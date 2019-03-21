/*************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------------
                              sdk_func_inner.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2010-04-09
        Author: w05867
   Description: SDK不对外发布的函数接口
                注意: 其中分页查询时，所需列表空间由外部申请，
                      大小根据分页查询时一页的个数进行申请。


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
* 通用查询接口
* @param [IN]       pstUserLoginID      用户登录ID信息标识
* @param [IN]       ulQryFlag           查询标志位#UNI_QUERY_FLAG_E
* @param [IN]       ulQryPieceNum       查询PIECE数目
* @param [IN]       pulQryPiecelist     查询PIECE列表
* @param [IN]       pstSdkConditon      查询约束信息
* @param [IN][OUT]  pstSdkPageInfo      查询分页信息
* @param [OUT]      oQryInfo            查询到得PIECE内容列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* - 2. 调用者工程中“C/C++ ---> 代码生成 ---> 运行时库”，必须设置为“多线程调试 DLL (/MDd)”参数。
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

/* Begin: added by zhangdong(kf0134), 2013.9.10 for 通用查询接口*/
/**
* 通用查询接口
* @param [IN] USER_LOGIN_ID_INFO_S        *pstUserLoginID       用户登录ID信息标识
* @param [IN] CHAR                         *pcSql             查询sql 语句信息
* @param [IN] ULONG                       ulQryFlag             查询标志位 #UNIVERSAL_QUERY_FLAG_E
* @param [INOUT] SDK_PAGE_S               *pstSdkPageInfo       查询分页信息
* @param [OUT] std::vector<std::string>   &oQryInfo             查询得到内容列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* - 2. 调用者工程中“C/C++ ---> 代码生成 ---> 运行时库”，必须设置为“多线程调试 DLL (/MDd)”参数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBySql
(
    IN           USER_LOGIN_ID_INFO_S        *pstUserLoginID,
    IN           ULONG_32                                    ulQryFlag,
    IN           CHAR                                     *pcSql,
    INOUT     UNI_PAGE_INFO_S                *pstPageInfo,
    OUT        std::vector<std::string>        &oQryInfo
);
/* End: added by zhangdong(kf0134), 2013.9.10 for 通用查询接口*/


#ifdef  __cplusplus
extern "C"{
#endif


/**
* 设置产品标识
* @param [IN] pstPdtInfo    产品信息
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*   - 此接口需要在IMOS_Initiate前调用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPDTInfo(IN PDT_INFO_S *pstPdtInfo);

/**
* 发送PTZ数据
* @param [IN] pstUserLogIDInfo 用户信息标识
* @param [IN] szCameCode       摄像机编码
* @param [IN] pcData           待发送的数据
* @param [IN] ulDataLen        待发送的数据长度, 最大长度为#IMOS_STRING_LEN_1024
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendPtzData
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szCameCode[IMOS_CODE_LEN],
    IN  CHAR                 *pcData,
    IN  ULONG_32                 ulDataLen
);

/**
* 设置EC实况网络适应性
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstSetNetworkAdapt       实况网络适应性信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetNetworkAdapt
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    CHAR                       szEcCode[IMOS_CODE_LEN],
    IN    NETWORK_ADAPT_INFO_S       *pstSetNetworkAdapt
);

/**
* 查询EC实况网络适应性
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [OUT]   pstSetNetworkAdapt       实况网络适应性信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNetworkAdapt
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    CHAR                        szEcCode[IMOS_CODE_LEN],
    OUT   NETWORK_ADAPT_INFO_S        *pstSetNetworkAdapt
);


/**
* 修改摄像机的视角信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstCameraViewInfo       摄像机的视角信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCameraViewInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_VIEW_INFO_S              *pstCameraViewInfo
);

/**
* 查询摄像机的视角信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szCameraCode            摄像机编码
* @param [OUT]  pstCameraViewInfo       摄像机的视角信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraViewInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    OUT CAMERA_VIEW_INFO_S              *pstCameraViewInfo
);

/**
* 增加道路信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstRoadInfo             道路信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRoadPathInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   MAP_ROAD_INFO_S             *pstRoadInfo
);

/**
* 修改道路信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstRoadInfo             道路信息，根据道路ID修改
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyRoadPathInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      MAP_ROAD_INFO_S             *pstRoadInfo
);

/**
* 删除道路信息
* @param [IN]     pstUserLogIDInfo                 用户信息
* @param [IN]     dulRoadID                        道路ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteRoadPathInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      DULONG                      dulRoadID
);

/**
* 查询道路信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstQueryPageInfo        查询分页信息
* @param [IN]     pstQueryCondition       通用查询条件(可填NULL;支持的查询条件包括:#NAME_TYPE[道路名称] #CODE_TYPE[道路ID])
* @param [OUT]    pstRspPageInfo          返回分页信息
* @param [OUT]    pstRoadInfoList         路线信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 按照 szPathCode 排列顺序
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
* 增加道路流量统计配置信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     MAP_ROAD_FLOWMETER_S    道路流量统计配置信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRoadFlowmeterInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      MAP_ROAD_FLOWMETER_S        *pstFlowmeterInfo
);

/**
* 修改道路流量统计配置信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     MAP_ROAD_FLOWMETER_S    道路流量统计配置信息,根据道路ID修改
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyRoadFlowmeterInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      MAP_ROAD_FLOWMETER_S        *pstFlowmeterInfo
);

/**
* 删除路线流量统计配置信息
* @param [IN]     pstUserLogIDInfo                 用户信息
* @param [IN]     dulRoadID                        道路ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteRoadFlowmeterInfo
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      DULONG                      dulRoadID
);

/**
* 查询路线流量统计配置信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstQueryPageInfo        查询分页信息
* @param [IN]     pstQueryCondition       通用查询条件(可填NULL;支持的查询条件包括:#CODE_TYPE[道路ID])
* @param [OUT]    pstRspPageInfo          返回分页信息
* @param [OUT]    pstFlowmeterList        道路流量统计配置信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 按照 szPathCode 排列顺序
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

/* Begin Added by zhangzeyaoKF0189, 2013-08-26 for monitorlite,查询设备信息(MWARE)*/
/**
* 设备基本信息显示\n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [OUT]  DEV_BASE_INFO_FOR_ECR_S *pstDevBaseInf      设备基本信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeviceBaseInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    OUT DEV_BASE_INFO_FOR_ECR_S             *pstDevBaseInfo
);

/**
* 设备运行信息显示\n
* 函数详细说明
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param[OUT]   pstDevRunStatus 设备实时运行信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDeviceRunStatForECR
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT DEV_RUN_STATUS_FOR_ECR_S   *pstDevRunStatus
);

/**
* 设备网卡的数量\n
* 函数详细说明
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param[OUT]   pstNicNumber    网卡数量
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNICNumberForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT NIC_NUMBER_FOR_ECR_S        *pstNicNumber
);

/**
* 设备单个网卡的信息\n
* 函数详细说明
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param[IN]      ulNICIndex    网卡的序号
* @param[OUT]     *pstNicInfo   设备单个网卡的信息
* @return ERR_COMMON_SUCCEED表示成功，失败返回请见错误码
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNICInfoForECR
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      ULONG_32                   ulNICIndex,
    OUT     NIC_INFO_FOR_ECR_S      *pstNicInfo
);
/* End   Added by zhangzeyaoKF0189, 2013-08-26 for monitorlite,查询设备信息(MWARE)*/

/**
* 查询过车数据列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    组织域编码
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
* - #CODE_TYPE[通用编码类型]
* - #PASS_TIME[通过时间/驶入卡口时间]
* - #VEHICLE_LICENSE_PLATE[号牌号码]
* - #VEHICLE_IDENTIFY_STATUS[识别状态]
* - #VEHICLE_STATUS[行驶状态]
* - #VEHICLE_DATA_TYPE[过车数据类型]
* @限制
* - 1. 该接口仅支持ECR设备
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
/* Begin AddedBy liuhongjieKF0170 2013-8-30 合入3D遮盖功能 */
/**
* @brief 3D遮盖区域信息查询\n
* @param [IN]  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo 用户信息
* @param [IN]  CHAR                            szCameraCode   摄像机编码
* @param [IN]  ULONG                           ulAreaIndex    区域索引
                                                   -- 区域索引 填写 0     查询所有的遮盖区域
                                                               填写其他   查询指定区域索引的区域信息
* @param [OUT] THREE_DIM_COVER_POSITION_STATE_S *pst3DCoverPositionState   查询到的区域信息
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_3DCoverPositionState
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                 szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                               ulAreaIndex,    /* 如果填0 查询所有的，填索引则查询该索引的area*/
    OUT THREE_DIM_COVER_POSITION_STATE_S    *pst3DCoverPositionState
);


/**
* 定位3D遮盖区域
* @param [IN]  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,  用户信息
* @param [IN]  CHAR                   szCameraCode        摄像机编码
* @param [IN]  ULONG                  ulAreaIndex         遮盖区域索引

* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_Local3DCover
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulAreaIndex
);
/* End AddedBy liuhongjieKF0170 2013-8-30 合入3D遮盖功能 */


/* Begin AddedBy liuhongjieKF0170 2013-9-4 区块OSD功能 */
/**
* 设置IPC输入通道OSD2.0信息
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         用户信息
* @param [IN]  DEV_CHANNEL_INDEX_S      *pstChannelIndex          设备通道索引信息
* @param [IN]    NEW_OSD_ROW_COMM_PARAM_S *pstOSDRowCommPara        OSD通用信息
* @param [IN]  ULONG                    ulAreaNum                 输入通道OSD块的个数
* @param [IN]  VIDEO_AREA_S             *pstArea                  OSD块信息
* @param [IN]  ULONG                    ulOSDNum,                 OSD个数
* @param [IN]  NEW_OSD_S                *pstNewOSD                输入通道OSD信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询IPC输入通道OSD2.0信息
* @param [IN]     USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         用户信息
* @param [IN]     DEV_CHANNEL_INDEX_S      *pstChannelIndex          设备通道索引信息
* @param [OUT]    NEW_OSD_ROW_COMM_PARAM_S *pstOSDRowCommPara        OSD通用信息
* @param [INOUT]  ULONG                    ulAreaNum                 输入通道OSD块的个数
* @param [OUT]    VIDEO_AREA_S             *pstArea                  OSD块信息
* @param [INOUT]  ULONG                    ulOSDNum,                 OSD个数
* @param [OUT]    NEW_OSD_S                *pstNewOSD                输入通道OSD信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
/* End AddedBy liuhongjieKF0170 2013-9-4 区块OSD功能 */
/**前端图片抓拍图片信息查询
* @param [IN]   pstUserLoginIDInfo        用户信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstOperateLogInfo       日志信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如果无通用查询条件，pstQueryCondition可以为NULL
* - 2. 支持按名称、时间、编码查询,
* -   对应通用查询条件中的查询项类型分别为:
* -   #OPER_TIME
* - 3. 若排序条件不填，将默认按照操作时间降序排序;
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
* 设置IPC输入通道OSD2.0信息V2
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         用户信息
* @param [IN]  DEV_CHANNEL_INDEX_S      *pstChannelIndex          设备通道索引信息
* @param [IN]    NEW_OSD_ROW_COMM_PARAM_S_V2 *pstOSDRowCommPara        OSD通用信息
* @param [IN]  ULONG                    ulAreaNum                 输入通道OSD块的个数
* @param [IN]  VIDEO_AREA_S_V2             *pstArea                  OSD块信息
* @param [IN]  ULONG                    ulOSDNum,                 OSD个数
* @param [IN]  NEW_OSD_S                *pstNewOSD                输入通道OSD信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询IPC输入通道OSD2.0信息
* @param [IN]     USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         用户信息
* @param [IN]     DEV_CHANNEL_INDEX_S      *pstChannelIndex          设备通道索引信息
* @param [OUT]    NEW_OSD_ROW_COMM_PARAM_S_V2 *pstOSDRowCommPara        OSD通用信息
* @param [INOUT]  ULONG                    ulAreaNum                 输入通道OSD块的个数
* @param [OUT]    VIDEO_AREA_S_V2             *pstArea                  OSD块信息
* @param [INOUT]  ULONG                    ulOSDNum,                 OSD个数
* @param [OUT]    NEW_OSD_S                *pstNewOSD                输入通道OSD信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询外域设备信息
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szInterDeviceCode       摄像机编码
* @param [IN]   szInterLocalDomainCode  本域编码
* @param [OUT]  pstDeviceInfo           查询设备信息结果
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExdomianDeviceInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],/* 这里的设备编码是本域设备编码对应的互联编码 */
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],/* 这里的本域编码是本域编码对应的国标互联编码，在中心服务器的跨域互联配置里面可看到 */
    OUT DEVICE_INFO_S                   *pstDeviceInfo
);


/* Begin Add by zhengyibing(01306), 2014-03-05 for 方圆检测PAG需求 */
/**
* 查询PAG-GB接入摄像机的目录
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szDevCode               摄像机编码
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGBCamCatalog
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_CODE_LEN]
);
/* End Add by zhengyibing(01306), 2014-03-05 for 方圆检测PAG需求 */

/**
* 开始/结束手动存储
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szCamCode               摄像机编码
* @param [IN]   szInterLocalDomainCode  本域互联编码
* @param [IN]   ulManualRecordMode      手动存储处理标记，0停止，1启动
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessManualRecordGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulManualRecordMode
);

/**
* 重启设备
* @param [IN] pstUserLogIDInfo  用户信息标识
* @param [IN] szDevCode         设备编码
* @param [IN] szInterLocalDomainCode  本域互联编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RebootDeviceGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN]
);


/**
* 手动布防处理-(手动布防，手动撤防) \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   szInterLocalDomainCode  本域互联编码
* @param [IN]   ulAlarmSrcType          告警类型
* @param [IN]   ulCtrlMode              1 手动布防，0 手动撤防
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 告警重置处理 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   szInterLocalDomainCode  本域互联编码
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AlarmResetGuobiao
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_CODE_LEN]
);


/* Begin added by z00758,2013-11-28 for 跨域智能拉框放大 */
/**
* @brief 配置云台摄像机拉框放大协议\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
* @param [IN]  CHAR                         szCameraCode   摄像机编码
* @param [IN]  ULONG                         ulZoomProtocol   拉框放大协议
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigZoomProtocol
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    IN  ULONG_32                    ulZoomProtocol
);
/* End added by z00758,2013-11-28 for 跨域智能拉框放大 */

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
* 设置监管代理的基本信息. \n
* @param [IN] USER_LOGIN_ID_INFO_S * pstUserLogIDInfo   用户信息
* @param [IN] GUARD_AGENT_INFO_FOR_ECR_S *   pstGuardAgentInfo 监管代理基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
* - 1. 修改流套餐与制式需要SDK用户调用重启设备的接口后，设备重启后设置生效.
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetGuardAgentInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  GUARD_AGENT_INFO_FOR_ECR_S  *pstGuardAgentInfo
);

/**
* 获取监管平台基本信息. \n
* @param [IN] USER_LOGIN_ID_INFO_S * pstUserLogIDInfo  用户信息
* @param [OUT] GUARD_AGENT_INFO_FOR_ECR_S * pstGuardAgentInfo 监管平台信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetGuardAgentInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT GUARD_AGENT_INFO_FOR_ECR_S  *pstGuardAgentInfo
);

/**
* 设置监管代理的基本信息. \n
* @param [IN] USER_LOGIN_ID_INFO_S *pstUserLogIDInfo   用户信息
* @param [IN] CHAR      *pszCameraCode   摄像机编码
* @param [IN] ULONG     ulCameraIndex   摄像机索引号
* @param [IN] ULONG     ulActionType   动作类型
* @param [IN] CHAR      *pszDesc   描述
* @param [IN] CHAR      *pszPictureName  图片名字
* @param [IN] ULONG     ulPictureFormat  图片格式
* @param [IN] ULONG     ulPictureSize 图片尺寸
* @param [IN] CHAR      *pastPicture 图片信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 添加IPC
* @param [IN] USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,  用户信息
* @param [IN] ADD_IPC_INFO_S         *pstIPCInfo         IPC信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddIPC
(
    IN    USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN    ADD_IPC_INFO_S             *pstIPCInfo
);

/**
* 查询IPC能力集
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo         用户信息
* @param [IN]  DEV_CHANNEL_INDEX_S      *pstChannelIndex          设备通道索引信息
* @param [OUT]  IPC_CAPABILITIES_S      *pstUniIPCCapabilities    IPC能力集信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUniIPCCapabilities
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szDeviceCode[IMOS_DEVICE_CODE_LEN],
    OUT IPC_CAPABILITIES_S        *pstUniIPCCapabilities
);

/**
* 设置输入通道移动侦测区域信息V2
* @param [IN]  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,         用户信息
* @param [IN]  DEV_CHANNEL_INDEX_S            *pstChannelIndex,          设备通道索引信息
* @param [IN]  ULONG                          ulMotionDetectAreaNum,    输入通道移动侦测区域的个数
* @param [IN]  MOTION_DETECT_AREA_S           *pstMotionDetectArea,      输入通道移动侦测区域信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMotionDetectAreaV2
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S            *pstChannelIndex,
    IN  ULONG_32                          ulMotionDetectAreaNum,
    IN  MOTION_DETECT_AREA_S           *pstMotionDetectArea
);

/**
* 查询输入通道移动侦测区域信息V2
* @param [IN]     USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,         用户信息
* @param [IN]     DEV_CHANNEL_INDEX_S           *pstChannelIndex,          设备通道索引信息
* @param [INOUT]  ULONG                         ulMotionDetectAreaNum,    输入通道移动侦测区域的个数
* @param [OUT]    MOTION_DETECT_AREA_S          *pstMotionDetectArea,      输入通道移动侦测区域信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMotionDetectAreaV2
(
    IN      USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN      DEV_CHANNEL_INDEX_S        *pstChannelIndex,
    INOUT   ULONG_32                      *pulMotionDetectAreaNum,
    OUT     MOTION_DETECT_AREA_S       *pstMotionDetectArea
);

/**
* 查询输入通道感兴趣区域信息
* @param [IN]       USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,     用户信息
* @param [IN]       DEV_CHANNEL_INDEX_S       *pstChannelIndex,      设备通道索引信息
* @param [INOUT]    ULONG                     *pulAreaNum,           输入通道感兴趣区域的个数
* @param [OUT]      ROI_AREA_S                *pstArea,              输入通道感兴趣区域信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryROIArea
(
    IN      USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN      DEV_CHANNEL_INDEX_S        *pstChannelIndex,
    INOUT   ULONG_32                      *pulAreaNum,
    OUT     ROI_AREA_S                 *pstArea
);

/**
* 设置输入通道感兴趣区域信息V2
* @param [IN]  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,        用户信息
* @param [IN]  DEV_CHANNEL_INDEX_S     *pstChannelIndex,         设备通道索引信息
* @param [IN]  ULONG                   ulROIAreaNum,             输入通道感兴趣区域的个数
* @param [IN]  ROI_AREA_S              *pstArea,                 输入通道感兴趣区域信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigROIArea
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S     *pstChannelIndex,
    IN  ULONG_32                   ulROIAreaNum,
    IN  ROI_AREA_S              *pstArea
);

/**
* 查询输入通道信息
* @param [IN]  USER_LOGIN_ID_INFO_S  pstUserLogIDInfo            用户信息
* @param [IN]  DEV_CHANNEL_INDEX_S   pstChannelIndex             设备通道索引信息
* @param [OUT] VIN_CHANNEL_EXTEND_S  pstVideoInChannelInfo       输入通道扩展信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVideoInChannelV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT VIN_CHANNEL_EXTEND_S            *pstVideoInChannelInfo
);

/**
* 设置EC输入通道通道扩展信息
* @param [IN] USER_LOGIN_ID_INFO_S  pstUserLogIDInfo            用户信息
* @param [IN] DEV_CHANNEL_INDEX_S   pstChannelIndex             设备通道索引信息
* @param [IN] VIN_CHANNEL_EXTEND_S  pstVideoInChannelInfo       输入通道扩展信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigVideoInChannelV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIN_CHANNEL_EXTEND_S            *pstVideoInChannelInfo
);

/**
* 查询IPC xml导入FTP信息\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户登录信息
* @param [OUT] FTP_INFO_S *pstFtpInfo FTP信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetIPCXMLFTPInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT FTP_INFO_S                  *pstFtpInfo
);

/**
* 界面导入xml后通知平台进行鉴权\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户登录信息
* @param [IN] CHAR szIPCXMLFilePath                 FTP路径
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckIPCXML
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szIPCXMLFilePath[IMOS_FILE_PATH_LEN]
);

/**
* 将车辆录像数据导出到DVR、NVR 本机U盘 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件，用于过滤导出的录像
* @param [IN]   szUsbFoldPath        导出U盘的路径
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExportVehicleVideoToUSBForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  CHAR    szUsbFoldPath[IMOS_FILE_PATH_LEN]
);

/**
*  查询录像导出进度\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]   pstExportProcess       导出进度信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExportVideoProcessForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT EXPORT_PROCESS_FOR_ECR_S             *pstExportProcess
);

/**
* 将车辆图片数据导出到DVR、NVR 本机U盘 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件，用于过滤导出的录像
* @param [IN]   szUsbFoldPath        导出U盘的路径
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExportVehiclePicToUSBForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  CHAR    szUsbFoldPath[IMOS_FILE_PATH_LEN]
);

/**
*  查询图片导出进度\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]   pstExportProcess       导出进度信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExportPicProcessForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT EXPORT_PROCESS_FOR_ECR_S             *pstExportProcess
);

/**
*  通过UM查询U盘信息\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]   pstUMUsbDiskInfo       U盘信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUMUsbDiskForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT UM_USB_DISK_INFO_FOR_ECR_S             *pstUMUsbDiskInfo
);

/**
*  通过UM查询U盘文件夹信息\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]   pstUMUsbDirInfo       U盘文件夹信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUMUsbDirForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT UM_USB_DIR_LIST_FOR_ECR_S                *pstUMUsbDirInfo
);

/* Begin:Added by nirenzhuo01045, 2013.05.21 for 跨域业务优化 */
/**
* 输出开关量共享处理
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]   ulShareOutputSrcNum     输出开关量数量
* @param [IN]   pstShareOutputSrcList   输出开关量共享信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 增加数据字典项 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       数据字典项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDictionaryDataForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_FOR_ECR_S               *pstDictionaryData
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
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDictionaryDataForECR
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
* @note
* - 1. 仅允许修改数据字典名称
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDictionaryDataForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_FOR_ECR_S               *pstDictionaryData
);
/**
* 根据数据类型查询数据字典枚举列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulDictionaryDataType    数据字典类型，参考#DICTIONARY_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件包括:#CODE_TYPE[数据字典编码];#NAME_TYPE[数据字典名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDictionaryDataList   数据字典枚举列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 分配MAS存储资源，针对所有的摄像头，统一分配存储资源
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstStoreMasResInfo         分配存储容量信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignMasStoreResForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAS_STORE_RES_INFO_FOR_ECR_S                *pstStoreMasResInfo
);

/**
* 扩大MAS存储资源
* @param [IN]   pstUserLogIDInfo          用户信息
* @param [IN]   pstStoreMasResInfo        扩容存储容量信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExpandMasStoreResForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAS_STORE_RES_INFO_FOR_ECR_S                *pstStoreMasResInfo
);
/* End Added by lw0581,2013-11-12 for  VVD05864*/

/* Begin Add by zhengyibing(01306), 2014-03-05 for 方圆检测PAG需求 */
/**
* @brief 查询摄像机所属的域\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
* @param [IN]  CHAR                       szCameraCode   摄像机编码
* @param [OUT] BOOL_T                     *pbIsExDomainCamara   是否为外域摄像机 ; 外域摄像机 BOOL_TRUE  本域摄像机BOOL_FALSE
* @param [OUT] BOOL_T                     *pbIsDevOnline         设备是否在线
* @param [OUT] BOOL_T                     *pbIsExDomain          是否是外域
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
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
* @brief 外域摄像机信息查询处理函数
* @param [IN]  CHAR                       szCameraCode   摄像机编码
* @param [IN]  CHAR                       szInterLocalDomainCode   本域编码
* @param [OUT] DEVICE_STATUS_S             *pstDeviceStatus 查询设备状态结果
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainCameraStatusProc
(
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_STATUS_S                 *pstDeviceStatus
);


/**
* @brief 本域摄像机状态查询处理函数
* @param [IN]  CHAR                       szCameraCode   摄像机编码
* @param [IN]  CHAR                       szInterLocalDomainCode   本域编码
* @param [OUT] DEVICE_STATUS_S             *pstDeviceStatus 查询设备状态结果
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_LoCameraStatusProc
(
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_STATUS_S                 *pstDeviceStatus
);


/**
* 查询设备状态包括外域设备和国标协议PAG接入设备
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szInterDeviceCode       摄像机编码
* @param [IN]   szInterLocalDomainCode  本域编码
* @param [OUT]  pstDeviceStatus         查询设备状态结果
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
* @note 无
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExdomianDeviceStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szInterDeviceCode[IMOS_DEVICE_CODE_LEN],
    IN  CHAR                            szInterLocalDomainCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_STATUS_S                 *pstDeviceStatus
);
/* End Add by zhengyibing(01306), 2014-03-05 for 方圆检测PAG需求 */
/** Begin:add by lw0581, 2013-12-16 for MPPD07153开关量告警恢复停止存储 **/
/**
* 创建告警联动(for ECR&NVR)
* @param [IN]   USER_LOGIN_ID_INFO_S        pstUserLogIDInfo        用户信息标识
* @param [IN]   CHAR                        szAlarmSrcCode          告警源编码
* @param [IN]   ULONG                       ulAlarmType             告警类型
* @param [IN]   ALARM_ACTION_FOR_ECR_V2_S   pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmLinkageForECRV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_V2_S      *pstAlarmAction
);

/**
* 修改告警联动信息(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmType             告警类型
* @param [IN]   pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmLinkageForECRV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_V2_S       *pstAlarmAction
);

/**
* 查询告警联动信息(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmType          告警类型
* @param [OUT]  pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkageForECRV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    OUT ALARM_ACTION_FOR_ECR_V2_S       *pstAlarmAction
);
/** End:add by lw0581, 2013-8-16 for MPPD07153 开关量告警恢复停止存储 **/

/* Begin:Added by lw0581,2013.12.16 for MPPD07154 球机转速设置保存*/
/**
* 通过摄像机编码从缓存中查询云台转速\n
* @param [IN]   USER_LOGIN_ID_INFO_S pstUserLogIDInfo   用户信息结构
* @param [IN]   CHAR   szCamCode[IMOS_CODE_LEN]               摄像机编码
* @param [OUT] ULONG *pstSDKPtzSpeed   云台速度信息
* @return   返回如下结果:
* - 成功:
* - ERR_COMMON_SUCCEED
* - 失败:
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPtzSpeed
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR szCamCode[IMOS_CODE_LEN],
    OUT ULONG_32 *pulPtzSpeed
);
/* End:Added by lw0581,2013.12.16 for MPPD07154 球机转速设置保存*/

/* Begin: added by lw0581, 2013.12.19 for  MPPD06992 */
/**
* 添加组织节点，包含编码信息 \n
* @param [IN]     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo   用户信息
* @param [INOUT]  ORG_NODE_INFO_EXTEND_FORECR_S   *pstOrgNodeInfo     组织信息(IN时,组织编码可以为空;如果为空,则OUT组织编码)
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOrganizationExtendForECR
(
    IN      USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    INOUT   ORG_NODE_INFO_EXTEND_FORECR_S  *pstOrgNodeInfo
);

/**
* 修改组织节点信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo 用户信息
* @param [IN]   ORG_NODE_INFO_EXTEND_FORECR_S   *pstOrgNodeInfo   组织节点信息
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOrganizationExtendForECR
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   ORG_NODE_INFO_EXTEND_FORECR_S  *pstOrgNodeInfo
);

/**
* 查询组织节点信息 \n
* @param [IN]    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo           用户信息
* @param [IN]    CHAR                           szOrgCode                   组织节点编码
* @param [OUT]   ORG_NODE_INFO_EXTEND_FORECR_S  *pstOrgNodeInfo             组织节点信息
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOrgInfoExtendForECR
(
    IN     USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN     CHAR                             szOrgCode[IMOS_DOMAIN_CODE_LEN],
    OUT    ORG_NODE_INFO_EXTEND_FORECR_S    *pstOrgNodeInfo
);

/**
* 获取组织下面的子组织节点列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(组织名称升序)
* @param [IN]   USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo   用户信息
* @param [IN]   CHAR                          szOrgCode           组织节点编码
* @param [IN]   COMMON_QUERY_CONDITION_S      *pstQueryCondition  通用查询条件(可填NULL;可填条件:NAME_TYPE[组织名称])
* @param [IN]   QUERY_PAGE_INFO_S             *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S               *pstRspPageInfo     返回分页信息
* @param [OUT]  ORG_NODE_INFO_EXTEND_FORECR_S *pstOrgNodeList     组织节点列表指针
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 资源转移，从组织A转移到组织B \n
* @param [IN]   USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo 用户信息
* @param [IN]   CHAR   szDesOrgCode   组织ID
* @param [IN]   ULONG   ulResNum        资源数量
* @param [IN]   RES_ITEM_V2_S   *pstResInfo   资源信息列表
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TransferResToSpecifiedOrgForECR
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szDesOrgCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                ulResNum,
    IN  RES_ITEM_V2_S        *pstResInfo
);

/**
* 根据角色编码，查询某个角色的权限信息(V2) \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   szRoleCode                   角色编码，对应唯一一个角色
* @param [IN]   pstQueryCondition            查询条件(支持的查询条件包括:#RES_ID[资源ID]
*                                                                        #RES_TYPE[资源类型]，
*                                                                        #NAME_TYPE[资源名称])
* @param [IN]   pstQueryPageInfo             请求分页信息
* @param [OUT]  pstRspPageInfo               响应分页信息
* @param [OUT]  pstResAuthorityList          角色权限列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @attention
* - 全局权限和其他权限必须分开查询。
* - 查询全局权限时，查询条件为RES_ID等于0，不能有其他查询条件，查询其他权限时，RES_ID大于0，且可以有其他查询条件。
* - 如果权限记录对应的资源不存在，出参角色权限列表中对应该资源的RES_INFO_S除szResIdCode有效，其他字段都无效。
* @note
* - 1. 该接口仅支持ECR设备
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
* 根据角色编码，设置角色权限(V2) \n
* @param [IN]   pstUserLogIDInfo      用户登录ID信息标识
* @param [IN]   szRoleCode            角色编码，对应唯一一个角色
* @param [IN]   ulResAuthorityNum     资源授权信息数量
* @param [IN]   pstResAuthorityList   资源授权信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口配置的资源范围仅限于角色所属组织和子组织
* - 2. 授予的权限可以是系统权限，也可以是针对资源（包括组织、摄像头、监视器等）的权限
* - 3. 调用该接口后, 以该次调用的权限为准，角色之前的权限会被覆盖
* - 4. ulResAuthorityNum设置为0，同时pstResAuthorityList设置为NULL，表示清除角色所有权限。
* - 5. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRoleAuthorityV2ForECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRoleCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulResAuthorityNum,
    IN  RES_AUTHORITY_FORECR_S  *pstResAuthorityList
);

/**
* 查询组织下资源信息列表(V3,返回RES_INFO_S结构，包含资源ID，不过滤权限) \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstResList                 资源信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有资源(不查子组织)
* - 2.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按"资源名称"模糊查询:#NAME_TYPE
* - 4.支持按"是否外域资源"查询:#DOMAIN_TYPE = 1 是;= 0 否
* - 5.支持按"资源类型"查询:#RES_TYPE,取值为#IMOS_TYPE_E
* - 6.支持按"资源子类型"查询:#RES_SUB_TYPE(资源类型为摄像机时,取值为#CAMERA_TYPE_E)
* - 排序
* - 1.不指定排序条件情况下,默认按"资源名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(资源名称),#CODE_TYPE(资源编码),#RES_TYPE(资源类型),#RES_SUB_TYPE(资源子类型),
* -   #DOMAIN_TYPE(是否外域资源)
* - 限制
* - 1. 该接口仅支持ECR设备
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
* 查询出当前设备下，支持指定摄像头或者所有摄像机（模拟+数字）的运动检测告警开启状态,布防计划开启状态
* 不填查询条件时,查所有
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   用户信息标识
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  通用查询条件(可填NULL;可填条件:INDEX_TYPE[开关量索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     返回分页信息
* @param [OUT]  CAMERA_MOTION_DETECT_ALARM_INFO_FOR_ECR_S *pstCameraMotionDetectInfoList 摄像头动检状态信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 查询出当前设备下，支持指定摄像头或者所有摄像机（模拟+数字）的遮挡检测告警开启状态,布防计划开启状态
* 不填查询条件时,查所有
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   用户信息标识
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  通用查询条件(可填NULL;可填条件:INDEX_TYPE[开关量索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     返回分页信息
* @param [OUT]  CAMERA_MASK_DETECT_ALARM_INFO_FOR_ECR_S *pstCameraMaskDetectInfoList 摄像头遮挡信息状态列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 指定设备或者批量查询所有设备（本地EC+IPC）的设备类告警对应的联动蜂鸣器状态 \n
* 不填查询条件时,查所有
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   用户信息标识
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  通用查询条件(可填NULL;可填条件:INDEX_TYPE[开关量索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     返回分页信息
* @param [OUT]  BUZZER_LINKED_ALARM_INFO_FOR_ECR_S *pstBuzzerLinkedAlarmInfoList 设备告警蜂鸣状态信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 扫描IPSAN \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szIpsanCode         IPSAN编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_DM_DEV_NOT_ONLINE
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ScanIpsan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szIpsanCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 触发MP扫描存储设备容量 \n
* @param [IN]  pstUserLogIDInfo  用户登录ID信息标识
* @param [IN]  szStoreDevCode    存储设备编码
* @param [IN]  ulStoreDevType    存储设备类型，枚举值: #STORE_DEV_TYPE_E
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_DM_DEV_NOT_ONLINE
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ScanStoreDev
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
	IN  CHAR                           szStoreDevCode[IMOS_DEVICE_CODE_LEN],
	IN  ULONG_32                          ulStorageType
);


/**
* 查询用户对指定资源的权限列表. \n
* 如果用户是系统管理员,则只返回"是否是系统管理员"标识,不返回权限列表;
* 如果不是系统管理员,则返回权限列表(包括系统权限和资源权限).
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   ulResType           资源类型(取值#IMOS_TYPE_E)
* @param [IN]   szResCode           资源编码
* @param [OUT]  pbIsSystemMgr       "是否是系统管理员"标识, #BOOL_TRUE为系统管理员, #BOOL_FALSE为非系统管理员
* @param [OUT]  pstAuthorityInfo    权限列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_QUERY_AUTH_NUM_EXCEED_MAX
* -     返回操作结果码，见错误码文件
* @note 如果用户为非登陆用户，用户登录 ID和用户IP为空
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
* 划归资源到目标组织 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szDesOrgCode        目标组织编码
* @param [IN]   szResCode           资源编码
* @param [IN]   ulResType           资源类型, 取值自#IMOS_TYPE_E, 目前支持的合法取值为#IMOS_TYPE_EC; #IMOS_TYPE_DC; #IMOS_TYPE_CAMERA; #IMOS_TYPE_MONITOR; #IMOS_TYPE_DM; #IMOS_TYPE_TS;#IMOS_TYPE_MS; #IMOS_TYPE_VX500
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_DAO_DEVICE_NOT_EXIST
* - #ERR_MM_DEVICE_ALREADY_IN_DOMAIN
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如果该资源没有编码，则把资源名称作为资源编码
* - 2. 一个资源可以划归到多个组织，但不能重复划归到同一个组织
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShareResToDesOrg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDesOrgCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulResType
);

/**
* 将资源从组织中解除划归 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szDesOrgCode        目标组织编码
* @param [IN]   szResCode           资源编码
* @param [IN]   ulResType           资源类型
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_CAMERA_ALREADY_SHARED
* - #ERR_MM_DEVICE_BELONG_TO_ORIGINAL_DOMAIN
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 1、如果该资源没有编码，则把资源名称作为资源编码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ReclaimResFromDesOrg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDesOrgCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szResCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                       ulResType
);

/**
* 查询组织下面的摄像机共享信息列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(摄像机名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN]   szExDomainCode     外域编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL)
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstCamShareInfo    摄像机共享信息列表指针
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1.可填通用查询条件:
*     #NAME_TYPE[摄像机名称]
*     #IS_QUERY_SHARED[查询已共享或未共享] = 0 未共享; = 1 已共享
*   2.共享查询条件不填，不进行共享过滤，结果中包含组织下所有满足其它查询条件的摄像机(未共享 + 已共享)
*   3.此接口返回结构中摄像机支持的流数目(ulStreamNum)无效
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
* 查询某个监视器所对应的解码器信息
* @param [IN] pstUserLogIDInfo              用户登录信息标识
* @param [IN] szScrCode                     监视器编码
* @param [OUT]pstScrRelatedDC               监视器对应的解码器结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenRelatedDC
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szScrCode[IMOS_CODE_LEN],
    OUT   SCREEN_RELATED_DC_S           *pstScrRelatedDC
);

/**
* 分页查询建立在设备（摄像机、监视器、播放器窗格）上的实时监控记录 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]   ulUAType                设备类型,取值范围见#IMOS_TYPE_E.注:查询窗格监控关系时,合法的取值为#IMOS_TYPE_XP(XP)
* @param [IN]   szUACode                摄像机/监视器/窗格编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstMonitorUnit          实时监控记录列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_MONITOR_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询实时监控记录列表 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstMonRecList           实时监控记录列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 只支持tbl_monitor_record内的记录
* - 2. 该接口仅支持VM平台
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
* 查询轮切记录列表 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstRecordList           轮切记录列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 只支持tbl_switch_record内的记录
* - 2. 该接口仅支持VM平台
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
* 查询监视器上正在轮切的轮切资源信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]   szMonitorCode           在硬解实况中为监视器编码; 在软解实况中为窗格编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSwitchResBase        轮切资源基本信息
* @param [OUT]  pstSwitchResUnit        轮切资源单元信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询设备上正在进行的业务信息 \n
* @param [IN]   pstUserLoginIDInfo  用户登录ID信息标识
* @param [IN]   szDevCode           设备编码
* @param [IN]   ulDevType           设备类型, 取值为#IMOS_TYPE_E, 合法的取值为#IMOS_TYPE_MONITOR(监视器), #IMOS_TYPE_XP_WIN(XP窗格)
* @param [IN]   szVirDomainCode     虚拟域编码
* @param [OUT]  pstSrvInfo          业务信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 目前只实现查询实时监控、轮切的业务状态
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
* 查询设备上正在进行的业务信息 \n
* @param [IN]   pstUserLoginIDInfo  用户登录ID信息
* @param [IN]   szDevCode           设备编码
* @param [IN]   ulDevType           设备类型, 取值为#IMOS_TYPE_E, 合法的取值为#IMOS_TYPE_MONITOR(监视器), #IMOS_TYPE_XP_WIN(XP窗格)
* @param [IN]   szVirDomainCode     虚拟域编码
* @param [OUT]  *pstSrvInfo         业务信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 目前只实现查询实时监控、轮切的业务状态
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
* 查询资源上正在进行的业务信息 \n
* @param [IN]   pstUserLoginIDInfo  用户登录ID信息标识
* @param [IN]   szResCode           资源编码
* @param [IN]   ulResType           资源类型, 取值为#IMOS_TYPE_E, 合法的取值为#IMOS_TYPE_SALVO_RESOURCE(组显示), #IMOS_TYPE_GROUP_SWITCH_RESOURCE(组轮巡)
* @param [IN]   szVirDomainCode     虚拟域编码
* @param [OUT]  pstSrvInfo          业务信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 目前只实现查询组显示的业务状态
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
* 分页查询语音广播信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]   szXPVocBrdCode          语音广播编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstVocBrdUnit           语音广播单元列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询语音业务信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]   szXPVocTalkCode         语音对讲编码
* @param [IN]   szXPVocBrdCode          语音广播编码
* @param [OUT]  szCameraCode            摄像机编码
* @param [OUT]  szCameraName            摄像机名称
* @param [OUT]  pulVoiceSrvType         语音业务类型, 取值为#SRV_TYPE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_CS_VOCTALK_NOT_EXIST
* - #ERR_CS_VOCBRD_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
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
配置XP单组播接口
****************************************************************************/
/**
* @name 配置XP单组播接口管理
* @{    配置XP单组播接口管理
*/
/**
* 配置XP单组播信息
* @param [IN]  pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]  ulStreamType                 单组播类型，0为单播，1为组播
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_XP_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 1.如果找不到xp流信息，调用该接口会返回失败
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigXPStreamType
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulStreamType
);

/**
* 查询XP单组播的信息
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [OUT]  pulStreamType                单组播类型，0为组播，1为单播
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_XP_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryXPStreamType
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulStreamType
);

/**
* 设置本域前端设备最大直连媒体流数量系统参数 \n
* @param [IN]   pstUserLogIDInfo                用户登陆信息
* @param [IN]   ulMaxMediaByPassOfTerminalDev   前端设备最大直连媒体流数量(取值范围1~3)
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 只有admin用户才有权限
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CfgMaxMediaByPassOfTerminalDev
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulMaxMediaByPassOfTerminalDev
);

/**
* 查询本域前端设备最大直连媒体流数量系统参数 \n
* @param [IN]   pstUserLogIDInfo                用户登陆信息
* @param [OUT]  pulMaxMediaByPassOfTerminalDev  前端设备最大直连媒体流数量(取值范围1~3)
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
 设备-EC,DC串口管理
*******************************************************************************/
/**
* @name 设备(EC,DC)串口管理
* @{    设备(EC,DC)串口管理
*/
/**
* 配置设备的串口信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [IN]   pstSerialInfo           串口信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_SERIAL_USED
* - #ERR_DAO_SERIAL_PORT_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfSerial
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  SERIAL_INFO_S               *pstSerialInfo
);


/**
* 分页查询设备的串口列表 \n
* 条件为空时,查询所有串口,并默认按照"串口索引升序"排序
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szDevCode              设备编码
* @param [IN]   ulDevType              设备类型，取值范围: #IMOS_TYPE_E
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;支持的查询条件包括:#INDEX_TYPE[串口索引])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstSerialList          串口列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询串口信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [OUT]  pstSerialInfo           串口信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SERIAL_PORT_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySerialInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT SERIAL_INFO_S                   *pstSerialInfo
);

/**
* 分页查询某个EC串口被相关资源占用的信息列表
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         串口通道索引信息
* @param [IN]   pstQueryPageInfo        请求分页信息(不支持偏移)
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSerialRelationList   串口被相关资源占用的信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1、支持查询的EC串口模式有:云台控制(#IMOS_SE_PTZ)、透明通道(#IMOS_SE_TRANS)
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
 设备-EC,DC OSD图片
************************************************************************************************************/


#if 0
#endif

/**
* 查询某个组织下的编码器列表  \n
    Begin modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
* 支持模糊查询。pstQueryCondition允许为空，表示该条件无效，查询该组织下所有编码器，否则按缺省进行模糊查询。默认按照"编码器名称升序"排序.
* 支持查询EC和"HC"和"HD"结尾的ECR,当查询ECR时，要额外指定设备类型为ECR，在pstQueryCondition中指定RES_TYPE为#IMOS_TYPE_ECR.
    End modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
  Begin added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* 对于设备IP查询，只支持模糊查询，不支持精确查询.
  End added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szOrgCode                   域编码
* @param [IN]   pstQueryCondition           查询信息条件(可为NULL;支持的查询条件包括:#NAME_TYPE[编码器名称]; #CODE_TYPE[编码器编码]; #RES_TYPE[资源类型]; #PHY_DEV_IP[编码器IP地址]; #CAMERA_NAME[摄像机名称])
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstEcList                   EC信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 查询条件中的摄像机名称#CAMERA_NAME只能使用LIKE_FLAG进行模糊查询, 查询的是摄像机对应的编码器
* - 2. 该接口仅支持VM平台
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
* 查询某个组织下的编码器列表  \n
    Begin modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
* 支持模糊查询。pstQueryCondition允许为空，表示该条件无效，查询该组织下所有编码器，否则按缺省进行模糊查询。默认按照"编码器名称升序"排序.
* 支持查询EC和"HC"和"HD"结尾的ECR,当查询ECR时，要额外指定设备类型为ECR，在pstQueryCondition中指定RES_TYPE为#IMOS_TYPE_ECR.
    End modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
  Begin added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* 对于设备IP查询，只支持模糊查询，不支持精确查询.
  End added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szOrgCode                   域编码
* @param [IN]   pstQueryCondition           查询信息条件(可为NULL;支持的查询条件包括:#NAME_TYPE[编码器名称]; #CODE_TYPE[编码器编码]; #RES_TYPE[资源类型]; #PHY_DEV_IP[编码器IP地址]; #CAMERA_NAME[摄像机名称])
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstEcList                   EC信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 查询条件中的摄像机名称#CAMERA_NAME只能使用LIKE_FLAG进行模糊查询, 查询的是摄像机对应的编码器
* - 2. 该接口仅支持VM平台
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


/**Begin Added by liujia ,2016-03-15 for 鱼眼配置添加*/
/**
* 查询某个组织下的编码器列表以及鱼眼表信息	\n
	Begin modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
* 支持模糊查询。pstQueryCondition允许为空，表示该条件无效，查询该组织下所有编码器，否则按缺省进行模糊查询。默认按照"编码器名称升序"排序.
* 支持查询EC和"HC"和"HD"结尾的ECR,当查询ECR时，要额外指定设备类型为ECR，在pstQueryCondition中指定RES_TYPE为IMOS_TYPE_ECR.
	End modified by gkf0050(gaoshufeng), 2012.06.11 for VVD64883
  Begin added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* 对于设备IP查询，只支持模糊查询，不支持精确查询.
  End added by gkf0050(gaoshufeng), 2012.08.06 for VVD68412
* @param [IN]	pstUserLoginIDInfo			  用户信息标识
* @param [IN]	szOrgCode					域编码
* @param [IN]	pstQueryCondition			查询信息条件(可为NULL;支持的查询条件包括:#NAME_TYPE[编码器名称]; #CODE_TYPE[编码器编码]; #RES_TYPE[资源类型]; #PHY_DEV_IP[编码器IP地址]; #CAMERA_NAME[摄像机名称])
* @param [IN]	pstQueryPageInfo			请求分页信息
* @param [OUT]	pstRspPageInfo				返回分页信息
* @param [OUT]	pstEcList					EC信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 	返回操作结果码，见错误码文件
* @note
* - 1. 查询条件中的摄像机名称#CAMERA_NAME只能使用LIKE_FLAG进行模糊查询, 查询的是摄像机对应的编码器
* - 2. 该接口仅支持VM平台
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
/**End Added by liujia ,2016-03-15 for 鱼眼配置添加*/



/**************************************************************************************************************
设备-EC,DC通道，计划以及SNMP模板管理
***************************************************************************************************************/
/** @defgroup groupTempletMg 设备(EC,DC)模板以及计划模板管理
*   设备(EC,DC)模板以及计划模板管理
*   @{
*/
/**
* @name EC模板
* @{    EC模板
*/
/**
* 增加EC通道参数模板 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   pstSDKECChannelTemplet          EC通道参数模板信息
* @param [OUT]  szECChannelTempletCode          模板编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddECChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  EC_CHANNEL_TEMPLET_S            *pstSDKECChannelTemplet,
    OUT CHAR                            szECChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* 删除EC参数模板 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szECChannelTempletCode      模板编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VIN_CHANL_TEMPL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteECChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szECChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* 修改EC参数模板 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szECChannelTempletCode      模板编码
* @param [IN]   pstSDKECChannelTemplet      EC通道参数模板信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VIN_CHANL_TEMPL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyECChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szECChannelTempletCode[IMOS_RES_CODE_LEN],
    IN  EC_CHANNEL_TEMPLET_S            *pstSDKECChannelTemplet
);


/**
* 分页查询EC通道参数模板列表 \n
* 条件为空时,查询所有模板,并默认按照"通道号升序排序"排序
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstQueryCondition          通用查询条件(可为NULL;支持的查询条件包括:#DEV_SUB_TYPE[设备子类型]; #NAME_TYPE[模板名称]; #TIME_TYPE[模板更新时间])
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstSDKECChannelTempList    EC通道参数模板列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询EC参数模板具体信息 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szECChannelTempletCode      模板编码
* @param [OUT]  pstSDKECChannelTemplet      EC通道参数模板信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VIN_CHANL_TEMPL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECChannelTemplet
(
    IN     USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN     CHAR                         szECChannelTempletCode[IMOS_RES_CODE_LEN],
    OUT    EC_CHANNEL_TEMPLET_S         *pstSDKECChannelTemplet
);
/** @} */  /* EC模板结束 */
/**
* @name DC模板
* @{    DC模板
*/
/**
* 增加DC通道参数模板 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstSDKDCChannelTemplet      DC通道参数模板信息
* @param [OUT]  szDCChannelTempletCode      模板编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DC_CHANNEL_TEMPLET_S        *pstSDKDCChannelTemplet,
    OUT CHAR                        szDCChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* 删除DC参数模板 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szDCChannelTempletCode      模板编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VOUT_CHANL_TEMPL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDCChannelTempletCode[IMOS_RES_CODE_LEN]
);

/**
* 修改DC参数模板 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szDCChannelTempletCode      模板编码
* @param [IN]   pstSDKDCChannelTemplet      DC参数模板信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VOUT_CHANL_TEMPL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDCChannelTempletCode[IMOS_RES_CODE_LEN],
    IN  DC_CHANNEL_TEMPLET_S            *pstSDKDCChannelTemplet
);


/**
* 分页查询DC通道参数模板列表 \n
* 条件为空时,查询所有模板,并默认按照"通道号升序"排序.
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstQueryCondition          通用查询条件(可为NULL;支持的查询条件包括:#DEV_SUB_TYPE[设备子类型]; #NAME_TYPE[模板名称]; #TIME_TYPE[模板更新时间])
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstSDKDCChannelTempList    DC通道参数模板列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询DC参数模板具体信息 \n
* @param [IN]   pstUserLogIDInfo                用户登录ID信息标识
* @param [IN]   szDCChannelTempletCode          模板编码
* @param [OUT]  pstSDKDCChannelTemplet          DC参数模板信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VOUT_CHANL_TEMPL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDCChannelTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDCChannelTempletCode[IMOS_RES_CODE_LEN],
    OUT DC_CHANNEL_TEMPLET_S        *pstSDKDCChannelTemplet
);
/** @} */  /* DC模板结束 */


/**
* @name 计划模板
* @{    计划模板
*/
/**
* 增加计划模板 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstSDKPlanTemplet       计划模板信息
* @param [OUT]  szPlanTempletCode       模板编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPlanTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  PLAN_TEMPLET_S              *pstSDKPlanTemplet,
    OUT CHAR                        szPlanTempletCode[IMOS_RES_CODE_LEN]
);


/**
* 删除计划模板 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szPlanTempletCode       模板编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PLAN_TEMPLET_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeletePlanTemplet
(
    IN USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN CHAR                             szPlanTempletCode[IMOS_RES_CODE_LEN]
);


/**
* 修改计划模板 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szPlanTempletCode       模板编码
* @param [IN]   pstSDKPlanTemplet       计划模板信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PLAN_TEMPLET_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyPlanTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPlanTempletCode[IMOS_RES_CODE_LEN],
    IN  PLAN_TEMPLET_S              *pstSDKPlanTemplet
);


/**
* 分页查询计划参数模板列表 \n
* 条件为空时,查询所有模板,并默认按照"模板名称升序"排序
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstQueryCondition      通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[模板名称]; #TIME_TYPE[模板更新时间])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstPlanTempList        计划模板信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询计划参数模板具体信息 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szPlanTempletCode       模板名称
* @param [OUT]  pstSDKPlanTemplet       计划模板信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PLAN_TEMPLET_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPlanTemplet
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szPlanTempletCode[IMOS_RES_CODE_LEN],
    OUT PLAN_TEMPLET_S              *pstSDKPlanTemplet
);
/** @} */  /* 计划模板结束 */
/** @} */ /* end of TEMPLET MANAGEMENT MODULE */
#if 0
#endif
/** @defgroup groupCruise 巡航业务
*   巡航业务
*   @{
*/
/**
* @name 巡航路线管理
* @{    巡航路线管理
*/
/**
* 创建巡航路线\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstCruisePathInfo   巡航路线信息
* @param [OUT]  szCruisePathCode    巡航路线编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCruisePath
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CRUISE_PATH_INFO_S      *pstCruisePathInfo,
    OUT CHAR                    szCruisePathCode[IMOS_RES_CODE_LEN]
);


/**
* 删除巡航路线 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePathCode    巡航路线编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CRUISE_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCruisePath
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN]
);


/**
* 修改巡航路线 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePathCode    巡航路线编码
* @param [IN]   pstCruisePathInfo   巡航路线信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* - #ERR_DAO_CRUISE_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCruisePath
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCruisePathCode[IMOS_RES_CODE_LEN],
    IN  CRUISE_PATH_INFO_S      *pstCruisePathInfo
);


/**
* 分页查询某个摄像机的巡航路线列表 \n
* 条件为空时,查该摄像机的所有巡航路线,并默认"巡航路线名称升序排序"
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   szCamCode              摄像机编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[路线名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstCruisePathList      巡航路线列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* @note 无
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
* 查询某个摄像机的巡航路线的详细信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePathCode    巡航路线编码
* @param [OUT]  pstCruisePathInfo   巡航路线信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* - #ERR_DAO_PRESET_VALUE_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePathInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN],
    OUT CRUISE_PATH_INFO_S          *pstCruisePathInfo
);

/**
* 手动启动巡航路线
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePathCode    巡航路线编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_NO_OUTDOMAIN_OPERATE_CRUISE
* - #ERR_DAO_CRUISE_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* - #ERR_PTZ_AUTHORITY_LOW
* - 其他返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCruisePath
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN]
);

/**
* 手动停止巡航路线
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePathCode    巡航路线编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_NO_OUTDOMAIN_OPERATE_CRUISE
* - #ERR_DAO_CRUISE_NOT_EXIST
* - #ERR_AS_CAMERA_NOT_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* - #ERR_PTZ_AUTHORITY_LOW
* - 其他返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCruisePath
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePathCode[IMOS_RES_CODE_LEN]
);

/**
* 停止摄像机下的所有手动巡航路线
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCameraCode        摄像机编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_NO_OUTDOMAIN_OPERATE_CRUISE
* - #ERR_AS_CAMERA_NOT_EXIST
* - #ERR_AS_CAMERA_OFFLINE
* - #ERR_AS_CAMERA_NOT_PTZTYPE
* - #ERR_PTZ_AUTHORITY_LOW
* - 其他返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopAllCruisePathByCam
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_DEVICE_CODE_LEN]
);
/** @} */ /* 巡航路线结束 */

#if 0
#endif
/***************************************************************************
巡航计划
****************************************************************************/
/**
* @name 巡航计划管理
* @{    巡航计划管理
*/
/**
* 创建巡航计划\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstCruisePlanInfo   巡航计划信息
* @param [OUT]  szCruisePlanCode    巡航计划编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* - #ERR_DAO_CRUISE_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CRUISE_PLAN_INFO_S          *pstCruisePlanInfo,
    OUT CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* 创建八航巡航计划
* @param [IN]	pstUserLoginIDInfo		  用户信息
* @param [IN]	pstCruisePlanInfo		巡航计划信息
* @param [OUT]	szCruisePlanCode		巡航计划编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 	返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCruisePlanV2
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CRUISE_V2_PLAN_INFO_S			*pstCruisePlanInfo,
	OUT CHAR						szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* 修改巡航计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePlanCode    巡航计划编码
* @param [IN]   pstCruisePlanInfo   巡航计划信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN],
    IN  CRUISE_PLAN_INFO_S          *pstCruisePlanInfo
);


/**
* 修改八航巡航计划
* @param [IN]	pstUserLoginIDInfo		  用户信息
* @param [IN]	szCruisePlanCode		巡航计划编码
* @param [IN]	pstCruisePlanInfo		巡航计划信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 	返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCruisePlanV2
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CHAR						szCruisePlanCode[IMOS_RES_CODE_LEN],
	IN	CRUISE_V2_PLAN_INFO_S			*pstCruisePlanInfo
);


/**
* 删除巡航计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePlanCode    巡航计划编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* 查询巡航计划\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePlanCode    巡航计划编码
* @param [OUT]  pstCruisePlanInfo   巡航计划信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CRUISEID_NOT_EXIST
* - #ERR_DAO_CAMERA_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN],
    OUT CRUISE_PLAN_INFO_S          *pstCruisePlanInfo

);



/**
* 查询八航巡航计划
* @param [IN]	pstUserLoginIDInfo		  用户信息
* @param [IN]	szCruisePlanCode		巡航计划编码
* @param [OUT]	pstCruisePlanInfo		巡航计划信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 	返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCruisePlanV2
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CHAR						szCruisePlanCode[IMOS_RES_CODE_LEN],
	OUT CRUISE_V2_PLAN_INFO_S			*pstCruisePlanInfo
);


/**
* 分页查询巡航计划列表 \n
* 条件为空时,查所有巡航计划,并默认"巡航计划名称升序"排序
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szOrgCode              组织编码
* @param [IN]   pstQueryCondition      通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[计划名称]、
* -                                    #TIME_TYPE[创建时间]、#CODE_TYPE[摄像机编码])
* @param [IN    pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstCruisePlanList      巡航计划列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* @note 目前不支持按组织查询巡航计划列表
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
* 使能巡航计划 \n
* @param [IN    pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePlanCode    巡航计划编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);


/**
* 去使能巡航计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCruisePlanCode    巡航计划编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CRUISEID_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCruisePlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCruisePlanCode[IMOS_RES_CODE_LEN]
);
/** @} */  /* 巡航计划结束 */
/** @} */ // end of groupCruise
#if 0
#endif
/***************************************************************************
告警
****************************************************************************/
/** @defgroup groupAlarm 告警管理
*   告警管理包括告警源增删改查(列表)，告警输出设备增删改查(列表)，告警联动增删改查等
*   @{
*/
/**
* 创建扩展告警源(不包括编码器,解码器,摄像机等)
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstAlarmSrc                 告警源信息
* @param [OUT]  szAlarmSrcCode              告警源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     返回操作结果码，见错误码文件
* @note 1.告警源编码不可能为空
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ALARM_SRC_S                         *pstAlarmSrc,
    OUT CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN]
);


/**
* 删除扩展告警源(不包括编码器,解码器,摄像机等)
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szAlarmSrcCode              告警源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN]
);


/**
* 修改扩展告警源信息(不包括编码器,解码器,摄像机等)
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szAlarmSrcCode              告警源编码
* @param [IN]   pstAlarmSrc                 告警源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 告警源的编码不可修改, 但在修改告警源信息时需要填写
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ALARM_SRC_S                         *pstAlarmSrc
);


/**
* 查询扩展告警源信息(不包括编码器,解码器,摄像机等)
* @param [IN]   pstUserLoginIDInfo          用户登录ID信息标识
* @param [IN]   szAlarmSrcCode              告警源编码
* @param [OUT]  pstAlarmSrc                 告警源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExAlarmSrc
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmSrcCode[IMOS_RES_CODE_LEN],
    OUT ALARM_SRC_S                         *pstAlarmSrc

);


/**
* 分页查询组织下的告警源(包括编码器,解码器,摄像机等以及扩展告警源)列表  \n
* 条件为空时,查询所有告警源,并默认按照"告警源名称升序"排序.
* @param [IN]   pstUserLogIDInfo       用户信息标识
* @param [IN]   szOrgCode              组织编码
* @param [IN]   pstQueryCondition      通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[告警源名称]、#DOMAIN_TYPE[所属域类型:0 本域,1 外域])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstAlarmSrcExList      告警源信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 创建告警输出设备
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstAlarmExporter            告警输出设备信息
* @param [OUT]  szAlarmExporterCode         告警输出设备编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 1.告警输出设备编码不可能为空
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ALARM_EXPORTER_S                    *pstAlarmExporter,
    OUT CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN]
);


/**
* 删除告警输出设备
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szAlarmExporterCode         告警输出设备编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN]
);


/**
* 修改告警输出设备信息
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szAlarmExporterCode         告警输出设备编码
* @param [IN]   pstAlarmExporter            告警输出设备信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN],
    IN  ALARM_EXPORTER_S                    *pstAlarmExporter
);


/**
* 查询告警输出设备信息
* @param [IN]   tUserLoginIDInfo            用户登录ID信息标识
* @param [IN]   szAlarmExporterCode         告警输出设备编码
* @param [OUT]  pstAlarmExporter            告警输出设备信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmExporter
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szAlarmExporterCode[IMOS_RES_CODE_LEN],
    OUT ALARM_EXPORTER_S                    *pstAlarmExporter

);


/**
* 分页查询组织下的告警输出设备列表  \n
* 条件为空时,查所有告警输出设备,并默认"告警输出设备名称升序排序"
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szOrgCode              组织编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;支持的查询条件包括:#NAME_TYPE[设备名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstAlarmExporterList   告警输出设备信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询告警信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szEventRecordCode   告警编码
* @param [OUT]  pstEventRecord      告警信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_EVENT_NOT_EXIST
 * -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarm
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szEventRecordCode[IMOS_RES_CODE_LEN],
    OUT EVENT_RECORD_S          *pstEventRecord
);


/**
* 分页查询告警信息列表
* 条件为空时,查询所有角色,并默认按照"告警时间降序"排序.
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstQueryCondition   通用查询条件(可为NULL;支持的查询条件包括:#USER_NAME_TYPE[确认用户名称];
* -                                 #NAME_TYPE[告警源名称]; #EVENT_TYPE[告警事件类型]; #EVENT_SECURITY[告警事件级别];
* -                                 #EVENT_STATUS_TYPE[告警状态]; #EVENT_TIME[告警时间]; #IS_PLAN_ALARM[是否告警预案];
* -                                 #IS_ONCE_PLAN_ALARM[是否启动过预案]; #IS_MISINFORM[是否误报] #CODE_TYPE[告警源编码];
* -                                 #CHK_USER_NAME_TYPE[核警用户名称];)
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstAlarmList        告警信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 1.告警严重级别排序从危急到提示为升序；
* -     2.告警严重级别排序从提示到危急为降序。
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
* 分页查询告警信息列表(增加所属设备名称)
* 条件为空时,查询所有角色,并默认按照"告警时间降序"排序.
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstQueryCondition   通用查询条件(可为NULL;支持的查询条件包括:#USER_NAME_TYPE[确认用户名称];
* -                                 #NAME_TYPE[告警源名称]; #EVENT_TYPE[告警事件类型]; #EVENT_SECURITY[告警事件级别];
* -                                 #EVENT_STATUS_TYPE[告警状态]; #EVENT_TIME[告警时间]; #IS_PLAN_ALARM[是否告警预案];
* -                                 #IS_ONCE_PLAN_ALARM[是否启动过预案]; #IS_MISINFORM[是否误报] #CODE_TYPE[告警源编码];
* -                                 #CHK_USER_NAME_TYPE[核警用户名称];)
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstAlarmList        告警信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 1.告警严重级别排序从危急到提示为升序；
* -     2.告警严重级别排序从提示到危急为降序。
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
* 确认告警
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szEventRecordCode       告警编码
* @param [IN]   szAckSuggestion         告警确认描述
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_EVENT_NOT_EXIST
* - #ERR_AS_ALARM_CONFIRMED
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfirmAlarm
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szEventRecordCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szAckSuggestion[IMOS_DESC_LEN]
);


/**
* 增加告警联动
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmType             告警类型, 取值为#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_LINKAGE_EXIST
* -     返回操作结果码，见错误码文件
* @note 可配置完全重复的动作，但注意例子中的情况。例：配置多次"同一个摄像机到同一个监视器", 都会配置成功，但最终只有
*       最先配置的会执行成功.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_S                  *pstAlarmAction
);


/**
* 删除告警联动
* @param [IN]  pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]  szAlarmSrcCode               告警源编码
* @param [IN]  ulAlarmType                  告警类型, 取值为#AlARM_TYPE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType
);


/**
* 修改告警联动信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmType             告警类型, 取值为#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 可配置完全重复的动作，但注意例子中的情况。例：配置多次"同一个摄像机到同一个监视器", 都会配置成功，但最终只有
*       最先的配置会执行成功.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_S                  *pstAlarmAction
);


/**
* 查询告警联动信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmSrcType          告警类型, 取值为#AlARM_TYPE_E
* @param [OUT]  pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_LINKAGE_NOT_EXIST
* - #ERR_AS_LINKAGE_NUM
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkage
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    OUT ALARM_ACTION_S                  *pstAlarmAction
);

/**
* 查询告警事件信息列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       查询条件，支持按照起止时间以及告警联动对象查询录像
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstAlarmEventInfo       告警联动信息数据结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 查询时间跨度不能大于24小时，且在录像检索流程中时间格式为："%Y-%m-%d %H:%M:%S"格式 ，信息长度限定为24字符
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
* 查询历史告警联动外域摄像机录像信息(目前仅支持外域是DA的情况) \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstAlarmLinkageStoreInfo        告警联动录像信息
* @param [OUT]  pstExDomainCamStoreInfo       外域摄像机录像存储信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
布防以及布防计划 GuardPlan Edited By sunyifan(06966)  Complete
**************************************************************************************************************/
/** @defgroup groupGPMg 布防以及布防计划管理
*   布防以及布防计划管理
*   @{
*/
/**
* 增加布防计划 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmSrcType          告警类型, 取值为#AlARM_TYPE_E
* @param [IN]   pstGuardPlanInfo        布防计划信息
* @param [OUT]  szGuardPlanCode         布防计划编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
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
* 修改布防计划 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGuardPlanCode         布防计划编码
* @param [IN]   pstGuardPlanInfo        布防计划信息结构体
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN],
    IN  GUARD_PLAN_INFO_S               *pstGuardPlanInfo
);

/**
* 删除布防计划 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGuardPlanCode         布防计划编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 查询布防计划 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGuardPlanCode         布防计划编码
* @param [OUT]  pstGuardPlanInfo        布防计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN],
    OUT GUARD_PLAN_INFO_S               *pstGuardPlanInfo
);


/**
* 分页查询布防计划列表 \n
* 条件为空时,查询所有布防计划,并默认按照"计划名称升序"排序.
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szOrgCode              组织编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[计划名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstGuardPlanList       布防计划列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 布防计划 - 查询列表(按告警源编码) \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szAlarmSrcCode      告警源编码
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstGuardPlanList    布防计划信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 控制布防计划, 包括布防计划的启动和停止 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGuardPlanCode         布防计划编码
* @param [IN]   ulCtrlMode              控制操作的类型, 1为启动; 0为停止
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GUARD_POLICY_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CtrlGuardPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGuardPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulCtrlMode
);

/**
* 手动布防处理, 包括手动布防和手动撤防 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmSrcType          告警类型
* @param [IN]   ulCtrlMode              1为手动布防, 0为手动撤防
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 返回操作结果码，见错误码文件
* @note 无
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
/** @defgroup groupGIS  GIS地图管理
*   GIS地图管理包括上传,下载,删除,设置GIS地图等接口,热点,热区,文本框,各项资源图标的增删改查(列表)等
*   @{
*/
/*--------------------------------------------GIS地图管理--------------------------------------*/

/**
* 上传GIS地图时, 将地图名称以及文件名上传到服务器进行校验, 成功后, 返回FTP服务器用户名、密码以及文件存放路径
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstGISInfo              GIS信息("地图文件名"不允许重复,即不允许重复上传"同文件名"地图)
* @param [OUT]  pstFtpInfo              FTP服务信息
* @param [OUT]  pulSequenceNumber       本次FTP服务器的序列号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_MAP_NUM_OVERFLOW
* - #ERR_AS_FIND_SAME_MAP_NAME
* - #ERR_AS_FIND_SAME_MAP_FILE_NAME
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisMapStart
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  FILE_GIS_INFO_S             *pstGISInfo,
    OUT FTP_INFO_S                  *pstFtpInfo,
    OUT ULONG_32                       *pulSequenceNumber
);

/**
* 将上传GIS地图的结果, 通知服务器
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   bIsSuccess              上传文件的结果, #BOOL_TRUE为成功; #BOOL_FALSE为失败
* @param [IN]   ulSequenceNumber        本次FTP服务器的序列号
* @param [OUT]  szGISMapCode            GIS地图编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_UPLOAD_MAP_FAIL
* - #ERR_DAO_GIS_MAP_CODE_EXIST
* - #ERR_DAO_GIS_MAP_NAME_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisMapEnd
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  BOOL_T                        bIsSuccess,
    IN  ULONG_32                         ulSequenceNumber,
    OUT CHAR                          szGISMapCode[IMOS_RES_CODE_LEN]
);

/**
* 获取GIS地图信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [OUT]  pstGISInfo              GIS地图信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MAP_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetGisMapInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    OUT FILE_GIS_INFO_S             *pstGISInfo
);



/**
* 下载GIS地图的时候，请求FTP的相关信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [OUT]  pstFtpInfo              FTP服务信息
* @param [OUT]  ulSequenceNumber        本次FTP服务器的序列号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_FIND_SAME_MAP_FILE_NAME
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisMapStart
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    OUT FTP_INFO_S                  *pstFtpInfo,
    OUT ULONG_32                       *ulSequenceNumber
);

/**
* 将下载GIS地图的结果通知服务器
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   bIsSuccess              上传文件的结果，#BOOL_TRUE为成功; #BOOL_FALSE为失败
* @param [IN]   ulSequenceNumber        本次FTP服务器的序列号
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisMapEnd
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  BOOL_T                        bIsSuccess,
    IN  ULONG_32                         ulSequenceNumber
);


/**
* 删除GIS地图
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MAP_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 注意，如果删除空文件，也返回成功：
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGisMap
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN]
);

/**
* 修改GIS地图名称
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szGisMapName            GIS地图名称
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MAP_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGisMapName
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szGisMapName[IMOS_NAME_LEN]
);


/**
* 指定组织下默认地图
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDomainCode            组织编码
* @param [IN]   szGISMapCode            GIS地图编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MAP_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetOrgDefGISMap
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                        szGISMapCode[IMOS_RES_CODE_LEN]
);


/**
* 查询组织下默认地图信息
* @param [IN]  pstUserLogIDInfo         用户登录ID信息标识
* @param [IN]  szDomainCode             组织编码
* @param [OUT] pstGisMapItem            默认地图信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MAP_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetOrgDefGISMap
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    OUT GIS_QUERY_ITEM_S            *pstGisMapItem
);

/*--------------------------------------------热点--------------------------------------*/


/**
* 在GIS地图上创建热区
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热区所在GIS地图的编码
* @param [IN]   pstHotZone              热区信息
* @param [OUT]  szHotZoneCode           热区编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTZONE_CODE_EXIST
* - #ERR_DAO_GIS_HOTZONE_NAME_EXIST
* - #ERR_DAO_GIS_HOTZONE_LINK_MAP_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateHotZone
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTZONE_S                   *pstHotZone,
    OUT CHAR                            szHotZoneCode[IMOS_RES_CODE_LEN]
);

/**
* 在GIS地图上删除热区
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热区所在GIS地图编码
* @param [IN]   szHotZoneCode           热区编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTZONE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelHotZone
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szHotZoneCode[IMOS_RES_CODE_LEN]
);


/**
* 在GIS地图上修改热区
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热区所在GIS地图编码
* @param [IN]   szHotZoneCode           热区编码
* @param [IN]   pstHotZone              热区信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTZONE_CODE_NOT_EXIST
* - #ERR_DAO_GIS_HOTZONE_NAME_EXIST
* - #ERR_DAO_GIS_HOTZONE_LINK_MAP_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyHotZone
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                        szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                        szHotZoneCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTZONE_S              *pstHotZone
);


/**
* 查询热区信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热区所在GIS地图编码
* @param [IN]   szHotZoneCode           热区编码
* @param [OUT]  pstHotZone              热区信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTZONE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHotZone
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szHotZoneCode[IMOS_RES_CODE_LEN],
    OUT GIS_HOTZONE_WITH_CODE_S     *pstHotZone
);


/**
* 分页查询某个GIS地图上的热区列表 \n
* 条件为空时,查所有热区,并默认"热区名称升序排序"
* @param [IN    pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szGISMapCode           热区所在GIS地图编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;支持的查询条件包括:#NAME_TYPE[热区名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstHotZoneList         热区列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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

/*--------------------------------------------热点--------------------------------------*/

/**
* 在GIS地图上创建热点
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热点所在GIS地图编码
* @param [IN]   pstHotSpot              热点信息
* @param [OUT]  szHotSpotCode           热点编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTSPOT_CODE_EXIST
* - #ERR_DAO_GIS_HOTSPOT_LINK_DOMAIN_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTSPOT_S                   *pstHotSpot,
    OUT CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN]
);

/**
* 在GIS地图上删除热点
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热点所在GIS地图编码
* @param [IN]   szHotSpotCode           热点编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTSPOT_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN]
);



/**
* 在GIS地图上修改热点
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热点所在GIS地图编码
* @param [IN]   szHotSpotCode           热点编码
* @param [IN]   pstHotSpot              热点信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTSPOT_CODE_NOT_EXIST
* - #ERR_DAO_GIS_HOTSPOT_LINK_DOMAIN_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN],
    IN  GIS_HOTSPOT_S                   *pstHotSpot
);


/**
* 查询热点信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            热点所在GIS地图编码
* @param [IN]   szHotSpotCode           热点编码
* @param [OUT]  pstHotSpot              热点信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_HOTSPOT_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryHotSpot
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szHotSpotCode[IMOS_RES_CODE_LEN],
    OUT GIS_HOTSPOT_WITH_CODE_S         *pstHotSpot
);


/**
* 分页查询某个GIS地图上的热点列表
* 条件为空时,查所有热点,并默认"热点编码升序排序"
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szGISMapCode           热区所在GIS地图编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;支持的查询条件包括:#CODE_TYPE[热点编码])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstHotSpotList         热点信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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

/*--------------------------------------------文本框--------------------------------------*/

/**
* 在GIS地图上创建文本框
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            文本框所在GIS地图编码
* @param [IN]   pstTextBox              文本框信息
* @param [OUT]  szTextBoxCode           文本框编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MSGBOX_CODE_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateTextBox
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_TEXTBOX_S                   *pstTextBox,
    OUT CHAR                             szTextBoxCode[IMOS_RES_CODE_LEN]
);

/**
* 在GIS地图上删除文本框
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            文本框所在GIS地图编码
* @param [IN]   szTextBoxCode           文本框编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MSGBOX_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTextBox
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szTextBoxCode[IMOS_RES_CODE_LEN]
);


/**
* 在GIS地图上修改文本框
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            文本框所在GIS地图编码
* @param [IN]   szTextBoxCode           文本框编码
* @param [IN]   pstTextBox              文本框信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MSGBOX_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTextBox
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szTextBoxCode[IMOS_RES_CODE_LEN],
    IN  GIS_TEXTBOX_S               *pstTextBox
);


/**
* 查询某个文本框信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            文本框所在GIS地图编码
* @param [IN]   szTextBoxCode           文本框编码
* @param [OUT]  pstTextBox              文本框信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_MSGBOX_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTextBox
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szTextBoxCode[IMOS_RES_CODE_LEN],
    OUT GIS_TEXTBOX_WITH_CODE_S     *pstTextBox
);


/**
* 分页查询某个GIS地图上的文本框列表 \n
* 条件为空时,查所有文本框,并默认"文本框编码升序"排序
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szGISMapCode           文本框所在GIS地图编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;支持的查询条件包括:#CODE_TYPE[文本框编码])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstTextBoxList         文本框信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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


/*-------------------------------资源图标(摄像机、告警源、告警输出)--------------------------------------*/

/**
* 在GIS地图上创建摄像机图标
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            摄像机图标所在GIS地图编码
* @param [IN]   pstCameraIcon           摄像机图标信息
* @param [OUT]  szCameraIconCode        摄像机图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_CAM_ICON_S              *pstCamIcon,
    OUT CHAR                         szCamIconCode[IMOS_RES_CODE_LEN]
);

/**
* 在GIS地图上删除摄像机图标
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szCamIconCode           摄像机图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szCamIconCode[IMOS_RES_CODE_LEN]
);


/**
* 在GIS地图上修改摄像机图标
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szCamIconCode           摄像机图标编码
* @param [IN]   pstCamIcon              摄像机图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szCamIconCode[IMOS_RES_CODE_LEN],
    IN  GIS_CAM_ICON_S              *pstCamIcon
);


/**
* 查询摄像机图标信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szCamIconCode           摄像机图标编码
* @param [OUT]  pstCamIcon              摄像机图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamIcon
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                         szCamIconCode[IMOS_RES_CODE_LEN],
    OUT GIS_CAM_ICON_WITH_CODE_S    *pstCamIcon
);


/**
* 分页查询某个GIS地图上的摄像机图标列表
* 条件为空时,查所有摄像机图标 ,并默认"摄像机图标编码升序排序"
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szGISMapCode           摄像机图标所在GIS地图编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;支持的查询条件包括:#CODE_TYPE[图标编码])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstCameraIconList      摄像机图标信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 在GIS地图上增加告警源图标
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            告警源图标所在GIS地图编码
* @param [IN]   pstAlarmSrcIcon         告警源图标信息
* @param [OUT]  szAlarmSrcIconCode      告警源图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_SRC_ICON_S            *pstAlarmSrcIcon,
    OUT CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN]
);

/**
* 在GIS地图上删除告警源图标
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            告警源图标所在GIS地图编码
* @param [IN]   szAlarmSrcIconCode      告警源图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN]
);


/**
* 在GIS地图上修改告警源图标
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szAlarmSrcIconCode      告警源图标编码
* @param [IN]   pstAlarmSrcIcon         告警源图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_SRC_ICON_S            *pstAlarmSrcIcon
);


/**
* 查询某个告警源图标信息
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szGISMapCode                GIS地图编码
* @param [IN]   szAlarmSrcIconCode          告警源图标编码
* @param [OUT]  pstAlarmSrcIcon             告警源图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmSrcIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmSrcIconCode[IMOS_RES_CODE_LEN],
    OUT GIS_ALARM_SRC_ICON_WITH_CODE_S  *pstAlarmSrcIcon
);


/**
* 分页查询某个GIS地图上的告警源图标列表
* 条件为空时,查所有告警源图标,并默认"告警源图标编码升序排序"
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szGISMapCode           告警源图标所在GIS地图编码
* @param [IN]   pstQueryCondition      通用查询条件(可为NULL;支持的查询条件包括:#CODE_TYPE[图标编码])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstAlarmSrcIconList    告警源图标信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 在GIS地图上创建告警输出图标
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szGISMapCode                告警输出图标所在GIS地图编码
* @param [IN]   pstAlarmDstIcon             告警输出图标信息
* @param [OUT]  szAlarmDstIconCode          告警输出图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_DST_ICON_S            *pstAlarmDstIcon,
    OUT CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN]
);

/**
* 在GIS地图上删除告警输出图标
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szGISMapCode                GIS地图编码
* @param [IN]   szAlarmDstIconCode          告警输出图标编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN]
);


/**
* 在GIS地图上修改告警输出图标
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szGISMapCode                GIS地图编码
* @param [IN]   szAlarmDstIconCode          告警输出图标编码
* @param [IN]   pstAlarmDstIcon             告警输出图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* - #ERR_DAO_GIS_DEV_ICON_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN],
    IN  GIS_ALARM_DST_ICON_S            *pstAlarmDstIcon
);


/**
* 查询某个告警输出图标信息
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szGISMapCode                GIS地图编码
* @param [IN]   szAlarmDstIconCode          告警输出图标编码
* @param [OUT]  pstAlarmDstIcon             告警输出图标信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GIS_ICON_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmDstIcon
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                             szGISMapCode[IMOS_RES_CODE_LEN],
    IN  CHAR                             szAlarmDstIconCode[IMOS_RES_CODE_LEN],
    OUT GIS_ALARM_DST_ICON_WITH_CODE_S  *pstAlarmDstIcon
);


/**
* 分页查询某个GIS地图上的告警输出图标列表 \n
* 条件为空时,查所有告警输出图标,并默认"告警输出图标编码升序排序"
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szGISMapCode        告警输出图标所在GIS地图编码
* @param [IN]   pstQueryCondition   通用查询条件(可填NULL;支持的查询条件包括:#CODE_TYPE[图标编码])
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstAlarmDstIconList 告警输出图标信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
透明通道 Transparent
********************************************************************************************************/
/** @defgroup groupTP 透明通道管理
*   透明通道管理
*   @{
*/
/**
* 增加透明通道,包含串口到指定地址和串口到串口
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstTransChannelInfo     透明通道的信息
* @param [OUT]  szTransChannelCode      透明通道编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SERIAL_PORT_EXIST
* -     返回操作结果码，见错误码文件
* @note 1.现只支持串口到1个IP的地址的透明通道创建,
* -     2.创建透明通道最大支持2个串口.
* -     3.只支持协议类型为UDP方式的透明通道
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  TRANSPARENT_INFO_S          *pstTransChannelInfo,
    OUT CHAR                        szTransChannelCode[IMOS_RES_CODE_LEN]
);

/**
* 删除透明通道
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTransChannelCode      透明通道编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szTransChannelCode[IMOS_RES_CODE_LEN]
);


/**
* 修改透明通道
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szTransChannelCode          透明通道编码
* @param [IN]   pstSDKTransparentChannel    透明通道信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_TL_OPENED
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* - #ERR_DAO_SERIAL_PORT_EXIST
* -     返回操作结果码，见错误码文件
* @note 1.只能修改透明通道名称与通道端描述字段,
* -     2.只支持协议类型为UDP方式的透明通道
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN],
    IN  TRANSPARENT_INFO_S              *pstSDKTransparentChannel
);



/**
* 分页查询某个组织下的透明通道列表  \n
* 条件为空时,查询所有透明通道,并默认按照"透明通道名称升序"排序.
* @param [IN]   pstUserLogIDInfo         用户信息标识
* @param [IN]   szDomainCode             组织编码
* @param [IN]   pstQueryCondition        通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[透明通道名称]; #CODE_TYPE[透明通道编码])
* @param [IN]   pstQueryPageInfo         请求分页信息
* @param [OUT]  pstRspPageInfo           响应分页信息
* @param [OUT]  pstSDKTransparentChannel 透明通道信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询透明通道信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTransChannelCode      透明通道编码
* @param [OUT]  pstSDKUpgTaskInfo       透明通道信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTransparentChannelInfo
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szTransChannelCode[IMOS_RES_CODE_LEN],
    OUT TRANSPARENT_INFO_S               *pstSDKTransparentInfo
);

/**
* 启动透明通道
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTransChannelCode      透明通道编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* - #ERR_AS_TL_DEVICE_OFFLINE
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN]
);
/**
* 停用透明通道
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTransChannelCode      透明通道编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopTransparentChannel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTransChannelCode[IMOS_RES_CODE_LEN]
);

/**
* 通过透明通道发送数据
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szTransChannelCode      透明通道编码
* @param [IN]   pData                   待发送的数据
* @param [IN]   ulDataLen               待发送的数据长度, 最大长度为#IMOS_STRING_LEN_1024
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_CHANNEL_NOT_ENABLE
* - #ERR_AS_TL_CLOSED
* - #ERR_DAO_TRANSPARENT_CHANNLE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
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
 系统管理
*******************************************************************************/
/** @defgroup groupLogMg 系统管理
*   系统管理模块包括升级管理,日志管理,License管理,信息统计管理等子模块
*   @{
*/
/**
* @name 日志管理
* @{    日志管理
*/
/* Begin added by z00758,2012-11-29 for VVD66805 */
/**根据输入日志信息添加用户操作日志
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   pstOperateLogInfo       操作日志信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOperLog
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  OPERATE_LOG_S               *pstOperateLogInfo
);
/* End added by z00758,2012-11-29 for VVD66805 */

/**
* 分页查询用户操作日志
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstQueryCondition      通用查询条件
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstOperateLogInfo      日志信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如果无通用查询条件，pstQueryCondition可以为NULL
* - 2. 支持按操作员名称、查询起/止时间、IP地址、操作类型、操作结果、业务类型、操作对象进行排序与内容查询,
* -    对应通用查询条件中的查询项类型分别为:
* -    #USER_NAME_TYPE、#OPER_TIME、#OPER_IP、#OPER_TYPE、#OPER_RESULT、#OPER_SERVICE_TYPE、#OPER_OBJ;
* - 3. 若排序条件不填，将默认按照操作时间降序排序;
* - 4. 操作时间的查询项#OPER_TIME，可以查询某段时间，#QUERY_CONDITION_ITEM_S中#ulLogicFlag中填写请参照#LOGIC_FLAG_E, 如:
* -    查询操作时间为A至B的操作日志，那么查询项为2, 查询项列表中第一(或二)数组元素中查询项类型为操作时间，
* -    查询条件逻辑关系类型为大于等于(或小于等于)，查询内容为A(或B);
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOperLog
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT OPERATE_LOG_S               *pstOperateLogInfo
);

/** @} */ /* end of 日志管理 */
#if 0
#endif
/***************************************************************************
其它
****************************************************************************/
/**
* @name 其它
* @{    其它
*/
/**
* 备份信息（包括配置信息、日志信息和数据库信息）, 并返回备份的执行结果。 \n
* @param [IN]    pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]    ulFlag                  备份类型标记, 取值为#BP_BACKUPTYPE_E
* @param [OUT]   pulStatus               当前备份状态, 取值为#BACKUP_STATUS_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 每次备份时，会删除之前的备份文件。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BackupData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                           ulFlag,
    OUT ULONG_32                           *pulStatus
);

/**
* 查询备份信息, 若系统处于非备份状态则给出其所在FTP的信息。 \n
* @param [IN]    pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]    ulFlag                  备份类型标记, 取值为#BP_BACKUPTYPE_E
* @param [OUT]   pulStatus               当前备份状态, 取值为#BACKUP_STATUS_E
* @param [OUT]   pstFtpInfo              备份文件相关的FTP信息, 信息中的文件路径包含了文件名称
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBackupInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                           ulFlag,
    OUT ULONG_32                           *pulStatus,
    OUT FTP_INFO_S                      *pstFtpInfo
);

/**
* 执行预定义的命令通用接口
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstCmdInfo              命令信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* - #ERR_AS_INVALID_NTP_IP_ADDRESS
 * -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExecutePredefinedCmd
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SDK_CMD_INFO_S                   *pstCmdInfo
);


/**
* 启动/停止服务器NTP时间同步
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulSyncFlag              同步标记，1开始，2停止
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* - #ERR_COMMON_FAIL_CALL_SYSTEM
* -     返回操作结果码，见错误码文件
* @note 无
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
* 校验License序列号的有效性 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szLicenseSerial     License序列号
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_CHECK_LICENSE_SERIAL_FAIL
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckLicenseSerial
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szLicenseSerial[IMOS_LICENSE_AUTHORITY_CODE_LENGTH]
);


/**
* 将一系列license整合生成一个license文件 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   apcLicenseSerials       授权码列表
* @param [IN]   ulLicenseSerialCount    授权码个数
* @param [IN]   pstClientInfo           客户信息
* @param [IN]   szContractId            合同编号
* @param [OUT]  pstFtpInfo              FTP服务信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_BP_GENERATE_HOST_ID_FILE_FAIL
* -     返回操作结果码，见错误码文件
* @note 无
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
* 分页获取当前生效的License授权码列表 \n
* 目前只支持一次查询所有列表，即一页的行数最好为授权码最大规格数#IMOS_LICENSE_SERIALS_MAX_NUM
* 对于分页偏移量不再关注。
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  apcSerials          授权码列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_BP_LICENSE_FILE_CANT_OPEN
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseSerialsList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT CHAR                        (*apcSerials)[IMOS_LICENSE_AUTHORITY_CODE_LENGTH]
);


/**
* 分页获取当前生效的License包含的规格信息列表 \n
* 目前只支持一次查询所有列表，即一页的行数最好为license针对的业务类型数:IMOS_LICENSE_SERVICE_TYPE_NUM
* 对于分页偏移量不再关注。
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstServiceInfoList     业务规格列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_BP_LICENSE_FILE_CANT_OPEN
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseInfoList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT LICENSE_AUTHORITYINFO_S     *pstServiceInfoList
);


/**
* 获取当前生效的License包含的规格详细信息列表V2 \n
* 目前只支持一次查询所有列表，即一页的行数最好为license针对的业务类型数:IMOS_LICENSE_SERVICE_TYPE_NUM
* 对于分页偏移量不再关注。
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       用户信息
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         返回分页信息
* @param [OUT]  LICENSE_AUTHORITYINFO_V2_S     *pstServiceInfoList     授权码列表
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1、如果查询的数目小于其查到的行数，则只返回查询的数目即对应分页查询结果中的实际查询数目.
*       2、查询结果中的总数为实际查询到的记录数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLicenseInfoList_V2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT LICENSE_AUTHORITYINFO_V2_S   *pstServiceInfoList
);

/**
* 获取当前生效的License的超时时间 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [OUT]  pstExpireDate       超时时间
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_BP_LICENSE_FILE_CANT_OPEN
* - #ERR_BP_FAIL_PARSE_LICENSE_FILE
* -     返回操作结果码，见错误码文件
* @note 无
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
升级管理 Edit By sunyifan (06966) Complete
*********************************************************************************************************/
/**
* @name 升级管理
* @{    升级管理
*/
/**
* 设置设备升级模式 \n
* 对于自动升级模式来说，不需要再设置任何升级任务
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   ulUpgMode           升级模式, 取值为#MM_UPGMODE_E
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_UPG_MODE_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetUpgMode
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                            ulUpgMode
);

/**
* 查询设备升级模式 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [OUT]  pulUpgMode         升级模式, 取值为#MM_UPGMODE_E
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUpgMode
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulUpgMode
);

/**
* 创建升级任务 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstUpgTaskInfo      升级任务信息
* @param [IN]   ulDevNum            待升级设备数组中待升级设备的实际数量, 最大取值为#UM_MAX_DEVICENUM_INJOB
* @param [IN]   pstUpgDevInfo       待升级设备数组
* @param [OUT]  szUpgTaskCode       升级任务编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_UPGRADE_DEV_NUM_ERR
* - #ERR_DAO_JOB_DEV_EXIST
* @note 无
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
* 修改升级任务信息，如果不需要修改升级设备列表，则ulDevNum和pstUpgDevInfo无效 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUpgTaskCode       升级任务编码
* @param [IN]   pstUpgTaskInfo      升级任务信息
* @param [IN]   bISModifyDevList    是否需要修改设备列表,#BOOL_TRUE为修改; #BOOL_FALSE为不修改
* @param [IN]   ulDevNum            待升级设备数组中待升级设备的实际数量, 最大取值为#UM_MAX_DEVICENUM_INJOB
* @param [IN]   pstUpgDevInfo       待升级设备数组
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_UPGRADE_DEV_NUM_ERR
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note 1.仅当任务状态为等待或挂起时, 才允许修改任务。
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
* 删除升级任务 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUpgTaskCode       升级任务编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note 可以删除已经完成的, 挂起的和处于等待状态的升级任务，在执行中的任务不能删除
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);

/**
* 挂起任务 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUpgTaskCode       升级任务编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note 当任务处于以下几种状态时，挂起任务操作会失败：
* - 当任务状态处于正在挂起，或已经挂起时
* - 当升级任务中设备均已经执行
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PauseUpgJob
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);


/**
* 激活任务 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUpgTaskCode       升级任务编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_JOB_NOT_EXIST
* - #ERR_MM_JOB_STATUS_NOT_PERMIT
* @note  当任务处于以下几种状态时，激活任务操作会失败：
* - 升级任务处于非挂起状态（等待，运行，正在挂起）
* - 升级任务过期，任务模块会自动删除过期任务
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ActiveUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN]
);


/**
* 分页查询所有升级任务  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstQueryCondition      通用查询条件
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstSDKUpgTaskList      升级任务查询信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* @note
* - 1. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 2. 支持按升级任务名称、状态、创建者、升级结果、调度/完成/制定时间排序，对应通用查询条件中的查询项类型分别为:
* -    #NAME_TYPE、#JOB_STATUS、#JOB_CREATOR、#JOB_RESULT、#JOB_EXEC_TIME、#JOB_END_TIME、#JOB_ESTB_TIME;
* - 3. 若排序条件不填，将默认按照升级任务名称升序排序;
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
* 查询升级任务信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUpgTaskCode       升级任务编码
* @param [OUT]  pstUpgTaskInfo      升级任务信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_JOB_NOT_EXIST
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUpgTask
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUpgTaskCode[IMOS_RES_CODE_LEN],
    OUT UPG_TASK_INFO_S             *pstUpgTaskInfo
);

/**
* 查询指定升级任务中的升级设备列表 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUpgTaskCode       升级任务编码
* @param [IN]   pstQueryCondition   通用查询条件
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstUpgDevInfo       待升级设备数组
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* @note
* - 1. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 2. 支持按升级设备编码、名称排序，对应通用查询条件中的查询项类型为#CODE_TYPE、#NAME_TYPE;
* - 3. 若排序条件不填，将默认按照升级设备名称升序排序;
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
* 分页查询需要升级的设备，以及设备升级版本及升级建议\n
* @param [IN]   pstUserLogIDInfo   用户登录信息
* @param [IN]   pstQueryCondition  通用查询条件
* @param [IN]   pstQueryPageInfo   请求分页信
* @param [IN]   ULONG 升级建议类型（0:所有，1:需要升级，2:不需要升级）
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstSDKUpgDevInfo   需要升级的设备以及相应版本信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* @note
* - 1. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 2. 支持按升级设备编码、名称排序，对应通用查询条件中的查询项类型为#CODE_TYPE、#NAME_TYPE;
* - 3. 若排序条件不填，将默认按照升级设备名称升序排序;
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
* 上传升级包开始,先获取上传时所需要的信息\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szFileName          文件名称
* @param [IN]   szDeviceType        设备类型
* @param [OUT]  pstFtpInfo          FTP服务信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_COMMON_DIR_FAIL_MKDIR
* - #ERR_COMMON_DIR_FAIL_REMOVE
* - #ERR_COMMON_FILE_FAIL_CHMOD
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUploadUpgPackInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szFileName[IMOS_FILE_PATH_LEN],
    IN  CHAR                    szDeviceType[IMOS_DESC_LEN],
    OUT FTP_INFO_S              *pstFtpInfo
);


/**
* 上传升级包完成,通知服务器上传成功\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   bIsSuccess          成功与否的标识, #BOOL_TRUE为成功; #BOOL_FALSE为失败
* @param [IN]   szFilePath          文件路径
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_COMMON_FILE_CANT_OPEN
* - #ERR_COMMON_DIR_FAIL_OPEN
* - #ERR_COMMON_FAIL_STAT
* - #ERR_COMMON_FILE_FAIL_CHMOD
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_NotifyUploadUpgPackResult
(
    IN USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN BOOL_T                    bIsSuccess,
    IN CHAR                      szFilePath[IMOS_FILE_PATH_LEN]
);


/**
* 上传升级配套表开始, 先获取上传时所需要的信息\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szFileName          文件名
* @param [OUT]  pstFtpInfo          FTP服务信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_COMMON_DIR_FAIL_REMOVE
* - #ERR_COMMON_DIR_FAIL_MKDIR
* - #ERR_COMMON_FILE_FAIL_CHMOD
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUploadUpgMatchListInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szFileName[IMOS_FILE_PATH_LEN],
    OUT FTP_INFO_S              *pstFtpInfo
);

/**
* 上传升级配套表完成, 通知服务器上传成功\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   bIsSuccess          成功与否的标志, #BOOL_TRUE为成功; #BOOL_FALSE为失败
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_MM_MATCHTBL_OPEN_FAIL
* @note 无
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
信息统计
*******************************************************************************/
/**
* @name 信息统计管理
* @{    信息统计管理
*/
/**
* 当前业务信息数据统计
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]  pstSrvStatInfo          统计业务信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySrvStat
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT SRV_STAT_INFO_S         *pstSrvStatInfo
);


/** @} */  /* end of 信息统计管理模块 */


/**
* 查询设备故障统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szOrgCode               组织编码
* @param [IN]       ulDevType               设备类型,取值为#IMOS_TYPE_DM, #IMOS_TYPE_MS , #IMOS_TYPE_TS,#IMOS_TYPE_VX500, #IMOS_TYPE_MONITOR, #IMOS_TYPE_EC, #IMOS_TYPE_DC, #IMOS_TYPE_CAMERA, #IMOS_TYPE_ECR, #IMOS_TYPE_DEV_ALL。若为#IMOS_TYPE_DEV_ALL则为统计所有的设备类型
* @param [IN]       ulDevBelAttr            设备归属属性，取值为#IMOS_DEV_BELONG_ATTR，当取#IMOS_DEV_BELONG_ALL时表示不分本域外域，统计所有的设备
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN][OUT]  pulArraySize            设备状态统计数组大小, 若需要统计所有的设备类型，则数组大小应该大于等于#IMOS_DEVICE_TYPE_NUM
* @param [OUT]      pstDevStatistic         设备状态统计数组
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
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
* 根据设备状态查询设备信息列表
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szOrgCode                   组织编码
* @param [IN]   ulDevStatus,                设备状态，取值为#IMOS_DEV_FAULT_STATUS_E, 当取值为#IMOS_DEV_FAULT_STATUS_ALL时表示不分状态，查询所有的设备
* @param [IN]   ulDevType                   设备类型，取值为#IMOS_TYPE_DM, #IMOS_TYPE_MS,#IMOS_TYPE_TS, #IMOS_TYPE_VX500, #IMOS_TYPE_MONITOR, #IMOS_TYPE_EC, #IMOS_TYPE_DC, #IMOS_TYPE_CAMERA, #IMOS_TYPE_ECR. 不支持查询所有(值为#IMOS_TYPE_DEV_ALL)的设备类型的设备信息列表
* @param [IN]   ulDevBelAttr                设备归属属性，取值范围见#IMOS_DEV_BELONG_ATTR, 值为#IMOS_DEV_BELONG_ALL表示不分本域外域，查询所有的设备
* @param [IN]   pstQueryCondition           通用查询条件，若无查询条件, 可以填为NULL
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              响应分页信息
* @param [OUT]  pstDevInfoArray             设备基本信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
电视墙
*******************************************************************************/
/** @defgroup groupTvWall 电视墙
*   包含电视墙的增删改查
*   @{
*/
/**
* 增加电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN][OUT]  pstTVWallInfo      电视墙信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - #ERR_MM_PARENT_RES_NOT_EXIST
* -      返回操作结果码，见错误码文件
* @note
* - 1、若电视墙信息pstTVWallInfo中电视墙编码添加时填写为空，则平台处理成功后返回编码，若填写则按照填写的编码添加;
* - 2、一个电视墙包含的最大监视器数目为#IMOS_MONITOR_MAXNUM_PER_WALL,监视器的数量可以为零;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWall
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    INOUT   TV_WALL_INFO_S          *pstTVWallInfo
);

/**
* 删除电视墙 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szTVWallCode        电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - #ERR_DAO_RES_AGG_NOT_EXIST
* -      返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWall
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTVWallCode[IMOS_CODE_LEN]
);

/**
* 修改电视墙信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstTVWallInfo      电视墙信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - #ERR_DAO_RES_AGG_NOT_EXIST
* -      返回操作结果码，见错误码文件
* @note
* - 1、电视墙信息pstTVWallInfo中电视墙编码不允许修改,填错可能导致修改失败或修改错误;
* - 2、一个电视墙包含的最大监视器数目为IMOS_MONITOR_MAXNUM_PER_WALL,监视器的数量可以为零;
* - 3、向电视墙内添加监视器，可以采用该接口实现电视墙信息的更新;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTVWall
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TV_WALL_INFO_S          *pstTVWallInfo
);

/**
* 查询电视墙详细信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szTVWallCode        电视墙编码
* @param [OUT]  pstTVWallInfo       电视墙信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - #ERR_DAO_RES_AGG_NOT_EXIST
* -      返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTVWallCode[IMOS_CODE_LEN],
    OUT TV_WALL_INFO_S          *pstTVWallInfo
);

/**
* 分页查询某个组织下的电视墙列表 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szOrgCode           组织域编码
* @param [IN]   pstQueryCondition   通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[电视墙名称])
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstTVWallList       电视墙信息列表
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* -      返回操作结果码，见错误码文件
* @note
* - 1、pstTVWallList分页中每页数组的长度必须大于或等于pstQueryPageInfo内的ulPageRowNum，否则会越界;
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
* SDK接收通知消息接口
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szDevCode                   通用设备ID
* @param [IN]   ulBufferLen                 消息长度，最大长度为:#IMOS_MAX_NOTIFY_LEN
* @param [IN]   pcBuffer                    消息内容
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 此接口目前只开放给文安项目使用
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
* 设置第三方设备轮询配置
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstPollCfg                  轮询配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetThdDevPollCfg
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    THD_DEV_POLL_CFG_S        *pstPollCfg
);

/**
* 获取第三方设备轮询配置
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [INOUT]   pstPollCfg                  轮询配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetThdDevPollCfg
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    INOUT THD_DEV_POLL_CFG_S        *pstPollCfg
);

#if 0
#endif

/**
* 添加通用设备
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstGeneralDevInfo           通用设备信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.通用设备编码不能填空,且不能包含空格
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGeneralDev
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    GENERAL_DEV_INFO_S        *pstGeneralDevInfo
);

/**
* 修改通用设备
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstGeneralDevInfo           通用设备信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGeneralDev
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    GENERAL_DEV_INFO_S        *pstGeneralDevInfo
);

/**
* 删除通用设备
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szGeneralDevCode            通用设备ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGeneralDev
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    CHAR                      szGeneralDevCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 查询某个组织下的通用设备列表  \n
* 支持按名字模糊查询。pstName允许为空，表示该条件无效，否则按名字进行模糊查询
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szOrgCode                   域编码
* @param [IN]   pstQueryCondition           通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[名称]; #CODE_TYPE[编码]; #PHY_DEV_IP[IP地址])
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  GENERAL_DEV_INFO_S          通用设备信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询某个通用的信息
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szGeneralDevCode            通用设备编码
* @param [OUT]  pstGeneralDevInfo           通用设备信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGeneralInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szGeneralDevCode[IMOS_DEVICE_CODE_LEN],
    OUT GENERAL_DEV_INFO_S              *pstGeneralDevInfo
);

/**
* 查询服务器NTP时间同步信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]  pbNTPSyncStatus         服务器NTP时间同步信息标记  pbNTPSyncStatus为#BOOL_FALSE表示停止同步，为#BOOL_TRUE表示开启同步
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryNTPSyncStatus
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT BOOL_T                          *pbNTPSyncStatus
);

#if 0
#endif

/**
* 外域 - 添加V2，包含权签信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   pstExDomain            外域信息结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddExDomainV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   EX_DOMAIN_V2_S             *pstExDomain
);


/**
* 外域 - 修改V2，编码不可修改，但需要带入
* @param [IN]  pstUserLogIDInfo          用户信息标识
* @param [IN]  pstExDomain               外域信息结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyExDomainV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   EX_DOMAIN_V2_S             *pstExDomain
);

/**
* 外域 - 查询（某个）V2
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szExDomainCode          外域编码
* @param [OUT]  pstExDomain             外域信息结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryExDomainV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    OUT  EX_DOMAIN_V2_S             *pstExDomain
);

/**
* 外域 - 查询（列表）V2 \n
* @param [IN]   pstUserLogIDInfo       用户信息标识
* @param [IN]   pstQueryCondition      通用查询条件
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         返回分页信息
* @param [OUT]  pstExDomainList        外域查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 2. 支持按外域编码、名称、类型、IP、端口、干线数量、域间组播策略、引流标志排序，对应通用查询条件中的查询项类型分别为:
* -   #CODE_TYPE、#NAME_TYPE、#EXT_DOMAIN_TPYE、#EXT_DOMAIN_IP、#EXT_DOMAIN_TRUNK_NUM、#EXT_DOMAIN_TRUNK_NUM、
* -   #EXT_DOMAIN_MULTICAST、#EXT_DOMAIN_SESSION;
* - 3. 若排序条件不填，将默认按照外域名称升序排序;
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
* 共享摄像机处理V2，可以共享，也可以取消
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]   ulShareCamNum           摄像机的个数
* @param [IN]   pstShareCamList         共享/取消摄像机列表

* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询共享的摄像机列表V2
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szExDomainCode      外域编码
* @param [IN]   ulQueryFlag         查询标记
* @param [IN]   pstQueryCondition   通用查询条件
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      返回分页信息
* @param [OUT]  pstShareCamList     查询出来摄像机列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulQueryFlag作为查询标记:0表示查本域共享给外域的摄像机，1表示查外域共享给本域的摄像机
* - 2. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 3. 支持按摄像机编码、名称排序，对应通用查询条件中的查询项类型分别为:#CODE_TYPE、#NAME_TYPE;
* - 4. 若排序条件不填，将默认按照摄像机名称升序排序;
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
* 删除外域共享资源
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   ulResType                   资源类型，取值#IMOS_TYPE_E
* @param [IN]   szResCode                   待删除的资源编码
* @param [IN]   szExdomainCode              外域编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResSharedByExdomain
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResType,
    IN  CHAR                            szResCode[IMOS_RES_CODE_LEN],
    IN  CHAR                            szExdomainCode[IMOS_DOMAIN_CODE_LEN]
);

/***************************************************************************
共享组织管理
****************************************************************************/
/**
* @name 组织共享管理
* @{    组织共享管理
*/
/**
* 组织共享处理，可以共享，也可以取消
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]   ulShareAll              共享方式: 0为仅共享组织, 1为连同其中的其它资源一并共享
* @param [IN]   ulShareOrgNum           组织的个数
* @param [IN]   pstShareOrgList         共享/取消组织列表

* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询组织下面的子组织节点共享信息列表 \n
* 不填查询条件时,查所有,并默认排序(组织名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN]   szExDomainCode     外域编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL;可填条件:#NAME_TYPE[组织名称],#IS_QUERY_SUB[是否查子组织,=1是,=0否])
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstOrgShareList    组织节点共享信息列表指针
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询共享给外域/外域共享的组织列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulQueryFlag             查询标记，0表示查本域共享给外域的组织，1表示查外域共享给本域的组织
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstShareOrgList         查询出来组织列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持按"组织名称"模糊查询和排序:#NAME_TYPE;
* - 2. 支持按"组织编码"模糊查询和排序:#CODE_TYPE;
* - 3. 若排序条件不填，将默认按照组织名称升序排序;
* - 4. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 5. 该接口仅支持VM平台
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
共享告警源管理
****************************************************************************/
/**
* @name 告警源共享管理
* @{    告警源共享管理
*/
/**
* 告警源共享处理，可以共享，也可以取消
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]   ulShareAlarmSrcNum      告警源的个数
* @param [IN]   pstShareAlarmSrcList    共享/取消告警源列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询组织下面的告警源共享信息列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(告警源名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN]   szExDomainCode     外域编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL)
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstAlmSrcShareList 告警源共享信息列表指针
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* - 1.可填通用查询条件:
*     #NAME_TYPE[告警源名称]
*     #IS_QUERY_SHARED[查询已共享或未共享] = 0 未共享; = 1 已共享
*   2.共享查询条件不填，不进行共享过滤，结果中包含组织下所有满足其它查询条件的告警源(未共享 + 已共享)
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
* 查询共享给外域/外域共享的告警源列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulQueryFlag             查询标记，0表示查本域共享给外域的告警源，1表示查外域共享给本域的告警源
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstShareAlmSrcList      查询出来告警源列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按"告警源名称"模糊查询和排序:#NAME_TYPE;
* - 2.支持按"告警源编码"模糊查询和排序:#CODE_TYPE;
* - 3.若排序条件不填，将默认按照告警源名称升序排序;
* - 4.如果无查询条件，指针pstQueryCondition可以为NULL;
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
* 查询共享给外域的告警输出列表V2
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulQueryFlag             查询标记，0表示查本域共享给外域的告警输出，1表示查外域共享给本域的告警输出
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstShareAlmOutList      查询出来的告警输出列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持按"告警输出名称"模糊查询和排序:#NAME_TYPE;
* - 2. 支持按"告警输出编码"模糊查询和排序:#CODE_TYPE;
* - 3. 若排序条件不填，将默认按照告警输出名称升序排序;
* - 4. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 5. 该接口仅支持VM平台
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
* 查询外域的共享组织和摄像机列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               外域组织编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstResList              查询出来组织和摄像机列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 设置外域资源查询策略
* @param [IN]   *pstUserLogIDInfo                    用户信息
* @param [IN]   ulExdomainResQueryPolicy             外域资源查询策略，取值#EXDOMAIN_RES_QUERY_POLICY_E
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetExdomainResQueryPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                       ulExdomainResQueryPolicy
);

/**
* 查询外域资源查询策略
* @param [IN]   *pstUserLogIDInfo       用户信息
* @param [OUT]  *pulExdomainResQueryPolicy          外域资源查询策略，取值#EXDOMAIN_RES_QUERY_POLICY_E
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QryExdomainResQueryPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  ULONG_32                      *pulExdomainResQueryPolicy
);


/***************************************************************************
共享告警输出管理
****************************************************************************/
/**
* @name 告警输出共享管理
* @{    告警输出共享管理
*/
/**
* 告警输出共享处理，可以共享，也可以取消
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]   ulShareAlarmOutNum      告警输出的个数
* @param [IN]   pstShareAlarmOutList    共享/取消告警输出列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 查询组织下面的告警输出共享信息列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(告警输出名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN]   szExDomainCode     外域编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL;可填条件:#NAME_TYPE[告警输出名称])
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstAlmOutShareList 告警输出共享信息列表指针
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 查询共享给外域的告警输出列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulQueryFlag             查询标记，0表示查本域共享给外域的告警输出，1表示查外域共享给本域的告警输出
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstShareAlmOutList      查询出来告警输出列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 设置告警输出
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szAlarmOutResCode       告警输出资源编码
* @param [IN]   ulActionType            设置动作类型，参见#ALARM_OUTPUT_SET_TYPE_E
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAlarmOut
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szAlarmOutResCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulActionType
);

/***************************************************************************
共享GIS地图管理
****************************************************************************/
/**
* @name GIS地图共享管理
* @{    GIS地图共享管理
*/
/**
* 地图共享处理，可以共享，也可以取消
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]   ulShareMapNum           地图的个数
* @param [IN]   pstShareMapList         共享/取消地图列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 建议一次共享不要超过8个地图
* - 2. 该接口仅支持VM平台
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
* 查询组织下面的地图共享信息列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(地图名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN    szExDomainCode     外域编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL)
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstMapShareList    地图共享信息列表指针
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 可填通用查询条件:
*     #NAME_TYPE[地图名称]
*     #IS_QUERY_SHARED[查询已共享或未共享] = 0 未共享; = 1 已共享
* - 2. 共享查询条件不填，不进行共享过滤，结果中包含组织下所有满足其它查询条件的地图(未共享 + 已共享)
* - 3. 该接口仅支持VM平台
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
* 查询共享给外域/外域共享的地图列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulQueryFlag             查询标记，0表示查本域共享给外域的地图，1表示查外域共享给本域的地图
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstShareMapList         查询出来地图列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持按"地图名称"模糊查询和排序:#NAME_TYPE;
* - 2. 支持按"地图编码"模糊查询和排序:#CODE_TYPE;
* - 3. 若排序条件不填，将默认按照地图名称升序排序;
* - 4. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 5. 该接口仅支持VM平台
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
资源共享关系查询
****************************************************************************/
/**
* 查询某个资源上存在的共享关系 \n
* @param [IN]   pstUserLoginIDInfo       用户登录ID信息
* @param [IN]   pstResQueryInfo          资源查询基本信息(编码和类型)
* @param [IN]   pstQueryCondition        通用查询条件(可以为NULL)
* @param [IN]   pstQueryPageInfo         请求分页信息
* @param [OUT]  pstResShareInRecord      资源被共享记录(IN)
* @param [OUT]  pstRspPageInfo           返回分页信息
* @param [OUT]  pstResShareOutRecList    资源共享记录列表(OUT)
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如是本域资源,资源被共享记录(IN)则填写本域名称和编码
* - 2. pstQueryCondition内#QUERY_CONDITION_ITEM_S的查询项类型枚举#QUERY_TYPE_E,
*       目前支持的只有#CODE_TYPE、#NAME_TYPE、#EXT_DOMAIN_TPYE
* - 3. 该接口仅支持VM平台
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
* 卡口共享处理
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulShareFlag             共享标记，1表示共享，0表示取消共享
* @param [IN]   ulTollgateNum        共享的卡口数目
* @param [IN]   pstTollgateList        卡口列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 查询共享的卡口列表
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   szExDomainCode          外域编码
* @param [IN]   ulQueryFlag             查询标记
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstTollgateList         查询出来卡口列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulQueryFlag作为查询标记:0表示查本域共享给外域的摄像机，1表示查外域共享给本域的摄像机
* - 2. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 3. 支持按摄像机编码、名称排序，对应通用查询条件中的查询项类型分别为:#CODE_TYPE、#NAME_TYPE;
* - 4. 若排序条件不填，将默认按照摄像机名称升序排序;
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
* 查询组织下面的卡口共享信息列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(卡口名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN]   szExDomainCode     外域编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL)
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstTgShareItemList    卡口共享信息列表指针
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1.可填通用查询条件:
*     #NAME_TYPE[卡口名称]
*     #IS_QUERY_SHARED[查询已共享或未共享] = 0 未共享; = 1 已共享
*   2.共享查询条件不填，不进行共享过滤，结果中包含组织下所有满足其它查询条件的卡口(未共享 + 已共享)
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
资源组配置，包含增加，修改，删除，查询，查询列表。
***************************************************************************************/
/**
* 增加资源组
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   szGroupName             资源组名称
* @param [IN]   ulGroupResType          资源组类型，枚举为#IMOS_TYPE_E，如摄像机组为#IMOS_TYPE_CAMERA_GROUP
* @param [IN]   ulResNum                组内资源数目
* @param [IN]   pstResGroupUnit         组内资源单元信息
* @param [OUT]  szResGroupCode          资源组编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 目前只支持摄像机组/监视器组的配置
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
* 修改资源组
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   szResGroupCode          资源组编码
* @param [IN]   szGroupName             资源组名称
* @param [IN]   ulGroupResType          资源组类型，枚举为#IMOS_TYPE_E，如摄像机组为#IMOS_TYPE_CAMERA_GROUP
* @param [IN]   ulResNum                组内资源数目
* @param [IN]   pstResGroupUnit         组内资源单元信息
* @param [IN]   bIsDeleteOldData        是否删除以前的元素
* @param [IN]   szExtInfo               扩展信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 目前只支持摄像机组/监视器组的配置
* - 类型为"图像拼接"时,扩展信息为"标定点信息"
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
* 删除资源组
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulGroupResType          资源组类型，枚举为#IMOS_TYPE_E，如摄像机组为#IMOS_TYPE_CAMERA_GROUP
* @param [IN]   szResGroupCode          资源组编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulGroupResType,
    IN  CHAR                            szResGroupCode[IMOS_RES_CODE_LEN]
);

/**
* 查询资源组信息
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szResGroupCode          资源组编码
* @param [IN]   ulGroupResType          资源组类型
* @param [IN]   ulCameraOperateType     操作类型，取值为#CAMERA_GROUP_OPERATE_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件(可填NULL;支持的查询条件包括:#NAME_TYPE[资源名称])
* @param [IN]   pstQueryPageInfo        查询分页信息
* @param [OUT]  szOrgCode               组织编码
* @param [OUT]  szGroupName             资源组名称
* @param [OUT]  szExtInfo               扩展信息
* @param [OUT]  pstRspPageInfo          查询返回分页信息
* @param [OUT]  pstResGroupUnit         组内资源单元信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 类型为"图像拼接"时,扩展信息为"标定点信息",类型为"摄像机组"时，资源组单元信息包括中心录像状态
* - 2. 该接口仅支持VM平台
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
* 分页查询某个组织下的资源组列表  \n
* 条件为空时,查询组织下所有资源组列表,并默认按照"资源组名称升序"排序.
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   ulGroupResType          资源组类型
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[资源组名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstResGroupList         资源组列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
布局配置，包含增加，修改，删除，查询，查询列表。
***************************************************************************************/
#if 0/* 暂时只提供查询功能 */
/**
* 增加布局
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [INOUT]  pstLayoutInfo           布局信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_AddLayout
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   LAYOUT_INFO_S               *pstLayoutInfo
);

/**
* 修改布局
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstLayoutInfo           布局信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_ModifyLayout
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   LAYOUT_INFO_S               *pstLayoutInfo
);


/**
* 删除布局
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szLayoutCode            布局编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_DelLayout
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szLayoutCode[IMOS_RES_CODE_LEN]
);
#endif

/**
* 查询布局信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szLayoutCode            布局编码
* @param [OUT]  pstLayoutInfo           布局信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLayout
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szLayoutCode[IMOS_RES_CODE_LEN],
    OUT LAYOUT_INFO_S                   *pstLayoutInfo
);

/**
* 分页查询布局列表  \n
* 条件为空时,查询所有布局列表,并默认按照"布局名称升序"排序.
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* - 可填NULL
* - 可填条件:#NAME_TYPE(布局名称),#LAYOUT_TYPE(布局类型，取值#LAYOUT_TYPE_E)
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstLayoutList           布局列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 增加组显示
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szOrgCode               组织编码
* @param [INOUT]  pstSalvoInfo            组显示信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 组显示信息中组显示编码可以为空;若入参的组显示编码为空, 则携带出内部生成的组显示编码)
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSalvoV2
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    INOUT   SALVO_INFO_V2_S             *pstSalvoInfo
);

/**
* 修改组显示
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstSalvoInfo            组显示信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySalvoV2
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN   SALVO_INFO_V2_S            *pstSalvoInfo
);

/**
* 查询组显示信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szSalvoCode             组显示编码
* @param [IN]   ulMaxUnitNum            最大查询单元数目
* @param [OUT]  pstSalvoInfo            组显示信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 增加轮切资源V2
* @param [IN]  pstUserLogIDInfo 用户登录ID信息标识
* @param [IN]  szOrgCode        组织编码
* @param [IN]  pstSwitchInfo    轮切资源信息
* @param [OUT] szSwitchResCode  轮切资源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_GUARDTOUR_TIMESLOT_EXCEEDED
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSwitchResourceV2
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szOrgCode[IMOS_CODE_LEN],
    IN  SWITCH_RESOURE_V2_S  *pstSwitchInfo,
    OUT CHAR                  szSwitchResCode[IMOS_CODE_LEN]
);

/**
* 修改轮切资源V2
* @param [IN] pstUserLogIDInfo 用户登录ID信息标识
* @param [IN] szSwitchResCode  轮切资源编码
* @param [IN] pstSwitchInfo    轮切资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_GUARDTOUR_TIMESLOT_EXCEEDED
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySwitchResourceV2
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szSwitchResCode[IMOS_CODE_LEN],
    IN  SWITCH_RESOURE_V2_S  *pstSwitchInfo
);

/**
* 查询轮切资源V2
* @param [IN]  pstUserLogIDInfo 用户登录ID信息标识
* @param [IN]  szSwitchResCode  轮切资源编码
* @param [OUT] pstSwitchInfo    轮切资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SWITCH_ID_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchResourceV2
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                  szSwitchResCode[IMOS_CODE_LEN],
    OUT SWITCH_RESOURE_V2_S  *pstSwitchInfo
);

#if 0
#endif

/* Begin Added by dengshuhua00673, 2012-11-28 of 自动布局轮巡 */
/**
* 增加通用轮切资源
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstSwitchInfo           通用轮切资源信息
* @param [OUT]  szSwitchResCode         通用轮切资源编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前只支持组轮巡
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommonSwitchResV2
(
    IN  USER_LOGIN_ID_INFO_S	    *pstUserLogIDInfo,
    IN  CHAR	                    szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  COMMON_SWITCH_RESOURCE_V2_S	*pstSwitchInfo,
    OUT CHAR	                    szSwitchResCode[IMOS_RES_CODE_LEN]
);

/**
* 修改通用轮切资源
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szSwitchResCode         通用轮切资源编码
* @param [IN]   pstSwitchInfo           通用轮切资源信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommonSwitchResV2
(
    IN  USER_LOGIN_ID_INFO_S	    *pstUserLogIDInfo,
    IN  CHAR	                    szSwitchResCode[IMOS_RES_CODE_LEN],
    IN  COMMON_SWITCH_RESOURCE_V2_S	*pstSwitchInfo
);

/**
* 查询通用轮切资源信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulSwitchType            轮切类型，取值为#COMMON_SWITCH_TYPE_E
* @param [IN]   szSwitchResCode         通用轮切资源编码
* @param [OUT]  pstSwitchInfo           通用轮切资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchResV2
(
    IN  USER_LOGIN_ID_INFO_S	    *pstUserLogIDInfo,
    IN  ULONG_32	                    ulSwitchType,
    IN  CHAR	                    szSwitchResCode[IMOS_RES_CODE_LEN],
    OUT COMMON_SWITCH_RESOURCE_V2_S	*pstSwitchInfo
);

/**
* 分页查询某个组织下的通用轮切资源列表V2  \n
* 条件为空时,查询组织下所有通用轮切资源列表,并默认按照"轮切资源名称升序"排序.
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   ulSwitchType            轮切类型，取值为#COMMON_SWITCH_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件
* - 可填NULL
* - 可填条件:#NAME_TYPE(轮切资源名称),#RES_SUB_TYPE(轮切子类型，对组轮巡取值#GROUP_SWITCH_TYPE_E)
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSwitchResList        通用轮切资源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
/* End Added by dengshuhua00673, 2012-11-28 of 自动布局轮巡 */

/* Begin Added by gKF0090, 2012-12-27 of 查询摄像机组轮巡信息 */
/**
* 查询摄像机上的组轮巡信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szUACode                摄像机编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstGroupSwitchResList   组轮巡列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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

/* End Added by gKF0090, 2012-12-27 of 查询摄像机组轮巡信息 */

/*************************************************************************************
通用轮切计划配置，包含增加，修改，删除，查询，查询列表。
***************************************************************************************/
/**
* 增加通用轮切计划
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstSwitchPlanInfo       通用轮切计划信息
* @param [OUT]  szSwitchPlanCode        通用轮切计划编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_SWITCH_PLAN_INFO_S       *pstSwitchPlanInfo,
    OUT CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);


/**
* 修改通用轮切计划
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szSwitchPlanCode        轮切计划编码
* @param [IN]   pstSwitchPlanInfo       轮切计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    IN  COMMON_SWITCH_PLAN_INFO_S       *pstSwitchPlanInfo
);


/**
* 删除通用轮切计划
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulSwitchPlanType        通用轮切计划类型，取值为#COMMON_SWITCH_PLANTYPE_E
* @param [IN]   szSwitchPlanCode        通用轮切计划编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulSwitchPlanType,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 查询通用轮切计划信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   ulSwitchPlanType        通用轮切计划类型，取值为#COMMON_SWITCH_PLANTYPE_E
* @param [IN]   szSwitchPlanCode        通用轮切计划编码
* @param [OUT]  pstSwitchPlanInfo       通用轮切计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommonSwitchPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulSwitchPlanType,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    OUT COMMON_SWITCH_PLAN_INFO_S       *pstSwitchPlanInfo
);

/**
* 分页查询通用轮切计划列表
* 条件为空时,查询所有通用轮切计划,并默认按照"通用轮切计划名称升序"排序.
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   ulSwitchPlanType        通用轮切计划类型，取值为#COMMON_SWITCH_PLANTYPE_E
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[轮切计划名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSwitchPlanList       通用轮切计划列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
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
* 添加厂商信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstFactoryInfo      厂商类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddManufacturerType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  MANUFACTURER_TYPE_INFO_S            *pstManufacturerInfo
);

/**
* 删除厂商信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   ulFactoryTypeId     厂商类型信息ID
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelManufacturerType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ULONG_32                               ulManufacturerTypeId
);

/**
* 修改厂商信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstFactoryInfo      厂商类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyManufacturerType
(
    IN    USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN    MANUFACTURER_TYPE_INFO_S            *pstManufacturerInfo
);

/**
* 查询厂商信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   ulTypeId           类型ID
* @param [OUT]  pstFactoryInfo     类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_MANUFACUTURER_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManufacturerType
(
    IN   USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  ULONG_32                              ulManufacturerTypeId,
    OUT  MANUFACTURER_TYPE_INFO_S          *pstManufacturerInfo
);

/**
* 查询厂商类型列表 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstQueryCondition  通用查询条件
* @param [IN]   pstQueryPageInfo   查询分页信息
* @param [OUT]  pstRspPageInfo     查询返回分页信息
* @param [OUT]  pstFactoryInfoList 类型信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 添加设备类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstDevTypeInfo     设备类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEV_TYPE_NOT_EXIST 设备类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDevType
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  DEV_TYPE_INFO_S                *pstDevTypeInfo
);

/**
* 删除设备类型信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   ulDevTypeId         设备信息类型ID
* @param [IN]   ulDevSubTypeID      设备信息子类型ID
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEV_TYPE_NOT_EXIST 设备类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDevType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ULONG_32                               ulDevTypeId,
    IN  ULONG_32                               ulDevSubTypeID
);

/**
* 修改设备类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstDevTypeInfo     设备类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEV_TYPE_NOT_EXIST 设备类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDevType
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    DEV_TYPE_INFO_S                *pstDevTypeInfo
);

/**
* 查询设备类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   ulTypeId           类型ID
* @param [IN]   ulDevSubTypeId     设备信息子类型ID
* @param [OUT]  pstDevTypeInfo     设备类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEV_TYPE_NOT_EXIST 设备类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevType
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   ULONG_32                          ulDevTypeId,
    IN   ULONG_32                          ulDevSubTypeId,
    OUT  DEV_TYPE_INFO_S                *pstDevTypeInfo
);

/**
* 查询设备类型列表 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstQueryCondition  通用查询条件
* @param [IN]   pstQueryPageInfo   查询分页信息
* @param [OUT]  pstRspPageInfo     查询返回分页信息
* @param [OUT]  pstDevTypeInfoList 类型信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 添加事件类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstEventType       事件类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_EVENT_TYPE_ID_EXIST 事件类型ID已存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_TYPE_S                *pstEventType
);

/**
* 删除事件类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   ulDevTypeId        事件信息类型ID
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_EVENT_TYPE_NOT_EXIST 事件类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventType
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  ULONG_32                               ulEventTypeId
);

/**
* 修改事件类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstEventType       事件类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_EVENT_TYPE_NOT_EXIST 事件类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEventType
(
    IN    USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN    EVENT_TYPE_S                    *pstEventTypeInfo
);

/**
* 查询事件类型信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   ulDevTypeId        事件信息类型ID
* @param [OUT]  pstEventTypeInfo   事件类型信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_EVENT_TYPE_NOT_EXIST 事件类型不存在
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventType
(
    IN   USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN   ULONG_32                            ulEventTypeId,
    OUT  EVENT_TYPE_S                     *pstEventTypeInfo
);

/**
* 查询事件类型列表 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   ulDevTypeId        设备类型ID,取值范围见#IMOS_TYPE_E
* @param [IN]   ulDevSubTypeId     设备信息子类型ID,摄像机类型取值见#CAMERA_TYPE_E,组织类型取值范围见mm_def.h中6种MM_DOMAIN_SUBTYPE_XXX_XXX的宏定义,
*                                      组显示类型取值见#SALVO_TYPE_E,组轮巡类型取值见#GROUP_SWITCH_TYPE_E,EC和DC类型取值见#IMOS_DEVICE_TYPE_E
* @param [IN]   szDevCode          设备编码
* @param [IN]   ulParentDevType    父设备类型ID,取值范围见#IMOS_TYPE_E
* @param [IN]   ulParentSubDevType 父设备信息子类型ID,摄像机类型取值见#CAMERA_TYPE_E,组织类型取值范围见mm_def.h中6种MM_DOMAIN_SUBTYPE_XXX_XXX的宏定义,
*                                      组显示类型取值见#SALVO_TYPE_E,组轮巡类型取值见#GROUP_SWITCH_TYPE_E,EC和DC类型取值见#IMOS_DEVICE_TYPE_E
* @param [IN]   pstQueryCondition  通用查询条件（目前只支持联动和布防，只支持等于）
* @param [IN]   pstQueryPageInfo   查询分页信息
* @param [OUT]  pstRspPageInfo     查询返回分页信息
* @param [OUT]  pstEventTypeExtInfoList  事件类型信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
 订阅
****************************************************************************/
/**
* 订阅告警 \n
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   pstSubscInfo        订阅信息
* @param [OUT]  szSessionID         返回订阅成功的业务ID
* @return 返回如下结果:
* - 成功:
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 IMOS_SubscribeEvent
(
    IN USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN SUBSC_BASE_INFO_S      *pstSubscInfo,
    OUT CHAR  szSessionID[IMOS_SSN_ID_LEN]
);

/**
* 续订告警 \n
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   ulExpires           续订时长
* @param [IN]   szSessionID         订阅成功的业务ID
* @return 返回如下结果:
* - 成功:
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 IMOS_RenewSubscribe
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN ULONG_32  ulExpires,
    IN CHAR   szSessionID[IMOS_SSN_ID_LEN]
);

/**
* 取消订阅 \n
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   szSessionID         订阅成功的业务ID
* @return 返回如下结果:
* - 成功:
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 IMOS_CancelSubscribe
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR  szSessionID[IMOS_SSN_ID_LEN]
);

/**
* 查询订阅列表 \n
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   pstQueryCondition   查询条件
* @param [IN]   pstQueryPageInfo    分页请求信息
* @param [OUT]  pstRspPageInfo      分页请求返回信息
* @param [OUT]  pstSubscList        查询的告警信息
* @return 返回如下结果:
* - 成功:
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 在查询到多条记录时pstSubscFullInfo是指向查询列表首记录的地址
*       目前只支持资源编码查询条件 [#CODE_TYPE]
*/
IMOS_EXPORT ULONG_32 IMOS_QuerySubscribeList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SUBSC_FULL_INFO_S           *pstSubscList
);

/* Begin Add By hexiaojun/hW0959 for 目录查询 2014-11-10 */
/**
* 查询目录订阅列表 \n
* @param [IN]   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo    用户信息标识
* @param [IN]   COMMON_QUERY_CONDITION_S       *pstQueryCondition   查询条件
* @param [IN]   QUERY_PAGE_INFO_S              *pstQueryPageInfo    分页请求信息
* @param [OUT]  RSP_PAGE_INFO_S                *pstRspPageInfo      分页请求返回信息
* @param [OUT]  SUBSC_FULL_INFO_S            *pstCatalogList        查询的目录信息
* @return 返回如下结果:
* - 成功:
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 在查询到多条记录时pstSubscFullInfo是指向查询列表首记录的地址
*       目前只支持资源编码查询条件 [#CODE_TYPE]
*/
IMOS_EXPORT ULONG_32 IMOS_QueryCatalogSubscribeList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SUBSC_FULL_INFO_S           *pstCatalogList
);
/* End Add By hexiaojun/hW0959 for 目录查询 2014-11-10 */

/**
* 新增干线
* @param [IN]   pstUserLogIDInfo 用户登陆信息
* @param [IN]   pstTrunkInfo     干线信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TRUNK_INFO_S            *pstTrunkInfo
);

/**
* 修改干线信息
* @param [IN]   pstUserLogIDInfo 用户登陆信息
* @param [IN]   pstTrunkInfo     干线信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TRUNK_INFO_S            *pstTrunkInfo
);

/**
* 删除干线信息
* @param [IN]   pstUserLogIDInfo 用户登陆信息
* @param [IN]   szTrunkCode      干线编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN]
);

/**
* 查询干线列表信息
* @param [IN]   pstUserLogIDInfo     用户登陆信息
* @param [IN]   pstQueryCondition    通用查询条件
* @param [IN]   pstQueryPageInfo     请求分页信息
* @param [OUT]  pstRspPageInfo       返回分页信息
* @param [OUT]  pstTrunkList         干线列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无查询条件，pstQueryCondition可以为NULL,
*       目前只支持名称查询条件.
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
* Added by g00762(gaoshufeng), 2012-08-03 for VM管理ECR的干线管理
* 添加干线内容信息，设备干线可添加的干线内容为EC，ECR或组织。域间干线可添加的内容为外域。
* @param [IN]   pstUserLogIDInfo      用户登陆信息
* @param [IN]   szTrunkCode           干线编码
* @param [IN]   ulContentNum          干线内容数目,最大值为#IMOS_TRUNK_CONTENT_MAXNUM
* @param [IN]   pstTrunkContentList   干线内容列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTrunkContent
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                   ulContentNum,
    IN  TRUNK_CONTENT_INFO_S    *pstTrunkContentList
);

/**
* 删除干线内容信息
* @param [IN]   pstUserLogIDInfo    用户登陆信息
* @param [IN]   szTrunkContentCode  干线内容编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteTrunkContent
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkContentCode[IMOS_RES_CODE_LEN]
);

/**
* Added by g00762(gaoshufeng), 2012-08-03 for VM管理ECR的干线管理
* 查询干线内容信息。设备干线查询到的干线内容为EC，ECR或组织，域间干线查询到的内容为外域。
* @param [IN]   pstUserLogIDInfo     用户登陆信息
* @param [IN]   szTrunkCode          干线编码
* @param [IN]   pstQueryCondition    通用查询条件
* @param [IN]   pstQueryPageInfo     请求分页信息
* @param [OUT]  pstRspPageInfo       返回分页信息
* @param [OUT]  pstTrunkContentList  干线内容列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 目前暂不支持任何查询条件
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
* 启动干线管理
* @param [IN]   pstUserLogIDInfo  用户登陆信息
* @param [IN]   szTrunkCode       干线编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN]
);

/**
* 停止干线管理
* @param [IN]   pstUserLogIDInfo  用户登陆信息
* @param [IN]   szTrunkCode       干线编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DisableTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTrunkCode[IMOS_RES_CODE_LEN]
);

/**
* 申请干线
* @param [IN]   pstUserLogIDInfo  用户登陆信息
* @param [IN]   szResCode         资源编码
* @param [OUT]  szSsnID           会话ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 该函数针对某种可能产生流传输的业务和资源使用:
* -     目前在回放/下载录像前，需要为摄像机先申请干线。
* -     申请成功后如果业务释放需要调用释放函数释放申请的干线。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ApplyTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szResCode[IMOS_RES_CODE_LEN],
    OUT CHAR                    szSsnID[IMOS_SSN_ID_LEN]
);

/**
* 释放干线
* @param [IN]   pstUserLogIDInfo   用户登陆信息
* @param [IN]   szSsnID            会话ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_FreeTrunk
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szSsnID[IMOS_SSN_ID_LEN]
);

/**
* 更新系统流封装格式
* @param [IN] pstUserLogIDInfo      用户登录ID信息标识
* @param [IN] pstSysStreamFormat    系统封装流格式信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* 允许配置 UDP+TS , RTP+TS,RTP_NO_RTCP+ES
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSysStreamFormat
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SYS_STREAM_FORMAT_S             *pstSysStreamFormat
);

/**
* 查询系统流封装格式
* @param [IN] pstUserLogIDInfo       用户登录ID信息标识
* @param [OUT] pstSysStreamFormat    系统封装流格式信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysStreamFormat
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT SYS_STREAM_FORMAT_S             *pstSysStreamFormat
);

/**
* 更新系统实况请求主辅流自适应匹配策略
* @param [in] pstUserLogIDInfo          用户登录ID信息标识
* @param [in] ulMonStreamMatchPolicy    系统实况请求主辅流自适应匹配策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSysMonStreamMatchPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulMonStreamMatchPolicy
);

/**
* 查询系统实况请求主辅流自适应匹配策略
* @param [IN]  pstUserLogIDInfo           用户登录ID信息标识
* @param [OUT] pulMonStreamMatchPolicy    系统实况请求主辅流自适应匹配策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysMonStreamMatchPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulMonStreamMatchPolicy
);

/**
* 更新系统组播地址的主辅流选择策略
* @param [in] pstUserLogIDInfo           用户登录ID信息标识
* @param [in] ulMCastAddrStreamPolicy    系统组播地址的主辅流选择策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSysMCastAddrStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulMCastAddrStreamPolicy
);

/**
* 查询系统组播地址的主辅流选择策略
* @param [IN]  pstUserLogIDInfo            用户登录ID信息标识
* @param [OUT] pulMCastAddrStreamPolicy    系统组播地址的主辅流选择策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysMCastAddrStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT ULONG_32                           *pulMCastAddrStreamPolicy
);

/**
* 更新系统参数值
* @param [in] pstUserLoginIDInfo           用户登录ID信息标识
* @param [in] pszSystemParamName      系统参数名长度小于#IMOS_NAME_LEN，暂时只对#SS_SYSPARAM_NAME_SECOND_MCAST_ADDR_STREAM_POLICY开放
* @param [in] ulMCastAddrStreamPolicy    系统组播地址的主辅流选择策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSystemParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                                    *pszSystemParamName,
    IN  ULONG_32                               ulSystemParamValue
);

/**
* 查询系统参数值
* @param [IN]  pstUserLoginIDInfo            用户登录ID信息标识
* @param [in] pszSystemParamName      系统参数名长度小于#IMOS_NAME_LEN，暂时只对#SS_SYSPARAM_NAME_MCAST_ADDR_STREAM_POLICY开放
* @param [OUT] pulSystemParamValue    系统参数设置
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryfigSystemParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                                    *pszSystemParamName,
    OUT ULONG_32                             *pulSystemParamValue
);

/**
* 将摄像机绑定到EC的某个通道上，需要带齐所有信息，支持场名OSD，遮盖区域，视频流，遮挡检测区域，运动检测区域五种元素变长
* @param [IN]   pstUserLogIDInfo             用户信息
* @param [IN]   pstVINBindCamBaseInfo        摄像机及其绑定通道的基本信息
* @param [IN]   pstVINFullVarietyElement     视频通道全部变长元素结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* 1.摄像机编码不能为空,且不能包含空格
* 2.变长元素个数和变长元素内存长度由调用者保证，变长元素个数不可大于变长元素实际内存长度
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelV2
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLogIDInfo,
    IN  VINCHNL_BIND_CAMERA_BASE_S              *pstVINBindCamBaseInfo,
    IN  VINCHNL_FULL_VARIETY_ELEMENT_S          *pstVINFullVarietyElement
);

/**
* 将摄像机绑定到EC 的某个通道上，需要带齐所有信息，支持场名OSD，遮盖区域，视频流，遮挡检测区域，运动检测区域五种元素变长
* @param [IN]  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo             用户信息
* @param [IN]  VINCHNL_BIND_CAMERA_BASE_V2_S       *pstVINBindCamBaseInfo        摄像机及其绑定通道的基本信息
* @param [IN]  VINCHNL_FULL_VARIETY_ELEMENT_S   *pstVINFullVarietyElement     视频通道全部变长元素结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* 1.摄像机编码不能为空,且不能包含空格
* 2.变长元素个数和变长元素内存长度由调用者保证，变长元素个数不可大于变长元素实际内存长度
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelV3
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLoginIDInfo,
    IN  VINCHNL_BIND_CAMERA_BASE_V2_S           *pstVINBindCamBaseInfo,
    IN  VINCHNL_FULL_VARIETY_ELEMENT_S          *pstVINFullVarietyElement
);

/**
* 查询某个组织下的某台设备的摄像机存储资源分配情况列表V2
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstStoreResList         摄像机存储资源分配信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1.如果无查询条件,指针pstQueryCondition可以为NULL
* - 过滤
* - 1. 支持按"是否查子组织"条件查询:#IS_QUERY_SUB,1 是,0 否
* - 2. 对于刚分配完的存储资源，接口返回资源状态为正常、但需要延时一定时间(若干秒)才能执行录像存储
* - 限制
* - 1. 该接口仅支持VM平台
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
* 查询在某个存储设备上配置了存储的摄像机列表  \n
* @param [IN]   *pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szStorDevCode           存储设备编码
* @param [IN]   ulStorageType           存储类型  0: 独享存储 1: 共享存储
* @param [IN]   *pstQueryPageInfo       请求分页信息
* @param [OUT]  *pstRspPageInfo         响应分页信息
* @param [OUT]  *pstSDKCamList          摄像机列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 排序方式为"摄像机编码升序排序"
* - 2. 本接口需分别查询两张表,暂不支持通用查询条件
* - 3. 该接口仅支持VM平台
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
设备-BM
***************************************************************************************************************/
/** @defgroup group BM 服务器管理
*   服务器管理包括BM,备份资源，备份任务，备份文件，备份计划管理等
*   @{
*/
/**
* @name BM管理
* @{    BM管理
*/
/**
* 添加BM服务器 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBMInfo           BM信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddBM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BM_INFO_S                   *pstBMInfo
);

/**
* 修改BM服务器 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBMInfo           BM信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BM_INFO_S                   *pstBMInfo
);

/**
* 删除BM服务器 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szBMCode            BM编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBM
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBMCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 查询BM服务器列表 \n
* szOrgCode值无效，填任何值，都只查询本域BM列表
* 条件为空时,查所有,并默认"名称升序排序"  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szOrgCode              组织编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[BM名称] #CODE_TYPE[BM编码] #PHY_DEV_IP[BM IP])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstSDKBMList           BM列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
备份资源管理
****************************************************************************/
/**
* @name 备份资源管理
* @{    涉及BM备份资源管理,摄像机备份资源管理
*/
/**
* 从存储设备为BM服务器分配资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBMResInfo        BM资源信息
* @param [OUT]  szBMResCode         BM资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromStoreDev
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DM_RES_FOR_BM_INFO_S    *pstBMResInfo,
    OUT CHAR                    szBMResCode[IMOS_CODE_LEN]
);

/**
* 从第三方资源为BM服务器分配资源V2 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBMResInfo        BM资源信息
* @param [OUT]  szBMResCode         BM资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromThird
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  THIRD_RES_FOR_BM_INFO_S   *pstBMResInfo,
    OUT CHAR                      szBMResCode[IMOS_CODE_LEN]
);


/**
* 从第三方资源为BM服务器分配资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBMResInfo        BM资源信息
* @param [OUT]  szBMResCode         BM资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromThirdV2
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  THIRD_RES_FOR_BM_INFO_S_V2   *pstBMResInfoV2,
    OUT CHAR                      szBMResCode[IMOS_CODE_LEN]
);

/**
* 从第三方资源为BM服务器分配资源(V3) \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBMResInfo        BM资源信息
* @param [OUT]  szBMResCode         BM资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignBMResFromThirdV3
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  THIRD_RES_FOR_BM_INFO_S_V3   *pstBMResInfoV3,
    OUT CHAR                      szBMResCode[IMOS_CODE_LEN]
);

/**
* 删除BM服务器上分配的备份资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN    szResCode           BM资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBMRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szResCode[IMOS_CODE_LEN]
);

/**
* 查询BM备份资源列表 \n
* 目前只支持组织编码szOrgCode允许为空串的查询 \n
* 条件为空时,查所有,并默认"名称升序排序"  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szBMCode               BM编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[BM资源名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstSDKBMResList        BM备份资源列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 从存储设备上分配共享存储资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstShareResInfo     共享资源信息
* @param [OUT]  szShareResCode     共享资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignShareRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  DM_SHARE_RES_INFO_S     *pstShareResInfo,
    OUT CHAR       szShareResCode[IMOS_CODE_LEN]
);

/**
*分配存储资源V2
*@param [IN]    pstUserLogInfo        用户登录ID 信息标识
*@param [IN]    szCamCode        摄像机编码
*@param [IN]    pstStoreResInfo        存储资源信息
*@return 返回如下结果:
* 成功:
* #ERR_COMMON_SUCCEED
*失败:
* #ERR_AS_CAM_NOT_LOCAL_DOMAIN
* #ERR_AS_STORE_RES_ALLOCTED
*    返回操作结果码，见错误码文件
*@note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignStoreResV2
(
    IN USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN CHAR                               szCamCode[IMOS_RES_CODE_LEN],
    IN STORE_RES_INFO_V2_S            *pstStoreResInfo
);

/**
* 查询存储资源V2
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szCamCode               摄像机编码
* @param [OUT]  pstStoreResInfo         分配的存储资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_STORAGE_NOT_EXIST
* - #ERR_DAO_STORE_RES_NOT_EXIST
* - #ERR_DAO_EVENT_STORAGE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStoreResV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT STORE_RES_INFO_V2_S            *pstStoreResInfo
);

/**
* 分页查询已分配共享资源DM列表  \n
* 查询所有已配置共享资源的DM, 并默认按照共享存储时间降序排列\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCamCode           摄像机编码
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstSDKDMList        DM列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note  无
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
* 删除共享存储资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szResCode     共享资源编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelShareRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR       szResCode[IMOS_CODE_LEN]
);


#if 0
#endif
/**
* 分配摄像机备份资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstCamBakResInfo    摄像机备份资源信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_BAK_RES_INFO_S      *pstCamBakResInfo
);

/**
* 修改摄像机独享备份资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstCamBakResInfo    摄像机备份资源信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_BAK_RES_INFO_S      *pstCamBakResInfo
);

/**
* 删除摄像机备份资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCamCode           摄像机编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 查询摄像机备份资源 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCamCode           摄像机编码
* @param [OUT]  ulItemNum           摄像机备份资源信息条数
* @param [OUT]  pstCamBakResList    摄像机备份资源列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机在本域的备份资源查询
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraBakRes
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szCamCode[IMOS_DEVICE_CODE_LEN],
    OUT ULONG_32                     *pulItemNum,
    OUT CAM_BAK_RES_INFO_S        *pstCamBakResList
);


/**
* 分页查询某个组织下摄像机备份资源分配情况列表
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[摄像机名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstCamBakResList        摄像机备份资源分配信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机在本域的备份资源查询
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
备份任务管理
****************************************************************************/
/**
* @name 备份任务管理
* @{    备份任务管理
*/
/**
* 设置手动备份 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstManulBakInfo     手动备份任务信息
* @param [OUT]  szTaskCode          备份任务编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行手动备份
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetManualBak
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  MANUL_BAK_INFO_S          *pstManulBakInfo,
    OUT CHAR                      szTaskCode[IMOS_CODE_LEN]
);

/**
* 删除备份任务 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szTaskCode          备份任务编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBakTask
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTaskCode[IMOS_CODE_LEN]
);

/**
* 查询备份任务列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   ulTaskType              任务类型#BAK_TYPE_E
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSDKBakTaskList       备份任务列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1、通用查询条件支持:任务状态[#TASK_STATUS]、任务提交时间[#TASK_SUB_TIME]、任务结束时间[#TASK_END_TIME]、摄像机名称[#NAME_TYPE]、
* -    录像开始时间[#REC_START_TIME]、录像结束时间[#REC_END_TIME]、用户名称[#USER_NAME_TYPE]、案例描述[#CASE_DESC]的查询和排序;
* - 2、通用查询条件为NULL,或无排序条件时,默认按"任务提交时间升序"排序;
* - 3、非admin用户的任务类型只能是手动任务[#BAK_MANUL];
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
备份文件管理
****************************************************************************/
/**
* @name 备份文件管理
* @{    备份文件管理
*/
/**
* 操作备份文件 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBakFileInfo      备份文件操作信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_HandleBakFile
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  BAK_FILE_HANDLE_INFO_S     *pstBakFileInfo
);

/* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
/**
* 录像锁定\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         用户登录ID信息标识
* @param [IN]   LOCK_RECORD_INFO_S     *pstLockRecordInfo            录像锁定信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LockRecord
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  LOCK_RECORD_INFO_S     *pstLockRecordInfo
);

/**
* 录像解锁\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         用户登录ID信息标识
* @param [IN]   ULONG_32                          ulUnlockType            录像解锁类型
* @param [IN]   CHAR                          szUnlockKeyStr[IMOS_STRING_LEN_256]            录像编码根据锁定类型含义不同
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnlockRecord
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  ULONG_32   ulUnlockType,
    IN  CHAR    szUnlockKeyStr[IMOS_STRING_LEN_256]
);

/**
* 查询锁定摄像机列表，支持分页查询\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         用户登录ID信息标识
* @param [IN]   ULONG_32      ulQueryType            查询条件类型
* @param [IN]   CHAR        szQueryKeyStr[IMOS_STRING_LEN_256]            查询条件
* @param [IN]  QUERY_PAGE_INFO_S        *pstQueryPageInfo        请求分页信息
* @param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo          响应分页信息
* @param [OUT] LOCKED_CAMERA_QUERY_ITEM_S   *pstLockedCameraList       被锁定摄像机信息列表
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
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
* 查询某摄像机的锁定录像信息列表，支持分页查询\n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLoginIDInfo         用户登录ID信息标识
* @param [IN]   CHAR       szCameraCode[IMOS_CODE_LEN]    摄像机编码
* @param [IN]  QUERY_PAGE_INFO_S        *pstQueryPageInfo        请求分页信息
* @param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo          响应分页信息
* @param [OUT] LOCKED_CAMERA_QUERY_ITEM_S   *pstLockedCameraList       被锁定录像信息列表
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
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
* 备份录像检索 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSDKRecordFileInfo    备份文件信息数据结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1、通用查询条件支持:摄像机编码[#CODE_TYPE]、摄像机名称[#NAME_TYPE]、文件生成时间[#FILE_CREATE_TIME]、
* -    备份开始时间[#BAK_START_TIME]、备份结束时间[#BAK_END_TIME]、文件容量[#FILE_CAPACITY]、文件类型[#FILE_TYPE]、
* -    文件锁定标识[#FILE_LOCK_FLAG]、案例描述[#CASE_DESC]的查询和排序;
* - 2、通用查询条件为NULL,或无排序条件时,默认按"备份开始时间升序"排序;
* - 3、通用查询条件中添加的备份开始时间与结束时间之间的时间跨度不能跨天，且时间格式为："%Y-%m-%d %H:%M:%S"格式 ，信息长度限定为24字符
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
* 获取备份录像文件的URL信息 \n
* @param[IN]    pstUserLogIDInfo        用户登录ID信息标识
* @param[IN]    pstSDKGetBakUrlInfo     获取URL请求消息数据结构
* @param[OUT]    pstSDKURLInfo          URL信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
备份计划
****************************************************************************/
/**
* @name 备份计划管理
* @{    涉及备份计划的删改查,以及查询备份计划列表接口
*/
/**
* 添加备份计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBakPlanInfo      备份计划信息
* @param [OUT]  szBakPlanCode       备份计划编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BAK_PLAN_INFO_S             *pstBakPlanInfo,
    OUT CHAR                        szBakPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 修改备份计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstBakPlan          备份计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 启动备份计划需要调用IMOS_ProcessPlan接口; 而通过修改计划时间的方式不能够自动使计划启动/停止
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  BAK_PLAN_INFO_S                 *pstBakPlanInfo
);

/**
* 删除备份计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szBakPlanCode       备份计划编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBakPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 查询备份计划信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szBakPlanCode       备份计划编码
* @param [OUT]  pstBakPlanInfo      备份计划信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBackupPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBakPlanCode[IMOS_RES_CODE_LEN],
    OUT BAK_PLAN_INFO_S                 *pstBakPlanInfo
);

/*Begin added by liujian 02319 for 留存期备份扩容特性*/
/**
* 修改备份计划延迟信息
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                        用户登录ID信息标识
* @param [IN]   ULONG_32    ulNumber                                                             批量配置的个数
* @param [IN]   CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos          备份计划延迟信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBackupPlanDelayInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                                 ulNumber,
    IN  CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos
);

/**
* 查询备份计划延迟信息
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                        用户登录ID信息标识
* @param [IN]   ULONG_32    ulNumber                                                             批量配置的个数
* @param [INOUT]   CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos          备份计划延迟信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_BAK_PLAN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @attention
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBackupPlanDelayInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  ULONG_32                                 ulNumber,
    INOUT  CAMERA_BAK_PLAN_DELAY_INFO_S    *pstBakPlanDelayInfos
);

/*End added by liujian 02319 for 留存期备份扩容特性*/

/**
* 分配摄像机流转存配置 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo   摄像机流转存配置信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AssignCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo
);

/**
* 修改摄像机流转存基本配置 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo   摄像机流转存配置信息
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note: 无
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CAM_STREAM_STOR_INFO_S  *pstCamStreamStorInfo
);

/**
* 删除摄像机流转存配置 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo                  用户登录ID信息标识
* @param [IN]   CHAR                    szCamCode[IMOS_CODE_LEN]           摄像机编码
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_CODE_LEN]
);

/**
* 查询摄像机流转存配置信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   CHAR                        szCamCode[IMOS_CODE_LEN]    摄像机编码
* @param [OUT]  CAM_STREAM_STOR_INFO_S      *pstCamStreamStorInfo       摄像机流转存信息列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStreamStorInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  CHAR                     szCamCode[IMOS_CODE_LEN],
    OUT CAM_STREAM_STOR_INFO_S   *pstCamStreamStorInfo
);

/**
* 分页查询某个组织下摄像机流转存配置信息列表 \n
* 条件为空时,查所有,并默认"名称升序排序"
* @param [IN]  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]  CHAR                         szOrgCode[IMOS_CODE_LEN]    组织编码
* @param [IN]  COMMON_QUERY_CONDITION_S     *pstQueryCondition          通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[摄像机名称])
* @param [IN]  QUERY_PAGE_INFO_S            *pstQueryPageInfo           请求分页信息
* @param [OUT] RSP_PAGE_INFO_S              *pstRspPageInfo             响应分页信息
* @param [OUT] CAM_STREAM_STOR_QUERY_ITEM_S *pstCamStreamStorList       摄像机备份资源分配信息列表
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 添加摄像机流转存的计划配置 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo                       用户登录ID信息标识
* @param [IN]   STREAM_STOR_PLAN_INFO_S     *pstStreamStorPlanInfo                  流转存计划信息
* @param [OUT]  CHAR                        szStreamStorPlanCode[IMOS_CODE_LEN]     返回的流转存计划编码
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  STREAM_STOR_PLAN_INFO_S              *pstStreamStorPlanInfo,
    OUT CHAR                                 szStreamStorPlanCode[IMOS_CODE_LEN]
);

/**
* 修改流转存计划
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]  STREAM_STOR_PLAN_INFO_S      *pstStreamStorPlanInfo  流转存计划信息
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  STREAM_STOR_PLAN_INFO_S    *pstStreamStorPlanInfo
);

/**
* 删除流转存计划
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo                         用户登录ID信息标识
* @param [IN]   CHAR                       szStreamStorPlanCode[IMOS_CODE_LEN]       流转存计划编码
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szStreamStorPlanCode[IMOS_CODE_LEN]
);

/**
* 查询流转存计划信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo                         用户登录ID信息标识
* @param [IN]   CHAR                       szStreamStorPlanCode[IMOS_CODE_LEN]       流转存计划编码
* @param [OUT]  STREAM_STOR_PLAN_INFO_S    *pstStreamStorPlanInfo                    流转存计划信息
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamStreamStorPlan
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szStreamStorPlanCode[IMOS_CODE_LEN],
    OUT STREAM_STOR_PLAN_INFO_S    *pstStreamStorPlanInfo
);

/**
* 启动/停止计划 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   ulPlanType          计划类型#PLAN_TYPE_E
* @param [IN]   szStorePlanCode     计划编码
* @param [IN]   ulPlanMode          计划处理标记, #PLAN_OPER_MODE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note 无
* @attention 本接口支持对共享摄像机进行本域配置
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulPlanType,
    IN  CHAR                            szPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulPlanMode
);

/**
* 对内初始化总入口。 \n
* @param [IN]       szServerAdd     服务器IP
* @param [IN]       ulServerPort    服务器端口
* @param [INOUT]  pstInit         SDK初始化参数，其中pParam字段为INOUT型
* @return ULONG  返回如下结果:
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件。
* @note szServerAdd的取值为127.0.0.0,127.0.0.1,VM服务器地址
*       ulServerPort的取值为8800
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_InterInitiate
(
    IN    CHAR       szServerAdd[IMOS_IPADDR_LEN],
    IN    ULONG_32      ulServerPort,
    INOUT SDK_MU_INIT_S *pstInit
);

/* added by z06806 for vodwall prj 20101211 begin */
/**
* 开始回放上墙 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szXPCode                XP编码
* @param [IN]   szMonitorCode           监视器编码
* @param [IN]   ulOperateCode           操作原因码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulOperateCode取值参见#CS_OPERATE_CODE_E
* - 2.  szMonitorCode在回放上墙中为对应监视器编码
* - 3. szXPCode在回放上墙中为对应窗格编码
* - 4. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartVodToTV
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szXPCode[IMOS_CODE_LEN],
    IN  CHAR                        szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulOperateCode
);

/**
* 停止回放上墙 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   ulCodeType              编码类型，见#VODWALL_STOP_CODETYPE_E
* @param [IN]   szXPCode                XP编码
* @param [IN]   szMonitorCode           监视器编码
* @param [IN]   ulOperateCode           操作原因码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulOperateCode取值参见#CS_OPERATE_CODE_E
* - 2. 如果编码类型为监视器，则szMonitorCode填监视器编码，szXPCode可以不填
* - 3. 如果编码类型为XP，则szXPCode填XP编码，szMonitorCode可以不填
* - 4. 该接口仅支持VM平台
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
* 查询组织下资源信息列表(V3，返回#RES_INFO_S结构，包含资源ID，不过滤权限) \n
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstResList                 资源信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有资源(不查子组织)
* - 2.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按"资源名称"模糊查询:#NAME_TYPE
* - 4.支持按"是否外域资源"查询:#DOMAIN_TYPE = 1 是;= 0 否
* - 5.支持按"资源类型"查询:#RES_TYPE,取值为#IMOS_TYPE_E
* - 6.支持按"资源子类型"查询:#RES_SUB_TYPE(资源类型为摄像机时,取值为#CAMERA_TYPE_E)
* - 排序
* - 1.不指定排序条件情况下,默认按"资源名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(资源名称),#CODE_TYPE(资源编码),#RES_TYPE(资源类型),#RES_SUB_TYPE(资源子类型),
* -   #DOMAIN_TYPE(是否外域资源)
* - 限制
* - 1. 该接口仅支持VM平台
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
* 根据角色编码，设置角色权限(V2) \n
* @param [IN]   pstUserLogIDInfo      用户登录ID信息标识
* @param [IN]   szRoleCode            角色编码，对应唯一一个角色
* @param [IN]   ulResAuthorityNum     资源授权信息数量
* @param [IN]   pstResAuthorityList   资源授权信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_ROLE_NOT_EXIST
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口配置的资源范围仅限于角色所属组织和子组织
* - 2. 授予的权限可以是系统权限，也可以是针对资源（包括组织、摄像头、监视器等）的权限
* - 3. 调用该接口后, 以该次调用的权限为准，角色之前的权限会被覆盖
* - 4. ulResAuthorityNum设置为0，同时pstResAuthorityList设置为NULL，表示清除角色所有权限。
* - 5. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRoleAuthorityV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szRoleCode[IMOS_CODE_LEN],
    IN  ULONG_32                       ulResAuthorityNum,
    IN  RES_AUTHORITY_S             *pstResAuthorityList
);

/**
* 根据角色编码，查询某个角色的权限信息(V2) \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   szRoleCode                   角色编码，对应唯一一个角色
* @param [IN]   pstQueryCondition            查询条件(支持的查询条件包括:#RES_ID[资源ID]
*                                                                        #RES_TYPE[资源类型]，
*                                                                        #NAME_TYPE[资源名称])
* @param [IN]   pstQueryPageInfo             请求分页信息
* @param [OUT]  pstRspPageInfo               响应分页信息
* @param [OUT]  pstResAuthorityList          角色权限列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 全局权限和其他权限必须分开查询。
* - 2. 查询全局权限时，查询条件为RES_ID等于0，不能有其他查询条件，查询其他权限时，RES_ID大于0，且可以有其他查询条件。
* - 3. 如果权限记录对应的资源不存在，出参角色权限列表中对应该资源的#RES_INFO_S除szResIdCode有效，其他字段都无效。
* - 4. 该接口仅支持VM平台
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
* 查询当前登录用户的所有权限(V2). \n
* 如果当前登录用户是系统管理员,则只返回"是否是系统管理员"标识,不返回权限列表;
* 如果不是系统管理员,则返回权限列表(包括系统权限和资源权限).
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [OUT]  pbIsSystemMgr       "是否是系统管理员"标识, #BOOL_TRUE为系统管理员; #BOOL_FALSE为非系统管理员
* @param [OUT]  pstAuthorityInfo    权限列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_MM_AUTHORITY_NOT_DEFINED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAuthListByUserV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT BOOL_T                  *pbIsSystemMgr,
    OUT ORG_AUTHORITY_V2_S         *pstAuthorityInfo
);

/**
* 删除角色的一条授权记录 \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   szRoleCode                   角色编码，对应唯一一个角色
* @param [IN]   szResIdCode                  资源ID，字符串"0"表示删除角色的系统权限
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 客户端文件上传函数 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,  用户登录信息
* @param [IN]   IMOS_UPLOAD_ADDR_S          *pstServerAddr,     服务器地址信息
* @param [IN]   IMOS_UPLOAD_OPTION_S        *pstOptions,        上传选项信息
* @param [IN]   IMOS_LOCAL_FILE_INFO_S      *pstLocalFile,      本地文件信息
* @param [INOUT]    IMOS_HANDLE             *pUploadHandle      上传句柄
* @return 返回如下结果：
* - 成功：
* - 失败：返回操作结果码，见错误码文件
* @note 无
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
* 客户端取消文件上传函数 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,  用户登录信息
* @param [IN]   IMOS_HANDLE                 hUpload             上传句柄
* @return 返回如下结果：
* - 成功：
* - 失败：返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CancelUpload
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  IMOS_HANDLE                 hUpload
);

/**
* 获取客户端文件上传进度函数 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,  用户登录信息
* @param [IN]   IMOS_HANDLE                 hUpload             上传句柄
* @param [INOUT]   FLOAT                     *pfProcess         具体百分比进度
* @return 返回如下结果：
* - 成功：
* - 失败：返回操作结果码，见错误码文件
* @note 无
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
IPC光学参数配置
****************************************************************************/
/**
* 设置光学参数
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstChannelIndex             设备通道索引信息
* @param [IN]   pstOpticsParam              光学参数信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_OPT_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigOpticsParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  OPTICS_PARAM_S                  *pstOpticsParam
);

/**
* 查询光学参数
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstChannelIndex             设备通道索引信息
* @param [OUT]  pstOpticsParam              光学参数信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_OPT_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOpticsParam
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT OPTICS_PARAM_S                  *pstOpticsParam
);

/**
* 设置系统业务抢占策略
* @param [IN] pstUserLogIDInfo      用户登录信息
* @param [IN] pstSrvRevStrategy     业务抢占策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetReaveStrategy
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  SRV_REV_STRATEGY_S     *pstSrvRevStrategy
);

/**
* 查询系统业务抢占策略
* @param [IN]  pstUserLogIDInfo       用户登录信息
* @param [OUT] pstSrvRevStrategy      业务抢占策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryReaveStrategy
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    OUT SRV_REV_STRATEGY_S       *pstSrvRevStrategy
);

/** @} */ /* end of BACKUP PLAN MANAGEMENT MODULE */
/** @} */

/**
* 通过XML增加设备通用接口
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   ulXmlLen               设备的XML长度信息
* @param [IN]   pcXml                  设备的XML信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* - #ERR_AS_EC_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. XML格式请见"批量导入.xml"文件
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDevByXML
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    ULONG_32                         ulXmlLen,
    IN    CHAR                          *pcXml
);

/**
* 启动自动发现
* @param [IN]   pstUserLogIDInfo        用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartAutoFind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo
);

/**
* 停止自动发现
* @param [IN]   pstUserLogIDInfo        用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopAutoFind
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo
);

/**
* 查询自动发现状态
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [OUT]  pulstate            自动发现状态，1代表启动，0代表停止，系统每次启动默认停止状态
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
*   包括VM管理ECR, ECR设备管理两部分
*   @{
*/
/***************************************************************************
PartI VM管理ECR
****************************************************************************/
/**
* @PartI VM管理ECR
* @{    VM管理ECR
*/
/**
* 添加带存储的编码器, 仅支持HF系列。添加ECR时传入设备类型为设备具体类型。添加NVR时传入设备类型为IMOS_DT_ISC_MIN，设备注册上线后会获取具体设备型号 \n
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   pstECRBasicInfo    带存储的编码器基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ECR_BASIC_INFO_S        *pstECRBasicInfo
);

/**
* 修改带存储的编码器, 仅支持HF系列.也可修改网络视频录像机 \n
* 目前仅支持修改名称.
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   pstECRBasicInfo    带存储的编码器基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ECR_BASIC_INFO_S        *pstECRBasicInfo
);

/**
* 删除带存储的编码器, 仅支持HF系列.也可删除网络视频录像机 \n
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szECRCode           带存储的编码器编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN]
);

/**
* 查询带存储的编码器, 仅支持HF系列.也可查询网络视频录像机信息 \n
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szECRCode           带存储的编码器编码
* @param [OUT]  pstECRBasicInfo     带存储的编码器基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECRInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN],
    OUT ECR_BASIC_INFO_S        *pstECRBasicInfo
);

/**
* 查询某个组织下带存储的编码器列表信息, 仅支持HF系列.也可查询网络视频录像机 \n
* 查询条件中没有对域子类型的查询条件时查询ECR和NVR.
* 查询ECR添加查询条件：ulQueryType:206,ulLogicFlag:3,szQueryData:7.ulQueryType:206,ulLogicFlag:4,szQueryData:1012
* 查询NVR添加查询条件：ulQueryType:206,ulLogicFlag:3,szQueryData:1013.ulQueryType:206,ulLogicFlag:4,szQueryData:2020
* 对于设备编码的查询，只支持模糊查询，不支持精确查询.
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织域编码
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[带存储的编码器名称] #CODE_TYPE[带存储的编码器编码] #EXT_DOMAIN_IP[带存储的编码器地址])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstECRBasicInfoList     带存储的编码器基本信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询ECR的摄像机列表, 仅支持HF系列.
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szECRCode               ECR编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstECRCamList           查询出来摄像机列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如果无查询条件，指针pstQueryCondition可以为NULL;
* - 2. 支持按摄像机编码、名称排序，对应通用查询条件中的查询项类型分别为:#CODE_TYPE、#NAME_TYPE;
* - 3. 若排序条件不填，将默认按照摄像机编码升序排序;
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
* 删除ECR摄像机, 会将当前业务停止; 用于删除ECR时的操作; 仅支持HF系列.
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szCamCode               待删除的摄像机编码
* @param [IN]   szECRCode               ECR编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCameraForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCamCode[IMOS_CODE_LEN],
    IN  CHAR                        szECRCode[IMOS_ECR_CODE_LEN]
);

/**
* 查询ECR的告警源列表, 用于删除ECR时的操作; 仅支持HF系列.
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szECRCode               ECR编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstECRAlmSrcList        查询出来告警源列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 删除ECR告警源, 用于删除ECR时的操作; 仅支持HF系列.
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   szAlarmSrcCode      待删除的告警源编码
* @param [IN]   szECRCode           ECR编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmSrcForECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szAlarmSrcCode[IMOS_CODE_LEN],
    IN  CHAR                    szECRCode[IMOS_ECR_CODE_LEN]
);
/** @} */ /* end of PartI：VM管理ECR */

/**
* 查询ECR的告警输出列表, 用于删除ECR时的操作; 仅支持HF系列.
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   szECRCode               ECR编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstECRAlmOutList        查询出来告警源列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 删除ECR告警输出, 用于删除ECR时的操作; 仅支持HF系列.
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   szAlarmSrcCode              待删除的告警源编码
* @param [IN]   szECRCode                   ECR编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
PartII ECR设备管理
****************************************************************************/
/**
* @PartII ECR设备管理
* @{    ECR设备管理
/**
* 修改系统时间. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       用户信息
* @param [IN]   CHAR                    szTime[IMOS_TIME_LEN]   修改后的时间，格式为"YYYY-MM-DD HH:MM:SS"
* @return 返回如下结果：
* - 成功：
* - 失败：
* - #ERR_AS_GET_TIME_FAIL
* - #ERR_AS_SET_TIME_FAIL
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySystemTime
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szTime[IMOS_TIME_LEN]
);

/**
* 获取系统时间. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo       用户信息
* @param [OUT]  CHAR                    szTime[IMOS_TIME_LEN]   系统时间，格式为"YYYY-MM-DD HH:MM:SS"
* @return 返回如下结果：
* - 成功：
* - 失败：
* - #ERR_AS_GET_TIME_FAIL
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSystemTime
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT CHAR                         szTime[IMOS_TIME_LEN]
);

/**
* 带存储的编码器重启，用于带存储的编码器本机. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RebootECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo
);

/**
* 带存储的编码器关机，用于带存储的编码器本机. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShutdownECR
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo
);

/* begin added by gaoshufeng-gKF0050 for VVD65569,2012.05.08 */
/*begin added by panchen-pKF0016 for 输出开关量时长可配置,2012.02.02*/
/**
* 配置设备的输出开关量( 带时间)
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [IN]   SemaOutputInfo          开关量信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfOutSwitchWithTimeForECR
(
    IN  USER_LOGIN_ID_INFO_S              *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S               *pstChannelIndex,
    IN  SEMA_OUTPUT_INFO_WITHTIME_FOR_ECR_S       *pstSemaOutputInfoWithTime
);
/*end added by panchen-pKF0016 for 输出开关量时长可配置,2012.02.02*/

/*begin added by panchen-pKF0016 for 输出开关量时长可配置,2012.02.02*/
/**
* 查询输出开关量信息 (带时间)
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [OUT]  SemaInputInfo           输出开关量信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOutSwitchWithTimeForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT SEMA_OUTPUT_INFO_WITHTIME_FOR_ECR_S     *pstSemaOutputInfo
);
/*end added by panchen-pKF0016 for 输出开关量时长可配置,2012.02.02*/
/* end added by gaoshufeng-gKF0050 for VVD65569,2012.05.08 */

/**
* 带存储的编码器恢复默认配置, 与Mware的CAPI接口配合使用. \n
* 只保留网络相关的配置和设备、通道编码，保留存储, 其余恢复缺省值;
* 用于带存储的编码器本机，调用该接口后会将整个系统重启.
* @param [IN]  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo   用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RestoreECRDefaultConfig
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo
);

/**
* ECR本机上设置设备基本信息, 仅支持HF系列. \n
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   pstDeviceBasicInfo 设备基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* 1. 修改流套餐与制式需要SDK用户调用重启设备的接口后，设备重启后设置生效.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevBasicInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ECR_DEVICE_BASIC_INFO_S *pstDeviceBasicInfo
);

/**
* ECR本机上查询设备基本信息, 仅支持HF系列. \n
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [OUT]  pstDeviceBasicInfo 设备基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevBasicInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    OUT	ECR_DEVICE_BASIC_INFO_S *pstDeviceBasicInfo
);

/**
* ECR本机上设置服务器管理信息, 仅支持HF系列. \n
* @param [IN]   pstUserLogIDInfo  用户信息, 只有拥有系统管理权限的用户可以进行操作
* @param [IN]   pstServerMgrInfo  服务器管理信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* 1. 服务器管理模式下切换服务器模式或者修改服务器信息会停止原服务器正在进行的实时业务.
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetServerMgrInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ECR_SERVER_MGR_INFO_S       *pstServerMgrInfo
);

/**
* ECR本机上查询服务器管理信息, 仅支持HF系列. \n
* @param [IN]   pstUserLogIDInfo  用户信息, 无权限过滤, 具体权限由SDK用户控制
* @param [OUT]  pstServerMgrInfo  服务器管理信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServerMgrInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT ECR_SERVER_MGR_INFO_S       *pstServerMgrInfo
);

/**
* 增加告警联动(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmType             告警类型, 取值为#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_LINKAGE_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 可配置完全重复的动作，但注意例子中的情况。例：配置多次"同一个摄像机到同一个监视器", 都会配置成功，但最终只有
*       最先配置的会执行成功.
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_S          *pstAlarmAction
);


/**
* 删除告警联动(for ECR&NVR buzzer)
* @param [IN]  pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]  szAlarmSrcCode               告警源编码
* @param [IN]  ulAlarmType                  告警类型, 取值为#AlARM_TYPE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType
);


/**
* 修改告警联动信息(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmType             告警类型, 取值为#AlARM_TYPE_E
* @param [IN]   pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_LINKAGE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 可配置完全重复的动作，但注意例子中的情况。例：配置多次"同一个摄像机到同一个监视器", 都会配置成功，但最终只有
*       最先的配置会执行成功.
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    IN  ALARM_ACTION_FOR_ECR_S          *pstAlarmAction
);


/**
* 查询告警联动信息(for ECR&NVR buzzer)
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szAlarmSrcCode          告警源编码
* @param [IN]   ulAlarmSrcType          告警类型, 取值为#AlARM_TYPE_E
* @param [OUT]  pstAlarmAction          告警联动动作信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_LINKAGE_NOT_EXIST
* - #ERR_AS_LINKAGE_NUM
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmLinkageForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szAlarmSrcCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulAlarmType,
    OUT ALARM_ACTION_FOR_ECR_S          *pstAlarmAction
);

/**
* 将摄像机绑定到编码器的某个通道上 for ECR&NVR
* @param [IN]  pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]  pstVinChnlAndCamInfo         摄像机及其绑定通道的信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 摄像机编码不能为空,且不能包含空格
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VINCHNL_BIND_CAMERA_FOR_ECR_S   *pstVinChnlAndCamInfo
);
/** @} */ /* end of PartII:ECR设备管理 */


/** @} *//* end of group ECR33**-HF */

#if 0
#endif
/***************************************************************************
告警订阅
****************************************************************************/
/**
* 增加告警订阅规则（非系统预定义规则告警源不能为空，系统预定义规则告警源必须为空）
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstRule                     告警订阅规则
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 不允许增加系统预定义规则
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_AddAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_S   *pstRule
);

/**
* 删除告警订阅规则（系统预定义规则不能删除）
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstRule                     告警订阅规则编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_DelAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo,
    IN  CHAR                   szRuleCode[IMOS_CODE_LEN]
);

/**
* 修改告警订阅规则（非系统预定义规则告警源不能为空，系统预定义规则告警源必须为空）
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstRule                     告警订阅规则
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_ModifyAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_S  *pstRule
);

/**
* 查询告警订阅规则基本信息
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szRuleCode                  告警订阅规则编码
* @param [OUT]  pstRuleBase                 告警订阅规则
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRule
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szRuleCode[IMOS_CODE_LEN],
    OUT ALARM_SENDING_RULE_BASE_INFO_S  *pstRuleBase
);

/**
* 查询告警订阅规则告警源列表（最多每次查询#IMOS_ALARM_SEND_SRC_MAXNUM条记录）
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szRuleCode                  告警订阅规则编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstAlarmSrcList             告警源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持的查询条件：#NAME_TYPE[告警源名称]
* - 2. 该接口仅支持VM平台
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
* 查询告警订阅规则用户列表（最多每次查询#IMOS_ALARM_SEND_USER_MAXNUM条记录）
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szRuleCode                  告警订阅规则编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstAlarmSrcList             告警源列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持的查询条件：#USER_NAME_TYPE[用户名称]
* - 2. 该接口仅支持VM平台
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
* 查询告警订阅规则第三方系统列表
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szRuleCode                  告警订阅规则编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstThdSysList               第三方系统列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持的查询条件：#CODE_TYPE[第三方系统编码], #NAME_TYPE[第三方系统名称]
* - 2. 该接口仅支持VM平台
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
* 查询告警订阅规则列表
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szRuleCode                  告警订阅规则编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstAlarmSrcList             告警订阅规则列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 支持的查询条件：#NAME_TYPE[规则名称]
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_QueryAlarmSendingRuleList
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S         *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S                  *pstRspPageInfo,
    OUT ALARM_SENDING_RULE_BASE_INFO_S   *pstAlarmSendingRuleList
);

/* Begin add by l01420, 2014-7-10 for 丹东局点需求汇总*/
/**
* 增加告警订阅规则V2
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstRule                     告警订阅规则
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 不允许增加系统预定义规则
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_AddAlarmSendingRuleV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_V2_S     *pstRule
);

/**
* 修改告警订阅规则V2
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstRule                     告警订阅规则
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 IMOS_ModifyAlarmSendingRuleV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ALARM_SENDING_RULE_V2_S     *pstRule
);

/* End add by l01420, 2014-7-10 for 丹东局点需求汇总*/
/**
* 配置定位信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [IN]   pstLocateInfo           定位信息
* @return ULONG 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigLocateInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  LOCATE_INFO_S               *pstLocateInfo
);

/**
* 查询定位信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [OUT]  pstLocateInfo           定位信息
* @return ULONG 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLocateInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT LOCATE_INFO_S               *pstLocateInfo
);

#if 0
#endif

/* Begin: Modified for 场景增强, by p00232 2012-12-13 */
/***************************************************************************
配置场景
****************************************************************************/
/**
* 增加场景资源
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szOrgCode               组织编码
* @param [IN]     szSceneName             场景名称
* @param [INOUT]  pcSceneCode             场景编码
* @param [IN]     ulIsPrivate             是否私有
* @param [IN]     pcContent               场景内容
* @param [IN]     ulContentLen            场景内容字符长度
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. pcSceneCode由外界传入#IMOS_CODE_LEN长度的字符数组, 由接口返回系统生成的编码
* - 2. 该接口仅支持VM平台
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
* 修改场景资源
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szSceneName             场景名称
* @param [IN]     szSceneCode             场景编码
* @param [IN]     ulIsPrivate             是否私有
* @param [IN]     pcContent               场景内容
* @param [IN]     ulContentLen            场景内容字符长度
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 删除场景资源
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szSceneCode             场景编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelScene
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSceneCode[IMOS_CODE_LEN]
);

/**
* 查询组显示信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szSceneCode             场景编码
* @param [INOUT]  pcSceneName             场景名称
* @param [INOUT]  pulIsPrivate            是否私有
* @param [INOUT]  pcContent               场景内容
* @param [INOUT]  pulContentLen           场景内容字符长度
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 传入的pcContent为NULL时, 只返回相应内容的长度信息
* - 2. 该接口仅支持VM平台
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
* 分页查询场景编码名称列表  \n
* @param [IN]     pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]     pstQueryCondition       通用查询条件
* - 可填NULL
* - 可填条件:暂不实现
* @param [IN]     pstQueryPageInfo        请求分页信息
* @param [INOUT]  pstRspPageInfo          响应分页信息
* @param [INOUT]  pcSceneCodeList         场景编码列表
* @param [INOUT]  pcSceneNameList         场景名称列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. pcSceneCodeList以#IMOS_CODE_LEN为单位;pcSceneNameList以IMOS_NAME_LEN为单位
* - 2. 该接口仅支持VM平台
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
/* 根据CCB结论, 场景增强不使用结构, 平台不理解场景信息, 屏蔽场景共享; 后续采取另外方式合入 */

/* End: Modified for 场景增强, by p00232 2012-12-13 */

/**
* 设置邮件发送的配置 \n
* @param [IN]    pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]    pstEmailSendingConfig        Email发送相关的配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* 获取邮件发送的配置 \n
* @param [IN]    pstUserLogIDInfo             用户登录ID信息标识
* @param [OUT]   pstEmailSendingConfig        Email发送相关的配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* 发送测试邮件， 验证邮件发送的配置是否正确 \n
* @param [IN]    pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]    pstEmailSendingConfig        Email发送相关的配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendTestingEmail
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* 设置短信业务中心配置  \n
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       pstSMSSendingConfig     短信业务中心配置信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySMSSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SMS_SENDING_CONFIG_S            *pstSMSSendingConfig
);

/**
* 获取短信业务中心信息配置  \n
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]      pstSMSSendingConfig     短信业务中心配置信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySMSSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    OUT SMS_SENDING_CONFIG_S            *pstSMSSendingConfig
);

/**
* 测试发送短信，验证短信发送的配置是否正确 \n
* @param [IN]    pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]    pstSMSTestSendingConfig      短信测试发送配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendTestingSMS
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  SMS_TEST_SENDING_CONFIG_S    *pstSMSTestSendingConfig
);

#if 0
#endif

/***************************************************************************
轮切计划V2版本
****************************************************************************/

/**
* 增加轮切计划V2版本
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstSwitchPlanInfo       轮切计划信息
* @param [OUT]  szSwitchPlanCode        轮切计划编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  SWITCH_PLAN_INFO_V2_S           *pstSwitchPlanInfo,
    OUT CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 修改轮切计划V2版本
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szSwitchPlanCode        轮切计划编码
* @param [IN]   pstSwitchPlanInfo       轮切计划信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    IN  SWITCH_PLAN_INFO_V2_S           *pstSwitchPlanInfo
);

/**
* 删除轮切计划V2版本
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szSwitchPlanCode        轮切计划编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 查询轮切计划V2版本
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szSwitchPlanCode        轮切计划编码
* @param [OUT]  pstSwitchPlanInfo       轮切计划信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySwitchPlanV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szSwitchPlanCode[IMOS_RES_CODE_LEN],
    OUT SWITCH_PLAN_INFO_V2_S              *pstSwitchPlanInfo
);

/**
* 查询轮切计划列表V2版本，可以根据条件查，也可以查所有的。
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstSwitchPlanList       轮切计划列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.如果无查询条件,指针pstQueryCondition可以为NULL
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
* 配置行为分析信息
* @param [IN]  pstUserLogIDInfo     用户登录ID信息标识
* @param [IN]  pstChannelIndex      设备通道索引信息
* @param [IN]  pstBehaviorAnalyse   行为分析信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigBehaviorAnalyse
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  IMOS_BEHAVIOR_ANALYSE_INFO_S    *pstBehaviorAnalyse
);

/**
* 查询行为分析信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstChannelIndex     设备通道索引信息
* @param [OUT]  pstBehaviorAnalyse  行为分析信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
资产信息配置，包含增加，修改，删除。
**************************************************************************************/
/**
* 增加资产
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szOrgCode               资产所属组织编码
* @param [IN]     pstAssetInfo            资产信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAsset
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    INOUT   ASSET_INFO_S                *pstAssetInfo
);

/**
* 修改资产
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstAssetInfo           资产信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAsset
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ASSET_INFO_S               *pstAssetInfo
);


/**
* 删除资产
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szAssetCode             资产编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelAsset
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szAssetCode[IMOS_CODE_LEN]
);

/**
* 查询资产
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   ulQueryType          查询方式，取值#ASSET_QUERY_TYPE_E
* @param [IN]   szQryCode            查询编码
* @param [OUT]  pstAssetList         资产信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前支持按设备编码/资产编号查询资产信息
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAsset
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulQueryType,
    IN   CHAR                       szQryCode[IMOS_CODE_LEN],
    OUT  ASSET_INFO_S               *pstAssetInfo
);

/**
* 查询组织下资产信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstAssetList               资产信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有资产(不查子组织)
* - 2.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按"资产名称"模糊查询:#NAME_TYPE
* - 3.支持按资产各属性模糊查询:范围#ASSET_TYPE----#ASSET_PRODEALER
* - 排序
* - 1.不指定排序条件情况下,默认按"资产名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(资产名称),#CODE_TYPE(资产编码)
* - 限制
* - 1. 该接口仅支持VM平台
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
* 查询资产统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szOrgCode               组织编码
* @param [IN]       ulClassification        统计分类，取值#STATISTIC_CLASSIFICATION_TYPE_E，默认为按资产类型分类统计
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pstAssetStatistic       资产统计数组
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 2.支持按资产各属性查询:#ASSET_TYPE,#ASSET_MANUFACTURE,#ASSET_PURCHASE_TIME,#ASSET_WARRANT_TIME,
                           #ASSET_INSTALL_TIME,#ASSET_PRODEALER
* - 3. 该接口仅支持VM平台
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
* 设置设备资产绑定录入策略
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   ulBindPolicy            绑定录入策略，取值#DEVASSET_BINDPOLICY_E
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevAssetBindPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                       ulBindPolicy
);

/**
* 查询设备资产绑定录入策略
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [OUT]  pulBindPolicy          绑定录入策略，取值#DEVASSET_BINDPOLICY_E
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QryDevAssetBindPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  ULONG_32                      *pulBindPolicy
);

/**
* 查询组织下故障设备列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstFaultDevList            故障设备信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有故障设备列表(不查子组织)
* - 2.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按"设备名称"模糊查询:#NAME_TYPE
* - 3.支持按设备类型#DEV_TYPE条件查询，,
            故障类型#FAULT_TYPE条件查询，取值#IMOS_DEV_FAULT_STATUS_E
            故障统计时间#FAULT_STAT_TIME条件查询
* - 排序
* - 1.不指定排序条件情况下,默认按"设备名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(设备名称),#CODE_TYPE(设备编码)
* - 限制
* - 1. 该接口仅支持VM平台
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
* 查询故障设备统计时刻
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szOrgCode               组织编码
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pcStatTimes            故障统计时刻列表(以IMOS_TIME_LEN为单位)
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 2.支持按设备类型查询#DEV_TYPE
* - 3.支持按统计时间查询#FAULT_STAT_TIME
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
* 查询故障设备统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szOrgCode               组织编码
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pstFaultStatistic       故障统计列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 2.支持按设备类型查询#DEV_TYPE
* - 3.支持按统计时间查询#FAULT_STAT_TIME
* - 限制
* - 1. 该接口仅支持VM平台
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
* 更新域拓扑文件信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szParentDomainCode      父域编码
* @param [IN]   szSubDomainCode         子域编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateTopologyInfo
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szParentDomainCode[IMOS_CODE_LEN],
    IN  CHAR                       szSubDomainCode[IMOS_CODE_LEN]
);

/**
* 查询两个域之间的业务信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szParentDomainCode      父域编码
* @param [IN]   szSubDomainCode         子域编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryServiceInfoBetweenDomain
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szParentDomainCode[IMOS_CODE_LEN],
    IN  CHAR                       szSubDomainCode[IMOS_CODE_LEN]
);

/**
* 手工同步业务统计数据
* @param [IN]   pstUserLogIDInfo      用户信息
* @param [IN]   pstSyncSrvInfo        同步业务信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前支持全网资产/故障设备统计数据手动同步
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualSyncStatData
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   SYNC_SERVICE_INFO          *pstSyncSrvInfo
);

/**
* 设置看守位
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szCamCode           摄像头编码
* @param [IN]   pstGuardPos         看守位信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前此接口只支持对外域摄像机设置看守位
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetGuardPosition
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_CODE_LEN],
    IN  GUARD_POSITION_INFO_S   *pstGuardPos
);

/**
* 删除看守位
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szCamCode           摄像头编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前此接口只支持对外域摄像机删除看守位
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGuardPosition
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCamCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* 查询带密码的用户信息
* @param [IN]   *pstQueryCondition        通用查询条件
* @param [OUT]  pstUserPasswordInfo       带密码的用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 对应通用查询条件中的查询项类型分别为:#USER_CODE_TYPE、#USER_NAME_TYPE、#USER_DESC
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserInfoByCondition
(
    IN   USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN   COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT  USER_INFO_PASSWORD_S        *pstUserPasswordInfo
);

/**
* 查询组织下具有某个权限的用户列表 \n
* 不填排序条件时, 默认按用户名称排序
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szOrgCode           组织编码
* @param [IN]   bIsQuerySub         是否查子组织
* @param [IN]   szResCode           资源编码(系统权限可为空'\0')
* @param [IN]   ulResType           资源类型(按系统权限查时填0)
* @param [IN]   ulAuthorityName     权限名(当bHasAnyAuth为BOOL_TRUE时无意义)
* @param [IN]   bHasAnyAuth         是否只要具备任一权限即可
* @param [IN]   pstQueryCondition   通用查询条件(查询条件数量可为0, 但不允直接传NULL;支持的查询条件包括:#USER_NAME_TYPE[用户名称]、#USER_CODE_TYPE[用户编码])
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstUserList         用户信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.按任一权限和按资源权限查暂不支持, 目前只支持按指定的系统权限查, 资源类型填0
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
* 触发紧急事件 \n
* @param [IN]    pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]    szDeviceCode       设备编码
* @param [IN]    ulAlarmType        告警类型(目前仅支持#AlARM_TYPE_IMPERATIVE_EVENT)
* @param [IN]    ulXmlLen           xml字符串长度
* @param [IN]    pcXml              xml字符串
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 刷新摄像机存储索引
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szCamCode               摄像机编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RefreshStoreIdx
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* 配置监视器分屏信息
* @param [IN] pstUserLogIDInfo 用户信息标识
* @param [IN] szScrCode        监视器编码
* @param [IN] pstSplitScrInfo  分屏信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_DEVICE_OFFLINE
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSplitScrInfo
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR                 szScrCode[IMOS_CODE_LEN],
    IN SPLIT_SCR_INFO_S     *pstSplitScrInfo
);

/**
* 查询监视器分屏信息
* @param [IN]  pstUserLogIDInfo 用户信息标识
* @param [IN]  szScrCode        监视器编码
* @param [OUT] pstSplitScrInfo  分屏信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_DEVICE_OFFLINE
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySplitScrInfo
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szScrCode[IMOS_CODE_LEN],
    OUT SPLIT_SCR_INFO_S     *pstSplitScrInfo
);

/* Begin: Added by gaoshufeng(00762), 2013-5-15 for DCV3R5拼接切换 */
/**
* 设置监视器拼接信息
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo           用户信息标识
* @param [IN] CHAR                  szDevCode[IMOS_CODE_LEN]    监视器编码
* @param [IN] DEVINST_S             *pstDevInst                 拼接信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevInst
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szDevCode[IMOS_CODE_LEN],
    IN  DEVINST_S            *pstDevInst
);

/**
* 查询监视器拼接信息
* @param [IN]    USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo           用户信息标识
* @param [IN]    CHAR                   szDevCode[IMOS_CODE_LEN]    监视器编码
* @param [INOUT] DEVINST_S              *pstDevInst                 拼接信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 查询拼接信息，pstDevInst->ulInstType输入10，查询模拟输入信息输入11。
* - 2. 查询摄像机角度与变倍输入21。
* - 3. 查询模拟输入时，pstDevInst->szParam2输入解码通道号
* - 4. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevInst
(
    IN    USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN    CHAR                 szDevCode[IMOS_CODE_LEN],
    INOUT DEVINST_S            *pstDevInst
);
/* End: Added by gaoshufeng(00762), 2013-5-15 for DCV3R5拼接切换 */

/**
* 添加资源到收藏夹 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   ulResType                   资源类型
* @param [IN]   szResCode                   资源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddResToFavorite
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulResType,
    IN  CHAR                        szResCode[IMOS_CODE_LEN]
);

/**
* 从收藏夹删除资源
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   ulResType                   资源类型
* @param [IN]   szResCode                   资源编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResFromFavorite
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulResType,
    IN  CHAR                        szResCode[IMOS_CODE_LEN]
);

/**
* 查询收藏夹资源列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstResList              收藏夹下资源列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 增加第三方EC \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   pstThirdPartyECInfo          第三方EC信息
* @param [IN]   pstVINBindCamBaseInfo        摄像机及其绑定通道的基本信息
* @param [IN]   pstVINFullVarietyElement     视频通道全部变长元素结构体
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddThirdPartyEC
(
    IN USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN THIRDPARTY_EC_S                *pstThirdPartyECInfo,
    IN VINCHNL_BIND_CAMERA_BASE_S     *pstVINBindCamBaseInfo,
    IN VINCHNL_FULL_VARIETY_ELEMENT_S *pstVINFullVarietyElement
);

/**
* 修改第三方EC \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   pstThirdPartyECInfo          第三方EC信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyThirdPartyEC
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN THIRDPARTY_EC_S      *pstThirdPartyECInfo
);

/**
* 删除第三方EC \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   szThirdPartyIPCCode          第三方IPC编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelThirdPartyEC
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR                 szThirdPartyIPCCode[IMOS_CODE_LEN]
);

/**
* 查询一个第三方EC的具体信息 \n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   szThirdPartyIPCCode          第三方IPC编码
* @param [OUT]  pstThirdPartyECInfo          第三方EC信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyEC
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN  CHAR                 szThirdPartyIPCCode[IMOS_CODE_LEN],
    OUT THIRDPARTY_EC_S      *pstThirdPartyECInfo
);

/**
* 查询第三方EC列表
* 不填查询条件时,查所有,默认排序(EC名称升序)
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szOrgCode                   组织域编码
* @param [IN]   pstQueryCondition           通用查询条件(可为NULL, 可填条件: #NAME_TYPE[IPC名称];)
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstThirdPartyECInfoList     第三方EC列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 资源统计数量查询
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   szOrgCode                   组织编码
* @param [IN]   ulResType                   资源类型，取值为#IMOS_TYPE_CAMERA，#IMOS_TYPE_GUARD_TOUR_RESOURCE，#IMOS_TYPE_ALARM_SOURCE，#IMOS_TYPE_ALARM_OUTPUT，#IMOS_TYPE_SALVO_RESOURCE，#IMOS_TYPE_GROUP_SWITCH_RESOURCE，#IMOS_TYPE_SCENE，#IMOS_TYPE_MAP,
* #IMOS_TYPE_BROADCAST_GROUP
* @param [IN]   ulResStatus                 资源状态，只对#IMOS_TYPE_CAMERA有效，取值为#IMOS_DEV_FAULT_STATUS_E, 当取值为#IMOS_DEV_FAULT_STATUS_ALL时表示不分状态
* @param [IN]   bQuerySubOrg                是否查询子组织
* @param [OUT]  pulResNum                   资源数量
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 摄像机的备用存储录像检索 \n
* @param [IN]   pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN]   bExtDomainDev           是否外域共享推送的摄像机
* @param [IN]   pstSDKRecQueryInfo      回放检索消息数据结构，对于外域摄像机，szCamCode为摄像机共享编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstSDKRecordFileInfo    录像文件信息数据结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 查询时间跨度不能大于24小时，且在录像检索流程中时间格式为："%Y-%m-%d %H:%M:%S"格式 ，信息长度限定为24字符
* - 2. 该接口仅支持VM平台
* - 3. 相比于IMOS_SlaveRecordRetrieval，该接口的区别在于返回的录像文件名长度为#IMOS_FILE_NAME_LEN_V2
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
* 获取摄像机的备用存储录像的URL信息V2 \n
* @param[IN]    pstUserLoginIDInfo            用户登录ID信息标识
* @param [IN]   bExtDomainDev               是否外域共享推送的摄像机
* @param[IN]    pstSDKGetUrlInfo            获取URL请求消息数据结构，对于外域摄像机，szCamCode为摄像机共享编码
* @param[OUT]    pstSDKURLInfo               URL信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* - 2. 相比较IMOS_GetSlaveRecordFileURL，该接口的区别在于请求下发的录像文件名长度为#IMOS_FILE_NAME_LEN_V2
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSlaveRecordFileURLV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BOOL_T                      bExtDomainDev,
    IN  GET_URL_INFO_V2_S           *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* 查询摄像机属性的接口 \n
* @param [IN]  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]  CHAR                         szCamCode[IMOS_CODE_LEN]    摄像机编码
* @param [OUT] ULONG		                *pulAttribute               摄像机属性信息，0代表本域摄像机，2代码DVR推送上来的摄像机
* @return 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
* @attention
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamAttribute
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  CHAR                             szCamCode[IMOS_CODE_LEN],
    OUT ULONG_32                            *pulAttribute
);

/**
* 通知DC控制信息处理接口
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo           用户信息标识
* @param [IN] CHAR                  szDevCode[IMOS_CODE_LEN]    监视器编码或DC 编码
* @param [IN] DEVINST_S             *pstDCDCCtrlInfo            DC控制信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 设置系统参数信息
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       ulSysParamNum           系统参数个数, 最大为#IMOS_SYS_PARAM_MAX_NUM
* @param [IN][OUT]  pstSysParamListInfos    系统参数列表信息, 其中信息参数类型必须填写
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSystemParamInfos
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      ULONG_32                   ulSysParamNum,
    INOUT   IMOS_SYS_PARAM_INFO_S   *pstSysParamList
);

/**
* 查询系统参数信息
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       ulSysParamNum           系统参数个数, 最大为#IMOS_SYS_PARAM_MAX_NUM
* @param [IN][OUT]  pstSysParamListInfos    系统参数列表信息, 其中信息参数类型必须填写
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySystemParamInfos
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      ULONG_32                   ulSysParamNum,
    INOUT   IMOS_SYS_PARAM_INFO_S   *pstSysParamList
);

/**
* 查询系统时间，CPU、内存使用率等信息
* @param [IN]       pstUserLogIDInfo     用户登录ID信息标识
* @param [IN]       ulQuerySysInfoNum    查询信息个数 (小于#QUERY_SYS_INFO_NAME_MAX)
* @param [IN][OUT]  pstQuerySysInfoList  查询系统信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_PARAM_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySysInfo
(
    IN     USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN     ULONG_32                 ulQuerySysInfoNum,
    INOUT  QUERY_SYS_INFO_S      *pstQuerySysInfoList
);

/**
* 查询组织下设备的故障详细信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [IN]   pstQueryTimeSlice          查询时间片信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstDevFaultDetailList      设备故障详细信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有故障设备列表(不查子组织)
* - 2.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按"设备名称"模糊查询:#NAME_TYPE
* - 4.支持按"设备编码"精确查询:#CODE_TYPE
* - 5.支持按设备类型#DEV_TYPE条件查询，,
            故障类型#FAULT_TYPE条件查询，取值#IMOS_DEV_FAULT_STATUS_E
            故障统计时间#FAULT_STAT_TIME条件查询
* - 排序
* - 1.不指定排序条件情况下,默认按"设备名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(设备名称),#CODE_TYPE(设备编码),故障发生时间，故障恢复时间，故障时长，故障类型排序。
* - 限制
* - 1. 该接口仅支持VM平台
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
* 查询设备的故障详细信息统计
* @param [IN]       pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]       szOrgCode                   组织编码
* @param [IN]       pstQueryCondition           通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo            请求分页信息
* @param [IN]       pstQueryTimeSlice           查询时间片信息
* @param [OUT]      pstRspPageInfo              响应分页信息
* @param [OUT]      pstDevFaultDetailStat       设备故障详细信息统计
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 2.支持按设备类型查询#DEV_TYPE
* - 3.支持按"设备编码"精确查询:#CODE_TYPE
* - 3.支持按故障发生时间和结束时间查询

* - 排序
* - 1.不指定排序条件情况下,默认按"设备名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(设备名称),#CODE_TYPE(设备编码),故障发生时间，故障恢复时间，故障时长，故障类型排序。

* - 限制
* - 1. 该接口仅支持VM平台
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
* 查询设备的故障频次统计开关
* @param [IN]       pstUserLogIDInfo            用户登录ID信息标识
* @param [OUT]      pulDevFaultStat       设备的故障频次统计开关
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevFaultDetailStatisticGate
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    OUT   ULONG_32                          *pulDevFaultStat
);

/**
* 设置设备的故障频次统计开关
* @param [IN]       pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]       ulDevFaultStat              设备的故障频次统计开关
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDevFaultDetailStatisticGate
(
    IN    USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN    ULONG_32                          ulDevFaultStat
);

/**
* 查询资源路径（附带资源信息） \n
* @param [IN]       pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]       szOrgCode		    所属组织编码
* @param [IN]       szResCode			资源编码
* @param [IN]       ulResType			资源类型
* @param [IN][OUT]  pulTierNum		    资源路径层数
* @param [OUT]      pstResList		    资源信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 返回的列表需要按照从顶级组织(不包括Root节点)到查待询资源自身的顺序排列
* - 2. 当资源类型为本域、外域、虚拟域(组织)时, ulResType统一填#IMOS_TYPE_ORG
* - 3. 如果所查的资源类型为组织域，所属组织编码可以为空'\0'，但不允许传NULL
* - 4. 资源层数参数不超过最大值#IMOS_RES_TREE_LEVEL
* - 5. 出参资源信息结构流套餐参数(ulDevEncodeSet)无效，其它参数有效性与资源类型相关
* - 6. 该接口仅支持VM平台
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
* 获取资源的路径信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szOrgCode           组织节点编码
* @param [IN]   szResCode           资源编码
* @param [IN]   ulResType           资源类型，取值为#IMOS_TYPE_E
* @param [OUT]  szResPath           资源所在路径信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note
* - 1. 如果组织编码未赋值，则当资源被划归时返回其中任意一个划归路径，如果没有划归则返回资源原始加入位置所在路径
* - 2. 当资源类型为本域、外域、虚拟域(组织)时, ulResType统一填#IMOS_TYPE_ORG
* - 3. 路径中不返回最顶级的Root节点，不包含资源名称
* - 4. 返回的路径中各级组织通过" >> "连接，如：本域 >> 浙江省 >> 杭州市 >> 滨江区 >> 长河派出所
* - 5. 该接口仅支持VM平台
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
* 获取资源的排序序号 \n
* @param [IN]     pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]     szOrgCode           父资源组织编码
* @param [IN]     szResCode           资源编码
* @param [IN]     ulResType           资源类型，取值为#IMOS_TYPE_E
* @param [OUT]    pulOrderNumber      资源排序序号值
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 当资源类型为域或组织时，父资源组织编码允许为空
* - 2. 当资源类型为本域、外域、虚拟域(组织)时, ulResType统一填#IMOS_TYPE_ORG
* - 3. 该接口仅支持VM平台
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
* 修改资源的排序序号 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szOrgCode           父资源组织编码
* @param [IN]   szResCode           资源编码
* @param [IN]   ulResType           资源类型，取值为#IMOS_TYPE_E
* @param [IN]   ulOrderNumber       资源排序序号值
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 当资源类型为域或组织时，父资源组织编码允许为空
* - 2. 当资源类型为本域、外域、虚拟域(组织)时, ulResType统一填#IMOS_TYPE_ORG
* - 3. 该接口仅支持VM平台
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
* 查询告警处理记录
* 不填查询条件时,查所有,并默认排序(执行时间升序)
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szEventRecordCode       告警编码
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;可填条件:#USER_NAME_TYPE[用户名称];#OPER_IP[IP地址];#OPER_TYPE[操作类型];#OPER_TIME[操作时间])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstAlarmRecordInfoList  告警记录信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 修改预案
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstActionPlanInfo       预案信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 通用预案不支持转发原告警和产生新告警这两个动作，通用预案的任务执行策略只能是自动
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyActionPlan
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ACTION_PLAN_INFO_S          *pstActionPlanInfo
);

/**
* 删除预案
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szActionPlanCode    预案编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelActionPlan
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szActionPlanCode[IMOS_CODE_LEN]
);

/**
* 查询预案列表
* 不填查询条件时,查所有,并默认排序(预案名称升序)
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;可填条件:#NAME_TYPE[预案名称];#TYPE_ACTION_PLAN[预案类型])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstActionPlanList       预案列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 查询触发器列表
* 不填查询条件时,查所有,并默认排序(触发器ID升序)
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   ulActionPlanType        预案类型，取值为#ACTION_PLAN_TYPE_E
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;可填条件:#NAME_TYPE[触发器名称];#TRIGGER_ID[触发器ID])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstTriggerList          触发器列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 处理任务\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szEventRecordCode   告警编码
* @param [IN]   ulTaskNum           任务数目
* @param [IN]   pstPlanTaskInfoList 任务信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DealWithTask
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szEventRecordCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulTaskNum,
    IN  PLAN_TASK_BASE_INFO_S   *pstPlanTaskInfoList
);

/**
* 触发触发器（确认告警采用原先接口，其他触发器使用此接口）\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szEventRecordCode   告警编码
* @param [IN]   ulTriggerID         触发器ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DealWithTrigger
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szEventRecordCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulTriggerID
);

/**
* 根据告警编码查询触发器列表
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szEventRecordCode       告警编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstTaskTriggerList      触发器信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 根据告警编码查询任务列表
* @param [IN]       pstUserLogIDInfo   用户信息
* @param [IN]       szEventRecordCode  告警编码
* @param [IN][OUT]  pulTaskNum         任务数(入参建议为#IMOS_MAX_TASK_NUM)
* @param [OUT]      pstTaskInfoList    任务信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAlarmTaskInfoList
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szEventRecordCode[IMOS_CODE_LEN],
    INOUT ULONG_32                 *pulTaskNum,
    OUT   PLAN_TASK_BASE_INFO_S *pstTaskInfoList
);

/**
* 增加预案
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstActionPlanInfo       预案信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 通用预案不支持转发原告警和产生新告警这两个动作，通用预案的任务执行策略只能是自动
*       预案编码传入为无效值
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddActionPlan
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR                    szOrgCode[IMOS_CODE_LEN],
    IN      ACTION_PLAN_INFO_S      *pstActionPlanInfo
);

/**
* 查询预案
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szActionPlanCode    预案编码
* @param [OUT]  pstActionPlanInfo   预案信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryActionPlan
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szActionPlanCode[IMOS_CODE_LEN],
    OUT   ACTION_PLAN_INFO_S    *pstActionPlanInfo
);

/**
* 启动预案
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szActionPlanCode    预案编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartActionPlan
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szActionPlanCode[IMOS_CODE_LEN]
);

#if 0
#endif

/**
* 用户启动/接受双向语音对讲 \n
* @param [IN]   pstOperUserInfo      操作用户信息
* @param [IN]   pstDstInfo           目的信息
* @param [IN]   ulVocTalkApplySeq    语音对讲申请序列号，被叫方接受语音时填写
* @param [IN]   ulSrvType            操作业务类型，取值参见#SRV_TYPE_E
* @param [IN]   ulOperateCode        操作原因码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulOperateCode取值参见#CS_OPERATE_CODE_E：
*     主叫用户填写#USER_OPERATE_SERVICE，
*     被叫用户填写#CALLEE_USER_OPERATE_SERVICE
* - 2. 该接口仅支持VM平台
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
* 用户停止/拒绝双向语音对讲 \n
* @param [IN]   pstOperUserInfo      操作用户信息
* @param [IN]   pstDstInfo           目的用户信息
* @param [IN]   ulVocTalkApplySeq    语音对讲申请序列号，被叫方填写
* @param [IN]   ulOperateCode        操作原因码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulOperateCode取值参见#CS_OPERATE_CODE_E：
*     主叫用户填写#USER_OPERATE_SERVICE，
*     被叫用户填写#CALLEE_USER_OPERATE_SERVICE,
*     如果被叫用户不支持此业务的可填写#CALLEE_NOT_SUPPORT_SERVICE
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopUserVoiceTalk
(
    IN  USER_LOGIN_ID_INFO_S            *pstOperUserInfo,
    IN  VOC_SRV_DST_INFO_S              *pstDstInfo,
    IN  ULONG_32                            ulVocTalkApplySeq,
    IN  ULONG_32                            ulOperateCode
);

/**
* 查询语音业务信息 \n
* @param [IN]   pstOperUserInfo     操作用户信息
* @param [IN]   pstQueryCondition   通用查询条件, 只对语音广播起作用
* @param [IN]   pstQueryPageInfo    请求分页信息, 只对语音广播起作用
* @param [OUT]  pstRspPageInfo      返回分页信息
* @param [OUT]  pstRecordInfo       返回语音记录信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 用户启动/接受语音广播 \n
* @param [IN]       pstOperUserInfo      操作用户信息
* @param [IN]       ulVocBrdApplySeq     语音广播申请序列号，被叫方接受语音时填写
* @param [IN]       ulSrvType            操作业务类型，取值参见#SRV_TYPE_E
* @param [IN]       ulOperateCode        操作原因码
* @param [IN]       ulVocBrdUnitNum      广播单元数量
* @param [IN][OUT]  pstVocBrdUnit        语音广播单元列表，作为出参时，填写状态
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulOperateCode取值参见#CS_OPERATE_CODE_E：
*     主叫用户填写#USER_OPERATE_SERVICE，
*     被叫用户填写#CALLEE_USER_OPERATE_SERVICE
* - 2. 该接口仅支持VM平台
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
* 用户停止/拒绝语音广播 \n
* @param [IN]       pstOperUserInfo      操作用户信息
* @param [IN]       ulVocBrdApplySeq     语音广播申请序列号，被叫方停止/拒绝语音时填写
* @param [IN]       ulOperateCode        操作原因码
* @param [IN]       ulVocBrdUnitNum      广播单元数量
* @param [IN][OUT]  pstVocBrdUnit        语音广播单元列表，作为出参时，填写状态
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulOperateCode取值参见#CS_OPERATE_CODE_E：
*     主叫用户填写#USER_OPERATE_SERVICE，
*     被叫用户填写#CALLEE_USER_OPERATE_SERVICE
*     如果被叫用户不支持此业务的可填写#CALLEE_NOT_SUPPORT_SERVICE
* - 2. 该接口仅支持VM平台
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
* 设置组织自动共享标识信息
* @param [IN] pstUserLogIDInfo 用户登录ID信息标识
* @param [IN] pstAutoShareInfo 自动共享信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAutoShareOrg
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN EX_AUTO_SHARE_INFO_S *pstAutoShareInfo
);

/**
* 查询组织自动共享信息
* @param [IN] pstUserLogIDInfo 用户登录ID信息标识
* @param [IN] szExDomainCode 外域编码
* @param [IN] szOrgCode 组织编码
* @param [OUT] pstAutoShareInfo 自动共享信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 查询未共享成功资源记录
* @param [IN]   pstUserLogIDInfo         用户信息
* @param [IN]   szExDomainCode           外域编码
* @param [IN]   pstQueryCondition        查询条件
* @param [IN]   pstQueryPageInfo         请求分页信息
* @param [OUT]  pstRspPageInfo           响应分页信息
* @param [OUT]  pstShareUnsucceedResList 未共享成功资源列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前过滤查询条件支持资源类型(#RES_TYPE)和结果码(#RESULT_CODE)、支持按资源编码和名称排序
* - 2. 该接口仅支持VM平台
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
* 删除未共享成功资源记录
* @param [IN]   pstUserLogIDInfo         用户信息
* @param [IN]   szExDomainCode           外域编码
* @param [IN]   ulDelResNum              待删除记录数目
* @param [IN]   pstShareUnsucceedResList 未共享成功资源列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. ulDelResNum为0表示删除该域所有未共享成功记录
* - 2. 该接口仅支持VM平台
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
* 修改共享摄像机的相关信息(目前只有经纬度信息)
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szOrgCode                   组织节点编码
* @param [IN]   szExDomainCode              外域编码
* @param [IN]   pstCamInfo                  摄像机信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyShareCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  CHAR                            szExDomainCode[IMOS_DOMAIN_CODE_LEN],
    IN  CAMERA_INFO_S                   *pstCamInfo
);

/**
* 录像检索(V2) \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstSDKRecQueryInfo      回放检索消息数据结构
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstSDKRecordFileInfo    录像文件信息数据结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 查询时间跨度不能大于24小时，且在录像检索流程中时间格式为："%Y-%m-%d %H:%M:%S"格式 ，信息长度限定为24字符.
* - 2. 文件名字符串数组最大长度为#IMOS_FILE_NAME_LEN_V2
* - 3. 该接口仅支持VM平台
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
* 获取录像文件的URL信息(V2) \n
* @param[IN]    pstUserLogIDInfo            用户登录ID信息标识
* @param[IN]    pstSDKGetUrlInfo            获取URL请求消息数据结构
* @param[IN]    pstSDKURLInfo               URL信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 构造SOI消息的IE结构使用#SOI_IE_GET_REC_URL_V2_S，而非#SOI_IE_GET_URL_S
*          注意与SDK接口IMOS_GetBakRecordFileURL的区别
*          AS_RQ模块在处理GetURL业务时，会将#SOI_IE_GET_REC_URL_V2_S中的信息转换为#SOI_IE_GET_URL_S
* - 2. 文件名字符串数组最大长度为#IMOS_FILE_NAME_LEN_V2
* - 3. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetURLV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_V2_S           *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);
/* End add by z07291 for VVD64632 */

/**
* 获取录像文件的URL信息(V3) \n
* @param[IN]    pstUserLogIDInfo            用户登录ID信息标识
* @param[IN]    pstSDKGetUrlInfo            获取URL请求消息数据结构
* @param[IN]    pstSDKURLInfo               URL信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 相比V2接口，扩展了回放中继策略的信息
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetURLV3
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  GET_URL_INFO_V3_S           *pstSDKGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* 新增一个事件使能策略
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szAlarmSrcCode      告警源编码，允许为空，表示系统告警类型的使能策略
* @param [IN]   ulEventType         事件类型ID
* @param [IN]   pstEventEnableInfo  事件使能策略信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType,
    IN    EVENT_ENABLE_INFO_S   *pstEventEnableInfo
);

/**
* 更新一个事件使能策略
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szAlarmSrcCode      告警源编码，允许为空，表示系统告警类型的使能策略
* @param [IN]   ulEventType         事件类型ID
* @param [IN]   pstEventEnableInfo  事件使能策略信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType,
    IN    EVENT_ENABLE_INFO_S   *pstEventEnableInfo
);

/**
* 查询一个事件使能策略
* @param [IN]     pstUserLogIDInfo      用户信息
* @param [IN]     szAlarmSrcCode        告警源编码，允许为空，表示系统告警类型的使能策略
* @param [IN]     ulEventType           事件ID
* @param [OUT]    pstEventEnableInfo    事件使能策略信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType,
    OUT   EVENT_ENABLE_INFO_S   *pstEventEnableInfo
);

/**
* 删除一个事件使能策略
* @param [IN]   pstUserLogIDInfo    用户信息
* @param [IN]   szAlarmSrcCode      告警源编码，允许为空，表示系统告警类型的使能策略
* @param [IN]   ulEventType         事件类型ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN    CHAR                  szAlarmSrcCode[IMOS_CODE_LEN],
    IN    ULONG_32                 ulEventType
);

/**
* 批量新增告警源的事件使能策略
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstBathEventEnableInfo  批量设置设备信息
* @param [IN]   pstEventEnableInfo      事件使能策略信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BathAddEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    BATH_EVENT_ENABLE_INFO_S  *pstBathEventEnableInfo,
    IN    EVENT_ENABLE_INFO_S       *pstEventEnableInfo
);

/**
* 批量删除告警源的事件使能策略
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstBathEventEnableInfo  批量设置设备信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BathDelEventStrategy
(
    IN    USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN    BATH_EVENT_ENABLE_INFO_S  *pstBathEventEnableInfo
);

/**
* 查询系统告警类型信息
* 不填查询条件时,查所有,并默认排序(告警级别升序)
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   pstQueryCondition       通用查询条件(可为NULL;#EVENT_TYPE_NAME[告警事件名称]; #EVENT_SECURITY[告警事件级别];#NAME_TYPE[告警事件类型名称];)
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  psEventTypeInfoList     告警类型信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 只支持事件名称、事件类型名称的模糊查询以及事件级别查询
* - 2. 该接口仅支持VM平台
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
* 查询本域、协议告警类型对应关系信息\n
* @param [IN]   pstUserLogIDInfo              用户登录ID信息标识
* @param [IN]   szEventTypeL2ORelCode         本域、协议告警类型对应关系ID编码
* @param [OUT]   pstEventTypeL2Orel           本域、协议告警类型对应关系信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventTypeL2ORel
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   CHAR                        szEventTypeL2ORelCode[IMOS_CODE_LEN],
    OUT  EVENT_TYPE_L2OREL_S         *pstEventTypeL2Orel
);

/**
* 添加本域、协议告警类型对应关系信息\n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   pstEventTypeL2Orel           本域、协议告警类型对应关系信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventTypeL2ORel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_TYPE_L2OREL_S         *pstEventTypeL2Orel
);

/**
* 删除本域、协议告警类型对应关系信息\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szEventTypeL2ORelCode   本域、协议告警类型对应关系ID编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventTypeL2ORel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szEventTypeL2ORelCode[IMOS_CODE_LEN]
);

/**
* 修改本域、协议告警类型对应关系信息\n
* @param [IN]   pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   pstEventTypeL2Orel           本域、协议告警类型对应关系信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEventTypeL2ORel
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_TYPE_L2OREL_S         *pstEventTypeL2Orel
);

/**
* 分页查询本域、协议告警类型关系列表
* 不填查询条件时,查所有
* @param [IN]   pstUserLogIDInfo              用户信息
* @param [IN]   pstQueryCondition             通用查询条件(可为NULL;可填条件:#EVENT_TYPE[事件类型])
* @param [IN]   pstQueryPageInfo              请求分页信息
* @param [OUT]  pstRspPageInfo                返回分页信息
* @param [OUT]  pstEventTypeL2OrelList        本域、协议告警类型对应关系
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 查询输出开关量信息V2
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [OUT]  pstSemaOutputInfo       输出开关量信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOutSwitch_V2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT SEMA_OUTPUT_INFO_V2_S       *pstSemaOutputInfo
);

/**
* 配置设备的输出开关量V2
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstChannelIndex         设备通道索引信息
* @param [IN]   pstSemaOutputInfo         输出开关量信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfOutSwitch_V2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  SEMA_OUTPUT_INFO_V2_S       *pstSemaOutputInfo
);

/**
* SDK客户端不退出情况下，只清空本地用户登录信息接口，主要实现发送用户退出消息以及回收SDK为该用户业务所申请的资源。 \n
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @return ULONG  返回如下结果:
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件。
* @note
* 1、只清除gstAutoKeepAliveCB中所有信息、gstClibSysCB中的用户登录信息以及gpUICallBackFunc指针;
* 2、SDK用户后续直接再次登录后，订阅推送消息并注册回调函数, 即可进行其他SDK业务;
* 3、本接口不校验用户信息，需要用户自己注销之前登录的用户，本接口会调用gpUICallBackFunc通知用户退出，故暂只适用于BM
使用;
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CleanUpUserInfoOnlyforClientNotExit
(
    IN  USER_LOGIN_ID_INFO_S *pstUserLogIDInfo
);
/**
* 添加单个层文件开始
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   pstLayerInfo             层文件信息
* @param [OUT]  pstFtpInfo              FTP信息
* @param [OUT]  pulSequenceNumber       本次FTP服务器的序列号
* @note
* - 1. 该接口仅支持VM平台
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
* 将上传层图层文件的结果, 通知服务器
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   bIsSuccess              上传文件的结果, #BOOL_TRUE为成功; #BOOL_FALSE为失败
* @param [IN]   ulSequenceNumber        本次FTP服务器的序列号
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGisLayerEnd
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BOOL_T                      bIsSuccess,
    IN  ULONG_32                       ulSequenceNumber
);

/**
* 更新单个层文件开始
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   pstOldLayerInfo         更新前层文件信息
* @param [IN]   pstNewLayerInfo         更新后层文件信息
* @param [OUT]  pstFtpInfo              FTP信息
* @param [OUT]  pulSequenceNumber       本次FTP服务器的序列号
* @note
* - 1. 该接口仅支持VM平台
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
* 将上传层文件的结果, 通知服务器
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   bIsSuccess              上传文件的结果, #BOOL_TRUE为成功; #BOOL_FALSE为失败
* @param [IN]   ulSequenceNumber        本次FTP服务器的序列号
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateGisLayerEnd
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  BOOL_T                  bIsSuccess,
    IN  ULONG_32                   ulSequenceNumber
);

/**
* 下载层文件列表开始
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [INOUT]  pulLayerNumber          层文件数量
* @param [INOUT]  pstFtpInfo              FTP信息列表
* @param [OUT]    pulSequenceNumber       本次FTP服务器的序列号
* @note
* - 1. 该接口仅支持VM平台
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
* 将下载层文件的结果, 通知服务器
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   bIsSuccess              下载文件的结果, #BOOL_TRUE为成功; #BOOL_FALSE为失败
* @param [IN]   ulSequenceNumber        本次FTP服务器的序列号
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DownloadGisLayersEnd
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  BOOL_T                      bIsSuccess,
    IN  ULONG_32                       ulSequenceNumber
);

/**
* 获取GIS图层相关信息(除基础图层)
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [OUT]  pulLayerNumber          图层数目
* @param [OUT]  pstLayerInfo            图层信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLayerMapInfo
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_CODE_LEN],
    OUT ULONG_32                        *pulLayerNumber,
    OUT LAYER_BASIC_INFO_S           *pstLayerInfo
);

/**
* 删除GIS图层
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [IN]   szLayerName             图层文件名
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 注意，如果删除空文件，也需要返回成功：
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelGisLayer
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szGISMapCode[IMOS_CODE_LEN],
    IN  CHAR                    szLayerName[IMOS_NAME_LEN]
);

/**
* 获取GIS地图颜色信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [OUT]  pstMapColors            GIS颜色
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMapColors
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_CODE_LEN],
    OUT FILE_MAP_COLORS_S            *pstMapColors
);

/**
* 配置GIS地图颜色信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szGISMapCode            GIS地图编码
* @param [OUT]  pstMapColors            GIS颜色
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMapColors
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szGISMapCode[IMOS_CODE_LEN],
    IN  FILE_MAP_COLORS_S            *pstMapColors
);

/**
* 添加事件级别信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstEventType       事件级别信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 添加的事件级别ID范围为5--30
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEventSecurityType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_SECURITY_TYPE_S       *pstEventSecurityType
);

/**
* 删除事件级别信息 \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   ulEventSecurityType    事件级别ID
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 允许删除的事件级别ID范围为5-30
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEventSecurityType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulEventSecurityType
);

/**
* 修改事件级别信息 \n
* @param [IN]   pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]   pstEventType       事件级别信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEventSecurityType
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  EVENT_SECURITY_TYPE_S       *pstEventSecurityType
);

/**
* 查询事件级别信息 \n
* @param [IN]   pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]   ulEventSecurityType       事件级别ID
* @param [OUT]  pstEventSecurityType      事件级别信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEventSecurityType
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   ULONG_32                       ulEventSecurityType,
    OUT  EVENT_SECURITY_TYPE_S       *pstEventSecurityType
);

/**
* 查询事件级别类型列表 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstQueryCondition   通用查询条件
* @param [IN]   pstQueryPageInfo    查询分页信息
* @param [OUT]  pstRspPageInfo      查询返回分页信息
* @param [OUT]  pstSecurityTypeList 类型信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 条件可以为NULL,表示查询所有事件级别信息
* - 2. 支持按"事件级别名称"模糊查询:#NAME_TYPE;
* - 3. 该接口仅支持VM平台
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
* 启动播放器组件。\n
* @param [IN]   pstUserLoginIDInfo  用户登录ID信息标识
* @param [IN]   ulPlayWndNum        播放窗格数量。
* @param [INOUT]   pstPlayWndInfo      播放窗格编码结构体指针。
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlayerEx
(
     IN USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
     IN ULONG_32                    ulPlayWndNum,
     INOUT PLAY_WND_INFO_S       *pstPlayWndInfo
);

/**
* 获取摄像机的DecoderTag信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szCamCode               摄像机编码
* @param [OUT]  szDecoderTag            DecoderTag
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDecoderTag
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szCamCode[IMOS_CODE_LEN],
    OUT CHAR                         szDecoderTag[IMOS_STRING_LEN_64]
);

/**
* 启动/停止组轮巡计划 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息标识
* @param [IN]   szGroupsalvoPlanCode    组轮巡计划编码
* @param [IN]   ulProcessType           操作类型: 启动/停止
* @param [IN]   ulOperateCode           操作原因码: #CS_OPERATE_CODE_E
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
案件信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加案件
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szOrgCode               案件所属组织编码
* @param [INOUT]  pstCaseInfo             案件信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCase
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    INOUT   CASE_INFO_S                 *pstCaseInfo
);

/**
* 修改案件
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstCaseInfo            案件信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_INFO_S                *pstCaseInfo
);

/**
* 删除案件
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szCaseCode              案件编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szCaseCode[IMOS_CODE_LEN]
);

/**
* 查询案件
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szCaseCode           案件编号
* @param [OUT]  pstCaseInfo          案件信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szCaseCode[IMOS_CODE_LEN],
    OUT  CASE_INFO_S                *pstCaseInfo
);

/**
* 复制案件
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szSrcCaseCode           源案件编号
* @param [IN]     szDstCaseCode           目的案件编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DuplicateCase
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   CHAR                        szSrcCaseCode[IMOS_CODE_LEN],
    IN   CHAR                        szDstCaseCode[IMOS_CODE_LEN]
);

/*************************************************************************************
案件涉及人员信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加案件人员信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstCasePersInfo         案件人员信息，出参将案件人员编码返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCasePersonnel
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   CASE_PERSONNEL_INFO_S       *pstCasePersInfo
);

/**
* 修改案件人员信息
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstCasePersInfo        案件人员信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCasePersonnel
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_PERSONNEL_INFO_S      *pstCasePersInfo
);

/**
* 删除案件人员
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   ulPersonnelType         案件人员类型，取值#CASE_PERSONNEL_TYPE_E
* @param [IN]   szPersCode              案件人员编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCasePersonnel
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulPersonnelType,
    IN   CHAR                       szPersCode[IMOS_CODE_LEN]
);

/**
* 查询案件人员信息
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   ulPersonnelType      案件人员类型，取值#CASE_PERSONNEL_TYPE_E
* @param [IN]   szPersCode           案件人员编号
* @param [OUT]  pstCasePersInfo      案件人员信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 查询案件的人员信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   ulPersonnelType            案件人员类型，取值#CASE_PERSONNEL_TYPE_E
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCasePersList            案件人员信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定案件下所有人员信息
* - 2.支持按"人员类别"过滤查询
* - 3.支持按"人员名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"人员名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(人员名称),#CODE_TYPE(人员编号)
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
案件涉及车辆信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加案件车辆信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstCaseVehicleInfo      案件车辆信息，出参将案件车辆编码返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseVehicle
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   CASE_VEHICLE_INFO_S         *pstCaseVehicleInfo
);

/**
* 修改案件车辆信息
* @param [IN]   pstUserLogIDInfo          用户信息
* @param [IN]   pstCaseVehicleInfo        案件车辆信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseVehicle
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_VEHICLE_INFO_S        *pstCaseVehicleInfo
);

/**
* 删除案件车辆
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szVehicleCode           案件车辆编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCaseVehicle
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szVehicleCode[IMOS_CODE_LEN]
);

/**
* 查询案件车辆信息
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szVehicleCode        案件车辆编号
* @param [OUT]  pstCaseVehicleInfo   案件车辆信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseVehicle
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szVehicleCode[IMOS_CODE_LEN],
    OUT  CASE_VEHICLE_INFO_S        *pstCaseVehicleInfo
);

/**
* 查询案件的车辆信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCaseVehicleList         案件车辆信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定案件下所有车辆信息
* - 2.支持按"车牌号码"模糊查询:#PLATE_CODE
* - 排序
* - 1.不指定排序条件情况下,默认按"车牌号码"升序排序
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
案件涉及物品信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加案件物品信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstCaseStuffInfo        案件物品信息，出参将案件物品编码返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseStuff
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    INOUT   CASE_STUFF_INFO_S           *pstCaseStuffInfo
);

/**
* 修改案件物品信息
* @param [IN]   pstUserLogIDInfo          用户信息
* @param [IN]   pstCaseStuffInfo          案件物品信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseStuff
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_STUFF_INFO_S          *pstCaseStuffInfo
);

/**
* 删除案件物品
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szStuffCode             案件物品编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCaseStuff
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szStuffCode[IMOS_CODE_LEN]
);

/**
* 查询案件物品信息
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szStuffCode          案件物品编号
* @param [OUT]  pstCaseStuffInfo     案件物品信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseStuff
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szStuffCode[IMOS_CODE_LEN],
    OUT  CASE_STUFF_INFO_S          *pstCaseStuffInfo
);

/**
* 查询案件的物品信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCaseStuffList           案件物品信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定案件下所有物品信息
* - 2.支持按"物品名称"模糊查询:#NAME_TYPE
* - 3.支持按"物品类别"查询:#STUFF_TYPE
* - 4.支持按"物品性质"查询:#STUFF_PROPERTY
* - 排序
* - 1.不指定排序条件情况下,默认按"物品名称"升序排序
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
串并案信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加串并案
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szOrgCode               串并案所属组织编码
* @param [IN]     pstSeriesCaseInfo       串并案信息，IN时,串并案编码可以为空;如果为空,则OUT串并案编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSeriesCase
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szOrgCode[IMOS_CODE_LEN],
    INOUT   SERIES_CASE_INFO_S          *pstSeriesCaseInfo
);

/**
* 修改串并案
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstSeriesCaseInfo      串并案信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySeriesCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   SERIES_CASE_INFO_S         *pstSeriesCaseInfo
);

/**
* 删除串并案
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szSeriesCaseCode        串并案编号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSeriesCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSeriesCaseCode[IMOS_CODE_LEN]
);

/**
* 查询串并案
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szSeriesCaseCode     串并案编号
* @param [OUT]  pstSeriesCaseInfo    串并案信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySeriesCase
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szSeriesCaseCode[IMOS_CODE_LEN],
    OUT  SERIES_CASE_INFO_S         *pstSeriesCaseInfo
);

/**
* 查询部门下串并案信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szDeptCode                 部门编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstSeriesCaseList          串并案信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEPT_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定部门下所有串并案(不查子部门)
* - 2.支持按"是否查子部门"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按串并案编号和名称模糊查询:#NAME_TYPE,#CODE_TYPE
* - 4.支持按串并案属性查询:串并案类型:#SERIESCASE_TYPE，所含案件编号:#CASEINSE_CODE
* - 排序
* - 1.不指定排序条件情况下,默认按"串并案编号"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(串并案名称),#CODE_TYPE(串并案编号)
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
* 增加案件到串并案
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szSeriesCaseCode        串并案编码
* @param [IN]     ulCaseNum               案件数目，最大值#IMOS_CASE_MAXNUM_PER_SERIESCASE
* @param [IN]     pcCaseCodeList          案件编码列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 共享案件
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szCaseCode              案件编号
* @param [IN]     ulShareFlag             共享标志: 0为取消共享，1为共享
* @param [IN]     ulShareType             共享类型，取值#CASE_SHARE_TYPE_E
* @param [IN]     szResCode               共享目标编码(用户编码/组织编码)
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 目前只支持共享给用户
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
* 查询案件共享目标列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstShareDstList            案件共享目标信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CASE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 目前仅支持查询案件共享的用户列表
* - 过滤
* - 1.支持按共享类型过滤查询:#CASESHARE_TYPE，取值#CASE_SHARE_TYPE_E.
* - 2.支持按共享目标编码和名称模糊查询:#CODE_TYPE,#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"目标编码"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(目标名称),#CODE_TYPE(目标编码)
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
* 查询共享给目标的案件列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   ulShareType                共享类型，取值#CASE_SHARE_TYPE_E
* @param [IN]   szResCode                  共享目标编码(用户编码/组织编码)
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCaseList                共享案件信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查共享给该目标的案件列表
* - 3.支持按案件各属性查询:案件编号/名称/性质/类型/状态/警情来源/开始时间/结束时间
      见#CASE_PROPERTY-------#CASE_END_TIME
* - 排序
* - 1.不指定排序条件情况下,默认按"案件编号"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(案件名称),#CODE_TYPE(案件编号)
    目前仅支持查共享给某用户的案件列表
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
案件关联信息(录像/图片/其他文件)配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加案件录像信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szCaseCode              案件编号
* @param [INOUT]     pstCaseRecord        案件录像信息，出参将案件录像编码返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseRecord
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szCaseCode[IMOS_CODE_LEN],
    INOUT   CASE_RECORD_INFO_S          *pstCaseRecord
);

/**
* 修改案件录像信息
* @param [IN]   pstUserLogIDInfo          用户信息
* @param [IN]   pstCaseRecord             案件录像信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseRecord
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_RECORD_INFO_S         *pstCaseRecord
);

/**
* 删除案件关联信息
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   ulRelationType          关联信息类型,取值#CASE_RELATEDINFO_TYPE_E
* @param [IN]   szInfoCode              案件关联信息编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCaseRelatedInfo
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   ULONG_32                      ulRelationType,
    IN   CHAR                       szInfoCode[IMOS_CODE_LEN]
);

/**
* 查询案件录像信息
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szRecordCode         案件录像编号
* @param [OUT]  pstCaseRecInfo       案件录像信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseRecord
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szRecordCode[IMOS_CODE_LEN],
    OUT  CASE_RECORD_INFO_S         *pstCaseRecInfo
);

/**
* 查询案件的录像信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCaseRecList             案件录像信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -    返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定案件下所有录像信息
* - 2.支持按"视频监控点名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"视频监控点名称"升序排序
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
* 获取案件录像文件下载信息 \n
* @param[IN]    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo       用户登录ID信息标识
* @param[IN]    ULONG                    ulCaseRecSrvType        案件录像业务类型，0:下载，1:回放
* @param[IN]    CHAR                     szRecordCode            案件录像编号
* @param[INOUT] ULONG                    *pulRecFileNum          案件录像文件下载数组长度，最大取值IMOS_FILE_MAXNUM_PER_CASERECORD
* @param[IN]    FILE_DOWNLOAD_INFO_S     *pstFileDLInfo          录像下载信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 增加案件关联文件信息
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szCaseCode              案件编号
* @param [IN]     pstCaseFile             案件文件信息，出参将案件文件编码返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCaseFile
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szCaseCode[IMOS_CODE_LEN],
    INOUT   CASE_FILE_INFO_S            *pstCaseFile
);

/**
* 修改案件文件信息
* @param [IN]   pstUserLogIDInfo          用户信息
* @param [IN]   pstCaseFile               案件文件信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCaseFile
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CASE_FILE_INFO_S           *pstCaseFile
);

/**
* 查询案件文件信息
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szFileCode           案件文件编码
* @param [OUT]  pstCaseFileInfo      案件文件信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCaseFile
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szFileCode[IMOS_CODE_LEN],
    OUT  CASE_FILE_INFO_S           *pstCaseFileInfo
);

/**
* 查询案件的文件信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCaseFileList            案件文件信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定案件下所有文件信息
* - 2.支持按"文件类型"过滤查询:#FILE_TYPE
* - 2.支持按"文件名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"文件名称"升序排序
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
电子公告信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加电子公告
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstEBInfo               公告信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEBulletin
(
    IN   USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN   ELECTRONIC_BULLETIN_INFO_S   *pstEBInfo
);

/**
* 修改电子公告
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstEBInfo              公告信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyEBulletin
(
    IN   USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN   ELECTRONIC_BULLETIN_INFO_S   *pstEBInfo
);

/**
* 删除电子公告
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szBulletinCode          公告编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelEBulletin
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szBulletinCode[IMOS_CODE_LEN]
);

/**
* 查询电子公告
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szBulletinCode       公告编码
* @param [OUT]  pstEBulletinInfo     公告信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEBulletin
(
    IN   USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN   CHAR                         szBulletinCode[IMOS_CODE_LEN],
    OUT  ELECTRONIC_BULLETIN_INFO_S   *pstEBulletinInfo
);

/**
* 查询公告信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstEBulletinList           公告信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查所有公告
* - 排序
* - 1.不指定排序条件情况下,默认按"发布时间"降序排序
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
* 在组织下按人员进行案件处理查询统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szOrgCode               组织编码
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pstCaseProStatistic     案件处理统计数组
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按人员关联录像数量/结案数量统计
* - 3.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
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
案件资料查阅用户配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 案件资料查阅用户配置
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     ulOperType              操作类型，0:增加用户，1:删除用户
* @param [IN]     ulDataType              案件资料类型，取值#CASE_DATA_TYPE_E
* @param [IN]     szCaseDataCode          案件资料编码
* @param [IN]     szUserName              用户名称
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 案件资料查阅用户列表查询
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pcUserNameList             用户名称列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.支持按案件资料编码类型查询:#CODE_TYPE
* - 2.支持按案件资料类型查询:#CASE_DATA_TYPE
* - 2.支持按"用户名称"模糊查询:#USER_NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"用户编码"升序排序
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
案件图片组信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 增加案件图片组
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szCaseCode              案件编号
* @param [IN]     pstPicGrpInfo           图片组信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCasePicGroup
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      CHAR                        szCaseCode[IMOS_CODE_LEN],
    INOUT   PICTURE_GROUP_INFO_S        *pstPicGrpInfo
);

/**
* 删除案件图片组
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     szPicGrpCode            图片组编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCasePicGroup
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   CHAR                        szPicGrpCode[IMOS_CODE_LEN]
);

/**
* 修改案件图片组
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstPicGrpInfo           图片组信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCasePicGroup
(
    IN   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN   PICTURE_GROUP_INFO_S        *pstPicGrpInfo
);

/**
* 查询案件图片组信息
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szPicGrpCode         图片组编码
* @param [OUT]  pstPicGrpInfo        图片组信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCasePicGroup
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   CHAR                       szPicGrpCode[IMOS_CODE_LEN],
    OUT  PICTURE_GROUP_INFO_S       *pstPicGrpInfo
);

/**
* 查询案件的图片组信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szCaseCode                 案件编号
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCasePicGrpList          案件图片组信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_GACASE_CODE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定案件下所有录像信息
* - 2.支持按"图片组名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"图片组名称"升序排序
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
部门信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 配置用户部门信息
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   ulCfgType                   配置类型,0:配置部门，1:取消配置部门
* @param [IN]   szUserCode                  用户编码
* @param [IN]   szDeptCode                  部门编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigUserDeptInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  ULONG_32                       ulCfgType,
    IN  CHAR                        szUserCode[IMOS_CODE_LEN],
    IN  CHAR                        szDeptCode[IMOS_CODE_LEN]
);

/**
* 查询用户部门信息
* @param [IN]   pstUserLogIDInfo           用户信息标识
* @param [IN]   szUserCode                   用户编码
* @param [OUT]   DEPT_INFO_S          用户部门信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserDeptInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szUserCode[IMOS_CODE_LEN],
    OUT DEPT_INFO_S                 *pstDeptInfo
);

/**
* 在单位下按照单位信息按照条件做案件统计或者上传资料统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szDepartmentCode        单位编码
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [IN]       ulQueryFlag             查询标志位(统计案件数或者资料数#CASE_STAT_FLAG_S)
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pstCaseDepartmentStat   单位下的案件信息统计
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按统计开始时间#STAT_START_TIME，和统计结束时间#STAT_END_TIME进行统计
* - 2.支持按照案件信息的案件性质，案件所属单位查询
* - 3、支持是否查询所属子单位的查询
* - 排序
* - 1.默认按"单位名称"升序排序
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
* 在单位下按照用户信息按照条件做案件统计或者上传资料统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szDepartmentCode        单位编码
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [IN]       ulQueryFlag             查询标志位(统计案件数或者资料数#CASE_STAT_FLAG_S)
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pstCaseDepartmentStat   单位下的案件信息统计
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按统计开始时间#STAT_START_TIME，和统计结束时间#STAT_END_TIME进行统计
* - 2.支持按照案件信息的案件性质，案件状态，用户编码，用户所属单位编码
* - 3、支持是否查询所属子单位的查询
* - 排序
* - 1.默认按"用户名称"升序排序
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
* 在单位下按照条件做案件信息分析统计
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szDepartmentCode        单位编码
* @param [IN]       pstQueryCondition       通用查询条件，若无查询条件可填为NULL
* @param [IN]       pstQueryPageInfo        请求分页信息
* @param [OUT]      pstRspPageInfo          响应分页信息
* @param [OUT]      pstCaseInfoAnalysisStat 单位下的案件信息分析统计
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按统计开始时间#STAT_START_TIME，和统计结束时间#STAT_END_TIME进行统计
* - 2.支持按照案件信息的案件性质，案件状态，用户编码
* - 排序
* - 1.默认按"单位名称"升序排序
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
* 根据地点查询周边摄像机列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  NEIGHBOR_CAMERA_INFO_S     周边摄像机信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_DEVICE_LOCATION_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1.支持按"设备编码"过滤查询该设备周边的摄像机列表:#CODE_TYPE，支持的设备包括摄像机，卡口，卡口相机
* - 2.支持按"周边范围"查询:#DISTANCE_RANGE
* - 3.支持按"摄像机名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"摄像机名称"升序排序
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
WebGis信息配置，包含增加，修改，删除，查询。
**************************************************************************************/
/**
* 添加WebGIS
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]       szOrgCode               组织编码
* @param [INOUT]    pstWebGisBaseInfo       WebGis地图信息，地图编码由后台返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddWebGis
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN     CHAR                            szOrgCode[IMOS_CODE_LEN],
    INOUT  WEBGIS_BASE_INFO_S              *pstWebGisBaseInfo
);

/**
* 修改WebGIS
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstWebGisBaseInfo       WebGis地图信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyWebGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  WEBGIS_BASE_INFO_S              *pstWebGisBaseInfo
);

/**
* 删除WebGIS
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szWebGisCode            地图编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelWebGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szWebGisCode[IMOS_CODE_LEN]
);

/**
* 查询WebGIS
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szWebGisCode            地图编码
* @param [OUT]  pstBaseInfo             WebGis地图信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGis
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szWebGisCode[IMOS_CODE_LEN],
    OUT WEBGIS_BASE_INFO_S              *pstWebGisBaseInfo
);

/**
* 查询WebGIS信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstWebGisList              WebGis地图信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有WebGis地图信息
* - 2.支持按"是否为默认地图"过滤查询:#DEFAULT_WEBGIS_MAP
* - 2.支持按"地图名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"地图名称"升序排序
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
* 添加WebGIS关注点
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [INOUT]    pstAttentivePoint       WebGis地图关注点信息，关注点编码由后台返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddWebGisAttPoint
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    INOUT  WEBGIS_ATTENTIVE_POINT_S        *pstAttentivePoint
);

/**
* 修改WebGIS关注点
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstAttentivePoint       WebGis地图关注点信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyWebGisAttPoint
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  WEBGIS_ATTENTIVE_POINT_S        *pstAttentivePoint
);

/**
* 删除WebGIS关注点
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szPointCode            关注点编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelWebGisAttPoint
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szPointCode[IMOS_CODE_LEN]
);

/**
* 查询WebGIS关注点
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szPointCode             地图编码
* @param [OUT]  pstAttentivePoint       WebGis地图关注点信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryWebGisAttPoint
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szPointCode[IMOS_CODE_LEN],
    OUT WEBGIS_ATTENTIVE_POINT_S        *pstAttentivePoint
);

/**
* 查询WebGIS地图关注点信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szMapCode                  地图编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstWebGisList              WebGis地图信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有WebGis地图信息
* - 2.支持按"是否为地图默认关注点"过滤查询:#DEFAULT_WEBGIS_POINT
* - 2.支持按"关注点名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"关注点名称"升序排序
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
* 添加社会资源摄像机
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [INOUT]    pstComCameraInfo        社会资源摄像机信息，IN时,摄像机编码可以为空;如果为空,则OUT摄像机编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCommunityCamera
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    INOUT  COMMUNITY_CAMERA_INFO_S         *pstComCameraInfo
);

/**
* 修改社会资源摄像机
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstComCameraInfo        社会资源摄像机信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCommunityCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMUNITY_CAMERA_INFO_S         *pstComCameraInfo
);

/**
* 删除社会资源摄像机
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szComCameraCode         社会资源摄像机编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCommunityCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szComCameraCode[IMOS_CODE_LEN]
);

/**
* 查询社会资源摄像机
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szComCameraCode         社会资源摄像机编码
* @param [OUT]  pstComCameraInfo        社会资源摄像机信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCommunityCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szComCameraCode[IMOS_CODE_LEN],
    OUT COMMUNITY_CAMERA_INFO_S         *pstComCameraInfo
);

/**
* 查询社会资源摄像机信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstCameraList              社会资源摄像机信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有社会资源摄像机信息
* - 2.支持按"摄像机名称"模糊查询:#NAME_TYPE
* - 排序
* - 1.不指定排序条件情况下,默认按"摄像机名称"升序排序
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
* 同步资源到GIS地图上
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szGisCode           同步地图编码
* @param [IN]   ulResType           同步的资源类型
* @param [IN]   pstGisDbInfo        GIS数据库的信息(此参数暂时未使用，保留)
* @param [IN]
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 查询组织下面摄像机云台信息 \n
* 不填查询条件时,查所有,并默认排序(摄像机名称升序)
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   szOrgCode          组织节点编码
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL)
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pstCamPTZInfo      摄像机云台信息列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 可填通用查询条件:
*     #NAME_TYPE[摄像机名称]
*     #CODE_TYPE[摄像机编码]
* - 2. 只会查询云台类摄像机
* - 3. 该接口仅支持VM平台
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
* 修改摄像机云台信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstCameraPTZInfo    摄像机云台信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 目前只能修改 云台标识ulPtzID
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModCameraPTZInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CAMERA_PTZ_INFO_S               *pstCameraPTZInfo
);

/**
* 查询摄像机的最后一条错误
* @param [IN]   szDevCode            摄像机编码
* @param [OUT]   pstThirdDevError      第三方设备错误信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_QueryCameraLastError
(
    IN  CHAR                    szDevCode[IMOS_CODE_LEN],
    OUT  THIRD_DEVICE_ERROR_S                 *pstThirdDevError
);

/**
* 分页查询某个组织下的用户列表(V2, 扩展返回"用户所属组织的编码") \n
* 不填查询条件时, 查所有, 并默认排序(用户名称升序)
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szOrgCode           组织域编码
* @param [IN]   bIsQuerySubOrg      是否查询子组织
* @param [IN]   pstQueryCondition   通用查询条件(可填NULL;支持的查询条件包括:#USER_NAME_TYPE[用户名称])
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstUserList         用户信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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

/*Begin: Added by lkf0106, 2012-09-19 for onvif3开关量输出*/

/**
* 查询IPC输出开关量列表
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDevCode               IPC设备编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstSemaOutputList       输出开关量列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_SEMAPHORE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIPCOutSwitchList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_CODE_LEN],
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SEMA_QUERY_ITEM_S           *pstSemaOutputList
);

/*End: Added by lkf0106, 2012-09-19 for onvif3开关量输出*/

/**
* 设置告警联动上墙标注参数 \n
* @param [IN]   pstUserLogIDInfo              用户登陆信息
* @param [IN]   pstLinkWallLabel              告警联动上墙标注信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 只有超级管理员用户才有权限
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CfgLinkWallLabel
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  LINK_WALL_LABEL_INFO_S          *pstLinkWallLabel
);

/**
* 查询设置告警联动上墙标注参数\n
* @param [IN]   pstUserLogIDInfo         用户登陆信息
* @param [OUT]  pstLinkWallLabel         告警联动上墙标注信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 只有超级管理员用户才有权限
* - 2. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLinkWallLabel
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    OUT LINK_WALL_LABEL_INFO_S              *pstLinkWallLabel
);

/*====== BEGIN: Added by shendongchun 00400 for 用户登录功能增强, 2012年11月13日 19:09:23 =====*/
/**
* 用户登录接口V2
* @param [IN]   szUserLoginName         用户登录用户名
* @param [IN]   szPassword              用户登录密码
* @param [IN]   szSrcIpAddress          用户登录IP
* @param [IN]   pstLoginExtInfo         用户登录扩展信息
* @param [OUT]  pstSDKLoginInfo         用户登录信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 用户登录限制配置接口
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szBindUserCode          配置绑定信息用户名(如果用户名为空，则表示配置全局信息)
* @param [IN]   pstUserLoginBindInfo    用户登录限制信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetUserLoginBindInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBindUserCode[IMOS_USER_CODE_LEN],
    IN  USER_LOGIN_BIND_INFO_S      *pstUserLoginBindInfo
);

/**
* 用户登录限制查询接口
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szBindUserCode          查询绑定信息用户名(如果用户名为空，则表示查询全局信息)
* @param [OUT]  pstUserLoginBindInfo    用户登录限制信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserLoginBindInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szBindUserCode[IMOS_USER_CODE_LEN],
    OUT  USER_LOGIN_BIND_INFO_S     *pstUserLoginBindInfo
);
/*====== END  : Added by shendongchun 00400 for 用户登录功能增强, 2012年11月13日 19:09:23 =====*/

/* BEGIN: Added by shendongchun 00400 for 用户统一认证, 2013年3月14日 */
/**
* 用户登录CA接口
* @param [IN]   szUserLoginName         用户登录用户名
* @param [IN]   szUserToken             用户Token
* @param [IN]   szSrcIpAddress          用户登录IP
* @param [IN]   pstLoginExtInfo         用户登录扩展信息
* @param [OUT]  pstSDKLoginInfo         用户登录信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LoginCA
(
    IN  CHAR                        szUserLoginName[IMOS_NAME_LEN],
    IN  CHAR                        szUserToken[IMOS_PASSWD_ENCRYPT_LEN],
    IN  CHAR                        szSrcIpAddress[IMOS_IPADDR_LEN],
    IN  LOGIN_EXT_INFO_S            *pstLoginExtInfo,
    OUT LOGIN_INFO_S                *pstSDKLoginInfo
);
/* END  : Added by shendongchun 00400 for 用户统一认证, 2013年3月14日 */



/**
* 添加XP窗格布局信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstXpLayoutInfo     XP窗格布局信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddXpLayoutInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  XP_LAYOUT_INFO_S            *pstXpLayoutInfo
);

/**
* 删除XP窗格布局信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szXpLayoutCode      XP窗格布局编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelXpLayoutInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szXpLayoutCode[IMOS_CODE_LEN]
);

/**
* 查询XP窗格布局信息列表
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstXpLayoutList     XP窗格布局信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryXpLayoutList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT XP_LAYOUT_INFO_S            *pstXpLayoutList
);

/**
* 添加WebGIS地图比例尺
* @param [IN]       pstUserLogIDInfo        用户登录ID信息标识
* @param [INOUT]    pstWebGisBaseInfo       WebGis地图比例尺信息，比例尺ID由后台返回
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddWebGisScaleInfo
(
    IN     USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    INOUT  WEBGIS_SCALE_INFO_S             *pstWebGisScaleInfo
);

/**
* 修改WebGIS比例尺信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstWebGisBaseInfo       WebGis地图比例尺信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyWebGisScaleInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  WEBGIS_SCALE_INFO_S             *pstWebGisScaleInfo
);

/**
* 查询WebGIS比例尺信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   ulScaleID                  比例尺信息ID
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstWebGisList              WebGis地图信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DOMAIN_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.比例尺信息ID可以为0,表示查所有WebGis比例尺地图信息
* - 2.比例尺信息ID不为0，表示查询指定的WEBGIS的比例尺信息,分页信息为1即可
* - 排序
* - 1.不指定排序条件情况下,默认按比例尺ID升序排序
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

/**查询某个组织下编码器及其下属摄像机信息\n
* 支持模糊查询。pstQueryCondition允许为空，表示该条件无效，否则按缺省进行模糊查询
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szOrgCode                   域编码
* @param [IN]   pstQueryCondition           查询信息条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstEcList                   EC信息数组(包括编码器及下属摄像机信息)
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 配置人机输出端口表信息\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户登录信息
* @param [IN] MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo 人机输出端口信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMMIVoutForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo
);

/**
* 配置人机预览窗格摄像机序列信息\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户登录信息
* @param [IN] MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo 分屏窗格对应的摄像机表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigMMIVoutWinListForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo
);

/**
* 查询人机输出端口表信息\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户登录信息
* @param [IN] ULONG ulMMIVoutID 物理输出端口序号,取值参考#MMI_VEDIO_OUT_ID_E,其中#MMI_VOUT_ID_ALL为查询所有输出端口
* @param [INOUT] ULONG *pulMMIVoutNum 物理输出端口个数
* @param [OUT] MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo 物理输出端口表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMMIVoutConfigForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN ULONG_32 ulMMIVoutID,
    INOUT ULONG_32 *pulMMIVoutNum,
    OUT MMI_VOUT_INFO_FOR_ECR_S *pstMMIVoutInfo
);

/**
* 查询人机预览窗格摄像机列表信息\n
* @param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 　用户登录信息
* @param [INOUT] MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo 人机预览窗格摄像机序列信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMMIVoutWinListForECR
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    INOUT MMI_VOUT_WINLIST_INFO_FOR_ECR_S *pstMMIWinListInfo
);

/**
*@brief 物理输出端口绑定虚拟通道\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户信息
*@param [IN] VIRTUAL_CHANNEL_BIND_INFO_FOR_ECR_S *pstVirtualChannelBindInfo 摄像机及其绑定通道信息
*@return 返回如下结果:
*- 成功:
*- 失败:
*-     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindVirtualChannel
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN VIRTUAL_CHANNEL_BIND_INFO_FOR_ECR_S *pstVirtualChannelBindInfo
);

/**
*@brief 重新绑定虚拟通道\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户信息
*@param [IN] VIRTUAL_CHANNEL_REBIND_INFO_FOR_ECR_S *pstVirtualChannelReBindInfo 重新绑定通道信息
*@return 返回如下结果:
*- 成功:
*- 失败:
*-     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ReBindVirtualChannel
(
    IN USER_LOGIN_ID_INFO_S *pstSDKLoginInfo,
    IN VIRTUAL_CHANNEL_REBIND_INFO_FOR_ECR_S *pstVirtualChannelReBindInfo
);

/**
*@brief 查询虚拟通道绑定信息\n
*@param [IN] USER_LOGIN_INFO_S *pstSDKLoginInfo 用户信息
*@param [INOUT] ULONG *pulVirtualChannelNum 虚拟通道个数
*@param [OUT] VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S *pstVirtualChannelStatus 输出端口虚拟通道绑定信息
*@return 返回如下结果:
*- 成功:
*- 失败:
*-     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVirtualChannelStatus
(
    IN USER_LOGIN_ID_INFO_S     *pstSDKLoginInfo,
    INOUT ULONG_32                 *pulVirtualChannelNum,
    OUT VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S  *pstVirtualChannelStatus
);

/**
*@brief 解绑虚拟通道\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstSDKLoginInfo 用户信息
*@param [IN] ULONG ulVirtualChannelID 虚拟通道序号
*@return 返回如下结果:
*- 成功:
*- 失败:
*-     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnBindVirtualChannel
(
    IN USER_LOGIN_ID_INFO_S  *pstSDKLoginInfo,
    IN ULONG_32                  ulVirtualChannelID
);

/**
* 查询存储设备节点信息
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szCamCode               摄像机编码
* @param [OUT]  szSanResDesc            存储设备节点信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySanResDesc
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCamCode[IMOS_RES_CODE_LEN],
    OUT CHAR                            szSanResDesc[IMOS_DESC_LEN]
);

/**
* 添加第三方IPC
* @param [IN]  pstUserLogIDInfo           用户信息
* @param [IN]  pstThirdpartyIPCInfo       第三方IPC信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  THIRDPARTY_IPC_S        *pstThirdpartyIPCInfo
);

/**
* 修改第三方IPC
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   pstThirdpartyIPCInfo        IPC信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  THIRDPARTY_IPC_S           *pstThirdpartyIPCInfo
);

/**
* 删除第三方IPC
* @param [IN]   pstUserLogIDInfo            用户信息标识
* @param [IN]   szThirdpartyIPCCode         IPC编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szThirdpartyIPCCode[IMOS_CODE_LEN]
);

/**
* 查询某个第三方IPC的具体信息
* @param [IN]   pstUserLogIDInfo            用户信息标志信息
* @param [IN]   szThirdpartyIPCCode         第三方IPC编码
* @param [OUT]  pstThirdpartyIPCInfo        第三方IPC信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdPartyIPC
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szThirdpartyIPCCode[IMOS_CODE_LEN],
    OUT THIRDPARTY_IPC_S           *pstThirdpartyIPCInfo
);

/*Begin: Added by mozhanfei(m01736), 2014-7-17 for camera  add optimize*/
/**
* 查询待管理IPC列表
* @param [IN]   pstUserLoginIDInfo            用户信息标志信息
* @param [IN]   pstQueryWaitManageIPCList            查询条件信息
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstWaitManageIPCInfoList    待管理IPC列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询第三方IPC列表
* @param [IN]   pstUserLogIDInfo            用户信息标志信息
* @param [IN]   szDevCode                   ECR编码
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstThirdpartyIPCInfoList    第三方IPC列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
*@brief查询所有摄像机共享状态\n
*@param [IN] USER_LOGIN_ID_INFO_S *pstUserLogIDInfo   用户信息
*@param [IN] QUERY_PAGE_INFO_S    *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S     *pstRspPageInfo     返回分页信息
*@param [OUT] CAM_SHARE_INFO_S    *pstCamWithInterCode 摄像机共享信息
*@return 返回如下结果:
*- 成功:
*- 失败:
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllCamShareInfoForECR
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT   CAM_SHARE_INFO_S        *pstCamWithInterCode
);

/**
*@brief查询所有开关量互联编码及共享状态
*@param [IN] USER_LOGIN_ID_INFO_S *pstUserLogIDInfo   用户信息
*@param [IN] QUERY_PAGE_INFO_S    *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     返回分页信息
*@param [OUT] SEMA_SHARE_INFO_S   *pstSemaInfo        开关量共享信息
*return  返回如下结果:
*- 成功:
*- 失败:
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAllSemaShareInfoForECR
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    QUERY_PAGE_INFO_S       *pstQueryPageInfo,
    OUT   RSP_PAGE_INFO_S         *pstRspPageInfo,
    OUT   SEMA_SHARE_INFO_S       *pstSemaInfo
);

/**
* 查询所有设备的串口列表for UI 界面调整特性 \n
* 不填查询条件时,查所有,并默认排序(串口索引升序)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo       用户信息标识
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    组织域编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      通用查询条件(可填NULL;可填条件:#INDEX_TYPE[串口索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         返回分页信息
* @param [OUT]  SERIAL_QUERY_ITEM_S         *pstSerialList          串口信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 查询所有设备的输入开关量列表for UI 界面调整特性 \n
* 不填查询条件时,查所有,并默认排序(开关量索引升序)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   用户信息标识
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    组织域编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  通用查询条件(可填NULL;可填条件:#INDEX_TYPE[开关量索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     返回分页信息
* @param [OUT]  SEMAIN_ALLINFO_QUERY_ITEM_S           *pstSemaList        开关量查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 查询所有设备的输出开关量列表for UI 界面调整特性 \n
* 不填查询条件时,查所有,并默认排序(开关量索引升序)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo   用户信息标识
* @param [IN]   CHAR                        szOrgCode[IMOS_CODE_LEN]    组织域编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  通用查询条件(可填NULL;可填条件:#INDEX_TYPE[开关量索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     返回分页信息
* @param [OUT]  SEMAOUT_ALLINFO_QUERY_ITEM_S           *pstSemaList        开关量查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 设置EC输入通道遮挡区域信息
* @param [IN]  pstUserLogIDInfo         用户信息
* @param [IN]  pstChannelIndex          设备通道索引信息
* @param [IN]  ulCoverDetectAreaNum     输入通道遮挡区域的个数
* @param [IN]  pstCoverDetectArea       输入通道遮挡区域信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigECCoverDetectArea
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S          *pstChannelIndex,
    IN  ULONG_32                        ulCoverDetectAreaNum,
    IN  VIDEO_AREA_S                 *pstCoverDetectArea
);

/**
* 查询EC输入通道遮挡区域信息
* @param [IN]    pstUserLogIDInfo         用户信息
* @param [IN]    pstChannelIndex          设备通道索引信息
* @param [INOUT] pulCoverDetectAreaNum    输入通道遮挡区域的个数
* @param [OUT]   pstCoverDetectArea       输入通道遮挡区域信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECCoverDetectArea
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                       *pulCoverDetectAreaNum,
    OUT   VIDEO_AREA_S                *pstCoverDetectArea
);

/* Begin: Added by lkf0106 for ONVIF存储空间弹性扩展 2012-12-12*/
/**
* 查询共享存储资源列表 \n
* 条件为空时,查所有,并默认"名称升序排序"  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[共享资源名称]或者#CODE_TYPE[共享设备编码])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstDmShareResItemList  共享存储资源列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryShareResList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S     *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT DM_SHARE_RES_QUERY_ITEM_S    *pstDmShareResItemList
);
/* End: Added by lkf0106 for ONVIF存储空间弹性扩展 2012-12-12*/

/**
* 查询共享存储设备可存储信息(共享资源总容量，总共可存储天数) \n
* "按照总共可存储天数降序排序"  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szCameraCode           配置摄像机编码
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstDmShareResItemList  共享存储资源列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
设备-TS
***************************************************************************************************************/
/**
* @name TS设备管理
* @{    TS设备管理
*/
/**
* 增加TS服务器 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstSDKTSInfo        TS信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_AS_TS_NUM_EXCEEDED
* - #ERR_MM_PARENT_DEIVCE_NOT_EXIST
* - #ERR_DAO_DEVICE_CODE_EXIST
* -     返回操作结果码，见错误码文件
* @note 1.TS信息中的TS编码是TS的唯一标识
* -     2.TS编码不能填空,且不能包含空格
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  TS_INFO_S                   *pstSDKTSInfo
 );

/**
* 删除TS \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szTSCode            TS编码
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_MP_CODE_NOT_EXIST
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTS
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTSCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 修改TS信息 \n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstSDKTSInfo        TS信息
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note TS信息中的TS编码不能修改, 在修改TS信息的时候需要传入
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  TS_INFO_S                   *pstSDKTSInfo
);

/**
* 查询某个组织下的TS列表  \n
* 目前只支持组织编码szOrgCode允许为空串的查询。
* 条件为空时,查所有TS,并默认"TS名称升序排序"
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szOrgCode           组织编码
* @param [IN]   pstQueryCondition   通用查询条件(可填NULL;支持的查询条件包括:#NAME_TYPE[MS名称] #CODE_TYPE[MS编码] #PHY_DEV_IP[MS IP])
* @param [IN]   pstQueryPageInfo    请求分页信息
* @param [OUT]  pstRspPageInfo      响应分页信息
* @param [OUT]  pstSDKTSList        TS列表
* @return ULONG 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 1、szOrgCode允许为空串，表示查询本系统所有的MS列表。
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
* 查询TS的详细信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szTSCode            TS编码
* @param [OUT]  pstSDKTSInfo        TS信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_DEVICE_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szTSCode[IMOS_DEVICE_CODE_LEN],
    OUT TS_INFO_S               *pstSDKTSInfo
);
/** @} */
/** @} */ /* end of DEVICE MS MANAGEMENT MODULE */

/* Begin added by l01420, 2014-6-30 for 自定义TS转码策略 */
/**
* 增加TS转码规则
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstTSRuleInfo         TS转码规则
* @param [IN]   ulSrcUANum   源UA数目
* @param [IN]  pstSrcUAList    源UA信息列表
* @param [IN]  ulDstUANum   目标UA数目
* @param [IN]  pstDstUAList    目标UA信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 删除某个TS转码规则
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szRuleCode         TS规则编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTSRule
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRuleCode[IMOS_CODE_LEN]
);

/**
* 修改某个TS转码规则
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstTSRuleInfo         TS转码规则
* @param [IN]  ulSrcUANum   源UA数目
* @param [IN]  pstSrcUAList    源UA信息列表
* @param [IN]  ulDstUANum   目标UA数目
* @param [IN]  pstDstUAList    目标UA信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询某个TS转码规则信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szRuleCode         TS规则编码
* @param [OUT] pstTSRuleInfo   TS转码规则信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note pstSrcUAList和pstDstUAList的内存需要由调用者申请
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSRule
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szRuleCode[IMOS_CODE_LEN],
    OUT TS_RULE_INFO_S          *pstTSRuleInfo
);

/**
* 分页查询某个TS规则绑定的UA
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szRuleCode         TS规则编码
* @param [INOUT]  pstSrcPageInfo 源UA分页信息
* @param [INOUT]  pstDstPageInfo 目标UA分页信息
* @param [OUT] pstSrcPageInfoRsp  返回的源UA分页信息
* @param [OUT] pstSrcUAList    源UA列表
* @param [OUT] pstDstPageInfoRsp  返回的目标UA分页信息
* @param [OUT] pstDstUAList    目标UA列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note pstSrcUAList和pstDstUAList的内存需要由调用者申请
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
* 分页查询某个TS服务器上配置的转码规则列表信息\n
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstQueryPageInfo     请求分页信息
* @param [OUT]  pstRspPageInfo       返回分页信息
* @param [OUT] pstTSRuleInfo    TS规则信息，只返回基本信息，不返回UA信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTSRuleList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TS_RULE_QUERY_ITEM_S        *pstTSRuleInfo
);

/* End added by l01420, 2014-6-30 for 自定义TS转码策略 */



/* Begin added by z00758,2012-08-08 of 跨域巡航*/
/**
* 查询摄像机预置位列表V2(可查询下级域预置位列表)
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szCamCode               摄像头编码
* @param [IN]   ulSyncFlag               同步标志
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstQueryResultScope     预置位信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
/* End added by z00758,2012-08-08 of 跨域巡航*/

/**
* 查询VM所属的数据库的配置信息
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [OUT]  pulDBLocalFlag          数据库是否和VM安装在一起(1一起，0分开)
* @param [OUT]  pstDataBaseInfo         VM所属的数据库信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDataBaseInfo
(
 IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
 OUT ULONG_32                           *pulDBLocalFlag,
 OUT DATABASE_INFO_S                 *pstDataBaseInfo
 );


/* BEGIN: Added by kf0092 for 安全接入外域, 2013年3月15日 */
/**
* 配置安全接入摄像机信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCameraCode        摄像机编码
* @param [IN]   pstSafeCameraInfo   安全接入摄像机信息
* @return ULONG 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigSafeCameraInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    IN  SAFE_CAMERA_INFO_S      *pstSafeCameraInfo
);

/**
* 查询安全接入摄像机信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCameraCode        摄像机编码
* @param [OUT]  pstSafeCameraInfo   安全接入摄像机信息
* @return ULONG 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - 返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySafeCameraInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    OUT SAFE_CAMERA_INFO_S      *pstSafeCameraInfo
);
/* END  : Added by kf0092 for 安全接入外域, 2013年3月15日 */



/* BEGIN: Added by kf0092 for 摄像机组手动启停存储, 2013年3月11日 */
/**
* 摄像机组功能操作
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szGroupCode             摄像机组编码
* @param [IN]   ulCameraOperateType     操作类型，取值为#CAMERA_GROUP_OPERATE_TYPE_E
* @param [IN]   szReserve               保留字段
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CameraGroupOperate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szGroupCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulCameraOperateType,
    IN  CHAR                    szReserve[512]
);
/* END  : Added by kf0092 for 摄像机组手动启停存储, 2013年3月11日 */

/* Begin:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of 第三方IPC优化 */
/**
* 查询EC视频输入通道流及扩展信息
* @param [IN]       USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo      用户信息
* @param [IN]       DEV_CHANNEL_INDEX_S    *pstChannelIndex       设备通道索引信息
* @param [INOUT]    ULONG                  *pulStreamNum          输入通道视频流的数量
* @param [OUT]      VIDEO_STREAM_EXTEND_FORECR_S  *pstVideoInChannelInfo 视频流及扩展信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT  ULONG_32 STDCALL IMOS_QueryThirdIPCVideoStreamForECR
(
    IN    USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN    DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    INOUT ULONG_32                      *pulStreamNum,
    OUT   VIDEO_STREAM_EXTEND_FORECR_S *pstVideoStreamInfo
);

/**
* 设置EC视频输入通道流信息
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo            用户信息
* @param [IN]   DEV_CHANNEL_INDEX_S       *pstChannelIndex             设备通道索引信息
* @param [IN]   VIDEO_STREAM_EXTEND_FORECR_S *pstVideoStreamInfo          视频输入通道流信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigThirdIPCVideoStreamForECR
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S           *pstChannelIndex,
    IN  VIDEO_STREAM_EXTEND_FORECR_S  *pstVideoStreamInfo
);
/* End:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of 第三方IPC优化 */

/* Begin: added by tangxiaobin00764, 2013.1.18 for IVSD00576 of 第三方IPC优化 */
/**
* 查询某个组织下的IPC列表  \n
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo        用户信息标识
* @param [IN]   CHAR                      szOrgCode                域编码
* @param [IN]   COMMON_QUERY_CONDITION_S  *pstQueryCondition       查询信息条件(可为NULL;支持的查询条件包括:#DEVICE_CODE_FOR_ECR[IPC设备编码];
*                                                     #CAMERA_TYPE_FOR_ECR[摄像机类型]
*                                                     #NAME_TYPE[摄像机名称]
*                                                     #CODE_TYPE[摄像机编码])
* @param [IN]   QUERY_PAGE_INFO_S         *pstQueryPageInfo        请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S           *pstRspPageInfo          返回分页信息
* @param [OUT]  IPC_CAM_INFO_FORECR_S     *pstIPCInfoList          IPC数组信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
/* End: added by tangxiaobin00764, 2013.1.15 for IVSD00576 of 第三方IPC优化 */


/* Begin:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of 第三方IPC优化--一键删除 */
/**
* 删除IPC (支持一键删除IPC)
* @param [IN] pstUserLogIDInfo           用户信息标识
* @param [IN] szEcCode                      EC的编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelIPCForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szEcCode[IMOS_DEVICE_CODE_LEN]
);
/* End:Added by h00275, 2013.1.9 for IVSD00576 for IVSD00576 of 第三方IPC优化--一键删除 */

/**
* 统一录像检索 \n
* @param [IN]   pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   pstRecQueryInfo             回放检索消息数据结构
* @param [IN]   ulRowNum                    请求的记录数
* @param [OUT]  pstRecRspRowInfo            返回记录信息
* @param [OUT]  pstUnitedRecFileInfoList    录像文件信息数据结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1、查询时间跨度不能大于24小时，且在录像检索流程中时间格式为："%Y-%m-%d %H:%M:%S"格式 ，信息长度限定为24字符.
*       2、文件名字符串数组最大长度为IMOS_FILE_NAME_LEN_V2
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
* 获取录像文件的URL信息 \n
* @param[IN]    pstUserLogIDInfo            用户登录ID信息标识
* @param[IN]    pstUnitedGetUrlInfo         获取云录像URL的请求结构
* @param[OUT]   pstSDKURLInfo               URL信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnitedGetRecordFileURL
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  UNITED_GET_URL_INFO_S       *pstUnitedGetUrlInfo,
    OUT URL_INFO_S                  *pstSDKURLInfo
);

/**
* 查询服务器的云录像检索配置策略的SDK接口 \n
* @param [IN]   *pstUserLogIDInfo       用户信息
* @param [OUT]  *pstUnitedRecDomainCfg  云录像检索配置信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUnitedRecRetrievalPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    OUT  UNITED_REC_DOMAIN_CFG_S    *pstUnitedRecDomainCfg
);

/**
* 设置服务器的云录像检索配置策略 \n
* @param [IN]   *pstUserLogIDInfo       用户信息
* @param [IN]   *pstUnitedRecDomainCfg  云录像检索配置信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetUnitedRecRetrievalPolicy
(
    IN   USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN   UNITED_REC_DOMAIN_CFG_S    *pstUnitedRecDomainCfg
);

/* Begin added by wuweiping/01403 2013.01.06 for IVSD06510 NVR与DDNS信息交互*/
/**
* 获取DDNS配置的基本信息. \n
* @param [IN] USER_LOGIN_ID_INFO_S * pstUserLogIDInfo  用户信息
* @param [OUT] DDNS_INFO_FOR_ECR_S * pstDDNSInfo DDNS配置信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDDNSInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    OUT DDNS_INFO_FOR_ECR_S   *pstDDNSBaseInfo
);

/**
* 修改DDNS配置 \n
* @param [IN]   USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   DDNS_INFO_FOR_ECR_S   *pstDDNSBaseInfo    DDNS信息结构体
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
* @note 仅允许修改DDNS的开启或关闭状态
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDDNSInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN DDNS_INFO_FOR_ECR_S   *pstDDNSBaseInfo
);
/* End added by wuweiping/01403 2013.01.06 for IVSD06510 NVR与DDNS信息交互*/

/* Begin Added by zhudingjingKF0104, 2013-06-18 of 语音对讲资源化 */
/**
* 开始语音广播组广播，允许有失败的情况，但是如果都失败，则返回失败 \n
* @param [IN]       pstUserLoginIDInfo      用户登录ID信息
* @param [IN]       szXPVocBrdCode          语音广播编码
* @param [IN]       szGroupCode             广播组编码
* @param [IN]       ulOperateCode           操作原因码
* @param [OUT]      pulUnitNum               广播组单元数量
* @param [OUT]      pstVocBrdUnit           语音广播单元列表，作为出参时，填写状态
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1.可以支持同时最多和#MAX_VOCBRD_CAM_NUM个广播单元进行语音广播，但是这些广播单元必须属于本域
* - 2.ulOperateCode取值参见CS_OPERATE_CODE_E
* - 3.szXPVocBrdCode暂不使用, 可以为空串, 但不能为空指针
* - 4. 该接口仅支持ECR设备
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
* 停止语音广播组 \n
* @param [IN]       pstUserLoginIDInfo      用户登录ID信息
* @param [IN]       szXPVocBrdCode          语音广播编码
* @param [IN]       szGroupCode             广播组编码
* @param [IN]       ulOperateCode           操作原因码
* @param [OUT]      pulUnitNum              广播组单元数量
* @param [OUT]      pstVoiceBrdUnit         语音广播单元列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1.ulOperateCode取值参见CS_OPERATE_CODE_E
* - 2.szXPVocBrdCode暂不使用, 可以为空串, 但不能为空指针
* - 3. 该接口仅支持ECR设备
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
* 查询某个广播组语音广播信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szXPVocBrdCode          语音广播编码
* @param [IN]   szGroupCode             广播组编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstVocBrdUnit           语音广播单元列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. szXPVocBrdCode暂不使用, 可以为空串, 但不能为空指针
* - 2. 该接口仅支持ECR设备
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
* @brief配置独立音频输入 \n
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo 用户信息
* @param [IN] DEV_CHANNEL_INDEX_S   *pstChannelIndex 通道索引信息
* @param [IN] AUDIO_INPUT_INFO_S    *pstAudioInInfo   独立音频输入信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigEcAudioInForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    IN  AUDIO_INPUT_INFO_S          *pstAudioInInfo
);

/**
*@brief查询独立音频输入列表 \n
*@param [IN] USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo 用户信息
*@param [IN] COMMON_QUERY_CONDITION_S  *pstQueryCondition   查询信息条件
*- 可以为空
*@param [IN] QUERY_PAGE_INFO_S         *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo     返回分页信息
*@param[OUT] AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S  *pstAudioInAndChannelList 独立音频输入及通道查询列表
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
*@note:
* - 1. 此接口暂无用, 保留
* - 2. 该接口仅支持ECR设备
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
*@brief查询独立音频输入详细信息 \n
*@param [IN] USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo 用户信息
*@param [IN] DEV_CHANNEL_INDEX_S    *pstChannelIndex  通道索引信息
*@param [OUT] AUDIO_INPUT_INFO_S    *pstAudioInInfo   独立音频输入信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioInputInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT AUDIO_INPUT_INFO_S          *pstAudioInInfo
);

/**
*@brief配置独立音频输出 \n
*@param [IN] USER_LOGIN_ID_INFO_S   *pstUserLogIDInfo 用户信息
*@param [IN] DEV_CHANNEL_INDEX_S    *pstChannelIndex  通道索引信息
*@param [IN] AUDIO_OUTPUT_INFO_S    *pstAudioInInfo   独立音频输出信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigEcAudioOutForECR
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S        *pstChannelIndex,
    IN  AUDIO_OUTPUT_INFO_S        *pstAudioOutInfo
);

/**
*@brief查询独立音频输出列表 \n
*@param [IN] USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo 用户信息
*@param [IN] COMMON_QUERY_CONDITION_S  *pstQueryCondition   查询信息条件
*- 可以为空
*@param [IN] QUERY_PAGE_INFO_S         *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S          *pstRspPageInfo     返回分页信息
*@param[OUT] AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S  *pstAudioInAndChannelList 独立音频输出及通道查询列表
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
*@note:
* - 1. 此接口暂无用, 保留
* - 2. 该接口仅支持ECR设备
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
*@brief查询独立音频输出详细信息 \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo 用户信息
*@param [IN] DEV_CHANNEL_INDEX_S   *pstChannelIndex  通道索引信息
*@param [OUT] AUDIO_OUTPUT_INFO_S  *pstAudioOutInfo  独立音频输出信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioOutputInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  DEV_CHANNEL_INDEX_S         *pstChannelIndex,
    OUT AUDIO_OUTPUT_INFO_S         *pstAudioOutInfo
);

/**
*@brief查询语音资源列表 \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo   用户信息
*@param [IN] QUERY_PAGE_INFO_S     *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     返回分页信息
*@param [OUT] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList 语音资源列表
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioResListForECR
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S         *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S           *pstRspPageInfo,
    OUT AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList
);

/**
*@brief查询语音资源详细信息 \n
*@param [IN] USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
*@param [IN] CHAR                       *pcAudioResCode   语音资源编码
*@param [OUT] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfo  语音资源信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN  CHAR                      szAudioResCode[IMOS_RES_CODE_LEN],
    OUT AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfo
);

/**
*@brief配置语音资源详细信息 \n
*@param [IN] USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
*@param [IN] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfo  语音资源信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  AUDIO_RES_INFO_FOR_ECR_S   *pstAudioResInfo
);

/**
*@brief查询摄像机可绑定的语音资源列表 \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo   用户信息
*@param [IN] CHAR  szCamCode[IMOS_CODE_LEN] 摄像机编码
*@param [IN] QUERY_PAGE_INFO_S     *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     返回分页信息
*@param [OUT] AUDIO_RES_INFO_FOR_ECR_S  *pstAudioResInfoList 语音资源列表
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
*@brief 修改摄像机绑定语音资源信息 \n
*@param [IN] USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo 用户信息
*@param [OUT]CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResInfo 摄像机绑定语音资源信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
*@note:
* - 1. 此接口暂无用, 保留
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyCamBindAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLogIDInfo,
    IN  CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S      *pstCamBindAudioResInfo
);

/**
*@brief查询摄像机绑定语音资源信息列表\n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo   用户信息
*@param [IN] QUERY_PAGE_INFO_S     *pstQueryPageInfo   请求分页信息
*@param [OUT] RSP_PAGE_INFO_S      *pstRspPageInfo     返回分页信息
*@param [OUT] CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResList 摄像机绑定语音资源信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamBindAudioResListForECR
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  QUERY_PAGE_INFO_S     *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S       *pstRspPageInfo,
    OUT CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResList
);

/**
*@brief 查询摄像机绑定语音资源信息 \n
*@param [IN] USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo 用户信息
*@param [IN] CHAR                  szResCode[IMOS_RES_CODE_LEN] 摄像机编码/语音资源编码
*@param [OUT] CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResInfo 摄像机绑定语音资源信息
*@return 返回如下结果：
*- 成功：
*- 失败：
*-      返回操作结果码，见错误码文件
*@note
* - 1. 如果szResCode可以为摄像机编码或者语音资源编码
* - 2. 该接口仅支持ECR设备
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamBindAudioResInfoForECR
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLogIDInfo,
    IN  CHAR                  szResCode[IMOS_RES_CODE_LEN],
    OUT CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S  *pstCamBindAudioResInfo
);
/* End Added by zhudingjingKF0104, 2013-06-18 of 语音对讲资源化 */

/** Begin:add by sunxiaojisKF0138, 2013-7-18 of NVRV3R1 **/
/**
* 从第三方接受消息发送给IO处理器 \n
* @param [IN]USER_LOGIN_ID_INFO_S        *pstUserInfo   用户登录信息
* @param [IN]SERIAL_OF_IO_INFO_FOR_ECR_S *pstSerialInfo 串口信息
* @param [IN]ULONG                       ulIOInfoLen    消息内容长度
* @param [IN]CHAR                        *pcIOInfo      要传送的消息内容信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持ECR设备
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
* 增加MAPM \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstMAPMInfo             MAPM信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAPM_INFO_S                     *pstMAPMInfo
);

/**
* 删除MAPM \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szMAPMCode              MAPM编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMAPMCode[IMOS_CODE_LEN]
);

/**
* 修改MAPM \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstMAPMInfo               MAPM信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  MAPM_INFO_S                     *pstMAPMInfo
);

/**
* 查询MAPM \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szMAPMCode              MAPM编码
* @param [OUT]  pstMAPMInfo             MAPM信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMAPM
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMAPMCode[IMOS_CODE_LEN],
    OUT MAPM_INFO_S                     *pstMAPMInfo
);

/**
* 查询MAPM列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件(支持的查询条件可以为#NAME_TYPE[设备名称])
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstMAPMList             MAPM列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 同步GIS地图上资源点位信息到配置
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstDevGisInfo       设备的点位信息
* @param [IN]   pstGisDbInfo        GIS数据库的信息(此参数暂时未使用，保留)
* @param [IN]
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SyncGisResToConfig
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DEV_WEBGIS_INFO_S               *pstDevGisInfo,
    IN  DATABASE_INFO_S                 *pstGisDbInfo
);

/**
* 查询BM备份资源列表V2 \n
* 目前只支持组织编码szOrgCode允许为空串的查询 \n
* 条件为空时,查所有,并默认"名称升序排序"  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szBMCode               BM编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[BM资源名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstSDKBMResList        BM备份资源列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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


/* Begin Add by zhengyibing(01306), 2014-05-30 for 新国标修改二期 */
/**
* @brief 查询摄像机的配置信息\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
* @param [IN]   CHAR                        szCameraCode   摄像机编码
* @param [IN]   ULONG_32                    ulCameraConfigQueryType  摄像机配置查询方式 详间枚举 CAMERA_CONFIG_INF0_REQ_TYPE_E
* @param [OUT]  CAMERA_CONFIG_INFO_RES_S   *pstConfigInfo 摄像机的配置查询结果
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraConfiureInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulCameraConfigQueryType,
    OUT CAMERA_CONFIG_INFO_RES_S        *pstConfigInfo
);

/*  Begin add by liujian/02319, 2016-07-06 for 2016 国标设备配置 */
/**
* @brief 查询摄像机的配置信息\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
* @param [IN]   CHAR                        szCameraCode   摄像机编码
* @param [IN]   ULONG_32                    ulCameraConfigQueryType  摄像机配置查询方式 详间枚举 CAMERA_CONFIG_INF0_REQ_TYPE_E
* @param [OUT]  CAMERA_CONFIG_INFO_RES_EXT_S   *pstConfigInfo 摄像机的配置查询结果
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCameraConfiureInfoExt
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulCameraConfigQueryType,
    OUT CAMERA_CONFIG_INFO_RES_EXT_S        *pstConfigInfo
);
/*  End add by liujian/02319, 2016-07-06 for 2016 国标设备配置 */

/**
* @brief 设置摄像机的配置信息\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
* @param [IN]  CHAR                       szCameraCode   摄像机编码
* @param [IN]  CAMERA_CONFIG_INFO_S       *pstConfigInfo  摄像机的配置信息
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCameraConfiureInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN CAMERA_CONFIG_INFO_SET_S          *pstConfigInfo
);

/* Begin add by liujian/02319, 2016-07-06 for 2016 国标设备配置 */
/**
* @brief 设置摄像机的配置信息\n
* @param [IN]  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo 用户信息
* @param [IN]  CHAR                       szCameraCode   摄像机编码
* @param [IN]  CAMERA_CONFIG_INFO_SET_EXT_S       *pstConfigInfo  摄像机的配置信息
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCameraConfiureInfoExt
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_RES_CODE_LEN],
    IN CAMERA_CONFIG_INFO_SET_EXT_S          *pstConfigInfo
);
/* End add by liujian/02319, 2016-07-06 for 2016 国标设备配置 */

/* End Add by zhengyibing(01306), 2014-05-30 for 新国标修改二期 */

/* Begin Add By hexiaojun/hW0959 for 国标支持双码流 2014-8-21*/
/**
* @brief 查询国标摄像机的流配置信息\n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo 用户信息
* @param [IN]   CHAR                        szCameraCode   摄像机编码
* @param [IN]   ULONG_32                    ulCameraConfigQueryType  摄像机配置查询方式 详间枚举 CAMERA_CONFIG_INFO_REQ_TYPE_E
* @param [OUT]  GB_PROFILES_S               *pstGbProfileConfigInfo 摄像机的配置查询结果
* @return 返回如下结果:
* - 成功:
* - 失败:
* -     返回操作结果码:见结果码文件sdk_err.h
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGbCameraStreamInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    IN  ULONG_32                        ulCameraConfigQueryType,
    OUT GB_PROFILES_S                   *pstGbProfileConfigInfo
);
/* End Add By hexiaojun/hW0959 for 国标支持双码流 2014-8-21 */

/* Begin add by zhengyibing/01306 2015/01/05 for onvif批量主辅流配置 */
/**
* 获取onvif摄像机流配置策略. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       用户信息
* @param [OUT]  ULONG_32                 ulOnvifStreamStrategy   onvif摄像机主辅流配置策略 0:自适应 1:第一股流
@return 返回如下结果：
* - 成功：
* - 失败：
* - #ERR_AS_GET_TIME_FAIL
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetOnvifStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    OUT  ULONG_32                    *pulOnvifStreamStrategy
);


/**
* 更改onvif摄像机流配置策略. \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       用户信息
* @param [OUT]  ULONG_32                 ulOnvifStreamStrategy   onvif摄像机主辅流配置策略 0:自适应 1:第一股流
@return 返回如下结果：
* - 成功：
* - 失败：
* - #ERR_AS_GET_TIME_FAIL
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifStreamPolicy
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                    ulOnvifStreamStrategy
);
/* End add by zhengyibing/01306 2015/01/05 for onvif批量主辅流配置 */

/**
* 查询BM备份资源列表V3 \n
* 目前只支持组织编码szOrgCode允许为空串的查询 \n
* 条件为空时,查所有,并默认"名称升序排序"  \n
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szBMCode               BM编码
* @param [IN]   pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[BM资源名称])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstSDKBMResList        BM备份资源列表
* @return ULONG 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询域间协议信息\n
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   pstQueryCondition  通用查询条件(可填NULL)
* @param [IN]   pstQueryPageInfo   请求分页信息
* @param [OUT]  pstRspPageInfo     返回分页信息
* @param [OUT]  pDomainProtocolInfoList   返回域间协议信息链表
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
* @note
* - 可填通用查询条件:
*     IS_DEFAULT_SG[是否默认SG]
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
* 删除域间协议信息\n
* @param [IN]   pstUserLogIDInfo   用户信息
* @param [IN]   ulProtocolType      协议类型
* @return ULONG 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDomainProtocol
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  ULONG_32                                     ulProtocolType
);

/*Begin added by liangchao, 2015-11-25 for BM2516合主线*/
/**
* 添加手动备份任务摄像机组\n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [OUT]  MANUL_BAKTASK_GROUP_S *pstManulBakTaskInfo      手动备份任务组信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
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
* 删除手动备份任务\n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [OUT]  CHAR *szManulBakTaskGroupCode      任务组编码
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelManualBakTaskGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szManulBakTaskGroupCode[IMOS_CODE_LEN]
);

/**
* 查询备份任务列表 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  MANUL_BAKTASK_ORG_S *pstManulBakTaskOrgInfo      备份任务信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryManualBakTaskGroupList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT MANUL_BAKTASK_ORG_S       *pstManulBakTaskOrgInfo
);


/**
* 查询某个备份任务中摄像机列表 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [IN]   CHAR    szManulBakTaskGroupCode   备份任务编码
* @param [IN]   CHAR    szCamName       摄像机名称(支持模糊查询)
* @param [IN]   CHAR    szCamName       摄像机编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  MANUL_BAKTASK_ORG_S *pstManulBakTaskOrgInfo      备份任务信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
* @note 摄像机编码不为空时，只查这个摄像机
* @note 摄像机编码为空时，只查云检索部分，多个摄像机
* @note 摄像机名称不为空时，按照摄像机名称模糊查询
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
* 添加BM服务器，包含编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       用户登录ID信息标识
* @param [IN]   BYWEEK_BM_INFO_S               *pstBMInfo                  BM信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddBMV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BYWEEK_BM_INFO_S                   *pstBMInfo
);

/**
* 修改BM服务器，包含编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo           用户登录ID信息标识
* @param [IN]   ALL_BM_INFO_S               *pstBMInfo                  BM信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 只允许修改:BM设备名称，满策略，备份开始时间，备份结束时间。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyBMV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  BYWEEK_BM_INFO_S                   *pstBMInfo
);
/**
* 查询单个的BM服务器 \n
* szOrgCode值无效，填任何值，都只查询本域BM列表
* 条件为空时,查所有,并默认"名称升序排序"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo     用户登录ID信息标识
* @param [IN]  CHAR  szBMCode[IMOS_DEVICE_CODE_LEN]               BM编码
* @param [OUT]  OUT BYWEEK_BM_INFO_S             *pstSDKBMInfo          BM信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryBMV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR  szBMCode[IMOS_DEVICE_CODE_LEN],
    OUT BYWEEK_BM_INFO_S             *pstSDKBMInfo
);
/**
* 从指定备份任务中删除指定摄像机 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [IN]   CHAR    szManulBakTaskGroupCode   备份任务编码
* @param [IN]   CHAR     szCamCode   摄像机编码
* @param [IN]   CHAR     szTaskCode   任务编码
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelCamFromManualBakTaskGroup
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szManulBakTaskGroupCode[IMOS_CODE_LEN],
    IN  CHAR                        szCamCode[IMOS_CODE_LEN],
    IN  CHAR                    szTaskCode[IMOS_CODE_LEN]
);
/*End added by liangchao, 2015-11-25 for BM2516合主线*/

/**
* 分页查询EC设备下的摄像机以及通道列表 \n
* 条件为空时,查所有,并按照默认条件(视频输入通道索引升序)排序
* @param [IN]   pstUserLogIDInfo       用户登录ID信息标识
* @param [IN]   szDevCode              编码器编码
* @param [IN]   pstQueryCondition      通用查询条件(可为#NULL;支持的查询条件包括:#INDEX_TYPE[通道索引])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstCamAndChannelList   摄像机以及通道信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_VIN_CHANNEL_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询EC输入通道信息
* @param [IN]   pstUserLoginIDInfo            用户信息
* @param [IN]   pstChannelIndex             设备通道索引信息
* @param [OUT]  pstVideoInChannelInfo       输入通道信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryECVideoInChannelV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    OUT VIN_CHANNEL_V3_S                   *pstVideoInChannelInfo
);


/**
* 设置EC输入通道通道扩展信息
* @param [IN] USER_LOGIN_ID_INFO_S  pstUserLogIDInfo            用户信息
* @param [IN] DEV_CHANNEL_INDEX_S   pstChannelIndex             设备通道索引信息
* @param [IN] VIN_CHANNEL_EXTEND_S  pstVideoInChannelInfo       输入通道扩展信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigVideoInChannelV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  DEV_CHANNEL_INDEX_S             *pstChannelIndex,
    IN  VIN_CHANNEL_V3_S            *pstVideoInChannelInfo
);

/**
* 将摄像机绑定到EC 的某个通道上，需要带齐所有信息，支持场名OSD，遮盖区域，视频流，遮挡检测区域，运动检测区域五种元素变长
* @param [IN]  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo             用户信息
* @param [IN]  VINCHNL_BIND_CAMERA_BASE_V2_S       *pstVINBindCamBaseInfo        摄像机及其绑定通道的基本信息
* @param [IN]  VINCHNL_FULL_VARIETY_ELEMENT_S   *pstVINFullVarietyElement     视频通道全部变长元素结构体
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* 1.摄像机编码不能为空,且不能包含空格
* 2.变长元素个数和变长元素内存长度由调用者保证，变长元素个数不可大于变长元素实际内存长度
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindCameraToVideoInChannelV4
(
    IN  USER_LOGIN_ID_INFO_S                    *pstUserLoginIDInfo,
    IN  VINCHNL_BIND_CAMERA_BASE_V3_S              *pstVINBindCamBaseInfo,
    IN  VINCHNL_FULL_VARIETY_ELEMENT_S          *pstVINFullVarietyElement
);


/**查询某个设备上存在的业务信息
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   szResCode                   资源编码
* @param [IN]   ulResType                   资源类型  IMOS_TYPE_E
* @param [IN]   ulextraParam                当资源类型为1001，表示是否属于外域
                                            当资源类型为2时，表示是否是 NVR/ECR
* @param [OUT]  SERVICE_INFO_ON_RES_S       stServiceInfo     设备业务信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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

/**查询组织中所被共享的组织信息
* 查询组织下面的子组织节点共享信息列表，只获取一层 \n
* 不填查询条件时,查所有,并默认排序(组织名称升序)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo   	用户信息
* @param [IN]   CHAR                        szOrgCode           	组织节点编码
* @param [IN]   CHAR                        szExDomainCode     		外域编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  	通用查询条件(可填NULL;可填条件:NAME_TYPE[组织名称],IS_QUERY_SUB[是否查子组织,=1是,=0否])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   	请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     	返回分页信息
* @param [OUT]  SHARE_ORG_INFO_S          *pstOrgShareList    	返回组织基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 查询设备的开关量列表V3(增加告警源或者告警输出是否使能) \n
* 不填查询条件时,查所有,并默认排序(开关量索引升序)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo   用户信息标识
* @param [IN]   CHAR                        szDevCode           设备编码
* @param [IN]   ULONG_32                       ulDevType           设备类型
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition  通用查询条件(可填NULL;可填条件:#INDEX_TYPE[开关量索引])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo   请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo     返回分页信息
* @param [OUT]  SEMA_QUERY_ITEM_S           *pstSemaList        开关量查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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

/** 增加看守位轮切计划
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   pstGuardPositionInfo      看守计划信息
* @param [OUT]  szGuardPositionPlanCode   看守计划编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  GUARD_POSITION_PLAN_INFO_S      *pstGuardPositionInfo,
    OUT CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN]
);

/**
* 修改看守位轮切计划
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   szGuardPositionPlanCode   看守计划编码
* @param [IN]   pstGuardPositionInfo      看守计划信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN],
    IN  GUARD_POSITION_PLAN_INFO_S      *pstGuardPositionPlanInfo
);

/**
* 启动/停止看守位轮切计划 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szGuardPositionPlanCode 看守位轮切计划编码
* @param [IN]   ulOperateCode           操作模式
* @param [IN]   ulPlanMode              计划处理标记，0停止，1启动
@return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note ulPlanMode取值参见#PLAN_OPER_MODE_E
*       ulOperateCode取值参见#CS_OPERATE_CODE_E
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                        ulOperateCode,
    IN  ULONG_32                        ulPlanMode
);

/**
* 查询看守位轮切计划
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   szSwitchPlanCode          看守计划编码
* @param [OUT]  pstGuardPositionPlanInfo  看守计划信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryGuardPositionPlan
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szGuardPositionPlanCode[IMOS_RES_CODE_LEN],
    OUT GUARD_POSITION_PLAN_INFO_S      *pstGuardPositionPlanInfo
);

/**
* 查询看守位计划列表 \n
* 条件为空时,查所有,并默认"名称升序排序"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       用户信息
* @param [IN]   CHAR                        szOrgCode               组织编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      通用查询条件
* - 可填NULL
* - 可填条件:NAME_TYPE(计划名称),TIME_TYPE(创建时间),CODE_TYPE(摄像机编码)
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         返回分页信息
* @param [OUT]  GUARD_POSITION_PLAN_QUERY_ITEM_S      *pstGuardPositionPlanList      看守计划列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 分页查询组织下的告警源的告警联动动作列表  \n
* @param [IN]   pstUserLogIDInfo       用户信息标识
* @param [IN]   szOrgCode              组织编码
* @param [IN]   pstQueryCondition      通用查询条件(可为NULL;支持的查询条件包括:#NAME_TYPE[告警源名称]、#EVENT_TYPE[事件类型]、#ACTION_TYPE[动作类型])
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pstAlarmLinkageList    告警联动信息列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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
* 分页查询告警源的告警联动事件列表  \n
* @param [IN]   pstUserLogIDInfo       用户信息标识
* @param [IN]   szAlarmSrcCode         告警源编码
* @param [IN]   pstQueryCondition      通用查询条件(预留,目前只能为NULL)
* @param [IN]   pstQueryPageInfo       请求分页信息
* @param [OUT]  pstRspPageInfo         响应分页信息
* @param [OUT]  pulDevType             设备类型（具体枚举取值参见#IMOS_TYPE_E）
* @param [OUT]  pulDevSubType          设备子类型（具体枚举取值参见#IMOS_DEVICE_TYPE_E）
* @param [OUT]  pulParentDevType       父设备类型（具体枚举取值参见#IMOS_TYPE_E）
* @param [OUT]  pulParentSubDevType    父设备子类型（具体枚举取值参见#IMOS_DEVICE_TYPE_E）
* @param [OUT]  pstAlarmLinkEventList  告警联动事件列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* -     返回操作结果码，见错误码文件
* @note 无
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

/* begin: added by yW1054 in 2014-8-21 for 日志审计服务器 */
/**
* 添加LS服务器，包含编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       用户信息
* @param [IN]   LS_INFO_S               *pstSDKLSInfo           LS信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.LS信息中的LS编码是LS服务器的唯一标识
* -     2.LS编码不能填空,且不能包含空格
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddLS
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN LS_INFO_S                    *pstSDKLSInfo
);

/**
* 查询某个LS的具体信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo                   用户信息
*@param[IN]CHAR  szLSCode[IMOS_DEVICE_CODE_LEN]      LS编码
* @param [OUT]  LS_INFO_S               *pstSDKLSInfo                       LS信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryLSInfo
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR      szLSCode[IMOS_DEVICE_CODE_LEN],
    OUT  LS_INFO_S                   *pstSDKLSInfo
);


/**
* 修改LS服务器，编码不可修改，但是需要带入 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo       用户信息
* @param [IN]   LS_INFO_S               *pstSDKLSInfo      LS信息
* @return ULONG_32 返回如下结果：
* - 成功RR_COMMON_SUCCEED?
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyLS
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  LS_INFO_S                   *pstSDKLSInfo
);

/**
* 删除LS服务器 \n
*@param[IN]USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo    用户信息
*@param[IN]CHAR   szLSCode[IMOS_DEVICE_CODE_LEN]      LS编码
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 只能一个个删除LS，不能删除LS列表
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelLS
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN CHAR       szLSCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 查询某个组织下的LS列表  \n
* 目前只支持组织编码szOrgCode允许为空串的查询。
* 条件为空时,查所有,并默认"名称升序排序"
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo       用户信息
* @param [IN]   CHAR             szOrgCode               组织编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition      通用查询条件(可填NULL;可填条件:#NAME_TYPE[LS名称])
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo       请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo         返回分页信息
* @param [OUT]  LS_QUERY_ITEM_S             *pstSDKLSList           LS列表
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note  1、szOrgCode允许为空串，表示查询本系统所有的LS列表
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


/* end: added by yW1054 in 2014-8-21 for 日志审计服务器*/

/* Begin: Added by zhongke z01354, 2014-10-28 for uniview_keyboard */
/**
* 添加键盘。
* @param [IN]   pstUserLoginIDInfo    用户信息标识
* @param [IN]   pstKeyboardInfo       键盘信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
ULONG_32 STDCALL IMOS_AddKeyboard
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN    KEYBOARD_INFO_S               *pstKeyboardInfo
);

/**
* 修改键盘,其中设备编码不可能修改，但是需要带入。
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   pstKeyboardInfo               键盘信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_ModifyKeyboard
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  KEYBOARD_INFO_S                 *pstKeyboardInfo
);

/**
* 删除键盘
* @param [IN] pstUserLoginIDInfo              用户信息标识
* @param [IN] szKeyboardIP                    键盘IP
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_DelKeyboard
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szKeyboardIP[IMOS_IPADDR_LEN]
);

/**
* 查询某个键盘的信息
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   szKeyboardIP                  键盘IP
* @param [OUT]  pstKeyboardInfo               键盘信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_QueryKeyboardInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szKeyboardIP[IMOS_IPADDR_LEN],
    OUT KEYBOARD_INFO_S                 *pstKeyboardInfo
);

/**
* 查询键盘列表 \n
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstKeyboardList             键盘信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 设置键盘的全局摄像机关联列表
* @param [IN]  pstUserLoginIDInfo       用户信息
* @param [IN]  ulRelationListNum        关联列表个数
* @param [IN]  pstKeyboardCamera        摄像机关联列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_ConfigKeyboardCamera
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulRelationListNum,
    IN  KEYBOARD_CAMERA_S            *pstKeyboardCamera
);

/**
* 设置键盘的全局监视器关联列表
* @param [IN]  pstUserLoginIDInfo       用户信息
* @param [IN]  ulRelationListNum        关联列表个数
* @param [IN]  pstKeyboardMonitor       监视器关联列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_ConfigKeyboardMonitor
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulRelationListNum,
    IN  KEYBOARD_MONITOR_S           *pstKeyboardMonitor
);

/**
* 删除键盘某个摄像机关联信息
* @param [IN] pstUserLoginIDInfo              用户信息标识
* @param [IN] ulKeyboardControlNumber         键盘控制编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_DelKeyboardCamera
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulKeyboardControlNumber
);

/**
* 删除键盘某个监视器关联信息
* @param [IN] pstUserLoginIDInfo              用户信息标识
* @param [IN] ulKeyboardControlNumber         键盘控制编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_DelKeyboardMonitor
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                     ulKeyboardControlNumber
);

/**
* 查询键盘摄像机列表  \n
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstKeyboardCameraList       键盘摄像机信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 查询键盘监视器列表  \n
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstKeyboardMonitorList      键盘监视器信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 设置键盘的全局轮切资源关联列表
* @param [IN]  pstUserLoginIDInfo       用户信息
* @param [IN]  ulRelationListNum        关联列表个数
* @param [IN]  pstKeyboardMonitor       轮切资源关联列表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_ConfigKeyboardSwitchRes
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  ULONG_32                      ulRelationListNum,
    IN  KEYBOARD_SWITCHRES_S         *pstKeyboardSwitchRes
);

/**
* 查询键盘轮切资源列表  \n
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstKeyboardSwitchResList       键盘轮切资源信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 删除键盘某个监视器关联信息
* @param [IN] pstUserLoginIDInfo              用户信息标识
* @param [IN] pszKeyboardMonitorCode          监视器编码
* @param [IN] ulKeyboardMonitorWindow         监视器窗格
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 设置OSD分设备叠加
* @param [IN]  pstUserLoginIDInfo         用户信息
* @param [IN]  OSD_PART_ADD_S           输入OSD信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 注意当输入摄像机编码为'\0'时,默认为设置模板
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPartOSD
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN  PART_OSD_INFO_S               *pstPartOsdInfo
);


/**
* 查询OSD分设备叠加
* @param [IN]  pstUserLoginIDInfo            用户信息
* @param [IN]  CHAR * szCameraCode     摄像机编码
* @param [OUT]  OSD_PART_ADD_S         输出OSD信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 注意当输入摄像机编码为'\0'时,默认为设置模板
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryPartOSD
(
    IN     USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN     CHAR                          *szCameraCode,
    OUT    PART_OSD_INFO_S               *pstPartOsdInfo
);

/* Begin Add By hexiaojun/hW0959 for 摄像机云台控制是否经过云台控制器 2015-1-15 */
/**
* 摄像机云台控制是否经过云台控制器处理函数 可以配置经过，可以配置不经过\n
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo        用户信息
* @param [IN] ULONG_32               ulPassFlag              0表示不经过云台控制器，1表示经过云台控制器
* @param [IN] ULONG_32               ulPassCamNum            摄像机的个数
* @param [IN] CAMERA_BASE_INFO_S    *pstCamList              摄像机列表

* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ProcessPassPTZCtrollerCamList
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN  ULONG_32                 ulPassFlag,
    IN  ULONG_32                 ulPassCamNum,
    IN  CAMERA_BASE_INFO_S       *pstCamList
);
/* End Add By hexiaojun/hW0959 for 摄像机云台控制是否经过晕他控制器 2015-2-9 */

/* Begin: Added by zhouquanwei/z01364, 2015-01-05 for ONVIF配置支持 */

/**
* 查询ONVIF摄像机视频编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                            szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [OUT]  ONVIF_VIDEO_ENCODER_CFGS_S      *pstVideoEncoderCfgs            视频编码配置
* @param [OUT]  ONVIF_VIDEO_ENCODER_OPTIONS_S   *pstVideoEncoderOptions         视频编码配置选项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifVideoEncodeing
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_VIDEO_ENCODER_CFGS_S      *pstVideoEncoderCfgs,
    OUT ONVIF_VIDEO_ENCODER_OPTIONS_S   *pstVideoEncoderOptions
);

/**
* 修改ONVIF摄像机视频编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [IN]  ONVIF_VIDEO_ENCODER_CFG_S    *pstVideoEncoderCfg             单个视频编码配置
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifVideoEncodeing
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_VIDEO_ENCODER_CFG_S   *pstVideoEncoderCfg
);

/**
* 暂时不支持音频编码的添加
*/
/**
* 查询ONVIF摄像机音频编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                            szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [OUT]  ONVIF_AUDIO_ENCODER_CFGS_S      *pstAudioEncoderCfgs            音频编码配置集合
* @param [OUT]  ONVIF_AUDIO_ENCODER_OPTIONS_S   *pstAudioEncoderOptions         音频编码配置选项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifAudioEncodeing
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_AUDIO_ENCODER_CFGS_S      *pstAudioEncoderCfgs,
    OUT ONVIF_AUDIO_ENCODER_OPTIONS_S   *pstAudioEncoderOptions
);

/**
* 设置ONVIF摄像机音频编码信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [IN]   ONVIF_AUDIO_ENCODER_CFG_S   *pstAudioEncoderCfg             音频编码配置
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifAudioEncodeing
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_AUDIO_ENCODER_CFG_S   *pstAudioEncoderCfg
);

/**
* 查询ONVIF摄像机图像参数 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [OUT]  ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings             图像设置
* @param [OUT]  ONVIF_IMAGING_OPTIONS_S     *pstImagingOptions              图像设置选项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifImagingSettings
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings,
    OUT ONVIF_IMAGING_OPTIONS_S     *pstImagingOptions
);

/**
* 设置ONVIF摄像机图像参数 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [IN]   ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings             图像设置
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifImagingSettings
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_IMAGING_SETTINGS_S    *pstImagingSettings
);

/**
* 查询ONVIF摄像机运动检测信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                        szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [OUT]  ONVIF_CELL_MOTION_INFO_S    *pstCellMotionInfo              运动检测信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifCellMotion
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_CELL_MOTION_INFO_S    *pstCellMotionInfo
);

/**
* 修改ONVIF摄像机运动检测信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                    szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [OUT]  ONVIF_OSD_S             *pstOnvifOSD                    ONVIF OSD 信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifCelMotion
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_CELL_MOTION_INFO_S    *pstCellMotionInfo
);

/**
* 查询ONVIF摄像机OSD信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                    szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [OUT]  ONVIF_OSDS_S            *pstOnvifOSDs                   ONVIF OSD 信息集合
* @param [OUT]  ONVIF_OSD_OPTIONS_S     *pstOnvifOSDOptions             ONVIF OSD 选项
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOnvifOSDs
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    OUT ONVIF_OSDS_S            *pstOnvifOSDs,
    OUT ONVIF_OSD_OPTIONS_S     *pstOnvifOSDOptions
);

/**
* 修改ONVIF摄像机OSD信息 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]   CHAR                    szCameraCode[IMOS_CODE_LEN]     摄像机编码
* @param [IN]   ONVIF_OSD_S             *pstOnvifOSD                    ONVIF OSD 信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* - #ERR_DAO_CAMERA_NOT_EXIST
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyOnvifOSD
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szCameraCode[IMOS_CODE_LEN],
    IN  ONVIF_OSD_MODIFY_S      *pstOnvifOSD
);
/* End: Added by zhouquanwei/z01364, 2015-01-05 for ONVIF配置支持 */

/**
* 查询DVR、NVR 下的通道列表  \n
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo        用户信息标识
* @param [IN]   CHAR                      szOrgCode                组织编码
* @param [IN]   COMMON_QUERY_CONDITION_S  *pstQueryCondition       查询信息条件
* @param [IN]   QUERY_PAGE_INFO_S         *pstQueryPageInfo        请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S           *pstRspPageInfo          返回分页信息
* @param [OUT]  NVR_CHL_CFG_INFO_S        *pstNvrChlInfoList          通道数组信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
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
/* Begin Add By hexiaojun/hW0959 for 平台支持snmpV3 2015-4-9 */
/**
* 增加SNMP模板 \n
* @param [IN]   pstUserLoginIDInfo          用户登录ID信息标识
* @param [IN]   pstSDKSnmpTemp              SNMP模板信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  SNMP_TEMP_S                 *pstSDKSnmpTemp
);

/**
* 修改snmp模板
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   pstModifySnmpTempl            键盘信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifySNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  SNMP_TEMP_S                     *pstModifySnmpTempl
);

/**
* 删除snmp模板
* @param [IN] pstUserLoginIDInfo              用户信息标识
* @param [IN] szSnmpTemplateName              snmp模板名称
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                         szSnmpTemplateId[IMOS_STRING_LEN_64]
);

/**
* 查询某个snmp模板的参数信息
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   szSnmpTemplateName            snmp模板名称
* @param [OUT]  pstSnmpTemplate               snmp模板参数信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QuerySNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                        szSnmpTemplateId[IMOS_STRING_LEN_64],
    OUT SNMP_TEMP_S                     *pstSnmpTemplate
);

/**
* 查询snmp模板列表 \n
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstSnmpTemplateList             键盘信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 设备配置snmp模板，可以配置一个也可以批量配置\n
* @param [IN] USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo     用户信息
* @param [IN] ULONG_32              ulDeviceNum             设备数量
* @param [IN] DEV_SNMP_INFO_S       *pstDeviceList          设备列表

* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ConfigDevSnmpTemplateList
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLoginIDInfo,
    IN  ULONG_32                 ulDeviceNum,
    IN  DEV_SNMP_INFO_S          *pstDeviceList
);

/**
* 查询某个设备配置了那一个snmp模板
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   szDevCode                     设备编码
* @param [OUT]  szSnmpTemplateId              设备配置的模板ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDevSNMPTemplate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szDevCode[IMOS_CODE_LEN],
    OUT SNMP_TEMP_S                     *pstSnmpTemplate
);
/* End Add By hexiaojun/hW0959 for 平台支持snmpV3 2015-4-9 */
/* Begin Add by yaojinhai/y01359 2014-11-19 for A8 */
/**
* 增加电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]       pstTVWallInfo      电视墙信息
* @param [OUT]    pcTVWallCode      电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_A8_S  *pstTVWallInfo,
    OUT     CHAR                    *pcTVWallCode
);

/**
* 修改电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN][OUT]  pstTVWallInfo      电视墙信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_A8_S  *pstTVWallInfo
);

/**
* 删除电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]       pcTvWallCode       电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWallA8
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR       *pcTvWallCode
);

/**
* 开启窗口 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [INOUT]       pstWindowInfo                  窗口信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenWindow
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    INOUT      TV_WALL_WINDOWS_INFO             *pstWindowInfo
);

/**
* 关闭窗口 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pcWindowCode                   窗口编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CloseWindow
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcWindowCode
);

/**
* 修改窗口（包括移动，缩放） \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstWindowInfo                  窗口信息
* @param [IN]       bSingleDB                          是否单纯数据库操作
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModWindow
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TV_WALL_WINDOWS_INFO             *pstWindowInfo,
    IN      BOOL_T                           bSingleDB
);

/**
* 设置窗口层次 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstWindowInfoList                   窗口数组
* @param [IN]       ulWindowNum                    窗口数量
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetWindowLevel
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TV_WALL_WINDOWS_INFO             *pstWindowInfoList,
    IN      ULONG_32                         ulWindowNum
);


/**
* 设置窗口透明度 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pcWindowCode                   窗口编码
* @param [IN]       ulTransparency                 透明度(0-100), 0不透明, 100全透明
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 保存电视墙场景 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pcSceneName                  场景名称
* @param [IN]       ulSceneID                      场景ID(1 - 32)
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 场景只保存32个，场景ID为1 - 32
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallSceneSave
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcSceneName,
    IN      ULONG_32                         ulSceneID
);

/**
* 修改电视墙场景名称 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pcSceneName                  场景名称
* @param [IN]       ulSceneID                      场景ID(1 - 32)
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 场景只保存32个，场景ID为1 - 32
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UpdateTVWallSceneName
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      CHAR                             *pcSceneName,
    IN      ULONG_32                         ulSceneID
);

/**
* 删除电视墙场景 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulSceneID                      场景ID(1 - 32)
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TVWallSceneDelete
(
   IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
   IN      CHAR                             *pcTVWallCode,
   IN      ULONG_32                         ulSceneID
);

/**
* 复制电视墙场景 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulFromID                       复制源场景ID
* @param [IN]       ulToID                         复制目的地场景ID
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 上传底图 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pcBasePicName                   电视墙底图名称
* @param [IN]       ulBasePicID                    底图ID号(0 - 7)
* @param [IN]       pcBasePicPath                  底图本地路径
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note 已经存在的编号进行覆盖
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
* 绑定底图 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulBasePicID                    底图ID号
* @param [IN]       pstPosition                    底图位置
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 启用停止底图 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulEnabled                      0: 停用  1:启用
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BasePicEnable
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulEnabled
);

/**
* 设置虚拟LED \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstTVWallVirtualLEDInfo      LED信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVirtualLEDInfo
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_VIRTUAL_LED_INFO_S        *pstTVWallVirtualLEDInfo
);

/**
* 启用/停用虚拟LED \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulEnabled                      是否启用，0: 停用 1: 启用
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulEnabled
);

/**
* 调整电视墙监视器亮度对比度 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstTVWallAdjustBrightCNT             调整亮度对比度信息
* @return ULONG返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：ERR_COMMON_FAIL
* -       其他见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustBrightCNT
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_ADJUST_BRIGHT_CNT_S       *pstTVWallAdjustBrightCNT
);

/**
* 配置电视墙监视器定时参数 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulDialSwitchID                 拼接屏拨码ID
* @param [IN]       pstTimerParam                  定时参数
* @return ULONG返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：ERR_COMMON_FAIL
* -       其他见错误码文件
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
* 配置电视墙监视器休眠恢复 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       ulDialSwitchID                 拼接屏拨码ID
* @param [IN]       ulDormancy                    休眠或恢复
* @return ULONG返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：ERR_COMMON_FAIL
* -       其他见错误码文件
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
* 测试输出端口 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pcOutputCode                   输出端口编码(如果为NULL，则表示测试所有输出端口)
* @param [IN]       ulTestMode                     测试模式(TEST_MODE_E)
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 设置输入端口EDID \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcInputCode                    输入端口编码(如果为NULL，则表示设置A8所有输入端口)
* @param [IN]       pcEDIDData                     EDID文件名
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetEDID
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcInputCode,
    IN      CHAR                             *pcEDIDName
);

/**
* 设置电视墙音频输入 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcAudioInputCode              音频输入源编码
* @param [IN]       pcTVWallCode                    电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAudioInput
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcAudioInputCode,
    IN      CHAR                             *pcTVWallCode
);

/**
* 设置电视墙音频输出 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcAudioOutputCode           音频输出编码
* @param [IN]       pcTVWallCode                    电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAudioOutput
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcAudioOutputCode,
    IN      CHAR                             *pcTVWallCode
);

/**
* 设置音频输出静音 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                    电视墙编码
* @param [IN]       ulIsEnable                          是否静音
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAudioMute
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcTVWallCode,
    IN      ULONG_32                         ulIsEnable
);

/**
* 调整音频音量 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                    电视墙编码
* @param [IN]       pcOutputCode                    输出编码
* @param [IN]       ulVolume                            音量
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 设置电视墙音频输出参数信息 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstTVWallOutputAudioParam            电视墙音频输出参数信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetOutputAudioParam
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_OUTPUT_AUDIO_PARAM_S      *pstTVWallOutputAudioParam
);

/**
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  A8_INFO_S                       *pstA8Info
);

/**
* 增加A8 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstA8Info             A8信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  A8_INFO_S                       *pstA8Info
);

/**
* 删除A8 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szA8Code                A8编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szA8Code[IMOS_CODE_LEN]
);

/**
* 修改A8 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstA8Info               A8信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  A8_INFO_S                       *pstA8Info
);

/**
* 查询A8 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szA8Code                A8编码
* @param [OUT]  pstA8Info               A8信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryA8
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szA8Code[IMOS_CODE_LEN],
    OUT A8_INFO_S                       *pstA8Info
);

/**
* 查询A8列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [IN]   bIsQuerySub             是否查询子组织
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstA8List               A8列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 增加电视墙场景组 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTVWallSceneGroup         场景组信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroup
);

/**
* 删除电视墙场景组 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pcTVWallSceneGroupCode         电视墙场景组编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            *pcTVWallSceneGroupCode
);

/**
* 修改电视墙场景组 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstTVWallSceneGroup          电视墙场景组
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroup
);

/**
* 查询电视墙场景组\n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pcTVWallSceneGroupCode                电视墙场景组编码
* @param [OUT]  pstTVWallSceneGroup               电视墙场景组信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTVWallSceneGroup
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            *pcTVWallSceneGroupCode,
    OUT TV_WALL_SCENE_GROUP_S           *pstTVWallSceneGroup
);

/**
* 修改输入图像参数 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstVinChannelImageParam                   输入图像参数
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVinChannelImageParam
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      VIN_CHANNEL_IMAGE_PARAM_S        *pstVinChannelImageParam
);

/**
* 查询输入图像参数 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcInputCode                   输入编码
* @param [OUT]    pstVinChannelImageParam        通道输入图像参数
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVinChannelImageParam
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcInputCode,
    OUT     VIN_CHANNEL_IMAGE_PARAM_S        *pstVinChannelImageParam
);

/**
* 修改输入参数 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pstVinChannelParam                   输入参数
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVinChannelParamA8
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      VIN_CHANNEL_PARAM_A8_S        *pstVinChannelParam
);

/**
* 查询输入参数 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcInputCode                   输入编码
* @param [OUT]    pstVinChannelParam        通道输入参数
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVinChannelParamA8
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             *pcInputCode,
    OUT     VIN_CHANNEL_PARAM_A8_S        *pstVinChannelParam
);

/**
*设置A8设备是否畅显 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       szDevCode                   设备编码
* @param [OUT]    ulIsSmoothDisplay        是否畅显
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetA8SmoothDisplay
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szDevCode[IMOS_DEVICE_CODE_LEN],
    IN      ULONG_32                         ulIsSmoothDisplay
);

/**
*获取A8设备是否畅显 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       szDevCode                   设备编码
* @param [OUT]    pulIsSmoothDisplay        是否畅显
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetA8SmoothDisplay
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT     ULONG_32                         *pulIsSmoothDisplay
);

/**
*设置电视墙是否自动吸附 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       szTVWallCode                   设备编码
* @param [OUT]    ulIsAutoAdsorbent        是否自动吸附
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTVWallAutoAdsorbent
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTVWallCode[IMOS_CODE_LEN],
    IN      ULONG_32                         ulIsAutoAdsorbent
);

/**
* 开始A8轮切 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szTVWallCode            电视墙编码
* @param [IN]   szSwitchResCode         轮切资源编码
* @param [IN]   szMonitorCode           窗口编码
* @param [IN]   ulOperateCode           操作原因码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 停止手动轮切 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szTVWallCode            电视墙编码
* @param [IN]   szMonitorCode           窗口编码
* @param [IN]   ulOperateCode           操作原因码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note ulOperateCode取值参见CS_OPERATE_CODE_E
*       szMonitorCode在软解轮切中为对应窗格编码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopA8Switch
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szTVWallCode[IMOS_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_RES_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* 获取窗口解码信息 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       szTVWallCode                   电视墙编码
* @param [IN]       szWindowCode                   窗口编码
* @param [IN]       ulSplitNum                     分屏号
* @param [OUT]      pstTVWallWindowDecodeInfo      窗口解码信息
* @return ULONG返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：ERR_COMMON_FAIL
* -       其他见错误码文件
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
* 根据DC设备编码查询监视器编码和通道索引信息 \n
* @param [IN]   pstUserLoginIDInfo      用户登录ID信息
* @param [IN]   szUACode                DC设备编码
* @param [OUT]  pulCount                返回记录数
* @param [OUT]  pstDCCodeIndexInfo      监视器编码和通道索引信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
/**查询某个组织下的ADU列表  \n
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   szOrgCode                   组织编码
* @param [IN]   pstQueryCondition           通用查询条件
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstDcQueryList              ADU查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 查询第三方DC共享资源列表
* @param [IN]   pstUserLoginIDInfo        用户信息
* @param [IN]   szOrgCode               外域组织编码
* @param [IN]   pstQueryPageInfo        设备分页信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryThirdDcRes
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo
);

/*Begin added by liangchao, 2016-03-21 for备份异常恢复需求*/
/**
* 启动失败任务补备 \n
* @param [IN]   USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo         用户登录ID信息标识
* @param [IN]   BAK_TASK_INFO_S           *pstManulBakInfo          手动备份任务信息
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddRetryBakTask
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN  ADD_RETRY_BAK_INFO_S          *pstRetryBakInfo
);

/**
* 删除补备任务 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo           用户登录ID信息标识
* @param [IN]   CHAR                    szRetryTaskId[IMOS_CODE_LEN]  补备任务ID
* @return ULONG_32 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelRetryBakTask
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                     szRetryTaskId[IMOS_CODE_LEN]
);

/**
* 查询失败任务列表 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  MANUL_BAKTASK_ORG_S *pstManulBakTaskOrgInfo      备份任务信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRetryBakTaskList
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IMOS_RETRY_TASK_INFO_S      *pstRetryBakTaskOrgInfo
);

/*End added by liangchao, 2016-03-21 for备份异常恢复需求*/

/* Begin: Added by zW4671, 2017-09-04 for MPPD51479  备份恢复列表增加相机名称 */
/**
* 查询失败任务列表V2 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo           用户信息标识
* @param [IN]   QUERY_PAGE_INFO_S        pstQueryPageInfo           请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S          pstRspPageInfo             响应分页信息
* @param [OUT]  IMOS_RETRY_TASK_INFO_V2_S  *pstRetryBakTaskOrgInfoV2     备份任务信息
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryRetryBakTaskListV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT IMOS_RETRY_TASK_INFO_V2_S      *pstRetryBakTaskOrgInfoV2
);
/* End: Added by zW4671, 2017-09-04 for MPPD51479  备份恢复列表增加相机名称 */


/*Begin added by w01677, 2016-08-10 forVM2500电视墙性能优化 */
/**
* 查询监视器监控关系列表 \n
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo   用户信息标识
* @param [IN]   CHAR                    szMonitorCode         监视器编码
* @param [INOUT]   ULONG_32             *pulSplitScreenNum      监视器分屏数
* @param [INOUT]  SCREEN_MON_RELATION_S *pstScreenMonRelationList      分屏监控关系列表
* @return ERR_COMMON_SUCCEED    表示成功，失败返回请见错误码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenMonRelation
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szMonitorCode[IMOS_RES_CODE_LEN],
    INOUT  ULONG_32                 *pulSplitScreenNum,
    INOUT   SCREEN_MON_RELATION_S   *pstScreenMonRelationList
);
/*Eend added by w01677, 2016-08-10 forVM2500电视墙性能优化 */
/**Begin Added by liujia ,2016-03-15 for 鱼眼配置添加*/
/**
* 查询鱼眼表信息
* @param [IN]	pstUserLoginIDInfo		用户信息
* @param [IN]	szFishEyeCode			鱼眼表编码
* @param [OUT]	pstFishEyeInfo			鱼眼表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 	返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFishEye
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	CHAR						 szFishEyeCode[IMOS_CODE_LEN],
	OUT FISHEYE_INFO_S				*pstFishEyeInfo
);

/**
* 配置鱼眼表信息
* @param [IN]	pstUserLoginIDInfo		用户信息
* @param [IN]	szFishEyeCode			鱼眼编码
* @param [IN]	pstFishEyeInfo			鱼眼表信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 	返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFishEye
(
	IN	USER_LOGIN_ID_INFO_S		*pstUserLoginIDInfo,
	IN	FISHEYE_INFO_S				*pstFishEyeInfo
);
/**End Added by liujia ,2016-03-15 for 鱼眼配置添加*/

/*Begin add by f03368, 2016-10-26 for MPPD42015*/
/**
* 查询某个UA的TCP策略信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szUACode             UA编码
* @param [OUT]  pstTCPStrateInfo    TCP策略信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note pstSrcUAList和pstDstUAList的内存需要由调用者申请
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTCPStrate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szUACode[IMOS_CODE_LEN],
    OUT TCP_STRATE_INFO_S          *pstTCPStrateInfo
);

/**
* 修改某个TC转码策略
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   pstTCPStrateInfo         TCP策略
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTCPStrate
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  TCP_STRATE_INFO_S       *pstTCPStrateInfo
);

/*End add by f03368, 2016-10-26 for MPPD42015*/

/* Begin: Added by huangsen W4381, 2017-09-19 for MPPD51185 告警联动到A8 告警属性窗口 */
/**
* 设置/取消窗口作为告警联动窗口 \n
* @param [IN]		pstUserLogIDInfo			   用户登录ID信息标识
* @param [IN]		pcTVWallCode				   电视墙编码
* @param [IN]		pcTVWindowsCode 			   窗口编码
* @param [IN]		ulEnabled					   是否启用，0: 停用 1: 启用
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* - 	 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableWinAlarm
(
	IN		USER_LOGIN_ID_INFO_S			 *pstUserLogIDInfo,
	IN		CHAR							 szTVWallCode[IMOS_CODE_LEN],
	IN		CHAR							 szTVWindowsCode[IMOS_CODE_LEN],
	IN		ULONG_32						 ulEnabled
);
/* End: Added by huangsen W4381, 2017-09-19 for MPPD51185 告警联动到A8 告警属性窗口 */

/* Begin: Added by lW2822, 2016-10-17 for MPPD42034支持海外包行业款IPC接入 */
/**
* 添加编码器，包含设备编码信息，如果该设备有独立音频，则后台自动增加。
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   pstEcAndAudioInfo           完整的EC设备级信息（包含EC信息和独立音频信息）
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.EC编码不能填空,且不能包含空格
* @note 2.新增携带设备显示型号
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddEcV2
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLoginIDInfo,
    IN    EC_INFO_V2_S                  *pstEcInfo
);


/**
* 查询某个编码器的信息
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   szEcCode                    编码器编码
* @param [OUT]  pstEcInfo                   EC信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryEcInfoV2
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szEcCode[IMOS_DEVICE_CODE_LEN],
    OUT EC_INFO_V2_S                    *pstEcInfo
);
/* End: Added by lW2822, 2016-10-17 for MPPD42034支持海外包行业款IPC接入 */



/**
* Restful初始化函数 \n
* @param [IN]  CHAR    szServerAdd[IMOS_IPADDR_LEN] 服务器IP
* @param [IN]  CALL_BACK_ALARM_PROC_PF pfnCallBackAlarmProc 告警回调函数
* @param [IN]  SPS_CALL_BACK_ALARM_PROC_PF pfnSpsCallBackAlarmProc SPS告警回调函数

* @return ULONG_32	返回如下结果:
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* - 	返回操作结果码，见错误码文件。
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_InitRestful
(
    IN CHAR szServerAdd[IMOS_IPADDR_LEN],
    IN CALL_BACK_ALARM_PROC_PF pfnCallBackAlarmProc,
    IN SPS_CALL_BACK_ALARM_PROC_PF pfnSpsCallBackAlarmProc
);

/* Begin: Added by lW2822, 2017-03-22 for MPPD45413 智能回放 */
/**
* 分页查询移动量记录
* @param [IN]    pstUserLogIDInfo        用户信息
* @parzm [IN]    pstMotionQueryInfo      感兴趣窗口对应的宏块信息
* @param [IN]    pstQueryPageInfo        分页请求信息
* @param [OUT]   pstRspPageInfo          分页响应信息
* @param [OUT]   pstMotionSliceInfoList  返回有移动量的时间信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMotionRecord
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  MOTION_QUERY_INFO_S         *pstMotionQueryInfo,
    IN  QUERY_PAGE_INFO_S           *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT TIME_SLICE_S                *pstMotionSliceInfoList
);
/* End: Added by lW2822, 2017-03-22 for MPPD45413 智能回放 */

/* Begin add by zhuzhicong/02302/代傅晓合入, 2017-07-03 for MPPD48388 显控终端 */
/**
* 增加显控终端 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDACTInfo             显控终端信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DACT_INFO_S                       *pstDACTInfo
);

/**
* 修改显控终端 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDACTInfo               显控终端信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DACT_INFO_S                       *pstDACTInfo
);

/**
* 删除显控终端 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDACTCode                显控终端编码
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDACTCode[IMOS_CODE_LEN]
);

/**
* 查询显控终端 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szDACTCode                显控终端编码
* @param [OUT]  pstDACTInfo               显控终端信息
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                                szDACTCode[IMOS_CODE_LEN],
    OUT DACT_INFO_S                       *pstDACTInfo
);

/**
* 查询显控终端列表 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstQueryCondition       通用查询条件
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [IN]   bIsQuerySub             是否查询子组织
* @param [OUT]  pstRspPageInfo          响应分页信息
* @param [OUT]  pstDACTList             显控终端列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
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
* 重置设备 \n
* @param [IN]   pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   pstDACTList             显控终端列表
* @return 返回如下结果：
* - 成功：
* - #ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetDACT
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DACT_INFO_S                       *pstDACTInfo
);
/* End add by zhuzhicong/02302/代傅晓合入, 2017-07-03 for MPPD48388 显控终端 */

/* Begin: Added by zhuzhicong 02302\代杨晓峰合入, 2017-07-03 for MPPD48388 XWARE接入到平台 */
/**
* 查询xware设备能力信息
* @param [IN]   pstUserLoginIDInfo      用户信息
* @param [IN]   szDeviceCode            xware设备编码
* @param [IN]   pstXWareAbility         xware设备能力信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_QueryXWareAbility
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo,
    IN  CHAR                       szDeviceCode[IMOS_CODE_LEN],
    OUT XWARE_ABILITY_S           *pstXWareAbility
);

/**
* 查询xware设备底图上传状态
* @param [IN]   pstUserLoginIDInfo      用户信息
* @param [IN]   pcTVWallCode            电视墙编码
* @param [IN]   ulBasePicID             底图id
* @param [IN]   ulBasePicStatus         底图状态
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
ULONG_32 STDCALL IMOS_QueryUploadPictureStatus
(
    IN  USER_LOGIN_ID_INFO_S      *pstUserLoginIDInfo,
    IN  CHAR                       pcTVWallCode[IMOS_CODE_LEN],
    IN  ULONG_32                   ulBasePicID,
    OUT ULONG_32                   &ulBasePicStatus
);
/* End: Added by zhuzhicong 02302\代杨晓峰合入, 2017-07-03 for MPPD48388 XWARE接入到平台 */

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 VM接入Xware */
#if 0
/* Xware独立于A8 sdk处理 */
#endif

/**
* 增加显控设备电视墙 \n
* @param [IN]       pstUserLogIDInfo 用户登录ID信息标识
* @param [IN]       pstTVWallInfo    电视墙信息
* @param [OUT]      szTVWallCode       电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_DACT_S  *pstTVWallInfo,
    OUT     CHAR                      szTVWallCode[IMOS_CODE_LEN]
);

/**
* 修改显控设备电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN][OUT]  pstTVWallInfo      电视墙信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S      *pstUserLogIDInfo,
    IN      TV_WALL_BASE_INFO_DACT_S  *pstTVWallInfo
);

/**
* 删除显控设备电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]       szTVWallCode       电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTVWallDACT
(
    IN      USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN      CHAR                    szTVWallCode[IMOS_CODE_LEN]
);

/**
* 查询显控设备电视墙 \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]       pcTvWallCode       电视墙编码
* @param [IN]       bUserControl       是否用户控制操作
* @param [OUT]      pstTVWallAllInfo   电视墙所有信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 查询显控设备电视墙列表 \n
* @param [IN]            pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]            pstQueryCondition       通用查询条件
* @param [IN]            pstQueryPageInfo        请求分页信息
* @param [OUT]         pstRspPageInfo          响应分页信息
* @param [OUT]         pstTVWallList      电视墙列表
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 新增虚拟LED \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [OUT]    pstTvwallVirLEDInfo            电视墙虚拟LED信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN      TVWALL_VIRTUAL_LED_INFO_V2_S    *pstTvwallVirLEDInfo
);

/**
* 修改虚拟LED \n
* @param [IN]       pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]    pstTvwallVirLEDInfo            电视墙虚拟LED信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      TVWALL_VIRTUAL_LED_INFO_V2_S     *pstTvwallVirLEDInfo
);

/**
* 删除虚拟LED \n
* @param [IN]    pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]    pcTvwallCode               电视墙编码
* @param [IN]    pulLEDID                    虚拟LED编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVirtualLED
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTvwallCode[IMOS_CODE_LEN],
    IN      ULONG_32                         ulLEDID
);

/**
* 查询单个虚拟LED \n
* @param [IN]       pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]       pcTvWallCode        电视墙编码
* @param [IN]       pulLEDID            虚拟LED编码
* @param [OUT]      pstTVWallVirLEDInfo 虚拟LED信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 查询电视墙所有虚拟LED \n
* @param [IN]       pstUserLogIDInfo   用户登录ID信息标识
* @param [IN]       pcTvWallCode       电视墙编码
* @param [INOUT]    *pulVirLEDNum      电视墙下虚拟led个数
* @param [OUT]      pstTVWallVirLEDList电视墙虚拟led列表
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 启用/停用虚拟LED-V2 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       pcTVWallCode                   电视墙编码
* @param [IN]       pulLEDID                       LED编码
* @param [IN]       ulEnabled                      是否启用，0: 停用 1: 启用
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 一键关闭显控终端电视墙所有窗口 \n
* @param [IN]       pstUserLogIDInfo               用户登录ID信息标识
* @param [IN]       szTVWallCode                   电视墙编码
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ClosedDACTAllWindows
(
    IN      USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN      CHAR                             szTVWallCode[IMOS_CODE_LEN]
);

#if 0
#endif
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 VM接入Xware */

/* Begin: Added by mW4699 maojiangfeng, 2018-03-07 for MPPD57183 Xware双击放大 */
/**
* 缩放Xware窗口\n
* @param [IN]       pstUserLogIDInfo              用户登录ID信息标识
* @param [IN]       pstWindowInfo                   电视墙窗口信息
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ZoomWindowDACT
(
    IN      USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN      TV_WALL_WINDOWS_INFO      *pstWindowInfo
);
/* End: Added by mW4699 maojiangfeng, 2018-03-07 for MPPD57183 Xware双击放大 */

/*Begin: Added by hesongchang/02908, 2017-07-06 for 物联网MAC业务，支持场所、安全厂商新配置项*/
/*************************************************************************************
场所信息配置，包含增加、删除、修改、查询
**************************************************************************************/
/**
* 增加场所
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstMacPlaceInfo            场所信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMacPlace
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* 删除场所
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szMacPlaceCode             场所编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMacPlace
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  CHAR                   szMacPlaceCode[IMOS_CODE_LEN]
);


/**
* 修改场所
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstMacPlaceInfo           场所信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMacPlace
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* 查询场所
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szMacPlaceCode            场所编码
* @param [OUT]  pstMacPlaceInfo         场所信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacPlace
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                   szMacPlaceCode[IMOS_CODE_LEN],
    OUT MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* 查询场所信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstMacPlaceList               场所信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
安全厂商信息配置，包含增加、删除、修改、查询
**************************************************************************************/
/**
* 增加安全厂商
* @param [IN]     pstUserLogIDInfo        用户信息
* @param [IN]     pstMacManuInfo            安全厂商信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMacManu
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  MAC_SEC_MANU_INFO_S        *pstMacManuInfo
);


/**
* 删除安全厂商
* @param [IN]   pstUserLogIDInfo        用户信息
* @param [IN]   szMacManuOrgCode             安全厂商编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMacManu
(
    IN  USER_LOGIN_ID_INFO_S   *pstUserLoginIDInfo,
    IN  CHAR                   szMacManuOrgCode[IMOS_CODE_LEN]
);


/**
* 修改安全厂商
* @param [IN]   pstUserLogIDInfo       用户信息
* @param [IN]   pstMacManuInfo           安全厂商信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMacManu
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  MAC_SEC_MANU_INFO_S        *pstMacManuInfo
);


/**
* 查询安全厂商
* @param [IN]   pstUserLogIDInfo     用户信息
* @param [IN]   szMacManuOrgCode            安全厂商编码
* @param [OUT]  pstMacManuInfo         安全厂商信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMacManu
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                   szMacManuOrgCode[IMOS_CODE_LEN],
    OUT MAC_SEC_MANU_INFO_S        *pstMacManuInfo
);


/**
* 查询安全厂商信息列表
* @param [IN]   pstUserLogIDInfo           用户登录ID信息标识
* @param [IN]   szOrgCode                  组织编码
* @param [IN]   pstQueryCondition          查询条件
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstMacManuList               安全厂商信息列表
* @return ULONG 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
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
* 查询IOT设备的场所信息
* @param [IN]   pstUserLoginIDInfo     用户信息
* @param [IN]   szIOTCode            物联网设备编码
* @param [OUT]  pstMacPlaceInfo         场所信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTMacPlaceInfo
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    OUT MAC_PLACE_INFO_S        *pstMacPlaceInfo
);


/**
* 查询IOT设备的安全厂商信息
* @param [IN]   pstUserLoginIDInfo     用户信息
* @param [IN]   szIOTCode            物联网设备编码
* @param [OUT]  pstMacPlaceInfo         场所信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
* - 1. 该接口仅支持VM平台
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTSecManuInfo
(
    IN  USER_LOGIN_ID_INFO_S  *pstUserLoginIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    OUT MAC_SEC_MANU_INFO_S        *pstMacSecManuInfo
);

/*End: Added by hesongchang/02908, 2017-07-06 for 物联网MAC业务，支持场所、安全厂商新配置项*/

/* Begin: Added by l03769, 2017-07-26 for MPPD49572 物联网设备经纬度上报和超感IPC能力管理 */
/**
* 查询物联网设备推送的资源(V2,扩展支持条件查询)
* @param [IN]   USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]   CHAR                        szOrgCode              组织编码
* @param [IN]   COMMON_QUERY_CONDITION_S    *pstQueryCondition     查询条件
* @param [IN]   QUERY_PAGE_INFO_S           *pstQueryPageInfo      请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S             *pstRspPageInfo        响应分页信息
* @param [OUT]  IOT_RES_QUERY_ITEM_V2_S     *pstIOTResList         物联网设备推送资源列表
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有物联网设备(包括DAE和超感IPC，但不查推送的资源)
* - 2.支持查询某一类物联网设备，QUERY_IOT_TYPE = 1 只查DAE设备；= 2 只查超感IPC；
                                               = 3 不查DAE和超感IPC，只查推送的资源，具体资源由条件3、4决定
* - 3.支持查询物联网设备下推送的资源，IS_QUERY_RES = 0 不查物联网设备下面的资源；= 1 查询物联网设备下的资源
      (如果只传了该条件且为1，但没有规定资源类型和资源子类型则默认返回物联网设备下的所有子资源)
* - 4.支持查询物联网设备推送资源类型，RES_TYPE = 2200 传感器；= 2201 动力设备
      (如果只传了资源类型而没有子类型，例如只传了传感器，则返回所有传感器资源)
* - 5.支持查询物联网设备推送资源子类型，RES_SUB_TYPE，传感器参见#SENSOR_TYPE_E，动环设备参见#MOVING_RING_DEV_TYPE_E
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
/* End: Added by l03769, 2017-07-26 for MPPD49572 物联网设备经纬度上报和超感IPC能力管理 */

/* Begin: Added by l03769, 2017-09-18 for MPPD51328 视频加扰 */
/**
* 查询摄像机视频解扰信息
* @param [IN]   pstUserLogIDInfo    用户登录ID信息标识
* @param [IN]   szCamCode           摄像机编码
* @param [IN]   pstQueryCondition   查询条件, 预留, 目前不需要填
* @param [OUT]  pstDescrambleInfo   视频解扰信息
* @note 1.如果无查询条件,指针pstQueryCondition可以为NULL
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryCamDescrambleInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  CHAR                            szCamCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT CAM_DESCRAMBLE_INFO_S           *pstCameraDescrambleInfo
);
/* End: Added by l03769, 2017-09-18 for MPPD51328 视频加扰 */

/* Begin: Added by l03769, 2017-09-18 for MPPD51448 物联网资源信息查询 */
/**
* 根据物联网资源编码查询资源信息
* @param [IN]   pstUserLogIDInfo      用户信息标识
* @param [IN]   pstIOTResQryInfo      物联网资源查询信息
* @param [IN]   pstQueryPageInfo      请求分页信息
* @param [OUT]  pstRspPageInfo        响应分页信息
* @param [OUT]  pstIOTResInfo         物联网资源信息
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 查询某个物联网设备下推送的资源V3
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   szIOTCode                   物联网设备编码
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstIOTResList               物联网设备推送资源列表
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.增加返回设备名称
        2.支持条件查询
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
* 根据资源类型信息查询所有物联网相关信息
* @param [IN]   pstUserLogIDInfo           用户信息标识
* @param [IN]   pstQueryPageInfo           请求分页信息
* @param [IN]   pstIOTInfoQryParameter     物联网信息查询参数
* @param [OUT]  pstRspPageInfo             响应分页信息
* @param [OUT]  pstIOTInfoList             物联网信息列表
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 根据名称模糊检索物联网设备
* @param [IN]   pstUserLogIDInfo              用户信息标识
* @param [IN]   pstFuzzyQueryIOTParameter     模糊查询物联网设备参数
* @param [IN]   pstQueryPageInfo              请求分页信息
* @param [OUT]  pstRspPageInfo                响应分页信息
* @param [OUT]  pstFuzzyQueryIOTResultList    模糊查询物联网设备列表
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 批量查询物联网资源列表
* @param [IN]   pstUserLogIDInfo             用户信息标识
* @param [IN]   pstBatchQueryIOTParameter    批量查询物联网资源参数
* @param [IN]   pstQueryPageInfo             请求分页信息
* @param [OUT]  pstRspPageInfo               响应分页信息
* @param [OUT]  pstBatchQueryIOTResList      批量查询物联网资源列表
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BatchQueryIOTResList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  BATCH_QUERY_IOT_PARAMETER_S  *pstBatchQueryIOTParameter,
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT BATCH_QUERY_IOT_RES_LIST_S   *pstBatchQueryIOTResList
);
/* End: Added by l03769, 2017-09-18 for MPPD51448 物联网资源信息查询 */

/* Begin: Added by sW4519, 2017-9-19 for MPPD50527\代liningchuan合入 */
/**
* 资源树右键修改任何类型相机名称
* @param [IN] pstUserLoginIDInfo 用户信息标识
* @param [IN] pstCamInfo         摄像机信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyAllKindsCamName
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN ALL_KINDS_CAM_NAME_S *pstCamInfo
);
/* End: Added by sW4519, 2017-9-19 for MPPD50527\代liningchuan合入 */

/* Begin: Add by yW4708, 2017-10-18 for MPPD52393 增加用户身份证信息 */
/**
* 增加用户信息，此信息中包含用户编码，唯一索引
* @param [IN]   pstUserLoginIDInfo        用户信息标识
* @param [IN]   szOrgCode               组织编码
* @param [IN]   pstUserPasswordInfo     带密码和身份证的用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddUserV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN],
    IN  USER_INFO_PASSWORD_V2_S        *pstUserPasswordInfo
);

/**
* 修改用户信息，其中用户编码不可修改，但是需要带入
* @param [IN]   pstUserLoginIDInfo        用户信息标识
* @param [IN]   pstUserInfo             用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyUserV2
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN  USER_INFO_V2_S                 *pstUserInfo
);

/**
* 查询某个用户的信息
* @param [IN]   pstUserLoginIDInfo            用户信息标识
* @param [IN]   szUserCode                  用户编码
* @param [OUT]  pstUserInfo                 用户信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryUserInfoV2
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo,
    IN   CHAR                           szUserCode[IMOS_USER_CODE_LEN],
    OUT  USER_INFO_V2_S                    *pstUserInfo
);
/* End: Add by yW4708, 2017-10-18 for MPPD52393 增加用户身份证信息 */

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */
/**
* 查询物联网设备信息V2
* @param [IN]   pstUserLoginIDInfo    用户信息标识
* @param [IN]   szIOTCode             物联网设备编码
* @param [OUT]  pstIOTInfo            物联网设备信息
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTInfoV2
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szIOTCode[IMOS_DEVICE_CODE_LEN],
    OUT IOT_INFO_V2_S           *pstIOTInfo
);

/**
* 增加舱室信息
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]   CABIN_INFO_S            *pstCabinInfo          舱室信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddCabinInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CABIN_INFO_S            *pstCabinInfo
);

/**
* 删除舱室信息
* @param [IN]   USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]   ULONG_32                ulCabinType            舱室类型枚举
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteCabinInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  ULONG_32                ulCabinType
);

/**
* 查询舱室信息
* @param [IN]    USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]    QUERY_CABIN_INFO_S          *pstQueryCabinInfo     查询舱室信息
* @param [IN]    COMMON_QUERY_CONDITION_S    *pstQueryCondition     查询条件
* @param [IN]    QUERY_PAGE_INFO_S           *pstQueryPageInfo      请求分页信息
* @param [OUT]   RSP_PAGE_INFO_S             *pstRspPageInfo        响应分页信息
* @param [OUT]   CABIN_INFO_S                *pstCabinInfoList      舱室信息列表
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1.条件暂时为NULL，方便以后扩展使用
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
* 增加防火分区组合
* @param [IN]   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]   FIRE_ZONE_COMBINATIONINFO_S    *pstAddFireZoneCom     增加防火分区组合入参
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFireZoneCombination
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  FIRE_ZONE_COMBINATION_INFO_S    *pstAddFireZoneCom
);

/**
* 删除防火分区组合
* @param [IN]   USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]   FIRE_ZONE_COMBINATION_INFO_S    *pstDelFireZoneCom     删除防火分区组合入参
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteFireZoneCombination
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  FIRE_ZONE_COMBINATION_INFO_S     *pstDelFireZoneCom
);

/**
* 查询防火分区组合
* @param [IN]    USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo            用户登录ID信息标识
* @param [IN]    FIRE_ZONE_QUERY_INFO_S         *pstFireZoneQueryInfo          防火分区查询信息
* @param [IN]    COMMON_QUERY_CONDITION_S       *pstQueryCondition             查询条件
* @param [OUT]   FIRE_ZONE_COMBINATIONINFO_S    *pstFireZoneCombinationInfo    防火分区组合信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1.条件暂时为NULL，方便以后扩展使用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFireZoneCombination
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
    IN  FIRE_ZONE_QUERY_INFO_S          *pstFireZoneQueryInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    OUT FIRE_ZONE_COMBINATION_INFO_S    *pstFireZoneCombinationInfo
);

/**
* 增加防火分区与舱室绑定关系
* @param [IN]   USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo                    用户登录ID信息标识
* @param [IN]   FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstAddFireZoneAndCabinRelationInfo    增加防火分区与舱室关联信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddFireZoneAndCabinRelationInfo
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo,
    IN  FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstAddFireZoneAndCabinRelationInfo
);

/**
* 删除防火分区与舱室绑定关系
* @param [IN]   USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo                     用户登录ID信息标识
* @param [IN]   FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstDeldFireZoneAndCabinRelationInfo    删除防火分区与舱室关联信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelFireZoneAndCabinRelationInfo
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo,
    IN  FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstDeldFireZoneAndCabinRelationInfo
);

/**
* 查询防火分区与舱室绑定关系
* @param [IN]    USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo                 用户登录ID信息标识
* @param [IN]    FIRE_ZONE_AND_CABIN_QUERY_INFO_S       *pstFireZoneAndCabinQueryInfo       防火分区与舱室查询信息
* @param [IN]    COMMON_QUERY_CONDITION_S               *pstQueryCondition                  查询条件
* @param [OUT]   FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstFireZoneAndCabinRelationInfo    防火分区与舱室关联信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1.条件暂时为NULL，方便以后扩展使用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryFireZoneAndCabinRelationInfo
(
    IN  USER_LOGIN_ID_INFO_S                   *pstUserLoginIDInfo,
    IN  FIRE_ZONE_AND_CABIN_QUERY_INFO_S       *pstFireZoneAndCabinQueryInfo,
    IN  COMMON_QUERY_CONDITION_S               *pstQueryCondition,
    OUT FIRE_ZONE_AND_CABIN_RELATION_INFO_S    *pstFireZoneAndCabinRelationInfo
);

/**
* 增加物联网设备推送资源与舱室绑定关系
* @param [IN]    USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo               用户登录ID信息标识
* @param [IN]    RES_AND_CABIN_RELATION_INFO_S    *pstAddResAndCabinRelationInfo    物联网设备推送资源与舱室关联信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddResAndCabinRelation
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  RES_AND_CABIN_RELATION_INFO_S    *pstAddResAndCabinRelationInfo
);

/**
* 删除物联网设备推送资源与舱室绑定关系
* @param [IN]    USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo               用户登录ID信息标识
* @param [IN]    RES_AND_CABIN_RELATION_INFO_S    *pstDelResAndCabinRelationInfo    物联网设备推送资源与舱室关联信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelResAndCabinRelation
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  RES_AND_CABIN_RELATION_INFO_S    *pstDelResAndCabinRelationInfo
);

/**
* 修改物联网设备推送资源与舱室绑定关系
* @param [IN]    USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo                  用户登录ID信息标识
* @param [IN]    RES_AND_CABIN_RELATION_INFO_S    *pstModifyResAndCabinRelationInfo    物联网设备推送资源与舱室关联信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyResAndCabinRelation
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLoginIDInfo,
    IN  RES_AND_CABIN_RELATION_INFO_S    *pstModifyResAndCabinRelationInfo
);

/**
* 查询物联网设备推送资源与舱室绑定关系
* @param [IN]      USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo    用户登录ID信息标识
* @param [IN]      COMMON_QUERY_CONDITION_S    *pstQueryCondition     查询条件
* @param [IN]      ULONG_32                    ulReqNum               请求数量
* @param [INOUT]   RES_AND_CABIN_LIST_S        *pstResAndCabinList    物联网设备推送资源与舱室关联列表
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1.条件暂时为NULL，方便以后扩展使用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryResAndCabinRelation
(
    IN     USER_LOGIN_ID_INFO_S        *pstUserLoginIDInfo,
    IN     COMMON_QUERY_CONDITION_S    *pstQueryCondition,
    IN     ULONG_32                    ulReqNum,
    INOUT  RES_AND_CABIN_ITEM_S        *pstResAndCabinList
);

/**
* 查询物联网设备推送资源的历史数据
* @param [IN]   USER_LOGIN_ID_INFO_S           *pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN]   IOT_RES_DATA_QUERY_INFO_S      *pstIOTResDataQueryInfo    物联网推送资源的数据查询信息
* @param [IN]   COMMON_QUERY_CONDITION_S       *pstQueryCondition         查询条件
* @param [IN]   QUERY_PAGE_INFO_S              *pstQueryPageInfo          请求分页信息
* @param [OUT]  RSP_PAGE_INFO_S                *pstRspPageInfo            响应分页信息
* @param [OUT]  IOT_RES_HISTORY_DATA_ITEM_S    *pstIOTHistoryDataList     物联网设备推送资源的历史数据列表
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
* - 1.条件暂时为NULL，方便以后扩展使用
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
* 查询物联网设备推送资源的实时数据
* @param [IN]   USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo             用户登录ID信息标识
* @param [IN]   QUERY_REAL_TIME_DATA_S           *pstQueryInfo                 查询实时数据信息
* @param [OUT]  IOT_RES_REAL_TIME_DATA_ITEM_S    *pstIOTResRealTimeDataList    物联网设备推送资源的实时数据列表
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTPushResRealTimeData
(
    IN  USER_LOGIN_ID_INFO_S             *pstUserLogIDInfo,
    IN  QUERY_REAL_TIME_DATA_S           *pstQueryInfo,
    OUT IOT_RES_REAL_TIME_DATA_ITEM_S    *pstIOTResRealTimeDataList
);

/**
* 物联网开关量控制
* @param [IN]   USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo        用户登录ID信息标识
* @param [IN]   SWITCH_CONTROL_INFO_S    *pstSwitchControlInfo    开关量信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_IOTSwitchControl
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  SWITCH_CONTROL_INFO_S    *pstSwitchControlInfo
);

/**
* 物联网开关量状态查询
* @param [IN]   USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo            用户登录ID信息标识
* @param [IN]   SWITCH_STATUS_QUERY_INFO_S    *pstSwitchStatusQueryInfo    开关量状态查询信息
* @param [OUT]  SWITCH_STATUS_INFO_S          *pstSwitchStatusInfo         开关量状态as信息
* @return ULONG_32 返回如下结果：
* - 成功：#ERR_COMMON_SUCCEED
* - 失败: #ERR_DAO_DOMAIN_NOT_EXIST
* - 返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTSwitchStatus
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  SWITCH_STATUS_QUERY_INFO_S    *pstSwitchStatusQueryInfo,
    OUT SWITCH_STATUS_INFO_S          *pstSwitchStatusInfo
);

/**
* 根据传感器编码批量查询传感器在数据库中最新的记录
* @param [IN]     USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo          用户登录ID信息标识
* @param [IN]     IOT_RES_CODE_LIST_S           *pstIOTResCode             物联网资源编码
* @param [INOUT]  ULONG_32                      *pulQueryNum               查询个数
* @param [OUT]    IOT_RES_HISTORY_DATA_ITEM_S   *pstIOTHistoryDataList     物联网设备推送资源的历史数据最新记录列表
* @return 返回如下结果:
* - 成功:
* - #ERR_COMMON_SUCCEED
* - 失败:
* -      返回操作结果码，见错误码文件
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
* 查询某个物联网设备下推送资源的所有信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   szIOTCode               设备编码
* @param [IN]   pstQueryPageInfo        请求分页信息
* @param [OUT]  pstRspPageInfo          返回分页信息
* @param [OUT]  pstIOTResAllInfoList    物联网设备推送资源列表
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryIOTAllInfoList
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  CHAR                         szIOTCode[IMOS_DOMAIN_CODE_LEN],
    IN  QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S              *pstRspPageInfo,
    OUT IOT_RES_ALL_INFO_ITEM_S      *pstIOTResAllInfoList
);
/* End: Added by l03769, 2017-11-07 for MPPD52823 地下综合管廊特性后台合入B3328 */

/* Begin: Added by l03769, 2017-12-21 for MPPD53844 物联网资源管理二期 */
/**
* 查出环境中所有的物联网设备(包括超感IPC和DAE)
* @param [IN]    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo           用户信息标识
* @param [IN]    QUERY_PAGE_INFO_S       *pstQueryPageInfo           请求分页信息
* @param [OUT]   RSP_PAGE_INFO_S         *pstRspPageInfo             响应分页信息
* @param [OUT]   IOT_QUERY_ITEM_V2_S     *pstIOTQueryItemInfoList    所有的物联网设备(包括超感IPC和DAE)
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
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
* 手动导入物联网设备及资源
* @param [IN]    pstUserLogIDInfo              *pstUserLogIDInfo           用户信息标识
* @param [IN]    MANUAL_ADD_IOT_INFO_S         *pstManualAddIOTInfo        手动添加IOT信息
* @param [OUT]   MANUAL_ADD_IOT_FAIL_INFO_S    *pstManualAddIOTFailInfo    手动添加IOT失败信息
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.这个出参主要是为了让用户知道哪个设备添加的时候出问题了，以便排查
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualAddIOT
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  MANUAL_ADD_IOT_INFO_S        *pstManualAddIOTInfo,
    OUT MANUAL_ADD_IOT_FAIL_INFO_S   *pstManualAddIOTFailInfo
);

/**
* 手动导出物联网设备及资源
* @param [IN]    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo          用户信息标识
* @param [IN]    CHAR                     szIOTCode                  设备编码
* @param [OUT]   MANUAL_ADD_IOT_INFO_S    *pstManualExportIOTInfo    手动导出的IOT信息
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualExportIOT
(
    IN   USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN   CHAR                     szIOTCode[IMOS_DEVICE_CODE_LEN],
    OUT  MANUAL_ADD_IOT_INFO_S    *pstManualExportIOTInfo
);
/* End: Added by l03769, 2017-12-21 for MPPD53844 物联网资源管理二期 */

#if 0
#endif

/* Begin added by zhukaikai/W4801, 2017-12-28 for 地标器特性 MPPD54420 */
/*******************************************************************************
设备-地标器
*******************************************************************************/
/**添加地标器
* @param [IN]   pstUserLoginIDInfo    用户信息标识
* @param [IN]   pstLandmarksInfo      地标器信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 地标器编码不能填空,且不能包含空格
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_AddLandmarks
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN    LANDMARKS_INFO_S        *pstLandmarksInfo
);


/**删除地标器
* @param [IN]   pstUserLoginIDInfo    用户信息标识
* @param [IN]   szLandmarksCode       地标器编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_DelLandmarks
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  CHAR                    szLandmarksCode[IMOS_DEVICE_CODE_LEN]
);


/**修改地标器
* @param [IN]   pstUserLoginIDInfo    用户信息标识
* @param [IN]   pstLandmarksInfo      地标器信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 其中设备编码不可能修改，但是需要带入
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_ModifyLandmarks
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN  LANDMARKS_INFO_S        *pstLandmarksInfo
);


/**查询某个地标器的信息
* @param [IN]    pstUserLoginIDInfo    用户信息标识
* @param [IN]    szLandmarksCode       地标器编码
* @param [OUT]   pstLandmarksInfo      地标器设备信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL  IMOS_QueryLandmarksInfo
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLoginIDInfo,
    IN    CHAR                    szLandmarksCode[IMOS_DEVICE_CODE_LEN],
    OUT   LANDMARKS_INFO_S        *pstLandmarksInfo
);


/**查询某个组织下的地标器列表  \n
* @param [IN]   pstUserLoginIDInfo       用户信息标识
* @param [IN]   szOrgCode                组织编码
* @param [IN]   pstQueryCondition        通用查询条件(可为NULL;支持的查询条件:#NAME_TYPE[地标器名称])
* @param [IN]   pstQueryPageInfo         请求分页信息
* @param [OUT]  pstRspPageInfo           返回分页信息
* @param [OUT]  pstLandmarksQueryList    地标器查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
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
/* End added by zhukaikai/W4801, 2017-12-28 for 地标器特性 MPPD54420 */

/* Begin: Added by limengni 03868, 2017-12-19 for 物联网设备类型及场所相关查询 */
/**
* 查询某个物联网设备下推送的资源V4
* @param [IN]   pstUserLoginIDInfo          用户信息标识
* @param [IN]   szOrgCode                   组织编码
* @param [IN]   pstQueryPageInfo            请求分页信息
* @param [OUT]  pstRspPageInfo              返回分页信息
* @param [OUT]  pstIOTResList               物联网设备推送资源列表
* @return 返回如下结果：
* - 成功：ERR_COMMON_SUCCEED
* - 失败：
* -     返回操作结果码，见错误码文件
* @note 1.增加返回设备名称
        2.支持条件查询
        * - 过滤
* - 1.条件可以为NULL,表示查指定组织下所有资源(不查子组织)
* - 2.支持按"是否查子组织"条件查询:#IS_QUERY_SUB = 1 是;= 0 否
* - 3.支持按"资源名称"模糊查询:#NAME_TYPE
* - 4.支持按"资源类型"查询:#RES_TYPE,取值为#IMOS_TYPE_E, 仅支持逻辑关系类型为#EQUAL_FLAG;
* - 5.支持按"资源子类型"查询:#RES_SUB_TYPE(资源类型为摄像机时,取值为#CAMERA_TYPE_E)
* - 排序
* - 1.不指定排序条件情况下,默认按"资源名称"升序排序
* - 2.支持的排序条件,包括:#NAME_TYPE(资源名称),#CODE_TYPE(资源编码),#RES_TYPE(资源类型),#RES_SUB_TYPE(资源子类型)
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
/* End: Added by limengni 03868, 2017-12-19 for 物联网设备类型及场所相关查询 */

/* Begin: added by gaopan/W4627, 2018-3-7 for 公安客户端摄像机上墙时能够有上墙的历史记录特性 MPPD56781*/
/**查询当前用户所在目录下在线监视器信息 \n
* @param [IN]   pstUserLoginIDInfo       用户信息标识
* @param [IN]   pstQueryPageInfo         请求分页信息
* @param [OUT]  pstRspPageInfo           返回分页信息
* @param [OUT]  pstScreenSplitInfoList    监视器信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* - 返回操作结果码，见错误码文件
* @note 分页查询中每页的最大条目数, 不能为0, 也不能大于#IMOS_SCREEN_SPLIT_PAGE_MAX_NUM
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryScreenSplitInfoByUser
(
    IN USER_LOGIN_ID_INFO_S         *pstUserLoginIDInfo,
    IN QUERY_PAGE_INFO_S            *pstQueryPageInfo,
    OUT RSP_PAGE_INFO_S             *pstRspPageInfo,
    OUT SCREEN_SPLIT_INFO_S         *pstScreenSplitInfoList
);
/* End: added by gaopan/W4627, 2018-3-7 for 公安客户端摄像机上墙时能够有上墙的历史记录特性 MPPD56781*/


#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif


