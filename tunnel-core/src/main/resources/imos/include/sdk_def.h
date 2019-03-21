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
   Description: �꣬ö�ٶ����ĵ�

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
/** A8��ͼ��·�� */
#define A8_BASE_PICTURE_PATH "/mnt/syncdata/resftp/A8/BASEPIC/"

/** A8 EDID�ļ���·�� */
#define A8_EDID_PATH "/mnt/syncdata/resftp/A8/EDID/"

/** A8 EDID�ļ���С */
#define A8_EDID_SIZE 128

/** A8 EDID�ļ�����С */
#define A8_EDID_MAX_SIZE 256

/** Ĭ�ϵ���ǽ����ID */
#define CS_TVWALL_SCENE_ID 99

/*Begin: Modified by huangsen W4381, 2017-08-31 for MPPD50646 A8������չ*/
/** ����ǽ����������� */
#define TVWALL_SCENE_MAX_NUM 64
/*End: Modified by huangsen W4381, 2017-08-31 for MPPD50646 A8������չ*/

/** ����ǽ����Ĭ��ͷ */
#define  TVWALL_DEFAULT_CODE         "tvwall"

/** ����ǽ���ڱ���Ĭ��ͷ */
#define  WINDOW_DEFAULT_CODE         "window"

/** ����ǽ���������Ĭ��ͷ */
#define  CAMERA_DEFAULT_CODE         "cam"

/** ����ǽ����������Ĭ��ͷ */
#define  SCREEN_DEFAULT_CODE         "screen"

/** ����ǽ���������Ĭ��ͷ */
#define  TVWALL_SCENE_GROUP_DEFAULT_CODE         "scenegroup"

/** ����ǽ�����ñ��� */
#define A8_TVWALL_DISABLE_CODE "DISABLE_TVWALL_CODE"

/** ����ǽ�����������ñ��� */
#define A8_INVILD_SCREEN_CODE "INVALID_SCREEN_CODE"

/** ����ǽ����������ñ��� */
#define A8_INVILD_CAMERA_CODE "INVALID_CAMERA_CODE"

/** ����ǽ������Դ�����ñ��� */
#define A8_INVILD_SWITCH_RES_CODE "INVALID_SWITCH_RES_CODE"

/* End added by y01359 2014-10-09 for A8 */

/* Begin: Added by gupeng, 2017-10-15 for MPPD54245 A8����Ѳ���Կ��� */
/** ����ǽ��Ѳ��Դ�����ñ��� */
#define A8_INVILD_POLL_RES_CODE "INVALID_POLL_RES_CODE"
/* End: Added by gupeng, 2017-10-15 for MPPD54245 A8����Ѳ���Կ��� */

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE����ƽ̨ */
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

/* Begin: Added by maojiangfeng W4699, 2017-10-26 for MPPD50773 Xwareҵ���������ӷ������� */
#define     XWARE_REG_XML_NODE_SUP_PANE_TYPE        "SupportPaneTypes"
/* End: Added by maojiangfeng W4699, 2017-10-26 for MPPD50773 Xwareҵ���������ӷ������� */

/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE����ƽ̨ */


/** @brief ѡ��ֵ�ڴ�鳤����Сֵ */
#define IMOS_OPTION_BUFFER_LEN_MIN              1

/** @brief ѡ��ֵ�ڴ�鳤�����ֵ */
#define IMOS_OPTION_BUFFER_LEN_MAX              64


/** @brief һ������ǽ�����������������Ŀ */
#define IMOS_MONITOR_MAXNUM_PER_WALL            256

/* Begin Added by dengshuhua00673, 2013-02-05 of �Զ�������Ѳ */
/** @brief һ������ǽ�����ķ����������Ŀ */
#define IMOS_SPLIT_MAXNUM_PER_WALL  (SPLIT_SCR_MODE_MAX * IMOS_MONITOR_MAXNUM_PER_WALL)
/* End Added by dengshuhua00673, 2013-02-05 of �Զ�������Ѳ */

/*@brief �澯�����洢�������Ŀ */
#define IMOS_ALARM_STORE_ACTION_MAXNUM          16

/* Begin added by liuzhikun/01420, 2013-11-12 for �澯���������Խ� */
/*@brief �澯���������Խ������Ŀ */
#define IMOS_ALARM_VOCTALK_ACTION_MAXNUM          16
/* End added by liuzhikun/01420, 2013-11-12 for �澯���������Խ� */

/* Begin added by y01359, 2016-03-25 for A8 */
/*@brief �澯��������ǽʵ�������Ŀ */
#define IMOS_ALARM_TVWALL_MONITOR_ACTION_MAXNUM   16
/* End added by y01359, 2016-03-25 for A8 */

/*@brief �澯����������洢�������Ŀ */
#define IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM   16

/*@brief �澯����Ԥ��λ�������Ŀ */
#define IMOS_ALARM_PRESET_ACTION_MAXNUM         16

/*@brief �澯����ʵ��������������Ŀ */
#define IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM     16

/*@brief �澯����ʵ�����������������Ŀ */
#define IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM    16

/*@brief �澯������ͼ��˸�������Ŀ */
#define IMOS_ALARM_GIS_ACTION_MAXNUM            16

/*@brief �澯��������������������Ŀ */
#define IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM      16

/*@brief �澯�������ݵ������Ŀ */
#define IMOS_ALARM_BACKUP_ACTION_MAXNUM         16

/*@brief �澯�������Ż��ʼ������˵������Ŀ */
#define IMOS_ALARM_ACTION_RECEIVER_MAXNUM       300

/*@brief �澯�����������������Ŀ */
#define IMOS_ALARM_BUZZER_ACTION_MAXNUM         1

/*@brief ͸��ͨ��3PCCģʽ������Ĵ����� */
#define IMOS_TRANSPARENT_SERIAL_NUM             2

/*@brief �������������������Ŀ */
#define IMOS_SWITCH_CAM_MAXNUM                  32

/* @brief ������Դ������������ĿV2 */
#define IMOS_SWITCH_CAM_MAXNUM_V2               512

/*@brief Ѳ��·��Ԥ��λ�������ֵ */
#define IMOS_CRUISE_PATH_PRESET_MAX_COUNT       32

/*@brief �������������λ��Ŀ */
#define IMOS_ARRAY_SLOT_MAXNUM                  10

/*@brief ��ͨ���ڸ�����������Ŀ(3) */
#define IMOS_MASK_AREA_MAXNUM_III               3

/*@brief ��ͨ���ڸ�����������Ŀ(1) */
#define IMOS_MASK_AREA_MAXNUM_I                 1

/*@brief ��ͨ���ڵ�����������Ŀ */
#define IMOS_COVER_AREA_MAXNUM                   4

/*@brief NTP������������ */
#define IMOS_NTP_SERVER_MAXNUM                  3

/*@brief һ���澯Դ�豸�����ĵ�ͼ�б�������� */
#define IMOS_GIS_FOR_ALARM_SRC_MAX_NUM          5

/** ��˾��ͬ��ų��� */
#define IMOS_CONTRACT_ID                        32

/** license���кŹ���� */
#define IMOS_LICENSE_SERIALS_NUM                256

/** license��Ե�ҵ�������� */
#define IMOS_LICENSE_SERVICE_TYPE_NUM           20

/*@brief ��ҳ��ѯ�������ֵ */
#define IMOS_PAGE_QUERY_ROW_MAX_NUM             200

/** @brief һ�����͵������Դ��Ŀ */
#define IMOS_ONCE_SHARE_RES_MAXNUM              1    /**< MAX_DEVSHARE_ONCE_PUSH */

/** @brief EC�µ�CAM�����Ŀ*/
#define IMOS_MAX_CAMERA_NUM_PER_EC              64   /**< MAX_CAMERA_NUM_PER_EC */

/** @brief DC�µ�SCREEN�����Ŀ*/
#define IMOS_MAX_SCREEN_NUM_PER_DC              16   /**< MAX_SCREEN_NUM_PER_DC */

/** @brief URL�ַ�������.��Ҫ��MCͬ������ */
#define IMOS_IE_URL_LEN                         IMOS_STRING_LEN_512

/*@brief ��Чͨ���� */
#define IMOS_INVALID_CHANNEL_NO                 0xFF

/*@brief ÿ��XP��Ӧ��������� */
#define IMOS_XP_WIN_MAX_NUM                     128

/*@brief ��ѯ�����ݵ����̶� */
#define IMOS_QUERY_DATA_MAX_LEN                 64

/*@brief ��ѯ�������� */
#define IMOS_QUERY_ITEM_MAX_NUM                 16

/*@brief ����ӵ����������Ŀ */
#define IMOS_MAX_EXTERNAL_DOMAIN_NUM            2048


/*@brief ��Ϊ�����û����������ɫ���� */
#define IMOS_MAX_USER_ROLES_NUM                 16

/*@brief Notify��󳤶� */
#define IMOS_MAX_NOTIFY_LEN                     4096

/*@brief �豸״̬��������ֵ */
#define IMOS_DEV_STATUS_MAX_NUM                4


/*@brief ����������������ʾ��Ŀ */
#define IMOS_DISPLAY_MAXNUM_PER_LAYOUT          IMOS_MONITOR_MAXNUM_PER_WALL

/*@brief ����ʾ����������ʾ��Ŀ */
#define IMOS_DISPLAY_MAXNUM_PER_SALVO           256

/* Modify by g00351 for MPPD04637 ���߲���֧���Ĵ�����Э�飬��stGisMapShareInfo�ṹ��astMapParam������С��1��0��������B03D025�汾 */
/*@brief ����������������Դ��Ŀ */
//#define IMOS_SCENE_MAXNUM_RES                   256
#define IMOS_SCENE_MAXNUM_RES                   1

/** @brief ��Դ������Դ�������Ŀ(������ר��ָ��ʱ�ô˺�) */
#define IMOS_RES_NUM_MAX_PER_GROUP 256

/*@brief ͨ����������������Դ��Ŀ */
#define IMOS_COMMON_SWITCH_RES_MAXNUM           256

/* Begin: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */
/*@brief A8ƴ���豸��Ѳ������������Դ��Ŀ */
#define IMOS_AUTOPOLL_CAMERA_RES_MAXNUM           5000

/*@brief A8ƴ���豸��Ѳ����󴰿���Դ��Ŀ */
#define IMOS_AUTOPOLL_WINDOW_RES_MAXNUM           480

/*@brief A8ƴ���豸��Ѳ����������Ŀ */
#define IMOS_AUTOPOLL_WINDOWSPLIT_MAXNUM           480 * 16
/* End: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */

/** @brief һ����ͼ���������õ�������������� */
#define IMOS_GIS_MAX_HOTZONE_NUM_PER_MAP        32
/** @brief һ����ͼ���������õ�ͼ��(�����ȵ㡢�ı��������ͼ�ꡢ�澯Դͼ�ꡢ�澯���ͼ��)��������� */
#define IMOS_GIS_MAX_ICON_NUM_PER_MAP           2048

/* Modify by g00351 for MPPD04637 ���߲���֧���Ĵ�����Э�飬��stGisMapShareInfo�ṹ��astMapParam������С��1��0��������B03D025�汾 */
/** @brief ��ͼ�����Ĳ���������*/
//#define IMOS_MAX_GIS_MAP_PARAM_NUM             (IMOS_GIS_MAX_HOTZONE_NUM_PER_MAP + IMOS_GIS_MAX_ICON_NUM_PER_MAP)
#define IMOS_MAX_GIS_MAP_PARAM_NUM             1

/* ������ǰ¼��ṹ��ĳ��� */
#define IMOS_BEALARM_REPLAY_LEN                (IMOS_CODE_LEN + 8 + IMOS_TIME_LEN)

/*@brief ����ץ��Ԥ���ַ����ĳ��� */
#define IMOS_IDLE_LEN                          (IMOS_NAME_LEN + IMOS_CODE_LEN - 12 - IMOS_BEALARM_REPLAY_LEN)

/*@brief IMOSϵͳ����������� */
#define IMOS_SYS_PARAM_MAX_NUM                  128

/*@brief һ�ο��������¼�ʹ��������� */
#define IMOS_EVENT_ENABLE_ADD_MAX_NUM           1024

/** �¼������豸���������Ŀ */
#define IMOS_EVENT_TYPE_REL_MAX_NUM             128

/**���������Ż� */
#define NIC_COUNT_MAX      4

/* ONVIF FLOAT����:float����Ϊ32��Ϊ�˲����ʹ��48 */
#define ONVIF_FLOAT_LEN                     48

/**
* ONVIF OSD��ض���
*/

/* ONVIF URL���� */
#define ONVIF_URL_LEN                       256

/* ONVIF OSD�ı���󳤶� */
#define ONVIF_OSD_TEXT_MAX_LEN              256

/* ONVIF OSD������ */
#define ONVIF_OSD_MAX_NUM                   8

/* ONVIF date formate����*/
#define ONVIF_OSD_DATE_FORMAT_LEN           32

/* ONVIF date formate���֧����Ŀ*/
#define ONVIF_OSD_DATE_FORMAT_MAX_NUM       8

/* ONVIF text string type max length*/
#define ONVIF_OSD_TEXT_STRING_TYPE_MAX_LEN  32

/* ONVIF text string type max number*/
#define ONVIF_OSD_TEXT_STRING_TYPE_MAX_NUM  8

/* ONVIF time formate����*/
#define ONVIF_OSD_TIME_FORMAT_LEN           32

/* ONVIF time formate���֧����Ŀ*/
#define ONVIF_OSD_TIME_FORMAT_MAX           4

/* ONVIF OSD��ɫ���֧����Ŀ*/
#define ONVIF_OSD_COLOR_MAX_NUM             16

/* ONVIF OSD��ɫ��Χ���֧����Ŀ*/
#define ONVIF_OSD_COLOR_RANGE_MAX_NUM       16

/* ONVIF OSDͼƬ·�����֧����Ŀ*/
#define ONVIF_OSD_IMAGE_PATH_MAX_NUM        16

/* ONVIF OSD λ��������󳤶� */
#define ONVIF_OSD_POS_TYPE_MAX_LEN          32

/* ONVIF OSD λ�����������Ŀ */
#define ONVIF_OSD_POS_TYPE_MAX_NUM          8

/* ONVIF ACTIVE CELL ������ */
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
* ��Ƶ����
*/
/* ��Ƶ���������� */
#define ONVIF_VIDEO_ENCODER_MAX_NUM         16

/* ��Ƶ�������Ƴ��� */
#define ONVIF_VIDEO_ENCODER_NAME_LEN        64

/* ��Ƶ����token���� */
#define ONVIF_VIDEO_ENCODER_TOKEN_LEN       64

/**< ���ֱ��ʸ��� */
#define ONVIF_VIDEO_RESOLUTION_MAX_NUM      16

/**< ʱ�䳤�� */
#define ONVIF_TIME_LEN                      32

/**< ONVIF IPADDR���� */
#define ONVIF_IPADDR_LEN                    64

/**
* ��Ƶ����
*/
/* ��Ƶ������ */
#define ONVIF_AUDIO_ENCODER_MAX_NUM                 4

/* ��Ƶѡ�������� */
#define ONVIF_AUDIO_OPTIONS_MAX_NUM                 8

/* ��Ƶѡ������������� */
#define ONVIF_AUDIO_OPTIONS_BIT_RATE_MAX_NUM        8

/* ��Ƶѡ������������� */
#define ONVIF_AUDIO_OPTIONS_SAMPLE_RATE_MAX_NUM     8

/*
* @name ��������
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

/*Begin added by liangchao, 2015-11-25 for BM2516������*/
/**@brief DABackup */
#define IMOS_MANUFACTURER_TYPE_DABK       "DABackup"
/*End added by liangchao, 2015-11-25 for BM2516������*/
/** @} */

/*
* @name ��̨Э������
* @{
*/
/** @brief INTERNAL-PTZ */
#define IMOS_PTZ_PROTOCOL_TYPE_INTERNAL     "INTERNAL-PTZ"
/** @} */

/** @brief ��Ч�ĳ�ʼ����ַ��������IMG���� */
#define IMOS_SDK_CLIB_INVALID_IP_ADDRESS    "N/A"

/** @brief Adapter�ĳ�ʼ����ַ��������IMG���� */
#define IMOS_SDK_INITIATE_INVALID_IP_ADDRESS    "0.0.0.0"

/** @brief ��ʵ��ģ������ */
#define IMOS_SDK_MU_CLIB_MODULE_NAME       "VM"

/*******************************************************************************
SS��������
����Ѷ�����Ķ���ǰ������IMOS_�� �Ա�����
*******************************************************************************/
/*@brief Email��ǰ֪ͨ���� */
#define IMOS_EMAIL_NOTIFICATION_NUMBER                  3

/*@brief �᳡���Ƶ���󳤶� */
#define IMOS_HD_MAX_SITE_NAME_LEN                       31
#define IMOS_SITE_NAME_LEN                              48 /*< �ο� #IMOS_HD_MAX_SITE_NAME_LEN */

/*@brief �������Ƶ���󳤶� */
#define IMOS_HD_MAX_CONF_NAME_LEN                       31
#define IMOS_CONF_NAME_LEN                              48  /*< �ο� #IMOS_HD_MAX_CONF_NAME_LEN */

/*@brief �᳡���������֧�ֵ���ƵЭ���� */
#define IMOS_HD_MAX_AUDIO_PROTOCOL_NUM                  20

/*@brief ��������� */
#define IMOS_HD_MAX_BANNER_LEN                          43
#define IMOS_BANNER_LEN                                 66 /*< �ο� #IMOS_HD_MAX_BANNER_LEN */


/*@brief �����������󳤶� */
#define IMOS_HD_MAX_CONF_ALIAS_LEN                      31
#define IMOS_CONF_ALIAS_LEN                             (IMOS_HD_MAX_CONF_ALIAS_LEN + 1)

/*@brief Э�鶨���ÿ����������᳡�� */
#define IMOS_HD_MAX_SITE_PER_CONF_NUM                   256

/*@brief �ӻ��������� */
#define IMOS_HD_MAX_SUBPIC_NUM                          64

/*@brief �᳡�����������͸������֧�ֵ���Ƶ��ʽ�� */
#define IMOS_HD_MAX_VIDEO_FORMAT_NUM                    32

/*@brief �᳡���������֧�ֵ���Ƶ֡���� */
#define IMOS_HD_MAX_VIDEO_FRAMERATE_NUM                 7

/*@brief �᳡���������֧�ֵ���ƵЭ���� */
#define IMOS_HD_MAX_VIDEO_PROTOCOL_NUM                  4

/*@brief �᳡���������֧�ֵ���Ƶ������ */
#define IMOS_HD_MAX_VIDEO_RATE_NUM                      8

/*@brief ��������ͬʱ������������  */
#define IMOS_HD_MAX_SIM_CAP_NUM                         8



/*@brief ������������Ѳ���� */
#define IMOS_MC_MAX_CONF_CYCLE_TABLE_COUNT              10


/*@brief �����������󳤶� */
#define IMOS_MC_MAX_CONF_PWD_LEN                        11
#define IMOS_CONF_PWD_LEN                               (IMOS_MC_MAX_CONF_PWD_LEN + 1)

/*@brief ������ڸ��� */
#define IMOS_MC_MAX_LAN_NET_NUM                         4

/*@brief ���ڱ�ʶ��󳤶� */
#define IMOS_HD_MAX_NETCARD_NAME_LEN                    31
#define IMOS_NETCARD_NAME_LEN                           48 /*< �ο� #IMOS_HD_MAX_NETCARD_NAME_LEN */

/*@brief MCU���Ƶ���󳤶� */
#define IMOS_MC_MAX_MCU_NAME_LEN                        31
#define IMOS_MCU_NAME_LEN                               (IMOS_MC_MAX_MCU_NAME_LEN + 1)

/*@brief MCU�ⲿIP��ַ�������� */
#define IMOS_MC_MAX_MCU_IP_NUM                          4

/*@brief ÿ�����ڿ�����·�ɸ��� */
#define IMOS_MC_MAX_LAN_ROUTE_NUM                       20

/*@brief ÿ������ARP������ */
#define IMOS_MC_MAX_LAN_ARP_NUM                         20

/*@brief MAC��ַ��󳤶� */
#define IMOS_MC_MAX_MAC_ADDR_LEN                        20


/*@brief ����汾�ŵ���󳤶� */
#define IMOS_HD_MAX_SOFT_VERSION_LEN                    255
#define IMOS_SOFT_VERSION_LEN                           (IMOS_HD_MAX_SOFT_VERSION_LEN + 1)

/*@brief ÿ�������DSP�� */
#define IMOS_HD_MAX_DSP_PER_PLANK                       15

/*@brief ÿ��DSP����������� */
#define IMOS_HD_MAX_DSP_NUM_PER_CONF                    4

/*@brief �����ʼ�����󳤶� */
#define IMOS_HD_MAX_EMAIL_NAME_LEN                      63

/*@brief ���ͼ���ػ᳡���� */
#define IMOS_MC_MAX_WATCH_SITE_NUM                      9

/*@brief �ն���Ч������� */
#define IMOS_HD_VIDEO_OUT_NUM                          (4)

/*@brief �ն���/Ӳ���汾/���кų��� */
#define IMOS_HD_VERSION_LEN                            (32)

/*@brief UI��WEB��PC����û��� */
#define IMOS_HD_MAX_USER_NUM                           (32)

/*@brief Ԥ��λ�� */
#define IMOS_HD_MAX_CAM_PRE_NUM                        (20)

/*@brief �ն���������ַ������� */
#define IMOS_HD_MAX_NAME_LENGTH                        (32)

/*@brief �ն����IP�ַ������� */
#define IMOS_HD_MAX_IP_LENGTH                          (32)

/*@brief �ն����·���ַ������� */
#define IMOS_HD_MAX_PATH_LENGTH                        (100)

/*@brief �ն���������ַ������� */
#define IMOS_HD_MAX_PASSWORD_LENGTH                    (32)

/*@brief �ն����˽������ */
#define IMOS_HD_MAX_PRIVATE_NET_COUNT                  (4)

/*@brief ���MAC�ַ�����ʾ���� */
#define IMOS_HD_MAX_MAC_DISPLAYLENGTH                  (17)

/*@brief �����Ļ��Ŀ */
#define IMOS_TITLE_MAXNUM                              (2)

/*@brief �����Ļ���� */
#define IMOS_TITLE_LEN                                 (2404)

/*@brief һ����������ϵ�������Ŀ*/
#define IMOS_MAX_CONTACTS_IN_CONF                      (512)

/*@brief IMOS֧�ֵ���������Ŀ*/
#define IMOS_COMPONENT_MAX_NUM                         (50)

/*@brief MCU�����Ļ�᳡��Ŀ */
#define IMOS_MAX_SITE_LIVE_NUM                         (240)

/*@brief MCU�������鲥��Ŀ*/
#define IMOS_MAX_MULTI_ADDR_NUM                        (8)

/*@brief �����������·�� */
#define IMOS_MC_MAX_BITRATE_ADAPT_COUNT                (3)

/*@brief һ��������MCU�����Ŀ */
#define IMOS_MAX_MCU_IN_CONF                           (16)

/*@brief һ���������ն������Ŀ */
#define IMOS_MAX_TERM_IN_CONF                          (1024)


/*@brief ͸��ͨ��DIRECTģʽ�������IP�� */
#define IMOS_TRANSPARENT_IP_NUM                 1

/** @brief ���������㲥����֧�ֵ�������������  */
#define MAX_VOCBRD_CAM_NUM       128

/** @brief ��̨����ٶ�ֵ  */
#define MAX_PTZ_SPEED            9

/** @brief ����������󳤶�  */
#define IMOS_PROC_NAME_MAX_LEN                          32

/** @brief ������ֱ��ý��������ȱʡֵ */
#define IMOS_DEFAULT_NUM_OF_STREAM_BYPASS            1024

/*@brief ���������Ŀ */
#define IMOS_MAX_TASK_NUM                   (16)

/*@brief �澯ת���û������Ŀ */
#define IMOS_ALARM_ACTION_TRAN_MAXNUM       (300)

/*@brief �����������Ŀ */
#define IMOS_MAX_TRIGGER_NUM                (10)

/*@brief �¸澯�����Ŀ */
#define IMOS_MAX_NEW_ALARM_NUM              (1)

/*@brief ������Ԥ�������Ŀ */
#define IMOS_ALARM_ACTION_PLAN_MAXNUM       (1)

/*@brief ֧���¸澯���� */
#define IMOS_TYPE_NEW_ALARM                 (65534)

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/*@brief ��ͨ���ڸ�����������Ŀ(8) */
#define IMOS_MASK_AREA_MAXNUM_VIII              8
/** @brief ��������������� */
#define IMOS_VEHICLE_TYPE_MAX_NUM                    32
/** @brief ����ͼƬ�����ߴ� */
#define IMOS_PICTURE_SIZE_MAX_LEN                       (512*1024)

/*@brief ��������: ������ǿ */
#define IMOS_VIDEO_AREA_TYPE_ROI            3

/* End Added by lw0581,2013-11-6 for  VVD06374*/

/** @brief һ�����������������������Ŀ */
#define IMOS_CASE_MAXNUM_PER_SERIESCASE            64

/** @brief һ������¼�񱸷ݼ��������Ŀ */
#define IMOS_FILE_MAXNUM_PER_CASERECORD            8

/** @brief Υ������������� */
#define IMOS_VEHICLE_VIOLATION_MAX_NUM               200

/** @brief �����ֵ������������ */
#define IMOS_DIC_CODE_MAX_NUM                        200

/** @brief ��������������� */
#define IMOS_VEHICLE_TYPE_MAX_NUM                    32

/** @brief һ������������������� */
#define IMOS_VEHICLE_DISPOSITION_DOMAIN_MAX_NUM      200

/** @brief �����쳣��Ϊ�����������Ŀ������� */
#define IMOS_VEHICLE_ABNORMAL_ANALYSE_TG_MAX_NUM     200

/** @brief ����һ���ߵĵ������*/
#define IMOS_MAP_LINT_POINT_NUM                      2

/** @brief ��·������λ�� */
#define IMOS_MAP_ROAD_POINT_MAX_NUM                  64

/** @brief �������䳬�ٰٷֱ������������ */
#define IMOS_DETECTION_ROAD_SECTION_VIO_CONF_MAX_NUM 32

/** @brief TMS���ַת������������� */
#define TMS_MULTI_ADDR_FORWARD_RULE_MAX_NUM 64

/** @brief ����֧�ֵ���󳵵�����*/
#define IMOS_TOLLGATE_LANE_MAX_NUM          32

/** @brief �����Դ�б����� */
#define IMOS_RES_LIST_MAX_NUM                        200

/* Begin: Modifid by luhaitao/01337, 2016-03-29 for ��̶���� */
/** @brief ϵͳ�����������������ֿ��� */
#define IMOS_SYSTEM_PARAM_BKP_LINK_ENABLE_NAME	"bkp_link_enable_flag"

/** @brief ϵͳ������������������֧�ֱ�����Դ���� */
#define IMOS_SYSTEM_PARAM_BKP_LINK_ENABLE_LOC_RES_NAME "bkp_link_enable_loc_res_flag"
/* End: Modifid by luhaitao/01337, 2016-03-29 for ��̶���� */

#define NIC_COUNT_MAX      4

/* Begin: Added by l03769, 2017-09-18 for MPPD51448 ��������Դ��Ϣ��ѯ */
/** @brief �����������Դ�������� */
#define IMOS_IOT_RES_TYPE_MAX_NUM            50
/* End: Added by l03769, 2017-09-18 for MPPD51448 ��������Դ��Ϣ��ѯ */

/* Begin: Added by wW4366, 2017-09-11 for MPPD54245 A8ƴ���豸��Ѳ���� */
/** A8����ǽ������������� */
#define IMOS_TVWALL_SCREN_RES_MAXNUM     48
/* End: Added by wW4366, 2017-09-11 for MPPD54245 A8ƴ���豸��Ѳ���� */

/**
 * @enum tagIMOSThruLineDirection
 * @brief "������Ϊ"����
 * @attention
 */
typedef enum tagIMOSThruLineDirection
{
    IMOS_THRU_LINE_DIRECTION_CLOCKWISE          = 0,    /**< ˳ʱ�� */
    IMOS_THRU_LINE_DIRECTION_ANTICLOCKWISE      = 1,    /**< ��ʱ�� */
    IMOS_THRU_LINE_DIRECTION_ALL                = 2,    /**< ˫�� */

    IMOS_THRU_LINE_DIRECTION_MAX,
    IMOS_THRU_LINE_DIRECTION_INVALID            = 0XFFFFFFFF
} IMOS_THRU_LINE_DIRECTION_E;

/**
 * @enum tagIMOSAreaDirection
 * @brief "������Ϊ"����
 * @attention
 */
typedef enum tagIMOSAreaDirection
{
    IMOS_AREA_DIRECTION_IN       = 0,    /**< In */
    IMOS_AREA_DIRECTION_OUT      = 1,    /**< Out */
    IMOS_AREA_DIRECTION_ALL      = 2,    /**< ˫�� */

    IMOS_AREA_DIRECTION_MAX,
    IMOS_AREA_DIRECTION_INVALID  = 0XFFFFFFFF
} IMOS_AREA_DIRECTION_E;

/**
* @enum tagOptionName
* @brief ѡ����ö��
* @attention
*/
typedef enum tagOptionName
{
    OPTION_NAME_CC_SERVER_ADDR      = 0,            /**< CC�ķ�������ַ, ��Ӧ�ṹ : (CHAR *) */
    OPTION_IMOS_ROOT_PATH           = 1,            /**< IMOSROOT��������, ��Ӧ�ṹ : (CHAR *) */
    OPTION_PROTOCOL_PORT_RANGE      = 2,            /**< Э��Ķ˿ڷ�Χ, ��Ӧ�ṹ : (PORT_RANGE_S *) */
    OPTION_MEDIA_PORT_RANGE         = 3,            /**< ý�����Ķ˿ڷ�Χ,��Ӧ�ṹ : (PORT_RANGE_S *) */
    OPTION_NAME_SERVER_IMG_PORT      = 4,         /**< IMG�ķ������˿�, ��Ӧ�ṹ : (USHORT) */

    OPTION_NAME_MAX,
    OPTION_NAME_INVALID             = 0XFFFFFFFF
} OPTION_NAME_E;

/** @brief ECR���볤�� */
#define IMOS_ECR_CODE_LEN               (IMOS_CODE_LEN - 8)

/*@brief ϵͳ֧�ֵĸ��ߵ������ */
#define IMOS_TRUNK_MAXNUM                       32

/*@brief ������������������Ŀ */
#define IMOS_TRUNK_CONTENT_MAXNUM               256

/* Begin Added by liuhongjieKF0170,2013-8-28 of ֧������OSD */
/** 3D�ڸ����������� */
#define IMOS_MAX_3D_COVER_AREA_NUM     8
/* End Added by liuhongjieKF0170,2013-8-28 of ֧������OSD */

/** �ص�����������Ϣ���� */
typedef enum tagCallBackProcType
{
    PROC_TYPE_DEV_STATUS            = 0,            /**< �豸״̬����Ӧ�ṹ : AS_STAPUSH_UI_S */
    PROC_TYPE_ALARM                 = 1,            /**< �澯����Ӧ�ṹ : AS_ALARMPUSH_UI_S */
    PROC_TYPE_DEV_CAM_SHEAR         = 2,            /**< �������������Ӧ�ṹ : AS_DEVPUSH_UI_S */
    PROC_TYPE_MONITOR_BE_REAVED     = 3,            /**< ʵ������ռ����Ӧ�ṹ : CS_MONITOR_REAVE_NOTIFY_S */
    PROC_TYPE_SWITCH_BE_REAVED      = 4,            /**< ���б���ռ����Ӧ�ṹ : CS_SWITCH_REAVE_NOTIFY_S */
    PROC_TYPE_MONITOR_BE_STOPPED    = 5,            /**< ʵ����ֹͣ����Ӧ�ṹ : CS_MONITOR_REAVE_NOTIFY_S */
    PROC_TYPE_SWITCH_BE_STOPPED     = 6,            /**< ���б�ֹͣ����Ӧ�ṹ : CS_SWITCH_REAVE_NOTIFY_S */
    PROC_TYPE_VOCSRV_BE_REAVED      = 7,            /**< ��������ռ����Ӧ�ṹ : CS_VOCSRV_REAVE_NOTIFY_S */
    PROC_TYPE_PTZ_EVENT             = 8,            /**< ��̨�¼�֪ͨ����Ӧ�ṹ : CS_PTZ_REAVE_NOTIFY_S */
    PROC_TYPE_TRB_PROC              = 9,            /**< ���ϴ���֪ͨ����Ӧ�ṹ : CS_NOTIFY_UI_TRB_EVENT_PROC_S */
    PROC_TYPE_SRV_SETUP             = 10,           /**< ���ϻָ�ҵ����֪ͨ����Ӧ�ṹ : CS_NOTIFY_UI_SRV_SETUP_S */
    PROC_TYPE_XP_ALARM_SETUP        = 11,           /**< �澯������XP����֪ͨ����Ӧ�ṹ : CS_NOTIFY_UI_SRV_SETUP_S */

    PROC_TYPE_LOGOUT                = 12,           /**< �˳���½����Ӧ�ṹ :�� */

    PROC_TYPE_MEDIA_PARAM_CHANGE    = 13,           /**< ý������ı䣬��Ӧ�ṹ : CS_NOTIFY_UI_MEDIA_PARAM_CHANGE_PROC_S */

    PROC_TYPE_EXDOMAIN_STATUS       = 14,           /**< ����״̬����Ӧ�ṹ : AS_EXDOMAIN_STAPUSH_UI_S */

    PROC_TYPE_BACKUP_DATA_FINISH    = 15,           /**< ��Ϣ�������֪ͨ, ��Ӧ�ṹ : CS_BACKUP_FINISH_INFO_S */

    PROC_TYPE_TL_EVENT              = 16,           /**< ͸��ͨ���¼�֪ͨ����Ӧ�ṹ : CS_TL_REAVE_NOTIFY_S */

    PROC_TYPE_SALVO_UNIT_EVENT      = 17,           /**< ����ʾ��Ԫ�¼�֪ͨ, ��Ӧ�ṹ : CS_NOTIFY_SALVO_UNIT_EVENT_S */
    PROC_TYPE_SALVO_EVENT           = 18,           /**< ����ҵ���¼�֪ͨ, ��Ӧ�ṹ : CS_NOTIFY_UI_SALVO_EVENT_S */
    PROC_TYPE_START_XP_SALVO        = 19,           /**< ֪ͨUI��������Ѳ������ʾ, ��Ӧ�ṹ: CS_NOTIFY_START_XP_SALVO_S */

    PROC_TYPE_VODWALL_BE_REAVED     = 20,           /**< ֪ͨ�ط���ǽ����ռ����Ӧ�ṹ��CS_VODWALL_REAVE_NOTIFY_S */
    PROC_TYPE_VODWALL_BE_STOPPED    = 21,           /**< ֪ͨ�ط���ǽ��ֹͣ����Ӧ�ṹ��CS_VODWALL_REAVE_NOTIFY_S */

    PROC_TYPE_VOD_BE_REAVED         = 22,           /**< �طű���ռ����Ӧ�ṹ : CS_VOD_REAVE_NOTIFY_S */

    PROC_TYPE_DOMAIN_SYN_RESULT     = 23,           /**< ���ͬ���Ľ������Ӧ�ṹ : AS_DOMAIN_SYN_PUSHUI_S */

    PROC_TYPE_VOC_REQ               = 24,           /**< �ͻ����������󣬶�Ӧ�ṹ : CS_VOC_REQ_NOTIFY_S */
    PROC_TYPE_VOC_STATE_NOTIFY      = 25,           /**< ����ҵ��״̬֪ͨ����Ӧ�ṹ : CS_VOC_STATE_NOTIFY_S */

    PROC_TYPE_PLAN_ALARM_CHG_REPORT = 26,           /**< Ԥ���澯�仯�ϱ�����Ӧ�ṹ��PLAN_ALARM_CHG_PUSH_UI_S */
    PROC_TYPE_EVENT_SECURITY_CHG_REPORT = 27,       /**< ϵͳ������Ϣ�仯�ϱ�����Ӧ�ṹ��EVENT_SECURITY_CHG_PUSH_UI_S */
	PROC_TYPE_OSD_NAME_CHANGED		= 30,			/**< ֪ͨ�˻�Preview�û�OSD�������Ӧ�ṹ: AS_NOTIFY_OSD_NAME_UI_S */
	PROC_TYPE_MASK_AREA_CHANGED		= 31,			/**< ֪ͨ�˻�Preview�û��ڵ�����������Ӧ�ṹ: AS_NOTIFY_EC_MASK_AREA_UI_S */

    PROC_TYPE_PTZ_STATUS_EVENT      = 32,           /**< ��̨״̬���֪ͨ����Ӧ�ṹ : CS_PTZ_STATUS_NOTIFY_S */
    PROC_TYPE_DEL_EXDOMAIN_RESULT   = 33,           /**< ɾ������������Ӧ�ṹ: AS_DEL_EXDOMAIN_PUSH_UI_S*/
    /* Added by dengshuhua00673, 2013-02-20 of �Զ�������Ѳ */
    PROC_TYPE_START_XP_AUTOSALVO    = 34,           /**< ֪ͨUI�����Զ���������Ѳ, ��Ӧ�ṹ: CS_NOTIFY_START_XP_AUTOSALVO_S */

    /** Begin:add by sunxiaojisKF0138, 2013-7-21 of NVRV3R1 **/
    PROC_TYPE_GET_CHANNEL_MSG_FROM_CS_TO_UI = 35,      /**< ͸��ͨ������͸����Ϣ�������� */
    /** End:add by sunxiaojisKF0138, 2013-7-21 of NVRV3R1 **/

    /* Begin added by baoyihui02795, 2011-04-28 of ������Ŀ */
    PROC_TYPE_VEHICLE_DATA          = 90,           /**< ֪ͨʵʱ������Ϣ����Ӧ�ṹ:VEHICLE_REAL_TIME_DATA_S */
    PROC_TYPE_VEHICLE_ALARM_DATA    = 91,           /**< ֪ͨʵʱ������������Ӧ�ṹ:VEHICLE_ALARM_DATA_S */
    PROC_TYPE_GIS_DEV_STATUS        = 92,           /**< ֪ͨGIS�豸״̬�仯����Ӧ�ṹ��DEVICE_GIS_STATUS_DATA_S */
    /* End added by baoyihui02795, 2011-04-28 of ������Ŀ */
    PROC_TYPE_ELEC_BULLETIN_CHANGE  = 93,           /**< ���ӹ���仯�ϱ�����Ӧ�ṹ��ELEC_BULLETIN_PUSH_UI_S */

    /*******************************************************************************
    SS�������� �����ص�����
    *******************************************************************************/
    PROC_TYPE_ACCEPT_SPEAK_YESORNO  = 100,           /**< �������룬 ��Ӧ�ṹ ��CONF_SITE_INFO_EX_S */
    PROC_TYPE_CONF_STATUS_CHANGE    = 101,           /**< ����״̬�ı䣬 ��Ӧ�ṹ ��CONF_STATUS_INFO_EX_S ��������ڻ����ҷ����һ�����ڣ��ϱ�����δ��ʼ/�����ϱ������Ѿ����� */
    PROC_TYPE_DEVICE_CODE_CHANGE    = 102,           /**< �豸����ı䣬 ��Ӧ�ṹ ��DEVICE_CODE_CHANGE_INFO_EX_S */
    PROC_TYPE_DEVICE_CHANGE         = 103,           /**< �ն��豸������Ϣ�� �������豸������ɾ��ʱ�� �ϱ�������Ϣ�� ��Ӧ�Ľṹ ��DEVICE_CHANGE_INFO_EX_S */
    PROC_TYPE_MODIFY_TERM           = 104,           /**< �޸��ն���Ϣ�� ��Ӧ�Ľṹ ��MODIFY_TERM_REP_EX_S */
    PROC_TYPE_CHAIR_CHANGE          = 105,           /**< ��ǰ��ϯ�����ı䣬 ��ϯ�᳡�ͷ���᳡����Ϊ�ա���Ӧ�Ľṹ ��CONF_SITE_INFO_EX_S */
    PROC_TYPE_SPEAKER_CHANGE        = 106,           /**< ��ǰ�����˷����ı䣬 ��Ӧ�Ľṹ ��CONF_SITE_INFO_EX_S */
    PROC_TYPE_TERM_STATUS_CHANGE    = 107,           /**< �᳡�ն�״̬�ı䣬 ��Ӧ�Ľṹ ��TERM_STATUS_CHANGE_EX_S */
    PROC_TYPE_DELAY_CONF            = 108,           /**< �ӳٻ��飬 ��Ӧ�ṹ ��DELAY_CONF_INFO_EX_S */
    PROC_TYPE_SYNCHRONIZE_WITH_WEB  = 109,           /**< �ϱ��㲥�᳡�� ��ϯ�������ۿ��᳡ ��Ӧ�Ľṹ �� MC_SYNCHRONIZE_WITH_WEB_EX_S  */
    PROC_TYPE_MCU_BACKUP_CHANGE_TO_MASTER  = 110,    /**< MCU����֪ͨ�� ��Ӧ�ṹ ��BACKUP_MCU_REPORT_S  */
    PROC_TYPE_SEND_ROLE_SITE_CHANGE = 111,           /**< ��ǰ���������߱仯֪ͨ�� ��Ӧ�ṹ ��CONF_SEND_ROLE_SITE_CHANGE_S  */
    PROC_TYPE_AUTOMULTIPIC_CHANGE   = 112,           /**< �໭���Զ��л�ֵ�ı�֪ͨ�� ��Ӧ�ṹ ��CONF_AUTOMULTIPIC_CHANGE_S  */
    PROC_TYPE_SET_TURN_BROADCAST_CHANGE = 113,       /**< ���û�����ѯģʽ�ı�֪ͨ�� ��Ӧ�ṹ ��CONF_SET_TURN_BROADCAST_CHANGE_S */
    PROC_TYPE_SET_PIC_MODE_CHANGE   = 114,           /**< ���û���ģʽ�ı�֪ͨ�� ��Ӧ�ṹ ��CONF_SET_PIC_MODE_CHANGE_S */
    PROC_TYPE_MCU_SYNC_STATUS_CHANGE = 115,          /**< MCUͬ��״̬�ı�֪ͨ�� ��Ӧ�ṹ ��MCU_SYNC_STATUS_CHANGE_S */
    PROC_TYPE_CUR_BROADCAST_CHANGE   = 116,          /**< ��ǰʵ�ʹ㲥�᳡�ı�֪ͨ����Ӧ�ṹ��CUR_BROADCAST_INFO_EX_S */
    PROC_TYPE_CUR_CHAIR_BROWSE_CHANGE     = 117,     /**< ��ǰ��ϯ������ʵ�ʹۿ��Ļ᳡�ı�֪ͨ����Ӧ�ṹ��CUR_CHAIR_BROWSE_INFO_EX_S */
    PROC_TYPE_CONF_FECC_CHANGE       = 118,          /**< ��ǰFECC�����߻򱻿��߱仯֪ͨ����Ӧ�ṹ��CONF_FECC_CHANGE_S */
    PROC_TYPE_CONF_MCU_BACKUP_CHANGE      = 119,     /**< ��ǰ������MCU���ݱ仯֪ͨ����Ӧ�ṹ��CONF_MCU_BACKUP_CHANGE_S */
    PROC_TYPE_CALL_SITE_RESULT       = 120,          /**< ���л᳡���֪ͨ����Ӧ�ṹ��CALL_SITE_INFO_EX_S */
    PROC_TYPE_GK_REG_STATE           = 121,          /**< GKע����֪ͨ����Ӧ�ṹ��GK_REG_STATE_INFO_EX_S */
    PROC_TYPE_MG_SESSION_STATUS_CHANGE    = 122,     /**< �ն˻Ự״̬����Ӧ�ṹ��MG_SESSION_STATUS_EX_S */
    PROC_TYPE_FREE_STORE_RES_SUCCEED = 123,          /**< �洢��Դ���ͷţ���Ӧ�ṹ : FREE_STORE_RES_SUCCEED_S */
    PROC_TYPE_MEDIA_STATUS_NOTIFY    = 124,          /**< ý��״̬֪ͨ��Ϣ����Ӧ�ṹ : MEDIA_STATUS_NOTIFY_S */
    /* Begin added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */
    PROC_TYPE_ALARM_LINKAGE_VOCTALK = 125,          /**< �澯�����������Խ�֪ͨ����Ӧ�ṹ : ALARM_LINKAGE_VOCTALK_TO_UI_S */
    /* End added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */

    /* ECR��Ӧ�Ļص���������400��ʼ */
    PROC_TYPE_MMI_VOUT_INFO_CHANGE             = 400,      /**<�˻���������˿ڻ�����Ϣ�ı�.��Ӧ�ṹ��MMI_VOUT_INFO_FOR_ECR_S */
    PROC_TYPE_MMI_VOUT_WINLIST_CHANGE          = 401,      /**<�˻�����Ԥ�����������������Ϣ�ı�, ��Ӧ�ṹ��: MMI_VOUT_WINLIST_INFO_FOR_ECR_S */
    PROC_TYPE_VIRTUAL_CHANNEL_STATUS_CHANGE    = 402,      /**<����ͨ��������Ϣ�ı䣬��Ӧ�ṹ��VIRTUAL_CHANNEL_BIND_STATUS_S */

    /* Begin: Added by chenyongfa, 2013-05-03 of IVSD00832 */
    PROC_TYPE_VIRTUAL_CHANNEL_INFO_CHANGE       = 403,               /**<����ͨ���ֱ���/֡�ʸı䣬��Ӧ�ṹ��VIRTUAL_CHANNEL_BIND_STATUS_S */
    /* End: Added by chenyongfa, 2013-05-03 of IVSD00832 */
    /* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
    PROC_TYPE_LOCK_SPACE_NOTIFY    = 404,          /**< ��������ռ�֪ͨ��Ϣ����Ӧ�ṹ : AS_SM_LOCK_SPACE_NOTIFY_S */
    PROC_TYPE_LOCK_FAILURE_NOTIFY    = 405,          /**< ������������·�֪ͨ��Ϣ����Ӧ�ṹ : AS_SM_LOCK_FAILURE_NOTIFY_S */
    /* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
	/* Begin: Added by y01359, 2015-04-27 for A8 */
    PROC_TYPE_TV_WALL_POLL_INFO_NOTIFY       = 406,               /**<����ǽ������ѯ��Ϣ����Ӧ�ṹ��CS_TVWALL_POLL_INFO_NOTIFY_S */
    /* End: Added by y01359, 2015-04-27 for A8 */
	 /* Add by liujian/02319, 2016-10-13 for MPPD41303 */
    PROC_TYPE_USER_LOGIN_REAVE_NOTIFY   = 407,      /**< �û���½��ռ֪ͨ��Ϣ����Ӧ�ṹ��: LOGIN_REAVE_NOTIFY_S*/

    PROC_TYPE_TRAFFIC_EVENT = 408,                  /**< ��ͨ�¼�����Ӧ�ṹ : TMS_TRAFFIC_EVENT_S */

    PROC_TYPE_MAX,                                   /**< �ص�����������Ϣ�������ֵ */
    PROC_TYPE_INVALID                = 0xFFFFFFFF    /**< ��Чֵ */
}CALL_BACK_PROC_TYPE_E;

/** ��̨����UI���¼�ö�����Ͷ��� */
typedef enum tagPtzNotifyUIEventType
{
    PTZ_NOTIFY_TYPE_RELEASE_TIME_OUT                = 0,    /** ��̨���ӿ��г�ʱ ���ӱ��ͷ� */
    PTZ_NOTIFY_TYPE_REAVED                          = 1,    /** ��̨��ǿռ�������ͷ� */
    PTZ_NOTIFY_TYPE_TROUBLE                         = 2,    /** ��̨���ϣ������ͷ� */
    PTZ_NOTIFY_TYPE_USER_HAS_NO_AUTHORITY           = 3,    /** �û�����̨����Ȩ�� */
    PTZ_NOTIFY_TYPE_PTZ_USER_HAS_LOWER_AUTHORITY    = 4,    /** �û�Ȩ�޵� */
    PTZ_NOTIFY_TYPE_PTZ_HAS_LOCKED_BY_OTHER         = 5,    /** ��̨�������û����� */
    /* Added by wangyaqi,KF1963,2010-12-07 of VVD50927 */
    PTZ_NOTIFY_TYPE_PTZ_CCB_FULL                    = 6,    /** ���ƿ����� */
    PTZ_NOTIFY_TYPE_MAX,
    PTZ_NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}PTZ_NOTIFY_UI_EVENT_TYPE;

/** ����ʾ��Ԫ�����¼�ö�����Ͷ��� */
typedef enum tagSalvoUnitNotifyUIEventType
{
    SALVO_UNIT_NOTIFY_TYPE_START_FAIL       = 0,    /** ����ʾ��Ԫ����ʵ��ʧ�� */
    SALVO_UNIT_NOTIFY_TYPE_BE_REAVED        = 1,    /** ����ʾ��Ԫ��ʵ������ռ */
    SALVO_UNIT_NOTIFY_TYPE_SAME_EXIST       = 2,    /** ��ͬ������ʾ��Ԫ��ʵ���Ѵ��� */
    SALVO_UNIT_NOTIFY_TYPE_SAME_CREATING    = 3,    /** ��ͬ������ʾ��Ԫ��ʵ�����ڽ��� */
    SALVO_UNIT_NOTIFY_TYPE_TROUBLE          = 4,    /** ������������ʾ��Ԫʵ���ͷ� */
    SALVO_UNIT_NOTIFY_TYPE_RESUME_SUCC      = 5,    /** ����ʾ��Ԫ�ָ�ʵ�� */
    SALVO_UNIT_NOTIFY_TYPE_RES_MODIFY       = 6,    /** ����ʾ�޸�����Ԫʵ���ͷ� */
    SALVO_UNIT_NOTIFY_TYPE_USER_STOP        = 7,    /** �û�ֹͣ����ʾ��Ԫ */

    SALVO_UNIT_NOTIFY_TYPE_MAX,
    SALVO_UNIT_NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}SALVO_UNIT_NOTIFY_UI_EVENT_TYPE_E;

/** ����ҵ�������¼�ö�����Ͷ��� */
typedef enum tagSalvoNotifyEventType
{
    NOTIFY_TYPE_SALVO_BE_STOPPED                = 0,    /** ����ʾҵ��ֹͣ */
    NOTIFY_TYPE_SALVO_BE_REAVED                 = 1,    /** ����ʾҵ����ռ */
    NOTIFY_TYPE_GROUPSALVO_BE_STOPPED           = 2,    /** ����Ѳҵ��ֹͣ */
    NOTIFY_TYPE_GROUPSALVO_BE_REAVED            = 3,    /** ����Ѳҵ����ռ */
    NOTIFY_TYPE_GROUPSALVO_STOP_SALVO_PER_TIME  = 4,    /** ����Ѳ�л�ֹͣ����ʾ */
    NOTIFY_TYPE_SALVO_ALL_MON_UNACTIVE          = 5,    /** ����ʾҵ��������ʵ�����ָ� */

    NOTIFY_TYPE_MAX,
    NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}SALVO_NOTIFY_EVENT_TYPE_E;

/*@brief ������Ϣ����ص��������ͣ�ulProcTypeΪ�������ͣ�ö��ֵΪCALL_BACK_PROC_TYPE_E */
typedef VOID (STDCALL *CALL_BACK_PROC_PF)(IN ULONG_32 ulProcType, IN VOID *pParam);

/** �澯���� */
typedef enum tagAlarmType
{
    /** MIB�澯 1~200 */
    AlARM_TYPE_HIGH_TEMPERATURE         = 1,    /**< ���¸澯 */
    AlARM_TYPE_LOW_TEMPERATURE          = 2,    /**< ���¸澯 */
    AlARM_TYPE_TEMPERATURE_RESUME       = 3,    /**< �¶ȸ澯�ָ� */
    AlARM_TYPE_FAN_FAULT                = 4,    /**< ���ȹ��ϸ澯 */
    AlARM_TYPE_FAN_FAULT_RESUME         = 5,    /**< ���ȹ��ϸ澯�ָ� */
    ALARM_TYPE_FLASH_OPERATE            = 6,    /**< Flash�����澯 */
    ALARM_TYPE_CPU_EXCEED               = 7,    /**< CPU�����ʹ��߸澯 */
    ALARM_TYPE_MEMOY_EXCEED             = 8,    /**< �ڴ������ʹ��߸澯 */
    ALARM_TYPE_REBOOT                   = 9,    /**< �豸���� */
    ALARM_TYPE_DEVICE_CONFIG_CHANGE     = 10,   /**< �豸���ñ�� */
    AlARM_TYPE_DISK_ERR                 = 11,   /**< ���̹��� */
    AlARM_TYPE_DISK_ERR_RECOVER         = 12,   /**< ���̹��ϻָ� */
    AlARM_TYPE_DISK_POWER_ON            = 13,   /**< �������� */
    AlARM_TYPE_DISK_POWER_OFF           = 14,   /**< �������� */
    AlARM_TYPE_RAID_EXCEPTION           = 15,   /**< �����쳣�澯 */
    AlARM_TYPE_RAID_REBUILD_START       = 16,   /**< �����ؽ�״̬ */
    AlARM_TYPE_RAID_REBUILD_FINISH      = 17,   /**< �˳��ؽ� */
    AlARM_TYPE_STP_EXEC_EXCEPTION       = 18,   /**< δ���ƻ�¼��澯 */
    AlARM_TYPE_STP_EXEC_RECOVER         = 19,   /**< δ���ƻ�¼��ָ��澯 */
    AlARM_TYPE_IPSAN_NO_ACCESS          = 20,   /**< �޷�����IPSAN�洢�豸�澯 */
    AlARM_TYPE_IPSAN_NO_ACCESS_RECOVER  = 21,   /**< �޷�����IPSAN�洢�豸�ָ��澯 */
    AlARM_TYPE_STORED_DATA_READ_ERR     = 22,   /**< ��ȡ�洢����ʧ�� */
    AlARM_TYPE_STORED_DATA_SEEK_ERR     = 23,   /**< ��λ�洢�豸ʧ�� */
    AlARM_TYPE_VOD_OVER_THRESHOLD       = 24,   /**< �㲥·��������ֵ */
    AlARM_TYPE_VOD_UNDER_THRESHOLD      = 25,   /**< �㲥�������ָ� */
    ALARM_TYPE_TEMPERATURE              = 26,   /**< �¶ȸ澯 */
    AlARM_TYPE_CAM_BAK_OWN_UNDER_THR    = 27,   /**< �������������Դ����ʹ�ôﵽ��ֵ�ָ� */
    AlARM_TYPE_CAM_BAK_SHARD_OVER_THR   = 28,   /**< �������������Դ����ʹ�ôﵽ��ֵ */
    AlARM_TYPE_CAM_BAK_SHARD_UNDER_THR  = 29,   /**< �������������Դ����ʹ�ôﵽ��ֵ�ָ� */
    AlARM_TYPE_CAM_BAK_OWN_CAP_SCANT    = 30,   /**< �������������Դ������ֹͣ����ʱ����Դʣ���������� */
    AlARM_TYPE_CAM_BAK_OWN_CAP_ENOUGH   = 31,   /**< �������������Դ������ֹͣ����ʱ����Դʣ����������ָ� */
    AlARM_TYPE_BAK_RES_CAP_SCANT        = 32,   /**< ȫ�ֱ���������ֹͣ����ʱ��ȫ����Դʣ���������� */
    AlARM_TYPE_BAK_RES_CAP_ENOUGH       = 33,   /**< ȫ�ֱ���������ֹͣ����ʱ��ȫ����Դʣ����������ָ� */
    AlARM_TYPE_BAK_RES_ABNORMAL         = 34,   /**< ������Դ�쳣 */
    AlARM_TYPE_BAK_RES_NORMAL           = 35,   /**< ������Դ�쳣�ָ� */
    AlARM_TYPE_BAK_FAILED               = 36,   /**< ��������ִ��ʧ�� */
    AlARM_TYPE_CAM_BAK_OWN_OVER_THR     = 37,   /**< �������������Դ����ʹ�ôﵽ��ֵ */
    /* Begin: Added by mozhanfei(kf0149), 2013-9-9 for �����쳣�ָ��澯 */
    AlARM_TYPE_RAID_EXCEPTION_RECOVER           = 38,   /**< �����쳣�ָ��澯 */
    /* End: Added by mozhanfei(kf0149), 2013-7-18 for �����쳣�ָ��澯 */

    AlARM_TYPE_PREVENT_REMOVAL          = 71,   /**< ����澯 */
    AlARM_TYPE_PREVENT_REMOVAL_RESUME   = 72,   /**< ����澯�ָ� */

    /* Begin: Added by wangxiaozhi(w01677), 2015-1-29 for ����VX1600�澯 */
    AlARM_TYPE_DISK_REMOVA_NOT_IN_RAID  = 73,   /**< ����RAID�еĴ��̱��γ� */
    AlARM_TYPE_DISK_REMOVA_IN_RAID      = 74,   /**< ��Raid�еĴ��̱��γ� */
    AlARM_TYPE_DISK_ERR_REMOVA_IN_RAID  = 75,   /**< ��Raid�еĴ��̹��� */
    /* End: Added by wangxiaozhi(w01677), 2015-1-29 for ����VX1600�澯 */

	/*Begin added by liangchao, 2015-12-09 for ��ε�¼ʧ�ܸ澯*/
	AlARM_TYPE_MULTI_LOGIN_FAIL         =76,
	/*End added by liangchao, 2015-12-09 for ��ε�¼ʧ�ܸ澯*/

    /* Begin: Added by limengni 03868, 2017-10-11 for MPPD46920 */
    AlARM_TYPE_STOR_THRES  = 80,  /**<�ֶ������ļ��洢�ռ�ﵽ��ֵ�澯 */
    AlARM_TYPE_STOR_THRES_RESUME  = 81,  /**<�ֶ������ļ��洢�ռ�ﵽ��ֵ�澯�ָ� */
    /* End: Added by limengni 03868, 2017-10-11 for MPPD46920 */

    /* Begin add by zhengyibing(01306), 2015/01/13 for MPPD08280 */
    AlARM_TYPE_SERVER_ACTION_REPORT      = 193,   /**< ƽ̨�������鱨�� */
    /* End add by zhengyibing(01306), 2015/01/13 for MPPD08280 */

    /* Begin added by baoyihui02795, 2011-04-28 of ������Ŀ */
    ALARM_TYPE_FLASHLIGHT_FAULT         = 194,   /**< ����ƹ��� */
    ALARM_TYPE_FLASHLIGHT_FAULT_RESUME  = 195,   /**< ����ƹ��ϻָ� */
    ALARM_TYPE_STOR_RES_ABNORMAL        = 196,   /**< �洢��Դ�쳣 */
    ALARM_TYPE_STOR_RES_NORMAL          = 197,   /**< �洢��Դ�쳣�ָ� */
    ALARM_TYPE_COIL_DISABLED            = 198,   /**< ��ȦʧЧ */
    ALARM_TYPE_COIL_ENABLED             = 199,   /**< ��ȦʧЧ�ָ� */
    /* End added by baoyihui02795, 2011-04-28 of ������Ŀ */

    /** SIP�澯 201~ */
    AlARM_TYPE_VIDEO_LOST               = 201,  /**< ��Ƶ��ʧ�澯 */
    AlARM_TYPE_VIDEO_LOST_RESUME        = 202,  /**< ��Ƶ��ʧ�澯�ָ� */
    AlARM_TYPE_MOVE_DETECT              = 203,  /**< �˶����澯 */
    AlARM_TYPE_MOVE_DETECT_RESUME       = 204,  /**< �˶����澯�ָ� */
    AlARM_TYPE_MASK_DETECT              = 205,  /**< �ڵ����澯 */
    AlARM_TYPE_MASK_DETECT_RESUME       = 206,  /**< �ڵ����澯�ָ� */
    AlARM_TYPE_INPUT_SWITCH             = 207,  /**< ���뿪�����澯 */
    AlARM_TYPE_INPUT_SWITCH_RESUME      = 208,  /**< ���뿪�����澯�ָ� */
    AlARM_TYPE_SHORT_CIRCUIT            = 209,  /**< ��������·��·�澯 */
    AlARM_TYPE_BREAKER_CIRCUIT          = 210,  /**< ��������·��·�澯 */
    AlARM_TYPE_SHORT_CIRCUIT_RESUME     = 211,  /**< ��������·��·�澯�ָ� */
    AlARM_TYPE_STOR_FULL_PRE            = 212,  /**< �洢�������澯 */
    AlARM_TYPE_STOR_FULL                = 213,  /**< ���洢�澯 */
    AlARM_TYPE_STOR_FAILED              = 214,  /**< �洢��дʧ�ܸ澯 */
    AlARM_TYPE_STOR_FAILED_RESUME       = 215,  /**< �洢��дʧ�ܸ澯�ָ� */
    AlARM_TYPE_DEVICE_ONLINE            = 216,  /**< �豸���߸澯 */
    AlARM_TYPE_DEVICE_OFFLINE           = 217,  /**< �豸���߸澯 */
    AlARM_TYPE_BREAKER_CIRCUIT_RESUME   = 219,  /**< ��������·��·�澯�ָ� */

    /* Begin Added by yangzichao(w1856), for֧��ƽ̨�����߸澯*/
    ALARM_TYPE_OUTER_DOMAIN_ONLINE		= 220,  /**< �������� */
    ALARM_TYPE_OUTER_DOMAIN_OFFLINE		= 221,  /**< �������� */
    /*End Added by yangzichao(w1856), for֧��ƽ̨�����߸澯*/

    AlARM_TYPE_STREAM_STOR_CAM_WARN     = 222,  /**< ������洢ֹͣ�澯 */

    AlARM_TYPE_EXT_STOR_FULL_PRE        = 223,  /**< Զ�˴洢�������澯 */
    AlARM_TYPE_EXT_STOR_FULL            = 224,  /**< Զ�˴洢���澯 */
    AlARM_TYPE_EXT_STOR_FAILED          = 225,  /**< Զ�˴洢��дʧ�ܸ澯 */
    AlARM_TYPE_EXT_STOR_FAILED_RESUME   = 226,  /**< Զ�˴洢��дʧ�ܸ澯�ָ� */

    AlARM_TYPE_STOR_NO_ENOUGH_SPACE     = 229,  /**< ��������ڴ��̴洢�ռ䲻��澯 */
    AlARM_TYPE_STOR_DEL_FILE_FAILED     = 230,  /**< ɾ�����ļ�ʧ�ܸ澯 */

    AlARM_TYPE_BEHAVIOR                 = 231,  /**< ��Ϊ�澯 */
    AlARM_TYPE_BEHAVIOR_RESUME          = 232,  /**< ��Ϊ�澯�ָ� */

    ALARM_TYPE_STREAM_BREAK             = 233,  /**< ����������澯 */

    /* Begin: Added by luhaitao/01337, 2015-01-13 for ��֡�澯�ϱ� */
    ALARM_TYPE_STOR_LOST_FRAME          = 234,  /**< �洢��֡�澯 */
    /* End: Added by luhaitao/01337, 2015-01-13 for ��֡�澯�ϱ� */

    AlARM_TYPE_SOUND_ABNORMAL           = 241,  /**< �쳣�����澯 */
    AlARM_TYPE_SOUND_ABNORMAL_RESUME    = 242,  /**< �쳣�����澯�ָ� */

    /* Begin: Added by zhouquanwei/z01364, 2014-12-04 for ʵ������ */
    AlARM_TYPE_MON_START                = 251,  /**< ����ʵ���澯 */
    /* End: Added by zhouquanwei/z01364, 2014-12-04 for ʵ������ */

    ALARM_TYPE_CROSS_LINE               = 301,  /**< �������ܰ��� */
    ALARM_TYPE_INTROSION_ZONE           = 302,  /**< �������� */
    ALARM_TYPE_ACCESS_ZONE              = 303,  /**< �������� */
    ALARM_TYPE_LEAVE_ZONE               = 304,  /**< �뿪���� */
    ALARM_TYPE_HOVER_ZONE               = 305,  /**< �����ǻ� */
    ALARM_TYPE_OVER_FENCE               = 306,  /**< ��ԽΧ�� */
    ALARM_TYPE_CARE_ARTICLE             = 307,  /**< ��Ʒ���� */
    ALARM_TYPE_REMAIN_ARTICLE           = 308,  /**< ��Ʒ���� */
    /* Begin Added by zhangchi zW4385 2017-09-08 for MPPD24025 */
    ALARM_TYPE_GATHER                   = 309,  /**< ��Ա�ۼ� */
    ALARM_TYPE_FAST_MOVE                = 310,  /**< �����ƶ� */
    ALARM_TYPE_CAR_STOP                 = 311,  /**< ͣ�� */
    ALARM_TYPE_OUT_FOCUS                = 312,  /**< �齹 */
    ALARM_TYPE_OUT_FOCUS_RESUME         = 313,  /**< �齹�澯�ָ� */
    ALARM_TYPE_SCENCE_CHANGE            = 314,  /**< ������� */
    ALARM_TYPE_FACE_DETECT              = 315,  /**< ������� */
    ALARM_TYPE_CAR_DETECT               = 316,  /**< ��·��� */
    ALARM_TYPE_PEOPLE_COUNT             = 317,  /**< ����ͳ�� */
    ALARM_TYPE_GATHER_RESUME            = 318,  /**< ��Ա�ۼ��ָ� */
    ALARM_TYPE_HEATMAP                  = 319,  /**< ����ͼ */
    /*End Added by zhangchi zW4385 2017-09-08 for MPPD24025 */
    ALARM_TYPE_ILLEGALLY_PARKED         = 320,  /**< Υ��ͣ�� */
    ALARM_TYPE_PRESS_LINE_DRIVING       = 321,  /**< ѹ�� */
    ALARM_TYPE_REVERSE_DRIVING          = 322,  /**< ���� */
    ALARM_TYPE_ILLEGAL_DETECT_START     = 323,  /**< ���ץ�Ŀ�ʼ */
    ALARM_TYPE_ILLEGAL_DETECT_OVER      = 324,  /**< ���ץ�Ľ��� */
    ALARM_TYPE_ILLEGAL_DETECT_AWAY      = 325,  /**< ���Ŀ���뿪 */
    ALARM_TYPE_ILLEGAL_DETECT_CLEAN     = 326,  /**< ��ʷ���Ŀ����� */
    AlARM_TYPE_IPSAN_WRITE_ERR          = 327,  /*�洢д��ͼƬʧ��*/
    AlARM_TYPE_FORWARD_SEND_ERR         = 328,  /*����ʧ�ܸ澯*/
    AlARM_CDS_TYPE_STOR_FULL            = 329,  /**< ���洢�澯 */

    //traffic flow


    /* Begin: Added by zhongke */
    ALARM_TYPE_TRAFFIC_FLOW     = 336,  /**< ������ */
    /* Begin: Added by luhaitao/01337, 2015-01-13 for ��֡�澯�ϱ� */

    /* �ֹ��澯 401~ */
    AlARM_TYPE_IMPERATIVE_EVENT         = 401,  /**< �����澯 */

    ALARM_TYPE_BAKEUP_LINK_SWITCH       = 402,  /**< ������·�л��澯 */

    /* Begin: Added by luhaitao/01337, 2016-05-21 for ǰ�˹����澯֧�� */
    ALARM_TYPE_VEHICLE_DETECTOR_FAILED = 701,                                                                       /**< ���̵Ƽ�������߸澯 */
    ALARM_TYPE_VEHICLE_DETECTOR_FAILED_RESUME  = 702,                                                 /**< ���̵Ƽ�������߸澯�ָ� */
    ALARM_TYPE_VEHICLE_RADAR_FAILED = 703,                                                                                /**< �״���� */
    ALARM_TYPE_VEHICLE_RADAR_FAILED_RESUME = 704,                                                           /**< �״���ϻָ� */
    ALARM_TYPE_VEHICLE_LASER_DETECTOR_FAILED = 705,                                                      /**< ������������ */
    ALARM_TYPE_VEHICLE_LASER_DETECTOR_FAILED_RESUME = 706,                                 /**< �����������ϻָ� */
    ALARM_TYPE_VEHICLE_INFRARED_DETECTOR_FAILED = 707,                                              /**< ������������ */
    ALARM_TYPE_VEHICLE_INFRARED_DETECTOR_FAILED_RESUME = 708,                         /**< �����������ϻָ� */
    ALARM_TYPE_VEHICLE_GROUND_SENSOR_DETECTOR_FAILED = 709,                             /**< �ظм�������� */
    ALARM_TYPE_VEHICLE_GROUND_SENSOR_DETECTOR_FAILED_RESUME = 710,        /**< �ظм�������ϻָ� */
    ALARM_TYPE_VEHICLE_FLASHLIGHT_FAILED = 711,                                                                     /**< ����ƹ��� */
    ALARM_TYPE_VEHICLE_FLASHLIGHT_FAILED_RESUME = 712,                                                /**< ����ƹ��ϻָ� */
    /* End: Added by luhaitao/01337, 2016-05-21 for ǰ�˹����澯֧�� */

    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
    ALARM_TYPE_WATER_LEVEL_GAUGE_FAILED                                  = 716, /**< ˮλ�ƹ��ϸ澯 */
    ALARM_TYPE_WATER_LEVEL_GAUGE_FAILED_RESUME                           = 717, /**< ˮλ�ƹ��ϸ澯�ָ� */
    ALARM_TYPE_WATERLOGGING_DETECTOR_FAILED                              = 718, /**< ˮ����������ϸ澯 */
    ALARM_TYPE_WATERLOGGING_DETECTOR_FAILED_RESUME                       = 719, /**< ˮ����������ϸ澯�ָ� */
    ALARM_TYPE_O2_DETECTOR_FAILED                                        = 720, /**< ����Ũ�ȼ���ǹ��ϸ澯 */
    ALARM_TYPE_O2_DETECTOR_FAILED_RESUME                                 = 721, /**< ����Ũ�ȼ���ǹ��ϸ澯�ָ� */
    ALARM_TYPE_H2S_DETECTOR_FAILED                                       = 722, /**< ����Ũ�ȼ���ǹ��ϸ澯 */
    ALARM_TYPE_H2S_DETECTOR_FAILED_RESUME                                = 723, /**< ����Ũ�ȼ���ǹ��ϸ澯�ָ� */
    ALARM_TYPE_CH4_DETECTOR_FAILED                                       = 724, /**< ����Ũ�ȼ���ǹ��ϸ澯 */
    ALARM_TYPE_CH4_DETECTOR_FAILED_RESUME                                = 725, /**< ����Ũ�ȼ���ǹ��ϸ澯�ָ� */
    ALARM_TYPE_CO_DETECTOR_FAILED                                        = 726, /**< һ����̼Ũ�ȼ���ǹ��ϸ澯 */
    ALARM_TYPE_CO_DETECTOR_FAILED_RESUME                                 = 727, /**< һ����̼Ũ�ȼ���ǹ��ϸ澯�ָ� */
    ALARM_TYPE_LED_FAILED                                                = 728, /**< LED�ƹ��ϸ澯 */
    ALARM_TYPE_LED_FAILED_RESUME                                         = 729, /**< LED�ƹ��ϸ澯�ָ� */
    ALARM_TYPE_PUMP_FAILED                                               = 730, /**< ˮ�ù��ϸ澯 */
    ALARM_TYPE_PUMP_FAILED_RESUME                                        = 731, /**< ˮ�ù��ϸ澯�ָ� */
    ALARM_TYPE_BLOWER_FAILED                                             = 732, /**< ������ϸ澯 */
    ALARM_TYPE_BLOWER_FAILED_RESUME                                      = 733, /**< ������ϸ澯�ָ� */
    ALARM_TYPE_AIR_VALVE_FAILED                                          = 734, /**< �緧���ϸ澯 */
    ALARM_TYPE_AIR_VALVE_FAILED_RESUME                                   = 735, /**< �緧���ϸ澯�ָ� */
    ALARM_TYPE_ELECTRONIC_MANHOLE_COVER_FAILED                           = 736, /**< ���Ӿ��ǹ��ϸ澯 */
    ALARM_TYPE_ELECTRONIC_MANHOLE_COVER_FAILED_RESUME                    = 737, /**< ���Ӿ��ǹ��ϸ澯�ָ� */
    ALARM_TYPE_ANNUNCIATOR_FAILED                                        = 738, /**< ���ⱨ�������ϸ澯 */
    ALARM_TYPE_ANNUNCIATOR_FAILED_RESUME                                 = 739, /**< ���ⱨ�������ϸ澯�ָ� */
    ALARM_TYPE_MEGAPHONE_FAILED                                          = 740, /**< ���������ϸ澯 */
    ALARM_TYPE_MEGAPHONE_FAILED_RESUME                                   = 741, /**< ���������ϸ澯�ָ� */
    ALARM_TYPE_INDUSTRIAL_TELEPHONE_FAILED                               = 742, /**< ��ҵ�绰�����ϸ澯 */
    ALARM_TYPE_INDUSTRIAL_TELEPHONE_FAILED_RESUME                        = 743, /**< ��ҵ�绰�����ϸ澯�ָ� */
    ALARM_TYPE_AUTOMATIC_FIRE_EXTINGUISHER_FAILED                        = 744, /**< �Զ���������ϸ澯 */
    ALARM_TYPE_AUTOMATIC_FIRE_EXTINGUISHER_FAILED_RESUME                 = 745, /**< �Զ���������ϸ澯�ָ� */
    ALARM_TYPE_WIRELESS_AP_FAILED                                        = 746, /**< ����AP���ϸ澯 */
    ALARM_TYPE_WIRELESS_AP_FAILED_RESUME                                 = 747, /**< ����AP���ϸ澯�ָ� */
    ALARM_TYPE_ACCESS_CONTROLLER_FAILED                                  = 748, /**< �Ž����������ϸ澯 */
    ALARM_TYPE_ACCESS_CONTROLLER_FAILED_RESUME                           = 749, /**< �Ž����������ϸ澯�ָ� */
    ALARM_TYPE_UPS_FAILED                                                = 750, /**< UPS���ϸ澯 */
    ALARM_TYPE_UPS_FAILED_RESUME                                         = 751, /**< UPS���ϸ澯�ָ� */
    ALARM_TYPE_STORAGE_BATTERY_FAILED                                    = 752, /**< ���ع��ϸ澯 */
    ALARM_TYPE_STORAGE_BATTERY_FAILED_RESUME                             = 753, /**< ���ع��ϸ澯�ָ� */
    ALARM_TYPE_INFRARED_DETECTOR_FAILED                                  = 754, /**< �������̽�������ϸ澯 */
    ALARM_TYPE_INFRARED_DETECTOR_FAILED_RESUME                           = 755, /**< �������̽�������ϸ澯�ָ� */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_FAILED        = 756, /**< ���͹��˲���̽�������ϸ澯 */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_FAILED_RESUME = 757, /**< ���͹��˲���̽�������ϸ澯�ָ� */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

    AlARM_TYPE_NM_PROTECT_EVENT         = 800,  /**< ����N+M������澯, ��Ҫ���ڿ���N+M�����澯����,
                                                     ���ĺ��൱�ڶ����˴洢ʧ�ܡ��洢ֹͣ�����澯 */
    AlARM_TYPE_EVENT_PICTURE           = 801,   /**< ͼƬ�¼��ϱ� */

    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
    ALARM_TYPE_PIPLINE_LEVEL_HIGH                               = 900,  /**< ��ˮ��ˮλ���߸澯 */
    ALARM_TYPE_PIPLINE_LEVEL_HIGH_RESUME                        = 901,  /**< ��ˮ��ˮλ���߸澯�ָ� */
    ALARM_TYPE_WATERLOGGING_DETECTOR_DETECTED                   = 902,  /**< ˮ��������澯 */
    ALARM_TYPE_WATERLOGGING_DETECTOR_DETECTED_RESUME            = 903,  /**< ˮ��������澯�ָ� */
    ALARM_TYPE_O2_LEVEL_LOW                                     = 904,  /**< ����Ũ�ȹ��͸澯 */
    ALARM_TYPE_O2_LEVEL_HIGH                                    = 905,  /**< ����Ũ�ȹ��߸澯 */
    ALARM_TYPE_O2_LEVEL_RESUME                                  = 906,  /**< ����Ũ�ȸ澯�ָ� */
    ALARM_TYPE_H2S_LEVEL_HIGH                                   = 907,  /**< ����Ũ�ȹ��߸澯 */
    ALARM_TYPE_H2S_LEVEL_HIGH_RESUME                            = 908,  /**< ����Ũ�ȹ��߸澯�ָ� */
    ALARM_TYPE_CH4_LEVEL_HIGH                                   = 909,  /**< ����Ũ�ȹ��߸澯 */
    ALARM_TYPE_CH4_LEVEL_HIGH_RESUME                            = 910,  /**< ����Ũ�ȹ��߸澯�ָ� */
    ALARM_TYPE_CO_LEVEL_HIGH                                    = 911,  /**< һ����̼Ũ�ȹ��߸澯 */
    ALARM_TYPE_CO_LEVEL_HIGH_RESUME                             = 912,  /**< һ����̼Ũ�ȹ��߸澯�ָ� */
    ALARM_TYPE_UPS_LOW                                          = 929,  /**< UPS�������͸澯 */
    ALARM_TYPE_UPS_LOW_RESUME                                   = 930,  /**< UPS�������͸澯�ָ� */
    ALARM_TYPE_STORAGE_BATTERY_LOW                              = 931,  /**< ���ص������͸澯 */
    ALARM_TYPE_STORAGE_BATTERY_LOW_RESUME                       = 932,  /**< ���ص������͸澯�ָ� */
    ALARM_TYPE_INFRARED_DETECTOR_DETECTED                       = 933,  /**< �������̽�����澯 */
    ALARM_TYPE_INFRARED_DETECTOR_DETECTED_RESUME                = 934,  /**< �������̽�����澯�ָ� */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_HIGH = 935,  /**< ���͹��˲���̽�������¸澯 */
    ALARM_TYPE_LINETYPE_OPTICAL_FIBER_TEMPERATURE_DETECTOR_HIGH_RESUME = 936,  /**< ���͹��˲���̽�������¸澯�ָ� */
    /**   ALARM_TYPE_IOT_LABEL = 1000~1099   RFID��ǩ��澯 */
    ALARM_TYPE_IOT_LABEL_IN                       = 1001,   /**< ��ǩ�����ͷ(DAE/����IPC) */
    ALARM_TYPE_LABEL_OUT                          = 1002,   /**< ��ǩ�뿪��ͷ(DAE/����IPC) */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

    /* Begin added by zhukaikai/W4801, 2017-12-28 for �ر������� MPPD54420 */
    ALARM_TYPE_LANDMARK_IN                        = 1003,   /**< �ر�����ǩ���� */
    ALARM_TYPE_LANDMARK_OUT                       = 1004,   /**< �ر�����ǩ�뿪 */
    /* End added by zhukaikai/W4801, 2017-12-28 for �ر������� MPPD54420 */

    /* Begin added by baoyihui02795, 2011-04-28 of ������Ŀ */
    /** ����ҵ��澯 2001~ */
    ALARM_TYPE_DISPOSITION_STOLEN_VEHICLE         = 2001,   /**< ������ */
    ALARM_TYPE_DISPOSITION_ROBBED_VEHICLE         = 2002,   /**< ������ */
    ALARM_TYPE_DISPOSITION_SUSPICION_VEHICLE      = 2003,   /**< ���ɳ� */
    ALARM_TYPE_DISPOSITION_TRAFFIC_VIOLATION      = 2004,   /**< ��ͨΥ���� */
    ALARM_TYPE_DISPOSITION_EMERGENCY_SURVEILLANCE = 2005,   /**< ������س� */
    ALARM_TYPE_VEHICLE_BLACKLIST                  = 2006,   /**< ������ */
    ALARM_TYPE_OTHER_VEHICLE_ALARM                = 2007,   /**< ��������Υ����Ϊ */
    ALARM_TYPE_P2P_SPEED_DETECTION                = 2008,   /**< �������Υ�� */
    ALARM_TYPE_NOT_WHITELIST                      = 2009,   /**< �ǰ��������� */
    /* End added by baoyihui02795, 2011-04-28 of ������Ŀ */
    ALARM_TYPE_P2P_TIME_DETECTION                 = 2010,   /**< ���䳬ʱΥ�� *//*Added by c02845, 2015-11-05,of MPPD31387 */

    /* Begin added by zhuzhicong/02302 2016��6��30��11:32:37�������¹���澯���� 2011~ */
    /* �澯���͡�alarmmethod�� */
    AlARM_TYPE_TELEPHONE                          = 2011,   /**< �绰���� */
    AlARM_TYPE_DEVICE                             = 2012,   /**< �豸���� */
    AlARM_TYPE_NOTE                               = 2013,   /**< ���ű��� */
    AlARM_TYPE_GPS                                = 2014,   /**< GPS���� */
    AlARM_TYPE_VEDIO                              = 2015,   /**< ��Ƶ���� */
    AlARM_TYPE_DEVICE_FAULT                       = 2016,   /**< �豸���ϱ��� */
    AlARM_TYPE_OTHER                              = 2017,   /**< �������� */

    /* �澯���͡�alarmtype�� */
    AlARM_TYPE_ARTIFICIAL_VIDEO                   = 2018,   /**< �˹���Ƶ���� */
    AlARM_TYPE_TRAFFIC_ANALYSIS                   = 2019,   /**< ����ͳ�Ʊ��� */
    AlARM_TYPE_DENSITY_DETECTION                  = 2020,   /**< �ܶȼ�ⱨ�� */
    AlARM_TYPE_VIDEO_ERROR                        = 2021,   /**< ��Ƶ�쳣��ⱨ�� */
    AlARM_TYPE_MOVE_FAST                          = 2022,   /**< �����ƶ����� */
    AlARM_TYPE_MOVE_FACE                          = 2023,   /**< ������ⱨ�� */
    /* End added by zhuzhicong/02302 2016��6��30��11:32:37�������¹���澯���� */

    /* Begin added by zhangchi zW4385, 2017-08-28 of MPPD50528 NVR��֧�����ܸ��ٿ�ʼ�ͽ����澯 */
    AlARM_TYPE_SMART_TRACK_BEGIN                  = 2025,   /**< ���ܸ��ٿ�ʼ�澯*/
    AlARM_TYPE_SMART_TRACK_FINISH                 = 2026,   /**< ���ܸ��ٽ����澯*/
    /* End added by zhangchi zW4385, 2017-08-28 of MPPD50528 NVR��֧�����ܸ��ٿ�ʼ�ͽ����澯  */

    ALARM_TYPE_WEITING_ALERT_PRE                      = 3001,   /**ΥͣԤ��*//*Begin added by yaozhongmin 02844 date: Jul 03 2016 for ΥͣԤ��*/
    ALARM_TYPE_TRAFFIC_EVENT                          = 3002,   /** ��ͨ�¼� */

    /*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
    ALARM_TYPE_RFID_DISPOSITION_STOLEN_VEHICLE                  = 3011,   /**< RFID������ */
    ALARM_TYPE_RFID_DISPOSITION_ROBBED_VEHICLE                 = 3012,   /**< RFID������ */
    ALARM_TYPE_RFID_DISPOSITION_TRAFFIC_VIOLATION              = 3013,   /**< RFID���Υ�³�> */
    ALARM_TYPE_RFID_DISPOSITION_SUSPICION_VEHICLE            = 3014,   /**< RFID���ɳ� */
	ALARM_TYPE_RFID_DISPOSITION_BREAK_IN                   = 3018,   /**< RFID�������� */
    ALARM_TYPE_RFID_OTHER_VEHICLE_ALARM                               = 3019,   /**< RFID����Υ����Ϊ */

    ALARM_TYPE_MAC_DISPOSITION_SUSPICION_PERSON             = 3021,   /**< MAC������> */
    ALARM_TYPE_MAC_DISPOSITION_KILLED_PERSON                    = 3022,   /**< MAC������>*/
    ALARM_TYPE_MAC_DISPOSITION_IMPORTANT_PERSON           = 3023,   /**< MAC�ص���Ա>*/
    ALARM_TYPE_MAC_DISPOSITION_CASE_INVOLVED_PERSON    = 3024,   /**< MAC�永��Ա>*/
    ALARM_TYPE_MAC_DISPOSITION_OTHER_PERSON                     = 3029,   /**< MAC����Υ����Ϊ>*/
    /*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

	/* Begin added by s03924 for MPPD53784 2017/11/25 */
    ALARM_TYPE_TRAFFICFLOW_CONGESTION                   = 3040,              /**<��ͨ��ӵ�¸澯 */
    /* End added by s03924 for MPPD53784 2017/11/25 */

    AlARM_TYPE_MAX,                         /**< ���ֵ */

    AlARM_TYPE_ALL      = 0xFFFE,           /**< ���и澯�������� */
    AlARM_TYPE_INVALID  = 0xFFFF            /**< ��Чֵ */
}AlARM_TYPE_E;

/* Begin: Added by luchunfeng02289, 2015-12-08 for �澯���� */
/** �澯���ͷ��� */
typedef enum tagAlarmClass
{
    ALARM_CLASS_DEVICE     = 1,     /**< �豸��澯 */
	ALARM_CLASS_SERVICE    = 2,     /**< ҵ����澯 */
	ALARM_CLASS_STORAGE    = 3,     /**< �洢��澯 */

	ALARM_CLASS_MAX,
    ALARM_CLASS_INVALID = 0xFF
}ALARM_CLASS_E;
/* End: Added by luchunfeng02289, 2015-12-08 for �澯���� */

/**
* @enum tagDevStatusBit
* @brief �豸״̬λö��
* @attention
*/
typedef enum tagDevStatusBit
{
    DEV_STATUS_BIT_DEVICE_OFFLINE       = 0,    /**< �豸���� */
    DEV_STATUS_BIT_HIGH_TEMPERATURE     = 1,    /**< �豸���� */
    DEV_STATUS_BIT_LOW_TEMPERATURE      = 2,    /**< �豸���� */
    DEV_STATUS_BIT_FAN_FAULT            = 3,    /**< �豸���ȹ��� */
    DEV_STATUS_BIT_VIDEO_LOST           = 4,    /**< ��Ƶ��ʧ */
    DEV_STATUS_BIT_MOVE_DETECT          = 5,    /**< �˶���� */
    DEV_STATUS_BIT_MASK_DETECT          = 6,    /**< �ڵ���� */
    DEV_STATUS_BIT_STOR_FAILED          = 7,    /**< �洢��дʧ�� */
    DEV_STATUS_BIT_INPUT_SWITCH         = 8,    /**< ���뿪���� */
    DEV_STATUS_BIT_SHORT_CIRCUIT        = 9,    /**< ��������·��· */
    DEV_STATUS_BIT_BREAKER_CIRCUIT      = 10,   /**< ��������·��· */
    DEV_STATUS_BIT_BEHAVIOR_ALARM       = 11,   /**< ��Ϊ�澯 */
    DEV_STATUS_BIT_COIL_DISABLED        = 32,   /**< ��ȦʧЧ */

    DEV_STATUS_BIT_MAX_NUM              = 128   /**< ���ֵ */
}DEV_STATUS_BIT_E;

/**
* @enum tagManualStoreStatus
* @brief �洢״̬ö��
* @attention
*/
typedef enum tagManualStoreStatus
{
    MANUAL_STORE_STATUS_STOP  =  0,                   /**< �洢״̬Ϊֹͣ */
    MANUAL_STORE_STATUS_START   = 1,                  /**< �洢״̬Ϊ��ʼ */

    MANUAL_STORE_STATUS_MAX,                          /**< �洢״̬���ֵ */
    MANUAL_STORE_STATUS_INVALID = 0XFFFFFFFF
}MANUAL_STORE_STATUS_E;

#ifndef LANG_SETING_OF_E
#define LANG_SETING_OF_E
/**
* @enum LANG_SETTING
* @brief ��Ʒ������Ӣ������ö��ֵ(�������־����������)
* @attention
*/
typedef enum LANG_SETTING
{
    LANG_CN = 0,                        /* < �������� */
    LANG_EN = 1,                        /* < Ӣ�� */

    LANG_MAX,                           /* < ���ֵ */
    LANG_INVALID                        /* < �������� */
} MW_LANGUAGE_E;
#endif
/**
* @enum tagTerminalDevLang
* @brief �ն��豸(EC/DC)����������ö��ֵ
* @attention
*/
typedef enum tagTerminalDevLang
{
    TERMINAL_DEV_LANG_CN = 1,                /* < ��������(�ն�����) */
    TERMINAL_DEV_LANG_EN = 2,                /* < Ӣ��(�ն�����) */

    TERMINAL_DEV_LANG_MAX,                   /* < ���ֵ */
    TERMINAL_DEV_LANG_INVALID                /* < �������� */
} TD_LANGUAGE_E;

/** �������� */
typedef enum tagActionType
{
    ACTION_TYPE_PRESET          = 0,    /**< Ԥ��λ */
    ACTION_TYPE_BOOLEAN_OUTPUT  = 1,    /**< ��������� */
    ACTION_TYPE_STORE           = 2,    /**< �洢 */
    ACTION_TYPE_BUZZER          = 4,    /**< ������ */
    ACTION_TYPE_CENTER_STORE    = 5,    /**< ������洢 */
    ACTION_TYPE_GIS             = 10,   /**< GIS */
    ACTION_TYPE_MON_LIVE        = 11,   /**< ʵ���������� */
    ACTION_TYPE_PANE_LIVE       = 12,   /**< ʵ�����û����� */
    ACTION_TYPE_BACKUP          = 13,   /**< ����*/
    ACTION_TYPE_SMS             = 14,   /**< ����*/
    ACTION_TYPE_EMAIL           = 15,   /**< �ʼ�*/
    ACTION_TYPE_END_TASK        = 16,   /**< ��������*/
    ACTION_TYPE_START_TASK      = 17,   /**< ��ʼ����*/
    ACTION_TYPE_CREATE_NEW_ALARM  = 18,   /**< �����¸澯*/
    ACTION_TYPE_TRAN_ALARM      = 19,   /**< ת���澯*/
    ACTION_TYPE_PLAN            = 20,   /**< Ԥ��*/
    /* Added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */
    ACTION_TYPE_VOCTALK        = 21,   /**< �����Խ� */
    /* Added by y01359, 2014-11-13 for �澯������A8���� */
    ACTION_TYPE_TVWALL_SCENE   = 22,   /**< A8���� */
    ACTION_TYPE_TVWALL_MONITOR = 23,   /**< A8ʵ�� */

    ACTION_TYPE_MAX,                    /**< ���ֵ */
    ACTION_TYPE_INVALID = 0xFFFFFFFF    /**< ��Чֵ */
}ACTION_TYPE_E;

/** �û�״̬ö�� */
typedef enum tagUserStatus
{
    USER_STATUS_LOCK    = 1,    /**< ���� */
    USER_STATUS_UNLOCK  = 2,    /**< ���� */
    USER_STATUS_ONLINE  = 3,    /**< ���� */
    USER_STATUS_OFFLINE = 4,    /**< ���� */

    USER_STATUS_MAX,                       /**< ���ֵ */
    USER_STATUS_INVALID = 0xFFFFFFFF       /**< ��Чֵ */
}USER_STATUS_E;

/**
* @enum tagASCameraStatus
* @brief �����״̬ö��
* @attention
*/
typedef enum tagASCameraStatus
{
    AS_CAMERA_STATUS_ONLINE         = 1,    /**< ��������� ,��IMOS_DEV_STATUS_ONLINEȡֵһ��*/
    AS_CAMERA_STATUS_OFFLINE        = 2,    /**< ��������� */
    AS_CAMERA_STATUS_VIDEO_LOST     = 3,    /**< �������Ƶ��ʧ */
    AS_CAMERA_STATUS_VIDEO_RESUME   = 4,    /**< �������Ƶ�ָ� */

    AS_CAMERA_STATUS_REPAIRE        = 5,   /**< ����������� ��ö��5~8�����ͽ���ʱʹ�ã����ڼ������͸��ϼ������ڲ�ʹ��*/
    AS_CAMERA_STATUS_MOVE           = 6,   /**< �������Ǩ�� */
    AS_CAMERA_STATUS_BUILD          = 7,   /**< ������ڽ��� */
    AS_CAMERA_STATUS_POWEROFF       = 8,   /**< ������ϵ��� */

    AS_CAMERA_STATUS_MAX,
    AS_CAMERA_STATUS_INVALID = 0xFFFFFFFF
}AS_CAMERA_STATUS_E;

/** ��������ö�� */
typedef enum tagVideoAreaType
{
    VIDEO_AREA_TYPE_MASK          = IMOS_VIDEO_AREA_TYPE_MASK,           /**< �ڸ����� */
    VIDEO_AREA_TYPE_COVER_DETECT  = IMOS_VIDEO_AREA_TYPE_COVER_DETECT,   /**< �ڵ����� */
    VIDEO_AREA_TYPE_MOTION_DETECT = IMOS_VIDEO_AREA_TYPE_MOTION_DETECT,  /**< �˶�������� */
    VIDEO_AREA_TYPE_ROI           = IMOS_VIDEO_AREA_TYPE_ROI,            /**< ������ǿ */

    VIDEO_AREA_TYPE_MAX,                   /**< ���ֵ */
    VIDEO_AREA_TYPE_INVALID = 0xFFFFFFFF   /**< ��Чֵ */
}VIDEO_AREA_TYPE_E;

/** �澯���ؼ���ö�� */
typedef enum tagAlarmSeverityLevel
{
    ALARM_SEVERITY_CRITICAL = 0,    /**< Σ�� */
    ALARM_SEVERITY_MAJOR    = 1,    /**< ��Ҫ */
    ALARM_SEVERITY_MINOR    = 2,    /**< ��Ҫ */
    ALARM_SEVERITY_WARN     = 3,    /**< ���� */
    ALARM_SEVERITY_INFO     = 4,    /**< ��ʾ */

    ALARM_SEVERITY_MAX      = 31,   /**< ���ֵ */
    ALARM_SEVERITY_ALL      = 0xFFFFFFFE,   /**< ���и澯����������� */
    ALARM_SEVERITY_INVALID  = 0xFFFFFFFF    /**< ��Чֵ */
}ALARM_SEVERITY_LEVEL_E;

/**
* @enum tagCtrlMode
* @brief �������ģʽ
* @attention ��
*/
typedef enum tagCtrlMode
{
    CTRL_MODE_NORMAL = 0,               /**< ��ͨ����ģʽ */
    CTRL_MODE_FULL = 1,                 /**< ǿ����ģʽ */

    CTRL_MODE_MAX,                      /**< ���ֵ */
    CTRL_MODE_INVALID = 0xFFFFFFFF      /**< ��Чֵ */
}FULL_CTRL_MODE_E;

/**
* @enum tagSrvType
* @brief ҵ������,������¼�����ã��û�����ɫ��Ȩ�ޡ��豸����Դ����ʵ���ࡢ�����ࡢ��̨���ơ�Ԥ��λ��Ѳ����·���洢�ࡢ�ط���
* @attention ��
*/
typedef enum tagSrvType
{
    SRV_TYPE_LOGIN          = 0,                        /**< ��¼ */
    SRV_TYPE_CONFIG_USER    = 1,                        /**< �û�����:���û������ɫ */
    SRV_TYPE_CONFIG_ROLE    = 2,                        /**< ��ɫ���� */
    SRV_TYPE_CONFIG_DEV     = 4,                        /**< �豸���� */
    SRV_TYPE_CONFIG_RES     = 5,                        /**< ��Դ����(�����洢��Դ,���ݣ���ת����Դ��) */

    SRV_TYPE_CONFIG_STORAGE_PLAN    = 6,                /**< �洢�ƻ����� */
    SRV_TYPE_CONFIG_SWITCH_PLAN     = 7,                /**< ���мƻ����� */
    SRV_TYPE_CONFIG_CRUISE_PLAN     = 8,                /**< Ѳ���ƻ����� */

    SRV_TYPE_CONFIG_PTZ     = 9,                        /**< ��̨���� */
    SRV_TYPE_CONFIG_TL      = 10,                       /**< ͸��ͨ�������� */
    SRV_TYPE_VOD            = 11,                       /**< �ط�:��ǩ��ɾ */

    SRV_TYPE_MONITOR            = 12,                   /**< ʵʱ��� */
    SRV_TYPE_SWITCH             = 13,                   /**< ���� */
    SRV_TYPE_PLAN_SWITCH        = 14,                   /**< �ƻ����� */
    SRV_TYPE_VOICE_TALK         = 15,                   /**< �����Խ� */
    SRV_TYPE_VOICE_BROADCAST    = 16,                   /**< �����㲥 */
    SRV_TYPE_PTZ                = 17,                   /**< ��̨���� */
    SRV_TYPE_TL                 = 18,                   /**< ͸��ͨ�� */

    SRV_TYPE_BOOLEAN    = 19,                           /**< ������ */

    SRV_TYPE_MAP        = 20,                           /**< ��ͼ����(�ϴ�,ɾ��,�޸�,����,����ȱʡ��ͼ) */

    SRV_TYPE_STORAGE    = 22,                           /**< �洢 */

    SRV_TYPE_SYS_BACKUP = 23,                           /**< ϵͳ��Ϣ���� */

    SRV_TYPE_SUBSCRIBE  = 24,                           /**< �����ϱ�ҵ�� */

    SRV_TYPE_TRUNK      = 25,                           /**< ���߲���ҵ�� */

    SRV_TYPE_CONFIG_BACKUP_PLAN = 26,                   /**< ���ݼƻ����� */

    SRV_TYPE_BACKUP     = 27,                           /**< ���� */

    SRV_TYPE_SALVO      = 28,                           /**< ����ʾ */
    SRV_TYPE_GROUPSALVO         = 29,                   /**< ����Ѳ */
    SRV_TYPE_GROUPSALVO_PLAN    = 30,                   /**< ����Ѳ�ƻ� */

    /* added by z06806 for vodwall prj 20101202 begin */
    SRV_TYPE_VODWALL            = 31,                   /**< �ط���ǽ */
    /* added by z06806 for vodwall prj 20101202 end */

    SRV_TYPE_CONFIG_TIME = 32,                          /**< ʱ������ */

    SRV_TYPE_REBOOT = 33,                               /**< ���� */

    SRV_TYPE_SHUTDOWN = 34,                             /**< �ػ� */

    SRV_TYPE_RESTORE_DEFAULT = 35,                      /**< �ָ�Ĭ�� */

    SRV_TYPE_VOD_AND_DOWNLOAD = 36,                      /**< �طź����� */

    SRV_TYPE_CONFIG_STREAM_STORAGE_PLAN = 37,                   /**< ��ת��ƻ����� */

    SRV_TYPE_SMS = 38,                                  /**< ���� */

    SRV_TYPE_EMAIL = 39,                                /**< �ʼ� */

    SRV_TYPE_SYS_PARAM_SET = 40,                        /**< ϵͳ�������� */
    SRV_TYPE_VOICE_USER_TALK         = 41,              /**< �ͻ��������Խ� */
    SRV_TYPE_VOICE_USER_BROADCAST    = 42,              /**< �ͻ��������㲥 */
    SRV_TYPE_MON_USER_TALK           = 43,              /**< �ͻ�������Ƶ�Խ� */
    SRV_TYPE_MON_USER_BROADCAST      = 44,              /**< �ͻ�������Ƶ�㲥 */

    SRV_TYPE_CONFIG_ACTION_PLAN = 45,                   /**< Ԥ������ */

    SRV_TYPE_PLAN = 46,                                 /**< Ԥ�� */

    SRV_TYPE_EVENT = 47,                                /**< �¼�ʹ�� */

    SRV_TYPE_RESTART = 48,                                /**< ���������� */

    /* Added by dengshuhua00673, 2012-12-22 of �Զ�������Ѳ */
    SRV_TYPE_AUTOSALVO = 49,                            /**< �Զ�������Ѳ */

	SRV_TYPE_CONFIG_GUARD_POSITION_PLAN  = 50,          /**< ����λ�ƻ����� */

	SRV_TYPE_GUARD_POSITION_PLAN  = 51,          /**< ����λ�ƻ� */

    /* Begin added by y01359 2014-10-09 for A8 */
	SRV_TYPE_TVWALL             = 52,                   /**< ����ǽ */

	SRV_TYPE_TVWALL_OPERATE     = 53,                   /**< ����ǽsip���� */
    /* End added by y01359 2014-10-09 for A8 */

    /* Begin: Added by chenmenglin 04110, 2017-09-09 for MPPD54245 A8ƴ���豸��Ѳ���� */
    SRV_TYPE_AUTOPOLL           = 54,                   /**< A8�Զ�������Ѳ */
    SRV_TYPE_WINDOWGROUPPOLL    = 55,                  /**< A8��������Ѳ */
    /* End: Added by chenmenglin 04110, 2017-09-09 for MPPD54245 A8ƴ���豸��Ѳ���� */

    SRV_TYPE_TOLLGATE           = 99,                   /**< ���ڵ羯 */

    SRV_TYPE_PTZ_LOCK           = 171,
    SRV_TYPE_PTZ_UNLOCK           = 172,
    SRV_TYPE_SERVICE_VOD = 361,                                 /**< �ط� */
    SRV_TYPE_SERVICE_DOWNLOAD = 362,                            /**< ���� */
    SRV_TYPE_SERVICE_LOCAL_STOR = 363,                            /**< ����¼�� */

    SRV_TYPE_MAX,
    SRV_TYPE_INVALID = 0xFFFFFFFF
}SRV_TYPE_E;

/** �������ö�� */
typedef enum tagOperateResult
{
    OPERATE_RESULT_SUCCESS  = 0,    /**< �ɹ� */
    OPERATE_RESULT_FAIL     = 1,    /**< ʧ�� */

    OPERATE_RESULT_MAX,                     /**< ���ֵ */
    OPERATE_RESULT_INVALID = 0xFFFFFFFF     /**< ��Чֵ */
}OPERATE_RESULT_E;

typedef enum tagOperateType
{
    OPERATE_USER_LOGIN  = 0,    /**< �û���½ */
    OPERATE_USER_LOGOUT = 1,    /**< �û��ǳ� */

    OPERATE_USER_START  = 2,    /**< �û�����ҵ�� */
    OPERATE_USER_STOP   = 3,    /**< �û�ֹͣҵ�� */

    OPERATE_CONFIG_ADD  = 4,    /**< �������� */
    OPERATE_CONFIG_MOD  = 5,    /**< �޸����� */
    OPERATE_CONFIG_DEL  = 6,    /**< ɾ������ */

    OPERATE_FILE_DOWNLOAD   = 7,    /**< �ļ����� */

/*****************��������������Ķ�������(��ʼ)*******************/

    OPERATE_DEV_OFFLINE_STOP    = 8,    /**< �豸����ֹͣ */
    OPERATE_DEV_DELETE_STOP     = 9,    /**< �豸ɾ��ֹͣ */
    OPERATE_DEV_ONLINE_STOP     = 10,   /**< �豸�������ҵ�� */

    OPERATE_USER_QUIT_STOP      = 11,   /**< �û��˳�ֹͣ */
    OPERATE_USER_DELETE_STOP    = 12,   /**< �û�ɾ��ֹͣ */
    OPERATE_USER_KEEPOUT_STOP   = 13,   /**< �û�����ʧ�����ҵ�� */

    OPERATE_EXTDOMAIN_OFFLINE_STOP  = 14,   /**< ��������ֹͣ */
    OPERATE_EXTDOMAIN_DELETE_STOP   = 15,   /**< ����ɾ��ֹͣ */
    OPERATE_EXTDOMAIN_ONLINE_STOP   = 16,   /**< �����������ҵ�� */

    OPERATE_SRV_TRANSFER_STOP   = 17,   /**< ҵ��ת��ֹͣ */
    OPERATE_SRV_TRANSFER_START  = 18,   /**< ҵ��ת������ */
    OPERATE_SRV_REAVE_STOP      = 19,   /**< ҵ����ռֹͣ */
    OPERATE_SRV_RESTORE_START   = 20,   /**< ���ϻָ����� */

    OPERATE_SRV_TIMEOUT_STOP    = 21,   /**< ��ʱֹͣ */

    OPERATE_CONFIG_MOD_STOP = 22,   /**< ���ñ仯ֹͣ */

    OPERATE_ALARM_START = 23,       /**< �澯�������� */
    OPERATE_ALARM_STOP  = 24,       /**< �澯����ֹͣ */

    OPERATE_PLAN_START  = 25,       /**< �ƻ����������� */
    OPERATE_PLAN_STOP   = 26,       /**< �ƻ�������ֹͣ */

/*****************��������������Ķ�������(����)*******************/

    OPERATE_ADJUST_FORWARD = 27,    /**< ������һ������ */
    OPERATE_ADJUST_BACKWARD = 28,   /**< ������һ������ */
    OPERATE_ADJUST_PAUSE = 29,      /**< ������ͣ���� */
    OPERATE_ADJUST_CONTINUE = 30,   /**< ���м������� */

    OPERATE_TRUNK_START = 31,       /**< �������߲��� */
    OPERATE_TRUNK_STOP = 32,        /**< ֹͣ���߲��� */
    OPERATE_TRUNK_APPLY = 33,       /**< ������߲��� */
    OPERATE_TRUNK_FREE = 34,        /**< �ͷŸ��߲��� */

    OPERATE_FILE_LOCK     = 35,     /**< �ļ����� */
    OPERATE_FILE_UNLOCK   = 36,     /**< �ļ����� */
    OPERATE_FILE_DELETE   = 37,     /**< �ļ�ɾ�� */

    OPERATE_USER_RESTART  = 38,     /**< �û�����ҵ�� */

    OPERATE_ALARM_RESUME  = 39,     /**< �澯�����ָ� */
    OPERATE_USER_ACCEPT   = 40,     /**< �û�����ҵ�� */
    OPERATE_USER_REJECT   = 41,     /**< �û��ܾ�ҵ�� */

    OPERATE_ALARM_EXE_TASK = 42,    /**< �û�ִ������ */
    OPERATE_ALARM_LAUNCH_TRIGGER = 43,    /**< �û����д����� */
    OPERATE_ALARM_START_PLAN = 44,    /**< �û�����Ԥ�� */

    OPERATE_THIRD_DEVICE_ERROR = 45,  /**<�������豸����  */

    OPERATE_USER_RESTART_VMSERVER = 46,  /**<�û����������� */
    /* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
    OPERATE_RECORD_LOCK     = 47,     /**< ¼������ */
    OPERATE_RECORD_UNLOCK   = 48,     /**< ¼����� */
    OPERATE_CHECK_LOCK_SPACE = 49,     /**< ��������ռ�*/
    /* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
    /* Begin Added by lw0581,2013-11-6 for  VVD06374*/
    OPERATE_STORAGE_NOTIFY_TWARE    = 50,    /**< ��TWARE֪ͨ�洢�ռ�仯 */
    OPERATE_EXPORT_VEDIO_TO_USB     = 51,    /**< ¼�񵼳���U�� */
    OPERATE_EXPORT_PIC_TO_USB       = 52,    /**< ͼƬ������U �� */
    OPERATE_CONFIG_QUERY            = 53,    /**< ��ѯ���� */
    OPERATE_EXPORT_PROCESS_QUERY    = 54,    /**< ��ѯ�������� */
    OPERATE_USB_DISK_QUERY          = 55,    /**< ��ѯU����Ϣ */
    OPERATE_USB_DIR_QUERY           = 56,    /**< ��ѯU���ļ�����Ϣ */
    OPERATE_RECORD_REPLAY           = 57,    /**< ¼��ط� */
    OPERATE_RECORD_DOWNLOAD         = 58,    /**< ¼������ */
    OPERATE_PIC_REMOTE_EXPORT       = 59,    /**< ͼƬԶ�̵��� */
    /* End Added by lw0581,2013-11-6 for  VVD06374*/
    /*Begin: Added by mozhanfei(m01736), 2014-7-2 for add query vedio operate log*/
    OPERATE_RECORD_QUERY           = 60,    /**< ��ѯ¼��*/
    /*End: Added by mozhanfei(m01736), 2014-7-2 for add query vedio operate log*/
    /* Begin add by z00562 for ��˳*/
    OPERATE_TG_RECORD_DEL  = 61,
    /* End add by z00562 for ��˳*/
    /* Begin add by z00562 for ��־������ */
    OPERATE_TG_RECORD_QUERY  = 62,
    OPERATE_TG_IMAGE_DOWNLOAD = 63,
    OPERATE_TG_RECORD_DOWNLOAD  = 64,
    OPERATE_TG_RECORD_CHECK  = 65,
    /* End add by z00562 for ��־������ */

	/* Begin add by y01359, 2016-03-24 for A8 */
	OPERATE_A8_SCENE_START = 66,       /**< A8������������ */
    OPERATE_A8_SCENE_STOP  = 67,       /**< A8��������ֹͣ */
    /* End add by y01359, 2016-03-24 for A8 */

    /* Begin: Added by chenmenglin 04110, 2017-11-10 for MPPD54245 A8ƴ���豸��Ѳ���� */
    OPERATE_A8_AUTOPOLL_START = 68,      /**< A8ƴ����Ѳ�������� */
    OPERATE_A8_AUTOPOLL_STOP  = 69,       /**< A8ƴ����Ѳ����ֹͣ */
    /* End: Added by chenmenglin 04110, 2017-11-10 for MPPD54245 A8ƴ���豸��Ѳ���� */

    OPERATE_TYPE_MAX,
    OPERATE_TYPE_INVALID = 0xFF
}OPERATE_TYPE_E;

/** �������� */
typedef enum tagExDomainType
{
    EX_DOMAIN_SUPERIOR  = 1,    /**< �ϼ��� */
    EX_DOMAIN_JUNIOR    = 2,    /**< �¼��� */
    EX_DOMAIN_PARITY    = 3,    /**< ͬ���� */


    EX_DOMAIN_SAFE_VM     = 10001,    /**< VM��ȫ������ */
    EX_DOMAIN_SAFE_DVR    = 10002,    /**< DVR��ȫ������ */
    EX_DOMAIN_SAFE_MATRIX = 10003,    /**< ����ȫ������ */

    EX_DOMAIN_MAX,                      /**< ���ֵ */
    EX_DOMAIN_INVALID = 0xFFFFFFFF      /**< ��Чֵ */
}EX_DOMAIN_TYPE_E;

/** �洢ģʽ */
typedef enum tagStorageMode
{
    STORAGE_MODE_IPSAN  = 1,    /**< ����IPSAN�洢ģʽ*/
    STORAGE_MODE_NAS    = 2,    /**< NAS �洢ģʽ*/
    STORAGE_MODE_LOCAL  = 3,    /**< ����Ӳ�̴洢ģʽ*/

    STORAGE_MODE_MAX ,                     /**< ���ֵ*/
    STORAGE_MODE_INVALID = 0xFFFFFFFF,     /**< ��Чֵ*/

}STORAGE_MODE_E;

/**
* @enum tagASDEVShareOperationType
* @brief �豸�����������ö��
* @attention
*/
typedef enum tagASDEVShareOperationType
{
    AS_DEVSHARE_OPERATION_DEL   = 0,    /**< �����豸ȡ�� */
    AS_DEVSHARE_OPERATION_ADD   = 1,    /**< �����豸���� */
    AS_DEVSHARE_OPERATION_MOD   = 2,    /**< �����豸�޸� */
    AS_DEVSHARE_OPERATION_QUERY = 3,    /**< �����豸������ѯ */

    AS_DEVSHARE_OPERATION_MAX,
    AS_DEVSHARE_OPERATION_INVALID = 0xFFFFFFFF
}AS_DEVSHARE_OPERATION_TYPE_E;

/**
* @enum tagIMOSType
* @brief ���Ͷ���
* @attention IMOS������Դ����ö��(��15��1003�Ǹ澯Դ,�澯Դ�豸��Ҫ�ڴ˷�Χ��,�Ǹ澯Դ�豸�����ڴ˷�Χ��)
*            4001-5000Ϊ��Ѷ����
*            201-300Ϊ��Ѷ�豸
*            �豸���͵�ȡֵ��ΧΪ11-2000
*/
typedef enum tagIMOSType
{
    IMOS_TYPE_ORG = 1,                     /**< ��֯�� */
    IMOS_TYPE_OUTER_DOMAIN = 2,            /**< ���� */
    IMOS_TYPE_LOCAL_DOMAIN = 3,            /**< ���� */
    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
    IMOS_TYPE_CABIN = 4,                   /**< ����,�ǿͻ�������ĸ���,ƽ̨�ݲ�ʹ�� */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

    IMOS_TYPE_DEVICE_MIN_VALUE = 10,       /**< �豸��Դ������Сֵ */

    IMOS_TYPE_DM = 11,                     /**< DM */
    IMOS_TYPE_MS = 12,                     /**< MS */
    IMOS_TYPE_VX500 = 13,                  /**< VX500 */
    IMOS_TYPE_MONITOR = 14,                /**< ������ */

    IMOS_TYPE_EC = 15,                     /**< EC */
    IMOS_TYPE_DC = 16,                     /**< DC */

    IMOS_TYPE_GENERAL = 17,                /**< ͨ���豸 */
    IMOS_TYPE_ECR = 18,                    /**< ECR */

    IMOS_TYPE_TS = 19,                     /**< TS */
    IMOS_TYPE_LS = 20,                      /**<LS ��־��Ʒ�����*/
    IMOS_TYPE_VOD = 21,                  /**<VOD*/
    IMOS_TYPE_TMS = 30,                    /**< ��ͨý�彻�������� */
    IMOS_TYPE_TOLLGATE = 31,               /**< ���� */
    IMOS_TYPE_DR = 32,                     /**< �������������� */
    IMOS_TYPE_MAPM = 33,                   /**< ��ͼ������ */
    IMOS_TYPE_IAHR = 34,                   /**< �����������ڷ����� */

    /* Begin: Added by zhongke, 2015-03-01 for CDS�ƴ洢 */
    IMOS_TYPE_CDS = 35,                    /**< CDSϵͳ */
    /* End: Added by zhongke, 2015-03-01 for CDS�ƴ洢 */

    /* Begin: Added by luchunfeng02289, 2016-04-07 for �������豸���� */
	IMOS_TYPE_IOT = 36,                    /**< �������豸 */
	/* End: Added by luchunfeng02289, 2016-04-07 for �������豸���� */

    /* Begin Added by shendongchun 00400 2014-02-26 for �����ݷ��������� */
    IMOS_TYPE_DB8500 = 40,                 /**< ���ݴ洢������ - DB8500 */
    IMOS_TYPE_DB9500 = 41,                 /**< ���ݴ洢������ - DB9500 */
    /* End Added by shendongchun 00400 2014-02-26 for �����ݷ��������� */

    IMOS_TYPE_MCU = 201,                   /**< MCU */
    IMOS_TYPE_MG = 202,                    /**< MG */

    IMOS_TYPE_CAMERA = 1001,               /**< ����� */
    IMOS_TYPE_TOLLGATE_CAMERA = 1002,      /**< ������� */
    IMOS_TYPE_ALARM_SOURCE = 1003,         /**< �澯Դ */

    IMOS_TYPE_STORAGE_DEV = 1004,          /**< �洢�豸 */
    IMOS_TYPE_TRANS_CHANNEL = 1005,        /**< ͸��ͨ�� */
    /* Begin: added by yW1054 in 2014-11-24 for ͼ��ͻ���ͳ�� */
    IMOS_TYPE_ICSCI = 1006,		  /**< ͼ��ͻ��� */
    /* End: added by yW1054 in 2014-11-24 for  ͼ��ͻ���ͳ��*/

    IMOS_TYPE_ALARM_OUTPUT = 1200,         /**< �澯��� */

    IMOS_TYPE_BM = 1300,                   /**< BM */

    IMOS_TYPE_SEMAPHORE_OUTPUT = 1400,    /**<��������� */
    /*Begin: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/
    IMOS_TYPE_CDM = 1500,                   /**< CDM */
    IMOS_TYPE_CDV = 1501,                   /**< CDV */
    /*End: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/

	/* Begin Added by y01359 2014-09-26 for A8 */
	IMOS_TYPE_A8 = 1502,                   /**< A8�豸 */
    /* End Added by y01359 2014-09-26 for A8 */

    /* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE����ƽ̨ */
    IMOS_TYPE_XWARE = 1503,                /**< XWARE�豸 */
    /* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388��XWARE����ƽ̨ */

    IMOS_TYPE_FLASHLIGHT       = 1999,     /**< ����� */
    IMOS_TYPE_DEVICE_MAX_VALUE = 2000,     /**< �豸��Դ�������ֵ */

    IMOS_TYPE_GUARD_TOUR_RESOURCE = 2001,  /**< ������Դ */
    IMOS_TYPE_GUARD_TOUR_PLAN = 2002,      /**< ���мƻ� */
    IMOS_TYPE_MAP = 2003,                  /**< ��ͼ */

    IMOS_TYPE_XP = 2005,                   /**< XP */
    IMOS_TYPE_XP_WIN = 2006,               /**< XP���� */
    IMOS_TYPE_GUARD_PLAN = 2007,           /**< �����ƻ� */

    IMOS_TYPE_DEV_ALL = 2008,              /**< ���е��豸����(EC/DC/MS/DM/VX500/����ͷ/������) */

	IMOS_TYPE_GUARD_POSITION_PLAN = 2009,	   /**< ���ؼƻ� */

    /* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
    IMOS_TYPE_WIRELESS_INSPECTION      = 2200,       /**< ���߼�� */
    IMOS_TYPE_SENSOR                   = 2201,       /**< ������ */
    IMOS_TYPE_MOVING_RING_EQUIPMENT    = 2202,       /**< �����豸 */
    IMOS_TYPE_COMMUNICATION_EQUIPMENT  = 2203,       /**< ͨ���豸 */
    IMOS_TYPE_OTHER_IOT_EQUIPMENT      = 2250,       /**< �����豸���� */
    IMOS_TYPE_IOT_RES_MAX_VALUE        = 2251,       /**< ��������Դ�������ֵ */
    /* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

	/* Begin Added by y01359 2014-09-26 for A8 */
	IMOS_TYPE_WINDOW_A8 = 2999,            /**< A8���� */
	IMOS_TYPE_TV_WALL_A8 = 3000,           /**< A8����ǽ */
    /* End Added by y01359 2014-09-26 for A8 */

    IMOS_TYPE_TV_WALL = 3001,              /**< ����ǽ */

    IMOS_TYPE_CAMERA_GROUP = 3002,                   /**< ������� */
    IMOS_TYPE_MONITOR_GROUP = 3003,                  /**< �������� */
    IMOS_TYPE_SALVO_RESOURCE = 3004,                 /**< ����ʾ��Դ */
    IMOS_TYPE_BROADCAST_GROUP = 3005,                /**< �㲥�� */
    IMOS_TYPE_IMAGE_MOSAIC = 3006,                   /**< ͼ��ƴ����Դ */
    IMOS_TYPE_BALLLINKAGE_GROUP = 3007,              /**< ǹ����������Դ */
    IMOS_TYPE_GROUP_SWITCH_RESOURCE = 3010,          /**< ����Ѳ��Դ */
    IMOS_TYPE_GROUP_SWITCH_PLAN = 3011,              /**< ����Ѳ�ƻ���Դ */
    /* Begin Added by dengshuhua00673, 2012-12-14 of �Զ�������Ѳ */
    IMOS_TYPE_AUTO_SWITCH_RESOURCE = 3012,           /**< �Զ�������Ѳ��Դ */
    IMOS_TYPE_GROUP_SWITCH_RESOURCE_BOTH = 3013,     /**< ����(�Զ�������ʾ)��Ѳ��Դ */
    /* End Added by dengshuhua00673, 2012-12-14 of �Զ�������Ѳ */

    IMOS_TYPE_SCENE             = 3015,              /**< ������Դ(�μ�DAO�궨��#DAO_RES_AGG_TYPE_SCENE,���иĶ�������ͬ��) */

    IMOS_TYPE_ACTION_PLAN = 3016,          /**< Ԥ����Դ */

    /* Begin Added by liucanming/03903, 2017-09-05 of MPPD54245 A8����Ѳ �Զ�������Ѳ */
    IMOS_TYPE_AUTO_POLL_RESOURCE = 3021,            /**A8�Զ�������Ѳ��Դ */
    IMOS_TYPE_WINDOW_POLL_RESOURCE = 3022,          /**A8 ��������Ѳ��Դ */
    /* End Added by liucanming/03903, 2017-09-05 of MPPD54245 A8����Ѳ �Զ�������Ѳ */

    IMOS_TYPE_TRUNK = 3050,                /**< ���� */

    IMOS_TYPE_CONFERENCE = 4001,           /**< ������Դ */

    IMOS_TYPE_USER       = 5001,          /**< �û���Դ */

    /* Begin Added by zhudingjingKF0104, 2013-06-19 of ������Դ�� */
    IMOS_TYPE_MICROPHONE = 8001,           /**< �����Խ���Դ */
    IMOS_TYPE_SPEAKER    = 8002,           /**< �����㲥��Դ */

    IMOS_TYPE_AUDIO_INPUT = 8003,          /**< ������Ƶ���� */
    IMOS_TYPE_AUDIO_OUTPUT = 8004,         /**< ������Ƶ��� */
    /* End Added by zhudingjingKF0104, 2013-06-19 of ������Դ�� */

    /* Begin Added by luchunfeng02289, 2015-09-28 for ADUȫ��ƴ��*/
    IMOS_TYPE_IMAGE_MOSAIC_V2 = 9000,      /**< ADUͼ��ƴ����Դ */
    /* End Added by luchunfeng02289, 2015-09-28 for ADUȫ��ƴ��*/

    /* Begin added by zhukaikai/W4801, 2017-12-28 for �ر������� MPPD54420 */
    IMOS_TYPE_LANDMARKS = 9026,       /**< �ر���/RFID������(���ӻ��ͻ��˳�֮ΪRFID) */
    /* End added by zhukaikai/W4801, 2017-12-28 for �ر������� MPPD54420 */

    IMOS_TYPE_MAX,
    IMOS_TYPE_INVALID = 0xFFFFFFFF
}IMOS_TYPE_E;

/**
 * @enum tagAlarmSrcType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagAlarmDevType
{
    ALARM_DEV_TYPE_EC  = 0,            /**< �澯�豸ΪEC */
    ALARM_DEV_TYPE_DC  = 1,            /**< �澯�豸ΪDC */
    ALARM_DEV_TYPE_IPSAN  = 2,            /**< �澯�豸Ϊ�洢�豸 */
    ALARM_DEV_TYPE_CAM  = 3,            /**< �澯�豸Ϊ����� */
    ALARM_DEV_TYPE_BOOLEAN  = 4,            /**< �澯�豸Ϊ������ */
    ALARM_DEV_TYPE_SERIAL   = 5,            /**< �澯�豸Ϊ���� */
    ALARM_DEV_TYPE_GENERAL  = 6,            /**< �澯�豸Ϊͨ���豸 */

    ALARM_DEV_TYPE_MAX,                     /**< �澯�豸ö�����ֵ */
    ALARM_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}ALARM_DEV_TYPE_E;

/**
 * @enum tagDMType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagDMDevType
{
    DM_DEV_TYPE_3  = 0,            /**< DM3.0 */
    DM_DEV_TYPE_5  = 2,            /**< DM5.0 */
    DM_DEV_TYPE_CDV  = 3,            /**< CDV */
    DM_DEV_TYPE_MAX,                     /**< DM�豸ö�����ֵ */
    DM_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}DM_DEV_TYPE_E;

/**
 * @enum tagVODType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagVODDevType
{
    VOD_DEV_TYPE_5  = 0,            /**< VOD 5.0*/
    VOD_DEV_TYPE_MAX,                     /**< VOD�豸ö�����ֵ */
    VOD_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}VOD_DEV_TYPE_E;


/**
 * @enum tagMSType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagMSDevType
{
    MS_DEV_TYPE_3  = 0,            /**< MS3.0 */
    MS_DEV_TYPE_5  = 2,            /**< MS5.0 */
    MS_DEV_TYPE_MAX,                     /**< MS�豸ö�����ֵ */
    MS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}MS_DEV_TYPE_E;

/**
 * @enum tagTMSType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagTMSDevType
{
    TMS_DEV_TYPE_3  = 0,            /**< TMS3.0 */
    TMS_DEV_TYPE_5  = 2,            /**< TMS5.0 */
    TMS_DEV_TYPE_5516  = 3,            /**< TMS5516 */
    TMS_DEV_TYPE_MAX,                     /**< MS�豸ö�����ֵ */
    TMS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}TMS_DEV_TYPE_E;

/**
 * @enum tagTSType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagTSDevType
{
    TS_DEV_TYPE_3  = 0,            /**< TS3.0 */
    TS_DEV_TYPE_5  = 2,            /**< TS5.0 */
    TS_DEV_TYPE_MAX,                     /**< TS�豸ö�����ֵ */
    TS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}TS_DEV_TYPE_E;

/**
 * @enum tagLSType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagLSDevType
{
    LS_DEV_TYPE_LOG8500  = 0,            /**< LS LOG8500 */
    LS_DEV_TYPE_LOG9500  = 1,            /**< LS LOG9500 */
    LS_DEV_TYPE_MAX,                     /**< LS�豸ö�����ֵ */
    LS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}LS_DEV_TYPE_E;

/* Begin added by hw3668 for MAPM9500*/
/**
 * @enum tagMAPMType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagMAPMDevType
{
    MAP_DEV_TYPE_MAPM8500  = 0,           /**< MAPM8500 */
    MAP_DEV_TYPE_MAPM9500  = 1,           /**< MAPM9500 */
    MAP_DEV_TYPE_MAX,                     /**< MAPM�豸ö�����ֵ */
    MAP_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}MAPM_DEV_TYPE_E;
/* End added by hw3668 for MAPM9500*/

/* Begin: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */
/**
 * @enum tagCDSDevType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagCDSDevType
{
    CDS_DEV_TYPE_9500  = 0,              /**< CDS9500 */
    CDS_DEV_TYPE_MAX,                     /**< DM�豸ö�����ֵ */
    CDS_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */
}CDS_DEV_TYPE_E;
/* End: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */


/**
* @enum tagNameCodeFlag
* @brief ���Ʊ��:0 ������Ч 1 ����ѯ�豸���� 2 ����ѯ��Դ����
* @attention
*/
typedef enum tagNameCodeFlag
{
    NAME_FLAG_NULL    = 0,                /**< ������Ч */
    NAME_FLAG_DEV     = 1,                /**< ����ѯ�豸���� */
    NAME_FLAG_RES     = 2,                /**< ����ѯ��Դ���� */
    NAME_FLAG_RESCODE = 3,                /**< ����ѯ��Դ���� */

    NAME_FLAG_MAX,                      /**< ���Ʊ��ö�����ֵ */
    NAME_FLAG_INVALID   = 0xFFFFFFFF    /**< ��Чֵ */

}NAME_CODE_FLAG_E;

/**
* @enum tagSearchMode
* @brief ��Ѱģʽ���:0 ������Ч 1 ��ȷƥ�� 2 ģ��ƥ��
* @attention
*/
typedef enum tagSearchMode
{
    SEARCH_MODE_NULL    = 0,                /**< ��Ч */
    SEARCH_MODE_EQU     = 1,                /**< ��ȷƥ��*/
    SEARCH_MODE_LIKE    = 2,                /**< ģ��ƥ�� */

    SEARCH_MODE_MAX,                        /**< ���ֵ */
    SEARCH_MODE_INVALID   = 0xFFFFFFFF      /**< ��Чֵ */

}SEARCH_MODE_E;

/**
* @enum tagTimeFlag
* @brief ʱ����:0 ʱ����Ч 1 ��ʱ����ѯ 2 ��ʱ��β�ѯ
* @attention
*/
typedef enum tagTimeFlag
{
    TIME_FLAG_NULL  = 0,                /**< ʱ����Ч */
    TIME_FLAG_ONE   = 1,                /**< ��ʱ����ѯ */
    TIME_FLAG_TWO   = 2,                /**< ��ʱ��β�ѯ */

    TIME_FLAG_MAX,                      /**< ʱ����ö�����ֵ */
    TIME_FLAG_INVALID   = 0xFFFFFFFF    /**< ��Чֵ */
}TIME_FLAG_E;

/**
* @enum tagStoreAssignType
* @brief �洢�����������
* @attention
*/
typedef enum tagStoreAssignType
{
    ASSIGN_TYPE_SIZE         = 0,       /**< ֱ�ӷ���洢���������д洢 */
    ASSIGN_TYPE_DAY          = 1,       /**< ����洢��ͨ���������������Ҫ��������� */

    ASSIGN_TYPE_MAX,                    /**< �洢�������ö�����ֵ */
    ASSIGN_TYPE_INVALID = 0xFFFFFFFF    /**< ��Чֵ */

}STORE_ASSIGN_TYPE_E;

/**
* @enum tagStoreDevType
* @brief �洢�豸����ö��
* @attention
*/
typedef enum tagStoreDevType
{
    STORE_DEV_TYPE_IPSAN    = 0,            /**< IPSAN�豸 */
    STORE_DEV_TYPE_VX500    = 1,            /**< VX500���� */
    STORE_DEV_TYPE_ECR      = 2,            /**< ECR�豸 */

    /* Begin: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */
    STORE_DEV_TYPE_CDS      = 3,           /**< �ƴ洢�豸 */
    /* End: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */

    STORE_DEV_TYPE_MAX,                     /**< �洢�豸����ö�����ֵ */
    STORE_DEV_TYPE_INVALID  = 0xFFFFFFFF    /**< ��Чֵ */
}STORE_DEV_TYPE_E;

/**
* @enum tagIpsanStoreDevType
* @brief IPSAN�洢�豸������ö��
* @attention
*/
typedef enum tagIpsanStoreDevSubType
{
    STORE_DEV_SUB_TYPE_VX1500      = 0,            /**< VX1500 */
    STORE_DEV_SUB_TYPE_VX1500_E    = 1,            /**< VX1500-E */
    STORE_DEV_SUB_TYPE_VX1600      = 2,            /**< VX1600 */

    STORE_DEV_SUB_TYPE_MAX,                        /**< IPSAN�洢�豸������ö�����ֵ */
    STORE_DEV_SUB_TYPE_INVALID  = 0xFFFFFFFF       /**< ��Чֵ */
}IPSAN_STORE_DEV_SUB_TYPE_E;

/**
* @enum tagStoreConfigType
* @brief �洢��������ö��
* @attention
* 1.��ö����dao_as_def.h�е�#DAO_STORE_CONFIG_TYPE_E�ϸ��Ӧ�������޸ģ�����ͬ������
*/
typedef enum tagStoreConfigType
{
    STORE_CONFIG_TYPE_STOR         = 0,            /**< ֱ������ */
    STORE_CONFIG_TYPE_STREAM_STOR  = 1,            /**< ��ת������ */

    STORE_CONFIG_TYPE_MAX,                        /**< �洢��������ö�����ֵ */
    STORE_CONFIG_TYPE_INVALID     = 0xFFFFFFFF    /**< ��Чֵ */
}STORE_CONFIG_TYPE_E;

/** ͨ������ */
typedef enum tagIMOSChannelType
{
    IMOS_CHANNEL_TYPE_BOOLEAN   = 0,    /**< ������ */
    IMOS_CHANNEL_TYPE_SERIAL    = 1,    /**< ���� */

    IMOS_CHANNEL_TYPE_MAX,
    IMOS_CHANNEL_TYPE_INVALID = 0xFFFFFFFF
}IMOS_CHANNEL_TYPE_E;

/** �����㲥״̬*/
typedef enum tagVocBrdStatus
{
    VOCBRD_STATUS_ON    = 0,    /**< ���ڹ㲥*/
    VOCBRD_STATUS_OFF   = 1,    /**< û�й㲥*/

    VOCBRD_STATUS_MAX,
    VOCBRD_STATUS_INVALID = 0xFFFFFFFF
}VOCBRD_STATUS_E;

/** ͸��ͨ��ʹ��״̬ö�� */
typedef enum tagTlTransChannelStatus
{
    TL_TRANS_CHANNEL_DISABLED   = 0,    /**< ��ʹ�� */
    TL_TRANS_CHANNEL_ENABLED    = 1,    /**< ʹ�� */

    TL_TRANS_CHANNEL_STATUS_MAX,                     /**< ���ֵ */
    TL_TRANS_CHANNEL_STATUS_INVALID = 0xFFFFFFFF     /**< ��Чֵ */
}TL_TRANS_CHANNEL_STATUS_E;

/** ͸��ͨ����ǰ����״̬ö�� */
typedef enum tagTlTransChannelWorkStatus
{
    TL_TRANS_CHANNEL_CLOSED = 0,                        /**< �ر� */
    TL_TRANS_CHANNEL_OPENED = 1,                        /**< �� */

    TL_TRANS_CHANNEL_WORK_STATUS_MAX,                   /**< ���ֵ */
    TL_TRANS_CHANNEL_WORK_STATUS_INVALID = 0xFFFFFFFF   /**< ��Чֵ */
}TL_TRANS_CHANNEL_WORK_STATUS_E;

/**
* @enum tagManufacturerType
* @brief ��������ö��
* @attention
*/
typedef enum tagManufacturerType
{
    MANUFACTURER_TYPE_H3C      = 0,             /**< H3C_8500 */
    MANUFACTURER_TYPE_H3C_3000E,                /**< H3C_3000E */
    MANUFACTURER_TYPE_DB33,                     /**< ��H3C��������DB33��׼����ĳ��� */
    MANUFACTURER_TYPE_OTHER,                    /**< ���϶������ڵĳ��� */

    MANUFACTURER_TYPE_MAX,
    MANUFACTURER_TYPE_INVALID = 0xFFFFFFFF
}MANUFACTURER_TYPE_E;

/**
* @enum tagCameraType
* @brief ���������ö��
* @attention
*/
typedef enum tagCameraType
{
    CAMERA_TYPE_FIX         = 1,            /**< ����̶������ */
    CAMERA_TYPE_PTZ         = 2,            /**< ������̨����� */
    CAMERA_HD_TYPE_FIX      = 3,            /**< ����̶������ */
    CAMERA_HD_TYPE_PTZ      = 4,            /**< ������̨����� */
    CAMERA_TYPE_CAR         = 5,            /**< ��������� */
    CAMERA_TYPE_VIRTUAL     = 6,            /**< ��������� */
    CAMERA_TYPE_BALL_NOT_CONTROL            = 7,            /**< ���ɿر������ */
    CAMERA_HD_TYPE_BALL_NOT_CONTROL         = 8,            /**< ���ɿظ������ */

    /* BEGIN: Added by kf0092 for ��ȫ��������, 2013��3��22�� */
    CAMERA_TYPE_SAFE_VM     = 9,            /**< VM��ȫ��������� */
    CAMERA_TYPE_SAFE_DVR    = 10,           /**< DVR��ȫ��������� */
    CAMERA_TYPE_SAFE_MATRIX = 11,           /**< ����ȫ��������� */
    /* END  : Added by kf0092 for ��ȫ��������, 2013��3��22�� */
	CAMERA_TYPE_FIX_BOX= 12,                /**�佹ǹ�� */

	/* Begin added by y01359, 2014-12-11 for A8 */
	CAMERA_TYPE_VGA = 13,                   /**< VGA��������� */
	CAMERA_TYPE_DVI = 14,                   /**< DVI��������� */
	/* End added by y01359, 2014-12-11 for A8 */

    /* Begin added by zW4385, 2017-12-21 for MPPD54252 ������� */
    CAMERA_TYPE_FE         = 15,            /**< ���������(���ÿ�) */
    CAMERA_HD_TYPE_FE      = 16,            /**< �������������(4KԤ��) */
    /* End added by zW4385, 2017-12-21 for MPPD54252 ������� */

    CAMERA_TYPE_MAX,                        /**< ���������ö�����ֵ */
    CAMERA_TYPE_INVALID     = 0xFFFFFFFF    /**< ��Чֵ */
}CAMERA_TYPE_E;

/**
* @enum tagTargetType
* @brief ���Ŀ������ö��
* @attention
*/
typedef enum tagTargetType
{
    TARGET_TYPE_ORGAN           = 1,                /**< �������� */
    TARGET_TYPE_PLAZA           = 2,                /**< ������㳡 */
    TARGET_TYPE_TVB             = 3,                /**< ��̨����̨ */
    TARGET_TYPE_FINANCE         = 4,                /**< ���ڻ������� */
    TARGET_TYPE_CULTURE         = 5,                /**< ѧУ�Ĳ�����Ժ�� */
    TARGET_TYPE_LIFESUPPLY      = 6,                /**< ˮ��������Ӧվ */
    TARGET_TYPE_MEDICAL         = 7,                /**< ҽ�ƻ��� */
    TARGET_TYPE_STATION         = 8,                /**< ��վ��ͷ */
    TARGET_TYPE_LANDSCAPE       = 9,                /**< ���ξ��� */
    TARGET_TYPE_TRAFFIC         = 10,               /**< ��ͨ��· */
    TARGET_TYPE_CONSUMPTION     = 11,               /**< �̳ǾƵ����ֳ��� */
    TARGET_TYPE_TOLLGATE        = 12,               /**< ���� */
    TARGET_TYPE_OTHER           = 99,               /**< ���� */


    TARGET_TYPE_INVALID         = 0xFFFFFFFF        /**< ��Чֵ */
} TARGET_TYPE_E;


/**
* @enum tagTargetType
* @brief ���Ŀ��������ö��
* @attention
*/
typedef enum tagTargetSubType
{
    TARGET_SUBTYPE_RESERVE                         = 0,                /**< Ĭ�ϱ��� */
    TARGET_SUBTYPE_PUBIC_SECURITY_CONSTRUCTION     = 1,                /**< �����Խ� */
    TARGET_SUBTYPE_TELECOM_OPERATOR_LEASE          = 2,                /**< ��Ӫ������ */
    TARGET_SUBTYPE_COMPANY_CONSTRUCTION            = 3,                /**< ��λ�Խ� */

    TARGET_SUBTYPE_INVALID         = 0xFFFFFFFF        /**< ��Чֵ */
} TARGET_SUBTYPE_E;

/**
* @enum tagCameraAttribute
* @brief ���������ö��
* @attention
*/
typedef enum tagCameraAttribute
{
    CAMERA_ATTRIBUTE_LOCAL      = 0,            /**< ��������ͨ������������� */
    CAMERA_ATTRIBUTE_EC         = 1,            /**< ���������� */
    CAMERA_ATTRIBUTE_ECRHF_NVR  = 2,            /**< ������ECR HFϵ������� */
    CAMERA_ATTRIBUTE_ECPAG      = 3,            /**< ������IPC */
    /* Begin added by y01359, 2015-03-11 for A8 */
    CAMERA_ATTRIBUTE_DISABLE    = 4,            /**< ����������� */
    /* End added by y01359, 2015-03-11 for A8 */
    CAMERA_ATTRIBUTE_MAX,                       /**< ö�����ֵ */
    CAMERA_ATTRIBUTE_INVALID    = 0xFFFFFFFF    /**< ��Чֵ */
}CAMERA_ATTRIBUTE_E;

/**
* @enum tagLicenseType
* @brief License�������
* @attention ��
*/
typedef enum tagLicenseType
{
    LICENSE_TYPE_BASE_FUNCTION_FOR_LINUX = 0x00,    /**< ��ع������������ȨFor Linux */

    LICENSE_TYPE_MCU_LO_DOMAIN = 0x0A,              /**< ����MCU������� */
    LICENSE_TYPE_CAMERA_LO_DOMAIN = 0x10,           /**< ����CAMERA������� */
    LICENSE_TYPE_CAMERA_EX_H3C_DOMAIN = 0x11,       /**< H3C����CAMERA������� */
    LICENSE_TYPE_CAMERA_EX_NOT_H3C_DOMAIN = 0x12,   /**< ��H3C����CAMERA������� */

    LICENSE_TYPE_STORAGE = 0x30,                    /**< �洢������� */
    /*Begin added by luokunzhong 2015-11-25, for tms5516 license У��*/
    LICENSE_TYPE_TMS_5516 = 0x3C,                        /**< TMS5516������� */
    /*End added by luokunzhong 2015-11-25, for tms5516 license У��*/

    LICENSE_TYPE_DM = 0x35,                         /**< DM������� */
    LICENSE_TYPE_MS = 0x36,                         /**< MS������� */
    /* 0x37������DA,����ʹ�� */
    LICENSE_TYPE_SDC = 0x38,                        /**< SDC������� */
    LICENSE_TYPE_TMS = 0x39,                        /**< TMS������� */
    LICENSE_TYPE_TOLLGATE_CAMERA_LO_DOMAIN = 0x3A,  /**< ����ץ������������ */
    /*Begin added by liangchao, 2015-11-25 for BM2516������*/
    LICENSE_TYPE_BM_3_5 = 0x3B,      /**< ����һ���BM3.5(BM2516-DA/BM8516/BM8500-E)������� */
    /*End added by liangchao, 2015-11-25 for BM2516������*/

    /* Begin: Add by lW2822, 2016-09-29 for ƽ̨����BM9500 */
    LICENSE_TYPE_BM_5 = 0x7C,        /**< ����һ���BM5.0(BM9500)������� */
    /* End: Add by lW2822, 2016-09-29 for ƽ̨����BM9500 */
    LICENSE_TYPE_TS = 0x42,                         /**< TS������� */
    LICENSE_TYPE_GASRV_ICSCI = 0x43,                /**< ����ʵսͼ��ͻ��˽��������� */
    LICENSE_TYPE_GASRV_CAMERA = 0x44,               /**< ����ʵս��CAMERA������� */

    LICENSE_TYPE_CAMERA_THIRD_PARTY = 0x45,      /**< ������CAMERA������� */
    LICENSE_TYPE_GASRV_ICC = 0x48,                  /**< ����ʵսΥ��ץ�Ŀͻ��˽��������� */
    LICENSE_TYPE_DB8500E   = 0x54,                         /**< DB��Ⱥ���������������� */
    LICENSE_TYPE_DR8500 = 0x55,                       /**< DR8500��Ⱥ���������������� */
    LICENSE_TYPE_DB   = 0x56,                         /**< DB��Ⱥ���������������� */
    LICENSE_TYPE_DR9500 = 0x57,                       /**< DR9500��Ⱥ���������������� */

	/*Begin added by l02274 2015-6-23, for map license У��*/
    LICENSE_TYPE_MAPM = 0x58,                         /**< MAPM��ͼ���������������� */
    /*End added by l02274 2015-6-23, for map license У��*/

    LICENSE_TYPE_THIRD_STOR = 0x6C,                  /**< �������洢������� */

	/*Begin added by hw3668 2017-4-10, for map5.0 license У��*/
    LICENSE_TYPE_MAPM_5 = 0x7F,                      /**< MAPM5.0��ͼ���������������� */
    /*End added by hw3668 2017-4-10, for map5.0 license У��*/

    LICENSE_TYPE_IAHR = 0x53,                       /**< IAHR������� */

    /* V3R5 license��Ȩ */
    LICENSE_TYPE_BASE_FUNCTION_FOR_VM5 = 0x67,    /**< ��ع������������ȨFor VM5.0 */
    LICENSE_TYPE_DM_5 = 0x68,                         /**< DM5.0������� */
    LICENSE_TYPE_MS_5 = 0x69,                         /**< MS5.0������� */
    LICENSE_TYPE_TMS_5 = 0x6A,                        /**< TMS5.0������� */
    LICENSE_TYPE_TS_5 = 0x6B,                         /**< TS5.0������� */
    LICENSE_TYPE_LS_LOG8500 = 0x6D,                 /**< LOG8500��־��Ʒ���������*/
    LICENSE_TYPE_LS_LOG9500 = 0x6E,                 /**< LOG9500��־��Ʒ���������*/

    /*Begin: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/
    LICENSE_TYPE_CDM = 0x6F,                         /**< CDM������� */
    LICENSE_TYPE_CDV = 0x70,                         /**< CDV������� */
    LICENSE_TYPE_VOD = 0x71,                         /**< VOD������� */
    /*End: Added by mozhanfei(m01736), 2014-8-18 for cloud store*/

    /* Begin: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */
    LICENSE_TYPE_CDS = 0x72,                         /**< CDM������� */
    /* End: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */
    LICENSE_TYPE_MCD = 0x78,                         /**< �ƶ�ָ��ҵ������--�ƶ�ָ�ӵ�¼�ͻ��� */
    LICENSE_TYPE_MLE = 0x79,                         /**< �ƶ�ִ��ҵ������--�ƶ�ִ����¼�ͻ��� */
    LICENSE_TYPE_MVC = 0x7A,                         /**< �ƶ��ɼ�ҵ������--�ƶ�ǰ���豸 */

    /* Begin: Added by yangfeng/yW3815, 2017-12-08 for MPPD54031 VM B3326H200�汾��Ҫ����DB9500E-S��license */
    LICENSE_TYPE_DB9500ES = 0x82,                    /**< DB9500E-S������������� */

    /* �����Ȩ */
    LICENSE_TYPE_CONFERENCE_BASE = 0x97,            /**< ��Ѷ�����Ȩ */

    LICENSE_TYPE_MAX,                               /**< ����������ֵ */
    LICENSE_TYPE_INVALID        = 0xFF
}LICENSE_TYPE_E;

/* Begin: Added by MultiDomain */
/**
* @enum tagInterDomainProtocolType
* @brief ���ͨѶЭ������ö��
* @attention
*/
typedef enum tagInterDomainProtocolType
{
    INTER_DOMAIN_PROTOCOL_DB33      = 0,    /**< DB33 */
    INTER_DOMAIN_PROTOCOL_GLOBALEYE = 1,    /**< ȫ���� */
    INTER_DOMAIN_PROTOCOL_WIDEEYE   = 2,    /**< ���ӽ� */
    INTER_DOMAIN_PROTOCOL_ELECTRIC  = 3,    /**< �Ĵ����� */
    INTER_DOMAIN_PROTOCOL_IMOS      = 4,    /**< IMOS */
    INTER_DOMAIN_PROTOCOL_DB33NEW   = 5,    /**< DB33 2010 */
    INTER_DOMAIN_PROTOCOL_GDA       = 6,    /**< ����A��׼ */
    INTER_DOMAIN_PROTOCOL_GDB       = 7,    /**< ����B��׼ */
    INTER_DOMAIN_PROTOCOL_IMOSV2    = 8,    /**< IMOS V2 */
    INTER_DOMAIN_PROTOCOL_GB        = 9,    /**< ���� */
    INTER_DOMAIN_PROTOCOL_DB33_2012 = 10,   /**< DB33 2012 */

    INTER_DOMAIN_PROTOCOL_SAFE      = 1001, /**< ��ȫ�������� */

    INTER_DOMAIN_PROTOCOL_MAX,                    /**< ö�����ֵ */
    INTER_DOMAIN_PROTOCOL_INVALID = 0xFFFFFFFF    /**< ��Чֵ */
}INTERDOMAIN_PROTOCOL_TYPE_E;
/* End: Added by MultiDomain */


/**
* @enum tagSwitchCircuitAlarmEnabledType
* @brief ��������·���澯����
* @attention ��
*/
typedef enum tagSwitchCircuitAlarmEnabledType
{
    SWITCH_CIRCUIT_ALARM_ENABLED        = 1,    /**< ֧�ֿ�������·���澯(��֧�ֿ�������·��·�澯Ҳ֧�ֿ�������·��·�澯) */
    SWITCH_CIRCUIT_ALARM_DISABLED       = 2,    /**< ��֧�ֿ�������·���澯(�Ȳ�֧�ֿ�������·��·�澯Ҳ��֧�ֿ�������·��·�澯) */
    SWITCH_CIRCUIT_SHORT_ENABLED_ONLY   = 3,    /**< ֧�ֿ�������·��·�澯����֧�ֿ�������·��·�澯 */
    SWITCH_CIRCUIT_BREAK_ENABLED_ONLY   = 4,    /**< ֧�ֿ�������·��·�澯����֧�ֿ�������·��·�澯 */

    SWITCH_CIRCUIT_ALARM_MAX,
    SWITCH_CIRCUIT_ALARM_INVALID = 0xFF
}SWITCH_CIRCUIT_ALARM_ENABLED_TYPE_E;

/**
* @enum tagBackupStatus
* @brief ����״̬ö��
* @attention
*/
typedef enum tagBackupStatus
{
    BACKUP_STATUS_START         = 0,    /**< ��ʼ�������� */
    BACKUP_STATUS_PROCESSING    = 1,    /**< ���ݽ����� */
    BACKUP_STATUS_IDLE          = 2,    /**< �Ǳ���״̬ */

    BACKUP_STATUS_MAX,                    /**< ����״̬ö�����ֵ */
    BACKUP_STATUS_INVALID    = 0xFFFFFFFF /**< ��Чֵ */
}BACKUP_STATUS_E;

/**
 * @enum tagLogicFlag
 * @brief  ���Ӳ�ѯ����Լ���е��߼���ϵ����
 * @attention ��
 */
typedef enum tagLogicFlag
{
    EQUAL_FLAG      = 0,    /**< ���� */
    GREAT_FLAG      = 1,    /**< ���� */
    LITTLE_FLAG     = 2,    /**< С�� */
    GEQUAL_FLAG     = 3,    /**< ���ڵ��� */
    LEQUAL_FLAG     = 4,    /**< С�ڵ��� */
    LIKE_FLAG       = 5,    /**< ģ����ѯ */
    ASCEND_FLAG     = 6,    /**< ���� */
    DESCEND_FLAG    = 7,    /**< ���� */
    NEQUAL_FLAG     = 8,    /**< ������ */
    NLIKE_FLAG      = 13,   /**< NOT LIKE */
	IN_SELECT_FLAG  = 14,   /**< IN SELECT��� */
    IN_FLAG         = 99,   /**<   */
    LOGIC_FLAG_MAX          /**< ��Чֵ */
}LOGIC_FLAG_E;


/**
 * @enum tagQueryType
 * @brief  ��ѯ������
 * @attention 300~500 ��Ѷʹ��
 */
typedef enum tagQueryType
{
    CODE_TYPE       = 0,    /**< ��������(���û�����֮��) */
    NAME_TYPE       = 1,    /**< ��������(���û�����֮��) */
    USER_CODE_TYPE  = 2,    /**< �û��������� */
    USER_NAME_TYPE  = 3,    /**< �û��������� */
    TIME_TYPE       = 4,    /**< ʱ������ */

    EVENT_TYPE      = 5,    /**< �澯�¼�����,ȡֵΪ#AlARM_TYPE_E */
    EVENT_SECURITY  = 6,    /**< �澯�¼�����,ȡֵΪ#ALARM_SEVERITY_LEVEL_E */
    EVENT_STATUS_TYPE = 7,  /**< �澯״̬,ȡֵΪ#ALARM_STATUS_E */
    EVENT_TIME      = 8,    /**< �澯ʱ�� */

    DEV_SUB_TYPE    = 9,    /**< �豸������ */

    INDEX_TYPE      = 10,   /**< ��������(����Ƶ����ͨ������,��Ƶ���ͨ������,��������,����������) */

    RES_SUB_TYPE    = 11,   /**< ��Դ������ */

    /* Begin: Add by x06948 for VVD38087, 20100115 */
    SRV_TYPE            = 12,       /**< ҵ������ */
    MONITOR_TYPE        = 13,       /**< ���������� */
    MONITOR_NAME        = 14,       /**< ���������� */
    MONITOR_DOMAIN      = 15,       /**< ������������ */
    CAMERA_NAME         = 16,       /**< ��������� */
    USER_LOGIN_IP       = 17,       /**< �û���¼IP */
    MON_SRV_STATUS      = 18,       /**< ʵ��״̬ */
    VOCBRD_SRV_STATUS   = 19,       /**< �㲥״̬ */
    /* End: Add by x06948 for VVD38087, 20100115 */
    //RES_TYPE            = 20,       /**< ��Դ���� */

    CASE_DESC               = 20,       /**< �������� */
    TASK_STATUS             = 21,       /**< ����״̬ */
    TASK_SUB_TIME           = 22,       /**< �����ύʱ�� */
    TASK_END_TIME           = 23,       /**< �������ʱ�� */
    BAK_START_TIME          = 24,       /**< ���ݿ�ʼʱ�� */
    BAK_END_TIME            = 25,       /**< ���ݽ���ʱ�� */
    FILE_CREATE_TIME        = 26,       /**< �ļ�����ʱ�� */
    FILE_CAPACITY           = 27,       /**< �ļ����� */
    FILE_TYPE               = 28,       /**< �ļ����� */
    FILE_LOCK_FLAG          = 29,       /**< �ļ�������ʶ */
    LAYOUT_TYPE             = 30,       /**< �������ͣ�ȡֵΪ#LAYOUT_TYPE_E */

    PHY_DEV_IP              = 31,

    ASSET_TYPE              = 32,       /**< �ʲ����ͣ�ȡֵΪ#ASSET_TYPE_E */
    ASSET_MODEL             = 33,       /**< �ʲ��ͺ� */
    ASSET_MANUFACTURE       = 34,       /**< �ʲ����� */
    ASSET_STATUS            = 35,       /**< �ʲ�״̬��ȡֵΪ#ASSET_STATUS_E */
    ASSET_PURCHASE_TIME     = 36,       /**< �ʲ��ɹ�ʱ�� */
    ASSET_WARRANT_TIME      = 37,       /**< �ʲ�����ʱ�� */
    ASSET_INSTALL_TIME      = 38,       /**< �ʲ���װʱ�� */
    ASSET_INSTALL_LOCATION  = 39,       /**< �ʲ���װ�ص� */
    ASSET_PRODEALER         = 40,       /**< �ʲ������� */
    FAULT_STAT_TIME         = 41,       /**< ����ͳ��ʱ�� */
    FAULT_TYPE              = 42,       /**< �������� */
    FAULT_RECO_TIME         = 43,       /**< ���ϻָ�ʱ�� */
    FAULT_INTERVAL          = 44,       /**< ����ʱ�� */
    FAULT_COUNT             = 45,       /**< ���ϴ��� */

    PLATE_CODE              = 46,       /**< ���ƺ��� */
    STUFF_TYPE              = 47,       /**< �永��Ʒ���� */
    STUFF_PROPERTY          = 48,       /**< �永��Ʒ���� */
    SERIESCASE_TYPE         = 49,       /**< ���������� */
    CASEINSE_CODE           = 50,       /**< �������а������ */
    CASESHARE_TYPE          = 51,       /**< ������������ */
    CASE_PROPERTY           = 52,       /**< �������� */
    CASE_TYPE               = 53,       /**< �������� */
    CASE_STATUS             = 54,       /**< ����״̬ */
    POLICE_INTSRC           = 55,       /**< ����������Դ */
    CASE_BEGIN_TIME         = 56,       /**< ������ʼʱ�� */
    CASE_END_TIME           = 57,       /**< ��������ʱ�� */
    STAT_START_TIME         = 58,       /**< ͳ�ƿ�ʼʱ�� */
    STAT_END_TIME           = 59,       /**< ͳ�ƽ���ʱ�� */
    EBULLETIN_EXPIRE_FLAG   = 60,       /**< ���ӹ�����ڱ�־ */
    CASE_DATA_TYPE          = 61,       /**< ������������ */
    CASE_SOLVED_TIME        = 63,       /**< �����ư�ʱ�� */
    CASE_CLOSED_TIME        = 64,       /**< �����᰸ʱ�� */
    CASE_UPLOAD_TIME        = 65,       /**< ���������ϴ�ʱ�� */
    CASE_CREATE_TIME        = 66,       /**< ��������ʱ�� */
    DEPT_CODE               = 67,       /**< ���ű��� */
    ACTION_TYPE             = 68,       /**< ��������,ȡֵΪ#ACTION_TYPE_E */

    DOMAIN_TYPE = 100,       /**< ������,��ֻ֧�ֱ����� */

	/* Begin: Added by luchunfeng02289, 2015-12-08 for �澯���� */
	EVENT_CLASS             = 101,      /**< �澯�¼����ͷ��࣬ȡֵΪ#ALARM_CLASS_E */
	/* End: Added by luchunfeng02289, 2015-12-08 for �澯���� */

    EXT_DOMAIN_TPYE         = 200,      /**< ��������:��/��/ƽ���� */
    EXT_DOMAIN_IP           = 201,      /**< ����IP */
    EXT_DOMAIN_PORT         = 202,      /**< ����PORT */
    EXT_DOMAIN_TRUNK_NUM    = 203,      /**< ����������� */
    EXT_DOMAIN_MULTICAST    = 204,      /**< ����鲥���� */
    EXT_DOMAIN_SESSION      = 205,      /**< ����������־ */
    EXT_DOMAIN_SUBTYPE      = 206,      /**< ���������� */

    JOB_STATUS          = 210,          /**< ��������״̬ */
    JOB_CREATOR         = 211,          /**< �������񴴽��� */
    JOB_EXEC_TIME       = 212,          /**< �����������ʱ�� */
    JOB_ESTB_TIME       = 213,          /**< ���������ƶ�ʱ�� */
    JOB_END_TIME        = 214,          /**< �����������ʱ�� */
    JOB_RESULT          = 215,          /**< ������� */

    OPER_TIME               = 220,      /**< ����ʱ�� */
    OPER_IP                 = 221,      /**< ������IP��ַ */
    OPER_TYPE               = 222,      /**< �������� */
    OPER_RESULT             = 223,      /**< ������� */
    OPER_SERVICE_TYPE       = 224,      /**< ������ҵ������ */
    OPER_OBJ                = 225,      /**< �������� */

    LABEL_TIME          = 230,          /**< ��ǩʱ��� */
    REC_START_TIME      = 231,          /**< ��ǩ¼��ʼʱ�䣬��ʽΪ"hh:mm:ss" */
    REC_END_TIME        = 232,          /**< ��ǩ¼�����ʱ�䣬��ʽΪ"hh:mm:ss" */

    USER_FULL_NAME          = 240,      /**< �û�ȫ�� */
    USER_TEL_PHONE          = 241,      /**< �û������绰 */
    USER_MOBILE_PHONE       = 242,      /**< �û��ƶ��绰 */
    USER_EMAIL              = 243,      /**< �û������ʼ� */
    USER_IS_LOCKED          = 244,      /**< �û��Ƿ����� */

    USER_DESC               = 245,      /**< �û����� */

    ROLE_PRIORITY       =250,           /**< ��ɫ���ȼ� */

    DEV_TYPE            = 255,          /**< �豸���� */
    RES_TYPE            = 256,          /**< ��Դ���� */
    IS_QUERY_SUB        = 257,          /**< �Ƿ���¼�(��Ҫ��AS_CON_Parse���н���) */
    RES_ID              = 258,          /**< ��ԴID */
    SUPPORT_LINK        = 259,          /**< �Ƿ�֧������ */
    SUPPORT_GUARD       = 260,          /**< �Ƿ�֧�ֲ��� */
    RES_ATTRIBUTE       = 261,          /**< ��Դ���� */
    IS_QUERY_ENCODESET  = 262,          /**< �Ƿ��ѯ��������߼����������豸�����ײͣ���ӦszQueryDataΪ0-����ѯ��1-��ѯ */

    TYPE_ACTION_PLAN    = 263,          /**< Ԥ������ */
    IS_PLAN_ALARM       = 264,          /**< �Ƿ�Ԥ���澯 */
    IS_ONCE_PLAN_ALARM  = 265,          /**< �Ƿ�������Ԥ�� */
    IS_MISINFORM        = 266,          /**< �Ƿ��� */
    CHK_USER_NAME_TYPE  = 267,          /**< �˾��û��� */
    TRIGGER_ID          = 268,          /**< ������ID */

    IS_HIDE_EMPTY_ORG   = 269,          /**< �Ƿ����ؿ���֯ */
    IS_QUERY_SHARED     = 270,          /**< �ǲ�ѯ�ѹ�����Դ=1���ǲ�δ������Դ=0 */

    IS_LEACH_SHARED_BELONG  = 271,      /**< �Ƿ���˵���Ϊ��Դ��������������Դ�������ɵĻ����¼(��Ҫ��AS_CON_Parse���н���) */
    RESULT_CODE             = 272,      /**< ����� */
    RES_ORDER_NUMBER        = 273,      /**< ��Դ������� */

    AUTOID                  = 273,      /**< ���� */

    EVENT_TYPE_NAME         = 273,      /**< �¼��������� */

    IS_QUERY_SYSTEM_EVENT_TYPE = 274,   /**< 0-��ѯȫ��;1-��ѯϵͳԤ����;2-��ѯ�û��Զ��� */

    IS_SUPPORT_BISTORE_CAM     = 275,   /**< �Ƿ�����֧��˫ֱ�������������������� */

    RES_STATUS_CONDITON     = 276,      /**< ��Դ״̬��ѯ���� */
    DM_CODE                 = 277,      /**< DM���� */      /* Add by zhouquanwei/z01364 for �ֲ�ʽPAG����SDK�ӿ� */

    /* Begin: Modifid by luhaitao/01337, 2016-03-29 for ��̶���� */
    IS_HIDE_BKP_LINK_DEV    = 278,      /**< �Ƿ����α���·�ظ��ڵ���Դ */
    /* End: Modifid by luhaitao/01337, 2016-03-29 for ��̶���� */

    CONF_START_TIME         = 300,      /**< ���鿪ʼʱ�䣬1970������������ */
    CONF_END_TIME           = 301,      /**< �������ʱ�䣬1970������������ */

    STORE_DEV_NAME       = 302,          /**< �洢�豸���� */
    DM_NAME                   = 303,          /**< ���ݹ������������ */
    RES_BELONGIN         = 304,          /**< ��Դ����,0����ԭʼ����#MM_RESOURCE_BELONGIN_ORIGINAL��1���������#MM_RESOURCE_BELONGIN_TRANSFER */
    IS_CASE_SERVER          = 310,      /**< �Ƿ񰸼����ݹ�������� */
    BAK_SERVICE_TYPE        = 311,      /**< ����ҵ������ */
    BAK_RES_SERVICE_TYPE    = 312,      /**< ������Դҵ������ */
    DOMAIN_CODE                 = 350,      /**< ����� */
    TOLLGATE_CODE               = 351,      /**< ���ڱ�� */
    TOLLGATE_NAME               = 352,      /**< �������� */
    TOLLGATE_CAMERA_CODE        = 353,      /**< ����������� */
    LANE_NUMBER                 = 354,      /**< ������� */
    LANE_DIRECTION              = 355,      /**< ���������� */
    PASS_TIME                   = 356,      /**< ͨ��ʱ�� */
    VEHICLE_LICENSE_PLATE       = 357,      /**< ���ƺ��� */
    VEHICLE_LICENSE_PLATE_TYPE  = 358,      /**< �������� */
    VEHICLE_LICENSE_PLATE_COLOR = 359,      /**< ������ɫ */
    SPEED_TYPE                  = 360,      /**< �ٶ� */
    LIMIT_SPEED                 = 361,      /**< ���� */
    VEHICLE_LOGO                = 362,      /**< ����Ʒ�� */
    VEHICLE_TYPE                = 363,      /**< �������� */
    VEHICLE_COLOR_DEPTH         = 364,      /**< ������ɫ��ǳ */
    VEHICLE_COLOR               = 365,      /**< ������ɫ */
    VEHICLE_IDENTIFY_STATUS     = 366,      /**< ʶ��״̬ */
    VEHICLE_STATUS              = 367,      /**< ��ʻ״̬ */
    VEHICLE_DEAL_STATUS         = 368,      /**< ���������� */
    DISPOSITION_CODE            = 369,      /**< ���ر�� */
    DISPOSITION_TYPE            = 370,      /**< ������� */
    DISPOSITION_DEPT            = 371,      /**< ���ص�λ */
    DISPOSITION_USER            = 372,      /**< ������Ա */
    DISPOSITION_STATUS          = 373,      /**< ����״̬ */
    DISPOSITION_UNDO_DEPT       = 374,      /**< ���ص�λ */
    DISPOSITION_UNDO_USER       = 375,      /**< ������Ա */
    PRIORITY_TYPE               = 376,      /**< ���ȼ� */
    ALARM_TYPE                  = 377,      /**< �澯���� */
    PLATE_ANALYSE_STATUS        = 378,      /**< ���Ʒ���״̬ */
    SECTION_CODE                = 379,      /**< ���������� */
    SECTION_NAME                = 380,      /**< ������������ */
    TOLLGATE_CODE_IN            = 381,      /**< ʻ�뿨�� */
    TOLLGATE_CODE_OUT           = 382,      /**< ʻ������ */
    VEHICLE_DATA_TYPE           = 383,      /**< ������������ */
    PASS_TIME2                  = 384,      /**< ͨ��ʱ��2 */
    DISPOSITION_RESULT          = 385,      /**< ���ش����� */
    EXT_DOMAIN_PROTOCOL_TYPE    = 386,      /**< ���ͨѶЭ������ */
    DISTANCE_RANGE              = 387,      /**< ���뷶Χ */
    DEFAULT_WEBGIS_MAP          = 388,      /**< Ĭ��WebGis��ͼ */
    DEFAULT_WEBGIS_POINT        = 389,      /**< Ĭ��WebGis��ͼ��ע�� */
    STAT_TIME                   = 390,      /**< ͳ��ʱ�� */

    PLACE_CODE                  = 501,      /**< Υ�µص���� */
    EQUIPMENT_TYPE              = 502,      /**< �ɼ����� */
    ABNORMAL_ANALYSE_STATUS     = 503,      /**< �쳣��Ϊ����״̬ */
    COUNT_TYPE                  = 504,      /**< ���� */
    RESTRICT_TYPE               = 505,      /**< ���з�ʽ */
    VEHICLE_DATA_CODE           = 506,      /**< ������Ϣ��� */
    COMBINE_FLAG                = 507,      /**< ͼƬ�ϳɱ�ʶ */

    PROTOCOL_ID                 = 508,      /**< Э������ */
    PROTOCOL_DESC               = 509,      /**< Э������ */
    IS_SUPPORT                  = 510,      /**< �Ƿ�֧�ָ�Э�� */
    IS_DEFAULT_SG               = 511,      /**< �Ƿ�Ĭ��SG֧�ֵ�Э��*/
    SG_CODE                     = 512,      /**< SG����*/

    /* Begin: Added by luhaitao/01337, 2015-06-15 for ONVIF��NVR */
    PARENT_CODE_TYPE            = 513,      /**< ���豸�������� */
    /* End: Added by luhaitao/01337, 2015-06-15 for ONVIF��NVR */

    /*Begin add by l01420, 2014-7-31 for MPPD14821*/
    LOG_DESC                    = 515,      /**< ��־����*/
    /*End add by l01420, 2014-7-31 for MPPD14821*/

	/* Begin Add By hexiaojun/hW0959 for �������̨�����Ƿ񾭹���̨������ 2015-2-10 */
	IS_PASS_PTZ                 = 516,      /**< ��̨�������̨�����Ƿ񾭹���̨������ */
    /* End Add By hexiaojun/hW0959 for �������̨�����Ƿ񾭹���̨������ 2015-2-10 */
	VEHICLE_LINE                = 517,      /**< ��ϵ */
    VEHICLE_YEAR                = 518,      /**< ����������� */
    VEHICLE_BRAND               = 519,      /**< ���� */

    TVWALL_CODE                 = 520,      /**< ����ǽ���� */
    TVWALL_SCENE_ID             = 521,      /**< ����ǽ����ID */
    TVWALL_ORG_CODE             = 522,      /**< ��֯����� */
    /*add by y02360 bugid = 29678 */
    TOLLGATE_INOUTCITY          = 523,      /**< ���ڽ����� */
    /* Begin: Added by zhouquanwei/z01364, 2015-05-11 for CDS �������� */
    BM_CODE                     = 560,      /**< BM���� */
    DEV_ONLINE_STATE            = 561,      /**< �豸����״̬ */
    GROUP_ID                    = 562,      /**< ����ID */
    ACCOUNT_ID                  = 563,      /**< �˻�ID*/
    /* End: Added by zhouquanwei/z01364, 2015-05-11 for CDS �������� */

    /* Begin added by liangchao, 2015-11-04 for MPPD30081  ����CDV���Ʋ���*/
    CDV_NAME                  = 564,      /**< CDV����*/
    CDV_CODE                  = 565,      /**< CDV����*/
    CDV_ID                    = 567,      /**< CDV ID*/
    CDV_ADDR                  = 568,      /**< CDV��ַ*/
    /* End added by liangchao, 2015-11-04 for MPPD30081  ����CDV���Ʋ���*/

    /*Added by yaozhongmin02844,2015-12-08,�����壬��ȫ����������绰*/
    VEHICLE_MODEL                                    = 569,         /**<����> */
    DRIVER_SUN_VISOR_STATUS           = 570,       /**<����ʻ������> */
    CODRIVER_SUN_VISOR_STATUS         = 571,       /**<����ʻ������>*/
    DRIVER_SEAT_BELT_STATUS            = 572,       /**<����ʻ��ȫ��>*/
    CODRIVER_SEAT_BELT_STATUS      = 573,       /**<����ʻ��ȫ��>*/
    DRIVER_MOBIL_STATUS                         = 574,       /**<������绰>*/

    /*End Added by yaozhongmin02844,2015-12-08,�����壬��ȫ����������绰*/

    IDENTIFY_INFO                = 579,   /**<�����Ϣ>*/
    /*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
    DEVICE_CODE                                      = 580,    /**<�豸����(rfid����)>*/
    MAC_ADDR                                            = 581,   /**<MAC��ַ>*/
    DISPOSITION_MACRFID_TYPE         = 582,    /**<MAC&RFID��������>*/
    DISPOSITION_MACRFID_STATUS    = 583,    /**<MAC&RFID����״̬>*/
    MAC_DISPOSE_REASON                    = 584,    /**<MAC����ԭ��>*/
    RFID_DISPOSE_REASON                    = 585,    /**<RFID����ԭ��>*/
    /*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

    START_TIME                             = 586,             /**< ��ʼʱ�� */
    END_TIME                               = 587,            /**< ����ʱ�� */
    /* Begin: Added by lW2822, 2016-11-10 for MPPD39454��ͨ�û���DC28ϵ�е���ǽʧ�� */
    IS_CHECK_AUTHORITY        = 588,              /**< �Ƿ��Ȩ��0������Ȩ��1�����Ȩ */
    ADD_TIME                  = 589,               /**< ��ӵ�ʱ�� */
    /* End: Added by lW2822, 2016-11-10 for MPPD39454��ͨ�û���DC28ϵ�е���ǽʧ�� */

    /* Begin added by wupeixin/03329, 2017-2-6 for fullCoverOptimization */
    CDV_TYPE                  = 590,      /**< CDV����*/
    POOL_NAME                 = 591,      /**< ���������*/
    POOL_PURPOSE              = 592,      /**< �������;*/
    POOL_CODE                 = 593,      /**< ����ر���*/
    POOL_STAT                 = 594,      /**< �����״̬*/
    /* End added by wupeixin/03329, 2017-2-6 for fullCoverOptimization */
    /* Added by wupeixin/03329, 2017-3-16 for MPPD46031 */
    POOL_SPARE_CAP            = 595,      /**< �����ʣ������*/

    /*Begin: Added by hesongchang/02908, 2017-07-06 for ������MACҵ��֧�ֳ�������ȫ������������*/
    /*---------------����---------------*/
    MAC_PLACE_CODE                  = 600,
    MAC_PLACE_NAME                  = 601,
    MAC_BOSS_NAME                   = 602,
    MAC_PLACE_FULL_NAME                   = 603,

    /*---------------��ȫ����---------------*/
    MAC_MANU_NAME                   = 604,
    MAC_MANU_ORG_CODE               = 605,
    MAC_CONTACT_PEOPLE              = 606,
    /*End: Added by hesongchang/02908, 2017-07-06 for ������MACҵ��֧�ֳ�������ȫ������������*/

    /* Begin: Added by l03769, 2017-07-26 for MPPD49572 �������豸��γ���ϱ��ͳ���IPC�������� */
    QUERY_IOT_TYPE            = 607,               /** = 1 ֻ���������豸������DAE�ͳ���IPC
                                                       = 2 ֻ���������豸���͵���Դ */
    /* End: Added by l03769, 2017-07-26 for MPPD49572 �������豸��γ���ϱ��ͳ���IPC�������� */

	/*Begin added by w4028 2017-11-06 for ���θ��¼��ֶ�MPPD53407*/
    QUERY_DANGEROUS_GOODS           = 608,
    QUERY_YELLOW_CAR                = 609,
    QEURY_ANNUAL_SURVEY             = 610,
    QUERY_PENDENT                   = 611,
	/*End added by w4028 2017-11-06 for ���θ��¼��ֶ�MPPD53407*/
   /* Begin: Add by zW4385, 2017-12-28 for MPPD54417 ģ����ѯȥ�� */
    IS_DISTINCT                =612,              /**<  �Ƿ�ȥ�� */
    /* End: Add by zW4385, 2017-12-28 for MPPD54417 ģ����ѯȥ�� */

    QUERY_TYPE_MAX          /**< ��Чֵ */
}QUERY_TYPE_E;

/**
 * @enum tagIMOSFavoriteStream
 * @brief  �����ò�������
 * @attention ��
 */
typedef enum tagIMOSFavoriteStream
{
    IMOS_FAVORITE_STREAM_ANY        = 0,        /**< ��ָ�� */
    IMOS_FAVORITE_STREAM_PRIMARY    = 1,        /**< ָ������ */
    IMOS_FAVORITE_STREAM_SECONDERY  = 2,        /**< ָ������ */
    IMOS_FAVORITE_STREAM_THIRD      = 3,        /**< ָ������ */
    IMOS_FAVORITE_STREAM_FOURTH     = 4,        /**< ָ������ */
    IMOS_FAVORITE_STREAM_FIFTH      = 5,        /**< ָ������ */
    IMOS_FAVORITE_STREAM_BI_AUDIO   = 6,        /**< ָ�������Խ� */
    IMOS_FAVORITE_STREAM_VOICE_BR   = 7,        /**< ָ�������㲥 */
    IMOS_FAVORITE_STREAM_BUTT,
    IMOS_FAVORITE_STREAM_INVALID    = 0xFFFF    /**< ��Чֵ */
}IMOS_FAVORITE_STREAM_E;


/**
 * @enum  tagSubscribePushType
 * @brief �������͵�����
 * @attention ��
 */
typedef enum tagSubscribePushType
{
    SUBSCRIBE_PUSH_TYPE_ALL          = 0,   /**< ���ܸ澯���ͺ��豸״̬���� */
    SUBSCRIBE_PUSH_TYPE_ALARM        = 1,   /**< ֻ���ո澯���� */
    SUBSCRIBE_PUSH_TYPE_ALARM_STATUS = 2,   /**< ֻ�����豸״̬���� */

    SUBSCRIBE_PUSH_TYPE_MAX,
    SUBSCRIBE_PUSH_TYPE_INVALID = 0xFFFFFFFF
}SUBSCRIBE_PUSH_TYPE_E;

/**
 * @enum  tagCSOperateCode
 * @brief ���з������ԭ����
 * @attention ��
 */
typedef enum tagCSOperateCode
{
    USER_OPERATE_SERVICE = 0,                               /**< �û������������ */

/*****************��������������Ķ�������(��ʼ)*******************/

    SWITCH_OPERATE              = 1,    /**< ���в��� */
    PLAN_SWITCH_OPERATE         = 2,    /**< �ƻ����в��� */
    SERVICE_REAVE               = 3,    /**< ҵ����ռ */
    ALARM_LINKAGE_START_SERVICE = 4,    /**< �澯���� */
    EXT_DOMAIN_OPER_SERVICE     = 5,    /**< ��������� */

    EC_ONLINE                   = 6,    /**< EC���� */
    EC_OFFLINE                  = 7,    /**< EC���� */
    EC_DELETE                   = 8,    /**< ECɾ�� */
    CAMERA_ONLINE               = 9,    /**< ��������� */
    CAMERA_OFFLINE              = 10,   /**< ��������� */

    DC_ONLINE                   = 11,   /**< DC���� */
    DC_OFFLINE                  = 12,   /**< DC���� */
    DC_DELETE                   = 13,   /**< DCɾ�� */

    MS_ONLINE                   = 14,   /**< MS���� */
    MS_OFFLINE                  = 15,   /**< MS���� */
    MS_OFFLINE_TRANSFER         = 16,   /**< MS���������ת�� */
    MS_DELETE_TRANSFER          = 17,   /**< MSɾ�������ת�� */
    MS_DELETE                   = 18,   /**< MSɾ�� */

    VX500_ONLINE                = 19,   /**< VX500���� */
    VX500_OFFLINE               = 20,   /**< VX500���� */
    VX500_DELETE                = 21,   /**< VX500ɾ�� */

    ISC_ONLINE                  = 22,   /**< ISC3000-E���� */
    ISC_OFFLINE                 = 23,   /**< ISC3000-E���� */

    EX_DOMAIN_JUNIOR_ONLINE     = 24,   /**< �¼������� */
    EX_DOMAIN_SUPERIOR_ONLINE   = 25,   /**< �ϼ������� */
    EX_DOMAIN_JUNIOR_OFFLINE    = 26,   /**< �¼������� */
    EX_DOMAIN_SUPERIOR_OFFLINE  = 27,   /**< �ϼ������� */
    EXT_DOMAIN_DELETE           = 28,   /**< ����ɾ�� */

    EXT_DOM_CANCEL_SHR_CAM      = 29,   /**< ����ȡ����������������� */
    LOC_DOM_CANCEL_SHR_CAM      = 30,   /**< ����ȡ����������������� */

    CAMERA_DELETE               = 31,   /**< CAMERAɾ�� */
    MONITOR_DELETE              = 32,   /**< MONITORɾ�� */

    SWITCH_RES_MDF              = 33,   /**< ������Դ�޸� */
    SWITCH_RES_DEL              = 34,   /**< ������Դɾ�� */
    SWITCH_PLAN_DEL             = 35,   /**< ���мƻ�ɾ�� */
    SWITCH_PLAN_MODIFY          = 36,   /**< ���мƻ��޸� */

    XP_ONLINE                   = 37,   /**< XP���� */
    XP_OFFLINE                  = 38,   /**< XP���� */
    USER_KEEPALIVE_FAIL         = 39,   /**< �û�����ʧ�� */
    USER_DELETE                 = 40,   /**< �û���ɾ�� */
    USER_QUIT                   = 41,   /**< �û��˳� */
    USER_KICKED_OUT             = 42,   /**< �û���ǿ������ */

    SYSMANGER_OPERATE_SERVICE   = 43,   /**< ����Ա���� */
    PTZ_LINK_TIMER_OUT          = 44,   /**< ��̨���ӳ�ʱ */
    PTZ_FIRST_LINK              = 45,   /**< ��̨�״����� */
    PTZ_LOW_AUTHORITY           = 46,   /**< ��̨����Ȩ�޵� */
    PTZ_NO_AUTHORITY            = 47,   /**< ����̨����Ȩ�� */
    PTZ_HAS_LOCKED              = 48,   /**< ��̨������ */

    DEV_MEDIA_PARAM_CHANGE      = 49,   /**< �豸ý������޸� */

    SALVO_OPERATE               = 50,   /**< ����ʾ���� */

    SALVO_RES_DEL               = 51,   /**< ����ʾɾ�� */
    SALVO_RES_MDF               = 52,   /**< ����ʾ�޸� */

    GROUPSWITCH_RES_DEL         = 53,   /**< ����Ѳ��Դɾ�� */
    GROUPSWITCH_RES_MDF         = 54,   /**< ����Ѳ��Դ�޸� */

    GROUPSWITCH_PLAN_DEL        = 55,   /**< ����Ѳ�ƻ�ɾ�� */
    GROUPSWITCH_PLAN_MODIFY     = 56,   /**< ����Ѳ�ƻ��޸� */

    GROUPSALVO_OPERATE          = 57,   /**< ����Ѳ���� */
    GROUPSALVO_STOP             = 58,   /**< ����Ѳֹͣ */
    GROUPSALVO_PLAN_OPERATE     = 59,   /**< ����Ѳ�ƻ����� */

    INTERNAL_ERR_OPERATE        = 60,   /**< �ڲ������������ */

    PTZ_CCB_FULL                = 61,   /**< ���ƿ����� */

    MONITOR_SPLIT_SCREEN_DELETE = 62,   /**< ����������ɾ�� */
    MONITOR_SPLIT_SCREEN_SWITCH = 63, /**< �����������л� */

    ALARM_LINKAGE_RESUME_SERVICE = 64,  /**< �澯�����ָ� */
    MONITOR_SPLIT_SCREEN_SWITCH_STOP = 65, /**< �����������л������"ֹͣҵ��"���� */
    MONITOR_SPLIT_SCREEN_SWITCH_START = 66, /**< �����������л������"����ҵ��"���� */
    MONITOR_SPLIT_SCREEN_SWITCH_START_FULL = 67, /**< �����������л������"����ҵ��"���� - ����ȫ�� */
    MONITOR_SPLIT_SCREEN_SWITCH_START_EXIT = 68, /**< �����������л������"����ҵ��"���� - �˳�ȫ�� */

    CALLEE_USER_OPERATE_SERVICE = 70,   /**< �����û�������� */
    SYSTEM_OPERATE_SERVICE      = 71,   /**< ϵͳ������� */
    CALLEE_NOT_SUPPORT_SERVICE  = 72,   /**< ���в�֧�ִ�ҵ����� */

    EXDOMAIN_CRUISE_PATH_DELETE  = 73,   /**< ����Ѳ��·��ɾ�� */

    TS_OFFLINE                   = 74,   /**< TS���� */
    TS_OFFLINE_TRANSFER          = 75,   /**< TS���������ת�� */
    TS_DELETE_TRANSFER           = 76,   /**< TSɾ�������ת�� */
    TS_DELETE                    = 77,   /**< TSɾ�� */
    TS_ONLINE                    = 78,   /**< TS���� */
    VOD_OFFLINEORDELETE          = 79,   /**< VOD���������߻�ɾ�� */
	/* Begin Added by dengshuhua00673, 2012-11-27 of �Զ�������Ѳ */
	AUTOSALVO_OPERATE            = 80,   /**< �Զ���������Ѳ���� */
	AUTOSALVO_STOP               = 81,   /**< �Զ���������Ѳֹͣ */
	AUTOSWITCH_RES_MDF           = 82,   /**< �Զ���������Ѳ��Դ�޸� */
	AUTOSWITCH_RES_DEL           = 83,   /**< �Զ���������Ѳ��Դɾ�� */
	/* End Added by dengshuhua00673, 2012-11-27 of �Զ�������Ѳ */

    DC_CONFIGURE_DC_INST         = 84,   /**< ����DCƴ�ӡ�ģ���������Ϣ */

    /* Begin: added by zkf0134, 2013.11.23 for �����л�֧������������Ӧ*/
    MONITOR_SWITCH_SPLIT_SCREEN_START = 85,   /**< �����������л������"����ҵ�����"*/
    /* End: added by zkf0134, 2013.11.23 for �����л�֧������������Ӧ*/

	PLAN_GUARD_OPERATE   =  86,/**<�ƻ����ز���*/
    LS_OFFLINE                   = 87,   /**< LS���� */
    LS_OFFLINE_TRANSFER          = 88,   /**< LS���������ת�� */
    LS_DELETE_TRANSFER           = 89,   /**<LSɾ�������ת�� */
    LS_DELETE                    = 90,   /**< LSɾ�� */
    LS_ONLINE                    = 91,   /**< LS���� */

    VOD_ONLINE                   = 92,   /**< VOD���� */
    VOD_OFFLINE                  = 93,   /**< VOD���� */
    VOD_OFFLINE_TRANSFER         = 94,   /**< VOD���������ת�� */
    VOD_DELETE_TRANSFER          = 95,   /**< VODɾ�������ת�� */
    VOD_DELETE                   = 96,   /**<VODɾ�� */

    TS_RULE_CHANGE               = 97,   /**< TS����ı� */
	/* Begin: added by y01359, 2015-01-28 for A8 */
	A8_ONLINE                    = 98,  /**< A8���� */
	A8_OFFLINE                   = 99,  /**< A8���� */
	A8_DELETE                    = 100,  /**< A8ɾ�� */
	A8_WINDOW_DELETE             = 101,  /**< A8����ɾ�� */
	/* End: added by y01359, 2015-01-28 for A8 */

	STREAM_REBUILD               = 102, /**<VM��⵽�쳣�������ؽ��� */

	/* Begin: added by y01359, 2016-05-13 for A8 */
    A8_SCENE_SERVICE             = 103,  /**< A8�������� */
    A8_WINDOW_SPLIT              = 104,  /**< A8���ڷ��� */
	/* End: added by y01359, 2015-01-28 for A8 */

    /* Begin add by zhuzhicong/02302/����������, 2017-07-03 for MPPD48388 XWARE����ƽ̨ */
    XWARE_ONLINE                 = 105,    /**< XWARE���� */
    XWARE_OFFLINE                = 106,    /**< XWARE���� */
    XWARE_DELETE                 = 107,    /**< XWAREɾ�� */
    /* End add by zhuzhicong/02302/����������, 2017-07-03 for MPPD48388 XWARE����ƽ̨ */

    /* Begin add by f03368, 2017-06-17 for �¹�������������豸 */
    AUDIO_OUTPUT_ONLINE       = 108,      /**< ����������� */
    AUDIO_OUTPUT_OFFLINE      = 109,      /**< ����������� */
    AUDIO_OUTPUT_DELETE        = 110,     /**< �������ɾ�� */
    EXT_DOM_CANCEL_SHR_AUDIO_OUTPUT      = 111,   /**< ����ȡ������������������� */
    LOC_DOM_CANCEL_SHR_AUDIO_OUTPUT      = 112,   /**< ����ȡ������������������� */
    /* End add by f03368, 2017-06-17 for �¹�������������豸 */
    /* Begin: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */
    AUTOPOLL_OPERATE             = 113,   /** A8ƴ���Զ�������Ѳ����*/
    /* End: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */

    /* Begin: Added by liucanming 03903, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */
    GROUPPOLL_RES_DEL            = 114,   /**< A8����Ѳ��Դɾ�� */
    GROUPPOLL_RES_MDF            = 115,   /**< A8����Ѳ��Դ�޸� */
    AUTOPOLL_RES_MDF             = 116,   /**< A8�Զ�������Ѳ��Դ�޸� */
    AUTOPOLL_RES_DEL             = 117,   /**< A8�Զ�������Ѳ��Դɾ�� */
    /* End: Added by liucanming 03903, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */

/*****************��������������Ķ�������(����)*******************/

    CS_OPERATE_CODE_MAX,
    CS_OPERATE_CODE_INVALID = 0xFF
}CS_OPERATE_CODE_E;

/**
 * @enum  tagCSSwitchAdjustAction
 * @brief ���з����ֶ���������
 * @attention ��
 */
typedef enum tagCSSwitchAdjustAction
{
    SWTICH_PAUSE    = 0,    /**< ������ͣ */
    SWITCH_CONTINUE = 1,    /**< ���лָ� */
    SWITCH_FORWARD  = 2,    /**< ������ǰ���� */
    SWITCH_BACKWARD = 3,    /**< ���������� */

    SWITCH_ADJUST_ACTION_MAX,                   /**< ���ֵ */
    SWITCH_ADJUST_ACTION_INVALID = 0xFF         /**< ��Чֵ */
}CS_SWITCH_ADJUST_ACTION_E;



/**
 * @enum tagTCProtocolType
 * @brief  ͸��ͨ�����ݴ���Э������ö��
 * @attention 1.ֻ֧��UDPЭ������,�ݲ�֧��TCP��SIPЭ������
 */
typedef enum tagTCProtocolType
{
    UDP_PROTOCOL    = 1,    /**< Э������ΪUDP */

    TCP_PROTOCOL    = 2,    /**< Э������ΪTCP(�ݲ�֧��) */
    SIP_PROTOCOL    = 3,    /**< Э������ΪSIP(�ݲ�֧��) */

    PROTOCOL_TYPE_INVALID = 0xFFFFFFFF /**< ��Чֵ */
}TC_PROTOCOL_TYPE_E;

/**
* @enum tagGisMapParamType
* @brief ��ͼ��������ö��
* @attention
*/
typedef enum tagGisMapParamType
{
    GIS_MAP_PAPAM_HOTZONE   = 0,    /**< ���� */
    GIS_MAP_PAPAM_HOTPOT   = 1,     /**< �ȵ� */
    GIS_MAP_PAPAM_CAMICON = 2,      /**< �����ͼ�� */
    GIS_MAP_PAPAM_ALMSRCICON = 3,   /**< �澯Դͼ�� */
    GIS_MAP_PAPAM_TOLLGATE = 4,     /**< ����ͼ�� */

    GIS_MAP_PAPAM_MAX,
    GIS_MAP_PAPAM_INVALID = 0xFF
}GIS_MAP_PAPAM_TYPE_E;


/*******************************************************************************
SS��������
*******************************************************************************/

/**
 * @enum tagDeviceOnlineStatus
 * @brief �豸����״̬
 * @attention
 */
typedef enum tagDeviceOnlineStatus
{
    IMOS_EN_DEVICE_STATUS_INVALID   = 0,    /**< �豸��Ч״̬*/
    IMOS_EN_DEVICE_STATUS_ONLINE    = 1,    /**< �豸����, ��IMOS_DEV_STATUS_ONLINEȡֵһ��*/
    IMOS_EN_DEVICE_STATUS_OFFLINE   = 2,    /**< �豸����, ��IMOS_DEV_STATUS_OFFLINEȡֵһ��*/

    IMOS_EN_DEVICE_STATUS_MAX               /**< �豸״̬, ���ֵ*/
}DEV_ONLINE_STATUS_E;

/**
 * @enum tagDeviceOperateType
 * @brief �豸��������
 * @attention
 */
typedef enum tagDeviceOperateType
{
    OPERATE_DEVICE_ADD  = 0,    /**< �豸���� */
    OPERATE_DEVICE_MOD  = 1,    /**< �豸�޸� */
    OPERATE_DEVICE_DEL  = 2     /**< �豸ɾ�� */
}DEVICE_OPERATE_TYPE_E;

/**
* @enum tagHD_NaaTypeEx
* @brief NAA����
* @attention ��
*/
typedef  enum  tagHD_NaaTypeEx
{
    IMOS_EN_NAA_TYPE_AUTO = 0,                                     /**< �Զ� */
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
 * @brief ���ͼ����������
 * @attention
 */
typedef  enum tagMC_MonitorEx
{
    IMOS_EN_MONITOR1_VIDEO  = 0,    /**< ��ص����� */
    IMOS_EN_MONITOR4_VIDEO  = 1,    /**< ���4���� */
    IMOS_EN_MONITOR9_VIDEO  = 2,    /**< ���9���� */
    IMOS_EN_MONITOR_VIDEO_COUNT
} MC_MONITOR_EX_E;

/**
 * @enum tagMC_ConfStatusEx
 * @brief ����״̬
 */
typedef  enum tagMC_ConfStatusEx
{
    IMOS_EN_CONF_STATUS_NOT_BEGIN   = 0,    /**< ����ԤԼ�ɹ���û�п�ʼ */
    IMOS_EN_CONF_STATUS_CALLING     = 1,    /**< �����ټ��� */
    IMOS_EN_CONF_STATUS_LIVING      = 2,    /**< �ٿ��� */
    IMOS_EN_CONF_STATUS_DROPPING    = 3,    /**< �ڽ�ɢ�� */
    IMOS_EN_CONF_STATUS_ENDED       = 4,    /**< �����Ѿ����� */
    IMOS_EN_CONF_UNREGED            = 5,    /**< ������ע�� */
    IMOS_EN_CONF_REGED              = 6,    /**< ������ע�� */
    IMOS_EN_CONF_STATUS_CREATE_FAIL = 1000, /**< ���鴴��ʧ�� */
    IMOS_EN_CONF_STATUS_CALL_IN     = 1001, /**< �����ٿ����һ���ͨ���� */
    IMOS_EN_CONF_STATUS_DELETED     = 1002, /**< ����ɾ�� */

    IMOS_EN_CONF_STATUS_INVALID = 0xFFFF
} MC_CONF_STATUS_EX_E;

/* Begin: added by o06299 for �������� of 2010.04.13 */
/**
* @enum tagConfMcuCascTypeEx
* @brief ����MCU��������
* @attention
*/
typedef  enum tagConfMcuCascTypeEx
{
    IMOS_EN_CONF_MCU_TYPE_MASTER     = 0,  /**< �򵥼�����MCU */
    IMOS_EN_CONF_MCU_TYPE_SECONDARY  = 1,  /**< �򵥴�MCU */
    IMOS_EN_CONF_MCU_TYPE_NO_CASCADE = 2,  /**< �Ǽ���MCU */
    IMOS_EN_CONF_MCU_TYPE_COUNT
}CONF_MCU_CASCADE_TYPE_E;
/* END: added by o06299 for �������� of 2010.04.13 */

/**
 * @enum tagMC_BroadcastedObserveEx
 * @brief ���㲥�᳡�Ĺۿ��᳡����
 * @attention
 */
typedef  enum tagMC_BroadcastedObserveEx
{
    IMOS_EN_OBSERVE_MYSELF  = 0,    /**< �Լ� */
    IMOS_EN_OBSERVE_LASTER  = 1,    /**< �ϴι㲥�᳡ */
    IMOS_EN_OBSERVE_MAIN    = 2,    /**< ���᳡ */
    IMOS_EN_OBSERVE_COUNT
} MC_BROADCASTED_OBSERVE_EX_E;

/**
 * @enum tagMC_SingleShowModeEx
 * @brief ��������ʾģʽ
 * @attention
 */
typedef  enum tagMC_SingleShowModeEx
{
    IMOS_EN_SHOW_SET_SITE        = 0,   /**< ��ʾָ���᳡ */
    IMOS_EN_SHOW_CHAIR           = 1,   /**< ��ʾ������ϯ */
    IMOS_EN_SHOW_SPEAKER         = 2,   /**< ��ʾ������ */
    IMOS_EN_SHOW_VOICE_ACTIVATED = 3,   /**< �������� */
    IMOS_EN_SHOW_COUNT
} MC_SINGLE_SHOW_MODE_EX_E;

/**
 * @enum tagHD_ColorGroupTypeEx
 * @brief 16����ɫ��
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
 * @brief Diffserv���
 * @attention
 */
typedef  enum  tagHD_DiffServTypeEx
{
    IMOS_EN_EXPEDITED_FORWARDING = 0xB8,              /**< ����ת������ */
    IMOS_EN_ASSURED_FORWARDING_4_1 = 0x88,            /**< ȷ��ת������41 */
    IMOS_EN_ASSURED_FORWARDING_4_2 = 0x90,            /**< ȷ��ת������42 */
    IMOS_EN_ASSURED_FORWARDING_4_3 = 0x98,            /**< ȷ��ת������43 */
    IMOS_EN_CLASS_BEST_EFFORD = 0                     /**< �������� */
} HD_DIFFSERV_TYPE_EX_E;

/**
 * @enum tagMC_ChairLookModeEx
 * @brief ��������Ҫ���ӵ��л��㲥����ʱ��ϯ�ۿ�ģʽ
 * @attention
 */
typedef enum tagMC_ChairLookModeEx
{
    IMOS_EN_CHAIR_LOOK_NOCHG    = 0,    /**< [����] Ĭ�� */
    IMOS_EN_CHAIR_LOOK_BROAD    = 1,    /**< [����㲥�л�] */
    IMOS_EN_CHAIR_LOOK_CLOSE    = 2,    /**< �ر� */
    IMOS_EN_CHAIR_LOOK_COUNT
} MC_CHAIR_LOOK_MODE_EX_E;

/**
 * @enum tagMC_MultiPicCycModeEx
 * @brief �໭����Ѳ��Ҫ���õ�����ģʽ
 * @attention
 */
typedef  enum  tagMC_MultiPicCycModeEx
{
    IMOS_EN_MULTI_CYC_SAME_LIST = 0,    /**< �໭����Ѳʹ��ͬһ����Ѳ�б� */
    IMOS_EN_MULTI_CYC_SEP_LIST  = 1,    /**< �໭����Ѳʹ�ø��Ե���Ѳ�б� */
    IMOS_EN_MULTI_CYC_COUNT
} MC_MULTIPIC_CYC_MODE_EX_E;

/**
 * @enum tagMC_SelectLookEx
 * @brief �᳡ѡ��ۿ�ö��
 * @attention
 */
typedef  enum  tagMC_SelectLookEx
{
    IMOS_EN_SEL_LOOK_NO     = 0,    /**< ������ѡ��ۿ� */
    IMOS_EN_SEL_LOOK_YES    = 1,    /**< ����ѡ��ۿ� */
    IMOS_EN_SEL_LOOK_COUNT
} MC_SELECT_LOOK_EX_E;

/**
 * @enum tagMC_AheadEndConfEx
 * @brief ��ǰ��������֪ͨ��ö��
 * @attention
 */
typedef  enum  tagMC_AheadEndConfEx
{
    IMOS_EN_AHEAD_END_CONF_NO     = 0,                /**< ����ǰ�������� */
    IMOS_EN_AHEAD_END_CONF_THREE  = 180,              /**< ��ǰ�����ӽ������� */
    IMOS_EN_AHEAD_END_CONF_FIVE   = 300,              /**< ��ǰ����ӽ������� */
    IMOS_EN_AHEAD_END_CONF_TEN    = 600,              /**< ��ǰʮ���ӽ������� */
    IMOS_EN_AHEAD_END_CONF_TWENTY = 1200,             /**< ��ǰ��ʮ���ӽ������� */
    IMOS_EN_AHEAD_END_CONF_THIRTY = 1800,             /**< ��ǰ��ʮ���ӽ������� */
    IMOS_EN_AHEAD_END_CONF_COUNT,
} MC_AHEAD_END_CONF_EX_E;

/**
 * @enum tagMC_ConfCycleTypeEx
 * @brief �����ظ���ʽ
 * @attention
 */
typedef  enum tagMC_ConfCycleTypeEx
{
    IMOS_EN_CONF_NOT_CYCLE              = 0,    /**< �����ڻ���[��һ��] */
    IMOS_EN_CONF_CYCLE_TYPE_EVERY_MONTH = 1,    /**< ���� */
    IMOS_EN_CONF_CYCLE_TYPE_EVERY_WEEK  = 2,    /**< ���� */
    IMOS_EN_CONF_CYCLE_TYPE_EVERY_DAY   = 3,    /**< ���� */
    IMOS_EN_CONF_CYCLE_TYPE_COUNT
} MC_CONF_CYCLE_TYPE_EX_E;

/**
 * @enum tagMC_ConfCycleEndTypeEx
 * @brief ���ڻ����������
 * @attention
 */
typedef  enum tagMC_ConfCycleEndTypeEx
{
    IMOS_EN_CONF_CYCLE_END_COUNT = 0,   /**< �ظ����� */
    IMOS_EN_CONF_CYCLE_END_DATE  = 1,   /**< ��ֹ���� */
    IMOS_EN_CONF_CYCLE_END_TYPE_COUNT
} MC_CONF_CYCLE_END_TYPE_EX_E;

/**
 * @enum tagConfReportSampleType
 * @brief ���������������
 * @attention
 */
typedef  enum tagConfReportSampleType
{
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_HOUR    = 0,    /**< ��Сʱ */
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_DAY     = 1,    /**< ���� */
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_MONTH   = 2,    /**< ���� */
    IMOS_EN_CONF_REPORT_SAMPLE_TYPE_COUNT
} CONF_REPORT_SAMPLE_TYPE_E;

/**
 * @enum tagMC_ConfCascadeTypeEx
 * @brief ���鼶��ģʽ
 * @attention
 */
typedef  enum tagMC_ConfCascadeTypeEx
{
    IMOS_EN_CONF_CASCADE_TYPE_NO    = 0,    /**< �Ǽ��� */
    IMOS_EN_CONF_CASCADE_TYPE_YES   = 1,    /**< ���� */
    IMOS_EN_CONF_CASCADE_TYPE_COUNT
} MC_CONF_CASCADE_TYPE_EX_E;

/**
 * @enum tagMC_ConfCascadeRelationEx
 * @brief ���鼶����ϵ,����Ӽ�������ʱָ��
 * @attention
 */
typedef  enum tagMC_ConfCascadeRelationEx
{
    IMOS_EN_CONF_CASCADE_RELATION_SUP    = 0,   /**< �ϼ����� */
    IMOS_EN_CONF_CASCADE_RELATION_SUB    = 1,   /**< �¼����� */
    IMOS_EN_CONF_CASCADE_RELATION_SIMPLE = 2,   /**< �򵥼��� */
    IMOS_EN_CONF_CASCADE_RELATION_COUNT
} MC_CONF_CASCADE_RELATION_EX_E;



/**
 * @enum tagHD_ColorTable16TypeEx
 * @brief 16ɫ��ɫ������ɫ����
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
 * @brief ���λ��
 * @attention
 */
typedef  enum  tagHD_BannerPosEx
{
    IMOS_EN_BANNER_POS_TOPQTR   = 0,    /**< ���λ��ռ��Ļ�Ϸ�1/4 */
    IMOS_EN_BANNER_POS_TOP3RD   = 1,    /**< ���λ��ռ��Ļ�Ϸ�1/3 */
    IMOS_EN_BANNER_POS_TOP5     = 2,    /**< ���λ��ռ��Ļ�Ϸ�1/5 */
    IMOS_EN_BANNER_POS_TOP6TH   = 3,    /**< ���λ��ռ��Ļ�Ϸ�1/6 */
    IMOS_EN_BANNER_POS_TOP7     = 4,    /**< ���λ��ռ��Ļ�Ϸ�1/7 */
    IMOS_EN_BANNER_POS_TOP8TH   = 5,    /**< ���λ��ռ��Ļ�Ϸ�1/8 */
} HD_BANNER_POS_EX_E;

/**
 * @enum tagHD_ConfShowTimerTypeEx
 * @brief ��ʾ����ʱ�������,�����Ѿ���ʼʱ�䡢��������ʣ��ʱ��
 * @attention
 */
typedef  enum tagHD_ConfShowTimerTypeEx
{
    IMOS_EN_SHOW_TIMER_TYPE_NO      = 0,    /**< ����ʾ����ʱ�� */
    IMOS_EN_SHOW_TIMER_TYPE_BEGIN   = 1,    /**< ����ʣ��ʱ�� */
    IMOS_EN_SHOW_TIMER_TYPE_END     = 2,    /**< �������ʱ�� */
    IMOS_EN_SHOW_TIMER_TYPE_COUNT
} HD_CONF_SHOW_TIMER_TYPE_EX_E;



/**
 * @enum tagMC_ProtocolTypeEx
 * @brief MCU����֧�ֵ�Э������
 * @attention
 */
typedef  enum tagMC_ProtocolTypeEx
{
    IMOS_EN_PROTOCOL_H323   = 0,    /**< H323Э�� */
    IMOS_EN_PROTOCOL_SIP    = 1,    /**< SIPЭ�� */
    IMOS_EN_PROTOCOL_MIX    = 2,    /**< ��Э��[˫Э��] */
    IMOS_EN_PROTOCOL_COUNT
} MC_PROTOCOL_TYPE_EX_E;

/**
 * @enum tagMC_ConfModeEx
 * @brief ����ģʽ
 * @attention
 */
typedef  enum tagMC_ConfModeEx
{
    IMOS_EN_CONF_MODE_DIRECTOR       = 0,   /**< ����ģʽ */
    IMOS_EN_CONF_MODE_CHAIR          = 1,   /**< ��ϯģʽ */
    IMOS_EN_CONF_MODE_VOICE_ACTUATOR = 2,   /**< ��������ģʽ */
    IMOS_EN_CONF_MODE_COUNT
} MC_CONF_MODE_EX_E;

/**
 * @enum tagHD_MultiPicNumEx
 * @brief �����������
 * @attention
 */
typedef  enum  tagHD_MultiPicNumEx
{
    IMOS_EN_MULTI_PIC_0 = 0,                 /**< ��ת�������� */
    IMOS_EN_MULTI_PIC_1 = 1,                 /**< ������ */
    IMOS_EN_MULTI_PIC_2 = 2,                 /**< 2���� */
    IMOS_EN_MULTI_PIC_3 = 3,                 /**< 3���� */
    IMOS_EN_MULTI_PIC_4 = 4,                 /**< 4���� */
    IMOS_EN_MULTI_PIC_5 = 5,                 /**< 5���� */
    IMOS_EN_MULTI_PIC_6 = 6,                 /**< 6���� */
    IMOS_EN_MULTI_PIC_7 = 7,                 /**< 7���� */
    IMOS_EN_MULTI_PIC_8 = 8,                 /**< 8���� */
    IMOS_EN_MULTI_PIC_9 = 9,                 /**< 9���� */
    IMOS_EN_MULTI_PIC_10 = 10,               /**< 10���� */
    IMOS_EN_MULTI_PIC_11 = 11,               /**< 11���� */
    IMOS_EN_MULTI_PIC_12 = 12,               /**< 12���� */
    IMOS_EN_MULTI_PIC_13 = 13,               /**< 13���� */
    IMOS_EN_MULTI_PIC_14 = 14,               /**< 14���� */
    IMOS_EN_MULTI_PIC_15 = 15,               /**< 15���� */
    IMOS_EN_MULTI_PIC_16 = 16,               /**< 16���� */
    IMOS_EN_MULTI_PIC_17 = 17,               /**< 17���� */
    IMOS_EN_MULTI_PIC_18 = 18,               /**< 18���� */
    IMOS_EN_MULTI_PIC_19 = 19,               /**< 19���� */
    IMOS_EN_MULTI_PIC_20 = 20,               /**< 20���� */
    IMOS_EN_MULTI_PIC_21 = 21,               /**< 21���� */
    IMOS_EN_MULTI_PIC_22 = 22,               /**< 22���� */
    IMOS_EN_MULTI_PIC_23 = 23,               /**< 23���� */
    IMOS_EN_MULTI_PIC_24 = 24,               /**< 24���� */
    IMOS_EN_MULTI_PIC_25 = 25,               /**< 25���� */
    IMOS_EN_MULTI_PIC_26 = 26,               /**< 26���� */
    IMOS_EN_MULTI_PIC_27 = 27,               /**< 27���� */
    IMOS_EN_MULTI_PIC_28 = 28,               /**< 28���� */
    IMOS_EN_MULTI_PIC_29 = 29,               /**< 29���� */
    IMOS_EN_MULTI_PIC_30 = 30,               /**< 30���� */
    IMOS_EN_MULTI_PIC_31 = 31,               /**< 31���� */
    IMOS_EN_MULTI_PIC_32 = 32,               /**< 32���� */
    IMOS_EN_MULTI_PIC_33 = 33,               /**< 33���� */
    IMOS_EN_MULTI_PIC_34 = 34,               /**< 34���� */
    IMOS_EN_MULTI_PIC_35 = 35,               /**< 35���� */
    IMOS_EN_MULTI_PIC_36 = 36,               /**< 36���� */
    IMOS_EN_MULTI_PIC_NUM_COUNT
} HD_MULTI_PIC_NUM_EX_E;

/**
 * @enum tagMC_MultiPicObserveEx
 * @brief �໭��ʱ�ۿ�������
 * @attention
 */
typedef  enum tagMC_MultiPicObserveEx
{
    IMOS_EN_MULTI_PIC_OBSERVE_BROAD_CAST = 0,   /**< �㲥�໭�� */
    IMOS_EN_MULTI_PIC_OBSERVE_CHAIR      = 1,   /**< ��ϯ�ۿ��໭�� */
    IMOS_EN_MULTI_PIC_OBSERVE_COUNT
} MC_MULTI_PIC_OBSERVE_EX_E;

/**
 * @enum tagMC_DropReinviteModeEx
 * @brief ����������ʽ
 * @attention
 */
typedef  enum tagMC_DropReinviteModeEx
{
    IMOS_DROP_REINVITE_MODE_ALWAYS  = 0,    /**< ������������ [����] */
    IMOS_DROP_REINVITE_MODE_AUTO    = 1,    /**< �����Զ����� [�Զ���20��] */
    IMOS_DROP_REINVITE_MODE_CLOSE   = 2,    /**< �ر��������� [�ر�] */
    IMOS_DROP_REINVITE_MODE_COUNT
} MC_DROP_REINVITE_MODE_EX_E;

/**
 * @enum tagHD_FrameThickTypeEx
 * @brief �߿��ϸ����
 * @attention
 */
typedef  enum  tagHD_FrameThickTypeEx
{
    IMOS_EN_FRAME_THICK     = 0,    /**< �ֱ߿� */
    IMOS_EN_FRAME_MIDDLE    = 1,    /**< �����߿� */
    IMOS_EN_FRAME_THIN      = 2,    /**< ϸ�߿� */
    IMOS_EN_FRAME_COUNT
} HD_FRAME_THICK_TYPE_EX_E;

/**
 * @enum tagMC_CycleTableIndexEx
 * @brief ��Ѳ������
 * @attention
 */
typedef enum tagMC_CycleTableIndexEx
{
    IMOS_EN_CYCLE_TABLE_INDEX_0 = 0,        /**< ȫ���᳡�� */
    IMOS_EN_CYCLE_TABLE_INDEX_1 = 1,        /**< ��Ѳ��1 */
    IMOS_EN_CYCLE_TABLE_INDEX_2 = 2,        /**< ��Ѳ��2 */
    IMOS_EN_CYCLE_TABLE_INDEX_3 = 3,        /**< ��Ѳ��3 */
    IMOS_EN_CYCLE_TABLE_INDEX_4 = 4,        /**< ��Ѳ��4 */
    IMOS_EN_CYCLE_TABLE_INDEX_5 = 5,        /**< ��Ѳ��5 */
    IMOS_EN_CYCLE_TABLE_INDEX_6 = 6,        /**< ��Ѳ��6 */
    IMOS_EN_CYCLE_TABLE_INDEX_7 = 7,        /**< ��Ѳ��7 */
    IMOS_EN_CYCLE_TABLE_INDEX_8 = 8,        /**< ��Ѳ��8 */
    IMOS_EN_CYCLE_TABLE_INDEX_9 = 9,        /**< ��Ѳ��9 */
    IMOS_EN_CYCLE_TABLE_INDEX_COUNT
} MC_CYCLE_TABLE_INDEX_EX_E;

/**
 * @enum tagHD_ColorTable4TypeEx
 * @brief 4ɫ��ɫ������ɫ����
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
 * @brief ������Ļλ��
 * @attention
 */
typedef  enum tagHD_TitlePosEx
{
    IMOS_EN_TITLE_POS_BOTTOM      = 0,      /**< ��Ļ����Ļ�·�1 */
    IMOS_EN_TITLE_POS_TOP         = 1,      /**< ��Ļ����Ļ�Ϸ�1 */
    IMOS_EN_TITLE_POS_LEFT        = 2,      /**< ��Ļ����Ļ���1 */
    IMOS_EN_TITLE_POS_RIGHT       = 3,      /**< ��Ļ����Ļ�Ҳ�1 */
    IMOS_EN_TITLE_POS_FULL_SCREEN = 4,      /**< ��Ļ��ȫ����ʾ[ȫ��] */
    IMOS_EN_TITLE_POS_COUNT
} HD_TITLE_POS_EX_E;

/**
 * @enum tagHD_TitleRollSpeedEx
 * @brief ������Ļ�����ٶ�
 * @attention
 */
typedef  enum tagHD_TitleRollSpeedEx
{
    IMOS_EN_TITLE_ROLL_MID          = 0,    /**< ��Ļ��������[����] */
    IMOS_EN_TITLE_ROLL_LOW          = 1,    /**< ��Ļ��������[����] */
    IMOS_EN_TITLE_ROLL_FAST         = 2,    /**< ��Ļ��������[����] */
    IMOS_EN_TITLE_ROLL_QUIESCENCE   = 3,    /**< ��Ļ��ֹ[��ֹ] */
    IMOS_EN_TITLE_ROLL_SPEED_COUNT
} HD_TITLE_ROLL_SPEED_EX_E;

/**
 * @enum tagHD_TitleRollEndTypeEx
 * @brief ��Ļ����������ʽ
 * @attention
 */
typedef  enum tagHD_TitleRollEndTypeEx
{
    IMOS_EN_TITLE_ROLL_END_COUNT    = 0,    /**< ��Ļ�������� */
    IMOS_EN_TITLE_ROLL_END_TIME     = 1,    /**< ��Ļ����ʱ�� */
    IMOS_EN_TITLE_ROLL_END_TYPE_COUNT
} HD_TITLE_ROLL_END_TYPE_EX_E;

/**
 * @enum tagHD_TitleRollDirectionEx
 * @brief ������Ļ��������
 * @attention
 */
typedef  enum tagHD_TitleRollDirectionEx
{
    IMOS_EN_ROLL_FROM_RIGHT_TO_LEFT = 0,    /**< ��Ļ���ҵ������[���ҵ���] */
    IMOS_EN_ROLL_FROM_BUTTOM_TO_TOP = 1,    /**< ��Ļ���µ��Ϲ���[���µ���] */
    IMOS_EN_TITLE_ROLL_DIRECTION_COUNT
} HD_TITLE_ROLL_DIRECTION_EX_E;

/**
 * @enum tagHD_TitleLastTimeEx
 * @brief ������Ļ����ʱ��
 * @attention
 */
typedef  enum tagHD_TitleLastTimeEx
{
    IMOS_EN_TITLE_LAST_TIME_FOREVER = 0,       /**< ��Ļ����ʱ������[����] */
    IMOS_EN_TITLE_LAST_TIME_5MIN  = 5,         /**< ��Ļ����5����[5����] */
    IMOS_EN_TITLE_LAST_TIME_10MIN = 10,        /**< ��Ļ����10����[10����] */
    IMOS_EN_TITLE_LAST_TIME_15MIN = 15,        /**< ��Ļ����15����[15����] */
    IMOS_EN_TITLE_LAST_TIME_30MIN = 30,        /**< ��Ļ����30����[30����] */
    IMOS_EN_TITLE_LAST_TIME_45MIN = 45,        /**< ��Ļ����45����[45����] */
    IMOS_EN_TITLE_LAST_TIME_60MIN = 60,        /**< ��Ļ����60����[60����] */
    IMOS_EN_TITLE_LAST_TIME_120MIN = 120,      /**< ��Ļ����120����[120����] */
    IMOS_EN_TITLE_LAST_TIME_COUNT
} HD_TITLE_LAST_TIME_EX_E;

/**
 * @enum tagHD_MultiPicModeEx
 * @brief ����ģʽ
 * @attention
 */
typedef  enum  tagHD_MultiPicModeEx
{
    IMOS_EN_SINGLE_MODE =0,     /**< ������ */

    IMOS_EN_MULTI_PIC2_MODE     = 1,    /**< 2���� */
    IMOS_EN_MULTI_PIC3_MODE1    = 2,    /**< 3����1  */
    IMOS_EN_MULTI_PIC3_MODE2    = 3,    /**< 3����2  */
    IMOS_EN_MULTI_PIC4_MODE     = 4,    /**< 4����  */

    IMOS_EN_MULTI_PIC5P1_MODE   = 5,    /**< 5+1����  */
    IMOS_EN_MULTI_PIC9_MODE     = 6,    /**< 9����  */

    IMOS_EN_MULTI_PIC3P1_MODE   = 7,    /**< 3+1���� */
    IMOS_EN_MULTI_PIC4P2_MODE1  = 8,    /**< 4+2����1 */
    IMOS_EN_MULTI_PIC12_MODE    = 9,    /**< 12���� */
    IMOS_EN_MULTI_PIC4P2_MODE2  = 10,   /**< 4+2����2 */
    IMOS_EN_MULTI_PIC7P1_MODE   = 11,   /**< 7+1���� */
    IMOS_EN_MULTI_PIC12P1_MODE1 = 12,   /**< 12+1����1 */
    IMOS_EN_MULTI_PIC8P2_MODE1  = 13,   /**< 8+2����1 */
    IMOS_EN_MULTI_PIC16_MODE    = 14,   /**< 16���� */
    IMOS_EN_MULTI_PIC8P2_MODE2  = 15,   /**< 8+2����2 */
    IMOS_EN_MULTI_PIC8P2_MODE3  = 16,   /**< 8+2����3 */
    IMOS_EN_MULTI_PIC8P2_MODE4  = 17,   /**< 8+2����4 */
    IMOS_EN_MULTI_PIC8P2_MODE5  = 18,   /**< 8+2����8 */
    IMOS_EN_MULTI_PIC12P1_MODE2 = 19,   /**< 12+1����2 */
    IMOS_EN_MULTI_PIC12P1_MODE3 = 20,   /**< 12+1����3 */
    IMOS_EN_MULTI_PIC12P1_MODE4 = 21,   /**< 12+1����4 */
    IMOS_EN_MULTI_PIC12P1_MODE5 = 22,   /**< 12+1����5 */
    IMOS_EN_MULTI_PIC8P2_MODE6  = 23,   /**< 8+2����6 */
    IMOS_EN_MULTI_PIC3P4_MODE1  = 24,   /**< 3+4����1 */
    IMOS_EN_MULTI_PIC3P4_MODE2  = 25,   /**< 3+4����2 */
    IMOS_EN_MULTI_PIC3P4_MODE3  = 26,   /**< 3+4����3 */
    IMOS_EN_MULTI_PIC3P4_MODE4  = 27,   /**< 3+4����4 */

    IMOS_EN_MULTI_PIC11P1_MODE  = 28,   /**< 11+1���� */
    IMOS_EN_MULTI_PIC20P1_MODE1 = 29,   /**< 20+1����1 */
    IMOS_EN_MULTI_PIC20P1_MODE2 = 30,   /**< 20+1����2 */
    IMOS_EN_MULTI_PIC24P3_MODE1 = 31,   /**< 24+3����1 */
    IMOS_EN_MULTI_PIC24P3_MODE3 = 32,   /**< 24+3����3 */
    IMOS_EN_MULTI_PIC6P12_MODE3 = 33,   /**< 6+12����3 */
    IMOS_EN_MULTI_PIC6P12_MODE5 = 34,   /**< 6+12����5 */
    IMOS_EN_MULTI_PIC27P1_MODE1 = 35,   /**< 27+1����1 */
    IMOS_EN_MULTI_PIC9P3_MODE4  = 36,   /**< 9+3����4 */
    IMOS_EN_MULTI_PIC18P2_MODE1 = 37,   /**< 18+2����1 */
    IMOS_EN_MULTI_PIC18P2_MODE4 = 38,   /**< 18+2����4 */
    IMOS_EN_MULTI_PIC18P2_MODE6 = 39,   /**< 18+2����6 */
    IMOS_EN_MULTI_PIC36_MODE    = 40,   /**< 36���� */

    IMOS_EN_MULTI_PICE_COUNT
} HD_MULTIPIC_MODE_EX_E;



/**
 * @enum tagHD_VideoProtFmtEx
 * @brief ��Ƶ��Э���ʽ����
 * @attention
 */
typedef  enum  tagHD_VideoProtFmtEx
{
    IMOS_EN_VID_H264_1080P  = 0,   /**<  H264Э�� 1080P��ʽ */
    IMOS_EN_VID_H264_720P   = 1,   /**<  H264Э�� 720P��ʽ */
    IMOS_EN_VID_H264_4CIF   = 2,   /**<  H264Э�� 4CIF��ʽ */
    IMOS_EN_VID_H264_CIF    = 3,   /**<  H264Э�� CIF��ʽ */
    IMOS_EN_VID_H263_1080P  = 4,   /**<  H263Э�� 1080P��ʽ */
    IMOS_EN_VID_H263_720P   = 5,   /**<  H263Э�� 720P��ʽ */
    IMOS_EN_VID_H263_4CIF   = 6,   /**<  H263Э�� 4CIF��ʽ */
    IMOS_EN_VID_H263_CIF    = 7,   /**<  H263Э�� CIF��ʽ */
    IMOS_EN_VID_PROT_FMT_COUNT
} HD_VIDEO_PROT_FMT_EX_E;


/**
 * @enum tagMC_CycleTimeIntervalEx
 * @brief ��Ѳʱ����
 * @attention
 */
typedef  enum tagMC_CycleTimeIntervalEx
{
    IMOS_EN_CYCLE_TIME_INTERVAL_15SEC = 15,                   /**< 15�� */
    IMOS_EN_CYCLE_TIME_INTERVAL_30SEC = 30,                   /**< 30�� */
    IMOS_EN_CYCLE_TIME_INTERVAL_45SEC = 45,                   /**< 45�� */
    IMOS_EN_CYCLE_TIME_INTERVAL_1MIN  = 60,                   /**< 1���� */
    IMOS_EN_CYCLE_TIME_INTERVAL_2MIN  = 120,                  /**< 2���� */
    IMOS_EN_CYCLE_TIME_INTERVAL_5MIN  = 300,                  /**< 5���� */
    IMOS_EN_CYCLE_TIME_INTERVAL_10MIN = 600,                  /**< 10���� */
    IMOS_EN_CYCLE_TIME_INTERVAL_15MIN = 900,                  /**< 15���� */
    IMOS_EN_CYCLE_TIME_INTERVAL_30MIN = 1800,                 /**< 30���� */
    IMOS_EN_CYCLE_TIME_INTERVAL_COUNT
} MC_CYCLE_TIME_INTERVAL_EX_E;


/**
 * @enum tagMC_MultiPicOnePicEx
 * @brief �໭����С��������
 * @attention
 */
typedef  enum tagMC_MultiPicOnePicEx
{
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_AUTO_FILL        = 0,    /**< �Զ���� */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_CHAIR            = 1,    /**< ������ϯ */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_SPEAKER          = 2,    /**< ������ */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_SET_SITE         = 3,    /**< ָ���᳡ */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_CYCLE            = 4,    /**< �᳡��Ѳ */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_VOICE_ACTUATOR   = 5,    /**< �������� */
    IMOS_EN_CONF_MULTI_PIC_ONE_PIC_COUNT
} MC_MULTI_PIC_ONE_PIC_EX_E;

/**
 * @enum tagHD_VideoProtEx
 * @brief ��Ƶ��Э������
 * @attention
 */
typedef  enum  tagHD_VideoProtEx
{
    IMOS_EN_VID_PROT_H261   = 0,    /**< H261Э�� */
    IMOS_EN_VID_PROT_H263   = 1,    /**< H263Э�� */
    IMOS_EN_VID_PROT_H263P  = 2,    /**< H263+Э�� */
    IMOS_EN_VID_PROT_H264   = 3,    /**< H264Э�� */
    IMOS_EN_VID_PROT_MPEG4  = 4,    /**< MPEG4Э�� */
    IMOS_EN_VID_PROT_AUTO   = 5,    /**< �Զ� */
    IMOS_EN_VID_PROT_COUNT
} HD_VIDEO_PROT_EX_E;

/**
 * @enum tagHD_AudioProtEx
 * @brief ��ƵЭ������
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
    IMOS_EN_AUD_PROT_AUTO                   = 18,   /**< �Զ� */
    IMOS_EN_AUD_PROT_COUNT
} HD_AUDIO_PROT_EX_E;

/**
 * @enum tagHD_VideoFormatEx
 * @brief �����С
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
    IMOS_EN_VIDEO_FMT_AUTO      = 11,   /**< �Զ� */
    IMOS_EN_VIDEO_FMT_NONSTD    = 12,   /**< �Ǳ��ʽ*/
    IMOS_EN_VIDEO_FMT_COUNT

} HD_VIDEO_FORMAT_EX_E;

/**
 * @enum tagHD_FrameRateEx
 * @brief ֡��
 * @attention
 */
typedef  enum  tagHD_FrameRateEx
{
    IMOS_EN_FRAME_RATE_AUTO = 0,                                   /**< �Զ� */
    IMOS_EN_FRAME_RATE_3F = 3,                                     /**< 3֡ */
    IMOS_EN_FRAME_RATE_5F = 5,                                     /**< 5֡ */
    IMOS_EN_FRAME_RATE_10F = 10,                                   /**< 10֡ */
    IMOS_EN_FRAME_RATE_15F = 15,                                   /**< 15֡ */
    IMOS_EN_FRAME_RATE_25F = 25,                                   /**< 25֡ */
    IMOS_EN_FRAME_RATE_30F = 30,                                   /**< 30֡ */
    IMOS_EN_FRAME_RATE_COUNT
} HD_FRAME_RATE_EX_E;

/**
 * @enum tagMC_ConfMixRateEx
 * @brief �����������
 * @attention
 */
typedef  enum tagMC_ConfMixRateEx
{
    IMOS_EN_MIX_RATE_NO     = 0,    /**< ��֧�ֻ��� */
    IMOS_EN_MIX_RATE_PART   = 1,    /**< ���ֻ��� */
    IMOS_EN_MIX_RATE_ALL    = 2,    /**< ȫ���� */
    IMOS_EN_MIX_RATE_CHOICE = 3,    /**< ѡ����� */
    IMOS_EN_MIX_RATE_COUNT
} MC_CONF_MIXRATE_EX_E;

/**
 * @enum tagHD_RateAndFrameAdaptModeEx
 * @brief ���ʣ�֡���������ȵ�ö��
 * @attention
 */
typedef  enum  tagHD_RateAndFrameAdaptModeEx
{
    IMOS_EN_RATE_FRAME_NO           = 0,    /**< ���������� */
    IMOS_EN_RATE_FRAME_FALL         = 1,    /**< ���� */
    IMOS_EN_RATE_FRAME_RATE_FIRST   = 2,    /**< ������������ */
    IMOS_EN_RATE_FRAME_FRAME_FIRST  = 3,    /**< ֡���������� */
    IMOS_EN_RATE_FRAME_COUNT
} HD_RATE_AND_FRAME_ADAPT_MODE_EX_E;

/**
 * @enum tagMC_AdaptCountEx
 * @brief ����·��ö��
 * @attention
 */
typedef  enum  tagMC_AdaptCountEx
{
    IMOS_EN_ADAPT_COUNT_1 = 1,            /**< ����1· */
    IMOS_EN_ADAPT_COUNT_2 = 2,            /**< ����2· */
    IMOS_EN_ADAPT_COUNT_3 = 3,            /**< ����3· */
    IMOS_EN_ADAPT_COUNT_COUNT
} MC_ADAPT_COUNT_EX_E;


/**
 * @enum tagMC_ConfTypeEx
 * @brief ���鴴��ʱ��������
 * @attention
 */
typedef  enum tagMC_ConfTypeEx
{
    IMOS_EN_CONF_TYPE_ONLY_AUDIO    = 0,    /**< ����Ƶ���� */
    IMOS_EN_CONF_TYPE_AUDIVISION    = 1,    /**< ����Ƶ���� */
    IMOS_EN_CONF_TYPE_ANNEX_VIDEO   = 2,    /**< ˫����Ƶ���� */
    IMOS_EN_CONF_TYPE_COUNT
} MC_CONF_TYPE_EX_E;


/**
 * @enum tagHD_RoleVideoTypeEx
 * @brief ��������
 * @attention
 */
typedef  enum    tagHD_RoleVideoTypeEx
{
     IMOS_EN_HD_ROLE_LIVE           = 1,    /**< ����ģʽ */
     IMOS_EN_HD_ROLE_TOKEN          = 2,    /**< ����ģʽ */
     IMOS_EN_HD_ROLE_LIVE_TOKEN     = 3,    /**< ͬʱ֧�����ɺ�����ģʽ */
     IMOS_EN_HD_ROLE_NO_STANDARD    = 4,    /**< �Ǳ�ģʽ */
     IMOS_EN_HD_ROLE_COUNT                                        /**< ���� */
} HD_ROLE_VIDEO_TYPE_EX_E;

/**
 * @enum tagMC_MediaEncryptEx
 * @brief ý���������
 * @attention
 */
typedef enum tagMC_MediaEncryptEx
{
    IMOS_EN_MEDIA_ENCRYPT_NO    = 0,    /**< ��֧��ý����� */
    IMOS_EN_MEDIA_ENCRYPT_AES   = 1,    /**< AES���� */
    IMOS_EN_MEDIA_ENCRYPT_DES   = 2,    /**< DES���� */
    IMOS_EN_MEDIA_ENCRYPT_COUNT
} MC_MEDIA_ENCRYPT_EX_E;


/**
 * @enum tagMC_SignalTypeEx
 * @brief ý���������
 * @attention
 */
typedef  enum tagMC_SignalTypeEx
{
    IMOS_EN_SIGNAL_TYPE_NO      = 0,    /**< ��֧��������� */
    IMOS_EN_SIGNAL_TYPE_H235    = 1,    /**< H235���� */
    IMOS_EN_SIGNAL_TYPE_COUNT
} MC_SIGNAL_TYPE_EX_E;

/**
 * @enum tagHD_IFrameNumEx
 * @brief ÿ�ν���/����I֡����ķ���I֡֡��
 * @attention
 */
typedef  enum  tagHD_IFrameNumEx
{
    IMOS_EN_IFRAME_NUM_1F = 1,                               /**< 1֡ */
    IMOS_EN_IFRAME_NUM_2F = 2,                               /**< 2֡ */
    IMOS_EN_IFRAME_NUM_3F = 3,                               /**< 3֡ */
    IMOS_EN_IFRAME_NUM_4F = 4,                               /**< 4֡ */
    IMOS_EN_IFRAME_NUM_5F = 5,                               /**< 5֡ */
    IMOS_EN_IFRAME_NUM_6F = 6,                               /**< 6֡ */
    IMOS_EN_IFRAME_NUM_7F = 7,                               /**< 7֡ */
    IMOS_EN_IFRAME_NUM_8F = 8,                               /**< 8֡ */
    IMOS_EN_IFRAME_NUM_9F = 9,                               /**< 9֡ */
    IMOS_EN_IFRAME_NUM_10F = 10,                             /**< 10֡ */
    IMOS_EN_IFRAME_NUM_20F = 20,                             /**< 20֡ */
    IMOS_EN_IFRAME_NUM_30F = 30,                             /**< 30֡ */
    IMOS_EN_IFRAME_NUM_40F = 40,                             /**< 40֡ */
    IMOS_EN_IFRAME_NUM_50F = 50,                             /**< 50֡ */
    IMOS_EN_IFRAME_NUM_60F = 60,                             /**< 60֡ */
    IMOS_EN_IFRAME_NUM_70F = 70,                             /**< 70֡ */
    IMOS_EN_IFRAME_NUM_80F = 80,                             /**< 80֡ */
    IMOS_EN_IFRAME_NUM_90F = 90,                             /**< 90֡ */
    IMOS_EN_IFRAME_NUM_120F = 120,                           /**< 120֡ */
    IMOS_EN_IFRAME_NUM_FRAME_COUNT
} HD_IFRAME_NUM_FRAME_EX_E;

/**
 * @enum tagHD_IFrameAutoEncIntervalEx
 * @brief �Զ�����I֡��ʱ����
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
 * @brief �Զ�����I֡��ʱ����
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
 * @brief �������ת/��б����
 * @attention
 */
typedef  enum  tagHD_CameraPositionEx
{
    IMOS_EN_POS_UP      = 0,    /**< ����  */
    IMOS_EN_POS_DOWN    = 1,    /**< ����  */
    IMOS_EN_POS_LEFT    = 2,    /**< ����  */
    IMOS_EN_POS_RIGHT   = 3,    /**< ����  */
    IMOS_EN_POS_RESET   = 4,    /**< ����  */
    IMOS_EN_POS_STOP    = 5,    /**< ֹͣ */
    IMOS_EN_POS_COUNT
} HD_CAMERA_POSITION_EX_E;

/**
 * @enum tagHD_CameraZoomEx
 * @brief ͼ������ģʽ
 * @attention
 */
typedef  enum  tagHD_CameraZoomEx
{
    IMOS_EN_CAMERA_ZOOM_OUT     = 0,    /**< ��С  */
    IMOS_EN_CAMERA_ZOOM_IN      = 1,    /**< �Ŵ�  */
    IMOS_EN_CAMERA_ZOOM_STOP    = 2,    /**< ֹͣ */
    IMOS_EN_CAMERA_ZOOM_COUNT
} HD_CAMERA_ZOOM_EX_E;

/**
 * @enum tagHD_CameraFocusEx
 * @brief �۽�ģʽ
 * @attention
 */
typedef enum tagHD_CameraFocusEx
{
    IMOS_EN_CAMERA_FOCUS_AUTO   = 0,    /**< �Զ� */
    IMOS_EN_CAMERA_FOCUS_MANUAL = 1,    /**< �ֶ� */
    IMOS_EN_CAMERA_FOCUS_COUNT
} HD_CAMERA_FOCUS_EX_E;


/**
 * @enum tagMC_SiteStatusEx
 * @brief �᳡״̬
 * @attention
 */
typedef  enum tagMC_SiteStatusEx
{
    IMOS_EN_SITE_OFF_LINE       = 0,    /**< �᳡������ */
    IMOS_EN_SITE_CALLING_IN     = 1,    /**< ���ڱ�MCU���� */
    IMOS_EN_SITE_CALLING_OUT    = 2,    /**< ���ں���MCU */
    IMOS_EN_SITE_IN_CONF        = 3,    /**< �Ѿ��ڻ����� */
    IMOS_EN_SITE_DROPING        = 4,    /**< ���ڹҶϻ᳡ */
    IMOS_EN_SITE_DROPED         = 5,    /**< �᳡�Ѿ��˳����� */
    IMOS_EN_SITE_UNKNOW         = 6,    /**< �᳡״̬δ֪ */
    IMOS_EN_SITE_DELETING       = 7,    /**< ���ڱ�ɾ�� */
    IMOS_EN_SITE_DISABLE        = 8,    /**< �᳡�����ã����������ʹ�� */
    IMOS_EN_SITE_STATUS_COUNT
} MC_SITE_STATUS_EX_E;

/**
 * @enum tagHD_CapTypeEx
 * @brief �������е���������
 * @attention
 */
typedef  enum    tagHD_CapTypeEx
{
     IMOS_EN_HD_CAP_AUDIO   = 0,    /**< ��Ƶ���� */
     IMOS_EN_HD_CAP_VIDEO   = 1,    /**< ��Ƶ���� */
     IMOS_EN_HD_CAP_ANNEX   = 2,    /**< �������� */
     IMOS_EN_HD_CAP_DATA    = 3,    /**< �������� */
     IMOS_EN_HD_CAP_CTRL    = 4,    /**< �������� */
     IMOS_EN_HD_CAP_COUNT           /**< ���� */
} HD_CAP_TYPE_EX_E;

/**
 * @enum tagHD_DataProtEx
 * @brief ����Э������
 * @attention
 */
typedef  enum  tagHD_DataProtEx
{
    IMOS_EN_DATA_PROT_H224 = 0,                                    /**< H224Э�� */
    IMOS_EN_DATA_PROT_COUNT
} HD_DATA_PROT_EX_E;

/**
 * @enum tagHD_ControlProtEx
 * @brief ����Э������
 * @attention
 */
typedef  enum  tagHD_ControlProtEx
{
    IMOS_EN_CTRL_PROT_H239 = 0,                                   /**< H239Э�� */
    IMOS_EN_CTRL_PROT_LPR  = 1,                                   /**< �Ǳ�LPR */
    IMOS_EN_CTRL_PROT_COUNT
} HD_CTRL_PROT_EX_E;

/**
 * @enum tagHD_SysTimeZoneEx
 * @brief ʱ��
 * @attention
 */
typedef enum tagHD_SysTimeZoneEx
{
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_12 = 0,    /**< (GMT-12:00)�ս�����*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_11 = 1,    /**< (GMT-11:00)��;��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_10 = 2,    /**< (GMT-10:00)������*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_9  = 3,    /**< (GMT-09:00)����˹��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_8  = 4,    /**< (GMT-08:00)̫ƽ��ʱ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_7  = 5,    /**< (GMT-07:00)ɽ��ʱ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_6  = 6,    /**< (GMT-06:00)�в�ʱ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_5  = 7,    /**< (GMT-05:00)����ʱ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_4  = 8,    /**< (GMT-04:00)������ʱ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_3  = 9,    /**< (GMT-03:00)������*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_2  = 10,   /**< (GMT-02:00)�д�����*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT_1  = 11,   /**< (GMT-01:00)��ý�Ⱥ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT    = 12,   /**< (GMT)�������α�׼ʱ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT1   = 13,   /**< (GMT+01:00)���֣�����*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT2   = 14,   /**< (GMT+02:00)���ޣ��ŵ�*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT3   = 15,   /**< (GMT+03:00)Ī˹�ƣ��͸��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT4   = 16,   /**< (GMT+04:00)�Ϳ⣬������*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT5   = 17,   /**< (GMT+05:00)��˹����*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT6   = 18,   /**< (GMT+06:00)����ľͼ*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT7   = 19,   /**< (GMT+07:00)���ȣ�����*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT8   = 20,   /**< (GMT+08:00)���������� */
    IMOS_EN_HD_SYS_TIME_ZONE_GMT9   = 21,   /**< (GMT+09:00)�������׶�*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT10  = 22,   /**< (GMT+10:00)��������ī����*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT11  = 23,   /**< (GMT+11:00)������Ⱥ��*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT12  = 24,   /**< (GMT+12:00)�¿����������*/
    IMOS_EN_HD_SYS_TIME_ZONE_GMT13  = 25,   /**< (GMT+13:00)Ŭ�Ⱒ�巨*/
    IMOS_EN_HD_SYS_TIME_ZONE_COUNT
} HD_SYS_TIMEZONE_EX_E;

/**
 * @enum tagHD_SysLanguageEx
 * @brief ϵͳ��������
 * @attention
 */
typedef enum tagHD_SysLanguageEx
{
    IMOS_EN_LANGUAGE_SIMPLE_CHINESE         = 0,    /**< �������� */
    IMOS_EN_LANGUAGE_TRADITIONAL_CHINESE    = 1,    /**< �������� */
    IMOS_EN_LANGUAGE_ENGLISH                = 2,    /**< Ӣ�� */
    IMOS_EN_LANGUAGE_COUNT
} HD_SYS_LANGUAGE_EX_E;

/**
 * @enum tagHD_NetCardDuplexTypeEx
 * @brief ����˫��ģʽ
 * @attention
 */
typedef  enum  tagHD_NetCardDuplexTypeEx
{
    IMOS_EN_FULLDUPLEX          = 0,    /**< ȫ˫�� */
    IMOS_EN_SEMIDUPLEX          = 1,    /**< ��˫�� */
    IMOS_EN_DUPLEX_NEGOTIATE    = 2,    /**< ��Э�� */
    IMOS_EN_KEEP_DUPLEX_CFG     = 255   /**< ����ԭ������ */
} HD_NETCARD_DUPLEX_TYPE_EX_E;

/**
 * @enum tagHD_NetCardRateEx
 * @brief ����֧������
 * @attention
 */
typedef  enum  tagHD_NetCardRateEx
{
    IMOS_EN_CARD_RATE10M        = 0,    /**< 10M */
    IMOS_EN_CARD_RATE100M       = 1,    /**< 100M */
    IMOS_EN_CARD_RATE1000M      = 2,    /**< 1000M */
    IMOS_EN_CARD_RATE_NEGOTIATE = 3,    /**< ��Э�� */
    IMOS_EN_KEEP_CARD_RATE_CFG  = 255   /**< ����ԭ������ */
} HD_NETCARD_RATE_EX_E;

/**
 * @enum tagHD_BoardTypeEx
 * @brief �豸����
 * @attention
 */
typedef  enum tagHD_BoardTypeEx
{
    IMOS_EN_BOARD_MMC   = 0,    /**< ����MC����� */
    IMOS_EN_BOARD_BMC   = 1,    /**< ����MC����� */
    IMOS_EN_BOARD_LAN   = 2,    /**< �ӿڴ���� */
    IMOS_EN_BOARD_AUX   = 3,    /**< ��Ƶ����� */
    IMOS_EN_BOARD_VP    = 4,    /**< ��Ƶ����� */
    IMOS_EN_BOARD_TYPE_COUNT
} HD_BOARD_TYPE_EX_E;

/**
 * @enum tagHD_FanStateEx
 * @brief ����״̬
 * @attention
 */
typedef enum tagHD_FanStateEx
{
    IMOS_EN_FAN_STATE_ABSENT            = -1,   /**< ����λ */
    IMOS_EN_FAN_STATE_NORMAL            = 0,    /**< ���� */
    IMOS_EN_FAN_STATE_SPEED_ABNORMAL    = 1,    /**< ת���쳣 */
    IMOS_EN_FAN_STATE_BLOCKED           = 2,    /**< �������� */
    IMOS_EN_FAN_STATE_OUT_OF_CONTROL    = 3     /**< ʧȥ����--���� */
} HD_FAN_STATE_EX_E;

/**
 * @enum tagHD_DspStatusEnEx
 * @brief DSP״̬����ʶDSP�Ƿ����
 * @attention
 */
typedef  enum  tagHD_DspStatusEnEx
{
    IMOS_EN_DSP_STAT_IDLE   = 0,    /**< ����״̬  */
    IMOS_EN_DSP_STAT_USED   = 1,    /**< DSP��ʹ����  */
    IMOS_EN_DSP_STAT_ERROR  = 2,    /**< DSP����  */
    IMOS_EN_DSP_STAT_COUNT
} HD_DSP_STATUS_EX_E;

/**
 * @enum tagHD_ComBitRateEx
 * @brief ���ڴ��䲨����
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
 * @brief �ն�����Ƶʹ������
 * @attention
 */
typedef  enum tagMC_TermTypeEx
{
    IMOS_EN_TERM_AUDIO                      = 0,    /**< ����Ƶ�ն� */
    IMOS_EN_TERM_AUDIO_VIDEO                = 1,    /**< ����Ƶ�ն� */
    IMOS_EN_TERM_SECOND_AUDIO_VIDEO         = 2,    /**< ������Ƶ�ն� */
    IMOS_EN_TERN_VIRTUAL_SEND_VIDEO_ONLY    = 3,    /**< ֻ����Ƶ�������ն� */
    IMOS_EN_TERN_VIRTUAL_RECV_VIDEO_ONLY    = 4,    /**< ֻ������Ƶ�������ն� */
    IMOS_EN_TERM_TYPE_COUNT
} MC_TERM_TYPE_EX_E;

/**
 * @enum tagMC_CallTermTypeEx
 * @brief ��������ʱ��ǰ�ն˺�������
 * @attention
 */
typedef enum tagMC_CallTermTypeEx
{
    IMOS_EN_CALL_TERM_TYPE_TERM = 0,    /**< ���е��ն�����Ϊ�˵� */
    IMOS_EN_CALL_TERM_TYPE_MCU  = 1,    /**< ���е��ն�����ΪMCU */
    IMOS_EN_CALL_TERM_TYPE_COUNT
}MC_CALL_TERM_TYPE_EX_E;

/**
 * @enum tagHD_ChnDirectionEx
 * @brief ͨ������
 * @attention
 */
typedef  enum  tagHD_ChnDirectionEx
{
    IMOS_EN_CHN_IN  = 0,    /**< ����ͨ�� */
    IMOS_EN_CHN_OUT = 1,    /**< ���ͨ�� */
    IMOS_EN_DIRECT_COUNT
} HD_CHN_DIRECTION_EX_E;

/**
 * @enum tagMC_ConfTurnBroadcastModeEx
 * @brief ������Ѳ���㲥��Ѳģʽ
 * @attention
 */
typedef  enum tagMC_ConfTurnBroadcastModeEx
{
    IMOS_EN_TURN_MAIN_SITE = 0,     /**< ������Ѳ */
    IMOS_EN_TURN_BROADCAST = 1,     /**< �㲥��Ѳ */
    IMOS_EN_TURN_COUNT
} MC_CONF_TURN_BROADCAST_MODE_EX_E;

/**
 * @enum tagMC_GKTypeEx
 * @brief GK������
 * @attention
 */
typedef    enum    tagMC_GKTypeEx
{
    IMOS_EN_INNER_GK    = 0,    /**< ����GK */
    IMOS_EN_EXTER_GK    = 1,    /**< ����GK */
    IMOS_EN_NO_GK       = 2,    /**< ��ʹ��GK */
    IMOS_EN_GK_TYPE_COUNT,
} MC_GK_TYPE_EX_E;

/**
 * @enum tagMC_NtpTimeSynchIntervalEx
 * @brief NTPʱ��ͬ�����
 * @attention
 */
typedef  enum tagMC_NtpTimeSynchIntervalEx
{
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_10MIN = 10 * 60,                  /**< 10���� */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_15MIN = 15 * 60,                  /**< 15���� */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_30MIN = 30 * 60,                  /**< 30���� */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_1HOUR = 60 * 60,                  /**< 1Сʱ */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_2HOUR = 2 * 60 * 60,              /**< 2Сʱ */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_12HOUR = 12 * 60 * 60,            /**< 12Сʱ */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_24HOUR = 24 * 60 * 60,            /**< 24Сʱ */
    IMOS_EN_NTP_TIME_SYNCH_INTERVAL_COUNT
} MC_NTP_TIME_SYNCH_INTERVAL_EX_E;

#if 0
#endif

/*******************************************************************************
SS �ն��豸ʹ�õ�ö��
*******************************************************************************/

/**
 * @enum tagHD_AudioVolumeEx
 * @brief ����
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
 * @brief �������
 * @attention
 */
typedef enum tagHD_RingTypeEx
{
    IMOS_EN_RING_TYPE_BOOT_CALL1            = 0,    /**< ��������1 */
    IMOS_EN_RING_TYPE_BOOT_CALL2            = 1,    /**< ��������2 */
    IMOS_EN_RING_TYPE_BOOT_CALL3            = 2,    /**< ��������3 */
    IMOS_EN_RING_TYPE_BOOT_CALL4            = 3,    /**< ��������4 */
    IMOS_EN_RING_TYPE_BOOT_CALL5            = 4,    /**< ��������5 */
    IMOS_EN_RING_TYPE_BOOT_DEFAULT          = 5,    /**< Ĭ�ϵĿ������� */
    IMOS_EN_RING_TYPE_BOOT_FASHION          = 6,    /**< ʱ�еĿ������� */
    IMOS_EN_RING_TYPE_BOOT_GRACE            = 7,    /**< ������ŵĿ������� */
    IMOS_EN_RING_TYPE_INCOMING_CALL1        = 8,    /**< ��������1 */
    IMOS_EN_RING_TYPE_INCOMING_CALL2        = 9,    /**< ��������2 */
    IMOS_EN_RING_TYPE_INCOMING_CALL3        = 10,   /**< ��������3 */
    IMOS_EN_RING_TYPE_INCOMING_CALL4        = 11,   /**< ��������4 */
    IMOS_EN_RING_TYPE_INCOMING_CALL5        = 12,   /**< ��������5 */
    IMOS_EN_RING_TYPE_INCOMING_CALL_DEFAULT = 13,   /**< Ĭ�ϵ��������� */
    IMOS_EN_RING_TYPE_INCOMING_CALL_FASHION = 14,   /**< ʱ�е��������� */
    IMOS_EN_RING_TYPE_INCOMING_CALL_GRACE   = 15,   /**< ������ŵ��������� */
    IMOS_EN_RING_TYPE_CUSTOM1               = 16,   /**< �Զ�������1��������������������ѡ�� */
    IMOS_EN_RING_TYPE_CUSTOM2               = 17,   /**< �Զ�������2��������������������ѡ�� */
    IMOS_EN_RING_TYPE_CUSTOM3               = 18,   /**< �Զ�������3��������������������ѡ�� */
    IMOS_EN_RING_TYPE_CUSTOM4               = 19,   /**< �Զ�������4��������������������ѡ�� */
    IMOS_EN_RING_TYPE_CUSTOM5               = 20,   /**< �Զ�������5��������������������ѡ�� */
    IMOS_EN_RING_TYPE_COUNT                         /**< ���� */
}HD_RING_TYPE_EX_E;


/**
 * @enum tagHD_NIC_NumberEx
 * @brief ���ں�
 * @attention
 */
typedef  enum  tagHD_NIC_NumberEx
{
    IMOS_EN_HD_NIC_INVALID = -1,
    IMOS_EN_HD_NIC_0 = 0,                                          /**< ����0 ֵ���ɸı�(���������±�, ������������ֵ����ת��ֱ���ô�) */
    IMOS_EN_HD_NIC_1 = 1,                                          /**< ����1 ֵ���ɸı�(���������±�) */
    IMOS_EN_HD_NIC_COUNT
}HD_NIC_NUMBER_EX_E;

/**
 * @enum tagHD_Framerate_TypeEx
 * @brief ��Ƶ֡������
 * @attention
 */
typedef enum tagHD_Framerate_TypeEx
{
    IMOS_EN_AUTO_FRAMERATE      = 0,    /**< �Զ� */
    IMOS_EN_CLEAR_FRAMERATE     = 1,    /**< ���� */
    IMOS_EN_FLUENT_FRAMERATE    = 2,    /**< ���� */
    IMOS_EN_FRAMERATE_TYPE_COUNT,
}HD_FRAMERATE_TYPE_EX_E;


/**
 * @enum tagHD_VideoInPortEx
 * @brief ��Ƶ����˿�
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
    IMOS_EN_VIDEO_IN_PORT_COUNT             /**< ���� */
} HD_VIDEO_IN_PORT_EX_E;


/**
 * @enum tagHD_AECTypeEx
 * @brief MIC �� RCA ������������
 * @attention
 */
typedef enum tagHD_AECTypeEx
{
    IMOS_EN_AEC_TYPE_STRONG = 0,    /**< ǿ */
    IMOS_EN_AEC_TYPE_WEAK   = 1,    /**< �� */
    IMOS_EN_AEC_TYPE_NONE   = 2,    /**< �� */
    IMOS_EN_AEC_TYPE_COUNT          /**< ���� */
}HD_AEC_TYPE_EX_E;


/**
 * @enum tagHD_TNAAType
 * @brief �����������
 * @attention
 */
typedef enum tagHD_TNAAType
{
    IMOS_NAA_TYPE_SHORT_DELAY   = 0,    /** ��������ʱ*/
    IMOS_NAA_TYPE_MID_DELAY     = 1,    /** �е�������ʱ*/
    IMOS_NAA_TYPE_LONG_DELAY    = 2,    /** ��������ʱ*/
    IMOS_NAA_TYPE_DELAY_COUNT
}HD_TNAA_TYPE_EX_E;


/**
 * @enum tagHD_DebugLevelEx
 * @brief ���Լ���
 * @attention
 */
typedef  enum  tagHD_DebugLevelEx
{
    IMOS_EN_HD_DEBUG    = 0,    /**< Debug��������Ϣ,�������е�����Ϣ */
    IMOS_EN_HD_INFO     = 1,    /**< Info��������Ϣ,�������漶������Ϣ */
    IMOS_EN_HD_WARNING  = 2,    /**< ���漶������Ϣ,�������󼶵�����Ϣ */
    IMOS_EN_HD_ERROR    = 3,    /**< ���󼶵�����Ϣ,�����������������Ϣ */
    IMOS_EN_HD_FATAL    = 4,    /**< �������󼶵�����Ϣ */
    IMOS_EN_HD_NO       = 5,    /**< �����������Ϣ */
    IMOS_EN_HD_DEBUG_LEVEL_COUNT    /**< ��ö�����͵ĸ��� */
} HD_DEBUG_LEVEL_EX_E;


/**
 * @enum tagHD_LogoTypeEx
 * @brief ʹ��Logo ����
 * @attention
 */
typedef enum tagHD_LogoTypeEx
{
    IMOS_EN_LOGO_DEFAULT    = 0,    /**< Ĭ��LOGO */
    IMOS_EN_LOGO_TYPE1      = 1,    /**< ���������1 */
    IMOS_EN_LOGO_TYPE2      = 2,    /**< ���������2 */
    IMOS_EN_LOGO_TYPE3      = 3,    /**< ���������3 */
    IMOS_EN_LOGO_TYPE4      = 4,    /**< ���������4 */
    IMOS_EN_LOGO_TYPE5      = 5,    /**< ���������5 */
    IMOS_EN_LOGO_TYPE6      = 6,    /**< ���������6 */
    IMOS_EN_LOGO_TYPE7      = 7,    /**< ���������7 */
    IMOS_EN_LOGO_TYPE8      = 8,    /**< ���������8 */
    IMOS_EN_LOGO_TYPE9      = 9,    /**< ���������9 */
    IMOS_EN_LOGO_TYPE10     = 10,   /**< ���������10 */
    IMOS_EN_LOGO_COUNT              /**< ���� */
}HD_LOGO_TYPE_EX_E;


/**
 * @enum tagHD_QosTypeEx
 * @brief QOS�������IP Precedence��Diffserv
 * @attention
 */
typedef  enum  tagHD_QosTypeEx
{
    IMOS_EN_IP_PRECEDENCE = 0,                                   /**< IP ���ȼ��� */
    IMOS_EN_DIFF_SERV     = 1,                                   /**< Diffserv */
    IMOS_EN_SERVER_COUNT
} HD_QOS_TYPE_EX_E;


/**
 * @enum tagHD_UserTypeEx
 * @brief �û�����
 * @attention
 */
typedef enum tagHD_UserTypeEx
{
    IMOS_EN_USER_TYPE_TERMINAL_ADMIN    = 0,    /**< �ն˹���Ա */
    IMOS_EN_USER_TYPE_WEB_ADMIN         = 1,    /**< WEB����Ա  */
    IMOS_EN_USER_TYPE_PC_ADMIN          = 2,    /**< ����̨����Ա */
    IMOS_EN_USER_TYPE_COUNT                     /**< ���� */
}HD_USER_TYPE_EX_E;


/**
 * @enum tagHD_PwdEncTypeEx
 * @brief ������ܷ���
 * @attention
 */
typedef enum tagHD_PwdEncTypeEx
{
    IMOS_EN_PWD_ENC_NONE    = 0,    /**< �����ܣ����� */
    IMOS_EN_PWD_ENC_MD5     = 1,    /**< MD5����  */
    IMOS_EN_PWD_ENC_DES     = 2,    /**< DES���� */
    IMOS_EN_PWD_ENC_TYPE_COUNT
}HD_PWD_ENC_TYPE_EX_E;


/**
 * @enum tagHD_ConnectTypeEx
 * @brief �������ӷ�ʽ
 * @attention
 */
typedef enum tagHD_ConnectTypeEx
{
    IMOS_EN_CONNECT_TYPE_FIXEDIP    = 0,    /**< �̶�IP */
    IMOS_EN_CONNECT_TYPE_PPPOE      = 1,    /**< PPPoE��ʽ */
    IMOS_EN_CONNECT_TYPE_DHCP       = 2,    /**< �Զ����IP */
    IMOS_EN_CONNECT_TYPE_COUNT              /**< ���� */
}HD_CONNECT_TYPE_EX_E;


/**
 * @enum tagHD_BitRateEx
 * @brief ����
 * @attention
 */
typedef  enum tagHD_BitRateEx
{
    IMOS_EN_BIT_RATE_AUTO = 0,                      /**< �Զ� */
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
 * @brief �������÷�ʽ
 * @attention
 */
typedef  enum  tagHD_NetCardSetTypeEx
{
    IMOS_EN_CARD_SET_BY_MANUAL  = 0,    /**< �ֶ��������� */
    IMOS_EN_CARD_SET_BY_AUTO    = 1,    /**< ��Э�� */
    IMOS_EN_CARD_SET_COUNT,
} HD_NETCARD_SET_TYPE_EX_E;


/**
 * @enum tagHD_VideoOutPortEx
 * @brief ��Ƶ����˿�
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
    IMOS_EN_VIDEO_OUT_PORT_COUNT                /**< ���� */
} HD_VIDEO_OUT_PORT_EX_E;

/**
 * @enum tagHD_VideoOutContentTypeEx
 * @brief �������
 * @attention
 */
typedef enum tagHD_VideoOutContentTypeEx
{
    IMOS_EN_VIDEO_OUT_CONTENT_WITH_GUI      = 0,    /**< ��GUIͼ������   */
    IMOS_EN_VIDEO_OUT_CONTENT_LOCAL_MAIN    = 1,    /**< �������� */
    IMOS_EN_VIDEO_OUT_CONTENT_LOCAL_ROLE    = 2,    /**< ���ظ��� */
    IMOS_EN_VIDEO_OUT_CONTENT_REMOTE_MAIN   = 3,    /**< Զ������ */
    IMOS_EN_VIDEO_OUT_CONTENT_REMOTE_ROLE   = 4,    /**< Զ�˸���  */
    IMOS_EN_VIDEO_OUT_CONTENT_WITH_FIRST    = 5,    /**< ���һ·��ͬ  */
    IMOS_EN_VIDEO_OUT_CONTENT_COUNT                 /**< ���� */
} HD_VIDEO_OUT_CONTENT_TYPE_EX_E;


/**
 * @enum tagHD_Audio_In_Port_Sub_TypeEx
 * @brief ��Ƶ����˿ڵľ�������
 * @attention
 */
typedef enum tagHD_Audio_In_Port_Sub_TypeEx
{
    IMOS_EN_AUDIO_IN_PORT_SUB_TYPE_CLEARONEMIC  = 0,    /**< clearone MIC */
    IMOS_EN_AUDIO_IN_PORT_SUB_TYPE_OTHERS       = 1,    /**< ���� */
    IMOS_EN_AUDIO_IN_PORT_SUB_TYPE_COUNT                /**< ���� */
} HD_AUDIO_IN_PORT_SUB_TYPE_EX_E;


/**
 * @enum tagHD_Record_Storage_TypeEx
 * @brief ¼���洢����
 * @attention
 */
typedef enum tagHD_Record_Storage_TypeEx
{
   IMOS_EN_HD_RECORD_2PORT  = 0,    /**< ¼�����ӿ���� */
   IMOS_EN_HD_RECORD_2USB   = 1,    /**< ¼���洢��U�� */
   IMOS_EN_HD_RECORD_2DISK  = 2,    /**< ¼���洢��Ӳ��*/
   IMOS_EN_HD_RECORD_STORAGE_COUNT
} HD_RECORD_STORAGE_TYPE_EX_E;


/**
 * @enum tagHD_AudioOutPortEx
 * @brief ��Ƶ�����
 * @attention
 */
typedef enum tagHD_AudioOutPortEx
{
    IMOS_EN_AUDIO_OUT_PORT_PHOENIX1 = 0,    /**< ��˿� */
    IMOS_EN_AUDIO_OUT_PORT_RCA1     = 1,    /**< RCA1 */
    IMOS_EN_AUDIO_OUT_PORT_DVI_I1   = 2,    /**< DVI1 */
    IMOS_EN_AUDIO_OUT_PORT_DVI_I2   = 3,    /**< DVI2 */
    IMOS_EN_AUDIO_OUT_PORT_DVI_I3   = 4,    /**< DVI3 */
    IMOS_EN_AUDIO_OUT_PORT_COUNT             /**< ��Ƶ����˿���Ŀ */
} HD_AUDIO_OUT_PORT_EX_E;


/**
 * @enum tagHD_AudioInPortEx
 * @brief ��Ƶ����ӿ�
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
 * @brief ��ʾ�᳡��ģʽ,������Ϊ��ʾ����Ԥ��Ļ᳡��ȴ
 *        û��Ԥ��û᳡�Ļ᳡��ʱ��ʾ�᳡�Դ��Ļ᳡����
 * @attention
 */
typedef  enum tagHD_ShowSiteNameEx
{
    IMOS_EN_SHOW_SITE_OWNER = 0,                                   /**< ��ʾ�᳡�Դ��Ļ᳡�� */
    IMOS_EN_SHOW_SET_NAME   = 1,                                   /**< ��ʾԤ��Ļ᳡�� */
    IMOS_EN_SHOW_NO         = 2,                                   /**< ����ʾ�᳡�� */
    IMOS_EN_SHOW_SITE_COUNT
} HD_CONF_SHOW_SITE_NAME_EX_E;

/**
 * @enum tagHD_FontEx
 * @brief �᳡�������塢��Ļ���塢�������
 * @attention
 */
typedef  enum tagHD_FontEx
{
     IMOS_EN_FONT_HEITI = 0,                                       /**< ���� */
     IMOS_EN_FONT_YOUYUAN = 1,                                     /**< ��Բ */
     IMOS_EN_FONT_COUNT
} HD_FONT_EX_E;


/**
 * @enum tagHD_FontSizeEx
 * @brief �᳡���������С����Ļ�����С����������С
 * @attention
 */
typedef  enum tagHD_FontSizeEx
{
     IMOS_EN_FONT_SMALL = 0,                                       /**< С���� */
     IMOS_EN_FONT_MIDDLE = 1,                                      /**< ������ [��������] */
     IMOS_EN_FONT_LARGE = 2,                                       /**< ������ [������] */
     IMOS_EN_FONT_SIZE_COUNT
} HD_FONT_SIZE_EX_E;


/**
 * @enum tagHD_SiteNameTimerPosEx
 * @brief �᳡���ơ�����ʱ����ʾ��λ��
 * @attention
 */
typedef  enum tagHD_SiteNameTimerPosEx
{
    IMOS_EN_SITE_NAME_TIMER_POS_RIGHT_TOP       = 0,    /**< �᳡���ơ�ʱ�������ϲ�[����] */
    IMOS_EN_SITE_NAME_TIMER_POS_RIGHT_BOTTOM    = 1,    /**< �᳡���ơ�ʱ�������²�[����] */
    IMOS_EN_SITE_NAME_TIMER_POS_LEFT_TOP        = 2,    /**< �᳡���ơ�ʱ�������ϲ�[����] */
    IMOS_EN_SITE_NAME_TIMER_POS_LEFT_BOTTOM     = 3,    /**< �᳡���ơ�ʱ�������²�[����] */
    IMOS_EN_SITE_NAME_TIMER_POS_COUNT
} HD_SITE_NAME_TIMER_POS_EX_E;


/**
 * @enum tagHD_CameraTypeEx
 * @brief ���������
 * @attention
 */
typedef enum tagHD_CameraTypeEx
{
    IMOS_EN_CAM_SONY_D70    = 0,    /**< SONY_D70 */
    IMOS_EN_CAM_SONY_D100   = 1,    /**< SONY_D100 */
    IMOS_EN_CAM_SONY_EVIHD1 = 2,    /**< EVIHD1 */
    IMOS_EN_CAM_TYPE_COUNT          /**< ���� */
}HD_CAMERA_TYPE_EX_E;

/**
 * @enum tagHD_CameraSpeedEx
 * @brief �����ת���ٶ�
 * @attention
 */
typedef enum tagHD_CameraSpeedEx
{
    IMOS_EN_CAM_SPEED_LOW       = 0,        /**< ���� */
    IMOS_EN_CAM_SPEED_MIDDLE    = 1,        /**< ���� */
    IMOS_EN_CAM_SPEED_HIGH      = 2,        /**< ���� */
    IMOS_EN_CAM_SPEED_COUNT                 /**< ���� */
}HD_CAMERA_SPEED_EX_E;


/**
 * @enum tagHD_CameraPortEx
 * @brief ������˿�
 * @attention
 */
typedef enum tagHD_CameraPortEx
{
    IMOS_EN_CAM_PORT_NONE       = 0,    /**< �޶˿� */
    IMOS_EN_CAM_PORT_RS232_1    = 1,    /**< ����һ */
    IMOS_EN_CAM_PORT_RS232_2    = 2,    /**< ���ڶ� */
    IMOS_EN_CAM_PORT_COUNT
}HD_CAMERA_PORT_EX_E;

/**
 * @enum tagHD_VideoPortTypeEx
 * @brief �˿�����
 * @attention
 */
typedef enum tagHD_VideoPortTypeEx
{
    IMOS_EN_HD_VIDEO_PORT_DVI_I = 0,    /**< DVI  */
    IMOS_EN_HD_VIDEO_PORT_S     = 1,    /**< S���� */
    IMOS_EN_HD_VIDEO_PORT_RCA   = 2,    /**< RCA  */
    IMOS_EN_HD_VIDEO_PORT_SDI   = 3,    /**< SDI  */
    IMOS_EN_HD_VIDEO_PORT_COUNT         /**< ���� */
} HD_VIDEO_PORT_TYPE_EX_E;

/**
 * @enum tagHD_IPPrecedenceTypeEx
 * @brief IP���������Сʱ�ӡ��������������߿ɿ��ԡ���С����
 * @attention
 */
typedef  enum  tagHD_IPPrecedenceTypeEx
{
    IMOS_EN_PRECEDENCE_MIN_DELAY       = 0x10,                  /**< ��Сʱ�� */
    IMOS_EN_PRECEDENCE_MAX_THROUGHPUT  = 0x08,                  /**< ��������� */
    IMOS_EN_PRECEDENCE_MAX_RELIABILITY = 0x04,                  /**< ��߿ɿ��� */
    IMOS_EN_PRECEDENCE_MIN_MONETARY    = 0x02,                  /**< ��С���� */
    IMOS_EN_PRECEDENCE_NORMAL          = 0                      /**< ��ͨ */
} HD_IP_PRECEDENCE_TYPE_EX_E;



/**
 * @enum tagHD_Process_TypeEx
 * @brief ��������
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
    IMOS_EN_HD_PROCESS_TYPE_COUNT                          /**< ���� */
}HD_PROCESS_TYPE_EX_E;

/**
 * @enum tagHD_VideoPortDVITypeEx
 * @brief DVI����Ƶ����
 * @attention
 */
typedef enum tagHD_VideoPortDVITypeEx
{
    IMOS_EN_HD_VIDEO_PORT_DVI_RGBHV     = 0,    /**< RGBHV������D-SUB,XGA */
    IMOS_EN_HD_VIDEO_PORT_DVI_HDMIDVI   = 1,    /**< HDMI DVI ��������  */
    /**< IMOS_EN_HD_VIDEO_PORT_DVI_D,                                    D  */
    IMOS_EN_HD_VIDEO_PORT_DVI_YPrPb     = 2,    /**< YPrPb  */
    IMOS_EN_HD_VIDEO_PORT_DVI_RGB       = 3,    /**< RGB  */
    IMOS_EN_HD_VIDEO_PORT_DVI_COUNT             /**< ���� */
} HD_VIDEO_PORT_DVI_TYPE_EX_E;


/**
 * @enum tagHD_VideoFrequenceEx
 * @brief ��ƵƵ������
 * @attention
 */
typedef enum tagHD_VideoFrequenceEx
{
    IMOS_EN_HD_VIDEO_FREQUENCE_25HZ = 0,    /**< 25HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_30HZ = 1,    /**< 30HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_60HZ = 2,    /**< 60HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_75HZ = 3,    /**< 75HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_85HZ = 4,    /**< 85HZ */
    IMOS_EN_HD_VIDEO_FREQUENCE_COUNT        /**< ���� */
} HD_VIDEO_FREQUENCE_TYPE_EX_E;


/**
 * @enum tagHD_Restrict_TypeEx
 * @brief PAL��NTSC��ʽ
 * @attention
 */
typedef enum tagHD_Restrict_TypeEx
{
    IMOS_EN_PAL_TYPE    = 0,    /**< PAL��ʽ */
    IMOS_EN_NTSC_TYPE   = 1,    /**< NTSC��ʽ */
    IMOS_EN_RESTRICT_COUNT,
}HD_RESTRICT_TYPE_EX_E;

/**
 * @enum tagHD_ProtoTypeEx
 * @brief Э������
 * @attention
 */
typedef enum tagHD_ProtoTypeEx
{
    IMOS_EN_PROTO_TYPE_H323 = 0,    /**< H323Э�� */
    IMOS_EN_PROTO_TYPE_SIP  = 1,    /**< sipЭ��  */
    IMOS_EN_PROTO_TYPE_COUNT        /**< ���� */
}HD_PROTO_TYPE_EX_E;


/**
 * @enum tagHD_VideoTypeEx
 * @brief ����˿ڶ�Ӧ������������
 * @attention
 */
typedef  enum  tagHD_VideoTypeEx
{
    IMOS_EN_MV_PORT_1   = 0,    /**< ������ƵԴ1 */
    IMOS_EN_MV_PORT_2   = 1,    /**< ������ƵԴ2 */
    IMOS_EN_RV_PORT     = 2,    /**< ������ƵԴ */
    IMOS_EN_VIDEO_TYPE_COUNT
} HD_VIDEO_TYPE_EX_E;



/**
 * @enum tagModule_TypeEx
 * @brief �ն�ģ������
 * @attention
 */
typedef enum tagModule_TypeEx
{
    IMOS_EN_HD_MODULE_GUI   = 0,    /**< GUI (��ֵ���ɸı䣬���������±�)*/
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
 * @brief ��־����
 * @attention
 */
typedef  enum  tagHD_LogTypeEx
{
    IMOS_EN_HD_SYS_TYPE     = 0,    /**< ϵͳ��־ */
    IMOS_EN_HD_USER_TYPE    = 1,    /**< �û���־ */
    IMOS_EN_HD_CONF_TYPE    = 2,    /**< ������־ */
    IMOS_EN_HD_DEBUG_TYPE   = 3,    /**< ������־(�ն˽��治��ʾ) */
    IMOS_EN_HD_LOG_TYPE_COUNT       /**< ��ö�����͵ĸ��� */
} HD_LOG_TYPE_EX_E;


/**
 * @enum tagHD_VERSION_INDEXEx
 * @brief �汾�������
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
 * @brief ��ǰBAK���̵�״̬��������������������δȷ��
 * @attention
 */
typedef enum tagBAK_HostStateEx
{
    IMOS_EN_BAK_STATE_ALONE     = 0,    /**< ���� */
    IMOS_EN_BAK_STATE_MAIN      = 1,    /**< ���� */
    IMOS_EN_BAK_STATE_BACK      = 2,    /**< ���� */
    IMOS_EN_BAK_STATE_UNSURE    = 3,    /**< δȷ�� */

    IMOS_EN_BAK_SWITCHING_ALONE = 4,    /**< �����е��� */
    IMOS_EN_BAK_SWITCHING_MAIN  = 5,    /**< ���������� */
    IMOS_EN_BAK_SWITCHING_BACK  = 6,    /**< �����б��� */

    IMOS_EN_BAK_STATE_COUNT
}BAK_STATE_EX_E;


/**
 * @enum tagMC_LinkStatusEx
 * @brief ��·״̬ [����״̬���л�ʹ��]
 * @attention
 */
typedef enum tagMC_LinkStatusEx
{
    /** ������·�ߴ����ȶ� ������·UP */
    IMOS_EN_LINK_STATUS_MAIN_HB_BAK_UP      = 0,

    /** ������·�ʹ����ȶ� ������·UP */
    IMOS_EN_LINK_STATUS_MAIN_LB_BAK_UP      = 1,

    /** ������·�ʹ����� ������·UP */
    IMOS_EN_LINK_STATUS_MAIN_LP_BAK_UP      = 2,

    /** ������·DOWN ������·UP */
    IMOS_EN_LINK_STATUS_MAIN_DOWN_BAK_UP    = 3,

    /** ������·�ߴ����ȶ� ������·DOWN */
    IMOS_EN_LINK_STATUS_MAIN_HB_BAK_DOWN    = 4,

    /** ������·�ʹ����ȶ� ������·DOWN */
    IMOS_EN_LINK_STATUS_MAIN_LB_BAK_DOWN    = 5,

    /** ������·�ʹ����� ������·DOWN */
    IMOS_EN_LINK_STATUS_MAIN_LP_BAK_DOWN    = 6,

    /** ������·DOWN ������·DOWN */
    IMOS_EN_LINK_STATUS_MAIN_DOWN_BAK_DOWN  = 7,
    IMOS_EN_LINK_STATUS_COUNT
} MC_LINK_STATUS_EX_E;

/**
 * @enum tagMC_LinkStatusChgStepEx
 * @brief ��·״̬�л����� [����״̬���л�ʹ��]
 * @attention
 */
typedef enum tagMC_LinkStatusChgStepEx
{
    /** ����BFD */
    IMOS_EN_CHG_STEP_UPDATE_BFD_STATUS      = 0,

    /** ɾ��������·BFD */
    IMOS_EN_CHG_STEP_DELETE_MAIN_BFD        = 1,

    /** ɾ��������·BFD */
    IMOS_EN_CHG_STEP_DELETE_BAK_BFD         = 2,

    /** ����������·BFD */
    IMOS_EN_CHG_STEP_CREATE_MAIN_BFD        = 3,

    /** ����������·BFD */
    IMOS_EN_CHG_STEP_CREATE_BAK_BFD         = 4,

    /** �л�·����������· */
    IMOS_EN_CHG_STEP_CHG_ROUTE2MAIN         = 5,

    /** �л�·����������· */
    IMOS_EN_CHG_STEP_CHG_ROUTE2BAK          = 6,

    /** ����request mode */
    IMOS_EN_CHG_STEP_SEND_REQMODE           = 7,

    /** �޸�VP�������� */
    IMOS_EN_CHG_STEP_MODIFY_CHN_IN          = 8,

    /** �޸�VP�������� */
    IMOS_EN_CHG_STEP_MODIFY_CHN_OUT         = 9,

    /** ��ʼ������ */
    IMOS_EN_CHG_STEP_START_DETECT_BITRATE   = 10,

    /** ֹͣ������ */
    IMOS_EN_CHG_STEP_STOP_DETECT_BITRATE    = 11,
    IMOS_EN_CHG_STEP_COUNT
} MC_LINK_STATUS_CHG_STEP_EX_E;

/**
 * @enum tagMC_LinkChgActionEx
 * @brief ��·״̬�л����� [����״̬���л�ʹ��]
 * @attention
 */
typedef enum tagMC_LinkChgActionEx
{
    /** ·���л���������· */
    IMOS_EN_CHG_ACTION_ROUTE2BAK                = 0,

    /** ·���л���������· */
    IMOS_EN_CHG_ACTION_ROUTE2MAIN               = 1,

    /** ����ʽ��������·�ɲ��� */
    IMOS_EN_CHG_ACTION_ROUTE2BAK_BITRATE2BAK    = 2,

    /** ����ʽ��������·�ɲ��� */
    IMOS_EN_CHG_ACTION_ROUTE2MAIN_BITRATE2MAIN  = 3,

    /** [����ʽ]�����ʲ��� */
    IMOS_EN_CHG_ACTION_D_BITRATE                = 4,

    /** [����ʽ]�����ʲ��� */
    IMOS_EN_CHG_ACTION_U_BITRATE                = 5,

    /** ·���л���������·��ͨ��RESET������·BFDʵ�� */
    IMOS_EN_CHG_ACTION_RESET2MAIN               = 6,
    IMOS_EN_CHG_ACTION_COUNT
} MC_LINK_CHG_ACTION_EX_E;

/**
 * @enum tagMC_Link_Layer_TypeEx
 * @brief ��·����
 * @attention
 */
typedef  enum  tagMC_Link_Layer_TypeEx
{
    /** ������· */
    IMOS_EN_LINK_LAYER_MAIN = 0,

    /** ������· */
    IMOS_EN_LINK_LAYER_BAK  = 1,
    IMOS_EN_LINK_LAYER_TYPE_COUNT
} MC_LINK_LAYER_TYPE_EX_E;

/**
 * @enum tagMC_Link_Layer_StateEx
 * @brief ��·����״̬
 * @attention
 */
typedef  enum  tagMC_Link_Layer_StateEx
{
    /** ��·�Ͽ� */
    IMOS_EN_LINK_LAYER_DISCONNECT = 0,

    /** �ߴ����ȶ� */
    IMOS_EN_LINK_LAYER_HIGH_BANDWIDTH = 1,

    /** �ʹ����ȶ� */
    IMOS_EN_LINK_LAYER_LOW_BANDWIDTH = 2,

    /** �ʹ����� */
    IMOS_EN_LINK_LAYER_LOW_BANDWIDTH_WITH_LOST = 3,

    IMOS_EN_LINK_LAYER_STATE_COUNT
} MC_LINK_LAYER_STATE_EX_E;

/**
 * @enum tagMC_Link_Layer_NIC_TypeEx
 * @brief ��·��
 * @attention
 *      1������ MCU :������·�� --> eth0;   ������·�� --> eth1
 *      2������ �ն�:������·�� --> eth0/1; ������·�� --> E1
 *      3��LO �� IP ��ַ��Ϊҵ���ַ
 */
typedef  enum  tagMC_Link_Layer_NIC_TypeEx
{
    /** ������·��[������·��ַ] */
    IMOS_EN_LINK_LAYER_NIC_TYPE_MAIN = 0,

    /** ������·��[������·��ַ] */
    IMOS_EN_LINK_LAYER_NIC_TYPE_BAK = 1,

    /** LO ��[ҵ���ַ] */
    IMOS_EN_LINK_LAYER_NIC_TYPE_LO = 2,
    IMOS_EN_LINK_LAYER_NIC_TYPE_COUNT,
} MC_LINK_LAYER_NIC_TYPE_EX_E;

/**
 * @enum tagMC_Link_Layer_Switch_ModeEx
 * @brief ��·�л�ģʽ
 * @attention
 */
typedef  enum  tagMC_Link_Layer_Switch_ModeEx
{
    /** �Զ� */
    IMOS_EN_LINK_LAYER_SWITCH_BY_AUTO = 0,

    /** �ֶ� */
    IMOS_EN_LINK_LAYER_SWITCH_BY_MANUAL = 1,
    IMOS_EN_LINK_LAYER_SWITCH_MODE_COUNT,
} MC_LINK_LAYER_SWITCH_MODE_EX_E;

 /**
 * @enum tagMC_TermAlarmStatusEx
 * @brief �ն�����澯״̬
 * @attention
 */
typedef enum tagMC_TermAlarmStatusEx
{
    /**< ������ */
    IMOS_EN_TERM_ALARM_DISABLE  = 0,

    /**< �澯 */
    IMOS_EN_TERM_ALARM_YES = 1,

    /**< ���� */
    IMOS_EN_TERM_ALARM_NO = 2,
    IMOS_EN_TERM_ALARM_COUNT
} MC_TERM_ALARM_STATUS_EX_E;

 /**
 * @enum tagMC_NodeTypeEx
 * @brief �ڵ�����
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
 * @attention ��������ն�״̬
 */
typedef enum tagMC_VirtualResStatusEx
{
    /**< ���� */
    IMOS_EN_VIRTUAL_RES_STATUS_IDLE  = 0,

    /**< ���������� */
    IMOS_EN_VIRTUAL_RES_STATUS_CAMERA = 1,

    /**< ����ɼ����� */
    IMOS_EN_VIRTUAL_RES_STATUS_SCREEN = 2,

    IMOS_EN_VIRTUAL_RES_STATUS_COUNT

} MC_VIRTUAL_RES_STATUS_EX_E;


/******************************************************************************
��־��MC_DEVICE_TYPE_E
���ͣ�ö��
Ŀ�ģ��ϱ���iMSC���豸�ͺ�
���壺
******************************************************************************/

/**
 * @enum tagMC_VirtualResStatusEx
 * @attention �ϱ���iMSC���豸�ͺ�
 */
typedef  enum tagMcDeviceTypeEx
{
    IMOS_EN_DEVICE_TYPE_SD_TERM_BEGIN   = 0,
    IMOS_EN_DEVICE_TYPE_MG6030          = 1,
    IMOS_EN_DEVICE_TYPE_MG6050          = 2,
    IMOS_EN_DEVICE_TYPE_MG6050S         = 3,
    IMOS_EN_DEVICE_TYPE_MG6060          = 4,
    IMOS_EN_DEVICE_TYPE_TOPVIEW         = 5,

    /** �����ն� */
    IMOS_EN_DEVICE_TYPE_VIRTUAL_TERM    = 6,

    /** �������ն� */
    IMOS_EN_DEVICE_TYPE_3RD_TERM    = 7,
    /** ������MCU */
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
 * @attention ����ѡ��ۿ�ģʽ
*/
typedef  enum tagMC_ChairBrowseModeEx
{
    /**< ����ѡ��ۿ������� */
    IMOS_EN_CHAIR_BROWSE_MODE_SINGLE_PIC = 0,

    /**< ����ѡ��ۿ��໭�� */
    IMOS_EN_CHAIR_BROWSE_MODE_MULTI_PIC = 1,

    IMOS_EN_CHAIR_BROWSE_MODE_COUNT
} MC_CHAIR_BROWSE_MODE_EX_E;

/**
 * @enum MC_BROADCAST_MODE_EX_E
 * @attention �㲥ģʽ
*/
typedef  enum tagMC_BroadcastModeEX
{
    /**< �㲥������ */
    IMOS_EN_BROADCAST_MODE_SINGLE_PIC = 0,

    /**< �㲥�໭�� */
    IMOS_EN_BROADCAST_MODE_MULTI_PIC = 1,

    IMOS_EN_BROADCAST_MODE_COUNT
} MC_BROADCAST_MODE_EX_E;

/**
 * @enum tagTermQueryType
 * @brief �ն˲�ѯ����
 * @attention
 */
typedef enum tagTermQueryType
{
    /**< �������ն� */
    IMOS_EN_TERM_QUERY_TYPE_3RD  = 0,

    /**< H3C�ն� */
    IMOS_EN_TERM_QUERY_TYPE_H3C = 1,

    /**< �����ն�(�����������ն�) */
    IMOS_EN_TERM_QUERY_TYPE_ALL = 2,

    /**< �����ն� */
    IMOS_EN_TERM_QUERY_TYPE_ANONY,

    IMOS_EN_TERM_QUERY_TYPE_COUNT
} TERM_QUERY_TYPE_E;



/**
 * @enum tagMC_ConfigRouteTypeEx
 * @brief ·�ɲ�������
 * @attention
 */
typedef  enum  tagMC_ConfigRouteTypeEx
{
    /**< ���·�� */
    IMOS_EN_CONFIG_ROUTE_ADD = 0,

    /**< �޸�·�� */
    IMOS_EN_CONFIG_ROUTE_MDF = 1,

    /**< ɾ��·�� */
    IMOS_EN_CONFIG_ROUTE_DEL = 2,

    /**< ���·�� */
    IMOS_EN_CONFIG_ROUTE_CLR = 3,

    IMOS_EN_CONFIG_ROUTE_COUNT
} MC_CONFIG_ROUTE_TYPE_EX_E;


/**
 * @enum tagMC_BrowseSiteTypeEx
 * @brief �ն˱��ۿ�ģʽ
 * @attention
 */
typedef  enum  tagMC_BrowseSiteTypeEx
{
    /**< �᳡��Ч */
    IMOS_EN_BROWSE_SITE_USE = 0,

    /**< �᳡��Ч */
    IMOS_EN_BROWSE_SITE_INVALID = 1,

    /**< �໭�� */
    IMOS_EN_BROWSE_SITE_MULTIPIC = 2,

    /**< MCU */
    IMOS_EN_BROWSE_SITE_MCU,

    IMOS_EN_BROWSE_SITE_COUNT
} MC_BROWSE_SITE_TYPE_EX_E;



/**
 * @enum tagEN_SCALER_TYPE_EX
 * @brief ����ģʽ: �ȱȺڱߴ����ȱȲü��������죬���ܵ��±��Ρ�͸������1:1
 * @attention
 */
typedef enum tagEN_SCALER_TYPE_EX
{
    /**< �ȱ�����ڱ� */
    IMOS_EN_HD_SCALER_TYPE_STRETCH_BLACK = 0,

    /**< �ȱ����ü� */
    IMOS_EN_HD_SCALER_TYPE_STRETCH_CUT = 1,

    /**< ȫ�� */
    IMOS_EN_HD_SCALER_TYPE_STRETCH = 2,

    /**< ԭʼ��С */
    IMOS_EN_HD_SCALER_TYPE_TRANSP = 3
} HD_SCALER_TYPE_EX_E;


/**
 * @enum tagHD_LPR_Type_EX
 * @brief LPR����
 * @attention
 */
typedef enum tagHD_LPR_Type_EX
{
    /**< ������LPR */
    IMOS_EN_HD_LPR_TYPE_NO = 0,

    /**< �������᳡���� */
    IMOS_EN_HD_LPR_TYPE_LOST_PATCKET_SITE = 1,

    /**< ȫ���᳡���� */
    IMOS_EN_HD_LPR_TYPE_ALL_SITE = 2
} HD_LPR_TYPE_EX_E;


/**
* @enum tagInterconnectInfoType
* @brief ������Ϣ����ö��
* @attention
*/
typedef enum tagInterconnectInfoType
{
    INTERCONNECT_INFO_TYPE_LODOMAIN      = 0,             /**< ��������Ϣ  */

    INTERCONNECT_INFO_TYPE_MAX,
    INTERCONNECT_INFO_TYPE_INVALID = 0xFF
}INTERCONNECT_INFO_TYPE_E;


/**
* @enum tagPlanOperateMode
* @brief �ƻ�����ģʽ
* @attention
*/
typedef enum tagPlanOperateMode
{
    PLAN_OPER_STOP = 0,                                 /**< ֹͣ�ƻ� */
    PLAN_OPER_START = 1,                                /**< �����ƻ� */
    PLAN_OPER_INVALID = 0xFFFFFFFF                      /**< ��Чֵ */
}PLAN_OPER_MODE_E;

/**
* @enum tagManualOperType
* @brief �ֶ���������
* @attention
*/
typedef enum tagManualOperType
{
    MANUAL_OPER_STOP = 0,               /**< ֹͣ */
    MANUAL_OPER_START = 1,              /**< ���� */
    MANUAL_OPER_FORWARD = 2,            /**< ��ǰ���� */
    MANUAL_OPER_BACKWARD = 3,           /**< ������ */
    MANUAL_OPER_PAUSE = 4,              /**< ��ͣ */
    MANUAL_OPER_RESUME = 5,             /**< �ָ� */

    MANUAL_OPER_MAX,                    /**< ö�����ֵ */
    MANUAL_OPER_INVALID = 0xFFFFFFFF    /**< ��Чֵ */
}MANUAL_OPER_TYPE_E;

/**
* @enum tagLayoutType
* @brief ��������ö��
* @attention
*/
typedef enum tagLayoutType
{
    LAYOUT_TYPE_SCREEN       = 1,       /**< ��Ļ���� */
    LAYOUT_TYPE_MONITOR      = 2,       /**< ���������� */

    LAYOUT_TYPE_MAX,                    /**< ö�����ֵ */
    LAYOUT_TYPE_INVALID = 0xFFFFFFFF    /**< ��Чֵ */
}LAYOUT_TYPE_E;


/**
* @enum tagSalvoType
* @brief ����ʾ����ö��
* @attention
*/
typedef enum tagSalvoType
{
    SALVO_TYPE_MONITOR      = 0,       /**< ����������ʾ */
    SALVO_TYPE_TVWALL       = 1,       /**< ����ǽ����ʾ */
    SALVO_TYPE_SCREEN       = 2,       /**< ��Ļ����ʾ */

    SALVO_TYPE_MAX,                    /**< ö�����ֵ */
    SALVO_TYPE_INVALID = 0xFFFFFFFF    /**< ��Чֵ */
}SALVO_TYPE_E;


/**
* @enum tagCommonSwitchType
* @brief ͨ����������ö��
* @attention
*/
typedef enum tagCommonSwitchType
{
    COMMON_SWITCH_GUARDTOUR     =  0,           /**< ��ͨ���� */
    COMMON_SWITCH_GROUPSWITCH   =  1,           /**< ����ʾ��Ѳ */
    /* Begin Added by dengshuhua00673, 2012-12-14 of �Զ�������Ѳ */
	COMMON_SWITCH_AUTOSWITCH       = 2,           /**< �Զ�������Ѳ */
	COMMON_SWITCH_GROUPSWITCH_BOTH = 3,         /**< ��������������Ѳ */
    /* End Added by dengshuhua00673, 2012-12-14 of �Զ�������Ѳ */

    /* Begin: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */
    COMMON_SWITCH_AUTOPOLL = 87,                   /**A8ƴ���Զ�������Ѳ*/
    COMMON_SWITCH_WINDOWPOLL = 86,             /**A8ƴ�ش�������Ѳ*/
    /* End: Added by chenmenglin 04110, 2017-09-02 for MPPD54245 A8ƴ���豸��Ѳ���� */

    COMMON_SWITCH_MAX,                          /**< ͨ�������������ֵ */
    COMMON_SWITCH_INVALID = 0XFFFFFFFF
}COMMON_SWITCH_TYPE_E;

/**
* @enum tagCommonSwitchPlanType
* @brief ͨ�����мƻ�����ö��
* @attention
*/
typedef enum tagCommonSwitchPlanType
{
    COMMON_SWITCHPLAN_TYPE_MONITOR = 0,                 /**< Ӳ�����мƻ� */
    COMMON_SWITCHPLAN_TYPE_SCREEN = 1,                  /**< ������мƻ� */
    COMMON_SWITCHPLAN_TYPE_GROUPSWITCH = 2,             /**< ����Ѳ�ƻ� */

    COMMON_SWITCHPLAN_TYPE_MAX,                         /**< ö�����ֵ */
    COMMON_SWITCHPLAN_TYPE_INVALID = 0xFFFFFFFF         /**< ��Чֵ */
}COMMON_SWITCHPLAN_TYPE_E;


/**
* @enum tagGroupSwitchType
* @brief ����Ѳ����ö��
* @attention
*/
typedef enum tagGroupSwitchType
{
    GROUP_SWITCH_TYPE_MONITOR     =  0,           /**< ����������Ѳ */
    GROUP_SWITCH_TYPE_TVWALL      =  1,           /**< ����ǽ����Ѳ */
    GROUP_SWITCH_TYPE_SCREEN      =  2,           /**< ��Ļ����Ѳ */

    GROUP_SWITCH_TYPE_MAX,                        /**< ����Ѳ�������ֵ */
    GROUP_SWITCH_TYPE_INVALID = 0XFFFFFFFF
}GROUP_SWITCH_TYPE_E;

/* Begin Added by dengshuhua00673, 2013-03-20 of �Զ�������Ѳ */
/**
* @enum tagAutoSalvoReaveType
* @brief �Զ�������Ѳ��ռ����
* @attention
*/
typedef enum tagAutoSalvoReaveType
{
    AUTOSALVO_REAVE_TYPE_NOREAVE     =  0,           /**< ����ռ */
    AUTOSALVO_REAVE_TYPE_REAVE       =  1,           /**< ��ռ */

    AUTOSALVO_REAVE_TYPE_MAX,                        /**< �Զ�������Ѳ��ռ�������ֵ */
    AUTOSALVO_REAVE_TYPE_INVALID = 0XFFFFFFFF
}AUTOSALVO_REAVE_TYPE_E;
/* End Added by dengshuhua00673, 2013-03-20 of �Զ�������Ѳ */

/** ͸��ͨ������UI���¼�ö�����Ͷ��� */
typedef enum tagTLNotifyUIEventType
{
    TL_NOTIFY_TYPE_REAVE   = 1,    /** ͸��ͨ����ͣ�� */

    TL_NOTIFY_TYPE_INVALID = 0xFFFFFFFF

}TL_NOTIFY_UI_EVENT_TYPE;

/**
* @enum tagConfCheckAuthMode
* @brief �����Ȩ��ʽ
* @attention
*/
typedef enum tagConfCheckAuthMode
{
    IMOS_EN_CONF_CHECK_AUTH_CONFCTRL   = 0,             /**< ������Ƽ�Ȩ */
    IMOS_EN_CONF_CHECK_AUTH_CONFMANAGE = 1,                 /**< ��������Ȩ */
    IMOS_EN_CONF_CHECK_AUTH_COUNT
} CONF_CHECK_AUTH_MODE_E;


/**
* @enum tagMcuSynchronStatus
* @brief MCUͬ��״̬
* @attention
*/
typedef enum tagMcuSynchronStatus
{
    IMOS_EN_MCU_SYNC_STATUS_OPEN  = 0,             /**< ����ͬ�� */
    IMOS_EN_MCU_SYNC_STATUS_CLOSE = 1,             /**< û����ͬ�� */
    IMOS_EN_MCU_SYNC_STATUS_COUNT
} MCU_SYNCHRON_STATUS_E;


/**
* @enum tagIMOSFtpFileType
* @brief FTP�ļ�����
* @attention
*/
typedef enum tagIMOSFtpFileType
{
    IMOS_FTP_FILE_TYPE_DEFAULT           = 0,      /** ȱʡ�ļ����ͣ���ʾֱ����ftp��Ŀ¼ */
    IMOS_FTP_FILE_TYPE_CONFERENCE_CONFIG = 1,      /** ��Ѷ�豸���������ļ�����Ӧ�����Ѷ���������ļ���Ŀ¼ */

    IMOS_FTP_FILE_TYPE_MAX,
    IMOS_FTP_FILE_TYPE_INVALID = 0xFFFFFFFF
}IMOS_FTP_FILE_TYPE_E;

/**
* @enum tagMCUBackupType
* @brief MCU��������
* @attention
*/
typedef enum tagMCUBackupType
{
    IMOS_MCU_BACKUP_TYPE_SPECIFIC       = 0,    /**< ר���ڱ��ݵ�MCU */
    IMOS_MCU_BACKUP_TYPE_AVAILABLE      = 1,    /**< �����ڱ��ݵ�MCU */
    IMOS_MCU_BACKUP_TYPE_UNAVAILABLE    = 2,    /**< �������ڱ��ݵ�MCU */
    IMOS_MCU_BACKUP_TYPE_COUNT
}MCU_BACKUP_TYPE_E;

/**
* @enum tagMCUBackupScope
* @brief MCU��������
* @attention
*/
typedef enum tagMCUBackupScope
{
    IMOS_MCU_BACKUP_SCOPE_LOCAL              = 0,  /**< ֻ���ڱ��ݵ�ǰ���MCU */
    IMOS_MCU_BACKUP_SCOPE_LOCAL_AND_CHILDREN = 1,  /**< ���ڱ��ݵ�ǰ����������MCU */
    IMOS_MCU_BACKUP_SCOPE_COUNT
}MCU_BACKUP_SCOPE_E;

/**
* @enum tagMgSessionStatus
* @brief MG�Ự״̬
* @attention
*/
typedef enum tagMgSessionStatus
{
    IMOS_MG_SESSION_STATUS_IDLE              = 0,  /**< ���� */
    IMOS_MG_SESSION_STATUS_CALLING           = 1,  /**< ͨ���� */
    IMOS_MG_SESSION_STATUS_UNKNOWN           = 2,  /**< δ֪ */
    IMOS_MG_SESSION_STATUS_COUNT
}MG_SESSION_STATUS_E;

/**
* @enum tagMCMCUCallTypeEX
* @brief MCU�����ն˵ĺ�����������
* @attention
*/
typedef enum tagMCMCUCallTypeEX
{
    IMOS_EN_MCU_CALL_TYPE_AUTO               = 0,  /* �Զ� */
    IMOS_EN_MCU_CALL_TYPE_CALL               = 1,  /* �������� */
    IMOS_EN_MCU_CALL_TYPE_WAIT               = 2,  /* �ȴ����� */
    IMOS_EN_MCU_CALL_TYPE_COUNT
} MC_MCU_CALL_TYPE_EX_E;

/**
* @enum tagTIP_TimeLenTypeEx
* @brief ��ʾ��ǰ���õ������ֽ�����ʾ��
* @attention
*/
typedef enum tagTIP_TimeLenTypeEx
{
    IMOS_EN_AUD_TIP_CONF_END_TIME0           = 0,  /* �����û��������ʾ�� */
    IMOS_EN_AUD_TIP_CONF_END_TIME3           = 3,  /* ���û������3���� */
    IMOS_EN_AUD_TIP_CONF_END_TIME5           = 5,  /* ���û������5���� */
    IMOS_EN_AUD_TIP_CONF_END_TIME10          = 10  /* ���û������10���� */
} HD_TIP_TIME_LEN_TYPE_EX_E;

/**
* @enum tagSubscType
* @brief ��������ö��
* @attention
*/
typedef enum tagSubscType
{
    SUBSC_ALARM_TYPE              = 0,                /**< �澯���ģ���Ӧ����ö��Ϊ:#SUBSC_ALARM_CON_E  */
    SUBSC_CATALOG_TYPE            = 1,                /**< Ŀ¼���� */

    SUBSC_MAX_TYPE,
    SUBSC_INVALID_TYPE            = 0xFF
}SUBSC_TYPE_E;

/**
* @struct SUBSC_ALARM_CON_S
* @brief ���ĸ澯��������ö��
*/
typedef enum tagAlarmConType
{
    ALARM_CON_EVENT_TYPE            = 0,            /** ���ĵĸ澯���� */
    ALARM_CON_LEVEL_TYPE,                           /** ���ĵĸ澯���𣬴�������ALARM_CON_EVENT_TYPE���� */

    ALARM_CON_TYPE_MAX,
    ALARM_CON_TYPE_INVALID          = 0xFF
}SUBSC_ALARM_CON_E;

/**
* @enum tagTrunkType
* @brief ���߹�������ö��
* @attention
*/
typedef enum tagTrunkType
{
    TRUNK_TYPE_EXDOMAIN     = 0,             /**< �������  */
    TRUNK_TYPE_DEV          = 1,             /**< �豸����  */

    TRUNK_TYPE_MAX,
    TRUNK_TYPE_INVALID          = 0xFF
}TRUNK_TYPE_E;

/**
* @enum tagTrunkContentType
* @brief ������������ö��
* @attention
*/
typedef enum tagTrunkContentType
{
    TRUNK_CONTENT_TYPE_ALL_EXDOMAIN     = 0,             /**< ��������  */
    TRUNK_CONTENT_TYPE_EXDOMAIN         = 1,             /**< ����  */
    TRUNK_CONTENT_TYPE_ORG              = 2,             /**< ��֯  */
    TRUNK_CONTENT_TYPE_DEV              = 3,             /**< �豸  */
    TRUNK_CONTENT_TYPE_ECR_DEV          = 4,             /**< ECR�豸  */

    /* Begin add by zhuzhicong/02302, 2016-10-13 13:44:36�� �෿�߶�����ECR���߹��� */
    TRUNK_CONTENT_TYPE_EXDOMAIN_ORG     = 5,             /**< ������֯ */
    /* End add by zhuzhicong/02302, 2016-10-13 13:45:46 */

    TRUNK_CONTENT_TYPE_MAX,
    TRUNK_CONTENT_TYPE_INVALID          = 0xFF
}TRUNK_CONTENT_TYPE_E;


/**
* @enum tagTrunkContentRangeType
* @brief �������ݹ���Χ����ö��
* @attention
*/
typedef enum tagTrunkContentRangeType
{
    TRUNK_CONTENT_RANGE_TYPE_LOC            = 0,        /**< ���� */
    TRUNK_CONTENT_RANGE_TYPE_LOC_AND_SUB    = 1,        /**< �����Լ��¼�  */

    TRUNK_CONTENT_RANG_TYPE_MAX,
    TRUNK_CONTENT_RANG_TYPE_INVALID         = 0xFF
}TRUNK_CONTENT_RANGE_TYPE_E;

/**
* @enum tagPlanTypeDef
* @brief �ƻ����Ͷ���
* @attention
*/
typedef enum tagPlanTypeDef
{
    PLAN_BAK              = 0,                          /**< ���ݼƻ� */
    PLAN_STREAM_STOR      = 1,     						/**< ��ת��ƻ� */
    PLAN_TYPE_DEF_MAX,                                  /**< ���ֵ */
    PLAN_TYPE_DEF_INVALID = 0xFFFFFFFF                  /**< ��Чֵ */
}PLAN_TYPE_DEF_E;

/**
* @enum tagBakMode
* @brief ����ģʽ
* @attention
*/
typedef enum tagBakMode
{
    BAK_SHARE        = 0,                               /**< ���� */
    BAK_OWN          = 1,                               /**< ���� */
    BAK_MODE_MAX,                                       /**< ���ֵ */
    BAK_MODE_INVALID = 0xFFFFFFFF                       /**< ��Чֵ */
}BAK_MODE_E;

/**
* @enum tagBakType
* @brief ��������
* @attention
*/
typedef enum tagBakType
{
    BAK_PLAN         = 0,                               /**< �ƻ����� */
    BAK_MANUL        = 1,                               /**< �ֶ����� */
    BAK_ALARM        = 2,                               /**< �澯���� */
    BAK_ALL          = 3,                               /**< �����������ͣ���ѯ����ʱʹ�� */
    BAK_TYPE_MAX,                                       /**< ���ֵ */
    BAK_TYPE_INVALID = 0xFFFFFFFF                       /**< ��Чֵ */
}BAK_TYPE_E;

/**
* @enum tagBakPolicy
* @brief ���ݲ���
* @attention
*/
typedef enum tagBakPolicy
{
    BAK_POLICY_FULLFRAME = 0,                           /**< ȫ֡���� */
    /*begin add by liangchao, 2016-03-5 for ֧��svc*/
	BAK_POLICY_SOMEFRAME = 1,                           /**< ��֡���� */
	BAK_POLICY_HALFFRAME = 2,                           /**<1/2��֡ */
	BAK_POLICY_QUARTERFRAME = 3,                        /**<1/4��֡ */
	/*end add by liangchao, 2016-03-5 for ֧��svc*/
    BAK_POLICY_MAX,                                     /**< ���ֵ */
    BAK_POLICY_INVALID   = 0xFFFFFFFF                   /**< ��Чֵ */
}BAK_POLICY_E;

/**
* @enum tagAutoRetryEnable
* @brief �Զ����Ȳ���
* @attention
*/
typedef enum tagAutoRetry
{
    AUTO_RETRY_DISABLE = 0,                           /**< �������Զ����� */
    AUTO_RETRY_ENABLE = 1,                           /**< �����Զ����� */
    AUTO_RETRY_MAX,                                     /**< ���ֵ */
    AUTO_RETRY_INVALID   = 0xFFFFFF                     /**< ��Чֵ */
}AUTO_RETRY_E;

/**
* @enum tagBakTaskStatus
* @brief ��������״̬
* @attention
*/
typedef enum tagBakTaskStatus
{
    BAK_TASK_WAIT           = 0,                        /**< δ���� */
    BAK_TASK_RUN            = 1,                        /**< ���ڱ��� */
    BAK_TASK_DONE           = 2,                        /**< �Ѿ���� */
    BAK_TASK_HANG           = 3,                        /**< �һ� */
    BAK_TASK_STATUS_MAX,                                /**< ���ֵ */
    BAK_TASK_STATUS_INVALID = 0xFFFFFFFF                /**< ��Чֵ */
}BAK_TASK_STATUS_E;

/**
* @enum tagBakFileOper
* @brief �����ļ�����
* @attention
*/
typedef enum tagBakFileOper
{
    BAK_FILE_LOCK         = 1,                          /**< ���� */
    BAK_FILE_UNLOCK       = 2,                          /**< ���� */
    BAK_FILE_DELETE       = 3,                          /**< ɾ�� */
    BAK_FILE_OPER_MAX,                                  /**< ���ֵ */
    BAK_FILE_OPER_INVALID = 0xFFFFFFFF                  /**< ��Чֵ */
}BAK_FILE_OPER_E;

/**
* @enum tagBakResStatus
* @brief ������Դ״̬
* @attention
*/
typedef enum tagBakResStatus
{
    BAK_RES_UNFORMATTED    = 0,                         /**< δ��ʽ�� */
    BAK_RES_FORMATTING     = 1,                         /**< ���ڸ�ʽ�� */
    BAK_RES_ONLINE         = 2,                         /**< ���� */
    BAK_RES_OFFLINE        = 3,                         /**< ���� */
    BAK_RES_STATUS_MAX,                                 /**< ���ֵ */
    BAK_RES_STATUS_INVALID = 0xFFFFFFFF                 /**< ��Чֵ */
}BAK_RES_STATUS_E;

/**
* @enum tagBakFileQueryType
* @brief ����¼���ѯ����
* @attention
*/
typedef enum tagBakFileQueryType
{
    BAK_FILE_QUERY_TYPE_TIME    = 0,                    /**< ������ʱ���ѯ */
    BAK_FILE_QUERY_TYPE_CASE    = 1,                    /**< ������������ѯ */
    BAK_FILE_QUERY_TYPE_MAX,                            /**< ���ֵ */
    BAK_FILE_QUERY_TYPE_INVALID = 0xFFFFFFFF            /**< ��Чֵ */
}BAK_FILE_QUERY_TYPE_E;

/**
* @enum tagBakResType
* @brief ������Դ����
* @attention
*/
typedef enum tagBakResType
{
    BAK_RES_TYPE_H3C     = 0,                           /**< ��˾�豸 */
    BAK_RES_TYPE_THIRD   = 1,                           /**< �������豸 */
    BAK_RES_TYPE_CDS     = 4,                           /**< cds�豸 */
    BAK_RES_TYPE_MAX,                                   /**< ���ֵ */
    BAK_RES_TYPE_INVALID = 0xFFFFFFFF                   /**< ��Чֵ */
}BAK_RES_TYPE_E;

/* added by z06806 for vodwall prj 20101216 begin */
/**
* @enum tagVODWALLStopCodeType
* @brief ��ʾʹ�����ֱ������رջط���ǽ
* @attention
*/
typedef enum tagVODWALLStopCodeType
{
    IMOS_VODWALL_STOP_CODETYPE_XP           = 0,  /* ����XP����رջط���ǽ */
    IMOS_VODWALL_STOP_CODETYPE_MONITOR      = 1,  /* ���ݼ���������رջط���ǽ */
} VODWALL_STOP_CODETYPE_E;
/* added by z06806 for vodwall prj 20101216 end */

/*@brief �ص��������� */
typedef VOID (STDCALL *SDK_CALL_BACK_PROC_PF)(INOUT VOID *pParam);


/**
* @enum tagUniversalConditionFlag
* @brief ͨ��Լ����ѯ������־λ
* @attention
*/
typedef enum tagUniversalConditionFlag
{
    /** ȫ�� */
    CONDITION_OR_ALL,
    /** ȫ�� */
    CONDITION_AND_ALL,
    /** �Ȼ���� ����:<a and b and (c or d)> */
    CONDITION_AND_OR,
    /** ������ ����:<a or b or (c and d)> */
    CONDITION_OR_AND
}UNI_CONDITION_FLAG_E;

/**************************************************************************/
/**
* @enum tagUniversalQueryFlag
* @brief ͨ�ò�ѯ��־λ
* @attention
*/
typedef enum tagUniversalQueryFlag
{
    UNI_QRY_CAM_STORAGE_INFO = 0,   /**< ������洢��Ϣ��ѯ,��Ӧ������#QRY_CAM_STORAGE_INFO_E */
    UNI_QRY_FAULT_DEVICE_INFO = 1,  /**< �����豸��Ϣ��ѯ,��Ӧ������#QRY_FAULT_DEV_INFO_E */
    UNI_QRY_FAULT_DEVSTAT_INFO = 2, /**< �����豸ͳ����Ϣ��ѯ,��Ӧ������#QRY_FAULT_DEV_STAT_E */
    UNI_QRY_ASSET_INFO = 3,         /**< �ʲ���Ϣ��ѯ,��Ӧ������#QRY_ASSET_INFO_E */
    UNI_QRY_ASSET_STAT_INFO = 4,    /**< �ʲ�ͳ����Ϣ��ѯ,��Ӧ������#QRY_ASSET_INFO_E */

    UNI_QRY_VEHICLE_DAY_STAT_BY_TYPE  = 5,  /**< ����ͳ�ƣ��ձ����ֳ�������ͳ��#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_DAY_STAT_BY_DIR   = 6,  /**< ����ͳ�ƣ��ձ����ֳ�������ͳ��#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_DAY_STAT_BY_LANE  = 7,  /**< ����ͳ�ƣ��ձ����ֳ���ͳ��#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_HOUR_STAT_BY_TYPE = 8,  /**< ����ͳ�ƣ�Сʱ�����ֳ�������ͳ��#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_HOUR_STAT_BY_DIR  = 9,  /**< ����ͳ�ƣ�Сʱ�����ֳ�������ͳ��#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_VEHICLE_HOUR_STAT_BY_LANE = 10, /**< ����ͳ�ƣ�Сʱ�����ֳ���ͳ��#QRY_VEHICLE_STAT_INFO_E */
    UNI_QRY_GACASE_INFO               = 11, /**< ������Ϣ��ѯ(��������֯),��Ӧ������#QRY_GACASE_INFO_E */
    UNI_QRY_GACASE_SUB_INFO           = 12, /**< ������Ϣ��ѯ(������֯),��Ӧ������#QRY_GACASE_INFO_E */

    UNI_QRY_MAX
}UNI_QUERY_FLAG_E;

/* Begin: added by zhangdong(kf0134), 2013.9.11 for ͨ�����ݿ��ѯ*/
/**
* @enum tagUniversalQueryFlag
* @brief ͨ�ò�ѯ��־λ
* @attention
*/
typedef enum tagUniversalQryFlag
{
    UNI_QUERY_TOTAL_COUNT_INFO = 0,   /**< ��ѯ�������������� */
    UNI_QUERY_SQL_STATEMENT_INFO = 1,  /**< ���ݿ�SQL ����ѯ */
    UNI_QUERY_STORAGE_PROCESS_INFO = 2, /**<  ���ݿ�洢���̲�ѯ */
    /* Begin added by z00758,2013-11-28 for ������������Ŵ� */
    UNI_EXECUTE_SQL_STATEMENT_INFO = 3,  /**< ���ݿ�SQL ���ִ�� */
    /* End added by z00758,2013-11-28 for ������������Ŵ� */

    UNI_QUERY_MAX
}UNIVERSAL_QUERY_FLAG_E;
/* End: added by zhangdong(kf0134), 2013.9.11 for ͨ�����ݿ��ѯ*/

/**
* @enum tagQryCamStorageInfo
* @brief ������洢��Ϣ��ѯ����
* @attention
*/
typedef enum tagQryCamStorageInfo
{
    CAMST_CAMERA_NAME = 0,    /**< ���������#IMOS_NAME_LEN */
    CAMST_CAMERA_CODE,        /**< ���������#IMOS_CODE_LEN */
    CAMST_RECODRD_DATE,       /**< �洢����#IMOS_TIME_LEN */
    CAMST_STORAGE_DEVNAME,    /**< �洢�豸����#IMOS_NAME_LEN */
    CAMST_STORAGE_DEVCODE,    /**< �洢�豸����#IMOS_CODE_LEN */
    CAMST_STORAGE_DEVTYPE,    /**< �洢�豸����#ULONG */
    CAMST_RECORD_HOUR0002,    /**< 00:00-02:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR0204,    /**< 02:00-04:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR0406,    /**< 04:00-06:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR0608,    /**< 06:00-08:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR0810,    /**< 08:00-10:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR1012,    /**< 10:00-12:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR1214,    /**< 12:00-14:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR1416,    /**< 14:00-16:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR1618,    /**< 16:00-18:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR1820,    /**< 18:00-20:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR2022,    /**< 20:00-22:00��Ĵ洢��Ϣ#ULONG */
    CAMST_RECORD_HOUR2224,    /**< 22:00-24:00��Ĵ洢��Ϣ#ULONG */
    CAMST_IS_CREATEPLAN,      /**< �Ƿ��ƶ��˴洢�ƻ�#ULONG */
    CAMST_IS_ENABELPLAN,      /**< �Ƿ������˴洢�ƻ�#ULONG */
    CAM_ST_MAX
}QRY_CAM_STORAGE_INFO_E;


typedef enum tagQryGACaseInfo
{
    GA_CASE_CODE            = 0,         /**< ��������#IMOS_CODE_LEN */
    GA_CASE_NAME            = 1,         /**< ��������#IMOS_NAME_LEN */
    GA_CASE_PROPERTY        = 2,         /**< ��������#CASE_PROPERTY_E */
    GA_CASE_TYPE            = 3,         /**< ��������#CASE_TYPE_E */
    GA_CASE_STATUS          = 4,         /**< ����״̬#CASE_STATUS_E */
    GA_CASE_POLICESRC       = 5,         /**< ������Դ#POLICE_INTELLIGENCE_SOURCE_ */
    GA_CASE_REPORTCODE      = 6,         /**< �Ӿ�����#IMOS_CODE_LEN */
    GA_CASE_REPORTTIME      = 7,         /**< �Ӿ�ʱ��#IMOS_TIME_LEN */
    GA_CASE_PROPERSON       = 8,         /**< ������#IMOS_NAME_LEN */
    GA_CASE_ENDANGERMENT    = 9,         /**< Σ���̶�#IMOS_NAME_LEN */
    GA_CASE_DESC            = 10,         /**< ��������#IMOS_CASE_DESC_LEN */
    GA_CASE_NOTE            = 11,         /**< ������ע#IMOS_NOTE_LEN */
    GA_CASE_BEGINTIME       = 12,         /**< ������ʼʱ��#IMOS_CODE_LEN */
    GA_CASE_ENDTIME         = 13,         /**< ��������ʱ��#IMOS_CODE_LEN */
    GA_CASE_CRIMEOPPERUNITY = 14,         /**< ����ʱ��#IMOS_TIME_LEN */
    GA_CASE_CRIMELOCATION   = 15,         /**< �����ص�#IMOS_TIME_LEN */
    GA_CASE_CRIMEPOSITION   = 16,         /**< ������λ#IMOS_NAME_LEN */
    GA_CASE_CRIMENUM        = 17,         /**< ��������#ULONG */
    GA_CASE_CRIMTARGET      = 18,         /**< ��������#IMOS_NAME_LEN */
    GA_CASE_CRIMSTYLE       = 19,         /**< �����ص�#IMOS_NAME_LEN */
    GA_CASE_DISTRICT        = 20,         /**< ����#IMOS_NAME_LEN */
    GA_CASE_STREET          = 21,         /**< �ֵ�#IMOS_NAME_LEN */
    GA_CASE_POLICEDISTRICT  = 22,         /**< ����#IMOS_NAME_LEN */
    GA_CASE_COMMUNITY       = 23,         /**< ����#IMOS_NAME_LEN */
    GA_CASE_ADDRESS         = 24,         /**< ��ϸ��ַ#IMOS_STRING_LEN_256 */
    GA_CASE_CREATOR         = 25,         /**< ������#IMOS_NAME_LEN */
    GA_CASE_ORGCODE         = 26,         /**< ������֯����#IMOS_CODE_LEN */
    GA_CASE_ORGNAME         = 27,         /**< ������֯����#IMOS_NAME_LEN */

    GA_RECODE_CODE          = 28,       /**< ¼�����#IMOS_CODE_LEN */
    GA_RECODE_NAME          = 29,       /**< ¼������#IMOS_NAME_LEN */
    GA_CAMERA_CODE          = 30,       /**< ���������#IMOS_CODE_LEN */
    GA_RECORD_BEGINTIME     = 31,       /**< ¼��ʼʱ��#IMOS_TIME_LEN */
    GA_RECODE_ENTIME        = 32,       /**< ¼�����ʱ��#IMOS_TIME_LEN */
    GA_RECODE_SIZE          = 33,       /**< ¼���С#ULONG */
    GA_RECODE_UPLOADTIME    = 34,       /**< ¼���ϴ�ʱ��#IMOS_TIME_LEN */
    GA_RECODE_UPLOADUSER    = 35,       /**< ¼���ϴ���#IMOS_NAME_LEN */
    GA_RECODE_NOTE          = 36,       /**< ¼��ע#IMOS_NOTE_LEN */

    GA_FILE_CODE            = 37,       /**< �ļ�����#IMOS_CODE_LEN */
    GA_FILE_NAME            = 38,       /**< �ļ�����#IMOS_NAME_LEN */
    GA_FILE_SIZE            = 39,       /**< �ļ���С#ULONG */
    GA_FILE_TYPE            = 40,       /**< �ļ�����#CASE_FILE_TYPE_E */
    GA_FILE_UPLOADTIME      = 41,       /**< �ļ��ϴ�ʱ��#IMOS_TIME_LEN */
    GA_FILE_UPLOADUSER      = 42,       /**< �ļ��ϴ���#IMOS_NAME_LEN */
    GA_FILE_NOTE            = 43,       /**< �ļ���ע#IMOS_NAME_LEN */

    GA_REPORTER_CODE        = 44,       /**< �����˱���#IMOS_CODE_LEN */
    GA_REPORTER_NAME        = 45,       /**< ����������#IMOS_NAME_LEN */
    GA_REPORTER_GENDER      = 46,       /**< �������Ա�#GENDER_TYPE_E */
    GA_REPORTER_MINAGE      = 47,       /**< ��������С���#ULONG */
    GA_REPORTER_MAXAGE      = 48,       /**< ������������#ULONG */
    GA_REPORTER_NATIVE      = 49,       /**< �����˼���#IMOS_NAME_LEN */
    GA_REPORTER_TELEPHONE   = 50,       /**< �����˵绰#IMOS_NAME_LEN */
    GA_REPORTER_COMPANY     = 51,       /**< �����˹�����λ#IMOS_PHONE_LEN */
    GA_REPORTER_NOTE        = 52,       /**< �����˱�ע#IMOS_NOTE_LEN */

    GA_STUFF_CODE           = 53,       /**< �永��Ʒ����#IMOS_CODE_LEN */
    GA_STUFF_NAME           = 54,       /**< �永��Ʒ����#IMOS_NAME_LEN */
    GA_STUFF_TYPE           = 55,       /**< �永��Ʒ����#CASE_STUFF_TYPE_E */
    GA_STUFF_PROPERTY       = 56,       /**< �永��Ʒ����#CASE_STUFF_PROPERTY_E */
    GA_STUFF_NOTE           = 57,       /**< �永��Ʒ��ע#IMOS_NOTE_LEN */

    GA_VEHICLE_CODE         = 58,       /**< �永��������#IMOS_NAME_LEN */
    GA_VEHICLE_COLOR        = 59,       /**< �永������ɫ#IMOS_NAME_LEN */
    GA_VEHICLE_TYPE         = 60,       /**< �永�����ͺ�#IMOS_NAME_LEN */
    GA_VEHICLE_FEATURE      = 61,       /**< �永��������#IMOS_NAME_LEN */
    GA_VEHICLE_LOCALIZATION = 62,       /**< �永����������#IMOS_NAME_LEN */
    GA_VEHICLE_CLASSIFICATE = 63,       /**< �永��������#IMOS_NAME_LEN */
    GA_VEHICLE_MANUFACTURER = 64,       /**< �永��������#IMOS_NAME_LEN */
    GA_VEHICLE_BEHAVIOR     = 65,       /**< �永������Ϊ#IMOS_NAME_LEN */
    GA_VEHICLE_PLATECODE    = 66,       /**< �永�������ƺ���#IMOS_NAME_LEN */
    GA_VEHICLE_PLATETYPE    = 67,       /**< �永������������#IMOS_NAME_LEN */
    GA_VEHICLE_PLATECOVER   = 68,       /**< �永���������ڵ�#IMOS_NAME_LEN */
    GA_VEHICLE_WINDOWFILM   = 69,       /**< �永������Ĥ#IMOS_NAME_LEN */
    GA_VEHICLE_NOTE         = 70,       /**< �永������ע#IMOS_NAME_LEN */

    GA_REFER_CODE           = 71,       /**< �永�˱���#IMOS_CODE_LEN */
    GA_REFER_NAME           = 72,       /**< �永������#IMOS_NAME_LEN */
    GA_REFER_GENDER         = 73,       /**< �永���Ա�#GENDER_TYPE_E */
    GA_REFER_MINAGE         = 74,       /**< �永����С���#ULONG */
    GA_REFER_MAXAGE         = 75,       /**< �永��������#ULONG */
    GA_REFER_NATIVE         = 76,       /**< �永�˼���#IMOS_NAME_LEN */
    GA_REFER_TELEPHONE      = 77,       /**< �永�˵绰#IMOS_NAME_LEN */
    GA_REFER_COMPANY        = 78,       /**< �永�˹�����λ#IMOS_NAME_LEN */
    GA_REFER_BEHAVIOR       = 79,       /**< �永����Ϊ#IMOS_NAME_LEN */
    GA_REFER_ACCENT         = 80,       /**< �永�˿���#IMOS_NAME_LEN */
    GA_REFER_BODYSHAPE      = 81,       /**< �永������#IMOS_NAME_LEN */
    GA_REFER_HEIGHT         = 82,       /**< �永�����#IMOS_NAME_LEN */
    GA_REFER_SKINCOLOR      = 83,       /**< �永�˷�ɫ#IMOS_NAME_LEN */
    GA_REFER_SHIRTSTYPE     = 84,       /**< �永�����¿�ʽ#IMOS_NAME_LEN */
    GA_REFER_SHIRTCOLOR     = 85,       /**< �永��������ɫ#IMOS_NAME_LEN */
    GA_REFER_SHIRTFRATURE   = 86,       /**< �永����������#IMOS_NAME_LEN */
    GA_REFER_SLEEVELENTH    = 87,       /**< �永�����䳤��#IMOS_NAME_LEN */
    GA_REFER_COLLAR         = 88,       /**< �永������#IMOS_NAME_LEN */
    GA_REFER_TROUSERS       = 89,       /**< �永�˿���#IMOS_NAME_LEN */
    GA_REFER_TROUSERSLENGTH = 90,       /**< �永�˿㳤#IMOS_NAME_LEN */
    GA_REFER_TROUSERSCOLOR  = 91,       /**< �永�˿�����ɫ#IMOS_NAME_LEN */
    GA_REFER_HAIRSTYLE      = 92,       /**< �永�˷���#IMOS_NAME_LEN */
    GA_REFER_HAIRCOLOR      = 93,       /**< �永�˷�ɫ#IMOS_NAME_LEN */
    GA_REFER_EYECLASS       = 94,       /**< �永���۾�#IMOS_NAME_LEN */
    GA_REFER_CAP            = 95,       /**< �永��ñ��#IMOS_NAME_LEN */
    GA_REFER_SCARF          = 96,       /**< �永��Χ��#IMOS_NAME_LEN */
    GA_REFER_BAG            = 97,       /**< �永�˰���#IMOS_NAME_LEN */
    GA_REFER_SHOESTYLE      = 98,       /**< �永��Ь��#IMOS_NAME_LEN */
    GA_REFER_SHOECOLOR      = 99,       /**< �永��Ь����ɫ#IMOS_NAME_LEN */
    GA_REFER_BODYSURFACE    = 100,
    GA_REFER_NOTE           = 101,

    GA_SERIES_CODE          = 102,      /**< ����������#IMOS_NAME_LEN */
    GA_SERIES_NAME          = 103,      /**< ����������#IMOS_NAME_LEN */
    GA_SERIES_NOTE          = 104,      /**< ��������ע#IMOS_NAME_LEN */

    GA_DEPT_CODE            = 105,      /**< ���ű���#IMOS_CODE_LEN */
    GA_DEPT_NAME            = 106,      /**< ��������#IMOS_NAME_LEN */
    GA_CASE_CREATETIME      = 107,      /**< ��������ʱ��#IMOS_TIME_LEN */
    GA_CASE_SOLVEDTIME      = 108,      /**< �����ư�ʱ��#IMOS_TIME_LEN */
    GA_CASE_CLOSEDTIME      = 109,      /**< �����᰸ʱ��#IMOS_TIME_LEN */
    GA_CASE_CRIMESPECIALTY  = 110,      /**< ���������ص�#*/
    GA_VEHICLE_PLATECOLOR   = 111,      /**< �永�����ĳ�����ɫ#IMOS_DICTIONARY_KEY_LEN */

    GA_CASE_MAX,
}QRY_GACASE_INFO_E;

/**
* @enum tagTVWallResolution
* @brief ����ǽ�ֱ�������
* @attention
*/
typedef enum tagTVWallResolution
{
    TW_RESOLUTION_1440_900                     = 0,                 /**< ����ǽ1440*900�ֱ��� */
    TW_RESOLUTION_1280_1024                    = 1,                 /**< ����ǽ1280*1024�ֱ��� */
    TW_RESOLUTION_1280_800                     = 2,                 /**< ����ǽ1280*800�ֱ��� */
    TW_RESOLUTION_1024_768                     = 3,                 /**< ����ǽ1024*768�ֱ��� */
    TW_RESOLUTION_MAX,                                              /**< ���ֵ */
    TW_RESOLUTION_INVALID                      = 0xFFFFFFFF         /**< ��Чֵ */
}TW_RESOLUTION_E;


/**
* @enum tagIMOSStreamServerMode
* @brief �����䷽ʽ
* @attention
*/
typedef enum tagIMOSStreamServerMode
{
    IMOS_STREAM_MODE_MS                 = 0,   /**< ָ��MS*/
    IMOS_STREAM_MODE_MS_AUTO            = 1,   /**< MS����Ӧ*/
    IMOS_STREAM_MODE_MS_BYPASS          = 2,   /**< ������MS */
    IMOS_STREAM_MODE_MS_BYPASS_FIRST    = 3,   /**< ֱ������ */

    IMOS_STREAM_MODE_BUTT
}IMOS_STREAM_SERVER_MODE_E;

/**
* @enum tagIMOSVODStreamServerMode
* @brief �����䷽ʽ
* @attention
*/
typedef enum tagIMOSVODStreamServerMode
{
    IMOS_VOD_STREAM_MODE_MS_NEEDED      = 1,   /**< ����Ӧ����MS */
    IMOS_VOD_STREAM_MODE_MS_BYPASS      = 2,   /**< ������MS*/

    IMOS_VOD_STREAM_MODE_BUTT
}IMOS_VOD_STREAM_SERVER_MODE_E;

/* Begin: Added by luhaitao/01337, 2014-11-12 for ǰ��¼��ط� */
/**
* @enum tagIMOSVODRecordMode
* @brief ¼��ط�ģʽ
* @attention
*/
typedef enum tagIMOSVODRecordMode
{
    IMOS_VOD_RECORD_MODE_CENTER_DOM     = 0,   /**< ������¼��ط� */
    IMOS_VOD_RECORD_MODE_FRONT_END      = 1,   /**< ǰ��¼��ط� */

    IMOS_VOD_RECORD_MODE_BUTT
}IMOS_VOD_RECORD_MODE_E;
/* End: Added by luhaitao/01337, 2014-11-12 for ǰ��¼��ط� */

/**
 * @enum tagOutChannelType
 * @brief ���ͨ������
 * @attention ��
 */
typedef enum tagOutChannelType
{
    OUT_CHANNEL_TYPE_VGA        = 0,            /**< VGA */

    OUT_CHANNEL_TYPE_MAX,                       /**< ���ֵ */
    OUT_CHANNEL_TYPE_INVALID    = 0xFFFFFFFF,   /**< ��Чֵ */
} OUT_CHANNEL_TYPE_E;

/**
 * @enum tagOutChannelMode
 * @brief ���ͨ��ģʽ
 * @attention ��
 */
typedef enum tagOutChannelMode
{
    OUT_CHANNEL_MODE_EXIT_FULL_SCREEN   = 0,            /**< �˳�ȫ�� */
    OUT_CHANNEL_MODE_FULL_SCREEN,                       /**< �Ŵ�ȫ�� */

    OUT_CHANNEL_MODE_MAX,                               /**< ���ֵ */
    OUT_CHANNEL_MODE_INVALID            = 0xFFFFFFFF,   /**< ��Чֵ */
} OUT_CHANNEL_MODE_E;


/**
 * @struct tagVinChnlBindCameraElement
 * @brief ����������ͨ���䳤Ԫ�ؽṹ��
 * @attention
 */
typedef enum tagVinChnlBindCameraVarietyElementID
{
    /** ����OSD */
    OSD_NAME_ELEMENT,

    /** �ڸ����� */
    MASK_AREA_ELEMENT ,

    /** ��Ƶ��  */
    VIDEO_STREAM_ELEMENT,

    /** �ڵ�������� */
    COVER_DETEC_AREA_ELEMENT,

    /** �˶�������� */
    MOTION_DETEC_AREA_ELEMENT,

    VARIETY_ELEMENT_ID_MAX
}VINCHNL_BIND_CAMERA_VARIETY_ELEMENT_ID_E;

/**
* @enum tagReaveStrategy
* @brief ��ռ���Զ���
* @attention
*/
typedef enum tagReaveStrategy
{
    REV_STRATEGY_PRI_AND_FIR               = 0,          /**< ���ȼ�+ͬ�������ȵ� */
    REV_STRATEGY_PRI_AND_SECOND            = 1,          /**< ���ȼ�+ͬ�������ȵ� */
    REV_STRATEGY_ONLINE_AND_PRI_AND_FIR    = 2,          /**< �����û�+���ȼ�+ͬ�������ȵ� */
    REV_STRATEGY_ONLINE_AND_PRI_AND_SECOND = 3,          /**< �����û�+���ȼ�+ͬ�������ȵ� */
    REV_STRATEGY_SECOND                    = 4,          /**< �����ȵ� */
    REV_STRATEGY_MAX,                                    /**< ���ֵ */
    REV_STRATEGY_INVALID                   = 0xFFFFFFFF  /**< ��Чֵ */
}REAVE_STRATEGY_E;

/**
* @enum tagReaveSrvType
* @brief ��ռ����ҵ�����Ͷ���
* @attention
*/
typedef enum tagReaveSrvType
{
    REV_SRV_MON_AND_VOD     = 0,            /**< ʵ���ࡢ�ط���ǽҵ�� */
    REV_SRV_PTZ             = 1,            /**< ��̨ҵ�� */
    REV_SRV_MAX,                            /**< ���ֵ */
    REV_SRV_INVALID         = 0xFFFFFFFF    /**< ��Чֵ */
}REAVE_SRV_TYPE_E;

/**
* @enum tagQueryFaultDeviceInfo
* @brief �����豸��Ϣ��ѯ
* @attention
*/
typedef enum tagQueryFaultDeviceInfo
{
    FDEV_DEV_CODE = 0,      /**< �豸����#IMOS_CODE_LEN */
    FDEV_DEV_NAME = 1,      /**< �豸����#IMOS_NAME_LEN */
    FDEV_DEV_TYPE = 2,      /**< �豸����#ULONG */
    FDEV_DEV_MODEL = 3,     /**< �豸������#IMOS_NAME_LEN */
    FDEV_DEV_IPADDR = 4,    /**< �豸��ַ#IMOS_IPADDR_LEN */
    FDEV_DOMAIN_CODE = 5,   /**< �����#IMOS_CODE_LEN */
    FDEV_DOMAIN_NAME = 6,   /**< ������#IMOS_NAME_LEN */
    FDEV_FAULT_TIME = 7,    /**< �豸����ʱ��#IMOS_TIME_LEN */
    FDEV_FAULT_TYPE = 8,    /**< �豸��������#ULONG */
    FDEV_MACADDR,           /**< �豸mac��ַ#IMOS_IPADDR_LEN */
    FDEV_PAR_ORG,           /**< ����֯����#IMOS_CODE_LEN */
    FDEV_MAX,
}QRY_FAULT_DEV_INFO_E;

/**
* @enum tagQueryFaultDeviceInfo
* @brief �����豸ͳ����Ϣ
* @attention
*/
typedef enum tagQueryFaultDeviceStat
{
    FDSTAT_DOMAIN_CODE = 0,     /**< �����#IMOS_CODE_LEN */
    FDSTAT_DOMAIN_NAME,         /**< ������#IMOS_NAME_LEN */
    FDSTAT_DEV_TYPE,            /**< �豸����#ULONG */
    FDSTAT_DEV_NUM,             /**< �豸����#ULONG */
    FDSTAT_FAULT_NUM,           /**< �豸��������#ULONG */
    FDSTAT_STAT_TIME ,          /**< �豸����ͳ��ʱ��#IMOS_TIME_LEN */
    FDSTAT_FAULT_RATE ,         /**< �豸������#FLOAT */
    FDSTAT_PAR_ORG,             /**< ����֯����#IMOS_CODE_LEN */
    FDSTAT_MAX,
}QRY_FAULT_DEV_STAT_E;

/**
* @enum tagQueryAssetInfo
* @brief �ʲ���Ϣ
* @attention
*/
typedef enum tagQueryAssetInfo
{
    QRY_ASSET_IMOSID = 0,           /**< ��ԴID#IMOS_ID */
    QRY_ASSET_CODE,                 /**< �ʲ����#IMOS_CODE_LEN */
    QRY_ASSET_NAME,                 /**< �ʲ�����#IMOS_NAME_LEN */
    QRY_ASSET_TYPE,                 /**< �ʲ�����#ULONG */
    QRY_ASSET_MODEL,                /**< �ʲ��ͺ�#IMOS_NAME_LEN */
    QRY_ASSET_STATUS,               /**< �ʲ�״̬#ULONG */
    QRY_ASSET_MANUFACTURE,          /**< �ʲ�����#IMOS_NAME_LEN */
    QRY_ASSET_PURCHASE_TIME,        /**< �ʲ��ɹ�ʱ��#IMOS_TIME_LEN */
    QRY_ASSET_WARRANT_TIME,         /**< �ʲ�����ʱ��#IMOS_TIME_LEN */
    QRY_ASSET_INSTALL_TIME,         /**< �ʲ���װʱ��#IMOS_TIME_LEN */
    QRY_ASSET_INSTALL_LOCATION,     /**< �ʲ���װ�ص�#IMOS_NAME_LEN */
    QRY_ASSET_MPERSON,              /**< ά����Ա#IMOS_NAME_LEN */
    QRY_ASSET_MTELEPHONE,           /**< ά�޵绰#IMOS_PHONE_LEN */
    QRY_ASSET_PRODEALER,            /**< ������#IMOS_NAME_LEN */
    QRY_ASSET_IPADDR,               /**< �ʲ�MAC��ַ#IMOS_IPADDR_LEN */
    QRY_ASSET_MACADDR,              /**< �ʲ�MAC��ַ#IMOS_NAME_LEN */
    QRY_ASSET_DEV_CODE,             /**< �ʲ��豸����#IMOS_CODE_LEN */
    QRY_ASSET_DEV_NAME,             /**< �ʲ��豸����#IMOS_NAME_LEN */
    QRY_ASSET_DOMAIN_CODE,          /**< �����#IMOS_CODE_LEN */
    QRY_ASSET_DOMAIN_NAME,          /**< ������#IMOS_NAME_LEN */
    QRY_ASSET_PARENT_ORG,           /**< �ʲ�����֯#IMOS_CODE_LEN */
    QRY_ASSET_COUNT,                /**< �ʲ�ͳ������#IMOS_NAME_LEN */
    QRY_ASSET_MAX,
}QRY_ASSET_INFO_E;


#if 0
/**
* @enum tagQueryAssetStat
* @brief �ʲ�ͳ����Ϣ
* @attention
*/
typedef enum tagQueryAssetStat
{
    ASSETSTAT_COUNT,                /**< �ʲ�ͳ������#ULONG */
    ASSETSTAT_TYPE,                 /**< �ʲ�����#ULONG */
    ASSETSTAT_STATUS,               /**< �ʲ�״̬#ULONG */
    ASSETSTAT_DOMAIN_CODE,          /**< �����#IMOS_CODE_LEN */
    ASSETSTAT_ORG1_NAME,            /**< һ����֯����#IMOS_NAME_LEN */
    ASSETSTAT_ORG2_NAME,            /**< ������֯����#IMOS_NAME_LEN */
    ASSETSTAT_ORG3_NAME,            /**< ������֯����#IMOS_NAME_LEN */
    ASSETSTAT_MAX,
}QRY_ASSET_STAT_E;
#endif

/**
* @enum tagAssetType
* @brief �ʲ�����ö��
* @attention
*/
typedef enum tagAssetType
{
    ASSET_TYPE_ALL              = 0,            /**< ���� */
    ASSET_TYPE_SERVER           = 1,            /**< ������ */

    ASSET_TYPE_FIX_CAMERA       = 5,            /**< �̶������ */
    ASSET_TYPE_PTZ_CAMERA       = 6,            /**< ��̨����� */
    ASSET_TYPE_FIX_CAMERA_HD    = 7,            /**< ����̶������ */
    ASSET_TYPE_PTZ_CAMERA_HD    = 8,            /**< ������̨����� */
    ASSET_TYPE_CAR_CAMERA       = 9,            /**< ��������� */


    ASSET_TYPE_DM               = 11,           /**< DM */
    ASSET_TYPE_MS               = 12,           /**< MS */
    ASSET_TYPE_VX500            = 13,           /**< VX500 */

    ASSET_TYPE_MONITOR          = 14,           /**< ������ */
    ASSET_TYPE_EC               = 15,           /**< ������ */
    ASSET_TYPE_DC               = 16,           /**< ������ */
    ASSET_TYPE_GENERAL          = 17,           /**< ͨ���豸 */
    ASSET_TYPE_ECR              = 18,           /**< ECR */

    ASSET_TYPE_TMS              = 30,           /**< ��ͨý�彻�������� */
    ASSET_TYPE_TOLLGATE         = 31,           /**< ���� */

    /* ��������������ͣ���501��ʼ */
    ASSET_TYPE_VIRTUAL              = 501,      /**< ��������� */
    ASSET_TYPE_BALL_NOT_CONTROL     = 502,      /**< ���ɿر������ */
    ASSET_HD_TYPE_BALL_NOT_CONTROL  = 503,      /**< ���ɿظ������ */
    ASSET_TYPE_SAFE_VM_CAMERA       = 504,      /**< ������Ƶ��������� */
    ASSET_TYPE_SAFE_DVR_CAMERA      = 505,      /**< DVR��Ƶ��������� */
    ASSET_TYPE_SAFE_MATRIX_CAMERA   = 506,      /**< ������Ƶ��������� */

    ASSET_TYPE_CAMERA           = 1001,         /**< ����� */
    ASSET_TYPE_AUDIO            = 1002,         /**< ʶ���� */
    ASSET_TYPE_IPSAN            = 1004,         /**< IPSAN */
    ASSET_TYPE_TOLLGATE_CAMERA  = 1005,         /**< ������� */

    ASSET_TYPE_BM               = 1300,         /**< BM */
    /* Begin added by y01359, 2015-08-18 for A8 */
    ASSET_TYPE_A8               = 1500,         /**< A8�豸 */
    /* End added by y01359, 2015-08-18 for A8 */
    ASSET_TYPE_MAX,                             /**< �ʲ�����ö�����ֵ */
    ASSET_TYPE_INVALID          = 0xFFFF        /**< ��Чֵ */
}ASSET_TYPE_E;

/**
* @enum tagAssetStatus
* @brief �ʲ�״̬ö��
* @attention
*/
typedef enum tagAssetStatus
{
    ASSET_STATUS_NORMAL      = 0,            /**< ���� */
    ASSET_STATUS_FAULT       = 1,            /**< �� */
    ASSET_STATUS_REPAIR      = 2,            /**< ά�� */
    ASSET_STATUS_RETIREMENT  = 3,            /**< ���� */
    ASSET_STATUS_STOCK       = 4,            /**< ��� */
    ASSET_STATUS_TOINSTALL   = 5,            /**< ����װ */
    ASSET_STATUS_INSTALLED   = 6,            /**< �Ѱ�װ */
    ASSET_STATUS_DEBUGGED    = 7,            /**< �ѵ��� */

    ASSET_STATUS_MAX,                        /**< �ʲ�״̬ö�����ֵ */
    ASSET_STATUS_INVALID     = 0xFF          /**< ��Чֵ */
}ASSET_STATUS_E;

/**
* @enum tagDevAssetBindPolicy
* @brief �豸�ʲ��󶨲���ö��
* @attention
*/
typedef enum tagDevAssetBindPolicy
{
    DEVASSET_BINDPOLICY_SEPARATE       = 0,       /**< �豸�ʲ�����¼�� */
    DEVASSET_BINDPOLICY_BIND           = 1,       /**< �豸�ʲ���¼�� */

    DEVASSET_BINDPOLICY_MAX,                      /**< �豸�ʲ��󶨲���ö�����ֵ */
    DEVASSET_BINDPOLICY_INVALID        = 0xFF     /**< ��Чֵ */
}DEVASSET_BINDPOLICY_E;

/**
* @enum tagAssetQueryType
* @brief �ʲ���ѯ��ʽö��
* @attention
*/
typedef enum tagAssetQueryType
{
    ASSET_QUERY_TYPE_DEVCODE       = 1,       /**< �����豸�����ѯ�ʲ� */
    ASSET_QUERY_TYPE_ASSETCODE     = 2,       /**< �����ʲ���Ų�ѯ�ʲ� */

    ASSET_QUERY_TYPE_MAX,                     /**< �ʲ���ѯ��ʽö�����ֵ */
    ASSET_QUERY_TYPE_INVALID       = 0xFF     /**< ��Чֵ */
}ASSET_QUERY_TYPE_E;


/**
* @enum tagStatisticServiceType
* @brief ͳ��ҵ������ö��
* @attention
*/
typedef enum tagStatisticServiceType
{
    STATISTIC_SERVICE_TYPE_ASSET   = 0,         /**< �ʲ�ͳ�� */
    STATISTIC_SERVICE_TYPE_FAULT   = 1,         /**< ����ͳ�� */
    STATISTIC_SERVICE_TYPE_DETAIL  = 2,         /**< �������� */

    STATISTIC_SERVICE_TYPE_MAX,                 /**< ͳ��ҵ������ö�����ֵ */
    STATISTIC_SERVICE_TYPE_INVALID = 0xFF      /**< ��Чֵ */
}STATISTIC_SERVICE_TYPE_E;


/**
* @enum tagStatisticClassificationType
* @brief ͳ�Ʒ�������ö��
* @attention
*/
typedef enum tagStatisticClassificationType
{
    STATISTIC_CLASSIFICATION_ASSETTYPE   = 0,         /**< ���ʲ����ͷ���ͳ�� */
    STATISTIC_CLASSIFICATION_ASSETMODEL  = 1,         /**< ���ʲ��ͺŷ���ͳ�� */

    STATISTIC_CLASSIFICATION_MAX,                     /**< ͳ�Ʒ�������ö�����ֵ */
    STATISTIC_CLASSIFICATION_INVALID = 0xFF           /**< ��Чֵ */
}STATISTIC_CLASSIFICATION_TYPE_E;

/**
* @enum tagSyncServiceType
* @brief ͬ��ҵ������ö��
* @attention
*/
typedef enum tagSyncServiceType
{
    SYNCSRV_TYPE_ASSET_STATISTIC   = 0,         /**< ͬ���ʲ�ͳ�� */
    SYNCSRV_TYPE_FAULT_STATISTIC   = 1,         /**< ͬ������ͳ�� */

    SYNCSRV_TYPE_MAX,                           /**< ͬ��ҵ������ö�����ֵ */
    SYNCSRV_TYPE_INVALID = 0xFF                 /**< ��Чֵ */
}SYNCSRV_TYPE_E;

/**
* @enum tagSyncSrvMode
* @brief ͬ��ģʽ����ö��
* @attention
*/
typedef enum tagSyncSrvMode
{
    SYNCSRV_MODE_INCREMENT   = 0,                /**< ����ͬ�� */
    SYNCSRV_MODE_TOTAL       = 1,                /**< ȫ��ͬ�� */

    SYNCSRV_MODE_MAX,                           /**< ͬ��ģʽö�����ֵ */
    SYNCSRV_MODE_INVALID = 0xFF                 /**< ��Чֵ */
}SYNCSRV_MODE_E;

/**
* @enum tagSplitScrMode
* @brief ����������ģʽ
* @attention
*/
typedef enum tagSplitScrMode
{
    SPLIT_SCR_MODE_0    = 0,    /**< �����ַ� */
    SPLIT_SCR_MODE_1    = 1,    /**< ȫ�� */
    SPLIT_SCR_MODE_2    = 2,    /**< 2 ����*/
    SPLIT_SCR_MODE_3    = 3,    /**< 3 ����*/
    SPLIT_SCR_MODE_4    = 4,    /**< 4���� */
    SPLIT_SCR_MODE_5    = 5,    /**< 5 ����*/
    SPLIT_SCR_MODE_6    = 6,    /**< 6���� */
    SPLIT_SCR_MODE_7    = 7,    /**< 7 ����*/
    SPLIT_SCR_MODE_8    = 8,    /**< 8 ���� */
    SPLIT_SCR_MODE_9    = 9,    /**< 9 ���� */
    SPLIT_SCR_MODE_10   = 10,   /**< 10 ���� */
    SPLIT_SCR_MODE_11   = 11,    /**< 11 ����*/
    SPLIT_SCR_MODE_12   = 12,    /**< 12 ����*/
    SPLIT_SCR_MODE_13   = 13,   /**< 13 ���� */
    SPLIT_SCR_MODE_14   = 14,    /**< 14 ����*/
    SPLIT_SCR_MODE_15   = 15,    /**< 15 ����*/
    SPLIT_SCR_MODE_16   = 16,   /**< 16 ���� */
    SPLIT_SRC_MODE_25   = 25,   /**< 25����*/
    SPLIT_SRC_MODE_36   = 36,   /**< 36����*/

    SPLIT_SCR_MODE_MAX,                     /**< ���ֵ */

    /* Begin modified by l01420 for MPPD08374, 2014-4-8 */
    /**<SPLIT_SCR_MODE_MAXö��ֵ���϶������·�������ģʽ��
    �����������ֵ��ʾ����ķ���ģʽ(�������ظ���ģʽ��ͬ)*/
    SPLIT_SCR_MODE_80    = 80,    /**< 8 ���� ����ģʽ */

    SPLIT_SCR_MODE_LIMIT_VALUE ,/**<����ģʽ���ֵ*/
    /* End modified by l01420 for MPPD08374, 2014-4-8 */

    SPLIT_SCR_MODE_INVALID  = 0xFFFFFFFF    /**< ��Чֵ */
} SPLIT_SCR_MODE_E;

/**
 * @struct tagECRServerModeType
 * @brief ECR�豸����ģʽ����
 * @attention
 */
typedef enum tagECRServerModeInfo
{
    ECR_SERVER_MODE_TYPE_INDEPENDENT = 0,  /**< ��������ģʽ */
    ECR_SERVER_MODE_TYPE_SERVER = 1,       /**< ����������ģʽ */

    ECR_SERVER_MODE_TYPE_MAX,              /**< ����ģʽ���ֵ */
    ECR_SERVER_MODE_TYPE_INVALID = 0xFF
}ECR_SERVER_MODE_TYPE_E;

/**
* ��Ƶ����
*/
/**
* @enum     tagOnvifVideoEncoding
* @brief    ONVIF ��Ƶ����
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
* ��Ƶ����
*/

/**
* @enum     tagOnvifAudioEncoding
* @brief    ONVIF ��Ƶ����
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
* ͼ���������
*/

/**
* @enum     tagOnvifBacklightCompensationMode
* @brief    ONVIF �ع�ģʽ
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
* @brief    ONVIF �ع�ģʽ
* @attention
*/
typedef enum tagOnvifExposureMode
{
    ONVIF_EXPOSURE_MODE_AUTO = 0,           /**< �Զ��ع� */
    ONVIF_EXPOSURE_MODE_MANUAL,             /**< �ֶ��ع� */
    ONVIF_EXPOSURE_MODE_MAX,
    ONVIF_EXPOSURE_MODE_INVALID = 0xFFFF
}ONVIF_EXPOSURE_MODE_E;

/**
* @enum     tagOnvifExposurePriority
* @brief    ONVIF �ع����ȼ�
* @attention
*/
typedef enum tagOnvifExposurePriority
{
    ONVIF_EXPOSURE_PRIORITY_LOW_NOISE = 0,          /**< ���������� */
    ONVIF_EXPOSURE_PRIORITY_FRAME_RATE,             /**< ֡������ */
    ONVIF_EXPOSURE_PRIORITY_MAX,
    ONVIF_EXPOSURE_PRIORITY_INVALID = 0xFFFF
}ONVIF_EXPOSURE_PRIORITY_E;

/**
* @enum     tagOnvifFocusMode
* @brief    ONVIF �۽�ģʽ
* @attention
*/
typedef enum tagOnvifFocusMode
{
    ONVIF_FOCUS_MODE_AUTO = 0,           /**< �Զ��۽� */
    ONVIF_FOCUS_MODE_MANUAL,             /**< �ֶ��۽� */
    ONVIF_FOCUS_MODE_MAX,
    ONVIF_FOCUS_MODE_INVALID = 0xFFFF
}ONVIF_FOCUS_MODE_E;

/**
* @enum     tagOnvifIrCutFilter
* @brief    ONVIF �����ֹ�˹�
* @attention
*/
typedef enum tagOnvifIrCutFilter
{
    ONVIF_INFRARED_CUTOFF_FILTER_ON = 0,            /**< �� */
    ONVIF_INFRARED_CUTOFF_FILTER_OFF,               /**< �ر� */
    ONVIF_INFRARED_CUTOFF_FILTER_AUTO,              /**< �Զ� */
    ONVIF_INFRARED_CUTOFF_FILTER_MAX,
    ONVIF_INFRARED_CUTOFF_FILTER_INVALID = 0xFFFF
}ONVIF_INFRARED_CUTOFF_FILTER_E;

/**
* @enum     tagOnvifWideDynamicMode
* @brief    ONVIF WDRģʽ
* @attention
*/
typedef enum tagOnvifWideDynamicMode
{
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_OFF = 0,          /**< �ر� */
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_ON,               /**< �� */
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_MAX,
    ONVIF_WIDE_DYNAMIC_RANGE_MODE_INVALID = 0xFFFF
}ONVIF_WIDE_DYNAMIC_RANGE_MODE_E;

/**
* @enum     tagOnvifWideDynamicMode
* @brief    ONVIF ��ƽ��ģʽ
* @attention
*/
typedef enum tagOnvifWhiteBalanceMode
{
    ONVIF_WHITE_BALANCE_MODE_AUTO = 0,          /**< �Զ���ƽ�� */
    ONVIF_WHITE_BALANCE_MODE_MANUAL,            /**< �ֶ���ƽ�� */
    ONVIF_WHITE_BALANCE_MODE_MAX,
    ONVIF_WHITE_BALANCE_MODE_INVALID = 0xFFFF
}ONVIF_WHITE_BALANCE_MODE_E;

/**
* ONVIF OSD��ض���
*/
/**
* @enum     tagOnvifOSDType
* @brief    OSD����
* @attention
*/
typedef enum tagOnvifOSDType
{
    ONVIF_OSD_TYPE_TEXT = 0,            /**< �ı� */
    ONVIF_OSD_TYPE_IMAGE,               /**< ͼƬ */
    ONVIF_OSD_TYPE_MAX,
    ONVIF_OSD_TYPE_INVALID = 0xFFFF
}ONVIF_OSD_TYPE_E;

/**
* @enum     tagOnvifOSDTextStringType
* @brief    ONVIF OSD text����
* @attention
*/
typedef enum tagOnvifOSDTextStringType
{
    ONVIF_OSD_TEXT_STRING_TYPE_PLAIN = 0,          /**< ��ͨ�ı� */
    ONVIF_OSD_TEXT_STRING_TYPE_DATE,               /**< ���� */
    ONVIF_OSD_TEXT_STRING_TYPE_TIME,               /**< ʱ�� */
    ONVIF_OSD_TEXT_STRING_TYPE_DATE_TIME,          /**< ����+ʱ�� */
    ONVIF_OSD_TEXT_STRING_TYPE_MAX,
    ONVIF_OSD_TEXT_STRING_TYPE_INVALID = 0xFFFF
}ONVIF_OSD_TEXT_STRING_TYPE_E;

/**
* @enum     tagMwStdOnvifIPType
* @brief    onvif IP ����
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
* @brief ��ͼ����ö��
* @attention
*/
typedef enum tagMapType
{
    MAP_TYPE_JPG   = 0,    /**< JPG��ͼ */
    MAP_TYPE_SVG,          /**< SVG��ͼ */
    MAP_TYPE_JPEG,         /**< JPEG��ͼ */
    MAP_TYPE_BMP,          /**< BMP��ͼ */
    MAP_TYPE_SHP,          /**< SHP��ͼ */

    MAP_TYPE_MAX,          /**< Ŀǰ֧�ֵĵ�ͼ�������ֵ */
    MAP_TYPE_INVALID    = 0xFFFFFFFF,   /**< ��Чֵ */
}MAP_TYPE_E;

/**
* @enum tagDomainSynServiceType
* @brief ���ͬ����ҵ������ö��
* @attention
*/
typedef enum tagDomainSynServiceType
{
    DOMAIN_SYN_TOPO_FILE = 1,   /**< ����ļ� */
    DOMAIN_SYN_TOPO_SRVNUM,     /**< ҵ����Ϣ */
    DOMAIN_SYN_DEV_FAULT,       /**< �豸����������Ϣ */
    DOMAIN_SYN_FAULT_DEV,       /**< �����豸ͳ�� */
    DOMAIN_SYN_ASSET,           /**< �ʲ���Ϣ */

    DOMAIN_SYN_MAX,             /**< ͬ��ҵ���������ֵ */
    DOMAIN_SYN_INVALID = 0XFF
}DOMAIN_SYN_SRVTYPE_E;

/**
* @enum tagIMOSSystemParamType
* @brief ϵͳ��������
* @attention
*/
typedef enum tagIMOSSystemParamType
{
    ALARM_LINKAGE_MONITOR_RESUME_ENABLE       = 1,                /**< �澯�������������Ļָ����� */
    ALARM_LINKAGE_MONITOR_RESUME_TIME         = 2,                /**< �澯�������������Ļָ�ʱ��, ��λ:�� */
    SYS_PARAM_PLATE_CODE_PREFIX               = 3,                /**< ���ƺ���ǰ׺ */
    SYS_PARAM_VEHICLE_ALARM_PHOTO_FULL_POLICY = 4,                /**< �����澯ͼƬ������:0-��ֹͣ��1-������ */
    SYS_PARAM_VEHICLE_ALARM_RECORD_BACKUP_ENABLE = 5,             /**< Υ��¼�񱸷�ʹ�� */
    SYS_PARAM_VEHICLE_RECORD_BEFORE_TIME         = 6,             /**< ����ǰ¼��ط����� */
    SYS_PARAM_VEHICLE_RECORD_AFTER_TIME          = 7,             /**< ������¼��ط����� */
    SYS_PARAM_TMS_BIGDATA_REALTIME_INDEX         = 8,             /**< ������ʵʱ����ʹ�� */
    SYS_PARAM_TMS_REV_BUFFER                     = 9,             /**< TMS���ݽ������ȼ� */
    SYS_PARAM_TMS_COMBINE_PIC_TYPE               = 10,            /**< TMS�����ϳ�ͼƬ�������� */

    SYS_PARAM_ONVIF_SERVER_USER                  = 11,            /**< onvif server �û��� */
    SYS_PARAM_ONVIF_SERVER_PASSWD                = 12,            /**< onvif server ���� */
    SYS_PARAM_ONVIF_SERVER_BIND_MS               = 13,            /**< onvif server ��ms */

	SYS_PARAM_AUTO_RETRY_BACK_TASK               = 14,            /**<���������Զ����� */

    SYS_PARAM_MAX,                                              /**< ���ֵ */
    SYS_PARAM_INVALID                       = 0xFFFF            /**< ��Чֵ */
}IMOS_SYS_PARAM_TYPE_E;

/**
* @enum tagVocEventType
* @brief ����֪ͨ�¼�������
* @attention ��
*/
typedef enum tagVocEventType
{
    VOC_EVENT_TYPE_USER_STOP       = 0,   /**< ����ҵ���û�ֹͣ */
    VOC_EVENT_TYPE_REAVE           = 1,   /**< ����ҵ����ռ */
    VOC_EVENT_TYPE_SERVER_STOP     = 2,   /**< ����ҵ�������������ֹͣ */
    VOC_EVENT_TYPE_SERVER_BE_STOP  = 3,   /**< ����ҵ��������˱���ֹͣ */

    VOC_EVENT_TYPE_MAX,
    VOC_EVENT_TYPE_INVALID = 0xFFFFFFFF
}VOC_EVENT_TYPE_E;

/**
* @enum tagVocEventType
* @brief ����ҵ��״̬
* @attention ��
*/
typedef enum tagVocSrvStatus
{
    VOCSRV_STATUS_IDLE    = 0,    /**< û������ҵ�� */
    VOCSRV_STATUS_SETUP   = 1,    /**< ����ҵ�����ڽ����� */
    VOCSRV_STATUS_ACTIVE  = 2,    /**< ����ҵ�����ɹ� */

    VOCSRV_STATUS_MAX,
    VOCSRV_STATUS_INVALID = 0xFFFFFFFF
}VOCSRV_STATUS_E;

/**
* @enum tagAlarmRecordType
* @brief �澯�����¼����
* @attention
*/
typedef enum tagAlarmRecordType
{
    ALARM_RECORD_TYPE_TRIGGER           = 1,    /**< ������ */
    ALARM_RECORD_TYPE_EXECUTE_TASK      = 2,    /**< ִ������ */
    ALARM_RECORD_TYPE_CANCEL_TASK       = 3,    /**< ȡ������ */
    ALARM_RECORD_TYPE_PLAN_ALARM_PUSH   = 4,    /**< Ԥ���澯���� */
    ALARM_RECORD_TYPE_ALARM_NEW_ALARM   = 5,    /**< �����¸澯 */
    ALARM_RECORD_TYPE_PLAN_BEGIN        = 6,    /**< Ԥ������ */
    ALARM_RECORD_TYPE_PLAN_END          = 7,    /**< Ԥ������ */

    ALARM_RECORD_TYPE_MAX,
    ALARM_RECORD_TYPE_INVALID = 0xFFFFFFFF
}ALARM_RECORD_TYPE_E;


/**
* @enum tagActionPlanType
* @brief Ԥ������
* @attention
*/
typedef enum tagActionPlanType
{
    ACTION_PLAN_TYPE_ALARM = 1,                /**< �澯Ԥ�� */
    ACTION_PLAN_TYPE_COMMON = 2,               /**< ͨ��Ԥ�� */

    ACTION_PLAN_TYPE_MAX,                      /**< ���ֵ */
    ACTION_PLAN_TYPE_INVALID = 0xFFFFFFFF      /**< ��Чֵ */
}ACTION_PLAN_TYPE_E;

/**
* @enum tagAlarmStatus
* @brief �澯״̬
* @attention
*/
typedef enum tagAlarmStatus
{
    ALARM_STATUS_NOT_CONFIRM            = 0,    /**< δȷ�� */
    ALARM_STATUS_ALREADY_CONFIRM        = 1,    /**< ��ȷ�� */
    ALARM_STATUS_NOT_CHECK              = 2,    /**< δ�˾� */
    ALARM_STATUS_ALREADY_CHECK          = 3,    /**< �Ѻ˾� */

    ALARM_STATUS_MAX,
    ALARM_STATUS_INVALID = 0xFFFFFFFF
}ALARM_STATUS_E;


/**
* @enum tagTaskDealMode
* @brief ������ģʽ
* @attention
*/
typedef enum tagTaskDealMode
{
    TASK_DEAL_MODE_EXECUTE          = 1,    /**< ִ������ */
    TASK_DEAL_MODE_CANCEL           = 2,    /**< ȡ������ */

    TASK_DEAL_MODE_MAX,
    TASK_DEAL_MODE_INVALID = 0xFFFFFFFF
}TASK_DEAL_MODE_E;

/**
* @enum tagPlanAlarmChgType
* @brief Ԥ���澯�仯��������
* @attention
*/
typedef enum tagPlanAlarmChgType
{
    PLAN_ALARM_CHG_TYPE_ADD             = 1,    /**< Ԥ���澯���� */
    PLAN_ALARM_CHG_TYPE_TASK_CHG        = 2,    /**< Ԥ���澯����仯 */
    PLAN_ALARM_CHG_TYPE_DEL             = 3,    /**< Ԥ���澯ɾ�� */

    PLAN_ALARM_CHG_TYPE_MAX,
    PLAN_ALARM_CHG_TYPE_INVALID = 0xFFFFFFFF
}PLAN_ALARM_CHG_TYPE_E;

/**
* @enum tagPlanExecStrategy
* @brief Ԥ��ִ�в���
* @attention
*/
typedef enum tagPlanExecStrategy
{
    PLAN_EXEC_STRATEGY_STRICT_ORDER     = 1,    /**< �ϸ�˳��ִ�� */
    PLAN_EXEC_STRATEGY_RAND_ORDER       = 2,    /**< �������ִ�� */
    PLAN_EXEC_STRATEGY_AUTO_CANCEL_TASK = 3,    /**< �Զ�ȡ��ǰ��δִ������ */

    PLAN_EXEC_STRATEGY_MAX,
    PLAN_EXEC_STRATEGY_INVALID = 0xFFFFFFFF
}PLAN_EXEC_STRATEGY_E;

/**
* @enum tagTaskExecStrategy
* @brief ����ִ�в���
* @attention
*/
typedef enum tagTaskExecStrategy
{
    TASK_EXEC_STRATEGY_AUTO             = 1,    /**< �Զ� */
    TASK_EXEC_STRATEGY_MANUAL_YES       = 2,    /**< �ֶ�Ĭ��ִ�� */
    TASK_EXEC_STRATEGY_MANUAL_NO        = 3,    /**< �ֶ�Ĭ�ϲ�ִ�� */

    TASK_EXEC_STRATEGY_MAX,
    TASK_EXEC_STRATEGY_INVALID = 0xFFFFFFFF
}TASK_EXEC_STRATEGY_E;

/**
* @enum tagTriggerID
* @brief ������ID
* @attention
*/
typedef enum tagTriggerID
{
    TRIGGER_ID_CONFIRM          = 1,    /**< ȷ�� */
    TRIGGER_ID_INFORM           = 2,    /**< �˾�Ϊ���� */
    TRIGGER_ID_MISINFORM        = 3,    /**< �˾�Ϊ�� */
    TRIGGER_ID_IMMEDIATELY      = 4,    /**< ���� */
    TRIGGER_ID_TIMING           = 5,    /**< ��ʱ */

    TRIGGER_ID_MAX,
    TRIGGER_ID_INVALID = 0xFFFFFFFF
}TRIGGER_ID_E;

/**
* @enum tagQuerySysInfoName
* @brief ��ѯϵͳ��Ϣ����
* @attention
*/
typedef enum tagQuerySysInfoName
{
    QUERY_SYS_TIME              = 1,    /**< ʱ�䣨��ʽΪ"YYYY-MM-DD HH:MM:SS"��*/
    QUERY_SYS_CPU_USAGE         = 2,    /**< cpuʹ���ʣ�����ΪFLOAT������С�������λ��*/
    QUERY_SYS_MEM_TOTAL         = 3,    /**< �ڴ�����������ΪULONG����λΪKB��*/
    QUERY_SYS_MEM_USAGE         = 4,    /**< �ڴ�ʹ���ʣ�����ΪFLOAT������С�������λ��*/

    QUERY_SYS_INFO_NAME_MAX,
    QUERY_SYS_INFO_NAME_INVALID = 0xFFFFFFFF
}QUERY_SYS_INFO_NAME_E;


/** @brief ����Ŵ�Э������ */
typedef enum tagZoomProtocol
{
    ZOOM_GENERAL          = 0,                      /**ͨ��Э��*/
    ZOOM_SPECIAL          = 1,                      /**ר��Э��*/
    ZOOM_GONGAN           = 2,                      /**����Э��*/
    ZOOM_INTELLIGENT      = 3,                      /**����Э��*/

    ZOOM_PROTOCOL_MAX,                              /** ���ֵ*/
    ZOOM_PROTOCOL_MAX_INVALID = 0xFFFFFFFF
}ZOOM_PROTOCOL_E;

/**
* @enum tagMonFavStreamAnyMatchPolicy
* @brief ʵ������Ӧ��������ƥ�����
* @attention ����Ĭ����������, ����Ĭ�ϸ�������
*/
typedef enum tagMonFavStreamAnyMatchPolicy
{
    MON_STREAM_ANY_MATCH_SEC_FIRST = 0,                 /**< ��������, ƥ�����:���������������� */
    MON_STREAM_ANY_MATCH_PRI_FIRST = 1,                 /**< ��������, ƥ�����:���������������� */
    MON_STREAM_ANY_MATCH_THD_FIRST = 2,                 /**< ��������, ƥ�����:���������������� */
    MON_STREAM_ANY_MATCH_BUTT
}MON_STREAM_ANY_MATCH_POLICY_E;

/**
* @enum tagMCastAddrStreamPolicy
* @brief �鲥��ַ��������ѡ�����
* @attention Ĭ������ʹ���鲥��ַ
*/
typedef enum tagMCastAddrStreamPolicy
{
    MCAST_ADDR_STREAM_POLICY_PRI = 0,                   /**< ������ʹ���鲥��ַ */
    MCAST_ADDR_STREAM_POLICY_SEC = 1,                   /**< ������ʹ���鲥��ַ, �޸��������, ����ʹ���鲥��ַ */
    MCAST_ADDR_STREAM_POLICY_THD = 2,                   /**< ������ʹ���鲥��ַ, �����������, ����ʹ���鲥��ַ */
    MCAST_ADDR_STREAM_POLICY_BUTT
}MCAST_ADDR_STREAM_POLICY_E;

/**
* @enum tagMCastAddrStreamPolicy
* @brief �ڶ����鲥��ַ��������ѡ�����
* @attention Ĭ�Ϲر�
*/
typedef enum tagSecondMCastAddrStreamPolicy
{
    SECOND_MCAST_ADDR_STREAM_POLICY_CLOSED = 0,
    SECOND_MCAST_ADDR_STREAM_POLICY_PRI = 1,                   /**< ����ʹ���鲥��ַ */
    SECOND_MCAST_ADDR_STREAM_POLICY_SEC = 2,                   /**< ����ʹ���鲥��ַ */
    SECOND_MCAST_ADDR_STREAM_POLICY_THD = 3,                   /**< ����ʹ���鲥��ַ */
    SECOND_MCAST_ADDR_STREAM_POLICY_BUTT
}SECOND_MCAST_ADDR_STREAM_POLICY_E;

/**
* @enum tagDomainStreamPullType
* @brief ���������ʶ����
* @attention
*/
typedef enum tagDomainStreamPullType
{
    DOMAIN_STREAM_PULL_NONE         = 0,    /**< ������ */
    DOMAIN_STREAM_PULL_IN           = 1,    /**< ���� */
    DOMAIN_STREAM_PULL_OUT          = 2,    /**< ��������(�ϼ�����Nat�ڵ����) */
    DOMAIN_STREAM_PULL_AND_URL_EX   = 3,    /**< ����֧�ֻط�URL�滻(�¼��򲦺Ž��룬IP��ַ��̬�仯���������ú��¼�������DM�Ļط�Nat������Ч */
    DOMAIN_STREAM_PULL_DOUBLE_NAT_OUT         = 4,   /**< ˫˽��(�¼�����˫˽����������˺�TCP�ķ����)�����������൱��������NAT��(����4S��ģ��) */
    DOMAIN_STREAM_PULL_DOUBLE_NAT_IN          = 5,   /**< ˫˽��(�¼�����˫˽�������ͻ��˺�TCP�Ŀͻ���)�����������൱��������NAT��(ȫ������ģ��)*/
	DOMAIN_STREAM_PULL_BUTT

}DOMAIN_STREAM_PULL_TYPE;


/**
* @enum tagXPStreamPullType
* @brief XP������ʶ����
* @attention
*/
typedef enum tagXPStreamPullType
{
    XP_STREAM_PULL_AUTO         = 0,    /**< ����Ӧ */
	XP_STREAM_PULL_NONE         = 1,    /**< ������ */
    XP_STREAM_PULL_IN           = 2,    /**< ���� */
    XP_STREAM_PULL_OUT          = 3,    /**< ��������(�ϼ�����Nat�ڵ����) */
    XP_STREAM_PULL_AND_URL_EX   = 4,    /**< ����֧�ֻط�URL�滻(�¼��򲦺Ž��룬IP��ַ��̬�仯���������ú��¼�������DM�Ļط�Nat������Ч */
    XP_STREAM_PULL_DOUBLE_NAT_OUT         = 5,   /**< ˫˽��(�¼�����˫˽����������˺�TCP�ķ����)�����������൱��������NAT��(����4S��ģ��) */
    XP_STREAM_PULL_DOUBLE_NAT_IN          = 6,   /**< ˫˽��(�¼�����˫˽�������ͻ��˺�TCP�Ŀͻ���)�����������൱��������NAT��(ȫ������ģ��)*/
	XP_STREAM_PULL_BUTT

}XP_STREAM_PULL_TYPE;


/** @brief Э��澯���͵ĸ澯״̬ */
typedef enum tagProtocolAlarmStatus
{
    PROTOCOL_ALARM_STATUS_RECOVER          = 0,     /** �ָ� */
    PROTOCOL_ALARM_STATUS_CREATE           = 1,     /** ���� */

    PROTOCOL_ALARM_STATUS_MAX,                    /** ���ֵ*/
    PROTOCOL_ALARM_STATUS_INVALID = 0xFFFFFFFF
}PROTOCOL_ALARM_STATUS_E;


/**
* @enum tagEventSecurityChgType
* @brief �¼�������Ϣ�仯��������
* @attention
*/
typedef enum tagEventSecurityChgType
{
    EVENT_SECURITY_CHG_TYPE_ADD             = 1,    /**< �¼��������� */
    EVENT_SECURITY_CHG_TYPE_MOD             = 2,    /**< �¼������޸� */
    EVENT_SECURITY_CHG_TYPE_DEL             = 3,    /**< �¼�����ɾ�� */

    EVENT_SECURITY_CHG_TYPE_MAX,
    EVENT_SECURITY_CHG_TYPE_INVALID = 0xFFFFFFFF
}EVENT_SECURITY_CHG_TYPE_E;

/**
* @enum tagAssetStatus
* @brief ��������ö��
* @attention
*/
typedef enum tagCaseProperty
{
    CASE_PROPERTY_CASE_PUBSECURITY      = 0,     /**< �ΰ� */
    CASE_PROPERTY_CASE_CRIMINAL         = 1,     /**< ���� */
    CASE_PROPERTY_POLICE_INTELLIGENCE   = 2,     /**< ���� */

    CASE_PROPERTY_MAX,                           /**< ��������ö�����ֵ */
    CASE_PROPERTY_INVALID     = 0xFF             /**< ��Чֵ */
}CASE_PROPERTY_E;


/**
* @enum tagCaseType
* @brief ��������ö��
* @attention
*/
typedef enum tagCaseType
{
    CASE_TYPE_THEFT                 = 0,     /**< ͵�� */
    CASE_TYPE_ROBBERY               = 1,     /**< ���� */
    CASE_TYPE_FIGHT                 = 2,     /**< ��Ź */
    CASE_TYPE_GAMBLING              = 3,     /**< �Ĳ� */
    CASE_TYPE_PUBLIC_DISTURBANCE    = 4,     /**< �ƻ��������� */
    CASE_TYPE_OTHER                 = 5,     /**< ���� */

    CASE_TYPE_MAX,                           /**< ��������ö�����ֵ */
    CASE_TYPE_INVALID     = 0xFF             /**< ��Чֵ */
}CASE_TYPE_E;

/**
* @enum tagCaseStatus
* @brief ����״̬ö��
* @attention
*/
typedef enum tagCaseStatus
{
    CASE_STATUS_PROCESSING            = 0,     /**< ������ */
    CASE_STATUS_CLOSED                = 1,     /**< �ѽ᰸ */
    CASE_STATUS_CANCELLATION          = 2,     /**< ���� */
    CASE_STATUS_SOLVED                = 3,     /**< ���ư� */

    CASE_STATUS_MAX,                           /**< ����״̬ö�����ֵ */
    CASE_STATUS_INVALID     = 0xFF             /**< ��Чֵ */
}CASE_STATUS_E;

/**
* @enum tagPoliceIntelligenceSource
* @brief ������Դö��
* @attention
*/
typedef enum tagPoliceIntelligenceSource
{
    POLICE_INTELLIGENCE_SOURCE_CAPTURE           = 0,     /**< �ֳ�ץ�� */
    POLICE_INTELLIGENCE_SOURCE_RECPLAYBACK       = 1,     /**< ¼��ط� */
    POLICE_INTELLIGENCE_SOURCE_110               = 2,     /**< 110���� */
    POLICE_INTELLIGENCE_SOURCE_POLICESTATION     = 3,     /**< �ɳ������� */
    POLICE_INTELLIGENCE_SOURCE_PMSYS             = 4,     /**< ����ϵͳ */

    POLICE_INTELLIGENCE_SOURCE_MAX,                       /**< ������Դö�����ֵ */
    POLICE_INTELLIGENCE_SOURCE_INVALID     = 0xFF         /**< ��Чֵ */
}POLICE_INTELLIGENCE_SOURCE_E;


/**
* @enum tagCasePersonnelType
* @brief ������Ա����ö��
* @attention
*/
typedef enum tagCasePersonnelType
{
    CASE_PERSONNEL_TYPE_REPORTER      = 0,     /**< ������ */
    CASE_PERSONNEL_TYPE_SUSPECT       = 1,     /**< ������ */
    CASE_PERSONNEL_TYPE_PARTY         = 2,     /**< ������ */
    CASE_PERSONNEL_TYPE_INVOLVER      = 3,     /**< �永�ˣ���ѯ�б�ʱʹ�ã����������˺͵����� */

    CASE_PERSONNEL_TYPE_MAX,                   /**< ������Ա����ö�����ֵ */
    CASE_PERSONNEL_TYPE_INVALID     = 0xFF     /**< ��Чֵ */
}CASE_PERSONNEL_TYPE_E;

/**
* @enum tagGenderType
* @brief ��Ա�Ա�ö��
* @attention
*/
typedef enum tagGenderType
{
    GENDER_TYPE_MALE      = 0,     /**< ���� */
    GENDER_TYPE_FEMALE    = 1,     /**< Ů�� */
    GENDER_TYPE_UNKNOWN   = 2,     /**< δ֪ */

    GENDER_TYPE_MAX,               /**< ��Ա�Ա�ö�����ֵ */
    GENDER_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}GENDER_TYPE_E;

/**
* @enum tagCaseStuffType
* @brief ������Ʒ����ö��
* @attention
*/
typedef enum tagCaseStuffType
{
    CASE_STUFF_TYPE_TOOLS            = 0,      /**< ������ */
    CASE_STUFF_TYPE_TRANSPORT        = 1,      /**< ��ͨ���� */
    CASE_STUFF_TYPE_POISON           = 2,      /**< ������ */
    CASE_STUFF_TYPE_EXPLOSIVE        = 3,      /**< ��ը��Ʒ�� */
    CASE_STUFF_TYPE_JEWELRY          = 4,      /**< �������μ������� */
    CASE_STUFF_TYPE_ELECAPPLIANCES   = 5,      /**< ���õ����� */
    CASE_STUFF_TYPE_INSTRUMENT       = 6,      /**< �����Ǳ����������� */
    CASE_STUFF_TYPE_AGRICULTURALPDT  = 7,      /**< ũ��������Ʒ��Ұ����Ʒ�� */
    CASE_STUFF_TYPE_FOOD             = 8,      /**< ʳƷ�̾��� */
    CASE_STUFF_TYPE_TEXTILE          = 9,      /**< ��֯Ʒ�� */
    CASE_STUFF_TYPE_CLOTHING         = 10,     /**< ��װЬñ������Ʒ�� */
    CASE_STUFF_TYPE_OFFICESUPPLIES   = 11,     /**< �Ľ��������ּ��칫��Ʒ�� */
    CASE_STUFF_TYPE_FURNITURE        = 12,     /**< �Ҿ߼�������Ʒ�� */
    CASE_STUFF_TYPE_DEVICE           = 13,     /**< ͨ���豸�繤������������ */
    CASE_STUFF_TYPE_RUBBERPDT        = 14,     /**< ��������Ʒ�� */
    CASE_STUFF_TYPE_BULIDINGMATERIAL = 15,     /**< ����װ�꼰���������� */
    CASE_STUFF_TYPE_CHEMICALPDT      = 16,     /**< ʯ�ͻ�����Ʒ�� */
    CASE_STUFF_TYPE_MEDICALDEVICES   = 17,     /**< ҽҩ��ҽ����е�� */
    CASE_STUFF_TYPE_DRUGS            = 18,     /**< ��Ʒ�� */
    CASE_STUFF_TYPE_OBSCENEARTICLES  = 19,     /**< ������Ʒ�� */
    CASE_STUFF_TYPE_COMPUTEREQPT     = 20,     /**< ������豸����Ʒ */
    CASE_STUFF_TYPE_COMMUEQPT        = 21,     /**< ͨ���豸 */
    CASE_STUFF_TYPE_CURRENCY         = 22,     /**< ������ */
    CASE_STUFF_TYPE_CERTIFICATE      = 23,     /**< ֤���� */
    CASE_STUFF_TYPE_SECURITIES       = 24,     /**< �м�֤ȯ */
    CASE_STUFF_TYPE_GUNS             = 25,     /**< ǹ֧ */
    CASE_STUFF_TYPE_OTHER            = 26,     /**< ���� */

    CASE_STUFF_TYPE_MAX,               /**< ������Ʒ����ö�����ֵ */
    CASE_STUFF_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}CASE_STUFF_TYPE_E;


/**
* @enum tagCaseStuffProperty
* @brief ������Ʒ����ö��
* @attention
*/
typedef enum tagCaseStuffProperty
{
    CASE_STUFF_PROPERTY_LOSS             = 0,     /**< ��ʧ */
    CASE_STUFF_PROPERTY_CRIMINALTOOLS    = 1,     /**< �������� */
    CASE_STUFF_PROPERTY_STOLENGOODS      = 2,     /**< �߿����� */
    CASE_STUFF_PROPERTY_EVIDENCE         = 3,     /**< ֤�� */
    CASE_STUFF_PROPERTY_OTHER            = 4,     /**< �����永��Ʒ */

    CASE_STUFF_PROPERTY_MAX,                      /**< ������Ʒ����ö�����ֵ */
    CASE_STUFF_PROPERTY_INVALID = 0xFF            /**< ��Чֵ */
}CASE_STUFF_PROPERTY_E;


/**
* @enum tagSeriesCaseType
* @brief ����������ö��
* @attention
*/
typedef enum tagSeriesCaseType
{
    SERIES_CASE_TYPE_CASE      = 0,     /**< �԰����� */
    SERIES_CASE_TYPE_PERSON    = 1,     /**< ���˴��� */
    SERIES_CASE_TYPE_OBJECT    = 2,     /**< ���ﴮ�� */

    SERIES_CASE_TYPE_MAX,               /**< ����������ö�����ֵ */
    SERIES_CASE_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}SERIES_CASE_TYPE_E;


/**
* @enum tagCaseShareType
* @brief ������������ö��
* @attention
*/
typedef enum tagCaseShareType
{
    CASE_SHARE_TYPE_USER   = 0,        /**< ������û� */
    CASE_SHARE_TYPE_ORG    = 1,        /**< �������֯ */

    CASE_SHARE_TYPE_MAX,               /**< ������������ö�����ֵ */
    CASE_SHARE_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}CASE_SHARE_TYPE_E;


/**
* @enum tagCaseRelatedInfoType
* @brief ����������Ϣ����ö��
* @attention
*/
typedef enum tagCaseRelatedInfoType
{
    CASE_RELATEDINFO_TYPE_RECORD   = 0,        /**< ����¼�� */
    CASE_RELATEDINFO_TYPE_IMAGE    = 1,        /**< ����ͼƬ */
    CASE_RELATEDINFO_TYPE_OTHER    = 2,        /**< �������� */

    CASE_RELATEDINFO_TYPE_MAX,               /**< ����������Ϣ����ö�����ֵ */
    CASE_RELATEDINFO_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}CASE_RELATEDINFO_TYPE_E;

/**
* @enum tagCaseFileType
* @brief �����ļ���Ϣ����ö��
* @attention
*/
typedef enum tagCaseFileType
{
    CASE_FILE_TYPE_IMAGE   = 0,            /**< ����ͼƬ�ļ� */
    CASE_FILE_TYPE_OTHER   = 1,            /**< ���������ļ� */
    CASE_FILE_TYPE_UPLOAD_VEDIO   = 2,     /**< �����ϴ�¼�� */
    CASE_FILE_TYPE_PICGRP  = 3,            /**< ����ͼƬ��ͼƬ�ļ� */

    CASE_FILE_TYPE_MAX,               /**< �����ļ�����ö�����ֵ */
    CASE_FILE_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}CASE_FILE_TYPE_E;

/**
* @enum tagAlarmSendToThdSysProcType
* @brief �澯����ת��������ϵͳЭ������
* @attention
*/
typedef enum tagAlarmSendToThdSysProcType
{
    ALARM_SEND_PROC_TYPE_KUNMING_SUBWAY         = 0,    /**< �����������и澯Э�� */
    ALARM_SEND_PROC_TYPE_BUTT
}ALARM_SEND_TO_THD_SYS_PROC_TYPE_E;

/**
* @enum tagResServiceType
* @brief ��Դҵ������(�洢������Դ)
* @attention
*/
typedef enum tagResServiceType
{
    RES_SERVICE_TYPE_GENERAL    = 0,    /**< һ��ҵ�� */
    RES_SERVICE_TYPE_CASE       = 1,    /**< ��������ҵ�� */

    RES_SERVICE_TYPE_MAX,
    RES_SERVICE_TYPE_INVALID = 0xFFFFFFFF
}RES_SERVICE_TYPE_E;

/**
* @enum tagBakTaskServiceType
* @brief ��������ҵ������
* @attention
*/
typedef enum tagBakTaskServiceType
{
    BAK_TASK_SERVICE_TYPE_GENERAL   = 0,    /**< һ��ҵ�� */
    BAK_TASK_SERVICE_TYPE_CASE      = 1,    /**< ��������ҵ�� */

    BAK_TASK_SERVICE_TYPE_MAX,
    BAK_TASK_SERVICE_TYPE_INVALID = 0xFFFFFFFF
}BAK_TASK_SERVICE_TYPE_E;

/**
* @enum tagIMOSSDKUploadType
* @brief ����SDK�ϴ�����
* @attention
*/
typedef enum tagIMOSSDKUploadType
{
    IMOS_SDK_UPLOAD_TYPE_CAMERA_TS  = 0,            /* �����TS�ļ��ϴ� */
    IMOS_SDK_UPLOAD_TYPE_CLIENT     = 1,            /* �ͻ����ļ��ϴ� */
    IMOS_SDK_UPLOAD_TYPE_BUTT
}IMOS_SDK_UPLOAD_TYPE_E;

/**
* @enum tagIMOSUploadAddrType
* @brief �����ļ��ϴ���ַ����
* @attention
*/
typedef enum tagIMOSUploadAddrType
{
    IMOS_UPLOAD_ADDR_TYPE_NONE      = 0,            /**< �޵�ַ, �ɷ�����ѡ�� */
    IMOS_UPLOAD_ADDR_TYPE_SRV_CODE  = 1,            /**< ����������, ��ӦIMOS_CODE_LEN */
    IMOS_UPLOAD_ADDR_TYPE_IPV4      = 2,            /**< IPv4��ַ */
    IMOS_UPLOAD_ADDR_TYPE_BUTT
}IMOS_UPLOAD_ADDR_TYPE_E;

/**
* @enum tagCaseClassificationType
* @brief �����ܼ�ö��
* @attention
*/
typedef enum tagCaseClassificationType
{
    CASE_CLASSIFICATION_TYPE_PUBLIC         = 0,        /**< ���� */
    CASE_CLASSIFICATION_TYPE_SECRET         = 1,        /**< ���� */
    CASE_CLASSIFICATION_TYPE_CONFIDENTIAL   = 2,        /**< ���� */
    CASE_CLASSIFICATION_TYPE_TOPSECRET      = 3,        /**< ���� */

    CASE_CLASSIFICATION_TYPE_MAX,                      /**< �ܼ�ö�����ֵ */
    CASE_CLASSIFICATION_TYPE_INVALID = 0xFF            /**< ��Чֵ */
}CASE_CLASSIFICATION_TYPE_E;

/**
* @enum tagCaseDataType
* @brief ������������ö��
* @attention
*/
typedef enum tagCaseDataType
{
    CASE_DATA_TYPE_CASEINFO       = 0,            /**< ������Ϣ */
    CASE_DATA_TYPE_RECORD         = 1,            /**< ����¼�� */
    CASE_DATA_TYPE_FILE           = 2,            /**< ���������ļ� */

    CASE_DATA_TYPE_MAX,                           /**< ��������ö�����ֵ */
    CASE_DATA_TYPE_INVALID = 0xFF                 /**< ��Чֵ */
}CASE_DATA_TYPE_E;

/* Added by z00359 for TG 20120604 */
/* Begin added by baoyihui02795, 2011-04-28 of ������Ŀ */
/**
* @enum tagQryVehicleStatInfo
* @brief ����ͳ�Ʊ����ѯ����
* @attention
*/
typedef enum tagQryVehicleStatInfo
{
    VEHICLE_STAT_DATE                = 0,    /**< ͳ������#IMOS_SIMPLE_DATE_LEN */
    VEHICLE_STAT_TIME                = 1,    /**< ͳ��ʱ��#IMOS_TIME_LEN */
    VEHICLE_STAT_TOLLGATE_CODE       = 2,    /**< ���ڱ��#IMOS_CODE_LEN */
    VEHICLE_STAT_TOLLGATE_NAME       = 3,    /**< ��������#IMOS_NAME_LEN */
    VEHICLE_STAT_LANE_NUMBER         = 4,    /**< �������#ULONG */
    VEHICLE_STAT_TOTAL_COUNT         = 5,    /**< ����������#ULONG */
    VEHICLE_STAT_AVG_SPEED           = 6,    /**< ���ڳ���ƽ���ٶ�#ULONG */

    VEHICLE_STAT_UNKNOWN_TYPE_COUNT  = 7,    /**< δ֪��������#ULONG */
    VEHICLE_STAT_SMALL_TYPE_COUNT    = 8,    /**< С�ͳ�����#ULONG */
    VEHICLE_STAT_MIDDLE_TYPE_COUNT   = 9,    /**< ���ͳ�����#ULONG */
    VEHICLE_STAT_LARGE_TYPE_COUNT    = 10,   /**< ���ͳ�����#ULONG */
    VEHICLE_STAT_OTHER_TYPE_COUNT    = 11,   /**< ������������#ULONG */

    VEHICLE_STAT_DIR_1               = 12,   /**< ����1����#ULONG */
    VEHICLE_STAT_DIR_2               = 13,   /**< ����2����#ULONG */

    VEHICLE_STAT_MAX
}QRY_VEHICLE_STAT_INFO_E;



/**
* @enum tagFTPOperType
* @brief FTP��������ö��
* @attention
*/
typedef enum tagFTPOperType
{
    FTP_OPER_TYPE_TALLGATE_IMAGE       = 0,            /**< ����ʾ��ͼ�ϴ� */
    FTP_OPER_TYPE_DISPOSITION_IMAGE    = 1,            /**< ������Ƭ�ϴ� */

    FTP_OPER_TYPE_MAX,                                 /**< ���ֵ */
    FTP_OPER_TYPE_INVALID              = 0xFFFF        /**< ��Чֵ */
} FTP_OPER_TYPE_E;

/**
* @enum tagTollgateType
* @brief ��������ö��
* @attention
*/
typedef enum tagTollgateType
{
    TOLLGATE_TYPE_PUBLIC_SECURITY   = 0,            /**< �ΰ����� */
    TOLLGATE_TYPE_TOLL_STATION      = 1,            /**< �շ�վ */
    TOLLGATE_TYPE_PARK              = 2,            /**< ͣ���� */
    TOLLGATE_TYPE_CIQ               = 3,            /**< ���� */
    TOLLGATE_TYPE_E_POLICE          = 4,            /**< �羯 */
    TOLLGATE_TYPE_MOBILE_E_POLICE   = 5,            /**< �ƶ��羯 */
    TOLLGATE_TYPE_VIOLATE_PARK_BALL = 6,            /**< Υͣ�� */
    TOLLGATE_TYPE_PERSON_FACE       = 7,            /**<�������� */
	TOLLGATE_TYPE_SPACESPEED        = 8,			/**< ���俨��*/
    TOLLGATE_TYPE_MAX,                              /**< ���ֵ */
    TOLLGATE_TYPE_INVALID         = 0xFFFF          /**< ��Чֵ */
} TOLLGATE_TYPE_E;

/**
* @enum tagTallgateCameraType
* @brief �����������ö��
* @attention
*/
typedef enum tagTallgateCameraType
{
    TALLGATE_CAMERA_TYPE_3RD         = 0,            /**< ������IPC */

    TALLGATE_CAMERA_TYPE_MAX,                        /**< ���ֵ */
    TALLGATE_CAMERA_TYPE_INVALID     = 0xFFFF        /**< ��Чֵ */
} TALLGATE_CAMERA_TYPE_E;

/**
* @enum tagLaneType
* @brief ��������
* @attention
*/
typedef enum tagLaneType
{
    LANE_TYPE_MOTOR_VEHICLE     = 0,                       /**< �������� */
    LANE_TYPE_NON_MOTOR_VEHICLE = 1,                       /**< �ǻ������� */
    LANE_TYPE_MAX,                                         /**< ���ֵ */
    LANE_TYPE_INVALID           = 0xFFFF               /**< ��Чֵ */
} LANE_TYPE_E;

/**
* @enum tagTrafficLightStatusE
* @brief �źŵ�״̬
* @attention
*/
typedef enum tagTrafficLightStatusE
{
    TRAFFIC_LIGHT_RED_STATUS              = 0,           /**< ���״̬ */
    TRAFFIC_LIGHT_YELLOW_STATUS           = 1,           /**< �Ƶ�״̬ */
    TRAFFIC_LIGHT_GREEN_STATUS            = 2,           /**< �̵�״̬ */
    TRAFFIC_LIGHT_NULL_STATUS             = 3,           /**< �޺��̵��豸 */
    TRAFFIC_LIGHT_ABNORMAL_STATUS         = 4,           /**< ���̵��豸�쳣 */

    TRAFFIC_LIGHT_STATUS_MAX,                            /**< ���ֵ */
    TRAFFIC_LIGHT_STATUS_INVALID  = 0xFFFFFFFF           /**< ��Чֵ */
} TRAFFIC_LIGHT_STATUS_E;

/**
* @enum tagDispositionDeptType
* @brief �����ص�λ����ö��
* @attention
*/
typedef enum tagDispositionDeptType
{
    DISPOSITION_DEPT_TYPE_DISPOSITION       = 0,                   /**< ���� */
    DISPOSITION_DEPT_TYPE_UNDO_DISPOSITION  = 1,                   /**< ���� */
    DISPOSITION_DEPT_TYPE_BOTH              = 2,                   /**< ������ */
    DISPOSITION_DEPT_TYPE_MAX,                                     /**< ���ֵ */
    DISPOSITION_DEPT_TYPE_INVALID           = 0xFFFF               /**< ��Чֵ */
} DISPOSITION_DEPT_TYPE_E;

/**
* @enum tagVehicleColorDepth
* @brief ������ɫ��ǳö��
* @attention
*/
typedef enum tagVehicleColorDepth
{
    VEHICLE_COLOR_DEPTH_UNKNOWN = 0,                       /**< δ֪ */
    VEHICLE_COLOR_DEPTH_LIGHT   = 1,                       /**< ǳ */
    VEHICLE_COLOR_DEPTH_DARK    = 2,                       /**< �� */
    VEHICLE_COLOR_DEPTH_MAX,                               /**< ���ֵ */
    VEHICLE_COLOR_DEPTH_INVALID = 0xFFFF                   /**< ��Чֵ */
} VEHICLE_COLOR_DEPTH_E;

/**
* @enum tagVehicleIdentifyStatus
* @brief ����ʶ��״̬
* @attention
*/
typedef enum tagVehicleIdentifyStatus
{
    VEHICLE_IDENTIFY_STATUS_SUCCEED       = 0,                 /**< ʶ��ɹ� */
    VEHICLE_IDENTIFY_STATUS_FAILED        = 1,                 /**< ʶ��ʧ�� */
    VEHICLE_IDENTIFY_STATUS_PARTLY        = 2,                 /**< ����ʶ�� */
    VEHICLE_IDENTIFY_STATUS_UNRECOGNIZED  = 3,                 /**< δʶ�� */
    VEHICLE_IDENTIFY_STATUS_MAX,                               /**< ���ֵ */
    VEHICLE_IDENTIFY_STATUS_INVALID = 0xFFFF                   /**< ��Чֵ */
} VEHICLE_IDENTIFY_STATUS_E;

/**
* @enum tagVehicleAlarmType
* @brief �����澯���
* @attention
*/
typedef enum tagVehicleAlarmType
{
    VEHICLE_ALARM_TYPE_OTHER                 = 0,             /**< ���� */
    VEHICLE_ALARM_TYPE_DISPOSITION           = 1,             /**< ���ظ澯 */
    VEHICLE_ALARM_TYPE_BLACKLIST             = 2,             /**< �������澯 */
    VEHICLE_ALARM_TYPE_P2P_SPEED_DETECTION   = 3,             /**< ������ٸ澯 *//* Added by b02795, 2011-11-08 of �������� */
    VEHICLE_ALARM_TYPE_P2P_TIME_DETECTION    = 4,             /**< ���䳬ʱ�澯 *//* Added by c02845, 2015-11-05 of MPPD31387  */
	VEHICLE_ALARM_TYPE_MAX,                                   /**< ���ֵ */
    VEHICLE_ALARM_TYPE_INVALID               = 0xFFFF         /**< ��Чֵ */
} VEHICLE_ALARM_TYPE_E;

/**
* @enum tagBlacklistSrc
* @brief ��������Դ
* @attention
*/
typedef enum tagBlacklistSrc
{
    BLACKLIST_SRC_UNKNOWN               = 0,                    /**< δ֪ */
    BLACKLIST_SRC_LOCAL                 = 1,                    /**< �ֹ���� */
    BLACKLIST_SRC_DRIVER_MANAGEMENT     = 2,                    /**< ���ݹ����ݿ� */
    BLACKLIST_SRC_TRAFFIC_VIOLATION     = 3,                    /**< Υ���������ݿ� */
    BLACKLIST_SRC_VEHICLE_GRAB          = 4,                    /**< �����������ݿ� */
    BLACKLIST_SRC_MAX,                                          /**< ���ֵ */
    BLACKLIST_SRC_INVALID = 0xFFFF                              /**< ��Чֵ */
} BLACKLIST_SRC_E;


/**
*@enum tagVehicleListType
*@brief ��������ö��
*@attention
*/
typedef enum tagVehicleListType
{
    VEHICLE_LIST_TYPE_RED             = 0,              /**< ������ */
    VEHICLE_LIST_TYPE_MAX,                              /**< ���ֵ */
    VEHICLE_LIST_TYPE_INVALID         = 0xFFFF          /**< ��Чֵ */
} VEHICLE_LIST_TYPE_E;

/**
* @enum tagVehicleDealStatus
* @brief �������ݴ����־����
* @attention
*/
typedef enum tagVehicleDealStatus
{
    VEHICLE_DEAL_STATUS_INIT      = 0,                  /**< δ���� */
    VEHICLE_DEAL_STATUS_CORRECTED = 1,                  /**< ��У�� */
    VEHICLE_DEAL_STATUS_USELESS   = 2,                  /**< ��Ч��Ϣ */
    VEHICLE_DEAL_STATUS_AUDITED   = 3,                  /**< ����� */
    VEHICLE_DEAL_STATUS_DONE      = 4,                  /**< �Ѵ��� */
    VEHICLE_DEAL_STATUS_MAX,                            /**< ���ֵ */
    VEHICLE_DEAL_STATUS_INVALID = 0xFFFF                /**< ��Чֵ */
} VEHICLE_DEAL_STATUS_E;

/**
* @enum tagDictionaryType
* @brief �����ֵ�����ö��
* @attention
*/
typedef enum tagDictionaryType
{
    DICTIONARY_TYPE_LICENSE_PLATE_TYPE      = 1,    /**< �������� */
    DICTIONARY_TYPE_LICENSE_PLATE_COLOR     = 2,    /**< ������ɫ */
    DICTIONARY_TYPE_VEHICLE_TYPE            = 3,    /**< �������� */
    DICTIONARY_TYPE_VEHICLE_COLOR           = 4,    /**< ������ɫ */
    DICTIONARY_TYPE_VEHICLE_LOGO            = 5,    /**< ����Ʒ�� */
    DICTIONARY_TYPE_VEHICLE_STATUS          = 6,    /**< ������ʻ״̬ */
    DICTIONARY_TYPE_DISPOSITION_TYPE        = 7,    /**< �������� */
    DICTIONARY_TYPE_EQUIPMENT_TYPE          = 8,    /**< �ɼ����� */
    DICTIONARY_TYPE_LANE_DIR                = 9,    /**< ��ʻ���� */
    DICTIONARY_TYPE_LICENSE_PLATE_PREFIX    = 10,   /**< ����ʡ�ݼ�� */
    DICTIONARY_TYPE_ERR_DECK                = 11,   /**<���Ʒ����ִ���ԭ�� */
    DICTIONARY_TYPE_DEAL_STATUS             = 311, /**<����״̬*/
    DICTIONARY_TYPE_AUDIT_STATUS        = 312,/**<����״̬*/
    DICTIONARY_TYPE_MAX = 400   ,                    /**< ���ֵ */
    DICTIONARY_TYPE_INVALID = 0xFFFF                /**< ��Чֵ */
} DICTIONARY_TYPE_E;

/**
* @enum tagDispositionStatus
* @brief ����״̬ö��
* @attention
*/
typedef enum tagDispositionStatus
{
    DISPOSITION_STATUS_IN_PROCESS       = 0,    /**< ���� */
    DISPOSITION_STATUS_MANUAL_UNDO      = 1,    /**< �ֹ����� */
    DISPOSITION_STATUS_AUTO_UNDO        = 2,    /**< �Զ����� */
    DISPOSITION_STATUS_PAUSE            = 3,    /**< ������ͣ */
    DISPOSITION_STATUS_CONTINUE         = 4,    /**< ���ؼ��� */
    DISPOSITION_AUDIT_STATUS_PENDING    = 5,    /**< ����� */
    DISPOSITION_AUDIT_STATUS_NO_PASS    = 6,    /**< ���δͨ�� */
    DISPOSITION_STATUS_MAX,                     /**< ���ֵ */
    DISPOSITION_STATUS_INVALID = 0xFFFF         /**< ��Чֵ */
} DISPOSITION_STATUS_E;

/* End added by baoyihui02795, 2011-04-28 of ������Ŀ */

/*Begin added by a02842 for whitelist extension,2017-02-23*/
/**
* @enum tagDispositionStatus
* @brief ������״̬ö��
* @attention
*/
typedef enum tagWhiteListStatus
{
    WHITELIST_STATUS_IN_PROCESS       = 0,    /**< ������ʹ��*/
    WHITELIST_STATUS_MANUAL_UNDO      = 1,    /**< �ֹ�����*/
    WHITELIST_STATUS_AUTO_UNDO        = 2,    /**< �Զ�����*/
    WHITELIST_STATUS_PAUSE            = 3,    /**< ��������ͣ */
    WHITELIST_STATUS_CONTINUE         = 4,    /**< ���������� */
    WHITELIST_STATUS_MAX,                     /**< ���ֵ */
    WHITELIST_STATUS_INVALID = 0xFFFF         /**< ��Чֵ */
} WHITELIST_STATUS_E;
/*End added by a02842 for whitelist extension,2017-02-23*/

/**
* @enum tagDevLocalResOperType
* @brief ���ش洢��Դ����ö��
* @attention
*/
typedef enum tagDevLocalResOperType
{
    DEV_LOCAL_RES_OPER_TYPE_TOLLGATE       = 0,           /**< ���� */
    DEV_LOCAL_RES_OPER_TYPE_MAX,                          /**< ���ֵ */
    DEV_LOCAL_RES_OPER_TYPE_INVALID        = 0xFFFF       /**< ��Чֵ */
} DEV_LOCAL_RES_OPER_TYPE_E;

/**
* @enum tagStorageResUsage
* @brief �洢��Դ��;ö��
* @attention
*/
typedef enum tagStorageResUsage
{
    STORAGE_RES_USAGE_DEFAULT                   = 0,            /**< Ĭ�� */
    STORAGE_RES_USAGE_VEHICLE_ALARM_IMG         = 1,            /**< �����澯ͼƬ�洢 */
    STORAGE_RES_USAGE_IAHR                      = 2,            /**< ����ͼƬ�洢 */

    STORAGE_RES_USAGE_MAX,                                      /**< ���ֵ */
    STORAGE_RES_USAGE_INVALID                   = 0xFFFF        /**< ��Чֵ */
} STORAGE_RES_USAGE_E;

/* Added by z06806 for TGII 20110721 begin */
/**
* @enum tagPlateAnalyseStatus
* @brief ���Ʒ���״̬
* @attention
*/
typedef enum tagPlateAnalyseStatus
{
    PLATE_ANALYSE_STATUS_INIT               = 0,            /**< ��ʼ�� */
    PLATE_ANALYSE_STATUS_ANALYSING          = 1,            /**< ���ڷ��� */
    PLATE_ANALYSE_STATUS_FINISHED           = 2,            /**< ������� */
    PLATE_ANALYSE_STATUS_USER_STOP          = 3,            /**< �û��ֶ�ֹͣ */
    PLATE_ANALYSE_STATUS_ERR_STOP           = 4,            /**< �ڲ�����ֹͣ */
    PLATE_ANALYSE_STATUS_MAX,                               /**< ���ֵ */
    PLATE_ANALYSE_STATUS_INVALID            = 0xFFFF        /**< ��Чֵ */
} PLATE_ANALYSE_STATUS_E;

/**
* @enum tagVehicleAbnormalAnalyseStatus
* @brief �����쳣��Ϊ����״̬
* @attention
*/
typedef enum tagVehicleAbnormalAnalyseStatus
{
    VEHICLE_ABNORMAL_STATUS_INIT               = 0,            /**< ��ʼ�� */
    VEHICLE_ABNORMAL_STATUS_ANALYSING          = 1,            /**< ���ڷ��� */
    VEHICLE_ABNORMAL_STATUS_FINISHED           = 2,            /**< ������� */
    VEHICLE_ABNORMAL_STATUS_USER_STOP          = 3,            /**< �û��ֶ�ֹͣ */
    VEHICLE_ABNORMAL_STATUS_ERR_STOP           = 4,            /**< �ڲ�����ֹͣ */
    VEHICLE_ABNORMAL_STATUS_MAX,                               /**< ���ֵ */
    VEHICLE_ABNORMAL_STATUS_INVALID            = 0xFFFF        /**< ��Чֵ */
} VEHICLE_ABNORMAL_ANALYSE_STATUS_E;

/**
* @enum tagVehicleAbnormalAnalyseOperator
* @brief �����쳣��Ϊ����������
* @attention
*/
typedef enum tagVehicleAbnormalAnalyseOperator
{
    VEHICLE_ABNORMAL_OPERATOR_GE               = 0,            /**< ���ڵ��� */
    VEHICLE_ABNORMAL_OPERATOR_GREAT            = 1,            /**< ���� */
    VEHICLE_ABNORMAL_OPERATOR_EQUAL            = 2,            /**< ���� */
    VEHICLE_ABNORMAL_OPERATOR_LE               = 3,            /**< С�ڵ��� */
    VEHICLE_ABNORMAL_OPERATOR_LESS             = 4,            /**< С�� */
    VEHICLE_ABNORMAL_OPERATOR_MAX,                             /**< ���ֵ */
    VEHICLE_ABNORMAL_OPERATOR_INVALID          = 0xFFFF        /**< ��Чֵ */
} VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E;


/* Added by z06806 for TGII 20110721 end */

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/**
* @enum tagVehicleTrackCollisionStatus
* @brief �����켣��ײ����״̬
* @attention
*/
typedef enum tagVehicleTrackCollisionStatus
{
    VEHICLE_TRACK_COLLISION_STATUS_INIT               = 0,            /**< ��ʼ�� */
    VEHICLE_TRACK_COLLISION_STATUS_ANALYSING          = 1,            /**< ���ڷ��� */
    VEHICLE_TRACK_COLLISION_STATUS_FINISHED           = 2,            /**< ������� */
    VEHICLE_TRACK_COLLISION_STATUS_USER_STOP          = 3,            /**< �û��ֶ�ֹͣ */
    VEHICLE_TRACK_COLLISION_STATUS_ERR_STOP           = 4,            /**< �ڲ�����ֹͣ */
    VEHICLE_TRACK_COLLISION_STATUS_MAX,                               /**< ���ֵ */
    VEHICLE_TRACK_COLLISION_STATUS_INVALID            = 0xFFFF        /**< ��Чֵ */
} VEHICLE_TRACK_COLLISION_STATUS_E;

/**
* @enum tagVehicleFirstAppearStatus
* @brief �����״γ��ַ���״̬
* @attention
*/
typedef enum tagVehicleFirstAppearStatus
{
    VEHICLE_FIRST_APPEAR_STATUS_INIT               = 0,            /**< ��ʼ�� */
    VEHICLE_FIRST_APPEAR_STATUS_ANALYSING          = 1,            /**< ���ڷ��� */
    VEHICLE_FIRST_APPEAR_STATUS_FINISHED           = 2,            /**< ������� */
    VEHICLE_FIRST_APPEAR_STATUS_USER_STOP          = 3,            /**< �û��ֶ�ֹͣ */
    VEHICLE_FIRST_APPEAR_STATUS_ERR_STOP           = 4,            /**< �ڲ�����ֹͣ */
    VEHICLE_FIRST_APPEAR_STATUS_MAX,                               /**< ���ֵ */
    VEHICLE_FIRST_APPEAR_STATUS_INVALID            = 0xFFFF        /**< ��Чֵ */
} VEHICLE_FIRST_APPEAR_STATUS_E;

/**
* @enum tagVehiclePerilTimeStatus
* @brief ������Σʱ�η���״̬
* @attention
*/
typedef enum tagVehiclePerilTimeStatus
{
    VEHICLE_PERIL_TIME_STATUS_INIT               = 0,              /**< ��ʼ�� */
    VEHICLE_PERIL_TIME_STATUS_ANALYSING          = 1,              /**< ���ڷ��� */
    VEHICLE_PERIL_TIME_STATUS_FINISHED           = 2,              /**< ������� */
    VEHICLE_PERIL_TIME_STATUS_USER_STOP          = 3,              /**< �û��ֶ�ֹͣ */
    VEHICLE_PERIL_TIME_STATUS_ERR_STOP           = 4,              /**< �ڲ�����ֹͣ */
    VEHICLE_PERIL_TIME_STATUS_MAX,                                 /**< ���ֵ */
    VEHICLE_PERIL_TIME_STATUS_INVALID            = 0xFFFF          /**< ��Чֵ */
} VEHICLE_PERIL_TIME_STATUS_E;

/* End added by bt00977, 2013-1-25 of MPPD00420 */

/**
* @enum tagVehicleFrequentNightOutStatus
* @brief ����Ƶ��ҹ������״̬
* @attention
*/
typedef enum tagVehicleFrequentNightOutStatus
{
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_INIT               = 0,              /**< ��ʼ�� */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_ANALYSING          = 1,              /**< ���ڷ��� */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_FINISHED           = 2,              /**< ������� */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_USER_STOP          = 3,              /**< �û��ֶ�ֹͣ */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_ERR_STOP           = 4,              /**< �ڲ�����ֹͣ */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_MAX,                                 /**< ���ֵ */
    VEHICLE_FREQUENT_NIGHT_OUT_STATUS_INVALID            = 0xFFFF          /**< ��Чֵ */
} VEHICLE_FREQUENT_NIGHT_OUT_STATUS_E;

/**
* @enum tagVehicleNocturnalStatus
* @brief �������ҹ������״̬
* @attention
*/
typedef enum tagVehicleNocturnalStatus
{
    VEHICLE_NOCTURNAL_STATUS_INIT               = 0,              /**< ��ʼ�� */
    VEHICLE_NOCTURNAL_STATUS_ANALYSING          = 1,              /**< ���ڷ��� */
    VEHICLE_NOCTURNAL_STATUS_FINISHED           = 2,              /**< ������� */
    VEHICLE_NOCTURNAL_STATUS_USER_STOP          = 3,              /**< �û��ֶ�ֹͣ */
    VEHICLE_NOCTURNAL_STATUS_ERR_STOP           = 4,              /**< �ڲ�����ֹͣ */
    VEHICLE_NOCTURNAL_STATUS_MAX,                                 /**< ���ֵ */
    VEHICLE_NOCTURNAL_STATUS_INVALID            = 0xFFFF          /**< ��Чֵ */
} VEHICLE_NOCTURNAL_STATUS_E;

/**
* @enum tagVehicleOnlyIntoCityStatus
* @brief ������ν��ǲ����Ƿ���״̬
* @attention
*/
typedef enum tagVehicleOnlyIntoCityStatus
{
    VEHICLE_ONLY_INTO_CITY_STATUS_INIT               = 0,              /**< ��ʼ�� */
    VEHICLE_ONLY_INTO_CITY_STATUS_ANALYSING          = 1,              /**< ���ڷ��� */
    VEHICLE_ONLY_INTO_CITY_STATUS_FINISHED           = 2,              /**< ������� */
    VEHICLE_ONLY_INTO_CITY_STATUS_USER_STOP          = 3,              /**< �û��ֶ�ֹͣ */
    VEHICLE_ONLY_INTO_CITY_STATUS_ERR_STOP           = 4,              /**< �ڲ�����ֹͣ */
    VEHICLE_ONLY_INTO_CITY_STATUS_MAX,                                 /**< ���ֵ */
    VEHICLE_ONLY_INTO_CITY_STATUS_INVALID            = 0xFFFF          /**< ��Чֵ */
} VEHICLE_ONLY_INTO_CITY_STATUS_E;

/**
* @enum tagVehicleFrequentNightOutOperator
* @brief ����Ƶ��ҹ������������
* @attention
*/
typedef enum tagVehicleFrequentNightOutOperator
{
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_GE               = 0,            /**< ���ڵ��� */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_GREAT            = 1,            /**< ���� */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_EQUAL            = 2,            /**< ���� */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_LE               = 3,            /**< С�ڵ��� */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_LESS             = 4,            /**< С�� */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_MAX,                             /**< ���ֵ */
    VEHICLE_FREQUENT_NIGHT_OUT_OPERATOR_INVALID          = 0xFFFF        /**< ��Чֵ */
} VEHICLE_FREQUENT_NIGHT_OUT_ANALYSE_OPERATOR_E;

/**
 * @enum tagTmsMultiAddrForward
 * @brief ���ַת��״̬
 * @attention
 */
typedef enum tagTmsMultiAddrForward
{
    TMS_MULTI_ADDR_FORWARD_INIT                = 0,    /**< ��ʼ�� */
    TMS_MULTI_ADDR_FORWARD_SUCCEED             = 1,    /**< ���� */
    TMS_MULTI_ADDR_FORWARD_ERROR               = 2,    /**< ���� */
    TMS_MULTI_ADDR_FORWARD_MAX,
    TMS_MULTI_ADDR_FORWARD_INVALID            = 0XFFFFFFFF
} TMS_MULTI_ADDR_FORWARD_E;

/* Begin added by b02795, 2011-11-08 of �������� */
/**
* @enum tagVehicleRecordType
* @brief ������¼���
* @attention
*/
typedef enum tagVehicleRecordType
{
    VEHICLE_RECORD_TYPE_NORMAL               = 0,             /**< ������¼ */
    VEHICLE_RECORD_TYPE_P2P_SPEED_DETECTION  = 1,             /**< ������� */
    VEHICLE_RECORD_TYPE_REDLIST              = 2,             /**< ������������¼ */
    VEHICLE_RECORD_TYPE_MAX,                                  /**< ���ֵ */
    VEHICLE_RECORD_TYPE_INVALID              = 0xFFFF         /**< ��Чֵ */
} VEHICLE_RECORD_TYPE_E;

/**
* @enum tagDeviceGisStatus
* @brief �豸GIS״̬
* @attention
*/
typedef enum tagDeviceGisStatus
{
    DEVICE_GIS_STATUS_NORMAL                 = 0,             /**< ���� */
    DEVICE_GIS_STATUS_ALARM                  = 1,             /**< �澯 */
    DEVICE_GIS_STATUS_MAX,                                    /**< ���ֵ */
    DEVICE_GIS_STATUS_INVALID                = 0xFFFF         /**< ��Чֵ */
} DEVICE_GIS_STATUS_E;
/* End added by b02795, 2011-11-08 of �������� */

/*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
/**
* @enum tagDispositionType
* @brief �������ö��
* @attention
*/
typedef enum tagDispositionType
{
    DISPOSITION_TYPE_MAC      = 0,    /**< MAC���� */
    DISPOSITION_TYPE_RFID      = 1,    /**< RFID����*/
    DISPOSITION_TYPE_MAX,                     /**< ���ֵ */
    DISPOSITION_TYPE_INVALID = 0xFFFF         /**< ��Чֵ */
} DISPOSITION_TYPE_E;
/*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

/**
* @enum tagDispositionInterType
* @brief ������������
* @attention
*/
typedef enum tagDispositionInterType
{
    DISPOSITION_INTER_TYPE_LOCAL                 = 0,             /**< ���� */
    DISPOSITION_INTER_TYPE_LOWER                 = 1,             /**< �¼��� */
    DISPOSITION_INTER_TYPE_LOCAL_LOWER           = 2,             /**< ������¼��� */
    DISPOSITION_INTER_TYPE_UPPER                 = 3,             /**< �ϼ��� */
    DISPOSITION_INTER_TYPE_MAX,                                   /**< ���ֵ */
    DISPOSITION_INTER_TYPE_INVALID               = 0xFFFF         /**< ��Чֵ */
} DISPOSITION_INTER_TYPE_E;

/**
* @enum tagDispositionResultType
* @brief ���ؽ��
* @attention
*/
typedef enum tagDispositionResultType
{
    DISPOSITION_RESULT_IN_PROCESS            = 0,             /**< ���ڴ��� */
    DISPOSITION_RESULT_SUCCEED               = 1,             /**< �ɹ� */
    DISPOSITION_RESULT_FAILED                = 2,             /**< ʧ�� */
    DISPOSITION_RESULT_TIMEOUT               = 3,             /**< ��ʱ */
    DISPOSITION_RESULT_MAX,                                   /**< ���ֵ */
    DISPOSITION_RESULT_INVALID               = 0xFFFF         /**< ��Чֵ */
} DISPOSITION_RESULT_E;

/**
* @enum tagDispositionExtStatus
* @brief ������չ״̬
* @attention
*/
typedef enum tagDispositionExtStatus
{
    DISPOSITION_EXT_STATUS_SUCCESS           = 0,             /**< �ɹ� */
    DISPOSITION_EXT_STATUS_OTHER             = 1,             /**< ���� */
    DISPOSITION_EXT_STATUS_MAX,                               /**< ���ֵ */
    DISPOSITION_EXT_STATUS_INVALID           = 0xFFFF         /**< ��Чֵ */
} DISPOSITION_EXT_STATUS_E;

/**
* @enum tagVehicleRestrictType
* @brief �������з�ʽ
* @attention
*/
typedef enum tagVehicleRestrictType
{
    VEHICLE_RESTRICT_TYPE_LAST_NUMBER      = 0,            /**< β������ */
    VEHICLE_RESTRICT_TYPE_ODD              = 1,            /**< �������� */
    VEHICLE_RESTRICT_TYPE_EVEN             = 2,            /**< ˫������ */
    VEHICLE_RESTRICT_TYPE_VEHICLE_TYPE     = 3,            /**< �������� */

    VEHICLE_RESTRICT_TYPE_MAX,                             /**< �������з�ʽö�����ֵ */
    VEHICLE_RESTRICT_TYPE_INVALID          = 0xFFFF        /**< ��Чֵ */
} VEHICLE_RESTRICT_TYPE_E;


/**
* @enum tagTMSForwardMode
* @brief ת��ģʽ
* @attention
*/
typedef enum tagTMSForwardMode
{
    TMS_FORWARD_MODE_IMAGE            = 0,            /**< ת��ͼƬ */
    TMS_FORWARD_MODE_URL              = 1,            /**< ת��ͼƬURL */

    TMS_FORWARD_MODE_MAX,                             /**< ���ֵ */
    TMS_FORWARD_MODE_INVALID          = 0xFFFF        /**< ��Чֵ */
} TMS_FORWARD_MODE_E;

/**
* @enum tagWebGisMapType
* @brief WebGis��ͼ����
* @attention
*/
typedef enum tagWebGisMapType
{
    WEBGIS_TYPE_WMS             = 0,             /**< WMS��ͼ */
    WEBGIS_TYPE_BMP             = 1,             /**< BMP��ͼ */
    WEBGIS_TYPE_JPEG            = 2,             /**< JPEG��ͼ */
    WEBGIS_TYPE_SVG             = 3,             /**< SVG��ͼ */
    WEBGIS_TYPE_TMS             = 4,             /**< TMS��ͼ */
    WEBGIS_TYPE_SHP             = 5,             /**< SHP��ͼ *��

    WEBGIS_TYPE_MAX,                             /**< ���ֵ */
    WEBGIS_TYPE_INVALID         = 0xFF           /**< ��Чֵ */

} WEBGIS_MAP_TYPE;

/**
* @enum tagCommunityCameraStatus
* @brief �����Դ�����״̬ö��
* @attention
*/
typedef enum tagCommunityCameraStatus
{
    COMMUNITY_CAMERA_STATUS_NORMAL      = 0,            /**< ���� */
    COMMUNITY_CAMERA_STATUS_FAULT       = 1,            /**< �� */
    COMMUNITY_CAMERA_STATUS_REPAIR      = 2,            /**< ά�� */
    COMMUNITY_CAMERA_STATUS_RETIREMENT  = 3,            /**< ���� */

    COMMUNITY_CAMERA_STATUS_MAX,                        /**< �����Դ�����״̬ö�����ֵ */
    COMMUNITY_CAMERA_STATUS_INVALID     = 0xFF          /**< ��Чֵ */
}COMMUNITY_CAMERA_STATUS_E;

/**
* @enum tagUserClientType
* @brief �û�ǰ�˵�����
* @attention
*/
typedef enum tagUserClientType
{
    /* (0~999)����BS�ͻ��� */
    USER_CLIENT_TYPE_BS          = 0,            /**< BS�ͻ��� */
    USER_CLIENT_TYPE_MBS         = 1,            /**< ����BS�ͻ��� */

    /* (1000~1999):����CS�ͻ��� */
    USER_CLIENT_TYPE_ICSCI      = 1000,         /**< ����ͼ��ͻ��� */
    USER_CLIENT_TYPE_ICC        = 1001,         /**< Υ��ץ�Ŀͻ��� */

    /* (2000~2999):�����ƶ��ͻ��� */
    USER_CLIENT_TYPE_MOBILE      = 2000,         /**< �ƶ��ͻ��� */

    USER_CLIENT_TYPE_MCD      = 2001,         /**< �ƶ�ָ�ӵ��ȿͻ��� */
    USER_CLIENT_TYPE_MLE      = 2002,         /**< �ƶ�ִ���ͻ��� */


    USER_CLIENT_TYPE_MAX,                        /**< �û�ǰ�˵�����ö�����ֵ */
    USER_CLIENT_TYPE_INVALID     = 0xFFFF        /**< ��Чֵ */
}USER_CLIENT_TYPE_E;


/**
* @enum tagBallLinkageType
* @brief ǹ����������ö��
* @attention
*/
typedef enum tagBallLinkageType
{
    BALLLINKAGE_TYPE_SINGLE      = 0,       /**< һǹһ�� */
    BALLLINKAGE_TYPE_TRIPLE      = 1,       /**< ��ǹһ�� */

    BALLLINKAGE_TYPE_MAX,                    /**< ö�����ֵ */
    BALLLINKAGE_TYPE_INVALID = 0xFFFFFFFF    /**< ��Чֵ */
}BALLLINKAGE_TYPE_E;

/**
* @enum tagOrgResSubType
* @brief ��֯��Դ������ö��
* @attention
*/
typedef enum tagOrgResSubType
{
    ORG_RES_SUB_TYPE_LOCAL_PHY   = 1,       /**< �������� */
    ORG_RES_SUB_TYPE_LOCAL_VIR   = 2,       /**< ����������� */
    ORG_RES_SUB_TYPE_EXT_VIR     = 3,       /**< ����������� */
    ORG_RES_SUB_TYPE_UPPER_PHY   = 4,       /**< �ϼ��������� */
    ORG_RES_SUB_TYPE_LOWER_PHY   = 5,       /**< �¼��������� */
    ORG_RES_SUB_TYPE_PARITY_PHY  = 6,       /**< ƽ���������� */

    ORG_RES_SUB_TYPE_MAX,                   /**< ö�����ֵ */
    ORG_RES_SUB_TYPE_INVALID = 0xFFFFFFFF   /**< ��Чֵ */
}RES_SUB_TYPE_E;

/**
* @enum tagExdomainResQueryPolicy
* @brief ������Դ��ѯ����ö��
* @attention
*/
typedef enum tagExdomainResQueryPolicy
{
    EXDOMAIN_RES_QUERY_POLICY_CURRENTORG              = 0,       /**< ֻ��ѯ��ǰ��֯�µ���Դ��Ϣ */
    EXDOMAIN_RES_QUERY_POLICY_CONTAINSUBRES           = 1,       /**<��ѯ��������֯����Դ��Ϣ */

    EXDOMAIN_RES_QUERY_POLICY_MAX,                              /**< �豸������Դ��ѯ����ö�����ֵ */
    EXDOMAIN_RES_QUERY_POLICY_INVALID        = 0xFF             /**< ��Чֵ */
}EXDOMAIN_RES_QUERY_POLICY_E;

/**
* @enum tagAlarmOutputSetType
* @brief ���ø澯�����������
* @attention
*/
typedef enum tagAlarmOutputSetType
{
    ALARM_OUTPUT_OFF = 0,  /**< ֹͣ��� */
    ALARM_OUTPUT_ON  = 1   /**< ������� */

}ALARM_OUTPUT_SET_TYPE_E;

/**
* @enum tagUserLoginNameType
* @brief �û���¼������
* @attention ��
*/
typedef enum tagUserLoginNameType
{
    LONGIN_NAME_TYPE_USER_NAME = 0,        /**< �û����� */
    LONGIN_NAME_TYPE_USER_CODE = 1,        /**< �û����� */

    LONGIN_NAME_TYPE_MAX,                  /**< �û���¼���������ֵ */
    LONGIN_NAME_TYPE_INVALID = 0xFFFF      /**< �û���¼��������Чֵ */
}USER_LOGIN_NAME_TYPE_E;

/**
* @enum tagStorageType
* @brief �洢����
* @attention
*/
typedef enum tagStorageType
{
    STORAGE_TYPE_OWN    = 0,  /**< ����洢 */
    STORAGE_TYPE_SHARE  = 1   /**< ����洢 */

}STORAGE_TYPE_E;


/* BEGIN: Added by kf0092 for ��������ֶ���ͣ�洢, 2013��3��11�� */
/**
* @enum tagCameraGroupOperateType
* @brief���������
* @attention ��
*/
typedef enum tagCameraGroupOperateType
{
    CAMERA_GROUP_OPERATE_TYPE_STOP_STOR = 0,    /**< ֹͣ����¼�� */
    CAMERA_GROUP_OPERATE_TYPE_START_STOR,       /**< ��������¼�� */
    CAMERA_GROUP_OPERATE_TYPE_STOP_BROADCAST,   /**< ֹͣ�㲥 */
    CAMERA_GROUP_OPERATE_TYPE_START_BROADCAST,  /**< �����㲥 */

    CAMERA_GROUP_OPERATE_TYPE_TYPE_MAX,         /**< �����������������ֵ */
    CAMERA_GROUP_OPERATE_TYPE_INVALID = 0xFFFF  /**< ����������������Чֵ */
} CAMERA_GROUP_OPERATE_TYPE_E;

/* END  : Added by kf0092 for ��������ֶ���ͣ�洢, 2013��3��11�� */

/**
* @enum tagTVWallExt
* @brief ����ǽ��������
* @attention ��
*/
typedef enum tagTVWallExt
{
    TV_WALL_MONITOR = 0,    /**< ������ */
    TV_WALL_DC = 1          /**< DC */
} TV_WALL_EXT_E;

/* Begin: Added by zhangjirui00227, 2012-07-18 of IVSD01426���� */
/** �澯���� */
typedef enum tagAlarmPriority
{
    ALARM_PRIORITY_1 = 1, /* 1������ */
    ALARM_PRIORITY_2 = 2, /* 2������ */
    ALARM_PRIORITY_3 = 3, /* 3������ */
    ALARM_PRIORITY_4= 4, /* 4������ */

    AlARM_PRIORITY_MAX,                         /**< ���ֵ */
    AlARM_PRIORITY_ALL      = 0xFFFE,           /**< ���и澯�������� */
    AlARM_PRIORITY_INVALID  = 0xFFFF            /**< ��Чֵ */
}ALARM_PRIORITY_E;

/** ������ʽ */
typedef enum tagAlarmMethod
{
    ALARM_METHODL_TEL = 1, /* �绰���� */
    ALARM_METHOD_DEVICE = 2, /*�豸���� */
    ALARM_METHOD_MESSAGE = 3, /* ���ű��� */
    ALARM_METHOD_GPS = 4, /* GPS���� */
    ALARM_METHOD_VEDIO = 5, /* ��Ƶ���� */
    ALARM_METHOD_DEVICE_DEFECT = 6, /* �豸���ϱ��� */
    ALARM_METHOD_OTHER = 7, /* �������� */

    AlARM_METHOD_MAX,                         /**< ���ֵ */
    AlARM_METHOD_ALL      = 0xFFFE,           /**< ���и澯�������� */
    AlARM_METHOD_INVALID  = 0xFFFF            /**< ��Чֵ */
}ALARM_METHOD_E;
/* End: Added by zhangjirui00227, 2012-07-18 of IVSD01426���� */

/**
* @enum tagDevInstType
* @brief �豸��������
* @attention ��
*/
typedef enum tagDevInstType
{
    DEV_INST_IMAGE_JOIN = 10,           /**< ͼ��ƴ�� */
    DEV_INST_ANALOG_INPUT = 11,         /**< ģ������ */
    DEV_INST_CAMERA_ANGLE_ZOME = 21,    /**< ������ǶȺͱ䱶 */
    DEV_INST_IMAGE_PARAM_ADJUST = 30,    /**< ͼ��������� */
    /* AddedBy liuhongjieKF0170,2013-9-9  of ��ѯIPC�Ƿ�֧������OSD */
    DEV_INST_BLOCK_OSD_SUPPORT = 60,/**<����OSD  */

    /* Begin: added by zhangdong(kf0134), 2013.10.15 for SDC3.5 ֧��ȫ��ƴ��*/
    DEV_INST_VIDEO_JOIN = 91,         /**< ��Ƶƴ��*/
    DEV_INST_VIDEO_Cancle = 92,       /**< ȡ����Ƶƴ��*/
    /* End: added by zhangdong(kf0134), 2013.10.15 for SDC3.5 ֧��ȫ��ƴ��*/

    /*��������������͸��--͸�����豸*/
    DEV_INST_DC_COMMAND_BEGIN = 1000,
    DEV_INST_IMAGE_MOSAIC_JOIN = 1001,    /* SDC ����ƴ��*/    /* Added by zkf0134, 2013.10.25 for SDC ����ƴ��*/

	/* Begin: Added by luchunfeng02289, 2015-09-28 for ADU */
    DEV_INST_ADU_VID_JOIN = 1003,         /**< ADUȫ��ƴ�� */
    DEV_INST_ADU_VID_Cancle = 1004,       /**< ADUȫ��ƴ��ȡ�� */
    DEV_INST_ADU_VID_STATE = 1005,        /**< ADUȫ��ƴ�Ӳ�ѯ */
    DEV_INST_ADU_TV_WALL = 1006,          /**< ADU����ǽ���á���ѯ */
    DEV_INST_ADU_TV_WINCTL = 1007,        /**< ADU�������� */
    /* End: Added by luchunfeng02289, 2015-09-28 for ADU */

    DEV_INST_DC_COMMAND_END = 1100,

    /*��������������͸�� Added by c01344 for 2014-11-8 */
    DEV_INST_SCREEN_MIN = 1101,
    DEV_INST_SCREEN_RECORD_PLAY = 1102,   /* ¼��ط� ¼�������� */

    /* Begin: Added by luchunfeng02289, 2015-09-28 for ADU */
    DEV_INST_SCREEN_VIDEO_START = 1108,   /**< USB��Ƶ���� */
    DEV_INST_SCREEN_VIDEO_STOP = 1109,    /**< USB��Ƶֹͣ���� */
    DEV_INST_SCREEN_VIDEO = 1110,         /**< USB��Ƶ���Ų�ѯ*/
    /* End: Added by luchunfeng02289, 2015-09-28 for ADU */

    DEV_INST_SCREEN_MAX = 1199,
    /*��������������͸�� End by c01344 for 2014-11-8 */

	DEV_INST_CAMERA_MIN = 1200,
	DEV_INST_CAMERA_IR= 1201,
	DEV_INST_CAMERA_MAX = 1299,

	DEV_INST_CAMERA_SET_MIN = 1300,
	DEV_INST_CAMERA_SET_IR_MODE = 1301,
	DEV_INST_CAMERA_SET_IR_BRIGHT = 1302,
	DEV_INST_CAMERA_SET_MAX = 1399

} DEV_INST_TYPE_E;

/* Begin Added by zhudingjingKF0104, 2013-06-26 of ������Դ�� */
/**
* @enum tagAudioInputTypeForECR
* @brief ��Ƶ��������
* @attention ��
*/
typedef enum tagAudioInputTypeForECR
{
    AUDIO_INPUT_TYPE_FOLLOW             = 0,          /** ��·��Ƶ���� */
    AUDIO_INPUT_TYPE_INDEPENDENT        = 1,          /** ������Ƶ���� */

    AUDIO_RES_TYPE_INVALID              = 0xFF
}AUDIO_INPUT_TYPE_FOR_ECR_E;

/**
* @enum tagVoiceStatusForECR
* @brief ����ҵ��״̬
* @attention ��
*/
typedef enum tagVoiceStatusForECR
{
    VOICE_STATUS_NORMAL          = 0,        /** ��ͨ״̬ */
    VOICE_STATUS_TALK            = 1,        /** ���ڶԽ� */
    VOICE_STATUS_BROADCAST       = 2,        /** ���ڹ㲥 */

    VOICE_STATUS_MAX,
    VOICE_STATUS_INVALID         = 0xFF
}VOICE_STATUS_FOR_ECR_E;
/* End Added by zhudingjingKF0104, 2013-06-26 of ������Դ�� */

/**
 * @struct tagMapRoadDirection
 * @brief ��ͼ��·����
 * @attention
 */
typedef enum tagMapRoadDirection
{
    MAP_ROAD_UP = 0,                       /**< ��·���� */
    MAP_ROAD_DOWN = 1,                     /**< ��·���� */
    MAP_ROAD_DOUBLE,                       /**< ��·˫�е� */
    MAP_ROAD_NONE,                         /**< δ֪���� */
    MAP_ROAD_MAX
}MAP_ROAD_DIRECTION_E;

/* Begin:Added by gaoshufeng(00762),2014-4-21 for MPPD11595 */
/**
* @enum tagONVIFTransPackMode
* @brief ONVIF����תTSģʽ
* @attention
*/
typedef enum tagONVIFTransPackMode
{
    ONVIF_TRANS_PACK_MODE_NO_TRANS                 = 0,   /**< ��ת������ʽ */
    ONVIF_TRANS_PACK_MODE_UDP_TS                   = 1,   /**< ONVIF����תUDP+TS */
    ONVIF_TRANS_PACK_MODE_RTP_TS                   = 2,   /**< ONVIF����תUDP+TS */

    ONVIF_TRANS_PACK_MODE_BUTT
}ONVIF_TRANS_PACK_MODE_E;

/* Begin: Added by luhaitao/01337, 2014-07-03 for ˫��·���� */
/**
* @enum tagONVIFTransPackMode
* @brief ONVIF����תTSģʽ
* @attention
*/
typedef enum tagBakeUpLinkFlag
{
    BAKE_UP_LINK_FLAG_NONE              = 0,   /**< ��������· */
    BAKE_UP_LINK_FLAG_MAST              = 1,   /**< ����· */
    BAKE_UP_LINK_FLAG_BAKE              = 2,   /**< ����· */

    BAKE_UP_LINK_FLAG_BUTT
}BAKE_UP_LINK_FLAG_E;
/* End: Added by luhaitao/01337, 2014-07-03 for ˫��·���� */

/* Begin add by zhengyibing(01306), 2014-04-19 for �¹����޶�*/
/**
 * @struct tagMapRoadDirection
 * @brief ģ����ѯ����
 * @attention
 */
typedef enum tagIndistinctQueryType
{
    INDISTINCT_QUERY_NULL = 0,                       /**< ������ģ����ѯ */  /* �ݲ�ʹ�ã�������չ*/
    INDISTINCT_QUERY_DOMAIN = 1,                     /**< ������в�ѯ */
    INDISTINCT_QUERY_DEVICE = 2,                       /**< ��ǰ���豸���в�ѯ */
    INDISTINCT_QUERY_ALL = 3,                         /**< ģ����ѯ:�����ǰ�˽��в�ѯ */
    INDISTINCT_QUERY_MAX
}INDISTINCT_QUERY_TYPE_E;

/**
 * @struct tagMapRoadDirection
 * @brief ¼���������
 * @attention
 */
typedef enum tagRecordQueryType
{
    RECORD_QUERY_TIME = 0,                           /**< �ƻ����ʹ洢�Ĳ�ѯ */
    RECORD_QUERY_ALARM = 1,                         /**< �澯���ʹ洢�Ĳ�ѯ */
    RECORD_QUERY_MANUAL = 2,                        /**< �ֶ��ٷ��洢�Ĳ�ѯ */
    RECORD_QUERY_ALL = 3,                            /**< ���д洢�Ĳ�ѯ */
    RECORD_QUERY_NONE = 4,                           /* ��Чֵ */
    RECORD_QUERY_MAX
}RECORD_QUERY_TYPE_E;
/* End add by zhengyibing(01306), 2014-04-19 for �¹����޶�*/
/* End:Added by gaoshufeng(00762),2014-4-21 for MPPD11595 */

/**
* @enum tagDBDevSubType
* @brief DB9500�豸������
* @attention
*/
typedef enum tagDBDevSubType
{
    DB_DEV_SUB_TYPE_S                 = 0,   /**< DB�ӷ����� */
    DB_DEV_SUB_TYPE_M                 = 1,   /**< DB�������� */
} DB_DEV_SUB_TYPE_E;
/* End:Added by gaoshufeng(00762),2014-4-21 for MPPD11595 */

/* Begin Add by zhengyibing(01306), 2014-05-30 for �¹����޸����� */
/**
 * @struct tagMapRoadDirection
 * @brief ��������ò�ѯ��ʽ
 * @attention
 */
typedef enum tagCameraConfgigQueryType
{
    CAMEAR_CONFIG_INFO_DEFAULT_CONFIG_QUEY = 0,                    /**< ������ѯ��ʽ(5��): ������������/��Ƶ�������÷�Χ/��Ƶ������ǰ����/��Ƶ�������÷�Χ/��Ƶ������ǰ���� */
    CAMEAR_CONFIG_INFO_SVC_ENCODE_CONFIG_QUEY = 1,                /**< ������ѯ��ʽ��SVAC�������ò�ѯ */
    CAMEAR_CONFIG_INFO_SVC_DECODE_CONFIG_QUEY = 2,                /**< ������ѯ��ʽ��SVAC�������ò�ѯ*/

    CAMERA_CONFIG_INFO_DEFAULT_AND_SVAENCODE_QUERY_TYPE = 3,    /* ������ѯ��ʽ+SVAC�����ѯ */
    CAMERA_CONFIG_INFO_DEFAULT_AND_SVADECODE_QUERY_TYPE = 4,    /* ������ѯ��ʽ+SVAC�����ѯ */
    CAMERA_CONFIG_INFO_DEFAULT_AND_SVADECODE_AND_SVACENCODE_QUERY_TYPE = 5,    /* ������ѯ��ʽ+SVAC�����ѯ+SVAC�����ѯ */

    CAMERA_CONFIG_INFO_TRANSFER = 6,                        /* ����ʽ��ֱ��͸����IPC */

    CAMEAR_CONFIG_INFO_QUERY_NONE = 7,                           /* ��Чֵ */
    CAMEAR_CONFIG_INFO_QUERY_MAX
}CAMERA_CONFIG_INFO_REQ_TYPE_E;



/* End Add by zhengyibing(01306), 2014-05-30 for �¹����޸����� */



/* Begin Add by zhengyibing(01306), 2014-10-20 for �¹���Ŀ¼�������޸� */
/**
 * @struct tagCatalogType
 * @brief �¼���Ŀ¼����: ֧��(0/1/2/3)
 * @brief �ϼ���Ŀ¼���ͷ�ʽ: ֧��(0/1/3)
 * @brief ƽ����Ŀ¼���غ����ͷ�ʽ: ֧��(0/1/3)
 * @attention
 */
typedef enum tagCatalogType
{
    DOMAIN_CATALOG_DEFAULT_MOUNT_TYPE = 0,                    /** ����ӦĬ�Ϲ��ط�ʽ */
    DOMAIN_CATALOG_UP_DEVICEID_MOUNT_TYPE = 1,                /** �����ϲ�DeviceID����(�ɹ��귽ʽ) */
    DOMAIN_CATALOG_CIVILCODE_MOUNT_TYPE = 2,                   /** �����������ط�ʽ*/
    DOMAIN_CATALOG_PARENTID_MOUNT_TYPE = 3,                    /* ����֯���ط�ʽ(parentid����) */
    DOMAIN_CATALOG_MOUNT_TYPE_NONE = 4,                           /* ��Чֵ */
    DOMAIN_CATALOG_MOUNT_TYPE_MAX
}DOMAIN_CATALOG_MOUNT_TYPE_E;
/* End Add by zhengyibing(01306), 2014-10-20 for �¹���Ŀ¼�������޸� */


typedef enum tagDevQueryType
{
    DEV_QUERY_IPC_WEBGPAE_URL = 10,           /**��ѯIPC����תURL  */
    DEV_QUERY_MAX,                         /**< ���ֵ */
    DEV_QUERY_INVALID  = 0xFFFF            /**< ��Чֵ */

} DEV_QUERY_TYPE_E;

/* Begin added by l01420, 2014-6-30 for �Զ���TSת����� */
/**
 * @enum tagTSRuleUAType
 * @brief TS UA����
 * @attention
 */
typedef enum tagTSRuleUAType
{
    TS_RULE_UA_SRC      = 0,
    TS_RULE_UA_DST      = 1,
}TS_RULE_UA_TYPE_E;

/**
 * @enum tagTSRuleSrcType
 * @brief TSת�����Դ����
 * @attention
 */
typedef enum tagTSRuleSrcType
{
    TS_RULE_SRC_CAMERA     = 0,            /* �����*/
    TS_RULE_SRC_ECR        = 1,            /* ECR*/
    TS_RULE_SRC_NVR        = 2,            /* NVR*/
    TS_RULE_SRC_DOMAIN     = 3,            /* ����(�¼���)*/
	TS_RULE_SRC_LV_DOMAIN  = 4,            /*ƽ����*/
    /* �Ƿ�ֵ */
    TS_RULE_SRC_INVALID
}TS_RULE_SRC_TYPE_E;

/**
 * @enum tagTSRuleSrcType
 * @brief TSת�����Ŀ������
 * @attention
 */
typedef enum tagTSRuleDstType
{
    TS_RULE_DST_MONITOR     = 0,        /* ������*/
    TS_RULE_DST_XP          = 1,        /* XP���������� */
    TS_RULE_DST_DOMAIN      = 2,        /* ����(�ϼ���)*/
	TS_RULE_DST_LV_DOMAIN   = 3,        /*ƽ����*/
    /* �Ƿ�ֵ */
    TS_RULE_DST_INVALID
}TS_RULE_DST_TYPE_E;

/* End added by l01420, 2014-6-30 for �Զ���TSת����� */

/**
 * @enum tagsServiceOnResType
 * @brief ��Դҵ��ö��
 * @attention
 */
typedef enum tagServiceOnResType
{
	/* ͨ����ҵ��ö�� 0--100 */
	SERVICE_ON_RES_TYPE_CAM_SHARE   	 			= 0,            /**<����������� */
	SERVICE_ON_RES_TYPE_ALARM_SRC_SHARE    		= 1,            /**<�澯Դ������ */
	SERVICE_ON_RES_TYPE_ALARM_OUT_SHARE    		= 2,            /**<�澯��������� */
    SERVICE_ON_RES_TYPE_STORE    				= 3,            /**< �����˴洢 */
    SERVICE_ON_RES_TYPE_BACKUP  					= 4,            /**< �����˱��� */
    SERVICE_ON_RES_TYPE_CAM_STREAM_STOR  		= 5,            /**< ��������ת�� */
   	SERVICE_ON_RES_TYPE_CASE_BAK 				= 6,            /**< �����˰������� */


	/* �豸��ҵ�� 101--200 */
	SERVICE_ON_RES_TYPE_TRANSPARENT_OPEN    	= 101,          /**< ͸��ͨ��������*/
	SERVICE_ON_RES_TYPE_TRANSPARENT_EXIST    	= 102,          /**< ����͸��ͨ��*/
	SERVICE_ON_RES_TYPE_CAM_EXIST 				= 103,          /**< ���������*/
	SERVICE_ON_RES_TYPE_ALARM_SRC_EXIST 		= 104,          /**< ���ڸ澯Դ*/
	SERVICE_ON_RES_TYPE_ALARM_OUT_EXIST 		= 105,          /**< ���ڸ澯���*/
	SERVICE_ON_RES_TYPE_MONITOR_EXIST 			= 106,          /**< ���ڼ�����*/
	SERVICE_ON_RES_TYPE_CAM_EXIST_FOR_ECR  		= 107,          /**< ����ECR/NVR�µ������*/
	SERVICE_ON_RES_TYPE_ALARM_SRC_EXIST_FOR_ECR = 108,         /**< ����ECR/NVR�µĸ澯Դ*/
	SERVICE_ON_RES_TYPE_ALARM_OUT_EXIST_FOR_ECR = 109,         /**< ����ECR/NVR�µĸ澯Դ*/

    SERVICE_ON_RES_TYPE_MAX,                     /**< �澯�豸ö�����ֵ */
    SERVICE_ON_RES_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}SERVICE_ON_RES_TYPE_E;

/* Begin add by l01420, 2014-7-10 for �����ֵ��������*/
/**
* @enum tagAlarmSrcType
* @brief �澯Դ����ö��
* @attention
*/
typedef enum tagAlarmSrcType
{
    ALARMSRC_CAM_FOLDER                 = 0,        /* �澯Դ-������ļ���*/
    ALARMSRC_BOOLEAN_FOLDER             = 1,        /* �澯Դ-�������ļ���*/
    ALARMSRC_GENERAL_FOLDER             = 2,        /* �澯Դ-�������豸�ļ���*/
    ALARMSRC_DEV_FOLDER                 = 3,        /* �澯Դ-�豸��ά�ļ���*/
    ALARMSRC_TOLLGATE_FOLDER            = 4,        /* �澯Դ-�����ļ���*/

    ALARMSRC_MAX                        = 0xff,
    ALARMSRC_INVALID
}ALARM_SRC_TYPE_E;
/* End add by l01420, 2014-7-10 for �����ֵ��������*/


/* Begin add by zhengyibing(01306), 2015-01-26 for onvif���������Ӧ����������*/
/**
 * @struct tagOnvifStreamPolicy
 * @brief onvif���������������
 * @attention
 */
typedef enum tagOnvifStreamPolicy
{
    ONVIF_STREAM_SELF_ADAPTION_POLICY = 0,            /**< ����Ӧ����, �ֱ������Ϊ�������ֱ�����СΪ���� */
    ONVIF_STREAM_FIRST_POLICY = 1,                      /**< ��������Ϊ��һ���� */
    ONVIF_STREAM_NONE_POLICY = 2,                           /* ��Чֵ */
    ONVIF_STREAM_MAX
}ONVIF_STREAM_POLICY_E;
/* End add by zhengyibing(01306), 2015-01-26 for onvif���������Ӧ����������*/

/* Added by y01693 for mppd21982 20150128 begin */
/**
* @enum tagTMSCombineType
* @brief TMS����Υ���ϳ���������
* @attention
*/
typedef enum tagTMSCombineType
{
    TMS_COMBINE_TOLLGATE                 = 0,   /**< ���� */
    TMS_COMBINE_E_POLICE                 = 1,   /**< �羯 */
    TMS_COMBINE_P2P                      = 2,   /**< ������� */
    TMS_COMBINE_VIOLATE_PARK_BALL        = 3,   /**< Υͣ�� */

    TMS_COMBINE_MAX,                            /**< ö�����ֵ */
    TMS_COMBINE_INVALID = 0xFFFFFFFF            /**< ��Чֵ */
} TMS_COMBINE_TYPE_E;
/* Added by  y01693  for mppd21982  20150128  end */

/* Begin Add By hexiaojun/hW0959 for ��̨�������̨�����Ƿ񾭹���̨������ 2015-1-21 */
/**
* @enum tagIsPassPTZCtroller
* @brief ѡ���Ƿ������̨������״̬ö��
* @attention
*/
typedef enum tagIsPassPTZCtroller
{
    CAMERA_NOT_PASS_PTZCTROLLER          = 0,    /**< ��������̨������ */
    CAMERA_PASS_PTZCTROLLER              = 1,    /**< ������̨������ */
    CAMERA_PASS_AND_NOTPASS_PTZCTROLLER  = 2,    /**< ѡ��ȫ��ȫ��*/
    CAMERA_NOT_PASS_AND_NOTPASS_PTZCTROLLER =3,  /**< ��ѡ���κ���̨����� */

    PASS_STATUS_MAX,                    /**< ö�����ֵ */
    PASS_STATUS_INVALID    = 0xFFFFFFFF /**< ��Чֵ */
}IS_PASS_PTZCTROLLER_E;
/* End Add By hexiaojun/hW0959 for ��̨�������̨�����Ƿ񾭹���̨������ 2015-1-21 */

/* Begin: Added by zhongke, 2015-05-11 for CDS�ƴ洢 */
/**
* @enum tagCruiseInfoChangeType
* @brief Ѳ����Ϣ�������
* @attention
*/
typedef enum tagCruiseInfoChangeType
{
    CRUISE_INFO_CHANGE_TYPE_PATH_ADD   = 0,     /**< Ѳ��·������ */
    CRUISE_INFO_CHANGE_TYPE_PATH_MOD,           /**< Ѳ��·���޸� */
    CRUISE_INFO_CHANGE_TYPE_PATH_DEL,           /**< Ѳ��·��ɾ�� */
    CRUISE_INFO_CHANGE_TYPE_PLAN_ADD,           /**< Ѳ���ƻ����� */
    CRUISE_INFO_CHANGE_TYPE_PLAN_MOD,           /**< Ѳ���ƻ��޸� */
    CRUISE_INFO_CHANGE_TYPE_PLAN_DEL,           /**< Ѳ���ƻ�ɾ�� */

    CRUISE_INFO_CHANGE_TYPE_MAX,
    CRUISE_INFO_CHANGE_TYPE_INVALID = 0xFFFFFFFF

}CRUISE_INFO_CHANGE_TYPE_E;

/**
* @enum tagAsCruiseChgInfo
* @brief Ѳ����Ϣ�����Ϣ�ṹ
* @attention
*/
typedef struct tagAsCruiseChgInfo
{
    CHAR szCameraCode[IMOS_CODE_LEN];           /**< ��������� */
    ULONG ulChangeType;                         /**< ��Ϣ�������  CRUISE_INFO_CHANGE_TYPE_E */
    IMOS_ID idChangeInfoId;                     /**< �����ϢID */
}AS_CRUISE_CHANGE_INFO_S;
/* End: Added by zhongke, 2015-05-11 for CDS�ƴ洢 */

/**
* @enum tagExdomainOperType
* @brief �����������
*/
typedef enum tagExdomainOperType
{
    EXDOMAIN_OPER_ADD       = 0,    /** <�����������: ���*/
    EXDOMAIN_OPER_MOD       = 1,    /** <�����������: �޸�*/
    EXDOMAIN_OPER_DEL       = 2,    /** <�����������: ɾ��*/

    EXDOMAIN_OPER_MAX,
    EXDOMAIN_OPER_INVALID   = 0xFFFF
}EXDOMAIN_OPER_TYPE_E;

/**
* @enum tagPdtType
* @brief ��Ʒ����
*/
typedef enum tagPdtType
{
    PDT_TYPE_IMOS           = 0,    /** <IMOS��Ʒ*/
    PDT_TYPE_NONBRAND       = 1,    /** <���Ʋ�Ʒ*/

    PDT_TYPE_MAX,
    PDT_TYPE_INVALID        = 0xFF
}PDT_TYPE_E;

/*Begin added by liangchao, 2015-11-25 for BM2516������:��ӱ���һ�������licenseУ��*/
/**
 * @enum tagBMDevType
 * @brief �澯�豸����
 * @attention
 */
typedef enum tagBMDevType
{
    BM_DEV_TYPE_3_0       = 0,            /**< BM3.0 */
    BM_DEV_TYPE_BM2516_DA = 1,            /**< BM2516-DA */
    BM_DEV_TYPE_BM8516    = 2,            /**< BM8516 */
    BM_DEV_TYPE_BM8500_E  = 3,            /**< BM8500-E */
    /* Begin: Add by lW2822, 2016-09-29 for ƽ̨����BM9500 */
    BM_DEV_TYPE_BM9500    = 4,            /**< BM9500 */
    /* End: Add by lW2822, 2016-09-29 for ƽ̨����BM9500 */

    BM_DEV_TYPE_MAX,                     /**< BM�豸ö�����ֵ */
    BM_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}BM_DEV_TYPE_E;
/*End added by liangchao, 2015-11-25 for BM2516������:��ӱ���һ�������licenseУ��*/

/*Begin added by liangchao, 2015-12-18 for IAFA license���*/
/**
 * @enum tagIADevType
 * @brief ������������
 * @attention
 */
typedef enum tagIADevType
{
    IA_DEV_TYPE_IAHR  = 0,            /**< IAHR */
    IA_DEV_TYPE_IAFA  = 1,            /**< IAFA */
    IA_DEV_TYPE_IAIT  = 2,			  /**< IAIT */
    IA_DEV_TYPE_IAM  = 3,            /**< IAM */

    IA_DEV_TYPE_MAX,                     /**< IA�豸ö�����ֵ */
    IA_DEV_TYPE_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}IA_DEV_TYPE_E;
/*End added by liangchao, 2015-12-18 for IAFA license���*/

/* Begin added by y01359, 2016-04-12 for A8 */
/**
 * @enum tagTVWallMonitorAlarmOperateType
 * @brief ����ǽʵ���澯��������
 * @attention
 */
typedef enum tagTVWallMonitorAlarmOperateType
{
    TVWALL_MONITOR_ALARM_STOP   = 0,            /**< ֹͣ����ǽʵ���澯 */
    TVWALL_MONITOR_ALARM_START  = 1,            /**< ��������ǽʵ���澯 */

    TVWALL_MONITOR_ALARM_INVALID = 0xFFFFFFFF     /**< ��Чֵ */

}TVWALL_MONITOR_ALARM_OPERATE_TYPE_E;
/* End added by y01359, 2016-04-12 for A8 */

/* Begin added by c02845,2016-05-12,��ͨ����Ϣ����*/
/**
 * @enum tagTrafficQueryType
 * @brief  ��ѯʱ�䷽ʽ
 * @attention ���ա��¡���ȷ�ʽ
 */
typedef enum tagTrafficQueryTime
{
    TRAFFIC_QUERY_TIME_DAY    = 0,              /**< ���ղ�ѯ */
    TRAFFIC_QUERY_TIME_MOMTH  = 1,              /**< ���²�ѯ */
    TRAFFIC_QUERY_TIME_YEAR   = 2,              /**< �����ѯ */

    TRAFFIC_QUERY_TIME_MAX,                     /**< ��ѯ��ʽ���ֵ */
    TRAFFIC_QUERY_TIME_INVALID = 0xFFFFFFFF    /**< ��Чֵ */

}TRAFFIC_QUERY_TIME_E;


/**
 * @enum tagTrafficQueryType
 * @brief  ��ѯ��Ϣ����
 * @attention ������������ƽ�����١�ƽ���Ŷӳ��ȵ���Ϣ����
 */
typedef enum tagTrafficQueryType
{
    TRAFFIC_QUERY_TYPE_VEHICLE_COUNT    = 0,              /**< �������� */
    TRAFFIC_QUERY_TYPE_AVG_SPEED        = 1,              /**< ƽ���ٶ� */
    TRAFFIC_QUERY_TYPE_QUEUE_LENGTH     = 2,              /**< �Ŷӳ��� */

    TRAFFIC_QUERY_TYPE_MAX,                     /**< ��ѯ��ʽ���ֵ */
    TRAFFIC_QUERY_TYPE_INVALID = 0xFFFFFFFF    /**< ��Чֵ */

}TRAFFIC_QUERY_TYPE_E;

/* End by c02845,2016-05-12,��ͨ����Ϣ����*/

/* Begin added by s03924 for MPPD53784 2017/11/25 */
/**
 * @enum tagTrafficFlowState
 * @brief ��ͨ��ӵ��״̬
 * @attation
 */
typedef enum tagTrafficFlowState
{
	TRAFFIC_FLOW_CONGESTION             = 1,              /**< �������� */
	TRAFFIC_FLOW_CONGESTION_RECOVERY    = 2,              /**< ��������ָ� */
	TRAFFIC_FLOW_NORMAL                 = 3,              /**< ���� */
	TRAFFIC_FLOW_LOW                    = 4,              /**< �������� */
	TRAFFIC_FLOW_LOW_RECOVERY           = 5,              /**< ��������ָ� */
}TRAFFIC_FLOW_STATE_E;
/* End added by s03924 for MPPD53784 2017/11/25 */

typedef enum tagNetworkModeType
{
    NET_WORK_MODE_MULTI_ADDRESS   = 0x1, /* ��ַ */
    NET_WORK_MODE_BLANCE          = 0x2,      /* ���ؾ��� */
    NET_WORK_MODE_FAULT_TOLERANT  = 0x4,/* �����ݴ� */
    NET_WORK_MODE_BUTT
} NET_WORK_MODE_TYPE_E;

/* Begin Add By hexiaojun/h02450 for BM֧��CDS�洢 2016-2-25 */
/**
* @enum tagStorServiceType
* @brief �洢��������
* @attention
*/
typedef enum tagStorServiceType
{
    STOR_SERVICE_TYPE_DM    = 0,    /** ���ݹ��������(DM) */
    STOR_SERVICE_TYPE_CDS   = 1,    /** CDS */

    STOR_SERVICE_TYPE_MAX,
    STOR_SERVICE_TYPE_INVALID = 0xFFFFFFFF
}STOR_SERVICE_TYPE_E;
/* End Add By hexiaojun/h02450 for BM֧��CDS�洢 2016-2-25 */

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
/**
 * @enum tagIOTDevType
 * @brief  IOT �豸����
 * @attention
 */
typedef enum tagIOTDevType
{
    IOT_DEV_TYPE_DAE_2000    = 200,            /**< DAE2000 */
    IOT_DEV_TYPE_DAE_6000    = 600,            /**< DAE6000 */

    IOT_DEV_TYPE_MAX,                        /**< IOT�豸�������ֵ */
    IOT_DEV_TYPE_INVALID     = 0xFF          /**< ��Чֵ */
}IOT_DEV_TYPE_E;

/**
* @enum tagWirelessInspection
* @brief ���߼������ö��(2200)
* @attention
*/
typedef enum tagWirelessInspection
{
    UNKNOWN_WIRELESS_INSPECTION = 0,                      /**< δ֪ */
    RFID_WIRELESS_INSPECTION = 1,                         /**< RFID����� */
    WIFI_SNIFFER_WIRELESS_INSPECTION = 2,                 /**< WiFi sniffer����� */
    ZIGBEE_WIRELESS_INSPECTION = 3,                       /**< zigbee����� */
    BLUETOOTH_WIRELESS_INSPECTION = 4,                    /**< ��������� */

    WIRELESS_INSPECTION_MAX,                              /**< ���߼������ö�����ֵ */
    WIRELESS_INSPECTION_INVALID = 0xFF                    /**< ��Чֵ */
}WIRELESS_INSPECTION_E;

/**
* @enum tagSensorType
* @brief ����������ö��(2201)
* @attention
*/
typedef enum tagSensorType
{
    UNKNOWN_SENSOR = 0,                                    /**< δ֪ */
    TEMPERATURE_SENSOR = 1,                                /**< �¶� */
    HUMIDITY_SENSOR = 2,                                   /**< ʪ�� */
    WIND_DIRECTION_SENSOR = 3,                             /**< ���� */
    RAINFALL_SENSOR = 4,                                   /**< ����/��ˮ�� */
    PM25_SENSOR = 5,                                       /**< PM2.5 */
    PM100_SENSOR = 6,                                      /**< PM10.0 */
    CHANNEL_WATER_LEVEL_SENSOR = 7,                        /**< �ӵ�ˮλ */
    NOISE_SENSOR = 8,                                      /**< ���� */
    ELECTRICITY_CONSUMPTION_SENSOR = 9,                    /**< �õ��� */
    UNDETERMINED_SENSOR = 10,                              /**< ���� */
    SMOKE_SENSOR = 11,                                     /**< ���� */
    GPS_BIG_DIPPER_SENSOR = 12,                            /**< GPS/���� */
    PUT_INTO_TYPE_LIQUID_LEVEL_SENSOR = 13,                /**< Ͷ��ʽҺλ�� */
    IMMERSION_DETECTOR_SENSOR = 14,                        /**< ˮ������� */
    O2_CONCENTRATION_SENSOR = 15,                          /**< O2Ũ�ȼ���� */
    H2S_CONCENTRATION_SENSOR = 16,                         /**< H2SŨ�ȼ���� */
    CH4_CONCENTRATION_SENSOR = 17,                         /**< CH4Ũ�ȼ���� */
    CO_CONCENTRATION_SENSOR = 18,                          /**< COŨ�ȼ���� */
    LINEAR_OPTICAL_FIBER_TEMPERATURE_SENSING_SENSOR = 19,  /**< ���͹��˸���̽���� */
    TURBIDITY_SENSOR = 20,                                 /**< �Ƕ� */

    SENSOR_TYPE_MAX,                                       /**< ����������ö�����ֵ */
    SENSOR_TYPE_INVALID = 0xFF                             /**< ��Чֵ */
}SENSOR_TYPE_E;

/**
* @enum tagPowerEquipmentType
* @brief �����豸����ö��(2202)
* @attention
*/
typedef enum tagPowerEquipmentType
{
    UNKNOWN_POWER_EQUIPMENT = 0,            /**< δ֪�����豸���� */
    WATER_PUMP = 1,                         /**< ˮ�� */
    FAN = 2,                                /**< ��� */
    AIR_VALVE = 3,                          /**< �緧 */
    ELECTRONIC_MANHOLE_COVER = 4,           /**< ���Ӿ��� */
    AUTOMATIC_FIRE_EXTINGUISHER = 5,        /**< �Զ������ */
    THE_ACCESS_CONTROLLER = 6,              /**< �Ž������� */

    POWER_EQUIPMENT_TYPE_MAX,               /**< �����豸����ö�����ֵ */
    POWER_EQUIPMENT_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}POWER_EQUIPMENT_TYPE_E;

/**
* @enum tagCommunicationEquipmentType
* @brief ͨ���豸����ö��(2203)
* @attention
*/
typedef enum tagCommunicationEquipmentType
{
    UNKNOWN_COMMUNICATION_EQUIPMENT = 0,            /**< δ֪�����豸���� */
    ACOUSTOOPTIC_ALARM = 1,                         /**< ���ⱨ���� */
    MEGAPHONE = 2,                                  /**< ������ */
    INDUSTRIAL_TELEPHONE_SET = 3,                   /**< ��ҵ�绰�� */
    WIRELESS_AP = 4,                                /**< ����AP */

    COMMUNICATION_EQUIPMENT_TYPE_MAX,               /**< ͨ���豸����ö�����ֵ */
    COMMUNICATION_EQUIPMENT_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}COMMUNICATION_EQUIPMENT_TYPE_E;

/**
* @enum tagOtherEquipmentType
* @brief �����豸����ö��(2250)
* @attention
*/
typedef enum tagOtherEquipmentType
{
    UNKNOWN_OTHER_EQUIPMENT = 0,            /**< δ֪�����豸���� */
    UPS = 1,                                /**< UPS */
    BATTERY = 2,                            /**< ���� */
    LED = 3,                                /**< LED�� */
    INFRARED_COUNTER_DETECTOR = 4,          /**< �������̽���� */

    OTHER_EQUIPMENT_TYPE_MAX,               /**< �����豸����ö�����ֵ */
    OTHER_EQUIPMENT_TYPE_INVALID = 0xFF     /**< ��Чֵ */
}OTHER_EQUIPMENT_TYPE_E;

/**
* @enum tagASIOTResStatus
* @brief ������������Դ״̬ö��
* @attention
*/
typedef enum tagASIOTResStatus
{
    AS_IOT_RES_STATUS_ONLINE         = 1,    /**< ��Դ���� */
    AS_IOT_RES_STATUS_OFFLINE        = 2,    /**< ��Դ���� */
    AS_IOT_RES_STATUS_ONLINE_ON      = 3,    /**< ��Դ���ߣ��ҿ������� */
    AS_IOT_RES_STATUS_ONLINE_OFF     = 4,    /**< ��Դ���ߣ��ҿ������ر� */
    AS_IOT_RES_STATUS_OFFLINE_ON     = 5,    /**< ��Դ���ߣ��ҿ������� */
    AS_IOT_RES_STATUS_OFFLINE_OFF    = 6,    /**< ��Դ���ߣ��ҿ������ر� */

    AS_IOT_RES_STATUS_MAX,
    AS_IOT_RES_STATUS_INVALID = 0xFFFFFFFF
}AS_IOT_RES_STATUS_E;
/* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

/* Begin: Added by chenmenglin 04110, 2017-09-11 for MPPD54245 A8ƴ���豸��Ѳ���� */
/**
* @enum tagAutoPollReaveType
* @brief A8ƴ���Զ�������Ѳ��ռ����
* @attention
*/
typedef enum tagAutoPollReaveType
{
    AUTOPOLL_REAVE_TYPE_NOREAVE     =  0,           /**< ����ռ */
    AUTOPOLL_REAVE_TYPE_REAVE       =  1,           /**< ��ռ */

    AUTOPOLL_REAVE_TYPE_MAX,                        /**< �Զ�������Ѳ��ռ�������ֵ */
    AUTOPOLL_REAVE_TYPE_INVALID = 0XFFFFFFFF
}AUTOPOLL_REAVE_TYPE_E;
/* End: Added by chenmenglin 04110, 2017-09-11 for MPPD54245 A8ƴ���豸��Ѳ���� */

/* Begin: Added by l03769, 2017-12-21 for MPPD53844 ��������Դ������� */
/**
* @enum tagIOTDevAttribute
* @brief �������豸����
* @attention
*/
typedef enum tagIOTDevAttribute
{
    UNKNOW_IOT_DEV    = 0,     /**< δ֪���� */
    FIXTURE_IOT_DEV   = 1,     /**< �̶�IOT�豸 */
    MOBILE_IOT_DEV    = 2,     /**< �ƶ�IOT�豸 */

    IOT_DEV_ATTRIBUTE_MAX,
    IOT_DEV_ATTRIBUTE_INVALID = 0xFFFFFFFF
}IOT_DEV_ATTRIBUE_E;
/* End: Added by l03769, 2017-12-21 for MPPD53844 ��������Դ������� */

/*Begin added by liuyufei l04448 for MPPD54774 Xware��������,Dec 28, 2017*/
/**
* @enum tagXwareVIType
* @brief Xware�豸��Ƶ����˿�����
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
/*End added by liuyufei l04448 for MPPD54774 Xware��������,Dec 28, 2017*/

/* Begin: Added by chenmenglin 04110, 2018-01-23 for MPPD54841 �������δ�󶨼�����δ���������� */
/**
* @enum tagMonitorBindStatus
* @brief ����ƴ���豸��������״̬
* @attention
*/
typedef enum tagMonitorBindStatus
{
    MONITOR_BIND_STATUS_UNBIND     = 0,           /**< δ�� */
    MONITOR_BIND_STATUS_BIND       = 1,           /**< �� */

    MONITOR_BIND_STATUS_MAX,                      /**< ����ƴ���豸��������״̬���ֵ */
    MONITOR_BIND_STATUS_INVALID    = 0XFFFFFFFF
}MONITOR_BIND_STATUS_E;
/* End: Added by chenmenglin 04110, 2018-01-23 for MPPD54841 �������δ�󶨼�����δ���������� */

#endif /* end of __cplusplus */

#endif

