/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              sdk_tollgate_func_inner.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2011-03-14
        Author: baoyihui/02795
   Description: ����SDK�ڲ��ӿ�
                ע��: 1)���з�ҳ��ѯʱ�������б�ռ����ⲿ���룬
                        ��С���ݷ�ҳ��ѯʱһҳ�ĸ����������롣
                      2)�����ֵ�����˵���ο�IMOS_QueryDictionaryDataList�ӿ�˵��

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/


#ifndef _IMOS_SDK_TOLLGATE_FUNC_INNER_H_
#define _IMOS_SDK_TOLLGATE_FUNC_INNER_H_

#ifdef  __cplusplus
extern "C"{
#endif

/** @defgroup groupSDKTollgate ����SDK
*   ����SDK
*   @{
*/

/**
* ����TMS \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTMSInfo              TMS��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_INFO_S                      *pstTMSInfo
);

/**
* ɾ��TMS \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSCode               TMS����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN]
);

/**
* �޸�TMS \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTMSInfo              TMS��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_INFO_S                      *pstTMSInfo
);

/**
* ��ѯTMS \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSCode               TMS����
* @param [OUT]  pstTMSInfo              TMS��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN],
    OUT  TMS_INFO_S                     *pstTMSInfo
);

/**
* ��ѯTMS�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#NAME_TYPE[�豸����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTMSList              TMS�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TMS_INFO_S                     *pstTMSList
);

#if 0
#endif

/**
* ���ӿ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateInfo         ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����ʾ��ͼ��Ҫͨ��FTP�ϴ�����������ͨ��IMOS_GetFTPInfoByOper�ӿڻ�ȡFTP���������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_INFO_S                 *pstTollgateInfo
);

/**
* ɾ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode          ���ڱ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ɾ��ʱ��̨��ͬʱɾ������ʾ��ͼ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN ULONG_32                      ulIsSave
);

/**
* �޸Ŀ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateInfo         ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_INFO_S                 *pstTollgateInfo
);

/**
* ���ӿ�����TMS�İ󶨹�ϵ\n
* @param [IN] pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] pstBindInfo ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateTMSBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_TMS_BIND_INFO_S        *pstBindInfo
);

/**
* ɾ��������TMS�İ󶨹�ϵ\n
* @param [IN] pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] pstBindInfo ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateTMSBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_TMS_BIND_INFO_S        *pstBindInfo
);

#if 0
#endif

/**
* �޸Ŀ��ڳ�����Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstLaneInfo             ���ڳ�����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateLane
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_LANE_INFO_S            *pstLaneInfo
);

/**
* ��ѯ���ڳ����б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode          �������ڱ���
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstLaneQueryItemList    ���ڳ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ/������������Ϊ#LANE_NUMBER[������]��#LANE_DIRECTION(����������)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateLaneList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_LANE_QUERY_ITEM_S     *pstLaneQueryItemList
);

#if 0
#endif

/**
* ���������  \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateFlashlightInfo   �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateFlashlight
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_FLASHLIGHT_INFO_S          *pstTollgateFlashlightInfo
);

/**
* ɾ������� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateFlashlightCode    ����Ʊ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateFlashlight
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateFlashlightCode[IMOS_CODE_LEN]
);

/**
* �޸������\n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateFlashlightInfo   �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateFlashlight
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_FLASHLIGHT_INFO_S          *pstTollgateFlashlightInfo
);

/**
* ��ѯ������б� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode              �������ڱ���
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateFlashlightList   ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateFlashlightList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_FLASHLIGHT_INFO_S     *pstTollgateFlaselightList
);

#if 0
#endif

/**
* ��ѯ���ں��̵�״̬�б� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode              �������ڱ���
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTrafficLightStatusList   ���ں��̵�״̬�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrafficLightStatusList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TRAFFIC_LIGHT_STATUS_S          *pstTrafficLightStatusList
);

#if 0
#endif

/**
* ���Ӳ�/���ص�λ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDispositionDept      ��/���ص�λ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DISPOSITION_DEPT_S              *pstDispositionDept
);

/**
* ɾ����/���ص�λ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionDeptCode   ��/���ص�λ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionDeptCode[IMOS_CODE_LEN]
);

/**
* �޸Ĳ�/���ص�λ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDispositionDept      ��/���ص�λ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DISPOSITION_DEPT_S              *pstDispositionDept
);

#if 0
#endif

/**
* ����洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstStoreResBasicInfo    �洢��Դ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����ϵͳ��֧��IPSAN�洢��ulStorageType��������ΪSTORE_DEV_TYPE_IPSAN
*       ����ϵͳ��֧���Զ�ѡ��洢�豸��bAutoSelectStoreDev��������Ϊ��дBOOL_FALSE
*       ����ϵͳ��֧�ֹ����洢��ʽ��ulDiskFullPolicy��������ΪDISK_FULL_POLICY_OVERLOAD
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignDevStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* ɾ���洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode               �洢��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDevStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode               �洢��Դ����
* @param [OUT]  pstStoreResBasicInfo    �洢��Դ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    OUT STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* ��ѯ�洢��Դ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode               �豸����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ,#NAME_TYPE[��Դ����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstStoreResBasicList    �洢��Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevStoreResList
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szDevCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S         *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                  *pstRspPageInfo,
    OUT STORE_RES_BASIC_QUERY_ITEM_S     *pstStoreResBasicList
);

#if 0
#endif

/**
* ��GIS��ͼ�ϴ���ͼ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstMapBaseIcon          ͼ�������Ϣ
* @param [OUT]  szIconCode              ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GIS_MAP_BASE_ICON_S         *pstMapBaseIcon,
    OUT CHAR                        szIconCode[IMOS_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ��ͼ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szIconCode              ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    IN  CHAR                        szIconCode[IMOS_CODE_LEN]
);

/**
* ��GIS��ͼ���޸�ͼ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstMapBaseIcon          ͼ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GIS_MAP_BASE_ICON_S         *pstMapBaseIcon
);

/**
* ��ѯGIS��ͼͼ����Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szIconCode              ͼ�����
* @param [OUT]  pstCamIcon              ͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    IN  CHAR                        szIconCode[IMOS_CODE_LEN],
    OUT GIS_MAP_ICON_S              *pstMapIcon
);

/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵ�ͼ���б� \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode           GIS��ͼ����
* @param [IN]   ulIconType             ͼ�����ͣ��ο�#IMOS_TYPE_E��Ŀǰ��֧��IMOS_TYPE_TOLLGATE
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������:#CODE_TYPE[ͼ�����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstMapIconList         ͼ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMapIconList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulIconType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GIS_MAP_ICON_S              *pstMapIconList
);

#if 0
#endif

/**
* ��Ӱ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleWhitelist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_S             *pstVehicleWhitelist
);

/**
* ɾ�������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleWhitelistCode  ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleWhitelistCode[IMOS_CODE_LEN]
);

/**
* �޸İ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleWhitelist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_S             *pstVehicleWhitelist
);

/**
* ��ѯ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleWhitelistCode  ���������
* @param [OUT]  pstVehicleWhitelist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleWhitelistCode[IMOS_CODE_LEN],
    OUT  VEHICLE_WHITELIST_S            *pstVehicleWhitelist
);

/**
* ��ѯ�������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleWhitelistList �������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleWhitelistList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_WHITELIST_S            *pstVehicleWhitelistList
);

/*Begin added by a02842 for whitelist extension,2017-02-23*/
/**
* ��Ӱ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleWhitelist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleWhitelistV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_V2_S             *pstVehicleWhitelist,
    IN  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaResInfo
);

/**
* �޸İ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleWhitelist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleWhitelistV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_V2_S             *pstVehicleWhitelist
);

/**
* ��ѯ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleWhitelistCode  ���������
* @param [OUT]  pstVehicleWhitelist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleWhitelistV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleWhitelistCode[IMOS_CODE_LEN],
    OUT  VEHICLE_WHITELIST_V2_S            *pstVehicleWhitelist,
    OUT  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaResInfo
);

/**
* ��ѯ�������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleWhitelistList �������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleWhitelistListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_WHITELIST_V2_S            *pstVehicleWhitelistList
);
/*End added by a02842 for whitelist extension,2017-02-23*/

#if 0
#endif


/**
* ������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulType                  �������ͣ��ο�#VEHICLE_LIST_TYPE_E
* @param [IN]   pstVehiclePlate         ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  VEHICLE_PLATE_S                 *pstVehiclePlate
);

/**
* ɾ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulType                  �������ͣ��ο�#VEHICLE_LIST_TYPE_E
* @param [IN]   szVehiclePlateCode      �������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  CHAR                            szVehiclePlateCode[IMOS_CODE_LEN]
);

/**
* �޸����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulType                  �������ͣ��ο�#VEHICLE_LIST_TYPE_E
* @param [IN]   pstVehiclePlate         ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  VEHICLE_PLATE_S                 *pstVehiclePlate
);

/**
* ��ѯ���� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulType                  �������ͣ��ο�#VEHICLE_LIST_TYPE_E
* @param [IN]   szVehiclePlateCode      �������
* @param [OUT]  pstVehiclePlate         ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  CHAR                            szVehiclePlateCode[IMOS_CODE_LEN],
    OUT VEHICLE_PLATE_S                 *pstVehiclePlate
);

/**
* ��ѯ�����б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulType                  �������ͣ��ο�#VEHICLE_LIST_TYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehiclePlateList     �����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehiclePlateList
(
    IN   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN   ULONG_32                           ulType,
    IN   COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN   QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT  VEHICLE_PLATE_S                 *pstVehiclePlateList
);

#if 0
#endif

/**
* ��ѯ���ڱ�����Դ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSCode               TMS����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateLocalResList ���ڱ�����Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateLocalResList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_LOCAL_RES_S           *pstTollgateLocalResList
);

#if 0
#endif

/**
* ��ѯ���ڱ������� \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstTollgateStorCycle       ���ڱ�������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateStorCycle
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT TOLLGATE_STOR_CYCLE_S       *pstTollgateStorCycle
);

/**
* �޸Ŀ��ڱ������� \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateStorCycle       ���ڱ�������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateStorCycle
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  TOLLGATE_STOR_CYCLE_S       *pstTollgateStorCycle
);

#if 0
#endif

/**
* ���������ֵ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       �����ֵ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧��42λ�����ַ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDictionaryDataV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATAV2_S               *pstDictionaryData
);

/**
* �޸������ֵ���  V2\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       �����ֵ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �������޸������ֵ����� ֧��42λ�����ַ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDictionaryDataV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATAV2_S               *pstDictionaryData
);
#if 0
#endif

/**
* ������Ʒ��� \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstPlateAnalyseInfo    ���Ʒ�����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPlateAnalyse
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  PLATE_ANALYSE_INFO_S        *pstPlateAnalyseInfo
);

/**
* ɾ�����Ʒ��� \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szPlateAnalyseCode     ���Ʒ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelPlateAnalyse
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPlateAnalyseCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ���Ʒ����б� \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstPlateAnalyseList    ���Ʒ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[���Ʒ������]
* - #PLATE_ANALYSE_STATUS[���Ʒ���״̬]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPlateAnalyseList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT PLATE_ANALYSE_INFO_S        *pstPlateAnalyseList
);

/**
* ��ҳ��ѯ���Ʒ�������б� \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition          ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������:#CODE_TYPE[���Ʒ������])
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstPlateAnalyseResultList  ���Ʒ�������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPlateAnalyseResultList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT PLATE_ANALYSE_RESULT_S      *pstPlateAnalyseResultList
);

#if 0
#endif

/**
* ɾ���������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleAlarmCode      ����������Ϣ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleAlarmData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleAlarmCode[IMOS_CODE_LEN]
);


#if 0
#endif

/**
* ����DR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDRInfo               DR��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DR_INFO_S                       *pstDRInfo
);

/**
* ɾ��DR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDRCode                DR����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDRCode[IMOS_CODE_LEN]
);

/**
* �޸�DR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDRInfo               DR��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DR_INFO_S                       *pstDRInfo
);

/**
* ��ѯDR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDRCode                DR����
* @param [OUT]  pstDRInfo               DR��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDRCode[IMOS_CODE_LEN],
    OUT DR_INFO_S                       *pstDRInfo
);

/**
* ��ѯDR�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#NAME_TYPE[�豸����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDRList               DR�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDRList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DR_INFO_S                      *pstDRList
);

#if 0
#endif

/**
* Υ��ͳ�ƣ���Υ������ͳ�� \n
* @param [IN]   pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition              ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo               �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                 ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstViolationStatByTypeList     ��Υ������ͳ�ƽ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #TOLLGATE_CODE[���ڱ���]
* - #EVENT_TIME[����ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleViolationStatByType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S            *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                   *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                    *pstRspPageInfo,
    OUT  VEHICLE_VIOLATION_STAT_BY_TYPE_S   *pstViolationStatByTypeList
);

/**
* Υ��ͳ�ƣ�������ͳ�� \n
* @param [IN]   pstUserLogIDInfo                   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                  ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                     ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstViolationStatByTollgateList     ������ͳ�ƽ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_STATUS[Υ������]
* - #EVENT_TIME[����ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleViolationStatByTollgate
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S              *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                     *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                      *pstRspPageInfo,
    OUT  VEHICLE_VIOLATION_STAT_BY_TOLLGATE_S *pstViolationStatByTollgateList
);

/**
* Υ��ͳ�ƣ�������״̬ͳ�� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#EVENT_TIME[����ʱ��])
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstViolationStatByDealStatusList     ������״̬ͳ�ƽ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleViolationStatByDealStatus
(
    IN  USER_LOGIN_ID_INFO_S                     *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                 *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                        *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                         *pstRspPageInfo,
    OUT  VEHICLE_VIOLATION_STAT_BY_DEAL_STATUS_S *pstViolationStatByDealStatusList
);

/* Begin added by a02842 for ����������ͳ��,2016-06-24*/
/**
* ����������ͳ��\n
* @param [IN]   pstUserLogIDInfo                   �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                              ��ѯ��������
* @param [IN]   pstResList                              ��ѯ�����б�
* @param [IN]   pstStatQueryInfo                    ��ѯ����
* @param [IN]   pstQueryPageInfo                   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                     ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstStatResultList                   ����ͳ�ƽ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_STATUS[Υ������]
* - #EVENT_TIME[����ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrafficStatByHbase
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  ULONG_32                                        ulResNum,
    IN  RES_INFO_S                                    *pstResList,
    IN  TRAFFIC_STAT_INFO_HBASE_S              *pstStatQueryInfo,
    IN  QUERY_PAGE_INFO_S                     *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                      *pstRspPageInfo,
    OUT  TRAFFIC_STAT_RESULT_HBASE_S    *pstStatResultList
);
/* End added by a02842 for ����������ͳ��,2016-06-24*/

#if 0
#endif

/**
* ��ѯ����ͼƬ������������ \n
* @param [IN]   pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstTollgatePhotoLifeCycleCfg  ����ͼƬ������������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgatePhotoLifeCycleCfg
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    OUT TOLLGATE_PHOTO_LIFE_CYCLE_CFG_S       *pstTollgatePhotoLifeCycleCfg
);

/**
* �޸Ĺ���ͼƬ������������ \n
* @param [IN]   pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgatePhotoLifeCycleCfg  ����ͼƬ������������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgatePhotoLifeCycleCfg
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  TOLLGATE_PHOTO_LIFE_CYCLE_CFG_S       *pstTollgatePhotoLifeCycleCfg
);

#if 0
#endif

/**
* ����TMSת����ַ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTMSForwardAddrInfo   ת����ַ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_FORWARD_ADDR_INFO_S         *pstTMSForwardAddrInfo
);

/**
* ɾ��TMSת����ַ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSForwardAddrCode    ת����ַ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSForwardAddrCode[IMOS_CODE_LEN]
);

/**
* �޸�TMSת����ַ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTMSForwardAddrInfo   ת����ַ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_FORWARD_ADDR_INFO_S         *pstTMSForwardAddrInfo
);

/**
* ��ѯTMSת����ַ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSForwardAddrCode    ת����ַ���
* @param [OUT]  pstTMSForwardAddrInfo   ת����ַ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSForwardAddrCode[IMOS_CODE_LEN],
    OUT  TMS_FORWARD_ADDR_INFO_S        *pstTMSForwardAddrInfo
);

/**
* ��ѯTMSת����ַ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSCode               TMS����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTMSForwardAddrList   ת����ַ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[ת����ַ���]
* - #PHY_DEV_IP[ת����ַ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSForwardAddressList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TMS_FORWARD_ADDR_INFO_S        *pstTMSForwardAddrList
);

#if 0
#endif

/**
* ����Υ�µص� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstViolationPlace       Υ�µص���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VIOLATION_PLACE_S               *pstViolationPlace
);

/**
* ɾ��Υ�µص� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szViolationPlaceCode    Υ�µص����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szViolationPlaceCode[IMOS_CODE_LEN]
);

/**
* �޸�Υ�µص� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstViolationPlace       Υ�µص���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VIOLATION_PLACE_S               *pstViolationPlace
);

/**
* ��ѯΥ�µص� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szViolationPlaceCode    Υ�µص����
* @param [OUT]  pstViolationPlace       Υ�µص���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szViolationPlaceCode[IMOS_CODE_LEN],
    OUT  VIOLATION_PLACE_S              *pstViolationPlace
);

/**
* ��ѯΥ�µص��б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstViolationPlaceList   Υ�µص��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ/��������
* - #CODE_TYPE[���]
* - #NAME_TYPE[����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryViolationPlaceList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VIOLATION_PLACE_S              *pstViolationPlaceList
);

/**
* ��ѯ�豸��ַ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode               �豸����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDevAddrList          �豸��ַ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ/��������
* - #PHY_DEV_IP[��ַ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevAddrList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT DEV_ADDR_S                      *pstDevAddrList
);

#if 0
#endif

/**
* ����쳣��Ϊ���� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstAbnormalAnalyseInfo          �쳣��Ϊ������Ϣ
* @param [IN]   ulTollgateNum                   ��������
* @param [IN]   aszTollgateCodeList             ���ڱ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAbnormalAnalyse
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_ABNORMAL_ANALYSE_INFO_S       *pstAbnormalAnalyseInfo,
    IN  ULONG_32                                  ulTollgateNum,
    IN  CHAR                                   aszTollgateCodeList[IMOS_VEHICLE_ABNORMAL_ANALYSE_TG_MAX_NUM][IMOS_CODE_LEN]
);

/**
* ɾ���쳣��Ϊ���� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szAbnormalAnalyseCode           �쳣��Ϊ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAbnormalAnalyse
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                        szAbnormalAnalyseCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ�쳣��Ϊ�����б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAbnormalAnalyseList          �쳣��Ϊ�����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�쳣��Ϊ�������]
* - #ABNORMAL_ANALYSE_STATUS[�쳣��Ϊ����״̬]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAbnormalAnalyseList
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S              *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                     *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                       *pstRspPageInfo,
    OUT VEHICLE_ABNORMAL_ANALYSE_INFO_S       *pstAbnormalAnalyseList
);

/**
* ��ҳ��ѯ�쳣��Ϊ��������б� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAbnormalAnalyseResultList         ���Ʒ�������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�쳣��Ϊ�������]
* - #RESULT_CODE[������]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #COUNT_TYPE[ͨ������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAbnormalAnalyseResultList
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                      *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                        *pstRspPageInfo,
    OUT VEHICLE_ABNORMAL_ANALYSE_RESULT_S      *pstAbnormalAnalyseResultList
);

#if 0
#endif

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/**
* ��ӳ�������:�����켣��ײ \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTrackCollisionDetail         �����켣��ײ��ϸ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTrackCollision
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_TRACK_COLLISION_DETAIL_S      *pstTrackCollisionDetail
);

/**
* ɾ����������:�����켣��ײ \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szTrackCollisionCode            �����켣��ײ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTrackCollision
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szTrackCollisionCode[IMOS_CODE_LEN]
);

/**
* ��ѯ��������:�����켣��ײ \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szTrackCollisionCode            �����켣��ײ�������
* @param [OUT]  pstTrackCollisionDetail         �����켣��ײ��ϸ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrackCollision
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  CHAR                                  szTrackCollisionCode[IMOS_CODE_LEN],
    OUT VEHICLE_TRACK_COLLISION_DETAIL_S      *pstTrackCollisionDetail
);

/**
* ��ҳ��ѯ��������:�����켣��ײ�б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTrackCollisionList           �����켣��ײ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�����켣��ײ���]
* - #NAME_TYPE[�����켣��ײ����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrackCollisionList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_TRACK_COLLISION_QUERY_ITEM_S         *pstTrackCollisionList
);

/**
* ��ҳ��ѯ��������:�����켣��ײ����б� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTrackCollisionResultList          �켣��ײ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #RESULT_CODE[������]
* - #CODE_TYPE[�����켣��ײ���]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #PASS_TIME[ͨ������ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrackCollisionResultList
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                      *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                        *pstRspPageInfo,
    OUT VEHICLE_TRACK_COLLISION_RESULT_S       *pstTrackCollisionResultList
);

#if 0
#endif

/**
* ��ӳ�������:�����״γ��� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstFirstAppearInfo              �����״γ�����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFirstAppear
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_FIRST_APPEAR_INFO_S           *pstFirstAppearInfo
);

/**
* ɾ����������:�����״γ��� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szFirstAppearCode               �����״γ��ֱ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelFirstAppear
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szFirstAppearCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ��������:�����״γ����б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstFirstAppearList              �����״γ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�����״γ��ֱ��]
* - #NAME_TYPE[�����״γ�������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFirstAppearList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_FIRST_APPEAR_INFO_S                  *pstFirstAppearList
);

/**
* ��ҳ��ѯ��������:�����״γ��ֽ���б� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstFirstAppearResultList             �����״γ��ֽ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #RESULT_CODE[������]
* - #CODE_TYPE[�����״γ��ֱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #PASS_TIME[ͨ������ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFirstAppearResultList
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                      *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                        *pstRspPageInfo,
    OUT VEHICLE_FIRST_APPEAR_RESULT_S          *pstFirstAppearResultList
);

#if 0
#endif

/**
* ��ӳ�������:������Σʱ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstPerilTimeInfo                ������Σʱ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPerilTime
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_PERIL_TIME_INFO_S             *pstPerilTimeInfo
);

/**
* ɾ����������:������Σʱ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szPerilTimeCode                 ������Σʱ�α���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelPerilTime
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPerilTimeCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ��������:������Σʱ���б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstPerilTimeList                ������Σʱ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Σʱ�α��]
* - #NAME_TYPE[������Σʱ������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPerilTimeList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_PERIL_TIME_INFO_S                    *pstPerilTimeList
);

/**
* ��ҳ��ѯ��������:������Σʱ�ν���б� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstPerilTimeResultList               ������Σʱ�ν���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #RESULT_CODE[������]
* - #CODE_TYPE[������Σʱ�α��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #PASS_TIME[ͨ������ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPerilTimeResultList
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                      *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                        *pstRspPageInfo,
    OUT VEHICLE_PERIL_TIME_RESULT_S            *pstPerilTimeResultList
);

#if 0
#endif
/**
* ��ӳ�������:������ν��ǲ����� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstOnlyIntoCity                 ��ν��ǲ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOnlyIntoCity
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLogIDInfo,
    IN  VEHICLE_ONLY_INTO_CITY_INFO_S           *pstOnlyIntoCityInfo
);

/**
* ɾ����������:������ν��ǲ����� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szOnlyIntoCity                  ��ν��ǲ����Ǳ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelOnlyIntoCity
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOnlyIntoCityCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ��������:������ν��ǲ������б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstOnlyIntoCityList             ��ν��ǲ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������ν��ǲ����Ǳ��]
* - #NAME_TYPE[������ν��ǲ���������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnlyIntoCityList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_ONLY_INTO_CITY_INFO_S                *pstOnlyIntoCityList
);

/**
* ��ҳ��ѯ��������:������ν��ǲ����ǽ���б� \n
* @param [IN]   pstUserLogIDInfo                      �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                     ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                      �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                        ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstOnlyIntoCityResultList ��ν��ǲ����ǽ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #RESULT_CODE[������]
* - #CODE_TYPE[������ν��ǲ����Ǳ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #PASS_TIME[ͨ������ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnlyIntoCityResultList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_ONLY_INTO_CITY_RESULT_S              *pstOnlyIntoCityResultList
);

#if 0
#endif

/**
* ��ӳ�������:����Ƶ��ҹ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstFrequentNightOutInfo         Ƶ��ҹ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFrequentNightOut
(
    IN  USER_LOGIN_ID_INFO_S                        *pstUserLogIDInfo,
    IN  VEHICLE_FREQUENT_NIGHT_OUT_INFO_S           *pstFrequentNightOutInfo
);

/**
* ɾ����������:����Ƶ��ҹ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szFrequentNightOutCode          Ƶ��ҹ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelFrequentNightOut
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szFrequentNightOutCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ��������:����Ƶ��ҹ���б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstFrequentNightOutList         Ƶ��ҹ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[����Ƶ��ҹ�����]
* - #NAME_TYPE[����Ƶ��ҹ������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFrequentNightOutList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_FREQUENT_NIGHT_OUT_INFO_S            *pstFrequentNightOutList
);

/**
* ��ҳ��ѯ��������:����Ƶ��ҹ������б� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstFrequentNightOutResultList        Ƶ��ҹ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #RESULT_CODE[������]
* - #CODE_TYPE[����Ƶ��ҹ�����]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #PASS_TIME[ͨ������ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFrequentNightOutResultList
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                      *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                        *pstRspPageInfo,
    OUT VEHICLE_FREQUENT_NIGHT_OUT_RESULT_S    *pstFrequentNightOutResultList
);

#if 0
#endif

/**
* ��ӳ�������:�������ҹ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstNocturnalInfo                ���ҹ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddNocturnal
(
    IN  USER_LOGIN_ID_INFO_S                        *pstUserLogIDInfo,
    IN  VEHICLE_FREQUENT_NIGHT_OUT_INFO_S           *pstNocturnalInfo
);

/**
* ɾ����������:�������ҹ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szNocturnalCode                 ���ҹ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelNocturnal
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szNocturnalCode[IMOS_CODE_LEN]
);

/**
* ��ҳ��ѯ��������:�������ҹ���б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstNocturnalList                ���ҹ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�������ҹ�����]
* - #NAME_TYPE[�������ҹ������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNocturnalList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_FREQUENT_NIGHT_OUT_INFO_S            *pstNocturnalList
);

/**
* ��ҳ��ѯ��������:�������ҹ������б� \n
* @param [IN]   pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                       ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstNocturnalResultList               ���ҹ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #RESULT_CODE[������]
* - #CODE_TYPE[�������ҹ�����]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #PASS_TIME[ͨ������ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNocturnalResultList
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                      *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                        *pstRspPageInfo,
    OUT VEHICLE_FREQUENT_NIGHT_OUT_RESULT_S    *pstNocturnalResultList
);

#if 0
#endif

/* End added by bt00977, 2013-1-25 of MPPD00420 */

/**
* ���ӳ������� \n
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstVehicleRestrictInfo  ����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_RESTRICT_INFO_S         *pstVehicleRestrictInfo
);

/**
* �޸ĳ������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleRestrictInfo  ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����/ֹͣ�������У�ʹ��IMOS_ProcessVehicleRestrict
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_RESTRICT_INFO_S         *pstVehicleRestrictInfo
);

/**
* ɾ���������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleRestrictCode   �������б���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleRestrictCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleRestrictCode   �������б���
* @param [OUT]  pstVehicleRestrictInfo  ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleRestrictCode[IMOS_CODE_LEN],
    OUT VEHICLE_RESTRICT_INFO_S         *pstVehicleRestrictInfo
);

/**
* ��ҳ��ѯ�������л�����Ϣ�б� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleRestrictBaseList  �������л�����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ/�����������԰���
* - #NAME_TYPE[��������]
* - #RESTRICT_TYPE[���з�ʽ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleRestrictBaseList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT VEHICLE_RESTRICT_BASE_S     *pstVehicleRestrictBaseList
);

/**
* ����/ֹͣ�������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szVehicleRestrictCode   �������б���
* @param [IN]   ulPlanStatus            BOOL_TRUE:����; BOOL_FALSE:ֹͣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleRestrictCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulPlanStatus
);


/**
* ��ѯ���������б�v2 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                ��Դ����
* @param [IN]   pstResList              ��Դ�б�
* @param [IN]   ulNestConditionNum      Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList    Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleDataList      ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DATA_TYPE[������������]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - VEHICLE_DATA_TYPE[������������]�����������ʱ����ʹ��SECTION_CODE��ѯ����
* - VEHICLE_DATA_TYPE[������������]���ڹ�������ʱ����ʹ��DOMAIN_CODE��TOLLGATE_CODE��ѯ����
* - DOMAIN_CODE��TOLLGATE_CODEֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_S                 *pstVehicleDataList
);

/*Added by yaozhongmin02844,2015-11-28*/
/**
* ��ѯ���������б�V5(���������壬��ȫ����������绰) \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                ��Դ����
* @param [IN]   pstResList              ��Դ�б�
* @param [IN]   ulNestConditionNum      Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList    Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleDataV4List    ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DATA_TYPE[������������]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - VEHICLE_DATA_TYPE[������������]�����������ʱ����ʹ��SECTION_CODE��ѯ����
* - VEHICLE_DATA_TYPE[������������]���ڹ�������ʱ����ʹ��DOMAIN_CODE��TOLLGATE_CODE��ѯ����
* - DOMAIN_CODE��TOLLGATE_CODEֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataListV5
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_V4_S              *pstVehicleDataV4List
);

/*end Added by yaozhongmin02844,2015-11-28*/

/*begin added by a02842 for �����ֶ�MPPD41265��2016-10-14*/
/**
* ��ѯ���������б�V5(���������壬��ȫ����������绰) \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                ��Դ����
* @param [IN]   pstResList              ��Դ�б�
* @param [IN]   ulNestConditionNum      Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList    Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleDataV6List    ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DATA_TYPE[������������]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - VEHICLE_DATA_TYPE[������������]�����������ʱ����ʹ��SECTION_CODE��ѯ����
* - VEHICLE_DATA_TYPE[������������]���ڹ�������ʱ����ʹ��DOMAIN_CODE��TOLLGATE_CODE��ѯ����
* - DOMAIN_CODE��TOLLGATE_CODEֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataListV6
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_V6_S              *pstVehicleDataV6List
);
/*end added by a02842 for �����ֶ�MPPD41265��2016-10-14*/

/**
* ��ѯ������������ \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [OUT]  szVehicleCount            ������������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataCount
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                        ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                        ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT CHAR                            szVehicleCount[IMOS_CODE_LEN]
);

/**
* ��ѯ������������,�������� \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [OUT]  szVehicleCount            ������������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataCountV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT CHAR                            szVehicleCount[IMOS_CODE_LEN]
);

/*Added by yaozhongmin02844,2015-12-05�������壬��ȫ����������绰*/
/**
* ��ѯ������������,�����壬��ȫ����������绰 \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [OUT]  szVehicleCount            ������������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataCountV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT CHAR                            szVehicleCount[IMOS_CODE_LEN]
);
/*End Added by yaozhongmin02844,2015-12-07*/


/**
* ��ѯ���������������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                ��Դ����
* @param [IN]   pstResList              ��Դ�б�
* @param [IN]   ulNestConditionNum      Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList    Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleDataV2List    ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ�뿨��ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DEAL_STATUS[������]
* - #DEPT_CODE[���ű���]
* @attention
* - �ڲ��ӿڣ�����ʹ��
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - DOMAIN_CODE��TOLLGATE_CODEֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleRedlistList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_V2_S              *pstVehicleDataV2List
);

/**
* ������������ϢУ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleDataV2        ������������ʻ��¼
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
* - �ڲ��ӿڣ�����ʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleRedlist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_DATA_V2_S               *pstVehicleDataV2
);

/**
* ��ѯȫ���������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   szPassTime              ����ʱ��
* @param [IN]   ulIntervalSec           ��ѯȫ��ͼƬʱ��������λ:��
* @param [OUT]  pstVehicleData          ȫ����������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehiclePanorama
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  CHAR                            szPassTime[IMOS_TIME_LEN],
    IN  ULONG_32                           ulIntervalSec,
    OUT  VEHICLE_DATA_S                 *pstVehicleData
);

/**
* ��ѯ���������б�v2 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                ��Դ����
* @param [IN]   pstResList              ��Դ�б�
* @param [IN]   ulNestConditionNum      Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList    Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleAlarmDataList ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[����������Ϣ���]
* - #VEHICLE_DATA_CODE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #ALARM_TYPE[�澯���]
* - #DISPOSITION_CODE[���ر��]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_DEPT[���ص�λ����]
* - #DISPOSITION_USER[������Ա����]
* - #EVENT_TIME[����ʱ��]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* - #COMBINE_FLAG[�ϳɱ�ʶ]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - ALARM_TYPE[�澯���]���ڲ��ظ澯ʱ��DISPOSITION_CODE��д�������ر�ţ���ʹ��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER
* - ALARM_TYPE[�澯���]���ں������澯ʱ��DISPOSITION_CODE��д��������ţ�DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - ALARM_TYPE[�澯���]����������ٸ澯ʱ��DISPOSITION_CODE��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - DOMAIN_CODE��TOLLGATE_CODE��DISPOSITION_DEPT��DISPOSITION_USERֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
* - COMBINE_FLAG[�ϳɱ�ʶ]��֧�ֵ���/�����ڣ�����0����ʾ�Ѻϳɣ�������0����ʾδ�ϳ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_ALARM_DATA_S           *pstVehicleAlarmDataList
);

/**
* ��ѯ���������б�(�ڲ��ӿڣ�����ʹ��) \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo          �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo            ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleAlarmDataV2List ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[����������Ϣ���]
* - #VEHICLE_DATA_CODE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #ALARM_TYPE[�澯���]
* - #DISPOSITION_CODE[���ر��]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_DEPT[���ص�λ����]
* - #DISPOSITION_USER[������Ա����]
* - #EVENT_TIME[����ʱ��]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* - #COMBINE_FLAG[�ϳɱ�ʶ]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - ALARM_TYPE[�澯���]���ڲ��ظ澯ʱ��DISPOSITION_CODE��д�������ر�ţ���ʹ��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER
* - ALARM_TYPE[�澯���]���ں������澯ʱ��DISPOSITION_CODE��д��������ţ�DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - ALARM_TYPE[�澯���]����������ٸ澯ʱ��DISPOSITION_CODE��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - DOMAIN_CODE��TOLLGATE_CODE��DISPOSITION_DEPT��DISPOSITION_USERֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
* - COMBINE_FLAG[�ϳɱ�ʶ]��֧�ֵ���/�����ڣ�����0����ʾ�Ѻϳɣ�������0����ʾδ�ϳ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataListV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_ALARM_DATA_V2_S        *pstVehicleAlarmDataV2List
);


/*Added by yaozhongmin02844,2015-12-03������ʻ��ȫ��������ʻ������绰*/
/**
* ��ѯ���������б�(�ڲ��ӿڣ�����ʹ��) \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo          �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo            ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleAlarmDataV3List ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[����������Ϣ���]
* - #VEHICLE_DATA_CODE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #ALARM_TYPE[�澯���]
* - #DISPOSITION_CODE[���ر��]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_DEPT[���ص�λ����]
* - #DISPOSITION_USER[������Ա����]
* - #EVENT_TIME[����ʱ��]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* - #COMBINE_FLAG[�ϳɱ�ʶ]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - ALARM_TYPE[�澯���]���ڲ��ظ澯ʱ��DISPOSITION_CODE��д�������ر�ţ���ʹ��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER
* - ALARM_TYPE[�澯���]���ں������澯ʱ��DISPOSITION_CODE��д��������ţ�DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - ALARM_TYPE[�澯���]����������ٸ澯ʱ��DISPOSITION_CODE��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - DOMAIN_CODE��TOLLGATE_CODE��DISPOSITION_DEPT��DISPOSITION_USERֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
* - COMBINE_FLAG[�ϳɱ�ʶ]��֧�ֵ���/�����ڣ�����0����ʾ�Ѻϳɣ�������0����ʾδ�ϳ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataListV4
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_ALARM_DATA_V3_S        *pstVehicleAlarmDataV3List
);

/*end Added by yaozhongmin02844,2015-12-03������ʻ��ȫ��������ʻ������绰*/

/*begin added by a02842 for �����ֶ�MPPD41265��2016-10-14*/
/**
* ��ѯ���������б�(�ڲ��ӿڣ�����ʹ��) \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo          �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo            ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleAlarmDataV6List ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[����������Ϣ���]
* - #VEHICLE_DATA_CODE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #ALARM_TYPE[�澯���]
* - #DISPOSITION_CODE[���ر��]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_DEPT[���ص�λ����]
* - #DISPOSITION_USER[������Ա����]
* - #EVENT_TIME[����ʱ��]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* - #COMBINE_FLAG[�ϳɱ�ʶ]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - ALARM_TYPE[�澯���]���ڲ��ظ澯ʱ��DISPOSITION_CODE��д�������ر�ţ���ʹ��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER
* - ALARM_TYPE[�澯���]���ں������澯ʱ��DISPOSITION_CODE��д��������ţ�DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - ALARM_TYPE[�澯���]����������ٸ澯ʱ��DISPOSITION_CODE��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - DOMAIN_CODE��TOLLGATE_CODE��DISPOSITION_DEPT��DISPOSITION_USERֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
* - COMBINE_FLAG[�ϳɱ�ʶ]��֧�ֵ���/�����ڣ�����0����ʾ�Ѻϳɣ�������0����ʾδ�ϳ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataListV6
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_ALARM_DATA_V6_S        *pstVehicleAlarmDataV6List
);
/*end added by a02842 for �����ֶ�MPPD41265��2016-10-14*/

/**
* ��ѯ������������ \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                  ��Դ����
* @param [IN]   pstResList                ��Դ�б�
* @param [IN]   ulNestConditionNum        Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList      Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [OUT]  szAlarmCount              ������������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataCount
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                        ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                        ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT CHAR                            szAlarmCount[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* ��ѯ����ƽ���ٶ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [OUT]  pulTollgateAverageSpeed ����ƽ���ٶ�KM/H
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��ѯʱ�β��ܳ���24Сʱ
        û�й�������ʱ,������Ч�ٶ�ֵ IMOS_TOLLGATE_INVALID_AVERAGE_SPEED
        ����ƽ���ٶ�KM/H,��(����ֵ * 1000) ULONG�������,����3λС��
        ͨ�ò�ѯ�����������
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_DIRECTION[����������]
* - #PASS_TIME[��ʼʱ��]
* - #PASS_TIME[����ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateAverageSpeed
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT ULONG_32                           *pulTollgateAverageSpeed
);

/**
* ��ҳ��ѯ��������ͼƬ:��������ͼƬ�б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   ulNestConditionNum              Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList            Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleCharacterPicList      ��������ͼƬ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #PASS_TIME[ͨ��ʱ��]
*   �������������Ҫ��ѯ�Ĺ�����Ϣ�б����������һ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataCharacterPicList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  ULONG_32                                        ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S                       *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_CHARACTER_PIC_S                      *pstVehicleCharacterPicList
);

/**
* ��ҳ��ѯ�澯����ͼƬ:�澯����ͼƬ�б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   ulNestConditionNum              Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList            Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleCharacterPicList      �澯����ͼƬ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�澯��Ϣ���]
* - #PASS_TIME[ͨ��ʱ��]
*   �������������Ҫ��ѯ�Ĺ�����Ϣ�б����������һ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataCharacterPicList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  ULONG_32                                        ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S                       *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_CHARACTER_PIC_S                      *pstVehicleCharacterPicList
);

/**
* ���ؽӿ� \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pcHttpUrl                  Http����URL
* @param [IN]   pcLocalFilePath            �����ļ�·��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_HttpDownload
(
    IN USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN CHAR *pcHttpUrl,
    IN CHAR *pcLocalFilePath
);

#if 0
#endif

/**
* ��ҳ��ѯ����������ʻ����ͳ������:������ͳ���б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleRealTimeStatList      ������ͳ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��ѯͳ�Ƶ����ݲ��ܳ���24Сʱ��֧�ֵĲ�ѯ��������
* - #STAT_TIME[ͳ��ʱ��]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleRealTimeStatByDirList
(
    IN  USER_LOGIN_ID_INFO_S                         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                              *pstRspPageInfo,
    OUT VEHICLE_REAL_TIME_STAT_BY_DIR_S              *pstVehicleRealTimeStatList
);

#if 0
#endif

/**
* ����TMS���ַת�� \n
* @param [IN]   pstUserLogIDInfo                    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTMSMultiAddrForwardInfo          TMS���ַת����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMSMultiAddrForward
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardInfo
);

/**
* ɾ��TMS���ַת�� \n
* @param [IN]   pstUserLogIDInfo                    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSMultiAddrForward               TMSת��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMSMultiAddrForward
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSMultiAddrForward[IMOS_CODE_LEN]
);

/**
* �޸�TMS���ַת�� \n
* @param [IN]        pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]        pstTMSMultiAddrForwardInfo     TMS���ַת����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMSMultiAddrForward
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN      TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardInfo
);

/**
* ��ѯTMS���ַת�� \n
* @param [IN]   pstUserLogIDInfo                    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSMultiAddrForward               TMSת��������
* @param [OUT]  pstTMSMultiAddrForwardInfo          TMS���ַת����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[ת��������]
* - #NAME_TYPE[ת����������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSMultiAddrForward
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSMultiAddrForward[IMOS_CODE_LEN],
    OUT TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardInfo
);

/**
* ��ѯTMS���ַת���б� \n
* @param [IN]   pstUserLogIDInfo                    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition                   ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTMSMultiAddrForwardList          TMS���ַת���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[ת��������]
* - #NAME_TYPE[ת����������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSMultiAddrForwardList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardList
);

#if 0
#endif



/**
* ���ӿ���������\n
* @param [IN]   pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTTollgateGroupInfo         ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateGroup
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TOLLGATE_GROUP_INFO_S   *pstTollgateGroupInfo
);

/**
* ɾ�������� \n
* @param [IN]   pstUserLogIDInfo                   �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateGroupCode               ��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateGroupCode[IMOS_CODE_LEN]
);

/**
* �޸Ŀ����� \n
* @param [IN]        pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]        pstTollgateGroupInfo    ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateGroup
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      TOLLGATE_GROUP_INFO_S   *pstTollgateGroupInfo
);

/**
* ��ѯ������\n
* @param [IN]   pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateGroupCode           ��������
* @param [OUT]  pstTollgateGroupInfo          ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[��������]
* - #NAME_TYPE[����������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateGroup
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTollgateGroupCode[IMOS_CODE_LEN],
    OUT TOLLGATE_GROUP_INFO_S   *pstTollgateGroupInfo
);
/**
* ��ѯ�������б� \n
* @param [IN]   pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition             ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo              �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateGroupList          �������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[��������]
* - #NAME_TYPE[����������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateGroupList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TOLLGATE_GROUP_INFO_S           *pstTollgateGroupList
);
#if 0
#endif

/**
* ��ѯΥ��ͼƬ�ϳ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstViolationCombineConf  �ϳ�Υ��ͼƬ���ӵ����ýṹ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryViolationCombineConf
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT VIOLATION_COMBINE_CONF_S    *pstViolationCombineConf
);

/**
* �޸�Υ��ͼƬ�ϳ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstViolationCombineConf    �ϳ�Υ��ͼƬ���ӵ����ýṹ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyViolationCombineConf
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  VIOLATION_COMBINE_CONF_S    *pstViolationCombineConf
);

/* Start added by lKF0174, 2013-11-18 of MPPD06792 */
/**
* �޸Ĺ�����¼/�澯��¼�ϴ���־λ \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTransFlagInfo           �޸��ϴ���־λ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ڲ��ӿڣ��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleTransFlag
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  VEHICLE_TRANS_FLAG_S        *pstVehicleTransFlag
);
/* End added by lKF0174, 2013-11-18 of MPPD06792 */
/** @} */ /* end of groupSDKTollgate */

/* Begin Added by shendongchun 00400 2014-02-26 for �����ݷ��������� */
/**
* ����DB \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDBInfo               DB��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DB_INFO_S                       *pstDBInfo
);

/**
* ɾ��DB \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDBCode                DB����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDBCode[IMOS_CODE_LEN]
);

/**
* �޸�DB \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDBInfo               DB��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DB_INFO_S                       *pstDBInfo
);

/**
* ��ѯDB \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDBCode                DB����
* @param [OUT]  pstDBInfo               DB��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDBCode[IMOS_CODE_LEN],
    OUT DB_INFO_S                       *pstDBInfo
);

/**
* ��ѯDB�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#NAME_TYPE[�豸����], DEV_SUB_TYPE[�豸������])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDBList               DB�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDBList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DB_INFO_S                      *pstDBList
);

/* End Added by shendongchun 00400 2014-02-26 for �����ݷ��������� */

#if 0
#endif

/**
* ����IAHR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstIAHRInfo             IAHR��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IAHR_INFO_S                     *pstIAHRInfo
);

/**
* ɾ��IAHR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szIAHRCode              IAHR����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIAHRCode[IMOS_CODE_LEN]
);

/**
* �޸�IAHR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstIAHRInfo             IAHR��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IAHR_INFO_S                     *pstIAHRInfo
);

/**
* ��ѯIAHR \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szIAHRCode              IAHR����
* @param [OUT]  pstIAHRInfo             IAHR��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIAHRCode[IMOS_CODE_LEN],
    OUT IAHR_INFO_S                     *pstIAHRInfo
);

/**
* ��ѯIAHR�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#NAME_TYPE[�豸����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstIAHRList             IAHR�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHRList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  IAHR_INFO_S                    *pstIAHRList
);

/**
* ����IAHR�洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstStoreResBasicInfo    �洢��Դ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����ϵͳ��֧��IPSAN�洢��ulStorageType��������ΪSTORE_DEV_TYPE_IPSAN
*       ����ϵͳ��֧���Զ�ѡ��洢�豸��bAutoSelectStoreDev��������Ϊ��дBOOL_FALSE
*       ����ϵͳ��֧�ֹ����洢��ʽ��ulDiskFullPolicy��������ΪDISK_FULL_POLICY_OVERLOAD
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIAHRStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* ɾ��IAHR�洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode               �洢��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIAHRStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN]
);

/**
* ��ѯIAHR�洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode               �洢��Դ����
* @param [OUT]  pstStoreResBasicInfo    �洢��Դ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHRStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    OUT STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* ��ѯIAHR�洢��Դ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode               �豸����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ,#NAME_TYPE[��Դ����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstStoreResBasicList    �洢��Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHRStoreResList
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szDevCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S         *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                  *pstRspPageInfo,
    OUT STORE_RES_BASIC_QUERY_ITEM_S     *pstStoreResBasicList
);

/**
* ��ѯIAHR������Դ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTMSCode               TMS����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateLocalResList ���ڱ�����Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHRLocalResList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIACode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_LOCAL_RES_S           *pstIAHRLocalResList
);

/**
* ���ӵ羯�󶨹�ϵ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstElecPoliceBindInfo   �羯����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �羯�󶨵Ŀ����б�ο���Դ�б�ʽ�����֧��200��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddElecPoliceBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ELEC_POLICE_BIND_INFO_S         *pstElecPoliceBindInfo
);

/**
* ɾ���羯�󶨹�ϵ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szElecPoliceCode        �羯����
* @param [IN]   szTollgateCode          ���ڱ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ���ڱ���Ϊ��,������п���;ָ�����ڱ���,���ָ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelElecPoliceBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szElecPoliceCode[IMOS_CODE_LEN],
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�羯�󶨹�ϵ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szElecPoliceCode        �羯����
* @param [OUT]  pstElecPoliceBindInfo   �羯����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryElecPoliceBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szElecPoliceCode[IMOS_CODE_LEN],
    OUT  ELEC_POLICE_BIND_INFO_S        *pstElecPoliceBindInfo
);

/**
* �޸�/���� ��ͨ�¼� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTrafficEventInfo     ��ͨ�¼���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTrafficEvent
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  TMS_TRAFFIC_EVENT_S           *pstTrafficEventInfo
);

/**
* ��ѯ��ͨ�¼��б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTrafficEventInfoList ��ͨ�¼��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note ֧�ֵĲ�ѯ��������:
* //TO-DO z02878
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrafficEventList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TMS_TRAFFIC_EVENT_S             *pstTrafficEventInfo
);



/**
* ��ѯ����������Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode       ���ڱ���
* @param [OUT]  pstDispositionInfo      ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateFlowInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    OUT  TOLLGATE_FLOW_INFO_S   *pstTollgateFlowInfo
);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

