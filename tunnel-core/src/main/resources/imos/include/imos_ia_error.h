
#ifndef _IMOS_IA_ERROR_H_
#define _IMOS_IA_ERROR_H_

/************************************************************************/
/* 33400 - 33599                                                        */
/************************************************************************/
#define ERR_IA_COMMON_BASE    33400

/**/
#ifndef ERR_COMMON_SUCCEED
#define ERR_COMMON_SUCCEED 0
#endif

#ifndef ERR_COMMON_FAIL
#define ERR_COMMON_FAIL 1
#endif

#define ERR_IA_COMMON_UNINITIAL            (ERR_IA_COMMON_BASE + 2)    /* IA服务器未初始化 */
#define ERR_IA_COMMON_PARAMETER_INVALID    (ERR_IA_COMMON_BASE + 3)    /* 输入参数非法 */
#define ERR_IA_COMMON_NO_MEMORY            (ERR_IA_COMMON_BASE + 4)    /* 内存不足 */
#define ERR_IA_COMMON_RES_ISNOT_EXIST      (ERR_IA_COMMON_BASE + 5)    /* 所需资源不存在 */
#define ERR_IA_COMMON_RES_HAVE_EXIST       (ERR_IA_COMMON_BASE + 6)    /* 需要创建的资源已经存在 */
#define ERR_IA_COMMON_CREATE_RES           (ERR_IA_COMMON_BASE + 7)    /* 创建资源失败 */
#define ERR_IA_COMMON_EXCEPTION            (ERR_IA_COMMON_BASE + 8)    /* 程序发生异常 */
#define ERR_IA_COMMON_VOD_COMPLIETE        (ERR_IA_COMMON_BASE + 9)    /* 回放完成 */
#define ERR_IA_COMMON_MERGEFILE_NO_FILE    (ERR_IA_COMMON_BASE + 11)   /* 不存在文件无法合并*/
#define ERR_IA_COMMON_DOWNLOAD_ERR         (ERR_IA_COMMON_BASE + 12)   /* 下载失败*/
#define ERR_IA_COMMON_RES_NOT_ENOUGH       (ERR_IA_COMMON_BASE + 13)   /* 输入的资源不足*/
#define ERR_IA_COMMON_9LIN_EXCEPTION       (ERR_IA_COMMON_BASE + 14)   /* 久凌异常*/
#define ERR_IA_COMMON_NOT_9LIN_SERVER	   (ERR_IA_COMMON_BASE + 15)   /* 不是久凌服务器*/

/* UserMgr错误码 */
#define ERR_IA_USER_ISNOT_EXIST            (ERR_IA_COMMON_BASE + 20)   /* 用户不存在 */
#define ERR_IA_USER_PASSWD                 (ERR_IA_COMMON_BASE + 21)   /* 用户密码错误 */
#define ERR_IA_USER_KEEPALIVE              (ERR_IA_COMMON_BASE + 22)   /* 用户保活超时 */

#define ERR_IA_URL_IS_EMPTY                (ERR_IA_COMMON_BASE + 23)   /* url 资源为空,可能未配置存储资源；摄像机离线*/
#define ERR_IA_USER_NOT_LOGIN              (ERR_IA_COMMON_BASE + 24)   /* 用户未登录*/

/* source模块错误码 */
#define ERR_IA_SOURCE_RECV                 (ERR_IA_COMMON_BASE + 50)
#define ERR_IA_SOURCE_SEND                 (ERR_IA_COMMON_BASE + 51)
#define ERR_IA_SOURCE_TIMEOUT              (ERR_IA_COMMON_BASE + 52)
#define ERR_IA_SOURCE_KEEPALIVE_FAILD      (ERR_IA_COMMON_BASE + 55)   /*source 保活失败*/
#define ERR_IA_SOURCE_GETRES_FAILD         (ERR_IA_COMMON_BASE + 56)   /*获取通道资源失败*/
#define ERR_IA_SOURCE_STARTVOD_FAILD       (ERR_IA_COMMON_BASE + 57)   /*启动回放失败*/

/*decoder filter 失败错误码范围*/
#define ERR_IA_DECODER_BASE                (ERR_IA_COMMON_BASE + 100)
#define ERR_IA_DECODER_RES_FAIL            (ERR_IA_DECODER_BASE + 101)

/*analytics filter 失败错误码范围*/
#define ERR_IA_ANALYTICS_BASE              (ERR_IA_COMMON_BASE + 200)

/* 业务类错误码 */
#define ERR_IA_LOGIN_FAILED                (ERR_IA_COMMON_BASE + 300)   /* 用户登录失败 */
#define ERR_IA_CREATE_MSG_CHANNEL          (ERR_IA_COMMON_BASE + 301)   /* 启动服务器与客户端消息通信通道失败 */

/* license模块错误码 */
#define ERR_IA_COMMON_NO_LICENSE           (ERR_IA_COMMON_BASE + 400)   /* license未授权 */
#define ERR_IA_COMMON_EXPIRE               (ERR_IA_COMMON_BASE + 401)   /* license超期 */
#define ERR_IA_COMMON_OUTNUMBER            (ERR_IA_COMMON_BASE + 402)   /* license超过授权数量 */
#define ERR_IA_COMMON_HANDLE_REPEAT        (ERR_IA_COMMON_BASE + 403)   /* 重复的智能业务句柄 */

/* merger 模块错误码*/
#define ERR_IA_COMMON_NO_ALARM             (ERR_IA_COMMON_BASE + 450)   /* 指定时间内无告警*/
#define ERR_IA_COMMON_DIFFTIME_ZERO        (ERR_IA_COMMON_BASE + 451)   /* 指定时间间隔为0*/
#define ERR_IA_COMMON_UPLOAD_LARGEFILE     (ERR_IA_COMMON_BASE + 452)   /* 合并大于1G的文件*/
#define ERR_IA_COMMON_UPLOAD_FAILD         (ERR_IA_COMMON_BASE + 453)   /* 上传到备份服务器失败*/
#endif