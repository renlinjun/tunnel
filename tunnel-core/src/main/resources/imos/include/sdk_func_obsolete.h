/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              sdk_func_obsolete.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2010-04-09
        Author: w05867
   Description: SDK的保留函数接口
                注意: 其中分页查询时，所需列表空间由外部申请，
                      大小根据分页查询时一页的个数进行申请。


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
* 完成获取XP信息的功能。\n
* @param [IN]   pstUserLoginIDInfo  用户登录ID信息标识
* @param [IN]   ulScreenIndex       屏序号, 支持多屏用, 目前为1
* @param [IN]   ulWinNum            序号为ulScreenIndex的屏的窗格数量, 最大值为#AS_XP_WIN_MAX_NUM
* @param [OUT]  pstXpInfo           XP信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_XP_CODE_EXIST
* - #ERR_DAO_XP_SCREEN_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetXPCode
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  ULONG_32                  ulScreenIndex,
    IN  ULONG_32                  ulWinNum,
    OUT XP_INFO_S              *pstXpInfo
);

/**
* 获取录像文件的URL信息 \n
* @param[IN]    pstUserLogIDInfo            用户登录ID信息标识
* @param[IN]    pstSDKGetUrlInfo            获取录像文件URL的请求
* @param[IN]    pstSDKURLInfo               URL信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_LAST_QUERY_NOT_FINISH
* - #ERR_DAO_STORE_RES_NOT_EXIST
* - #ERR_AS_STORAGE_DEV_NOT_ONLINE
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GETURL
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_S              *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* 修改本域信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstLoDomain             本域信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_INTERDOMAIN_LEVEL_INVALID
* - #ERR_AS_INTERDOMAIM_PARAM_CANNOT_MODIFY
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 本域信息中的本域编码不可修改, 但在修改时需要填写
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

