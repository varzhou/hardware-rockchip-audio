/*
 * Copyright (C) 2015 Fuzhou Rockchip Electronics Co. Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
**
** Copyright 2007, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License"); 
** you may not use this file except in compliance with the License. 
** You may obtain a copy of the License at 
**
**     http://www.apache.org/licenses/LICENSE-2.0 
**
** Unless required by applicable law or agreed to in writing, software 
** distributed under the License is distributed on an "AS IS" BASIS, 
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
** See the License for the specific language governing permissions and 
** limitations under the License.
*/

#include <cutils/properties.h>
#include <string.h>
#include <unistd.h>
//#define LOG_NDEBUG 0

#define LOG_TAG "AudioHardwareInterface"
#include <utils/Log.h>
#include <utils/String8.h>

#include "AudioHardwareStub.h"
#include "AudioHardwareGeneric.h"

#ifdef ENABLE_AUDIO_DUMP
#include "AudioDumpInterface.h"
#endif


// change to 1 to log routing calls
#define LOG_ROUTING_CALLS 1

namespace android_audio_legacy {

#if LOG_ROUTING_CALLS
static const char* routingModeStrings[] =
{
    "OUT OF RANGE",
    "INVALID",
    "CURRENT",
    "NORMAL",
    "RINGTONE",
    "IN_CALL",
    "IN_COMMUNICATION"
};

static const char* routeNone = "NONE";

static const char* displayMode(int mode)
{
    if ((mode < AudioSystem::MODE_INVALID) || (mode >= AudioSystem::NUM_MODES))
        return routingModeStrings[0];
    return routingModeStrings[mode+3];
}
#endif

// ----------------------------------------------------------------------------

AudioHardwareInterface* AudioHardwareInterface::create()
{
    return NULL;
}

AudioStreamOut::~AudioStreamOut()
{
}

// default implementation is unsupported
status_t AudioStreamOut::getNextWriteTimestamp(int64_t *timestamp)
{
    return INVALID_OPERATION;
}

status_t AudioStreamOut::getPresentationPosition(uint64_t *frames, struct timespec *timestamp)
{
    return INVALID_OPERATION;
}

AudioStreamIn::~AudioStreamIn() {}

AudioHardwareBase::AudioHardwareBase()
{
    mMode = 0;
}

status_t AudioHardwareBase::setMode(int mode)
{
#if LOG_ROUTING_CALLS
    ALOGD("setMode(%s)", displayMode(mode));
#endif
    if ((mode < 0) || (mode >= AudioSystem::NUM_MODES))
        return BAD_VALUE;
    if (mMode == mode)
        return ALREADY_EXISTS;
    mMode = mode;
    return NO_ERROR;
}

// default implementation
status_t AudioHardwareBase::setParameters(const String8& keyValuePairs)
{
    return NO_ERROR;
}

// default implementation
String8 AudioHardwareBase::getParameters(const String8& keys)
{
    AudioParameter param = AudioParameter(keys);
    return param.toString();
}

// default implementation
size_t AudioHardwareBase::getInputBufferSize(uint32_t sampleRate, int format, int channelCount)
{
    if (sampleRate != 8000) {
        ALOGW("getInputBufferSize bad sampling rate: %d", sampleRate);
        return 0;
    }
    if (format != AudioSystem::PCM_16_BIT) {
        ALOGW("getInputBufferSize bad format: %d", format);
        return 0;
    }
    if (channelCount != 1) {
        ALOGW("getInputBufferSize bad channel count: %d", channelCount);
        return 0;
    }

    return 320;
}

// default implementation is unsupported
status_t AudioHardwareBase::getMasterVolume(float *volume)
{
    return INVALID_OPERATION;
}

status_t AudioHardwareBase::dumpState(int fd, const Vector<String16>& args)
{
    const size_t SIZE = 256;
    char buffer[SIZE];
    String8 result;
    snprintf(buffer, SIZE, "AudioHardwareBase::dumpState\n");
    result.append(buffer);
    snprintf(buffer, SIZE, "\tmMode: %d\n", mMode);
    result.append(buffer);
    ::write(fd, result.string(), result.size());
    dump(fd, args);  // Dump the state of the concrete child.
    return NO_ERROR;
}

// default implementation calls its "without flags" counterpart
AudioStreamOut* AudioHardwareInterface::openOutputStreamWithFlags(uint32_t devices,
                                          audio_output_flags_t flags,
                                          int *format,
                                          uint32_t *channels,
                                          uint32_t *sampleRate,
                                          status_t *status)
{
    return openOutputStream(devices, format, channels, sampleRate, status);
}

// ----------------------------------------------------------------------------

}; // namespace android
