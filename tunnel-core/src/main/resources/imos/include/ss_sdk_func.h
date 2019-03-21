/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              ss_sdk_func.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2009-07-27
        Author: huangjun (00754)
                chenshangwu (07076)
   Description: SDK对外接口
                注意: 其中分页查询时，所需列表空间由外部申请，
                      大小根据分页查询时一页的个数进行申请。


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SS_SDK_INTERFACE_H_
#define _IMOS_SS_SDK_INTERFACE_H_

/* 包含BP预编译宏以及基础类型的文件 */

#ifdef  __cplusplus
extern "C"{
#endif


/*************************************************************************************
SS 新增函数
***************************************************************************************/

/*************************************************************************************
SS 会议操作
***************************************************************************************/

#if 0
#endif

/** @defgroup groupConfMgr 会议管理
*   预约会议、活动会议、历史会议、会议模板管理
*   @{
*/

/**
* 立即召开会议 周期会议不能立即召开，永久会议可以。
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId
);


/**
* 获得活动会议信息， 其中包括会场列表，各会场的状态
* @param [IN]      pstUserLogIDInfo        用户信息标识
* @param [IN]      ulConfCheckAuthMode     会议鉴权方式(CONF_CHECK_AUTH_MODE_E，进入会控使用会控鉴权，进入拓扑使用会议管理鉴权)
* @param [IN]      idConfId                会议ID
* @param [OUT]     pstConferenceActiveInfo 会场活动信息
* @param [IN][OUT] pulSiteCount            会场个数
* @param [OUT]     pstSiteList             会场列表
* @param [IN][OUT] pulMcuCount             会议MCU个数
* @param [OUT]     pstMcuList              会议MCU列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 获得会议中多个会场的信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstName                 按名字模糊查询信息条件， 为空则查询全部
* @param [IN]    pstQueryPageInfo        请求分页信息
* @param [OUT]   pstRspPageInfo          返回分页信息
* @param [OUT]   pstTerminalList         终端信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS 活动会议控制
***************************************************************************************/

/** @defgroup groupConfControl 会议控制
*   会议控制
*   @{
*/

/**
* 结束会议
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EndConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId
);

/**
* 延长会议， 单位为分钟
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    lMinute                 延长会议时间
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ExtendConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  LONG_32                    lMinute
);

/**
* 群邀会场/挂断所有会场
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    bCallAllSites           BOOL_TRUE表示呼叫所有会场， 否则挂断所有会场
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CallAllSites
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bCallAllSites
);


/**
* 锁定/取消锁定会议。会议锁定后，不允许匿名会场主动呼叫加入会议。但MCU还可以主动呼叫已加入MCU的其他会场。
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    bLockConf               BOOL_TRUE表示锁定会议， 否则表示取消锁定会议
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LockConference
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bLockConf
);

/**
* 关闭/开启所有扬声器。关闭所有扬声器， 即全部静音
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    bSilenceAll             BOOL_TRUE表示关闭所有扬声器, 否则开启所有扬声器
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAllSilence
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bSilenceAll
);

/**
* 关闭/开启所有麦克风。 关闭所有麦克风， 即全部闭音
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    bMuteAll                BOOL_TRUE表示关闭所有麦克风， 否则开启所有麦克风
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAllMute
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  BOOL_T                  bMuteAll
);

/**
* 开启轮巡  \n
* @param [IN]    pstUserLogIDInfo              用户信息标识
* @param [IN]    idConfId                      会议ID
* @param [IN]    ulTurnMode                    轮巡模式  MC_CONF_TURN_BROADCAST_MODE_EX_E
* @param [IN]    bCycle                        BOOL_TRUE, 进行轮巡, 否则不轮巡
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTurnBroadcast
(
    IN  USER_LOGIN_ID_INFO_S              *pstUserLogIDInfo,
    IN  IMOS_ID                           idConfId,
    IN  ULONG_32                             ulTurnMode,
    IN  BOOL_T                            bCycle
);

/**
* 停止/发送所有视频
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    bSendAllVideo           BOOL_TRUE表示发送所有视频， 否则停止所有视频
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 获取会议轮巡列表
* @param [IN]      pstUserLogIDInfo        用户信息标识
* @param [IN]      idConfId                会议ID
* @param [OUT]     pulCycleTime            轮巡时间间隔，单位秒
* @param [IN][OUT] pulCycleTermCount       会议轮巡列表终端个数
* @param [OUT]     pstCycleTermList        会议轮巡列表终端列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 设置轮巡配置
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    ulCycleTime             轮巡时间间隔，单位秒
* @param [IN]    ulCycleTermCount        会议轮巡列表终端个数
* @param [IN]    pstCycleTermList        会议轮巡列表终端列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 获取横幅
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstBanner               横幅结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetBanner
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    OUT HD_BANNER_INFO_EX_S     *pstBanner
);

/**
* 设置横幅
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstBanner               横幅结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBanner
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  HD_BANNER_INFO_EX_S     *pstBanner
);

/**
* 获取字幕
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstTitle                字幕结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTitle
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    OUT HD_TITLE_INFO_EX_S      *pstTitle
);

/**
* 设置字幕
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstTitle                字幕结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTitle
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  HD_TITLE_INFO_EX_S      *pstTitle
);

/**
* 获取画面模式
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstShowMode             画面模式
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 包括单画面和多画面两个视图，其中单画面可以看作多画面的0号子画面。对于多画面而言，\n
*       它包括小画面位置、小画面显示类型（主席、发言人、其它会场、激励、轮巡等）。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPicMode
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  IMOS_ID                       idConfId,
    OUT MC_SET_PIC_MODE_MSG_EX_S      *pstShowMode
);

/**
* 设置画面模式
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstShowMode             画面模式
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 包括单画面和多画面两个视图，其中单画面可以看作多画面的0号子画面。对于多画面而言，\n
*       它包括小画面位置、小画面显示类型（主席、发言人、其它会场、激励、轮巡等）。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPicMode
(
    IN  USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN  IMOS_ID                       idConfId,
    IN  MC_SET_PIC_MODE_MSG_EX_S      *pstShowMode
);

/**
* 获取会议边框。画面的边框设置,包括设置主席、发言人、其它会场边框颜色、边框粗细。
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstConferenceFrame      会议边框结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConferenceFrame
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    OUT MC_CONF_FRAME_EX_S      *pstConferenceFrame
);

/**
* 设置会议边框。画面的边框设置,包括设置主席、发言人、其它会场边框颜色、边框粗细。
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstConferenceFrame      会议边框结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetConferenceFrame
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  MC_CONF_FRAME_EX_S      *pstConferenceFrame
);

/**
* 获取会议颜色组
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstColorInfo            颜色组信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetConferenceColorGroup
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  IMOS_ID                    idConfId,
    OUT MC_CONF_COLOR_INFO_EX_S    *pstColorInfo
);

/**
* 设置会场名模式: 是否显示会场名， 会场名的位置、字体、大小、颜色等信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstShowSiteName         会场名显示属性
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetShowSiteNameMode
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  IMOS_ID                    idConfId,
    IN  HD_SITE_NAME_INFO_EX_S     *pstShowSiteName
);

/**
* 获取会场名模式: 是否显示会场名， 会场名的位置、字体、大小、颜色等信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstShowSiteName         会场名显示属性
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetShowSiteNameMode
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  IMOS_ID                    idConfId,
    OUT HD_SITE_NAME_INFO_EX_S     *pstShowSiteName
);

/**
* 设置会控参数
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    pstCtrlInfo             会控参数
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetConfCtrlInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  MC_CONF_CTRL_INFO_EX_S   *pstCtrlInfo
);

/**
* 获取会控参数
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   pstCtrlInfo             会控参数
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 添加会场
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szDevCode               MCU设备编码， 可以为空。 当为空的时候， 表示自动为会场选择合适的MCU
* @param [IN]    szSiteCode              会场编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szDevCode[IMOS_RES_CODE_LEN],
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* 删除会场
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* 呼叫/挂断会场
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bCallSite               BOOL_TRUE表示呼叫会场， 否则挂断会场
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CallSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bCallSite
);

/**
* 同意发言申请。 没有收到同意发言的终端， 则默认其发言申请被拒绝
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bAgree                  是否同意发言， BOOL_TRUE 表示同意
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AcceptSpeakReq
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bAgree
);


/**
* 获取发言申请列表。
* @param [IN]      pstUserLogIDInfo        用户信息标识
* @param [IN]      idConfId                会议ID
* @param [IN][OUT] pulTermCount            会场个数
* @param [OUT]     pstTermList             会场列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSpeakReqList
(
    IN    USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN    IMOS_ID                 idConfId,
    INOUT ULONG_32                   *pulTermCount,
    OUT   MC_CONF_SITE_NAME_EX_S  *pstTermList
);


/**
* 关闭/开启某终端扬声器。 关闭麦克风， 即静音
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bSilenceOne                BOOL_TRUE表示关闭某终端扬声器， 否则开启某终端扬声器
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteSilence
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSilenceOne
);

/**
* 关闭/开启某终端麦克风。 关闭麦克风， 即闭音
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bMuteOne                BOOL_TRUE表示关闭某终端麦克风， 否则开启某终端麦克风
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteMute
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bMuteOne
);

/**
* 广播某终端。 广播某终端即广播图像
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBroadcastSite
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* 打开/取消会场视频
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bOpenSiteVideo          BOOL_TRUE表示打开会场视频， 否则取消会场视频
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenSiteVideo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bOpenSiteVideo
);

/**
* 设置/取消主席
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bSetSiteChair           BOOL_TRUE表示设置主席， 否则取消主席
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteChair
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSetSiteChair
);

/**
* 设置/取消设置会场为FECC控制者。Far End Camera Control，远程摄像机控制，\n
* 指将本地摄像机的控制信号通过网络传送到远端摄像机并实现对远端摄像机的控制   \n
* FECC控制者 控制 FECC受控者会场的摄像机
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bSetSiteFECCController  BOOL_TRUE表示设置设置会场为FECC控制者， 否则取消设置会场为FECC控制者
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteFECCController
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSetSiteFECCController
);

/**
* 设置/取消第二路视频源。设置第二路视频源，把终端指定为双流发送者
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [IN]    bSetSecondVideoRes      BOOL_TRUE表示设置第二路视频源， 否则取消设置第二路视频源
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSecondVideoRes
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    IN  BOOL_T                  bSetSecondVideoRes
);

/**
* 获得会场通道信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [OUT]   pstSiteChannelInfo      会场通道信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSiteChannel
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_SITE_CAP_SET_EX_S    *pstSiteChannelInfo
);

/**
* 获得会议中单个会场的信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [OUT]   pstSiteInfo             会场信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSiteInfo
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_SITE_INFO_EX_S       *pstSiteInfo
);

/**
* 获得单个会场的入会状态
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [OUT]   pulStatus               会场状态 MC_SITE_STATUS_EX_E
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTermStatus
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  IMOS_ID                 idConfId,
    IN  CHAR                    szSiteCode[IMOS_RES_CODE_LEN],
    OUT ULONG_32                   *pulStatus
);

/*************************************************************************************
SS 公安部双链路备份特性
***************************************************************************************/

/**
* 开启/取消终端告警。 公安部双链路备份特性
* @param [IN]    pstUserLogIDInfo             用户信息标识
* @param [IN]    idConfId                     会议ID
* @param [IN]    ulAlarmCount                 需要告警的会场总数， 最大数目IMOS_MAX_SITE_LIVE_NUM
* @param [IN]    pstAlarmSiteList             需要告警的会场列表
* @param [IN]    bStartAlarmOfTerminal        BOOL_TRUE表示开启终端告警， 否则取消终端告警
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 设置会场链路切换模式 公安部双链路备份特性
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议编码
* @param [IN]    szSiteCode              会场编码
* @param [IN]    pstSwitchCfg            会场链路切换模式
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSiteLayerSwitchMode
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN],
    IN  MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S *pstSwitchCfg
);

/**
* 获取会场链路切换模式 公安部双链路备份特性
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议编码
* @param [IN]    szSiteCode              会场编码
* @param [OUT]   pstSwitchCfg            会场链路切换模式
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetSiteLayerSwitchMode
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S *pstSwitchCfg
);

/**
* 恢复主用链路状态至高带宽稳定状态 \n
* 启用主备链路后，当链路出现丢包，MCU会要求降低通话的带宽（低带宽稳定），\n
* 当丢包没有后，通过本函数，使通话恢复到先前的高带宽（高带宽稳定状态）
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [OUT]   szSiteCode              站点编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResumeMainLayer
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN]
);

/**
* 获取终端双链路信息 公安部双链路备份特性
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @param [OUT]   pstLinkInfo             终端双链路信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetTermLinkInfo
(
    IN  USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN  IMOS_ID                  idConfId,
    IN  CHAR                     szSiteCode[IMOS_RES_CODE_LEN],
    OUT MC_LINK_INFO_EX_S        *pstLinkInfo
);


/**
* 导演模式下， 为主场选择观看会场；主席模式下， 为主席选择观看会场
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idConfId                会议ID
* @param [IN]    szSiteCode              会场编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS MCU设备配置
***************************************************************************************/

/** @defgroup groupMCUConfig MCU设备配置
*   MCU设备配置
*   @{
*/

/**
* 设置GK
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    ulGKType                GK内嵌 MC_GK_TYPE_EX_E
* @param [IN]    szGKIP                  外部GK的IP地址
* @param [IN]    szMCUAlias              MCU别名
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 获取GK
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pulGKType               GK内嵌 MC_GK_TYPE_EX_E
* @param [OUT]   szGKIP                  外部GK的IP地址
* @param [OUT]   *pulGKRegState          GK的注册状态
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 设置NAT
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    pstNATCfg               NAT配置结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetNAT
(
    IN  USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN  CHAR                       szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  MC_MCU_CONFIG_NAT_EX_S     *pstNATCfg
);

/**
* 获取NAT
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstNATCfg               NAT配置结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetNAT
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_CONFIG_NAT_EX_S  *pstNATCfg
);

/**
* 设置MCU的QOS服务
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    pstQosCfg               Qos配置结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMCUQos
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  HD_QOS_SERV_EX_S        *pstQosCfg
);

/**
* 获取MCU的QOS服务
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstQosCfg               Qos配置结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCUQos
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT HD_QOS_SERV_EX_S        *pstQosCfg
);

/**
* 设置MCU运行模式
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    pstMcuRunMode           MCU运行模式信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMCURunMode
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  HA_SYSTEM_INFO_EX_S     *pstMcuRunMode
);

/**
* 获取MCU运行模式
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstMcuRunMode           MCU运行模式信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCURunMode
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT HA_SYSTEM_INFO_EX_S     *pstMcuRunMode
);

/**
* 获取MCU别名
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   szMCUName               MCU名称
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCUName
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT CHAR                    szMCUName[IMOS_MCU_NAME_LEN]
);

/**
* 设置MCU网络地址
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    ulNetID                 网口标识(0 ~ 3)
* @param [IN]    pstIPInfo               网口的IP地址
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMCULanIP
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  ULONG_32                   ulNetID,
    IN  MC_NET_STATUS_EX_S      *pstIPInfo
);

/**
* 获取MCU网络地址
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstIpCfg                MCU的IP信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCULanIP
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  CHAR                    szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_IP_CFG_S         *pstIpCfg
);

/**
* 修改网口路由表
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    pstConfigRoute          路由信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMCULanRoute
(
    IN  USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN  CHAR                           szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  MC_CONFIG_ROUTE_MSG_EX_S       *pstConfigRoute
);

/**
* 获取路由表
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstRouteInfo            网络Route表信息结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCULanRouteInfo
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_LAN_ROUTE_TABLE_EX_S         *pstRouteInfo
);

/**
* 获取ARP表
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstARPInfo              网络ARP表信息结构
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMCUARPInfo
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT MC_MCU_ARP_TABLE_EX_S               *pstARPInfo
);

/**
* 设置声光告警配置消息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    szIpAddress             声光告警服务器地址
* @param [IN]    ulPower1AlarmID         电源1掉电声光告警号
* @param [IN]    ulPower2AlarmID         电源2掉电声光告警号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 获取声光告警配置
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   szIpAddress             声光告警服务器地址
* @param [OUT]   pulPower1AlarmID        电源1掉电声光告警号
* @param [OUT]   pulPower2AlarmID        电源2掉电声光告警号
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS 公安部双链路备份特性
***************************************************************************************/

/**
* 设置备份链路策略的 IP 配置 公安部双链路备份特性
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [IN]    pstIPInfo               备份链路策略的 IP 配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBackupLinkLayerIPCfg
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CHAR                        szDevCode[IMOS_DEVICE_CODE_LEN],
    IN  MC_BACKUP_LAYER_IP_CFG_EX_S *pstIPInfo
);

/**
* 获取备份链路策略的 IP 配置 公安部双链路备份特性
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szDevCode               设备编码
* @param [OUT]   pstIPInfo               备份链路策略的 IP 配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 设置颜色组。 颜色组为全局配置， 配置到所有的MCU。 \n
* 系统缺省提供了6组（每组4色+16色）颜色选项为各会场使用，其中4色为字幕的颜色选项， \n
* 16色为横幅、会场名以及各边框的颜色选项。如果系统提供的6组颜色选项不满足需要，    \n
* 可以在这里对颜色选项进行自定义设置。系统缺省值，不能修改。
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    lGroupID                组ID
* @param [IN]    astGroupIn16ColorT      16色
* @param [IN]    astGroupIn4ColorT       4色
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetColorGroupValue
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  LONG_32                    lGroupID,
    IN  HD_COLOR_VALUE_EX_S     astGroupIn16ColorT[IMOS_EN_COLOR_TABLE16_TYPE_COUNT],
    IN  HD_COLOR_VALUE_EX_S     astGroupIn4ColorT[IMOS_EN_COLOR_TABLE4_TYPE_COUNT]
);

/**
* 获取颜色组。 颜色组为全局配置， 配置到所有的MCU。\n
* 系统缺省提供了6组（每组4色+16色）颜色选项为各会场使用，其中4色为字幕的颜色选项， \n
* 16色为横幅、会场名以及各边框的颜色选项。如果系统提供的6组颜色选项不满足需要，    \n
* 可以在这里对颜色选项进行自定义设置。系统缺省值，不能修改。
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [OUT]   astGroupIn16ColorT      16色
* @param [OUT]   astGroupIn4ColorT       4色
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS 联系人管理
***************************************************************************************/

/** @defgroup groupConfContactMgr 联系人管理
*   联系人管理
*   @{
*/

/**
* 增加联系人信息，此信息中包含联系人ID，唯一索引
* @param [IN]      pstUserLogIDInfo        用户信息标识
* @param [IN]      pstContactInfo          联系人信息
* @param [OUT]     pidContactId            联系人ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddContact
(
    IN    USER_LOGIN_ID_INFO_S       *pstUserLogIDInfo,
    IN    CONF_CONTACT_INFO_EX_S     *pstContactInfo,
    OUT   IMOS_ID                    *pidContactId
);

/**
* 修改联系人信息，其中联系人ID不可修改，但是需要带入
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    pstContactInfo          联系人信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyContact
(
    IN  USER_LOGIN_ID_INFO_S        *pstUserLogIDInfo,
    IN  CONF_CONTACT_INFO_EX_S      *pstContactInfo
);

/**
* 删除联系人
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    idContactId             联系人ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelContact
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   IMOS_ID                        idContactId
);

/**
* 查询某个联系人的信息
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    idContactId                 联系人ID
* @param [OUT]   pstContactInfo              联系人信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryContactInfo
(
    IN   USER_LOGIN_ID_INFO_S           *pstUserLogIDInfo,
    IN   IMOS_ID                        idContactId,
    OUT  CONF_CONTACT_INFO_EX_S         *pstContactInfo
);

/**
* 查询联系人列表 \n
* 支持按名字模糊查询。pstName允许为空，表示该条件无效，否则按名字进行模糊查询
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    pstName                     按名字模糊查询信息条件
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstContactList              联系人查询信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
 * 设备-MG视讯终端
*******************************************************************************/

/** @defgroup groupMGMgr 终端管理
*   终端（包括第三方终端）管理
*   @{
*/

/**
* 添加MG视讯终端
* 包含设备编码、设备名称、设备型号、E.164号码等基本信息
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szTerminalCode              MG视讯终端编码
* @param [IN]    pstTerminalBaseInfo         MG视讯终端基本信息
* @param [IN]    pstTerminalRestrictCapacity MG视讯终端的限制能力集
* @param [IN]    pstTerminalconfig           MG视讯终端常用参数
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note H3C设备仅需设置pstTerminalBaseInfo，其他设置可选。 第三方设备需要全部设置
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
* 修改MG视讯终端的基本信息
* 其中设备编码不可能修改，但是需要带入。
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szTerminalCode              MG视讯终端编码
* @param [IN]    pstTerminalBaseInfo         MG视讯终端基本信息
* @param [IN]    pstTerminalRestrictCapacity MG视讯终端的限制能力集
* @param [IN]    pstTerminalconfig           MG视讯终端常用参数
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note H3C设备仅需设置pstTerminalBaseInfo，其他设置可选。 第三方设备需要全部设置
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
* 删除MG视讯终端
* @param [IN]  pstUserLogIDInfo              用户信息标识
* @param [IN]  szTerminalCode                MG视讯终端编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTerminal
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTerminalCode[IMOS_DEVICE_CODE_LEN]
);


/**
* 查询单个MG视讯终端的基本信息
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szTerminalCode              MG视讯终端编码
* @param [OUT]   pulRegistered               MG视讯终端是否注册过
* @param [OUT]   pstTerminalBaseInfo         MG视讯终端基本信息
* @param [OUT]   pstTerminalOriginalCapacity MG视讯终端的原始能力集
* @param [OUT]   pstTerminalRestrictCapacity MG视讯终端的限制能力集
* @param [OUT]   pstTerminalconfig           MG视讯终端常用参数
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 查询单个第三方MG视讯终端的基本信息
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szTerminalCode              MG视讯终端编码
* @param [OUT]   pstTerminalBaseInfo         MG视讯终端基本信息
* @param [OUT]   pstTerminalInfo             MG视讯终端详细信息
* @param [OUT]   pstTerminalconfig           MG视讯终端常用参数
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 查询某个组织下的MG视讯终端列表
* 支持按名字模糊查询。pstName允许为空，表示该条件无效，否则按名字进行模糊查询
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szOrgCode                   组织域编码
* @param [IN]    bContainSubOrg              是否包含子组织。查询条件: 按照名称查找的时候， 是否查找子组织。
* @param [IN]    ulTermQueryType             查询终端类型 TERM_QUERY_TYPE_E
* @param [IN]    pstName                     按名字模糊查询信息条件， 为空则查询全部
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstTerminalList             MG视讯终端信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
设备-MCU视讯终端
*******************************************************************************/

/** @defgroup groupMCUMgr MCU管理
*   MCU的增删改查
*   @{
*/

/**
* 添加MCU设备 \n
* 包含设备编码、设备备份类型等基本信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    pstMcuBaseInfo          MCU基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddMcu
(
    IN    USER_LOGIN_ID_INFO_S     *pstUserLogIDInfo,
    IN    MCU_BASE_INFO_EX_S       *pstMcuBaseInfo
);

/**
* 修改MCU设备 \n
* 包含设备编码、设备备份类型等基本信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    pstMcuBaseInfo          MCU基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyMcu
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    MCU_BASE_INFO_EX_S            *pstMcuBaseInfo
);


/**
* 查询MCU设备 \n
* 包含设备编码、设备备份类型等基本信息
* @param [IN]    pstUserLogIDInfo        用户信息标识
* @param [IN]    szMcuCode               MCU设备编码
* @param [OUT]   pstMcuBaseInfo          MCU基本信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryMcu
(
    IN    USER_LOGIN_ID_INFO_S          *pstUserLogIDInfo,
    IN    CHAR                          szMcuCode[IMOS_DEVICE_CODE_LEN],
    OUT   MCU_BASE_INFO_EX_S            *pstMcuBaseInfo
);


/**
* 删除MCU设备
* @param [IN]  pstUserLogIDInfo              用户信息标识
* @param [IN]  szMcuCode                     MCU设备编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMcu
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMcuCode[IMOS_DEVICE_CODE_LEN]
);



/**
* 查询某个组织下的MCU设备列表 \n
* 支持按名字模糊查询。pstName允许为空，表示该条件无效，否则按名字进行模糊查询
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szOrgCode                   组织域编码
* @param [IN]    bContainSubOrg              是否包含子组织。 查询条件: 按照名称查找的时候， 是否查找子组织。
* @param [IN]    pstName                     按名字模糊查询信息条件
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstMcuList                  MCU设备信息数组
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS  会议管理
*******************************************************************************/

/** @defgroup groupConfMgr 会议管理
*   预约会议、活动会议、历史会议、会议模板管理
*   @{
*/

/**
* 查询活动会议信息列表
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szOrgCode                   组织编码
* @param [IN]    pstName                     按名字模糊查询信息条件
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstConfList                 会议信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 查询某个组织下的预约会议信息列表
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szOrgCode                   组织编码
* @param [IN]    pstName                     按名字模糊查询信息条件
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstConfList                 会议信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 查询历史会议信息列表。 历史会议不归属组织。否则组织删除， 需要同时删除历史会议。
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    pstQueryCondition           查询信息条件
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstConfList                 会议信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 支持的查询排序条件包括:#NAME_TYPE[历史会议名称];
*                              #CONF_START_TIME[会议开始时间];
*                              #CONF_END_TIME[会议结束时间];
*                              #USER_NAME_TYPE[会议创建者]
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
* 查询会议模板列表
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    pstName                     按名字模糊查询信息条件
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstConfTempList             会议模板列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* 创建会议
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   pstConfInfo             会议信息
* @param [IN]   ulConfTermCount         会议终端个数
* @param [IN]   pstConfTermList         会议终端列表
* @param [IN]   ulMcuCount              会议MCU个数
* @param [IN]   pstMcuList              会议MCU列表
* @param [IN]   ulCycleTermCount        会议轮巡列表终端个数
* @param [IN]   pstCycleTermList        会议轮巡列表终端列表 多个列表， 按照编号顺序从小到大填写； 同一列表， 按照下标顺序从小到大填写
* @param [IN]   ulContactCount          联系人个数
* @param [IN]   pidContactList          联系人列表
* @param [OUT]  pidConfId               会议ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note  直接调用 不提供自动调度 开始创建会议
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
* 获取会议信息
* @param [IN]      pstUserLogIDInfo       用户信息标识
* @param [IN]      idConfId               会议ID
* @param [OUT]     pstConfInfo            会议信息
* @param [IN][OUT] pulConfTermCount       会议终端列表缓存大小,会议终端个数
* @param [OUT]     pstConfTermList        会议终端列表
* @param [IN][OUT] pulMcuCount            MCU列表缓存大小,会议MCU个数
* @param [OUT]     pstMcuList             会议MCU列表
* @param [IN][OUT] pulCycleTermCount      轮巡列表缓存大小，会议轮巡列表终端个数
* @param [OUT]     pstCycleTermList       会议轮巡列表终端列表
* @param [IN][OUT] pulContactCount        联系人列表缓存大小，联系人个数
* @param [OUT]     pstContactList         联系人列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 只能删除未召开会议
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
* 获取历史会议信息
* @param [IN]      pstUserLogIDInfo       用户信息标识
* @param [IN]      idConfId               会议ID
* @param [OUT]     pstConfInfo            会议信息
* @param [IN][OUT] ulConfTermCount        会议终端列表缓存大小,会议终端个数
* @param [OUT]     pstConfTermList        会议终端列表
* @param [IN][OUT] pulMcuCount            MCU列表缓存大小,会议MCU个数
* @param [OUT]     pstMcuList             会议MCU列表
* @param [IN][OUT] pulCycleTermCount      轮巡列表缓存大小，会议轮巡列表终端个数
* @param [OUT]     pstCycleTermList       会议轮巡列表终端列表
* @param [IN][OUT] pulContactCount        联系人列表缓存大小，联系人个数
* @param [OUT]     pstContactList         联系人列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 会议混音终端列表 会议语音激励列表 会议接收字幕终端列表 为NULL, 现不实现
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
* 修改会议
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   idConfId                会议ID
* @param [IN]   pstConfInfo             会议信息
* @param [IN]   ulConfTermCount         会议终端个数
* @param [IN]   pstConfTermList         会议终端列表
* @param [IN]   ulMcuCount              会议MCU个数
* @param [IN]   pstMcuList              会议MCU列表
* @param [IN]   ulCycleTermCount        会议轮巡列表终端个数
* @param [IN]   pstCycleTermList        会议轮巡列表终端列表 多个列表， 按照编号顺序从小到大填写； 同一列表， 按照下标顺序从小到大填写
* @param [IN]   ulContactCount          联系人个数
* @param [IN]   pidContactList          联系人列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 会议混音终端列表 会议语音激励列表 会议接收字幕终端列表 为NULL, 现不实现
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
* 删除会议
* @param [IN]  pstUserLogIDInfo              用户信息标识
* @param [IN]  idConfId                      会议ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 只能删除预约会议
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteConference
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IMOS_ID                         idConfId
);

/**
* 创建会议模板信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   pstConfTempInfo         会议模板信息
* @param [IN]   ulConfTermCount         会议终端个数
* @param [IN]   pstConfTermList         会议终端列表
* @param [IN]   ulCycleTermCount        会议轮巡列表终端个数
* @param [IN]   pstCycleTermList        会议轮巡列表终端列表。 多个列表， 按照编号顺序从小到大填写； 同一列表， 按照下标顺序从小到大填写
* @param [IN]   ulContactCount          联系人个数
* @param [IN]   pidContactList          联系人列表
* @param [OUT]  pidConfTempId           会议模板ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note   会议混音终端列表 会议语音激励列表 会议接收字幕终端列表 为NULL, 现不实现
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
* 获取会议模板信息
* @param [IN]      pstUserLogIDInfo       用户信息标识
* @param [IN]      idConfTempId           会议模板ID
* @param [IN]      pstConfTempInfo        会议模板信息
* @param [IN][OUT] ulConfTermCount        会议终端列表缓存大小,会议终端个数
* @param [OUT]     pstConfTermList        会议终端列表
* @param [IN][OUT] pulCycleTermCount      轮巡列表缓存大小，会议轮巡列表终端个数
* @param [OUT]     pstCycleTermList       会议轮巡列表终端列表
* @param [IN][OUT] pulContactCount        联系人列表缓存大小，联系人个数
* @param [OUT]     pstContactList         联系人列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 会议混音终端列表 会议语音激励列表 会议接收字幕终端列表 为NULL, 现不实现
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
* 修改会议模板信息
* @param [IN]   pstUserLogIDInfo        用户信息标识
* @param [IN]   idConfTempId            会议模板ID
* @param [IN]   pstConfTempInfo         会议模板信息
* @param [IN]   ulConfTermCount         会议终端个数
* @param [IN]   pstConfTermList         会议终端列表
* @param [IN]   ulCycleTermCount        会议轮巡列表终端个数
* @param [IN]   pstCycleTermList        会议轮巡列表终端列表
* @param [IN]   ulContactCount          联系人个数
* @param [IN]   pidContactList          联系人列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 会议混音终端列表 会议语音激励列表 会议接收字幕终端列表 为NULL, 现不实现
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
* 删除会议模板
* @param [IN]  pstUserLogIDInfo              用户信息标识
* @param [IN]  idConfTempId                  会议模板ID
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeleteConfTemp
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  IMOS_ID                         idConfTempId
);


/**
* 获取推荐级联信息
* @param [IN]  pstUserLogIDInfo                  用户信息标识
* @param [IN]  pstConfInfo                       会议信息
* @param [IN]  ulConfTermCount                   会议终端个数
* @param [IN]  pstConfTermList                   会议终端列表
* @param [IN][OUT] pulConfTermCasteCount         带归属关系会议终端个数
* @param [OUT] pstConfTermCasteList              带归属关系会议终端列表
* @param [IN][OUT] pulMcuCount                   会议MCU个数
* @param [OUT] pstMcuList                        带级联关系会议MCU列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件sdk_err.h
* @note 无
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
SS 统计信息
***************************************************************************************/

/** @defgroup groupConfReport 会议报表
*   提供报表查询功能
*   @{
*/

/**
* 会场入会时间报表
* @param [IN]    pstUserLogIDInfo            用户信息标识
* @param [IN]    szOrgCode                   组织编码
* @param [IN]    bContainSubOrg              是否包含子组织。 查询条件: 按照名称查找的时候， 是否查找子组织。
* @param [IN]    lStartTime                  统计开始时间
* @param [IN]    lEndTime                    统计结束时间
* @param [IN]    pstName                     按名字模糊查询信息条件 为空查询所有
* @param [IN]    pstQueryPageInfo            请求分页信息
* @param [OUT]   pstRspPageInfo              返回分页信息
* @param [OUT]   pstTerminalInConfInfoList   会议终端入会时间统计信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
* MCU的会议数与会议终端数报表
* @param [IN]      pstUserLogIDInfo        用户信息标识
* @param [IN]      szMcuCode               MCU设备编码
* @param [IN]      lStartTime              统计开始时间
* @param [IN]      lEndTime                统计结束时间
* @param [IN]      ulSampleType            采样间隔: CONF_REPORT_SAMPLE_TYPE_E
* @param [IN][OUT] pulConfStatInfoCount    统计个数
* @param [OUT]     pstConfStatInfoList     MCU的会议数与会议终端数统计信息列表
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS 地址簿管理
***************************************************************************************/

/** @defgroup groupMGMgr 终端管理
*   终端管理
*   @{
*/

/**
* iMSC向终端导入地址簿消息
* @param [IN]      pstUserLogIDInfo             用户信息标识
* @param [IN]      szDevCode                    设备编码
* @param [IN]      pstAddrBookItem              地址簿记录
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS 设备面板 使用最小MIB实现
***************************************************************************************/

/** @defgroup groupDevPanel 设备面板
*   设备面板
*   @{
*/

/**
* 获取设备性能信息
* @param [IN]     pstUserLogIDInfo             用户信息标识
* @param [IN]     szDevCode                    设备编码
* @param [OUT]    pstPerformanceInfo           设备性能信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDevicePerformanceInfo
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDevCode[IMOS_DEVICE_CODE_LEN],
    OUT DEVICE_PERFORMANCE_INFO_S       *pstPerformanceInfo
);

/**
* 获取设备端口相关的信息
* @param [IN]     pstUserLogIDInfo             用户信息标识
* @param [IN]     szDevCode                    设备编码
* @param [OUT]    pstDevicePortInfo            设备端口信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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
SS 邮件服务器的配置管理
***************************************************************************************/

/** @defgroup groupEmailMgr 邮件服务器配置
*   邮件服务器配置
*   @{
*/

/**
* 获取邮件发送的配置
* @param [IN]    pstUserLogIDInfo             用户信息标识
* @param [OUT]   pstEmailSendingConfig        Email发送相关的配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* 设置邮件发送的配置
* @param [IN]    pstUserLogIDInfo             用户信息标识
* @param [IN]    pstEmailSendingConfig        Email发送相关的配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetEmailSendingConfig
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);

/**
* 获取邮件发送规则
* @param [IN]    pstUserLogIDInfo             用户信息标识
* @param [OUT]   pstRules                     Email发送规则
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetEmailSendingRules
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    OUT EMAIL_SENDING_RULES_S        *pstRules
);

/**
* 设置邮件发送规则
* @param [IN]    pstUserLogIDInfo             用户信息标识
* @param [IN]    pstRules                     Email发送规则
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetEmailSendingRules
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_RULES_S        *pstRules
);


/**
* 发送测试邮件， 验证邮件发送的配置是否正确
* @param [IN]    pstUserLogIDInfo             用户信息标识
* @param [OUT]   pstEmailSendingConfig        Email发送相关的配置
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_TestToSendEmail
(
    IN  USER_LOGIN_ID_INFO_S         *pstUserLogIDInfo,
    IN  EMAIL_SENDING_CONFIG_S       *pstEmailSendingConfig
);


/*************************************************************************************
SS 设备批量配置
***************************************************************************************/

/**
* 获取FTP信息
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [OUT]  pstFtpInfo          返回FTP服务信息
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFTPInfo
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    OUT FTP_INFO_S *pstFtpInfo
);

/**
* 获取一个唯一文件名路径（用户编码 + 日期时间 + 随机数）
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   ulFileType          文件类型  对应枚举：IMOS_FTP_FILE_TYPE_E
* @param [OUT]  szUniqueFilePath    在文件类型对应目录路径下生成一个唯一文件名路径
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetUniqueFilePath
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN ULONG_32 ulFileType,
    OUT CHAR szUniqueFilePath[IMOS_FILE_PATH_LEN]
);

/**
* 从服务器下发文件给终端
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   szDevCode           终端编码
* @param [IN]   szFilePath          文件在服务器的路径（源文件路径）
* @param [IN]   szDevFilePath       文件在设备上的路径（目的文件路径），对于视讯设备的配置文件，由视讯侧定义，需要填充为（config）
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
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
* 从终端获取文件到服务器
* @param [IN]   pstUserLogIDInfo    用户信息标识
* @param [IN]   szDevCode           终端编码
* @param [IN]   ulFileType          文件类型 对应枚举：IMOS_FTP_FILE_TYPE_E
* @param [IN]   szDevFilePath       文件在设备的路径（源文件路径），对于视讯设备的配置文件，由视讯侧定义，需要填充为（config）
* @param [IN][OUT] szSrvFilePath 文件在服务器的路径（目的文件路径）
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 如果存放在服务器的目的文件路径不指定（空字符串），就由服务器自动生成，根据文件类型选择文件存放目录路径
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
* 手工同步设备
* @param [IN] pstUserLogIDInfo  用户信息标识
* @param [IN] szDevCode         设备编码
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ManualSyncDev
(
    IN USER_LOGIN_ID_INFO_S *pstUserLogIDInfo,
    IN CHAR szDevCode[IMOS_DEVICE_CODE_LEN]
);

/**
* 指定会场选择观看会场
* @param [IN]    pstUserLogIDInfo       用户信息标识
* @param [IN]    idConfId               会议ID
* @param [IN]    szBrowseSiteCode       观看会场编码
* @param [IN]    szBrowsedSiteCode      被观看会场编码
* @param [IN]    bCancelBrowse          BOOL_TRUE取消选择观看,BOOL_FALSE设置取消观看
* @return 返回如下结果：
* - 成功：
* - 失败：
* -     返回操作结果码：见结果码文件
* @note 无
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

