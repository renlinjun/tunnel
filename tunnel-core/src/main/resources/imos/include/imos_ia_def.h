
#ifndef _IMOS_IA_DEF_H_
#define _IMOS_IA_DEF_H_

/* ������׼����Լ�� */
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
* ע�⣬�ṹ�嶨����ַ������ܰ��������ַ� \/:*?"<>|
*/


#define MSG_BUFFER_SIZE     (2 * 1024 * 1024)     /* @brief ��Ϣ��Ĵ�С */
#define JPG_MAX_BUF         (10 * 1024 * 1024)     /* @brief jpgͼƬ��С */
#define TCP_MSG_FALG        '$'                   /* @brief tcpý�����ĵ�һ���ֽ�ֵ���� */
#define TCP_MSG_CHANNELID   0                     /* @brief tcpý�����ĵڶ����ֽ�ֵ���� */
#define TCP_LEN_OFFSET      2                     /* @brief tcp��ý�����ݰ�����ƫ�Ƶ�ַ */
#define TCP_HEADER_LEN      6                     /* @brief tcp��ý�����ݰ���ý������ƫ�Ƶ�ַ */

#define IA_FILE_PATH_LEN              512         /* @brief  IA�ļ�·������ */
#define IA_ITEM_NAME_LEN              148         /* @brief  ���������Ƴ��� */
#define IA_IP_LEN                     32          /* @brief  IP��ַ���� */
#define IA_PASSWD_LEN                 256         /* @brief  �û����볤��(MD5�����ַ���) */

#define MAX_PLAN_TIME_SCALE           4           /* @brief  �ƻ�ʱ�����Ϣ */
#define MAX_RULE_NUM                  3           /* @brief  һ���������������е��������� */
#define RULE_CFG_LEN                  (10 * 1024) /* @brief  һ������processer�����ù��򳤶� */

#define IA_NETWORK_NUM                4
#define DEL_DSIK_FREEPERCENTAGE       0.1
#define SOCKET_ADDRESS_LEN            40          /* @brief  Socket��ַ��Ϣ���� */

#define SEND_TYPE_MIN_INTERVAL (1*1000)

#define UPLOAD_POSTFXI  "!"

#define DAY_COUNT_OF_WEEK             7           /* @brief  һ�ܵ����� */

/**
 * @struct IA_VOD_STREAM_SPEED_E
 * @brief �طŷ���ý�����ٶ�
 * @attention
 */
typedef enum tagVodStreamSpeed
{
    IA_ONE_FOUR_SPEED   = 0,                        /* @brief 1/4���� */
    IA_ONE_TWO_SPEED    = 1,                        /* @brief 1/2���� */
    IA_ONE_SPEED        = 2,                        /* @brief 1���� */
    IA_TWO_SPEED        = 3,                        /* @brief 2���� */
    IA_FOUR_SPEED       = 4,                        /* @brief 4���� */
    IA_SIXTEEN_SPEED    = 6,                        /* @brief 16���� */
    IA_SUPER_FAST_SPEED = 10                        /* @brief ���߱��������ھ���ط����� */
}IA_VOD_STREAM_SPEED_E;

/**
 * ֧�ֵ����ܴ���������
 */
typedef enum tagIaRuleType
{
    IA_RULE_YS_TW = 0,                               /* @brief ����_����(TripWire) */

    IA_RULE_YS_OC = 3,                                /* @brief ����_OSD��ͼ��ƴ��(OSD Combine) */
    IA_RULE_YS_FACE = 4,
    IA_RULE_YS_BL  = 5,                   /* @brief ����_BLǹ������(Ball Linkage) */
    IA_RULE_YS_VB = 6,                              /* @brief ����_����ʶ��*/
    IA_RULE_YS_TELPHONE = 7,                         /* @brief ����_������绰*/
    IA_RULE_YS_PLANE    = 8,                        /*@brief ����_����ʶ��*/
    IA_RULE_YS_VD        = 9,                       /* @brief ����_��Ƶ��� */
    IA_RULE_YS_VP  = 10,                             /* @brief ����_����ʶ��*/
    IA_RULE_YS_ILLGEAL_PARK = 11,                    /* @brief ����_Υ��ͣ�� */
    IA_RULE_YS_9LIN = 15,                            /*@brief ����_��ƵժҪ*/
/* BEGIN: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */	
    IA_RULE_YS_PRISONDETECT = 20,                    /* @brief ��������*/
/* END: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */
    IA_RULE_YS_CARTYPE = 21
}IA_RULE_TYPE_E;

/**
 * ���ܷ�������ַ�����
 */
typedef enum tagIaSenderType
{
    IA_SENDER_TMS = 1,                          /* @brief ���͸�TMS����ǰֻ֧�����ӿ���Э��(��Ч) */
    IA_SENDER_IAS_DB = 2,                       /* @brief ���������ݱ�����ias DB�� */
    IA_SENDER_LOCAL_VIDEO_STORAGE = 4,          /* @brief ��������Ƶ��Ϣ���浽ias������(��Ч) */
    IA_SENDER_CENTER_VIDEO_STORAGE = 8,         /* @brief ��������Ƶ��Ϣ���浽���Ĵ洢������ */
    IA_SENDER_LOCAL_PIC_STORAGE = 16,           /* @brief ������ͼƬ���ݱ��浽���ط�����(��Ч) */
    IA_SENDER_CENTER_PIC_STORAGE = 32,          /* @brief ������ͼƬ���ݱ��浽ias������(��Ч) */
    IA_SENDER_ALARM_VM = 64,                    /* @brief �����ܷ��������Ϊ�澯�ϱ���VM������(��Ч) */
    IA_SENDER_UI_PICTURE = 128,                 /* @brief ����ͼƬ��ָ���ͻ��� (��Ч)*/
    IA_SENDER_BL_COMMAND = 256,                /* @brief ���������Sender*/
    IA_SENDER_VB = 512 ,                         /* @brief ���괦��*/
    IA_SENDER_TEL = 1024,                        /* @brief ������绰����*/
    IA_SENDER_FILE_UPDATE = 2048,                 /* @brief ���滺���ļ�*/
    IA_SENDER_VD = 4096,                         /* @brief ��Ƶ��� */
    IA_SENDER_PLLPR = 8192  ,              /*����ʶ��*/
    IA_SENDER_VP    = 16384 ,               /*����ʶ��*/
    IA_SENDER_TELFILE4WH = 32768,            /*�人���ֵܾ�ͼƬ��������*/
	IA_SENDER_HUAYI = 65536,            		/*����ʵ��*/
/* BEGIN: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */	
    IA_SENDER_PRISONDETECT = 0x20000,          /* @brief��������*/ 
/* END: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */	
    IA_SENDER_CAR_TYPE = 0x40000    /*@brief ���ͼ��*/
}IA_SENDER_TYPE_E;

/**
 * ������������ģʽ
 */
typedef enum tagIaRunMode
{
    IA_RUN_MODE_FREE = 0,
    IA_RUN_MODE_REAL = 1,               /* @brief ʵʱ����ģʽ */
    IA_RUN_MODE_VOD  = 2,                /* @brief �ط�����ģʽ */
    IA_RUN_MODE_DOWN = 3,               /* @brief ��������ģʽ ��֧��*/
    IA_RUN_MODE_FILE = 4,               /* @brief �����ļ�����ģʽ */
    IA_RUN_MODE_FORMAT = 5 ,
    IA_RUN_MODE_BALLLINKAGE = 6,         /* @brief ǹ������ */
    IA_RUN_MODE_HTTP_IMAGE= 7,          /*@brief http��ȡͼƬģʽ*/
    IA_RUN_MODE_DB = 8,                  /* @brief Dbģʽ */
    IA_RUN_MODE_VD = 9,                   /* @brief��Ƶ���ģʽ */
    IA_RUN_MODE_HTTP_TEL = 10  ,            /* @brief������绰ģʽ */
    IA_RUN_MODE_ILLEGAL_PARK = 11,       /* @briefΥ��ͣ��ģʽ */
    IA_RUN_MODE_9lin_FILE = 14,         /*@brief 9lin �����ļ�*/
    IA_RUN_MODE_9lin_VOD = 15,          /*@brief 9lin �ط�*/
    IA_RUN_MODE_HUAYI_REAL = 16,         /*@brief ����ʵ��*/
/* BEGIN: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */	
    IA_RUN_MODE_PRISON_DETECT = 20,       /* @brief ��������*/
/* END: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */	
    IA_RUN_MODE_CAR_TYPE = 21           /* @brief ���ͼ��*/
}IA_RUN_MODE_E;

/**
 * ������������״̬
 */
typedef enum tagIaRunStatus
{
    IA_RUN_STATUS_STOP,             /* @brief ֹͣ״̬ */
    IA_RUN_STATUS_STOPPING,         /* @brief ֹͣ������ */
    IA_RUN_STATUS_RUN,              /* @brief ������ */
    IA_RUN_STATUS_COMPLETE,         /* @brief ���ܷ������ */
    IA_RUN_STATUS_UPLOAD_EXCEPTION, /* @brief �ϴ��쳣 */
    IA_RUN_STATUS_SOURCE_EXCEPTION,    /* @brief �ط�/ʵ���쳣 */
    IA_RUN_STATUS_UPLOAD,            /* @brief �ļ��ϴ��� */

    /* Begin: Added by kangshunli 2013/6/14 ��Ƶ�������״̬ */
    IA_RUN_STATUS_ANALYZED,          /* @brief �ѷ��� */
    IA_RUN_STATUS_UNANALYZED,          /* @brief �ȴ����� */
    IA_RUN_STATUS_DEL,                 /* @brief ��������ɾ�� */
    /* End: Added by kangshunli 2013/6/14 ��Ƶ�������״̬ */
	IA_RUN_STATUS_PAUSE                /* ������ͣ״̬ */
}IA_RUN_STATUS_E;

/**
 * ����ö�ٶ���(�����ж�һ�ܵ�ĳ���Ƿ������˼ƻ�)
 */
typedef enum tagIaWeekDay
{
    IA_WEEK_SUNDAY = 0,             /* @brief ������ */
    IA_WEEK_MONDAY  = 1,            /* @brief ����һ */
    IA_WEEK_TUESDAY = 2,            /* @brief ���ڶ� */
    IA_WEEK_WEDNESDAY = 4,          /* @brief ������ */
    IA_WEEK_THURSDAY = 8,           /* @brief ������ */
    IA_WEEK_FRIDAY = 16,            /* @brief ������ */
    IA_WEEK_SATURDAY = 32           /* @brief ������ */
}IA_WEEK_DAY_E;

/**
 * ����ö�ٶ���(���ڹ�����ƻ�)
 */
typedef enum tagWeekDay
{
    WEEK_SUNDAY = 0,             /* @brief ������ */
    WEEK_MONDAY  = 1,            /* @brief ����һ */
    WEEK_TUESDAY = 2,            /* @brief ���ڶ� */
    WEEK_WEDNESDAY = 3,          /* @brief ������ */
    WEEK_THURSDAY = 4,           /* @brief ������ */
    WEEK_FRIDAY = 5,            /* @brief ������ */
    WEEK_SATURDAY = 6           /* @brief ������ */
}WEEK_DAY_E;

/**
 * ��Ϣ���Ͷ���
 */
typedef enum tagIaMsgTypeCode
{
    IA_MSG_KEEPALIVE_TIMEOUT = 0,    /* @brief �û����ʱ */
    IA_MSG_START_TASK,               /* @brief ����һ�����ܷ������� */
    IA_MSG_STOP_TASK,                /* @brief �ر�һ�����ܷ������� */
    IA_MSG_INTELLINGET_COMPLETE,     /* @brief ���ܷ���������� */
    IA_MSG_INTELLIGENT_STOP,         /* @brief ���ܷ�������ֹͣ */
    IA_MSG_URL_PICTURE,              /* @brief �ֶ���ȡurlͼƬ */
    IA_MSG_REAL_PICTURE,             /* @brief ��������ʵʱͼƬ���� */
    IA_MSG_REAL_INFO,                /* @brief ��������ʵʱ��Ϣ */

    /* Ias�ڲ�ʹ�� */
    IA_MSG_VM_OFFLINE = 100,                /* @brief VM���������� */
    IA_MSG_VM_VOD_END = 101,                /* @brief �ط����������� */
    IA_MSG_VM_VOD_EXCEPTION = 102,          /* @brief �طŷ��������в����쳣 */

    IA_MSG_VM_DOWN_END = 150,               /* @brief ¼�����غϲ����� */
    IA_MSG_VM_DOWN_EXCEPTION = 151,         /* @brief ¼�����غϲ������г����쳣 */

    IA_MSG_COMBINE_START = 200,             /* @brief ����¼��ϲ� */
    IA_MSG_COMBINE_EXCEPTION = 201,         /* @brief ¼��ϲ��쳣 */
    IA_MSG_COMBINE_END = 202,               /* @brief ¼��ϲ����� */

    IA_MSG_TSLOCAL_FILE_EXCEPTION = 250,    /* @brief �ļ����������в����쳣 */
    IA_MSG_TSLOCAL_FILE_END = 251 ,         /* @brief �ļ����������� */

    IA_MSG_FORMATLOCAL_FILE_EXCEPTION = 300,/* @brief �ļ�ת������������ */
    IA_MSG_FORMATLOCAL_FILE_END = 301,      /* @brief �ļ�ת�����������в����쳣 */

    IA_MSG_SVR_SETUP = 350,
    IA_MSG_REAL_EXCEPTION = 351,            /* @brief �ܽ��쳣 */
    IA_MSG_REAL_EXCEPTION_RECOVER = 352,    /* @brief �ܽ��쳣�ָ� */
    IA_MSG_HTTP_GET_END = 400,       /* @brief http��ȡ��� */
    IA_MSG_HTTP_GET_EXCEPTION = 401,  /* @brief http��ȡʧ�� */
    IA_MSG_TW_INFO       = 500,            /* @brief ���߸澯��Ϣ���� */

    IA_MSG_9LIN_END = 550,                   /*@brief �����������*/
    IA_MSG_9LIN_EXCEPTION = 551            /* @brief ������������в����쳣 */
}IA_MSG_TYPE_CODE_E;

/**
 * IA�����߼�ʱ����Ϣ
 */
typedef struct tagIaAlarmInfo
{
    char szCameraID[IA_ITEM_NAME_LEN];            /* @brief * ���ID */
    char szIntelligentName[IA_ITEM_NAME_LEN];     /* @brief * ������������� */
    char szAlarmTime[IA_ITEM_NAME_LEN];           /* %Y-%m-%d %H:%M:%S */
}IA_ALARM_INFO_S;

/**
 * IAS�������״̬��Ϣ
 */
typedef struct tagIaCameraInfo
{
    char szCameraID[IA_ITEM_NAME_LEN];            /* @brief * ���ID */
    char szCameraType[IA_ITEM_NAME_LEN];          /* @brief * ������� */
    char szCameraIP[IA_IP_LEN];                   /* @brief * ���IP��ַ */
    char szRoadName[IA_ITEM_NAME_LEN];            /* @brief * ·������ */
    char szRoadDirection[IA_ITEM_NAME_LEN];       /* @brief * ·�ڷ��� */
}IA_CAMERA_INFO_S;

/* @brief ʱ�����Ϣ�ṹ�� */
typedef struct tagIaTimeScale
{
    char szBeginTime[IA_ITEM_NAME_LEN];/*"%Y-%m-%d %H:%M:%S"*/
    char szEndTime[IA_ITEM_NAME_LEN]  ;/*"%Y-%m-%d %H:%M:%S"*/
}IA_TIME_SCALE_S;

/**
 * @struct tagIaVodIntelligentTaskInfo
 * @brief vod���ܷ���ҵ��Ĳ�����Ϣ
 * @attention
 */
typedef struct tagIaVodIntelligentTaskInfo
{
    IA_TIME_SCALE_S       stTimeScale;           /* @brief  ��Ҫ��������ƵԴʱ���� */
    long                  lTaskSliceNum;         /* @brief  ������Ƭ��������һ����ʱ��¼�񣬿ɽ�����Ƭ���� */
    IA_VOD_STREAM_SPEED_E eSpeed;                /* @brief  �����ٶȣ�Ӱ��������µ����������� */
    long                  lFrontEventSec;        /* @brief  ��ǰʱ��(��) */
    long                  lAfterEventSec;        /* @brief  �º�ʱ��(��) */
}IA_VOD_INTELLIGENT_TASK_INFO_S;

/**
 * BM�û���������Ϣ
 */
typedef struct tagBmUserInfo
{
    char                    szUserName[IA_ITEM_NAME_LEN];   /* @brief  �û��� */
    char                    szPasswd[IA_ITEM_NAME_LEN];     /* @brief  ���� */
}BM_USER_INFO_S;

/**
 * ���ܻ�����Ϣ
 */
typedef struct tagIaIntelligentInfo
{
    char                    szCameraID[IA_ITEM_NAME_LEN];
    char                    szIntelligentID[IA_ITEM_NAME_LEN];     /* @brief  ������������ */
    char                    szIntelligentName[IA_ITEM_NAME_LEN];
    unsigned long           ulIntelligentHandle;                   /* @brief  ���ܷ������ */
    IA_RUN_STATUS_E         enRunStatus;                           /* @brief  ���õ����ܷ��������Ƿ������� */
    IA_RUN_MODE_E           enRunMode;                             /* @brief  �Ƿ�Ϊʵʱ����ģʽ */
    IA_VOD_INTELLIGENT_TASK_INFO_S  stVodIntelligentTaskInfo;      /* @brief  �ط���ؿ�չ������Ϣ */
    CHAR                    szExtra[IA_ITEM_NAME_LEN];             /* @brief  �����ֽ� */
}IA_INTELLIGENT_INFO_S;

/**
 * @brief rule���ù���һ��rule��Ӧһ��processer
 * @brief vod���ܷ���ҵ��Ĳ�����Ϣ
 * @attention
 */
typedef struct tagIaRuleConfig
{
    IA_RULE_TYPE_E  enRuleType;                         /* @brief  ���ù������� */
    char            szRuleName[IA_ITEM_NAME_LEN];       /* @brief  �������ƣ��ͻ����û������Զ��� */
    char            szLastRuleName[IA_ITEM_NAME_LEN];   /* @brief  ǰһ���ù������� */
    unsigned long   ulItemsruleSize;                    /* @brief  ���ù�����Ϣ��С */
    unsigned char   szItemsrule[RULE_CFG_LEN];          /* @brief  ���ù������� */
}IA_RULE_CONFIG_S;

/**
 * @brief ����һ������ҵ����򣬺��ж��rule��Ԫ
 * @brief vod���ܷ���ҵ��Ĳ�����Ϣ
 * @attention
 */
typedef struct tagIaIntelligentConfig
{
    unsigned long      ulRuleNum;                      /* @brief  �����ð����Ĺ����� */
    IA_RULE_CONFIG_S   szstRuleItem[MAX_RULE_NUM];     /* @brief  ���ù���ṹ������ */
}IA_INTELLIGENT_CONFIG_S;

/**
 * @struct tagDayPlanDetail
 * @brief  �ܼƻ���Ϣ�ṹ��Ԫ����ƻ����飩
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
 * @brief ��������ļƻ�
 * @attention
 */
typedef struct tagIaTaskPlanInfo
{
    long             lTrigTime;                                      /* @brief  ����ʱ����,ÿ������ִֻ��һ�εģ����ʱ��Ϊ0����λ�� */
    long             lWeekDay;                                       /* @brief  �ο�IA_WEEK_DAY_E */
    IA_TIME_SCALE_S  szWithinPlanTimeScale;                          /* @brief  �ƻ���ʱ��Σ����ڰ�������*/
    IA_TIME_SCALE_S  szBeyondPlanTimeScale[MAX_PLAN_TIME_SCALE];     /* @brief  ����ʱ��� */
	DAY_PLAN_DETAIL_S szWeekPlanInfo[DAY_COUNT_OF_WEEK];             /* @brief  �ܼƻ���Ϣ */
}IA_TASK_PLAN_INFO_S;

/**
 * @struct tagIaMsgHeaderInfo
 * @brief  tcp����ʱ��Ϣͷ����
 * @attention
 */
typedef struct tagIaMsgHeaderInfo
{
    unsigned long            ulIntelligentHandle;                    /* @brief  ���ܷ������ */
    IA_MSG_TYPE_CODE_E       enMsgTypeCode;                          /* @brief  ��Ϣ���� */
    unsigned long            ulMsgLen;                               /* @brief  ��Ϣ���� */
    unsigned char            szMsgExInfo[IA_ITEM_NAME_LEN];          /* @brief  ��չ��Ϣ��Ϣ,���ֶο�����Ϊurl��Ϣʹ�� */
}IA_MSG_HEADER_INFO_S;

/**
* @struct tagIaSystemInfo
* @brief  iaϵͳ��Ϣ
* @attention
*/
typedef struct tagIaSystemInfo
{
    long lCpu;                      /* @brief  cpuʹ����[0-100] */
    long lMemory;                   /* @brief  �ڴ�ʹ����[0-100] */
    long lDisk;                     /* @brief  Ӳ��ʹ����[0-100] */
    long lNetWork[IA_NETWORK_NUM];  /* @brief  ����1ʹ����[0-100] */
    long lUser[IA_NETWORK_NUM];     /* @brief  ������Ϣ */
}IA_SYSTEM_INFO_S;

/**
* ��Ϣ�ϱ��ص��ӿ����Ͷ���
* @param [IN] lUserHandle           �û���¼���
* @param [IN] ulIntelligentHandle   ���ܷ������
* @param [IN] iMsgCode              ��Ϣ����,��ǰ֧��ͼƬ���͵������ϱ�
* @param [IN] szMsgBuf              ��Ϣ��ַ
* @param [IN] ulMsgLen              ��Ϣ����
* @param [IN] pUsrData              �û��Զ�������
* @return �ͻ�����Ϣ�ϱ�����ԭ�Ͷ���
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
* ��Ϣ�ϱ��ص��ӿ����Ͷ���
* @param [IN] lUserHandle           �û���¼���
* @param [IN] ulIntelligentHandle   ���ܷ������
* @param [IN] iMsgCode              ��Ϣ����,��ǰ֧��ͼƬ���͵������ϱ�
* @param [IN] szMsgBuf              ��Ϣ��ַ
* @param [IN] ulMsgLen              ��Ϣ����
* @param [IN] pUsrData              �û��Զ�������
* @return �ͻ�����Ϣ�ϱ�����ԭ�Ͷ���
*/
typedef void (STDCALL * MsgCallBack)(IN long lUserHandle,
                                     IN unsigned long ulIntelligentHandle,
                                     IN long lMsgCode,
                                     IN char* szMsgBuf,
                                     IN unsigned long ulMsgLen,
                                     IN void* pUsrData,
                                     IN ULONG ulUser1);

#endif
