/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              sdk_func.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2009-02-27
        Author: sunyifan (s06966)
                zhuyi (KF1397)
                yangbin (07022)
   Description: SDK����ӿ�
                ע��: ���з�ҳ��ѯʱ�������б�ռ����ⲿ���룬
                      ��С���ݷ�ҳ��ѯʱһҳ�ĸ����������롣


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
  2009-10-22  sunyifan (s06966) ����review����Խӿ���������������޸�
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_INTERFACE_H_
#define _IMOS_SDK_INTERFACE_H_

/* ����BPԤ������Լ��������͵��ļ� */
/** ����BPͷ�ļ�*/
#include "imos_public.h"
#include "imos_def.h"
#include "imos_errcode.h"

#include "imos_bp_def.h"
#include "imos_terminal_def.h"
#include "imos_mp_def.h"
#include "imos_mm_def.h"
#include "imos_as_def.h"

/** ����SDKͷ�ļ�*/
#include "sdk_def.h"
#include "sdk_struct.h"
#include "sdk_func_obsolete.h"

#include "sdk_tollgate_struct.h"

#ifdef  __cplusplus
extern "C"{
#endif

#if 0
#endif
/*************************************************************************************
SDK INIT
***************************************************************************************/
/** @defgroup groupSDKInit SDK��ʼ����ע��
*   SDK��ʼ������ϸ�ĵ���������ϵ��μ�SDK˵���ĵ�����ģ�������ʼ���ӿں���սӿڡ�
*   @{
*/
/**
* �����ʼ������ڡ� \n
* @param [IN]   szServerAdd         ��������ַ
* @param [IN]   ulServerPort        �������˿�
* @param [IN]   bUIFlag             SDK��UI�������ı�ǣ�#BOOL_TRUEΪ��UI�࣬#BOOL_FALSEΪ�ڷ�������
* @param [IN]   bXPFlag             SDK�Ƿ������XP�ı��, #BOOL_TRUEΪ����(XP)������; #BOOL_FALSEΪ������XP(������)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_SDK_ONE_USER_IN_ONE_PROC_ONLY
* - #ERR_AS_SDK_CREATE_THREAD_FAIL
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ʹ�õ�ʵ���ĵ���ģʽ#IMOS_Login/#IMOS_Logoutʱ,szServerAdd��ȡֵ:
*      1)�ڷ�������ȡ127.0.0.0, 127.0.0.1��VM��������ַ
*      2)�ڿͻ���ȡVM��������ַ
* - 2. ��ʹ�ö�ʵ���ĵ���ģʽ#IMOS_LoginEx/#IMOS_LogoutExʱ��szServerAdd��дΪ#IMOS_SDK_CLIB_INVALID_IP_ADDRESS
* - 3. ulServerPort��ȡֵΪ8800
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Initiate
(
    IN  CHAR    szServerAdd[IMOS_IPADDR_LEN],
    IN  ULONG_32   ulServerPort,
    IN  BOOL_T  bUIFlag,
    IN  BOOL_T  bXPFlag
);

/**
* SDK��սӿڣ���Ҫʵ�ַ����û���¼��Ϣ�Լ�����SDK��Ϊҵ��������ĸ�����Դ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. ��ʵ���˳�ʱ���봫NULL,��ȫ���ͷŵĲ���(��һ�Σ�����#IMOS_Initiate)
* - 2. ��ʵ���˳�ʱ���봫���½�û���Ϣ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CleanUp
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo
);
/** @} */ /* end of MG Module */

#if 0
#endif
/*************************************************************************************
User Login
***************************************************************************************/
/** @defgroup groupUserLogin �û���¼���˳�
*   �û�����
*   @{
*/


/**
* ����û���¼���ܣ�֧�ֶ���¼���ܡ�\n
* @param [IN]   szUserLoginName �û�����ĵ�¼��
* @param [IN]   szPassword      �û�����Ŀ���
* @param [IN]   szIpAddress     �û����ڿͻ��˵�IP��ַ
* @param [OUT]  pstSDKLoginInfo �û���¼������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_ADMIN_HAS_LOGGED_IN
* - #ERR_DAO_USER_NOT_EXIST
* - #ERR_MM_USER_IS_LOCKED
* - #ERR_MM_USER_PASSWORD_INCORRECT
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Login
(
    IN  CHAR           szUserLoginName[IMOS_NAME_LEN],
    IN  CHAR           szPassword[IMOS_PASSWD_ENCRYPT_LEN],
    IN  CHAR           szIpAddress[IMOS_IPADDR_LEN],
    OUT LOGIN_INFO_S   *pstSDKLoginInfo
);

/**
* �û��ǳ�
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_LOGIN_ID_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Logout
(
   IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo
);

/**
* ����û���¼���ܣ�֧�ֶ��û���¼���ܡ�\n
* @param [IN]   szUserLoginName �û�����ĵ�¼��
* @param [IN]   szPassword      �û�����Ŀ���
* @param [IN]   szSvrIpAddress  �û�����¼������IP��ַ
* @param [IN]   szCltIpAddress  �û����ڿͻ��˵�IP��ַ
* @param [OUT]  pstSDKLoginInfo �û���¼������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ͻ���ֱ�ӵ��ô˽ӿڣ������Ƚ�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LoginEx
(
    IN  CHAR           szUserLoginName[IMOS_NAME_LEN],
    IN  CHAR           szPassword[IMOS_PASSWD_ENCRYPT_LEN],
    IN  CHAR           szSvrIpAddress[IMOS_IPADDR_LEN],
    IN  CHAR           szCltIpAddress[IMOS_IPADDR_LEN],
    OUT LOGIN_INFO_S   *pstSDKLoginInfo
);

/**
* �û��ǳ�
* @param [IN]   pstUserLogIDInfo    �û���Ϣ��ʶ
* @return VOID
* @note
*/
IMOS_EXPORT VOID STDCALL IMOS_LogoutEx
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo
);

/**
* ����û�����ܡ�\n
* @param [IN]   pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ýӿ����ڵ�¼�ɹ�����û�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UserKeepAlive
(
    IN USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo
);

/**
* SDK�Զ�����ܡ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.�ýӿ�Ҫ���������������#USER_LOGIN_ID_INFO_S������������Ӧ�ڵ�¼�ɹ��󣬲��ܵ��øýӿڣ�
* -   ����֤UserloginID����ȷ�ԡ�
* - 2.���ӿ�ֻ���ڿͻ��˵��òŻ�ɹ���
* - 3.�Զ��������ö�ʱ����ʽʵ�֣����α��һ��30S������ʧ�ܴ����������� �� �յ����������صı���ʧ�ܵĴ�����Ӧ��
* -   ����ʶ�Զ�����ʧ�ܡ�
* - 4.�Զ�����ʧ�ܣ�����õ������ṩ�Ļص�����������#PROC_TYPE_LOGOUT��Ϣ�����������ṩ�Ļص�������Ȼ��Ч��
* - 5.һ��������ֻ֧��һ����¼�û����Զ������Ҫ�ٴε��ã������ȵ���IMOS_CleanUp()���SDK���ǳ��Ѿ���¼���û�
* - 6.���ӿ�ֻ��ӳ�Զ����������Ƿ�ɹ���ʧ��ԭ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AutoKeepAlive
(
    IN USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo
);

/**
* ��ɶ������͹��ܡ�\n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   ulSubscribePushType �������ͣ�ȡֵ��ΧΪ#SUBSCRIBE_PUSH_TYPE_E��Ŀǰ��֧��#SUBSCRIBE_PUSH_TYPE_ALL
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SubscribePushInfo
(
    IN USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN ULONG_32                  ulSubscribePushType
);

/** @} */ /* end of USER LOGIN MODULE */

#if 0
#endif
/**************************************************************************************************************
Role
***************************************************************************************************************/
/** @defgroup groupRoleMg Ȩ��(��ɫ)����
*   Ȩ��(��ɫ)����
*   @{
*/
/**
* ��ӽ�ɫ�����ؽ�ɫ���� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKUserRoleInfo  ��ɫ��Ϣ
* @param [OUT]  szRoleCode          ��ɫ���룬��ɫ��Ψһ��ʶ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NAME_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRole
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    USER_ROLE_INFO_S          *pstSDKUserRoleInfo,
    OUT   CHAR                      szRoleCode[IMOS_RES_CODE_LEN]
);


/**
* ���ݽ�ɫ���룬�޸Ľ�ɫ��Ϣ \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode                ��ɫ���룬��ɫ��Ψһ��ʶ
* @param [IN]   pstSDKUserRoleInfo        ��ɫ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_DAO_ROLE_NAME_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyRole
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szRoleCode[IMOS_RES_CODE_LEN],
    IN  USER_ROLE_INFO_S            *pstSDKUserRoleInfo
);


/**
* ���ݽ�ɫ���룬���ý�ɫȨ�� \n
* @param [IN]   pstUserLogIDInfo      �û���Ϣ��ʶ
* @param [IN]   szRoleCode            ��ɫ���룬��ӦΨһһ����ɫ
* @param [IN]   pstSDKDomainAuthority Ȩ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* - #ERR_DAO_ROLE_RES_NOT_EXIST
* - #ERR_DAO_ROLE_RES_EXIST
* -     ���ز�������룬���������ļ�
* @note
* -     1.�ýӿ����õ�Ȩ�޽����ڽ�ɫ������֯�����ýӿڽ������ý�ɫ������֯���Ƿ����ĳ��Ȩ��
* -     2.���øýӿں�, �Ըôε��õ�Ȩ��Ϊ׼; ��ɫ֮ǰ��Ȩ�޻ᱻ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRoleAuthority
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szRoleCode[IMOS_RES_CODE_LEN],
    IN  ORG_AUTHORITY_S             *pstSDKDomainAuthority
);


/**
* ���ݽ�ɫ���룬ɾ����ɫ��\n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode          ��ɫ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_MM_ROLE_IS_ASSIGNED
* - #ERR_MM_ROLE_IS_SYSTEM_MANAGER
* @note �����ɫ������ĳ�û�������ɾ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelRole
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szRoleCode[IMOS_RES_CODE_LEN]
);


/**
* ��ҳ��ѯ��ɫ�б� \n
* ����Ϊ��ʱ,��ѯ���н�ɫ,��Ĭ�ϰ���"��ɫ��������"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   bIsQuerySubOrg      �Ƿ��ѯ����֯�����¼���֯�������Ȩ��, #BOOL_TRUEΪ��ѯ; #BOOL_FALSEΪ����ѯ
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��ɫ����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKUserRoleList  ��ɫ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRoleList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  BOOL_T                          bIsQuerySubOrg,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ROLE_QUERY_ITEM_S               *pstSDKUserRoleList
);


/**
* ���ݽ�ɫ���룬��ѯ��ɫ����ϸ��Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode                  ����ѯ��ɫ����
* @param [OUT]  pstSDKUserRoleInfo          ��ɫ��ϸ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_ROLE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRoleInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRoleCode[IMOS_RES_CODE_LEN],
    OUT USER_ROLE_INFO_S        *pstSDKUserRoleInfo
);


/**
* ���ݽ�ɫ���룬��ѯĳ����ɫ��Ȩ����Ϣ \n
* @param [IN]  pstUserLogIDInfo     �û���¼ID��Ϣ��ʶ
* @param [IN]  szRoleCode           ��ɫ����
* @param [OUT] pstAuthorityInfo     ��ɫȨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByRole

(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRoleCode[IMOS_RES_CODE_LEN],
    OUT ORG_AUTHORITY_S         *pstAuthorityInfo
);

/**
* ��ѯ��ǰ��¼�û�������Ȩ��. \n
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
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByUser
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT BOOL_T                  *pbIsSystemMgr,
    OUT ORG_AUTHORITY_S         *pstAuthorityInfo
);


/**
* ���ݽ�ɫ���룬��ҳ��ѯ�˽�ɫ���������û�����Ϣ \n
* ����Ϊ��ʱ,��ѯ���й����û�,��Ĭ�ϰ���"�û���������"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szRoleCode          ��ɫ����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:
* -                                 #USER_CODE_TYPE[�û�����]��#USER_NAME_TYPE[�û�����]��#USER_FULL_NAME[�û�ȫ��]��
* -                                 #USER_TEL_PHONE[�û���������]��#USER_MOBILE_PHONE[�û��ƶ��绰����]��
* -                                 #USER_EMAIL[�û������ʼ���ַ]��#USER_IS_LOCKED[�û��Ƿ�����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKUserList      �û���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRelatedUserForRole
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szRoleCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT USER_QUERY_ITEM_S           *pstSDKUserList
);
/** @} */ /* end of ROLE MANAGEMENT MODULE */

#if 0
#endif
/**************************************************************************************************************
�û�
***************************************************************************************************************/
/** @defgroup groupUserMg �û�����
*   �û�����
*   @{
*/
/**
* �����û� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               �û�������֯����
* @param [IN]   pstUserPasswordInfo     �û���Ϣ(�����û���¼����)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_USER_EXCEED_LIMIT_NUM
* - #ERR_DAO_USER_CODE_EXIST
* - #ERR_DAO_USER_NAME_EXIST
* -     ���ز�������룬���������ļ�
* @note ����Ϣ�а����û����룬���û���Ψһ��ʶ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddUser
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  USER_INFO_PASSWORD_S        *pstUserPasswordInfo
);

/**
* �޸��û���Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstUserInfo             �û���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note �û���Ϣ�е��û�����˴�������д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyUser
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  USER_INFO_S                 *pstUserInfo
);

/**
* �޸��û����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstUserModifyPassword   �û�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_OPERATOR_AND_PASSWD_MODIFIED_USER_NOT_SAME
* - #ERR_DAO_USER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note �û�ֻ���޸����������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyUserPassword
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  USER_MODIFY_PASSWORD_S      *pstUserModifyPassword
);



/**
* Ϊ�û������ɫ���б� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szUserCode                  �û�����
* @param [IN]   aszRoleCode                 �����û��Ľ�ɫ��������
* @param [IN]   ulRoleCount                 �����û��Ľ�ɫ���������н�ɫ��ʵ�ʸ���,���ܳ���#IMOS_MAX_USER_ROLES_NUM
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_NOT_EXIST
* - #ERR_MM_USER_IS_ADMIN
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignRoleForUser
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szUserCode[IMOS_USER_CODE_LEN],
    IN  CHAR                                aszRoleCode[IMOS_MAX_USER_ROLES_NUM][IMOS_RES_CODE_LEN],
    IN  ULONG_32                               ulRoleCount
);

/**
* ɾ���û� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szUserCode                  �û�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_OPERATOR_SELF
* - #ERR_DAO_USER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelUser
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   CHAR                           szUserCode[IMOS_USER_CODE_LEN]
);

/**
* ��ѯ�û�����ϸ��Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szUserCode                  �û�����
* @param [OUT]  pstUserInfo                 �û���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserInfo
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   CHAR                           szUserCode[IMOS_USER_CODE_LEN],
    OUT  USER_INFO_S                    *pstUserInfo
);

/**
* ��ҳ��ѯ�û�ӵ�еĽ�ɫ \n
* ����Ϊ��ʱ,��ѯ�û�ӵ�е����н�ɫ,��Ĭ�ϰ���"��ɫ��������"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szUserCode          �û�����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��ɫ����]��#ROLE_PRIORITY[��ɫ���ȼ�])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstRoleList         ��ɫ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserAssignedRoles
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szUserCode[IMOS_USER_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ROLE_QUERY_ITEM_S               *pstRoleList
);



/**
* ��ҳ��ѯĳ����֯�µ��û��б� \n
* �����ѯ����ʱ,������,��Ĭ������(�û���������)
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����#NULL;֧�ֵĲ�ѯ��������:#USER_NAME_TYPE[�û�����],
* -                                              #IS_QUERY_SUB[�Ƿ������֯,#BOOL_TRUE��,#BOOL_FALSE��])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstUserList         �û���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT USER_QUERY_ITEM_S               *pstUserList
);



/**
* ��ѯĳ����֯�µ������û��б�  \n
* �����ѯ����ʱ,������,������Ĭ����������(�û���������)
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�����
* @param [IN]   bIsQuerySubOrg      �Ƿ��ѯ����֯���Լ��¼���֯������������û�, #BOOL_TRUEΪ��ѯ; #BOOL_FALSEΪ����ѯ
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����#NULL;֧�ֵĲ�ѯ��������:#USER_NAME_TYPE[�û�����])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstUserList         �û�������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnlineUserList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  BOOL_T                          bIsQuerySubOrg,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT USER_QUERY_ITEM_S               *pstUserList
);

/**
* �����û���¼���� \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  szUserCode               ��Ҫ����������û�����
* @param [IN]  szPassword               �µĵ�¼����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetUserPassword
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUserCode[IMOS_USER_CODE_LEN],
    IN  CHAR                        szPassword[IMOS_PASSWD_ENCRYPT_LEN]
);


/**
* ǿ��ĳ����¼�û�������
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  szUserLoginID            ��ǿ�������û��ĵ�¼ID
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_OPERATOR_SELF
* - #ERR_AS_EXPECTED_USER_NOT_EXIST
* - #ERR_MM_USER_IS_ADMIN
* -     ���ز�������룬���������ļ�
* @note 1.�û�����ǿ�Ʊ������ߣ�
* -     2.����ǿ��admin�û�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_KickOffLoginUser
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUserLoginID[IMOS_RES_CODE_LEN]
);


/**
* �����û�
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  szUserCode               �������û��ı���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_NOT_EXIST
* - #ERR_MM_USER_IS_ADMIN
* -     ���ز�������룬���������ļ�
* @note 1.���������û��ڽ���ǰ���ܹ���¼;
* -     2.�û���������,�����е�¼��(�����)����ǿ������;
* -     3.admin�û����ܱ�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LockUser
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUserCode[IMOS_USER_CODE_LEN]
);


/**
* �û�����
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  szUserCode               �������û��ı���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_USER_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnLockUser
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUserCode[IMOS_USER_CODE_LEN]
);
/** @} */ /* end of USER MANAGEMENT MODULE */

#if 0
#endif
/*******************************************************************************
��֯����

*******************************************************************************/
/** @defgroup groupOrgMg ��֯����
*   ��֯����
*   @{
*/
/**
* �����֯�ڵ� \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN][OUT]  pstOrgNodeInfo     ��֯��Ϣ(��Ϊ���ʱ,��֯�������Ϊ��;��Ϊ����ʱ, ����ε���֯����Ϊ��, ��Я�����ڲ����ɵ���֯����)
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_DOMAIN_EXCEED_LIMIT_NUM
* - #ERR_MM_DOMAIN_PARENT_DOMAIN_NOT_EXIST
* - #ERR_MM_DOMAIN_TOO_DEEP
* -     ���ز�������룬���������ļ�
* @note ��֯�ڵ���Ϣ�е���֯��������֯��Ψһ��ʶ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOrganization
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    INOUT   ORG_NODE_INFO_S         *pstOrgNodeInfo
);


/**
* �޸���֯�ڵ���Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstOrgNodeInfo      ���޸���֯�ڵ���Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_DAO_RES_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOrganization
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   ORG_NODE_INFO_S                *pstOrgNodeInfo
);



/**
* ɾ����֯�ڵ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��ɾ����֯�ڵ����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_DAO_RES_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - 1.����ɾ����ǰ�û�������֯
* - 2.��ĳ��֯��������֯����Դʱ, ����֯�޷�ɾ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelOrganization
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN]
);


/**
* ��ҳ��ѯ��֯�µ�����֯�ڵ��б�ֻ��ѯ����֯��һ�������֯ \n
* �����ѯ����ʱ,������,������Ĭ����������(��֯��������)
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode          ��֯�ڵ����
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[��֯����])
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstOrgNodeList     ��֯�ڵ��б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ORG_NODE_INFO_S                 *pstOrgNodeList
);


/**
* ��ѯ��֯�ڵ���Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�ڵ����
* @param [OUT]  pstOrgNodeInfo      ��֯�ڵ���Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgInfo
(
    IN     USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN     CHAR                         szOrgCode[IMOS_DOMAIN_CODE_LEN],
    OUT    ORG_NODE_INFO_S              *pstOrgNodeInfo
);


/**
* ��ҳ��ѯ��֯�µ���Դ��Ϣ�б� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯�ڵ����
* @param [IN]   ulResType           ����ѯ����Դ���ͣ�ȡֵΪ#IMOS_TYPE_E
* @param [IN]   pstQueryCondition   ��ѯ����(����NULL;֧�ֵĲ�ѯ��������:#RES_SUB_TYPE[��Դ������])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResList          ��Դ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.�����Ҫ��ѯ�ض�������(�籾�������)�µ���Դ�б�,�����Ӳ�ѯ����#DOMAIN_TYPE(������),���Ҳ�ѯ�������ַ���"0"������,"1"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                           ulResType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT ORG_RES_QUERY_ITEM_S            *pstResList
);

/**
* ��ѯ��֯����Դ��Ϣ�б�(V2,��չ����"��Դ������֯������") \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   pstQueryCondition   ��ѯ����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResList          ��Դ��Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ����֯��������Դ(��������֯);
* - 2.֧�ְ�"�Ƿ������֯"������ѯ:#IS_QUERY_SUB = 1 ��;= 0 ��;
* - 3.֧�ְ�"��Դ����"ģ����ѯ:#NAME_TYPE;
* - 4.֧�ְ�"�Ƿ�������Դ"��ѯ:#DOMAIN_TYPE = 1 ��;= 0 ��;
* - 5.֧�ְ�"��Դ����"��ѯ:#RES_TYPE,ȡֵΪ#IMOS_TYPE_E, ��֧���߼���ϵ����Ϊ#EQUAL_FLAG;
* - 6.֧�ְ�"��Դ������"��ѯ:#RES_SUB_TYPE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_TYPE_E);
* - 7.֧�ְ�"��Դ����"��ѯ:#RES_ATTRIBUTE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_ATTRIBUTE_E);
* - 8.֧��"���ײ�"��ѯ:#IS_QUERY_ENCODESET
     (��Դ����Ϊ������������ʱ,
      ȡֵΪ#0-����ѯ����pstResList�е�ulDevEncodeSet��Ч;
      ȡֵΪ#1-��ѯ����pstResList�е�ulDevEncodeSet��Ч);
* - 9.֧���Ƿ������ؿ���֯: #IS_HIDE_EMPTY_ORG = 1 ��; =0 ��
* - 10.֧���Ƿ���˵���Ϊ��Դ��������������Դ�������ɵĻ����¼: #IS_LEACH_SHARED_BELONG = 1 ��; = 0 ��
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Դ����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��Դ����),#CODE_TYPE(��Դ����),#RES_TYPE(��Դ����),#RES_SUB_TYPE(��Դ������),
* -   #DOMAIN_TYPE(�Ƿ�������Դ),#RES_ATTRIBUTE(��Դ����),#RES_ORDER_NUMBER(��Դ���)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT RES_ITEM_V2_S                   *pstResList
);

/** @} */ /* end of ORG MANAGEMENT MODULE */

/* Begin Added by s04382, 20180226 for v2 optimize*/
/**
* ��ѯ��֯����Դ��Ϣ�б�(V2Opt,��չ����"��Դ������֯������") \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                        szOrgCode                   ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition          ��ѯ����
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  RES_ITEM_V2_S               *pstResList                 ��Դ��Ϣ�б�
* @return ULONG_32 �������½����
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
* - 5.֧�ְ�"��Դ����"��ѯ:#RES_TYPE,ȡֵΪ#IMOS_TYPE_E, ��֧���߼���ϵ����Ϊ#EQUAL_FLAG;
* - 6.֧�ְ�"��Դ������"��ѯ:#RES_SUB_TYPE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_TYPE_E)
* - 7.֧�ְ�"��Դ����"��ѯ:#RES_ATTRIBUTE(��Դ����Ϊ�����ʱ,ȡֵΪ#CAMERA_ATTRIBUTE_E)
* - 8.֧��"���ײ�"��ѯ:#IS_QUERY_ENCODESET
     (��Դ����Ϊ������������ʱ,
      ȡֵΪ#0-����ѯ����pstResList�е�ulDevEncodeSet��Ч;
      ȡֵΪ#1-��ѯ����pstResList�е�ulDevEncodeSet��Ч)
* - 9.֧���Ƿ������ؿ���֯: #IS_HIDE_EMPTY_ORG = 1 ��; =0 ��
* - 10.֧���Ƿ���˵���Ϊ��Դ��������������Դ�������ɵĻ����¼: #IS_LEACH_SHARED_BELONG = 1 ��; = 0 ��
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��Դ����"��������
* - 2.֧�ֵ���������,����:#NAME_TYPE(��Դ����),#CODE_TYPE(��Դ����),#RES_TYPE(��Դ����),#RES_SUB_TYPE(��Դ������),
* -   #DOMAIN_TYPE(�Ƿ�������Դ),#RES_ATTRIBUTE(��Դ����),#RES_ORDER_NUMBER(��Դ���)
*/
ULONG_32 STDCALL IMOS_QueryResourceListV2Opt
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT RES_ITEM_V2_S                   *pstResList
);
/*End add by s04382 for v2 opt 20180305*/

/* Begin: Added by luhaitao/01337, 2015-03-04 for ���ֶ��� */
/**
* ��ѯ������Դ��·������Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [INOUT]   pulRowNum                  �����Դ���������������Դ����
* @param [INOUT]   pstResLinkFlagList         �����Դ��Ϣ�����������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetShareResBkpLinkFlagList
(
    IN    USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    INOUT ULONG_32                        *pulRowNum,
    INOUT SHARE_RES_BKP_LINK_FLAG_S       *pstResLinkFlagList
);

/**
* ���ù�����Դ��·������Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ��ʶ
* @param [IN]   ulRowNum                      ��Դ����
* @param [IN]   pstResLinkFlagList            ��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetShareResBkpLinkFlagList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                        ulRowNum,
    IN  SHARE_RES_BKP_LINK_FLAG_S       *pstResLinkFlagList
);
/* End: Added by luhaitao/01337, 2015-03-04 for ���ֶ��� */

#if 0
#endif
/*******************************************************************************
�豸-EC/DC
*******************************************************************************/
/** @defgroup groupEC �豸����
* - ����EC����ɾ�Ĳ��Լ�����ECͨ��,����,�������Ƚӿ�;
* - ����DC����ɾ�Ĳ��Լ�����DCͨ��,����,�������Ƚӿ�
*   @{
*/
/**
* @name ������(EC)
* @{    ������(EC)
*/
/**
* ���ӱ����� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEcInfo                   EC�豸��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_AS_EC_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.EC���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEc
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    EC_INFO_S                     *pstEcInfo
);



/**
* �޸ı�������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstEcInfo                   ��������Ϣ
* @param [IN]   bIsEncodeChange             ���ײ��Ƿ�����ʶ, #BOOL_TRUEΪ��������ײ�; #BOOL_FALSEΪδ������ײ�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��������Ϣ�е�EC���벻���޸�, ����Ҫ��д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEc
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  EC_INFO_S                       *pstEcInfo,
    IN  BOOL_T                          bIsEncodeChange
);



/**
* ɾ�������� \n
* @param [IN] pstUserLogIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN] szEcCode          EC�ı���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_HAS_CAMERA
* - #ERR_MM_DEV_CONTAIN_SUBDEVICE
* - #ERR_AS_HAS_TRANSCHNL
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEc
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szEcCode[IMOS_DEVICE_CODE_LEN]
);


/**
* �����豸 \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode           �豸����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* - #ERR_MM_DEVICE_OFFLINE
* - #ERR_MM_CONFIGURE_DEVICE_FAIL
* -     ���ز�������룬���������ļ�
* @note ֻ֧��EC��DC������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RebootDevice
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_CODE_LEN]
);


/**
* ��ҳ��ѯĳ����֯�µı������б�  \n
* ֧��ģ����ѯ��pstQueryCondition����Ϊ�գ���ʾ��������Ч����ѯ����֯�����б�����������ȱʡ����ģ����ѯ��Ĭ�ϰ���"��������������"����.
* ֧�ֲ�ѯEC��"HC"��"HD"��β��ECR,����ѯECRʱ��Ҫ����ָ���豸����ΪECR����pstQueryCondition��ָ��#RES_TYPEΪ#IMOS_TYPE_ECR.
* �����豸IP��ѯ��ֻ֧��ģ����ѯ����֧�־�ȷ��ѯ.
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryCondition           ��ѯ��Ϣ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����������]; #CODE_TYPE[����������]; #RES_TYPE[��Դ����]; #PHY_DEV_IP[������IP��ַ]; #CAMERA_NAME[���������])
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstEcList                   �������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��ѯ�����е����������#CAMERA_NAMEֻ��ʹ��#LIKE_FLAG����ģ����ѯ, ��ѯ�����������Ӧ�ı�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEcList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT EC_QUERY_ITEM_S                 *pstEcList
);



/**
* ��ѯ����������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szEcCode                    ����������
* @param [OUT]  pstEcInfo                   ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEcInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szEcCode[IMOS_DEVICE_CODE_LEN],
    OUT EC_INFO_S                       *pstEcInfo
);
/** @} */ /* End of EC */


#if 0
#endif
/***************************************************************************
�豸-ECͨ���Լ������
****************************************************************************/
/**
* @name ECͨ��
* @{    ECͨ��
*/
/**
* ��������󶨵���������ĳ��ͨ���� \n
* @param [IN]  pstUserLogIDInfo             �û���¼ID��Ϣ��ʶ
* @param [IN]  pstVinChnlAndCamInfo         ����������ͨ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.��������벻��Ϊ��,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VINCHNL_BIND_CAMERA_S           *pstVinChnlAndCamInfo

);



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
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraAndChannelList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CAM_AND_CHANNEL_QUERY_ITEM_S    *pstCamAndChannelList
);



/**
* �޸������ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCamInfo                  �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_INFO_S                   *pstCamInfo
);

/* Begin Add by zhouquanwei/z01364 2013/12/16 for ���������������չ */
/**
* �޸������
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCamInfoEX                �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCameraEX
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_INFO_EX_S                *pstCamInfoEX
);
/* End Add by zhouquanwei/z01364 2013/12/16 for ���������������չ */

/**
* ���������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* @note 1.���ý����������ӿں󣬸��������������Ϣ������ɾ����
* -     2.�������������ô洢��Դ������øýӿڽ�ʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnBindCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN]
);


/**
* ��ѯ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode                   ���������
* @param [OUT]  pstCameraInfo               �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT CAMERA_INFO_S                   *pstCameraInfo
);

/* Begin Add by zhouquanwei/z01364 2013/12/16 for ���������������չ */
/**
* ��ѯ�������Ϣ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode                   ���������
* @param [OUT]  pstCameraInfoEX             ��չ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraEX
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT CAMERA_INFO_EX_S                *pstCameraInfoEX
);
/* End Add by zhouquanwei/z01364 2013/12/16 for ���������������չ */

/**
* ����EC����ͨ����Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN]   pstVideoInChannelInfo       ����ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigVideoInChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIN_CHANNEL_S                   *pstVideoInChannelInfo
);


/**
* ��ѯEC����ͨ����Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [OUT]  pstVideoInChannelInfo       ����ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECVideoInChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT VIN_CHANNEL_S                   *pstVideoInChannelInfo
);


/**
* ����EC��Ƶ����ͨ������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN]   pstVideoStreamInfo          ��Ƶ����ͨ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIN_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigECVideoStream
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIDEO_STREAM_S                  *pstVideoStreamInfo
);


/**
* ��ѯEC��Ƶ����ͨ������Ϣ \n
* @param [IN]       pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]       pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN][OUT]  pulStreamNum                ����ͨ����Ƶ��������, ȡ���ڱ����������ײ�ѡ��, ���ȡֵΪ2
* @param [OUT]      pstVideoStreamInfo          ��Ƶ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIDEO_STREAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECVideoStream
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulStreamNum,
    OUT   VIDEO_STREAM_S              *pstVideoStreamInfo
);
/*Begin added by liangchao, 2016-03-24 for svc���Ժ�����*/
/**
* ����EC��Ƶ����ͨ������Ϣ
* @param [IN]   pstUserLoginIDInfo            �û���Ϣ
* @param [IN]   pstChannelIndex             �豸ͨ��������Ϣ
* @param [IN]   pstVideoStreamInfo          ��Ƶ����ͨ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����svc������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigECVideoStreamV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIDEO_STREAM_S_V2                  *pstVideoStreamInfo
);

/**
* ��ѯEC��Ƶ����ͨ������ϢV2
* @param [IN]     pstUserLoginIDInfo            �û���Ϣ
* @param [IN]     pstChannelIndex             �豸ͨ��������Ϣ
* @param [INOUT]  pulStreamNum                ����ͨ����Ƶ��������
* @param [OUT]    pstVideoInChannelInfo       ��Ƶ����Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����svc����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECVideoStreamV2
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulStreamNum,
    OUT   VIDEO_STREAM_S_V2              *pstVideoStreamInfo
);
/*End added by liangchao, 2016-03-24 for svc���Ժ�����*/

/**
* ����EC����ͨ���ڸ�������Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  ulMaskAreaNum            ����ͨ���ڸ�����ĸ���, ���ȡֵΪ#IMOS_MASK_AREA_MAXNUM
* @param [IN]  pstMaskArea              ����ͨ���ڸ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIDEO_AREA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigECMaskAreaOSD
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  ULONG_32                        ulMaskAreaNum,
    IN  VIDEO_AREA_S                *pstMaskArea
);

/**
* ��ѯEC����ͨ���ڸ�������Ϣ \n
* @param [IN]       pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]       pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN][OUT]  pulMaskAreaNum           ����ͨ���ڸ�����ĸ���, ���ȡֵΪ#IMOS_MASK_AREA_MAXNUM
* @param [OUT]      pstMaskArea              ����ͨ���ڸ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIDEO_AREA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECMaskAreaOSD
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulMaskAreaNum,
    OUT   VIDEO_AREA_S                *pstMaskArea
);


/**
* ����EC����ͨ���˶����������Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  ulMotionDetectAreaNum    ����ͨ���˶��������ĸ���, ���ȡֵΪ#IMOS_DETECT_AREA_MAXNUM
* @param [IN]  pstMotionDetectArea      ����ͨ���˶����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIDEO_AREA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigECMotionDetectArea
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  ULONG_32                        ulMotionDetectAreaNum,
    IN  VIDEO_AREA_S                *pstMotionDetectArea
);

/**
* ��ѯEC����ͨ���˶����������Ϣ \n
* @param [IN]       pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]       pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN][OUT]  pulMotionDetectAreaNum   ����ͨ���˶��������ĸ���, ���ȡֵΪ#IMOS_DETECT_AREA_MAXNUM
* @param [OUT]      pstMotionDetectArea      ����ͨ���˶����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VIDEO_AREA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECMotionDetectArea
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulMotionDetectAreaNum,
    OUT   VIDEO_AREA_S                *pstMotionDetectArea
);

/**
* �����豸��ͨ��ʱ��OSD��Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  pstTimeOSD               ����ͨ��ʱ��OSD��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_OSD_TIME_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigDeviceTimeOSD
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  OSD_TIME_S                  *pstTimeOSD
);

/**
* ��ѯ�豸��ͨ��ʱ��OSD��Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [OUT] pstTimeOSD               ����ͨ��ʱ��OSD��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_OSD_TIME_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeviceTimeOSD
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT OSD_TIME_S                  *pstTimeOSD
);

/**
* �����豸��ͨ������OSD��Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  ulNameOSDNum             ����ͨ������OSD�ĸ���, ���ȡֵΪ#IMOS_OSD_NAME_MAXNUM;
*                                       ��ֵ���豸�������:���豸����ΪEC2004-HF/VR2004/EC2016-HC[4CH]/EC2016-HC[8CH]/EC2016-HCʱ,��ֵΪ#IMOS_OSD_NAME_MAXNUM_II;
*                                       �����ϼ������͵�EC�豸��,�豸����Ϊ��������ECʱ,��ֵΪ#IMOS_OSD_NAME_MAXNUM;
*                                       ���豸����ΪDCʱ,��ֵΪ#IMOS_OSD_NAME_MAXNUM_I
* @param [IN]  pstNameOSD               ����ͨ������OSD��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_OSD_NAME_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ע��"��̨�����û�OSD"�Ĵ���:������1,���б����1��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigDeviceNameOSD
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  ULONG_32                        ulNameOSDNum,
    IN  OSD_NAME_S                  *pstNameOSD
);

/**
* ��ѯ�豸��ͨ������OSD��Ϣ \n
* @param [IN]       pstUserLogIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]       pstChannelIndex       �豸ͨ��������Ϣ
* @param [IN][OUT]  pulNameOSDNum         ����ͨ������OSD����, ���ȡֵΪ#IMOS_OSD_NAME_MAXNUM;
*                                         ��ֵ���豸�������:���豸����ΪEC2004-HF/VR2004/EC2016-HC[4CH]/EC2016-HC[8CH]/EC2016-HCʱ,��ֵΪ#IMOS_OSD_NAME_MAXNUM_II;
*                                         �����ϼ������͵�EC�豸��,�豸����Ϊ��������ECʱ,��ֵΪ#IMOS_OSD_NAME_MAXNUM;
*                                         ���豸����ΪDCʱ,��ֵΪ#IMOS_OSD_NAME_MAXNUM_I
* @param [OUT]      pstNameOSD            ����ͨ������OSD��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_OSD_NAME_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeviceNameOSD
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulNameOSDNum,
    OUT   OSD_NAME_S                  *pstNameOSD
);

/** @} */ /* end of CAMERA & CHANNEL MANAGEMENT MODULE */


#if 0
#endif
/*******************************************************************************
�豸-DC
*******************************************************************************/
/**
* @name ������(DC)
* @{    ������(DC)
*/
/**
* ���ӽ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDcInfo               ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_AS_DC_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.DC���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDc
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DC_INFO_S                   *pstDcInfo
);



/**
* �޸Ľ�������Ϣ�������豸���벻�����޸ģ�������Ҫ���롣 \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDcInfo                   �����Ľ�������Ϣ
* @param [IN]   bIsEncodeChange             ���ײ��Ƿ�����ʶ, #BOOL_TRUEΪ���������ײ�; #BOOL_FALSEΪδ�������ײ�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDc
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DC_INFO_S                       *pstDcInfo,
    IN  BOOL_T                          bIsEncodeChange
);


/**
* ɾ�������� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDcCode                    ����������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_HAS_MONITOR
* - #ERR_MM_DEV_CONTAIN_SUBDEVICE
* - #ERR_AS_HAS_TRANSCHNL
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDc
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDcCode[IMOS_DEVICE_CODE_LEN]
);


/**
* ��ҳ��ѯĳ����֯�µĽ������б�  \n
* ����Ϊ��ʱ,��ѯ���н�����,��Ĭ�ϰ���"��������������"����.
* �����豸IP��ѯ��ֻ֧��ģ����ѯ����֧�־�ȷ��ѯ.
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[����������]; #CODE_TYPE[����������]; #PHY_DEV_IP[������IP��ַ]; #MONITOR_NAME[����������])
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDcQueryList              ��������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��ѯ�����еļ���������#MONITOR_NAMEֻ��ʹ��#LIKE_FLAG����ģ����ѯ, ��ѯ���Ǽ�������Ӧ�Ľ�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDcList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szcOrgCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT DC_QUERY_ITEM_S                 *pstDcQueryList
);



/**
* ��ѯ����������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDcCode                    �������ı���
* @param [OUT]  pstDcInfo                   ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDcInfo
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   CHAR                           szDcCode[IMOS_DEVICE_CODE_LEN],
    OUT  DC_INFO_S                      *pstDcInfo
);
/** @} */ /* end of DC MANAGEMENT MODULE */



#if 0
#endif
/***************************************************************************
�豸-DCͨ���Լ�������
****************************************************************************/
/**
* @name DCͨ��
* @{    DCͨ��
*/
/**
* ���������󶨵�DC��ĳ��ͨ���� \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstVOUTChnlAndScrInfo    �����������ͨ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.���������벻��Ϊ��,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindScreenToVideoOutChannel
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  VOUTCHNL_BIND_SCREEN_S  *pstVOUTChnlAndScrInfo

);

/**
* ��ѯĳ��DC�豸��ͨ���Լ���������Ϣ�б� \n
* ����Ϊ��ʱ,��ѯ����ͨ���Լ�������,��Ĭ�ϰ���"��Ƶ���ͨ����������"����
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode              �豸����
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#INDEX_TYPE[��Ƶ���ͨ������])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVOUTChnlAndScrList  �����������ͨ�����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenAndChannelList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT SCR_AND_CHANNEL_QUERY_ITEM_S    *pstVOUTChnlAndScrList
);



/**
* �޸ļ�������Ϣ \n
* @param [IN]  pstUserLogIDInfo                     �û���¼ID��Ϣ��ʶ
* @param [IN]  pstScrInfo                           ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��������Ϣ�еļ��������벻���޸�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyScreen
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   SCREEN_INFO_S                  *pstScrInfo
);



/**
* ����󶨼����� \n
* @param [IN] pstUserLogIDInfo                      �û���¼ID��Ϣ��ʶ
* @param [IN] szScrCode                             ����������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnBindScreen
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szScrCode[IMOS_RES_CODE_LEN]
);


/**
* ��ѯĳ���������ľ�����Ϣ \n
* @param [IN] pstUserLogIDInfo                          �û���¼ID��Ϣ��ʶ
* @param [IN] szScrCode                                 ����������
* @param [OUT]pstScrInfo                                ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreen
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szScrCode[IMOS_RES_CODE_LEN],
    OUT   SCREEN_INFO_S                 *pstScreenInfo
);


/**
* ����DC����Ƶ�߼����ͨ����Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  ulVideoOutNum            ����ͨ�������߼�ͨ��������, ���ֵΪ(#SPLIT_SCR_MODE_MAX - 1)
* @param [IN]  pstVideoInChannelInfo    ��Ƶ�߼����ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VOUT_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigDCVideoOutChannel
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S     *pstChannelIndex,
    IN  ULONG_32                    ulVideoOutNum,
    IN  VOUT_CHANNEL_S          *pstVideoOutChannelInfo
);


/**
* ��ѯDC����Ƶ�߼����ͨ����Ϣ \n
* @param [IN]       pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]       pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN][OUT]  pulVideoOutNum           ����ͨ�������߼�ͨ��������, ���ֵΪ(#SPLIT_SCR_MODE_MAX - 1)
* @param [OUT]      pstVideoOutChannelInfo   ��Ƶ�߼����ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_VOUT_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDCVideoOutChannel
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S     *pstChannelIndex,
    INOUT ULONG_32                   *pulVideoOutNum,
    OUT   VOUT_CHANNEL_S          *pstVideoOutChannelInfo
);



/**
* ����DC�������ͨ����Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [IN]  pstPhyoutChannelInfo     �������ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PHYOUT_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigDCPhyOutChannel
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S     *pstChannelIndex,
    IN  PHYOUT_CHANNEL_S        *pstPhyoutChannelInfo
);


/**
* ��ѯDC���������ͨ����Ϣ \n
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstChannelIndex          �豸ͨ��������Ϣ
* @param [OUT] pstPhyoutChannelInfo     �������ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PHYOUT_CHANNEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDCPhyOutChannel
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S     *pstChannelIndex,
    OUT PHYOUT_CHANNEL_S        *pstPhyoutChannelInfo
);

/** @} */ /* end of DC Channel */

/** @} */ /* end of EC/DC Channel Module */

#if 0
#endif
/*******************************************************************************
 �豸���ع���
*******************************************************************************/
/**
* @name �豸���ع���(EC,DC)
* @{    �豸���ع���(EC,DC)
*/
/**
* �����豸�����뿪���� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [IN]   pstSemaInputInfo        ���뿪������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfInSwitch
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  SEMA_INPUT_INFO_S           *pstSemaInputInfo
);

/**
* �����豸����������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [IN]   pstSemaOutputInfo       �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfOutSwitch
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  SEMA_OUTPUT_INFO_S          *pstSemaOutputInfo
);



/**
* ��ѯ�豸�Ŀ������б� \n
* �����ѯ����ʱ,������,��Ĭ������(��������������)
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode          �豸����
* @param [IN]   ulDevType          �豸����, ȡֵΪ#IMOS_TYPE_EC��#IMOS_TYPE_DC
* @param [IN]   pstQueryCondition  ͨ�ò�ѯ����(����#NULL;֧�ֵĲ�ѯ��������:#INDEX_TYPE[����������])
* @param [IN]   pstQueryPageInfo   �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo     ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSemaList        ��������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                       ulDevType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SEMA_QUERY_ITEM_S           *pstSemaList
);

/* Begin Add By hexiaojun for/hW0959 IPC�澯�������� 2014-11-22 */
/**
* ��ѯ����������澯Դ�б�
* @param [IN]   pstUserLoginIDInfo      �û���Ϣ
* @param [IN]   szCameraCode            ���������
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstIPCAlmSrcList        ��ѯ�����澯Դ�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.����޲�ѯ������ָ��pstQueryCondition����ΪNULL;
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIPCAlarmSrcList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IPC_ALARMSRC_INFO_S         *pstIPCAlmSrcList
);
/* End Add By hexiaojun for/hW0959 IPC�澯�������� 2014-11-22 */

/**
* ��ѯ���뿪������Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [OUT]  pstSemaInputInfo        ���뿪������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryInSwitch
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT SEMA_INPUT_INFO_S           *pstSemaInputInfo
);

/**
* ��ѯ�����������Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstChannelIndex         �豸ͨ��������Ϣ
* @param [OUT]  pstSemaOutputInfo       �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOutSwitch
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT SEMA_OUTPUT_INFO_S          *pstSemaOutputInfo
);
/** @} */ /* end of SWITCH MANAGEMENT MODULE */

#if 0
#endif

/**
* ���DM������������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   DM_INFO_S               *pstSDKDMInfo           DM��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.DM��Ϣ�е�DM������DM��������Ψһ��ʶ
* -     2.DM���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCDM
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN CDM_INFO_S                    *pstSDKCDMInfo
);

/**
* �޸�DM�����������벻���޸ģ�������Ҫ���� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   DM_INFO_S               *pstSDKDMInfo           DM��Ϣ
* @return ULONG_32 �������½����
* - �ɹ��ERR_COMMON_SUCCEED?
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCDM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CDM_INFO_S                   *pstSDKCDMInfo
);

/**
* ɾ��DM������ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                   �û���Ϣ
* @param [IN]   CHAR                    szDMCode[IMOS_DEVICE_CODE_LEN]      DM����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֻ��һ����ɾ��DM������ɾ��DM�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCDM
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN CHAR                         szCDMCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯĳ����֯�µ�DM�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CHAR                        szOrgCode               ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[DM����])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  DM_QUERY_ITEM_S             *pstSDKDMList           DM�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note  1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�DM�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDMList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CDM_QUERY_ITEM_S             *pstSDKCDMList
);

/**
* ��ѯĳ��DM�ľ�����Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                   �û���Ϣ
* @param [IN]   CHAR                    szDMCode[IMOS_DEVICE_CODE_LEN]      DM����
* @param [OUT]  DM_INFO_S               *pstSDKDMInfo                       DM��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDMInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szCDMCode[IMOS_DEVICE_CODE_LEN],
    OUT CDM_INFO_S                   *pstSDKCDMInfo
);


/**
* �޸Ĵ洢�豸�����벻���޸ģ�������Ҫ���� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   STORE_DEV_INFO_S        *pstStoreDevInfo        �洢�豸��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCDV
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CDV_INFO_S            *pstCDVInfo
);


/**
* ��Ӵ洢�豸������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   STORE_DEV_INFO_S        *pstStoreDevInfo        �洢�豸��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCDV
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CDV_INFO_S            *pstCDVInfo
);

/**
* ���洢�豸����ɾ���洢�豸 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                       �û���Ϣ
* @param [IN]   CHAR                    szStorageDevCode[IMOS_DEVICE_CODE_LEN]  �洢�豸����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCDV
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szCDVCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯĳ����֯�µĴ洢�豸�б�  \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo                   �û���Ϣ
* @param [IN]   CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN]     ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition                  ͨ�ò�ѯ����
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo                   �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo                     ���ط�ҳ��Ϣ
* @param [OUT]  STORE_DEV_QUERY_ITEM_S      *pstStoreDevList                    �洢�豸�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1��szOrgCode����Ϊ�մ�, ��ʾ��ѯ��ϵͳ���еĴ洢�豸�б�
* - 2��pstQueryCondition��QUERY_CONDITION_ITEM_S�Ĳ�ѯ������ö��QUERY_TYPE_E, Ŀǰ֧�ֵ�ֻ��NAME_TYPE CODE_TYPE PHY_DEV_IP;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgCDVList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR       szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR       szCDMCode[IMOS_DEVICE_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CDV_QUERY_ITEM_S      *pstCDVList
);

/**
* ��ѯĳ���洢�豸 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                       �û���Ϣ
* @param [IN]   CHAR                    szStorageDevCode[IMOS_DEVICE_CODE_LEN]  �洢�豸����
* @param [OUT]   STORE_DEV_INFO_S        *pstStoreDevInfo                        �洢�豸��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDVInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szCDVCode[IMOS_DEVICE_CODE_LEN],
    OUT CDV_QUERY_INFO_S            *pstCDVInfo
);

/**
* �Ӵ洢�豸�Ϸ��乲��洢��Դ \n
* @param [IN]   pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstShareResInfo     ������Դ��Ϣ
* @param [OUT]  szShareResCode      ������Դ����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignCDVRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CDV_RES_INFO_S     *pstCDVResInfo
);

/**
* ɾ������洢��Դ \n
* @param [IN]   pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode     ������Դ����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCDVRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo,
    IN  CHAR       szCDVResCode[IMOS_CODE_LEN]
);

/**
* ��ѯ����洢��Դ�б� \n
* ����Ϊ��ʱ,������,��Ĭ��"������������"  \n
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:NAME_TYPE[������Դ����])
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDmShareResItemList  ����洢��Դ�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDVResList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR   szCDVCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT CDV_RES_QUERY_ITEM_S    *pstCDVResItemList
);


#if 0
#endif
/**************************************************************************************************************
�豸-DM
***************************************************************************************************************/
/** @defgroup group ����������(DM)
*   �������������DM,VX500,MS,�洢�豸�����
*   @{
*/
/**
* @name DM����
* @{    DM����
*/
/**
* ����DM������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKDMInfo        DM��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_LICENSE_EXCEEDED
* - #ERR_AS_DM_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.DM��Ϣ�е�DM������DM��������Ψһ��ʶ
* -     2.DM���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDM
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN DM_INFO_S                    *pstSDKDMInfo
);


/**
* �޸�DM��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKDMInfo        DM��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note DM��Ϣ�е�DM���벻���޸�, �����޸�DM��Ϣʱ��Ҫ��д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DM_INFO_S                   *pstSDKDMInfo
);


/**
* ɾ��DM������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szDMCode            DM����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_HAS_STORAGE_DEV
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDM
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN CHAR                         szDMCode[IMOS_DEVICE_CODE_LEN]
);


/**
* ��ҳ��ѯĳ����֯�µ�DM�б�  \n
* ֧�ְ�DM������ģ����ѯ��Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,��ѯ����DM,��Ĭ�ϰ���"DM��������"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[DM����] #CODE_TYPE[DM����] #PHY_DEV_IP[DM IP])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKDMList        DM�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note  1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�DM�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDMList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT DM_QUERY_ITEM_S             *pstSDKDMList
);


/**
* ��ѯĳ��DM�ľ�����Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szDMCode            DM����
* @param [OUT]  pstSDKDMInfo        DM��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDMInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDMCode[IMOS_DEVICE_CODE_LEN],
    OUT DM_INFO_S                   *pstSDKDMInfo
);
/** @} */ /* end of DEVICE DM MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
�豸-�洢�豸
****************************************************************************/
/**
* @name �洢�豸����
* @{    �洢�豸����
*/
/**
* ���Ӵ洢�豸 \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstStoreDevInfo     �洢�豸��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_IPSAN_NUM_PER_DM_EXCEEDED
* - #ERR_MP_ISM_USERNAME
* - #ERR_MP_ISM_GET_CAPACITY
* - #ERR_DAO_STORAGE_CODE_EXIST
* - #ERR_DAO_STORAGE_NAME_EXIST
* - #ERR_DAO_STORAGE_ADDR_EXIST
* -     ���ز�������룬���������ļ�
* @note �洢�豸��Ϣ�еĴ洢�豸�����Ǵ洢�豸��Ψһ��ʶ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddStorageDev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  STORE_DEV_INFO_S            *pstStoreDevInfo
);


/**
* �޸Ĵ洢�豸��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstStoreDevInfo     �洢�豸��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_NAME_EXIST
* - #ERR_DAO_STORAGE_ADDR_EXIST
* - #ERR_DAO_STORAGE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note �洢�豸��Ϣ�еĴ洢�豸���벻���޸�, ���޸Ĵ洢�豸��Ϣʱ��Ҫ��д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyStorageDev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  STORE_DEV_INFO_S            *pstStoreDevInfo
);


/**
* ɾ���洢�豸 \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorageDevCode    �洢�豸����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelStorageDev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szStorageDevCode[IMOS_DEVICE_CODE_LEN]
);


/**
* ɨ��洢�豸���� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorageDevCode        �洢�豸����
* @param [IN]   ulStorageDevType        �洢�豸���ͣ�ȡֵΪ#STORE_DEV_TYPE_E
* @param [OUT]  pulStoreDevTotalSize    �洢�豸������(��λ: MB)
* @param [OUT]  pulStoreDevUsedSize     �洢�豸��������(��λ: MB)
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_CODE_NOT_EXIST
* - #ERR_DAO_ISC_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ScanStorageDevSize
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStorageDevCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulStorageDevType,
    OUT ULONG_32                           *pulStoreDevTotalSize,
    OUT ULONG_32                           *pulStoreDevUsedSize
);

/* Begin: Added by luchunfeng02289, 2015-12-18 for MPPD31840 */
/**
* ɨ��ĳ���洢�豸����V2 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                        �û���Ϣ
* @param [IN]   CHAR                    szStorageDevCode[IMOS_RES_CODE_LEN]        �洢�豸����
* @param [IN]   ULONG_32                *ulStorageDevType                          �洢�豸���ͣ�ö��ֵ: STORE_DEV_TYPE_E
* @param [OUT]  CHAR                    szStoreDevTotalSize[IMOS_STRING_LEN_64]    �洢�豸������
* @param [OUT]  CHAR                    szStoreDevUsedSize[IMOS_STRING_LEN_64]     �洢�豸��������
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ScanStorageDevSizeV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szStorageDevCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulStorageDevType,
    OUT CHAR                            szStoreDevTotalSize[IMOS_STRING_LEN_64],
    OUT CHAR                            szStoreDevUsedSize[IMOS_STRING_LEN_64]
);
/* End: Added by luchunfeng02289, 2015-12-18 for MPPD31840 */

/**
* ��ҳ��ѯĳ����֯�µĴ洢�豸�б�  \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[�洢�豸����] #CODE_TYPE[����] #PHY_DEV_IP[IP��ַ])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstStoreDevList     �洢�豸�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1��szOrgCodeΪ�մ�ʱ��ʾ��ѯ��ϵͳ���еĴ洢�豸�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgStorageDevList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT STORE_DEV_QUERY_ITEM_S      *pstStoreDevList
);


/**
* ��ѯĳ���洢�豸��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorageDevCode    �洢�豸����
* @param [OUT]  pstStoreDevInfo     �洢�豸��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStorageDev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szStorageDevCode[IMOS_DEVICE_CODE_LEN],
    OUT STORE_DEV_INFO_S            *pstStoreDevInfo
);
/** @} */ /* end of DEVICE STORAGE MANAGEMENT MODULE */


#if 0
#endif
/***************************************************************************
�豸-VX500
****************************************************************************/
/**
* @name VX500����
* @{    VX500����
*/
/**
* ����VX500 \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVX500Info        VX500��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_VX500_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.VX500���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVX500Dev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  VX500_INFO_S                *pstVX500Info
);


/**
* �޸�VX500��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVX500Info        VX500��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVX500Dev
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  VX500_INFO_S                *pstVX500Info
);


/**
* ɾ��VX500 \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500�豸����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_CODE_NOT_EXIST
* - #ERR_DAO_ISC_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVX500Dev
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVX500Code[IMOS_DEVICE_CODE_LEN]
);


/**
* ��ҳ��ѯĳ����֯�µ�VX500�б�  \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[VX500����]; #NAME_TYPE(VX500����) #PHY_DEV_IP[VX500��ַ])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVX500List        VX500�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�VX500�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVX500List
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT VX500_QUERY_ITEM_S          *pstVX500List
);


/**
* ��ѯĳ��VX500��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [OUT]  pstVX500Info        VX500��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVX500Info
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szVX500Code[IMOS_DEVICE_CODE_LEN],
    OUT VX500_INFO_S                *pstVX500Info
);


/**
* ��ҳ��ѯĳ��VX500��λ�б� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVX500SlotList    VX500��λ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_VX500_DEV_NOT_ONLINE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVX500SlotList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szVX500Code[IMOS_DEVICE_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SLOT_INFO_S                 *pstVX500SlotList
);


/**
* ��Ӵ������� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [IN]   pstArrayInfo        ������Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_VX500_DEV_NOT_ONLINE
* - #ERR_MP_SS_OTHER_ARRAY_INSYNC
* - #ERR_MP_SS_ARRAY_CREATE
* - #ERR_MP_SS_ARRAY_EXIST
* - #ERR_MP_SS_DISK_NOT_FREE
* - #ERR_MP_SS_DISK_SIZE_ABNORMAL
* - #ERR_MP_SS_DISK_QUERY
* - #ERR_MP_SS_UPDATECFG_FAILED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVX500Array
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szVX500Code[IMOS_DEVICE_CODE_LEN],
    IN  ARRAY_INFO_S                *pstArrayInfo
);


/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ���ط�ҳ��Ϣ
* @param [OUT]  pstArrayList        VX500���������б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVX500ArrayList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szVX500Code[IMOS_DEVICE_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ARRAY_STATUS_INFO_S         *pstArrayList
);


/**
* ���⻯���У������з����߼��ռ� \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [IN]   szArrayName         ��������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_VX500_DEV_NOT_ONLINE
* - #ERR_MP_SS_ARRAY_HASVIRTUALIZED
* - #ERR_MP_SS_ARRAY_INITIALIZING
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_VirtualizeVX500Array
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVX500Code[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szArrayName[IMOS_NAME_LEN]
);


/**
* ɾ������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [IN]   szArrayName         ��������
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_VX500_DEV_NOT_ONLINE
* - #ERR_MP_SS_ARRAY_NOEXIST
* - #ERR_MP_SS_ARRAY_DELETE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVX500Array
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVX500Code[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szArrayName[IMOS_NAME_LEN]
);


/**
* �ؽ����У���һ�����õĲ�λ���������У�������𻵵Ĳ�λ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szVX500Code         VX500����
* @param [IN]   szArrayName         ��������
* @param [IN]   ulSlotNum           ��λ��
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_VX500_DEV_NOT_ONLINE
* - #ERR_MP_SS_ARRAY_NOEXIST
* - #ERR_MP_SS_OTHER_ARRAY_INSYNC
* - #ERR_MP_SS_DISK_NOT_FREE
* - #ERR_MP_SS_ARRAY_REBUILD
* - #ERR_MP_SS_DISK_QUERY
* - #ERR_MP_SS_DISK_SIZE_ABNORMAL
* - #ERR_MP_SS_UPDATECFG_FAILED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ReBuildVX500Array
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVX500Code[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szArrayName[IMOS_NAME_LEN],
    IN  ULONG_32                           ulSlotNum
);
/** @} */ /* end of DEVICE VX500 MANAGEMENT MODULE */


#if 0
#endif
/**************************************************************************************************************
�豸-MS
***************************************************************************************************************/
/**
* @name �豸����(MS)
* @{    MS�豸����
*/
/**
* ����MS������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKMSInfo        MS��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_MS_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     ���ز�������룬���������ļ�
* @note 1.MS��Ϣ�е�MS������MS��Ψһ��ʶ
* -     2.MS���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  MS_INFO_S                   *pstSDKMSInfo
 );


/**
* ɾ��MS \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szMSCode            MS����
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_MP_CODE_NOT_EXIST
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMSCode[IMOS_DEVICE_CODE_LEN]
);


/**
* �޸�MS��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKMSInfo        MS��Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note MS��Ϣ�е�MS���벻���޸�, ���޸�MS��Ϣ��ʱ����Ҫ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  MS_INFO_S                   *pstSDKMSInfo
);


/**
* ��ѯĳ����֯�µ�MS�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������MS,��Ĭ��"MS������������"
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode           ��֯����
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(����#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[MS����] #CODE_TYPE[MS����] #PHY_DEV_IP[MS IP])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKMSList        MS�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note 1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�MS�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMSList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MS_QUERY_ITEM_S             *pstSDKMSList
);


/**
* ��ѯMS����ϸ��Ϣ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szMSCode            MS����
* @param [OUT]  pstSDKMSInfo        MS��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMSInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szMSCode[IMOS_DEVICE_CODE_LEN],
    OUT MS_INFO_S               *pstSDKMSInfo
);
/** @} */
/** @} */ /* end of DEVICE MS MANAGEMENT MODULE */

#if 0
#endif
/*******************************************************************************
 �����������
*******************************************************************************/
/** @defgroup groupDomainMg �����
*   �����������
*   @{
*/
/**
* @name ��������
* @{    ��������
*/

/**
* ��ѯ������Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstLoDomain             ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLoDomain
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  LO_DOMAIN_S                *pstLoDomain
);



/**
* �������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstOutDomain            ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_INTERDOMAIN_LEVEL_INVALID
* - #ERR_AS_LODOMAIN_INTERINFO_NOT_EXIST
* - #ERR_AS_EXDOMAIN_LEVEL_INVALID
* - #ERR_AS_INTER_DOMAIMCODE_ALREADY_EXIST
* - #ERR_AS_INTER_USERCODE_ALREADY_EXIST
* - #ERR_DAO_DOMAIN_CODE_EXIST
* - #ERR_DAO_INTER_DOMAIN_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddExDomain
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   EX_DOMAIN_S                *pstExDomain
);



/**
* �޸�������Ϣ
* @param [IN]  pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]  pstExDomain              ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_AS_EXDOMAIN_SERVICE_FAIL
* -     ���ز�������룬���������ļ�
* @note ������Ϣ�е�������벻���޸�, ���޸�������Ϣʱ��Ҫ��д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyExDomain
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   EX_DOMAIN_S                *pstExDomain
);



/**
* ɾ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szExDomainCode          �������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_EXDOMAIN_SERVICE_FAIL
* - #ERR_DAO_INTER_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelExDomain
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szExDomainCode[IMOS_DOMAIN_CODE_LEN]
);



/**
* ��ѯ������Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szExDomainCode          �������
* @param [OUT]  pstExDomain             ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_EXDOMAIN_SERVICE_FAIL
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomain
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT  EX_DOMAIN_S                *pstExDomain
);



/**
* ��ҳ��ѯ�����б� \n
* ����Ϊ��ʱ,��ѯ��������,��Ĭ�ϰ���"������������"����.
* @param [IN]   pstUserLogIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition      ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo         ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstExDomainList        ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ְ�������롢���ơ����͡�IP���˿ڡ���������������鲥���ԡ�������־���򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:
* -   #CODE_TYPE��#NAME_TYPE��#EXT_DOMAIN_TPYE��#EXT_DOMAIN_IP��#EXT_DOMAIN_TRUNK_NUM��#EXT_DOMAIN_TRUNK_NUM��
* -   #EXT_DOMAIN_MULTICAST��#EXT_DOMAIN_SESSION;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT EX_DOMAIN_S                 *pstExDomainList
);


/**
* ���û�����Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstInterConnectInfo     ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_INTERDOMAIN_LEVEL_INVALID
* - #ERR_AS_INTERDOMAIM_PARAM_CANNOT_MODIFY
* - #ERR_AS_INTER_USERCODE_ALREADY_EXIST
* - #ERR_DAO_INTER_DOMAIN_EXIST
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻ�жԱ������û�����Ϣ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetInterconnectInfo
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   INTERCONNECT_INFO_S        *pstInterConnectInfo
);


/**
* ��ѯ������Ϣ \n
* @param [IN]   pstUserLogIDInfo                  �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode[IMOS_RES_CODE_LEN]      ������Ϣ������Դ����
* @param [IN]   ulInterInfoType                   ������Ϣ���ͣ�ȡֵΪ#INTERCONNECT_INFO_TYPE_E
* @param [IN]   ulProtocolType                    ����Э�����ͣ�ȡֵΪ#INTERDOMAIN_PROTOCOL_TYPE_E
* @param [OUT]  pstInterConnect                   ������Ϣ�ṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_INTER_DOMAIN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryInterconnectInfo
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szResCode[IMOS_RES_CODE_LEN],
    IN   ULONG_32                      ulInterInfoType,
    IN   ULONG_32                      ulProtocolType,
    OUT  INTERCONNECT_INFO_S        *pstInterConnect
);


/***************************************************************************
�������������
****************************************************************************/
/**
* @name ������������
* @{    ������������
*/
/**
* �������������, ���������ȡ������
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szExDomainCode          �������
* @param [IN]   ulShareFlag             ���������ͱ�ʶ: 0Ϊȡ������1Ϊ����
* @param [IN]   ulShareCamNum           ������ĸ���, ���ֵΪ32
* @param [IN]   pstShareCamList         ����/ȡ��������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_INTER_DOMAIN_NOT_EXIST
* - #ERR_AS_INTER_CAMCODE_ALREADY_EXIST
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessShareCamera
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                   ulShareFlag,
    IN  ULONG_32                   ulShareCamNum,
    IN  SHARE_CAMERA_BASE_S     *pstShareCamList
);


/**
* ��ҳ��ѯ�����µĹ���������б�
* ����Ϊ��ʱ,��ѯ���й��������,��Ĭ�ϰ���"�����������������"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szExDomainCode      �������
* @param [IN]   ulQueryFlag         ��ѯ���, 0Ϊ�鱾�����������������1Ϊ�������������������
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#CODE_TYPE[�������������]��#NAME_TYPE[�������������])
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstShareCamList     ����������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareCamera
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulQueryFlag,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SHARE_CAM_INFO_S            *pstShareCamList
);

/**
* ɾ�������������
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode                   ��ɾ�������������
* @param [IN]   szExdomainCode              �������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SHARE_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCameraSharedInExdomain
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szExdomainCode[IMOS_DOMAIN_CODE_LEN]
);
/** @} */ /* end of ��������� */
/** @} */ /* end of DOMAIN MANAGEMENT MODULE */

/***************************************************************************
Ԥ��λ
****************************************************************************/
/** @defgroup groupPresetMg Ԥ��λ����
*   Ԥ��λ����
*   @{
*/
/**
* ����Ԥ��λ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @param [IN]   stPreset            Ԥ��λ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_PRESET_INVALID
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_DAO_PRESET_VALUE_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPreset
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_RES_CODE_LEN],
    IN  PRESET_INFO_S           *pstPreset
);


/**
* ɾ��Ԥ��λ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ����ͷ����
* @param [IN]   ulPresetValue       Ԥ��λֵ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_DAO_PRESET_VALUE_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelPreset
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCamCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulPresetValue
);


/**
* ��ҳ��ѯ�������Ԥ��λ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstPresetList           Ԥ��λ��Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPresetList
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_RES_CODE_LEN],
    IN  QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT PRESET_INFO_S           *pstPresetList
);

/**
* ʹ��Ԥ��λ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode           ���������
* @param [IN]   ulPresetNum         Ԥ��λֵ��ȡֵ��ΧΪ#PTZ_PRESET_MINVALUE~�����������ļ������õ�Ԥ��λ���ֵ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PRESET_VALUE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UsePreset
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulPresetNum
);
/** @} */ /* end of PRESET MANAGEMENT MODULE */

#if 0
#endif
/***************************************************************************
�洢��Դ����
****************************************************************************/
/** @defgroup groupStorageResMg �洢��Դ����
*   �洢ҵ������洢��Դ����,�洢�ƻ�����
*   @{
*/
/**
* @name �洢��Դ����
* @{    �漰�洢��Դ����ɾ�Ĳ�,�Լ���ѯ�洢��Դ�б�ӿ�
*/
/**
* ����洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [IN]   pstStoreResInfo         �洢��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* - #ERR_AS_STORE_RES_ALLOCATED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  STORE_RES_INFO_S                *pstStoreResInfo
);


/*Begin: Added by mozhanfei(m01736), 2014-7-11 for PAG share store enlarge and reduce*/
/**
*��ѯPAG����洢��Դ����
*@param [IN]    pstUserLogInfo        �û���¼ID ��Ϣ��ʶ
*@param [IN]    szCamCode        ���������
*@param [IN]    szDMDevCode        DM �豸����
*@param [OUT]    pstStoreResCap        PAG����洢��Դ������Ϣ
*@return �������½��:
* �ɹ�:
* #ERR_COMMON_SUCCEED
*ʧ��:
* #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* #ERR_AS_STORE_RES_ALLOCTED
*    ���ز��������: ��������ļ�std_err.h
*@note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStoreResCap
(
    IN USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN CHAR                               szCamCode[IMOS_CODE_LEN],
    IN CHAR        szDMDevCode[IMOS_CODE_LEN],
    OUT STORE_RES_CAP_S  *pstStoreResCap
);

/**
*�޸�PAG����洢��Դ����
*@param [IN]    pstUserLogInfo        �û���¼ID ��Ϣ��ʶ
*@param [IN]    szCamCode        ���������
*@param [IN]    szDMDevCode        DM �豸����
*@param [IN]    dulAllocCap        PAG����洢��������������
*@return �������½��:
* �ɹ�:
* #ERR_COMMON_SUCCEED
*ʧ��:
* #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* #ERR_AS_STORE_RES_ALLOCTED
*    ���ز��������: ��������ļ�std_err.h
*@note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyStoreResCap
(
    IN USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN CHAR        szCamCode[IMOS_CODE_LEN],
    IN CHAR        szDMDevCode[IMOS_CODE_LEN],
    IN CHAR        szAllocCap[IMOS_NAME_LEN]
);
/*End: Added by mozhanfei(m01736), 2014-7-11 for PAG share store enlarge and reduce*/
/**
* ����洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [IN]   pstStoreResInfo         �洢��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* - #ERR_AS_STORE_RES_UNALLOCATED
* - #ERR_AS_STORE_DEV_OFFLINE
* - #ERR_MP_ISM_CAPACITY_NOT_ENOUGH
* - #ERR_DAO_CAM_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExpandStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  STORE_RES_INFO_S                *pstStoreResInfo
);


/**
* ɾ���洢��Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_STORE_RES_UNALLOCATED
* - #ERR_AS_STORE_DEV_OFFLINE
* - #ERR_DAO_CAM_CODE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN]
);


/**
* ��ѯ�洢��Դ \n
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT STORE_RES_INFO_S                *pstStoreResInfo
);


/**
* ��ҳ��ѯĳ����֯��������洢��Դ��������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��ΪNULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[���������])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstStoreResList         ������洢��Դ������Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1.����޲�ѯ����,ָ��#pstQueryCondition����ΪNULL
* - 2.���ڸշ�����Ĵ洢��Դ���ӿڷ�����Դ״̬Ϊ����������Ҫ��ʱһ��ʱ��(������)����ִ��¼��洢
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStoreResList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT STORE_RES_QUERY_ITEM_S      *pstStoreResList
);
/** @} */ /* end of name �洢��Դ���� */
#if 0
#endif
/***************************************************************************
�洢�ƻ�
****************************************************************************/
/**
* @name �洢�ƻ�����
* @{    �漰�洢�ƻ���ɾ�Ĳ�,�Լ���ѯ�洢�ƻ��б�ӿ�
*/

/**
* �޸Ĵ洢�ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorePlanCode         �洢�ƻ�����
* @param [IN]   pstStorePlan            �洢�ƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note �����洢�ƻ���Ҫ����IMOS_ProcessStorePlan�ӿ�; ��ͨ���޸ļƻ�ʱ��ķ�ʽ���ܹ��Զ�ʹ�ƻ�����/ֹͣ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyStorePlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStorePlanCode[IMOS_RES_CODE_LEN],
    IN  STORAGE_PLAN_INFO_S             *pstStorePlanInfo
);


/**
* ɾ���洢�ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorePlanCode         �洢�ƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelStorePlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStorePlanCode[IMOS_RES_CODE_LEN]
);


/**
* ��ҳ��ѯ�洢�ƻ��б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   bConditionFlag          ��ѯ������־��#BOOL_TRUEΪҪʹ��������ѯ��#BOOL_FALSEΪ����Ҫ������ѯ
* @param [IN]   pstQueryCondition       ��ѯ�����ṹָ�룺�������ƺ�ʱ��Ĳ�ѯ���������bConditionFlagΪ#BOOL_FALSEʱ������ΪNULL��
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ���ط�ҳ��Ϣ
* @param [OUT]  pstStorePlanList        �洢�ƻ��б���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStorePlanList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  BOOL_T                      bConditionFlag,
    IN  QUERY_CONDITION_INFO_S      *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT STORY_PLAN_QUERY_ITEM       *pstStorePlanList
);


/**
* ��ѯ�洢�ƻ���Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorePlanCode         �洢�ƻ�����
* @param [OUT]  pstStorePlan            �洢�ƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStorePlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStorePlanCode[IMOS_RES_CODE_LEN],
    OUT STORAGE_PLAN_INFO_S             *pstStorePlanInfo
);
/** @} */  /* �洢�ƻ����� */

/**
* ��ѯ�洢�ƻ���Ϣ, �����ԭ���ӿ�, ���Ӽƻ�����״̬�ֶ�
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szStorePlanCode         �洢�ƻ�����
* @param [OUT]  pstStorePlan            �洢�ƻ���Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStorePlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStorePlanCode[IMOS_RES_CODE_LEN],
    OUT STORAGE_PLAN_INFO_V2_S          *pstStorePlanInfo
);

/**
* @name �洢����
* @{    �洢�ƻ�������/ֹͣ���ֶ��洢������ֹͣ���ѯ
*/
/**
* ����/ֹͣ�洢�ƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szStorePlanCode         �洢�ƻ�����
* @param [IN]   ulPlanMode              �ƻ�������, #BOOL_FALSEΪֹͣ�ƻ�, #BOOL_TRUEΪ�����ƻ�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_STORAGE_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessStorePlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStorePlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulPlanMode
);


/**
* ��ʼ/�����ֶ��洢 \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [IN]   ulManualRecordMode      �ֶ��洢�����ǣ�#BOOL_FALSEΪֹͣ�ֶ��洢��#BOOL_TRUEΪ�����ֶ��洢
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* - #ERR_AS_STORE_BEING_PROCESSING
* - #ERR_DAO_TRIGGER_STORAGE_NOT_EXIST
* - #ERR_AS_MANUAL_STRORE_ALREADY_STOPED
* - #ERR_AS_STRORE_ALREADY_STARTED
* - #ERR_AS_MANUAL_STRORE_USER_UNMATCH
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessManualRecord
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulManualRecordMode
);

/**
* ��ѯ�ֶ��洢״̬��Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode            ���������
* @param [OUT]  pulManStoStatus         �ֶ��洢״̬, ȡֵΪ#MANUAL_STORE_STATUS_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_DAO_TRIGGER_STORAGE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManualStoreStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN CHAR                             szCameraCode[IMOS_RES_CODE_LEN],
    OUT ULONG_32                           *pulManStoStatus
);
/** @} */ /* �洢�������� */
/** @} */ /* end of STORAGE PLAN MANAGEMENT MODULE */

/* Begin: Added by luhaitao/01337, 2014-11-14 for ǰ��¼�� */
/**
* ��ʼ/����ǰ�˴洢
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ
* @param [IN]   szCamCode               ���������
* @param [IN]   ulFrontEndRecordMode      �ֶ��洢�����ǣ�0ֹͣ��1����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessFrontEndRecord
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulFrontEndRecordMode
);

/**
* ��ѯǰ�˴洢״̬��Ϣ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szCameraCode            ���������
* @param [OUT]  pulManStoStatus         �洢��������ö�� MANUAL_STORE_STATUS_E
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFrontEndStoreStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN CHAR                             szCameraCode[IMOS_RES_CODE_LEN],
    OUT ULONG_32                           *pulManStoStatus
);
/* End: Added by luhaitao/01337, 2014-11-14 for ǰ��¼�� */

#if 0
#endif
/***************************************************************************
������Դ����
****************************************************************************/
/** @defgroup groupSwitchResMg ���й���
*   ���й������������Դ�������мƻ���������в���
*   @{
*/
/**
* @name ������Դ����
* @{    ������Դ����
*/
/**
* ����������Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstSwitchInfo           ������Դ��Ϣ
* @param [OUT]  szSwitchResCode         ������Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARDTOUR_TIMESLOT_EXCEEDED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSwitchResource
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  SWITCH_RESOURE_S            *pstSwitchInfo,
    OUT CHAR                        szSwitchResCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�������Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchResCode         ������Դ����
* @param [IN]   pstSwitchInfo           ������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARDTOUR_TIMESLOT_EXCEEDED
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySwitchResource
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchResCode[IMOS_RES_CODE_LEN],
    IN  SWITCH_RESOURE_S                *pstSwitchInfo
);

/**
* ɾ��������Դ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchResCode         ������Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSwitchResource
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szSwitchResCode[IMOS_RES_CODE_LEN]
);


/**
* ��ѯ������Դ��Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchResCode         ������Դ����
* @param [OUT]  pstSwitchInfo           ������Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchResource
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchResCode[IMOS_RES_CODE_LEN],
    OUT SWITCH_RESOURE_S                *pstSwitchInfo
);

/**
* ��ҳ��ѯĳ����֯�µ�������Դ�б�  \n
* ����Ϊ��ʱ,��ѯ��֯������������Դ�б�,��Ĭ�ϰ���"������Դ��������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[������Դ����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSwitchResList        ������Դ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchResList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SWITCH_RES_QUERY_ITEM_S     *pstSwitchResList
);
/** @} */  //������Դ����ģ��
#if 0
#endif
/***************************************************************************
���мƻ�
****************************************************************************/
/**
* @name ���мƻ�����
* @{    ���мƻ�����
*/
/**
* �������мƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSwitchPlanInfo       ���мƻ���Ϣ
* @param [OUT]  szSwitchPlanCode        ���мƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SWITCH_PLAN_INFO_S              *pstSwitchPlanInfo,
    OUT CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);


/**
* �޸����мƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @param [IN]   pstSwitchPlanInfo       ���мƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARD_TOUR_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    IN  SWITCH_PLAN_INFO_S              *pstSwitchPlanInfo
);


/**
* ɾ�����мƻ� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARD_TOUR_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);


/**
* ��ҳ��ѯ���мƻ��б� \n
* ����Ϊ��ʱ,��ѯ�������мƻ�,��Ĭ�ϰ���"���мƻ���������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(��Ϊ#NULL;֧�ֵĲ�ѯ��������:#NAME_TYPE[���мƻ�����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSwitchPlanList       ���мƻ��б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchPlanList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SWITCH_PLAN_QUERY_ITEM_S    *pstSwitchPlanList
);


/**
* ��ѯ���мƻ���Ϣ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @param [OUT]  pstSwitchPlanInfo       ���мƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_GUARD_TOUR_PLAN_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    OUT SWITCH_PLAN_INFO_S              *pstSwitchPlanInfo
);
/** @} */  //������Դ����ģ��

/**
* @name ���в���
* @{    ���в���
*/
/**
* �����ֶ����� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchResCode         ������Դ����
* @param [IN]   szMonitorCode           Ӳ��������Ϊ����������, ���������Ϊ�������
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#USER_OPERATE_SERVICE
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_MONITOR_NOT_EXIST
* - #ERR_AS_MONITOR_OFFLINE
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartSwitchManual
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szSwitchResCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ֹͣ�ֶ����� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szMonitorCode           Ӳ��������Ϊ����������, ���������Ϊ�������
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#USER_OPERATE_SERVICE
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_MONITOR_NOT_EXIST
* - #ERR_AS_MONITOR_OFFLINE
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopSwitchManual
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ��������,�������������л�����һ������һ���������������ͣ�Լ����лָ� \n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   szMonitorCode       Ӳ��������Ϊ����������, ���������Ϊ�������
* @param [IN]   ulActionType        ��������,ȡֵΪ#CS_SWITCH_ADJUST_ACTION_E
* @param [IN]   ulOperateCode       ����ԭ����, ȡֵΪ#USER_OPERATE_SERVICE
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_CS_SWITCH_ABNORMAL_STOP
* - #ERR_CS_SWITCH_DELAY_SETUP
* - #ERR_CS_SWITCH_SUSPENDING
* - #ERR_CS_ALL_SWITCH_CAM_DELETED
* - #ERR_AS_MONITOR_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustSwitch
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulActionType,
    IN  ULONG_32                           ulOperateCode
);

/**
* ������ֹͣ���мƻ� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szSwitchPlanCode        ���мƻ�����
* @param [IN]   ulOperateCode           ����ģʽ
* @param [IN]   ulPlanMode              �ƻ������ǣ�0ֹͣ��1����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_CS_PSWITCH_NOT_EXIST
* - #ERR_CS_PLAN_SWITCH_STARTED
* - #ERR_CS_OTHER_PLANSWITCH_START
* -     ���ز�������룬���������ļ�
* @note ulPlanModeȡֵ�μ�#PLAN_OPER_MODE_E
*       ulOperateCodeȡֵ�μ�#CS_OPERATE_CODE_E
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode,
    IN  ULONG_32                           ulPlanMode
);

/** @} */ /* end of ���в���*/
/** @} */ /* end of SWITCH MODULE */

#if 0
#endif
/*******************************************************************************************************
PTZ Ctrl
********************************************************************************************************/
/** @defgroup groupPtzMg ��̨ҵ��
*   ��̨ҵ��
*   @{
*/
/**
* ����ȫ����̨�Զ��ͷŵ�ʱ��
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulReleaseTime           ��̨�Զ��ͷ�ʱ��, ȡֵΪ#MIN_PTZ_RELEASE_TIME~#MAX_PTZ_RELEASE_TIME
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_PARAM_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPtzReleaseTime
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulReleaseTime
);

/**
* ��ѯ��̨�Զ��ͷŵ�ʱ�� \n
* @param [IN]    pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [OUT]   pulReleaseTime          ��̨�Զ��ͷ�ʱ��, ȡֵΪ#MIN_PTZ_RELEASE_TIME~#MAX_PTZ_RELEASE_TIME
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPtzReleaseTime
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulReleaseTime
);


/**
* ������̨���� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPtzCtrl
(
    IN USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN CHAR                             szCamCode[IMOS_RES_CODE_LEN]
);


/**
* �ͷ���̨����Ȩ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [IN]   bReleaseSelf            �Ƿ���ͷ��û�����������̨��·, #BOOL_TRUEΪ���ͷ��û�����������·;��֮Ϊ#BOOL_FALSE
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note bReleaseSelfĿǰ����ϵͳ����Ա(admin)�����ã������û�ֻ���ͷ�����������̨��·
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ReleasePtzCtrl
(
    IN USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN CHAR                             szCamCode[IMOS_RES_CODE_LEN],
    IN BOOL_T                           bReleaseSelf
);


/**
* �û�������̨ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LockPtz
(
    IN USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN CHAR                                 szCamCode[IMOS_RES_CODE_LEN]
);


/**
* �û�������̨ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnLockPtz
(
    IN USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN CHAR                             szCamCode[IMOS_RES_CODE_LEN]
);


/**
* �û�������̨����ָ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [IN]   pstSDKPtzCtrlCommand    ��̨����ָ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1����pstSDKPtzCtrlCommand�е���̨��������1�Ͳ���2����Ϊ���������ٶ�ʱ,
* - 2�����ڳ�������ٶȵ�ֵ����Ӧ����ٶ�ֵ����
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PtzCtrlCommand
(
    IN USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN CHAR                             szCamCode[IMOS_RES_CODE_LEN],
    IN PTZ_CTRL_COMMAND_S               *pstSDKPtzCtrlCommand
);

/**
* ��ѯ��̨״̬ \n
* @param [IN]    pstUserLogIDInfo        �û���Ϣ�ṹ
* @param [IN]    szCamCode               ���������
* @param [OUT]   pulStatus               ��̨״̬,ȡֵ����Ϊ0�������״̬��1��������״̬��
                                         2������������״̬��3����״̬���ֵ��0xFFFFFFFFΪ��Чֵ
* @param [OUT]   pbQueryUserCtrl         ��ǰ��ѯ�û��ǲ��ǿ��Ƹ���̨��1�����ڿ��ƣ�0�����ڿ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPtzStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szCamCode[IMOS_RES_CODE_LEN],
    OUT ULONG_32                           *pulStatus,
    OUT BOOL_T                          *pbQueryUserCtrl
);

/** @} */ /* end of PTZ CONTROL MANAGEMENT MODULE */

#if 0
#endif
/************************************************************************************************************
�����ط�
************************************************************************************************************/
/** @defgroup groupRR �����ط�
*   �����ط�
*   @{
*/
/**
* ��ҳ����¼�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSDKRecQueryInfo      �طż�����Ϣ���ݽṹ
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSDKRecordFileInfo    ¼���ļ���Ϣ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��¼�����������ʱ���ʽΪ��"%Y-%m-%d %H:%M:%S"��ʽ ����Ϣ�����޶�Ϊ24�ַ�
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RecordRetrieval
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  REC_QUERY_INFO_S            *pstSDKRecQueryInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT RECORD_FILE_INFO_S          *pstSDKRecordFileInfo
);


/**
* ��ȡ¼���ļ���URL��Ϣ \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param[IN]    pstSDKGetUrlInfo            ��ȡ¼���ļ�URL������
* @param[OUT]   pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_LAST_QUERY_NOT_FINISH
* - #ERR_DAO_STORE_RES_NOT_EXIST
* - #ERR_AS_STORAGE_DEV_NOT_ONLINE
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetRecordFileURL
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_S              *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* @name ����¼�����
* @{    ˫ֱ��ҵ���¼���ѯ�ӿ�
*/
/**
* ������ı��ô洢¼����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
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
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SlaveRecordRetrieval
(
 IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
 IN  BOOL_T                      bExtDomainDev,
 IN  REC_QUERY_INFO_S            *pstSDKRecQueryInfo,
 IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
 OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
 OUT RECORD_FILE_INFO_S          *pstSDKRecordFileInfo
 );

/**
* ��ȡ������ı��ô洢¼���URL��Ϣ \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   bExtDomainDev               �Ƿ����������͵������
* @param[IN]    pstSDKGetUrlInfo            ��ȡURL������Ϣ���ݽṹ�����������������szCamCodeΪ������������
* @param[OUT]    pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSlaveRecordFileURL
(
 IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
 IN  BOOL_T                      bExtDomainDev,
 IN  GET_URL_INFO_S              *pstSDKGetUrlInfo,
 OUT URL_INFO_S                  *pstSDKURLInfo
 );
/** @} */

/**
* ���¼���ǩ \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param[IN]    pstSDKGetUrlInfo            ��ӱ�ǩ��Ϣ���ݽṹ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRecordTag
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ADD_TAG_INFO_S                  *pstSDKAddTagInfo
);

/**
* ɾ��¼���ǩ \n
* @param[IN]    pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param[IN]    szTagCode          ��ǩ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_LABEL_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelRecordTag
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTagCode[IMOS_RES_CODE_LEN]
);

/**
* ��ѯ¼���ǩ \n
* ����Ϊ��ʱ,��ѯ���б�ǩ,��Ĭ�ϰ���"��ǩʱ������"����.
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode        ���������
* @param [IN]   pstQueryCondition   ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo    �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo      ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTagList          ��ǩ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1. ֧�ֲ�ѯ�������ǩʱ��㡢��ǩ���ݽ��в�ѯ�����򣬶�Ӧͨ�ò�ѯ�����еĲ�ѯ�����ͷֱ�Ϊ:#LABEL_TIME��#NAME_TYPE;
* - 2. ������ǩʱ������ʼ/����ʱ��Ĳ�ѯ��#LABEL_TIME�����Բ�ѯĳ��ʱ�䣬#QUERY_CONDITION_ITEM_S��#ulLogicFlag����д
* -    �����#LOGIC_FLAG_E, ��:��ѯ��ʼ(�����)ʱ��ΪA��B�ı�ǩ����ô��ѯ��Ϊ#LABEL_TIME, ��ѯ���б��е�һ(���)����Ԫ��
* -    �в�ѯ������Ϊ������ʼ(�����)ʱ�䣬��ѯ�����߼���ϵ����Ϊ���ڵ���(��С�ڵ���)����ѯ����ΪA(��B);
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRecordTagList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TAG_QUERY_ITEM_S                *pstTagList
);

/** @} */ /* end of RECORD RETRIEVAL MANAGEMENT MODULE */

/***************************************************************************
CSҵ��
****************************************************************************/
/** @defgroup groupMonitor ʵʱ���ҵ��
*   ʵʱ���ҵ��
*   @{
*/
/**
* ��ʼʵʱ��� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode            ���������
* @param [IN]   szMonitorCode           ��Ӳ��ʵ����Ϊ����������; �����ʵ����Ϊ�������
* @param [IN]   ulStreamType            ������, ȡֵΪ#IMOS_FAVORITE_STREAM_E
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_SERVER_BUSY
* - #ERR_AS_MONITOR_NOT_EXIST
* - #ERR_AS_MONITOR_OFFLINE
* - #ERR_CS_MONITOR_IS_NOT_LOCAL_DOMAIN
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMonitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulStreamType,
    IN  ULONG_32                           ulOperateCode
);

/* Begin: Added by chenmenglin 04110, 2018-04-16 for MPPD59129 �½��ֵ�IMP������־���� */
/**
* ��ʼʵʱ���V2(������־д��tbl_operlog_inner��) \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   pstMonitorCameraInfo    ����ʵ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_SERVER_BUSY
* - #ERR_AS_MONITOR_NOT_EXIST
* - #ERR_AS_MONITOR_OFFLINE
* - #ERR_CS_MONITOR_IS_NOT_LOCAL_DOMAIN
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMonitorV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  MONITOR_CAMERA_INFO_S           *pstMonitorCameraInfo
);

/**
* ֹͣʵʱ���V2(������־д��tbl_operlog_inner��) \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   pstMonitorInfo          ֹͣʵ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopMonitorV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  MONITOR_INFO_S                  *pstMonitorInfo
);
/* End: Added by chenmenglin 04110, 2018-04-16 for MPPD59129 �½��ֵ�IMP������־���� */

/**
* ֹͣʵʱ��� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szMonitorCode           ��Ӳ��ʵ����Ϊ����������; �����ʵ����Ϊ�������
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
* @attention ���ӿ�֧�ֿ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopMonitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/// @cond
//#if defined(WIN32)
/// @endcond
/**
* ���������������\n
* @param [IN]       pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]       ulPlayWndNum        ���Ŵ�������������ȡֵ��ʵ���������
* @param [IN][OUT]  pstPlayWndInfo      ���Ŵ������ṹ��ָ�롣
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ýӿ���Windows��Linux�����о���Ч
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlayer
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN ULONG_32                    ulPlayWndNum,
    INOUT PLAY_WND_INFO_S       *pstPlayWndInfo
);


/**
* ֹͣ�����������\n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ýӿ���Windows��Linux�����о���Ч
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopPlayer
(
    IN USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo
);
/// @cond
//#endif
/// @endcond

/** @} */  //ʵʱ��ؽ���

/** @defgroup groupVoice �����Խ��������㲥
*   ��ʼ��ֹͣ˫�������Խ��������㲥����Ҫ���õ����нӿ�
*   @{
*/
/**
* ��ʼ˫�������Խ� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode            ���������
* @param [IN]   szXPVoiceTalkCode       ˫�������Խ�����
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_CS_SAME_ACTIVE_VOCTALK_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* -     ���ز�������룬���������ļ�
* @note
* - 1.szXPVoiceTalkCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartVoiceTalk
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szXPVoiceTalkCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ֹͣ˫�������Խ� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szXPVoiceTalkCode       ˫�������Խ�����
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
* - 1.szXPVoiceTalkCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopVoiceTalk
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szXPVoiceTalkCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ��ʼ�����㲥 \n
* @param [IN]       pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]       szXPVocBrdCode      �����㲥����
* @param [IN]       ulOperateCode       ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @param [IN]       ulCameraNum         ���������, ����֧��ͬʱ����#MAX_VOCBRD_CAM_NUM����������������㲥��������Щ��������붼���ڲ�ͬ��EC����������������ڱ���
* @param [IN][OUT]  pstVocBrdUnit       �����㲥��Ԫ�б�
* @return ULONG ����ֵ,�����½����
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_CS_SAME_ACTIVE_VOCTALK_EXIST
* -      ���ز�������룬���������ļ�
* @note
* - 1.szXPVocBrdCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
* - 2.����������������Ͽ�ʼ�����㲥��ʧ��ʱ, �ýӿڷ���ʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartVoiceBroadcast
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN      CHAR                            szXPVocBrdCode[IMOS_RES_CODE_LEN],
    IN      ULONG_32                           ulOperateCode,
    IN      ULONG_32                           ulCameraNum,
    INOUT   VOC_BRD_UNIT_S                  *pstVocBrdUnit
);

/**
* ֹͣ�����㲥 \n
* @param [IN]       pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]       szXPVocBrdCode      �����㲥����
* @param [IN]       ulOperateCode       ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @param [IN]       ulCameraNum         ���������, ���ֵΪ#MAX_VOCBRD_CAM_NUM
* @param [IN][OUT]  pstVocBrdUnit       �����㲥��Ԫ�б�
* @return ULONG ����ֵ,�����½����
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* -      ���ز�������룬���������ļ�
* @note
* - 1.�����㲥��Ԫ�б���Ϊ���ʱ��������㲥״̬����������Ʋ��Ǳ�����д�ģ�ֻҪ�����������Ϳ���
* - 2.szXPVocBrdCode�ݲ�ʹ��, ����Ϊ�մ�, ������Ϊ��ָ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopVoiceBroadcast
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN      CHAR                            szXPVocBrdCode[IMOS_RES_CODE_LEN],
    IN      ULONG_32                           ulOperateCode,
    IN      ULONG_32                           ulCameraNum,
    INOUT   VOC_BRD_UNIT_S                  *pstVocBrdUnit
);


/** @} */ /* end of CS SERVICES MANAGEMENT MODULE */

#if 0
#endif

/***************************************************************************
����XPʵʱ�������Ϣ�ӿ�
****************************************************************************/
/**
* @name ����XPʵʱ�������Ϣ�ӿڹ���
* @{    ����XPʵʱ�������Ϣ�ӿڹ���
*/

/**
* ����XPʵʱ�������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstXpStreamInfo     XPʵʱ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigXpStreamInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  XP_STREAM_INFO_S                *pstXpStreamInfo
);

/**
* ��ѯXPʵʱ�������Ϣ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstXpStreamInfo     XPʵʱ�������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryXpStreamInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT XP_STREAM_INFO_S                *pstXpStreamInfo
);

/** @} */ /* end of XP STREAM MANAGEMENT MODULE */

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
* IMOS�û���������㷨\n
* @param [IN]   pcInput     ��������������
* @param [IN]   ulInlen     ���������ݳ���
* @param [OUT]  szOutput    ���ܺ�����ݻ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Encrypt
(
    IN const CHAR *pcInput,
    IN ULONG_32 ulInLen,
    OUT CHAR szOutput[IMOS_PASSWD_ENCRYPT_LEN]
);

/**
* ��ѯ�豸״̬ \n
* @param [IN]       pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       ulDevNum                �����ѯ���豸����
* @param [IN][OUT]  pstDevStatusList        �豸״̬�б���������豸���룬
*                                           ���η��ض�Ӧ���豸���ͼ��豸״̬
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevStatus
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    ULONG_32                          ulDevNum,
    INOUT DEV_STATUS_INFO_S              *pstDevStatusList
);

/**
* ע��������Ϣ����Ļص������� \n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN] pfnCallBackProc       �ص�������ָ��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RegCallBackPrcFunc
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN CALL_BACK_PROC_PF        pfnCallBackProc
);

/**
* �����ṩע��������Ϣ����Ļص������� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       �û���¼��Ϣ
* @param [IN]   CALL_BACK_PROC_PF       pfnCallBackProc         �ص���������ָ��
* @return ULONG  �������½��:
* - �ɹ���#ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ���
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RegCallBackPrcFuncEx
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN CALL_BACK_PROC_EX_PF        pfnCallBackProc
);

#if 0
#endif
/**
* ����ѡ��,������"CC�ķ�������ַ" \n
* @param [IN]   ulOptionName    ѡ����(ȡֵΪ#OPTION_NAME_E)
* @param [IN]   pOption         ѡ��ֵָ��
* @param [IN]   ulBufferLen     ѡ��ֵ�ڴ�鳤��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. ͨ�ýӿ�,һ�ε�������һ������
* - 2. ���õ����ͺ�ƥ���pOption��#OPTION_NAME_E;
* - 3. ����������#OPTION_IMOS_ROOT_PATHʱ��������SDK��ʼ������֮ǰ���øú�����
*      ���pOptionΪNULL��������Ϊ��ǰ���ص�SDK���ļ�����Ŀ¼��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetOption
(
     IN ULONG_32    ulOptionName,
     IN VOID     *pOption,
     IN ULONG_32    ulBufferLen
 );

/**
* ����DC VGA���ͨ��ģʽ
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szScrCode           ����������
* @param [IN]   pstOutChannelInfo   ���ͨ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DEVICE_OFFLINE
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigScreenOutMode
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szScrCode[IMOS_CODE_LEN],
    IN  OUT_CHANNEL_INFO_S      *pstOutChannelInfo
);

/**
* ��ѯDC���ͨ���ķ�����Ϣ.
* @param [IN]  pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]  szDcCode           DC����
* @param [IN]  ulOutChannelType   ���ͨ������,ȡֵΪ#OUT_CHANNEL_TYPE_E
* @param [OUT] pstOutSplitScrInfo ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_DEVICE_OFFLINE
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenOutMode
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szDcCode[IMOS_CODE_LEN],
    IN  ULONG_32                        ulOutChannelType,
    OUT OUT_CHANNEL_SPLIT_SCR_INFO_S *pstOutSplitScrInfo
);

/** @} */ /* end of ADDITIONAL MODULE */

#if 0
#endif
/**************************************************************************************************************
LICENCE
***************************************************************************************************************/
/**
* @name LICENCE����
* @{    LICENCE����
*/
/**
* �ϴ�license�ļ�ʱ����ȡFTP�������û��������Լ��ļ����·�� \n
* @param [IN]   pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [OUT]  pstFtpInfo         FTP������Ϣ
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUploadLicenseFTPInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT FTP_INFO_S                  *pstFtpInfo
);


/**
* ���ϴ�license�ļ��Ľ����֪ͨ������ \n
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   bIsSuccess          �ϴ��ļ��Ľ����#BOOL_TRUEΪ�ɹ�, #BOOL_FALSEΪʧ��
* @param [IN]   szLicenseFileName   license�ļ���
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_UPLOAD_LICENSE_FILE_FAIL
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_NotifyUpLoadLicenseResult
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  BOOL_T                          bIsSuccess,
    IN  CHAR                            szLicenseFileName[IMOS_FILE_PATH_LEN]
);

/** @} */ /* end of LICENSE MODULE */

#if 0
#endif
/*************************************************************************************
����ʾ���ã��������ӣ��޸ģ�ɾ������ѯ����ѯ�б�
***************************************************************************************/
/** @defgroup groupSalvo ����ʾ����
*   �������ӡ�ɾ�����޸ġ���ѯ(�б�)����ͣ�ȹ���
*   @{
*/

/**
* ��������ʾ \n
* @param [IN]       pstUserLogIDInfo        �û���Ϣ
* @param [IN]       szOrgCode               ��֯����
* @param [IN][OUT]  pstSalvoInfo            ����ʾ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ����ʾ��Ϣ������ʾ�������Ϊ��;����ε�����ʾ����Ϊ��, ��Я�����ڲ����ɵ�����ʾ����)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSalvo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    INOUT   SALVO_INFO_S                *pstSalvoInfo
);

/**
* �޸�����ʾ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstSalvoInfo            ����ʾ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySalvo
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN   SALVO_INFO_S               *pstSalvoInfo
);


/**
* ɾ������ʾ
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szSalvoCode             ����ʾ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSalvo
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSalvoCode[IMOS_CODE_LEN]
);

/**
* ��ѯ����ʾ��Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szSalvoCode             ����ʾ����
* @param [OUT]  pstSalvoInfo            ����ʾ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySalvo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSalvoCode[IMOS_CODE_LEN],
    OUT SALVO_INFO_S                    *pstSalvoInfo
);

/**
* ��ҳ��ѯĳ����֯�µ�����ʾ�б�  \n
* ����Ϊ��ʱ,��ѯ��֯����������ʾ�б�,��Ĭ�ϰ���"����ʾ��������"����.
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* - ����NULL
* - ��������:#NAME_TYPE(����ʾ����),#RES_SUB_TYPE(����ʾ���ͣ�ȡֵ#SALVO_TYPE_E)
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstSalvoList            ����ʾ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySalvoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SALVO_QUERY_ITEM_S          *pstSalvoList
);

/**
* ��������ʾ \n
* @param [IN]   pstUserLoginIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   szSalvoCode                 ����ʾ����
* @param [IN]   ulStreamType                ������, ȡֵΪ#IMOS_FAVORITE_STREAM_E
* @param [IN]   ulOperateCode               ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @param [IN]   ulSrcHandle                 ��������ʾԴ���
* @param [IN]   ulMsgSequence               ��Ϣ���к�
* @param [OUT]  pulSalvoUnitNum             ����ʾ��Ԫ��Ŀ
* @param [OUT]  pstSalvoUnitList            ����ʾ��Ԫ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �ֶ���������ʾ��ʹ��ulSrcHandle, ������Чֵ#IMOS_INVALID_HANDLE;
        �ֶ���������ʾ��ʹ��ulMsgSequence, ������Чֵ0;
*       ����Ѳ��������ʾʱulSrcHandle��Ч, ��д����Ѳ�ϱ���Ϣ��Я����Դ���;
        ����Ѳ��������ʾʱulMsgSequence��Ч, ��д����Ѳ�ϱ���ϢЯ������Ϣ���к�
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartSalvo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szSalvoCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulStreamType,
    IN  ULONG_32                       ulOperateCode,
    IN  ULONG_32                       ulSrcHandle,
    IN  ULONG_32                       ulMsgSequence,
    OUT ULONG_32                       *pulSalvoUnitNum,
    OUT CS_SALVO_START_SALVO_UNIT_S *pstSalvoUnitList
);

/**
* ֹͣ����ʾ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szSalvoCode             ����ʾ����
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopSalvo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szSalvoCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulOperateCode
);

/** @} */ /* end of groupSalvo*/

#if 0
#endif

/*************************************************************************************
ͨ��������Դ���ã��������ӣ��޸ģ�ɾ������ѯ����ѯ�б�
***************************************************************************************/
/** @defgroup groupCSwitchRes ���й���
*   ���� ���ӡ��޸ġ�ɾ������ѯ����ѯ�б�����Ѳ�Ĺ���
*   @{
*/

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
* @note Ŀǰֻ֧������Ѳ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommonSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_SWITCH_RESOURCE_S    *pstSwitchInfo,
    OUT CHAR                        szSwitchResCode[IMOS_RES_CODE_LEN]
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommonSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szSwitchResCode[IMOS_RES_CODE_LEN],
    IN  COMMON_SWITCH_RESOURCE_S    *pstSwitchInfo
);

/**
* ɾ��ͨ��������Դ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulSwitchType            �������ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E
* @param [IN]   szSwitchResCode         ͨ��������Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCommonSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ULONG_32                   ulSwitchType,
    IN  CHAR                    szSwitchResCode[IMOS_RES_CODE_LEN]
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulSwitchType,
    IN  CHAR                            szSwitchResCode[IMOS_RES_CODE_LEN],
    OUT COMMON_SWITCH_RESOURCE_S        *pstSwitchInfo
);

/**
* ��ҳ��ѯĳ����֯�µ�ͨ��������Դ�б�  \n
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
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchResList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  ULONG_32                       ulSwitchType,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SWITCH_RES_QUERY_ITEM_S     *pstSwitchResList
);

/**
* ����/ֹͣ/ǰ��/����/�ָ�/��ͣ����Ѳ \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szGroupsalvoCode        ����Ѳ����
* @param [IN]   ulProcessType           ��������: ����/ֹͣ/ǰ��/����/�ָ�/��ͣ #MANUAL_OPER_TYPE_E
* @param [IN]   ulOperateCode           ����ԭ����: #CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessGroupsalvo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szGroupsalvoCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulProcessType,
    IN  ULONG_32                   ulOperateCode
);

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
* ��¼���ݿ������־ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstOperLogInfo          ��־��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOperLogForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  SDK_OPER_LOG_INFO_FOR_ECR_S           *pstOperLogInfo
);
/* End Added by lw0581,2013-11-6 for  VVD06374*/
/* Begin Added by lw0581,2013-11-12 for  VVD05864*/
/**
* ����TMS \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTMSInfo              TMS��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMSForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_INFO_FOR_ECR_S                      *pstTMSInfo
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
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMSForECR
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
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMSForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_INFO_FOR_ECR_S                      *pstTMSInfo
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
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN],
    OUT  TMS_INFO_FOR_ECR_S                     *pstTMSInfo
);

/**
* �޸�ͼƬ�ϳɷ�ʽ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCompositeInfo        ͼƬ�ϳɷ�ʽ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyPicCompositeTypeForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  PIC_COM_INFO_FOR_ECR_S                  *pstCompositeInfo
);

/**
* ��ѯͼƬ�ϳɷ�ʽ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [OUT]  pstCompositeInfo              ͼƬ�ϳɷ�ʽ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPicCompositeTypeForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_CODE_LEN],
    OUT  PIC_COM_INFO_FOR_ECR_S                 *pstCompositeInfo
);


/**
* �޸Ŀ���ͼƬOSD ���ӷ�ʽ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCompositeInfo        OSD ���ӷ�ʽ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOSDSpliceForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  PIC_OSD_SPLICE_INFO_FOR_ECR_S           *pstPicOSDSpliceInfo
);

/**
* ��ѯ����ͼƬOSD ���ӷ�ʽ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode               ���������
* @param [OUT]  pstPicOSDSpliceInfo     OSD ���ӷ�ʽ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. �ýӿڽ�֧��ECR�豸
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOSDSpliceForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_CODE_LEN],
    OUT  PIC_OSD_SPLICE_INFO_FOR_ECR_S          *pstPicOSDSpliceInfo
);
/* End Added by lw0581,2013-11-12 for  VVD05864*/
/** @} */ /* end of groupCSwitchRes*/

/* Begin Add by zhouquanwei/z01364 2013-11-08 of onvif֧�ֶ�profile */
/**
* ��ѯ�����������������
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOnvifCode         Onvif���������
* @param [OUT]  pstOnvifStreamCFG   Onvif�����������
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyIPCStreamCFG
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szThirdPartyIPCCode[IMOS_CODE_LEN],
    OUT THIRD_PARTY_IPC_STREAM_CFGS_S     *pstThirdPartyIPCStreamCFG
);

/**
* ��������������������
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   pstOnvifStreamCFG   Onvif�����������
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetThirdPartyIPCStreamCFG
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  THIRD_PARTY_IPC_STREAM_CFGS_S     *pstThirdPartyIPCStreamCFG
);

/**
* ��ѯ����Onvif�����profile
* @param [IN]   pstUserLogIDInfo    �û���¼ID��Ϣ��ʶ
* @param [IN]   szOnvifCode         Onvif���������
* @param [OUT]  pstOnvifProfiles    Onvif���������profile
* @return ULONG �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifProfile
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szOnvifCode[IMOS_CODE_LEN],
    OUT ONVIF_PROFILES_S        *pstOnvifProfiles
);
/* End Add by zhouquanwei/z01364 2013-11-08 of onvif֧�ֶ�profile */



/**��ѯĳ���豸����Ϣ
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szDevCode                   �豸�ı���
* @param [IN]   ulQueryType                 ��ѯ����
* @param [OUT]  szQueryResult               �豸��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevInfoByQueryType
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo,
    IN   CHAR                           szDevCode[IMOS_CODE_LEN],
    IN   ULONG_32                       ulQueryType,
    OUT  CHAR                           szQueryResult[IMOS_STRING_LEN_2048]

);
/* End Add by xuzhilang/w0995 2014-7-28 of ��ѯͨ���豸��Ϣ�ӿ� */

/**
* �޸������ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstCamInfo                  �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCameraV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_INFO_V2_S                   *pstCamInfo
);


/**
* ��ѯ�������Ϣ \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szCamCode                   ���������
* @param [OUT]  pstCameraInfo               �������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT CAMERA_INFO_V2_S                   *pstCameraInfo
);
/** ���VOD������������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   VOD_INFO_S               *pstSDKVODInfo           VOD��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.VOD��Ϣ�е�VOD������VOD��Ψһ��ʶ
* -     2.VOD���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVOD
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  VOD_INFO_S                   *pstSDKVODInfo
);


/**
* ɾ��VOD \n
* @param [IN]   USER_LOGIN_ID_INFO_S    pstUserLoginIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   CHAR                    szVODCode[IMOS_DEVICE_CODE_LEN]  VOD����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֻ��һ����ɾ��VOD������ɾ��VOD�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVOD
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szVODCode[IMOS_DEVICE_CODE_LEN]
);

/**
* �޸�VOD�����벻���޸ģ�������Ҫ���� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ
* @param [IN]   VOD_INFO_S               *pstSDKMSInfo           VOD��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVOD
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  VOD_INFO_S                   *pstSDKVODInfo
);


/**
* ��ѯĳ����֯�µ�VOD�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CHAR                        szOrgCode               ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:NAME_TYPE[MS����])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  VOD_QUERY_ITEM_S             *pstSDKVODList           VOD�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�VOD�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVODList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT VOD_QUERY_ITEM_S             *pstSDKVODList
);


/**
* ��ѯĳ��VOD�ľ�����Ϣ
* @param [IN]    USER_LOGIN_ID_INFO_S   pstUserLoginIDInfo                �û���¼��Ϣ
* @param [IN]    CHAR                   szVODCode[IMOS_DEVICE_CODE_LEN]  VOD����
* @param [OUT]   VOD_INFO_S              *pstSDKVODInfo                   VOD��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVODInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szVODCode[IMOS_DEVICE_CODE_LEN],
    OUT VOD_INFO_S               *pstSDKVODInfo
);

/* Begin: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */
/**
* ���CDS������������������Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CDS_INFO_S              *pstSDKCDSInfo             CDS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note 1.DM��Ϣ�е�DM������DM��������Ψһ��ʶ
* -     2.DM���벻�����,�Ҳ��ܰ����ո�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCDS
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN CDS_INFO_S                   *pstSDKCDSInfo
);

/**
* �޸�CDS�����벻���޸ģ�������Ҫ���� \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CDS_INFO_S               *pstSDKCDSInfo           CDS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ��ERR_COMMON_SUCCEED?
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCDS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CDS_INFO_S                  *pstSDKCDSInfo
);

/**
* ɾ��CDSϵͳ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                   �û���Ϣ
* @param [IN]   CHAR                    szCDSCode[IMOS_DEVICE_CODE_LEN]       CDS����
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֻ��һ����ɾ��CDS������ɾ��CDS�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCDS
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN CHAR                         szCDSCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ��ѯĳ����֯�µ�CDS�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CHAR                        szOrgCode               ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[CDS����])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         ���ط�ҳ��Ϣ
* @param [OUT]  CDS_QUERY_ITEM_S            *pstSDKCDSList          CDS�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note  1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���е�CDS�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDSList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CDS_QUERY_ITEM_S             *pstSDKCDSList
);

/* Begin: Deleted by liguideng/l04215, 2018-03-07 for MPPD53855, �ýӿ�ֻ����δ���� */
#if 0
/**
* ��ѯĳ����֯�µ����д洢�豸�б�  \n
* Ŀǰֻ֧����֯����szOrgCode����Ϊ�մ��Ĳ�ѯ��
* ����Ϊ��ʱ,������,��Ĭ��"������������"
* @param [IN]   USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo       �û���Ϣ
* @param [IN]   CHAR                          szOrgCode                 ��֯����
* @param [IN]   COMMON_QUERY_CONDITION_S      *pstQueryCondition        ͨ�ò�ѯ����(����NULL;��������:#NAME_TYPE[�豸����])
* @param [IN]   QUERY_PAGE_INFO_S             *pstQueryPageInfo         �����ҳ��Ϣ
* @param [OUT]  RSP_PAGE_INFO_S               *pstRspPageInfo           ���ط�ҳ��Ϣ
* @param [OUT]  ALL_STORAGE_DEV_QUERY_ITEM_S  *pstSDKAllStorageDevList  ���д洢�豸�б�
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note  1��szOrgCode����Ϊ�մ�����ʾ��ѯ��ϵͳ���д洢�豸�б�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllStorageDevList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT ALL_STORAGE_DEV_QUERY_ITEM_S  *pstSDKAllStorageDevList
);
#endif
/* End: Deleted by liguideng/l04215, 2018-03-07 for MPPD53855, �ýӿ�ֻ����δ���� */

/**
* ��ѯĳ��CDS�ľ�����Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                  �û���Ϣ
* @param [IN]   CHAR                    szCDSCode[IMOS_DEVICE_CODE_LEN]      CDS����
* @param [OUT]  CDS_INFO_S              *pstSDKCDSInfo                       CDS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDSInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szCDSCode[IMOS_DEVICE_CODE_LEN],
    OUT CDS_INFO_S                  *pstSDKCDSInfo
);

/* End: Added by zhongke, 2015-03-02 for CDS�ƴ洢 */

/* Begin add by liujian/02319, 2016-09-08 for ¼���������  */
/**
* ��ѯĳ��CDS����Ϣ \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                  �û���Ϣ
* @param [IN]   CHAR                    szCameraCode[IMOS_DEVICE_CODE_LEN]      ���������
* @param [OUT]  CDS_INFO_V2_S              *pstCDSInfo                       CDS��Ϣ
* @return ULONG_32 �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCDSInfoV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szCameraCode[IMOS_DEVICE_CODE_LEN],
    OUT CDS_INFO_V2_S                  *pstCDSInfo
);
/* End add by liujian/02319, 2016-09-08 for ¼���������  */

/* Begin: Added by luhaitao/01337, 2015-05-21 for ONVIF��NVR */
/**
* ��ӵ�����NVR����ͨ��Ϊ��ͨ���豸 \n
* @param [IN]   pstUserLoginIDInfo   �û���Ϣ
* @param [IN]   pstThirdPartyNVR     ������NVR��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddThirdPartyNVR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  THIRDPARTY_NVR_S        *pstThirdPartyNVR
);

/**
* ɾ��������NVR \n
* @param [IN]   pstUserLoginIDInfo   �û���Ϣ
* @param [IN]   szDevCode            �豸����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelThirdPartyNVR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN]
);

/**
* ���µ�����NVR��Ϣ \n
* @param [IN]   pstUserLoginIDInfo   �û���Ϣ
* @param [IN]   pstThirdPartyNVR     ������NVR��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateThirdPartyNVR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  THIRDPARTY_NVR_S        *pstThirdPartyNVR
);

/**
* ��ѯ������NVR��Ϣ \n
* @param [IN]   pstUserLoginIDInfo   �û���Ϣ
* @param [IN]   szDevCode            �豸����
* @param [OUT]  pstThirdPartyNVR     ������NVR��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyNVR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT THIRDPARTY_NVR_S        *pstThirdPartyNVR
);

/**
* ��ѯ������NVR��Ϣ�б�����ԭ˽��Э��NVR��ѯ
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryCondition           ��ѯ��Ϣ����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstEcList                   �������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyNVRList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT NVR_QRY_ITME_INFO_S             *pstThirdPartyNVRList
);

/**
* ��ѯ������EC�б����ݸ��豸����
* �����ѯ����ʱ,������,Ĭ������(EC��������)
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDevCode                   �豸����
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����(��ΪNULL, ��������: #NAME_TYPE[IPC����];)
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstThirdPartyIPCInfoList    ������IPC�б�
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�

* @note
* - 1. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyECListByParDev
(
    IN    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN    CHAR                     szDevCode[IMOS_CODE_LEN],
    IN    COMMON_QUERY_CONDITION_S *pstQueryCondition,
    IN    QUERY_PAGE_INFO_S        *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S          *pstRspPageInfo,
    OUT   THIRDPARTY_EC_S          *pstThirdPartyIPCInfoList
);

/* End: Added by luhaitao/01337, 2015-05-21 for ONVIF��NVR */

#if 0
#endif

/**
* ��ȫ��������
* @param [IN]       pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       pstSetSecurityCodeInfo    ��ȫ������Ϣ(����)
                                              note:�ɵ��÷���֤�����ʽ��ȷ��Ϊǿ���룬ÿ�����볤�����Ϊ16�ֽ�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSecurityCode
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN    IMOS_SET_SECU_CODE_INFO_S   *pstSetSecurityCodeInfo
);

/* Begin added by zW4385 for MPPD32215  VM ��ȫ���������볤����16��Ϊ64λ */
/**
* ��ȫ��������
* @param [IN]       pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]       pstSetSecurityCodeInfo    ��ȫ������Ϣ(����)
                                              note:�ɵ��÷���֤�����ʽ��ȷ��Ϊǿ���룬ÿ�����볤�����Ϊ16�ֽ�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSecurityCode_V2
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo,
    IN    IMOS_SET_SECU_CODE_INFO_V2_S   *pstSetSecurityCodeInfo
);
/* End added by zW4385 for MPPD32215  VM ��ȫ���������볤����16��Ϊ64λ */

/**
* ��ȫ�����ѯ
* @param [IN]       pstUserLoginIDInfo          �û���¼ID��Ϣ��ʶ
* @param [INOUT]       pstQrySecurityCodeInfo   ��ѯ���İ�ȫ������Ϣ(���ܺ�)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySecurityCode
(
    IN       USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    INOUT    IMOS_QRY_SECU_CODE_INFO_S   *pstQrySecurityCodeInfo
);

/**
* �����ж�
* @param [IN]       pstUserLoginIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]       pstCheckIPSegmentInfo   ��Ҫ�жϵ�ip��ַ��Ϣ
* @param [INOUT]    pbIsSameSegment         �Ƿ��������ipͬһ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckIPSegment
(
    IN       IMOS_CHECK_IP_SEGM_INFO_S   *pstCheckIPSegmentInfo,
    OUT      BOOL_T     *pbIsSameSegment
);

/**
* ��Ӱ�ȫ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSafeNetSegment           ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSafeNetSegment
(
    IN    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN    SAFE_NET_SEGM_S          *pstSafeNetSegment
);

/**
* ɾ����ȫ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstSafeNetSegment           ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteSafeNetSegment
(
    IN    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN    SAFE_NET_SEGM_S          *pstSafeNetSegment
);

/**
* ��ѯ��ȫ����
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [OUT]   pstSafeNetSegmList         ��ȫ������Ϣ�б�
* @param [OUT]   pulQueryNetSegmNum         ʵ�ʲ�ѯ�������θ���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySafeNetSegment
(
    IN    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    OUT   SAFE_NET_SEGM_S   *pstSafeNetSegmList,
    OUT   ULONG_32  *pulQueryNetSegmNum
);


/**
* ��ȡ����������Ϣ \n
* ������ϸ˵��
* @param[IN]    pstUserLogIDInfo    �û���Ϣ
* @param[OUT]   pulNetworkMode       ���繤��ģʽ����Ӧö�� NET_WORK_MODE_TYPE_E
* @param[OUT]   pstDNSInfo          DNS ��Ϣ
* @param[OUT]   pulDefaultNICIndex   Ĭ������(·��)���
* @param[OUT]   pulNICNumber         ��ģʽ����������
* @param[OUT]   astNicInfo          �������������
* @return       ERR_COMMON_SUCCEED  ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetNetworkInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT ULONG_32       *pulNetworkMode,
    OUT DNS_INFO_S  *pstDNSInfo,
    OUT ULONG_32       *pulDefaultNICIndex,
    OUT ULONG_32       *pulNICNumber,
    OUT NIC_INFO_S  astNicInfo[NIC_COUNT_MAX]
);

/**
* ��ȡ����������Ϣ \n
* ������ϸ˵��
* @param[IN]    pstUserLogIDInfo        �û���Ϣ
* @param[IN]    *pulNetworkMode         ���繤��ģʽ����Ӧö�� NET_WORK_MODE_TYPE_E
* @param[IN]    pstDNSInfo              DNS ��Ϣ
* @param[IN]    *pulDefaultNICIndex     Ĭ������(·��)���
* @param[IN]    *pulNICNumber           ��ģʽ����������
* @param[IN]    astNicInfo              �������������
* @return       ERR_COMMON_SUCCEED  ��ʾ�ɹ���ʧ�ܷ������������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetNetworkInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32       ulNetworkMode,
    IN  DNS_INFO_S  *pstDNSInfo,
    IN  ULONG_32       ulDefaultNICIndex,
    IN  ULONG_32       ulNICNumber,
    IN  NIC_INFO_S  astNicInfo[NIC_COUNT_MAX]
);
/** @defgroup groupDepart ���Ź���
*   ���ŵ�����ɾ���ġ���
*   @{
*/
/**
* ��Ӳ�����Ϣ \n
* @param [IN]       USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   �û���Ϣ
* @param [IN]       CHAR                    szOrgCode           �������������ű���
* @param [IN][OUT]  DEPT_INFO_S             *pstDeptInfo        ������Ϣ(INʱ,���ű������Ϊ��;���Ϊ��,��OUT���ű���)
* @return ULONG �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT  ULONG_32 STDCALL IMOS_AddDepartment
(
    IN      USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN      CHAR                   szParDeptCode[IMOS_CODE_LEN],
    INOUT   DEPT_INFO_S            *pstDeptInfo
);

/**
* �޸Ĳ���
* @param [IN]   pstUserLogIDInfo       �û���Ϣ
* @param [IN]   pstDeptInfo            ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDepartment
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   DEPT_INFO_S                *pstDeptInfo
);

/**
* ɾ������
* @param [IN]   pstUserLogIDInfo        �û���Ϣ
* @param [IN]   szDeptCode              ���ű���
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDepartMent
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szDeptCode[IMOS_CODE_LEN]
);

/**
* ��ѯ������Ϣ
* @param [IN]   pstUserLogIDInfo     �û���Ϣ
* @param [IN]   szDeptCode           ���ű���
* @param [OUT]  pstDeptInfo          ������Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDepartment
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szDeptCode[IMOS_CODE_LEN],
    OUT  DEPT_INFO_S                *pstDeptInfo
);

/**
* ��ѯ�����µ��Ӳ����б�
* @param [IN]   pstUserLogIDInfo           �û���¼ID��Ϣ��ʶ
* @param [IN]   szDeptCode                 ���ű���
* @param [IN]   pstQueryCondition          ��ѯ����
* @param [IN]   pstQueryPageInfo           �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo             ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDeptList                ������Ϣ�б�
* @return ULONG �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_DEPT_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note
* - ����
* - 1.��������ΪNULL,��ʾ��ָ�����������в�����Ϣ
* - ����
* - 1.��ָ���������������,Ĭ�ϰ�"��������"��������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeptList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDeptCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT DEPT_INFO_S                     *pstDeptList
);
/** @} */ /* end of MG Module */

/* Begin: Added by luchunfeng02289, 2016-04-07 for �������豸���� */
/**
* ����������豸
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstIOTInfo                �������豸��Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIOT
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  IOT_INFO_S                   *pstIOTInfo
);

/**
* ɾ���������豸
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   szIOTCode                 �������豸����
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIOT
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DEVICE_CODE_LEN]
);

/**
* �޸��������豸
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   pstIOTInfo                �������豸��Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyIOT
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  IOT_INFO_S                   *pstIOTInfo
);

/**
* ��ѯ�������豸��Ϣ
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ��ʶ
* @param [IN]   szIOTCode                 �������豸����
* @param [OUT]  pstIOTInfo                �������豸��Ϣ
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTInfo
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DEVICE_CODE_LEN],
    OUT IOT_INFO_S                   *pstIOTInfo
);

/**
* ��ѯĳ����֯���������豸�б�
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryCondition           ͨ�ò�ѯ����(��ΪNULL)
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstIOTList                  �������豸�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_QUERY_ITEM_S             *pstIOTList
);

/**
* ��ѯĳ���������豸�����͵���Դ
* @param [IN]   pstUserLoginIDInfo          �û���Ϣ��ʶ
* @param [IN]   szOrgCode                   ��֯����
* @param [IN]   pstQueryPageInfo            �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo              ���ط�ҳ��Ϣ
* @param [OUT]  pstIOTResList               �������豸������Դ�б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTRecourseList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_RES_QUERY_ITEM_S         *pstIOTResList
);

/* End: Added by luchunfeng02289, 2016-04-07 for �������豸���� */

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
* ��ѯӲ��������Ϣ
* @param [IN]      USER_LOGIN_ID_INFO_S *pstUserLogIDInfo      �û���¼ID��Ϣ��ʶ
* @param [OUT]   DEV_DISK_CAPACITY_MSG_S    *pstDevDiskCapacityMsg            Ӳ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룺��������ļ�sdk_err.h
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDiskCapacity
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  DEV_DISK_CAPACITY_S    *pstDevDiskCapacity
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

/*Begin added by h02674 2016-07-08 for ��GBǿ�ƹؼ�֡�·�MPPD42024*/
/**
* GB������·�ǿ�ƹؼ�֡
* @param [IN]   pstUserLoginIDInfo        �û���Ϣ�ṹ
* @param [IN]   szCamCode           ���������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendKeyFrame
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CAM_INFO_S                           *pstCamInfo
);
/*End added by h02674 2016-07-08 for ��GBǿ�ƹؼ�֡�·�MPPD42024*/


#if 0
#endif

/* Begin add by liujian/02319, 2016-12-09 for MPPD43569 */
/**
* ��ʱ�俪ʼ����   \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szCameraCode            ���������
* @param [IN]   pstDownloadInfo         ������Ϣ
* @param [OUT]  szDownloadCode          ����ͨ�����б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬��������Ĵ������ļ�
* @note ��
*/
IMOS_EXPORT ULONG STDCALL IMOS_StartDownloadByTime
(
    IN const USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN const CHAR                   szCameraCode[IMOS_RES_CODE_LEN],
    IN const SDK_DOWNLOAD_INFO_S    *pstDownloadInfo,
    OUT CHAR                        szDownloadCode[IMOS_RES_CODE_LEN]
);

/**
* ֹͣ��ʱ������   \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]  szDownloadCode          ����ͨ�����б�
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬��������Ĵ������ļ�
* @note ��
*/
IMOS_EXPORT ULONG STDCALL IMOS_StopDownloadByTime
(
    IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
    IN const CHAR                 szDownloadCode[IMOS_RES_CODE_LEN]
);

/**
* ��ʱ�俪ʼ�㲥�ط�    \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szCameraCode            ���������
* @param [IN]   szChannelCode           ͨ������
* @param [IN]   pstVodInfo              �㲥�ط���Ϣ�ṹ��
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬��������Ĵ������ļ�
* @note ��
*/
IMOS_EXPORT ULONG STDCALL IMOS_StartVodStreamByTime
(
    IN const USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN const CHAR                   szCameraCode[IMOS_RES_CODE_LEN],
    IN const CHAR                   szChannelCode[IMOS_RES_CODE_LEN],
    IN const SDK_VOD_INFO_S         *pstVodInfo
);

/**
* ֹͣ��ʱ��㲥�ط�
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szChannelCode           ͨ������
* @return �������½����
* - �ɹ���ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬��������Ĵ������ļ�
* @note ��
*/
IMOS_EXPORT ULONG STDCALL IMOS_StopVodStreamByTime
(
    IN const USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN const CHAR                   szChannelCode[IMOS_RES_CODE_LEN]
);
/* End add by liujian/02319, 2016-12-09 for MPPD43569 */

/* Begin: Added by zhuzhicong 02302, 2016-12-19 for MPPD43726,A8���Ƶ������л������ṩSDK�ӿ� */
/* A8�����ṩSDK�ӿڣ���shijiaqi�ṩ */
/**
* ��ѯ����ǽ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTvWallCode       ����ǽ����
* @param [IN]       bUserControl       �Ƿ��û����Ʋ���
* @param [OUT]      pstTVWallInfo      ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR                    *pcTVWallCode,
    IN      BOOL_T                  bUserControl,
    OUT     TV_WALL_ALL_INFO_S      *pstTVWallInfo
);

/**
* ��ʼʵʱ��� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szTVWallCode            ����ǽ����
* @param [IN]   szCameraCode            ���������
* @param [IN]   szMonitorCode           ����������
* @param [IN]   ulStreamType            ������,����ֵ������ļ�sdk_def.h��ö�ٶ���IMOS_FAVORITE_STREAM_E
* @param [IN]   ulOperateCode           ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ulOperateCodeȡֵ�μ�CS_OPERATE_CODE_E
*       szMonitorCode�����ʵ����Ϊ��Ӧ�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartA8Monitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szTVWallCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulStreamType,
    IN  ULONG_32                           ulOperateCode
);

/**
* ֹͣʵʱ��� \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szTVWallCode            ����ǽ����
* @param [IN]   szMonitorCode           ����������
* @param [IN]   ulOperateCode           ����ԭ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ulOperateCodeȡֵ�μ�CS_OPERATE_CODE_E
*       szMonitorCode�����ʵ����Ϊ��Ӧ�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopA8Monitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szTVWallCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ����A8����ǽOSD \n
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ
* @param [IN]   szTVWallCode            ����ǽ����
* @param [OUT]  pulWindowAllNum         ���ڷ�������
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetA8TVWallOSD
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szTVWallCode[IMOS_RES_CODE_LEN],
    OUT ULONG_32                        *pulWindowAllNum
);

/**
* ���õ���ǽ���� \n
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallSceneEnable
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulSceneID
);

/**
* ��ʼ��ѯ����ǽ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallSceneGroupCode         ����ǽ���������
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallScenePollStart
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallSceneGroupCode
);

/**
* ֹͣ��ѯ����ǽ���� \n
* @param [IN]       pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]       pcTVWallCode                   ����ǽ����
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallScenePollStop
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode
);

/**
* ��ѯ����ǽ�б� \n
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallListA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT TV_WALL_A8_INFO                 *pstTVWallList
);

/**
* ��ѯ����ǽ�����б� \n
* @param [IN]            pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]            pcTVWallCode       ����ǽ����
* @param [INOUT]         pulSceneNum         ����ǽ��������
* @param [OUT]         pstTVWallSceneList      ����ǽ�����б�
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallSceneListA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN      CHAR                        *pcTVWallCode,
    INOUT   ULONG_32                    *pulSceneNum,
    OUT TV_WALL_BASE_INFO_A8_S          *pstTVWallSceneList
);

/**
* ��ѯ����ǽ�������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTVWallSceneGroupList         ����ǽ�������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallSceneGroupList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroupList
);

/* End: Added by zhuzhicong 02302, 2016-12-19 for MPPD43726,A8���Ƶ������л������ṩSDK�ӿ� */

/* Begin: Added by liucanming/03903, 2017-08-30 for MPPD54245 A8 ƴ����Ѳ*/
/**
* ���A8ƴ����Ѳ��Դ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstPollResInfo          ��Ѳ��Դ��Ϣ
* @param [OUT]  szPollResCode           ��Ѳ��Դ����
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note
* - 1. Ŀǰֻ֧������Ѳ
* - 2. �ýӿڽ�֧��VMƽ̨
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPollRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  POLL_RES_INFO_S                 *pstPollResInfo,
    OUT CHAR                            szPollResCode[IMOS_RES_CODE_LEN]
);

/**
* ɾ��A8ƴ����Ѳ��Դ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulPollType              ��Ѳ���ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E
* @param [IN]   szPollResCode           ��Ѳ��Դ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelPollRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ULONG_32                ulPollType,
    IN  CHAR                    szPollResCode[IMOS_RES_CODE_LEN]
);

/**
* �޸�A8ƴ����Ѳ��Դ
* @param [IN]   pstUserLogIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szPollResCode         ��Ѳ��Դ����
* @param [IN]   pstPollResInfo        ��Ѳ��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyPollRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szPollResCode[IMOS_RES_CODE_LEN],
    IN  POLL_RES_INFO_S                    *pstPollResInfo
);

/**
* ��ѯA8ƴ����Ѳ��Դ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulPollType              ��Ѳ���ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E
* @param [IN]   szPollResCode           ��Ѳ��Դ����
* @param [OUT]  pstPollResInfo          ��Ѳ��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPollRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                        ulPollType,
    IN  CHAR                            szPollResCode[IMOS_RES_CODE_LEN],
    OUT POLL_RES_INFO_S                 *pstPollResInfo
);
/* End: Added by liucanming/03903, 2017-08-30 for MPPD54245 A8 ����Ѳ */

/* Begin: Added by chenmenglin 04110, 2017-09-01 for MPPD54245 A8ƴ���豸��Ѳ���� */
/**
* ����/ֹͣA8ƴ����Ѳ��Դ
* @param [IN]   pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ
* @param [IN]   szPollResCode           ��Ѳ��Դ����
* @param [IN]   ulProcessType           ��������: ��֧������/ֹͣ #MANUAL_OPER_TYPE_E
* @param [IN]   ulOperateCode           ����ԭ����: #CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessPollRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szPollResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                ulProcessType,
    IN  ULONG_32                ulOperateCode
);
/* End: Added by chenmenglin 04110, 2017-09-01 for MPPD54245 A8ƴ���豸��Ѳ���� */

/* Begin: Added by liucanming/03903, 2017-09-18 for MPPD54245 A8ƴ����Ѳ */
/**
* A8ƴ����Ѳ�����Լ���������Ѳ��Դ��ѯ�ӿ�
* @param [IN]   pstUserLoginIDInfo     �û���¼ID��Ϣ��ʶ
* @param [IN]   szTVWallCode           ����ǽ����
* @param [INOUT]  *pulSceneNum         ��������
* @param [OUT]  pstSceneAndPollInfoList    �����Լ���Ѳ��Դ��Ϣ(�Խṹ����ķ�ʽ����: #IMOS_SCENE_MAX_NUM_EX  32)
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySceneAndPollResByTVWcode
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                     szTVWallCode[IMOS_CODE_LEN],
    INOUT ULONG_32                *pulSceneNum,
    OUT POLL_INFO_IN_SCENE_S    *pstSceneAndPollInfoList
);
/* End: Added by liucanming/03903, 2017-09-18 for MPPD54245 A8ƴ����Ѳ */

/* Begin: Added by gupeng 04273, 2017-09-20 for MPPD54245 A8ƴ���豸��Ѳ���� �ṩSDK�ӿ� */
/**
* ���ݵ���ǽ����ͳ���ID��ѯ����ǽ��Ϣ \n
* @param [IN]       pstUserLogIDInfo   �û���¼ID��Ϣ��ʶ
* @param [IN]       szTVWallCode       ����ǽ����
* @param [IN]       ulSceneId          ����ID
* @param [OUT]      pstTVWallInfo      ����ǽ��Ϣ
* @return �������½��:
* - �ɹ�:
* - #ERR_COMMON_SUCCEED
* - ʧ��:
* -      ���ز�������룬���������ļ�
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWBySceneId
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR                     szTVWallCode[IMOS_CODE_LEN],
    IN      ULONG_32                 ulSceneId,
    OUT     TV_WALL_ALL_INFO_S      *pstTVWallInfo
);
/* End add by gupeng/04273, 2017-09-20 for MPPD54245 A8ƴ���豸��Ѳ���� */

/*begin add by shangxiang 04382 20171108 for map authority optimize*/
/**
* Ϊ��ͼ�ͻ��˲����û���������Ȩ��Դ\n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstResList         ��Դ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResourceListForMap
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                 *pstRspPageInfo,
    OUT CAMERA_RES_FOR_MAP_S                   *pstResList
);
/*end add by shangxiang 04382 20171108 for map authority optimize*/

/* Begin: Added by zhuzhicong 02302, 2018-01-09 for A8ƴ����Ѳ */
/**
* ��ѯ��Դ�����ڽ��е�ҵ����Ϣ \n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   szResCode           ��Դ����
* @param [IN]   ulResType           ��Դ����, ȡֵΪ#IMOS_TYPE_E, �Ϸ���ȡֵΪ#IMOS_TYPE_SALVO_RESOURCE(����ʾ), #IMOS_TYPE_GROUP_SWITCH_RESOURCE(����Ѳ)
* @param [IN]   szVirDomainCode     ���������
* @param [OUT]  pstSrvInfoV2        ҵ����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* -     ���ز�������룬���������ļ�
* @note Ŀǰֻʵ�ֲ�ѯ����ʾ��ҵ��״̬
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceUnderResV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulResType,
    IN  CHAR                    szVirDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT RES_SRV_STATE_INFO_V2_S    *pstSrvInfoV2
);
/* End: Added by zhuzhicong 02302, 2018-01-09 for A8ƴ����Ѳ */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

