/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_func_obsolete.h

  Project Code: IMOS XP播放器
   Module Name: IMOS XP播放器
  Date Created: 2008-09-10
        Author: shiyouhua/04562
   Description: 播放器XP老接口函数头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_MEDIA_PLAYER_SDK_OBSOLETE_FUNC_H_
#define _IMOS_XP_MEDIA_PLAYER_SDK_OBSOLETE_FUNC_H_

/* 包含基础平台的头文件 */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"
/* 包含XP SDK数据结构头文件 */
#include "xp_datatype.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* 初始化播放器XP资源。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* -         #ERR_XP_FAIL_TO_REG_BP_CMD   注册基础平台BP的命令行模块失败
* -         #ERR_XP_FAIL_TO_INIT_XP      初始化播放器XP资源失败
* @note
* - 使用播放器XP软件包首先需要调用的函数。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_Init();

/**
* 释放播放器XP资源。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* -         #ERR_XP_FAIL_TO_CLEANUP_XP   释放播放器XP资源失败
* @note 退出播放器XP软件包最后一个需要调用函数。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_Cleanup();

/**
* 初始化播放器XP资源。\n
* @param [IN] pcModuleBaseCode 基础平台BP模块的编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* -         #ERR_XP_FAIL_TO_REG_BP_CMD   注册基础平台BP的命令行模块ID失败
* -         #ERR_COMMON_INVALID_PARAM    输入参数无效
* -         #ERR_XP_FAIL_TO_INIT_XP      初始化播放器XP资源失败
* @note
* - 使用播放器XP软件包首先需要调用的函数。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_InitXP(IN const CHAR *pcModuleBaseCode);

/**
* 释放播放器XP资源。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* -         #ERR_XP_FAIL_TO_CLEANUP_XP   释放播放器XP资源失败
* @note 退出播放器XP软件包最后一个需要调用函数。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_CleanupXP();

/** @defgroup groupPlayerStart 播放器启动
*   播放器启动，主要用于设置播放器启动参数、注册/注销和启动/停止播放器等。
*   @{
*/
/**
* 设置播放器XP的设备ID。\n
* @param [IN] pcXPDevID 播放器XP的设备ID，由IMOS_GetXPCode函数获得XP信息，其中包含播放器XP的设备ID。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数无效
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetXPDevID(IN const CHAR *pcXPDevID);

/**
* 设置播放窗口的句柄和资源编码。\n
* @param [IN] hWnd         播放窗口句柄。
* @param [IN] pcWndResCode 播放窗口的资源编码，由IMOS_GetXPCode函数获得XP信息，其中包含第一个窗口的资源编码，
*                          其他的窗口资源编码可在第一个窗口的资源编码的基础上生成。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_EXCEED_MAX_PLAY_WINDOW_NUM       注册的播放窗口数超过了限制
* @note
* -      1、每调用一次设置一个播放窗口的句柄和资源编码。一般按照最大分屏数（支持的最大播放窗口数）来分别调用该函数。
* -         比如：最大分屏数为25，就需要调用25次该函数设置25个播放窗口的句柄和资源编码
* -      2、该函数设置的各个播放窗口句柄不能重复，各个播放窗口的资源编码也不能重复（播放器XP内部对此不检查，需要用户保证）。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetWndIDInfo(IN IMOS_HANDLE hWnd,
                                          IN const CHAR *pcWndResCode);

/**
* 设置语音对讲的资源编码。\n
* @param [IN] pcTalkbackResCode 语音对讲的资源编码，由IMOS_GetXPCode函数获得XP信息，其中包含语音对讲的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数无效
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceTalkbackResCode(IN const CHAR *pcTalkbackResCode);

/**
* 设置语音广播的资源编码。\n
* @param [IN] pcBroadcastResCode 语音广播的资源编码，由IMOS_GetXPCode函数获得XP信息，其中包含语音广播的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数无效
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceBroadcastResCode(IN const CHAR *pcBroadcastResCode);

/**
* 注册消息或异常消息回调函数。\n
* @param [IN] pfRunInfoFunc 消息或异常消息回调函数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数无效
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetRunMsgCB(IN const XP_RUN_INFO_CALLBACK_PF pfnRunInfoFunc);

/**
* 设置解码后媒体流数据回调函数。\n
* @param [IN] pfnDataProcFunc 解码后媒体流数据回调函数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      注册解码后媒体流数据回调函数失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetOutputMediaDataCB(IN XP_PROCESS_MEDIA_DATA_CALLBACK_PF pfnDataProcFunc);

/**
* 设置视频显示模式。\n
* @param [IN] enRenderMode 视频显示模式。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_XP_FUNCTION_CALL_ORDER_ERROR      接口调用顺序错误
* @note
* - 1、如果客户没有调用该函数设置视频显示模式，则播放器XP内部默认使用DDraw的Normal显示模式；
* - 2、必须在XP_StartXP函数之前调用。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetRenderMode(IN XP_RENDER_MODE_E enRenderMode);

/**
* 设置视频图像格式，有YUV和RGB两种视频图像格式。\n
* @param [IN] enPixelFormat 视频图像格式。
* @return 无
* @note
* - 1、如果客户没有调用该函数接口，则播放器XP内部默认使用YUV视频图像格式；
* - 2、必须在XP_StartXP函数之前调用。
*/
IMOS_EXPORT VOID STDCALL XP_SetPixelFormat(IN XP_PIXEL_FORMAT_E enPixelFormat);

/**
* 设置控制信令服务器CC的信息。\n
* @param [IN] pcServerDevID 控制信令服务器的设备ID。
* @param [IN] pcServerIP    控制信令服务器的IP。
* @param [IN] usServerPort  控制信令服务器的端口号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* -         #ERR_COMMON_INVALID_PARAM    输入参数无效
* @note 控制信令服务器主要用于播放器XP和服务器之间的SIP注册和SIP会话。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetCCServerInfo(IN const CHAR *pcServerDevID,
                                             IN const CHAR *pcServerIP,
                                             IN USHORT usServerPort);

/**
* 注册播放器XP。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_XP_FAIL_TO_REGIST_XP        注册播放器XP失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_RegXP();

/**
* 查询播放器XP是否在NAT内网。\n
* @param [IN] 无。
* @return 返回如下错误码:
* -         #BOOL_TRUE          XP在NAT内网
* -         #BOOL_FALSE         XP不在NAT内网
* @note 必须在XP_RegXP函数之后调用。
*/
IMOS_EXPORT BOOL_T STDCALL XP_IsXPInNat();

/**
* 注销播放器XP。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_XP_FAIL_TO_UNREGIST_XP      注销播放器XP失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_UnregXP();

/**
* 启动播放器XP。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_XP_FAIL_TO_START_XP         启动播放器XP失败
* @note
* -    必须在XP_RegXP接口调用之后调用
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartXP();

/**
* 停止播放器XP。\n
* @param [IN] 无。
* @return 无。
* @note
* -     1、在退出XP之前调用该函数停止当前所有的活动通道；
* -     2、必须在XP_UnregXP函数之前调用。
*/
IMOS_EXPORT VOID STDCALL XP_StopXP();

/**
* 清除用户配置的窗口句柄、资源编码等信息。\n
* @param [IN] 无。
* @return 无。
* @note 无。
*/
IMOS_EXPORT VOID STDCALL XP_ResetInfo();
/** @} */  /* end of groupPlayerStart */

/**
* 初始化播放窗口的媒体业务类型。\n
* @param [IN] hXpWnd        播放窗口句柄。
* @param [IN] enWndPlayType 播放窗口的播放业务类型。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_XP_WINDOW_NOT_REGISTER      窗口没有被注册
* -         #ERR_XP_PORT_NOT_AVAILABLE       窗口不可使用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     获得播放窗口的资源失败
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC    播放通道的媒体业务类型不支持此操作
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenPlaySvc(IN IMOS_HANDLE hXpWnd,
                                         IN XP_PLAY_TYPE_E enWndPlayType);

/**
* 设置播放通道的本地IP地址和端口号。\n
* @param [IN] hXpWnd      播放窗口句柄。
* @param [IN] pcLocalIP   本地IP地址。
* @param [IN] usLocalPort 本地监听端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* @note 如果使用本地默认的IP地址，则本地IP地址参数pcLocalIP传入空字符串。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetWndLocalAddress(IN IMOS_HANDLE hXpWnd,
                                                IN const CHAR *pcLocalIP,
                                                IN USHORT usLocalPort);

/**
* 设置播放通道的媒体服务器IP地址和端口号。\n
* @param [IN] hXpWnd       播放窗口句柄。
* @param [IN] pcServerIP   媒体服务器IP地址。
* @param [IN] usServerPort 媒体服务器端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetWndServerAddress(IN IMOS_HANDLE hXpWnd,
                                                 IN const CHAR *pcServerIP,
                                                 IN USHORT usServerPort);

/**
* 输入媒体流数据。\n
* @param [IN] hXpWnd   播放窗口句柄。
* @param [IN] pcBuf    媒体数据指针。
* @param [IN] ulLength 媒体数据长度。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口未注册
* -         #ERR_XP_FAIL_TO_INPUT_DATA               输入媒体流数据失败
* @note 用户在启动实况或点播回放后,调用该函数输入媒体流数据进行播放。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_InputMediaData(IN IMOS_HANDLE hXpWnd,
                                            IN const CHAR *pcBuf,
                                            IN ULONG_32 ulLength);

/**
* 设置指定播放通道的媒体数据封装格式。\n
* @param [IN] hXpWnd            播放窗口句柄。
* @param [IN] enMediaDataformat 媒体数据封装格式。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_NOT_SUPPORT_MEDIA_STREAM_TYPE    不支持的码流类型
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放窗口的资源失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetMediaDataFormat(IN IMOS_HANDLE hXpWnd,
                                                IN XP_MEDIA_DATA_FORMAT_E enMediaDataformat);

/**
* 打开实时监控媒体流。\n
* @param [IN] hXpWnd          播放窗口句柄。
* @param [IN] pcRemoteResCode 前端媒体源的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放窗口被占用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_FAIL_TO_SETUP_SESSION        发起会话请求失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体失败
* -         #ERR_XP_FAIL_TO_OPEN_REALTIME        启动实时监控业务失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenRealtimeMonitor(IN IMOS_HANDLE hXpWnd,
                                                 IN const CHAR *pcRemoteResCode);

/** @defgroup groupPlayerRealtime 播放器实时播放
*   播放器实时播放，主要用于抓图、获取媒体流参数和实时播放控制等。
*   @{
*/
/**
* 设置解码场模式。\n
* @param [IN]  hXpWnd      播放窗口句柄。
* @param [OUT] enFieldMode 场模式。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未开始播放操作
* -         #ERR_XP_FAIL_TO_SET_FIELD_MODE       设置场模式失败
* @note
* -    1、MPEG4解码方式没有场的概念；
* -    2、在启动实况、点播回放或本地文件回放之后调用该函数设置解码场模式。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetFieldMode(IN IMOS_HANDLE hXpWnd,
                                          IN XP_FIELD_MODE_E enFieldMode);

/**
* 开启/关闭去交织处理。\n
* @param [IN] hXpWnd            播放窗口句柄。
* @param [IN] enDeinterlaceMode 去交织处理模式。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                   未开始播放操作
* -         #ERR_XP_FAIL_TO_ENABLE_DEINTERLACE       启动或关闭去交织处理失败
* @note
* -    1、默认情况下，使用混合模式启动去交织处理。
* -    2、在启动实况、点播回放或本地文件回放之后调用该接口启动或关闭去交织处理。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_EnableDeinterlace(IN IMOS_HANDLE hXpWnd,
                                               IN XP_DEINTERLACE_MODE_E enDeinterlaceMode);

/**
* 开启/关闭解码后媒体流数据输出。\n
* @param [IN] hXpWnd          播放窗口句柄。
* @param [IN] enMediaDataType 输出的媒体流数据的类型。
* @param [IN] bEnable         是否输出媒体流数据。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                   指定的通道未开始播放操作
* -         #ERR_XP_FAIL_TO_ENABLE_OUTPUT_DATA       启动或关闭XP输出媒体数据失败
* @note 开启或关闭指定的播放通道输出解码后指定类型的媒体数据，默认情况下不输出。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_EnableOutputMediaData(IN IMOS_HANDLE hXpWnd,
                                                   IN XP_OUTPUT_MEDIA_DATA_TYPE_E enMediaDataType,
                                                   IN BOOL_T bEnable);

/**
* 暂停播放。\n
* @param [IN] hXpWnd   播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未启动播放操作
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          暂停媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       流控协商暂停失败
* -         #ERR_XP_FAIL_TO_PAUSE                暂停播放操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_PausePlay(IN IMOS_HANDLE hXpWnd);

/**
* 恢复播放，恢复播放已暂停的通道。\n
* @param [IN] hXpWnd    播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未启动播放操作
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放失败
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         恢复媒体播放处理失败
* -         #ERR_XP_FAIL_TO_RESUME               恢复播放操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_ResumePlay(IN IMOS_HANDLE hXpWnd);

/**
* 启用/取消静音。\n
* @param [IN] hXpWnd 播放窗口句柄。
* @param [IN] bEnabled 是否静音 （BOOL_TRUE：静音操作，BOOL_FALSE：取消静音）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                   指定的通道未开始播放操作
* -         #ERR_XP_FAIL_TO_QUIET                    启用/取消静音操作失败
* @note
* -     同一时间只能播放一路声音。也就是说，当取消某个播放通道静音时，先查看是否有其他的播放通道或语音通道正
* -     在播放声音；如果有，就将正在播放声音的通道置成静音，然后取消指定播放通道静音，使其开始播放声音。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_Quiet(IN IMOS_HANDLE hXpWnd,
                                   IN BOOL_T bEnabled);

/**
* 音量调节。\n
* @param [IN] ulVolume 音量值（取值为0—255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        入参无效
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_AdjustVolume(IN ULONG_32 ulVolume);

/**
* 获得当前设置的音量值。\n
* @param [OUT] pulVolume 音量值的指针（返回的音量值取值为0—255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        入参无效
* -         #ERR_XP_FAIL_TO_GET_VOLUME       获得音量值失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetVolume(OUT ULONG_32 *pulVolume);

/**
* 调整所有通道音频数据的WAVE波形，可以改变所有通道播放声音的大小。\n
* @param [IN] ulCoefficient 调整的参数（范围从0到255，255为最大调整参数值）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        入参无效
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note
* -    此函数和XP_AdjustVolume函数的不同之处在于，它是调整所有通道
* -  （包括实时播放、回放和语音）声音数据的WAVE波形，只对所有通道起作用；
* -   而XP_AdjustVolume是调整声卡音量，对整个操作系统起作用。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_AdjustAllWaveAudio(IN ULONG_32 ulCoefficient);

/**
* 单次实时抓拍。\n
* @param [IN] hXpWnd      播放窗口句柄。
* @param [IN] pcFileName  存放抓拍图片的文件路径，包括文件名（不带扩展名）。
* @param [IN] enPicFormat 抓拍图片的格式（XP_PICTURE_BMP：表示bmp格式；XP_PICTURE_JPG：表示jpg格式）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未启动播放操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          单次抓拍操作失败
* @note 播放器XP会在文件名后面附加类似于"20080928(13-10-50-99)"格式的抓拍时间戳字符串。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SnatchOnce(IN IMOS_HANDLE hXpWnd,
                                        IN const CHAR *pcFileName,
                                        IN XP_PICTURE_FORMAT_E enPicFormat);

/**
* 启动连续实时抓拍。\n
* @param [IN] hXpWnd           播放窗格句柄。
* @param [IN] pcFileName       存放抓拍图片的文件路径，包括文件名（不带扩展名）。
* @param [IN] enPicFormat      抓拍图片的格式。
* @param [IN] ulSnatchInterval 抓拍间隔（单位：毫秒）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     硬盘空间不足
* -         #ERR_XP_NOT_START_PLAY               未启动播放操作
* -         #ERR_XP_ALREADY_START_SERIES_SNATCH  播放窗口已经启动了连续抓拍的操作
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    抓拍格式不支持
* -         #ERR_XP_FAIL_TO_START_SERIES_SNATCH  启动连续抓拍操作失败
* @note
* -      播放器XP会在文件名后面附加类似于"20080928(13-10-50-99)"格式的抓拍时间戳字符串。
* -      每秒钟内成功抓拍的最多图片数和机器性能有关。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartSnatchSeries(IN IMOS_HANDLE hXpWnd,
                                               IN const CHAR *pcFileName,
                                               IN XP_PICTURE_FORMAT_E enPicFormat,
                                               IN ULONG_32 ulSnatchInterval);

/**
* 停止连续实时抓拍。\n
* @param [IN] hXpWnd 播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未启动播放操作
* -         #ERR_XP_NOT_START_SERIES_SNATCH      未启动连续抓拍操作
* -         #ERR_XP_FAIL_TO_STOP_SERIES_SNATCH   停止连续抓拍操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopSnatchSeries(IN IMOS_HANDLE hXpWnd);

/**
* 启动本地录像。\n
* @param [IN] hXpWnd            播放窗口句柄。
* @param [IN] pcFilePathName    存储录像的目的文件路径，不包括文件名(路径不含斜杠)。
* @param [IN] enVideoFileFormat 保存的视频文件的格式。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_COMMON_INVALID_PARAM                    输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER                  播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                       未启动播放操作
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           指定的播放通道已经启动录像操作
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      录像格式不支持
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             硬盘空间不足
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 当前正处于暂停播放状态
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         当前正处于倍速播放状态
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  当前正处于单帧播放状态
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           启动本地录像失败
* @note
* -    播放器XP会在文件名后面附加类似于"00-20091222(14-30-24-984)"格式的字符串；
* -                                      |          |
* -                                   通道ID  开始录像时间戳
* -    当点播回放或本地文件回放处于暂停播放、倍速播放或单帧播放状态时，不支持启动本地录像操作。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartRecordVideo(IN IMOS_HANDLE hXpWnd,
                                              IN const CHAR *pcFilePathName,
                                              IN XP_MEDIA_FILE_FORMAT_E enVideoFileFormat);

/**
* 停止本地录像。\n
* @param [IN] hXpWnd 播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER                  播放窗口没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC                播放窗口的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_RECORD_VIDEO               指定的播放通道未启动本地录像操作
* -         #ERR_XP_FAIL_TO_STOP_RECORD_VIDEO            停止本地录像失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopRecordVideo(IN IMOS_HANDLE hXpWnd);

/**
* 获得指定播放通道的视频编码格式。\n
* @param [IN]  hXpWnd             播放窗口句柄。
* @param [OUT] penVideoEncodeType 视频编码格式。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES           获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER            播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                 未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE  获得视频编码格式失败
* @note
* -    在启动实况、点播回放或本地文件回放之后调用该函数获得指定播放通道的视频编码格式。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetVideoEncodeType(IN IMOS_HANDLE hXpWnd,
                                                OUT XP_VIDEO_ENCODE_TYPE_E *penVideoEncodeType);

/**
* 获得指定播放通道的丢包率。\n
* @param [IN]  hXpWnd        播放窗口句柄。
* @param [OUT] pulRecvPktNum 接收到的包数。
* @param [OUT] pulLostPktNum 丢弃的包数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_LOST_PKT_RATE    获得丢包率统计数据失败
* @note
* -    在启动实况、点播回放或本地文件回放之后调用该接口获得指定播放通道的丢包率。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetLostPacketRate(IN IMOS_HANDLE hXpWnd,
                                               OUT ULONG_32 *pulRecvPktNum,
                                               OUT ULONG_32 *pulLostPktNum);

/**
* 复位指定播放通道的丢包率。\n
* @param [IN] hXpWnd    播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                   未开始播放操作
* -         #ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE      复位丢包率统计失败
* @note 调用该函数后，将从复位时刻重新开始统计丢包率。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_ResetLostPacketRate(IN IMOS_HANDLE hXpWnd);

/**
* 获得指定播放通道的丢帧率。\n
* @param [IN] hXpWnd           播放窗口句柄。
* @param [OUT] pulAllFrameNum  帧总数。
* @param [OUT] pulLostFrameNum 丢弃的帧数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE  获得丢帧率数据失败
* @note
* -    在启动实况、点播回放或本地文件回放之后调用该函数获得指定播放通道的丢帧率。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetLostFrameRate(IN IMOS_HANDLE hXpWnd,
                                              OUT ULONG_32 *pulAllFrameNum,
                                              OUT ULONG_32 *pulLostFrameNum);

/**
* 复位指定播放通道的丢帧率。\n
* @param [IN] hXpWnd 播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER              播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY                   未开始播放操作
* -         #ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE    复位丢帧率失败
* @note 调用该函数后，将从复位时刻重新开始统计丢帧率。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_ResetLostFrameRate(IN IMOS_HANDLE hXpWnd);

/**
* 获得指定播放通道的帧率。\n
* @param [IN]  hXpWnd       播放窗口句柄。
* @param [OUT] pulFrameRate 帧率（单位为fps）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_FRAME_RATE       获得帧率数据失败
* @note
* -    在启动实况、点播回放或本地文件回放之后调用该函数获得指定播放通道的帧率。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetFrameRate(IN IMOS_HANDLE hXpWnd,
                                          OUT ULONG_32 *pulFrameRate);

/**
* 获得指定播放通道的码率。\n
* @param [IN]  hXpWnd     播放窗口句柄。
* @param [OUT] pulBitRate 码率（单位为bps）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_NOT_START_PLAY               未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_BIT_RATE         获得码率数据失败
* @note
* -    在启动实况或点播回放之后调用该函数获得指定播放通道的码率。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetBitRate(IN IMOS_HANDLE hXpWnd,
                                        OUT ULONG_32 *pulBitRate);
/** @} */  /* end of groupPlayerRealtime */

/** @defgroup groupPlayerPlayback 播放器点播回放
*   播放器点播回放，主要用于启停点播回放、抓图、获取媒体流参数、回放控制以及录像文件下载等。
*   @{
*/
/**
* 设置媒体流数据的传输协议。\n
* @param [IN] hXpWnd       播放窗口句柄。
* @param [IN] enTransProtl 媒体数据的传输协议。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_XP_NOT_SUPPORT_TRANSPORT_PROTOCOL_TYPE  不支持的传输层协议类型
* -         #ERR_XP_WINDOW_NOT_REGISTER                  播放窗口没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放窗口的资源失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetTransportProtocol(IN IMOS_HANDLE hXpWnd,
                                                  IN XP_NETWORK_TRANSPORT_PROTOCOL_E enTransProtl);

/**
* 设置通道的厂商信息。\n
* @param [IN] hXpWnd       播放窗口句柄。
* @param [IN] pcDecoderTag 解码器标签。目前支持的厂商解码器有："h3c-v3"表示H3C V3版本解码器。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                          成功
* -         #ERR_XP_WINDOW_NOT_REGISTER                  播放窗口没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 获得播放窗口的资源失败
* -         #ERR_COMMON_INVALID_PARAM                    输入参数无效
* @note 如果客户没有调用该函数接口，则播放器XP内各通道默认使用H3C V3版本的解码器。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetDecoderTag(IN IMOS_HANDLE hXpWnd,
                                           IN const CHAR * pcDecoderTag);

/**
* 打开点播回放媒体流。\n
* @param [IN] hXpWnd       播放窗口句柄。
* @param [IN] pcVodUrl     点播回放的URL。
* @param [IN] pcServerIP   媒体流控服务器的IP。
* @param [IN] usServerPort 媒体流控服务器的端口号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放窗口被占用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体流失败
* -         #ERR_XP_FAIL_TO_OPEN_VOD             启动点播回放业务失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenVodStream(IN IMOS_HANDLE hXpWnd,
                                           IN const CHAR *pcVodUrl,
                                           IN const CHAR *pcServerIP,
                                           IN USHORT usServerPort);

/**
* 开始播放。\n
* @param [IN] hXpWnd 播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_PORT_NOT_OPEN                未启动媒体业务
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放失败
* -         #ERR_XP_FAIL_TO_START_PLAY           开始播放失败
* @note 主要用于开始点播回放和本地文件回放。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartPlay(IN IMOS_HANDLE hXpWnd);

/**
* 倍速前进/后退播放。\n
* @param [IN] hXpWnd      播放窗口句柄。
* @param [IN] enPlaySpeed 播放的速率。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放窗口的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               指定的通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在录像
* -         #ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY   倍速前进/后退播放失败
* @note 正在本地录像时，不支持倍速前进/后退播放操作。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetPlaySpeed(IN IMOS_HANDLE hXpWnd,
                                          IN XP_PLAY_STATUS_E enPlaySpeed);

/**
* 单帧前进/后退播放。\n
* @param [IN] hXpWnd   播放窗口句柄。
* @param [IN] bForward 单帧前进或单帧后退播放（BOOL_TRUE：单帧前进，BOOL_FALSE：单帧后退）
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放窗口的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               指定的通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧播放失败
* @note 正在本地录像时，不支持单帧前进/后退播放操作。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OneStepPlay(IN IMOS_HANDLE hXpWnd,
                                         IN BOOL_T bForward);

/**
* 跳转播放。\n
* @param [IN] hXpWnd      播放窗口句柄。
* @param [IN] pcTimeStamp 跳转到的时间值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放窗口的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               指定的通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            跳转播放失败
* @note
* -     1、对于不同的应用，pcTimeStamp参数取值应不同：
* -     （1）本地文件回放时，该参数的值应为相对时间，相对于文件头的播放时间（单位为秒）。
* -     （2）点播回放时，该参数的值应为绝对时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* -     2、正在本地录像时候，不支持跳转播放操作。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_DragPlay(IN IMOS_HANDLE hXpWnd,
                                      IN const CHAR * pcTimeStamp);

/**
* 获得指定播放通道的播放进度。\n
* @param [IN]  hXpWnd       播放窗口句柄。
* @param [OUT] szCurPlayPos 存放当前播放进度的时间值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放窗口的媒体类型不支持该操作
* -         #ERR_XP_NOT_START_PLAY               指定的通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    获得当前播放进度失败
* @note
* -     szCurPlayPos参数用来存放当前播放进度的时间值，对于不同的应用其取值不同：
* -     1、本地文件回放时，该参数存放的是相对时间，即相对于文件头的播放时间（单位为秒）。
* -     2、点播回放时，该参数存放的是绝对时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetCurPlayPos(IN IMOS_HANDLE hXpWnd,
                                           OUT CHAR szCurPlayPos[IMOS_TIME_LEN]);

/**
* 启动下载媒体流。\n
* @param [IN]  pcServerIP       媒体流控服务器的IP。
* @param [IN]  usServerPort     媒体流控服务器的端口号。
* @param [IN]  pcDownUrl        需下载媒体数据源的URL。
* @param [IN]  pcFileName       下载媒体数据保存的路径，不含文件名(路径不含斜杠)。
* @param [IN]  enDownMediaSpeed 媒体数据下载速度。
* @param [OUT] szDownloadID     下载通道的ID。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      限制下载通道数
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放（下载）失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       启动媒体处理失败
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     磁盘空间不够
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       启动下载失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* -         1、该函数调用成功后，返回给用户下载通道的ID，用于标识一路下载通道。
* -         2、用户同时启动下载的最大通道数为5。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartDownMediaStream(IN const CHAR *pcServerIP,
                                                  IN USHORT usServerPort,
                                                  IN const CHAR *pcDownUrl,
                                                  IN const CHAR *pcFileName,
                                                  IN XP_DOWN_MEDIA_SPEED_E enDownMediaSpeed,
                                                  OUT CHAR szDownloadID[IMOS_RES_CODE_LEN]);

/**
* 停止下载媒体流。\n
* @param [IN] pcDownloadID 下载通道的ID。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopDownMediaStream(IN const CHAR *pcDownloadID);

/**
* 获得录像下载进度。\n
* @param [IN]    pcDownloadID 下载通道ID。
* @param [INOUT] szCurDownPos 获得的当前录像下载进度的时间值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_GET_DOWN_POSITION    获得当前下载进度失败
* @note
* -     szCurDownPos参数存放的是当前录像下载进度的绝对时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetCurDownPos(IN const CHAR *pcDownloadID,
                                           OUT CHAR szCurDownPos[IMOS_TIME_LEN]);

/**
* 停止播放。\n
* @param [IN] hXpWnd 播放窗口句柄。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_NOT_START_PLAY               未启动播放操作
* -         #ERR_XP_FAIL_TO_STOP_MEDIA           停止媒体播放处理失败
* -         #ERR_XP_FAIL_TO_STOP_PROTOCOL        停止流控协商
* -         #ERR_XP_FAIL_TO_QUIT_SESSION         退出会话失败
* -         #ERR_XP_FAIL_TO_STOP_PLAY            停止播放操作失败
* @note 主要用于停止点播回放和本地文件回放。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopPlay(IN IMOS_HANDLE hXpWnd);
/** @} */  /* end of groupPlayerPlayback */

/** @defgroup groupPlayerLocalFile 播放器本地文件回放
*   播放器本地文件回放，主要用于启停本地文件回放、抓图、获取媒体流参数和回放控制等。
*   @{
*/
/**
* 打开本地播放文件。\n
* @param [IN]  hXpWnd       播放窗口句柄。
* @param [IN]  pcFileName   本地文件的文件名（包括文件路径）。
* @param [OUT] pulTotalTime 本地文件总的时间长度。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_WINDOW_NOT_REGISTER          播放窗口没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放窗口被占用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口的资源失败
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      文件播放格式不支持
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       获得文件总的播放时间失败
* -         #ERR_XP_FAIL_TO_OPEN_FILE            启动本地文件播放失败(文件不存在或者正在被其他程序使用)
* -         #ERR_XP_FILE_DESTROY                 需要打开的文件太小或者已经损坏
* -         #ERR_COMMON_NO_MEMORY                打开文件时系统内存不足
* -         #ERR_XP_FILE_HAVE_OPEN               指定通道已经打开了文件

* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenLocalFile(IN IMOS_HANDLE hXpWnd,
                                           IN const CHAR *pcFileName,
                                           OUT ULONG_32 * const pulTotalTime);
/** @} */  /* end of groupPlayerLocalFile */

/**
* 启动语音对讲。\n
* @param [IN] pszDstResCode 语音对讲对端的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_ALREADY_OPEN                指定的通道已经启动
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* -         #ERR_XP_FAIL_TO_OPEN_VOICE_TALKBACK      启动语音对讲失败
* @note 启动到指定语音终端的语音对讲。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenVoiceTalkback(IN const CHAR *pszDstResCode);

/**
* 停止语音对讲。\n
* @param [IN] pszDstResCode 语音对讲对端的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_NOT_OPEN                    指定的通道未启动
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* @note 停止与指定语音终端的语音对讲。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_CloseVoiceTalkback(IN const CHAR *pszDstResCode);

/**
* 启动语音广播。\n
* @param [IN] pszDstResCode 语音广播对端的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_ALREADY_OPEN                指定的通道已经启动
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* -         #ERR_XP_FAIL_TO_OPEN_VOICE_BROADCAST     启动语音广播失败
* @note 启动到指定语音终端的语音广播。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenVoiceBroadcast(IN const CHAR *pszDstResCode);

/**
* 停止语音广播。\n
* @param [IN] pszDstResCode 语音广播对端的资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_NOT_OPEN                    指定的通道未启动
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* @note 停止到指定语音终端的语音广播。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_CloseVoiceBroadcast(IN const CHAR *pszDstResCode);

/** @defgroup groupPlayerVoice 播放器语音对讲和广播
*   播放器语音对讲和广播，主要用于启停语音对讲和广播、音频数据流控制和音量调节（系统音量和麦克风音量）等。
*   @{
*/
/**
* 语音业务闭音操作。\n
* @param [IN] bSilence 是否闭音（BOOL_TRUE：启用闭音，BOOL_FALSE：取消闭音）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_VOICE_SILENCE            启用/取消闭音操作失败
* @note 语音业务闭音操作是指停止向语音对端发送音频数据。目前是通过停止音频采集和编码实现此功能。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_VoiceSilence(IN BOOL_T bSilence);

/**
* 语音业务静音操作。\n
* @param [IN] bEnabled 是否静音（BOOL_TRUE：启用静音，BOOL_FALSE：取消静音）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_NOT_START_VOICE_TALKBACK         当前没有启动语音对讲业务
* -         #ERR_XP_FAIL_TO_QUIET                    启用/取消静音操作失败
* @note 无
*/
IMOS_EXPORT ULONG_32 STDCALL XP_VoiceQuiet(IN BOOL_T bEnabled);

/**
* 麦克风音量调节。\n
* @param [IN] ulVolume 音量值（取值范围为0—255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        入参无效
* -         #ERR_XP_MIC_NOT_EXIST            系统中麦克风适配不存在
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    调节音量操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_AdjustMicVolume(IN ULONG_32 ulVolume);

/**
* 获得麦克风音量值。\n
* @param [OUT] pulVolume 音量值的指针（返回的音量值范围为0—255，255为最大音量）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        入参无效
* -         #ERR_XP_MIC_NOT_EXIST            系统中麦克风适配不存在
* -         #ERR_XP_FAIL_TO_GET_VOLUME       获得音量值失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetMicVolume(OUT ULONG_32 *pulVolume);
/** @} */  /* end of groupPlayerVoice */

/**
* 初始化语音业务。\n
* @param [IN] pszVoiceID     语音业务通道ID。
* @param [IN] enVoiceSvcType 语音业务类型（语音广播或语音对讲）
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_ALREADY_EXIST               指定的通道已经存在（已经初始化）
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* @note
* -     pszVoiceID是一个字符串指针，用于唯一标识一个语音业务通道。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_InitVoiceSvc(IN const CHAR *pszVoiceID,
                                          IN XP_VOICE_SERVICE_TYPE_E enVoiceSvcType);

/**
* 设置语音业务的本地地址信息。\n
* @param [IN] pszVoiceID  语音业务ID。
* @param [IN] pszLocalIP  语音业务本地IP地址。
* @param [IN] usLocalPort 语音业务本地端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_NOT_EXIST                   指定的通道不存在（通道未初始化）
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceLocalAddr(IN const CHAR *pszVoiceID,
                                               IN const CHAR *pszLocalIP,
                                               IN USHORT usLocalPort);

/**
* 设置语音业务的远端地址信息。\n
* @param [IN] pszVoiceID   语音业务ID。
* @param [IN] pszRemoteIP  语音业务远端IP地址。
* @param [IN] usRemotePort 语音业务远端端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_NOT_EXIST                   指定的通道不存在（通道未初始化）
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceRemoteAddr(IN const CHAR *pszVoiceID,
                                                IN const CHAR *pszRemoteIP,
                                                IN USHORT usRemotePort);

/**
* 启动语音业务。\n
* @param [IN] pszVoiceID 语音业务ID。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_NOT_EXIST                   指定的通道不存在（通道未初始化）
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* -         #ERR_XP_FAIL_TO_START_VOICE_SVC          启动语音业务失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartVoiceSvc(IN const CHAR *pszVoiceID);

/**
* 停止语音业务。\n
* @param [IN] pszVoiceID 语音业务ID。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_PORT_NOT_EXIST                   指定的通道不存在（通道未初始化）
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_VOICE_SVC           停止语音业务失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopVoiceSvc(IN const CHAR *pszVoiceID);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_MEDIA_PLAYER_SDK_OBSOLETE_FUNC_H_ */