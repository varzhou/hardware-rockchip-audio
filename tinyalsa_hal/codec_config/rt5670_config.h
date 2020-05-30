/*
** config of rt5670
*/

#ifndef _RT5670_CONFIG_H_
#define _RT5670_CONFIG_H_

#include "config.h"

const struct config_control rt5670_speaker_normal_controls[] = {
};

const struct config_control rt5670_speaker_incall_controls[] = {
};

const struct config_control rt5670_speaker_ringtone_controls[] = {
};

const struct config_control rt5670_speaker_voip_controls[] = {
};

const struct config_control rt5670_earpiece_normal_controls[] = {

};

const struct config_control rt5670_earpiece_incall_controls[] = {
};

const struct config_control rt5670_earpiece_ringtone_controls[] = {
};
const struct config_control rt5670_earpiece_voip_controls[] = {
};

const struct config_control rt5670_headphone_normal_controls[] = {
	{
        .ctl_name = "Stereo DAC MIXL DAC L1 Switch",// 114
        .int_val = 1,
    },
    {
        .ctl_name = "Stereo DAC MIXR DAC L1 Switch",//119
        .int_val = 1,
    },
	{
        .ctl_name = "Stereo DAC MIXL DAC R1 Switch",//116
        .int_val = 1,
    },
    {
        .ctl_name = "Stereo DAC MIXR DAC R1 Switch",//117
        .int_val = 1,
    },	
	{
		.ctl_name = "IN1 Boost",//16
		.int_val = {0},
    },
};

const struct config_control rt5670_headphone_incall_controls[] = {
};

const struct config_control rt5670_headphone_ringtone_controls[] = {
};
		
const struct config_control rt5670_speaker_headphone_normal_controls[] = {
};

const struct config_control rt5670_speaker_headphone_ringtone_controls[] = {
};

const struct config_control rt5670_headphone_voip_controls[] = {
};

const struct config_control rt5670_headset_normal_controls[] = {

};

const struct config_control rt5670_headset_incall_controls[] = {

};

const struct config_control rt5670_headset_ringtone_controls[] = {
};

const struct config_control rt5670_headset_voip_controls[] = {
	
};
const struct config_control rt5670_bluetooth_normal_controls[] = {
	
};

const struct config_control rt5670_bluetooth_incall_controls[] = {

};

const struct config_control rt5670_bluetooth_voip_controls[] = {

};

const struct config_control rt5670_main_mic_capture_controls[] = {
	{
        .ctl_name = "Sto1 ADC MIXR ADC1 Switch", //88
        .int_val = 1,
    },
    {
        .ctl_name = "Sto1 ADC MIXL ADC1 Switch",//86
        .int_val = 1,
    },
	{
        .ctl_name = "ADC Capture Volume",//20
        .int_val = {36, 36},
    },
	{
        .ctl_name = "RECMIXL BST1 Switch",//65
        .int_val = {1},
    },
	{
        .ctl_name = "RECMIXR BST1 Switch",//68
        .int_val = {1},
    },
    {
        .ctl_name = "RECMIXL INL Switch",//63
        .int_val = {1},
    },
    {
        .ctl_name = "RECMIXR INR Switch",//66
        .int_val = {1},
    },
    {
		.ctl_name = "IN1 Boost",//16
		.int_val = {0},
    },

};

const struct config_control rt5670_hands_free_mic_capture_controls[] = {
	
};

const struct config_control rt5670_bluetooth_sco_mic_capture_controls[] = {
	
};

const struct config_control rt5670_playback_off_controls[] = {
	
	{
        .ctl_name = "Stereo DAC MIXL DAC L1 Switch",// 114
        .int_val = 0,
    },
    {
        .ctl_name = "Stereo DAC MIXR DAC L1 Switch",//119
        .int_val = 0,
    },
	{
        .ctl_name = "Stereo DAC MIXL DAC R1 Switch",//116
        .int_val = 0,
    },
    {
        .ctl_name = "Stereo DAC MIXR DAC R1 Switch",//117
        .int_val = 0,
    },
};

const struct config_control rt5670_capture_off_controls[] = {
	{
        .ctl_name = "Sto1 ADC MIXR ADC1 Switch", //88
        .int_val = 0,
    },
    {
        .ctl_name = "Sto1 ADC MIXL ADC1 Switch",//86
        .int_val = 0,
    },
	{
        .ctl_name = "ADC Capture Volume",//20
        .int_val = {0, 0},
    },
	{
        .ctl_name = "RECMIXL BST1 Switch",//65
        .int_val = {0},
    },
	{
        .ctl_name = "RECMIXR BST1 Switch",//68
        .int_val = {0},
    },
    {
        .ctl_name = "RECMIXL INL Switch",//63
        .int_val = {0},
    },
    {
        .ctl_name = "RECMIXR INR Switch",//66
        .int_val = {0},
    },
    {
		.ctl_name = "IN1 Boost",//16
		.int_val = {0},
    },
};

const struct config_control rt5670_incall_off_controls[] = {

};

const struct config_control rt5670_voip_off_controls[] = {

};

const struct config_route_table rt5670_config_table = {
    //speaker
    .speaker_normal = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_normal_controls,
        .controls_count = sizeof(rt5670_speaker_normal_controls) / sizeof(struct config_control),
    },
    .speaker_incall = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_incall_controls,
        .controls_count = sizeof(rt5670_speaker_incall_controls) / sizeof(struct config_control),
    },
    .speaker_ringtone = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_ringtone_controls,
        .controls_count = sizeof(rt5670_speaker_ringtone_controls) / sizeof(struct config_control),
    },
    .speaker_voip = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_voip_controls,
        .controls_count = sizeof(rt5670_speaker_voip_controls) / sizeof(struct config_control),
    },

    //earpiece
    .earpiece_normal = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_earpiece_normal_controls,
        .controls_count = sizeof(rt5670_earpiece_normal_controls) / sizeof(struct config_control),
    },
    .earpiece_incall = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_earpiece_incall_controls,
        .controls_count = sizeof(rt5670_earpiece_incall_controls) / sizeof(struct config_control),
    },
    .earpiece_ringtone = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_earpiece_ringtone_controls,
        .controls_count = sizeof(rt5670_earpiece_ringtone_controls) / sizeof(struct config_control),
    },
    .earpiece_voip = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_earpiece_voip_controls,
        .controls_count = sizeof(rt5670_earpiece_voip_controls) / sizeof(struct config_control),
    },

    //headphone
    .headphone_normal = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headphone_normal_controls,
        .controls_count = sizeof(rt5670_headphone_normal_controls) / sizeof(struct config_control),
    },
    .headphone_incall = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headphone_incall_controls,
        .controls_count = sizeof(rt5670_headphone_incall_controls) / sizeof(struct config_control),
    },
    .headphone_ringtone = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headphone_ringtone_controls,
        .controls_count = sizeof(rt5670_headphone_ringtone_controls) / sizeof(struct config_control),
    },
    .speaker_headphone_normal = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_headphone_normal_controls,
        .controls_count = sizeof(rt5670_speaker_headphone_normal_controls) / sizeof(struct config_control),
    },
    .speaker_headphone_ringtone = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_headphone_ringtone_controls,
        .controls_count = sizeof(rt5670_speaker_headphone_ringtone_controls) / sizeof(struct config_control),
    },
    .headphone_voip = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headphone_voip_controls,
        .controls_count = sizeof(rt5670_headphone_voip_controls) / sizeof(struct config_control),
    },

    //headset
    .headset_normal = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headset_normal_controls,
        .controls_count = sizeof(rt5670_headset_normal_controls) / sizeof(struct config_control),
    },
    .headset_incall = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headset_incall_controls,
        .controls_count = sizeof(rt5670_headset_incall_controls) / sizeof(struct config_control),
    },
    .headset_ringtone = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headset_ringtone_controls,
        .controls_count = sizeof(rt5670_headset_ringtone_controls) / sizeof(struct config_control),
    },
    .headset_voip = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_headset_voip_controls,
        .controls_count = sizeof(rt5670_headset_voip_controls) / sizeof(struct config_control),
    },

    //bluetooth
    .bluetooth_normal = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_bluetooth_normal_controls,
        .controls_count = sizeof(rt5670_bluetooth_normal_controls) / sizeof(struct config_control),
    },
    .bluetooth_incall = {
        .sound_card = 0,
        .devices = DEVICES_0_1,
        .controls = rt5670_bluetooth_incall_controls,
        .controls_count = sizeof(rt5670_bluetooth_incall_controls) / sizeof(struct config_control),
    },
    .bluetooth_voip = {
        .sound_card = 0,
        .devices = DEVICES_0_1,
        .controls = rt5670_bluetooth_voip_controls,
        .controls_count = sizeof(rt5670_bluetooth_voip_controls) / sizeof(struct config_control),
    },

    //capture
    .main_mic_capture = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_main_mic_capture_controls,
        .controls_count = sizeof(rt5670_main_mic_capture_controls) / sizeof(struct config_control),
    },
    .hands_free_mic_capture = {
        .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_hands_free_mic_capture_controls,
        .controls_count = sizeof(rt5670_hands_free_mic_capture_controls) / sizeof(struct config_control),
    },
    .bluetooth_sco_mic_capture = {
        .sound_card = 0,
        .devices = DEVICES_0_1,
        .controls = rt5670_bluetooth_sco_mic_capture_controls,
        .controls_count = sizeof(rt5670_bluetooth_sco_mic_capture_controls) / sizeof(struct config_control),
    },

    //off
    .playback_off = {
        .controls = rt5670_playback_off_controls,
        .controls_count = sizeof(rt5670_playback_off_controls) / sizeof(struct config_control),
    },
    .capture_off = {
        .controls = rt5670_capture_off_controls,
        .controls_count = sizeof(rt5670_capture_off_controls) / sizeof(struct config_control),
    },
    .incall_off = {
        .controls = rt5670_incall_off_controls,
        .controls_count = sizeof(rt5670_incall_off_controls) / sizeof(struct config_control),
    },
    .voip_off = {
        .controls = rt5670_voip_off_controls,
        .controls_count = sizeof(rt5670_voip_off_controls) / sizeof(struct config_control),
    },

    //hdmi
    .hdmi_normal = {
        //.sound_card = 1,
        //.devices = DEVICES_0,
        //.controls_count = 0,
         .sound_card = 0,
        .devices = DEVICES_0,
        .controls = rt5670_speaker_normal_controls,
        .controls_count = sizeof(rt5670_speaker_normal_controls) / sizeof(struct config_control),
    },

    //usb audio
    .usb_normal = {
        .sound_card = 2,
        .devices = DEVICES_0,
        .controls_count = 0,
    },
    .usb_capture = {
        .sound_card = 2,
        .devices = DEVICES_0,
        .controls_count = 0,
    },
};


#endif //_rt5670_CONFIG_H_
