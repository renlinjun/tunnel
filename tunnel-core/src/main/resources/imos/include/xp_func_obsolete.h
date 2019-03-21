/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_func_obsolete.h

  Project Code: IMOS XP������
   Module Name: IMOS XP������
  Date Created: 2008-09-10
        Author: shiyouhua/04562
   Description: ������XP�Ͻӿں���ͷ�ļ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_MEDIA_PLAYER_SDK_OBSOLETE_FUNC_H_
#define _IMOS_XP_MEDIA_PLAYER_SDK_OBSOLETE_FUNC_H_

/* ��������ƽ̨��ͷ�ļ� */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"
/* ����XP SDK���ݽṹͷ�ļ� */
#include "xp_datatype.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* ��ʼ��������XP��Դ��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* -         #ERR_XP_FAIL_TO_REG_BP_CMD   ע�����ƽ̨BP��������ģ��ʧ��
* -         #ERR_XP_FAIL_TO_INIT_XP      ��ʼ��������XP��Դʧ��
* @note
* - ʹ�ò�����XP�����������Ҫ���õĺ�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_Init();

/**
* �ͷŲ�����XP��Դ��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* -         #ERR_XP_FAIL_TO_CLEANUP_XP   �ͷŲ�����XP��Դʧ��
* @note �˳�������XP��������һ����Ҫ���ú�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_Cleanup();

/**
* ��ʼ��������XP��Դ��\n
* @param [IN] pcModuleBaseCode ����ƽ̨BPģ��ı��롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* -         #ERR_XP_FAIL_TO_REG_BP_CMD   ע�����ƽ̨BP��������ģ��IDʧ��
* -         #ERR_COMMON_INVALID_PARAM    ���������Ч
* -         #ERR_XP_FAIL_TO_INIT_XP      ��ʼ��������XP��Դʧ��
* @note
* - ʹ�ò�����XP�����������Ҫ���õĺ�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_InitXP(IN const CHAR *pcModuleBaseCode);

/**
* �ͷŲ�����XP��Դ��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* -         #ERR_XP_FAIL_TO_CLEANUP_XP   �ͷŲ�����XP��Դʧ��
* @note �˳�������XP��������һ����Ҫ���ú�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_CleanupXP();

/** @defgroup groupPlayerStart ����������
*   ��������������Ҫ�������ò���������������ע��/ע��������/ֹͣ�������ȡ�
*   @{
*/
/**
* ���ò�����XP���豸ID��\n
* @param [IN] pcXPDevID ������XP���豸ID����IMOS_GetXPCode�������XP��Ϣ�����а���������XP���豸ID��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ���������Ч
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetXPDevID(IN const CHAR *pcXPDevID);

/**
* ���ò��Ŵ��ڵľ������Դ���롣\n
* @param [IN] hWnd         ���Ŵ��ھ����
* @param [IN] pcWndResCode ���Ŵ��ڵ���Դ���룬��IMOS_GetXPCode�������XP��Ϣ�����а�����һ�����ڵ���Դ���룬
*                          �����Ĵ�����Դ������ڵ�һ�����ڵ���Դ����Ļ��������ɡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_EXCEED_MAX_PLAY_WINDOW_NUM       ע��Ĳ��Ŵ���������������
* @note
* -      1��ÿ����һ������һ�����Ŵ��ڵľ������Դ���롣һ�㰴������������֧�ֵ���󲥷Ŵ����������ֱ���øú�����
* -         ���磺��������Ϊ25������Ҫ����25�θú�������25�����Ŵ��ڵľ������Դ����
* -      2���ú������õĸ������Ŵ��ھ�������ظ����������Ŵ��ڵ���Դ����Ҳ�����ظ���������XP�ڲ��Դ˲���飬��Ҫ�û���֤����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetWndIDInfo(IN IMOS_HANDLE hWnd,
                                          IN const CHAR *pcWndResCode);

/**
* ���������Խ�����Դ���롣\n
* @param [IN] pcTalkbackResCode �����Խ�����Դ���룬��IMOS_GetXPCode�������XP��Ϣ�����а��������Խ�����Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ���������Ч
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceTalkbackResCode(IN const CHAR *pcTalkbackResCode);

/**
* ���������㲥����Դ���롣\n
* @param [IN] pcBroadcastResCode �����㲥����Դ���룬��IMOS_GetXPCode�������XP��Ϣ�����а��������㲥����Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ���������Ч
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceBroadcastResCode(IN const CHAR *pcBroadcastResCode);

/**
* ע����Ϣ���쳣��Ϣ�ص�������\n
* @param [IN] pfRunInfoFunc ��Ϣ���쳣��Ϣ�ص�������ָ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ���������Ч
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetRunMsgCB(IN const XP_RUN_INFO_CALLBACK_PF pfnRunInfoFunc);

/**
* ���ý����ý�������ݻص�������\n
* @param [IN] pfnDataProcFunc �����ý�������ݻص�������ָ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ע������ý�������ݻص�����ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetOutputMediaDataCB(IN XP_PROCESS_MEDIA_DATA_CALLBACK_PF pfnDataProcFunc);

/**
* ������Ƶ��ʾģʽ��\n
* @param [IN] enRenderMode ��Ƶ��ʾģʽ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_XP_FUNCTION_CALL_ORDER_ERROR      �ӿڵ���˳�����
* @note
* - 1������ͻ�û�е��øú���������Ƶ��ʾģʽ���򲥷���XP�ڲ�Ĭ��ʹ��DDraw��Normal��ʾģʽ��
* - 2��������XP_StartXP����֮ǰ���á�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetRenderMode(IN XP_RENDER_MODE_E enRenderMode);

/**
* ������Ƶͼ���ʽ����YUV��RGB������Ƶͼ���ʽ��\n
* @param [IN] enPixelFormat ��Ƶͼ���ʽ��
* @return ��
* @note
* - 1������ͻ�û�е��øú����ӿڣ��򲥷���XP�ڲ�Ĭ��ʹ��YUV��Ƶͼ���ʽ��
* - 2��������XP_StartXP����֮ǰ���á�
*/
IMOS_EXPORT VOID STDCALL XP_SetPixelFormat(IN XP_PIXEL_FORMAT_E enPixelFormat);

/**
* ���ÿ������������CC����Ϣ��\n
* @param [IN] pcServerDevID ����������������豸ID��
* @param [IN] pcServerIP    ���������������IP��
* @param [IN] usServerPort  ��������������Ķ˿ںš�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM    ���������Ч
* @note ���������������Ҫ���ڲ�����XP�ͷ�����֮���SIPע���SIP�Ự��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetCCServerInfo(IN const CHAR *pcServerDevID,
                                             IN const CHAR *pcServerIP,
                                             IN USHORT usServerPort);

/**
* ע�Ქ����XP��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_XP_FAIL_TO_REGIST_XP        ע�Ქ����XPʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_RegXP();

/**
* ��ѯ������XP�Ƿ���NAT������\n
* @param [IN] �ޡ�
* @return �������´�����:
* -         #BOOL_TRUE          XP��NAT����
* -         #BOOL_FALSE         XP����NAT����
* @note ������XP_RegXP����֮����á�
*/
IMOS_EXPORT BOOL_T STDCALL XP_IsXPInNat();

/**
* ע��������XP��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_XP_FAIL_TO_UNREGIST_XP      ע��������XPʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_UnregXP();

/**
* ����������XP��\n
* @param [IN] �ޡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_XP_FAIL_TO_START_XP         ����������XPʧ��
* @note
* -    ������XP_RegXP�ӿڵ���֮�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartXP();

/**
* ֹͣ������XP��\n
* @param [IN] �ޡ�
* @return �ޡ�
* @note
* -     1�����˳�XP֮ǰ���øú���ֹͣ��ǰ���еĻͨ����
* -     2��������XP_UnregXP����֮ǰ���á�
*/
IMOS_EXPORT VOID STDCALL XP_StopXP();

/**
* ����û����õĴ��ھ������Դ�������Ϣ��\n
* @param [IN] �ޡ�
* @return �ޡ�
* @note �ޡ�
*/
IMOS_EXPORT VOID STDCALL XP_ResetInfo();
/** @} */  /* end of groupPlayerStart */

/**
* ��ʼ�����Ŵ��ڵ�ý��ҵ�����͡�\n
* @param [IN] hXpWnd        ���Ŵ��ھ����
* @param [IN] enWndPlayType ���Ŵ��ڵĲ���ҵ�����͡�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_XP_WINDOW_NOT_REGISTER      ����û�б�ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE       ���ڲ���ʹ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC    ����ͨ����ý��ҵ�����Ͳ�֧�ִ˲���
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenPlaySvc(IN IMOS_HANDLE hXpWnd,
                                         IN XP_PLAY_TYPE_E enWndPlayType);

/**
* ���ò���ͨ���ı���IP��ַ�Ͷ˿ںš�\n
* @param [IN] hXpWnd      ���Ŵ��ھ����
* @param [IN] pcLocalIP   ����IP��ַ��
* @param [IN] usLocalPort ���ؼ����˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* @note ���ʹ�ñ���Ĭ�ϵ�IP��ַ���򱾵�IP��ַ����pcLocalIP������ַ�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetWndLocalAddress(IN IMOS_HANDLE hXpWnd,
                                                IN const CHAR *pcLocalIP,
                                                IN USHORT usLocalPort);

/**
* ���ò���ͨ����ý�������IP��ַ�Ͷ˿ںš�\n
* @param [IN] hXpWnd       ���Ŵ��ھ����
* @param [IN] pcServerIP   ý�������IP��ַ��
* @param [IN] usServerPort ý��������˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetWndServerAddress(IN IMOS_HANDLE hXpWnd,
                                                 IN const CHAR *pcServerIP,
                                                 IN USHORT usServerPort);

/**
* ����ý�������ݡ�\n
* @param [IN] hXpWnd   ���Ŵ��ھ����
* @param [IN] pcBuf    ý������ָ�롣
* @param [IN] ulLength ý�����ݳ��ȡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���δע��
* -         #ERR_XP_FAIL_TO_INPUT_DATA               ����ý��������ʧ��
* @note �û�������ʵ����㲥�طź�,���øú�������ý�������ݽ��в��š�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_InputMediaData(IN IMOS_HANDLE hXpWnd,
                                            IN const CHAR *pcBuf,
                                            IN ULONG_32 ulLength);

/**
* ����ָ������ͨ����ý�����ݷ�װ��ʽ��\n
* @param [IN] hXpWnd            ���Ŵ��ھ����
* @param [IN] enMediaDataformat ý�����ݷ�װ��ʽ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_NOT_SUPPORT_MEDIA_STREAM_TYPE    ��֧�ֵ���������
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò��Ŵ��ڵ���Դʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetMediaDataFormat(IN IMOS_HANDLE hXpWnd,
                                                IN XP_MEDIA_DATA_FORMAT_E enMediaDataformat);

/**
* ��ʵʱ���ý������\n
* @param [IN] hXpWnd          ���Ŵ��ھ����
* @param [IN] pcRemoteResCode ǰ��ý��Դ����Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ���Ŵ��ڱ�ռ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_SESSION        ����Ự����ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_REALTIME        ����ʵʱ���ҵ��ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenRealtimeMonitor(IN IMOS_HANDLE hXpWnd,
                                                 IN const CHAR *pcRemoteResCode);

/** @defgroup groupPlayerRealtime ������ʵʱ����
*   ������ʵʱ���ţ���Ҫ����ץͼ����ȡý����������ʵʱ���ſ��Ƶȡ�
*   @{
*/
/**
* ���ý��볡ģʽ��\n
* @param [IN]  hXpWnd      ���Ŵ��ھ����
* @param [OUT] enFieldMode ��ģʽ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_SET_FIELD_MODE       ���ó�ģʽʧ��
* @note
* -    1��MPEG4���뷽ʽû�г��ĸ��
* -    2��������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øú������ý��볡ģʽ��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetFieldMode(IN IMOS_HANDLE hXpWnd,
                                          IN XP_FIELD_MODE_E enFieldMode);

/**
* ����/�ر�ȥ��֯����\n
* @param [IN] hXpWnd            ���Ŵ��ھ����
* @param [IN] enDeinterlaceMode ȥ��֯����ģʽ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                   δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_ENABLE_DEINTERLACE       ������ر�ȥ��֯����ʧ��
* @note
* -    1��Ĭ������£�ʹ�û��ģʽ����ȥ��֯����
* -    2��������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øýӿ�������ر�ȥ��֯����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_EnableDeinterlace(IN IMOS_HANDLE hXpWnd,
                                               IN XP_DEINTERLACE_MODE_E enDeinterlaceMode);

/**
* ����/�رս����ý�������������\n
* @param [IN] hXpWnd          ���Ŵ��ھ����
* @param [IN] enMediaDataType �����ý�������ݵ����͡�
* @param [IN] bEnable         �Ƿ����ý�������ݡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ָ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_ENABLE_OUTPUT_DATA       ������ر�XP���ý������ʧ��
* @note ������ر�ָ���Ĳ���ͨ����������ָ�����͵�ý�����ݣ�Ĭ������²������
*/
IMOS_EXPORT ULONG_32 STDCALL XP_EnableOutputMediaData(IN IMOS_HANDLE hXpWnd,
                                                   IN XP_OUTPUT_MEDIA_DATA_TYPE_E enMediaDataType,
                                                   IN BOOL_T bEnable);

/**
* ��ͣ���š�\n
* @param [IN] hXpWnd   ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ�������Ų���
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          ��ͣý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       ����Э����ͣʧ��
* -         #ERR_XP_FAIL_TO_PAUSE                ��ͣ���Ų���ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_PausePlay(IN IMOS_HANDLE hXpWnd);

/**
* �ָ����ţ��ָ���������ͣ��ͨ����\n
* @param [IN] hXpWnd    ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ�������Ų���
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲���ʧ��
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         �ָ�ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_RESUME               �ָ����Ų���ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_ResumePlay(IN IMOS_HANDLE hXpWnd);

/**
* ����/ȡ��������\n
* @param [IN] hXpWnd ���Ŵ��ھ����
* @param [IN] bEnabled �Ƿ��� ��BOOL_TRUE������������BOOL_FALSE��ȡ����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ָ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_QUIET                    ����/ȡ����������ʧ��
* @note
* -     ͬһʱ��ֻ�ܲ���һ·������Ҳ����˵����ȡ��ĳ������ͨ������ʱ���Ȳ鿴�Ƿ��������Ĳ���ͨ��������ͨ����
* -     �ڲ�������������У��ͽ����ڲ���������ͨ���óɾ�����Ȼ��ȡ��ָ������ͨ��������ʹ�俪ʼ����������
*/
IMOS_EXPORT ULONG_32 STDCALL XP_Quiet(IN IMOS_HANDLE hXpWnd,
                                   IN BOOL_T bEnabled);

/**
* �������ڡ�\n
* @param [IN] ulVolume ����ֵ��ȡֵΪ0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        �����Ч
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    ������������ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_AdjustVolume(IN ULONG_32 ulVolume);

/**
* ��õ�ǰ���õ�����ֵ��\n
* @param [OUT] pulVolume ����ֵ��ָ�루���ص�����ֵȡֵΪ0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        �����Ч
* -         #ERR_XP_FAIL_TO_GET_VOLUME       �������ֵʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetVolume(OUT ULONG_32 *pulVolume);

/**
* ��������ͨ����Ƶ���ݵ�WAVE���Σ����Ըı�����ͨ�����������Ĵ�С��\n
* @param [IN] ulCoefficient �����Ĳ�������Χ��0��255��255Ϊ����������ֵ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        �����Ч
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    ������������ʧ��
* @note
* -    �˺�����XP_AdjustVolume�����Ĳ�֮ͬ�����ڣ����ǵ�������ͨ��
* -  ������ʵʱ���š��طź��������������ݵ�WAVE���Σ�ֻ������ͨ�������ã�
* -   ��XP_AdjustVolume�ǵ�����������������������ϵͳ�����á�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_AdjustAllWaveAudio(IN ULONG_32 ulCoefficient);

/**
* ����ʵʱץ�ġ�\n
* @param [IN] hXpWnd      ���Ŵ��ھ����
* @param [IN] pcFileName  ���ץ��ͼƬ���ļ�·���������ļ�����������չ������
* @param [IN] enPicFormat ץ��ͼƬ�ĸ�ʽ��XP_PICTURE_BMP����ʾbmp��ʽ��XP_PICTURE_JPG����ʾjpg��ʽ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ�������Ų���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          ����ץ�Ĳ���ʧ��
* @note ������XP�����ļ������渽��������"20080928(13-10-50-99)"��ʽ��ץ��ʱ����ַ�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SnatchOnce(IN IMOS_HANDLE hXpWnd,
                                        IN const CHAR *pcFileName,
                                        IN XP_PICTURE_FORMAT_E enPicFormat);

/**
* ��������ʵʱץ�ġ�\n
* @param [IN] hXpWnd           ���Ŵ�������
* @param [IN] pcFileName       ���ץ��ͼƬ���ļ�·���������ļ�����������չ������
* @param [IN] enPicFormat      ץ��ͼƬ�ĸ�ʽ��
* @param [IN] ulSnatchInterval ץ�ļ������λ�����룩��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NOT_START_PLAY               δ�������Ų���
* -         #ERR_XP_ALREADY_START_SERIES_SNATCH  ���Ŵ����Ѿ�����������ץ�ĵĲ���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_START_SERIES_SNATCH  ��������ץ�Ĳ���ʧ��
* @note
* -      ������XP�����ļ������渽��������"20080928(13-10-50-99)"��ʽ��ץ��ʱ����ַ�����
* -      ÿ�����ڳɹ�ץ�ĵ����ͼƬ���ͻ��������йء�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartSnatchSeries(IN IMOS_HANDLE hXpWnd,
                                               IN const CHAR *pcFileName,
                                               IN XP_PICTURE_FORMAT_E enPicFormat,
                                               IN ULONG_32 ulSnatchInterval);

/**
* ֹͣ����ʵʱץ�ġ�\n
* @param [IN] hXpWnd ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ�������Ų���
* -         #ERR_XP_NOT_START_SERIES_SNATCH      δ��������ץ�Ĳ���
* -         #ERR_XP_FAIL_TO_STOP_SERIES_SNATCH   ֹͣ����ץ�Ĳ���ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopSnatchSeries(IN IMOS_HANDLE hXpWnd);

/**
* ��������¼��\n
* @param [IN] hXpWnd            ���Ŵ��ھ����
* @param [IN] pcFilePathName    �洢¼���Ŀ���ļ�·�����������ļ���(·������б��)��
* @param [IN] enVideoFileFormat �������Ƶ�ļ��ĸ�ʽ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                    ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER                  ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                       δ�������Ų���
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           ָ���Ĳ���ͨ���Ѿ�����¼�����
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      ¼���ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             Ӳ�̿ռ䲻��
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 ��ǰ��������ͣ����״̬
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         ��ǰ�����ڱ��ٲ���״̬
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  ��ǰ�����ڵ�֡����״̬
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           ��������¼��ʧ��
* @note
* -    ������XP�����ļ������渽��������"00-20091222(14-30-24-984)"��ʽ���ַ�����
* -                                      |          |
* -                                   ͨ��ID  ��ʼ¼��ʱ���
* -    ���㲥�طŻ򱾵��ļ��طŴ�����ͣ���š����ٲ��Ż�֡����״̬ʱ����֧����������¼�������
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartRecordVideo(IN IMOS_HANDLE hXpWnd,
                                              IN const CHAR *pcFilePathName,
                                              IN XP_MEDIA_FILE_FORMAT_E enVideoFileFormat);

/**
* ֹͣ����¼��\n
* @param [IN] hXpWnd ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER                  ���Ŵ���û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC                ���Ŵ��ڵ�ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_RECORD_VIDEO               ָ���Ĳ���ͨ��δ��������¼�����
* -         #ERR_XP_FAIL_TO_STOP_RECORD_VIDEO            ֹͣ����¼��ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopRecordVideo(IN IMOS_HANDLE hXpWnd);

/**
* ���ָ������ͨ������Ƶ�����ʽ��\n
* @param [IN]  hXpWnd             ���Ŵ��ھ����
* @param [OUT] penVideoEncodeType ��Ƶ�����ʽ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES           ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER            ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                 δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE  �����Ƶ�����ʽʧ��
* @note
* -    ������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øú������ָ������ͨ������Ƶ�����ʽ��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetVideoEncodeType(IN IMOS_HANDLE hXpWnd,
                                                OUT XP_VIDEO_ENCODE_TYPE_E *penVideoEncodeType);

/**
* ���ָ������ͨ���Ķ����ʡ�\n
* @param [IN]  hXpWnd        ���Ŵ��ھ����
* @param [OUT] pulRecvPktNum ���յ��İ�����
* @param [OUT] pulLostPktNum �����İ�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_LOST_PKT_RATE    ��ö�����ͳ������ʧ��
* @note
* -    ������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øýӿڻ��ָ������ͨ���Ķ����ʡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetLostPacketRate(IN IMOS_HANDLE hXpWnd,
                                               OUT ULONG_32 *pulRecvPktNum,
                                               OUT ULONG_32 *pulLostPktNum);

/**
* ��λָ������ͨ���Ķ����ʡ�\n
* @param [IN] hXpWnd    ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                   δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE      ��λ������ͳ��ʧ��
* @note ���øú����󣬽��Ӹ�λʱ�����¿�ʼͳ�ƶ����ʡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_ResetLostPacketRate(IN IMOS_HANDLE hXpWnd);

/**
* ���ָ������ͨ���Ķ�֡�ʡ�\n
* @param [IN] hXpWnd           ���Ŵ��ھ����
* @param [OUT] pulAllFrameNum  ֡������
* @param [OUT] pulLostFrameNum ������֡����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE  ��ö�֡������ʧ��
* @note
* -    ������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øú������ָ������ͨ���Ķ�֡�ʡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetLostFrameRate(IN IMOS_HANDLE hXpWnd,
                                              OUT ULONG_32 *pulAllFrameNum,
                                              OUT ULONG_32 *pulLostFrameNum);

/**
* ��λָ������ͨ���Ķ�֡�ʡ�\n
* @param [IN] hXpWnd ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER              ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY                   δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE    ��λ��֡��ʧ��
* @note ���øú����󣬽��Ӹ�λʱ�����¿�ʼͳ�ƶ�֡�ʡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_ResetLostFrameRate(IN IMOS_HANDLE hXpWnd);

/**
* ���ָ������ͨ����֡�ʡ�\n
* @param [IN]  hXpWnd       ���Ŵ��ھ����
* @param [OUT] pulFrameRate ֡�ʣ���λΪfps����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_FRAME_RATE       ���֡������ʧ��
* @note
* -    ������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øú������ָ������ͨ����֡�ʡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetFrameRate(IN IMOS_HANDLE hXpWnd,
                                          OUT ULONG_32 *pulFrameRate);

/**
* ���ָ������ͨ�������ʡ�\n
* @param [IN]  hXpWnd     ���Ŵ��ھ����
* @param [OUT] pulBitRate ���ʣ���λΪbps����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý��ҵ�����Ͳ�֧�ִ˲���
* -         #ERR_XP_NOT_START_PLAY               δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_BIT_RATE         �����������ʧ��
* @note
* -    ������ʵ����㲥�ط�֮����øú������ָ������ͨ�������ʡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetBitRate(IN IMOS_HANDLE hXpWnd,
                                        OUT ULONG_32 *pulBitRate);
/** @} */  /* end of groupPlayerRealtime */

/** @defgroup groupPlayerPlayback �������㲥�ط�
*   �������㲥�طţ���Ҫ������ͣ�㲥�طš�ץͼ����ȡý�����������طſ����Լ�¼���ļ����صȡ�
*   @{
*/
/**
* ����ý�������ݵĴ���Э�顣\n
* @param [IN] hXpWnd       ���Ŵ��ھ����
* @param [IN] enTransProtl ý�����ݵĴ���Э�顣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_XP_NOT_SUPPORT_TRANSPORT_PROTOCOL_TYPE  ��֧�ֵĴ����Э������
* -         #ERR_XP_WINDOW_NOT_REGISTER                  ���Ŵ���û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò��Ŵ��ڵ���Դʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetTransportProtocol(IN IMOS_HANDLE hXpWnd,
                                                  IN XP_NETWORK_TRANSPORT_PROTOCOL_E enTransProtl);

/**
* ����ͨ���ĳ�����Ϣ��\n
* @param [IN] hXpWnd       ���Ŵ��ھ����
* @param [IN] pcDecoderTag ��������ǩ��Ŀǰ֧�ֵĳ��̽������У�"h3c-v3"��ʾH3C V3�汾��������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_XP_WINDOW_NOT_REGISTER                  ���Ŵ���û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_COMMON_INVALID_PARAM                    ���������Ч
* @note ����ͻ�û�е��øú����ӿڣ��򲥷���XP�ڸ�ͨ��Ĭ��ʹ��H3C V3�汾�Ľ�������
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetDecoderTag(IN IMOS_HANDLE hXpWnd,
                                           IN const CHAR * pcDecoderTag);

/**
* �򿪵㲥�ط�ý������\n
* @param [IN] hXpWnd       ���Ŵ��ھ����
* @param [IN] pcVodUrl     �㲥�طŵ�URL��
* @param [IN] pcServerIP   ý�����ط�������IP��
* @param [IN] usServerPort ý�����ط������Ķ˿ںš�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ���Ŵ��ڱ�ռ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý����ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_VOD             �����㲥�ط�ҵ��ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenVodStream(IN IMOS_HANDLE hXpWnd,
                                           IN const CHAR *pcVodUrl,
                                           IN const CHAR *pcServerIP,
                                           IN USHORT usServerPort);

/**
* ��ʼ���š�\n
* @param [IN] hXpWnd ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_PORT_NOT_OPEN                δ����ý��ҵ��
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲���ʧ��
* -         #ERR_XP_FAIL_TO_START_PLAY           ��ʼ����ʧ��
* @note ��Ҫ���ڿ�ʼ�㲥�طźͱ����ļ��طš�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartPlay(IN IMOS_HANDLE hXpWnd);

/**
* ����ǰ��/���˲��š�\n
* @param [IN] hXpWnd      ���Ŵ��ھ����
* @param [IN] enPlaySpeed ���ŵ����ʡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ���Ŵ��ڵ�ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ָ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ����¼��
* -         #ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY   ����ǰ��/���˲���ʧ��
* @note ���ڱ���¼��ʱ����֧�ֱ���ǰ��/���˲��Ų�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetPlaySpeed(IN IMOS_HANDLE hXpWnd,
                                          IN XP_PLAY_STATUS_E enPlaySpeed);

/**
* ��֡ǰ��/���˲��š�\n
* @param [IN] hXpWnd   ���Ŵ��ھ����
* @param [IN] bForward ��֡ǰ����֡���˲��ţ�BOOL_TRUE����֡ǰ����BOOL_FALSE����֡���ˣ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ���Ŵ��ڵ�ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ָ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_STEP_PLAY            ��֡����ʧ��
* @note ���ڱ���¼��ʱ����֧�ֵ�֡ǰ��/���˲��Ų�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OneStepPlay(IN IMOS_HANDLE hXpWnd,
                                         IN BOOL_T bForward);

/**
* ��ת���š�\n
* @param [IN] hXpWnd      ���Ŵ��ھ����
* @param [IN] pcTimeStamp ��ת����ʱ��ֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ���Ŵ��ڵ�ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ָ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            ��ת����ʧ��
* @note
* -     1�����ڲ�ͬ��Ӧ�ã�pcTimeStamp����ȡֵӦ��ͬ��
* -     ��1�������ļ��ط�ʱ���ò�����ֵӦΪ���ʱ�䣬������ļ�ͷ�Ĳ���ʱ�䣨��λΪ�룩��
* -     ��2���㲥�ط�ʱ���ò�����ֵӦΪ����ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* -     2�����ڱ���¼��ʱ�򣬲�֧����ת���Ų�����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_DragPlay(IN IMOS_HANDLE hXpWnd,
                                      IN const CHAR * pcTimeStamp);

/**
* ���ָ������ͨ���Ĳ��Ž��ȡ�\n
* @param [IN]  hXpWnd       ���Ŵ��ھ����
* @param [OUT] szCurPlayPos ��ŵ�ǰ���Ž��ȵ�ʱ��ֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ���Ŵ��ڵ�ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ָ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    ��õ�ǰ���Ž���ʧ��
* @note
* -     szCurPlayPos����������ŵ�ǰ���Ž��ȵ�ʱ��ֵ�����ڲ�ͬ��Ӧ����ȡֵ��ͬ��
* -     1�������ļ��ط�ʱ���ò�����ŵ������ʱ�䣬��������ļ�ͷ�Ĳ���ʱ�䣨��λΪ�룩��
* -     2���㲥�ط�ʱ���ò�����ŵ��Ǿ���ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetCurPlayPos(IN IMOS_HANDLE hXpWnd,
                                           OUT CHAR szCurPlayPos[IMOS_TIME_LEN]);

/**
* ��������ý������\n
* @param [IN]  pcServerIP       ý�����ط�������IP��
* @param [IN]  usServerPort     ý�����ط������Ķ˿ںš�
* @param [IN]  pcDownUrl        ������ý������Դ��URL��
* @param [IN]  pcFileName       ����ý�����ݱ����·���������ļ���(·������б��)��
* @param [IN]  enDownMediaSpeed ý�����������ٶȡ�
* @param [OUT] szDownloadID     ����ͨ����ID��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_DOWNLOAD_PORT_NUM_LIMIT      ��������ͨ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SETUP_PROTOCOL       ��������Э��ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲��ţ����أ�ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ����ý�崦��ʧ��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     ���̿ռ䲻��
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       ��������ʧ��
* -         #ERR_XP_RTSP_REQ_TIMEOUT             ����ҵ����ʱ
* -         #ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH    ����ҵ�������
* -         #ERR_XP_RTSP_SERVINTERERR            ����ҵ���ڲ�����
* @note
* -         1���ú������óɹ��󣬷��ظ��û�����ͨ����ID�����ڱ�ʶһ·����ͨ����
* -         2���û�ͬʱ�������ص����ͨ����Ϊ5��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartDownMediaStream(IN const CHAR *pcServerIP,
                                                  IN USHORT usServerPort,
                                                  IN const CHAR *pcDownUrl,
                                                  IN const CHAR *pcFileName,
                                                  IN XP_DOWN_MEDIA_SPEED_E enDownMediaSpeed,
                                                  OUT CHAR szDownloadID[IMOS_RES_CODE_LEN]);

/**
* ֹͣ����ý������\n
* @param [IN] pcDownloadID ����ͨ����ID��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopDownMediaStream(IN const CHAR *pcDownloadID);

/**
* ���¼�����ؽ��ȡ�\n
* @param [IN]    pcDownloadID ����ͨ��ID��
* @param [INOUT] szCurDownPos ��õĵ�ǰ¼�����ؽ��ȵ�ʱ��ֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_GET_DOWN_POSITION    ��õ�ǰ���ؽ���ʧ��
* @note
* -     szCurDownPos������ŵ��ǵ�ǰ¼�����ؽ��ȵľ���ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetCurDownPos(IN const CHAR *pcDownloadID,
                                           OUT CHAR szCurDownPos[IMOS_TIME_LEN]);

/**
* ֹͣ���š�\n
* @param [IN] hXpWnd ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_NOT_START_PLAY               δ�������Ų���
* -         #ERR_XP_FAIL_TO_STOP_MEDIA           ֹͣý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_STOP_PROTOCOL        ֹͣ����Э��
* -         #ERR_XP_FAIL_TO_QUIT_SESSION         �˳��Ựʧ��
* -         #ERR_XP_FAIL_TO_STOP_PLAY            ֹͣ���Ų���ʧ��
* @note ��Ҫ����ֹͣ�㲥�طźͱ����ļ��طš�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopPlay(IN IMOS_HANDLE hXpWnd);
/** @} */  /* end of groupPlayerPlayback */

/** @defgroup groupPlayerLocalFile �����������ļ��ط�
*   �����������ļ��طţ���Ҫ������ͣ�����ļ��طš�ץͼ����ȡý���������ͻطſ��Ƶȡ�
*   @{
*/
/**
* �򿪱��ز����ļ���\n
* @param [IN]  hXpWnd       ���Ŵ��ھ����
* @param [IN]  pcFileName   �����ļ����ļ����������ļ�·������
* @param [OUT] pulTotalTime �����ļ��ܵ�ʱ�䳤�ȡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_WINDOW_NOT_REGISTER          ���Ŵ���û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ���Ŵ��ڱ�ռ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò��Ŵ��ڵ���Դʧ��
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      �ļ����Ÿ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       ����ļ��ܵĲ���ʱ��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_FILE            ���������ļ�����ʧ��(�ļ������ڻ������ڱ���������ʹ��)
* -         #ERR_XP_FILE_DESTROY                 ��Ҫ�򿪵��ļ�̫С�����Ѿ���
* -         #ERR_COMMON_NO_MEMORY                ���ļ�ʱϵͳ�ڴ治��
* -         #ERR_XP_FILE_HAVE_OPEN               ָ��ͨ���Ѿ������ļ�

* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenLocalFile(IN IMOS_HANDLE hXpWnd,
                                           IN const CHAR *pcFileName,
                                           OUT ULONG_32 * const pulTotalTime);
/** @} */  /* end of groupPlayerLocalFile */

/**
* ���������Խ���\n
* @param [IN] pszDstResCode �����Խ��Զ˵���Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_ALREADY_OPEN                ָ����ͨ���Ѿ�����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_OPEN_VOICE_TALKBACK      ���������Խ�ʧ��
* @note ������ָ�������ն˵������Խ���
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenVoiceTalkback(IN const CHAR *pszDstResCode);

/**
* ֹͣ�����Խ���\n
* @param [IN] pszDstResCode �����Խ��Զ˵���Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_NOT_OPEN                    ָ����ͨ��δ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* @note ֹͣ��ָ�������ն˵������Խ���
*/
IMOS_EXPORT ULONG_32 STDCALL XP_CloseVoiceTalkback(IN const CHAR *pszDstResCode);

/**
* ���������㲥��\n
* @param [IN] pszDstResCode �����㲥�Զ˵���Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_ALREADY_OPEN                ָ����ͨ���Ѿ�����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_OPEN_VOICE_BROADCAST     ���������㲥ʧ��
* @note ������ָ�������ն˵������㲥��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_OpenVoiceBroadcast(IN const CHAR *pszDstResCode);

/**
* ֹͣ�����㲥��\n
* @param [IN] pszDstResCode �����㲥�Զ˵���Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_NOT_OPEN                    ָ����ͨ��δ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* @note ֹͣ��ָ�������ն˵������㲥��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_CloseVoiceBroadcast(IN const CHAR *pszDstResCode);

/** @defgroup groupPlayerVoice �����������Խ��͹㲥
*   �����������Խ��͹㲥����Ҫ������ͣ�����Խ��͹㲥����Ƶ���������ƺ��������ڣ�ϵͳ��������˷��������ȡ�
*   @{
*/
/**
* ����ҵ�����������\n
* @param [IN] bSilence �Ƿ������BOOL_TRUE�����ñ�����BOOL_FALSE��ȡ����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_VOICE_SILENCE            ����/ȡ����������ʧ��
* @note ����ҵ�����������ָֹͣ�������Զ˷�����Ƶ���ݡ�Ŀǰ��ͨ��ֹͣ��Ƶ�ɼ��ͱ���ʵ�ִ˹��ܡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_VoiceSilence(IN BOOL_T bSilence);

/**
* ����ҵ����������\n
* @param [IN] bEnabled �Ƿ�����BOOL_TRUE�����þ�����BOOL_FALSE��ȡ����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_NOT_START_VOICE_TALKBACK         ��ǰû�����������Խ�ҵ��
* -         #ERR_XP_FAIL_TO_QUIET                    ����/ȡ����������ʧ��
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_VoiceQuiet(IN BOOL_T bEnabled);

/**
* ��˷��������ڡ�\n
* @param [IN] ulVolume ����ֵ��ȡֵ��ΧΪ0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        �����Ч
* -         #ERR_XP_MIC_NOT_EXIST            ϵͳ����˷����䲻����
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    ������������ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_AdjustMicVolume(IN ULONG_32 ulVolume);

/**
* �����˷�����ֵ��\n
* @param [OUT] pulVolume ����ֵ��ָ�루���ص�����ֵ��ΧΪ0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        �����Ч
* -         #ERR_XP_MIC_NOT_EXIST            ϵͳ����˷����䲻����
* -         #ERR_XP_FAIL_TO_GET_VOLUME       �������ֵʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_GetMicVolume(OUT ULONG_32 *pulVolume);
/** @} */  /* end of groupPlayerVoice */

/**
* ��ʼ������ҵ��\n
* @param [IN] pszVoiceID     ����ҵ��ͨ��ID��
* @param [IN] enVoiceSvcType ����ҵ�����ͣ������㲥�������Խ���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_ALREADY_EXIST               ָ����ͨ���Ѿ����ڣ��Ѿ���ʼ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* @note
* -     pszVoiceID��һ���ַ���ָ�룬����Ψһ��ʶһ������ҵ��ͨ����
*/
IMOS_EXPORT ULONG_32 STDCALL XP_InitVoiceSvc(IN const CHAR *pszVoiceID,
                                          IN XP_VOICE_SERVICE_TYPE_E enVoiceSvcType);

/**
* ��������ҵ��ı��ص�ַ��Ϣ��\n
* @param [IN] pszVoiceID  ����ҵ��ID��
* @param [IN] pszLocalIP  ����ҵ�񱾵�IP��ַ��
* @param [IN] usLocalPort ����ҵ�񱾵ض˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_NOT_EXIST                   ָ����ͨ�������ڣ�ͨ��δ��ʼ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceLocalAddr(IN const CHAR *pszVoiceID,
                                               IN const CHAR *pszLocalIP,
                                               IN USHORT usLocalPort);

/**
* ��������ҵ���Զ�˵�ַ��Ϣ��\n
* @param [IN] pszVoiceID   ����ҵ��ID��
* @param [IN] pszRemoteIP  ����ҵ��Զ��IP��ַ��
* @param [IN] usRemotePort ����ҵ��Զ�˶˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_NOT_EXIST                   ָ����ͨ�������ڣ�ͨ��δ��ʼ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_SetVoiceRemoteAddr(IN const CHAR *pszVoiceID,
                                                IN const CHAR *pszRemoteIP,
                                                IN USHORT usRemotePort);

/**
* ��������ҵ��\n
* @param [IN] pszVoiceID ����ҵ��ID��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_NOT_EXIST                   ָ����ͨ�������ڣ�ͨ��δ��ʼ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_START_VOICE_SVC          ��������ҵ��ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StartVoiceSvc(IN const CHAR *pszVoiceID);

/**
* ֹͣ����ҵ��\n
* @param [IN] pszVoiceID ����ҵ��ID��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_PORT_NOT_EXIST                   ָ����ͨ�������ڣ�ͨ��δ��ʼ����
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_STOP_VOICE_SVC           ֹͣ����ҵ��ʧ��
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL XP_StopVoiceSvc(IN const CHAR *pszVoiceID);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_MEDIA_PLAYER_SDK_OBSOLETE_FUNC_H_ */