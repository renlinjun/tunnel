#ifndef __IA_CLIENT_LIB_H__
#define __IA_CLIENT_LIB_H__

#include "imos_ia_error.h"
#include "imos_ia_def.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* ia客户端协议全局初始化
* @param [IN] 无
* @return 初始化是否成功
*/
long STDCALL IAC_Init();

/**
* ia客户端协议全局释放
* @param [IN] 无
* @return
*/
void STDCALL IAC_Uninit();

/**
* ias用户登录接口
* @param [IN] pcIasIP       ias服务器地址
* @param [IN] usIasPort     ias服务器端口
* @param [IN] pcUserName    用户名
* @param [IN] pcPasswd      密码(MD5加密)
* @param [OUT] lUserHandle  用户登录句柄
* @return 返回错误码
*/
long STDCALL IAC_Login(IN char *pcIasIP,
                       IN unsigned short usIasPort,
                       IN char *pcUserName,
                       IN char *pcPasswd,
                       OUT long *plUserHandle);

/**
* iac用户登出接口
* @param [IN] lUserHandle  IAC_logout返回值
* @return 无
*/
void STDCALL IAC_Logout(IN long lUserHandle);

/**
* 进行用户保活
* @param [IN] lUserHandle  login返回值
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_Keeplive(IN long lUserHandle);

/**
* 设置ias对应的vm服务器信息
* @param [IN]   lUserHandle     用户登录句柄
* @param [IN]   pcVmServerIP    VM服务器登录IP地址
* @param [IN]   usVmServerPort  VM服务器登录端口号
* @param [IN]   pcVmUserName    VM登录用户名
* @param [IN]   pcVmUserPasswd  VM登录密码(MD5加密)
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_SetVmConfig(IN long lUserHandle,
                             IN char *pcVmServerIP,
                             IN unsigned short usVmServerPort,
                             IN char *pcVmUserName,
                             IN char *pcVmUserPasswd);

/**
* 获取ias对应的vm服务器信息
* @param [IN]    lUserHandle     用户登录句柄
* @param [OUT]   pcVmServerIP    VM服务器登录IP地址（内存长度为IA_IP_LEN）
* @param [OUT]   pusVmServerPort VM服务器登录端口号
* @param [OUT]   pcVmUserName    VM登录用户名（内存长度为IA_ITEM_NAME_LEN）
* @param [OUT]   pcVmUserPasswd  VM登录密码(MD5加密)（内存长度为IA_PASSWD_LEN）
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_GetVmConfig(IN long lUserHandle,
                             OUT char *pcVmServerIP,
                             OUT unsigned short *pusVmServerPort,
                             OUT char *pcVmUserName,
                             OUT char *pcVmUserPasswd);

/**
* 设置ias对应的TMS服务器信息
* @param [IN]    lUserHandle     用户登录句柄
* @param [IN]    pcTmsIp         Tms的IP地址
* @param [IN]    usTmsPort       Tms的端口号
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_SetTmsConfig(IN long lUserHandle,
                              IN char *pcTmsIp,
                              IN unsigned short usTmsPort);

/**
* 获取ias对应的TMS服务器信息
* @param [IN]    lUserHandle     用户登录句柄
* @param [OUT]   pcTmsIp         Tms的IP地址（内存长度为IA_IP_LEN）
* @param [OUT]   usTmsPort       Tms的端口号
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_GetTmsConfig(IN long lUserHandle,
                              OUT char *pcTmsIp,
                              OUT unsigned short *pusTmsPort);

/**
* 设置中心存储配置信息,当前只支持1个存储挂载
* @param [IN]    lUserHandle     用户登录句柄
* @param [IN]    pcStorageIp     Storage的Ip地址
* @param [IN]    usStoragePort   Storage的端口号
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_SetStorageConfig(IN long lUserHandle,
                                  IN char *pcStorageIp,
                                  IN unsigned short usStoragePort);

/**
* 获取中心存储配置信息
* @param [IN]    lUserHandle     用户登录句柄
* @param [OUT]   pcStorageIp     Storage的Ip地址（内存长度为IA_IP_LEN）
* @param [OUT]   pusStoragePort  Storage的端口号
* @return 成功 ERR_COMMON_SUCCEED
          错误 具体错误码
*/
long STDCALL IAC_GetStorageConfig(IN long lUserHandle,
                                  OUT char *pcStorageIp,
                                  OUT unsigned short *pusStoragePort);

/**
* 通过用户登录句柄与相机ID号获取一帧图片,历史图片路径信息
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] urlPicture   相机ID号/或者历史录像url路径
* @param [IN] pucPictureBuffer  图片缓存句柄
* @param [IN] lPictureBufferLen 图片缓存大小
* @return 获取一帧图片是否成功
*/
long STDCALL IAC_SnachOncePicture(IN long lUserHandle,
                                  IN char *urlPicture,
                                  IN unsigned char *pucPictureBuffer,
                                  INOUT long *plPictureBufferLen);

/**
* 消息及图片上报回调接口
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] pfnMsgCallBack        回调函数指针
* @param [IN] pUserData             用户数据
* @return 无
*/
void STDCALL IAC_SetMsgCallBack(IN long lUserHandle,
                                IN ClientMsgCallBack pfnClientMsgCallBack,
                                IN void *pUserData);


/***************************************************
**            智能相关业务配置                    **
***************************************************/
/**
* 从ias获取当前摄像机列表与状态信息
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pstIasCamereIntelligentInfo 摄像机智能列表信息
* @param [INOUT] ias摄像机数目
* @return 获取当前摄像机信息是否成功
*/
long STDCALL IAC_GetIntelligentInfo(IN long lUserHandle,
                                          OUT IA_INTELLIGENT_INFO_S *pstIasCamereIntelligentInfo,
                                          INOUT long *plIasCameraNum);

/**
* 查询指定相机的配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [OUT] pstIaIntelligentConfig 智能配置规则
* @return 智能配置规则
*/
long STDCALL IAC_GetIntelligentCfg(IN long lUserHandle,
                                         IN unsigned long ulIntelligentHandle,
                                         OUT IA_INTELLIGENT_CONFIG_S *pstIaIntelligentConfig);

/**
* 配置指定相机智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_CreateRealIntelligent(IN long lUserHandle,
                                            IN char *pcIntelligentID,
                                            IN char *pcCameraID,
                                            IN char *pcIntelligentName,
                                            IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                            OUT unsigned long *pulIntelligentHandle);

/**
* 创建一个违章检查业务
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_CreateIllegalParkIntelligent(IN long lUserHandle,
                                              IN char *pcIntelligentID,
                                              IN char *pcCameraID,
                                              IN char *pcIntelligentName,
                                              IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                              OUT unsigned long *pulIntelligentHandle);

/**
* 配置指定录像智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称
* @param [IN] pstIaVodIntelligentTaskInfo   录像回放扩展参数
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_CreateVodIntelligent(IN long lUserHandle,
                                               IN char *pcIntelligentID,
                                               IN char *pcCameraID,
                                               IN char *pcIntelligentName,
                                               IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                               IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                               OUT unsigned long *pulIntelligentHandle);
/**
* 配置指定相机录像智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentID  智能分析名称
* @param [IN] stIaIntelligentCfg 智能配置规则
* @param [IN] pstIaVodIntelligentTaskInfoOUT  回放扩展部分配置
* @param [OUT] pulIntelligentHandle 智能业务句柄
* @return 开启一路本地文件智能分析是否成功
*/
long STDCALL IAC_CreateFileIntelligent(IN long lUserHandle,
                                           IN const char *pcIntelligentID,
                                           IN const char *pIntelligentName,
                                           IN const char *pcCameraID,//文件名，不携带路径 非中文
                                           IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                           IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                           OUT unsigned long *pulIntelligentHandle);
/* BEGIN: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */
/**
* 创建一路监狱视频诊断
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称 [必须为utf 8 编码]
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 创建一路监狱视频诊断是否成功
*/
long STDCALL IAC_CreatePrisonDetectIntelligent(IN long lUserHandle,
                                                                            IN char *pcIntelligentID,
                                                                            IN char *pcCameraID,
                                                                            IN char *pcIntelligentName,
                                                                            IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                                                            OUT unsigned long *pulIntelligentHandle);
/* END: Added by chenxioayan, 2014/3/4 智能监所 问题单号: MPPD10105 */
/**
* 启动服务器端智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @return 启动服务器端智能配置参数
*/
long STDCALL IAC_StartIntelligent(IN long lUserHandle,
                                                 IN unsigned long ulIntelligentHandle);
/**
* 停止服务器端智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @return 停止服务器端智能配置参数
*/
void STDCALL IAC_StopIntelligent(IN long lUserHandle,
                                                IN unsigned long ulIntelligentHandle);

/**
* 删除指定相机智能配置规则
* @param [IN] lUserHandle          用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @return 开启一路实况是否成功
*/
void STDCALL IAC_DeleteIntelligent(IN long lUserHandle,
                                            IN unsigned long ulIntelligentHandle);

/**
* 设置是否开始相应的sender。
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [IN] ulSenderType         智能分发对象(IA_SENDER_TYPE_E进行或组合)
* @return 设置智能分析结果分发对象
*/
long STDCALL IAC_SetSenderType(IN long lUserHandle,
                               IN unsigned long ulIntelligentHandle,
                               IN unsigned long ulSenderType);

/**
* 获取服务器端读取的sender分发类型
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [IN] ulSenderType  智能分析分发类型
* @return 获取智能分析分发类型是否成功
*/
long STDCALL IAC_GetSenderType(IN long lUserHandle,
                               IN unsigned long ulIntelligentHandle,
                               OUT unsigned long *pulSenderType);

/**
* 设置智能业务计划
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [IN] stTaskPlanInfo       计划时间设置
* @return 设置任务分析计划是否成功
*/
long STDCALL IAC_SetTaskPlan(IN long lUserHandle,
                             IN unsigned long ulIntelligentHandle,
                             IN IA_TASK_PLAN_INFO_S *pstTaskPlanInfo);

/**
* 获取智能业务计划
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [OUT] stTaskPlanInfo       计划时间信息
* @return 获取任务分析计划是否成功
*/
long STDCALL IAC_GetTaskPlan(IN long lUserHandle,
                             IN unsigned long ulIntelligentHandle,
                             OUT IA_TASK_PLAN_INFO_S *pstTaskPlanInfo);

/**
* 获取ias数据库信息
* @param [IN] lUserHandle  用户登录句柄
* @param [Out]   pcDbAddr  Db的IP地址（内存长度为IA_IP_LEN）
* @return 错误码
*/
long STDCALL IAC_GetDbAddress(IN long lUserHandle,OUT char *pcDbAddr);

/**
* 获取ias系统信息
* @param [IN] lUserHandle  用户登录句柄
* @param [INOut]pcInfo  ias的系统信息
* @return 错误码
*/
long STDCALL IAC_GetSystemInfo(IN long lUserHandle,OUT IA_SYSTEM_INFO_S *pcInfo);

/**
* 生成Host文件
* @param[in] lUserHandle    用户登录句柄
* @param[in] pstClientInfo户信息结构体
* @param[in] pcContractId   合同编号
* @param[out] pstrHostIdFileData  生成的Host文件的内容
* @param[out] plLen               生产的Host文件大小
* @return ERR_IA_COMMON_SUCCESS            成功
          ERR_COMMON_FAILURE            生成文件失败
          ERR_IA_COMMON_MEM_INSUFFICIENT   内存不足
          ERR_IA_COMMON_NONVALID_PARAM     无效参数
* @note 调用接口前，分配20k左右的内存。当返回内存不足时，plLen指出了实际内存大小
*/
long STDCALL IAC_MakeHostIdFile(IN long lUserHandle, IN const IA_CLIENTINFO_S *pstClientInfo, IN const char *pcContractId, OUT char *pcHostIdFileData, OUT long *plLen);

/**
* 保存License文件
* @param[in] lUserHandle    用户登录句柄
* @param[in] pcLicenseData    License文件内容
* @param[in] lLen             文件长度
* @return ERR_IA_COMMON_SUCCESS 成功
          ERR_COMMON_FAILURE 失败
*/
long STDCALL IAC_LoadLicenseFile(IN long lUserHandle, IN const char *pcLicenseData, IN const long lLen);

/**
* 获取当前授权信息列表
* @param[in] lUserHandle    用户登录句柄
* @param[out] pstLicenseInfo，授权信息列表
* @param[inout] plLicenseNum，授权信息个数
* @return ERR_IA_COMMON_SUCCESS            成功
         ERR_IA_COMMON_MEM_INSUFFICIENT    内存不足
         ERR_COMMON_INVALID_PARAM          无效参数
*/
long STDCALL IAC_GetCurLicenseInfo(IN long lUserHandle, OUT IA_LICENSE_INFO_S *pstLicenseInfo, INOUT long *plLicenseNum);

/**
* 获取任务状态信息
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [OUT]pulStatus  任务状态
* @return 错误码
*/
long STDCALL IAC_GetTaskStatus(IN long lUserHandle,IN unsigned long ulIntelligentHandle,INOUT unsigned long *pulStatus);

/**
* 设置任务状态信息
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [OUT]pulStatus  任务状态
* @return 错误码
*/
long STDCALL IAC_SetTaskStatus(IN long lUserHandle,IN unsigned long ulIntelligentHandle,IN unsigned long ulStatus);

/**
* 获取IAS ID
* @param [IN] lUserHandle  用户登录句柄
* @param [Out]   pcIASID  Db的IP地址（内存长度为IA_ITEM_NAME_LEN）
* @return 错误码
*/
long STDCALL IAC_GetDeviceID(IN long lUserHandle,INOUT char *pcIASID);

/**
* 通过智能id获取智能句柄
* @param [IN] pcIntelligentID 设备id（内存长度为IA_ITEM_NAME_LEN）
* @return 句柄
注，必须是IAS_init 之后调用
*/
long STDCALL IAC_GetIntelligentHandle(IN long lUserHandle,IN char *pcIntelligentID);

/**
* 获取任务进度信息
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [OUT]pulSchedule  任务进度
* 需要结合任务目前所处的状态
* @return 错误码
*/
long STDCALL IAC_GetTaskSchedule(IN long lUserHandle,IN unsigned long ulIntelligentHandle,INOUT unsigned long *pulSchedule);

/**
* 获取当前授权信息列表
* @param[in] lUserHandle         用户登录句柄
* @param[in] ulIntelligentHandle 智能分析业务句柄
* @param[in] lManufacture，      设备厂商ID
* @param[in] lDevType            设备类型ID
* @param[in] lAlarmType          告警类型
* @return ERR_IA_COMMON_SUCCESS            成功
         ERR_IA_COMMON_MEM_INSUFFICIENT    内存不足
         ERR_COMMON_INVALID_PARAM          无效参数
*/
long STDCALL IAC_AddAlarm(IN long lUserHandle, IN unsigned long ulIntelligentHandle, IN long lManufacture, IN long lDevType, IN long lAlarmType);

/**
* 获取任务状态信息
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] ulIntelligentHandle  智能任务句柄
* @param [OUT] lManufacture，      设备厂商ID
* @param [OUT] lDevType            设备类型ID
* @param [OUT] lAlarmType          告警类型
* @return 错误码
*/
long STDCALL IAC_QueryAlarm(IN long lUserHandle,IN unsigned long ulIntelligentHandle,IN long *plManufacture, IN long *plDevType, IN long *plAlarmType);

/**
* 配置指定相机智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称[必须为uft8编码]
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_CreateHttpCBIntelligent(IN long lUserHandle,
                                            IN char *pcIntelligentID,
                                            IN char *pcCameraID,
                                            IN char *pcIntelligentName,
                                            IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                            IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                            OUT unsigned long *pulIntelligentHandle);

/**
* 配置指定相机智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称[必须为uft8编码]
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_CreateHttpTelIntelligent(IN long lUserHandle,
                                         IN char *pcIntelligentID,
                                         IN char *pcCameraID,
                                         IN char *pcIntelligentName,
                                         IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                         IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                         OUT unsigned long *pulIntelligentHandle);

/**
* 配置指定相机智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称[必须为uft8编码]
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路车型检测是否成功
*/
long STDCALL IAC_CreateCarTypeIntelligent(IN long lUserHandle,
    IN char *pcIntelligentID,
    IN char *pcCameraID,
    IN char *pcIntelligentName,
    IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
    IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
    OUT unsigned long *pulIntelligentHandle);

/**
* 配置指定车道启用占道分析规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称[必须为uft8编码]
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_CreateDbIntelligent(IN long lUserHandle,
                                        IN char *pcIntelligentID,
                                        IN char *pcLaneID,
                                        IN char *pcIntelligentName,
                                        IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                        IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                        OUT unsigned long *pulIntelligentHandle);

/**
* 启动一个抢球联动业务
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] pcIntelligentID   智能分析ID号
* @param [IN] pcBallLinkageRes  枪球联动资源
* @param [IN] pcIntelligentName 智能分析名称
* @param [IN] pstIaIntelligentCfg   智能配置规则
* @param [OUT] pulIntelligentHandle 智能分析句柄
* @return 错误码
*/
long STDCALL IAC_CreateBallLinkageIntelligent(IN long lUserHandle,
                                              IN char *pcIntelligentID,
                                              IN char *pcBallLinkageRes,
                                              IN char *pcIntelligentName,
                                              IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                              OUT unsigned long *pulIntelligentHandle);

/**
* 设置枪机中的跟踪目标坐标信息
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] lIntelligentHandle    智能分析ID号
* @param [IN] lTraceObjPointX       枪机跟踪目标横坐标信息
* @param [IN] lTraceObjPointY       枪机跟踪目标纵坐标信息
* @return 错误码
*/
long STDCALL IAC_SetTraceObjForBall(IN long lUserHandle,
                                    IN long lIntelligentHandle,
                                    IN long lTraceObjPointX,
                                    IN long lTraceObjPointY);
/**
* 启动客户端媒体收流端口信息
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] lIntelligentHandle    智能分析ID号
* @param [IN] pucClientIp           客户端收流IP地址
* @param [IN] lClientPort           客户端收流Port地址
* @return 错误码
*/
long STDCALL IAC_StartClientReceiveInfo(IN long lUserHandle,
                                        IN long lIntelligentHandle,
                                        IN const char *pcClientIp,
                                        IN long lClientPort);

/**
* 设置媒体流类型
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] lIntelligentHandle    智能分析任务句柄
* @param [IN] pcDecoderTag          媒体流类型
* @return 错误码
*/
long STDCALL IAC_SetDecoderTag(IN long lUserHandle,
                               IN long lIntelligentHandle,
                               IN const char *pcDecoderTag);

/**
* 停止客户端媒体收流端口信息
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] lIntelligentHandle    智能分析ID号
* @param [IN] pucClientIp           客户端收流IP地址
* @param [IN] lClientPort           客户端收流Port地址
* @return 错误码
*/
long STDCALL IAC_StopClientReceiveInfo(IN long lUserHandle,
                                       IN long lIntelligentHandle,
                                       IN const char *pcClientIp,
                                       IN long lClientPort);

/**
* 设置客户端媒体收流端口信息
* @param [IN] lUserHandle           用户登录句柄
* @param [IN] lIntelligentHandle    智能分析ID号
* @param [IN] pucTmsIp              客户端收流IP地址
* @param [IN] iTmsPort              客户端收流Port地址
* @param [IN] pucDevCode            卡口设备编码
* @param [IN] iLaneId               车道信息
* @return 错误码
*/
long STDCALL IAC_AddTmsBindInfo(IN long lUserHandle,
                                IN long lIntelligentHandle,
                                IN const char *pcTmsIp,
                                IN long lTmsPort,
                                IN const char *pcDevCode,
                                IN long lLaneId);

/**
* 获取指定业务类型运行的Ias服务器地址与任务句柄信息
* @param [IN] pcResCode             资源编码
* @param [IN] enRunMode             业务类型
* @param [IN] pcIasIp               Ia Server地址信息
* @param [IN] pusIasPort            Ia Server服务器端口号
* @param [IN] pulIntelligentHandle  智能任务句柄
* @return 错误码
*/
long STDCALL IAC_QueryServerAddr(IN char *pcResCode,
                                 IN IA_RUN_MODE_E enRunMode,
                                 OUT char *pcIasIp,
                                 OUT unsigned short *pusIasPort,
                                 OUT unsigned long *pulIntelligentHandle);


/* 创建一个视频诊断业务
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] pcIntelligentName 智能分析名称
* @param [IN] pcIntelligentID   智能分析ID号
* @param [IN] ulVideoDiagnosisType  视频诊断类型
* @param [IN] ppcCameraID           视频诊断摄像机列表
* @param [IN] lCameraNum            视频诊断摄像机个数
* @param [OUT] pulIntelligentHandle 智能分析句柄
* @return 错误码
*/
long STDCALL IAC_CreateVDIntelligent(IN long lUserHandle,
                                     IN char *pcIntelligentName,
                                     IN char *pcIntelligentID,
                                     IN unsigned long ulVideoDiagnosisType,
                                     IN char **ppcCameraID,
                                     IN long lCameraNum,
                                     OUT unsigned long *pulIntelligentHandle);

/* 增加相机到视频诊断组
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] ulIntelligentHandle 视频诊断任务句柄
* @param [IN] ppcCameraID       需要添加的摄像机列表
* @param [IN] lCameraNum        需要添加的摄像机个数
* @return 错误码
*/
long STDCALL IAC_SubVDCamera(IN long lUserHandle,
                                                    IN unsigned long ulIntelligentHandle,
                                                    IN char **ppcCameraID,
                                                    IN long lCameraNum);

/* 从视频诊断组中删除一批摄像机
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] ulIntelligentHandle 视频诊断任务句柄
* @param [IN] ppcCameraID       需要添加的摄像机列表
* @param [IN] lCameraNum        需要添加的摄像机个数
* @return 错误码
*/
long STDCALL IAC_AddVDCamera(IN long lUserHandle,
                                                    IN unsigned long ulIntelligentHandle,
                                                    IN char **ppcCameraID,
                                                    IN long lCameraNum);

/* 暂停视频诊断
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] ulIntelligentHandle 视频诊断任务句柄
* @return 错误码
*/
long STDCALL IAC_PauseVDIntelligent(IN long lUserHandle,
                                                           IN unsigned long ulIntelligentHandle);

/* 恢复暂停的视频诊断，只对暂停任务有效
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] ulIntelligentHandle 视频诊断任务句柄
* @return 错误码
*/
long STDCALL IAC_ResumeVDIntelligent(IN long lUserHandle,
                                                              IN unsigned long ulIntelligentHandle);

/* 恢复暂停的视频诊断，只对暂停任务有效
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] ulIntelligentHandle 视频诊断任务句柄
* @return 错误码
*/
long STDCALL IAC_RestartVDIntelligent(IN long lUserHandle,
                                                             IN unsigned long ulIntelligentHandle);

/* 恢复暂停的视频诊断，只对暂停任务有效
* @param [IN] lUserHandle       用户登录句柄
* @param [IN] ulIntelligentHandle 视频诊断任务句柄
* @param [IN] ulRestartTimes      第几次进行重新诊断操作
* @return 错误码
*/
long STDCALL IAC_RestartVDIntelligentV2(IN long lUserHandle,
                                     IN unsigned long ulIntelligentHandle,
                                     IN unsigned long ulRestartTimes);

/**
* 配置指定录像智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称
* @param [IN] pstIaVodIntelligentTaskInfo   录像回放扩展参数
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路实况智能分析是否成功
*/
long STDCALL IAC_Create9linVodIntelligent(IN long lUserHandle,
    IN char *pcIntelligentID,
    IN char *pcIntelligentName,
    IN char *pcCameraID,
    IN const char *pcCfgData,
    IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
    IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
    OUT unsigned long *pulIntelligentHandle);
/**
* 配置指定相机录像智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentID  智能分析名称
* @param [IN] stIaIntelligentCfg 智能配置规则
* @param [IN] pstIaVodIntelligentTaskInfoOUT  回放扩展部分配置
* @param [OUT] pulIntelligentHandle 智能业务句柄
* @return 开启一路本地文件智能分析是否成功
*/
long STDCALL IAC_Create9linFileIntelligent(IN long lUserHandle,
                                           IN const char *pcIntelligentID,
                                           IN const char *pIntelligentName,
                                           IN const char *pcCameraID,//文件名，不携带路径 非中文
                                           IN const char *pcCfgData,
                                           IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                           IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                           OUT unsigned long *pulIntelligentHandle);

/**
* 配置指定录像智能配置规则
* @param [IN] lUserHandle  用户登录句柄
* @param [IN] pcCameraID   摄像机ID号
* @param [IN] pcIntelligentName             智能业务名称
* @param [IN] pstIaVodIntelligentTaskInfo   录像回放扩展参数
* @param [IN] stIaIntelligentCfg            智能配置规则
* @param [OUT] pulIntelligentHandle         智能业务句柄
* @return 开启一路华亿实况智能分析是否成功
*/
long STDCALL IAC_CreateHuayiIntelligent(IN long lUserHandle,
    IN char *pcIntelligentID,
    IN char *pcCameraID,
    IN char *pcIntelligentName,
    IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
    IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
    OUT unsigned long *pulIntelligentHandle);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif
