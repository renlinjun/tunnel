/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              ss_sdk_func.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2009-07-27
        Author: huangjun (00754)
                chenshangwu (07076)
   Description: SDK����ӿ�
                ע��: ���з�ҳ��ѯʱ�������б�ռ����ⲿ���룬
                      ��С���ݷ�ҳ��ѯʱһҳ�ĸ����������롣


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SS_SDK_INTERFACE_H_
#define _IMOS_SS_SDK_INTERFACE_H_

/* ����BPԤ������Լ��������͵��ļ� */

#ifdef  __cplusplus
extern "C"{
#endif


/*************************************************************************************
SS ��������
***************************************************************************************/

/*************************************************************************************
SS �������
***************************************************************************************/

#if 0
#endif

/** @defgroup groupConfMgr �������
*   ԤԼ���顢����顢��ʷ���顢����ģ�����
*   @{
*/

/**
* �����ٿ����� ���ڻ��鲻�������ٿ������û�����ԡ�
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId
);


/**
* ��û������Ϣ�� ���а����᳡�б����᳡��״̬
* @param [IN]      pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]      ulConfCheckAuthMode     �����Ȩ��ʽ(CONF_CHECK_AUTH_MODE_E��������ʹ�û�ؼ�Ȩ����������ʹ�û�������Ȩ)
* @param [IN]      idConfId                ����ID
* @param [OUT]     pstConferenceActiveInfo �᳡���Ϣ
* @param [IN][OUT] pulSiteCount            �᳡����
* @param [OUT]     pstSiteList             �᳡�б�
* @param [IN][OUT] pulMcuCount             ����MCU����
* @param [OUT]     pstMcuList              ����MCU�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConferenceActiveInfo
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    ULONG_32                         ulConfCheckAuthMode,
    IN    IMOS_ID                       idConfId,
    OUT   MC_CONF_ACTIVE_INFO_EX_S      *pstConferenceActiveInfo,
    INOUT ULONG_32                         *pulSiteCount,
    OUT   MC_CONF_SITE_LIST_EX_S        *pstSiteList,
    INOUT ULONG_32                         *pulMcuCount,
    OUT   CONF_MCU_CASTE_EX_S           *pstMcuList
);

/**
* ��û����ж���᳡����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstName                 ������ģ����ѯ��Ϣ������ Ϊ�����ѯȫ��
* @param [IN]    pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]   pstTerminalList         �ն���Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySiteInConf
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  IMOS_ID                     idConfId,
    IN  QUERY_BY_NAME_S             *pstName,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MC_CONF_SITE_LIST_EX_S      *pstTerminalList
);

/** @} */ /* end of groupConfMgr */

#if 0
#endif

/*************************************************************************************
SS ��������
***************************************************************************************/

/** @defgroup groupConfControl �������
*   �������
*   @{
*/

/**
* ��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EndConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId
);

/**
* �ӳ����飬 ��λΪ����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    lMinute                 �ӳ�����ʱ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExtendConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  LONG_32                    lMinute
);

/**
* Ⱥ���᳡/�Ҷ����л᳡
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    bCallAllSites           BOOL_TRUE��ʾ�������л᳡�� ����Ҷ����л᳡
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CallAllSites
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bCallAllSites
);


/**
* ����/ȡ���������顣���������󣬲����������᳡�������м�����顣��MCU���������������Ѽ���MCU�������᳡��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    bLockConf               BOOL_TRUE��ʾ�������飬 �����ʾȡ����������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LockConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bLockConf
);

/**
* �ر�/�����������������ر������������� ��ȫ������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    bSilenceAll             BOOL_TRUE��ʾ�ر�����������, ����������������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAllSilence
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bSilenceAll
);

/**
* �ر�/����������˷硣 �ر�������˷磬 ��ȫ������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    bMuteAll                BOOL_TRUE��ʾ�ر�������˷磬 ������������˷�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAllMute
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bMuteAll
);

/**
* ������Ѳ  \n
* @param [IN]    pstUserLogIDInfo              �û���Ϣ��ʶ
* @param [IN]    idConfId                      ����ID
* @param [IN]    ulTurnMode                    ��Ѳģʽ  MC_CONF_TURN_BROADCAST_MODE_EX_E
* @param [IN]    bCycle                        BOOL_TRUE, ������Ѳ, ������Ѳ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTurnBroadcast
(
    IN  USER_LOGIN_ID_INFO_S              *pstUserLogIDInfo,
    IN  IMOS_ID                           idConfId,
    IN  ULONG_32                             ulTurnMode,
    IN  BOOL_T                            bCycle
);

/**
* ֹͣ/����������Ƶ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    bSendAllVideo           BOOL_TRUE��ʾ����������Ƶ�� ����ֹͣ������Ƶ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendAllVideo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bSendAllVideo
);

#if 0
#endif

/**
* ��ȡ������Ѳ�б�
* @param [IN]      pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]      idConfId                ����ID
* @param [OUT]     pulCycleTime            ��Ѳʱ��������λ��
* @param [IN][OUT] pulCycleTermCount       ������Ѳ�б��ն˸���
* @param [OUT]     pstCycleTermList        ������Ѳ�б��ն��б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetCycleList
(
    IN    USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN    IMOS_ID                            idConfId,
    OUT   ULONG_32                              *pulCycleTime,
    INOUT ULONG_32                              *pulCycleTermCount,
    OUT   CONF_SITE_CIRCLE_EX_S              *pstCycleTermList
);

/**
* ������Ѳ����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    ulCycleTime             ��Ѳʱ��������λ��
* @param [IN]    ulCycleTermCount        ������Ѳ�б��ն˸���
* @param [IN]    pstCycleTermList        ������Ѳ�б��ն��б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCycleList
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  ULONG_32                   ulCycleTime,
    IN  ULONG_32                   ulCycleTermCount,
    IN  CONF_SITE_CIRCLE_EX_S   *pstCycleTermList
);

/**
* ��ȡ���
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstBanner               ����ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetBanner
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    OUT HD_BANNER_INFO_EX_S     *pstBanner
);

/**
* ���ú��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstBanner               ����ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBanner
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  HD_BANNER_INFO_EX_S     *pstBanner
);

/**
* ��ȡ��Ļ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstTitle                ��Ļ�ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTitle
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    OUT HD_TITLE_INFO_EX_S      *pstTitle
);

/**
* ������Ļ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstTitle                ��Ļ�ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTitle
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  HD_TITLE_INFO_EX_S      *pstTitle
);

/**
* ��ȡ����ģʽ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstShowMode             ����ģʽ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ����������Ͷ໭��������ͼ�����е�������Կ����໭���0���ӻ��档���ڶ໭����ԣ�\n
*       ������С����λ�á�С������ʾ���ͣ���ϯ�������ˡ������᳡����������Ѳ�ȣ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPicMode
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  IMOS_ID                       idConfId,
    OUT MC_SET_PIC_MODE_MSG_EX_S      *pstShowMode
);

/**
* ���û���ģʽ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstShowMode             ����ģʽ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ����������Ͷ໭��������ͼ�����е�������Կ����໭���0���ӻ��档���ڶ໭����ԣ�\n
*       ������С����λ�á�С������ʾ���ͣ���ϯ�������ˡ������᳡����������Ѳ�ȣ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPicMode
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  IMOS_ID                       idConfId,
    IN  MC_SET_PIC_MODE_MSG_EX_S      *pstShowMode
);

/**
* ��ȡ����߿򡣻���ı߿�����,����������ϯ�������ˡ������᳡�߿���ɫ���߿��ϸ��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstConferenceFrame      ����߿�ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConferenceFrame
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    OUT MC_CONF_FRAME_EX_S      *pstConferenceFrame
);

/**
* ���û���߿򡣻���ı߿�����,����������ϯ�������ˡ������᳡�߿���ɫ���߿��ϸ��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstConferenceFrame      ����߿�ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetConferenceFrame
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  MC_CONF_FRAME_EX_S      *pstConferenceFrame
);

/**
* ��ȡ������ɫ��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstColorInfo            ��ɫ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConferenceColorGroup
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  IMOS_ID                    idConfId,
    OUT MC_CONF_COLOR_INFO_EX_S    *pstColorInfo
);

/**
* ���û᳡��ģʽ: �Ƿ���ʾ�᳡���� �᳡����λ�á����塢��С����ɫ����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstShowSiteName         �᳡����ʾ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetShowSiteNameMode
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  IMOS_ID                    idConfId,
    IN  HD_SITE_NAME_INFO_EX_S     *pstShowSiteName
);

/**
* ��ȡ�᳡��ģʽ: �Ƿ���ʾ�᳡���� �᳡����λ�á����塢��С����ɫ����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstShowSiteName         �᳡����ʾ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetShowSiteNameMode
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  IMOS_ID                    idConfId,
    OUT HD_SITE_NAME_INFO_EX_S     *pstShowSiteName
);

/**
* ���û�ز���
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    pstCtrlInfo             ��ز���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetConfCtrlInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  MC_CONF_CTRL_INFO_EX_S   *pstCtrlInfo
);

/**
* ��ȡ��ز���
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   pstCtrlInfo             ��ز���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConfCtrlInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    OUT MC_CONF_CTRL_INFO_EX_S   *pstCtrlInfo
);


#if 0
#endif

/**
* ��ӻ᳡
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szDevCode               MCU�豸���룬 ����Ϊ�ա� ��Ϊ�յ�ʱ�� ��ʾ�Զ�Ϊ�᳡ѡ����ʵ�MCU
* @param [IN]    szSiteCode              �᳡����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szDevCode[IMOS_RES_CODE_LEN],
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* ɾ���᳡
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* ����/�Ҷϻ᳡
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bCallSite               BOOL_TRUE��ʾ���л᳡�� ����Ҷϻ᳡
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CallSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bCallSite
);

/**
* ͬ�ⷢ�����롣 û���յ�ͬ�ⷢ�Ե��նˣ� ��Ĭ���䷢�����뱻�ܾ�
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bAgree                  �Ƿ�ͬ�ⷢ�ԣ� BOOL_TRUE ��ʾͬ��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AcceptSpeakReq
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bAgree
);


/**
* ��ȡ���������б�
* @param [IN]      pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]      idConfId                ����ID
* @param [IN][OUT] pulTermCount            �᳡����
* @param [OUT]     pstTermList             �᳡�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSpeakReqList
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    IMOS_ID                 idConfId,
    INOUT ULONG_32                   *pulTermCount,
    OUT   MC_CONF_SITE_NAME_EX_S  *pstTermList
);


/**
* �ر�/����ĳ�ն��������� �ر���˷磬 ������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bSilenceOne                BOOL_TRUE��ʾ�ر�ĳ�ն��������� ������ĳ�ն�������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteSilence
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSilenceOne
);

/**
* �ر�/����ĳ�ն���˷硣 �ر���˷磬 ������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bMuteOne                BOOL_TRUE��ʾ�ر�ĳ�ն���˷磬 ������ĳ�ն���˷�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteMute
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bMuteOne
);

/**
* �㲥ĳ�նˡ� �㲥ĳ�ն˼��㲥ͼ��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBroadcastSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* ��/ȡ���᳡��Ƶ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bOpenSiteVideo          BOOL_TRUE��ʾ�򿪻᳡��Ƶ�� ����ȡ���᳡��Ƶ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenSiteVideo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bOpenSiteVideo
);

/**
* ����/ȡ����ϯ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bSetSiteChair           BOOL_TRUE��ʾ������ϯ�� ����ȡ����ϯ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteChair
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSetSiteChair
);

/**
* ����/ȡ�����û᳡ΪFECC�����ߡ�Far End Camera Control��Զ����������ƣ�\n
* ָ������������Ŀ����ź�ͨ�����紫�͵�Զ���������ʵ�ֶ�Զ��������Ŀ���   \n
* FECC������ ���� FECC�ܿ��߻᳡�������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bSetSiteFECCController  BOOL_TRUE��ʾ�������û᳡ΪFECC�����ߣ� ����ȡ�����û᳡ΪFECC������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteFECCController
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSetSiteFECCController
);

/**
* ����/ȡ���ڶ�·��ƵԴ�����õڶ�·��ƵԴ�����ն�ָ��Ϊ˫��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    bSetSecondVideoRes      BOOL_TRUE��ʾ���õڶ�·��ƵԴ�� ����ȡ�����õڶ�·��ƵԴ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSecondVideoRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSetSecondVideoRes
);

/**
* ��û᳡ͨ����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [OUT]   pstSiteChannelInfo      �᳡ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSiteChannel
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_SITE_CAP_SET_EX_S    *pstSiteChannelInfo
);

/**
* ��û����е����᳡����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [OUT]   pstSiteInfo             �᳡��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSiteInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_SITE_INFO_EX_S       *pstSiteInfo
);

/**
* ��õ����᳡�����״̬
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [OUT]   pulStatus               �᳡״̬ MC_SITE_STATUS_EX_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTermStatus
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    OUT ULONG_32                   *pulStatus
);

/*************************************************************************************
SS ������˫��·��������
***************************************************************************************/

/**
* ����/ȡ���ն˸澯�� ������˫��·��������
* @param [IN]    pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]    idConfId                     ����ID
* @param [IN]    ulAlarmCount                 ��Ҫ�澯�Ļ᳡������ �����ĿIMOS_MAX_SITE_LIVE_NUM
* @param [IN]    pstAlarmSiteList             ��Ҫ�澯�Ļ᳡�б�
* @param [IN]    bStartAlarmOfTerminal        BOOL_TRUE��ʾ�����ն˸澯�� ����ȡ���ն˸澯
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartAlarmOfTerminal
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IMOS_ID                         idConfId,
    IN  ULONG_32                           ulAlarmCount,
    IN  CONF_SITE_CODE_EX_S             *pstAlarmSiteList,
    IN  BOOL_T                          bStartAlarmOfTerminal
);

/**
* ���û᳡��·�л�ģʽ ������˫��·��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                �������
* @param [IN]    szSiteCode              �᳡����
* @param [IN]    pstSwitchCfg            �᳡��·�л�ģʽ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteLayerSwitchMode
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN],
    IN  MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S *pstSwitchCfg
);

/**
* ��ȡ�᳡��·�л�ģʽ ������˫��·��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                �������
* @param [IN]    szSiteCode              �᳡����
* @param [OUT]   pstSwitchCfg            �᳡��·�л�ģʽ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSiteLayerSwitchMode
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S *pstSwitchCfg
);

/**
* �ָ�������·״̬���ߴ����ȶ�״̬ \n
* ����������·�󣬵���·���ֶ�����MCU��Ҫ�󽵵�ͨ���Ĵ����ʹ����ȶ�����\n
* ������û�к�ͨ����������ʹͨ���ָ�����ǰ�ĸߴ����ߴ����ȶ�״̬��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [OUT]   szSiteCode              վ�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResumeMainLayer
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* ��ȡ�ն�˫��·��Ϣ ������˫��·��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @param [OUT]   pstLinkInfo             �ն�˫��·��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTermLinkInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_LINK_INFO_EX_S        *pstLinkInfo
);


/**
* ����ģʽ�£� Ϊ����ѡ��ۿ��᳡����ϯģʽ�£� Ϊ��ϯѡ��ۿ��᳡
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idConfId                ����ID
* @param [IN]    szSiteCode              �᳡����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ChairBrowseSite
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN]
);


/** @} */ /* end of groupConfControl */

#if 0
#endif

/*************************************************************************************
SS MCU�豸����
***************************************************************************************/

/** @defgroup groupMCUConfig MCU�豸����
*   MCU�豸����
*   @{
*/

/**
* ����GK
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    ulGKType                GK��Ƕ MC_GK_TYPE_EX_E
* @param [IN]    szGKIP                  �ⲿGK��IP��ַ
* @param [IN]    szMCUAlias              MCU����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetGK
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                      ulGKType,
    IN  CHAR                       szGKIP[IMOS_IPADDR_LEN],
    IN  CHAR                       szMCUAlias[IMOS_MCU_NAME_LEN]
);

/**
* ��ȡGK
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pulGKType               GK��Ƕ MC_GK_TYPE_EX_E
* @param [OUT]   szGKIP                  �ⲿGK��IP��ַ
* @param [OUT]   *pulGKRegState          GK��ע��״̬
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetGK
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT ULONG_32                   *pulGKType,
    OUT CHAR                    szGKIP[IMOS_IPADDR_LEN],
    OUT ULONG_32                   *pulGKRegState
);

/**
* ����NAT
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    pstNATCfg               NAT���ýṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetNAT
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  MC_MCU_CONFIG_NAT_EX_S     *pstNATCfg
);

/**
* ��ȡNAT
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstNATCfg               NAT���ýṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetNAT
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_CONFIG_NAT_EX_S  *pstNATCfg
);

/**
* ����MCU��QOS����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    pstQosCfg               Qos���ýṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMCUQos
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  HD_QOS_SERV_EX_S        *pstQosCfg
);

/**
* ��ȡMCU��QOS����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstQosCfg               Qos���ýṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCUQos
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT HD_QOS_SERV_EX_S        *pstQosCfg
);

/**
* ����MCU����ģʽ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    pstMcuRunMode           MCU����ģʽ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMCURunMode
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  HA_SYSTEM_INFO_EX_S     *pstMcuRunMode
);

/**
* ��ȡMCU����ģʽ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstMcuRunMode           MCU����ģʽ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCURunMode
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT HA_SYSTEM_INFO_EX_S     *pstMcuRunMode
);

/**
* ��ȡMCU����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   szMCUName               MCU����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCUName
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT CHAR                    szMCUName[IMOS_MCU_NAME_LEN]
);

/**
* ����MCU�����ַ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    ulNetID                 ���ڱ�ʶ(0 ~ 3)
* @param [IN]    pstIPInfo               ���ڵ�IP��ַ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMCULanIP
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                   ulNetID,
    IN  MC_NET_STATUS_EX_S      *pstIPInfo
);

/**
* ��ȡMCU�����ַ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstIpCfg                MCU��IP��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCULanIP
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_IP_CFG_S         *pstIpCfg
);

/**
* �޸�����·�ɱ�
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    pstConfigRoute          ·����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMCULanRoute
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  CHAR                           szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  MC_CONFIG_ROUTE_MSG_EX_S       *pstConfigRoute
);

/**
* ��ȡ·�ɱ�
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstRouteInfo            ����Route����Ϣ�ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCULanRouteInfo
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_LAN_ROUTE_TABLE_EX_S         *pstRouteInfo
);

/**
* ��ȡARP��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstARPInfo              ����ARP����Ϣ�ṹ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCUARPInfo
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_ARP_TABLE_EX_S               *pstARPInfo
);

/**
* ��������澯������Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    szIpAddress             ����澯��������ַ
* @param [IN]    ulPower1AlarmID         ��Դ1��������澯��
* @param [IN]    ulPower2AlarmID         ��Դ2��������澯��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAlarmConfig
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                    szIpAddress[IMOS_IPADDR_LEN],
    IN  ULONG_32                   ulPower1AlarmID,
    IN  ULONG_32                   ulPower2AlarmID
);



/**
* ��ȡ����澯����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   szIpAddress             ����澯��������ַ
* @param [OUT]   pulPower1AlarmID        ��Դ1��������澯��
* @param [OUT]   pulPower2AlarmID        ��Դ2��������澯��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetAlarmConfig
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT CHAR                    szIpAddress[IMOS_IPADDR_LEN],
    OUT ULONG_32                   *pulPower1AlarmID,
    OUT ULONG_32                   *pulPower2AlarmID
);

/*************************************************************************************
SS ������˫��·��������
***************************************************************************************/

/**
* ���ñ�����·���Ե� IP ���� ������˫��·��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [IN]    pstIPInfo               ������·���Ե� IP ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBackupLinkLayerIPCfg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  MC_BACKUP_LAYER_IP_CFG_EX_S *pstIPInfo
);

/**
* ��ȡ������·���Ե� IP ���� ������˫��·��������
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szDevCode               �豸����
* @param [OUT]   pstIPInfo               ������·���Ե� IP ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetBackupLinkLayerIPCfg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_BACKUP_LAYER_IP_CFG_EX_S *pstIPInfo
);

#if 0
#endif

/**
* ������ɫ�顣 ��ɫ��Ϊȫ�����ã� ���õ����е�MCU�� \n
* ϵͳȱʡ�ṩ��6�飨ÿ��4ɫ+16ɫ����ɫѡ��Ϊ���᳡ʹ�ã�����4ɫΪ��Ļ����ɫѡ� \n
* 16ɫΪ������᳡���Լ����߿����ɫѡ����ϵͳ�ṩ��6����ɫѡ�������Ҫ��    \n
* �������������ɫѡ������Զ������á�ϵͳȱʡֵ�������޸ġ�
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    lGroupID                ��ID
* @param [IN]    astGroupIn16ColorT      16ɫ
* @param [IN]    astGroupIn4ColorT       4ɫ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetColorGroupValue
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  LONG_32                    lGroupID,
    IN  HD_COLOR_VALUE_EX_S     astGroupIn16ColorT[IMOS_EN_COLOR_TABLE16_TYPE_COUNT],
    IN  HD_COLOR_VALUE_EX_S     astGroupIn4ColorT[IMOS_EN_COLOR_TABLE4_TYPE_COUNT]
);

/**
* ��ȡ��ɫ�顣 ��ɫ��Ϊȫ�����ã� ���õ����е�MCU��\n
* ϵͳȱʡ�ṩ��6�飨ÿ��4ɫ+16ɫ����ɫѡ��Ϊ���᳡ʹ�ã�����4ɫΪ��Ļ����ɫѡ� \n
* 16ɫΪ������᳡���Լ����߿����ɫѡ����ϵͳ�ṩ��6����ɫѡ�������Ҫ��    \n
* �������������ɫѡ������Զ������á�ϵͳȱʡֵ�������޸ġ�
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [OUT]   astGroupIn16ColorT      16ɫ
* @param [OUT]   astGroupIn4ColorT       4ɫ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetColorGroupValue
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT HD_COLOR_VALUE_EX_S     astGroupIn16ColorT[IMOS_EN_COLOR_GROUP_COUNT][IMOS_EN_COLOR_TABLE16_TYPE_COUNT],
    OUT HD_COLOR_VALUE_EX_S     astGroupIn4ColorT[IMOS_EN_COLOR_GROUP_COUNT][IMOS_EN_COLOR_TABLE4_TYPE_COUNT]
);

/** @} */ /* end of groupMCUConfig */

#if 0
#endif

/*************************************************************************************
SS ��ϵ�˹���
***************************************************************************************/

/** @defgroup groupConfContactMgr ��ϵ�˹���
*   ��ϵ�˹���
*   @{
*/

/**
* ������ϵ����Ϣ������Ϣ�а�����ϵ��ID��Ψһ����
* @param [IN]      pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]      pstContactInfo          ��ϵ����Ϣ
* @param [OUT]     pidContactId            ��ϵ��ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddContact
(
    IN    USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN    CONF_CONTACT_INFO_EX_S     *pstContactInfo,
    OUT   IMOS_ID                    *pidContactId
);

/**
* �޸���ϵ����Ϣ��������ϵ��ID�����޸ģ�������Ҫ����
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    pstContactInfo          ��ϵ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyContact
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CONF_CONTACT_INFO_EX_S      *pstContactInfo
);

/**
* ɾ����ϵ��
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    idContactId             ��ϵ��ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelContact
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   IMOS_ID                        idContactId
);

/**
* ��ѯĳ����ϵ�˵���Ϣ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    idContactId                 ��ϵ��ID
* @param [OUT]   pstContactInfo              ��ϵ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryContactInfo
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   IMOS_ID                        idContactId,
    OUT  CONF_CONTACT_INFO_EX_S         *pstContactInfo
);

/**
* ��ѯ��ϵ���б� \n
* ֧�ְ�����ģ����ѯ��pstName����Ϊ�գ���ʾ��������Ч���������ֽ���ģ����ѯ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstContactList              ��ϵ�˲�ѯ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryContactList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  QUERY_BY_NAME_S                 *pstName,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CONF_CONTACT_INFO_EX_S          *pstContactList
);

/** @} */ /* end of groupConfContactMgr */

#if 0
#endif

/*******************************************************************************
 * �豸-MG��Ѷ�ն�
*******************************************************************************/

/** @defgroup groupMGMgr �ն˹���
*   �նˣ������������նˣ�����
*   @{
*/

/**
* ���MG��Ѷ�ն�
* �����豸���롢�豸���ơ��豸�ͺš�E.164����Ȼ�����Ϣ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szTerminalCode              MG��Ѷ�ն˱���
* @param [IN]    pstTerminalBaseInfo         MG��Ѷ�ն˻�����Ϣ
* @param [IN]    pstTerminalRestrictCapacity MG��Ѷ�ն˵�����������
* @param [IN]    pstTerminalconfig           MG��Ѷ�ն˳��ò���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note H3C�豸��������pstTerminalBaseInfo���������ÿ�ѡ�� �������豸��Ҫȫ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTerminal
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szTerminalCode[IMOS_DEVICE_CODE_LEN],
    IN    DEVICE_BASE_INFO_S            *pstTerminalBaseInfo,
    IN    TERMINAL_CAPACITY_EX_S        *pstTerminalRestrictCapacity,
    IN    TERMINAL_CONFIG_EX_S          *pstTerminalconfig
);

/**
* �޸�MG��Ѷ�ն˵Ļ�����Ϣ
* �����豸���벻�����޸ģ�������Ҫ���롣
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szTerminalCode              MG��Ѷ�ն˱���
* @param [IN]    pstTerminalBaseInfo         MG��Ѷ�ն˻�����Ϣ
* @param [IN]    pstTerminalRestrictCapacity MG��Ѷ�ն˵�����������
* @param [IN]    pstTerminalconfig           MG��Ѷ�ն˳��ò���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note H3C�豸��������pstTerminalBaseInfo���������ÿ�ѡ�� �������豸��Ҫȫ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTerminal
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szTerminalCode[IMOS_DEVICE_CODE_LEN],
    IN    DEVICE_BASE_INFO_S            *pstTerminalBaseInfo,
    IN    TERMINAL_CAPACITY_EX_S        *pstTerminalRestrictCapacity,
    IN    TERMINAL_CONFIG_EX_S          *pstTerminalconfig
);


/**
* ɾ��MG��Ѷ�ն�
* @param [IN]  pstUserLogIDInfo              �û���Ϣ��ʶ
* @param [IN]  szTerminalCode                MG��Ѷ�ն˱���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTerminal
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTerminalCode[IMOS_DEVICE_CODE_LEN]
);


/**
* ��ѯ����MG��Ѷ�ն˵Ļ�����Ϣ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szTerminalCode              MG��Ѷ�ն˱���
* @param [OUT]   pulRegistered               MG��Ѷ�ն��Ƿ�ע���
* @param [OUT]   pstTerminalBaseInfo         MG��Ѷ�ն˻�����Ϣ
* @param [OUT]   pstTerminalOriginalCapacity MG��Ѷ�ն˵�ԭʼ������
* @param [OUT]   pstTerminalRestrictCapacity MG��Ѷ�ն˵�����������
* @param [OUT]   pstTerminalconfig           MG��Ѷ�ն˳��ò���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTerminal
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTerminalCode[IMOS_DEVICE_CODE_LEN],
    OUT ULONG_32                           *pulRegistered,
    OUT DEVICE_BASE_INFO_S              *pstTerminalBaseInfo,
    OUT TERMINAL_CAPACITY_EX_S          *pstTerminalOriginalCapacity,
    OUT TERMINAL_CAPACITY_EX_S          *pstTerminalRestrictCapacity,
    OUT TERMINAL_CONFIG_EX_S            *pstTerminalconfig
);

/**
* ��ѯ����������MG��Ѷ�ն˵Ļ�����Ϣ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szTerminalCode              MG��Ѷ�ն˱���
* @param [OUT]   pstTerminalBaseInfo         MG��Ѷ�ն˻�����Ϣ
* @param [OUT]   pstTerminalInfo             MG��Ѷ�ն���ϸ��Ϣ
* @param [OUT]   pstTerminalconfig           MG��Ѷ�ն˳��ò���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Query3rdTerminal
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTerminalCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_BASE_INFO_S              *pstTerminalBaseInfo,
    OUT TERMINAL_CAPACITY_EX_S          *pstTerminalCapacity,
    OUT TERMINAL_CONFIG_EX_S            *pstTerminalconfig
);


/**
* ��ѯĳ����֯�µ�MG��Ѷ�ն��б�
* ֧�ְ�����ģ����ѯ��pstName����Ϊ�գ���ʾ��������Ч���������ֽ���ģ����ѯ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szOrgCode                   ��֯�����
* @param [IN]    bContainSubOrg              �Ƿ��������֯����ѯ����: �������Ʋ��ҵ�ʱ�� �Ƿ��������֯��
* @param [IN]    ulTermQueryType             ��ѯ�ն����� TERM_QUERY_TYPE_E
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ������ Ϊ�����ѯȫ��
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstTerminalList             MG��Ѷ�ն���Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTerminalList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  BOOL_T                          bContainSubOrg,
    IN  ULONG_32                           ulTermQueryType,
    IN  QUERY_BY_NAME_S                 *pstName,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TERMINAL_QURERY_ITEM_EX_S       *pstTerminalList
);

/** @} */ /* end of groupMGMgr */

#if 0
#endif
/*******************************************************************************
�豸-MCU��Ѷ�ն�
*******************************************************************************/

/** @defgroup groupMCUMgr MCU����
*   MCU����ɾ�Ĳ�
*   @{
*/

/**
* ���MCU�豸 \n
* �����豸���롢�豸�������͵Ȼ�����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    pstMcuBaseInfo          MCU������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMcu
(
    IN    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN    MCU_BASE_INFO_EX_S       *pstMcuBaseInfo
);

/**
* �޸�MCU�豸 \n
* �����豸���롢�豸�������͵Ȼ�����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    pstMcuBaseInfo          MCU������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMcu
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    MCU_BASE_INFO_EX_S            *pstMcuBaseInfo
);


/**
* ��ѯMCU�豸 \n
* �����豸���롢�豸�������͵Ȼ�����Ϣ
* @param [IN]    pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]    szMcuCode               MCU�豸����
* @param [OUT]   pstMcuBaseInfo          MCU������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMcu
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szMcuCode[IMOS_DEVICE_CODE_LEN],
    OUT   MCU_BASE_INFO_EX_S            *pstMcuBaseInfo
);


/**
* ɾ��MCU�豸
* @param [IN]  pstUserLogIDInfo              �û���Ϣ��ʶ
* @param [IN]  szMcuCode                     MCU�豸����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMcu
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMcuCode[IMOS_DEVICE_CODE_LEN]
);



/**
* ��ѯĳ����֯�µ�MCU�豸�б� \n
* ֧�ְ�����ģ����ѯ��pstName����Ϊ�գ���ʾ��������Ч���������ֽ���ģ����ѯ
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szOrgCode                   ��֯�����
* @param [IN]    bContainSubOrg              �Ƿ��������֯�� ��ѯ����: �������Ʋ��ҵ�ʱ�� �Ƿ��������֯��
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstMcuList                  MCU�豸��Ϣ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMcuList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  BOOL_T                          bContainSubOrg,
    IN  QUERY_BY_NAME_S                 *pstName,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT MCU_BASE_INFO_EX_S              *pstMcuList
);

/** @} */ /* end of groupMCUMgr */

#if 0
#endif

/*******************************************************************************
SS  �������
*******************************************************************************/

/** @defgroup groupConfMgr �������
*   ԤԼ���顢����顢��ʷ���顢����ģ�����
*   @{
*/

/**
* ��ѯ�������Ϣ�б�
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szOrgCode                   ��֯����
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstConfList                 ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryActiveConfList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_BY_NAME_S                 *pstName,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CONF_QUERY_ITEM_EX_S            *pstConfList
);

/**
* ��ѯĳ����֯�µ�ԤԼ������Ϣ�б�
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szOrgCode                   ��֯����
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstConfList                 ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBookingConfList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_BY_NAME_S                 *pstName,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CONF_QUERY_ITEM_EX_S            *pstConfList
);

/**
* ��ѯ��ʷ������Ϣ�б� ��ʷ���鲻������֯��������֯ɾ���� ��Ҫͬʱɾ����ʷ���顣
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    pstQueryCondition           ��ѯ��Ϣ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstConfList                 ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ֧�ֵĲ�ѯ������������:#NAME_TYPE[��ʷ��������];
*                              #CONF_START_TIME[���鿪ʼʱ��];
*                              #CONF_END_TIME[�������ʱ��];
*                              #USER_NAME_TYPE[���鴴����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHistoryConfList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CONF_QUERY_ITEM_EX_S            *pstConfList
);

/**
* ��ѯ����ģ���б�
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstConfTempList             ����ģ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryConfTempList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  QUERY_BY_NAME_S                 *pstName,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CONF_QUERY_ITEM_EX_S            *pstConfTempList
);

/**
* ��������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstConfInfo             ������Ϣ
* @param [IN]   ulConfTermCount         �����ն˸���
* @param [IN]   pstConfTermList         �����ն��б�
* @param [IN]   ulMcuCount              ����MCU����
* @param [IN]   pstMcuList              ����MCU�б�
* @param [IN]   ulCycleTermCount        ������Ѳ�б��ն˸���
* @param [IN]   pstCycleTermList        ������Ѳ�б��ն��б� ����б� ���ձ��˳���С������д�� ͬһ�б� �����±�˳���С������д
* @param [IN]   ulContactCount          ��ϵ�˸���
* @param [IN]   pidContactList          ��ϵ���б�
* @param [OUT]  pidConfId               ����ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note  ֱ�ӵ��� ���ṩ�Զ����� ��ʼ��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  MC_CONF_INFO_EX_S       *pstConfInfo,
    IN  ULONG_32                   ulConfTermCount,
    IN  CONF_SITE_CASTE_EX_S    *pstConfTermList,
    IN  ULONG_32                   ulMcuCount,
    IN  CONF_MCU_CASTE_EX_S     *pstMcuList,
    IN  ULONG_32                   ulCycleTermCount,
    IN  CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    IN  ULONG_32                   ulContactCount,
    IN  IMOS_ID                 *pidContactList,
    OUT IMOS_ID                 *pidConfId
);

/**
* ��ȡ������Ϣ
* @param [IN]      pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]      idConfId               ����ID
* @param [OUT]     pstConfInfo            ������Ϣ
* @param [IN][OUT] pulConfTermCount       �����ն��б����С,�����ն˸���
* @param [OUT]     pstConfTermList        �����ն��б�
* @param [IN][OUT] pulMcuCount            MCU�б����С,����MCU����
* @param [OUT]     pstMcuList             ����MCU�б�
* @param [IN][OUT] pulCycleTermCount      ��Ѳ�б����С��������Ѳ�б��ն˸���
* @param [OUT]     pstCycleTermList       ������Ѳ�б��ն��б�
* @param [IN][OUT] pulContactCount        ��ϵ���б����С����ϵ�˸���
* @param [OUT]     pstContactList         ��ϵ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ֻ��ɾ��δ�ٿ�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConference
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    IMOS_ID                 idConfId,
    OUT   MC_CONF_INFO_EX_S       *pstConfInfo,
    INOUT ULONG_32                   *pulConfTermCount,
    OUT   CONF_SITE_CASTE_EX_S    *pstConfTermList,
    INOUT ULONG_32                   *pulMcuCount,
    OUT   CONF_MCU_CASTE_EX_S     *pstMcuList,
    INOUT ULONG_32                   *pulCycleTermCount,
    OUT   CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    INOUT ULONG_32                   *pulContactCount,
    OUT   CONF_CONTACT_INFO_EX_S  *pstContactList
);

/**
* ��ȡ��ʷ������Ϣ
* @param [IN]      pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]      idConfId               ����ID
* @param [OUT]     pstConfInfo            ������Ϣ
* @param [IN][OUT] ulConfTermCount        �����ն��б����С,�����ն˸���
* @param [OUT]     pstConfTermList        �����ն��б�
* @param [IN][OUT] pulMcuCount            MCU�б����С,����MCU����
* @param [OUT]     pstMcuList             ����MCU�б�
* @param [IN][OUT] pulCycleTermCount      ��Ѳ�б����С��������Ѳ�б��ն˸���
* @param [OUT]     pstCycleTermList       ������Ѳ�б��ն��б�
* @param [IN][OUT] pulContactCount        ��ϵ���б����С����ϵ�˸���
* @param [OUT]     pstContactList         ��ϵ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��������ն��б� �������������б� ���������Ļ�ն��б� ΪNULL, �ֲ�ʵ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetHistoryConference
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    IMOS_ID                 idConfId,
    OUT   MC_CONF_INFO_EX_S       *pstConfInfo,
    INOUT ULONG_32                   *pulConfTermCount,
    OUT   CONF_SITE_CASTE_EX_S    *pstConfTermList,
    INOUT ULONG_32                   *pulMcuCount,
    OUT   CONF_MCU_CASTE_EX_S     *pstMcuList,
    INOUT ULONG_32                   *pulCycleTermCount,
    OUT   CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    INOUT ULONG_32                   *pulContactCount,
    OUT   CONF_CONTACT_INFO_EX_S  *pstContactList
);


/**
* �޸Ļ���
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   idConfId                ����ID
* @param [IN]   pstConfInfo             ������Ϣ
* @param [IN]   ulConfTermCount         �����ն˸���
* @param [IN]   pstConfTermList         �����ն��б�
* @param [IN]   ulMcuCount              ����MCU����
* @param [IN]   pstMcuList              ����MCU�б�
* @param [IN]   ulCycleTermCount        ������Ѳ�б��ն˸���
* @param [IN]   pstCycleTermList        ������Ѳ�б��ն��б� ����б� ���ձ��˳���С������д�� ͬһ�б� �����±�˳���С������д
* @param [IN]   ulContactCount          ��ϵ�˸���
* @param [IN]   pidContactList          ��ϵ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��������ն��б� �������������б� ���������Ļ�ն��б� ΪNULL, �ֲ�ʵ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  MC_CONF_INFO_EX_S       *pstConfInfo,
    IN  ULONG_32                   ulConfTermCount,
    IN  CONF_SITE_CASTE_EX_S    *pstConfTermList,
    IN  ULONG_32                   ulMcuCount,
    IN  CONF_MCU_CASTE_EX_S     *pstMcuList,
    IN  ULONG_32                   ulCycleTermCount,
    IN  CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    IN  ULONG_32                   ulContactCount,
    IN  IMOS_ID                 *pidContactList
);


/**
* ɾ������
* @param [IN]  pstUserLogIDInfo              �û���Ϣ��ʶ
* @param [IN]  idConfId                      ����ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ֻ��ɾ��ԤԼ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteConference
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IMOS_ID                         idConfId
);

/**
* ��������ģ����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstConfTempInfo         ����ģ����Ϣ
* @param [IN]   ulConfTermCount         �����ն˸���
* @param [IN]   pstConfTermList         �����ն��б�
* @param [IN]   ulCycleTermCount        ������Ѳ�б��ն˸���
* @param [IN]   pstCycleTermList        ������Ѳ�б��ն��б� ����б� ���ձ��˳���С������д�� ͬһ�б� �����±�˳���С������д
* @param [IN]   ulContactCount          ��ϵ�˸���
* @param [IN]   pidContactList          ��ϵ���б�
* @param [OUT]  pidConfTempId           ����ģ��ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note   ��������ն��б� �������������б� ���������Ļ�ն��б� ΪNULL, �ֲ�ʵ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateConfTemp
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  MC_CONF_INFO_EX_S       *pstConfTempInfo,
    IN  ULONG_32                   ulConfTermCount,
    IN  CONF_SITE_CODE_EX_S     *pstConfTermList,
    IN  ULONG_32                   ulCycleTermCount,
    IN  CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    IN  ULONG_32                   ulContactCount,
    IN  IMOS_ID                 *pidContactList,
    OUT IMOS_ID                 *pidConfTempId
);


/**
* ��ȡ����ģ����Ϣ
* @param [IN]      pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]      idConfTempId           ����ģ��ID
* @param [IN]      pstConfTempInfo        ����ģ����Ϣ
* @param [IN][OUT] ulConfTermCount        �����ն��б����С,�����ն˸���
* @param [OUT]     pstConfTermList        �����ն��б�
* @param [IN][OUT] pulCycleTermCount      ��Ѳ�б����С��������Ѳ�б��ն˸���
* @param [OUT]     pstCycleTermList       ������Ѳ�б��ն��б�
* @param [IN][OUT] pulContactCount        ��ϵ���б����С����ϵ�˸���
* @param [OUT]     pstContactList         ��ϵ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��������ն��б� �������������б� ���������Ļ�ն��б� ΪNULL, �ֲ�ʵ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryConfTemp
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    IMOS_ID                 idConfTempId,
    OUT   MC_CONF_INFO_EX_S       *pstConfTempInfo,
    INOUT ULONG_32                   *pulConfTermCount,
    OUT   CONF_SITE_NAME_S        *pstConfTermList,
    INOUT ULONG_32                   *pulCycleTermCount,
    OUT   CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    INOUT ULONG_32                   *pulContactCount,
    OUT   CONF_CONTACT_INFO_EX_S  *pstContactList
);


/**
* �޸Ļ���ģ����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]   idConfTempId            ����ģ��ID
* @param [IN]   pstConfTempInfo         ����ģ����Ϣ
* @param [IN]   ulConfTermCount         �����ն˸���
* @param [IN]   pstConfTermList         �����ն��б�
* @param [IN]   ulCycleTermCount        ������Ѳ�б��ն˸���
* @param [IN]   pstCycleTermList        ������Ѳ�б��ն��б�
* @param [IN]   ulContactCount          ��ϵ�˸���
* @param [IN]   pidContactList          ��ϵ���б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��������ն��б� �������������б� ���������Ļ�ն��б� ΪNULL, �ֲ�ʵ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyConfTemp
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfTempId,
    IN  MC_CONF_INFO_EX_S       *pstConfTempInfo,
    IN  ULONG_32                   ulConfTermCount,
    IN  CONF_SITE_CODE_EX_S     *pstConfTermList,
    IN  ULONG_32                   ulCycleTermCount,
    IN  CONF_SITE_CIRCLE_EX_S   *pstCycleTermList,
    IN  ULONG_32                   ulContactCount,
    IN  IMOS_ID                 *pidContactList
);


/**
* ɾ������ģ��
* @param [IN]  pstUserLogIDInfo              �û���Ϣ��ʶ
* @param [IN]  idConfTempId                  ����ģ��ID
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteConfTemp
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IMOS_ID                         idConfTempId
);


/**
* ��ȡ�Ƽ�������Ϣ
* @param [IN]  pstUserLogIDInfo                  �û���Ϣ��ʶ
* @param [IN]  pstConfInfo                       ������Ϣ
* @param [IN]  ulConfTermCount                   �����ն˸���
* @param [IN]  pstConfTermList                   �����ն��б�
* @param [IN][OUT] pulConfTermCasteCount         ��������ϵ�����ն˸���
* @param [OUT] pstConfTermCasteList              ��������ϵ�����ն��б�
* @param [IN][OUT] pulMcuCount                   ����MCU����
* @param [OUT] pstMcuList                        ��������ϵ����MCU�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetRecommendCascadeConf
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  MC_CONF_INFO_EX_S           *pstConfInfo,
    IN  ULONG_32                       ulConfTermCount,
    IN  CONF_SITE_CODE_EX_S         *pstConfTermList,
    INOUT  ULONG_32                    *pulConfTermCasteCount,
    OUT CONF_SITE_CASTE_EX_S        *pstConfTermCasteList,
    INOUT ULONG_32                     *pulMcuCount,
    OUT CONF_MCU_CASTE_EX_S         *pstMcuList
 );



/** @} */ /* end of groupConfMgr */

#if 0
#endif
/*************************************************************************************
SS ͳ����Ϣ
***************************************************************************************/

/** @defgroup groupConfReport ���鱨��
*   �ṩ�����ѯ����
*   @{
*/

/**
* �᳡���ʱ�䱨��
* @param [IN]    pstUserLogIDInfo            �û���Ϣ��ʶ
* @param [IN]    szOrgCode                   ��֯����
* @param [IN]    bContainSubOrg              �Ƿ��������֯�� ��ѯ����: �������Ʋ��ҵ�ʱ�� �Ƿ��������֯��
* @param [IN]    lStartTime                  ͳ�ƿ�ʼʱ��
* @param [IN]    lEndTime                    ͳ�ƽ���ʱ��
* @param [IN]    pstName                     ������ģ����ѯ��Ϣ���� Ϊ�ղ�ѯ����
* @param [IN]    pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]   pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]   pstTerminalInConfInfoList   �����ն����ʱ��ͳ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTermInConfReport
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  CHAR                          szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  BOOL_T                        bContainSubOrg,
    IN  LONG_32                          lStartTime,
    IN  LONG_32                          lEndTime,
    IN  QUERY_BY_NAME_S               *pstName,
    IN  QUERY_PAGE_INFO_S             *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S               *pstRspPageInfo,
    OUT TERMINAL_TIME_STAT_INFO_EX_S  *pstTerminalInConfInfoList
);

/**
* MCU�Ļ�����������ն�������
* @param [IN]      pstUserLogIDInfo        �û���Ϣ��ʶ
* @param [IN]      szMcuCode               MCU�豸����
* @param [IN]      lStartTime              ͳ�ƿ�ʼʱ��
* @param [IN]      lEndTime                ͳ�ƽ���ʱ��
* @param [IN]      ulSampleType            �������: CONF_REPORT_SAMPLE_TYPE_E
* @param [IN][OUT] pulConfStatInfoCount    ͳ�Ƹ���
* @param [OUT]     pstConfStatInfoList     MCU�Ļ�����������ն���ͳ����Ϣ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryConfInMcuReport
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    CHAR                    szMcuCode[IMOS_DEVICE_CODE_LEN],
    IN    LONG_32                    lStartTime,
    IN    LONG_32                    lEndTime,
    IN    ULONG_32                   ulSampleType,
    INOUT ULONG_32                   *pulConfStatInfoCount,
    OUT   CONF_STAT_INFO_EX_S     *pstConfStatInfoList
);

/** @} */ /* end of groupConfReport */

#if 0
#endif


/*************************************************************************************
SS ��ַ������
***************************************************************************************/

/** @defgroup groupMGMgr �ն˹���
*   �ն˹���
*   @{
*/

/**
* iMSC���ն˵����ַ����Ϣ
* @param [IN]      pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]      szDevCode                    �豸����
* @param [IN]      pstAddrBookItem              ��ַ����¼
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ImportAddressBook
(
    IN    USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN    CHAR                             szDevCode[IMOS_DEVICE_CODE_LEN],
    IN    HD_ADDRBOOK_ITEM_EX_S            *pstAddrBookItem
);

/** @} */ /* end of groupMGMgr */

#if 0
#endif

/*************************************************************************************
SS �豸��� ʹ����СMIBʵ��
***************************************************************************************/

/** @defgroup groupDevPanel �豸���
*   �豸���
*   @{
*/

/**
* ��ȡ�豸������Ϣ
* @param [IN]     pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]     szDevCode                    �豸����
* @param [OUT]    pstPerformanceInfo           �豸������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDevicePerformanceInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_PERFORMANCE_INFO_S       *pstPerformanceInfo
);

/**
* ��ȡ�豸�˿���ص���Ϣ
* @param [IN]     pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]     szDevCode                    �豸����
* @param [OUT]    pstDevicePortInfo            �豸�˿���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDevicePortInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_PORT_INFO_S              *pstDevicePortInfo
);

/** @} */ /* end of groupDevPanel */

#if 0
#endif

/*************************************************************************************
SS �ʼ������������ù���
***************************************************************************************/

/** @defgroup groupEmailMgr �ʼ�����������
*   �ʼ�����������
*   @{
*/

/**
* ��ȡ�ʼ����͵�����
* @param [IN]    pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [OUT]   pstEmailSendingConfig        Email������ص�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* �����ʼ����͵�����
* @param [IN]    pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]    pstEmailSendingConfig        Email������ص�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* ��ȡ�ʼ����͹���
* @param [IN]    pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [OUT]   pstRules                     Email���͹���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetEmailSendingRules
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT EMAIL_SENDING_RULES_S        *pstRules
);

/**
* �����ʼ����͹���
* @param [IN]    pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [IN]    pstRules                     Email���͹���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetEmailSendingRules
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_RULES_S        *pstRules
);


/**
* ���Ͳ����ʼ��� ��֤�ʼ����͵������Ƿ���ȷ
* @param [IN]    pstUserLogIDInfo             �û���Ϣ��ʶ
* @param [OUT]   pstEmailSendingConfig        Email������ص�����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TestToSendEmail
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);


/*************************************************************************************
SS �豸��������
***************************************************************************************/

/**
* ��ȡFTP��Ϣ
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [OUT]  pstFtpInfo          ����FTP������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFTPInfo
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    OUT FTP_INFO_S *pstFtpInfo
);

/**
* ��ȡһ��Ψһ�ļ���·�����û����� + ����ʱ�� + �������
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   ulFileType          �ļ�����  ��Ӧö�٣�IMOS_FTP_FILE_TYPE_E
* @param [OUT]  szUniqueFilePath    ���ļ����Ͷ�ӦĿ¼·��������һ��Ψһ�ļ���·��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUniqueFilePath
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN ULONG_32 ulFileType,
    OUT CHAR szUniqueFilePath[IMOS_FILE_PATH_LEN]
);

/**
* �ӷ������·��ļ����ն�
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   szDevCode           �ն˱���
* @param [IN]   szFilePath          �ļ��ڷ�������·����Դ�ļ�·����
* @param [IN]   szDevFilePath       �ļ����豸�ϵ�·����Ŀ���ļ�·������������Ѷ�豸�������ļ�������Ѷ�ඨ�壬��Ҫ���Ϊ��config��
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendFileToTerm
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR szDevCode[IMOS_DEVICE_CODE_LEN],
    IN CHAR szSrvFilePath[IMOS_FILE_PATH_LEN],
    IN CHAR szDevFilePath[IMOS_FILE_PATH_LEN]
);

/**
* ���ն˻�ȡ�ļ���������
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @param [IN]   szDevCode           �ն˱���
* @param [IN]   ulFileType          �ļ����� ��Ӧö�٣�IMOS_FTP_FILE_TYPE_E
* @param [IN]   szDevFilePath       �ļ����豸��·����Դ�ļ�·������������Ѷ�豸�������ļ�������Ѷ�ඨ�壬��Ҫ���Ϊ��config��
* @param [IN][OUT] szSrvFilePath �ļ��ڷ�������·����Ŀ���ļ�·����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note �������ڷ�������Ŀ���ļ�·����ָ�������ַ����������ɷ������Զ����ɣ������ļ�����ѡ���ļ����Ŀ¼·��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFileFromTerm
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR szDevCode[IMOS_DEVICE_CODE_LEN],
    IN ULONG_32 ulFileType,
    IN CHAR szDevFilePath[IMOS_FILE_PATH_LEN],
    INOUT CHAR szSrvFilePath[IMOS_FILE_PATH_LEN]
);

/**
* �ֹ�ͬ���豸
* @param [IN] pstUserLogIDInfo  �û���Ϣ��ʶ
* @param [IN] szDevCode         �豸����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualSyncDev
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR szDevCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ָ���᳡ѡ��ۿ��᳡
* @param [IN]    pstUserLogIDInfo       �û���Ϣ��ʶ
* @param [IN]    idConfId               ����ID
* @param [IN]    szBrowseSiteCode       �ۿ��᳡����
* @param [IN]    szBrowsedSiteCode      ���ۿ��᳡����
* @param [IN]    bCancelBrowse          BOOL_TRUEȡ��ѡ��ۿ�,BOOL_FALSE����ȡ���ۿ�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SiteBrowseSite
(
     IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
     IN  IMOS_ID                  idConfId,
     IN  CHAR                     szBrowseSiteCode[IMOS_RES_CODE_LEN],
     IN  CHAR                     szBrowsedSiteCode[IMOS_RES_CODE_LEN],
     IN  BOOL_T                   bCancelBrowse
 );

/** @} */ /* end of groupEmailMgr */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

