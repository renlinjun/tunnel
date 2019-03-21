/*************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------------
                              sdk_func_inner.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2010-04-09
        Author: w05867
   Description: SDK�����ⷢ���ĺ����ӿ�
                ע��: ���з�ҳ��ѯʱ�������б�ռ����ⲿ���룬
                      ��С���ݷ�ҳ��ѯʱһҳ�ĸ����������롣


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_FUNC_INNER_H_
#define _IMOS_SDK_FUNC_INNER_H_

#include <string>
#include <vector>

/**
* ͨ�ò�ѯ�ӿ�
* @param [IN]       pstUserLoginID      �û���¼ID��Ϣ��ʶ
* @param [IN]       ulQryFlag           ��ѯ��־λ#UNI_QUERY_FLAG_E
* @param [IN]       ulQryPieceNum       ��ѯPIECE��Ŀ
* @param [IN]       pulQryPiecelist     ��ѯPIECE�б�
* @param [IN]       pstSdkConditon      ��ѯԼ����Ϣ
* @param [IN][OUT]  pstSdkPageInfo      ��ѯ��ҳ��Ϣ
* @param [OUT]      oQryInfo            ��ѯ����PIECE�����б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* - 2. �����߹����С�C/C++ ---> �������� ---> ����ʱ�⡱����������Ϊ�����̵߳��� DLL (/MDd)��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Query
(
    IN USER_LOGIN_ID_INFO_S        *pstUserLoginID,
    IN ULONG_32                       ulQryFlag,
    IN ULONG_32                       ulQryPieceNum,
    IN ULONG_32                       *pulQryPiecelist,
    IN UNI_CONDITION_S             *pstConditon,
    INOUT UNI_PAGE_S               *pstPageInfo,
    OUT std::vector<std::string>   &oQryInfo
);

/* Begin: added by zhangdong(kf0134), 2013.9.10 for ͨ�ò�ѯ�ӿ�*/
/**
* ͨ�ò�ѯ�ӿ�
* @param [IN] USER_LOGIN_ID_INFO_S        *pstUserLoginID       �û���¼ID��Ϣ��ʶ
* @param [IN] CHAR                         *pcSql             ��ѯsql �����Ϣ
* @param [IN] ULONG                       ulQryFlag             ��ѯ��־λ #UNIVERSAL_QUERY_FLAG_E
* @param [INOUT] SDK_PAGE_S               *pstSdkPageInfo       ��ѯ��ҳ��Ϣ
* @param [OUT] std::vector<std::string>   &oQryInfo             ��ѯ�õ������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* - 2. �����߹����С�C/C++ ---> �������� ---> ����ʱ�⡱����������Ϊ�����̵߳��� DLL (/MDd)��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBySql
(
    IN           USER_LOGIN_ID_INFO_S        *pstUserLoginID,
    IN           ULONG_32                                    ulQryFlag,
    IN           CHAR                                     *pcSql,
    INOUT     UNI_PAGE_INFO_S                *pstPageInfo,
    OUT        std::vector<std::string>        &oQryInfo
);
/* End: added by zhangdong(kf0134), 2013.9.10 for ͨ�ò�ѯ�ӿ�*/


#ifdef  __cplusplus
extern "C"{
#endif


/**
* ���ò�Ʒ��ʶ
* @param [IN] pstPdtInfo    ��Ʒ��Ϣ
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*   - �˽ӿ���Ҫ��IMOS_Initiateǰ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPDTInfo(IN PDT_INFO_S *pstPdtInfo);

/**
* ����PTZ����
* @param [IN] pstUserLogIDInfo �û���Ϣ��ʶ
* @param [IN] szCameCode       ���������
* @param [IN] pcData           �����͵�����
* @param [IN] ulDataLen        �����͵����ݳ���, ��󳤶�Ϊ#IMOS_STRING_LEN_1024
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendPtzData
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szCameCode[IMOS_CODE_LEN],
    IN  CHAR                 *pcData,
    IN  ULONG_32                 ulDataLen
);

/**
* ����ECʵ��������Ӧ��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSetNetworkAdapt       ʵ��������Ӧ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetNetworkAdapt
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    CHAR                       szEcCode[IMOS_CODE_LEN],
    IN    NETWORK_ADAPT_INFO_S       *pstSetNetworkAdapt
);

/**
* ��ѯECʵ��������Ӧ��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstSetNetworkAdapt       ʵ��������Ӧ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNetworkAdapt
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    CHAR                        szEcCode[IMOS_CODE_LEN],
    OUT   NETWORK_ADAPT_INFO_S        *pstSetNetworkAdapt
);


/**
* �޸���������ӽ���Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCameraViewInfo       ��������ӽ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCameraViewInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_VIEW_INFO_S              *pstCameraViewInfo
);

/**
* ��ѯ��������ӽ���Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode            ���������
* @param [OUT]  pstCameraViewInfo       ��������ӽ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraViewInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    OUT CAMERA_VIEW_INFO_S              *pstCameraViewInfo
);

/**
* ���ӵ�·��Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstRoadInfo             ��·��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRoadPathInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   MAP_ROAD_INFO_S             *pstRoadInfo
);

/**
* �޸ĵ�·��Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstRoadInfo             ��·��Ϣ�����ݵ�·ID�޸�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyRoadPathInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      MAP_ROAD_INFO_S             *pstRoadInfo
);

/**
* ɾ����·��Ϣ
* @param [IN]     pstUserLogIDInfo                 �û���Ϣ
* @param [IN]     dulRoadID                        ��·ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteRoadPathInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      DULONG                      dulRoadID
);

/**
* ��ѯ��·��Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstQueryPageInfo        ��ѯ��ҳ��Ϣ
* @param [IN]     pstQueryCondition       ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��·����] #CODE_TYPE[��·ID])
* @param [OUT]    pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]    pstRoadInfoList         ·����Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ���� szPathCode ����˳��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRoadPathList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT MAP_ROAD_INFO_S                 *pstRoadInfoList
);

/**
* ���ӵ�·����ͳ��������Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     MAP_ROAD_FLOWMETER_S    ��·����ͳ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRoadFlowmeterInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      MAP_ROAD_FLOWMETER_S        *pstFlowmeterInfo
);

/**
* �޸ĵ�·����ͳ��������Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     MAP_ROAD_FLOWMETER_S    ��·����ͳ��������Ϣ,���ݵ�·ID�޸�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyRoadFlowmeterInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      MAP_ROAD_FLOWMETER_S        *pstFlowmeterInfo
);

/**
* ɾ��·������ͳ��������Ϣ
* @param [IN]     pstUserLogIDInfo                 �û���Ϣ
* @param [IN]     dulRoadID                        ��·ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteRoadFlowmeterInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      DULONG                      dulRoadID
);

/**
* ��ѯ·������ͳ��������Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstQueryPageInfo        ��ѯ��ҳ��Ϣ
* @param [IN]     pstQueryCondition       ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[��·ID])
* @param [OUT]    pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]    pstFlowmeterList        ��·����ͳ��������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ���� szPathCode ����˳��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRoadFlowmeterList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT MAP_ROAD_FLOWMETER_S            *pstFlowmeterList
);


#if 0
#endif

/* Begin Added by zhangzeyaoKF0189, 2013-08-26 for monitorlite,��ѯ�豸��Ϣ(MWARE)*/
/**
* �豸������Ϣ��ʾ\n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [OUT]  DEV_BASE_INFO_FOR_ECR_S *pstDevBaseInf      �豸������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeviceBaseInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    OUT DEV_BASE_INFO_FOR_ECR_S             *pstDevBaseInfo
);

/**
* �豸������Ϣ��ʾ\n
* ������ϸ˵��
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param[OUT]   pstDevRunStatus �豸ʵʱ������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeviceRunStatForECR
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT DEV_RUN_STATUS_FOR_ECR_S   *pstDevRunStatus
);

/**
* �豸����������\n
* ������ϸ˵��
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param[OUT]   pstNicNumber    ��������
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNICNumberForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT NIC_NUMBER_FOR_ECR_S        *pstNicNumber
);

/**
* �豸������������Ϣ\n
* ������ϸ˵��
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param[IN]      ulNICIndex    ���������
* @param[OUT]     *pstNicInfo   �豸������������Ϣ
* @return ERR_COMMON_SUCCEED��ʾ�ɹ���ʧ�ܷ������������
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNICInfoForECR
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      ULONG_32                   ulNICIndex,
    OUT     NIC_INFO_FOR_ECR_S      *pstNicInfo
);
/* End   Added by zhangzeyaoKF0189, 2013-08-26 for monitorlite,��ѯ�豸��Ϣ(MWARE)*/

/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    ��֯�����
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
* - #CODE_TYPE[ͨ�ñ�������]
* - #PASS_TIME[ͨ��ʱ��/ʻ�뿨��ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DATA_TYPE[������������]
* @����
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataListForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_FOR_ECR_S                 *pstVehicleDataList
);
/* Begin AddedBy liuhongjieKF0170 2013-8-30 ����3D�ڸǹ��� */
/**
* @brief 3D�ڸ�������Ϣ��ѯ\n
* @param [IN]  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo �û���Ϣ
* @param [IN]  CHAR                            szCameraCode   ���������
* @param [IN]  ULONG                           ulAreaIndex    ��������
                                                   -- �������� ��д 0     ��ѯ���е��ڸ�����
                                                               ��д����   ��ѯָ������������������Ϣ
* @param [OUT] THREE_DIM_COVER_POSITION_STATE_S *pst3DCoverPositionState   ��ѯ����������Ϣ
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_3DCoverPositionState
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                 szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                               ulAreaIndex,    /* �����0 ��ѯ���еģ����������ѯ��������area*/
    OUT THREE_DIM_COVER_POSITION_STATE_S    *pst3DCoverPositionState
);


/**
* ��λ3D�ڸ�����
* @param [IN]  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,  �û���Ϣ
* @param [IN]  CHAR                   szCameraCode        ���������
* @param [IN]  ULONG                  ulAreaIndex         �ڸ���������

* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Local3DCover
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulAreaIndex
);
/* End AddedBy liuhongjieKF0170 2013-8-30 ����3D�ڸǹ��� */


/* Begin AddedBy liuhongjieKF0170 2013-9-4 ����OSD���� */
/**
* ����IPC����ͨ��OSD2.0��Ϣ
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         �û���Ϣ
* @param [IN]  DEV_CHANNEL_INDEX_S      *pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]    NEW_OSD_ROW_COMM_PARAM_S *pstOSDRowCommPara        OSDͨ����Ϣ
* @param [IN]  ULONG                    ulAreaNum                 ����ͨ��OSD��ĸ���
* @param [IN]  VIDEO_AREA_S             *pstArea                  OSD����Ϣ
* @param [IN]  ULONG                    ulOSDNum,                 OSD����
* @param [IN]  NEW_OSD_S                *pstNewOSD                ����ͨ��OSD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigNewOSD
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S   *pstChannelIndex,
    IN  NEW_OSD_ROW_COMM_PARAM_S  *pstOSDRowCommPara,
    IN  ULONG_32                 ulAreaNum,
    IN  VIDEO_AREA_S          *pstArea,
    IN  ULONG_32                 ulOSDNum,
    IN  NEW_OSD_S             *pstNewOSD
);

/**
* ��ѯIPC����ͨ��OSD2.0��Ϣ
* @param [IN]     USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         �û���Ϣ
* @param [IN]     DEV_CHANNEL_INDEX_S      *pstChannelIndex          �豸ͨ��������Ϣ
* @param [OUT]    NEW_OSD_ROW_COMM_PARAM_S *pstOSDRowCommPara        OSDͨ����Ϣ
* @param [INOUT]  ULONG                    ulAreaNum                 ����ͨ��OSD��ĸ���
* @param [OUT]    VIDEO_AREA_S             *pstArea                  OSD����Ϣ
* @param [INOUT]  ULONG                    ulOSDNum,                 OSD����
* @param [OUT]    NEW_OSD_S                *pstNewOSD                ����ͨ��OSD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNewOSD
(
    IN      USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN      DEV_CHANNEL_INDEX_S       *pstChannelIndex,
    OUT     NEW_OSD_ROW_COMM_PARAM_S  *pstOSDRowCommPara,
    INOUT   ULONG_32                     *pulAreaNum,
    OUT     VIDEO_AREA_S              *pstArea,
    INOUT   ULONG_32                     *pulOSDNum,
    OUT     NEW_OSD_S                 *pstNewOSD
);
/* End AddedBy liuhongjieKF0170 2013-9-4 ����OSD���� */
/**ǰ��ͼƬץ��ͼƬ��Ϣ��ѯ
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstOperateLogInfo       ��־��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �����ͨ�ò�ѯ������pstQueryCondition����ΪNULL
* - 2. ֧�ְ����ơ�ʱ�䡢�����ѯ,
* -   ��Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:
* -   #OPER_TIME
* - 3. ���������������Ĭ�ϰ��ղ���ʱ�併������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPictureInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT PICTURE_TAKE_INFO_S         *pstPictureInfo
);

/**
* ����IPC����ͨ��OSD2.0��ϢV2
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         �û���Ϣ
* @param [IN]  DEV_CHANNEL_INDEX_S      *pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]    NEW_OSD_ROW_COMM_PARAM_S_V2 *pstOSDRowCommPara        OSDͨ����Ϣ
* @param [IN]  ULONG                    ulAreaNum                 ����ͨ��OSD��ĸ���
* @param [IN]  VIDEO_AREA_S_V2             *pstArea                  OSD����Ϣ
* @param [IN]  ULONG                    ulOSDNum,                 OSD����
* @param [IN]  NEW_OSD_S                *pstNewOSD                ����ͨ��OSD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigNewOSDV2
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S   *pstChannelIndex,
    IN  NEW_OSD_ROW_COMM_PARAM_S_V2  *pstOSDRowCommPara,
    IN  ULONG_32                 ulAreaNum,
    IN  VIDEO_AREA_S_V2          *pstArea,
    IN  ULONG_32                 ulOSDNum,
    IN  NEW_OSD_S             *pstNewOSD
);

/**
* ��ѯIPC����ͨ��OSD2.0��Ϣ
* @param [IN]     USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         �û���Ϣ
* @param [IN]     DEV_CHANNEL_INDEX_S      *pstChannelIndex          �豸ͨ��������Ϣ
* @param [OUT]    NEW_OSD_ROW_COMM_PARAM_S_V2 *pstOSDRowCommPara        OSDͨ����Ϣ
* @param [INOUT]  ULONG                    ulAreaNum                 ����ͨ��OSD��ĸ���
* @param [OUT]    VIDEO_AREA_S_V2             *pstArea                  OSD����Ϣ
* @param [INOUT]  ULONG                    ulOSDNum,                 OSD����
* @param [OUT]    NEW_OSD_S                *pstNewOSD                ����ͨ��OSD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNewOSDV2
(
    IN      USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN      DEV_CHANNEL_INDEX_S       *pstChannelIndex,
    OUT     NEW_OSD_ROW_COMM_PARAM_S_V2  *pstOSDRowCommPara,
    INOUT   ULONG_32                     *pulAreaNum,
    OUT     VIDEO_AREA_S_V2              *pstArea,
    INOUT   ULONG_32                     *pulOSDNum,
    OUT     NEW_OSD_S                 *pstNewOSD
);


/**
* ��ѯ�����豸��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szInterDeviceCode       ���������
* @param [IN]   szInterLocalDomainCode  �������
* @param [OUT]  pstDeviceInfo           ��ѯ�豸��Ϣ���
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExdomianDeviceInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],/* ������豸�����Ǳ����豸�����Ӧ�Ļ������� */
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],/* ����ı�������Ǳ�������Ӧ�Ĺ��껥�����룬�����ķ������Ŀ�������������ɿ��� */
    OUT DEVICE_INFO_S                   *pstDeviceInfo
);


/* Begin Add by zhengyibing(01306), 2014-03-05 for ��Բ���PAG���� */
/**
* ��ѯPAG-GB�����������Ŀ¼
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szDevCode               ���������
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGBCamCatalog
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_CODE_LEN]
);
/* End Add by zhengyibing(01306), 2014-03-05 for ��Բ���PAG���� */

/**
* ��ʼ/�����ֶ��洢
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szCamCode               ���������
* @param [IN]   szInterLocalDomainCode  ����������
* @param [IN]   ulManualRecordMode      �ֶ��洢�����ǣ�0ֹͣ��1����
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessManualRecordGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulManualRecordMode
);

/**
* �����豸
* @param [IN] pstUserLogIDInfo  �û���Ϣ��ʶ
* @param [IN] szDevCode         �豸����
* @param [IN] szInterLocalDomainCode  ����������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RebootDeviceGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN]
);


/**
* �ֶ���������-(�ֶ��������ֶ�����) \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   szInterLocalDomainCode  ����������
* @param [IN]   ulAlarmSrcType          �澯����
* @param [IN]   ulCtrlMode              1 �ֶ�������0 �ֶ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CtrlManualGuardGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ULONG_32                           ulCtrlMode
);


/**
* �澯���ô��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   szInterLocalDomainCode  ����������
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AlarmResetGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN]
);


/* Begin added by z00758,2013-11-28 for ������������Ŵ� */
/**
* @brief ������̨���������Ŵ�Э��\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
* @param [IN]  CHAR                         szCameraCode   ���������
* @param [IN]  ULONG                         ulZoomProtocol   ����Ŵ�Э��
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigZoomProtocol
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    IN  ULONG_32                    ulZoomProtocol
);
/* End added by z00758,2013-11-28 for ������������Ŵ� */

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
* ���ü�ܴ���Ļ�����Ϣ. \n
* @param [IN] USER_LOGIN_ID_INFO_S * pstUserLogIDInfo   �û���Ϣ
* @param [IN] GUARD_AGENT_INFO_FOR_ECR_S *   pstGuardAgentInfo ��ܴ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
* - 1. �޸����ײ�����ʽ��ҪSDK�û����������豸�Ľӿں��豸������������Ч.
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetGuardAgentInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  GUARD_AGENT_INFO_FOR_ECR_S  *pstGuardAgentInfo
);

/**
* ��ȡ���ƽ̨������Ϣ. \n
* @param [IN] USER_LOGIN_ID_INFO_S * pstUserLogIDInfo  �û���Ϣ
* @param [OUT] GUARD_AGENT_INFO_FOR_ECR_S * pstGuardAgentInfo ���ƽ̨��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetGuardAgentInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT GUARD_AGENT_INFO_FOR_ECR_S  *pstGuardAgentInfo
);

/**
* ���ü�ܴ���Ļ�����Ϣ. \n
* @param [IN] USER_LOGIN_ID_INFO_S *pstUserLogIDInfo   �û���Ϣ
* @param [IN] CHAR      *pszCameraCode   ���������
* @param [IN] ULONG     ulCameraIndex   �����������
* @param [IN] ULONG     ulActionType   ��������
* @param [IN] CHAR      *pszDesc   ����
* @param [IN] CHAR      *pszPictureName  ͼƬ����
* @param [IN] ULONG     ulPictureFormat  ͼƬ��ʽ
* @param [IN] ULONG     ulPictureSize ͼƬ�ߴ�
* @param [IN] CHAR      *pastPicture ͼƬ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CameraMaintainForECR
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  CHAR    *pcCameraCode,
    IN  ULONG_32   ulCameraIndex,
    IN  ULONG_32   ulActionType,
    IN  CHAR    *pcDesc,
    IN  CHAR    *pcPictureName,
    IN  ULONG_32   ulPictureFormat,
    IN  ULONG_32   ulPictureSize,
    IN  CHAR    *pastPicture
);

/**
* ���IPC
* @param [IN] USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,  �û���Ϣ
* @param [IN] ADD_IPC_INFO_S         *pstIPCInfo         IPC��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIPC
(
    IN    USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN    ADD_IPC_INFO_S             *pstIPCInfo
);

/**
* ��ѯIPC������
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         �û���Ϣ
* @param [IN]  DEV_CHANNEL_INDEX_S      *pstChannelIndex          �豸ͨ��������Ϣ
* @param [OUT]  IPC_CAPABILITIES_S      *pstUniIPCCapabilities    IPC��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUniIPCCapabilities
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szDeviceCode[IMOS_DEVICE_CODE_LEN],
    OUT IPC_CAPABILITIES_S        *pstUniIPCCapabilities
);

/**
* ��������ͨ���ƶ����������ϢV2
* @param [IN]  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,         �û���Ϣ
* @param [IN]  DEV_CHANNEL_INDEX_S            *pstChannelIndex,          �豸ͨ��������Ϣ
* @param [IN]  ULONG                          ulMotionDetectAreaNum,    ����ͨ���ƶ��������ĸ���
* @param [IN]  MOTION_DETECT_AREA_S           *pstMotionDetectArea,      ����ͨ���ƶ����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMotionDetectAreaV2
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S            *pstChannelIndex,
    IN  ULONG_32                          ulMotionDetectAreaNum,
    IN  MOTION_DETECT_AREA_S           *pstMotionDetectArea
);

/**
* ��ѯ����ͨ���ƶ����������ϢV2
* @param [IN]     USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,         �û���Ϣ
* @param [IN]     DEV_CHANNEL_INDEX_S           *pstChannelIndex,          �豸ͨ��������Ϣ
* @param [INOUT]  ULONG                         ulMotionDetectAreaNum,    ����ͨ���ƶ��������ĸ���
* @param [OUT]    MOTION_DETECT_AREA_S          *pstMotionDetectArea,      ����ͨ���ƶ����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMotionDetectAreaV2
(
    IN      USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN      DEV_CHANNEL_INDEX_S        *pstChannelIndex,
    INOUT   ULONG_32                      *pulMotionDetectAreaNum,
    OUT     MOTION_DETECT_AREA_S       *pstMotionDetectArea
);

/**
* ��ѯ����ͨ������Ȥ������Ϣ
* @param [IN]       USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,     �û���Ϣ
* @param [IN]       DEV_CHANNEL_INDEX_S       *pstChannelIndex,      �豸ͨ��������Ϣ
* @param [INOUT]    ULONG                     *pulAreaNum,           ����ͨ������Ȥ����ĸ���
* @param [OUT]      ROI_AREA_S                *pstArea,              ����ͨ������Ȥ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryROIArea
(
    IN      USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN      DEV_CHANNEL_INDEX_S        *pstChannelIndex,
    INOUT   ULONG_32                      *pulAreaNum,
    OUT     ROI_AREA_S                 *pstArea
);

/**
* ��������ͨ������Ȥ������ϢV2
* @param [IN]  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,        �û���Ϣ
* @param [IN]  DEV_CHANNEL_INDEX_S     *pstChannelIndex,         �豸ͨ��������Ϣ
* @param [IN]  ULONG                   ulROIAreaNum,             ����ͨ������Ȥ����ĸ���
* @param [IN]  ROI_AREA_S              *pstArea,                 ����ͨ������Ȥ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigROIArea
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S     *pstChannelIndex,
    IN  ULONG_32                   ulROIAreaNum,
    IN  ROI_AREA_S              *pstArea
);

/**
* ��ѯ����ͨ����Ϣ
* @param [IN]  USER_LOGIN_ID_INFO_S  pstUserLogIDInfo            �û���Ϣ
* @param [IN]  DEV_CHANNEL_INDEX_S   pstChannelIndex             �豸ͨ��������Ϣ
* @param [OUT] VIN_CHANNEL_EXTEND_S  pstVideoInChannelInfo       ����ͨ����չ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVideoInChannelV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT VIN_CHANNEL_EXTEND_S            *pstVideoInChannelInfo
);

/**
* ����EC����ͨ��ͨ����չ��Ϣ
* @param [IN] USER_LOGIN_ID_INFO_S  pstUserLogIDInfo            �û���Ϣ
* @param [IN] DEV_CHANNEL_INDEX_S   pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN] VIN_CHANNEL_EXTEND_S  pstVideoInChannelInfo       ����ͨ����չ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigVideoInChannelV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIN_CHANNEL_EXTEND_S            *pstVideoInChannelInfo
);

/**
* ��ѯIPC xml����FTP��Ϣ\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���¼��Ϣ
* @param [OUT] FTP_INFO_S *pstFtpInfo FTP��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetIPCXMLFTPInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT FTP_INFO_S                  *pstFtpInfo
);

/**
* ���浼��xml��֪ͨƽ̨���м�Ȩ\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���¼��Ϣ
* @param [IN] CHAR szIPCXMLFilePath                 FTP·��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckIPCXML
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szIPCXMLFilePath[IMOS_FILE_PATH_LEN]
);

/**
* ������¼�����ݵ�����DVR��NVR ����U�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ���������ڹ��˵�����¼��
* @param [IN]   szUsbFoldPath        ����U�̵�·��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExportVehicleVideoToUSBForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  CHAR    szUsbFoldPath[IMOS_FILE_PATH_LEN]
);

/**
*  ��ѯ¼�񵼳�����\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstExportProcess       ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExportVideoProcessForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT EXPORT_PROCESS_FOR_ECR_S             *pstExportProcess
);

/**
* ������ͼƬ���ݵ�����DVR��NVR ����U�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ���������ڹ��˵�����¼��
* @param [IN]   szUsbFoldPath        ����U�̵�·��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExportVehiclePicToUSBForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  CHAR    szUsbFoldPath[IMOS_FILE_PATH_LEN]
);

/**
*  ��ѯͼƬ��������\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstExportProcess       ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExportPicProcessForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT EXPORT_PROCESS_FOR_ECR_S             *pstExportProcess
);

/**
*  ͨ��UM��ѯU����Ϣ\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstUMUsbDiskInfo       U����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUMUsbDiskForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT UM_USB_DISK_INFO_FOR_ECR_S             *pstUMUsbDiskInfo
);

/**
*  ͨ��UM��ѯU���ļ�����Ϣ\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstUMUsbDirInfo       U���ļ�����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUMUsbDirForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT UM_USB_DIR_LIST_FOR_ECR_S                *pstUMUsbDirInfo
);

/* Begin:Added by nirenzhuo01045, 2013.05.21 for ����ҵ���Ż� */
/**
* ���������������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareOutputSrcNum     �������������
* @param [IN]   pstShareOutputSrcList   ���������������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareOutputSrcForECR
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  CHAR                   szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                  ulShareFlag,
    IN  ULONG_32                  ulShareOutputSrcNum,
    IN  SHARE_ALARMOUT_BASE_S  *pstShareOutputSrcList
);

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
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDictionaryDataForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_FOR_ECR_S               *pstDictionaryData
);

/**
* ɾ�������ֵ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   szDictionaryDataCode    �����ֵ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDictionaryDataForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  CHAR                            szDictionaryDataCode[IMOS_DICTIONARY_KEY_LEN]
);
/**
* �޸������ֵ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       �����ֵ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �������޸������ֵ�����
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDictionaryDataForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_FOR_ECR_S               *pstDictionaryData
);
/**
* �����������Ͳ�ѯ�����ֵ�ö���б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������:#CODE_TYPE[�����ֵ����];#NAME_TYPE[�����ֵ�����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDictionaryDataList   �����ֵ�ö���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDictionaryDataListForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DICTIONARY_DATA_FOR_ECR_S               *pstDictionaryDataList
);
/* End Added by lw0581,2013-11-6 for  VVD06374*/
/* Begin Added by lw0581,2013-11-12 for  VVD05864*/
/**
* ����MAS�洢��Դ��������е�����ͷ��ͳһ����洢��Դ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstStoreMasResInfo         ����洢������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignMasStoreResForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAS_STORE_RES_INFO_FOR_ECR_S                *pstStoreMasResInfo
);

/**
* ����MAS�洢��Դ
* @param [IN]   pstUserLogIDInfo          �û���Ϣ
* @param [IN]   pstStoreMasResInfo        ���ݴ洢������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExpandMasStoreResForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAS_STORE_RES_INFO_FOR_ECR_S                *pstStoreMasResInfo
);
/* End Added by lw0581,2013-11-12 for  VVD05864*/

/* Begin Add by zhengyibing(01306), 2014-03-05 for ��Բ���PAG���� */
/**
* @brief ��ѯ�������������\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
* @param [IN]  CHAR                       szCameraCode   ���������
* @param [OUT] BOOL_T                     *pbIsExDomainCamara   �Ƿ�Ϊ��������� ; ��������� BOOL_TRUE  ���������BOOL_FALSE
* @param [OUT] BOOL_T                     *pbIsDevOnline         �豸�Ƿ�����
* @param [OUT] BOOL_T                     *pbIsExDomain          �Ƿ�������
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraDomain
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    OUT BOOL_T                          *pbIsExDomainCamara,
    OUT BOOL_T                          *pbIsDevOnline,
    OUT BOOL_T                          *pbIsExDomain
);

/**
* @brief �����������Ϣ��ѯ������
* @param [IN]  CHAR                       szCameraCode   ���������
* @param [IN]  CHAR                       szInterLocalDomainCode   �������
* @param [OUT] DEVICE_STATUS_S             *pstDeviceStatus ��ѯ�豸״̬���
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainCameraStatusProc
(
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_STATUS_S                 *pstDeviceStatus
);


/**
* @brief ���������״̬��ѯ������
* @param [IN]  CHAR                       szCameraCode   ���������
* @param [IN]  CHAR                       szInterLocalDomainCode   �������
* @param [OUT] DEVICE_STATUS_S             *pstDeviceStatus ��ѯ�豸״̬���
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_LoCameraStatusProc
(
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_STATUS_S                 *pstDeviceStatus
);


/**
* ��ѯ�豸״̬���������豸�͹���Э��PAG�����豸
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szInterDeviceCode       ���������
* @param [IN]   szInterLocalDomainCode  �������
* @param [OUT]  pstDeviceStatus         ��ѯ�豸״̬���
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note ��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExdomianDeviceStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_STATUS_S                 *pstDeviceStatus
);
/* End Add by zhengyibing(01306), 2014-03-05 for ��Բ���PAG���� */
/** Begin:add by lw0581, 2013-12-16 for MPPD07153�������澯�ָ�ֹͣ�洢 **/
/**
* �����澯����(for ECR&NVR)
* @param [IN]   USER_LOGIN_ID_INFO_S        pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   CHAR                        szAlarmSrcCode          �澯Դ����
* @param [IN]   ULONG                       ulAlarmType             �澯����
* @param [IN]   ALARM_ACTION_FOR_ECR_V2_S   pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmLinkageForECRV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_V2_S      *pstAlarmAction
);

/**
* �޸ĸ澯������Ϣ(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmType             �澯����
* @param [IN]   pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmLinkageForECRV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_V2_S       *pstAlarmAction
);

/**
* ��ѯ�澯������Ϣ(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmType          �澯����
* @param [OUT]  pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkageForECRV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    OUT ALARM_ACTION_FOR_ECR_V2_S       *pstAlarmAction
);
/** End:add by lw0581, 2013-8-16 for MPPD07153 �������澯�ָ�ֹͣ�洢 **/

/* Begin:Added by lw0581,2013.12.16 for MPPD07154 ���ת�����ñ���*/
/**
* ͨ�����������ӻ����в�ѯ��̨ת��\n
* @param [IN]   USER_LOGIN_ID_INFO_S pstUserLogIDInfo   �û���Ϣ�ṹ
* @param [IN]   CHAR   szCamCode[IMOS_CODE_LEN]               ���������
* @param [OUT] ULONG *pstSDKPtzSpeed   ��̨�ٶ���Ϣ
* @return   �������½��:
* - �ɹ�:
* - ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPtzSpeed
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR szCamCode[IMOS_CODE_LEN],
    OUT ULONG_32 *pulPtzSpeed
);
/* End:Added by lw0581,2013.12.16 for MPPD07154 ���ת�����ñ���*/

/* Begin: added by lw0581, 2013.12.19 for  MPPD06992 */
/**
* �����֯�ڵ㣬����������Ϣ \n
* @param [IN]     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo   �û���Ϣ
* @param [INOUT]  ORG_NODE_INFO_EXTEND_FORECR_S   *pstOrgNodeInfo     ��֯��Ϣ(INʱ,��֯�������Ϊ��;���Ϊ��,��OUT��֯����)
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOrganizationExtendForECR
(
    IN      USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    INOUT   ORG_NODE_INFO_EXTEND_FORECR_S  *pstOrgNodeInfo
);

/**
* �޸���֯�ڵ���Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo �û���Ϣ
* @param [IN]   ORG_NODE_INFO_EXTEND_FORECR_S   *pstOrgNodeInfo   ��֯�ڵ���Ϣ
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOrganizationExtendForECR
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   ORG_NODE_INFO_EXTEND_FORECR_S  *pstOrgNodeInfo
);

/**
* ��ѯ��֯�ڵ���Ϣ \n
* @param [IN]    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo           �û���Ϣ
* @param [IN]    CHAR                           szOrgCode                   ��֯�ڵ����
* @param [OUT]   ORG_NODE_INFO_EXTEND_FORECR_S  *pstOrgNodeInfo             ��֯�ڵ���Ϣ
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgInfoExtendForECR
(
    IN     USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN     CHAR                             szOrgCode[IMOS_DOMAIN_CODE_LEN],
    OUT    ORG_NODE_INFO_EXTEND_FORECR_S    *pstOrgNodeInfo
);

/**
* ��ȡ��֯���������֯�ڵ��б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(��֯��������)
* @param [IN]   USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo   �û���Ϣ
* @param [IN]   CHAR                          szOrgCode           ��֯�ڵ����
* @param [IN]   COMMON_QUERY_CONDITION_S      *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:NAME_TYPE[��֯����])
* @param [IN]   QUERY_PAGE_INFO_S             *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S               *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  ORG_NODE_INFO_EXTEND_FORECR_S *pstOrgNodeList     ��֯�ڵ��б�ָ��
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgListExtendForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ORG_NODE_INFO_EXTEND_FORECR_S   *pstOrgNodeList
);

/**
* ��Դת�ƣ�����֯Aת�Ƶ���֯B \n
* @param [IN]   USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo �û���Ϣ
* @param [IN]   CHAR   szDesOrgCode   ��֯ID
* @param [IN]   ULONG   ulResNum        ��Դ����
* @param [IN]   RES_ITEM_V2_S   *pstResInfo   ��Դ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TransferResToSpecifiedOrgForECR
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szDesOrgCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                ulResNum,
    IN  RES_ITEM_V2_S        *pstResInfo
);

/**
* ���ݽ�ɫ���룬��ѯĳ����ɫ��Ȩ����Ϣ(V2) \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode                   ��ɫ���룬��ӦΨһһ����ɫ
* @param [IN]   pstQueryCondition            ��ѯ����(֧�ֵĲ�ѯ��������:#RES_ID[��ԴID]
*                                                                        #RES_TYPE[��Դ����]��
*                                                                        #NAME_TYPE[��Դ����])
* @param [IN]   pstQueryPageInfo             �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo               ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResAuthorityList          ��ɫȨ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @attention
* - ȫ��Ȩ�޺�����Ȩ�ޱ���ֿ���ѯ��
* - ��ѯȫ��Ȩ��ʱ����ѯ����ΪRES_ID����0��������������ѯ��������ѯ����Ȩ��ʱ��RES_ID����0���ҿ�����������ѯ������
* - ���Ȩ�޼�¼��Ӧ����Դ�����ڣ����ν�ɫȨ���б��ж�Ӧ����Դ��RES_INFO_S��szResIdCode��Ч�������ֶζ���Ч��
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByRoleV2ForECR
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szRoleCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S            *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                   *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT RES_AUTHORITY_QUERY_ITEM_FORECR_S   *pstResAuthorityList
);

/**
* ���ݽ�ɫ���룬���ý�ɫȨ��(V2) \n
* @param [IN]   pstUserLogIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode            ��ɫ���룬��ӦΨһһ����ɫ
* @param [IN]   ulResAuthorityNum     ��Դ��Ȩ��Ϣ����
* @param [IN]   pstResAuthorityList   ��Դ��Ȩ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿ����õ���Դ��Χ�����ڽ�ɫ������֯������֯
* - 2. �����Ȩ�޿�����ϵͳȨ�ޣ�Ҳ�����������Դ��������֯������ͷ���������ȣ���Ȩ��
* - 3. ���øýӿں�, �Ըôε��õ�Ȩ��Ϊ׼����ɫ֮ǰ��Ȩ�޻ᱻ����
* - 4. ulResAuthorityNum����Ϊ0��ͬʱpstResAuthorityList����ΪNULL����ʾ�����ɫ����Ȩ�ޡ�
* - 5. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRoleAuthorityV2ForECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRoleCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulResAuthorityNum,
    IN  RES_AUTHORITY_FORECR_S  *pstResAuthorityList
);

/**
* ��ѯ��֯����Դ��Ϣ�б�(V3,����RES_INFO_S�ṹ��������ԴID��������Ȩ��) \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResList                 ��Դ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯��������Դ(��������֯)
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ�"��Դ����"ģ����ѯ:#NAME_TYPE
* - 4.֧�ְ�"�Ƿ�������Դ"��ѯ:#DOMAIN_TYPE = 1 ��;= 0 ��
* - 5.֧�ְ�"��Դ����"��ѯ:#RES_TYPE,ȡֵΪ#IMOS_TYPE_E
* - 6.֧�ְ�"��Դ������"��ѯ:#RES_SUB_TYPE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_TYPE_E)
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Դ����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��Դ����),#CODE_TYPE(��Դ����),#RES_TYPE(��Դ����),#RES_SUB_TYPE(��Դ������),
* -   #DOMAIN_TYPE(�Ƿ�������Դ)
* - ����
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceListNoAuthForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT RES_INFO_S                      *pstResList
);

/* Begin Added by zhangzeyaoKF0189, 2013-08-14 of IVSD02565 */
/**
* ��ѯ����ǰ�豸�£�֧��ָ������ͷ���������������ģ��+���֣����˶����澯����״̬,�����ƻ�����״̬
* �����ѯ����ʱ,������
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:INDEX_TYPE[����������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  CAMERA_MOTION_DETECT_ALARM_INFO_FOR_ECR_S *pstCameraMotionDetectInfoList ����ͷ����״̬��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllCameraMotionDetectAlarmInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                             *pstRspPageInfo,
    OUT CAMERA_MOTION_DETECT_ALARM_INFO_FOR_ECR_S   *pstCameraMotionDetectInfoList
);

/**
* ��ѯ����ǰ�豸�£�֧��ָ������ͷ���������������ģ��+���֣����ڵ����澯����״̬,�����ƻ�����״̬
* �����ѯ����ʱ,������
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:INDEX_TYPE[����������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  CAMERA_MASK_DETECT_ALARM_INFO_FOR_ECR_S *pstCameraMaskDetectInfoList ����ͷ�ڵ���Ϣ״̬�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllCameraMaskDetectAlarmInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                             *pstRspPageInfo,
    OUT CAMERA_MASK_DETECT_ALARM_INFO_FOR_ECR_S     *pstCameraMaskDetectInfoList
);

/**
* ָ���豸����������ѯ�����豸������EC+IPC�����豸��澯��Ӧ������������״̬ \n
* �����ѯ����ʱ,������
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:INDEX_TYPE[����������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  BUZZER_LINKED_ALARM_INFO_FOR_ECR_S *pstBuzzerLinkedAlarmInfoList �豸�澯����״̬��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllBuzzerLinkedAlarmInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S            *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                   *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT BUZZER_LINKED_ALARM_INFO_FOR_ECR_S  *pstBuzzerLinkedAlarmInfoList
);
/* End: added by lw0581, 2013.12.19 for  MPPD06992 */


/**
* ɨ��IPSAN \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szIpsanCode         IPSAN����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DM_DEV_NOT_ONLINE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ScanIpsan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIpsanCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ����MPɨ��洢�豸���� \n
* @param [IN]  pstUserLogIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]  szStoreDevCode    �洢�豸����
* @param [IN]  ulStoreDevType    �洢�豸���ͣ�ö��ֵ: #STORE_DEV_TYPE_E
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DM_DEV_NOT_ONLINE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ScanStoreDev
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
	IN  CHAR                           szStoreDevCode[IMOS_DEVICE_CODE_LEN],
	IN  ULONG_32                          ulStorageType
);


/**
* ��ѯ�û���ָ����Դ��Ȩ���б�. \n
* ����û���ϵͳ����Ա,��ֻ����"�Ƿ���ϵͳ����Ա"��ʶ,������Ȩ���б�;
* �������ϵͳ����Ա,�򷵻�Ȩ���б�(����ϵͳȨ�޺���ԴȨ��).
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResType           ��Դ����(ȡֵ#IMOS_TYPE_E)
* @param [IN]   szResCode           ��Դ����
* @param [OUT]  pbIsSystemMgr       "�Ƿ���ϵͳ����Ա"��ʶ, #BOOL_TRUEΪϵͳ����Ա, #BOOL_FALSEΪ��ϵͳ����Ա
* @param [OUT]  pstAuthorityInfo    Ȩ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_QUERY_AUTH_NUM_EXCEED_MAX
* -     ���ز�������룬���������ļ�
* @note ����û�Ϊ�ǵ�½�û����û���¼ ID���û�IPΪ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ULONG_32                   ulResType,
    IN  CHAR                    szResCode[IMOS_RES_CODE_LEN],
    OUT BOOL_T                  *pbIsSystemMgr,
    OUT ORG_AUTHORITY_V2_S         *pstAuthorityInfo
);

/**
* ������Դ��Ŀ����֯ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szDesOrgCode        Ŀ����֯����
* @param [IN]   szResCode           ��Դ����
* @param [IN]   ulResType           ��Դ����, ȡֵ��#IMOS_TYPE_E, Ŀǰ֧�ֵĺϷ�ȡֵΪ#IMOS_TYPE_EC; #IMOS_TYPE_DC; #IMOS_TYPE_CAMERA; #IMOS_TYPE_MONITOR; #IMOS_TYPE_DM; #IMOS_TYPE_TS;#IMOS_TYPE_MS; #IMOS_TYPE_VX500
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_DAO_DEVICE_NOT_EXIST
* - #ERR_MM_DEVICE_ALREADY_IN_DOMAIN
* -     ���ز�������룬���������ļ�
* @note
* - 1. �������Դû�б��룬�����Դ������Ϊ��Դ����
* - 2. һ����Դ���Ի��鵽�����֯���������ظ����鵽ͬһ����֯
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShareResToDesOrg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDesOrgCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulResType
);

/**
* ����Դ����֯�н������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szDesOrgCode        Ŀ����֯����
* @param [IN]   szResCode           ��Դ����
* @param [IN]   ulResType           ��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAMERA_ALREADY_SHARED
* - #ERR_MM_DEVICE_BELONG_TO_ORIGINAL_DOMAIN
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note 1���������Դû�б��룬�����Դ������Ϊ��Դ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ReclaimResFromDesOrg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDesOrgCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulResType
);

/**
* ��ѯ��֯����������������Ϣ�б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(�������������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   szExDomainCode     �������
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL)
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstCamShareInfo    �����������Ϣ�б�ָ��
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.����ͨ�ò�ѯ����:
*     #NAME_TYPE[���������]
*     #IS_QUERY_SHARED[��ѯ�ѹ����δ����] = 0 δ����; = 1 �ѹ���
*   2.�����ѯ������������й�����ˣ�����а�����֯����������������ѯ�����������(δ���� + �ѹ���)
*   3.�˽ӿڷ��ؽṹ�������֧�ֵ�����Ŀ(ulStreamNum)��Ч
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraShareInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SHARE_CAM_INFO_V2_S             *pstCamShareInfo
);

/**
* ��ѯĳ������������Ӧ�Ľ�������Ϣ
* @param [IN] pstUserLogIDInfo              �û���¼��Ϣ��ʶ
* @param [IN] szScrCode                     ����������
* @param [OUT]pstScrRelatedDC               ��������Ӧ�Ľ������ṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenRelatedDC
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szScrCode[IMOS_CODE_LEN],
    OUT   SCREEN_RELATED_DC_S           *pstScrRelatedDC
);

/**
* ��ҳ��ѯ�������豸����������������������������ϵ�ʵʱ��ؼ�¼ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   ulUAType                �豸����,ȡֵ��Χ��#IMOS_TYPE_E.ע:��ѯ�����ع�ϵʱ,�Ϸ���ȡֵΪ#IMOS_TYPE_XP(XP)
* @param [IN]   szUACode                �����/������/�������
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstMonitorUnit          ʵʱ��ؼ�¼�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_MONITOR_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMonitorRecordUnderUA
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  ULONG_32                       ulUAType,
    IN  CHAR                        szUACode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MONITOR_UNIT_S              *pstMonitorUnit
);

/**
* ��ѯʵʱ��ؼ�¼�б� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstMonRecList           ʵʱ��ؼ�¼�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֻ֧��tbl_monitor_record�ڵļ�¼
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMonitorRecordList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MONITOR_REC_S               *pstMonRecList
);

/**
* ��ѯ���м�¼�б� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstRecordList           ���м�¼�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֻ֧��tbl_switch_record�ڵļ�¼
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchRecordList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SWITCH_RECORD_S             *pstRecordList
);

/**
* ��ѯ���������������е�������Դ��Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szMonitorCode           ��Ӳ��ʵ����Ϊ����������; �����ʵ����Ϊ�������
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSwitchResBase        ������Դ������Ϣ
* @param [OUT]  pstSwitchResUnit        ������Դ��Ԫ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchResInfoUnderScreen
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo,
    IN   CHAR                       szMonitorCode[IMOS_RES_CODE_LEN],
    IN   QUERY_PAGE_INFO_S          *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S            *pstRspPageInfo,
    OUT  SWITCH_RES_BASE_S          *pstSwitchResBase,
    OUT  SWITCH_RES_UNIT_S          *pstSwitchResUnit
);


/**
* ��ѯ�豸�����ڽ��е�ҵ����Ϣ \n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode           �豸����
* @param [IN]   ulDevType           �豸����, ȡֵΪ#IMOS_TYPE_E, �Ϸ���ȡֵΪ#IMOS_TYPE_MONITOR(������), #IMOS_TYPE_XP_WIN(XP����)
* @param [IN]   szVirDomainCode     ���������
* @param [OUT]  pstSrvInfo          ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻʵ�ֲ�ѯʵʱ��ء����е�ҵ��״̬
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceUnderDev
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                   ulDevType,
    IN  CHAR                    szVirDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT SRV_STATE_INFO_S        *pstSrvInfo
);

/* Begin added by y01359, 2016-05-09 for A8 */
/**
* ��ѯ�豸�����ڽ��е�ҵ����Ϣ \n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ
* @param [IN]   szDevCode           �豸����
* @param [IN]   ulDevType           �豸����, ȡֵΪ#IMOS_TYPE_E, �Ϸ���ȡֵΪ#IMOS_TYPE_MONITOR(������), #IMOS_TYPE_XP_WIN(XP����)
* @param [IN]   szVirDomainCode     ���������
* @param [OUT]  *pstSrvInfo         ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻʵ�ֲ�ѯʵʱ��ء����е�ҵ��״̬
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceUnderDevV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                   ulDevType,
    IN  CHAR                    szVirDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT SRV_STATE_INFO_V2_S     *pstSrvInfo
);
/* End added by y01359, 2016-05-09 for A8 */

/**
* ��ѯ��Դ�����ڽ��е�ҵ����Ϣ \n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode           ��Դ����
* @param [IN]   ulResType           ��Դ����, ȡֵΪ#IMOS_TYPE_E, �Ϸ���ȡֵΪ#IMOS_TYPE_SALVO_RESOURCE(����ʾ), #IMOS_TYPE_GROUP_SWITCH_RESOURCE(����Ѳ)
* @param [IN]   szVirDomainCode     ���������
* @param [OUT]  pstSrvInfo          ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻʵ�ֲ�ѯ����ʾ��ҵ��״̬
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceUnderRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulResType,
    IN  CHAR                    szVirDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT RES_SRV_STATE_INFO_S    *pstSrvInfo
);

/**
* ��ҳ��ѯ�����㲥��Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szXPVocBrdCode          �����㲥����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVocBrdUnit           �����㲥��Ԫ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPlayerVoiceBroadcastInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szXPVocBrdCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT VOC_BRD_UNIT_S              *pstVocBrdUnit
);

/**
* ��ѯ����ҵ����Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szXPVocTalkCode         �����Խ�����
* @param [IN]   szXPVocBrdCode          �����㲥����
* @param [OUT]  szCameraCode            ���������
* @param [OUT]  szCameraName            ���������
* @param [OUT]  pulVoiceSrvType         ����ҵ������, ȡֵΪ#SRV_TYPE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_CS_VOCTALK_NOT_EXIST
* - #ERR_CS_VOCBRD_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryXPVoiceServiceInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szXPVocTalkCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szXPVocBrdCode[IMOS_RES_CODE_LEN],
    OUT CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    OUT CHAR                            szCameraName[IMOS_RES_CODE_LEN],
    OUT ULONG_32                           *pulVoiceSrvType
);

/***************************************************************************
����XP���鲥�ӿ�
****************************************************************************/
/**
* @name ����XP���鲥�ӿڹ���
* @{    ����XP���鲥�ӿڹ���
*/
/**
* ����XP���鲥��Ϣ
* @param [IN]  pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]  ulStreamType                 ���鲥���ͣ�0Ϊ������1Ϊ�鲥
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_XP_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.����Ҳ���xp����Ϣ�����øýӿڻ᷵��ʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigXPStreamType
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulStreamType
);

/**
* ��ѯXP���鲥����Ϣ
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [OUT]  pulStreamType                ���鲥���ͣ�0Ϊ�鲥��1Ϊ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_XP_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryXPStreamType
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulStreamType
);

/**
* ���ñ���ǰ���豸���ֱ��ý��������ϵͳ���� \n
* @param [IN]   pstUserLogIDInfo                �û���½��Ϣ
* @param [IN]   ulMaxMediaByPassOfTerminalDev   ǰ���豸���ֱ��ý��������(ȡֵ��Χ1~3)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֻ��admin�û�����Ȩ��
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CfgMaxMediaByPassOfTerminalDev
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulMaxMediaByPassOfTerminalDev
);

/**
* ��ѯ����ǰ���豸���ֱ��ý��������ϵͳ���� \n
* @param [IN]   pstUserLogIDInfo                �û���½��Ϣ
* @param [OUT]  pulMaxMediaByPassOfTerminalDev  ǰ���豸���ֱ��ý��������(ȡֵ��Χ1~3)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMaxMediaByPassOfTerminalDev
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulMaxMediaByPassOfTerminalDev
);
/** @} */ /* end of XP STREAM MANAGEMENT MODULE */
/** @} */ /* end of INFO MANAGEMENT MODULE */
#if 0
#endif
/*******************************************************************************
 �豸-EC,DC���ڹ���
*******************************************************************************/
/**
* @name �豸(EC,DC)���ڹ���
* @{    �豸(EC,DC)���ڹ���
*/
/**
* �����豸�Ĵ�����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [IN]   pstSerialInfo           ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_SERIAL_USED
* - #ERR_DAO_SERIAL_PORT_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfSerial
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  SERIAL_INFO_S               *pstSerialInfo
);


/**
* ��ҳ��ѯ�豸�Ĵ����б� \n
* ����Ϊ��ʱ,��ѯ���д���,��Ĭ�ϰ���"������������"����
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode              �豸����
* @param [IN]   ulDevType              �豸���ͣ�ȡֵ��Χ: #IMOS_TYPE_E
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#INDEX_TYPE[��������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSerialList          �����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySerialList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                           ulDevType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SERIAL_QUERY_ITEM_S             *pstSerialList
);

/**
* ��ѯ������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [OUT]  pstSerialInfo           ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SERIAL_PORT_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySerialInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT SERIAL_INFO_S                   *pstSerialInfo
);

/**
* ��ҳ��ѯĳ��EC���ڱ������Դռ�õ���Ϣ�б�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         ����ͨ��������Ϣ
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ(��֧��ƫ��)
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSerialRelationList   ���ڱ������Դռ�õ���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1��֧�ֲ�ѯ��EC����ģʽ��:��̨����(#IMOS_SE_PTZ)��͸��ͨ��(#IMOS_SE_TRANS)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECSerialUsedRelation
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SERIAL_RELATION_ITEM_S          *pstSerialRelationList
);
/** @} */ /* end of SERIAL MANAGEMENT MODULE */

#if 0
#endif
/************************************************************************************************************
 �豸-EC,DC OSDͼƬ
************************************************************************************************************/


#if 0
#endif

/**
* ��ѯĳ����֯�µı������б�  \n
    Begin modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
* ֧��ģ����ѯ��pstQueryCondition����Ϊ�գ���ʾ��������Ч����ѯ����֯�����б�����������ȱʡ����ģ����ѯ��Ĭ�ϰ���"��������������"����.
* ֧�ֲ�ѯEC��"HC"��"HD"��β��ECR,����ѯECRʱ��Ҫ����ָ���豸����ΪECR����pstQueryCondition��ָ��RES_TYPEΪ#IMOS_TYPE_ECR.
    End modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
  Begin added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* �����豸IP��ѯ��ֻ֧��ģ����ѯ����֧�־�ȷ��ѯ.
  End added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   �����
* @param [IN]   pstQueryCondition           ��ѯ��Ϣ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����������]; #CODE_TYPE[����������]; #RES_TYPE[��Դ����]; #PHY_DEV_IP[������IP��ַ]; #CAMERA_NAME[���������])
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstEcList                   EC��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ѯ�����е����������#CAMERA_NAMEֻ��ʹ��LIKE_FLAG����ģ����ѯ, ��ѯ�����������Ӧ�ı�����
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNormalEcList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EC_QUERY_ITEM_S                 *pstEcList
);

/**
* ��ѯĳ����֯�µı������б�  \n
    Begin modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
* ֧��ģ����ѯ��pstQueryCondition����Ϊ�գ���ʾ��������Ч����ѯ����֯�����б�����������ȱʡ����ģ����ѯ��Ĭ�ϰ���"��������������"����.
* ֧�ֲ�ѯEC��"HC"��"HD"��β��ECR,����ѯECRʱ��Ҫ����ָ���豸����ΪECR����pstQueryCondition��ָ��RES_TYPEΪ#IMOS_TYPE_ECR.
    End modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
  Begin added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* �����豸IP��ѯ��ֻ֧��ģ����ѯ����֧�־�ȷ��ѯ.
  End added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   �����
* @param [IN]   pstQueryCondition           ��ѯ��Ϣ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����������]; #CODE_TYPE[����������]; #RES_TYPE[��Դ����]; #PHY_DEV_IP[������IP��ַ]; #CAMERA_NAME[���������])
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstEcList                   EC��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ѯ�����е����������#CAMERA_NAMEֻ��ʹ��LIKE_FLAG����ģ����ѯ, ��ѯ�����������Ӧ�ı�����
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNetIPCList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EC_QUERY_ITEM_S                 *pstEcList
);


/**Begin Added by liujia ,2016-03-15 for �����������*/
/**
* ��ѯĳ����֯�µı������б��Լ����۱���Ϣ	\n
	Begin modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
* ֧��ģ����ѯ��pstQueryCondition����Ϊ�գ���ʾ��������Ч����ѯ����֯�����б�����������ȱʡ����ģ����ѯ��Ĭ�ϰ���"��������������"����.
* ֧�ֲ�ѯEC��"HC"��"HD"��β��ECR,����ѯECRʱ��Ҫ����ָ���豸����ΪECR����pstQueryCondition��ָ��RES_TYPEΪIMOS_TYPE_ECR.
	End modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
  Begin added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* �����豸IP��ѯ��ֻ֧��ģ����ѯ����֧�־�ȷ��ѯ.
  End added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* @param [IN]	pstUserLoginIDInfo			  �û���Ϣ��ʶ
* @param [IN]	szOrgCode					�����
* @param [IN]	pstQueryCondition			��ѯ��Ϣ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����������]; #CODE_TYPE[����������]; #RES_TYPE[��Դ����]; #PHY_DEV_IP[������IP��ַ]; #CAMERA_NAME[���������])
* @param [IN]	pstQueryPageInfo			�����ҳ��Ϣ
* @param [OUT]	pstRspPageInfo				���ط�ҳ��Ϣ
* @param [OUT]	pstEcList					EC��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ�
* @note
* - 1. ��ѯ�����е����������#CAMERA_NAMEֻ��ʹ��LIKE_FLAG����ģ����ѯ, ��ѯ�����������Ӧ�ı�����
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_QueryNetIPCListV2
(
	IN	USER_LOGIN_ID_INFO_S			*pstUserLoginIDInfo,
	IN	CHAR							 szOrgCode[IMOS_DOMAIN_CODE_LEN],
	IN	COMMON_QUERY_CONDITION_S		*pstQueryCondition,
	IN	QUERY_PAGE_INFO_S				*pstQueryPageInfo,
	OUT RSP_PAGE_INFO_S 				*pstRspPageInfo,
	OUT EC_QUERY_ITEM_V2_S				*pstEcList
);
/**End Added by liujia ,2016-03-15 for �����������*/



/**************************************************************************************************************
�豸-EC,DCͨ�����ƻ��Լ�SNMPģ�����
***************************************************************************************************************/
/** @defgroup groupTempletMg �豸(EC,DC)ģ���Լ��ƻ�ģ�����
*   �豸(EC,DC)ģ���Լ��ƻ�ģ�����
*   @{
*/
/**
* @name ECģ��
* @{    ECģ��
*/
/**
* ����ECͨ������ģ�� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKECChannelTemplet          ECͨ������ģ����Ϣ
* @param [OUT]  szECChannelTempletCode          ģ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddECChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  EC_CHANNEL_TEMPLET_S            *pstSDKECChannelTemplet,
    OUT CHAR                            szECChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* ɾ��EC����ģ�� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szECChannelTempletCode      ģ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANL_TEMPL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteECChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szECChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�EC����ģ�� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szECChannelTempletCode      ģ�����
* @param [IN]   pstSDKECChannelTemplet      ECͨ������ģ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANL_TEMPL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyECChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szECChannelTempletCode[IMOS_RES_CODE_LEN],
    IN  EC_CHANNEL_TEMPLET_S            *pstSDKECChannelTemplet
);


/**
* ��ҳ��ѯECͨ������ģ���б� \n
* ����Ϊ��ʱ,��ѯ����ģ��,��Ĭ�ϰ���"ͨ������������"����
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition          ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#DEV_SUB_TYPE[�豸������]; #NAME_TYPE[ģ������]; #TIME_TYPE[ģ�����ʱ��])
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKECChannelTempList    ECͨ������ģ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECChannelTempletList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CHANNEL_TEMP_QUERY_ITEM_S       *pstSDKECChannelTempList
);


/**
* ��ѯEC����ģ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szECChannelTempletCode      ģ�����
* @param [OUT]  pstSDKECChannelTemplet      ECͨ������ģ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANL_TEMPL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECChannelTemplet
(
    IN     USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN     CHAR                         szECChannelTempletCode[IMOS_RES_CODE_LEN],
    OUT    EC_CHANNEL_TEMPLET_S         *pstSDKECChannelTemplet
);
/** @} */  /* ECģ����� */
/**
* @name DCģ��
* @{    DCģ��
*/
/**
* ����DCͨ������ģ�� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKDCChannelTemplet      DCͨ������ģ����Ϣ
* @param [OUT]  szDCChannelTempletCode      ģ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DC_CHANNEL_TEMPLET_S        *pstSDKDCChannelTemplet,
    OUT CHAR                        szDCChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* ɾ��DC����ģ�� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDCChannelTempletCode      ģ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VOUT_CHANL_TEMPL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDCChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�DC����ģ�� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDCChannelTempletCode      ģ�����
* @param [IN]   pstSDKDCChannelTemplet      DC����ģ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VOUT_CHANL_TEMPL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDCChannelTempletCode[IMOS_RES_CODE_LEN],
    IN  DC_CHANNEL_TEMPLET_S            *pstSDKDCChannelTemplet
);


/**
* ��ҳ��ѯDCͨ������ģ���б� \n
* ����Ϊ��ʱ,��ѯ����ģ��,��Ĭ�ϰ���"ͨ��������"����.
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition          ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#DEV_SUB_TYPE[�豸������]; #NAME_TYPE[ģ������]; #TIME_TYPE[ģ�����ʱ��])
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKDCChannelTempList    DCͨ������ģ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDCChannelTempletList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CHANNEL_TEMP_QUERY_ITEM_S       *pstSDKDCChannelTempList
);


/**
* ��ѯDC����ģ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szDCChannelTempletCode          ģ�����
* @param [OUT]  pstSDKDCChannelTemplet          DC����ģ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VOUT_CHANL_TEMPL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDCChannelTempletCode[IMOS_RES_CODE_LEN],
    OUT DC_CHANNEL_TEMPLET_S        *pstSDKDCChannelTemplet
);
/** @} */  /* DCģ����� */


/**
* @name �ƻ�ģ��
* @{    �ƻ�ģ��
*/
/**
* ���Ӽƻ�ģ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKPlanTemplet       �ƻ�ģ����Ϣ
* @param [OUT]  szPlanTempletCode       ģ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPlanTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  PLAN_TEMPLET_S              *pstSDKPlanTemplet,
    OUT CHAR                        szPlanTempletCode[IMOS_RES_CODE_LEN]
);


/**
* ɾ���ƻ�ģ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szPlanTempletCode       ģ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PLAN_TEMPLET_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeletePlanTemplet
(
    IN USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN CHAR                             szPlanTempletCode[IMOS_RES_CODE_LEN]
);


/**
* �޸ļƻ�ģ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szPlanTempletCode       ģ�����
* @param [IN]   pstSDKPlanTemplet       �ƻ�ģ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PLAN_TEMPLET_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyPlanTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPlanTempletCode[IMOS_RES_CODE_LEN],
    IN  PLAN_TEMPLET_S              *pstSDKPlanTemplet
);


/**
* ��ҳ��ѯ�ƻ�����ģ���б� \n
* ����Ϊ��ʱ,��ѯ����ģ��,��Ĭ�ϰ���"ģ����������"����
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[ģ������]; #TIME_TYPE[ģ�����ʱ��])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstPlanTempList        �ƻ�ģ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPlanTempletList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CHANNEL_TEMP_QUERY_ITEM_S   *pstPlanTempList
);


/**
* ��ѯ�ƻ�����ģ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szPlanTempletCode       ģ������
* @param [OUT]  pstSDKPlanTemplet       �ƻ�ģ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PLAN_TEMPLET_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPlanTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPlanTempletCode[IMOS_RES_CODE_LEN],
    OUT PLAN_TEMPLET_S              *pstSDKPlanTemplet
);
/** @} */  /* �ƻ�ģ����� */
/** @} */ /* end of TEMPLET MANAGEMENT MODULE */
#if 0
#endif
/** @defgroup groupCruise Ѳ��ҵ��
*   Ѳ��ҵ��
*   @{
*/
/**
* @name Ѳ��·�߹���
* @{    Ѳ��·�߹���
*/
/**
* ����Ѳ��·��\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCruisePathInfo   Ѳ��·����Ϣ
* @param [OUT]  szCruisePathCode    Ѳ��·�߱���
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCruisePath
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CRUISE_PATH_INFO_S      *pstCruisePathInfo,
    OUT CHAR                    szCruisePathCode[IMOS_RES_CODE_LEN]
);


/**
* ɾ��Ѳ��·�� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePathCode    Ѳ��·�߱���
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CRUISE_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCruisePath
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN]
);


/**
* �޸�Ѳ��·�� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePathCode    Ѳ��·�߱���
* @param [IN]   pstCruisePathInfo   Ѳ��·����Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* - #ERR_DAO_CRUISE_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCruisePath
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCruisePathCode[IMOS_RES_CODE_LEN],
    IN  CRUISE_PATH_INFO_S      *pstCruisePathInfo
);


/**
* ��ҳ��ѯĳ���������Ѳ��·���б� \n
* ����Ϊ��ʱ,��������������Ѳ��·��,��Ĭ��"Ѳ��·��������������"
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   szCamCode              ���������
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[·������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCruisePathList      Ѳ��·���б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePathList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCamCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CRUISE_PATH_QUERY_ITEM_S    *pstCruisePathList
);


/**
* ��ѯĳ���������Ѳ��·�ߵ���ϸ��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePathCode    Ѳ��·�߱���
* @param [OUT]  pstCruisePathInfo   Ѳ��·����Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* - #ERR_DAO_PRESET_VALUE_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePathInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN],
    OUT CRUISE_PATH_INFO_S          *pstCruisePathInfo
);

/**
* �ֶ�����Ѳ��·��
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePathCode    Ѳ��·�߱���
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_NO_OUTDOMAIN_OPERATE_CRUISE
* - #ERR_DAO_CRUISE_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* - #ERR_PTZ_AUTHORITY_LOW
* - �������ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCruisePath
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN]
);

/**
* �ֶ�ֹͣѲ��·��
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePathCode    Ѳ��·�߱���
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_NO_OUTDOMAIN_OPERATE_CRUISE
* - #ERR_DAO_CRUISE_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* - #ERR_PTZ_AUTHORITY_LOW
* - �������ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCruisePath
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN]
);

/**
* ֹͣ������µ������ֶ�Ѳ��·��
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode        ���������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_NO_OUTDOMAIN_OPERATE_CRUISE
* - #ERR_AS_CAMERA_NOT_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* - #ERR_PTZ_AUTHORITY_LOW
* - �������ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopAllCruisePathByCam
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_DEVICE_CODE_LEN]
);
/** @} */ /* Ѳ��·�߽��� */

#if 0
#endif
/***************************************************************************
Ѳ���ƻ�
****************************************************************************/
/**
* @name Ѳ���ƻ�����
* @{    Ѳ���ƻ�����
*/
/**
* ����Ѳ���ƻ�\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCruisePlanInfo   Ѳ���ƻ���Ϣ
* @param [OUT]  szCruisePlanCode    Ѳ���ƻ�����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* - #ERR_DAO_CRUISE_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CRUISE_PLAN_INFO_S          *pstCruisePlanInfo,
    OUT CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* �����˺�Ѳ���ƻ�
* @param [IN]	pstUserLoginIDInfo		  �û���Ϣ
* @param [IN]	pstCruisePlanInfo		Ѳ���ƻ���Ϣ
* @param [OUT]	szCruisePlanCode		Ѳ���ƻ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCruisePlanV2
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CRUISE_V2_PLAN_INFO_S			*pstCruisePlanInfo,
	OUT CHAR						szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* �޸�Ѳ���ƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePlanCode    Ѳ���ƻ�����
* @param [IN]   pstCruisePlanInfo   Ѳ���ƻ���Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN],
    IN  CRUISE_PLAN_INFO_S          *pstCruisePlanInfo
);


/**
* �޸İ˺�Ѳ���ƻ�
* @param [IN]	pstUserLoginIDInfo		  �û���Ϣ
* @param [IN]	szCruisePlanCode		Ѳ���ƻ�����
* @param [IN]	pstCruisePlanInfo		Ѳ���ƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCruisePlanV2
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CHAR						szCruisePlanCode[IMOS_RES_CODE_LEN],
	IN	CRUISE_V2_PLAN_INFO_S			*pstCruisePlanInfo
);


/**
* ɾ��Ѳ���ƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePlanCode    Ѳ���ƻ�����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* ��ѯѲ���ƻ�\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePlanCode    Ѳ���ƻ�����
* @param [OUT]  pstCruisePlanInfo   Ѳ���ƻ���Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CRUISEID_NOT_EXIST
* - #ERR_DAO_CAMERA_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN],
    OUT CRUISE_PLAN_INFO_S          *pstCruisePlanInfo

);



/**
* ��ѯ�˺�Ѳ���ƻ�
* @param [IN]	pstUserLoginIDInfo		  �û���Ϣ
* @param [IN]	szCruisePlanCode		Ѳ���ƻ�����
* @param [OUT]	pstCruisePlanInfo		Ѳ���ƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePlanV2
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CHAR						szCruisePlanCode[IMOS_RES_CODE_LEN],
	OUT CRUISE_V2_PLAN_INFO_S			*pstCruisePlanInfo
);


/**
* ��ҳ��ѯѲ���ƻ��б� \n
* ����Ϊ��ʱ,������Ѳ���ƻ�,��Ĭ��"Ѳ���ƻ���������"����
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode              ��֯����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[�ƻ�����]��
* -                                    #TIME_TYPE[����ʱ��]��#CODE_TYPE[���������])
* @param [IN    pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCruisePlanList      Ѳ���ƻ��б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note Ŀǰ��֧�ְ���֯��ѯѲ���ƻ��б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePlanList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CRUISE_PLAN_QUERY_ITEM      *pstCruisePlanList
);


/**
* ʹ��Ѳ���ƻ� \n
* @param [IN    pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePlanCode    Ѳ���ƻ�����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* ȥʹ��Ѳ���ƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCruisePlanCode    Ѳ���ƻ�����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);
/** @} */  /* Ѳ���ƻ����� */
/** @} */ // end of groupCruise
#if 0
#endif
/***************************************************************************
�澯
****************************************************************************/
/** @defgroup groupAlarm �澯����
*   �澯��������澯Դ��ɾ�Ĳ�(�б�)���澯����豸��ɾ�Ĳ�(�б�)���澯������ɾ�Ĳ��
*   @{
*/
/**
* ������չ�澯Դ(������������,������,�������)
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstAlarmSrc                 �澯Դ��Ϣ
* @param [OUT]  szAlarmSrcCode              �澯Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.�澯Դ���벻����Ϊ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ALARM_SRC_S                         *pstAlarmSrc,
    OUT CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN]
);


/**
* ɾ����չ�澯Դ(������������,������,�������)
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode              �澯Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN]
);


/**
* �޸���չ�澯Դ��Ϣ(������������,������,�������)
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode              �澯Դ����
* @param [IN]   pstAlarmSrc                 �澯Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note �澯Դ�ı��벻���޸�, �����޸ĸ澯Դ��Ϣʱ��Ҫ��д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ALARM_SRC_S                         *pstAlarmSrc
);


/**
* ��ѯ��չ�澯Դ��Ϣ(������������,������,�������)
* @param [IN]   pstUserLoginIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode              �澯Դ����
* @param [OUT]  pstAlarmSrc                 �澯Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN],
    OUT ALARM_SRC_S                         *pstAlarmSrc

);


/**
* ��ҳ��ѯ��֯�µĸ澯Դ(����������,������,��������Լ���չ�澯Դ)�б�  \n
* ����Ϊ��ʱ,��ѯ���и澯Դ,��Ĭ�ϰ���"�澯Դ��������"����.
* @param [IN]   pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]   szOrgCode              ��֯����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[�澯Դ����]��#DOMAIN_TYPE[����������:0 ����,1 ����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmSrcExList      �澯Դ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmSrcList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALARM_SRC_QUERY_ITEM_EX_S   *pstAlarmSrcExList
);


/**
* �����澯����豸
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstAlarmExporter            �澯����豸��Ϣ
* @param [OUT]  szAlarmExporterCode         �澯����豸����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.�澯����豸���벻����Ϊ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ALARM_EXPORTER_S                    *pstAlarmExporter,
    OUT CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN]
);


/**
* ɾ���澯����豸
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmExporterCode         �澯����豸����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN]
);


/**
* �޸ĸ澯����豸��Ϣ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmExporterCode         �澯����豸����
* @param [IN]   pstAlarmExporter            �澯����豸��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN],
    IN  ALARM_EXPORTER_S                    *pstAlarmExporter
);


/**
* ��ѯ�澯����豸��Ϣ
* @param [IN]   tUserLoginIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmExporterCode         �澯����豸����
* @param [OUT]  pstAlarmExporter            �澯����豸��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN],
    OUT ALARM_EXPORTER_S                    *pstAlarmExporter

);


/**
* ��ҳ��ѯ��֯�µĸ澯����豸�б�  \n
* ����Ϊ��ʱ,�����и澯����豸,��Ĭ��"�澯����豸������������"
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode              ��֯����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[�豸����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmExporterList   �澯����豸��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmExporterList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALARM_EXPORTER_QUERY_ITEM_S *pstAlarmExporterList

);

/**
* ��ѯ�澯��Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szEventRecordCode   �澯����
* @param [OUT]  pstEventRecord      �澯��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_EVENT_NOT_EXIST
 * -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarm
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szEventRecordCode[IMOS_RES_CODE_LEN],
    OUT EVENT_RECORD_S          *pstEventRecord
);


/**
* ��ҳ��ѯ�澯��Ϣ�б�
* ����Ϊ��ʱ,��ѯ���н�ɫ,��Ĭ�ϰ���"�澯ʱ�併��"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#USER_NAME_TYPE[ȷ���û�����];
* -                                 #NAME_TYPE[�澯Դ����]; #EVENT_TYPE[�澯�¼�����]; #EVENT_SECURITY[�澯�¼�����];
* -                                 #EVENT_STATUS_TYPE[�澯״̬]; #EVENT_TIME[�澯ʱ��]; #IS_PLAN_ALARM[�Ƿ�澯Ԥ��];
* -                                 #IS_ONCE_PLAN_ALARM[�Ƿ�������Ԥ��]; #IS_MISINFORM[�Ƿ���] #CODE_TYPE[�澯Դ����];
* -                                 #CHK_USER_NAME_TYPE[�˾��û�����];)
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmList        �澯��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note 1.�澯���ؼ��������Σ������ʾΪ����
* -     2.�澯���ؼ����������ʾ��Σ��Ϊ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EVENT_RECORD_S                  *pstAlarmList
);

/**
* ��ҳ��ѯ�澯��Ϣ�б�(���������豸����)
* ����Ϊ��ʱ,��ѯ���н�ɫ,��Ĭ�ϰ���"�澯ʱ�併��"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#USER_NAME_TYPE[ȷ���û�����];
* -                                 #NAME_TYPE[�澯Դ����]; #EVENT_TYPE[�澯�¼�����]; #EVENT_SECURITY[�澯�¼�����];
* -                                 #EVENT_STATUS_TYPE[�澯״̬]; #EVENT_TIME[�澯ʱ��]; #IS_PLAN_ALARM[�Ƿ�澯Ԥ��];
* -                                 #IS_ONCE_PLAN_ALARM[�Ƿ�������Ԥ��]; #IS_MISINFORM[�Ƿ���] #CODE_TYPE[�澯Դ����];
* -                                 #CHK_USER_NAME_TYPE[�˾��û�����];)
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmList        �澯��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note 1.�澯���ؼ��������Σ������ʾΪ����
* -     2.�澯���ؼ����������ʾ��Σ��Ϊ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EVENT_RECORD_V2_S                  *pstAlarmList
);


/**
* ȷ�ϸ澯
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szEventRecordCode       �澯����
* @param [IN]   szAckSuggestion         �澯ȷ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_EVENT_NOT_EXIST
* - #ERR_AS_ALARM_CONFIRMED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfirmAlarm
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szEventRecordCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szAckSuggestion[IMOS_DESC_LEN]
);


/**
* ���Ӹ澯����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmType             �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LINKAGE_EXIST
* -     ���ز�������룬���������ļ�
* @note ��������ȫ�ظ��Ķ�������ע�������е�������������ö��"ͬһ���������ͬһ��������", �������óɹ���������ֻ��
*       �������õĻ�ִ�гɹ�.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_S                  *pstAlarmAction
);


/**
* ɾ���澯����
* @param [IN]  pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]  szAlarmSrcCode               �澯Դ����
* @param [IN]  ulAlarmType                  �澯����, ȡֵΪ#AlARM_TYPE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType
);


/**
* �޸ĸ澯������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmType             �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��������ȫ�ظ��Ķ�������ע�������е�������������ö��"ͬһ���������ͬһ��������", �������óɹ���������ֻ��
*       ���ȵ����û�ִ�гɹ�.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_S                  *pstAlarmAction
);


/**
* ��ѯ�澯������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmSrcType          �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [OUT]  pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_LINKAGE_NOT_EXIST
* - #ERR_AS_LINKAGE_NUM
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    OUT ALARM_ACTION_S                  *pstAlarmAction
);

/**
* ��ѯ�澯�¼���Ϣ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ��ѯ������֧�ְ�����ֹʱ���Լ��澯���������ѯ¼��
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmEventInfo       �澯������Ϣ���ݽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��ѯʱ���Ȳ��ܴ���24Сʱ������¼�����������ʱ���ʽΪ��"%Y-%m-%d %H:%M:%S"��ʽ ����Ϣ�����޶�Ϊ24�ַ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmEventList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ALARM_EVENT_QUERY_CONDITION_S *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALARM_EVENT_INFO_S          *pstAlarmEventInfo
);

/* Begin added by z00758,2012-11-13 for VVD75914 */
/**
* ��ѯ��ʷ�澯�������������¼����Ϣ(Ŀǰ��֧��������DA�����) \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstAlarmLinkageStoreInfo        �澯����¼����Ϣ
* @param [OUT]  pstExDomainCamStoreInfo       ���������¼��洢��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLinkageExDomainCamStore
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ALARM_LINKAGE_STORE_INFO_S           *pstAlarmLinkageStoreInfo,
    OUT EXDOMAIN_CAM_STORE_INFO_S          *pstExDomainCamStoreInfo
);
/* End added by z00758,2012-11-13 for VVD75914 */

/** @} */ /* end of ALARM MODULE */

#if 0
#endif
/**************************************************************************************************************
�����Լ������ƻ� GuardPlan Edited By sunyifan(06966)  Complete
**************************************************************************************************************/
/** @defgroup groupGPMg �����Լ������ƻ�����
*   �����Լ������ƻ�����
*   @{
*/
/**
* ���Ӳ����ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmSrcType          �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [IN]   pstGuardPlanInfo        �����ƻ���Ϣ
* @param [OUT]  szGuardPlanCode         �����ƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  GUARD_PLAN_INFO_S               *pstGuardPlanInfo,
    OUT CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN]
);

/**
* �޸Ĳ����ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGuardPlanCode         �����ƻ�����
* @param [IN]   pstGuardPlanInfo        �����ƻ���Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN],
    IN  GUARD_PLAN_INFO_S               *pstGuardPlanInfo
);

/**
* ɾ�������ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGuardPlanCode         �����ƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯ�����ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGuardPlanCode         �����ƻ�����
* @param [OUT]  pstGuardPlanInfo        �����ƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN],
    OUT GUARD_PLAN_INFO_S               *pstGuardPlanInfo
);


/**
* ��ҳ��ѯ�����ƻ��б� \n
* ����Ϊ��ʱ,��ѯ���в����ƻ�,��Ĭ�ϰ���"�ƻ���������"����.
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode              ��֯����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[�ƻ�����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstGuardPlanList       �����ƻ��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPlanList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GUARD_PLAN_QUERY_ITEM_S     *pstGuardPlanList
);

/**
* �����ƻ� - ��ѯ�б�(���澯Դ����) \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode      �澯Դ����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstGuardPlanList    �����ƻ���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPlanListBySrc
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szAlarmSrcCode[IMOS_DEVICE_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GUARD_PLAN_QUERY_ITEM_S     *pstGuardPlanList
);


/**
* ���Ʋ����ƻ�, ���������ƻ���������ֹͣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGuardPlanCode         �����ƻ�����
* @param [IN]   ulCtrlMode              ���Ʋ���������, 1Ϊ����; 0Ϊֹͣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CtrlGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulCtrlMode
);

/**
* �ֶ���������, �����ֶ��������ֶ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmSrcType          �澯����
* @param [IN]   ulCtrlMode              1Ϊ�ֶ�����, 0Ϊ�ֶ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CtrlManualGuard
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ULONG_32                           ulCtrlMode
);

/** @} */ /* end of GUARD PLAN MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
GIS
****************************************************************************/
/** @defgroup groupGIS  GIS��ͼ����
*   GIS��ͼ��������ϴ�,����,ɾ��,����GIS��ͼ�Ƚӿ�,�ȵ�,����,�ı���,������Դͼ�����ɾ�Ĳ�(�б�)��
*   @{
*/
/*--------------------------------------------GIS��ͼ����--------------------------------------*/

/**
* �ϴ�GIS��ͼʱ, ����ͼ�����Լ��ļ����ϴ�������������У��, �ɹ���, ����FTP�������û����������Լ��ļ����·��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstGISInfo              GIS��Ϣ("��ͼ�ļ���"�������ظ�,���������ظ��ϴ�"ͬ�ļ���"��ͼ)
* @param [OUT]  pstFtpInfo              FTP������Ϣ
* @param [OUT]  pulSequenceNumber       ����FTP�����������к�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_MAP_NUM_OVERFLOW
* - #ERR_AS_FIND_SAME_MAP_NAME
* - #ERR_AS_FIND_SAME_MAP_FILE_NAME
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisMapStart
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  FILE_GIS_INFO_S             *pstGISInfo,
    OUT FTP_INFO_S                  *pstFtpInfo,
    OUT ULONG_32                       *pulSequenceNumber
);

/**
* ���ϴ�GIS��ͼ�Ľ��, ֪ͨ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess              �ϴ��ļ��Ľ��, #BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @param [IN]   ulSequenceNumber        ����FTP�����������к�
* @param [OUT]  szGISMapCode            GIS��ͼ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_UPLOAD_MAP_FAIL
* - #ERR_DAO_GIS_MAP_CODE_EXIST
* - #ERR_DAO_GIS_MAP_NAME_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisMapEnd
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  BOOL_T                        bIsSuccess,
    IN  ULONG_32                         ulSequenceNumber,
    OUT CHAR                          szGISMapCode[IMOS_RES_CODE_LEN]
);

/**
* ��ȡGIS��ͼ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [OUT]  pstGISInfo              GIS��ͼ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MAP_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetGisMapInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    OUT FILE_GIS_INFO_S             *pstGISInfo
);



/**
* ����GIS��ͼ��ʱ������FTP�������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [OUT]  pstFtpInfo              FTP������Ϣ
* @param [OUT]  ulSequenceNumber        ����FTP�����������к�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_FIND_SAME_MAP_FILE_NAME
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisMapStart
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    OUT FTP_INFO_S                  *pstFtpInfo,
    OUT ULONG_32                       *ulSequenceNumber
);

/**
* ������GIS��ͼ�Ľ��֪ͨ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess              �ϴ��ļ��Ľ����#BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @param [IN]   ulSequenceNumber        ����FTP�����������к�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisMapEnd
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  BOOL_T                        bIsSuccess,
    IN  ULONG_32                         ulSequenceNumber
);


/**
* ɾ��GIS��ͼ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MAP_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ע�⣬���ɾ�����ļ���Ҳ���سɹ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGisMap
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�GIS��ͼ����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szGisMapName            GIS��ͼ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MAP_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGisMapName
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szGisMapName[IMOS_NAME_LEN]
);


/**
* ָ����֯��Ĭ�ϵ�ͼ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDomainCode            ��֯����
* @param [IN]   szGISMapCode            GIS��ͼ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MAP_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetOrgDefGISMap
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                        szGISMapCode[IMOS_RES_CODE_LEN]
);


/**
* ��ѯ��֯��Ĭ�ϵ�ͼ��Ϣ
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  szDomainCode             ��֯����
* @param [OUT] pstGisMapItem            Ĭ�ϵ�ͼ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MAP_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetOrgDefGISMap
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    OUT GIS_QUERY_ITEM_S            *pstGisMapItem
);

/*--------------------------------------------�ȵ�--------------------------------------*/


/**
* ��GIS��ͼ�ϴ�������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            ��������GIS��ͼ�ı���
* @param [IN]   pstHotZone              ������Ϣ
* @param [OUT]  szHotZoneCode           ��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTZONE_CODE_EXIST
* - #ERR_DAO_GIS_HOTZONE_NAME_EXIST
* - #ERR_DAO_GIS_HOTZONE_LINK_MAP_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateHotZone
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTZONE_S                   *pstHotZone,
    OUT CHAR                            szHotZoneCode[IMOS_RES_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            ��������GIS��ͼ����
* @param [IN]   szHotZoneCode           ��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTZONE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelHotZone
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szHotZoneCode[IMOS_RES_CODE_LEN]
);


/**
* ��GIS��ͼ���޸�����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            ��������GIS��ͼ����
* @param [IN]   szHotZoneCode           ��������
* @param [IN]   pstHotZone              ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTZONE_CODE_NOT_EXIST
* - #ERR_DAO_GIS_HOTZONE_NAME_EXIST
* - #ERR_DAO_GIS_HOTZONE_LINK_MAP_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyHotZone
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szHotZoneCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTZONE_S              *pstHotZone
);


/**
* ��ѯ������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            ��������GIS��ͼ����
* @param [IN]   szHotZoneCode           ��������
* @param [OUT]  pstHotZone              ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTZONE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHotZone
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szHotZoneCode[IMOS_RES_CODE_LEN],
    OUT GIS_HOTZONE_WITH_CODE_S     *pstHotZone
);


/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵ������б� \n
* ����Ϊ��ʱ,����������,��Ĭ��"����������������"
* @param [IN    pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode           ��������GIS��ͼ����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstHotZoneList         �����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHotZoneList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GIS_HOTZONE_WITH_CODE_S     *pstHotZoneList
);

/*--------------------------------------------�ȵ�--------------------------------------*/

/**
* ��GIS��ͼ�ϴ����ȵ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ȵ�����GIS��ͼ����
* @param [IN]   pstHotSpot              �ȵ���Ϣ
* @param [OUT]  szHotSpotCode           �ȵ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTSPOT_CODE_EXIST
* - #ERR_DAO_GIS_HOTSPOT_LINK_DOMAIN_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTSPOT_S                   *pstHotSpot,
    OUT CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ���ȵ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ȵ�����GIS��ͼ����
* @param [IN]   szHotSpotCode           �ȵ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTSPOT_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN]
);



/**
* ��GIS��ͼ���޸��ȵ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ȵ�����GIS��ͼ����
* @param [IN]   szHotSpotCode           �ȵ����
* @param [IN]   pstHotSpot              �ȵ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTSPOT_CODE_NOT_EXIST
* - #ERR_DAO_GIS_HOTSPOT_LINK_DOMAIN_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTSPOT_S                   *pstHotSpot
);


/**
* ��ѯ�ȵ���Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ȵ�����GIS��ͼ����
* @param [IN]   szHotSpotCode           �ȵ����
* @param [OUT]  pstHotSpot              �ȵ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_HOTSPOT_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN],
    OUT GIS_HOTSPOT_WITH_CODE_S         *pstHotSpot
);


/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵ��ȵ��б�
* ����Ϊ��ʱ,�������ȵ�,��Ĭ��"�ȵ������������"
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode           ��������GIS��ͼ����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[�ȵ����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstHotSpotList         �ȵ���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHotSpotList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GIS_HOTSPOT_WITH_CODE_S     *pstHotSpotList
);

/*--------------------------------------------�ı���--------------------------------------*/

/**
* ��GIS��ͼ�ϴ����ı���
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ı�������GIS��ͼ����
* @param [IN]   pstTextBox              �ı�����Ϣ
* @param [OUT]  szTextBoxCode           �ı������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MSGBOX_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateTextBox
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_TEXTBOX_S                   *pstTextBox,
    OUT CHAR                             szTextBoxCode[IMOS_RES_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ���ı���
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ı�������GIS��ͼ����
* @param [IN]   szTextBoxCode           �ı������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MSGBOX_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTextBox
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szTextBoxCode[IMOS_RES_CODE_LEN]
);


/**
* ��GIS��ͼ���޸��ı���
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ı�������GIS��ͼ����
* @param [IN]   szTextBoxCode           �ı������
* @param [IN]   pstTextBox              �ı�����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MSGBOX_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTextBox
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szTextBoxCode[IMOS_RES_CODE_LEN],
    IN  GIS_TEXTBOX_S               *pstTextBox
);


/**
* ��ѯĳ���ı�����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �ı�������GIS��ͼ����
* @param [IN]   szTextBoxCode           �ı������
* @param [OUT]  pstTextBox              �ı�����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_MSGBOX_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTextBox
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szTextBoxCode[IMOS_RES_CODE_LEN],
    OUT GIS_TEXTBOX_WITH_CODE_S     *pstTextBox
);


/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵ��ı����б� \n
* ����Ϊ��ʱ,�������ı���,��Ĭ��"�ı����������"����
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode           �ı�������GIS��ͼ����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[�ı������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTextBoxList         �ı�����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTextBoxList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GIS_TEXTBOX_WITH_CODE_S     *pstTextBoxList
);


/*-------------------------------��Դͼ��(��������澯Դ���澯���)--------------------------------------*/

/**
* ��GIS��ͼ�ϴ��������ͼ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �����ͼ������GIS��ͼ����
* @param [IN]   pstCameraIcon           �����ͼ����Ϣ
* @param [OUT]  szCameraIconCode        �����ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_CAM_ICON_S              *pstCamIcon,
    OUT CHAR                         szCamIconCode[IMOS_RES_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ�������ͼ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szCamIconCode           �����ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szCamIconCode[IMOS_RES_CODE_LEN]
);


/**
* ��GIS��ͼ���޸������ͼ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szCamIconCode           �����ͼ�����
* @param [IN]   pstCamIcon              �����ͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szCamIconCode[IMOS_RES_CODE_LEN],
    IN  GIS_CAM_ICON_S              *pstCamIcon
);


/**
* ��ѯ�����ͼ����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szCamIconCode           �����ͼ�����
* @param [OUT]  pstCamIcon              �����ͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szCamIconCode[IMOS_RES_CODE_LEN],
    OUT GIS_CAM_ICON_WITH_CODE_S    *pstCamIcon
);


/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵ������ͼ���б�
* ����Ϊ��ʱ,�����������ͼ�� ,��Ĭ��"�����ͼ�������������"
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode           �����ͼ������GIS��ͼ����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[ͼ�����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCameraIconList      �����ͼ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamIconList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GIS_CAM_ICON_WITH_CODE_S    *pstCamIconList
);


/**
* ��GIS��ͼ�����Ӹ澯Դͼ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �澯Դͼ������GIS��ͼ����
* @param [IN]   pstAlarmSrcIcon         �澯Դͼ����Ϣ
* @param [OUT]  szAlarmSrcIconCode      �澯Դͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_SRC_ICON_S            *pstAlarmSrcIcon,
    OUT CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ���澯Դͼ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            �澯Դͼ������GIS��ͼ����
* @param [IN]   szAlarmSrcIconCode      �澯Դͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN]
);


/**
* ��GIS��ͼ���޸ĸ澯Դͼ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szAlarmSrcIconCode      �澯Դͼ�����
* @param [IN]   pstAlarmSrcIcon         �澯Դͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_SRC_ICON_S            *pstAlarmSrcIcon
);


/**
* ��ѯĳ���澯Դͼ����Ϣ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode                GIS��ͼ����
* @param [IN]   szAlarmSrcIconCode          �澯Դͼ�����
* @param [OUT]  pstAlarmSrcIcon             �澯Դͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN],
    OUT GIS_ALARM_SRC_ICON_WITH_CODE_S  *pstAlarmSrcIcon
);


/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵĸ澯Դͼ���б�
* ����Ϊ��ʱ,�����и澯Դͼ��,��Ĭ��"�澯Դͼ�������������"
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode           �澯Դͼ������GIS��ͼ����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[ͼ�����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmSrcIconList    �澯Դͼ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGISAlarmSrcIconList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT GIS_ALARM_SRC_ICON_WITH_CODE_S  *pstAlarmSrcIconList
);


/**
* ��GIS��ͼ�ϴ����澯���ͼ��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode                �澯���ͼ������GIS��ͼ����
* @param [IN]   pstAlarmDstIcon             �澯���ͼ����Ϣ
* @param [OUT]  szAlarmDstIconCode          �澯���ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_DST_ICON_S            *pstAlarmDstIcon,
    OUT CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN]
);

/**
* ��GIS��ͼ��ɾ���澯���ͼ��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode                GIS��ͼ����
* @param [IN]   szAlarmDstIconCode          �澯���ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN]
);


/**
* ��GIS��ͼ���޸ĸ澯���ͼ��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode                GIS��ͼ����
* @param [IN]   szAlarmDstIconCode          �澯���ͼ�����
* @param [IN]   pstAlarmDstIcon             �澯���ͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_DST_ICON_S            *pstAlarmDstIcon
);


/**
* ��ѯĳ���澯���ͼ����Ϣ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode                GIS��ͼ����
* @param [IN]   szAlarmDstIconCode          �澯���ͼ�����
* @param [OUT]  pstAlarmDstIcon             �澯���ͼ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN],
    OUT GIS_ALARM_DST_ICON_WITH_CODE_S  *pstAlarmDstIcon
);


/**
* ��ҳ��ѯĳ��GIS��ͼ�ϵĸ澯���ͼ���б� \n
* ����Ϊ��ʱ,�����и澯���ͼ��,��Ĭ��"�澯���ͼ�������������"
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode        �澯���ͼ������GIS��ͼ����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[ͼ�����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmDstIconList �澯���ͼ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGISAlarmDstIconList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT GIS_ALARM_DST_ICON_WITH_CODE_S  *pstAlarmDstIconList
);
/** @} */ /* end of GIS MODULE */
#if 0
#endif
/*******************************************************************************************************
͸��ͨ�� Transparent
********************************************************************************************************/
/** @defgroup groupTP ͸��ͨ������
*   ͸��ͨ������
*   @{
*/
/**
* ����͸��ͨ��,�������ڵ�ָ����ַ�ʹ��ڵ�����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstTransChannelInfo     ͸��ͨ������Ϣ
* @param [OUT]  szTransChannelCode      ͸��ͨ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SERIAL_PORT_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.��ֻ֧�ִ��ڵ�1��IP�ĵ�ַ��͸��ͨ������,
* -     2.����͸��ͨ�����֧��2������.
* -     3.ֻ֧��Э������ΪUDP��ʽ��͸��ͨ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  TRANSPARENT_INFO_S          *pstTransChannelInfo,
    OUT CHAR                        szTransChannelCode[IMOS_RES_CODE_LEN]
);

/**
* ɾ��͸��ͨ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTransChannelCode      ͸��ͨ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szTransChannelCode[IMOS_RES_CODE_LEN]
);


/**
* �޸�͸��ͨ��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szTransChannelCode          ͸��ͨ������
* @param [IN]   pstSDKTransparentChannel    ͸��ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_TL_OPENED
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* - #ERR_DAO_SERIAL_PORT_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.ֻ���޸�͸��ͨ��������ͨ���������ֶ�,
* -     2.ֻ֧��Э������ΪUDP��ʽ��͸��ͨ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN],
    IN  TRANSPARENT_INFO_S              *pstSDKTransparentChannel
);



/**
* ��ҳ��ѯĳ����֯�µ�͸��ͨ���б�  \n
* ����Ϊ��ʱ,��ѯ����͸��ͨ��,��Ĭ�ϰ���"͸��ͨ����������"����.
* @param [IN]   pstUserLogIDInfo         �û���Ϣ��ʶ
* @param [IN]   szDomainCode             ��֯����
* @param [IN]   pstQueryCondition        ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[͸��ͨ������]; #CODE_TYPE[͸��ͨ������])
* @param [IN]   pstQueryPageInfo         �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo           ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKTransparentChannel ͸��ͨ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTransparentChannelList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TRANSPARENT_QUERY_ITEM_S    *pstSDKTransparentChannel
);

/**
* ��ѯ͸��ͨ����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTransChannelCode      ͸��ͨ������
* @param [OUT]  pstSDKUpgTaskInfo       ͸��ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTransparentChannelInfo
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szTransChannelCode[IMOS_RES_CODE_LEN],
    OUT TRANSPARENT_INFO_S               *pstSDKTransparentInfo
);

/**
* ����͸��ͨ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTransChannelCode      ͸��ͨ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* - #ERR_AS_TL_DEVICE_OFFLINE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN]
);
/**
* ͣ��͸��ͨ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTransChannelCode      ͸��ͨ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN]
);

/**
* ͨ��͸��ͨ����������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTransChannelCode      ͸��ͨ������
* @param [IN]   pData                   �����͵�����
* @param [IN]   ulDataLen               �����͵����ݳ���, ��󳤶�Ϊ#IMOS_STRING_LEN_1024
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CHANNEL_NOT_ENABLE
* - #ERR_AS_TL_CLOSED
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendDataByChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN],
    IN  VOID                            *pData,
    IN  ULONG_32                           ulDataLen
);
/** @} */ /* end of TRANSPARENT MANAGEMENT MODULE */
#if 0
#endif
/*******************************************************************************
 ϵͳ����
*******************************************************************************/
/** @defgroup groupLogMg ϵͳ����
*   ϵͳ����ģ�������������,��־����,License����,��Ϣͳ�ƹ������ģ��
*   @{
*/
/**
* @name ��־����
* @{    ��־����
*/
/* Begin added by z00758,2012-11-29 for VVD66805 */
/**����������־��Ϣ����û�������־
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstOperateLogInfo       ������־��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOperLog
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  OPERATE_LOG_S               *pstOperateLogInfo
);
/* End added by z00758,2012-11-29 for VVD66805 */

/**
* ��ҳ��ѯ�û�������־
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstOperateLogInfo      ��־��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �����ͨ�ò�ѯ������pstQueryCondition����ΪNULL
* - 2. ֧�ְ�����Ա���ơ���ѯ��/ֹʱ�䡢IP��ַ���������͡����������ҵ�����͡���������������������ݲ�ѯ,
* -    ��Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:
* -    #USER_NAME_TYPE��#OPER_TIME��#OPER_IP��#OPER_TYPE��#OPER_RESULT��#OPER_SERVICE_TYPE��#OPER_OBJ;
* - 3. ���������������Ĭ�ϰ��ղ���ʱ�併������;
* - 4. ����ʱ��Ĳ�ѯ��#OPER_TIME�����Բ�ѯĳ��ʱ�䣬#QUERY_CONDITION_ITEM_S��#ulLogicFlag����д�����#LOGIC_FLAG_E, ��:
* -    ��ѯ����ʱ��ΪA��B�Ĳ�����־����ô��ѯ��Ϊ2, ��ѯ���б��е�һ(���)����Ԫ���в�ѯ������Ϊ����ʱ�䣬
* -    ��ѯ�����߼���ϵ����Ϊ���ڵ���(��С�ڵ���)����ѯ����ΪA(��B);
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOperLog
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT OPERATE_LOG_S               *pstOperateLogInfo
);

/** @} */ /* end of ��־���� */
#if 0
#endif
/***************************************************************************
����
****************************************************************************/
/**
* @name ����
* @{    ����
*/
/**
* ������Ϣ������������Ϣ����־��Ϣ�����ݿ���Ϣ��, �����ر��ݵ�ִ�н���� \n
* @param [IN]    pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]    ulFlag                  �������ͱ��, ȡֵΪ#BP_BACKUPTYPE_E
* @param [OUT]   pulStatus               ��ǰ����״̬, ȡֵΪ#BACKUP_STATUS_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ÿ�α���ʱ����ɾ��֮ǰ�ı����ļ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BackupData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                           ulFlag,
    OUT ULONG_32                           *pulStatus
);

/**
* ��ѯ������Ϣ, ��ϵͳ���ڷǱ���״̬�����������FTP����Ϣ�� \n
* @param [IN]    pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]    ulFlag                  �������ͱ��, ȡֵΪ#BP_BACKUPTYPE_E
* @param [OUT]   pulStatus               ��ǰ����״̬, ȡֵΪ#BACKUP_STATUS_E
* @param [OUT]   pstFtpInfo              �����ļ���ص�FTP��Ϣ, ��Ϣ�е��ļ�·���������ļ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBackupInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                           ulFlag,
    OUT ULONG_32                           *pulStatus,
    OUT FTP_INFO_S                      *pstFtpInfo
);

/**
* ִ��Ԥ���������ͨ�ýӿ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCmdInfo              ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* - #ERR_AS_INVALID_NTP_IP_ADDRESS
 * -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExecutePredefinedCmd
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SDK_CMD_INFO_S                   *pstCmdInfo
);


/**
* ����/ֹͣ������NTPʱ��ͬ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulSyncFlag              ͬ����ǣ�1��ʼ��2ֹͣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* - #ERR_COMMON_FAIL_CALL_SYSTEM
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessNTPSync
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulSyncFlag
);

/** @} */ /* end of ADDITIONAL MODULE */
#if 0
#endif
/**
* У��License���кŵ���Ч�� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szLicenseSerial     License���к�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CHECK_LICENSE_SERIAL_FAIL
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckLicenseSerial
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szLicenseSerial[IMOS_LICENSE_AUTHORITY_CODE_LENGTH]
);


/**
* ��һϵ��license��������һ��license�ļ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   apcLicenseSerials       ��Ȩ���б�
* @param [IN]   ulLicenseSerialCount    ��Ȩ�����
* @param [IN]   pstClientInfo           �ͻ���Ϣ
* @param [IN]   szContractId            ��ͬ���
* @param [OUT]  pstFtpInfo              FTP������Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_BP_GENERATE_HOST_ID_FILE_FAIL
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MakeHostLicenseFile
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        (*apcLicenseSerials)[IMOS_LICENSE_AUTHORITY_CODE_LENGTH],
    IN  ULONG_32                       ulLicenseSerialCount,
    IN  CLIENTINFO_S                *pstClientInfo,
    IN  CHAR                        szContractId[IMOS_CONTRACT_ID],
    OUT FTP_INFO_S                  *pstFtpInfo
);

/**
* ��ҳ��ȡ��ǰ��Ч��License��Ȩ���б� \n
* Ŀǰֻ֧��һ�β�ѯ�����б���һҳ���������Ϊ��Ȩ���������#IMOS_LICENSE_SERIALS_MAX_NUM
* ���ڷ�ҳƫ�������ٹ�ע��
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  apcSerials          ��Ȩ���б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_BP_LICENSE_FILE_CANT_OPEN
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseSerialsList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CHAR                        (*apcSerials)[IMOS_LICENSE_AUTHORITY_CODE_LENGTH]
);


/**
* ��ҳ��ȡ��ǰ��Ч��License�����Ĺ����Ϣ�б� \n
* Ŀǰֻ֧��һ�β�ѯ�����б���һҳ���������Ϊlicense��Ե�ҵ��������:IMOS_LICENSE_SERVICE_TYPE_NUM
* ���ڷ�ҳƫ�������ٹ�ע��
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstServiceInfoList     ҵ�����б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_BP_LICENSE_FILE_CANT_OPEN
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT LICENSE_AUTHORITYINFO_S     *pstServiceInfoList
);


/**
* ��ȡ��ǰ��Ч��License�����Ĺ����ϸ��Ϣ�б�V2 \n
* Ŀǰֻ֧��һ�β�ѯ�����б���һҳ���������Ϊlicense��Ե�ҵ��������:IMOS_LICENSE_SERVICE_TYPE_NUM
* ���ڷ�ҳƫ�������ٹ�ע��
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       ��ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  LICENSE_AUTHORITYINFO_V2_S     *pstServiceInfoList     ��Ȩ���б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1�������ѯ����ĿС����鵽����������ֻ���ز�ѯ����Ŀ����Ӧ��ҳ��ѯ����е�ʵ�ʲ�ѯ��Ŀ.
*       2����ѯ����е�����Ϊʵ�ʲ�ѯ���ļ�¼����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseInfoList_V2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT LICENSE_AUTHORITYINFO_V2_S   *pstServiceInfoList
);

/**
* ��ȡ��ǰ��Ч��License�ĳ�ʱʱ�� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstExpireDate       ��ʱʱ��
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_BP_LICENSE_FILE_CANT_OPEN
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseExpireTime
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT TIMELIMIT_S                 *pstExpireDate
);
/** @} */ /* end of LICENCE MANAGEMENT MODULE */

#if 0
#endif
/********************************************************************************************************
�������� Edit By sunyifan (06966) Complete
*********************************************************************************************************/
/**
* @name ��������
* @{    ��������
*/
/**
* �����豸����ģʽ \n
* �����Զ�����ģʽ��˵������Ҫ�������κ���������
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   ulUpgMode           ����ģʽ, ȡֵΪ#MM_UPGMODE_E
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_UPG_MODE_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetUpgMode
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                            ulUpgMode
);

/**
* ��ѯ�豸����ģʽ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [OUT]  pulUpgMode         ����ģʽ, ȡֵΪ#MM_UPGMODE_E
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUpgMode
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulUpgMode
);

/**
* ������������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstUpgTaskInfo      ����������Ϣ
* @param [IN]   ulDevNum            �������豸�����д������豸��ʵ������, ���ȡֵΪ#UM_MAX_DEVICENUM_INJOB
* @param [IN]   pstUpgDevInfo       �������豸����
* @param [OUT]  szUpgTaskCode       �����������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_UPGRADE_DEV_NUM_ERR
* - #ERR_DAO_JOB_DEV_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  UPG_TASK_INFO_S             *pstUpgTaskInfo,
    IN  ULONG_32                       ulDevNum,
    IN  UPG_DEV_INFO_S              *pstUpgDevInfo,
    OUT CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�����������Ϣ���������Ҫ�޸������豸�б���ulDevNum��pstUpgDevInfo��Ч \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUpgTaskCode       �����������
* @param [IN]   pstUpgTaskInfo      ����������Ϣ
* @param [IN]   bISModifyDevList    �Ƿ���Ҫ�޸��豸�б�,#BOOL_TRUEΪ�޸�; #BOOL_FALSEΪ���޸�
* @param [IN]   ulDevNum            �������豸�����д������豸��ʵ������, ���ȡֵΪ#UM_MAX_DEVICENUM_INJOB
* @param [IN]   pstUpgDevInfo       �������豸����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_UPGRADE_DEV_NUM_ERR
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note 1.��������״̬Ϊ�ȴ������ʱ, �������޸�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyUpgTaskInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN],
    IN  UPG_TASK_INFO_S             *pstUpgTaskInfo,
    IN  BOOL_T                      bIsModifyDevList,
    IN  ULONG_32                       ulDevNum,
    IN  UPG_DEV_INFO_S              *pstUpgDevInfo
);

/**
* ɾ���������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUpgTaskCode       �����������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note ����ɾ���Ѿ���ɵ�, ����ĺʹ��ڵȴ�״̬������������ִ���е�������ɾ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);

/**
* �������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUpgTaskCode       �����������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note �����������¼���״̬ʱ���������������ʧ�ܣ�
* - ������״̬�������ڹ��𣬻��Ѿ�����ʱ
* - �������������豸���Ѿ�ִ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PauseUpgJob
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);


/**
* �������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUpgTaskCode       �����������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note  �����������¼���״̬ʱ���������������ʧ�ܣ�
* - ���������ڷǹ���״̬���ȴ������У����ڹ���
* - ����������ڣ�����ģ����Զ�ɾ����������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ActiveUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);


/**
* ��ҳ��ѯ������������  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKUpgTaskList      ���������ѯ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note
* - 1. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 2. ֧�ְ������������ơ�״̬�������ߡ��������������/���/�ƶ�ʱ�����򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:
* -    #NAME_TYPE��#JOB_STATUS��#JOB_CREATOR��#JOB_RESULT��#JOB_EXEC_TIME��#JOB_END_TIME��#JOB_ESTB_TIME;
* - 3. ���������������Ĭ�ϰ�����������������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUpgTaskList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT UPG_TASK_QUERY_ITEM_S       *pstSDKUpgTaskList
);


/**
* ��ѯ����������Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUpgTaskCode       �����������
* @param [OUT]  pstUpgTaskInfo      ����������Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_JOB_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN],
    OUT UPG_TASK_INFO_S             *pstUpgTaskInfo
);

/**
* ��ѯָ�����������е������豸�б� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUpgTaskCode       �����������
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstUpgDevInfo       �������豸����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note
* - 1. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 2. ֧�ְ������豸���롢�������򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ������Ϊ#CODE_TYPE��#NAME_TYPE;
* - 3. ���������������Ĭ�ϰ��������豸������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUpgDev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT UPG_DEV_INFO_S              *pstUpgDevInfo
);


/**
* ��ҳ��ѯ��Ҫ�������豸���Լ��豸�����汾����������\n
* @param [IN]   pstUserLogIDInfo   �û���¼��Ϣ
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo   �����ҳ��
* @param [IN]   ULONG �����������ͣ�0:���У�1:��Ҫ������2:����Ҫ������
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstSDKUpgDevInfo   ��Ҫ�������豸�Լ���Ӧ�汾��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note
* - 1. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 2. ֧�ְ������豸���롢�������򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ������Ϊ#CODE_TYPE��#NAME_TYPE;
* - 3. ���������������Ĭ�ϰ��������豸������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDevVersion
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    IN  ULONG_32                                 ulAdviceType,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT UPG_ADVICE_INFO_S           *pstSDKUpgDevInfo
);



/**
* �ϴ���������ʼ,�Ȼ�ȡ�ϴ�ʱ����Ҫ����Ϣ\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szFileName          �ļ�����
* @param [IN]   szDeviceType        �豸����
* @param [OUT]  pstFtpInfo          FTP������Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_COMMON_DIR_FAIL_MKDIR
* - #ERR_COMMON_DIR_FAIL_REMOVE
* - #ERR_COMMON_FILE_FAIL_CHMOD
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUploadUpgPackInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szFileName[IMOS_FILE_PATH_LEN],
    IN  CHAR                    szDeviceType[IMOS_DESC_LEN],
    OUT FTP_INFO_S              *pstFtpInfo
);


/**
* �ϴ����������,֪ͨ�������ϴ��ɹ�\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess          �ɹ����ı�ʶ, #BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @param [IN]   szFilePath          �ļ�·��
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_COMMON_FILE_CANT_OPEN
* - #ERR_COMMON_DIR_FAIL_OPEN
* - #ERR_COMMON_FAIL_STAT
* - #ERR_COMMON_FILE_FAIL_CHMOD
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_NotifyUploadUpgPackResult
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN BOOL_T                    bIsSuccess,
    IN CHAR                      szFilePath[IMOS_FILE_PATH_LEN]
);


/**
* �ϴ��������ױ�ʼ, �Ȼ�ȡ�ϴ�ʱ����Ҫ����Ϣ\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szFileName          �ļ���
* @param [OUT]  pstFtpInfo          FTP������Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_COMMON_DIR_FAIL_REMOVE
* - #ERR_COMMON_DIR_FAIL_MKDIR
* - #ERR_COMMON_FILE_FAIL_CHMOD
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUploadUpgMatchListInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szFileName[IMOS_FILE_PATH_LEN],
    OUT FTP_INFO_S              *pstFtpInfo
);

/**
* �ϴ��������ױ����, ֪ͨ�������ϴ��ɹ�\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess          �ɹ����ı�־, #BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_MATCHTBL_OPEN_FAIL
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_NotifyUploadUpgMatchListResult
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN BOOL_T                    bIsSuccess
);
/** @} */ /* end of UPGRADE MANAGEMENT MODULE */

#if 0
#endif
/*******************************************************************************
��Ϣͳ��
*******************************************************************************/
/**
* @name ��Ϣͳ�ƹ���
* @{    ��Ϣͳ�ƹ���
*/
/**
* ��ǰҵ����Ϣ����ͳ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstSrvStatInfo          ͳ��ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySrvStat
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT SRV_STAT_INFO_S         *pstSrvStatInfo
);


/** @} */  /* end of ��Ϣͳ�ƹ���ģ�� */


/**
* ��ѯ�豸����ͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode               ��֯����
* @param [IN]       ulDevType               �豸����,ȡֵΪ#IMOS_TYPE_DM, #IMOS_TYPE_MS , #IMOS_TYPE_TS,#IMOS_TYPE_VX500, #IMOS_TYPE_MONITOR, #IMOS_TYPE_EC, #IMOS_TYPE_DC, #IMOS_TYPE_CAMERA, #IMOS_TYPE_ECR, #IMOS_TYPE_DEV_ALL����Ϊ#IMOS_TYPE_DEV_ALL��Ϊͳ�����е��豸����
* @param [IN]       ulDevBelAttr            �豸�������ԣ�ȡֵΪ#IMOS_DEV_BELONG_ATTR����ȡ#IMOS_DEV_BELONG_ALLʱ��ʾ���ֱ�������ͳ�����е��豸
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN][OUT]  pulArraySize            �豸״̬ͳ�������С, ����Ҫͳ�����е��豸���ͣ��������СӦ�ô��ڵ���#IMOS_DEVICE_TYPE_NUM
* @param [OUT]      pstDevStatistic         �豸״̬ͳ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevStatusStatistic
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN    ULONG_32                          ulDevType,
    IN    ULONG_32                          ulDevBelAttr,
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    INOUT ULONG_32                          *pulArraySize,
    OUT   DEV_STATUS_STATISTIC_S         *pstDevStatistic
 );


/**
* �����豸״̬��ѯ�豸��Ϣ�б�
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   ulDevStatus,                �豸״̬��ȡֵΪ#IMOS_DEV_FAULT_STATUS_E, ��ȡֵΪ#IMOS_DEV_FAULT_STATUS_ALLʱ��ʾ����״̬����ѯ���е��豸
* @param [IN]   ulDevType                   �豸���ͣ�ȡֵΪ#IMOS_TYPE_DM, #IMOS_TYPE_MS,#IMOS_TYPE_TS, #IMOS_TYPE_VX500, #IMOS_TYPE_MONITOR, #IMOS_TYPE_EC, #IMOS_TYPE_DC, #IMOS_TYPE_CAMERA, #IMOS_TYPE_ECR. ��֧�ֲ�ѯ����(ֵΪ#IMOS_TYPE_DEV_ALL)���豸���͵��豸��Ϣ�б�
* @param [IN]   ulDevBelAttr                �豸�������ԣ�ȡֵ��Χ��#IMOS_DEV_BELONG_ATTR, ֵΪ#IMOS_DEV_BELONG_ALL��ʾ���ֱ������򣬲�ѯ���е��豸
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ���������޲�ѯ����, ������ΪNULL
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDevInfoArray             �豸������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevListByFaultStatus
(
    IN USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN CHAR                           szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN ULONG_32                          ulDevStatus,
    IN ULONG_32                          ulDevType,
    IN ULONG_32                          ulDevBelAttr,
    IN COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S               *pstRspPageInfo,
    OUT DEV_BASIC_INFO_S              *pstDevInfoArray
 );
#if 0
#endif
/*******************************************************************************
����ǽ
*******************************************************************************/
/** @defgroup groupTvWall ����ǽ
*   ��������ǽ����ɾ�Ĳ�
*   @{
*/
/**
* ���ӵ���ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN][OUT]  pstTVWallInfo      ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - #ERR_MM_PARENT_RES_NOT_EXIST
* -      ���ز�������룬���������ļ�
* @note
* - 1��������ǽ��ϢpstTVWallInfo�е���ǽ�������ʱ��дΪ�գ���ƽ̨����ɹ��󷵻ر��룬����д������д�ı������;
* - 2��һ������ǽ����������������ĿΪ#IMOS_MONITOR_MAXNUM_PER_WALL,����������������Ϊ��;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWall
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    INOUT   TV_WALL_INFO_S          *pstTVWallInfo
);

/**
* ɾ������ǽ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTVWallCode        ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - #ERR_DAO_RES_AGG_NOT_EXIST
* -      ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWall
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTVWallCode[IMOS_CODE_LEN]
);

/**
* �޸ĵ���ǽ��Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTVWallInfo      ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - #ERR_DAO_RES_AGG_NOT_EXIST
* -      ���ز�������룬���������ļ�
* @note
* - 1������ǽ��ϢpstTVWallInfo�е���ǽ���벻�����޸�,�����ܵ����޸�ʧ�ܻ��޸Ĵ���;
* - 2��һ������ǽ����������������ĿΪIMOS_MONITOR_MAXNUM_PER_WALL,����������������Ϊ��;
* - 3�������ǽ����Ӽ����������Բ��øýӿ�ʵ�ֵ���ǽ��Ϣ�ĸ���;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTVWall
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TV_WALL_INFO_S          *pstTVWallInfo
);

/**
* ��ѯ����ǽ��ϸ��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTVWallCode        ����ǽ����
* @param [OUT]  pstTVWallInfo       ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - #ERR_DAO_RES_AGG_NOT_EXIST
* -      ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTVWallCode[IMOS_CODE_LEN],
    OUT TV_WALL_INFO_S          *pstTVWallInfo
);

/**
* ��ҳ��ѯĳ����֯�µĵ���ǽ�б� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����ǽ����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTVWallList       ����ǽ��Ϣ�б�
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* -      ���ز�������룬���������ļ�
* @note
* - 1��pstTVWallList��ҳ��ÿҳ����ĳ��ȱ�����ڻ����pstQueryPageInfo�ڵ�ulPageRowNum�������Խ��;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TV_WALL_QUERY_ITEM_S        *pstTVWallList
);
/** @} */ /* end of TV Wall */
#if 0
#endif

/**
* SDK����֪ͨ��Ϣ�ӿ�
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode                   ͨ���豸ID
* @param [IN]   ulBufferLen                 ��Ϣ���ȣ���󳤶�Ϊ:#IMOS_MAX_NOTIFY_LEN
* @param [IN]   pcBuffer                    ��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �˽ӿ�Ŀǰֻ���Ÿ��İ���Ŀʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Notify
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                   ulBufferLen,
    IN  CHAR                    *pcBuffer
);

#if 0
#endif

/**
* ���õ������豸��ѯ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstPollCfg                  ��ѯ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetThdDevPollCfg
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    THD_DEV_POLL_CFG_S        *pstPollCfg
);

/**
* ��ȡ�������豸��ѯ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [INOUT]   pstPollCfg                  ��ѯ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetThdDevPollCfg
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    INOUT THD_DEV_POLL_CFG_S        *pstPollCfg
);

#if 0
#endif

/**
* ���ͨ���豸
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstGeneralDevInfo           ͨ���豸��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.ͨ���豸���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGeneralDev
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    GENERAL_DEV_INFO_S        *pstGeneralDevInfo
);

/**
* �޸�ͨ���豸
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstGeneralDevInfo           ͨ���豸��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGeneralDev
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    GENERAL_DEV_INFO_S        *pstGeneralDevInfo
);

/**
* ɾ��ͨ���豸
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szGeneralDevCode            ͨ���豸ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGeneralDev
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    CHAR                      szGeneralDevCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯĳ����֯�µ�ͨ���豸�б�  \n
* ֧�ְ�����ģ����ѯ��pstName����Ϊ�գ���ʾ��������Ч���������ֽ���ģ����ѯ
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   �����
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����]; #CODE_TYPE[����]; #PHY_DEV_IP[IP��ַ])
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  GENERAL_DEV_INFO_S          ͨ���豸��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGeneralDevList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT GENERAL_DEV_INFO_S              *pstGeneralDevList
);

/**
* ��ѯĳ��ͨ�õ���Ϣ
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szGeneralDevCode            ͨ���豸����
* @param [OUT]  pstGeneralDevInfo           ͨ���豸��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGeneralInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGeneralDevCode[IMOS_DEVICE_CODE_LEN],
    OUT GENERAL_DEV_INFO_S              *pstGeneralDevInfo
);

/**
* ��ѯ������NTPʱ��ͬ����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]  pbNTPSyncStatus         ������NTPʱ��ͬ����Ϣ���  pbNTPSyncStatusΪ#BOOL_FALSE��ʾֹͣͬ����Ϊ#BOOL_TRUE��ʾ����ͬ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNTPSyncStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT BOOL_T                          *pbNTPSyncStatus
);

#if 0
#endif

/**
* ���� - ���V2������Ȩǩ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstExDomain            ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddExDomainV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   EX_DOMAIN_V2_S             *pstExDomain
);


/**
* ���� - �޸�V2�����벻���޸ģ�����Ҫ����
* @param [IN]  pstUserLogIDInfo          �û���Ϣ��ʶ
* @param [IN]  pstExDomain               ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyExDomainV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   EX_DOMAIN_V2_S             *pstExDomain
);

/**
* ���� - ��ѯ��ĳ����V2
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szExDomainCode          �������
* @param [OUT]  pstExDomain             ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT  EX_DOMAIN_V2_S             *pstExDomain
);

/**
* ���� - ��ѯ���б�V2 \n
* @param [IN]   pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  pstExDomainList        �����ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 2. ֧�ְ�������롢���ơ����͡�IP���˿ڡ���������������鲥���ԡ�������־���򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:
* -   #CODE_TYPE��#NAME_TYPE��#EXT_DOMAIN_TPYE��#EXT_DOMAIN_IP��#EXT_DOMAIN_TRUNK_NUM��#EXT_DOMAIN_TRUNK_NUM��
* -   #EXT_DOMAIN_MULTICAST��#EXT_DOMAIN_SESSION;
* - 3. ���������������Ĭ�ϰ�������������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT EX_DOMAIN_V2_S              *pstExDomainList
);

/**
* �������������V2�����Թ���Ҳ����ȡ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareCamNum           ������ĸ���
* @param [IN]   pstShareCamList         ����/ȡ��������б�

* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareCameraV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                   ulShareFlag,
    IN  ULONG_32                   ulShareCamNum,
    IN  SHARE_CAMERA_BASE_V2_S  *pstShareCamList
);

/**
* ��ѯ�����������б�V2
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szExDomainCode      �������
* @param [IN]   ulQueryFlag         ��ѯ���
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ���ط�ҳ��Ϣ
* @param [OUT]  pstShareCamList     ��ѯ����������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulQueryFlag��Ϊ��ѯ���:0��ʾ�鱾�����������������1��ʾ�������������������
* - 2. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 3. ֧�ְ���������롢�������򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:#CODE_TYPE��#NAME_TYPE;
* - 4. ���������������Ĭ�ϰ��������������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareCameraV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_CAM_INFO_V2_S         *pstShareCamList
);

/**
* ɾ����������Դ
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   ulResType                   ��Դ���ͣ�ȡֵ#IMOS_TYPE_E
* @param [IN]   szResCode                   ��ɾ������Դ����
* @param [IN]   szExdomainCode              �������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResSharedByExdomain
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResType,
    IN  CHAR                            szResCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szExdomainCode[IMOS_DOMAIN_CODE_LEN]
);

/***************************************************************************
������֯����
****************************************************************************/
/**
* @name ��֯�������
* @{    ��֯�������
*/
/**
* ��֯���������Թ���Ҳ����ȡ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareAll              ����ʽ: 0Ϊ��������֯, 1Ϊ��ͬ���е�������Դһ������
* @param [IN]   ulShareOrgNum           ��֯�ĸ���
* @param [IN]   pstShareOrgList         ����/ȡ����֯�б�

* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareOrg
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                   ulShareFlag,
    IN  ULONG_32                   ulShareAll,
    IN  ULONG_32                   ulShareOrgNum,
    IN  SHARE_ORG_BASE_S        *pstShareOrgList
);

/**
* ��ѯ��֯���������֯�ڵ㹲����Ϣ�б� \n
* �����ѯ����ʱ,������,��Ĭ������(��֯��������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   szExDomainCode     �������
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[��֯����],#IS_QUERY_SUB[�Ƿ������֯,=1��,=0��])
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstOrgShareList    ��֯�ڵ㹲����Ϣ�б�ָ��
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgShareInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SHARE_ORG_INFO_S                *pstOrgShareList
);


/**
* ��ѯ���������/���������֯�б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulQueryFlag             ��ѯ��ǣ�0��ʾ�鱾������������֯��1��ʾ����������������֯
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstShareOrgList         ��ѯ������֯�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ְ�"��֯����"ģ����ѯ������:#NAME_TYPE;
* - 2. ֧�ְ�"��֯����"ģ����ѯ������:#CODE_TYPE;
* - 3. ���������������Ĭ�ϰ�����֯������������;
* - 4. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 5. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareOrgList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_ORG_INFO_S            *pstShareOrgList
);


/***************************************************************************
����澯Դ����
****************************************************************************/
/**
* @name �澯Դ�������
* @{    �澯Դ�������
*/
/**
* �澯Դ���������Թ���Ҳ����ȡ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareAlarmSrcNum      �澯Դ�ĸ���
* @param [IN]   pstShareAlarmSrcList    ����/ȡ���澯Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                   ulShareFlag,
    IN  ULONG_32                   ulShareAlarmSrcNum,
    IN  SHARE_ALARMSRC_BASE_S   *pstShareAlarmSrcList
);

/**
* ��ѯ��֯����ĸ澯Դ������Ϣ�б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(�澯Դ��������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   szExDomainCode     �������
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL)
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstAlmSrcShareList �澯Դ������Ϣ�б�ָ��
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* - 1.����ͨ�ò�ѯ����:
*     #NAME_TYPE[�澯Դ����]
*     #IS_QUERY_SHARED[��ѯ�ѹ����δ����] = 0 δ����; = 1 �ѹ���
*   2.�����ѯ������������й�����ˣ�����а�����֯����������������ѯ�����ĸ澯Դ(δ���� + �ѹ���)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmSrcShareInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SHARE_ALARMSRC_INFO_S           *pstAlmSrcShareList
);

/**
* ��ѯ���������/������ĸ澯Դ�б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulQueryFlag             ��ѯ��ǣ�0��ʾ�鱾���������ĸ澯Դ��1��ʾ�������������ĸ澯Դ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstShareAlmSrcList      ��ѯ�����澯Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�"�澯Դ����"ģ����ѯ������:#NAME_TYPE;
* - 2.֧�ְ�"�澯Դ����"ģ����ѯ������:#CODE_TYPE;
* - 3.���������������Ĭ�ϰ��ո澯Դ������������;
* - 4.����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_ALARMSRC_INFO_S       *pstShareAlmSrcList
);

/* Begin added by z00758,2012-11-21 for VVD75068 */
/**
* ��ѯ���������ĸ澯����б�V2
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulQueryFlag             ��ѯ��ǣ�0��ʾ�鱾���������ĸ澯�����1��ʾ�������������ĸ澯���
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstShareAlmOutList      ��ѯ�����ĸ澯����б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ְ�"�澯�������"ģ����ѯ������:#NAME_TYPE;
* - 2. ֧�ְ�"�澯�������"ģ����ѯ������:#CODE_TYPE;
* - 3. ���������������Ĭ�ϰ��ո澯���������������;
* - 4. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 5. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareAlarmOutV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_ALARMOUT_INFO_S       *pstShareAlmOutList
);
/* End added by z00758,2012-11-21 for VVD75068 */

/**
* ��ѯ����Ĺ�����֯��������б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ������֯����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstResList              ��ѯ������֯��������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainOrgAndCamList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ORG_RES_QUERY_ITEM_S            *pstResList
);


/**
* ����������Դ��ѯ����
* @param [IN]   *pstUserLogIDInfo                    �û���Ϣ
* @param [IN]   ulExdomainResQueryPolicy             ������Դ��ѯ���ԣ�ȡֵ#EXDOMAIN_RES_QUERY_POLICY_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetExdomainResQueryPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                       ulExdomainResQueryPolicy
);

/**
* ��ѯ������Դ��ѯ����
* @param [IN]   *pstUserLogIDInfo       �û���Ϣ
* @param [OUT]  *pulExdomainResQueryPolicy          ������Դ��ѯ���ԣ�ȡֵ#EXDOMAIN_RES_QUERY_POLICY_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QryExdomainResQueryPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  ULONG_32                      *pulExdomainResQueryPolicy
);


/***************************************************************************
����澯�������
****************************************************************************/
/**
* @name �澯����������
* @{    �澯����������
*/
/**
* �澯������������Թ���Ҳ����ȡ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareAlarmOutNum      �澯����ĸ���
* @param [IN]   pstShareAlarmOutList    ����/ȡ���澯����б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareAlarmOut
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulShareFlag,
    IN  ULONG_32                   ulShareAlarmOutNum,
    IN  SHARE_ALARMOUT_BASE_S   *pstShareAlarmOutList
);

/**
* ��ѯ��֯����ĸ澯���������Ϣ�б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(�澯�����������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   szExDomainCode     �������
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[�澯�������])
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstAlmOutShareList �澯���������Ϣ�б�ָ��
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmOutShareInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SHARE_ALARMOUT_INFO_S           *pstAlmOutShareList
);

/**
* ��ѯ���������ĸ澯����б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulQueryFlag             ��ѯ��ǣ�0��ʾ�鱾���������ĸ澯�����1��ʾ�������������ĸ澯���
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstShareAlmOutList      ��ѯ�����澯����б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareAlarmOut
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulQueryFlag,
    IN  QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT SHARE_ALARMOUT_INFO_S   *pstShareAlmOutList
);

/**
* ���ø澯���
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szAlarmOutResCode       �澯�����Դ����
* @param [IN]   ulActionType            ���ö������ͣ��μ�#ALARM_OUTPUT_SET_TYPE_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAlarmOut
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szAlarmOutResCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulActionType
);

/***************************************************************************
����GIS��ͼ����
****************************************************************************/
/**
* @name GIS��ͼ�������
* @{    GIS��ͼ�������
*/
/**
* ��ͼ���������Թ���Ҳ����ȡ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareMapNum           ��ͼ�ĸ���
* @param [IN]   pstShareMapList         ����/ȡ����ͼ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����һ�ι���Ҫ����8����ͼ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareMap
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulShareFlag,
    IN  ULONG_32                   ulShareMapNum,
    IN  SHARE_MAP_BASE_S        *pstShareMapList
);

/**
* ��ѯ��֯����ĵ�ͼ������Ϣ�б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(��ͼ��������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN    szExDomainCode     �������
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL)
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstMapShareList    ��ͼ������Ϣ�б�ָ��
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����ͨ�ò�ѯ����:
*     #NAME_TYPE[��ͼ����]
*     #IS_QUERY_SHARED[��ѯ�ѹ����δ����] = 0 δ����; = 1 �ѹ���
* - 2. �����ѯ������������й�����ˣ�����а�����֯����������������ѯ�����ĵ�ͼ(δ���� + �ѹ���)
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMapShareInfoList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SHARE_MAP_INFO_S                *pstMapShareList
);

/**
* ��ѯ���������/������ĵ�ͼ�б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulQueryFlag             ��ѯ��ǣ�0��ʾ�鱾���������ĵ�ͼ��1��ʾ�������������ĵ�ͼ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstShareMapList         ��ѯ������ͼ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ְ�"��ͼ����"ģ����ѯ������:#NAME_TYPE;
* - 2. ֧�ְ�"��ͼ����"ģ����ѯ������:#CODE_TYPE;
* - 3. ���������������Ĭ�ϰ��յ�ͼ������������;
* - 4. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 5. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareMapList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_MAP_INFO_S            *pstShareMapList
);

/***************************************************************************
��Դ�����ϵ��ѯ
****************************************************************************/
/**
* ��ѯĳ����Դ�ϴ��ڵĹ����ϵ \n
* @param [IN]   pstUserLoginIDInfo       �û���¼ID��Ϣ
* @param [IN]   pstResQueryInfo          ��Դ��ѯ������Ϣ(���������)
* @param [IN]   pstQueryCondition        ͨ�ò�ѯ����(����ΪNULL)
* @param [IN]   pstQueryPageInfo         �����ҳ��Ϣ
* @param [OUT]  pstResShareInRecord      ��Դ�������¼(IN)
* @param [OUT]  pstRspPageInfo           ���ط�ҳ��Ϣ
* @param [OUT]  pstResShareOutRecList    ��Դ�����¼�б�(OUT)
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ���Ǳ�����Դ,��Դ�������¼(IN)����д�������ƺͱ���
* - 2. pstQueryCondition��#QUERY_CONDITION_ITEM_S�Ĳ�ѯ������ö��#QUERY_TYPE_E,
*       Ŀǰ֧�ֵ�ֻ��#CODE_TYPE��#NAME_TYPE��#EXT_DOMAIN_TPYE
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResShareRelation
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLoginIDInfo,
    IN  QUERY_RES_REQUEST_INFO_S            *pstResQueryInfo,
    IN  COMMON_QUERY_CONDITION_S            *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                   *pstQueryPageInfo,
    OUT RES_SHARE_IN_RECORD_INFO_S          *pstResShareInRecord,
    OUT RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT RES_SHARE_OUT_RECORD_INFO_S         *pstResShareOutRecList
);

/**
* ���ڹ�����
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             �����ǣ�1��ʾ����0��ʾȡ������
* @param [IN]   ulTollgateNum        ����Ŀ�����Ŀ
* @param [IN]   pstTollgateList        �����б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareTollgate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                ulShareFlag,
    IN  ULONG_32                ulTollgateNum,
    IN  SHARE_TOLLGATE_INFO_S   *pstTollgateList
);

/**
* ��ѯ����Ŀ����б�
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulQueryFlag             ��ѯ���
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstTollgateList         ��ѯ���������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulQueryFlag��Ϊ��ѯ���:0��ʾ�鱾�����������������1��ʾ�������������������
* - 2. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 3. ֧�ְ���������롢�������򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:#CODE_TYPE��#NAME_TYPE;
* - 4. ���������������Ĭ�ϰ��������������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareTollgateList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                    ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_TOLLGATE_INFO_S       *pstTollgateList
);


/**
* ��ѯ��֯����Ŀ��ڹ�����Ϣ�б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(������������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   szExDomainCode     �������
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL)
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstTgShareItemList    ���ڹ�����Ϣ�б�ָ��
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.����ͨ�ò�ѯ����:
*     #NAME_TYPE[��������]
*     #IS_QUERY_SHARED[��ѯ�ѹ����δ����] = 0 δ����; = 1 �ѹ���
*   2.�����ѯ������������й�����ˣ�����а�����֯����������������ѯ�����Ŀ���(δ���� + �ѹ���)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateShareInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TOLLGATE_SHARE_QUERY_ITEM_S     *pstTgShareItemList
);


#if 0
#endif

/*************************************************************************************
��Դ�����ã��������ӣ��޸ģ�ɾ������ѯ����ѯ�б�
***************************************************************************************/
/**
* ������Դ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   szGroupName             ��Դ������
* @param [IN]   ulGroupResType          ��Դ�����ͣ�ö��Ϊ#IMOS_TYPE_E�����������Ϊ#IMOS_TYPE_CAMERA_GROUP
* @param [IN]   ulResNum                ������Դ��Ŀ
* @param [IN]   pstResGroupUnit         ������Դ��Ԫ��Ϣ
* @param [OUT]  szResGroupCode          ��Դ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻ֧���������/�������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddResGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                        szGroupName[IMOS_NAME_LEN],
    IN  ULONG_32                       ulGroupResType,
    IN  ULONG_32                       ulResNum,
    IN  RESOURCE_GROUP_UNIT_S       *pstResGroupUnit,
    OUT CHAR                        szResGroupCode[IMOS_RES_CODE_LEN]
);


/**
* �޸���Դ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   szResGroupCode          ��Դ�����
* @param [IN]   szGroupName             ��Դ������
* @param [IN]   ulGroupResType          ��Դ�����ͣ�ö��Ϊ#IMOS_TYPE_E�����������Ϊ#IMOS_TYPE_CAMERA_GROUP
* @param [IN]   ulResNum                ������Դ��Ŀ
* @param [IN]   pstResGroupUnit         ������Դ��Ԫ��Ϣ
* @param [IN]   bIsDeleteOldData        �Ƿ�ɾ����ǰ��Ԫ��
* @param [IN]   szExtInfo               ��չ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻ֧���������/�������������
* - ����Ϊ"ͼ��ƴ��"ʱ,��չ��ϢΪ"�궨����Ϣ"
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyResGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                        szResGroupCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szGroupName[IMOS_NAME_LEN],
    IN  ULONG_32                       ulGroupResType,
    IN  ULONG_32                       ulResNum,
    IN  RESOURCE_GROUP_UNIT_S       *pstResGroupUnit,
    IN  BOOL_T                      bIsDeleteOldData,
    IN  CHAR                        szExtInfo[IMOS_RES_GROUP_EXT_LEN]
);

/**
* ɾ����Դ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulGroupResType          ��Դ�����ͣ�ö��Ϊ#IMOS_TYPE_E�����������Ϊ#IMOS_TYPE_CAMERA_GROUP
* @param [IN]   szResGroupCode          ��Դ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulGroupResType,
    IN  CHAR                            szResGroupCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯ��Դ����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szResGroupCode          ��Դ�����
* @param [IN]   ulGroupResType          ��Դ������
* @param [IN]   ulCameraOperateType     �������ͣ�ȡֵΪ#CAMERA_GROUP_OPERATE_TYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��Դ����])
* @param [IN]   pstQueryPageInfo        ��ѯ��ҳ��Ϣ
* @param [OUT]  szOrgCode               ��֯����
* @param [OUT]  szGroupName             ��Դ������
* @param [OUT]  szExtInfo               ��չ��Ϣ
* @param [OUT]  pstRspPageInfo          ��ѯ���ط�ҳ��Ϣ
* @param [OUT]  pstResGroupUnit         ������Դ��Ԫ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����Ϊ"ͼ��ƴ��"ʱ,��չ��ϢΪ"�궨����Ϣ",����Ϊ"�������"ʱ����Դ�鵥Ԫ��Ϣ��������¼��״̬
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResGroupCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulGroupResType,
    IN  ULONG_32                           ulCameraOperateType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT CHAR                            szOrgCode[IMOS_CODE_LEN],
    OUT CHAR                            szGroupName[IMOS_NAME_LEN],
    OUT CHAR                            szExtInfo[IMOS_RES_GROUP_EXT_LEN],
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT RESOURCE_GROUP_UNIT_S           *pstResGroupUnit
);


/**
* ��ҳ��ѯĳ����֯�µ���Դ���б�  \n
* ����Ϊ��ʱ,��ѯ��֯��������Դ���б�,��Ĭ�ϰ���"��Դ����������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   ulGroupResType          ��Դ������
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��Դ������])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResGroupList         ��Դ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResGroupList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulGroupResType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT RESOURCE_GROUP_INFO_S       *pstResGroupList
);


#if 0
#endif

/*************************************************************************************
�������ã��������ӣ��޸ģ�ɾ������ѯ����ѯ�б�
***************************************************************************************/
#if 0/* ��ʱֻ�ṩ��ѯ���� */
/**
* ���Ӳ���
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [INOUT]  pstLayoutInfo           ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_AddLayout
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   LAYOUT_INFO_S               *pstLayoutInfo
);

/**
* �޸Ĳ���
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstLayoutInfo           ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_ModifyLayout
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   LAYOUT_INFO_S               *pstLayoutInfo
);


/**
* ɾ������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szLayoutCode            ���ֱ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_DelLayout
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szLayoutCode[IMOS_RES_CODE_LEN]
);
#endif

/**
* ��ѯ������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szLayoutCode            ���ֱ���
* @param [OUT]  pstLayoutInfo           ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLayout
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szLayoutCode[IMOS_RES_CODE_LEN],
    OUT LAYOUT_INFO_S                   *pstLayoutInfo
);

/**
* ��ҳ��ѯ�����б�  \n
* ����Ϊ��ʱ,��ѯ���в����б�,��Ĭ�ϰ���"������������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* - ����NULL
* - ��������:#NAME_TYPE(��������),#LAYOUT_TYPE(�������ͣ�ȡֵ#LAYOUT_TYPE_E)
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstLayoutList           �����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLayoutList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT LAYOUT_INFO_QUERY_ITEM_S    *pstLayoutList
);

#if 0
#endif
/**
* ��������ʾ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szOrgCode               ��֯����
* @param [INOUT]  pstSalvoInfo            ����ʾ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����ʾ��Ϣ������ʾ�������Ϊ��;����ε�����ʾ����Ϊ��, ��Я�����ڲ����ɵ�����ʾ����)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSalvoV2
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    INOUT   SALVO_INFO_V2_S             *pstSalvoInfo
);

/**
* �޸�����ʾ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstSalvoInfo            ����ʾ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySalvoV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN   SALVO_INFO_V2_S            *pstSalvoInfo
);

/**
* ��ѯ����ʾ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSalvoCode             ����ʾ����
* @param [IN]   ulMaxUnitNum            ����ѯ��Ԫ��Ŀ
* @param [OUT]  pstSalvoInfo            ����ʾ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySalvoV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSalvoCode[IMOS_CODE_LEN],
    IN  ULONG_32                        ulMaxUnitNum,
    OUT SALVO_INFO_V2_S                 *pstSalvoInfo
);

#if 0
#endif

/**
* ����������ԴV2
* @param [IN]  pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN]  szOrgCode        ��֯����
* @param [IN]  pstSwitchInfo    ������Դ��Ϣ
* @param [OUT] szSwitchResCode  ������Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARDTOUR_TIMESLOT_EXCEEDED
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSwitchResourceV2
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szOrgCode[IMOS_CODE_LEN],
    IN  SWITCH_RESOURE_V2_S  *pstSwitchInfo,
    OUT CHAR                  szSwitchResCode[IMOS_CODE_LEN]
);

/**
* �޸�������ԴV2
* @param [IN] pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] szSwitchResCode  ������Դ����
* @param [IN] pstSwitchInfo    ������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARDTOUR_TIMESLOT_EXCEEDED
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySwitchResourceV2
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szSwitchResCode[IMOS_CODE_LEN],
    IN  SWITCH_RESOURE_V2_S  *pstSwitchInfo
);

/**
* ��ѯ������ԴV2
* @param [IN]  pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN]  szSwitchResCode  ������Դ����
* @param [OUT] pstSwitchInfo    ������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchResourceV2
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szSwitchResCode[IMOS_CODE_LEN],
    OUT SWITCH_RESOURE_V2_S  *pstSwitchInfo
);

#if 0
#endif

/* Begin Added by dengshuhua00673, 2012-11-28 of �Զ�������Ѳ */
/**
* ����ͨ��������Դ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstSwitchInfo           ͨ��������Դ��Ϣ
* @param [OUT]  szSwitchResCode         ͨ��������Դ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰֻ֧������Ѳ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommonSwitchResV2
(
    IN  USER_LOGIN_ID_INFO_S	    *pstUserLogIDInfo,
    IN  CHAR	                    szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_SWITCH_RESOURCE_V2_S	*pstSwitchInfo,
    OUT CHAR	                    szSwitchResCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�ͨ��������Դ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSwitchResCode         ͨ��������Դ����
* @param [IN]   pstSwitchInfo           ͨ��������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommonSwitchResV2
(
    IN  USER_LOGIN_ID_INFO_S	    *pstUserLogIDInfo,
    IN  CHAR	                    szSwitchResCode[IMOS_RES_CODE_LEN],
    IN  COMMON_SWITCH_RESOURCE_V2_S	*pstSwitchInfo
);

/**
* ��ѯͨ��������Դ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulSwitchType            �������ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E
* @param [IN]   szSwitchResCode         ͨ��������Դ����
* @param [OUT]  pstSwitchInfo           ͨ��������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchResV2
(
    IN  USER_LOGIN_ID_INFO_S	    *pstUserLogIDInfo,
    IN  ULONG_32	                    ulSwitchType,
    IN  CHAR	                    szSwitchResCode[IMOS_RES_CODE_LEN],
    OUT COMMON_SWITCH_RESOURCE_V2_S	*pstSwitchInfo
);

/**
* ��ҳ��ѯĳ����֯�µ�ͨ��������Դ�б�V2  \n
* ����Ϊ��ʱ,��ѯ��֯������ͨ��������Դ�б�,��Ĭ�ϰ���"������Դ��������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   ulSwitchType            �������ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* - ����NULL
* - ��������:#NAME_TYPE(������Դ����),#RES_SUB_TYPE(���������ͣ�������Ѳȡֵ#GROUP_SWITCH_TYPE_E)
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSwitchResList        ͨ��������Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchResListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulSwitchType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SWITCH_RES_QUERY_ITEM_V2_S  *pstSwitchResList
);
/* End Added by dengshuhua00673, 2012-11-28 of �Զ�������Ѳ */

/* Begin Added by gKF0090, 2012-12-27 of ��ѯ���������Ѳ��Ϣ */
/**
* ��ѯ������ϵ�����Ѳ��Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szUACode                ���������
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstGroupSwitchResList   ����Ѳ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGroupSwitchResListUnderUA
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szUACode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GROUP_SWITCH_RES_LIST_S     *pstGroupSwitchResList
);

/* End Added by gKF0090, 2012-12-27 of ��ѯ���������Ѳ��Ϣ */

/*************************************************************************************
ͨ�����мƻ����ã��������ӣ��޸ģ�ɾ������ѯ����ѯ�б�
***************************************************************************************/
/**
* ����ͨ�����мƻ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSwitchPlanInfo       ͨ�����мƻ���Ϣ
* @param [OUT]  szSwitchPlanCode        ͨ�����мƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_SWITCH_PLAN_INFO_S       *pstSwitchPlanInfo,
    OUT CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);


/**
* �޸�ͨ�����мƻ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @param [IN]   pstSwitchPlanInfo       ���мƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    IN  COMMON_SWITCH_PLAN_INFO_S       *pstSwitchPlanInfo
);


/**
* ɾ��ͨ�����мƻ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulSwitchPlanType        ͨ�����мƻ����ͣ�ȡֵΪ#COMMON_SWITCH_PLANTYPE_E
* @param [IN]   szSwitchPlanCode        ͨ�����мƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulSwitchPlanType,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯͨ�����мƻ���Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulSwitchPlanType        ͨ�����мƻ����ͣ�ȡֵΪ#COMMON_SWITCH_PLANTYPE_E
* @param [IN]   szSwitchPlanCode        ͨ�����мƻ�����
* @param [OUT]  pstSwitchPlanInfo       ͨ�����мƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulSwitchPlanType,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    OUT COMMON_SWITCH_PLAN_INFO_S       *pstSwitchPlanInfo
);

/**
* ��ҳ��ѯͨ�����мƻ��б�
* ����Ϊ��ʱ,��ѯ����ͨ�����мƻ�,��Ĭ�ϰ���"ͨ�����мƻ���������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   ulSwitchPlanType        ͨ�����мƻ����ͣ�ȡֵΪ#COMMON_SWITCH_PLANTYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[���мƻ�����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSwitchPlanList       ͨ�����мƻ��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchPlanList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                           ulSwitchPlanType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT COMMONSWITCH_PLAN_QUERY_ITEM_S  *pstSwitchPlanList
);



/**
* ��ӳ�����Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstFactoryInfo      ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddManufacturerType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  MANUFACTURER_TYPE_INFO_S            *pstManufacturerInfo
);

/**
* ɾ��������Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   ulFactoryTypeId     ����������ϢID
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelManufacturerType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ULONG_32                               ulManufacturerTypeId
);

/**
* �޸ĳ�����Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstFactoryInfo      ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyManufacturerType
(
    IN    USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN    MANUFACTURER_TYPE_INFO_S            *pstManufacturerInfo
);

/**
* ��ѯ������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   ulTypeId           ����ID
* @param [OUT]  pstFactoryInfo     ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManufacturerType
(
    IN   USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  ULONG_32                              ulManufacturerTypeId,
    OUT  MANUFACTURER_TYPE_INFO_S          *pstManufacturerInfo
);

/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo   ��ѯ��ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ��ѯ���ط�ҳ��Ϣ
* @param [OUT]  pstFactoryInfoList ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManufacturerTypeList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT MANUFACTURER_TYPE_INFO_S        *pstManufacturerInfoList
);

/**
* ����豸������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDevTypeInfo     �豸������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEV_TYPE_NOT_EXIST �豸���Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDevType
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  DEV_TYPE_INFO_S                *pstDevTypeInfo
);

/**
* ɾ���豸������Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDevTypeId         �豸��Ϣ����ID
* @param [IN]   ulDevSubTypeID      �豸��Ϣ������ID
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEV_TYPE_NOT_EXIST �豸���Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDevType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ULONG_32                               ulDevTypeId,
    IN  ULONG_32                               ulDevSubTypeID
);

/**
* �޸��豸������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDevTypeInfo     �豸������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEV_TYPE_NOT_EXIST �豸���Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDevType
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    DEV_TYPE_INFO_S                *pstDevTypeInfo
);

/**
* ��ѯ�豸������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   ulTypeId           ����ID
* @param [IN]   ulDevSubTypeId     �豸��Ϣ������ID
* @param [OUT]  pstDevTypeInfo     �豸������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEV_TYPE_NOT_EXIST �豸���Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevType
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   ULONG_32                          ulDevTypeId,
    IN   ULONG_32                          ulDevSubTypeId,
    OUT  DEV_TYPE_INFO_S                *pstDevTypeInfo
);

/**
* ��ѯ�豸�����б� \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo   ��ѯ��ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ��ѯ���ط�ҳ��Ϣ
* @param [OUT]  pstDevTypeInfoList ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevTypeList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT DEV_TYPE_INFO_S                 *pstDevTypeInfoList
);

/**
* ����¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEventType       �¼�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_EVENT_TYPE_ID_EXIST �¼�����ID�Ѵ���
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_TYPE_S                *pstEventType
);

/**
* ɾ���¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDevTypeId        �¼���Ϣ����ID
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_EVENT_TYPE_NOT_EXIST �¼����Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ULONG_32                               ulEventTypeId
);

/**
* �޸��¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEventType       �¼�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_EVENT_TYPE_NOT_EXIST �¼����Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEventType
(
    IN    USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN    EVENT_TYPE_S                    *pstEventTypeInfo
);

/**
* ��ѯ�¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDevTypeId        �¼���Ϣ����ID
* @param [OUT]  pstEventTypeInfo   �¼�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_EVENT_TYPE_NOT_EXIST �¼����Ͳ�����
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventType
(
    IN   USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN   ULONG_32                            ulEventTypeId,
    OUT  EVENT_TYPE_S                     *pstEventTypeInfo
);

/**
* ��ѯ�¼������б� \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDevTypeId        �豸����ID,ȡֵ��Χ��#IMOS_TYPE_E
* @param [IN]   ulDevSubTypeId     �豸��Ϣ������ID,���������ȡֵ��#CAMERA_TYPE_E,��֯����ȡֵ��Χ��mm_def.h��6��MM_DOMAIN_SUBTYPE_XXX_XXX�ĺ궨��,
*                                      ����ʾ����ȡֵ��#SALVO_TYPE_E,����Ѳ����ȡֵ��#GROUP_SWITCH_TYPE_E,EC��DC����ȡֵ��#IMOS_DEVICE_TYPE_E
* @param [IN]   szDevCode          �豸����
* @param [IN]   ulParentDevType    ���豸����ID,ȡֵ��Χ��#IMOS_TYPE_E
* @param [IN]   ulParentSubDevType ���豸��Ϣ������ID,���������ȡֵ��#CAMERA_TYPE_E,��֯����ȡֵ��Χ��mm_def.h��6��MM_DOMAIN_SUBTYPE_XXX_XXX�ĺ궨��,
*                                      ����ʾ����ȡֵ��#SALVO_TYPE_E,����Ѳ����ȡֵ��#GROUP_SWITCH_TYPE_E,EC��DC����ȡֵ��#IMOS_DEVICE_TYPE_E
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ������Ŀǰֻ֧�������Ͳ�����ֻ֧�ֵ��ڣ�
* @param [IN]   pstQueryPageInfo   ��ѯ��ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ��ѯ���ط�ҳ��Ϣ
* @param [OUT]  pstEventTypeExtInfoList  �¼�������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventTypeList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDevTypeId,
    IN  ULONG_32                           ulDevSubTypeId,
    IN  CHAR                            szDevCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulParentDevType,
    IN  ULONG_32                           ulParentSubDevType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EVENT_TYPE_EXT_INFO_S           *pstEventTypeExtInfoList
);
/***************************************************************************
 ����
****************************************************************************/
/**
* ���ĸ澯 \n
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   pstSubscInfo        ������Ϣ
* @param [OUT]  szSessionID         ���ض��ĳɹ���ҵ��ID
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 IMOS_SubscribeEvent
(
    IN USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN SUBSC_BASE_INFO_S      *pstSubscInfo,
    OUT CHAR  szSessionID[IMOS_SSN_ID_LEN]
);

/**
* �����澯 \n
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   ulExpires           ����ʱ��
* @param [IN]   szSessionID         ���ĳɹ���ҵ��ID
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 IMOS_RenewSubscribe
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN ULONG_32  ulExpires,
    IN CHAR   szSessionID[IMOS_SSN_ID_LEN]
);

/**
* ȡ������ \n
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   szSessionID         ���ĳɹ���ҵ��ID
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 IMOS_CancelSubscribe
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR  szSessionID[IMOS_SSN_ID_LEN]
);

/**
* ��ѯ�����б� \n
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   pstQueryCondition   ��ѯ����
* @param [IN]   pstQueryPageInfo    ��ҳ������Ϣ
* @param [OUT]  pstRspPageInfo      ��ҳ���󷵻���Ϣ
* @param [OUT]  pstSubscList        ��ѯ�ĸ澯��Ϣ
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note �ڲ�ѯ��������¼ʱpstSubscFullInfo��ָ���ѯ�б��׼�¼�ĵ�ַ
*       Ŀǰֻ֧����Դ�����ѯ���� [#CODE_TYPE]
*/
IMOS_EXPORT ULONG_32 IMOS_QuerySubscribeList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SUBSC_FULL_INFO_S           *pstSubscList
);

/* Begin Add By hexiaojun/hW0959 for Ŀ¼��ѯ 2014-11-10 */
/**
* ��ѯĿ¼�����б� \n
* @param [IN]   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]   COMMON_QUERY_CONDITION_S       *pstQueryCondition   ��ѯ����
* @param [IN]   QUERY_PAGE_INFO_S              *pstQueryPageInfo    ��ҳ������Ϣ
* @param [OUT]  RSP_PAGE_INFO_S                *pstRspPageInfo      ��ҳ���󷵻���Ϣ
* @param [OUT]  SUBSC_FULL_INFO_S            *pstCatalogList        ��ѯ��Ŀ¼��Ϣ
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note �ڲ�ѯ��������¼ʱpstSubscFullInfo��ָ���ѯ�б��׼�¼�ĵ�ַ
*       Ŀǰֻ֧����Դ�����ѯ���� [#CODE_TYPE]
*/
IMOS_EXPORT ULONG_32 IMOS_QueryCatalogSubscribeList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SUBSC_FULL_INFO_S           *pstCatalogList
);
/* End Add By hexiaojun/hW0959 for Ŀ¼��ѯ 2014-11-10 */

/**
* ��������
* @param [IN]   pstUserLogIDInfo �û���½��Ϣ
* @param [IN]   pstTrunkInfo     ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TRUNK_INFO_S            *pstTrunkInfo
);

/**
* �޸ĸ�����Ϣ
* @param [IN]   pstUserLogIDInfo �û���½��Ϣ
* @param [IN]   pstTrunkInfo     ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TRUNK_INFO_S            *pstTrunkInfo
);

/**
* ɾ��������Ϣ
* @param [IN]   pstUserLogIDInfo �û���½��Ϣ
* @param [IN]   szTrunkCode      ���߱���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯ�����б���Ϣ
* @param [IN]   pstUserLogIDInfo     �û���½��Ϣ
* @param [IN]   pstQueryCondition    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo       ���ط�ҳ��Ϣ
* @param [OUT]  pstTrunkList         �����б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �޲�ѯ������pstQueryCondition����ΪNULL,
*       Ŀǰֻ֧�����Ʋ�ѯ����.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrunkList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TRUNK_INFO_S                *pstTrunkList
);

/**
* Added by g00762(gaoshufeng), 2012-08-03 for VM����ECR�ĸ��߹���
* ��Ӹ���������Ϣ���豸���߿���ӵĸ�������ΪEC��ECR����֯�������߿���ӵ�����Ϊ����
* @param [IN]   pstUserLogIDInfo      �û���½��Ϣ
* @param [IN]   szTrunkCode           ���߱���
* @param [IN]   ulContentNum          ����������Ŀ,���ֵΪ#IMOS_TRUNK_CONTENT_MAXNUM
* @param [IN]   pstTrunkContentList   ���������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTrunkContent
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulContentNum,
    IN  TRUNK_CONTENT_INFO_S    *pstTrunkContentList
);

/**
* ɾ������������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���½��Ϣ
* @param [IN]   szTrunkContentCode  �������ݱ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteTrunkContent
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkContentCode[IMOS_RES_CODE_LEN]
);

/**
* Added by g00762(gaoshufeng), 2012-08-03 for VM����ECR�ĸ��߹���
* ��ѯ����������Ϣ���豸���߲�ѯ���ĸ�������ΪEC��ECR����֯�������߲�ѯ��������Ϊ����
* @param [IN]   pstUserLogIDInfo     �û���½��Ϣ
* @param [IN]   szTrunkCode          ���߱���
* @param [IN]   pstQueryCondition    ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo       ���ط�ҳ��Ϣ
* @param [OUT]  pstTrunkContentList  ���������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note Ŀǰ�ݲ�֧���κβ�ѯ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrunkContentList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szTrunkCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TRUNK_CONTENT_INFO_S        *pstTrunkContentList
);

/**
* �������߹���
* @param [IN]   pstUserLogIDInfo  �û���½��Ϣ
* @param [IN]   szTrunkCode       ���߱���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN]
);

/**
* ֹͣ���߹���
* @param [IN]   pstUserLogIDInfo  �û���½��Ϣ
* @param [IN]   szTrunkCode       ���߱���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DisableTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN]
);

/**
* �������
* @param [IN]   pstUserLogIDInfo  �û���½��Ϣ
* @param [IN]   szResCode         ��Դ����
* @param [OUT]  szSsnID           �ỰID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ú������ĳ�ֿ��ܲ����������ҵ�����Դʹ��:
* -     Ŀǰ�ڻط�/����¼��ǰ����ҪΪ�������������ߡ�
* -     ����ɹ������ҵ���ͷ���Ҫ�����ͷź����ͷ�����ĸ��ߡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ApplyTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szResCode[IMOS_RES_CODE_LEN],
    OUT CHAR                    szSsnID[IMOS_SSN_ID_LEN]
);

/**
* �ͷŸ���
* @param [IN]   pstUserLogIDInfo   �û���½��Ϣ
* @param [IN]   szSsnID            �ỰID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_FreeTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szSsnID[IMOS_SSN_ID_LEN]
);

/**
* ����ϵͳ����װ��ʽ
* @param [IN] pstUserLogIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN] pstSysStreamFormat    ϵͳ��װ����ʽ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* �������� UDP+TS , RTP+TS,RTP_NO_RTCP+ES
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSysStreamFormat
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SYS_STREAM_FORMAT_S             *pstSysStreamFormat
);

/**
* ��ѯϵͳ����װ��ʽ
* @param [IN] pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [OUT] pstSysStreamFormat    ϵͳ��װ����ʽ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysStreamFormat
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT SYS_STREAM_FORMAT_S             *pstSysStreamFormat
);

/**
* ����ϵͳʵ����������������Ӧƥ�����
* @param [in] pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [in] ulMonStreamMatchPolicy    ϵͳʵ����������������Ӧƥ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSysMonStreamMatchPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulMonStreamMatchPolicy
);

/**
* ��ѯϵͳʵ����������������Ӧƥ�����
* @param [IN]  pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [OUT] pulMonStreamMatchPolicy    ϵͳʵ����������������Ӧƥ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysMonStreamMatchPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulMonStreamMatchPolicy
);

/**
* ����ϵͳ�鲥��ַ��������ѡ�����
* @param [in] pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [in] ulMCastAddrStreamPolicy    ϵͳ�鲥��ַ��������ѡ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSysMCastAddrStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulMCastAddrStreamPolicy
);

/**
* ��ѯϵͳ�鲥��ַ��������ѡ�����
* @param [IN]  pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [OUT] pulMCastAddrStreamPolicy    ϵͳ�鲥��ַ��������ѡ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysMCastAddrStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulMCastAddrStreamPolicy
);

/**
* ����ϵͳ����ֵ
* @param [in] pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ
* @param [in] pszSystemParamName      ϵͳ����������С��#IMOS_NAME_LEN����ʱֻ��#SS_SYSPARAM_NAME_SECOND_MCAST_ADDR_STREAM_POLICY����
* @param [in] ulMCastAddrStreamPolicy    ϵͳ�鲥��ַ��������ѡ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSystemParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                                    *pszSystemParamName,
    IN  ULONG_32                               ulSystemParamValue
);

/**
* ��ѯϵͳ����ֵ
* @param [IN]  pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ
* @param [in] pszSystemParamName      ϵͳ����������С��#IMOS_NAME_LEN����ʱֻ��#SS_SYSPARAM_NAME_MCAST_ADDR_STREAM_POLICY����
* @param [OUT] pulSystemParamValue    ϵͳ��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryfigSystemParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                                    *pszSystemParamName,
    OUT ULONG_32                             *pulSystemParamValue
);

/**
* ��������󶨵�EC��ĳ��ͨ���ϣ���Ҫ����������Ϣ��֧�ֳ���OSD���ڸ�������Ƶ�����ڵ���������˶������������Ԫ�ر䳤
* @param [IN]   pstUserLogIDInfo             �û���Ϣ
* @param [IN]   pstVINBindCamBaseInfo        ����������ͨ���Ļ�����Ϣ
* @param [IN]   pstVINFullVarietyElement     ��Ƶͨ��ȫ���䳤Ԫ�ؽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* 1.��������벻��Ϊ��,�Ҳ��ܰ����ո�
* 2.�䳤Ԫ�ظ����ͱ䳤Ԫ���ڴ泤���ɵ����߱�֤���䳤Ԫ�ظ������ɴ��ڱ䳤Ԫ��ʵ���ڴ泤��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelV2
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLogIDInfo,
    IN  VINCHNL_BIND_CAMERA_BASE_S              *pstVINBindCamBaseInfo,
    IN  VINCHNL_FULL_VARIETY_ELEMENT_S          *pstVINFullVarietyElement
);

/**
* ��������󶨵�EC ��ĳ��ͨ���ϣ���Ҫ����������Ϣ��֧�ֳ���OSD���ڸ�������Ƶ�����ڵ���������˶������������Ԫ�ر䳤
* @param [IN]  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo             �û���Ϣ
* @param [IN]  VINCHNL_BIND_CAMERA_BASE_V2_S       *pstVINBindCamBaseInfo        ����������ͨ���Ļ�����Ϣ
* @param [IN]  VINCHNL_FULL_VARIETY_ELEMENT_S   *pstVINFullVarietyElement     ��Ƶͨ��ȫ���䳤Ԫ�ؽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* 1.��������벻��Ϊ��,�Ҳ��ܰ����ո�
* 2.�䳤Ԫ�ظ����ͱ䳤Ԫ���ڴ泤���ɵ����߱�֤���䳤Ԫ�ظ������ɴ��ڱ䳤Ԫ��ʵ���ڴ泤��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelV3
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLoginIDInfo,
    IN  VINCHNL_BIND_CAMERA_BASE_V2_S           *pstVINBindCamBaseInfo,
    IN  VINCHNL_FULL_VARIETY_ELEMENT_S          *pstVINFullVarietyElement
);

/**
* ��ѯĳ����֯�µ�ĳ̨�豸��������洢��Դ��������б�V2
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstStoreResList         ������洢��Դ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.����޲�ѯ����,ָ��pstQueryCondition����ΪNULL
* - ����
* - 1. ֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB,1 ��,0 ��
* - 2. ���ڸշ�����Ĵ洢��Դ���ӿڷ�����Դ״̬Ϊ����������Ҫ��ʱһ��ʱ��(������)����ִ��¼��洢
* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStoreResListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT STORE_RES_QUERY_ITEM_V2_S   *pstStoreResList
);

/**
* ��ѯ��ĳ���洢�豸�������˴洢��������б�  \n
* @param [IN]   *pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorDevCode           �洢�豸����
* @param [IN]   ulStorageType           �洢����  0: ����洢 1: ����洢
* @param [IN]   *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  *pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  *pstSDKCamList          ������б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����ʽΪ"�����������������"
* - 2. ���ӿ���ֱ��ѯ���ű�,�ݲ�֧��ͨ�ò�ѯ����
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamListByStoreDev
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStoreDevCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulStorageType,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CAM_STORE_BASIC_QUERY_ITEM_S    *pstSDKCamList
);
#if 0
#endif
/**************************************************************************************************************
�豸-BM
***************************************************************************************************************/
/** @defgroup group BM ����������
*   �������������BM,������Դ���������񣬱����ļ������ݼƻ������
*   @{
*/
/**
* @name BM����
* @{    BM����
*/
/**
* ���BM������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBMInfo           BM��Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddBM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BM_INFO_S                   *pstBMInfo
);

/**
* �޸�BM������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBMInfo           BM��Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BM_INFO_S                   *pstBMInfo
);

/**
* ɾ��BM������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szBMCode            BM����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBMCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯBM�������б� \n
* szOrgCodeֵ��Ч�����κ�ֵ����ֻ��ѯ����BM�б�
* ����Ϊ��ʱ,������,��Ĭ��"������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode              ��֯����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[BM����] #CODE_TYPE[BM����] #PHY_DEV_IP[BM IP])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKBMList           BM�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBMList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT BM_QUERY_ITEM_S             *pstSDKBMList
);
/** @} */ /* end of DEVICE BM MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
������Դ����
****************************************************************************/
/**
* @name ������Դ����
* @{    �漰BM������Դ����,�����������Դ����
*/
/**
* �Ӵ洢�豸ΪBM������������Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBMResInfo        BM��Դ��Ϣ
* @param [OUT]  szBMResCode         BM��Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromStoreDev
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DM_RES_FOR_BM_INFO_S    *pstBMResInfo,
    OUT CHAR                    szBMResCode[IMOS_CODE_LEN]
);

/**
* �ӵ�������ԴΪBM������������ԴV2 \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBMResInfo        BM��Դ��Ϣ
* @param [OUT]  szBMResCode         BM��Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromThird
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  THIRD_RES_FOR_BM_INFO_S   *pstBMResInfo,
    OUT CHAR                      szBMResCode[IMOS_CODE_LEN]
);


/**
* �ӵ�������ԴΪBM������������Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBMResInfo        BM��Դ��Ϣ
* @param [OUT]  szBMResCode         BM��Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromThirdV2
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  THIRD_RES_FOR_BM_INFO_S_V2   *pstBMResInfoV2,
    OUT CHAR                      szBMResCode[IMOS_CODE_LEN]
);

/**
* �ӵ�������ԴΪBM������������Դ(V3) \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBMResInfo        BM��Դ��Ϣ
* @param [OUT]  szBMResCode         BM��Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromThirdV3
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  THIRD_RES_FOR_BM_INFO_S_V3   *pstBMResInfoV3,
    OUT CHAR                      szBMResCode[IMOS_CODE_LEN]
);

/**
* ɾ��BM�������Ϸ���ı�����Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN    szResCode           BM��Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBMRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szResCode[IMOS_CODE_LEN]
);

/**
* ��ѯBM������Դ�б� \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szBMCode               BM����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[BM��Դ����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKBMResList        BM������Դ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBMResList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBMCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT BM_RES_QUERY_ITEM_S         *pstSDKBMResList
);

/**
* �Ӵ洢�豸�Ϸ��乲��洢��Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstShareResInfo     ������Դ��Ϣ
* @param [OUT]  szShareResCode     ������Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignShareRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DM_SHARE_RES_INFO_S     *pstShareResInfo,
    OUT CHAR       szShareResCode[IMOS_CODE_LEN]
);

/**
*����洢��ԴV2
*@param [IN]    pstUserLogInfo        �û���¼ID ��Ϣ��ʶ
*@param [IN]    szCamCode        ���������
*@param [IN]    pstStoreResInfo        �洢��Դ��Ϣ
*@return �������½��:
* �ɹ�:
* #ERR_COMMON_SUCCEED
*ʧ��:
* #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* #ERR_AS_STORE_RES_ALLOCTED
*    ���ز�������룬���������ļ�
*@note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignStoreResV2
(
    IN USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN CHAR                               szCamCode[IMOS_RES_CODE_LEN],
    IN STORE_RES_INFO_V2_S            *pstStoreResInfo
);

/**
* ��ѯ�洢��ԴV2
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [OUT]  pstStoreResInfo         ����Ĵ洢��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_NOT_EXIST
* - #ERR_DAO_STORE_RES_NOT_EXIST
* - #ERR_DAO_EVENT_STORAGE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStoreResV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT STORE_RES_INFO_V2_S            *pstStoreResInfo
);

/**
* ��ҳ��ѯ�ѷ��乲����ԴDM�б�  \n
* ��ѯ���������ù�����Դ��DM, ��Ĭ�ϰ��չ���洢ʱ�併������\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKDMList        DM�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note  ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareResDMList
(
    IN     USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN     CHAR                                   szCamCode[IMOS_CODE_LEN],
    IN     QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT  DM_SHARE_STORAGE_DEVICE_INFO_S  *pstSDKDMList
);

/**
* ɾ������洢��Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode     ������Դ����
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelShareRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR       szResCode[IMOS_CODE_LEN]
);


#if 0
#endif
/**
* ���������������Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCamBakResInfo    �����������Դ��Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_BAK_RES_INFO_S      *pstCamBakResInfo
);

/**
* �޸��������������Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCamBakResInfo    �����������Դ��Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_BAK_RES_INFO_S      *pstCamBakResInfo
);

/**
* ɾ�������������Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯ�����������Դ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @param [OUT]  ulItemNum           �����������Դ��Ϣ����
* @param [OUT]  pstCamBakResList    �����������Դ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ���������ڱ���ı�����Դ��ѯ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szCamCode[IMOS_DEVICE_CODE_LEN],
    OUT ULONG_32                     *pulItemNum,
    OUT CAM_BAK_RES_INFO_S        *pstCamBakResList
);


/**
* ��ҳ��ѯĳ����֯�������������Դ��������б�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[���������])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCamBakResList        �����������Դ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ���������ڱ���ı�����Դ��ѯ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamBakResList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CAM_BAK_RES_QUERY_ITEM_S    *pstCamBakResList
);

/** @} */ /* end of BACKUP RESOURCE MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
�����������
****************************************************************************/
/**
* @name �����������
* @{    �����������
*/
/**
* �����ֶ����� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstManulBakInfo     �ֶ�����������Ϣ
* @param [OUT]  szTaskCode          �����������
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�������������ֶ�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetManualBak
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  MANUL_BAK_INFO_S          *pstManulBakInfo,
    OUT CHAR                      szTaskCode[IMOS_CODE_LEN]
);

/**
* ɾ���������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTaskCode          �����������
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBakTask
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTaskCode[IMOS_CODE_LEN]
);

/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   ulTaskType              ��������#BAK_TYPE_E
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKBakTaskList       ���������б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1��ͨ�ò�ѯ����֧��:����״̬[#TASK_STATUS]�������ύʱ��[#TASK_SUB_TIME]���������ʱ��[#TASK_END_TIME]�����������[#NAME_TYPE]��
* -    ¼��ʼʱ��[#REC_START_TIME]��¼�����ʱ��[#REC_END_TIME]���û�����[#USER_NAME_TYPE]����������[#CASE_DESC]�Ĳ�ѯ������;
* - 2��ͨ�ò�ѯ����ΪNULL,������������ʱ,Ĭ�ϰ�"�����ύʱ������"����;
* - 3����admin�û�����������ֻ�����ֶ�����[#BAK_MANUL];
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBakTaskList
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S   *pstQueryCondition,
    IN  ULONG_32                      ulTaskType,
    IN  QUERY_PAGE_INFO_S          *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S            *pstRspPageInfo,
    OUT BAK_TASK_QUERY_ITEM_S      *pstSDKBakTaskList
);
/** @} */ /* end of BACKUP TASK MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
�����ļ�����
****************************************************************************/
/**
* @name �����ļ�����
* @{    �����ļ�����
*/
/**
* ���������ļ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBakFileInfo      �����ļ�������Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_HandleBakFile
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  BAK_FILE_HANDLE_INFO_S     *pstBakFileInfo
);

/* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
/**
* ¼������\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   LOCK_RECORD_INFO_S     *pstLockRecordInfo            ¼��������Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LockRecord
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  LOCK_RECORD_INFO_S     *pstLockRecordInfo
);

/**
* ¼�����\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   ULONG_32                          ulUnlockType            ¼���������
* @param [IN]   CHAR                          szUnlockKeyStr[IMOS_STRING_LEN_256]            ¼���������������ͺ��岻ͬ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnlockRecord
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  ULONG_32   ulUnlockType,
    IN  CHAR    szUnlockKeyStr[IMOS_STRING_LEN_256]
);

/**
* ��ѯ����������б�֧�ַ�ҳ��ѯ\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   ULONG_32      ulQueryType            ��ѯ��������
* @param [IN]   CHAR        szQueryKeyStr[IMOS_STRING_LEN_256]            ��ѯ����
* @param [IN]  QUERY_PAGE_INFO_S        *pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT] LOCKED_CAMERA_QUERY_ITEM_S   *pstLockedCameraList       �������������Ϣ�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLockedCameraList
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  ULONG_32   ulQueryType,
    IN  CHAR    szQueryKeyStr[IMOS_STRING_LEN_256],
    IN  QUERY_PAGE_INFO_S   *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S     *pstRspPageInfo,
    OUT LOCKED_CAMERA_QUERY_ITEM_S   *pstLockedCameraList
);

/**
* ��ѯĳ�����������¼����Ϣ�б�֧�ַ�ҳ��ѯ\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR       szCameraCode[IMOS_CODE_LEN]    ���������
* @param [IN]  QUERY_PAGE_INFO_S        *pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT] LOCKED_CAMERA_QUERY_ITEM_S   *pstLockedCameraList       ������¼����Ϣ�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLockedRecordList
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  CHAR                szCameraCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S   *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S     *pstRspPageInfo,
    OUT LOCKED_RECORD_QUERY_ITEM_S   *pstLockedRecordList
);
/* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */

/**
* ����¼����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKRecordFileInfo    �����ļ���Ϣ���ݽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1��ͨ�ò�ѯ����֧��:���������[#CODE_TYPE]�����������[#NAME_TYPE]���ļ�����ʱ��[#FILE_CREATE_TIME]��
* -    ���ݿ�ʼʱ��[#BAK_START_TIME]�����ݽ���ʱ��[#BAK_END_TIME]���ļ�����[#FILE_CAPACITY]���ļ�����[#FILE_TYPE]��
* -    �ļ�������ʶ[#FILE_LOCK_FLAG]����������[#CASE_DESC]�Ĳ�ѯ������;
* - 2��ͨ�ò�ѯ����ΪNULL,������������ʱ,Ĭ�ϰ�"���ݿ�ʼʱ������"����;
* - 3��ͨ�ò�ѯ��������ӵı��ݿ�ʼʱ�������ʱ��֮���ʱ���Ȳ��ܿ��죬��ʱ���ʽΪ��"%Y-%m-%d %H:%M:%S"��ʽ ����Ϣ�����޶�Ϊ24�ַ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BakRecordRetrieval
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CAM_BAK_FILE_QUERY_ITEM_S   *pstRecordFileInfo
);

/**
* ��ȡ����¼���ļ���URL��Ϣ \n
* @param[IN]    pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param[IN]    pstSDKGetBakUrlInfo     ��ȡURL������Ϣ���ݽṹ
* @param[OUT]    pstSDKURLInfo          URL��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetBakRecordFileURL
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_BAK_URL_INFO_S          *pstSDKGetBakUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);
/** @} */ /* end of BACKUP FILE MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
���ݼƻ�
****************************************************************************/
/**
* @name ���ݼƻ�����
* @{    �漰���ݼƻ���ɾ�Ĳ�,�Լ���ѯ���ݼƻ��б�ӿ�
*/
/**
* ��ӱ��ݼƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBakPlanInfo      ���ݼƻ���Ϣ
* @param [OUT]  szBakPlanCode       ���ݼƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BAK_PLAN_INFO_S             *pstBakPlanInfo,
    OUT CHAR                        szBakPlanCode[IMOS_RES_CODE_LEN]
);

/**
* �޸ı��ݼƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstBakPlan          ���ݼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note �������ݼƻ���Ҫ����IMOS_ProcessPlan�ӿ�; ��ͨ���޸ļƻ�ʱ��ķ�ʽ���ܹ��Զ�ʹ�ƻ�����/ֹͣ
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  BAK_PLAN_INFO_S                 *pstBakPlanInfo
);

/**
* ɾ�����ݼƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szBakPlanCode       ���ݼƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBakPlanCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯ���ݼƻ���Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szBakPlanCode       ���ݼƻ�����
* @param [OUT]  pstBakPlanInfo      ���ݼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBakPlanCode[IMOS_RES_CODE_LEN],
    OUT BAK_PLAN_INFO_S                 *pstBakPlanInfo
);

/*Begin added by liujian 02319 for �����ڱ�����������*/
/**
* �޸ı��ݼƻ��ӳ���Ϣ
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                        �û���¼ID��Ϣ��ʶ
* @param [IN]   ULONG_32    ulNumber                                                             �������õĸ���
* @param [IN]   CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos          ���ݼƻ��ӳ���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBackupPlanDelayInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                                 ulNumber,
    IN  CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos
);

/**
* ��ѯ���ݼƻ��ӳ���Ϣ
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                        �û���¼ID��Ϣ��ʶ
* @param [IN]   ULONG_32    ulNumber                                                             �������õĸ���
* @param [INOUT]   CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos          ���ݼƻ��ӳ���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @attention
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBackupPlanDelayInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                                 ulNumber,
    INOUT  CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos
);

/*End added by liujian 02319 for �����ڱ�����������*/

/**
* �����������ת������ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo   �������ת��������Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo
);

/**
* �޸��������ת��������� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo   �������ת��������Ϣ
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note: ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo
);

/**
* ɾ���������ת������ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo                  �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                    szCamCode[IMOS_CODE_LEN]           ���������
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�������ת��������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szCamCode[IMOS_CODE_LEN]    ���������
* @param [OUT]  CAM_STREAM_STOR_INFO_S      *pstCamStreamStorInfo       �������ת����Ϣ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  CHAR                     szCamCode[IMOS_CODE_LEN],
    OUT CAM_STREAM_STOR_INFO_S   *pstCamStreamStorInfo
);

/**
* ��ҳ��ѯĳ����֯���������ת��������Ϣ�б� \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]  CHAR                         szOrgCode[IMOS_CODE_LEN]    ��֯����
* @param [IN]  COMMON_QUERY_CONDITION_S     *pstQueryCondition          ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[���������])
* @param [IN]  QUERY_PAGE_INFO_S            *pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT] RSP_PAGE_INFO_S              *pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT] CAM_STREAM_STOR_QUERY_ITEM_S *pstCamStreamStorList       �����������Դ������Ϣ�б�
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStreamStorInfoList
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S         *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                  *pstRspPageInfo,
    OUT CAM_STREAM_STOR_QUERY_ITEM_S     *pstCamStreamStorList
);

/**
* ����������ת��ļƻ����� \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo                       �û���¼ID��Ϣ��ʶ
* @param [IN]   STREAM_STOR_PLAN_INFO_S     *pstStreamStorPlanInfo                  ��ת��ƻ���Ϣ
* @param [OUT]  CHAR                        szStreamStorPlanCode[IMOS_CODE_LEN]     ���ص���ת��ƻ�����
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  STREAM_STOR_PLAN_INFO_S              *pstStreamStorPlanInfo,
    OUT CHAR                                 szStreamStorPlanCode[IMOS_CODE_LEN]
);

/**
* �޸���ת��ƻ�
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]  STREAM_STOR_PLAN_INFO_S      *pstStreamStorPlanInfo  ��ת��ƻ���Ϣ
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  STREAM_STOR_PLAN_INFO_S    *pstStreamStorPlanInfo
);

/**
* ɾ����ת��ƻ�
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo                         �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                       szStreamStorPlanCode[IMOS_CODE_LEN]       ��ת��ƻ�����
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStreamStorPlanCode[IMOS_CODE_LEN]
);

/**
* ��ѯ��ת��ƻ���Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo                         �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                       szStreamStorPlanCode[IMOS_CODE_LEN]       ��ת��ƻ�����
* @param [OUT]  STREAM_STOR_PLAN_INFO_S    *pstStreamStorPlanInfo                    ��ת��ƻ���Ϣ
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szStreamStorPlanCode[IMOS_CODE_LEN],
    OUT STREAM_STOR_PLAN_INFO_S    *pstStreamStorPlanInfo
);

/**
* ����/ֹͣ�ƻ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   ulPlanType          �ƻ�����#PLAN_TYPE_E
* @param [IN]   szStorePlanCode     �ƻ�����
* @param [IN]   ulPlanMode          �ƻ�������, #PLAN_OPER_MODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֶԹ�����������б�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulPlanType,
    IN  CHAR                            szPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulPlanMode
);

/**
* ���ڳ�ʼ������ڡ� \n
* @param [IN]       szServerAdd     ������IP
* @param [IN]       ulServerPort    �������˿�
* @param [INOUT]  pstInit         SDK��ʼ������������pParam�ֶ�ΪINOUT��
* @return ULONG  �������½��:
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ���
* @note szServerAdd��ȡֵΪ127.0.0.0,127.0.0.1,VM��������ַ
*       ulServerPort��ȡֵΪ8800
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_InterInitiate
(
    IN    CHAR       szServerAdd[IMOS_IPADDR_LEN],
    IN    ULONG_32      ulServerPort,
    INOUT SDK_MU_INIT_S *pstInit
);

/* added by z06806 for vodwall prj 20101211 begin */
/**
* ��ʼ�ط���ǽ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szXPCode                XP����
* @param [IN]   szMonitorCode           ����������
* @param [IN]   ulOperateCode           ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E
* - 2.  szMonitorCode�ڻط���ǽ��Ϊ��Ӧ����������
* - 3. szXPCode�ڻط���ǽ��Ϊ��Ӧ�������
* - 4. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartVodToTV
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szXPCode[IMOS_CODE_LEN],
    IN  CHAR                        szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulOperateCode
);

/**
* ֹͣ�ط���ǽ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   ulCodeType              �������ͣ���#VODWALL_STOP_CODETYPE_E
* @param [IN]   szXPCode                XP����
* @param [IN]   szMonitorCode           ����������
* @param [IN]   ulOperateCode           ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E
* - 2. �����������Ϊ����������szMonitorCode����������룬szXPCode���Բ���
* - 3. �����������ΪXP����szXPCode��XP���룬szMonitorCode���Բ���
* - 4. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopVodToTV
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                           ulCodeType,
    IN  CHAR                            szXPCode[IMOS_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);
/* added by z06806 for vodwall prj 20101211 end */

/**
* ��ѯ��֯����Դ��Ϣ�б�(V3������#RES_INFO_S�ṹ��������ԴID��������Ȩ��) \n
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResList                 ��Դ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯��������Դ(��������֯)
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ�"��Դ����"ģ����ѯ:#NAME_TYPE
* - 4.֧�ְ�"�Ƿ�������Դ"��ѯ:#DOMAIN_TYPE = 1 ��;= 0 ��
* - 5.֧�ְ�"��Դ����"��ѯ:#RES_TYPE,ȡֵΪ#IMOS_TYPE_E
* - 6.֧�ְ�"��Դ������"��ѯ:#RES_SUB_TYPE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_TYPE_E)
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Դ����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��Դ����),#CODE_TYPE(��Դ����),#RES_TYPE(��Դ����),#RES_SUB_TYPE(��Դ������),
* -   #DOMAIN_TYPE(�Ƿ�������Դ)
* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceListNoAuth
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT RES_INFO_S                      *pstResList
);

/**
* ���ݽ�ɫ���룬���ý�ɫȨ��(V2) \n
* @param [IN]   pstUserLogIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode            ��ɫ���룬��ӦΨһһ����ɫ
* @param [IN]   ulResAuthorityNum     ��Դ��Ȩ��Ϣ����
* @param [IN]   pstResAuthorityList   ��Դ��Ȩ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿ����õ���Դ��Χ�����ڽ�ɫ������֯������֯
* - 2. �����Ȩ�޿�����ϵͳȨ�ޣ�Ҳ�����������Դ��������֯������ͷ���������ȣ���Ȩ��
* - 3. ���øýӿں�, �Ըôε��õ�Ȩ��Ϊ׼����ɫ֮ǰ��Ȩ�޻ᱻ����
* - 4. ulResAuthorityNum����Ϊ0��ͬʱpstResAuthorityList����ΪNULL����ʾ�����ɫ����Ȩ�ޡ�
* - 5. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRoleAuthorityV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szRoleCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulResAuthorityNum,
    IN  RES_AUTHORITY_S             *pstResAuthorityList
);

/**
* ���ݽ�ɫ���룬��ѯĳ����ɫ��Ȩ����Ϣ(V2) \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode                   ��ɫ���룬��ӦΨһһ����ɫ
* @param [IN]   pstQueryCondition            ��ѯ����(֧�ֵĲ�ѯ��������:#RES_ID[��ԴID]
*                                                                        #RES_TYPE[��Դ����]��
*                                                                        #NAME_TYPE[��Դ����])
* @param [IN]   pstQueryPageInfo             �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo               ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResAuthorityList          ��ɫȨ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ȫ��Ȩ�޺�����Ȩ�ޱ���ֿ���ѯ��
* - 2. ��ѯȫ��Ȩ��ʱ����ѯ����ΪRES_ID����0��������������ѯ��������ѯ����Ȩ��ʱ��RES_ID����0���ҿ�����������ѯ������
* - 3. ���Ȩ�޼�¼��Ӧ����Դ�����ڣ����ν�ɫȨ���б��ж�Ӧ����Դ��#RES_INFO_S��szResIdCode��Ч�������ֶζ���Ч��
* - 4. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByRoleV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szRoleCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT RES_AUTHORITY_QUERY_ITEM_S      *pstResAuthorityList
);

/**
* ��ѯ��ǰ��¼�û�������Ȩ��(V2). \n
* �����ǰ��¼�û���ϵͳ����Ա,��ֻ����"�Ƿ���ϵͳ����Ա"��ʶ,������Ȩ���б�;
* �������ϵͳ����Ա,�򷵻�Ȩ���б�(����ϵͳȨ�޺���ԴȨ��).
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [OUT]  pbIsSystemMgr       "�Ƿ���ϵͳ����Ա"��ʶ, #BOOL_TRUEΪϵͳ����Ա; #BOOL_FALSEΪ��ϵͳ����Ա
* @param [OUT]  pstAuthorityInfo    Ȩ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByUserV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT BOOL_T                  *pbIsSystemMgr,
    OUT ORG_AUTHORITY_V2_S         *pstAuthorityInfo
);

/**
* ɾ����ɫ��һ����Ȩ��¼ \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode                   ��ɫ���룬��ӦΨһһ����ɫ
* @param [IN]   szResIdCode                  ��ԴID���ַ���"0"��ʾɾ����ɫ��ϵͳȨ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAuthItemByRole
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRoleCode[IMOS_CODE_LEN],
    IN  CHAR                    szResIdCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* �ͻ����ļ��ϴ����� \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,  �û���¼��Ϣ
* @param [IN]   IMOS_UPLOAD_ADDR_S          *pstServerAddr,     ��������ַ��Ϣ
* @param [IN]   IMOS_UPLOAD_OPTION_S        *pstOptions,        �ϴ�ѡ����Ϣ
* @param [IN]   IMOS_LOCAL_FILE_INFO_S      *pstLocalFile,      �����ļ���Ϣ
* @param [INOUT]    IMOS_HANDLE             *pUploadHandle      �ϴ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ����ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UploadFile
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  IMOS_UPLOAD_ADDR_S          *pstServerAddr,
    IN  IMOS_UPLOAD_OPTION_S        *pstOptions,
    IN  IMOS_LOCAL_FILE_INFO_S      *pstLocalFile,
    INOUT   IMOS_HANDLE             *pUploadHandle
);

/**
* �ͻ���ȡ���ļ��ϴ����� \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,  �û���¼��Ϣ
* @param [IN]   IMOS_HANDLE                 hUpload             �ϴ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ����ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CancelUpload
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  IMOS_HANDLE                 hUpload
);

/**
* ��ȡ�ͻ����ļ��ϴ����Ⱥ��� \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,  �û���¼��Ϣ
* @param [IN]   IMOS_HANDLE                 hUpload             �ϴ����
* @param [INOUT]   FLOAT                     *pfProcess         ����ٷֱȽ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ����ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUploadProcess
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  IMOS_HANDLE                 hUpload,
    INOUT FLOAT                     *pfProcess
);

#if 0
#endif

/***************************************************************************
IPC��ѧ��������
****************************************************************************/
/**
* ���ù�ѧ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN]   pstOpticsParam              ��ѧ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_OPT_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigOpticsParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  OPTICS_PARAM_S                  *pstOpticsParam
);

/**
* ��ѯ��ѧ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [OUT]  pstOpticsParam              ��ѧ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_OPT_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOpticsParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT OPTICS_PARAM_S                  *pstOpticsParam
);

/**
* ����ϵͳҵ����ռ����
* @param [IN] pstUserLogIDInfo      �û���¼��Ϣ
* @param [IN] pstSrvRevStrategy     ҵ����ռ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetReaveStrategy
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  SRV_REV_STRATEGY_S     *pstSrvRevStrategy
);

/**
* ��ѯϵͳҵ����ռ����
* @param [IN]  pstUserLogIDInfo       �û���¼��Ϣ
* @param [OUT] pstSrvRevStrategy      ҵ����ռ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryReaveStrategy
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    OUT SRV_REV_STRATEGY_S       *pstSrvRevStrategy
);

/** @} */ /* end of BACKUP PLAN MANAGEMENT MODULE */
/** @} */

/**
* ͨ��XML�����豸ͨ�ýӿ�
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   ulXmlLen               �豸��XML������Ϣ
* @param [IN]   pcXml                  �豸��XML��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_AS_EC_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. XML��ʽ���"��������.xml"�ļ�
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDevByXML
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    ULONG_32                         ulXmlLen,
    IN    CHAR                          *pcXml
);

/**
* �����Զ�����
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartAutoFind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo
);

/**
* ֹͣ�Զ�����
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopAutoFind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo
);

/**
* ��ѯ�Զ�����״̬
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [OUT]  pulstate            �Զ�����״̬��1����������0����ֹͣ��ϵͳÿ������Ĭ��ֹͣ״̬
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAutoFindState
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulstate
);

#if 0
#endif
/**************************************************************************************************************
ECR33**-HF
***************************************************************************************************************/
/** @defgroup group ECR33**-HF
*   ����VM����ECR, ECR�豸����������
*   @{
*/
/***************************************************************************
PartI VM����ECR
****************************************************************************/
/**
* @PartI VM����ECR
* @{    VM����ECR
*/
/**
* ��Ӵ��洢�ı�����, ��֧��HFϵ�С����ECRʱ�����豸����Ϊ�豸�������͡����NVRʱ�����豸����ΪIMOS_DT_ISC_MIN���豸ע�����ߺ���ȡ�����豸�ͺ� \n
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   pstECRBasicInfo    ���洢�ı�����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ECR_BASIC_INFO_S        *pstECRBasicInfo
);

/**
* �޸Ĵ��洢�ı�����, ��֧��HFϵ��.Ҳ���޸�������Ƶ¼��� \n
* Ŀǰ��֧���޸�����.
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   pstECRBasicInfo    ���洢�ı�����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ECR_BASIC_INFO_S        *pstECRBasicInfo
);

/**
* ɾ�����洢�ı�����, ��֧��HFϵ��.Ҳ��ɾ��������Ƶ¼��� \n
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szECRCode           ���洢�ı���������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN]
);

/**
* ��ѯ���洢�ı�����, ��֧��HFϵ��.Ҳ�ɲ�ѯ������Ƶ¼�����Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szECRCode           ���洢�ı���������
* @param [OUT]  pstECRBasicInfo     ���洢�ı�����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECRInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN],
    OUT ECR_BASIC_INFO_S        *pstECRBasicInfo
);

/**
* ��ѯĳ����֯�´��洢�ı������б���Ϣ, ��֧��HFϵ��.Ҳ�ɲ�ѯ������Ƶ¼��� \n
* ��ѯ������û�ж��������͵Ĳ�ѯ����ʱ��ѯECR��NVR.
* ��ѯECR��Ӳ�ѯ������ulQueryType:206,ulLogicFlag:3,szQueryData:7.ulQueryType:206,ulLogicFlag:4,szQueryData:1012
* ��ѯNVR��Ӳ�ѯ������ulQueryType:206,ulLogicFlag:3,szQueryData:1013.ulQueryType:206,ulLogicFlag:4,szQueryData:2020
* �����豸����Ĳ�ѯ��ֻ֧��ģ����ѯ����֧�־�ȷ��ѯ.
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯�����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[���洢�ı���������] #CODE_TYPE[���洢�ı���������] #EXT_DOMAIN_IP[���洢�ı�������ַ])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstECRBasicInfoList     ���洢�ı�����������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECRList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ECR_BASIC_INFO_S            *pstECRBasicInfoList
);

/**
* ��ѯECR��������б�, ��֧��HFϵ��.
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szECRCode               ECR����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstECRCamList           ��ѯ����������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
* - 2. ֧�ְ���������롢�������򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:#CODE_TYPE��#NAME_TYPE;
* - 3. ���������������Ĭ�ϰ��������������������;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECRCameraList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szECRCode[IMOS_ECR_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ECR_CAM_INFO_S              *pstECRCamList
);

/**
* ɾ��ECR�����, �Ὣ��ǰҵ��ֹͣ; ����ɾ��ECRʱ�Ĳ���; ��֧��HFϵ��.
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szCamCode               ��ɾ�������������
* @param [IN]   szECRCode               ECR����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCameraForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCamCode[IMOS_CODE_LEN],
    IN  CHAR                        szECRCode[IMOS_ECR_CODE_LEN]
);

/**
* ��ѯECR�ĸ澯Դ�б�, ����ɾ��ECRʱ�Ĳ���; ��֧��HFϵ��.
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szECRCode               ECR����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstECRAlmSrcList        ��ѯ�����澯Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECRAlarmSrcList
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN],
    IN  QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT ECR_ALARMSRC_INFO_S     *pstECRAlmSrcList
);

/**
* ɾ��ECR�澯Դ, ����ɾ��ECRʱ�Ĳ���; ��֧��HFϵ��.
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   szAlarmSrcCode      ��ɾ���ĸ澯Դ����
* @param [IN]   szECRCode           ECR����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmSrcForECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szAlarmSrcCode[IMOS_CODE_LEN],
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN]
);
/** @} */ /* end of PartI��VM����ECR */

/**
* ��ѯECR�ĸ澯����б�, ����ɾ��ECRʱ�Ĳ���; ��֧��HFϵ��.
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szECRCode               ECR����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstECRAlmOutList        ��ѯ�����澯Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECRAlarmOutList
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN],
    IN  QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT ECR_ALARMOUT_INFO_S     *pstECRAlmOutList
);

/**
* ɾ��ECR�澯���, ����ɾ��ECRʱ�Ĳ���; ��֧��HFϵ��.
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   szAlarmSrcCode              ��ɾ���ĸ澯Դ����
* @param [IN]   szECRCode                   ECR����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmOutForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szAlarmOutCode[IMOS_CODE_LEN],
    IN  CHAR                            szECRCode[IMOS_ECR_CODE_LEN]
);
#if 0
#endif

/***************************************************************************
PartII ECR�豸����
****************************************************************************/
/**
* @PartII ECR�豸����
* @{    ECR�豸����
/**
* �޸�ϵͳʱ��. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       �û���Ϣ
* @param [IN]   CHAR                    szTime[IMOS_TIME_LEN]   �޸ĺ��ʱ�䣬��ʽΪ"YYYY-MM-DD HH:MM:SS"
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - #ERR_AS_GET_TIME_FAIL
* - #ERR_AS_SET_TIME_FAIL
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySystemTime
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szTime[IMOS_TIME_LEN]
);

/**
* ��ȡϵͳʱ��. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       �û���Ϣ
* @param [OUT]  CHAR                    szTime[IMOS_TIME_LEN]   ϵͳʱ�䣬��ʽΪ"YYYY-MM-DD HH:MM:SS"
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - #ERR_AS_GET_TIME_FAIL
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSystemTime
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT CHAR                         szTime[IMOS_TIME_LEN]
);

/**
* ���洢�ı��������������ڴ��洢�ı���������. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RebootECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo
);

/**
* ���洢�ı������ػ������ڴ��洢�ı���������. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShutdownECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo
);

/* begin added by gaoshufeng-gKF0050 for VVD65569,2012.05.08 */
/*begin added by panchen-pKF0016 for ���������ʱ��������,2012.02.02*/
/**
* �����豸�����������( ��ʱ��)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [IN]   SemaOutputInfo          ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfOutSwitchWithTimeForECR
(
    IN  USER_LOGIN_ID_INFO_S              *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S               *pstChannelIndex,
    IN  SEMA_OUTPUT_INFO_WITHTIME_FOR_ECR_S       *pstSemaOutputInfoWithTime
);
/*end added by panchen-pKF0016 for ���������ʱ��������,2012.02.02*/

/*begin added by panchen-pKF0016 for ���������ʱ��������,2012.02.02*/
/**
* ��ѯ�����������Ϣ (��ʱ��)
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [OUT]  SemaInputInfo           �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOutSwitchWithTimeForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT SEMA_OUTPUT_INFO_WITHTIME_FOR_ECR_S     *pstSemaOutputInfo
);
/*end added by panchen-pKF0016 for ���������ʱ��������,2012.02.02*/
/* end added by gaoshufeng-gKF0050 for VVD65569,2012.05.08 */

/**
* ���洢�ı������ָ�Ĭ������, ��Mware��CAPI�ӿ����ʹ��. \n
* ֻ����������ص����ú��豸��ͨ�����룬�����洢, ����ָ�ȱʡֵ;
* ���ڴ��洢�ı��������������øýӿں�Ὣ����ϵͳ����.
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo   �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RestoreECRDefaultConfig
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo
);

/**
* ECR�����������豸������Ϣ, ��֧��HFϵ��. \n
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   pstDeviceBasicInfo �豸������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* 1. �޸����ײ�����ʽ��ҪSDK�û����������豸�Ľӿں��豸������������Ч.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevBasicInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ECR_DEVICE_BASIC_INFO_S *pstDeviceBasicInfo
);

/**
* ECR�����ϲ�ѯ�豸������Ϣ, ��֧��HFϵ��. \n
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [OUT]  pstDeviceBasicInfo �豸������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevBasicInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT	ECR_DEVICE_BASIC_INFO_S *pstDeviceBasicInfo
);

/**
* ECR���������÷�����������Ϣ, ��֧��HFϵ��. \n
* @param [IN]   pstUserLogIDInfo  �û���Ϣ, ֻ��ӵ��ϵͳ����Ȩ�޵��û����Խ��в���
* @param [IN]   pstServerMgrInfo  ������������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* 1. ����������ģʽ���л�������ģʽ�����޸ķ�������Ϣ��ֹͣԭ���������ڽ��е�ʵʱҵ��.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetServerMgrInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ECR_SERVER_MGR_INFO_S       *pstServerMgrInfo
);

/**
* ECR�����ϲ�ѯ������������Ϣ, ��֧��HFϵ��. \n
* @param [IN]   pstUserLogIDInfo  �û���Ϣ, ��Ȩ�޹���, ����Ȩ����SDK�û�����
* @param [OUT]  pstServerMgrInfo  ������������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServerMgrInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT ECR_SERVER_MGR_INFO_S       *pstServerMgrInfo
);

/**
* ���Ӹ澯����(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmType             �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LINKAGE_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��������ȫ�ظ��Ķ�������ע�������е�������������ö��"ͬһ���������ͬһ��������", �������óɹ���������ֻ��
*       �������õĻ�ִ�гɹ�.
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_S          *pstAlarmAction
);


/**
* ɾ���澯����(for ECR&NVR buzzer)
* @param [IN]  pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]  szAlarmSrcCode               �澯Դ����
* @param [IN]  ulAlarmType                  �澯����, ȡֵΪ#AlARM_TYPE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType
);


/**
* �޸ĸ澯������Ϣ(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmType             �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��������ȫ�ظ��Ķ�������ע�������е�������������ö��"ͬһ���������ͬһ��������", �������óɹ���������ֻ��
*       ���ȵ����û�ִ�гɹ�.
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_S          *pstAlarmAction
);


/**
* ��ѯ�澯������Ϣ(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szAlarmSrcCode          �澯Դ����
* @param [IN]   ulAlarmSrcType          �澯����, ȡֵΪ#AlARM_TYPE_E
* @param [OUT]  pstAlarmAction          �澯����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_LINKAGE_NOT_EXIST
* - #ERR_AS_LINKAGE_NUM
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    OUT ALARM_ACTION_FOR_ECR_S          *pstAlarmAction
);

/**
* ��������󶨵���������ĳ��ͨ���� for ECR&NVR
* @param [IN]  pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]  pstVinChnlAndCamInfo         ����������ͨ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��������벻��Ϊ��,�Ҳ��ܰ����ո�
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VINCHNL_BIND_CAMERA_FOR_ECR_S   *pstVinChnlAndCamInfo
);
/** @} */ /* end of PartII:ECR�豸���� */


/** @} *//* end of group ECR33**-HF */

#if 0
#endif
/***************************************************************************
�澯����
****************************************************************************/
/**
* ���Ӹ澯���Ĺ��򣨷�ϵͳԤ�������澯Դ����Ϊ�գ�ϵͳԤ�������澯Դ����Ϊ�գ�
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstRule                     �澯���Ĺ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����������ϵͳԤ�������
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_AddAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_S   *pstRule
);

/**
* ɾ���澯���Ĺ���ϵͳԤ���������ɾ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstRule                     �澯���Ĺ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_DelAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  CHAR                   szRuleCode[IMOS_CODE_LEN]
);

/**
* �޸ĸ澯���Ĺ��򣨷�ϵͳԤ�������澯Դ����Ϊ�գ�ϵͳԤ�������澯Դ����Ϊ�գ�
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstRule                     �澯���Ĺ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_ModifyAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_S  *pstRule
);

/**
* ��ѯ�澯���Ĺ��������Ϣ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode                  �澯���Ĺ������
* @param [OUT]  pstRuleBase                 �澯���Ĺ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szRuleCode[IMOS_CODE_LEN],
    OUT ALARM_SENDING_RULE_BASE_INFO_S  *pstRuleBase
);

/**
* ��ѯ�澯���Ĺ���澯Դ�б����ÿ�β�ѯ#IMOS_ALARM_SEND_SRC_MAXNUM����¼��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode                  �澯���Ĺ������
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstAlarmSrcList             �澯Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ֵĲ�ѯ������#NAME_TYPE[�澯Դ����]
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRuleAlarmSrcList
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szRuleCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S  *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S         *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S           *pstRspPageInfo,
    OUT ALARM_SRC_QUERY_ITEM_S    *pstAlarmSrcList
);

/**
* ��ѯ�澯���Ĺ����û��б����ÿ�β�ѯ#IMOS_ALARM_SEND_USER_MAXNUM����¼��
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode                  �澯���Ĺ������
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstAlarmSrcList             �澯Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ֵĲ�ѯ������#USER_NAME_TYPE[�û�����]
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRuleUserList
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szRuleCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S  *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S         *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S           *pstRspPageInfo,
    OUT USER_QUERY_ITEM_S         *pstUserList
);

/**
* ��ѯ�澯���Ĺ��������ϵͳ�б�
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode                  �澯���Ĺ������
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstThdSysList               ������ϵͳ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ֵĲ�ѯ������#CODE_TYPE[������ϵͳ����], #NAME_TYPE[������ϵͳ����]
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRuleThdSysList
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szRuleCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S  *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S         *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S           *pstRspPageInfo,
    OUT ALARM_SENDING_RULE_THD_SYS_S    *pstThdSysList
);

/**
* ��ѯ�澯���Ĺ����б�
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode                  �澯���Ĺ������
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstAlarmSrcList             �澯���Ĺ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ֵĲ�ѯ������#NAME_TYPE[��������]
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRuleList
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S         *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                  *pstRspPageInfo,
    OUT ALARM_SENDING_RULE_BASE_INFO_S   *pstAlarmSendingRuleList
);

/* Begin add by l01420, 2014-7-10 for �����ֵ��������*/
/**
* ���Ӹ澯���Ĺ���V2
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstRule                     �澯���Ĺ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����������ϵͳԤ�������
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_AddAlarmSendingRuleV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_V2_S     *pstRule
);

/**
* �޸ĸ澯���Ĺ���V2
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstRule                     �澯���Ĺ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 IMOS_ModifyAlarmSendingRuleV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_V2_S     *pstRule
);

/* End add by l01420, 2014-7-10 for �����ֵ��������*/
/**
* ���ö�λ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [IN]   pstLocateInfo           ��λ��Ϣ
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigLocateInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  LOCATE_INFO_S               *pstLocateInfo
);

/**
* ��ѯ��λ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [OUT]  pstLocateInfo           ��λ��Ϣ
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLocateInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT LOCATE_INFO_S               *pstLocateInfo
);

#if 0
#endif

/* Begin: Modified for ������ǿ, by p00232 2012-12-13 */
/***************************************************************************
���ó���
****************************************************************************/
/**
* ���ӳ�����Դ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szOrgCode               ��֯����
* @param [IN]     szSceneName             ��������
* @param [INOUT]  pcSceneCode             ��������
* @param [IN]     ulIsPrivate             �Ƿ�˽��
* @param [IN]     pcContent               ��������
* @param [IN]     ulContentLen            ���������ַ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. pcSceneCode����紫��#IMOS_CODE_LEN���ȵ��ַ�����, �ɽӿڷ���ϵͳ���ɵı���
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddScene
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN      CHAR                        szSceneName[IMOS_NAME_LEN],
    INOUT   CHAR                        *pcSceneCode,
    IN      ULONG_32                       ulIsPrivate,
    IN      CHAR                        *pcContent,
    IN      ULONG_32                       ulContentLen
);

/**
* �޸ĳ�����Դ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szSceneName             ��������
* @param [IN]     szSceneCode             ��������
* @param [IN]     ulIsPrivate             �Ƿ�˽��
* @param [IN]     pcContent               ��������
* @param [IN]     ulContentLen            ���������ַ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyScene
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szSceneCode[IMOS_CODE_LEN],
    IN      CHAR                        szSceneName[IMOS_NAME_LEN],
    IN      ULONG_32                       ulIsPrivate,
    IN      CHAR                        *pcContent,
    IN      ULONG_32                       ulContentLen
);

/**
* ɾ��������Դ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSceneCode             ��������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelScene
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSceneCode[IMOS_CODE_LEN]
);

/**
* ��ѯ����ʾ��Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szSceneCode             ��������
* @param [INOUT]  pcSceneName             ��������
* @param [INOUT]  pulIsPrivate            �Ƿ�˽��
* @param [INOUT]  pcContent               ��������
* @param [INOUT]  pulContentLen           ���������ַ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �����pcContentΪNULLʱ, ֻ������Ӧ���ݵĳ�����Ϣ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScene
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szSceneCode[IMOS_CODE_LEN],
    INOUT   CHAR                        *pcSceneName,
    INOUT   ULONG_32                       *pulIsPrivate,
    INOUT   CHAR                        *pcContent,
    INOUT   ULONG_32                       *pulContentLen
);

/**
* ��ҳ��ѯ�������������б�  \n
* @param [IN]     pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]     pstQueryCondition       ͨ�ò�ѯ����
* - ����NULL
* - ��������:�ݲ�ʵ��
* @param [IN]     pstQueryPageInfo        �����ҳ��Ϣ
* @param [INOUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [INOUT]  pcSceneCodeList         ���������б�
* @param [INOUT]  pcSceneNameList         ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. pcSceneCodeList��#IMOS_CODE_LENΪ��λ;pcSceneNameList��IMOS_NAME_LENΪ��λ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySceneList
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN      QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    INOUT   RSP_PAGE_INFO_S             *pstRspPageInfo,
    INOUT   CHAR                        *pcSceneCodeList,
    INOUT   CHAR                        *pcSceneNameList
);
/* ����CCB����, ������ǿ��ʹ�ýṹ, ƽ̨����ⳡ����Ϣ, ���γ�������; ������ȡ���ⷽʽ���� */

/* End: Modified for ������ǿ, by p00232 2012-12-13 */

/**
* �����ʼ����͵����� \n
* @param [IN]    pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]    pstEmailSendingConfig        Email������ص�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* ��ȡ�ʼ����͵����� \n
* @param [IN]    pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstEmailSendingConfig        Email������ص�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* ���Ͳ����ʼ��� ��֤�ʼ����͵������Ƿ���ȷ \n
* @param [IN]    pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]    pstEmailSendingConfig        Email������ص�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendTestingEmail
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* ���ö���ҵ����������  \n
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       pstSMSSendingConfig     ����ҵ������������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySMSSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SMS_SENDING_CONFIG_S            *pstSMSSendingConfig
);

/**
* ��ȡ����ҵ��������Ϣ����  \n
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]      pstSMSSendingConfig     ����ҵ������������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySMSSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT SMS_SENDING_CONFIG_S            *pstSMSSendingConfig
);

/**
* ���Է��Ͷ��ţ���֤���ŷ��͵������Ƿ���ȷ \n
* @param [IN]    pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]    pstSMSTestSendingConfig      ���Ų��Է�������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendTestingSMS
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  SMS_TEST_SENDING_CONFIG_S    *pstSMSTestSendingConfig
);

#if 0
#endif

/***************************************************************************
���мƻ�V2�汾
****************************************************************************/

/**
* �������мƻ�V2�汾
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstSwitchPlanInfo       ���мƻ���Ϣ
* @param [OUT]  szSwitchPlanCode        ���мƻ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SWITCH_PLAN_INFO_V2_S           *pstSwitchPlanInfo,
    OUT CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);

/**
* �޸����мƻ�V2�汾
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @param [IN]   pstSwitchPlanInfo       ���мƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    IN  SWITCH_PLAN_INFO_V2_S           *pstSwitchPlanInfo
);

/**
* ɾ�����мƻ�V2�汾
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯ���мƻ�V2�汾
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @param [OUT]  pstSwitchPlanInfo       ���мƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    OUT SWITCH_PLAN_INFO_V2_S              *pstSwitchPlanInfo
);

/**
* ��ѯ���мƻ��б�V2�汾�����Ը��������飬Ҳ���Բ����еġ�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstSwitchPlanList       ���мƻ��б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.����޲�ѯ����,ָ��pstQueryCondition����ΪNULL
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchPlanListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SWITCH_PLAN_QUERY_ITEM_S    *pstSwitchPlanList
);

/**
* ������Ϊ������Ϣ
* @param [IN]  pstUserLogIDInfo     �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex      �豸ͨ��������Ϣ
* @param [IN]  pstBehaviorAnalyse   ��Ϊ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigBehaviorAnalyse
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  IMOS_BEHAVIOR_ANALYSE_INFO_S    *pstBehaviorAnalyse
);

/**
* ��ѯ��Ϊ������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex     �豸ͨ��������Ϣ
* @param [OUT]  pstBehaviorAnalyse  ��Ϊ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBehaviorAnalyse
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT IMOS_BEHAVIOR_ANALYSE_INFO_S    *pstBehaviorAnalyse
);

#if 0
#endif

/*************************************************************************************
�ʲ���Ϣ���ã��������ӣ��޸ģ�ɾ����
**************************************************************************************/
/**
* �����ʲ�
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szOrgCode               �ʲ�������֯����
* @param [IN]     pstAssetInfo            �ʲ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAsset
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    INOUT   ASSET_INFO_S                *pstAssetInfo
);

/**
* �޸��ʲ�
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstAssetInfo           �ʲ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAsset
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ASSET_INFO_S               *pstAssetInfo
);


/**
* ɾ���ʲ�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szAssetCode             �ʲ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAsset
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szAssetCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�ʲ�
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   ulQueryType          ��ѯ��ʽ��ȡֵ#ASSET_QUERY_TYPE_E
* @param [IN]   szQryCode            ��ѯ����
* @param [OUT]  pstAssetList         �ʲ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰ֧�ְ��豸����/�ʲ���Ų�ѯ�ʲ���Ϣ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAsset
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulQueryType,
    IN   CHAR                       szQryCode[IMOS_CODE_LEN],
    OUT  ASSET_INFO_S               *pstAssetInfo
);

/**
* ��ѯ��֯���ʲ���Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAssetList               �ʲ���Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯�������ʲ�(��������֯)
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ�"�ʲ�����"ģ����ѯ:#NAME_TYPE
* - 3.֧�ְ��ʲ�������ģ����ѯ:��Χ#ASSET_TYPE----#ASSET_PRODEALER
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�ʲ�����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(�ʲ�����),#CODE_TYPE(�ʲ�����)
* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAssetList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ASSET_INFO_S                    *pstAssetList
);

/**
* ��ѯ�ʲ�ͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode               ��֯����
* @param [IN]       ulClassification        ͳ�Ʒ��࣬ȡֵ#STATISTIC_CLASSIFICATION_TYPE_E��Ĭ��Ϊ���ʲ����ͷ���ͳ��
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstAssetStatistic       �ʲ�ͳ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 2.֧�ְ��ʲ������Բ�ѯ:#ASSET_TYPE,#ASSET_MANUFACTURE,#ASSET_PURCHASE_TIME,#ASSET_WARRANT_TIME,
                           #ASSET_INSTALL_TIME,#ASSET_PRODEALER
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAssetStatistic
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szOrgCode[IMOS_CODE_LEN],
    IN    ULONG_32                          ulClassification,
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   ASSET_STATISTIC_S              *pstAssetStatistic
);

/**
* �����豸�ʲ���¼�����
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   ulBindPolicy            ��¼����ԣ�ȡֵ#DEVASSET_BINDPOLICY_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevAssetBindPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                       ulBindPolicy
);

/**
* ��ѯ�豸�ʲ���¼�����
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [OUT]  pulBindPolicy          ��¼����ԣ�ȡֵ#DEVASSET_BINDPOLICY_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QryDevAssetBindPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  ULONG_32                      *pulBindPolicy
);

/**
* ��ѯ��֯�¹����豸�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstFaultDevList            �����豸��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯�����й����豸�б�(��������֯)
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ�"�豸����"ģ����ѯ:#NAME_TYPE
* - 3.֧�ְ��豸����#DEV_TYPE������ѯ��,
            ��������#FAULT_TYPE������ѯ��ȡֵ#IMOS_DEV_FAULT_STATUS_E
            ����ͳ��ʱ��#FAULT_STAT_TIME������ѯ
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�豸����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(�豸����),#CODE_TYPE(�豸����)
* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFaultDevList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT FAULT_DEV_INFO_S                *pstFaultDevList
);

/**
* ��ѯ�����豸ͳ��ʱ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode               ��֯����
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pcStatTimes            ����ͳ��ʱ���б�(��IMOS_TIME_LENΪ��λ)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 2.֧�ְ��豸���Ͳ�ѯ#DEV_TYPE
* - 3.֧�ְ�ͳ��ʱ���ѯ#FAULT_STAT_TIME
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFaultDevStatTimes
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szOrgCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   CHAR                           *pcStatTimes
);

/**
* ��ѯ�����豸ͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode               ��֯����
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstFaultStatistic       ����ͳ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 2.֧�ְ��豸���Ͳ�ѯ#DEV_TYPE
* - 3.֧�ְ�ͳ��ʱ���ѯ#FAULT_STAT_TIME
* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFaultDevStatistic
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szOrgCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   FAULT_STATISTIC_S              *pstFaultStatistic
);

/**
* �����������ļ���Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szParentDomainCode      �������
* @param [IN]   szSubDomainCode         �������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateTopologyInfo
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szParentDomainCode[IMOS_CODE_LEN],
    IN  CHAR                       szSubDomainCode[IMOS_CODE_LEN]
);

/**
* ��ѯ������֮���ҵ����Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szParentDomainCode      �������
* @param [IN]   szSubDomainCode         �������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceInfoBetweenDomain
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szParentDomainCode[IMOS_CODE_LEN],
    IN  CHAR                       szSubDomainCode[IMOS_CODE_LEN]
);

/**
* �ֹ�ͬ��ҵ��ͳ������
* @param [IN]   pstUserLogIDInfo      �û���Ϣ
* @param [IN]   pstSyncSrvInfo        ͬ��ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰ֧��ȫ���ʲ�/�����豸ͳ�������ֶ�ͬ��
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualSyncStatData
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   SYNC_SERVICE_INFO          *pstSyncSrvInfo
);

/**
* ���ÿ���λ
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szCamCode           ����ͷ����
* @param [IN]   pstGuardPos         ����λ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰ�˽ӿ�ֻ֧�ֶ�������������ÿ���λ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetGuardPosition
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_CODE_LEN],
    IN  GUARD_POSITION_INFO_S   *pstGuardPos
);

/**
* ɾ������λ
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szCamCode           ����ͷ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰ�˽ӿ�ֻ֧�ֶ����������ɾ������λ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGuardPosition
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* ��ѯ��������û���Ϣ
* @param [IN]   *pstQueryCondition        ͨ�ò�ѯ����
* @param [OUT]  pstUserPasswordInfo       ��������û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:#USER_CODE_TYPE��#USER_NAME_TYPE��#USER_DESC
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserInfoByCondition
(
    IN   USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN   COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT  USER_INFO_PASSWORD_S        *pstUserPasswordInfo
);

/**
* ��ѯ��֯�¾���ĳ��Ȩ�޵��û��б� \n
* ������������ʱ, Ĭ�ϰ��û���������
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   bIsQuerySub         �Ƿ������֯
* @param [IN]   szResCode           ��Դ����(ϵͳȨ�޿�Ϊ��'\0')
* @param [IN]   ulResType           ��Դ����(��ϵͳȨ�޲�ʱ��0)
* @param [IN]   ulAuthorityName     Ȩ����(��bHasAnyAuthΪBOOL_TRUEʱ������)
* @param [IN]   bHasAnyAuth         �Ƿ�ֻҪ�߱���һȨ�޼���
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��ѯ����������Ϊ0, ������ֱ�Ӵ�NULL;֧�ֵĲ�ѯ��������:#USER_NAME_TYPE[�û�����]��#USER_CODE_TYPE[�û�����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstUserList         �û���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.����һȨ�޺Ͱ���ԴȨ�޲��ݲ�֧��, Ŀǰֻ֧�ְ�ָ����ϵͳȨ�޲�, ��Դ������0
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHasAuthUserList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  BOOL_T                          bIsQuerySub,
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulResType,
    IN  ULONG_32                           ulAuthorityName,
    IN  BOOL_T                          bHasAnyAuth,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT USER_QUERY_ITEM_S               *pstUserList
);

/**
* ���������¼� \n
* @param [IN]    pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]    szDeviceCode       �豸����
* @param [IN]    ulAlarmType        �澯����(Ŀǰ��֧��#AlARM_TYPE_IMPERATIVE_EVENT)
* @param [IN]    ulXmlLen           xml�ַ�������
* @param [IN]    pcXml              xml�ַ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendImperativeEvent
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szDeviceCode[IMOS_CODE_LEN],
    IN  ULONG_32                ulAlarmType,
    IN  ULONG_32                ulXmlLen,
    IN  CHAR                 *pcXml
);

/**
* ˢ��������洢����
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szCamCode               ���������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RefreshStoreIdx
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* ���ü�����������Ϣ
* @param [IN] pstUserLogIDInfo �û���Ϣ��ʶ
* @param [IN] szScrCode        ����������
* @param [IN] pstSplitScrInfo  ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DEVICE_OFFLINE
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSplitScrInfo
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR                 szScrCode[IMOS_CODE_LEN],
    IN SPLIT_SCR_INFO_S     *pstSplitScrInfo
);

/**
* ��ѯ������������Ϣ
* @param [IN]  pstUserLogIDInfo �û���Ϣ��ʶ
* @param [IN]  szScrCode        ����������
* @param [OUT] pstSplitScrInfo  ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DEVICE_OFFLINE
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySplitScrInfo
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szScrCode[IMOS_CODE_LEN],
    OUT SPLIT_SCR_INFO_S     *pstSplitScrInfo
);

/* Begin: Added by gaoshufeng(00762), 2013-5-15 for DCV3R5ƴ���л� */
/**
* ���ü�����ƴ����Ϣ
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN] CHAR                  szDevCode[IMOS_CODE_LEN]    ����������
* @param [IN] DEVINST_S             *pstDevInst                 ƴ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevInst
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szDevCode[IMOS_CODE_LEN],
    IN  DEVINST_S            *pstDevInst
);

/**
* ��ѯ������ƴ����Ϣ
* @param [IN]    USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN]    CHAR                   szDevCode[IMOS_CODE_LEN]    ����������
* @param [INOUT] DEVINST_S              *pstDevInst                 ƴ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ѯƴ����Ϣ��pstDevInst->ulInstType����10����ѯģ��������Ϣ����11��
* - 2. ��ѯ������Ƕ���䱶����21��
* - 3. ��ѯģ������ʱ��pstDevInst->szParam2�������ͨ����
* - 4. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevInst
(
    IN    USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN    CHAR                 szDevCode[IMOS_CODE_LEN],
    INOUT DEVINST_S            *pstDevInst
);
/* End: Added by gaoshufeng(00762), 2013-5-15 for DCV3R5ƴ���л� */

/**
* �����Դ���ղؼ� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResType                   ��Դ����
* @param [IN]   szResCode                   ��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddResToFavorite
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulResType,
    IN  CHAR                        szResCode[IMOS_CODE_LEN]
);

/**
* ���ղؼ�ɾ����Դ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResType                   ��Դ����
* @param [IN]   szResCode                   ��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResFromFavorite
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulResType,
    IN  CHAR                        szResCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�ղؼ���Դ�б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstResList              �ղؼ�����Դ�б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFavoriteResList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT RES_ITEM_V2_S               *pstResList
);

/**
* ���ӵ�����EC \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   pstThirdPartyECInfo          ������EC��Ϣ
* @param [IN]   pstVINBindCamBaseInfo        ����������ͨ���Ļ�����Ϣ
* @param [IN]   pstVINFullVarietyElement     ��Ƶͨ��ȫ���䳤Ԫ�ؽṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddThirdPartyEC
(
    IN USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN THIRDPARTY_EC_S                *pstThirdPartyECInfo,
    IN VINCHNL_BIND_CAMERA_BASE_S     *pstVINBindCamBaseInfo,
    IN VINCHNL_FULL_VARIETY_ELEMENT_S *pstVINFullVarietyElement
);

/**
* �޸ĵ�����EC \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   pstThirdPartyECInfo          ������EC��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyThirdPartyEC
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN THIRDPARTY_EC_S      *pstThirdPartyECInfo
);

/**
* ɾ��������EC \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   szThirdPartyIPCCode          ������IPC����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelThirdPartyEC
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR                 szThirdPartyIPCCode[IMOS_CODE_LEN]
);

/**
* ��ѯһ��������EC�ľ�����Ϣ \n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   szThirdPartyIPCCode          ������IPC����
* @param [OUT]  pstThirdPartyECInfo          ������EC��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyEC
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szThirdPartyIPCCode[IMOS_CODE_LEN],
    OUT THIRDPARTY_EC_S      *pstThirdPartyECInfo
);

/**
* ��ѯ������EC�б�
* �����ѯ����ʱ,������,Ĭ������(EC��������)
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯�����
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����(��ΪNULL, ��������: #NAME_TYPE[IPC����];)
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstThirdPartyECInfoList     ������EC�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyECListByOrg
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN CHAR                     szOrgCode[IMOS_CODE_LEN],
    IN COMMON_QUERY_CONDITION_S *pstQueryCondition,
    IN QUERY_PAGE_INFO_S        *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT THIRDPARTY_EC_S         *pstThirdPartyECInfoList
);

/**
* ��Դͳ��������ѯ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   ulResType                   ��Դ���ͣ�ȡֵΪ#IMOS_TYPE_CAMERA��#IMOS_TYPE_GUARD_TOUR_RESOURCE��#IMOS_TYPE_ALARM_SOURCE��#IMOS_TYPE_ALARM_OUTPUT��#IMOS_TYPE_SALVO_RESOURCE��#IMOS_TYPE_GROUP_SWITCH_RESOURCE��#IMOS_TYPE_SCENE��#IMOS_TYPE_MAP,
* #IMOS_TYPE_BROADCAST_GROUP
* @param [IN]   ulResStatus                 ��Դ״̬��ֻ��#IMOS_TYPE_CAMERA��Ч��ȡֵΪ#IMOS_DEV_FAULT_STATUS_E, ��ȡֵΪ#IMOS_DEV_FAULT_STATUS_ALLʱ��ʾ����״̬
* @param [IN]   bQuerySubOrg                �Ƿ��ѯ����֯
* @param [OUT]  pulResNum                   ��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceStatistics
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  CHAR                           szOrgCode[IMOS_CODE_LEN],
    IN  ULONG_32                          ulResType,
    IN  ULONG_32                          ulResStatus,
    IN  BOOL_T                         bQuerySubOrg,
    OUT ULONG_32                          *pulResNum
);



/**
* ������ı��ô洢¼����� \n
* @param [IN]   pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   bExtDomainDev           �Ƿ����������͵������
* @param [IN]   pstSDKRecQueryInfo      �طż�����Ϣ���ݽṹ�����������������szCamCodeΪ������������
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstSDKRecordFileInfo    ¼���ļ���Ϣ���ݽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ѯʱ���Ȳ��ܴ���24Сʱ������¼�����������ʱ���ʽΪ��"%Y-%m-%d %H:%M:%S"��ʽ ����Ϣ�����޶�Ϊ24�ַ�
* - 2. �ýӿڽ�֧��VMƽ̨
* - 3. �����IMOS_SlaveRecordRetrieval���ýӿڵ��������ڷ��ص�¼���ļ�������Ϊ#IMOS_FILE_NAME_LEN_V2
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SlaveRecordRetrievalV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BOOL_T                      bExtDomainDev,
    IN  REC_QUERY_INFO_S            *pstSDKRecQueryInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT RECORD_FILE_INFO_V2_S       *pstSDKRecordFileInfo
);

/**
* ��ȡ������ı��ô洢¼���URL��ϢV2 \n
* @param[IN]    pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   bExtDomainDev               �Ƿ����������͵������
* @param[IN]    pstSDKGetUrlInfo            ��ȡURL������Ϣ���ݽṹ�����������������szCamCodeΪ������������
* @param[OUT]    pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* - 2. ��Ƚ�IMOS_GetSlaveRecordFileURL���ýӿڵ��������������·���¼���ļ�������Ϊ#IMOS_FILE_NAME_LEN_V2
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSlaveRecordFileURLV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BOOL_T                      bExtDomainDev,
    IN  GET_URL_INFO_V2_S           *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* ��ѯ��������ԵĽӿ� \n
* @param [IN]  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]  CHAR                         szCamCode[IMOS_CODE_LEN]    ���������
* @param [OUT] ULONG		                *pulAttribute               �����������Ϣ��0�������������2����DVR���������������
* @return �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ����ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamAttribute
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szCamCode[IMOS_CODE_LEN],
    OUT ULONG_32                            *pulAttribute
);

/**
* ֪ͨDC������Ϣ����ӿ�
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN] CHAR                  szDevCode[IMOS_CODE_LEN]    �����������DC ����
* @param [IN] DEVINST_S             *pstDCDCCtrlInfo            DC������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_NotifyDCCtrlInfoProc
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szDevCode[IMOS_CODE_LEN],
    IN  DEVINST_S            *pstDCDCCtrlInfo
);


#if 0
#endif

/**
* ����ϵͳ������Ϣ
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       ulSysParamNum           ϵͳ��������, ���Ϊ#IMOS_SYS_PARAM_MAX_NUM
* @param [IN][OUT]  pstSysParamListInfos    ϵͳ�����б���Ϣ, ������Ϣ�������ͱ�����д
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSystemParamInfos
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      ULONG_32                   ulSysParamNum,
    INOUT   IMOS_SYS_PARAM_INFO_S   *pstSysParamList
);

/**
* ��ѯϵͳ������Ϣ
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       ulSysParamNum           ϵͳ��������, ���Ϊ#IMOS_SYS_PARAM_MAX_NUM
* @param [IN][OUT]  pstSysParamListInfos    ϵͳ�����б���Ϣ, ������Ϣ�������ͱ�����д
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySystemParamInfos
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      ULONG_32                   ulSysParamNum,
    INOUT   IMOS_SYS_PARAM_INFO_S   *pstSysParamList
);

/**
* ��ѯϵͳʱ�䣬CPU���ڴ�ʹ���ʵ���Ϣ
* @param [IN]       pstUserLogIDInfo     �û���¼ID��Ϣ��ʶ
* @param [IN]       ulQuerySysInfoNum    ��ѯ��Ϣ���� (С��#QUERY_SYS_INFO_NAME_MAX)
* @param [IN][OUT]  pstQuerySysInfoList  ��ѯϵͳ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysInfo
(
    IN     USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN     ULONG_32                 ulQuerySysInfoNum,
    INOUT  QUERY_SYS_INFO_S      *pstQuerySysInfoList
);

/**
* ��ѯ��֯���豸�Ĺ�����ϸ��Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [IN]   pstQueryTimeSlice          ��ѯʱ��Ƭ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDevFaultDetailList      �豸������ϸ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯�����й����豸�б�(��������֯)
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ�"�豸����"ģ����ѯ:#NAME_TYPE
* - 4.֧�ְ�"�豸����"��ȷ��ѯ:#CODE_TYPE
* - 5.֧�ְ��豸����#DEV_TYPE������ѯ��,
            ��������#FAULT_TYPE������ѯ��ȡֵ#IMOS_DEV_FAULT_STATUS_E
            ����ͳ��ʱ��#FAULT_STAT_TIME������ѯ
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�豸����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(�豸����),#CODE_TYPE(�豸����),���Ϸ���ʱ�䣬���ϻָ�ʱ�䣬����ʱ����������������
* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevFaultDetailList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    IN  QUERY_TIME_SLICE_S              *pstQueryTimeSlice,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT DEV_FAULT_DETAIL_S              *pstDevFaultDetailList
);

/**
* ��ѯ�豸�Ĺ�����ϸ��Ϣͳ��
* @param [IN]       pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode                   ��֯����
* @param [IN]       pstQueryCondition           ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo            �����ҳ��Ϣ
* @param [IN]       pstQueryTimeSlice           ��ѯʱ��Ƭ��Ϣ
* @param [OUT]      pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstDevFaultDetailStat       �豸������ϸ��Ϣͳ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 2.֧�ְ��豸���Ͳ�ѯ#DEV_TYPE
* - 3.֧�ְ�"�豸����"��ȷ��ѯ:#CODE_TYPE
* - 3.֧�ְ����Ϸ���ʱ��ͽ���ʱ���ѯ

* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�豸����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(�豸����),#CODE_TYPE(�豸����),���Ϸ���ʱ�䣬���ϻָ�ʱ�䣬����ʱ����������������

* - ����
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevFaultDetailStatistic
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szOrgCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    IN    QUERY_TIME_SLICE_S             *pstQueryTimeSlice,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   DEV_FAULT_DETAIL_STAT_S        *pstDevFaultDetailStat
);

/**
* ��ѯ�豸�Ĺ���Ƶ��ͳ�ƿ���
* @param [IN]       pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [OUT]      pulDevFaultStat       �豸�Ĺ���Ƶ��ͳ�ƿ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevFaultDetailStatisticGate
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    OUT   ULONG_32                          *pulDevFaultStat
);

/**
* �����豸�Ĺ���Ƶ��ͳ�ƿ���
* @param [IN]       pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]       ulDevFaultStat              �豸�Ĺ���Ƶ��ͳ�ƿ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevFaultDetailStatisticGate
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    ULONG_32                          ulDevFaultStat
);

/**
* ��ѯ��Դ·����������Դ��Ϣ�� \n
* @param [IN]       pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode		    ������֯����
* @param [IN]       szResCode			��Դ����
* @param [IN]       ulResType			��Դ����
* @param [IN][OUT]  pulTierNum		    ��Դ·������
* @param [OUT]      pstResList		    ��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ���ص��б���Ҫ���մӶ�����֯(������Root�ڵ�)�����ѯ��Դ�����˳������
* - 2. ����Դ����Ϊ��������������(��֯)ʱ, ulResTypeͳһ��#IMOS_TYPE_ORG
* - 3. ����������Դ����Ϊ��֯��������֯�������Ϊ��'\0'����������NULL
* - 4. ��Դ�����������������ֵ#IMOS_RES_TREE_LEVEL
* - 5. ������Դ��Ϣ�ṹ���ײͲ���(ulDevEncodeSet)��Ч������������Ч������Դ�������
* - 6. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResPathWithInfo
(
    IN    USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN    CHAR                       szOrgCode[IMOS_CODE_LEN],
    IN    CHAR                       szResCode[IMOS_CODE_LEN],
    IN    ULONG_32                      ulResType,
    INOUT ULONG_32                      *pulTierNum,
    OUT   RES_ITEM_V2_S              *pstResList
);

/**
* ��ȡ��Դ��·����Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�ڵ����
* @param [IN]   szResCode           ��Դ����
* @param [IN]   ulResType           ��Դ���ͣ�ȡֵΪ#IMOS_TYPE_E
* @param [OUT]  szResPath           ��Դ����·����Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. �����֯����δ��ֵ������Դ������ʱ������������һ������·�������û�л����򷵻���Դԭʼ����λ������·��
* - 2. ����Դ����Ϊ��������������(��֯)ʱ, ulResTypeͳһ��#IMOS_TYPE_ORG
* - 3. ·���в����������Root�ڵ㣬��������Դ����
* - 4. ���ص�·���и�����֯ͨ��" >> "���ӣ��磺���� >> �㽭ʡ >> ������ >> ������ >> �����ɳ���
* - 5. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourcePath
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulResType,
    OUT CHAR                            szResPath[IMOS_RES_PATH_LEN]
);

/**
* ��ȡ��Դ��������� \n
* @param [IN]     pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]     szOrgCode           ����Դ��֯����
* @param [IN]     szResCode           ��Դ����
* @param [IN]     ulResType           ��Դ���ͣ�ȡֵΪ#IMOS_TYPE_E
* @param [OUT]    pulOrderNumber      ��Դ�������ֵ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����Դ����Ϊ�����֯ʱ������Դ��֯��������Ϊ��
* - 2. ����Դ����Ϊ��������������(��֯)ʱ, ulResTypeͳһ��#IMOS_TYPE_ORG
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceOrderNumber
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szOrgCode[IMOS_CODE_LEN],
    IN  CHAR                                szResCode[IMOS_CODE_LEN],
    IN  ULONG_32                               ulResType,
    OUT ULONG_32                               *pulOrderNumber
);

/**
* �޸���Դ��������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ����Դ��֯����
* @param [IN]   szResCode           ��Դ����
* @param [IN]   ulResType           ��Դ���ͣ�ȡֵΪ#IMOS_TYPE_E
* @param [IN]   ulOrderNumber       ��Դ�������ֵ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����Դ����Ϊ�����֯ʱ������Դ��֯��������Ϊ��
* - 2. ����Դ����Ϊ��������������(��֯)ʱ, ulResTypeͳһ��#IMOS_TYPE_ORG
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyResourceOrderNumber
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szOrgCode[IMOS_CODE_LEN],
    IN  CHAR                                szResCode[IMOS_CODE_LEN],
    IN  ULONG_32                               ulResType,
    IN  ULONG_32                               ulOrderNumber
);

/**
* ��ѯ�澯�����¼
* �����ѯ����ʱ,������,��Ĭ������(ִ��ʱ������)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szEventRecordCode       �澯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;��������:#USER_NAME_TYPE[�û�����];#OPER_IP[IP��ַ];#OPER_TYPE[��������];#OPER_TIME[����ʱ��])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstAlarmRecordInfoList  �澯��¼��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmRecordInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szEventRecordCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALARM_RECORD_INFO_S         *pstAlarmRecordInfoList
);

/**
* �޸�Ԥ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstActionPlanInfo       Ԥ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ͨ��Ԥ����֧��ת��ԭ�澯�Ͳ����¸澯������������ͨ��Ԥ��������ִ�в���ֻ�����Զ�
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyActionPlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ACTION_PLAN_INFO_S          *pstActionPlanInfo
);

/**
* ɾ��Ԥ��
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szActionPlanCode    Ԥ������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelActionPlan
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szActionPlanCode[IMOS_CODE_LEN]
);

/**
* ��ѯԤ���б�
* �����ѯ����ʱ,������,��Ĭ������(Ԥ����������)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;��������:#NAME_TYPE[Ԥ������];#TYPE_ACTION_PLAN[Ԥ������])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstActionPlanList       Ԥ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryActionPlanList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ACTION_PLAN_BASE_INFO_S     *pstActionPlanList
);

/**
* ��ѯ�������б�
* �����ѯ����ʱ,������,��Ĭ������(������ID����)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   ulActionPlanType        Ԥ�����ͣ�ȡֵΪ#ACTION_PLAN_TYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;��������:#NAME_TYPE[����������];#TRIGGER_ID[������ID])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTriggerList          �������б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTriggerList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulActionPlanType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TASK_TRIGGER_INFO_S         *pstTriggerList
);

/**
* ��������\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szEventRecordCode   �澯����
* @param [IN]   ulTaskNum           ������Ŀ
* @param [IN]   pstPlanTaskInfoList ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DealWithTask
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szEventRecordCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulTaskNum,
    IN  PLAN_TASK_BASE_INFO_S   *pstPlanTaskInfoList
);

/**
* ������������ȷ�ϸ澯����ԭ�Ƚӿڣ�����������ʹ�ô˽ӿڣ�\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szEventRecordCode   �澯����
* @param [IN]   ulTriggerID         ������ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DealWithTrigger
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szEventRecordCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulTriggerID
);

/**
* ���ݸ澯�����ѯ�������б�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szEventRecordCode       �澯����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstTaskTriggerList      ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmTriggerList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szEventRecordCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TASK_TRIGGER_INFO_S         *pstTaskTriggerList
);

/**
* ���ݸ澯�����ѯ�����б�
* @param [IN]       pstUserLogIDInfo   �û���Ϣ
* @param [IN]       szEventRecordCode  �澯����
* @param [IN][OUT]  pulTaskNum         ������(��ν���Ϊ#IMOS_MAX_TASK_NUM)
* @param [OUT]      pstTaskInfoList    ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmTaskInfoList
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szEventRecordCode[IMOS_CODE_LEN],
    INOUT ULONG_32                 *pulTaskNum,
    OUT   PLAN_TASK_BASE_INFO_S *pstTaskInfoList
);

/**
* ����Ԥ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstActionPlanInfo       Ԥ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ͨ��Ԥ����֧��ת��ԭ�澯�Ͳ����¸澯������������ͨ��Ԥ��������ִ�в���ֻ�����Զ�
*       Ԥ�����봫��Ϊ��Чֵ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddActionPlan
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR                    szOrgCode[IMOS_CODE_LEN],
    IN      ACTION_PLAN_INFO_S      *pstActionPlanInfo
);

/**
* ��ѯԤ��
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szActionPlanCode    Ԥ������
* @param [OUT]  pstActionPlanInfo   Ԥ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryActionPlan
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szActionPlanCode[IMOS_CODE_LEN],
    OUT   ACTION_PLAN_INFO_S    *pstActionPlanInfo
);

/**
* ����Ԥ��
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szActionPlanCode    Ԥ������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartActionPlan
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szActionPlanCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* �û�����/����˫�������Խ� \n
* @param [IN]   pstOperUserInfo      �����û���Ϣ
* @param [IN]   pstDstInfo           Ŀ����Ϣ
* @param [IN]   ulVocTalkApplySeq    �����Խ��������кţ����з���������ʱ��д
* @param [IN]   ulSrvType            ����ҵ�����ͣ�ȡֵ�μ�#SRV_TYPE_E
* @param [IN]   ulOperateCode        ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E��
*     �����û���д#USER_OPERATE_SERVICE��
*     �����û���д#CALLEE_USER_OPERATE_SERVICE
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartUserVoiceTalk
(
    IN  USER_LOGIN_ID_INFO_S            *pstOperUserInfo,
    IN  VOC_SRV_DST_INFO_S              *pstDstInfo,
    IN  ULONG_32                            ulVocTalkApplySeq,
    IN  ULONG_32                            ulSrvType,
    IN  ULONG_32                            ulOperateCode
);

/**
* �û�ֹͣ/�ܾ�˫�������Խ� \n
* @param [IN]   pstOperUserInfo      �����û���Ϣ
* @param [IN]   pstDstInfo           Ŀ���û���Ϣ
* @param [IN]   ulVocTalkApplySeq    �����Խ��������кţ����з���д
* @param [IN]   ulOperateCode        ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E��
*     �����û���д#USER_OPERATE_SERVICE��
*     �����û���д#CALLEE_USER_OPERATE_SERVICE,
*     ��������û���֧�ִ�ҵ��Ŀ���д#CALLEE_NOT_SUPPORT_SERVICE
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopUserVoiceTalk
(
    IN  USER_LOGIN_ID_INFO_S            *pstOperUserInfo,
    IN  VOC_SRV_DST_INFO_S              *pstDstInfo,
    IN  ULONG_32                            ulVocTalkApplySeq,
    IN  ULONG_32                            ulOperateCode
);

/**
* ��ѯ����ҵ����Ϣ \n
* @param [IN]   pstOperUserInfo     �����û���Ϣ
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����, ֻ�������㲥������
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ, ֻ�������㲥������
* @param [OUT]  pstRspPageInfo      ���ط�ҳ��Ϣ
* @param [OUT]  pstRecordInfo       ����������¼��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserVoiceSrvInfo
(
    IN   USER_LOGIN_ID_INFO_S        *pstSrcUserInfo,
    IN   COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN   QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT  VOCSRV_RECORD_INFO_S        *pstVocRecordInfo
);

/**
* �û�����/���������㲥 \n
* @param [IN]       pstOperUserInfo      �����û���Ϣ
* @param [IN]       ulVocBrdApplySeq     �����㲥�������кţ����з���������ʱ��д
* @param [IN]       ulSrvType            ����ҵ�����ͣ�ȡֵ�μ�#SRV_TYPE_E
* @param [IN]       ulOperateCode        ����ԭ����
* @param [IN]       ulVocBrdUnitNum      �㲥��Ԫ����
* @param [IN][OUT]  pstVocBrdUnit        �����㲥��Ԫ�б���Ϊ����ʱ����д״̬
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E��
*     �����û���д#USER_OPERATE_SERVICE��
*     �����û���д#CALLEE_USER_OPERATE_SERVICE
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartUserVoiceBrd
(
    IN      USER_LOGIN_ID_INFO_S            *pstOperUserInfo,
    IN      ULONG_32                            ulVocBrdApplySeq,
    IN      ULONG_32                            ulSrvType,
    IN      ULONG_32                            ulOperateCode,
    IN      ULONG_32                            ulVocBrdUnitNum,
    INOUT   VOCSRV_RECORD_INFO_S            *pstVocBrdUnit
);

/**
* �û�ֹͣ/�ܾ������㲥 \n
* @param [IN]       pstOperUserInfo      �����û���Ϣ
* @param [IN]       ulVocBrdApplySeq     �����㲥�������кţ����з�ֹͣ/�ܾ�����ʱ��д
* @param [IN]       ulOperateCode        ����ԭ����
* @param [IN]       ulVocBrdUnitNum      �㲥��Ԫ����
* @param [IN][OUT]  pstVocBrdUnit        �����㲥��Ԫ�б���Ϊ����ʱ����д״̬
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E��
*     �����û���д#USER_OPERATE_SERVICE��
*     �����û���д#CALLEE_USER_OPERATE_SERVICE
*     ��������û���֧�ִ�ҵ��Ŀ���д#CALLEE_NOT_SUPPORT_SERVICE
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopUserVoiceBrd
(
    IN      USER_LOGIN_ID_INFO_S            *pstOperUserInfo,
    IN      ULONG_32                            ulVocBrdApplySeq,
    IN      ULONG_32                            ulOperateCode,
    IN      ULONG_32                            ulVocBrdUnitNum,
    INOUT   VOCSRV_RECORD_INFO_S            *pstVocBrdUnit
);

/**
* ������֯�Զ������ʶ��Ϣ
* @param [IN] pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] pstAutoShareInfo �Զ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAutoShareOrg
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN EX_AUTO_SHARE_INFO_S *pstAutoShareInfo
);

/**
* ��ѯ��֯�Զ�������Ϣ
* @param [IN] pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] szExDomainCode �������
* @param [IN] szOrgCode ��֯����
* @param [OUT] pstAutoShareInfo �Զ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAutoShareOrg
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR szExDomainCode[IMOS_CODE_LEN],
    IN CHAR szOrgCode[IMOS_CODE_LEN],
    OUT EX_AUTO_SHARE_INFO_S *pstAutoShareInfo
);

#if 0
#endif

/**
* ��ѯδ����ɹ���Դ��¼
* @param [IN]   pstUserLogIDInfo         �û���Ϣ
* @param [IN]   szExDomainCode           �������
* @param [IN]   pstQueryCondition        ��ѯ����
* @param [IN]   pstQueryPageInfo         �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo           ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstShareUnsucceedResList δ����ɹ���Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰ���˲�ѯ����֧����Դ����(#RES_TYPE)�ͽ����(#RESULT_CODE)��֧�ְ���Դ�������������
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareUnsucceedRes
(
    IN     USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN     CHAR                      szExDomainCode[IMOS_CODE_LEN],
    IN     COMMON_QUERY_CONDITION_S *pstQueryCondition,
    IN     QUERY_PAGE_INFO_S        *pstQueryPageInfo,
    OUT    RSP_PAGE_INFO_S          *pstRspPageInfo,
    OUT    SHARE_UNSUCCEED_RES_S    *pstShareUnsucceedResList
);

/**
* ɾ��δ����ɹ���Դ��¼
* @param [IN]   pstUserLogIDInfo         �û���Ϣ
* @param [IN]   szExDomainCode           �������
* @param [IN]   ulDelResNum              ��ɾ����¼��Ŀ
* @param [IN]   pstShareUnsucceedResList δ����ɹ���Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ulDelResNumΪ0��ʾɾ����������δ����ɹ���¼
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelShareUnsucceedRes
(
    IN     USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN     CHAR                      szExDomainCode[IMOS_CODE_LEN],
    IN     ULONG_32                     ulDelResNum,
    IN     SHARE_UNSUCCEED_RES_S    *pstShareUnsucceedResList
);


/* Begin add by z07291 for VVD64632 */
/**
* �޸Ĺ���������������Ϣ(Ŀǰֻ�о�γ����Ϣ)
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯�ڵ����
* @param [IN]   szExDomainCode              �������
* @param [IN]   pstCamInfo                  �������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyShareCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  CAMERA_INFO_S                   *pstCamInfo
);

/**
* ¼�����(V2) \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKRecQueryInfo      �طż�����Ϣ���ݽṹ
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstSDKRecordFileInfo    ¼���ļ���Ϣ���ݽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ѯʱ���Ȳ��ܴ���24Сʱ������¼�����������ʱ���ʽΪ��"%Y-%m-%d %H:%M:%S"��ʽ ����Ϣ�����޶�Ϊ24�ַ�.
* - 2. �ļ����ַ���������󳤶�Ϊ#IMOS_FILE_NAME_LEN_V2
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RecordRetrievalV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  REC_QUERY_INFO_S            *pstSDKRecQueryInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT RECORD_FILE_INFO_V2_S       *pstSDKRecordFileInfo
);

/**
* ��ȡ¼���ļ���URL��Ϣ(V2) \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param[IN]    pstSDKGetUrlInfo            ��ȡURL������Ϣ���ݽṹ
* @param[IN]    pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����SOI��Ϣ��IE�ṹʹ��#SOI_IE_GET_REC_URL_V2_S������#SOI_IE_GET_URL_S
*          ע����SDK�ӿ�IMOS_GetBakRecordFileURL������
*          AS_RQģ���ڴ���GetURLҵ��ʱ���Ὣ#SOI_IE_GET_REC_URL_V2_S�е���Ϣת��Ϊ#SOI_IE_GET_URL_S
* - 2. �ļ����ַ���������󳤶�Ϊ#IMOS_FILE_NAME_LEN_V2
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetURLV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_V2_S           *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);
/* End add by z07291 for VVD64632 */

/**
* ��ȡ¼���ļ���URL��Ϣ(V3) \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param[IN]    pstSDKGetUrlInfo            ��ȡURL������Ϣ���ݽṹ
* @param[IN]    pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ���V2�ӿڣ���չ�˻ط��м̲��Ե���Ϣ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetURLV3
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_V3_S           *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* ����һ���¼�ʹ�ܲ���
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szAlarmSrcCode      �澯Դ���룬����Ϊ�գ���ʾϵͳ�澯���͵�ʹ�ܲ���
* @param [IN]   ulEventType         �¼�����ID
* @param [IN]   pstEventEnableInfo  �¼�ʹ�ܲ�����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType,
    IN    EVENT_ENABLE_INFO_S   *pstEventEnableInfo
);

/**
* ����һ���¼�ʹ�ܲ���
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szAlarmSrcCode      �澯Դ���룬����Ϊ�գ���ʾϵͳ�澯���͵�ʹ�ܲ���
* @param [IN]   ulEventType         �¼�����ID
* @param [IN]   pstEventEnableInfo  �¼�ʹ�ܲ�����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType,
    IN    EVENT_ENABLE_INFO_S   *pstEventEnableInfo
);

/**
* ��ѯһ���¼�ʹ�ܲ���
* @param [IN]     pstUserLogIDInfo      �û���Ϣ
* @param [IN]     szAlarmSrcCode        �澯Դ���룬����Ϊ�գ���ʾϵͳ�澯���͵�ʹ�ܲ���
* @param [IN]     ulEventType           �¼�ID
* @param [OUT]    pstEventEnableInfo    �¼�ʹ�ܲ�����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType,
    OUT   EVENT_ENABLE_INFO_S   *pstEventEnableInfo
);

/**
* ɾ��һ���¼�ʹ�ܲ���
* @param [IN]   pstUserLogIDInfo    �û���Ϣ
* @param [IN]   szAlarmSrcCode      �澯Դ���룬����Ϊ�գ���ʾϵͳ�澯���͵�ʹ�ܲ���
* @param [IN]   ulEventType         �¼�����ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType
);

/**
* ���������澯Դ���¼�ʹ�ܲ���
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstBathEventEnableInfo  ���������豸��Ϣ
* @param [IN]   pstEventEnableInfo      �¼�ʹ�ܲ�����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BathAddEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    BATH_EVENT_ENABLE_INFO_S  *pstBathEventEnableInfo,
    IN    EVENT_ENABLE_INFO_S       *pstEventEnableInfo
);

/**
* ����ɾ���澯Դ���¼�ʹ�ܲ���
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstBathEventEnableInfo  ���������豸��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BathDelEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    BATH_EVENT_ENABLE_INFO_S  *pstBathEventEnableInfo
);

/**
* ��ѯϵͳ�澯������Ϣ
* �����ѯ����ʱ,������,��Ĭ������(�澯��������)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;#EVENT_TYPE_NAME[�澯�¼�����]; #EVENT_SECURITY[�澯�¼�����];#NAME_TYPE[�澯�¼���������];)
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  psEventTypeInfoList     �澯������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֻ֧���¼����ơ��¼��������Ƶ�ģ����ѯ�Լ��¼������ѯ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySystemEventTypeInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT EVENT_TYPE_EXT_INFO_S       *pstEventTypeInfoList
);

/**
* ��ѯ����Э��澯���Ͷ�Ӧ��ϵ��Ϣ\n
* @param [IN]   pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [IN]   szEventTypeL2ORelCode         ����Э��澯���Ͷ�Ӧ��ϵID����
* @param [OUT]   pstEventTypeL2Orel           ����Э��澯���Ͷ�Ӧ��ϵ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventTypeL2ORel
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   CHAR                        szEventTypeL2ORelCode[IMOS_CODE_LEN],
    OUT  EVENT_TYPE_L2OREL_S         *pstEventTypeL2Orel
);

/**
* ��ӱ���Э��澯���Ͷ�Ӧ��ϵ��Ϣ\n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEventTypeL2Orel           ����Э��澯���Ͷ�Ӧ��ϵ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventTypeL2ORel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_TYPE_L2OREL_S         *pstEventTypeL2Orel
);

/**
* ɾ������Э��澯���Ͷ�Ӧ��ϵ��Ϣ\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szEventTypeL2ORelCode   ����Э��澯���Ͷ�Ӧ��ϵID����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventTypeL2ORel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szEventTypeL2ORelCode[IMOS_CODE_LEN]
);

/**
* �޸ı���Э��澯���Ͷ�Ӧ��ϵ��Ϣ\n
* @param [IN]   pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEventTypeL2Orel           ����Э��澯���Ͷ�Ӧ��ϵ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEventTypeL2ORel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_TYPE_L2OREL_S         *pstEventTypeL2Orel
);

/**
* ��ҳ��ѯ����Э��澯���͹�ϵ�б�
* �����ѯ����ʱ,������
* @param [IN]   pstUserLogIDInfo              �û���Ϣ
* @param [IN]   pstQueryCondition             ͨ�ò�ѯ����(��ΪNULL;��������:#EVENT_TYPE[�¼�����])
* @param [IN]   pstQueryPageInfo              �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                ���ط�ҳ��Ϣ
* @param [OUT]  pstEventTypeL2OrelList        ����Э��澯���Ͷ�Ӧ��ϵ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventTypeL2ORelList
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT EVENT_TYPE_L2OREL_S            *pstEventTypeL2OrelList
);

/**
* ��ѯ�����������ϢV2
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [OUT]  pstSemaOutputInfo       �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOutSwitch_V2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT SEMA_OUTPUT_INFO_V2_S       *pstSemaOutputInfo
);

/**
* �����豸�����������V2
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [IN]   pstSemaOutputInfo         �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfOutSwitch_V2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  SEMA_OUTPUT_INFO_V2_S       *pstSemaOutputInfo
);

/**
* SDK�ͻ��˲��˳�����£�ֻ��ձ����û���¼��Ϣ�ӿڣ���Ҫʵ�ַ����û��˳���Ϣ�Լ�����SDKΪ���û�ҵ�����������Դ�� \n
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @return ULONG  �������½��:
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ���
* @note
* 1��ֻ���gstAutoKeepAliveCB��������Ϣ��gstClibSysCB�е��û���¼��Ϣ�Լ�gpUICallBackFuncָ��;
* 2��SDK�û�����ֱ���ٴε�¼�󣬶���������Ϣ��ע��ص�����, ���ɽ�������SDKҵ��;
* 3�����ӿڲ�У���û���Ϣ����Ҫ�û��Լ�ע��֮ǰ��¼���û������ӿڻ����gpUICallBackFunc֪ͨ�û��˳�������ֻ������BM
ʹ��;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CleanUpUserInfoOnlyforClientNotExit
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo
);
/**
* ��ӵ������ļ���ʼ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   pstLayerInfo             ���ļ���Ϣ
* @param [OUT]  pstFtpInfo              FTP��Ϣ
* @param [OUT]  pulSequenceNumber       ����FTP�����������к�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisLayerStart
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_CODE_LEN],
    IN  LAYER_BASIC_INFO_S              *pstLayerInfo,
    OUT FTP_INFO_S                      *pstFtpInfo,
    OUT ULONG_32                           *pulSequenceNumber
);

/**
* ���ϴ���ͼ���ļ��Ľ��, ֪ͨ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess              �ϴ��ļ��Ľ��, #BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @param [IN]   ulSequenceNumber        ����FTP�����������к�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisLayerEnd
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BOOL_T                      bIsSuccess,
    IN  ULONG_32                       ulSequenceNumber
);

/**
* ���µ������ļ���ʼ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   pstOldLayerInfo         ����ǰ���ļ���Ϣ
* @param [IN]   pstNewLayerInfo         ���º���ļ���Ϣ
* @param [OUT]  pstFtpInfo              FTP��Ϣ
* @param [OUT]  pulSequenceNumber       ����FTP�����������к�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateGisLayerStart
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    IN  LAYER_BASIC_INFO_S          *pstOldLayerInfo,
    OUT FTP_INFO_S                  *pstFtpInfo,
    OUT ULONG_32                       *pulSequenceNumber
);

/**
* ���ϴ����ļ��Ľ��, ֪ͨ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess              �ϴ��ļ��Ľ��, #BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @param [IN]   ulSequenceNumber        ����FTP�����������к�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateGisLayerEnd
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  BOOL_T                  bIsSuccess,
    IN  ULONG_32                   ulSequenceNumber
);

/**
* ���ز��ļ��б�ʼ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [INOUT]  pulLayerNumber          ���ļ�����
* @param [INOUT]  pstFtpInfo              FTP��Ϣ�б�
* @param [OUT]    pulSequenceNumber       ����FTP�����������к�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisLayersStart
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    INOUT ULONG_32                       *pulLayerNumber,
    INOUT FTP_INFO_S                  *pstFtpInfo,
    OUT   ULONG_32                       *pulSequenceNumber
);

/**
* �����ز��ļ��Ľ��, ֪ͨ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess              �����ļ��Ľ��, #BOOL_TRUEΪ�ɹ�; #BOOL_FALSEΪʧ��
* @param [IN]   ulSequenceNumber        ����FTP�����������к�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisLayersEnd
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BOOL_T                      bIsSuccess,
    IN  ULONG_32                       ulSequenceNumber
);

/**
* ��ȡGISͼ�������Ϣ(������ͼ��)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [OUT]  pulLayerNumber          ͼ����Ŀ
* @param [OUT]  pstLayerInfo            ͼ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLayerMapInfo
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_CODE_LEN],
    OUT ULONG_32                        *pulLayerNumber,
    OUT LAYER_BASIC_INFO_S           *pstLayerInfo
);

/**
* ɾ��GISͼ��
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [IN]   szLayerName             ͼ���ļ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ע�⣬���ɾ�����ļ���Ҳ��Ҫ���سɹ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGisLayer
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szGISMapCode[IMOS_CODE_LEN],
    IN  CHAR                    szLayerName[IMOS_NAME_LEN]
);

/**
* ��ȡGIS��ͼ��ɫ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [OUT]  pstMapColors            GIS��ɫ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMapColors
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_CODE_LEN],
    OUT FILE_MAP_COLORS_S            *pstMapColors
);

/**
* ����GIS��ͼ��ɫ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szGISMapCode            GIS��ͼ����
* @param [OUT]  pstMapColors            GIS��ɫ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMapColors
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_CODE_LEN],
    IN  FILE_MAP_COLORS_S            *pstMapColors
);

/**
* ����¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEventType       �¼�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ӵ��¼�����ID��ΧΪ5--30
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventSecurityType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_SECURITY_TYPE_S       *pstEventSecurityType
);

/**
* ɾ���¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   ulEventSecurityType    �¼�����ID
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����ɾ�����¼�����ID��ΧΪ5-30
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventSecurityType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulEventSecurityType
);

/**
* �޸��¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEventType       �¼�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEventSecurityType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_SECURITY_TYPE_S       *pstEventSecurityType
);

/**
* ��ѯ�¼�������Ϣ \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   ulEventSecurityType       �¼�����ID
* @param [OUT]  pstEventSecurityType      �¼�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventSecurityType
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   ULONG_32                       ulEventSecurityType,
    OUT  EVENT_SECURITY_TYPE_S       *pstEventSecurityType
);

/**
* ��ѯ�¼����������б� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo    ��ѯ��ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��ѯ���ط�ҳ��Ϣ
* @param [OUT]  pstSecurityTypeList ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��������ΪNULL,��ʾ��ѯ�����¼�������Ϣ
* - 2. ֧�ְ�"�¼���������"ģ����ѯ:#NAME_TYPE;
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventSecurityTypeList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EVENT_SECURITY_EXT_TYPE_S       *pstSecurityTypeExtList
);

/**
* ���������������\n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   ulPlayWndNum        ���Ŵ���������
* @param [INOUT]   pstPlayWndInfo      ���Ŵ������ṹ��ָ�롣
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlayerEx
(
     IN USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
     IN ULONG_32                    ulPlayWndNum,
     INOUT PLAY_WND_INFO_S       *pstPlayWndInfo
);

/**
* ��ȡ�������DecoderTag��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [OUT]  szDecoderTag            DecoderTag
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDecoderTag
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szCamCode[IMOS_CODE_LEN],
    OUT CHAR                         szDecoderTag[IMOS_STRING_LEN_64]
);

/**
* ����/ֹͣ����Ѳ�ƻ� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szGroupsalvoPlanCode    ����Ѳ�ƻ�����
* @param [IN]   ulProcessType           ��������: ����/ֹͣ
* @param [IN]   ulOperateCode           ����ԭ����: #CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessGroupsalvoPlan
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szGroupsalvoPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulProcessType,
    IN  ULONG_32                   ulOperateCode
);

#if 0
#endif

/*************************************************************************************
������Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӱ���
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szOrgCode               ����������֯����
* @param [INOUT]  pstCaseInfo             ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCase
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    INOUT   CASE_INFO_S                 *pstCaseInfo
);

/**
* �޸İ���
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstCaseInfo            ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_INFO_S                *pstCaseInfo
);

/**
* ɾ������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szCaseCode              �������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szCaseCode[IMOS_CODE_LEN]
);

/**
* ��ѯ����
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szCaseCode           �������
* @param [OUT]  pstCaseInfo          ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szCaseCode[IMOS_CODE_LEN],
    OUT  CASE_INFO_S                *pstCaseInfo
);

/**
* ���ư���
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szSrcCaseCode           Դ�������
* @param [IN]     szDstCaseCode           Ŀ�İ������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DuplicateCase
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   CHAR                        szSrcCaseCode[IMOS_CODE_LEN],
    IN   CHAR                        szDstCaseCode[IMOS_CODE_LEN]
);

/*************************************************************************************
�����漰��Ա��Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӱ�����Ա��Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstCasePersInfo         ������Ա��Ϣ�����ν�������Ա���뷵��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCasePersonnel
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   CASE_PERSONNEL_INFO_S       *pstCasePersInfo
);

/**
* �޸İ�����Ա��Ϣ
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstCasePersInfo        ������Ա��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCasePersonnel
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_PERSONNEL_INFO_S      *pstCasePersInfo
);

/**
* ɾ��������Ա
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   ulPersonnelType         ������Ա���ͣ�ȡֵ#CASE_PERSONNEL_TYPE_E
* @param [IN]   szPersCode              ������Ա���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCasePersonnel
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulPersonnelType,
    IN   CHAR                       szPersCode[IMOS_CODE_LEN]
);

/**
* ��ѯ������Ա��Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   ulPersonnelType      ������Ա���ͣ�ȡֵ#CASE_PERSONNEL_TYPE_E
* @param [IN]   szPersCode           ������Ա���
* @param [OUT]  pstCasePersInfo      ������Ա��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCasePersonnel
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulPersonnelType,
    IN   CHAR                       szPersCode[IMOS_CODE_LEN],
    OUT  CASE_PERSONNEL_INFO_S      *pstCasePersInfo
);

/**
* ��ѯ��������Ա��Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   ulPersonnelType            ������Ա���ͣ�ȡֵ#CASE_PERSONNEL_TYPE_E
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCasePersList            ������Ա��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ��������������Ա��Ϣ
* - 2.֧�ְ�"��Ա���"���˲�ѯ
* - 3.֧�ְ�"��Ա����"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Ա����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��Ա����),#CODE_TYPE(��Ա���)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCasePersonnelList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulPersonnelType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_PERSONNEL_INFO_S           *pstCasePersList
);

/*************************************************************************************
�����漰������Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӱ���������Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstCaseVehicleInfo      ����������Ϣ�����ν������������뷵��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseVehicle
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   CASE_VEHICLE_INFO_S         *pstCaseVehicleInfo
);

/**
* �޸İ���������Ϣ
* @param [IN]   pstUserLogIDInfo          �û���Ϣ
* @param [IN]   pstCaseVehicleInfo        ����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseVehicle
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_VEHICLE_INFO_S        *pstCaseVehicleInfo
);

/**
* ɾ����������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szVehicleCode           �����������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCaseVehicle
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szVehicleCode[IMOS_CODE_LEN]
);

/**
* ��ѯ����������Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szVehicleCode        �����������
* @param [OUT]  pstCaseVehicleInfo   ����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseVehicle
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szVehicleCode[IMOS_CODE_LEN],
    OUT  CASE_VEHICLE_INFO_S        *pstCaseVehicleInfo
);

/**
* ��ѯ�����ĳ�����Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCaseVehicleList         ����������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ�����������г�����Ϣ
* - 2.֧�ְ�"���ƺ���"ģ����ѯ:#PLATE_CODE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"���ƺ���"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseVehicleList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_VEHICLE_INFO_S             *pstCaseVehicleList
);


/*************************************************************************************
�����漰��Ʒ��Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӱ�����Ʒ��Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstCaseStuffInfo        ������Ʒ��Ϣ�����ν�������Ʒ���뷵��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseStuff
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   CASE_STUFF_INFO_S           *pstCaseStuffInfo
);

/**
* �޸İ�����Ʒ��Ϣ
* @param [IN]   pstUserLogIDInfo          �û���Ϣ
* @param [IN]   pstCaseStuffInfo          ������Ʒ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseStuff
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_STUFF_INFO_S          *pstCaseStuffInfo
);

/**
* ɾ��������Ʒ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szStuffCode             ������Ʒ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCaseStuff
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szStuffCode[IMOS_CODE_LEN]
);

/**
* ��ѯ������Ʒ��Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szStuffCode          ������Ʒ���
* @param [OUT]  pstCaseStuffInfo     ������Ʒ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseStuff
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szStuffCode[IMOS_CODE_LEN],
    OUT  CASE_STUFF_INFO_S          *pstCaseStuffInfo
);

/**
* ��ѯ��������Ʒ��Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCaseStuffList           ������Ʒ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ��������������Ʒ��Ϣ
* - 2.֧�ְ�"��Ʒ����"ģ����ѯ:#NAME_TYPE
* - 3.֧�ְ�"��Ʒ���"��ѯ:#STUFF_TYPE
* - 4.֧�ְ�"��Ʒ����"��ѯ:#STUFF_PROPERTY
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Ʒ����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseStuffList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_STUFF_INFO_S               *pstCaseStuffList
);

/*************************************************************************************
��������Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӵ�����
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szOrgCode               ������������֯����
* @param [IN]     pstSeriesCaseInfo       ��������Ϣ��INʱ,�������������Ϊ��;���Ϊ��,��OUT����������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSeriesCase
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    INOUT   SERIES_CASE_INFO_S          *pstSeriesCaseInfo
);

/**
* �޸Ĵ�����
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstSeriesCaseInfo      ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySeriesCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   SERIES_CASE_INFO_S         *pstSeriesCaseInfo
);

/**
* ɾ��������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSeriesCaseCode        ���������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSeriesCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSeriesCaseCode[IMOS_CODE_LEN]
);

/**
* ��ѯ������
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szSeriesCaseCode     ���������
* @param [OUT]  pstSeriesCaseInfo    ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySeriesCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSeriesCaseCode[IMOS_CODE_LEN],
    OUT  SERIES_CASE_INFO_S         *pstSeriesCaseInfo
);

/**
* ��ѯ�����´�������Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szDeptCode                 ���ű���
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSeriesCaseList          ��������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEPT_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ�����������д�����(�����Ӳ���)
* - 2.֧�ְ�"�Ƿ���Ӳ���"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ���������ź�����ģ����ѯ:#NAME_TYPE,#CODE_TYPE
* - 4.֧�ְ����������Բ�ѯ:����������:#SERIESCASE_TYPE�������������:#CASEINSE_CODE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"���������"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(����������),#CODE_TYPE(���������)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySeriesCaseList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDeptCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SERIES_CASE_lIST_S              *pstSeriesCaseList
);

/**
* ���Ӱ�����������
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szSeriesCaseCode        ����������
* @param [IN]     ulCaseNum               ������Ŀ�����ֵ#IMOS_CASE_MAXNUM_PER_SERIESCASE
* @param [IN]     pcCaseCodeList          ���������б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseToSeriesCase
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szSeriesCaseCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulCaseNum,
    IN  CHAR                        *pcCaseCodeList
);

/**
* ������
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szCaseCode              �������
* @param [IN]     ulShareFlag             �����־: 0Ϊȡ������1Ϊ����
* @param [IN]     ulShareType             �������ͣ�ȡֵ#CASE_SHARE_TYPE_E
* @param [IN]     szResCode               ����Ŀ�����(�û�����/��֯����)
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻ֧�ֹ�����û�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShareCase
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCaseCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulShareFlag,
    IN  ULONG_32                       ulShareType,
    IN  CHAR                        szResCode[IMOS_CODE_LEN]
);

/**
* ��ѯ��������Ŀ���б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstShareDstList            ��������Ŀ����Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CASE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note Ŀǰ��֧�ֲ�ѯ����������û��б�
* - ����
* - 1.֧�ְ��������͹��˲�ѯ:#CASESHARE_TYPE��ȡֵ#CASE_SHARE_TYPE_E.
* - 2.֧�ְ�����Ŀ����������ģ����ѯ:#CODE_TYPE,#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"Ŀ�����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(Ŀ������),#CODE_TYPE(Ŀ�����)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseShareDstList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_SHAREDST_INFO_S            *pstShareDstList
);

/**
* ��ѯ�����Ŀ��İ����б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   ulShareType                �������ͣ�ȡֵ#CASE_SHARE_TYPE_E
* @param [IN]   szResCode                  ����Ŀ�����(�û�����/��֯����)
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCaseList                ��������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ�鹲�����Ŀ��İ����б�
* - 3.֧�ְ����������Բ�ѯ:�������/����/����/����/״̬/������Դ/��ʼʱ��/����ʱ��
      ��#CASE_PROPERTY-------#CASE_END_TIME
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�������"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��������),#CODE_TYPE(�������)
    Ŀǰ��֧�ֲ鹲���ĳ�û��İ����б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareCaseList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulShareType,
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_LIST_INFO_S                *pstCaseList
);


/*************************************************************************************
����������Ϣ(¼��/ͼƬ/�����ļ�)���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӱ���¼����Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szCaseCode              �������
* @param [INOUT]     pstCaseRecord        ����¼����Ϣ�����ν�����¼����뷵��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseRecord
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szCaseCode[IMOS_CODE_LEN],
    INOUT   CASE_RECORD_INFO_S          *pstCaseRecord
);

/**
* �޸İ���¼����Ϣ
* @param [IN]   pstUserLogIDInfo          �û���Ϣ
* @param [IN]   pstCaseRecord             ����¼����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseRecord
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_RECORD_INFO_S         *pstCaseRecord
);

/**
* ɾ������������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   ulRelationType          ������Ϣ����,ȡֵ#CASE_RELATEDINFO_TYPE_E
* @param [IN]   szInfoCode              ����������Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCaseRelatedInfo
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulRelationType,
    IN   CHAR                       szInfoCode[IMOS_CODE_LEN]
);

/**
* ��ѯ����¼����Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szRecordCode         ����¼����
* @param [OUT]  pstCaseRecInfo       ����¼����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseRecord
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szRecordCode[IMOS_CODE_LEN],
    OUT  CASE_RECORD_INFO_S         *pstCaseRecInfo
);

/**
* ��ѯ������¼����Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCaseRecList             ����¼����Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -    ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ������������¼����Ϣ
* - 2.֧�ְ�"��Ƶ��ص�����"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Ƶ��ص�����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseRecordList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_RECORD_LIST_INFO_S         *pstCaseRecList
);

/**
* ��ȡ����¼���ļ�������Ϣ \n
* @param[IN]    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param[IN]    ULONG                    ulCaseRecSrvType        ����¼��ҵ�����ͣ�0:���أ�1:�ط�
* @param[IN]    CHAR                     szRecordCode            ����¼����
* @param[INOUT] ULONG                    *pulRecFileNum          ����¼���ļ��������鳤�ȣ����ȡֵIMOS_FILE_MAXNUM_PER_CASERECORD
* @param[IN]    FILE_DOWNLOAD_INFO_S     *pstFileDLInfo          ¼��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetCaseRecordDLInfo
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    ULONG_32                       ulCaseRecSrvType,
    IN    CHAR                        szRecordCode[IMOS_CODE_LEN],
    INOUT ULONG_32                       *pulRecFileNum,
    OUT   FILE_DOWNLOAD_INFO_S        *pstFileDLInfo
);

/**
* ���Ӱ��������ļ���Ϣ
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szCaseCode              �������
* @param [IN]     pstCaseFile             �����ļ���Ϣ�����ν������ļ����뷵��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseFile
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szCaseCode[IMOS_CODE_LEN],
    INOUT   CASE_FILE_INFO_S            *pstCaseFile
);

/**
* �޸İ����ļ���Ϣ
* @param [IN]   pstUserLogIDInfo          �û���Ϣ
* @param [IN]   pstCaseFile               �����ļ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseFile
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_FILE_INFO_S           *pstCaseFile
);

/**
* ��ѯ�����ļ���Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szFileCode           �����ļ�����
* @param [OUT]  pstCaseFileInfo      �����ļ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseFile
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szFileCode[IMOS_CODE_LEN],
    OUT  CASE_FILE_INFO_S           *pstCaseFileInfo
);

/**
* ��ѯ�������ļ���Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCaseFileList            �����ļ���Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ�������������ļ���Ϣ
* - 2.֧�ְ�"�ļ�����"���˲�ѯ:#FILE_TYPE
* - 2.֧�ְ�"�ļ�����"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�ļ�����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseFileList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CASE_FILE_INFO_S                *pstCaseFileList
);


/*************************************************************************************
���ӹ�����Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���ӵ��ӹ���
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstEBInfo               ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEBulletin
(
    IN   USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN   ELECTRONIC_BULLETIN_INFO_S   *pstEBInfo
);

/**
* �޸ĵ��ӹ���
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstEBInfo              ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEBulletin
(
    IN   USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN   ELECTRONIC_BULLETIN_INFO_S   *pstEBInfo
);

/**
* ɾ�����ӹ���
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szBulletinCode          �������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEBulletin
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szBulletinCode[IMOS_CODE_LEN]
);

/**
* ��ѯ���ӹ���
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szBulletinCode       �������
* @param [OUT]  pstEBulletinInfo     ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEBulletin
(
    IN   USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN   CHAR                         szBulletinCode[IMOS_CODE_LEN],
    OUT  ELECTRONIC_BULLETIN_INFO_S   *pstEBulletinInfo
);

/**
* ��ѯ������Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstEBulletinList           ������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ�����й���
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"����ʱ��"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEBulletinList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ELECTRONIC_BULLETIN_INFO_S      *pstEBulletinList
);


/**
* ����֯�°���Ա���а��������ѯͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode               ��֯����
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstCaseProStatistic     ��������ͳ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ���Ա����¼������/�᰸����ͳ��
* - 3.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseProcessStat
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szOrgCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   CASE_PROCESS_STATISTIC_S       *pstCaseProStatistic
);

/*************************************************************************************
�������ϲ����û����ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* �������ϲ����û�����
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     ulOperType              �������ͣ�0:�����û���1:ɾ���û�
* @param [IN]     ulDataType              �����������ͣ�ȡֵ#CASE_DATA_TYPE_E
* @param [IN]     szCaseDataCode          �������ϱ���
* @param [IN]     szUserName              �û�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CfgCaseDataUser
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      ULONG_32                       ulOperType,
    IN      ULONG_32                       ulDataType,
    IN      CHAR                        szCaseDataCode[IMOS_CODE_LEN],
    IN      CHAR                        szUserCode[IMOS_CODE_LEN]
);

/**
* �������ϲ����û��б��ѯ
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pcUserNameList             �û������б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.֧�ְ��������ϱ������Ͳ�ѯ:#CODE_TYPE
* - 2.֧�ְ������������Ͳ�ѯ:#CASE_DATA_TYPE
* - 2.֧�ְ�"�û�����"ģ����ѯ:#USER_NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"�û�����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseDataUserList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CHAR                            *pcUserCodeList
);

#if 0
/*************************************************************************************
����ͼƬ����Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���Ӱ���ͼƬ��
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szCaseCode              �������
* @param [IN]     pstPicGrpInfo           ͼƬ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCasePicGroup
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szCaseCode[IMOS_CODE_LEN],
    INOUT   PICTURE_GROUP_INFO_S        *pstPicGrpInfo
);

/**
* ɾ������ͼƬ��
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     szPicGrpCode            ͼƬ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCasePicGroup
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   CHAR                        szPicGrpCode[IMOS_CODE_LEN]
);

/**
* �޸İ���ͼƬ��
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstPicGrpInfo           ͼƬ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCasePicGroup
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   PICTURE_GROUP_INFO_S        *pstPicGrpInfo
);

/**
* ��ѯ����ͼƬ����Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szPicGrpCode         ͼƬ�����
* @param [OUT]  pstPicGrpInfo        ͼƬ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCasePicGroup
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szPicGrpCode[IMOS_CODE_LEN],
    OUT  PICTURE_GROUP_INFO_S       *pstPicGrpInfo
);

/**
* ��ѯ������ͼƬ����Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szCaseCode                 �������
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCasePicGrpList          ����ͼƬ����Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_GACASE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ������������¼����Ϣ
* - 2.֧�ְ�"ͼƬ������"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"ͼƬ������"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCasePicGrpList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCaseCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT PICTURE_GROUP_INFO_S            *pstCasePicGrpList
);
#endif


/*************************************************************************************
������Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* �����û�������Ϣ
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   ulCfgType                   ��������,0:���ò��ţ�1:ȡ�����ò���
* @param [IN]   szUserCode                  �û�����
* @param [IN]   szDeptCode                  ���ű���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigUserDeptInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulCfgType,
    IN  CHAR                        szUserCode[IMOS_CODE_LEN],
    IN  CHAR                        szDeptCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�û�������Ϣ
* @param [IN]   pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN]   szUserCode                   �û�����
* @param [OUT]   DEPT_INFO_S          �û�������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserDeptInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUserCode[IMOS_CODE_LEN],
    OUT DEPT_INFO_S                 *pstDeptInfo
);

/**
* �ڵ�λ�°��յ�λ��Ϣ��������������ͳ�ƻ����ϴ�����ͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szDepartmentCode        ��λ����
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [IN]       ulQueryFlag             ��ѯ��־λ(ͳ�ư���������������#CASE_STAT_FLAG_S)
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstCaseDepartmentStat   ��λ�µİ�����Ϣͳ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�ͳ�ƿ�ʼʱ��#STAT_START_TIME����ͳ�ƽ���ʱ��#STAT_END_TIME����ͳ��
* - 2.֧�ְ��հ�����Ϣ�İ������ʣ�����������λ��ѯ
* - 3��֧���Ƿ��ѯ�����ӵ�λ�Ĳ�ѯ
* - ����
* - 1.Ĭ�ϰ�"��λ����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseDepartmentStat
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szDepartmentCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    IN    ULONG_32                          ulQueryFlag,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   CASE_DEPARTMENT_STAT_S         *pstCaseDepartmentStat
);

/**
* �ڵ�λ�°����û���Ϣ��������������ͳ�ƻ����ϴ�����ͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szDepartmentCode        ��λ����
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [IN]       ulQueryFlag             ��ѯ��־λ(ͳ�ư���������������#CASE_STAT_FLAG_S)
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstCaseDepartmentStat   ��λ�µİ�����Ϣͳ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�ͳ�ƿ�ʼʱ��#STAT_START_TIME����ͳ�ƽ���ʱ��#STAT_END_TIME����ͳ��
* - 2.֧�ְ��հ�����Ϣ�İ������ʣ�����״̬���û����룬�û�������λ����
* - 3��֧���Ƿ��ѯ�����ӵ�λ�Ĳ�ѯ
* - ����
* - 1.Ĭ�ϰ�"�û�����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseUserInfoStat
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szDepartmentCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    IN    ULONG_32                          ulQueryFlag,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   CASE_USER_STAT_S               *pstCaseUserStat
);

/**
* �ڵ�λ�°���������������Ϣ����ͳ��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szDepartmentCode        ��λ����
* @param [IN]       pstQueryCondition       ͨ�ò�ѯ���������޲�ѯ��������ΪNULL
* @param [IN]       pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]      pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]      pstCaseInfoAnalysisStat ��λ�µİ�����Ϣ����ͳ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�ͳ�ƿ�ʼʱ��#STAT_START_TIME����ͳ�ƽ���ʱ��#STAT_END_TIME����ͳ��
* - 2.֧�ְ��հ�����Ϣ�İ������ʣ�����״̬���û�����
* - ����
* - 1.Ĭ�ϰ�"��λ����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseInfoAnalysisStat
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    CHAR                           szDepartmentCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT   CASE_ANALYSIS_STAT_S           *pstCaseInfoAnalysisStat
);

/**
* ���ݵص��ѯ�ܱ�������б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  NEIGHBOR_CAMERA_INFO_S     �ܱ��������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DEVICE_LOCATION_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.֧�ְ�"�豸����"���˲�ѯ���豸�ܱߵ�������б�:#CODE_TYPE��֧�ֵ��豸��������������ڣ��������
* - 2.֧�ְ�"�ܱ߷�Χ"��ѯ:#DISTANCE_RANGE
* - 3.֧�ְ�"���������"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"���������"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamListByLocation
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT NEIGHBOR_CAMERA_INFO_S          *pstCameraList
);

#if 0
#endif

/*************************************************************************************
WebGis��Ϣ���ã��������ӣ��޸ģ�ɾ������ѯ��
**************************************************************************************/
/**
* ���WebGIS
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       szOrgCode               ��֯����
* @param [INOUT]    pstWebGisBaseInfo       WebGis��ͼ��Ϣ����ͼ�����ɺ�̨����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddWebGis
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN     CHAR                            szOrgCode[IMOS_CODE_LEN],
    INOUT  WEBGIS_BASE_INFO_S              *pstWebGisBaseInfo
);

/**
* �޸�WebGIS
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstWebGisBaseInfo       WebGis��ͼ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyWebGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  WEBGIS_BASE_INFO_S              *pstWebGisBaseInfo
);

/**
* ɾ��WebGIS
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szWebGisCode            ��ͼ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelWebGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szWebGisCode[IMOS_CODE_LEN]
);

/**
* ��ѯWebGIS
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szWebGisCode            ��ͼ����
* @param [OUT]  pstBaseInfo             WebGis��ͼ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szWebGisCode[IMOS_CODE_LEN],
    OUT WEBGIS_BASE_INFO_S              *pstWebGisBaseInfo
);

/**
* ��ѯWebGIS��Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstWebGisList              WebGis��ͼ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯������WebGis��ͼ��Ϣ
* - 2.֧�ְ�"�Ƿ�ΪĬ�ϵ�ͼ"���˲�ѯ:#DEFAULT_WEBGIS_MAP
* - 2.֧�ְ�"��ͼ����"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��ͼ����"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGisList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT WEBGIS_BASE_INFO_S              *pstWebGisList
);


/**
* ���WebGIS��ע��
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [INOUT]    pstAttentivePoint       WebGis��ͼ��ע����Ϣ����ע������ɺ�̨����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddWebGisAttPoint
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    INOUT  WEBGIS_ATTENTIVE_POINT_S        *pstAttentivePoint
);

/**
* �޸�WebGIS��ע��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstAttentivePoint       WebGis��ͼ��ע����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyWebGisAttPoint
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  WEBGIS_ATTENTIVE_POINT_S        *pstAttentivePoint
);

/**
* ɾ��WebGIS��ע��
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szPointCode            ��ע�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelWebGisAttPoint
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szPointCode[IMOS_CODE_LEN]
);

/**
* ��ѯWebGIS��ע��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szPointCode             ��ͼ����
* @param [OUT]  pstAttentivePoint       WebGis��ͼ��ע����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGisAttPoint
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szPointCode[IMOS_CODE_LEN],
    OUT WEBGIS_ATTENTIVE_POINT_S        *pstAttentivePoint
);

/**
* ��ѯWebGIS��ͼ��ע����Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szMapCode                  ��ͼ����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstWebGisList              WebGis��ͼ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯������WebGis��ͼ��Ϣ
* - 2.֧�ְ�"�Ƿ�Ϊ��ͼĬ�Ϲ�ע��"���˲�ѯ:#DEFAULT_WEBGIS_POINT
* - 2.֧�ְ�"��ע������"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��ע������"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGisAttPointList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMapCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT WEBGIS_ATTENTIVE_POINT_S        *pstAttPointList
);

/**
* ��������Դ�����
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [INOUT]    pstComCameraInfo        �����Դ�������Ϣ��INʱ,������������Ϊ��;���Ϊ��,��OUT���������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommunityCamera
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    INOUT  COMMUNITY_CAMERA_INFO_S         *pstComCameraInfo
);

/**
* �޸������Դ�����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstComCameraInfo        �����Դ�������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommunityCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMUNITY_CAMERA_INFO_S         *pstComCameraInfo
);

/**
* ɾ�������Դ�����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szComCameraCode         �����Դ���������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCommunityCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szComCameraCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�����Դ�����
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szComCameraCode         �����Դ���������
* @param [OUT]  pstComCameraInfo        �����Դ�������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommunityCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szComCameraCode[IMOS_CODE_LEN],
    OUT COMMUNITY_CAMERA_INFO_S         *pstComCameraInfo
);

/**
* ��ѯ�����Դ�������Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCameraList              �����Դ�������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯�����������Դ�������Ϣ
* - 2.֧�ְ�"���������"ģ����ѯ:#NAME_TYPE
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"���������"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommunityCameraList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT COMMUNITY_CAMERA_INFO_S         *pstCameraList
);

/**
* ͬ����Դ��GIS��ͼ��
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szGisCode           ͬ����ͼ����
* @param [IN]   ulResType           ͬ������Դ����
* @param [IN]   pstGisDbInfo        GIS���ݿ����Ϣ(�˲�����ʱδʹ�ã�����)
* @param [IN]
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SyncResourceToGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGisCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulResType,
    IN  DATABASE_INFO_S                 *pstGisDbInfo
);
/**
* ��ѯ��֯�����������̨��Ϣ \n
* �����ѯ����ʱ,������,��Ĭ������(�������������)
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL)
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pstCamPTZInfo      �������̨��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ����ͨ�ò�ѯ����:
*     #NAME_TYPE[���������]
*     #CODE_TYPE[���������]
* - 2. ֻ���ѯ��̨�������
* - 3. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraPTZInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CAMERA_PTZ_INFO_S               *pstCamPTZInfo
);

/**
* �޸��������̨��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCameraPTZInfo    �������̨��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰֻ���޸� ��̨��ʶulPtzID
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModCameraPTZInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_PTZ_INFO_S               *pstCameraPTZInfo
);

/**
* ��ѯ����������һ������
* @param [IN]   szDevCode            ���������
* @param [OUT]   pstThirdDevError      �������豸������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_QueryCameraLastError
(
    IN  CHAR                    szDevCode[IMOS_CODE_LEN],
    OUT  THIRD_DEVICE_ERROR_S                 *pstThirdDevError
);

/**
* ��ҳ��ѯĳ����֯�µ��û��б�(V2, ��չ����"�û�������֯�ı���") \n
* �����ѯ����ʱ, ������, ��Ĭ������(�û���������)
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�����
* @param [IN]   bIsQuerySubOrg      �Ƿ��ѯ����֯
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#USER_NAME_TYPE[�û�����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstUserList         �û���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  BOOL_T                          bIsQuerySubOrg,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT USER_QUERY_ITEM_V2_S            *pstUserList
);

/*Begin: Added by lkf0106, 2012-09-19 for onvif3���������*/

/**
* ��ѯIPC����������б�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode               IPC�豸����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSemaOutputList       ����������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIPCOutSwitchList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SEMA_QUERY_ITEM_S           *pstSemaOutputList
);

/*End: Added by lkf0106, 2012-09-19 for onvif3���������*/

/**
* ���ø澯������ǽ��ע���� \n
* @param [IN]   pstUserLogIDInfo              �û���½��Ϣ
* @param [IN]   pstLinkWallLabel              �澯������ǽ��ע��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֻ�г�������Ա�û�����Ȩ��
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CfgLinkWallLabel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  LINK_WALL_LABEL_INFO_S          *pstLinkWallLabel
);

/**
* ��ѯ���ø澯������ǽ��ע����\n
* @param [IN]   pstUserLogIDInfo         �û���½��Ϣ
* @param [OUT]  pstLinkWallLabel         �澯������ǽ��ע��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֻ�г�������Ա�û�����Ȩ��
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLinkWallLabel
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    OUT LINK_WALL_LABEL_INFO_S              *pstLinkWallLabel
);

/*====== BEGIN: Added by shendongchun 00400 for �û���¼������ǿ, 2012��11��13�� 19:09:23 =====*/
/**
* �û���¼�ӿ�V2
* @param [IN]   szUserLoginName         �û���¼�û���
* @param [IN]   szPassword              �û���¼����
* @param [IN]   szSrcIpAddress          �û���¼IP
* @param [IN]   pstLoginExtInfo         �û���¼��չ��Ϣ
* @param [OUT]  pstSDKLoginInfo         �û���¼��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LoginV2
(
    IN  CHAR                        szUserLoginName[IMOS_NAME_LEN],
    IN  CHAR                        szPassword[IMOS_PASSWD_ENCRYPT_LEN],
    IN  CHAR                        szSrcIpAddress[IMOS_IPADDR_LEN],
    IN  LOGIN_EXT_INFO_S            *pstLoginExtInfo,
    OUT LOGIN_INFO_S                *pstSDKLoginInfo
);

/**
* �û���¼�������ýӿ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szBindUserCode          ���ð���Ϣ�û���(����û���Ϊ�գ����ʾ����ȫ����Ϣ)
* @param [IN]   pstUserLoginBindInfo    �û���¼������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetUserLoginBindInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBindUserCode[IMOS_USER_CODE_LEN],
    IN  USER_LOGIN_BIND_INFO_S      *pstUserLoginBindInfo
);

/**
* �û���¼���Ʋ�ѯ�ӿ�
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szBindUserCode          ��ѯ����Ϣ�û���(����û���Ϊ�գ����ʾ��ѯȫ����Ϣ)
* @param [OUT]  pstUserLoginBindInfo    �û���¼������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserLoginBindInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBindUserCode[IMOS_USER_CODE_LEN],
    OUT  USER_LOGIN_BIND_INFO_S     *pstUserLoginBindInfo
);
/*====== END  : Added by shendongchun 00400 for �û���¼������ǿ, 2012��11��13�� 19:09:23 =====*/

/* BEGIN: Added by shendongchun 00400 for �û�ͳһ��֤, 2013��3��14�� */
/**
* �û���¼CA�ӿ�
* @param [IN]   szUserLoginName         �û���¼�û���
* @param [IN]   szUserToken             �û�Token
* @param [IN]   szSrcIpAddress          �û���¼IP
* @param [IN]   pstLoginExtInfo         �û���¼��չ��Ϣ
* @param [OUT]  pstSDKLoginInfo         �û���¼��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LoginCA
(
    IN  CHAR                        szUserLoginName[IMOS_NAME_LEN],
    IN  CHAR                        szUserToken[IMOS_PASSWD_ENCRYPT_LEN],
    IN  CHAR                        szSrcIpAddress[IMOS_IPADDR_LEN],
    IN  LOGIN_EXT_INFO_S            *pstLoginExtInfo,
    OUT LOGIN_INFO_S                *pstSDKLoginInfo
);
/* END  : Added by shendongchun 00400 for �û�ͳһ��֤, 2013��3��14�� */



/**
* ���XP���񲼾���Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstXpLayoutInfo     XP���񲼾���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddXpLayoutInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  XP_LAYOUT_INFO_S            *pstXpLayoutInfo
);

/**
* ɾ��XP���񲼾���Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szXpLayoutCode      XP���񲼾ֱ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelXpLayoutInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szXpLayoutCode[IMOS_CODE_LEN]
);

/**
* ��ѯXP���񲼾���Ϣ�б�
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstXpLayoutList     XP���񲼾���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryXpLayoutList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT XP_LAYOUT_INFO_S            *pstXpLayoutList
);

/**
* ���WebGIS��ͼ������
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [INOUT]    pstWebGisBaseInfo       WebGis��ͼ��������Ϣ��������ID�ɺ�̨����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddWebGisScaleInfo
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    INOUT  WEBGIS_SCALE_INFO_S             *pstWebGisScaleInfo
);

/**
* �޸�WebGIS��������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstWebGisBaseInfo       WebGis��ͼ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyWebGisScaleInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  WEBGIS_SCALE_INFO_S             *pstWebGisScaleInfo
);

/**
* ��ѯWebGIS��������Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   ulScaleID                  ��������ϢID
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstWebGisList              WebGis��ͼ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ϢID����Ϊ0,��ʾ������WebGis�����ߵ�ͼ��Ϣ
* - 2.��������ϢID��Ϊ0����ʾ��ѯָ����WEBGIS�ı�������Ϣ,��ҳ��ϢΪ1����
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�������ID��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGisScaleList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulScaleID,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT WEBGIS_SCALE_INFO_S             *pstWebGisScaleList
);
#if 0
#endif

/**��ѯĳ����֯�±��������������������Ϣ\n
* ֧��ģ����ѯ��pstQueryCondition����Ϊ�գ���ʾ��������Ч������ȱʡ����ģ����ѯ
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   �����
* @param [IN]   pstQueryCondition           ��ѯ��Ϣ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstEcList                   EC��Ϣ����(�����������������������Ϣ)
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEcListAndCamInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EC_INFO_EX_S                    *pstEcList
);

/**
* �����˻�����˿ڱ���Ϣ\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���¼��Ϣ
* @param [IN] MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo �˻�����˿���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMMIVoutForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo
);

/**
* �����˻�Ԥ�����������������Ϣ\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���¼��Ϣ
* @param [IN] MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo ���������Ӧ�����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMMIVoutWinListForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo
);

/**
* ��ѯ�˻�����˿ڱ���Ϣ\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���¼��Ϣ
* @param [IN] ULONG ulMMIVoutID ��������˿����,ȡֵ�ο�#MMI_VEDIO_OUT_ID_E,����#MMI_VOUT_ID_ALLΪ��ѯ��������˿�
* @param [INOUT] ULONG *pulMMIVoutNum ��������˿ڸ���
* @param [OUT] MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo ��������˿ڱ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMMIVoutConfigForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN ULONG_32 ulMMIVoutID,
    INOUT ULONG_32 *pulMMIVoutNum,
    OUT MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo
);

/**
* ��ѯ�˻�Ԥ������������б���Ϣ\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo ���û���¼��Ϣ
* @param [INOUT] MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo �˻�Ԥ�����������������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMMIVoutWinListForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    INOUT MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo
);

/**
*@brief ��������˿ڰ�����ͨ��\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���Ϣ
*@param [IN] VIRTUAL_CHANNEL_BIND_INFO_FOR_ECR_S *pstVirtualChannelBindInfo ����������ͨ����Ϣ
*@return �������½��:
*- �ɹ�:
*- ʧ��:
*-     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindVirtualChannel
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN VIRTUAL_CHANNEL_BIND_INFO_FOR_ECR_S *pstVirtualChannelBindInfo
);

/**
*@brief ���°�����ͨ��\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���Ϣ
*@param [IN] VIRTUAL_CHANNEL_REBIND_INFO_FOR_ECR_S *pstVirtualChannelReBindInfo ���°�ͨ����Ϣ
*@return �������½��:
*- �ɹ�:
*- ʧ��:
*-     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ReBindVirtualChannel
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN VIRTUAL_CHANNEL_REBIND_INFO_FOR_ECR_S *pstVirtualChannelReBindInfo
);

/**
*@brief ��ѯ����ͨ������Ϣ\n
*@param [IN] USER_LOGIN_INFO_S *pstSDKLoginInfo �û���Ϣ
*@param [INOUT] ULONG *pulVirtualChannelNum ����ͨ������
*@param [OUT] VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S *pstVirtualChannelStatus ����˿�����ͨ������Ϣ
*@return �������½��:
*- �ɹ�:
*- ʧ��:
*-     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVirtualChannelStatus
(
    IN USER_LOGIN_ID_INFO_S     *pstSDKLoginInfo,
    INOUT ULONG_32                 *pulVirtualChannelNum,
    OUT VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S  *pstVirtualChannelStatus
);

/**
*@brief �������ͨ��\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo �û���Ϣ
*@param [IN] ULONG ulVirtualChannelID ����ͨ�����
*@return �������½��:
*- �ɹ�:
*- ʧ��:
*-     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnBindVirtualChannel
(
    IN USER_LOGIN_ID_INFO_S  *pstSDKLoginInfo,
    IN ULONG_32                  ulVirtualChannelID
);

/**
* ��ѯ�洢�豸�ڵ���Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szCamCode               ���������
* @param [OUT]  szSanResDesc            �洢�豸�ڵ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySanResDesc
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT CHAR                            szSanResDesc[IMOS_DESC_LEN]
);

/**
* ��ӵ�����IPC
* @param [IN]  pstUserLogIDInfo           �û���Ϣ
* @param [IN]  pstThirdpartyIPCInfo       ������IPC��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  THIRDPARTY_IPC_S        *pstThirdpartyIPCInfo
);

/**
* �޸ĵ�����IPC
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   pstThirdpartyIPCInfo        IPC��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  THIRDPARTY_IPC_S           *pstThirdpartyIPCInfo
);

/**
* ɾ��������IPC
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]   szThirdpartyIPCCode         IPC����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szThirdpartyIPCCode[IMOS_CODE_LEN]
);

/**
* ��ѯĳ��������IPC�ľ�����Ϣ
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��־��Ϣ
* @param [IN]   szThirdpartyIPCCode         ������IPC����
* @param [OUT]  pstThirdpartyIPCInfo        ������IPC��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szThirdpartyIPCCode[IMOS_CODE_LEN],
    OUT THIRDPARTY_IPC_S           *pstThirdpartyIPCInfo
);

/*Begin: Added by mozhanfei(m01736), 2014-7-17 for camera  add optimize*/
/**
* ��ѯ������IPC�б�
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��־��Ϣ
* @param [IN]   pstQueryWaitManageIPCList            ��ѯ������Ϣ
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstWaitManageIPCInfoList    ������IPC�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWaitManageIPCInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_WAIT_MANAGE_IPC_LIST_S    *pstQueryWaitManageIPCList,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT WAIT_MANAGE_IPC_S            *pstWaitManageIPCInfoList
);
/*End: Added by mozhanfei(m01736), 2014-7-17 for camera  add optimize*/
/**
* ��ѯ������IPC�б�
* @param [IN]   pstUserLogIDInfo            �û���Ϣ��־��Ϣ
* @param [IN]   szDevCode                   ECR����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstThirdpartyIPCInfoList    ������IPC�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyIPCInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT THIRDPARTY_IPC_S            *pstThirdpartyIPCInfoList
);

/**
*@brief��ѯ�������������״̬\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstUserLogIDInfo   �û���Ϣ
*@param [IN] QUERY_PAGE_INFO_S    *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S     *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param [OUT] CAM_SHARE_INFO_S    *pstCamWithInterCode �����������Ϣ
*@return �������½��:
*- �ɹ�:
*- ʧ��:
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllCamShareInfoForECR
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT   CAM_SHARE_INFO_S        *pstCamWithInterCode
);

/**
*@brief��ѯ���п������������뼰����״̬
*@param [IN] USER_LOGIN_ID_INFO_S *pstUserLogIDInfo   �û���Ϣ
*@param [IN] QUERY_PAGE_INFO_S    *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param [OUT] SEMA_SHARE_INFO_S   *pstSemaInfo        ������������Ϣ
*return  �������½��:
*- �ɹ�:
*- ʧ��:
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllSemaShareInfoForECR
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT   SEMA_SHARE_INFO_S       *pstSemaInfo
);

/**
* ��ѯ�����豸�Ĵ����б�for UI ����������� \n
* �����ѯ����ʱ,������,��Ĭ������(������������)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    ��֯�����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#INDEX_TYPE[��������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  SERIAL_QUERY_ITEM_S         *pstSerialList          ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllSerialList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                                         szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SERIAL_ALLINFO_QUERY_ITEM_S     *pstSerialList
);

/**
* ��ѯ�����豸�����뿪�����б�for UI ����������� \n
* �����ѯ����ʱ,������,��Ĭ������(��������������)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    ��֯�����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:#INDEX_TYPE[����������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  SEMAIN_ALLINFO_QUERY_ITEM_S           *pstSemaList        ��������ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllSwitchInList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                                         szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SEMAIN_ALLINFO_QUERY_ITEM_S   *pstSemaList
);

/**
* ��ѯ�����豸������������б�for UI ����������� \n
* �����ѯ����ʱ,������,��Ĭ������(��������������)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    ��֯�����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:#INDEX_TYPE[����������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  SEMAOUT_ALLINFO_QUERY_ITEM_S           *pstSemaList        ��������ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllSwitchOutList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                                         szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SEMAOUT_ALLINFO_QUERY_ITEM_S   *pstSemaList
);

/**
* ����EC����ͨ���ڵ�������Ϣ
* @param [IN]  pstUserLogIDInfo         �û���Ϣ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  ulCoverDetectAreaNum     ����ͨ���ڵ�����ĸ���
* @param [IN]  pstCoverDetectArea       ����ͨ���ڵ�������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigECCoverDetectArea
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S          *pstChannelIndex,
    IN  ULONG_32                        ulCoverDetectAreaNum,
    IN  VIDEO_AREA_S                 *pstCoverDetectArea
);

/**
* ��ѯEC����ͨ���ڵ�������Ϣ
* @param [IN]    pstUserLogIDInfo         �û���Ϣ
* @param [IN]    pstChannelIndex          �豸ͨ��������Ϣ
* @param [INOUT] pulCoverDetectAreaNum    ����ͨ���ڵ�����ĸ���
* @param [OUT]   pstCoverDetectArea       ����ͨ���ڵ�������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECCoverDetectArea
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulCoverDetectAreaNum,
    OUT   VIDEO_AREA_S                *pstCoverDetectArea
);

/* Begin: Added by lkf0106 for ONVIF�洢�ռ䵯����չ 2012-12-12*/
/**
* ��ѯ����洢��Դ�б� \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[������Դ����]����#CODE_TYPE[�����豸����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDmShareResItemList  ����洢��Դ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareResList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT DM_SHARE_RES_QUERY_ITEM_S    *pstDmShareResItemList
);
/* End: Added by lkf0106 for ONVIF�洢�ռ䵯����չ 2012-12-12*/

/**
* ��ѯ����洢�豸�ɴ洢��Ϣ(������Դ���������ܹ��ɴ洢����) \n
* "�����ܹ��ɴ洢������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode           �������������
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDmShareResItemList  ����洢��Դ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareStorageDeviceList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szCameraCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT SHARE_STORAGE_DEVICE_INFO_S  *pstShareStorageDevInfoList
);

/**************************************************************************************************************
�豸-TS
***************************************************************************************************************/
/**
* @name TS�豸����
* @{    TS�豸����
*/
/**
* ����TS������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKTSInfo        TS��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_TS_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.TS��Ϣ�е�TS������TS��Ψһ��ʶ
* -     2.TS���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  TS_INFO_S                   *pstSDKTSInfo
 );

/**
* ɾ��TS \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTSCode            TS����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_MP_CODE_NOT_EXIST
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTSCode[IMOS_DEVICE_CODE_LEN]
);

/**
* �޸�TS��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKTSInfo        TS��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note TS��Ϣ�е�TS���벻���޸�, ���޸�TS��Ϣ��ʱ����Ҫ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  TS_INFO_S                   *pstSDKTSInfo
);

/**
* ��ѯĳ����֯�µ�TS�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������TS,��Ĭ��"TS������������"
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[MS����] #CODE_TYPE[MS����] #PHY_DEV_IP[MS IP])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKTSList        TS�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note 1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�MS�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TS_QUERY_ITEM_S             *pstSDKTSList
);


/**
* ��ѯTS����ϸ��Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szTSCode            TS����
* @param [OUT]  pstSDKTSInfo        TS��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTSCode[IMOS_DEVICE_CODE_LEN],
    OUT TS_INFO_S               *pstSDKTSInfo
);
/** @} */
/** @} */ /* end of DEVICE MS MANAGEMENT MODULE */

/* Begin added by l01420, 2014-6-30 for �Զ���TSת����� */
/**
* ����TSת�����
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTSRuleInfo         TSת�����
* @param [IN]   ulSrcUANum   ԴUA��Ŀ
* @param [IN]  pstSrcUAList    ԴUA��Ϣ�б�
* @param [IN]  ulDstUANum   Ŀ��UA��Ŀ
* @param [IN]  pstDstUAList    Ŀ��UA��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTSRule
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TS_RULE_INFO_S          *pstTSRuleInfo,
    IN  ULONG_32                ulSrcUANum,
    IN  TS_RULE_UA_INFO_S       *pstSrcUAList,
    IN  ULONG_32                ulDstUANum,
    IN  TS_RULE_UA_INFO_S       *pstDstUAList
);

/**
* ɾ��ĳ��TSת�����
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode         TS�������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTSRule
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRuleCode[IMOS_CODE_LEN]
);

/**
* �޸�ĳ��TSת�����
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTSRuleInfo         TSת�����
* @param [IN]  ulSrcUANum   ԴUA��Ŀ
* @param [IN]  pstSrcUAList    ԴUA��Ϣ�б�
* @param [IN]  ulDstUANum   Ŀ��UA��Ŀ
* @param [IN]  pstDstUAList    Ŀ��UA��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTSRule
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TS_RULE_INFO_S          *pstTSRuleInfo,
    IN  ULONG_32                ulSrcUANum,
    IN  TS_RULE_UA_INFO_S       *pstSrcUAList,
    IN  ULONG_32                ulDstUANum,
    IN  TS_RULE_UA_INFO_S       *pstDstUAList
);

/**
* ��ѯĳ��TSת�������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode         TS�������
* @param [OUT] pstTSRuleInfo   TSת�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note pstSrcUAList��pstDstUAList���ڴ���Ҫ�ɵ���������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSRule
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRuleCode[IMOS_CODE_LEN],
    OUT TS_RULE_INFO_S          *pstTSRuleInfo
);

/**
* ��ҳ��ѯĳ��TS����󶨵�UA
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szRuleCode         TS�������
* @param [INOUT]  pstSrcPageInfo ԴUA��ҳ��Ϣ
* @param [INOUT]  pstDstPageInfo Ŀ��UA��ҳ��Ϣ
* @param [OUT] pstSrcPageInfoRsp  ���ص�ԴUA��ҳ��Ϣ
* @param [OUT] pstSrcUAList    ԴUA�б�
* @param [OUT] pstDstPageInfoRsp  ���ص�Ŀ��UA��ҳ��Ϣ
* @param [OUT] pstDstUAList    Ŀ��UA�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note pstSrcUAList��pstDstUAList���ڴ���Ҫ�ɵ���������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSRuleUAList
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRuleCode[IMOS_CODE_LEN],
    INOUT  QUERY_PAGE_INFO_S    *pstSrcPageInfo,
    INOUT  QUERY_PAGE_INFO_S    *pstDstPageInfo,
    OUT RSP_PAGE_INFO_S         *pstSrcPageInfoRsp,
    OUT TS_RULE_UA_INFO_S       *pstSrcUAList,
    OUT RSP_PAGE_INFO_S         *pstDstPageInfoRsp,
    OUT TS_RULE_UA_INFO_S       *pstDstUAList
);


/**
* ��ҳ��ѯĳ��TS�����������õ�ת������б���Ϣ\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryPageInfo     �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo       ���ط�ҳ��Ϣ
* @param [OUT] pstTSRuleInfo    TS������Ϣ��ֻ���ػ�����Ϣ��������UA��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSRuleList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TS_RULE_QUERY_ITEM_S        *pstTSRuleInfo
);

/* End added by l01420, 2014-6-30 for �Զ���TSת����� */



/* Begin added by z00758,2012-08-08 of ����Ѳ��*/
/**
* ��ѯ�����Ԥ��λ�б�V2(�ɲ�ѯ�¼���Ԥ��λ�б�)
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szCamCode               ����ͷ����
* @param [IN]   ulSyncFlag               ͬ����־
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstQueryResultScope     Ԥ��λ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPresetListV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulSyncFlag,
    IN  QUERY_PAGE_INFO_S        *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT PRESET_INFO_S           *pstPresetList
);
/* End added by z00758,2012-08-08 of ����Ѳ��*/

/**
* ��ѯVM���������ݿ��������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]  pulDBLocalFlag          ���ݿ��Ƿ��VM��װ��һ��(1һ��0�ֿ�)
* @param [OUT]  pstDataBaseInfo         VM���������ݿ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDataBaseInfo
(
 IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
 OUT ULONG_32                           *pulDBLocalFlag,
 OUT DATABASE_INFO_S                 *pstDataBaseInfo
 );


/* BEGIN: Added by kf0092 for ��ȫ��������, 2013��3��15�� */
/**
* ���ð�ȫ�����������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode        ���������
* @param [IN]   pstSafeCameraInfo   ��ȫ�����������Ϣ
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSafeCameraInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    IN  SAFE_CAMERA_INFO_S      *pstSafeCameraInfo
);

/**
* ��ѯ��ȫ�����������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode        ���������
* @param [OUT]  pstSafeCameraInfo   ��ȫ�����������Ϣ
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySafeCameraInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    OUT SAFE_CAMERA_INFO_S      *pstSafeCameraInfo
);
/* END  : Added by kf0092 for ��ȫ��������, 2013��3��15�� */



/* BEGIN: Added by kf0092 for ��������ֶ���ͣ�洢, 2013��3��11�� */
/**
* ������鹦�ܲ���
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szGroupCode             ����������
* @param [IN]   ulCameraOperateType     �������ͣ�ȡֵΪ#CAMERA_GROUP_OPERATE_TYPE_E
* @param [IN]   szReserve               �����ֶ�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CameraGroupOperate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szGroupCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulCameraOperateType,
    IN  CHAR                    szReserve[512]
);
/* END  : Added by kf0092 for ��������ֶ���ͣ�洢, 2013��3��11�� */

/* Begin:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of ������IPC�Ż� */
/**
* ��ѯEC��Ƶ����ͨ��������չ��Ϣ
* @param [IN]       USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo      �û���Ϣ
* @param [IN]       DEV_CHANNEL_INDEX_S    *pstChannelIndex       �豸ͨ��������Ϣ
* @param [INOUT]    ULONG                  *pulStreamNum          ����ͨ����Ƶ��������
* @param [OUT]      VIDEO_STREAM_EXTEND_FORECR_S  *pstVideoInChannelInfo ��Ƶ������չ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT  ULONG_32 STDCALL IMOS_QueryThirdIPCVideoStreamForECR
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                      *pulStreamNum,
    OUT   VIDEO_STREAM_EXTEND_FORECR_S *pstVideoStreamInfo
);

/**
* ����EC��Ƶ����ͨ������Ϣ
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo            �û���Ϣ
* @param [IN]   DEV_CHANNEL_INDEX_S       *pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN]   VIDEO_STREAM_EXTEND_FORECR_S *pstVideoStreamInfo          ��Ƶ����ͨ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigThirdIPCVideoStreamForECR
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S           *pstChannelIndex,
    IN  VIDEO_STREAM_EXTEND_FORECR_S  *pstVideoStreamInfo
);
/* End:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of ������IPC�Ż� */

/* Begin: added by tangxiaobin00764, 2013.1.18 for IVSD00576 of ������IPC�Ż� */
/**
* ��ѯĳ����֯�µ�IPC�б�  \n
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   CHAR                      szOrgCode                �����
* @param [IN]   COMMON_QUERY_CONDITION_S  *pstQueryCondition       ��ѯ��Ϣ����(��ΪNULL;֧�ֵĲ�ѯ��������:#DEVICE_CODE_FOR_ECR[IPC�豸����];
*                                                     #CAMERA_TYPE_FOR_ECR[���������]
*                                                     #NAME_TYPE[���������]
*                                                     #CODE_TYPE[���������])
* @param [IN]   QUERY_PAGE_INFO_S         *pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S           *pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  IPC_CAM_INFO_FORECR_S     *pstIPCInfoList          IPC������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIPCInfoListForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IPC_CAM_INFO_FORECR_S       *pstIPCInfoList

);
/* End: added by tangxiaobin00764, 2013.1.15 for IVSD00576 of ������IPC�Ż� */


/* Begin:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of ������IPC�Ż�--һ��ɾ�� */
/**
* ɾ��IPC (֧��һ��ɾ��IPC)
* @param [IN] pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN] szEcCode                      EC�ı���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIPCForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szEcCode[IMOS_DEVICE_CODE_LEN]
);
/* End:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of ������IPC�Ż�--һ��ɾ�� */

/**
* ͳһ¼����� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstRecQueryInfo             �طż�����Ϣ���ݽṹ
* @param [IN]   ulRowNum                    ����ļ�¼��
* @param [OUT]  pstRecRspRowInfo            ���ؼ�¼��Ϣ
* @param [OUT]  pstUnitedRecFileInfoList    ¼���ļ���Ϣ���ݽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1����ѯʱ���Ȳ��ܴ���24Сʱ������¼�����������ʱ���ʽΪ��"%Y-%m-%d %H:%M:%S"��ʽ ����Ϣ�����޶�Ϊ24�ַ�.
*       2���ļ����ַ���������󳤶�ΪIMOS_FILE_NAME_LEN_V2
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnitedRecordRetrieval
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  REC_QUERY_INFO_S          *pstRecQueryInfo,
    IN  ULONG_32                     ulRowNum,
    OUT REC_RSP_ROW_INFO_S        *pstRecRspRowInfo,
    OUT UNITED_REC_FILE_INFO_S    *pstUnitedRecFileInfoList
);

/**
* ��ȡ¼���ļ���URL��Ϣ \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param[IN]    pstUnitedGetUrlInfo         ��ȡ��¼��URL������ṹ
* @param[OUT]   pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnitedGetRecordFileURL
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  UNITED_GET_URL_INFO_S       *pstUnitedGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* ��ѯ����������¼��������ò��Ե�SDK�ӿ� \n
* @param [IN]   *pstUserLogIDInfo       �û���Ϣ
* @param [OUT]  *pstUnitedRecDomainCfg  ��¼�����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUnitedRecRetrievalPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  UNITED_REC_DOMAIN_CFG_S    *pstUnitedRecDomainCfg
);

/**
* ���÷���������¼��������ò��� \n
* @param [IN]   *pstUserLogIDInfo       �û���Ϣ
* @param [IN]   *pstUnitedRecDomainCfg  ��¼�����������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetUnitedRecRetrievalPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   UNITED_REC_DOMAIN_CFG_S    *pstUnitedRecDomainCfg
);

/* Begin added by wuweiping/01403 2013.01.06 for IVSD06510 NVR��DDNS��Ϣ����*/
/**
* ��ȡDDNS���õĻ�����Ϣ. \n
* @param [IN] USER_LOGIN_ID_INFO_S * pstUserLogIDInfo  �û���Ϣ
* @param [OUT] DDNS_INFO_FOR_ECR_S * pstDDNSInfo DDNS������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDDNSInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT DDNS_INFO_FOR_ECR_S   *pstDDNSBaseInfo
);

/**
* �޸�DDNS���� \n
* @param [IN]   USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   DDNS_INFO_FOR_ECR_S   *pstDDNSBaseInfo    DDNS��Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note �������޸�DDNS�Ŀ�����ر�״̬
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDDNSInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN DDNS_INFO_FOR_ECR_S   *pstDDNSBaseInfo
);
/* End added by wuweiping/01403 2013.01.06 for IVSD06510 NVR��DDNS��Ϣ����*/

/* Begin Added by zhudingjingKF0104, 2013-06-18 of �����Խ���Դ�� */
/**
* ��ʼ�����㲥��㲥��������ʧ�ܵ���������������ʧ�ܣ��򷵻�ʧ�� \n
* @param [IN]       pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]       szXPVocBrdCode          �����㲥����
* @param [IN]       szGroupCode             �㲥�����
* @param [IN]       ulOperateCode           ����ԭ����
* @param [OUT]      pulUnitNum               �㲥�鵥Ԫ����
* @param [OUT]      pstVocBrdUnit           �����㲥��Ԫ�б���Ϊ����ʱ����д״̬
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.����֧��ͬʱ����#MAX_VOCBRD_CAM_NUM���㲥��Ԫ���������㲥��������Щ�㲥��Ԫ�������ڱ���
* - 2.ulOperateCodeȡֵ�μ�CS_OPERATE_CODE_E
* - 3.szXPVocBrdCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
* - 4. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartVoiceBrdGroupForECR
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN      CHAR                            szXPVocBrdCode[IMOS_RES_CODE_LEN],
    IN      CHAR                            szGroupCode[IMOS_RES_CODE_LEN],
    IN      ULONG_32                           ulOperateCode,
    OUT     ULONG_32                           *pulUnitNum,
    OUT     VOC_BRD_UNIT_S                  *pstVocBrdUnit
);

/**
* ֹͣ�����㲥�� \n
* @param [IN]       pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]       szXPVocBrdCode          �����㲥����
* @param [IN]       szGroupCode             �㲥�����
* @param [IN]       ulOperateCode           ����ԭ����
* @param [OUT]      pulUnitNum              �㲥�鵥Ԫ����
* @param [OUT]      pstVoiceBrdUnit         �����㲥��Ԫ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.ulOperateCodeȡֵ�μ�CS_OPERATE_CODE_E
* - 2.szXPVocBrdCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
* - 3. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopVoiceBrdGroupForECR
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN      CHAR                            szXPVocBrdCode[IMOS_RES_CODE_LEN],
    IN      CHAR                            szGroupCode[IMOS_RES_CODE_LEN],
    IN      ULONG_32                           ulOperateCode,
    OUT     ULONG_32                           *pulUnitNum,
    OUT     VOC_BRD_UNIT_S                  *pstVocBrdUnit
);

/**
* ��ѯĳ���㲥�������㲥��Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szXPVocBrdCode          �����㲥����
* @param [IN]   szGroupCode             �㲥�����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstVocBrdUnit           �����㲥��Ԫ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. szXPVocBrdCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVoiceBrdGroupInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szXPVocBrdCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szGroupCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT VOC_BRD_UNIT_S              *pstVocBrdUnit
);

/**
* @brief���ö�����Ƶ���� \n
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo �û���Ϣ
* @param [IN] DEV_CHANNEL_INDEX_S   *pstChannelIndex ͨ��������Ϣ
* @param [IN] AUDIO_INPUT_INFO_S    *pstAudioInInfo   ������Ƶ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigEcAudioInForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  AUDIO_INPUT_INFO_S          *pstAudioInInfo
);

/**
*@brief��ѯ������Ƶ�����б� \n
*@param [IN] USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo �û���Ϣ
*@param [IN] COMMON_QUERY_CONDITION_S  *pstQueryCondition   ��ѯ��Ϣ����
*- ����Ϊ��
*@param [IN] QUERY_PAGE_INFO_S         *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param[OUT] AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S  *pstAudioInAndChannelList ������Ƶ���뼰ͨ����ѯ�б�
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
*@note:
* - 1. �˽ӿ�������, ����
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioInputListForECR
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S             *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                    *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                      *pstRspPageInfo,
    OUT AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S  *pstAudioInAndChannelList
);

/**
*@brief��ѯ������Ƶ������ϸ��Ϣ \n
*@param [IN] USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo �û���Ϣ
*@param [IN] DEV_CHANNEL_INDEX_S    *pstChannelIndex  ͨ��������Ϣ
*@param [OUT] AUDIO_INPUT_INFO_S    *pstAudioInInfo   ������Ƶ������Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioInputInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT AUDIO_INPUT_INFO_S          *pstAudioInInfo
);

/**
*@brief���ö�����Ƶ��� \n
*@param [IN] USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo �û���Ϣ
*@param [IN] DEV_CHANNEL_INDEX_S    *pstChannelIndex  ͨ��������Ϣ
*@param [IN] AUDIO_OUTPUT_INFO_S    *pstAudioInInfo   ������Ƶ�����Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigEcAudioOutForECR
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S        *pstChannelIndex,
    IN  AUDIO_OUTPUT_INFO_S        *pstAudioOutInfo
);

/**
*@brief��ѯ������Ƶ����б� \n
*@param [IN] USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo �û���Ϣ
*@param [IN] COMMON_QUERY_CONDITION_S  *pstQueryCondition   ��ѯ��Ϣ����
*- ����Ϊ��
*@param [IN] QUERY_PAGE_INFO_S         *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param[OUT] AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S  *pstAudioInAndChannelList ������Ƶ�����ͨ����ѯ�б�
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
*@note:
* - 1. �˽ӿ�������, ����
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioOutputListForECR
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S              *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                     *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                       *pstRspPageInfo,
    OUT AUDIO_OUT_AND_CHANNEL_INFO_FOR_ECR_S  *pstAudioOutAndChannelList
);

/**
*@brief��ѯ������Ƶ�����ϸ��Ϣ \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo �û���Ϣ
*@param [IN] DEV_CHANNEL_INDEX_S   *pstChannelIndex  ͨ��������Ϣ
*@param [OUT] AUDIO_OUTPUT_INFO_S  *pstAudioOutInfo  ������Ƶ�����Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioOutputInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT AUDIO_OUTPUT_INFO_S         *pstAudioOutInfo
);

/**
*@brief��ѯ������Դ�б� \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo   �û���Ϣ
*@param [IN] QUERY_PAGE_INFO_S     *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param [OUT] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList ������Դ�б�
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioResListForECR
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S         *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S           *pstRspPageInfo,
    OUT AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList
);

/**
*@brief��ѯ������Դ��ϸ��Ϣ \n
*@param [IN] USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
*@param [IN] CHAR                       *pcAudioResCode   ������Դ����
*@param [OUT] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfo  ������Դ��Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szAudioResCode[IMOS_RES_CODE_LEN],
    OUT AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfo
);

/**
*@brief����������Դ��ϸ��Ϣ \n
*@param [IN] USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
*@param [IN] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfo  ������Դ��Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  AUDIO_RES_INFO_FOR_ECR_S   *pstAudioResInfo
);

/**
*@brief��ѯ������ɰ󶨵�������Դ�б� \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo   �û���Ϣ
*@param [IN] CHAR  szCamCode[IMOS_CODE_LEN] ���������
*@param [IN] QUERY_PAGE_INFO_S     *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param [OUT] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList ������Դ�б�
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamAvailableAudioResListForECR
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                                          szCamCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S         *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S           *pstRspPageInfo,
    OUT AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList
);

/**
*@brief �޸��������������Դ��Ϣ \n
*@param [IN] USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo �û���Ϣ
*@param [OUT]CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResInfo �������������Դ��Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
*@note:
* - 1. �˽ӿ�������, ����
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamBindAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S      *pstCamBindAudioResInfo
);

/**
*@brief��ѯ�������������Դ��Ϣ�б�\n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo   �û���Ϣ
*@param [IN] QUERY_PAGE_INFO_S     *pstQueryPageInfo   �����ҳ��Ϣ
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     ���ط�ҳ��Ϣ
*@param [OUT] CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResList �������������Դ��Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamBindAudioResListForECR
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S     *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S       *pstRspPageInfo,
    OUT CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResList
);

/**
*@brief ��ѯ�������������Դ��Ϣ \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo �û���Ϣ
*@param [IN] CHAR                  szResCode[IMOS_RES_CODE_LEN] ���������/������Դ����
*@param [OUT] CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResInfo �������������Դ��Ϣ
*@return �������½����
*- �ɹ���
*- ʧ�ܣ�
*-      ���ز�������룬���������ļ�
*@note
* - 1. ���szResCode����Ϊ������������������Դ����
* - 2. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamBindAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  CHAR                  szResCode[IMOS_RES_CODE_LEN],
    OUT CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResInfo
);
/* End Added by zhudingjingKF0104, 2013-06-18 of �����Խ���Դ�� */

/** Begin:add by sunxiaojisKF0138, 2013-7-18 of NVRV3R1 **/
/**
* �ӵ�����������Ϣ���͸�IO������ \n
* @param [IN]USER_LOGIN_ID_INFO_S        *pstUserInfo   �û���¼��Ϣ
* @param [IN]SERIAL_OF_IO_INFO_FOR_ECR_S *pstSerialInfo ������Ϣ
* @param [IN]ULONG                       ulIOInfoLen    ��Ϣ���ݳ���
* @param [IN]CHAR                        *pcIOInfo      Ҫ���͵���Ϣ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendMsgToIOForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserInfo,
    IN  SERIAL_OF_IO_INFO_FOR_ECR_S *pstSerialInfo,
    IN  ULONG_32                       ulIOInfoLen,
    IN  CHAR                        *pcIOInfo
);
/** End:add by sunxiaojisKF0138, 2013-7-18 of NVRV3R1 **/

#if 0
#endif

/**
* ����MAPM \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstMAPMInfo             MAPM��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAPM_INFO_S                     *pstMAPMInfo
);

/**
* ɾ��MAPM \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szMAPMCode              MAPM����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMAPMCode[IMOS_CODE_LEN]
);

/**
* �޸�MAPM \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstMAPMInfo               MAPM��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAPM_INFO_S                     *pstMAPMInfo
);

/**
* ��ѯMAPM \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szMAPMCode              MAPM����
* @param [OUT]  pstMAPMInfo             MAPM��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMAPMCode[IMOS_CODE_LEN],
    OUT MAPM_INFO_S                     *pstMAPMInfo
);

/**
* ��ѯMAPM�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#NAME_TYPE[�豸����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstMAPMList             MAPM�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMAPMList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT MAPM_INFO_S                     *pstMAPMList
);

/**
* ͬ��GIS��ͼ����Դ��λ��Ϣ������
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDevGisInfo       �豸�ĵ�λ��Ϣ
* @param [IN]   pstGisDbInfo        GIS���ݿ����Ϣ(�˲�����ʱδʹ�ã�����)
* @param [IN]
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SyncGisResToConfig
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_WEBGIS_INFO_S               *pstDevGisInfo,
    IN  DATABASE_INFO_S                 *pstGisDbInfo
);

/**
* ��ѯBM������Դ�б�V2 \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szBMCode               BM����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[BM��Դ����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKBMResList        BM������Դ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBMResListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBMCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT BM_RES_QUERY_ITEM_S_V2         *pstSDKBMResList
);


/* Begin Add by zhengyibing(01306), 2014-05-30 for �¹����޸Ķ��� */
/**
* @brief ��ѯ�������������Ϣ\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
* @param [IN]   CHAR                        szCameraCode   ���������
* @param [IN]   ULONG_32                    ulCameraConfigQueryType  ��������ò�ѯ��ʽ ���ö�� CAMERA_CONFIG_INF0_REQ_TYPE_E
* @param [OUT]  CAMERA_CONFIG_INFO_RES_S   *pstConfigInfo ����������ò�ѯ���
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraConfiureInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulCameraConfigQueryType,
    OUT CAMERA_CONFIG_INFO_RES_S        *pstConfigInfo
);

/*  Begin add by liujian/02319, 2016-07-06 for 2016 �����豸���� */
/**
* @brief ��ѯ�������������Ϣ\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
* @param [IN]   CHAR                        szCameraCode   ���������
* @param [IN]   ULONG_32                    ulCameraConfigQueryType  ��������ò�ѯ��ʽ ���ö�� CAMERA_CONFIG_INF0_REQ_TYPE_E
* @param [OUT]  CAMERA_CONFIG_INFO_RES_EXT_S   *pstConfigInfo ����������ò�ѯ���
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraConfiureInfoExt
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulCameraConfigQueryType,
    OUT CAMERA_CONFIG_INFO_RES_EXT_S        *pstConfigInfo
);
/*  End add by liujian/02319, 2016-07-06 for 2016 �����豸���� */

/**
* @brief �����������������Ϣ\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
* @param [IN]  CHAR                       szCameraCode   ���������
* @param [IN]  CAMERA_CONFIG_INFO_S       *pstConfigInfo  �������������Ϣ
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCameraConfiureInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN CAMERA_CONFIG_INFO_SET_S          *pstConfigInfo
);

/* Begin add by liujian/02319, 2016-07-06 for 2016 �����豸���� */
/**
* @brief �����������������Ϣ\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo �û���Ϣ
* @param [IN]  CHAR                       szCameraCode   ���������
* @param [IN]  CAMERA_CONFIG_INFO_SET_EXT_S       *pstConfigInfo  �������������Ϣ
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCameraConfiureInfoExt
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN CAMERA_CONFIG_INFO_SET_EXT_S          *pstConfigInfo
);
/* End add by liujian/02319, 2016-07-06 for 2016 �����豸���� */

/* End Add by zhengyibing(01306), 2014-05-30 for �¹����޸Ķ��� */

/* Begin Add By hexiaojun/hW0959 for ����֧��˫���� 2014-8-21*/
/**
* @brief ��ѯ�������������������Ϣ\n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo �û���Ϣ
* @param [IN]   CHAR                        szCameraCode   ���������
* @param [IN]   ULONG_32                    ulCameraConfigQueryType  ��������ò�ѯ��ʽ ���ö�� CAMERA_CONFIG_INFO_REQ_TYPE_E
* @param [OUT]  GB_PROFILES_S               *pstGbProfileConfigInfo ����������ò�ѯ���
* @return �������½��:
* - �ɹ�:
* - ʧ��:
* -     ���ز��������:��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGbCameraStreamInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    IN  ULONG_32                        ulCameraConfigQueryType,
    OUT GB_PROFILES_S                   *pstGbProfileConfigInfo
);
/* End Add By hexiaojun/hW0959 for ����֧��˫���� 2014-8-21 */

/* Begin add by zhengyibing/01306 2015/01/05 for onvif�������������� */
/**
* ��ȡonvif����������ò���. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [OUT]  ULONG_32                 ulOnvifStreamStrategy   onvif��������������ò��� 0:����Ӧ 1:��һ����
@return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - #ERR_AS_GET_TIME_FAIL
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetOnvifStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    OUT  ULONG_32                    *pulOnvifStreamStrategy
);


/**
* ����onvif����������ò���. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [OUT]  ULONG_32                 ulOnvifStreamStrategy   onvif��������������ò��� 0:����Ӧ 1:��һ����
@return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - #ERR_AS_GET_TIME_FAIL
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                    ulOnvifStreamStrategy
);
/* End add by zhengyibing/01306 2015/01/05 for onvif�������������� */

/**
* ��ѯBM������Դ�б�V3 \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szBMCode               BM����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[BM��Դ����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKBMResList        BM������Դ�б�
* @return ULONG �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBMResListV3
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBMCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT BM_RES_QUERY_ITEM_S_V3         *pstSDKBMResList
);


/**
* ��ѯ���Э����Ϣ\n
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����NULL)
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  pDomainProtocolInfoList   �������Э����Ϣ����
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note
* - ����ͨ�ò�ѯ����:
*     IS_DEFAULT_SG[�Ƿ�Ĭ��SG]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDomainProtocolInfo
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                     *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                       *pstRspPageInfo,
    OUT DOMAIN_PROTOCOL_INFO_S          *pDomainProtocolInfoList
);

/**
* ɾ�����Э����Ϣ\n
* @param [IN]   pstUserLogIDInfo   �û���Ϣ
* @param [IN]   ulProtocolType      Э������
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDomainProtocol
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  ULONG_32                                     ulProtocolType
);

/*Begin added by liangchao, 2015-11-25 for BM2516������*/
/**
* ����ֶ����������������\n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [OUT]  MANUL_BAKTASK_GROUP_S *pstManulBakTaskInfo      �ֶ�������������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ADDManualBakTaskGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  MANUL_BAKTASK_GROUP_S  *pstManulBakTaskInfo
);

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetManualBakV2
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo,
    IN  MANUL_BAK_INFO_S          *pstManulBakInfo,
    OUT CHAR                      szTaskCode[IMOS_CODE_LEN]
);

/**
* ɾ���ֶ���������\n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [OUT]  CHAR *szManulBakTaskGroupCode      ���������
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelManualBakTaskGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szManulBakTaskGroupCode[IMOS_CODE_LEN]
);

/**
* ��ѯ���������б� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  MANUL_BAKTASK_ORG_S *pstManulBakTaskOrgInfo      ����������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManualBakTaskGroupList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MANUL_BAKTASK_ORG_S       *pstManulBakTaskOrgInfo
);


/**
* ��ѯĳ������������������б� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   CHAR    szManulBakTaskGroupCode   �����������
* @param [IN]   CHAR    szCamName       ���������(֧��ģ����ѯ)
* @param [IN]   CHAR    szCamName       ���������
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  MANUL_BAKTASK_ORG_S *pstManulBakTaskOrgInfo      ����������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
* @note ��������벻Ϊ��ʱ��ֻ����������
* @note ���������Ϊ��ʱ��ֻ���Ƽ������֣���������
* @note ��������Ʋ�Ϊ��ʱ���������������ģ����ѯ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManualBakTaskGroupInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szManulBakTaskGroupCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    IN  CHAR                        szCamName[IMOS_NAME_LEN],
    IN  CHAR                        szCamCode[IMOS_CODE_LEN],
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MANUL_BAKT_PROGRESS_S       *pstManulBakTaskInfo
);

#if 0
#endif
/**
* ���BM������������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   BYWEEK_BM_INFO_S               *pstBMInfo                  BM��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddBMV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BYWEEK_BM_INFO_S                   *pstBMInfo
);

/**
* �޸�BM������������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   ALL_BM_INFO_S               *pstBMInfo                  BM��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֻ�����޸�:BM�豸���ƣ������ԣ����ݿ�ʼʱ�䣬���ݽ���ʱ�䡣
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBMV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BYWEEK_BM_INFO_S                   *pstBMInfo
);
/**
* ��ѯ������BM������ \n
* szOrgCodeֵ��Ч�����κ�ֵ����ֻ��ѯ����BM�б�
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo     �û���¼ID��Ϣ��ʶ
* @param [IN]  CHAR  szBMCode[IMOS_DEVICE_CODE_LEN]               BM����
* @param [OUT]  OUT BYWEEK_BM_INFO_S             *pstSDKBMInfo          BM��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBMV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR  szBMCode[IMOS_DEVICE_CODE_LEN],
    OUT BYWEEK_BM_INFO_S             *pstSDKBMInfo
);
/**
* ��ָ������������ɾ��ָ������� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   CHAR    szManulBakTaskGroupCode   �����������
* @param [IN]   CHAR     szCamCode   ���������
* @param [IN]   CHAR     szTaskCode   �������
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamFromManualBakTaskGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szManulBakTaskGroupCode[IMOS_CODE_LEN],
    IN  CHAR                        szCamCode[IMOS_CODE_LEN],
    IN  CHAR                    szTaskCode[IMOS_CODE_LEN]
);
/*End added by liangchao, 2015-11-25 for BM2516������*/

/**
* ��ҳ��ѯEC�豸�µ�������Լ�ͨ���б� \n
* ����Ϊ��ʱ,������,������Ĭ������(��Ƶ����ͨ����������)����
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode              ����������
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#INDEX_TYPE[ͨ������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstCamAndChannelList   ������Լ�ͨ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraAndChannelListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CAM_AND_CHANNEL_QUERY_ITEM_V2_S    *pstCamAndChannelList
);

/**
* ��ѯEC����ͨ����Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [OUT]  pstVideoInChannelInfo       ����ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECVideoInChannelV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT VIN_CHANNEL_V3_S                   *pstVideoInChannelInfo
);


/**
* ����EC����ͨ��ͨ����չ��Ϣ
* @param [IN] USER_LOGIN_ID_INFO_S  pstUserLogIDInfo            �û���Ϣ
* @param [IN] DEV_CHANNEL_INDEX_S   pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN] VIN_CHANNEL_EXTEND_S  pstVideoInChannelInfo       ����ͨ����չ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigVideoInChannelV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIN_CHANNEL_V3_S            *pstVideoInChannelInfo
);

/**
* ��������󶨵�EC ��ĳ��ͨ���ϣ���Ҫ����������Ϣ��֧�ֳ���OSD���ڸ�������Ƶ�����ڵ���������˶������������Ԫ�ر䳤
* @param [IN]  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo             �û���Ϣ
* @param [IN]  VINCHNL_BIND_CAMERA_BASE_V2_S       *pstVINBindCamBaseInfo        ����������ͨ���Ļ�����Ϣ
* @param [IN]  VINCHNL_FULL_VARIETY_ELEMENT_S   *pstVINFullVarietyElement     ��Ƶͨ��ȫ���䳤Ԫ�ؽṹ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* 1.��������벻��Ϊ��,�Ҳ��ܰ����ո�
* 2.�䳤Ԫ�ظ����ͱ䳤Ԫ���ڴ泤���ɵ����߱�֤���䳤Ԫ�ظ������ɴ��ڱ䳤Ԫ��ʵ���ڴ泤��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelV4
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLoginIDInfo,
    IN  VINCHNL_BIND_CAMERA_BASE_V3_S              *pstVINBindCamBaseInfo,
    IN  VINCHNL_FULL_VARIETY_ELEMENT_S          *pstVINFullVarietyElement
);


/**��ѯĳ���豸�ϴ��ڵ�ҵ����Ϣ
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szResCode                   ��Դ����
* @param [IN]   ulResType                   ��Դ����  IMOS_TYPE_E
* @param [IN]   ulextraParam                ����Դ����Ϊ1001����ʾ�Ƿ���������
                                            ����Դ����Ϊ2ʱ����ʾ�Ƿ��� NVR/ECR
* @param [OUT]  SERVICE_INFO_ON_RES_S       stServiceInfo     �豸ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceInfoOnRes
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo,
    IN   CHAR                           szResCode[IMOS_CODE_LEN],
    IN   ULONG_32                        ulResType,
    IN   ULONG_32                        ulExtraParam,
    IN   QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT  SERVICE_INFO_ON_RES_S          *pstServiceInfo

);

/**��ѯ��֯�������������֯��Ϣ
* ��ѯ��֯���������֯�ڵ㹲����Ϣ�б�ֻ��ȡһ�� \n
* �����ѯ����ʱ,������,��Ĭ������(��֯��������)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo   	�û���Ϣ
* @param [IN]   CHAR                        szOrgCode           	��֯�ڵ����
* @param [IN]   CHAR                        szExDomainCode     		�������
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  	ͨ�ò�ѯ����(����NULL;��������:NAME_TYPE[��֯����],IS_QUERY_SUB[�Ƿ������֯,=1��,=0��])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   	�����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     	���ط�ҳ��Ϣ
* @param [OUT]  SHARE_ORG_INFO_S          *pstOrgShareList    	������֯������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllShareSubOrgList
(
	IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SHARE_ORG_INFO_S              *pstOrgShareList
);


/**
* ��ѯ�豸�Ŀ������б�V3(���Ӹ澯Դ���߸澯����Ƿ�ʹ��) \n
* �����ѯ����ʱ,������,��Ĭ������(��������������)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo   �û���Ϣ��ʶ
* @param [IN]   CHAR                        szDevCode           �豸����
* @param [IN]   ULONG_32                       ulDevType           �豸����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  ͨ�ò�ѯ����(����NULL;��������:#INDEX_TYPE[����������])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     ���ط�ҳ��Ϣ
* @param [OUT]  SEMA_QUERY_ITEM_S           *pstSemaList        ��������ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchListV3
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                       ulDevType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SEMA_QUERY_ITEM_V3_S        *pstSemaListV3
);

#if 0
#endif

/** ���ӿ���λ���мƻ�
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   pstGuardPositionInfo      ���ؼƻ���Ϣ
* @param [OUT]  szGuardPositionPlanCode   ���ؼƻ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  GUARD_POSITION_PLAN_INFO_S      *pstGuardPositionInfo,
    OUT CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN]
);

/**
* �޸Ŀ���λ���мƻ�
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szGuardPositionPlanCode   ���ؼƻ�����
* @param [IN]   pstGuardPositionInfo      ���ؼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN],
    IN  GUARD_POSITION_PLAN_INFO_S      *pstGuardPositionPlanInfo
);

/**
* ����/ֹͣ����λ���мƻ� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szGuardPositionPlanCode ����λ���мƻ�����
* @param [IN]   ulOperateCode           ����ģʽ
* @param [IN]   ulPlanMode              �ƻ������ǣ�0ֹͣ��1����
@return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ulPlanModeȡֵ�μ�#PLAN_OPER_MODE_E
*       ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulOperateCode,
    IN  ULONG_32                        ulPlanMode
);

/**
* ��ѯ����λ���мƻ�
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szSwitchPlanCode          ���ؼƻ�����
* @param [OUT]  pstGuardPositionPlanInfo  ���ؼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN],
    OUT GUARD_POSITION_PLAN_INFO_S      *pstGuardPositionPlanInfo
);

/**
* ��ѯ����λ�ƻ��б� \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CHAR                        szOrgCode               ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      ͨ�ò�ѯ����
* - ����NULL
* - ��������:NAME_TYPE(�ƻ�����),TIME_TYPE(����ʱ��),CODE_TYPE(���������)
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  GUARD_POSITION_PLAN_QUERY_ITEM_S      *pstGuardPositionPlanList      ���ؼƻ��б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPositionPlanList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT GUARD_POSITION_PLAN_QUERY_ITEM_S      *pstGuardPositionPlanList
);
/**
* ��ҳ��ѯ��֯�µĸ澯Դ�ĸ澯���������б�  \n
* @param [IN]   pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]   szOrgCode              ��֯����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[�澯Դ����]��#EVENT_TYPE[�¼�����]��#ACTION_TYPE[��������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstAlarmLinkageList    �澯������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkageList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALARM_LINKAGE_QUERY_ITEM_S  *pstAlarmLinkageList
);

/**
* ��ҳ��ѯ�澯Դ�ĸ澯�����¼��б�  \n
* @param [IN]   pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]   szAlarmSrcCode         �澯Դ����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(Ԥ��,Ŀǰֻ��ΪNULL)
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pulDevType             �豸���ͣ�����ö��ȡֵ�μ�#IMOS_TYPE_E��
* @param [OUT]  pulDevSubType          �豸�����ͣ�����ö��ȡֵ�μ�#IMOS_DEVICE_TYPE_E��
* @param [OUT]  pulParentDevType       ���豸���ͣ�����ö��ȡֵ�μ�#IMOS_TYPE_E��
* @param [OUT]  pulParentSubDevType    ���豸�����ͣ�����ö��ȡֵ�μ�#IMOS_DEVICE_TYPE_E��
* @param [OUT]  pstAlarmLinkEventList  �澯�����¼��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmSrcEventList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szAlarmSrcCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT ULONG_32                    *pulDevType,
    OUT ULONG_32                    *pulDevSubType,
    OUT ULONG_32                    *pulParentDevType,
    OUT ULONG_32                    *pulParentSubDevType,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALARM_LINK_EVENT_QUERY_ITEM_S *pstAlarmLinkEventList
);

/* begin: added by yW1054 in 2014-8-21 for ��־��Ʒ����� */
/**
* ���LS������������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   LS_INFO_S               *pstSDKLSInfo           LS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.LS��Ϣ�е�LS������LS��������Ψһ��ʶ
* -     2.LS���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddLS
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN LS_INFO_S                    *pstSDKLSInfo
);

/**
* ��ѯĳ��LS�ľ�����Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                   �û���Ϣ
*@param[IN]CHAR  szLSCode[IMOS_DEVICE_CODE_LEN]      LS����
* @param [OUT]  LS_INFO_S               *pstSDKLSInfo                       LS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLSInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR      szLSCode[IMOS_DEVICE_CODE_LEN],
    OUT  LS_INFO_S                   *pstSDKLSInfo
);


/**
* �޸�LS�����������벻���޸ģ�������Ҫ���� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   LS_INFO_S               *pstSDKLSInfo      LS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ��ERR_COMMON_SUCCEED?
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyLS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  LS_INFO_S                   *pstSDKLSInfo
);

/**
* ɾ��LS������ \n
*@param[IN]USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo    �û���Ϣ
*@param[IN]CHAR   szLSCode[IMOS_DEVICE_CODE_LEN]      LS����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֻ��һ����ɾ��LS������ɾ��LS�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelLS
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN CHAR       szLSCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯĳ����֯�µ�LS�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CHAR             szOrgCode               ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[LS����])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  LS_QUERY_ITEM_S             *pstSDKLSList           LS�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note  1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�LS�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLSList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR           szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT LS_QUERY_ITEM_S             *pstSDKLSList
);


/* end: added by yW1054 in 2014-8-21 for ��־��Ʒ�����*/

/* Begin: Added by zhongke z01354, 2014-10-28 for uniview_keyboard */
/**
* ��Ӽ��̡�
* @param [IN]   pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]   pstKeyboardInfo       ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
ULONG_32 STDCALL IMOS_AddKeyboard
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN    KEYBOARD_INFO_S               *pstKeyboardInfo
);

/**
* �޸ļ���,�����豸���벻�����޸ģ�������Ҫ���롣
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   pstKeyboardInfo               ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_ModifyKeyboard
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  KEYBOARD_INFO_S                 *pstKeyboardInfo
);

/**
* ɾ������
* @param [IN] pstUserLoginIDInfo              �û���Ϣ��ʶ
* @param [IN] szKeyboardIP                    ����IP
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_DelKeyboard
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szKeyboardIP[IMOS_IPADDR_LEN]
);

/**
* ��ѯĳ�����̵���Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   szKeyboardIP                  ����IP
* @param [OUT]  pstKeyboardInfo               ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_QueryKeyboardInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szKeyboardIP[IMOS_IPADDR_LEN],
    OUT KEYBOARD_INFO_S                 *pstKeyboardInfo
);

/**
* ��ѯ�����б� \n
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstKeyboardList             ������Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
ULONG_32 STDCALL IMOS_QueryKeyboardList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT KEYBOARD_INFO_S                 *pstKeyboardList
);

/**
* ���ü��̵�ȫ������������б�
* @param [IN]  pstUserLoginIDInfo       �û���Ϣ
* @param [IN]  ulRelationListNum        �����б����
* @param [IN]  pstKeyboardCamera        ����������б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_ConfigKeyboardCamera
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulRelationListNum,
    IN  KEYBOARD_CAMERA_S            *pstKeyboardCamera
);

/**
* ���ü��̵�ȫ�ּ����������б�
* @param [IN]  pstUserLoginIDInfo       �û���Ϣ
* @param [IN]  ulRelationListNum        �����б����
* @param [IN]  pstKeyboardMonitor       �����������б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_ConfigKeyboardMonitor
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulRelationListNum,
    IN  KEYBOARD_MONITOR_S           *pstKeyboardMonitor
);

/**
* ɾ������ĳ�������������Ϣ
* @param [IN] pstUserLoginIDInfo              �û���Ϣ��ʶ
* @param [IN] ulKeyboardControlNumber         ���̿��Ʊ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_DelKeyboardCamera
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulKeyboardControlNumber
);

/**
* ɾ������ĳ��������������Ϣ
* @param [IN] pstUserLoginIDInfo              �û���Ϣ��ʶ
* @param [IN] ulKeyboardControlNumber         ���̿��Ʊ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_DelKeyboardMonitor
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulKeyboardControlNumber
);

/**
* ��ѯ����������б�  \n
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstKeyboardCameraList       �����������Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
ULONG_32 STDCALL IMOS_QueryKeyboardCameraList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT KEYBOARD_CAMERA_S               *pstKeyboardCameraList
);

/**
* ��ѯ���̼������б�  \n
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstKeyboardMonitorList      ���̼�������Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
ULONG_32 STDCALL IMOS_QueryKeyboardMonitorList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT KEYBOARD_MONITOR_S              *pstKeyboardMonitorList
);
/* End: Added by zhongke z01354, 2014-10-28 for uniview_keyboard */


/**
* ���ü��̵�ȫ��������Դ�����б�
* @param [IN]  pstUserLoginIDInfo       �û���Ϣ
* @param [IN]  ulRelationListNum        �����б����
* @param [IN]  pstKeyboardMonitor       ������Դ�����б���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_ConfigKeyboardSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                      ulRelationListNum,
    IN  KEYBOARD_SWITCHRES_S         *pstKeyboardSwitchRes
);

/**
* ��ѯ����������Դ�б�  \n
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstKeyboardSwitchResList       ����������Դ��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
ULONG_32 STDCALL IMOS_QueryKeyboardSwitchResList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT KEYBOARD_SWITCHRES_S               *pstKeyboardSwitchResList
);

/**
* ɾ������ĳ��������������Ϣ
* @param [IN] pstUserLoginIDInfo              �û���Ϣ��ʶ
* @param [IN] pszKeyboardMonitorCode          ����������
* @param [IN] ulKeyboardMonitorWindow         ����������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_DelKeyboardSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                     *pszKeyboardMonitorCode,
    IN  ULONG_32                  ulKeyboardMonitorWindow
);


#if 0
#endif

/**
* ����OSD���豸����
* @param [IN]  pstUserLoginIDInfo         �û���Ϣ
* @param [IN]  OSD_PART_ADD_S           ����OSD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ע�⵱�������������Ϊ'\0'ʱ,Ĭ��Ϊ����ģ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPartOSD
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  PART_OSD_INFO_S               *pstPartOsdInfo
);


/**
* ��ѯOSD���豸����
* @param [IN]  pstUserLoginIDInfo            �û���Ϣ
* @param [IN]  CHAR * szCameraCode     ���������
* @param [OUT]  OSD_PART_ADD_S         ���OSD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ע�⵱�������������Ϊ'\0'ʱ,Ĭ��Ϊ����ģ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPartOSD
(
    IN     USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN     CHAR                          *szCameraCode,
    OUT    PART_OSD_INFO_S               *pstPartOsdInfo
);

/* Begin Add By hexiaojun/hW0959 for �������̨�����Ƿ񾭹���̨������ 2015-1-15 */
/**
* �������̨�����Ƿ񾭹���̨������������ �������þ������������ò�����\n
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo        �û���Ϣ
* @param [IN] ULONG_32               ulPassFlag              0��ʾ��������̨��������1��ʾ������̨������
* @param [IN] ULONG_32               ulPassCamNum            ������ĸ���
* @param [IN] CAMERA_BASE_INFO_S    *pstCamList              ������б�

* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessPassPTZCtrollerCamList
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN  ULONG_32                 ulPassFlag,
    IN  ULONG_32                 ulPassCamNum,
    IN  CAMERA_BASE_INFO_S       *pstCamList
);
/* End Add By hexiaojun/hW0959 for �������̨�����Ƿ񾭹����������� 2015-2-9 */

/* Begin: Added by zhouquanwei/z01364, 2015-01-05 for ONVIF����֧�� */

/**
* ��ѯONVIF�������Ƶ������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                            szCameraCode[IMOS_CODE_LEN]     ���������
* @param [OUT]  ONVIF_VIDEO_ENCODER_CFGS_S      *pstVideoEncoderCfgs            ��Ƶ��������
* @param [OUT]  ONVIF_VIDEO_ENCODER_OPTIONS_S   *pstVideoEncoderOptions         ��Ƶ��������ѡ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifVideoEncodeing
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_VIDEO_ENCODER_CFGS_S      *pstVideoEncoderCfgs,
    OUT ONVIF_VIDEO_ENCODER_OPTIONS_S   *pstVideoEncoderOptions
);

/**
* �޸�ONVIF�������Ƶ������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     ���������
* @param [IN]  ONVIF_VIDEO_ENCODER_CFG_S    *pstVideoEncoderCfg             ������Ƶ��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifVideoEncodeing
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_VIDEO_ENCODER_CFG_S   *pstVideoEncoderCfg
);

/**
* ��ʱ��֧����Ƶ��������
*/
/**
* ��ѯONVIF�������Ƶ������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                            szCameraCode[IMOS_CODE_LEN]     ���������
* @param [OUT]  ONVIF_AUDIO_ENCODER_CFGS_S      *pstAudioEncoderCfgs            ��Ƶ�������ü���
* @param [OUT]  ONVIF_AUDIO_ENCODER_OPTIONS_S   *pstAudioEncoderOptions         ��Ƶ��������ѡ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifAudioEncodeing
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_AUDIO_ENCODER_CFGS_S      *pstAudioEncoderCfgs,
    OUT ONVIF_AUDIO_ENCODER_OPTIONS_S   *pstAudioEncoderOptions
);

/**
* ����ONVIF�������Ƶ������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     ���������
* @param [IN]   ONVIF_AUDIO_ENCODER_CFG_S   *pstAudioEncoderCfg             ��Ƶ��������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifAudioEncodeing
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_AUDIO_ENCODER_CFG_S   *pstAudioEncoderCfg
);

/**
* ��ѯONVIF�����ͼ����� \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     ���������
* @param [OUT]  ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings             ͼ������
* @param [OUT]  ONVIF_IMAGING_OPTIONS_S     *pstImagingOptions              ͼ������ѡ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifImagingSettings
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings,
    OUT ONVIF_IMAGING_OPTIONS_S     *pstImagingOptions
);

/**
* ����ONVIF�����ͼ����� \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     ���������
* @param [IN]   ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings             ͼ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifImagingSettings
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings
);

/**
* ��ѯONVIF������˶������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     ���������
* @param [OUT]  ONVIF_CELL_MOTION_INFO_S    *pstCellMotionInfo              �˶������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifCellMotion
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_CELL_MOTION_INFO_S    *pstCellMotionInfo
);

/**
* �޸�ONVIF������˶������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                    szCameraCode[IMOS_CODE_LEN]     ���������
* @param [OUT]  ONVIF_OSD_S             *pstOnvifOSD                    ONVIF OSD ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifCelMotion
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_CELL_MOTION_INFO_S    *pstCellMotionInfo
);

/**
* ��ѯONVIF�����OSD��Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                    szCameraCode[IMOS_CODE_LEN]     ���������
* @param [OUT]  ONVIF_OSDS_S            *pstOnvifOSDs                   ONVIF OSD ��Ϣ����
* @param [OUT]  ONVIF_OSD_OPTIONS_S     *pstOnvifOSDOptions             ONVIF OSD ѡ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifOSDs
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_OSDS_S            *pstOnvifOSDs,
    OUT ONVIF_OSD_OPTIONS_S     *pstOnvifOSDOptions
);

/**
* �޸�ONVIF�����OSD��Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                    szCameraCode[IMOS_CODE_LEN]     ���������
* @param [IN]   ONVIF_OSD_S             *pstOnvifOSD                    ONVIF OSD ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifOSD
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_OSD_MODIFY_S      *pstOnvifOSD
);
/* End: Added by zhouquanwei/z01364, 2015-01-05 for ONVIF����֧�� */

/**
* ��ѯDVR��NVR �µ�ͨ���б�  \n
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   CHAR                      szOrgCode                ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S  *pstQueryCondition       ��ѯ��Ϣ����
* @param [IN]   QUERY_PAGE_INFO_S         *pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S           *pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  NVR_CHL_CFG_INFO_S        *pstNvrChlInfoList          ͨ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note
*/
IMOS_EXPORT ULONG STDCALL IMOS_QueryNVRChannelInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT NVR_CHL_CFG_INFO_S          *pstNvrChlInfoList
);

#if 0
#endif
/* Begin Add By hexiaojun/hW0959 for ƽ̨֧��snmpV3 2015-4-9 */
/**
* ����SNMPģ�� \n
* @param [IN]   pstUserLoginIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKSnmpTemp              SNMPģ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  SNMP_TEMP_S                 *pstSDKSnmpTemp
);

/**
* �޸�snmpģ��
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   pstModifySnmpTempl            ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  SNMP_TEMP_S                     *pstModifySnmpTempl
);

/**
* ɾ��snmpģ��
* @param [IN] pstUserLoginIDInfo              �û���Ϣ��ʶ
* @param [IN] szSnmpTemplateName              snmpģ������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                         szSnmpTemplateId[IMOS_STRING_LEN_64]
);

/**
* ��ѯĳ��snmpģ��Ĳ�����Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   szSnmpTemplateName            snmpģ������
* @param [OUT]  pstSnmpTemplate               snmpģ�������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                        szSnmpTemplateId[IMOS_STRING_LEN_64],
    OUT SNMP_TEMP_S                     *pstSnmpTemplate
);

/**
* ��ѯsnmpģ���б� \n
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstSnmpTemplateList             ������Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySNMPTemplateList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SNMP_TEMP_S                     *pstSnmpTemplateList
);

/**
* �豸����snmpģ�壬��������һ��Ҳ������������\n
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo     �û���Ϣ
* @param [IN] ULONG_32              ulDeviceNum             �豸����
* @param [IN] DEV_SNMP_INFO_S       *pstDeviceList          �豸�б�

* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigDevSnmpTemplateList
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN  ULONG_32                 ulDeviceNum,
    IN  DEV_SNMP_INFO_S          *pstDeviceList
);

/**
* ��ѯĳ���豸��������һ��snmpģ��
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   szDevCode                     �豸����
* @param [OUT]  szSnmpTemplateId              �豸���õ�ģ��ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevSNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szDevCode[IMOS_CODE_LEN],
    OUT SNMP_TEMP_S                     *pstSnmpTemplate
);
/* End Add By hexiaojun/hW0959 for ƽ̨֧��snmpV3 2015-4-9 */
/* Begin Add by yaojinhai/y01359 2014-11-19 for A8 */
/**
* ���ӵ���ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       pstTVWallInfo      ����ǽ��Ϣ
* @param [OUT]    pcTVWallCode      ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_A8_S  *pstTVWallInfo,
    OUT     CHAR                    *pcTVWallCode
);

/**
* �޸ĵ���ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN][OUT]  pstTVWallInfo      ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_A8_S  *pstTVWallInfo
);

/**
* ɾ������ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTvWallCode       ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR       *pcTvWallCode
);

/**
* �������� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [INOUT]       pstWindowInfo                  ������Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenWindow
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    INOUT      TV_WALL_WINDOWS_INFO             *pstWindowInfo
);

/**
* �رմ��� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pcWindowCode                   ���ڱ���
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CloseWindow
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcWindowCode
);

/**
* �޸Ĵ��ڣ������ƶ������ţ� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstWindowInfo                  ������Ϣ
* @param [IN]       bSingleDB                          �Ƿ񵥴����ݿ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModWindow
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TV_WALL_WINDOWS_INFO             *pstWindowInfo,
    IN      BOOL_T                           bSingleDB
);

/**
* ���ô��ڲ�� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstWindowInfoList                   ��������
* @param [IN]       ulWindowNum                    ��������
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetWindowLevel
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TV_WALL_WINDOWS_INFO             *pstWindowInfoList,
    IN      ULONG_32                         ulWindowNum
);


/**
* ���ô���͸���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pcWindowCode                   ���ڱ���
* @param [IN]       ulTransparency                 ͸����(0-100), 0��͸��, 100ȫ͸��
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTVWallTransparency
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcWindowCode,
    IN      ULONG_32                         ulTransparency
);

/**
* �������ǽ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pcSceneName                  ��������
* @param [IN]       ulSceneID                      ����ID(1 - 32)
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note ����ֻ����32��������IDΪ1 - 32
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallSceneSave
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcSceneName,
    IN      ULONG_32                         ulSceneID
);

/**
* �޸ĵ���ǽ�������� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pcSceneName                  ��������
* @param [IN]       ulSceneID                      ����ID(1 - 32)
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note ����ֻ����32��������IDΪ1 - 32
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateTVWallSceneName
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcSceneName,
    IN      ULONG_32                         ulSceneID
);

/**
* ɾ������ǽ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulSceneID                      ����ID(1 - 32)
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallSceneDelete
(
   IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
   IN      CHAR                             *pcTVWallCode,
   IN      ULONG_32                         ulSceneID
);

/**
* ���Ƶ���ǽ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulFromID                       ����Դ����ID
* @param [IN]       ulToID                         ����Ŀ�ĵس���ID
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallSceneDup
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulFromID,
    IN      ULONG_32                         ulToID
);

/**
* �ϴ���ͼ \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pcBasePicName                   ����ǽ��ͼ����
* @param [IN]       ulBasePicID                    ��ͼID��(0 - 7)
* @param [IN]       pcBasePicPath                  ��ͼ����·��
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note �Ѿ����ڵı�Ž��и���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BasePicUpload
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcBasePicName,
    IN      ULONG_32                         ulBasePicID,
    IN      CHAR                             *pcBasePicPath
);

/**
* �󶨵�ͼ \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulBasePicID                    ��ͼID��
* @param [IN]       pstPosition                    ��ͼλ��
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BasePicBind
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulBasePicID,
    IN      AREA_SCOPE_S                     *pstPosition
);

/**
* ����ֹͣ��ͼ \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulEnabled                      0: ͣ��  1:����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BasePicEnable
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulEnabled
);

/**
* ��������LED \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstTVWallVirtualLEDInfo      LED��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVirtualLEDInfo
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_VIRTUAL_LED_INFO_S        *pstTVWallVirtualLEDInfo
);

/**
* ����/ͣ������LED \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulEnabled                      �Ƿ����ã�0: ͣ�� 1: ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulEnabled
);

/**
* ��������ǽ���������ȶԱȶ� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstTVWallAdjustBrightCNT             �������ȶԱȶ���Ϣ
* @return ULONG�������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�ERR_COMMON_FAIL
* -       �������������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustBrightCNT
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_ADJUST_BRIGHT_CNT_S       *pstTVWallAdjustBrightCNT
);

/**
* ���õ���ǽ��������ʱ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulDialSwitchID                 ƴ��������ID
* @param [IN]       pstTimerParam                  ��ʱ����
* @return ULONG�������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�ERR_COMMON_FAIL
* -       �������������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMonitorTimer
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulDialSwitchID,
    IN      TIMER_PARAM_S                    *pstTimerParam
);

/**
* ���õ���ǽ���������߻ָ� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       ulDialSwitchID                 ƴ��������ID
* @param [IN]       ulDormancy                    ���߻�ָ�
* @return ULONG�������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�ERR_COMMON_FAIL
* -       �������������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMonitorDormancy
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulDialSwitchID,
    IN      ULONG_32                         ulDormancy
);

/**
* ��������˿� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pcOutputCode                   ����˿ڱ���(���ΪNULL�����ʾ������������˿�)
* @param [IN]       ulTestMode                     ����ģʽ(TEST_MODE_E)
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OutputTest
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcOutputCode,
    IN      ULONG_32                         ulTestMode
);

/**
* ��������˿�EDID \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcInputCode                    ����˿ڱ���(���ΪNULL�����ʾ����A8��������˿�)
* @param [IN]       pcEDIDData                     EDID�ļ���
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetEDID
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcInputCode,
    IN      CHAR                             *pcEDIDName
);

/**
* ���õ���ǽ��Ƶ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcAudioInputCode              ��Ƶ����Դ����
* @param [IN]       pcTVWallCode                    ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAudioInput
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcAudioInputCode,
    IN      CHAR                             *pcTVWallCode
);

/**
* ���õ���ǽ��Ƶ��� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcAudioOutputCode           ��Ƶ�������
* @param [IN]       pcTVWallCode                    ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAudioOutput
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcAudioOutputCode,
    IN      CHAR                             *pcTVWallCode
);

/**
* ������Ƶ������� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                    ����ǽ����
* @param [IN]       ulIsEnable                          �Ƿ���
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAudioMute
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulIsEnable
);

/**
* ������Ƶ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                    ����ǽ����
* @param [IN]       pcOutputCode                    �������
* @param [IN]       ulVolume                            ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustOuputVolume
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcOutputCode,
    IN      ULONG_32                         ulVolume
);

/**
* ���õ���ǽ��Ƶ���������Ϣ \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstTVWallOutputAudioParam            ����ǽ��Ƶ���������Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetOutputAudioParam
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_OUTPUT_AUDIO_PARAM_S      *pstTVWallOutputAudioParam
);

/**
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  A8_INFO_S                       *pstA8Info
);

/**
* ����A8 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstA8Info             A8��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  A8_INFO_S                       *pstA8Info
);

/**
* ɾ��A8 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szA8Code                A8����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szA8Code[IMOS_CODE_LEN]
);

/**
* �޸�A8 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstA8Info               A8��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  A8_INFO_S                       *pstA8Info
);

/**
* ��ѯA8 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szA8Code                A8����
* @param [OUT]  pstA8Info               A8��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szA8Code[IMOS_CODE_LEN],
    OUT A8_INFO_S                       *pstA8Info
);

/**
* ��ѯA8�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [IN]   bIsQuerySub             �Ƿ��ѯ����֯
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstA8List               A8�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryA8List
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    IN  BOOL_T                          bIsQuerySub,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  A8_INFO_S                      *pstA8List
);


/**
* ���ӵ���ǽ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTVWallSceneGroup         ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroup
);

/**
* ɾ������ǽ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pcTVWallSceneGroupCode         ����ǽ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            *pcTVWallSceneGroupCode
);

/**
* �޸ĵ���ǽ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTVWallSceneGroup          ����ǽ������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroup
);

/**
* ��ѯ����ǽ������\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pcTVWallSceneGroupCode                ����ǽ���������
* @param [OUT]  pstTVWallSceneGroup               ����ǽ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            *pcTVWallSceneGroupCode,
    OUT TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroup
);

/**
* �޸�����ͼ����� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstVinChannelImageParam                   ����ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVinChannelImageParam
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      VIN_CHANNEL_IMAGE_PARAM_S        *pstVinChannelImageParam
);

/**
* ��ѯ����ͼ����� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcInputCode                   �������
* @param [OUT]    pstVinChannelImageParam        ͨ������ͼ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVinChannelImageParam
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcInputCode,
    OUT     VIN_CHANNEL_IMAGE_PARAM_S        *pstVinChannelImageParam
);

/**
* �޸�������� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pstVinChannelParam                   �������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVinChannelParamA8
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      VIN_CHANNEL_PARAM_A8_S        *pstVinChannelParam
);

/**
* ��ѯ������� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcInputCode                   �������
* @param [OUT]    pstVinChannelParam        ͨ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVinChannelParamA8
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcInputCode,
    OUT     VIN_CHANNEL_PARAM_A8_S        *pstVinChannelParam
);

/**
*����A8�豸�Ƿ��� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       szDevCode                   �豸����
* @param [OUT]    ulIsSmoothDisplay        �Ƿ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetA8SmoothDisplay
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szDevCode[IMOS_DEVICE_CODE_LEN],
    IN      ULONG_32                         ulIsSmoothDisplay
);

/**
*��ȡA8�豸�Ƿ��� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       szDevCode                   �豸����
* @param [OUT]    pulIsSmoothDisplay        �Ƿ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetA8SmoothDisplay
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT     ULONG_32                         *pulIsSmoothDisplay
);

/**
*���õ���ǽ�Ƿ��Զ����� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       szTVWallCode                   �豸����
* @param [OUT]    ulIsAutoAdsorbent        �Ƿ��Զ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTVWallAutoAdsorbent
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTVWallCode[IMOS_CODE_LEN],
    IN      ULONG_32                         ulIsAutoAdsorbent
);

/**
* ��ʼA8���� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szTVWallCode            ����ǽ����
* @param [IN]   szSwitchResCode         ������Դ����
* @param [IN]   szMonitorCode           ���ڱ���
* @param [IN]   ulOperateCode           ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartA8Switch
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szTVWallCode[IMOS_CODE_LEN],
    IN  CHAR                            szSwitchResCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ֹͣ�ֶ����� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szTVWallCode            ����ǽ����
* @param [IN]   szMonitorCode           ���ڱ���
* @param [IN]   ulOperateCode           ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ulOperateCodeȡֵ�μ�CS_OPERATE_CODE_E
*       szMonitorCode�����������Ϊ��Ӧ�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopA8Switch
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szTVWallCode[IMOS_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ��ȡ���ڽ�����Ϣ \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       szTVWallCode                   ����ǽ����
* @param [IN]       szWindowCode                   ���ڱ���
* @param [IN]       ulSplitNum                     ������
* @param [OUT]      pstTVWallWindowDecodeInfo      ���ڽ�����Ϣ
* @return ULONG�������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�ERR_COMMON_FAIL
* -       �������������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTVWallWindowDecodeInfo
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTVWallCode[IMOS_CODE_LEN],
    IN      CHAR                             szWindowCode[IMOS_CODE_LEN],
    IN      ULONG_32                         ulSplitNum,
    OUT     TVWALL_WINDOW_DECODE_INFO_S      *pstTVWallWindowDecodeInfo
);

/* End Add by yaojinhai/y01359 2014-11-19 for A8 */

/* Begin: Added by luchunfeng02289, 2015-12-28 for ADU */
/**
* ����DC�豸�����ѯ�����������ͨ��������Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szUACode                DC�豸����
* @param [OUT]  pulCount                ���ؼ�¼��
* @param [OUT]  pstDCCodeIndexInfo      �����������ͨ��������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDCScreenCodeAndChannelIndex
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN    CHAR                          szUACode[IMOS_DEVICE_CODE_LEN],
    OUT   ULONG_32                      *pulCount,
    OUT   DC_CODE_INDEX_INFO_S          *pstDCCodeIndexInfo
);
/* End: Added by luchunfeng02289, 2015-12-28 for ADU */

/* Begin: Added by luchunfeng02289, 2016-01-25 for ADU */
/**��ѯĳ����֯�µ�ADU�б�  \n
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstDcQueryList              ADU��ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryADUList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szcOrgCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ADU_TV_WALL_INFO_S              *pstADUQueryList
);
/* End: Added by luchunfeng02289, 2016-01-25 for ADU */

/*Begin added by fW2028, 2016-03-24 for MPPD35331*/
/**
* ��ѯ������DC������Դ�б�
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ������֯����
* @param [IN]   pstQueryPageInfo        �豸��ҳ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdDcRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo
);

/*Begin added by liangchao, 2016-03-21 for�����쳣�ָ�����*/
/**
* ����ʧ�����񲹱� \n
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   BAK_TASK_INFO_S           *pstManulBakInfo          �ֶ�����������Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRetryBakTask
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN  ADD_RETRY_BAK_INFO_S          *pstRetryBakInfo
);

/**
* ɾ���������� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                    szRetryTaskId[IMOS_CODE_LEN]  ��������ID
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelRetryBakTask
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                     szRetryTaskId[IMOS_CODE_LEN]
);

/**
* ��ѯʧ�������б� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  MANUL_BAKTASK_ORG_S *pstManulBakTaskOrgInfo      ����������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRetryBakTaskList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IMOS_RETRY_TASK_INFO_S      *pstRetryBakTaskOrgInfo
);

/*End added by liangchao, 2016-03-21 for�����쳣�ָ�����*/

/* Begin: Added by zW4671, 2017-09-04 for MPPD51479  ���ݻָ��б������������ */
/**
* ��ѯʧ�������б�V2 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN]   QUERY_PAGE_INFO_S        pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S          pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  IMOS_RETRY_TASK_INFO_V2_S  *pstRetryBakTaskOrgInfoV2     ����������Ϣ
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRetryBakTaskListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IMOS_RETRY_TASK_INFO_V2_S      *pstRetryBakTaskOrgInfoV2
);
/* End: Added by zW4671, 2017-09-04 for MPPD51479  ���ݻָ��б������������ */


/*Begin added by w01677, 2016-08-10 forVM2500����ǽ�����Ż� */
/**
* ��ѯ��������ع�ϵ�б� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ��ʶ
* @param [IN]   CHAR                    szMonitorCode         ����������
* @param [INOUT]   ULONG_32             *pulSplitScreenNum      ������������
* @param [INOUT]  SCREEN_MON_RELATION_S *pstScreenMonRelationList      ������ع�ϵ�б�
* @return ERR_COMMON_SUCCEED    ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenMonRelation
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szMonitorCode[IMOS_RES_CODE_LEN],
    INOUT  ULONG_32                 *pulSplitScreenNum,
    INOUT   SCREEN_MON_RELATION_S   *pstScreenMonRelationList
);
/*Eend added by w01677, 2016-08-10 forVM2500����ǽ�����Ż� */
/**Begin Added by liujia ,2016-03-15 for �����������*/
/**
* ��ѯ���۱���Ϣ
* @param [IN]	pstUserLoginIDInfo		�û���Ϣ
* @param [IN]	szFishEyeCode			���۱����
* @param [OUT]	pstFishEyeInfo			���۱���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFishEye
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CHAR						 szFishEyeCode[IMOS_CODE_LEN],
	OUT FISHEYE_INFO_S				*pstFishEyeInfo
);

/**
* �������۱���Ϣ
* @param [IN]	pstUserLoginIDInfo		�û���Ϣ
* @param [IN]	szFishEyeCode			���۱���
* @param [IN]	pstFishEyeInfo			���۱���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFishEye
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	FISHEYE_INFO_S				*pstFishEyeInfo
);
/**End Added by liujia ,2016-03-15 for �����������*/

/*Begin add by f03368, 2016-10-26 for MPPD42015*/
/**
* ��ѯĳ��UA��TCP������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUACode             UA����
* @param [OUT]  pstTCPStrateInfo    TCP������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note pstSrcUAList��pstDstUAList���ڴ���Ҫ�ɵ���������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTCPStrate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szUACode[IMOS_CODE_LEN],
    OUT TCP_STRATE_INFO_S          *pstTCPStrateInfo
);

/**
* �޸�ĳ��TCת�����
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTCPStrateInfo         TCP����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTCPStrate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TCP_STRATE_INFO_S       *pstTCPStrateInfo
);

/*End add by f03368, 2016-10-26 for MPPD42015*/

/* Begin: Added by huangsen W4381, 2017-09-19 for MPPD51185 �澯������A8 �澯���Դ��� */
/**
* ����/ȡ��������Ϊ�澯�������� \n
* @param [IN]		pstUserLogIDInfo			   �û���¼ID��Ϣ��ʶ
* @param [IN]		pcTVWallCode				   ����ǽ����
* @param [IN]		pcTVWindowsCode 			   ���ڱ���
* @param [IN]		ulEnabled					   �Ƿ����ã�0: ͣ�� 1: ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - 	 ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableWinAlarm
(
	IN		USER_LOGIN_ID_INFO_S			 *pstUserLogIDInfo,
	IN		CHAR							 szTVWallCode[IMOS_CODE_LEN],
	IN		CHAR							 szTVWindowsCode[IMOS_CODE_LEN],
	IN		ULONG_32						 ulEnabled
);
/* End: Added by huangsen W4381, 2017-09-19 for MPPD51185 �澯������A8 �澯���Դ��� */

/* Begin: Added by lW2822, 2016-10-17 for MPPD42034֧�ֺ������ҵ��IPC���� */
/**
* ��ӱ������������豸������Ϣ��������豸�ж�����Ƶ�����̨�Զ����ӡ�
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   pstEcAndAudioInfo           ������EC�豸����Ϣ������EC��Ϣ�Ͷ�����Ƶ��Ϣ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.EC���벻�����,�Ҳ��ܰ����ո�
* @note 2.����Я���豸��ʾ�ͺ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEcV2
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN    EC_INFO_V2_S                  *pstEcInfo
);


/**
* ��ѯĳ������������Ϣ
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szEcCode                    ����������
* @param [OUT]  pstEcInfo                   EC��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEcInfoV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szEcCode[IMOS_DEVICE_CODE_LEN],
    OUT EC_INFO_V2_S                    *pstEcInfo
);
/* End: Added by lW2822, 2016-10-17 for MPPD42034֧�ֺ������ҵ��IPC���� */



/**
* Restful��ʼ������ \n
* @param [IN]  CHAR    szServerAdd[IMOS_IPADDR_LEN] ������IP
* @param [IN]  CALL_BACK_ALARM_PROC_PF pfnCallBackAlarmProc �澯�ص�����
* @param [IN]  SPS_CALL_BACK_ALARM_PROC_PF pfnSpsCallBackAlarmProc SPS�澯�ص�����

* @return ULONG_32	�������½��:
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - 	���ز�������룬���������ļ���
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_InitRestful
(
    IN CHAR szServerAdd[IMOS_IPADDR_LEN],
    IN CALL_BACK_ALARM_PROC_PF pfnCallBackAlarmProc,
    IN SPS_CALL_BACK_ALARM_PROC_PF pfnSpsCallBackAlarmProc
);

/* Begin: Added by lW2822, 2017-03-22 for MPPD45413 ���ܻط� */
/**
* ��ҳ��ѯ�ƶ�����¼
* @param [IN]    pstUserLogIDInfo        �û���Ϣ
* @parzm [IN]    pstMotionQueryInfo      ����Ȥ���ڶ�Ӧ�ĺ����Ϣ
* @param [IN]    pstQueryPageInfo        ��ҳ������Ϣ
* @param [OUT]   pstRspPageInfo          ��ҳ��Ӧ��Ϣ
* @param [OUT]   pstMotionSliceInfoList  �������ƶ�����ʱ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMotionRecord
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  MOTION_QUERY_INFO_S         *pstMotionQueryInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TIME_SLICE_S                *pstMotionSliceInfoList
);
/* End: Added by lW2822, 2017-03-22 for MPPD45413 ���ܻط� */

/* Begin add by zhuzhicong/02302/����������, 2017-07-03 for MPPD48388 �Կ��ն� */
/**
* �����Կ��ն� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDACTInfo             �Կ��ն���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DACT_INFO_S                       *pstDACTInfo
);

/**
* �޸��Կ��ն� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDACTInfo               �Կ��ն���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DACT_INFO_S                       *pstDACTInfo
);

/**
* ɾ���Կ��ն� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDACTCode                �Կ��ն˱���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDACTCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�Կ��ն� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDACTCode                �Կ��ն˱���
* @param [OUT]  pstDACTInfo               �Կ��ն���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                                szDACTCode[IMOS_CODE_LEN],
    OUT DACT_INFO_S                       *pstDACTInfo
);

/**
* ��ѯ�Կ��ն��б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [IN]   bIsQuerySub             �Ƿ��ѯ����֯
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDACTList             �Կ��ն��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDACTList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    IN  BOOL_T                          bIsQuerySub,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DACT_INFO_S                      *pstDACTList
);

/**
* �����豸 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDACTList             �Կ��ն��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DACT_INFO_S                       *pstDACTInfo
);
/* End add by zhuzhicong/02302/����������, 2017-07-03 for MPPD48388 �Կ��ն� */

/* Begin: Added by zhuzhicong 02302\�����������, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */
/**
* ��ѯxware�豸������Ϣ
* @param [IN]   pstUserLoginIDInfo      �û���Ϣ
* @param [IN]   szDeviceCode            xware�豸����
* @param [IN]   pstXWareAbility         xware�豸������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_QueryXWareAbility
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo,
    IN  CHAR                       szDeviceCode[IMOS_CODE_LEN],
    OUT XWARE_ABILITY_S           *pstXWareAbility
);

/**
* ��ѯxware�豸��ͼ�ϴ�״̬
* @param [IN]   pstUserLoginIDInfo      �û���Ϣ
* @param [IN]   pcTVWallCode            ����ǽ����
* @param [IN]   ulBasePicID             ��ͼid
* @param [IN]   ulBasePicStatus         ��ͼ״̬
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
ULONG_32 STDCALL IMOS_QueryUploadPictureStatus
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo,
    IN  CHAR                       pcTVWallCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulBasePicID,
    OUT ULONG_32                   &ulBasePicStatus
);
/* End: Added by zhuzhicong 02302\�����������, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 VM����Xware */
#if 0
/* Xware������A8 sdk���� */
#endif

/**
* �����Կ��豸����ǽ \n
* @param [IN]       pstUserLogIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN]       pstTVWallInfo    ����ǽ��Ϣ
* @param [OUT]      szTVWallCode       ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_DACT_S  *pstTVWallInfo,
    OUT     CHAR                      szTVWallCode[IMOS_CODE_LEN]
);

/**
* �޸��Կ��豸����ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN][OUT]  pstTVWallInfo      ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_DACT_S  *pstTVWallInfo
);

/**
* ɾ���Կ��豸����ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       szTVWallCode       ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR                    szTVWallCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�Կ��豸����ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTvWallCode       ����ǽ����
* @param [IN]       bUserControl       �Ƿ��û����Ʋ���
* @param [OUT]      pstTVWallAllInfo   ����ǽ������Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN      CHAR                     szTVWallCode[IMOS_CODE_LEN],
    IN      BOOL_T                   bUserControl,
    OUT     TV_WALL_ALL_INFO_DACT_S  *pstTVWallAllInfo
);

/**
* ��ѯ�Կ��豸����ǽ�б� \n
* @param [IN]            pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]            pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]            pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]         pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]         pstTVWallList      ����ǽ�б�
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallListDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TV_WALL_INFO_DACT_S             *pstTVWallList
);

/**
* ��������LED \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [OUT]    pstTvwallVirLEDInfo            ����ǽ����LED��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN      TVWALL_VIRTUAL_LED_INFO_V2_S    *pstTvwallVirLEDInfo
);

/**
* �޸�����LED \n
* @param [IN]       pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]    pstTvwallVirLEDInfo            ����ǽ����LED��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_VIRTUAL_LED_INFO_V2_S     *pstTvwallVirLEDInfo
);

/**
* ɾ������LED \n
* @param [IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]    pcTvwallCode               ����ǽ����
* @param [IN]    pulLEDID                    ����LED����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTvwallCode[IMOS_CODE_LEN],
    IN      ULONG_32                         ulLEDID
);

/**
* ��ѯ��������LED \n
* @param [IN]       pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTvWallCode        ����ǽ����
* @param [IN]       pulLEDID            ����LED����
* @param [OUT]      pstTVWallVirLEDInfo ����LED��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN      CHAR                            szTVWallCode[IMOS_CODE_LEN],
    IN      ULONG_32                        ulLEDID,
    OUT     TVWALL_VIRTUAL_LED_INFO_V2_S    *pstTVWallVirLEDInfo
);

/**
* ��ѯ����ǽ��������LED \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTvWallCode       ����ǽ����
* @param [INOUT]    *pulVirLEDNum      ����ǽ������led����
* @param [OUT]      pstTVWallVirLEDList����ǽ����led�б�
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szTVWallCode[IMOS_CODE_LEN],
    INOUT   ULONG_32                    *pulVirLEDNum,
    OUT     TVWALL_VIRTUAL_LED_INFO_V2_S *pstTVWallVirLEDList
);

/**
* ����/ͣ������LED-V2 \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @param [IN]       pulLEDID                       LED����
* @param [IN]       ulEnabled                      �Ƿ����ã�0: ͣ�� 1: ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableVirtualLEDV2
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTVWallCode[IMOS_CODE_LEN],
    IN      ULONG_32                         ulLEDID,
    IN      ULONG_32                         ulEnabled
);

/**
* һ���ر��Կ��ն˵���ǽ���д��� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       szTVWallCode                   ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ClosedDACTAllWindows
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTVWallCode[IMOS_CODE_LEN]
);

#if 0
#endif
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 VM����Xware */

/* Begin: Added by mW4699 maojiangfeng, 2018-03-07 for MPPD57183 Xware˫���Ŵ� */
/**
* ����Xware����\n
* @param [IN]       pstUserLogIDInfo              �û���¼ID��Ϣ��ʶ
* @param [IN]       pstWindowInfo                   ����ǽ������Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ZoomWindowDACT
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      TV_WALL_WINDOWS_INFO      *pstWindowInfo
);
/* End: Added by mW4699 maojiangfeng, 2018-03-07 for MPPD57183 Xware˫���Ŵ� */

/*Begin: Added by hesongchang/02908, 2017-07-06 for ������MACҵ��֧�ֳ�������ȫ������������*/
/*************************************************************************************
������Ϣ���ã��������ӡ�ɾ�����޸ġ���ѯ
**************************************************************************************/
/**
* ���ӳ���
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstMacPlaceInfo            ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMacPlace
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* ɾ������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szMacPlaceCode             ��������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMacPlace
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  CHAR                   szMacPlaceCode[IMOS_CODE_LEN]
);


/**
* �޸ĳ���
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstMacPlaceInfo           ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMacPlace
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* ��ѯ����
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szMacPlaceCode            ��������
* @param [OUT]  pstMacPlaceInfo         ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacPlace
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                   szMacPlaceCode[IMOS_CODE_LEN],
    OUT MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* ��ѯ������Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstMacPlaceList               ������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacPlaceList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT MAC_PLACE_INFO_S             *pstMacPlaceList
);


/*************************************************************************************
��ȫ������Ϣ���ã��������ӡ�ɾ�����޸ġ���ѯ
**************************************************************************************/
/**
* ���Ӱ�ȫ����
* @param [IN]     pstUserLogIDInfo        �û���Ϣ
* @param [IN]     pstMacManuInfo            ��ȫ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMacManu
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  MAC_SEC_MANU_INFO_S        *pstMacManuInfo
);


/**
* ɾ����ȫ����
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szMacManuOrgCode             ��ȫ���̱���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMacManu
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  CHAR                   szMacManuOrgCode[IMOS_CODE_LEN]
);


/**
* �޸İ�ȫ����
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstMacManuInfo           ��ȫ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMacManu
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  MAC_SEC_MANU_INFO_S        *pstMacManuInfo
);


/**
* ��ѯ��ȫ����
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szMacManuOrgCode            ��ȫ���̱���
* @param [OUT]  pstMacManuInfo         ��ȫ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacManu
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                   szMacManuOrgCode[IMOS_CODE_LEN],
    OUT MAC_SEC_MANU_INFO_S        *pstMacManuInfo
);


/**
* ��ѯ��ȫ������Ϣ�б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                  ��֯����
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstMacManuList               ��ȫ������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacManuList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT MAC_SEC_MANU_INFO_S             *pstMacManuList
);


/**
* ��ѯIOT�豸�ĳ�����Ϣ
* @param [IN]   pstUserLoginIDInfo     �û���Ϣ
* @param [IN]   szIOTCode            �������豸����
* @param [OUT]  pstMacPlaceInfo         ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTMacPlaceInfo
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    OUT MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* ��ѯIOT�豸�İ�ȫ������Ϣ
* @param [IN]   pstUserLoginIDInfo     �û���Ϣ
* @param [IN]   szIOTCode            �������豸����
* @param [OUT]  pstMacPlaceInfo         ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTSecManuInfo
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    OUT MAC_SEC_MANU_INFO_S        *pstMacSecManuInfo
);

/*End: Added by hesongchang/02908, 2017-07-06 for ������MACҵ��֧�ֳ�������ȫ������������*/

/* Begin: Added by l03769, 2017-07-26 for MPPD49572 �������豸��γ���ϱ��ͳ���IPC�������� */
/**
* ��ѯ�������豸���͵���Դ(V2,��չ֧��������ѯ)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szOrgCode              ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition     ��ѯ����
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo      �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo        ��Ӧ��ҳ��Ϣ
* @param [OUT]  IOT_RES_QUERY_ITEM_V2_S     *pstIOTResList         �������豸������Դ�б�
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯�������������豸(����DAE�ͳ���IPC�����������͵���Դ)
* - 2.֧�ֲ�ѯĳһ���������豸��QUERY_IOT_TYPE = 1 ֻ��DAE�豸��= 2 ֻ�鳬��IPC��
                                               = 3 ����DAE�ͳ���IPC��ֻ�����͵���Դ��������Դ������3��4����
* - 3.֧�ֲ�ѯ�������豸�����͵���Դ��IS_QUERY_RES = 0 �����������豸�������Դ��= 1 ��ѯ�������豸�µ���Դ
      (���ֻ���˸�������Ϊ1����û�й涨��Դ���ͺ���Դ��������Ĭ�Ϸ����������豸�µ���������Դ)
* - 4.֧�ֲ�ѯ�������豸������Դ���ͣ�RES_TYPE = 2200 ��������= 2201 �����豸
      (���ֻ������Դ���Ͷ�û�������ͣ�����ֻ���˴��������򷵻����д�������Դ)
* - 5.֧�ֲ�ѯ�������豸������Դ�����ͣ�RES_SUB_TYPE���������μ�#SENSOR_TYPE_E�������豸�μ�#MOVING_RING_DEV_TYPE_E
*/
ULONG_32 STDCALL IMOS_QueryIOTRecourseListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IOT_RES_QUERY_ITEM_V2_S     *pstIOTResList
);
/* End: Added by l03769, 2017-07-26 for MPPD49572 �������豸��γ���ϱ��ͳ���IPC�������� */

/* Begin: Added by l03769, 2017-09-18 for MPPD51328 ��Ƶ���� */
/**
* ��ѯ�������Ƶ������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @param [IN]   pstQueryCondition   ��ѯ����, Ԥ��, Ŀǰ����Ҫ��
* @param [OUT]  pstDescrambleInfo   ��Ƶ������Ϣ
* @note 1.����޲�ѯ����,ָ��pstQueryCondition����ΪNULL
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamDescrambleInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCamCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT CAM_DESCRAMBLE_INFO_S           *pstCameraDescrambleInfo
);
/* End: Added by l03769, 2017-09-18 for MPPD51328 ��Ƶ���� */

/* Begin: Added by l03769, 2017-09-18 for MPPD51448 ��������Դ��Ϣ��ѯ */
/**
* ������������Դ�����ѯ��Դ��Ϣ
* @param [IN]   pstUserLogIDInfo      �û���Ϣ��ʶ
* @param [IN]   pstIOTResQryInfo      ��������Դ��ѯ��Ϣ
* @param [IN]   pstQueryPageInfo      �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo        ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstIOTResInfo         ��������Դ��Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTRecourseInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IOT_RES_QUERY_INFO_S    *pstIOTResQryInfo,
    IN  QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT IOT_RES_INFO_S          *pstIOTResInfoList
);

/**
* ��ѯĳ���������豸�����͵���ԴV3
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szIOTCode                   �������豸����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstIOTResList               �������豸������Դ�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.���ӷ����豸����
        2.֧��������ѯ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTRecourseListV3
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_RES_INFO_S               *pstIOTResList
);

/**
* ������Դ������Ϣ��ѯ���������������Ϣ
* @param [IN]   pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [IN]   pstIOTInfoQryParameter     ��������Ϣ��ѯ����
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstIOTInfoList             ��������Ϣ�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllIOTInfoByResTypeInfo
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    IN  IOT_INFO_QUERY_PARAMRTER_S   *pstIOTInfoQryParameter,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_RES_INFO_S               *pstIOTInfoList
);

/**
* ��������ģ�������������豸
* @param [IN]   pstUserLogIDInfo              �û���Ϣ��ʶ
* @param [IN]   pstFuzzyQueryIOTParameter     ģ����ѯ�������豸����
* @param [IN]   pstQueryPageInfo              �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstFuzzyQueryIOTResultList    ģ����ѯ�������豸�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_FuzzyQueryIOT
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  FUZZY_QUERY_IOT_PARAMETER_S  *pstFuzzyQueryIOTParameter,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT FUZZY_QUERY_IOT_RESULT_S     *pstFuzzyQueryIOTResultList
);

/**
* ������ѯ��������Դ�б�
* @param [IN]   pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]   pstBatchQueryIOTParameter    ������ѯ��������Դ����
* @param [IN]   pstQueryPageInfo             �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo               ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstBatchQueryIOTResList      ������ѯ��������Դ�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BatchQueryIOTResList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  BATCH_QUERY_IOT_PARAMETER_S  *pstBatchQueryIOTParameter,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT BATCH_QUERY_IOT_RES_LIST_S   *pstBatchQueryIOTResList
);
/* End: Added by l03769, 2017-09-18 for MPPD51448 ��������Դ��Ϣ��ѯ */

/* Begin: Added by sW4519, 2017-9-19 for MPPD50527\��liningchuan���� */
/**
* ��Դ���Ҽ��޸��κ������������
* @param [IN] pstUserLoginIDInfo �û���Ϣ��ʶ
* @param [IN] pstCamInfo         �������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAllKindsCamName
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN ALL_KINDS_CAM_NAME_S *pstCamInfo
);
/* End: Added by sW4519, 2017-9-19 for MPPD50527\��liningchuan���� */

/* Begin: Add by yW4708, 2017-10-18 for MPPD52393 �����û����֤��Ϣ */
/**
* �����û���Ϣ������Ϣ�а����û����룬Ψһ����
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstUserPasswordInfo     ����������֤���û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddUserV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  USER_INFO_PASSWORD_V2_S        *pstUserPasswordInfo
);

/**
* �޸��û���Ϣ�������û����벻���޸ģ�������Ҫ����
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstUserInfo             �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyUserV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  USER_INFO_V2_S                 *pstUserInfo
);

/**
* ��ѯĳ���û�����Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   szUserCode                  �û�����
* @param [OUT]  pstUserInfo                 �û���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserInfoV2
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo,
    IN   CHAR                           szUserCode[IMOS_USER_CODE_LEN],
    OUT  USER_INFO_V2_S                    *pstUserInfo
);
/* End: Add by yW4708, 2017-10-18 for MPPD52393 �����û����֤��Ϣ */

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
/**
* ��ѯ�������豸��ϢV2
* @param [IN]   pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]   szIOTCode             �������豸����
* @param [OUT]  pstIOTInfo            �������豸��Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTInfoV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szIOTCode[IMOS_DEVICE_CODE_LEN],
    OUT IOT_INFO_V2_S           *pstIOTInfo
);

/**
* ���Ӳ�����Ϣ
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   CABIN_INFO_S            *pstCabinInfo          ������Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCabinInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CABIN_INFO_S            *pstCabinInfo
);

/**
* ɾ��������Ϣ
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   ULONG_32                ulCabinType            ��������ö��
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteCabinInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  ULONG_32                ulCabinType
);

/**
* ��ѯ������Ϣ
* @param [IN]    USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]    QUERY_CABIN_INFO_S          *pstQueryCabinInfo     ��ѯ������Ϣ
* @param [IN]    COMMON_QUERY_CONDITION_S    *pstQueryCondition     ��ѯ����
* @param [IN]    QUERY_PAGE_INFO_S           *pstQueryPageInfo      �����ҳ��Ϣ
* @param [OUT]   RSP_PAGE_INFO_S             *pstRspPageInfo        ��Ӧ��ҳ��Ϣ
* @param [OUT]   CABIN_INFO_S                *pstCabinInfoList      ������Ϣ�б�
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1.������ʱΪNULL�������Ժ���չʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCabinInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_CABIN_INFO_S          *pstQueryCabinInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CABIN_INFO_S                *pstCabinInfoList
);

/**
* ���ӷ���������
* @param [IN]   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   FIRE_ZONE_COMBINATIONINFO_S    *pstAddFireZoneCom     ���ӷ������������
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFireZoneCombination
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  FIRE_ZONE_COMBINATION_INFO_S    *pstAddFireZoneCom
);

/**
* ɾ������������
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   FIRE_ZONE_COMBINATION_INFO_S    *pstDelFireZoneCom     ɾ���������������
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteFireZoneCombination
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  FIRE_ZONE_COMBINATION_INFO_S     *pstDelFireZoneCom
);

/**
* ��ѯ����������
* @param [IN]    USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]    FIRE_ZONE_QUERY_INFO_S         *pstFireZoneQueryInfo          ���������ѯ��Ϣ
* @param [IN]    COMMON_QUERY_CONDITION_S       *pstQueryCondition             ��ѯ����
* @param [OUT]   FIRE_ZONE_COMBINATIONINFO_S    *pstFireZoneCombinationInfo    ������������Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1.������ʱΪNULL�������Ժ���չʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFireZoneCombination
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  FIRE_ZONE_QUERY_INFO_S          *pstFireZoneQueryInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT FIRE_ZONE_COMBINATION_INFO_S    *pstFireZoneCombinationInfo
);

/**
* ���ӷ����������Ұ󶨹�ϵ
* @param [IN]   USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo                    �û���¼ID��Ϣ��ʶ
* @param [IN]   FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstAddFireZoneAndCabinRelationInfo    ���ӷ����������ҹ�����Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFireZoneAndCabinRelationInfo
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo,
    IN  FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstAddFireZoneAndCabinRelationInfo
);

/**
* ɾ�������������Ұ󶨹�ϵ
* @param [IN]   USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]   FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstDeldFireZoneAndCabinRelationInfo    ɾ�������������ҹ�����Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelFireZoneAndCabinRelationInfo
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo,
    IN  FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstDeldFireZoneAndCabinRelationInfo
);

/**
* ��ѯ�����������Ұ󶨹�ϵ
* @param [IN]    USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo                 �û���¼ID��Ϣ��ʶ
* @param [IN]    FIRE_ZONE_AND_CABIN_QUERY_INFO_S       *pstFireZoneAndCabinQueryInfo       �����������Ҳ�ѯ��Ϣ
* @param [IN]    COMMON_QUERY_CONDITION_S               *pstQueryCondition                  ��ѯ����
* @param [OUT]   FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstFireZoneAndCabinRelationInfo    �����������ҹ�����Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1.������ʱΪNULL�������Ժ���չʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFireZoneAndCabinRelationInfo
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo,
    IN  FIRE_ZONE_AND_CABIN_QUERY_INFO_S       *pstFireZoneAndCabinQueryInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    OUT FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstFireZoneAndCabinRelationInfo
);

/**
* �����������豸������Դ����Ұ󶨹�ϵ
* @param [IN]    USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]    RES_AND_CABIN_RELATION_INFO_S    *pstAddResAndCabinRelationInfo    �������豸������Դ����ҹ�����Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddResAndCabinRelation
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  RES_AND_CABIN_RELATION_INFO_S    *pstAddResAndCabinRelationInfo
);

/**
* ɾ���������豸������Դ����Ұ󶨹�ϵ
* @param [IN]    USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]    RES_AND_CABIN_RELATION_INFO_S    *pstDelResAndCabinRelationInfo    �������豸������Դ����ҹ�����Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResAndCabinRelation
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  RES_AND_CABIN_RELATION_INFO_S    *pstDelResAndCabinRelationInfo
);

/**
* �޸��������豸������Դ����Ұ󶨹�ϵ
* @param [IN]    USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo                  �û���¼ID��Ϣ��ʶ
* @param [IN]    RES_AND_CABIN_RELATION_INFO_S    *pstModifyResAndCabinRelationInfo    �������豸������Դ����ҹ�����Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyResAndCabinRelation
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  RES_AND_CABIN_RELATION_INFO_S    *pstModifyResAndCabinRelationInfo
);

/**
* ��ѯ�������豸������Դ����Ұ󶨹�ϵ
* @param [IN]      USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]      COMMON_QUERY_CONDITION_S    *pstQueryCondition     ��ѯ����
* @param [IN]      ULONG_32                    ulReqNum               ��������
* @param [INOUT]   RES_AND_CABIN_LIST_S        *pstResAndCabinList    �������豸������Դ����ҹ����б�
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1.������ʱΪNULL�������Ժ���չʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResAndCabinRelation
(
    IN     USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN     COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN     ULONG_32                    ulReqNum,
    INOUT  RES_AND_CABIN_ITEM_S        *pstResAndCabinList
);

/**
* ��ѯ�������豸������Դ����ʷ����
* @param [IN]   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   IOT_RES_DATA_QUERY_INFO_S      *pstIOTResDataQueryInfo    ������������Դ�����ݲ�ѯ��Ϣ
* @param [IN]   COMMON_QUERY_CONDITION_S       *pstQueryCondition         ��ѯ����
* @param [IN]   QUERY_PAGE_INFO_S              *pstQueryPageInfo          �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S                *pstRspPageInfo            ��Ӧ��ҳ��Ϣ
* @param [OUT]  IOT_RES_HISTORY_DATA_ITEM_S    *pstIOTHistoryDataList     �������豸������Դ����ʷ�����б�
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
* - 1.������ʱΪNULL�������Ժ���չʹ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTPushResHistoryData
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo,
    IN  IOT_RES_DATA_QUERY_INFO_S      *pstIOTResDataQueryInfo,
    IN  COMMON_QUERY_CONDITION_S       *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S              *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT IOT_RES_HISTORY_DATA_ITEM_S    *pstIOTHistoryDataList
);

/**
* ��ѯ�������豸������Դ��ʵʱ����
* @param [IN]   USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]   QUERY_REAL_TIME_DATA_S           *pstQueryInfo                 ��ѯʵʱ������Ϣ
* @param [OUT]  IOT_RES_REAL_TIME_DATA_ITEM_S    *pstIOTResRealTimeDataList    �������豸������Դ��ʵʱ�����б�
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTPushResRealTimeData
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  QUERY_REAL_TIME_DATA_S           *pstQueryInfo,
    OUT IOT_RES_REAL_TIME_DATA_ITEM_S    *pstIOTResRealTimeDataList
);

/**
* ����������������
* @param [IN]   USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   SWITCH_CONTROL_INFO_S    *pstSwitchControlInfo    ��������Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_IOTSwitchControl
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  SWITCH_CONTROL_INFO_S    *pstSwitchControlInfo
);

/**
* ������������״̬��ѯ
* @param [IN]   USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   SWITCH_STATUS_QUERY_INFO_S    *pstSwitchStatusQueryInfo    ������״̬��ѯ��Ϣ
* @param [OUT]  SWITCH_STATUS_INFO_S          *pstSwitchStatusInfo         ������״̬as��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ��: #ERR_DAO_DOMAIN_NOT_EXIST
* - ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTSwitchStatus
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  SWITCH_STATUS_QUERY_INFO_S    *pstSwitchStatusQueryInfo,
    OUT SWITCH_STATUS_INFO_S          *pstSwitchStatusInfo
);

/**
* ���ݴ���������������ѯ�����������ݿ������µļ�¼
* @param [IN]     USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]     IOT_RES_CODE_LIST_S           *pstIOTResCode             ��������Դ����
* @param [INOUT]  ULONG_32                      *pulQueryNum               ��ѯ����
* @param [OUT]    IOT_RES_HISTORY_DATA_ITEM_S   *pstIOTHistoryDataList     �������豸������Դ����ʷ�������¼�¼�б�
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BatchQueryIOTResData
(
    IN     USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN     IOT_RES_CODE_LIST_S          *pstIOTResCode,
    INOUT  ULONG_32                     *pulQueryNum,
    OUT    IOT_RES_HISTORY_DATA_ITEM_S  *pstIOTHistoryDataList
);

/**
* ��ѯĳ���������豸��������Դ��������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   szIOTCode               �豸����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstIOTResAllInfoList    �������豸������Դ�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTAllInfoList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_RES_ALL_INFO_ITEM_S      *pstIOTResAllInfoList
);
/* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

/* Begin: Added by l03769, 2017-12-21 for MPPD53844 ��������Դ������� */
/**
* ������������е��������豸(��������IPC��DAE)
* @param [IN]    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN]    QUERY_PAGE_INFO_S       *pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]   RSP_PAGE_INFO_S         *pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]   IOT_QUERY_ITEM_V2_S     *pstIOTQueryItemInfoList    ���е��������豸(��������IPC��DAE)
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDaeAndIpcDevList
(
    IN   USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN   QUERY_PAGE_INFO_S        *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S          *pstRspPageInfo,
    OUT  IOT_QUERY_ITEM_V2_S      *pstIOTQueryItemInfoList
);

/**
* �ֶ������������豸����Դ
* @param [IN]    pstUserLogIDInfo              *pstUserLogIDInfo           �û���Ϣ��ʶ
* @param [IN]    MANUAL_ADD_IOT_INFO_S         *pstManualAddIOTInfo        �ֶ����IOT��Ϣ
* @param [OUT]   MANUAL_ADD_IOT_FAIL_INFO_S    *pstManualAddIOTFailInfo    �ֶ����IOTʧ����Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.���������Ҫ��Ϊ�����û�֪���ĸ��豸��ӵ�ʱ��������ˣ��Ա��Ų�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualAddIOT
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  MANUAL_ADD_IOT_INFO_S        *pstManualAddIOTInfo,
    OUT MANUAL_ADD_IOT_FAIL_INFO_S   *pstManualAddIOTFailInfo
);

/**
* �ֶ������������豸����Դ
* @param [IN]    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo          �û���Ϣ��ʶ
* @param [IN]    CHAR                     szIOTCode                  �豸����
* @param [OUT]   MANUAL_ADD_IOT_INFO_S    *pstManualExportIOTInfo    �ֶ�������IOT��Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualExportIOT
(
    IN   USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN   CHAR                     szIOTCode[IMOS_DEVICE_CODE_LEN],
    OUT  MANUAL_ADD_IOT_INFO_S    *pstManualExportIOTInfo
);
/* End: Added by l03769, 2017-12-21 for MPPD53844 ��������Դ������� */

#if 0
#endif

/* Begin added by zhukaikai/W4801, 2017-12-28 for �ر������� MPPD54420 */
/*******************************************************************************
�豸-�ر���
*******************************************************************************/
/**��ӵر���
* @param [IN]   pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]   pstLandmarksInfo      �ر�����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note �ر������벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_AddLandmarks
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN    LANDMARKS_INFO_S        *pstLandmarksInfo
);


/**ɾ���ر���
* @param [IN]   pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]   szLandmarksCode       �ر�������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_DelLandmarks
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szLandmarksCode[IMOS_DEVICE_CODE_LEN]
);


/**�޸ĵر���
* @param [IN]   pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]   pstLandmarksInfo      �ر�����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note �����豸���벻�����޸ģ�������Ҫ����
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_ModifyLandmarks
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  LANDMARKS_INFO_S        *pstLandmarksInfo
);


/**��ѯĳ���ر�������Ϣ
* @param [IN]    pstUserLoginIDInfo    �û���Ϣ��ʶ
* @param [IN]    szLandmarksCode       �ر�������
* @param [OUT]   pstLandmarksInfo      �ر����豸��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_QueryLandmarksInfo
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN    CHAR                    szLandmarksCode[IMOS_DEVICE_CODE_LEN],
    OUT   LANDMARKS_INFO_S        *pstLandmarksInfo
);


/**��ѯĳ����֯�µĵر����б�  \n
* @param [IN]   pstUserLoginIDInfo       �û���Ϣ��ʶ
* @param [IN]   szOrgCode                ��֯����
* @param [IN]   pstQueryCondition        ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ����:#NAME_TYPE[�ر�������])
* @param [IN]   pstQueryPageInfo         �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo           ���ط�ҳ��Ϣ
* @param [OUT]  pstLandmarksQueryList    �ر�����ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_QueryLandmarksList
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo,
    IN   CHAR                       szOrgCode[IMOS_RES_CODE_LEN],
    IN   COMMON_QUERY_CONDITION_S   *pstQueryCondition,
    IN   QUERY_PAGE_INFO_S          *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S            *pstRspPageInfo,
    OUT  LANDMARKS_QUERY_ITEM_S     *pstLandmarksQueryList
);
/* End added by zhukaikai/W4801, 2017-12-28 for �ر������� MPPD54420 */

/* Begin: Added by limengni 03868, 2017-12-19 for �������豸���ͼ�������ز�ѯ */
/**
* ��ѯĳ���������豸�����͵���ԴV4
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstIOTResList               �������豸������Դ�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.���ӷ����豸����
        2.֧��������ѯ
        * - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯��������Դ(��������֯)
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��
* - 3.֧�ְ�"��Դ����"ģ����ѯ:#NAME_TYPE
* - 4.֧�ְ�"��Դ����"��ѯ:#RES_TYPE,ȡֵΪ#IMOS_TYPE_E, ��֧���߼���ϵ����Ϊ#EQUAL_FLAG;
* - 5.֧�ְ�"��Դ������"��ѯ:#RES_SUB_TYPE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_TYPE_E)
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Դ����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��Դ����),#CODE_TYPE(��Դ����),#RES_TYPE(��Դ����),#RES_SUB_TYPE(��Դ������)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTRecourseListV4
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_RES_INFO_ALL_S           *pstIOTResList
);
/* End: Added by limengni 03868, 2017-12-19 for �������豸���ͼ�������ز�ѯ */

/* Begin: added by gaopan/W4627, 2018-3-7 for �����ͻ����������ǽʱ�ܹ�����ǽ����ʷ��¼���� MPPD56781*/
/**��ѯ��ǰ�û�����Ŀ¼�����߼�������Ϣ \n
* @param [IN]   pstUserLoginIDInfo       �û���Ϣ��ʶ
* @param [IN]   pstQueryPageInfo         �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo           ���ط�ҳ��Ϣ
* @param [OUT]  pstScreenSplitInfoList    ��������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��ҳ��ѯ��ÿҳ�������Ŀ��, ����Ϊ0, Ҳ���ܴ���#IMOS_SCREEN_SPLIT_PAGE_MAX_NUM
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenSplitInfoByUser
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SCREEN_SPLIT_INFO_S         *pstScreenSplitInfoList
);
/* End: added by gaopan/W4627, 2018-3-7 for �����ͻ����������ǽʱ�ܹ�����ǽ����ʷ��¼���� MPPD56781*/


#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif


