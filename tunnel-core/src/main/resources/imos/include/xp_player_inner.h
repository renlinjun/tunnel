/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
xp_player_inner.h

Project Code: IMOS通用媒体播放器
Module Name: IMOS通用媒体播放器
Date Created: 2012-03-31
Author: jinqifeng 00350
Description: IMOS通用媒体播放器XP内部接口

--------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_PLAYER_INNER_H_
#define _IMOS_XP_PLAYER_INNER_H_

/* 包含IMOS基础平台的头文件 */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"

/* 包含播放器SDK数据结构头文件 */
#include "xp_datatype.h"
#include "xp_player.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* 启动指定抓拍数目的连续实时抓拍。\n
* @param [IN] ulPort             播放通道号。
* @param [IN] pcFileName         图像文件存放的路径，包括文件名（不带扩展名）。
* @param [IN] ulPicFormat        图像文件的格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] ulInterval         抓拍间隔，单位为毫秒。
* @param [IN] ulCount            抓拍数目。
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
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartSnatchSeriesEx(IN ULONG_32 ulPort,
                                                                IN const CHAR *pcFileName,
                                                                IN ULONG_32 ulPicFormat,
                                                                IN ULONG_32 ulInterval,
                                                                IN ULONG_32 ulCount);

/**
* 设置指定通道的数字放大功能。\n
* @param [IN] ulPort                   播放通道号
* @param [IN] hWnd                     画中画句柄,hWnd = IMOS_INVALID_HANDLE表示关闭，非IMOS_INVALID_HANDLE表示开启
* @param [IN] pstRect                  原始图像区域坐标，pstRect = NULL为全部显示，该坐标值为区域在图像中的百分比值
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT                  不支持该功能
* -         #ERR_XP_FAIL_TO_SET_DIGITALZOOM      设置电子放大失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDigitalZoom(IN ULONG_32 ulPort,
                                                           IN IMOS_HANDLE hWnd,
                                                           IN XP_RECT_S *pstRect);

/**
* 获取指定通道的图片信息。\n
* @param [IN] ulPort                   播放通道号
* @param [OUT] pulWidth                图片的宽
* @param [OUT] pulHeight               图片的高
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_GET_PIC_PARAM        获得当前通道解码后图片长宽信息失败
* -         #ERR_COMMON_INVALID_PARAM            参数错误
* @note
* - 1、该接口函数仅支持Windows。
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetPicSize(IN ULONG_32 ulPort,
                                                       OUT ULONG_32 *pulWidth,
                                                       OUT ULONG_32 *pulHeight);

/**
* 设置是否启动乱序整理功能。\n
* @param [IN] bAdjust 是否开启乱序整理功能
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_SET_PARAM            设置播放器的配置参数失败
* @note
* -  1、当前只支持UDP+TS中的视频包乱序功能
* -  2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_AdjustPktSeq(IN BOOL_T bAdjust);

/**
* 对指定通道做图（不规则区域）
* @param [IN] ulPort             播放通道号
* @param [IN] pDrawHandle        画图句柄
* @param [IN] ulNum              不规则区域顶点个数，最大为6
* @param [IN] pointArry          坐标地址
* @param [IN] ulDir              方向,需从#XP_AREA_DIRECTION_E枚举中取值。
* @param [IN] ulColor            线条颜色
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_PolylineTo(IN ULONG_32 ulPort,
                                                      IN IMOS_HANDLE pDrawHandle,
                                                      IN ULONG_32 ulNum,
                                                      IN XP_POINT_S *pointArry,
                                                      IN ULONG_32 ulDir,
                                                      IN ULONG_32 ulColor);

/**
* 对指定通道做图（不规则区域）
* @param [IN] ulPort                   播放通道号
* @param [IN] pDrawHandle              画图句柄
* @param [IN] ulNum                    不规则区域顶点个数，最大为#MAX_AREA_POINT
* @param [IN] pointArry                坐标地址
* @param [IN] ulWidth                  线条宽度
* @param [IN] ulColor                  线条颜色
* @return 无
* @note 无
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_PolylineToWindow(IN ULONG_32 ulPort,
                                                            IN IMOS_HANDLE pDrawHandle,
                                                            IN ULONG_32 ulNum,
                                                            IN XP_POINT_S *pointArry,
                                                            IN ULONG_32 ulWidth,
                                                            IN ULONG_32 ulColor);

/**
* 对指定通道做图（阴影线）
* @param [IN] ulPort             播放通道号
* @param [IN] pDrawHandle        画图句柄
* @param [IN] pstStart           直线起点
* @param [IN] pstEnd             直线终点
* @param [IN] ulDir，            线条方向,需从#XP_THRU_LINE_DIRECTION_E枚举中取值
* @param [IN] ulColor            线条颜色
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_DLineTo(IN ULONG_32 ulPort,
                                                   IN IMOS_HANDLE pDrawHandle,
                                                   IN const XP_POINT_S *pstStart,
                                                   IN const XP_POINT_S *pstEnd,
                                                   IN ULONG_32 ulDir,
                                                   IN ULONG_32 ulColor);

/**
* 获取画图句柄
* @param [IN] ulPort             播放通道号
* @return 返回如下结果：
* - 成功：IMOS_HANDLE
* - #
* - 失败：IMOS_INVALID_HANDLE
* -
* @note
* - 1、需要在视频上做图，首先需要调用#IMOS_GetHVDC获取HVDC，才可以做图并显示；调用#IMOS_ReleaseHVDC取消做图数据显示
* - 2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT IMOS_HANDLE STDCALL IMOS_XP_GetHVDC(IN ULONG_32 ulPort);

/**
* 释放画图句柄
* @param [IN] ulPort             播放通道号
* @param [IN] pDrawHandle        通过IMOS_GetHVDC获取的句柄
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_ReleaseHVDC(IN ULONG_32 ulPort,
                                                       IN IMOS_HANDLE pDrawHandle);
/**
* 开始做图
* @param [IN] ulPort                   播放通道号
* @param [IN] pDrawHandle              画图句柄
* @param [IN] pverBer                  保留参数
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_BEGINHVDC           开始画图失败
* @note
* - 1、在图像上画线，首先需要在#IMOS_BeginDraw和#IMOS_EndDraw 之间操作，其他操作无效
* - 2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_BeginDraw(IN ULONG_32 ulPort,
                                                      IN IMOS_HANDLE pDrawHandle,
                                                      IN VOID *pverBer);

/**
* 完成做图
* @param [IN] ulPort             播放通道号
* @param [IN] pDrawHandle        画图句柄
* @return 无
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_EndDraw(IN ULONG_32 ulPort,
                                                   IN IMOS_HANDLE pDrawHandle);

/**
* 设置解码端智能规则显示使能
* @param [IN] ulPort             播放通道号
* @param [IN] bEnable            是否显示
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERULE   设置显示智能规则失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ShowAnalyseRule(IN ULONG_32 ulPort,
                                                            IN const BOOL_T bEnable);

/**
* 设置解码端智能结果显示使能
* @param [IN] ulPort        播放通道号
* @param [IN] bEnable       是否显示
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERESULT 设置显示智能结果失败
* @note
* - 1、该接口函数仅支持Windows。
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ShowAnalyseResult(IN ULONG_32 ulPort,
                                                              IN const BOOL_T bEnable);

/**
* 影像调节\n
* @param [IN] ulPort        播放通道号
* @param [IN] pstAdjust     影像调节参数
* @param [IN] bOpen         是否打开影像调节
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY              播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                 不支持该功能
* -         #ERR_XP_FAIL_TO_SET_VIDEO_ADJUST    设置影像调节失败
* @note
*      1、该函数需要在#IMOS_XP_StartPlay之后和#IMOS_XP_StopPlay之前调用。
* -    2、默认不启动影像调节。
* -    3、对比度取值范围为[0--199]，默认值为100；
* -       亮度取值范围为[0--199]，默认值为100；
* -       色调取值范围为[0--359]，默认值为0；
* -       饱和度取值范围为[0--359]，默认值为100；
* -       伽玛取值范围为[0--99]，默认值为10。
* -    4、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoAdjust(IN ULONG_32 ulPort,
                                                           IN const XP_VIDEO_ADJUST_S *pstAdjust,
                                                           IN BOOL_T bOpen);

/**
* 模糊处理\n
* @param [IN] ulPort        播放通道号
* @param [IN] ulFactor      模糊处理参数
* @param [IN] bOpen         是否启动模糊处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_VIDEO_MONITOR_BLUR  设置模糊处理失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后和#IMOS_XP_StopPlay之前调用。
* -    2、默认不启动模糊处理。
* -    3、模糊处理参数取值范围为[1--127]，默认值为80。
* -    4、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoMotionBlur(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulFactor,
                                                               IN BOOL_T bOpen);

/**
* 单次区域实时抓拍。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcFileName        保存图像的文件路径，包括文件名（不带后缀名）。
* @param [IN] ulPicFormat       图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
* @param [IN] pstRect           制定抓拍区域
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
* -  1. 播放器将根据图像格式在文件名后面追加对应的后缀名。如BMP图像文件的后缀为.bmp。
* -  2. pstRect为NULL时，为抓拍整幅图像。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SnatchRegion(IN ULONG_32 ulPort,
                                                         IN const CHAR *pcFileName,
                                                         IN ULONG_32 ulPicFormat,
                                                         IN const XP_RECT_S *pstRect,
                                                         OUT CHAR *pcFilePostfix);

/**
* 锐化处理\n
* @param [IN] ulPort        播放通道号
* @param [IN] fSigma        锐化处理参数
* @param [IN] bOpen         是否启动锐化处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_VIDEO_SHARPEN       设置锐化处理失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后和#IMOS_XP_StopPlay之前调用。
* -    2、默认不启动锐化处理。
* -    3、锐化处理参数取值范围为[0.0--2.0]，默认值为0.05。
* -    4、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoSharpen(IN ULONG_32 ulPort,
                                                            IN FLOAT fSigma,
                                                            IN BOOL_T bOpen);

/**
* 去雾处理\n
* @param [IN] ulPort            播放通道号
* @param [IN] ulLowValue        暗区调节参数
* @param [IN] ulHighValue       亮区调节参数
* @param [IN] bOpen             是否启动去雾处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_DE_FOG              设置去雾处理失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后和#IMOS_XP_StopPlay之前调用。
* -    2、默认不启动去雾处理。
* -    3、去雾处理参数1取值范围为[0--49]，默认值为0；
* -       去雾处理参数2取值范围为[51--100]，默认值为100。
* -    4、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDeFog(IN ULONG_32 ulPort,
                                                     IN ULONG_32 ulLowValue,
                                                     IN ULONG_32 ulHighValue,
                                                     IN BOOL_T bOpen);

/**
* 设置码流丢包情况下拼帧策略。\n
* @param [IN] ulDataLostSplitterPolicy  码流丢包情况下拼帧策略，需从#XP_MEDIA_DATA_LOST_SPLITTER_POLICY枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* @note
* -    1、码流丢包情况下默认丢弃一个I帧组
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMediaDataLostSplitterPolicy(IN ULONG_32 ulDataLostSplitterPolicy);

/**
* 防闪烁处理\n
* @param [IN] ulPort            播放通道号
* @param [IN] ulWinSize         参考帧数
* @param [IN] ulSoftenVal       帧间滤波参数
* @param [IN] bOpen             是否启动防闪烁处理
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_ANTI_FLICKER        设置防闪烁处理失败
* @note
* -    1、该函数需要在#IMOS_XP_StartPlay之后和#IMOS_XP_StopPlay之前调用。
* -    2、默认不启动防闪烁处理。
* -    3、ulWinSize取值范围为[0--100]；
* -       ulSoftenVal取值范围为[0--30]。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetAntiFlicker(IN ULONG_32 ulPort,
                                                           IN ULONG_32 ulWinSize,
                                                           IN ULONG_32 ulSoftenVal,
                                                           IN BOOL_T bOpen);

/**
* 设置图象的对比度参数。\n
* @param [IN] ulPort             播放通道号。
* @param [IN] ulContrastMode     图象对比度模式，需从#XP_PICTURE_CONTRAST_MODE_E枚举中取值。
* @param [IN] ulContrastLevelEx  图象对比度级别，需从#XP_PICTURE_CONTRAST_LEVEL_EX_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED              成功
* -         #ERR_COMMON_INVALID_PARAM        输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     获得播放通道资源失败
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST 播放通道不支持设置图象对比度参数
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     设置图象对比度失败
* @note
* -    1、在不调用该接口的情况下，视频图像默认不进行对比度调节处理。
* -    2、可以在开始播放#IMOS_XP_StartPlay之前设置，但设置的对比度参数被保存，作为启动该通道播放时
* -       的初始值；在开始播放后调用该接口设置的对比度参数即时生效。
* -    3、调用该接口对指定播放通道设置的对比参数在播放器运行期间一直有效；当参数ulContrastMode
* -       传入#XP_PICTURE_CONTRAST_MODE_NONE时，即停止对比度调节处理，此时ulContrastLevel参数传
* -       入的值无效。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPictureContrastEx(IN ULONG_32 ulPort,
                                                                 IN ULONG_32 ulContrastMode,
                                                                 IN ULONG_32 ulContrastLevelEx);

/**
* 单帧后退播放。\n
* @param [IN] ulPort   播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_NOT_START_PLAY               播放通道未开始播放操作
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       当前正在本地录像
* -         #ERR_XP_FAIL_TO_STEP_PLAY            单帧播放失败
* @note
* -    1、正在本地录像时，不支持单帧后退播放操作；
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OneByOneBack(IN ULONG_32 ulPort);

/**
* 检测运行系统的硬件参数
* @param [IN] 无。
* @return 返回#XP_HW_STATUS_E枚举类型的参数
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CheckHWValidate();

/**
* 启动图像拼接操作
* @param [IN] ulChannelID                   播放图像拼接的通道号
* @param [IN] pcCombineResCode              图像拼接资源编码
* @param [IN] ulCombineStreamNum             图像拼接的通道数目
* @param [IN] pulCombineStreamChannelID     图像拼接通道数组
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_START_COMBINE_IMAGE 启动图像拼接操作失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartCombineVideo(IN const ULONG_32 ulChannelID,
                                                              IN const CHAR  *pcCombineResCode,
                                                              IN const ULONG_32 ulCombineStreamNum,
                                                              IN const ULONG_32 *pulCombineStreamChannelID);
/**
* 停止图像拼接操作
* @param [IN] ulChannelID           播放图像拼接的通道号
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_IMAGE  停止图像拼接操作失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopCombineVideo(IN const ULONG_32 ulChannelID);

/**
* 标定图像拼接特征点
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
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_MarkCombinePoint(IN const CHAR  *pcCombineResCode,
                                                             IN LONG_32  lCombineStreamNum,
                                                             IN LONG_32  *plCombinPointNum,
                                                             IN LONG_32  *plCombinPointVal,
                                                             IN LONG  lReserve);

/**
* 启动视频图像电子放大功能。\n
* @param [IN] ulChannelID           播放电子放大的通道号
* @param [IN] pcCombineResCode      图像拼接资源编码
* @param [IN] pstComobineZoomRect   电子放大区域信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_START_COMBINE_ZOOM   启动电子放大失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartCombineZoom(IN const ULONG_32 ulChannelID,
                                                             IN const CHAR  *pcCombineResCode,
                                                             IN const XP_COMBINE_ZOOM_RECT_S *pstComobineZoomRect);

/**
* 修改电子放大区域信息。\n
* @param [IN] ulChannelID           播放电子放大的通道号
* @param [IN] pcCombineResCode      图像拼接资源编码
* @param [IN] pstComobineZoomRect   电子放大区域信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_MOVE_COMBINE_ZOOM    修改电子放大区域信息失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_MoveCombineZoom(IN const ULONG_32 ulChannelID,
                                                            IN const CHAR  *pcCombineResCode,
                                                            IN const XP_COMBINE_ZOOM_RECT_S *pstComobineZoomRect);


/**
* 关闭视频图像电子放大功能。\n
* @param [IN] ulChannelID           播放电子放大的通道号
* @param [IN] pcCombineResCode      图像拼接资源编码
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获得通道资源失败
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_ZOOM    关闭电子放大功能失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopCombineZoom(IN const ULONG_32 ulChannelID,
                                                            IN const CHAR  *pcCombineResCode);

/**
* 判断是否为DB33解码标准接入。\n
* @param [IN] pcDecodetag    decodetag信息
* @return #BOOL_TRUE：是DB33解码插件标准接入； #BOOL_FALSE：非DB33解码插件标准接入
* @note 无
*/
IMOS_XP_PLAYER_EXPORT BOOL_T STDCALL IMOS_XP_IsDB33Decodetag(IN const CHAR *pcDecodetag);

/**
* 设置解码模式 \n
* @param [IN] ulChannelID        用户登录ID信息标识 ，该参数无效，全局生效
* @param [IN] ulMode                    解码模式 0 代表软解模式
* @return
* @note
* - 1、该接口函数仅支持Windows。
* - 2、该接口为实验性接口，会导致程序稳定性下降，不推荐用户使用。
* - 3、该函数返回成功失败
* - 4、该接口可以和IMOS_XP_SetTransParam配合使用
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoDecodeMode(IN const ULONG_32 ulChannelID,
                                                               IN ULONG_32 ulMode);

/**
* 获取空闲端口号。\n
* @param [INOUT] pulPort    播放通道号
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获取资源失败
* @note 无
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetPort(INOUT ULONG_32 *pulPort);

/**
* 释放端口号。\n
* @param [IN] ulPort    播放通道号
* @return 无
* @note 无
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_FreePort(IN ULONG_32 ulPort);


/**
* 设置通道的原始厂商信息。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcDecoderTag  任意解码器标签。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放窗口的资源失败
* @note 该接口会将传入的DecoderTag修改为各厂商的原始码流对应的DecoderTag;
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRawDecoderTag(IN ULONG_32 ulPort,
                                                             IN const CHAR *pcDecoderTag);

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartMultiSectionJoint(IN const CHAR *pcFileName,
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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartMultiFileJoint(IN CHAR *pacFileName[],
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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CreateTsDataJointFile(IN const CHAR *pcJointFileName, OUT ULONG *pulHandle);

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_JointTsDataToFile(IN ULONG ulHandle, IN UCHAR *pucDataBuf, IN ULONG_32 ulDataLen,IN ULONG_32 ulMode);

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CloseTsDataJointFile(IN ULONG ulHandle, OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* 启动图片播放功能。\n
* @param [IN] ulPort 播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_START_IMAGE          启动图片播放模式失败
* @note 当前只支持http协议的jpg图片播放。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartImage(IN ULONG_32 ulPort);

/**
* 图片加载。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcImageURL    卡口图片URL信息
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           加载图片失败
* @note 当前只支持http协议的jpg图片播放。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_LoadImage(IN ULONG_32 ulPort,
                                                      IN const CHAR *pcImageURL);

/**
* 加载图片内存.\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcImageMemory 图片始地址
* @param [IN] ulImageSize   图片大小
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           加载图片失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_LoadImageMemory(IN ULONG_32 ulPort,
                                                            IN const UCHAR *pucImageMemory,
                                                            IN const ULONG_32 ulImageSize);

/**
* 加载图片内存.\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcImageMemory 图片始地址
* @param [IN] ulImageSize   图片大小
* @param [IN] pcPrivateData 私有数据起始地址
* @param [IN] ulPrivateLen  私有数据长度
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           加载图片失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_LoadImageMemoryEx(IN ULONG_32 ulPort,
                                                              IN const UCHAR *pcImageMemory,
                                                              IN const ULONG_32 ulImageSize,
                                                              IN const UCHAR *pcPrivateData,
                                                              IN const ULONG_32  ulPrivateLen);


/**
* 关闭图片播放功能。\n
* @param [IN] ulPort  播放通道号。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER            播放通道没有注册
* -         #ERR_XP_FAIL_TO_STOP_IMAGE           关闭图片播放模式失败
* @note 当前只支持http协议的jpg图片播放。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopImage(IN ULONG_32 ulPort);


/**
* 设置语音业务编码类型。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] ulAudioEncType  音频编码类型，需从#XP_AUDIO_ENCODE_TYPE_E枚举中取值。
* @param [IN] ulSampleRate  音频采样率。
* @param [IN] ulChannels  音频声道数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVoiceEncodeType(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulAudioEncType,
                                                               IN ULONG_32 ulSampleRate,
                                                               IN ULONG_32 ulChannels);

/**
* 设置解码通道的SDP信息。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcDecoderSdp  通道解码器的SDP信息。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放窗口的资源失败
* @note
* -    1、目前仅是为了接入第三方DB33解码插件，将和第三方协商出的sdp信息设置给第三方DB33解码插件。
* -    2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDecoderSdp(IN ULONG_32 ulPort,
                                                          IN const CHAR *pcDecoderSdp);

/**
* 单次实时抓拍（不修改文件名）。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcFileName        保存图像的文件路径，包括文件名。
* @param [IN] ulPicFormat       图像格式，需从#XP_PICTURE_FORMAT_E枚举中取值。
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
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SnatchOnceEx(IN ULONG_32 ulPort,
                                                         IN const CHAR *pcFileName,
                                                         IN ULONG_32 ulPicFormat);


/**
* 开始本地录像（不修改文件名）。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcFileName        录像文件存放路径，包括文件名。
* @param [IN] ulMediaFileFormat 录像文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
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
* -    1、当播放处于暂停播放、快速播放、慢速播放或单帧播放状态时，不支持启动本地录像操作。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartRecordEx(IN ULONG_32 ulPort,
                                                          IN const CHAR *pcFileName,
                                                          IN ULONG_32 ulMediaFileFormat);

/**
* 设置转码后的媒体流数据回调函数。\n
* @param [IN] ulPort                  播放通道号。
* @param [IN] pfnTranscodeCBFun       转码后媒体流数据回调函数的指针。
* @param [IN] pstEncParam             编码器参数
* @param [IN] bContinue               是否继续进行后面的拼帧、解码和显示操作。
* @param [IN] lUserParam              用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note
* -     1、该函数在IMOS_XP_StartPlay之前或之后调用；
* -     2、务必IMOS_XP_StopPlay前将回调函数指针设为NULL；
* -     3、该函数不可与其他的码流回调函数同时使用；
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTranscodeCB(IN ULONG_32 ulPort,
                                                           IN XP_PLAYER_TRANSCODE_CALLBACK_PF pfnTranscodeCBFun,
                                                           IN const XP_ENCODE_PARAM_S *pstEncParam,
                                                           IN BOOL_T bContinue,
                                                           IN LONG_REAL lUserParam);

/**
* 设置转封装成TS码流输出的回调函数指针。\n
* @param [IN] ulPort                        播放通道号。
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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTsDataOutputCB(IN ULONG_32 ulPort,
                                                              IN XP_PLAYER_MEDIA_DATA_CALLBACK_PF pfnMediaDataCallback,
                                                              IN LONG_REAL lUserParam);

/**
* 获取某个通道的媒体流收流信息。\n
* @param [IN] ulPort                        播放通道号。
* @param [OUT] pcMediaReceiveIp             媒体流收流IP地址
* @param [OUT] pusMediaReceivePort          媒体流收流端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
* - 1、在#IMOS_XP_StartPlay之后调用，在#IMOS_XP_StopPlay时自动失效
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetMediaReceiveInfo(IN ULONG_32 ulPort,
                                                                OUT CHAR *pcMediaReceiveIp,
                                                                OUT USHORT *pusMediaReceivePort);

/**
* 启动与关闭媒体流防串流功能。\n
* @param [IN] ulPort                        播放通道号。
* @param [IN] bOpen                         是否开启防串流功能
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
* - 1、在#IMOS_XP_StartPlay之后调用，在#IMOS_XP_StopPlay时自动失效
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetCrossStream(IN ULONG_32 ulPort,
                                                           IN const BOOL_T bOpen);

/**
* 打开本地播放文件（建立文件索引）。\n
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
* @note 无。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OpenFileBuildIndex(IN ULONG_32 ulPort,
                                                               IN const CHAR *pcFileName);

/**
* 设置显示OSD
* @param [IN] ulPort        播放通道号
* @param [IN] pstOsdList    OSD信息列表
* @param [IN] ulOsdNum      OSD个数
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_XP_FAIL_TO_SET_OSD             设置显示osd失败
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* @note
* - 1、调用该接口开始显示指定的OSD，直到调用IMOS_XP_StopOSD后OSD消失。
* - 2、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartOSD(IN ULONG_32 ulPort,
                                                     IN const XP_OSD_OVER_INFO_S *pstOsdList,
                                                     IN ULONG_32 ulOsdNum);

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_AddOSD(IN ULONG_32 ulPort,
													  IN const XP_OSD_OVER_INFO_S *pstOsdList,
													  IN ULONG_32 ulOsdNum);
/************************************************************************/
/* 查询OSD信息(主要是OSD的区域，长和宽) 
* @param [IN] ulPort        播放通道号
* @param [INOUT] pstOsdList    OSD信息列表
* @param [IN] ulOsdNum      OSD个数
* @return 返回如下结果：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* @note
* - 返回的是调用IMOS_AddOsd接口添加的OSD，不返回时间OSD

*/
/************************************************************************/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_QueryOSD(IN ULONG ulPort,
                                                        INOUT XP_OSD_OVER_INFO_S *pstOsdList,
                                                        IN ULONG_32 ulOsdNum);												  

/**
* 复位显示OSD
* @param [IN] ulPort        播放通道号
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_XP_FAIL_TO_STOP_OSD            停止显示osd失败
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放通道资源失败
* @note
* - 1、该接口函数仅支持Windows。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopOSD(IN ULONG_32 ulPort);

/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */
/**
* 设置获取点播回放时间的回调函数 \n
* @param [IN]  ulPort                   播放通道号。
* @param [IN]  pfnGetVodTimeCBFun       获取点播回放时间的回调函数指针。
* @param [IN]  lUserParam               用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_PORT_NOT_REGISTER                指定的播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* @note 无。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVodTimeCB(IN ULONG_32 ulPort,
                                                   IN XP_PLAYER_GET_VODTIME_CALLBACK_PF pfnGetVodTimeCBFun,
                                                   IN LONG_REAL lUserParam);
/* END: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */


/**
* 获得码流格式信息。\n
* @param [IN] ulPort                        播放通道号。
* @param [IN] pulStreamType                 码流格式信息(类型为#XP_MEDIA_FILE_FORMAT_E）。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* @note
* - 1、在#IMOS_XP_StartPlay之后调用
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetStreamType(IN ULONG_32 ulPort,
                                                          OUT ULONG_32 *pulStreamType);
/**
* 设置转码解码参数（内部接口）。\n
* @param [IN] ulPort                  播放通道号。
* @param [IN] pstTrans         转码后视频图像分辨率信息  NULL 为关闭

* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         ERR_COMMON_INVALID_PARAM                 输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
@note 在调用该接口前，需要全局调用IMOS_XP_SetVideoDecodeMode ,选择GPU模式
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTransParam(IN ULONG_32 ulPort,
                                                                IN const XP_TRANS_PARAM_S *pstPicDimension);

/**
* 设置播放或下载时的音频声道，默认为左声道。\n
* @param [IN] ulPort      播放通道。
* @param [IN] ulSoundChannel     语音声道，需从#XP_AUDIO_CHANNEL_E枚举中取值

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetSoundChannel(IN ULONG_32 ulPort, IN ULONG_32 ulSoundChannel);

/**
* 设置是否启动抗丢包。\n
* @param [IN] bResistLost 是否启动抗丢包
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_SET_PARAM            设置播放器的配置参数失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ResistLost(IN BOOL_T bResistLost);

/**
* 设置xp端通知报文的接收端地址\n
* @param [IN] ulPort          播放通道号。
* @param [IN] pcFeedbackIP       抗丢包通知报文的接收端地址。
* @param [IN] usFeedbackPort      抗丢包通知报文的接收端监听端口。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         设置播放通道失败
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetFeedbackAddr(IN ULONG_32 ulPort,
                                                            IN const CHAR *pcFeedbackIP,
                                                            IN USHORT usFeedbackPort);

/**
* 设置录像数据类型\n
* @param [IN] pstUserLoginIDInfo  用户登录ID信息标识。
* @param [IN] pcChannelCode      下载资源编码。
* @param [IN] ulType              见枚举值  0 both,1 only video, 2 video and left audio, 3,vidoe and right audio
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
            其他见具体错误码
* @note 该接口IMOS_XP_StartRecord在之前调用
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRecordDataType(IN ULONG_32 ulPort,
                                                                            IN XP_MEDIATYPE_E enMediaType);

/* 启动转码录像。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcFileName        录像文件存放路径，包括文件名（不带后缀名）。
* @param [IN] ulMediaFileFormat 录像文件的格式，需从#XP_MEDIA_FILE_FORMAT_E枚举中取值。
* @param [IN] pstParam          转码参数
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
* -         #ERR_XP_NOT_SUPPORT                          不支持该功能
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           启动本地录像失败
* @note
* -    1、播放器将根据媒体流格式在文件名后面追加对应的后缀名。如TS流录像文件的后缀为.ts。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartConvertToFile(IN ULONG_32 ulPort,
                                                                  IN const CHAR *pcFileName,
                                                                  IN ULONG_32 ulMediaFileFormat,
                                                                  IN const XP_ENCODE_PARAM_S *pstParam,
                                                                  OUT CHAR *pcFilePostfix);

/* 停止转码录像。\n
* @param [IN] ulPort            播放通道号。
* @return VOID
* @note 无
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_StopConvertToFile(IN ULONG_32 ulPort);

/* 查询指定的播放通道是否处于活动状态。\n
* @param [IN] ulPort            播放通道号。
* @return VOID
* @note 无
*/
IMOS_XP_PLAYER_EXPORT BOOL_T STDCALL IMOS_XP_IsPortActive(IN ULONG_32 ulPort);

/**
* 设置桶型矫正\n
* @param [IN] ulPort                    播放通道号
* @param [IN] bOpen                     是否开启桶型矫正功能。
* @param [IN] enBarrelAjustLevel        桶型矫正等级，需从#XP_BARREL_ADJUST_LEVEL_E枚举值中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
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
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetBarrelAdjust(IN ULONG_32 ulPort,
                                                       IN BOOL_T bOpen,
                                                       IN XP_BARREL_ADJUST_LEVEL_E enBarrelAjustLevel);

/**
* 设置指定播放通道的业务类型。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] ulRenderScale     视频图像在播放通道上的显示比例，需从#PORT_MEDIA_SVC_TYPE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* @note
* -    1、在不调用该接口的情况下，视频图像默认填充整个播放窗格。

*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMediaSvcType(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulMediaSvcType);

/* Begin add by sunbiao/sW1071 2014.10.28 for MPPD18406 新增dsp去抖动 */
/**
* 设置视频去抖动参数\n
* @param [IN] ulPort                    播放通道号
* @param [IN] bOpen                     是否开启去抖动功能。
* @param [IN] stDeshakeParm             去抖动参数,结构体XP_DESHAKE_PARM_S 。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_COMMON_INVALID_PARAM               输入参数无效
* -         #ERR_XP_PORT_NOT_REGISTER               播放通道没有注册
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            获得播放通道资源失败
* -         #ERR_XP_NOT_START_PLAY                  播放通道未开始播放操作
* -         #ERR_XP_NOT_SUPPORT                     不支持该功能
* -         #ERR_XP_FAIL_TO_SET_DESHAKE             设置去抖动失败
* @note
*       不支持320 * 240及以下分辨率，待dsp库优化
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetDeshake(IN ULONG_32 ulPort,
                                                  IN BOOL_T bOpen,
                                                  IN XP_DESHAKE_PARM_S &stDeshakeParm);
/* End add by sunbiao/sW1071 2014.10.28 for MPPD18406 新增dsp去抖动 */

/**
* 启用IA GPU解码库。\n
* @param [IN] ulPort                   播放通道号。
* @param [IN] bEnable                  是否启用IA GPU解码
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_ENABLE_IA_GPU_DECODE     启用解码库失败
* @note
*      1、该函数在创建通道资源之后调用，释放通道资源后失效。
*      2、该函数仅支持我司h264解码，非h264编码时将转为软解。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_EnableIAGpuDecode(IN ULONG_32 ulPort,
                                                                 IN BOOL_T bEnable);

/**
* 启动与关闭显示智能功能。\n
* @param [IN] ulPort                        播放通道号。
* @param [IN] bOpen                         是否开启智能显示
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDisplayIntelligence(IN ULONG_32 ulPort, IN BOOL_T bOpen);

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */
/**
* 设置分段录像时, 文件大小上限。\n
* @param [IN] ulPort                             播放通道号
* @param [IN]  ulMaxRecordSize                   录像文件的最大值, 单位为M。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获取通道失败
* -         #ERR_PUBLIC_ACQUIRE_MUTEX_FAIL       获取锁失败
* -         #ERR_COMMON_INVALID_PARAM            参数错误
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMaxRecordSize(IN ULONG_32 ulPort, IN ULONG_32 ulMaxRecordSize);

/**
* 设置录像分段文件名生成方式。\n
* @param [IN]  ulPort                            播放通道号。
* @param [IN]  ulRecSegmentNameMode                  设置录像分段文件命名模式，需从#FILENAME_SPECIFY_MODE_E枚举中取值。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         获取通道失败
* -         #ERR_PUBLIC_ACQUIRE_MUTEX_FAIL       获取锁失败
* -         #ERR_COMMON_INVALID_PARAM            参数错误
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRecSegmentNameMode(IN ULONG_32 ulPort,
                                                                     IN ULONG_32 ulRecSegmentNameMode);

/**
* 设置获取当前下载进度输出回调函数。\n
* @param [IN]  ulPort                   播放通道号。
* @param [IN]  pfnGetCurDownPosCBFun    获取当前下载进度输出回调函数的指针。
* @param [IN]  lUserParam               用户设置参数。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_XP_PORT_NOT_REGISTER                指定的播放通道没有注册
* -         #ERR_XP_NOT_START_PLAY                   指定的播放通道未开始播放操作
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      设置媒体流数据回调函数失败
* -         #ERR_XP_FAIL_TO_SET_CUR_POS_CB           设置setCurDownPosCallback回调函数失败
* @note 无。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetCurDownPosCB(IN ULONG_32 ulPort,
                                                       IN XP_PLAYER_GET_CURDOWNPOS_CALLBACK_PF pfnGetCurDownPosCBFun,
                                                       IN LONG_REAL lUserParam);
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */

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
*      1、该函数在IMOS_XP_StartPlay之前或之后调用，在IMOS_XP_StopPlay时自动失效。
*      2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL。
*      3、目前只有bContinue为false才有效。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetSourceMediaDataCBEx(IN ULONG_32 ulPort,
                                                                 IN XP_PLAYER_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                                 IN BOOL_T bContinue,
                                                                 IN LONG_REAL lUserParam);

/**
* 获取媒体能力集。\n
* @param [IN] ulPort            端口号
* @param [OUT] pstMediaAbility              媒体能力集
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数非法
* -         #ERR_XP_PORT_NOT_REGISTER                播放通道没有注册
* @note
* - 1、在#IMOS_StartPlay之后调用，在#IMOS_StopPlay时自动失效
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetMediaAbilityInfo(IN ULONG_32 ulPort,
                                                                OUT XP_MEDIA_ABILITY_S *pstMediaAbility);

/**
* 设置通道的代理厂商信息。\n
* @param [IN] ulPort        播放通道号。
* @param [IN] pcProcxyDecoderTag  代理解码器标签。目前支持的厂商解码器有："h3c-v3"表示H3C V3版本解码器。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_COMMON_INVALID_PARAM           输入参数非法
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        获得播放窗口的资源失败
* @note 如果用户没有调用该函数，则播放器XP内各通道默认使用H3C V3版本的解码器。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetProcxyDecoderTag(IN ULONG_32 ulPort,
                                                                IN const CHAR *pcProcxyDecoderTag);

/**
* 设置加扰相关信息。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] ulScrambleKey    加扰KEY。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 引流字符串可以自行定义，但是收发双方必须保持一致；可以传空字符串，但指针不能为空。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetScrambleKey(IN ULONG_32 ulPort,
															   IN const ULONG ulScrambleKey);

/**
* 设置回放上墙的信息。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] pcScrambleMode    加扰模式。
* @param [IN] pcScrambleKey     加扰KEY(未异或摄像机编码)。
* @param [IN] pcCameraCode      摄像机编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 引流字符串可以自行定义，但是收发双方必须保持一致；可以传空字符串，但指针不能为空。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetScrambleInfo(IN ULONG_32 ulPort,
                                                              IN CHAR *pcScrambleMode,
                                                              IN CHAR *pcScrambleKey,
                                                              IN CHAR *pcCameraCode);

/**
* 获取回放上墙的信息。\n
* @param [IN] ulPort            播放通道号。
* @param [OUT] pcScrambleMode    加扰模式。
* @param [OUT] pcScrambleKey     加扰KEY(未异或摄像机编码)。
* @param [OUT] pcCameraCode      摄像机编码。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 引流字符串可以自行定义，但是收发双方必须保持一致；可以传空字符串，但指针不能为空。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetScrambleInfo(IN ULONG_32 ulPort,
                                                               OUT CHAR *pcScrambleMode,
                                                               OUT CHAR *pcScrambleKey,
                                                               OUT CHAR *pcCameraCode);

/**
* 获取加扰录像中的标识信息。\n
* @param [IN] ulPort            播放通道号。
* @param [IN] ulScrambleKey     加扰KEY。
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                      成功
* -         #ERR_COMMON_INVALID_PARAM                输入参数无效
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             获得播放通道资源失败
* @note 引流字符串可以自行定义，但是收发双方必须保持一致；可以传空字符串，但指针不能为空。
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetFileScrambleInfo(IN ULONG_32 ulPort,
                                                                   IN OUT CHAR *strCamCode);
																   
																   /**
* 鱼眼矫正设置。\n
* @param [IN] ulPort                播放通道号
* @param [IN] pstWorkInterfaceParam 算法处理1帧参数
* @return 返回如下错误码：
* -         #ERR_COMMON_SUCCEED                  成功
* -         #ERR_COMMON_INVALID_PARAM            输入参数无效
            #ERR_COMMON_FAIL                     执行失败
* @note 
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetFishAdjust(IN ULONG_32 ulPort,
                                                IN  IMOS_uintptr_t pstWorkInterfaceParam);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_PLAYER_INNER_H_ */
