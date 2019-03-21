/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
            xp_func_inner.h

Project Code: IMOS XP播放器
Module Name: IMOS XP播放器
Date Created: 2010-04-14
Author: shiyouhua/04562
Description: 播放器XP内部接口函数头文件

--------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_MEDIA_PLAYER_SDK_INNER_FUNC_H_
#define _IMOS_XP_MEDIA_PLAYER_SDK_INNER_FUNC_H_

/* 包含基础平台的头文件*/
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"
/* 包含播放器SDK数据结构头文件 */
#include "xp_datatype.h"
#include "xp_func.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* 初始化播放器资源。\n
* @param [IN] pcBaseModuleCode 基础平台BP模块的编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* -         #ERR_COMMON_INVALID_PARAM    输入参数非法
* -         #ERR_XP_FAIL_TO_REG_BP_CMD   注册基础平台BP的命令行模块ID失败
* -         #ERR_XP_FAIL_TO_INIT_XP      初始化播放器XP资源失败
* @note
* - 使用播放器软件包首先需要调用的函数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_InitXP(IN const CHAR *pcBaseModuleCode);

/**
* 释放播放器资源。\n
* @param [IN] 无。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED          成功
* @note 退出播放器软件包最后一个需要调用函数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CleanupXP();

/**
* 注册播放器。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pstXPInfo          播放器信息结构体。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_REGIST_XP        注册播放器XP失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RegisterXP(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const XP_INFO_S *pstXPInfo);

/**
* 注销播放器。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnregisterXP(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo);

/**
* 添加播放窗格资源编码，一次可添加多个播放窗格资源编码。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pstWndCode         播放窗格编码结构体指针。
* @param [IN] ulPlayWndNum       播放窗格数量。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_EXCEED_MAX_PLAY_PORT_NUM 注册的播放通道数已超过了最大支持的播放通道数
* -         #ERR_XP_FAIL_TO_SET_PARAM        设置播放器XP的配置参数失败
* @note 一个播放窗格资源编码对应一个播放通道。对于同一个用户登陆ID，同时最多支持的播放通道数为128。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPlayWndInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const PLAY_WND_INFO_S *pstWndCode,
                                              IN ULONG_32 ulPlayWndNum);

/**
* 删除播放窗格资源编码，一次可删除多个播放窗格资源编码。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pstWndCode         播放窗格编码结构体指针。
* @param [IN] ulPlayWndNum       播放窗格数量。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeletePlayWndInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const PLAY_WND_INFO_S *pstWndCode,
                                                 IN ULONG_32 ulPlayWndNum);

/**
* 获得下载通道资源编码。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识。
* @param [IN] ulDownloadResCodeNum      下载通道数
* @param [IN] pstDownloadResCodeList    下载通道资源编码数组
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
1、SDK用户在调用IMOS_StartPlayer之后调用该接口。
2、ulDownloadResCodeNum取值小于等于32
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDownloadResCode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const ULONG_32 ulDownloadResCodeNum,
                                                  INOUT PORD_RES_CODE_INFO_S *pstDownloadResCodeList);

/**
* 单帧后退播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持此操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧后退播放失败
* @note 正在本地录像时，不支持单帧后退播放操作。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OneByOneBack(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode);

/**
* 逐帧后退播放。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体类型不支持此操作
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧后退播放失败
* @note 正在本地录像时，不支持单帧后退播放操作。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AutoOneByOneBack(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
											   IN const CHAR *pcChannelCode);											
											
											
											
/**
* 设置媒体数据流格式。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulMediaDataformat  媒体数据流格式，需从#XP_MEDIA_DATA_FORMAT_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_NOT_SUPPORT_MEDIA_STREAM_TYPE    不支持的码流类型
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaDataFormat(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulMediaDataformat);

/**
* 启动指定通道的即时回放。\n
* @param [IN] pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN] pcChannelCode            播放通道编码。
* @param [IN] pcReplayChannelCode      播放回放视频编码
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口资源失败
* -         #ERR_XP_FAIL_TO_START_REALREPLAY     开始即时回放失败
* @note     pcReplayChannelCode 的资源编码应为有效的通道编码
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartRealReplay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcReplayChannelCode);

/**
* 设置指定通道的即时回放时长。\n
* @param [IN] pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN] pcChannelCode            播放通道编码。
* @param [IN] ulTime                   即时回放时长。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            通道没有注册
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        播放通道的媒体业务类型不支持此操作
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放窗口资源失败
* -         #ERR_XP_SET_REALREPLAY_TIME_LARGE    即时回放设置时间太长
* @note     时间取值范围[0 - 60]s
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRealReplayTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN ULONG_32 ulTime);

/**
* 设置网络媒体流的端口范围。\n
* @param [IN] usMinPort            起始端口。
* @param [IN] usMaxPort            结束端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* @note
* -    1、范围包括设置的端口。
* -    2、在调用 IMOS_InitXP之前调用。
* -    3、入参均为零时或不调用时，采用默认值。
* -    4、默认值范围为32768～65535之间的偶数。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaPortRange(IN USHORT usMinPort,
                                                 IN USHORT usMaxPort);

/**
* 设置信令的端口范围。\n
* @param [IN] usMinPort         起始端口。
* @param [IN] usMaxPort         结束端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* @note
* -    1、范围包括设置的端口。
* -    2、在调用 IMOS_InitXP之前调用。
* -    3、入参均为零时或不调用时，采用默认值。
* -    4、默认值范围为6001～10000。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetProtlPortRange(IN USHORT usMinPort,
                                                 IN USHORT usMaxPort);
/**
* 启动下载媒体流备份，将接收到的媒体流数据回调给用户。\n
* @param [IN]  pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN]  pcDownUrl                需下载媒体数据源的URL。
* @param [IN]  pcServerIP               媒体流控服务器的IP。
* @param [IN]  usServerPort             媒体流控服务器的端口号。
* @param [IN]  ulProtl                  接收媒体流的协议类型，需从tagProtocol枚举中取值（保留，目前仅支持TCP协议）。
* @param [IN]  ulDownMediaSpeed         媒体数据下载速度，需从tagDownMediaSpeed枚举中取值。
* @param [IN]  pfnSourceMediaDataCBFun  下载媒体流数据回调函数的指针。
* @param [IN]  lUserParam               用户设置参数。
* @param [OUT] pcDownloadID             下载通道号，缓冲区长度应不小于#IMOS_RES_CODE_LEN。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      限制下载通道数
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放（下载）失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       启动媒体处理失败
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       启动下载失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note
* -         1、该函数调用成功后，返回给用户下载通道号，用于标识一路下载通道。
* -         2、最大同时支持启动32路下载通道。
* -         3、目前仅支持TCP协议下载媒体流。
* -         4、停止媒体流下载备份须调用#IMOS_StopDownMediaStreamCallback接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownMediaStreamCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN const CHAR *pcDownUrl,
                                                            IN const CHAR *pcServerIP,
                                                            IN USHORT usServerPort,
                                                            IN ULONG_32 ulProtl,
                                                            IN ULONG_32 ulDownMediaSpeed,
                                                            IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                            IN LONG_REAL lUserParam,
                                                            OUT CHAR *pcDownloadID);

/**
* 停止下载媒体流备份。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownloadID        下载通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note 该接口与#IMOS_StartDownMediaStreamCallback接口匹配。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownMediaStreamCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                           IN const CHAR *pcDownloadID);

/**
* 打开媒体流下载，支持TS流和其它媒体流下载，将下载的媒体流保存为指定的格式。下载录像文件名全部由用户指定。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcChannelCode       下载通道资源编码。
* @param [IN]  pcDownUrl           要下载录像文件的URL。
* @param [IN]  pcServerIP          媒体流控服务器的IP。
* @param [IN]  usServerPort        媒体流控服务器的端口号。
* @param [IN]  ulProtl             接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值（目前仅支持TCP协议）。
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
* -    1、最大同时支持启动32路下载通道。
* -    2、目前仅支持TCP协议下载媒体流。
* -    3、打开媒体流下载后，需调用IMOS_StartDownloadEx接口开始下载，停止下载时调用IMOS_StopDownload接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadEx2(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcDownUrl,
                                               IN const CHAR *pcServerIP,
                                               IN USHORT usServerPort,
                                               IN ULONG_32 ulProtl);


/**
* 打开媒体流下载，支持TS流和其它媒体流下载，将下载的媒体流保存为指定的格式。下载录像文件名全部由用户指定。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownUrl           要下载录像文件的URL。
* @param [IN]  pcServerIP          媒体流控服务器的IP。
* @param [IN]  usServerPort        媒体流控服务器的端口号。
* @param [IN]  ulProtl             接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值（目前仅支持TCP协议）。
* @param [IN]  ulDownMediaSpeed    媒体数据下载速度，需从#XP_DOWN_MEDIA_SPEED_E枚举中取值。
* @param [OUT]  pcChannelCode      下载通道资源编码。
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
* -    1、最大同时支持启动32路下载通道。
* -    2、目前仅支持TCP协议下载媒体流。
* -    3、打开媒体流下载后，需调用IMOS_StartDownloadEx接口开始下载，停止下载时调用IMOS_StopDownload接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadEx3(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcDownUrl,
                                                  IN const CHAR *pcServerIP,
                                                  IN USHORT usServerPort,
                                                  IN ULONG_32 ulProtl,
                                                  IN ULONG_32 ulDownMediaSpeed,
                                                  OUT CHAR *pcChannelCode);

/**
* 暂停下载。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          暂停媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       流控协商暂停失败
* -         #ERR_XP_FAIL_TO_PAUSE                暂停播放操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PauseDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode);

/**
* 恢复下载。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      下载资源编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放失败
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         恢复媒体播放处理失败
* -         #ERR_XP_FAIL_TO_RESUME               恢复播放操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResumeDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode);



/**
* 开始播放（扩展接口：可以指定起始播放时间和播放速率参数）。
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcTime             设置文件播放位置到指定时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @param [IN] ulPlaySpeed        播放速率，需从tagPlayStatus枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_PORT_NOT_OPEN                指定的播放通道未启动媒体业务
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        流控协商播放失败
* -         #ERR_XP_FAIL_TO_START_PLAY           开始播放失败
* @note
* 1、该接口在用户设置的录像时间点启动指定倍速播放点播回放，用于规避启动即时回放后图片OSD乱的问题。
* 2、SDK用户在调用#IMOS_OpenVodStream之后调用该接口，替代#IMOS_StartPlay。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlayEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           IN const char *pcTime,
                                           IN ULONG_32 ulPlaySpeed);


/**
* 设置指定通道的数字放大功能。\n
* @param [IN] pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN] pcChannelCode            播放通道编码。
* @param [IN] hWnd                     画中画句柄,hWnd = #IMOS_INVALID_HANDLE表示关闭，非#IMOS_INVALID_HANDLE表示开启
* @param [IN] pstRect                  原始图像区域坐标，pstRect = NULL为全部显示，该坐标值为区域在图像中的百分比值
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_NOT_SUPPORT                  不支持该功能
* -         #ERR_XP_FAIL_TO_SET_DIGITALZOOM      设置电子放大失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDigitalZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN IMOS_HANDLE hWnd,
                                              IN XP_RECT_S *pstRect);

/**
* 获取图像大小。\n
* @param [IN] pstUserLoginIDInfo       用户登录ID信息标识。
* @param [IN] pcChannelCode            播放通道编码。
* @param [OUT] pulWidth                图像的宽
* @param [OUT] pulHeight               图像的长
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_GET_PIC_PARAM        获得当前通道解码后图片长宽信息失败
* -         #ERR_COMMON_INVALID_PARAM            参数错误
* @note
* - 1、该接口函数仅支持Windows。
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPicSize(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          OUT ULONG_32 *pulWidth,
                                          OUT ULONG_32 *pulHeight);

/**
* 启动UDP包乱序整理功能。\n
* @param [IN] bAdjust                  是否启动乱序整理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_SET_PARAM            设置播放器的配置参数失败
* @note
* -  1、当前只支持UDP+TS中的视频包乱序功能
* -  2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustPktSeq(IN BOOL_T bAdjust);


/**
* 对指定通道做图（不规则区域）
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pcChannelCode            播放通道编码
* @param [IN] pDrawHandle              画图句柄
* @param [IN] ulNum                    不规则区域顶点个数，最大为6
* @param [IN] pointArry                坐标地址
* @param [IN] ulDir                    方向，需从#IMOS_AREA_DIRECTION_E枚举中取值。
* @param [IN] ulColor                  线条颜色
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT VOID STDCALL IMOS_PolylineTo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN IMOS_HANDLE pDrawHandle,
                                         IN ULONG_32 ulNum,
                                         IN XP_POINT_S *pointArry,
                                         IN ULONG_32 ulDir,
                                         IN ULONG_32 ulColor);

/**
* 对指定通道做图（不规则区域）
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pcChannelCode            播放通道编码
* @param [IN] pDrawHandle              画图句柄
* @param [IN] ulNum                    不规则区域顶点个数，最大为6
* @param [IN] pointArry                坐标地址
* @param [IN] ulWidth                  线条宽度
* @param [IN] ulColor                  线条颜色
* @return 无
*/
IMOS_EXPORT VOID STDCALL IMOS_PolylineToWindow(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN IMOS_HANDLE pDrawHandle,
                                         IN ULONG_32 ulNum,
                                         IN XP_POINT_S *pointArry,
                                         IN ULONG_32 ulWidth,
                                         IN ULONG_32 ulColor);


/**
* 对指定通道做图（阴影线）
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] pDrawHandle              画图句柄
* @param [IN] pstStart                 直线起点
* @param [IN] pstEnd                   直线终点
* @param [IN] ulDir                    线条方向,需从#IMOS_THRU_LINE_DIRECTION_E枚举中取值。
* @param [IN] ulColor                  线条颜色
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT VOID STDCALL IMOS_DLineTo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                      IN const CHAR *pcChannelCode,
                                      IN IMOS_HANDLE pDrawHandle,
                                      IN const XP_POINT_S *pstStart,
                                      IN const XP_POINT_S *pstEnd,
                                      IN ULONG_32 ulDir,
                                      IN ULONG_32 ulColor);
/**
* 对指定通道做图（阴影线）
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] pDrawHandle              画图句柄
* @param [IN] pstStart                 直线起点
* @param [IN] pstEnd                   直线终点
* @param [IN] ulDir                    线条方向,需从#IMOS_THRU_LINE_DIRECTION_E枚举中取值。
* @param [IN] ulColor                  线条颜色
* @return 无
* @note
* - 1、该接口函数仅支持Windows。#IMOS_DLineTo指标单位为1%, #IMOS_DLineToEx坐标单位为0.01%
*/
IMOS_EXPORT VOID STDCALL IMOS_DLineToEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN IMOS_HANDLE pDrawHandle,
                                        IN const XP_POINT_S *pstStart,
                                        IN const XP_POINT_S *pstEnd,
                                        IN ULONG_32 ulDir,
                                        IN ULONG_32 ulColor);
/**
* 对指定通道做图（箭头线）
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] pDrawHandle              画图句柄
* @param [IN] pstStart                 直线起点
* @param [IN] pstEnd                   直线终点
* @param [IN] ulDir                    线条方向,需从#IMOS_THRU_LINE_DIRECTION_E枚举中取值。
* @param [IN] ulColor                  线条颜色
* @return 无
* @note
* - 1、该接口函数仅支持Windows。坐标单位为0.01%
*/
IMOS_EXPORT VOID STDCALL IMOS_DrawLineWithArrow(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
												IN const CHAR *pcChannelCode,
												IN IMOS_HANDLE pDrawHandle,
												IN const XP_POINTEX_S *pstStart,
												IN const XP_POINTEX_S *pstEnd,
												IN ULONG_32 ulDir,
												IN ULONG_32 ulColor);

/**
* 获取画图句柄
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @return 返回如下结果：
* - 成功：IMOS_HANDLE
* - #
* - 失败：IMOS_INVALID_HANDLE
* -
* @note
* - 1、需要在视频上做图，首先需要调用#IMOS_GetHVDC获取HVDC，才可以做图并显示；调用#IMOS_ReleaseHVDC取消做图数据显示
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT IMOS_HANDLE STDCALL IMOS_GetHVDC(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode);

/**
* 释放画图句柄
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] pDrawHandle              通过IMOS_GetHVDC获取的句柄
* @return 返回如下结果：
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT VOID STDCALL IMOS_ReleaseHVDC(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          IN IMOS_HANDLE pDrawHandle);
/**
* 开始做图
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码。
* @param [IN] pDrawHandle              画图句柄
* @param [IN] pverBer                  保留参数
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER           播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_BEGINHVDC           开始画图失败
* @note
* - 1、图像上画线，首先需要在#IMOS_BeginDraw和#IMOS_EndDraw之间操作，其他操作无效
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BeginDraw(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN IMOS_HANDLE pDrawHandle,
                                         IN VOID *pverBer);

/**
* 完成做图
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] pDrawHandle              画图句柄
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT VOID STDCALL IMOS_EndDraw(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                      IN const CHAR *pcChannelCode,
                                      IN IMOS_HANDLE pDrawHandle);

/**
* 设置解码端智能规则显示使能
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] ulMethod                 输入解码端信息叠加方法信息
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER           播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERULE   设置显示智能规则失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShowAnalyseRule(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const BOOL_T bEnable );

/**
* 设置解码端智能结果显示使能
* @param [IN] pstUserLogIDInfo         用户登录ID信息标识
* @param [IN] pstChannelIndex          播放通道编码
* @param [IN] ulMethod                 输入解码端信息叠加方法信息
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER           播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERESULT 设置显示智能结果失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShowAnalyseResult(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const BOOL_T bEnable );
/**
* 检测运行系统的硬件参数
* @param [IN] 无。
* @return 返回#XP_HW_STATUS_E枚举类型的参数
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckHWValidate();

/**
* 启动图像拼接操作。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放图像拼接视频的通道编码
* @param [IN] pcCombineResCode          图像拼接资源编码
* @param [IN] lCombineStreamNum         图像拼接的通道数目
* @param [IN] ppcNeedCombineChannelCode 图像拼接的通道编码数组
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      启动图像拼接成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_START_COMBINE_IMAGE      启动图像拼接操作失败
* @note
* - 1、当前只支持3个通道的资源拼接
* - 2、拼接前需要预先打开需要拼接的视频播放业务
* - 3、ppcNeedCombineChannelCode为数组
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCombineVideo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const CHAR *pcCombineResCode,
                                                 IN const LONG_32 lCombineStreamNum,
                                                 IN const CHAR **ppcNeedCombineChannelCode);

/**
* 停止图像拼接操作。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             图像拼接资源编码
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_IMAGE   停止图像拼接操作失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCombineVideo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode);

/**
* 标定图像拼接特征点。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcCombineResCode          图像拼接资源编码
* @param [IN] lCombineStreamNum         图像拼接资源通道数目
* @param [IN] plCombinPointNum          相邻图像特征点数目的数组
* @param [IN] plCombinPointVal          用户设置拼接图像特征点值数组
* @param [IN] lReserve                  保留值，后续作拼接模式使用，当前填写0
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_MARK_COMBINE_IMAGE   标定特征点失败
* @note
* - 标识为数组各值需要连续存放
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MarkCombinePoint(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcCombineResCode,
                                                IN LONG_32 lCombineStreamNum,
                                                IN LONG_32 *plCombinPointNum,
                                                IN LONG_32 *plCombinPointVal,
                                                IN LONG lReserve);

/**
* 启动视频图像电子放大功能。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放电子放大视频的通道编码
* @param [IN] pcCombineResCode          图像拼接资源编码
* @param [IN] pstCombineZoomRect        电子放大区域信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_START_COMBINE_ZOOM   启动电子放大失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCombineZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                IN const CHAR *pcCombineResCode,
                                                IN const XP_COMBINE_ZOOM_RECT_S *pstCombineZoomRect);

/**
* 修改电子放大区域信息。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放电子放大视频的通道编码
* @param [IN] pcCombineResCode          图像拼接资源编码
* @param [IN] pstCombineZoomRect        电子放大区域信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_MOVE_COMBINE_ZOOM    修改电子放大区域信息失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MoveCombineZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcCombineResCode,
                                               IN const XP_COMBINE_ZOOM_RECT_S *pstCombineZoomRect);

/**
* 关闭视频图像电子放大功能 \n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放电子放大视频的通道编码
* @param [IN] pcCombineResCode          图像拼接资源编码
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_ZOOM    关闭电子放大功能失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCombineZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcCombineResCode);




/**
* 判断是否为DB33解码标准接入。\n
* @param [IN] pcDecodetag    decodetag信息
* @return #BOOL_TRUE：是DB33解码插件标准接入； #BOOL_FALSE：非DB33解码插件标准接入
* @note 无
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_IsDB33Decodetag(IN const CHAR *pcDecodetag);


/**
* 设置解码模式 \n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放的通道编码
* @param [IN] ulMode                    解码模式 0 代表软解模式
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* @note
* - 1、该接口函数仅支持Windows。
* - 2、该接口为实验性接口，会导致程序稳定性下降，不推荐用户使用。
* - 3、该函数返回成功失败
* - 4、该接口可以和IMOS_XP_SetTransParam配合使用
* - 5、如果GPU 支持，那么默认输出yuv为 cif ，2cif ，d1 ，和原始大小。具体由播放窗格大小决定
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoDecodeMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN ULONG_32 ulMode);

/**
* 影像调节\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放通道编码
* @param [IN] pstAdjust                 影像调节参数
* @param [IN] bOpen                     是否打开影像调节
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER           播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_SET_VIDEO_ADJUST    设置影像调节失败
* @note
* -    1、默认不启动影像调节。
* -    2、对比度取值范围为[0--199]，默认值为100；
* -       亮度取值范围为[0--199]，默认值为100；
* -       色调取值范围为[0--359]，默认值为0；
* -       饱和度取值范围为[0--359]，默认值为100；
* -       伽玛取值范围为[0--99]，默认值为10。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN const XP_VIDEO_ADJUST_S *pstAdjust,
                                              IN BOOL_T bOpen);

/**
* 模糊处理\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放通道编码
* @param [IN] ulFactor                  模糊处理参数
* @param [IN] bOpen                     是否启动模糊处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_VIDEO_MONITOR_BLUR  设置模糊处理失败
* @note
* -    1、默认不启动模糊处理。
* -    2、模糊处理参数取值范围为[1--127]，默认值为80。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoMotionBlur(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulFactor,
                                                  IN BOOL_T bOpen);

/**
* 锐化处理\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放通道编码
* @param [IN] fSigma                    锐化处理参数
* @param [IN] bOpen                     是否启动锐化处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_VIDEO_SHARPEN       设置锐化处理失败
* @note
* -    1、默认不启动锐化处理。
* -    2、锐化处理参数取值范围为[0.0--2.0]，默认值为0.05。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoSharpen(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN FLOAT fSigma,
                                               IN BOOL_T bOpen);

/**
* 去雾处理\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放通道编码
* @param [IN] ulLowValue                暗区调节参数
* @param [IN] ulHighValue               亮区调节参数
* @param [IN] bOpen                     是否启动去雾处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_DE_FOG              设置去雾处理失败
* @note
* -    1、默认不启动去雾处理。
* -    2、去雾处理参数1取值范围为[0--49]，默认值为0；
* -       去雾处理参数2取值范围为[51--100]，默认值为100。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDeFog(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN ULONG_32 ulLowValue,
                                        IN ULONG_32 ulHighValue,
                                        IN BOOL_T bOpen);

/**
* 设置码流丢包情况下拼帧策略。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] ulDataLostSplitterPolicy 码流丢包情况下拼帧策略，需从#XP_MEDIA_DATA_LOST_SPLITTER_POLICY枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* @note
* - 1、码流丢包情况下默认不继续拼帧
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaDataLostSplitterPolicy(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN ULONG_32 ulDataLostDecodePolicy);

/**
* 防闪烁处理\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识
* @param [IN] pcChannelCode             播放通道编码
* @param [IN] ulWinSize                 参考帧数
* @param [IN] ulSoftenVal               帧间滤波参数
* @param [IN] bOpen                     是否启动防闪烁处理处理
* @return 返回如下错误码：
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_ANTI_FLICKER        设置防闪烁处理失败
* @note
* -    1、默认不启动去雾处理。
* -    2、ulWinSize取值范围为[0--100]；
* -       ulSoftenVal取值范围为[0--30]。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAntiFlicker(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN ULONG_32 ulWinSize,
                                              IN ULONG_32 ulSoftenVal,
                                              IN BOOL_T bOpen);

/**
* 设置图象的对比度参数。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulContrastMode     图象对比度模式，需从#XP_PICTURE_CONTRAST_MODE_E枚举中取值。
* @param [IN] ulContrastLevelEx  图象对比度级别，需从#XP_PICTURE_CONTRAST_LEVEL_EX_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER        播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST 播放通道不支持设置图象对比度参数
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     设置图象对比度参数失败
* @note
* -    1、在不调用该接口的情况下，视频图像默认不进行对比度调节处理。
* -    2、可以在开始播放#IMOS_StartPlay之前设置，但设置的对比度参数被保存，作为启动该通道播放时
* -       的初始值；在开始播放后调用该接口设置的对比度参数即时起作用。
* -    3、调用该接口对指定播放通道设置的对比参数在播放器运行期间一直有效；当参数ulContrastMode
* -       传入#XP_PICTURE_CONTRAST_MODE_NONE时，即停止对比度调节处理，此时ulContrastLevel传入的
* -       值无效。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPictureContrastEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN ULONG_32 ulContrastMode,
                                                    IN ULONG_32 ulContrastLevelEx);

/**
* 启动指定抓拍数目的连续实时抓拍。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         图像文件存放的路径，包括文件名（不带扩展名）。
* @param [IN] ulPicFormat        图像文件的格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] ulInterval         抓拍间隔，单位为毫秒 ; 0xFFFFFFFF 表示抓拍每个I帧
* @param [IN] ulCount            抓拍数目（取值大于0）。
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartSnatchSeriesEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN const CHAR *pcFileName,
                                                   IN ULONG_32 ulPicFormat,
                                                   IN ULONG_32 ulInterval,
                                                   IN ULONG_32 ulCount);

/**
* 启动一个文件中多段录像合并成一个ts文件。\n
* @param [IN] pacFileName 输入文件首地址。
* @param [IN] ulBeginTime   开始拼接的时间(ms)。
* @param [IN] ulEndTime   结束拼接的时间(ms)。
* @param [IN] ulJointCount 拼接块的个数。
* @param [IN] pcJointFileName   输出文件名。
* @param [OUT] pulJointErrNumber   出错的时间段的序号，从0开始。
* @param [OUT] pstFileJointInfo     拼接文件信息。
* @return 返回如下错误码：
*          ERR_COMMON_SUCCEED           文件合并成功
*          ERR_COMMON_INVALID_PARAM     参数错误
*          ERR_COMMON_NO_MEMORY         系统没有足够的内存
*          ERR_XP_FILE_HAVE_OPEN        文件已经打开。
*          ERR_XP_FILE_DESTROY          TS媒体文件已经损坏
*          ERR_XP_FAIL_TO_JOIN_FILE     文件合并出错

* @note
* -    1、只支持TS文件的合并操作。
* -    2、函数为阻塞式，即在合并完成之后才会返回。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMultiSectionJoint(IN const CHAR *pcFileName,
                                                      IN ULONG_32 aulBeginTime[],
                                                      IN ULONG_32 aulEndTime[],
                                                      IN ULONG_32 ulJointCount,
                                                      IN CHAR *pcJointFileName,
                                                      OUT ULONG_32 *pulJointErrNumber,
                                                      OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* 启动多个ts文件合并成一个ts文件。\n
* @param [IN] pacFileName 输入文件数组首地址。
* @param [IN] ulFileNum   输入文件个数。
* @param [IN] pcJointFileName   输出文件名。
* @param [OUT] pulJointErrNumber   出错的文件的序号，从0开始。
* @param [OUT] pstFileJointInfo     拼接文件信息。
* @return 返回如下错误码：
*          ERR_COMMON_SUCCEED           文件合并成功
*          ERR_COMMON_INVALID_PARAM     参数错误
*          ERR_COMMON_NO_MEMORY         系统没有足够的内存
*          ERR_XP_FILE_HAVE_OPEN        文件已经打开。
*          ERR_XP_FILE_DESTROY          TS媒体文件已经损坏
*          ERR_XP_FAIL_TO_JOIN_FILE     文件合并出错
* @note
* -    1、只支持TS文件的合并操作。
* -    2、函数为阻塞式，即在合并完成之后才会返回。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMultiFileJoint(IN CHAR *pacFileName[],
                                                   IN ULONG_32 ulFileNum,
                                                   IN CHAR *pcJointFileName,
                                                   OUT ULONG_32 *pulJointErrNumber,
                                                   OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* 创建TS码流合并成文件。\n
* @param [IN] pcJointFileName       输出文件名。
* @param [OUT] pulHandle            合成句柄。
* @return 返回如下错误码：
*          ERR_COMMON_SUCCEED           文件合并成功
*          ERR_COMMON_INVALID_PARAM     参数错误
*          ERR_COMMON_NO_MEMORY         没有足够的内存
*          ERR_XP_FILE_HAVE_OPEN        文件已经打开
*          ERR_XP_FAIL_TO_JOIN_FILE     文件合并失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateTsDataJointFile(IN const CHAR *pcJointFileName, OUT ULONG_REAL *pulHandle);

/**
* 输入TS码流进行合并成文件。\n
* @param [IN] ulHandle          句柄。
* @param [IN] pucDataBuf        码流数据。
* @param [IN] ulDataLen         码流长度。
* @param [IN] ulMode            合并模式，XP_TSJOINT_MODE_E
* @return 返回如下错误码：
*          ERR_COMMON_SUCCEED           文件合并成功
*          ERR_COMMON_INVALID_PARAM     参数错误
*          ERR_COMMON_NO_MEMORY         系统没有足够的内存
*          ERR_XP_FAIL_TO_JOIN_FILE     文件合并出错
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_JointTsDataToFile(IN ULONG ulHandle, IN UCHAR *pucDataBuf, IN ULONG_32 ulDataLen,IN ULONG_32 ulMode);

/**
* 关闭TS码流合并成文件。\n
* @param [IN] ulHandle              句柄。
* @param [OUT] pstFileJointInfo     拼接文件信息。
* @return 返回如下错误码：
*          ERR_COMMON_SUCCEED           文件合并成功
*          ERR_COMMON_INVALID_PARAM     参数错误
*          ERR_XP_FAIL_TO_JOIN_FILE     文件合并出错
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CloseTsDataJointFile(IN ULONG ulHandle, OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* 设置转码后的媒体流数据回调函数。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [IN] pfnTranscodeMediaDataCBFun 转码后的媒体流数据回调函数的指针。
* @param [IN] pstParam                编码参数
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
*      #IMOS_StartMonitor之前或者之后需要重新设置；点播回放时，该函数可在#IMOS_OpenVodStream之前调用，也可
*      在#IMOS_OpenVodStream和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自
*      动失效，下次启动点播回放时需要在相同位置重新设置；本地回放时，该函数可在#IMOS_OpenFile之前调用，
*      也可在#IMOS_OpenFile和#IMOS_StartPlay之间调用，还可以在#IMOS_StartPlay之后调用。
* - 2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针#XP_TRANSCODE_MEDIA_DATA_CALLBACK_PF设为NULL；
* - 3、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTranscodeMediaDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode,
                                                       IN XP_TRANSCODE_MEDIA_DATA_CALLBACK_PF pfnTranscodeMediaDataCBFun,
                                                       IN const XP_ENCODE_PARAM_S *pstParam,
                                                       IN BOOL_T bContinue,
                                                       IN LONG_REAL lUserParam);


/**
* 单次区域实时抓拍，播放器将在用户指定的的文件名后附加抓拍系统时间。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         要保存的图像文件的文件名（不带扩展名）；文件名全部由用户指定。
* @param [IN] ulPicFormat        图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] pstRect            指定区域抓拍
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
* -   1. 播放器将在用户指定的文件名后面附加类似于"20080928(13-10-50-99)"格式的抓拍系统时间。
* -   2. pstRect为NULL时，指定抓拍整幅图像。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchRegion(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN const CHAR *pcFileName,
                                            IN ULONG_32 ulPicFormat,
                                            IN const XP_RECT_S *pstRect);

/**
* 单次区域实时抓拍，文件名全部由用户指定。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         要保存的图像文件的文件名（不带扩展名）；文件名全部由用户指定。
* @param [IN] ulPicFormat        图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] pstRect            指定区域抓拍
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
* -   1. 文件名全部由用户指定，用户需确保在同一抓拍保存路径下，抓拍图像文件名不能重名。
* -   2. pstRect为NULL时，指定抓拍整幅图像。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchRegionEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN const CHAR *pcFileName,
                                              IN ULONG_32 ulPicFormat,
                                              IN const XP_RECT_S *pstRect);

/**
* 设置点播回放的起始时间。
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcTime             时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   设置开始时间和结束时间失败
* @note
* 1、SDK用户在调用#IMOS_OpenVodStream之后和#IMOS_StartPlay之前调用该接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVodBeginTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const char *pcTime);

/**
* 设置点播回放的终止时间。
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcTime             时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   设置开始时间和结束时间失败
* @note
* 1、SDK用户在调用#IMOS_OpenVodStream之后和#IMOS_StartPlay之前调用该接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVodEndTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const char *pcTime);

/**
* 设置下载的起始时间。
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcTime             时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   设置开始时间和结束时间失败
* @note
* 1、SDK用户在调用#IMOS_OpenDownloadEx之后和#IMOS_StartDownloadEx之前调用该接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadBeginTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN const char *pcTime);

/**
* 设置下载的终止时间。
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcTime             时间（时间格式为：yyyy-mm-dd hh:mm:ss）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   设置开始时间和结束时间失败
* @note
* 1、SDK用户在调用#IMOS_OpenDownloadEx之后和#IMOS_StartDownloadEx之前调用该接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadEndTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN const char *pcTime);
/**
* 绑定一个球机到指定枪球联动资源。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源编码
* @param [IN] pcBallCameraResCode   球机资源编码
* @param [IN] pstBallLoginInfo      球机登录信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindBallCamera(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN const XP_BALL_LOGIN_INFO_S *pstBallLoginInfo);
/**
* 对枪球资源进行标定。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源编码
* @param [IN] pcBallCameraResCode   球机资源编码
* @param [IN] pstBallMarkPoint      球机标定信息
* @param [IN] pstOffsetMatchParam   机芯偏移信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MarkBallCamera(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN const XP_BALL_MARK_POINT_S *pstBallMarkPoint,
											  IN const XP_BL_OFFSET_MATCHPARAM_S *pstOffsetMatchParam, 
											  IN const DOUBLE dfocalLength);

/**
* 进行电子拉框放大 \n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源
* @param [IN] pcBallCameraResCode   球机资源
* @param [IN] pstCameraZoomArea     放大区域
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallRectZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcBallLinkageResCode,
                                            IN const CHAR *pcBallCameraResCode,
											IN const XP_CAMERA_ZOOMAREA_S *pstCameraZoomArea, 
											IN const DOUBLE dfocalLength);

/**
* 球机转动到预置位\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源
* @param [IN] pcBallCameraResCode   球机资源
* @param [IN] ulPresetID     预置位编号
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallSetPreset(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcBallLinkageResCode,
                                             IN const CHAR *pcBallCameraResCode,
                                             IN ULONG_32 ulPresetID);

/**
* 获取当前球机位置信息\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源
* @param [IN] pcBallCameraResCode   球机资源
* @param [OUT] pstAbsZoom            放大倍率信息
* @param [OUT] pstAbsPosition        经纬度信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallGetStatus(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcBallLinkageResCode,
                                             IN const CHAR *pcBallCameraResCode,
                                             OUT XP_PTZ_ABSZOOM_S *pstAbsZoom,
                                             OUT XP_PTZ_ABSPOSITION_S *pstAbsPosition);

/**
* 设置球机位置信息\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源
* @param [IN] pcBallCameraResCode   球机资源
* @param [IN] pstAbsZoom            放大倍率信息
* @param [IN] pstAbsPosition        经纬度信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallGotoPreset(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN XP_PTZ_ABSZOOM_S *pstAbsZoom,
                                              IN XP_PTZ_ABSPOSITION_S *pstAbsPosition);

/**
* 进行球机命令的控制\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源
* @param [IN] pcBallCameraResCode   球机资源
* @param [IN] ulPTZCmdID            命令码
* @param [IN] lPTZCmdPara1          参数1
* @param [IN] lPTZCmdPara2          参数2
* @param [IN] lPTZCmdPara3          参数3
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallPtzCommand(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN const ULONG_32 ulPTZCmdID,
                                              IN const LONG_32  lPTZCmdPara1,
                                              IN const LONG_32  lPTZCmdPara2,
                                              IN const LONG_32  lPTZCmdPara3);


/**
* 将球机解绑定\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcBallLinkageResCode  枪球联动资源
* @param [IN] pcBallCameraResCode   球机资源
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DetachBallCamera(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcBallLinkageResCode,
                                                IN const CHAR *pcBallCameraResCode);

/**
* 数据回调函数的指针类型。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pBuffer               存放媒体流数据缓冲区指针。
* @param [IN] ulBufSize             缓冲区大小。
* @param [IN] lUserParam            用户设置参数
* @param [IN] lReserved1            保留参数1
* @param [IN] lReserved2            保留参数2
* @return 无。
* @note
* -     用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_MEDIA_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN const UCHAR *pBuffer,
                                                  IN ULONG_32 ulBufSize,
                                                  IN LONG_REAL lUserParam,
                                                  IN LONG_REAL lReserved1,
                                                  IN LONG_REAL lReserved2);

/**
* 设置转封装成TS码流输出的回调函数指针。\n
* @param [IN] pstUserLoginIDInfo            用户登录ID信息标识。
* @param [IN] pcChannelCode                 播放通道编码。
* @param [IN] pfnMediaDataCallback          媒体流数据回调函数的指针。
* @param [IN] lUserParam                    用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* - 1、在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自动失效
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTsDataOutputCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN XP_MEDIA_DATA_CALLBACK_PF pfnMediaDataCallback,
                                                 IN LONG_REAL lUserParam);

/**
* 获取某个通道的媒体流收流信息。\n
* @param [IN] pstUserLoginIDInfo            用户登录ID信息标识。
* @param [IN] pcChannelCode                 播放通道编码。
* @param [OUT] pcMediaReceiveIp             媒体流收流IP地址
* @param [OUT] pusMediaReceivePort          媒体流收流端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
* - 1、在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自动失效
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMediaReceiveInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   OUT CHAR *pcMediaReceiveIp,
                                                   OUT USHORT *pusMediaReceivePort);

/**
* 启动与关闭媒体流防串流功能。\n
* @param [IN] pstUserLoginIDInfo            用户登录ID信息标识。
* @param [IN] pcChannelCode                 播放通道编码。
* @param [IN] bOpen                         是否开启防串流功能
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
* - 1、在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自动失效
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCrossStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN const BOOL_T bOpen);

/**
* 打开本地播放文件（建立文件索引）。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcFileName         本地文件的文件名（包括文件路径）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道的资源失败
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      文件播放格式不支持
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       获得文件总的播放时间失败
* -         #ERR_XP_FAIL_TO_OPEN_FILE            启动本地文件播放失败(文件不存在或者正在被其他程序使用)
* -         #ERR_XP_FILE_DESTROY                 需要打开的文件太小或者已经损坏
* -         #ERR_COMMON_NO_MEMORY                打开文件时系统内存不足
* -         #ERR_XP_FILE_HAVE_OPEN               指定通道已经打开了文件
* @note。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenFileBuildIndex(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN const CHAR *pcFileName);
/**
* 设置转码解码参数（内部接口）。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pstPicDimension         转码后视频图像分辨率信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         ERR_COMMON_INVALID_PARAM                 输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTransParam(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN const XP_TRANS_PARAM_S *pstPicDimension);

/**
* 打开点播回放媒体流（媒体流处理流程中不丢数据，提供给IA进行高倍速智能分析）。\n
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodStreamEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcVodUrl,
                                               IN const CHAR *pcServerIP,
                                               IN USHORT usServerPort,
                                               IN ULONG_32 ulProtl);

/**
* 设置播放或下载时的音频声道，默认为左声道。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] ulSoundChannel     音频声道选择，需从#XP_AUDIO_CHANNEL_E枚举中取值

* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                入参无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_PUBLIC_NOT_SUPPORT_SERVICE          业务类型不支持
* -         #ERR_XP_NOT_START_PLAY                   播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_SET_AUDIO_CHANNEL        设置音频声道失败
* -         #ERR_XP_FAIL_NO_RIGHT_AUDIO_CHANNEL      音频没有右声道
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSoundChannel(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode, IN ULONG_32 ulSoundChannel);

/**
* 启动抗丢包功能。\n
* @param [IN] bResistLost                  是否启动抗丢包
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_SET_PARAM            设置播放器的配置参数失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResistLost(IN BOOL_T bResistLost);

/**
* 设置录像数据类型\n
* @param [IN] pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN] pcChannelCode      下载资源编码。
* @param [IN] enMediaType              见枚举值
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
            其他见具体错误码
* @note 该接口在IMOS_OpenDownload(Ex)之后调用或IMOS_StartRecord(Ex)之前调用
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRecordDataType(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                             IN const CHAR *pcChannelCode, IN XP_MEDIATYPE_E enMediaType);

/**
* 获取通道解码器的厂商类型。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcDecoderTag       解码器标签。长度IMOS_STRING_LEN_64
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           入参无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetChannelDecoderTag(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                                  IN const CHAR *pcChannelCode,
                                                                  OUT CHAR *pcDecoderTag);

/* Begin: Add by chenliang w0897, 2014/8/28, MPPD16481: 实现不同模块调用XP消息回调函数的设置 */
/**
* 设置接收消息或者异常消息的回调函数: 可重复设置。\n
* @param [IN] pfRunInfoFunc 消息或者异常消息回调函数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* - 1、用户不能在设置给播放器库的回调函数中直接调用播放器库任何接口函数；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMultiRunMsgCB(IN XP_RUN_INFO_CALLBACK_EX_PF pfnRunInfoFunc);
/* End: Add by chenliang w0897, 2014/8/28, MPPD16481: 实现不同模块调用XP消息回调函数的设置 */


/* Begin: Add by chenxiangyi w1099, 2014/10/29, MPPD18550: 实现不同模块调用XP消息回调函数的删除 */
/**
* 释放接收消息或者异常消息的回调函数。\n
* @param [IN] pfRunInfoFunc 消息或者异常消息回调函数的指针。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* @note
* - 1、用户不能在设置给播放器库的回调函数中直接调用播放器库任何接口函数；
* - 2、该接口函数支持Windows和Linux。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMultiRunMsgCB(IN XP_RUN_INFO_CALLBACK_EX_PF pfnRunInfoFunc);
/* End: Add by chenxiangyi w1099, 2014/10/29, MPPD18550: 实现不同模块调用XP消息回调函数的删除 */

/**
* 设置GPU工作模式。\n
* @param [IN] pstUserLoginIDInfo        用户登录ID信息标识。
* @param [IN] pcChannelCode             通道资源编码。
* @param [IN] bEnable   是否启用GPU标志
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                    成功
* -         #ERR_COMMON_INVALID_PARAM              输入参数无效
* -         #ERR_XP_FAIL_TO_ENABLE_IA_GPU_DECODE   设置失败
* @note
* - 1、该接口仅针对宇视云播放器有效，其余产品请勿调用
* - 2、用户在调用#IMOS_OpenVodStream之后和#IMOS_StartPlay之前调用该接口。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableIAGpuDecode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN BOOL_T bEnable);

/**
* 启动与关闭显示智能功能。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] bOpen              是否开启智能显示
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
*/
IMOS_EXPORT ULONG_32 IMOS_SetDisplayIntelligence(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN BOOL_T bEnable);


/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */
/**
* 设置显示OSD
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pstOsdList            OSD信息列表
* @param [IN] ulOsdNum              OSD个数
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_SET_OSD              设置显示osd失败
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note
* - 1、调用该接口开始显示指定的OSD，直到调用IMOS_StopOSD后OSD消失。
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN const XP_OSD_OVER_INFO_S *pstOsdList,
                                        IN ULONG_32 ulOsdNum);

IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN const XP_OSD_OVER_INFO_S *pstOsdList,
                                         IN ULONG_32 ulOsdNum);
/* Begin:Add by lizhen for 查询OSD信息 in 2017/3/24
/** 
* 查询OSD信息(重要的是长和宽)
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [INOUT] pstOsdList         OSD信息列表
* @param [IN] ulOsdNum              OSD个数
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* @note 
* - 1、只返回调用IMOS_AddOSD增加的OSD，不返回系统时间
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           INOUT XP_OSD_OVER_INFO_S *pstOsdList,
                                           IN ULONG_32 ulOsdNum);
/**
* 复位显示OSD
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_STOP_OSD            停止显示osd失败
* -         #ERR_XP_PORT_NOT_REGISTER           播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);
/* End: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */
/**
* 设置分段下载时, 文件大小上限。\n
* @param [IN]  pstUserLoginIDInfo           用户登录ID信息标识。
* @param [IN]  pcChannelCode                下载资源编码。
* @param [IN]  ulMaxDownloadSize            下载文件的最大值, 单位为M。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获取通道失败
* -         #ERR_PUBLIC_ACQUIRE_MUTEX_FAIL       获取锁失败
* -         #ERR_COMMON_INVALID_PARAM            参数错误
* @note 如不调用该接口或设置下载最大值为0，则表示下载文件大小没有限制
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMaxDownloadSize(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                     IN const CHAR *pcChannelCode,
                                                     IN const ULONG_32 ulMaxDownloadSize);
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */

/**
* 设置拼帧前媒体流数据回调函数。\n
* @param [IN] pstUserLoginIDInfo      用户登录ID信息标识。
* @param [IN] pcChannelCode           播放通道编码。
* @param [IN] pfnSourceMediaDataCBFun 拼帧前媒体流数据回调函数的指针。
* @param [IN] bContinue               是否继续进行后面的拼帧、解码和显示操作。
* @param [IN] lUserParam              用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                入参无效
* -         #ERR_XP_NOT_START_PLAY                   指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note 目前只有bContinue为false才有效。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSourceMediaDataCBEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                         IN BOOL_T bContinue,
                                                         IN LONG lUserParam);

/**
* 获取媒体能力集。\n
* @param [IN] pstUserLoginIDInfo            用户登录ID信息标识。
* @param [IN] pcChannelCode                 播放通道编码。
* @param [OUT] pstMediaAbility              媒体能力集
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
* - 1、在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自动失效
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMediaAbilityInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   OUT XP_MEDIA_ABILITY_S *pstMediaAbility);

/**
* 设置实况代理。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      播放通道编码。
* @param [IN] pcProxyIP          实况代理ip
* @param [IN] usProxyPort        实况代理端口号
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         ERR_COMMON_INVALID_PARAM                 输入参数非法
* -         #ERR_XP_FAIL_TO_SET_PROXY                设置代理失败
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetStreamProxyParam(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN const CHAR *pcProxyIP,
                                                   IN USHORT usProxyPort);


/**
* 设置下载的option间隔。\n
* @param [IN] pstUserLoginIDInfo 用户登录ID信息标识。
* @param [IN] pcChannelCode      下载资源编码。
* @param [IN] ulOptionInterval   下载option间隔。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY               指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          暂停媒体播放处理失败
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       流控协商暂停失败
* -         #ERR_XP_FAIL_TO_PAUSE                暂停播放操作失败
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadOptionInterval(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN const CHAR *pcChannelCode,
                                                            IN ULONG_32 ulOptionInterval);

/**
* 打开分段点播回放媒体流。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pcVodUrl              录像文件的URL列表。
* @param [IN] ulUrlCount            分段录像的数目
* @param [IN] pcServerIP            媒体流控服务器的IP。
* @param [IN] usServerPort          媒体流控服务器的端口号。
* @param [IN] ulProtl               接收媒体流的协议类型，需从tagProtocol枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可占用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道的资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体流失败
* -         #ERR_XP_FAIL_TO_OPEN_VOD             启动点播回放业务失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note 无。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodStreamV2(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcVodUrl[],
                                               IN ULONG_32 ulUrlCount,
                                               IN const CHAR *pcServerIP,
                                               IN USHORT usServerPort,
                                               IN ULONG_32 ulProtl);

/**
* 启动分段录像下载，并将下载下来的文件合并成一个文件。    /n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownUrl           需下载媒体数据源的URL列表。
* @param [IN]  pcServerIP          媒体流控服务器的IP。
* @param [IN]  usServerPort        媒体流控服务器的端口号。
* @param [IN]  ulProtl             接收媒体流的协议类型，需从#XP_PROTOCOL_E枚举中取值（保留，目前仅支持TCP协议）。
* @param [IN]  ulDownMediaSpeed    媒体数据下载速度，需从#XP_DOWN_MEDIA_SPEED_E枚举中取值。
* @param [IN]  pcFileName          下载媒体数据保存的文件名，包括路径。
* @param [IN]  szDecoderTag        解码标签
* @param [OUT] pcDownloadID        下载通道号列表，缓冲区长度应不小于#IMOS_RES_CODE_LEN（48）。
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
* - 4、停止媒体流下载须调用#IMOS_StopMultiSectionDownload接口；
* - 5、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMultiSectionDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN CHAR *pcDownUrl[],
                                                            IN ULONG_32 ulUrlCount,
                                                            IN const CHAR *pcServerIP,
                                                            IN USHORT usServerPort,
                                                            IN ULONG_32 ulProtl,
                                                            IN ULONG_32 ulDownMediaSpeed,
                                                            IN const CHAR *pcFileName,
                                                            IN CHAR szDecoderTag[IMOS_STRING_LEN_64],
                                                            OUT CHAR *pcDownloadID);

/**
* 停止分段录像下载。\n
* @param [IN]  pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN]  pcDownloadID        下载通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得下载通道资源失败
* @note
* - 1、该接口与#IMOS_StartMultiSectionDownload接口匹配；
* - 2、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopMultiSectionDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcDownloadID);

/* begin: added by zhangbolun 03503 2017/07/24 for 视频结构化 MPPD49482*/
/**
* 打开智能回放媒体流(VAS与XP通信)。\n
* @param [IN] pstUserLoginIDInfo    用户登录ID信息标识。
* @param [IN] pcChannelCode         播放通道编码。
* @param [IN] pcServerIP                  发流端IP地址。
* @param [IN] usServerPort             发流端端口。
* @param [OUT] pcLocalIP                本地收流IP。
* @param [OUT] pulLocalPort          本地收流端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER            指定的播放通道没有注册
* -         #ERR_XP_PORT_NOT_AVAILABLE           播放通道不可占用
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道的资源失败
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       建立流控协商失败
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       打开网络媒体流失败
* -         #ERR_XP_FAIL_TO_OPEN_VOD             启动点播回放业务失败
* -         #ERR_XP_RTSP_REQ_TIMEOUT             流控业务处理超时
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    流控业务带宽不足
* -         #ERR_XP_RTSP_SERVINTERERR            流控业务内部错误
* @note 
* - 1、目前仅支持UDP传输的RTP+ES流。
* - 2、H.264的rtp_typ为105，私有数据的rtp_typ为115
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenIntelligenceVod (IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode,
                                                       IN CHAR *pcServerIP,
                                                       IN USHORT usServerPort,
                                                       OUT CHAR *pcLocalIP,
                                                       OUT ULONG_32 *pulLocalPort);
 /* end: added by zhangbolun 03503 2017/07/24 for 视频结构化 MPPD49482*/
#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_MEDIA_PLAYER_SDK_INNER_FUNC_H_ */



