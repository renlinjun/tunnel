 /*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_func.h

  Project Code: IMOS XP播放器
   Module Name: IMOS XP播放器
  Date Created: 2008-09-10
        Author: shiyouhua/04562
   Description: 播放器XP接口函数头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_MEDIA_PLAYER_SDK_FUNC_H_
#define _IMOS_XP_MEDIA_PLAYER_SDK_FUNC_H_

/* 包含基础平台的头文件 */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"
#include "sdk_def.h"
#include "sdk_struct.h"

/* 包含播放器 SDK数据结构头文件 */
#include "xp_datatype.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* 消息或者异常消息回调函数的指针类型，在新接口函数IMOS_SetRunMsgCB中使用。\n
* @param [IN] pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN] ulRunInfoType       消息或者异常消息类型，对应#XP_RUN_INFO_TYPE_E枚举中的值。
* @param [IN] pParam              存放消息或者异常消息数据的缓冲区指针（所存放的数据与消息或异常消息类型有关）。
* @return 无。
* @note
* -     1、客户在实现该回调函数时需要确保函数尽快返回，否则会阻塞播放器XP内部调用该回调函数的线程。
* -     2、参数pParam的实际类型根据具体的消息或者异常消息类型而定，客户需要根据消息或者异常消息类型做相应的类型转换；在某些情况下，该参数有可能为NULL。
* -     具体的类型转换关系如下：
* -         当ulRunInfoType值为#XP_RUN_INFO_SERIES_SNATCH、#XP_RUN_INFO_RECORD_VIDEO、#XP_RUN_INFO_MEDIA_PROCESS、
* -                            #XP_RUN_INFO_RTSP_PROTOCOL、#XP_RUN_INFO_PASSIVE_MONITOR、#XP_RUN_INFO_DOWN_MEDIA_PROCESS
* -                            或#XP_RUN_INFO_DOWN_RTSP_PROTOCOL时，需将pParam指针转换为#XP_RUN_INFO_EX_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_SIP_LIVE_TIMEOUT时，pParam指针为NULL；
* -         当ulRunInfoType值为#XP_RUN_INFO_VOICE_MEDIA_PROCESS时，需将pParam指针转换为#XP_VOICE_RUN_INFO_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_PASSIVE_START_MONITOR时，需将pParam指针转换为#XP_START_MONITOR_RUN_INFO_S结构体指针类型。
* -         当ulRunInfoType值为#XP_RUN_INFO_MEDIA_NOT_IDENTIFY时，需将pParam指针转换为#XP_RUN_INFO_EX_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_RECV_PACKET_NUM时，需将pParam指针转换为#XP_RECV_PACKET_NUM_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_RECV_BYTE_NUM时，需将pParam指针转换为#XP_RECV_BYTE_NUM_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_VIDEO_FRAME_NUM时，需将pParam指针转换为#XP_VIDEO_FRAME_NUM_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_AUDIO_FRAME_NUM时，需将pParam指针转换为#XP_AUDIO_FRAME_NUM_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_LOST_PACKET_RATIO时，需将pParam指针转换为#XP_LOST_PAKCET_RATIO_S结构体指针类型；
* -         当ulRunInfoType值为#XP_RUN_INFO_MEDIA_ABNORMAL时，需将pParam指针转换为#XP_RUN_INFO_EX_S结构体指针类型；
*/
typedef VOID (STDCALL* XP_RUN_INFO_CALLBACK_EX_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN ULONG_32 ulRunInfoType,
                                                   IN VOID *pParam);

/**
* 拼帧前媒体流数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pBuffer               存放拼帧前媒体流数据缓冲区指针。
* @param [IN] ulBufSize             缓冲区大小。
* @param [IN] ulMediaDataType       媒体流数据类型，对应#XP_MEDIA_DATA_FORMAT_E枚举中的值。
* @param [IN] lUserParam            用户设置参数，用户在调用IMOS_SetSourceMediaDataCB函数时指定的用户参数。
* @param [IN] lReserved             存放拼帧前媒体流扩展信息缓冲区指针，用户需要转换为#XP_SOURCE_DATA_EX_INFO_S
*                                   结构体指针类型，内含解码器标签（DecoderTag），当用户使用播放库解码和显示回调
*                                   的媒体流时，可根据解码器标签指定解码器。
* @return 无。
* @note
* -     用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_SOURCE_MEDIA_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN const UCHAR *pBuffer,
                                                         IN ULONG_32 ulBufSize,
                                                         IN ULONG_32 ulMediaDataType,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved);

/**
* 转码后的媒体流数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pBuffer               存放拼帧前媒体流数据缓冲区指针。
* @param [IN] ulBufSize             缓冲区大小。
* @param [IN] lUserParam            用户设置参数，用户在调用#IMOS_SetSourceMediaDataCB函数时指定的用户参数。
* @param [IN] lReserved             预留参数
* @return 无。
* @note
* -     用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_TRANSCODE_MEDIA_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN const CHAR *pcChannelCode,
                                                            IN const UCHAR *pBuffer,
                                                            IN ULONG_32 ulBufSize,
                                                            IN LONG_REAL lUserParam,
                                                            IN LONG_REAL lReserved);

/**
* 拼帧后视频流数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pstParseVideoData     存放拼帧后视频流数据信息缓冲区指针
* @param [IN] lUserParam            用户设置参数，用户在调用#IMOS_SetParseVideoDataCB函数时指定的用户参数。
* @param [IN] lReserved             保留参数。
* @return 无。
* @note
* -     用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL *XP_PARSE_VIDEO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcChannelCode,
                                                        IN const XP_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                        IN LONG_REAL lUserParam,
                                                        IN LONG_REAL lReserved);

/**
* 拼帧后音频流数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pstParseAudioData     存放拼帧后音频流数据信息缓冲区指针
* @param [IN] lUserParam            用户设置参数，用户在调用#IMOS_SetParseAudioDataCB函数时指定的用户参数
* @param [IN] lReserved             保留参数
* @return 无。
* @note
* -     用户应及时处理输出的数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL *XP_PARSE_AUDIO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcChannelCode,
                                                        IN const XP_PARSE_AUDIO_DATA_S *pstParseAudioData,
                                                        IN LONG_REAL lUserParam,
                                                        IN LONG_REAL lReserved);

/**
* 解码后视频流数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo   用户登录ID信息标识。
* @param [IN] pcChannelCode        播放通道编码。
* @param [IN] pstPictureData       存放解码后视频流数据信息缓冲区指针。
* @param [IN] lUserParam           用户设置参数，用户在调用#IMOS_SetDecodeVideoDataCB函数时指定的用户参数。
* @param [IN] lReserved            保留参数。
* @return 无。
* @note
* -     1、用户应及时处理输出的视频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
* -     2、视频数据是yv12格式。排列顺序“Y0-Y1-......”，“U0-U1-......”，“V0-V1-......”。
*/
typedef VOID (STDCALL* XP_DECODE_VIDEO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN const XP_PICTURE_DATA_S *pstPictureData,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved);

/**
* 解码后音频流数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pstWaveData           存放解码后音频流数据信息缓冲区指针。
* @param [IN] lUserParam            用户设置参数，用户在调用#IMOS_SetDecodeAudioDataCB函数时指定的用户参数。
* @param [IN] lReserved             保留参数。
* @return 无。
* @note
* -     用户应及时处理输出的音频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_DECODE_AUDIO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN const XP_WAVE_DATA_S *pstWaveData,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved);
/**
* 解码前语音数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pucVoiceDataBuffer    存放解码前语音数据信息缓冲区指针
* @param [IN] ulBufSize             音频数据大小
* @param [IN] ulAudioFlag           音频数据类型,需从#XP_AUDIO_FLAG_E枚举中取值
* @param [IN] pUserParam            用户设置参数
* @return 无。
* @note
* -     用户应及时处理输出的音频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_PARSE_VOICE_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
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
typedef VOID (STDCALL* XP_PLAYER_HDC_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                  IN const VOID *pHDC,
                                                  IN LONG_REAL lUserParam,
                                                  IN LONG_REAL lReserved);
/** @defgroup groupStartPlayer 播放器启动时配置信息
*   可设置视频显示模式、视频像素格式和接收消息或者异常消息的回调函数等。
*   @{
*/
/**
* 设置视频显示模式。\n
* @param [IN] ulRenderMode 视频显示模式，需从#XP_RENDER_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数非法
* @note
* - 1、在不调用此接口函数设置视频显示模式的情况下，将默认使用D3D显示模式；
* - 2、推荐在启动播放器时调用。
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRenderMode(IN ULONG_32 ulRenderMode);

/**
* 设置视频像素格式，支持YUV420和RGB32两种视频像素格式。\n
* @param [IN] ulPixelFormat 视频像素格式，需从#XP_PIXEL_FORMAT_EX_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数非法
* @note
* - 1、在不调用此函数接口函数设置视频像素格式的情况下，将默认使用YUV420视频像素格式；
* - 2、推荐在启动播放器时调用。
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPixelFormat(IN ULONG_32 ulPixelFormat);

/**
* 设置实时播放时图像的流畅性。\n
* @param [IN] ulFluency             设置实时播放时图像是实时性优先还是流畅性优先，需从#XP_PICTURE_FLUENCY_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数非法
* @note
* - 1、此接口函数用于设置实时播放时图像的流畅性，对回放时图像进行设置将不起作用，因为回放默认使用图像流畅性优先；
* - 2、在不调用此接口函数设置实时播放的图像流畅性时，将默认使用图像实时性优先；
* - 3、设置对所有实时通道有效。可在启动播放器时调用，也可在每次启动一路实时播放之前调用。
* - 4、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRealtimeFluency(IN ULONG_32 ulFluency);

/**
* 设置接收消息或者异常消息的回调函数。\n
* @param [IN] pfRunInfoFunc 消息或者异常消息回调函数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* - 1、用户不能在设置给播放器库的回调函数中直接调用播放器库任何接口函数；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRunMsgCB(IN XP_RUN_INFO_CALLBACK_EX_PF pfnRunInfoFunc);

/**
* 查询播放器是否在NAT内网。\n
* @param [IN] 无。
* @return
* -         #BOOL_TRUE          XP在NAT内网
* -         #BOOL_FALSE         XP不在NAT内网
* @note
* - 1、只有在启动播放器之后调用，才能准确查询到播放器是否在NAT内网；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_IsInNat();

/**
* 查询用户对应的播放器是否在NAT内网。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @return
* -         #BOOL_TRUE          XP在NAT内网
* -         #BOOL_FALSE         XP不在NAT内网
* @note 只有在注册播放器之后调用，才能准确查询到播放器是否在NAT内网。
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_IsInNatEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo);
/** @} */  /* end of groupStartPlayer */

/** @defgroup groupPlayerRealtime 实时播放（播放器）
*   实现实时播放功能。包括抓图、本地录像、实时流数据捕获、声音控制以及获取媒体流统计信息等功能。
*   @{
*/
/**
* 设置播放视频的窗口句柄。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] hWnd               播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* @note
* - 1、用于实况、点播回放和本地文件回放时设置播放视频的窗口句柄。
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlayWnd(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          IN IMOS_HANDLE hWnd);

/**
* 设置播放窗口上视频图像显示比例。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulRenderScale      视频图像在播放窗口上的显示比例，需从#XP_RENDER_SCALE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_RENDER_SCALE        设置图像显示比例参数失败
* @note
* - 1、在不调用该接口的情况下，视频图像默认填充整个播放窗口；
* - 2、在启动播放之前调用该接口时，则设置的显示比例参数在后续启动该播放通道播放时生效；
* - 3、在播放过程中调用该接口时，则设置的显示比例参数实时生效；
* - 4、调用该接口对指定播放通道设置的显示比例参数在播放器运行期间一直有效；
* - 5、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRenderScale(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN ULONG_32 ulRenderScale);

/**
* 设置抓拍图片质量。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulPictureQuality       图片质量
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           入参无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPictureQuality(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const ULONG_32 ulPictureQuality);


/**
* 设置图象的对比度参数，即时起作用。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulContrastMode     图象对比度模式，需从#XP_PICTURE_CONTRAST_MODE_E枚举中取值。
* @param [IN] ulContrastLevel    图象对比度级别，需从#XP_PICTURE_CONTRAST_LEVEL_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER        播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST 播放通道不支持设置图象对比度参数
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     设置图象对比度参数失败
* @note
* - 1、在不调用该接口的情况下，视频图像默认不进行对比度调节处理；
* - 2、可以在开始播放#IMOS_StartPlay之前设置，但设置的对比度参数被保存，作为启动该通道播放时
* -    的初始值；在开始播放后调用该接口设置的对比度参数即时起作用；
* - 3、调用该接口对指定播放通道设置的对比参数在播放器运行期间一直有效；当参数ulContrastMode
* -    传入#XP_PICTURE_CONTRAST_MODE_NONE时，即停止对比度调节处理，此时ulContrastLevel参数传
* -    入的值无效；
* - 4、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPictureContrast(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulContrastMode,
                                                  IN ULONG_32 ulContrastLevel);

/**
* 设置解码场模式。\n
* @param [IN] pstUserLoginIDInfo   用户登录ID信息标识。
* @param [IN] pcChannelCode        播放通道编码。
* @param [IN] ulFieldMode          场模式，需从#XP_FIELD_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_SET_FIELD_MODE       设置解码场模式失败
* @note
* - 1、MPEG4没有场的概念；
* - 2、在启动实况、点播回放或本地文件回放之后调用该接口函数设置解码场模式；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFieldMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN ULONG_32 ulFieldMode);

/**
* 设置去交织处理模式。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [IN] ulDeinterlaceMode       去交织处理模式，需从#XP_DEINTERLACE_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_ENABLE_DEINTERLACE       启动或关闭去交织处理失败
* @note
* - 1、在不调用该接口的情况下，默认使用混合模式启动去交织处理；
* - 2、在启动实况、点播回放或本地文件回放之后调用该接口函数启动或关闭去交织处理；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDeinterlaceMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulDeinterlaceMode);

/**
* 设置音频数据源。\n
* @param [IN] ulWaveInSource     音频数据源，包括音频采集设备#XP_WAVEIN_SOURCE_DEVICE和音频文件#XP_WAVEIN_SOURCE_FILE
                                 以及用户输入音频数据#XP_WAVEIN_SOURCE_INPUT三种音频数据源。需从#XP_WAVEIN_SOURCE_E枚举中取值。
* @param [IN] pWaveInParameter   附加信息参数，当音频输入源为#XP_WAVEIN_SOURCE_FILE时，需要使用#XP_WAVEIN_FILE_INFO_S结构体作附加参数；
*                                当音频数据源为#XP_WAVEIN_SOURCE_DEVICE时，该参数传入NULL。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_SET_WAVEIN_MOD           设置音频数据源与工作模式失败
* @note
* - 1、在不调用该接口函数的情况下，默认采用音频采集设备作为数据源；
* - 2、当设置音频文件作为音频数据源时需要传入附加信息，参考#XP_WAVEIN_FILE_INFO_S结构体；
* - 3、音频文件只支持8000采样率+16位采样+单声道的wave格式音频文件；
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetWaveInSourceMode(IN ULONG_32 ulWaveInSource,
                                                   IN VOID *pWaveInParameter);

/**
* 设置拼帧前媒体流数据回调函数。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [IN] pfnSourceMediaDataCBFun 拼帧前媒体流数据回调函数的指针。
* @param [IN] bContinue               是否继续进行后面的拼帧、解码和显示操作。
* @param [IN] lUserParam              用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* - 1、实时播放时，该函数在#IMOS_StartMonitor之前或者之后调用，在#IMOS_StopMonitor时自动失效，下次调用
*      #IMOS_StartMonitor之前或者之后需要重新设置；点播回放时，该函数可在IMOS_OpenVodStream之前调用，也可
*      在#IMOS_OpenVodStream和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动点播回放时需要在相同位置重新设置；本地回放时，该函数可在#IMOS_OpenFile之前调用，
*      也可在#IMOS_OpenFile和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动本地回放时需要在相同位置重新设置；
* - 2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针#XP_SOURCE_MEDIA_DATA_CALLBACK_PF设为NULL；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSourceMediaDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                    IN BOOL_T bContinue,
                                                    IN LONG_REAL lUserParam);

/**
* 设置拼帧后视频数据回调函数。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [IN] pfnParseVideoDataCBFun  拼帧后视频数据回调函数的指针。
* @param [IN] bContinue               是否继续进行视频解码和播放操作。
* @param [IN] lUserParam              用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* - 1、实时播放时，该函数在#IMOS_StartMonitor之前或者之后调用，在#IMOS_StopMonitor时自动失效，下次调用
*      #IMOS_StartMonitor之前或者之后需要重新设置；点播回放时，该函数可在#IMOS_OpenVodStream之前调用，也可
*      在#IMOS_OpenVodStream和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动点播回放时需要在相同位置重新设置；
* - 2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针#XP_PARSE_VIDEO_DATA_CALLBACK_PF设为NULL；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetParseVideoDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN XP_PARSE_VIDEO_DATA_CALLBACK_PF pfnParseVideoDataCBFun,
                                                   IN BOOL_T bContinue,
                                                   IN LONG_REAL lUserParam);

/**
* 设置拼帧后音频数据回调函数。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [IN] pfnParseAudioDataCBFun  拼帧后音频数据回调函数的指针。
* @param [IN] bContinue               是否继续进行音频解码和播放操作。
* @param [IN] lUserParam              用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* - 1、实时播放时，该函数在#IMOS_StartMonitor之前或者之后调用，在#IMOS_StopMonitor时自动失效，下次调用
*      #IMOS_StartMonitor之前或者之后需要重新设置；点播回放时，该函数可在#IMOS_OpenVodStream之前调用，也可
*      在#IMOS_OpenVodStream和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动点播回放时需要在相同位置重新设置；
* - 2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针#XP_PARSE_AUDIO_DATA_CALLBACK_PF设为NULL；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetParseAudioDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN XP_PARSE_AUDIO_DATA_CALLBACK_PF pfnParseAudioDataCBFun,
                                                   IN BOOL_T bContinue,
                                                   IN LONG_REAL lUserParam);

/**
* 设置解码后视频流数据回调函数。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识。
* @param [IN] pcChannelCode             播放通道编码。
* @param [IN] pfnDecodeVideoDataCBFun   解码后视频流数据回调函数的指针。
* @param [IN] bContinue                 是否继续进行后面的视频显示操作。
* @param [IN] lUserParam                用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* - 1、实时播放时，该函数在#IMOS_StartMonitor之前或者之后调用，在#IMOS_StopMonitor时自动失效，下次调用
*      #IMOS_StartMonitor之前或者之后需要重新设置；点播回放时，该函数可在#IMOS_OpenVodStream之前调用，也可
*      在#IMOS_OpenVodStream和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动点播回放时需要在相同位置重新设置；本地回放时，该函数可在#IMOS_OpenFile之前调用，
*      也可在#IMOS_OpenFile和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动本地回放时需要在相同位置重新设置；
* - 2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针#XP_DECODE_VIDEO_DATA_CALLBACK_PF设为NULL；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDecodeVideoDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN XP_DECODE_VIDEO_DATA_CALLBACK_PF pfnDecodeVideoDataCBFun,
                                                    IN BOOL_T bContinue,
                                                    IN LONG_REAL lUserParam);

/**
* 设置解码后音频流数据回调函数。\n
* @param [IN] pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN] pcChannelCode            播放通道编码。
* @param [IN] pfnDecodeAudioDataCBFun  解码后音频流数据回调函数的指针。
* @param [IN] bContinue                是否继续进行后面的音频播放操作。
* @param [IN] lUserParam               用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* - 1、实时播放时，该函数在#IMOS_StartMonitor之前或者之后调用，在#IMOS_StopMonitor时自动失效，下次调用
*      #IMOS_StartMonitor之前或者之后需要重新设置；点播回放时，该函数可在#IMOS_OpenVodStream之前调用，也可
*      在#IMOS_OpenVodStream和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动点播回放时需要在相同位置重新设置；本地回放时，该函数可在#IMOS_OpenFile之前调用，
*      也可在#IMOS_OpenFile和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动本地回放时需要在相同位置重新设置；
* - 2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针#XP_DECODE_AUDIO_DATA_CALLBACK_PF设为NULL；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDecodeAudioDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN XP_DECODE_AUDIO_DATA_CALLBACK_PF pfnDecodeAudioDataCBFun,
                                                    IN BOOL_T bContinue,
                                                    IN LONG_REAL lUserParam);

/**
* 单次实时抓拍，播放器将在用户指定的的图像文件名后附加抓拍系统时间。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         要保存的图像文件的文件名（不带扩展名），播放器会在此文件名后附加抓拍系统时间。
* @param [IN] ulPicFormat        图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         没有解码过的图片可供抓拍
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          单次抓拍操作失败
* @note
* - 1、播放器将在用户指定的文件名后面附加类似于"20080928(13-10-50-99)"格式的抓拍系统时间；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchOnce(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          IN const CHAR *pcFileName,
                                          IN ULONG_32 ulPicFormat);

/**
* 单次实时抓拍，抓取的图像文件名全部由用户指定。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         要保存的图像文件的文件名（不带扩展名）；文件名全部由用户指定。
* @param [IN] ulPicFormat        图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         没有解码过的图片可供抓拍
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          单次抓拍操作失败
* @note
* - 1、用户需确保在同一抓拍保存路径下，抓拍图像文件名不能重名；
* - 2、播放器会在用户指定的图像文件名后附加上后缀名；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchOnceEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN const CHAR *pcFileName,
                                            IN ULONG_32 ulPicFormat);

/**
* 启动连续实时抓拍。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         图像文件存放的路径，包括文件名（不带扩展名）。
* @param [IN] ulPicFormat        图像文件的格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] ulInterval         抓拍间隔，单位为毫秒 ; 0xFFFFFFFF 表示抓拍每个I帧
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_ALREADY_START_SERIES_SNATCH  播放通道已经启动了连续抓拍的操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_FAIL_TO_START_SERIES_SNATCH  启动连续抓拍操作失败
* @note
* - 1、播放器会在文件名后面附加“抓拍系统时间-系统毫秒级时间”格式的时间戳字符串，如“20110228110325-1997060991”；
* - 2、单位时间内成功抓拍的最多图片数和机器性能有关；
* - 3、播放器会在最终的图像文件名后附加上后缀名；
* - 4、启动连续抓拍后，在抓拍过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报抓拍消息#XP_RUN_INFO_SERIES_SNATCH；携带的错误码：
* -     #ERR_XP_DISK_CAPACITY_WARN          播放器内继续抓拍
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH    上报消息之前，播放器停止抓拍
* -     #ERR_XP_NO_PICTURE_TO_SNATCH        上报消息之前，播放器停止抓拍
* -     #ERR_XP_FAIL_TO_SERIES_SNATCH       上报消息之前，播放器停止抓拍
* -     #ERR_XP_FINISH_SERIES_SNATCH        上报消息之前，播放器停止抓拍
* - 5、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartSnatchSeries(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const CHAR *pcFileName,
                                                 IN ULONG_32 ulPicFormat,
                                                 IN ULONG_32 ulInterval);

/**
* 停止连续实时抓拍。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_NOT_START_SERIES_SNATCH      播放通道未启动连续抓拍操作
* -         #ERR_XP_FAIL_TO_STOP_SERIES_SNATCH   停止连续抓拍操作失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopSnatchSeries(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode);

/**
* 启动本地录像，录像文件名由播放器生成。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         录像文件存放路径（不包含文件名，且路径后面不带斜杠）。
* @param [IN] ulFileFormat       录像文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_COMMON_INVALID_PARAM                    输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                    播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                       播放通道未开始播放操作
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           播放通道已经启动录像操作
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      录像格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             硬盘空间不足
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 当前正处于暂停播放状态
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         当前正处于倍速播放状态
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  当前正处于单帧播放状态
* -         #ERR_XP_NOT_SUPPORT                          不支持该功能
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           启动本地录像失败
* -         #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE        播放通道的媒体编码类型不支持该操作
* @note
* - 1、播放器中录像文件的命名规则为：摄像机编码-通道号-S开始时间E结束时间，时间是形如“YYYYMMDDHHMMSSMS”
* -    格式的时间值组成，例如：Cam0001-00-S20100316094658286E20100316094806084；
* - 2、当点播回放或本地文件回放处于暂停播放、倍速播放或单帧播放状态时，不支持启动本地录像操作；
* - 3、启动录像后，在录像过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报录像消息#XP_RUN_INFO_RECORD_VIDEO；携带的错误码：
* -     #ERR_XP_DISK_CAPACITY_WARN              播放器内继续录像
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        上报消息之前，播放器停止录像
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      上报消息之前，播放器停止录像
* -     #ERR_XP_FAIL_TO_WRITE_FILE              上报消息之前，播放器停止录像
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   上报消息之前，播放器停止录像
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         上报消息之前，播放器停止录像
* - 4、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartRecord(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           IN const CHAR *pcFileName,
                                           IN ULONG_32 ulFileFormat);

/**
* 启动本地录像，录像文件名全部由用户指定。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         要保存的录像文件名（不带扩展名），文件名全部由用户指定。
* @param [IN] ulFileFormat       录像文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
* @param [OUT] pcFilePostfix     存放录像文件后缀的指针，缓冲区长度应不小于#IMOS_XP_FILE_POSTFIX_LEN。
*                                如果用户不需要返回后缀名，可将该参数设置为NULL。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_COMMON_INVALID_PARAM                    输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                    播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                       播放通道未开始播放操作
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           播放通道已经启动录像操作
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      录像格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             硬盘空间不足
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 当前正处于暂停播放状态
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         当前正处于倍速播放状态
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  当前正处于单帧播放状态
* -         #ERR_XP_NOT_SUPPORT                          不支持该功能
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           启动本地录像失败
* -         #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE        播放通道的媒体编码类型不支持该操作
* @note
* - 1、用户需确保在同一录像保存路径下，录像文件名不能重名；
* - 2、当点播回放或本地文件回放处于暂停播放、倍速播放或单帧播放状态时，不支持启动本地录像操作。
* - 3、播放器会在用户指定的录像文件名后附加上后缀名；
* - 4、启动录像后，在录像过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报录像消息#XP_RUN_INFO_RECORD_VIDEO；携带的错误码：
* -     #ERR_XP_DISK_CAPACITY_WARN              播放器内继续录像
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        上报消息之前，播放器停止录像
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      上报消息之前，播放器停止录像
* -     #ERR_XP_FAIL_TO_WRITE_FILE              上报消息之前，播放器停止录像
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   上报消息之前，播放器停止录像
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         上报消息之前，播放器停止录像
* - 5、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartRecordEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcFileName,
                                             IN ULONG_32 ulFileFormat,
                                             OUT CHAR *pcFilePostfix);

/**
* 停止本地录像。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_COMMON_INVALID_PARAM                    输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                    播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                       播放通道未开始播放操作
* -         #ERR_XP_NOT_START_RECORD_VIDEO               播放通道未启动本地录像操作
* -         #ERR_XP_FAIL_TO_STOP_RECORD_VIDEO            停止本地录像失败
* @note
* - 1、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopRecord(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);

/**
* 获得视频编码格式。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [OUT] pulVideoEncodeType     视频编码格式，需从#XP_VIDEO_ENCODE_TYPE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES           获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER              播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                 播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE  获得视频编码格式失败
* @note
* - 1、只有在实况、点播回放或本地文件回放开始后才能准确获取到指定通道的视频编码格式；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetVideoEncodeType(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  OUT ULONG_32 *pulVideoEncodeType);

/**
* 获得丢包率。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [OUT] pulRecvPktNum        已接收到包数。
* @param [OUT] pulLostPktNum        丢弃包数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_LOST_PKT_RATE    获得丢包率统计数据失败
* @note
* - 1、只有在实况、点播回放或本地文件回放开始之后才能准确获得指定播放通道的丢包率；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLostPacketRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 OUT ULONG_32 *pulRecvPktNum,
                                                 OUT ULONG_32 *pulLostPktNum);

/**
* 复位丢包率。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE      复位丢包率统计失败
* @note
* - 1、调用该函数后，将从复位时刻重新开始统计丢包率；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetLostPacketRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode);

/**
* 获得丢帧率。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [OUT] pulAllFrameNum       帧总数。
* @param [OUT] pulLostFrameNum      丢弃的帧数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE  获得丢帧率统计数据失败
* @note
* - 1、只有在实况、点播回放或本地文件回放开始之后才能准确获得指定播放通道的丢帧率；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLostFrameRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                OUT ULONG_32 *pulAllFrameNum,
                                                OUT ULONG_32 *pulLostFrameNum);
/**
* 复位丢帧率。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE    复位丢帧率统计失败
* @note
* - 1、调用该函数后，将从复位时刻重新开始统计丢帧率；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetLostFrameRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode);

/**
* 获得帧率。\n
* @param [IN] pstUserLoginIDInfo   用户登录ID信息标识。
* @param [IN] pcChannelCode        播放通道编码。
* @param [OUT] pulFrameRate        帧率，单位为fps。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_FRAME_RATE       获得帧率数据失败
* @note
* - 1、只有在实况、点播回放或本地文件回放开始之后才能准确获得指定播放通道的帧率；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFrameRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            OUT ULONG_32 *pulFrameRate);

/**
* 获得码率。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [OUT] pulBitRate           码率，单位为bps。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_BIT_RATE         获得码率数据失败
* @note
* - 1、只有在实况或点播回放开始之后才能准确获得指定播放通道的码率；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetBitRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          OUT ULONG_32 *pulBitRate);

/**
* 打开声音。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   播放通道未开始播放操作
* -         #ERR_XP_DECODE_AUDIO_NOT_CONTINUE        音频流数据解码后不继续进行播放操作
* -         #ERR_XP_FAIL_TO_QUIET                    打开声音操作失败
* @note
* - 1、同一时刻只能有一路声音。如果现在已经有声音打开，则自动关闭原来已经打开的声音；默认
* -    情况下声音是关闭的；
* - 2、调用该函数时，如果返回#ERR_XP_DECODE_AUDIO_NOT_CONTINUE错误码，是因为用户在调用
* -    #IMOS_SetDecodeAudioDataCB函数时将bContinue设置为BOOL_FALSE的原因引起的；也就是说，
* -    #IMOS_SetDecodeAudioDataCB函数的解码后音频流数据是否播放功能的优先级高于本函数功能；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PlaySound(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* 关闭声音。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_QUIET                    关闭声音操作失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopSound(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* 设置音量，调整声卡的音量。\n
* @param [IN] ulVolume 音量值（取值从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVolume(IN ULONG_32 ulVolume);

/**
* 获得当前设置的音量值。\n
* @param [OUT] pulVolume 音量值的指针（返回的音量值取值从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_GET_VOLUME       获得音量值失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetVolume(OUT ULONG_32 *pulVolume);

/**
* 调整所有通道音频数据的WAVE波形，可以改变所有通道播放声音的大小。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] ulCoefficient      调整的参数（范围从0到255，255为最大调整参数值）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* - 1、本函数和#IMOS_SetVolume函数的不同之处在于，它是调整所有通道（包括实时播放、回放和语音）
* -    声音数据的WAVE波形，只对所有通道起作用；而#IMOS_SetVolume是调整声卡音量，对整个操作系统起作用；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustAllWaveAudio(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN ULONG_32 ulCoefficient);
/** @} */  /* end of groupPlayerRealtime */

/** @defgroup groupPlayerPlayback 点播回放（播放器）
*   实现点播回放和下载录像相关功能，包括抓图、本地录像、回放录像文件时数据捕获、回放控制、录像文件下载、
*   声音控制以及获取媒体流参数等功能。
*   @{
*/
/**
* 打开点播回放媒体流。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pcVodUrl              录像文件的URL。
* @param [IN] pcServerIP            媒体流控服务器的IP。
* @param [IN] usServerPort          媒体流控服务器的端口号。
* @param [IN] ulProtl               接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道的资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体流失败
* -         #ERR_XP_FAIL_TO_OPEN_VOD             打开点播回放失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* - 1、如果播放器在NAT内网，必须将接收媒体流的协议类型设置为#XP_PROTOCOL_TCP协议；
* - 2、启动点播回放后，在播放过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报消息
* -     上报消息：#XP_RUN_INFO_MEDIA_PROCESS，携带的错误码：
* -     #ERR_COMMON_NO_MEMORY               上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  上报消息之前，播放器停止对应通道的播放
* -     上报消息：#XP_RUN_INFO_RTSP_PROTOCOL，携带的错误码：
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN      上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_RTSP_DISCONNECT             上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_RTSP_ENCODE_CHANGE          上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT     上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_RTSP_COMPLETE               上报消息之前，播放器暂停对应通道的播放
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcVodUrl,
                                             IN const CHAR *pcServerIP,
                                             IN USHORT usServerPort,
                                             IN ULONG_32 ulProtl);

/**
* 回放上墙。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] ulProtl               接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodToTv(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
											  IN const CHAR *pcChannelCode,
											  IN ULONG_32 ulProtl);

/**
* 设置通道解码器的厂商标识。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcDecoderTag       通道解码器的厂商标识，调用#IMOS_GetRecordFileURL函数获取，参见
*                                #IMOS_GetRecordFileURL函数的使用说明。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* @note
* - 1、如果用户没有调用该函数设置指定通道解码器的厂商标识，则该通道默认使用H3C V3（TS封装流）的解码器；
* - 2、仅用于点播回放时设置通道解码器的厂商标识；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDecoderTag(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcDecoderTag);

/**
* 设置指定通道的数字放大功能。\n
* @param [IN] pstUserLoginIDInfo       用户登录信息
* @param [IN] pcChannelCode            通道编码
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

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSceneControl(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
													 IN const CHAR *pcChannelCode,
													 IN const LONG_32 lHorizon,
													 IN const LONG_32 lVectal,
													 IN const LONG_32 lZoom);
													 
/**
* 开始播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_PORT_NOT_OPEN                播放通道未启动媒体业务
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放失败
* -         #ERR_XP_FAIL_TO_START_PLAY           开始播放失败
* @note
* - 1、主要用于开始点播回放和本地文件回放；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* 暂停播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          暂停媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       流控协商暂停失败
* -         #ERR_XP_FAIL_TO_PAUSE                暂停播放操作失败
* @note
* - 1、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PausePlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* 恢复播放，恢复播放已暂停的通道。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放失败
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         恢复媒体播放处理失败
* -         #ERR_XP_FAIL_TO_RESUME               恢复播放操作失败
* @note
* - 1、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResumePlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);

/**
* 停止播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_STOP_MEDIA           停止媒体播放处理失败
* -         #ERR_XP_FAIL_TO_STOP_PROTOCOL        停止流控协商
* -         #ERR_XP_FAIL_TO_QUIT_SESSION         退出会话失败
* -         #ERR_XP_FAIL_TO_STOP_PLAY            停止播放操作失败
* @note
* - 1、主要用于停止点播回放和本地文件回放；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopPlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCodel);

/**
* 设置播放速度，可以调整播放速度，使其倍速前进或者后退播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulPlaySpeed        播放速度，需从#XP_PLAY_STATUS_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY   倍速前进/后退播放失败
* @note
* - 1、正在本地录像时，不支持倍速前进/后退播放操作；
* - 2、点播回放时，不支持1/2和1/4倍速后退播放；本地文件播放时，不支持后退播放；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlaySpeed(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN ULONG_32 ulPlaySpeed);

/**
* 单帧播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧播放失败
* @note
* - 1、目前该接口仅支持点播回放时单帧播放，本地文件回放时暂不支持单帧播放；
* - 2、正在本地录像时，不支持单帧播放操作；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OneByOne(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode);

/**
* 逐帧播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧播放失败
* @note
* - 1、目前该接口仅支持点播回放时单帧播放，本地文件回放时暂不支持单帧播放；
* - 2、正在本地录像时，不支持单帧播放操作；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AutoOneByOne(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
										   IN const CHAR *pcChannelCode);
										
										
/**
* 根据时间（字符串型）设置文件播放位置。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcTime             设置文件播放位置到指定时间。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            跳转播放失败
* @note
* - 1、对于不同的应用，pcTime参数取值应不同：
* -   （1）本地文件回放时，该参数的值应为相对时间，相对于文件头的播放时间（单位为秒）；
* -   （2）点播回放时，该参数的值应为绝对时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* - 2、正在本地录像时候，不支持根据时间设置文件播放位置操作；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlayedTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcTime);

/**
* 根据时间（整型）设置文件播放位置。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulTime             设置文件播放位置到指定时间。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            跳转播放失败
* @note
* - 1、对于不同的应用，ulTime参数取值应不同：
* -   （1）本地文件回放时，该参数的值应为相对时间，相对于文件头的播放时间，单位为秒；
* -   （2）点播回放时，该参数的值应为绝对时间，单位为秒。
* - 2、正在本地录像时候，不支持根据时间设置文件播放位置操作；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlayedTimeEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN ULONG_32 ulTime);

/**
* 获得当前播放时间（字符串型）。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [OUT] pszTime           存放当前播放时间值，缓冲区长度应不小于#IMOS_TIME_LEN（32）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    获得当前播放进度失败
* @note
* -     pszTime参数存放当前播放时间，对于不同的应用其存放的值不同：
* - 1、本地文件回放时，存放的是相对时间，即相对于文件头的播放时间（单位为秒）；
* - 2、点播回放时，存放的是绝对时间（时间格式为：yyyy-mm-dd hh:mm:ss）；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPlayedTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             OUT CHAR *pszTime);

/**
* 获得当前播放时间（整型）。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [OUT] pulTime           存放当前播放时间值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    获得当前播放进度失败
* @note
* -     pulTime参数用来存放当前播放进度的时间值，对于不同的应用其存放的值不同：
* - 1、本地文件回放时，存放的是相对时间，即相对于文件头的播放时间，单位为秒；
* - 2、点播回放时，存放的是绝对时间，单位为秒；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPlayedTimeEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               OUT ULONG_32 *pulTime);

/**
* 启动下载媒体流，只支持下载TS流并存为TS格式录像文件。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownUrl           需下载媒体数据源的URL。
* @param [IN]  pcServerIP          媒体流控服务器的IP。
* @param [IN]  usServerPort        媒体流控服务器的端口号。
* @param [IN]  ulProtl             接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值（保留，目前仅支持TCP协议）。
* @param [IN]  ulDownMediaSpeed    媒体数据下载速度，需从#XP_DOWN_MEDIA_SPEED_E枚举中取值。
* @param [IN]  pcFileName          下载媒体数据保存的文件名，包括路径。
* @param [OUT] pcDownloadID        下载通道号，缓冲区长度应不小于#IMOS_RES_CODE_LEN（48）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      限制下载通道数
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放（下载）失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体失败
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     磁盘空间不够
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       启动下载失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* - 1、该函数调用成功后，返回给用户下载通道号，用于标识一路下载通道；
* - 2、最大同时支持启动32路下载通道；
* - 3、目前仅支持TCP协议下载媒体流；
* - 4、停止媒体流下载须调用#IMOS_StopDownMediaStream接口；
* - 5、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownMediaStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcDownUrl,
                                                    IN const CHAR *pcServerIP,
                                                    IN USHORT usServerPort,
                                                    IN ULONG_32 ulProtl,
                                                    IN ULONG_32 ulDownMediaSpeed,
                                                    IN const CHAR *pcFileName,
                                                    OUT CHAR *pcDownloadID);

/**
* 设置抽帧下载。\n
* @param [IN]  pstUserLoginIDInfo           用户登录ID信息标识。
* @param [IN]  pcChannelCode                下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note
* 1、不调用该接口时默认为全帧下载
* 2、在#IMOS_OpenDownloadCallback和#IMOS_StartDownloadCallback之间调用
* 3、在#IMOS_OpenDownload和#IMOS_StartDownload之间调用
* 4、在#IMOS_OpenDownloadEx和#IMOS_StartDownloadEx之间调用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetExtractFrameDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode);

/**
* 停止下载媒体流。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownloadID        下载通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note
* - 1、该接口与#IMOS_StartDownMediaStream接口匹配；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownMediaStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcDownloadID);

/**
* 打开媒体流下载，支持TS流和其它媒体流下载，将下载的媒体流保存为指定的格式。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownUrl           要下载录像文件的URL。
* @param [IN]  pcServerIP          媒体流控服务器的IP。
* @param [IN]  usServerPort        媒体流控服务器的端口号。
* @param [IN]  ulProtl             接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值（目前仅支持TCP协议）。
* @param [IN]  ulDownMediaSpeed    媒体数据下载速度，需从#XP_DOWN_MEDIA_SPEED_E枚举中取值。
* @param [IN]  pcFileName          下载后保存到本地的文件路径（不包含文件名，且路径后面不带斜杠）。
* @param [IN]  ulFileFormat        下载保存文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
* @param [OUT] pcChannelCode       下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      限制下载通道数
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_DOWNLOAD        启动下载业务失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* - 1、用户调用该函数成功后，可获得下载资源编码，用于标识一路下载通道；
* - 2、最大同时支持启动32路下载通道；
* - 3、打开媒体流下载后，需调用#IMOS_StartDownload接口开始下载，停止下载时调用#IMOS_StopDownload接口；
* - 4、下载录像文件的命名规则为：摄像机编码-通道号-S开始时间E结束时间，其中时间的格式为“YYYYMMDDHHMMSSMS”
* -    如：Cam0001-00-S20100316094658286E20100316094806084；
* - 5、启动下载后，在下载过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报消息
* -     上报消息：#XP_RUN_INFO_DOWN_MEDIA_PROCESS，携带的错误码为：
* -     #ERR_XP_DISK_CAPACITY_WARN              播放器继续下载
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_FAIL_TO_WRITE_FILE              上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         上报该消息之前，播放器停止对应通道的下载
* -     上报消息：#XP_RUN_INFO_DOWN_RTSP_PROTOCOL，携带的错误码为：
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN          上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_DISCONNECT                 上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_ENCODE_CHANGE              上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT         上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_COMPLETE                   上报该消息之前，播放器停止对应通道的下载
* - 7、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                      IN const CHAR *pcDownUrl,
                                                      IN const CHAR *pcServerIP,
                                                      IN USHORT usServerPort,
                                                      IN ULONG_32 ulProtl,
                                                      IN ULONG_32 ulDownMediaSpeed,
                                                      IN const CHAR *pcFileName,
                                                      IN ULONG_32 ulFileFormat,
                                                      OUT CHAR *pcDownloadID);

/**
* 打开媒体流下载，目前只支持TS媒体流下载，将下载的媒体流保存为ts的格式。下载录像文件名全部由用户指定。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownUrl           要下载录像文件的URL。
* @param [IN]  pcServerIP          媒体流控服务器的IP。
* @param [IN]  usServerPort        媒体流控服务器的端口号。
* @param [IN]  ulProtl             接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值。
* @param [OUT] pcChannelCode       下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      限制下载通道数
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_DOWNLOAD        启动下载业务失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* - 1、用户调用该函数成功后，可获得下载资源编码，用于标识一路下载通道；
* - 2、最大同时支持启动32路下载通道；
* - 3、目前仅支持TS媒体流下载,且仅支持1倍速下载；
* - 4、打开媒体流下载后，需调用#IMOS_StartDownloadEx接口开始下载，停止下载时调用#IMOS_StopDownload接口；
* - 5、启动下载后，在下载过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报消息
* -     上报消息：#XP_RUN_INFO_DOWN_MEDIA_PROCESS，携带的错误码为：
* -     #ERR_XP_DISK_CAPACITY_WARN              播放器继续下载
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_FAIL_TO_WRITE_FILE              上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         上报该消息之前，播放器停止对应通道的下载
* -     上报消息：#XP_RUN_INFO_DOWN_RTSP_PROTOCOL，携带的错误码为：
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN          上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_DISCONNECT                 上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_ENCODE_CHANGE              上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT         上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_COMPLETE                   上报该消息之前，播放器停止对应通道的下载
* - 6、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcDownUrl,
                                              IN const CHAR *pcServerIP,
                                              IN USHORT usServerPort,
                                              IN ULONG_32 ulProtl,
                                              OUT CHAR *pcChannelCode);

/**
* 开始下载，只有打开媒体流下载后才能开始下载。\n
* @param [IN] pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN] pcChannelCode       下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放（下载）失败
* -         #ERR_XP_NOT_SUPPORT_DOWNLOAD_FORMAT  下载文件格式不支持
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体失败
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           媒体播放处理失败
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     磁盘空间不够
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       开始下载失败
* @note
* - 1、用户调用#IMOS_OpenDownload接口打开媒体流下载后，再调用该接口开始下载，停止下载时调用#IMOS_StopDownload接口；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode);

/**
* 开始下载，只有打开媒体流下载后才能开始下载。下载录像文件名全部由用户指定。\n
* @param [IN]  pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN]  pcChannelCode      下载资源编码。
* @param [IN]  pcFileName         下载后保存到本地的文件名（不带扩展名），包括文件路径，文件名
*                                 全部由用户指定。
* @param [IN]  ulFileFormat       下载保存文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
* @param [IN]  ulDownMediaSpeed   媒体数据下载速度，需从#XP_DOWN_MEDIA_SPEED_E枚举中取值。
* @param [OUT] pcFilePostfix      存放录像文件后缀的指针，缓冲区长度应不小于#IMOS_XP_FILE_POSTFIX_LEN。
*                                 如果用户不需要返回后缀名，可将该参数设置为NULL。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放（下载）失败
* -         #ERR_XP_NOT_SUPPORT_DOWNLOAD_FORMAT  下载文件格式不支持
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       启动媒体流处理失败
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           媒体播放处理失败
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     磁盘空间不够
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       开始下载失败
* @note
* - 1、用户调用#IMOS_OpenDownloadEx接口打开媒体流下载后，再调用该接口开始下载，停止下载时调用#IMOS_StopDownload接口；
* - 2、播放器会在用户指定的的文件名后附加上后缀名；
* - 3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownloadEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcFileName,
                                               IN ULONG_32 ulFileFormat,
                                               IN ULONG_32 ulDownMediaSpeed,
                                               OUT CHAR *pcFilePostfix);

/**
* 停止下载媒体流。\n
* @param [IN]  pstUserLoginIDInfo   用户登录ID信息标识。
* @param [IN]  pcChannelCode        下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note
* - 1、该接口与#IMOS_OpenDownload和#IMOS_StartDownload接口匹配；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcDownloadID);

/**
* 打开下载捕获媒体流通道。\n
* @param [IN]  pstUserLoginIDInfo           用户登录ID信息标识。
* @param [IN]  pcDownUrl                    要下载录像文件的URL。
* @param [IN]  pcServerIP                   媒体流控服务器的IP。
* @param [IN]  usServerPort                 媒体流控服务器的端口号。
* @param [IN]  ulProtl                      接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值（目前仅支持TCP协议）。
* @param [IN]  ulDownMediaSpeed             媒体数据下载速度，需从#XP_DOWN_MEDIA_SPEED_E枚举中取值。
* @param [IN]  pfnSourceMediaDataCBFun      下载媒体流数据回调函数的指针。
* @param [IN]  lUserParam                   用户设置参数。
* @param [OUT] pcChannelCode                下载资源编码，缓冲区长度应不小于#IMOS_RES_CODE_LEN。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      限制下载通道数
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_DOWNLOAD        启动下载业务失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* - 1、用户调用该函数成功后，可获得下载资源编码，用于标识一路下载通道；
* - 2、最大同时支持启动32路下载通道；
* - 3、目前仅支持TCP协议下载媒体流；
* - 4、打开媒体流下载后，需调用#IMOS_StartDownloadCallback接口开始下载，停止下载时调用#IMOS_StopDownloadCallback接口；
* - 5、启动下载后，在下载过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报消息
* -     上报消息：#XP_RUN_INFO_DOWN_MEDIA_PROCESS，携带的错误码为：
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      上报该消息之前，播放器停止对应通道的下载
* -     上报消息：#XP_RUN_INFO_DOWN_RTSP_PROTOCOL，携带的错误码为：
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN          上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_DISCONNECT                 上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_ENCODE_CHANGE              上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT         上报该消息之前，播放器停止对应通道的下载
* -     #ERR_XP_RTSP_COMPLETE                   上报该消息之前，播放器停止对应通道的下载
* - 6、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcDownUrl,
                                                    IN const CHAR *pcServerIP,
                                                    IN USHORT usServerPort,
                                                    IN ULONG_32 ulProtl,
                                                    IN ULONG_32 ulDownMediaSpeed,
                                                    IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                    IN LONG_REAL lUserParam,
                                                    OUT CHAR *pcChannelCode);

/**
* 开始下载捕获媒体流。\n
* @param [IN]  pstUserLoginIDInfo           用户登录ID信息标识。
* @param [IN]  pcChannelCode                下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放（下载）失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体失败
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           媒体播放处理失败
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       开始下载失败
* @note
* - 1、用户调用#IMOS_OpenDownloadCallback接口打开媒体流下载后，再调用该接口开始下载，停止下载时调用#IMOS_StopDownloadCallback接口；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownloadCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                     IN const CHAR *pcChannelCode);

/**
* 停止下载捕获媒体流。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcChannelCode        下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note
* - 1、该接口与#IMOS_OpenDownloadCallback和#IMOS_StartDownloadCallback接口匹配调用；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownloadCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode);

/**
* 获得当前下载录像文件的绝对时间，可用于计算当前下载录像文件的进度。\n
* @param [IN]  pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN]  pcDownloadID          下载通道号。
* @param [OUT] pszTime               当前下载录像文件进度的绝对时间值，缓冲区长度应不小于#IMOS_TIME_LEN（32）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_GET_DOWN_POSITION    获得当前下载进度失败
* @note
* - 1、pszTime参数存放的是当前下载录像文件的绝对时间，时间格式为：yyyy-mm-dd hh:mm:ss；
* - 2、本函数需要和#IMOS_RecordRetrieval函数一起配合使用，才能计算出当前下载录像文件的进度。
*      用户调用#IMOS_RecordRetrieval函数后可获得录像文件的开始时间和结束时间，调用本函数后获得
*      当前下载录像文件的时间，所以，当前下载录像文件的进度 =（当前下载录像文件的时间 - 开始时间）
*      / （结束时间 - 开始时间）；
* - 3、该函数一般用于计算录像文件下载过程中的进度。在录像下载完成时，播放器会通过消息回调函数给用户
*      上报“录像下载完成”消息，用户接收到消息后可刷新下载状态为“完成”；
* - 4、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDownloadTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcDownloadID,
                                               OUT CHAR *pszTime);

/** @} */  /* end of groupPlayerPlayback */

/** @defgroup groupPlayerLocalFile 本地文件回放（播放器）
*   实现本地文件回放功能、包括抓图、本地录像、本地回放录像文件时数据捕获、回放控制、声音控制
*   以及获取媒体流参数等功能。
*   @{
*/
/**
* 打开本地播放文件。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         本地文件的文件名（包括文件路径）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道的资源失败
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      文件播放格式不支持
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       获得文件总的播放时间失败
* -         #ERR_XP_FAIL_TO_OPEN_FILE            启动本地文件播放失败(文件不存在或者正在被其他程序使用)
* -         #ERR_XP_FILE_DESTROY                 要打开的文件太小或者已经损坏
* -         #ERR_COMMON_NO_MEMORY                打开文件时系统内存不足
* -         #ERR_XP_FILE_HAVE_OPEN               播放通道已经打开了文件
* @note
* - 1、启动文件播放后，在播放过程中，播放器通过#IMOS_SetRunMsgCB设置的回调函数上报消息#XP_RUN_INFO_MEDIA_PROCESS；携带的错误码：
* -     #ERR_XP_FINISH_PLAY_FILE            上报消息之前，播放器暂停对应通道的播放
* -     #ERR_XP_FILE_DESTROY                上报消息之前，播放器停止对应通道的播放
* -     #ERR_COMMON_NO_MEMORY               上报消息之前，播放器停止对应通道的播放
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  上报消息之前，播放器停止对应通道的播放
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenFile(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN const CHAR *pcFileName);
/**
* 获得文件总的时间长度。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [OUT] pulTotalTime      文件总的时间长度，单位为秒。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* @note
* - 1、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFileTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           OUT ULONG_32 *pulTotalTime);
/** @} */  /* end of groupPlayerLocalFile */

/** @defgroup groupPlayerVoice 语音对讲和广播（播放器）
*   实现语音对讲和广播相关功能，包括音频数据发送控制和语音声音控制等功能。
*   @{
*/
/**
* 启动或停止向语音对端发送语音数据。\n
* @param [IN] pstUserLoginIDInfo   用户登录ID信息标识。
* @param [IN] bSend                是否向语音对端发送语音数据（#BOOL_TRUE：启动发送，#BOOL_FALSE：停止发送）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_VOICE_SILENCE            启动或停止向语音对端发送语音数据失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendVoiceData(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN BOOL_T bSend);

/**
* 启动或停止语音的声音播放。\n
* @param [IN] pstUserLoginIDInfo   用户登录ID信息标识。
* @param [IN] bQuiet               是否启动或停止本端语音的声音播放（#BOOL_TRUE：启用语音声音播放，#BOOL_FALSE：停止语音声音播放）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_NOT_START_VOICE_TALKBACK         当前没有启动语音对讲业务
* -         #ERR_XP_FAIL_TO_QUIET                    启用或停止语音的声音播放失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_VoiceQuiet(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN BOOL_T bQuiet);

/**
* 设置麦克风音量。\n
* @param [IN] ulVolume 音量值（取值范围从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_MIC_NOT_EXIST            系统中麦克风适配不存在
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMicVolume(IN ULONG_32 ulVolume);

/**
* 获得麦克风音量值。\n
* @param [OUT] pulVolume 音量值的指针（返回的音量值范围从0到255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_MIC_NOT_EXIST            系统中麦克风适配不存在
* -         #ERR_XP_FAIL_TO_GET_VOLUME       获得音量值失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMicVolume(OUT ULONG_32 *pulVolume);
/** @} */  /* end of groupPlayerVoice */

/**
* 设置回放或者下载的开始时间和结束时间。
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcStartTime        播放的起始时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @param [IN] pcStopTime         播放的结束时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_PORT_NOT_OPEN                指定的播放通道未启动媒体业务
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   设置开始时间和结束时间失败
* @note
* 1、该接口用于自动更新时间进度。
* 2、回放时，用户在调用#IMOS_OpenVodStream之后和#IMOS_StartPlay之前调用该接口。
* 3、下载时，用户在调用#IMOS_OpenDownloadEx之后和#IMOS_StartDownloadEx之前调用该接口。
* 4、国标的域间录像，需要调用这个接口设置开始时间和结束时间，才能正确获取进度。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetStartStopTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                IN const CHAR *pcStartTime,
                                                IN const CHAR *pcStopTime);


/**
* 设置媒体片段的开始时间和结束时间。
* @param [IN] pstUserLoginIDInfo           用户登录ID信息标识。
* @param [IN] pcChannelCode                播放通道编码。
* @param [IN] pstMediaSectionTime        媒体片段的时间信息（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @param [IN] ulSenctionNum                 媒体片段的数目。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM      输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_PORT_NOT_OPEN                指定的播放通道未启动媒体业务
* -         #ERR_XP_FAIL_TO_SET_MEDIA_SECTION_TIME   设置媒体片段时间信息失败
* @note
* 1、该接口用于保存媒体片段的时间。
* 2、下载时，用户在调用#IMOS_OpenDownloadEx之后和#IMOS_StartDownloadEx之前调用该接口。
* 3、目前仅支持下载。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaSectionTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
												   IN const CHAR *pcChannelCode,
												   IN const XP_MEDIA_SECTION_TIME_S *pstMediaSectionTime,
												   IN ULONG_32 ulSectionNum);



/**
* 添加IP地址映射 \n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识
* @param [IN] pcSrcAddr          源地址
* @param [IN] pcDstAddr          映射后地址
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAddressMap(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN const CHAR *pcSrcAddr, IN const CHAR *pcDstAddr);

/**
* 删除IP地址映射 \n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识
* @param [IN] pcSrcAddr          源地址
* @return 无
* @note
*/
IMOS_EXPORT VOID STDCALL IMOS_DelAddressMap(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN const CHAR *pcSrcAddr);

/**
* 输入语音数据
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] szXPVoiceTalkCode     语音对讲编码。
* @param [IN] pucDataBuf            语音数据地址。
* @param [IN] ulDataLen             语音数据长度。
* @param [IN] pstVoiceParam         语音参数。
* @return 输入语音数据是否成功。
*         ERR_COMMON_SUCCEED        成功。
*         ERR_COMMON_INVALID_PARAM  无效参数。
* @note
*   1.szXPVoiceTalkCode可为空串，pstVoiceParam为保留参数，暂不使用，填NULL
*   2.目前只支持输入G711音频编码类型数据，每次发送的数据大小为320字节
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_VoiceInputData(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN  CHAR szXPVoiceTalkCode[IMOS_RES_CODE_LEN],
                                                 IN const UCHAR *pucDataBuf,
                                                 IN ULONG_32 ulDataLen,
                                                 IN XP_AUDIO_SAMPLE_PARAM_S *pstVoiceParam);

/**
* 设置解析后音频流数据回调函数。\n
* @param [IN] pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN] pfnParseVoiceDataCBFun   解析后音频流数据回调函数的指针。
* @param [IN] bContinue                是否继续进行音频解码和播放操作。
* @param [IN] lUserParam               用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_PORT_NOT_REGISTER                指定的播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
*   1.该函数在IMOS_StartVoiceTalk之前或之后调用，在IMOS_StopVoiceTalk之后自动失效
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetParseVoiceDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                      IN XP_PARSE_VOICE_DATA_CALLBACK_PF pfnParseVoiceDataCBFun,
                                                      IN BOOL_T bContinue,
                                                      IN LONG_REAL lUserParam);

/**
* 设置桶型矫正\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识。
* @param [IN] pcChannelCode             通道资源编码。
* @param [IN] bOpen                     是否开启桶型矫正功能。
* @param [IN] enBarrelAjustLevel        桶型矫正等级，需从#XP_BARREL_ADJUST_LEVEL_E枚举值中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_FAIL                        执行失败
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_BARREL_ADJUST       设置桶型矫正失败
* @note
* -    1、默认不启动桶型矫正。
* -    2、桶型矫正等级范围为[1--10]，默认值为1。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBarrelAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN BOOL_T bOpen,
                                                  IN XP_BARREL_ADJUST_LEVEL_E enBarrelAjustLevel);


/**
* 设置ddraw表面hdc的回调函数。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDisplayHdcCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN XP_PLAYER_HDC_CALLBACK_PF pfnDisplayHdcCBFun,
                                                  IN LONG_REAL lUserParam);

/**
* 设置显存释放模式。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] bRemainRenderRes   是否保留显存
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数无效
* @note
* - 1、该函数用来设置是否释放通道显示资源，用以解决长时间轮切导致DirectX显存资源无法申请问题。
* - 2、如果用户没有调用该函数，则播放器XP内部默认使用显存释放模式；
* - 3、在Startplay之前或之后调用，StopPlay之后失效。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRenderResourceMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcChannelCode,
                                                        IN BOOL_T bRemainRenderRes);


/**
* 获取空闲的通道资源编码。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [OUT] pcChannelCodel         播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetChannelCode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, OUT CHAR *pcChannelCode);

/**
* 释放空闲的通道资源编码。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [OUT] pcChannelCodel         播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* @note 无。
*/
IMOS_EXPORT VOID STDCALL IMOS_FreeChannelCode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN const CHAR *pcChannelCode);

/**
* 启动图片播放功能。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_START_IMAGE          启动图片播放模式失败
* @note 当前只支持http协议的jpg图片播放。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartImage(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);

/**
* 图片加载。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcImageURL         图片URL信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           加载图片失败
* @note 当前只支持http协议的jpg图片播放。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LoadImage(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN const CHAR *pcImageURL);

/**
* 关闭图片播放功能。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_STOP_IMAGE           关闭图片播放模式失败
* @note 当前只支持http协议的jpg图片播放。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopImage(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);
										 

/**
* 设置下载的录像是否是加扰(默认同原始码流)。\n
* @param [IN] pstUserLoginIDInfo        用户信息
* @param [IN] pcChannelCode             播放通道号。
* @param [IN] bDownloadMode             是否加扰。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 引流字符串可以自行定义，但是收发双方必须保持一致；可以传空字符串，但指针不能为空。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadScrambleMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  BOOL_T bDOownloadMode);

/**
* 设置查找摄像机对应的Key值的回调函数 
* @param [IN] pstUserLoginIDInfo        用户信息
* @param [IN] szCamName                 摄像机名称
* @param [IN] pstQueryCondition         查询条件(赋值为NULL)
* @param [INOUT]pstCameraDescrambleInfo 获取出来的信息
*/
typedef ULONG_32 (STDCALL *XP_GETSCRAMBLE_KEY_CALLBACK_PF)(IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
                                                           IN  CHAR                            szCamName[IMOS_NAME_LEN],
                                                           IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
                                                           OUT CAM_DESCRAMBLE_INFO_S           *pstCameraDescrambleInfo);

/* Begin Added by lizhen 2017-6-23 for 设置获取视频加扰key的回调函数指针 */
/**
* 设置获取加扰key函数的回调函数。\n
* @param [IN] pstUserLoginIDInfo        用户信息
* @param [IN] XP_GETSCRAMBLE_KEY_CALLBACK_PF             回调函数指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetScrambleKeyCallBack(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN XP_GETSCRAMBLE_KEY_CALLBACK_PF pfnXpGetScrambleKeyCallBack);
														 
/* Begin:Added by lizhen in 2017-9-1 for 鱼眼矫正 */
/**
* 鱼眼矫正设置。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pstWorkParam          算法处理1帧参数
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
            #ERR_COMMON_FAIL                     执行失败
* @note 
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFishAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                IN IMOS_uintptr_t pstWorkInterfaceParam);

/**
* 设置鱼眼矫正回调指针
* @param [IN] pstUserLoginIDInfo                用户登录ID信息标识。
* @param [IN] pcChannelCode                     播放通道编码。
* @param [INOUT] pfnFishAdajustDataCBFun        鱼眼矫正回调指针
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
#ERR_COMMON_FAIL                                 执行失败
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFishAdajustDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode,
                                                       IN IMOS_uintptr_t pfnFishAdajustDataCBFun,
                                                       IN IMOS_uintptr_t pfnISFQueryCBFun);

/**
* 判断当前通道是否是鱼眼通道
* @param [IN] pstUserLoginIDInfo                用户登录ID信息标识。
* @param [IN] pcChannelCode                     播放通道编码。
* @param [IN] pbIsFishAdjust                    返回是否是鱼眼通道
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
#ERR_COMMON_FAIL                                 执行失败
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_IsFishAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               OUT BOOL_T *pbIsFishAdjust);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_MEDIA_PLAYER_SDK_FUNC_H_ */
