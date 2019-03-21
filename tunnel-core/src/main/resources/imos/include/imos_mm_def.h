/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_mm_def.h
  Project Code: IMOS MM
   Module Name: MM
  Date Created: 2009-03-31
        Author: yangpengfei/06985
   Description: MM�����꼰ö�ٶ���

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef __IMOS_MM_DEF_H__
#define __IMOS_MM_DEF_H__

/** ����ģʽ�������� */
typedef enum tagMMUpgMode
{
    MM_UPG_MODE_AUTO = 1,        /**< �Զ����� */

    MM_UPG_MODE_MANUAL = 2          /**< �ֶ����� */
} MM_UPGMODE_E;

/** @brief �������ͣ���Чֵ, �����ϰ汾 Added by z07067 for DVR. 2010-12-09 of VVD44847 */
#define MM_DOMAIN_SUBTYPE_INVALID                   0

/** @brief �������ͣ��������� */
#define MM_DOMAIN_SUBTYPE_LOCAL_PHYSICAL            1

/** @brief �������ͣ������������ */
#define MM_DOMAIN_SUBTYPE_LOCAL_VIRTUAL             2

/** @brief �������ͣ������������ */
#define MM_DOMAIN_SUBTYPE_FOREIGN_VIRTUAL           3

/** @brief �������ͣ��ϼ��������� */
#define MM_DOMAIN_SUBTYPE_FOREIGN_PHYSICAL_UPPER    4

/** @brief �������ͣ��¼��������� */
#define MM_DOMAIN_SUBTYPE_FOREIGN_PHYSICAL_LOWER    5

/** @brief �������ͣ�ƽ���������� */
#define MM_DOMAIN_SUBTYPE_FOREIGN_PHYSICAL_PARITY   6

/** @brief �������ͣ���������ECR3308-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_DVR3308           7

/** @brief �������ͣ�������ECR3316-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_DVR3316           8

/** @brief �������ͣ���������ECR3308-HF-E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3308E          9

/** @brief �������ͣ�������ECR3316-HF-E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3316E          10

/** @brief �������ͣ���������ECR3308-HF-S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3308S          11

/** @brief �������ͣ�������ECR3316-HF-S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR3316S          12

/* Begin: Modified by gaoshufeng(00762) 2012-12-14 for NVR���� */
/** @brief �������ͣ���������ECR2104-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR2104           13

/** @brief �������ͣ���������ECR2108-HF */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR2108           14

/* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */
/** @brief �������ͣ���������ECR��Сֵ��ECR����ֵ */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ECR_MIN           15
/* End: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */

/** @brief �������ͣ���������DVR���ֵ:Ԥ��1006��DVR�ã�������ӦIMOS_DEVICE_TYPE_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_DVR_MAX           1012

/** @brief �������ͣ���������NVR��Сֵ */
#define MM_DOMAIN_SUBTYPE_FOREIGN_NVR_MIN           1013

/** @brief �������ͣ���������ISC3500_ET */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500ET         1014

/** @brief �������ͣ���������ISC3500_EL */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500EL         1015

/** @brief �������ͣ���������ISC3500_ST */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500ST         1016

/** @brief �������ͣ���������ISC3500_SL */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500SL         1017

/** @brief �������ͣ���������ISC2500_ST */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500SP         1018

/** @brief �������ͣ���������ISC2500_ST */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500EP         1019

/** @brief �������ͣ���������ISC5000_S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC5000S          1020

/** @brief �������ͣ���������ISC5000_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC5000E          1021

/** @brief �������ͣ���������ISC2500_S */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500S          1022

/** @brief �������ͣ���������ISC2500_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500E          1023

/** @brief �������ͣ���������ISC3500E_B05 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500E_B05          1024

/** @brief �������ͣ���������ISC3500S_B05 */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC3500S_B05          1025

/* Added by zhangdong(kf0134), 2013-5-31 of 02415 */
/** @brief �������ͣ���������ISC2500-SCT */
#define MM_DOMAIN_SUBTYPE_FOREIGN_ISC2500SCT          1117

/* Added by liujian/02319, 2016-10-17 for GNVR��GBЭ����豸��ʽ���� */
#define MM_DOMAIN_SUBTYPE_FOREIGN_GNVR   2019

/** @brief �������ͣ���������NVR���ֵ:Ԥ��1004��NVR�ã�������ӦIMOS_DEVICE_TYPE_E */
#define MM_DOMAIN_SUBTYPE_FOREIGN_NVR_MAX           2020

/** @brief ��������������������NVR��ͨ�������� */
#define MM_DOMAIN_DESC_ISC_PUB                      "ISC"

/* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */
/** @brief ��������������������H3CNVR��ͨ�������� */
#define MM_DOMAIN_DESC_H3CISC_PUB                   "H3C-ISC"
/* End: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */

/** @brief ��������������������NVR��ͨ������������ */
#define MM_DOMAIN_DESC_ISC_PUBLEN                   3

/** @brief ��������������������NVR�Ĳ�Ʒϵ���±� */
#define MM_DOMAIN_DESC_ISC_CLASS_INDEX              4

/** @brief ��������������������ECR��ͨ�������� */
#define MM_DOMAIN_DESC_ECR_PUB                      "ECR"

/** @brief ��������������������H3CECR��ͨ�������� */
#define MM_DOMAIN_DESC_H3CECR_PUB                   "H3C-ECR"

/** @brief ��������������������H3CECR�Ĺ��ܿ�ѡ�ַ���ʼ�±� */
#define MM_DOMAIN_DESC_H3CECR_PUBLEN                7
/* End: Modified by gaoshufeng(00762) 2012-12-14 for NVR���� */

/** @brief �����û� */
#define MM_USER_TYPE_LOCAL_DOMAIN 1UL

/** @brief �����û� */
#define MM_USER_TYPE_FOREIGN_DOMAIN 2UL

/** @brief �����ɫ */
#define MM_ROLE_TYPE_LOCAL_DOMAIN 1UL

/** @brief �����ɫ */
#define MM_ROLE_TYPE_FOREIGN_DOMAIN 2UL

/**
* @struct tagMMDomainType
* @brief ������ö��
* @attention ��
*/
typedef enum tagMMDomainType
{
    MM_DOMAIN_TYPE_PHYSICAL = 1,           /**< ������ */

    MM_DOMAIN_TYPE_VIRTUAL = 2             /**< ������ */

}MM_DOMAINTYPE_E;

/** ����������� */
typedef enum tagMMJobSchdType
{
    MM_JOB_SCHD_UNINITIAL = 0,                  /**< �����������δ��ʼ�� */
    MM_JOB_ONCE = 1,                            /**< һ���� */
    MM_JOB_IMMEDIATELY = 2,                     /**< ����ִ�� */
    MM_JOB_MONTHLY = 3,                         /**< ÿ��(1~28��) */
    MM_JOB_LAST_DAY_OF_MONTH = 4,               /**< ÿ�����һ�� */
    MM_JOB_WEEKLY = 5,                          /**< ÿ�� */
    MM_JOB_DAILY = 6,                           /**< ÿ�� */
    MM_JOB_HOURS_INTERVAL = 7                   /**< ÿ����Сʱ */
} MM_JOBSCHDTYPE_E;

/** �����豸ִ��״̬ */
typedef enum tagMMJobDevStatus
{
    MM_JOBDEV_STATUS_UNINITIAL = 0,             /**< �����豸ִ��״̬δ��ʼ�� */
    MM_JOBDEV_WAITTING = 1,                     /**< �ȴ� */
    MM_JOBDEV_CANCELED = 2,                     /**< ȡ�� */
    MM_JOBDEV_RUNNING = 3,                      /**< ���� */
    MM_JOBDEV_FINISHED = 4                      /**< ���� */
}MM_JOBDEVSTATUS_E;

/** �����豸ִ�н�� */
typedef enum tagMMJobDevResult
{
    MM_JOBDEV_RESULT_UNINITIAL = 0,              /**< �����豸ִ�н��δ��ʼ�� */
    MM_JOBDEV_UNKNOW = 1,                        /**< ���δ֪ */
    MM_JOBDEV_TIMEOUT = 2,                       /**< ��ʱ */
    MM_JOBDEV_FAILED = 3,                        /**< ʧ�� */
    MM_JOBDEV_SUCCESS = 4                        /**< �ɹ� */
}MM_JOBDEVRESULT_E;

/** �豸��������������� */
typedef enum tagMMDevUpgResult
{
    MM_UPG_DEV_RESULT_UNINITIAL = 0,      /**< δ��ʼ�� */

    MM_UPT_DEV_RESULT_UNKNOW = 1,             /**< δ֪ */

    MM_UPG_DEV_RESULT_SUCCESS = 2,            /**< �����ɹ� */

    MM_UPG_DEV_RESULT_VERSION_ERROR = 3,      /**< �汾���� */

    MM_UPG_DEV_RESULT_DOWNLOAD_ERROR = 4,     /**< ���ش��� */

    MM_UPG_DEV_RESULT_UPGCFG_ERROR = 5,       /**< �豸����ʧ�� */

    MM_UPG_DEV_RESULT_TIMEOUT_ERROR = 6,      /**< �豸������ʱ */

    MM_UPG_DEV_RESULT_FAIL = 7                /**< �豸����ʧ�� */
} MM_UPGDEVEXTRESULT_E;

#endif
