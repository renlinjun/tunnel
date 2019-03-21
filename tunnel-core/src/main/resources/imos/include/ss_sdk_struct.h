/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              ss_sdk_struct.h

  Project Code: SDK
   Module Name: SDK
  Date Created: 2009-02-27
        Author: huangjun (00754)
                chenshangwu (07076)
   Description: 数据结构定义文档

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _SS_SDK_STRUCT_H_
#define _SS_SDK_STRUCT_H_

#ifdef  __cplusplus
extern "C"{
#endif

#pragma pack(4)

/*******************************************************************************
SS新增结构
*******************************************************************************/

/**
* @struct tagQueryByCond
* @brief 按条件进行模糊查询。
* @attention
*/
typedef struct tagQueryByCond
{
    /** 设备名称或资源名称。 如果名称为空， 则查询所有的记录 */
    CHAR    szName[IMOS_NAME_LEN];

    /** 开始时间。 如果开始时间和结束时间均为0， 则查询所有时间段的记录 */
    LONG_32    lStartTime;

    /** 结束时间 */
    LONG_32    lEndTime;

} QUERY_BY_COND_S;


/**
 * @struct tagTerminalTimeStatInfoEx
 * @brief  终端时间统计信息
 * @attention
 */
typedef struct tagTerminalTimeStatInfoEx
{

  /** 设备编码 */
  CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

  /** 设备名称 */
  CHAR  szDevName[IMOS_NAME_LEN];

  /** 时长*/
  ULONG_32        ulTimeDuration;
} TERMINAL_TIME_STAT_INFO_EX_S;

/**
 * @struct tagConfStatInfoEx
 * @brief  会议数统计信息
 * @attention
 */
typedef struct tagConfStatInfoEx
{
  /** 采样时间*/
  LONG_32         lSampleTime;

  /** 会议数*/
  ULONG_32        ulConfNumber;

  /** 会议终端数*/
  ULONG_32        ulTermNumber;
} CONF_STAT_INFO_EX_S;

/**
 * @struct tagVirtualTermResEx
 * @brief  虚拟终端资源信息
 * @attention
 */
typedef struct tagVirtualTermResEx
{
    /** 虚拟终端资源编码*/
    CHAR        szVirtualResCode[IMOS_RES_CODE_LEN];

    /** 终端E164号*/
    CHAR        szTermE164[IMOS_CONF_ALIAS_LEN];

    /** 终端别名*/
    CHAR        szTermAlias[IMOS_CONF_ALIAS_LEN];

    /** 虚拟监视器编码*/
    CHAR        szVirtualScreenCode[IMOS_RES_CODE_LEN];

    /** 虚拟摄像机编码*/
    CHAR        szVirtualCameraCode[IMOS_RES_CODE_LEN];

    /** 资源使用状态 枚举类型 MC_VIRTUAL_RES_STATUS_EX_E */
    ULONG_32       ulResStatus;
} VIRTUAL_TERM_RES_QURERY_ITEM_EX_S;

/**
* @struct tagMC_ConfBaseInfoEx
* @brief 会议简单结构
* @attention
*/
typedef struct tagMC_ConfBaseInfoEx
{
    /** 会议名称或会议模板名 */
    CHAR        szConfName[IMOS_CONF_NAME_LEN];

    /** 会议E164号码 */
    CHAR        szConfE164[IMOS_CONF_ALIAS_LEN];

    /** 会议创建者 */
    CHAR        szCreater[IMOS_NAME_LEN];

    /** 会议创建者的用户编码 */
    CHAR        szCreaterUserCode[IMOS_USER_CODE_LEN];

    /** 会议创建时间 创建时界面不需要填写，统一IMSC填写*/
    LONG_32        lCreateTime;

    /** 是否立即会议 */
    BOOL_T      bAtOnce;

    /** 是否永久会议(不设结束时间) */
    BOOL_T      bConfForever;

    /** 会议召开时间 */
    LONG_32        lStartTime;

    /** 会议时长，单位为秒 */
    LONG_32        lDuration;

    /** 会议描述 */
    CHAR        szDescribe[IMOS_DESC_LEN];

    /** 单画面纯转发 */
    BOOL_T      bPureTransmit;

    /** 打包方式适配 */
    BOOL_T      bPackageAdapt;
} MC_CONF_BASE_INFO_EX_S;

/**
* @struct tagMC_ConfReserveInfoEx
* @brief 预约会议信息
* @attention 第1次创建时不在周期中也创建成功，后续会议按周期内的有效期来开，周期会议时长不能超过24小时。
*/
typedef struct tagMC_ConfReserveInfoEx
{
    /** 周期会议类型  MC_CONF_CYCLE_TYPE_EX_E */
    ULONG_32                   ulCycleType;

    /** 重复日期, 用二进制位表示;
    如果周期类型为月, 则第0位表示1号, 依次递增, 第31位表示月末;
    如果周期类型为周, 则第0位表示星期一, 依次递增

    其中第0位是从最右边开始算的。
    举例:
    1、如果按周的话，代表周一/周二/周三召开会议应该是 0000....0000111 代表周二召开会议应该是 0000....0000010
    2、如果按月的话，代表1号2号开会应该是 0000....0000011 代表月末开会应该是 1000....0000000
    代表31号开会应该是 0100....0000000
    3、如果按天的话，lCycleDate没有意义
    */
    LONG_32                    lCycleDate;

    /** 重复次数1-10000 */
    ULONG_32                   ulCycleCount;

    /** 周期会议结束类型 MC_CONF_CYCLE_END_TYPE_EX_E */
    ULONG_32                   ulCycleEndType;

    /** 重复会议的开始日期 创建会议时不填写，以会议召开时间为准 */
    LONG_32                    lCycleBeginTime;

    /** 重复会议的截止日期，实际填写位截止日期 + 23:59:59 */
    LONG_32                    lCycleEndTime;
} MC_CONF_RESERVE_INFO_EX_S;


/**
* @struct tagMC_ConfAuthorityInfoEx
* @brief 会议入会权限设置
* @attention
*/
typedef struct tagMC_ConfAuthorityInfoEx
{
    /** 是否密码会议，密码非空时填BOOL_TRUE,否则填BOOL_FALSE */
    BOOL_T           bSecret;

    /** 入会密码 */
    CHAR             szPwd[IMOS_CONF_PWD_LEN];

    /** 匿名电话拨入支持，指是否启用匿名会场 */
    BOOL_T           bNameless;

    /** 会议锁定，指会控期间不允许新匿名会场呼入 */
    BOOL_T           bLocked;
} MC_CONF_AUTHORITY_INFO_EX_S;

/**
* @struct tagHD_BannerInfoEx
* @brief 横幅信息
* @attention
*/
typedef  struct  tagHD_BannerInfoEx
{
    /** BOOL_TRUE, 支持横幅 */
    BOOL_T                       bSupportBanner;

    /** 横幅内容 */
    CHAR                         szBannerInfo[IMOS_BANNER_LEN];

    /** 字体 HD_FONT_EX_E */
    ULONG_32                        ulFont;

    /** 字体大小 HD_FONT_SIZE_EX_E */
    ULONG_32                        ulFontSize;

    /** 字体颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32                        ulFontColor;

    /** 背景颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32                        ulBgColor;

    /** 横幅位置 HD_BANNER_POS_EX_E */
    ULONG_32                        ulBannerPos;

    /** 横幅是否隐藏 */
    BOOL_T                       bIsConceal;
} HD_BANNER_INFO_EX_S;


/**
* @struct tagHD_ConfShowTimerInfoEx
* @brief 会议时间显示的结构
* @attention
*/
typedef struct tagHD_ConfShowTimerInfoEx
{
    /** 时间显示类型 HD_CONF_SHOW_TIMER_TYPE_EX_E */
    ULONG_32   ulShowType;

    /** 字体颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32   ulFontColor;

    /** 背景颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32   ulBGColor;

    /** 字体类型 HD_FONT_EX_E */
    ULONG_32   ulFont;

    /** 字体大小 HD_FONT_SIZE_EX_E */
    ULONG_32   ulFontSize;

    /** 位置 HD_SITE_NAME_TIMER_POS_EX_E */
    ULONG_32   ulSitePos;
} HD_CONF_SHOW_TIMER_INFO_EX_S;

/**
* @struct tagHD_SiteNameInfoEx
* @brief 会场名显示结构
* @attention
*/
typedef struct tagHD_SiteNameInfoEx
{
    /** BOOL_TRUE, 支持会场名 */
    BOOL_T   bSupportSiteName;

    /** 是否显示会场名、显示MCU设置的会场名、显示终端自带会场名 HD_CONF_SHOW_SITE_NAME_EX_E */
    ULONG_32    ulSiteNameAble;

    /** 会场名颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32    ulNameColor;

    /** 背景颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32    ulBGColor;

    /** 会场名字体 HD_FONT_EX_E */
    ULONG_32    ulFont;

    /** 会场名字体大小 HD_FONT_SIZE_EX_E */
    ULONG_32    ulFontSize;

    /** 会场名位置 HD_SITE_NAME_TIMER_POS_EX_E，当会议支持横幅时，只能选择左下和右下位置 */
    ULONG_32    ulSitePos;
} HD_SITE_NAME_INFO_EX_S;

/**
* @struct tagMC_ConfFrameEx
* @brief 画面的边框设置,包括设置主席、发言人、其它会场边框颜色、边框粗细。
* @attention
*/
typedef struct tagMC_ConfFrameEx
{
    /** 边框粗细 HD_FRAME_THICK_TYPE_EX_E */
    ULONG_32         ulFrameThick;

    /** 主席边框颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32         ulChairColor;

    /** 发言人边框颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32         ulSpeakerColor;

    /** 其它会场边框颜色 HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32         ulOtherColor;
} MC_CONF_FRAME_EX_S;

/**
* @struct tagHD_TitleInfoEx
* @brief 字幕信息
* @attention 字幕时长和滚动次数二选1。
*/
typedef  struct  tagHD_TitleInfoEx
{
    /** 是否支持字幕: BOOL_TRUE, 支持字幕 */
    BOOL_T            bSupport;

    /** 字体 HD_FONT_EX_E  */
    ULONG_32             ulFont;

    /** 字体大小 HD_FONT_SIZE_EX_E  */
    ULONG_32             ulFontSize;

    /** 字体颜色 HD_COLOR_TABLE4_TYPE_EX_E */
    ULONG_32             ulFontColor;

    /** 背景设置 HD_COLOR_TABLE4_TYPE_EX_E */
    ULONG_32             ulBgColor;

    /** 字幕位置 HD_TITLE_POS_EX_E */
    ULONG_32             ulTitlePos;

    /** 字幕滚动速度 HD_TITLE_ROLL_SPEED_EX_E */
    ULONG_32             ulMoveSpeed;

    /** 字幕滚动方向 HD_TITLE_ROLL_DIRECTION_EX_E */
    ULONG_32             ulMoveDirection;

    /** 字幕滚动次数 */
    LONG_32              lRollNum;

    /** 字幕滚动时长 HD_TITLE_LAST_TIME_EX_E */
    ULONG_32             ulRollTimeLen;

    /** 字幕滚动结束方式 HD_TITLE_ROLL_END_TYPE_EX_E */
    ULONG_32             ulRollEndType;

    /** 字幕是否显示  */
    BOOL_T            bIsConceal;

    /** 是否多排字幕显示 */
    BOOL_T            bIsMoreRowDisplay;

    /** 字幕内容 */
    CHAR              szTitleBuff[IMOS_TITLE_LEN];
} HD_TITLE_INFO_EX_S;

/**
* @struct tagMC_MultiPicSiteShowModeInfoEx
* @brief 设置会场显示模式的信息结构:
* szSiteCode只在画面显示模式为指定会场时才有效; 当为指定会场且szSiteCode为空时，表示"无"，即该小画面位置不显示任何会场。
* 当画面显示模式为会议主席、发言人、语音激励、会场轮巡时由IMSC在会议属性中获取，SDK下发时会场编码为空;
* 当画面显示模式为自动填充时, 填充任意一个在线会场, SDK下发时会场编码为空
* @attention
*/
typedef struct tagMC_MultiPicSiteShowModeInfoEx
{
    /** 画面显示模式 MC_MULTI_PIC_ONE_PIC_EX_E */
    ULONG_32                    ulShowSite;

    /** 指定会场编码  不同"画面显示模式"有不同的意义 */
    CHAR                     szSiteCode[IMOS_RES_CODE_LEN];

    /** 指定会场名称 */
    CHAR                     szSiteName[IMOS_NAME_LEN];

    /** 当前会场编码 */
    CHAR                     szCurrSiteCode[IMOS_RES_CODE_LEN];

    /** 当前会场名称 */
    CHAR                     szCurrSiteName[IMOS_NAME_LEN];

    /** 对应在多分屏中,各小画面的编号 单画面的时候此项无效, 单分屏时填0 */
    LONG_32                     lSerialNum;

    /** 轮巡时所选的轮巡列表序号 MC_CYCLE_TABLE_INDEX_EX_E */
    ULONG_32                    ulCycleIndex;
} MC_MULTI_PIC_SITE_SHOW_MODE_EX_S;

/**
* @enum tagMC_MultiPicInfoEx
* @brief 多分屏信息结构
* @attention
*/
typedef struct tagMC_MultiPicInfoEx
{
    /** 是否多画面。BOOL_FALSE表示纯转发；由MCU根据其他条件判断，SDK下发时填BOOL_TRUE */
    BOOL_T                bMultiPic;

    /** 多分屏模式 HD_MULTIPIC_MODE_EX_E */
    ULONG_32                 ulMultiPic;

    /** 多分屏数 */
    LONG_32                  lMultiPicNum;

    /** 小画面位置、显示模式 */
    MC_MULTI_PIC_SITE_SHOW_MODE_EX_S   astSiteShowMode[IMOS_HD_MAX_SUBPIC_NUM];
} MC_MULTI_PIC_INFO_EX_S;


/**
* @struct tagMC_ConfPollModeEx
* @brief 会议轮巡模式
* @attention
*/
typedef  struct tagMC_ConfPollModeEx
{
    /** BOOL_TRUE, 进行轮巡, 否则不轮巡 */
    BOOL_T                           bCycle;

    /** 轮巡时间间隔,单位秒 MC_CYCLE_TIME_INTERVAL_EX_E */
    ULONG_32                            ulCycleTime;
} MC_CONF_POLL_MODE_EX_S;

/**
* @struct tagMC_ConfBaseAttrEx
* @brief 会议基本属性
* @attention
*/
typedef struct tagMC_ConfBaseAttrEx
{
    /** 协议类型,默认H323 MC_PROTOCOL_TYPE_EX_E */
    ULONG_32       ulProtocolType;

    /** 会议模式 MC_CONF_MODE_EX_E 目前实现导演和主席模式，激励模式已合并到导演模式中 */
    ULONG_32       ulConfMode;

    /** 最大多分屏数 HD_MULTI_PIC_NUM_EX_E */
    ULONG_32       ulMultiPicNum;

    /** 主场选择观看模式 MC_CHAIR_BROWSE_MODE_EX_E */
    ULONG_32       ulChairBrowseMode;

    /** 广播模式 MC_BROADCAST_MODE_EX_E */
    ULONG_32       ulBroadcastMode;

    /** 单分屏详细信息结构 小画面的编号无效 */
    MC_MULTI_PIC_SITE_SHOW_MODE_EX_S   stSinglePicInfo;

    /** 多分屏详细信息结构 */
    MC_MULTI_PIC_INFO_EX_S      stMultiPicInfo;

    /** BOOL_TRUE支持多画面自动切换, 否则不支持多画面自动切换 */
    BOOL_T                      bAutoMultiPic;

    /** 会议速率 HD_BITRATE_EX_E */
    ULONG_32                       ulBitRate;

    /** 离线重邀方式 MC_DROP_REINVITE_MODE_EX_E */
    ULONG_32                       ulReInvite;

    /** BOOL_TRUE支持自动降速，MCU未用到，填0 */
    BOOL_T                      bAutoRateAdjust;

    /** 会议主场轮巡信息结构 */
    MC_CONF_POLL_MODE_EX_S      stConfMainPoll;

    /** 会议广播轮巡信息结构 */
    MC_CONF_POLL_MODE_EX_S      stConfBroadPoll;
} MC_CONF_BASE_ATTR_EX_S;

/**
* @struct tagMC_ConfNormalInfo
* @brief 会议基本信息 iMSC扩展的
* @attention
*/
typedef struct tagMC_ConfNormalInfoEx
{
    /** 是否是iMSC创建的会议 */
    BOOL_T                       bConfIsImscCreate;

    /** 会议备份 */
    BOOL_T                       bAutoBackup;

    /** 级联类型 MC_CONF_CASCADE_TYPE_EX_E */
    ULONG_32                        ulCascadeType;

    /** 会议基本信息 */
    MC_CONF_BASE_INFO_EX_S       stConfBaseInfo;

    /** 预约会议信息 */
    MC_CONF_RESERVE_INFO_EX_S    stConfReserveInfo;

    /** 会议入会权限信息 */
    MC_CONF_AUTHORITY_INFO_EX_S  stConfAuthInfo;


    /** 会议横幅信息 */
    HD_BANNER_INFO_EX_S          stBannerInfo;

    /** 会议时间显示信息，此字段MCU没有用到，全填0  */
    HD_CONF_SHOW_TIMER_INFO_EX_S stTimerInfo;

    /** 会场名显示信息 */
    HD_SITE_NAME_INFO_EX_S       stSiteNameInfo;

    /** 会议基本属性信息 */
    MC_CONF_BASE_ATTR_EX_S       stConfBaseAttr;

    /** 边框设置 */
    MC_CONF_FRAME_EX_S           stConfFrame;

    /** 会议字幕信息结构 */
    HD_TITLE_INFO_EX_S           stTitleInfo;
} MC_CONF_NORMAL_INFO_EX_S;





/**
* @struct tagMC_MainVideoCfgEx
* @brief 主流适配配置
* @attention
*/
typedef struct tagMC_MainVideoCfgEx
{
    /** 适配协议格式数 */
    LONG_32                lVideoProtFmtNum;

    /** 适配协议格式 HD_VIDEO_PROT_FMT_EX_E */
    ULONG_32               aulVideoProtFmt[IMOS_EN_VID_PROT_FMT_COUNT];

    /** 支持帧率个数 */
    LONG_32                lVideoFramerateNum;

    /** 视频帧率 HD_FRAME_RATE_EX_E */
    ULONG_32               aulFramerate[IMOS_HD_MAX_VIDEO_FRAMERATE_NUM];

    /** 视频速率的个数 */
    LONG_32                lVideoRateNum;

    /** 视频比特率 HD_BITRATE_EX_E */
    ULONG_32               aulVideoRate[IMOS_HD_MAX_VIDEO_RATE_NUM];
} MC_MAIN_VIDEO_CFG_EX_S;


/**
* @struct tagMC_MainVideoCfgEx
* @brief 辅流适配配置
* @attention
*/
typedef struct tagMC_RoleVideoCfgEx
{
    /* 视频标准的个数，如果有适配，填1，否则填0 */
    LONG_32                lVideoProtNum;

    /** 支持的视频标准, 会议为H264时，填H263+, 否则填H264  HD_VIDEO_PROT_EX_E */
    ULONG_32               aulVideoProt[IMOS_HD_MAX_VIDEO_PROTOCOL_NUM];

    /** 视频格式的个数 */
    LONG_32                lVideoFmtNum;

    /** 视频格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32               aulVideoFmt[IMOS_HD_MAX_VIDEO_FORMAT_NUM];

    /** 支持帧率个数 */
    LONG_32                lVideoFramerateNum;

    /** 视频帧率 HD_FRAME_RATE_EX_E */
    ULONG_32               aulFramerate[IMOS_HD_MAX_VIDEO_FRAMERATE_NUM];

    /** 视频速率的个数 */
    LONG_32                lVideoRateNum;

    /* 视频比特率 HD_BITRATE_EX_E */
    ULONG_32               aulVideoRate[IMOS_HD_MAX_VIDEO_RATE_NUM];
} MC_ROLE_VIDEO_CFG_EX_S;


/**
* @struct tagMC_ConfMediaInfo
* @brief 会议媒体信息
* @attention
*/
typedef struct tagMC_ConfMediaInfoEx
{
    /** 音频 */
    /** 会议当前音频标准 HD_AUDIO_PROT_EX_E */
    ULONG_32                          ulCurrentAudioProt;

    /** 音频协议适配, 下面lAudioProtCount字段非0时，填BOOL_TRUE，否则BOOL_FALSE */
    BOOL_T                         bAudioAdapt;

    /** 支持音频协议数 */
    LONG_32                           lAudioProtCount;

    /** 音频标准 HD_AUDIO_PROT_EX_E */
    ULONG_32                          aulAudioProt[IMOS_HD_MAX_AUDIO_PROTOCOL_NUM];

    /** 主流视频 */
    /** 会议当前主流视频标准 HD_VIDEO_PROT_EX_E */
    ULONG_32                          ulCurrentMainVideoProt;

    /** 会议当前主流格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32                          ulCurrentMainVideoFmt;

    /** 会议当前主流速率 HD_BITRATE_EX_E, 默认填写为会议带宽 */
    ULONG_32                          ulCurrentMainVideoBitRate;

    /** 会议当前主流帧率 HD_FRAME_RATE_EX_E */
    ULONG_32                          ulCurMainFrameRate;

    /** 主流协议适配 */
    BOOL_T                         bMainVideoProtoAdapt;

    /** 主流格式适配，选择了适配格式时就填BOOL_TRUE */
    BOOL_T                         bMainVideoFmtAdapt;

    /** 主流设置 */
    MC_MAIN_VIDEO_CFG_EX_S         stMainVidoCfg;

    /** 主视频支持混速级别 MC_CONF_MIXRATE_EX_E，暂未用到，填0 */
    ULONG_32                          ulMainMixType;

    /** 速率帧率适配的枚举 HD_RATE_AND_FRAME_ADAPT_MODE_EX_E */
    ULONG_32                          ulRateFrameFirst;

    /** 速率或帧率适配的路数 MC_ADAPT_COUNT_EX_E，只有在选择速率或帧率适配优先时有效，否则填1 */
    ULONG_32                          ulAdapterCount;

    /** 主流速率适配值 */
    ULONG_32                          aulRateAdapterValue[IMOS_MC_MAX_BITRATE_ADAPT_COUNT];

    /** 辅流视频 */
    /** 会议当前辅流视频标准 HD_VIDEO_PROT_EX_E */
    ULONG_32                          ulCurrentRoleVideoProt;

    /** 会议当前辅流格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32                          ulCurrentRoleVideoFmt;

    /** 会议当前辅流速率 HD_BITRATE_EX_E */
    ULONG_32                          ulCurrentRoleVideoBitRate;

    /** 会议的类型 MC_CONF_TYPE_EX_E */
    ULONG_32                          ulConfType;

    /** 会议当前辅流帧率 HD_FRAME_RATE_EX_E */
    ULONG_32                          ulCurRoleFrameRate;

    /** 是否辅流适配 */
    BOOL_T                         bRoleVideoProtAdapt;

    /** 辅流格式适配 */
    BOOL_T                         bRoleVideoFmtAdapt;

    /** 辅流设置 */
    MC_ROLE_VIDEO_CFG_EX_S         stRoleVidoCfg;

    /** 辅流类型 HD_ROLE_VIDEO_TYPE_EX_E，默认填令牌模式 */
    ULONG_32                          ulRoleVideoMode;

    /** 速率帧率适配  HD_RATE_AND_FRAME_ADAPT_MODE_EX_E，只能选择IMOS_EN_RATE_FRAME_NO或IMOS_EN_RATE_FRAME_FALL */
    ULONG_32                          ulRoleRateFrameAdapt;

    /** 其他信息 */
    /** 是否支持智能流控 */
    BOOL_T                         bAutoFlowCtrl;

    /** 是否支持终端模式转换, 暂不支持，填FALSE。 */
    BOOL_T                         bSiteRequestMode;

    /** 媒体加密算法 MC_MEDIA_ENCRYPT_EX_E，目前填IMOS_EN_MEDIA_ENCRYPT_NO */
    ULONG_32                          ulMediaEncryptType;

    /** 信令加密(H.235)信息 MC_SIGNAL_TYPE_EX_E，目前填IMOS_EN_SIGNAL_TYPE_NO */
    ULONG_32                          ulSignalType;
} MC_CONF_MEDIA_INFO_EX_S;

/**
* @struct tagMC_ConfNAAEx
* @brief NAA设置
* @attention
*/
typedef struct tagMC_ConfNAAEx
{
    /** 是否采用NAA */
    BOOL_T                      bNAA;

    /** NAA值类型 HD_NAA_TYPE_EX_E */
    ULONG_32                       ulNaaType;
} MC_CONF_NAA_EX_S;

/**
* @struct tagHD_IFramePolicyEx
* @brief I帧处理策略
* @attention
*/
typedef  struct  tagHD_IFramePolicyEx
{
    /** 自动编码I帧的每次帧数 HD_IFRAME_NUM_FRAME_EX_E */
    ULONG_32           ulAutoEncIFrameNum;

    /** 自动编码I帧的时间间隔(秒) HD_IFRAME_ATUO_ENC_INTERVAL_EX_E */
    ULONG_32           ulAutoEncIFrameInterval;

    /** 发送I帧请求的每次帧数 HD_IFRAME_NUM_FRAME_EX_E，暂未用，填0 */
    ULONG_32           ulRequestIFrameNum;

    /** 发送I帧请求的最小间隔(秒) HD_IFRAME_MANUAL_ENC_INTERVAL_EX_E */
    ULONG_32           ulRequestInterval;

    /** 响应I帧请求的每次帧数 HD_IFRAME_NUM_FRAME_EX_E，暂未用，填0 */
    ULONG_32           ulResponseIFrameNum;

    /** 响应I帧请求的最小间隔(秒) HD_IFRAME_MANUAL_ENC_INTERVAL_EX_E */
    ULONG_32           ulResponseInterval;
} HD_IFRAME_POLICY_EX_S;

/**
* @struct tagHD_APowEstParamEx
* @brief 音频能量估计器参数
* @attention
*/
typedef struct tagHD_APowEstParamEx
{
    /** 上报时间间隔，以10ms为单位，默认为1  */
    LONG_32    lPowerReportGap;

    /** 能量窗口长度，以10ms为单位  */
    LONG_32    lPowerWinLen;

    /** 立体声能量计算参数：
    0－取左声道能量；
    1-取右声道能量；
    2－取左右声道平均值；
    3－取取左右声道最大值；
    4－取取左右声道最小值      */
    USHORT  usPowerStereoPara;
    UCHAR   szReserved[2];
}HD_APOWEST_PARAM_EX_S;


/**
* @struct tagMC_ConfColorInfoEx
* @brief 会议的颜色信息
* @attention
*/
typedef struct tagMC_ConfColorInfoEx
{
    /** 字幕所在颜色组 HD_COLOR_GROUP_TYPE_EX_E 现在要求界面填写两个值是一样的 */
    ULONG_32  ulTitleGroup;

    /** 其它设置所在颜色组 HD_COLOR_GROUP_TYPE_EX_E */
    ULONG_32  ulOtherGroup;
}MC_CONF_COLOR_INFO_EX_S;


/**
* @union tagHD_IpPreDiffServEx
* @brief IP Precedence 和Diffserv只能同时存在一种。
* @attention
*/
typedef  union  tagHD_IpPreDiffServEx
{
    /** ip优先 HD_IP_PRECEDENCE_TYPE_EX_E */
    ULONG_32            ulIPPrecedence;

    /** Diffserv HD_DIFFSERV_TYPE_EX_E */
    ULONG_32            ulDiffServ;
} HD_IPPRECEDENCE_DIFFSERV_EX_U;

/**
* @struct tagHD_QosServEx
* @brief ip 优先和服务优先信息
* @attention
*/
typedef  struct tagHD_QosServEx
{
    /** 服务类型 HD_QOS_TYPE_EX_E */
    ULONG_32                             ulQOSType;

    /** 服务级别 */
    HD_IPPRECEDENCE_DIFFSERV_EX_U     unQOSLerver;
} HD_QOS_SERV_EX_S;


/**
* @struct tagMC_ConfLostPacketPolicyEx
* @brief 会议丢包策略结构
* @attention
*/
typedef struct tagMC_ConfLostPacketPolicyEx
{
    /** 丢包率上限 */
    LONG_32 lMaxLostPacketRate;

    /** 最大持续丢包时长，单位S */
    LONG_32 lMaxLostPacketTime;
} MC_CONF_LP_POLICY_EX_S;

/**
* @struct tagMC_ConfAlarmInfoEx
* @brief 会议声光告警信息结构
* @attention
*/
typedef struct tagMC_ConfAlarmInfoEx
{
    /** 是否启用声光告警，填BOOL_TRUE。 */
    BOOL_T bUseVoiceLightAlarm;
} MC_CONF_ALARM_INFO_EX_S;

/**
* @struct tagConfAdvanceInfoEx
* @brief 会议高级信息 iMSC扩展的
* @attention
*/
typedef struct tagMC_ConfAdvanceInfoEx
{
    /** 会议媒体信息 */
    MC_CONF_MEDIA_INFO_EX_S     stConfMediaInfo;

    /** 网络适应性设置 */
    MC_CONF_NAA_EX_S            stNAA;

    /** I帧处理策略 */
    HD_IFRAME_POLICY_EX_S       stIFramePolicy;

    /** 是否支持组播，创建会议时填0 */
    BOOL_T                      bMultiCast;

    /** 是否自动发送组播 */
    BOOL_T                      bAutoMultiCast;

    /** 会议状态 MC_CONF_STATUS_EX_E */
    ULONG_32                       ulStatus;

    /** 开始组播标志 */
    BOOL_T                      bBeginMulticast;

    /** 预设会议主席, 设置为无主席时 为空  */
    CHAR                        szSetChairCode[IMOS_RES_CODE_LEN];

    /** 预设会议发言人，未用到，为空  */
    CHAR                        szSetSpeakerCode[IMOS_RES_CODE_LEN];

    /** 预设广播会场，创建会议时，为空  */
    CHAR                        szSetBroadcastCode[IMOS_RES_CODE_LEN];

    /** 指定辅流会场,自动时为空  */
    CHAR                        szSetRoleVideoSiteCode[IMOS_RES_CODE_LEN];

    /** 预设主场观看的会场 */
    CHAR                        szSetMainSiteObserve[IMOS_RES_CODE_LEN];

    /** 被广播者观看画面 MC_BROADCASTED_OBSERVE_EX_E。 未使用，填0 */
    ULONG_32                       ulBroadcastedObserve;

    /** 音频能量估计器，未用到，填0  */
    HD_APOWEST_PARAM_EX_S          stApowestParam;

    /** 颜色信息 */
    MC_CONF_COLOR_INFO_EX_S        stColorInfo;

    /** 服务级别，未用到，填0 */
    HD_QOS_SERV_EX_S               stQosServ;

    /** 切换广播时，主席观看模式 MC_CHAIR_LOOK_MODE_EX_E */
    ULONG_32                          ulChairLookMode;

    /** 会场选择观看的枚举 MC_SELECT_LOOK_EX_E */
    ULONG_32                          ulSelectLook;

    /** 是否提前结束会议通知的枚举 MC_AHEAD_END_CONF_EX_E。 未实现 提前结束会议功能未实现，未用到，填0 */
    ULONG_32                          ulAheadEndConf;

    /** 丢包策略 */
    MC_CONF_LP_POLICY_EX_S         stLPPolicy;

    /** 声光告警信息 */
    MC_CONF_ALARM_INFO_EX_S        stAlarmInfo;

    /** 主场选择观看会场是否自动开麦克风 */
    BOOL_T                         bIsChairWatchedMicAutoOpen;

    /** 被广播会场是否自动开麦克风 */
    BOOL_T                         bIsBroadcastedMicAutoOpen;

    /** 会场入会后麦克风是否自动开启 */
    BOOL_T                         bIsAllSiteMicAutoOpen;

    /** 图像拉伸设置 HD_SCALER_TYPE_EX_E */
    ULONG_32                          ulScalerType;

    /** 丢包隐藏类型 HD_LPR_TYPE_EX_E */
    ULONG_32                          ulLPRType;

    /** 结束音提示类型 HD_TIP_TIME_LEN_TYPE_EX_E */
    ULONG_32                          ulTipEndType;
} MC_CONF_ADVANCE_INFO_EX_S;

/**
 * @struct tagMC_ConfInfoEx
 * @brief 会议基本信息和高级信息
 * @attention ?? 需要增加自动调度/手工调度的信息， 该部分信息为iMSC扩展的
 */
typedef struct tagMC_ConfInfoEx
{
    /** 会议普通信息 */
    MC_CONF_NORMAL_INFO_EX_S          stNormalInfo;

    /** 会议高级信息 */
    MC_CONF_ADVANCE_INFO_EX_S         stAdvanceInfo;
} MC_CONF_INFO_EX_S;


/**
 * @struct tagConfTopologyNodeEx
 * @brief  会议拓扑节点信息
 * @attention
 */
typedef struct tagConfTopologyNodeEx
{
    /**  节点编码 */
    CHAR                    szNodeCode[IMOS_RES_CODE_LEN];

    /**  节点类型 MC_NODE_TYPE_EX_E */
    ULONG_32                   ulNodeType;

    /**  节点的X坐标 */
    ULONG_32                   ulXpos;

    /**  节点类型y坐标 */
    ULONG_32                   ulYpos;

    /**  节点名 */
    CHAR                    szNodeName[IMOS_NAME_LEN];

    /** 设备描述 */
    CHAR                    szNodeDesc[IMOS_DESC_LEN];
} CONF_TOPOLOGY_NODE_EX_S;

/**
 * @struct tagMC_MultiCastInfoEx
 * @brief 组播信息
 * @attention
 */
typedef struct tagMC_MultiCastInfoEx
{
    /** 是否支持组播 */
    BOOL_T      bMultiCast;

    /** 组播地址 */
    CHAR        szMultiAddr[IMOS_IPADDR_LEN];

    /** 组播用户密码 */
    CHAR        szMultiUserPwd[IMOS_CONF_PWD_LEN];

    /** 指定的组播网口数 */
    LONG_32        lIfaceCount;

    /** 发送组播的网口 */
    USHORT      ausIface[IMOS_MC_MAX_LAN_NET_NUM];

    /** 音频组播端口 */
    ULONG_32       ulMultiPortAudio;

    /** 主流视频组播端口,音频组播端口加2 */
    ULONG_32       ulMultiPortVideo;

    /** 辅流视频组播端口,主流组播端口加2 */
    ULONG_32       ulMultiPortRoleVideo;
} MC_MULTICAST_INFO_EX_S;






/**
 * @struct tagMC_ConfActiveInfoEx
 * @brief 会议活动信息 iMSC扩展
 * @attention
 */
typedef    struct    tagMC_ConfActiveInfoEx
{
    /** 会议ID, iMSC中使用 */
    IMOS_ID              idConfId;

    /** 会议名 */
    CHAR                 szConfName[IMOS_CONF_NAME_LEN];

    /** 当前会议主席会场名 */
    CHAR                 szCurrentChair[IMOS_NAME_LEN];

    /** 当前会议主席编码 */
    CHAR                 szCurrentChairCode[IMOS_RES_CODE_LEN];

    /** 当前会议发言者的会场名 */
    CHAR                 szCurrentSpeaker[IMOS_NAME_LEN];

    /** 会议发言者的会场编码 */
    CHAR                 szCurrentSpeakerCode[IMOS_RES_CODE_LEN];

    /** 当前广播会场名 */
    CHAR                 szCurrentBroadcastSite[IMOS_NAME_LEN];

    /** 当前广播会场编码 */
    CHAR                 szCurrentBroadcastCode[IMOS_RES_CODE_LEN];

    /** 主场观看会场名 */
    CHAR                 szMainSiteBWSite[IMOS_NAME_LEN];

    /** 主场观看会场编码 */
    CHAR                 szMainSiteBWSiteCode[IMOS_RES_CODE_LEN];

    /** 预设的会议主席会场名 */
    CHAR                 szSetChair[IMOS_NAME_LEN];

    /** 预设会议主席会场编码 */
    CHAR                 szSetChairCode[IMOS_RES_CODE_LEN];

    /** 会议FECC控制者的会场名 */
    CHAR                 szFECCController[IMOS_NAME_LEN];

    /** 会议FECC控制者会场编码*/
    CHAR                 szFECCControllerCode[IMOS_RES_CODE_LEN];

    /** 会议FECC受控者的会场名 */
    CHAR                 szFECCControlled[IMOS_NAME_LEN];

    /** 会议FECC受控者会场编码*/
    CHAR                 szFECCControlledCode[IMOS_RES_CODE_LEN];

    /** 会议双流源的会场名 */
    CHAR                 szSetRoleVideoSite[IMOS_NAME_LEN];

    /** 会议双流源的会编码 */
    CHAR                 szSetRoleVideoSiteCode[IMOS_RES_CODE_LEN];

    /** 会议当前双流源的会场名 */
    CHAR                 szCurRoleVideoSite[IMOS_NAME_LEN];

    /** 会议当前双流源的会场编码 */
    CHAR                 szCurRoleVideoSiteCode[IMOS_RES_CODE_LEN];

    /** 会议开始时间 */
    LONG_32                 lConfBeginTime;

    /** 会议持续时间 */
    LONG_32                 lLastTime;

    /** 会场总数 */
    LONG_32                 lSiteCount;

    /** 会议模式 MC_CONF_MODE_EX_E */
    ULONG_32                ulConfMode;

    /** 在线会场数 */
    LONG_32                 lLiveSiteCount;
} MC_CONF_ACTIVE_INFO_EX_S;

/**
* @struct tagMC_SiteMediaInfoEx
* @brief 会场入会后的状态信息
* @attention
*/
typedef struct tagMC_SiteMediaInfoEx
{
    /** 入会时间 */
    LONG_32                    lJoinTime;

    /** 是否静音 */
    BOOL_T                  bIsSilence;

    /** 是否闭音 */
    BOOL_T                  bIsMute;

    /** 是否发送主流视频 */
    BOOL_T                  bSendMainVideo;

    /** 是否发送辅流视频 */
    BOOL_T                  bSendRoleVideo;

    /** 呼叫带宽 HD_BITRATE_EX_E */
    ULONG_32                   ulBandWidth;

    /** 当前被会场观看的会场编码 */
    CHAR                    szTermWatchedCode[IMOS_RES_CODE_LEN];

    /** 当前被会场观看的会场名称 */
    CHAR                    szTermWatchedName[IMOS_NAME_LEN];
} MC_CONF_SITE_STATUS_INFO_EX_S;

/**
* @struct tagHD_AudioCapEx
* @brief 音频能力
* @attention
*/
typedef  struct    tagHD_AudioCapEx
{
    /** 音频编解码格式 HD_AUDIO_PROT_EX_E */
    ULONG_32            ulAudio;

    /** 音频比特率bps */
    LONG_32             lAudBitRate;

    /** 采样率 */
    LONG_32             lSampleRate;

    /** 是否H235 */
    BOOL_T           bH235;
} HD_AUDIO_CAP_EX_S;


/**
* @struct tagHD_VideoFmtFREx
* @brief 视频图像格式和帧率结构
* @attention
*/
typedef  struct    tagHD_VideoFmtFREx
{
    /** 图像格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32             ulFmt;

    /** 视频图像帧率 */
    LONG_32              lFrameRate;

    /** 视频图像帧率适配 */
    BOOL_T            bFrameRateAdapt;
} HD_VIDEO_FMT_FR_EX_S;

/**
* @struct tagHD_VideoCapEx
* @brief 视频能力
* @attention
*/
typedef  struct    tagHD_VideoCapEx
{
    /** 视频编解码协议 HD_VIDEO_PROT_EX_E */
    ULONG_32                ulVideo;

    /** 图像格式个数 */
    LONG_32                 lFmtCount;

    /** 视频图像格式及帧率 */
    HD_VIDEO_FMT_FR_EX_S    astFmt[IMOS_HD_MAX_VIDEO_FORMAT_NUM];

    /** 视频图像码率bps */
    LONG_32                 lBitrate;

    /** 视频填写码率适配 */
    BOOL_T               bBitrateAdapt;

    /** 是否H235 */
    BOOL_T               bH235;

    /** 是否H239 */
    BOOL_T               bH239;

    /** 角色类型 HD_ROLE_VIDEO_TYPE_EX_E */
    ULONG_32                ulRole;
} HD_VIDEO_CAP_EX_S;

/**
* @struct tagHD_DataCapEx
* @brief 数据能力
* @attention
*/
typedef  struct    tagHD_DataCapEx
{
    /** 数据格式 HD_DATA_PROT_EX_E */
    ULONG_32            ulData;

    /** 比特率bps */
    LONG_32             lBitRate;

    /** 是否H235 */
    BOOL_T           bH235;
} HD_DATA_CAP_EX_S;

/**
* @struct tagHD_ControlCapEx
* @brief 控制能力
* @attention
*/
typedef  struct    tagHD_ControlCapEx
{
    /** 控制能力格式 HD_CTRL_PROT_EX_E */
    ULONG_32   ulCtrl;
} HD_CTRL_CAP_EX_S;

/**
* @union tagHD_CapSetUnEx
* @brief 能力集联合体
* @attention
*/
typedef  union    tagHD_CapSetUnEx
{
    /** 音频能力 */
    HD_AUDIO_CAP_EX_S   stAudio;

    /** 视频能力 */
    HD_VIDEO_CAP_EX_S   stVideo;

    /** 数据能力 */
    HD_DATA_CAP_EX_S    stData;

    /** 控制能力 */
    HD_CTRL_CAP_EX_S    stCtrl;
} HD_CAP_SET_EX_U;

/**
* @struct tagHD_CapItemEx
* @brief 能力项结构体
* @attention
*/
typedef  struct    tagHD_CapItemEx
{
    /** 能力类型 HD_CAP_TYPE_EX_E */
    ULONG_32               ulCapType;

    /** 能力参数 */
    HD_CAP_SET_EX_U     unCap;
} HD_CAP_ITEM_EX_S;

/**
* @struct tagMC_SiteCapStEx
* @brief 能力交换确定的会场能力
* @attention
*/
typedef  struct    tagMC_SiteCapStEx
{
    /*能力个数*/
    LONG_32          lCapCount;

    /*会场能力*/
    HD_CAP_ITEM_EX_S astCap[IMOS_HD_MAX_SIM_CAP_NUM];
}MC_SITE_CAP_EX_S;

/**
 * @struct tagMC_SiteInfo
 * @brief 会场入会后的信息
 * @attention
 */
typedef struct tagMC_SiteInfoEx
{
    /** 会场编码 */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** 会场所在会议的唯一标志 */
    IMOS_ID  idConfId;

    /** 会场E164号码 */
    CHAR     szE164[IMOS_NAME_LEN];

    /** 会场别名 */
    CHAR     szAlias[IMOS_NAME_LEN];

    /** 会场名称 */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** 选择观看的会场编码 */
    CHAR     szLookSiteCode[IMOS_RES_CODE_LEN];

    /** 表示本会场被其它会场观看时用的混合器ID */
    CHAR     szMixerCode[IMOS_RES_CODE_LEN];

    /** H323CC相关上下文 */
    ULONG_32    ulCCContext;

    /** 会场视频通道所在的VP板号 */
    LONG_32     lVPID;

    /** 会场状态参数信息 */
    MC_CONF_SITE_STATUS_INFO_EX_S   stSiteConf;

    /** 会场能力 */
    MC_SITE_CAP_EX_S                stCap;

    /** 会场的IP地址 */
    CHAR          szIP[IMOS_IPADDR_LEN];
} MC_SITE_INFO_EX_S;

/**
 * @struct tagMC_ConfSiteListDefEx
 * @brief 配置在会议中的会场列表信息
 * @attention
 */
typedef struct tagMC_ConfSiteListDefEx
{
    /** 会场编码 */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** 会场所在MCU的编码 */
    CHAR     szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** 会场在MCU上的ID，-1为无效的会场ID */
    LONG_32     lSiteIdInMcu;

    /** 会场名称 */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** 会场状态参数信息 */
    MC_CONF_SITE_STATUS_INFO_EX_S   stSiteConf;

    /** 会场状态 MC_SITE_STATUS_EX_E */
    ULONG_32              ulSiteStatus;

    /** 仅当会场离线的时候用于判断会场离线的原因 HD_RESULT_EX_E */
    ULONG_32              ulResult;

    /** 终端IP地址 */
    CHAR               szIpAddr[IMOS_IPADDR_LEN];

    /** 终端音视频使用类型 MC_TERM_TYPE_EX_E */
    ULONG_32              ulTermType;

    /** 终端总带宽 */
    LONG_32               lBandWidth;

    /** 终端类型(TERM_QUERY_TYPE_E) */
    ULONG_32              ulQueryTermType;

    /** 切换方式 MC_LINK_LAYER_SWITCH_MODE_EX_E */
    ULONG_32              ulSwitchMode;

    /** 当前使用的链路 MC_LINK_LAYER_TYPE_EX_E */
    ULONG_32              ulCurLinkLayer;

    /** 各链路的连接状态 MC_LINK_LAYER_STATE_EX_E */
    ULONG_32              aulLayerState[IMOS_EN_LINK_LAYER_TYPE_COUNT];

    /** 声光告警状态 MC_TERM_ALARM_STATUS_EX_E */
    ULONG_32              ulAlarmStatus;
} MC_CONF_SITE_LIST_EX_S;


/**
 * @struct tagMC_ConfSiteNameEx
 * @brief  会场名字信息
 * @attention
 */
typedef struct tagMC_ConfSiteNameEx
{
    /** 会场编码 */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

   /** 会场名称 */
    CHAR     szSiteName[IMOS_NAME_LEN];
}MC_CONF_SITE_NAME_EX_S;



/**
* @struct tagMC_NetStatusEx
* @brief 网口参数
* @attention
*/
typedef struct tagMC_NetStatusEx
{
    /** 网口是否启用标志 */
    BOOL_T      bUseFlag;

    /** 网口标识 */
    CHAR        szCardName[IMOS_NETCARD_NAME_LEN];

    /** 连接状态, BOOL_TRUE表示已经连接网络 */
    BOOL_T      bConnect;

    /** IP地址 */
    CHAR        szIPAddr[IMOS_IPADDR_LEN];

    /** 子网掩码 */
    CHAR        szSubmask[IMOS_IPADDR_LEN];

    /** 网关地址 */
    CHAR        szGateWay[IMOS_IPADDR_LEN];

    /** 网口双工模式 HD_NETCARD_DUPLEX_TYPE_EX_E */
    ULONG_32       ulCardDuplexType;

    /** 网口支持速率 HD_NETCARD_RATE_EX_E */
    ULONG_32       ulCardRate;

    /** BOOL_TRUE使用光口 */
    BOOL_T      bUseLightNet;
} MC_NET_STATUS_EX_S;


/**
* @struct tagMC_McuLanIPEx
* @brief 网口信息基本结构：修改时ulMask表示网口号(按二进制位表示);
* @attention
*/
typedef struct tagMC_McuLanIPEx
{
    /** 网口基本信息 */
    MC_NET_STATUS_EX_S     astLanAddr[IMOS_MC_MAX_MCU_IP_NUM];
}MC_MCU_LAN_IP_EX_S;

/**
* @struct tagMC_BackupLayer_IPCfgEx
* @brief 备份链路策略的 IP 配置
* @attention
*/
typedef struct tagMC_BackupLayer_IPCfgEx
{
    /** lo/eth1/eth2 地址 */
    MC_NET_STATUS_EX_S astLanAddr[IMOS_EN_LINK_LAYER_NIC_TYPE_COUNT];
} MC_BACKUP_LAYER_IP_CFG_EX_S;

/**
 * @struct tagMC_MCUIPCfgEx
  * @brief MCU IP 配置信息
 * @attention
 */
typedef struct tagMC_MCUIPCfgEx
{
    /** 是否启用备份线路策略 */
    BOOL_T                        bUseBakLayer;

    /** MCU的IP信息 */
    MC_MCU_LAN_IP_EX_S            stLanIP;

    /** 双链路备份策略的 IP 配置 */
    MC_BACKUP_LAYER_IP_CFG_EX_S    stBakIPInfo;
} MC_MCU_IP_CFG_S;


/**
 * @struct tagMC_MCURouteEx
 * @brief 网络路由表结构
 * @attention
 */
typedef struct tagMC_MCURouteEx
{
    /** 目的IP地址 */
    CHAR             szDestAddr[IMOS_IPADDR_LEN];

    /** 网关地址 */
    CHAR             szGateway[IMOS_IPADDR_LEN];

    /** 子网掩码 */
    CHAR             szSubmask[IMOS_IPADDR_LEN];

    /** 启用NAT时是否是外部路由 */
    BOOL_T           bExtern;
} MC_MCU_ROUTE_EX_S;

/**
 * @struct tagMC_MCULanTableEx
 * @brief LAN板的已经连接的外部网口数，每个已经连接的网口的路由表的信息
 * @attention
 */
typedef struct tagMC_MCULanTableEx
{
    /** 已经连接的网口个数 */
    ULONG_32              ulCount;

    /** 每个网口的路由记录数 */
    LONG_32               alRouteCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** 路由表 */
    MC_MCU_ROUTE_EX_S  astRouteTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ROUTE_NUM];
} MC_MCU_LAN_ROUTE_TABLE_EX_S;


/**
* @struct tagMC_MCUARPEx
* @brief 网络ARP结构
* @attention
*/
typedef struct tagMC_MCUARPEx
{
    /** IP地址 */
    CHAR  szAddr[IMOS_IPADDR_LEN];

    /** MAC地址 */
    CHAR  szMACAddr[IMOS_MC_MAX_MAC_ADDR_LEN];

    /** 网口标识 */
    CHAR  szCardName[IMOS_NETCARD_NAME_LEN];
} MC_MCU_ARP_EX_S;

/**
 * @struct tagMC_MCUARPTableEx
 * @brief LAN板的已经连接的外部网口数，每个已经连接的网口的ARP表的信息
 * @attention
 */
typedef struct tagMC_MCUARPTableEx
{
    /** 已经连接的网口个数 */
    ULONG_32              ulCount;

    /** 每个网口的ARP记录数 */
    LONG_32               alARPCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** ARP表 */
    MC_MCU_ARP_EX_S    astARPTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ARP_NUM];
} MC_MCU_ARP_TABLE_EX_S;

/**
* @struct tagHD_BoardSeriesInfoEx
* @brief 串口的配置参数
* @attention
*/
typedef struct tagHD_BoardSeriesInfoEx
{
    /** 每秒比特率 HD_COM_BIT_RATE_EX_E */
    ULONG_32              ulBitRate;

    /** 数据位 */
    USHORT             usData;

    /** 保留字段用于字节对齐 */
    USHORT             usReserve;

    /** 奇偶校验 */
    BOOL_T             bParityCheck;

    /** 停止位 */
    USHORT             usStopBit;

    /** 保留字段用于字节对齐 */
    USHORT             usReserve1;

    /** 数据流控 */
    BOOL_T             bFlowControl;
} HD_BOARD_SERIAL_INFO_EX_S;

/**
* @struct tagHD_BoardNormalInfoEx
* @brief 每个板块的基本信息
* @attention
*/
typedef struct tagHD_BoardNormalInfoEx
{
    /** MCU软件板本号 */
    CHAR        szMcuSoftVersion[IMOS_SOFT_VERSION_LEN];

    /** 设备名称 */
    CHAR        szDeviceName[IMOS_SOFT_VERSION_LEN];

    /** 硬件版本号 */
    CHAR        szHardDeviceVision[IMOS_SOFT_VERSION_LEN];

    /** UBoot版本号 */
    CHAR        szUBootVersion[IMOS_SOFT_VERSION_LEN];

    /** Kernel版本号 */
    CHAR        szKernelVersion[IMOS_SOFT_VERSION_LEN];

    /** Fpga版本号 */
    CHAR        szFpgaVersion[IMOS_SOFT_VERSION_LEN];

    /** Cpld版本号(现共有两块CPLD), 0位表示CPLD0版本(数值表示), 1位表示CPLD1 */
    CHAR        szCpldVersion[IMOS_SOFT_VERSION_LEN];

    /** 板子槽位号 */
    USHORT      usSlot;

    /** 保留字段用于字节对齐 */
    USHORT      usReserve;

    /** 内网IP地址 */
    CHAR        szIpAddr[IMOS_IPADDR_LEN];

    /** 内网监听端口 */
    ULONG_32       ulPort;

    /** CPU温度 */
    LONG_32       ulCPUTemperature;

    /** CPU风扇的转速 HD_FAN_STATE_EX_E */
    ULONG_32       ulFanState;

    /** CPU资源使用率 */
    ULONG_32       ulUsedCPU;

    /** 总内存大小 */
    ULONG_32       ulTotalMemory;

    /** 内存资源使用率 */
    ULONG_32       ulUsedM;

    /** 串口配置信息 */
    HD_BOARD_SERIAL_INFO_EX_S    stSeriesInfo;

    /** 对外版本号 */
    CHAR        szMcuExVersion[IMOS_SOFT_VERSION_LEN];

    /** 编译时间 */
    CHAR        szMeMakeTime[50];

    /** 保留字段用于字节对齐 */
    USHORT      usReserve2;
    /** 驱动版本 */
    CHAR        szDrvVersion[IMOS_SOFT_VERSION_LEN];

    /** DSP版本号 */
    CHAR        szDSPVersion[IMOS_SOFT_VERSION_LEN];

    /** 设备型号 */
    CHAR        szDevModel[IMOS_SOFT_VERSION_LEN];

    /** 设备序列号 */
    CHAR        szSerialNum[IMOS_HD_MAX_SOFT_VERSION_LEN + 1];

    /** 音频估计器 */
    CHAR        szAudEstDevDSP[IMOS_SOFT_VERSION_LEN];

    /** 音频混合器 */
    CHAR        szAudMixDevDSP[IMOS_SOFT_VERSION_LEN];

    /** 视频解码器*/
    CHAR        szVidDeCodeDevDSP[IMOS_SOFT_VERSION_LEN];

    /** 视频编码器 */
    CHAR        szVidEnCodeDevDSP[IMOS_SOFT_VERSION_LEN];
    /** 板卡启动时间 */
    LONG_32        lBootTime;
} HD_BOARD_NORMAL_INFO_EX_S;


/**
* @struct tagHD_LanInfoEx
* @brief LAN板的信息,链接状态表示网口是否链接网络。
* @attention
*/
typedef struct tagHD_LanInfoEx
{
    /** LAN板基本信息 */
    HD_BOARD_NORMAL_INFO_EX_S    stLANBoard;

    /** LAN板的SFP1口是否在位 */
    BOOL_T                    bSFP1;

    /** LAN板的SFP1口是否在位 */
    BOOL_T                    bSFP2;

    /** LAN板的GE3口是否在位 */
    BOOL_T                    bGE3;

    /** LAN板的GE4口是否在位 */
    BOOL_T                    bGE4;

    /** LAN板的SFP1口链接状态 */
    BOOL_T                    bConnect1;

    /** LAN板的SFP1口链接状态 */
    BOOL_T                    bConnect2;

    /** LAN板的GE3口链接状态 */
    BOOL_T                    bConnect3;

    /** LAN板的GE4口链接状态 */
    BOOL_T                    bConnect4;

    /** 网络流量1 */
    USHORT                    usNet1;

    /** 网络流量2 */
    USHORT                    usNet2;

    /** 网络流量3 */
    USHORT                    usNet3;

    /** 网络流量4 */
    USHORT                    usNet4;
} HD_LAN_INFO_EX_S;

/**
* @struct tagHD_BoardDSPInfoEx
* @brief 每个DSP的使用情况
* @attention
*/
typedef struct tagHD_BoardDSPInfoEx
{
    /** DSP状态 HD_DSP_STATUS_EX_E */
    ULONG_32                ulDspStat;

    /** DSP上的会议 */
    IMOS_ID              aidConfId[IMOS_HD_MAX_DSP_NUM_PER_CONF];
} HD_BOARD_DSP_INFO_EX_S;


/**
* @struct tagHD_VPAPInfoEx
* @brief 每个VP板、AP板的配置,HD_DSP_INFO_EX_S 包括了每个DSP上的会议
* @attention
*/
typedef struct tagHD_VPAPInfoEx
{
    /** 单板基本信息 */
    HD_BOARD_NORMAL_INFO_EX_S  stBoard;

    /** 单板DSP个数 */
    ULONG_32                   ulDSP;

    /** DSP列表 */
    HD_BOARD_DSP_INFO_EX_S  astDSPInfo[IMOS_HD_MAX_DSP_PER_PLANK];
} HD_VP_AP_INFO_EX_S;

/**
 * @union tagHD_DeviceUnionEx
 * @brief VP、AP、LAN、MC、MC备板信息的一种。
 * @attention
 */
typedef  union  tagHD_DeviceUnionEx
{
    /** MC板信息 */
    HD_BOARD_NORMAL_INFO_EX_S         stMCInfo;

    /** MC备板信息 */
    HD_BOARD_NORMAL_INFO_EX_S         stMCBInfo;

    /** LAN板信息 */
    HD_LAN_INFO_EX_S                  stLanInfo;

    /** VP板信息 */
    HD_VP_AP_INFO_EX_S                stVPInfo;

    /** AP板信息 */
    HD_VP_AP_INFO_EX_S                stAPInfo;
} HD_DEVICE_EX_U;




/**
 * @struct tagMC_TermVideoCfgEx
 * @brief 添加终端配置主流视频支持的标准、格式、速率、帧率等信息的结构
 * @attention
 */
typedef struct tagMC_TermVideoCfgEx
{
    /** 视频标准的个数，填1 */
    LONG_32                lVideoProtNum;

    /** 支持的视频标准 HD_VIDEO_PROT_EX_E，只选择1个 */
    ULONG_32               aulVideoProt[IMOS_EN_VID_PROT_COUNT];

    /** 视频最高格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32               ulVideoFmt;

    /** 视频最高帧率 HD_FRAME_RATE_EX_E */
    ULONG_32               ulFrameRate;

    /** 视频最高比特率 HD_BITRATE_EX_E */
    ULONG_32               ulVideoRate;
} MC_TERM_VIDEO_CFG_EX_S;

/**
 * @struct tagMC_TermRoleVideoCfgEx
 * @brief 添加终端配置辅流视频支持的标准、格式、速率、帧率等信息的结构
 * @attention
 */
typedef struct tagMC_TermRoleVideoCfgEx
{
    /** 视频标准的个数，填1  */
    LONG_32                lVideoProtNum;

    /** 支持的视频标准 HD_VIDEO_PROT_EX_E，选择1种  */
    ULONG_32               aulVideoProt[IMOS_EN_VID_PROT_COUNT];

    /** 活动视频最高格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32               ulVideoFmt;

    /** 活动视频最高帧率 HD_FRAME_RATE_EX_E */
    ULONG_32               ulFrameRate;

    /** 视频最高比特率 HD_BITRATE_EX_E */
    ULONG_32               ulVideoRate;

    /** 胶片视频最高格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32               ulPresentationVideoFmt;

    /** 胶片视频最高帧率 HD_FRAME_RATE_EX_E */
    ULONG_32               ulPresentationFrameRate;
} MC_TERM_ROLEVIDEO_CFG_EX_S;



/**
* @struct tagHD_SimpleChannelEx
* @brief 单个媒体通道的动态信息
* @attention
*/
typedef  struct  tagHD_SimpleChannelEx
{
    /** 通道属性 */
    /** 通道能力类型 HD_CAP_TYPE_EX_E */
    ULONG_32                   ulCapType;

    /** 通道类型 HD_CHN_DIRECTION_EX_E */
    ULONG_32                   ulDirect;

    /** 通道能力信息 */
    HD_CAP_SET_EX_U         unSimpleCap;

    /** BOOL_TRUE, 加密 */
    BOOL_T                  bEncrypt;

    /** 远端地址 */
    CHAR                    szRemoteIP[IMOS_IPADDR_LEN];

    /** 远端端口 0-65535 */
    ULONG_32                   ulRemotePort;

    /** 本端地址 */
    CHAR                    szLocalIP[IMOS_IPADDR_LEN];

    /** 本端端口 0-65535 */
    ULONG_32                   ulLocalPort;

    /** 通道状态信息 */
    /** 通道码率 */
    ULONG_32                   ulBiteRateCurrent;

    /** 该通道接收总数 */
    LONG_32                    lTotalPacketNum;

    /** 该通道丢包总数 */
    LONG_32                    lLostPacketNum;

    /** 实时丢包率, 用数值表示的是放大1000倍, 实际获取的百分比为lMaxLostPackRate */
    LONG_32                    lLostRateCurrent;

    /** 峰值丢包率, 用数值表示的是放大1000倍, 实际获取的百分比为lMaxLostPackRate */
    LONG_32                    lLostRatePeak;

    /** JB */
    /** 当前JB(JitterBuffer)大小 */
    LONG_32                    lJBSizeCurrent;

    /** 峰值JB(JitterBuffer)大小 */
    LONG_32                    lJBSizePeak;

    /** 当前通道的NAA缓冲包数 */
    LONG_32                    lNAACachePackNumCurrent;

    /** 峰值通道的NAA缓冲包数 */
    LONG_32                    lNAACachePackNumPeak;

    /** 请求重发次数 */
    LONG_32                    lReSendNumRequested;

    /** 实际收到的重发包数 */
    LONG_32                    lResendNumReceved;
} HD_SIMPLE_CHANNEL_EX_S;

/**
 * @struct tagMC_SiteCapSetEx
 * @brief 终端所有通道的信息
 * @attention
 */
typedef  struct    tagMC_SiteCapSetEx
{
    /** 通道个数 */
    LONG_32                     lCount;

    /** 数组 */
    HD_SIMPLE_CHANNEL_EX_S   astCap[IMOS_HD_MAX_SIM_CAP_NUM];
} MC_SITE_CAP_SET_EX_S;


/**
* @struct tagMC_IPPortEx
* @brief IP/Port 组播IP
* @attention
*/
typedef struct tagMC_IPPortEx
{
    /** IP地址 */
    CHAR          szIP[IMOS_IPADDR_LEN];

    /** 开始端口, 后续占用2个,依次是音频、视频端口
    * 开始端口号：比如 100，
    * 那么100，101 是音频，102 103 是视频。
    * 也就是说，通过指定一个端口，就可推算出音频、视频的端口号。
    */
    ULONG_32         ulPort;
} MC_IP_PORT_EX_S;

/**
 * @struct tagMC_MulticastEx
 * @brief 带唯一ID的组播结构
 * @attention
 */
typedef struct tagMC_MulticastEx
{
    /** 组播的唯一ID */
    LONG_32                              lMulticastID;

    /** 单条组播地址 */
    MC_IP_PORT_EX_S                   stMulticastIP;
}MC_MULTICAST_EX_S;


/**
 * @struct tagMC_MCUConfNATEx
 * @brief NAT配置
 * @attention
 */
typedef struct tagMC_MCUConfNATEx
{
    /** 是否启用NAT */
    BOOL_T              abUseNAT[IMOS_MC_MAX_MCU_IP_NUM];

    /** NAT外部地址 */
    CHAR                aszNatAddr[IMOS_MC_MAX_MCU_IP_NUM][IMOS_IPADDR_LEN];

    /** 呼叫开始端口 */
    ULONG_32               ulBeginCallPort;

    /** 呼叫结束端口 */
    ULONG_32               ulEndCallPort;

    /** 媒体开始端口 */
    ULONG_32               ulBeginRTPPort;

    /** 媒体结束端口 */
    ULONG_32               ulEndRTPPort;
} MC_MCU_CONFIG_NAT_EX_S;

/**
 * @struct tagMC_MCUNTPInfoEx
 * @brief NTP配置
 * @attention
 */
typedef struct tagMC_MCUNTPInfoEx
{
    /** 是否启用NTP */
    BOOL_T              bUseNTP;

    /** NTP服务器地址 */
    CHAR                szNTPServerAddr[IMOS_IPADDR_LEN];

    /** NTP时间同步间隔 MC_NTP_TIME_SYNCH_INTERVAL_EX_E */
    ULONG_32               ulSynchInterval;
} MC_MCU_NTP_INFO_EX_S;

/**
 * @struct tagHD_ColorValueEx
 * @brief 颜色RGB值结构
 * @attention
 */
typedef struct tagHD_ColorValueEx
{
    /** 颜色R值 */
    UCHAR      ucRed;

    /** 颜色G值 */
    UCHAR      ucGreen;

    /** 颜色B值 */
    UCHAR      ucBlue;

    /** 透明度 */
    UCHAR      ucAlfa;
} HD_COLOR_VALUE_EX_S;

/**
 * @struct tagHD_McuColorValueEx
 * @brief 颜色配置结构
 * @attention
 */
typedef struct tagHD_McuColorValueEx
{
    HD_COLOR_VALUE_EX_S    astOSDValue[IMOS_EN_COLOR_GROUP_COUNT][IMOS_EN_COLOR_TABLE16_TYPE_COUNT];
    HD_COLOR_VALUE_EX_S    astTitleValue[IMOS_EN_COLOR_GROUP_COUNT][IMOS_EN_COLOR_TABLE4_TYPE_COUNT];
}HD_MCU_COLOR_VALUE_EX_S;

/**
* @struct tagMC_MCUConfigAlarmEx
* @brief 声光告警配置
* @attention
*/
typedef struct tagMC_MCUConfigAlarmEx
{
    /** 声光告警服务器地址 */
    CHAR   szRemoteIP[IMOS_IPADDR_LEN];

    /** 声光告警服务器端口 */
    ULONG_32 ulRemotePort;

    /** 声光告警本地端口 */
    ULONG_32 ulLocalPort;

    /** 电源1掉电声光告警号 */
    ULONG_32 ulPower1AlarmID;

    /** 电源2掉电声光告警号 */
    ULONG_32 ulPower2AlarmID;
} MC_MCU_CONFIG_ALARM_EX_S;

/**
* @struct tagMC_MCUConfigNormalEx
* @brief 系统基本配置
* @attention
*/
typedef struct tagMC_MCUConfigNormalEx
{
    /** 别名H323ID */
    CHAR                  szAlias[IMOS_MCU_NAME_LEN];

    /** 系统时间 */
    LONG_32                  lSystemTime;

    /** 时区 HD_SYS_TIMEZONE_EX_E */
    ULONG_32                 ulTimeZone;

    /** 系统语言 HD_SYS_LANGUAGE_EX_E */
    ULONG_32                 ulLanguage;
} MC_MCU_CONFIG_NORMAL_EX_S;

/**
* @struct tagMC_MCUConfigGKEx
* @brief 网守配置
* @attention
*/
typedef struct tagMC_MCUConfigGKEx
{
    /** 是否使用网守, 是否内置网守 MC_GK_TYPE_EX_E */
    ULONG_32              ulGKType;

    /** 外部GK IP地址 */
    CHAR               szGKAddr[IMOS_IPADDR_LEN];
} MC_MCU_CONFIG_GK_EX_S;

/**
* @struct tagHASystem_InfoEx
* @brief 双机系统配置信息
* @attention
*/
typedef struct tagHASystem_InfoEx
{
    /** 对外服务的IP地址，所登录MCU的IP地址 */
    CHAR                szLocIp[IMOS_IPADDR_LEN];

    /** 远端IP地址， 备机的IP地址 */
    CHAR                szRemoteIp[IMOS_IPADDR_LEN];

    /** 对外服务的端口号， 规定填 0 */
    ULONG_32               ulLocPort;

    /** 远端端口号， 规定填 0 */
    ULONG_32               ulRemotePort;

    /** 配置BAK的状态 BAK_STATE_EX_E */
    ULONG_32               ulCfgBakState;

    /**  公安部版本为远端业务地址 */
    CHAR                szLoIp[IMOS_IPADDR_LEN];
}HA_SYSTEM_INFO_EX_S;

/**
* @struct tagHD_MPPromptCfgEx
* @brief 配置使用默认提示音和图片
* @attention
*/
typedef  struct  tagHD_MPPromptCfgEx
{
    /** BOOL_TRUE, 使用默认提示音 */
    BOOL_T          bUseDefaultPromptSound;

    /** BOOL_TRUE, 使用默认提示图片 */
    BOOL_T          bUseDefaultPromptPic;
} HD_MP_PROMPT_CFG_EX_S;

/**
* @struct tagMC_MCULanARPTableEx
* @brief LAN板的已经连接的外部网口数，每个已经连接的网口的ARP表、路由表的信息
* @attention
*/
typedef struct tagMC_MCULanARPTableEx
{
    /** 已经连接的网口个数 */
    ULONG_32              ulCount;

    /** 每个网口的路由记录数 */
    LONG_32               alRouteCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** 路由表 */
    MC_MCU_ROUTE_EX_S  astRouteTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ROUTE_NUM];

    /** 每个网口的ARP记录数 */
    LONG_32               alARPCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** ARP表 */
    MC_MCU_ARP_EX_S    astARPTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ARP_NUM];
} MC_MCU_LAN_ROUTE_ARP_TABLE_EX_S;


/**
* @struct tagMC_VersionCfgEx
* @brief 版本配置
* @attention
*/
typedef struct tagMC_VersionCfgEx
{
    /** 是否演示版本 */
    BOOL_T bIsTestVersion;

    /** 是否支持组播 */
    BOOL_T bSupportMulticast;

    /** 是否支持Nat */
    BOOL_T bSupportNat;
} MC_VERSION_CONFIG_EX_S;


/**
 * @struct tagMC_MCUConfigAllEx
 * @brief MCU配置
 * @attention
 */
typedef struct tagMC_MCUConfigAllEx
{
    /** 双线路备份特性 是否启用备份线路策略 */
    BOOL_T                               bUseBakLayer;

    /** 双线路备份特性 双线路备份IP配置 */
    MC_BACKUP_LAYER_IP_CFG_EX_S          stBackupLanIP;

    /** 声光告警配置 */
    MC_MCU_CONFIG_ALARM_EX_S             stConfigAlarm;

    /** 网口配置 */
    MC_MCU_LAN_IP_EX_S                    stConfAddr;

    /** MCU普通信息 */
    MC_MCU_CONFIG_NORMAL_EX_S             stConfNormal;

    /** MCU的GK配置 */
    MC_MCU_CONFIG_GK_EX_S                 stConfGK;

    /** 路由表、ARP表*/
    MC_MCU_LAN_ROUTE_ARP_TABLE_EX_S       stConfRouteARP;

    /** NAT配置 */
    MC_MCU_CONFIG_NAT_EX_S                stConfNAT;

    /** 服务级别 */
    HD_QOS_SERV_EX_S                      stQosServ;

    /** 颜色值 */
    HD_MCU_COLOR_VALUE_EX_S               stColorValue;

    /** 是否支持RIP协议 */
    BOOL_T                                bRIPEnabled;

    /** GK注册状态 HD_RESULT_EX_E */
    ULONG_32                                 ulGkRegState;

    /** MCU运行模式 */
    HA_SYSTEM_INFO_EX_S                   stMcuRunMode;

    /** NTP服务配置 */
    MC_MCU_NTP_INFO_EX_S                  stNTPInfo;

    /** MP提示配置 */
    HD_MP_PROMPT_CFG_EX_S                 stMPPromptCfg;

    /** 版本配置 */
    MC_VERSION_CONFIG_EX_S                stVersionCfg;
} MC_MCU_CONFIG_ALL_EX_S;

#if 0
#endif

/**
 * @struct tagConfContactInfo
 * @brief 会议联系人信息
 * @attention
 */
typedef struct tagConfContactInfo
{
    /** 联系人ID */
    IMOS_ID idContactId;

    /** 联系人姓名 */
    CHAR    szContactName[IMOS_NAME_LEN];

    /** 联系人移动电话 */
    CHAR    szMobilePhone[IMOS_MOBILE_LEN];

    /** 联系人电子邮件 */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** 联系人Notes邮件 */
    CHAR    szNotesEmail[IMOS_MAIL_LEN];

    /** 联系人所在的部门 */
    CHAR    szDepartment[IMOS_NAME_LEN];

    /** 联系人备注 */
    CHAR    szDesc[IMOS_DESC_LEN];
}CONF_CONTACT_INFO_EX_S;

#if 0
#endif

/**
 * @struct tagDeviceBaseInfo
 * @brief MG视讯设备基本信息
 * @attention
 */
typedef struct tagDeviceBaseInfo
{
    /** 设备名称 */
    CHAR  szDevName[IMOS_SITE_NAME_LEN];

    /** 设备类型， IMOS_TYPE_E */
    ULONG_32 ulDevType;

    /** 设备子类型， MC_DEVICE_TYPE_EX_E */
    ULONG_32 ulDevSubType;

    /** 设备地址类型: IMOS_IPADDR_TYPE_IPV4、IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32 ulDevAddrType;

    /**设备地址 */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线：设备在线状态IMOS_DEV_STATUS_ONLINE，设备离线状态IMOS_DEV_STATUS_OFFLINE */
    ULONG_32 ulIsOnline;

    /** 所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备扩展状态*/
    ULONG_32 ulDevExtStatus;

    /** 设备描述 , 现在只能填写为空 */
    CHAR  szDevDesc[IMOS_DESC_LEN];
}DEVICE_BASE_INFO_S;


/**
 * @struct tagTerminalQueryItemEx
 * @brief MG视讯终端列表查询单元信息
 * @attention
 */
typedef struct tagTerminalQueryItemEx
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** E.164号码 */
    CHAR  szDevE164Num[IMOS_CONF_ALIAS_LEN];

    /** H.323 ID */
    CHAR  szDevH323Id[IMOS_CONF_ALIAS_LEN];

    /** 终端总带宽 HD_BITRATE_EX_E */
    ULONG_32 ulBandWidth;

    /** 终端状态 MG_SESSION_STATUS_E */
    ULONG_32 ulCallStatus;

    /** BOOL_TRUE表示为第三方设备 */
    BOOL_T             bIs3rdTerm;

    /** 设备基本信息 */
    DEVICE_BASE_INFO_S stDeviceBaseInfo;
}TERMINAL_QURERY_ITEM_EX_S;

/**
 * @struct tagMC_TermAlarmInfoEx
 * @brief 终端告警信息
 * @attention
 */
typedef struct tagMC_TermAlarmInfoEx
{
    /** 告警号 */
    LONG_32                      lAlarmID;

    /** 告警状态 MC_TERM_ALARM_STATUS_EX_E，增加终端时不用，填0 */
    ULONG_32                     ulAlarmStatus;
} MC_TERM_ALARM_INFO_EX_S;

/**
* @struct tagMC_Site_BFD_Layer_Switch_ModeEx
* @brief 会场链路切换模式结构
* @attention
*/
typedef struct tagMC_Site_BFD_Layer_Switch_ModeEx
{
    /** 切换方式 MC_LINK_LAYER_SWITCH_MODE_EX_E */
    ULONG_32 ulSwitchMode;

    /** 目的链路 MC_LINK_LAYER_TYPE_EX_E */
    ULONG_32 ulLinkLayer;
} MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S;


/**
* @struct tagMC_Site_BFD_LinkLayer_InfoEx
* @brief 会场使用的链路信息结构
* @attention
*/
typedef struct tagMC_Site_BFD_LinkLayer_InfoEx
{
    /** 当前使用的链路 MC_LINK_LAYER_TYPE_EX_E */
    ULONG_32 ulInUseLayer;

    /** 各链路的连接状态 MC_LINK_LAYER_STATE_EX_E */
    ULONG_32 aulLayerState[IMOS_EN_LINK_LAYER_TYPE_COUNT];
} MC_SITE_BFD_LINK_LAYER_INFO_EX_S;

/**
* @struct tagMC_LinkInfoEx
* @brief 双链路信息
* @attention
*/
typedef struct tagMC_LinkInfoEx
{
    /** 主备链路IP地址 */
    CHAR                               szIpAddressMain[IMOS_IPADDR_LEN];
    CHAR                               szIpAddressBak[IMOS_IPADDR_LEN];

    /** 各链路带宽 HD_BITRATE_EX_E */
    ULONG_32                              ulBandWidthMain;
    ULONG_32                              ulBandWidthBak;

    /** 链路切换模式 */
    MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S stLayerSwitchMode;

    /** 链路信息，增加终端时不用，填0 */
    MC_SITE_BFD_LINK_LAYER_INFO_EX_S   stLayerInfo;
} MC_LINK_INFO_EX_S;

/**
 * @struct tagTerminalConfigEx
 * @brief MG视讯终端常用参数
 * @attention
 */
typedef struct tagTerminalConfigEx
{
    /** E.164号码 */
    CHAR  szDevE164Num[IMOS_CONF_ALIAS_LEN];

    /** H.323 ID */
    CHAR  szDevH323Id[IMOS_CONF_ALIAS_LEN];

    /** 终端业务IP地址 */
    CHAR                   szTermAddr[IMOS_IPADDR_LEN];

    /** 终端总带宽 HD_BITRATE_EX_E */
    ULONG_32                  ulBandWidth;

    /** 终端协议类型 MC_PROTOCOL_TYPE_EX_E */
    ULONG_32                  ulProtocolType;

    /** 终端音视频使用类型 MC_TERM_TYPE_EX_E */
    ULONG_32                  ulTermType;

    /** BOOL_TRUE表示为第三方设备 */
    BOOL_T                 bIs3rdTerm;

    /** 终端状态 MG_SESSION_STATUS_E */
    ULONG_32                  ulSiteStatus;

    /** 是否丢包会场 */
    BOOL_T                 bLostPacketSite;

    /** MCU类型终端的呼叫配置 MC_MCU_CALL_TYPE_EX_E */
    ULONG_32                  ulMCUCallType;

    /** 双链路信息 */
    MC_LINK_INFO_EX_S      stLinkInfo;

    /** 告警信息 */
    MC_TERM_ALARM_INFO_EX_S stAlarmInfo;
}TERMINAL_CONFIG_EX_S;

/**
 * @struct tagTerminalCapacityEx
 * @brief MG视讯终端的能力集
 * @attention
 */
typedef struct tagTerminalCapacityEx
{
    /** 配置的主流信息 */
    MC_TERM_VIDEO_CFG_EX_S stMainVideoCfg;

    /** 配置的辅流信息 */
    MC_TERM_ROLEVIDEO_CFG_EX_S stRoleVideoCfg;

    /** 支持音频标准的个数 */
    LONG_32                lAudioCount;

    /** 支持的音频标准 HD_AUDIO_PROT_EX_E */
    ULONG_32               aulAudioProt[IMOS_EN_AUD_PROT_COUNT];

}TERMINAL_CAPACITY_EX_S;

/**
* @struct tagMcuBackupInfoEx
* @brief MCU备份信息
* @attention
*/
typedef struct tagMcuBackupInfoEx
{
    /** MCU备份类型 MCU_BACKUP_TYPE_E 专用于备份的MCU、可用于备份的MCU、不能用于备份的MCU */
    ULONG_32 ulBackupType;

    /** 备份范围MCU_BACKUP_SCOPE_E 只用于备份当前域的MCU、可用于备份当前域和子孙域的MCU，目前暂不支持 */
    ULONG_32 ulBackupScope;

    /** 备份优先级，目前暂不支持 */
    ULONG_32 ulBackupPriority;
}MCU_BACKUP_INFO_EX_S;

/**
 * @struct tagMcuBaseInfoEx
 * @brief MCU基本信息
 * @attention
 */
typedef struct tagMcuBaseInfoEx
{
   /** 设备编码 */
   CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

   /** MCU备份信息 */
   MCU_BACKUP_INFO_EX_S stMcuBackupInfo;

   /** 设备基本信息 */
   DEVICE_BASE_INFO_S stDeviceBaseInfo;
}MCU_BASE_INFO_EX_S;



 /**
  * @struct tagConfQueryItemEx
  * @brief 会议查询单元信息
  * @attention
  */
 typedef struct tagConfQueryItemEx
 {
     /** 会议ID */
     IMOS_ID  idConfId;

     /** 是否是iMSC创建的会议 */
     ULONG_32 ulConfIsImscCreated;

     /** 会议名称 或 会议模板名字 */
     CHAR  szConfName[IMOS_NAME_LEN];

     /** 会议创建者 */
     CHAR  szCreater[IMOS_NAME_LEN];

     /** 会议模式 MC_CONF_MODE_EX_E */
     ULONG_32 ulConfMode;

     /** 会议方数 */
     LONG_32  lSiteCount;

     /** 会议速率 HD_BITRATE_EX_E */
     ULONG_32 ulBitRate;

     /** 会议召开时间，对于会议模板无效*/
     LONG_32  lStartTime;

     /** 会议总时长，单位是秒，对于会议模板无效 */
     LONG_32  lTotalDuration;

     /** 会议剩余时长，单位是秒。只有对于活动会议有效 */
     LONG_32  lLeftDuration;

     /** 是否支持组播 */
     ULONG_32  ulMultiCast;

     /** 会议是否是永久会议 */
     BOOL_T bConfForever;

     /** 所属组织编码 */
     CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

 }CONF_QUERY_ITEM_EX_S;

/**
 * @struct tagConfSiteCasteEx
 * @brief MG视讯终端的级联信息
 * @attention
 */
typedef struct tagConfSiteCasteEx
{
    /** 终端编码 */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** 终端所在MCU的编码 */
    CHAR  szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];
}CONF_SITE_CASTE_EX_S;

/**
 * @struct tagConfSiteName
 * @brief MG视讯终端的名字信息
 * @attention
 */
typedef struct tagConfSiteName
{
    /** 终端编码 */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];
}CONF_SITE_NAME_S;

/**
* @struct tagConfTermNameType
* @brief 终端的名字信息和类型
* @attention
*/
typedef struct tagConfTermNameType
{
    /** 终端编码 */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 终端类型(TERM_QUERY_TYPE_E) */
    ULONG_32 ulTermType;

}CONF_TERM_NAME_TYPE_S;


/**
 * @struct tagConfContact
 * @brief 会议联系人
 * @attention
 */
typedef struct tagConfContact
{
    /** 联系人ID */
    IMOS_ID idContactId;

    /** 联系人姓名 */
    CHAR    szContactName[IMOS_NAME_LEN];
}CONF_CONRTACT_S;


/**
 * @struct tagConfSiteCircleEx
 * @brief MG视讯终端的轮巡信息
 * @attention
 */
typedef struct tagConfSiteCircleEx
{
    /** 轮巡表序号 MC_CYCLE_TABLE_INDEX_EX_E */
    ULONG_32 ulTableIndex;

    /** 设备编码 */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR  szTermName[IMOS_NAME_LEN];
}CONF_SITE_CIRCLE_EX_S;

/**
 * @struct tagConfMcuCasteEx
 * @brief 会议的MCU信息
 * @attention ulMcuOnlineStatus只在SDK中使用（给界面的出参中使用），内部接口默认无效值，界面入参无需使用（无效值）
 */
typedef struct tagConfMcuCasteEx
{
    /** MCU编码 */
    CHAR  szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 上级MCU编码 */
    CHAR  szUpperMcuCode[IMOS_DEVICE_CODE_LEN];

    /** MCU上分会议的状态 MC_CONF_STATUS_EX_E */
    ULONG_32 ulMCUConfStatus;

    /** MCU上分会议的ID，-1为无效的会议ID */
    LONG_32 lConfIdInMcu;

    /** MCU在线状态 DEV_ONLINE_STATUS_E*/
    ULONG_32 ulMcuOnlineStatus;

    /** 组播配置参数 */
    MC_MULTICAST_INFO_EX_S      stMulticastInfo;
}CONF_MCU_CASTE_EX_S;

/**
 * @struct tagConfSiteInfoEx
 * @brief  会场处理信息
 * @attention
 */
typedef struct tagConfSiteInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 会场编码 */
    CHAR  szSiteCode[IMOS_RES_CODE_LEN];

    /** 会场名称 */
    CHAR  szSiteName[IMOS_NAME_LEN];
}CONF_SITE_INFO_EX_S;


/**
 * @struct tagTermStatusChangeEx
 * @brief  终端状态改变
 * @attention
 */
typedef struct tagTermStatusChangeEx
{
    /** 会场编码 */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** 会场名称 */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** 终端状态 MC_SITE_STATUS_EX_E */
    ULONG_32    ulSiteStatus;

    /** 会议ID， 终端目前参加的会议ID，不在会议中为0，0时以下参数无效 */
    IMOS_ID  idConfId;

    /** 麦克风是否关闭，是否闭音 */
    BOOL_T   bCloseMic;

    /** 扬声器是否关闭，是否静音 */
    BOOL_T   bCloseSpeaker;

    /** 是否主场 */
    BOOL_T   bIsChair;

    /** 是否广播 */
    BOOL_T   bIsBroadcast;

    /** 当前被该会场查看的终端模式 MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulTermWatchedSiteType;

    /** 当前被该会场查看的终端 */
    CHAR     szTermWatchedCode[IMOS_RES_CODE_LEN];
    CHAR     szTermWatchedName[IMOS_NAME_LEN];

    /** 网络是否连接正常 */
    BOOL_T   bConnected;
}TERM_STATUS_CHANGE_EX_S;

/**
* @struct tagCallSiteInfoEx
* @brief  呼叫会场信息
* @attention
*/
typedef struct tagCallSiteInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 会场编码 */
    CHAR  szSiteCode[IMOS_RES_CODE_LEN];

    /** 会场名称 */
    CHAR  szSiteName[IMOS_NAME_LEN];

    /** 呼叫失败结果 具体取值参见imos_ss_err.h错误码文件 */
    ULONG_32 ulCallFailRslt;
}CALL_SITE_INFO_EX_S;

/**
* @struct tagGKRegStateInfoEx
* @brief  GK注册结果信息
* @attention
*/
typedef struct tagGKRegStateInfoEx
{
    /** MCU编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** GK注册结果具体取值参见imos_ss_err.h */
    ULONG_32  ulGKRegState;
}GK_REG_STATE_INFO_EX_S;

/**
* @struct tagMgSessionStatusEx
* @brief MG会话状态上报结构
* @attention
*/
typedef struct tagMgSessionStatusEx
{
    /** 终端编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** MG终端状态具体取值参见MG_SESSION_STATUS_E */
    ULONG_32  ulMgSessionStatus;
}MG_SESSION_STATUS_EX_S;

/**
 * @struct tagConfResStatusChangeInfoEx
 * @brief  会议资源分配状态改变
 * @attention
 */
typedef struct tagConfResStatusChangeInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;


    /** 分配成功/失败 */
    BOOL_T   bAssinFlag;
}CONF_RES_STATUS_CHANGE_INFO_EX_S;


/**
* @struct tagDeviceChangeInfoEx
* @brief  终端设备更新信息
* @attention
*/
typedef struct tagDeviceChangeInfoEx
{
    /** 会议ID， 当设备不在会议中， 会议ID无意义 */
    IMOS_ID  idConfId;

    /** MCU编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 会场数 */
    ULONG_32 ulSiteCount;

    /** 会场名字和类型信息 */
    CONF_TERM_NAME_TYPE_S stTermNameType[IMOS_HD_MAX_SITE_PER_CONF_NUM];

    /** 更新类型， 新增、修改、删除 DEVICE_OPERATE_TYPE_E */
    ULONG_32    ulChangeType;
}DEVICE_CHANGE_INFO_EX_S;

/**
 * @struct tagDelayConfInfoEx
 * @brief  会议延长信息
 * @attention
 */
typedef struct tagDelayConfInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 会议延迟时间, 时间单位为分钟 */
    LONG_32  lDelayTime;
}DELAY_CONF_INFO_EX_S;

/**
 * @struct tagMC_SynchronizeWithWebEx
 * @brief  广播会场， 主席、主场观看会场
 * @attention
 */
typedef struct tagMC_SynchronizeWithWebEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 预定广播会场 */
    CHAR     szSetBroadcastSiteCode[IMOS_RES_CODE_LEN];
    CHAR     szSetBroadcastSiteName[IMOS_NAME_LEN];

    /** 实际广播会场模式 MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurBroadcastSiteType;

    /** 实际广播会场 */
    CHAR    szCurBroadcastSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurBroadcastSiteName[IMOS_NAME_LEN];

    /** 主席、主场预定观看会场 */
    CHAR    szSetChairBrowseSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szSetChairBrowseSiteName[IMOS_NAME_LEN];

    /** 主席、主场实际观看会场模式 MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurChairBrowseSiteType;

    /** 主席、主场实际观看会场 */
    CHAR    szCurChairBrowseSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurChairBrowseSiteName[IMOS_NAME_LEN];
} MC_SYNCHRONIZE_WITH_WEB_EX_S;

/**
* @struct tagCurBroadcastInfoEx
* @brief  当前实际广播会场
* @attention
*/
typedef struct tagCurBroadcastInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 实际广播会场 */
    CHAR    szCurBroadcastSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurBroadcastSiteName[IMOS_NAME_LEN];

    /** 实际广播会场模式MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurBroadcastSiteType;
} CUR_BROADCAST_INFO_EX_S;

/**
* @struct tagCurChairBrowseInfoEx
* @brief  当前主席、主场观看会场
* @attention
*/
typedef struct tagCurChairBrowseInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 主席、主场实际观看会场 */
    CHAR    szCurChairBrowseSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurChairBrowseSiteName[IMOS_NAME_LEN];

    /** 主席、主场实际观看会场模式MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurChairBrowseSiteType;
} CUR_CHAIR_BROWSE_INFO_EX_S;

/**
 * @struct tagAppointChairInfoEx
 * @brief  指定主席信息
 * @attention
 */
typedef struct tagAppointChairInfoEx
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 会场编码 */
    CHAR  szSiteCode[IMOS_RES_CODE_LEN];

    /** 指定主场唯一标识 */
    CHAR  szSetChairCode[IMOS_RES_CODE_LEN];

    /** 当前主场唯一标识 */
    CHAR  szCurChairCode[IMOS_RES_CODE_LEN];
}APPOINT_CHAIR_INFO_EX_S;


/**
 * @struct tagConfStatusInfoEx
 * @brief  会议状态信息
 * @attention
 */
typedef struct tagConfStatusInfoEx
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** MCU级联类型 CONF_MCU_CASCADE_TYPE_E */
    ULONG_32                   ulMcuCascType;

    /** 会议ID */
    IMOS_ID                 idConfId;

    /** 会议状态 MC_CONF_STATUS_EX_E */
    ULONG_32                   ulConfStatus;
}CONF_STATUS_INFO_EX_S;


/**
 * @struct tagDeviceCodeChangeInfoEx
 * @brief  设备编码改变信息
 * @attention
 */
typedef struct tagDeviceCodeChangeInfoEx
{
    /** 原终端编码 */
    CHAR szOldSiteCode[IMOS_RES_CODE_LEN];

    /** 新终端名字和类型 */
    CONF_TERM_NAME_TYPE_S stNewConfTermNameType;

}DEVICE_CODE_CHANGE_INFO_EX_S;

/**
 * @struct tagSiteSelectBrowseSiteInfoEx
 * @brief  某会场选择了一个观看的会场的信息
 * @attention
 */
typedef struct tagSiteSelectBrowseSiteInfoEx
{
    /** 会议ID */
    IMOS_ID                 idConfId;


    /** 会场编码 */
    CHAR                    szSiteCode[IMOS_RES_CODE_LEN];

    /** 被观看会场的编码 */
    CHAR                    szBeBrowsedSiteCode[IMOS_RES_CODE_LEN];
}SITE_SELECT_BROWSE_SITE_INFO_EX_S;

/**
 * @struct tagConfSiteCodeEx
 * @brief MG视讯终端的设备编码
 * @attention
 */
typedef struct tagConfSiteCodeEx
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];
}CONF_SITE_CODE_EX_S;

/**
 * @struct tagConfMcuCodeEx
 * @brief MCU的设备编码
 * @attention
 */
typedef struct tagConfMcuCodeEx
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];
}CONF_MCU_CODE_EX_S;

/*************************************************************************************
SS MG会场终端配置数据结构
***************************************************************************************/
/**
* @struct tagHD_AnswerConfigEx
* @brief 接听配置
* @attention
*/
typedef struct tagHD_AnswerConfigEx
{

    /** 自动应答*/
    BOOL_T                  bAutoAnswer;

    /** 多少秒后自动应答 */
    LONG_32                    lRingTime;

    /** 铃音音量 HD_AUDIO_VOLUME_EX_E */
    ULONG_32                   ulRingVol;

    /** 铃音选择 HD_RING_TYPE_EX_E */
    ULONG_32                   ulRingType;
    LONG_32                    lReserved[8];
}HD_ANSWER_CONFIG_EX_S;

/**
* @struct tagHD_Sys_Started_CfgEx
* @brief 开机画面/开机铃声等相关内容(未完)
* @attention
*/
typedef struct tagHD_Sys_Started_CfgEx
{

    /** 开机铃声 HD_RING_TYPE_EX_E */
    ULONG_32       ulRingType;
}HD_SYS_STARTED_CFG_EX_S;

/**
 * @struct tagHD_OtherConfigParamEx
 * @brief MG其他配置参数
 * @attention
 */
typedef struct tagHD_OtherConfigParamEx
{
    /** 接听设置配置参数  */
    HD_ANSWER_CONFIG_EX_S            stAnswerParam;



    /** 开机内容 */
    HD_SYS_STARTED_CFG_EX_S          stStartedParam;
} MC_OTHERCONFIGPARAM_EX_S;


/**
* @struct tagHD_H323ConfigEx
* @brief h323设置
* @attention
*/
typedef struct tagHD_H323ConfigEx
{

    /** 是否使用服务器 */
    BOOL_T           bUseServer;

    /** 服务器ip地址 */
    CHAR             szServerIP[IMOS_IPADDR_LEN];

    /** 注册号码 */
    CHAR             szRegNumber[IMOS_HD_MAX_NAME_LENGTH];

    /** 注册密码 */
    CHAR             szRegPasswd[IMOS_HD_MAX_PASSWORD_LENGTH];

    /** H323 ID */
    CHAR             szH323id[IMOS_HD_MAX_NAME_LENGTH];

    /** 是否使用H323ID注册 */
    BOOL_T           bUseH323id;

    /** 是否设置系统名 */
    BOOL_T           bSetSysName;

    /** H323 系统名 */
    CHAR             szSysName[IMOS_HD_MAX_NAME_LENGTH];
    LONG_32             lReserved[2];
}HD_H323_CONFIG_EX_S;



/**
* @struct tagHD_SIPConfigEx
* @brief SIP设置
* @attention
*/
typedef struct tagHD_SIPConfigEx
{

    /** 是否使用服务器 */
    BOOL_T               bUseServer;

    /** 服务器ip地址 */
    CHAR                 szServerIP[IMOS_IPADDR_LEN];

    /** 注册号码 */
    CHAR                 szRegNumber[IMOS_HD_MAX_NAME_LENGTH];

    /** 注册密码 */
    CHAR                 szRegPasswd[IMOS_HD_MAX_PASSWORD_LENGTH];

    /** SIP注册ID */
    CHAR                 szRegid[IMOS_HD_MAX_NAME_LENGTH];
    LONG_32                 lReserved[2];
}HD_SIP_CONFIG_EX_S;

/**
 * @struct tagHD_ProtocolAllEx
 * @brief 协议设置
 * @attention
 */
typedef struct tagHD_ProtocolAllEx
{

    /** 是否选择对应协议 */
    BOOL_T              abProtoType[IMOS_EN_PROTO_TYPE_COUNT];

    /** H.323配置 */
    HD_H323_CONFIG_EX_S stH323Config;

    /** SIP配置 */
    HD_SIP_CONFIG_EX_S  stSIPConfig;
    LONG_32                alReserved[8];
}HD_PROTOCOL_ALL_EX_S;


/**
* @struct tagHD_ConnetConfigEx
* @brief 网络连接设置
* @attention
*/
typedef struct tagHD_ConnetConfigEx
{

    /** 网络连接方式 HD_CONNECT_TYPE_EX_E */
    ULONG_32                   ulConnectType;

    /** 网络接入带宽 HD_BITRATE_EX_E */
    ULONG_32                   ulBandwidth;

    /* 固定IP的设置 */

    /** ip地址 */
    CHAR                    szIPaddr[IMOS_IPADDR_LEN];

    /** 子网掩码 */
    CHAR                    szSubmask[IMOS_IPADDR_LEN];

    /** 网关 */
    CHAR                    szGateway[IMOS_IPADDR_LEN];

    /* PPPoE的设置 */

    /** 用户名 */
    CHAR                    szPppoe_user[IMOS_HD_MAX_NAME_LENGTH];

    /** 密码 */
    CHAR                    szPppoe_passwd[IMOS_HD_MAX_PASSWORD_LENGTH];

    LONG_32                    alReserved[8];
}HD_CONNECT_CONFIG_EX_S;

/**
 * @struct tagHD_AllConnetConfigEx
 * @brief 所有网络连接设置
 * @attention
 */
typedef struct tagHD_AllConnetConfigEx
{
    /** 所有网口的连接设置 */
    HD_CONNECT_CONFIG_EX_S astAllConnectCfg[IMOS_EN_HD_NIC_COUNT];
}HD_ALLCONNECT_CONFIG_EX_S;

/**
 * @struct tagHD_NIC_Number_CfgEx
 * @brief 当前使用的网口号
 * @attention
 */
typedef struct tagHD_NIC_Number_CfgEx
{

    /** 网口号 HD_NIC_NUMBER_EX_E */
    ULONG_32  ulNIC;
}HD_NIC_NUMBER_CFG_EX_S;

/**
* @struct tagHD_NicConfigEx
* @brief 网口设置
* @attention
*/
typedef struct tagHD_NicConfigEx
{

    /** 网口类型 自动/全双工/半双工 HD_NETCARD_DUPLEX_TYPE_EX_E */
    ULONG_32                        ulNICType;

    /** 网口速率 HD_NETCARD_RATE_EX_E */
    ULONG_32                        ulNICSpeed;

    /** 网卡设置方式 HD_NETCARD_SET_TYPE_EX_E */
    ULONG_32                        ulCardSetType;
    LONG_32                         lReserved[4];
}HD_NICCONFIG_EX_S;

/**
 * @struct tagHD_AllNicConfigEx
 * @brief 所有网口配置
 * @attention
 */
typedef struct tagHD_AllNicConfigEx
{

    /** 网口配置信息 */
    HD_NICCONFIG_EX_S     astNICConfig[IMOS_EN_HD_NIC_COUNT];
    LONG_32                  alReserved[7];
}HD_ALLNIC_CONFIG_EX_S;


/**
* @struct tagHD_NetConfigEx
* @brief 内网配置信息结构
* @attention
*/
typedef struct tagHD_NetConfigEx
{
    /** 网段 */
    CHAR                   szNetIP[IMOS_IPADDR_LEN];

    /** 子网掩码 */
    CHAR                   szNetMask[IMOS_IPADDR_LEN];
    LONG_32                   lReserved[2];
}HD_NET_CONFIG_EX_S;


/**
* @struct tagHD_NATConfigEx
* @brief NAT 设置
* @attention
*/
typedef struct tagHD_NATConfigEx
{

    /** 是否使用 NAT 地址 */
    BOOL_T                  bUseNAT;

    /** NAT地址 */
    CHAR                    szNATAddr[IMOS_IPADDR_LEN];

    /** NAT网关地址 */
    CHAR                    szNATGateway[IMOS_IPADDR_LEN];

    /* 端口设置 */

    /** 是否使用固定端口 */
    BOOL_T                  bUseFixedPort;

    /** 呼叫端口 */
    ULONG_32                   ulCallPort;

    /** RAS端口 */
    ULONG_32                   ulRasPort;

    /** 数据端口 */
    ULONG_32                   ulDataPort;

    /** 音频端口 */
    ULONG_32                   ulAudioPort;

    /** 主流视频 */
    ULONG_32                   ulMainVideoPort;

    /** 辅流视频 */
    ULONG_32                   ulSecVideoPort;

    /** h225/h245使用  */
    ULONG_32                   ulOtherTcpPort1;

    /** h225/h245使用 */
    ULONG_32                   ulOtherTcpPort2;

    /* 内网设置 */

    /** 私网个数 */
    USHORT                  usPriNetCount;

    /** 保留字段用于字节对齐 */
    USHORT                  usReserved;

    /** 私网配置 */
    HD_NET_CONFIG_EX_S      astPriNetConfig[IMOS_HD_MAX_PRIVATE_NET_COUNT];
    LONG_32                    alReserved[8];
}HD_NAT_CONFIG_EX_S;

/**
 * @struct tagHD_AllNATConfigEx
 * @brief NAT 设置
 * @attention
 */
typedef struct tagHD_AllNATConfigEx
{
    HD_NAT_CONFIG_EX_S    astAllNATCfg[IMOS_EN_HD_NIC_COUNT];
}HD_ALL_NAT_CONFIG_EX_S;

/**
 * @struct tagHD_NTPConfigEx
 * @brief NTP设置
 * @attention
 */
typedef struct tagHD_NTPConfigEx
{

    /** 是否使用NTP */
    BOOL_T                    bUseNTP;

    /** NTP服务器地址 */
    CHAR                      szNTPServer[IMOS_IPADDR_LEN];
    LONG_32                      alReserved[8];
}HD_NTP_CONFIG_EX_S;

/**
 * @struct tagHD_MvConfigEx
 * @brief 主流设置
 * @attention
 */
typedef struct tagHD_MvConfigEx
{

    /** 是否自动发送主流视频 */
    BOOL_T                     bAutoSend;

    /** 能力优先级 HD_VIDEO_PROT_EX_E */
    ULONG_32                      ulCapacity;

    /** 帧率 HD_FRAMERATE_TYPE_EX_E */
    ULONG_32                      ulFramRate;

    /** 图像格式 HD_VIDEO_FORMAT_EX_E */
    ULONG_32                      ulVideoFmt;
    LONG_32                       alReservered[8];
}HD_MV_CONFIG_EX_S;


/**
 * @struct tagHD_RvConfigEx
 * @brief 辅流设置
 * @attention
 */
typedef struct tagHD_RvConfigEx
{

    /** 是否使用辅流 */
    BOOL_T                     bStartRV;

    /** 是否自动发送辅流视频 */
    BOOL_T                     bAutoSend;

    /** 能力优先级 HD_VIDEO_PROT_EX_E */
    ULONG_32                      ulCapacity;

    /** 双流模式 HD_ROLE_VIDEO_TYPE_EX_E */
    ULONG_32                      ulRoleVideoType;

    /** 辅流带宽 HD_BITRATE_EX_E */
    ULONG_32                      ulBandwidth;

    /** 隐私设置 */
    BOOL_T                     bPrivate;

    /** 帧率 HD_FRAMERATE_TYPE_EX_E */
    ULONG_32                      ulFramRate;
    LONG_32                       alReservered[7];
}HD_RV_CONFIG_EX_S;


/**
* @struct tagHD_VideoOutInfoEx
* @brief 视频输出信息
* @attention
*/
typedef struct tagHD_VideoOutInfoEx
{

    /** 视频输出端口 HD_VIDEO_OUT_PORT_EX_E */
    ULONG_32                           ulVideoOutPort;

    /** 视频输出内容 HD_VIDEO_OUT_CONTENT_TYPE_EX_E */
    ULONG_32                           ulVideoOutContent;
} HD_VIDEO_OUT_INFO_EX_S;

/**
 * @struct tagHD_VideoInOutEx
 * @brief 视频输入输出配置
 * @attention
 */
typedef struct tagHD_VideoInOutEx
{

    /** 视频输入配置 HD_VIDEO_IN_PORT_EX_E */
    ULONG_32                  aulVideoIn[IMOS_EN_VIDEO_TYPE_COUNT];

    /** 视频输出配置 */
    HD_VIDEO_OUT_INFO_EX_S astVideoOut[IMOS_HD_VIDEO_OUT_NUM];
} HD_VIDEO_INOUT_EX_S;


/**
* @struct tagHD_AudioInOutEx
* @brief 音频输入输出配置
* @attention
*/
typedef  struct    tagHD_AudioInOutEx
{

    /** 音频输入配置 */
    BOOL_T                         abAudioIn[IMOS_EN_AUDIO_IN_PORT_COUNT];

    /** 音频输入配置 */
    BOOL_T                         abAudioOut[IMOS_EN_AUDIO_OUT_PORT_COUNT];

    /** 音频 RCA 输入端口类型 HD_AUDIO_IN_PORT_SUB_TYPE_EX_E  */
    ULONG_32                          aulAudioInPortType[IMOS_EN_AUDIO_IN_PORT_COUNT];
} HD_AUDIO_INOUT_EX_S;

/**
* @struct tagHD_Record_CfgEx
* @brief 录音配置
* @attention
*/
typedef  struct    tagHD_Record_CfgEx
{

    /** 是否使用录音 */
    BOOL_T                      bUseRecord;

    /** 录音存储类型 HD_RECORD_STORAGE_TYPE_EX_E */
    ULONG_32                       ulStorageType;

    /** 录音存储路径 */
    CHAR                        szPath[IMOS_HD_MAX_PATH_LENGTH];

    /** 录音输出接口类型 HD_AUDIO_OUT_PORT_EX_E */
    ULONG_32                       ulOutPort;
} HD_RECORD_CFG_EX_S;

/**
 * @struct tagHD_AudioAllConfigEx
 * @brief 音频配置
 * @attention
 */
typedef struct tagHD_AudioAllConfigEx
{

    /** 音频输入输出端口 */
    HD_AUDIO_INOUT_EX_S     stInOutPorts;

    /** 是否自动发送音频 */
    BOOL_T                  bAutoSend;

    /** MIC回声抵消等级 HD_AEC_TYPE_EX_E */
    ULONG_32                   ulMICAEC;

    /** RCA回声抵消等级 HD_AEC_TYPE_EX_E */
    ULONG_32                   ulRCAAEC;

    /** 能力优先级 HD_AUDIO_PROT_EX_E */
    ULONG_32                   ulCapacity;

    /** 输入音量 HD_AUDIO_VOLUME_EX_E */
    ULONG_32                   aulInVol[IMOS_EN_AUDIO_IN_PORT_COUNT];

    /** 输出音量 HD_AUDIO_VOLUME_EX_E */
    ULONG_32                   ulOutVol;

    /** 是否启用自动增益 */
    BOOL_T                  bAutoAGC;

    /** 静音 */
    BOOL_T                  bSilence;

    /** 闭音 */
    BOOL_T                  bMute;

    /** 馈电(只针对 MIC )  */
    BOOL_T                  abFeedBack[IMOS_EN_AUDIO_IN_PORT_COUNT];

    /** 录音配置 */
    HD_RECORD_CFG_EX_S      stRecordCfg;
    LONG_32                    alReservered[5];
}HD_AUDIOALL_CONFIG_EX_S;

/**
 * @struct tagHD_InnerModuleDebugLevelEx
 * @brief 模块的调试级别组合信息
 * @attention
 */
typedef  struct  tagHD_InnerModuleDebugLevelEx
{

    /** 模块调试级别 HD_DEBUG_LEVEL_EX_E */
    ULONG_32               aulDebugLevel[IMOS_EN_HD_MODULE_TYPE_COUNT];

    /** 日志服务器地址 */
    CHAR                szServer[IMOS_IPADDR_LEN];
}HD_INNER_MODULE_DEBUG_LEVEL_EX_S;

/**
 * @struct tagHD_LogConfigEx
 * @brief 日志设置
 * @attention
 */
typedef struct tagHD_LogConfigEx
{

    /** 是否启用日志 */
    BOOL_T             bUseLOG;

    /** 对应日志类型是否启用 */
    BOOL_T             abLevel[IMOS_EN_HD_LOG_TYPE_COUNT];
    LONG_32               lReserved[8];
}HD_LOG_CONFIG_EX_S;

/**
 * @struct tagHD_UpdateConfigEx
 * @brief 升级设置
 * @attention
 */
typedef struct tagHD_UpdateConfigEx
{

    /** 是否自动升级 */
    BOOL_T          bAutoUpdate;

    /** 升级服务器ip地址 */
    CHAR            szServer[IMOS_IPADDR_LEN];

    /** 升级路径 */
    CHAR            szPath[IMOS_HD_MAX_PATH_LENGTH];

    /** 自动升级路径 */
    CHAR            szAutoPath[IMOS_HD_MAX_PATH_LENGTH];

    /** 升级文件名 */
    CHAR            szFilename[IMOS_HD_MAX_NAME_LENGTH];

    /** 本地版本号 */
    CHAR            szVersion[IMOS_HD_VERSION_LEN];

    /** 兼容版本区间 */
    CHAR            szVerRange[IMOS_EN_MAX_VERSION_COUNT][IMOS_HD_VERSION_LEN];
    LONG_32            lReserved[8];
}HD_UPDATE_CONFIG_EX_S;

/**
 * @struct tagHD_SiteConfigEx
 * @brief 会场设置 即信息设置
 * @attention
 */
typedef struct tagHD_SiteConfigEx
{
    HD_SITE_NAME_INFO_EX_S stSiteNameInfo;

    /** 是否使用 LOGO  */
    BOOL_T                  bUseLogo;

    /** 使用默认 LOGO 还是系统 LOGO，只有确认使用 LOGO 的情况下才能使用 HD_LOGO_TYPE_EX_E */
    ULONG_32                   ulLogoType;

    /** 日期 */
    TIME_T                  tiDate;

    /** 时间 */
    TIME_T                  tiTime;
    LONG_32                    lReserved[8];
}HD_SITE_CONFIG_EX_S;

/**
 * @struct tagHD_NAAConfigEx
 * @brief NAA设置
 * @attention
 */
typedef struct tagHD_NAAConfigEx
{

    /** 是否使用 NAA */
    BOOL_T             bUseNAA;

    /** 使用 NAA 的类型 HD_TNAA_TYPE_EX_E */
    ULONG_32              ulNAAType;
    LONG_32               alReservered[8];
}HD_NAA_CONFIG_EX_S;

/**
* @struct tagHD_CamPresetPosEx
* @brief 摄像机预置位结构
* @attention
*/
typedef struct tagHD_CamPresetPosEx
{

    /** 预置位的有效性 */
    BOOL_T         bValidPos;

    /** 左右位置 */
    USHORT         usPanPos;

    /** 上下位置 */
    USHORT         usTiltPos;

    /** 焦距位置 */
    USHORT         usZoomPos;

    USHORT         usReserved;
    LONG_32           alReserved[3];
}HD_CAM_PRESET_POS_EX_S;

/**
* @struct tagHD_CameraConfigEx
* @brief 摄像机结构
* @attention
*/
typedef struct tagHD_CameraConfigEx
{

    /** 名称，用于界面显示 22个字符不包括\0  */
    CHAR                      szName[IMOS_HD_MAX_NAME_LENGTH];

    /** 类型 HD_CAMERA_TYPE_EX_E */
    ULONG_32                     ulType;

    /** 运动速度 HD_CAMERA_SPEED_EX_E */
    ULONG_32                     ulSpeed;

    /** 控制串口 HD_CAMERA_PORT_EX_E */
    ULONG_32                     ulPort;

    /** 该摄像机的预置位 */
    HD_CAM_PRESET_POS_EX_S    astCamPresetPos[IMOS_HD_MAX_CAM_PRE_NUM];
    LONG_32                      alReserved[8];
}HD_CAMERA_CONFIG_EX_S;


/**
 * @struct tagAllCam_ConfigEx
 * @brief 摄像机配置
 * @attention
 */
typedef struct tagAllCam_ConfigEx
{
    HD_CAMERA_CONFIG_EX_S astCamCfg[IMOS_EN_VIDEO_IN_PORT_COUNT];
}HD_ALLCAM_CONFIG_EX_S;


/**
 * @struct tagAllCam_Preset_PosEx
 * @brief 摄像机预置位(ALL)
 * @attention
 */
typedef struct tagAllCam_Preset_PosEx
{

    /** 本地设本地预置位 */
    HD_CAM_PRESET_POS_EX_S astCamPos[IMOS_EN_VIDEO_IN_PORT_COUNT][IMOS_HD_MAX_CAM_PRE_NUM];

    /** 远端设本地预置位 */
    HD_CAM_PRESET_POS_EX_S astRemoteCamPos[IMOS_EN_VIDEO_IN_PORT_COUNT][IMOS_HD_MAX_CAM_PRE_NUM];

    /** 本地设远端预置位 */
    BOOL_T                 abRemoteNumber[IMOS_HD_MAX_CAM_PRE_NUM];
}HD_ALLCAM_PRESET_POS_EX_S;


/**
 * @struct tagHD_ConfServerEx
 * @brief ip 优先和服务优先信息
 * @attention
 */
typedef  struct tagHD_ConfServerEx
{

    /** 服务类型 HD_QOS_TYPE_EX_E */
    ULONG_32                           ulQOSType;

    /** 服务级别 */
    HD_IPPRECEDENCE_DIFFSERV_EX_U   unQOSLerver;
} HD_QOS_SERVER_EX_S;


/**
* @struct tagHD_VideoPortDVIFmtEx
* @brief DVI格式信息
* @attention
*/
typedef struct tagHD_VideoPortDVIFmtEx
{

    /** DVI输入类型 HD_VIDEO_PORT_DVI_TYPE_EX_E */
    ULONG_32     ulVideoPortDVIType;

    /** 视频分辨率大小 HD_VIDEO_FORMAT_EX_E */
    ULONG_32     ulVideoResolution;

    /** 视频刷新频率 HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32     ulVideoFrequence;
} HD_VIDEO_PORT_DVI_FMT_EX_S;

/**
* @struct tagHD_VideoPortSDIFmtEx
* @brief SDI格式信息
* @attention
*/
typedef struct tagHD_VideoPortSDIFmtEx
{

    /** 视频分辨率大小 HD_VIDEO_FORMAT_EX_E */
    ULONG_32            ulVideoResolution;

    /** 视频刷新频率 HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32            ulVideoFrequence;
} HD_VIDEO_PORT_SDI_FMT_EX_S;

/**
* @struct tagHD_VideoPortSFmt
* @brief S 格式信息
* @attention
*/
typedef struct tagHD_VideoPortSFmt
{

    /** P/N  HD_RESTRICT_TYPE_EX_E */
    ULONG_32        ulRestictType;

    /** 视频刷新频率  HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32        ulVideoFrequence;
} HD_VIDEO_PORT_S_FMT_EX_S;

/**
* @struct tagHD_VideoPortRCAFmtEx
* @brief RCA 格式信息
* @attention
*/
typedef struct tagHD_VideoPortRCAFmtEx
{

    /** P/N HD_RESTRICT_TYPE_EX_E */
    ULONG_32        ulRestictType;

    /** 视频刷新频率 HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32        ulVideoFrequence;
} HD_VIDEO_PORT_RCA_FMT_EX_S;

/**
* @union tagHD_VideoPortFmtUEx
* @brief 视频端口格式
* @attention
*/
typedef union tagHD_VideoPortFmtUEx
{

    /** DVI 格式 */
    HD_VIDEO_PORT_DVI_FMT_EX_S stVideoPortDVIFmt;

    /** SDI 格式 */
    HD_VIDEO_PORT_SDI_FMT_EX_S stVideoPortSDIFmt;

    /** S 格式 */
    HD_VIDEO_PORT_S_FMT_EX_S   stVideoPortSFmt;

    /** RCA 格式 */
    HD_VIDEO_PORT_RCA_FMT_EX_S stVideoPortRCAFmt;
} HD_VIDEO_PORT_FMT_EX_U;


/**
* @struct tagHD_VideoParamEx
* @brief 视频参数
* @attention
*/
typedef struct tagHD_VideoParamEx
{

    /** 亮度 */
    LONG_32    lBright;

    /** 对比度 */
    LONG_32    lContrast;

    /** 饱和度 */
    LONG_32    lSaturation;

    /** 色度 */
    LONG_32    lChroma;
} HD_VIDEO_PARAM_EX_S;


/**
* @struct tagHD_VideoInPortParaEx
* @brief 视频输入端口参数
* @attention
*/
typedef struct tagHD_VideoInPortParaEx
{

    /** 输入端口类型 HD_VIDEO_PORT_TYPE_EX_E */
    ULONG_32                   ulVideoPortType;

    /** 输入端口格式 */
    HD_VIDEO_PORT_FMT_EX_U  unVideoPortFmt;

    /** 输入端口AD参数 */
    HD_VIDEO_PARAM_EX_S     stVideoParam;

    /** 输入端口对应摄像机属性 */
    HD_CAMERA_CONFIG_EX_S   stCameraParam;
} HD_VIDEO_IN_PORT_PARA_EX_S;

/**
 * @struct tagHD_VideoInPortCfgEx
 * @brief 视频输入端口配置
 * @attention
 */
typedef struct tagHD_VideoInPortCfgEx
{

    /** 所有输入端口属性 */
    HD_VIDEO_IN_PORT_PARA_EX_S astVideoInPortPara[IMOS_EN_VIDEO_IN_PORT_COUNT];
} HD_VIDEO_IN_PORT_CFG_EX_S;

/**
 * @struct tagHD_VideoInPortEventEx
 * @brief 实际视频输入端口参数
 * @attention
 */
typedef struct tagHD_VideoInPortEventEx
{

    /** 特定端口是否有变化 */
    BOOL_T                     abChange[IMOS_EN_VIDEO_IN_PORT_COUNT];

    /** 0值表示特定端口输入源无法识别或无输入源 */
    ULONG_32                      aulCheckFlag[IMOS_EN_VIDEO_IN_PORT_COUNT];

    /** 实际输入端口属性 */
    HD_VIDEO_IN_PORT_PARA_EX_S astVideoInPortPara[IMOS_EN_VIDEO_IN_PORT_COUNT];
} HD_VIDEO_IN_PORT_EVENT_EX_S;


/**
* @struct tagHD_VideoOutPortParaEx
* @brief 视频输出端口参数
* @attention
*/
typedef struct tagHD_VideoOutPortParaEx
{

    /** 视频输出端口类型 HD_VIDEO_PORT_TYPE_EX_E */
    ULONG_32                   ulVideoPortType;

    /** 视频输出端口格式 */
    HD_VIDEO_PORT_FMT_EX_U  unVideoPortFmt;

    /** 视频输出AD参数 */
    HD_VIDEO_PARAM_EX_S     stVideoParam;
} HD_VIDEO_OUT_PORT_PARA_EX_S;


/**
 * @struct tagHD_VideoOutPortCfgEx
 * @brief 视频输出端口配置
 * @attention
 */
typedef struct tagHD_VideoOutPortCfgEx
{

    /** 所有输出端口属性 */
    HD_VIDEO_OUT_PORT_PARA_EX_S astVideoOutPortFmt[IMOS_EN_VIDEO_OUT_PORT_COUNT];
} HD_VIDEO_OUT_PORT_CFG_EX_S;

/**
 * @struct tagMC_MultiCastCfgEx
 * @brief 组播信息结构
 * @attention
 */
typedef struct tagMC_MultiCastCfgEx
{

    /** 是否启用组播 */
    BOOL_T          bUseMulticast;

    /** 组播 IP 地址 */
    CHAR            szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播起始端口 */
    ULONG_32           ulMulticastPort;

    /** 组播路由中继 */
    ULONG_32           ulMulticastTTL;

    /** 是否使用认证 */
    BOOL_T          bUseMCPwd;

    /** 组播认证密码 */
    CHAR            szMulticastPwd[IMOS_HD_MAX_PASSWORD_LENGTH];
} MC_MULTICAST_CFG_EX_S;

/**
* @struct tagInner_VersionEx
* @brief 版本信息
* @attention
*/
typedef struct tagInner_VersionEx
{

    /** 终端版本 */
    CHAR szTerminalSoftVer[IMOS_HD_VERSION_LEN];

    /** 软件版本编译时间 */
    CHAR szSoftVerMaketime[IMOS_HD_VERSION_LEN];

    /** 驱动软件版本 */
    CHAR szDriverVer[IMOS_HD_VERSION_LEN];

    /** 内核驱动版本 */
    CHAR szKernelVer[IMOS_HD_VERSION_LEN];

    /** UBOOT 版本 */
    CHAR szUbootVer[IMOS_HD_VERSION_LEN];

    /** FPGA 版本 */
    CHAR szFpgaVer[IMOS_HD_VERSION_LEN];

    /** CPLD 版本 */
    CHAR szCpldVer[IMOS_HD_VERSION_LEN];

    /** DSP 版本 */
    CHAR szDspVer[IMOS_HD_VERSION_LEN];

    /** JRE 版本 */
    CHAR szJREVer[IMOS_HD_VERSION_LEN];

    /** 软件各进程版本(界面暂不显示) */
    CHAR szCourseVer[IMOS_EN_HD_PROCESS_TYPE_COUNT][IMOS_HD_VERSION_LEN];
}HD_INNER_VERSION_EX_S;

/**
 * @struct tagDevice_InfoEx
 * @brief 设备信息
 * @attention
 */
typedef struct tagDevice_InfoEx
{

    /** 产品序列号 */
    CHAR szSerialNum[IMOS_HD_VERSION_LEN];

    /** 软件版本 */
    CHAR szSoftVer[IMOS_HD_VERSION_LEN];

    /** 硬件版本 */
    CHAR szHardVer[IMOS_HD_VERSION_LEN];

    /** 内部版本信息 */
    HD_INNER_VERSION_EX_S stInnerVer;
}HD_DEVICE_INFO_EX_S;

/**
 * @struct tagHD_LicenseInfoEx
 * @brief 与 license 相关的功能类型
 * 注意: LONG lLicenseInfo 其中各位分别代表:(从高到低，未标注位待扩展)
 *       ....       BIT1               BIT0
 *       ....    bSupportTMC       bSupport1080P
      *
 *       附: BIT0 = 0 表示不支持 1080P  BIT0 = 1 表示支持 1080P
 *           BIT1 = 0 表示不支持 TMC    BIT1 = 1 表示支持 TMC
 * @attention
 */
typedef struct tagHD_LicenseInfoEx
{

    /** 特定位表示特定的信息(详见上述结构定义) */
    ULONG_32 ulLicenseInfo;
} HD_LICENSE_INFO_EX_S;


/**
 * @struct tagHD_MPSwitchCfgEx
 * @brief MP 开关配置
 * @attention
 */
typedef struct tagHD_MPSwitchCfgEx
{

    /** 控制是否关闭码流平滑 */
    BOOL_T bIsCloseSmoothSend;
} HD_MP_SWITCH_CFG_EX_S;

/**
 * @struct tagHD_STKDropCallCfgEx
 * @brief STK自动挂断时间配置
 * @attention
 */
typedef struct tagHD_STKDropCallCfgEx
{

    /** 检测对端是否活跃、往返延迟超时时间，单位秒 */
    LONG_32 lRoundTripDelayTime;

    /** 发送往返延迟的间隔，单位秒 */
    LONG_32 lRoundTripIntervalTime;

    /** 发送往返延迟的次数 */
    LONG_32 lRoundTripCount;
} HD_STK_DROP_CALL_CFG_EX_S;

/**
 * @struct tagHD_ApPrearrange_CfgEx
 * @brief AP 预配置
 * @attention
 */
typedef struct tagHD_ApPrearrange_CfgEx
{

    /** 解码延时包数 */
    ULONG_32 ulDecodeTimeLapRtpNum;

    /** 编码延时包数 */
    ULONG_32 ulEncodeTimeLapRtpNum;
} HD_AP_PREARRANG_CFG_EX_S;

/**
 * @struct tagAddrbook_ItemEx
 * @brief 地址簿子项结构(单个)
 * @attention
 */
typedef struct tagAddrbook_ItemEx
{
    /** 终端IP地址 */
    CHAR                  szIPAddr[IMOS_IPADDR_LEN];

    /** 终端名称 */
    CHAR                  szName[IMOS_NAME_LEN];

    /** 终端E.164号码 */
    CHAR                  szNumber[IMOS_HD_MAX_NAME_LENGTH];

    /**  终端H.323 ID */
    CHAR                  szAlias[IMOS_HD_MAX_NAME_LENGTH];

    /** 类型 HD_PROTO_TYPE_EX_E */
    ULONG_32                 ulProtoType;

    /** 填0 */
    LONG_32                  lAddrID;

    /** 如下信息会议终端中不存在， 填空即可 */
    CHAR                  szCity[IMOS_HD_MAX_NAME_LENGTH];
    CHAR                  szProv[IMOS_HD_MAX_NAME_LENGTH];
    LONG_32                  lReservered[2];
} HD_ADDRBOOK_ITEM_EX_S;

/**
 * @struct tagBatchImportAddrAckEx
 * @brief 从iMSC上批量导入地址簿操作的结果结构.
 * @attention
 */
typedef struct tagBatchImportAddrAckEx
{
    /** 导入操作结果 OPERATE_RESULT_E */
    ULONG_32                     ulRslt;

    /** 被导入的地址簿记录 */
    HD_ADDRBOOK_ITEM_EX_S      stAddrBookItem;
} BATCH_IMPORT_ADDR_ACK_CAUSE_EX_S;

/**
* @struct tagHD_AllConfigParamEx
* @brief MG所有配置参数
* @attention
*/
typedef struct tagHD_AllConfigParamEx
{
    /** 接听设置配置参数  */
    HD_ANSWER_CONFIG_EX_S            stAnswerParam;

    /** 协议配置参数 */
    HD_PROTOCOL_ALL_EX_S             stProtocolParam;



    /** 所有网口连接设置配置参数 */
    HD_ALLCONNECT_CONFIG_EX_S        stAllConnectParam;

    /** 网口号*/
    HD_NIC_NUMBER_CFG_EX_S           stNICNumber;

    /** NIC设置配置参数 */
    HD_ALLNIC_CONFIG_EX_S            stAllNicParam;

    /** 所有NAT设置配置参数 */
    HD_ALL_NAT_CONFIG_EX_S           stAllNATParam;

    /** NTP设置配置参数 */
    HD_NTP_CONFIG_EX_S               stNTPParam;

    /** 主流设置配置参数 */
    HD_MV_CONFIG_EX_S                stMvParam;

    /** 辅流设置配置参数 */
    HD_RV_CONFIG_EX_S                stRvParam;

    /** 视频输入输出选择配置 */
    HD_VIDEO_INOUT_EX_S              stVideoIOParam;

    /** 音频配置参数 */
    HD_AUDIOALL_CONFIG_EX_S          stAudioParam;

    /** 调试级别参数 */
    HD_INNER_MODULE_DEBUG_LEVEL_EX_S stDebugParam;

    /** 日志配置参数 */
    HD_LOG_CONFIG_EX_S               stLogParam;

    /** 升级设置配置参数 */
    HD_UPDATE_CONFIG_EX_S            stUpdateParam;

    /** 会场设置配置参数 */
    HD_SITE_CONFIG_EX_S              stSiteParam;

    /** NAA配置参数 */
    HD_NAA_CONFIG_EX_S               stNAAParam;

    /** 摄像机配置参数 */
    HD_ALLCAM_CONFIG_EX_S            stCamParam;

    /** 摄像机预置位 */
    HD_ALLCAM_PRESET_POS_EX_S        stCamAllPos;


    /** QOS配置参数 */
    HD_QOS_SERVER_EX_S               stQosParam;

    /** 视频输入端口配置 */
    HD_VIDEO_IN_PORT_CFG_EX_S        stVideoInPortParam;

    /** 实际视频输入端口配置(与界面无关) */
    HD_VIDEO_IN_PORT_EVENT_EX_S      stRealVideoInPortParam;

    /** 视频输出端口配置 */
    HD_VIDEO_OUT_PORT_CFG_EX_S       stVideoOutPortParam;

    /** 组播配置参数 */
    MC_MULTICAST_CFG_EX_S            stMultiCastParam;

    /** 开机内容 */
    HD_SYS_STARTED_CFG_EX_S          stStartedParam;

    /** 设备信息 */
    HD_DEVICE_INFO_EX_S              stDevInfo;

    /** license 信息 */
    HD_LICENSE_INFO_EX_S             stLicenseInfo;

    /** MP 开关信息(与界面无关) */
    HD_MP_SWITCH_CFG_EX_S            stMPSwitchParam;

    /** 挂断信息(与界面无关) */
    HD_STK_DROP_CALL_CFG_EX_S        stHangUpParam;

    /** AP 预配置信息(与界面无关) */
    HD_AP_PREARRANG_CFG_EX_S         stAPPrearrangeParam;
}MC_ALLCONFIGPARAM_EX_S;

/**
* @struct tagHD_NetworkConfigParamEx
* @brief MG网络配置参数
* @attention
*/
typedef struct tagHD_NetworkConfigParamEx
{
    /** 所有网口连接设置配置参数 */
    HD_ALLCONNECT_CONFIG_EX_S        stAllConnectParam;

    /** 网口号*/
    HD_NIC_NUMBER_CFG_EX_S           stNICNumber;

    /** NIC设置配置参数 */
    HD_ALLNIC_CONFIG_EX_S            stAllNicParam;

    /** NAA配置参数 */
    HD_NAA_CONFIG_EX_S               stNAAParam;

    /** 所有NAT设置配置参数 */
    HD_ALL_NAT_CONFIG_EX_S           stAllNATParam;

    /** NTP设置配置参数 */
    HD_NTP_CONFIG_EX_S               stNTPParam;

    /** QOS配置参数 */
    HD_QOS_SERVER_EX_S               stQosParam;

    /** 组播配置参数 */
    MC_MULTICAST_CFG_EX_S            stMultiCastParam;
} MC_NETWORKCONFIGPARAM_EX_S;

/**
* @struct tagHD_VideoConfigParamEx
* @brief MG视频配置参数
* @attention
*/
typedef struct tagHD_VideoConfigParamEx
{
    /** 主流设置配置参数 */
    HD_MV_CONFIG_EX_S                stMvParam;

    /** 辅流设置配置参数 */
    HD_RV_CONFIG_EX_S                stRvParam;

    /** 视频输入输出选择配置 */
    HD_VIDEO_INOUT_EX_S              stVideoIOParam;

    /** 摄像机配置参数 */
    HD_ALLCAM_CONFIG_EX_S            stCamParam;

    /** 摄像机预置位 */
    HD_ALLCAM_PRESET_POS_EX_S        stCamAllPos;

    /** 视频输入端口配置 */
    HD_VIDEO_IN_PORT_CFG_EX_S        stVideoInPortParam;

    /** 实际视频输入端口配置(与界面无关) */
    HD_VIDEO_IN_PORT_EVENT_EX_S      stRealVideoInPortParam;

    /** 视频输出端口配置 */
    HD_VIDEO_OUT_PORT_CFG_EX_S       stVideoOutPortParam;

} MC_VIDEOCONFIGPARAM_EX_S;

#if 0
#endif

/*************************************************************************************
SS 最小MIB
***************************************************************************************/

/**
 * @struct tagDevicePerformanceInfo
 * @brief 设备性能数据
 * @attention
 */
typedef struct tagDevicePerformanceInfo
{
    /** 自设备开机之后， 设备总的运行时间 */
    ULONG_32                 ulSysUpTime;

    /** CPU利用率 */
    ULONG_32                 ulCpuUsage;

    /** 内存利用率  */
    ULONG_32                 ulMemUsage;

    /** 内存大小  */
    ULONG_32                 ulMemSize;

    /** 设备温度  */
    LONG_32                  lTemperature;
} DEVICE_PERFORMANCE_INFO_S;

/**
 * @struct tagPort_InfoEx
 * @brief 端口信息
 * @attention
 */
typedef struct tagPort_Info
{
    /** 接口索引， 为大于0的整数 */
    LONG_32                  lIfIndex;

    /** 接口类型， 一般为6. ethernetCsmacd(6), -- for all ethernet-like interfaces, regardless of speed, as per RFC3635 */
    LONG_32                  lIfType;

    /** 接口描述 */
    CHAR                  szIfDescr[IMOS_DESC_LEN];

    /** 接口能够接收/发送的最大的包 */
    LONG_32                  lIfMtu;

    /** IfAdminStatus和ifOperStatus反映了设备接口的状态，用于网管显示设备状态 */

    /** 接口的管理状态， 取值范围:
       1: up(1)
       2: down(2)
       3: testing(3)
    */
    LONG_32                  lIfAdminStatus;

    /** 接口的操作状态， 取值范围:
        1: up(1)
        2: down(2)
        3: testing(3)
        4: unknown(4)
        5: dormant(5)
        6: notPresent(6)
        7: lowerLayerDown(7)
    */
    LONG_32                  lIfOperStatus;

    /** 物理地址 */
    CHAR                  szIfPhysAddress[IMOS_IPADDR_LEN];

    /** 端口速率 */
    ULONG_32                 ulIfSpeed;

} PORT_INFO_S;

/**
 * @struct tagDevicePortInfo
 * @brief 设备端口信息
 * @attention
 */
typedef struct tagDevicePortInfo
{
    /** 端口个数 */
    ULONG_32                        ulPortNum;

    /** 端口信息 */
    PORT_INFO_S               astPortInfo[IMOS_HD_MAX_PRIVATE_NET_COUNT];
} DEVICE_PORT_INFO_S;

/*************************************************************************************
SS 邮件发送相关的配置
***************************************************************************************/
/**
 * @struct tagEmailSendingRules
 * @brief 邮件发送规则:
 * 邮件发送存在两种调度：
 * 1、创建会议和修改会议成功时， 通知一次；
 * 2、开会之前一小时 通知3次（第1次：开会前1小时、第2次：前半小时、第3次：前十分钟）。
 * @attention
 */
typedef struct tagEmailSendingRules
{
    /** 创建会议和修改会议成功时， 通知一次。 BOOL_TRUE，通知， 否则不通知 */
    BOOL_T  bSendMailOnceConfCreated;

    /** 是否发出通知， BOOL_TRUE，通知， 否则不通知  */
    BOOL_T  abNotify[IMOS_EMAIL_NOTIFICATION_NUMBER];

    /** 会前提前通知时间， 单位为分钟 */
    ULONG_32   aulNotifyTime[IMOS_EMAIL_NOTIFICATION_NUMBER];
} EMAIL_SENDING_RULES_S;


/*************************************************************************************
SS 双链路备份特性
***************************************************************************************/




/**
 * @struct tagModifyTermRepEx
 * @brief MCU上报终端修改的信息
 * @attention
 */
typedef struct tagModifyTermRepEx
{
    /** 终端编码 */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** 终端名称 */
    CHAR  szTermName[IMOS_NAME_LEN];

    /** 双链路信息 */
    MC_LINK_INFO_EX_S      stLinkInfo;

    /** 告警信息 */
    MC_TERM_ALARM_INFO_EX_S stAlarmInfo;

} MODIFY_TERM_REP_EX_S;

/**
 * @struct tagMCSetPicModeMsgEx
 * @brief 画面模式
 * @attention
*/
typedef struct tagMCSetPicModeMsgEx
{
    /** 主场选择观看模式 MC_CHAIR_BROWSE_MODE_EX_E */
    ULONG_32                              ulChairBrowseMode;

    /** 广播模式 MC_BROADCAST_MODE_EX_E */
    ULONG_32                              ulBroadcastMode;

    /** 单分屏详细信息结构 */
    MC_MULTI_PIC_SITE_SHOW_MODE_EX_S   stSinglePicInfo;

    /** 多画面模式、会场位置等结构*/
    MC_MULTI_PIC_INFO_EX_S             stMultiPicModePos;
} MC_SET_PIC_MODE_MSG_EX_S;


/**
 * @struct tagMC_ConfigRouteMsgEx
 * @brief 添加、修改、删除MCU单条路由消息。只在修改的时候填写旧的路由
 * @attention
*/
typedef struct tagMC_ConfigRouteMsgEx
{
    /** 网口编号 */
    ULONG_32                      ulLanID;

    /** 路由修改类型 MC_CONFIG_ROUTE_TYPE_EX_E*/
    ULONG_32                      ulConfigRouteType;

    /** 旧的路由 */
    MC_MCU_ROUTE_EX_S          stOldRoute;

    /** 新的路由 */
    MC_MCU_ROUTE_EX_S          stNewRoute;
} MC_CONFIG_ROUTE_MSG_EX_S;


/**
 * @struct tagMC_ConfCtrlInfoEx
 * @brief 配置是否自动打开麦克风的数据结构
 * @attention
*/
typedef struct tagMC_ConfCtrlInfoEx
{
    /** 主场选择观看会场是否自动开麦克风 */
    BOOL_T                     bIsChairWatchedMicAutoOpen;

    /** 被广播会场是否自动开麦克风 */
    BOOL_T                     bIsBroadcastedMicAutoOpen;
} MC_CONF_CTRL_INFO_EX_S;


/**
 * @struct tagBackupMCUReport
 * @brief  备份MCU信息
 * @attention
 */
typedef struct tagBackupMCUReport
{
    /** MCU编码 */
    CHAR szMCUCode[IMOS_RES_CODE_LEN];

    /** MCU名称 */
    CHAR szMCUName[IMOS_NAME_LEN];

    /** MCU设备地址 */
    CHAR szMCUAddr[IMOS_IPADDR_LEN];

    /**被备份MCU设备地址 */
    CHAR szBackupMCUAddr[IMOS_IPADDR_LEN];
} BACKUP_MCU_REPORT_S;


/**
 * @struct tagConfSendRoleSiteChange
 * @brief  会议当前辅流发送的会场的变化
 * @attention
 */
typedef struct tagConfSendRoleSiteChange
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 会场编码 */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** 会场名称 */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** 辅流发送/停止发送标记, (TRUE)--开始发送， (FALSE)--停止发送 */
    BOOL_T   bSendRole;
} CONF_SEND_ROLE_SITE_CHANGE_S;


/**
 * @struct tagConfAutoMultPicChange
 * @brief  多画面自动切换值改变
 * @attention
 */
typedef struct tagConfAutoMultPicChange
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 自动切换的状态值 */
    BOOL_T   bAutoMultiPic;
} CONF_AUTOMULTIPIC_CHANGE_S;


/**
 * @struct tagConfSetTurnBroadcaseChange
 * @brief  画面轮询模式改变
 * @attention
 */
typedef struct tagConfSetTurnBroadcaseChange
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /**  轮巡模式   MC_CONF_TURN_BROADCAST_MODE_EX_E*/
    ULONG_32    ulTurnMode;

    /** BOOL_TRUE, 进行轮询, 否则不轮询 */
    BOOL_T    bCycle;
} CONF_SET_TURN_BROADCAST_CHANGE_S;

/**
 * @struct tagConfSetPicModeChange
 * @brief  设置画面模式上报
 * @attention
 */
typedef struct tagConfSetPicModeChange
{
    /** 会议ID */
    IMOS_ID  idConfId;
} CONF_SET_PIC_MODE_CHANGE_S;

/**
* @struct tagMcuSyncStatusChange
* @brief  MCU同步状态改变上报
* @attention
*/
typedef struct tagMcuSyncStatusChange
{
    /** MCU编码 */
    CHAR szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** 同步状态(MCU_SYNCHRON_STATUS_E) */
    ULONG_32 ulMcuSyncStatus;

    /** 同步操作错误码(同步开始永远填0；同步结束成功填0，失败填相应错误码) */
    ULONG_32 ulSyncRet;

    /** 用户登陆编码，是用户登陆后服务器分配的，唯一标识。 */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

} MCU_SYNC_STATUS_CHANGE_S;

/**
 * @struct tagConfFECCChange
 * @brief  会议当前FECC控制者或被控者发生变化
 * @attention
 */
typedef struct tagConfFECCChange
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 控制者会场编码 */
    CHAR     szControllerCode[IMOS_RES_CODE_LEN];

    /** 控制者会场名称 */
    CHAR     szControllerName[IMOS_NAME_LEN];

    /** 被控者会场编码 */
    CHAR     szControlledCode[IMOS_RES_CODE_LEN];

    /** 被控者会场名称 */
    CHAR     szControlledName[IMOS_NAME_LEN];

} CONF_FECC_CHANGE_S;

/**
* @struct tagConfMcuBackupChange
* @brief  会议MCU备份信息
* @attention
*/
typedef struct tagConfMcuBackupChange
{
    /** 会议ID */
    IMOS_ID  idConfId;

    /** 备份MCU编码 */
    CHAR szMCUCode[IMOS_RES_CODE_LEN];

    /** 备份MCU名称 */
    CHAR szMCUName[IMOS_NAME_LEN];

    /** 故障MCU编码 */
    CHAR szBackupMCUCode[IMOS_RES_CODE_LEN];

} CONF_MCU_BACKUP_CHANGE_S;

#pragma pack()

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

