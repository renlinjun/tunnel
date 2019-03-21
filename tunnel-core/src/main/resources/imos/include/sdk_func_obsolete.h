/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              sdk_func_obsolete.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2010-04-09
        Author: w05867
   Description: SDK�ı��������ӿ�
                ע��: ���з�ҳ��ѯʱ�������б�ռ����ⲿ���룬
                      ��С���ݷ�ҳ��ѯʱһҳ�ĸ����������롣


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_FUNC_OBSOLETE_H_
#define _IMOS_SDK_FUNC_OBSOLETE_H_
#include "sdk_func.h"
#ifdef  __cplusplus
extern "C"{
#endif
/**
* ��ɻ�ȡXP��Ϣ�Ĺ��ܡ�\n
* @param [IN]   pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ
* @param [IN]   ulScreenIndex       �����, ֧�ֶ�����, ĿǰΪ1
* @param [IN]   ulWinNum            ���ΪulScreenIndex�����Ĵ�������, ���ֵΪ#AS_XP_WIN_MAX_NUM
* @param [OUT]  pstXpInfo           XP��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_DAO_XP_CODE_EXIST
* - #ERR_DAO_XP_SCREEN_EXIST
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetXPCode
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  ULONG_32                  ulScreenIndex,
    IN  ULONG_32                  ulWinNum,
    OUT XP_INFO_S              *pstXpInfo
);

/**
* ��ȡ¼���ļ���URL��Ϣ \n
* @param[IN]    pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param[IN]    pstSDKGetUrlInfo            ��ȡ¼���ļ�URL������
* @param[IN]    pstSDKURLInfo               URL��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_LAST_QUERY_NOT_FINISH
* - #ERR_DAO_STORE_RES_NOT_EXIST
* - #ERR_AS_STORAGE_DEV_NOT_ONLINE
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GETURL
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_S              *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* �޸ı�����Ϣ
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstLoDomain             ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* - #ERR_AS_INTERDOMAIN_LEVEL_INVALID
* - #ERR_AS_INTERDOMAIM_PARAM_CANNOT_MODIFY
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     ���ز�������룬���������ļ�
* @note ������Ϣ�еı�����벻���޸�, �����޸�ʱ��Ҫ��д
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetLoDomain
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   LO_DOMAIN_S                *pstLoDomain
);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

