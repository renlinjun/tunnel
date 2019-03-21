 /*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_player.h

  Project Code: IMOS通用媒体播放器
   Module Name: IMOS通用媒体播放器
  Date Created: 2010-07-12
        Author: shiyouhua/04562
   Description: IMOS通用媒体播放器XP接口头文件。XP：x-player通用播放器

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_PLAYER_H_
#define _IMOS_XP_PLAYER_H_

/* 包含IMOS基础平台的头文件 */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"

/* 包含通用媒体播放器SDK数据结构头文件 */
#include "xp_datatype.h"

#ifdef  __cplusplus
extern "C"{
#endif

/** 编译选项 */
#if defined(WIN32)
    #if defined(XP_PLAYER_DLL_EXPORTS)
        #define IMOS_XP_PLAYER_EXPORT  __declspec( dllexport )
    #else
        #define IMOS_XP_PLAYER_EXPORT  __declspec( dllimport )
    #endif
#else
    #define IMOS_XP_PLAYER_EXPORT
#endif

/** 厂商标识 */
#define XP_DECODERTAG_H3C_V1       "h3c-v1"          /**< H3C V1版本 */
#define XP_DECODERTAG_H3C_V3       "h3c-v3"          /**< H3C V3版本，TS封装流 */
#define XP_DECODERTAG_H3C_V3_20    "h3c-v3@20"       /**< H3C V3版本，RTP + TS */
#define XP_DECODERTAG_H3C_V3_31    "h3c-v3@31"       /**< H3C V3版本，RTP + ES */
#define XP_DECODERTAG_HIK_SELF     "hikvision-self"  /**< 海康SELF */
#define XP_DECODERTAG_HIK_V1       "hikvision-v1"    /**< 海康V1版本 */
#define XP_DECODERTAG_HIK_V3       "hikvision-v3"    /**< 海康V3版本 */
/* add by chenxiangyi 02451 2016/9/14 for MPPD40679 烽火对接 */
#define DECODERTAG_HIK_MEGA        "hikvision-mega"  /**< 海康全球眼 */
#define XP_DECODERTAG_DAHUA_SELF   "dahua-self"      /**< 大华SELF */
#define XP_DECODERTAG_DAHUA_V1     "dahua-v1"        /**< 大华V1版本 */
#define XP_DECODERTAG_DAHUA_V3     "dahua-v3"        /**< 大华V3版本 */
#define XP_DECODERTAG_AXIS_V4      "axis-v4"         /**< Axis 4.00版本(Firmware版本) */
#define XP_DECODERTAG_AXIS_V5      "axis-v5"         /**< Axis 5.00版本(Firmware版本) */
#define XP_DECODERTAG_ALEC         "alec"            /**< 艾立克 */
#define XP_DECODERTAG_MOBOTIX      "mobotix"         /**< mobotix */
#define XP_DECODERTAG_APROUD_ONU   "aproud-onu"      /**< 亚邦老系统 */
#define XP_DECODERTAG_APROUD_OEM   "aproud-sivx"     /**< 亚邦OEM系统 */
#define XP_DECODERTAG_YAAN_V3      "yaan-v3"         /**< 亚安 */
#define XP_DECODERTAG_SONY         "sony"            /**< 索尼 */
#define XP_DECODERTAG_SAMSUNG      "samsung"         /**< 三星 */
#define XP_DECODERTAG_RUIMING      "ruiming"         /**< 锐明V3版本 */
#define XP_DECODERTAG_RUIMING_SELF "ruiming-self"    /**< 锐明SELF */
#define XP_DECODERTAG_NANZI        "nanzi"           /**< 南自 */
#define XP_DECODERTAG_NANZI_SELF   "nanzi-self"      /**< 南自SELF */
#define XP_DECODETAG_TDY_SWALLOW   "TDY-SWALLOW"     /**< TDY */
#define XP_DECODETAG_TDY           "tiandy"          /**< 天地伟业 */
#define XP_DECODETAG_DMA_SWALLOW   "DMA-SWALLOW"     /**< DMA */
#define XP_DECODERTAG_AXIS         "axis"            /**< axis */

/* Begin added by yaojinhai01359, 2016-12-29 视频加扰 */
#define XP_SCRAMBLE_CAMERA_EXTERN_LEN         41
#define XP_SCRAMBLE_CAMERA_EXTERN_LEN_FILE        26
/**
* @enum tagXpScrambleModeType
* @brief 视频加扰模式
* @attention 无
*/
typedef enum tagXpScrambleModeType
{
	XP_SCRAMBLE_MODE_SIMPLE   = 0,               /**< 普通加密 */
	XP_SCRAMBLE_MODE_DIGITAL  = 1                /**< 数字加密 */
}XP_SCRAMBLE_MODE_TYPE;
/* End added by yaojinhai01359, 2016-12-29 视频加扰 */

/**
* @enum tagXpLogLevel
* @brief 运行日志等级枚举类型
* @attention 无
*/
typedef enum tagXpLogLevel
{
    XP_DEBUG = 1,               /**< debug级别 */
    XP_INFO  = 2,               /**< info级别 */
    XP_WARN  = 3,               /**< warn级别 */
    XP_ERROR = 4,               /**< error级别 */
    XP_FATAL = 5                /**< fatal级别 */
}XP_LOGLEVEL_E;

/**
* @enum tagMediaPlayerRunInfoType
* @brief 独立播放器上报运行信息的类型的枚举定义
* @attention 无
*/
typedef enum tagMediaPlayerRunInfoType
{
    XP_PLAYER_RUN_INFO_RECORD_VIDEO  = 0,          /**< 本地录像过程中上报运行信息 */
    XP_PLAYER_RUN_INFO_MEDIA_PROCESS = 1,          /**< 视频媒体处理过程中的上报运行信息 */
    XP_PLAYER_RUN_INFO_SERIES_SNATCH = 2,          /**< 连续抓拍过程中上报运行信息 */
    XP_PLAYER_RUN_INFO_MEDIA_VOICE = 3,            /**< 语音业务过程中上报运行信息 */
    XP_PLAYER_RUN_INFO_MEDIA_NOT_IDENTIFY = 4,     /**< 码流无法识别 */
    XP_PLAYER_RUN_INFO_RECV_PACKET_NUM = 5,        /**< 周期内接收到的包数 */
    XP_PLAYER_RUN_INFO_RECV_BYTE_NUM = 6,          /**< 周期内接收到的字节数 */
    XP_PLAYER_RUN_INFO_VIDEO_FRAME_NUM = 7,        /**< 周期内解析的视频帧数 */
    XP_PLAYER_RUN_INFO_AUDIO_FRAME_NUM = 8,        /**< 周期内解析的音频帧数 */
    XP_PLAYER_RUN_INFO_LOST_PACKET_RATIO = 9,      /**< 周期内丢包率统计信息（单位为0.01%） */
    XP_PLAYER_RUN_INFO_MEDIA_PLAY_PROGRESS = 10,   /**< 媒体中携带的进度信息 */
    XP_PLAYER_RUN_INFO_MEDIA_PLAY_END = 11,        /**< 媒体中携带的播放结束 */
    XP_PLAYER_RUN_INFO_MEDIA_ABNORMAL = 12         /**< 媒体处理异常 */
}XP_MEDIA_PLAYER_RUN_INFO_TYPE_E;

/**
* @struct tagRunInfo
* @brief 上报消息的结构体定义。
* @attention 无
*/
typedef struct tagPlayerRunInfo
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulErrCode;                            /**< 上报的错误码 */
}PLAYER_RUN_INFO_S;

/**
* @struct tagRunInfoEx
* @brief 上报消息的扩展结构体定义。
* @attention 无
*/
typedef struct tagPlayerRunInfoEx
{
    ULONG_32 ulPort;                              /**< 播放通道号 */
    ULONG_32 ulErrCode;                           /**< 上报的错误码 */
    CHAR szDescribe[IMOS_URL_LEN];            /*描述信息*/
}PLAYER_RUN_INFO_EX_S;

/**
* @struct tagPlayerRecvPktNum
* @brief 上报周期内接收包数消息的结构体定义。
* @attention 无
*/
typedef struct tagPlayerRecvPktNum
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulRecvPktNum;                         /**< 接收到的包数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}PLAYER_RECV_PACKET_NUM_S;

/**
* @struct tagPlayerRecvByteNum
* @brief 上报周期内接收字节数消息的结构体定义。
* @attention 无
*/
typedef struct tagPlayerRecvByteNum
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulRecvByteNum;                        /**< 接收到的字节数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}PLAYER_RECV_BYTE_NUM_S;

/**
* @struct tagPlayerVideoFrameNum
* @brief 上报周期内解析视频帧数消息的结构体定义。
* @attention 无
*/
typedef struct tagPlayerVideoFrameNum
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulVideoFrameNum;                      /**< 解析的视频帧数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}PLAYER_VIDEO_FRAME_NUM_S;

/**
* @struct tagPlayerAudioFrameNum
* @brief 上报周期内解析音频帧数消息的结构体定义。
* @attention 无
*/
typedef struct tagPlayerAudioFrameNum
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulAudioFrameNum;                      /**< 解析的音频帧数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}PLAYER_AUDIO_FRAME_NUM_S;

/**
* @struct tagPlayerLostPktRatio
* @brief 上报周期内丢包率消息的结构体定义。
* @attention 无
*/
typedef struct tagPlayerLostPktRatio
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulLostPktRatio;                       /**< 丢包率信息（单位为0.01%） */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}PLAYER_LOST_PAKCET_RATIO_S;

/**
* @struct tagPlayerMediaProgress
* @brief 上报媒体流中携带的进度信息。
* @attention 无
*/
typedef struct tagPlayerMediaProgress
{
    ULONG_32 ulPort;                               /**< 播放通道号 */
    ULONG_32 ulMediaProgress;                      /**< 进度信息（单位为秒） */
}PLAYER_MEDIA_PROGRESS_S;

/**
* 记录日志的回调函数类型定义 \n
* @param [IN] ulLogLevel        日志级别, 对应#XP_LOGLEVEL_E枚举中的值。
* @param [IN] ulErrCode         日志信息错误码。
* @param [IN] ulCmdModuleID     命令行模块ID。
* @param [IN] pcFileName        代码文件名。
* @param [IN] ulFileLine        代码所在行数。
* @param [IN] pcLogDescription  日志描述字符串。
* @return VOID
* @note
* -    1、播放器内部记录日志级别。
* -    2、播放器内部多线程调用该回调函数，用户记录日志处理中需要做线程同步处理。
* -    3、播放器内部输出的日志描述字符串末尾没有带"\r\n"符。用户在写日志文件的时候需要做换行处理。
*/
typedef VOID (STDCALL* XP_WRITE_LOG_CALLBACK_PF)(IN ULONG_32 ulLogLevel,
                                                 IN ULONG_32 ulErrCode,
                                                 IN ULONG_32 ulCmdModuleID,
                                                 IN const CHAR *pcFileName,
                                                 IN ULONG_32 ulFileLine,
                                                 IN const CHAR *pcLogDescription);

/**
* 消息或异常消息回调函数的指针类型。\n
* @param [IN] enRunInfoType 消息或者异常消息类型，对应#XP_MEDIA_PLAYER_RUN_INFO_TYPE_E枚举中的值。
* @param [IN] pParam        存放消息或异常消息数据的缓冲区指针（所存放的数据与消息或异常消息类型有关）
* @return VOID
* @note
* -     1、用户需要确保该回调函数尽快返回。
* -     2、用户不能在该回调函数中直接调用播放器SDK的任何接口函数。
* -     3、参数pParam所指的缓冲区中存放的数据的类型视消息或者异常消息类型而定，用户需要根据消息或者异常消息类型对其做类型转换。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_RECORD_VIDEO
                              #XP_PLAYER_RUN_INFO_MEDIA_PROCESS
                              #XP_PLAYER_RUN_INFO_SERIES_SNATCH
                              #XP_PLAYER_RUN_INFO_MEDIA_VOICE时，用户需将pParam转换为#PLAYER_RUN_INFO_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_MEDIA_NOT_IDENTIFY，用户需将pParam转换为#PLAYER_RUN_INFO_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_RECV_PACKET_NUM，用户需将pParam转换为#PLAYER_RECV_PACKET_NUM_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_VIDEO_FRAME_NUM，用户需将pParam转换为#PLAYER_VIDEO_FRAME_NUM_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_AUDIO_FRAME_NUM，用户需将pParam转换为#PLAYER_AUDIO_FRAME_NUM_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_RECV_BYTE_NUM，用户需将pParam转换为#PLAYER_RECV_BYTE_NUM_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_LOST_PACKET_RATIO，用户需将pParam转换为#PLAYER_LOST_PAKCET_RATIO_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_MEDIA_PLAY_PROGRESS，用户需将pParam转换为#PLAYER_MEDIA_PROGRESS_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_MEDIA_PLAY_END，用户需将pParam转换为#PLAYER_MEDIA_PROGRESS_S结构体类型指针。
* -        当ulRunInfoType值为#XP_PLAYER_RUN_INFO_MEDIA_ABNORMAL，用户需将pParam转换为#PLAYER_RUN_INFO_S结构体类型指针。
*/
typedef VOID (STDCALL* XP_PLAYER_RUN_INFO_CALLBACK_PF)(IN ULONG_32 ulRunInfoType,
                                                       IN VOID *pParam);

/**
* 拼帧前媒体流数据回调函数的指针类型。\n
* @param [IN] ulPort           播放通道号
* @param [IN] pucBuffer        存放拼帧前媒体流数据缓冲区指针
* @param [IN] ulBufSize        缓冲区大小
* @param [IN] ulMediaDataType  媒体数据类型，参见媒体类型枚举定义#XP_MEDIA_DATA_FORMAT_E
* @param [IN] lUserParam       用户设置参数，即用户在调用#IMOS_XP_SetSourceMediaDataCB函数时指定的用户参数
* @param [IN] lReserved        存放拼帧前媒体流扩展信息缓冲区指针，用户需要转换为#XP_SOURCE_DATA_EX_INFO_S
*                              结构体指针类型，内含解码器标签（DecoderTag），当用户使用播放库解码和显示回调
*                              的媒体流时，可根据解码器标签指定解码器。
* @return 无。
* @note  用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_PLAYER_SOURCE_MEDIA_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                                IN const UCHAR *pucBuffer,
                                                                IN ULONG_32 ulBufSize,
                                                                IN ULONG_32 ulMediaDataType,
                                                                IN LONG_REAL lUserParam,
                                                                IN LONG_REAL lReserved);

/**
* 拼帧后视频流数据回调函数的指针类型。\n
* @param [IN] ulPort                播放通道号
* @param [IN] pstParseVideoData     存放拼帧后视频流数据信息缓冲区指针
* @param [IN] lUserParam            用户设置参数，即用户在调用#IMOS_XP_SetParseVideoDataCB函数时指定的用户参数
* @param [IN] lReserved             保留参数
* @return 无。
* @note
* -     用户应及时处理输出的数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL *XP_PLAYER_PARSE_VIDEO_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                               IN const XP_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                               IN LONG_REAL lUserParam,
                                                               IN LONG_REAL lReserved);

/**
* 拼帧后音频流数据回调函数的指针类型。\n
* @param [IN] ulPort                播放通道号
* @param [IN] pstParseAudioData     存放拼帧后音频流数据信息缓冲区指针
* @param [IN] lUserParam            用户设置参数，即用户在调用#IMOS_XP_SetParseAudioDataCB函数时指定的用户参数
* @param [IN] lReserved             保留参数
* @return 无。
* @note
* -     用户应及时处理输出的数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL *XP_PLAYER_PARSE_AUDIO_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                               IN const XP_PARSE_AUDIO_DATA_S *pstParseAudioData,
                                                               IN LONG_REAL lUserParam,
                                                               IN LONG_REAL lReserved);

/**
* 解码后视频流数据回调函数的指针类型。\n
* @param [IN] ulPort         播放通道号
* @param [IN] pPictureData   存放解码后视频流数据信息缓冲区指针
* @param [IN] lUserParam     用户设置参数，即用户在调用#IMOS_XP_SetDecodeVideoDataCB函数时指定的用户参数
* @param [IN] lReserved      保留参数
* @return 无。
* @note
* -     1、用户应及时处理输出的视频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
* -     2、视频数据是yv12格式。排列顺序“Y0-Y1-......”，“U0-U1-......”，“V0-V1-......”
*/
typedef VOID (STDCALL* XP_PLAYER_DECODE_VIDEO_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                                IN const XP_PICTURE_DATA_S *pPictureData,
                                                                IN LONG_REAL lUserParam,
                                                                IN LONG_REAL lReserved);

/**
* 解码后音频流数据回调函数的指针类型。\n
* @param [IN] ulPort         播放通道号
* @param [IN] pWaveData      存放解码后音频流数据信息缓冲区指针
* @param [IN] lUserParam     用户设置参数，即用户在调用#IMOS_XP_SetDecodeAudioDataCB函数时指定的用户参数
* @param [IN] lReserved      保留参数
* @return 无。
* @note
* -     用户应及时处理输出的音频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_PLAYER_DECODE_AUDIO_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                                IN const XP_WAVE_DATA_S *pWaveData,
                                                                IN LONG_REAL lUserParam,
                                                                IN LONG_REAL lReserved);

/**
* 数据回调函数的指针类型。\n
* @param [IN] ulPort                播放通道号
* @param [IN] pBuffer               存放媒体流数据缓冲区指针。
* @param [IN] ulBufSize             缓冲区大小。
* @param [IN] lUserParam            用户设置参数
* @param [IN] lReserved1            保留参数1
* @param [IN] lReserved2            保留参数2
* @return 无。
* @note
* -     用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_PLAYER_MEDIA_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                         IN const UCHAR *pBuffer,
                                                         IN ULONG_32 ulBufSize,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved1,
                                                         IN LONG_REAL lReserved2);
/**
* 用于语音对讲解析后的语音数据回调函数的指针类型。\n
* @param [IN] ulPort                播放通道号
* @param [IN] pucVoiceDataBuffer    存放解析后语音数据信息缓冲区指针
* @param [IN] ulBufSize             音频数据大小
* @param [IN] ulAudioFlag           音频数据类型,需从#XP_AUDIO_FLAG_E枚举中取值
* @param [IN] pUserParam            用户设置参数
* @return 无。
* @note
* -     用户应及时处理输出的数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL *XP_PLAYER_PARSE_VOICE_DATA_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                               IN const UCHAR *pucVoiceDataBuffer,
                                                               IN ULONG_32 ulBufSize,
                                                               IN ULONG_32 ulAudioFlag,
                                                               IN LONG_REAL lUserParam);


/**
* DDraw表面hdc回调函数的指针类型。\n
* @param [IN] ulPort         播放通道号
* @param [IN] pHDC           存放ddraw表面DC句柄的指针
* @param [IN] lUserParam     用户设置参数，即用户在调用#IMOS_XP_SetDisplayHdcCB函数时指定的用户参数
* @param [IN] lReserved      保留参数
* @return 无。
* @note
* -     用户应及时处理输出的设备环境，确保函数尽快返回，否则会影响播放器内的媒体流处理。
* -     该回调函数仅限于普通品质和低品质时使用。
* -     若锁屏等情况下，可能导致HDC丢失，使用时请判断pHDC是否为NULL。
* -     使用时可将pHDC按照(HDC) (*(HDC* )pHDC)转化为HDC使用。
*/
#ifndef _WIN64
typedef VOID (STDCALL* XP_PLAYER_HDC_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                   IN const VOID *pHDC,
                                                   IN LONG_REAL lUserParam,
                                                   IN LONG_REAL lReserved);
#else
typedef VOID (STDCALL* XP_PLAYER_HDC_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                  IN const VOID *pHDC,
                                                  IN LONG_REAL lUserParam,
                                                  IN LONG_REAL lReserved);
#endif

/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */
/**
* 点播回放时间输出回调函数。\n
* @param [IN] ulChannel        播放通道号
* @param [IN] lUserParam       用户设置参数
* @param [IN] lReserved        保留参数
* @param [OUT] pszTime          存放点播回放时间数据的缓冲区指针
* @return 无。
*/
typedef VOID (STDCALL* XP_PLAYER_GET_VODTIME_CALLBACK_PF)(IN ULONG_32 ulChannelID,
                                                          IN LONG_REAL lUserParam,
                                                          IN LONG_REAL lReserved,
                                                          OUT CHAR *pszTime
                                                          );
/* End: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */
/**
* 获取当前下载进度输出回调函数。\n
* @param [IN] ulChannel        播放通道号
* @param [IN] lUserParam       用户设置参数
* @param [IN] lReserved        保留参数
* @param [OUT] pszTime          存放当前下载进度时间数据的缓冲区指针, 缓冲区长度应不小于IMOS_TIME_LEN(32).
* @return 无。
*/
typedef VOID (STDCALL* XP_PLAYER_GET_CURDOWNPOS_CALLBACK_PF)(IN ULONG_32 ulChannel,
                                                             IN LONG_REAL lUserParam,
                                                             IN LONG_32 lReserved,
                                                             OUT CHAR *pszTime
                                                             );
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */



/**
* @struct tagParseVoiceDataCBInfo
* @brief 语音数据回调函数相关信息，用于缓存。
* @attention 无
*/
typedef struct tagParseVoiceDataCBInfo
{
    XP_PLAYER_PARSE_VOICE_DATA_CALLBACK_PF pfnParseVoiceDataCBFun;
    BOOL_T bContinue;
    LONG_REAL lUserParam;
} PARSE_VOICE_DATA_CB_INFO_S;

/* 未公开接口包含 */
#include "xp_player_inner.h"

/**
* 注册播放器内运行日志的回调函数。\n
* @param [IN] pfnWriteLogFunc 播放器内运行日志回调函数指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -    1、为了防止日志信息记录遗漏，用户应在调用播放器其他接口函数之前调用该函数；
* -    2、如果用户不调用该函数设置运行日志的回调函数，则播放器内部不记录任何日志信息；
* -    3、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetWriteLogCB(IN XP_WRITE_LOG_CALLBACK_PF pfnWriteLogFunc);

/**
* 设置播放器库所在的根目录路径。\n
* @param [IN] pcRootPath 播放器库所在的根目录路径。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -    1、该接口需要在#IMOS_XP_Init之前调用；
* -    2、如果用户不调用该函数设置播放器库所在的根目录路径，则播放器内部默认采用当前应用程序的运行路径；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPlayerRootPath(IN const CHAR *pcRootPath);

/**
* 初始化播放器SDK资源。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_XP_FAIL_TO_INIT_XP          初始化播放器资源失败
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_Init();

/**
* 释放播放器SDK资源，在结束使用播放器SDK之前最后调用。\n
* @param [IN] 无。
* @return 无
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_Cleanup();

/**
* 注册消息或异常消息回调函数。\n
* @param [IN] pfRunInfoFunc 消息或异常消息回调函数指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -    1、不允许在设置给播放器库的回调函数中调用播放器库接口；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPlayerRunMsgCB(IN XP_PLAYER_RUN_INFO_CALLBACK_PF pfnRunInfoFunc);

/* Begin: Add by chenxiangyi w1099, 2014/10/27, MPPD16039 录像下载完成，界面仍显示99% */
/**
* 注册消息或异常消息回调函数。\n
* @param [IN] pfRunInfoFunc 消息或异常消息回调函数指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -    1、不允许在设置给播放器库的回调函数中调用播放器库接口；
* -    2、该接口函数支持Windows和Linux。
* -    3、调用该接口重复设置回调函数时，不会覆盖先前设置的回调函数。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPlayerMultiRunMsgCB(IN XP_PLAYER_RUN_INFO_CALLBACK_PF pfnRunInfoFunc);
/* End: Add by chenxiangyi w1099, 2014/10/27, MPPD16039 录像下载完成，界面仍显示99% */


/* Begin: Add by chenxiangyi w1099, 2014/10/29, MPPD18550: 实现不同模块调用XP消息回调函数的删除 */
/**
* 释放回调函数。\n
* @param [IN] pfRunInfoFunc 消息或异常消息回调函数指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -    1、不允许在设置给播放器库的回调函数中调用播放器库接口；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_DelPlayerMultiRunMsgCB(IN XP_PLAYER_RUN_INFO_CALLBACK_PF pfnRunInfoFunc);
/* End: Add by chenxiangyi w1099, 2014/10/29, MPPD18550: 实现不同模块调用XP消息回调函数的删除 */


/**
* 设置视频显示模式。\n
* @param [IN] ulRenderMode 视频显示模式，需从#XP_RENDER_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -  1、该接口在IMOS_XP_Init之后调用，设置的视频显示模式将对所有播放通道起作用；
* -  2、如果客户不调用该函数设置视频显示模式，则播放器内部默认使用D3D的显示模式；
* -  3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRenderMode(IN ULONG_32 ulRenderMode);

/**
* 设置视频像素格式。\n
* @param [IN] ulPixelFormat 视频像素格式，需从#XP_PIXEL_FORMAT_EX_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* -  1、该接口在IMOS_XP_Init之后调用，设置的视频像素格式将对所有播放通道起作用；
* -  2、如果客户不调用该函数设置视频像素格式，则播放器内部默认使用YUV420视频像素格式；
* -  3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPixelFormat(IN ULONG_32 ulPixelFormat);

/**
* 打开本地播放文件。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcFileName    本地文件的文件名（包括文件路径）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可用
* -         #ERR_COMMON_NO_MEMORY                系统内存不足
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道的资源失败
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      文件播放格式不支持
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       获得文件总的播放时间失败
* -         #ERR_XP_FAIL_TO_OPEN_FILE            启动本地文件播放失败(文件不存在或者正在被其他程序使用)
* -         #ERR_XP_FILE_DESTROY                 需要打开的文件太小或者已经损坏
* -         #ERR_XP_FILE_HAVE_OPEN               指定通道已经打开了文件
* @note
* -    1、启动文件播放后，在播放过程中，播放器通过#IMOS_XP_SetPlayerRunMsgCB设置的回调函数上报消息#XP_PLAYER_RUN_INFO_MEDIA_PROCESS；携带的错误码：
* -     #ERR_COMMON_NO_MEMORY               上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FINISH_PLAY_FILE            上报消息之前，播放器暂停对应通道的播放
* -     #ERR_XP_FILE_DESTROY                上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_RECV_DATA           上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  上报消息之前，播放器停止对应通道的播放
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OpenFile(IN ULONG_32 ulPort,
                                                     IN const CHAR *pcFileName);

/**
* 获得文件总的时间长度。\n
* @param [IN] ulPort        播放通道号。
* @param [OUT] pulTotalTime 存放文件总的时间长度的指针（单位为秒）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetFileTime(IN ULONG_32 ulPort,
                                                        OUT ULONG_32 *pulTotalTime);

/**
* 关闭本地播放文件。\n
* @param [IN] ulPort        播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_CLOSE_FILE           关闭本地文件回放业务失败
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CloseFile(IN ULONG_32 ulPort);

/**
* 打开网络流数据播放。\n
* @param [IN] ulPort          播放通道号。
* @param [IN] pcLocalIP       本地IP地址。
* @param [IN] usLocalPort     本地监听端口。
* @param [IN] pcRemoteIP      远端IP地址。
* @param [IN] usRemotePort    远端端口。
* @param [IN] ulTransProtl    接收媒体流的传输层协议，需从#XP_PROTOCOL_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_AVAILABLE       播放通道不可用
* -         #ERR_COMMON_NO_MEMORY            系统内存不足
* -         #ERR_XP_FAIL_TO_OPEN_STREAM      启动媒体流播放业务失败
* @note
* -    1、目前仅支持UDP协议接收媒体数据流；
* -    2、该函数支持单播和组播两种方式。单播时，如果使用本地默认的IP地址，则本地IP地址传入空字符串即可，
* -       此时，远端的IP地址和端口可用于对接收到的数据包进行校验、过滤，防止串流，如果用户不需要防止串流，
* -       则可将远端IP地址和端口分别填写为“0.0.0.0”和0；组播时，远端的IP地址和端口必须填写组播地址和端口，
* -       此时，本地IP地址也必须要填写一个真实有效的本地IP地址，而本地端口可以填写任意值(不使用)；
* -    3、启动网络流播放后，在播放过程中，播放器通过#IMOS_XP_SetPlayerRunMsgCB设置的回调函数上报消息#XP_PLAYER_RUN_INFO_MEDIA_PROCESS；携带的错误码：
* -     #ERR_COMMON_NO_MEMORY               上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_RECV_DATA           上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  上报消息之前，播放器停止对应通道的播放
* -    4、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OpenNetStream(IN ULONG_32 ulPort,
                                                          IN const CHAR *pcLocalIP,
                                                          IN USHORT usLocalPort,
                                                          IN const CHAR *pcRemoteIP,
                                                          IN USHORT usRemotePort,
                                                          IN ULONG_32 ulTransProtl);

/**
* 关闭网络流数据播放。\n
* @param [IN] ulPort       播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_CLOSE_STREAM         关闭媒体流播放失败
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CloseNetStream(IN ULONG_32 ulPort);

/**
* 打开输入流数据播放。\n
* @param [IN] ulPort           播放通道号。
* @param [IN] pucFileHeadBuf   文件头数据。
* @param [IN] ulSize           文件头长度。
* @param [IN] ulBufPoolSize    设置播放器中存放媒体数据流的缓冲区大小。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_PORT_NOT_AVAILABLE               播放通道不可用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_COMMON_NO_MEMORY                    系统内存不足
* -         #ERR_XP_FAIL_TO_OPEN_STREAM              启动输入流播放业务失败
* @note
* -    1、该接口函数支持Windows和Linux。
* -    2、启动输入流播放后，在播放过程中，播放器通过#IMOS_XP_SetPlayerRunMsgCB设置的回调函数上报消息#XP_PLAYER_RUN_INFO_MEDIA_PROCESS；携带的错误码：
* -     #ERR_COMMON_NO_MEMORY               上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_RECV_DATA           上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  上报消息之前，播放器停止对应通道的播放
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OpenInputStream(IN ULONG_32 ulPort,
                                                            IN const UCHAR *pucFileHeadBuf,
                                                            IN ULONG_32 ulSize,
                                                            IN ULONG_32 ulBufPoolSize);

/**
* 输入流数据；打开输入流后才能输入数据。\n
* @param [IN] ulPort          播放通道号。
* @param [IN] pucDataBuf      流数据缓冲区地址。
* @param [IN] ulDataLen       流数据缓冲区长度。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_OPEN                    通道未打开媒体业务
* -         #ERR_COMMON_NO_MEMORY                    系统内存不足
* -         #ERR_XP_FAIL_TO_INPUT_DATA               码流输入失败
* -         #ERR_XP_INPUTDATA_BUFFER_FULL            缓冲区满，码流输入失败
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_InputMediaData(IN ULONG_32 ulPort,
                                                           IN const UCHAR *pucDataBuf,
                                                           IN ULONG_32 ulDataLen);

/**
* 关闭输入流数据播放。\n
* @param [IN] ulPort    播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_CLOSE_STREAM             关闭媒体流播放失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CloseInputStream(IN ULONG_32 ulPort);

/**
* 设置播放图像流畅性或实时性。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] ulFluency     播放图像是实时性优先还是流畅性优先，需从#XP_PICTURE_FLUENCY_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES           获得播放通道资源失败
* @note
* -    1、该函数用于设置网络流和输入流播放时图像的流畅性，对本地文件回放时图像进行设置将不起作用；
*         且需要在#IMOS_XP_StartPlay之前调用，设置仅对指定通道有效；
* -    2、如果用户不调用该函数设置播放图像流畅性，则播放器内部默认使用图像实时性优先；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPictureFluency(IN ULONG_32 ulPort,
                                                              IN ULONG_32 ulFluency);

/**
* 设置拼帧前媒体流数据回调函数。\n
* @param [IN] ulPort                  播放通道号。
* @param [IN] pfnSourceMediaDataCBFun 拼帧前媒体流数据回调函数的指针。
* @param [IN] bContinue               是否继续进行后面的拼帧、解码和显示操作。
* @param [IN] lUserParam              用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* -     1、该函数在#IMOS_XP_StartPlay之前或之后调用，在#IMOS_XP_StopPlay时自动失效；
* -     2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
* -     3、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetSourceMediaDataCB(IN ULONG_32 ulPort,
                                                                 IN XP_PLAYER_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                                 IN BOOL_T bContinue,
                                                                 IN LONG_REAL lUserParam);

/**
* 设置拼帧后视频数据回调函数。\n
* @param [IN] ulPort                    播放通道号。
* @param [IN] pfnParseVideoDataCBFun    拼帧后视频数据回调函数的指针。
* @param [IN] bContinue                 是否继续进行解码和显示操作。
* @param [IN] lUserParam                用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* -    1、该函数在#IMOS_XP_StartPlay之前或之后调用，在#IMOS_XP_StopPlay时自动失效；
* -    2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
* -    3、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetParseVideoDataCB(IN ULONG_32 ulPort,
                                                                IN XP_PLAYER_PARSE_VIDEO_DATA_CALLBACK_PF pfnParseVideoDataCBFun,
                                                                IN BOOL_T bContinue,
                                                                IN LONG_REAL lUserParam);

/**
* 设置拼帧后音频数据回调函数。\n
* @param [IN] ulPort                    播放通道号。
* @param [IN] pfnParseAudioDataCBFun    拼帧后音频数据回调函数的指针。
* @param [IN] bContinue                 是否继续进行解码和播放操作。
* @param [IN] lUserParam                用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* -    1、该函数在#IMOS_XP_StartPlay之前或之后调用，在#IMOS_XP_StopPlay时自动失效；
* -    2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetParseAudioDataCB(IN ULONG_32 ulPort,
                                                                IN XP_PLAYER_PARSE_AUDIO_DATA_CALLBACK_PF pfnParseAudioDataCBFun,
                                                                IN BOOL_T bContinue,
                                                                IN LONG_REAL lUserParam);

/**
* 设置解码后视频媒体流数据回调函数。\n
* @param [IN] ulPort                    播放通道号。
* @param [IN] pfnDecodeVideoDataCBFun   解码后视频媒体流数据回调函数的指针。
* @param [IN] bContinue                 是否继续进行后面的显示操作。
* @param [IN] lUserParam                用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* -    1、该函数在#IMOS_XP_StartPlay之前或之后调用，在#IMOS_XP_StopPlay时自动失效；
* -    2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
* -    3、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDecodeVideoMediaDataCB(IN ULONG_32 ulPort,
                                                                      IN XP_PLAYER_DECODE_VIDEO_DATA_CALLBACK_PF pfnDecodeVideoDataCBFun,
                                                                      IN BOOL_T bContinue,
                                                                      IN LONG_REAL lUserParam);

/**
* 设置解码后音频媒体流数据回调函数。\n
* @param [IN] ulPort                    播放通道号。
* @param [IN] pfnDecodeAudioDataCBFun   解码后音频媒体流数据回调函数的指针。
* @param [IN] bContinue                 是否继续进行后面的播放操作。
* @param [IN] lUserParam                用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* -    1、该函数在#IMOS_XP_StartPlay之前或之后调用，在#IMOS_XP_StopPlay时自动失效；
* -    2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDecodeAudioMediaDataCB(IN ULONG_32 ulPort,
                                                                      IN XP_PLAYER_DECODE_AUDIO_DATA_CALLBACK_PF pfnDecodeAudioDataCBFun,
                                                                      IN BOOL_T bContinue,
                                                                      IN LONG_REAL lUserParam);

/**
* 设置通道解码器的厂商标识。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcDecoderTag  通道解码器的厂商标识，需从XP_DECODERTAG_XXXX一类的宏定义中取值。如XP_DECODERTAG_H3C_V3
*                           是H3C V3版本的标识，设置了该标识的播放通道将使用H3C V3版本的解码器。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放窗口的资源失败
* @note
* -    1、如果用户没有调用该函数设置指定通道解码器的厂商标识，则该通道默认使用H3C V3（TS封装流）的解码器；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDecoderTag(IN ULONG_32 ulPort,
                                                          IN const CHAR *pcDecoderTag);

/**
* 获得通道解码器的厂商标识。\n
* @param [IN] ulPort         播放通道号。
* @param [OUT] pcDecoderTag  通道解码器的厂商标识，长度为#IMOS_STRING_LEN_32
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放窗口的资源失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetDecoderTag(IN ULONG_32 ulPort,
                                                          OUT CHAR *pcDecoderTag);

/**
* 设置播放视频的窗口句柄。\n
* @param [IN] ulPort    播放通道号。
* @param [IN] hWnd      播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPlayWnd(IN ULONG_32 ulPort,
                                                       IN IMOS_HANDLE hWnd);

/**
* 开始播放。\n
* @param [IN] ulPort    播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_COMMON_NO_MEMORY                系统内存不足
* -         #ERR_XP_PORT_NOT_OPEN                通道未打开媒体业务
* -         #ERR_XP_FAIL_TO_START_PLAY           开始播放失败
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartPlay(IN ULONG_32 ulPort);

/**
* 暂停播放。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          暂停媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PAUSE                暂停播放操作失败
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_PausePlay(IN ULONG_32 ulPort);

/**
* 恢复播放，恢复播放已暂停的通道。\n
* @param [IN] ulPort    播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         恢复媒体播放处理失败
* -         #ERR_XP_FAIL_TO_RESUME               恢复播放操作失败
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ResumePlay(IN ULONG_32 ulPort);

/**
* 根据时间设置文件播放位置。\n
* @param [IN] ulPort      播放通道号。
* @param [IN] ulTime      跳转目的时间（单位为秒）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            跳转播放失败
* @note
* -    1、如果当前正在本地录像，不支持根据时间设置文件播放位置操作；
* -    2、该函数只适用于本地文件回放时根据时间设置其播放位置；
* -    3、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPlayedTime(IN ULONG_32 ulPort,
                                                          IN ULONG_32 ulTime);

/**
* 获得文件当前播放时间。\n
* @param [IN]  ulPort       播放通道号。
* @param [OUT] pulTime      存放当前播放进度时间的指针（单位为秒）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    获得当前播放进度失败
* @note
* -    1、该函数只适用于本地文件回放时获得其当前播放时间；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetPlayedTime(IN ULONG_32 ulPort,
                                                          OUT ULONG_32 *pulTime);

/**
* 设置播放速度。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] ulPlaySpeed   播放速度，需从#XP_PLAY_STATUS_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY   倍速前进/后退播放失败
* @note
* -    1、正在本地录像时，不支持倍速前进/后退播放操作；
* -    2、本地文件播放不支持后退播放；
* -    3、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPlaySpeed(IN ULONG_32 ulPort,
                                                         IN ULONG_32 ulPlaySpeed);

/**
* 单帧前进播放。\n
* @param [IN] ulPort   播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧播放失败
* @note
* -    1、正在本地录像时，不支持单帧播放操作；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OneByOne(IN ULONG_32 ulPort);

/**
* 清空所有缓冲区的剩余数据。\n
* @param [IN] ulPort        播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_RESET_BUFFER         清空缓冲区失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ResetBuf(IN ULONG_32 ulPort);

/**
* 停止播放。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_PLAY            停止播放操作失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopPlay(IN ULONG_32 ulPort);

/**
* 独占方式打开声音。\n
* @param [IN] ulPort   通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                   通道未开始播放操作
* -         #ERR_XP_DECODE_AUDIO_NOT_CONTINUE        音频流数据解码后不继续进行播放操作
* -         #ERR_XP_FAIL_TO_PLAY_SOUND               打开声音失败
* @note
* -    1、同一时刻只能播放一路声音，如果现在已经有声音打开，则自动关闭原来已经打开的声音。
* -       默认情况下声音是关闭的。
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_PlaySound(IN ULONG_32 ulPort);

/**
* 关闭声音。\n
* @param [IN] ulPort    通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                   通道未开始播放操作
* -         #ERR_XP_FAIL_TO_STOP_SOUND               关闭声音失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopSound(IN ULONG_32 ulPort);

/**
* 音量调节。\n
* @param [IN] ulVolume  音量值（范围从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVolume(IN ULONG_32 ulVolume);

/**
* 获得当前设置的音量值。\n
* @param [OUT] pulVolume    存放音量值的指针（范围从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_GET_VOLUME       获得音量值失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetVolume(OUT ULONG_32 *pulVolume);

/**
* 调整所有通道音频数据的WAVE波形，可以改变所有通道播放声音的大小。\n
* @param [IN] ulCoefficient 调整的参数（范围从0到255，255为最大调整参数值）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* -    1、此函数和#IMOS_XP_SetVolume函数的不同之处在于，它是调整播放器所有通道声音数据的WAVE波形，对所有通道起作用；
          #IMOS_XP_SetVolume是调整声卡音量，对整个操作系统起作用；
* -    2、如果用户不调用该函数调整所有通道音频数据的WAVE波形，则采用默认的调整参数值146；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_AdjustAllWaveAudio(IN ULONG_32 ulCoefficient);

/**
* 设置指定播放通道的视频图像显示比例。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] ulRenderScale     视频图像在播放通道上的显示比例，需从#XP_RENDER_SCALE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_RENDER_SCALE        设置图像显示比例参数失败
* @note
* -    1、在不调用该接口的情况下，视频图像默认填充整个播放窗格；
* -    2、在启动播放之前调用该接口时，则设置的显示比例参数在后续启动该播放通道播放时生效；
* -    3、在播放过程中调用该接口时，则设置的显示比例参数实时生效；
* -    4、调用该接口对指定播放通道设置的显示比例参数在播放器运行期间一直有效；
* -    5、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRenderScale(IN ULONG_32 ulPort,
                                                           IN ULONG_32 ulRenderScale);

/**
* 设置图象的对比度参数，即时起作用。\n
* @param [IN] ulPort             播放通道号。
* @param [IN] ulContrastMode     图象对比度模式，需从#XP_PICTURE_CONTRAST_MODE_E枚举中取值。
* @param [IN] ulContrastLevel    图象对比度级别，需从#XP_PICTURE_CONTRAST_LEVEL_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST 播放通道不支持设置图象对比度参数
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     设置图象对比度失败
* @note
* -    1、在不调用该接口的情况下，视频图像默认不进行对比度调节处理；
* -    2、可以在开始播放#IMOS_XP_StartPlay之前设置，但设置的对比度参数被保存，作为启动该通道播放时
* -       的初始值；在开始播放后调用该接口设置的对比度参数即时生效；
* -    3、调用该接口对指定播放通道设置的对比参数在播放器运行期间一直有效；当参数ulContrastMode
* -       传入#XP_PICTURE_CONTRAST_MODE_NONE时，即停止对比度调节处理，此时ulContrastLevel参数传
* -       入的值将无效；
* -    4、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPictureContrast(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulContrastMode,
                                                               IN ULONG_32 ulContrastLevel);

/**
* 设置图象质量。\n
* @param [IN] ulPort             播放通道号。
* @param [IN] enPictureQuality     图象质量
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetPictureQuality(IN ULONG_32 ulPort,
                                                       IN JPG_PICTURE_QUALITY_LEVEL_E enJpgPictureQualityLevel);


/**
* 设置解码场模式。\n
* @param [IN] ulPort      播放通道号。
* @param [IN] ulFieldMode 场模式，需从#XP_FIELD_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_SET_FIELD_MODE       设置解码场模式失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后调用；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetFieldMode(IN ULONG_32 ulPort,
                                                         IN ULONG_32 ulFieldMode);

/**
* 设置去交织处理模式。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] ulDeinterlaceMode 去交织处理模式，需从#XP_DEINTERLACE_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                   通道未启动播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC            播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_ENABLE_DEINTERLACE       启动或关闭去交织处理失败
* @note
* -    1、如果用户不调用该函数设置去交织处理模式，则播放器内部默认使用混合模式启动去交织处理；
* -    2、该函数需要在#IMOS_XP_StartPlay之后调用；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDeinterlaceMode(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulDeinterlaceMode);

/**
* 单次实时抓拍。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcFileName        保存图像的文件路径，包括文件名（不带后缀名）。
* @param [IN] ulPicFormat       图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [OUT] pcFilePostfix    存放图像文件后缀的指针，缓冲区长度应不小于#IMOS_XP_FILE_POSTFIX_LEN。
*                               如果用户不需要返回后缀名，可将该参数设置为NULL。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         没有解码过的图片可供抓拍
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          单次抓拍操作失败
* @note
* -    1、播放器将根据图像格式在文件名后面追加对应的后缀名。如BMP图像文件的后缀为.bmp；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SnatchOnce(IN ULONG_32 ulPort,
                                                       IN const CHAR *pcFileName,
                                                       IN ULONG_32 ulPicFormat,
                                                       OUT CHAR *pcFilePostfix);



/**
* 设置录像质量参数。\n
* @param [IN] ulPort                 播放通道号。
* @param [IN] ulRecordQuality        录像质量参数，需从#XP_RECORD_QUALITY_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* @note
* -    1、录像质量参数设置为#XP_RECORD_PRIORITY时，录像处理优先；设置为#XP_PLAY_PRIORITY时，播放处理优先，即录像可能会丢弃数据；
* -    2、不调用该接口时，播放器内部默认为#XP_PLAY_PRIORITY；
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRecordQuality(IN ULONG_32 ulPort,
                                                             IN ULONG_32 ulRecordQuality);

/**
* 开始本地录像。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcFileName        录像文件存放路径，包括文件名（不带后缀名）。
* @param [IN] ulMediaFileFormat 录像文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
* @param [OUT] pcFilePostfix    存放录像文件后缀的指针，缓冲区长度应不小于#IMOS_XP_FILE_POSTFIX_LEN。
*                               如果用户不需要返回后缀名，可将该参数设置为NULL。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_COMMON_INVALID_PARAM                    输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                       通道未开始播放操作
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           指定的播放通道已经启动录像操作
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      录像格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             硬盘空间不足
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 当前正处于暂停播放状态
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         当前正处于倍速播放状态
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  当前正处于单帧播放状态
* -         #ERR_XP_NOT_SUPPORT                          不支持该功能
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           启动本地录像失败
* @note
* -    1、播放器将根据媒体流格式在文件名后面追加对应的后缀名。如TS流录像文件的后缀为.ts；
* -    2、当播放处于暂停播放、快速播放、慢速播放或单帧播放状态时，不支持启动本地录像操；
* -    3、启动录像后，在录像过程中，播放器通过#IMOS_XP_SetPlayerRunMsgCB设置的回调函数上报消息#XP_PLAYER_RUN_INFO_RECORD_VIDEO；携带的错误码：
* -     #ERR_XP_DISK_CAPACITY_WARN              上报消息之前，播放器继续录像
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        上报消息之前，播放器停止录像
* -     #ERR_XP_FAIL_TO_WRITE_FILE              上报消息之前，播放器停止录像
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      上报消息之前，播放器停止录像
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         上报消息之前，播放器停止录像
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   上报消息之前，播放器停止录像
* -    4、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartRecord(IN ULONG_32 ulPort,
                                                        IN const CHAR *pcFileName,
                                                        IN ULONG_32 ulMediaFileFormat,
                                                        OUT CHAR *pcFilePostfix);

/**
* 停止本地录像。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_NOT_START_RECORD_VIDEO               通道未开始本地录像操作
* -         #ERR_XP_FAIL_TO_STOP_RECORD_VIDEO            停止本地录像失败
* -         #ERR_XP_NOT_START_PLAY                       通道未开始播放操作
* @note
* -    1、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopRecord(IN ULONG_32 ulPort);

/**
* 获得视频编码格式。\n
* @param [IN]  ulPort             播放通道号。
* @param [OUT] pulVideoEncodeType 存放视频编码格式的指针，值为#XP_VIDEO_ENCODE_TYPE_E枚举中一个。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES           获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                 通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC          播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE  获得视频编码格式失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后且#IMOS_XP_StopPlay之前调用，才能准确获得指定播放通道的视频编码格式；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetVideoEncodeType(IN ULONG_32 ulPort,
                                                               OUT ULONG_32 *pulVideoEncodeType);

/**
* 获得丢包率。\n
* @param [IN]  ulPort        播放通道号。
* @param [OUT] pulRecvPktNum 存放已接收到包数的指针。
* @param [OUT] pulLostPktNum 存放丢弃包数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_GET_LOST_PKT_RATE    获得丢包率统计数据失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后且#IMOS_XP_StopPlay之前调用，才能准确获得指定播放通道的丢包率；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetLostPacketRate(IN ULONG_32 ulPort,
                                                              OUT ULONG_32 *pulRecvPktNum,
                                                              OUT ULONG_32 *pulLostPktNum);

/**
* 复位丢包率。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                   通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC            播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE      复位丢包率统计数据失败
* @note
* -    1、调用该函数后，将从复位时刻重新开始统计丢包率；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ResetLostPacketRate(IN ULONG_32 ulPort);

/**
* 获得丢帧率。\n
* @param [IN] ulPort           播放通道号。
* @param [OUT] pulAllFrameNum  存放帧总数的指针。
* @param [OUT] pulLostFrameNum 存放丢弃的帧数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE  获得丢帧率统计数据失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后且#IMOS_XP_StopPlay之前调用，才能准确获得指定播放通道的丢帧率；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetLostFrameRate(IN ULONG_32 ulPort,
                                                             OUT ULONG_32 *pulAllFrameNum,
                                                             OUT ULONG_32 *pulLostFrameNum);

/**
* 复位丢帧率。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                   通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC            播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE    复位丢帧率统计失败
* @note
* -    1、调用该函数后，将从复位时刻重新开始统计丢帧率；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ResetLostFrameRate(IN ULONG_32 ulPort);

/**
* 设置指定通道的数字放大功能。\n
* @param [IN] ulPort                   播放通道号
* @param[IN]    horizon                水平转动 (-360 取值为  360，单位度)
* @param[IN]    vectal                 垂直转动 (-360 取值为  360，单位度)
* @param[IN]    zoom                   放大缩小    (-1表示缩小5%,0表示不伸缩，1表示扩大5%)
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT                  不支持该功能
* @note
* - 1、该接口函数仅支持Windows。
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetSceneControl(IN const ULONG_32 ulPort,
															   IN const LONG_32 lHorizon,
															   IN const LONG_32 lVectal,
															   IN const LONG_32 lZoom);
															   
/**
* 获得帧率。\n
* @param [IN]  ulPort       播放通道号。
* @param [OUT] pulFrameRate 存放帧率的指针，单位为fps。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_GET_FRAME_RATE       获得帧率数据失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后且#IMOS_XP_StopPlay之前调用，才能准确获得指定播放通道的帧率；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetFrameRate(IN ULONG_32 ulPort,
                                                         OUT ULONG_32 *pulFrameRate);

/**
* 获得码率。\n
* @param [IN] ulPort        播放通道号。
* @param [OUT] pulBitRate   存放码率的指针，单位为bps。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_FAIL_TO_GET_BIT_RATE         获得码率数据失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后且#IMOS_XP_StopPlay之前调用，才能准确获得指定播放通道的码率；另外，
*         该函数不支持获得本地文件回放通道的码率；
* -    2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetBitRate(IN ULONG_32 ulPort,
                                                       OUT ULONG_32 *pulBitRate);


/**
* 打开语音业务。\n
* @param [IN] ulVoiceSvcType  语音业务类型，需从#XP_VOICE_SERVICE_TYPE_E枚举中取值。
* @param [IN] pcLocalIP       本端IP地址。
* @param [IN] usLocalPort     本端监听端口。
* @param [IN] pcRemoteIP      远端IP地址。
* @param [IN] usRemotePort    远端端口。
* @param [IN] ulTransProtl    收发媒体流的传输层协议，需从#XP_PROTOCOL_E枚举中取值。
* @param [OUT] pulPort        返回语音业务通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得语音通道资源失败
* -         #ERR_XP_FAIL_TO_OPEN_VOICE_SVC           启动语音业务失败
* @note
* -    1、如果使用本地默认的IP地址，则本地IP地址参数pcLocalIP传入空字符串；
* -    2、启动语音业务后，在播放过程中，播放器通过#IMOS_XP_SetPlayerRunMsgCB设置的回调函数上报消息#XP_PLAYER_RUN_INFO_MEDIA_VOICE；携带的错误码：
* -     #ERR_XP_FINISH_PLAY_FILE                上报消息之前，播放器停止语音业务
* -     #ERR_XP_VOICE_RUNNING                   上报消息之前，播放器停止语音业务
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OpenVoiceSvc(IN ULONG_32 ulVoiceSvcType,
                                                         IN const CHAR *pcLocalIP,
                                                         IN USHORT usLocalPort,
                                                         IN const CHAR *pcRemoteIP,
                                                         IN USHORT usRemotePort,
                                                         IN ULONG_32 ulTransProtl,
                                                         OUT ULONG_32 *pulPort);

/**
* 开始语音业务。\n
* @param [IN] ulPort 语音业务通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得语音通道资源失败
* -         #ERR_XP_FAIL_TO_START_VOICE_SVC          启动语音业务失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartVoiceSvc(IN ULONG_32 ulPort);

/**
* 停止语音业务。\n
* @param [IN] ulPort 语音业务通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得语音通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_VOICE_SVC           停止语音业务失败
* -         #ERR_XP_NOT_START_PLAY                   通道未开始播放操作
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopVoiceSvc(IN ULONG_32 ulPort);

/**
* 关闭语音业务。\n
* @param [IN] ulPort 语音业务通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得语音通道资源失败
* -         #ERR_XP_FAIL_TO_CLOSE_VOICE_SVC          关闭语音业务失败
* -         #ERR_XP_NOT_START_PLAY                   通道未开始播放操作
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CloseVoiceSvc(IN ULONG_32 ulPort);

/**
* 启动或停止向语音对端发送语音数据。\n
* @param [IN] ulPort 语音业务通道号。
* @param [IN] bSend     是否向语音对端发送语音数据（#BOOL_TRUE：启动发送，#BOOL_FALSE：停止发送）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_VOICE_SILENCE            启动/停止发送语音数据失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SendVoiceData(IN ULONG_32 ulPort, IN BOOL_T bSend);

/**
* 麦克风音量调节。\n
* @param [IN] ulVolume 音量值（范围从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_MIC_NOT_EXIST            系统中麦克风适配不存在
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMicVolume(IN ULONG_32 ulVolume);

/**
* 获得麦克风音量值。\n
* @param [OUT] pulVolume 音量值的指针（范围从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_MIC_NOT_EXIST            系统中麦克风适配不存在
* -         #ERR_XP_FAIL_TO_GET_VOLUME       获得音量值失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetMicVolume(OUT ULONG_32 *pulVolume);

/**
* 启动连续实时抓拍。\n
* @param [IN] ulPort             播放通道号。
* @param [IN] pcFileName         图像文件存放的路径，包括文件名（不带扩展名）。
* @param [IN] ulPicFormat        图像文件的格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] ulInterval         抓拍间隔，单位为毫秒。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_ALREADY_START_SERIES_SNATCH  播放通道已经启动了连续抓拍的操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_FAIL_TO_START_SERIES_SNATCH  启动连续抓拍操作失败
* @note
* -
* -    1、播放器XP会在文件名后面附加类似于"20080928(13-10-50-99)"格式的抓拍时间戳字符串，
* -       单位时间内成功抓拍的最多图片数和机器性能有关；
* -    2、启动连续抓拍后，在抓拍过程中，播放器通过#IMOS_XP_SetPlayerRunMsgCB设置的回调函数上报消息#XP_PLAYER_RUN_INFO_SERIES_SNATCH；携带的错误码：
* -     #ERR_XP_DISK_CAPACITY_WARN              上报消息之前，播放器继续抓拍
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        上报消息之前，播放器停止抓拍
* -     #ERR_XP_FAIL_TO_SERIES_SNATCH           上报消息之前，播放器停止抓拍
* -     #ERR_XP_NO_PICTURE_TO_SNATCH            上报消息之前，播放器停止抓拍
* -    3、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartSnatchSeries(IN ULONG_32 ulPort,
                                                              IN const CHAR *pcFileName,
                                                              IN ULONG_32 ulPicFormat,
                                                              IN ULONG_32 ulInterval);

/**
* 停止连续实时抓拍。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_NOT_START_SERIES_SNATCH      指定的播放通道未启动连续抓拍操作
* -         #ERR_XP_FAIL_TO_STOP_SERIES_SNATCH   停止连续抓拍操作失败
* @note
* -    1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopSnatchSeries(IN ULONG_32 ulPort);

/**
* 设置指定播放通道的NAT类型。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] ulNatMode         NAT类型，需从#XP_NAT_MODE_E枚举中取值。
* @param [IN] pcNatSessionStr   NAT引流字符串。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note
* -    1、引流字符串可以自行定义，但是收发双方必须保持一致；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetNatParam(IN ULONG_32 ulPort,
                                                        IN ULONG_32 ulNatMode,
                                                        IN const CHAR *pcNatSessionStr);

/**
* 设置音频数据源。\n
* @param [IN] enWaveInSource     音频数据源，包括音频采集设备#XP_WAVEIN_SOURCE_DEVICE和音频文件#XP_WAVEIN_SOURCE_FILE两种音频数据源。
*                                需从#XP_WAVEIN_SOURCE_E枚举中取值。
* @param [IN] pWaveInParameter   附加信息参数，当音频数据源为#XP_WAVEIN_SOURCE_FILE时，需要使用#XP_WAVEIN_FILE_INFO_S结构体作附加参数；
*                                当音频数据源为#XP_WAVEIN_SOURCE_DEVICE时，该参数传入NULL。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_SET_WAVEIN_MOD           设置音频输入源失败
* @note
* - 1、在不调用该接口函数的情况下，默认采用音频采集设备作为音频数据源；
* - 2、当设置音频文件作为音频数据源时需要传入附加信息，参考#XP_WAVEIN_FILE_INFO_S结构体；
* - 3、音频文件只支持8000采样率+16位采样+单声道的wave格式音频文件；
* - 4、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetWaveInSourceMode(IN XP_WAVEIN_SOURCE_E enWaveInSource, IN VOID *pWaveInParameter);


/**
* 输入语音数据
* @param [IN] ulPort    语音通道号。
* @param [IN] pucDataBuf            语音数据地址。
* @param [IN] ulDataLen             语音数据长度。
* @param [IN] pstVoiceParam         语音参数。
* @return 输入语音数据是否成功。
*         ERR_COMMON_SUCCEED        成功。
*         ERR_COMMON_INVALID_PARAM  无效参数。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_VoiceInputData(IN ULONG_32 ulPort, IN const UCHAR *pucDataBuf,
                                                              IN ULONG_32 ulDataLen, IN XP_AUDIO_SAMPLE_PARAM_S *pstVoiceParam);

/**
* 设置解析后语音数据回调函数\n
* @param [IN] ulPort                    播放通道号。
* @param [IN] pfnParseVoiceDataCBFun    解析后语音数据回调函数的指针。
* @param [IN] bContinue                 是否继续进行后面的播放操作。
* @param [IN] lUserParam                用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
*      1、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetParseVoiceDataCB(IN ULONG_32 ulPort,
                                                                   IN XP_PLAYER_PARSE_VOICE_DATA_CALLBACK_PF pfnParseVoiceDataCBFun,
                                                                   IN BOOL_T bContinue,
                                                                   IN LONG_REAL lUserParam);

/**
* 设置ddraw表面hdc的回调函数。\n
* @param [IN] ulPort                   播放通道号。
* @param [IN] pfnDDrawDisplayHdcCBFun  DDraw表面hdc回调函数的指针。
* @param [IN] lUserParam               用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_DISPLAY_HDC_CB       设置显示回调函数失败
* @note
*      1、该函数在创建通道资源之后调用，释放通道资源后失效。
*      2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL。
*      3、该回调函数仅限于普通品质时使用。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDisplayHdcCB(IN ULONG_32 ulPort,
                                                               IN XP_PLAYER_HDC_CALLBACK_PF pfnDisplayHdcCBFun,
                                                               IN LONG_REAL lUserParam);


/* Begin add by sunbiao/sW1071 2014.10.24 for MPPD08613 SonyIPC onvif组播实况无声音 */
/**
* 设置网络流的发送音频源端口。\n
* @param [IN] ulPort                             播放通道号。
* @param [IN] usRemoteAudioPort                  播放音频端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可用
* @note
*      1、该函数在创建通道资源之后调用，释放通道资源后失效。
*      2、该接口函数支持Windows和Linux。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetAudioPort(IN ULONG_32 ulPort, IN USHORT usRemoteAudioPort);
/* End add by sunbiao/sW1071 2014.10.24 for MPPD08613 SonyIPC onvif组播实况无声音 */


/**
* 设置显存释放模式。\n
* @param [IN]  ulPort                              播放通道号。
* @param [IN] bRemainRenderRes                     是否保留显存
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数无效
* @note
* - 1、该函数用来设置是否释放通道显示资源，用以解决长时间轮切导致DirectX显存资源无法申请问题。
* - 2、如果用户没有调用该函数，则播放器XP内部默认使用显存释放模式；
* - 3、在Startplay之前或之后调用，StopPlay之后失效。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRenderResourceMode(IN ULONG_32 ulPort, IN BOOL_T bRemainRenderRes);

/**
* 设置下载的录像是否是加扰(默认同原始码流)。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] bDownloadMode     是否加扰。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 引流字符串可以自行定义，但是收发双方必须保持一致；可以传空字符串，但指针不能为空。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDownloadScrambleMode(IN ULONG_32 ulPort, IN const BOOL_T bDownloadMode);

/* Begin to add by wangzenghui/03836 on 2017/12/15 for MPPD54171 */
/**
* 判断是否支持硬件编码 \n
* @return 返回如下：
* -         #BOOL_TRUE                  支持硬件编码
* -         #BOOL_FALSE              不支持硬件解码
*/
IMOS_XP_PLAYER_EXPORT BOOL_T STDCALL IMOS_XP_IsSupportGpuEncode();
/* End to add by wangzenghui/03836 on 2017/12/15 for MPPD54171 */

/**
* 设置鱼眼矫正回调指针
* @param [IN] ulPort                            播放通道号
* @param [INOUT] pfnFishAdajustDataCBFun        鱼眼矫正回调指针
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
#ERR_COMMON_FAIL                                 执行失败
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetFishAdajustDataCB(IN ULONG_32 ulPort,
                                                                    IN IMOS_uintptr_t pfnFishAdajustDataCBFun,
                                                                    IN IMOS_uintptr_t pfnISFQueryCBFun);

/**
* 判断当前通道是否是鱼眼通道
* @param [IN] pcChannelCode                     播放通道编码。
* @param [IN] pbIsFishAdjust                    返回是否是鱼眼通道
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
#ERR_COMMON_FAIL                                 执行失败
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_IsFishAdjust(IN ULONG_32 ulPort,
                                                            OUT BOOL_T *pbIsFishAdjust);

   /**
    * 设置tcp连接次数\n
    * @param [IN] ulTcpReceiveCnt tcp连续收包失败次数。
	* @param [IN] ulTcpConnectCnt tcp连续等待连接次数。
    * @return VOID
    */
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTCPConnectCnt(IN ULONG_32 ulPort, IN const ULONG_32 ulTcpReceiveCnt, IN ULONG_32 ulTcpConnectCnt);


#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_PLAYER_H_ */
