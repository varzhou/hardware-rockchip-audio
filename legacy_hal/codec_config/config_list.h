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

#ifndef _CONFIG_LIST_H_
#define _CONFIG_LIST_H_

#include "config.h"
#include "default_config.h"
#include "rk616_config.h"
#include "rt3261_config.h"
#include "rt5616_config.h"
#include "rt3224_config.h"
#include "wm8960_config.h"

struct alsa_sound_card_config
{
    const char *sound_card_name;
    const struct config_route_table *route_table;
};

/*
* List of sound card name and config table.
* Audio will get config_route_table and set route 
* according to the name of sound card 0 and sound_card_name.
*/
struct alsa_sound_card_config sound_card_config_list[] = {
    {
        .sound_card_name = "RKRK616",
        .route_table = &rk616_config_table,
    },
    {
        .sound_card_name = "RK29RT3224",
        .route_table = &rt3224_config_table,
    },
    {
        .sound_card_name = "RK29RT3261",
        .route_table = &rt3261_config_table,
    },
    {
        .sound_card_name = "RK29WM8960",
        .route_table = &wm8960_config_table,
    },
    {
        .sound_card_name = "RKRT3224",
        .route_table = &rt3224_config_table,
    },
    {
        .sound_card_name = "RKRT3261",
        .route_table = &rt3261_config_table,
    },
    {
        .sound_card_name = "RKWM8960",
        .route_table = &wm8960_config_table,
    },
    {
        .sound_card_name = "RKRT5616",
        .route_table = &rt5616_config_table,
    },
};

#endif //_CONFIG_LIST_H_
