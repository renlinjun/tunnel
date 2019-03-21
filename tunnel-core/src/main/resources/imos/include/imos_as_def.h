/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_as_def.h

  Project Code: IMOS
   Module Name: AS、CS公共对外头文件
  Date Created: 2009-03-19
        Author: Baogang/03821
   Description: 定义AS、CS公共对外使用的宏、枚举

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

/** @brief XP最大窗格数目 */
#define AS_XP_WIN_MAX_NUM 512

/** @brief 用户允许XP最大窗格数目的默认值 */
#define AS_XP_WIN_DEFAULT_NUM_FOR_USER 25

/** @brief 单个任务中最大设备数 */
#define UM_MAX_DEVICENUM_INJOB 200

/** @brief Ptz模块的预置位的最小值 */
#define PTZ_PRESET_MINVALUE      1

/** @brief Ptz模块的预置位的无效值 */
#define PTZ_PRESET_INVALIDVALUE  0XFFFF

/** @brief 云台释放时间最小值，参考默认值，最短半分钟，下面单位为秒 */
#define MIN_PTZ_RELEASE_TIME     30

/** @brief 云台释放时间最大值，参考默认值，最长60分钟，下面单位为秒 */
#define MAX_PTZ_RELEASE_TIME     3600

/** @brief 轮切时间间隔最小值，单位是毫秒 */
#define MIN_TIME_SWITCH_INTERVAL 5000

/** @brief 轮切时间间隔最大值，单位是毫秒 */
#define MAX_TIME_SWITCH_INTERVAL 3600000

/** @brief 摄像机的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_CAMERA   8

/** @brief DM的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_DM       1

/** @brief DM的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_CDM       1

/* Begin: Added by zhongke, 2015-03-02 for CDS云存储 */
/** @brief CDS的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_CDS       1
/* End: Added by zhongke, 2015-03-02 for CDS云存储 */

/* begin: added by yW1054 in 2014-9-4 for VOD设备 */
/** @brief VOD的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_VOD       1
/* end: added by yW1054 in 2014-9-4 for VOD设备*/

/** @brief MS的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_MS       1

/** @brief TS的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_TS       1

/*Begin added by liangchao, 2015-11-25 for BM2516合主线*/
/** @brief BM的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_BM       1
/*End added by liangchao, 2015-11-25 for BM2516合主线*/


/* begin: added by yW1054 in 2014-8-21 for logserver */
/** @brief LS的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_LS       0
/* end: added by yW1054 in 2014-8-21 for logserver*/


/** @brief 存储设备的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_STORAGE_DEV  1

/** @brief SDC的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_SDC  1

/** @brief ONVIF开启特殊存储模式 */
#define AS_ONVIF_SPECIAL_STOR_MODE_ENABLE           1

/** @brief ONVIF不开启特殊存储模式 */
#define AS_ONVIF_SPECIAL_STOR_MODE_DISENABLE        0

/* Begin modified by b00103, 2012-10-31 of VVD75062 */
/** @brief TMS的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_TMS      1

/** @brief 第三方存储的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_THIRD_STOR      1

/* Begin added by baoyihui02795, 2011-05-03 of 卡口项目 */
/** @brief 卡口相机的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_TOLLGATE_CAMERA      0
/* End modified by b00103, 2012-10-31 of VVD75062 */

/** @brief 存储设备的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_STORAGE_DEV  1
/* End added by baoyihui02795, 2011-05-03 of 卡口项目 */

/* Begin: Added by z00293 for 公安实战License */
/** @brief 公安实战图侦客户端缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_GASRV_ICSCI   0

/** @brief 公安实战CAMERA缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_GASRV_CAMERA  8

/** @brief 外域摄像机的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_EXTERNAL_CAMERA   0

/** @brief 公安实战违章抓拍客户端缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_GASRV_ICC         0
/* End: Added by z00293 for 公安实战License */

/*Begin added by l02274 2015-6-23, for map license 校验*/
#define AS_DEFAULT_LICENSE_FOR_MAPM 0
/*End added by l02274 2015-6-23, for map license 校验*/

/** @brief DB9500缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_DB         0

/** @brief DR9500缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_DR9500    0

/** @brief DR8500缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_DR8500    0

/** @brief IAHR的缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_IAHR             1

/** @brief 移动指挥调度客户端/移动执法客户端 缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_GASRV_MCD_OR_MLE        1

/** @brief 移动前端 缺省License规格 */
#define AS_DEFAULT_LICENSE_FOR_MOBILE_CAMERA  1

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE接入到平台 */
/** @brief 操作类型字段 */
#define  AM_SIP_KEY_OPERATETYPE  "OperateType"

/** @brief 视频输入通道 */
#define  AM_SIP_KEY_VIDEO_INPUT  "VI"

/** @brief 视频输出通道 */
#define  AM_SIP_KEY_VIDEO_OUTPUT "VO"

/** @brief 音频输入通道 */
#define  AM_SIP_KEY_AUDIO_INPUT "AI"

/** @brief 音频输出通道 */
#define  AM_SIP_KEY_AUDIO_OUTPUT "AO"

/** @brief 告警输入通道 */
#define  AM_SIP_KEY_ALARM_INPUT "AlarmIn"

/** @brief 告警输出通道 */
#define  AM_SIP_KEY_ALARM_OUTPUT "AlarmOut"
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE接入到平台 */

/* Begin: Added by huangsen W4381, 2017-10-25 for MPPD49831 Xware 摘要字修改*/
#define  AM_SIP_KEY_ABSTRACT "Abstract"
/* End: Added by huangsen W4381, 2017-10-25 for MPPD49831 Xware 摘要字修改*/

/** @brief 串口类型 */
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
* @brief 计划类型
* @attention 无
*/
typedef enum tagPlanType
{
    PLAN_TYPE_DAY       = 0,        /**< 日计划 */
    PLAN_TYPE_WEEK,                 /**< 周计划 */

    PLAN_TYPE_MAX,
    PLAN_TYPE_INVALID   = 0xFF
}PLAN_TYPE_E;

/** @brief 存储类型 */
typedef enum tagASDEVCMStorageType
{
    STORAGE_TYPE_IPSAN = 0,             /**< IPSAN存储 */
    STORAGE_TYPE_NAS = 1,               /**< NAS存储 */
    STORAGE_TYPE_LOCAL = 2,             /**< 本地存储 */
    STORAGE_TYPE_SHARE_LOCAL = 3,       /**< 空间共享本地存储 */
    STORAGE_TYPE_LOCAL_MAS = 4,         /**< 本地MAS存储 */
    STORAGE_TYPE_THIRD_RES = 5,         /**< 第三方存储资源 */
    STORAGE_TYPE_CDM_SHARE_DIRECT = 7,  /**< CDM视频直存, 枚举值3~6已被IPC定义为其它类型, 平台顺延到7开始增加 */
    STORAGE_TYPE_CDS_TG_SHARE_DIRECT = 8,/**< CDS卡口直存*/

    STORAGE_TYPE_MAX,
    STORAGE_TYPE_INVALID = 0xFF
}AS_DEVCM_STORAGE_TYPE_E;

/** @brief 磁盘满策略 */
typedef enum tagASDEVCMDiskFullPolicy
{
    DISK_FULL_POLICY_STOP = 0,      /**< 磁盘满停止存储 */
    DISK_FULL_POLICY_OVERLOAD= 1,   /**< 磁盘满覆盖存储 */

    DISK_FULL_POLICY_MAX,
    DISK_FULL_POLICY_INVALID = 0xFF
} AS_DEVCM_DISK_FULL_POLICY_E;


/** @brief 业务当前状态 */
typedef enum tagSRVState
{
    SRV_STATE_IDLE = 0,             /**< 空闲状态 实况、轮切、组显示、组轮巡共用业务状态 */
    SRV_STATE_ACTIVE,               /**< 运行状态 实况、轮切、组显示、组轮巡共用业务状态 */
    SRV_STATE_PAUSE,                /**< 暂停状态 轮切、组轮巡共用业务状态 */
    SRV_STATE_UNACTIVE,             /**< 休眠状态 实况、轮切、组轮巡共用业务状态 */
    SRV_STATE_SUSPEND,              /**< 挂起状态 轮切业务状态 */

    SRV_STATE_MAX,                  /**< 最大值 */
    SRV_STATE_INVALID = 0xFF        /**< 无效值 */
}SRV_STATE_E;

/** @brief 业务释放原因码 */
typedef enum tagSRVReleaseCode
{
    SRV_RELEASE_REBUILD_STREAM       = 1000,  /**< 终端或者MS请求重建流，注意，枚举值必须和IMOS_REBUILD_STREAM一样*/
    SRV_RELEASE_USER_KEEPALIVE_FAIL  = 1001,  /**< 用户保活失败导致该用户的业务被服务器强制释放 */
    SRV_RELEASE_USER_KICKED_OUT      = 1002,  /**< 用户被强制下线导致该用户的业务被服务器强制释放 */
    SRV_RELEASE_USER_DELETE          = 1003,  /**< 用户被删除导致该用户的业务被服务器强制释放 */
    SRV_RELEASE_CAMERA_OFFLINE       = 2001,  /**< 摄像机下线导致该业务被服务器释放 */
    SRV_RELEASE_CAMERA_PARAM_CHANGE  = 2002,  /**< 摄像机的参数被修改导致该业务被服务器释放 */
    SRV_RELEASE_MS_OFFLINE           = 2003,  /**< 摄像机媒体转发的MS下线导致该业务被服务器释放 */
    SRV_RELEASE_TS_OFFLINE           = 2004,  /**< 摄像机媒体转发的TS下线导致该业务被服务器释放 */
    SRV_RELEASE_VOD_OFFLINEORDELETE  = 2005,  /**< 摄像机回放的VOD服务器下线或删除导致该业务被服务器释放 */
    SRV_RELEASE_MONITOR_OFFLINE      = 3001,  /**< 监视器下线导致该业务被服务器释放 */
    SRV_RELEASE_MONITOR_PARAM_CHANGE = 3002,  /**< 监视器的参数被修改导致该业务被服务器释放 */
    SRV_RELEASE_EX_DOMAIN_OFFLINE    = 4001,  /**< 外域下线导致该业务被服务器释放 */
    SRV_RELEASE_SERVER_PROC_ERR      = 5001,  /**< 服务器在处理业务请求的过程中出现错误导致的业务释放 */
    SRV_RELEASE_OTHER_USER_REAVE     = 6001,  /**< 业务被其他用户抢占释放 */
    SRV_RELEASE_SWITCH_SPLIT_SCR     = 7001,  /**< 切换监视器分屏模式 */
    /* Added by gaoshufeng(00762),2013-1-22 for IVSD00191 */
    SRV_RELEASE_INSUFFICIENT_DC_ABILITY = 7002,  /**< 监视器解码能力不足 */
    SRV_RELEASE_LINK_TO_RESUME       = 8001,  /**< 告警联动至监视器后恢复 */
    SRV_RELEASE_LINK_TO_STOP         = 9001,  /**< 告警联动至监视器后释放 */

    SRV_RELEASE_CODE_MAX,                     /**< 最大值 */
    SRV_RELEASE_CODE_INVALID = 0xFFFF         /**< 无效值 */
}SRV_RELEASE_CODE_E;

/* Begin modifyed by kf0092, 2012-12-04 for PAG接国标 */
/**
* enum tagCameraManutype
* brief 第三方IPC摄像机类型枚举值
* @attention 无
*/
typedef enum tagCameraManutype
{
    CAMERA_MANU_TYPE_ONVIF1_0      = 0,                /* ONVIF1.0 IPC */
    CAMERA_MANU_TYPE_ONVIF2_0      = 1,                /* ONVIF2.0 IPC */
    CAMERA_MANU_TYPE_ONVIF2_1      = 2,                /* ONVIF2.1 IPC */
    CAMERA_MANU_TYPE_GUOBIAO       = 9,                /* 国标 IPC */
    /* Begin added by j00350 for MPPD08948, 20140120 */
    CAMERA_MANU_TYPE_MOBILE        = 19,               /* 通用移动设备 */
    /* End added by j00350 for MPPD08948, 20140120 */

    CAMERA_MANU_TYPE_INVALID
}AS_CAMERA_MANU_TYPE_E;
/* End modifyed by kf0092, 2012-12-04 for PAG接国标 */


#ifdef  __cplusplus
}
#endif

#endif  /** __IMOS_AS_DEF_H__ */


