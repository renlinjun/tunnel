
/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_terminal_def.h

  Project Code: IMOS PLAT
   Module Name: PUBLIC
  Date Created: 2009-06-09
        Author: lipengfei/07070
   Description: 基础平台公共头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_TERMINAL_DEF_H_
#define _IMOS_TERMINAL_DEF_H_

#ifdef  __cplusplus
extern "C"{
#endif

/* 波特率 */
#define IMOS_BUADRATE_1200                      1200
#define IMOS_BUADRATE_2400                      2400
#define IMOS_BUADRATE_4800                      4800
#define IMOS_BUADRATE_9600                      9600
#define IMOS_BUADRATE_19200                     19200
#define IMOS_BUADRATE_38400                     38400
#define IMOS_BUADRATE_57600                     57600
#define IMOS_BUADRATE_115200                    115200

/* 串口流控 */
#define IMOS_FLOW_CTRL_NULL                     0
#define IMOS_FLOW_CTRL_SOFTWARE                 1
#define IMOS_FLOW_CTRL_HARDWARE                 2

/* 校验位 */
#define IMOS_PARITY_NULL                        0
#define IMOS_PARITY_ODD                         1
#define IMOS_PARITY_EVEN                        2

#define IMOS_IPC_PREFIX_LEN                     3    /* IPC的前3位英文编号长度 */
#define IMOS_SIC_DESC                           "SIC"
#define IMOS_HIC_DESC                           "HIC"
#define IMOS_HIC5401_DESC                           "HIC5401"
#define IMOS_HIC5421_DESC                           "HIC5421"
#define IMOS_HIC5201_H_DESC                         "HIC5201-H"
#define IMOS_HIC5221_H_DESC                         "HIC5221-H"
#define IMOS_HIC6621_DESC                           "HIC6621"
#define IMOS_HIC6501_DESC                           "HIC6501"
#define IMOS_HIC3401_DESC                           "HIC3401"
#define IMOS_HIC3421_DESC                           "HIC3421"
#define IMOS_HIC3401_D_DESC                         "HIC3401D"
#define IMOS_SIC235_DESC                            "SIC235"
#define IMOS_SIC335_E_DESC                          "SIC335E"
#define IMOS_SIC335_D_DESC                          "SIC335D"
#define IMOS_HIC7501_DESC                           "HIC7501"
#define IMOS_HIC7621_DESC                           "HIC7621"
#define IMOS_HIC7821_DESC                           "HIC7821"
#define STANDARD_DEF_IP_CAMERA                "STANDARD_DEF_IP_CAMERA"
#define HIGH_DEF_IP_CAMERA                    "HIGH_DEF_IP_CAMERA"
#define HIGH_DEF_IP_CAMERA_720                "HIGH_720P_DEF_IP_CAMERA"
#define HIGH_DEF_IP_CAMERA_1080               "HIGH_1080P_DEF_IP_CAMERA"
#define HIGH_DEF_IP_CAMERA_3M               "HIGH_3M_DEF_IP_CAMERA"
#define IMOS_IPC_CHANNEL_NUM                    1
#define IMOS_HTS_DESC                       ("HTS")
/* Begin Added by zhangjiarui03328,2017-03-09 for MPPD37115 */
#define IMOS_PC_DESC                         ("PC")
#define IMOS_IPC_DESC                         ("IPC-")
/* End Added by zhangjiarui03328,2017-03-09 for MPPD37115 */

/* 前端设备类型 */
typedef enum tagIMOSDeviceType
{
    IMOS_DT_EC1001_HF = 0,
    IMOS_DT_EC1002_HD,                          /* 软型号 由 EC1004_HC 配置而成，对应 EC1004-HC[2CH] */
    IMOS_DT_EC1004_HC,
    IMOS_DT_EC2004_HF,
    IMOS_DT_ER3304_HF,
    IMOS_DT_ER3308_HD = 5,
    IMOS_DT_ER3316_HC,
    IMOS_DT_DC1001_FF = 7,
    IMOS_DT_EC3016_HF,
    IMOS_DT_ISC3100_ER,
    IMOS_DT_EC1001_EF = 10,
    IMOS_DT_EC3004_HF_ER,
    IMOS_DT_EC3008_HD_ER,
    IMOS_DT_EC3016_HC = 13,
    IMOS_DT_EC3016_HC_8CH = 14,
    IMOS_DT_EC3016_HC_4CH = 15,

    /* 枚举值 200 -- 500 */
    IMOS_DT_EC2016_HC = 200,
    IMOS_DT_EC2016_HC_8CH,
    IMOS_DT_EC2016_HC_4CH,
    IMOS_DT_EC1501_HF,                          /* 6437真双流 */
    IMOS_DT_EC1004_MF,                          /* 多路EC */
    IMOS_DT_ECR2216_HC,                         /* ECR预研，1U */
    IMOS_DT_EC1304_HC,                          /* 带PCMCIA */
    IMOS_DT_EC1501_IHF = 207,
    IMOS_DT_EC1504_HFE = 208,                   /* EC1504-HF-E */
    IMOS_DT_EC2508_HFE = 209,                   /* EC2508-HF-E */
    IMOS_DT_EC2516_HFE = 210,                   /* EC2516-HF-E */
    IMOS_DT_EC1504_HFW = 211,                   /* EC1504-HF-W */
    IMOS_DT_EC2508_HFW = 212,                   /* EC2508-HF-W */
    IMOS_DT_EC2516_HFW = 213,                   /* EC2516-HF-W */
    IMOS_DT_EC2524_HF  = 214,                   /* EC2524-HF */


    IMOS_DT_ECR3316_HC = 300,
    IMOS_DT_ECR3316_HC_8CH,
    IMOS_DT_ECR3316_HC_4CH,
    IMOS_DT_ECR3308_HD,
    IMOS_DT_ECR3308_HD_4CH,

    /* 枚举值 500 -- 800 */
    IMOS_DT_DC3016_FC = 500,                    /* 目前V1R5，2U，和ISC3000-M共用设计 */
    IMOS_DT_DC2016_FC,                          /* DC3016-FC降成本 */
    IMOS_DT_DC1016_MF,                          /* 多路DC */
    IMOS_DT_DC2004_FF,                          /* 带数字矩阵的多路DC */

    IMOS_DT_EC1001 = 1000,                      /* R1 编码板，为了方便扩展，从1000开始计数 */
    IMOS_DT_DC1001 = 1001,                      /* R1 解码板 */
    IMOS_DT_EC1101_HF = 1002,
    IMOS_DT_EC1102_HF = 1003,
    IMOS_DT_EC1801_HH = 1004,
    IMOS_DT_DC1801_FH = 1005,
    IMOS_DT_ECR3308_HF = 1006,                  /* ECR3308-HF */
    IMOS_DT_ECR3316_HF = 1007,                  /* ECR3316-HF */
    IMOS_DT_EC1504_HF = 1008,                   /* EC1504-HF */
    IMOS_DT_EC2516_HF = 1009,                   /* EC2516-HF */
    IMOS_DT_EC2508_HF = 1010,                   /* EC2508-HF */
    IMOS_DT_EC1004_HC_1CH   = 1011,
    IMOS_DT_EC1004_HC_2CH   = 1012,
    IMOS_DT_EC2508_HF_4CH = 1013,
    IMOS_DT_EC2516_HF_8CH = 1014,
    IMOS_DT_EC_PAG = 1015,

    IMOS_DT_ECR3308_HF_E = 1016,                  /* ECR3308-HF-E */
    IMOS_DT_ECR3316_HF_E = 1017,                  /* ECR3316-HF-E */
    IMOS_DT_ECR3308_HF_S = 1018,                  /* ECR3308-HF-S */
    IMOS_DT_ECR3316_HF_S = 1019,                  /* ECR3316-HF-S */
    IMOS_DT_ISC3500_ET = 1020,                    /* ISC3500_ET */
    IMOS_DT_ISC3500_EL = 1021,                    /* ISC3500_EL */
    IMOS_DT_ISC3500_ST = 1022,                    /* ISC3500_ST */
    IMOS_DT_ISC3500_SL = 1023,                    /* ISC3500_SL */

    IMOS_DT_EC_PAG_NVR = 1024,                  /* PAG模型，NVR子类 */

    /* V3R5产品 */
    IMOS_DT_DC2808_FH = 1100,                     /* DC2808-FH */
    IMOS_DT_DC2804_FH = 1101,                     /* DC2804-FH */

	/* Begin added by y01359, 2016-03-30 for ADU8618作为DC2816-FH接入VM */
	IMOS_DT_DC2816_FH = 1102,                     /* DC2816-FH */
	/* End added by y01359, 2016-03-30 for ADU8618作为DC2816-FH接入VM */

    /* Begin: added by l02289, 2015-05-19 for V3R7 DC */
    /* V3R7产品 */
    IMOS_DT_DC1801_FH_E = 1150,                   /* DC1801-FH-E */
    IMOS_DT_DC2804_FH_E = 1151,                   /* DC2804-FH-E */
    IMOS_DT_DC2808_FH_E = 1152,                   /* DC2808-FH-E */
    IMOS_DT_DC2816_FH_E = 1153,                   /* DC2816-FH-E */
    IMOS_DT_DC1801_FH_S = 1154,                   /*  DC1801-FH-S */
    /* End: added by l02289, 2015-05-19 for V3R7 DC */

    /* ONVIF DC */
    IMOS_DT_DC_ONVIF = 1200,

	/*GB DC*/
	IMOS_DT_DC_GB = 1201,                        /*Added by fW2028, 2016-03-24 for MPPD35331*/

    /* Begin: Added by mozhanfei(kf0149), 2013-7-30 for VX500E */
    IMOS_DT_VX500_E = 2001,                          /* VX500_E */
    /* End: Added by mozhanfei(kf0149), 2013-7-30 for VX500E */

    /* Begin: Added by luchunfeng(02289), 2015-09-11 for ADU*/
    IMOS_DT_ADU8606 = 3000,                       /* ADU8606 */
    IMOS_DT_ADU8609 = 3001,                       /* ADU8609 */
    IMOS_DT_ADU8612 = 3002,                       /* ADU8612 */
    IMOS_DT_ADU8615 = 3003,                       /* ADU8615 */
    IMOS_DT_ADU8618 = 3004,                       /* ADU8618 */
    IMOS_DT_ADU8609_4K = 3005,                    /* ADU8609-4K */
    IMOS_DT_ADU8618_4K = 3006,                    /* ADU8618-4K */
    /* End: Added by luchunfeng(02289), 2015-09-11 for ADU*/

    /* ECR产品型号 范围 */
    IMOS_DT_ECR_MIN  = 7000,
    IMOS_DT_ECR2104_HF = 7001,                    /* ECR2104-HF */
    IMOS_DT_ECR2108_HF = 7002,                    /* ECR2108-HF */
    IMOS_DT_ECR_MAX  = 7999,

    /* ISC产品型号 范围 */
    IMOS_DT_ISC_MIN  = 8000,
    IMOS_DT_ISC2500_SP = 8001,                    /* ISC2500_SP */
    IMOS_DT_ISC2500_EP = 8002,                    /* ISC2500_EP */
    IMOS_DT_ISC5000_S  = 8003,                    /* ISC5000_S */
    IMOS_DT_ISC5000_E  = 8004,                    /* ISC5000_E */
    IMOS_DT_ISC2500_S  = 8005,                    /* ISC2500_S */
    IMOS_DT_ISC2500_E  = 8006,                    /* ISC2500_E */
    IMOS_DT_ISC3500E_B05  = 8007,                    /* ISC3500-E_B05 */
    IMOS_DT_ISC3500S_B05  = 8008,                    /* ISC3500-S_B05 */
    IMOS_DT_ISC2500_SCT  = 8100,                    /* ISC2500_SCT */
    IMOS_DT_ISC_MAX  = 8999,

    /* OEM产品型号 */
    IMOS_DT_VR2004 = 10003,
    IMOS_DT_R1000  = 10203,
    IMOS_DT_VL2004 = 10503,
    IMOS_DT_VR1102 = 11003,
    /* IPC产品型号 */
    /* AddedBy liuhongjieKF0170,2013-9-6 of IPC支持区块OSD */
    IMOS_DT_IPC_MIN=12000, /** IPC产品型号最小类型  */
    IMOS_DT_HIC5201 = 12001,
    IMOS_DT_HIC5221 = 12002,
    IMOS_DT_HIC5421 = 12003,
    IMOS_DT_HIC5401 = 12004,
    IMOS_DT_SIC = 12005,    /**< 标清网络摄像机(standard definition IP camera) */
    IMOS_DT_HIC = 12006,    /**< 高清网络摄像机(high definition IP camera) */
    IMOS_DT_HIC_1080P = 12007, /**< 高清网络摄像机(high definition IP camera)1080P */
    HIGH_3M_DEF_IP_CAMERA = 12008,  /**< 3M高清网络摄像机(high definition IP camera) */
    IMOS_DT_HIC_HTS   = 12009,        /**<智能交通高清网络摄像机 */
    IMOS_DT_PC = 12010,                    /** <停车场摄像机*/
    /* AddedBy liuhongjieKF0170,2013-9-6 of IPC支持区块OSD */
    IMOS_DT_IPC_MAX=19899, /** IPC产品型号最大类型 */

    IMOS_DT_TOLLGATE_MIN_TYPE = 19900,         /* 卡口设备最小类型 */

    IMOS_DT_HTS_HC131_FE   = 19972,            /* HTS-HC131-FE */
    IMOS_DT_HTS_HC131_FR   = 19973,            /* HTS-HC131-FR */
    IMOS_DT_HTS_HC131_FE_A = 19974,            /* HTS-HC131-FE-A */
    IMOS_DT_HTS_HC131_FR_A = 19975,            /* HTS-HC131-FR-A */
    IMOS_DT_HTS_HC531_F    = 19976,            /* HTS-HC531-F */
    IMOS_DT_HTS_HC531_F_A  = 19977,            /* HTS-HC531-F-A */


    IMOS_DT_HTS_HC521_FP = 19978,              /* HTS-HC521-FP */
    IMOS_DT_HTS_HC551_FP = 19979,              /* HTS-HC551-FP */
    IMOS_DT_HTS_HC121_FP = 19980,              /* HTS-HC121-FP */
    IMOS_DT_HTS_HC151_FR = 19981,              /* HTS-HC151-FR */
    IMOS_DT_HTS_HC151_FE = 19982,              /* HTS-HC151-FE */
    IMOS_DT_HTS_HC121_FR = 19983,              /* HTS-HC121-FR */
    IMOS_DT_HTS_HC121_FE = 19984,              /* HTS-HC121-FE */
    IMOS_DT_HTS_HC122_FR = 19985,              /* HTS-HC122-FR */
    IMOS_DT_HTS_HC122_FE = 19986,              /* HTS-HC122-FE */
    IMOS_DT_HTS_HC151_FP = 19987,              /* HTS-HC151-FP */
    IMOS_DT_HIC5421_E_K = 19988,               /* HIC5421E-K */
    IMOS_DT_HTS_HC121_F = 19989,               /* HTS-HC121-F */
    IMOS_DT_HTS_HC122_F = 19990,               /* HTS-HC122-F */
    IMOS_DT_HTS_HC321_F = 19991,               /* HTS-HC321-F */
    IMOS_DT_HTS_HC521_F = 19992,               /* HTS-HC521-F */
    IMOS_DT_HTS_HC551_F = 19993,               /* HTS-HC551-F */
    IMOS_DT_HTS_HC321_E = 19994,               /* HTS-HC321-E */
    IMOS_DT_HTS_HC121_E = 19995,               /* HTS-HC121-E */
    IMOS_DT_HTS_HC122_E = 19996,               /* HTS-HC122-E */
    IMOS_DT_HTS_HC121 = 19997,                 /* HTS-HC121 */
    IMOS_DT_HTS_HC221 = 19998,                 /* HTS-HC221 */
    IMOS_DT_HTS_HC321 = 19999,                 /* HTS-HC321 */

    /* SDC设备 */
    IMOS_DT_SDC_HJSX = 20000,                   /* 黄金视讯的SDC */

    /* 嵌入式解码器(解码卡)*/
    IMOS_DT_EDC_NI01IN4DC   = 20001,           /* NI01IN4DC */


	/* Begin Added by y01359 2014-09-26 for A8 */
    IMOS_TYPE_EC_A8 = 21001,                 /**< A8设备EC */
    IMOS_TYPE_DC_A8 = 21002,                 /**< A8设备DC */

    /* Added by liujian/02319, 2016-10-17  for  GNVR以GB协议和设备形式接入 */
    IMOS_DT_GNVR = 21003,					/**< 工程商NVR */
    
    /* End Added by y01359 2014-09-26 for A8 */
    IMOS_DT_BUTT
}IMOS_DEVICE_TYPE_E;

/* 编码格式搭配套餐 */
typedef enum tagIMOSStreamRelationSet
{
    IMOS_SR_MPEG4_MPEG4 = 0,                    /* MPEG4[主码流] + MPEG4[辅码流] */
    IMOS_SR_H264_SHARE = 1,                     /* H.264[主码流] */
    IMOS_SR_MPEG2_MPEG4 = 2,                    /* MPEG2[主码流] + MPEG4[辅码流] */
    IMOS_SR_H264_MJPEG = 3,                     /* H.264[主码流] + MJPEG[辅码流] */
    IMOS_SR_MPEG4_SHARE = 4,                    /* MPEG4[主码流] */
    IMOS_SR_MPEG2_SHARE = 5,                    /* MPEG2[主码流] */
    IMOS_SR_STREAM_MPEG4_8D1 = 8,               /* MPEG4[主码流_D1] 8D1 套餐*/
    IMOS_SR_MPEG2_MPEG2 = 9,                    /* MPEG2[主码流] + MPEG2[辅码流] */
    IMOS_SR_H264_H264 = 11,                     /* H.264[主码流] + H.264[辅码流] */
    IMOS_SR_MPEG2_H264 = 13,                    /* MPEG2[主码流] + H.264[辅码流] */

    IMOS_SR_H264_H264_H264 = 14,                /* H.264[主码流] + H.264[辅码流] + H.264[第三码流] */
    IMOS_SR_H264_JPEG      = 15,                /* H.264[主码流] + JPEG[辅码流] */
    /* Begin: added by zhangdong(kf0134), 2013.1.7 for 摄像机支持流套餐*/
    IMOS_SR_MJPEG_SHARE = 16,               /* MJPEG[ 主码流] */
    /* End: added by zhangdong(kf0134), 2013.1.7 for 摄像机支持流套餐*/
    IMOS_SR_BUTT,
    IMOS_SR_INVALID        =0xFFFF              /* 65535非法值 */
}IMOS_STREAM_RELATION_SET_E;

/* 码流类型 */
typedef enum tagIMOSStreamType
{
    IMOS_ST_TS  = 0,
    IMOS_ST_H3C_ES = 1,                         /* H3C ES RTP */
    IMOS_ST_PS  = 2,
    IMOS_ST_MEGA_EYE = 3,                       /* 中国电信全球眼 */
    IMOS_ST_CNC = 4,                            /* 中国网通宽世界 */
    IMOS_ST_LPR = 5,                            /* LPR流封装格式 */
    IMOS_ST_UNIVIEW = 6,                        /* 宇视卡口电警协议 */
    IMOS_ST_IMOS_ALL = 7,                       /* IMOS所有流封装格式 */
    IMOS_ST_3984 = 8,                           /* ONVIF 3984原始流 */
    IMOS_ST_BUTT
}IMOS_STREAM_TYPE_E;

 /* 图像制式 */
typedef enum tagIMOSPictureFormat
{
	IMOS_PF_PAL = 0,							/* PAL 制式 */
	IMOS_PF_NTSC,								/* NTSC 制式 */
	IMOS_PF_720P24HZ,
	IMOS_PF_720P25HZ,
	IMOS_PF_720P30HZ,
	IMOS_PF_720P50HZ,
	IMOS_PF_720P60HZ,
	IMOS_PF_1080I48HZ,
	IMOS_PF_1080I50HZ,
	IMOS_PF_1080I60HZ,
	IMOS_PF_1080P24HZ,	/*枚举 10*/
	IMOS_PF_1080P25HZ,
	IMOS_PF_1080P30HZ,
	IMOS_PF_1080P50HZ,
	IMOS_PF_1080P60HZ,
	IMOS_PF_XGA60HZ,
	IMOS_PF_SXGA60HZ,
	IMOS_PF_AUTO,
	IMOS_PF_UXGA25HZ,
	IMOS_PF_3MP12_HALF,
	IMOS_PF_3MP15,			/* 枚举 20 */
	IMOS_PF_3MP20,
	IMOS_PF_5MP12_HALF, /* 5M@12.5HZ */
	IMOS_PF_5MP15,			/* 5M@15HZ */
	IMOS_PF_5MP25,
	IMOS_PF_WUXGA25HZ,
	IMOS_PF_WUXGA30HZ,
	IMOS_PF_960P25HZ,
	IMOS_PF_960P30HZ,
	IMOS_PF_3MP25,
	IMOS_PF_3MP30,			/*枚举 30*/
	IMOS_PF_1460P12,		/* 1940x1460@12 */
	IMOS_PF_1460P15,		/* 1940x1460@15 */
	IMOS_PF_1460P25,		/* 1940x1460@25 */
	IMOS_PF_1460P30,		/* 1940x1460@30 */
	IMOS_PF_5MP30,
	IMOS_PF_2208P12,	  /* 2758x2208@12 */
	IMOS_PF_2208P15,		/* 2758x2208@15 */
	IMOS_PF_2208P25,		/* 2758x2208@25 */
	IMOS_PF_2208P30,		/* 2758x2208@30 */
	IMOS_PF_2472P12,		/* 3296x2472@12 */ /* 枚举40 */
	IMOS_PF_2472P15,		/* 3296x2472@15 */
	IMOS_PF_2472P25,		/* 3296x2472@25 */
	IMOS_PF_2472P30,		/* 3296x2472@30 */
	IMOS_PF_2160P25,		/* 3840x2160@25 */
	IMOS_PF_2160P30,		/* 3840x2160@30*/
	IMOS_PF_2160FP25,		/* 4096×2160@25 */
	IMOS_PF_2160FP30,		/* 4096×2160@30 */
	IMOS_PF_UXGA30,
	IMOS_PF_UXGA50,
	IMOS_PF_960P50, 	/*枚举50*/
	IMOS_PF_960P60,
	IMOS_PF_SXGA25HZ,
	IMOS_PF_SXGA30HZ,
	IMOS_PF_SXGA50HZ,
	IMOS_PF_UXGA60HZ,
	IMOS_PF_WUXGA50,
	IMOS_PF_WUXGA60,
	IMOS_PF_2000P25,		/* 3008x2000@25 */
	IMOS_PF_1760P25,		/* 3408x1760@25 */
	IMOS_PF_2008P20,		/* 3408x2008@20 */ /* 枚举60 */
	IMOS_PF_12MP25,   /* 4000*3000 */
	IMOS_PF_12MP30,   /* 4000*3000 */
	IMOS_PF_12MP20,   /* 4000*3000 */
	IMOS_PF_4096_2160P12,
	IMOS_PF_2592_1520P20,
	IMOS_PF_2048_1520P25,
	IMOS_PF_WSXGAPLUS60,
	IMOS_PF_2048_1520P30,
	IMOS_PF_2560_1440_25,
	IMOS_PF_4000_3000_10,

    /* Begin: Added by songshihui/W4519, 2017-12-26 for MPPD54568 4K鱼眼接入平台 */
    IMOS_PF_12MP15,         /* 4000x3000@15 */
    IMOS_PF_9MP15,          /* 3008x3000@15 */
    IMOS_PF_2560_2560P25,   /* 2560x2560@25 */
    /* End: Added by songshihui/W4519, 2017-12-26 for MPPD54568 4K鱼眼接入平台 */

    /* Begin: Added by songshihui/W4519, 2018-03-05 for 6MP人脸抓拍相机接入平台 */
    IMOS_PF_3072_2048P25,        /* 3072x2048@25 */
    IMOS_PF_3072_2048P30,        /* 3072x2048@30 */
    IMOS_PF_3072_1728P25,        /* 3072x1728@25 */
    IMOS_PF_3072_1728P30,        /* 3072x1728@30 */
    /* End: Added by songshihui/W4519, 2018-03-05 for 6MP人脸抓拍相机接入平台 */

	IMOS_PF_INVALID
}IMOS_PICTURE_FORMAT_E;



/* 视频编码格式 */
typedef enum tagIMOSVideoFormat
{
    IMOS_VF_MPEG1 = 0,
    IMOS_VF_MPEG2,
    IMOS_VF_MPEG4,
    IMOS_VF_MJPEG,
    IMOS_VF_H263,
    IMOS_VF_H263PLUS,
    IMOS_VF_H264,
    IMOS_VF_H265,
    IMOS_VF_JPEG = 12,
    IMOS_VF_BUTT,
    IMOS_VF_ENCFORMAT_INVALID = 0xFFFF         /* OTHER */
}IMOS_VIDEO_FORMAT_E;

/* 流传输方式 */
typedef enum tagIMOSTransType
{
    IMOS_TT_UDP = 0,
    IMOS_TT_TCP = 1,
    IMOS_TT_RTP = 2,
    IMOS_TT_RTP_NO_RTCP = 3,
    IMOS_TT_AUTO = 4,
    IMOS_TT_BUTT = 5,
	IMOS_TT_TCP_SERVER = 6
}IMOS_TRANS_TYPE_E;

/* 编码方式 */
typedef enum tagIMOSEncMode
{
    IMOS_EM_CBR = 0,                           /* CBR方式 */
    IMOS_EM_VBR,                               /* VBR方式 */
    IMOS_EM_BUTT
}IMOS_ENC_MODE_E;

/* CBR 编码模式设置 */
typedef enum tagIMOSCbrEncMode
{
    IMOS_CE_MODE_FLUENT = 0,                   /* 连贯性方式 */
    IMOS_CE_MODE_CLEARLY,                      /* 清晰性方式 */
    IMOS_CE_MODE_INVALID
}IMOS_CBR_ENC_MODE_E;

/* 平滑等级设置 */
typedef enum tagIMOSStreamSmooth
{
    IMOS_SS_NO_SMOOTH = 0,
    IMOS_SS_VALUE1,
    IMOS_SS_VALUE2,
    IMOS_SS_VALUE3,
    IMOS_SS_VALUE4,
    IMOS_SS_VALUE5,
    IMOS_SS_VALUE6,
    IMOS_SS_VALUE7,
    IMOS_SS_VALUE8,
    IMOS_SS_VALUE9,
    IMOS_SS_INVALID_VALUE
}IMOS_STREAM_SMOOTH_E;
/*Begin added by liangchao, 2016-03-24 for svc特性合主线*/
/* SVC配置 */
typedef enum tagIMOSSVCMode
{
	IMOS_SVC_OFF = 0,
	IMOS_SVC_ON
}IMOS_SVC_MODE_E;
/*End added by liangchao, 2016-03-24 for svc特性合主线*/

/* GOP 结构参数 */
typedef enum tagIMOSGopType
{
    IMOS_GT_IP = 0,                           /* IP */
    IMOS_GT_IBP,                              /* IBP */
    IMOS_GT_IBBP,                             /* IBBP */
    IMOS_GT_I,                                /* I */
    IMOS_GT_INVALID                           /* OTHER */
}IMOS_GOP_TYPE_E;


/* 图像大小，增加枚举新增加对应具体分辨率注释 */
typedef enum tagIMOSPictureSize
{
	IMOS_PS_D1 = 0,
	IMOS_PS_4CIF,
	IMOS_PS_2CIF,
	IMOS_PS_CIF,
	IMOS_PS_QCIF,
	IMOS_PS_HALFD1,
	IMOS_PS_720,	  /* 1280x720 */
	IMOS_PS_1080,	  /* 1920x1080 */
	IMOS_PS_1024,		/* 1024x768 */
	IMOS_PS_1280,
	IMOS_PS_UXGA,		/* 1600x1200 */  /*枚举10*/
	IMOS_PS_3M, 	/* 2048x1536 */
	IMOS_PS_5M, 	/* 2592x2048 */
	IMOS_PS_DEFINE, 	/* 以后有新增枚举请加在 IMOS_PS_DEFINE后面 */
	IMOS_PS_960,	   /*  960P */
	IMOS_PS_960H,
	IMOS_PS_800,		/* 800x600 */
	IMOS_PS_1460,		/* 1940x1460 */
	IMOS_PS_2208,		/* 2758x2208 */
	IMOS_PS_2472,		/* 3296x2472 */
	IMOS_PS_2160,		/* 3840x2160*/	/* 枚举20 */
	IMOS_PS_2160F,		/* 4096x2160 */
	IMOS_PS_2000,		/* 3008x2000 */
	IMOS_PS_1760,		/* 3408x1760 */
	IMOS_PS_2008,		/* 3408x2008 */
	IMOS_PS_12M,		/* 4000x3000 */
	IMOS_PS_WUXGA,/*1920x1200*/
	IMOS_PS_1440,		/* 2560x1440 */
	IMOS_PS_1520F,		/* 2592x1520 */
	IMOS_PS_1050,	   /* 1680*1050 */
	IMOS_PS_1520,		/* 2048x1520 */
	IMOS_PS_3008_3000,
	IMOS_PS_2560_1800,
	IMOS_PS_2560_912,
	IMOS_PS_1536_1536,
	IMOS_PS_1600_600,
	IMOS_PS_2560_1440,
	IMOS_PS_1280_1280,

    /* Begin: Added by songshihui/W4519, 2017-12-26 for MPPD54568 4K鱼眼接入平台 */
    IMOS_PS_3000_3000,    /* 3000x3000 */
    IMOS_PS_3000_2000,    /* 3000x2000 */
    IMOS_PS_2560_2560,    /* 2560x2560 */  /* 枚举40 */
    IMOS_PS_2000_1500,    /* 2000x1500 */
    IMOS_PS_2000_2000,    /* 2000x2000 */
    IMOS_PS_3000_1500,    /* 3000x1500 */
    /* End: Added by songshihui/W4519, 2017-12-26 for MPPD54568 4K鱼眼接入平台 */

    /* Begin: Added by songshihui/W4519, 2018-03-05 for 6MP人脸抓拍相机接入平台 */
    IMOS_PS_3072_2048,    /* 3072x2048 */
    IMOS_PS_3072_1728,    /* 3072x1728 */
    /* End: Added by songshihui/W4519, 2018-03-05 for 6MP人脸抓拍相机接入平台 */

	IMOS_PS_INVALID
}IMOS_PICTURE_SIZE_E;


/* 图像质量，在VBR 模式下有效 */
typedef enum tagIMOSVideoQuality
{
    IMOS_VQ_L0 = 0,                          /* Level 0*/
    IMOS_VQ_L1 = 1,                          /* Level 1*/
    IMOS_VQ_L2 = 4,                          /* Level 2*/
    IMOS_VQ_L3 = 8,                          /* Level 3*/
    IMOS_VQ_L4 = 12,                         /* Level 4*/
    IMOS_VQ_L5 = 16,                         /* Level 5*/
    IMOS_VQ_L6 = 20,                         /* Level 6*/
    IMOS_VQ_L7 = 24,                         /* Level 7*/
    IMOS_VQ_L8 = 28,                         /* Level 8*/
    IMOS_VQ_L9 = 31                          /* Level 9*/
}IMOS_VIDEO_QUALITY_E;

/* 声道设置：L/R/STERO(MIC为单声道) */
typedef enum tagIMOSAudioChannelType
{
    IMOS_AC_STEREO = 0,                      /* 立体声 */
    IMOS_AC_L,                               /* 左声道 */
    IMOS_AC_R,                               /* 右声道 */
    IMOS_AC_MONO,                            /* 单声道 */
    IMOS_AC_INVALID
}IMOS_AUDIO_CHANNEL_TYPE_E;

/* 音频输入源：凤凰头/BNC和MIC二者选一 */
typedef enum tagIMOSAudioInputSource
{
    IMOS_AI_LR = 0,                          /* 凤凰头/BNC输入方式 */
    IMOS_AI_MIC,                             /* MIC输入方式 */
    IMOS_AI_INVALID                          /* OTHER */
}IMOS_AUDIO_INPUT_SOURCE_E;

/* 音频编码格式定义 */
typedef enum tagIMOSAudioFormat
{
    IMOS_AF_MPEG1_LAYER2 = 0,
    IMOS_AF_G711A,
    IMOS_AF_G711U,
    IMOS_AF_ADPCM,
    IMOS_AF_AUTO,
    IMOS_AF_G722,
    IMOS_AF_LC_AAC,
    IMOS_AF_BUTT
}IMOS_AUDIO_FORMAT_E;

/* 音频编码采样率定义 */
typedef enum tagIMOSAudioSampling
{
    IMOS_AS_8000 = 0,
    IMOS_AS_16000,
    IMOS_AS_22050,
    IMOS_AS_24000,
    IMOS_AS_32000,
    IMOS_AS_44100,
    IMOS_AS_48000,
    IMOS_AS_96000,
    IMOS_AS_INVALID
}IMOS_AUDIO_SAMPLING_E;

/* OSD 颜色 */
typedef enum tagIMOSOsdColor
{
     IMOS_OC_WHITE  = 0,
     IMOS_OC_RED,
     IMOS_OC_YELLOW,
     IMOS_OC_BLUE,
     IMOS_OC_BLACK,
     IMOS_OC_GREEN,
     IMOS_OC_PURPLE,
     IMOS_OC_BUTT
}IMOS_OSD_COLOR_E;

/* OSD 透明度 */
typedef enum tagIMOSOsdAlpha
{
    IMOS_OA_HIDE = 0,                        /* 不透明 */
    IMOS_OA_HALF,                            /* 半透明 */
    IMOS_OA_SHOW,                            /* 全透明 */
    IMOS_OA_BUTT
}IMOS_OSD_ALPHA_E;

/* OSD日期显示格式 */
typedef enum tagIMOSDateFormat
{
    IMOS_DF_Y_M_D1 = 0,                      /* 0: XXXX-XX-XX 年月日 */
    IMOS_DF_M_D_Y1,                          /* 1: XX-XX-XXXX 月日年 */
    IMOS_DF_Y_M_D2,                          /* 2: XXXX年XX月XX日 */
    IMOS_DF_M_D_Y2,                          /* 3: XX月XX日XXXX年 */
    IMOS_DF_BUTT                             /* 无效格式 */
}IMOS_DATA_FORMAT_E;

/* OSD时间显示格式 */
typedef enum tagIMOSTimeFormat
{
    IMOS_TF_1 = 0,                           /* XX:XX:XX ，常见于中国，美国，英国等 */
    IMOS_TF_2,                               /* XX:XX:XX p.m. ，常见于除西班牙以外的西班牙语国家 */
    IMOS_TF_3,                               /* XX:XX:XX PM ,常见于除英国以外的英语国家 */
    IMOS_TF_4,                               /* PM XX:XX:XX ，见于中文(新加坡) */
    IMOS_TF_5,                               /* 下午 XX:XX:XX ，见于中文(台湾) */
    IMOS_TF_BUTT                             /* 无效格式 */
}IMOS_TIME_FORMAT_E;

/* 场名OSD 类型 */
typedef enum tagIMOSInfoOsdType
{
    IMOS_IOT_WORD = 0,                       /* 文字 */
    IMOS_IOT_PICTURE,                        /* 图片 */
    IMOS_IOT_BUTT
}IMOS_INFO_OSD_TYPE_E;

/* 告警类型 */
typedef enum tagIMOSAlarmType
{
    IMOS_AT_HIGH_TEMPERATURE = 0,            /* 高温告警 */
    IMOS_AT_HIGH_TEMPERATURE_RESUME,         /* 高温告警恢复 */
    IMOS_AT_LOW_TEMPERATURE = 2,             /* 低温告警 */
    IMOS_AT_LOW_TEMPERATURE_RESUME,          /* 低温告警恢复 */
    IMOS_AT_VIDEO_LOST = 4,                  /* 视频丢失告警 */
    IMOS_AT_VIDEO_LOST_RESUME,               /* 视频丢失告警恢复 */
    IMOS_AT_MOVE_DETECT = 6,                 /* 运动检测告警 */
    IMOS_AT_MOVE_DETECT_RESUME,              /* 运动检测告警恢复 */
    IMOS_AT_MASK_DETECT = 8,                 /* 遮挡侦测告警 */
    IMOS_AT_MASK_DETECT_RESUME,              /* 遮挡侦测告警恢复 */
    IMOS_AT_INPUT_SWITCH = 10,               /* 输入开关量告警 */
    IMOS_AT_INPUT_SWITCH_RESUME,             /* 输入开关量告警恢复 */
    IMOS_AT_CIRCUIT_DETECT = 12,             /* 开关量线路检测告警 */
    IMOS_AT_CIRCUIT_DETECT_RESUME,           /* 开关量线路检测告警恢复 */
    IMOS_AT_FAN_DETECT = 14,                 /* 风扇检测告警 */
    IMOS_AT_FAN_DETECT_RESUME,               /* 风扇检测告警恢复 */
    IMOS_AT_STOR_FAILED = 16,                /* 存储失败告警 */
    IMOS_AT_STOR_FAILED_RESUME,              /* 存储失败告警恢复 */
    IMOS_AT_BUTT
}IMOS_ALARM_TYPE_E;

/* 串口模式 */
typedef enum tagIMOSSerialMode
{
    IMOS_SE_PTZ = 1,                         /* 云台控制 */
    IMOS_SE_TRANS,                           /* 透明通道 */
    IMOS_SE_CONSOLE,                         /* 控制台 */
    IMOS_SE_PTZ_AND_TRANS,                   /* 云台控制和透明通道 */
    IMOS_SE_OSD,                            /* IPC 串口OSD 叠加 */
    IMOS_SE_VEHICLE_DETECTOR_S,        /*  车检器S  */
    IMOS_SE_RADAR_C,                   /*  雷达C,  */
    IMOS_SE_LASER,                     /*  激光 */
    IMOS_SE_CASEALARM,                 /*  机箱告警  */
    IMOS_SE_TRAFFICLIGHT,              /* 红绿灯 */
    IMOS_SE_RADAR_A,                   /*  雷达A */
    IMOS_SE_OSD_R,                      /* OSD叠加 */
    IMOS_SE_RADAR_H ,                  /*  雷达H */
    IMOS_SE_VEHICLE_DETECTOR_Q,        /* 车检器 Q  */
    IMOS_SE_RADAR_C_CONTROLLER,        /*  雷达C控制器  */
    IMOS_SE_VEHICLE_DETECTOR_H,        /* 车检器 H */
    IMOS_SE_KEYBOARD,                      /* 专业键盘*/
    IMOS_SE_UNIVERSAL,                     /* 通用串口,用来接收一般的串口协议,根据具体的串口协议类型解析,并进行相应的处理 ,同时能够向外部串口设备发送串口协议指令  */
    IMOS_SE_BUTT
}IMOS_SERIAL_MODE_E;

/* 开关量运行模式 */
typedef enum tagIMOSSwitchRunMode
{
    IMOS_SM_OPEN = 1,                        /* 常开 */
    IMOS_SM_CLOSE,                           /* 常闭 */
    IMOS_SM_BUTT
}IMOS_SIWTCH_RUNMODE_E;

/* 黑白模式 */
typedef enum tagBlackWhiteMode
{
    IMOS_BLACKWHITE_AUTO = 0,          /* 自动模式 */
    IMOS_BLACKWHITE_COLOR,             /* 永远彩色 */
    IMOS_BLACKWHITE_GRAY,              /* 永远黑白 */
    IMOS_BLACKWHITE_BUTT,
}IMOS_BLACKWHIT_MODE_E;

/* 快门时间 */
typedef enum tagShuuter
{
    IMOS_ESHUTTER_AUTO      = 0,       /* 快门时间为自动 */
    IMOS_ESHUTTER_4_SEC     = 4,       /* 1/4 快门时间 */
    IMOS_ESHUTTER_8_SEC     = 8,       /* 1/8 快门时间 */
    IMOS_ESHUTTER_15_SEC    = 15,      /* 1/15 快门时间 */
    IMOS_ESHUTTER_25_SEC    = 25,      /* 1/25 快门时间 */
    IMOS_ESHUTTER_30_SEC    = 30,      /* 1/30 快门时间 */
    IMOS_ESHUTTER_50_SEC    = 50,      /* 1/50 快门时间 */
    IMOS_ESHUTTER_60_SEC    = 60,      /* 1/60 快门时间 */
    IMOS_ESHUTTER_100_SEC   = 100,     /* 1/100 快门时间 */
    IMOS_ESHUTTER_120_SEC   = 120,     /* 1/120 快门时间 */
    IMOS_ESHUTTER_180_SEC   = 180,     /* 1/180 快门时间 */
    IMOS_ESHUTTER_200_SEC   = 200,     /* 1/200 快门时间 */
    IMOS_ESHUTTER_250_SEC   = 250,     /* 1/250 快门时间 */
    IMOS_ESHUTTER_500_SEC   = 500,     /* 1/500 快门时间 */
    IMOS_ESHUTTER_1000_SEC  = 1000,    /* 1/1000 快门时间 */
    IMOS_ESHUTTER_2000_SEC  = 2000,    /* 1/2000 快门时间 */
    IMOS_ESHUTTER_4000_SEC  = 4000,    /* 1/4000 快门时间 */
    IMOS_ESHUTTER_8000_SEC  = 8000,    /* 1/8000 快门时间 */
    IMOS_ESHUTTER_10000_SEC = 10000,   /* 1/10000 快门时间 */
    IMOS_ESHUTTER_BUTT,
}IMOS_SHUTTER_E;

/* 测光控制 */
typedef enum tagAEMetering
{
    IMOS_AEMETERING_CENTER = 0,        /* 中央权重 */
    IMOS_AEMETERING_SPOT,              /* 点测光权重 */
    IMOS_AEMETERING_BACKLIGHT,         /* 背光补偿 */
    IMOS_AEMETERING_BUTT,
}IMOS_AEMETERING_E;

/* 白平衡 */
typedef enum tagAWB
{
    IMOS_AWB_AUTO = 0,
    IMOS_AWB_TUNGSTEN,                 /* 日落模式 */
    IMOS_AWB_DAYLIGHT,                 /* 日光模式 */
    IMOS_AWB_CLOUDSHADY,               /* 阴天多云 */
    IMOS_AWB_FLUORESC1,                /* 荧光灯1，偏蓝 */
    IMOS_AWB_FLUORESC2,                /* 荧光灯2，偏不蓝 */
    IMOS_AWB_INDOOR = 6,               /* 室内 */
    IMOS_AWB_OUTDOOR = 7,              /* 室外 */
    IMOS_AWB_BUTT,
}IMOS_AWB_E;

/* 图像镜像 */
typedef enum MirrorType
{
    IMOS_MIRRORTYPE_NONE = 0,          /* 正常模式 */
    IMOS_MIRRORTYPE_COL,               /* 垂直翻转 */
    IMOS_MIRRORTYPE_ROW,               /* 水平翻转 */
    IMOS_MIRRORTYPE_ROW_COL,           /* 垂直水平翻转 */
    IMOS_MIRRORTYPE_BUTT,
}IMOS_MIRRORTYPE_E;

/* 背景频率 */
typedef enum tagFlickerMode
{
    IMOS_FLICKERMODE_OFF = 0,           /* 关闭 */
    IMOS_FLICKERMODE_50HZ,              /* 50HZ */
    IMOS_FLICKERMODE_60HZ,              /* 60HZ */
    IMOS_FLICKERMODE_BUTT,
}IMOS_FLICKER_MODE_E;

/* Begin add by f03368, 2016-10-26 for MPPD42015 */
/* TCP方向 */
typedef enum tagTCPMode
{
    IMOS_TCPMODE_PRETER = 0,          /* TCP方向: 未定义，保持现有的策略*/
    IMOS_TCPMODE_SERVER,              /* TCP方向: 服务端 */
    IMOS_TCPMODE_CLIENT,              /* TCP方向: 客户端 */
    IMOS_TCPMODE_BUTT,
}IMOS_TCP_MODE_E;

/*TCP类型*/
typedef enum tagTCPType
{
	IMOS_TCPTYPE_NO_TCP = 0,        /* TCP类型: 非TCP */
	IMOS_TCPTYPE_TCP,               /* TCP类型: tcp */
	IMOS_TCPTYPE_RFC4571,           /* TCP类型: TCP/RTP/AVP */
	IMOS_TCPTYPE_BUTT,
}IMOS_TCP_TYPE_E;
/* End add by f03368, 2016-10-26 for MPPD42015 */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_PRODUCT_DEF_H_ */

