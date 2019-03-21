/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_datatype.h

  Project Code: IMOS通用媒体播放器
   Module Name: IMOS通用媒体播放器
  Date Created: 2008-09-10
        Author: shiyouhua/04562
   Description: 播放器XP的错误码和数据结构类型定义头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_MEDIA_PLAY_SDK_DATA_TYPE_H_
#define _IMOS_MEDIA_PLAY_SDK_DATA_TYPE_H_

/************************************************************************/
/*********************** XP SDK错误码定义********************************/
/**********************[0x000700—0x0008FF] *****************************/
/************************************************************************/

/* 启动和停止播放器XP返回错误码 */
#define ERR_XP_FAIL_TO_REG_BP_CMD                       0x000700        /**< 播放器XP的子模块向基础平台BP注册失败 */
#define ERR_XP_FAIL_TO_INIT_XP                          0x000701        /**< 初始化播放器XP失败 */
#define ERR_XP_FAIL_TO_CLEANUP_XP                       0x000702        /**< 释放播放器XP资源失败 */
#define ERR_XP_FAIL_TO_START_XP                         0x000703        /**< 启动播放器XP失败 */
#define ERR_XP_FAIL_TO_STOP_XP                          0x000704        /**< 停止播放器XP失败 */
#define ERR_XP_FAIL_TO_REGIST_XP                        0x000705        /**< 注册播放器XP失败 */
#define ERR_XP_FAIL_TO_UNREGIST_XP                      0x000706        /**< 注销播放器XP失败 */
#define ERR_XP_FAIL_TO_SET_PARAM                        0x000707        /**< 设置播放器XP的配置参数失败 */
#define ERR_XP_EXCEED_MAX_PLAY_WINDOW_NUM               0x000708        /**< 注册的播放窗口数已超过了最大支持的播放窗口数 */
#define ERR_XP_WINDOW_ALREADY_SET                       0x000709        /**< 通道已被注册 */
#define ERR_XP_EXCEED_MAX_PLAY_PORT_NUM                 0x00070A        /**< 注册的播放通道数已超过了最大支持的播放通道数 */
#define ERR_XP_NOT_SUPPORT                              0x00070B        /**< 不支持该功能*/
#define ERR_XP_UNKNOWN_ERROR                            0x00070C        /**< 未知错误*/

/* 加载和释放动态库资源返回错误码 */
#define ERR_XP_DLL_NOT_EXIST                            0x000720        /**< 指定的动态库不存在 */
#define ERR_XP_FAIL_TO_LOAD_DLL                         0x000721        /**< 加载动态库失败 */
#define ERR_XP_FAIL_TO_UNLOAD_DLL                       0x000722        /**< 卸载动态库失败 */
#define ERR_XP_FAIL_TO_WRITE_FILE                       0x000723        /**< 写文件操作失败 */
#define ERR_XP_FAIL_TO_INIT_DLL                         0x000724        /**< 动态库初始化失败 */
#define ERR_XP_FUNCTION_CALL_ORDER_ERROR                0x000725        /**< 函数调用顺序错误 */

/* 播放器XP媒体操作返回错误码 */
#define ERR_XP_WINDOW_NOT_REGISTER                      0x000730        /**< 播放窗口没有注册 */
#define ERR_XP_PORT_NOT_AVAILABLE                       0x000731        /**< 通道不可用 */
#define ERR_XP_FAIL_TO_GET_PORT_RES                     0x000732        /**< 获得播放通道资源失败 */
#define ERR_XP_NOT_SUPPORT_MEDIA_SVC                    0x000733        /**< 播放通道的媒体业务类型不支持此操作 */
#define ERR_XP_PORT_NOT_REGISTER                        0x000734        /**< 播放通道没有注册 */
#define ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE            0x000735        /**< 播放通道的媒体编码格式不支持此操作 */
#define ERR_XP_MEDIA_RESOLUTION_CHANGE                  0x000736        /**< 播放通道的媒体流分辨率发生变化 */
#define ERR_XP_FAIL_TO_START_IMAGE                      0x000737        /**< 打开图片播放模式失败 */
#define ERR_XP_FAIL_TO_LOAD_IMAGE                       0x000738        /**< 加载图片失败 */
#define ERR_XP_FAIL_TO_STOP_IMAGE                       0x000739        /**< 关闭图片播放模式失败 */
#define ERR_XP_FAIL_TO_JOIN_FILE                        0x000740        /**< 文件合并失败 */
#define ERR_XP_FAIL_TO_OPEN_REALTIME                    0x000741        /**< 启动实时监控业务失败 */
#define ERR_XP_FAIL_TO_OPEN_VOD                         0x000742        /**< 启动点播回放业务失败 */
#define ERR_XP_FAIL_TO_OPEN_FILE                        0x000743        /**< 启动本地文件回放业务失败(用户没有权限，或者该文件正在被其他程序使用) */
#define ERR_XP_FAIL_TO_START_PLAY                       0x000744        /**< 开始播放失败 */
#define ERR_XP_FAIL_TO_PAUSE                            0x000745        /**< 暂停播放失败 */
#define ERR_XP_FAIL_TO_RESUME                           0x000746        /**< 恢复播放失败 */
#define ERR_XP_FAIL_TO_STOP_PLAY                        0x000747        /**< 停止播放失败 */
#define ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY               0x000748        /**< 倍速前进/后退播放失败 */
#define ERR_XP_FAIL_TO_STEP_PLAY                        0x000749        /**< 单帧播放失败 */
#define ERR_XP_FAIL_TO_DRAG_PLAY                        0x00074A        /**< 跳转播放失败 */
#define ERR_XP_FAIL_TO_GET_PLAY_POSITION                0x00074B        /**< 获得当前播放进度失败 */
#define ERR_XP_FAIL_TO_QUIET                            0x00074C        /**< 启用或停止声音播放失败 */
#define ERR_XP_FAIL_TO_ADJUST_VOLUME                    0x00074D        /**< 调节音量失败 */
#define ERR_XP_FAIL_TO_GET_VOLUME                       0x00074E        /**< 获得音量值失败 */
#define ERR_XP_FAIL_TO_SNATCH_ONCE                      0x00074F        /**< 单次抓拍失败 */
#define ERR_XP_FAIL_TO_START_SERIES_SNATCH              0x000750        /**< 启动连续抓拍失败 */
#define ERR_XP_FAIL_TO_SERIES_SNATCH                    0x000751        /**< 连续抓拍过程中抓拍失败 */
#define ERR_XP_FAIL_TO_STOP_SERIES_SNATCH               0x000752        /**< 停止连续抓拍失败 */
#define ERR_XP_FAIL_TO_START_RECORD_VIDEO               0x000753        /**< 启动本地录像失败 */
#define ERR_XP_FAIL_TO_STOP_RECORD_VIDEO                0x000754        /**< 停止本地录像失败 */
#define ERR_XP_FAIL_TO_RECORD_VIDEO                     0x000755        /**< 本地录像过程中出错 */
#define ERR_XP_FAIL_TO_START_RECORD_AUDIO               0x000756        /**< 启动录音失败 */
#define ERR_XP_FAIL_TO_STOP_RECORD_AUDIO                0x000757        /**< 停止录音失败 */
#define ERR_XP_FAIL_TO_RECORD_AUDIO                     0x000758        /**< 录音过程中出错 */
#define ERR_XP_DOWNLOAD_PORT_NUM_LIMIT                  0x000759        /**< 超过最大下载通道数 */
#define ERR_XP_FAIL_TO_START_DOWNLOAD                   0x00075A        /**< 启动下载录像失败 */
#define ERR_XP_FAIL_TO_GET_DOWNLOAD_POSITION            0x00075B        /**< 获得当前录像下载进度失败 */
#define ERR_XP_MIC_NOT_EXIST                            0x00075C        /**< 系统中麦克风适配不存在 */
#define ERR_XP_NO_PICTURE_TO_SNATCH                     0x00075D        /**< 没有解码过的图片可供抓拍 */
#define ERR_XP_DECODE_AUDIO_NOT_CONTINUE                0x00075E        /**< 音频流数据解码后不继续进行播放操作 */
#define ERR_XP_FAIL_TO_OPEN_DOWNLOAD                    0x00075F        /**< 启动下载业务失败 */
#define ERR_XP_IN_PAUSE_PLAY_STATUS                     0x000760        /**< 当前正处于暂停播放状态 */
#define ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS             0x000761        /**< 当前正处于倍速播放状态 */
#define ERR_XP_IN_STEP_PLAY_STATUS                      0x000762        /**< 当前正处于单帧播放状态 */
#define ERR_XP_IN_RECORD_VIDEO_STATUS                   0x000763        /**< 当前正处于本地录像状态 */
#define ERR_XP_NOT_SUPPORT_DOWNLOAD_FORMAT              0x000764        /**< 下载格式不支持 */
#define ERR_XP_NOT_SUPPORT_SET_CONTRAST                 0x000765        /**< 播放通道不支持设置图像对比度参数 */
#define ERR_XP_FAIL_TO_SET_CONTRAST                     0x000766        /**< 设置图像对比度参数失败 */
#define ERR_XP_FAIL_TO_OPEN_VOICE_TALKBACK              0x000767        /**< 启动语音对讲失败 */
#define ERR_XP_FAIL_TO_CLOSE_VOICE_TALKBACK             0x000768        /**< 停止语音对讲失败 */
#define ERR_XP_FAIL_TO_OPEN_VOICE_BROADCAST             0x000769        /**< 启动语音广播失败 */
#define ERR_XP_FAIL_TO_CLOSE_VOICE_BROADCAST            0x00076A        /**< 停止语音广播失败 */
#define ERR_XP_ALREADY_START_VOICE_TALKBACK             0x00076B        /**< 语音对讲已经启动 */
#define ERR_XP_ALREADY_START_VOICE_BROADCAST            0x00076C        /**< 语音广播已经启动 */
#define ERR_XP_NOT_START_VOICE_SVC                      0x00076D        /**< 未启动语音业务 */
#define ERR_XP_NOT_START_VOICE_TALKBACK                 0x00076E        /**< 未启动语音对讲业务 */
#define ERR_XP_NOT_START_VOICE_BROADCAST                0x00076F        /**< 未启动语音广播业务 */
#define ERR_XP_FAIL_TO_VOICE_SILENCE                    0x000770        /**< 启动或停止向语音对端发送语音数据失败 */
#define ERR_XP_FAIL_TO_GET_LOST_PKT_RATE                0x000771        /**< 获得当前丢包率数据失败 */
#define ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE              0x000772        /**< 复位丢包率失败 */
#define ERR_XP_FAIL_TO_GET_FRAME_RATE                   0x000773        /**< 获得当前帧率数据失败 */
#define ERR_XP_FAIL_TO_GET_BIT_RATE                     0x000774        /**< 获得当前码率数据失败 */
#define ERR_XP_FAIL_TO_RESET_BUFFER                     0x000775        /**< 清空缓冲区失败 */
#define ERR_XP_FAIL_TO_SET_FIELD_MODE                   0x000776        /**< 设置解码场模式失败 */
#define ERR_XP_FAIL_TO_ENABLE_DEINTERLACE               0x000777        /**< 启动或关闭去交织处理失败 */
#define ERR_XP_FAIL_TO_SET_DEINTERLACE_MODE             0x000778        /**< 设置去交织处理模式失败 */
#define ERR_XP_FAIL_TO_INPUT_DATA                       0x000779        /**< 输入媒体流数据失败 */
#define ERR_XP_NOT_SUPPORT_STREAM_FORMAT                0x00077A        /**< 不支持的码流类型 */
#define ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB              0x00077B        /**< 设置媒体流数据回调函数失败 */
#define ERR_XP_FAIL_TO_ENABLE_OUTPUT_DATA               0x00077C        /**< 启动或关闭解码后媒体流数据输出失败 */
#define ERR_XP_FAIL_TO_SET_PORT_PARAM                   0x00077D        /**< 设置通道的参数失败 */
#define ERR_XP_FAIL_TO_START_VOICE_SVC                  0x00077E        /**< 启动语音业务失败 */
#define ERR_XP_FAIL_TO_STOP_VOICE_SVC                   0x00077F        /**< 停止语音业务失败 */
#define ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE              0x000780        /**< 获得当前丢帧率数据失败 */
#define ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE            0x000781        /**< 复位丢帧率失败 */
#define ERR_XP_FAIL_TO_SET_WAVEIN_MOD                   0x000782        /**< 设置音频输入源失败 */
#define ERR_XP_FAIL_TO_SET_RENDER_SCALE                 0x000783        /**< 设置图像显示比例参数失败 */
#define ERR_XP_ALREADY_START_SERIES_SNATCH              0x000784        /**< 播放通道已经启动连续抓拍操作 */
#define ERR_XP_ALREADY_START_RECORD_VIDEO               0x000785        /**< 播放通道已经启动本地录像操作 */
#define ERR_XP_ALREADY_START_RECORD_AUDIO               0x000786        /**< 播放通道已经启动录音操作 */
#define ERR_XP_NOT_START_SERIES_SNATCH                  0x000787        /**< 播放通道未启动连续抓拍操作 */
#define ERR_XP_NOT_START_RECORD_VIDEO                   0x000788        /**< 播放通道未启动本地录像操作 */
#define ERR_XP_NOT_START_RECORD_AUDIO                   0x000789        /**< 播放通道未启动录音操作 */
#define ERR_XP_ALREADY_START_OUTPUT_MEDIA               0x00078A        /**< 播放通道已经启动媒体流输出操作 */
#define ERR_XP_ALREADY_STOP_OUTPUT_MEDIA                0x00078B        /**< 播放通道未启动媒体流输出操作 */
#define ERR_XP_FINISH_SERIES_SNATCH                     0x00078C        /**< 完成连续抓拍任务 */
#define ERR_XP_PORT_NOT_EXIST                           0x00078D        /**< 通道不存在 */
#define ERR_XP_PORT_ALREADY_EXIST                       0x00078E        /**< 通道已经存在 */
#define ERR_XP_PORT_ALREADY_OPEN                        0x00078F        /**< 通道已经启动 */
#define ERR_XP_PORT_NOT_OPEN                            0x000790        /**< 通道未打开媒体业务 */
#define ERR_XP_NOT_START_PLAY                           0x000791        /**< 播放通道未开始播放操作 */
#define ERR_XP_FAIL_TO_OPEN_NET_MEDIA                   0x000792        /**< 打开网络媒体失败 */
#define ERR_XP_FAIL_TO_PLAY_MEDIA                       0x000793        /**< 媒体播放处理失败 */
#define ERR_XP_FAIL_TO_PAUSE_MEDIA                      0x000794        /**< 暂停媒体播放处理失败 */
#define ERR_XP_FAIL_TO_RESUME_MEDIA                     0x000795        /**< 恢复媒体播放处理失败 */
#define ERR_XP_FAIL_TO_STOP_MEDIA                       0x000796        /**< 停止媒体播放处理失败 */
#define ERR_XP_NOT_SUPPORT_FILE_FORMAT                  0x000797        /**< 文件播放格式不支持 */
#define ERR_XP_NOT_SUPPORT_SNATCH_FORMAT                0x000798        /**< 抓拍格式不支持 */
#define ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT          0x000799        /**< 录像格式不支持 */
#define ERR_XP_NOT_SUPPORT_RECORD_AUDIO_FORMAT          0x00079A        /**< 录音格式不支持 */
#define ERR_XP_DISK_CAPACITY_WARN                       0x00079B        /**< 硬盘剩余空间低于阈值 */
#define ERR_XP_DISK_CAPACITY_NOT_ENOUGH                 0x00079C        /**< 硬盘剩余空间不足，无法继续业务 */
#define ERR_XP_FAIL_TO_GET_TOTAL_TIME                   0x00079D        /**< 获得文件总的播放时间失败 */
#define ERR_XP_FINISH_PLAY_FILE                         0x00079E        /**< 文件已经播放完成 */
#define ERR_XP_FILE_DESTROY                             0x00079F        /**< 文件已损坏 */
#define ERR_XP_FILE_HAVE_OPEN                           0x0007A0        /**< 通道已经打开文件 */
#define ERR_XP_FAIL_TO_DECODE_VIDEO                     0x0007A1        /**< 视频解码失败 */
#define ERR_XP_FAIL_TO_DECODE_AUDIO                     0x0007A2        /**< 音频解码失败 */
#define ERR_XP_NOT_SUPPORT_MEDIA_STREAM_TYPE            0x0007A3        /**< 不支持的媒体码流类型 */
#define ERR_XP_NOT_SUPPORT_TRANSPORT_PROTOCOL_TYPE      0x0007A4        /**< 不支持的传输层协议类型 */
#define ERR_XP_FAIL_TO_RECV_DATA                        0x0007A5        /**< 网络故障导致接收数据失败 */
#define ERR_XP_FAIL_TO_SEND_DATA                        0x0007A6        /**< 网络故障导致发送数据失败 */
#define ERR_XP_FAIL_TO_OPERATE_AUDIO_EQUIPMENT          0x0007A7        /**< 音频设备操作失败 */
#define ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE            0x0007A8        /**< 获得视频编码格式失败 */
#define ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA               0x0007A9        /**< 媒体数据处理失败 */
#define ERR_XP_FAIL_TO_START_REALREPLAY                 0x0007AA        /**< 开始即时回放失败 */
#define ERR_XP_SET_REALREPLAY_TIME_LARGE                0x0007AB        /**< 设置即时回放时间太长 */
#define ERR_XP_VOICE_RUNNING                            0x0007AC        /**< 语音业务运行过程中出错*/
#define ERR_XP_FAIL_TO_OPEN_STREAM                      0x0007AD        /**< 启动媒体流播放失败 */
#define ERR_XP_FAIL_TO_CREATE_SOCKET                    0x0007AE        /**< Socket创建失败 */
#define ERR_XP_PLAY_ALREADY_START                       0x0007AF        /**< 通道已经启动播放 */

/* 流控协商 */
#define ERR_XP_FAIL_TO_SETUP_PROTOCOL                   0x0007B0        /**< 建立流控协商失败 */
#define ERR_XP_FAIL_TO_PLAY_PROTOCOL                    0x0007B1        /**< 流控协商播放失败 */
#define ERR_XP_FAIL_TO_PAUSE_PROTOCOL                   0x0007B2        /**< 流控协商暂停失败 */
#define ERR_XP_FAIL_TO_STOP_PROTOCOL                    0x0007B3        /**< 停止流控协商失败 */
#define ERR_XP_RTSP_COMPLETE                            0x0007B4        /**< RTSP播放或下载完成 */
#define ERR_XP_RTSP_ABNORMAL_TEATDOWN                   0x0007B5        /**< RTSP异常下线，服务器读取文件错误或数据被覆写 */
#define ERR_XP_RTSP_KEEP_LIVE_TIME_OUT                  0x0007B6        /**< RTSP保活失败 */
#define ERR_XP_RTSP_ENCODE_CHANGE                       0x0007B7        /**< RTSP中码流格式切换 */
#define ERR_XP_RTSP_DISCONNECT                          0x0007B8        /**< RTSP连接断开，点播回放或下载已自动终止，请检查网络 */
#define ERR_XP_RTSP_DISCONNECT_ONVIF                    0x0007B9        /**< ONVIF实况直连时，Rtsp连接断开，等待重连 */
#define ERR_XP_RTSP_MSREPLAY_VODONWALL_NOTSUPPORT       0x0007BA        /**< 经过MS中继的回放上墙不支持 */
#define ERR_XP_RTSP_VODONWALL_FAIL                      0x0007BB        /**< 回放上墙启动失败 */
#define ERR_XP_SIP_NEGORIATE_TIMEOUT                    0x0007BC        /**< SIP协商超时 */
#define ERR_XP_SIP_SESSION_OVERLAY                      0x0007BD        /**< SIP会话重复，进行释放 */
#define ERR_XP_SIP_ONVIF_RECONNECT_TIMEOUT              0x0007BE        /**< Onvif重连超时，进行释放 */
#define ERR_XP_RTSP_COMPLETE_CLOSE                      0x0007BF        /**< 播放到末尾结束，国标需求 */

/* 会话控制 */
#define ERR_XP_FAIL_TO_SETUP_SESSION                    0x0007C0        /**< 发起会话请求失败 */
#define ERR_XP_FAIL_TO_QUIT_SESSION                     0x0007C1        /**< 退出会话失败 */
#define ERR_XP_AUDIO_DEVICE_UNRIPE                      0x0007C2        /**< 音频设备未准备好 */

#define ERR_XP_RTSP_ONVIF_FAIL                          0x0007C5        /**< ONVIF实况时，与设备进行RTSP请求失败 */

/* Rtsp 会话错误 */
#define ERR_XP_RTSP_REQ_TIMEOUT                         0x0007D1        /**< 流控业务处理超时 */
#define ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH                0x0007D2        /**< 流控业务带宽不足 */
#define ERR_XP_RTSP_SERVINTERERR                        0x0007D3        /**< 流控业务内部错误 */

/* 播放业务*/
#define ERR_XP_FAIL_TO_CLOSE_FILE                       0x0007D4        /**< 关闭文件播放失败 */
#define ERR_XP_FAIL_TO_CLOSE_STREAM                     0x0007D5        /**< 关闭媒体流播放失败 */
#define ERR_XP_INPUTDATA_BUFFER_FULL                    0x0007D6        /**< 输入数据缓存满 */
#define ERR_XP_MEDIA_STREAM_NOT_SUPPORT                 0x0007D7        /**< 无法识别（或不支持）的码流 */
#define ERR_XP_FAIL_TO_PLAY_SOUND                       0x0007D8        /**< 启动声音播放失败 */
#define ERR_XP_FAIL_TO_STOP_SOUND                       0x0007D9        /**< 关闭声音播放失败 */
#define ERR_XP_FAIL_TO_OPEN_VOICE_SVC                   0x0007DA        /**< 启动语音业务失败 */
#define ERR_XP_FAIL_TO_CLOSE_VOICE_SVC                  0x0007DB        /**< 关闭语音业务失败 */
#define ERR_XP_FAIL_TO_SET_DIGITALZOOM                  0x0007DC        /**< 设置数字放大失败 */
#define ERR_XP_FAIL_TO_GET_PIC_PARAM                    0x0007DD        /**< 通道获取图片信息错误 */
#define ERR_XP_FAIL_TO_BEGINHVDC                        0x0007DE        /**< 开始画图失败 */
#define ERR_XP_FAIL_TO_ENABLEANALYSERULE                0x0007DF        /**< 设置显示智能规则失败 */
#define ERR_XP_FAIL_TO_ENABLEANALYSERESULT              0x0007E0        /**< 设置显示智能结果失败 */
#define ERR_XP_FAIL_TO_START_COMBINE_IMAGE              0x0007E1        /**< 启动图像拼接操作失败 */
#define ERR_XP_FAIL_TO_MARK_COMBINE_IMAGE               0x0007E2        /**< 设定图像拼接特征点失败 */
#define ERR_XP_FAIL_TO_STOP_COMBINE_IMAGE               0x0007E3        /**< 停止图像拼接操作失败 */
#define ERR_XP_FAIL_TO_START_COMBINE_ZOOM               0x0007E4        /**< 启动拼接图片数字放大失败 */
#define ERR_XP_FAIL_TO_STOP_COMBINE_ZOOM                0x0007E5        /**< 停止拼接图片数字放大失败 */
#define ERR_XP_FAIL_TO_MOVE_COMBINE_ZOOM                0x0007E6        /**< 修改拼接图片数字放大失败 */
#define ERR_XP_FAIL_TO_SET_DECODER_MODE                 0x0007E7        /**< 设置解码模式失败 */
#define ERR_XP_FAIL_TO_SET_VIDEO_ADJUST                 0x0007E8        /**< 设置影像调节失败 */
#define ERR_XP_FAIL_TO_SET_VIDEO_MOTION_BLUR            0x0007E9        /**< 设置模糊处理失败 */
#define ERR_XP_FAIL_TO_SET_VIDEO_SHARPEN                0x0007EA        /**< 设置锐化处理失败 */
#define ERR_XP_FAIL_TO_SET_DE_FOG                       0x0007EB        /**< 设置去雾处理失败 */
#define ERR_XP_FAIL_TO_SET_ANTI_FLICKER                 0x0007EC        /**< 设置防闪烁处理失败 */
#define ERR_XP_FAIL_TO_SIP_NEGORIATE                    0x0007ED        /**< SIP协商失败 */
#define ERR_XP_NOT_SUPPORT_DECODERTAG                   0x0007EE        /**< 解码插件不存在或厂商不支持 */
#define ERR_XP_FAIL_TO_SET_STARTSTOP_TIME               0x0007EF        /**< 设置开始时间和结束时间失败 */
#define ERR_XP_RECOERD_REBUILD                          0x0007F0        /**<下载或录像重建 */
#define ERR_XP_FAIL_TO_KEEP_LIVE_STREAM                 0x0007F1        /**< 码流保活失败 */
#define ERR_XP_FAIL_LOGIN_BALL                          0x0007F2        /**< 登录球机失败 */
#define ERR_XP_FAIL_MARK_BALL                           0x0007F3        /**< 球机绑定失败 */
#define ERR_XP_FAIL_OPT_BALL_COMMAND                    0x0007F4        /**< 球机命令操作失败 */
#define ERR_XP_BALL_CAMERA_LOGOUT                       0x0007F5        /**< 登出球机失败 */
#define ERR_XP_FAIL_TO_BUILD_FILE_INDEX                 0x0007F6        /**< 建立文件索引失败 */
#define ERR_XP_FAIL_TO_SET_OSD                          0x0007F7        /**< 设置OSD失败 */
#define ERR_XP_FAIL_TO_STOP_OSD                         0x0007F8        /**< 关闭OSD失败 */

#define ERR_XP_FAIL_TO_SET_AUDIO_CHANNEL                0x0007F9        /**< 设置音频声道失败 */
#define ERR_XP_FAIL_NO_RIGHT_AUDIO_CHANNEL              0x0007FA        /**< 没有音频右声道 */

#define ERR_XP_FAIL_TO_SET_BARREL_ADJUST                0x0007FB        /**< 设置桶型矫正失败 */
#define ERR_XP_FAIL_TO_SET_DISPLAY_HDC_CB               0x0007FC        /**< 设置显示HDC回调函数失败 */
#define ERR_XP_MEDIA_BUFFER_HIGH_LEVEL                  0x0007FD        /**< 媒体缓存高水位 */
#define ERR_XP_MEDIA_BUFFER_LOW_LEVEL                   0x0007FE        /**< 媒体缓存低水位 */
#define ERR_XP_FAIL_TO_SET_MEDIA_SVC_TYPE               0x0007FF        /**< 设置媒体业务类型失败 */

#define ERR_XP_FINISH_SERIES_ONESNATCH                  0x000800        /**< 连续抓拍成功抓拍一张图片*/

/* Add by sunbiao/sW1071 2014.10.28 for MPPD18406 新增dsp去抖动 */
#define ERR_XP_FAIL_TO_SET_DESHAKE                      0x000801        /**< 设置去抖动失败 */

/* Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */
#define ERR_XP_FAIL_TO_SET_VOD_TIME_CB                  0x000802        /**< 设置获取点播回放时间的回调函数失败 */

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */
#define ERR_XP_FAIL_TO_SET_CUR_POS_CB                   0x000803        /**< 设置setCurDownPosCallback回调函数失败 */
#define ERR_XP_FAIL_TO_SET_DOWNLOAD_TYPE                0x000804        /**< 设置setDownloadType函数失败 */
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP客户端录像时支持大小限制 */
/* begin add by liguopeng01371 2015-1-27 MPPD05811 解决轮切显存碎片问题 */
#define ERR_XP_FAIL_TO_SET_RENDER_RESOURCE_MODE         0x000805           /* 设置显存释放模式失败 */
#define ERR_XP_FAIL_TO_SET_PROXY                        0x000806           /**< 设置代理失败 */
#define ERR_XP_FAIL_TO_DELETE_ALL_SVC_AND_WND         0x000807           /**< 删除所有svc和窗口句柄 */

/* Added by shichao/W1439 2015/4/29 */
#define ERR_XP_FAIL_TO_ENABLE_IA_GPU_DECODE             0x000808       /**< 启动GPU解码失败 */
#define ERR_XP_FAIL_BL_MATCHERROR                        0x000809        /*枪球联动矩阵求解失败*/
#define ERR_XP_FAIL_TO_SET_MEDIA_SECTION_TIME    0x00080A   /*设置媒体片段时间信息失败*/
#define ERR_XP_FAIL_TO_SET_FISH_ADJUST                  0x00080B        /* 设置鱼眼矫正失败 */

/**********注意：XP错误码值范围为：[0x000700—0x0008FF] *****************/


/************************************************************************/
/*************************** 文件后缀名长度******************************/
/************************************************************************/
#define IMOS_XP_FILE_POSTFIX_LEN    32


/************************************************************************/
/*********************** XP SDK数据结构类型定义**************************/
/************************************************************************/
/* Begin:Added by lizhen in 2017-9-1 for 鱼眼矫正 */
/* 鱼眼矫正需要的参数 */
#define PTZ_NUM_MAX      (9)    /*最大支持的虚拟PTZ个数*/
#define FALSE_PTZ_ID      10    /* 无效PTZID */
#define FALSE_AREA_ID     10    /* 无效标定框ID */
/* End:Added by lizhen in 2017-9-1 for 鱼眼矫正 */

/**
* @enum tagPlayType
* @brief 通道播放业务类型枚举定义
* @attention 无
*/
typedef enum tagPlayType
{
    XP_PLAY_REALTIME = 0,               /**< 实时监控 */
    XP_PLAY_VOD = 1,                    /**< 回放 */
    XP_PLAY_INTELLIGENT = 2             /**< 智能相关业务 */
}XP_PLAY_TYPE_E;

/**
* @enum tagPictureFluency
* @brief 图像播放流畅性枚举类型定义
* @attention 无
*/
typedef enum tagPictureFluency
{
    XP_PICTURE_TIME_PRIORITY = 0,         /**< 实时性优先 */
    XP_PICTURE_FLUENCY_PRIORITY = 1,      /**< 流畅性优先 */
    XP_PICTURE_TIME_FLUENCY_AUTO = 2,     /**< 自适应 */
    XP_PICTURE_HIGH_LOWDELAY = 3,         /**< 超低延时 */
}XP_PICTURE_FLUENCY_E;

/**
* @enum tagRenderScale
* @brief 播放窗格显示图像的比例枚举类型定义
* @attention 无
*/
typedef enum tagRenderScale
{
    XP_RENDER_SCALE_FULL = 0,               /**< 图像填充整个播放窗格 */
    XP_RENDER_SCALE_PROPORTION = 1          /**< 图像按比例显示 */
}XP_RENDER_SCALE_E;

/**
* @enum tagPictureFormat
* @brief 图片格式枚举定义
* @attention 无
*/
typedef enum tagPictureFormat
{
    XP_PICTURE_BMP = 0,                 /**< 图片格式为bmp格式 */
    XP_PICTURE_JPG = 1                  /**< 图片格式为jpg格式 */
}XP_PICTURE_FORMAT_E;

/**
* @enum tagVideoEncodeType
* @brief 视频编码格式枚举定义
* @attention 无
*/
typedef enum tagVideoEncodeType
{
    XP_VIDEO_ENCODE_MPEG2 = 0,          /**< 视频符合MPEG-2标准 */
    XP_VIDEO_ENCODE_MPEG4 = 1,          /**< 视频符合MPEG-4标准 */
    XP_VIDEO_ENCODE_H264 = 2,           /**< 视频符合H.264标准 */
    XP_VIDEO_ENCODE_MJPEG = 3,          /**< 视频符合MJPEG标准 */
    /* add by chenxiangyi 02451 MPPD27703 h265合入主线 */
    XP_VIDEO_ENCODE_H265 = 4            /**< 视频符合h.265标准 */
}XP_VIDEO_ENCODE_TYPE_E;

/**
* @enum tagAudioEncodeType
* @brief 音频编码格式枚举定义
* @attention 无
*/
typedef enum tagAudioEncodeType
{
    XP_AUDIO_ENCODE_G711U = 0,          /**< 音频符合G.711U律标准 */
    XP_AUDIO_ENCODE_MP2 = 1,            /**< 音频符合MP2编码标准 */
    XP_AUDIO_ENCODE_AAC = 2,            /**< 音频符合AAC编码标准 */
    XP_AUDIO_ENCODE_G711A = 3,          /**< 音频符合G.711A律标准 */
    XP_AUDIO_ENCODE_PCMA = 4            /**< 音频符合PCMA律标准 */
}XP_AUDIO_ENCODE_TYPE_E;

/**
* @enum tagMediaFileFormat
* @brief 媒体文件格式枚举定义
* @attention 无
*/
typedef enum tagMediaFileFormat
{
    XP_MEDIA_FILE_TS  = 0,                  /**< TS格式的媒体文件 */
    XP_MEDIA_FILE_FLV = 1,                  /**< FLV格式的媒体文件 */
    XP_MEDIA_FILE_AVI = 2,                  /**< AVI格式的媒体文件 */
    XP_MEDIA_FILE_MP4 = 3,                  /**< MP4格式的媒体文件 */
    XP_MEDIA_FILE_WMV = 4,                  /**< MP4格式的媒体文件 */
    XP_MEDIA_FILE_MKV = 5,                  /**< MKV格式的媒体文件 */
    XP_MEDIA_FILE_ASF = 6,                  /**< ASF格式的媒体文件 */
    XP_MEDIA_FILE_M4V = 7,                  /**< M4V格式 */
    XP_MEDIA_FILE_H264 = 8,                 /**< H264裸码流格式 */
    XP_MEDIA_FILE_MPEG = 9,                 /**< MPEG裸码流格式 */

    XP_MEDIA_FILE_H3C_PRIVATE = 100,        /* H3C V1私有格式 */
    XP_MEDIA_FILE_HIK_PRIVATE = 101,        /* 海康私有格式 */
    XP_MEDIA_FILE_DAHUA_PRIVATE = 102,      /* 大华私有格式 */
    XP_MEDIA_FILE_MOBOTIX_PRIVATE = 103,    /* mobotix私有格式 */
    XP_MEDIA_FILE_NANZI_PRIVATE = 104,      /* 南自私有格式 */
    XP_MEDIA_FILE_RM_PRIVATE = 105,         /* 锐明私有格式 */
    XP_MEDIA_FILE_HANBANG_PRIVATE = 106,    /* 汉邦私有格式 */
    XP_MEDIA_FILE_CHENGFENG_PRIVATE = 107,  /* 诚丰私有格式 */

    XP_MEDIA_FILE_UNKNOWN = 0XFFFFFFFF
}XP_MEDIA_FILE_FORMAT_E;

/**
* @enum tagRenderMode
* @brief 视频显示模式枚举定义
* @attention 无
*/
typedef enum tagRenderMode
{
    XP_RENDER_MODE_D3D = 0,             /**< 使用D3D的方式进行显示 */
    XP_RENDER_MODE_DDRAW_NORMAL = 1 ,    /**< 使用Ddraw的Normal显示模式 */
    XP_RENDER_MODE_LOWER = 2,           /**< 使用低品质显示模式 */
    XP_RENDER_MODE_MAX = 0xFF
}XP_RENDER_MODE_E;

/**
* @enum tagPixelFormat
* @brief 视频像素格式枚举定义，主要在老接口函数#XP_SetPixelFormat中使用。
* @attention 无
*/
typedef enum tagPixelFormat
{
    XP_PIXEL_FORMAT_YUV = 0,            /**< YUV格式输出 */
    XP_PIXEL_FORMAT_RGB = 1             /**< RGB格式输出 */
}XP_PIXEL_FORMAT_E;

/**
* @enum tagPixelFormatEx
* @brief 视频像素格式枚举增强定义，主要在新接口函数#IMOS_SetPixelFormat中使用。
*        和tagPixelFormat枚举区别在于细化了视频像素格式
* @attention 无
*/
typedef enum tagPixelFormatEx
{
    XP_PIXEL_FORMAT_YUV420 = 0,         /**< YUV420格式输出 */
    XP_PIXEL_FORMAT_RGB32 = 1           /**< RGB32格式输出 */
}XP_PIXEL_FORMAT_EX_E;

/**
* @enum tagFieldMode
* @brief 场模式枚举定义
* @attention 无
*/
typedef enum tagFieldMode
{
    XP_FIELD_MODE_SINGLE = 0,           /**< 单场模式 */
    XP_FIELD_MODE_DOUBLE = 1            /**< 双场模式 */
}XP_FIELD_MODE_E;

/**
* @enum tagDeinterlaceMode
* @brief 去交织处理模式的枚举定义
* @attention 无
*/
typedef enum tagDeinterlaceMode
{
    XP_DEINTERLACE_NONE = 0,            /**< 不启用去交织处理 */
    XP_DEINTERLACE_DOUBLETOPFIELG = 1,  /**< 顶场拷贝到底场模式 */
    XP_DEINTERLACE_BLEND = 2,           /**< 混合模式 */
    XP_DEINTERLACE_X  = 3               /**< x模式 */
}XP_DEINTERLACE_MODE_E;

/**
* @enum tagWaveInSource
* @brief 音频输入源设置
* @attention 无
*/
typedef enum tagWaveInSource
{
    XP_WAVEIN_SOURCE_DEVICE = 0,        /**< 麦克风作音频输入源 */
    XP_WAVEIN_SOURCE_FILE = 1,          /**< 音频文件作音频输入源 */
    XP_WAVEIN_SOURCE_INPUT = 2          /**< 用户输入音频数据作为音频输入源 */
}XP_WAVEIN_SOURCE_E;

/**
* @enum tagAudioSampleFormatType
* @brief 音频位宽
* @attention 无
*/
typedef enum tagXPAudioSampleFormatType
{
    XP_AUDIO_SAMPLE_FMT_NONE = -1,
    XP_AUDIO_SAMPLE_FMT_U8,          ///< 无符号8位整型
    XP_AUDIO_SAMPLE_FMT_S16,         ///< 有符号16位整型
    XP_AUDIO_SAMPLE_FMT_S32,         ///<  有符号32位整型
    XP_AUDIO_SAMPLE_FMT_FLT,         ///< 浮点型
    XP_AUDIO_SAMPLE_FMT_DBL,         ///< double型
} XP_AUDIO_SAMPLE_FORMAT_E;

/**
* @struct tagAudioSampleParamType
* @brief 音频参数
* @attention 无
*/
typedef struct tagXPAudioSampleParamType
{
    ULONG ulChannels;                     /**< 声道数，单声道为1，立体声为2 */
    ULONG ulSampleRate;                   /**< 采样率 */
    XP_AUDIO_SAMPLE_FORMAT_E enSampleFormat; /**< 位宽 */
} XP_AUDIO_SAMPLE_PARAM_S;

/**
* @enum tagRecordQuality
* @brief 录像质量枚举定义
* @attention 无
*/
typedef enum tagRecordQuality
{
    XP_RECORD_PRIORITY = 0,             /**< 播放时录像处理质量优先*/
    XP_PLAY_PRIORITY = 1                /**< 播放时播放处理优先*/
}XP_RECORD_QUALITY_E;

/**
* @enum tagMediaDataLostSplitterPolicy
* @brief 码流丢包情况下拼帧策略的枚举定义
* @attention 无
*/
typedef enum tagMediaDataLostSplitterPolicy
{
    XP_MEDIA_LOST_NO_SPLITTER = 0 ,       /**< 码流丢包情况下丢弃处理 */
    XP_MEDIA_LOST_CONTINUE_SPLITTER = 1   /**< 码流丢包情况下继续拼帧 */
}XP_MEDIA_DATA_LOST_SPLITTER_POLICY;

/**
* @enum tagPlayStatus
* @brief 播放状态枚举定义
* @attention 无
*/
typedef enum tagPlayStatus
{
    XP_PLAY_STATUS_16_BACKWARD = 0,         /**< 16倍速后退播放 */
    XP_PLAY_STATUS_8_BACKWARD = 1,          /**< 8倍速后退播放 */
    XP_PLAY_STATUS_4_BACKWARD = 2,          /**< 4倍速后退播放 */
    XP_PLAY_STATUS_2_BACKWARD = 3,          /**< 2倍速后退播放 */
    XP_PLAY_STATUS_1_BACKWARD = 4,          /**< 正常速度后退播放 */
    XP_PLAY_STATUS_HALF_BACKWARD = 5,       /**< 1/2倍速后退播放 */
    XP_PLAY_STATUS_QUARTER_BACKWARD = 6,    /**< 1/4倍速后退播放 */
    XP_PLAY_STATUS_QUARTER_FORWARD = 7,     /**< 1/4倍速播放 */
    XP_PLAY_STATUS_HALF_FORWARD = 8,        /**< 1/2倍速播放 */
    XP_PLAY_STATUS_1_FORWARD = 9,           /**< 正常速度前进播放 */
    XP_PLAY_STATUS_2_FORWARD = 10,          /**< 2倍速前进播放 */
    XP_PLAY_STATUS_4_FORWARD = 11,          /**< 4倍速前进播放 */
    XP_PLAY_STATUS_8_FORWARD = 12,          /**< 8倍速前进播放 */
    XP_PLAY_STATUS_16_FORWARD = 13,         /**< 16倍速前进播放 */
    XP_PLAY_STATUS_SUPER_FAST_FORWARD = 14,  /**< 超快前进播放 */
    XP_PLAY_STATUS_ONEEIGHTH_FORWARD = 15     /**< 1/8倍速播放 */
}XP_PLAY_STATUS_E;

/**
* @enum tagRunInfoType
* @brief 上报消息类型的枚举定义
* @attention 无
*/
typedef enum tagRunInfoType
{
    XP_RUN_INFO_SERIES_SNATCH = 0,        /**< 连续抓拍过程中上报运行信息 */
    XP_RUN_INFO_RECORD_VIDEO = 1,         /**< 本地录像过程中上报运行信息 */
    XP_RUN_INFO_MEDIA_PROCESS = 2,        /**< 视频媒体处理过程中的上报运行信息 */
    XP_RUN_INFO_DOWN_MEDIA_PROCESS = 3,   /**< 媒体流下载过程中上报运行信息 */
    XP_RUN_INFO_VOICE_MEDIA_PROCESS = 4,  /**< 语音媒体处理过程中的上报运行信息 */
    XP_RUN_INFO_RTSP_PROTOCOL = 5,        /**< RTSP协议组件运行的错误信息 */
    XP_RUN_INFO_DOWN_RTSP_PROTOCOL = 6,   /**< 下载录像过程中RTSP协议的错误信息 */
    XP_RUN_INFO_SIP_LIVE_TIMEOUT = 7,     /**< SIP注册保活超时 */
    XP_RUN_INFO_PASSIVE_MONITOR = 8,      /**< 被动实况停止操作信息 */
    XP_RUN_INFO_PASSIVE_START_MONITOR = 9,/**< 被动实况启动操作信息 */
    XP_RUN_INFO_MEDIA_NOT_IDENTIFY = 10,  /**< 码流无法识别 */
    XP_RUN_INFO_RECV_PACKET_NUM = 11,     /**< 周期内接收到的包数 */
    XP_RUN_INFO_RECV_BYTE_NUM = 12,       /**< 周期内接收到的字节数 */
    XP_RUN_INFO_VIDEO_FRAME_NUM = 13,     /**< 周期内解析的视频帧数 */
    XP_RUN_INFO_AUDIO_FRAME_NUM = 14,     /**< 周期内解析的音频帧数 */
    XP_RUN_INFO_LOST_PACKET_RATIO = 15,   /**< 周期内丢包率统计信息（单位为0.01%） */
    XP_RUN_INFO_MEDIA_PLAY_PROGRESS = 16, /**< 媒体中携带的进度信息 */
    XP_RUN_INFO_MEDIA_PLAY_END = 17,      /**< 媒体中携带的播放结束 */
    XP_RUN_INFO_MEDIA_ABNORMAL = 18       /**< 媒体处理异常 */
}XP_RUN_INFO_TYPE_E;

/**
* @enum tagMediaDataType
* @brief 解码后媒体流数据类型的枚举定义
* @attention 无
*/
typedef enum tagMediaDataType
{
    XP_VIDEO_DATA_DECODE = 0,           /**< 解码后的视频数据 */
    XP_AUDIO_DATA_DECODE = 1            /**< 解码后的音频数据 */
}XP_OUTPUT_MEDIA_DATA_TYPE_E;

/**
* @enum tagWaveFormatInfo
* @brief 解码后音频格式的枚举类型定义
* @attention 无
*/
typedef enum tagWaveFormatInfo
{
    XP_WAVE_FORMAT_PCM8M16 = 0,         /**< PCM，8K采样率，单声道（M），16位采样 */
    XP_WAVE_FORMAT_PCM16M16 = 1,        /**< PCM，16K采样率，单声道（M），16位采样 */
    XP_WAVE_FORMAT_PCM441M16 = 2        /**< PCM，44.1K采样率，单声道（M），16位采样 */
}XP_WAVE_FORMAT_INFO_E;

/**
* @enum tagVoiceSvcType
* @brief 语音业务类型枚举定义
* @attention 无
*/
typedef enum tagVoiceSvcType
{
    XP_VOICE_SERVICE_BROADCAST = 0,        /**< 语音广播业务类型，语音发送 */
    XP_VOICE_SERVICE_TALKBACK = 1,         /**< 语音对讲业务类型，语音收发 */
    XP_VOICE_SERVICE_BE_BROADCASTED = 2    /**< 被语音广播业务类型，语音收 */
}XP_VOICE_SERVICE_TYPE_E;

/**
* @enum tagMediaDataFormat
* @brief 媒体数据流格式
* @attention 无
*/
typedef enum tagMediaDataFormat
{
    XP_MEDIA_DATA_TS = 0,               /**< TS封装码流 */
    XP_MEDIA_DATA_ES12 = 1,             /**< RTP + 音/视频私有头（12字节） + ES码流 */
    XP_MEDIA_DATA_ES12_TIME = 2,        /**< RTP + 时间戳（8字节） + 音/视频私有头（12字节） + ES码流 */
    XP_MEDIA_DATA_RTP_ES = 3,           /**< RTP + ES码流 */
    XP_MEDIA_DATA_HIK = 4,              /**< 海康码流，回调的第一个包是海康40字节系统头 */
    XP_MEDIA_DATA_DH = 5,               /**< 大华码流 */
    XP_MEDIA_DATA_RM = 6,               /**< 锐明码流，回调的第一个包是锐明40字节系统头 */
    XP_MEDIA_DATA_TDY_SWALLOW = 7,      /**< TDY-SWALLOW */
    XP_MEDIA_DATA_DMA_SWALLOW = 8,      /**< DMA-SWALLOW */
    XP_MEDIA_DATA_NANZI = 9,            /**< 南自码流 */
    XP_MEDIA_DATA_RTP3984 = 10,         /**< 国电的rfc3984码流 */
    XP_MEDIA_DATA_RTP_PS = 11,          /**< RTP+PS */
    XP_MEDIA_DATA_RTP_H264 = 12         /**< RTP+H264 */
}XP_MEDIA_DATA_FORMAT_E;

/**
* @enum tagNetworkTransportProtl
* @brief 网络传输协议，主要在老接口函数#XP_SetTransportProtocol中使用。
* @attention 无
*/
typedef enum tagNetworkTransportProtl
{
    XP_NETWORK_TRANSPORT_PROTOCOL_UDP = 0,  /**< UDP协议 */
    XP_NETWORK_TRANSPORT_PROTOCOL_TCP = 1   /**< TCP协议 */
}XP_NETWORK_TRANSPORT_PROTOCOL_E;

/**
* @enum tagProtocol
* @brief 网络协议，主要在新接口函数#IMOS_OpenVodStream和#IMOS_StartDownMediaStream中使用。
* @attention 无
*/
typedef enum tagProtocol
{
    XP_PROTOCOL_UDP = 0,                   /**< UDP协议 */
    XP_PROTOCOL_TCP = 1,                   /**< TCP协议Client端*/
    XP_PROTOCOL_TCP_SERVER = 2             /**< TCP协议Server端*/
}XP_PROTOCOL_E;

/* begin Added by chenxiangyi W1099, 2014/9/28  onvif支持组播  MPPD17374 */
/**
* @enum tagBroadcastmethod
* @brief 媒体传播方式枚举类型定义
* @attention 无
*/
typedef enum tagBroadcastmethod
{
    XP_BM_UNICAST = 0,                     /**< 单播 */
    XP_BM_MULTICAST = 1,                   /**< 组播 */

    XP_BM_INVALID = 0xFFFFFFFF             /**< 传播方式无效 */
}XP_BROADCAST_METHOD_E;
/* end Added by chenxiangyi W1099, 2014/9/28  onvif支持组播  MPPD17374 */

/**
* @enum tagRenderTimeType
* @brief 时间戳枚举类型定义
* @attention 无
*/
typedef enum tagRenderTimeType
{
    XP_RENDER_FRAME_RATE = 0,               /**< 使用帧率数据进行视频渲染 */
    XP_RENDER_ABSOLUTE_TIME = 1             /**< 使用绝对时间数据进行视频渲染 */
}XP_RENDER_TIME_TYPE_E;

/**
* @enum tagDownMediaSpeed
* @brief 媒体数据下载速度的枚举定义
* @attention 无
*/
typedef enum tagDownMediaSpeed
{
    XP_DOWN_MEDIA_SPEED_ONE = 0,            /**< 一倍速下载媒体文件 */
    XP_DOWN_MEDIA_SPEED_TWO = 1,            /**< 二倍速下载媒体文件 */
    XP_DOWN_MEDIA_SPEED_FOUR = 2,           /**< 四倍速下载媒体文件 */
    XP_DOWN_MEDIA_SPEED_EIGHT = 3           /**< 八倍速下载媒体文件 */
}XP_DOWN_MEDIA_SPEED_E;

/**
* @enum tagNatMode
* @brief NAT方式的枚举类型
* @attention 无
*/
typedef enum tagNatMode
{
    XP_NAT_NONE = 0,                     /**< 无NAT的方式 */
    XP_NAT_IN   = 1,                     /**< NAT IN方式 */
    XP_NAT_OUT  = 2                      /**< NAT OUT方式 */
}XP_NAT_MODE_E;

/**
* @enum tagVideoFrameType
* @brief 视频帧类型的枚举定义
* @attention 无
*/
typedef enum tagVideoFrameType
{
    XP_VIDEO_FRAME_I = 0,               /**< 视频帧为I帧 */
    XP_VIDEO_FRAME_P = 1,               /**< 视频帧为P帧 */
    XP_VIDEO_FRAME_B = 2                /**< 视频帧为B帧 */
}XP_VIDEO_FRAME_TYPE_E;

/**
* @enum tagPictureContrastMode
* @brief 图像对比度模式设置
* @attention 无
*/
typedef enum tagPictureContrastMode
{
    XP_PICTURE_CONTRAST_MODE_NONE = 0,       /**< 不进行对比度调节处理 */
    XP_PICTURE_CONTRAST_MODE_BRIGHTNESS = 1, /**< 对比度明亮模式 */
    XP_PICTURE_CONTRAST_MODE_SOFTNESS = 2    /**< 对比度柔和模式 */
}XP_PICTURE_CONTRAST_MODE_E;

/**
* @enum tagJpgPictureQuality
* @brief 图像质量设置
* @attention 无
*/
typedef enum tagPictureQualityLevel
{
    JPG_PICTURE_QUALITY_LEVEL_1 = 1,
    JPG_PICTURE_QUALITY_LEVEL_2 = 2,
    JPG_PICTURE_QUALITY_LEVEL_3 = 3,
    JPG_PICTURE_QUALITY_LEVEL_4 = 4,
    JPG_PICTURE_QUALITY_LEVEL_5 = 5,
    JPG_PICTURE_QUALITY_LEVEL_6 = 6,
    JPG_PICTURE_QUALITY_LEVEL_7 = 7,
    JPG_PICTURE_QUALITY_LEVEL_8 = 8,
    JPG_PICTURE_QUALITY_LEVEL_9 = 9,
    JPG_PICTURE_QUALITY_LEVEL_10 = 10
}JPG_PICTURE_QUALITY_LEVEL_E;


/**
* @enum tagPictureContrastLevel
* @brief 图像对比度级别设置
* @attention 无
*/
typedef enum tagPictureContrastLevel
{
    XP_PICTURE_CONTRAST_LEVEL_LOW = 0,       /**< 对比度低级别 */
    XP_PICTURE_CONTRAST_LEVEL_MIDDLE = 1,    /**< 对比度中级别 */
    XP_PICTURE_CONTRAST_LEVEL_HIGH = 2       /**< 对比度高级别 */
}XP_PICTURE_CONTRAST_LEVEL_E;

/**
* @enum tagPictureContrastLevelEx
* @brief 图像对比度级别设置
* @attention 无
*/
typedef enum tagPictureContrastLevelEx
{
    XP_PICTURE_CONTRAST_LEVEL_1 = 1,        /**< 对比度1级别 */
    XP_PICTURE_CONTRAST_LEVEL_2 = 2,        /**< 对比度2级别 */
    XP_PICTURE_CONTRAST_LEVEL_3 = 3,        /**< 对比度3级别 */
    XP_PICTURE_CONTRAST_LEVEL_4 = 4,        /**< 对比度4级别 */
    XP_PICTURE_CONTRAST_LEVEL_5 = 5,        /**< 对比度5级别 */
    XP_PICTURE_CONTRAST_LEVEL_6 = 6,        /**< 对比度6级别 */
    XP_PICTURE_CONTRAST_LEVEL_7 = 7,        /**< 对比度7级别 */
    XP_PICTURE_CONTRAST_LEVEL_8 = 8,        /**< 对比度8级别 */
    XP_PICTURE_CONTRAST_LEVEL_9 = 9,        /**< 对比度9级别 */
    XP_PICTURE_CONTRAST_LEVEL_10 = 10       /**< 对比度10级别 */
}XP_PICTURE_CONTRAST_LEVEL_EX_E;

/**
* @enum tagResolutionType
* @brief 分辨率类型
* @attention 无
*/
typedef enum tagResolutionType
{
    XP_RESOLUTION_AUTO = 0,       /**< 原有的分辨率，宽×高 表示 */
    XP_RESOLUTION_D1 = 1,         /**< 720 * 576 */
    XP_RESOLUTION_4CIF = 2,       /**< 704 * 576 */
    XP_RESOLUTION_2CIF = 3,       /**< 704 * 288 */
    XP_RESOLUTION_CIF = 4,        /**< 352 * 288 */
    XP_RESOLUTION_QCIF = 5,       /**< 176 * 144 */
    XP_RESOLUTION_1080 = 6,       /**< 1920 * 1080 */
    XP_RESOLUTION_1088 = 7,       /**< 1920 * 1080 */
    XP_RESOLUTION_720 = 8         /**< 1280 * 720 */
}XP_RESOLUTION_TYPE_E;

/**
* @enum tagEncodePacketType
* @brief 码流打包类型
* @attention 无
*/
typedef enum tagEncodePacketType
{
    XP_ENC_PKT_TS = 0,             /**< TS流格式 */
    XP_ENC_PKT_RTP_ES = 1,         /**< RTP+ES流格式 */
    XP_ENC_PKT_RTP_PS = 2,         /**< RTP+PS流格式 */
    XP_ENC_PKT_RFC3984 = 3,        /**< RFC3984流格式 */
    XP_ENC_PKT_RTP_TS = 4,         /**< RTP_TS流格式 */
}XP_ENCODE_PACKET_TYPE_E;

/**
* @enum tagEncodeSDKType
* @brief 编码库类型
* @attention 无
*/
typedef enum tagEncodeSDK
{
    XP_ENCODE_DSP = 0,          /**< DSP编码 */
    XP_ENCODE_SW = 1,           /**< Intel SDK软编码 */
    XP_ENCODE_HW = 2,           /**< Intel SDK硬编码 */
    XP_ENCODE_FRAME = 3,        /**< 转封装 */
    XP_ENCODE_HW_TOTAL = 4,     /** 编解码全部使用GPU,仅适用H264流 */
    XP_ENCODE_INVALID           /**< 无效编码参数 */
}XP_ENCODE_SDK_E;

/**
* @enum tagEncodeMode
* @brief 编码模式
* @attention 无
*/
typedef enum tagEncodeMode
{
    XP_ENC_MODE_CBR = 0,           /**< CBR */
    XP_ENC_MODE_CVBR = 1,          /**< CVBR */
    XP_ENC_MODE_VBR = 2            /**< VBR */
}XP_ENCODE_MODE_E;

/**
* @enum tagAudioFlag
* @brief 音频数据类型
* @attention 无
*/
typedef enum tagAudioFlag
{
    XP_AUDIO_LOCAL_GATHERED = 0,    /**< 本地采集的数据 */
    XP_AUDIO_DEVICE_SEND = 1        /**< 设备发送过来的语音数据 */
} XP_AUDIO_FLAG_E;

/**
* @struct tagRunInfo
* @brief 上报消息的结构体定义，主要在回调函数#XP_RUN_INFO_CALLBACK_PF中使用。
* @attention 无
*/
typedef struct tagRunInfo
{
    IMOS_HANDLE hWnd;                           /**< 播放窗格句柄 */
    ULONG_32 ulErrCode;                            /**< 上报的错误码 */
}XP_RUN_INFO_S;

/**
* @struct tagRunInfoEx
* @brief 上报消息的增强结构体定义，主要在回调函数#XP_RUN_INFO_CALLBACK_EX_PF中使用。
*        和tagRunInfo结构体区别在于使用通道资源编码替换播放窗口句柄。
* @attention 无
*/
typedef struct tagRunInfoEx
{
    CHAR szPortCode[IMOS_RES_CODE_LEN];         /**< 通道资源编码 */
    ULONG_32 ulErrCode;                            /**< 上报的错误码 */
}XP_RUN_INFO_EX_S;

/**
* @struct tagRunInfoEx
* @brief 上报消息的增强结构体定义，主要在回调函数#XP_RUN_INFO_CALLBACK_EX_PF中使用。
*        和tagRunInfo结构体区别在于使用通道资源编码替换播放窗口句柄。
* @attention 无
*/
typedef struct tagRunInfoEx2
{
    CHAR szPortCode[IMOS_RES_CODE_LEN];         /**< 通道资源编码 */
    ULONG_32 ulErrCode;                            /**< 上报的错误码 */
    CHAR szDescribe[IMOS_URL_LEN];            /*描述信息*/
}XP_RUN_INFO_EX2_S;

/**
* @struct tagStartMonitorRunInfo
* @brief 上报被动实况启动消息的结构体定义。
* @attention 无
*/
typedef struct tagStartMonitorRunInfo
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< 通道资源编码 */
    CHAR szCameraID[IMOS_CODE_LEN];             /**< 摄像机编码 */
    ULONG_32 ulErrCode;                            /**< 上报的错误码 */
    CHAR szReserved[64];                        /**< 保留参数 */
}XP_START_MONITOR_RUN_INFO_S;

/**
* @struct tagDownRunInfo
* @brief 媒体流下载过程中上报消息的结构体定义
* @attention 无
*/
typedef struct tagDownRunInfo
{
    CHAR szDownID[IMOS_RES_CODE_LEN];           /**< 媒体流下载ID */
    ULONG_32 ulErrCode;                            /**< 上报的错误码 */
}XP_DOWN_RUN_INFO_S;

/**
* @struct tagVoiceRunInfo
* @brief 语音业务媒体流处理过程中上报消息的结构体定义
* @attention 无
*/
typedef struct tagVoiceRunInfo
{
    CHAR szVoiceID[IMOS_RES_CODE_LEN];           /**< 如果为依赖于协议的语音业务，则该参数为远端资源编码；否则为SDK接口函数的语音通道ID参数 */
    ULONG_32 ulErrCode;                             /**< 上报的错误码 */
}XP_VOICE_RUN_INFO_S;

/**
* @struct tagRecvPktNum
* @brief 上报周期内接收包数消息的结构体定义。
* @attention 无
*/
typedef struct tagRecvPktNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< 通道资源编码 */
    ULONG_32 ulRecvPktNum;                         /**< 接收到的包数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒）*/
}XP_RECV_PACKET_NUM_S;

/**
* @struct tagRecvByteNum
* @brief 上报周期内接收字节数消息的结构体定义。
* @attention 无
*/
typedef struct tagRecvByteNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< 通道资源编码 */
    ULONG_32 ulRecvByteNum;                        /**< 接收到的字节数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒）*/
}XP_RECV_BYTE_NUM_S;

/**
* @struct tagVideoFrameNum
* @brief 上报周期内解析视频帧数消息的结构体定义。
* @attention 无
*/
typedef struct tagVideoFrameNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< 通道资源编码 */
    ULONG_32 ulVideoFrameNum;                      /**< 解析的视频帧数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}XP_VIDEO_FRAME_NUM_S;

/**
* @struct tagAudioFrameNum
* @brief 上报周期内解析音频帧数消息的结构体定义。
* @attention 无
*/
typedef struct tagAudioFrameNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< 通道资源编码 */
    ULONG_32 ulAudioFrameNum;                      /**< 解析的音频帧数 */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}XP_AUDIO_FRAME_NUM_S;

/**
* @struct tagLostPktRatio
* @brief 上报周期内丢包率消息的结构体定义。
* @attention 无
*/
typedef struct tagLostPktRatio
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< 通道资源编码 */
    ULONG_32 ulLostPktRatio;                       /**< 丢包率信息（单位为0.01%） */
    ULONG_32 ulStatPeriod;                         /**< 统计的周期（毫秒） */
}XP_LOST_PAKCET_RATIO_S;

/**
* @struct tagSourceDataExInfo
* @brief 拼帧前媒体流扩展信息的结构体定义。
* @attention 无
*/
typedef struct tagSourceDataExInfo
{
    CHAR szDecoderTag[IMOS_CODE_LEN];             /**< 解码器标签*/
    CHAR szReserved[64];                          /**< 保留参数*/
}XP_SOURCE_DATA_EX_INFO_S;

/**
* @struct tagParseVideoData
* @brief 存放拼帧后视频数据的指针和长度等信息的结构体定义
* @attention 无
*/
typedef struct tagParseVideoData
{
    UCHAR *pucData;             /**< 视频数据指针 */
    ULONG_32 ulDataLen;            /**< 视频数据长度 */
    ULONG_32 ulVideoFrameType;     /**< 视频帧类型，从#XP_VIDEO_FRAME_TYPE_E中取值 */
    ULONG_32 ulVideoCodeFormat;    /**< 视频编码格式，从#XP_VIDEO_ENCODE_TYPE_E中取值 */
    ULONG_32 ulHeight;             /**< 视频图像高度 */
    ULONG_32 ulWidth;              /**< 视频图像宽度 */
    DLONG dlTimeStamp;          /**< 时间戳（毫秒）*/
    ULONG_32 ulReserved1;          /**< 保留参数 */
    ULONG_32 ulReserved2;          /**< 保留参数 */
}XP_PARSE_VIDEO_DATA_S;

/**
* @struct tagParseAudioData
* @brief 存放拼帧后音频数据的指针和长度等信息的结构体定义
* @attention 无
*/
typedef struct tagParseAudioData
{
    UCHAR *pucData;             /**< 音频数据指针 */
    ULONG_32 ulDataLen;            /**< 音频数据长度 */
    ULONG_32 ulAudioCodeFormat;    /**< 音频编码格式，从#XP_AUDIO_ENCODE_TYPE_E中取值 */
    ULONG_32 ulWaveFormat;         /**< 音频数据解码后音频格式，对应#XP_WAVE_FORMAT_INFO_E枚举中的值 */
    DLONG dlTimeStamp;          /**< 时间戳（毫秒）*/
    ULONG_32 ulReserved1;          /**< 保留参数 */
    ULONG_32 ulReserved2;          /**< 保留参数 */
}XP_PARSE_AUDIO_DATA_S;

/**
* @struct tagPictureData
* @brief 存放解码后图像数据的指针和长度等信息的结构体定义
* @attention 无
*/
typedef struct tagPictureData
{
    UCHAR *pucData[4];                          /**< pucData[0]:Y 平面指针,pucData[1]:U 平面指针,pucData[2]:V 平面指针 */
    ULONG_32 ulLineSize[4];                        /**< ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距 */
    ULONG_32 ulPicHeight;                          /**< 图片高度 */
    ULONG_32 ulPicWidth;                           /**< 图片宽度 */
    ULONG_32 ulRenderTimeType;                     /**< 用于渲染的时间数据类型，对应tagRenderTimeType枚举中的值 */
    DLONG dlRenderTime;                         /**< 用于渲染的时间数据 */
}XP_PICTURE_DATA_S;

/**
* @struct tagPictureDataEx
* @brief 图像数据扩展参数结构体定义
* @attention 无
*/
typedef struct tagPictureDataEx
{
    /* 图像数据对应的UTC时间 */
    ULONG_32 ulUTCTime;

    /* 图像数据对应的UTC时间（通过UTC时间和时间戳计算得到） */
    ULONG_32 ulUTCTime2;

    /* 相对时间戳信息（单位为毫秒） */
    DLONG dlRelativeTimeStamp;

    /* 前一个I帧位置 */
    ULONG_32 ulPFilePos;

    /* 当前帧I帧位置 */
    ULONG_32 ulCFilePos;

    /* 下一个I帧位置 */
    ULONG_32 ulNFilePos;

    /* 保留数据 */
    CHAR szReserver[36];
}XP_PICTURE_DATA_EX_S;

/**
* @struct tagWaveData
* @brief 存放解码后音频数据的指针和长度等信息的结构体定义
* @attention 无
*/
typedef struct tagWaveData
{
    CHAR *pcData;                               /**< 音频数据指针 */
    ULONG_32 ulDataLen;                            /**< 音频数据长度 */
    ULONG_32 ulWaveFormat;                         /**< 解码后音频格式，对应tagWaveFormatInfo枚举中的值 */
}XP_WAVE_DATA_S;

/**
* @struct tagWaveInFileInfo
* @brief 设置音频文件作为输入源时，需要设置的额外参数信息。
* @attention 无
*/
typedef struct tagWaveInFileInfo
{
    CHAR szWaveFileName[IMOS_FILE_PATH_LEN];    /**< 音频文件名称（包括路径信息） */
    BOOL_T bCyclePlay;                          /**< 是否循环播放音频文件 */
}XP_WAVEIN_FILE_INFO_S;

/**
* @struct tagRect
* @brief 矩形信息。
* @attention 无
*/
typedef struct tagRect
{
    LONG_32 lLeft;                               /*x轴左点值百分比[0 ~ 100]*/
    LONG_32 lTop;                                /*y轴顶点值百分比[0 ~ 100]*/
    LONG_32 lRight;                              /*x轴右点值百分比[0 ~ 100]*/
    LONG_32 lBottom;                             /*y轴底点值百分比[0 ~ 100]*/
}XP_RECT_S;

/**
* @struct tagPoint
* @brief 坐标点信息。
* @attention 无
*/
typedef struct tagPoint
{
    LONG_32 lX;                               /*x轴值百分比[0 ~ 100]*/
    LONG_32 lY;                               /*y轴值百分比[0 ~ 100]*/
}XP_POINT_S;

/**
* @struct tagPointEx
* @brief 坐标点信息。
* @attention 无
*/
typedef struct tagPointEx
{
    LONG_32 lX;                               /*x轴值百分比[0 ~ 9999]*/
    LONG_32 lY;                               /*y轴值百分比[0 ~ 9999]*/
}XP_POINTEX_S;
/**
 * @enum tagCombineZoomRect
 * @brief 拼接图片放大区域信息
 * @attention
 */
typedef struct tagCombineZoomRect
{
    LONG_32  lX;                              /* 拼接图片中需要放大中心点X指标,精确到0.01%,[0 -- 10000] */
    LONG_32  lY;                              /* 拼接图片中需要放大中心点Y指标,精确到0.01%,[0 -- 10000] */
    ULONG_32 ulZoomHeight;                    /* 放大区域的高度,单位为像素 */
    ULONG_32 ulZoomWidth;                     /* 放大区域的宽度,单位为像素 */
}XP_COMBINE_ZOOM_RECT_S;


/**
 * @enum tagEncodeParam
 * @brief 编码参数
 * @attention
 */
typedef struct tagEncodeParam
{
    ULONG_32 ulVideoEncType;     /* 视频编码格式, #XP_VIDEO_ENCODE_TYPE_E,现仅支持#XP_VIDEO_ENCODE_H264 */
    ULONG_32 ulAudioEncType;     /* 音频编码格式,#XP_AUDIO_ENCODE_TYPE_E */
    ULONG_32 ulEncMode;          /* 编码模式,#XP_ENCODE_MODE_E */
    ULONG_32 ulPktType;          /* 打包类型,#XP_ENCODE_PACKET_TYPE_E*/
    ULONG_32 ulRltRatio;         /* 分辨率大小，见#XP_RESOLUTION_TYPE_E, #XP_RESOLUTION_AUTO 为原始分辨率*/
    ULONG_32 ulQpValue;          /* VBR时,QP值有效,取值[1,51]，默认填写则中填写为20*/
    ULONG_32 ulBitRate;          /* CBR时，码率有效，单位kbps，如为0时，自动根据分辨率填充 */
    ULONG_32 ulFrameRate;        /* 帧率 */
    ULONG_32 ulGopLen;           /* I帧间隔 */
    ULONG_32 ulEncSDK;              /* 解码库，默认使用DSP的解码库, #XP_ENCODE_SDK_E */
}XP_ENCODE_PARAM_S;

/**
* @enum tagVideoAdjust
* @brief 影像调节参数
* @attention
*/
typedef struct tagVideoAdjust
{
    LONG_32 lCont;             /**< 对比度 */
    LONG_32 lLum;              /**< 亮度 */
    LONG_32 lHue;              /**< 色调 */
    LONG_32 lSat;              /**< 饱和度 */
    LONG_32 lGamma;            /**< 伽玛 */
}XP_VIDEO_ADJUST_S;

/**
* @struct tagFileJointInfo
* @brief 文件拼接信息
* @attention
*/
typedef struct tagFileJointInfo
{
    /* 拼接生成的文件的播放总时间 */
    ULONG_32 ulJointFileTotalTime;

    /* 预留字段 */
    CHAR szReserve[60];
}XP_FILE_JOINT_INFO_S;

/**
* @struct tagMediaSectionTime
* @brief 媒体片段的起始时间
* @attention
*/
typedef struct tagMediaSectionTime
{
    CHAR szStartTime[IMOS_TIME_LEN];
    CHAR szEndTime[IMOS_TIME_LEN];
}XP_MEDIA_SECTION_TIME_S;

/**
* @struct tagPortResCodeInfo
* @brief 通道资源编码结构体
* @attention
*/
typedef struct tagPortResCodeInfo
{
    /** 通道资源编码 */
    CHAR szPortResCode[IMOS_RES_CODE_LEN];

    /* 预留字段 */
    CHAR szReserve[128];
}PORD_RES_CODE_INFO_S;

/**
* @enum tagOsdOverInfo
* @brief OSD信息的结构体
* @attention
*/
typedef struct tagOsdOverInfo
{
    UCHAR *pucBuf;              /**< 数据指针 */
    ULONG_32 ulBufLen;             /**< 数据长度 */
    ULONG_32 ulColor;              /**< 颜色 */
    ULONG_32 ulPosX;               /**< X轴百分比[0 ~ 100] */
    ULONG_32 ulPosY;               /**< Y轴百分比[0 ~ 100] */
    ULONG_32 ulSize;               /**< 字体大小 */
    /* Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */
    ULONG_32 ulOsdType;            /**< 具体定义见#XP_OSD_TYPE_INFO_E  */
    ULONG_32 ulOsdBkType;             /**< 具体定义见#XP_OSD_BK_TYPE_E  */
    ULONG_32 ulWidth;
    ULONG_32 ulHeigh;
    UCHAR ucOsdJudge[16];       /**< 特殊用途，一般不用传入 */
    UCHAR ucReserver[232];     /**< 保留字段，后续扩展的时候从该内存块中分配（当前SDK用户传入的该块数据必须为全0，便于后续接口功能扩展和SDK升级） */
}XP_OSD_OVER_INFO_S;

/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */
/**
* @enum tagOSDTypeInfo
* @brief OSD类型定义
* @attention 无
*/
typedef enum tagOSDTypeInfo
{
    NORMAL_OSD = 0,          /**< 普通OSD */
    SYSTIME_OSD = 1,         /**< 系统时间OSD */
    VODTIME_OSD = 2          /**< 点播回放时间OSD */
}XP_OSD_TYPE_INFO_E;
/* END: Add by chenliang w0897, 2014/12/1, MPPD19576, 海外版本需求特性合主线D109 */

/**
* @enum tagOSDBkType
* @brief OSD背景类型定义
* @attention 无
*/
typedef enum tagOSDBkType
{
    NORMAL_BK_OSD = 0,            /**< OSD普通背景 */
    WATERMARK_BK_OSD = 1,         /**< OSD水印背景 */
}XP_OSD_BK_TYPE_E;

typedef struct tagTransParam
{
    ULONG_32 ulEncodeType;//XP_VIDEO_ENCODE_TYPE_E
    ULONG_32 ulWidth;
    ULONG_32 ulHeight;
}XP_TRANS_PARAM_S;

/**
 * @enum tagXPThruLineDirection
 * @brief "绊线行为"方向
 * @attention
 */
typedef enum tagXPThruLineDirection
{
    XP_THRU_LINE_DIRECTION_CLOCKWISE          = 0,    /**< 顺时针 */
    XP_THRU_LINE_DIRECTION_ANTICLOCKWISE      = 1,    /**< 逆时针 */
    XP_THRU_LINE_DIRECTION_ALL                = 2,    /**< 双向 */

    XP_THRU_LINE_DIRECTION_MAX,
    XP_THRU_LINE_DIRECTION_INVALID            = 0XFFFFFFFF
} XP_THRU_LINE_DIRECTION_E;

/**
 * @enum tagXPAreaDirection
 * @brief "区域行为"方向
 * @attention
 */
typedef enum tagXPAreaDirection
{
    XP_AREA_DIRECTION_IN       = 0,    /**< In */
    XP_AREA_DIRECTION_OUT      = 1,    /**< Out */
    XP_AREA_DIRECTION_ALL      = 2,    /**< 双向 */

    XP_AREA_DIRECTION_MAX,
    XP_AREA_DIRECTION_INVALID  = 0XFFFFFFFF
} XP_AREA_DIRECTION_E;

/**
 * @enum tagXPHWStatus
 * @brief 硬件参数
 * @attention
 */
typedef enum tagXPHWStatus
{
    XP_HW_NORMAL = 0,                    /**< 正常 */
    XP_HW_DDRAW_NOSUPPORT   = 1,         /**< 普通品质硬件加速未开启 */
    XP_HW_D3D_NOSUPPORT     = 2,         /**< 高品质硬件加速未开启 */
    XP_HW_RENDER_NOSUPPORT  = 3          /**< 硬件加速均未开启 */
}XP_HW_STATUS_E;

/**
 * @struct tagXpPTZAbsPosition
 * @brief 云台绝对位置
 * @attention 无
 */
typedef struct tagXpPTZAbsPosition
{
    FLOAT fLatitude;              /**< 云台纬度, 范围: -18~90度, 精度至小数点后两位 */
    FLOAT fLongitude;             /**< 云台经度, 范围: 0~360度, 精度至小数点后两位 */
    FLOAT fMoveSpeed;             /**< 转动角速度，取值范围0-9级(与现有界面上统一)，0为使用默认速度 */
}XP_PTZ_ABSPOSITION_S;

/**
 * @struct tagXpPTZAbsZoom
 * @brief 云台绝对变倍信息
 * @attention 无
 */
typedef struct tagXpPTZAbsZoom
{
    FLOAT fPtzZoomNum;        /**< 云台zoom 倍数，精确至小数点后两位，取值范围1-36 */
    FLOAT fPtzZoomSpeed;      /**< 云台zoom 速度，99级 1-99 */
}XP_PTZ_ABSZOOM_S;

/**
 * @struct tagXPBallLoginInfo
 * @brief 球机登录相关信息
 * @attention
 */
typedef struct tagXPBallLoginInfo
{
    CHAR   szBallCameraIP[IMOS_IPADDR_LEN];  /**< 球机IP地址 */
    USHORT usBallCameraPort;                 /**< 球机端口号 */
    CHAR   szUserName[IMOS_NAME_LEN];        /**< 球机登录用户名 */
    CHAR   szPassword[IMOS_PASSWD_LEN];      /**< 球机登录密码 */
}XP_BALL_LOGIN_INFO_S;

/**
 * @struct tagXPBLMatchPointParam
 * @brief  枪球联动映射坐标结构体
 * @attention
 */
typedef struct tagXPBLMatchPointParam
{
    USHORT usMasterPointX;     /**< 枪机X坐标 */
    USHORT usMasterPointY;     /**< 枪机Y坐标 */
    USHORT usSlavePointX;      /**< 球机经度坐标 */
    USHORT usSlavePointY;      /**< 球机纬度坐标 */
}XP_BL_MATCH_POINT_PARAM_S;

/**
 * @struct tagXPBallMarkPoint
 * @brief  球机标定信息
 * @attention
 */
typedef struct tagXPBallMarkPoint
{
    USHORT  usCameraImageWdith;   /**< 枪机画面宽度 */
    USHORT  usCameraImageHeight;  /**< 枪机画面高度 */
    USHORT  usBallImageWidth;     /**< 球机画面宽度 */
    USHORT  usBallImageHeight;    /**< 球机画面高度 */
    USHORT  usBlMatchPointNum;    /**< 球机标定点个数 */
    XP_BL_MATCH_POINT_PARAM_S  *pstBLMatchPointParam;  /**< 球机标定点 */
}XP_BALL_MARK_POINT_S;

/**
 * @struct tagXPBLOffsetMatchPointParam
 * @brief  球机机芯偏移映射坐标结构体
 * @attention
 */
typedef struct tagXPBLOffsetMatchPointParam
{
    USHORT      usZoomNum;  /**< 变倍系数 */
    USHORT      usPointX;   /**< 球机坐标X */
    USHORT      usPointY;   /**< 球机坐标Y */
}XP_BL_OFFSET_MATCH_POINT_PARAM_S;

/**
* @struct tagXPBLOffsetMatchParam
* @brief  球机机芯偏离参数
* @attention
*/
/*球机机芯偏移映射坐标参数结构体*/
typedef struct tagXPBLOffsetMatchParam
{
    USHORT         usMaxZoonNum;  /**< 球机最大变倍系数 */
    USHORT         usZoomCnt;     /**< 球机机芯变倍参数个数 */
    XP_BL_OFFSET_MATCH_POINT_PARAM_S* pstBlOffsetMatchPointParam;  /**< 球机机芯变倍参数 */
}XP_BL_OFFSET_MATCHPARAM_S;

/**
 * @struct tagXPCameraZoomArea
 * @brief 拉框区域信息
 * @attention 无
 */
typedef struct tagXPCameraZoomArea
{
    USHORT usMidPointX;         /**< 拉框中心点横坐标 */
    USHORT usMidPointY;         /**< 拉框中心点纵坐标 */
    USHORT usLengthX;           /**< 拉框长度 */
    USHORT usLengthY;           /**< 拉框宽度 */
    USHORT usWidth;             /**< 播放窗格长度 */
    USHORT usHeight;            /**< 播放窗格宽度 */
}XP_CAMERA_ZOOMAREA_S;

/**
* @enum tagTsFileJointMode
* @brief ts拼接模式枚举定义
* @attention 无
*/
typedef enum tagTsFileJointMode
{
    XP_TSJOINT_MODE_NOMAL = 0,           /**< 普通模式 直接追加模式*/
    XP_TSJOINT_MODE_PAT = 1              /**<   pat模式 需要偏移掉第一个I帧前面的P帧*/
}XP_TSJOINT_MODE_E;

/**
* @enum tagAudioChannel
* @brief 音频左右声道设置
* @attention 无
*/
typedef enum tagAudioChannel
{
    XP_AUDIO_CHANNEL_LEFT = 0,       /**< 左声道 */
    XP_AUDIO_CHANNEL_RIGHT = 1,      /**< 右声道 */
}XP_AUDIO_CHANNEL_E;

/**
* @enum tagXPMediaType
* @brief 媒体数据类型
* @attention 无
*/
typedef enum tagXPMediaType
{
    XP_MEDIA_NONE = 0,       /**< 即没音频，也没视频  */
    XP_MEDIA_AUDIO_ONLY = 1, /**< 只含有音频数据 */
    XP_MEDIA_VIDEO_ONLY = 2, /**< 只含有视频数据 */
    XP_MEDIA_BOTH = 3        /**< 含有音视频数据 */
}XP_MEDIATYPE_E;

/**
* @enum tagBarrelAdjustLevel
* @brief 桶型矫正等级
* @attention 无
*/
typedef enum tagBarrelAdjustLevel
{
    XP_BARREL_ADJUST_LEVEL_1 = 1,   /** 桶型矫正等级1 */
    XP_BARREL_ADJUST_LEVEL_2 = 2,   /** 桶型矫正等级2 */
    XP_BARREL_ADJUST_LEVEL_3 = 3,   /** 桶型矫正等级3 */
    XP_BARREL_ADJUST_LEVEL_4 = 4,   /** 桶型矫正等级4 */
    XP_BARREL_ADJUST_LEVEL_5 = 5,   /** 桶型矫正等级5 */
    XP_BARREL_ADJUST_LEVEL_6 = 6,   /** 桶型矫正等级6 */
    XP_BARREL_ADJUST_LEVEL_7 = 7,   /** 桶型矫正等级7 */
    XP_BARREL_ADJUST_LEVEL_8 = 8,   /** 桶型矫正等级8 */
    XP_BARREL_ADJUST_LEVEL_9 = 9,   /** 桶型矫正等级9 */
    XP_BARREL_ADJUST_LEVEL_10 = 10  /** 桶型矫正等级10 */
} XP_BARREL_ADJUST_LEVEL_E;

/* Begin add by sunbiao/sW1071 2014.10.28 for MPPD18406 新增dsp去抖动 */
/**
* @enum tagXpDeshakeParm
* @brief dsp去抖动参数
* @attention 无
*/
typedef struct tagXpDeshakeParm
{
    ULONG_32 ulMaxXoffset;             //范围0-100 边缘截取宽度 默认50
    ULONG_32 ulMaxYoffset;             //范围0-100 边缘截取长度 默认50
    ULONG_32 ulUpdateFrameNum;         //范围25-100，默认25（刷新帧间隔）
}XP_DESHAKE_PARM_S;
/* Begin add by sunbiao/sW1071 2014.10.28 for MPPD18406 新增dsp去抖动 */

/**
* @enum tagAppliProtlID
* @brief 应用层协议类型
* @attention 无
*/
typedef enum tagAppliProtl
{
    APPLI_PROTL_NONE = 0,            /* 没有定义应用层协议 */
    APPLI_PROTL_RTP,                 /* 指定协议为rtp */
}XP_APPLI_PROTL_E;

/**
* @struct tagMediaAbility
* @brief 媒体能力集结构体。
* @attention 无
*/
typedef struct tagMediaAbility
{
    CHAR szDecoderTag[IMOS_CODE_LEN];             /**< 解码标签 */
    CHAR szReceiveIP[IMOS_IPADDR_LEN];              /**< 收流IP地址 */
    USHORT usReceivePort;                           /**< 收流端口号(主机序) */
    CHAR szSendIP[IMOS_IPADDR_LEN];              /**< 发流IP地址 */
    USHORT usSendPort;                           /**< 发流端口号(主机序) */

    XP_PROTOCOL_E enProtocol;                    /* 网络协议 */

    XP_APPLI_PROTL_E enAppliProtl;                /**  应用层协议 */

    XP_ENCODE_PACKET_TYPE_E enPacketType;         /**  码流封装类型 */

}XP_MEDIA_ABILITY_S;

/**
/* 消息或者异常消息回调函数的指针类型，在老接口函数#XP_SetRunMsgCB中使用。\n
* @param [IN] enRunInfoType 消息或者异常消息类型。
* @param [IN] pParam        存放消息或者异常消息数据的缓冲区指针（所存放的数据与消息或者异常消息类型有关）。
* @return 无。
* @note
* -     1、客户在实现该回调函数时需要确保函数尽快返回，否则会阻塞播放器XP内部调用该回调函数的线程。
* -     2、参数pParam的实际类型根据具体的消息或者异常消息类型而定，客户需要根据消息或者异常消息类型做相应的类型转换；在某些情况下，该参数有可能为NULL。
* -     具体的类型转换关系如下：
* -         当enRunInfoType值为#XP_RUN_INFO_SERIES_SNATCH、#XP_RUN_INFO_RECORD_VIDEO、#XP_RUN_INFO_MEDIA_PROCESS、
* -     #XP_RUN_INFO_RTSP_PROTOCOL或#XP_RUN_INFO_PASSIVE_MONITOR时，须将pParam指针转换为#XP_RUN_INFO_S结构体指针类型；
* -         当enRunInfoType值为#XP_RUN_INFO_DOWN_MEDIA_PROCESS或#XP_RUN_INFO_DOWN_RTSP_PROTOCOL时，
* -     须将pParam指针转换为#XP_DOWN_RUN_INFO_S结构体指针类型；
* -         当enRunInfoType值为#XP_RUN_INFO_VOICE_MEDIA_PROCESS时，需将pParam指针转换为#XP_VOICE_RUN_INFO_S结构体指针类型；
* -         当enRunInfoType值为#XP_RUN_INFO_SIP_LIVE_TIMEOUT时，pParam指针为NULL。
*/
typedef VOID (STDCALL* XP_RUN_INFO_CALLBACK_PF)(IN XP_RUN_INFO_TYPE_E enRunInfoType,
                                                IN VOID *pParam);

/**
* 解码后媒体流数据回调函数的指针类型，在老接口函数#XP_SetOutputMediaDataCB中使用。\n
* @param [IN] hXpWnd          播放窗口句柄。
* @param [IN] enMediaDataType 解码后媒体流数据类型。
* @param [IN] pDataParam      存放解码后媒体流数据信息缓冲区指针（所存放的媒体流数据与媒体流数据类型有关）。
* @return 无。
* @note
* -     1、客户应及时处理输出的媒体数据，确保函数尽快返回，否则会影响播放器XP内的媒体流处理。
* -     2、参数pDataParam的实际类型与参数enMediaDataType有关，客户需要根据运行信息类型做相应的类型转换。
* -     具体的类型转换关系如下：
* -         当enMediaDataType值为#XP_VIDEO_DATA_DECODE时，须将pDataParam指针转换为#XP_PICTURE_DATA_S结构体指针类型；
* -         当enMediaDataType值为#XP_AUDIO_DATA_DECODE时，须将pDataParam指针转换为#XP_WAVE_DATA_S结构体指针类型。
*/
typedef VOID (STDCALL* XP_PROCESS_MEDIA_DATA_CALLBACK_PF)(IN IMOS_HANDLE hWnd,
                                                          IN XP_OUTPUT_MEDIA_DATA_TYPE_E enMediaDataType,
                                                          IN const VOID *pDataParam);

/**
* 转码回调函数的指针类型。\n
* @param [IN] ulPort           播放通道号
* @param [IN] pucBuffer        转码后打包的数据指针
* @param [IN] ulBufSize        缓冲区大小
* @param [IN] lUserParam       用户设置参数，即用户在调用#IMOS_XP_SetTranscodeCB函数时指定的用户参数
* @param [IN] lReserved        预留参数
* @return 无。
* @note  用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* XP_PLAYER_TRANSCODE_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                        IN const UCHAR *pucBuffer,
                                                        IN ULONG_32 ulBufSize,
                                                        IN LONG_REAL lUserParam,
                                                        IN LONG_REAL lReserved);

#endif /* _IMOS_MEDIA_PLAY_SDK_DATA_TYPE_H_ */
