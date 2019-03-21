/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
            xp_func_inner.h

Project Code: IMOS XP������
Module Name: IMOS XP������
Date Created: 2010-04-14
Author: shiyouhua/04562
Description: ������XP�ڲ��ӿں���ͷ�ļ�

--------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_MEDIA_PLAYER_SDK_INNER_FUNC_H_
#define _IMOS_XP_MEDIA_PLAYER_SDK_INNER_FUNC_H_

/* ��������ƽ̨��ͷ�ļ�*/
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"
/* ����������SDK���ݽṹͷ�ļ� */
#include "xp_datatype.h"
#include "xp_func.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* ��ʼ����������Դ��\n
* @param [IN] pcBaseModuleCode ����ƽ̨BPģ��ı��롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM    ��������Ƿ�
* -         #ERR_XP_FAIL_TO_REG_BP_CMD   ע�����ƽ̨BP��������ģ��IDʧ��
* -         #ERR_XP_FAIL_TO_INIT_XP      ��ʼ��������XP��Դʧ��
* @note
* - ʹ�ò����������������Ҫ���õĺ�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_InitXP(IN const CHAR *pcBaseModuleCode);

/**
* �ͷŲ�������Դ��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* @note �˳���������������һ����Ҫ���ú�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CleanupXP();

/**
* ע�Ქ������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pstXPInfo          ��������Ϣ�ṹ�塣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_FAIL_TO_REGIST_XP        ע�Ქ����XPʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RegisterXP(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const XP_INFO_S *pstXPInfo);

/**
* ע����������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnregisterXP(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo);

/**
* ��Ӳ��Ŵ�����Դ���룬һ�ο���Ӷ�����Ŵ�����Դ���롣\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pstWndCode         ���Ŵ������ṹ��ָ�롣
* @param [IN] ulPlayWndNum       ���Ŵ���������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_EXCEED_MAX_PLAY_PORT_NUM ע��Ĳ���ͨ�����ѳ��������֧�ֵĲ���ͨ����
* -         #ERR_XP_FAIL_TO_SET_PARAM        ���ò�����XP�����ò���ʧ��
* @note һ�����Ŵ�����Դ�����Ӧһ������ͨ��������ͬһ���û���½ID��ͬʱ���֧�ֵĲ���ͨ����Ϊ128��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddPlayWndInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const PLAY_WND_INFO_S *pstWndCode,
                                              IN ULONG_32 ulPlayWndNum);

/**
* ɾ�����Ŵ�����Դ���룬һ�ο�ɾ��������Ŵ�����Դ���롣\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pstWndCode         ���Ŵ������ṹ��ָ�롣
* @param [IN] ulPlayWndNum       ���Ŵ���������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DeletePlayWndInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const PLAY_WND_INFO_S *pstWndCode,
                                                 IN ULONG_32 ulPlayWndNum);

/**
* �������ͨ����Դ���롣\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ��
* @param [IN] ulDownloadResCodeNum      ����ͨ����
* @param [IN] pstDownloadResCodeList    ����ͨ����Դ��������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* @note
1��SDK�û��ڵ���IMOS_StartPlayer֮����øýӿڡ�
2��ulDownloadResCodeNumȡֵС�ڵ���32
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDownloadResCode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const ULONG_32 ulDownloadResCodeNum,
                                                  INOUT PORD_RES_CODE_INFO_S *pstDownloadResCodeList);

/**
* ��֡���˲��š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ִ˲���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_STEP_PLAY            ��֡���˲���ʧ��
* @note ���ڱ���¼��ʱ����֧�ֵ�֡���˲��Ų�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OneByOneBack(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode);

/**
* ��֡���˲��š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ִ˲���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_STEP_PLAY            ��֡���˲���ʧ��
* @note ���ڱ���¼��ʱ����֧�ֵ�֡���˲��Ų�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AutoOneByOneBack(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
											   IN const CHAR *pcChannelCode);											
											
											
											
/**
* ����ý����������ʽ��\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulMediaDataformat  ý����������ʽ�����#XP_MEDIA_DATA_FORMAT_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_NOT_SUPPORT_MEDIA_STREAM_TYPE    ��֧�ֵ���������
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaDataFormat(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulMediaDataformat);

/**
* ����ָ��ͨ���ļ�ʱ�طš�\n
* @param [IN] pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode            ����ͨ�����롣
* @param [IN] pcReplayChannelCode      ���Żط���Ƶ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý��ҵ�����Ͳ�֧�ִ˲���
* -         #ERR_XP_NOT_START_PLAY               ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ�����Դʧ��
* -         #ERR_XP_FAIL_TO_START_REALREPLAY     ��ʼ��ʱ�ط�ʧ��
* @note     pcReplayChannelCode ����Դ����ӦΪ��Ч��ͨ������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartRealReplay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcReplayChannelCode);

/**
* ����ָ��ͨ���ļ�ʱ�ط�ʱ����\n
* @param [IN] pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode            ����ͨ�����롣
* @param [IN] ulTime                   ��ʱ�ط�ʱ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý��ҵ�����Ͳ�֧�ִ˲���
* -         #ERR_XP_NOT_START_PLAY               ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ�����Դʧ��
* -         #ERR_XP_SET_REALREPLAY_TIME_LARGE    ��ʱ�ط�����ʱ��̫��
* @note     ʱ��ȡֵ��Χ[0 - 60]s
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRealReplayTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN ULONG_32 ulTime);

/**
* ��������ý�����Ķ˿ڷ�Χ��\n
* @param [IN] usMinPort            ��ʼ�˿ڡ�
* @param [IN] usMaxPort            �����˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* @note
* -    1����Χ�������õĶ˿ڡ�
* -    2���ڵ��� IMOS_InitXP֮ǰ���á�
* -    3����ξ�Ϊ��ʱ�򲻵���ʱ������Ĭ��ֵ��
* -    4��Ĭ��ֵ��ΧΪ32768��65535֮���ż����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaPortRange(IN USHORT usMinPort,
                                                 IN USHORT usMaxPort);

/**
* ��������Ķ˿ڷ�Χ��\n
* @param [IN] usMinPort         ��ʼ�˿ڡ�
* @param [IN] usMaxPort         �����˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* @note
* -    1����Χ�������õĶ˿ڡ�
* -    2���ڵ��� IMOS_InitXP֮ǰ���á�
* -    3����ξ�Ϊ��ʱ�򲻵���ʱ������Ĭ��ֵ��
* -    4��Ĭ��ֵ��ΧΪ6001��10000��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetProtlPortRange(IN USHORT usMinPort,
                                                 IN USHORT usMaxPort);
/**
* ��������ý�������ݣ������յ���ý�������ݻص����û���\n
* @param [IN]  pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl                ������ý������Դ��URL��
* @param [IN]  pcServerIP               ý�����ط�������IP��
* @param [IN]  usServerPort             ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl                  ����ý������Э�����ͣ����tagProtocolö����ȡֵ��������Ŀǰ��֧��TCPЭ�飩��
* @param [IN]  ulDownMediaSpeed         ý�����������ٶȣ����tagDownMediaSpeedö����ȡֵ��
* @param [IN]  pfnSourceMediaDataCBFun  ����ý�������ݻص�������ָ�롣
* @param [IN]  lUserParam               �û����ò�����
* @param [OUT] pcDownloadID             ����ͨ���ţ�����������Ӧ��С��#IMOS_RES_CODE_LEN��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      ��������ͨ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲��ţ����أ�ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ����ý�崦��ʧ��
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       ��������ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note
* -         1���ú������óɹ��󣬷��ظ��û�����ͨ���ţ����ڱ�ʶһ·����ͨ����
* -         2�����ͬʱ֧������32·����ͨ����
* -         3��Ŀǰ��֧��TCPЭ������ý������
* -         4��ֹͣý�������ر��������#IMOS_StopDownMediaStreamCallback�ӿڡ�
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
* ֹͣ����ý�������ݡ�\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownloadID        ����ͨ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note �ýӿ���#IMOS_StartDownMediaStreamCallback�ӿ�ƥ�䡣
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownMediaStreamCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                           IN const CHAR *pcDownloadID);

/**
* ��ý�������أ�֧��TS��������ý�������أ������ص�ý��������Ϊָ���ĸ�ʽ������¼���ļ���ȫ�����û�ָ����\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode       ����ͨ����Դ���롣
* @param [IN]  pcDownUrl           Ҫ����¼���ļ���URL��
* @param [IN]  pcServerIP          ý�����ط�������IP��
* @param [IN]  usServerPort        ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl             ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��Ŀǰ��֧��TCPЭ�飩��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      ��������ͨ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_DOWNLOAD        ��������ҵ��ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note
* -    1�����ͬʱ֧������32·����ͨ����
* -    2��Ŀǰ��֧��TCPЭ������ý������
* -    3����ý�������غ������IMOS_StartDownloadEx�ӿڿ�ʼ���أ�ֹͣ����ʱ����IMOS_StopDownload�ӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadEx2(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcDownUrl,
                                               IN const CHAR *pcServerIP,
                                               IN USHORT usServerPort,
                                               IN ULONG_32 ulProtl);


/**
* ��ý�������أ�֧��TS��������ý�������أ������ص�ý��������Ϊָ���ĸ�ʽ������¼���ļ���ȫ�����û�ָ����\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl           Ҫ����¼���ļ���URL��
* @param [IN]  pcServerIP          ý�����ط�������IP��
* @param [IN]  usServerPort        ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl             ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��Ŀǰ��֧��TCPЭ�飩��
* @param [IN]  ulDownMediaSpeed    ý�����������ٶȣ����#XP_DOWN_MEDIA_SPEED_Eö����ȡֵ��
* @param [OUT]  pcChannelCode      ����ͨ����Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      ��������ͨ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_DOWNLOAD        ��������ҵ��ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note
* -    1�����ͬʱ֧������32·����ͨ����
* -    2��Ŀǰ��֧��TCPЭ������ý������
* -    3����ý�������غ������IMOS_StartDownloadEx�ӿڿ�ʼ���أ�ֹͣ����ʱ����IMOS_StopDownload�ӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadEx3(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcDownUrl,
                                                  IN const CHAR *pcServerIP,
                                                  IN USHORT usServerPort,
                                                  IN ULONG_32 ulProtl,
                                                  IN ULONG_32 ulDownMediaSpeed,
                                                  OUT CHAR *pcChannelCode);

/**
* ��ͣ���ء�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          ��ͣý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       ����Э����ͣʧ��
* -         #ERR_XP_FAIL_TO_PAUSE                ��ͣ���Ų���ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PauseDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode);

/**
* �ָ����ء�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲���ʧ��
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         �ָ�ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_RESUME               �ָ����Ų���ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResumeDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode);



/**
* ��ʼ���ţ���չ�ӿڣ�����ָ����ʼ����ʱ��Ͳ������ʲ�������
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcTime             �����ļ�����λ�õ�ָ��ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @param [IN] ulPlaySpeed        �������ʣ����tagPlayStatusö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_OPEN                ָ���Ĳ���ͨ��δ����ý��ҵ��
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲���ʧ��
* -         #ERR_XP_FAIL_TO_START_PLAY           ��ʼ����ʧ��
* @note
* 1���ýӿ����û����õ�¼��ʱ�������ָ�����ٲ��ŵ㲥�طţ����ڹ��������ʱ�طź�ͼƬOSD�ҵ����⡣
* 2��SDK�û��ڵ���#IMOS_OpenVodStream֮����øýӿڣ����#IMOS_StartPlay��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlayEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           IN const char *pcTime,
                                           IN ULONG_32 ulPlaySpeed);


/**
* ����ָ��ͨ�������ַŴ��ܡ�\n
* @param [IN] pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode            ����ͨ�����롣
* @param [IN] hWnd                     ���л����,hWnd = #IMOS_INVALID_HANDLE��ʾ�رգ���#IMOS_INVALID_HANDLE��ʾ����
* @param [IN] pstRect                  ԭʼͼ���������꣬pstRect = NULLΪȫ����ʾ��������ֵΪ������ͼ���еİٷֱ�ֵ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT                  ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_DIGITALZOOM      ���õ��ӷŴ�ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDigitalZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN IMOS_HANDLE hWnd,
                                              IN XP_RECT_S *pstRect);

/**
* ��ȡͼ���С��\n
* @param [IN] pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode            ����ͨ�����롣
* @param [OUT] pulWidth                ͼ��Ŀ�
* @param [OUT] pulHeight               ͼ��ĳ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_GET_PIC_PARAM        ��õ�ǰͨ�������ͼƬ������Ϣʧ��
* -         #ERR_COMMON_INVALID_PARAM            ��������
* @note
* - 1���ýӿں�����֧��Windows��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPicSize(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          OUT ULONG_32 *pulWidth,
                                          OUT ULONG_32 *pulHeight);

/**
* ����UDP�����������ܡ�\n
* @param [IN] bAdjust                  �Ƿ�������������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_SET_PARAM            ���ò����������ò���ʧ��
* @note
* -  1����ǰֻ֧��UDP+TS�е���Ƶ��������
* -  2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustPktSeq(IN BOOL_T bAdjust);


/**
* ��ָ��ͨ����ͼ������������
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode            ����ͨ������
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] ulNum                    ���������򶥵���������Ϊ6
* @param [IN] pointArry                �����ַ
* @param [IN] ulDir                    �������#IMOS_AREA_DIRECTION_Eö����ȡֵ��
* @param [IN] ulColor                  ������ɫ
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT VOID STDCALL IMOS_PolylineTo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN IMOS_HANDLE pDrawHandle,
                                         IN ULONG_32 ulNum,
                                         IN XP_POINT_S *pointArry,
                                         IN ULONG_32 ulDir,
                                         IN ULONG_32 ulColor);

/**
* ��ָ��ͨ����ͼ������������
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode            ����ͨ������
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] ulNum                    ���������򶥵���������Ϊ6
* @param [IN] pointArry                �����ַ
* @param [IN] ulWidth                  �������
* @param [IN] ulColor                  ������ɫ
* @return ��
*/
IMOS_EXPORT VOID STDCALL IMOS_PolylineToWindow(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN IMOS_HANDLE pDrawHandle,
                                         IN ULONG_32 ulNum,
                                         IN XP_POINT_S *pointArry,
                                         IN ULONG_32 ulWidth,
                                         IN ULONG_32 ulColor);


/**
* ��ָ��ͨ����ͼ����Ӱ�ߣ�
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] pstStart                 ֱ�����
* @param [IN] pstEnd                   ֱ���յ�
* @param [IN] ulDir                    ��������,���#IMOS_THRU_LINE_DIRECTION_Eö����ȡֵ��
* @param [IN] ulColor                  ������ɫ
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT VOID STDCALL IMOS_DLineTo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                      IN const CHAR *pcChannelCode,
                                      IN IMOS_HANDLE pDrawHandle,
                                      IN const XP_POINT_S *pstStart,
                                      IN const XP_POINT_S *pstEnd,
                                      IN ULONG_32 ulDir,
                                      IN ULONG_32 ulColor);
/**
* ��ָ��ͨ����ͼ����Ӱ�ߣ�
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] pstStart                 ֱ�����
* @param [IN] pstEnd                   ֱ���յ�
* @param [IN] ulDir                    ��������,���#IMOS_THRU_LINE_DIRECTION_Eö����ȡֵ��
* @param [IN] ulColor                  ������ɫ
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��#IMOS_DLineToָ�굥λΪ1%, #IMOS_DLineToEx���굥λΪ0.01%
*/
IMOS_EXPORT VOID STDCALL IMOS_DLineToEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN IMOS_HANDLE pDrawHandle,
                                        IN const XP_POINT_S *pstStart,
                                        IN const XP_POINT_S *pstEnd,
                                        IN ULONG_32 ulDir,
                                        IN ULONG_32 ulColor);
/**
* ��ָ��ͨ����ͼ����ͷ�ߣ�
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] pstStart                 ֱ�����
* @param [IN] pstEnd                   ֱ���յ�
* @param [IN] ulDir                    ��������,���#IMOS_THRU_LINE_DIRECTION_Eö����ȡֵ��
* @param [IN] ulColor                  ������ɫ
* @return ��
* @note
* - 1���ýӿں�����֧��Windows�����굥λΪ0.01%
*/
IMOS_EXPORT VOID STDCALL IMOS_DrawLineWithArrow(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
												IN const CHAR *pcChannelCode,
												IN IMOS_HANDLE pDrawHandle,
												IN const XP_POINTEX_S *pstStart,
												IN const XP_POINTEX_S *pstEnd,
												IN ULONG_32 ulDir,
												IN ULONG_32 ulColor);

/**
* ��ȡ��ͼ���
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @return �������½����
* - �ɹ���IMOS_HANDLE
* - #
* - ʧ�ܣ�IMOS_INVALID_HANDLE
* -
* @note
* - 1����Ҫ����Ƶ����ͼ��������Ҫ����#IMOS_GetHVDC��ȡHVDC���ſ�����ͼ����ʾ������#IMOS_ReleaseHVDCȡ����ͼ������ʾ
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT IMOS_HANDLE STDCALL IMOS_GetHVDC(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode);

/**
* �ͷŻ�ͼ���
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] pDrawHandle              ͨ��IMOS_GetHVDC��ȡ�ľ��
* @return �������½����
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT VOID STDCALL IMOS_ReleaseHVDC(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          IN IMOS_HANDLE pDrawHandle);
/**
* ��ʼ��ͼ
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ�����롣
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] pverBer                  ��������
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER           ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_BEGINHVDC           ��ʼ��ͼʧ��
* @note
* - 1��ͼ���ϻ��ߣ�������Ҫ��#IMOS_BeginDraw��#IMOS_EndDraw֮�����������������Ч
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BeginDraw(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN IMOS_HANDLE pDrawHandle,
                                         IN VOID *pverBer);

/**
* �����ͼ
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] pDrawHandle              ��ͼ���
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT VOID STDCALL IMOS_EndDraw(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                      IN const CHAR *pcChannelCode,
                                      IN IMOS_HANDLE pDrawHandle);

/**
* ���ý�������ܹ�����ʾʹ��
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] ulMethod                 ����������Ϣ���ӷ�����Ϣ
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER           ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERULE   ������ʾ���ܹ���ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShowAnalyseRule(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const BOOL_T bEnable );

/**
* ���ý�������ܽ����ʾʹ��
* @param [IN] pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN] pstChannelIndex          ����ͨ������
* @param [IN] ulMethod                 ����������Ϣ���ӷ�����Ϣ
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER           ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERESULT ������ʾ���ܽ��ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ShowAnalyseResult(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const BOOL_T bEnable );
/**
* �������ϵͳ��Ӳ������
* @param [IN] �ޡ�
* @return ����#XP_HW_STATUS_Eö�����͵Ĳ���
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CheckHWValidate();

/**
* ����ͼ��ƴ�Ӳ�����\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ����ͼ��ƴ����Ƶ��ͨ������
* @param [IN] pcCombineResCode          ͼ��ƴ����Դ����
* @param [IN] lCombineStreamNum         ͼ��ƴ�ӵ�ͨ����Ŀ
* @param [IN] ppcNeedCombineChannelCode ͼ��ƴ�ӵ�ͨ����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      ����ͼ��ƴ�ӳɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_START_COMBINE_IMAGE      ����ͼ��ƴ�Ӳ���ʧ��
* @note
* - 1����ǰֻ֧��3��ͨ������Դƴ��
* - 2��ƴ��ǰ��ҪԤ�ȴ���Ҫƴ�ӵ���Ƶ����ҵ��
* - 3��ppcNeedCombineChannelCodeΪ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCombineVideo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const CHAR *pcCombineResCode,
                                                 IN const LONG_32 lCombineStreamNum,
                                                 IN const CHAR **ppcNeedCombineChannelCode);

/**
* ֹͣͼ��ƴ�Ӳ�����\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ͼ��ƴ����Դ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_IMAGE   ֹͣͼ��ƴ�Ӳ���ʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCombineVideo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode);

/**
* �궨ͼ��ƴ�������㡣\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcCombineResCode          ͼ��ƴ����Դ����
* @param [IN] lCombineStreamNum         ͼ��ƴ����Դͨ����Ŀ
* @param [IN] plCombinPointNum          ����ͼ����������Ŀ������
* @param [IN] plCombinPointVal          �û�����ƴ��ͼ��������ֵ����
* @param [IN] lReserve                  ����ֵ��������ƴ��ģʽʹ�ã���ǰ��д0
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_MARK_COMBINE_IMAGE   �궨������ʧ��
* @note
* - ��ʶΪ�����ֵ��Ҫ�������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MarkCombinePoint(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcCombineResCode,
                                                IN LONG_32 lCombineStreamNum,
                                                IN LONG_32 *plCombinPointNum,
                                                IN LONG_32 *plCombinPointVal,
                                                IN LONG lReserve);

/**
* ������Ƶͼ����ӷŴ��ܡ�\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ���ŵ��ӷŴ���Ƶ��ͨ������
* @param [IN] pcCombineResCode          ͼ��ƴ����Դ����
* @param [IN] pstCombineZoomRect        ���ӷŴ�������Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_START_COMBINE_ZOOM   �������ӷŴ�ʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartCombineZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                IN const CHAR *pcCombineResCode,
                                                IN const XP_COMBINE_ZOOM_RECT_S *pstCombineZoomRect);

/**
* �޸ĵ��ӷŴ�������Ϣ��\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ���ŵ��ӷŴ���Ƶ��ͨ������
* @param [IN] pcCombineResCode          ͼ��ƴ����Դ����
* @param [IN] pstCombineZoomRect        ���ӷŴ�������Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_MOVE_COMBINE_ZOOM    �޸ĵ��ӷŴ�������Ϣʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MoveCombineZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcCombineResCode,
                                               IN const XP_COMBINE_ZOOM_RECT_S *pstCombineZoomRect);

/**
* �ر���Ƶͼ����ӷŴ��� \n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ���ŵ��ӷŴ���Ƶ��ͨ������
* @param [IN] pcCombineResCode          ͼ��ƴ����Դ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_ZOOM    �رյ��ӷŴ���ʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopCombineZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcCombineResCode);




/**
* �ж��Ƿ�ΪDB33�����׼���롣\n
* @param [IN] pcDecodetag    decodetag��Ϣ
* @return #BOOL_TRUE����DB33��������׼���룻 #BOOL_FALSE����DB33��������׼����
* @note ��
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_IsDB33Decodetag(IN const CHAR *pcDecodetag);


/**
* ���ý���ģʽ \n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ���ŵ�ͨ������
* @param [IN] ulMode                    ����ģʽ 0 �������ģʽ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* @note
* - 1���ýӿں�����֧��Windows��
* - 2���ýӿ�Ϊʵ���Խӿڣ��ᵼ�³����ȶ����½������Ƽ��û�ʹ�á�
* - 3���ú������سɹ�ʧ��
* - 4���ýӿڿ��Ժ�IMOS_XP_SetTransParam���ʹ��
* - 5�����GPU ֧�֣���ôĬ�����yuvΪ cif ��2cif ��d1 ����ԭʼ��С�������ɲ��Ŵ����С����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoDecodeMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN ULONG_32 ulMode);

/**
* Ӱ�����\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ����ͨ������
* @param [IN] pstAdjust                 Ӱ����ڲ���
* @param [IN] bOpen                     �Ƿ��Ӱ�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER           ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_VIDEO_ADJUST    ����Ӱ�����ʧ��
* @note
* -    1��Ĭ�ϲ�����Ӱ����ڡ�
* -    2���Աȶ�ȡֵ��ΧΪ[0--199]��Ĭ��ֵΪ100��
* -       ����ȡֵ��ΧΪ[0--199]��Ĭ��ֵΪ100��
* -       ɫ��ȡֵ��ΧΪ[0--359]��Ĭ��ֵΪ0��
* -       ���Ͷ�ȡֵ��ΧΪ[0--359]��Ĭ��ֵΪ100��
* -       ٤��ȡֵ��ΧΪ[0--99]��Ĭ��ֵΪ10��
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN const XP_VIDEO_ADJUST_S *pstAdjust,
                                              IN BOOL_T bOpen);

/**
* ģ������\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ����ͨ������
* @param [IN] ulFactor                  ģ���������
* @param [IN] bOpen                     �Ƿ�����ģ������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_VIDEO_MONITOR_BLUR  ����ģ������ʧ��
* @note
* -    1��Ĭ�ϲ�����ģ������
* -    2��ģ���������ȡֵ��ΧΪ[1--127]��Ĭ��ֵΪ80��
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoMotionBlur(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulFactor,
                                                  IN BOOL_T bOpen);

/**
* �񻯴���\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ����ͨ������
* @param [IN] fSigma                    �񻯴������
* @param [IN] bOpen                     �Ƿ������񻯴���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_VIDEO_SHARPEN       �����񻯴���ʧ��
* @note
* -    1��Ĭ�ϲ������񻯴���
* -    2���񻯴������ȡֵ��ΧΪ[0.0--2.0]��Ĭ��ֵΪ0.05��
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVideoSharpen(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN FLOAT fSigma,
                                               IN BOOL_T bOpen);

/**
* ȥ����\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ����ͨ������
* @param [IN] ulLowValue                �������ڲ���
* @param [IN] ulHighValue               �������ڲ���
* @param [IN] bOpen                     �Ƿ�����ȥ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_DE_FOG              ����ȥ����ʧ��
* @note
* -    1��Ĭ�ϲ�����ȥ����
* -    2��ȥ�������1ȡֵ��ΧΪ[0--49]��Ĭ��ֵΪ0��
* -       ȥ�������2ȡֵ��ΧΪ[51--100]��Ĭ��ֵΪ100��
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDeFog(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN ULONG_32 ulLowValue,
                                        IN ULONG_32 ulHighValue,
                                        IN BOOL_T bOpen);

/**
* �����������������ƴ֡���ԡ�\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] ulDataLostSplitterPolicy �������������ƴ֡���ԣ����#XP_MEDIA_DATA_LOST_SPLITTER_POLICYö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* @note
* - 1���������������Ĭ�ϲ�����ƴ֡
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaDataLostSplitterPolicy(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN ULONG_32 ulDataLostDecodePolicy);

/**
* ����˸����\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN] pcChannelCode             ����ͨ������
* @param [IN] ulWinSize                 �ο�֡��
* @param [IN] ulSoftenVal               ֡���˲�����
* @param [IN] bOpen                     �Ƿ���������˸������
* @return �������´����룺
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_ANTI_FLICKER        ���÷���˸����ʧ��
* @note
* -    1��Ĭ�ϲ�����ȥ����
* -    2��ulWinSizeȡֵ��ΧΪ[0--100]��
* -       ulSoftenValȡֵ��ΧΪ[0--30]��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetAntiFlicker(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN ULONG_32 ulWinSize,
                                              IN ULONG_32 ulSoftenVal,
                                              IN BOOL_T bOpen);

/**
* ����ͼ��ĶԱȶȲ�����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulContrastMode     ͼ��Աȶ�ģʽ�����#XP_PICTURE_CONTRAST_MODE_Eö����ȡֵ��
* @param [IN] ulContrastLevelEx  ͼ��Աȶȼ������#XP_PICTURE_CONTRAST_LEVEL_EX_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER        ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST ����ͨ����֧������ͼ��ԱȶȲ���
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     ����ͼ��ԱȶȲ���ʧ��
* @note
* -    1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ�ϲ����жԱȶȵ��ڴ���
* -    2�������ڿ�ʼ����#IMOS_StartPlay֮ǰ���ã������õĶԱȶȲ��������棬��Ϊ������ͨ������ʱ
* -       �ĳ�ʼֵ���ڿ�ʼ���ź���øýӿ����õĶԱȶȲ�����ʱ�����á�
* -    3�����øýӿڶ�ָ������ͨ�����õĶԱȲ����ڲ����������ڼ�һֱ��Ч��������ulContrastMode
* -       ����#XP_PICTURE_CONTRAST_MODE_NONEʱ����ֹͣ�Աȶȵ��ڴ�����ʱulContrastLevel�����
* -       ֵ��Ч��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPictureContrastEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN ULONG_32 ulContrastMode,
                                                    IN ULONG_32 ulContrastLevelEx);

/**
* ����ָ��ץ����Ŀ������ʵʱץ�ġ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         ͼ���ļ���ŵ�·���������ļ�����������չ������
* @param [IN] ulPicFormat        ͼ���ļ��ĸ�ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @param [IN] ulInterval         ץ�ļ������λΪ���� ; 0xFFFFFFFF ��ʾץ��ÿ��I֡
* @param [IN] ulCount            ץ����Ŀ��ȡֵ����0����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_ALREADY_START_SERIES_SNATCH  ����ͨ���Ѿ�����������ץ�ĵĲ���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_START_SERIES_SNATCH  ��������ץ�Ĳ���ʧ��
* @note
* - 1�������������ļ������渽�ӡ�ץ��ϵͳʱ��-ϵͳ���뼶ʱ�䡱��ʽ��ʱ����ַ������硰20110228110325-1997060991����
* - 2����λʱ���ڳɹ�ץ�ĵ����ͼƬ���ͻ��������йأ�
* - 3���������������յ�ͼ���ļ����󸽼��Ϻ�׺����
* - 4����������ץ�ĺ���ץ�Ĺ����У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ�ץ����Ϣ#XP_RUN_INFO_SERIES_SNATCH��Я���Ĵ����룺
* -     #ERR_XP_DISK_CAPACITY_WARN          �������ڼ���ץ��
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH    �ϱ���Ϣ֮ǰ��������ֹͣץ��
* -     #ERR_XP_NO_PICTURE_TO_SNATCH        �ϱ���Ϣ֮ǰ��������ֹͣץ��
* -     #ERR_XP_FAIL_TO_SERIES_SNATCH       �ϱ���Ϣ֮ǰ��������ֹͣץ��
* -     #ERR_XP_FINISH_SERIES_SNATCH        �ϱ���Ϣ֮ǰ��������ֹͣץ��
* - 5���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartSnatchSeriesEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN const CHAR *pcFileName,
                                                   IN ULONG_32 ulPicFormat,
                                                   IN ULONG_32 ulInterval,
                                                   IN ULONG_32 ulCount);

/**
* ����һ���ļ��ж��¼��ϲ���һ��ts�ļ���\n
* @param [IN] pacFileName �����ļ��׵�ַ��
* @param [IN] ulBeginTime   ��ʼƴ�ӵ�ʱ��(ms)��
* @param [IN] ulEndTime   ����ƴ�ӵ�ʱ��(ms)��
* @param [IN] ulJointCount ƴ�ӿ�ĸ�����
* @param [IN] pcJointFileName   ����ļ�����
* @param [OUT] pulJointErrNumber   �����ʱ��ε���ţ���0��ʼ��
* @param [OUT] pstFileJointInfo     ƴ���ļ���Ϣ��
* @return �������´����룺
*          ERR_COMMON_SUCCEED           �ļ��ϲ��ɹ�
*          ERR_COMMON_INVALID_PARAM     ��������
*          ERR_COMMON_NO_MEMORY         ϵͳû���㹻���ڴ�
*          ERR_XP_FILE_HAVE_OPEN        �ļ��Ѿ��򿪡�
*          ERR_XP_FILE_DESTROY          TSý���ļ��Ѿ���
*          ERR_XP_FAIL_TO_JOIN_FILE     �ļ��ϲ�����

* @note
* -    1��ֻ֧��TS�ļ��ĺϲ�������
* -    2������Ϊ����ʽ�����ںϲ����֮��Ż᷵�ء�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMultiSectionJoint(IN const CHAR *pcFileName,
                                                      IN ULONG_32 aulBeginTime[],
                                                      IN ULONG_32 aulEndTime[],
                                                      IN ULONG_32 ulJointCount,
                                                      IN CHAR *pcJointFileName,
                                                      OUT ULONG_32 *pulJointErrNumber,
                                                      OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* �������ts�ļ��ϲ���һ��ts�ļ���\n
* @param [IN] pacFileName �����ļ������׵�ַ��
* @param [IN] ulFileNum   �����ļ�������
* @param [IN] pcJointFileName   ����ļ�����
* @param [OUT] pulJointErrNumber   ������ļ�����ţ���0��ʼ��
* @param [OUT] pstFileJointInfo     ƴ���ļ���Ϣ��
* @return �������´����룺
*          ERR_COMMON_SUCCEED           �ļ��ϲ��ɹ�
*          ERR_COMMON_INVALID_PARAM     ��������
*          ERR_COMMON_NO_MEMORY         ϵͳû���㹻���ڴ�
*          ERR_XP_FILE_HAVE_OPEN        �ļ��Ѿ��򿪡�
*          ERR_XP_FILE_DESTROY          TSý���ļ��Ѿ���
*          ERR_XP_FAIL_TO_JOIN_FILE     �ļ��ϲ�����
* @note
* -    1��ֻ֧��TS�ļ��ĺϲ�������
* -    2������Ϊ����ʽ�����ںϲ����֮��Ż᷵�ء�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartMultiFileJoint(IN CHAR *pacFileName[],
                                                   IN ULONG_32 ulFileNum,
                                                   IN CHAR *pcJointFileName,
                                                   OUT ULONG_32 *pulJointErrNumber,
                                                   OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* ����TS�����ϲ����ļ���\n
* @param [IN] pcJointFileName       ����ļ�����
* @param [OUT] pulHandle            �ϳɾ����
* @return �������´����룺
*          ERR_COMMON_SUCCEED           �ļ��ϲ��ɹ�
*          ERR_COMMON_INVALID_PARAM     ��������
*          ERR_COMMON_NO_MEMORY         û���㹻���ڴ�
*          ERR_XP_FILE_HAVE_OPEN        �ļ��Ѿ���
*          ERR_XP_FAIL_TO_JOIN_FILE     �ļ��ϲ�ʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CreateTsDataJointFile(IN const CHAR *pcJointFileName, OUT ULONG_REAL *pulHandle);

/**
* ����TS�������кϲ����ļ���\n
* @param [IN] ulHandle          �����
* @param [IN] pucDataBuf        �������ݡ�
* @param [IN] ulDataLen         �������ȡ�
* @param [IN] ulMode            �ϲ�ģʽ��XP_TSJOINT_MODE_E
* @return �������´����룺
*          ERR_COMMON_SUCCEED           �ļ��ϲ��ɹ�
*          ERR_COMMON_INVALID_PARAM     ��������
*          ERR_COMMON_NO_MEMORY         ϵͳû���㹻���ڴ�
*          ERR_XP_FAIL_TO_JOIN_FILE     �ļ��ϲ�����
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_JointTsDataToFile(IN ULONG ulHandle, IN UCHAR *pucDataBuf, IN ULONG_32 ulDataLen,IN ULONG_32 ulMode);

/**
* �ر�TS�����ϲ����ļ���\n
* @param [IN] ulHandle              �����
* @param [OUT] pstFileJointInfo     ƴ���ļ���Ϣ��
* @return �������´����룺
*          ERR_COMMON_SUCCEED           �ļ��ϲ��ɹ�
*          ERR_COMMON_INVALID_PARAM     ��������
*          ERR_XP_FAIL_TO_JOIN_FILE     �ļ��ϲ�����
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_CloseTsDataJointFile(IN ULONG ulHandle, OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* ����ת����ý�������ݻص�������\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [IN] pfnTranscodeMediaDataCBFun ת����ý�������ݻص�������ָ�롣
* @param [IN] pstParam                �������
* @param [IN] bContinue               �Ƿ�������к����ƴ֡���������ʾ������
* @param [IN] lUserParam              �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note
* - 1��ʵʱ����ʱ���ú�����#IMOS_StartMonitor֮ǰ����֮����ã���#IMOS_StopMonitorʱ�Զ�ʧЧ���´ε���
*      #IMOS_StartMonitor֮ǰ����֮����Ҫ�������ã��㲥�ط�ʱ���ú�������#IMOS_OpenVodStream֮ǰ���ã�Ҳ��
*      ��#IMOS_OpenVodStream��#IMOS_StartPlay֮����ã���������#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ��
*      ��ʧЧ���´������㲥�ط�ʱ��Ҫ����ͬλ���������ã����ػط�ʱ���ú�������#IMOS_OpenFile֮ǰ���ã�
*      Ҳ����#IMOS_OpenFile��#IMOS_StartPlay֮����ã���������#IMOS_StartPlay֮����á�
* - 2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��#XP_TRANSCODE_MEDIA_DATA_CALLBACK_PF��ΪNULL��
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTranscodeMediaDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode,
                                                       IN XP_TRANSCODE_MEDIA_DATA_CALLBACK_PF pfnTranscodeMediaDataCBFun,
                                                       IN const XP_ENCODE_PARAM_S *pstParam,
                                                       IN BOOL_T bContinue,
                                                       IN LONG_REAL lUserParam);


/**
* ��������ʵʱץ�ģ������������û�ָ���ĵ��ļ����󸽼�ץ��ϵͳʱ�䡣\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         Ҫ�����ͼ���ļ����ļ�����������չ�������ļ���ȫ�����û�ָ����
* @param [IN] ulPicFormat        ͼ���ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @param [IN] pstRect            ָ������ץ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         û�н������ͼƬ�ɹ�ץ��
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          ����ץ�Ĳ���ʧ��
* @note
* -   1. �����������û�ָ�����ļ������渽��������"20080928(13-10-50-99)"��ʽ��ץ��ϵͳʱ�䡣
* -   2. pstRectΪNULLʱ��ָ��ץ������ͼ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchRegion(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN const CHAR *pcFileName,
                                            IN ULONG_32 ulPicFormat,
                                            IN const XP_RECT_S *pstRect);

/**
* ��������ʵʱץ�ģ��ļ���ȫ�����û�ָ����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         Ҫ�����ͼ���ļ����ļ�����������չ�������ļ���ȫ�����û�ָ����
* @param [IN] ulPicFormat        ͼ���ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @param [IN] pstRect            ָ������ץ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         û�н������ͼƬ�ɹ�ץ��
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          ����ץ�Ĳ���ʧ��
* @note
* -   1. �ļ���ȫ�����û�ָ�����û���ȷ����ͬһץ�ı���·���£�ץ��ͼ���ļ�������������
* -   2. pstRectΪNULLʱ��ָ��ץ������ͼ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchRegionEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN const CHAR *pcFileName,
                                              IN ULONG_32 ulPicFormat,
                                              IN const XP_RECT_S *pstRect);

/**
* ���õ㲥�طŵ���ʼʱ�䡣
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcTime             ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   ���ÿ�ʼʱ��ͽ���ʱ��ʧ��
* @note
* 1��SDK�û��ڵ���#IMOS_OpenVodStream֮���#IMOS_StartPlay֮ǰ���øýӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVodBeginTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const char *pcTime);

/**
* ���õ㲥�طŵ���ֹʱ�䡣
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcTime             ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   ���ÿ�ʼʱ��ͽ���ʱ��ʧ��
* @note
* 1��SDK�û��ڵ���#IMOS_OpenVodStream֮���#IMOS_StartPlay֮ǰ���øýӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVodEndTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const char *pcTime);

/**
* �������ص���ʼʱ�䡣
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcTime             ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   ���ÿ�ʼʱ��ͽ���ʱ��ʧ��
* @note
* 1��SDK�û��ڵ���#IMOS_OpenDownloadEx֮���#IMOS_StartDownloadEx֮ǰ���øýӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadBeginTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN const char *pcTime);

/**
* �������ص���ֹʱ�䡣
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcTime             ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   ���ÿ�ʼʱ��ͽ���ʱ��ʧ��
* @note
* 1��SDK�û��ڵ���#IMOS_OpenDownloadEx֮���#IMOS_StartDownloadEx֮ǰ���øýӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadEndTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN const char *pcTime);
/**
* ��һ�������ָ��ǹ��������Դ��\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ����
* @param [IN] pcBallCameraResCode   �����Դ����
* @param [IN] pstBallLoginInfo      �����¼��Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindBallCamera(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN const XP_BALL_LOGIN_INFO_S *pstBallLoginInfo);
/**
* ��ǹ����Դ���б궨��\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ����
* @param [IN] pcBallCameraResCode   �����Դ����
* @param [IN] pstBallMarkPoint      ����궨��Ϣ
* @param [IN] pstOffsetMatchParam   ��оƫ����Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_MarkBallCamera(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN const XP_BALL_MARK_POINT_S *pstBallMarkPoint,
											  IN const XP_BL_OFFSET_MATCHPARAM_S *pstOffsetMatchParam, 
											  IN const DOUBLE dfocalLength);

/**
* ���е�������Ŵ� \n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ
* @param [IN] pcBallCameraResCode   �����Դ
* @param [IN] pstCameraZoomArea     �Ŵ�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallRectZoom(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcBallLinkageResCode,
                                            IN const CHAR *pcBallCameraResCode,
											IN const XP_CAMERA_ZOOMAREA_S *pstCameraZoomArea, 
											IN const DOUBLE dfocalLength);

/**
* ���ת����Ԥ��λ\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ
* @param [IN] pcBallCameraResCode   �����Դ
* @param [IN] ulPresetID     Ԥ��λ���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallSetPreset(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcBallLinkageResCode,
                                             IN const CHAR *pcBallCameraResCode,
                                             IN ULONG_32 ulPresetID);

/**
* ��ȡ��ǰ���λ����Ϣ\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ
* @param [IN] pcBallCameraResCode   �����Դ
* @param [OUT] pstAbsZoom            �Ŵ�����Ϣ
* @param [OUT] pstAbsPosition        ��γ����Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallGetStatus(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcBallLinkageResCode,
                                             IN const CHAR *pcBallCameraResCode,
                                             OUT XP_PTZ_ABSZOOM_S *pstAbsZoom,
                                             OUT XP_PTZ_ABSPOSITION_S *pstAbsPosition);

/**
* �������λ����Ϣ\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ
* @param [IN] pcBallCameraResCode   �����Դ
* @param [IN] pstAbsZoom            �Ŵ�����Ϣ
* @param [IN] pstAbsPosition        ��γ����Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BallGotoPreset(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcBallLinkageResCode,
                                              IN const CHAR *pcBallCameraResCode,
                                              IN XP_PTZ_ABSZOOM_S *pstAbsZoom,
                                              IN XP_PTZ_ABSPOSITION_S *pstAbsPosition);

/**
* �����������Ŀ���\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ
* @param [IN] pcBallCameraResCode   �����Դ
* @param [IN] ulPTZCmdID            ������
* @param [IN] lPTZCmdPara1          ����1
* @param [IN] lPTZCmdPara2          ����2
* @param [IN] lPTZCmdPara3          ����3
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
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
* ��������\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcBallLinkageResCode  ǹ��������Դ
* @param [IN] pcBallCameraResCode   �����Դ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DetachBallCamera(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcBallLinkageResCode,
                                                IN const CHAR *pcBallCameraResCode);

/**
* ���ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pBuffer               ���ý�������ݻ�����ָ�롣
* @param [IN] ulBufSize             ��������С��
* @param [IN] lUserParam            �û����ò���
* @param [IN] lReserved1            ��������1
* @param [IN] lReserved2            ��������2
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ���������ý�������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* XP_MEDIA_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN const UCHAR *pBuffer,
                                                  IN ULONG_32 ulBufSize,
                                                  IN LONG_REAL lUserParam,
                                                  IN LONG_REAL lReserved1,
                                                  IN LONG_REAL lReserved2);

/**
* ����ת��װ��TS��������Ļص�����ָ�롣\n
* @param [IN] pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                 ����ͨ�����롣
* @param [IN] pfnMediaDataCallback          ý�������ݻص�������ָ�롣
* @param [IN] lUserParam                    �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note
* - 1����#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ�Զ�ʧЧ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTsDataOutputCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN XP_MEDIA_DATA_CALLBACK_PF pfnMediaDataCallback,
                                                 IN LONG_REAL lUserParam);

/**
* ��ȡĳ��ͨ����ý����������Ϣ��\n
* @param [IN] pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                 ����ͨ�����롣
* @param [OUT] pcMediaReceiveIp             ý��������IP��ַ
* @param [OUT] pusMediaReceivePort          ý���������˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
* - 1����#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ�Զ�ʧЧ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMediaReceiveInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   OUT CHAR *pcMediaReceiveIp,
                                                   OUT USHORT *pusMediaReceivePort);

/**
* ������ر�ý�������������ܡ�\n
* @param [IN] pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                 ����ͨ�����롣
* @param [IN] bOpen                         �Ƿ�������������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
* - 1����#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ�Զ�ʧЧ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetCrossStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN const BOOL_T bOpen);

/**
* �򿪱��ز����ļ��������ļ���������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         �����ļ����ļ����������ļ�·������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ����ͨ��������
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ������Դʧ��
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      �ļ����Ÿ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       ����ļ��ܵĲ���ʱ��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_FILE            ���������ļ�����ʧ��(�ļ������ڻ������ڱ���������ʹ��)
* -         #ERR_XP_FILE_DESTROY                 ��Ҫ�򿪵��ļ�̫С�����Ѿ���
* -         #ERR_COMMON_NO_MEMORY                ���ļ�ʱϵͳ�ڴ治��
* -         #ERR_XP_FILE_HAVE_OPEN               ָ��ͨ���Ѿ������ļ�
* @note��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenFileBuildIndex(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN const CHAR *pcFileName);
/**
* ����ת�����������ڲ��ӿڣ���\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pstPicDimension         ת�����Ƶͼ��ֱ�����Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         ERR_COMMON_INVALID_PARAM                 ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetTransParam(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN const XP_TRANS_PARAM_S *pstPicDimension);

/**
* �򿪵㲥�ط�ý������ý�������������в������ݣ��ṩ��IA���и߱������ܷ�������\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pcVodUrl              ¼���ļ���URL��
* @param [IN] pcServerIP            ý�����ط�������IP��
* @param [IN] usServerPort          ý�����ط������Ķ˿ںš�
* @param [IN] ulProtl               ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ����ͨ��������
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ������Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý����ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_VOD             �򿪵㲥�ط�ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note
* - 1�������������NAT���������뽫����ý������Э����������Ϊ#XP_PROTOCOL_TCPЭ�飻
* - 2�������㲥�طź��ڲ��Ź����У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ���Ϣ
* -     �ϱ���Ϣ��#XP_RUN_INFO_MEDIA_PROCESS��Я���Ĵ����룺
* -     #ERR_COMMON_NO_MEMORY               �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     �ϱ���Ϣ��#XP_RUN_INFO_RTSP_PROTOCOL��Я���Ĵ����룺
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN      �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_RTSP_DISCONNECT             �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_RTSP_ENCODE_CHANGE          �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT     �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_RTSP_COMPLETE               �ϱ���Ϣ֮ǰ����������ͣ��Ӧͨ���Ĳ���
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodStreamEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcVodUrl,
                                               IN const CHAR *pcServerIP,
                                               IN USHORT usServerPort,
                                               IN ULONG_32 ulProtl);

/**
* ���ò��Ż�����ʱ����Ƶ������Ĭ��Ϊ��������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulSoundChannel     ��Ƶ����ѡ�����#XP_AUDIO_CHANNEL_Eö����ȡֵ

* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                �����Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_PUBLIC_NOT_SUPPORT_SERVICE          ҵ�����Ͳ�֧��
* -         #ERR_XP_NOT_START_PLAY                   ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_SET_AUDIO_CHANNEL        ������Ƶ����ʧ��
* -         #ERR_XP_FAIL_NO_RIGHT_AUDIO_CHANNEL      ��Ƶû��������
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSoundChannel(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode, IN ULONG_32 ulSoundChannel);

/**
* �������������ܡ�\n
* @param [IN] bResistLost                  �Ƿ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_SET_PARAM            ���ò����������ò���ʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResistLost(IN BOOL_T bResistLost);

/**
* ����¼���������ͣ\�\\n
* @param [IN] pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ������Դ���롣
* @param [IN] enMediaType              ��ö��ֵ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
            ���������������
* @note �ýӿ���IMOS_OpenDownload(Ex)֮����û�IMOS_StartRecord(Ex)֮ǰ����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRecordDataType(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                             IN const CHAR *pcChannelCode, IN XP_MEDIATYPE_E enMediaType);

/**
* ��ȡͨ���������ĳ������͡�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcDecoderTag       ��������ǩ������IMOS_STRING_LEN_64
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           �����Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetChannelDecoderTag(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                                  IN const CHAR *pcChannelCode,
                                                                  OUT CHAR *pcDecoderTag);

/* Begin: Add by chenliang w0897, 2014/8/28, MPPD16481: ʵ�ֲ�ͬģ�����XP��Ϣ�ص����������� */
/**
* ���ý�����Ϣ�����쳣��Ϣ�Ļص�����: ���ظ����á�\n
* @param [IN] pfRunInfoFunc ��Ϣ�����쳣��Ϣ�ص�������ָ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* @note
* - 1���û����������ø���������Ļص�������ֱ�ӵ��ò��������κνӿں�����
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMultiRunMsgCB(IN XP_RUN_INFO_CALLBACK_EX_PF pfnRunInfoFunc);
/* End: Add by chenliang w0897, 2014/8/28, MPPD16481: ʵ�ֲ�ͬģ�����XP��Ϣ�ص����������� */


/* Begin: Add by chenxiangyi w1099, 2014/10/29, MPPD18550: ʵ�ֲ�ͬģ�����XP��Ϣ�ص�������ɾ�� */
/**
* �ͷŽ�����Ϣ�����쳣��Ϣ�Ļص�������\n
* @param [IN] pfRunInfoFunc ��Ϣ�����쳣��Ϣ�ص�������ָ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* @note
* - 1���û����������ø���������Ļص�������ֱ�ӵ��ò��������κνӿں�����
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelMultiRunMsgCB(IN XP_RUN_INFO_CALLBACK_EX_PF pfnRunInfoFunc);
/* End: Add by chenxiangyi w1099, 2014/10/29, MPPD18550: ʵ�ֲ�ͬģ�����XP��Ϣ�ص�������ɾ�� */

/**
* ����GPU����ģʽ��\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode             ͨ����Դ���롣
* @param [IN] bEnable   �Ƿ�����GPU��־
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ���������Ч
* -         #ERR_XP_FAIL_TO_ENABLE_IA_GPU_DECODE   ����ʧ��
* @note
* - 1���ýӿڽ���������Ʋ�������Ч�������Ʒ�������
* - 2���û��ڵ���#IMOS_OpenVodStream֮���#IMOS_StartPlay֮ǰ���øýӿڡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_EnableIAGpuDecode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN BOOL_T bEnable);

/**
* ������ر���ʾ���ܹ��ܡ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] bOpen              �Ƿ���������ʾ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
*/
IMOS_EXPORT ULONG_32 IMOS_SetDisplayIntelligence(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN BOOL_T bEnable);


/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */
/**
* ������ʾOSD
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pstOsdList            OSD��Ϣ�б�
* @param [IN] ulOsdNum              OSD����
* @return �������½����
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_SET_OSD              ������ʾosdʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note
* - 1�����øýӿڿ�ʼ��ʾָ����OSD��ֱ������IMOS_StopOSD��OSD��ʧ��
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN const XP_OSD_OVER_INFO_S *pstOsdList,
                                        IN ULONG_32 ulOsdNum);

IMOS_EXPORT ULONG_32 STDCALL IMOS_AddOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN const XP_OSD_OVER_INFO_S *pstOsdList,
                                         IN ULONG_32 ulOsdNum);
/* Begin:Add by lizhen for ��ѯOSD��Ϣ in 2017/3/24
/** 
* ��ѯOSD��Ϣ(��Ҫ���ǳ��Ϳ�)
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [INOUT] pstOsdList         OSD��Ϣ�б�
* @param [IN] ulOsdNum              OSD����
* @return �������½����
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* @note 
* - 1��ֻ���ص���IMOS_AddOSD���ӵ�OSD��������ϵͳʱ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           INOUT XP_OSD_OVER_INFO_S *pstOsdList,
                                           IN ULONG_32 ulOsdNum);
/**
* ��λ��ʾOSD
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_STOP_OSD            ֹͣ��ʾosdʧ��
* -         #ERR_XP_PORT_NOT_REGISTER           ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopOSD(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);
/* End: Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP�ͻ���¼��ʱ֧�ִ�С���� */
/**
* ���÷ֶ�����ʱ, �ļ���С���ޡ�\n
* @param [IN]  pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode                ������Դ���롣
* @param [IN]  ulMaxDownloadSize            �����ļ������ֵ, ��λΪM��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ȡͨ��ʧ��
* -         #ERR_PUBLIC_ACQUIRE_MUTEX_FAIL       ��ȡ��ʧ��
* -         #ERR_COMMON_INVALID_PARAM            ��������
* @note �粻���øýӿڻ������������ֵΪ0�����ʾ�����ļ���Сû������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMaxDownloadSize(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                     IN const CHAR *pcChannelCode,
                                                     IN const ULONG_32 ulMaxDownloadSize);
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP�ͻ���¼��ʱ֧�ִ�С���� */

/**
* ����ƴ֡ǰý�������ݻص�������\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [IN] pfnSourceMediaDataCBFun ƴ֡ǰý�������ݻص�������ָ�롣
* @param [IN] bContinue               �Ƿ�������к����ƴ֡���������ʾ������
* @param [IN] lUserParam              �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                �����Ч
* -         #ERR_XP_NOT_START_PLAY                   ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note Ŀǰֻ��bContinueΪfalse����Ч��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSourceMediaDataCBEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                         IN BOOL_T bContinue,
                                                         IN LONG lUserParam);

/**
* ��ȡý����������\n
* @param [IN] pstUserLoginIDInfo            �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                 ����ͨ�����롣
* @param [OUT] pstMediaAbility              ý��������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
* - 1����#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ�Զ�ʧЧ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMediaAbilityInfo(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   OUT XP_MEDIA_ABILITY_S *pstMediaAbility);

/**
* ����ʵ������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcProxyIP          ʵ������ip
* @param [IN] usProxyPort        ʵ������˿ں�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         ERR_COMMON_INVALID_PARAM                 ��������Ƿ�
* -         #ERR_XP_FAIL_TO_SET_PROXY                ���ô���ʧ��
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetStreamProxyParam(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN const CHAR *pcProxyIP,
                                                   IN USHORT usProxyPort);


/**
* �������ص�option�����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ������Դ���롣
* @param [IN] ulOptionInterval   ����option�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          ��ͣý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       ����Э����ͣʧ��
* -         #ERR_XP_FAIL_TO_PAUSE                ��ͣ���Ų���ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadOptionInterval(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN const CHAR *pcChannelCode,
                                                            IN ULONG_32 ulOptionInterval);

/**
* �򿪷ֶε㲥�ط�ý������\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pcVodUrl              ¼���ļ���URL�б�
* @param [IN] ulUrlCount            �ֶ�¼�����Ŀ
* @param [IN] pcServerIP            ý�����ط�������IP��
* @param [IN] usServerPort          ý�����ط������Ķ˿ںš�
* @param [IN] ulProtl               ����ý������Э�����ͣ����tagProtocolö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ����ͨ������ռ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ������Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý����ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_VOD             �����㲥�ط�ҵ��ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodStreamV2(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcVodUrl[],
                                               IN ULONG_32 ulUrlCount,
                                               IN const CHAR *pcServerIP,
                                               IN USHORT usServerPort,
                                               IN ULONG_32 ulProtl);

/**
* �����ֶ�¼�����أ����������������ļ��ϲ���һ���ļ���    /n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl           ������ý������Դ��URL�б�
* @param [IN]  pcServerIP          ý�����ط�������IP��
* @param [IN]  usServerPort        ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl             ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��������Ŀǰ��֧��TCPЭ�飩��
* @param [IN]  ulDownMediaSpeed    ý�����������ٶȣ����#XP_DOWN_MEDIA_SPEED_Eö����ȡֵ��
* @param [IN]  pcFileName          ����ý�����ݱ�����ļ���������·����
* @param [IN]  szDecoderTag        �����ǩ
* @param [OUT] pcDownloadID        ����ͨ�����б�����������Ӧ��С��#IMOS_RES_CODE_LEN��48����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      ��������ͨ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲��ţ����أ�ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý��ʧ��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     ���̿ռ䲻��
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       ��������ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note
* - 1���ú������óɹ��󣬷��ظ��û�����ͨ���ţ����ڱ�ʶһ·����ͨ����
* - 2�����ͬʱ֧������32·����ͨ����
* - 3��Ŀǰ��֧��TCPЭ������ý������
* - 4��ֹͣý�������������#IMOS_StopMultiSectionDownload�ӿڣ�
* - 5���ýӿں�����֧��Windows��
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
* ֹͣ�ֶ�¼�����ء�\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownloadID        ����ͨ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note
* - 1���ýӿ���#IMOS_StartMultiSectionDownload�ӿ�ƥ�䣻
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopMultiSectionDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcDownloadID);

/* begin: added by zhangbolun 03503 2017/07/24 for ��Ƶ�ṹ�� MPPD49482*/
/**
* �����ܻط�ý����(VAS��XPͨ��)��\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pcServerIP                  ������IP��ַ��
* @param [IN] usServerPort             �����˶˿ڡ�
* @param [OUT] pcLocalIP                ��������IP��
* @param [OUT] pulLocalPort          ���������˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ����ͨ������ռ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ������Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý����ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_VOD             �����㲥�ط�ҵ��ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note 
* - 1��Ŀǰ��֧��UDP�����RTP+ES����
* - 2��H.264��rtp_typΪ105��˽�����ݵ�rtp_typΪ115
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenIntelligenceVod (IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode,
                                                       IN CHAR *pcServerIP,
                                                       IN USHORT usServerPort,
                                                       OUT CHAR *pcLocalIP,
                                                       OUT ULONG_32 *pulLocalPort);
 /* end: added by zhangbolun 03503 2017/07/24 for ��Ƶ�ṹ�� MPPD49482*/
#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_MEDIA_PLAYER_SDK_INNER_FUNC_H_ */



