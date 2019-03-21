#ifndef __IA_CLIENT_LIB_H__
#define __IA_CLIENT_LIB_H__

#include "imos_ia_error.h"
#include "imos_ia_def.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* ia�ͻ���Э��ȫ�ֳ�ʼ��
* @param [IN] ��
* @return ��ʼ���Ƿ�ɹ�
*/
long STDCALL IAC_Init();

/**
* ia�ͻ���Э��ȫ���ͷ�
* @param [IN] ��
* @return
*/
void STDCALL IAC_Uninit();

/**
* ias�û���¼�ӿ�
* @param [IN] pcIasIP       ias��������ַ
* @param [IN] usIasPort     ias�������˿�
* @param [IN] pcUserName    �û���
* @param [IN] pcPasswd      ����(MD5����)
* @param [OUT] lUserHandle  �û���¼���
* @return ���ش�����
*/
long STDCALL IAC_Login(IN char *pcIasIP,
                       IN unsigned short usIasPort,
                       IN char *pcUserName,
                       IN char *pcPasswd,
                       OUT long *plUserHandle);

/**
* iac�û��ǳ��ӿ�
* @param [IN] lUserHandle  IAC_logout����ֵ
* @return ��
*/
void STDCALL IAC_Logout(IN long lUserHandle);

/**
* �����û�����
* @param [IN] lUserHandle  login����ֵ
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_Keeplive(IN long lUserHandle);

/**
* ����ias��Ӧ��vm��������Ϣ
* @param [IN]   lUserHandle     �û���¼���
* @param [IN]   pcVmServerIP    VM��������¼IP��ַ
* @param [IN]   usVmServerPort  VM��������¼�˿ں�
* @param [IN]   pcVmUserName    VM��¼�û���
* @param [IN]   pcVmUserPasswd  VM��¼����(MD5����)
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_SetVmConfig(IN long lUserHandle,
                             IN char *pcVmServerIP,
                             IN unsigned short usVmServerPort,
                             IN char *pcVmUserName,
                             IN char *pcVmUserPasswd);

/**
* ��ȡias��Ӧ��vm��������Ϣ
* @param [IN]    lUserHandle     �û���¼���
* @param [OUT]   pcVmServerIP    VM��������¼IP��ַ���ڴ泤��ΪIA_IP_LEN��
* @param [OUT]   pusVmServerPort VM��������¼�˿ں�
* @param [OUT]   pcVmUserName    VM��¼�û������ڴ泤��ΪIA_ITEM_NAME_LEN��
* @param [OUT]   pcVmUserPasswd  VM��¼����(MD5����)���ڴ泤��ΪIA_PASSWD_LEN��
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_GetVmConfig(IN long lUserHandle,
                             OUT char *pcVmServerIP,
                             OUT unsigned short *pusVmServerPort,
                             OUT char *pcVmUserName,
                             OUT char *pcVmUserPasswd);

/**
* ����ias��Ӧ��TMS��������Ϣ
* @param [IN]    lUserHandle     �û���¼���
* @param [IN]    pcTmsIp         Tms��IP��ַ
* @param [IN]    usTmsPort       Tms�Ķ˿ں�
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_SetTmsConfig(IN long lUserHandle,
                              IN char *pcTmsIp,
                              IN unsigned short usTmsPort);

/**
* ��ȡias��Ӧ��TMS��������Ϣ
* @param [IN]    lUserHandle     �û���¼���
* @param [OUT]   pcTmsIp         Tms��IP��ַ���ڴ泤��ΪIA_IP_LEN��
* @param [OUT]   usTmsPort       Tms�Ķ˿ں�
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_GetTmsConfig(IN long lUserHandle,
                              OUT char *pcTmsIp,
                              OUT unsigned short *pusTmsPort);

/**
* �������Ĵ洢������Ϣ,��ǰֻ֧��1���洢����
* @param [IN]    lUserHandle     �û���¼���
* @param [IN]    pcStorageIp     Storage��Ip��ַ
* @param [IN]    usStoragePort   Storage�Ķ˿ں�
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_SetStorageConfig(IN long lUserHandle,
                                  IN char *pcStorageIp,
                                  IN unsigned short usStoragePort);

/**
* ��ȡ���Ĵ洢������Ϣ
* @param [IN]    lUserHandle     �û���¼���
* @param [OUT]   pcStorageIp     Storage��Ip��ַ���ڴ泤��ΪIA_IP_LEN��
* @param [OUT]   pusStoragePort  Storage�Ķ˿ں�
* @return �ɹ� ERR_COMMON_SUCCEED
          ���� ���������
*/
long STDCALL IAC_GetStorageConfig(IN long lUserHandle,
                                  OUT char *pcStorageIp,
                                  OUT unsigned short *pusStoragePort);

/**
* ͨ���û���¼��������ID�Ż�ȡһ֡ͼƬ,��ʷͼƬ·����Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [IN] urlPicture   ���ID��/������ʷ¼��url·��
* @param [IN] pucPictureBuffer  ͼƬ������
* @param [IN] lPictureBufferLen ͼƬ�����С
* @return ��ȡһ֡ͼƬ�Ƿ�ɹ�
*/
long STDCALL IAC_SnachOncePicture(IN long lUserHandle,
                                  IN char *urlPicture,
                                  IN unsigned char *pucPictureBuffer,
                                  INOUT long *plPictureBufferLen);

/**
* ��Ϣ��ͼƬ�ϱ��ص��ӿ�
* @param [IN] lUserHandle           �û���¼���
* @param [IN] pfnMsgCallBack        �ص�����ָ��
* @param [IN] pUserData             �û�����
* @return ��
*/
void STDCALL IAC_SetMsgCallBack(IN long lUserHandle,
                                IN ClientMsgCallBack pfnClientMsgCallBack,
                                IN void *pUserData);


/***************************************************
**            �������ҵ������                    **
***************************************************/
/**
* ��ias��ȡ��ǰ������б���״̬��Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pstIasCamereIntelligentInfo ����������б���Ϣ
* @param [INOUT] ias�������Ŀ
* @return ��ȡ��ǰ�������Ϣ�Ƿ�ɹ�
*/
long STDCALL IAC_GetIntelligentInfo(IN long lUserHandle,
                                          OUT IA_INTELLIGENT_INFO_S *pstIasCamereIntelligentInfo,
                                          INOUT long *plIasCameraNum);

/**
* ��ѯָ����������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [OUT] pstIaIntelligentConfig �������ù���
* @return �������ù���
*/
long STDCALL IAC_GetIntelligentCfg(IN long lUserHandle,
                                         IN unsigned long ulIntelligentHandle,
                                         OUT IA_INTELLIGENT_CONFIG_S *pstIaIntelligentConfig);

/**
* ����ָ������������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateRealIntelligent(IN long lUserHandle,
                                            IN char *pcIntelligentID,
                                            IN char *pcCameraID,
                                            IN char *pcIntelligentName,
                                            IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                            OUT unsigned long *pulIntelligentHandle);

/**
* ����һ��Υ�¼��ҵ��
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateIllegalParkIntelligent(IN long lUserHandle,
                                              IN char *pcIntelligentID,
                                              IN char *pcCameraID,
                                              IN char *pcIntelligentName,
                                              IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                              OUT unsigned long *pulIntelligentHandle);

/**
* ����ָ��¼���������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������
* @param [IN] pstIaVodIntelligentTaskInfo   ¼��ط���չ����
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateVodIntelligent(IN long lUserHandle,
                                               IN char *pcIntelligentID,
                                               IN char *pcCameraID,
                                               IN char *pcIntelligentName,
                                               IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                               IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                               OUT unsigned long *pulIntelligentHandle);
/**
* ����ָ�����¼���������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentID  ���ܷ�������
* @param [IN] stIaIntelligentCfg �������ù���
* @param [IN] pstIaVodIntelligentTaskInfoOUT  �ط���չ��������
* @param [OUT] pulIntelligentHandle ����ҵ����
* @return ����һ·�����ļ����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateFileIntelligent(IN long lUserHandle,
                                           IN const char *pcIntelligentID,
                                           IN const char *pIntelligentName,
                                           IN const char *pcCameraID,//�ļ�������Я��·�� ������
                                           IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                           IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                           OUT unsigned long *pulIntelligentHandle);
/* BEGIN: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */
/**
* ����һ·������Ƶ���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������ [����Ϊutf 8 ����]
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·������Ƶ����Ƿ�ɹ�
*/
long STDCALL IAC_CreatePrisonDetectIntelligent(IN long lUserHandle,
                                                                            IN char *pcIntelligentID,
                                                                            IN char *pcCameraID,
                                                                            IN char *pcIntelligentName,
                                                                            IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                                                            OUT unsigned long *pulIntelligentHandle);
/* END: Added by chenxioayan, 2014/3/4 ���ܼ��� ���ⵥ��: MPPD10105 */
/**
* �������������������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @return �������������������ò���
*/
long STDCALL IAC_StartIntelligent(IN long lUserHandle,
                                                 IN unsigned long ulIntelligentHandle);
/**
* ֹͣ���������������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @return ֹͣ���������������ò���
*/
void STDCALL IAC_StopIntelligent(IN long lUserHandle,
                                                IN unsigned long ulIntelligentHandle);

/**
* ɾ��ָ������������ù���
* @param [IN] lUserHandle          �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @return ����һ·ʵ���Ƿ�ɹ�
*/
void STDCALL IAC_DeleteIntelligent(IN long lUserHandle,
                                            IN unsigned long ulIntelligentHandle);

/**
* �����Ƿ�ʼ��Ӧ��sender��
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [IN] ulSenderType         ���ַܷ�����(IA_SENDER_TYPE_E���л����)
* @return �������ܷ�������ַ�����
*/
long STDCALL IAC_SetSenderType(IN long lUserHandle,
                               IN unsigned long ulIntelligentHandle,
                               IN unsigned long ulSenderType);

/**
* ��ȡ�������˶�ȡ��sender�ַ�����
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [IN] ulSenderType  ���ܷ����ַ�����
* @return ��ȡ���ܷ����ַ������Ƿ�ɹ�
*/
long STDCALL IAC_GetSenderType(IN long lUserHandle,
                               IN unsigned long ulIntelligentHandle,
                               OUT unsigned long *pulSenderType);

/**
* ��������ҵ��ƻ�
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [IN] stTaskPlanInfo       �ƻ�ʱ������
* @return ������������ƻ��Ƿ�ɹ�
*/
long STDCALL IAC_SetTaskPlan(IN long lUserHandle,
                             IN unsigned long ulIntelligentHandle,
                             IN IA_TASK_PLAN_INFO_S *pstTaskPlanInfo);

/**
* ��ȡ����ҵ��ƻ�
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [OUT] stTaskPlanInfo       �ƻ�ʱ����Ϣ
* @return ��ȡ��������ƻ��Ƿ�ɹ�
*/
long STDCALL IAC_GetTaskPlan(IN long lUserHandle,
                             IN unsigned long ulIntelligentHandle,
                             OUT IA_TASK_PLAN_INFO_S *pstTaskPlanInfo);

/**
* ��ȡias���ݿ���Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [Out]   pcDbAddr  Db��IP��ַ���ڴ泤��ΪIA_IP_LEN��
* @return ������
*/
long STDCALL IAC_GetDbAddress(IN long lUserHandle,OUT char *pcDbAddr);

/**
* ��ȡiasϵͳ��Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [INOut]pcInfo  ias��ϵͳ��Ϣ
* @return ������
*/
long STDCALL IAC_GetSystemInfo(IN long lUserHandle,OUT IA_SYSTEM_INFO_S *pcInfo);

/**
* ����Host�ļ�
* @param[in] lUserHandle    �û���¼���
* @param[in] pstClientInfo�ͻ���Ϣ�ṹ��
* @param[in] pcContractId   ��ͬ���
* @param[out] pstrHostIdFileData  ���ɵ�Host�ļ�������
* @param[out] plLen               ������Host�ļ���С
* @return ERR_IA_COMMON_SUCCESS            �ɹ�
          ERR_COMMON_FAILURE            �����ļ�ʧ��
          ERR_IA_COMMON_MEM_INSUFFICIENT   �ڴ治��
          ERR_IA_COMMON_NONVALID_PARAM     ��Ч����
* @note ���ýӿ�ǰ������20k���ҵ��ڴ档�������ڴ治��ʱ��plLenָ����ʵ���ڴ��С
*/
long STDCALL IAC_MakeHostIdFile(IN long lUserHandle, IN const IA_CLIENTINFO_S *pstClientInfo, IN const char *pcContractId, OUT char *pcHostIdFileData, OUT long *plLen);

/**
* ����License�ļ�
* @param[in] lUserHandle    �û���¼���
* @param[in] pcLicenseData    License�ļ�����
* @param[in] lLen             �ļ�����
* @return ERR_IA_COMMON_SUCCESS �ɹ�
          ERR_COMMON_FAILURE ʧ��
*/
long STDCALL IAC_LoadLicenseFile(IN long lUserHandle, IN const char *pcLicenseData, IN const long lLen);

/**
* ��ȡ��ǰ��Ȩ��Ϣ�б�
* @param[in] lUserHandle    �û���¼���
* @param[out] pstLicenseInfo����Ȩ��Ϣ�б�
* @param[inout] plLicenseNum����Ȩ��Ϣ����
* @return ERR_IA_COMMON_SUCCESS            �ɹ�
         ERR_IA_COMMON_MEM_INSUFFICIENT    �ڴ治��
         ERR_COMMON_INVALID_PARAM          ��Ч����
*/
long STDCALL IAC_GetCurLicenseInfo(IN long lUserHandle, OUT IA_LICENSE_INFO_S *pstLicenseInfo, INOUT long *plLicenseNum);

/**
* ��ȡ����״̬��Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [OUT]pulStatus  ����״̬
* @return ������
*/
long STDCALL IAC_GetTaskStatus(IN long lUserHandle,IN unsigned long ulIntelligentHandle,INOUT unsigned long *pulStatus);

/**
* ��������״̬��Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [OUT]pulStatus  ����״̬
* @return ������
*/
long STDCALL IAC_SetTaskStatus(IN long lUserHandle,IN unsigned long ulIntelligentHandle,IN unsigned long ulStatus);

/**
* ��ȡIAS ID
* @param [IN] lUserHandle  �û���¼���
* @param [Out]   pcIASID  Db��IP��ַ���ڴ泤��ΪIA_ITEM_NAME_LEN��
* @return ������
*/
long STDCALL IAC_GetDeviceID(IN long lUserHandle,INOUT char *pcIASID);

/**
* ͨ������id��ȡ���ܾ��
* @param [IN] pcIntelligentID �豸id���ڴ泤��ΪIA_ITEM_NAME_LEN��
* @return ���
ע��������IAS_init ֮�����
*/
long STDCALL IAC_GetIntelligentHandle(IN long lUserHandle,IN char *pcIntelligentID);

/**
* ��ȡ���������Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [OUT]pulSchedule  �������
* ��Ҫ�������Ŀǰ������״̬
* @return ������
*/
long STDCALL IAC_GetTaskSchedule(IN long lUserHandle,IN unsigned long ulIntelligentHandle,INOUT unsigned long *pulSchedule);

/**
* ��ȡ��ǰ��Ȩ��Ϣ�б�
* @param[in] lUserHandle         �û���¼���
* @param[in] ulIntelligentHandle ���ܷ���ҵ����
* @param[in] lManufacture��      �豸����ID
* @param[in] lDevType            �豸����ID
* @param[in] lAlarmType          �澯����
* @return ERR_IA_COMMON_SUCCESS            �ɹ�
         ERR_IA_COMMON_MEM_INSUFFICIENT    �ڴ治��
         ERR_COMMON_INVALID_PARAM          ��Ч����
*/
long STDCALL IAC_AddAlarm(IN long lUserHandle, IN unsigned long ulIntelligentHandle, IN long lManufacture, IN long lDevType, IN long lAlarmType);

/**
* ��ȡ����״̬��Ϣ
* @param [IN] lUserHandle  �û���¼���
* @param [IN] ulIntelligentHandle  ����������
* @param [OUT] lManufacture��      �豸����ID
* @param [OUT] lDevType            �豸����ID
* @param [OUT] lAlarmType          �澯����
* @return ������
*/
long STDCALL IAC_QueryAlarm(IN long lUserHandle,IN unsigned long ulIntelligentHandle,IN long *plManufacture, IN long *plDevType, IN long *plAlarmType);

/**
* ����ָ������������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������[����Ϊuft8����]
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateHttpCBIntelligent(IN long lUserHandle,
                                            IN char *pcIntelligentID,
                                            IN char *pcCameraID,
                                            IN char *pcIntelligentName,
                                            IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                            IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                            OUT unsigned long *pulIntelligentHandle);

/**
* ����ָ������������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������[����Ϊuft8����]
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateHttpTelIntelligent(IN long lUserHandle,
                                         IN char *pcIntelligentID,
                                         IN char *pcCameraID,
                                         IN char *pcIntelligentName,
                                         IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                         IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                         OUT unsigned long *pulIntelligentHandle);

/**
* ����ָ������������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������[����Ϊuft8����]
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·���ͼ���Ƿ�ɹ�
*/
long STDCALL IAC_CreateCarTypeIntelligent(IN long lUserHandle,
    IN char *pcIntelligentID,
    IN char *pcCameraID,
    IN char *pcIntelligentName,
    IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
    IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
    OUT unsigned long *pulIntelligentHandle);

/**
* ����ָ����������ռ����������
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������[����Ϊuft8����]
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_CreateDbIntelligent(IN long lUserHandle,
                                        IN char *pcIntelligentID,
                                        IN char *pcLaneID,
                                        IN char *pcIntelligentName,
                                        IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                        IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                        OUT unsigned long *pulIntelligentHandle);

/**
* ����һ����������ҵ��
* @param [IN] lUserHandle       �û���¼���
* @param [IN] pcIntelligentID   ���ܷ���ID��
* @param [IN] pcBallLinkageRes  ǹ��������Դ
* @param [IN] pcIntelligentName ���ܷ�������
* @param [IN] pstIaIntelligentCfg   �������ù���
* @param [OUT] pulIntelligentHandle ���ܷ������
* @return ������
*/
long STDCALL IAC_CreateBallLinkageIntelligent(IN long lUserHandle,
                                              IN char *pcIntelligentID,
                                              IN char *pcBallLinkageRes,
                                              IN char *pcIntelligentName,
                                              IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                              OUT unsigned long *pulIntelligentHandle);

/**
* ����ǹ���еĸ���Ŀ��������Ϣ
* @param [IN] lUserHandle           �û���¼���
* @param [IN] lIntelligentHandle    ���ܷ���ID��
* @param [IN] lTraceObjPointX       ǹ������Ŀ���������Ϣ
* @param [IN] lTraceObjPointY       ǹ������Ŀ����������Ϣ
* @return ������
*/
long STDCALL IAC_SetTraceObjForBall(IN long lUserHandle,
                                    IN long lIntelligentHandle,
                                    IN long lTraceObjPointX,
                                    IN long lTraceObjPointY);
/**
* �����ͻ���ý�������˿���Ϣ
* @param [IN] lUserHandle           �û���¼���
* @param [IN] lIntelligentHandle    ���ܷ���ID��
* @param [IN] pucClientIp           �ͻ�������IP��ַ
* @param [IN] lClientPort           �ͻ�������Port��ַ
* @return ������
*/
long STDCALL IAC_StartClientReceiveInfo(IN long lUserHandle,
                                        IN long lIntelligentHandle,
                                        IN const char *pcClientIp,
                                        IN long lClientPort);

/**
* ����ý��������
* @param [IN] lUserHandle           �û���¼���
* @param [IN] lIntelligentHandle    ���ܷ���������
* @param [IN] pcDecoderTag          ý��������
* @return ������
*/
long STDCALL IAC_SetDecoderTag(IN long lUserHandle,
                               IN long lIntelligentHandle,
                               IN const char *pcDecoderTag);

/**
* ֹͣ�ͻ���ý�������˿���Ϣ
* @param [IN] lUserHandle           �û���¼���
* @param [IN] lIntelligentHandle    ���ܷ���ID��
* @param [IN] pucClientIp           �ͻ�������IP��ַ
* @param [IN] lClientPort           �ͻ�������Port��ַ
* @return ������
*/
long STDCALL IAC_StopClientReceiveInfo(IN long lUserHandle,
                                       IN long lIntelligentHandle,
                                       IN const char *pcClientIp,
                                       IN long lClientPort);

/**
* ���ÿͻ���ý�������˿���Ϣ
* @param [IN] lUserHandle           �û���¼���
* @param [IN] lIntelligentHandle    ���ܷ���ID��
* @param [IN] pucTmsIp              �ͻ�������IP��ַ
* @param [IN] iTmsPort              �ͻ�������Port��ַ
* @param [IN] pucDevCode            �����豸����
* @param [IN] iLaneId               ������Ϣ
* @return ������
*/
long STDCALL IAC_AddTmsBindInfo(IN long lUserHandle,
                                IN long lIntelligentHandle,
                                IN const char *pcTmsIp,
                                IN long lTmsPort,
                                IN const char *pcDevCode,
                                IN long lLaneId);

/**
* ��ȡָ��ҵ���������е�Ias��������ַ����������Ϣ
* @param [IN] pcResCode             ��Դ����
* @param [IN] enRunMode             ҵ������
* @param [IN] pcIasIp               Ia Server��ַ��Ϣ
* @param [IN] pusIasPort            Ia Server�������˿ں�
* @param [IN] pulIntelligentHandle  ����������
* @return ������
*/
long STDCALL IAC_QueryServerAddr(IN char *pcResCode,
                                 IN IA_RUN_MODE_E enRunMode,
                                 OUT char *pcIasIp,
                                 OUT unsigned short *pusIasPort,
                                 OUT unsigned long *pulIntelligentHandle);


/* ����һ����Ƶ���ҵ��
* @param [IN] lUserHandle       �û���¼���
* @param [IN] pcIntelligentName ���ܷ�������
* @param [IN] pcIntelligentID   ���ܷ���ID��
* @param [IN] ulVideoDiagnosisType  ��Ƶ�������
* @param [IN] ppcCameraID           ��Ƶ���������б�
* @param [IN] lCameraNum            ��Ƶ������������
* @param [OUT] pulIntelligentHandle ���ܷ������
* @return ������
*/
long STDCALL IAC_CreateVDIntelligent(IN long lUserHandle,
                                     IN char *pcIntelligentName,
                                     IN char *pcIntelligentID,
                                     IN unsigned long ulVideoDiagnosisType,
                                     IN char **ppcCameraID,
                                     IN long lCameraNum,
                                     OUT unsigned long *pulIntelligentHandle);

/* �����������Ƶ�����
* @param [IN] lUserHandle       �û���¼���
* @param [IN] ulIntelligentHandle ��Ƶ���������
* @param [IN] ppcCameraID       ��Ҫ��ӵ�������б�
* @param [IN] lCameraNum        ��Ҫ��ӵ����������
* @return ������
*/
long STDCALL IAC_SubVDCamera(IN long lUserHandle,
                                                    IN unsigned long ulIntelligentHandle,
                                                    IN char **ppcCameraID,
                                                    IN long lCameraNum);

/* ����Ƶ�������ɾ��һ�������
* @param [IN] lUserHandle       �û���¼���
* @param [IN] ulIntelligentHandle ��Ƶ���������
* @param [IN] ppcCameraID       ��Ҫ��ӵ�������б�
* @param [IN] lCameraNum        ��Ҫ��ӵ����������
* @return ������
*/
long STDCALL IAC_AddVDCamera(IN long lUserHandle,
                                                    IN unsigned long ulIntelligentHandle,
                                                    IN char **ppcCameraID,
                                                    IN long lCameraNum);

/* ��ͣ��Ƶ���
* @param [IN] lUserHandle       �û���¼���
* @param [IN] ulIntelligentHandle ��Ƶ���������
* @return ������
*/
long STDCALL IAC_PauseVDIntelligent(IN long lUserHandle,
                                                           IN unsigned long ulIntelligentHandle);

/* �ָ���ͣ����Ƶ��ϣ�ֻ����ͣ������Ч
* @param [IN] lUserHandle       �û���¼���
* @param [IN] ulIntelligentHandle ��Ƶ���������
* @return ������
*/
long STDCALL IAC_ResumeVDIntelligent(IN long lUserHandle,
                                                              IN unsigned long ulIntelligentHandle);

/* �ָ���ͣ����Ƶ��ϣ�ֻ����ͣ������Ч
* @param [IN] lUserHandle       �û���¼���
* @param [IN] ulIntelligentHandle ��Ƶ���������
* @return ������
*/
long STDCALL IAC_RestartVDIntelligent(IN long lUserHandle,
                                                             IN unsigned long ulIntelligentHandle);

/* �ָ���ͣ����Ƶ��ϣ�ֻ����ͣ������Ч
* @param [IN] lUserHandle       �û���¼���
* @param [IN] ulIntelligentHandle ��Ƶ���������
* @param [IN] ulRestartTimes      �ڼ��ν���������ϲ���
* @return ������
*/
long STDCALL IAC_RestartVDIntelligentV2(IN long lUserHandle,
                                     IN unsigned long ulIntelligentHandle,
                                     IN unsigned long ulRestartTimes);

/**
* ����ָ��¼���������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������
* @param [IN] pstIaVodIntelligentTaskInfo   ¼��ط���չ����
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·ʵ�����ܷ����Ƿ�ɹ�
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
* ����ָ�����¼���������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentID  ���ܷ�������
* @param [IN] stIaIntelligentCfg �������ù���
* @param [IN] pstIaVodIntelligentTaskInfoOUT  �ط���չ��������
* @param [OUT] pulIntelligentHandle ����ҵ����
* @return ����һ·�����ļ����ܷ����Ƿ�ɹ�
*/
long STDCALL IAC_Create9linFileIntelligent(IN long lUserHandle,
                                           IN const char *pcIntelligentID,
                                           IN const char *pIntelligentName,
                                           IN const char *pcCameraID,//�ļ�������Я��·�� ������
                                           IN const char *pcCfgData,
                                           IN IA_INTELLIGENT_CONFIG_S *pstIaIntelligentCfg,
                                           IN IA_VOD_INTELLIGENT_TASK_INFO_S *pstIaVodIntelligentTaskInfo,
                                           OUT unsigned long *pulIntelligentHandle);

/**
* ����ָ��¼���������ù���
* @param [IN] lUserHandle  �û���¼���
* @param [IN] pcCameraID   �����ID��
* @param [IN] pcIntelligentName             ����ҵ������
* @param [IN] pstIaVodIntelligentTaskInfo   ¼��ط���չ����
* @param [IN] stIaIntelligentCfg            �������ù���
* @param [OUT] pulIntelligentHandle         ����ҵ����
* @return ����һ·����ʵ�����ܷ����Ƿ�ɹ�
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
