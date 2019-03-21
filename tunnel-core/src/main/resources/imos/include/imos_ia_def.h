
#ifndef _IMOS_IA_DEF_H_
#define _IMOS_IA_DEF_H_

/* 函数标准调用约定 */
#ifndef STDCALL
#ifdef WIN32
#define STDCALL         __stdcall
#else
#ifdef i386
#define STDCALL         __attribute__((stdcall))
#else
#define STDCALL
#endif
#endif
#endif

#define INOUT
#define IN
#define OUT

/*
* 注意，结构体定义的字符串不能包含以下字符 \/:*?"<>|
*/


#define MSG_BUFFER_SIZE     (2 * 1024 * 1024)     /* @brief 消息体的大小 */
#define JPG_MAX_BUF         (10 * 1024 * 1024)     /* @brief jpg图片大小 */
#define TCP_MSG_FALG        '$'                   /* @brief tcp媒体流的第一个字节值定义 */
#define TCP_MSG_CHANNELID   0                     /* @brief tcp媒体流的第二个字节值定义 */
#define TCP_LEN_OFFSET      2                     /* @brief tcp包媒体数据包长度偏移地址 */
#define TCP_HEADER_LEN      6                     /* @brief tcp包媒体数据包中媒体数据偏移地址 */

#define IA_FILE_PATH_LEN              512         /* @brief  IA文件路径长度 */
#define IA_ITEM_NAME_LEN              148         /* @brief  配置项名称长度 */
#define IA_IP_LEN                     32          /* @brief  IP地址长度 */
#define IA_PASSWD_LEN                 256         /* @brief  用户密码长度(MD5加密字符串) */

#define MAX_PLAN_TIME_SCALE           4           /* @brief  计划时间段信息 */
#define MAX_RULE_NUM                  3           /* @brief  一个智能配置所含有的最大规则数 */
#define RULE_CFG_LEN                  (10 * 1024) /* @brief  一个智能processer的配置规则长度 */

#define IA_NETWORK_NUM                4
#define DEL_DSIK_FREEPERCENTAGE       0.1
#define SOCKET_ADDRESS_LEN            40          /* @brief  Socket地址信息长度 */

#define SEND_TYPE_MIN_INTERVAL (1*1000)

#define UPLOAD_POSTFXI  "!"

#define DAY_COUNT_OF_WEEK             7           /* @brief  一周的天数 */

/**
 * @struct IA_VOD_STREAM_SPEED_E
 * @brief 回放分析媒体流速度
 * @attention
 */
typedef enum tagVodStreamSpeed
{
    IA_ONE_FOUR_SPEED   = 0,                        /* @brief 1/4倍数 */
    IA_ONE_TWO_SPEED    = 1,                        /* @brief 1/2倍数 */
    IA_ONE_SPEED        = 2,                        /* @brief 1倍数 */
    IA_TWO_SPEED        = 3,                        /* @brief 2倍数 */
    IA_FOUR_SPEED       = 4,                        /* @brief 4倍数 */
    IA_SIXTEEN_SPEED    = 6,                        /* @brief 16倍数 */
    IA_SUPER_FAST_SPEED = 10                        /* @brief 超高倍数，用于久凌回放下载 */
}IA_VOD_STREAM_SPEED_E;

/**
 * 支持的智能处理器类型
 */
typedef enum tagIaRuleType
{
    IA_RULE_YS_TW = 0,                               /* @brief 宇视_伴线(TripWire) */

    IA_RULE_YS_OC = 3,                                /* @brief 宇视_OSD与图像拼接(OSD Combine) */
    IA_RULE_YS_FACE = 4,
    IA_RULE_YS_BL  = 5,                   /* @brief 宇视_BL枪球联动(Ball Linkage) */
    IA_RULE_YS_VB = 6,                              /* @brief 宇视_车标识别*/
    IA_RULE_YS_TELPHONE = 7,                         /* @brief 宇视_开车打电话*/
    IA_RULE_YS_PLANE    = 8,                        /*@brief 宇视_机号识别*/
    IA_RULE_YS_VD        = 9,                       /* @brief 宇视_视频诊断 */
    IA_RULE_YS_VP  = 10,                             /* @brief 宇视_车牌识别*/
    IA_RULE_YS_ILLGEAL_PARK = 11,                    /* @brief 宇视_违章停车 */
    IA_RULE_YS_9LIN = 15,                            /*@brief 久凌_视频摘要*/
/* BEGIN: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */	
    IA_RULE_YS_PRISONDETECT = 20,                    /* @brief 监所智能*/
/* END: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */
    IA_RULE_YS_CARTYPE = 21
}IA_RULE_TYPE_E;

/**
 * 智能分析结果分发对象
 */
typedef enum tagIaSenderType
{
    IA_SENDER_TMS = 1,                          /* @brief 发送给TMS，当前只支持宇视卡口协议(无效) */
    IA_SENDER_IAS_DB = 2,                       /* @brief 将分析数据保存在ias DB上 */
    IA_SENDER_LOCAL_VIDEO_STORAGE = 4,          /* @brief 将分析视频信息保存到ias服务器(无效) */
    IA_SENDER_CENTER_VIDEO_STORAGE = 8,         /* @brief 将分析视频信息保存到中心存储服务器 */
    IA_SENDER_LOCAL_PIC_STORAGE = 16,           /* @brief 将分析图片数据保存到本地服务器(无效) */
    IA_SENDER_CENTER_PIC_STORAGE = 32,          /* @brief 将分析图片数据保存到ias服务器(无效) */
    IA_SENDER_ALARM_VM = 64,                    /* @brief 将智能分析结果作为告警上报给VM服务器(无效) */
    IA_SENDER_UI_PICTURE = 128,                 /* @brief 发送图片到指定客户端 (无效)*/
    IA_SENDER_BL_COMMAND = 256,                /* @brief 联动到球机Sender*/
    IA_SENDER_VB = 512 ,                         /* @brief 车标处理*/
    IA_SENDER_TEL = 1024,                        /* @brief 开车打电话处理*/
    IA_SENDER_FILE_UPDATE = 2048,                 /* @brief 保存缓存文件*/
    IA_SENDER_VD = 4096,                         /* @brief 视频诊断 */
    IA_SENDER_PLLPR = 8192  ,              /*机号识别*/
    IA_SENDER_VP    = 16384 ,               /*车牌识别*/
    IA_SENDER_TELFILE4WH = 32768,            /*武汉交管局的图片保存需求*/
	IA_SENDER_HUAYI = 65536,            		/*华亿实况*/
/* BEGIN: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */	
    IA_SENDER_PRISONDETECT = 0x20000,          /* @brief监所智能*/ 
/* END: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */	
    IA_SENDER_CAR_TYPE = 0x40000    /*@brief 车型检测*/
}IA_SENDER_TYPE_E;

/**
 * 智能任务运行模式
 */
typedef enum tagIaRunMode
{
    IA_RUN_MODE_FREE = 0,
    IA_RUN_MODE_REAL = 1,               /* @brief 实时运行模式 */
    IA_RUN_MODE_VOD  = 2,                /* @brief 回放运行模式 */
    IA_RUN_MODE_DOWN = 3,               /* @brief 下载运行模式 不支持*/
    IA_RUN_MODE_FILE = 4,               /* @brief 本地文件运行模式 */
    IA_RUN_MODE_FORMAT = 5 ,
    IA_RUN_MODE_BALLLINKAGE = 6,         /* @brief 枪球联动 */
    IA_RUN_MODE_HTTP_IMAGE= 7,          /*@brief http获取图片模式*/
    IA_RUN_MODE_DB = 8,                  /* @brief Db模式 */
    IA_RUN_MODE_VD = 9,                   /* @brief视频诊断模式 */
    IA_RUN_MODE_HTTP_TEL = 10  ,            /* @brief过车打电话模式 */
    IA_RUN_MODE_ILLEGAL_PARK = 11,       /* @brief违章停车模式 */
    IA_RUN_MODE_9lin_FILE = 14,         /*@brief 9lin 本地文件*/
    IA_RUN_MODE_9lin_VOD = 15,          /*@brief 9lin 回放*/
    IA_RUN_MODE_HUAYI_REAL = 16,         /*@brief 华亿实况*/
/* BEGIN: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */	
    IA_RUN_MODE_PRISON_DETECT = 20,       /* @brief 监所智能*/
/* END: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */	
    IA_RUN_MODE_CAR_TYPE = 21           /* @brief 车型检测*/
}IA_RUN_MODE_E;

/**
 * 智能任务运行状态
 */
typedef enum tagIaRunStatus
{
    IA_RUN_STATUS_STOP,             /* @brief 停止状态 */
    IA_RUN_STATUS_STOPPING,         /* @brief 停止过程中 */
    IA_RUN_STATUS_RUN,              /* @brief 运行中 */
    IA_RUN_STATUS_COMPLETE,         /* @brief 智能分析完成 */
    IA_RUN_STATUS_UPLOAD_EXCEPTION, /* @brief 上传异常 */
    IA_RUN_STATUS_SOURCE_EXCEPTION,    /* @brief 回放/实况异常 */
    IA_RUN_STATUS_UPLOAD,            /* @brief 文件上传中 */

    /* Begin: Added by kangshunli 2013/6/14 视频诊断任务状态 */
    IA_RUN_STATUS_ANALYZED,          /* @brief 已分析 */
    IA_RUN_STATUS_UNANALYZED,          /* @brief 等待分析 */
    IA_RUN_STATUS_DEL,                 /* @brief 进行任务删除 */
    /* End: Added by kangshunli 2013/6/14 视频诊断任务状态 */
	IA_RUN_STATUS_PAUSE                /* 处于暂停状态 */
}IA_RUN_STATUS_E;

/**
 * 星期枚举定义(用于判断一周的某天是否配置了计划)
 */
typedef enum tagIaWeekDay
{
    IA_WEEK_SUNDAY = 0,             /* @brief 星期天 */
    IA_WEEK_MONDAY  = 1,            /* @brief 星期一 */
    IA_WEEK_TUESDAY = 2,            /* @brief 星期二 */
    IA_WEEK_WEDNESDAY = 4,          /* @brief 星期三 */
    IA_WEEK_THURSDAY = 8,           /* @brief 星期四 */
    IA_WEEK_FRIDAY = 16,            /* @brief 星期五 */
    IA_WEEK_SATURDAY = 32           /* @brief 星期六 */
}IA_WEEK_DAY_E;

/**
 * 星期枚举定义(用于关联天计划)
 */
typedef enum tagWeekDay
{
    WEEK_SUNDAY = 0,             /* @brief 星期天 */
    WEEK_MONDAY  = 1,            /* @brief 星期一 */
    WEEK_TUESDAY = 2,            /* @brief 星期二 */
    WEEK_WEDNESDAY = 3,          /* @brief 星期三 */
    WEEK_THURSDAY = 4,           /* @brief 星期四 */
    WEEK_FRIDAY = 5,            /* @brief 星期五 */
    WEEK_SATURDAY = 6           /* @brief 星期六 */
}WEEK_DAY_E;

/**
 * 消息类型定义
 */
typedef enum tagIaMsgTypeCode
{
    IA_MSG_KEEPALIVE_TIMEOUT = 0,    /* @brief 用户保活超时 */
    IA_MSG_START_TASK,               /* @brief 启动一个智能分析任务 */
    IA_MSG_STOP_TASK,                /* @brief 关闭一个智能分析任务 */
    IA_MSG_INTELLINGET_COMPLETE,     /* @brief 智能分析任务完成 */
    IA_MSG_INTELLIGENT_STOP,         /* @brief 智能分析任务被停止 */
    IA_MSG_URL_PICTURE,              /* @brief 手动获取url图片 */
    IA_MSG_REAL_PICTURE,             /* @brief 服务器端实时图片推送 */
    IA_MSG_REAL_INFO,                /* @brief 服务器端实时消息 */

    /* Ias内部使用 */
    IA_MSG_VM_OFFLINE = 100,                /* @brief VM服务器下线 */
    IA_MSG_VM_VOD_END = 101,                /* @brief 回放任务分析完成 */
    IA_MSG_VM_VOD_EXCEPTION = 102,          /* @brief 回放分析过程中产生异常 */

    IA_MSG_VM_DOWN_END = 150,               /* @brief 录像下载合并结束 */
    IA_MSG_VM_DOWN_EXCEPTION = 151,         /* @brief 录像下载合并过程中出现异常 */

    IA_MSG_COMBINE_START = 200,             /* @brief 启动录像合并 */
    IA_MSG_COMBINE_EXCEPTION = 201,         /* @brief 录像合并异常 */
    IA_MSG_COMBINE_END = 202,               /* @brief 录像合并结束 */

    IA_MSG_TSLOCAL_FILE_EXCEPTION = 250,    /* @brief 文件分析过程中产生异常 */
    IA_MSG_TSLOCAL_FILE_END = 251 ,         /* @brief 文件任务分析完成 */

    IA_MSG_FORMATLOCAL_FILE_EXCEPTION = 300,/* @brief 文件转换任务分析完成 */
    IA_MSG_FORMATLOCAL_FILE_END = 301,      /* @brief 文件转换分析过程中产生异常 */

    IA_MSG_SVR_SETUP = 350,
    IA_MSG_REAL_EXCEPTION = 351,            /* @brief 周界异常 */
    IA_MSG_REAL_EXCEPTION_RECOVER = 352,    /* @brief 周界异常恢复 */
    IA_MSG_HTTP_GET_END = 400,       /* @brief http获取完成 */
    IA_MSG_HTTP_GET_EXCEPTION = 401,  /* @brief http获取失败 */
    IA_MSG_TW_INFO       = 500,            /* @brief 绊线告警消息触发 */

    IA_MSG_9LIN_END = 550,                   /*@brief 久凌分析结束*/
    IA_MSG_9LIN_EXCEPTION = 551            /* @brief 久凌分析过程中产生异常 */
}IA_MSG_TYPE_CODE_E;

/**
 * IA产生高级时的信息
 */
typedef struct tagIaAlarmInfo
{
    char szCameraID[IA_ITEM_NAME_LEN];            /* @brief * 相机ID */
    char szIntelligentName[IA_ITEM_NAME_LEN];     /* @brief * 相机智能任务名 */
    char szAlarmTime[IA_ITEM_NAME_LEN];           /* %Y-%m-%d %H:%M:%S */
}IA_ALARM_INFO_S;

/**
 * IAS管理相机状态信息
 */
typedef struct tagIaCameraInfo
{
    char szCameraID[IA_ITEM_NAME_LEN];            /* @brief * 相机ID */
    char szCameraType[IA_ITEM_NAME_LEN];          /* @brief * 相机类型 */
    char szCameraIP[IA_IP_LEN];                   /* @brief * 相机IP地址 */
    char szRoadName[IA_ITEM_NAME_LEN];            /* @brief * 路口名称 */
    char szRoadDirection[IA_ITEM_NAME_LEN];       /* @brief * 路口方向 */
}IA_CAMERA_INFO_S;

/* @brief 时间段信息结构体 */
typedef struct tagIaTimeScale
{
    char szBeginTime[IA_ITEM_NAME_LEN];/*"%Y-%m-%d %H:%M:%S"*/
    char szEndTime[IA_ITEM_NAME_LEN]  ;/*"%Y-%m-%d %H:%M:%S"*/
}IA_TIME_SCALE_S;

/**
 * @struct tagIaVodIntelligentTaskInfo
 * @brief vod智能分析业务的参数信息
 * @attention
 */
typedef struct tagIaVodIntelligentTaskInfo
{
    IA_TIME_SCALE_S       stTimeScale;           /* @brief  需要分析的视频源时间跨度 */
    long                  lTaskSliceNum;         /* @brief  任务切片数。对于一个长时间录像，可进行切片分析 */
    IA_VOD_STREAM_SPEED_E eSpeed;                /* @brief  任务速度，影响该任务下的所有子任务 */
    long                  lFrontEventSec;        /* @brief  事前时间(秒) */
    long                  lAfterEventSec;        /* @brief  事后时间(秒) */
}IA_VOD_INTELLIGENT_TASK_INFO_S;

/**
 * BM用户名密码信息
 */
typedef struct tagBmUserInfo
{
    char                    szUserName[IA_ITEM_NAME_LEN];   /* @brief  用户名 */
    char                    szPasswd[IA_ITEM_NAME_LEN];     /* @brief  密码 */
}BM_USER_INFO_S;

/**
 * 智能基本信息
 */
typedef struct tagIaIntelligentInfo
{
    char                    szCameraID[IA_ITEM_NAME_LEN];
    char                    szIntelligentID[IA_ITEM_NAME_LEN];     /* @brief  智能任务名称 */
    char                    szIntelligentName[IA_ITEM_NAME_LEN];
    unsigned long           ulIntelligentHandle;                   /* @brief  智能分析句柄 */
    IA_RUN_STATUS_E         enRunStatus;                           /* @brief  设置的智能分析任务是否在运行 */
    IA_RUN_MODE_E           enRunMode;                             /* @brief  是否为实时分析模式 */
    IA_VOD_INTELLIGENT_TASK_INFO_S  stVodIntelligentTaskInfo;      /* @brief  回放相关开展配置信息 */
    CHAR                    szExtra[IA_ITEM_NAME_LEN];             /* @brief  保留字节 */
}IA_INTELLIGENT_INFO_S;

/**
 * @brief rule配置规则，一个rule对应一个processer
 * @brief vod智能分析业务的参数信息
 * @attention
 */
typedef struct tagIaRuleConfig
{
    IA_RULE_TYPE_E  enRuleType;                         /* @brief  配置规则类型 */
    char            szRuleName[IA_ITEM_NAME_LEN];       /* @brief  规则名称，客户端用户可以自定义 */
    char            szLastRuleName[IA_ITEM_NAME_LEN];   /* @brief  前一配置规则名称 */
    unsigned long   ulItemsruleSize;                    /* @brief  配置规则信息大小 */
    unsigned char   szItemsrule[RULE_CFG_LEN];          /* @brief  配置规则内容 */
}IA_RULE_CONFIG_S;

/**
 * @brief 创建一个智能业务规则，含有多个rule单元
 * @brief vod智能分析业务的参数信息
 * @attention
 */
typedef struct tagIaIntelligentConfig
{
    unsigned long      ulRuleNum;                      /* @brief  该配置包含的规则数 */
    IA_RULE_CONFIG_S   szstRuleItem[MAX_RULE_NUM];     /* @brief  配置规则结构体数组 */
}IA_INTELLIGENT_CONFIG_S;

/**
 * @struct tagDayPlanDetail
 * @brief  周计划信息结构单元（天计划详情）
 * @attention
 */
typedef struct tagDayPlanDetail
{
	char szBeginTime1[IA_ITEM_NAME_LEN];/*"%Y-%m-%d %H:%M:%S"*/
	char szEndTime1[IA_ITEM_NAME_LEN];  /*"%Y-%m-%d %H:%M:%S"*/

	char szBeginTime2[IA_ITEM_NAME_LEN];/*"%Y-%m-%d %H:%M:%S"*/
	char szEndTime2[IA_ITEM_NAME_LEN];  /*"%Y-%m-%d %H:%M:%S"*/

	char szBeginTime3[IA_ITEM_NAME_LEN];/*"%Y-%m-%d %H:%M:%S"*/
	char szEndTime3[IA_ITEM_NAME_LEN];  /*"%Y-%m-%d %H:%M:%S"*/

	char szBeginTime4[IA_ITEM_NAME_LEN];/*"%Y-%m-%d %H:%M:%S"*/
	char szEndTime4[IA_ITEM_NAME_LEN];  /*"%Y-%m-%d %H:%M:%S"*/
} DAY_PLAN_DETAIL_S;

/**
 * @struct tagIaTaskPlanInfo
 * @brief 设置任务的计划
 * @attention
 */
typedef struct tagIaTaskPlanInfo
{
    long             lTrigTime;                                      /* @brief  触发时间间隔,每个周期只执行一次的，间隔时间为0，单位秒 */
    long             lWeekDay;                                       /* @brief  参考IA_WEEK_DAY_E */
    IA_TIME_SCALE_S  szWithinPlanTimeScale;                          /* @brief  计划内时间段（用于按天任务）*/
    IA_TIME_SCALE_S  szBeyondPlanTimeScale[MAX_PLAN_TIME_SCALE];     /* @brief  例外时间段 */
	DAY_PLAN_DETAIL_S szWeekPlanInfo[DAY_COUNT_OF_WEEK];             /* @brief  周计划信息 */
}IA_TASK_PLAN_INFO_S;

/**
 * @struct tagIaMsgHeaderInfo
 * @brief  tcp传输时消息头解析
 * @attention
 */
typedef struct tagIaMsgHeaderInfo
{
    unsigned long            ulIntelligentHandle;                    /* @brief  智能分析句柄 */
    IA_MSG_TYPE_CODE_E       enMsgTypeCode;                          /* @brief  消息类型 */
    unsigned long            ulMsgLen;                               /* @brief  消息长度 */
    unsigned char            szMsgExInfo[IA_ITEM_NAME_LEN];          /* @brief  扩展消息信息,该字段可以作为url信息使用 */
}IA_MSG_HEADER_INFO_S;

/**
* @struct tagIaSystemInfo
* @brief  ia系统信息
* @attention
*/
typedef struct tagIaSystemInfo
{
    long lCpu;                      /* @brief  cpu使用率[0-100] */
    long lMemory;                   /* @brief  内存使用率[0-100] */
    long lDisk;                     /* @brief  硬盘使用率[0-100] */
    long lNetWork[IA_NETWORK_NUM];  /* @brief  网络1使用率[0-100] */
    long lUser[IA_NETWORK_NUM];     /* @brief  保留信息 */
}IA_SYSTEM_INFO_S;

/**
* 消息上报回调接口类型定义
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] ulIntelligentHandle   智能分析句柄
* @param [IN] iMsgCode              消息类型,当前支持图片类型的数据上报
* @param [IN] szMsgBuf              消息地址
* @param [IN] ulMsgLen              消息长度
* @param [IN] pUsrData              用户自定义数据
* @return 客户端消息上报函数原型定义
*/
typedef void (STDCALL * ClientMsgCallBack)(IN long lUserHandle,
                                           IN unsigned long ulIntelligentHandle,
                                           IN long lMsgCode,
                                           IN char* szMsgBuf,
                                           IN unsigned long ulMsgLen,
                                           IN char* szPictureBuf,
                                           IN unsigned long ulPictureSize,
                                           IN void* pUsrData);

/**
* 消息上报回调接口类型定义
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] ulIntelligentHandle   智能分析句柄
* @param [IN] iMsgCode              消息类型,当前支持图片类型的数据上报
* @param [IN] szMsgBuf              消息地址
* @param [IN] ulMsgLen              消息长度
* @param [IN] pUsrData              用户自定义数据
* @return 客户端消息上报函数原型定义
*/
typedef void (STDCALL * MsgCallBack)(IN long lUserHandle,
                                     IN unsigned long ulIntelligentHandle,
                                     IN long lMsgCode,
                                     IN char* szMsgBuf,
                                     IN unsigned long ulMsgLen,
                                     IN void* pUsrData,
                                     IN ULONG ulUser1);

#endif
