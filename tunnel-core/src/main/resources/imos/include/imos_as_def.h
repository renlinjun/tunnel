/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_as_def.h

  Project Code: IMOS
   Module Name: AS��CS��������ͷ�ļ�
  Date Created: 2009-03-19
        Author: Baogang/03821
   Description: ����AS��CS��������ʹ�õĺꡢö��

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------

*******************************************************************************/

#ifndef __IMOS_AS_DEF_H__
#define __IMOS_AS_DEF_H__

#ifdef  __cplusplus
extern "C"{
#endif

/** @brief XP��󴰸���Ŀ */
#define AS_XP_WIN_MAX_NUM 512

/** @brief �û�����XP��󴰸���Ŀ��Ĭ��ֵ */
#define AS_XP_WIN_DEFAULT_NUM_FOR_USER 25

/** @brief ��������������豸�� */
#define UM_MAX_DEVICENUM_INJOB 200

/** @brief Ptzģ���Ԥ��λ����Сֵ */
#define PTZ_PRESET_MINVALUE      1

/** @brief Ptzģ���Ԥ��λ����Чֵ */
#define PTZ_PRESET_INVALIDVALUE  0XFFFF

/** @brief ��̨�ͷ�ʱ����Сֵ���ο�Ĭ��ֵ����̰���ӣ����浥λΪ�� */
#define MIN_PTZ_RELEASE_TIME     30

/** @brief ��̨�ͷ�ʱ�����ֵ���ο�Ĭ��ֵ���60���ӣ����浥λΪ�� */
#define MAX_PTZ_RELEASE_TIME     3600

/** @brief ����ʱ������Сֵ����λ�Ǻ��� */
#define MIN_TIME_SWITCH_INTERVAL 5000

/** @brief ����ʱ�������ֵ����λ�Ǻ��� */
#define MAX_TIME_SWITCH_INTERVAL 3600000

/** @brief �������ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_CAMERA   8

/** @brief DM��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_DM       1

/** @brief DM��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_CDM       1

/* Begin: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */
/** @brief CDS��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_CDS       1
/* End: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */

/* begin: added by yW1054 in 2014-9-4 for VOD�豸 */
/** @brief VOD��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_VOD       1
/* end: added by yW1054 in 2014-9-4 for VOD�豸*/

/** @brief MS��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_MS       1

/** @brief TS��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_TS       1

/*Begin added by liangchao, 2015-11-25 for BM2516������*/
/** @brief BM��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_BM       1
/*End added by liangchao, 2015-11-25 for BM2516������*/


/* begin: added by yW1054 in 2014-8-21 for logserver */
/** @brief LS��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_LS       0
/* end: added by yW1054 in 2014-8-21 for logserver*/


/** @brief �洢�豸��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_STORAGE_DEV  1

/** @brief SDC��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_SDC  1

/** @brief ONVIF��������洢ģʽ */
#define AS_ONVIF_SPECIAL_STOR_MODE_ENABLE           1

/** @brief ONVIF����������洢ģʽ */
#define AS_ONVIF_SPECIAL_STOR_MODE_DISENABLE        0

/* Begin modified by b00103, 2012-10-31 of VVD75062 */
/** @brief TMS��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_TMS      1

/** @brief �������洢��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_THIRD_STOR      1

/* Begin added by baoyihui02795, 2011-05-03 of ������Ŀ */
/** @brief ���������ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_TOLLGATE_CAMERA      0
/* End modified by b00103, 2012-10-31 of VVD75062 */

/** @brief �洢�豸��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_STORAGE_DEV  1
/* End added by baoyihui02795, 2011-05-03 of ������Ŀ */

/* Begin: Added by z00293 for ����ʵսLicense */
/** @brief ����ʵսͼ��ͻ���ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_GASRV_ICSCI   0

/** @brief ����ʵսCAMERAȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_GASRV_CAMERA  8

/** @brief �����������ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_EXTERNAL_CAMERA   0

/** @brief ����ʵսΥ��ץ�Ŀͻ���ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_GASRV_ICC         0
/* End: Added by z00293 for ����ʵսLicense */

/*Begin added by l02274 2015-6-23, for map license У��*/
#define AS_DEFAULT_LICENSE_FOR_MAPM 0
/*End added by l02274 2015-6-23, for map license У��*/

/** @brief DB9500ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_DB         0

/** @brief DR9500ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_DR9500    0

/** @brief DR8500ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_DR8500    0

/** @brief IAHR��ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_IAHR             1

/** @brief �ƶ�ָ�ӵ��ȿͻ���/�ƶ�ִ���ͻ��� ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_GASRV_MCD_OR_MLE        1

/** @brief �ƶ�ǰ�� ȱʡLicense��� */
#define AS_DEFAULT_LICENSE_FOR_MOBILE_CAMERA  1

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */
/** @brief ���������ֶ� */
#define  AM_SIP_KEY_OPERATETYPE  "OperateType"

/** @brief ��Ƶ����ͨ�� */
#define  AM_SIP_KEY_VIDEO_INPUT  "VI"

/** @brief ��Ƶ���ͨ�� */
#define  AM_SIP_KEY_VIDEO_OUTPUT "VO"

/** @brief ��Ƶ����ͨ�� */
#define  AM_SIP_KEY_AUDIO_INPUT "AI"

/** @brief ��Ƶ���ͨ�� */
#define  AM_SIP_KEY_AUDIO_OUTPUT "AO"

/** @brief �澯����ͨ�� */
#define  AM_SIP_KEY_ALARM_INPUT "AlarmIn"

/** @brief �澯���ͨ�� */
#define  AM_SIP_KEY_ALARM_OUTPUT "AlarmOut"
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */

/* Begin: Added by huangsen W4381, 2017-10-25 for MPPD49831 Xware ժҪ���޸�*/
#define  AM_SIP_KEY_ABSTRACT "Abstract"
/* End: Added by huangsen W4381, 2017-10-25 for MPPD49831 Xware ժҪ���޸�*/

/** @brief �������� */
typedef enum tagSerialType
{
    SERIAL_TYPE_RS232 = 1,          /**< RS232 */
    SERIAL_TYPE_RS422 = 2,          /**< RS422 */
    SERIAL_TYPE_RS485 = 3,          /**< RS485 */

    SERIAL_TYPE_MAX,
    SERIAL_TYPE_INVALID = 0xFF
}SERIAL_TYPE_E;

/**
* @enum tagPlanType
* @brief �ƻ�����
* @attention ��
*/
typedef enum tagPlanType
{
    PLAN_TYPE_DAY       = 0,        /**< �ռƻ� */
    PLAN_TYPE_WEEK,                 /**< �ܼƻ� */

    PLAN_TYPE_MAX,
    PLAN_TYPE_INVALID   = 0xFF
}PLAN_TYPE_E;

/** @brief �洢���� */
typedef enum tagASDEVCMStorageType
{
    STORAGE_TYPE_IPSAN = 0,             /**< IPSAN�洢 */
    STORAGE_TYPE_NAS = 1,               /**< NAS�洢 */
    STORAGE_TYPE_LOCAL = 2,             /**< ���ش洢 */
    STORAGE_TYPE_SHARE_LOCAL = 3,       /**< �ռ乲���ش洢 */
    STORAGE_TYPE_LOCAL_MAS = 4,         /**< ����MAS�洢 */
    STORAGE_TYPE_THIRD_RES = 5,         /**< �������洢��Դ */
    STORAGE_TYPE_CDM_SHARE_DIRECT = 7,  /**< CDM��Ƶֱ��, ö��ֵ3~6�ѱ�IPC����Ϊ��������, ƽ̨˳�ӵ�7��ʼ���� */
    STORAGE_TYPE_CDS_TG_SHARE_DIRECT = 8,/**< CDS����ֱ��*/

    STORAGE_TYPE_MAX,
    STORAGE_TYPE_INVALID = 0xFF
}AS_DEVCM_STORAGE_TYPE_E;

/** @brief ���������� */
typedef enum tagASDEVCMDiskFullPolicy
{
    DISK_FULL_POLICY_STOP = 0,      /**< ������ֹͣ�洢 */
    DISK_FULL_POLICY_OVERLOAD= 1,   /**< ���������Ǵ洢 */

    DISK_FULL_POLICY_MAX,
    DISK_FULL_POLICY_INVALID = 0xFF
} AS_DEVCM_DISK_FULL_POLICY_E;


/** @brief ҵ��ǰ״̬ */
typedef enum tagSRVState
{
    SRV_STATE_IDLE = 0,             /**< ����״̬ ʵ�������С�����ʾ������Ѳ����ҵ��״̬ */
    SRV_STATE_ACTIVE,               /**< ����״̬ ʵ�������С�����ʾ������Ѳ����ҵ��״̬ */
    SRV_STATE_PAUSE,                /**< ��ͣ״̬ ���С�����Ѳ����ҵ��״̬ */
    SRV_STATE_UNACTIVE,             /**< ����״̬ ʵ�������С�����Ѳ����ҵ��״̬ */
    SRV_STATE_SUSPEND,              /**< ����״̬ ����ҵ��״̬ */

    SRV_STATE_MAX,                  /**< ���ֵ */
    SRV_STATE_INVALID = 0xFF        /**< ��Чֵ */
}SRV_STATE_E;

/** @brief ҵ���ͷ�ԭ���� */
typedef enum tagSRVReleaseCode
{
    SRV_RELEASE_REBUILD_STREAM       = 1000,  /**< �ն˻���MS�����ؽ�����ע�⣬ö��ֵ�����IMOS_REBUILD_STREAMһ��*/
    SRV_RELEASE_USER_KEEPALIVE_FAIL  = 1001,  /**< �û�����ʧ�ܵ��¸��û���ҵ�񱻷�����ǿ���ͷ� */
    SRV_RELEASE_USER_KICKED_OUT      = 1002,  /**< �û���ǿ�����ߵ��¸��û���ҵ�񱻷�����ǿ���ͷ� */
    SRV_RELEASE_USER_DELETE          = 1003,  /**< �û���ɾ�����¸��û���ҵ�񱻷�����ǿ���ͷ� */
    SRV_RELEASE_CAMERA_OFFLINE       = 2001,  /**< ��������ߵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_CAMERA_PARAM_CHANGE  = 2002,  /**< ������Ĳ������޸ĵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_MS_OFFLINE           = 2003,  /**< �����ý��ת����MS���ߵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_TS_OFFLINE           = 2004,  /**< �����ý��ת����TS���ߵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_VOD_OFFLINEORDELETE  = 2005,  /**< ������طŵ�VOD���������߻�ɾ�����¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_MONITOR_OFFLINE      = 3001,  /**< ���������ߵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_MONITOR_PARAM_CHANGE = 3002,  /**< �������Ĳ������޸ĵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_EX_DOMAIN_OFFLINE    = 4001,  /**< �������ߵ��¸�ҵ�񱻷������ͷ� */
    SRV_RELEASE_SERVER_PROC_ERR      = 5001,  /**< �������ڴ���ҵ������Ĺ����г��ִ����µ�ҵ���ͷ� */
    SRV_RELEASE_OTHER_USER_REAVE     = 6001,  /**< ҵ�������û���ռ�ͷ� */
    SRV_RELEASE_SWITCH_SPLIT_SCR     = 7001,  /**< �л�����������ģʽ */
    /* Added by gaoshufeng(00762),2013-1-22 for IVSD00191 */
    SRV_RELEASE_INSUFFICIENT_DC_ABILITY = 7002,  /**< ������������������ */
    SRV_RELEASE_LINK_TO_RESUME       = 8001,  /**< �澯��������������ָ� */
    SRV_RELEASE_LINK_TO_STOP         = 9001,  /**< �澯���������������ͷ� */

    SRV_RELEASE_CODE_MAX,                     /**< ���ֵ */
    SRV_RELEASE_CODE_INVALID = 0xFFFF         /**< ��Чֵ */
}SRV_RELEASE_CODE_E;

/* Begin modifyed by kf0092, 2012-12-04 for PAG�ӹ��� */
/**
* enum tagCameraManutype
* brief ������IPC���������ö��ֵ
* @attention ��
*/
typedef enum tagCameraManutype
{
    CAMERA_MANU_TYPE_ONVIF1_0      = 0,                /* ONVIF1.0 IPC */
    CAMERA_MANU_TYPE_ONVIF2_0      = 1,                /* ONVIF2.0 IPC */
    CAMERA_MANU_TYPE_ONVIF2_1      = 2,                /* ONVIF2.1 IPC */
    CAMERA_MANU_TYPE_GUOBIAO       = 9,                /* ���� IPC */
    /* Begin added by j00350 for MPPD08948, 20140120 */
    CAMERA_MANU_TYPE_MOBILE        = 19,               /* ͨ���ƶ��豸 */
    /* End added by j00350 for MPPD08948, 20140120 */

    CAMERA_MANU_TYPE_INVALID
}AS_CAMERA_MANU_TYPE_E;
/* End modifyed by kf0092, 2012-12-04 for PAG�ӹ��� */


#ifdef  __cplusplus
}
#endif

#endif  /** __IMOS_AS_DEF_H__ */


