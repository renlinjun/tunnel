/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              sdk_tollgate_func.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2011-03-14
        Author: baoyihui/02795
   Description: 卡口SDK对外接口
                注意: 1)其中分页查询时，所需列表空间由外部申请，
                        大小根据分页查询时一页的个数进行申请。
                      2)数据字典类型说明参考IMOS_QueryDictionaryDataList接口说明

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/


#ifndef _IMOS_SDK_TOLLGATE_FUNC_H_
#define _IMOS_SDK_TOLLGATE_FUNC_H_

#ifdef  __cplusplus
extern "C"{
#endif

/** @defgroup groupSDKTollgate 卡口SDK
*   卡口SDK
*   @{
*/

/**
* 查询卡口 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCode          卡口编码
* @param [OUT]  pstTollgateInfo         卡口信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    OUT  TOLLGATE_INFO_S                *pstTollgateInfo
);

/**
* 查询卡口列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#NAME_TYPE[卡口名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTollgateList         卡口列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_INFO_S                *pstTollgateList
);

#if 0
#endif

/**
* 查询布/撤控单位 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionDeptCode   布/撤控单位编码
* @param [OUT]  pstDispositionDept      布/撤控单位信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionDeptCode[IMOS_CODE_LEN],
    OUT  DISPOSITION_DEPT_S             *pstDispositionDept
);

/**
* 查询布/撤控单位列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#CODE_TYPE[单位编码]，#NAME_TYPE[单位名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionDeptList  布/撤控单位列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDispositionDeptList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DISPOSITION_DEPT_S             *pstDispositionDeptList
);

#if 0
#endif

/**
* 增加布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionInfo      布控信息
* @param [IN]   pstMapAreaDisposeResInfo区域布控资源信息
* @parma [IN]   pstDisposePlanInfo      布控计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 布控照片需要通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper接口获取FTP服务参数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STATEMENT_DISPOSITION_INFO_S    *pstDispositionInfo,
    IN  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaDisposeResInfo,
    IN  DISPOSE_PLAN_INFO_S             *pstDisposePlanInfo
);

/**
* 删除布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 删除时后台会同时删除布控照片
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN]
);

/**
* 修改布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionInfo      布控信息
* @parma [IN]   pstDisposePlanInfo      布控计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STATEMENT_DISPOSITION_INFO_S    *pstDispositionInfo,
    IN  DISPOSE_PLAN_INFO_S             *pstDisposePlanInfo
);

/**
* 撤控 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [IN]   pstUndoDispositionInfo  撤控信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UndoStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  STATEMENT_DISPOSITION_UNDO_INFO_S  *pstUndoDispositionInfo
);

/**
* 单个域撤控 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [IN]   szDomainCode            域编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UndoDomainStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  CHAR                               szDomainCode[IMOS_CODE_LEN]
);

/**
* 单个域重新布控 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [IN]   szDomainCode            域编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RedoDomainStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  CHAR                               szDomainCode[IMOS_CODE_LEN]
);

/**
* 查询布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [OUT]  pstDispositionInfo      布控信息
* @param [OUT]  pstMapAreaDisposeResInfo区域布控资源信息
* @param [OUT]  pstDisposePlanInfo      布控计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN],
    OUT  STATEMENT_DISPOSITION_INFO_S   *pstDispositionInfo,
    OUT  MAP_AREA_DISPOSE_RES_INFO_S    *pstMapAreaDisposeResInfo,
    OUT  DISPOSE_PLAN_INFO_S            *pstDisposePlanInfo
);

/**
* 查询车辆布控域列表 \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   szDispositionCode         布控编号
* @param [IN]   pstQueryCondition         通用查询条件
* @param [IN]   pstQueryPageInfo          请求分页信息
* @param [OUT]  pstRspPageInfo            响应分页信息
* @param [OUT]  pstDispositionDomainList  域列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[域编码]
* - #NAME_TYPE[域名称]
* - #DISPOSITION_STATUS[布控状态]
* - #DISPOSITION_RESULT[布控处理结果]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDispositionDomainList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  STATEMENT_DISPOSITION_DOMAIN_S *pstDispositionDomainList
);

/**
* 查询布控列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionList      布控列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #DOMAIN_CODE[域编码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_TYPE[车辆类型]
* - #VEHICLE_COLOR_DEPTH[车身颜色深浅]
* - #VEHICLE_COLOR[车身颜色]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_STATUS[布控状态]
* - #DISPOSITION_UNDO_DEPT[撤控单位编码]
* - #DISPOSITION_UNDO_USER[撤控人员编码]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDispositionList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  STATEMENT_DISPOSITION_INFO_S   *pstDispositionList
);

/*Begin added by a02842 for MPPD46586,2017-4-11*/
#if 0
#endif

/**
* 增加布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionInfo      布控信息
* @param [IN]   pstMapAreaDisposeResInfo区域布控资源信息
* @parma [IN]   pstDisposePlanInfo      布控计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 布控照片需要通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper接口获取FTP服务参数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddStatementDispositionV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STATEMENT_DISPOSITION_INFO_V2_S    *pstDispositionInfo,
    IN  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaDisposeResInfo,
    IN  DISPOSE_PLAN_INFO_S             *pstDisposePlanInfo
);

/**
* 修改布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionInfo      布控信息
* @parma [IN]   pstDisposePlanInfo      布控计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyStatementDispositionV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STATEMENT_DISPOSITION_INFO_V2_S    *pstDispositionInfo,
    IN  DISPOSE_PLAN_INFO_S             *pstDisposePlanInfo
);

/**
* 查询布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [OUT]  pstDispositionInfo      布控信息
* @param [OUT]  pstMapAreaDisposeResInfo区域布控资源信息
* @param [OUT]  pstDisposePlanInfo      布控计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDispositionV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN],
    OUT  STATEMENT_DISPOSITION_INFO_V2_S   *pstDispositionInfo,
    OUT  MAP_AREA_DISPOSE_RES_INFO_S    *pstMapAreaDisposeResInfo,
    OUT  DISPOSE_PLAN_INFO_S            *pstDisposePlanInfo
);

/**
* 查询布控列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionList      布控列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #DOMAIN_CODE[域编码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_TYPE[车辆类型]
* - #VEHICLE_COLOR_DEPTH[车身颜色深浅]
* - #VEHICLE_COLOR[车身颜色]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_STATUS[布控状态]
* - #DISPOSITION_UNDO_DEPT[撤控单位编码]
* - #DISPOSITION_UNDO_USER[撤控人员编码]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDispositionListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  STATEMENT_DISPOSITION_INFO_V2_S   *pstDispositionList
);
/*End added by a02842 for MPPD46586,2017-4-11*/

#if 0
#endif

/**
* 添加黑名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleBlacklist     黑名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_BLACKLIST_S             *pstVehicleBlacklist
);

/**
* 删除黑名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szBlacklistCode         黑名单编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBlacklistCode[IMOS_CODE_LEN]
);

/**
* 修改黑名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleBlacklist     黑名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_BLACKLIST_S             *pstVehicleBlacklist
);

/**
* 查询黑名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szBlacklistCode         黑名单编号
* @param [OUT]  pstVehicleBlacklist     黑名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBlacklistCode[IMOS_CODE_LEN],
    OUT  VEHICLE_BLACKLIST_S            *pstVehicleBlacklist
);

/**
* 查询黑名单列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleBlacklistList 黑名单列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_DEPT[录入单位编码]
* - #DISPOSITION_USER[录入人员编码]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleBlacklistList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_BLACKLIST_S            *pstVehicleBlacklistList
);

#if 0
#endif

/**
* 查询过车数据列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleDataList      过车数据列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆信息编号]
* - #DOMAIN_CODE[卡口所属组织编号]
* - #IS_QUERY_SUB[是否包含下级组织]
* - #TOLLGATE_CODE[卡口编号]
* - #LANE_NUMBER[车道号]
* - #LANE_DIRECTION[行驶方向编号]
* - #PASS_TIME[通过时间/驶出卡口时间]
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #SPEED_TYPE[车辆速度]
* - #LIMIT_SPEED[车道限速]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_TYPE[车辆类型]
* - #VEHICLE_COLOR_DEPTH[车身颜色深浅]
* - #VEHICLE_COLOR[车身颜色]
* - #VEHICLE_IDENTIFY_STATUS[识别状态]
* - #VEHICLE_STATUS[行驶状态]
* - #VEHICLE_DATA_TYPE[过车数据类型]
* - #VEHICLE_DEAL_STATUS[处理标记]
* - #SECTION_CODE[测速区间编号]
* - #PASS_TIME2[驶出卡口时间]
* - #PLACE_CODE[违章地点编码]
* - #EQUIPMENT_TYPE[采集类型]
* - #DEPT_CODE[部门编码]
* @attention
* - DOMAIN_CODE和TOLLGATE_CODE不能同时使用
* - VEHICLE_DATA_TYPE[过车数据类型]等于区间测速时，可使用SECTION_CODE查询条件
* - VEHICLE_DATA_TYPE[过车数据类型]等于过车数据时，可使用DOMAIN_CODE或TOLLGATE_CODE查询条件
* - DOMAIN_CODE、TOLLGATE_CODE只能用EQUAL_FLAG逻辑关系
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_S                 *pstVehicleDataList
);

/**
* 查询过车数据列表(内部接口，请勿使用) \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   ulNestConditionNum      嵌套查询条件数量
* @param [IN]   pstNestConditionList    嵌套查询条件列表
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleDataV2List    过车数据列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆信息编号]
* - #DOMAIN_CODE[卡口所属组织编号]
* - #IS_QUERY_SUB[是否包含下级组织]
* - #TOLLGATE_CODE[卡口编号]
* - #LANE_NUMBER[车道号]
* - #LANE_DIRECTION[行驶方向编号]
* - #PASS_TIME[通过时间/驶出卡口时间]
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #SPEED_TYPE[车辆速度]
* - #LIMIT_SPEED[车道限速]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_TYPE[车辆类型]
* - #VEHICLE_COLOR_DEPTH[车身颜色深浅]
* - #VEHICLE_COLOR[车身颜色]
* - #VEHICLE_IDENTIFY_STATUS[识别状态]
* - #VEHICLE_STATUS[行驶状态]
* - #VEHICLE_DATA_TYPE[过车数据类型]
* - #VEHICLE_DEAL_STATUS[处理标记]
* - #SECTION_CODE[测速区间编号]
* - #PASS_TIME2[驶出卡口时间]
* - #PLACE_CODE[违章地点编码]
* - #EQUIPMENT_TYPE[采集类型]
* - #DEPT_CODE[部门编码]
* @attention
* - DOMAIN_CODE和TOLLGATE_CODE不能同时使用
* - VEHICLE_DATA_TYPE[过车数据类型]等于区间测速时，可使用SECTION_CODE查询条件
* - VEHICLE_DATA_TYPE[过车数据类型]等于过车数据时，可使用DOMAIN_CODE或TOLLGATE_CODE查询条件
* - DOMAIN_CODE、TOLLGATE_CODE只能用EQUAL_FLAG逻辑关系
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataListV3
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
* 车辆信息校对 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleData          车辆行驶记录
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_DATA_S                  *pstVehicleData
);

/**
* 车辆信息校对 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleData          车辆行驶记录
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleDataV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_DATA_V3_S                  *pstVehicleData
);

/**
* 查询报警车辆列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleAlarmDataList 报警车辆列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆报警信息编号]
* - #VEHICLE_DATA_CODE[车辆信息编号]
* - #DOMAIN_CODE[卡口所属组织编号]
* - #IS_QUERY_SUB[是否包含下级组织]
* - #TOLLGATE_CODE[卡口编号]
* - #LANE_NUMBER[车道号]
* - #LANE_DIRECTION[行驶方向编号]
* - #PASS_TIME[通过时间/驶出卡口时间]
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #SPEED_TYPE[车辆速度]
* - #LIMIT_SPEED[车道限速]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_TYPE[车辆类型]
* - #VEHICLE_COLOR_DEPTH[车身颜色深浅]
* - #VEHICLE_COLOR[车身颜色]
* - #VEHICLE_STATUS[行驶状态]
* - #ALARM_TYPE[告警类别]
* - #DISPOSITION_CODE[布控编号]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #EVENT_TIME[报警时间]
* - #VEHICLE_DEAL_STATUS[处理标记]
* - #SECTION_CODE[测速区间编号]
* - #PASS_TIME2[驶出卡口时间]
* - #PLACE_CODE[违章地点编码]
* - #EQUIPMENT_TYPE[采集类型]
* - #DEPT_CODE[部门编码]
* - #COMBINE_FLAG[合成标识]
* @attention
* - DOMAIN_CODE和TOLLGATE_CODE不能同时使用
* - ALARM_TYPE[告警类别]等于布控告警时，DISPOSITION_CODE填写车辆布控编号，可使用DISPOSITION_TYPE、DISPOSITION_DEPT和DISPOSITION_USER
* - ALARM_TYPE[告警类别]等于黑名单告警时，DISPOSITION_CODE填写黑名单编号，DISPOSITION_TYPE、DISPOSITION_DEPT和DISPOSITION_USER无效
* - ALARM_TYPE[告警类别]等于区间测速告警时，DISPOSITION_CODE、DISPOSITION_TYPE、DISPOSITION_DEPT和DISPOSITION_USER无效
* - DOMAIN_CODE、TOLLGATE_CODE、DISPOSITION_DEPT、DISPOSITION_USER只能用EQUAL_FLAG逻辑关系
* - COMBINE_FLAG[合成标识]仅支持等于/不等于，等于0，表示已合成，不等于0，表示未合成
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_ALARM_DATA_S           *pstVehicleAlarmDataList
);

/**
* 报警车辆处理 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleAlarmData     报警车辆信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleAlarmData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_ALARM_DATA_S            *pstVehicleAlarmData
);

#if 0
#endif

/**
* 根据数据类型查询数据字典枚举列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件包括:#CODE_TYPE[数据字典编码];NAME_TYPE[数据字典名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDictionaryDataList   数据字典枚举列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDictionaryDataList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DICTIONARY_DATA_S              *pstDictionaryDataList
);

/**
* 根据数据类型查询数据字典枚举列表  V2 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件包括:#CODE_TYPE[数据字典编码];NAME_TYPE[数据字典名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDictionaryDataList   数据字典枚举列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 蝍dd by y02360 支持42位中文字符
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDictionaryDataListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DICTIONARY_DATAV2_S              *pstDictionaryDataList
);

/**
* 根据操作类型获取FTP服务信息 \n
* @param [IN]   pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   ulFtpOperType                  FTP操作类型，参考#FTP_OPER_TYPE_E
* @param [OUT]  pstFtpInfo                     FTP服务信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFTPInfoByOper
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ULONG_32                   ulFtpOperType,
    OUT FTP_INFO_S              *pstFtpInfo
);

/**
* 增加卡口相机 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTollgateCameraInfo   相机信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_CAMERA_INFO_S          *pstTollgateCameraInfo
);

/**
* 删除卡口相机 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCameraCode    相机编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCameraCode[IMOS_CODE_LEN]
);

/**
* 修改卡口相机 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTollgateCameraInfo   相机信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_CAMERA_INFO_S          *pstTollgateCameraInfo
);

/**
* 查询卡口相机 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCameraCode    相机编码
* @param [OUT]  pstTollgateCameraInfo   相机信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCameraCode[IMOS_CODE_LEN],
    OUT  TOLLGATE_CAMERA_INFO_S         *pstTollgateCameraInfo
);

/**
* 查询卡口相机列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCode          所属卡口编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTollgateCameraList   相机列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询/排序条件可以为#NAME_TYPE[相机名称]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateCameraList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_CAMERA_INFO_S         *pstTollgateCameraList
);

#if 0
#endif

/**
* 开始卡口实时监控 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szCameraCode            相机编码
* @param [IN]   szMonitorCode           窗格编码
* @param [IN]   ulOperateCode           操作原因码, 取值为#CS_OPERATE_CODE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartTollgateMonitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* 停止卡口实时监控 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szMonitorCode           窗格编码
* @param [IN]   ulOperateCode           操作原因码, 取值为#CS_OPERATE_CODE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopTollgateMonitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

#if 0
#endif

/**
* 绑定卡口摄像机 \n
* @param [IN]   pstUserLogIDInfo         用户登录ID信息标识
* @param [IN]   pstVideoCameraBindInfo   卡口摄像机绑定信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 抓拍的卡口车道数量和监控的卡口车道数量不能同时为0
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_VIDEO_CAMERA_BIND_INFO_S   *pstVideoCameraBindInfo
);

/**
* 解绑定卡口摄像机 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCode          卡口编码
* @param [IN]   szCameraCode            摄像机编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnbindTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN]
);

/**
* 修改卡口摄像机绑定信息 \n
* @param [IN]   pstUserLogIDInfo         用户登录ID信息标识
* @param [IN]   pstVideoCameraBindInfo   卡口摄像机绑定信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 仅能修改绑定的车道
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_VIDEO_CAMERA_BIND_INFO_S   *pstVideoCameraBindInfo
);

/**
* 查询卡口摄像机 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szCameraCode                卡口摄像机编码
* @param [OUT]  pstTollgateVideoCameraItem  卡口摄像机信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szCameraCode[IMOS_CODE_LEN],
    OUT TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S  *pstTollgateVideoCameraItem
);


/**
* 查询卡口摄像机列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szTollgateCode                  所属卡口编码
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstTollgateVideoCameraItemList  摄像机列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询/排序条件可以为#NAME_TYPE[摄像机名称]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateVideoCameraList
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  CHAR                                 szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S             *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                    *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT  TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S  *pstTollgateVideoCameraItemList
);

/**
* 根据卡口和车道查询摄像机 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szTollgateCode              所属卡口编码
* @param [IN]   ulLaneNumber                车道号
* @param [OUT]  pstTollgateVideoCameraItem  卡口摄像机信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateVideoCameraByTollgateAndLane
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szTollgateCode[IMOS_CODE_LEN],
    IN  ULONG_32                               ulLaneNumber,
    OUT TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S  *pstTollgateVideoCameraItem
);

#if 0
#endif

/**
* 增加数据字典项 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       数据字典项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDictionaryData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_S               *pstDictionaryData
);

/**
* 删除数据字典项 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   szDictionaryDataCode    数据字典编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDictionaryData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  CHAR                            szDictionaryDataCode[IMOS_DICTIONARY_KEY_LEN]
);

/**
* 修改数据字典项 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       数据字典项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 仅允许修改数据字典名称
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDictionaryData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_S               *pstDictionaryData
);

#if 0
#endif

/**
* 添加测速区间 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstDetectionRoadSection     测速区间信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DETECTION_ROAD_SECTION_S        *pstDetectionRoadSection
);

/**
* 删除测速区间 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szDetectionRoadSectionCode  测速区间编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDetectionRoadSectionCode[IMOS_CODE_LEN]
);

/**
* 修改测速区间 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDetectionRoadSection 测速区间信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DETECTION_ROAD_SECTION_S        *pstDetectionRoadSection
);

/**
* 查询测速区间 \n
* @param [IN]   pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   szDetectionRoadSectionCode     测速区间编号
* @param [OUT]  pstDetectionRoadSectionItem    测速区间信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szDetectionRoadSectionCode[IMOS_CODE_LEN],
    OUT DETECTION_ROAD_SECTION_QUERY_ITEM_S *pstDetectionRoadSectionItem
);

/**
* 查询测速区间列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstDetectionRoadSectionItemList 测速区间列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #SECTION_CODE[区间编号]
* - #NAME_TYPE[区间名称]
* - #TOLLGATE_CODE_IN[卡口编号（驶入）]
* - #TOLLGATE_CODE_OUT[卡口编号（驶出）]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDetectionRoadSectionList
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S             *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                    *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT  DETECTION_ROAD_SECTION_QUERY_ITEM_S *pstDetectionRoadSectionItemList
);

/**
* 修改测速区间超速百分比配置 \n
* @param [IN]   pstUserLogIDInfo                       用户登录ID信息标识
* @param [IN]   ulDetectionRoadSectionVioConfNum       测速区间超速百分比配置数量
* @param [IN]   pstDetectionRoadSectionVioConfList     测速区间超速百分比配置列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDetectionRoadSectionVioConf
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  ULONG_32                                 ulDetectionRoadSectionVioConfNum,
    IN  DETECTION_ROAD_SECTION_VIO_CONF_S     astDetectionRoadSectionVioConfList[IMOS_DETECTION_ROAD_SECTION_VIO_CONF_MAX_NUM]
);

/**
* 查询测速区间超速百分比配置 \n
* @param [IN]   pstUserLogIDInfo                         用户登录ID信息标识
* @param [OUT]  pulDetectionRoadSectionVioConfNum        测速区间超速百分比配置数量
* @param [OUT]  pstDetectionRoadSectionVioConfList       测速区间超速百分比配置列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDetectionRoadSectionVioConf
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    OUT ULONG_32                                *pulDetectionRoadSectionVioConfNum,
    OUT DETECTION_ROAD_SECTION_VIO_CONF_S    astDetectionRoadSectionVioConfList[IMOS_DETECTION_ROAD_SECTION_VIO_CONF_MAX_NUM]
);

/** @} */ /* end of groupSDKTollgate */

/* Begin added by c02845,2016-05-25,交通流信息接入 */

/**
* 查询车流量信息列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [OUT]  pstDetectionRoadSectionItemList 交通流信息按小时查询，区分每个车道的具体车流量信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括
* - #QUERY_TIME[日期]
* - #QUERY_HOUR[时间段]
* - #TOLLGATE_CODE_IN[卡口编号]

*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrafficFlowLaneList
(
    IN  USER_LOGIN_ID_INFO_S                       *pstUserLogIDInfo,
    IN  TRAFFICFLOW_QUERY_CONDITION_LANE_S         *pstQueryCondition,
    OUT TRAFFIC_FLOW_QUERY_LANE_LIST_S             *pstTrafficFlowItemLaneList
);


/**
* 查询车流量信息列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [OUT]  pstDetectionRoadSectionItemList 车流量信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 需要的查询条件包括
* - #QUERYWAY[查询方式]
* - #QUERY_TIME[日期]
* - #TOLLGATE_CODE[卡口编号]

*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrafficFlowList
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  TRAFFICFLOW_QUERY_CONDITION_S         *pstQueryCondition,
    OUT TRAFFIC_FLOW_QUERY_LIST_S             *pstTrafficFlowItemList
);

/* Begin added by c02845,2016-05-25,交通流信息接入 */


/*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
/**
* 增加Mac&Rfid布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionInfo      布控信息
* @param [IN]   pstMapAreaDisposeResInfo区域布控资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 布控照片需要通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper接口获取FTP服务参数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMacRfidDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MACRFID_DISPOSITION_INFO_S    *pstDispositionInfo,
    IN  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaDisposeResInfo
);

/**
* 删除Mac&Rfid布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 删除时后台会同时删除布控照片
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMacRfidDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN]
);

/**
* 修改Mac&Rfid布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionInfo      布控信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMacRfidDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MACRFID_DISPOSITION_INFO_S    *pstDispositionInfo
);

/**
* 撤控 Mac&Rfid\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [IN]   pstUndoDispositionInfo  撤控信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UndoMacRfidDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  MACRFID_DISPOSITION_UNDO_INFO_S  *pstUndoDispositionInfo
);

/**
* 查询Mac&Rfid布控内容 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       布控编号
* @param [OUT]  pstDispositionInfo      布控信息
* @param [OUT]  pstMapAreaDisposeResInfo区域布控资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacRfidDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN],
    OUT  MACRFID_DISPOSITION_INFO_S   *pstDispositionInfo,
    OUT  MAP_AREA_DISPOSE_RES_INFO_S    *pstMapAreaDisposeResInfo
);

/**
* 查询Mac&Rfid布控列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionList      布控列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括:Mac&Rfid布控查询条件待定，以下仅作为参考
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #DOMAIN_CODE[域编码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_COLOR[车身颜色]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_STATUS[布控状态]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacRfidDispositionList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  MACRFID_DISPOSITION_INFO_S   *pstDispositionList
);


/**
* 查询Mac告警列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionList      告警列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括:Mac告警列表查询条件待定，以下仅作为参考

* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_COLOR[车身颜色]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_STATUS[布控状态]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacAlarmList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  MAC_ALARM_INFO_S           *pstMacAlarmList
);

/*Begin added by a02842 for mac identify,2017-05-08*/
/**
* 查询Mac告警列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionList      告警列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括:Mac告警列表查询条件待定，以下仅作为参考

* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_COLOR[车身颜色]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_STATUS[布控状态]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacAlarmListV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  MAC_ALARM_INFO_V2_S           *pstMacAlarmList
);
/*End added by a02842 for mac identify,2017-05-08*/

/**
* 查询Rfid告警列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDispositionList      告警列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括:Mac告警列表查询条件待定，以下仅作为参考
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #DOMAIN_CODE[域编码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LOGO[车辆品牌]
* - #VEHICLE_COLOR[车身颜色]
* - #DISPOSITION_DEPT[布控单位编码]
* - #DISPOSITION_USER[布控人员编码]
* - #PRIORITY_TYPE[布控优先级]
* - #DISPOSITION_TYPE[布控类别]
* - #DISPOSITION_STATUS[布控状态]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRfidAlarmList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  RFID_ALARM_INFO_S   *pstRfidAlarmList
);

/*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

/* Begin added by sW5358 for MPPD58977 */
/**
* 删除报警车辆V2         操作分表     \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleAlarmCode      车辆报警信息编号
* @param [IN]   szPassTime      		车辆通过卡口时间
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleAlarmDataV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleAlarmCode[IMOS_CODE_LEN],
    IN  CHAR                            szPassTime[IMOS_TIME_LEN]
);

/* End added by sW5358 for MPPD58977 */



#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

