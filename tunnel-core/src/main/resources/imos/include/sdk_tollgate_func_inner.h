/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              sdk_tollgate_func_inner.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2011-03-14
        Author: baoyihui/02795
   Description: 卡口SDK内部接口
                注意: 1)其中分页查询时，所需列表空间由外部申请，
                        大小根据分页查询时一页的个数进行申请。
                      2)数据字典类型说明参考IMOS_QueryDictionaryDataList接口说明

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

/** @defgroup groupSDKTollgate 卡口SDK
*   卡口SDK
*   @{
*/

/**
* 增加TMS \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTMSInfo              TMS信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_INFO_S                      *pstTMSInfo
);

/**
* 删除TMS \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSCode               TMS编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN]
);

/**
* 修改TMS \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTMSInfo              TMS信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_INFO_S                      *pstTMSInfo
);

/**
* 查询TMS \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSCode               TMS编码
* @param [OUT]  pstTMSInfo              TMS信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSCode[IMOS_CODE_LEN],
    OUT  TMS_INFO_S                     *pstTMSInfo
);

/**
* 查询TMS列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#NAME_TYPE[设备名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTMSList              TMS列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 增加卡口 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTollgateInfo         卡口信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 卡口示意图需要通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper接口获取FTP服务参数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_INFO_S                 *pstTollgateInfo
);

/**
* 删除卡口 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCode          卡口编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 删除时后台会同时删除卡口示意图
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN ULONG_32                      ulIsSave
);

/**
* 修改卡口 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTollgateInfo         卡口信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_INFO_S                 *pstTollgateInfo
);

/**
* 增加卡口与TMS的绑定关系\n
* @param [IN] pstUserLogIDInfo 用户登录ID信息标识
* @param [IN] pstBindInfo 绑定信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateTMSBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_TMS_BIND_INFO_S        *pstBindInfo
);

/**
* 删除卡口与TMS的绑定关系\n
* @param [IN] pstUserLogIDInfo 用户登录ID信息标识
* @param [IN] pstBindInfo 绑定信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateTMSBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_TMS_BIND_INFO_S        *pstBindInfo
);

#if 0
#endif

/**
* 修改卡口车道信息 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstLaneInfo             卡口车道信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateLane
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_LANE_INFO_S            *pstLaneInfo
);

/**
* 查询卡口车道列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTollgateCode          所属卡口编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstLaneQueryItemList    卡口车道列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询/排序条件可以为#LANE_NUMBER[车道号]，#LANE_DIRECTION(车道方向编号)
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
* 增加闪光灯  \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstTollgateFlashlightInfo   闪光灯信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateFlashlight
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_FLASHLIGHT_INFO_S          *pstTollgateFlashlightInfo
);

/**
* 删除闪光灯 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szTollgateFlashlightCode    闪光灯编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateFlashlight
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateFlashlightCode[IMOS_CODE_LEN]
);

/**
* 修改闪光灯\n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstTollgateFlashlightInfo   闪光灯信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateFlashlight
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_FLASHLIGHT_INFO_S          *pstTollgateFlashlightInfo
);

/**
* 查询闪光灯列表 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szTollgateCode              所属卡口编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              响应分页信息
* @param [OUT]  pstTollgateFlashlightList   闪光灯列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询卡口红绿灯状态列表 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szTollgateCode              所属卡口编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              响应分页信息
* @param [OUT]  pstTrafficLightStatusList   卡口红绿灯状态列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 增加布/撤控单位 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionDept      布/撤控单位信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DISPOSITION_DEPT_S              *pstDispositionDept
);

/**
* 删除布/撤控单位 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionDeptCode   布/撤控单位编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionDeptCode[IMOS_CODE_LEN]
);

/**
* 修改布/撤控单位 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDispositionDept      布/撤控单位信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DISPOSITION_DEPT_S              *pstDispositionDept
);

#if 0
#endif

/**
* 分配存储资源 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstStoreResBasicInfo    存储资源
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 卡口系统仅支持IPSAN存储，ulStorageType必须设置为STORE_DEV_TYPE_IPSAN
*       卡口系统不支持自动选择存储设备，bAutoSelectStoreDev必须设置为填写BOOL_FALSE
*       卡口系统仅支持滚动存储方式，ulDiskFullPolicy必须设置为DISK_FULL_POLICY_OVERLOAD
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignDevStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* 删除存储资源 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szResCode               存储资源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDevStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN]
);

/**
* 查询存储资源 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szResCode               存储资源编码
* @param [OUT]  pstStoreResBasicInfo    存储资源
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    OUT STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* 查询存储资源列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDevCode               设备编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为,#NAME_TYPE[资源名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstStoreResBasicList    存储资源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 在GIS地图上创建图标 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstMapBaseIcon          图标基本信息
* @param [OUT]  szIconCode              图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GIS_MAP_BASE_ICON_S         *pstMapBaseIcon,
    OUT CHAR                        szIconCode[IMOS_CODE_LEN]
);

/**
* 在GIS地图上删除图标 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szIconCode              图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    IN  CHAR                        szIconCode[IMOS_CODE_LEN]
);

/**
* 在GIS地图上修改图标 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstMapBaseIcon          图标基本信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GIS_MAP_BASE_ICON_S         *pstMapBaseIcon
);

/**
* 查询GIS地图图标信息 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szIconCode              图标编码
* @param [OUT]  pstCamIcon              图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMapIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_CODE_LEN],
    IN  CHAR                        szIconCode[IMOS_CODE_LEN],
    OUT GIS_MAP_ICON_S              *pstMapIcon
);

/**
* 分页查询某个GIS地图上的图标列表 \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szGISMapCode           GIS地图编码
* @param [IN]   ulIconType             图标类型，参考#IMOS_TYPE_E，目前仅支持IMOS_TYPE_TOLLGATE
* @param [IN]   pstQueryCondition      通用查询条件(支持的查询条件包括:#CODE_TYPE[图标编码])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstMapIconList         图标信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 添加白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleWhitelist     白名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_S             *pstVehicleWhitelist
);

/**
* 删除白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleWhitelistCode  白名单编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleWhitelistCode[IMOS_CODE_LEN]
);

/**
* 修改白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleWhitelist     白名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_S             *pstVehicleWhitelist
);

/**
* 查询白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleWhitelistCode  白名单编号
* @param [OUT]  pstVehicleWhitelist     白名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleWhitelist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleWhitelistCode[IMOS_CODE_LEN],
    OUT  VEHICLE_WHITELIST_S            *pstVehicleWhitelist
);

/**
* 查询白名单列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleWhitelistList 白名单列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
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
* 添加白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleWhitelist     白名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleWhitelistV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_V2_S             *pstVehicleWhitelist,
    IN  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaResInfo
);

/**
* 修改白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleWhitelist     白名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleWhitelistV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_WHITELIST_V2_S             *pstVehicleWhitelist
);

/**
* 查询白名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleWhitelistCode  白名单编号
* @param [OUT]  pstVehicleWhitelist     白名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleWhitelistV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleWhitelistCode[IMOS_CODE_LEN],
    OUT  VEHICLE_WHITELIST_V2_S            *pstVehicleWhitelist,
    OUT  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaResInfo
);

/**
* 查询白名单列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleWhitelistList 白名单列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
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
* 添加名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulType                  名单类型，参考#VEHICLE_LIST_TYPE_E
* @param [IN]   pstVehiclePlate         名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  VEHICLE_PLATE_S                 *pstVehiclePlate
);

/**
* 删除名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulType                  名单类型，参考#VEHICLE_LIST_TYPE_E
* @param [IN]   szVehiclePlateCode      名单编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  CHAR                            szVehiclePlateCode[IMOS_CODE_LEN]
);

/**
* 修改名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulType                  名单类型，参考#VEHICLE_LIST_TYPE_E
* @param [IN]   pstVehiclePlate         名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  VEHICLE_PLATE_S                 *pstVehiclePlate
);

/**
* 查询名单 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulType                  名单类型，参考#VEHICLE_LIST_TYPE_E
* @param [IN]   szVehiclePlateCode      名单编号
* @param [OUT]  pstVehiclePlate         名单信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehiclePlate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulType,
    IN  CHAR                            szVehiclePlateCode[IMOS_CODE_LEN],
    OUT VEHICLE_PLATE_S                 *pstVehiclePlate
);

/**
* 查询名单列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulType                  名单类型，参考#VEHICLE_LIST_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehiclePlateList     名单列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
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
* 查询卡口本地资源列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSCode               TMS编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTollgateLocalResList 卡口本地资源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询卡口保存周期 \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [OUT]  pstTollgateStorCycle       卡口保存周期
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateStorCycle
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT TOLLGATE_STOR_CYCLE_S       *pstTollgateStorCycle
);

/**
* 修改卡口保存周期 \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstTollgateStorCycle       卡口保存周期
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateStorCycle
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  TOLLGATE_STOR_CYCLE_S       *pstTollgateStorCycle
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
* @note 支持42位中文字符
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDictionaryDataV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATAV2_S               *pstDictionaryData
);

/**
* 修改数据字典项  V2\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       数据字典项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 仅允许修改数据字典名称 支持42位中文字符
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
* 添加套牌分析 \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstPlateAnalyseInfo    套牌分析信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPlateAnalyse
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  PLATE_ANALYSE_INFO_S        *pstPlateAnalyseInfo
);

/**
* 删除套牌分析 \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szPlateAnalyseCode     套牌分析编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelPlateAnalyse
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPlateAnalyseCode[IMOS_CODE_LEN]
);

/**
* 分页查询套牌分析列表 \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstQueryCondition      通用查询条件
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstPlateAnalyseList    套牌分析列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[套牌分析编号]
* - #PLATE_ANALYSE_STATUS[套牌分析状态]
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
* 分页查询套牌分析结果列表 \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstQueryCondition          通用查询条件(支持的查询条件包括:#CODE_TYPE[套牌分析编号])
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstPlateAnalyseResultList  套牌分析结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 删除报警车辆 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleAlarmCode      车辆报警信息编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleAlarmData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleAlarmCode[IMOS_CODE_LEN]
);


#if 0
#endif

/**
* 增加DR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDRInfo               DR信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DR_INFO_S                       *pstDRInfo
);

/**
* 删除DR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDRCode                DR编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDRCode[IMOS_CODE_LEN]
);

/**
* 修改DR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDRInfo               DR信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DR_INFO_S                       *pstDRInfo
);

/**
* 查询DR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDRCode                DR编码
* @param [OUT]  pstDRInfo               DR信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDRCode[IMOS_CODE_LEN],
    OUT DR_INFO_S                       *pstDRInfo
);

/**
* 查询DR列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#NAME_TYPE[设备名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDRList               DR列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 违章统计：按违章类型统计 \n
* @param [IN]   pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   pstQueryCondition              通用查询条件
* @param [IN]   pstQueryPageInfo               请求分页信息
* @param [OUT]  pstRspPageInfo                 响应分页信息
* @param [OUT]  pstViolationStatByTypeList     按违章类型统计结果
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #TOLLGATE_CODE[卡口编码]
* - #EVENT_TIME[报警时间]
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
* 违章统计：按卡口统计 \n
* @param [IN]   pstUserLogIDInfo                   用户登录ID信息标识
* @param [IN]   pstQueryCondition                  通用查询条件
* @param [IN]   pstQueryPageInfo                   请求分页信息
* @param [OUT]  pstRspPageInfo                     响应分页信息
* @param [OUT]  pstViolationStatByTollgateList     按卡口统计结果
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #VEHICLE_STATUS[违章类型]
* - #EVENT_TIME[报警时间]
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
* 违章统计：按处理状态统计 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件(支持的查询条件可以为#EVENT_TIME[报警时间])
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstViolationStatByDealStatusList     按处理状态统计结果
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleViolationStatByDealStatus
(
    IN  USER_LOGIN_ID_INFO_S                     *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S                 *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                        *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                         *pstRspPageInfo,
    OUT  VEHICLE_VIOLATION_STAT_BY_DEAL_STATUS_S *pstViolationStatByDealStatusList
);

/* Begin added by a02842 for 大数据流量统计,2016-06-24*/
/**
* 大数据流量统计\n
* @param [IN]   pstUserLogIDInfo                   用户登录ID信息标识
* @param [IN]   ulResNum                              查询卡口数量
* @param [IN]   pstResList                              查询卡口列表
* @param [IN]   pstStatQueryInfo                    查询条件
* @param [IN]   pstQueryPageInfo                   请求分页信息
* @param [OUT]  pstRspPageInfo                     响应分页信息
* @param [OUT]  pstStatResultList                   流量统计结果
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括
* - #VEHICLE_STATUS[违章类型]
* - #EVENT_TIME[报警时间]
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
/* End added by a02842 for 大数据流量统计,2016-06-24*/

#if 0
#endif

/**
* 查询过车图片生命周期配置 \n
* @param [IN]   pstUserLogIDInfo              用户登录ID信息标识
* @param [OUT]  pstTollgatePhotoLifeCycleCfg  过车图片生命周期配置
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgatePhotoLifeCycleCfg
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    OUT TOLLGATE_PHOTO_LIFE_CYCLE_CFG_S       *pstTollgatePhotoLifeCycleCfg
);

/**
* 修改过车图片生命周期配置 \n
* @param [IN]   pstUserLogIDInfo              用户登录ID信息标识
* @param [IN]   pstTollgatePhotoLifeCycleCfg  过车图片生命周期配置
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgatePhotoLifeCycleCfg
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  TOLLGATE_PHOTO_LIFE_CYCLE_CFG_S       *pstTollgatePhotoLifeCycleCfg
);

#if 0
#endif

/**
* 增加TMS转发地址 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTMSForwardAddrInfo   转发地址信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_FORWARD_ADDR_INFO_S         *pstTMSForwardAddrInfo
);

/**
* 删除TMS转发地址 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSForwardAddrCode    转发地址编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSForwardAddrCode[IMOS_CODE_LEN]
);

/**
* 修改TMS转发地址 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTMSForwardAddrInfo   转发地址信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_FORWARD_ADDR_INFO_S         *pstTMSForwardAddrInfo
);

/**
* 查询TMS转发地址 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSForwardAddrCode    转发地址编号
* @param [OUT]  pstTMSForwardAddrInfo   转发地址信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSForwardAddress
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSForwardAddrCode[IMOS_CODE_LEN],
    OUT  TMS_FORWARD_ADDR_INFO_S        *pstTMSForwardAddrInfo
);

/**
* 查询TMS转发地址列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSCode               TMS编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTMSForwardAddrList   转发地址列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[转发地址编号]
* - #PHY_DEV_IP[转发地址]
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
* 增加违章地点 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstViolationPlace       违章地点信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VIOLATION_PLACE_S               *pstViolationPlace
);

/**
* 删除违章地点 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szViolationPlaceCode    违章地点编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szViolationPlaceCode[IMOS_CODE_LEN]
);

/**
* 修改违章地点 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstViolationPlace       违章地点信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VIOLATION_PLACE_S               *pstViolationPlace
);

/**
* 查询违章地点 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szViolationPlaceCode    违章地点编码
* @param [OUT]  pstViolationPlace       违章地点信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryViolationPlace
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szViolationPlaceCode[IMOS_CODE_LEN],
    OUT  VIOLATION_PLACE_S              *pstViolationPlace
);

/**
* 查询违章地点列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstViolationPlaceList   违章地点列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询/排序条件
* - #CODE_TYPE[编号]
* - #NAME_TYPE[名称]
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
* 查询设备地址列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDevCode               设备编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDevAddrList          设备地址列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询/排序条件
* - #PHY_DEV_IP[地址]
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
* 添加异常行为分析 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstAbnormalAnalyseInfo          异常行为分析信息
* @param [IN]   ulTollgateNum                   卡口数量
* @param [IN]   aszTollgateCodeList             卡口编码列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAbnormalAnalyse
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_ABNORMAL_ANALYSE_INFO_S       *pstAbnormalAnalyseInfo,
    IN  ULONG_32                                  ulTollgateNum,
    IN  CHAR                                   aszTollgateCodeList[IMOS_VEHICLE_ABNORMAL_ANALYSE_TG_MAX_NUM][IMOS_CODE_LEN]
);

/**
* 删除异常行为分析 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szAbnormalAnalyseCode           异常行为编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAbnormalAnalyse
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                        szAbnormalAnalyseCode[IMOS_CODE_LEN]
);

/**
* 分页查询异常行为分析列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstAbnormalAnalyseList          异常行为分析列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[异常行为分析编号]
* - #ABNORMAL_ANALYSE_STATUS[异常行为分析状态]
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
* 分页查询异常行为分析结果列表 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstAbnormalAnalyseResultList         套牌分析结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[异常行为分析编号]
* - #RESULT_CODE[结果编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #COUNT_TYPE[通过次数]
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
* 添加车辆研判:车辆轨迹碰撞 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstTrackCollisionDetail         车辆轨迹碰撞详细信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTrackCollision
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_TRACK_COLLISION_DETAIL_S      *pstTrackCollisionDetail
);

/**
* 删除车辆研判:车辆轨迹碰撞 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szTrackCollisionCode            车辆轨迹碰撞编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTrackCollision
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szTrackCollisionCode[IMOS_CODE_LEN]
);

/**
* 查询车辆研判:车辆轨迹碰撞 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szTrackCollisionCode            车辆轨迹碰撞任务编码
* @param [OUT]  pstTrackCollisionDetail         车辆轨迹碰撞详细信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTrackCollision
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  CHAR                                  szTrackCollisionCode[IMOS_CODE_LEN],
    OUT VEHICLE_TRACK_COLLISION_DETAIL_S      *pstTrackCollisionDetail
);

/**
* 分页查询车辆研判:车辆轨迹碰撞列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstTrackCollisionList           车辆轨迹碰撞列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆轨迹碰撞编号]
* - #NAME_TYPE[车辆轨迹碰撞名称]
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
* 分页查询车辆研判:车辆轨迹碰撞结果列表 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstTrackCollisionResultList          轨迹碰撞结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #RESULT_CODE[结果编号]
* - #CODE_TYPE[车辆轨迹碰撞编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #PASS_TIME[通过卡口时间]
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
* 添加车辆研判:车辆首次出现 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstFirstAppearInfo              车辆首次出现信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFirstAppear
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_FIRST_APPEAR_INFO_S           *pstFirstAppearInfo
);

/**
* 删除车辆研判:车辆首次出现 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szFirstAppearCode               车辆首次出现编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelFirstAppear
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szFirstAppearCode[IMOS_CODE_LEN]
);

/**
* 分页查询车辆研判:车辆首次出现列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstFirstAppearList              车辆首次出现列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆首次出现编号]
* - #NAME_TYPE[车辆首次出现名称]
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
* 分页查询车辆研判:车辆首次出现结果列表 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstFirstAppearResultList             车辆首次出现结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #RESULT_CODE[结果编号]
* - #CODE_TYPE[车辆首次出现编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #PASS_TIME[通过卡口时间]
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
* 添加车辆研判:车辆高危时段 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstPerilTimeInfo                车辆高危时段信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPerilTime
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  VEHICLE_PERIL_TIME_INFO_S             *pstPerilTimeInfo
);

/**
* 删除车辆研判:车辆高危时段 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szPerilTimeCode                 车辆高危时段编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelPerilTime
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPerilTimeCode[IMOS_CODE_LEN]
);

/**
* 分页查询车辆研判:车辆高危时段列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstPerilTimeList                车辆高危时段列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆高危时段编号]
* - #NAME_TYPE[车辆高危时段名称]
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
* 分页查询车辆研判:车辆高危时段结果列表 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstPerilTimeResultList               车辆高危时段结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #RESULT_CODE[结果编号]
* - #CODE_TYPE[车辆高危时段编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #PASS_TIME[通过卡口时间]
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
* 添加车辆研判:车辆多次进城不出城 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstOnlyIntoCity                 多次进城不出城信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOnlyIntoCity
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLogIDInfo,
    IN  VEHICLE_ONLY_INTO_CITY_INFO_S           *pstOnlyIntoCityInfo
);

/**
* 删除车辆研判:车辆多次进城不出城 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szOnlyIntoCity                  多次进城不出城编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelOnlyIntoCity
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOnlyIntoCityCode[IMOS_CODE_LEN]
);

/**
* 分页查询车辆研判:车辆多次进城不出城列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstOnlyIntoCityList             多次进城不出城列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆多次进城不出城编号]
* - #NAME_TYPE[车辆多次进城不出城名称]
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
* 分页查询车辆研判:车辆多次进城不出城结果列表 \n
* @param [IN]   pstUserLogIDInfo                      用户登录ID信息标识
* @param [IN]   pstQueryCondition                     通用查询条件
* @param [IN]   pstQueryPageInfo                      请求分页信息
* @param [OUT]  pstRspPageInfo                        响应分页信息
* @param [OUT]  pstOnlyIntoCityResultList 多次进城不出城结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #RESULT_CODE[结果编号]
* - #CODE_TYPE[车辆多次进城不出城编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #PASS_TIME[通过卡口时间]
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
* 添加车辆研判:车辆频繁夜出 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstFrequentNightOutInfo         频繁夜出信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFrequentNightOut
(
    IN  USER_LOGIN_ID_INFO_S                        *pstUserLogIDInfo,
    IN  VEHICLE_FREQUENT_NIGHT_OUT_INFO_S           *pstFrequentNightOutInfo
);

/**
* 删除车辆研判:车辆频繁夜出 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szFrequentNightOutCode          频繁夜出编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelFrequentNightOut
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szFrequentNightOutCode[IMOS_CODE_LEN]
);

/**
* 分页查询车辆研判:车辆频繁夜出列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstFrequentNightOutList         频繁夜出列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆频繁夜出编号]
* - #NAME_TYPE[车辆频繁夜出名称]
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
* 分页查询车辆研判:车辆频繁夜出结果列表 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstFrequentNightOutResultList        频繁夜出结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #RESULT_CODE[结果编号]
* - #CODE_TYPE[车辆频繁夜出编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #PASS_TIME[通过卡口时间]
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
* 添加车辆研判:车辆昼伏夜出 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstNocturnalInfo                昼伏夜出信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddNocturnal
(
    IN  USER_LOGIN_ID_INFO_S                        *pstUserLogIDInfo,
    IN  VEHICLE_FREQUENT_NIGHT_OUT_INFO_S           *pstNocturnalInfo
);

/**
* 删除车辆研判:车辆昼伏夜出 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szNocturnalCode                 昼伏夜出编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelNocturnal
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szNocturnalCode[IMOS_CODE_LEN]
);

/**
* 分页查询车辆研判:车辆昼伏夜出列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstNocturnalList                昼伏夜出列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆昼伏夜出编号]
* - #NAME_TYPE[车辆昼伏夜出名称]
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
* 分页查询车辆研判:车辆昼伏夜出结果列表 \n
* @param [IN]   pstUserLogIDInfo                     用户登录ID信息标识
* @param [IN]   pstQueryCondition                    通用查询条件
* @param [IN]   pstQueryPageInfo                     请求分页信息
* @param [OUT]  pstRspPageInfo                       响应分页信息
* @param [OUT]  pstNocturnalResultList               昼伏夜出结果列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #RESULT_CODE[结果编号]
* - #CODE_TYPE[车辆昼伏夜出编号]
* - #VEHICLE_LICENSE_PLATE[车牌号码]
* - #PASS_TIME[通过卡口时间]
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
* 增加车辆限行 \n
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstVehicleRestrictInfo  车辆限行信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_RESTRICT_INFO_S         *pstVehicleRestrictInfo
);

/**
* 修改车辆限行 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleRestrictInfo  车辆限行信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 启动/停止车辆限行，使用IMOS_ProcessVehicleRestrict
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_RESTRICT_INFO_S         *pstVehicleRestrictInfo
);

/**
* 删除车辆限行 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleRestrictCode   车辆限行编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleRestrictCode[IMOS_CODE_LEN]
);

/**
* 查询车辆限行 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleRestrictCode   车辆限行编码
* @param [OUT]  pstVehicleRestrictInfo  车辆限行信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleRestrictCode[IMOS_CODE_LEN],
    OUT VEHICLE_RESTRICT_INFO_S         *pstVehicleRestrictInfo
);

/**
* 分页查询车辆限行基本信息列表 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              响应分页信息
* @param [OUT]  pstVehicleRestrictBaseList  车辆限行基本信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询/排序条件可以包括
* - #NAME_TYPE[限行名称]
* - #RESTRICT_TYPE[限行方式]
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
* 启动/停止车辆限行 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szVehicleRestrictCode   车辆限行编码
* @param [IN]   ulPlanStatus            BOOL_TRUE:启动; BOOL_FALSE:停止
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessVehicleRestrict
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szVehicleRestrictCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulPlanStatus
);


/**
* 查询过车数据列表v2 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   ulNestConditionNum      嵌套查询条件数量
* @param [IN]   pstNestConditionList    嵌套查询条件列表
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
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
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
* 查询过车数据列表V5(增加遮阳板，安全带，开车打电话) \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   ulNestConditionNum      嵌套查询条件数量
* @param [IN]   pstNestConditionList    嵌套查询条件列表
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleDataV4List    过车数据列表
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

/*begin added by a02842 for 新增字段MPPD41265，2016-10-14*/
/**
* 查询过车数据列表V5(增加遮阳板，安全带，开车打电话) \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   ulNestConditionNum      嵌套查询条件数量
* @param [IN]   pstNestConditionList    嵌套查询条件列表
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVehicleDataV6List    过车数据列表
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
/*end added by a02842 for 新增字段MPPD41265，2016-10-14*/

/**
* 查询过车数据数量 \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [OUT]  szVehicleCount            过车数据数量
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询过车数据数量,包含车型 \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [OUT]  szVehicleCount            过车数据数量
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
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

/*Added by yaozhongmin02844,2015-12-05，遮阳板，安全带，开车打电话*/
/**
* 查询过车数据数量,遮阳板，安全带，开车打电话 \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [OUT]  szVehicleCount            过车数据数量
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 无
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
* 查询红名单过车数据列表 \n
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
* - #PASS_TIME[通过时间/驶入卡口时间]
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
* - #VEHICLE_DEAL_STATUS[处理标记]
* - #DEPT_CODE[部门编码]
* @attention
* - 内部接口，请勿使用
* - DOMAIN_CODE和TOLLGATE_CODE不能同时使用
* - DOMAIN_CODE、TOLLGATE_CODE只能用EQUAL_FLAG逻辑关系
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
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
* 红名单车辆信息校对 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstVehicleDataV2        红名单车辆行驶记录
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention
* - 内部接口，请勿使用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleRedlist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_DATA_V2_S               *pstVehicleDataV2
);

/**
* 查询全景过车数据 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   szPassTime              过车时间
* @param [IN]   ulIntervalSec           查询全景图片时间间隔，单位:秒
* @param [OUT]  pstVehicleData          全景过车数据
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #TOLLGATE_CODE[卡口编号]
* - #LANE_NUMBER[车道号]
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_LICENSE_PLATE_TYPE[号牌种类]
* - #VEHICLE_LICENSE_PLATE_COLOR[号牌颜色]
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
* 查询报警车辆列表v2 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulResNum                资源数量
* @param [IN]   pstResList              资源列表
* @param [IN]   ulNestConditionNum      嵌套查询条件数量
* @param [IN]   pstNestConditionList    嵌套查询条件列表
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
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
* - COMBINE_FLAG[合成标识]仅支持等于/不等于，等于0，表示已合成，不等于0，表示未合成
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
* 查询报警车辆列表(内部接口，请勿使用) \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [IN]   pstQueryPageInfo          请求分页信息
* @param [OUT]  pstRspPageInfo            响应分页信息
* @param [OUT]  pstVehicleAlarmDataV2List 报警车辆列表
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
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
* - COMBINE_FLAG[合成标识]仅支持等于/不等于，等于0，表示已合成，不等于0，表示未合成
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


/*Added by yaozhongmin02844,2015-12-03，正驾驶安全带，正驾驶开车打电话*/
/**
* 查询报警车辆列表(内部接口，请勿使用) \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [IN]   pstQueryPageInfo          请求分页信息
* @param [OUT]  pstRspPageInfo            响应分页信息
* @param [OUT]  pstVehicleAlarmDataV3List 报警车辆列表
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
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
* - COMBINE_FLAG[合成标识]仅支持等于/不等于，等于0，表示已合成，不等于0，表示未合成
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

/*end Added by yaozhongmin02844,2015-12-03，正驾驶安全带，正驾驶开车打电话*/

/*begin added by a02842 for 新增字段MPPD41265，2016-10-14*/
/**
* 查询报警车辆列表(内部接口，请勿使用) \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [IN]   pstQueryPageInfo          请求分页信息
* @param [OUT]  pstRspPageInfo            响应分页信息
* @param [OUT]  pstVehicleAlarmDataV6List 报警车辆列表
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
* - 嵌套查询条件之间是与的关系，查询条件取值列表各取值之间是或的关系
* - COMBINE_FLAG[合成标识]仅支持等于/不等于，等于0，表示已合成，不等于0，表示未合成
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
/*end added by a02842 for 新增字段MPPD41265，2016-10-14*/

/**
* 查询报警车辆数量 \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulResNum                  资源数量
* @param [IN]   pstResList                资源列表
* @param [IN]   ulNestConditionNum        嵌套查询条件数量
* @param [IN]   pstNestConditionList      嵌套查询条件列表
* @param [IN]   pstQueryCondition         通用查询条件
* @param [OUT]  szAlarmCount              报警车辆数量
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询卡口平均速度 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [OUT]  pulTollgateAverageSpeed 卡口平均速度KM/H
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 查询时段不能超过24小时
        没有过车数据时,返回无效速度值 IMOS_TOLLGATE_INVALID_AVERAGE_SPEED
        卡口平均速度KM/H,以(计算值 * 1000) ULONG类型输出,保留3位小数
        通用查询条件必需包括
* - #TOLLGATE_CODE[卡口编号]
* - #LANE_DIRECTION[车道方向编号]
* - #PASS_TIME[开始时间]
* - #PASS_TIME[结束时间]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateAverageSpeed
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT ULONG_32                           *pulTollgateAverageSpeed
);

/**
* 分页查询过车特征图片:过车特征图片列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   ulNestConditionNum              嵌套查询条件数量
* @param [IN]   pstNestConditionList            嵌套查询条件列表
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstVehicleCharacterPicList      过车特征图片列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[车辆信息编号]
* - #PASS_TIME[通过时间]
*   排序条件需和需要查询的过车信息列表的排序条件一致
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
* 分页查询告警特征图片:告警特征图片列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   ulNestConditionNum              嵌套查询条件数量
* @param [IN]   pstNestConditionList            嵌套查询条件列表
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstVehicleCharacterPicList      告警特征图片列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[告警信息编号]
* - #PASS_TIME[通过时间]
*   排序条件需和需要查询的过车信息列表的排序条件一致
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
* 下载接口 \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pcHttpUrl                  Http下载URL
* @param [IN]   pcLocalFilePath            本地文件路径
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 分页查询车流量按行驶方向统计数据:车流量统计列表 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstQueryCondition               通用查询条件
* @param [IN]   pstQueryPageInfo                请求分页信息
* @param [OUT]  pstRspPageInfo                  响应分页信息
* @param [OUT]  pstVehicleRealTimeStatList      车流量统计列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 查询统计的数据不能超过24小时，支持的查询条件包括
* - #STAT_TIME[统计时间]
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
* 增加TMS多地址转发 \n
* @param [IN]   pstUserLogIDInfo                    用户登录ID信息标识
* @param [IN]   pstTMSMultiAddrForwardInfo          TMS多地址转发信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTMSMultiAddrForward
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardInfo
);

/**
* 删除TMS多地址转发 \n
* @param [IN]   pstUserLogIDInfo                    用户登录ID信息标识
* @param [IN]   szTMSMultiAddrForward               TMS转发规则编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTMSMultiAddrForward
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSMultiAddrForward[IMOS_CODE_LEN]
);

/**
* 修改TMS多地址转发 \n
* @param [IN]        pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]        pstTMSMultiAddrForwardInfo     TMS多地址转发信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTMSMultiAddrForward
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN      TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardInfo
);

/**
* 查询TMS多地址转发 \n
* @param [IN]   pstUserLogIDInfo                    用户登录ID信息标识
* @param [IN]   szTMSMultiAddrForward               TMS转发规则编号
* @param [OUT]  pstTMSMultiAddrForwardInfo          TMS多地址转发信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[转发规则编号]
* - #NAME_TYPE[转发规则名称]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTMSMultiAddrForward
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTMSMultiAddrForward[IMOS_CODE_LEN],
    OUT TMS_MULTI_ADDR_FORWARD_INFO_S   *pstTMSMultiAddrForwardInfo
);

/**
* 查询TMS多地址转发列表 \n
* @param [IN]   pstUserLogIDInfo                    用户登录ID信息标识
* @param [IN]   pstQueryCondition                   通用查询条件
* @param [IN]   pstQueryPageInfo                    请求分页信息
* @param [OUT]  pstRspPageInfo                      响应分页信息
* @param [OUT]  pstTMSMultiAddrForwardList          TMS多地址转发列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[转发规则编号]
* - #NAME_TYPE[转发规则名称]
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
* 增加卡口组配置\n
* @param [IN]   pstUserLogIDInfo              用户登录ID信息标识
* @param [IN]   pstTTollgateGroupInfo         卡口组信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateGroup
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TOLLGATE_GROUP_INFO_S   *pstTollgateGroupInfo
);

/**
* 删除卡口组 \n
* @param [IN]   pstUserLogIDInfo                   用户登录ID信息标识
* @param [IN]   szTollgateGroupCode               卡口组编号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateGroupCode[IMOS_CODE_LEN]
);

/**
* 修改卡口组 \n
* @param [IN]        pstUserLogIDInfo         用户登录ID信息标识
* @param [IN]        pstTollgateGroupInfo    卡口组信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateGroup
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      TOLLGATE_GROUP_INFO_S   *pstTollgateGroupInfo
);

/**
* 查询卡口组\n
* @param [IN]   pstUserLogIDInfo              用户登录ID信息标识
* @param [IN]   szTollgateGroupCode           卡口组编号
* @param [OUT]  pstTollgateGroupInfo          卡口组信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[卡口组编号]
* - #NAME_TYPE[卡口组名称]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateGroup
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTollgateGroupCode[IMOS_CODE_LEN],
    OUT TOLLGATE_GROUP_INFO_S   *pstTollgateGroupInfo
);
/**
* 查询卡口组列表 \n
* @param [IN]   pstUserLogIDInfo              用户登录ID信息标识
* @param [IN]   pstQueryCondition             通用查询条件
* @param [IN]   pstQueryPageInfo              请求分页信息
* @param [OUT]  pstRspPageInfo                响应分页信息
* @param [OUT]  pstTollgateGroupList          卡口组列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 支持的查询条件包括
* - #CODE_TYPE[卡口组编号]
* - #NAME_TYPE[卡口组名称]
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
* 查询违章图片合成配置信息 \n
* @param [IN]   pstUserLogIDInfo         用户登录ID信息标识
* @param [OUT]  pstViolationCombineConf  合成违章图片叠加的配置结构消息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryViolationCombineConf
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT VIOLATION_COMBINE_CONF_S    *pstViolationCombineConf
);

/**
* 修改违章图片合成配置信息 \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstViolationCombineConf    合成违章图片叠加的配置结构消息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyViolationCombineConf
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  VIOLATION_COMBINE_CONF_S    *pstViolationCombineConf
);

/* Start added by lKF0174, 2013-11-18 of MPPD06792 */
/**
* 修改过车记录/告警记录上传标志位 \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstTransFlagInfo           修改上传标志位
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 内部接口，请勿调用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleTransFlag
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  VEHICLE_TRANS_FLAG_S        *pstVehicleTransFlag
);
/* End added by lKF0174, 2013-11-18 of MPPD06792 */
/** @} */ /* end of groupSDKTollgate */

/* Begin Added by shendongchun 00400 2014-02-26 for 大数据服务器增加 */
/**
* 增加DB \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDBInfo               DB信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DB_INFO_S                       *pstDBInfo
);

/**
* 删除DB \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDBCode                DB编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDBCode[IMOS_CODE_LEN]
);

/**
* 修改DB \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDBInfo               DB信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DB_INFO_S                       *pstDBInfo
);

/**
* 查询DB \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDBCode                DB编码
* @param [OUT]  pstDBInfo               DB信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDB
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDBCode[IMOS_CODE_LEN],
    OUT DB_INFO_S                       *pstDBInfo
);

/**
* 查询DB列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#NAME_TYPE[设备名称], DEV_SUB_TYPE[设备子类型])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDBList               DB列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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

/* End Added by shendongchun 00400 2014-02-26 for 大数据服务器增加 */

#if 0
#endif

/**
* 增加IAHR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstIAHRInfo             IAHR信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IAHR_INFO_S                     *pstIAHRInfo
);

/**
* 删除IAHR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szIAHRCode              IAHR编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIAHRCode[IMOS_CODE_LEN]
);

/**
* 修改IAHR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstIAHRInfo             IAHR信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IAHR_INFO_S                     *pstIAHRInfo
);

/**
* 查询IAHR \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szIAHRCode              IAHR编码
* @param [OUT]  pstIAHRInfo             IAHR信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIAHRCode[IMOS_CODE_LEN],
    OUT IAHR_INFO_S                     *pstIAHRInfo
);

/**
* 查询IAHR列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#NAME_TYPE[设备名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstIAHRList             IAHR列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 分配IAHR存储资源 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstStoreResBasicInfo    存储资源
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 卡口系统仅支持IPSAN存储，ulStorageType必须设置为STORE_DEV_TYPE_IPSAN
*       卡口系统不支持自动选择存储设备，bAutoSelectStoreDev必须设置为填写BOOL_FALSE
*       卡口系统仅支持滚动存储方式，ulDiskFullPolicy必须设置为DISK_FULL_POLICY_OVERLOAD
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIAHRStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* 删除IAHR存储资源 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szResCode               存储资源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIAHRStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN]
);

/**
* 查询IAHR存储资源 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szResCode               存储资源编码
* @param [OUT]  pstStoreResBasicInfo    存储资源
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIAHRStoreRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szResCode[IMOS_CODE_LEN],
    OUT STORE_RES_BASIC_INFO_S          *pstStoreResBasicInfo
);

/**
* 查询IAHR存储资源列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDevCode               设备编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为,#NAME_TYPE[资源名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstStoreResBasicList    存储资源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询IAHR本地资源列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTMSCode               TMS编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTollgateLocalResList 卡口本地资源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 增加电警绑定关系 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstElecPoliceBindInfo   电警绑定信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 电警绑定的卡口列表参考资源列表方式，最大支持200个
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddElecPoliceBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ELEC_POLICE_BIND_INFO_S         *pstElecPoliceBindInfo
);

/**
* 删除电警绑定关系 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szElecPoliceCode        电警编码
* @param [IN]   szTollgateCode          卡口编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 卡口编码为空,解绑所有卡口;指定卡口编码,解绑指定卡口
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelElecPoliceBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szElecPoliceCode[IMOS_CODE_LEN],
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN]
);

/**
* 查询电警绑定关系 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szElecPoliceCode        电警编码
* @param [OUT]  pstElecPoliceBindInfo   电警绑定信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryElecPoliceBind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szElecPoliceCode[IMOS_CODE_LEN],
    OUT  ELEC_POLICE_BIND_INFO_S        *pstElecPoliceBindInfo
);

/**
* 修改/处理 交通事件 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTrafficEventInfo     交通事件信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTrafficEvent
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  TMS_TRAFFIC_EVENT_S           *pstTrafficEventInfo
);

/**
* 查询交通事件列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTrafficEventInfoList 交通事件列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件

* @note 支持的查询条件包括:
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
* 查询卡口流量信息 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDispositionCode       卡口编码
* @param [OUT]  pstDispositionInfo      流量信息结构体
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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

