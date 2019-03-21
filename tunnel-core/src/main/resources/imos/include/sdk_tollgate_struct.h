/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              sdk_tollgate_struct.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2011-03-14
        Author: baoyihui/02795
   Description: 卡口SDK结构定义


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_TOLLGATE_STRUCT_H_
#define _IMOS_SDK_TOLLGATE_STRUCT_H_

#ifdef  __cplusplus
    extern "C"{
#endif

/**
 * @struct tagTMSInfo
 * @brief TMS(交通媒体交换服务器)信息
 * @attention
 */
typedef struct tagTMSInfo
{
    /** 编码 */
    CHAR szTMSCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR szTMSName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称，查询返回，其他情况下可以不填 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** TMS类型，目前填写0 */
    ULONG_32 ulType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址，查询返回，其他情况下可以不填 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 描述, 暂不使用，填空 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

} TMS_INFO_S;

/**
 * @struct tagDRInfo
 * @brief DR(数据搜索服务器)信息
 * @attention
 */
typedef struct tagDRInfo
{
    /** 编码 */
    CHAR szDRCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR szDRName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称，查询返回，其他情况下可以不填 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** DRS类型，目前填写0 */
    ULONG_32 ulType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址，查询返回，其他情况下可以不填 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 描述, 暂不使用，填空 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

} DR_INFO_S;


/**
 * @struct tagTollgateInfo
 * @brief 卡口信息结构
 * @attention
 */
typedef struct tagTollgateInfo
{
    /** 卡口编号 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称，暂不支持，填空 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** 所属TMS编码 */
    CHAR szTMSCode[IMOS_CODE_LEN];

    /** 所属TMS名称，查询返回，其他情况下可以不填 */
    CHAR szTMSName[IMOS_NAME_LEN];

    /** 卡口类型，参考#TALLGATE_TYPE_E */
    ULONG_32 ulType;

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 车道数 */
    ULONG_32 ulLaneNum;

    /** 经度 */
    CHAR szLongitude[IMOS_COORDINATE_LEN];

    /** 纬度 */
    CHAR szLatitude[IMOS_COORDINATE_LEN];

    /** 卡口示意图(形如ftp://用户名:密码@192.168.10.1/dispose/abc.jpg)，必须先通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper获取FTP参数 */
    CHAR szPicture[IMOS_FILE_PATH_LEN];

    /** 卡口描述，暂未使用，填空 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 地点编码 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** 地点名称，查询返回，其他情况下可以不填 */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** 采集机关编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 采集机关名称 */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** 预留字段 */
    CHAR szReserve[256];
} TOLLGATE_INFO_S;

/**
 * @struct tagTollgateLaneInfo
 * @brief 卡口车道信息结构
 * @attention
 */
typedef struct tagTollgateLaneInfo
{
    /** 所属卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 车道号 */
    ULONG_32 ulLaneNumber;

    /** 车道类型，参考#LANE_TYPE_E */
    ULONG_32 ulLaneType;

    /** 方向编号，废弃 */
    ULONG_32 ulDirection;

    /** 方向名称，废弃 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** 标示限速，单位Km/h */
    ULONG_32 ulMarkedSpeed;

    /** 执法限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 进出城标志: 0,不涉及 1,进城 2,出城 */
    ULONG_32 ulIntoCityFlag;

    /** 方向编号 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段信息 */
    CHAR szReserve[192];
}TOLLGATE_LANE_INFO_S;

/**
 * @struct tagTollgateLaneQueryItem
 * @brief 卡口车道查询结构
 * @attention
 */
typedef struct tagTollgateLaneQueryItem
{
    /** 所属卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 所属卡口名称，查询返回，其他情况下可以不填 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 车道号 */
    ULONG_32 ulLaneNumber;

    /** 车道类型，参考#LANE_TYPE_E */
    ULONG_32 ulLaneType;

    /** 方向编号，废弃 */
    ULONG_32 ulDirection;

    /** 方向名称，废弃 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** 标示限速，单位Km/h */
    ULONG_32 ulMarkedSpeed;

    /** 执法限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 进出城标志: 0,不涉及 1,进城 2,出城 */
    ULONG_32 ulIntoCityFlag;

    /** 抓拍相机编码 */
    CHAR szPhotoCameraCode[IMOS_CODE_LEN];

    /** 抓拍相机名称 */
    CHAR szPhotoCameraName[IMOS_NAME_LEN];

    /** 全景摄像机编码 */
    CHAR szVideoCameraCode[IMOS_CODE_LEN];

    /** 全景摄像机名称 */
    CHAR szVideoCameraName[IMOS_NAME_LEN];

    /** 方向编号 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段信息 */
    CHAR szReserve[192];
}TOLLGATE_LANE_QUERY_ITEM_S;

/**
 * @struct tagTrafficLightStatus
 * @brief 红绿灯状态
 * @attention
 */
typedef struct tagTrafficLightStatus
{
    /** 方向编号 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 采样时间 */
    CHAR szSampleTime[IMOS_TIME_LEN];

    /** 红绿灯状态，按照十进制位从低到高，依次表示左直右的红绿灯状态，千位预置位1，个/十/百，每一位的状态位参考#TRAFFIC_LIGHT_STATUS_E */
    ULONG_32 ulTrafficLightStatus;

    /** 预留字段信息 */
    CHAR szReserve[196];
}TRAFFIC_LIGHT_STATUS_S;

/**
 * @struct tagTollgateCameraInfo
 * @brief 卡口相机信息结构
 * @attention
 */
typedef struct tagTollgateCameraInfo
{
    /** 相机编码 */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** 相机名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 相机类型，参考#TALLGATE_CAMERA_TYPE_E */
    ULONG_32 ulCameraType;

    /** 所属EC编码 */
    CHAR szECCode[IMOS_CODE_LEN];

    /** 所属EC名称，查询返回，其他情况下可以不填 */
    CHAR szECName[IMOS_NAME_LEN];

    /** 所属EC类型 */
    ULONG_32 ulECType;

    /** 所属EC通道 */
    ULONG_32 ulECChannel;

    /** 所属卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 所属卡口名称，查询返回，其他情况下可以不填 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 抓拍的车道数量，如果是一个车道对应一个相机，则填1 */
    ULONG_32 ulTollgateLaneNum;

    /** 抓拍的卡口车道列表 */
    ULONG_32 aulTollgateLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 经度 */
    CHAR  szLongitude[IMOS_COORDINATE_LEN];

    /** 纬度 */
    CHAR  szLatitude[IMOS_COORDINATE_LEN];

    /** 相机描述, 暂不使用，填空 */
    CHAR  szCameraDesc[IMOS_DESC_LEN];

    /** 采集设备类型 */
    CHAR  szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段 */
    CHAR szReserve[196];
} TOLLGATE_CAMERA_INFO_S;

/**
 * @struct tagTollgateFlashlightInfo
 * @brief 闪光灯信息结构
 * @attention
 */
typedef struct tagTollgateFlashlightInfo
{
    /** 闪光灯编号 */
    CHAR szTollgateFlashlightCode[IMOS_CODE_LEN];

    /** 闪光灯名称 */
    CHAR szTollgateFlashlightName[IMOS_NAME_LEN];

    /** 所属卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 所属卡口名称，查询返回，其他情况下可以不填 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 安装时间 */
    CHAR szBulidTime[IMOS_TIME_LEN];

    /** 闪光次数 */
    ULONG_32 ulFlashCount;

    /** 抓拍的车道数量，如果是一个车道对应一个闪光灯则填写1 */
    ULONG_32 ulTollgateLaneNum;

    /** 抓拍的卡口车道列表 */
    ULONG_32 aulTollgateLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** 预留字段 */
    CHAR szReserve[256];
} TOLLGATE_FLASHLIGHT_INFO_S;

/**
 * @struct tagDispositionDept
 * @brief 布/撤控单位结构
 * @attention
 */
typedef struct tagDispositionDept
{
    /** 单位编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 单位名称 */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** 单位类型，参考#DISPOSITION_DEPT_TYPE_E */
    ULONG_32 ulDeptType;

    /** 城镇名称 */
    CHAR szCityName[IMOS_NAME_LEN];

    /** 联系人 */
    CHAR szContactName[IMOS_NAME_LEN];

    /** 联系电话 */
    CHAR szPhone[IMOS_PHONE_LEN];

    /** 联系手机 */
    CHAR szMobilePhone[IMOS_MOBILE_LEN];

    /** 单位描述 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;
} DISPOSITION_DEPT_S;

/**
 * @struct tagStatementDispositionUndoInfo
 * @brief 撤控信息结构
 * @attention
 */
typedef struct tagStatementDispositionUndoInfo
{

    /** 撤控单位编码，必须填写 */
    CHAR szUndoDept[IMOS_CODE_LEN];

    /** 撤控人员编码，必须填写 */
    CHAR szUndoUser[IMOS_CODE_LEN];

    /** 撤控时间 */
    CHAR szUndoTime[IMOS_TIME_LEN];

    /** 撤控原因，可以不填写 */
    CHAR szUndoDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[204];

} STATEMENT_DISPOSITION_UNDO_INFO_S;

/**
 * @struct tagStatementDispositionInfo
 * @brief 布控信息结构
 * @attention
 */
typedef struct tagStatementDispositionInfo
{
    /** 布控编号，系统自动生成 */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** 互联布控类型，参考#DISPOSITION_INTER_TYPE_E */
    ULONG_32 ulInterType;

    /** 是否模糊匹配，BOOL_TRUE: 模糊匹配，BOOL_FALSE: 精确匹配 */
    BOOL_T bFuzzyMatch;

    /** 号牌号码，必须填写 */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典，可以不填，默认为空，表示所有种类 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆品牌，参考数据字典，可以不填，默认为空，表示所有品牌 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典，可以不填，默认为空，表示所有类型 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典，可以不填，默认为空，表示所有颜色 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 布控单位编码，必须填写 */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 布控人员编码，必须填写 */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** 布控优先级，取值范围为1-63，1表示最高，默认为2 */
    ULONG_32 ulPriority;

    /** 布控性质, 0-秘密;1-公开，目前仅支持公开，填1 */
    ULONG_32 ulOpenFlag;

    /** 布控类别，参考数据字典，必须填写 */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** 布控照片(形如ftp://用户名:密码@192.168.10.1/tollgate/abc.jpg)，必须先通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper获取FTP参数 */
    CHAR  szDispositionImage[IMOS_FILE_PATH_LEN];

    /** 添加布控车辆名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 布控开始时间，必须填写 */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** 布控结束时间，必须填写 */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 布控状态，参考#DISPOSITION_STATUS_E，查询返回，入参可不填 */
    ULONG_32 ulStatus;

    /** 布控扩展状态，参考#DISPOSITION_EXT_STATUS_E，查询返回，入参可不填 */
    ULONG_32 ulExtStatus;

    /** 案件描述，可以不填 */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** 布控后处理意见，可以不填 */
    CHAR  szActionDesc[IMOS_DESC_LEN];

    /** 短信关联号码 (支持256个号码)*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];

    /** 域编码 (布控暂停、继续专用)*/
    CHAR szDomainCode[IMOS_CODE_LEN];

    /** 布控计划是否启动 */
    ULONG_32 ulDisposePlanStatus;

    /** 预留字段 */
    CHAR szReserve[140];

    /** 撤控信息 */
    STATEMENT_DISPOSITION_UNDO_INFO_S stUndoInfo;

    /* 新加：审核意见 */
    CHAR szAuditRemark[IMOS_STRING_LEN_512];

    /* 布控名称，可不填 */
    CHAR szDispositionName[IMOS_NAME_LEN];
} STATEMENT_DISPOSITION_INFO_S;

/*Begin added by a02842 for MPPD46586,2017-4-11*/
/**
 * @struct tagStatementDispositionInfoV2
 * @brief 布控信息结构
 * @attention
 */
typedef struct tagStatementDispositionInfoV2
{

    /** 布控编号，系统自动生成 */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** 互联布控类型，参考#DISPOSITION_INTER_TYPE_E */
    ULONG_32 ulInterType;

    /** 是否模糊匹配，BOOL_TRUE: 模糊匹配，BOOL_FALSE: 精确匹配 */
    BOOL_T bFuzzyMatch;

    /** 号牌号码，必须填写 */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典，可以不填，默认为空，表示所有种类 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆品牌，参考数据字典，可以不填，默认为空，表示所有品牌 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典，可以不填，默认为空，表示所有类型 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典，可以不填，默认为空，表示所有颜色 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 布控单位编码，必须填写 */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 布控人员编码，必须填写 */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** 布控优先级，取值范围为1-63，1表示最高，默认为2 */
    ULONG_32 ulPriority;

    /** 布控性质, 0-秘密;1-公开，目前仅支持公开，填1 */
    ULONG_32 ulOpenFlag;

    /** 布控类别，参考数据字典，必须填写 */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** 布控照片(形如ftp://用户名:密码@192.168.10.1/tollgate/abc.jpg)，必须先通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper获取FTP参数 */
    CHAR  szDispositionImage[IMOS_FILE_PATH_LEN];

    /** 添加布控车辆名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 布控开始时间，必须填写 */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** 布控结束时间，必须填写 */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 布控状态，参考#DISPOSITION_STATUS_E，查询返回，入参可不填 */
    ULONG_32 ulStatus;

    /** 布控扩展状态，参考#DISPOSITION_EXT_STATUS_E，查询返回，入参可不填 */
    ULONG_32 ulExtStatus;

    /** 案件描述，可以不填 */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** 布控后处理意见，可以不填 */
    CHAR  szActionDesc[IMOS_DESC_LEN];

    /** 短信关联号码 (支持256个号码)*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];

    /** 域编码 (布控暂停、继续专用)*/
    CHAR szDomainCode[IMOS_CODE_LEN];

    /** 布控计划是否启动 */
    ULONG_32 ulDisposePlanStatus;
    
    /** 预留字段 */
    CHAR szReserve[140];

    /** 撤控信息 */
    STATEMENT_DISPOSITION_UNDO_INFO_S stUndoInfo;
	
    /* 新加：审核意见 */
    CHAR szAuditRemark[IMOS_STRING_LEN_512];

    /* 布控名称，可不填 */
    CHAR szDispositionName[IMOS_NAME_LEN];
    /***********************************布控权限问题*****************************************/
    /**布控广播模式0:广播(可访问用户列表无效)， 1:单播或组播*/
    ULONG_32 ulBroadcastMode;

    /**布控用户编码()*/
    CHAR szAddUsrCode[IMOS_CODE_LEN];

    /**可访问用户列表,暂时支持64 个31位
    用户编码组成的字符串，用逗号连接*/
    CHAR szAccessUsrList[IMOS_STRING_LEN_2048];

    /**预留位*/
    CHAR szReserve1[8192];
} STATEMENT_DISPOSITION_INFO_V2_S;
/*End added by a02842 for MPPD46586,2017-4-11*/

/**
* @struct tagStatementDispositionDomain
* @brief 布控域信息
* @attention
*/
typedef struct tagStatementDispositionDomain
{
    /** 域编码 */
    CHAR  szDomainCode[IMOS_CODE_LEN];

    /** 域名称 */
    CHAR  szDomainName[IMOS_NAME_LEN];

    /** 布控状态，参考#DISPOSITION_STATUS_E */
    ULONG_32 ulStatus;

    /** 处理结果，参考#DISPOSITION_RESULT_E */
    ULONG_32 ulResult;
} STATEMENT_DISPOSITION_DOMAIN_S;

/**
* @struct tagMapAreaDisposeResInfo
* @brief 地图防区布控资源信息
* @attention
*/
typedef struct tagMapAreaDisposeResInfo
{
    /** 地图防区布控资源数量 */
    ULONG_32 ulDisposeResNum;

    /** 地图防区布控资源列表 */
    RES_INFO_S astDisposeResList[IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM];
} MAP_AREA_DISPOSE_RES_INFO_S;

/**
 * @struct tagDisposePlanBase
 * @brief 布控计划基本信息
 * @attention
 */
typedef struct tagDisposePlanBase
{
    /** 布控计划创建日期 */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** 计划状态，BOOL_TRUE:启动; BOOL_FALSE:停止 */
    ULONG_32    ulPlanStatus;

    /** 计划类型, 取值为#PLAN_TYPE_E */
    ULONG_32    ulPlanType;

    /** 计划描述, 可不填 */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}DISPOSE_PLAN_BASE_S;

/**
 * @struct tagDisposePlanInfo
 * @brief 布控计划信息
 * @attention
 */
typedef struct tagDisposePlanInfo
{
    /** 布控计划基本信息 */
    DISPOSE_PLAN_BASE_S stDisposeBaseInfo;

    /** 布控计划时间信息 */
    PLAN_TIME_FOR_RES_S stDisposeTimeInfo;
}DISPOSE_PLAN_INFO_S;

/**
 * @struct tagVehicleBlacklist
 * @brief 黑名单结构
 * @attention
 */
typedef struct tagVehicleBlacklist
{
    /** 黑名单编号，自动生成 */
    CHAR  szBlacklistCode[IMOS_CODE_LEN];

    /** 是否模糊匹配，BOOL_TRUE: 模糊匹配，BOOL_FALSE: 精确匹配，目前仅支持精确匹配，填BOOL_FALSE */
    BOOL_T bFuzzyMatch;

    /** 号牌号码 */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典，可以不填，默认为空，表示所有种类 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 录入部门编码，可以为空 */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 录入人编码，可以为空 */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** 黑名单来源，参考BLACKLIST_SRC_E */
    ULONG_32 ulSource;

    /** 布控优先级，取值范围为1-63，1表示最高，默认为3 */
    ULONG_32 ulPriority;

    /** 黑名单原因，暂不使用，填空 */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** 添加黑名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 布控开始时间，可以为空 */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** 布控结束时间，可以为空 */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 拦截说明，可以不填 */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;
} VEHICLE_BLACKLIST_S;

/**
 * @struct tagDictionaryData
 * @brief 数据字典结构
 * @attention
 */
typedef struct tagDictionaryData
{

    /** 数据字典编码 */
    CHAR  szDataCode[IMOS_DICTIONARY_KEY_LEN];

    /** 数据字典名称 */
    CHAR  szDataName[IMOS_NAME_LEN];

    /** 是否系统预定义项，系统预定义项不允许删除和修改，BOOL_TRUE:系统预定义，BOOL_FALSE:非系统预定义 */
    BOOL_T bPreDefined;

} DICTIONARY_DATA_S;

/**
 * @struct tagDictionaryDatav2
 * @brief 数据字典结构 支持42个中文字符
 * @attention
 */
typedef struct tagDictionaryDatav2
{

    /** 数据字典编码 */
    CHAR  szDataCode[IMOS_DICTIONARY_KEY_LEN];

    /** 数据字典名称 */
    CHAR  szDataName[IMOS_STRING_LEN_128];

    /** 是否系统预定义项，系统预定义项不允许删除和修改，BOOL_TRUE:系统预定义，BOOL_FALSE:非系统预定义 */
    BOOL_T bPreDefined;

} DICTIONARY_DATAV2_S;

/**
 * @struct tagStoreResBasicInfo
 * @brief 存储资源基本信息
 * @attention
 */
typedef struct tagStoreResBasicInfo
{

    /** 存储资源编码，自动生成，创建时填空 */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** 存储资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 设备编码 */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** 存储类型, 取值为#AS_DEVCM_STORAGE_TYPE_E */
    ULONG_32  ulStorageType;

    /** 存储设备编码，存储类型为STORAGE_TYPE_LOCAL(本地存储)时填空 */
    CHAR   szStoreDevCode[IMOS_CODE_LEN];

    /** 资源用途, 取值为#STORAGE_RES_USAGE_E */
    ULONG_32  ulResUsage;

    /** 指定存储设备空间不足时,是否支持自动选择存储设备(BOOL_TRUE为支持; BOOL_FALSE为不支持)，目前为BOOL_FALSE */
    BOOL_T bAutoSelectStoreDev;

    /** 磁盘满处理策略，取值为#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32  ulDiskFullPolicy;

    /** 分配存储空间，单位:MB */
    ULONG_32  ulStoreCapacity;

    /** 资源全路径，存储类型为STORAGE_TYPE_LOCAL(本地存储)时需要填写，其余填空 */
    CHAR szResPath[IMOS_FILE_PATH_LEN];

    /** 以下结构用于添加第三方资源时使用 */
    /** LUN ID */
    ULONG_32 ulLunId;

    /** Target名 */
    CHAR szTarget[IMOS_STRING_LEN_256];

    /** Initiator名 */
    CHAR szInitiator[IMOS_STRING_LEN_256];

    /** IPSAN设备地址 */
    CHAR szDevAddress[IMOS_IPADDR_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

}STORE_RES_BASIC_INFO_S;

/**
 * @struct tagStoreResBasicQueryItem
 * @brief 存储资源查询返回Item
 * @attention
 */
typedef struct tagStoreResBasicQueryItem
{

    /** 存储资源编码 */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** 存储资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 设备编码 */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 存储类型, 参考#AS_DEVCM_STORAGE_TYPE_E */
    ULONG_32  ulStorageType;

    /** 存储设备编码 */
    CHAR   szStoreDevCode[IMOS_CODE_LEN];

    /** 存储设备名称 */
    CHAR   szStoreDevName[IMOS_NAME_LEN];

    /** 存储设备类型, 参考#STORE_DEV_TYPE_E */
    ULONG_32  ulStoreDevType;

    /** 存储设备子类型, 目前暂不使用 */
    ULONG_32  ulStoreDevSubType;

    /** 资源用途, 取值为#STORAGE_RES_USAGE_E */
    ULONG_32  ulResUsage;

    /** 磁盘满处理策略，参考#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32  ulDiskFullPolicy;

    /** 资源状态，参考#BAK_RES_STATUS_E */
    ULONG_32 ulResStatus;

    /** 总容量，单位:MB */
    ULONG_32  ulTotalCapacity;

    /** 剩余容量，单位:MB */
    ULONG_32  ulFreeCapacity;

    /** 资源全路径 */
    CHAR  szResPath[IMOS_FILE_PATH_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

}STORE_RES_BASIC_QUERY_ITEM_S;

/**
 * @struct tagGisMapBaseIcon
 * @brief GIS图标基本信息
 * @attention
 */
typedef struct tagGisMapBaseIcon
{

    /** 图标编码，自动生成 */
    CHAR szIconCode[IMOS_CODE_LEN];

    /** 地图编码 */
    CHAR szGISMapCode[IMOS_CODE_LEN];

    /** 资源编码 */
    CHAR szResCode[IMOS_CODE_LEN];

    /** 图标类型，参考#IMOS_TYPE_E，目前仅支持IMOS_TYPE_TOLLGATE */
    ULONG_32 ulIconType;

    /** 位置信息描述 */
    CHAR szSiteDesc[IMOS_STRING_LEN_32];

} GIS_MAP_BASE_ICON_S;


/**
 * @struct tagGisMapIcon
 * @brief GIS图标信息
 * @attention
 */
typedef struct tagGisMapIcon
{
    /** 图标基本信息 */
    GIS_MAP_BASE_ICON_S stBaseIcon;

    /** 资源名称 */
    CHAR szResName[IMOS_NAME_LEN];

    /** 资源类型 */
    ULONG_32 ulResType;

    /** 资源子类型 */
    ULONG_32 ulResSubType;

    /** 资源状态 */
    ULONG_32 ulResState;

    /** 资源额外状态 */
    ULONG_32 ulResExtState;

    /** 是否外域 */
    ULONG_32 ulIsForeign;

    /** 告警严重程度, 取值为#ALARM_SEVERITY_LEVEL_E，预留 */
    ULONG_32 ulCamAlarmLevel;

}GIS_MAP_ICON_S;


/**
* @struct tagQueryVehicleDayStatByType
* @brief 按日分车辆类型统计
* @attention
*/
typedef struct tagQueryVehicleDayStatByType
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计日期 */
    CHAR szStatDate[IMOS_SIMPLE_DATE_LEN];

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 平均速度 */
    ULONG_32 ulAvgSpeed;

    /** 根据类型统计的流量 */
    ULONG_32 aulCountByType[IMOS_MAX_VEHICLE_TYPE_NUM];
} QUERY_VEHICLE_DAY_STAT_BY_TYPE_S;


/**
* @struct tagQueryVehicleDayStatByDir
* @brief 按日分车道方向统计
* @attention
*/
typedef struct tagQueryVehicleDayStatByDir
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计日期 */
    CHAR szStatDate[IMOS_SIMPLE_DATE_LEN];

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 平均速度 */
    ULONG_32 ulAvgSpeed;

    /** 根据方向统计的流量 */
    ULONG_32 aulCountByDir[IMOS_MAX_LANE_DIRECTION_NUM];
} QUERY_VEHICLE_DAY_STAT_BY_DIR_S;


/**
* @struct tagQueryVehicleDayStatByLane
* @brief 按日分车道统计
* @attention
*/
typedef struct tagQueryVehicleDayStatByLane
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计日期 */
    CHAR szStatDate[IMOS_SIMPLE_DATE_LEN];

    /** 车道号 */
    ULONG_32 ulLaneNumber;

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 平均速度 */
    ULONG_32 ulAvgSpeed;

} QUERY_VEHICLE_DAY_STAT_BY_LANE_S;





/**
* @struct tagQueryVehicleHourStatByType
* @brief 按小时分车辆类型统计
* @attention
*/
typedef struct tagQueryVehicleHourStatByType
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计时间 */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 平均速度 */
    ULONG_32 ulAvgSpeed;

    /** 根据类型统计的流量 */
    ULONG_32 aulCountByType[IMOS_MAX_VEHICLE_TYPE_NUM];
} QUERY_VEHICLE_HOUR_STAT_BY_TYPE_S;


/**
* @struct tagQueryVehicleHourStatByDir
* @brief 按小时分车道方向统计
* @attention
*/
typedef struct tagQueryVehicleHourStatByDir
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计时间 */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 平均速度 */
    ULONG_32 ulAvgSpeed;

    /** 根据方向统计的流量 */
    ULONG_32 aulCountByDir[IMOS_MAX_LANE_DIRECTION_NUM];
} QUERY_VEHICLE_HOUR_STAT_BY_DIR_S;


/**
* @struct tagQueryVehicleHourStatByLane
* @brief 按小时分车道统计
* @attention
*/
typedef struct tagQueryVehicleHourStatByLane
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计时间 */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** 车道号 */
    ULONG_32 ulLaneNumber;

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 平均速度 */
    ULONG_32 ulAvgSpeed;

} QUERY_VEHICLE_HOUR_STAT_BY_LANE_S;

/**
 * @struct tagTollgateVideoCameraBindInfo
 * @brief 卡口摄像机绑定信息
 * @attention
 */
typedef struct tagTollgateVideoCameraBindInfo
{
    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** 所属卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 抓拍的卡口车道数量 */
    ULONG_32 ulPhotoLaneNum;

    /** 抓拍的卡口车道列表 */
    ULONG_32 aulPhotoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** 监控的卡口车道数量 */
    ULONG_32 ulVideoLaneNum;

    /** 监控的卡口车道列表 */
    ULONG_32 aulVideoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** 采集设备类型 */
    CHAR  szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段 */
    CHAR szReserve[196];
} TOLLGATE_VIDEO_CAMERA_BIND_INFO_S;

/**
 * @struct tagTollgateVideoCameraQueryItem
 * @brief 卡口摄像机查询信息
 * @attention
 */
typedef struct tagTollgateVideoCameraQueryItem
{
    /** 全景摄像机编码 */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** 全景摄像机名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 全景摄像机类型，参考#CAMERA_TYPE_E */
    ULONG_32 ulCameraType;

    /** 所属卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 所属卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 抓拍的卡口车道数量 */
    ULONG_32 ulPhotoLaneNum;

    /** 抓拍的卡口车道列表 */
    ULONG_32 aulPhotoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** 监控的卡口车道数量 */
    ULONG_32 ulVideoLaneNum;

    /** 监控的卡口车道列表 */
    ULONG_32 aulVideoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 全景摄像机描述, 暂不使用，填空 */
    CHAR  szCameraDesc[IMOS_DESC_LEN];

    /** 资源是否属于外域 */
    ULONG_32   ulIsForeign;

    /** 采集设备类型 */
    CHAR  szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段 */
    CHAR szReserve[196];
} TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S;


/**
 * @struct tagVehicleWhitelist
 * @brief 白名单结构
 * @attention
 */
typedef struct tagVehicleWhitelist
{
    /** 白名单编号，自动生成 */
    CHAR  szWhitelistCode[IMOS_CODE_LEN];

    /** 号牌号码 */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典，可以不填，默认为空，表示所有种类 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 录入部门编码，可以为空 */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 录入人编码，可以为空 */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** 添加白名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 白名单描述 */
    CHAR  szWhiteListDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;
} VEHICLE_WHITELIST_S;

/*added by a02842 for whitelist extension,2017-02-23*/
/**
 * @struct tagVehicleWhitelist
 * @brief 白名单结构
 * @attention
 */
typedef struct tagVehicleWhitelistV2
{
    /** 白名单编号，自动生成 */
    CHAR  szWhitelistCode[IMOS_CODE_LEN];

    /** 号牌号码 */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典，可以不填，默认为空，表示所有种类 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 录入部门编码，可以为空 */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 录入人编码，可以为空 */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** 添加白名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 白名单描述 */
    CHAR  szWhiteListDesc[IMOS_DESC_LEN];

    /**----------------白名单扩展功能参数------------------*/
    /** 是否模糊匹配 */
    BOOL_T bFuzzyMatch;

    /** 白名单是否为临时状态0:永久1:临时*/
    BOOL_T bTempStatus;

    /** 白名单是否配置查询区域0:不配置区域1:配置区域(tbl_vehicle_whitelist)*/
    BOOL_T bRegionStatus;
    
    /** 白名单状态*/
    ULONG_32 ulWhiteListStatus;
	
    /** 布控开始时间 */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** 布控结束时间 */
    CHAR  szEndTime[IMOS_TIME_LEN];    

    /** 告警类型编码列表，最大支持50种违法类型，为空表示无限制*/
    CHAR  szAlarmTypeCodeList[IMOS_WHITELIST_ALARMTYPE_LEN];

    /*Begin added by h03869, Sep 07, 2017 for MPPD51033*/
    /** 短信接收号码*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];
    /*End added by h03869, Sep 07, 2017 for MPPD51033*/
    
    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;
} VEHICLE_WHITELIST_V2_S;

/**
 * @struct tagVehiclePlate
 * @brief 名单结构
 * @attention
 */
typedef struct tagVehiclePlate
{
    /** 名单编号，自动生成 */
    CHAR  szPlateCode[IMOS_CODE_LEN];

    /** 号牌号码 */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典，可以不填，默认为空，表示所有种类 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 录入部门编码，可以为空 */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 录入人编码，可以为空 */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** 添加名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 名单描述 */
    CHAR  szPlateDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[256];
} VEHICLE_PLATE_S;

/**
 * @struct tagTollgateLocalRes
 * @brief 卡口本地存储资源
 * @attention
 */
typedef struct tagTollgateLocalRes
{
    /** 资源路径 */
    CHAR szResPath[IMOS_FILE_PATH_LEN];

    /** 磁盘设备号 */
    CHAR szDiskName[IMOS_FILE_PATH_LEN];
} TOLLGATE_LOCAL_RES_S;

/**
* @struct tagPlateAnalyseResult
* @brief 套牌分析结果
* @attention
*/
typedef struct tagPlateAnalyseResult
{
    /** 结果编号 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车辆行驶记录 */
    VEHICLE_DATA_S stVehicleData;

} PLATE_ANALYSE_RESULT_S;

/**
* @struct tagPlateAnalyseInfo
* @brief 套牌分析信息
* @attention
*/
typedef struct tagPlateAnalyseInfo
{
    /** 套牌分析编号 */
    CHAR szPlateAnalyseCode[IMOS_CODE_LEN];

    /** 开始时间 */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** 卡口组编码1 */
    CHAR szTollgateGroupCode1[IMOS_CODE_LEN];

    /** 卡口组名称1 */
    CHAR szTollgateGroupName1[IMOS_NAME_LEN];

    /** 卡口组编码2 */
    CHAR szTollgateGroupCode2[IMOS_CODE_LEN];

    /** 卡口组名称2 */
    CHAR szTollgateGroupName2[IMOS_NAME_LEN];

    /** 是否启用相同号牌不同车辆颜色,1为启用; 0为不启用 */
    ULONG_32 ulDiffVehicleColorEnabled;

    /** 是否启用相同号牌不同车辆类型,1为启用; 0为不启用 */
    ULONG_32 ulDiffVehicleTypeEnabled;

    /** 是否启用相同号牌极短时间通过不同卡口组,1为启用; 0为不启用 */
    ULONG_32 ulCuttyTimeDiffTollgateEnabled;

    /** 同一辆车在两个卡口组之间的最小时间间隔，单位秒 */
    ULONG_32 ulTGTimePeriod;

    /** 分析状态 */
    ULONG_32 ulAnalyseStatus;

    /** 预留字段 */
    CHAR  szReserved[32];

} PLATE_ANALYSE_INFO_S;

/**
* @struct tagVehiclePhotoStorSlice
* @brief 留存期配置
* @attention
*/
typedef struct tagVehiclePhotoStorSlice
{
    /** 时间段 */
    TIME_SLICE_S stSlice;

    /** 比例 */
    ULONG_32 ulProportion;
} VEHICLE_PHOTO_STOR_SLICE_S;

/**
* @struct tagTollgateStorCycle
* @brief 卡口存储周期
* @attention
*/
typedef struct tagTollgateStorCycle
{
    /** 过车记录保存天数 */
    ULONG_32 ulVehicleDataStorDay;

    /** 过车告警保存天数 */
    ULONG_32 ulVehicleAlarmStorDay;

    /** 过车记录开始清理百分比0-100 */
    ULONG_32 ulVehicleDataClearPercent;

    /** 过车记录停止清理百分比0-100 */
    ULONG_32 ulVehicleDataStopPercent;

    /** 过车告警开始清理百分比0-100 */
    ULONG_32 ulVehicleAlarmClearPercent;

    /** 过车告警停止清理百分比0-100 */
    ULONG_32 ulVehicleAlarmStopPercent;

    /** 留存期数量 */
    ULONG_32 ulPhotoStorSliceNum;

    /** 留存期列表 */
    VEHICLE_PHOTO_STOR_SLICE_S astPhotoStorSliceList[IMOS_MAX_TOLLGATE_PHOTO_STOR_SLICE_NUM];

	/* Begin added by c02845,2016-03-28,卡口云直存 */	
    /** 卡口直存共享过车图片所点总数比例 0-100 */
    ULONG_32 ulCDSVehicleCapPercent;

    /** 卡口直存共享告警图片所点总数比例 0-100 */
    ULONG_32 ulCDSAlarmCapPercent;

    /** 卡口直存过车记录开始清理百分比0-100 */
    ULONG_32 ulCDSVehicleDataClearPercent;

    /** 卡口直存过车记录停止清理百分比0-100 */
    ULONG_32 ulCDSVehicleDataStopPercent;

    /** 卡口直存过车告警开始清理百分比0-100 */
    ULONG_32 ulCDSVehicleAlarmClearPercent;

    /** 卡口直存过车告警停止清理百分比0-100 */
    ULONG_32 ulCDSVehicleAlarmStopPercent;
	/* End added by c02845,2016-03-28,卡口云直存 */

    /** 卡口直存过车图片留存天数 */
    ULONG_32 ulCDSVehiclePicStorDay;

    /** 卡口直存过车告警图片留存天数 */
    ULONG_32 ulCDSVehicleAlarmPicStorDay;
} TOLLGATE_STOR_CYCLE_S;

/**
* @struct tagTollgatePhotoLifeCycle
* @brief 过车图片生命周期
* @attention
*/
typedef struct tagTollgatePhotoLifeCycle
{
    /** 是否启用，BOOL_TRUE：启用；BOOL_FALSE：不启用 */
    ULONG_32 ulEnableStatus;

    /** 起始天数 */
    ULONG_32 ulBeginDay;

    /** 截止天数 */
    ULONG_32 ulEndDay;

    /** 压缩百分比0～100 */
    ULONG_32 ulCompressPercent;

} TOLLGATE_PHOTO_LIFE_CYCLE_S;

/**
* @struct tagTollgatePhotoLifeCycleCfg
* @brief 过车图片生命周期配置
* @attention
*/
typedef struct tagTollgatePhotoLifeCycleCfg
{
    /** 过车图片生命周期数量 */
    ULONG_32 ulPhotoLifeCycleNum;

    /** 过车图片生命周期列表 */
    TOLLGATE_PHOTO_LIFE_CYCLE_S astPhotoLifeCycleList[IMOS_MAX_TOLLGATE_PHOTO_LIFT_CYCLE_NUM];

} TOLLGATE_PHOTO_LIFE_CYCLE_CFG_S;

/**
* @struct tagDetectionRoadSection
* @brief 测速区间
* @attention
*/
typedef struct tagDetectionRoadSection
{
    /** 区间编号 */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** 区间名称 */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** 卡口编号（驶入） */
    CHAR szInTollgateCode[IMOS_CODE_LEN];

    /** 卡口编号（驶出） */
    CHAR szOutTollgateCode[IMOS_CODE_LEN];

    /** 区间距离，单位:米 */
    ULONG_32 ulSectionDistance;

    /** 大车限速（高速），单位：Km/h */
    ULONG_32 ulLargeVehicleUpperSpeed;

    /** 大车限速（低速），单位：Km/h */
    ULONG_32 ulLargeVehicleLowerSpeed;

    /** 小车限速（高速），单位：Km/h */
    ULONG_32 ulSmallVehicleUpperSpeed;

    /** 小车限速（高速），单位：Km/h */
    ULONG_32 ulSmallVehicleLowerSpeed;

    /* Begin added by c02845, 2015-11-05, of MPPD31387, 增加区间超时违法 */
    /** 车辆在区间内的允许停留时间，单位秒 */
    ULONG_32 ulSectionTime;
    /* End added by c02845, 2015-11-05, of MPPD31387, 增加区间超时违法 */

    /** 区间描述 */
    CHAR szSectionDesc[IMOS_DESC_LEN];

} DETECTION_ROAD_SECTION_S;

/**
* @struct tagDetectionRoadSectionQueryItem
* @brief 测速区间查询Item
* @attention
*/
typedef struct tagDetectionRoadSectionQueryItem
{
    /** 区间编号 */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** 区间名称 */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** 卡口编号（驶入） */
    CHAR szInTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称（驶入） */
    CHAR szInTollgateName[IMOS_NAME_LEN];

    /** 卡口编号（驶出） */
    CHAR szOutTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称（驶出） */
    CHAR szOutTollgateName[IMOS_NAME_LEN];

    /** 区间距离，单位:米 */
    ULONG_32 ulSectionDistance;

    /** 大车限速（高速），单位：Km/h */
    ULONG_32 ulLargeVehicleUpperSpeed;

    /** 大车限速（低速），单位：Km/h */
    ULONG_32 ulLargeVehicleLowerSpeed;

    /** 小车限速（高速），单位：Km/h */
    ULONG_32 ulSmallVehicleUpperSpeed;

    /** 小车限速（高速），单位：Km/h */
    ULONG_32 ulSmallVehicleLowerSpeed;

    /* Begin added by c02845, 2015-11-05, of 增加区间超时违法 */
    /** 车辆在区间内的允许停留时间，单位秒 */
    ULONG_32 ulSectionTime;
    /* End added by  c02845, 2015-10-12 of 增加区间超时违法*/

    /** 区间描述 */
    CHAR szSectionDesc[IMOS_DESC_LEN];

} DETECTION_ROAD_SECTION_QUERY_ITEM_S;

/**
* @struct tagVehicleViolationTypeCount
* @brief 车辆类型和数量的对应关系
* @attention
*/
typedef struct tagVehicleViolationTypeCount
{

    /* 车辆类型 */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /* 数量 */
    ULONG_32 ulCount;

} VEHICLE_VIOLATION_TYPE_COUNT_S;

/**
* @struct tagVehicleViolationStatByType
* @brief 按违章类型统计结果
* @attention
*/
typedef struct tagVehicleViolationStatByType
{

    /** 违章类型 */
    CHAR szViolationType[IMOS_DICTIONARY_KEY_LEN];

    /** 违章类型名称 */
    CHAR szViolationName[IMOS_NAME_LEN];

    /** 总计 */
    ULONG_32 ulTotalCount;

    /** 车辆类型数量 */
    ULONG_32 ulTypeCountNum;

    /** 对应违章类型的各种车辆类型的违章数量统计结果 */
    VEHICLE_VIOLATION_TYPE_COUNT_S astTypeCountList[IMOS_VEHICLE_TYPE_MAX_NUM];

} VEHICLE_VIOLATION_STAT_BY_TYPE_S;

/**
* @struct tagViolationStatByTollgateItem
* @brief 根据违章类型统计的违章数量
* @attention
*/
typedef struct tagViolationStatByTollgateItem
{
    /** 违章类型 */
    CHAR szViolationType[IMOS_DICTIONARY_KEY_LEN];

    /** 违章数量 */
    ULONG_32 ulViolationCount;

} VIOLATION_STAT_BY_TOLLGATE_ITEM_S;

/**
* @struct tagVehicleViolationStatByTollgate
* @brief 按卡口统计结果
* @attention
*/
typedef struct tagVehicleViolationStatByTollgate
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 总计 */
    ULONG_32 ulTotalCount;

    /** 违章类型数量 */
    ULONG_32 ulViolationNum;

    /** 根据违章类型统计的违章数量列表 */
    VIOLATION_STAT_BY_TOLLGATE_ITEM_S astViolationList[IMOS_VEHICLE_VIOLATION_MAX_NUM];

} VEHICLE_VIOLATION_STAT_BY_TOLLGATE_S;

/**
* @struct tagVehicleViolationStatByDealStatus
* @brief 按处理状态统计结果
* @attention
*/
typedef struct tagVehicleViolationStatByDealStatus
{
    /** 处理状态 */
    ULONG_32 ulDealStatus;

    /** 违章数量 */
    ULONG_32 ulCount;

    /** 百分比，9999表示99.99% */
    ULONG_32 ulPercent;

} VEHICLE_VIOLATION_STAT_BY_DEAL_STATUS_S;

/**
* @struct tagTMSForwardAddrInfo
* @brief TMS转发地址
* @attention
*/
typedef struct tagTMSForwardAddrInfo
{
    /** 转发地址编号 */
    CHAR  szForwardAddrCode[IMOS_CODE_LEN];

    /** TMS编码 */
    CHAR  szTMSCode[IMOS_CODE_LEN];

    /** 转发地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulForwardAddrType;

    /** 转发地址 */
    CHAR  szForwardAddr[IMOS_IPADDR_LEN];

    /** 转发端口 */
    ULONG_32 ulForwardPort;

    /** 链路状态 */
    ULONG_32 ulLinkStatus;

} TMS_FORWARD_ADDR_INFO_S;

/**
 * @struct tagViolationPlace
 * @brief 违章地点
 * @attention
 */
typedef struct tagViolationPlace
{
    /** 地点编号 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** 地点名称 */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** 行政区划 */
    CHAR szAdminDivision[IMOS_CODE_LEN];

    /** 道路代号 */
    CHAR szRoadCode[IMOS_CODE_LEN];

    /** 公路里程桩号 */
    CHAR szKilometer[IMOS_MEASUREMENT_LEN];

    /** 米数 */
    CHAR szMeter[IMOS_MEASUREMENT_LEN];

    /** 地点描述 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VIOLATION_PLACE_S;

/**
 * @struct tagDevAddr
 * @brief 设备地址
 * @attention
 */
typedef struct tagDevAddr
{
    /** 地址编号 */
    CHAR szDevAddrCode[IMOS_CODE_LEN];

    /** 设备编码 */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** 地址类型 */
    ULONG_32 ulAddrType;

    /** 地址 */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** 端口号 */
    ULONG_32 ulPort;

    /** 预留字段 */
    CHAR szReserve[128];
} DEV_ADDR_S;

/**
* @struct tagVehicleAbnormalAnalyseInfo
* @brief 异常行为分析信息
* @attention
*/
typedef struct tagVehicleAbnormalAnalyseInfo
{
    /** 异常行为分析编号 */
    CHAR szAbnormalAnalyseCode[IMOS_CODE_LEN];

    /** 开始时间 */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** 通过次数阀值 */
    ULONG_32 ulMaxPassCount;

    /** 分析状态，见VEHICLE_ABNORMAL_ANALYSE_STATUS_E */
    ULONG_32 ulAnalyseStatus;

    /** 操作符，见VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulOperator;

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_ABNORMAL_ANALYSE_INFO_S;

/**
* @struct tagVehicleAbnormalAnalyseResult
* @brief 异常行为分析结果
* @attention
*/
typedef struct tagVehicleAbnormalAnalyseResult
{
    /** 结果编号 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车牌号码 */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 通过次数 */
    ULONG_32 ulPassCount;

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_ABNORMAL_ANALYSE_RESULT_S;

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/**
* @struct tagVehicleTrackCollisionInfo
* @brief 车辆轨迹碰撞信息
* @attention
*/
typedef struct tagVehicleTrackCollisionInfo
{
    /** 资源数量 */
    ULONG_32 ulResNum;

    /** 资源列表 */
    RES_INFO_S astResList[IMOS_VEHICLE_TRACK_COLLISION_RES_MAX_NUM];

    /** 开始时间 */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR szEndTime[IMOS_TIME_LEN];
} VEHICLE_TRACK_COLLISION_INFO_S;

/**
* @struct tagVehicleTrackCollisionDetail
* @brief 车辆轨迹碰撞详细信息
* @attention
*/
typedef struct tagVehicleTrackCollisionDetail
{
    /** 车辆轨迹碰撞编号 */
    CHAR szTrackCollisionCode[IMOS_CODE_LEN];

    /** 车辆轨迹碰撞名称 */
    CHAR szTrackCollisionName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 车辆轨迹数量 */
    ULONG_32 ulVehicleTrackNum;

    /** 车辆轨迹信息 */
    VEHICLE_TRACK_COLLISION_INFO_S astVehicleTrackList[IMOS_VEHICLE_TRACK_PLACE_MAX_NUM];

    /** 分析状态，见VEHICLE_TRACK_COLLISION_STATUS_E */
    ULONG_32 ulStatus;

    /** 备注 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_TRACK_COLLISION_DETAIL_S;

/**
* @struct tagVehicleTrackCollisionQueryItem
* @brief 车辆轨迹碰撞
* @attention
*/
typedef struct tagVehicleTrackCollisionQueryItem
{
    /** 车辆轨迹碰撞编号 */
    CHAR szTrackCollisionCode[IMOS_CODE_LEN];

    /** 车辆轨迹碰撞名称 */
    CHAR szTrackCollisionName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 分析状态，见VEHICLE_TRACK_COLLISION_STATUS_E */
    ULONG_32 ulStatus;

    /** 备注 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 轨迹碰撞最小时间 */
    CHAR szTrackCollisionMinTime[IMOS_TIME_LEN];

    /** 轨迹碰撞最大时间 */
    CHAR szTrackCollisionMaxTime[IMOS_TIME_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_TRACK_COLLISION_QUERY_ITEM_S;

/**
* @struct tagVehicleTrackCollisionResult
* @brief 车辆轨迹碰撞结果
* @attention
*/
typedef struct tagVehicleTrackCollisionResult
{
    /** 结果编码 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车辆信息编号 */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 行驶方向，参考数据字典 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌颜色，参考数据字典 */
    CHAR szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色，参考数据字典 */
    CHAR szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车速 */
    ULONG_32 ulVehicleSpeed;

    /** 通过卡口时间 */
    CHAR szPassTime[IMOS_TIME_LEN];

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_TRACK_COLLISION_RESULT_S;

/**
* @struct tagVehicleFirstAppearInfo
* @brief 车辆首次出现信息
* @attention
*/
typedef struct tagVehicleFirstAppearInfo
{
    /** 车辆首次出现编号 */
    CHAR szFirstAppearCode[IMOS_CODE_LEN];

    /** 车辆首次出现名称 */
    CHAR szFirstAppearName[IMOS_NAME_LEN];

    /** 资源数量 */
    ULONG_32 ulResNum;

    /** 资源列表 */
    RES_INFO_S astResList[IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM];

    /** 开始时间 */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** 分析状态，见VEHICLE_FIRST_APPEAR_STATUS_E */
    ULONG_32 ulStatus;

    /** 备注 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_FIRST_APPEAR_INFO_S;

/**
* @struct tagVehicleFirstAppearResult
* @brief 车辆首次出现结果
* @attention
*/
typedef struct tagVehicleFirstAppearResult
{
    /** 结果编码 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车辆信息编号 */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 行驶方向，参考数据字典 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌颜色，参考数据字典 */
    CHAR szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色，参考数据字典 */
    CHAR szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车速 */
    ULONG_32 ulVehicleSpeed;

    /** 通过卡口时间 */
    CHAR szPassTime[IMOS_TIME_LEN];

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_FIRST_APPEAR_RESULT_S;

/**
* @struct tagVehiclePerilTimeInfo
* @brief 车辆高危时段信息
* @attention
*/
typedef struct tagVehiclePerilTimeInfo
{
    /** 车辆高危时段编号 */
    CHAR szPerilTimeCode[IMOS_CODE_LEN];

    /** 车辆高危时段名称 */
    CHAR szPerilTimeName[IMOS_NAME_LEN];

    /** 资源数量 */
    ULONG_32 ulResNum;

    /** 资源列表 */
    RES_INFO_S astResList[IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM];

    /** 开始日期 YYYY-MM-DD */
    CHAR szBeginDate[IMOS_SIMPLE_DATE_LEN];

    /** 结束日期 YYYY-MM-DD */
    CHAR szEndDate[IMOS_SIMPLE_DATE_LEN];

    /** 开始时间 hh:mm:ss */
    CHAR szBeginTime[IMOS_SIMPLE_TIME_LEN];

    /** 结束时间 hh:mm:ss */
    CHAR szEndTime[IMOS_SIMPLE_TIME_LEN];

    /** 分析状态，见VEHICLE_PERIL_TIME_STATUS_E */
    ULONG_32 ulStatus;

    /** 备注 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_PERIL_TIME_INFO_S;

/**
* @struct tagVehiclePerilTimeResult
* @brief 车辆高危时段结果
* @attention
*/
typedef struct tagVehiclePerilTimeResult
{
    /** 结果编码 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车辆信息编号 */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 行驶方向，参考数据字典 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌颜色，参考数据字典 */
    CHAR szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色，参考数据字典 */
    CHAR szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车速 */
    ULONG_32 ulVehicleSpeed;

    /** 通过卡口时间 */
    CHAR szPassTime[IMOS_TIME_LEN];

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_PERIL_TIME_RESULT_S;

/**
* @struct tagOnlyIntoCItyInfo
* @brief 车辆多次进城不出城信息
* @attention
*/
typedef struct tagOnlyIntoCItyInfo
{
    /** 任务编号 */
    CHAR szTaskCode[IMOS_CODE_LEN];

    /** 任务名称 */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** 开始时间 YYYY-MM-DD HH:mm:ss */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 YYYY-MM-DD HH:mm:ss */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** 进城次数阀值 */
    ULONG_32 ulIntoCityCount;

    /** 出城次数阀值 */
    ULONG_32 ulOutCityCount;

    /** 分析状态，见VEHICLE_ABNORMAL_ANALYSE_STATUS_E */
    ULONG_32 ulAnalyseStatus;

    /** 进城操作符，见VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulIntoCityOperator;

    /** 出城操作符，见VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulOutCityOperator;

    /** 备注 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_ONLY_INTO_CITY_INFO_S;

/**
* @struct tagOnlyIntoCityResult
* @brief 车辆多次进城不出城结果
* @attention
*/
typedef struct tagOnlyIntoCityResult
{
    /** 结果编码 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车辆信息编号 */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 进城次数 */
    ULONG_32 ulIntoCityCount;

    /** 出城次数 */
    ULONG_32 ulOutCityCount;

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_ONLY_INTO_CITY_RESULT_S;

/**
* @struct tagFrequentNightOutInfo
* @brief 车辆频繁夜出、昼伏夜出共用信息
* @attention
*/
typedef struct tagFrequentNightOutInfo
{
    /** 任务编号 */
    CHAR szTaskCode[IMOS_CODE_LEN];

    /** 任务名称 */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** 资源数量 */
    ULONG_32 ulResNum;

    /** 资源列表 */
    RES_INFO_S astResList[IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM];

    /** 开始日期 YYYY-MM-DD */
    CHAR szBeginDate[IMOS_SIMPLE_DATE_LEN];

    /** 结束日期 YYYY-MM-DD */
    CHAR szEndDate[IMOS_SIMPLE_DATE_LEN];

    /** 白天开始时间 hh:mm:ss */
    CHAR szDayBeginTime[IMOS_SIMPLE_TIME_LEN];

    /** 白天结束时间 hh:mm:ss */
    CHAR szDayEndTime[IMOS_SIMPLE_TIME_LEN];

    /** 晚上开始时间 hh:mm:ss */
    CHAR szNightBeginTime[IMOS_SIMPLE_TIME_LEN];

    /** 晚上结束时间 hh:mm:ss */
    CHAR szNightEndTime[IMOS_SIMPLE_TIME_LEN];

    /** 白天通过次数阀值 */
    ULONG_32 ulDayMaxPassCount;

    /** 晚上通过次数阀值 */
    ULONG_32 ulNightMaxPassCount;

    /** 分析状态，见VEHICLE_ABNORMAL_ANALYSE_STATUS_E */
    ULONG_32 ulAnalyseStatus;

    /** 白天操作符，见VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulDayOperator;

    /** 晚上操作符，见VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulNightOperator;

    /** 备注 */
    CHAR szDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_FREQUENT_NIGHT_OUT_INFO_S;

/**
* @struct tagFrequentNightOutResult
* @brief 车辆频繁夜出、昼伏夜出共用结果
* @attention
*/
typedef struct tagFrequentNightOutResult
{
    /** 结果编码 */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** 车辆信息编号 */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 车牌号码  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** 白天车辆出现次数 */
    ULONG_32 ulDayPassCount;

    /** 晚上车辆出现次数 */
    ULONG_32 ulNightPassCount;

    /** 预留字段 */
    CHAR szReserve[128];
} VEHICLE_FREQUENT_NIGHT_OUT_RESULT_S;




/* End added by bt00977, 2013-1-25 of MPPD00420 */

/**
 * @struct tagRestrictPlanWeekTime
 * @brief 周计划
 * @attention
 */
typedef struct tagRestrictPlanWeekTime
{
    /** 周几 */
    ULONG_32 ulWeekDay;

    /** 时间信息, 其中的开始时间和结束时间格式为"hh:mm:ss" */
    TIME_SLICE_S astTimeSlice[IMOS_MAX_TIME_SLICE_NUM];

    /** 参数，尾号限行用逗号分隔，例如:1,9 */
    CHAR szParam[IMOS_MAX_PLAN_PARAM_LEN];

}RESTRICT_PLAN_WEEKTIME_S;

/**
 * @struct tagRestrictPlanExtTime
 * @brief 例外时间信息, 在配置例外计划时间时使用. 例外计划是在正常计划的基础上配置的特殊执行计划
 * @attention
 */
typedef struct tagRestrictPlanExtTime
{
    /** 例外日期 格式为"YYYY-MM-DD" */
    CHAR szExtDate[IMOS_SIMPLE_DATE_LEN];

    /** 例外时间片数组, 其中的开始时间和结束时间的格式为"hh:mm:ss" */
    TIME_SLICE_S astTimeSlice[IMOS_MAX_TIME_SLICE_NUM];

    /** 参数，尾号限行用逗号分隔，例如:1,9 */
    CHAR szParam[IMOS_MAX_PLAN_PARAM_LEN];
}RESTRICT_PLAN_EXTTIME_S;

/**
 * @struct tagRestrictPlanTime
 * @brief 计划时间信息结构
 * @attention
 */
typedef struct tagRestrictPlanTime
{
    /** 周计划 */
    RESTRICT_PLAN_WEEKTIME_S astPlanWeekTime[IMOS_WEEK_DAYS];

    /** 例外时间数组中例外时间的实际数量, 最大取值为#IMOS_EXCP_DAYS */
    ULONG_32 ulPlanExtTimeNum;

    /** 例外时间数组 */
    RESTRICT_PLAN_EXTTIME_S astPlanExtTime[IMOS_EXCP_DAYS];

}RESTRICT_PLAN_TIME_S;

/**
 * @struct tagVehicleRestrictBase
 * @brief 车辆限行基本配置
 * @attention
 */
typedef struct tagVehicleRestrictBase
{
    /** 限行编码 */
    CHAR szRestrictCode[IMOS_CODE_LEN];

    /** 限行名称 */
    CHAR szRestrictName[IMOS_NAME_LEN];

    /** 限行方式，参考#VEHICLE_RESTRICT_TYPE_E */
    ULONG_32 ulRestrictType;

    /** 车辆类型，参考数据字典 */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 起始日期 */
    CHAR szBeginDate[IMOS_SIMPLE_DATE_LEN];

    /** 结束日期 */
    CHAR szEndDate[IMOS_SIMPLE_DATE_LEN];

    /** 计划状态，BOOL_TRUE:启动; BOOL_FALSE:停止 */
    ULONG_32 ulPlanStatus;

    /** 计划类型, 取值为#PLAN_TYPE_E */
    ULONG_32 ulPlanType;

    /** 计划描述, 可不填 */
    CHAR szRestrictDesc[IMOS_DESC_LEN];

}VEHICLE_RESTRICT_BASE_S;

/**
 * @struct tagVehicleRestrictInfo
 * @brief 车辆限行
 * @attention
 */
typedef struct tagVehicleRestrictInfo
{
    /** 车辆限行基本配置 */
    VEHICLE_RESTRICT_BASE_S stRestrictBase;

    /** 车辆限行时间计划 */
    RESTRICT_PLAN_TIME_S stPlanTime;

}VEHICLE_RESTRICT_INFO_S;

/**
 * @struct tagNestQueryCondition
 * @brief 嵌套查询条件
 * @attention
 */
typedef struct tagNestQueryCondition
{
    /** 查询条件类型: #QUERY_TYPE_E */
    ULONG_32 ulQueryType;

    /** 查询条件逻辑关系类型: 支持#EQUAL_FLAG */
    ULONG_32 ulLogicFlag;

    /** 查询条件取值数量，最多#IMOS_QUERY_ITEM_MAX_NUM2 */
    ULONG_32 ulQueryDataNum;

    /** 查询条件取值列表 */
    CHAR aszQueryDataList[IMOS_QUERY_ITEM_MAX_NUM2][IMOS_QUERY_DATA_MAX_LEN];

} NEST_QUERY_CONDITION_S;

/**
* @struct tagVehicleCharacterPic
* @brief 过车特征图片
* @attention
*/
typedef struct tagVehicleCharacterPic
{
    /** 车辆信息编号 */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** 车牌彩色特征图片 */
    CHAR szPlatePic[IMOS_URL_LEN];

    /** 车牌二值化特征图片 */
    CHAR szBinaryPlatePic[IMOS_URL_LEN];

    /** 驾驶室特征图片 */
    CHAR szDriveCabPic[IMOS_URL_LEN];

    /** 副驾驶室特征图片 */
    CHAR szAssistDriveCabPic[IMOS_URL_LEN];

    /** 车标特征图片 */
    CHAR szVehicleLogoPic[IMOS_URL_LEN];

    /** 关联录像地址 */
    CHAR szRelateVideoAddr[IMOS_URL_LEN];

    /** 预留字段 */
    CHAR szReserve[512];
}VEHICLE_CHARACTER_PIC_S;

/**
* @struct tagDetectionRoadSectionVioConf
* @brief 测速区间超速百分比配置
* @attention
*/
typedef struct tagDetectionRoadSectionVioConf
{
    /** 超速百分比下限，取值范围[0,999] */
    ULONG_32 ulLowerSpeedPercent;

    /** 超速百分比上限，取值范围[0,999]，必须大于ulLowerSpeedPercent */
    ULONG_32 ulUpperSpeedPercent;

    /** 违法类型,参考数据字典 */
    CHAR szViolationType[IMOS_DICTIONARY_KEY_LEN];
	
	/** 车辆类型 */
    CHAR szVehicleType2[IMOS_DICTIONARY_KEY_LEN];

}DETECTION_ROAD_SECTION_VIO_CONF_S;

/**
* @struct tagVehicleRealTimeStatBaseInfo
* @brief 车流量统计基础信息
* @attention
*/
typedef struct tagVehicleRealTimeStatBaseInfo
{
    /** 卡口编码 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** 统计时间 */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** 总流量 */
    ULONG_32 ulTotalCount;

    /** 总平均速度 */
    ULONG_32 ulTotalAvgSpeed;
}VEHICLE_REAL_TIME_STAT_BASE_INFO_S;

/**
 * @struct tagVehicleRealTimeStatDirInfo
 * @brief 车流量统计行驶方向信息
 * @attention
 */
typedef struct tagVehicleRealTimeStatDirInfo
{
    /** 方向编号 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 方向名称 */
    CHAR szDirName[IMOS_NAME_LEN];

    /** 按行驶方向车流量 */
    ULONG_32 ulDirCount;

    /** 按行驶方向车流量 */
    ULONG_32 ulDirAvgSpeed;
}VEHICLE_REAL_TIME_STAT_DIR_INFO_S;

/**
* @struct tagVehicleRealTimeStatByDir
* @brief 车流量按行驶方向统计
* @attention
*/
typedef struct tagVehicleRealTimeStatByDir
{
    /** 车流量统计基本信息 */
    VEHICLE_REAL_TIME_STAT_BASE_INFO_S stStatBaseInfo;

    /** 统计行驶方向数量 */
    ULONG_32 ulStatDirNum;

    /** 根据行驶方向统计的流量信息 */
    VEHICLE_REAL_TIME_STAT_DIR_INFO_S astStatDirList[IMOS_MAX_LANE_DIRECTION_NUM];
}VEHICLE_REAL_TIME_STAT_BY_DIR_S;

/**
* @struct tagTMSMultiAddrForwardRule
* @brief TMS多地址转发规则
* @attention
*/
typedef struct tagTMSMultiAddrForwardRule
{
    /** 转发规则编号 */
    CHAR szForwardRuleCode[IMOS_CODE_LEN];

    /** 转发规则名称 */
    CHAR szForwardRuleName[IMOS_NAME_LEN];

    /** 转发类型，0-过车 1-布控/黑名单 */
    ULONG_32 ulForwardType;

    /** 转发模式，#参考TMS_FORWARD_MODE_E */
    ULONG_32 ulForwardMod;

    /** 转发地址类型，1-IPV4 2-IPV6 16-DNS */
    ULONG_32 ulForwardAddrType;

    /** 转发地址 */
    CHAR szForwardAddr[IMOS_IPADDR_LEN];

    /** 转发端口 */
    ULONG_32 ulForwardPort;

    /** 转发状态 */
    ULONG_32 ulStatus;

    /** 预留字段 */
    CHAR szReserve[124];
}TMS_MULTI_ADDR_FORWARD_RULE_S;

/**
* @struct tagTMSMultiAddrForwardInfo
* @brief TMS多地址转发
* @attention
*/
typedef struct tagTMSMultiAddrForwardInfo
{
    /** TMS转发规则 */
    TMS_MULTI_ADDR_FORWARD_RULE_S stTmsMultiForwardRule;

    /** 转发资源数量 */
    ULONG_32 ulResNum;

    /** 转发资源列表 */
    RES_INFO_S astResList[IMOS_TMS_MULTI_FORWARD_RES_MAX_NUM];
}TMS_MULTI_ADDR_FORWARD_INFO_S;


/**
* @struct tagTollgateGroupInfo
* @brief 卡口组配置
* @attention
*/
typedef struct tagTollgateGroupInfo
{
     /** 卡口组编号*/
    CHAR szTollgateGroupCode[IMOS_CODE_LEN];

    /** 卡口组名称 */
    CHAR szTollgateGroupName[IMOS_NAME_LEN];

    /** 卡口数量 */
    ULONG_32 ulResNum;

    /** 卡口列表 */
    RES_INFO_S astResList[IMOS_TMS_MULTI_FORWARD_RES_MAX_NUM];

    /** 预留字段 */
    CHAR szReserve[128];
}TOLLGATE_GROUP_INFO_S;



/**
* @struct tagViolationCombineConf
* @brief 合成违章图片叠加的配置结构
* @attention 无
*/
typedef struct tagViolationCombineConf
{
    /** 违章图片合成使能 */
    ULONG_32 ulCombineEnable;

    /** 叠加车牌号码 */
    ULONG_32 ulHasPlateCode;

    /** 叠加车牌颜色 */
    ULONG_32 ulHasPlateColor;

    /** 叠加红灯时间 */
    ULONG_32 ulHasRedLightTime;

    /** 叠加速度 */
    ULONG_32 ulHasSpeed;

    /** 叠加抓拍地点 */
    ULONG_32 ulHasTollgateName;

    /** 叠加限速 */
    ULONG_32 ulHasLimitedSpeed;

    /** 叠加抓拍时间 */
    ULONG_32 ulHasPassTime;

    /** 叠加车辆类型 */
    ULONG_32 ulHasVehicleType;

    /** 叠加违章类型 */
    ULONG_32 ulHasViolationType;

    /** 叠加车辆品牌 */
    ULONG_32 ulHasVehicleLogo;

    /** 叠加车身颜色 */
    ULONG_32 ulHasVehicleColor;

    /** 叠加车道号 */
    ULONG_32 ulHasLaneNumber;

    /** 叠加相机编号 */
    ULONG_32 ulHasCameraCode;

    /** 叠加相机名称 */
    ULONG_32 ulHasCameraName;

    /** 叠加方向 */
    ULONG_32 ulHasDirection;

    /** 叠加防伪码 */
    ULONG_32 ulHasEncrypt;

    /** 冒号分割，BOOL_TRUE:冒号分割，BOOL_FALSE:空格 */
    ULONG_32 ulHasColon;

    /* OSD位置信息，参考#OSD_PLACE_MODE */
    ULONG_32 ulOSDPlaceMode;

    /** 超速百分比 */
    ULONG_32 ulHasSpeedPercent;

    /** 设置字体大小 */
    ULONG_32 ulFontVectorSize;

    /** 是否时间显示毫秒 */
    ULONG_32 ulHasMillisecond;

    /** 叠加违法代码 */
    ULONG_32 ulHasViolationCode; /* Added by l01773, 2014-12-11 of MPPD20183*/

    /** 区间名称 */
    ULONG_32 ulHasP2PName;  /* Added by y01693 for mppd21982 20150128 */

    /** 区间距离 */
    ULONG_32 ulHasP2PDistance;

    /** 驶出监控点名称 */
    ULONG_32 ulHasTollgateName2;

    /** 驶出监控时间 */
    ULONG_32 ulHasPassTime2;

    /** 行驶时间 */
    ULONG_32 ulHasTravelTimes;

    /** 驶出相机编号 */
    ULONG_32 ulHasCameraCode2;

    /** 驶出相机名称 */
    ULONG_32 ulHasCameraName2;

    /** 数据类型，参考#TMS_COMBINE_TYPE_E */
    ULONG_32 ulHasDateType;

    /** 预留字段 */
    CHAR szReserve[80];
}VIOLATION_COMBINE_CONF_S;

/* Start added by lKF0174, 2013-11-18 of MPPD06792 */
/**
* @struct tagVehicleTransFlag
* @brief 修改过车/违法上传标志位结构
* @attention 无
*/
typedef struct tagVehicleTransFlag
{
    /** 车辆信息编号 */
    CHAR  szDataCode[IMOS_CODE_LEN];

    /** 数据类型 0表示过车数据，1表示违法数据*/
    ULONG_32 ulType;

    /** 通过时间 */
    CHAR  szPassTime[IMOS_TIME_LEN];

/* Start added by xW1251, 2014-11-19 for 违法录像手动备份优化*/
    /** 告警时间 */
    CHAR  szAlarmTime[IMOS_TIME_LEN];

    /** 卡口编码 ,长度32*/
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 车道编号 */
    ULONG_32 ulLaneIndex;

   /** 图片1名称*/
   CHAR szPic1Name[IMOS_URL_LEN];

/* End modified by xW1251, 2014-11-10 for 违法录像手动备份优化*/

    /** 是否上传 参考#VEHICLE_TRANS_FLAG_VALUE_E*/
    ULONG_32 ulTransFlag;

    /** 传输标识比特位，参考#VEHICLE_TRANS_FLAG_BIT_E */
    ULONG_32 ulTransFlagBit;

    /** 预留字段 */
    CHAR szReserve[256];
}VEHICLE_TRANS_FLAG_S;
/* End added by lKF0174, 2013-11-18 of MPPD06792 */

/* Begin Added by shendongchun 00400 2014-02-26 for 大数据服务器增加 */
/**
 * @struct tagDBInfo
 * @brief DB(数据存储服务器)信息
 * @attention
 */
typedef struct tagDBInfo
{
    /** 编码 */
    CHAR szDBCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR szDBName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称，查询返回，其他情况下可以不填 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** DBS类型，0-DB8500，1-DB9500 */
    ULONG_32 ulType;

  /** DBS子类型，DB9500_TYPE_E，查询时返回，其他情况不需要填写 */
    ULONG_32 ulSubType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址，查询返回，其他情况下可以不填 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 描述, 暂不使用，填空 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

} DB_INFO_S;

/* End Added by shendongchun 00400 2014-02-26 for 大数据服务器增加 */

/**
 * @struct tagIAHRInfo
 * @brief IAHR(智能人脸卡口服务器)信息
 * @attention
 */
typedef struct tagIAHRInfo
{
    /** 编码 */
    CHAR szIAHRCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR szIAHRName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称，查询返回，其他情况下可以不填 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** IAHR子类型，目前未使用，默认为0 */
    ULONG_32 ulType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址，查询返回，其他情况下可以不填 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 描述, 暂不使用，填空 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

} IAHR_INFO_S;

/**
* @struct tagElecPoliceBindInfo
* @brief 电警绑定信息
* @attention 资源列表最大支持200个
*/
typedef struct tagElecPoliceBindInfo
{
    /** 电警编码 */
    CHAR szElecPoliceCode[IMOS_CODE_LEN];

    /** 资源数量 */
    ULONG_32 ulResNum;

    /** 资源列表 */
    RES_INFO_S astResList[IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM];
} ELEC_POLICE_BIND_INFO_S;

/**
* 卡口与TMS的绑定关系
*
*/
typedef struct tagTollgateTmsBindInfo
{
    /** TMS编码(绑定时使用，解绑定时不使用)*/
    CHAR        szTMSCode[IMOS_CODE_LEN];

    /** 资源数目*/
    ULONG_32    ulResNum;

    /** 资源列表(最大为IMOS_MAX_DEAL_NUM_ONE_TIME)*/
    RES_INFO_S  astResList[IMOS_MAX_DEAL_NUM_ONE_TIME];
}TOLLGATE_TMS_BIND_INFO_S;

/* Begin added by c02845,2016-05-12,交通流信息接入 */

/**
 * @struct tagTrafficFlowQueryCondition
 * @brief 查询条件(不分车道)
 * @attention 按日、月、年等方式.若按日,则返回当天24小时内各个小时的24条统计数据，按月\年也类似
 */
typedef struct tagTrafficFlowQueryCondition
{
    /** 查询时间方式: #TRAFFIC_QUERY_TIME_E, 按日、月、年等方式*/
    ULONG_32 ulTrafficQueryTime;

    /** 查询时间点，格式为:YYYY_MM_DD的形式 */
    CHAR szDayTime[IMOS_SIMPLE_DATE_LEN];

    /* 卡口数量 */
    ULONG_32 ulTGDevNum;

    /* 卡口设备编码 */
    CHAR szTGDevCode[IMOS_TRAFFIC_FLOW_TOLLGATE_MAX_NUM][IMOS_CODE_LEN];
    
}TRAFFICFLOW_QUERY_CONDITION_S;

/**
* @struct tagTrafficFlowResInfo
* @brief 资源信息
* @attention 无
*/
typedef struct tagTrafficFlowResList
{
    /** 资源ID，字符串"0"表示系统 */
    CHAR    szResIdCode[IMOS_CODE_LEN];

    /** 资源编码 */
    CHAR    szResCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR    szResName[IMOS_NAME_LEN];

    /** 资源类型，取值范围为#IMOS_TYPE_E */
    ULONG_32   ulResType;

    /** 资源子类型,目前资源子类型只对摄像机/组织/组显示/组轮巡有效，对摄像机而言为云台/非云台;
        对组织而言为:1-本物理域，2-本域的虚拟域，3-外域的虚拟域. 4-上级外物理域.
        5-下级外物理域.6-平级外物理域.
        对组显示资源代表组显示类型，取值为#SALVO_TYPE_E
        对组轮巡资源代表组轮巡类型，取值为#GROUP_SWITCH_TYPE_E */
    ULONG_32   ulResSubType;

    /** 所属组织编码 */
    CHAR        szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称 */
    CHAR        szOrgName[IMOS_NAME_LEN];

} TRAFFICFLOW_RES_INFO_S;

/**
 * @struct tagTrafficFlowQueryCondition
 * @brief 分车道查询条件
 * @attention  按小时查询,查询的结果是从szBeginDayTime~szEndDayTime这段日期内
 * @attention 每天从szBeginHourTime~szBeginHourTime时间段内车流量信息的平均值统计结果
 */
typedef struct tagTrafficFlowHourQueryCondition
{
    /** 起始查询日期,格式为:YYYY-MM-DD的形式 */
    CHAR szBeginDayTime[IMOS_SIMPLE_DATE_LEN];

    /** 终止查询日期,格式为:YYYY-MM-DD的形式 */
    CHAR szEndDayTime[IMOS_SIMPLE_DATE_LEN];

    /** 起始查询时刻,格式为:HH:MM:SS的形式 */
    CHAR szBeginHourTime[IMOS_SIMPLE_DATE_LEN];

    /** 终止查询时刻,格式为:HH:MM:SS的形式 */
    CHAR szEndHourTime[IMOS_SIMPLE_DATE_LEN];

    /* 查询组织数量 */
    ULONG_32 ulResNum;
    
    /* 组织编码 */
    TRAFFICFLOW_RES_INFO_S astTrafficFlowResLaneList[IMOS_TRAFFIC_FLOW_TOLLGATE_MAX_NUM];

 }TRAFFICFLOW_QUERY_CONDITION_LANE_S;


/**
* @struct tagTrafficFlowQueryItem
* @brief 交通流信息查询信息
* @attention 按日、月、年查询的接口，不分车道号,只根据卡口编码查询车流量
*/
typedef struct tagTrafficFlowQueryInfo
{
    /* 查询结果时间,注:如果是年查询，则返回格式:YYYY-MM, */
    /* 按月查询则返回格式:YYYY-MM-DD, 按日查询,YYYY-MM-DD HH:00:00 */
    CHAR szQueryTime[IMOS_TIME_LEN];
    
    /** 车流总量,单位:辆 */
    ULONG_32 ulVehicleNum;

    /** 车流排队长度,单位:米 */
    ULONG_32 ulQueueLength;

    /** 平均车速,单位：Km/h */
    ULONG_32 ulVehicleAverageSpeed;

}TRAFFIC_FLOW_QUERY_INFO_S;

/**
 * @struct tagVehicleAtrributionList
 * @brief 交通流信息查询列表
 * @attention  IMOS_TRAFFIC_FLOW_LIST_MAX_NUM定义为32,
 * @attention  实际中，按日查询则返回24小时的信息（即24条查询结果）,按月则返回每月各个天数的信息 ...
 */
typedef struct tagTrafficFlowQueryList
{
    /* 查询结果数量 */
    ULONG_32 ulResultNum;

    /* 查询结果列表，每个时间点一条，例如：按日查询，则有24条;按月查询，则有28~31条不定;按年，则有12条 */
    TRAFFIC_FLOW_QUERY_INFO_S astTrafficFlowList[IMOS_TRAFFIC_FLOW_LIST_MAX_NUM];
}TRAFFIC_FLOW_QUERY_LIST_S;


/**
* @struct tagTrafficFlowQueryItem
* @brief 交通流信息按小时查询，区分每个车道的具体车流量信息
* @attention
*/
typedef struct tagTrafficFlowQueryLane
{  
    /** 卡口编号 */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称 */
    CHAR szTollgateName[IMOS_NAME_LEN];
    
    /* 车道编号 */
    ULONG_32 ulLaneID;

    /* 方向名称,与方向编号对应,根据平台配置赋值 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /* 查询结果的日期,格式为YYYY-MM-DD HH:MM:SS */
    CHAR szData[IMOS_TIME_LEN];

    /** 车流总量,单位:辆 */
    DULONG ulVehicleNum;

    /** 车流排队长度,单位:米 */
    ULONG_32 ulQueueLength;

    /** 平均车速,单位：Km/h */
    ULONG_32 ulVehicleAverageSpeed;

} TRAFFIC_FLOW_QUERY_LANE_INFO_S;

/**
 * @struct tagVehicleAtrributionList
 * @brief 交通流信息查询列表
 * @attention  IMOS_TRAFFIC_FLOW_LANE_MAX_NUM 定义为澹(4*8*7),即:4个卡口，每个卡口最多8个车道,查询天数最多7天;
 * @attention  实际中，返回查询天数内，每个卡口下面的每个车道的信息
 */
typedef struct tagTrafficFlowQueryLaneList
{
    /* 查询结果数量 */
    ULONG_32 ulResultNum;

    /* 查询结果列表，每个车道一条 */
    TRAFFIC_FLOW_QUERY_LANE_INFO_S astTrafficFlowlaneList[IMOS_TRAFFIC_FLOW_LANE_MAX_NUM];
}TRAFFIC_FLOW_QUERY_LANE_LIST_S;


/* End added by c02845,2016-05-12,交通流接入*/

/*Begin added by a02842 for 大数据流量统计,2016-06-24*/
/**
* @struct tagVehicleStatInfoHbase
* @brief 大数据统计SDK接口
*/
typedef struct tagTrafficStatInfoHbase
{
    /** 开始时间*/
    CHAR        szStartTime[IMOS_TIME_LEN];

    /** 结束时间*/
    CHAR        szEndTime[IMOS_TIME_LEN];

    /**查询类型1---按组织统计、2---按卡口统计*/
    ULONG_32 ulQueryType;

    /**统计类型1---过车、2---违法*/
    ULONG_32 ulStatType;

    /**报表类型，取值为日期类型对应的毫秒数*/
    ULONG_32 ulReportType;

    /**统计子类型,值参考tbl_dic_type*/
    ULONG_32 ulSubType;

    /**统计条件1---按时间统计、2---按地点卡口统计,3---按子类型统计*/
    ULONG_32  ulGroupType;

    /** 统计排序参考项0:时间或卡口,1:统计值*/
    ULONG_32   ulOrderItem;
    
    /** 统计排序类型0:asc升序,1:desc降序*/
    ULONG_32   ulOrderType;
}TRAFFIC_STAT_INFO_HBASE_S;

/**
* @struct tagTrafficStatDicInfo
* @brief 流量统计结果
*/
typedef struct tagTrafficStatDicCountResult
{
    /** 统计数据字典编码*/
    CHAR          szDicCode[IMOS_DICTIONARY_KEY_LEN];

    /** 统计数量*/
    ULONG_32    ulCount;        
}TRAFFIC_STAT_DIC_COUNT_RESULT;

/**
* @struct tagVehicleStatInfoHbase
* @brief 大数据统计SDK接口
*/
typedef struct tagTrafficStatResultHbase
{
    /**统计类型1---过车、2---违法*/
    ULONG_32 ulStatType;
    
    /**统计条件1---按时间统计、2---按地点卡口统计，,3---按子类型统计*/
    ULONG_32  ulGroupType;

    /**按时间统计:统计时间*/
    CHAR        szStatTime[IMOS_TIME_LEN];

    /**按卡口统计:统计卡口*/
    CHAR        szStatTollgate[IMOS_CODE_LEN];

    /**按子类型统计:统计子类型,ulGroupType = 3时不返回统计子类型结果列表*/
    CHAR        szDicCode[IMOS_DICTIONARY_KEY_LEN];
        
    /** 总计 */
    ULONG_32 ulTotalCount;

    /** 统计子类型*/
    ULONG_32    ulSubType;

    /** 统计子类型分类数量*/
    ULONG_32    ulDicCountNum;
    
    /** 统计子类型结果列表*/
    TRAFFIC_STAT_DIC_COUNT_RESULT astDicCount[IMOS_DIC_CODE_MAX_NUM];
}TRAFFIC_STAT_RESULT_HBASE_S;
/*End added by a02842 for 大数据流量统计,2016-06-24*/

/*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
/**
 * @struct tagMacRfidDispositionUndoInfo
 * @brief MAC&RFID撤控信息结构
 * @attention
 */
typedef struct tagMacRfidDispositionUndoInfo
{

    /** 撤控单位编码*/
    CHAR szUndoDept[IMOS_CODE_LEN];

    /** 撤控人员编码*/
    CHAR szUndoUser[IMOS_CODE_LEN];

    /** 撤控时间 */
    CHAR szUndoTime[IMOS_TIME_LEN];

    /** 撤控原因，可以不填写 */
    CHAR szUndoDesc[IMOS_DESC_LEN];

    /** 预留字段 */
    CHAR szReserve[204];

} MACRFID_DISPOSITION_UNDO_INFO_S;

/**
 * @struct tagMacRfidDispositionInfo
 * @brief MAC&RFID布控信息结构
 * @attention
 */
typedef struct tagMacRfidDispositionInfo
{

    /** 布控编号，系统自动生成 */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** 布控类别，参考#DISPOSITION_TYPE_E，入参必填 */
    ULONG_32 ulDispositionType;

    /** RFID设备号，必须填写 */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /**  布控的MAC地址，必须填写 */
    CHAR szMacAddr[IMOS_CODE_LEN];

    /** 号牌号码，可以不填*/
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /**所属组织，可以不填*/
    CHAR szOrganization[IMOS_CODE_LEN];

    /** 车身颜色，参考数据字典，可以不填，默认为空，表示所有颜色 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆品牌，参考数据字典，可以不填，默认为空，表示所有品牌 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车主姓名，可以不填，默认为空*/
    CHAR  szDriverName[IMOS_NAME_LEN];

    /** 车主身份证号码，可以不填，默认为空*/
    CHAR  szDriverID[IMOS_CODE_LEN];

    /** 车主联系电话，可以不填，默认为空*/
    CHAR  szDriverPhoneNum[IMOS_CODE_LEN];

    /** 布控单位编码，可以不填*/
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** 布控人员编码，可以不填*/
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** RFID布控原因，参考数据字典，必须填写 */
    CHAR  szRfidDispositionReason[IMOS_DICTIONARY_KEY_LEN];

    /** MAC布控原因，参考数据字典，必须填写 */
    CHAR  szMacDispositionReason[IMOS_DICTIONARY_KEY_LEN];

    /** 添加布控车辆名单的时刻，查询返回，入参可不填 */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** 布控开始时间，必须填写 */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** 布控结束时间，必须填写 */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 布控状态，参考#DISPOSITION_STATUS_E，查询返回，入参可不填 */
    ULONG_32 ulStatus;

    /** 案件描述，可以不填 */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** 短信关联号码 (支持256个号码)*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];

    /** 布控照片(形如ftp://用户名:密码@192.168.10.1/tollgate/abc.jpg)，必须先通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper获取FTP参数 */
    CHAR  szDispositionImage[IMOS_FILE_PATH_LEN];

    /** 撤控信息 */
    MACRFID_DISPOSITION_UNDO_INFO_S stUndoInfo;

    /** 扩展1*/
    CHAR szExpend1[IMOS_CODE_LEN];

    /** 扩展2*/
    CHAR szExpend2[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR szVehicleType[IMOS_CODE_LEN];
    
    /** 布控虚拟身份类型，支持按虚拟身份布控*/
    CHAR szIdentifyType[IMOS_CODE_LEN];

    /** 布控虚拟身份编码，支持按虚拟身份布控*/
    CHAR szIdentifyCode[IMOS_CODE_LEN];

} MACRFID_DISPOSITION_INFO_S;

/**
 * RFID信息结构
 */
typedef struct tagRfidAlarmInfo
{
     /* 告警ID，唯一 */
     CHAR szAlarmId[IMOS_CODE_LEN];

     /* 告警时间 */
     CHAR szAlarmTime[IMOS_TIME_LEN];

     /* 告警原因*/
     CHAR  szAlarmReason[IMOS_DICTIONARY_KEY_LEN];

     /* 记录ID 非空 */
    CHAR szRecordID[IMOS_CODE_LEN];
       
    /** 采集设备编号 */
    CHAR szDevID[IMOS_STRING_LEN_32];
    
    /**卡口编号*/
    CHAR szTollgateID[IMOS_STRING_LEN_32];

    /* 经度 */
    CHAR szLongitude[IMOS_COORDINATE_LEN];
    
    /* 纬度 */ 
    CHAR szLatitude[IMOS_COORDINATE_LEN];
    
    /**标签名字*/
    CHAR szRfidName[IMOS_CODE_LEN];

        /**标签ID*/
    CHAR szLabelID[IMOS_STRING_LEN_16];
    
    /**地标器ID*/
    CHAR szLandMarkID[IMOS_STRING_LEN_16];
    
    /**被采集设备状态*/
    CHAR szDevStatus[IMOS_STRING_LEN_16];

    /**状态*/
    CHAR szStatus[IMOS_STRING_LEN_16];
    
    /**逻辑防拆计数器*/
    CHAR szCounter[IMOS_STRING_LEN_16];
    
    /**信号强度RSSI*/
    CHAR szRSSI[IMOS_STRING_LEN_16];
    
    /**车道标号*/
    CHAR szLaneID[IMOS_STRING_LEN_16];
    
    /**方向编号*/
    CHAR szDirection[IMOS_STRING_LEN_16];
    
    /** 产生报警的设备类型 */
    CHAR szDevType[IMOS_STRING_LEN_16];
    
    /** 应用类型 */
    CHAR szApplyType[IMOS_STRING_LEN_16];

    /**经过时刻*/
    CHAR szPassTime[IMOS_TIME_LEN];
    
    /** 装置省份 */
    CHAR szProvince[IMOS_STRING_LEN_32];
    
    /** 装置城市 */
    CHAR szCity[IMOS_STRING_LEN_32];
    
    /** 数据入库时间 */
    CHAR szDatabaseTime[IMOS_TIME_LEN];
    
    /**平台接收时间 */
    CHAR szReceiveTime[IMOS_TIME_LEN];

	/** added by a02842 for MPPD51528,2017/09/22*/
    /** 设备名称*/
    CHAR szDevName[IMOS_NAME_LEN];
    
    /** 车牌号*/
    CHAR  szPlateCode[IMOS_CODE_LEN];
    
    /** 车主姓名*/
    CHAR  szDriverName[IMOS_NAME_LEN];

    /** 车主身份证号码*/
    CHAR  szDriverID[IMOS_CODE_LEN];

    /** 联系电话*/
    CHAR  szDriverPhone[IMOS_CODE_LEN];

    /** 预留位*/
    CHAR  szReserve[IMOS_STRING_LEN_256];
}RFID_ALARM_INFO_S;

/*Begin added by a02842 for mac identify,2017-05-08*/
/**
 * MAC虚拟身份结构
 */
typedef struct tagMACIdentifyInfo
{
    /** 虚拟身份类型*/
    CHAR szIdentifyType[IMOS_CODE_LEN];

    /** 虚拟身份编码*/
    CHAR szIdentifyCode[IMOS_CODE_LEN];
    
    /**虚拟身份ID*/
    CHAR szIdentifyID[IMOS_CODE_LEN];

    /**预留位*/
    CHAR szRes1[IMOS_CODE_LEN];  
}MAC_IDENTIFY_INFO;
/*End added by a02842 for mac identify,2017-05-08*/

/**
 * MAC地址信息结构
 */
typedef struct tagMacAlarmInfo
{
     /* 告警ID，唯一 */
     CHAR szAlarmId[IMOS_CODE_LEN];

     /* 告警时间 */
     CHAR szAlarmTime[IMOS_TIME_LEN];

     /* 告警原因*/
     CHAR szAlarmReason[IMOS_DICTIONARY_KEY_LEN];

     /* 记录ID 非空 */
    CHAR szRecordID[IMOS_CODE_LEN];

    /* 设备ID 非空 */
    CHAR szDevID[IMOS_CODE_LEN];

    /* MAC地址 非空 */
    CHAR szMACAddr[IMOS_CODE_LEN];

    /* 终端场强 非空 */
    CHAR szFieldIntensity[IMOS_CODE_LEN];

    /* 终端状态 可空 0-终端进入 1-终端离开 */
    CHAR szDevStatus[IMOS_DICTIONARY_KEY_LEN];

    /* 被采集设备类型 0: 终端设备(默认) 1: 热点 */
    CHAR szDevType[IMOS_DICTIONARY_KEY_LEN];

    /* 采集数量*/
    ULONG_32 ulScanNum;
    
    /* 采集时间 非空 */
    CHAR szCollecttime[IMOS_TIME_LEN]; 

    /* 场所编号 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /* 设备经度 */
    CHAR szLongitude[IMOS_COORDINATE_LEN];

    /* 设备纬度 */
    CHAR szLatitude[IMOS_COORDINATE_LEN];

    /* 设备海拔 */
    CHAR szAltitude[IMOS_STRING_LEN_32];

    /* X坐标 */
    CHAR szCoordX[IMOS_CODE_LEN];
    
    /* Y 坐标 */
    CHAR szCoordY[IMOS_CODE_LEN];

    /* 接入热点SSID */
    CHAR szHotPointSSID[IMOS_STRING_LEN_64];

    /* 接入热点MAC */
    CHAR szHotPointMAC[IMOS_CODE_LEN];

    /* 接入热点频道 */
    CHAR szHotPointChannel[IMOS_CODE_LEN];

    /* 接入热点加密类型 */
    CHAR szHotPointEncryptType[IMOS_CODE_LEN];

    /* 终端设备采集信息内容 */
    /* 终端品牌 */
    CHAR szDevBrand[IMOS_CODE_LEN];

    /* 终端信息*/
    CHAR szDevInfo[IMOS_DESC_LEN];

    /* 终端历史SSID列表 ,告警暂时不使用*/
    CHAR szSSIDList[IMOS_STRING_LEN_1024];

    /* 身份类型 0: Server 1: Client */
    CHAR szIDType[IMOS_DICTIONARY_KEY_LEN];

    /* 虚拟身份相关(上网过程中能够采集) */
    /* QQ帐号 */
    CHAR szQQID[IMOS_STRING_LEN_256];
    
    /* 微信识别号 */
    CHAR szWeCharID[IMOS_STRING_LEN_256];
    
    /* 微博帐号 */
    CHAR szWeiBoID[IMOS_STRING_LEN_256];

    /* 微博帐号 */
    CHAR szTencentweibo_ID[IMOS_STRING_LEN_256];
    
    /* 淘宝帐号 */
    CHAR szTaoBaoID[IMOS_STRING_LEN_256];
    
    /* IMEI: 移动设备识别码 */
    CHAR szIMEI[IMOS_STRING_LEN_32];
    
    /* IMSI: 移动用户识别码 */
    CHAR szIMSI[IMOS_STRING_LEN_32];
    
    /* 手机号码 */    
    CHAR szMobileNum[IMOS_STRING_LEN_256];
}    MAC_ALARM_INFO_S;

/*Begin added by a02842 for mac identify,2017-05-08*/
/**
 * MAC地址信息结构
 */
typedef struct tagMacAlarmInfoV2
{
     /* 告警ID，唯一 */
     CHAR szAlarmId[IMOS_CODE_LEN];

     /* 告警时间 */
     CHAR szAlarmTime[IMOS_TIME_LEN];

     /* 告警原因*/
     CHAR szAlarmReason[IMOS_DICTIONARY_KEY_LEN];

     /* 记录ID 非空 */
    CHAR szRecordID[IMOS_CODE_LEN];

    /* 设备ID 非空 */
    CHAR szDevID[IMOS_CODE_LEN];

    /* MAC地址 非空 */
    CHAR szMACAddr[IMOS_CODE_LEN];

    /* 终端场强 非空 */
    CHAR szFieldIntensity[IMOS_CODE_LEN];

    /* 终端状态 可空 0-终端进入 1-终端离开 */
    CHAR szDevStatus[IMOS_DICTIONARY_KEY_LEN];

    /* 被采集设备类型 0: 终端设备(默认) 1: 热点 */
    CHAR szDevType[IMOS_DICTIONARY_KEY_LEN];

    /* 采集数量*/
    ULONG_32 ulScanNum;
    
    /* 采集时间 非空 */
    CHAR szCollecttime[IMOS_TIME_LEN]; 

    /* 场所编号 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /* 设备经度 */
    CHAR szLongitude[IMOS_COORDINATE_LEN];

    /* 设备纬度 */
    CHAR szLatitude[IMOS_COORDINATE_LEN];

    /* 设备海拔 */
    CHAR szAltitude[IMOS_STRING_LEN_32];

    /* X坐标 */
    CHAR szCoordX[IMOS_CODE_LEN];
    
    /* Y 坐标 */
    CHAR szCoordY[IMOS_CODE_LEN];

    /* 接入热点SSID */
    CHAR szHotPointSSID[IMOS_STRING_LEN_64];

    /* 接入热点MAC */
    CHAR szHotPointMAC[IMOS_CODE_LEN];

    /* 接入热点频道 */
    CHAR szHotPointChannel[IMOS_CODE_LEN];

    /* 接入热点加密类型 */
    CHAR szHotPointEncryptType[IMOS_CODE_LEN];

    /* 终端设备采集信息内容 */
    /* 终端品牌 */
    CHAR szDevBrand[IMOS_CODE_LEN];

    /* 终端信息*/
    CHAR szDevInfo[IMOS_DESC_LEN];

    /* 终端历史SSID列表 ,告警暂时不使用*/
    CHAR szSSIDList[IMOS_STRING_LEN_1024];

    /* 身份类型 0: Server 1: Client */
    CHAR szIDType[IMOS_DICTIONARY_KEY_LEN];

    /* 虚拟身份相关(上网过程中能够采集) */
    /* QQ帐号 */
    CHAR szQQID[IMOS_STRING_LEN_256];
    
    /* 微信识别号 */
    CHAR szWeCharID[IMOS_STRING_LEN_256];
    
    /* 微博帐号 */
    CHAR szWeiBoID[IMOS_STRING_LEN_256];

    /* 微博帐号 */
    CHAR szTencentweibo_ID[IMOS_STRING_LEN_256];
    
    /* 淘宝帐号 */
    CHAR szTaoBaoID[IMOS_STRING_LEN_256];
    
    /* IMEI: 移动设备识别码 */
    CHAR szIMEI[IMOS_STRING_LEN_32];
    
    /* IMSI: 移动用户识别码 */
    CHAR szIMSI[IMOS_STRING_LEN_32];
    
    /* 手机号码 */    
    CHAR szMobileNum[IMOS_STRING_LEN_256];

    /*虚拟身份数量*/
    ULONG_32 ulIdentifyNum;
    
    /*虚拟身份信息*/
    MAC_IDENTIFY_INFO astIdentifyInfo[IMOS_MAC_IDENTIFY_INFO_MAX_NUM];

    /*布控规则ID*/
    IMOS_ID    idDisposeID;    
    
    /*预留位*/
    CHAR szReserve1[120];
}MAC_ALARM_INFO_V2_S;
/*End added by a02842 for mac identify,2017-05-08*/

/*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

/**
 * 卡口流量信息结构
 */
typedef struct tagTollgateFlowInfo
{   
    /* 卡口编码 */
    CHAR szTollgateID[IMOS_CODE_LEN];

    /* 采集时间 */
    CHAR szSampleTime[IMOS_TIME_LEN];

    /* 流量状态 */
    ULONG_32 ulState;
}TOLLGATE_FLOW_INFO_S;


#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif
