/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_errcode.h

  Project Code: IMOS PLAT
   Module Name: BP
  Date Created: 2008-08-28
        Author: wuxianmin/04253
   Description: 基础平台公共错误码定义头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_ERRCODE_H_
#define _IMOS_ERRCODE_H_

#ifdef  __cplusplus
extern "C"{
#endif

/* 通用错误码 */
#define ERR_COMMON_SUCCEED                      0x000000              /**< 执行成功 */
#define ERR_COMMON_FAIL                         0x000001              /**< 执行失败 */
#define ERR_COMMON_INVALID_PARAM                0x000002              /**< 输入参数非法 */
#define ERR_COMMON_NO_MEMORY                    0x000003              /**< 系统内存不足 */
#define ERR_COMMON_SYS_FAIL                     0x000004              /**< 系统通用错误 */
#define ERR_COMMON_IE_NOT_EXIST                 0x000005              /**< IE不存在 */
/* Begin Add By hexiaojun/hW0959 for 用户登录时间限制 */
#define ERR_COMMON_CB_STATUS_CHANGE                    0x000006              /**< 控制块中登录时间超出设定范围状态变化 */
#define ERR_COMMON_CB_BEYOND_EFECTIVE_TIME             0x000007              /**< 控制块中登录有效时间超出设定范围状态变化 */
/* End Add By hexiaojun/hW0959 for 用户登录时间限制 */

/* 文件、目录操作 */
#define ERR_COMMON_DIR_FAIL_OPEN                0x000010              /**< 打开目录失败 */
#define ERR_COMMON_DIR_FAIL_READ                0x000011              /**< 读取目录文件失败 */
#define ERR_COMMON_DIR_FAIL_REMOVE              0x000012              /**< 删除目录失败 */
#define ERR_COMMON_DIR_FAIL_MKDIR               0x000013              /**< 创建目录失败 */
#define ERR_COMMON_FILE_CANT_OPEN               0x000015              /**< 打开（创建）文件失败 */
#define ERR_COMMON_FILE_FAIL_FSEEK              0x000016              /**< 设置文件读写位置失败 */
#define ERR_COMMON_FILE_FAIL_FTELL              0x000017              /**< 获取文件读写位置失败 */
#define ERR_COMMON_FILE_FAIL_FREAD              0x000018              /**< 读取文件失败 */
#define ERR_COMMON_FILE_FAIL_FWRITE             0x000019              /**< 写入文件失败 */
#define ERR_COMMON_FAIL_STAT                    0x00001A              /**< 读取文件（目录）状态失败 */
#define ERR_COMMON_FILE_FAIL_CHMOD              0x00001B              /**< 修改文件属性失败 */
#define ERR_COMMON_FILE_FAIL_DELETE             0x00001C              /**< 删除文件失败 */

/* 数据库操作相关 */
#define ERR_COMMON_DB_EXCEPTION                 0x000020              /**< 数据库操作异常 */
#define ERR_COMMON_DB_RECORD_NOT_EXIST          0x000021              /**< 数据库记录不存在 */
#define ERR_COMMON_DB_READ_DATA_EXCEPTION       0x000022              /**< 数据库读取记录异常 */
#define ERR_COMMON_DB_RECORD_EXIST              0x000023              /**< 数据库记录已存在 */
/* added by c02845,2016-06-17,交通流信息接入 */
#define ERR_COMMON_DB_READ_DATA_OUTLIMIT        0x000024              /**< 数据库读取记录超出限制 */

/* 系统函数调用相关 */
#define ERR_COMMON_FAIL_CALL_SYSTEM             0x000030              /**< 执行shell脚本失败 */
#define ERR_COMMON_FAIL_CALL_POPEN              0x000031              /**< 打开管道失败 */

#define ERR_COMMON_PROCSRV_BUSY                 0x000032              /**< 业务忙 */

/* 以下为SIP通用错误码（错误码范围100~700） */
#define ERR_COMMON_SIP_RSP_STATE_RINGING        180   /**< 被叫本地振铃 */
#define ERR_COMMON_SIP_RSP_STATE_CALLFORWARD    181   /**< 呼叫正在转接中 */
#define ERR_COMMON_SIP_RSP_STATE_QUEUED         182   /**< 呼叫正在队列等待中 */
#define ERR_COMMON_SIP_RSP_STATE_SSNPRORESS     183   /**< 被叫远端振铃中 */
#define ERR_COMMON_SIP_RSP_STATE_OK             200   /**< 被叫摘机 */
#define ERR_COMMON_SIP_RSP_STATE_MULTCHOICE     300   /**< 被叫多路选择 */
#define ERR_COMMON_SIP_RSP_STATE_MOVPER         301   /**< 永久转移 */
#define ERR_COMMON_SIP_RSP_STATE_MOVTEM         302   /**< 暂时转移 */
#define ERR_COMMON_SIP_RSP_STATE_USEPROXY       305   /**< 代理模式应用 */
#define ERR_COMMON_SIP_RSP_STATE_ALTERSER       380   /**< 可选服务 */
#define ERR_COMMON_SIP_RSP_STATE_BADREQ         400   /**< 请求头域错误 */
#define ERR_COMMON_SIP_RSP_STATE_UNAUTHORIZE    401   /**< 鉴权未通过 */
#define ERR_COMMON_SIP_RSP_STATE_PAYREQ         402   /**< 付费不足, 请求失败 */
#define ERR_COMMON_SIP_RSP_STATE_FORBIDDEN      403   /**< 服务被禁止 */
#define ERR_COMMON_SIP_RSP_STATE_NOTFOUND       404   /**< 目的端不存在 */
#define ERR_COMMON_SIP_RSP_STATE_METHNOTALLOW   405   /**< 不支持的方法 */
#define ERR_COMMON_SIP_RSP_STATE_NOTACPT        406   /**< 请求不被接受 */
#define ERR_COMMON_SIP_RSP_STATE_PROXYAUTHREQ   407   /**< 代理模式鉴权请求 */
#define ERR_COMMON_SIP_RSP_STATE_REQTIMEOUT     408   /**< 请求超时 */
#define ERR_COMMON_SIP_RSP_STATE_GONE           410   /**< 服务挂死 */
#define ERR_COMMON_SIP_RSP_STATE_REQLARGE       413   /**< 请求消息体太大 */
#define ERR_COMMON_SIP_RSP_STATE_URILONG        414   /**< 请求URI太长 */
#define ERR_COMMON_SIP_RSP_STATE_UNSUPPTYPE     415   /**< 不支持的媒体类型 */
#define ERR_COMMON_SIP_RSP_STATE_UNSUPPURI      416   /**< 不支持的URI类 */
#define ERR_COMMON_SIP_RSP_STATE_BADEXTEND      420   /**< 非法的扩展字段 */
#define ERR_COMMON_SIP_RSP_STATE_EXTENDREQ      421   /**< 扩展的请求 */
#define ERR_COMMON_SIP_RSP_STATE_INTERBRIEFE    423   /**< 间隔太短 */
#define ERR_COMMON_SIP_RSP_STATE_NOTENFBNDWTH   453   /**< 带宽不足 */
#define ERR_COMMON_SIP_RSP_STATE_TEMPUNAVAIL    480   /**< 资源暂时不可用 */
#define ERR_COMMON_SIP_RSP_STATE_CALLNOTEXIST   481   /**< 呼叫或者事务不存在 */
#define ERR_COMMON_SIP_RSP_STATE_MANYHOP        483   /**< 中间跳数太多 */
#define ERR_COMMON_SIP_RSP_STATE_ADDRINCOMP     484   /**< 地址不全 */
#define ERR_COMMON_SIP_RSP_STATE_AMBIGUOUS      485   /**< 信息不明确 */
#define ERR_COMMON_SIP_RSP_STATE_BUSY           486   /**< 被叫正忙 */
#define ERR_COMMON_SIP_RSP_STATE_REQTERM        487   /**< 请求被终止 */
#define ERR_COMMON_SIP_RSP_STATE_NOACPTHERE     488   /**< 当前请求不被接受 */
#define ERR_COMMON_SIP_RSP_STATE_REQPEND        491   /**< 请求挂起中 */
#define ERR_COMMON_SIP_RSP_STATE_UNDECIPHER     493   /**< 难以确认的请求 */
#define ERR_COMMON_SIP_RSP_STATE_SERVINTERERR   500   /**< 服务端错误 */
#define ERR_COMMON_SIP_RSP_STATE_NOTIMPLEMENT   501   /**< 未被执行 */
#define ERR_COMMON_SIP_RSP_STATE_BADGATEWAY     502   /**< 网关错误 */
#define ERR_COMMON_SIP_RSP_STATE_SERVUNAVAIL    503   /**< 服务端不可用 */
#define ERR_COMMON_SIP_RSP_STATE_SERVTIMEOUT    504   /**< 服务端超时 */
#define ERR_COMMON_SIP_RSP_STATE_VERSNOTSUPP    505   /**< 不支持的版本 */
#define ERR_COMMON_SIP_RSP_STATE_MSGLARGE       513   /**< 消息太大 */
#define ERR_COMMON_SIP_RSP_STATE_BUSYALL        600   /**< 整体忙, 整体资源耗尽 */
#define ERR_COMMON_SIP_RSP_STATE_DECLINE        603   /**< 请求被谢绝 */
#define ERR_COMMON_SIP_RSP_STATE_NOTEXIST       604   /**< 搜索全体都不存在 */
#define ERR_COMMON_SIP_RSP_STATE_NOTACCEPT      606   /**< 不允许 */
/* Begin Added by w00523, 2012-08-23 for SIP-TCP project */
#define ERR_COMMON_SIP_RSP_STATE_HEADER_WAIT    608   /**< SIP报文头域不完整 */
#define ERR_COMMON_SIP_RSP_STATE_FRAGMENT       609   /**< 报文分片未满 */
#define ERR_COMMON_SIP_RSP_STATE_TCP_MSG_ERR    610   /**< TCP消息接收失败 */
#define ERR_COMMON_SIP_RSP_STATE_TCP_LINK_ERR   611   /**< TCP连接异常 */
#define ERR_COMMON_SIP_RSP_STATE_TCP_CCB_ERR    612   /**< TCP消息控制块异常 */
#define ERR_COMMON_SIP_RSP_STATE_MSG_LONG       613   /**< SIP消息太长 */
#define ERR_COMMON_SIP_RSP_STATE_NO_TCPCCB_FIND 614   /**< TCP连接控制块不存在 */
#define ERR_COMMON_SIP_RSP_STATE_TCP_CCB_MAX    615   /**< TCP连接控制块已满 */
/* End Added by w00523, 2012-08-23 for SIP-TCP project */
/* 以上为SIP通用错误码 */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* end of _IMOS_ERRCODE_H_ */
