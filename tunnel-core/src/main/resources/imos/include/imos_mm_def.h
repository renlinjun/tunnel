/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_mm_def.h
  Project Code: IMOS MM
   Module Name: MM
  Date Created: 2009-03-31
        Author: yangpengfei/06985
   Description: MM公共宏及枚举定义

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef __IMOS_MM_DEF_H__
#define __IMOS_MM_DEF_H__

/** 升级模式常量定义 */
typedef enum tagMMUpgMode
{
    MM_UPG_MODE_AUTO = 1,        /**< 自动升级 */

    MM_UPG_MODE_MANUAL = 2          /**< 手动升级 */
} MM_UPGMODE_E;

/** @brief 域子类型：无效值, 兼容老版本 Added by z07067 for DVR. 2010-12-09 of VVD44847 */
#define MM_DOMAIN_SUBTYPE_INVALID                   0

/** @brief 域子类型：本物理域 */
#define MM_DOMAIN_SUBTYPE_LOCAL_PHYSICAL            1

/** @brief 域子类型：本域的虚拟域 */
#define MM_DOMAIN_SUBTYPE_LOCAL_VIRTUAL             2

/** @brief 域子类型：外域的虚拟域 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_VIRTUAL           3

/** @brief 域子类型：上级外物理域 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_PHYSICAL_UPPER    4

/** @brief 域子类型：下级外物理域 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_PHYSICAL_LOWER    5

/** @brief 域子类型：平级外物理域 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_PHYSICAL_PARITY   6

/** @brief 域子类型：外物理域ECR3308-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_DVR3308           7

/** @brief 域子类型：外物理ECR3316-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_DVR3316           8

/** @brief 域子类型：外物理域ECR3308-HF-E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3308E          9

/** @brief 域子类型：外物理ECR3316-HF-E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3316E          10

/** @brief 域子类型：外物理域ECR3308-HF-S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3308S          11

/** @brief 域子类型：外物理ECR3316-HF-S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3316S          12

/* Begin: Modified by gaoshufeng(00762) 2012-12-14 for NVR大类 */
/** @brief 域子类型：外物理域ECR2104-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR2104           13

/** @brief 域子类型：外物理域ECR2108-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR2108           14

/* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */
/** @brief 域子类型：外物理域ECR最小值、ECR大类值 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR_MIN           15
/* End: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */

/** @brief 域子类型：外物理域DVR最大值:预留1006个DVR用，数量对应IMOS_DEVICE_TYPE_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_DVR_MAX           1012

/** @brief 域子类型：外物理域NVR最小值 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_NVR_MIN           1013

/** @brief 域子类型：外物理域ISC3500_ET */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500ET         1014

/** @brief 域子类型：外物理域ISC3500_EL */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500EL         1015

/** @brief 域子类型：外物理域ISC3500_ST */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500ST         1016

/** @brief 域子类型：外物理域ISC3500_SL */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500SL         1017

/** @brief 域子类型：外物理域ISC2500_ST */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500SP         1018

/** @brief 域子类型：外物理域ISC2500_ST */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500EP         1019

/** @brief 域子类型：外物理域ISC5000_S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC5000S          1020

/** @brief 域子类型：外物理域ISC5000_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC5000E          1021

/** @brief 域子类型：外物理域ISC2500_S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500S          1022

/** @brief 域子类型：外物理域ISC2500_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500E          1023

/** @brief 域子类型：外物理域ISC3500E_B05 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500E_B05          1024

/** @brief 域子类型：外物理域ISC3500S_B05 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500S_B05          1025

/* Added by zhangdong(kf0134), 2013-5-31 of 02415 */
/** @brief 域子类型：外物理域ISC2500-SCT */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500SCT          1117

/* Added by liujian/02319, 2016-10-17 for GNVR以GB协议和设备形式接入 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_GNVR   2019

/** @brief 域子类型：外物理域NVR最大值:预留1004个NVR用，数量对应IMOS_DEVICE_TYPE_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_NVR_MAX           2020

/** @brief 域类型描述：外物理域NVR的通用描述符 */
#define MM_DOMAIN_DESC_ISC_PUB                      "ISC"

/* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */
/** @brief 域类型描述：外物理域H3CNVR的通用描述符 */
#define MM_DOMAIN_DESC_H3CISC_PUB                   "H3C-ISC"
/* End: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */

/** @brief 域类型描述：外物理域NVR的通用描述符长度 */
#define MM_DOMAIN_DESC_ISC_PUBLEN                   3

/** @brief 域类型描述：外物理域NVR的产品系列下标 */
#define MM_DOMAIN_DESC_ISC_CLASS_INDEX              4

/** @brief 域类型描述：外物理域ECR的通用描述符 */
#define MM_DOMAIN_DESC_ECR_PUB                      "ECR"

/** @brief 域类型描述：外物理域H3CECR的通用描述符 */
#define MM_DOMAIN_DESC_H3CECR_PUB                   "H3C-ECR"

/** @brief 域类型描述：外物理域H3CECR的功能可选字符起始下标 */
#define MM_DOMAIN_DESC_H3CECR_PUBLEN                7
/* End: Modified by gaoshufeng(00762) 2012-12-14 for NVR大类 */

/** @brief 本域用户 */
#define MM_USER_TYPE_LOCAL_DOMAIN 1UL

/** @brief 外域用户 */
#define MM_USER_TYPE_FOREIGN_DOMAIN 2UL

/** @brief 本域角色 */
#define MM_ROLE_TYPE_LOCAL_DOMAIN 1UL

/** @brief 外域角色 */
#define MM_ROLE_TYPE_FOREIGN_DOMAIN 2UL

/**
* @struct tagMMDomainType
* @brief 域类型枚举
* @attention 无
*/
typedef enum tagMMDomainType
{
    MM_DOMAIN_TYPE_PHYSICAL = 1,           /**< 物理域 */

    MM_DOMAIN_TYPE_VIRTUAL = 2             /**< 虚拟域 */

}MM_DOMAINTYPE_E;

/** 任务调度类型 */
typedef enum tagMMJobSchdType
{
    MM_JOB_SCHD_UNINITIAL = 0,                  /**< 任务调度类型未初始化 */
    MM_JOB_ONCE = 1,                            /**< 一次性 */
    MM_JOB_IMMEDIATELY = 2,                     /**< 立即执行 */
    MM_JOB_MONTHLY = 3,                         /**< 每月(1~28号) */
    MM_JOB_LAST_DAY_OF_MONTH = 4,               /**< 每月最后一天 */
    MM_JOB_WEEKLY = 5,                          /**< 每周 */
    MM_JOB_DAILY = 6,                           /**< 每天 */
    MM_JOB_HOURS_INTERVAL = 7                   /**< 每隔几小时 */
} MM_JOBSCHDTYPE_E;

/** 任务设备执行状态 */
typedef enum tagMMJobDevStatus
{
    MM_JOBDEV_STATUS_UNINITIAL = 0,             /**< 任务设备执行状态未初始化 */
    MM_JOBDEV_WAITTING = 1,                     /**< 等待 */
    MM_JOBDEV_CANCELED = 2,                     /**< 取消 */
    MM_JOBDEV_RUNNING = 3,                      /**< 运行 */
    MM_JOBDEV_FINISHED = 4                      /**< 结束 */
}MM_JOBDEVSTATUS_E;

/** 任务设备执行结果 */
typedef enum tagMMJobDevResult
{
    MM_JOBDEV_RESULT_UNINITIAL = 0,              /**< 任务设备执行结果未初始化 */
    MM_JOBDEV_UNKNOW = 1,                        /**< 结果未知 */
    MM_JOBDEV_TIMEOUT = 2,                       /**< 超时 */
    MM_JOBDEV_FAILED = 3,                        /**< 失败 */
    MM_JOBDEV_SUCCESS = 4                        /**< 成功 */
}MM_JOBDEVRESULT_E;

/** 设备升级结果常量定义 */
typedef enum tagMMDevUpgResult
{
    MM_UPG_DEV_RESULT_UNINITIAL = 0,      /**< 未初始化 */

    MM_UPT_DEV_RESULT_UNKNOW = 1,             /**< 未知 */

    MM_UPG_DEV_RESULT_SUCCESS = 2,            /**< 升级成功 */

    MM_UPG_DEV_RESULT_VERSION_ERROR = 3,      /**< 版本错误 */

    MM_UPG_DEV_RESULT_DOWNLOAD_ERROR = 4,     /**< 下载错误 */

    MM_UPG_DEV_RESULT_UPGCFG_ERROR = 5,       /**< 设备配置失败 */

    MM_UPG_DEV_RESULT_TIMEOUT_ERROR = 6,      /**< 设备升级超时 */

    MM_UPG_DEV_RESULT_FAIL = 7                /**< 设备升级失败 */
} MM_UPGDEVEXTRESULT_E;

#endif
