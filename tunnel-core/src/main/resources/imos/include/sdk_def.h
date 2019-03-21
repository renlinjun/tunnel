/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              sdk_def.h

  Project Code: SDK
   Module Name: SDK
  Date Created: 2009-02-27
        Author: yangbin (07022)
                sunyifan (s06966)
                zhuyi (KF1397)
   Description: 宏，枚举定义文档

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_DEFINE_H_
#define _IMOS_SDK_DEFINE_H_
#ifdef  __cplusplus
extern "C"{
#endif

/* Begin added by y01359 2014-10-09 for A8 */
/** A8底图根路径 */
#define A8_BASE_PICTURE_PATH "/mnt/syncdata/resftp/A8/BASEPIC/"

/** A8 EDID文件根路径 */
#define A8_EDID_PATH "/mnt/syncdata/resftp/A8/EDID/"

/** A8 EDID文件大小 */
#define A8_EDID_SIZE 128

/** A8 EDID文件最大大小 */
#define A8_EDID_MAX_SIZE 256

/** 默认电视墙场景ID */
#define CS_TVWALL_SCENE_ID 99

/*Begin: Modified by huangsen W4381, 2017-08-31 for MPPD50646 A8场景扩展*/
/** 电视墙场景最大数量 */
#define TVWALL_SCENE_MAX_NUM 64
/*End: Modified by huangsen W4381, 2017-08-31 for MPPD50646 A8场景扩展*/

/** 电视墙编码默认头 */
#define  TVWALL_DEFAULT_CODE         "tvwall"

/** 电视墙窗口编码默认头 */
#define  WINDOW_DEFAULT_CODE         "window"

/** 电视墙摄像机编码默认头 */
#define  CAMERA_DEFAULT_CODE         "cam"

/** 电视墙监视器编码默认头 */
#define  SCREEN_DEFAULT_CODE         "screen"

/** 电视墙场景组编码默认头 */
#define  TVWALL_SCENE_GROUP_DEFAULT_CODE         "scenegroup"

/** 电视墙不可用编码 */
#define A8_TVWALL_DISABLE_CODE "DISABLE_TVWALL_CODE"

/** 电视墙监视屏不可用编码 */
#define A8_INVILD_SCREEN_CODE "INVALID_SCREEN_CODE"

/** 电视墙摄像机不可用编码 */
#define A8_INVILD_CAMERA_CODE "INVALID_CAMERA_CODE"

/** 电视墙轮切资源不可用编码 */
#define A8_INVILD_SWITCH_RES_CODE "INVALID_SWITCH_RES_CODE"

/* End added by y01359 2014-10-09 for A8 */

/* Begin: Added by gupeng, 2017-10-15 for MPPD54245 A8组轮巡特性开发 */
/** 电视墙轮巡资源不可用编码 */
#define A8_INVILD_POLL_RES_CODE "INVALID_POLL_RES_CODE"
/* End: Added by gupeng, 2017-10-15 for MPPD54245 A8组轮巡特性开发 */

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE接入平台 */
#define     MM_SIP_KEY_MESSAGE                      "Message"
#define     MM_SIP_KEY_COMMAND                      "Command"
#define     MM_SIP_KEY_COMMAND_VALUE                "CMD_ALARM_DATA"
#define     MM_SIP_KEY_TYPE                         "Type"
#define     MM_SIP_KEY_TYPE_VALUE                   "Req"
#define     MM_SIP_KEY_VARIABLE                     "Variable"
#define     MM_SIP_KEY_WINDOW                       "Window"
#define     MM_SIP_KEY_SPLIT                        "Split"
#define     MM_SIP_KEY_ROAM                         "Roam"
#define     MM_SIP_KEY_STACK                        "Stack"
#define     MM_SIP_KEY_MOSAIC                       "Mosaic"
#define     MM_SIP_KEY_BASEMAP                      "Basemap"
#define     MM_SIP_KEY_VLED                         "VLed"
#define     MM_SIP_KEY_TRANSPARENCY                 "Transparency"
#define     MM_SIP_KEY_ARBITRARILY                  "Arbitrarily"
#define     MM_SIP_KEY_BASEMAPSIZE                  "BasemapSize"
#define     MM_SIP_KEY_RESOLUTION                   "Resolution"

#define     XWARE_REG_XML_NODE_MAX_TVWALL_NUM           "MaxTVWallsNums"
#define     XWARE_REG_XML_NODE_MAX_SCENES_NUM           "MaxScenesNums"
#define     XWARE_REG_XML_NODE_MAX_ROW_NUM              "MaxRowNums"
#define     XWARE_REG_XML_NODE_MAX_COL_NUM              "MaxColNums"
#define     XWARE_REG_XML_NODE_SUP_VIDEO_FOR            "VideoFormats"
#define     XWARE_REG_XML_NODE_MAX_WIN_NUM              "MaxWinNums"
#define     XWARE_REG_XML_NODE_MAX_SCREEN_WIN           "MaxPerScreenWinAreas"
#define     XWARE_REG_XML_NODE_MAX_PER_WIN_PANE_NUM     "MaxPerWinPaneNums"
#define     XWARE_REG_XML_NODE_MIN_WIN_WIDTH            "MinWinWidth"
#define     XWARE_REG_XML_NODE_MIN_WIN_HEIGHT           "MinWinHeight"
#define     XWARE_REG_XML_NODE_MAX_BASEMAP_NUM          "MaxBaseMapNums"
#define     XWARE_REG_XML_NODE_MAX_PERSCENE_BASEMAP_NUM "MaxPerSceneBaseMapNums"
#define     XWARE_REG_XML_NODE_MAX_BASEMAP_WIDTH        "MaxBaseMapWidth"
#define     XWARE_REG_XML_NODE_MAX_BASEMAP_HEIGHT       "MaxBaseMapHeight"
#define     XWARE_REG_XML_NODE_MAX_BASEMAP_SIZE         "MaxBaseMapSize"
#define     XWARE_REG_XML_NODE_MAX_PERSCENE_VIR_LED_NUM "MaxPerSceneVLEDNums"
#define     XWARE_REG_XML_NODE_MAX_VIR_LED_ROW          "MaxVLEDRows"
#define     XWARE_REG_XML_NODE_MAX_VIR_LED_CHAR         "MaxVLEDChars"
#define     XWARE_REG_XML_NODE_MAX_SEQ_RES_NUM          "MaxSeqRSrcNums"
#define     XWARE_REG_XML_NODE_MAX_PANE_SEQ_NUM         "MaxPaneSeqNums"
#define     XWARE_REG_XML_NODE_MAX_WIN_SEQ_NUM          "MaxWinSeqNums"
#define     XWARE_REG_XML_NODE_MAX_SCENE_SEQ_NUM        "MaxSceneSeqNums"
#define     XWARE_REG_XML_NODE_IS_SUP_BACK_TO_SHOW      "CanBacktoShow"
#define     XWARE_REG_XML_NODE_WIN_CAP                  "WinCaps"
#define     XWARE_REG_XML_NODE_PANE_CAP                 "PaneCaps"
#define     XWARE_REG_XML_NODE_WIN_ROAM_CAP             "WinRoamingCaps"
#define     XWARE_REG_XML_NODE_IS_SUP_OVERLAY           "CanOverlay"
#define     XWARE_REG_XML_NODE_IS_SUP_SET_TRAN          "CanSetTrans"
#define     XWARE_REG_XML_NODE_ABSRACT                  "Abstract"

/* Begin: Added by maojiangfeng W4699, 2017-10-26 for MPPD50773 Xware业务能力增加分屏类型 */
#define     XWARE_REG_XML_NODE_SUP_PANE_TYPE        "SupportPaneTypes"
/* End: Added by maojiangfeng W4699, 2017-10-26 for MPPD50773 Xware业务能力增加分屏类型 */

/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE接入平台 */


/** @brief 选项值内存块长度最小值 */
#define IMOS_OPTION_BUFFER_LEN_MIN              1

/** @brief 选项值内存块长度最大值 */
#define IMOS_OPTION_BUFFER_LEN_MAX              64


/** @brief 一个电视墙包含监视器的最大数目 */
#define IMOS_MONITOR_MAXNUM_PER_WALL            256

/* Begin Added by dengshuhua00673, 2013-02-05 of 自动布局轮巡 */
/** @brief 一个电视墙包含的分屏的最大数目 */
#define IMOS_SPLIT_MAXNUM_PER_WALL  (SPLIT_SCR_MODE_MAX * IMOS_MONITOR_MAXNUM_PER_WALL)
/* End Added by dengshuhua00673, 2013-02-05 of 自动布局轮巡 */

/*@brief 告警联动存储的最大数目 */
#define IMOS_ALARM_STORE_ACTION_MAXNUM          16

/* Begin added by liuzhikun/01420, 2013-11-12 for 告警联动语音对讲 */
/*@brief 告警联动语音对讲最大数目 */
#define IMOS_ALARM_VOCTALK_ACTION_MAXNUM          16
/* End added by liuzhikun/01420, 2013-11-12 for 告警联动语音对讲 */

/* Begin added by y01359, 2016-03-25 for A8 */
/*@brief 告警联动电视墙实况最大数目 */
#define IMOS_ALARM_TVWALL_MONITOR_ACTION_MAXNUM   16
/* End added by y01359, 2016-03-25 for A8 */

/*@brief 告警联动中心域存储的最大数目 */
#define IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM   16

/*@brief 告警联动预置位的最大数目 */
#define IMOS_ALARM_PRESET_ACTION_MAXNUM         16

/*@brief 告警联动实况到窗格的最大数目 */
#define IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM     16

/*@brief 告警联动实况到监视器的最大数目 */
#define IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM    16

/*@brief 告警联动地图闪烁的最大数目 */
#define IMOS_ALARM_GIS_ACTION_MAXNUM            16

/*@brief 告警联动开关量输出的最大数目 */
#define IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM      16

/*@brief 告警联动备份的最大数目 */
#define IMOS_ALARM_BACKUP_ACTION_MAXNUM         16

/*@brief 告警联动短信或邮件接收人的最大数目 */
#define IMOS_ALARM_ACTION_RECEIVER_MAXNUM       300

/*@brief 告警联动蜂鸣器的最大数目 */
#define IMOS_ALARM_BUZZER_ACTION_MAXNUM         1

/*@brief 透明通道3PCC模式下允许的串口数 */
#define IMOS_TRANSPARENT_SERIAL_NUM             2

/*@brief 轮切允许的最大摄像机数目 */
#define IMOS_SWITCH_CAM_MAXNUM                  32

/* @brief 轮切资源中最大摄像机数目V2 */
#define IMOS_SWITCH_CAM_MAXNUM_V2               512

/*@brief 巡航路径预置位数量最大值 */
#define IMOS_CRUISE_PATH_PRESET_MAX_COUNT       32

/*@brief 阵列允许的最大槽位数目 */
#define IMOS_ARRAY_SLOT_MAXNUM                  10

/*@brief 单通道遮盖区域的最大数目(3) */
#define IMOS_MASK_AREA_MAXNUM_III               3

/*@brief 单通道遮盖区域的最大数目(1) */
#define IMOS_MASK_AREA_MAXNUM_I                 1

/*@brief 单通道遮挡区域的最大数目 */
#define IMOS_COVER_AREA_MAXNUM                   4

/*@brief NTP服务器最大个数 */
#define IMOS_NTP_SERVER_MAXNUM                  3

/*@brief 一个告警源设备所属的地图列表的最大个数 */
#define IMOS_GIS_FOR_ALARM_SRC_MAX_NUM          5

/** 公司合同编号长度 */
#define IMOS_CONTRACT_ID                        32

/** license序列号规格数 */
#define IMOS_LICENSE_SERIALS_NUM                256

/** license针对的业务类型数 */
#define IMOS_LICENSE_SERVICE_TYPE_NUM           20

/*@brief 分页查询行数最大值 */
#define IMOS_PAGE_QUERY_ROW_MAX_NUM             200

/** @brief 一次推送的最大资源数目 */
#define IMOS_ONCE_SHARE_RES_MAXNUM              1    /**< MAX_DEVSHARE_ONCE_PUSH */

/** @brief EC下的CAM最大数目*/
#define IMOS_MAX_CAMERA_NUM_PER_EC              64   /**< MAX_CAMERA_NUM_PER_EC */

/** @brief DC下的SCREEN最大数目*/
#define IMOS_MAX_SCREEN_NUM_PER_DC              16   /**< MAX_SCREEN_NUM_PER_DC */

/** @brief URL字符串长度.需要跟MC同步更新 */
#define IMOS_IE_URL_LEN                         IMOS_STRING_LEN_512

/*@brief 无效通道号 */
#define IMOS_INVALID_CHANNEL_NO                 0xFF

/*@brief 每个XP对应窗格最大数 */
#define IMOS_XP_WIN_MAX_NUM                     128

/*@brief 查询项内容的最大程度 */
#define IMOS_QUERY_DATA_MAX_LEN                 64

/*@brief 查询项最大个数 */
#define IMOS_QUERY_ITEM_MAX_NUM                 16

/*@brief 可添加的最大外域数目 */
#define IMOS_MAX_EXTERNAL_DOMAIN_NUM            2048


/*@brief 可为单个用户授予的最大角色个数 */
#define IMOS_MAX_USER_ROLES_NUM                 16

/*@brief Notify最大长度 */
#define IMOS_MAX_NOTIFY_LEN                     4096

/*@brief 设备状态数组的最大值 */
#define IMOS_DEV_STATUS_MAX_NUM                4


/*@brief 布局中允许的最大显示数目 */
#define IMOS_DISPLAY_MAXNUM_PER_LAYOUT          IMOS_MONITOR_MAXNUM_PER_WALL

/*@brief 组显示允许的最大显示数目 */
#define IMOS_DISPLAY_MAXNUM_PER_SALVO           256

/* Modify by g00351 for MPPD04637 主线不再支持四川电力协议，将stGisMapShareInfo结构中astMapParam个数改小（1或0），合入B03D025版本 */
/*@brief 场景中允许的最大资源数目 */
//#define IMOS_SCENE_MAXNUM_RES                   256
#define IMOS_SCENE_MAXNUM_RES                   1

/** @brief 资源组中资源的最大数目(无其他专门指定时用此宏) */
#define IMOS_RES_NUM_MAX_PER_GROUP 256

/*@brief 通用轮切允许的最大资源数目 */
#define IMOS_COMMON_SWITCH_RES_MAXNUM           256

/* Begin: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */
/*@brief A8拼控设备轮巡的最大摄像机资源数目 */
#define IMOS_AUTOPOLL_CAMERA_RES_MAXNUM           5000

/*@brief A8拼控设备轮巡的最大窗口资源数目 */
#define IMOS_AUTOPOLL_WINDOW_RES_MAXNUM           480

/*@brief A8拼控设备轮巡的最大分屏数目 */
#define IMOS_AUTOPOLL_WINDOWSPLIT_MAXNUM           480 * 16
/* End: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */

/** @brief 一个地图中允许设置的热区的最大数量 */
#define IMOS_GIS_MAX_HOTZONE_NUM_PER_MAP        32
/** @brief 一个地图中允许设置的图标(包括热点、文本框、摄像机图标、告警源图标、告警输出图标)的最大数量 */
#define IMOS_GIS_MAX_ICON_NUM_PER_MAP           2048

/* Modify by g00351 for MPPD04637 主线不再支持四川电力协议，将stGisMapShareInfo结构中astMapParam个数改小（1或0），合入B03D025版本 */
/** @brief 地图包含的参数最大个数*/
//#define IMOS_MAX_GIS_MAP_PARAM_NUM             (IMOS_GIS_MAX_HOTZONE_NUM_PER_MAP + IMOS_GIS_MAX_ICON_NUM_PER_MAP)
#define IMOS_MAX_GIS_MAP_PARAM_NUM             1

/* 联动警前录像结构体的长度 */
#define IMOS_BEALARM_REPLAY_LEN                (IMOS_CODE_LEN + 8 + IMOS_TIME_LEN)

/*@brief 联动抓拍预留字符串的长度 */
#define IMOS_IDLE_LEN                          (IMOS_NAME_LEN + IMOS_CODE_LEN - 12 - IMOS_BEALARM_REPLAY_LEN)

/*@brief IMOS系统参数最大数量 */
#define IMOS_SYS_PARAM_MAX_NUM                  128

/*@brief 一次可以增加事件使能最大数量 */
#define IMOS_EVENT_ENABLE_ADD_MAX_NUM           1024

/** 事件关联设备类型最大数目 */
#define IMOS_EVENT_TYPE_REL_MAX_NUM             128

/**网络配置优化 */
#define NIC_COUNT_MAX      4

/* ONVIF FLOAT长度:float长度为32，为了不溢出使用48 */
#define ONVIF_FLOAT_LEN                     48

/**
* ONVIF OSD相关定义
*/

/* ONVIF URL长度 */
#define ONVIF_URL_LEN                       256

/* ONVIF OSD文本最大长度 */
#define ONVIF_OSD_TEXT_MAX_LEN              256

/* ONVIF OSD最大个数 */
#define ONVIF_OSD_MAX_NUM                   8

/* ONVIF date formate长度*/
#define ONVIF_OSD_DATE_FORMAT_LEN           32

/* ONVIF date formate最大支持数目*/
#define ONVIF_OSD_DATE_FORMAT_MAX_NUM       8

/* ONVIF text string type max length*/
#define ONVIF_OSD_TEXT_STRING_TYPE_MAX_LEN  32

/* ONVIF text string type max number*/
#define ONVIF_OSD_TEXT_STRING_TYPE_MAX_NUM  8

/* ONVIF time formate长度*/
#define ONVIF_OSD_TIME_FORMAT_LEN           32

/* ONVIF time formate最大支持数目*/
#define ONVIF_OSD_TIME_FORMAT_MAX           4

/* ONVIF OSD颜色最大支持数目*/
#define ONVIF_OSD_COLOR_MAX_NUM             16

/* ONVIF OSD颜色范围最大支持数目*/
#define ONVIF_OSD_COLOR_RANGE_MAX_NUM       16

/* ONVIF OSD图片路径最大支持数目*/
#define ONVIF_OSD_IMAGE_PATH_MAX_NUM        16

/* ONVIF OSD 位置类型最大长度 */
#define ONVIF_OSD_POS_TYPE_MAX_LEN          32

/* ONVIF OSD 位置类型最大数目 */
#define ONVIF_OSD_POS_TYPE_MAX_NUM          8

/* ONVIF ACTIVE CELL 最大个数 */
#define ONVIF_ACTIVE_CELLS_MAX_LEN          512

/* ONVIF item */
#define ONVIF_ITEM_LEN                      64

/* ONVIF attribute */
#define ONVIF_ATTRIBUTE_LEN                 64

/* ONVIF max name length */
#define ONVIF_NAME_LEN                      64

/* ONVIF max type length */
#define ONVIF_TYPE_LEN                      64

/**
* 视频配置
*/
/* 视频编码最大个数 */
#define ONVIF_VIDEO_ENCODER_MAX_NUM         16

/* 视频编码名称长度 */
#define ONVIF_VIDEO_ENCODER_NAME_LEN        64

/* 视频编码token长度 */
#define ONVIF_VIDEO_ENCODER_TOKEN_LEN       64

/**< 最大分辨率个数 */
#define ONVIF_VIDEO_RESOLUTION_MAX_NUM      16

/**< 时间长度 */
#define ONVIF_TIME_LEN                      32

/**< ONVIF IPADDR长度 */
#define ONVIF_IPADDR_LEN                    64

/**
* 音频配置
*/
/* 音频最大个数 */
#define ONVIF_AUDIO_ENCODER_MAX_NUM                 4

/* 音频选项最大个数 */
#define ONVIF_AUDIO_OPTIONS_MAX_NUM                 8

/* 音频选项比特率最大个数 */
#define ONVIF_AUDIO_OPTIONS_BIT_RATE_MAX_NUM        8

/* 音频选项采样率最大个数 */
#define ONVIF_AUDIO_OPTIONS_SAMPLE_RATE_MAX_NUM     8

/*
* @name 厂商类型
* @{
*/
/** @brief H3C VM/ISC */
#define IMOS_MANUFACTURER_TYPE_VMISC        "H3C VM/ISC"

/** @brief VM/ISC */
#define IMOS_MANUFACTURER_TYPE_VMISC_V2        "VM/ISC"

/** @brief H3C DA */
#define IMOS_MANUFACTURER_TYPE_DA           "H3C DA"

/** @brief DA */
#define IMOS_MANUFACTURER_TYPE_CURRENCY_DA  "DA"

/** @brief Other */
#define IMOS_MANUFACTURER_TYPE_OTHER        "Other"

/** @brief Aproud PL */
#define IMOS_MANUFACTURER_TYPE_PL           "Aproud PL"

/** @brief Aproud PL-S */
#define IMOS_MANUFACTURER_TYPE_PLS          "Aproud PL-S"

/** @brief H3C ECR HF */
#define IMOS_MANUFACTURER_TYPE_ECRHF        "H3C ECR-HF"

/**@brief BOCOM */
#define IMOS_MANUFACTURER_TYPE_BOCOM       "BOCOM"

/*Begin added by liangchao, 2015-11-25 for BM2516合主线*/
/**@brief DABackup */
#define IMOS_MANUFACTURER_TYPE_DABK       "DABackup"
/*End added by liangchao, 2015-11-25 for BM2516合主线*/
/** @} */

/*
* @name 云台协议类型
* @{
*/
/** @brief INTERNAL-PTZ */
#define IMOS_PTZ_PROTOCOL_TYPE_INTERNAL     "INTERNAL-PTZ"
/** @} */

/** @brief 无效的初始化地址，不进行IMG连接 */
#define IMOS_SDK_CLIB_INVALID_IP_ADDRESS    "N/A"

/** @brief Adapter的初始化地址，不进行IMG连接 */
#define IMOS_SDK_INITIATE_INVALID_IP_ADDRESS    "0.0.0.0"

/** @brief 多实例模块名称 */
#define IMOS_SDK_MU_CLIB_MODULE_NAME       "VM"

/*******************************************************************************
SS新增定义
在视讯常量的定义前面增加IMOS_， 以便区别。
*******************************************************************************/
/*@brief Email会前通知次数 */
#define IMOS_EMAIL_NOTIFICATION_NUMBER                  3

/*@brief 会场名称的最大长度 */
#define IMOS_HD_MAX_SITE_NAME_LEN                       31
#define IMOS_SITE_NAME_LEN                              48 /*< 参考 #IMOS_HD_MAX_SITE_NAME_LEN */

/*@brief 会议名称的最大长度 */
#define IMOS_HD_MAX_CONF_NAME_LEN                       31
#define IMOS_CONF_NAME_LEN                              48  /*< 参考 #IMOS_HD_MAX_CONF_NAME_LEN */

/*@brief 会场、会议最多支持的音频协议数 */
#define IMOS_HD_MAX_AUDIO_PROTOCOL_NUM                  20

/*@brief 最大横幅长度 */
#define IMOS_HD_MAX_BANNER_LEN                          43
#define IMOS_BANNER_LEN                                 66 /*< 参考 #IMOS_HD_MAX_BANNER_LEN */


/*@brief 会议别名的最大长度 */
#define IMOS_HD_MAX_CONF_ALIAS_LEN                      31
#define IMOS_CONF_ALIAS_LEN                             (IMOS_HD_MAX_CONF_ALIAS_LEN + 1)

/*@brief 协议定义的每个会议的最大会场数 */
#define IMOS_HD_MAX_SITE_PER_CONF_NUM                   256

/*@brief 子画面最大个数 */
#define IMOS_HD_MAX_SUBPIC_NUM                          64

/*@brief 会场、会议主流和辅流最多支持的视频格式数 */
#define IMOS_HD_MAX_VIDEO_FORMAT_NUM                    32

/*@brief 会场、会议最多支持的视频帧率数 */
#define IMOS_HD_MAX_VIDEO_FRAMERATE_NUM                 7

/*@brief 会场、会议最多支持的视频协议数 */
#define IMOS_HD_MAX_VIDEO_PROTOCOL_NUM                  4

/*@brief 会场、会议最多支持的视频速率数 */
#define IMOS_HD_MAX_VIDEO_RATE_NUM                      8

/*@brief 能力集中同时能力的最大个数  */
#define IMOS_HD_MAX_SIM_CAP_NUM                         8



/*@brief 定义会议最大轮巡表数 */
#define IMOS_MC_MAX_CONF_CYCLE_TABLE_COUNT              10


/*@brief 会议密码的最大长度 */
#define IMOS_MC_MAX_CONF_PWD_LEN                        11
#define IMOS_CONF_PWD_LEN                               (IMOS_MC_MAX_CONF_PWD_LEN + 1)

/*@brief 最多网口个数 */
#define IMOS_MC_MAX_LAN_NET_NUM                         4

/*@brief 网口标识最大长度 */
#define IMOS_HD_MAX_NETCARD_NAME_LEN                    31
#define IMOS_NETCARD_NAME_LEN                           48 /*< 参考 #IMOS_HD_MAX_NETCARD_NAME_LEN */

/*@brief MCU名称的最大长度 */
#define IMOS_MC_MAX_MCU_NAME_LEN                        31
#define IMOS_MCU_NAME_LEN                               (IMOS_MC_MAX_MCU_NAME_LEN + 1)

/*@brief MCU外部IP地址的最大个数 */
#define IMOS_MC_MAX_MCU_IP_NUM                          4

/*@brief 每个网口可配置路由个数 */
#define IMOS_MC_MAX_LAN_ROUTE_NUM                       20

/*@brief 每个网口ARP最大个数 */
#define IMOS_MC_MAX_LAN_ARP_NUM                         20

/*@brief MAC地址最大长度 */
#define IMOS_MC_MAX_MAC_ADDR_LEN                        20


/*@brief 软件版本号的最大长度 */
#define IMOS_HD_MAX_SOFT_VERSION_LEN                    255
#define IMOS_SOFT_VERSION_LEN                           (IMOS_HD_MAX_SOFT_VERSION_LEN + 1)

/*@brief 每块板最大的DSP数 */
#define IMOS_HD_MAX_DSP_PER_PLANK                       15

/*@brief 每个DSP上最多会议个数 */
#define IMOS_HD_MAX_DSP_NUM_PER_CONF                    4

/*@brief 电子邮件名最大长度 */
#define IMOS_HD_MAX_EMAIL_NAME_LEN                      63

/*@brief 最大图像监控会场个数 */
#define IMOS_MC_MAX_WATCH_SITE_NUM                      9

/*@brief 终端有效输出个数 */
#define IMOS_HD_VIDEO_OUT_NUM                          (4)

/*@brief 终端软/硬件版本/序列号长度 */
#define IMOS_HD_VERSION_LEN                            (32)

/*@brief UI，WEB，PC最大用户数 */
#define IMOS_HD_MAX_USER_NUM                           (32)

/*@brief 预置位数 */
#define IMOS_HD_MAX_CAM_PRE_NUM                        (20)

/*@brief 终端最大姓名字符串长度 */
#define IMOS_HD_MAX_NAME_LENGTH                        (32)

/*@brief 终端最大IP字符串长度 */
#define IMOS_HD_MAX_IP_LENGTH                          (32)

/*@brief 终端最大路径字符串长度 */
#define IMOS_HD_MAX_PATH_LENGTH                        (100)

/*@brief 终端最大密码字符串长度 */
#define IMOS_HD_MAX_PASSWORD_LENGTH                    (32)

/*@brief 终端最大私网个数 */
#define IMOS_HD_MAX_PRIVATE_NET_COUNT                  (4)

/*@brief 最大MAC字符串显示长度 */
#define IMOS_HD_MAX_MAC_DISPLAYLENGTH                  (17)

/*@brief 最大字幕数目 */
#define IMOS_TITLE_MAXNUM                              (2)

/*@brief 最大字幕长度 */
#define IMOS_TITLE_LEN                                 (2404)

/*@brief 一个会议中联系人最大数目*/
#define IMOS_MAX_CONTACTS_IN_CONF                      (512)

/*@brief IMOS支持的组件最大数目*/
#define IMOS_COMPONENT_MAX_NUM                         (50)

/*@brief MCU中最大的活动会场数目 */
#define IMOS_MAX_SITE_LIVE_NUM                         (240)

/*@brief MCU中最大的组播数目*/
#define IMOS_MAX_MULTI_ADDR_NUM                        (8)

/*@brief 速率适配最大路数 */
#define IMOS_MC_MAX_BITRATE_ADAPT_COUNT                (3)

/*@brief 一个会议中MCU最大数目 */
#define IMOS_MAX_MCU_IN_CONF                           (16)

/*@brief 一个会议中终端最大数目 */
#define IMOS_MAX_TERM_IN_CONF                          (1024)


/*@brief 透明通道DIRECT模式下允许的IP数 */
#define IMOS_TRANSPARENT_IP_NUM                 1

/** @brief 单个语音广播中能支持的最大摄像机数量  */
#define MAX_VOCBRD_CAM_NUM       128

/** @brief 云台最大速度值  */
#define MAX_PTZ_SPEED            9

/** @brief 进程名称最大长度  */
#define IMOS_PROC_NAME_MAX_LEN                          32

/** @brief 域间最大直连媒体流数量缺省值 */
#define IMOS_DEFAULT_NUM_OF_STREAM_BYPASS            1024

/*@brief 任务最大数目 */
#define IMOS_MAX_TASK_NUM                   (16)

/*@brief 告警转发用户最大数目 */
#define IMOS_ALARM_ACTION_TRAN_MAXNUM       (300)

/*@brief 触发器最大数目 */
#define IMOS_MAX_TRIGGER_NUM                (10)

/*@brief 新告警最大数目 */
#define IMOS_MAX_NEW_ALARM_NUM              (1)

/*@brief 联动到预案最大数目 */
#define IMOS_ALARM_ACTION_PLAN_MAXNUM       (1)

/*@brief 支持新告警类型 */
#define IMOS_TYPE_NEW_ALARM                 (65534)

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/*@brief 单通道遮盖区域的最大数目(8) */
#define IMOS_MASK_AREA_MAXNUM_VIII              8
/** @brief 车辆类型最大数量 */
#define IMOS_VEHICLE_TYPE_MAX_NUM                    32
/** @brief 测试图片的最大尺寸 */
#define IMOS_PICTURE_SIZE_MAX_LEN                       (512*1024)

/*@brief 区域类型: 区域增强 */
#define IMOS_VIDEO_AREA_TYPE_ROI            3

/* End Added by lw0581,2013-11-6 for  VVD06374*/

/** @brief 一个串并案包含案件的最大数目 */
#define IMOS_CASE_MAXNUM_PER_SERIESCASE            64

/** @brief 一个案件录像备份件的最大数目 */
#define IMOS_FILE_MAXNUM_PER_CASERECORD            8

/** @brief 违章类型最大数量 */
#define IMOS_VEHICLE_VIOLATION_MAX_NUM               200

/** @brief 数据字典类型最大数量 */
#define IMOS_DIC_CODE_MAX_NUM                        200

/** @brief 车辆类型最大数量 */
#define IMOS_VEHICLE_TYPE_MAX_NUM                    32

/** @brief 一个车辆布控最大域数量 */
#define IMOS_VEHICLE_DISPOSITION_DOMAIN_MAX_NUM      200

/** @brief 车辆异常行为分析最大分析的卡口数量 */
#define IMOS_VEHICLE_ABNORMAL_ANALYSE_TG_MAX_NUM     200

/** @brief 决定一条线的点的数量*/
#define IMOS_MAP_LINT_POINT_NUM                      2

/** @brief 道路的最大点位数 */
#define IMOS_MAP_ROAD_POINT_MAX_NUM                  64

/** @brief 测速区间超速百分比配置最大数量 */
#define IMOS_DETECTION_ROAD_SECTION_VIO_CONF_MAX_NUM 32

/** @brief TMS多地址转发规则最大数量 */
#define TMS_MULTI_ADDR_FORWARD_RULE_MAX_NUM 64

/** @brief 卡口支持的最大车道数量*/
#define IMOS_TOLLGATE_LANE_MAX_NUM          32

/** @brief 最大资源列表数量 */
#define IMOS_RES_LIST_MAX_NUM                        200

/* Begin: Modifid by luhaitao/01337, 2016-03-29 for 湘潭容灾 */
/** @brief 系统参数配置项名，容灾开关 */
#define IMOS_SYSTEM_PARAM_BKP_LINK_ENABLE_NAME	"bkp_link_enable_flag"

/** @brief 系统参数配置项名，容灾支持本域资源开关 */
#define IMOS_SYSTEM_PARAM_BKP_LINK_ENABLE_LOC_RES_NAME "bkp_link_enable_loc_res_flag"
/* End: Modifid by luhaitao/01337, 2016-03-29 for 湘潭容灾 */

#define NIC_COUNT_MAX      4

/* Begin: Added by l03769, 2017-09-18 for MPPD51448 物联网资源信息查询 */
/** @brief 最大物联网资源类型数量 */
#define IMOS_IOT_RES_TYPE_MAX_NUM            50
/* End: Added by l03769, 2017-09-18 for MPPD51448 物联网资源信息查询 */

/* Begin: Added by wW4366, 2017-09-11 for MPPD54245 A8拼控设备轮巡特性 */
/** A8电视墙监视器最大数量 */
#define IMOS_TVWALL_SCREN_RES_MAXNUM     48
/* End: Added by wW4366, 2017-09-11 for MPPD54245 A8拼控设备轮巡特性 */

/**
 * @enum tagIMOSThruLineDirection
 * @brief "绊线行为"方向
 * @attention
 */
typedef enum tagIMOSThruLineDirection
{
    IMOS_THRU_LINE_DIRECTION_CLOCKWISE          = 0,    /**< 顺时针 */
    IMOS_THRU_LINE_DIRECTION_ANTICLOCKWISE      = 1,    /**< 逆时针 */
    IMOS_THRU_LINE_DIRECTION_ALL                = 2,    /**< 双向 */

    IMOS_THRU_LINE_DIRECTION_MAX,
    IMOS_THRU_LINE_DIRECTION_INVALID            = 0XFFFFFFFF
} IMOS_THRU_LINE_DIRECTION_E;

/**
 * @enum tagIMOSAreaDirection
 * @brief "区域行为"方向
 * @attention
 */
typedef enum tagIMOSAreaDirection
{
    IMOS_AREA_DIRECTION_IN       = 0,    /**< In */
    IMOS_AREA_DIRECTION_OUT      = 1,    /**< Out */
    IMOS_AREA_DIRECTION_ALL      = 2,    /**< 双向 */

    IMOS_AREA_DIRECTION_MAX,
    IMOS_AREA_DIRECTION_INVALID  = 0XFFFFFFFF
} IMOS_AREA_DIRECTION_E;

/**
* @enum tagOptionName
* @brief 选项名枚举
* @attention
*/
typedef enum tagOptionName
{
    OPTION_NAME_CC_SERVER_ADDR      = 0,            /**< CC的服务器地址, 对应结构 : (CHAR *) */
    OPTION_IMOS_ROOT_PATH           = 1,            /**< IMOSROOT环境变量, 对应结构 : (CHAR *) */
    OPTION_PROTOCOL_PORT_RANGE      = 2,            /**< 协议的端口范围, 对应结构 : (PORT_RANGE_S *) */
    OPTION_MEDIA_PORT_RANGE         = 3,            /**< 媒体流的端口范围,对应结构 : (PORT_RANGE_S *) */
    OPTION_NAME_SERVER_IMG_PORT      = 4,         /**< IMG的服务器端口, 对应结构 : (USHORT) */

    OPTION_NAME_MAX,
    OPTION_NAME_INVALID             = 0XFFFFFFFF
} OPTION_NAME_E;

/** @brief ECR编码长度 */
#define IMOS_ECR_CODE_LEN               (IMOS_CODE_LEN - 8)

/*@brief 系统支持的干线的最大数 */
#define IMOS_TRUNK_MAXNUM                       32

/*@brief 干线允许的最大内容数目 */
#define IMOS_TRUNK_CONTENT_MAXNUM               256

/* Begin Added by liuhongjieKF0170,2013-8-28 of 支持区块OSD */
/** 3D遮盖区域最大个数 */
#define IMOS_MAX_3D_COVER_AREA_NUM     8
/* End Added by liuhongjieKF0170,2013-8-28 of 支持区块OSD */

/** 回调函数处理信息类型 */
typedef enum tagCallBackProcType
{
    PROC_TYPE_DEV_STATUS            = 0,            /**< 设备状态，对应结构 : AS_STAPUSH_UI_S */
    PROC_TYPE_ALARM                 = 1,            /**< 告警，对应结构 : AS_ALARMPUSH_UI_S */
    PROC_TYPE_DEV_CAM_SHEAR         = 2,            /**< 共享摄像机，对应结构 : AS_DEVPUSH_UI_S */
    PROC_TYPE_MONITOR_BE_REAVED     = 3,            /**< 实况被抢占，对应结构 : CS_MONITOR_REAVE_NOTIFY_S */
    PROC_TYPE_SWITCH_BE_REAVED      = 4,            /**< 轮切被抢占，对应结构 : CS_SWITCH_REAVE_NOTIFY_S */
    PROC_TYPE_MONITOR_BE_STOPPED    = 5,            /**< 实况被停止，对应结构 : CS_MONITOR_REAVE_NOTIFY_S */
    PROC_TYPE_SWITCH_BE_STOPPED     = 6,            /**< 轮切被停止，对应结构 : CS_SWITCH_REAVE_NOTIFY_S */
    PROC_TYPE_VOCSRV_BE_REAVED      = 7,            /**< 语音被抢占，对应结构 : CS_VOCSRV_REAVE_NOTIFY_S */
    PROC_TYPE_PTZ_EVENT             = 8,            /**< 云台事件通知，对应结构 : CS_PTZ_REAVE_NOTIFY_S */
    PROC_TYPE_TRB_PROC              = 9,            /**< 故障处理通知，对应结构 : CS_NOTIFY_UI_TRB_EVENT_PROC_S */
    PROC_TYPE_SRV_SETUP             = 10,           /**< 故障恢复业务建立通知，对应结构 : CS_NOTIFY_UI_SRV_SETUP_S */
    PROC_TYPE_XP_ALARM_SETUP        = 11,           /**< 告警联动到XP窗格通知，对应结构 : CS_NOTIFY_UI_SRV_SETUP_S */

    PROC_TYPE_LOGOUT                = 12,           /**< 退出登陆，对应结构 :无 */

    PROC_TYPE_MEDIA_PARAM_CHANGE    = 13,           /**< 媒体参数改变，对应结构 : CS_NOTIFY_UI_MEDIA_PARAM_CHANGE_PROC_S */

    PROC_TYPE_EXDOMAIN_STATUS       = 14,           /**< 外域状态，对应结构 : AS_EXDOMAIN_STAPUSH_UI_S */

    PROC_TYPE_BACKUP_DATA_FINISH    = 15,           /**< 信息备份完成通知, 对应结构 : CS_BACKUP_FINISH_INFO_S */

    PROC_TYPE_TL_EVENT              = 16,           /**< 透明通道事件通知，对应结构 : CS_TL_REAVE_NOTIFY_S */

    PROC_TYPE_SALVO_UNIT_EVENT      = 17,           /**< 组显示单元事件通知, 对应结构 : CS_NOTIFY_SALVO_UNIT_EVENT_S */
    PROC_TYPE_SALVO_EVENT           = 18,           /**< 组切业务事件通知, 对应结构 : CS_NOTIFY_UI_SALVO_EVENT_S */
    PROC_TYPE_START_XP_SALVO        = 19,           /**< 通知UI启动组轮巡的组显示, 对应结构: CS_NOTIFY_START_XP_SALVO_S */

    PROC_TYPE_VODWALL_BE_REAVED     = 20,           /**< 通知回放上墙被抢占，对应结构：CS_VODWALL_REAVE_NOTIFY_S */
    PROC_TYPE_VODWALL_BE_STOPPED    = 21,           /**< 通知回放上墙被停止，对应结构：CS_VODWALL_REAVE_NOTIFY_S */

    PROC_TYPE_VOD_BE_REAVED         = 22,           /**< 回放被抢占，对应结构 : CS_VOD_REAVE_NOTIFY_S */

    PROC_TYPE_DOMAIN_SYN_RESULT     = 23,           /**< 域间同步的结果，对应结构 : AS_DOMAIN_SYN_PUSHUI_S */

    PROC_TYPE_VOC_REQ               = 24,           /**< 客户端语音请求，对应结构 : CS_VOC_REQ_NOTIFY_S */
    PROC_TYPE_VOC_STATE_NOTIFY      = 25,           /**< 语音业务状态通知，对应结构 : CS_VOC_STATE_NOTIFY_S */

    PROC_TYPE_PLAN_ALARM_CHG_REPORT = 26,           /**< 预案告警变化上报，对应结构：PLAN_ALARM_CHG_PUSH_UI_S */
    PROC_TYPE_EVENT_SECURITY_CHG_REPORT = 27,       /**< 系统级别信息变化上报，对应结构：EVENT_SECURITY_CHG_PUSH_UI_S */
	PROC_TYPE_OSD_NAME_CHANGED		= 30,			/**< 通知人机Preview用户OSD变更，对应结构: AS_NOTIFY_OSD_NAME_UI_S */
	PROC_TYPE_MASK_AREA_CHANGED		= 31,			/**< 通知人机Preview用户遮挡区域变更，对应结构: AS_NOTIFY_EC_MASK_AREA_UI_S */

    PROC_TYPE_PTZ_STATUS_EVENT      = 32,           /**< 云台状态变更通知，对应结构 : CS_PTZ_STATUS_NOTIFY_S */
    PROC_TYPE_DEL_EXDOMAIN_RESULT   = 33,           /**< 删除外域结果，对应结构: AS_DEL_EXDOMAIN_PUSH_UI_S*/
    /* Added by dengshuhua00673, 2013-02-20 of 自动布局轮巡 */
    PROC_TYPE_START_XP_AUTOSALVO    = 34,           /**< 通知UI启动自动布局组轮巡, 对应结构: CS_NOTIFY_START_XP_AUTOSALVO_S */

    /** Begin:add by sunxiaojisKF0138, 2013-7-21 of NVRV3R1 **/
    PROC_TYPE_GET_CHANNEL_MSG_FROM_CS_TO_UI = 35,      /**< 透明通道上行透传消息给第三方 */
    /** End:add by sunxiaojisKF0138, 2013-7-21 of NVRV3R1 **/

    /* Begin added by baoyihui02795, 2011-04-28 of 卡口项目 */
    PROC_TYPE_VEHICLE_DATA          = 90,           /**< 通知实时车辆信息，对应结构:VEHICLE_REAL_TIME_DATA_S */
    PROC_TYPE_VEHICLE_ALARM_DATA    = 91,           /**< 通知实时车辆报警，对应结构:VEHICLE_ALARM_DATA_S */
    PROC_TYPE_GIS_DEV_STATUS        = 92,           /**< 通知GIS设备状态变化，对应结构：DEVICE_GIS_STATUS_DATA_S */
    /* End added by baoyihui02795, 2011-04-28 of 卡口项目 */
    PROC_TYPE_ELEC_BULLETIN_CHANGE  = 93,           /**< 电子公告变化上报，对应结构：ELEC_BULLETIN_PUSH_UI_S */

    /*******************************************************************************
    SS新增定义 新增回调函数
    *******************************************************************************/
    PROC_TYPE_ACCEPT_SPEAK_YESORNO  = 100,           /**< 发言申请， 对应结构 ：CONF_SITE_INFO_EX_S */
    PROC_TYPE_CONF_STATUS_CHANGE    = 101,           /**< 会议状态改变， 对应结构 ：CONF_STATUS_INFO_EX_S 如果是周期会议且非最后一个周期，上报会议未开始/其它上报会议已经结束 */
    PROC_TYPE_DEVICE_CODE_CHANGE    = 102,           /**< 设备编码改变， 对应结构 ：DEVICE_CODE_CHANGE_INFO_EX_S */
    PROC_TYPE_DEVICE_CHANGE         = 103,           /**< 终端设备更新信息， 当存在设备新增、删除时， 上报更新消息， 对应的结构 ：DEVICE_CHANGE_INFO_EX_S */
    PROC_TYPE_MODIFY_TERM           = 104,           /**< 修改终端消息， 对应的结构 ：MODIFY_TERM_REP_EX_S */
    PROC_TYPE_CHAIR_CHANGE          = 105,           /**< 当前主席发生改变， 主席会场释放则会场编码为空。对应的结构 ：CONF_SITE_INFO_EX_S */
    PROC_TYPE_SPEAKER_CHANGE        = 106,           /**< 当前发言人发生改变， 对应的结构 ：CONF_SITE_INFO_EX_S */
    PROC_TYPE_TERM_STATUS_CHANGE    = 107,           /**< 会场终端状态改变， 对应的结构 ：TERM_STATUS_CHANGE_EX_S */
    PROC_TYPE_DELAY_CONF            = 108,           /**< 延迟会议， 对应结构 ：DELAY_CONF_INFO_EX_S */
    PROC_TYPE_SYNCHRONIZE_WITH_WEB  = 109,           /**< 上报广播会场， 主席、主场观看会场 对应的结构 ： MC_SYNCHRONIZE_WITH_WEB_EX_S  */
    PROC_TYPE_MCU_BACKUP_CHANGE_TO_MASTER  = 110,    /**< MCU备份通知， 对应结构 ：BACKUP_MCU_REPORT_S  */
    PROC_TYPE_SEND_ROLE_SITE_CHANGE = 111,           /**< 当前辅流发送者变化通知， 对应结构 ：CONF_SEND_ROLE_SITE_CHANGE_S  */
    PROC_TYPE_AUTOMULTIPIC_CHANGE   = 112,           /**< 多画面自动切换值改变通知， 对应结构 ：CONF_AUTOMULTIPIC_CHANGE_S  */
    PROC_TYPE_SET_TURN_BROADCAST_CHANGE = 113,       /**< 设置画面轮询模式改变通知， 对应结构 ：CONF_SET_TURN_BROADCAST_CHANGE_S */
    PROC_TYPE_SET_PIC_MODE_CHANGE   = 114,           /**< 设置画面模式改变通知， 对应结构 ：CONF_SET_PIC_MODE_CHANGE_S */
    PROC_TYPE_MCU_SYNC_STATUS_CHANGE = 115,          /**< MCU同步状态改变通知， 对应结构 ：MCU_SYNC_STATUS_CHANGE_S */
    PROC_TYPE_CUR_BROADCAST_CHANGE   = 116,          /**< 当前实际广播会场改变通知，对应结构：CUR_BROADCAST_INFO_EX_S */
    PROC_TYPE_CUR_CHAIR_BROWSE_CHANGE     = 117,     /**< 当前主席或主场实际观看的会场改变通知，对应结构：CUR_CHAIR_BROWSE_INFO_EX_S */
    PROC_TYPE_CONF_FECC_CHANGE       = 118,          /**< 当前FECC控制者或被控者变化通知，对应结构：CONF_FECC_CHANGE_S */
    PROC_TYPE_CONF_MCU_BACKUP_CHANGE      = 119,     /**< 当前会议中MCU备份变化通知，对应结构：CONF_MCU_BACKUP_CHANGE_S */
    PROC_TYPE_CALL_SITE_RESULT       = 120,          /**< 呼叫会场结果通知，对应结构：CALL_SITE_INFO_EX_S */
    PROC_TYPE_GK_REG_STATE           = 121,          /**< GK注册结果通知，对应结构：GK_REG_STATE_INFO_EX_S */
    PROC_TYPE_MG_SESSION_STATUS_CHANGE    = 122,     /**< 终端会话状态，对应结构：MG_SESSION_STATUS_EX_S */
    PROC_TYPE_FREE_STORE_RES_SUCCEED = 123,          /**< 存储资源被释放，对应结构 : FREE_STORE_RES_SUCCEED_S */
    PROC_TYPE_MEDIA_STATUS_NOTIFY    = 124,          /**< 媒体状态通知消息，对应结构 : MEDIA_STATUS_NOTIFY_S */
    /* Begin added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */
    PROC_TYPE_ALARM_LINKAGE_VOCTALK = 125,          /**< 告警联动到语音对讲通知，对应结构 : ALARM_LINKAGE_VOCTALK_TO_UI_S */
    /* End added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */

    /* ECR对应的回调函数，从400开始 */
    PROC_TYPE_MMI_VOUT_INFO_CHANGE             = 400,      /**<人机组切输出端口基本信息改变.对应结构体MMI_VOUT_INFO_FOR_ECR_S */
    PROC_TYPE_MMI_VOUT_WINLIST_CHANGE          = 401,      /**<人机组切预览窗格摄像机序列信息改变, 对应结构体: MMI_VOUT_WINLIST_INFO_FOR_ECR_S */
    PROC_TYPE_VIRTUAL_CHANNEL_STATUS_CHANGE    = 402,      /**<虚拟通道基本信息改变，对应结构体VIRTUAL_CHANNEL_BIND_STATUS_S */

    /* Begin: Added by chenyongfa, 2013-05-03 of IVSD00832 */
    PROC_TYPE_VIRTUAL_CHANNEL_INFO_CHANGE       = 403,               /**<虚拟通道分辨率/帧率改变，对应结构体VIRTUAL_CHANNEL_BIND_STATUS_S */
    /* End: Added by chenyongfa, 2013-05-03 of IVSD00832 */
    /* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
    PROC_TYPE_LOCK_SPACE_NOTIFY    = 404,          /**< 检查锁定空间通知消息，对应结构 : AS_SM_LOCK_SPACE_NOTIFY_S */
    PROC_TYPE_LOCK_FAILURE_NOTIFY    = 405,          /**< 摄像机上线重下发通知消息，对应结构 : AS_SM_LOCK_FAILURE_NOTIFY_S */
    /* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
	/* Begin: Added by y01359, 2015-04-27 for A8 */
    PROC_TYPE_TV_WALL_POLL_INFO_NOTIFY       = 406,               /**<电视墙场景轮询信息，对应结构体CS_TVWALL_POLL_INFO_NOTIFY_S */
    /* End: Added by y01359, 2015-04-27 for A8 */
	 /* Add by liujian/02319, 2016-10-13 for MPPD41303 */
    PROC_TYPE_USER_LOGIN_REAVE_NOTIFY   = 407,      /**< 用户登陆抢占通知消息，对应结构体: LOGIN_REAVE_NOTIFY_S*/

    PROC_TYPE_TRAFFIC_EVENT = 408,                  /**< 交通事件，对应结构 : TMS_TRAFFIC_EVENT_S */

    PROC_TYPE_MAX,                                   /**< 回调函数处理信息类型最大值 */
    PROC_TYPE_INVALID                = 0xFFFFFFFF    /**< 无效值 */
}CALL_BACK_PROC_TYPE_E;

/** 云台推送UI的事件枚举类型定义 */
typedef enum tagPtzNotifyUIEventType
{
    PTZ_NOTIFY_TYPE_RELEASE_TIME_OUT                = 0,    /** 云台连接空闲超时 连接被释放 */
    PTZ_NOTIFY_TYPE_REAVED                          = 1,    /** 云台被强占，连接释放 */
    PTZ_NOTIFY_TYPE_TROUBLE                         = 2,    /** 云台故障，连接释放 */
    PTZ_NOTIFY_TYPE_USER_HAS_NO_AUTHORITY           = 3,    /** 用户无云台控制权限 */
    PTZ_NOTIFY_TYPE_PTZ_USER_HAS_LOWER_AUTHORITY    = 4,    /** 用户权限低 */
    PTZ_NOTIFY_TYPE_PTZ_HAS_LOCKED_BY_OTHER         = 5,    /** 云台被其他用户锁定 */
    /* Added by wangyaqi,KF1963,2010-12-07 of VVD50927 */
    PTZ_NOTIFY_TYPE_PTZ_CCB_FULL                    = 6,    /** 控制块已满 */
    PTZ_NOTIFY_TYPE_MAX,
    PTZ_NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}PTZ_NOTIFY_UI_EVENT_TYPE;

/** 组显示单元推送事件枚举类型定义 */
typedef enum tagSalvoUnitNotifyUIEventType
{
    SALVO_UNIT_NOTIFY_TYPE_START_FAIL       = 0,    /** 组显示单元建立实况失败 */
    SALVO_UNIT_NOTIFY_TYPE_BE_REAVED        = 1,    /** 组显示单元的实况被抢占 */
    SALVO_UNIT_NOTIFY_TYPE_SAME_EXIST       = 2,    /** 相同的组显示单元的实况已存在 */
    SALVO_UNIT_NOTIFY_TYPE_SAME_CREATING    = 3,    /** 相同的组显示单元的实况正在建立 */
    SALVO_UNIT_NOTIFY_TYPE_TROUBLE          = 4,    /** 故障引起组显示单元实况释放 */
    SALVO_UNIT_NOTIFY_TYPE_RESUME_SUCC      = 5,    /** 组显示单元恢复实况 */
    SALVO_UNIT_NOTIFY_TYPE_RES_MODIFY       = 6,    /** 组显示修改引起单元实况释放 */
    SALVO_UNIT_NOTIFY_TYPE_USER_STOP        = 7,    /** 用户停止组显示单元 */

    SALVO_UNIT_NOTIFY_TYPE_MAX,
    SALVO_UNIT_NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}SALVO_UNIT_NOTIFY_UI_EVENT_TYPE_E;

/** 组切业务推送事件枚举类型定义 */
typedef enum tagSalvoNotifyEventType
{
    NOTIFY_TYPE_SALVO_BE_STOPPED                = 0,    /** 组显示业务被停止 */
    NOTIFY_TYPE_SALVO_BE_REAVED                 = 1,    /** 组显示业务被抢占 */
    NOTIFY_TYPE_GROUPSALVO_BE_STOPPED           = 2,    /** 组轮巡业务被停止 */
    NOTIFY_TYPE_GROUPSALVO_BE_REAVED            = 3,    /** 组轮巡业务被抢占 */
    NOTIFY_TYPE_GROUPSALVO_STOP_SALVO_PER_TIME  = 4,    /** 组轮巡切换停止组显示 */
    NOTIFY_TYPE_SALVO_ALL_MON_UNACTIVE          = 5,    /** 组显示业务中所有实况待恢复 */

    NOTIFY_TYPE_MAX,
    NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}SALVO_NOTIFY_EVENT_TYPE_E;

/*@brief 推送信息处理回调函数类型，ulProcType为处理类型，枚举值为CALL_BACK_PROC_TYPE_E */
typedef VOID (STDCALL *CALL_BACK_PROC_PF)(IN ULONG_32 ulProcType, IN VOID *pParam);

/** 告警类型 */
typedef enum tagAlarmType
{
    /** MIB告警 1~200 */
    AlARM_TYPE_HIGH_TEMPERATURE         = 1,    /**< 高温告警 */
    AlARM_TYPE_LOW_TEMPERATURE          = 2,    /**< 低温告警 */
    AlARM_TYPE_TEMPERATURE_RESUME       = 3,    /**< 温度告警恢复 */
    AlARM_TYPE_FAN_FAULT                = 4,    /**< 风扇故障告警 */
    AlARM_TYPE_FAN_FAULT_RESUME         = 5,    /**< 风扇故障告警恢复 */
    ALARM_TYPE_FLASH_OPERATE            = 6,    /**< Flash操作告警 */
    ALARM_TYPE_CPU_EXCEED               = 7,    /**< CPU利用率过高告警 */
    ALARM_TYPE_MEMOY_EXCEED             = 8,    /**< 内存利用率过高告警 */
    ALARM_TYPE_REBOOT                   = 9,    /**< 设备重启 */
    ALARM_TYPE_DEVICE_CONFIG_CHANGE     = 10,   /**< 设备配置变更 */
    AlARM_TYPE_DISK_ERR                 = 11,   /**< 磁盘故障 */
    AlARM_TYPE_DISK_ERR_RECOVER         = 12,   /**< 磁盘故障恢复 */
    AlARM_TYPE_DISK_POWER_ON            = 13,   /**< 磁盘上线 */
    AlARM_TYPE_DISK_POWER_OFF           = 14,   /**< 磁盘下线 */
    AlARM_TYPE_RAID_EXCEPTION           = 15,   /**< 阵列异常告警 */
    AlARM_TYPE_RAID_REBUILD_START       = 16,   /**< 进入重建状态 */
    AlARM_TYPE_RAID_REBUILD_FINISH      = 17,   /**< 退出重建 */
    AlARM_TYPE_STP_EXEC_EXCEPTION       = 18,   /**< 未按计划录像告警 */
    AlARM_TYPE_STP_EXEC_RECOVER         = 19,   /**< 未按计划录像恢复告警 */
    AlARM_TYPE_IPSAN_NO_ACCESS          = 20,   /**< 无法访问IPSAN存储设备告警 */
    AlARM_TYPE_IPSAN_NO_ACCESS_RECOVER  = 21,   /**< 无法访问IPSAN存储设备恢复告警 */
    AlARM_TYPE_STORED_DATA_READ_ERR     = 22,   /**< 读取存储数据失败 */
    AlARM_TYPE_STORED_DATA_SEEK_ERR     = 23,   /**< 定位存储设备失败 */
    AlARM_TYPE_VOD_OVER_THRESHOLD       = 24,   /**< 点播路数超出阈值 */
    AlARM_TYPE_VOD_UNDER_THRESHOLD      = 25,   /**< 点播流数量恢复 */
    ALARM_TYPE_TEMPERATURE              = 26,   /**< 温度告警 */
    AlARM_TYPE_CAM_BAK_OWN_UNDER_THR    = 27,   /**< 摄像机独享备份资源容量使用达到阈值恢复 */
    AlARM_TYPE_CAM_BAK_SHARD_OVER_THR   = 28,   /**< 摄像机共享备份资源容量使用达到阈值 */
    AlARM_TYPE_CAM_BAK_SHARD_UNDER_THR  = 29,   /**< 摄像机共享备份资源容量使用达到阈值恢复 */
    AlARM_TYPE_CAM_BAK_OWN_CAP_SCANT    = 30,   /**< 摄像机独享备份资源配置满停止策略时，资源剩余容量不足 */
    AlARM_TYPE_CAM_BAK_OWN_CAP_ENOUGH   = 31,   /**< 摄像机独享备份资源配置满停止策略时，资源剩余容量不足恢复 */
    AlARM_TYPE_BAK_RES_CAP_SCANT        = 32,   /**< 全局备份配置满停止策略时，全局资源剩余容量不足 */
    AlARM_TYPE_BAK_RES_CAP_ENOUGH       = 33,   /**< 全局备份配置满停止策略时，全局资源剩余容量不足恢复 */
    AlARM_TYPE_BAK_RES_ABNORMAL         = 34,   /**< 备份资源异常 */
    AlARM_TYPE_BAK_RES_NORMAL           = 35,   /**< 备份资源异常恢复 */
    AlARM_TYPE_BAK_FAILED               = 36,   /**< 备份任务执行失败 */
    AlARM_TYPE_CAM_BAK_OWN_OVER_THR     = 37,   /**< 摄像机独享备份资源容量使用达到阈值 */
    /* Begin: Added by mozhanfei(kf0149), 2013-9-9 for 新增异常恢复告警 */
    AlARM_TYPE_RAID_EXCEPTION_RECOVER           = 38,   /**< 阵列异常恢复告警 */
    /* End: Added by mozhanfei(kf0149), 2013-7-18 for 新增异常恢复告警 */

    AlARM_TYPE_PREVENT_REMOVAL          = 71,   /**< 防拆告警 */
    AlARM_TYPE_PREVENT_REMOVAL_RESUME   = 72,   /**< 防拆告警恢复 */

    /* Begin: Added by wangxiaozhi(w01677), 2015-1-29 for 新增VX1600告警 */
    AlARM_TYPE_DISK_REMOVA_NOT_IN_RAID  = 73,   /**< 不在RAID中的磁盘被拔出 */
    AlARM_TYPE_DISK_REMOVA_IN_RAID      = 74,   /**< 在Raid中的磁盘被拔出 */
    AlARM_TYPE_DISK_ERR_REMOVA_IN_RAID  = 75,   /**< 在Raid中的磁盘故障 */
    /* End: Added by wangxiaozhi(w01677), 2015-1-29 for 新增VX1600告警 */

	/*Begin added by liangchao, 2015-12-09 for 多次登录失败告警*/
	AlARM_TYPE_MULTI_LOGIN_FAIL         =76,
	/*End added by liangchao, 2015-12-09 for 多次登录失败告警*/

    /* Begin: Added by limengni 03868, 2017-10-11 for MPPD46920 */
    AlARM_TYPE_STOR_THRES  = 80,  /**<手动备份文件存储空间达到阈值告警 */
    AlARM_TYPE_STOR_THRES_RESUME  = 81,  /**<手动备份文件存储空间达到阈值告警恢复 */
    /* End: Added by limengni 03868, 2017-10-11 for MPPD46920 */

    /* Begin add by zhengyibing(01306), 2015/01/13 for MPPD08280 */
    AlARM_TYPE_SERVER_ACTION_REPORT      = 193,   /**< 平台主动警情报警 */
    /* End add by zhengyibing(01306), 2015/01/13 for MPPD08280 */

    /* Begin added by baoyihui02795, 2011-04-28 of 卡口项目 */
    ALARM_TYPE_FLASHLIGHT_FAULT         = 194,   /**< 闪光灯故障 */
    ALARM_TYPE_FLASHLIGHT_FAULT_RESUME  = 195,   /**< 闪光灯故障恢复 */
    ALARM_TYPE_STOR_RES_ABNORMAL        = 196,   /**< 存储资源异常 */
    ALARM_TYPE_STOR_RES_NORMAL          = 197,   /**< 存储资源异常恢复 */
    ALARM_TYPE_COIL_DISABLED            = 198,   /**< 线圈失效 */
    ALARM_TYPE_COIL_ENABLED             = 199,   /**< 线圈失效恢复 */
    /* End added by baoyihui02795, 2011-04-28 of 卡口项目 */

    /** SIP告警 201~ */
    AlARM_TYPE_VIDEO_LOST               = 201,  /**< 视频丢失告警 */
    AlARM_TYPE_VIDEO_LOST_RESUME        = 202,  /**< 视频丢失告警恢复 */
    AlARM_TYPE_MOVE_DETECT              = 203,  /**< 运动检测告警 */
    AlARM_TYPE_MOVE_DETECT_RESUME       = 204,  /**< 运动检测告警恢复 */
    AlARM_TYPE_MASK_DETECT              = 205,  /**< 遮挡侦测告警 */
    AlARM_TYPE_MASK_DETECT_RESUME       = 206,  /**< 遮挡侦测告警恢复 */
    AlARM_TYPE_INPUT_SWITCH             = 207,  /**< 输入开关量告警 */
    AlARM_TYPE_INPUT_SWITCH_RESUME      = 208,  /**< 输入开关量告警恢复 */
    AlARM_TYPE_SHORT_CIRCUIT            = 209,  /**< 开关量线路短路告警 */
    AlARM_TYPE_BREAKER_CIRCUIT          = 210,  /**< 开关量线路断路告警 */
    AlARM_TYPE_SHORT_CIRCUIT_RESUME     = 211,  /**< 开关量线路短路告警恢复 */
    AlARM_TYPE_STOR_FULL_PRE            = 212,  /**< 存储即将满告警 */
    AlARM_TYPE_STOR_FULL                = 213,  /**< 满存储告警 */
    AlARM_TYPE_STOR_FAILED              = 214,  /**< 存储读写失败告警 */
    AlARM_TYPE_STOR_FAILED_RESUME       = 215,  /**< 存储读写失败告警恢复 */
    AlARM_TYPE_DEVICE_ONLINE            = 216,  /**< 设备上线告警 */
    AlARM_TYPE_DEVICE_OFFLINE           = 217,  /**< 设备下线告警 */
    AlARM_TYPE_BREAKER_CIRCUIT_RESUME   = 219,  /**< 开关量线路断路告警恢复 */

    /* Begin Added by yangzichao(w1856), for支持平台上下线告警*/
    ALARM_TYPE_OUTER_DOMAIN_ONLINE		= 220,  /**< 外域上线 */
    ALARM_TYPE_OUTER_DOMAIN_OFFLINE		= 221,  /**< 外域下线 */
    /*End Added by yangzichao(w1856), for支持平台上下线告警*/

    AlARM_TYPE_STREAM_STOR_CAM_WARN     = 222,  /**< 摄像机存储停止告警 */

    AlARM_TYPE_EXT_STOR_FULL_PRE        = 223,  /**< 远端存储即将满告警 */
    AlARM_TYPE_EXT_STOR_FULL            = 224,  /**< 远端存储满告警 */
    AlARM_TYPE_EXT_STOR_FAILED          = 225,  /**< 远端存储读写失败告警 */
    AlARM_TYPE_EXT_STOR_FAILED_RESUME   = 226,  /**< 远端存储读写失败告警恢复 */

    AlARM_TYPE_STOR_NO_ENOUGH_SPACE     = 229,  /**< 摄像机所在磁盘存储空间不足告警 */
    AlARM_TYPE_STOR_DEL_FILE_FAILED     = 230,  /**< 删除老文件失败告警 */

    AlARM_TYPE_BEHAVIOR                 = 231,  /**< 行为告警 */
    AlARM_TYPE_BEHAVIOR_RESUME          = 232,  /**< 行为告警恢复 */

    ALARM_TYPE_STREAM_BREAK             = 233,  /**< 摄像机断流告警 */

    /* Begin: Added by luhaitao/01337, 2015-01-13 for 丢帧告警上报 */
    ALARM_TYPE_STOR_LOST_FRAME          = 234,  /**< 存储丢帧告警 */
    /* End: Added by luhaitao/01337, 2015-01-13 for 丢帧告警上报 */

    AlARM_TYPE_SOUND_ABNORMAL           = 241,  /**< 异常声音告警 */
    AlARM_TYPE_SOUND_ABNORMAL_RESUME    = 242,  /**< 异常声音告警恢复 */

    /* Begin: Added by zhouquanwei/z01364, 2014-12-04 for 实况联动 */
    AlARM_TYPE_MON_START                = 251,  /**< 启动实况告警 */
    /* End: Added by zhouquanwei/z01364, 2014-12-04 for 实况联动 */

    ALARM_TYPE_CROSS_LINE               = 301,  /**< 触发智能拌线 */
    ALARM_TYPE_INTROSION_ZONE           = 302,  /**< 区域入侵 */
    ALARM_TYPE_ACCESS_ZONE              = 303,  /**< 进入区域 */
    ALARM_TYPE_LEAVE_ZONE               = 304,  /**< 离开区域 */
    ALARM_TYPE_HOVER_ZONE               = 305,  /**< 区域徘徊 */
    ALARM_TYPE_OVER_FENCE               = 306,  /**< 翻越围栏 */
    ALARM_TYPE_CARE_ARTICLE             = 307,  /**< 物品看护 */
    ALARM_TYPE_REMAIN_ARTICLE           = 308,  /**< 物品遗留 */
    /* Begin Added by zhangchi zW4385 2017-09-08 for MPPD24025 */
    ALARM_TYPE_GATHER                   = 309,  /**< 人员聚集 */
    ALARM_TYPE_FAST_MOVE                = 310,  /**< 快速移动 */
    ALARM_TYPE_CAR_STOP                 = 311,  /**< 停车 */
    ALARM_TYPE_OUT_FOCUS                = 312,  /**< 虚焦 */
    ALARM_TYPE_OUT_FOCUS_RESUME         = 313,  /**< 虚焦告警恢复 */
    ALARM_TYPE_SCENCE_CHANGE            = 314,  /**< 场景变更 */
    ALARM_TYPE_FACE_DETECT              = 315,  /**< 人脸检测 */
    ALARM_TYPE_CAR_DETECT               = 316,  /**< 道路监控 */
    ALARM_TYPE_PEOPLE_COUNT             = 317,  /**< 人数统计 */
    ALARM_TYPE_GATHER_RESUME            = 318,  /**< 人员聚集恢复 */
    ALARM_TYPE_HEATMAP                  = 319,  /**< 热力图 */
    /*End Added by zhangchi zW4385 2017-09-08 for MPPD24025 */
    ALARM_TYPE_ILLEGALLY_PARKED         = 320,  /**< 违法停车 */
    ALARM_TYPE_PRESS_LINE_DRIVING       = 321,  /**< 压线 */
    ALARM_TYPE_REVERSE_DRIVING          = 322,  /**< 逆行 */
    ALARM_TYPE_ILLEGAL_DETECT_START     = 323,  /**< 检测抓拍开始 */
    ALARM_TYPE_ILLEGAL_DETECT_OVER      = 324,  /**< 检测抓拍结束 */
    ALARM_TYPE_ILLEGAL_DETECT_AWAY      = 325,  /**< 检测目标离开 */
    ALARM_TYPE_ILLEGAL_DETECT_CLEAN     = 326,  /**< 历史检测目标清除 */
    AlARM_TYPE_IPSAN_WRITE_ERR          = 327,  /*存储写入图片失败*/
    AlARM_TYPE_FORWARD_SEND_ERR         = 328,  /*发送失败告警*/
    AlARM_CDS_TYPE_STOR_FULL            = 329,  /**< 满存储告警 */

    //traffic flow


    /* Begin: Added by zhongke */
    ALARM_TYPE_TRAFFIC_FLOW     = 336,  /**< 车流量 */
    /* Begin: Added by luhaitao/01337, 2015-01-13 for 丢帧告警上报 */

    /* 手工告警 401~ */
    AlARM_TYPE_IMPERATIVE_EVENT         = 401,  /**< 紧急告警 */

    ALARM_TYPE_BAKEUP_LINK_SWITCH       = 402,  /**< 主备链路切换告警 */

    /* Begin: Added by luhaitao/01337, 2016-05-21 for 前端过车告警支持 */
    ALARM_TYPE_VEHICLE_DETECTOR_FAILED = 701,                                                                       /**< 红绿灯检测器离线告警 */
    ALARM_TYPE_VEHICLE_DETECTOR_FAILED_RESUME  = 702,                                                 /**< 红绿灯检测器离线告警恢复 */
    ALARM_TYPE_VEHICLE_RADAR_FAILED = 703,                                                                                /**< 雷达故障 */
    ALARM_TYPE_VEHICLE_RADAR_FAILED_RESUME = 704,                                                           /**< 雷达故障恢复 */
    ALARM_TYPE_VEHICLE_LASER_DETECTOR_FAILED = 705,                                                      /**< 激光检测器故障 */
    ALARM_TYPE_VEHICLE_LASER_DETECTOR_FAILED_RESUME = 706,                                 /**< 激光检测器故障恢复 */
    ALARM_TYPE_VEHICLE_INFRARED_DETECTOR_FAILED = 707,                                              /**< 红外检测器故障 */
    ALARM_TYPE_VEHICLE_INFRARED_DETECTOR_FAILED_RESUME = 708,                         /**< 红外检测器故障恢复 */
    ALARM_TYPE_VEHICLE_GROUND_SENSOR_DETECTOR_FAILED = 709,                             /**< 地感检测器故障 */
    ALARM_TYPE_VEHICLE_GROUND_SENSOR_DETECTOR_FAILED_RESUME = 710,        /**< 地感检测器故障恢复 */
    ALARM_TYPE_VEHICLE_FLASHLIGHT_FAILED = 711,                                                                     /**< 闪光灯故障 */
    ALARM_TYPE_VEHICLE_FLASHLIGHT_FAILED_RESUME = 712,                                                /**< 闪光灯故障恢复 */
    /* End: Added by luhaitao/01337, 2016-05-21 for 前端过车告警支持 */

    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */
    ALARM_TYPE_WATER_LEVEL_GAUGE_FAILED                                  = 716, /**< 水位计故障告警 */
    ALARM_TYPE_WATER_LEVEL_GAUGE_FAILED_RESUME                           = 717, /**< 水位计故障告警恢复 */
    ALARM_TYPE_WATERLOGGING_DETECTOR_FAILED                              = 718, /**< 水浸检测器故障告警 */
    ALARM_TYPE_WATERLOGGING_DETECTOR_FAILED_RESUME                       = 719, /**< 水浸检测器故障告警恢复 */
    ALARM_TYPE_O2_DETECTOR_FAILED                                        = 720, /**< 氧气浓度检测仪故障告警 */
    ALARM_TYPE_O2_DETECTOR_FAILED_RESUME                                 = 721, /**< 氧气浓度检测仪故障告警恢复 */
    ALARM_TYPE_H2S_DETECTOR_FAILED                                       = 722, /**< 硫化氢浓度检测仪故障告警 */
    ALARM_TYPE_H2S_DETECTOR_FAILED_RESUME                                = 723, /**< 硫化氢浓度检测仪故障告警恢复 */
    ALARM_TYPE_CH4_DETECTOR_FAILED                                       = 724, /**< 甲烷浓度检测仪故障告警 */
    ALARM_TYPE_CH4_DETECTOR_FAILED_RESUME                                = 725, /**< 甲烷浓度检测仪故障告警恢复 */
    ALARM_TYPE_CO_DETECTOR_FAILED                                        = 726, /**< 一氧化碳浓度检测仪故障告警 */
    ALARM_TYPE_CO_DETECTOR_FAILED_RESUME                                 = 727, /**< 一氧化碳浓度检测仪故障告警恢复 */
    ALARM_TYPE_LED_FAILED                                                = 728, /**< LED灯故障告警 */
    ALARM_TYPE_LED_FAILED_RESUME                                         = 729, /**< LED灯故障告警恢复 */
    ALARM_TYPE_PUMP_FAILED                                               = 730, /**< 水泵故障告警 */
    ALARM_TYPE_PUMP_FAILED_RESUME                                        = 731, /**< 水泵故障告警恢复 */
    ALARM_TYPE_BLOWER_FAILED                                             = 732, /**< 风机故障告警 */
    ALARM_TYPE_BLOWER_FAILED_RESUME                                      = 733, /**< 风机故障告警恢复 */
    ALARM_TYPE_AIR_VALVE_FAILED                                          = 734, /**< 风阀故障告警 */
    ALARM_TYPE_AIR_VALVE_FAILED_RESUME                                   = 735, /**< 风阀故障告警恢复 */
    ALARM_TYPE_ELECTRONIC_MANHOLE_COVER_FAILED                           = 736, /**< 电子井盖故障告警 */
    ALARM_TYPE_ELECTRONIC_MANHOLE_COVER_FAILED_RESUME                    = 737, /**< 电子井盖故障告警恢复 */
    ALARM_TYPE_ANNUNCIATOR_FAILED                                        = 738, /**< 声光报警器故障告警 */
    ALARM_TYPE_ANNUNCIATOR_FAILED_RESUME                                 = 739, /**< 声光报警器故障告警恢复 */
    ALARM_TYPE_MEGAPHONE_FAILED                                          = 740, /**< 喊话器故障告警 */
    ALARM_TYPE_MEGAPHONE_FAILED_RESUME                                   = 741, /**< 喊话器故障告警恢复 */
    ALARM_TYPE_INDUSTRIAL_TELEPHONE_FAILED                               = 742, /**< 工业电话机故障告警 */
    ALARM_TYPE_INDUSTRIAL_TELEPHONE_FAILED_RESUME                        = 743, /**< 工业电话机故障告警恢复 */
    ALARM_TYPE_AUTOMATIC_FIRE_EXTINGUISHER_FAILED                        = 744, /**< 自动灭火器故障告警 */
    ALARM_TYPE_AUTOMATIC_FIRE_EXTINGUISHER_FAILED_RESUME                 = 745, /**< 自动灭火器故障告警恢复 */
    ALARM_TYPE_WIRELESS_AP_FAILED                                        = 746, /**< 无线AP故障告警 */
    ALARM_TYPE_WIRELESS_AP_FAILED_RESUME                                 = 747, /**< 无线AP故障告警恢复 */
    ALARM_TYPE_ACCESS_CONTROLLER_FAILED                                  = 748, /**< 门禁控制器故障告警 */
    ALARM_TYPE_ACCESS_CONTROLLER_FAILED_RESUME                           = 749, /**< 门禁控制器故障告警恢复 */
    ALARM_TYPE_UPS_FAILED                                                = 750, /**< UPS故障告警 */
    ALARM_TYPE_UPS_FAILED_RESUME                                         = 751, /**< UPS故障告警恢复 */
    ALARM_TYPE_STORAGE_BATTERY_FAILED                                    = 752, /**< 蓄电池故障告警 */
    ALARM_TYPE_STORAGE_BATTERY_FAILED_RESUME                             = 753, /**< 蓄电池故障告警恢复 */
    ALARM_TYPE_INFRARED_DETECTOR_FAILED                                  = 754, /**< 红外对射探测器故障告警 */
    ALARM_TYPE_INFRARED_DETECTOR_FAILED_RESUME                           = 755, /**< 红外对射探测器故障告警恢复 */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_FAILED        = 756, /**< 线型光纤测温探测器故障告警 */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_FAILED_RESUME = 757, /**< 线型光纤测温探测器故障告警恢复 */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */

    AlARM_TYPE_NM_PROTECT_EVENT         = 800,  /**< 跨域N+M保护类告警, 主要用于跨域N+M保护告警订阅,
                                                     订阅后相当于订阅了存储失败、存储停止两个告警 */
    AlARM_TYPE_EVENT_PICTURE           = 801,   /**< 图片事件上报 */

    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */
    ALARM_TYPE_PIPLINE_LEVEL_HIGH                               = 900,  /**< 集水坑水位过高告警 */
    ALARM_TYPE_PIPLINE_LEVEL_HIGH_RESUME                        = 901,  /**< 集水坑水位过高告警恢复 */
    ALARM_TYPE_WATERLOGGING_DETECTOR_DETECTED                   = 902,  /**< 水浸检测器告警 */
    ALARM_TYPE_WATERLOGGING_DETECTOR_DETECTED_RESUME            = 903,  /**< 水浸检测器告警恢复 */
    ALARM_TYPE_O2_LEVEL_LOW                                     = 904,  /**< 氧气浓度过低告警 */
    ALARM_TYPE_O2_LEVEL_HIGH                                    = 905,  /**< 氧气浓度过高告警 */
    ALARM_TYPE_O2_LEVEL_RESUME                                  = 906,  /**< 氧气浓度告警恢复 */
    ALARM_TYPE_H2S_LEVEL_HIGH                                   = 907,  /**< 硫化氢浓度过高告警 */
    ALARM_TYPE_H2S_LEVEL_HIGH_RESUME                            = 908,  /**< 硫化氢浓度过高告警恢复 */
    ALARM_TYPE_CH4_LEVEL_HIGH                                   = 909,  /**< 甲烷浓度过高告警 */
    ALARM_TYPE_CH4_LEVEL_HIGH_RESUME                            = 910,  /**< 甲烷浓度过高告警恢复 */
    ALARM_TYPE_CO_LEVEL_HIGH                                    = 911,  /**< 一氧化碳浓度过高告警 */
    ALARM_TYPE_CO_LEVEL_HIGH_RESUME                             = 912,  /**< 一氧化碳浓度过高告警恢复 */
    ALARM_TYPE_UPS_LOW                                          = 929,  /**< UPS电量过低告警 */
    ALARM_TYPE_UPS_LOW_RESUME                                   = 930,  /**< UPS电量过低告警恢复 */
    ALARM_TYPE_STORAGE_BATTERY_LOW                              = 931,  /**< 蓄电池电量过低告警 */
    ALARM_TYPE_STORAGE_BATTERY_LOW_RESUME                       = 932,  /**< 蓄电池电量过低告警恢复 */
    ALARM_TYPE_INFRARED_DETECTOR_DETECTED                       = 933,  /**< 红外对射探测器告警 */
    ALARM_TYPE_INFRARED_DETECTOR_DETECTED_RESUME                = 934,  /**< 红外对射探测器告警恢复 */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_HIGH = 935,  /**< 线型光纤测温探测器高温告警 */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_HIGH_RESUME = 936,  /**< 线型光纤测温探测器高温告警恢复 */
    /**   ALARM_TYPE_IOT_LABEL = 1000~1099   RFID标签类告警 */
    ALARM_TYPE_IOT_LABEL_IN                       = 1001,   /**< 标签进入读头(DAE/超感IPC) */
    ALARM_TYPE_LABEL_OUT                          = 1002,   /**< 标签离开读头(DAE/超感IPC) */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */

    /* Begin added by zhukaikai/W4801, 2017-12-28 for 地标器特性 MPPD54420 */
    ALARM_TYPE_LANDMARK_IN                        = 1003,   /**< 地标器标签进入 */
    ALARM_TYPE_LANDMARK_OUT                       = 1004,   /**< 地标器标签离开 */
    /* End added by zhukaikai/W4801, 2017-12-28 for 地标器特性 MPPD54420 */

    /* Begin added by baoyihui02795, 2011-04-28 of 卡口项目 */
    /** 卡口业务告警 2001~ */
    ALARM_TYPE_DISPOSITION_STOLEN_VEHICLE         = 2001,   /**< 被盗车 */
    ALARM_TYPE_DISPOSITION_ROBBED_VEHICLE         = 2002,   /**< 被抢车 */
    ALARM_TYPE_DISPOSITION_SUSPICION_VEHICLE      = 2003,   /**< 嫌疑车 */
    ALARM_TYPE_DISPOSITION_TRAFFIC_VIOLATION      = 2004,   /**< 交通违法车 */
    ALARM_TYPE_DISPOSITION_EMERGENCY_SURVEILLANCE = 2005,   /**< 紧急查控车 */
    ALARM_TYPE_VEHICLE_BLACKLIST                  = 2006,   /**< 黑名单 */
    ALARM_TYPE_OTHER_VEHICLE_ALARM                = 2007,   /**< 其他车辆违法行为 */
    ALARM_TYPE_P2P_SPEED_DETECTION                = 2008,   /**< 区间测速违章 */
    ALARM_TYPE_NOT_WHITELIST                      = 2009,   /**< 非白名单车辆 */
    /* End added by baoyihui02795, 2011-04-28 of 卡口项目 */
    ALARM_TYPE_P2P_TIME_DETECTION                 = 2010,   /**< 区间超时违章 *//*Added by c02845, 2015-11-05,of MPPD31387 */

    /* Begin added by zhuzhicong/02302 2016年6月30日11:32:37，新增新国标告警类型 2011~ */
    /* 告警类型‘alarmmethod’ */
    AlARM_TYPE_TELEPHONE                          = 2011,   /**< 电话报警 */
    AlARM_TYPE_DEVICE                             = 2012,   /**< 设备报警 */
    AlARM_TYPE_NOTE                               = 2013,   /**< 短信报警 */
    AlARM_TYPE_GPS                                = 2014,   /**< GPS报警 */
    AlARM_TYPE_VEDIO                              = 2015,   /**< 视频报警 */
    AlARM_TYPE_DEVICE_FAULT                       = 2016,   /**< 设备故障报警 */
    AlARM_TYPE_OTHER                              = 2017,   /**< 其它报警 */

    /* 告警类型‘alarmtype’ */
    AlARM_TYPE_ARTIFICIAL_VIDEO                   = 2018,   /**< 人工视频报警 */
    AlARM_TYPE_TRAFFIC_ANALYSIS                   = 2019,   /**< 流量统计报警 */
    AlARM_TYPE_DENSITY_DETECTION                  = 2020,   /**< 密度检测报警 */
    AlARM_TYPE_VIDEO_ERROR                        = 2021,   /**< 视频异常检测报警 */
    AlARM_TYPE_MOVE_FAST                          = 2022,   /**< 快速移动报警 */
    AlARM_TYPE_MOVE_FACE                          = 2023,   /**< 人脸检测报警 */
    /* End added by zhuzhicong/02302 2016年6月30日11:32:37，新增新国标告警类型 */

    /* Begin added by zhangchi zW4385, 2017-08-28 of MPPD50528 NVR上支持智能跟踪开始和结束告警 */
    AlARM_TYPE_SMART_TRACK_BEGIN                  = 2025,   /**< 智能跟踪开始告警*/
    AlARM_TYPE_SMART_TRACK_FINISH                 = 2026,   /**< 智能跟踪结束告警*/
    /* End added by zhangchi zW4385, 2017-08-28 of MPPD50528 NVR上支持智能跟踪开始和结束告警  */

    ALARM_TYPE_WEITING_ALERT_PRE                      = 3001,   /**违停预警*//*Begin added by yaozhongmin 02844 date: Jul 03 2016 for 违停预警*/
    ALARM_TYPE_TRAFFIC_EVENT                          = 3002,   /** 交通事件 */

    /*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
    ALARM_TYPE_RFID_DISPOSITION_STOLEN_VEHICLE                  = 3011,   /**< RFID被盗车 */
    ALARM_TYPE_RFID_DISPOSITION_ROBBED_VEHICLE                 = 3012,   /**< RFID被抢车 */
    ALARM_TYPE_RFID_DISPOSITION_TRAFFIC_VIOLATION              = 3013,   /**< RFID多次违章车> */
    ALARM_TYPE_RFID_DISPOSITION_SUSPICION_VEHICLE            = 3014,   /**< RFID嫌疑车 */
	ALARM_TYPE_RFID_DISPOSITION_BREAK_IN                   = 3018,   /**< RFID禁区闯入 */
    ALARM_TYPE_RFID_OTHER_VEHICLE_ALARM                               = 3019,   /**< RFID其他违法行为 */

    ALARM_TYPE_MAC_DISPOSITION_SUSPICION_PERSON             = 3021,   /**< MAC嫌疑人> */
    ALARM_TYPE_MAC_DISPOSITION_KILLED_PERSON                    = 3022,   /**< MAC被害人>*/
    ALARM_TYPE_MAC_DISPOSITION_IMPORTANT_PERSON           = 3023,   /**< MAC重点人员>*/
    ALARM_TYPE_MAC_DISPOSITION_CASE_INVOLVED_PERSON    = 3024,   /**< MAC涉案人员>*/
    ALARM_TYPE_MAC_DISPOSITION_OTHER_PERSON                     = 3029,   /**< MAC其他违法行为>*/
    /*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

	/* Begin added by s03924 for MPPD53784 2017/11/25 */
    ALARM_TYPE_TRAFFICFLOW_CONGESTION                   = 3040,              /**<交通流拥堵告警 */
    /* End added by s03924 for MPPD53784 2017/11/25 */

    AlARM_TYPE_MAX,                         /**< 最大值 */

    AlARM_TYPE_ALL      = 0xFFFE,           /**< 所有告警的特殊标记 */
    AlARM_TYPE_INVALID  = 0xFFFF            /**< 无效值 */
}AlARM_TYPE_E;

/* Begin: Added by luchunfeng02289, 2015-12-08 for 告警分类 */
/** 告警类型分类 */
typedef enum tagAlarmClass
{
    ALARM_CLASS_DEVICE     = 1,     /**< 设备类告警 */
	ALARM_CLASS_SERVICE    = 2,     /**< 业务类告警 */
	ALARM_CLASS_STORAGE    = 3,     /**< 存储类告警 */

	ALARM_CLASS_MAX,
    ALARM_CLASS_INVALID = 0xFF
}ALARM_CLASS_E;
/* End: Added by luchunfeng02289, 2015-12-08 for 告警分类 */

/**
* @enum tagDevStatusBit
* @brief 设备状态位枚举
* @attention
*/
typedef enum tagDevStatusBit
{
    DEV_STATUS_BIT_DEVICE_OFFLINE       = 0,    /**< 设备下线 */
    DEV_STATUS_BIT_HIGH_TEMPERATURE     = 1,    /**< 设备高温 */
    DEV_STATUS_BIT_LOW_TEMPERATURE      = 2,    /**< 设备低温 */
    DEV_STATUS_BIT_FAN_FAULT            = 3,    /**< 设备风扇故障 */
    DEV_STATUS_BIT_VIDEO_LOST           = 4,    /**< 视频丢失 */
    DEV_STATUS_BIT_MOVE_DETECT          = 5,    /**< 运动检测 */
    DEV_STATUS_BIT_MASK_DETECT          = 6,    /**< 遮挡侦测 */
    DEV_STATUS_BIT_STOR_FAILED          = 7,    /**< 存储读写失败 */
    DEV_STATUS_BIT_INPUT_SWITCH         = 8,    /**< 输入开关量 */
    DEV_STATUS_BIT_SHORT_CIRCUIT        = 9,    /**< 开关量线路短路 */
    DEV_STATUS_BIT_BREAKER_CIRCUIT      = 10,   /**< 开关量线路断路 */
    DEV_STATUS_BIT_BEHAVIOR_ALARM       = 11,   /**< 行为告警 */
    DEV_STATUS_BIT_COIL_DISABLED        = 32,   /**< 线圈失效 */

    DEV_STATUS_BIT_MAX_NUM              = 128   /**< 最大值 */
}DEV_STATUS_BIT_E;

/**
* @enum tagManualStoreStatus
* @brief 存储状态枚举
* @attention
*/
typedef enum tagManualStoreStatus
{
    MANUAL_STORE_STATUS_STOP  =  0,                   /**< 存储状态为停止 */
    MANUAL_STORE_STATUS_START   = 1,                  /**< 存储状态为开始 */

    MANUAL_STORE_STATUS_MAX,                          /**< 存储状态最大值 */
    MANUAL_STORE_STATUS_INVALID = 0XFFFFFFFF
}MANUAL_STORE_STATUS_E;

#ifndef LANG_SETING_OF_E
#define LANG_SETING_OF_E
/**
* @enum LANG_SETTING
* @brief 产品化的中英文设置枚举值(如操作日志的语言设置)
* @attention
*/
typedef enum LANG_SETTING
{
    LANG_CN = 0,                        /* < 简体中文 */
    LANG_EN = 1,                        /* < 英文 */

    LANG_MAX,                           /* < 最大值 */
    LANG_INVALID                        /* < 其他语言 */
} MW_LANGUAGE_E;
#endif
/**
* @enum tagTerminalDevLang
* @brief 终端设备(EC/DC)的语言设置枚举值
* @attention
*/
typedef enum tagTerminalDevLang
{
    TERMINAL_DEV_LANG_CN = 1,                /* < 简体中文(终端配置) */
    TERMINAL_DEV_LANG_EN = 2,                /* < 英文(终端配置) */

    TERMINAL_DEV_LANG_MAX,                   /* < 最大值 */
    TERMINAL_DEV_LANG_INVALID                /* < 其他语言 */
} TD_LANGUAGE_E;

/** 动作类型 */
typedef enum tagActionType
{
    ACTION_TYPE_PRESET          = 0,    /**< 预置位 */
    ACTION_TYPE_BOOLEAN_OUTPUT  = 1,    /**< 开关量输出 */
    ACTION_TYPE_STORE           = 2,    /**< 存储 */
    ACTION_TYPE_BUZZER          = 4,    /**< 蜂鸣器 */
    ACTION_TYPE_CENTER_STORE    = 5,    /**< 中心域存储 */
    ACTION_TYPE_GIS             = 10,   /**< GIS */
    ACTION_TYPE_MON_LIVE        = 11,   /**< 实况到监视器 */
    ACTION_TYPE_PANE_LIVE       = 12,   /**< 实况到用户窗格 */
    ACTION_TYPE_BACKUP          = 13,   /**< 备份*/
    ACTION_TYPE_SMS             = 14,   /**< 短信*/
    ACTION_TYPE_EMAIL           = 15,   /**< 邮件*/
    ACTION_TYPE_END_TASK        = 16,   /**< 结束任务*/
    ACTION_TYPE_START_TASK      = 17,   /**< 开始任务*/
    ACTION_TYPE_CREATE_NEW_ALARM  = 18,   /**< 产生新告警*/
    ACTION_TYPE_TRAN_ALARM      = 19,   /**< 转发告警*/
    ACTION_TYPE_PLAN            = 20,   /**< 预案*/
    /* Added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */
    ACTION_TYPE_VOCTALK        = 21,   /**< 语音对讲 */
    /* Added by y01359, 2014-11-13 for 告警联动到A8场景 */
    ACTION_TYPE_TVWALL_SCENE   = 22,   /**< A8场景 */
    ACTION_TYPE_TVWALL_MONITOR = 23,   /**< A8实况 */

    ACTION_TYPE_MAX,                    /**< 最大值 */
    ACTION_TYPE_INVALID = 0xFFFFFFFF    /**< 无效值 */
}ACTION_TYPE_E;

/** 用户状态枚举 */
typedef enum tagUserStatus
{
    USER_STATUS_LOCK    = 1,    /**< 锁定 */
    USER_STATUS_UNLOCK  = 2,    /**< 解锁 */
    USER_STATUS_ONLINE  = 3,    /**< 在线 */
    USER_STATUS_OFFLINE = 4,    /**< 离线 */

    USER_STATUS_MAX,                       /**< 最大值 */
    USER_STATUS_INVALID = 0xFFFFFFFF       /**< 无效值 */
}USER_STATUS_E;

/**
* @enum tagASCameraStatus
* @brief 摄像机状态枚举
* @attention
*/
typedef enum tagASCameraStatus
{
    AS_CAMERA_STATUS_ONLINE         = 1,    /**< 摄像机在线 ,和IMOS_DEV_STATUS_ONLINE取值一样*/
    AS_CAMERA_STATUS_OFFLINE        = 2,    /**< 摄像机离线 */
    AS_CAMERA_STATUS_VIDEO_LOST     = 3,    /**< 摄像机视频丢失 */
    AS_CAMERA_STATUS_VIDEO_RESUME   = 4,    /**< 摄像机视频恢复 */

    AS_CAMERA_STATUS_REPAIRE        = 5,   /**< 摄像机报修中 ，枚举5~8在推送进来时使用，用于级联推送给上级域，域内不使用*/
    AS_CAMERA_STATUS_MOVE           = 6,   /**< 摄像机搬迁中 */
    AS_CAMERA_STATUS_BUILD          = 7,   /**< 摄像机在建中 */
    AS_CAMERA_STATUS_POWEROFF       = 8,   /**< 摄像机断电中 */

    AS_CAMERA_STATUS_MAX,
    AS_CAMERA_STATUS_INVALID = 0xFFFFFFFF
}AS_CAMERA_STATUS_E;

/** 区域类型枚举 */
typedef enum tagVideoAreaType
{
    VIDEO_AREA_TYPE_MASK          = IMOS_VIDEO_AREA_TYPE_MASK,           /**< 遮盖区域 */
    VIDEO_AREA_TYPE_COVER_DETECT  = IMOS_VIDEO_AREA_TYPE_COVER_DETECT,   /**< 遮挡区域 */
    VIDEO_AREA_TYPE_MOTION_DETECT = IMOS_VIDEO_AREA_TYPE_MOTION_DETECT,  /**< 运动检测区域 */
    VIDEO_AREA_TYPE_ROI           = IMOS_VIDEO_AREA_TYPE_ROI,            /**< 区域增强 */

    VIDEO_AREA_TYPE_MAX,                   /**< 最大值 */
    VIDEO_AREA_TYPE_INVALID = 0xFFFFFFFF   /**< 无效值 */
}VIDEO_AREA_TYPE_E;

/** 告警严重级别枚举 */
typedef enum tagAlarmSeverityLevel
{
    ALARM_SEVERITY_CRITICAL = 0,    /**< 危急 */
    ALARM_SEVERITY_MAJOR    = 1,    /**< 主要 */
    ALARM_SEVERITY_MINOR    = 2,    /**< 次要 */
    ALARM_SEVERITY_WARN     = 3,    /**< 警告 */
    ALARM_SEVERITY_INFO     = 4,    /**< 提示 */

    ALARM_SEVERITY_MAX      = 31,   /**< 最大值 */
    ALARM_SEVERITY_ALL      = 0xFFFFFFFE,   /**< 所有告警级别的特殊标记 */
    ALARM_SEVERITY_INVALID  = 0xFFFFFFFF    /**< 无效值 */
}ALARM_SEVERITY_LEVEL_E;

/**
* @enum tagCtrlMode
* @brief 外域管理模式
* @attention 无
*/
typedef enum tagCtrlMode
{
    CTRL_MODE_NORMAL = 0,               /**< 普通管理模式 */
    CTRL_MODE_FULL = 1,                 /**< 强管理模式 */

    CTRL_MODE_MAX,                      /**< 最大值 */
    CTRL_MODE_INVALID = 0xFFFFFFFF      /**< 无效值 */
}FULL_CTRL_MODE_E;

/**
* @enum tagSrvType
* @brief 业务类型,包括登录、配置（用户、角色、权限、设备、资源）、实况类、语音类、云台控制、预置位、巡航线路、存储类、回放类
* @attention 无
*/
typedef enum tagSrvType
{
    SRV_TYPE_LOGIN          = 0,                        /**< 登录 */
    SRV_TYPE_CONFIG_USER    = 1,                        /**< 用户配置:给用户分配角色 */
    SRV_TYPE_CONFIG_ROLE    = 2,                        /**< 角色配置 */
    SRV_TYPE_CONFIG_DEV     = 4,                        /**< 设备配置 */
    SRV_TYPE_CONFIG_RES     = 5,                        /**< 资源配置(包括存储资源,备份，流转存资源等) */

    SRV_TYPE_CONFIG_STORAGE_PLAN    = 6,                /**< 存储计划配置 */
    SRV_TYPE_CONFIG_SWITCH_PLAN     = 7,                /**< 轮切计划配置 */
    SRV_TYPE_CONFIG_CRUISE_PLAN     = 8,                /**< 巡航计划配置 */

    SRV_TYPE_CONFIG_PTZ     = 9,                        /**< 云台配置 */
    SRV_TYPE_CONFIG_TL      = 10,                       /**< 透明通道的配置 */
    SRV_TYPE_VOD            = 11,                       /**< 回放:标签增删 */

    SRV_TYPE_MONITOR            = 12,                   /**< 实时监控 */
    SRV_TYPE_SWITCH             = 13,                   /**< 轮切 */
    SRV_TYPE_PLAN_SWITCH        = 14,                   /**< 计划轮切 */
    SRV_TYPE_VOICE_TALK         = 15,                   /**< 语音对讲 */
    SRV_TYPE_VOICE_BROADCAST    = 16,                   /**< 语音广播 */
    SRV_TYPE_PTZ                = 17,                   /**< 云台控制 */
    SRV_TYPE_TL                 = 18,                   /**< 透明通道 */

    SRV_TYPE_BOOLEAN    = 19,                           /**< 开关量 */

    SRV_TYPE_MAP        = 20,                           /**< 地图配置(上传,删除,修改,下载,设置缺省地图) */

    SRV_TYPE_STORAGE    = 22,                           /**< 存储 */

    SRV_TYPE_SYS_BACKUP = 23,                           /**< 系统信息备份 */

    SRV_TYPE_SUBSCRIBE  = 24,                           /**< 订阅上报业务 */

    SRV_TYPE_TRUNK      = 25,                           /**< 干线操作业务 */

    SRV_TYPE_CONFIG_BACKUP_PLAN = 26,                   /**< 备份计划配置 */

    SRV_TYPE_BACKUP     = 27,                           /**< 备份 */

    SRV_TYPE_SALVO      = 28,                           /**< 组显示 */
    SRV_TYPE_GROUPSALVO         = 29,                   /**< 组轮巡 */
    SRV_TYPE_GROUPSALVO_PLAN    = 30,                   /**< 组轮巡计划 */

    /* added by z06806 for vodwall prj 20101202 begin */
    SRV_TYPE_VODWALL            = 31,                   /**< 回放上墙 */
    /* added by z06806 for vodwall prj 20101202 end */

    SRV_TYPE_CONFIG_TIME = 32,                          /**< 时间配置 */

    SRV_TYPE_REBOOT = 33,                               /**< 重启 */

    SRV_TYPE_SHUTDOWN = 34,                             /**< 关机 */

    SRV_TYPE_RESTORE_DEFAULT = 35,                      /**< 恢复默认 */

    SRV_TYPE_VOD_AND_DOWNLOAD = 36,                      /**< 回放和下载 */

    SRV_TYPE_CONFIG_STREAM_STORAGE_PLAN = 37,                   /**< 流转存计划配置 */

    SRV_TYPE_SMS = 38,                                  /**< 短信 */

    SRV_TYPE_EMAIL = 39,                                /**< 邮件 */

    SRV_TYPE_SYS_PARAM_SET = 40,                        /**< 系统参数配置 */
    SRV_TYPE_VOICE_USER_TALK         = 41,              /**< 客户端语音对讲 */
    SRV_TYPE_VOICE_USER_BROADCAST    = 42,              /**< 客户端语音广播 */
    SRV_TYPE_MON_USER_TALK           = 43,              /**< 客户端音视频对讲 */
    SRV_TYPE_MON_USER_BROADCAST      = 44,              /**< 客户端音视频广播 */

    SRV_TYPE_CONFIG_ACTION_PLAN = 45,                   /**< 预案配置 */

    SRV_TYPE_PLAN = 46,                                 /**< 预案 */

    SRV_TYPE_EVENT = 47,                                /**< 事件使能 */

    SRV_TYPE_RESTART = 48,                                /**< 服务器重启 */

    /* Added by dengshuhua00673, 2012-12-22 of 自动布局轮巡 */
    SRV_TYPE_AUTOSALVO = 49,                            /**< 自动布局轮巡 */

	SRV_TYPE_CONFIG_GUARD_POSITION_PLAN  = 50,          /**< 看守位计划配置 */

	SRV_TYPE_GUARD_POSITION_PLAN  = 51,          /**< 看守位计划 */

    /* Begin added by y01359 2014-10-09 for A8 */
	SRV_TYPE_TVWALL             = 52,                   /**< 电视墙 */

	SRV_TYPE_TVWALL_OPERATE     = 53,                   /**< 电视墙sip操作 */
    /* End added by y01359 2014-10-09 for A8 */

    /* Begin: Added by chenmenglin 04110, 2017-09-09 for MPPD54245 A8拼控设备轮巡特性 */
    SRV_TYPE_AUTOPOLL           = 54,                   /**< A8自动布局轮巡 */
    SRV_TYPE_WINDOWGROUPPOLL    = 55,                  /**< A8窗口组轮巡 */
    /* End: Added by chenmenglin 04110, 2017-09-09 for MPPD54245 A8拼控设备轮巡特性 */

    SRV_TYPE_TOLLGATE           = 99,                   /**< 卡口电警 */

    SRV_TYPE_PTZ_LOCK           = 171,
    SRV_TYPE_PTZ_UNLOCK           = 172,
    SRV_TYPE_SERVICE_VOD = 361,                                 /**< 回放 */
    SRV_TYPE_SERVICE_DOWNLOAD = 362,                            /**< 下载 */
    SRV_TYPE_SERVICE_LOCAL_STOR = 363,                            /**< 本地录像 */

    SRV_TYPE_MAX,
    SRV_TYPE_INVALID = 0xFFFFFFFF
}SRV_TYPE_E;

/** 操作结果枚举 */
typedef enum tagOperateResult
{
    OPERATE_RESULT_SUCCESS  = 0,    /**< 成功 */
    OPERATE_RESULT_FAIL     = 1,    /**< 失败 */

    OPERATE_RESULT_MAX,                     /**< 最大值 */
    OPERATE_RESULT_INVALID = 0xFFFFFFFF     /**< 无效值 */
}OPERATE_RESULT_E;

typedef enum tagOperateType
{
    OPERATE_USER_LOGIN  = 0,    /**< 用户登陆 */
    OPERATE_USER_LOGOUT = 1,    /**< 用户登出 */

    OPERATE_USER_START  = 2,    /**< 用户启动业务 */
    OPERATE_USER_STOP   = 3,    /**< 用户停止业务 */

    OPERATE_CONFIG_ADD  = 4,    /**< 新增配置 */
    OPERATE_CONFIG_MOD  = 5,    /**< 修改配置 */
    OPERATE_CONFIG_DEL  = 6,    /**< 删除配置 */

    OPERATE_FILE_DOWNLOAD   = 7,    /**< 文件下载 */

/*****************服务器主动发起的动作类型(开始)*******************/

    OPERATE_DEV_OFFLINE_STOP    = 8,    /**< 设备下线停止 */
    OPERATE_DEV_DELETE_STOP     = 9,    /**< 设备删除停止 */
    OPERATE_DEV_ONLINE_STOP     = 10,   /**< 设备上线清除业务 */

    OPERATE_USER_QUIT_STOP      = 11,   /**< 用户退出停止 */
    OPERATE_USER_DELETE_STOP    = 12,   /**< 用户删除停止 */
    OPERATE_USER_KEEPOUT_STOP   = 13,   /**< 用户保活失败清除业务 */

    OPERATE_EXTDOMAIN_OFFLINE_STOP  = 14,   /**< 外域下线停止 */
    OPERATE_EXTDOMAIN_DELETE_STOP   = 15,   /**< 外域删除停止 */
    OPERATE_EXTDOMAIN_ONLINE_STOP   = 16,   /**< 外域上线清除业务 */

    OPERATE_SRV_TRANSFER_STOP   = 17,   /**< 业务转移停止 */
    OPERATE_SRV_TRANSFER_START  = 18,   /**< 业务转移启动 */
    OPERATE_SRV_REAVE_STOP      = 19,   /**< 业务抢占停止 */
    OPERATE_SRV_RESTORE_START   = 20,   /**< 故障恢复启动 */

    OPERATE_SRV_TIMEOUT_STOP    = 21,   /**< 超时停止 */

    OPERATE_CONFIG_MOD_STOP = 22,   /**< 配置变化停止 */

    OPERATE_ALARM_START = 23,       /**< 告警联动启动 */
    OPERATE_ALARM_STOP  = 24,       /**< 告警联动停止 */

    OPERATE_PLAN_START  = 25,       /**< 计划触发的启动 */
    OPERATE_PLAN_STOP   = 26,       /**< 计划触发的停止 */

/*****************服务器主动发起的动作类型(结束)*******************/

    OPERATE_ADJUST_FORWARD = 27,    /**< 轮切下一个操作 */
    OPERATE_ADJUST_BACKWARD = 28,   /**< 轮切上一个操作 */
    OPERATE_ADJUST_PAUSE = 29,      /**< 轮切暂停操作 */
    OPERATE_ADJUST_CONTINUE = 30,   /**< 轮切继续操作 */

    OPERATE_TRUNK_START = 31,       /**< 启动干线操作 */
    OPERATE_TRUNK_STOP = 32,        /**< 停止干线操作 */
    OPERATE_TRUNK_APPLY = 33,       /**< 申请干线操作 */
    OPERATE_TRUNK_FREE = 34,        /**< 释放干线操作 */

    OPERATE_FILE_LOCK     = 35,     /**< 文件锁定 */
    OPERATE_FILE_UNLOCK   = 36,     /**< 文件解锁 */
    OPERATE_FILE_DELETE   = 37,     /**< 文件删除 */

    OPERATE_USER_RESTART  = 38,     /**< 用户重启业务 */

    OPERATE_ALARM_RESUME  = 39,     /**< 告警联动恢复 */
    OPERATE_USER_ACCEPT   = 40,     /**< 用户接受业务 */
    OPERATE_USER_REJECT   = 41,     /**< 用户拒绝业务 */

    OPERATE_ALARM_EXE_TASK = 42,    /**< 用户执行任务 */
    OPERATE_ALARM_LAUNCH_TRIGGER = 43,    /**< 用户运行触发器 */
    OPERATE_ALARM_START_PLAN = 44,    /**< 用户启动预案 */

    OPERATE_THIRD_DEVICE_ERROR = 45,  /**<第三方设备错误  */

    OPERATE_USER_RESTART_VMSERVER = 46,  /**<用户重启服务器 */
    /* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
    OPERATE_RECORD_LOCK     = 47,     /**< 录像锁定 */
    OPERATE_RECORD_UNLOCK   = 48,     /**< 录像解锁 */
    OPERATE_CHECK_LOCK_SPACE = 49,     /**< 检查锁定空间*/
    /* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
    /* Begin Added by lw0581,2013-11-6 for  VVD06374*/
    OPERATE_STORAGE_NOTIFY_TWARE    = 50,    /**< 向TWARE通知存储空间变化 */
    OPERATE_EXPORT_VEDIO_TO_USB     = 51,    /**< 录像导出到U盘 */
    OPERATE_EXPORT_PIC_TO_USB       = 52,    /**< 图片导出到U 盘 */
    OPERATE_CONFIG_QUERY            = 53,    /**< 查询配置 */
    OPERATE_EXPORT_PROCESS_QUERY    = 54,    /**< 查询导出进度 */
    OPERATE_USB_DISK_QUERY          = 55,    /**< 查询U盘信息 */
    OPERATE_USB_DIR_QUERY           = 56,    /**< 查询U盘文件夹信息 */
    OPERATE_RECORD_REPLAY           = 57,    /**< 录像回放 */
    OPERATE_RECORD_DOWNLOAD         = 58,    /**< 录像下载 */
    OPERATE_PIC_REMOTE_EXPORT       = 59,    /**< 图片远程导出 */
    /* End Added by lw0581,2013-11-6 for  VVD06374*/
    /*Begin: Added by mozhanfei(m01736), 2014-7-2 for add query vedio operate log*/
    OPERATE_RECORD_QUERY           = 60,    /**< 查询录像*/
    /*End: Added by mozhanfei(m01736), 2014-7-2 for add query vedio operate log*/
    /* Begin add by z00562 for 富顺*/
    OPERATE_TG_RECORD_DEL  = 61,
    /* End add by z00562 for 富顺*/
    /* Begin add by z00562 for 日志服务器 */
    OPERATE_TG_RECORD_QUERY  = 62,
    OPERATE_TG_IMAGE_DOWNLOAD = 63,
    OPERATE_TG_RECORD_DOWNLOAD  = 64,
    OPERATE_TG_RECORD_CHECK  = 65,
    /* End add by z00562 for 日志服务器 */

	/* Begin add by y01359, 2016-03-24 for A8 */
	OPERATE_A8_SCENE_START = 66,       /**< A8场景操作启动 */
    OPERATE_A8_SCENE_STOP  = 67,       /**< A8场景操作停止 */
    /* End add by y01359, 2016-03-24 for A8 */

    /* Begin: Added by chenmenglin 04110, 2017-11-10 for MPPD54245 A8拼控设备轮巡特性 */
    OPERATE_A8_AUTOPOLL_START = 68,      /**< A8拼控轮巡操作启动 */
    OPERATE_A8_AUTOPOLL_STOP  = 69,       /**< A8拼控轮巡操作停止 */
    /* End: Added by chenmenglin 04110, 2017-11-10 for MPPD54245 A8拼控设备轮巡特性 */

    OPERATE_TYPE_MAX,
    OPERATE_TYPE_INVALID = 0xFF
}OPERATE_TYPE_E;

/** 外域类型 */
typedef enum tagExDomainType
{
    EX_DOMAIN_SUPERIOR  = 1,    /**< 上级域 */
    EX_DOMAIN_JUNIOR    = 2,    /**< 下级域 */
    EX_DOMAIN_PARITY    = 3,    /**< 同级域 */


    EX_DOMAIN_SAFE_VM     = 10001,    /**< VM安全接入域 */
    EX_DOMAIN_SAFE_DVR    = 10002,    /**< DVR安全接入域 */
    EX_DOMAIN_SAFE_MATRIX = 10003,    /**< 矩阵安全接入域 */

    EX_DOMAIN_MAX,                      /**< 最大值 */
    EX_DOMAIN_INVALID = 0xFFFFFFFF      /**< 无效值 */
}EX_DOMAIN_TYPE_E;

/** 存储模式 */
typedef enum tagStorageMode
{
    STORAGE_MODE_IPSAN  = 1,    /**< 中心IPSAN存储模式*/
    STORAGE_MODE_NAS    = 2,    /**< NAS 存储模式*/
    STORAGE_MODE_LOCAL  = 3,    /**< 本地硬盘存储模式*/

    STORAGE_MODE_MAX ,                     /**< 最大值*/
    STORAGE_MODE_INVALID = 0xFFFFFFFF,     /**< 无效值*/

}STORAGE_MODE_E;

/**
* @enum tagASDEVShareOperationType
* @brief 设备共享操作类型枚举
* @attention
*/
typedef enum tagASDEVShareOperationType
{
    AS_DEVSHARE_OPERATION_DEL   = 0,    /**< 共享设备取消 */
    AS_DEVSHARE_OPERATION_ADD   = 1,    /**< 共享设备新增 */
    AS_DEVSHARE_OPERATION_MOD   = 2,    /**< 共享设备修改 */
    AS_DEVSHARE_OPERATION_QUERY = 3,    /**< 共享设备主动查询 */

    AS_DEVSHARE_OPERATION_MAX,
    AS_DEVSHARE_OPERATION_INVALID = 0xFFFFFFFF
}AS_DEVSHARE_OPERATION_TYPE_E;

/**
* @enum tagIMOSType
* @brief 类型定义
* @attention IMOS公共资源类型枚举(从15到1003是告警源,告警源设备需要在此范围内,非告警源设备不能在此范围内)
*            4001-5000为视讯类型
*            201-300为视讯设备
*            设备类型的取值范围为11-2000
*/
typedef enum tagIMOSType
{
    IMOS_TYPE_ORG = 1,                     /**< 组织域 */
    IMOS_TYPE_OUTER_DOMAIN = 2,            /**< 外域 */
    IMOS_TYPE_LOCAL_DOMAIN = 3,            /**< 本域 */
    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */
    IMOS_TYPE_CABIN = 4,                   /**< 舱室,是客户端虚拟的概念,平台暂不使用 */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */

    IMOS_TYPE_DEVICE_MIN_VALUE = 10,       /**< 设备资源类型最小值 */

    IMOS_TYPE_DM = 11,                     /**< DM */
    IMOS_TYPE_MS = 12,                     /**< MS */
    IMOS_TYPE_VX500 = 13,                  /**< VX500 */
    IMOS_TYPE_MONITOR = 14,                /**< 监视器 */

    IMOS_TYPE_EC = 15,                     /**< EC */
    IMOS_TYPE_DC = 16,                     /**< DC */

    IMOS_TYPE_GENERAL = 17,                /**< 通用设备 */
    IMOS_TYPE_ECR = 18,                    /**< ECR */

    IMOS_TYPE_TS = 19,                     /**< TS */
    IMOS_TYPE_LS = 20,                      /**<LS 日志审计服务器*/
    IMOS_TYPE_VOD = 21,                  /**<VOD*/
    IMOS_TYPE_TMS = 30,                    /**< 交通媒体交换服务器 */
    IMOS_TYPE_TOLLGATE = 31,               /**< 卡口 */
    IMOS_TYPE_DR = 32,                     /**< 数据搜索服务器 */
    IMOS_TYPE_MAPM = 33,                   /**< 地图服务器 */
    IMOS_TYPE_IAHR = 34,                   /**< 智能人脸卡口服务器 */

    /* Begin: Added by zhongke, 2015-03-01 for CDS云存储 */
    IMOS_TYPE_CDS = 35,                    /**< CDS系统 */
    /* End: Added by zhongke, 2015-03-01 for CDS云存储 */

    /* Begin: Added by luchunfeng02289, 2016-04-07 for 物联网设备接入 */
	IMOS_TYPE_IOT = 36,                    /**< 物联网设备 */
	/* End: Added by luchunfeng02289, 2016-04-07 for 物联网设备接入 */

    /* Begin Added by shendongchun 00400 2014-02-26 for 大数据服务器增加 */
    IMOS_TYPE_DB8500 = 40,                 /**< 数据存储服务器 - DB8500 */
    IMOS_TYPE_DB9500 = 41,                 /**< 数据存储服务器 - DB9500 */
    /* End Added by shendongchun 00400 2014-02-26 for 大数据服务器增加 */

    IMOS_TYPE_MCU = 201,                   /**< MCU */
    IMOS_TYPE_MG = 202,                    /**< MG */

    IMOS_TYPE_CAMERA = 1001,               /**< 摄像机 */
    IMOS_TYPE_TOLLGATE_CAMERA = 1002,      /**< 卡口相机 */
    IMOS_TYPE_ALARM_SOURCE = 1003,         /**< 告警源 */

    IMOS_TYPE_STORAGE_DEV = 1004,          /**< 存储设备 */
    IMOS_TYPE_TRANS_CHANNEL = 1005,        /**< 透明通道 */
    /* Begin: added by yW1054 in 2014-11-24 for 图侦客户端统计 */
    IMOS_TYPE_ICSCI = 1006,		  /**< 图侦客户端 */
    /* End: added by yW1054 in 2014-11-24 for  图侦客户端统计*/

    IMOS_TYPE_ALARM_OUTPUT = 1200,         /**< 告警输出 */

    IMOS_TYPE_BM = 1300,                   /**< BM */

    IMOS_TYPE_SEMAPHORE_OUTPUT = 1400,    /**<开关量输出 */
    /*Begin: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/
    IMOS_TYPE_CDM = 1500,                   /**< CDM */
    IMOS_TYPE_CDV = 1501,                   /**< CDV */
    /*End: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/

	/* Begin Added by y01359 2014-09-26 for A8 */
	IMOS_TYPE_A8 = 1502,                   /**< A8设备 */
    /* End Added by y01359 2014-09-26 for A8 */

    /* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE接入平台 */
    IMOS_TYPE_XWARE = 1503,                /**< XWARE设备 */
    /* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388，XWARE接入平台 */

    IMOS_TYPE_FLASHLIGHT       = 1999,     /**< 闪光灯 */
    IMOS_TYPE_DEVICE_MAX_VALUE = 2000,     /**< 设备资源类型最大值 */

    IMOS_TYPE_GUARD_TOUR_RESOURCE = 2001,  /**< 轮切资源 */
    IMOS_TYPE_GUARD_TOUR_PLAN = 2002,      /**< 轮切计划 */
    IMOS_TYPE_MAP = 2003,                  /**< 地图 */

    IMOS_TYPE_XP = 2005,                   /**< XP */
    IMOS_TYPE_XP_WIN = 2006,               /**< XP窗格 */
    IMOS_TYPE_GUARD_PLAN = 2007,           /**< 布防计划 */

    IMOS_TYPE_DEV_ALL = 2008,              /**< 所有的设备类型(EC/DC/MS/DM/VX500/摄像头/监视器) */

	IMOS_TYPE_GUARD_POSITION_PLAN = 2009,	   /**< 看守计划 */

    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */
    IMOS_TYPE_WIRELESS_INSPECTION      = 2200,       /**< 无线检测 */
    IMOS_TYPE_SENSOR                   = 2201,       /**< 传感器 */
    IMOS_TYPE_MOVING_RING_EQUIPMENT    = 2202,       /**< 动力设备 */
    IMOS_TYPE_COMMUNICATION_EQUIPMENT  = 2203,       /**< 通信设备 */
    IMOS_TYPE_OTHER_IOT_EQUIPMENT      = 2250,       /**< 其它设备类型 */
    IMOS_TYPE_IOT_RES_MAX_VALUE        = 2251,       /**< 物联网资源类型最大值 */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */

	/* Begin Added by y01359 2014-09-26 for A8 */
	IMOS_TYPE_WINDOW_A8 = 2999,            /**< A8窗口 */
	IMOS_TYPE_TV_WALL_A8 = 3000,           /**< A8电视墙 */
    /* End Added by y01359 2014-09-26 for A8 */

    IMOS_TYPE_TV_WALL = 3001,              /**< 电视墙 */

    IMOS_TYPE_CAMERA_GROUP = 3002,                   /**< 摄像机组 */
    IMOS_TYPE_MONITOR_GROUP = 3003,                  /**< 监视器组 */
    IMOS_TYPE_SALVO_RESOURCE = 3004,                 /**< 组显示资源 */
    IMOS_TYPE_BROADCAST_GROUP = 3005,                /**< 广播组 */
    IMOS_TYPE_IMAGE_MOSAIC = 3006,                   /**< 图像拼接资源 */
    IMOS_TYPE_BALLLINKAGE_GROUP = 3007,              /**< 枪球联动组资源 */
    IMOS_TYPE_GROUP_SWITCH_RESOURCE = 3010,          /**< 组轮巡资源 */
    IMOS_TYPE_GROUP_SWITCH_PLAN = 3011,              /**< 组轮巡计划资源 */
    /* Begin Added by dengshuhua00673, 2012-12-14 of 自动布局轮巡 */
    IMOS_TYPE_AUTO_SWITCH_RESOURCE = 3012,           /**< 自动布局轮巡资源 */
    IMOS_TYPE_GROUP_SWITCH_RESOURCE_BOTH = 3013,     /**< 两种(自动、组显示)轮巡资源 */
    /* End Added by dengshuhua00673, 2012-12-14 of 自动布局轮巡 */

    IMOS_TYPE_SCENE             = 3015,              /**< 场景资源(参见DAO宏定义#DAO_RES_AGG_TYPE_SCENE,如有改动，必须同步) */

    IMOS_TYPE_ACTION_PLAN = 3016,          /**< 预案资源 */

    /* Begin Added by liucanming/03903, 2017-09-05 of MPPD54245 A8组轮巡 自动布局轮巡 */
    IMOS_TYPE_AUTO_POLL_RESOURCE = 3021,            /**A8自动布局轮巡资源 */
    IMOS_TYPE_WINDOW_POLL_RESOURCE = 3022,          /**A8 窗口组轮巡资源 */
    /* End Added by liucanming/03903, 2017-09-05 of MPPD54245 A8组轮巡 自动布局轮巡 */

    IMOS_TYPE_TRUNK = 3050,                /**< 干线 */

    IMOS_TYPE_CONFERENCE = 4001,           /**< 会议资源 */

    IMOS_TYPE_USER       = 5001,          /**< 用户资源 */

    /* Begin Added by zhudingjingKF0104, 2013-06-19 of 语音资源化 */
    IMOS_TYPE_MICROPHONE = 8001,           /**< 语音对讲资源 */
    IMOS_TYPE_SPEAKER    = 8002,           /**< 语音广播资源 */

    IMOS_TYPE_AUDIO_INPUT = 8003,          /**< 独立音频输入 */
    IMOS_TYPE_AUDIO_OUTPUT = 8004,         /**< 独立音频输出 */
    /* End Added by zhudingjingKF0104, 2013-06-19 of 语音资源化 */

    /* Begin Added by luchunfeng02289, 2015-09-28 for ADU全景拼接*/
    IMOS_TYPE_IMAGE_MOSAIC_V2 = 9000,      /**< ADU图像拼接资源 */
    /* End Added by luchunfeng02289, 2015-09-28 for ADU全景拼接*/

    /* Begin added by zhukaikai/W4801, 2017-12-28 for 地标器特性 MPPD54420 */
    IMOS_TYPE_LANDMARKS = 9026,       /**< 地标器/RFID触发器(可视化客户端称之为RFID) */
    /* End added by zhukaikai/W4801, 2017-12-28 for 地标器特性 MPPD54420 */

    IMOS_TYPE_MAX,
    IMOS_TYPE_INVALID = 0xFFFFFFFF
}IMOS_TYPE_E;

/**
 * @enum tagAlarmSrcType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagAlarmDevType
{
    ALARM_DEV_TYPE_EC  = 0,            /**< 告警设备为EC */
    ALARM_DEV_TYPE_DC  = 1,            /**< 告警设备为DC */
    ALARM_DEV_TYPE_IPSAN  = 2,            /**< 告警设备为存储设备 */
    ALARM_DEV_TYPE_CAM  = 3,            /**< 告警设备为摄像机 */
    ALARM_DEV_TYPE_BOOLEAN  = 4,            /**< 告警设备为开关量 */
    ALARM_DEV_TYPE_SERIAL   = 5,            /**< 告警设备为串口 */
    ALARM_DEV_TYPE_GENERAL  = 6,            /**< 告警设备为通用设备 */

    ALARM_DEV_TYPE_MAX,                     /**< 告警设备枚举最大值 */
    ALARM_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}ALARM_DEV_TYPE_E;

/**
 * @enum tagDMType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagDMDevType
{
    DM_DEV_TYPE_3  = 0,            /**< DM3.0 */
    DM_DEV_TYPE_5  = 2,            /**< DM5.0 */
    DM_DEV_TYPE_CDV  = 3,            /**< CDV */
    DM_DEV_TYPE_MAX,                     /**< DM设备枚举最大值 */
    DM_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}DM_DEV_TYPE_E;

/**
 * @enum tagVODType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagVODDevType
{
    VOD_DEV_TYPE_5  = 0,            /**< VOD 5.0*/
    VOD_DEV_TYPE_MAX,                     /**< VOD设备枚举最大值 */
    VOD_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}VOD_DEV_TYPE_E;


/**
 * @enum tagMSType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagMSDevType
{
    MS_DEV_TYPE_3  = 0,            /**< MS3.0 */
    MS_DEV_TYPE_5  = 2,            /**< MS5.0 */
    MS_DEV_TYPE_MAX,                     /**< MS设备枚举最大值 */
    MS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}MS_DEV_TYPE_E;

/**
 * @enum tagTMSType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagTMSDevType
{
    TMS_DEV_TYPE_3  = 0,            /**< TMS3.0 */
    TMS_DEV_TYPE_5  = 2,            /**< TMS5.0 */
    TMS_DEV_TYPE_5516  = 3,            /**< TMS5516 */
    TMS_DEV_TYPE_MAX,                     /**< MS设备枚举最大值 */
    TMS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}TMS_DEV_TYPE_E;

/**
 * @enum tagTSType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagTSDevType
{
    TS_DEV_TYPE_3  = 0,            /**< TS3.0 */
    TS_DEV_TYPE_5  = 2,            /**< TS5.0 */
    TS_DEV_TYPE_MAX,                     /**< TS设备枚举最大值 */
    TS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}TS_DEV_TYPE_E;

/**
 * @enum tagLSType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagLSDevType
{
    LS_DEV_TYPE_LOG8500  = 0,            /**< LS LOG8500 */
    LS_DEV_TYPE_LOG9500  = 1,            /**< LS LOG9500 */
    LS_DEV_TYPE_MAX,                     /**< LS设备枚举最大值 */
    LS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}LS_DEV_TYPE_E;

/* Begin added by hw3668 for MAPM9500*/
/**
 * @enum tagMAPMType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagMAPMDevType
{
    MAP_DEV_TYPE_MAPM8500  = 0,           /**< MAPM8500 */
    MAP_DEV_TYPE_MAPM9500  = 1,           /**< MAPM9500 */
    MAP_DEV_TYPE_MAX,                     /**< MAPM设备枚举最大值 */
    MAP_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}MAPM_DEV_TYPE_E;
/* End added by hw3668 for MAPM9500*/

/* Begin: Added by zhongke, 2015-03-02 for CDS云存储 */
/**
 * @enum tagCDSDevType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagCDSDevType
{
    CDS_DEV_TYPE_9500  = 0,              /**< CDS9500 */
    CDS_DEV_TYPE_MAX,                     /**< DM设备枚举最大值 */
    CDS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */
}CDS_DEV_TYPE_E;
/* End: Added by zhongke, 2015-03-02 for CDS云存储 */


/**
* @enum tagNameCodeFlag
* @brief 名称标记:0 名称无效 1 按查询设备名称 2 按查询资源名称
* @attention
*/
typedef enum tagNameCodeFlag
{
    NAME_FLAG_NULL    = 0,                /**< 名称无效 */
    NAME_FLAG_DEV     = 1,                /**< 按查询设备名称 */
    NAME_FLAG_RES     = 2,                /**< 按查询资源名称 */
    NAME_FLAG_RESCODE = 3,                /**< 按查询资源编码 */

    NAME_FLAG_MAX,                      /**< 名称标记枚举最大值 */
    NAME_FLAG_INVALID   = 0xFFFFFFFF    /**< 无效值 */

}NAME_CODE_FLAG_E;

/**
* @enum tagSearchMode
* @brief 搜寻模式标记:0 名称无效 1 精确匹配 2 模糊匹配
* @attention
*/
typedef enum tagSearchMode
{
    SEARCH_MODE_NULL    = 0,                /**< 无效 */
    SEARCH_MODE_EQU     = 1,                /**< 精确匹配*/
    SEARCH_MODE_LIKE    = 2,                /**< 模糊匹配 */

    SEARCH_MODE_MAX,                        /**< 最大值 */
    SEARCH_MODE_INVALID   = 0xFFFFFFFF      /**< 无效值 */

}SEARCH_MODE_E;

/**
* @enum tagTimeFlag
* @brief 时间标记:0 时间无效 1 按时间点查询 2 按时间段查询
* @attention
*/
typedef enum tagTimeFlag
{
    TIME_FLAG_NULL  = 0,                /**< 时间无效 */
    TIME_FLAG_ONE   = 1,                /**< 按时间点查询 */
    TIME_FLAG_TWO   = 2,                /**< 按时间段查询 */

    TIME_FLAG_MAX,                      /**< 时间标记枚举最大值 */
    TIME_FLAG_INVALID   = 0xFFFFFFFF    /**< 无效值 */
}TIME_FLAG_E;

/**
* @enum tagStoreAssignType
* @brief 存储分配策略类型
* @attention
*/
typedef enum tagStoreAssignType
{
    ASSIGN_TYPE_SIZE         = 0,       /**< 直接分配存储容量，进行存储 */
    ASSIGN_TYPE_DAY          = 1,       /**< 按天存储，通过天和码流计算需要分配的容量 */

    ASSIGN_TYPE_MAX,                    /**< 存储分配策略枚举最大值 */
    ASSIGN_TYPE_INVALID = 0xFFFFFFFF    /**< 无效值 */

}STORE_ASSIGN_TYPE_E;

/**
* @enum tagStoreDevType
* @brief 存储设备类型枚举
* @attention
*/
typedef enum tagStoreDevType
{
    STORE_DEV_TYPE_IPSAN    = 0,            /**< IPSAN设备 */
    STORE_DEV_TYPE_VX500    = 1,            /**< VX500辅机 */
    STORE_DEV_TYPE_ECR      = 2,            /**< ECR设备 */

    /* Begin: Added by zhongke, 2015-03-02 for CDS云存储 */
    STORE_DEV_TYPE_CDS      = 3,           /**< 云存储设备 */
    /* End: Added by zhongke, 2015-03-02 for CDS云存储 */

    STORE_DEV_TYPE_MAX,                     /**< 存储设备类型枚举最大值 */
    STORE_DEV_TYPE_INVALID  = 0xFFFFFFFF    /**< 无效值 */
}STORE_DEV_TYPE_E;

/**
* @enum tagIpsanStoreDevType
* @brief IPSAN存储设备子类型枚举
* @attention
*/
typedef enum tagIpsanStoreDevSubType
{
    STORE_DEV_SUB_TYPE_VX1500      = 0,            /**< VX1500 */
    STORE_DEV_SUB_TYPE_VX1500_E    = 1,            /**< VX1500-E */
    STORE_DEV_SUB_TYPE_VX1600      = 2,            /**< VX1600 */

    STORE_DEV_SUB_TYPE_MAX,                        /**< IPSAN存储设备子类型枚举最大值 */
    STORE_DEV_SUB_TYPE_INVALID  = 0xFFFFFFFF       /**< 无效值 */
}IPSAN_STORE_DEV_SUB_TYPE_E;

/**
* @enum tagStoreConfigType
* @brief 存储配置类型枚举
* @attention
* 1.本枚举与dao_as_def.h中的#DAO_STORE_CONFIG_TYPE_E严格对应，如有修改，必现同步进行
*/
typedef enum tagStoreConfigType
{
    STORE_CONFIG_TYPE_STOR         = 0,            /**< 直存配置 */
    STORE_CONFIG_TYPE_STREAM_STOR  = 1,            /**< 流转存配置 */

    STORE_CONFIG_TYPE_MAX,                        /**< 存储配置类型枚举最大值 */
    STORE_CONFIG_TYPE_INVALID     = 0xFFFFFFFF    /**< 无效值 */
}STORE_CONFIG_TYPE_E;

/** 通道类型 */
typedef enum tagIMOSChannelType
{
    IMOS_CHANNEL_TYPE_BOOLEAN   = 0,    /**< 开关量 */
    IMOS_CHANNEL_TYPE_SERIAL    = 1,    /**< 串口 */

    IMOS_CHANNEL_TYPE_MAX,
    IMOS_CHANNEL_TYPE_INVALID = 0xFFFFFFFF
}IMOS_CHANNEL_TYPE_E;

/** 语音广播状态*/
typedef enum tagVocBrdStatus
{
    VOCBRD_STATUS_ON    = 0,    /**< 正在广播*/
    VOCBRD_STATUS_OFF   = 1,    /**< 没有广播*/

    VOCBRD_STATUS_MAX,
    VOCBRD_STATUS_INVALID = 0xFFFFFFFF
}VOCBRD_STATUS_E;

/** 透明通道使能状态枚举 */
typedef enum tagTlTransChannelStatus
{
    TL_TRANS_CHANNEL_DISABLED   = 0,    /**< 不使能 */
    TL_TRANS_CHANNEL_ENABLED    = 1,    /**< 使能 */

    TL_TRANS_CHANNEL_STATUS_MAX,                     /**< 最大值 */
    TL_TRANS_CHANNEL_STATUS_INVALID = 0xFFFFFFFF     /**< 无效值 */
}TL_TRANS_CHANNEL_STATUS_E;

/** 透明通道当前工作状态枚举 */
typedef enum tagTlTransChannelWorkStatus
{
    TL_TRANS_CHANNEL_CLOSED = 0,                        /**< 关闭 */
    TL_TRANS_CHANNEL_OPENED = 1,                        /**< 打开 */

    TL_TRANS_CHANNEL_WORK_STATUS_MAX,                   /**< 最大值 */
    TL_TRANS_CHANNEL_WORK_STATUS_INVALID = 0xFFFFFFFF   /**< 无效值 */
}TL_TRANS_CHANNEL_WORK_STATUS_E;

/**
* @enum tagManufacturerType
* @brief 域厂商类型枚举
* @attention
*/
typedef enum tagManufacturerType
{
    MANUFACTURER_TYPE_H3C      = 0,             /**< H3C_8500 */
    MANUFACTURER_TYPE_H3C_3000E,                /**< H3C_3000E */
    MANUFACTURER_TYPE_DB33,                     /**< 非H3C，但是用DB33标准接入的厂商 */
    MANUFACTURER_TYPE_OTHER,                    /**< 以上都不属于的厂商 */

    MANUFACTURER_TYPE_MAX,
    MANUFACTURER_TYPE_INVALID = 0xFFFFFFFF
}MANUFACTURER_TYPE_E;

/**
* @enum tagCameraType
* @brief 摄像机类型枚举
* @attention
*/
typedef enum tagCameraType
{
    CAMERA_TYPE_FIX         = 1,            /**< 标清固定摄像机 */
    CAMERA_TYPE_PTZ         = 2,            /**< 标清云台摄像机 */
    CAMERA_HD_TYPE_FIX      = 3,            /**< 高清固定摄像机 */
    CAMERA_HD_TYPE_PTZ      = 4,            /**< 高清云台摄像机 */
    CAMERA_TYPE_CAR         = 5,            /**< 车载摄像机 */
    CAMERA_TYPE_VIRTUAL     = 6,            /**< 虚拟摄像机 */
    CAMERA_TYPE_BALL_NOT_CONTROL            = 7,            /**< 不可控标清球机 */
    CAMERA_HD_TYPE_BALL_NOT_CONTROL         = 8,            /**< 不可控高清球机 */

    /* BEGIN: Added by kf0092 for 安全接入外域, 2013年3月22日 */
    CAMERA_TYPE_SAFE_VM     = 9,            /**< VM安全接入摄像机 */
    CAMERA_TYPE_SAFE_DVR    = 10,           /**< DVR安全接入摄像机 */
    CAMERA_TYPE_SAFE_MATRIX = 11,           /**< 矩阵安全接入摄像机 */
    /* END  : Added by kf0092 for 安全接入外域, 2013年3月22日 */
	CAMERA_TYPE_FIX_BOX= 12,                /**变焦枪机 */

	/* Begin added by y01359, 2014-12-11 for A8 */
	CAMERA_TYPE_VGA = 13,                   /**< VGA输入摄像机 */
	CAMERA_TYPE_DVI = 14,                   /**< DVI输入摄像机 */
	/* End added by y01359, 2014-12-11 for A8 */

    /* Begin added by zW4385, 2017-12-21 for MPPD54252 鱼眼相机 */
    CAMERA_TYPE_FE         = 15,            /**< 鱼眼摄像机(经济款) */
    CAMERA_HD_TYPE_FE      = 16,            /**< 高清鱼眼摄像机(4K预留) */
    /* End added by zW4385, 2017-12-21 for MPPD54252 鱼眼相机 */

    CAMERA_TYPE_MAX,                        /**< 摄像机类型枚举最大值 */
    CAMERA_TYPE_INVALID     = 0xFFFFFFFF    /**< 无效值 */
}CAMERA_TYPE_E;

/**
* @enum tagTargetType
* @brief 监控目标类型枚举
* @attention
*/
typedef enum tagTargetType
{
    TARGET_TYPE_ORGAN           = 1,                /**< 党政机关 */
    TARGET_TYPE_PLAZA           = 2,                /**< 公共活动广场 */
    TARGET_TYPE_TVB             = 3,                /**< 电台电视台 */
    TARGET_TYPE_FINANCE         = 4,                /**< 金融机构网点 */
    TARGET_TYPE_CULTURE         = 5,                /**< 学校文博科研院所 */
    TARGET_TYPE_LIFESUPPLY      = 6,                /**< 水电油气供应站 */
    TARGET_TYPE_MEDICAL         = 7,                /**< 医疗机构 */
    TARGET_TYPE_STATION         = 8,                /**< 车站码头 */
    TARGET_TYPE_LANDSCAPE       = 9,                /**< 旅游景区 */
    TARGET_TYPE_TRAFFIC         = 10,               /**< 交通道路 */
    TARGET_TYPE_CONSUMPTION     = 11,               /**< 商城酒店娱乐场所 */
    TARGET_TYPE_TOLLGATE        = 12,               /**< 卡口 */
    TARGET_TYPE_OTHER           = 99,               /**< 其他 */


    TARGET_TYPE_INVALID         = 0xFFFFFFFF        /**< 无效值 */
} TARGET_TYPE_E;


/**
* @enum tagTargetType
* @brief 监控目标子属性枚举
* @attention
*/
typedef enum tagTargetSubType
{
    TARGET_SUBTYPE_RESERVE                         = 0,                /**< 默认保留 */
    TARGET_SUBTYPE_PUBIC_SECURITY_CONSTRUCTION     = 1,                /**< 公安自建 */
    TARGET_SUBTYPE_TELECOM_OPERATOR_LEASE          = 2,                /**< 运营商租赁 */
    TARGET_SUBTYPE_COMPANY_CONSTRUCTION            = 3,                /**< 单位自建 */

    TARGET_SUBTYPE_INVALID         = 0xFFFFFFFF        /**< 无效值 */
} TARGET_SUBTYPE_E;

/**
* @enum tagCameraAttribute
* @brief 摄像机属性枚举
* @attention
*/
typedef enum tagCameraAttribute
{
    CAMERA_ATTRIBUTE_LOCAL      = 0,            /**< 本域内普通编码器的摄像机 */
    CAMERA_ATTRIBUTE_EC         = 1,            /**< 外域的摄像机 */
    CAMERA_ATTRIBUTE_ECRHF_NVR  = 2,            /**< 本域内ECR HF系列摄像机 */
    CAMERA_ATTRIBUTE_ECPAG      = 3,            /**< 第三方IPC */
    /* Begin added by y01359, 2015-03-11 for A8 */
    CAMERA_ATTRIBUTE_DISABLE    = 4,            /**< 不可用摄像机 */
    /* End added by y01359, 2015-03-11 for A8 */
    CAMERA_ATTRIBUTE_MAX,                       /**< 枚举最大值 */
    CAMERA_ATTRIBUTE_INVALID    = 0xFFFFFFFF    /**< 无效值 */
}CAMERA_ATTRIBUTE_E;

/**
* @enum tagLicenseType
* @brief License规格类型
* @attention 无
*/
typedef enum tagLicenseType
{
    LICENSE_TYPE_BASE_FUNCTION_FOR_LINUX = 0x00,    /**< 监控管理基本功能授权For Linux */

    LICENSE_TYPE_MCU_LO_DOMAIN = 0x0A,              /**< 本域MCU规格类型 */
    LICENSE_TYPE_CAMERA_LO_DOMAIN = 0x10,           /**< 本域CAMERA规格类型 */
    LICENSE_TYPE_CAMERA_EX_H3C_DOMAIN = 0x11,       /**< H3C外域CAMERA规格类型 */
    LICENSE_TYPE_CAMERA_EX_NOT_H3C_DOMAIN = 0x12,   /**< 非H3C外域CAMERA规格类型 */

    LICENSE_TYPE_STORAGE = 0x30,                    /**< 存储规格类型 */
    /*Begin added by luokunzhong 2015-11-25, for tms5516 license 校验*/
    LICENSE_TYPE_TMS_5516 = 0x3C,                        /**< TMS5516规格类型 */
    /*End added by luokunzhong 2015-11-25, for tms5516 license 校验*/

    LICENSE_TYPE_DM = 0x35,                         /**< DM规格类型 */
    LICENSE_TYPE_MS = 0x36,                         /**< MS规格类型 */
    /* 0x37已用于DA,请勿使用 */
    LICENSE_TYPE_SDC = 0x38,                        /**< SDC规格类型 */
    LICENSE_TYPE_TMS = 0x39,                        /**< TMS规格类型 */
    LICENSE_TYPE_TOLLGATE_CAMERA_LO_DOMAIN = 0x3A,  /**< 本域抓拍相机规格类型 */
    /*Begin added by liangchao, 2015-11-25 for BM2516合主线*/
    LICENSE_TYPE_BM_3_5 = 0x3B,      /**< 备份一体机BM3.5(BM2516-DA/BM8516/BM8500-E)规格类型 */
    /*End added by liangchao, 2015-11-25 for BM2516合主线*/

    /* Begin: Add by lW2822, 2016-09-29 for 平台接入BM9500 */
    LICENSE_TYPE_BM_5 = 0x7C,        /**< 备份一体机BM5.0(BM9500)规格类型 */
    /* End: Add by lW2822, 2016-09-29 for 平台接入BM9500 */
    LICENSE_TYPE_TS = 0x42,                         /**< TS规格类型 */
    LICENSE_TYPE_GASRV_ICSCI = 0x43,                /**< 公安实战图侦客户端接入规格类型 */
    LICENSE_TYPE_GASRV_CAMERA = 0x44,               /**< 公安实战的CAMERA规格类型 */

    LICENSE_TYPE_CAMERA_THIRD_PARTY = 0x45,      /**< 第三方CAMERA规格类型 */
    LICENSE_TYPE_GASRV_ICC = 0x48,                  /**< 公安实战违章抓拍客户端接入规格类型 */
    LICENSE_TYPE_DB8500E   = 0x54,                         /**< DB集群服务器接入规格类型 */
    LICENSE_TYPE_DR8500 = 0x55,                       /**< DR8500集群服务器接入规格类型 */
    LICENSE_TYPE_DB   = 0x56,                         /**< DB集群服务器接入规格类型 */
    LICENSE_TYPE_DR9500 = 0x57,                       /**< DR9500集群服务器接入规格类型 */

	/*Begin added by l02274 2015-6-23, for map license 校验*/
    LICENSE_TYPE_MAPM = 0x58,                         /**< MAPM地图服务器接入规格类型 */
    /*End added by l02274 2015-6-23, for map license 校验*/

    LICENSE_TYPE_THIRD_STOR = 0x6C,                  /**< 第三方存储规格类型 */

	/*Begin added by hw3668 2017-4-10, for map5.0 license 校验*/
    LICENSE_TYPE_MAPM_5 = 0x7F,                      /**< MAPM5.0地图服务器接入规格类型 */
    /*End added by hw3668 2017-4-10, for map5.0 license 校验*/

    LICENSE_TYPE_IAHR = 0x53,                       /**< IAHR规格类型 */

    /* V3R5 license授权 */
    LICENSE_TYPE_BASE_FUNCTION_FOR_VM5 = 0x67,    /**< 监控管理基本功能授权For VM5.0 */
    LICENSE_TYPE_DM_5 = 0x68,                         /**< DM5.0规格类型 */
    LICENSE_TYPE_MS_5 = 0x69,                         /**< MS5.0规格类型 */
    LICENSE_TYPE_TMS_5 = 0x6A,                        /**< TMS5.0规格类型 */
    LICENSE_TYPE_TS_5 = 0x6B,                         /**< TS5.0规格类型 */
    LICENSE_TYPE_LS_LOG8500 = 0x6D,                 /**< LOG8500日志审计服务器类型*/
    LICENSE_TYPE_LS_LOG9500 = 0x6E,                 /**< LOG9500日志审计服务器类型*/

    /*Begin: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/
    LICENSE_TYPE_CDM = 0x6F,                         /**< CDM规格类型 */
    LICENSE_TYPE_CDV = 0x70,                         /**< CDV规格类型 */
    LICENSE_TYPE_VOD = 0x71,                         /**< VOD规格类型 */
    /*End: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/

    /* Begin: Added by zhongke, 2015-03-02 for CDS云存储 */
    LICENSE_TYPE_CDS = 0x72,                         /**< CDM规格类型 */
    /* End: Added by zhongke, 2015-03-02 for CDS云存储 */
    LICENSE_TYPE_MCD = 0x78,                         /**< 移动指挥业务类型--移动指挥登录客户端 */
    LICENSE_TYPE_MLE = 0x79,                         /**< 移动执法业务类型--移动执法登录客户端 */
    LICENSE_TYPE_MVC = 0x7A,                         /**< 移动采集业务类型--移动前端设备 */

    /* Begin: Added by yangfeng/yW3815, 2017-12-08 for MPPD54031 VM B3326H200版本需要新增DB9500E-S的license */
    LICENSE_TYPE_DB9500ES = 0x82,                    /**< DB9500E-S服务器规格类型 */

    /* 组件授权 */
    LICENSE_TYPE_CONFERENCE_BASE = 0x97,            /**< 视讯组件授权 */

    LICENSE_TYPE_MAX,                               /**< 规格类型最大值 */
    LICENSE_TYPE_INVALID        = 0xFF
}LICENSE_TYPE_E;

/* Begin: Added by MultiDomain */
/**
* @enum tagInterDomainProtocolType
* @brief 域间通讯协议类型枚举
* @attention
*/
typedef enum tagInterDomainProtocolType
{
    INTER_DOMAIN_PROTOCOL_DB33      = 0,    /**< DB33 */
    INTER_DOMAIN_PROTOCOL_GLOBALEYE = 1,    /**< 全球眼 */
    INTER_DOMAIN_PROTOCOL_WIDEEYE   = 2,    /**< 宽视界 */
    INTER_DOMAIN_PROTOCOL_ELECTRIC  = 3,    /**< 四川电力 */
    INTER_DOMAIN_PROTOCOL_IMOS      = 4,    /**< IMOS */
    INTER_DOMAIN_PROTOCOL_DB33NEW   = 5,    /**< DB33 2010 */
    INTER_DOMAIN_PROTOCOL_GDA       = 6,    /**< 国电A标准 */
    INTER_DOMAIN_PROTOCOL_GDB       = 7,    /**< 国电B标准 */
    INTER_DOMAIN_PROTOCOL_IMOSV2    = 8,    /**< IMOS V2 */
    INTER_DOMAIN_PROTOCOL_GB        = 9,    /**< 国标 */
    INTER_DOMAIN_PROTOCOL_DB33_2012 = 10,   /**< DB33 2012 */

    INTER_DOMAIN_PROTOCOL_SAFE      = 1001, /**< 安全接入外域 */

    INTER_DOMAIN_PROTOCOL_MAX,                    /**< 枚举最大值 */
    INTER_DOMAIN_PROTOCOL_INVALID = 0xFFFFFFFF    /**< 无效值 */
}INTERDOMAIN_PROTOCOL_TYPE_E;
/* End: Added by MultiDomain */


/**
* @enum tagSwitchCircuitAlarmEnabledType
* @brief 开关量线路检测告警类型
* @attention 无
*/
typedef enum tagSwitchCircuitAlarmEnabledType
{
    SWITCH_CIRCUIT_ALARM_ENABLED        = 1,    /**< 支持开关量线路检测告警(既支持开关量线路短路告警也支持开关量线路断路告警) */
    SWITCH_CIRCUIT_ALARM_DISABLED       = 2,    /**< 不支持开关量线路检测告警(既不支持开关量线路短路告警也不支持开关量线路断路告警) */
    SWITCH_CIRCUIT_SHORT_ENABLED_ONLY   = 3,    /**< 支持开关量线路短路告警而不支持开关量线路断路告警 */
    SWITCH_CIRCUIT_BREAK_ENABLED_ONLY   = 4,    /**< 支持开关量线路断路告警而不支持开关量线路短路告警 */

    SWITCH_CIRCUIT_ALARM_MAX,
    SWITCH_CIRCUIT_ALARM_INVALID = 0xFF
}SWITCH_CIRCUIT_ALARM_ENABLED_TYPE_E;

/**
* @enum tagBackupStatus
* @brief 备份状态枚举
* @attention
*/
typedef enum tagBackupStatus
{
    BACKUP_STATUS_START         = 0,    /**< 开始启动备份 */
    BACKUP_STATUS_PROCESSING    = 1,    /**< 备份进行中 */
    BACKUP_STATUS_IDLE          = 2,    /**< 非备份状态 */

    BACKUP_STATUS_MAX,                    /**< 备份状态枚举最大值 */
    BACKUP_STATUS_INVALID    = 0xFFFFFFFF /**< 无效值 */
}BACKUP_STATUS_E;

/**
 * @enum tagLogicFlag
 * @brief  复杂查询条件约束中的逻辑关系定义
 * @attention 无
 */
typedef enum tagLogicFlag
{
    EQUAL_FLAG      = 0,    /**< 等于 */
    GREAT_FLAG      = 1,    /**< 大于 */
    LITTLE_FLAG     = 2,    /**< 小于 */
    GEQUAL_FLAG     = 3,    /**< 大于等于 */
    LEQUAL_FLAG     = 4,    /**< 小于等于 */
    LIKE_FLAG       = 5,    /**< 模糊查询 */
    ASCEND_FLAG     = 6,    /**< 升序 */
    DESCEND_FLAG    = 7,    /**< 降序 */
    NEQUAL_FLAG     = 8,    /**< 不等于 */
    NLIKE_FLAG      = 13,   /**< NOT LIKE */
	IN_SELECT_FLAG  = 14,   /**< IN SELECT语句 */
    IN_FLAG         = 99,   /**<   */
    LOGIC_FLAG_MAX          /**< 无效值 */
}LOGIC_FLAG_E;


/**
 * @enum tagQueryType
 * @brief  查询项类型
 * @attention 300~500 视讯使用
 */
typedef enum tagQueryType
{
    CODE_TYPE       = 0,    /**< 编码类型(除用户编码之外) */
    NAME_TYPE       = 1,    /**< 名称类型(除用户名称之外) */
    USER_CODE_TYPE  = 2,    /**< 用户编码类型 */
    USER_NAME_TYPE  = 3,    /**< 用户名称类型 */
    TIME_TYPE       = 4,    /**< 时间类型 */

    EVENT_TYPE      = 5,    /**< 告警事件类型,取值为#AlARM_TYPE_E */
    EVENT_SECURITY  = 6,    /**< 告警事件级别,取值为#ALARM_SEVERITY_LEVEL_E */
    EVENT_STATUS_TYPE = 7,  /**< 告警状态,取值为#ALARM_STATUS_E */
    EVENT_TIME      = 8,    /**< 告警时间 */

    DEV_SUB_TYPE    = 9,    /**< 设备子类型 */

    INDEX_TYPE      = 10,   /**< 索引类型(如视频输入通道索引,视频输出通道索引,串口索引,开关量索引) */

    RES_SUB_TYPE    = 11,   /**< 资源子类型 */

    /* Begin: Add by x06948 for VVD38087, 20100115 */
    SRV_TYPE            = 12,       /**< 业务类型 */
    MONITOR_TYPE        = 13,       /**< 监视器类型 */
    MONITOR_NAME        = 14,       /**< 监视器名称 */
    MONITOR_DOMAIN      = 15,       /**< 监视器所在域 */
    CAMERA_NAME         = 16,       /**< 摄像机名称 */
    USER_LOGIN_IP       = 17,       /**< 用户登录IP */
    MON_SRV_STATUS      = 18,       /**< 实况状态 */
    VOCBRD_SRV_STATUS   = 19,       /**< 广播状态 */
    /* End: Add by x06948 for VVD38087, 20100115 */
    //RES_TYPE            = 20,       /**< 资源类型 */

    CASE_DESC               = 20,       /**< 案例描述 */
    TASK_STATUS             = 21,       /**< 任务状态 */
    TASK_SUB_TIME           = 22,       /**< 任务提交时间 */
    TASK_END_TIME           = 23,       /**< 任务结束时间 */
    BAK_START_TIME          = 24,       /**< 备份开始时间 */
    BAK_END_TIME            = 25,       /**< 备份结束时间 */
    FILE_CREATE_TIME        = 26,       /**< 文件创建时间 */
    FILE_CAPACITY           = 27,       /**< 文件容量 */
    FILE_TYPE               = 28,       /**< 文件类型 */
    FILE_LOCK_FLAG          = 29,       /**< 文件锁定标识 */
    LAYOUT_TYPE             = 30,       /**< 布局类型，取值为#LAYOUT_TYPE_E */

    PHY_DEV_IP              = 31,

    ASSET_TYPE              = 32,       /**< 资产类型，取值为#ASSET_TYPE_E */
    ASSET_MODEL             = 33,       /**< 资产型号 */
    ASSET_MANUFACTURE       = 34,       /**< 资产厂商 */
    ASSET_STATUS            = 35,       /**< 资产状态，取值为#ASSET_STATUS_E */
    ASSET_PURCHASE_TIME     = 36,       /**< 资产采购时间 */
    ASSET_WARRANT_TIME      = 37,       /**< 资产保修时间 */
    ASSET_INSTALL_TIME      = 38,       /**< 资产安装时间 */
    ASSET_INSTALL_LOCATION  = 39,       /**< 资产安装地点 */
    ASSET_PRODEALER         = 40,       /**< 资产工程商 */
    FAULT_STAT_TIME         = 41,       /**< 故障统计时间 */
    FAULT_TYPE              = 42,       /**< 故障类型 */
    FAULT_RECO_TIME         = 43,       /**< 故障恢复时间 */
    FAULT_INTERVAL          = 44,       /**< 故障时长 */
    FAULT_COUNT             = 45,       /**< 故障次数 */

    PLATE_CODE              = 46,       /**< 车牌号码 */
    STUFF_TYPE              = 47,       /**< 涉案物品类型 */
    STUFF_PROPERTY          = 48,       /**< 涉案物品性质 */
    SERIESCASE_TYPE         = 49,       /**< 串并案类型 */
    CASEINSE_CODE           = 50,       /**< 串并案中案件编号 */
    CASESHARE_TYPE          = 51,       /**< 案件共享类型 */
    CASE_PROPERTY           = 52,       /**< 案件性质 */
    CASE_TYPE               = 53,       /**< 案件类型 */
    CASE_STATUS             = 54,       /**< 案件状态 */
    POLICE_INTSRC           = 55,       /**< 案件警情来源 */
    CASE_BEGIN_TIME         = 56,       /**< 案件开始时间 */
    CASE_END_TIME           = 57,       /**< 案件结束时间 */
    STAT_START_TIME         = 58,       /**< 统计开始时间 */
    STAT_END_TIME           = 59,       /**< 统计结束时间 */
    EBULLETIN_EXPIRE_FLAG   = 60,       /**< 电子公告过期标志 */
    CASE_DATA_TYPE          = 61,       /**< 案件资料类型 */
    CASE_SOLVED_TIME        = 63,       /**< 案件破案时间 */
    CASE_CLOSED_TIME        = 64,       /**< 案件结案时间 */
    CASE_UPLOAD_TIME        = 65,       /**< 案件资料上传时间 */
    CASE_CREATE_TIME        = 66,       /**< 案件创建时间 */
    DEPT_CODE               = 67,       /**< 部门编码 */
    ACTION_TYPE             = 68,       /**< 动作类型,取值为#ACTION_TYPE_E */

    DOMAIN_TYPE = 100,       /**< 域类型,现只支持本外域 */

	/* Begin: Added by luchunfeng02289, 2015-12-08 for 告警分类 */
	EVENT_CLASS             = 101,      /**< 告警事件类型分类，取值为#ALARM_CLASS_E */
	/* End: Added by luchunfeng02289, 2015-12-08 for 告警分类 */

    EXT_DOMAIN_TPYE         = 200,      /**< 外域类型:上/下/平级域 */
    EXT_DOMAIN_IP           = 201,      /**< 外域IP */
    EXT_DOMAIN_PORT         = 202,      /**< 外域PORT */
    EXT_DOMAIN_TRUNK_NUM    = 203,      /**< 外域干线数量 */
    EXT_DOMAIN_MULTICAST    = 204,      /**< 域间组播策略 */
    EXT_DOMAIN_SESSION      = 205,      /**< 外域引流标志 */
    EXT_DOMAIN_SUBTYPE      = 206,      /**< 外域子类型 */

    JOB_STATUS          = 210,          /**< 升级任务状态 */
    JOB_CREATOR         = 211,          /**< 升级任务创建者 */
    JOB_EXEC_TIME       = 212,          /**< 升级任务调度时间 */
    JOB_ESTB_TIME       = 213,          /**< 升级任务制定时间 */
    JOB_END_TIME        = 214,          /**< 升级任务完成时间 */
    JOB_RESULT          = 215,          /**< 升级结果 */

    OPER_TIME               = 220,      /**< 操作时间 */
    OPER_IP                 = 221,      /**< 操作者IP地址 */
    OPER_TYPE               = 222,      /**< 操作类型 */
    OPER_RESULT             = 223,      /**< 操作结果 */
    OPER_SERVICE_TYPE       = 224,      /**< 操作的业务类型 */
    OPER_OBJ                = 225,      /**< 操作对象 */

    LABEL_TIME          = 230,          /**< 标签时间点 */
    REC_START_TIME      = 231,          /**< 标签录像开始时间，格式为"hh:mm:ss" */
    REC_END_TIME        = 232,          /**< 标签录像结束时间，格式为"hh:mm:ss" */

    USER_FULL_NAME          = 240,      /**< 用户全名 */
    USER_TEL_PHONE          = 241,      /**< 用户座机电话 */
    USER_MOBILE_PHONE       = 242,      /**< 用户移动电话 */
    USER_EMAIL              = 243,      /**< 用户电子邮件 */
    USER_IS_LOCKED          = 244,      /**< 用户是否被锁定 */

    USER_DESC               = 245,      /**< 用户描述 */

    ROLE_PRIORITY       =250,           /**< 角色优先级 */

    DEV_TYPE            = 255,          /**< 设备类型 */
    RES_TYPE            = 256,          /**< 资源类型 */
    IS_QUERY_SUB        = 257,          /**< 是否查下级(需要调AS_CON_Parse进行解析) */
    RES_ID              = 258,          /**< 资源ID */
    SUPPORT_LINK        = 259,          /**< 是否支持联动 */
    SUPPORT_GUARD       = 260,          /**< 是否支持布防 */
    RES_ATTRIBUTE       = 261,          /**< 资源属性 */
    IS_QUERY_ENCODESET  = 262,          /**< 是否查询摄像机或者监视器所在设备的流套餐，对应szQueryData为0-不查询，1-查询 */

    TYPE_ACTION_PLAN    = 263,          /**< 预案类型 */
    IS_PLAN_ALARM       = 264,          /**< 是否预案告警 */
    IS_ONCE_PLAN_ALARM  = 265,          /**< 是否启动过预案 */
    IS_MISINFORM        = 266,          /**< 是否误报 */
    CHK_USER_NAME_TYPE  = 267,          /**< 核警用户名 */
    TRIGGER_ID          = 268,          /**< 触发器ID */

    IS_HIDE_EMPTY_ORG   = 269,          /**< 是否隐藏空组织 */
    IS_QUERY_SHARED     = 270,          /**< 是查询已共享资源=1还是查未共享资源=0 */

    IS_LEACH_SHARED_BELONG  = 271,      /**< 是否过滤掉因为资源共享给外域而在资源表中生成的划归记录(需要调AS_CON_Parse进行解析) */
    RESULT_CODE             = 272,      /**< 结果码 */
    RES_ORDER_NUMBER        = 273,      /**< 资源排序序号 */

    AUTOID                  = 273,      /**< 主键 */

    EVENT_TYPE_NAME         = 273,      /**< 事件类型名称 */

    IS_QUERY_SYSTEM_EVENT_TYPE = 274,   /**< 0-查询全部;1-查询系统预定义;2-查询用户自定义 */

    IS_SUPPORT_BISTORE_CAM     = 275,   /**< 是否增加支持双直存的外域摄像机过滤条件 */

    RES_STATUS_CONDITON     = 276,      /**< 资源状态查询条件 */
    DM_CODE                 = 277,      /**< DM编码 */      /* Add by zhouquanwei/z01364 for 分布式PAG——SDK接口 */

    /* Begin: Modifid by luhaitao/01337, 2016-03-29 for 湘潭容灾 */
    IS_HIDE_BKP_LINK_DEV    = 278,      /**< 是否屏蔽备链路重复节点资源 */
    /* End: Modifid by luhaitao/01337, 2016-03-29 for 湘潭容灾 */

    CONF_START_TIME         = 300,      /**< 会议开始时间，1970年以来的秒数 */
    CONF_END_TIME           = 301,      /**< 会议结束时间，1970年以来的秒数 */

    STORE_DEV_NAME       = 302,          /**< 存储设备名称 */
    DM_NAME                   = 303,          /**< 数据管理服务器名称 */
    RES_BELONGIN         = 304,          /**< 资源归属,0代表原始加入#MM_RESOURCE_BELONGIN_ORIGINAL，1代表划归过来#MM_RESOURCE_BELONGIN_TRANSFER */
    IS_CASE_SERVER          = 310,      /**< 是否案件备份管理服务器 */
    BAK_SERVICE_TYPE        = 311,      /**< 备份业务类型 */
    BAK_RES_SERVICE_TYPE    = 312,      /**< 备份资源业务类型 */
    DOMAIN_CODE                 = 350,      /**< 域编码 */
    TOLLGATE_CODE               = 351,      /**< 卡口编号 */
    TOLLGATE_NAME               = 352,      /**< 卡口名称 */
    TOLLGATE_CAMERA_CODE        = 353,      /**< 卡口相机编码 */
    LANE_NUMBER                 = 354,      /**< 车道编号 */
    LANE_DIRECTION              = 355,      /**< 车道方向编号 */
    PASS_TIME                   = 356,      /**< 通过时间 */
    VEHICLE_LICENSE_PLATE       = 357,      /**< 号牌号码 */
    VEHICLE_LICENSE_PLATE_TYPE  = 358,      /**< 号牌种类 */
    VEHICLE_LICENSE_PLATE_COLOR = 359,      /**< 号牌颜色 */
    SPEED_TYPE                  = 360,      /**< 速度 */
    LIMIT_SPEED                 = 361,      /**< 限速 */
    VEHICLE_LOGO                = 362,      /**< 车辆品牌 */
    VEHICLE_TYPE                = 363,      /**< 车辆类型 */
    VEHICLE_COLOR_DEPTH         = 364,      /**< 车身颜色深浅 */
    VEHICLE_COLOR               = 365,      /**< 车身颜色 */
    VEHICLE_IDENTIFY_STATUS     = 366,      /**< 识别状态 */
    VEHICLE_STATUS              = 367,      /**< 行驶状态 */
    VEHICLE_DEAL_STATUS         = 368,      /**< 车辆处理标记 */
    DISPOSITION_CODE            = 369,      /**< 布控编号 */
    DISPOSITION_TYPE            = 370,      /**< 布控类别 */
    DISPOSITION_DEPT            = 371,      /**< 布控单位 */
    DISPOSITION_USER            = 372,      /**< 布控人员 */
    DISPOSITION_STATUS          = 373,      /**< 布控状态 */
    DISPOSITION_UNDO_DEPT       = 374,      /**< 撤控单位 */
    DISPOSITION_UNDO_USER       = 375,      /**< 撤控人员 */
    PRIORITY_TYPE               = 376,      /**< 优先级 */
    ALARM_TYPE                  = 377,      /**< 告警类型 */
    PLATE_ANALYSE_STATUS        = 378,      /**< 套牌分析状态 */
    SECTION_CODE                = 379,      /**< 测速区间编号 */
    SECTION_NAME                = 380,      /**< 测速区间名称 */
    TOLLGATE_CODE_IN            = 381,      /**< 驶入卡口 */
    TOLLGATE_CODE_OUT           = 382,      /**< 驶出卡口 */
    VEHICLE_DATA_TYPE           = 383,      /**< 过车数据类型 */
    PASS_TIME2                  = 384,      /**< 通过时间2 */
    DISPOSITION_RESULT          = 385,      /**< 布控处理结果 */
    EXT_DOMAIN_PROTOCOL_TYPE    = 386,      /**< 域间通讯协议类型 */
    DISTANCE_RANGE              = 387,      /**< 距离范围 */
    DEFAULT_WEBGIS_MAP          = 388,      /**< 默认WebGis地图 */
    DEFAULT_WEBGIS_POINT        = 389,      /**< 默认WebGis地图关注点 */
    STAT_TIME                   = 390,      /**< 统计时间 */

    PLACE_CODE                  = 501,      /**< 违章地点编码 */
    EQUIPMENT_TYPE              = 502,      /**< 采集类型 */
    ABNORMAL_ANALYSE_STATUS     = 503,      /**< 异常行为分析状态 */
    COUNT_TYPE                  = 504,      /**< 次数 */
    RESTRICT_TYPE               = 505,      /**< 限行方式 */
    VEHICLE_DATA_CODE           = 506,      /**< 车辆信息编号 */
    COMBINE_FLAG                = 507,      /**< 图片合成标识 */

    PROTOCOL_ID                 = 508,      /**< 协议类型 */
    PROTOCOL_DESC               = 509,      /**< 协议描述 */
    IS_SUPPORT                  = 510,      /**< 是否支持该协议 */
    IS_DEFAULT_SG               = 511,      /**< 是否默认SG支持的协议*/
    SG_CODE                     = 512,      /**< SG编码*/

    /* Begin: Added by luhaitao/01337, 2015-06-15 for ONVIF接NVR */
    PARENT_CODE_TYPE            = 513,      /**< 父设备编码类型 */
    /* End: Added by luhaitao/01337, 2015-06-15 for ONVIF接NVR */

    /*Begin add by l01420, 2014-7-31 for MPPD14821*/
    LOG_DESC                    = 515,      /**< 日志描述*/
    /*End add by l01420, 2014-7-31 for MPPD14821*/

	/* Begin Add By hexiaojun/hW0959 for 摄像机云台控制是否经过云台控制器 2015-2-10 */
	IS_PASS_PTZ                 = 516,      /**< 云台摄像机云台控制是否经过云台控制器 */
    /* End Add By hexiaojun/hW0959 for 摄像机云台控制是否经过云台控制器 2015-2-10 */
	VEHICLE_LINE                = 517,      /**< 车系 */
    VEHICLE_YEAR                = 518,      /**< 车辆生产年份 */
    VEHICLE_BRAND               = 519,      /**< 车标 */

    TVWALL_CODE                 = 520,      /**< 电视墙编码 */
    TVWALL_SCENE_ID             = 521,      /**< 电视墙场景ID */
    TVWALL_ORG_CODE             = 522,      /**< 组织域编码 */
    /*add by y02360 bugid = 29678 */
    TOLLGATE_INOUTCITY          = 523,      /**< 卡口进出城 */
    /* Begin: Added by zhouquanwei/z01364, 2015-05-11 for CDS 独立部署 */
    BM_CODE                     = 560,      /**< BM编码 */
    DEV_ONLINE_STATE            = 561,      /**< 设备在线状态 */
    GROUP_ID                    = 562,      /**< 分组ID */
    ACCOUNT_ID                  = 563,      /**< 账户ID*/
    /* End: Added by zhouquanwei/z01364, 2015-05-11 for CDS 独立部署 */

    /* Begin added by liangchao, 2015-11-04 for MPPD30081  根据CDV名称查找*/
    CDV_NAME                  = 564,      /**< CDV名称*/
    CDV_CODE                  = 565,      /**< CDV编码*/
    CDV_ID                    = 567,      /**< CDV ID*/
    CDV_ADDR                  = 568,      /**< CDV地址*/
    /* End added by liangchao, 2015-11-04 for MPPD30081  根据CDV名称查找*/

    /*Added by yaozhongmin02844,2015-12-08,遮阳板，安全带，开车打电话*/
    VEHICLE_MODEL                                    = 569,         /**<车款> */
    DRIVER_SUN_VISOR_STATUS           = 570,       /**<正驾驶遮阳板> */
    CODRIVER_SUN_VISOR_STATUS         = 571,       /**<副驾驶遮阳板>*/
    DRIVER_SEAT_BELT_STATUS            = 572,       /**<正驾驶安全带>*/
    CODRIVER_SEAT_BELT_STATUS      = 573,       /**<副驾驶安全带>*/
    DRIVER_MOBIL_STATUS                         = 574,       /**<开车打电话>*/

    /*End Added by yaozhongmin02844,2015-12-08,遮阳板，安全带，开车打电话*/

    IDENTIFY_INFO                = 579,   /**<身份信息>*/
    /*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
    DEVICE_CODE                                      = 580,    /**<设备编码(rfid编码)>*/
    MAC_ADDR                                            = 581,   /**<MAC地址>*/
    DISPOSITION_MACRFID_TYPE         = 582,    /**<MAC&RFID布控类型>*/
    DISPOSITION_MACRFID_STATUS    = 583,    /**<MAC&RFID布控状态>*/
    MAC_DISPOSE_REASON                    = 584,    /**<MAC布控原因>*/
    RFID_DISPOSE_REASON                    = 585,    /**<RFID布控原因>*/
    /*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

    START_TIME                             = 586,             /**< 开始时间 */
    END_TIME                               = 587,            /**< 结束时间 */
    /* Begin: Added by lW2822, 2016-11-10 for MPPD39454普通用户绑定DC28系列电视墙失败 */
    IS_CHECK_AUTHORITY        = 588,              /**< 是否鉴权，0代表不鉴权，1代表鉴权 */
    ADD_TIME                  = 589,               /**< 添加的时间 */
    /* End: Added by lW2822, 2016-11-10 for MPPD39454普通用户绑定DC28系列电视墙失败 */

    /* Begin added by wupeixin/03329, 2017-2-6 for fullCoverOptimization */
    CDV_TYPE                  = 590,      /**< CDV类型*/
    POOL_NAME                 = 591,      /**< 共享池名称*/
    POOL_PURPOSE              = 592,      /**< 共享池用途*/
    POOL_CODE                 = 593,      /**< 共享池编码*/
    POOL_STAT                 = 594,      /**< 共享池状态*/
    /* End added by wupeixin/03329, 2017-2-6 for fullCoverOptimization */
    /* Added by wupeixin/03329, 2017-3-16 for MPPD46031 */
    POOL_SPARE_CAP            = 595,      /**< 共享池剩余容量*/

    /*Begin: Added by hesongchang/02908, 2017-07-06 for 物联网MAC业务，支持场所、安全厂商新配置项*/
    /*---------------场所---------------*/
    MAC_PLACE_CODE                  = 600,
    MAC_PLACE_NAME                  = 601,
    MAC_BOSS_NAME                   = 602,
    MAC_PLACE_FULL_NAME                   = 603,

    /*---------------安全厂商---------------*/
    MAC_MANU_NAME                   = 604,
    MAC_MANU_ORG_CODE               = 605,
    MAC_CONTACT_PEOPLE              = 606,
    /*End: Added by hesongchang/02908, 2017-07-06 for 物联网MAC业务，支持场所、安全厂商新配置项*/

    /* Begin: Added by l03769, 2017-07-26 for MPPD49572 物联网设备经纬度上报和超感IPC能力管理 */
    QUERY_IOT_TYPE            = 607,               /** = 1 只查物联网设备，包括DAE和超感IPC
                                                       = 2 只查物联网设备推送的资源 */
    /* End: Added by l03769, 2017-07-26 for MPPD49572 物联网设备经纬度上报和超感IPC能力管理 */

	/*Begin added by w4028 2017-11-06 for 二次更新加字段MPPD53407*/
    QUERY_DANGEROUS_GOODS           = 608,
    QUERY_YELLOW_CAR                = 609,
    QEURY_ANNUAL_SURVEY             = 610,
    QUERY_PENDENT                   = 611,
	/*End added by w4028 2017-11-06 for 二次更新加字段MPPD53407*/
   /* Begin: Add by zW4385, 2017-12-28 for MPPD54417 模糊查询去重 */
    IS_DISTINCT                =612,              /**<  是否去重 */
    /* End: Add by zW4385, 2017-12-28 for MPPD54417 模糊查询去重 */

    QUERY_TYPE_MAX          /**< 无效值 */
}QUERY_TYPE_E;

/**
 * @enum tagIMOSFavoriteStream
 * @brief  流配置策略类型
 * @attention 无
 */
typedef enum tagIMOSFavoriteStream
{
    IMOS_FAVORITE_STREAM_ANY        = 0,        /**< 不指定 */
    IMOS_FAVORITE_STREAM_PRIMARY    = 1,        /**< 指定主流 */
    IMOS_FAVORITE_STREAM_SECONDERY  = 2,        /**< 指定辅流 */
    IMOS_FAVORITE_STREAM_THIRD      = 3,        /**< 指定三流 */
    IMOS_FAVORITE_STREAM_FOURTH     = 4,        /**< 指定四流 */
    IMOS_FAVORITE_STREAM_FIFTH      = 5,        /**< 指定五流 */
    IMOS_FAVORITE_STREAM_BI_AUDIO   = 6,        /**< 指定语音对讲 */
    IMOS_FAVORITE_STREAM_VOICE_BR   = 7,        /**< 指定语音广播 */
    IMOS_FAVORITE_STREAM_BUTT,
    IMOS_FAVORITE_STREAM_INVALID    = 0xFFFF    /**< 无效值 */
}IMOS_FAVORITE_STREAM_E;


/**
 * @enum  tagSubscribePushType
 * @brief 订阅推送的类型
 * @attention 无
 */
typedef enum tagSubscribePushType
{
    SUBSCRIBE_PUSH_TYPE_ALL          = 0,   /**< 接受告警推送和设备状态推送 */
    SUBSCRIBE_PUSH_TYPE_ALARM        = 1,   /**< 只接收告警推送 */
    SUBSCRIBE_PUSH_TYPE_ALARM_STATUS = 2,   /**< 只接收设备状态推送 */

    SUBSCRIBE_PUSH_TYPE_MAX,
    SUBSCRIBE_PUSH_TYPE_INVALID = 0xFFFFFFFF
}SUBSCRIBE_PUSH_TYPE_E;

/**
 * @enum  tagCSOperateCode
 * @brief 呼叫服务操作原因码
 * @attention 无
 */
typedef enum tagCSOperateCode
{
    USER_OPERATE_SERVICE = 0,                               /**< 用户主动发起操作 */

/*****************服务器主动发起的动作类型(开始)*******************/

    SWITCH_OPERATE              = 1,    /**< 轮切操作 */
    PLAN_SWITCH_OPERATE         = 2,    /**< 计划轮切操作 */
    SERVICE_REAVE               = 3,    /**< 业务抢占 */
    ALARM_LINKAGE_START_SERVICE = 4,    /**< 告警联动 */
    EXT_DOMAIN_OPER_SERVICE     = 5,    /**< 外域发起操作 */

    EC_ONLINE                   = 6,    /**< EC上线 */
    EC_OFFLINE                  = 7,    /**< EC下线 */
    EC_DELETE                   = 8,    /**< EC删除 */
    CAMERA_ONLINE               = 9,    /**< 摄像机上线 */
    CAMERA_OFFLINE              = 10,   /**< 摄像机下线 */

    DC_ONLINE                   = 11,   /**< DC上线 */
    DC_OFFLINE                  = 12,   /**< DC下线 */
    DC_DELETE                   = 13,   /**< DC删除 */

    MS_ONLINE                   = 14,   /**< MS上线 */
    MS_OFFLINE                  = 15,   /**< MS下线 */
    MS_OFFLINE_TRANSFER         = 16,   /**< MS下线引起的转移 */
    MS_DELETE_TRANSFER          = 17,   /**< MS删除引起的转移 */
    MS_DELETE                   = 18,   /**< MS删除 */

    VX500_ONLINE                = 19,   /**< VX500上线 */
    VX500_OFFLINE               = 20,   /**< VX500下线 */
    VX500_DELETE                = 21,   /**< VX500删除 */

    ISC_ONLINE                  = 22,   /**< ISC3000-E上线 */
    ISC_OFFLINE                 = 23,   /**< ISC3000-E下线 */

    EX_DOMAIN_JUNIOR_ONLINE     = 24,   /**< 下级域上线 */
    EX_DOMAIN_SUPERIOR_ONLINE   = 25,   /**< 上级域上线 */
    EX_DOMAIN_JUNIOR_OFFLINE    = 26,   /**< 下级域下线 */
    EX_DOMAIN_SUPERIOR_OFFLINE  = 27,   /**< 上级域下线 */
    EXT_DOMAIN_DELETE           = 28,   /**< 外域删除 */

    EXT_DOM_CANCEL_SHR_CAM      = 29,   /**< 外域取消共享摄像机给本域 */
    LOC_DOM_CANCEL_SHR_CAM      = 30,   /**< 本域取消共享摄像机给外域 */

    CAMERA_DELETE               = 31,   /**< CAMERA删除 */
    MONITOR_DELETE              = 32,   /**< MONITOR删除 */

    SWITCH_RES_MDF              = 33,   /**< 轮切资源修改 */
    SWITCH_RES_DEL              = 34,   /**< 轮切资源删除 */
    SWITCH_PLAN_DEL             = 35,   /**< 轮切计划删除 */
    SWITCH_PLAN_MODIFY          = 36,   /**< 轮切计划修改 */

    XP_ONLINE                   = 37,   /**< XP上线 */
    XP_OFFLINE                  = 38,   /**< XP下线 */
    USER_KEEPALIVE_FAIL         = 39,   /**< 用户保活失败 */
    USER_DELETE                 = 40,   /**< 用户被删除 */
    USER_QUIT                   = 41,   /**< 用户退出 */
    USER_KICKED_OUT             = 42,   /**< 用户被强制下线 */

    SYSMANGER_OPERATE_SERVICE   = 43,   /**< 管理员操作 */
    PTZ_LINK_TIMER_OUT          = 44,   /**< 云台连接超时 */
    PTZ_FIRST_LINK              = 45,   /**< 云台首次连接 */
    PTZ_LOW_AUTHORITY           = 46,   /**< 云台控制权限低 */
    PTZ_NO_AUTHORITY            = 47,   /**< 无云台控制权限 */
    PTZ_HAS_LOCKED              = 48,   /**< 云台被锁定 */

    DEV_MEDIA_PARAM_CHANGE      = 49,   /**< 设备媒体参数修改 */

    SALVO_OPERATE               = 50,   /**< 组显示操作 */

    SALVO_RES_DEL               = 51,   /**< 组显示删除 */
    SALVO_RES_MDF               = 52,   /**< 组显示修改 */

    GROUPSWITCH_RES_DEL         = 53,   /**< 组轮巡资源删除 */
    GROUPSWITCH_RES_MDF         = 54,   /**< 组轮巡资源修改 */

    GROUPSWITCH_PLAN_DEL        = 55,   /**< 组轮巡计划删除 */
    GROUPSWITCH_PLAN_MODIFY     = 56,   /**< 组轮巡计划修改 */

    GROUPSALVO_OPERATE          = 57,   /**< 组轮巡操作 */
    GROUPSALVO_STOP             = 58,   /**< 组轮巡停止 */
    GROUPSALVO_PLAN_OPERATE     = 59,   /**< 组轮巡计划操作 */

    INTERNAL_ERR_OPERATE        = 60,   /**< 内部错误引起操作 */

    PTZ_CCB_FULL                = 61,   /**< 控制块已满 */

    MONITOR_SPLIT_SCREEN_DELETE = 62,   /**< 监视器分屏删除 */
    MONITOR_SPLIT_SCREEN_SWITCH = 63, /**< 监视器分屏切换 */

    ALARM_LINKAGE_RESUME_SERVICE = 64,  /**< 告警联动恢复 */
    MONITOR_SPLIT_SCREEN_SWITCH_STOP = 65, /**< 监视器分屏切换引起的"停止业务"操作 */
    MONITOR_SPLIT_SCREEN_SWITCH_START = 66, /**< 监视器分屏切换引起的"启动业务"操作 */
    MONITOR_SPLIT_SCREEN_SWITCH_START_FULL = 67, /**< 监视器分屏切换引起的"启动业务"操作 - 切至全屏 */
    MONITOR_SPLIT_SCREEN_SWITCH_START_EXIT = 68, /**< 监视器分屏切换引起的"启动业务"操作 - 退出全屏 */

    CALLEE_USER_OPERATE_SERVICE = 70,   /**< 被叫用户发起操作 */
    SYSTEM_OPERATE_SERVICE      = 71,   /**< 系统发起操作 */
    CALLEE_NOT_SUPPORT_SERVICE  = 72,   /**< 被叫不支持此业务操作 */

    EXDOMAIN_CRUISE_PATH_DELETE  = 73,   /**< 跨域巡航路线删除 */

    TS_OFFLINE                   = 74,   /**< TS下线 */
    TS_OFFLINE_TRANSFER          = 75,   /**< TS下线引起的转移 */
    TS_DELETE_TRANSFER           = 76,   /**< TS删除引起的转移 */
    TS_DELETE                    = 77,   /**< TS删除 */
    TS_ONLINE                    = 78,   /**< TS上线 */
    VOD_OFFLINEORDELETE          = 79,   /**< VOD服务器离线或删除 */
	/* Begin Added by dengshuhua00673, 2012-11-27 of 自动布局轮巡 */
	AUTOSALVO_OPERATE            = 80,   /**< 自动布局组轮巡操作 */
	AUTOSALVO_STOP               = 81,   /**< 自动布局组轮巡停止 */
	AUTOSWITCH_RES_MDF           = 82,   /**< 自动布局组轮巡资源修改 */
	AUTOSWITCH_RES_DEL           = 83,   /**< 自动布局组轮巡资源删除 */
	/* End Added by dengshuhua00673, 2012-11-27 of 自动布局轮巡 */

    DC_CONFIGURE_DC_INST         = 84,   /**< 设置DC拼接、模拟输入等信息 */

    /* Begin: added by zkf0134, 2013.11.23 for 分屏切换支持主辅流自适应*/
    MONITOR_SWITCH_SPLIT_SCREEN_START = 85,   /**< 监视器分屏切换引起的"启动业务操作"*/
    /* End: added by zkf0134, 2013.11.23 for 分屏切换支持主辅流自适应*/

	PLAN_GUARD_OPERATE   =  86,/**<计划看守操作*/
    LS_OFFLINE                   = 87,   /**< LS下线 */
    LS_OFFLINE_TRANSFER          = 88,   /**< LS下线引起的转移 */
    LS_DELETE_TRANSFER           = 89,   /**<LS删除引起的转移 */
    LS_DELETE                    = 90,   /**< LS删除 */
    LS_ONLINE                    = 91,   /**< LS上线 */

    VOD_ONLINE                   = 92,   /**< VOD上线 */
    VOD_OFFLINE                  = 93,   /**< VOD下线 */
    VOD_OFFLINE_TRANSFER         = 94,   /**< VOD下线引起的转移 */
    VOD_DELETE_TRANSFER          = 95,   /**< VOD删除引起的转移 */
    VOD_DELETE                   = 96,   /**<VOD删除 */

    TS_RULE_CHANGE               = 97,   /**< TS规则改变 */
	/* Begin: added by y01359, 2015-01-28 for A8 */
	A8_ONLINE                    = 98,  /**< A8上线 */
	A8_OFFLINE                   = 99,  /**< A8下线 */
	A8_DELETE                    = 100,  /**< A8删除 */
	A8_WINDOW_DELETE             = 101,  /**< A8窗口删除 */
	/* End: added by y01359, 2015-01-28 for A8 */

	STREAM_REBUILD               = 102, /**<VM检测到异常后主动重建流 */

	/* Begin: added by y01359, 2016-05-13 for A8 */
    A8_SCENE_SERVICE             = 103,  /**< A8场景操作 */
    A8_WINDOW_SPLIT              = 104,  /**< A8窗口分屏 */
	/* End: added by y01359, 2015-01-28 for A8 */

    /* Begin add by zhuzhicong/02302/代傅晓合入, 2017-07-03 for MPPD48388 XWARE接入平台 */
    XWARE_ONLINE                 = 105,    /**< XWARE上线 */
    XWARE_OFFLINE                = 106,    /**< XWARE下线 */
    XWARE_DELETE                 = 107,    /**< XWARE删除 */
    /* End add by zhuzhicong/02302/代傅晓合入, 2017-07-03 for MPPD48388 XWARE接入平台 */

    /* Begin add by f03368, 2017-06-17 for 新国标检测语音输出设备 */
    AUDIO_OUTPUT_ONLINE       = 108,      /**< 语音输出上线 */
    AUDIO_OUTPUT_OFFLINE      = 109,      /**< 语音输出下线 */
    AUDIO_OUTPUT_DELETE        = 110,     /**< 语音输出删除 */
    EXT_DOM_CANCEL_SHR_AUDIO_OUTPUT      = 111,   /**< 外域取消共享语音输出给本域 */
    LOC_DOM_CANCEL_SHR_AUDIO_OUTPUT      = 112,   /**< 本域取消共享语音输出给外域 */
    /* End add by f03368, 2017-06-17 for 新国标检测语音输出设备 */
    /* Begin: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */
    AUTOPOLL_OPERATE             = 113,   /** A8拼控自动布局轮巡操作*/
    /* End: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */

    /* Begin: Added by liucanming 03903, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */
    GROUPPOLL_RES_DEL            = 114,   /**< A8组轮巡资源删除 */
    GROUPPOLL_RES_MDF            = 115,   /**< A8组轮巡资源修改 */
    AUTOPOLL_RES_MDF             = 116,   /**< A8自动布局轮巡资源修改 */
    AUTOPOLL_RES_DEL             = 117,   /**< A8自动布局轮巡资源删除 */
    /* End: Added by liucanming 03903, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */

/*****************服务器主动发起的动作类型(结束)*******************/

    CS_OPERATE_CODE_MAX,
    CS_OPERATE_CODE_INVALID = 0xFF
}CS_OPERATE_CODE_E;

/**
 * @enum  tagCSSwitchAdjustAction
 * @brief 轮切服务手动调整类型
 * @attention 无
 */
typedef enum tagCSSwitchAdjustAction
{
    SWTICH_PAUSE    = 0,    /**< 轮切暂停 */
    SWITCH_CONTINUE = 1,    /**< 轮切恢复 */
    SWITCH_FORWARD  = 2,    /**< 轮切向前调整 */
    SWITCH_BACKWARD = 3,    /**< 轮切向后调整 */

    SWITCH_ADJUST_ACTION_MAX,                   /**< 最大值 */
    SWITCH_ADJUST_ACTION_INVALID = 0xFF         /**< 无效值 */
}CS_SWITCH_ADJUST_ACTION_E;



/**
 * @enum tagTCProtocolType
 * @brief  透明通道数据传输协议类型枚举
 * @attention 1.只支持UDP协议类型,暂不支持TCP与SIP协议类型
 */
typedef enum tagTCProtocolType
{
    UDP_PROTOCOL    = 1,    /**< 协议类型为UDP */

    TCP_PROTOCOL    = 2,    /**< 协议类型为TCP(暂不支持) */
    SIP_PROTOCOL    = 3,    /**< 协议类型为SIP(暂不支持) */

    PROTOCOL_TYPE_INVALID = 0xFFFFFFFF /**< 无效值 */
}TC_PROTOCOL_TYPE_E;

/**
* @enum tagGisMapParamType
* @brief 地图参数类型枚举
* @attention
*/
typedef enum tagGisMapParamType
{
    GIS_MAP_PAPAM_HOTZONE   = 0,    /**< 热区 */
    GIS_MAP_PAPAM_HOTPOT   = 1,     /**< 热点 */
    GIS_MAP_PAPAM_CAMICON = 2,      /**< 摄像机图标 */
    GIS_MAP_PAPAM_ALMSRCICON = 3,   /**< 告警源图标 */
    GIS_MAP_PAPAM_TOLLGATE = 4,     /**< 卡口图标 */

    GIS_MAP_PAPAM_MAX,
    GIS_MAP_PAPAM_INVALID = 0xFF
}GIS_MAP_PAPAM_TYPE_E;


/*******************************************************************************
SS新增定义
*******************************************************************************/

/**
 * @enum tagDeviceOnlineStatus
 * @brief 设备在线状态
 * @attention
 */
typedef enum tagDeviceOnlineStatus
{
    IMOS_EN_DEVICE_STATUS_INVALID   = 0,    /**< 设备无效状态*/
    IMOS_EN_DEVICE_STATUS_ONLINE    = 1,    /**< 设备在线, 和IMOS_DEV_STATUS_ONLINE取值一样*/
    IMOS_EN_DEVICE_STATUS_OFFLINE   = 2,    /**< 设备离线, 和IMOS_DEV_STATUS_OFFLINE取值一样*/

    IMOS_EN_DEVICE_STATUS_MAX               /**< 设备状态, 最大值*/
}DEV_ONLINE_STATUS_E;

/**
 * @enum tagDeviceOperateType
 * @brief 设备操作类型
 * @attention
 */
typedef enum tagDeviceOperateType
{
    OPERATE_DEVICE_ADD  = 0,    /**< 设备新增 */
    OPERATE_DEVICE_MOD  = 1,    /**< 设备修改 */
    OPERATE_DEVICE_DEL  = 2     /**< 设备删除 */
}DEVICE_OPERATE_TYPE_E;

/**
* @enum tagHD_NaaTypeEx
* @brief NAA类型
* @attention 无
*/
typedef  enum  tagHD_NaaTypeEx
{
    IMOS_EN_NAA_TYPE_AUTO = 0,                                     /**< 自动 */
    IMOS_EN_NAA_TYPE_100MS = 100,                                  /**< 100ms */
    IMOS_EN_NAA_TYPE_200MS = 200,                                  /**< 200ms */
    IMOS_EN_NAA_TYPE_300MS = 300,                                  /**< 300ms */
    IMOS_EN_NAA_TYPE_400MS = 400,                                  /**< 400ms */
    IMOS_EN_NAA_TYPE_500MS = 500,                                  /**< 500ms */
    IMOS_EN_NAA_TYPE_600MS = 600,                                  /**< 600ms */
    IMOS_EN_NAA_TYPE_700MS = 700,                                  /**< 700ms */
    IMOS_EN_NAA_TYPE_800MS = 800,                                  /**< 800ms */
    IMOS_EN_NAA_TYPE_900MS = 900,                                  /**< 900ms */
    IMOS_EN_NAA_TYPE_1000MS = 1000,                                /**< 1000ms */
    IMOS_EN_NAA_TYPE_1100MS = 1100,                                /**< 1100ms */
    IMOS_EN_NAA_TYPE_1200MS = 1200,                                /**< 1200ms */
    IMOS_EN_NAA_TYPE_1300MS = 1300,                                /**< 1300ms */
    IMOS_EN_NAA_TYPE_1400MS = 1400,                                /**< 1400ms */
    IMOS_EN_NAA_TYPE_1500MS = 1500,                                /**< 1500ms */
    IMOS_EN_NAA_TYPE_1600MS = 1600,                                /**< 1600ms */
    IMOS_EN_NAA_TYPE_1700MS = 1700,                                /**< 1700ms */
    IMOS_EN_NAA_TYPE_1800MS = 1800,                                /**< 1800ms */
    IMOS_EN_NAA_TYPE_1900MS = 1900,                                /**< 1900ms */
    IMOS_EN_NAA_TYPE_2000MS = 2000,                                /**< 2000ms */
    IMOS_EN_NAA_TYPE_COUNT
} HD_NAA_TYPE_EX_E;

/**
 * @enum tagMC_MonitorEx
 * @brief 监控图像类型设置
 * @attention
 */
typedef  enum tagMC_MonitorEx
{
    IMOS_EN_MONITOR1_VIDEO  = 0,    /**< 监控单画面 */
    IMOS_EN_MONITOR4_VIDEO  = 1,    /**< 监控4画面 */
    IMOS_EN_MONITOR9_VIDEO  = 2,    /**< 监控9画面 */
    IMOS_EN_MONITOR_VIDEO_COUNT
} MC_MONITOR_EX_E;

/**
 * @enum tagMC_ConfStatusEx
 * @brief 会议状态
 */
typedef  enum tagMC_ConfStatusEx
{
    IMOS_EN_CONF_STATUS_NOT_BEGIN   = 0,    /**< 会议预约成功，没有开始 */
    IMOS_EN_CONF_STATUS_CALLING     = 1,    /**< 正在召集中 */
    IMOS_EN_CONF_STATUS_LIVING      = 2,    /**< 召开中 */
    IMOS_EN_CONF_STATUS_DROPPING    = 3,    /**< 在解散中 */
    IMOS_EN_CONF_STATUS_ENDED       = 4,    /**< 会议已经结束 */
    IMOS_EN_CONF_UNREGED            = 5,    /**< 会议已注销 */
    IMOS_EN_CONF_REGED              = 6,    /**< 会议已注册 */
    IMOS_EN_CONF_STATUS_CREATE_FAIL = 1000, /**< 会议创建失败 */
    IMOS_EN_CONF_STATUS_CALL_IN     = 1001, /**< 会议召开，且互联通道打开 */
    IMOS_EN_CONF_STATUS_DELETED     = 1002, /**< 会议删除 */

    IMOS_EN_CONF_STATUS_INVALID = 0xFFFF
} MC_CONF_STATUS_EX_E;

/* Begin: added by o06299 for 级联特性 of 2010.04.13 */
/**
* @enum tagConfMcuCascTypeEx
* @brief 会议MCU级联类型
* @attention
*/
typedef  enum tagConfMcuCascTypeEx
{
    IMOS_EN_CONF_MCU_TYPE_MASTER     = 0,  /**< 简单级联主MCU */
    IMOS_EN_CONF_MCU_TYPE_SECONDARY  = 1,  /**< 简单从MCU */
    IMOS_EN_CONF_MCU_TYPE_NO_CASCADE = 2,  /**< 非级联MCU */
    IMOS_EN_CONF_MCU_TYPE_COUNT
}CONF_MCU_CASCADE_TYPE_E;
/* END: added by o06299 for 级联特性 of 2010.04.13 */

/**
 * @enum tagMC_BroadcastedObserveEx
 * @brief 被广播会场的观看会场设置
 * @attention
 */
typedef  enum tagMC_BroadcastedObserveEx
{
    IMOS_EN_OBSERVE_MYSELF  = 0,    /**< 自己 */
    IMOS_EN_OBSERVE_LASTER  = 1,    /**< 上次广播会场 */
    IMOS_EN_OBSERVE_MAIN    = 2,    /**< 主会场 */
    IMOS_EN_OBSERVE_COUNT
} MC_BROADCASTED_OBSERVE_EX_E;

/**
 * @enum tagMC_SingleShowModeEx
 * @brief 单画面显示模式
 * @attention
 */
typedef  enum tagMC_SingleShowModeEx
{
    IMOS_EN_SHOW_SET_SITE        = 0,   /**< 显示指定会场 */
    IMOS_EN_SHOW_CHAIR           = 1,   /**< 显示会议主席 */
    IMOS_EN_SHOW_SPEAKER         = 2,   /**< 显示发言人 */
    IMOS_EN_SHOW_VOICE_ACTIVATED = 3,   /**< 语音激励 */
    IMOS_EN_SHOW_COUNT
} MC_SINGLE_SHOW_MODE_EX_E;

/**
 * @enum tagHD_ColorGroupTypeEx
 * @brief 16组颜色组
 * @attention
 */
typedef  enum tagHD_ColorGroupTypeEx
{
     IMOS_EN_COLOR_GROUP0   = 0,
     IMOS_EN_COLOR_GROUP1   = 1,
     IMOS_EN_COLOR_GROUP2   = 2,
     IMOS_EN_COLOR_GROUP3   = 3,
     IMOS_EN_COLOR_GROUP4   = 4,
     IMOS_EN_COLOR_GROUP5   = 5,
     IMOS_EN_COLOR_GROUP6   = 6,
     IMOS_EN_COLOR_GROUP7   = 7,
     IMOS_EN_COLOR_GROUP8   = 8,
     IMOS_EN_COLOR_GROUP9   = 9,
     IMOS_EN_COLOR_GROUP10  = 10,
     IMOS_EN_COLOR_GROUP11  = 11,
     IMOS_EN_COLOR_GROUP12  = 12,
     IMOS_EN_COLOR_GROUP13  = 13,
     IMOS_EN_COLOR_GROUP14  = 14,
     IMOS_EN_COLOR_GROUP15  = 15,
     IMOS_EN_COLOR_GROUP_COUNT
} HD_COLOR_GROUP_TYPE_EX_E;


/**
 * @enum tagHD_DiffServTypeEx
 * @brief Diffserv类别
 * @attention
 */
typedef  enum  tagHD_DiffServTypeEx
{
    IMOS_EN_EXPEDITED_FORWARDING = 0xB8,              /**< 加速转发服务 */
    IMOS_EN_ASSURED_FORWARDING_4_1 = 0x88,            /**< 确保转发服务41 */
    IMOS_EN_ASSURED_FORWARDING_4_2 = 0x90,            /**< 确保转发服务42 */
    IMOS_EN_ASSURED_FORWARDING_4_3 = 0x98,            /**< 确保转发服务43 */
    IMOS_EN_CLASS_BEST_EFFORD = 0                     /**< 尽力服务 */
} HD_DIFFSERV_TYPE_EX_E;

/**
 * @enum tagMC_ChairLookModeEx
 * @brief 会议中需要增加的切换广播画面时主席观看模式
 * @attention
 */
typedef enum tagMC_ChairLookModeEx
{
    IMOS_EN_CHAIR_LOOK_NOCHG    = 0,    /**< [开启] 默认 */
    IMOS_EN_CHAIR_LOOK_BROAD    = 1,    /**< [跟随广播切换] */
    IMOS_EN_CHAIR_LOOK_CLOSE    = 2,    /**< 关闭 */
    IMOS_EN_CHAIR_LOOK_COUNT
} MC_CHAIR_LOOK_MODE_EX_E;

/**
 * @enum tagMC_MultiPicCycModeEx
 * @brief 多画面轮巡需要设置的两种模式
 * @attention
 */
typedef  enum  tagMC_MultiPicCycModeEx
{
    IMOS_EN_MULTI_CYC_SAME_LIST = 0,    /**< 多画面轮巡使用同一张轮巡列表 */
    IMOS_EN_MULTI_CYC_SEP_LIST  = 1,    /**< 多画面轮巡使用各自的轮巡列表 */
    IMOS_EN_MULTI_CYC_COUNT
} MC_MULTIPIC_CYC_MODE_EX_E;

/**
 * @enum tagMC_SelectLookEx
 * @brief 会场选择观看枚举
 * @attention
 */
typedef  enum  tagMC_SelectLookEx
{
    IMOS_EN_SEL_LOOK_NO     = 0,    /**< 不允许选择观看 */
    IMOS_EN_SEL_LOOK_YES    = 1,    /**< 允许选择观看 */
    IMOS_EN_SEL_LOOK_COUNT
} MC_SELECT_LOOK_EX_E;

/**
 * @enum tagMC_AheadEndConfEx
 * @brief 提前结束会议通知的枚举
 * @attention
 */
typedef  enum  tagMC_AheadEndConfEx
{
    IMOS_EN_AHEAD_END_CONF_NO     = 0,                /**< 不提前结束会议 */
    IMOS_EN_AHEAD_END_CONF_THREE  = 180,              /**< 提前三分钟结束会议 */
    IMOS_EN_AHEAD_END_CONF_FIVE   = 300,              /**< 提前五分钟结束会议 */
    IMOS_EN_AHEAD_END_CONF_TEN    = 600,              /**< 提前十分钟结束会议 */
    IMOS_EN_AHEAD_END_CONF_TWENTY = 1200,             /**< 提前二十分钟结束会议 */
    IMOS_EN_AHEAD_END_CONF_THIRTY = 1800,             /**< 提前三十分钟结束会议 */
    IMOS_EN_AHEAD_END_CONF_COUNT,
} MC_AHEAD_END_CONF_EX_E;

/**
 * @enum tagMC_ConfCycleTypeEx
 * @brief 会议重复方式
 * @attention
 */
typedef  enum tagMC_ConfCycleTypeEx
{
    IMOS_EN_CONF_NOT_CYCLE              = 0,    /**< 非周期会议[仅一次] */
    IMOS_EN_CONF_CYCLE_TYPE_EVERY_MONTH = 1,    /**< 按月 */
    IMOS_EN_CONF_CYCLE_TYPE_EVERY_WEEK  = 2,    /**< 按周 */
    IMOS_EN_CONF_CYCLE_TYPE_EVERY_DAY   = 3,    /**< 按天 */
    IMOS_EN_CONF_CYCLE_TYPE_COUNT
} MC_CONF_CYCLE_TYPE_EX_E;

/**
 * @enum tagMC_ConfCycleEndTypeEx
 * @brief 周期会议结束类型
 * @attention
 */
typedef  enum tagMC_ConfCycleEndTypeEx
{
    IMOS_EN_CONF_CYCLE_END_COUNT = 0,   /**< 重复次数 */
    IMOS_EN_CONF_CYCLE_END_DATE  = 1,   /**< 截止日期 */
    IMOS_EN_CONF_CYCLE_END_TYPE_COUNT
} MC_CONF_CYCLE_END_TYPE_EX_E;

/**
 * @enum tagConfReportSampleType
 * @brief 报表采样周期类型
 * @attention
 */
typedef  enum tagConfReportSampleType
{
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_HOUR    = 0,    /**< 按小时 */
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_DAY     = 1,    /**< 按天 */
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_MONTH   = 2,    /**< 按月 */
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_COUNT
} CONF_REPORT_SAMPLE_TYPE_E;

/**
 * @enum tagMC_ConfCascadeTypeEx
 * @brief 会议级联模式
 * @attention
 */
typedef  enum tagMC_ConfCascadeTypeEx
{
    IMOS_EN_CONF_CASCADE_TYPE_NO    = 0,    /**< 非级联 */
    IMOS_EN_CONF_CASCADE_TYPE_YES   = 1,    /**< 级联 */
    IMOS_EN_CONF_CASCADE_TYPE_COUNT
} MC_CONF_CASCADE_TYPE_EX_E;

/**
 * @enum tagMC_ConfCascadeRelationEx
 * @brief 会议级联关系,在添加级联会议时指定
 * @attention
 */
typedef  enum tagMC_ConfCascadeRelationEx
{
    IMOS_EN_CONF_CASCADE_RELATION_SUP    = 0,   /**< 上级级联 */
    IMOS_EN_CONF_CASCADE_RELATION_SUB    = 1,   /**< 下级级联 */
    IMOS_EN_CONF_CASCADE_RELATION_SIMPLE = 2,   /**< 简单级联 */
    IMOS_EN_CONF_CASCADE_RELATION_COUNT
} MC_CONF_CASCADE_RELATION_EX_E;



/**
 * @enum tagHD_ColorTable16TypeEx
 * @brief 16色颜色表中颜色类型
 * @attention
 */
typedef  enum tagHD_ColorTable16TypeEx
{
     IMOS_EN_COLOR_TABLE16_TYPE0    = 0,
     IMOS_EN_COLOR_TABLE16_TYPE1    = 1,
     IMOS_EN_COLOR_TABLE16_TYPE2    = 2,
     IMOS_EN_COLOR_TABLE16_TYPE3    = 3,
     IMOS_EN_COLOR_TABLE16_TYPE4    = 4,
     IMOS_EN_COLOR_TABLE16_TYPE5    = 5,
     IMOS_EN_COLOR_TABLE16_TYPE6    = 6,
     IMOS_EN_COLOR_TABLE16_TYPE7    = 7,
     IMOS_EN_COLOR_TABLE16_TYPE8    = 8,
     IMOS_EN_COLOR_TABLE16_TYPE9    = 9,
     IMOS_EN_COLOR_TABLE16_TYPE10   = 10,
     IMOS_EN_COLOR_TABLE16_TYPE11   = 11,
     IMOS_EN_COLOR_TABLE16_TYPE12   = 12,
     IMOS_EN_COLOR_TABLE16_TYPE13   = 13,
     IMOS_EN_COLOR_TABLE16_TYPE14   = 14,
     IMOS_EN_COLOR_TABLE16_TYPE15   = 15,
     IMOS_EN_COLOR_TABLE16_TYPE_COUNT
} HD_COLOR_TABLE16_TYPE_EX_E;

/**
 * @enum tagHD_BannerPosEx
 * @brief 横幅位置
 * @attention
 */
typedef  enum  tagHD_BannerPosEx
{
    IMOS_EN_BANNER_POS_TOPQTR   = 0,    /**< 横幅位置占屏幕上方1/4 */
    IMOS_EN_BANNER_POS_TOP3RD   = 1,    /**< 横幅位置占屏幕上方1/3 */
    IMOS_EN_BANNER_POS_TOP5     = 2,    /**< 横幅位置占屏幕上方1/5 */
    IMOS_EN_BANNER_POS_TOP6TH   = 3,    /**< 横幅位置占屏幕上方1/6 */
    IMOS_EN_BANNER_POS_TOP7     = 4,    /**< 横幅位置占屏幕上方1/7 */
    IMOS_EN_BANNER_POS_TOP8TH   = 5,    /**< 横幅位置占屏幕上方1/8 */
} HD_BANNER_POS_EX_E;

/**
 * @enum tagHD_ConfShowTimerTypeEx
 * @brief 显示会议时间的类型,会议已经开始时间、离会议结束剩余时间
 * @attention
 */
typedef  enum tagHD_ConfShowTimerTypeEx
{
    IMOS_EN_SHOW_TIMER_TYPE_NO      = 0,    /**< 不显示会议时间 */
    IMOS_EN_SHOW_TIMER_TYPE_BEGIN   = 1,    /**< 会议剩余时长 */
    IMOS_EN_SHOW_TIMER_TYPE_END     = 2,    /**< 会议持续时长 */
    IMOS_EN_SHOW_TIMER_TYPE_COUNT
} HD_CONF_SHOW_TIMER_TYPE_EX_E;



/**
 * @enum tagMC_ProtocolTypeEx
 * @brief MCU配置支持的协议类型
 * @attention
 */
typedef  enum tagMC_ProtocolTypeEx
{
    IMOS_EN_PROTOCOL_H323   = 0,    /**< H323协议 */
    IMOS_EN_PROTOCOL_SIP    = 1,    /**< SIP协议 */
    IMOS_EN_PROTOCOL_MIX    = 2,    /**< 混协议[双协议] */
    IMOS_EN_PROTOCOL_COUNT
} MC_PROTOCOL_TYPE_EX_E;

/**
 * @enum tagMC_ConfModeEx
 * @brief 会议模式
 * @attention
 */
typedef  enum tagMC_ConfModeEx
{
    IMOS_EN_CONF_MODE_DIRECTOR       = 0,   /**< 导演模式 */
    IMOS_EN_CONF_MODE_CHAIR          = 1,   /**< 主席模式 */
    IMOS_EN_CONF_MODE_VOICE_ACTUATOR = 2,   /**< 语音激励模式 */
    IMOS_EN_CONF_MODE_COUNT
} MC_CONF_MODE_EX_E;

/**
 * @enum tagHD_MultiPicNumEx
 * @brief 多分屏画面数
 * @attention
 */
typedef  enum  tagHD_MultiPicNumEx
{
    IMOS_EN_MULTI_PIC_0 = 0,                 /**< 纯转发单画面 */
    IMOS_EN_MULTI_PIC_1 = 1,                 /**< 单画面 */
    IMOS_EN_MULTI_PIC_2 = 2,                 /**< 2画面 */
    IMOS_EN_MULTI_PIC_3 = 3,                 /**< 3画面 */
    IMOS_EN_MULTI_PIC_4 = 4,                 /**< 4画面 */
    IMOS_EN_MULTI_PIC_5 = 5,                 /**< 5画面 */
    IMOS_EN_MULTI_PIC_6 = 6,                 /**< 6画面 */
    IMOS_EN_MULTI_PIC_7 = 7,                 /**< 7画面 */
    IMOS_EN_MULTI_PIC_8 = 8,                 /**< 8画面 */
    IMOS_EN_MULTI_PIC_9 = 9,                 /**< 9画面 */
    IMOS_EN_MULTI_PIC_10 = 10,               /**< 10画面 */
    IMOS_EN_MULTI_PIC_11 = 11,               /**< 11画面 */
    IMOS_EN_MULTI_PIC_12 = 12,               /**< 12画面 */
    IMOS_EN_MULTI_PIC_13 = 13,               /**< 13画面 */
    IMOS_EN_MULTI_PIC_14 = 14,               /**< 14画面 */
    IMOS_EN_MULTI_PIC_15 = 15,               /**< 15画面 */
    IMOS_EN_MULTI_PIC_16 = 16,               /**< 16画面 */
    IMOS_EN_MULTI_PIC_17 = 17,               /**< 17画面 */
    IMOS_EN_MULTI_PIC_18 = 18,               /**< 18画面 */
    IMOS_EN_MULTI_PIC_19 = 19,               /**< 19画面 */
    IMOS_EN_MULTI_PIC_20 = 20,               /**< 20画面 */
    IMOS_EN_MULTI_PIC_21 = 21,               /**< 21画面 */
    IMOS_EN_MULTI_PIC_22 = 22,               /**< 22画面 */
    IMOS_EN_MULTI_PIC_23 = 23,               /**< 23画面 */
    IMOS_EN_MULTI_PIC_24 = 24,               /**< 24画面 */
    IMOS_EN_MULTI_PIC_25 = 25,               /**< 25画面 */
    IMOS_EN_MULTI_PIC_26 = 26,               /**< 26画面 */
    IMOS_EN_MULTI_PIC_27 = 27,               /**< 27画面 */
    IMOS_EN_MULTI_PIC_28 = 28,               /**< 28画面 */
    IMOS_EN_MULTI_PIC_29 = 29,               /**< 29画面 */
    IMOS_EN_MULTI_PIC_30 = 30,               /**< 30画面 */
    IMOS_EN_MULTI_PIC_31 = 31,               /**< 31画面 */
    IMOS_EN_MULTI_PIC_32 = 32,               /**< 32画面 */
    IMOS_EN_MULTI_PIC_33 = 33,               /**< 33画面 */
    IMOS_EN_MULTI_PIC_34 = 34,               /**< 34画面 */
    IMOS_EN_MULTI_PIC_35 = 35,               /**< 35画面 */
    IMOS_EN_MULTI_PIC_36 = 36,               /**< 36画面 */
    IMOS_EN_MULTI_PIC_NUM_COUNT
} HD_MULTI_PIC_NUM_EX_E;

/**
 * @enum tagMC_MultiPicObserveEx
 * @brief 多画面时观看者设置
 * @attention
 */
typedef  enum tagMC_MultiPicObserveEx
{
    IMOS_EN_MULTI_PIC_OBSERVE_BROAD_CAST = 0,   /**< 广播多画面 */
    IMOS_EN_MULTI_PIC_OBSERVE_CHAIR      = 1,   /**< 主席观看多画面 */
    IMOS_EN_MULTI_PIC_OBSERVE_COUNT
} MC_MULTI_PIC_OBSERVE_EX_E;

/**
 * @enum tagMC_DropReinviteModeEx
 * @brief 离线重邀方式
 * @attention
 */
typedef  enum tagMC_DropReinviteModeEx
{
    IMOS_DROP_REINVITE_MODE_ALWAYS  = 0,    /**< 离线总是重邀 [永久] */
    IMOS_DROP_REINVITE_MODE_AUTO    = 1,    /**< 离线自动重邀 [自动呼20次] */
    IMOS_DROP_REINVITE_MODE_CLOSE   = 2,    /**< 关闭离线重邀 [关闭] */
    IMOS_DROP_REINVITE_MODE_COUNT
} MC_DROP_REINVITE_MODE_EX_E;

/**
 * @enum tagHD_FrameThickTypeEx
 * @brief 边框粗细类型
 * @attention
 */
typedef  enum  tagHD_FrameThickTypeEx
{
    IMOS_EN_FRAME_THICK     = 0,    /**< 粗边框 */
    IMOS_EN_FRAME_MIDDLE    = 1,    /**< 正常边框 */
    IMOS_EN_FRAME_THIN      = 2,    /**< 细边框 */
    IMOS_EN_FRAME_COUNT
} HD_FRAME_THICK_TYPE_EX_E;

/**
 * @enum tagMC_CycleTableIndexEx
 * @brief 轮巡表索引
 * @attention
 */
typedef enum tagMC_CycleTableIndexEx
{
    IMOS_EN_CYCLE_TABLE_INDEX_0 = 0,        /**< 全部会场表 */
    IMOS_EN_CYCLE_TABLE_INDEX_1 = 1,        /**< 轮巡表1 */
    IMOS_EN_CYCLE_TABLE_INDEX_2 = 2,        /**< 轮巡表2 */
    IMOS_EN_CYCLE_TABLE_INDEX_3 = 3,        /**< 轮巡表3 */
    IMOS_EN_CYCLE_TABLE_INDEX_4 = 4,        /**< 轮巡表4 */
    IMOS_EN_CYCLE_TABLE_INDEX_5 = 5,        /**< 轮巡表5 */
    IMOS_EN_CYCLE_TABLE_INDEX_6 = 6,        /**< 轮巡表6 */
    IMOS_EN_CYCLE_TABLE_INDEX_7 = 7,        /**< 轮巡表7 */
    IMOS_EN_CYCLE_TABLE_INDEX_8 = 8,        /**< 轮巡表8 */
    IMOS_EN_CYCLE_TABLE_INDEX_9 = 9,        /**< 轮巡表9 */
    IMOS_EN_CYCLE_TABLE_INDEX_COUNT
} MC_CYCLE_TABLE_INDEX_EX_E;

/**
 * @enum tagHD_ColorTable4TypeEx
 * @brief 4色颜色表中颜色类型
 * @attention
 */
typedef  enum tagHD_ColorTable4TypeEx
{
     IMOS_EN_COLOR_TABLE4_TYPE0 = 0,
     IMOS_EN_COLOR_TABLE4_TYPE1 = 1,
     IMOS_EN_COLOR_TABLE4_TYPE2 = 2,
     IMOS_EN_COLOR_TABLE4_TYPE3 = 3,
     IMOS_EN_COLOR_TABLE4_TYPE_COUNT
} HD_COLOR_TABLE4_TYPE_EX_E;

/**
 * @enum tagHD_TitlePosEx
 * @brief 会议字幕位置
 * @attention
 */
typedef  enum tagHD_TitlePosEx
{
    IMOS_EN_TITLE_POS_BOTTOM      = 0,      /**< 字幕在屏幕下方1 */
    IMOS_EN_TITLE_POS_TOP         = 1,      /**< 字幕在屏幕上方1 */
    IMOS_EN_TITLE_POS_LEFT        = 2,      /**< 字幕在屏幕左侧1 */
    IMOS_EN_TITLE_POS_RIGHT       = 3,      /**< 字幕在屏幕右侧1 */
    IMOS_EN_TITLE_POS_FULL_SCREEN = 4,      /**< 字幕在全屏显示[全屏] */
    IMOS_EN_TITLE_POS_COUNT
} HD_TITLE_POS_EX_E;

/**
 * @enum tagHD_TitleRollSpeedEx
 * @brief 会议字幕滚动速度
 * @attention
 */
typedef  enum tagHD_TitleRollSpeedEx
{
    IMOS_EN_TITLE_ROLL_MID          = 0,    /**< 字幕滚动中速[正常] */
    IMOS_EN_TITLE_ROLL_LOW          = 1,    /**< 字幕滚动慢速[低速] */
    IMOS_EN_TITLE_ROLL_FAST         = 2,    /**< 字幕滚动快速[高速] */
    IMOS_EN_TITLE_ROLL_QUIESCENCE   = 3,    /**< 字幕静止[静止] */
    IMOS_EN_TITLE_ROLL_SPEED_COUNT
} HD_TITLE_ROLL_SPEED_EX_E;

/**
 * @enum tagHD_TitleRollEndTypeEx
 * @brief 字幕滚动结束方式
 * @attention
 */
typedef  enum tagHD_TitleRollEndTypeEx
{
    IMOS_EN_TITLE_ROLL_END_COUNT    = 0,    /**< 字幕滚动次数 */
    IMOS_EN_TITLE_ROLL_END_TIME     = 1,    /**< 字幕持续时间 */
    IMOS_EN_TITLE_ROLL_END_TYPE_COUNT
} HD_TITLE_ROLL_END_TYPE_EX_E;

/**
 * @enum tagHD_TitleRollDirectionEx
 * @brief 会议字幕滚动方向
 * @attention
 */
typedef  enum tagHD_TitleRollDirectionEx
{
    IMOS_EN_ROLL_FROM_RIGHT_TO_LEFT = 0,    /**< 字幕从右到左滚动[从右到左] */
    IMOS_EN_ROLL_FROM_BUTTOM_TO_TOP = 1,    /**< 字幕从下到上滚动[从下到上] */
    IMOS_EN_TITLE_ROLL_DIRECTION_COUNT
} HD_TITLE_ROLL_DIRECTION_EX_E;

/**
 * @enum tagHD_TitleLastTimeEx
 * @brief 会议字幕持续时间
 * @attention
 */
typedef  enum tagHD_TitleLastTimeEx
{
    IMOS_EN_TITLE_LAST_TIME_FOREVER = 0,       /**< 字幕持续时间永久[永久] */
    IMOS_EN_TITLE_LAST_TIME_5MIN  = 5,         /**< 字幕持续5分钟[5分钟] */
    IMOS_EN_TITLE_LAST_TIME_10MIN = 10,        /**< 字幕持续10分钟[10分钟] */
    IMOS_EN_TITLE_LAST_TIME_15MIN = 15,        /**< 字幕持续15分钟[15分钟] */
    IMOS_EN_TITLE_LAST_TIME_30MIN = 30,        /**< 字幕持续30分钟[30分钟] */
    IMOS_EN_TITLE_LAST_TIME_45MIN = 45,        /**< 字幕持续45分钟[45分钟] */
    IMOS_EN_TITLE_LAST_TIME_60MIN = 60,        /**< 字幕持续60分钟[60分钟] */
    IMOS_EN_TITLE_LAST_TIME_120MIN = 120,      /**< 字幕持续120分钟[120分钟] */
    IMOS_EN_TITLE_LAST_TIME_COUNT
} HD_TITLE_LAST_TIME_EX_E;

/**
 * @enum tagHD_MultiPicModeEx
 * @brief 分屏模式
 * @attention
 */
typedef  enum  tagHD_MultiPicModeEx
{
    IMOS_EN_SINGLE_MODE =0,     /**< 单分屏 */

    IMOS_EN_MULTI_PIC2_MODE     = 1,    /**< 2分屏 */
    IMOS_EN_MULTI_PIC3_MODE1    = 2,    /**< 3分屏1  */
    IMOS_EN_MULTI_PIC3_MODE2    = 3,    /**< 3分屏2  */
    IMOS_EN_MULTI_PIC4_MODE     = 4,    /**< 4分屏  */

    IMOS_EN_MULTI_PIC5P1_MODE   = 5,    /**< 5+1分屏  */
    IMOS_EN_MULTI_PIC9_MODE     = 6,    /**< 9分屏  */

    IMOS_EN_MULTI_PIC3P1_MODE   = 7,    /**< 3+1分屏 */
    IMOS_EN_MULTI_PIC4P2_MODE1  = 8,    /**< 4+2分屏1 */
    IMOS_EN_MULTI_PIC12_MODE    = 9,    /**< 12分屏 */
    IMOS_EN_MULTI_PIC4P2_MODE2  = 10,   /**< 4+2分屏2 */
    IMOS_EN_MULTI_PIC7P1_MODE   = 11,   /**< 7+1分屏 */
    IMOS_EN_MULTI_PIC12P1_MODE1 = 12,   /**< 12+1分屏1 */
    IMOS_EN_MULTI_PIC8P2_MODE1  = 13,   /**< 8+2分屏1 */
    IMOS_EN_MULTI_PIC16_MODE    = 14,   /**< 16分屏 */
    IMOS_EN_MULTI_PIC8P2_MODE2  = 15,   /**< 8+2分屏2 */
    IMOS_EN_MULTI_PIC8P2_MODE3  = 16,   /**< 8+2分屏3 */
    IMOS_EN_MULTI_PIC8P2_MODE4  = 17,   /**< 8+2分屏4 */
    IMOS_EN_MULTI_PIC8P2_MODE5  = 18,   /**< 8+2分屏8 */
    IMOS_EN_MULTI_PIC12P1_MODE2 = 19,   /**< 12+1分屏2 */
    IMOS_EN_MULTI_PIC12P1_MODE3 = 20,   /**< 12+1分屏3 */
    IMOS_EN_MULTI_PIC12P1_MODE4 = 21,   /**< 12+1分屏4 */
    IMOS_EN_MULTI_PIC12P1_MODE5 = 22,   /**< 12+1分屏5 */
    IMOS_EN_MULTI_PIC8P2_MODE6  = 23,   /**< 8+2分屏6 */
    IMOS_EN_MULTI_PIC3P4_MODE1  = 24,   /**< 3+4分屏1 */
    IMOS_EN_MULTI_PIC3P4_MODE2  = 25,   /**< 3+4分屏2 */
    IMOS_EN_MULTI_PIC3P4_MODE3  = 26,   /**< 3+4分屏3 */
    IMOS_EN_MULTI_PIC3P4_MODE4  = 27,   /**< 3+4分屏4 */

    IMOS_EN_MULTI_PIC11P1_MODE  = 28,   /**< 11+1分屏 */
    IMOS_EN_MULTI_PIC20P1_MODE1 = 29,   /**< 20+1分屏1 */
    IMOS_EN_MULTI_PIC20P1_MODE2 = 30,   /**< 20+1分屏2 */
    IMOS_EN_MULTI_PIC24P3_MODE1 = 31,   /**< 24+3分屏1 */
    IMOS_EN_MULTI_PIC24P3_MODE3 = 32,   /**< 24+3分屏3 */
    IMOS_EN_MULTI_PIC6P12_MODE3 = 33,   /**< 6+12分屏3 */
    IMOS_EN_MULTI_PIC6P12_MODE5 = 34,   /**< 6+12分屏5 */
    IMOS_EN_MULTI_PIC27P1_MODE1 = 35,   /**< 27+1分屏1 */
    IMOS_EN_MULTI_PIC9P3_MODE4  = 36,   /**< 9+3分屏4 */
    IMOS_EN_MULTI_PIC18P2_MODE1 = 37,   /**< 18+2分屏1 */
    IMOS_EN_MULTI_PIC18P2_MODE4 = 38,   /**< 18+2分屏4 */
    IMOS_EN_MULTI_PIC18P2_MODE6 = 39,   /**< 18+2分屏6 */
    IMOS_EN_MULTI_PIC36_MODE    = 40,   /**< 36分屏 */

    IMOS_EN_MULTI_PICE_COUNT
} HD_MULTIPIC_MODE_EX_E;



/**
 * @enum tagHD_VideoProtFmtEx
 * @brief 视频流协议格式类型
 * @attention
 */
typedef  enum  tagHD_VideoProtFmtEx
{
    IMOS_EN_VID_H264_1080P  = 0,   /**<  H264协议 1080P格式 */
    IMOS_EN_VID_H264_720P   = 1,   /**<  H264协议 720P格式 */
    IMOS_EN_VID_H264_4CIF   = 2,   /**<  H264协议 4CIF格式 */
    IMOS_EN_VID_H264_CIF    = 3,   /**<  H264协议 CIF格式 */
    IMOS_EN_VID_H263_1080P  = 4,   /**<  H263协议 1080P格式 */
    IMOS_EN_VID_H263_720P   = 5,   /**<  H263协议 720P格式 */
    IMOS_EN_VID_H263_4CIF   = 6,   /**<  H263协议 4CIF格式 */
    IMOS_EN_VID_H263_CIF    = 7,   /**<  H263协议 CIF格式 */
    IMOS_EN_VID_PROT_FMT_COUNT
} HD_VIDEO_PROT_FMT_EX_E;


/**
 * @enum tagMC_CycleTimeIntervalEx
 * @brief 轮巡时间间隔
 * @attention
 */
typedef  enum tagMC_CycleTimeIntervalEx
{
    IMOS_EN_CYCLE_TIME_INTERVAL_15SEC = 15,                   /**< 15秒 */
    IMOS_EN_CYCLE_TIME_INTERVAL_30SEC = 30,                   /**< 30秒 */
    IMOS_EN_CYCLE_TIME_INTERVAL_45SEC = 45,                   /**< 45秒 */
    IMOS_EN_CYCLE_TIME_INTERVAL_1MIN  = 60,                   /**< 1分钟 */
    IMOS_EN_CYCLE_TIME_INTERVAL_2MIN  = 120,                  /**< 2分钟 */
    IMOS_EN_CYCLE_TIME_INTERVAL_5MIN  = 300,                  /**< 5分钟 */
    IMOS_EN_CYCLE_TIME_INTERVAL_10MIN = 600,                  /**< 10分钟 */
    IMOS_EN_CYCLE_TIME_INTERVAL_15MIN = 900,                  /**< 15分钟 */
    IMOS_EN_CYCLE_TIME_INTERVAL_30MIN = 1800,                 /**< 30分钟 */
    IMOS_EN_CYCLE_TIME_INTERVAL_COUNT
} MC_CYCLE_TIME_INTERVAL_EX_E;


/**
 * @enum tagMC_MultiPicOnePicEx
 * @brief 多画面中小画面设置
 * @attention
 */
typedef  enum tagMC_MultiPicOnePicEx
{
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_AUTO_FILL        = 0,    /**< 自动填充 */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_CHAIR            = 1,    /**< 会议主席 */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_SPEAKER          = 2,    /**< 发言人 */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_SET_SITE         = 3,    /**< 指定会场 */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_CYCLE            = 4,    /**< 会场轮巡 */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_VOICE_ACTUATOR   = 5,    /**< 语音激励 */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_COUNT
} MC_MULTI_PIC_ONE_PIC_EX_E;

/**
 * @enum tagHD_VideoProtEx
 * @brief 视频流协议类型
 * @attention
 */
typedef  enum  tagHD_VideoProtEx
{
    IMOS_EN_VID_PROT_H261   = 0,    /**< H261协议 */
    IMOS_EN_VID_PROT_H263   = 1,    /**< H263协议 */
    IMOS_EN_VID_PROT_H263P  = 2,    /**< H263+协议 */
    IMOS_EN_VID_PROT_H264   = 3,    /**< H264协议 */
    IMOS_EN_VID_PROT_MPEG4  = 4,    /**< MPEG4协议 */
    IMOS_EN_VID_PROT_AUTO   = 5,    /**< 自动 */
    IMOS_EN_VID_PROT_COUNT
} HD_VIDEO_PROT_EX_E;

/**
 * @enum tagHD_AudioProtEx
 * @brief 音频协议类型
 * @attention
 */
typedef  enum  tagHD_AudioProtEx
{
    IMOS_EN_AUD_PROT_G711A                  = 0,    /**< G711 A */
    IMOS_EN_AUD_PROT_G711U                  = 1,    /**< G711 U */
    IMOS_EN_AUD_PROT_G722_48K               = 2,    /**< G.722 48k */
    IMOS_EN_AUD_PROT_G722_56K               = 3,    /**< G.722 56k */
    IMOS_EN_AUD_PROT_G722_64K               = 4,    /**< G.722 64k */
    IMOS_EN_AUD_PROT_G7221_24K              = 5,    /**< G.722.1 24k */
    IMOS_EN_AUD_PROT_G7221_32K              = 6,    /**< G.722.1 32k */
    IMOS_EN_AUD_PROT_G7221AC_24K            = 7,    /**< G.722.1 AnnexC 24k */
    IMOS_EN_AUD_PROT_G7221AC_32K            = 8,    /**< G.722.1 AnnexC 32k */
    IMOS_EN_AUD_PROT_G7221AC_48K            = 9,    /**< G.722.1 AnnexC 48k */
    IMOS_EN_AUD_PROT_G7231_5_3K             = 10,   /**< G.723.1 5.3k */
    IMOS_EN_AUD_PROT_G7231_6_3K             = 11,   /**< G.723.1 6.3k */
    IMOS_EN_AUD_PROT_G7231SC_5_3K           = 12,   /**< G.723.1 5.3k Silence Compression */
    IMOS_EN_AUD_PROT_G7231SC_6_3K           = 13,   /**< G.723.1 6.3k Silence Compression */
    IMOS_EN_AUD_PROT_G728                   = 14,   /**< G728 */
    IMOS_EN_AUD_PROT_G7221AC_STEREO_48K     = 15,   /**< G.722.1 AnnexC 48k stereo */
    IMOS_EN_AUD_PROT_G7221AC_STEREO_64K     = 16,   /**< G.722.1 AnnexC 64k stereo */
    IMOS_EN_AUD_PROT_G7221AC_STEREO_96K     = 17,   /**< G.722.1 AnnexC 96k stereo */
    IMOS_EN_AUD_PROT_AUTO                   = 18,   /**< 自动 */
    IMOS_EN_AUD_PROT_COUNT
} HD_AUDIO_PROT_EX_E;

/**
 * @enum tagHD_VideoFormatEx
 * @brief 画面大小
 * @attention
 */
typedef  enum  tagHD_VideoFormatEx
{
    IMOS_EN_VIDEO_FMT_1080P     = 0,    /**< 1080P(1920 x 1080) */
    IMOS_EN_VIDEO_FMT_720P      = 1,    /**< 720P(1280 x 720) */
    IMOS_EN_VIDEO_FMT_4CIF      = 2,    /**< 4CIF(704 x 576) */
    IMOS_EN_VIDEO_FMT_CIF       = 3,    /**< CIF(352 x 288) */
    IMOS_EN_VIDEO_FMT_QCIF      = 4,    /**< QCIF(176 x 144) */
    IMOS_EN_VIDEO_FMT_WUXGA     = 5,    /**< WUXGA(1920 x 1200) */
    IMOS_EN_VIDEO_FMT_UXGA      = 6,    /**< UXGA(1600 x 1200) */
    IMOS_EN_VIDEO_FMT_SXGA      = 7,    /**< SXGA(1280 x 1024) */
    IMOS_EN_VIDEO_FMT_XGA       = 8,    /**< XGA(1024 x 768) */
    IMOS_EN_VIDEO_FMT_SVGA      = 9,    /**< SVGA(800 x 600) */
    IMOS_EN_VIDEO_FMT_VGA       = 10,   /**< VGA(640 x 480) */
    IMOS_EN_VIDEO_FMT_AUTO      = 11,   /**< 自动 */
    IMOS_EN_VIDEO_FMT_NONSTD    = 12,   /**< 非标格式*/
    IMOS_EN_VIDEO_FMT_COUNT

} HD_VIDEO_FORMAT_EX_E;

/**
 * @enum tagHD_FrameRateEx
 * @brief 帧率
 * @attention
 */
typedef  enum  tagHD_FrameRateEx
{
    IMOS_EN_FRAME_RATE_AUTO = 0,                                   /**< 自动 */
    IMOS_EN_FRAME_RATE_3F = 3,                                     /**< 3帧 */
    IMOS_EN_FRAME_RATE_5F = 5,                                     /**< 5帧 */
    IMOS_EN_FRAME_RATE_10F = 10,                                   /**< 10帧 */
    IMOS_EN_FRAME_RATE_15F = 15,                                   /**< 15帧 */
    IMOS_EN_FRAME_RATE_25F = 25,                                   /**< 25帧 */
    IMOS_EN_FRAME_RATE_30F = 30,                                   /**< 30帧 */
    IMOS_EN_FRAME_RATE_COUNT
} HD_FRAME_RATE_EX_E;

/**
 * @enum tagMC_ConfMixRateEx
 * @brief 会议混速类型
 * @attention
 */
typedef  enum tagMC_ConfMixRateEx
{
    IMOS_EN_MIX_RATE_NO     = 0,    /**< 不支持混速 */
    IMOS_EN_MIX_RATE_PART   = 1,    /**< 部分混速 */
    IMOS_EN_MIX_RATE_ALL    = 2,    /**< 全混速 */
    IMOS_EN_MIX_RATE_CHOICE = 3,    /**< 选择混速 */
    IMOS_EN_MIX_RATE_COUNT
} MC_CONF_MIXRATE_EX_E;

/**
 * @enum tagHD_RateAndFrameAdaptModeEx
 * @brief 速率，帧率适配优先的枚举
 * @attention
 */
typedef  enum  tagHD_RateAndFrameAdaptModeEx
{
    IMOS_EN_RATE_FRAME_NO           = 0,    /**< 不进行速率 */
    IMOS_EN_RATE_FRAME_FALL         = 1,    /**< 降速 */
    IMOS_EN_RATE_FRAME_RATE_FIRST   = 2,    /**< 速率适配优先 */
    IMOS_EN_RATE_FRAME_FRAME_FIRST  = 3,    /**< 帧率适配优先 */
    IMOS_EN_RATE_FRAME_COUNT
} HD_RATE_AND_FRAME_ADAPT_MODE_EX_E;

/**
 * @enum tagMC_AdaptCountEx
 * @brief 适配路数枚举
 * @attention
 */
typedef  enum  tagMC_AdaptCountEx
{
    IMOS_EN_ADAPT_COUNT_1 = 1,            /**< 适配1路 */
    IMOS_EN_ADAPT_COUNT_2 = 2,            /**< 适配2路 */
    IMOS_EN_ADAPT_COUNT_3 = 3,            /**< 适配3路 */
    IMOS_EN_ADAPT_COUNT_COUNT
} MC_ADAPT_COUNT_EX_E;


/**
 * @enum tagMC_ConfTypeEx
 * @brief 会议创建时会议类型
 * @attention
 */
typedef  enum tagMC_ConfTypeEx
{
    IMOS_EN_CONF_TYPE_ONLY_AUDIO    = 0,    /**< 纯音频会议 */
    IMOS_EN_CONF_TYPE_AUDIVISION    = 1,    /**< 音视频会议 */
    IMOS_EN_CONF_TYPE_ANNEX_VIDEO   = 2,    /**< 双流视频会议 */
    IMOS_EN_CONF_TYPE_COUNT
} MC_CONF_TYPE_EX_E;


/**
 * @enum tagHD_RoleVideoTypeEx
 * @brief 辅流类型
 * @attention
 */
typedef  enum    tagHD_RoleVideoTypeEx
{
     IMOS_EN_HD_ROLE_LIVE           = 1,    /**< 自由模式 */
     IMOS_EN_HD_ROLE_TOKEN          = 2,    /**< 令牌模式 */
     IMOS_EN_HD_ROLE_LIVE_TOKEN     = 3,    /**< 同时支持自由和令牌模式 */
     IMOS_EN_HD_ROLE_NO_STANDARD    = 4,    /**< 非标模式 */
     IMOS_EN_HD_ROLE_COUNT                                        /**< 个数 */
} HD_ROLE_VIDEO_TYPE_EX_E;

/**
 * @enum tagMC_MediaEncryptEx
 * @brief 媒体加密类型
 * @attention
 */
typedef enum tagMC_MediaEncryptEx
{
    IMOS_EN_MEDIA_ENCRYPT_NO    = 0,    /**< 不支持媒体加密 */
    IMOS_EN_MEDIA_ENCRYPT_AES   = 1,    /**< AES加密 */
    IMOS_EN_MEDIA_ENCRYPT_DES   = 2,    /**< DES加密 */
    IMOS_EN_MEDIA_ENCRYPT_COUNT
} MC_MEDIA_ENCRYPT_EX_E;


/**
 * @enum tagMC_SignalTypeEx
 * @brief 媒体加密类型
 * @attention
 */
typedef  enum tagMC_SignalTypeEx
{
    IMOS_EN_SIGNAL_TYPE_NO      = 0,    /**< 不支持信令加密 */
    IMOS_EN_SIGNAL_TYPE_H235    = 1,    /**< H235加密 */
    IMOS_EN_SIGNAL_TYPE_COUNT
} MC_SIGNAL_TYPE_EX_E;

/**
 * @enum tagHD_IFrameNumEx
 * @brief 每次接收/发送I帧请求的发送I帧帧数
 * @attention
 */
typedef  enum  tagHD_IFrameNumEx
{
    IMOS_EN_IFRAME_NUM_1F = 1,                               /**< 1帧 */
    IMOS_EN_IFRAME_NUM_2F = 2,                               /**< 2帧 */
    IMOS_EN_IFRAME_NUM_3F = 3,                               /**< 3帧 */
    IMOS_EN_IFRAME_NUM_4F = 4,                               /**< 4帧 */
    IMOS_EN_IFRAME_NUM_5F = 5,                               /**< 5帧 */
    IMOS_EN_IFRAME_NUM_6F = 6,                               /**< 6帧 */
    IMOS_EN_IFRAME_NUM_7F = 7,                               /**< 7帧 */
    IMOS_EN_IFRAME_NUM_8F = 8,                               /**< 8帧 */
    IMOS_EN_IFRAME_NUM_9F = 9,                               /**< 9帧 */
    IMOS_EN_IFRAME_NUM_10F = 10,                             /**< 10帧 */
    IMOS_EN_IFRAME_NUM_20F = 20,                             /**< 20帧 */
    IMOS_EN_IFRAME_NUM_30F = 30,                             /**< 30帧 */
    IMOS_EN_IFRAME_NUM_40F = 40,                             /**< 40帧 */
    IMOS_EN_IFRAME_NUM_50F = 50,                             /**< 50帧 */
    IMOS_EN_IFRAME_NUM_60F = 60,                             /**< 60帧 */
    IMOS_EN_IFRAME_NUM_70F = 70,                             /**< 70帧 */
    IMOS_EN_IFRAME_NUM_80F = 80,                             /**< 80帧 */
    IMOS_EN_IFRAME_NUM_90F = 90,                             /**< 90帧 */
    IMOS_EN_IFRAME_NUM_120F = 120,                           /**< 120帧 */
    IMOS_EN_IFRAME_NUM_FRAME_COUNT
} HD_IFRAME_NUM_FRAME_EX_E;

/**
 * @enum tagHD_IFrameAutoEncIntervalEx
 * @brief 自动编码I帧的时间间隔
 * @attention
 */
typedef  enum  tagHD_IFrameAutoEncIntervalEx
{
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_20MS = 20,                    /**< 20ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_40MS = 40,                    /**< 40ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_60MS = 60,                    /**< 60ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_80MS = 80,                    /**< 80ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_120MS = 120,                  /**< 120ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_160MS = 160,                  /**< 160ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_200MS = 200,                  /**< 200ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_240MS = 240,                  /**< 240ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_300MS = 300,                  /**< 300ms */
    IMOS_HD_IFRAME_ATUO_ENC_INTERVAL_COUNT
} HD_IFRAME_ATUO_ENC_INTERVAL_EX_E;


/**
 * @enum tagHD_IFrameManualEncIntervalEx
 * @brief 自动编码I帧的时间间隔
 * @attention
 */
typedef  enum  tagHD_IFrameManualEncIntervalEx
{
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_1S = 1,                      /**< 1s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_2S = 2,                      /**< 2s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_3S = 3,                      /**< 3s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_4S = 4,                      /**< 4s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_5S = 5,                      /**< 5s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_6S = 6,                      /**< 6s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_7S = 7,                      /**< 7s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_8S = 8,                      /**< 8s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_9S = 9,                      /**< 9s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_10S = 10,                    /**< 10s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_20S = 20,                    /**< 20s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_30S = 30,                    /**< 30s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_40S = 40,                    /**< 40s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_50S = 50,                    /**< 50s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_60S = 60,                    /**< 60s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_70S = 70,                    /**< 70s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_80S = 80,                    /**< 80s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_90S = 90,                    /**< 90s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_120S = 120,                  /**< 120s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_180S = 180,                  /**< 180s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_300S = 300,                  /**< 300s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_600S = 600,                  /**< 600s */
    IMOS_EN_IFRAME_MANUAL_ENC_INTERVAL_COUNT
} HD_IFRAME_MANUAL_ENC_INTERVAL_EX_E;


/**
 * @enum tagHD_CameraPositionEx
 * @brief 摄像机旋转/倾斜方向
 * @attention
 */
typedef  enum  tagHD_CameraPositionEx
{
    IMOS_EN_POS_UP      = 0,    /**< 向上  */
    IMOS_EN_POS_DOWN    = 1,    /**< 向下  */
    IMOS_EN_POS_LEFT    = 2,    /**< 向左  */
    IMOS_EN_POS_RIGHT   = 3,    /**< 向右  */
    IMOS_EN_POS_RESET   = 4,    /**< 重置  */
    IMOS_EN_POS_STOP    = 5,    /**< 停止 */
    IMOS_EN_POS_COUNT
} HD_CAMERA_POSITION_EX_E;

/**
 * @enum tagHD_CameraZoomEx
 * @brief 图像缩放模式
 * @attention
 */
typedef  enum  tagHD_CameraZoomEx
{
    IMOS_EN_CAMERA_ZOOM_OUT     = 0,    /**< 缩小  */
    IMOS_EN_CAMERA_ZOOM_IN      = 1,    /**< 放大  */
    IMOS_EN_CAMERA_ZOOM_STOP    = 2,    /**< 停止 */
    IMOS_EN_CAMERA_ZOOM_COUNT
} HD_CAMERA_ZOOM_EX_E;

/**
 * @enum tagHD_CameraFocusEx
 * @brief 聚焦模式
 * @attention
 */
typedef enum tagHD_CameraFocusEx
{
    IMOS_EN_CAMERA_FOCUS_AUTO   = 0,    /**< 自动 */
    IMOS_EN_CAMERA_FOCUS_MANUAL = 1,    /**< 手动 */
    IMOS_EN_CAMERA_FOCUS_COUNT
} HD_CAMERA_FOCUS_EX_E;


/**
 * @enum tagMC_SiteStatusEx
 * @brief 会场状态
 * @attention
 */
typedef  enum tagMC_SiteStatusEx
{
    IMOS_EN_SITE_OFF_LINE       = 0,    /**< 会场不在线 */
    IMOS_EN_SITE_CALLING_IN     = 1,    /**< 正在被MCU呼叫 */
    IMOS_EN_SITE_CALLING_OUT    = 2,    /**< 正在呼叫MCU */
    IMOS_EN_SITE_IN_CONF        = 3,    /**< 已经在会议中 */
    IMOS_EN_SITE_DROPING        = 4,    /**< 正在挂断会场 */
    IMOS_EN_SITE_DROPED         = 5,    /**< 会场已经退出会议 */
    IMOS_EN_SITE_UNKNOW         = 6,    /**< 会场状态未知 */
    IMOS_EN_SITE_DELETING       = 7,    /**< 正在被删除 */
    IMOS_EN_SITE_DISABLE        = 8,    /**< 会场不可用，级联情况下使用 */
    IMOS_EN_SITE_STATUS_COUNT
} MC_SITE_STATUS_EX_E;

/**
 * @enum tagHD_CapTypeEx
 * @brief 能力集中的能力类型
 * @attention
 */
typedef  enum    tagHD_CapTypeEx
{
     IMOS_EN_HD_CAP_AUDIO   = 0,    /**< 音频能力 */
     IMOS_EN_HD_CAP_VIDEO   = 1,    /**< 视频能力 */
     IMOS_EN_HD_CAP_ANNEX   = 2,    /**< 辅流能力 */
     IMOS_EN_HD_CAP_DATA    = 3,    /**< 数据能力 */
     IMOS_EN_HD_CAP_CTRL    = 4,    /**< 控制能力 */
     IMOS_EN_HD_CAP_COUNT           /**< 个数 */
} HD_CAP_TYPE_EX_E;

/**
 * @enum tagHD_DataProtEx
 * @brief 数据协议类型
 * @attention
 */
typedef  enum  tagHD_DataProtEx
{
    IMOS_EN_DATA_PROT_H224 = 0,                                    /**< H224协议 */
    IMOS_EN_DATA_PROT_COUNT
} HD_DATA_PROT_EX_E;

/**
 * @enum tagHD_ControlProtEx
 * @brief 控制协议类型
 * @attention
 */
typedef  enum  tagHD_ControlProtEx
{
    IMOS_EN_CTRL_PROT_H239 = 0,                                   /**< H239协议 */
    IMOS_EN_CTRL_PROT_LPR  = 1,                                   /**< 非标LPR */
    IMOS_EN_CTRL_PROT_COUNT
} HD_CTRL_PROT_EX_E;

/**
 * @enum tagHD_SysTimeZoneEx
 * @brief 时区
 * @attention
 */
typedef enum tagHD_SysTimeZoneEx
{
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_12 = 0,    /**< (GMT-12:00)日界线西*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_11 = 1,    /**< (GMT-11:00)中途岛*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_10 = 2,    /**< (GMT-10:00)夏威夷*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_9  = 3,    /**< (GMT-09:00)阿拉斯加*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_8  = 4,    /**< (GMT-08:00)太平洋时间*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_7  = 5,    /**< (GMT-07:00)山地时间*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_6  = 6,    /**< (GMT-06:00)中部时间*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_5  = 7,    /**< (GMT-05:00)东部时间*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_4  = 8,    /**< (GMT-04:00)大西洋时间*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_3  = 9,    /**< (GMT-03:00)格陵兰*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_2  = 10,   /**< (GMT-02:00)中大西洋*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_1  = 11,   /**< (GMT-01:00)佛得角群岛*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT    = 12,   /**< (GMT)格林威治标准时间*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT1   = 13,   /**< (GMT+01:00)柏林，罗马*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT2   = 14,   /**< (GMT+02:00)开罗，雅典*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT3   = 15,   /**< (GMT+03:00)莫斯科，巴格达*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT4   = 16,   /**< (GMT+04:00)巴库，埃里温*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT5   = 17,   /**< (GMT+05:00)伊斯兰堡*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT6   = 18,   /**< (GMT+06:00)阿拉木图*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT7   = 19,   /**< (GMT+07:00)曼谷，河内*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT8   = 20,   /**< (GMT+08:00)北京，重庆 */
    IMOS_EN_HD_SYS_TIME_ZONE_GMT9   = 21,   /**< (GMT+09:00)东京，首尔*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT10  = 22,   /**< (GMT+10:00)堪培拉，墨尔本*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT11  = 23,   /**< (GMT+11:00)所罗门群岛*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT12  = 24,   /**< (GMT+12:00)奥克兰，惠灵顿*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT13  = 25,   /**< (GMT+13:00)努库阿洛法*/
    IMOS_EN_HD_SYS_TIME_ZONE_COUNT
} HD_SYS_TIMEZONE_EX_E;

/**
 * @enum tagHD_SysLanguageEx
 * @brief 系统语言类型
 * @attention
 */
typedef enum tagHD_SysLanguageEx
{
    IMOS_EN_LANGUAGE_SIMPLE_CHINESE         = 0,    /**< 简体中文 */
    IMOS_EN_LANGUAGE_TRADITIONAL_CHINESE    = 1,    /**< 繁体中文 */
    IMOS_EN_LANGUAGE_ENGLISH                = 2,    /**< 英文 */
    IMOS_EN_LANGUAGE_COUNT
} HD_SYS_LANGUAGE_EX_E;

/**
 * @enum tagHD_NetCardDuplexTypeEx
 * @brief 网卡双工模式
 * @attention
 */
typedef  enum  tagHD_NetCardDuplexTypeEx
{
    IMOS_EN_FULLDUPLEX          = 0,    /**< 全双工 */
    IMOS_EN_SEMIDUPLEX          = 1,    /**< 半双工 */
    IMOS_EN_DUPLEX_NEGOTIATE    = 2,    /**< 自协商 */
    IMOS_EN_KEEP_DUPLEX_CFG     = 255   /**< 保持原有配置 */
} HD_NETCARD_DUPLEX_TYPE_EX_E;

/**
 * @enum tagHD_NetCardRateEx
 * @brief 网卡支持速率
 * @attention
 */
typedef  enum  tagHD_NetCardRateEx
{
    IMOS_EN_CARD_RATE10M        = 0,    /**< 10M */
    IMOS_EN_CARD_RATE100M       = 1,    /**< 100M */
    IMOS_EN_CARD_RATE1000M      = 2,    /**< 1000M */
    IMOS_EN_CARD_RATE_NEGOTIATE = 3,    /**< 自协商 */
    IMOS_EN_KEEP_CARD_RATE_CFG  = 255   /**< 保持原有配置 */
} HD_NETCARD_RATE_EX_E;

/**
 * @enum tagHD_BoardTypeEx
 * @brief 设备类型
 * @attention
 */
typedef  enum tagHD_BoardTypeEx
{
    IMOS_EN_BOARD_MMC   = 0,    /**< 主控MC处理板 */
    IMOS_EN_BOARD_BMC   = 1,    /**< 备份MC处理板 */
    IMOS_EN_BOARD_LAN   = 2,    /**< 接口处理板 */
    IMOS_EN_BOARD_AUX   = 3,    /**< 音频处理板 */
    IMOS_EN_BOARD_VP    = 4,    /**< 视频处理板 */
    IMOS_EN_BOARD_TYPE_COUNT
} HD_BOARD_TYPE_EX_E;

/**
 * @enum tagHD_FanStateEx
 * @brief 风扇状态
 * @attention
 */
typedef enum tagHD_FanStateEx
{
    IMOS_EN_FAN_STATE_ABSENT            = -1,   /**< 不在位 */
    IMOS_EN_FAN_STATE_NORMAL            = 0,    /**< 正常 */
    IMOS_EN_FAN_STATE_SPEED_ABNORMAL    = 1,    /**< 转速异常 */
    IMOS_EN_FAN_STATE_BLOCKED           = 2,    /**< 风扇阻塞 */
    IMOS_EN_FAN_STATE_OUT_OF_CONTROL    = 3     /**< 失去控制--掉电 */
} HD_FAN_STATE_EX_E;

/**
 * @enum tagHD_DspStatusEnEx
 * @brief DSP状态，标识DSP是否可用
 * @attention
 */
typedef  enum  tagHD_DspStatusEnEx
{
    IMOS_EN_DSP_STAT_IDLE   = 0,    /**< 空闲状态  */
    IMOS_EN_DSP_STAT_USED   = 1,    /**< DSP已使用用  */
    IMOS_EN_DSP_STAT_ERROR  = 2,    /**< DSP坏掉  */
    IMOS_EN_DSP_STAT_COUNT
} HD_DSP_STATUS_EX_E;

/**
 * @enum tagHD_ComBitRateEx
 * @brief 串口传输波特率
 * @attention
 */
typedef  enum tagHD_ComBitRateEx
{
    IMOS_EN_COM_RATE_100BPS = 100,                                /**< 100kbps */
    IMOS_EN_COM_RATE_300BPS = 300,                                /**< 300kbps */
    IMOS_EN_COM_RATE_1200BPS = 1200,                              /**< 1200kbps */
    IMOS_EN_COM_RATE_2400BPS = 2400,                              /**< 2400kbps */
    IMOS_EN_COM_RATE_4800BPS = 4800,                              /**< 4800kbps */
    IMOS_EN_COM_RATE_9600BPS = 9600,                              /**< 960kbps */
    IMOS_EN_COM_RATE_19200BPS = 19200,                            /**< 19200kbps */
    IMOS_EN_COM_RATE_38400BPS = 38400,                            /**< 39400kbps */
    IMOS_EN_COM_RATE_57600BPS = 57600,                            /**< 57600kbps */
    IMOS_EN_COM_RATE_115200BPS = 115200,                          /**< 115200kbps */
    IMOS_EN_COM_RATE_230400BPS = 230400,                          /**< 230400kbps */
    IMOS_EN_COM_RATE_460800BPS = 460800,                          /**< 460800kbps */
    IMOS_EN_COM_RATE_921600BPS = 921600,                          /**< 921600kbps */
    IMOS_EN_COM_RATE_COUNT
} HD_COM_BIT_RATE_EX_E;

/**
 * @enum tagMC_TermTypeEx
 * @brief 终端音视频使用类型
 * @attention
 */
typedef  enum tagMC_TermTypeEx
{
    IMOS_EN_TERM_AUDIO                      = 0,    /**< 纯音频终端 */
    IMOS_EN_TERM_AUDIO_VIDEO                = 1,    /**< 音视频终端 */
    IMOS_EN_TERM_SECOND_AUDIO_VIDEO         = 2,    /**< 辅流视频终端 */
    IMOS_EN_TERN_VIRTUAL_SEND_VIDEO_ONLY    = 3,    /**< 只发视频的虚拟终端 */
    IMOS_EN_TERN_VIRTUAL_RECV_VIDEO_ONLY    = 4,    /**< 只接收视频的虚拟终端 */
    IMOS_EN_TERM_TYPE_COUNT
} MC_TERM_TYPE_EX_E;

/**
 * @enum tagMC_CallTermTypeEx
 * @brief 级联会议时当前终端呼叫类型
 * @attention
 */
typedef enum tagMC_CallTermTypeEx
{
    IMOS_EN_CALL_TERM_TYPE_TERM = 0,    /**< 呼叫的终端类型为端点 */
    IMOS_EN_CALL_TERM_TYPE_MCU  = 1,    /**< 呼叫的终端类型为MCU */
    IMOS_EN_CALL_TERM_TYPE_COUNT
}MC_CALL_TERM_TYPE_EX_E;

/**
 * @enum tagHD_ChnDirectionEx
 * @brief 通道方向
 * @attention
 */
typedef  enum  tagHD_ChnDirectionEx
{
    IMOS_EN_CHN_IN  = 0,    /**< 输入通道 */
    IMOS_EN_CHN_OUT = 1,    /**< 输出通道 */
    IMOS_EN_DIRECT_COUNT
} HD_CHN_DIRECTION_EX_E;

/**
 * @enum tagMC_ConfTurnBroadcastModeEx
 * @brief 主场轮巡、广播轮巡模式
 * @attention
 */
typedef  enum tagMC_ConfTurnBroadcastModeEx
{
    IMOS_EN_TURN_MAIN_SITE = 0,     /**< 主场轮巡 */
    IMOS_EN_TURN_BROADCAST = 1,     /**< 广播轮巡 */
    IMOS_EN_TURN_COUNT
} MC_CONF_TURN_BROADCAST_MODE_EX_E;

/**
 * @enum tagMC_GKTypeEx
 * @brief GK的类型
 * @attention
 */
typedef    enum    tagMC_GKTypeEx
{
    IMOS_EN_INNER_GK    = 0,    /**< 内置GK */
    IMOS_EN_EXTER_GK    = 1,    /**< 外置GK */
    IMOS_EN_NO_GK       = 2,    /**< 不使用GK */
    IMOS_EN_GK_TYPE_COUNT,
} MC_GK_TYPE_EX_E;

/**
 * @enum tagMC_NtpTimeSynchIntervalEx
 * @brief NTP时间同步间隔
 * @attention
 */
typedef  enum tagMC_NtpTimeSynchIntervalEx
{
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_10MIN = 10 * 60,                  /**< 10分钟 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_15MIN = 15 * 60,                  /**< 15分钟 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_30MIN = 30 * 60,                  /**< 30分钟 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_1HOUR = 60 * 60,                  /**< 1小时 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_2HOUR = 2 * 60 * 60,              /**< 2小时 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_12HOUR = 12 * 60 * 60,            /**< 12小时 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_24HOUR = 24 * 60 * 60,            /**< 24小时 */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_COUNT
} MC_NTP_TIME_SYNCH_INTERVAL_EX_E;

#if 0
#endif

/*******************************************************************************
SS 终端设备使用的枚举
*******************************************************************************/

/**
 * @enum tagHD_AudioVolumeEx
 * @brief 音量
 * @attention
 */
typedef  enum    tagHD_AudioVolumeEx
{
    IMOS_EN_AUDIO_VOLUME1   = 1,    /**< 1 */
    IMOS_EN_AUDIO_VOLUME2   = 2,    /**< 2 */
    IMOS_EN_AUDIO_VOLUME3   = 3,    /**< 3 */
    IMOS_EN_AUDIO_VOLUME4   = 4,    /**< 4 */
    IMOS_EN_AUDIO_VOLUME5   = 5,    /**< 5 */
    IMOS_EN_AUDIO_VOLUME6   = 6,    /**< 6 */
    IMOS_EN_AUDIO_VOLUME7   = 7,    /**< 7 */
    IMOS_EN_AUDIO_VOLUME_COUNT
} HD_AUDIO_VOLUME_EX_E;

/**
 * @enum tagHD_RingTypeEx
 * @brief 铃声类别
 * @attention
 */
typedef enum tagHD_RingTypeEx
{
    IMOS_EN_RING_TYPE_BOOT_CALL1            = 0,    /**< 开机铃声1 */
    IMOS_EN_RING_TYPE_BOOT_CALL2            = 1,    /**< 开机铃声2 */
    IMOS_EN_RING_TYPE_BOOT_CALL3            = 2,    /**< 开机铃声3 */
    IMOS_EN_RING_TYPE_BOOT_CALL4            = 3,    /**< 开机铃声4 */
    IMOS_EN_RING_TYPE_BOOT_CALL5            = 4,    /**< 开机铃声5 */
    IMOS_EN_RING_TYPE_BOOT_DEFAULT          = 5,    /**< 默认的开机铃声 */
    IMOS_EN_RING_TYPE_BOOT_FASHION          = 6,    /**< 时尚的开机铃声 */
    IMOS_EN_RING_TYPE_BOOT_GRACE            = 7,    /**< 轻快优雅的开机铃声 */
    IMOS_EN_RING_TYPE_INCOMING_CALL1        = 8,    /**< 来电铃声1 */
    IMOS_EN_RING_TYPE_INCOMING_CALL2        = 9,    /**< 来电铃声2 */
    IMOS_EN_RING_TYPE_INCOMING_CALL3        = 10,   /**< 来电铃声3 */
    IMOS_EN_RING_TYPE_INCOMING_CALL4        = 11,   /**< 来电铃声4 */
    IMOS_EN_RING_TYPE_INCOMING_CALL5        = 12,   /**< 来电铃声5 */
    IMOS_EN_RING_TYPE_INCOMING_CALL_DEFAULT = 13,   /**< 默认的来电铃声 */
    IMOS_EN_RING_TYPE_INCOMING_CALL_FASHION = 14,   /**< 时尚的来电铃声 */
    IMOS_EN_RING_TYPE_INCOMING_CALL_GRACE   = 15,   /**< 轻快优雅的来电铃声 */
    IMOS_EN_RING_TYPE_CUSTOM1               = 16,   /**< 自定义铃声1，开机和来电铃声均可选择 */
    IMOS_EN_RING_TYPE_CUSTOM2               = 17,   /**< 自定义铃声2，开机和来电铃声均可选择 */
    IMOS_EN_RING_TYPE_CUSTOM3               = 18,   /**< 自定义铃声3，开机和来电铃声均可选择 */
    IMOS_EN_RING_TYPE_CUSTOM4               = 19,   /**< 自定义铃声4，开机和来电铃声均可选择 */
    IMOS_EN_RING_TYPE_CUSTOM5               = 20,   /**< 自定义铃声5，开机和来电铃声均可选择 */
    IMOS_EN_RING_TYPE_COUNT                         /**< 个数 */
}HD_RING_TYPE_EX_E;


/**
 * @enum tagHD_NIC_NumberEx
 * @brief 网口号
 * @attention
 */
typedef  enum  tagHD_NIC_NumberEx
{
    IMOS_EN_HD_NIC_INVALID = -1,
    IMOS_EN_HD_NIC_0 = 0,                                          /**< 网口0 值不可改变(用作数组下标, 含传给驱动的值不作转换直接用此) */
    IMOS_EN_HD_NIC_1 = 1,                                          /**< 网口1 值不可改变(用作数组下标) */
    IMOS_EN_HD_NIC_COUNT
}HD_NIC_NUMBER_EX_E;

/**
 * @enum tagHD_Framerate_TypeEx
 * @brief 视频帧率类型
 * @attention
 */
typedef enum tagHD_Framerate_TypeEx
{
    IMOS_EN_AUTO_FRAMERATE      = 0,    /**< 自动 */
    IMOS_EN_CLEAR_FRAMERATE     = 1,    /**< 清晰 */
    IMOS_EN_FLUENT_FRAMERATE    = 2,    /**< 流畅 */
    IMOS_EN_FRAMERATE_TYPE_COUNT,
}HD_FRAMERATE_TYPE_EX_E;


/**
 * @enum tagHD_VideoInPortEx
 * @brief 视频输入端口
 * @attention
 */
typedef enum tagHD_VideoInPortEx
{
    IMOS_EN_VIDEO_IN_PORT_DVI_I1    = 0,    /**< DVI1  */
    IMOS_EN_VIDEO_IN_PORT_S1        = 1,    /**< DVI1-S1 */
    IMOS_EN_VIDEO_IN_PORT_DVI_I2    = 2,    /**< DVI2  */
    IMOS_EN_VIDEO_IN_PORT_S2        = 3,    /**< DVI2-S2  */
    IMOS_EN_VIDEO_IN_PORT_DVI_I3    = 4,    /**< DVI3  */
    IMOS_EN_VIDEO_IN_PORT_SDI1      = 5,    /**< SDI1 */
    IMOS_EN_VIDEO_IN_PORT_SDI2      = 6,    /**< SDI2  */
    IMOS_EN_VIDEO_IN_PORT_COUNT             /**< 个数 */
} HD_VIDEO_IN_PORT_EX_E;


/**
 * @enum tagHD_AECTypeEx
 * @brief MIC 和 RCA 回声抵消级别
 * @attention
 */
typedef enum tagHD_AECTypeEx
{
    IMOS_EN_AEC_TYPE_STRONG = 0,    /**< 强 */
    IMOS_EN_AEC_TYPE_WEAK   = 1,    /**< 弱 */
    IMOS_EN_AEC_TYPE_NONE   = 2,    /**< 无 */
    IMOS_EN_AEC_TYPE_COUNT          /**< 个数 */
}HD_AEC_TYPE_EX_E;


/**
 * @enum tagHD_TNAAType
 * @brief 网络纠错类型
 * @attention
 */
typedef enum tagHD_TNAAType
{
    IMOS_NAA_TYPE_SHORT_DELAY   = 0,    /** 低网络延时*/
    IMOS_NAA_TYPE_MID_DELAY     = 1,    /** 中等网络延时*/
    IMOS_NAA_TYPE_LONG_DELAY    = 2,    /** 高网络延时*/
    IMOS_NAA_TYPE_DELAY_COUNT
}HD_TNAA_TYPE_EX_E;


/**
 * @enum tagHD_DebugLevelEx
 * @brief 调试级别
 * @attention
 */
typedef  enum  tagHD_DebugLevelEx
{
    IMOS_EN_HD_DEBUG    = 0,    /**< Debug级调试信息,包括所有调试信息 */
    IMOS_EN_HD_INFO     = 1,    /**< Info级调试信息,包括警告级调试信息 */
    IMOS_EN_HD_WARNING  = 2,    /**< 警告级调试信息,包括错误级调试信息 */
    IMOS_EN_HD_ERROR    = 3,    /**< 错误级调试信息,包括致命错误调试信息 */
    IMOS_EN_HD_FATAL    = 4,    /**< 致命错误级调试信息 */
    IMOS_EN_HD_NO       = 5,    /**< 不输出调试信息 */
    IMOS_EN_HD_DEBUG_LEVEL_COUNT    /**< 此枚举类型的个数 */
} HD_DEBUG_LEVEL_EX_E;


/**
 * @enum tagHD_LogoTypeEx
 * @brief 使用Logo 类型
 * @attention
 */
typedef enum tagHD_LogoTypeEx
{
    IMOS_EN_LOGO_DEFAULT    = 0,    /**< 默认LOGO */
    IMOS_EN_LOGO_TYPE1      = 1,    /**< 导入的类型1 */
    IMOS_EN_LOGO_TYPE2      = 2,    /**< 导入的类型2 */
    IMOS_EN_LOGO_TYPE3      = 3,    /**< 导入的类型3 */
    IMOS_EN_LOGO_TYPE4      = 4,    /**< 导入的类型4 */
    IMOS_EN_LOGO_TYPE5      = 5,    /**< 导入的类型5 */
    IMOS_EN_LOGO_TYPE6      = 6,    /**< 导入的类型6 */
    IMOS_EN_LOGO_TYPE7      = 7,    /**< 导入的类型7 */
    IMOS_EN_LOGO_TYPE8      = 8,    /**< 导入的类型8 */
    IMOS_EN_LOGO_TYPE9      = 9,    /**< 导入的类型9 */
    IMOS_EN_LOGO_TYPE10     = 10,   /**< 导入的类型10 */
    IMOS_EN_LOGO_COUNT              /**< 个数 */
}HD_LOGO_TYPE_EX_E;


/**
 * @enum tagHD_QosTypeEx
 * @brief QOS服务类别：IP Precedence，Diffserv
 * @attention
 */
typedef  enum  tagHD_QosTypeEx
{
    IMOS_EN_IP_PRECEDENCE = 0,                                   /**< IP 优先级别 */
    IMOS_EN_DIFF_SERV     = 1,                                   /**< Diffserv */
    IMOS_EN_SERVER_COUNT
} HD_QOS_TYPE_EX_E;


/**
 * @enum tagHD_UserTypeEx
 * @brief 用户类型
 * @attention
 */
typedef enum tagHD_UserTypeEx
{
    IMOS_EN_USER_TYPE_TERMINAL_ADMIN    = 0,    /**< 终端管理员 */
    IMOS_EN_USER_TYPE_WEB_ADMIN         = 1,    /**< WEB管理员  */
    IMOS_EN_USER_TYPE_PC_ADMIN          = 2,    /**< 控制台管理员 */
    IMOS_EN_USER_TYPE_COUNT                     /**< 个数 */
}HD_USER_TYPE_EX_E;


/**
 * @enum tagHD_PwdEncTypeEx
 * @brief 密码加密方法
 * @attention
 */
typedef enum tagHD_PwdEncTypeEx
{
    IMOS_EN_PWD_ENC_NONE    = 0,    /**< 不加密，明文 */
    IMOS_EN_PWD_ENC_MD5     = 1,    /**< MD5加密  */
    IMOS_EN_PWD_ENC_DES     = 2,    /**< DES加密 */
    IMOS_EN_PWD_ENC_TYPE_COUNT
}HD_PWD_ENC_TYPE_EX_E;


/**
 * @enum tagHD_ConnectTypeEx
 * @brief 网络连接方式
 * @attention
 */
typedef enum tagHD_ConnectTypeEx
{
    IMOS_EN_CONNECT_TYPE_FIXEDIP    = 0,    /**< 固定IP */
    IMOS_EN_CONNECT_TYPE_PPPOE      = 1,    /**< PPPoE方式 */
    IMOS_EN_CONNECT_TYPE_DHCP       = 2,    /**< 自动获得IP */
    IMOS_EN_CONNECT_TYPE_COUNT              /**< 个数 */
}HD_CONNECT_TYPE_EX_E;


/**
 * @enum tagHD_BitRateEx
 * @brief 速率
 * @attention
 */
typedef  enum tagHD_BitRateEx
{
    IMOS_EN_BIT_RATE_AUTO = 0,                      /**< 自动 */
    IMOS_EN_BIT_RATE_64K  = 64 * 1000,              /**< 64kbps[64K] */
    IMOS_EN_BIT_RATE_128K = 128 * 1000,             /**< 128kbps[128K] */
    IMOS_EN_BIT_RATE_256K = 256 * 1000,             /**< 256kbps[256K] */
    IMOS_EN_BIT_RATE_320K = 320 * 1000,             /**< 320kbps[320K] */
    IMOS_EN_BIT_RATE_384K = 384 * 1000,             /**< 384kbps[384K] */
    IMOS_EN_BIT_RATE_512K = 512 * 1000,             /**< 512kbps[512K] */
    IMOS_EN_BIT_RATE_640K = 640 * 1000,             /**< 640kbps[640K] */
    IMOS_EN_BIT_RATE_768K = 768 * 1000,             /**< 768kbps[768K] */
    IMOS_EN_BIT_RATE_1M = 1024 * 1000,              /**< 1Mbps[1024K] */
    IMOS_EN_BIT_RATE_1280K = 1280 * 1000,           /**< 1280Kbps[1280K] */
    IMOS_EN_BIT_RATE_1536K = 1536 * 1000,           /**< 1536Kbps[1536K] */
    IMOS_EN_BIT_RATE_1920K = 1920 * 1000,           /**< 1920Kbps[1920K] */
    IMOS_EN_BIT_RATE_2M = 2 * 1024 * 1000,          /**< 2Mbps[2048K] */
    IMOS_EN_BIT_RATE_2560K = 2560 * 1000,           /**< 2560Kbps[2560K] */
    IMOS_EN_BIT_RATE_3M = 3 * 1024 * 1000,          /**< 3Mbps[3072K] */
    IMOS_EN_BIT_RATE_3584K = 3584 * 1000,           /**< 3584Kbps[3584K] */
    IMOS_EN_BIT_RATE_4M = 4 * 1024 * 1000,          /**< 4Mbps[4096K] */
    IMOS_EN_BIT_RATE_4608K = 4608 * 1000,           /**< 4608Kbps[4608K] */
    IMOS_EN_BIT_RATE_5M = 5 * 1024 * 1000,          /**< 5Mbps[5120K] */
    IMOS_EN_BIT_RATE_5632K = 5632 * 1000,           /**< 5632Kbps[5632K] */
    IMOS_EN_BIT_RATE_6M = 6 * 1024 * 1000,          /**< 6Mbps[6144K] */
    IMOS_EN_BIT_RATE_6656K = 6656 * 1000,           /**< 6656Kbps[6656K] */
    IMOS_EN_BIT_RATE_7M = 7 * 1024 * 1000,          /**< 7Mbps[7168K] */
    IMOS_EN_BIT_RATE_7680K = 7680 * 1000,           /**< 7680Kbps[7680K] */
    IMOS_EN_BIT_RATE_8M = 8 * 1024 * 1000,          /**< 8Mbps[8192K] */
    IMOS_EN_BIT_RATE_12M = 12 * 1024 * 1000,        /**< 12Mbps[12288K] */
    IMOS_EN_BIT_RATE_16M = 16 * 1024 * 1000,        /**< 16Mbps[16384K] */
    IMOS_EN_BIT_RATE_32M = 32 * 1024 * 1000,        /**< 32Mbps[32768K] */
    IMOS_EN_BIT_RATE_COUNT
} HD_BITRATE_EX_E;



/**
 * @enum tagHD_NetCardSetTypeEx
 * @brief 网卡设置方式
 * @attention
 */
typedef  enum  tagHD_NetCardSetTypeEx
{
    IMOS_EN_CARD_SET_BY_MANUAL  = 0,    /**< 手动设置网卡 */
    IMOS_EN_CARD_SET_BY_AUTO    = 1,    /**< 自协商 */
    IMOS_EN_CARD_SET_COUNT,
} HD_NETCARD_SET_TYPE_EX_E;


/**
 * @enum tagHD_VideoOutPortEx
 * @brief 视频输出端口
 * @attention
 */
typedef enum tagHD_VideoOutPortEx
{
    IMOS_EN_VIDEO_OUT_PORT_DVI_I1   = 0,        /**< DVI1  */
    IMOS_EN_VIDEO_OUT_PORT_S1       = 1,        /**< DVI1-S1  */
    IMOS_EN_VIDEO_OUT_PORT_DVI_I2   = 2,        /**< DVI2  */
    IMOS_EN_VIDEO_OUT_PORT_S2       = 3,        /**< DVI2-S2  */
    IMOS_EN_VIDEO_OUT_PORT_DVI_I3   = 4,        /**< DVI3  */
    IMOS_EN_VIDEO_OUT_PORT_S3       = 5,        /**< DVI3-S3  */
    IMOS_EN_VIDEO_OUT_PORT_COUNT                /**< 个数 */
} HD_VIDEO_OUT_PORT_EX_E;

/**
 * @enum tagHD_VideoOutContentTypeEx
 * @brief 输出内容
 * @attention
 */
typedef enum tagHD_VideoOutContentTypeEx
{
    IMOS_EN_VIDEO_OUT_CONTENT_WITH_GUI      = 0,    /**< 带GUI图象内容   */
    IMOS_EN_VIDEO_OUT_CONTENT_LOCAL_MAIN    = 1,    /**< 本地主流 */
    IMOS_EN_VIDEO_OUT_CONTENT_LOCAL_ROLE    = 2,    /**< 本地辅流 */
    IMOS_EN_VIDEO_OUT_CONTENT_REMOTE_MAIN   = 3,    /**< 远端主流 */
    IMOS_EN_VIDEO_OUT_CONTENT_REMOTE_ROLE   = 4,    /**< 远端辅流  */
    IMOS_EN_VIDEO_OUT_CONTENT_WITH_FIRST    = 5,    /**< 与第一路相同  */
    IMOS_EN_VIDEO_OUT_CONTENT_COUNT                 /**< 个数 */
} HD_VIDEO_OUT_CONTENT_TYPE_EX_E;


/**
 * @enum tagHD_Audio_In_Port_Sub_TypeEx
 * @brief 音频输入端口的具体类型
 * @attention
 */
typedef enum tagHD_Audio_In_Port_Sub_TypeEx
{
    IMOS_EN_AUDIO_IN_PORT_SUB_TYPE_CLEARONEMIC  = 0,    /**< clearone MIC */
    IMOS_EN_AUDIO_IN_PORT_SUB_TYPE_OTHERS       = 1,    /**< 其它 */
    IMOS_EN_AUDIO_IN_PORT_SUB_TYPE_COUNT                /**< 个数 */
} HD_AUDIO_IN_PORT_SUB_TYPE_EX_E;


/**
 * @enum tagHD_Record_Storage_TypeEx
 * @brief 录音存储类型
 * @attention
 */
typedef enum tagHD_Record_Storage_TypeEx
{
   IMOS_EN_HD_RECORD_2PORT  = 0,    /**< 录音经接口输出 */
   IMOS_EN_HD_RECORD_2USB   = 1,    /**< 录音存储至U盘 */
   IMOS_EN_HD_RECORD_2DISK  = 2,    /**< 录音存储至硬盘*/
   IMOS_EN_HD_RECORD_STORAGE_COUNT
} HD_RECORD_STORAGE_TYPE_EX_E;


/**
 * @enum tagHD_AudioOutPortEx
 * @brief 音频输出口
 * @attention
 */
typedef enum tagHD_AudioOutPortEx
{
    IMOS_EN_AUDIO_OUT_PORT_PHOENIX1 = 0,    /**< 凤凰口 */
    IMOS_EN_AUDIO_OUT_PORT_RCA1     = 1,    /**< RCA1 */
    IMOS_EN_AUDIO_OUT_PORT_DVI_I1   = 2,    /**< DVI1 */
    IMOS_EN_AUDIO_OUT_PORT_DVI_I2   = 3,    /**< DVI2 */
    IMOS_EN_AUDIO_OUT_PORT_DVI_I3   = 4,    /**< DVI3 */
    IMOS_EN_AUDIO_OUT_PORT_COUNT             /**< 音频输出端口数目 */
} HD_AUDIO_OUT_PORT_EX_E;


/**
 * @enum tagHD_AudioInPortEx
 * @brief 音频输入接口
 * @attention
 */
typedef  enum    tagHD_AudioInPortEx
{
    IMOS_EN_AUDIO_IN_PORT_MIC1      = 0,
    IMOS_EN_AUDIO_IN_PORT_MIC2      = 1,
    IMOS_EN_AUDIO_IN_PORT_PHOENIX1  = 2,
    IMOS_EN_AUDIO_IN_PORT_RCA1      = 3,
    IMOS_EN_AUDIO_IN_PORT_RCA2      = 4,
    IMOS_EN_AUDIO_IN_PORT_DVI_I1    = 5,
    IMOS_EN_AUDIO_IN_PORT_DVI_I2    = 6,
    IMOS_EN_AUDIO_IN_PORT_DVI_I3    = 7,
    IMOS_EN_AUDIO_IN_PORT_COUNT
} HD_AUDIO_IN_PORT_EX_E;


/**
 * @enum tagHD_ShowSiteNameEx
 * @brief 显示会场名模式,当设置为显示会议预设的会场名却
 *        没有预设该会场的会场名时显示会场自带的会场名。
 * @attention
 */
typedef  enum tagHD_ShowSiteNameEx
{
    IMOS_EN_SHOW_SITE_OWNER = 0,                                   /**< 显示会场自带的会场名 */
    IMOS_EN_SHOW_SET_NAME   = 1,                                   /**< 显示预设的会场名 */
    IMOS_EN_SHOW_NO         = 2,                                   /**< 不显示会场名 */
    IMOS_EN_SHOW_SITE_COUNT
} HD_CONF_SHOW_SITE_NAME_EX_E;

/**
 * @enum tagHD_FontEx
 * @brief 会场名称字体、字幕字体、横幅字体
 * @attention
 */
typedef  enum tagHD_FontEx
{
     IMOS_EN_FONT_HEITI = 0,                                       /**< 黑体 */
     IMOS_EN_FONT_YOUYUAN = 1,                                     /**< 幼圆 */
     IMOS_EN_FONT_COUNT
} HD_FONT_EX_E;


/**
 * @enum tagHD_FontSizeEx
 * @brief 会场名称字体大小、字幕字体大小、横幅字体大小
 * @attention
 */
typedef  enum tagHD_FontSizeEx
{
     IMOS_EN_FONT_SMALL = 0,                                       /**< 小字体 */
     IMOS_EN_FONT_MIDDLE = 1,                                      /**< 中字体 [正常字体] */
     IMOS_EN_FONT_LARGE = 2,                                       /**< 大字体 [大字体] */
     IMOS_EN_FONT_SIZE_COUNT
} HD_FONT_SIZE_EX_E;


/**
 * @enum tagHD_SiteNameTimerPosEx
 * @brief 会场名称、会议时间显示的位置
 * @attention
 */
typedef  enum tagHD_SiteNameTimerPosEx
{
    IMOS_EN_SITE_NAME_TIMER_POS_RIGHT_TOP       = 0,    /**< 会场名称、时间在右上部[右上] */
    IMOS_EN_SITE_NAME_TIMER_POS_RIGHT_BOTTOM    = 1,    /**< 会场名称、时间在右下部[右下] */
    IMOS_EN_SITE_NAME_TIMER_POS_LEFT_TOP        = 2,    /**< 会场名称、时间在左上部[左上] */
    IMOS_EN_SITE_NAME_TIMER_POS_LEFT_BOTTOM     = 3,    /**< 会场名称、时间在左下部[左下] */
    IMOS_EN_SITE_NAME_TIMER_POS_COUNT
} HD_SITE_NAME_TIMER_POS_EX_E;


/**
 * @enum tagHD_CameraTypeEx
 * @brief 摄像机类型
 * @attention
 */
typedef enum tagHD_CameraTypeEx
{
    IMOS_EN_CAM_SONY_D70    = 0,    /**< SONY_D70 */
    IMOS_EN_CAM_SONY_D100   = 1,    /**< SONY_D100 */
    IMOS_EN_CAM_SONY_EVIHD1 = 2,    /**< EVIHD1 */
    IMOS_EN_CAM_TYPE_COUNT          /**< 个数 */
}HD_CAMERA_TYPE_EX_E;

/**
 * @enum tagHD_CameraSpeedEx
 * @brief 摄像机转动速度
 * @attention
 */
typedef enum tagHD_CameraSpeedEx
{
    IMOS_EN_CAM_SPEED_LOW       = 0,        /**< 慢速 */
    IMOS_EN_CAM_SPEED_MIDDLE    = 1,        /**< 中速 */
    IMOS_EN_CAM_SPEED_HIGH      = 2,        /**< 快速 */
    IMOS_EN_CAM_SPEED_COUNT                 /**< 个数 */
}HD_CAMERA_SPEED_EX_E;


/**
 * @enum tagHD_CameraPortEx
 * @brief 摄像机端口
 * @attention
 */
typedef enum tagHD_CameraPortEx
{
    IMOS_EN_CAM_PORT_NONE       = 0,    /**< 无端口 */
    IMOS_EN_CAM_PORT_RS232_1    = 1,    /**< 串口一 */
    IMOS_EN_CAM_PORT_RS232_2    = 2,    /**< 串口二 */
    IMOS_EN_CAM_PORT_COUNT
}HD_CAMERA_PORT_EX_E;

/**
 * @enum tagHD_VideoPortTypeEx
 * @brief 端口类型
 * @attention
 */
typedef enum tagHD_VideoPortTypeEx
{
    IMOS_EN_HD_VIDEO_PORT_DVI_I = 0,    /**< DVI  */
    IMOS_EN_HD_VIDEO_PORT_S     = 1,    /**< S端子 */
    IMOS_EN_HD_VIDEO_PORT_RCA   = 2,    /**< RCA  */
    IMOS_EN_HD_VIDEO_PORT_SDI   = 3,    /**< SDI  */
    IMOS_EN_HD_VIDEO_PORT_COUNT         /**< 个数 */
} HD_VIDEO_PORT_TYPE_EX_E;

/**
 * @enum tagHD_IPPrecedenceTypeEx
 * @brief IP优先类别：最小时延、最大吞吐量、最高可靠性、最小费用
 * @attention
 */
typedef  enum  tagHD_IPPrecedenceTypeEx
{
    IMOS_EN_PRECEDENCE_MIN_DELAY       = 0x10,                  /**< 最小时延 */
    IMOS_EN_PRECEDENCE_MAX_THROUGHPUT  = 0x08,                  /**< 最大吞吐量 */
    IMOS_EN_PRECEDENCE_MAX_RELIABILITY = 0x04,                  /**< 最高可靠性 */
    IMOS_EN_PRECEDENCE_MIN_MONETARY    = 0x02,                  /**< 最小费用 */
    IMOS_EN_PRECEDENCE_NORMAL          = 0                      /**< 普通 */
} HD_IP_PRECEDENCE_TYPE_EX_E;



/**
 * @enum tagHD_Process_TypeEx
 * @brief 进程类型
 * @attention
 */
typedef enum tagHD_Process_TypeEx
{
    IMOS_EN_HD_PROCESS_TYPE_GUI = 0,
    IMOS_EN_HD_PROCESS_TYPE_UM  = 1,
    IMOS_EN_HD_PROCESS_TYPE_MCM = 2,
    IMOS_EN_HD_PROCESS_TYPE_DBM = 3,
    IMOS_EN_HD_PROCESS_TYPE_H323 = 4,
    IMOS_EN_HD_PROCESS_TYPE_VP  = 5,
    IMOS_EN_HD_PROCESS_TYPE_AP  = 6,
    IMOS_EN_HD_PROCESS_TYPE_COUNT                          /**< 个数 */
}HD_PROCESS_TYPE_EX_E;

/**
 * @enum tagHD_VideoPortDVITypeEx
 * @brief DVI的视频内容
 * @attention
 */
typedef enum tagHD_VideoPortDVITypeEx
{
    IMOS_EN_HD_VIDEO_PORT_DVI_RGBHV     = 0,    /**< RGBHV，又名D-SUB,XGA */
    IMOS_EN_HD_VIDEO_PORT_DVI_HDMIDVI   = 1,    /**< HDMI DVI 不再区分  */
    /**< IMOS_EN_HD_VIDEO_PORT_DVI_D,                                    D  */
    IMOS_EN_HD_VIDEO_PORT_DVI_YPrPb     = 2,    /**< YPrPb  */
    IMOS_EN_HD_VIDEO_PORT_DVI_RGB       = 3,    /**< RGB  */
    IMOS_EN_HD_VIDEO_PORT_DVI_COUNT             /**< 个数 */
} HD_VIDEO_PORT_DVI_TYPE_EX_E;


/**
 * @enum tagHD_VideoFrequenceEx
 * @brief 视频频率类型
 * @attention
 */
typedef enum tagHD_VideoFrequenceEx
{
    IMOS_EN_HD_VIDEO_FREQUENCE_25HZ = 0,    /**< 25HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_30HZ = 1,    /**< 30HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_60HZ = 2,    /**< 60HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_75HZ = 3,    /**< 75HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_85HZ = 4,    /**< 85HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_COUNT        /**< 个数 */
} HD_VIDEO_FREQUENCE_TYPE_EX_E;


/**
 * @enum tagHD_Restrict_TypeEx
 * @brief PAL、NTSC制式
 * @attention
 */
typedef enum tagHD_Restrict_TypeEx
{
    IMOS_EN_PAL_TYPE    = 0,    /**< PAL制式 */
    IMOS_EN_NTSC_TYPE   = 1,    /**< NTSC制式 */
    IMOS_EN_RESTRICT_COUNT,
}HD_RESTRICT_TYPE_EX_E;

/**
 * @enum tagHD_ProtoTypeEx
 * @brief 协议类型
 * @attention
 */
typedef enum tagHD_ProtoTypeEx
{
    IMOS_EN_PROTO_TYPE_H323 = 0,    /**< H323协议 */
    IMOS_EN_PROTO_TYPE_SIP  = 1,    /**< sip协议  */
    IMOS_EN_PROTO_TYPE_COUNT        /**< 个数 */
}HD_PROTO_TYPE_EX_E;


/**
 * @enum tagHD_VideoTypeEx
 * @brief 输入端口对应的主辅流类型
 * @attention
 */
typedef  enum  tagHD_VideoTypeEx
{
    IMOS_EN_MV_PORT_1   = 0,    /**< 主流视频源1 */
    IMOS_EN_MV_PORT_2   = 1,    /**< 主流视频源2 */
    IMOS_EN_RV_PORT     = 2,    /**< 辅流视频源 */
    IMOS_EN_VIDEO_TYPE_COUNT
} HD_VIDEO_TYPE_EX_E;



/**
 * @enum tagModule_TypeEx
 * @brief 终端模块类型
 * @attention
 */
typedef enum tagModule_TypeEx
{
    IMOS_EN_HD_MODULE_GUI   = 0,    /**< GUI (数值不可改变，用作数组下标)*/
    IMOS_EN_HD_MODULE_UM    = 1,    /**< UM */
    IMOS_EN_HD_MODULE_MCM   = 2,    /**< MCM */
    IMOS_EN_HD_MODULE_DBM   = 3,    /**< DBM */
    IMOS_EN_HD_MODULE_STK   = 4,    /**< STK */
    IMOS_EN_HD_MODULE_VP    = 5,    /**< VP */
    IMOS_EN_HD_MODULE_AP    = 6,    /**< AP */
    IMOS_EN_HD_MODULE_OSD   = 7,    /**< OSD */
    IMOS_EN_HD_MODULE_TYPE_COUNT
}HD_MODULE_TYPE_EX_E;



/**
 * @enum tagHD_LogTypeEx
 * @brief 日志类型
 * @attention
 */
typedef  enum  tagHD_LogTypeEx
{
    IMOS_EN_HD_SYS_TYPE     = 0,    /**< 系统日志 */
    IMOS_EN_HD_USER_TYPE    = 1,    /**< 用户日志 */
    IMOS_EN_HD_CONF_TYPE    = 2,    /**< 会议日志 */
    IMOS_EN_HD_DEBUG_TYPE   = 3,    /**< 调试日志(终端界面不显示) */
    IMOS_EN_HD_LOG_TYPE_COUNT       /**< 此枚举类型的个数 */
} HD_LOG_TYPE_EX_E;


/**
 * @enum tagHD_VERSION_INDEXEx
 * @brief 版本编码序号
 * @attention
 */
typedef enum tagHD_VERSION_INDEXEx
{
    IMOS_EN_SOFT_OLD_VER    = 0,
    IMOS_EN_SOFT_NEW_VER    = 1,
    IMOS_EN_MG_SOFT_VER     = 2,
    IMOS_EN_JRE_OLD_VER     = 3,
    IMOS_EN_JRE_NEW_VER     = 4,
    IMOS_EN_MAX_VERSION_COUNT
} HD_VERSION_INDEX_EX_E;


/**
 * @enum tagBAK_HostStateEx
 * @brief 当前BAK进程的状态：单机、主机、备机、未确定
 * @attention
 */
typedef enum tagBAK_HostStateEx
{
    IMOS_EN_BAK_STATE_ALONE     = 0,    /**< 单机 */
    IMOS_EN_BAK_STATE_MAIN      = 1,    /**< 主机 */
    IMOS_EN_BAK_STATE_BACK      = 2,    /**< 备机 */
    IMOS_EN_BAK_STATE_UNSURE    = 3,    /**< 未确定 */

    IMOS_EN_BAK_SWITCHING_ALONE = 4,    /**< 正在切单机 */
    IMOS_EN_BAK_SWITCHING_MAIN  = 5,    /**< 正在切主机 */
    IMOS_EN_BAK_SWITCHING_BACK  = 6,    /**< 正在切备机 */

    IMOS_EN_BAK_STATE_COUNT
}BAK_STATE_EX_E;


/**
 * @enum tagMC_LinkStatusEx
 * @brief 链路状态 [仅供状态机切换使用]
 * @attention
 */
typedef enum tagMC_LinkStatusEx
{
    /** 主用链路高带宽稳定 备用链路UP */
    IMOS_EN_LINK_STATUS_MAIN_HB_BAK_UP      = 0,

    /** 主用链路低带宽稳定 备用链路UP */
    IMOS_EN_LINK_STATUS_MAIN_LB_BAK_UP      = 1,

    /** 主用链路低带宽丢包 备用链路UP */
    IMOS_EN_LINK_STATUS_MAIN_LP_BAK_UP      = 2,

    /** 主用链路DOWN 备用链路UP */
    IMOS_EN_LINK_STATUS_MAIN_DOWN_BAK_UP    = 3,

    /** 主用链路高带宽稳定 备用链路DOWN */
    IMOS_EN_LINK_STATUS_MAIN_HB_BAK_DOWN    = 4,

    /** 主用链路低带宽稳定 备用链路DOWN */
    IMOS_EN_LINK_STATUS_MAIN_LB_BAK_DOWN    = 5,

    /** 主用链路低带宽丢包 备用链路DOWN */
    IMOS_EN_LINK_STATUS_MAIN_LP_BAK_DOWN    = 6,

    /** 主用链路DOWN 备用链路DOWN */
    IMOS_EN_LINK_STATUS_MAIN_DOWN_BAK_DOWN  = 7,
    IMOS_EN_LINK_STATUS_COUNT
} MC_LINK_STATUS_EX_E;

/**
 * @enum tagMC_LinkStatusChgStepEx
 * @brief 链路状态切换步骤 [仅供状态机切换使用]
 * @attention
 */
typedef enum tagMC_LinkStatusChgStepEx
{
    /** 更新BFD */
    IMOS_EN_CHG_STEP_UPDATE_BFD_STATUS      = 0,

    /** 删除主用链路BFD */
    IMOS_EN_CHG_STEP_DELETE_MAIN_BFD        = 1,

    /** 删除备用链路BFD */
    IMOS_EN_CHG_STEP_DELETE_BAK_BFD         = 2,

    /** 创建主用链路BFD */
    IMOS_EN_CHG_STEP_CREATE_MAIN_BFD        = 3,

    /** 创建备用链路BFD */
    IMOS_EN_CHG_STEP_CREATE_BAK_BFD         = 4,

    /** 切换路由至主用链路 */
    IMOS_EN_CHG_STEP_CHG_ROUTE2MAIN         = 5,

    /** 切换路由至备用链路 */
    IMOS_EN_CHG_STEP_CHG_ROUTE2BAK          = 6,

    /** 发送request mode */
    IMOS_EN_CHG_STEP_SEND_REQMODE           = 7,

    /** 修改VP接收码率 */
    IMOS_EN_CHG_STEP_MODIFY_CHN_IN          = 8,

    /** 修改VP发送码率 */
    IMOS_EN_CHG_STEP_MODIFY_CHN_OUT         = 9,

    /** 开始检测带宽 */
    IMOS_EN_CHG_STEP_START_DETECT_BITRATE   = 10,

    /** 停止检测带宽 */
    IMOS_EN_CHG_STEP_STOP_DETECT_BITRATE    = 11,
    IMOS_EN_CHG_STEP_COUNT
} MC_LINK_STATUS_CHG_STEP_EX_E;

/**
 * @enum tagMC_LinkChgActionEx
 * @brief 链路状态切换动作 [仅供状态机切换使用]
 * @attention
 */
typedef enum tagMC_LinkChgActionEx
{
    /** 路由切换到备用链路 */
    IMOS_EN_CHG_ACTION_ROUTE2BAK                = 0,

    /** 路由切换到主用链路 */
    IMOS_EN_CHG_ACTION_ROUTE2MAIN               = 1,

    /** 降格式降码率切路由操作 */
    IMOS_EN_CHG_ACTION_ROUTE2BAK_BITRATE2BAK    = 2,

    /** 升格式升码率切路由操作 */
    IMOS_EN_CHG_ACTION_ROUTE2MAIN_BITRATE2MAIN  = 3,

    /** [降格式]降码率操作 */
    IMOS_EN_CHG_ACTION_D_BITRATE                = 4,

    /** [升格式]升码率操作 */
    IMOS_EN_CHG_ACTION_U_BITRATE                = 5,

    /** 路由切换到主用链路，通过RESET备用链路BFD实现 */
    IMOS_EN_CHG_ACTION_RESET2MAIN               = 6,
    IMOS_EN_CHG_ACTION_COUNT
} MC_LINK_CHG_ACTION_EX_E;

/**
 * @enum tagMC_Link_Layer_TypeEx
 * @brief 链路类型
 * @attention
 */
typedef  enum  tagMC_Link_Layer_TypeEx
{
    /** 主用链路 */
    IMOS_EN_LINK_LAYER_MAIN = 0,

    /** 备用链路 */
    IMOS_EN_LINK_LAYER_BAK  = 1,
    IMOS_EN_LINK_LAYER_TYPE_COUNT
} MC_LINK_LAYER_TYPE_EX_E;

/**
 * @enum tagMC_Link_Layer_StateEx
 * @brief 链路连接状态
 * @attention
 */
typedef  enum  tagMC_Link_Layer_StateEx
{
    /** 链路断开 */
    IMOS_EN_LINK_LAYER_DISCONNECT = 0,

    /** 高带宽稳定 */
    IMOS_EN_LINK_LAYER_HIGH_BANDWIDTH = 1,

    /** 低带宽稳定 */
    IMOS_EN_LINK_LAYER_LOW_BANDWIDTH = 2,

    /** 低带宽丢包 */
    IMOS_EN_LINK_LAYER_LOW_BANDWIDTH_WITH_LOST = 3,

    IMOS_EN_LINK_LAYER_STATE_COUNT
} MC_LINK_LAYER_STATE_EX_E;

/**
 * @enum tagMC_Link_Layer_NIC_TypeEx
 * @brief 链路口
 * @attention
 *      1、对于 MCU :主用链路口 --> eth0;   备用链路口 --> eth1
 *      2、对于 终端:主用链路口 --> eth0/1; 备用链路口 --> E1
 *      3、LO 口 IP 地址即为业务地址
 */
typedef  enum  tagMC_Link_Layer_NIC_TypeEx
{
    /** 主用链路口[主用链路地址] */
    IMOS_EN_LINK_LAYER_NIC_TYPE_MAIN = 0,

    /** 备用链路口[备用链路地址] */
    IMOS_EN_LINK_LAYER_NIC_TYPE_BAK = 1,

    /** LO 口[业务地址] */
    IMOS_EN_LINK_LAYER_NIC_TYPE_LO = 2,
    IMOS_EN_LINK_LAYER_NIC_TYPE_COUNT,
} MC_LINK_LAYER_NIC_TYPE_EX_E;

/**
 * @enum tagMC_Link_Layer_Switch_ModeEx
 * @brief 链路切换模式
 * @attention
 */
typedef  enum  tagMC_Link_Layer_Switch_ModeEx
{
    /** 自动 */
    IMOS_EN_LINK_LAYER_SWITCH_BY_AUTO = 0,

    /** 手动 */
    IMOS_EN_LINK_LAYER_SWITCH_BY_MANUAL = 1,
    IMOS_EN_LINK_LAYER_SWITCH_MODE_COUNT,
} MC_LINK_LAYER_SWITCH_MODE_EX_E;

 /**
 * @enum tagMC_TermAlarmStatusEx
 * @brief 终端声光告警状态
 * @attention
 */
typedef enum tagMC_TermAlarmStatusEx
{
    /**< 不启用 */
    IMOS_EN_TERM_ALARM_DISABLE  = 0,

    /**< 告警 */
    IMOS_EN_TERM_ALARM_YES = 1,

    /**< 正常 */
    IMOS_EN_TERM_ALARM_NO = 2,
    IMOS_EN_TERM_ALARM_COUNT
} MC_TERM_ALARM_STATUS_EX_E;

 /**
 * @enum tagMC_NodeTypeEx
 * @brief 节点类型
 * @attention
 */
typedef enum tagMC_NodeTypeEx
{
    /**< MG */
    IMOS_EN_NODE_TYPE_MG  = 0,

    /**< MCU */
    IMOS_EN_NODE_TYPE_MCU = 1,

    IMOS_EN_NODE_TYPE_COUNT
} MC_NODE_TYPE_EX_E;

/**
 * @enum tagMC_VirtualResStatusEx
 * @attention 虚拟会议终端状态
 */
typedef enum tagMC_VirtualResStatusEx
{
    /**< 空闲 */
    IMOS_EN_VIRTUAL_RES_STATUS_IDLE  = 0,

    /**< 虚拟成摄像机 */
    IMOS_EN_VIRTUAL_RES_STATUS_CAMERA = 1,

    /**< 虚拟成监视器 */
    IMOS_EN_VIRTUAL_RES_STATUS_SCREEN = 2,

    IMOS_EN_VIRTUAL_RES_STATUS_COUNT

} MC_VIRTUAL_RES_STATUS_EX_E;


/******************************************************************************
标志：MC_DEVICE_TYPE_E
类型：枚举
目的：上报给iMSC的设备型号
定义：
******************************************************************************/

/**
 * @enum tagMC_VirtualResStatusEx
 * @attention 上报给iMSC的设备型号
 */
typedef  enum tagMcDeviceTypeEx
{
    IMOS_EN_DEVICE_TYPE_SD_TERM_BEGIN   = 0,
    IMOS_EN_DEVICE_TYPE_MG6030          = 1,
    IMOS_EN_DEVICE_TYPE_MG6050          = 2,
    IMOS_EN_DEVICE_TYPE_MG6050S         = 3,
    IMOS_EN_DEVICE_TYPE_MG6060          = 4,
    IMOS_EN_DEVICE_TYPE_TOPVIEW         = 5,

    /** 虚拟终端 */
    IMOS_EN_DEVICE_TYPE_VIRTUAL_TERM    = 6,

    /** 第三方终端 */
    IMOS_EN_DEVICE_TYPE_3RD_TERM    = 7,
    /** 第三方MCU */
    IMOS_EN_DEVICE_TYPE_3RD_MCU     = 8,
    IMOS_EN_DEVICE_TYPE_SD_TERM_END,

    IMOS_EN_DEVICE_TYPE_HD_TERM_BEGIN   = 100,
    IMOS_EN_DEVICE_TYPE_MG9010          = 101,
    IMOS_EN_DEVICE_TYPE_MG9030          = 102,
    IMOS_EN_DEVICE_TYPE_MG9060          = 103,
    IMOS_EN_DEVICE_TYPE_MG9090          = 104,
    IMOS_EN_DEVICE_TYPE_HD_TERM_END,

    IMOS_EN_DEVICE_TYPE_MCU_BEGIN   = 500,
    IMOS_EN_DEVICE_TYPE_ME5000      = 501,
    IMOS_EN_DEVICE_TYPE_ME8000      = 502,
    IMOS_EN_DEVICE_TYPE_ME8600      = 503,
    IMOS_EN_DEVICE_TYPE_MCU_END,

    IMOS_EN_DEVICE_TYPE_GK_BEGIN    = 800,
    IMOS_EN_DEVICE_TYPE_H3C_GK      = 801,
    IMOS_EN_DEVICE_TYPE_GK_END,
}MC_DEVICE_TYPE_EX_E;


/**
 * @enum MC_CHAIR_BROWSE_MODE_EX_E
 * @attention 主场选择观看模式
*/
typedef  enum tagMC_ChairBrowseModeEx
{
    /**< 主场选择观看单画面 */
    IMOS_EN_CHAIR_BROWSE_MODE_SINGLE_PIC = 0,

    /**< 主场选择观看多画面 */
    IMOS_EN_CHAIR_BROWSE_MODE_MULTI_PIC = 1,

    IMOS_EN_CHAIR_BROWSE_MODE_COUNT
} MC_CHAIR_BROWSE_MODE_EX_E;

/**
 * @enum MC_BROADCAST_MODE_EX_E
 * @attention 广播模式
*/
typedef  enum tagMC_BroadcastModeEX
{
    /**< 广播单画面 */
    IMOS_EN_BROADCAST_MODE_SINGLE_PIC = 0,

    /**< 广播多画面 */
    IMOS_EN_BROADCAST_MODE_MULTI_PIC = 1,

    IMOS_EN_BROADCAST_MODE_COUNT
} MC_BROADCAST_MODE_EX_E;

/**
 * @enum tagTermQueryType
 * @brief 终端查询类型
 * @attention
 */
typedef enum tagTermQueryType
{
    /**< 第三方终端 */
    IMOS_EN_TERM_QUERY_TYPE_3RD  = 0,

    /**< H3C终端 */
    IMOS_EN_TERM_QUERY_TYPE_H3C = 1,

    /**< 所有终端(不包括匿名终端) */
    IMOS_EN_TERM_QUERY_TYPE_ALL = 2,

    /**< 匿名终端 */
    IMOS_EN_TERM_QUERY_TYPE_ANONY,

    IMOS_EN_TERM_QUERY_TYPE_COUNT
} TERM_QUERY_TYPE_E;



/**
 * @enum tagMC_ConfigRouteTypeEx
 * @brief 路由操作类型
 * @attention
 */
typedef  enum  tagMC_ConfigRouteTypeEx
{
    /**< 添加路由 */
    IMOS_EN_CONFIG_ROUTE_ADD = 0,

    /**< 修改路由 */
    IMOS_EN_CONFIG_ROUTE_MDF = 1,

    /**< 删除路由 */
    IMOS_EN_CONFIG_ROUTE_DEL = 2,

    /**< 清空路由 */
    IMOS_EN_CONFIG_ROUTE_CLR = 3,

    IMOS_EN_CONFIG_ROUTE_COUNT
} MC_CONFIG_ROUTE_TYPE_EX_E;


/**
 * @enum tagMC_BrowseSiteTypeEx
 * @brief 终端被观看模式
 * @attention
 */
typedef  enum  tagMC_BrowseSiteTypeEx
{
    /**< 会场有效 */
    IMOS_EN_BROWSE_SITE_USE = 0,

    /**< 会场无效 */
    IMOS_EN_BROWSE_SITE_INVALID = 1,

    /**< 多画面 */
    IMOS_EN_BROWSE_SITE_MULTIPIC = 2,

    /**< MCU */
    IMOS_EN_BROWSE_SITE_MCU,

    IMOS_EN_BROWSE_SITE_COUNT
} MC_BROWSE_SITE_TYPE_EX_E;



/**
 * @enum tagEN_SCALER_TYPE_EX
 * @brief 缩放模式: 等比黑边处理、等比裁减处理、拉伸，可能导致变形、透传，即1:1
 * @attention
 */
typedef enum tagEN_SCALER_TYPE_EX
{
    /**< 等比例填黑边 */
    IMOS_EN_HD_SCALER_TYPE_STRETCH_BLACK = 0,

    /**< 等比例裁减 */
    IMOS_EN_HD_SCALER_TYPE_STRETCH_CUT = 1,

    /**< 全屏 */
    IMOS_EN_HD_SCALER_TYPE_STRETCH = 2,

    /**< 原始大小 */
    IMOS_EN_HD_SCALER_TYPE_TRANSP = 3
} HD_SCALER_TYPE_EX_E;


/**
 * @enum tagHD_LPR_Type_EX
 * @brief LPR类型
 * @attention
 */
typedef enum tagHD_LPR_Type_EX
{
    /**< 不启用LPR */
    IMOS_EN_HD_LPR_TYPE_NO = 0,

    /**< 仅丢包会场启用 */
    IMOS_EN_HD_LPR_TYPE_LOST_PATCKET_SITE = 1,

    /**< 全部会场启用 */
    IMOS_EN_HD_LPR_TYPE_ALL_SITE = 2
} HD_LPR_TYPE_EX_E;


/**
* @enum tagInterconnectInfoType
* @brief 互联信息类型枚举
* @attention
*/
typedef enum tagInterconnectInfoType
{
    INTERCONNECT_INFO_TYPE_LODOMAIN      = 0,             /**< 本域互联信息  */

    INTERCONNECT_INFO_TYPE_MAX,
    INTERCONNECT_INFO_TYPE_INVALID = 0xFF
}INTERCONNECT_INFO_TYPE_E;


/**
* @enum tagPlanOperateMode
* @brief 计划操作模式
* @attention
*/
typedef enum tagPlanOperateMode
{
    PLAN_OPER_STOP = 0,                                 /**< 停止计划 */
    PLAN_OPER_START = 1,                                /**< 开启计划 */
    PLAN_OPER_INVALID = 0xFFFFFFFF                      /**< 无效值 */
}PLAN_OPER_MODE_E;

/**
* @enum tagManualOperType
* @brief 手动操作类型
* @attention
*/
typedef enum tagManualOperType
{
    MANUAL_OPER_STOP = 0,               /**< 停止 */
    MANUAL_OPER_START = 1,              /**< 启动 */
    MANUAL_OPER_FORWARD = 2,            /**< 向前调整 */
    MANUAL_OPER_BACKWARD = 3,           /**< 向后调整 */
    MANUAL_OPER_PAUSE = 4,              /**< 暂停 */
    MANUAL_OPER_RESUME = 5,             /**< 恢复 */

    MANUAL_OPER_MAX,                    /**< 枚举最大值 */
    MANUAL_OPER_INVALID = 0xFFFFFFFF    /**< 无效值 */
}MANUAL_OPER_TYPE_E;

/**
* @enum tagLayoutType
* @brief 布局类型枚举
* @attention
*/
typedef enum tagLayoutType
{
    LAYOUT_TYPE_SCREEN       = 1,       /**< 屏幕布局 */
    LAYOUT_TYPE_MONITOR      = 2,       /**< 监视器布局 */

    LAYOUT_TYPE_MAX,                    /**< 枚举最大值 */
    LAYOUT_TYPE_INVALID = 0xFFFFFFFF    /**< 无效值 */
}LAYOUT_TYPE_E;


/**
* @enum tagSalvoType
* @brief 组显示类型枚举
* @attention
*/
typedef enum tagSalvoType
{
    SALVO_TYPE_MONITOR      = 0,       /**< 监视器组显示 */
    SALVO_TYPE_TVWALL       = 1,       /**< 电视墙组显示 */
    SALVO_TYPE_SCREEN       = 2,       /**< 屏幕组显示 */

    SALVO_TYPE_MAX,                    /**< 枚举最大值 */
    SALVO_TYPE_INVALID = 0xFFFFFFFF    /**< 无效值 */
}SALVO_TYPE_E;


/**
* @enum tagCommonSwitchType
* @brief 通用轮切类型枚举
* @attention
*/
typedef enum tagCommonSwitchType
{
    COMMON_SWITCH_GUARDTOUR     =  0,           /**< 普通轮切 */
    COMMON_SWITCH_GROUPSWITCH   =  1,           /**< 组显示轮巡 */
    /* Begin Added by dengshuhua00673, 2012-12-14 of 自动布局轮巡 */
	COMMON_SWITCH_AUTOSWITCH       = 2,           /**< 自动布局轮巡 */
	COMMON_SWITCH_GROUPSWITCH_BOTH = 3,         /**< 包含以上两种轮巡 */
    /* End Added by dengshuhua00673, 2012-12-14 of 自动布局轮巡 */

    /* Begin: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */
    COMMON_SWITCH_AUTOPOLL = 87,                   /**A8拼控自动布局轮巡*/
    COMMON_SWITCH_WINDOWPOLL = 86,             /**A8拼控窗口组轮巡*/
    /* End: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8拼控设备轮巡特性 */

    COMMON_SWITCH_MAX,                          /**< 通用轮切类型最大值 */
    COMMON_SWITCH_INVALID = 0XFFFFFFFF
}COMMON_SWITCH_TYPE_E;

/**
* @enum tagCommonSwitchPlanType
* @brief 通用轮切计划类型枚举
* @attention
*/
typedef enum tagCommonSwitchPlanType
{
    COMMON_SWITCHPLAN_TYPE_MONITOR = 0,                 /**< 硬解轮切计划 */
    COMMON_SWITCHPLAN_TYPE_SCREEN = 1,                  /**< 软解轮切计划 */
    COMMON_SWITCHPLAN_TYPE_GROUPSWITCH = 2,             /**< 组轮巡计划 */

    COMMON_SWITCHPLAN_TYPE_MAX,                         /**< 枚举最大值 */
    COMMON_SWITCHPLAN_TYPE_INVALID = 0xFFFFFFFF         /**< 无效值 */
}COMMON_SWITCHPLAN_TYPE_E;


/**
* @enum tagGroupSwitchType
* @brief 组轮巡类型枚举
* @attention
*/
typedef enum tagGroupSwitchType
{
    GROUP_SWITCH_TYPE_MONITOR     =  0,           /**< 监视器组轮巡 */
    GROUP_SWITCH_TYPE_TVWALL      =  1,           /**< 电视墙组轮巡 */
    GROUP_SWITCH_TYPE_SCREEN      =  2,           /**< 屏幕组轮巡 */

    GROUP_SWITCH_TYPE_MAX,                        /**< 组轮巡类型最大值 */
    GROUP_SWITCH_TYPE_INVALID = 0XFFFFFFFF
}GROUP_SWITCH_TYPE_E;

/* Begin Added by dengshuhua00673, 2013-03-20 of 自动布局轮巡 */
/**
* @enum tagAutoSalvoReaveType
* @brief 自动布局轮巡抢占类型
* @attention
*/
typedef enum tagAutoSalvoReaveType
{
    AUTOSALVO_REAVE_TYPE_NOREAVE     =  0,           /**< 不抢占 */
    AUTOSALVO_REAVE_TYPE_REAVE       =  1,           /**< 抢占 */

    AUTOSALVO_REAVE_TYPE_MAX,                        /**< 自动布局轮巡抢占类型最大值 */
    AUTOSALVO_REAVE_TYPE_INVALID = 0XFFFFFFFF
}AUTOSALVO_REAVE_TYPE_E;
/* End Added by dengshuhua00673, 2013-03-20 of 自动布局轮巡 */

/** 透明通道推送UI的事件枚举类型定义 */
typedef enum tagTLNotifyUIEventType
{
    TL_NOTIFY_TYPE_REAVE   = 1,    /** 透明通道被停用 */

    TL_NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}TL_NOTIFY_UI_EVENT_TYPE;

/**
* @enum tagConfCheckAuthMode
* @brief 会议鉴权方式
* @attention
*/
typedef enum tagConfCheckAuthMode
{
    IMOS_EN_CONF_CHECK_AUTH_CONFCTRL   = 0,             /**< 会议控制鉴权 */
    IMOS_EN_CONF_CHECK_AUTH_CONFMANAGE = 1,                 /**< 会议管理鉴权 */
    IMOS_EN_CONF_CHECK_AUTH_COUNT
} CONF_CHECK_AUTH_MODE_E;


/**
* @enum tagMcuSynchronStatus
* @brief MCU同步状态
* @attention
*/
typedef enum tagMcuSynchronStatus
{
    IMOS_EN_MCU_SYNC_STATUS_OPEN  = 0,             /**< 正在同步 */
    IMOS_EN_MCU_SYNC_STATUS_CLOSE = 1,             /**< 没有在同步 */
    IMOS_EN_MCU_SYNC_STATUS_COUNT
} MCU_SYNCHRON_STATUS_E;


/**
* @enum tagIMOSFtpFileType
* @brief FTP文件类型
* @attention
*/
typedef enum tagIMOSFtpFileType
{
    IMOS_FTP_FILE_TYPE_DEFAULT           = 0,      /** 缺省文件类型，表示直接在ftp根目录 */
    IMOS_FTP_FILE_TYPE_CONFERENCE_CONFIG = 1,      /** 视讯设备会议配置文件，对应存放视讯会议配置文件的目录 */

    IMOS_FTP_FILE_TYPE_MAX,
    IMOS_FTP_FILE_TYPE_INVALID = 0xFFFFFFFF
}IMOS_FTP_FILE_TYPE_E;

/**
* @enum tagMCUBackupType
* @brief MCU备份类型
* @attention
*/
typedef enum tagMCUBackupType
{
    IMOS_MCU_BACKUP_TYPE_SPECIFIC       = 0,    /**< 专用于备份的MCU */
    IMOS_MCU_BACKUP_TYPE_AVAILABLE      = 1,    /**< 可用于备份的MCU */
    IMOS_MCU_BACKUP_TYPE_UNAVAILABLE    = 2,    /**< 不能用于备份的MCU */
    IMOS_MCU_BACKUP_TYPE_COUNT
}MCU_BACKUP_TYPE_E;

/**
* @enum tagMCUBackupScope
* @brief MCU备份类型
* @attention
*/
typedef enum tagMCUBackupScope
{
    IMOS_MCU_BACKUP_SCOPE_LOCAL              = 0,  /**< 只用于备份当前域的MCU */
    IMOS_MCU_BACKUP_SCOPE_LOCAL_AND_CHILDREN = 1,  /**< 用于备份当前域和子孙域的MCU */
    IMOS_MCU_BACKUP_SCOPE_COUNT
}MCU_BACKUP_SCOPE_E;

/**
* @enum tagMgSessionStatus
* @brief MG会话状态
* @attention
*/
typedef enum tagMgSessionStatus
{
    IMOS_MG_SESSION_STATUS_IDLE              = 0,  /**< 空闲 */
    IMOS_MG_SESSION_STATUS_CALLING           = 1,  /**< 通话中 */
    IMOS_MG_SESSION_STATUS_UNKNOWN           = 2,  /**< 未知 */
    IMOS_MG_SESSION_STATUS_COUNT
}MG_SESSION_STATUS_E;

/**
* @enum tagMCMCUCallTypeEX
* @brief MCU类型终端的呼叫配置类型
* @attention
*/
typedef enum tagMCMCUCallTypeEX
{
    IMOS_EN_MCU_CALL_TYPE_AUTO               = 0,  /* 自动 */
    IMOS_EN_MCU_CALL_TYPE_CALL               = 1,  /* 主动呼出 */
    IMOS_EN_MCU_CALL_TYPE_WAIT               = 2,  /* 等待呼入 */
    IMOS_EN_MCU_CALL_TYPE_COUNT
} MC_MCU_CALL_TYPE_EX_E;

/**
* @enum tagTIP_TimeLenTypeEx
* @brief 表示当前启用的是哪种结束提示音
* @attention
*/
typedef enum tagTIP_TimeLenTypeEx
{
    IMOS_EN_AUD_TIP_CONF_END_TIME0           = 0,  /* 不启用会议结束提示音 */
    IMOS_EN_AUD_TIP_CONF_END_TIME3           = 3,  /* 启用会议结束3分钟 */
    IMOS_EN_AUD_TIP_CONF_END_TIME5           = 5,  /* 启用会议结束5分钟 */
    IMOS_EN_AUD_TIP_CONF_END_TIME10          = 10  /* 启用会议结束10分钟 */
} HD_TIP_TIME_LEN_TYPE_EX_E;

/**
* @enum tagSubscType
* @brief 订阅类型枚举
* @attention
*/
typedef enum tagSubscType
{
    SUBSC_ALARM_TYPE              = 0,                /**< 告警订阅，对应条件枚举为:#SUBSC_ALARM_CON_E  */
    SUBSC_CATALOG_TYPE            = 1,                /**< 目录订阅 */

    SUBSC_MAX_TYPE,
    SUBSC_INVALID_TYPE            = 0xFF
}SUBSC_TYPE_E;

/**
* @struct SUBSC_ALARM_CON_S
* @brief 订阅告警过滤条件枚举
*/
typedef enum tagAlarmConType
{
    ALARM_CON_EVENT_TYPE            = 0,            /** 订阅的告警类型 */
    ALARM_CON_LEVEL_TYPE,                           /** 订阅的告警级别，此条件和ALARM_CON_EVENT_TYPE互斥 */

    ALARM_CON_TYPE_MAX,
    ALARM_CON_TYPE_INVALID          = 0xFF
}SUBSC_ALARM_CON_E;

/**
* @enum tagTrunkType
* @brief 干线管理类型枚举
* @attention
*/
typedef enum tagTrunkType
{
    TRUNK_TYPE_EXDOMAIN     = 0,             /**< 外域干线  */
    TRUNK_TYPE_DEV          = 1,             /**< 设备干线  */

    TRUNK_TYPE_MAX,
    TRUNK_TYPE_INVALID          = 0xFF
}TRUNK_TYPE_E;

/**
* @enum tagTrunkContentType
* @brief 干线内容类型枚举
* @attention
*/
typedef enum tagTrunkContentType
{
    TRUNK_CONTENT_TYPE_ALL_EXDOMAIN     = 0,             /**< 所有外域  */
    TRUNK_CONTENT_TYPE_EXDOMAIN         = 1,             /**< 外域  */
    TRUNK_CONTENT_TYPE_ORG              = 2,             /**< 组织  */
    TRUNK_CONTENT_TYPE_DEV              = 3,             /**< 设备  */
    TRUNK_CONTENT_TYPE_ECR_DEV          = 4,             /**< ECR设备  */

    /* Begin add by zhuzhicong/02302, 2016-10-13 13:44:36， 燕房线对外域ECR干线管理 */
    TRUNK_CONTENT_TYPE_EXDOMAIN_ORG     = 5,             /**< 外域组织 */
    /* End add by zhuzhicong/02302, 2016-10-13 13:45:46 */

    TRUNK_CONTENT_TYPE_MAX,
    TRUNK_CONTENT_TYPE_INVALID          = 0xFF
}TRUNK_CONTENT_TYPE_E;


/**
* @enum tagTrunkContentRangeType
* @brief 干线内容管理范围类型枚举
* @attention
*/
typedef enum tagTrunkContentRangeType
{
    TRUNK_CONTENT_RANGE_TYPE_LOC            = 0,        /**< 本级 */
    TRUNK_CONTENT_RANGE_TYPE_LOC_AND_SUB    = 1,        /**< 本级以及下级  */

    TRUNK_CONTENT_RANG_TYPE_MAX,
    TRUNK_CONTENT_RANG_TYPE_INVALID         = 0xFF
}TRUNK_CONTENT_RANGE_TYPE_E;

/**
* @enum tagPlanTypeDef
* @brief 计划类型定义
* @attention
*/
typedef enum tagPlanTypeDef
{
    PLAN_BAK              = 0,                          /**< 备份计划 */
    PLAN_STREAM_STOR      = 1,     						/**< 流转存计划 */
    PLAN_TYPE_DEF_MAX,                                  /**< 最大值 */
    PLAN_TYPE_DEF_INVALID = 0xFFFFFFFF                  /**< 无效值 */
}PLAN_TYPE_DEF_E;

/**
* @enum tagBakMode
* @brief 备份模式
* @attention
*/
typedef enum tagBakMode
{
    BAK_SHARE        = 0,                               /**< 共享 */
    BAK_OWN          = 1,                               /**< 独享 */
    BAK_MODE_MAX,                                       /**< 最大值 */
    BAK_MODE_INVALID = 0xFFFFFFFF                       /**< 无效值 */
}BAK_MODE_E;

/**
* @enum tagBakType
* @brief 备份类型
* @attention
*/
typedef enum tagBakType
{
    BAK_PLAN         = 0,                               /**< 计划任务 */
    BAK_MANUL        = 1,                               /**< 手动任务 */
    BAK_ALARM        = 2,                               /**< 告警任务 */
    BAK_ALL          = 3,                               /**< 所有任务类型，查询任务时使用 */
    BAK_TYPE_MAX,                                       /**< 最大值 */
    BAK_TYPE_INVALID = 0xFFFFFFFF                       /**< 无效值 */
}BAK_TYPE_E;

/**
* @enum tagBakPolicy
* @brief 备份策略
* @attention
*/
typedef enum tagBakPolicy
{
    BAK_POLICY_FULLFRAME = 0,                           /**< 全帧备份 */
    /*begin add by liangchao, 2016-03-5 for 支持svc*/
	BAK_POLICY_SOMEFRAME = 1,                           /**< 抽帧备份 */
	BAK_POLICY_HALFFRAME = 2,                           /**<1/2抽帧 */
	BAK_POLICY_QUARTERFRAME = 3,                        /**<1/4抽帧 */
	/*end add by liangchao, 2016-03-5 for 支持svc*/
    BAK_POLICY_MAX,                                     /**< 最大值 */
    BAK_POLICY_INVALID   = 0xFFFFFFFF                   /**< 无效值 */
}BAK_POLICY_E;

/**
* @enum tagAutoRetryEnable
* @brief 自动调度策略
* @attention
*/
typedef enum tagAutoRetry
{
    AUTO_RETRY_DISABLE = 0,                           /**< 不启用自动补备 */
    AUTO_RETRY_ENABLE = 1,                           /**< 启用自动补备 */
    AUTO_RETRY_MAX,                                     /**< 最大值 */
    AUTO_RETRY_INVALID   = 0xFFFFFF                     /**< 无效值 */
}AUTO_RETRY_E;

/**
* @enum tagBakTaskStatus
* @brief 备份任务状态
* @attention
*/
typedef enum tagBakTaskStatus
{
    BAK_TASK_WAIT           = 0,                        /**< 未启动 */
    BAK_TASK_RUN            = 1,                        /**< 正在备份 */
    BAK_TASK_DONE           = 2,                        /**< 已经完成 */
    BAK_TASK_HANG           = 3,                        /**< 挂机 */
    BAK_TASK_STATUS_MAX,                                /**< 最大值 */
    BAK_TASK_STATUS_INVALID = 0xFFFFFFFF                /**< 无效值 */
}BAK_TASK_STATUS_E;

/**
* @enum tagBakFileOper
* @brief 备份文件操作
* @attention
*/
typedef enum tagBakFileOper
{
    BAK_FILE_LOCK         = 1,                          /**< 锁定 */
    BAK_FILE_UNLOCK       = 2,                          /**< 解锁 */
    BAK_FILE_DELETE       = 3,                          /**< 删除 */
    BAK_FILE_OPER_MAX,                                  /**< 最大值 */
    BAK_FILE_OPER_INVALID = 0xFFFFFFFF                  /**< 无效值 */
}BAK_FILE_OPER_E;

/**
* @enum tagBakResStatus
* @brief 备份资源状态
* @attention
*/
typedef enum tagBakResStatus
{
    BAK_RES_UNFORMATTED    = 0,                         /**< 未格式化 */
    BAK_RES_FORMATTING     = 1,                         /**< 正在格式化 */
    BAK_RES_ONLINE         = 2,                         /**< 在线 */
    BAK_RES_OFFLINE        = 3,                         /**< 离线 */
    BAK_RES_STATUS_MAX,                                 /**< 最大值 */
    BAK_RES_STATUS_INVALID = 0xFFFFFFFF                 /**< 无效值 */
}BAK_RES_STATUS_E;

/**
* @enum tagBakFileQueryType
* @brief 备份录像查询类型
* @attention
*/
typedef enum tagBakFileQueryType
{
    BAK_FILE_QUERY_TYPE_TIME    = 0,                    /**< 按备份时间查询 */
    BAK_FILE_QUERY_TYPE_CASE    = 1,                    /**< 按案例描述查询 */
    BAK_FILE_QUERY_TYPE_MAX,                            /**< 最大值 */
    BAK_FILE_QUERY_TYPE_INVALID = 0xFFFFFFFF            /**< 无效值 */
}BAK_FILE_QUERY_TYPE_E;

/**
* @enum tagBakResType
* @brief 备份资源类型
* @attention
*/
typedef enum tagBakResType
{
    BAK_RES_TYPE_H3C     = 0,                           /**< 我司设备 */
    BAK_RES_TYPE_THIRD   = 1,                           /**< 第三方设备 */
    BAK_RES_TYPE_CDS     = 4,                           /**< cds设备 */
    BAK_RES_TYPE_MAX,                                   /**< 最大值 */
    BAK_RES_TYPE_INVALID = 0xFFFFFFFF                   /**< 无效值 */
}BAK_RES_TYPE_E;

/* added by z06806 for vodwall prj 20101216 begin */
/**
* @enum tagVODWALLStopCodeType
* @brief 表示使用哪种编码来关闭回放上墙
* @attention
*/
typedef enum tagVODWALLStopCodeType
{
    IMOS_VODWALL_STOP_CODETYPE_XP           = 0,  /* 根据XP编码关闭回放上墙 */
    IMOS_VODWALL_STOP_CODETYPE_MONITOR      = 1,  /* 根据监视器编码关闭回放上墙 */
} VODWALL_STOP_CODETYPE_E;
/* added by z06806 for vodwall prj 20101216 end */

/*@brief 回调函数类型 */
typedef VOID (STDCALL *SDK_CALL_BACK_PROC_PF)(INOUT VOID *pParam);


/**
* @enum tagUniversalConditionFlag
* @brief 通用约束查询条件标志位
* @attention
*/
typedef enum tagUniversalConditionFlag
{
    /** 全或 */
    CONDITION_OR_ALL,
    /** 全与 */
    CONDITION_AND_ALL,
    /** 先或后与 例如:<a and b and (c or d)> */
    CONDITION_AND_OR,
    /** 先与后或 例如:<a or b or (c and d)> */
    CONDITION_OR_AND
}UNI_CONDITION_FLAG_E;

/**************************************************************************/
/**
* @enum tagUniversalQueryFlag
* @brief 通用查询标志位
* @attention
*/
typedef enum tagUniversalQueryFlag
{
    UNI_QRY_CAM_STORAGE_INFO = 0,   /**< 摄像机存储信息查询,对应的内容#QRY_CAM_STORAGE_INFO_E */
    UNI_QRY_FAULT_DEVICE_INFO = 1,  /**< 故障设备信息查询,对应的内容#QRY_FAULT_DEV_INFO_E */
    UNI_QRY_FAULT_DEVSTAT_INFO = 2, /**< 故障设备统计信息查询,对应的内容#QRY_FAULT_DEV_STAT_E */
    UNI_QRY_ASSET_INFO = 3,         /**< 资产信息查询,对应的内容#QRY_ASSET_INFO_E */
    UNI_QRY_ASSET_STAT_INFO = 4,    /**< 资产统计信息查询,对应的内容#QRY_ASSET_INFO_E */

    UNI_QRY_VEHICLE_DAY_STAT_BY_TYPE  = 5,  /**< 车辆统计，日报表，分车辆类型统计#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_DAY_STAT_BY_DIR   = 6,  /**< 车辆统计，日报表，分车道方向统计#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_DAY_STAT_BY_LANE  = 7,  /**< 车辆统计，日报表，分车道统计#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_HOUR_STAT_BY_TYPE = 8,  /**< 车辆统计，小时报表，分车辆类型统计#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_HOUR_STAT_BY_DIR  = 9,  /**< 车辆统计，小时报表，分车道方向统计#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_HOUR_STAT_BY_LANE = 10, /**< 车辆统计，小时报表，分车道统计#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_GACASE_INFO               = 11, /**< 案件信息查询(不带子组织),对应的内容#QRY_GACASE_INFO_E */
    UNI_QRY_GACASE_SUB_INFO           = 12, /**< 案件信息查询(带子组织),对应的内容#QRY_GACASE_INFO_E */

    UNI_QRY_MAX
}UNI_QUERY_FLAG_E;

/* Begin: added by zhangdong(kf0134), 2013.9.11 for 通用数据库查询*/
/**
* @enum tagUniversalQueryFlag
* @brief 通用查询标志位
* @attention
*/
typedef enum tagUniversalQryFlag
{
    UNI_QUERY_TOTAL_COUNT_INFO = 0,   /**< 查询符合条件的总数 */
    UNI_QUERY_SQL_STATEMENT_INFO = 1,  /**< 数据库SQL 语句查询 */
    UNI_QUERY_STORAGE_PROCESS_INFO = 2, /**<  数据库存储过程查询 */
    /* Begin added by z00758,2013-11-28 for 跨域智能拉框放大 */
    UNI_EXECUTE_SQL_STATEMENT_INFO = 3,  /**< 数据库SQL 语句执行 */
    /* End added by z00758,2013-11-28 for 跨域智能拉框放大 */

    UNI_QUERY_MAX
}UNIVERSAL_QUERY_FLAG_E;
/* End: added by zhangdong(kf0134), 2013.9.11 for 通用数据库查询*/

/**
* @enum tagQryCamStorageInfo
* @brief 摄像机存储信息查询内容
* @attention
*/
typedef enum tagQryCamStorageInfo
{
    CAMST_CAMERA_NAME = 0,    /**< 摄像机名称#IMOS_NAME_LEN */
    CAMST_CAMERA_CODE,        /**< 摄像机编码#IMOS_CODE_LEN */
    CAMST_RECODRD_DATE,       /**< 存储日期#IMOS_TIME_LEN */
    CAMST_STORAGE_DEVNAME,    /**< 存储设备名称#IMOS_NAME_LEN */
    CAMST_STORAGE_DEVCODE,    /**< 存储设备编码#IMOS_CODE_LEN */
    CAMST_STORAGE_DEVTYPE,    /**< 存储设备类型#ULONG */
    CAMST_RECORD_HOUR0002,    /**< 00:00-02:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR0204,    /**< 02:00-04:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR0406,    /**< 04:00-06:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR0608,    /**< 06:00-08:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR0810,    /**< 08:00-10:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR1012,    /**< 10:00-12:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR1214,    /**< 12:00-14:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR1416,    /**< 14:00-16:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR1618,    /**< 16:00-18:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR1820,    /**< 18:00-20:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR2022,    /**< 20:00-22:00点的存储信息#ULONG */
    CAMST_RECORD_HOUR2224,    /**< 22:00-24:00点的存储信息#ULONG */
    CAMST_IS_CREATEPLAN,      /**< 是否制定了存储计划#ULONG */
    CAMST_IS_ENABELPLAN,      /**< 是否启动了存储计划#ULONG */
    CAM_ST_MAX
}QRY_CAM_STORAGE_INFO_E;


typedef enum tagQryGACaseInfo
{
    GA_CASE_CODE            = 0,         /**< 案件编码#IMOS_CODE_LEN */
    GA_CASE_NAME            = 1,         /**< 案件名称#IMOS_NAME_LEN */
    GA_CASE_PROPERTY        = 2,         /**< 案件性质#CASE_PROPERTY_E */
    GA_CASE_TYPE            = 3,         /**< 案件类型#CASE_TYPE_E */
    GA_CASE_STATUS          = 4,         /**< 案件状态#CASE_STATUS_E */
    GA_CASE_POLICESRC       = 5,         /**< 警情来源#POLICE_INTELLIGENCE_SOURCE_ */
    GA_CASE_REPORTCODE      = 6,         /**< 接警单号#IMOS_CODE_LEN */
    GA_CASE_REPORTTIME      = 7,         /**< 接警时间#IMOS_TIME_LEN */
    GA_CASE_PROPERSON       = 8,         /**< 处理人#IMOS_NAME_LEN */
    GA_CASE_ENDANGERMENT    = 9,         /**< 危害程度#IMOS_NAME_LEN */
    GA_CASE_DESC            = 10,         /**< 案件描述#IMOS_CASE_DESC_LEN */
    GA_CASE_NOTE            = 11,         /**< 案件备注#IMOS_NOTE_LEN */
    GA_CASE_BEGINTIME       = 12,         /**< 作案开始时间#IMOS_CODE_LEN */
    GA_CASE_ENDTIME         = 13,         /**< 作案结束时间#IMOS_CODE_LEN */
    GA_CASE_CRIMEOPPERUNITY = 14,         /**< 作案时间#IMOS_TIME_LEN */
    GA_CASE_CRIMELOCATION   = 15,         /**< 作案地点#IMOS_TIME_LEN */
    GA_CASE_CRIMEPOSITION   = 16,         /**< 作案部位#IMOS_NAME_LEN */
    GA_CASE_CRIMENUM        = 17,         /**< 作案人数#ULONG */
    GA_CASE_CRIMTARGET      = 18,         /**< 作案对象#IMOS_NAME_LEN */
    GA_CASE_CRIMSTYLE       = 19,         /**< 作案特点#IMOS_NAME_LEN */
    GA_CASE_DISTRICT        = 20,         /**< 区县#IMOS_NAME_LEN */
    GA_CASE_STREET          = 21,         /**< 街道#IMOS_NAME_LEN */
    GA_CASE_POLICEDISTRICT  = 22,         /**< 警区#IMOS_NAME_LEN */
    GA_CASE_COMMUNITY       = 23,         /**< 社区#IMOS_NAME_LEN */
    GA_CASE_ADDRESS         = 24,         /**< 详细地址#IMOS_STRING_LEN_256 */
    GA_CASE_CREATOR         = 25,         /**< 创建人#IMOS_NAME_LEN */
    GA_CASE_ORGCODE         = 26,         /**< 所属组织编码#IMOS_CODE_LEN */
    GA_CASE_ORGNAME         = 27,         /**< 所属组织名称#IMOS_NAME_LEN */

    GA_RECODE_CODE          = 28,       /**< 录像编码#IMOS_CODE_LEN */
    GA_RECODE_NAME          = 29,       /**< 录像名称#IMOS_NAME_LEN */
    GA_CAMERA_CODE          = 30,       /**< 摄像机编码#IMOS_CODE_LEN */
    GA_RECORD_BEGINTIME     = 31,       /**< 录像开始时间#IMOS_TIME_LEN */
    GA_RECODE_ENTIME        = 32,       /**< 录像结束时间#IMOS_TIME_LEN */
    GA_RECODE_SIZE          = 33,       /**< 录像大小#ULONG */
    GA_RECODE_UPLOADTIME    = 34,       /**< 录像上传时间#IMOS_TIME_LEN */
    GA_RECODE_UPLOADUSER    = 35,       /**< 录像上传人#IMOS_NAME_LEN */
    GA_RECODE_NOTE          = 36,       /**< 录像备注#IMOS_NOTE_LEN */

    GA_FILE_CODE            = 37,       /**< 文件编码#IMOS_CODE_LEN */
    GA_FILE_NAME            = 38,       /**< 文件名称#IMOS_NAME_LEN */
    GA_FILE_SIZE            = 39,       /**< 文件大小#ULONG */
    GA_FILE_TYPE            = 40,       /**< 文件类型#CASE_FILE_TYPE_E */
    GA_FILE_UPLOADTIME      = 41,       /**< 文件上传时间#IMOS_TIME_LEN */
    GA_FILE_UPLOADUSER      = 42,       /**< 文件上传人#IMOS_NAME_LEN */
    GA_FILE_NOTE            = 43,       /**< 文件备注#IMOS_NAME_LEN */

    GA_REPORTER_CODE        = 44,       /**< 报警人编码#IMOS_CODE_LEN */
    GA_REPORTER_NAME        = 45,       /**< 报警人名称#IMOS_NAME_LEN */
    GA_REPORTER_GENDER      = 46,       /**< 报警人性别#GENDER_TYPE_E */
    GA_REPORTER_MINAGE      = 47,       /**< 报警人最小年纪#ULONG */
    GA_REPORTER_MAXAGE      = 48,       /**< 报警人最大年纪#ULONG */
    GA_REPORTER_NATIVE      = 49,       /**< 报警人籍贯#IMOS_NAME_LEN */
    GA_REPORTER_TELEPHONE   = 50,       /**< 报警人电话#IMOS_NAME_LEN */
    GA_REPORTER_COMPANY     = 51,       /**< 报警人工作单位#IMOS_PHONE_LEN */
    GA_REPORTER_NOTE        = 52,       /**< 报警人备注#IMOS_NOTE_LEN */

    GA_STUFF_CODE           = 53,       /**< 涉案物品编码#IMOS_CODE_LEN */
    GA_STUFF_NAME           = 54,       /**< 涉案物品名称#IMOS_NAME_LEN */
    GA_STUFF_TYPE           = 55,       /**< 涉案物品类型#CASE_STUFF_TYPE_E */
    GA_STUFF_PROPERTY       = 56,       /**< 涉案物品性质#CASE_STUFF_PROPERTY_E */
    GA_STUFF_NOTE           = 57,       /**< 涉案物品备注#IMOS_NOTE_LEN */

    GA_VEHICLE_CODE         = 58,       /**< 涉案车辆编码#IMOS_NAME_LEN */
    GA_VEHICLE_COLOR        = 59,       /**< 涉案车辆颜色#IMOS_NAME_LEN */
    GA_VEHICLE_TYPE         = 60,       /**< 涉案车辆型号#IMOS_NAME_LEN */
    GA_VEHICLE_FEATURE      = 61,       /**< 涉案车辆特征#IMOS_NAME_LEN */
    GA_VEHICLE_LOCALIZATION = 62,       /**< 涉案车辆归属地#IMOS_NAME_LEN */
    GA_VEHICLE_CLASSIFICATE = 63,       /**< 涉案车辆分类#IMOS_NAME_LEN */
    GA_VEHICLE_MANUFACTURER = 64,       /**< 涉案车辆厂商#IMOS_NAME_LEN */
    GA_VEHICLE_BEHAVIOR     = 65,       /**< 涉案车辆行为#IMOS_NAME_LEN */
    GA_VEHICLE_PLATECODE    = 66,       /**< 涉案车辆车牌号码#IMOS_NAME_LEN */
    GA_VEHICLE_PLATETYPE    = 67,       /**< 涉案车辆车牌类型#IMOS_NAME_LEN */
    GA_VEHICLE_PLATECOVER   = 68,       /**< 涉案车辆车牌遮挡#IMOS_NAME_LEN */
    GA_VEHICLE_WINDOWFILM   = 69,       /**< 涉案车辆贴膜#IMOS_NAME_LEN */
    GA_VEHICLE_NOTE         = 70,       /**< 涉案车辆备注#IMOS_NAME_LEN */

    GA_REFER_CODE           = 71,       /**< 涉案人编码#IMOS_CODE_LEN */
    GA_REFER_NAME           = 72,       /**< 涉案人名称#IMOS_NAME_LEN */
    GA_REFER_GENDER         = 73,       /**< 涉案人性别#GENDER_TYPE_E */
    GA_REFER_MINAGE         = 74,       /**< 涉案人最小年纪#ULONG */
    GA_REFER_MAXAGE         = 75,       /**< 涉案人最大年纪#ULONG */
    GA_REFER_NATIVE         = 76,       /**< 涉案人籍贯#IMOS_NAME_LEN */
    GA_REFER_TELEPHONE      = 77,       /**< 涉案人电话#IMOS_NAME_LEN */
    GA_REFER_COMPANY        = 78,       /**< 涉案人工作单位#IMOS_NAME_LEN */
    GA_REFER_BEHAVIOR       = 79,       /**< 涉案人行为#IMOS_NAME_LEN */
    GA_REFER_ACCENT         = 80,       /**< 涉案人口音#IMOS_NAME_LEN */
    GA_REFER_BODYSHAPE      = 81,       /**< 涉案人体型#IMOS_NAME_LEN */
    GA_REFER_HEIGHT         = 82,       /**< 涉案人身高#IMOS_NAME_LEN */
    GA_REFER_SKINCOLOR      = 83,       /**< 涉案人肤色#IMOS_NAME_LEN */
    GA_REFER_SHIRTSTYPE     = 84,       /**< 涉案人上衣款式#IMOS_NAME_LEN */
    GA_REFER_SHIRTCOLOR     = 85,       /**< 涉案人上衣颜色#IMOS_NAME_LEN */
    GA_REFER_SHIRTFRATURE   = 86,       /**< 涉案人上衣特征#IMOS_NAME_LEN */
    GA_REFER_SLEEVELENTH    = 87,       /**< 涉案人衣袖长度#IMOS_NAME_LEN */
    GA_REFER_COLLAR         = 88,       /**< 涉案人衣领#IMOS_NAME_LEN */
    GA_REFER_TROUSERS       = 89,       /**< 涉案人裤型#IMOS_NAME_LEN */
    GA_REFER_TROUSERSLENGTH = 90,       /**< 涉案人裤长#IMOS_NAME_LEN */
    GA_REFER_TROUSERSCOLOR  = 91,       /**< 涉案人裤子颜色#IMOS_NAME_LEN */
    GA_REFER_HAIRSTYLE      = 92,       /**< 涉案人发型#IMOS_NAME_LEN */
    GA_REFER_HAIRCOLOR      = 93,       /**< 涉案人发色#IMOS_NAME_LEN */
    GA_REFER_EYECLASS       = 94,       /**< 涉案人眼镜#IMOS_NAME_LEN */
    GA_REFER_CAP            = 95,       /**< 涉案人帽子#IMOS_NAME_LEN */
    GA_REFER_SCARF          = 96,       /**< 涉案人围巾#IMOS_NAME_LEN */
    GA_REFER_BAG            = 97,       /**< 涉案人包包#IMOS_NAME_LEN */
    GA_REFER_SHOESTYLE      = 98,       /**< 涉案人鞋型#IMOS_NAME_LEN */
    GA_REFER_SHOECOLOR      = 99,       /**< 涉案人鞋子颜色#IMOS_NAME_LEN */
    GA_REFER_BODYSURFACE    = 100,
    GA_REFER_NOTE           = 101,

    GA_SERIES_CODE          = 102,      /**< 串并案编码#IMOS_NAME_LEN */
    GA_SERIES_NAME          = 103,      /**< 串并案名称#IMOS_NAME_LEN */
    GA_SERIES_NOTE          = 104,      /**< 串并案备注#IMOS_NAME_LEN */

    GA_DEPT_CODE            = 105,      /**< 部门编码#IMOS_CODE_LEN */
    GA_DEPT_NAME            = 106,      /**< 部门名称#IMOS_NAME_LEN */
    GA_CASE_CREATETIME      = 107,      /**< 案件创建时间#IMOS_TIME_LEN */
    GA_CASE_SOLVEDTIME      = 108,      /**< 案件破案时间#IMOS_TIME_LEN */
    GA_CASE_CLOSEDTIME      = 109,      /**< 案件结案时间#IMOS_TIME_LEN */
    GA_CASE_CRIMESPECIALTY  = 110,      /**< 案件作案特点#*/
    GA_VEHICLE_PLATECOLOR   = 111,      /**< 涉案车辆的车牌颜色#IMOS_DICTIONARY_KEY_LEN */

    GA_CASE_MAX,
}QRY_GACASE_INFO_E;

/**
* @enum tagTVWallResolution
* @brief 电视墙分辨率类型
* @attention
*/
typedef enum tagTVWallResolution
{
    TW_RESOLUTION_1440_900                     = 0,                 /**< 电视墙1440*900分辨率 */
    TW_RESOLUTION_1280_1024                    = 1,                 /**< 电视墙1280*1024分辨率 */
    TW_RESOLUTION_1280_800                     = 2,                 /**< 电视墙1280*800分辨率 */
    TW_RESOLUTION_1024_768                     = 3,                 /**< 电视墙1024*768分辨率 */
    TW_RESOLUTION_MAX,                                              /**< 最大值 */
    TW_RESOLUTION_INVALID                      = 0xFFFFFFFF         /**< 无效值 */
}TW_RESOLUTION_E;


/**
* @enum tagIMOSStreamServerMode
* @brief 流传输方式
* @attention
*/
typedef enum tagIMOSStreamServerMode
{
    IMOS_STREAM_MODE_MS                 = 0,   /**< 指定MS*/
    IMOS_STREAM_MODE_MS_AUTO            = 1,   /**< MS自适应*/
    IMOS_STREAM_MODE_MS_BYPASS          = 2,   /**< 不经过MS */
    IMOS_STREAM_MODE_MS_BYPASS_FIRST    = 3,   /**< 直连优先 */

    IMOS_STREAM_MODE_BUTT
}IMOS_STREAM_SERVER_MODE_E;

/**
* @enum tagIMOSVODStreamServerMode
* @brief 流传输方式
* @attention
*/
typedef enum tagIMOSVODStreamServerMode
{
    IMOS_VOD_STREAM_MODE_MS_NEEDED      = 1,   /**< 自适应经过MS */
    IMOS_VOD_STREAM_MODE_MS_BYPASS      = 2,   /**< 不经过MS*/

    IMOS_VOD_STREAM_MODE_BUTT
}IMOS_VOD_STREAM_SERVER_MODE_E;

/* Begin: Added by luhaitao/01337, 2014-11-12 for 前端录像回放 */
/**
* @enum tagIMOSVODRecordMode
* @brief 录像回放模式
* @attention
*/
typedef enum tagIMOSVODRecordMode
{
    IMOS_VOD_RECORD_MODE_CENTER_DOM     = 0,   /**< 中心域录像回放 */
    IMOS_VOD_RECORD_MODE_FRONT_END      = 1,   /**< 前端录像回放 */

    IMOS_VOD_RECORD_MODE_BUTT
}IMOS_VOD_RECORD_MODE_E;
/* End: Added by luhaitao/01337, 2014-11-12 for 前端录像回放 */

/**
 * @enum tagOutChannelType
 * @brief 输出通道类型
 * @attention 无
 */
typedef enum tagOutChannelType
{
    OUT_CHANNEL_TYPE_VGA        = 0,            /**< VGA */

    OUT_CHANNEL_TYPE_MAX,                       /**< 最大值 */
    OUT_CHANNEL_TYPE_INVALID    = 0xFFFFFFFF,   /**< 无效值 */
} OUT_CHANNEL_TYPE_E;

/**
 * @enum tagOutChannelMode
 * @brief 输出通道模式
 * @attention 无
 */
typedef enum tagOutChannelMode
{
    OUT_CHANNEL_MODE_EXIT_FULL_SCREEN   = 0,            /**< 退出全屏 */
    OUT_CHANNEL_MODE_FULL_SCREEN,                       /**< 放大全屏 */

    OUT_CHANNEL_MODE_MAX,                               /**< 最大值 */
    OUT_CHANNEL_MODE_INVALID            = 0xFFFFFFFF,   /**< 无效值 */
} OUT_CHANNEL_MODE_E;


/**
 * @struct tagVinChnlBindCameraElement
 * @brief 摄像机及其绑定通道变长元素结构体
 * @attention
 */
typedef enum tagVinChnlBindCameraVarietyElementID
{
    /** 场名OSD */
    OSD_NAME_ELEMENT,

    /** 遮盖区域 */
    MASK_AREA_ELEMENT ,

    /** 视频流  */
    VIDEO_STREAM_ELEMENT,

    /** 遮挡检测区域 */
    COVER_DETEC_AREA_ELEMENT,

    /** 运动检测区域 */
    MOTION_DETEC_AREA_ELEMENT,

    VARIETY_ELEMENT_ID_MAX
}VINCHNL_BIND_CAMERA_VARIETY_ELEMENT_ID_E;

/**
* @enum tagReaveStrategy
* @brief 抢占策略定义
* @attention
*/
typedef enum tagReaveStrategy
{
    REV_STRATEGY_PRI_AND_FIR               = 0,          /**< 优先级+同级先来先得 */
    REV_STRATEGY_PRI_AND_SECOND            = 1,          /**< 优先级+同级后来先得 */
    REV_STRATEGY_ONLINE_AND_PRI_AND_FIR    = 2,          /**< 在线用户+优先级+同级先来先得 */
    REV_STRATEGY_ONLINE_AND_PRI_AND_SECOND = 3,          /**< 在线用户+优先级+同级后来先得 */
    REV_STRATEGY_SECOND                    = 4,          /**< 后来先得 */
    REV_STRATEGY_MAX,                                    /**< 最大值 */
    REV_STRATEGY_INVALID                   = 0xFFFFFFFF  /**< 无效值 */
}REAVE_STRATEGY_E;

/**
* @enum tagReaveSrvType
* @brief 抢占策略业务类型定义
* @attention
*/
typedef enum tagReaveSrvType
{
    REV_SRV_MON_AND_VOD     = 0,            /**< 实况类、回放上墙业务 */
    REV_SRV_PTZ             = 1,            /**< 云台业务 */
    REV_SRV_MAX,                            /**< 最大值 */
    REV_SRV_INVALID         = 0xFFFFFFFF    /**< 无效值 */
}REAVE_SRV_TYPE_E;

/**
* @enum tagQueryFaultDeviceInfo
* @brief 故障设备信息查询
* @attention
*/
typedef enum tagQueryFaultDeviceInfo
{
    FDEV_DEV_CODE = 0,      /**< 设备编码#IMOS_CODE_LEN */
    FDEV_DEV_NAME = 1,      /**< 设备名称#IMOS_NAME_LEN */
    FDEV_DEV_TYPE = 2,      /**< 设备类型#ULONG */
    FDEV_DEV_MODEL = 3,     /**< 设备子类型#IMOS_NAME_LEN */
    FDEV_DEV_IPADDR = 4,    /**< 设备地址#IMOS_IPADDR_LEN */
    FDEV_DOMAIN_CODE = 5,   /**< 域编码#IMOS_CODE_LEN */
    FDEV_DOMAIN_NAME = 6,   /**< 域名称#IMOS_NAME_LEN */
    FDEV_FAULT_TIME = 7,    /**< 设备故障时间#IMOS_TIME_LEN */
    FDEV_FAULT_TYPE = 8,    /**< 设备故障类型#ULONG */
    FDEV_MACADDR,           /**< 设备mac地址#IMOS_IPADDR_LEN */
    FDEV_PAR_ORG,           /**< 父组织编码#IMOS_CODE_LEN */
    FDEV_MAX,
}QRY_FAULT_DEV_INFO_E;

/**
* @enum tagQueryFaultDeviceInfo
* @brief 故障设备统计信息
* @attention
*/
typedef enum tagQueryFaultDeviceStat
{
    FDSTAT_DOMAIN_CODE = 0,     /**< 域编码#IMOS_CODE_LEN */
    FDSTAT_DOMAIN_NAME,         /**< 域名称#IMOS_NAME_LEN */
    FDSTAT_DEV_TYPE,            /**< 设备类型#ULONG */
    FDSTAT_DEV_NUM,             /**< 设备总数#ULONG */
    FDSTAT_FAULT_NUM,           /**< 设备故障总数#ULONG */
    FDSTAT_STAT_TIME ,          /**< 设备故障统计时间#IMOS_TIME_LEN */
    FDSTAT_FAULT_RATE ,         /**< 设备故障率#FLOAT */
    FDSTAT_PAR_ORG,             /**< 父组织编码#IMOS_CODE_LEN */
    FDSTAT_MAX,
}QRY_FAULT_DEV_STAT_E;

/**
* @enum tagQueryAssetInfo
* @brief 资产信息
* @attention
*/
typedef enum tagQueryAssetInfo
{
    QRY_ASSET_IMOSID = 0,           /**< 资源ID#IMOS_ID */
    QRY_ASSET_CODE,                 /**< 资产编号#IMOS_CODE_LEN */
    QRY_ASSET_NAME,                 /**< 资产名称#IMOS_NAME_LEN */
    QRY_ASSET_TYPE,                 /**< 资产类型#ULONG */
    QRY_ASSET_MODEL,                /**< 资产型号#IMOS_NAME_LEN */
    QRY_ASSET_STATUS,               /**< 资产状态#ULONG */
    QRY_ASSET_MANUFACTURE,          /**< 资产厂家#IMOS_NAME_LEN */
    QRY_ASSET_PURCHASE_TIME,        /**< 资产采购时间#IMOS_TIME_LEN */
    QRY_ASSET_WARRANT_TIME,         /**< 资产保修时间#IMOS_TIME_LEN */
    QRY_ASSET_INSTALL_TIME,         /**< 资产安装时间#IMOS_TIME_LEN */
    QRY_ASSET_INSTALL_LOCATION,     /**< 资产安装地点#IMOS_NAME_LEN */
    QRY_ASSET_MPERSON,              /**< 维修人员#IMOS_NAME_LEN */
    QRY_ASSET_MTELEPHONE,           /**< 维修电话#IMOS_PHONE_LEN */
    QRY_ASSET_PRODEALER,            /**< 工程商#IMOS_NAME_LEN */
    QRY_ASSET_IPADDR,               /**< 资产MAC地址#IMOS_IPADDR_LEN */
    QRY_ASSET_MACADDR,              /**< 资产MAC地址#IMOS_NAME_LEN */
    QRY_ASSET_DEV_CODE,             /**< 资产设备编码#IMOS_CODE_LEN */
    QRY_ASSET_DEV_NAME,             /**< 资产设备名称#IMOS_NAME_LEN */
    QRY_ASSET_DOMAIN_CODE,          /**< 域编码#IMOS_CODE_LEN */
    QRY_ASSET_DOMAIN_NAME,          /**< 域名称#IMOS_NAME_LEN */
    QRY_ASSET_PARENT_ORG,           /**< 资产父组织#IMOS_CODE_LEN */
    QRY_ASSET_COUNT,                /**< 资产统计数量#IMOS_NAME_LEN */
    QRY_ASSET_MAX,
}QRY_ASSET_INFO_E;


#if 0
/**
* @enum tagQueryAssetStat
* @brief 资产统计信息
* @attention
*/
typedef enum tagQueryAssetStat
{
    ASSETSTAT_COUNT,                /**< 资产统计数量#ULONG */
    ASSETSTAT_TYPE,                 /**< 资产类型#ULONG */
    ASSETSTAT_STATUS,               /**< 资产状态#ULONG */
    ASSETSTAT_DOMAIN_CODE,          /**< 域编码#IMOS_CODE_LEN */
    ASSETSTAT_ORG1_NAME,            /**< 一层组织名称#IMOS_NAME_LEN */
    ASSETSTAT_ORG2_NAME,            /**< 二层组织名称#IMOS_NAME_LEN */
    ASSETSTAT_ORG3_NAME,            /**< 三层组织名称#IMOS_NAME_LEN */
    ASSETSTAT_MAX,
}QRY_ASSET_STAT_E;
#endif

/**
* @enum tagAssetType
* @brief 资产类型枚举
* @attention
*/
typedef enum tagAssetType
{
    ASSET_TYPE_ALL              = 0,            /**< 所有 */
    ASSET_TYPE_SERVER           = 1,            /**< 服务器 */

    ASSET_TYPE_FIX_CAMERA       = 5,            /**< 固定摄像机 */
    ASSET_TYPE_PTZ_CAMERA       = 6,            /**< 云台摄像机 */
    ASSET_TYPE_FIX_CAMERA_HD    = 7,            /**< 高清固定摄像机 */
    ASSET_TYPE_PTZ_CAMERA_HD    = 8,            /**< 高清云台摄像机 */
    ASSET_TYPE_CAR_CAMERA       = 9,            /**< 车载摄像机 */


    ASSET_TYPE_DM               = 11,           /**< DM */
    ASSET_TYPE_MS               = 12,           /**< MS */
    ASSET_TYPE_VX500            = 13,           /**< VX500 */

    ASSET_TYPE_MONITOR          = 14,           /**< 监视器 */
    ASSET_TYPE_EC               = 15,           /**< 编码器 */
    ASSET_TYPE_DC               = 16,           /**< 解码器 */
    ASSET_TYPE_GENERAL          = 17,           /**< 通用设备 */
    ASSET_TYPE_ECR              = 18,           /**< ECR */

    ASSET_TYPE_TMS              = 30,           /**< 交通媒体交换服务器 */
    ASSET_TYPE_TOLLGATE         = 31,           /**< 卡口 */

    /* 新增的摄像机类型，从501开始 */
    ASSET_TYPE_VIRTUAL              = 501,      /**< 虚拟摄像机 */
    ASSET_TYPE_BALL_NOT_CONTROL     = 502,      /**< 不可控标清球机 */
    ASSET_HD_TYPE_BALL_NOT_CONTROL  = 503,      /**< 不可控高清球机 */
    ASSET_TYPE_SAFE_VM_CAMERA       = 504,      /**< 隔离视频接入摄像机 */
    ASSET_TYPE_SAFE_DVR_CAMERA      = 505,      /**< DVR视频接入摄像机 */
    ASSET_TYPE_SAFE_MATRIX_CAMERA   = 506,      /**< 矩阵视频接入摄像机 */

    ASSET_TYPE_CAMERA           = 1001,         /**< 摄像机 */
    ASSET_TYPE_AUDIO            = 1002,         /**< 识音器 */
    ASSET_TYPE_IPSAN            = 1004,         /**< IPSAN */
    ASSET_TYPE_TOLLGATE_CAMERA  = 1005,         /**< 卡口相机 */

    ASSET_TYPE_BM               = 1300,         /**< BM */
    /* Begin added by y01359, 2015-08-18 for A8 */
    ASSET_TYPE_A8               = 1500,         /**< A8设备 */
    /* End added by y01359, 2015-08-18 for A8 */
    ASSET_TYPE_MAX,                             /**< 资产类型枚举最大值 */
    ASSET_TYPE_INVALID          = 0xFFFF        /**< 无效值 */
}ASSET_TYPE_E;

/**
* @enum tagAssetStatus
* @brief 资产状态枚举
* @attention
*/
typedef enum tagAssetStatus
{
    ASSET_STATUS_NORMAL      = 0,            /**< 运行 */
    ASSET_STATUS_FAULT       = 1,            /**< 损坏 */
    ASSET_STATUS_REPAIR      = 2,            /**< 维修 */
    ASSET_STATUS_RETIREMENT  = 3,            /**< 报废 */
    ASSET_STATUS_STOCK       = 4,            /**< 库存 */
    ASSET_STATUS_TOINSTALL   = 5,            /**< 待安装 */
    ASSET_STATUS_INSTALLED   = 6,            /**< 已安装 */
    ASSET_STATUS_DEBUGGED    = 7,            /**< 已调试 */

    ASSET_STATUS_MAX,                        /**< 资产状态枚举最大值 */
    ASSET_STATUS_INVALID     = 0xFF          /**< 无效值 */
}ASSET_STATUS_E;

/**
* @enum tagDevAssetBindPolicy
* @brief 设备资产绑定策略枚举
* @attention
*/
typedef enum tagDevAssetBindPolicy
{
    DEVASSET_BINDPOLICY_SEPARATE       = 0,       /**< 设备资产独立录入 */
    DEVASSET_BINDPOLICY_BIND           = 1,       /**< 设备资产绑定录入 */

    DEVASSET_BINDPOLICY_MAX,                      /**< 设备资产绑定策略枚举最大值 */
    DEVASSET_BINDPOLICY_INVALID        = 0xFF     /**< 无效值 */
}DEVASSET_BINDPOLICY_E;

/**
* @enum tagAssetQueryType
* @brief 资产查询方式枚举
* @attention
*/
typedef enum tagAssetQueryType
{
    ASSET_QUERY_TYPE_DEVCODE       = 1,       /**< 根据设备编码查询资产 */
    ASSET_QUERY_TYPE_ASSETCODE     = 2,       /**< 根据资产编号查询资产 */

    ASSET_QUERY_TYPE_MAX,                     /**< 资产查询方式枚举最大值 */
    ASSET_QUERY_TYPE_INVALID       = 0xFF     /**< 无效值 */
}ASSET_QUERY_TYPE_E;


/**
* @enum tagStatisticServiceType
* @brief 统计业务类型枚举
* @attention
*/
typedef enum tagStatisticServiceType
{
    STATISTIC_SERVICE_TYPE_ASSET   = 0,         /**< 资产统计 */
    STATISTIC_SERVICE_TYPE_FAULT   = 1,         /**< 故障统计 */
    STATISTIC_SERVICE_TYPE_DETAIL  = 2,         /**< 故障详情 */

    STATISTIC_SERVICE_TYPE_MAX,                 /**< 统计业务类型枚举最大值 */
    STATISTIC_SERVICE_TYPE_INVALID = 0xFF      /**< 无效值 */
}STATISTIC_SERVICE_TYPE_E;


/**
* @enum tagStatisticClassificationType
* @brief 统计分类类型枚举
* @attention
*/
typedef enum tagStatisticClassificationType
{
    STATISTIC_CLASSIFICATION_ASSETTYPE   = 0,         /**< 按资产类型分类统计 */
    STATISTIC_CLASSIFICATION_ASSETMODEL  = 1,         /**< 按资产型号分类统计 */

    STATISTIC_CLASSIFICATION_MAX,                     /**< 统计分类类型枚举最大值 */
    STATISTIC_CLASSIFICATION_INVALID = 0xFF           /**< 无效值 */
}STATISTIC_CLASSIFICATION_TYPE_E;

/**
* @enum tagSyncServiceType
* @brief 同步业务类型枚举
* @attention
*/
typedef enum tagSyncServiceType
{
    SYNCSRV_TYPE_ASSET_STATISTIC   = 0,         /**< 同步资产统计 */
    SYNCSRV_TYPE_FAULT_STATISTIC   = 1,         /**< 同步故障统计 */

    SYNCSRV_TYPE_MAX,                           /**< 同步业务类型枚举最大值 */
    SYNCSRV_TYPE_INVALID = 0xFF                 /**< 无效值 */
}SYNCSRV_TYPE_E;

/**
* @enum tagSyncSrvMode
* @brief 同步模式类型枚举
* @attention
*/
typedef enum tagSyncSrvMode
{
    SYNCSRV_MODE_INCREMENT   = 0,                /**< 增量同步 */
    SYNCSRV_MODE_TOTAL       = 1,                /**< 全量同步 */

    SYNCSRV_MODE_MAX,                           /**< 同步模式枚举最大值 */
    SYNCSRV_MODE_INVALID = 0xFF                 /**< 无效值 */
}SYNCSRV_MODE_E;

/**
* @enum tagSplitScrMode
* @brief 监视器分屏模式
* @attention
*/
typedef enum tagSplitScrMode
{
    SPLIT_SCR_MODE_0    = 0,    /**< 保留字符 */
    SPLIT_SCR_MODE_1    = 1,    /**< 全屏 */
    SPLIT_SCR_MODE_2    = 2,    /**< 2 分屏*/
    SPLIT_SCR_MODE_3    = 3,    /**< 3 分屏*/
    SPLIT_SCR_MODE_4    = 4,    /**< 4分屏 */
    SPLIT_SCR_MODE_5    = 5,    /**< 5 分屏*/
    SPLIT_SCR_MODE_6    = 6,    /**< 6分屏 */
    SPLIT_SCR_MODE_7    = 7,    /**< 7 分屏*/
    SPLIT_SCR_MODE_8    = 8,    /**< 8 分屏 */
    SPLIT_SCR_MODE_9    = 9,    /**< 9 分屏 */
    SPLIT_SCR_MODE_10   = 10,   /**< 10 分屏 */
    SPLIT_SCR_MODE_11   = 11,    /**< 11 分屏*/
    SPLIT_SCR_MODE_12   = 12,    /**< 12 分屏*/
    SPLIT_SCR_MODE_13   = 13,   /**< 13 分屏 */
    SPLIT_SCR_MODE_14   = 14,    /**< 14 分屏*/
    SPLIT_SCR_MODE_15   = 15,    /**< 15 分屏*/
    SPLIT_SCR_MODE_16   = 16,   /**< 16 分屏 */
    SPLIT_SRC_MODE_25   = 25,   /**< 25分屏*/
    SPLIT_SRC_MODE_36   = 36,   /**< 36分屏*/

    SPLIT_SCR_MODE_MAX,                     /**< 最大值 */

    /* Begin modified by l01420 for MPPD08374, 2014-4-8 */
    /**<SPLIT_SCR_MODE_MAX枚举值以上定义最新分屏数的模式，
    以下所定义的值表示特殊的分屏模式(分屏数重复，模式不同)*/
    SPLIT_SCR_MODE_80    = 80,    /**< 8 分屏 走廊模式 */

    SPLIT_SCR_MODE_LIMIT_VALUE ,/**<分屏模式最大值*/
    /* End modified by l01420 for MPPD08374, 2014-4-8 */

    SPLIT_SCR_MODE_INVALID  = 0xFFFFFFFF    /**< 无效值 */
} SPLIT_SCR_MODE_E;

/**
 * @struct tagECRServerModeType
 * @brief ECR设备管理模式类型
 * @attention
 */
typedef enum tagECRServerModeInfo
{
    ECR_SERVER_MODE_TYPE_INDEPENDENT = 0,  /**< 独立运行模式 */
    ECR_SERVER_MODE_TYPE_SERVER = 1,       /**< 服务器管理模式 */

    ECR_SERVER_MODE_TYPE_MAX,              /**< 管理模式最大值 */
    ECR_SERVER_MODE_TYPE_INVALID = 0xFF
}ECR_SERVER_MODE_TYPE_E;

/**
* 视频配置
*/
/**
* @enum     tagOnvifVideoEncoding
* @brief    ONVIF 视频编码
* @attention
*/
typedef enum tagOnvifVideoEncoding
{
    ONVIF_VIDEO_ENCODER_JPEG = 0,           /**< JEPG */
    ONVIF_VIDEO_ENCODER_MPEG4,              /**< MPEG4 */
    ONVIF_VIDEO_ENCODER_H264,               /**< H264 */
    ONVIF_VIDEO_ENCODER_MAX,
    ONVIF_VIDEO_ENCODER_INVALID = 0xFFFF
}ONVIF_VIDEO_ENCODING_E;

/**
* @enum     tagOnvifH264Profile
* @brief    ONVIF H264 profile
* @attention
*/
typedef enum tagOnvifH264Profile
{
    ONVIF_VIDEO_H264_BASELINE = 0,          /**< baseline */
    ONVIF_VIDEO_H264_MAIN,                  /**< main */
    ONVIF_VIDEO_H264_EXTENDED,              /**< extended */
    ONVIF_VIDEO_H264_HIGH,                  /**< high */
    ONVIF_VIDEO_H264_MAX,
    ONVIF_VIDEO_H264_INVALID = 0xFFFF
}ONVIF_VIDEO_H264_PROFILE_E;

/**
* 音频配置
*/

/**
* @enum     tagOnvifAudioEncoding
* @brief    ONVIF 视频编码
* @attention
*/
typedef enum tagOnvifAudioEncoding
{
    ONVIF_AUDIO_ENCODER_G711 = 0,           /**< G711 */
    ONVIF_AUDIO_ENCODER_G726,               /**< G726 */
    ONVIF_AUDIO_ENCODER_AAC,                /**< AAC */
    ONVIF_AUDIO_ENCODER_MAX,
    ONVIF_AUDIO_ENCODER_INVALID = 0xFFFF
}ONVIF_AUDIO_ENCODING_E;

/**
* 图像参数配置
*/

/**
* @enum     tagOnvifBacklightCompensationMode
* @brief    ONVIF 曝光模式
* @attention
*/
typedef enum tagOnvifBacklightCompensationMode
{
    ONVIF_BACKLIGHT_COMPENSATION_MODE_OFF = 0,          /**< OFF */
    ONVIF_BACKLIGHT_COMPENSATION_MODE_ON,               /**< ON */
    ONVIF_BACKLIGHT_COMPENSATION_MODE_MAX,
    ONVIF_BACKLIGHT_COMPENSATION_MODE_INVALID = 0xFFFF
}ONVIF_BACKLIGHT_COMPENSATION_MODE_E;

/**
* @enum     tagOnvifExposureMode
* @brief    ONVIF 曝光模式
* @attention
*/
typedef enum tagOnvifExposureMode
{
    ONVIF_EXPOSURE_MODE_AUTO = 0,           /**< 自动曝光 */
    ONVIF_EXPOSURE_MODE_MANUAL,             /**< 手动曝光 */
    ONVIF_EXPOSURE_MODE_MAX,
    ONVIF_EXPOSURE_MODE_INVALID = 0xFFFF
}ONVIF_EXPOSURE_MODE_E;

/**
* @enum     tagOnvifExposurePriority
* @brief    ONVIF 曝光优先级
* @attention
*/
typedef enum tagOnvifExposurePriority
{
    ONVIF_EXPOSURE_PRIORITY_LOW_NOISE = 0,          /**< 低噪声优先 */
    ONVIF_EXPOSURE_PRIORITY_FRAME_RATE,             /**< 帧率优先 */
    ONVIF_EXPOSURE_PRIORITY_MAX,
    ONVIF_EXPOSURE_PRIORITY_INVALID = 0xFFFF
}ONVIF_EXPOSURE_PRIORITY_E;

/**
* @enum     tagOnvifFocusMode
* @brief    ONVIF 聚焦模式
* @attention
*/
typedef enum tagOnvifFocusMode
{
    ONVIF_FOCUS_MODE_AUTO = 0,           /**< 自动聚焦 */
    ONVIF_FOCUS_MODE_MANUAL,             /**< 手动聚焦 */
    ONVIF_FOCUS_MODE_MAX,
    ONVIF_FOCUS_MODE_INVALID = 0xFFFF
}ONVIF_FOCUS_MODE_E;

/**
* @enum     tagOnvifIrCutFilter
* @brief    ONVIF 红外截止滤光
* @attention
*/
typedef enum tagOnvifIrCutFilter
{
    ONVIF_INFRARED_CUTOFF_FILTER_ON = 0,            /**< 打开 */
    ONVIF_INFRARED_CUTOFF_FILTER_OFF,               /**< 关闭 */
    ONVIF_INFRARED_CUTOFF_FILTER_AUTO,              /**< 自动 */
    ONVIF_INFRARED_CUTOFF_FILTER_MAX,
    ONVIF_INFRARED_CUTOFF_FILTER_INVALID = 0xFFFF
}ONVIF_INFRARED_CUTOFF_FILTER_E;

/**
* @enum     tagOnvifWideDynamicMode
* @brief    ONVIF WDR模式
* @attention
*/
typedef enum tagOnvifWideDynamicMode
{
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_OFF = 0,          /**< 关闭 */
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_ON,               /**< 打开 */
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_MAX,
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_INVALID = 0xFFFF
}ONVIF_WIDE_DYNAMIC_RANGE_MODE_E;

/**
* @enum     tagOnvifWideDynamicMode
* @brief    ONVIF 白平衡模式
* @attention
*/
typedef enum tagOnvifWhiteBalanceMode
{
    ONVIF_WHITE_BALANCE_MODE_AUTO = 0,          /**< 自动白平衡 */
    ONVIF_WHITE_BALANCE_MODE_MANUAL,            /**< 手动白平衡 */
    ONVIF_WHITE_BALANCE_MODE_MAX,
    ONVIF_WHITE_BALANCE_MODE_INVALID = 0xFFFF
}ONVIF_WHITE_BALANCE_MODE_E;

/**
* ONVIF OSD相关定义
*/
/**
* @enum     tagOnvifOSDType
* @brief    OSD类型
* @attention
*/
typedef enum tagOnvifOSDType
{
    ONVIF_OSD_TYPE_TEXT = 0,            /**< 文本 */
    ONVIF_OSD_TYPE_IMAGE,               /**< 图片 */
    ONVIF_OSD_TYPE_MAX,
    ONVIF_OSD_TYPE_INVALID = 0xFFFF
}ONVIF_OSD_TYPE_E;

/**
* @enum     tagOnvifOSDTextStringType
* @brief    ONVIF OSD text类型
* @attention
*/
typedef enum tagOnvifOSDTextStringType
{
    ONVIF_OSD_TEXT_STRING_TYPE_PLAIN = 0,          /**< 普通文本 */
    ONVIF_OSD_TEXT_STRING_TYPE_DATE,               /**< 日期 */
    ONVIF_OSD_TEXT_STRING_TYPE_TIME,               /**< 时间 */
    ONVIF_OSD_TEXT_STRING_TYPE_DATE_TIME,          /**< 日期+时间 */
    ONVIF_OSD_TEXT_STRING_TYPE_MAX,
    ONVIF_OSD_TEXT_STRING_TYPE_INVALID = 0xFFFF
}ONVIF_OSD_TEXT_STRING_TYPE_E;

/**
* @enum     tagMwStdOnvifIPType
* @brief    onvif IP 类型
* @attention
*/
typedef enum tagOnvifIPType
{
    ONVIF_TYPE_IPV4 = 0,             /**< ipv4 */
    ONVIF_TYPE_IPV6,                 /**< ipv6 */
    ONVIF_TYPE_INVALID = 0xFFFF
}ONVIF_IP_TYPE_E;

#ifdef  __cplusplus
}

/**
* @enum tagMapType
* @brief 地图类型枚举
* @attention
*/
typedef enum tagMapType
{
    MAP_TYPE_JPG   = 0,    /**< JPG地图 */
    MAP_TYPE_SVG,          /**< SVG地图 */
    MAP_TYPE_JPEG,         /**< JPEG地图 */
    MAP_TYPE_BMP,          /**< BMP地图 */
    MAP_TYPE_SHP,          /**< SHP地图 */

    MAP_TYPE_MAX,          /**< 目前支持的地图类型最大值 */
    MAP_TYPE_INVALID    = 0xFFFFFFFF,   /**< 无效值 */
}MAP_TYPE_E;

/**
* @enum tagDomainSynServiceType
* @brief 域间同步的业务类型枚举
* @attention
*/
typedef enum tagDomainSynServiceType
{
    DOMAIN_SYN_TOPO_FILE = 1,   /**< 监控文件 */
    DOMAIN_SYN_TOPO_SRVNUM,     /**< 业务信息 */
    DOMAIN_SYN_DEV_FAULT,       /**< 设备故障详情信息 */
    DOMAIN_SYN_FAULT_DEV,       /**< 故障设备统计 */
    DOMAIN_SYN_ASSET,           /**< 资产信息 */

    DOMAIN_SYN_MAX,             /**< 同步业务类型最大值 */
    DOMAIN_SYN_INVALID = 0XFF
}DOMAIN_SYN_SRVTYPE_E;

/**
* @enum tagIMOSSystemParamType
* @brief 系统参数类型
* @attention
*/
typedef enum tagIMOSSystemParamType
{
    ALARM_LINKAGE_MONITOR_RESUME_ENABLE       = 1,                /**< 告警联动至监视器的恢复开关 */
    ALARM_LINKAGE_MONITOR_RESUME_TIME         = 2,                /**< 告警联动至监视器的恢复时间, 单位:秒 */
    SYS_PARAM_PLATE_CODE_PREFIX               = 3,                /**< 车牌号码前缀 */
    SYS_PARAM_VEHICLE_ALARM_PHOTO_FULL_POLICY = 4,                /**< 过车告警图片满策略:0-满停止、1-满覆盖 */
    SYS_PARAM_VEHICLE_ALARM_RECORD_BACKUP_ENABLE = 5,             /**< 违法录像备份使能 */
    SYS_PARAM_VEHICLE_RECORD_BEFORE_TIME         = 6,             /**< 过车前录像回放秒数 */
    SYS_PARAM_VEHICLE_RECORD_AFTER_TIME          = 7,             /**< 过车后录像回放秒数 */
    SYS_PARAM_TMS_BIGDATA_REALTIME_INDEX         = 8,             /**< 大数据实时索引使能 */
    SYS_PARAM_TMS_REV_BUFFER                     = 9,             /**< TMS数据接收优先级 */
    SYS_PARAM_TMS_COMBINE_PIC_TYPE               = 10,            /**< TMS人脸合成图片数量配置 */

    SYS_PARAM_ONVIF_SERVER_USER                  = 11,            /**< onvif server 用户名 */
    SYS_PARAM_ONVIF_SERVER_PASSWD                = 12,            /**< onvif server 密码 */
    SYS_PARAM_ONVIF_SERVER_BIND_MS               = 13,            /**< onvif server 绑定ms */

	SYS_PARAM_AUTO_RETRY_BACK_TASK               = 14,            /**<补备任务自动调度 */

    SYS_PARAM_MAX,                                              /**< 最大值 */
    SYS_PARAM_INVALID                       = 0xFFFF            /**< 无效值 */
}IMOS_SYS_PARAM_TYPE_E;

/**
* @enum tagVocEventType
* @brief 语音通知事件的类型
* @attention 无
*/
typedef enum tagVocEventType
{
    VOC_EVENT_TYPE_USER_STOP       = 0,   /**< 语音业务用户停止 */
    VOC_EVENT_TYPE_REAVE           = 1,   /**< 语音业务抢占 */
    VOC_EVENT_TYPE_SERVER_STOP     = 2,   /**< 语音业务服务器端主动停止 */
    VOC_EVENT_TYPE_SERVER_BE_STOP  = 3,   /**< 语音业务服务器端被动停止 */

    VOC_EVENT_TYPE_MAX,
    VOC_EVENT_TYPE_INVALID = 0xFFFFFFFF
}VOC_EVENT_TYPE_E;

/**
* @enum tagVocEventType
* @brief 语音业务状态
* @attention 无
*/
typedef enum tagVocSrvStatus
{
    VOCSRV_STATUS_IDLE    = 0,    /**< 没有语音业务 */
    VOCSRV_STATUS_SETUP   = 1,    /**< 语音业务正在建立中 */
    VOCSRV_STATUS_ACTIVE  = 2,    /**< 语音业务建立成功 */

    VOCSRV_STATUS_MAX,
    VOCSRV_STATUS_INVALID = 0xFFFFFFFF
}VOCSRV_STATUS_E;

/**
* @enum tagAlarmRecordType
* @brief 告警处理记录类型
* @attention
*/
typedef enum tagAlarmRecordType
{
    ALARM_RECORD_TYPE_TRIGGER           = 1,    /**< 触发器 */
    ALARM_RECORD_TYPE_EXECUTE_TASK      = 2,    /**< 执行任务 */
    ALARM_RECORD_TYPE_CANCEL_TASK       = 3,    /**< 取消任务 */
    ALARM_RECORD_TYPE_PLAN_ALARM_PUSH   = 4,    /**< 预案告警推送 */
    ALARM_RECORD_TYPE_ALARM_NEW_ALARM   = 5,    /**< 产生新告警 */
    ALARM_RECORD_TYPE_PLAN_BEGIN        = 6,    /**< 预案产生 */
    ALARM_RECORD_TYPE_PLAN_END          = 7,    /**< 预案结束 */

    ALARM_RECORD_TYPE_MAX,
    ALARM_RECORD_TYPE_INVALID = 0xFFFFFFFF
}ALARM_RECORD_TYPE_E;


/**
* @enum tagActionPlanType
* @brief 预案类型
* @attention
*/
typedef enum tagActionPlanType
{
    ACTION_PLAN_TYPE_ALARM = 1,                /**< 告警预案 */
    ACTION_PLAN_TYPE_COMMON = 2,               /**< 通用预案 */

    ACTION_PLAN_TYPE_MAX,                      /**< 最大值 */
    ACTION_PLAN_TYPE_INVALID = 0xFFFFFFFF      /**< 无效值 */
}ACTION_PLAN_TYPE_E;

/**
* @enum tagAlarmStatus
* @brief 告警状态
* @attention
*/
typedef enum tagAlarmStatus
{
    ALARM_STATUS_NOT_CONFIRM            = 0,    /**< 未确认 */
    ALARM_STATUS_ALREADY_CONFIRM        = 1,    /**< 已确认 */
    ALARM_STATUS_NOT_CHECK              = 2,    /**< 未核警 */
    ALARM_STATUS_ALREADY_CHECK          = 3,    /**< 已核警 */

    ALARM_STATUS_MAX,
    ALARM_STATUS_INVALID = 0xFFFFFFFF
}ALARM_STATUS_E;


/**
* @enum tagTaskDealMode
* @brief 任务处理模式
* @attention
*/
typedef enum tagTaskDealMode
{
    TASK_DEAL_MODE_EXECUTE          = 1,    /**< 执行任务 */
    TASK_DEAL_MODE_CANCEL           = 2,    /**< 取消任务 */

    TASK_DEAL_MODE_MAX,
    TASK_DEAL_MODE_INVALID = 0xFFFFFFFF
}TASK_DEAL_MODE_E;

/**
* @enum tagPlanAlarmChgType
* @brief 预案告警变化推送类型
* @attention
*/
typedef enum tagPlanAlarmChgType
{
    PLAN_ALARM_CHG_TYPE_ADD             = 1,    /**< 预案告警新增 */
    PLAN_ALARM_CHG_TYPE_TASK_CHG        = 2,    /**< 预案告警任务变化 */
    PLAN_ALARM_CHG_TYPE_DEL             = 3,    /**< 预案告警删除 */

    PLAN_ALARM_CHG_TYPE_MAX,
    PLAN_ALARM_CHG_TYPE_INVALID = 0xFFFFFFFF
}PLAN_ALARM_CHG_TYPE_E;

/**
* @enum tagPlanExecStrategy
* @brief 预案执行策略
* @attention
*/
typedef enum tagPlanExecStrategy
{
    PLAN_EXEC_STRATEGY_STRICT_ORDER     = 1,    /**< 严格顺序执行 */
    PLAN_EXEC_STRATEGY_RAND_ORDER       = 2,    /**< 任意次序执行 */
    PLAN_EXEC_STRATEGY_AUTO_CANCEL_TASK = 3,    /**< 自动取消前面未执行任务 */

    PLAN_EXEC_STRATEGY_MAX,
    PLAN_EXEC_STRATEGY_INVALID = 0xFFFFFFFF
}PLAN_EXEC_STRATEGY_E;

/**
* @enum tagTaskExecStrategy
* @brief 任务执行策略
* @attention
*/
typedef enum tagTaskExecStrategy
{
    TASK_EXEC_STRATEGY_AUTO             = 1,    /**< 自动 */
    TASK_EXEC_STRATEGY_MANUAL_YES       = 2,    /**< 手动默认执行 */
    TASK_EXEC_STRATEGY_MANUAL_NO        = 3,    /**< 手动默认不执行 */

    TASK_EXEC_STRATEGY_MAX,
    TASK_EXEC_STRATEGY_INVALID = 0xFFFFFFFF
}TASK_EXEC_STRATEGY_E;

/**
* @enum tagTriggerID
* @brief 触发器ID
* @attention
*/
typedef enum tagTriggerID
{
    TRIGGER_ID_CONFIRM          = 1,    /**< 确认 */
    TRIGGER_ID_INFORM           = 2,    /**< 核警为非误报 */
    TRIGGER_ID_MISINFORM        = 3,    /**< 核警为误报 */
    TRIGGER_ID_IMMEDIATELY      = 4,    /**< 立即 */
    TRIGGER_ID_TIMING           = 5,    /**< 定时 */

    TRIGGER_ID_MAX,
    TRIGGER_ID_INVALID = 0xFFFFFFFF
}TRIGGER_ID_E;

/**
* @enum tagQuerySysInfoName
* @brief 查询系统信息名字
* @attention
*/
typedef enum tagQuerySysInfoName
{
    QUERY_SYS_TIME              = 1,    /**< 时间（格式为"YYYY-MM-DD HH:MM:SS"）*/
    QUERY_SYS_CPU_USAGE         = 2,    /**< cpu使用率（类型为FLOAT，保留小数点后三位）*/
    QUERY_SYS_MEM_TOTAL         = 3,    /**< 内存总数（类型为ULONG，单位为KB）*/
    QUERY_SYS_MEM_USAGE         = 4,    /**< 内存使用率（类型为FLOAT，保留小数点后三位）*/

    QUERY_SYS_INFO_NAME_MAX,
    QUERY_SYS_INFO_NAME_INVALID = 0xFFFFFFFF
}QUERY_SYS_INFO_NAME_E;


/** @brief 拉框放大协议类型 */
typedef enum tagZoomProtocol
{
    ZOOM_GENERAL          = 0,                      /**通用协议*/
    ZOOM_SPECIAL          = 1,                      /**专用协议*/
    ZOOM_GONGAN           = 2,                      /**公安协议*/
    ZOOM_INTELLIGENT      = 3,                      /**智能协议*/

    ZOOM_PROTOCOL_MAX,                              /** 最大值*/
    ZOOM_PROTOCOL_MAX_INVALID = 0xFFFFFFFF
}ZOOM_PROTOCOL_E;

/**
* @enum tagMonFavStreamAnyMatchPolicy
* @brief 实况自适应主辅流的匹配策略
* @attention 本域默认主流优先, 跨域默认辅流优先
*/
typedef enum tagMonFavStreamAnyMatchPolicy
{
    MON_STREAM_ANY_MATCH_SEC_FIRST = 0,                 /**< 辅流优先, 匹配次序:辅流、三流、主流 */
    MON_STREAM_ANY_MATCH_PRI_FIRST = 1,                 /**< 主流优先, 匹配次序:主流、辅流、三流 */
    MON_STREAM_ANY_MATCH_THD_FIRST = 2,                 /**< 三流优先, 匹配次序:三流、辅流、主流 */
    MON_STREAM_ANY_MATCH_BUTT
}MON_STREAM_ANY_MATCH_POLICY_E;

/**
* @enum tagMCastAddrStreamPolicy
* @brief 组播地址的主辅流选择策略
* @attention 默认主流使用组播地址
*/
typedef enum tagMCastAddrStreamPolicy
{
    MCAST_ADDR_STREAM_POLICY_PRI = 0,                   /**< 仅主流使用组播地址 */
    MCAST_ADDR_STREAM_POLICY_SEC = 1,                   /**< 仅辅流使用组播地址, 无辅流情况下, 主流使用组播地址 */
    MCAST_ADDR_STREAM_POLICY_THD = 2,                   /**< 仅三流使用组播地址, 无三流情况下, 主流使用组播地址 */
    MCAST_ADDR_STREAM_POLICY_BUTT
}MCAST_ADDR_STREAM_POLICY_E;

/**
* @enum tagMCastAddrStreamPolicy
* @brief 第二个组播地址的主辅流选择策略
* @attention 默认关闭
*/
typedef enum tagSecondMCastAddrStreamPolicy
{
    SECOND_MCAST_ADDR_STREAM_POLICY_CLOSED = 0,
    SECOND_MCAST_ADDR_STREAM_POLICY_PRI = 1,                   /**< 主流使用组播地址 */
    SECOND_MCAST_ADDR_STREAM_POLICY_SEC = 2,                   /**< 辅流使用组播地址 */
    SECOND_MCAST_ADDR_STREAM_POLICY_THD = 3,                   /**< 三流使用组播地址 */
    SECOND_MCAST_ADDR_STREAM_POLICY_BUTT
}SECOND_MCAST_ADDR_STREAM_POLICY_E;

/**
* @enum tagDomainStreamPullType
* @brief 域间引流标识类型
* @attention
*/
typedef enum tagDomainStreamPullType
{
    DOMAIN_STREAM_PULL_NONE         = 0,    /**< 不引流 */
    DOMAIN_STREAM_PULL_IN           = 1,    /**< 引流 */
    DOMAIN_STREAM_PULL_OUT          = 2,    /**< 反向引流(上级域在Nat内的情况) */
    DOMAIN_STREAM_PULL_AND_URL_EX   = 3,    /**< 引流支持回放URL替换(下级域拨号接入，IP地址动态变化，该项配置后下级域所在DM的回放Nat配置无效 */
    DOMAIN_STREAM_PULL_DOUBLE_NAT_OUT         = 4,   /**< 双私网(下级域做双私网引流服务端和TCP的服务端)，其他处理相当与外域在NAT外(重庆4S店模型) */
    DOMAIN_STREAM_PULL_DOUBLE_NAT_IN          = 5,   /**< 双私网(下级域做双私网引流客户端和TCP的客户端)，其他处理相当与外域在NAT内(全国邮政模型)*/
	DOMAIN_STREAM_PULL_BUTT

}DOMAIN_STREAM_PULL_TYPE;


/**
* @enum tagXPStreamPullType
* @brief XP引流标识类型
* @attention
*/
typedef enum tagXPStreamPullType
{
    XP_STREAM_PULL_AUTO         = 0,    /**< 自适应 */
	XP_STREAM_PULL_NONE         = 1,    /**< 不引流 */
    XP_STREAM_PULL_IN           = 2,    /**< 引流 */
    XP_STREAM_PULL_OUT          = 3,    /**< 反向引流(上级域在Nat内的情况) */
    XP_STREAM_PULL_AND_URL_EX   = 4,    /**< 引流支持回放URL替换(下级域拨号接入，IP地址动态变化，该项配置后下级域所在DM的回放Nat配置无效 */
    XP_STREAM_PULL_DOUBLE_NAT_OUT         = 5,   /**< 双私网(下级域做双私网引流服务端和TCP的服务端)，其他处理相当与外域在NAT外(重庆4S店模型) */
    XP_STREAM_PULL_DOUBLE_NAT_IN          = 6,   /**< 双私网(下级域做双私网引流客户端和TCP的客户端)，其他处理相当与外域在NAT内(全国邮政模型)*/
	XP_STREAM_PULL_BUTT

}XP_STREAM_PULL_TYPE;


/** @brief 协议告警类型的告警状态 */
typedef enum tagProtocolAlarmStatus
{
    PROTOCOL_ALARM_STATUS_RECOVER          = 0,     /** 恢复 */
    PROTOCOL_ALARM_STATUS_CREATE           = 1,     /** 产生 */

    PROTOCOL_ALARM_STATUS_MAX,                    /** 最大值*/
    PROTOCOL_ALARM_STATUS_INVALID = 0xFFFFFFFF
}PROTOCOL_ALARM_STATUS_E;


/**
* @enum tagEventSecurityChgType
* @brief 事件级别信息变化推送类型
* @attention
*/
typedef enum tagEventSecurityChgType
{
    EVENT_SECURITY_CHG_TYPE_ADD             = 1,    /**< 事件级别新增 */
    EVENT_SECURITY_CHG_TYPE_MOD             = 2,    /**< 事件级别修改 */
    EVENT_SECURITY_CHG_TYPE_DEL             = 3,    /**< 事件级别删除 */

    EVENT_SECURITY_CHG_TYPE_MAX,
    EVENT_SECURITY_CHG_TYPE_INVALID = 0xFFFFFFFF
}EVENT_SECURITY_CHG_TYPE_E;

/**
* @enum tagAssetStatus
* @brief 案件性质枚举
* @attention
*/
typedef enum tagCaseProperty
{
    CASE_PROPERTY_CASE_PUBSECURITY      = 0,     /**< 治安 */
    CASE_PROPERTY_CASE_CRIMINAL         = 1,     /**< 刑事 */
    CASE_PROPERTY_POLICE_INTELLIGENCE   = 2,     /**< 警情 */

    CASE_PROPERTY_MAX,                           /**< 案件性质枚举最大值 */
    CASE_PROPERTY_INVALID     = 0xFF             /**< 无效值 */
}CASE_PROPERTY_E;


/**
* @enum tagCaseType
* @brief 案件类型枚举
* @attention
*/
typedef enum tagCaseType
{
    CASE_TYPE_THEFT                 = 0,     /**< 偷窃 */
    CASE_TYPE_ROBBERY               = 1,     /**< 抢劫 */
    CASE_TYPE_FIGHT                 = 2,     /**< 斗殴 */
    CASE_TYPE_GAMBLING              = 3,     /**< 赌博 */
    CASE_TYPE_PUBLIC_DISTURBANCE    = 4,     /**< 破坏公共秩序 */
    CASE_TYPE_OTHER                 = 5,     /**< 其他 */

    CASE_TYPE_MAX,                           /**< 案件类型枚举最大值 */
    CASE_TYPE_INVALID     = 0xFF             /**< 无效值 */
}CASE_TYPE_E;

/**
* @enum tagCaseStatus
* @brief 案件状态枚举
* @attention
*/
typedef enum tagCaseStatus
{
    CASE_STATUS_PROCESSING            = 0,     /**< 处理中 */
    CASE_STATUS_CLOSED                = 1,     /**< 已结案 */
    CASE_STATUS_CANCELLATION          = 2,     /**< 作废 */
    CASE_STATUS_SOLVED                = 3,     /**< 已破案 */

    CASE_STATUS_MAX,                           /**< 案件状态枚举最大值 */
    CASE_STATUS_INVALID     = 0xFF             /**< 无效值 */
}CASE_STATUS_E;

/**
* @enum tagPoliceIntelligenceSource
* @brief 警情来源枚举
* @attention
*/
typedef enum tagPoliceIntelligenceSource
{
    POLICE_INTELLIGENCE_SOURCE_CAPTURE           = 0,     /**< 现场抓获 */
    POLICE_INTELLIGENCE_SOURCE_RECPLAYBACK       = 1,     /**< 录像回放 */
    POLICE_INTELLIGENCE_SOURCE_110               = 2,     /**< 110报警 */
    POLICE_INTELLIGENCE_SOURCE_POLICESTATION     = 3,     /**< 派出所报案 */
    POLICE_INTELLIGENCE_SOURCE_PMSYS             = 4,     /**< 警综系统 */

    POLICE_INTELLIGENCE_SOURCE_MAX,                       /**< 警情来源枚举最大值 */
    POLICE_INTELLIGENCE_SOURCE_INVALID     = 0xFF         /**< 无效值 */
}POLICE_INTELLIGENCE_SOURCE_E;


/**
* @enum tagCasePersonnelType
* @brief 案件人员类型枚举
* @attention
*/
typedef enum tagCasePersonnelType
{
    CASE_PERSONNEL_TYPE_REPORTER      = 0,     /**< 报警人 */
    CASE_PERSONNEL_TYPE_SUSPECT       = 1,     /**< 嫌疑人 */
    CASE_PERSONNEL_TYPE_PARTY         = 2,     /**< 当事人 */
    CASE_PERSONNEL_TYPE_INVOLVER      = 3,     /**< 涉案人，查询列表时使用，包括嫌疑人和当事人 */

    CASE_PERSONNEL_TYPE_MAX,                   /**< 案件人员类型枚举最大值 */
    CASE_PERSONNEL_TYPE_INVALID     = 0xFF     /**< 无效值 */
}CASE_PERSONNEL_TYPE_E;

/**
* @enum tagGenderType
* @brief 人员性别枚举
* @attention
*/
typedef enum tagGenderType
{
    GENDER_TYPE_MALE      = 0,     /**< 男性 */
    GENDER_TYPE_FEMALE    = 1,     /**< 女性 */
    GENDER_TYPE_UNKNOWN   = 2,     /**< 未知 */

    GENDER_TYPE_MAX,               /**< 人员性别枚举最大值 */
    GENDER_TYPE_INVALID = 0xFF     /**< 无效值 */
}GENDER_TYPE_E;

/**
* @enum tagCaseStuffType
* @brief 案件物品类型枚举
* @attention
*/
typedef enum tagCaseStuffType
{
    CASE_STUFF_TYPE_TOOLS            = 0,      /**< 工具类 */
    CASE_STUFF_TYPE_TRANSPORT        = 1,      /**< 交通工具 */
    CASE_STUFF_TYPE_POISON           = 2,      /**< 毒物类 */
    CASE_STUFF_TYPE_EXPLOSIVE        = 3,      /**< 爆炸物品类 */
    CASE_STUFF_TYPE_JEWELRY          = 4,      /**< 工艺首饰及文物类 */
    CASE_STUFF_TYPE_ELECAPPLIANCES   = 5,      /**< 家用电器类 */
    CASE_STUFF_TYPE_INSTRUMENT       = 6,      /**< 仪器仪表及计量器材类 */
    CASE_STUFF_TYPE_AGRICULTURALPDT  = 7,      /**< 农副渔牧产品及野生产品类 */
    CASE_STUFF_TYPE_FOOD             = 8,      /**< 食品烟酒类 */
    CASE_STUFF_TYPE_TEXTILE          = 9,      /**< 纺织品类 */
    CASE_STUFF_TYPE_CLOTHING         = 10,     /**< 服装鞋帽及穿戴品类 */
    CASE_STUFF_TYPE_OFFICESUPPLIES   = 11,     /**< 文教体育娱乐及办公用品类 */
    CASE_STUFF_TYPE_FURNITURE        = 12,     /**< 家具及日用杂品类 */
    CASE_STUFF_TYPE_DEVICE           = 13,     /**< 通用设备电工及照明器材类 */
    CASE_STUFF_TYPE_RUBBERPDT        = 14,     /**< 橡胶塑料制品类 */
    CASE_STUFF_TYPE_BULIDINGMATERIAL = 15,     /**< 建筑装潢及金属材料类 */
    CASE_STUFF_TYPE_CHEMICALPDT      = 16,     /**< 石油化工产品类 */
    CASE_STUFF_TYPE_MEDICALDEVICES   = 17,     /**< 医药及医疗器械类 */
    CASE_STUFF_TYPE_DRUGS            = 18,     /**< 毒品类 */
    CASE_STUFF_TYPE_OBSCENEARTICLES  = 19,     /**< 淫秽物品类 */
    CASE_STUFF_TYPE_COMPUTEREQPT     = 20,     /**< 计算机设备及产品 */
    CASE_STUFF_TYPE_COMMUEQPT        = 21,     /**< 通信设备 */
    CASE_STUFF_TYPE_CURRENCY         = 22,     /**< 货币类 */
    CASE_STUFF_TYPE_CERTIFICATE      = 23,     /**< 证件类 */
    CASE_STUFF_TYPE_SECURITIES       = 24,     /**< 有价证券 */
    CASE_STUFF_TYPE_GUNS             = 25,     /**< 枪支 */
    CASE_STUFF_TYPE_OTHER            = 26,     /**< 其它 */

    CASE_STUFF_TYPE_MAX,               /**< 案件物品类型枚举最大值 */
    CASE_STUFF_TYPE_INVALID = 0xFF     /**< 无效值 */
}CASE_STUFF_TYPE_E;


/**
* @enum tagCaseStuffProperty
* @brief 案件物品性质枚举
* @attention
*/
typedef enum tagCaseStuffProperty
{
    CASE_STUFF_PROPERTY_LOSS             = 0,     /**< 损失 */
    CASE_STUFF_PROPERTY_CRIMINALTOOLS    = 1,     /**< 作案工具 */
    CASE_STUFF_PROPERTY_STOLENGOODS      = 2,     /**< 赃款赃物 */
    CASE_STUFF_PROPERTY_EVIDENCE         = 3,     /**< 证据 */
    CASE_STUFF_PROPERTY_OTHER            = 4,     /**< 其它涉案物品 */

    CASE_STUFF_PROPERTY_MAX,                      /**< 案件物品性质枚举最大值 */
    CASE_STUFF_PROPERTY_INVALID = 0xFF            /**< 无效值 */
}CASE_STUFF_PROPERTY_E;


/**
* @enum tagSeriesCaseType
* @brief 串并案类型枚举
* @attention
*/
typedef enum tagSeriesCaseType
{
    SERIES_CASE_TYPE_CASE      = 0,     /**< 以案串案 */
    SERIES_CASE_TYPE_PERSON    = 1,     /**< 以人串案 */
    SERIES_CASE_TYPE_OBJECT    = 2,     /**< 以物串案 */

    SERIES_CASE_TYPE_MAX,               /**< 串并案类型枚举最大值 */
    SERIES_CASE_TYPE_INVALID = 0xFF     /**< 无效值 */
}SERIES_CASE_TYPE_E;


/**
* @enum tagCaseShareType
* @brief 案件共享类型枚举
* @attention
*/
typedef enum tagCaseShareType
{
    CASE_SHARE_TYPE_USER   = 0,        /**< 共享给用户 */
    CASE_SHARE_TYPE_ORG    = 1,        /**< 共享给组织 */

    CASE_SHARE_TYPE_MAX,               /**< 案件共享类型枚举最大值 */
    CASE_SHARE_TYPE_INVALID = 0xFF     /**< 无效值 */
}CASE_SHARE_TYPE_E;


/**
* @enum tagCaseRelatedInfoType
* @brief 案件关联信息类型枚举
* @attention
*/
typedef enum tagCaseRelatedInfoType
{
    CASE_RELATEDINFO_TYPE_RECORD   = 0,        /**< 关联录像 */
    CASE_RELATEDINFO_TYPE_IMAGE    = 1,        /**< 关联图片 */
    CASE_RELATEDINFO_TYPE_OTHER    = 2,        /**< 关联其他 */

    CASE_RELATEDINFO_TYPE_MAX,               /**< 案件关联信息类型枚举最大值 */
    CASE_RELATEDINFO_TYPE_INVALID = 0xFF     /**< 无效值 */
}CASE_RELATEDINFO_TYPE_E;

/**
* @enum tagCaseFileType
* @brief 案件文件信息类型枚举
* @attention
*/
typedef enum tagCaseFileType
{
    CASE_FILE_TYPE_IMAGE   = 0,            /**< 案件图片文件 */
    CASE_FILE_TYPE_OTHER   = 1,            /**< 案件其他文件 */
    CASE_FILE_TYPE_UPLOAD_VEDIO   = 2,     /**< 案件上传录像 */
    CASE_FILE_TYPE_PICGRP  = 3,            /**< 案件图片组图片文件 */

    CASE_FILE_TYPE_MAX,               /**< 案件文件类型枚举最大值 */
    CASE_FILE_TYPE_INVALID = 0xFF     /**< 无效值 */
}CASE_FILE_TYPE_E;

/**
* @enum tagAlarmSendToThdSysProcType
* @brief 告警订阅转发第三方系统协议类型
* @attention
*/
typedef enum tagAlarmSendToThdSysProcType
{
    ALARM_SEND_PROC_TYPE_KUNMING_SUBWAY         = 0,    /**< 昆明地铁集中告警协议 */
    ALARM_SEND_PROC_TYPE_BUTT
}ALARM_SEND_TO_THD_SYS_PROC_TYPE_E;

/**
* @enum tagResServiceType
* @brief 资源业务类型(存储备份资源)
* @attention
*/
typedef enum tagResServiceType
{
    RES_SERVICE_TYPE_GENERAL    = 0,    /**< 一般业务 */
    RES_SERVICE_TYPE_CASE       = 1,    /**< 案件备份业务 */

    RES_SERVICE_TYPE_MAX,
    RES_SERVICE_TYPE_INVALID = 0xFFFFFFFF
}RES_SERVICE_TYPE_E;

/**
* @enum tagBakTaskServiceType
* @brief 备份任务业务类型
* @attention
*/
typedef enum tagBakTaskServiceType
{
    BAK_TASK_SERVICE_TYPE_GENERAL   = 0,    /**< 一般业务 */
    BAK_TASK_SERVICE_TYPE_CASE      = 1,    /**< 案件备份业务 */

    BAK_TASK_SERVICE_TYPE_MAX,
    BAK_TASK_SERVICE_TYPE_INVALID = 0xFFFFFFFF
}BAK_TASK_SERVICE_TYPE_E;

/**
* @enum tagIMOSSDKUploadType
* @brief 备份SDK上传类型
* @attention
*/
typedef enum tagIMOSSDKUploadType
{
    IMOS_SDK_UPLOAD_TYPE_CAMERA_TS  = 0,            /* 摄像机TS文件上传 */
    IMOS_SDK_UPLOAD_TYPE_CLIENT     = 1,            /* 客户端文件上传 */
    IMOS_SDK_UPLOAD_TYPE_BUTT
}IMOS_SDK_UPLOAD_TYPE_E;

/**
* @enum tagIMOSUploadAddrType
* @brief 备份文件上传地址类型
* @attention
*/
typedef enum tagIMOSUploadAddrType
{
    IMOS_UPLOAD_ADDR_TYPE_NONE      = 0,            /**< 无地址, 由服务器选择 */
    IMOS_UPLOAD_ADDR_TYPE_SRV_CODE  = 1,            /**< 服务器编码, 对应IMOS_CODE_LEN */
    IMOS_UPLOAD_ADDR_TYPE_IPV4      = 2,            /**< IPv4地址 */
    IMOS_UPLOAD_ADDR_TYPE_BUTT
}IMOS_UPLOAD_ADDR_TYPE_E;

/**
* @enum tagCaseClassificationType
* @brief 案件密级枚举
* @attention
*/
typedef enum tagCaseClassificationType
{
    CASE_CLASSIFICATION_TYPE_PUBLIC         = 0,        /**< 公开 */
    CASE_CLASSIFICATION_TYPE_SECRET         = 1,        /**< 秘密 */
    CASE_CLASSIFICATION_TYPE_CONFIDENTIAL   = 2,        /**< 机密 */
    CASE_CLASSIFICATION_TYPE_TOPSECRET      = 3,        /**< 绝密 */

    CASE_CLASSIFICATION_TYPE_MAX,                      /**< 密级枚举最大值 */
    CASE_CLASSIFICATION_TYPE_INVALID = 0xFF            /**< 无效值 */
}CASE_CLASSIFICATION_TYPE_E;

/**
* @enum tagCaseDataType
* @brief 案件资料类型枚举
* @attention
*/
typedef enum tagCaseDataType
{
    CASE_DATA_TYPE_CASEINFO       = 0,            /**< 案件信息 */
    CASE_DATA_TYPE_RECORD         = 1,            /**< 案件录像 */
    CASE_DATA_TYPE_FILE           = 2,            /**< 案件其他文件 */

    CASE_DATA_TYPE_MAX,                           /**< 资料类型枚举最大值 */
    CASE_DATA_TYPE_INVALID = 0xFF                 /**< 无效值 */
}CASE_DATA_TYPE_E;

/* Added by z00359 for TG 20120604 */
/* Begin added by baoyihui02795, 2011-04-28 of 卡口项目 */
/**
* @enum tagQryVehicleStatInfo
* @brief 车辆统计报表查询内容
* @attention
*/
typedef enum tagQryVehicleStatInfo
{
    VEHICLE_STAT_DATE                = 0,    /**< 统计日期#IMOS_SIMPLE_DATE_LEN */
    VEHICLE_STAT_TIME                = 1,    /**< 统计时间#IMOS_TIME_LEN */
    VEHICLE_STAT_TOLLGATE_CODE       = 2,    /**< 卡口编号#IMOS_CODE_LEN */
    VEHICLE_STAT_TOLLGATE_NAME       = 3,    /**< 卡口名称#IMOS_NAME_LEN */
    VEHICLE_STAT_LANE_NUMBER         = 4,    /**< 车道编号#ULONG */
    VEHICLE_STAT_TOTAL_COUNT         = 5,    /**< 卡口总流量#ULONG */
    VEHICLE_STAT_AVG_SPEED           = 6,    /**< 卡口车辆平均速度#ULONG */

    VEHICLE_STAT_UNKNOWN_TYPE_COUNT  = 7,    /**< 未知车型流量#ULONG */
    VEHICLE_STAT_SMALL_TYPE_COUNT    = 8,    /**< 小型车流量#ULONG */
    VEHICLE_STAT_MIDDLE_TYPE_COUNT   = 9,    /**< 中型车流量#ULONG */
    VEHICLE_STAT_LARGE_TYPE_COUNT    = 10,   /**< 大型车流量#ULONG */
    VEHICLE_STAT_OTHER_TYPE_COUNT    = 11,   /**< 其他车型流量#ULONG */

    VEHICLE_STAT_DIR_1               = 12,   /**< 方向1流量#ULONG */
    VEHICLE_STAT_DIR_2               = 13,   /**< 方向2流量#ULONG */

    VEHICLE_STAT_MAX
}QRY_VEHICLE_STAT_INFO_E;



/**
* @enum tagFTPOperType
* @brief FTP操作类型枚举
* @attention
*/
typedef enum tagFTPOperType
{
    FTP_OPER_TYPE_TALLGATE_IMAGE       = 0,            /**< 卡口示意图上传 */
    FTP_OPER_TYPE_DISPOSITION_IMAGE    = 1,            /**< 布控照片上传 */

    FTP_OPER_TYPE_MAX,                                 /**< 最大值 */
    FTP_OPER_TYPE_INVALID              = 0xFFFF        /**< 无效值 */
} FTP_OPER_TYPE_E;

/**
* @enum tagTollgateType
* @brief 卡口类型枚举
* @attention
*/
typedef enum tagTollgateType
{
    TOLLGATE_TYPE_PUBLIC_SECURITY   = 0,            /**< 治安卡口 */
    TOLLGATE_TYPE_TOLL_STATION      = 1,            /**< 收费站 */
    TOLLGATE_TYPE_PARK              = 2,            /**< 停车场 */
    TOLLGATE_TYPE_CIQ               = 3,            /**< 海关 */
    TOLLGATE_TYPE_E_POLICE          = 4,            /**< 电警 */
    TOLLGATE_TYPE_MOBILE_E_POLICE   = 5,            /**< 移动电警 */
    TOLLGATE_TYPE_VIOLATE_PARK_BALL = 6,            /**< 违停球 */
    TOLLGATE_TYPE_PERSON_FACE       = 7,            /**<人脸卡口 */
	TOLLGATE_TYPE_SPACESPEED        = 8,			/**< 区间卡口*/
    TOLLGATE_TYPE_MAX,                              /**< 最大值 */
    TOLLGATE_TYPE_INVALID         = 0xFFFF          /**< 无效值 */
} TOLLGATE_TYPE_E;

/**
* @enum tagTallgateCameraType
* @brief 卡口相机类型枚举
* @attention
*/
typedef enum tagTallgateCameraType
{
    TALLGATE_CAMERA_TYPE_3RD         = 0,            /**< 第三方IPC */

    TALLGATE_CAMERA_TYPE_MAX,                        /**< 最大值 */
    TALLGATE_CAMERA_TYPE_INVALID     = 0xFFFF        /**< 无效值 */
} TALLGATE_CAMERA_TYPE_E;

/**
* @enum tagLaneType
* @brief 车道类型
* @attention
*/
typedef enum tagLaneType
{
    LANE_TYPE_MOTOR_VEHICLE     = 0,                       /**< 机动车道 */
    LANE_TYPE_NON_MOTOR_VEHICLE = 1,                       /**< 非机动车道 */
    LANE_TYPE_MAX,                                         /**< 最大值 */
    LANE_TYPE_INVALID           = 0xFFFF               /**< 无效值 */
} LANE_TYPE_E;

/**
* @enum tagTrafficLightStatusE
* @brief 信号灯状态
* @attention
*/
typedef enum tagTrafficLightStatusE
{
    TRAFFIC_LIGHT_RED_STATUS              = 0,           /**< 红灯状态 */
    TRAFFIC_LIGHT_YELLOW_STATUS           = 1,           /**< 黄灯状态 */
    TRAFFIC_LIGHT_GREEN_STATUS            = 2,           /**< 绿灯状态 */
    TRAFFIC_LIGHT_NULL_STATUS             = 3,           /**< 无红绿灯设备 */
    TRAFFIC_LIGHT_ABNORMAL_STATUS         = 4,           /**< 红绿灯设备异常 */

    TRAFFIC_LIGHT_STATUS_MAX,                            /**< 最大值 */
    TRAFFIC_LIGHT_STATUS_INVALID  = 0xFFFFFFFF           /**< 无效值 */
} TRAFFIC_LIGHT_STATUS_E;

/**
* @enum tagDispositionDeptType
* @brief 布撤控单位类型枚举
* @attention
*/
typedef enum tagDispositionDeptType
{
    DISPOSITION_DEPT_TYPE_DISPOSITION       = 0,                   /**< 布控 */
    DISPOSITION_DEPT_TYPE_UNDO_DISPOSITION  = 1,                   /**< 撤控 */
    DISPOSITION_DEPT_TYPE_BOTH              = 2,                   /**< 布撤控 */
    DISPOSITION_DEPT_TYPE_MAX,                                     /**< 最大值 */
    DISPOSITION_DEPT_TYPE_INVALID           = 0xFFFF               /**< 无效值 */
} DISPOSITION_DEPT_TYPE_E;

/**
* @enum tagVehicleColorDepth
* @brief 车身颜色深浅枚举
* @attention
*/
typedef enum tagVehicleColorDepth
{
    VEHICLE_COLOR_DEPTH_UNKNOWN = 0,                       /**< 未知 */
    VEHICLE_COLOR_DEPTH_LIGHT   = 1,                       /**< 浅 */
    VEHICLE_COLOR_DEPTH_DARK    = 2,                       /**< 深 */
    VEHICLE_COLOR_DEPTH_MAX,                               /**< 最大值 */
    VEHICLE_COLOR_DEPTH_INVALID = 0xFFFF                   /**< 无效值 */
} VEHICLE_COLOR_DEPTH_E;

/**
* @enum tagVehicleIdentifyStatus
* @brief 车牌识别状态
* @attention
*/
typedef enum tagVehicleIdentifyStatus
{
    VEHICLE_IDENTIFY_STATUS_SUCCEED       = 0,                 /**< 识别成功 */
    VEHICLE_IDENTIFY_STATUS_FAILED        = 1,                 /**< 识别失败 */
    VEHICLE_IDENTIFY_STATUS_PARTLY        = 2,                 /**< 部分识别 */
    VEHICLE_IDENTIFY_STATUS_UNRECOGNIZED  = 3,                 /**< 未识别 */
    VEHICLE_IDENTIFY_STATUS_MAX,                               /**< 最大值 */
    VEHICLE_IDENTIFY_STATUS_INVALID = 0xFFFF                   /**< 无效值 */
} VEHICLE_IDENTIFY_STATUS_E;

/**
* @enum tagVehicleAlarmType
* @brief 车辆告警类别
* @attention
*/
typedef enum tagVehicleAlarmType
{
    VEHICLE_ALARM_TYPE_OTHER                 = 0,             /**< 卡口 */
    VEHICLE_ALARM_TYPE_DISPOSITION           = 1,             /**< 布控告警 */
    VEHICLE_ALARM_TYPE_BLACKLIST             = 2,             /**< 黑名单告警 */
    VEHICLE_ALARM_TYPE_P2P_SPEED_DETECTION   = 3,             /**< 区间测速告警 *//* Added by b02795, 2011-11-08 of 卡口三期 */
    VEHICLE_ALARM_TYPE_P2P_TIME_DETECTION    = 4,             /**< 区间超时告警 *//* Added by c02845, 2015-11-05 of MPPD31387  */
	VEHICLE_ALARM_TYPE_MAX,                                   /**< 最大值 */
    VEHICLE_ALARM_TYPE_INVALID               = 0xFFFF         /**< 无效值 */
} VEHICLE_ALARM_TYPE_E;

/**
* @enum tagBlacklistSrc
* @brief 黑名单来源
* @attention
*/
typedef enum tagBlacklistSrc
{
    BLACKLIST_SRC_UNKNOWN               = 0,                    /**< 未知 */
    BLACKLIST_SRC_LOCAL                 = 1,                    /**< 手工添加 */
    BLACKLIST_SRC_DRIVER_MANAGEMENT     = 2,                    /**< 车驾管数据库 */
    BLACKLIST_SRC_TRAFFIC_VIOLATION     = 3,                    /**< 违法车辆数据库 */
    BLACKLIST_SRC_VEHICLE_GRAB          = 4,                    /**< 盗抢车辆数据库 */
    BLACKLIST_SRC_MAX,                                          /**< 最大值 */
    BLACKLIST_SRC_INVALID = 0xFFFF                              /**< 无效值 */
} BLACKLIST_SRC_E;


/**
*@enum tagVehicleListType
*@brief 名单类型枚举
*@attention
*/
typedef enum tagVehicleListType
{
    VEHICLE_LIST_TYPE_RED             = 0,              /**< 红名单 */
    VEHICLE_LIST_TYPE_MAX,                              /**< 最大值 */
    VEHICLE_LIST_TYPE_INVALID         = 0xFFFF          /**< 无效值 */
} VEHICLE_LIST_TYPE_E;

/**
* @enum tagVehicleDealStatus
* @brief 过车数据处理标志定义
* @attention
*/
typedef enum tagVehicleDealStatus
{
    VEHICLE_DEAL_STATUS_INIT      = 0,                  /**< 未处理 */
    VEHICLE_DEAL_STATUS_CORRECTED = 1,                  /**< 已校对 */
    VEHICLE_DEAL_STATUS_USELESS   = 2,                  /**< 无效信息 */
    VEHICLE_DEAL_STATUS_AUDITED   = 3,                  /**< 已审核 */
    VEHICLE_DEAL_STATUS_DONE      = 4,                  /**< 已处理 */
    VEHICLE_DEAL_STATUS_MAX,                            /**< 最大值 */
    VEHICLE_DEAL_STATUS_INVALID = 0xFFFF                /**< 无效值 */
} VEHICLE_DEAL_STATUS_E;

/**
* @enum tagDictionaryType
* @brief 数据字典类型枚举
* @attention
*/
typedef enum tagDictionaryType
{
    DICTIONARY_TYPE_LICENSE_PLATE_TYPE      = 1,    /**< 号牌种类 */
    DICTIONARY_TYPE_LICENSE_PLATE_COLOR     = 2,    /**< 号牌颜色 */
    DICTIONARY_TYPE_VEHICLE_TYPE            = 3,    /**< 车辆类型 */
    DICTIONARY_TYPE_VEHICLE_COLOR           = 4,    /**< 车身颜色 */
    DICTIONARY_TYPE_VEHICLE_LOGO            = 5,    /**< 车辆品牌 */
    DICTIONARY_TYPE_VEHICLE_STATUS          = 6,    /**< 车辆行驶状态 */
    DICTIONARY_TYPE_DISPOSITION_TYPE        = 7,    /**< 布控类型 */
    DICTIONARY_TYPE_EQUIPMENT_TYPE          = 8,    /**< 采集类型 */
    DICTIONARY_TYPE_LANE_DIR                = 9,    /**< 行驶方向 */
    DICTIONARY_TYPE_LICENSE_PLATE_PREFIX    = 10,   /**< 车牌省份简称 */
    DICTIONARY_TYPE_ERR_DECK                = 11,   /**<套牌分析粗错误原因 */
    DICTIONARY_TYPE_DEAL_STATUS             = 311, /**<处理状态*/
    DICTIONARY_TYPE_AUDIT_STATUS        = 312,/**<三审状态*/
    DICTIONARY_TYPE_MAX = 400   ,                    /**< 最大值 */
    DICTIONARY_TYPE_INVALID = 0xFFFF                /**< 无效值 */
} DICTIONARY_TYPE_E;

/**
* @enum tagDispositionStatus
* @brief 布控状态枚举
* @attention
*/
typedef enum tagDispositionStatus
{
    DISPOSITION_STATUS_IN_PROCESS       = 0,    /**< 布控 */
    DISPOSITION_STATUS_MANUAL_UNDO      = 1,    /**< 手工撤控 */
    DISPOSITION_STATUS_AUTO_UNDO        = 2,    /**< 自动撤控 */
    DISPOSITION_STATUS_PAUSE            = 3,    /**< 布控暂停 */
    DISPOSITION_STATUS_CONTINUE         = 4,    /**< 布控继续 */
    DISPOSITION_AUDIT_STATUS_PENDING    = 5,    /**< 待审核 */
    DISPOSITION_AUDIT_STATUS_NO_PASS    = 6,    /**< 审核未通过 */
    DISPOSITION_STATUS_MAX,                     /**< 最大值 */
    DISPOSITION_STATUS_INVALID = 0xFFFF         /**< 无效值 */
} DISPOSITION_STATUS_E;

/* End added by baoyihui02795, 2011-04-28 of 卡口项目 */

/*Begin added by a02842 for whitelist extension,2017-02-23*/
/**
* @enum tagDispositionStatus
* @brief 白名单状态枚举
* @attention
*/
typedef enum tagWhiteListStatus
{
    WHITELIST_STATUS_IN_PROCESS       = 0,    /**< 白名单使能*/
    WHITELIST_STATUS_MANUAL_UNDO      = 1,    /**< 手工撤销*/
    WHITELIST_STATUS_AUTO_UNDO        = 2,    /**< 自动撤销*/
    WHITELIST_STATUS_PAUSE            = 3,    /**< 白名单暂停 */
    WHITELIST_STATUS_CONTINUE         = 4,    /**< 白名单继续 */
    WHITELIST_STATUS_MAX,                     /**< 最大值 */
    WHITELIST_STATUS_INVALID = 0xFFFF         /**< 无效值 */
} WHITELIST_STATUS_E;
/*End added by a02842 for whitelist extension,2017-02-23*/

/**
* @enum tagDevLocalResOperType
* @brief 本地存储资源操作枚举
* @attention
*/
typedef enum tagDevLocalResOperType
{
    DEV_LOCAL_RES_OPER_TYPE_TOLLGATE       = 0,           /**< 卡口 */
    DEV_LOCAL_RES_OPER_TYPE_MAX,                          /**< 最大值 */
    DEV_LOCAL_RES_OPER_TYPE_INVALID        = 0xFFFF       /**< 无效值 */
} DEV_LOCAL_RES_OPER_TYPE_E;

/**
* @enum tagStorageResUsage
* @brief 存储资源用途枚举
* @attention
*/
typedef enum tagStorageResUsage
{
    STORAGE_RES_USAGE_DEFAULT                   = 0,            /**< 默认 */
    STORAGE_RES_USAGE_VEHICLE_ALARM_IMG         = 1,            /**< 过车告警图片存储 */
    STORAGE_RES_USAGE_IAHR                      = 2,            /**< 人脸图片存储 */

    STORAGE_RES_USAGE_MAX,                                      /**< 最大值 */
    STORAGE_RES_USAGE_INVALID                   = 0xFFFF        /**< 无效值 */
} STORAGE_RES_USAGE_E;

/* Added by z06806 for TGII 20110721 begin */
/**
* @enum tagPlateAnalyseStatus
* @brief 套牌分析状态
* @attention
*/
typedef enum tagPlateAnalyseStatus
{
    PLATE_ANALYSE_STATUS_INIT               = 0,            /**< 初始化 */
    PLATE_ANALYSE_STATUS_ANALYSING          = 1,            /**< 正在分析 */
    PLATE_ANALYSE_STATUS_FINISHED           = 2,            /**< 分析完成 */
    PLATE_ANALYSE_STATUS_USER_STOP          = 3,            /**< 用户手动停止 */
    PLATE_ANALYSE_STATUS_ERR_STOP           = 4,            /**< 内部出错停止 */
    PLATE_ANALYSE_STATUS_MAX,                               /**< 最大值 */
    PLATE_ANALYSE_STATUS_INVALID            = 0xFFFF        /**< 无效值 */
} PLATE_ANALYSE_STATUS_E;

/**
* @enum tagVehicleAbnormalAnalyseStatus
* @brief 车辆异常行为分析状态
* @attention
*/
typedef enum tagVehicleAbnormalAnalyseStatus
{
    VEHICLE_ABNORMAL_STATUS_INIT               = 0,            /**< 初始化 */
    VEHICLE_ABNORMAL_STATUS_ANALYSING          = 1,            /**< 正在分析 */
    VEHICLE_ABNORMAL_STATUS_FINISHED           = 2,            /**< 分析完成 */
    VEHICLE_ABNORMAL_STATUS_USER_STOP          = 3,            /**< 用户手动停止 */
    VEHICLE_ABNORMAL_STATUS_ERR_STOP           = 4,            /**< 内部出错停止 */
    VEHICLE_ABNORMAL_STATUS_MAX,                               /**< 最大值 */
    VEHICLE_ABNORMAL_STATUS_INVALID            = 0xFFFF        /**< 无效值 */
} VEHICLE_ABNORMAL_ANALYSE_STATUS_E;

/**
* @enum tagVehicleAbnormalAnalyseOperator
* @brief 车辆异常行为分析操作符
* @attention
*/
typedef enum tagVehicleAbnormalAnalyseOperator
{
    VEHICLE_ABNORMAL_OPERATOR_GE               = 0,            /**< 大于等于 */
    VEHICLE_ABNORMAL_OPERATOR_GREAT            = 1,            /**< 大于 */
    VEHICLE_ABNORMAL_OPERATOR_EQUAL            = 2,            /**< 等于 */
    VEHICLE_ABNORMAL_OPERATOR_LE               = 3,            /**< 小于等于 */
    VEHICLE_ABNORMAL_OPERATOR_LESS             = 4,            /**< 小于 */
    VEHICLE_ABNORMAL_OPERATOR_MAX,                             /**< 最大值 */
    VEHICLE_ABNORMAL_OPERATOR_INVALID          = 0xFFFF        /**< 无效值 */
} VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E;


/* Added by z06806 for TGII 20110721 end */

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/**
* @enum tagVehicleTrackCollisionStatus
* @brief 车辆轨迹碰撞分析状态
* @attention
*/
typedef enum tagVehicleTrackCollisionStatus
{
    VEHICLE_TRACK_COLLISION_STATUS_INIT               = 0,            /**< 初始化 */
    VEHICLE_TRACK_COLLISION_STATUS_ANALYSING          = 1,            /**< 正在分析 */
    VEHICLE_TRACK_COLLISION_STATUS_FINISHED           = 2,            /**< 分析完成 */
    VEHICLE_TRACK_COLLISION_STATUS_USER_STOP          = 3,            /**< 用户手动停止 */
    VEHICLE_TRACK_COLLISION_STATUS_ERR_STOP           = 4,            /**< 内部出错停止 */
    VEHICLE_TRACK_COLLISION_STATUS_MAX,                               /**< 最大值 */
    VEHICLE_TRACK_COLLISION_STATUS_INVALID            = 0xFFFF        /**< 无效值 */
} VEHICLE_TRACK_COLLISION_STATUS_E;

/**
* @enum tagVehicleFirstAppearStatus
* @brief 车辆首次出现分析状态
* @attention
*/
typedef enum tagVehicleFirstAppearStatus
{
    VEHICLE_FIRST_APPEAR_STATUS_INIT               = 0,            /**< 初始化 */
    VEHICLE_FIRST_APPEAR_STATUS_ANALYSING          = 1,            /**< 正在分析 */
    VEHICLE_FIRST_APPEAR_STATUS_FINISHED           = 2,            /**< 分析完成 */
    VEHICLE_FIRST_APPEAR_STATUS_USER_STOP          = 3,            /**< 用户手动停止 */
    VEHICLE_FIRST_APPEAR_STATUS_ERR_STOP           = 4,            /**< 内部出错停止 */
    VEHICLE_FIRST_APPEAR_STATUS_MAX,                               /**< 最大值 */
    VEHICLE_FIRST_APPEAR_STATUS_INVALID            = 0xFFFF        /**< 无效值 */
} VEHICLE_FIRST_APPEAR_STATUS_E;

/**
* @enum tagVehiclePerilTimeStatus
* @brief 车辆高危时段分析状态
* @attention
*/
typedef enum tagVehiclePerilTimeStatus
{
    VEHICLE_PERIL_TIME_STATUS_INIT               = 0,              /**< 初始化 */
    VEHICLE_PERIL_TIME_STATUS_ANALYSING          = 1,              /**< 正在分析 */
    VEHICLE_PERIL_TIME_STATUS_FINISHED           = 2,              /**< 分析完成 */
    VEHICLE_PERIL_TIME_STATUS_USER_STOP          = 3,              /**< 用户手动停止 */
    VEHICLE_PERIL_TIME_STATUS_ERR_STOP           = 4,              /**< 内部出错停止 */
    VEHICLE_PERIL_TIME_STATUS_MAX,                                 /**< 最大值 */
    VEHICLE_PERIL_TIME_STATUS_INVALID            = 0xFFFF          /**< 无效值 */
} VEHICLE_PERIL_TIME_STATUS_E;

/* End added by bt00977, 2013-1-25 of MPPD00420 */

/**
* @enum tagVehicleFrequentNightOutStatus
* @brief 车辆频繁夜出分析状态
* @attention
*/
typedef enum tagVehicleFrequentNightOutStatus
{
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_INIT               = 0,              /**< 初始化 */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_ANALYSING          = 1,              /**< 正在分析 */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_FINISHED           = 2,              /**< 分析完成 */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_USER_STOP          = 3,              /**< 用户手动停止 */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_ERR_STOP           = 4,              /**< 内部出错停止 */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_MAX,                                 /**< 最大值 */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_INVALID            = 0xFFFF          /**< 无效值 */
} VEHICLE_FREQUENT_NIGHT_OUT_STATUS_E;

/**
* @enum tagVehicleNocturnalStatus
* @brief 车辆昼伏夜出分析状态
* @attention
*/
typedef enum tagVehicleNocturnalStatus
{
    VEHICLE_NOCTURNAL_STATUS_INIT               = 0,              /**< 初始化 */
    VEHICLE_NOCTURNAL_STATUS_ANALYSING          = 1,              /**< 正在分析 */
    VEHICLE_NOCTURNAL_STATUS_FINISHED           = 2,              /**< 分析完成 */
    VEHICLE_NOCTURNAL_STATUS_USER_STOP          = 3,              /**< 用户手动停止 */
    VEHICLE_NOCTURNAL_STATUS_ERR_STOP           = 4,              /**< 内部出错停止 */
    VEHICLE_NOCTURNAL_STATUS_MAX,                                 /**< 最大值 */
    VEHICLE_NOCTURNAL_STATUS_INVALID            = 0xFFFF          /**< 无效值 */
} VEHICLE_NOCTURNAL_STATUS_E;

/**
* @enum tagVehicleOnlyIntoCityStatus
* @brief 车辆多次进城不出城分析状态
* @attention
*/
typedef enum tagVehicleOnlyIntoCityStatus
{
    VEHICLE_ONLY_INTO_CITY_STATUS_INIT               = 0,              /**< 初始化 */
    VEHICLE_ONLY_INTO_CITY_STATUS_ANALYSING          = 1,              /**< 正在分析 */
    VEHICLE_ONLY_INTO_CITY_STATUS_FINISHED           = 2,              /**< 分析完成 */
    VEHICLE_ONLY_INTO_CITY_STATUS_USER_STOP          = 3,              /**< 用户手动停止 */
    VEHICLE_ONLY_INTO_CITY_STATUS_ERR_STOP           = 4,              /**< 内部出错停止 */
    VEHICLE_ONLY_INTO_CITY_STATUS_MAX,                                 /**< 最大值 */
    VEHICLE_ONLY_INTO_CITY_STATUS_INVALID            = 0xFFFF          /**< 无效值 */
} VEHICLE_ONLY_INTO_CITY_STATUS_E;

/**
* @enum tagVehicleFrequentNightOutOperator
* @brief 车辆频繁夜出分析操作符
* @attention
*/
typedef enum tagVehicleFrequentNightOutOperator
{
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_GE               = 0,            /**< 大于等于 */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_GREAT            = 1,            /**< 大于 */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_EQUAL            = 2,            /**< 等于 */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_LE               = 3,            /**< 小于等于 */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_LESS             = 4,            /**< 小于 */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_MAX,                             /**< 最大值 */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_INVALID          = 0xFFFF        /**< 无效值 */
} VEHICLE_FREQUENT_NIGHT_OUT_ANALYSE_OPERATOR_E;

/**
 * @enum tagTmsMultiAddrForward
 * @brief 多地址转发状态
 * @attention
 */
typedef enum tagTmsMultiAddrForward
{
    TMS_MULTI_ADDR_FORWARD_INIT                = 0,    /**< 初始化 */
    TMS_MULTI_ADDR_FORWARD_SUCCEED             = 1,    /**< 正常 */
    TMS_MULTI_ADDR_FORWARD_ERROR               = 2,    /**< 错误 */
    TMS_MULTI_ADDR_FORWARD_MAX,
    TMS_MULTI_ADDR_FORWARD_INVALID            = 0XFFFFFFFF
} TMS_MULTI_ADDR_FORWARD_E;

/* Begin added by b02795, 2011-11-08 of 卡口三期 */
/**
* @enum tagVehicleRecordType
* @brief 过车记录类别
* @attention
*/
typedef enum tagVehicleRecordType
{
    VEHICLE_RECORD_TYPE_NORMAL               = 0,             /**< 过车记录 */
    VEHICLE_RECORD_TYPE_P2P_SPEED_DETECTION  = 1,             /**< 区间测速 */
    VEHICLE_RECORD_TYPE_REDLIST              = 2,             /**< 红名单过车记录 */
    VEHICLE_RECORD_TYPE_MAX,                                  /**< 最大值 */
    VEHICLE_RECORD_TYPE_INVALID              = 0xFFFF         /**< 无效值 */
} VEHICLE_RECORD_TYPE_E;

/**
* @enum tagDeviceGisStatus
* @brief 设备GIS状态
* @attention
*/
typedef enum tagDeviceGisStatus
{
    DEVICE_GIS_STATUS_NORMAL                 = 0,             /**< 正常 */
    DEVICE_GIS_STATUS_ALARM                  = 1,             /**< 告警 */
    DEVICE_GIS_STATUS_MAX,                                    /**< 最大值 */
    DEVICE_GIS_STATUS_INVALID                = 0xFFFF         /**< 无效值 */
} DEVICE_GIS_STATUS_E;
/* End added by b02795, 2011-11-08 of 卡口三期 */

/*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
/**
* @enum tagDispositionType
* @brief 布控类别枚举
* @attention
*/
typedef enum tagDispositionType
{
    DISPOSITION_TYPE_MAC      = 0,    /**< MAC布控 */
    DISPOSITION_TYPE_RFID      = 1,    /**< RFID布控*/
    DISPOSITION_TYPE_MAX,                     /**< 最大值 */
    DISPOSITION_TYPE_INVALID = 0xFFFF         /**< 无效值 */
} DISPOSITION_TYPE_E;
/*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

/**
* @enum tagDispositionInterType
* @brief 互联布控类型
* @attention
*/
typedef enum tagDispositionInterType
{
    DISPOSITION_INTER_TYPE_LOCAL                 = 0,             /**< 本域 */
    DISPOSITION_INTER_TYPE_LOWER                 = 1,             /**< 下级域 */
    DISPOSITION_INTER_TYPE_LOCAL_LOWER           = 2,             /**< 本域和下级域 */
    DISPOSITION_INTER_TYPE_UPPER                 = 3,             /**< 上级域 */
    DISPOSITION_INTER_TYPE_MAX,                                   /**< 最大值 */
    DISPOSITION_INTER_TYPE_INVALID               = 0xFFFF         /**< 无效值 */
} DISPOSITION_INTER_TYPE_E;

/**
* @enum tagDispositionResultType
* @brief 布控结果
* @attention
*/
typedef enum tagDispositionResultType
{
    DISPOSITION_RESULT_IN_PROCESS            = 0,             /**< 正在处理 */
    DISPOSITION_RESULT_SUCCEED               = 1,             /**< 成功 */
    DISPOSITION_RESULT_FAILED                = 2,             /**< 失败 */
    DISPOSITION_RESULT_TIMEOUT               = 3,             /**< 超时 */
    DISPOSITION_RESULT_MAX,                                   /**< 最大值 */
    DISPOSITION_RESULT_INVALID               = 0xFFFF         /**< 无效值 */
} DISPOSITION_RESULT_E;

/**
* @enum tagDispositionExtStatus
* @brief 布控扩展状态
* @attention
*/
typedef enum tagDispositionExtStatus
{
    DISPOSITION_EXT_STATUS_SUCCESS           = 0,             /**< 成功 */
    DISPOSITION_EXT_STATUS_OTHER             = 1,             /**< 其他 */
    DISPOSITION_EXT_STATUS_MAX,                               /**< 最大值 */
    DISPOSITION_EXT_STATUS_INVALID           = 0xFFFF         /**< 无效值 */
} DISPOSITION_EXT_STATUS_E;

/**
* @enum tagVehicleRestrictType
* @brief 车辆限行方式
* @attention
*/
typedef enum tagVehicleRestrictType
{
    VEHICLE_RESTRICT_TYPE_LAST_NUMBER      = 0,            /**< 尾号限行 */
    VEHICLE_RESTRICT_TYPE_ODD              = 1,            /**< 单号限行 */
    VEHICLE_RESTRICT_TYPE_EVEN             = 2,            /**< 双号限行 */
    VEHICLE_RESTRICT_TYPE_VEHICLE_TYPE     = 3,            /**< 车辆类型 */

    VEHICLE_RESTRICT_TYPE_MAX,                             /**< 车辆限行方式枚举最大值 */
    VEHICLE_RESTRICT_TYPE_INVALID          = 0xFFFF        /**< 无效值 */
} VEHICLE_RESTRICT_TYPE_E;


/**
* @enum tagTMSForwardMode
* @brief 转发模式
* @attention
*/
typedef enum tagTMSForwardMode
{
    TMS_FORWARD_MODE_IMAGE            = 0,            /**< 转发图片 */
    TMS_FORWARD_MODE_URL              = 1,            /**< 转发图片URL */

    TMS_FORWARD_MODE_MAX,                             /**< 最大值 */
    TMS_FORWARD_MODE_INVALID          = 0xFFFF        /**< 无效值 */
} TMS_FORWARD_MODE_E;

/**
* @enum tagWebGisMapType
* @brief WebGis地图类型
* @attention
*/
typedef enum tagWebGisMapType
{
    WEBGIS_TYPE_WMS             = 0,             /**< WMS地图 */
    WEBGIS_TYPE_BMP             = 1,             /**< BMP地图 */
    WEBGIS_TYPE_JPEG            = 2,             /**< JPEG地图 */
    WEBGIS_TYPE_SVG             = 3,             /**< SVG地图 */
    WEBGIS_TYPE_TMS             = 4,             /**< TMS地图 */
    WEBGIS_TYPE_SHP             = 5,             /**< SHP地图 *、

    WEBGIS_TYPE_MAX,                             /**< 最大值 */
    WEBGIS_TYPE_INVALID         = 0xFF           /**< 无效值 */

} WEBGIS_MAP_TYPE;

/**
* @enum tagCommunityCameraStatus
* @brief 社会资源摄像机状态枚举
* @attention
*/
typedef enum tagCommunityCameraStatus
{
    COMMUNITY_CAMERA_STATUS_NORMAL      = 0,            /**< 正常 */
    COMMUNITY_CAMERA_STATUS_FAULT       = 1,            /**< 损坏 */
    COMMUNITY_CAMERA_STATUS_REPAIR      = 2,            /**< 维修 */
    COMMUNITY_CAMERA_STATUS_RETIREMENT  = 3,            /**< 报废 */

    COMMUNITY_CAMERA_STATUS_MAX,                        /**< 社会资源摄像机状态枚举最大值 */
    COMMUNITY_CAMERA_STATUS_INVALID     = 0xFF          /**< 无效值 */
}COMMUNITY_CAMERA_STATUS_E;

/**
* @enum tagUserClientType
* @brief 用户前端的类型
* @attention
*/
typedef enum tagUserClientType
{
    /* (0~999)用于BS客户端 */
    USER_CLIENT_TYPE_BS          = 0,            /**< BS客户端 */
    USER_CLIENT_TYPE_MBS         = 1,            /**< 多屏BS客户端 */

    /* (1000~1999):用于CS客户端 */
    USER_CLIENT_TYPE_ICSCI      = 1000,         /**< 公安图侦客户端 */
    USER_CLIENT_TYPE_ICC        = 1001,         /**< 违章抓拍客户端 */

    /* (2000~2999):用于移动客户端 */
    USER_CLIENT_TYPE_MOBILE      = 2000,         /**< 移动客户端 */

    USER_CLIENT_TYPE_MCD      = 2001,         /**< 移动指挥调度客户端 */
    USER_CLIENT_TYPE_MLE      = 2002,         /**< 移动执法客户端 */


    USER_CLIENT_TYPE_MAX,                        /**< 用户前端的类型枚举最大值 */
    USER_CLIENT_TYPE_INVALID     = 0xFFFF        /**< 无效值 */
}USER_CLIENT_TYPE_E;


/**
* @enum tagBallLinkageType
* @brief 枪球联动类型枚举
* @attention
*/
typedef enum tagBallLinkageType
{
    BALLLINKAGE_TYPE_SINGLE      = 0,       /**< 一枪一球 */
    BALLLINKAGE_TYPE_TRIPLE      = 1,       /**< 三枪一球 */

    BALLLINKAGE_TYPE_MAX,                    /**< 枚举最大值 */
    BALLLINKAGE_TYPE_INVALID = 0xFFFFFFFF    /**< 无效值 */
}BALLLINKAGE_TYPE_E;

/**
* @enum tagOrgResSubType
* @brief 组织资源子类型枚举
* @attention
*/
typedef enum tagOrgResSubType
{
    ORG_RES_SUB_TYPE_LOCAL_PHY   = 1,       /**< 本物理域 */
    ORG_RES_SUB_TYPE_LOCAL_VIR   = 2,       /**< 本域的虚拟域 */
    ORG_RES_SUB_TYPE_EXT_VIR     = 3,       /**< 外域的虚拟域 */
    ORG_RES_SUB_TYPE_UPPER_PHY   = 4,       /**< 上级外物理域 */
    ORG_RES_SUB_TYPE_LOWER_PHY   = 5,       /**< 下级外物理域 */
    ORG_RES_SUB_TYPE_PARITY_PHY  = 6,       /**< 平级外物理域 */

    ORG_RES_SUB_TYPE_MAX,                   /**< 枚举最大值 */
    ORG_RES_SUB_TYPE_INVALID = 0xFFFFFFFF   /**< 无效值 */
}RES_SUB_TYPE_E;

/**
* @enum tagExdomainResQueryPolicy
* @brief 外域资源查询策略枚举
* @attention
*/
typedef enum tagExdomainResQueryPolicy
{
    EXDOMAIN_RES_QUERY_POLICY_CURRENTORG              = 0,       /**< 只查询当前组织下的资源信息 */
    EXDOMAIN_RES_QUERY_POLICY_CONTAINSUBRES           = 1,       /**<查询所有子组织的资源信息 */

    EXDOMAIN_RES_QUERY_POLICY_MAX,                              /**< 设备外域资源查询策略枚举最大值 */
    EXDOMAIN_RES_QUERY_POLICY_INVALID        = 0xFF             /**< 无效值 */
}EXDOMAIN_RES_QUERY_POLICY_E;

/**
* @enum tagAlarmOutputSetType
* @brief 设置告警输出动作类型
* @attention
*/
typedef enum tagAlarmOutputSetType
{
    ALARM_OUTPUT_OFF = 0,  /**< 停止输出 */
    ALARM_OUTPUT_ON  = 1   /**< 开启输出 */

}ALARM_OUTPUT_SET_TYPE_E;

/**
* @enum tagUserLoginNameType
* @brief 用户登录名类型
* @attention 无
*/
typedef enum tagUserLoginNameType
{
    LONGIN_NAME_TYPE_USER_NAME = 0,        /**< 用户名称 */
    LONGIN_NAME_TYPE_USER_CODE = 1,        /**< 用户编码 */

    LONGIN_NAME_TYPE_MAX,                  /**< 用户登录名类型最大值 */
    LONGIN_NAME_TYPE_INVALID = 0xFFFF      /**< 用户登录名类型无效值 */
}USER_LOGIN_NAME_TYPE_E;

/**
* @enum tagStorageType
* @brief 存储类型
* @attention
*/
typedef enum tagStorageType
{
    STORAGE_TYPE_OWN    = 0,  /**< 独享存储 */
    STORAGE_TYPE_SHARE  = 1   /**< 共享存储 */

}STORAGE_TYPE_E;


/* BEGIN: Added by kf0092 for 摄像机组手动启停存储, 2013年3月11日 */
/**
* @enum tagCameraGroupOperateType
* @brief组操作类型
* @attention 无
*/
typedef enum tagCameraGroupOperateType
{
    CAMERA_GROUP_OPERATE_TYPE_STOP_STOR = 0,    /**< 停止中心录像 */
    CAMERA_GROUP_OPERATE_TYPE_START_STOR,       /**< 启动中心录像 */
    CAMERA_GROUP_OPERATE_TYPE_STOP_BROADCAST,   /**< 停止广播 */
    CAMERA_GROUP_OPERATE_TYPE_START_BROADCAST,  /**< 启动广播 */

    CAMERA_GROUP_OPERATE_TYPE_TYPE_MAX,         /**< 摄像机组操作类型最大值 */
    CAMERA_GROUP_OPERATE_TYPE_INVALID = 0xFFFF  /**< 摄像机组操作类型无效值 */
} CAMERA_GROUP_OPERATE_TYPE_E;

/* END  : Added by kf0092 for 摄像机组手动启停存储, 2013年3月11日 */

/**
* @enum tagTVWallExt
* @brief 电视墙内容类型
* @attention 无
*/
typedef enum tagTVWallExt
{
    TV_WALL_MONITOR = 0,    /**< 监视器 */
    TV_WALL_DC = 1          /**< DC */
} TV_WALL_EXT_E;

/* Begin: Added by zhangjirui00227, 2012-07-18 of IVSD01426国标 */
/** 告警级别 */
typedef enum tagAlarmPriority
{
    ALARM_PRIORITY_1 = 1, /* 1级警情 */
    ALARM_PRIORITY_2 = 2, /* 2级警情 */
    ALARM_PRIORITY_3 = 3, /* 3级警情 */
    ALARM_PRIORITY_4= 4, /* 4级警情 */

    AlARM_PRIORITY_MAX,                         /**< 最大值 */
    AlARM_PRIORITY_ALL      = 0xFFFE,           /**< 所有告警的特殊标记 */
    AlARM_PRIORITY_INVALID  = 0xFFFF            /**< 无效值 */
}ALARM_PRIORITY_E;

/** 报警方式 */
typedef enum tagAlarmMethod
{
    ALARM_METHODL_TEL = 1, /* 电话报警 */
    ALARM_METHOD_DEVICE = 2, /*设备报警 */
    ALARM_METHOD_MESSAGE = 3, /* 短信报警 */
    ALARM_METHOD_GPS = 4, /* GPS报警 */
    ALARM_METHOD_VEDIO = 5, /* 视频报警 */
    ALARM_METHOD_DEVICE_DEFECT = 6, /* 设备故障报警 */
    ALARM_METHOD_OTHER = 7, /* 其它报警 */

    AlARM_METHOD_MAX,                         /**< 最大值 */
    AlARM_METHOD_ALL      = 0xFFFE,           /**< 所有告警的特殊标记 */
    AlARM_METHOD_INVALID  = 0xFFFF            /**< 无效值 */
}ALARM_METHOD_E;
/* End: Added by zhangjirui00227, 2012-07-18 of IVSD01426国标 */

/**
* @enum tagDevInstType
* @brief 设备控制类型
* @attention 无
*/
typedef enum tagDevInstType
{
    DEV_INST_IMAGE_JOIN = 10,           /**< 图像拼接 */
    DEV_INST_ANALOG_INPUT = 11,         /**< 模拟输入 */
    DEV_INST_CAMERA_ANGLE_ZOME = 21,    /**< 摄像机角度和变倍 */
    DEV_INST_IMAGE_PARAM_ADJUST = 30,    /**< 图像参数调节 */
    /* AddedBy liuhongjieKF0170,2013-9-9  of 查询IPC是否支持区块OSD */
    DEV_INST_BLOCK_OSD_SUPPORT = 60,/**<区块OSD  */

    /* Begin: added by zhangdong(kf0134), 2013.10.15 for SDC3.5 支持全景拼接*/
    DEV_INST_VIDEO_JOIN = 91,         /**< 视频拼接*/
    DEV_INST_VIDEO_Cancle = 92,       /**< 取消视频拼接*/
    /* End: added by zhangdong(kf0134), 2013.10.15 for SDC3.5 支持全景拼接*/

    /*该区段用于命令透传--透传至设备*/
    DEV_INST_DC_COMMAND_BEGIN = 1000,
    DEV_INST_IMAGE_MOSAIC_JOIN = 1001,    /* SDC 大屏拼接*/    /* Added by zkf0134, 2013.10.25 for SDC 大屏拼接*/

	/* Begin: Added by luchunfeng02289, 2015-09-28 for ADU */
    DEV_INST_ADU_VID_JOIN = 1003,         /**< ADU全景拼接 */
    DEV_INST_ADU_VID_Cancle = 1004,       /**< ADU全景拼接取消 */
    DEV_INST_ADU_VID_STATE = 1005,        /**< ADU全景拼接查询 */
    DEV_INST_ADU_TV_WALL = 1006,          /**< ADU电视墙设置、查询 */
    DEV_INST_ADU_TV_WINCTL = 1007,        /**< ADU大屏控制 */
    /* End: Added by luchunfeng02289, 2015-09-28 for ADU */

    DEV_INST_DC_COMMAND_END = 1100,

    /*该区段用于命令透传 Added by c01344 for 2014-11-8 */
    DEV_INST_SCREEN_MIN = 1101,
    DEV_INST_SCREEN_RECORD_PLAY = 1102,   /* 录像回放 录像倍数反馈 */

    /* Begin: Added by luchunfeng02289, 2015-09-28 for ADU */
    DEV_INST_SCREEN_VIDEO_START = 1108,   /**< USB视频播放 */
    DEV_INST_SCREEN_VIDEO_STOP = 1109,    /**< USB视频停止播放 */
    DEV_INST_SCREEN_VIDEO = 1110,         /**< USB视频播放查询*/
    /* End: Added by luchunfeng02289, 2015-09-28 for ADU */

    DEV_INST_SCREEN_MAX = 1199,
    /*该区段用于命令透传 End by c01344 for 2014-11-8 */

	DEV_INST_CAMERA_MIN = 1200,
	DEV_INST_CAMERA_IR= 1201,
	DEV_INST_CAMERA_MAX = 1299,

	DEV_INST_CAMERA_SET_MIN = 1300,
	DEV_INST_CAMERA_SET_IR_MODE = 1301,
	DEV_INST_CAMERA_SET_IR_BRIGHT = 1302,
	DEV_INST_CAMERA_SET_MAX = 1399

} DEV_INST_TYPE_E;

/* Begin Added by zhudingjingKF0104, 2013-06-26 of 语音资源化 */
/**
* @enum tagAudioInputTypeForECR
* @brief 音频输入类型
* @attention 无
*/
typedef enum tagAudioInputTypeForECR
{
    AUDIO_INPUT_TYPE_FOLLOW             = 0,          /** 随路音频输入 */
    AUDIO_INPUT_TYPE_INDEPENDENT        = 1,          /** 独立音频输入 */

    AUDIO_RES_TYPE_INVALID              = 0xFF
}AUDIO_INPUT_TYPE_FOR_ECR_E;

/**
* @enum tagVoiceStatusForECR
* @brief 语音业务状态
* @attention 无
*/
typedef enum tagVoiceStatusForECR
{
    VOICE_STATUS_NORMAL          = 0,        /** 普通状态 */
    VOICE_STATUS_TALK            = 1,        /** 正在对讲 */
    VOICE_STATUS_BROADCAST       = 2,        /** 正在广播 */

    VOICE_STATUS_MAX,
    VOICE_STATUS_INVALID         = 0xFF
}VOICE_STATUS_FOR_ECR_E;
/* End Added by zhudingjingKF0104, 2013-06-26 of 语音资源化 */

/**
 * @struct tagMapRoadDirection
 * @brief 地图道路方向
 * @attention
 */
typedef enum tagMapRoadDirection
{
    MAP_ROAD_UP = 0,                       /**< 道路上行 */
    MAP_ROAD_DOWN = 1,                     /**< 道路下行 */
    MAP_ROAD_DOUBLE,                       /**< 道路双行道 */
    MAP_ROAD_NONE,                         /**< 未知方向 */
    MAP_ROAD_MAX
}MAP_ROAD_DIRECTION_E;

/* Begin:Added by gaoshufeng(00762),2014-4-21 for MPPD11595 */
/**
* @enum tagONVIFTransPackMode
* @brief ONVIF码流转TS模式
* @attention
*/
typedef enum tagONVIFTransPackMode
{
    ONVIF_TRANS_PACK_MODE_NO_TRANS                 = 0,   /**< 不转码流格式 */
    ONVIF_TRANS_PACK_MODE_UDP_TS                   = 1,   /**< ONVIF码流转UDP+TS */
    ONVIF_TRANS_PACK_MODE_RTP_TS                   = 2,   /**< ONVIF码流转UDP+TS */

    ONVIF_TRANS_PACK_MODE_BUTT
}ONVIF_TRANS_PACK_MODE_E;

/* Begin: Added by luhaitao/01337, 2014-07-03 for 双链路备份 */
/**
* @enum tagONVIFTransPackMode
* @brief ONVIF码流转TS模式
* @attention
*/
typedef enum tagBakeUpLinkFlag
{
    BAKE_UP_LINK_FLAG_NONE              = 0,   /**< 非主备链路 */
    BAKE_UP_LINK_FLAG_MAST              = 1,   /**< 主链路 */
    BAKE_UP_LINK_FLAG_BAKE              = 2,   /**< 备链路 */

    BAKE_UP_LINK_FLAG_BUTT
}BAKE_UP_LINK_FLAG_E;
/* End: Added by luhaitao/01337, 2014-07-03 for 双链路备份 */

/* Begin add by zhengyibing(01306), 2014-04-19 for 新国标修订*/
/**
 * @struct tagMapRoadDirection
 * @brief 模糊查询类型
 * @attention
 */
typedef enum tagIndistinctQueryType
{
    INDISTINCT_QUERY_NULL = 0,                       /**< 不进行模糊查询 */  /* 暂不使用，后期扩展*/
    INDISTINCT_QUERY_DOMAIN = 1,                     /**< 对域进行查询 */
    INDISTINCT_QUERY_DEVICE = 2,                       /**< 对前端设备进行查询 */
    INDISTINCT_QUERY_ALL = 3,                         /**< 模糊查询:对域和前端进行查询 */
    INDISTINCT_QUERY_MAX
}INDISTINCT_QUERY_TYPE_E;

/**
 * @struct tagMapRoadDirection
 * @brief 录像检索类型
 * @attention
 */
typedef enum tagRecordQueryType
{
    RECORD_QUERY_TIME = 0,                           /**< 计划类型存储的查询 */
    RECORD_QUERY_ALARM = 1,                         /**< 告警类型存储的查询 */
    RECORD_QUERY_MANUAL = 2,                        /**< 手动促发存储的查询 */
    RECORD_QUERY_ALL = 3,                            /**< 所有存储的查询 */
    RECORD_QUERY_NONE = 4,                           /* 无效值 */
    RECORD_QUERY_MAX
}RECORD_QUERY_TYPE_E;
/* End add by zhengyibing(01306), 2014-04-19 for 新国标修订*/
/* End:Added by gaoshufeng(00762),2014-4-21 for MPPD11595 */

/**
* @enum tagDBDevSubType
* @brief DB9500设备子类型
* @attention
*/
typedef enum tagDBDevSubType
{
    DB_DEV_SUB_TYPE_S                 = 0,   /**< DB从服务器 */
    DB_DEV_SUB_TYPE_M                 = 1,   /**< DB主服务器 */
} DB_DEV_SUB_TYPE_E;
/* End:Added by gaoshufeng(00762),2014-4-21 for MPPD11595 */

/* Begin Add by zhengyibing(01306), 2014-05-30 for 新国标修改三期 */
/**
 * @struct tagMapRoadDirection
 * @brief 摄像机配置查询方式
 * @attention
 */
typedef enum tagCameraConfgigQueryType
{
    CAMEAR_CONFIG_INFO_DEFAULT_CONFIG_QUEY = 0,                    /**< 基本查询方式(5项): 基本参数配置/视频参数配置范围/视频参数当前配置/音频参数配置范围/音频参数当前配置 */
    CAMEAR_CONFIG_INFO_SVC_ENCODE_CONFIG_QUEY = 1,                /**< 单独查询方式，SVAC编码配置查询 */
    CAMEAR_CONFIG_INFO_SVC_DECODE_CONFIG_QUEY = 2,                /**< 单独查询方式，SVAC解码配置查询*/

    CAMERA_CONFIG_INFO_DEFAULT_AND_SVAENCODE_QUERY_TYPE = 3,    /* 基本查询方式+SVAC编码查询 */
    CAMERA_CONFIG_INFO_DEFAULT_AND_SVADECODE_QUERY_TYPE = 4,    /* 基本查询方式+SVAC解码查询 */
    CAMERA_CONFIG_INFO_DEFAULT_AND_SVADECODE_AND_SVACENCODE_QUERY_TYPE = 5,    /* 基本查询方式+SVAC解码查询+SVAC编码查询 */

    CAMERA_CONFIG_INFO_TRANSFER = 6,                        /* 外域方式，直接透传到IPC */

    CAMEAR_CONFIG_INFO_QUERY_NONE = 7,                           /* 无效值 */
    CAMEAR_CONFIG_INFO_QUERY_MAX
}CAMERA_CONFIG_INFO_REQ_TYPE_E;



/* End Add by zhengyibing(01306), 2014-05-30 for 新国标修改三期 */



/* Begin Add by zhengyibing(01306), 2014-10-20 for 新国标目录兼容性修改 */
/**
 * @struct tagCatalogType
 * @brief 下级域目录挂载: 支持(0/1/2/3)
 * @brief 上级域目录推送方式: 支持(0/1/3)
 * @brief 平级域目录挂载和推送方式: 支持(0/1/3)
 * @attention
 */
typedef enum tagCatalogType
{
    DOMAIN_CATALOG_DEFAULT_MOUNT_TYPE = 0,                    /** 自适应默认挂载方式 */
    DOMAIN_CATALOG_UP_DEVICEID_MOUNT_TYPE = 1,                /** 按照上层DeviceID挂载(旧国标方式) */
    DOMAIN_CATALOG_CIVILCODE_MOUNT_TYPE = 2,                   /** 行政区划挂载方式*/
    DOMAIN_CATALOG_PARENTID_MOUNT_TYPE = 3,                    /* 父组织挂载方式(parentid挂载) */
    DOMAIN_CATALOG_MOUNT_TYPE_NONE = 4,                           /* 无效值 */
    DOMAIN_CATALOG_MOUNT_TYPE_MAX
}DOMAIN_CATALOG_MOUNT_TYPE_E;
/* End Add by zhengyibing(01306), 2014-10-20 for 新国标目录兼容性修改 */


typedef enum tagDevQueryType
{
    DEV_QUERY_IPC_WEBGPAE_URL = 10,           /**查询IPC的跳转URL  */
    DEV_QUERY_MAX,                         /**< 最大值 */
    DEV_QUERY_INVALID  = 0xFFFF            /**< 无效值 */

} DEV_QUERY_TYPE_E;

/* Begin added by l01420, 2014-6-30 for 自定义TS转码策略 */
/**
 * @enum tagTSRuleUAType
 * @brief TS UA类型
 * @attention
 */
typedef enum tagTSRuleUAType
{
    TS_RULE_UA_SRC      = 0,
    TS_RULE_UA_DST      = 1,
}TS_RULE_UA_TYPE_E;

/**
 * @enum tagTSRuleSrcType
 * @brief TS转码规则源类型
 * @attention
 */
typedef enum tagTSRuleSrcType
{
    TS_RULE_SRC_CAMERA     = 0,            /* 摄像机*/
    TS_RULE_SRC_ECR        = 1,            /* ECR*/
    TS_RULE_SRC_NVR        = 2,            /* NVR*/
    TS_RULE_SRC_DOMAIN     = 3,            /* 外域(下级域)*/
	TS_RULE_SRC_LV_DOMAIN  = 4,            /*平级域*/
    /* 非法值 */
    TS_RULE_SRC_INVALID
}TS_RULE_SRC_TYPE_E;

/**
 * @enum tagTSRuleSrcType
 * @brief TS转码规则目标类型
 * @attention
 */
typedef enum tagTSRuleDstType
{
    TS_RULE_DST_MONITOR     = 0,        /* 监视器*/
    TS_RULE_DST_XP          = 1,        /* XP播放器窗格 */
    TS_RULE_DST_DOMAIN      = 2,        /* 外域(上级域)*/
	TS_RULE_DST_LV_DOMAIN   = 3,        /*平级域*/
    /* 非法值 */
    TS_RULE_DST_INVALID
}TS_RULE_DST_TYPE_E;

/* End added by l01420, 2014-6-30 for 自定义TS转码策略 */

/**
 * @enum tagsServiceOnResType
 * @brief 资源业务枚举
 * @attention
 */
typedef enum tagServiceOnResType
{
	/* 通道级业务，枚举 0--100 */
	SERVICE_ON_RES_TYPE_CAM_SHARE   	 			= 0,            /**<摄像机被共享 */
	SERVICE_ON_RES_TYPE_ALARM_SRC_SHARE    		= 1,            /**<告警源被共享 */
	SERVICE_ON_RES_TYPE_ALARM_OUT_SHARE    		= 2,            /**<告警输出被共享 */
    SERVICE_ON_RES_TYPE_STORE    				= 3,            /**< 配置了存储 */
    SERVICE_ON_RES_TYPE_BACKUP  					= 4,            /**< 配置了备份 */
    SERVICE_ON_RES_TYPE_CAM_STREAM_STOR  		= 5,            /**< 配置了流转存 */
   	SERVICE_ON_RES_TYPE_CASE_BAK 				= 6,            /**< 配置了案件备份 */


	/* 设备级业务 101--200 */
	SERVICE_ON_RES_TYPE_TRANSPARENT_OPEN    	= 101,          /**< 透明通道已启用*/
	SERVICE_ON_RES_TYPE_TRANSPARENT_EXIST    	= 102,          /**< 存在透明通道*/
	SERVICE_ON_RES_TYPE_CAM_EXIST 				= 103,          /**< 存在摄像机*/
	SERVICE_ON_RES_TYPE_ALARM_SRC_EXIST 		= 104,          /**< 存在告警源*/
	SERVICE_ON_RES_TYPE_ALARM_OUT_EXIST 		= 105,          /**< 存在告警输出*/
	SERVICE_ON_RES_TYPE_MONITOR_EXIST 			= 106,          /**< 存在监视器*/
	SERVICE_ON_RES_TYPE_CAM_EXIST_FOR_ECR  		= 107,          /**< 存在ECR/NVR下的摄像机*/
	SERVICE_ON_RES_TYPE_ALARM_SRC_EXIST_FOR_ECR = 108,         /**< 存在ECR/NVR下的告警源*/
	SERVICE_ON_RES_TYPE_ALARM_OUT_EXIST_FOR_ECR = 109,         /**< 存在ECR/NVR下的告警源*/

    SERVICE_ON_RES_TYPE_MAX,                     /**< 告警设备枚举最大值 */
    SERVICE_ON_RES_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}SERVICE_ON_RES_TYPE_E;

/* Begin add by l01420, 2014-7-10 for 丹东局点需求汇总*/
/**
* @enum tagAlarmSrcType
* @brief 告警源类型枚举
* @attention
*/
typedef enum tagAlarmSrcType
{
    ALARMSRC_CAM_FOLDER                 = 0,        /* 告警源-摄像机文件夹*/
    ALARMSRC_BOOLEAN_FOLDER             = 1,        /* 告警源-开关量文件夹*/
    ALARMSRC_GENERAL_FOLDER             = 2,        /* 告警源-第三方设备文件夹*/
    ALARMSRC_DEV_FOLDER                 = 3,        /* 告警源-设备运维文件夹*/
    ALARMSRC_TOLLGATE_FOLDER            = 4,        /* 告警源-卡口文件夹*/

    ALARMSRC_MAX                        = 0xff,
    ALARMSRC_INVALID
}ALARM_SRC_TYPE_E;
/* End add by l01420, 2014-7-10 for 丹东局点需求汇总*/


/* Begin add by zhengyibing(01306), 2015-01-26 for onvif摄像机自适应主辅流策略*/
/**
 * @struct tagOnvifStreamPolicy
 * @brief onvif摄像机主辅流策略
 * @attention
 */
typedef enum tagOnvifStreamPolicy
{
    ONVIF_STREAM_SELF_ADAPTION_POLICY = 0,            /**< 自适应策略, 分辨率最大为主流，分辨率最小为辅流 */
    ONVIF_STREAM_FIRST_POLICY = 1,                      /**< 主辅码流为第一股流 */
    ONVIF_STREAM_NONE_POLICY = 2,                           /* 无效值 */
    ONVIF_STREAM_MAX
}ONVIF_STREAM_POLICY_E;
/* End add by zhengyibing(01306), 2015-01-26 for onvif摄像机自适应主辅流策略*/

/* Added by y01693 for mppd21982 20150128 begin */
/**
* @enum tagTMSCombineType
* @brief TMS卡口违法合成数据类型
* @attention
*/
typedef enum tagTMSCombineType
{
    TMS_COMBINE_TOLLGATE                 = 0,   /**< 卡口 */
    TMS_COMBINE_E_POLICE                 = 1,   /**< 电警 */
    TMS_COMBINE_P2P                      = 2,   /**< 区间测速 */
    TMS_COMBINE_VIOLATE_PARK_BALL        = 3,   /**< 违停球 */

    TMS_COMBINE_MAX,                            /**< 枚举最大值 */
    TMS_COMBINE_INVALID = 0xFFFFFFFF            /**< 无效值 */
} TMS_COMBINE_TYPE_E;
/* Added by  y01693  for mppd21982  20150128  end */

/* Begin Add By hexiaojun/hW0959 for 云台摄像机云台控制是否经过云台控制器 2015-1-21 */
/**
* @enum tagIsPassPTZCtroller
* @brief 选择是否进过云台控制器状态枚举
* @attention
*/
typedef enum tagIsPassPTZCtroller
{
    CAMERA_NOT_PASS_PTZCTROLLER          = 0,    /**< 不经过云台控制器 */
    CAMERA_PASS_PTZCTROLLER              = 1,    /**< 经过云台控制器 */
    CAMERA_PASS_AND_NOTPASS_PTZCTROLLER  = 2,    /**< 选择全部全部*/
    CAMERA_NOT_PASS_AND_NOTPASS_PTZCTROLLER =3,  /**< 不选择任何云台摄像机 */

    PASS_STATUS_MAX,                    /**< 枚举最大值 */
    PASS_STATUS_INVALID    = 0xFFFFFFFF /**< 无效值 */
}IS_PASS_PTZCTROLLER_E;
/* End Add By hexiaojun/hW0959 for 云台摄像机云台控制是否经过云台控制器 2015-1-21 */

/* Begin: Added by zhongke, 2015-05-11 for CDS云存储 */
/**
* @enum tagCruiseInfoChangeType
* @brief 巡航信息变更类型
* @attention
*/
typedef enum tagCruiseInfoChangeType
{
    CRUISE_INFO_CHANGE_TYPE_PATH_ADD   = 0,     /**< 巡航路径增加 */
    CRUISE_INFO_CHANGE_TYPE_PATH_MOD,           /**< 巡航路径修改 */
    CRUISE_INFO_CHANGE_TYPE_PATH_DEL,           /**< 巡航路径删除 */
    CRUISE_INFO_CHANGE_TYPE_PLAN_ADD,           /**< 巡航计划增加 */
    CRUISE_INFO_CHANGE_TYPE_PLAN_MOD,           /**< 巡航计划修改 */
    CRUISE_INFO_CHANGE_TYPE_PLAN_DEL,           /**< 巡航计划删除 */

    CRUISE_INFO_CHANGE_TYPE_MAX,
    CRUISE_INFO_CHANGE_TYPE_INVALID = 0xFFFFFFFF

}CRUISE_INFO_CHANGE_TYPE_E;

/**
* @enum tagAsCruiseChgInfo
* @brief 巡航信息变更消息结构
* @attention
*/
typedef struct tagAsCruiseChgInfo
{
    CHAR szCameraCode[IMOS_CODE_LEN];           /**< 摄像机编码 */
    ULONG ulChangeType;                         /**< 信息变更类型  CRUISE_INFO_CHANGE_TYPE_E */
    IMOS_ID idChangeInfoId;                     /**< 变更信息ID */
}AS_CRUISE_CHANGE_INFO_S;
/* End: Added by zhongke, 2015-05-11 for CDS云存储 */

/**
* @enum tagExdomainOperType
* @brief 外域操作类型
*/
typedef enum tagExdomainOperType
{
    EXDOMAIN_OPER_ADD       = 0,    /** <外域操作类型: 添加*/
    EXDOMAIN_OPER_MOD       = 1,    /** <外域操作类型: 修改*/
    EXDOMAIN_OPER_DEL       = 2,    /** <外域操作类型: 删除*/

    EXDOMAIN_OPER_MAX,
    EXDOMAIN_OPER_INVALID   = 0xFFFF
}EXDOMAIN_OPER_TYPE_E;

/**
* @enum tagPdtType
* @brief 产品类型
*/
typedef enum tagPdtType
{
    PDT_TYPE_IMOS           = 0,    /** <IMOS产品*/
    PDT_TYPE_NONBRAND       = 1,    /** <白牌产品*/

    PDT_TYPE_MAX,
    PDT_TYPE_INVALID        = 0xFF
}PDT_TYPE_E;

/*Begin added by liangchao, 2015-11-25 for BM2516合主线:添加备份一体机进行license校验*/
/**
 * @enum tagBMDevType
 * @brief 告警设备类型
 * @attention
 */
typedef enum tagBMDevType
{
    BM_DEV_TYPE_3_0       = 0,            /**< BM3.0 */
    BM_DEV_TYPE_BM2516_DA = 1,            /**< BM2516-DA */
    BM_DEV_TYPE_BM8516    = 2,            /**< BM8516 */
    BM_DEV_TYPE_BM8500_E  = 3,            /**< BM8500-E */
    /* Begin: Add by lW2822, 2016-09-29 for 平台接入BM9500 */
    BM_DEV_TYPE_BM9500    = 4,            /**< BM9500 */
    /* End: Add by lW2822, 2016-09-29 for 平台接入BM9500 */

    BM_DEV_TYPE_MAX,                     /**< BM设备枚举最大值 */
    BM_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}BM_DEV_TYPE_E;
/*End added by liangchao, 2015-11-25 for BM2516合主线:添加备份一体机进行license校验*/

/*Begin added by liangchao, 2015-12-18 for IAFA license添加*/
/**
 * @enum tagIADevType
 * @brief 人脸卡口类型
 * @attention
 */
typedef enum tagIADevType
{
    IA_DEV_TYPE_IAHR  = 0,            /**< IAHR */
    IA_DEV_TYPE_IAFA  = 1,            /**< IAFA */
    IA_DEV_TYPE_IAIT  = 2,			  /**< IAIT */
    IA_DEV_TYPE_IAM  = 3,            /**< IAM */

    IA_DEV_TYPE_MAX,                     /**< IA设备枚举最大值 */
    IA_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< 无效值 */

}IA_DEV_TYPE_E;
/*End added by liangchao, 2015-12-18 for IAFA license添加*/

/* Begin added by y01359, 2016-04-12 for A8 */
/**
 * @enum tagTVWallMonitorAlarmOperateType
 * @brief 电视墙实况告警操作类型
 * @attention
 */
typedef enum tagTVWallMonitorAlarmOperateType
{
    TVWALL_MONITOR_ALARM_STOP   = 0,            /**< 停止电视墙实况告警 */
    TVWALL_MONITOR_ALARM_START  = 1,            /**< 启动电视墙实况告警 */

    TVWALL_MONITOR_ALARM_INVALID = 0xFFFFFFFF     /**< 无效值 */

}TVWALL_MONITOR_ALARM_OPERATE_TYPE_E;
/* End added by y01359, 2016-04-12 for A8 */

/* Begin added by c02845,2016-05-12,交通流信息接入*/
/**
 * @enum tagTrafficQueryType
 * @brief  查询时间方式
 * @attention 按日、月、年等方式
 */
typedef enum tagTrafficQueryTime
{
    TRAFFIC_QUERY_TIME_DAY    = 0,              /**< 按日查询 */
    TRAFFIC_QUERY_TIME_MOMTH  = 1,              /**< 按月查询 */
    TRAFFIC_QUERY_TIME_YEAR   = 2,              /**< 按年查询 */

    TRAFFIC_QUERY_TIME_MAX,                     /**< 查询方式最大值 */
    TRAFFIC_QUERY_TIME_INVALID = 0xFFFFFFFF    /**< 无效值 */

}TRAFFIC_QUERY_TIME_E;


/**
 * @enum tagTrafficQueryType
 * @brief  查询信息类型
 * @attention 按车流总量、平均车速、平均排队长度等信息类型
 */
typedef enum tagTrafficQueryType
{
    TRAFFIC_QUERY_TYPE_VEHICLE_COUNT    = 0,              /**< 车流总数 */
    TRAFFIC_QUERY_TYPE_AVG_SPEED        = 1,              /**< 平均速度 */
    TRAFFIC_QUERY_TYPE_QUEUE_LENGTH     = 2,              /**< 排队长度 */

    TRAFFIC_QUERY_TYPE_MAX,                     /**< 查询方式最大值 */
    TRAFFIC_QUERY_TYPE_INVALID = 0xFFFFFFFF    /**< 无效值 */

}TRAFFIC_QUERY_TYPE_E;

/* End by c02845,2016-05-12,交通流信息接入*/

/* Begin added by s03924 for MPPD53784 2017/11/25 */
/**
 * @enum tagTrafficFlowState
 * @brief 交通流拥堵状态
 * @attation
 */
typedef enum tagTrafficFlowState
{
	TRAFFIC_FLOW_CONGESTION             = 1,              /**< 流量过大 */
	TRAFFIC_FLOW_CONGESTION_RECOVERY    = 2,              /**< 流量过大恢复 */
	TRAFFIC_FLOW_NORMAL                 = 3,              /**< 正常 */
	TRAFFIC_FLOW_LOW                    = 4,              /**< 流量过大 */
	TRAFFIC_FLOW_LOW_RECOVERY           = 5,              /**< 流量过大恢复 */
}TRAFFIC_FLOW_STATE_E;
/* End added by s03924 for MPPD53784 2017/11/25 */

typedef enum tagNetworkModeType
{
    NET_WORK_MODE_MULTI_ADDRESS   = 0x1, /* 多址 */
    NET_WORK_MODE_BLANCE          = 0x2,      /* 负载均衡 */
    NET_WORK_MODE_FAULT_TOLERANT  = 0x4,/* 网卡容错 */
    NET_WORK_MODE_BUTT
} NET_WORK_MODE_TYPE_E;

/* Begin Add By hexiaojun/h02450 for BM支持CDS存储 2016-2-25 */
/**
* @enum tagStorServiceType
* @brief 存储服务类型
* @attention
*/
typedef enum tagStorServiceType
{
    STOR_SERVICE_TYPE_DM    = 0,    /** 数据管理服务器(DM) */
    STOR_SERVICE_TYPE_CDS   = 1,    /** CDS */

    STOR_SERVICE_TYPE_MAX,
    STOR_SERVICE_TYPE_INVALID = 0xFFFFFFFF
}STOR_SERVICE_TYPE_E;
/* End Add By hexiaojun/h02450 for BM支持CDS存储 2016-2-25 */

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */
/**
 * @enum tagIOTDevType
 * @brief  IOT 设备类型
 * @attention
 */
typedef enum tagIOTDevType
{
    IOT_DEV_TYPE_DAE_2000    = 200,            /**< DAE2000 */
    IOT_DEV_TYPE_DAE_6000    = 600,            /**< DAE6000 */

    IOT_DEV_TYPE_MAX,                        /**< IOT设备类型最大值 */
    IOT_DEV_TYPE_INVALID     = 0xFF          /**< 无效值 */
}IOT_DEV_TYPE_E;

/**
* @enum tagWirelessInspection
* @brief 无线检测类型枚举(2200)
* @attention
*/
typedef enum tagWirelessInspection
{
    UNKNOWN_WIRELESS_INSPECTION = 0,                      /**< 未知 */
    RFID_WIRELESS_INSPECTION = 1,                         /**< RFID检测器 */
    WIFI_SNIFFER_WIRELESS_INSPECTION = 2,                 /**< WiFi sniffer检测器 */
    ZIGBEE_WIRELESS_INSPECTION = 3,                       /**< zigbee检测器 */
    BLUETOOTH_WIRELESS_INSPECTION = 4,                    /**< 蓝牙检测器 */

    WIRELESS_INSPECTION_MAX,                              /**< 无线检测类型枚举最大值 */
    WIRELESS_INSPECTION_INVALID = 0xFF                    /**< 无效值 */
}WIRELESS_INSPECTION_E;

/**
* @enum tagSensorType
* @brief 传感器类型枚举(2201)
* @attention
*/
typedef enum tagSensorType
{
    UNKNOWN_SENSOR = 0,                                    /**< 未知 */
    TEMPERATURE_SENSOR = 1,                                /**< 温度 */
    HUMIDITY_SENSOR = 2,                                   /**< 湿度 */
    WIND_DIRECTION_SENSOR = 3,                             /**< 风向 */
    RAINFALL_SENSOR = 4,                                   /**< 雨量/降水量 */
    PM25_SENSOR = 5,                                       /**< PM2.5 */
    PM100_SENSOR = 6,                                      /**< PM10.0 */
    CHANNEL_WATER_LEVEL_SENSOR = 7,                        /**< 河道水位 */
    NOISE_SENSOR = 8,                                      /**< 噪音 */
    ELECTRICITY_CONSUMPTION_SENSOR = 9,                    /**< 用电量 */
    UNDETERMINED_SENSOR = 10,                              /**< 待定 */
    SMOKE_SENSOR = 11,                                     /**< 烟雾 */
    GPS_BIG_DIPPER_SENSOR = 12,                            /**< GPS/北斗 */
    PUT_INTO_TYPE_LIQUID_LEVEL_SENSOR = 13,                /**< 投入式液位计 */
    IMMERSION_DETECTOR_SENSOR = 14,                        /**< 水浸检测器 */
    O2_CONCENTRATION_SENSOR = 15,                          /**< O2浓度检测仪 */
    H2S_CONCENTRATION_SENSOR = 16,                         /**< H2S浓度检测仪 */
    CH4_CONCENTRATION_SENSOR = 17,                         /**< CH4浓度检测仪 */
    CO_CONCENTRATION_SENSOR = 18,                          /**< CO浓度检测仪 */
    LINEAR_OPTICAL_FIBER_TEMPERATURE_SENSING_SENSOR = 19,  /**< 线型光纤感温探测器 */
    TURBIDITY_SENSOR = 20,                                 /**< 浊度 */

    SENSOR_TYPE_MAX,                                       /**< 传感器类型枚举最大值 */
    SENSOR_TYPE_INVALID = 0xFF                             /**< 无效值 */
}SENSOR_TYPE_E;

/**
* @enum tagPowerEquipmentType
* @brief 动力设备类型枚举(2202)
* @attention
*/
typedef enum tagPowerEquipmentType
{
    UNKNOWN_POWER_EQUIPMENT = 0,            /**< 未知动力设备类型 */
    WATER_PUMP = 1,                         /**< 水泵 */
    FAN = 2,                                /**< 风机 */
    AIR_VALVE = 3,                          /**< 风阀 */
    ELECTRONIC_MANHOLE_COVER = 4,           /**< 电子井盖 */
    AUTOMATIC_FIRE_EXTINGUISHER = 5,        /**< 自动灭火器 */
    THE_ACCESS_CONTROLLER = 6,              /**< 门禁控制器 */

    POWER_EQUIPMENT_TYPE_MAX,               /**< 动力设备类型枚举最大值 */
    POWER_EQUIPMENT_TYPE_INVALID = 0xFF     /**< 无效值 */
}POWER_EQUIPMENT_TYPE_E;

/**
* @enum tagCommunicationEquipmentType
* @brief 通信设备类型枚举(2203)
* @attention
*/
typedef enum tagCommunicationEquipmentType
{
    UNKNOWN_COMMUNICATION_EQUIPMENT = 0,            /**< 未知动力设备类型 */
    ACOUSTOOPTIC_ALARM = 1,                         /**< 声光报警器 */
    MEGAPHONE = 2,                                  /**< 喊话器 */
    INDUSTRIAL_TELEPHONE_SET = 3,                   /**< 工业电话机 */
    WIRELESS_AP = 4,                                /**< 无线AP */

    COMMUNICATION_EQUIPMENT_TYPE_MAX,               /**< 通信设备类型枚举最大值 */
    COMMUNICATION_EQUIPMENT_TYPE_INVALID = 0xFF     /**< 无效值 */
}COMMUNICATION_EQUIPMENT_TYPE_E;

/**
* @enum tagOtherEquipmentType
* @brief 其它设备类型枚举(2250)
* @attention
*/
typedef enum tagOtherEquipmentType
{
    UNKNOWN_OTHER_EQUIPMENT = 0,            /**< 未知其它设备类型 */
    UPS = 1,                                /**< UPS */
    BATTERY = 2,                            /**< 蓄电池 */
    LED = 3,                                /**< LED灯 */
    INFRARED_COUNTER_DETECTOR = 4,          /**< 红外对射探测器 */

    OTHER_EQUIPMENT_TYPE_MAX,               /**< 其它设备类型枚举最大值 */
    OTHER_EQUIPMENT_TYPE_INVALID = 0xFF     /**< 无效值 */
}OTHER_EQUIPMENT_TYPE_E;

/**
* @enum tagASIOTResStatus
* @brief 物联网推送资源状态枚举
* @attention
*/
typedef enum tagASIOTResStatus
{
    AS_IOT_RES_STATUS_ONLINE         = 1,    /**< 资源在线 */
    AS_IOT_RES_STATUS_OFFLINE        = 2,    /**< 资源离线 */
    AS_IOT_RES_STATUS_ONLINE_ON      = 3,    /**< 资源在线，且开关量打开 */
    AS_IOT_RES_STATUS_ONLINE_OFF     = 4,    /**< 资源在线，且开关量关闭 */
    AS_IOT_RES_STATUS_OFFLINE_ON     = 5,    /**< 资源离线，且开关量打开 */
    AS_IOT_RES_STATUS_OFFLINE_OFF    = 6,    /**< 资源离线，且开关量关闭 */

    AS_IOT_RES_STATUS_MAX,
    AS_IOT_RES_STATUS_INVALID = 0xFFFFFFFF
}AS_IOT_RES_STATUS_E;
/* End: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */

/* Begin: Added by chenmenglin 04110, 2017-09-11 for MPPD54245 A8拼控设备轮巡特性 */
/**
* @enum tagAutoPollReaveType
* @brief A8拼控自动布局轮巡抢占类型
* @attention
*/
typedef enum tagAutoPollReaveType
{
    AUTOPOLL_REAVE_TYPE_NOREAVE     =  0,           /**< 不抢占 */
    AUTOPOLL_REAVE_TYPE_REAVE       =  1,           /**< 抢占 */

    AUTOPOLL_REAVE_TYPE_MAX,                        /**< 自动布局轮巡抢占类型最大值 */
    AUTOPOLL_REAVE_TYPE_INVALID = 0XFFFFFFFF
}AUTOPOLL_REAVE_TYPE_E;
/* End: Added by chenmenglin 04110, 2017-09-11 for MPPD54245 A8拼控设备轮巡特性 */

/* Begin: Added by l03769, 2017-12-21 for MPPD53844 物联网资源管理二期 */
/**
* @enum tagIOTDevAttribute
* @brief 物联网设备属性
* @attention
*/
typedef enum tagIOTDevAttribute
{
    UNKNOW_IOT_DEV    = 0,     /**< 未知属性 */
    FIXTURE_IOT_DEV   = 1,     /**< 固定IOT设备 */
    MOBILE_IOT_DEV    = 2,     /**< 移动IOT设备 */

    IOT_DEV_ATTRIBUTE_MAX,
    IOT_DEV_ATTRIBUTE_INVALID = 0xFFFFFFFF
}IOT_DEV_ATTRIBUE_E;
/* End: Added by l03769, 2017-12-21 for MPPD53844 物联网资源管理二期 */

/*Begin added by liuyufei l04448 for MPPD54774 Xware本地输入,Dec 28, 2017*/
/**
* @enum tagXwareVIType
* @brief Xware设备视频输入端口类型
* @attention
*/
typedef enum tagXwareVIType
{
    XWARE_VI_TYPE_BNC   = 0,    /**< BNC */
    XWARE_VI_TYPE_VGA   = 1,    /**< VGA */
    XWARE_VI_TYPE_HDMI  = 2,    /**< HDMI */
    XWARE_VI_TYPE_DVID  = 3,    /**< DVI-D */
    XWARE_VI_TYPE_DVII  = 4,    /**< DVI-I */
    XWARE_VI_TYPE_DP    = 5,    /**< DP */
    XWARE_VI_TYPE_SDI   = 6,    /**< SDI */

    XWARE_VI_TYPE_INVALID = 0xFFFFFFFF
}XWARE_VI_TYPE;
/*End added by liuyufei l04448 for MPPD54774 Xware本地输入,Dec 28, 2017*/

/* Begin: Added by chenmenglin 04110, 2018-01-23 for MPPD54841 解决绑定与未绑定监视器未做区分问题 */
/**
* @enum tagMonitorBindStatus
* @brief 解码拼控设备监视器绑定状态
* @attention
*/
typedef enum tagMonitorBindStatus
{
    MONITOR_BIND_STATUS_UNBIND     = 0,           /**< 未绑定 */
    MONITOR_BIND_STATUS_BIND       = 1,           /**< 绑定 */

    MONITOR_BIND_STATUS_MAX,                      /**< 解码拼控设备监视器绑定状态最大值 */
    MONITOR_BIND_STATUS_INVALID    = 0XFFFFFFFF
}MONITOR_BIND_STATUS_E;
/* End: Added by chenmenglin 04110, 2018-01-23 for MPPD54841 解决绑定与未绑定监视器未做区分问题 */

#endif /* end of __cplusplus */

#endif

