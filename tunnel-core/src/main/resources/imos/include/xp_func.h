 /*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_func.h

  Project Code: IMOS XP������
   Module Name: IMOS XP������
  Date Created: 2008-09-10
        Author: shiyouhua/04562
   Description: ������XP�ӿں���ͷ�ļ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_MEDIA_PLAYER_SDK_FUNC_H_
#define _IMOS_XP_MEDIA_PLAYER_SDK_FUNC_H_

/* ��������ƽ̨��ͷ�ļ� */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"
#include "sdk_def.h"
#include "sdk_struct.h"

/* ���������� SDK���ݽṹͷ�ļ� */
#include "xp_datatype.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* ��Ϣ�����쳣��Ϣ�ص�������ָ�����ͣ����½ӿں���IMOS_SetRunMsgCB��ʹ�á�\n
* @param [IN] pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN] ulRunInfoType       ��Ϣ�����쳣��Ϣ���ͣ���Ӧ#XP_RUN_INFO_TYPE_Eö���е�ֵ��
* @param [IN] pParam              �����Ϣ�����쳣��Ϣ���ݵĻ�����ָ�루����ŵ���������Ϣ���쳣��Ϣ�����йأ���
* @return �ޡ�
* @note
* -     1���ͻ���ʵ�ָûص�����ʱ��Ҫȷ���������췵�أ����������������XP�ڲ����øûص��������̡߳�
* -     2������pParam��ʵ�����͸��ݾ������Ϣ�����쳣��Ϣ���Ͷ������ͻ���Ҫ������Ϣ�����쳣��Ϣ��������Ӧ������ת������ĳЩ����£��ò����п���ΪNULL��
* -     ���������ת����ϵ���£�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_SERIES_SNATCH��#XP_RUN_INFO_RECORD_VIDEO��#XP_RUN_INFO_MEDIA_PROCESS��
* -                            #XP_RUN_INFO_RTSP_PROTOCOL��#XP_RUN_INFO_PASSIVE_MONITOR��#XP_RUN_INFO_DOWN_MEDIA_PROCESS
* -                            ��#XP_RUN_INFO_DOWN_RTSP_PROTOCOLʱ���轫pParamָ��ת��Ϊ#XP_RUN_INFO_EX_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_SIP_LIVE_TIMEOUTʱ��pParamָ��ΪNULL��
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_VOICE_MEDIA_PROCESSʱ���轫pParamָ��ת��Ϊ#XP_VOICE_RUN_INFO_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_PASSIVE_START_MONITORʱ���轫pParamָ��ת��Ϊ#XP_START_MONITOR_RUN_INFO_S�ṹ��ָ�����͡�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_MEDIA_NOT_IDENTIFYʱ���轫pParamָ��ת��Ϊ#XP_RUN_INFO_EX_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_RECV_PACKET_NUMʱ���轫pParamָ��ת��Ϊ#XP_RECV_PACKET_NUM_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_RECV_BYTE_NUMʱ���轫pParamָ��ת��Ϊ#XP_RECV_BYTE_NUM_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_VIDEO_FRAME_NUMʱ���轫pParamָ��ת��Ϊ#XP_VIDEO_FRAME_NUM_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_AUDIO_FRAME_NUMʱ���轫pParamָ��ת��Ϊ#XP_AUDIO_FRAME_NUM_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_LOST_PACKET_RATIOʱ���轫pParamָ��ת��Ϊ#XP_LOST_PAKCET_RATIO_S�ṹ��ָ�����ͣ�
* -         ��ulRunInfoTypeֵΪ#XP_RUN_INFO_MEDIA_ABNORMALʱ���轫pParamָ��ת��Ϊ#XP_RUN_INFO_EX_S�ṹ��ָ�����ͣ�
*/
typedef VOID (STDCALL* XP_RUN_INFO_CALLBACK_EX_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN ULONG_32 ulRunInfoType,
                                                   IN VOID *pParam);

/**
* ƴ֡ǰý�������ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pBuffer               ���ƴ֡ǰý�������ݻ�����ָ�롣
* @param [IN] ulBufSize             ��������С��
* @param [IN] ulMediaDataType       ý�����������ͣ���Ӧ#XP_MEDIA_DATA_FORMAT_Eö���е�ֵ��
* @param [IN] lUserParam            �û����ò������û��ڵ���IMOS_SetSourceMediaDataCB����ʱָ�����û�������
* @param [IN] lReserved             ���ƴ֡ǰý������չ��Ϣ������ָ�룬�û���Ҫת��Ϊ#XP_SOURCE_DATA_EX_INFO_S
*                                   �ṹ��ָ�����ͣ��ں���������ǩ��DecoderTag�������û�ʹ�ò��ſ�������ʾ�ص�
*                                   ��ý����ʱ���ɸ��ݽ�������ǩָ����������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ���������ý�������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* XP_SOURCE_MEDIA_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN const UCHAR *pBuffer,
                                                         IN ULONG_32 ulBufSize,
                                                         IN ULONG_32 ulMediaDataType,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved);

/**
* ת����ý�������ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pBuffer               ���ƴ֡ǰý�������ݻ�����ָ�롣
* @param [IN] ulBufSize             ��������С��
* @param [IN] lUserParam            �û����ò������û��ڵ���#IMOS_SetSourceMediaDataCB����ʱָ�����û�������
* @param [IN] lReserved             Ԥ������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ���������ý�������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* XP_TRANSCODE_MEDIA_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                            IN const CHAR *pcChannelCode,
                                                            IN const UCHAR *pBuffer,
                                                            IN ULONG_32 ulBufSize,
                                                            IN LONG_REAL lUserParam,
                                                            IN LONG_REAL lReserved);

/**
* ƴ֡����Ƶ�����ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pstParseVideoData     ���ƴ֡����Ƶ��������Ϣ������ָ��
* @param [IN] lUserParam            �û����ò������û��ڵ���#IMOS_SetParseVideoDataCB����ʱָ�����û�������
* @param [IN] lReserved             ����������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ���������ý�������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL *XP_PARSE_VIDEO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcChannelCode,
                                                        IN const XP_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                        IN LONG_REAL lUserParam,
                                                        IN LONG_REAL lReserved);

/**
* ƴ֡����Ƶ�����ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pstParseAudioData     ���ƴ֡����Ƶ��������Ϣ������ָ��
* @param [IN] lUserParam            �û����ò������û��ڵ���#IMOS_SetParseAudioDataCB����ʱָ�����û�����
* @param [IN] lReserved             ��������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ������������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL *XP_PARSE_AUDIO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcChannelCode,
                                                        IN const XP_PARSE_AUDIO_DATA_S *pstParseAudioData,
                                                        IN LONG_REAL lUserParam,
                                                        IN LONG_REAL lReserved);

/**
* �������Ƶ�����ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo   �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode        ����ͨ�����롣
* @param [IN] pstPictureData       ��Ž������Ƶ��������Ϣ������ָ�롣
* @param [IN] lUserParam           �û����ò������û��ڵ���#IMOS_SetDecodeVideoDataCB����ʱָ�����û�������
* @param [IN] lReserved            ����������
* @return �ޡ�
* @note
* -     1���û�Ӧ��ʱ�����������Ƶ�����ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
* -     2����Ƶ������yv12��ʽ������˳��Y0-Y1-......������U0-U1-......������V0-V1-......����
*/
typedef VOID (STDCALL* XP_DECODE_VIDEO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN const XP_PICTURE_DATA_S *pstPictureData,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved);

/**
* �������Ƶ�����ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pstWaveData           ��Ž������Ƶ��������Ϣ������ָ�롣
* @param [IN] lUserParam            �û����ò������û��ڵ���#IMOS_SetDecodeAudioDataCB����ʱָ�����û�������
* @param [IN] lReserved             ����������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ�����������Ƶ�����ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* XP_DECODE_AUDIO_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN const CHAR *pcChannelCode,
                                                         IN const XP_WAVE_DATA_S *pstWaveData,
                                                         IN LONG_REAL lUserParam,
                                                         IN LONG_REAL lReserved);
/**
* ����ǰ�������ݻص�������ָ�����͡�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pucVoiceDataBuffer    ��Ž���ǰ����������Ϣ������ָ��
* @param [IN] ulBufSize             ��Ƶ���ݴ�С
* @param [IN] ulAudioFlag           ��Ƶ��������,���#XP_AUDIO_FLAG_Eö����ȡֵ
* @param [IN] pUserParam            �û����ò���
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ�����������Ƶ�����ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* XP_PARSE_VOICE_DATA_CALLBACK_PF)(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const UCHAR *pucVoiceDataBuffer,
                                                        IN ULONG_32 ulBufSize,
                                                        IN ULONG_32 ulAudioFlag,
                                                        IN LONG_REAL lUserParam);

/**
* DDraw����hdc�ص�������ָ�����͡�\n
* @param [IN] ulPort         ����ͨ����
* @param [IN] pHDC           ���ddraw����DC�����ָ��
* @param [IN] lUserParam     �û����ò��������û��ڵ���#IMOS_XP_SetDisplayHdcCB����ʱָ�����û�����
* @param [IN] lReserved      ��������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ����������豸������ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
* -     �ûص�������������ͨƷ�ʺ͵�Ʒ��ʱʹ�á�
* -     ������������£����ܵ���HDC��ʧ��ʹ��ʱ���ж�pHDC�Ƿ�ΪNULL��
* -     ʹ��ʱ�ɽ�pHDC����(HDC) (*(HDC* )pHDC)ת��ΪHDCʹ�á�
*/
typedef VOID (STDCALL* XP_PLAYER_HDC_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                  IN const VOID *pHDC,
                                                  IN LONG_REAL lUserParam,
                                                  IN LONG_REAL lReserved);
/** @defgroup groupStartPlayer ����������ʱ������Ϣ
*   ��������Ƶ��ʾģʽ����Ƶ���ظ�ʽ�ͽ�����Ϣ�����쳣��Ϣ�Ļص������ȡ�
*   @{
*/
/**
* ������Ƶ��ʾģʽ��\n
* @param [IN] ulRenderMode ��Ƶ��ʾģʽ�����#XP_RENDER_MODE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ��������Ƿ�
* @note
* - 1���ڲ����ô˽ӿں���������Ƶ��ʾģʽ������£���Ĭ��ʹ��D3D��ʾģʽ��
* - 2���Ƽ�������������ʱ���á�
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRenderMode(IN ULONG_32 ulRenderMode);

/**
* ������Ƶ���ظ�ʽ��֧��YUV420��RGB32������Ƶ���ظ�ʽ��\n
* @param [IN] ulPixelFormat ��Ƶ���ظ�ʽ�����#XP_PIXEL_FORMAT_EX_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ��������Ƿ�
* @note
* - 1���ڲ����ô˺����ӿں���������Ƶ���ظ�ʽ������£���Ĭ��ʹ��YUV420��Ƶ���ظ�ʽ��
* - 2���Ƽ�������������ʱ���á�
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPixelFormat(IN ULONG_32 ulPixelFormat);

/**
* ����ʵʱ����ʱͼ��������ԡ�\n
* @param [IN] ulFluency             ����ʵʱ����ʱͼ����ʵʱ�����Ȼ������������ȣ����#XP_PICTURE_FLUENCY_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ��������Ƿ�
* @note
* - 1���˽ӿں�����������ʵʱ����ʱͼ��������ԣ��Իط�ʱͼ��������ý��������ã���Ϊ�ط�Ĭ��ʹ��ͼ�����������ȣ�
* - 2���ڲ����ô˽ӿں�������ʵʱ���ŵ�ͼ��������ʱ����Ĭ��ʹ��ͼ��ʵʱ�����ȣ�
* - 3�����ö�����ʵʱͨ����Ч����������������ʱ���ã�Ҳ����ÿ������һ·ʵʱ����֮ǰ���á�
* - 4���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRealtimeFluency(IN ULONG_32 ulFluency);

/**
* ���ý�����Ϣ�����쳣��Ϣ�Ļص�������\n
* @param [IN] pfRunInfoFunc ��Ϣ�����쳣��Ϣ�ص�������ָ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* @note
* - 1���û����������ø���������Ļص�������ֱ�ӵ��ò��������κνӿں�����
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRunMsgCB(IN XP_RUN_INFO_CALLBACK_EX_PF pfnRunInfoFunc);

/**
* ��ѯ�������Ƿ���NAT������\n
* @param [IN] �ޡ�
* @return
* -         #BOOL_TRUE          XP��NAT����
* -         #BOOL_FALSE         XP����NAT����
* @note
* - 1��ֻ��������������֮����ã�����׼ȷ��ѯ���������Ƿ���NAT������
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_IsInNat();

/**
* ��ѯ�û���Ӧ�Ĳ������Ƿ���NAT������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @return
* -         #BOOL_TRUE          XP��NAT����
* -         #BOOL_FALSE         XP����NAT����
* @note ֻ����ע�Ქ����֮����ã�����׼ȷ��ѯ���������Ƿ���NAT������
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_IsInNatEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo);
/** @} */  /* end of groupStartPlayer */

/** @defgroup groupPlayerRealtime ʵʱ���ţ���������
*   ʵ��ʵʱ���Ź��ܡ�����ץͼ������¼��ʵʱ�����ݲ������������Լ���ȡý����ͳ����Ϣ�ȹ��ܡ�
*   @{
*/
/**
* ���ò�����Ƶ�Ĵ��ھ����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] hWnd               ���Ŵ��ھ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* @note
* - 1������ʵ�����㲥�طźͱ����ļ��ط�ʱ���ò�����Ƶ�Ĵ��ھ����
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlayWnd(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          IN IMOS_HANDLE hWnd);

/**
* ���ò��Ŵ�������Ƶͼ����ʾ������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulRenderScale      ��Ƶͼ���ڲ��Ŵ����ϵ���ʾ���������#XP_RENDER_SCALE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_RENDER_SCALE        ����ͼ����ʾ��������ʧ��
* @note
* - 1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ������������Ŵ��ڣ�
* - 2������������֮ǰ���øýӿ�ʱ�������õ���ʾ���������ں��������ò���ͨ������ʱ��Ч��
* - 3���ڲ��Ź����е��øýӿ�ʱ�������õ���ʾ��������ʵʱ��Ч��
* - 4�����øýӿڶ�ָ������ͨ�����õ���ʾ���������ڲ����������ڼ�һֱ��Ч��
* - 5���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRenderScale(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcChannelCode,
                                              IN ULONG_32 ulRenderScale);

/**
* ����ץ��ͼƬ������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulPictureQuality       ͼƬ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           �����Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPictureQuality(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const ULONG_32 ulPictureQuality);


/**
* ����ͼ��ĶԱȶȲ�������ʱ�����á�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulContrastMode     ͼ��Աȶ�ģʽ�����#XP_PICTURE_CONTRAST_MODE_Eö����ȡֵ��
* @param [IN] ulContrastLevel    ͼ��Աȶȼ������#XP_PICTURE_CONTRAST_LEVEL_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER        ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST ����ͨ����֧������ͼ��ԱȶȲ���
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     ����ͼ��ԱȶȲ���ʧ��
* @note
* - 1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ�ϲ����жԱȶȵ��ڴ���
* - 2�������ڿ�ʼ����#IMOS_StartPlay֮ǰ���ã������õĶԱȶȲ��������棬��Ϊ������ͨ������ʱ
* -    �ĳ�ʼֵ���ڿ�ʼ���ź���øýӿ����õĶԱȶȲ�����ʱ�����ã�
* - 3�����øýӿڶ�ָ������ͨ�����õĶԱȲ����ڲ����������ڼ�һֱ��Ч��������ulContrastMode
* -    ����#XP_PICTURE_CONTRAST_MODE_NONEʱ����ֹͣ�Աȶȵ��ڴ�����ʱulContrastLevel������
* -    ���ֵ��Ч��
* - 4���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPictureContrast(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulContrastMode,
                                                  IN ULONG_32 ulContrastLevel);

/**
* ���ý��볡ģʽ��\n
* @param [IN] pstUserLoginIDInfo   �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode        ����ͨ�����롣
* @param [IN] ulFieldMode          ��ģʽ�����#XP_FIELD_MODE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_SET_FIELD_MODE       ���ý��볡ģʽʧ��
* @note
* - 1��MPEG4û�г��ĸ��
* - 2��������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øýӿں������ý��볡ģʽ��
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFieldMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN ULONG_32 ulFieldMode);

/**
* ����ȥ��֯����ģʽ��\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [IN] ulDeinterlaceMode       ȥ��֯����ģʽ�����#XP_DEINTERLACE_MODE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_ENABLE_DEINTERLACE       ������ر�ȥ��֯����ʧ��
* @note
* - 1���ڲ����øýӿڵ�����£�Ĭ��ʹ�û��ģʽ����ȥ��֯����
* - 2��������ʵ�����㲥�طŻ򱾵��ļ��ط�֮����øýӿں���������ر�ȥ��֯����
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDeinterlaceMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN ULONG_32 ulDeinterlaceMode);

/**
* ������Ƶ����Դ��\n
* @param [IN] ulWaveInSource     ��Ƶ����Դ��������Ƶ�ɼ��豸#XP_WAVEIN_SOURCE_DEVICE����Ƶ�ļ�#XP_WAVEIN_SOURCE_FILE
                                 �Լ��û�������Ƶ����#XP_WAVEIN_SOURCE_INPUT������Ƶ����Դ�����#XP_WAVEIN_SOURCE_Eö����ȡֵ��
* @param [IN] pWaveInParameter   ������Ϣ����������Ƶ����ԴΪ#XP_WAVEIN_SOURCE_FILEʱ����Ҫʹ��#XP_WAVEIN_FILE_INFO_S�ṹ�������Ӳ�����
*                                ����Ƶ����ԴΪ#XP_WAVEIN_SOURCE_DEVICEʱ���ò�������NULL��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_SET_WAVEIN_MOD           ������Ƶ����Դ�빤��ģʽʧ��
* @note
* - 1���ڲ����øýӿں���������£�Ĭ�ϲ�����Ƶ�ɼ��豸��Ϊ����Դ��
* - 2����������Ƶ�ļ���Ϊ��Ƶ����Դʱ��Ҫ���븽����Ϣ���ο�#XP_WAVEIN_FILE_INFO_S�ṹ�壻
* - 3����Ƶ�ļ�ֻ֧��8000������+16λ����+��������wave��ʽ��Ƶ�ļ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetWaveInSourceMode(IN ULONG_32 ulWaveInSource,
                                                   IN VOID *pWaveInParameter);

/**
* ����ƴ֡ǰý�������ݻص�������\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [IN] pfnSourceMediaDataCBFun ƴ֡ǰý�������ݻص�������ָ�롣
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
*      #IMOS_StartMonitor֮ǰ����֮����Ҫ�������ã��㲥�ط�ʱ���ú�������IMOS_OpenVodStream֮ǰ���ã�Ҳ��
*      ��#IMOS_OpenVodStream��#IMOS_StartPlay֮����ã���������#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ��
*      ��ʧЧ���´������㲥�ط�ʱ��Ҫ����ͬλ���������ã����ػط�ʱ���ú�������#IMOS_OpenFile֮ǰ���ã�
*      Ҳ����#IMOS_OpenFile��#IMOS_StartPlay֮����ã���������#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ��
*      ��ʧЧ���´��������ػط�ʱ��Ҫ����ͬλ���������ã�
* - 2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��#XP_SOURCE_MEDIA_DATA_CALLBACK_PF��ΪNULL��
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSourceMediaDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                    IN BOOL_T bContinue,
                                                    IN LONG_REAL lUserParam);

/**
* ����ƴ֡����Ƶ���ݻص�������\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [IN] pfnParseVideoDataCBFun  ƴ֡����Ƶ���ݻص�������ָ�롣
* @param [IN] bContinue               �Ƿ����������Ƶ����Ͳ��Ų�����
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
*      ��ʧЧ���´������㲥�ط�ʱ��Ҫ����ͬλ���������ã�
* - 2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��#XP_PARSE_VIDEO_DATA_CALLBACK_PF��ΪNULL��
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetParseVideoDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN XP_PARSE_VIDEO_DATA_CALLBACK_PF pfnParseVideoDataCBFun,
                                                   IN BOOL_T bContinue,
                                                   IN LONG_REAL lUserParam);

/**
* ����ƴ֡����Ƶ���ݻص�������\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [IN] pfnParseAudioDataCBFun  ƴ֡����Ƶ���ݻص�������ָ�롣
* @param [IN] bContinue               �Ƿ����������Ƶ����Ͳ��Ų�����
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
*      ��ʧЧ���´������㲥�ط�ʱ��Ҫ����ͬλ���������ã�
* - 2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��#XP_PARSE_AUDIO_DATA_CALLBACK_PF��ΪNULL��
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetParseAudioDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode,
                                                   IN XP_PARSE_AUDIO_DATA_CALLBACK_PF pfnParseAudioDataCBFun,
                                                   IN BOOL_T bContinue,
                                                   IN LONG_REAL lUserParam);

/**
* ���ý������Ƶ�����ݻص�������\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode             ����ͨ�����롣
* @param [IN] pfnDecodeVideoDataCBFun   �������Ƶ�����ݻص�������ָ�롣
* @param [IN] bContinue                 �Ƿ�������к������Ƶ��ʾ������
* @param [IN] lUserParam                �û����ò�����
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
*      Ҳ����#IMOS_OpenFile��#IMOS_StartPlay֮����ã���������#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ��
*      ��ʧЧ���´��������ػط�ʱ��Ҫ����ͬλ���������ã�
* - 2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��#XP_DECODE_VIDEO_DATA_CALLBACK_PF��ΪNULL��
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDecodeVideoDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN XP_DECODE_VIDEO_DATA_CALLBACK_PF pfnDecodeVideoDataCBFun,
                                                    IN BOOL_T bContinue,
                                                    IN LONG_REAL lUserParam);

/**
* ���ý������Ƶ�����ݻص�������\n
* @param [IN] pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode            ����ͨ�����롣
* @param [IN] pfnDecodeAudioDataCBFun  �������Ƶ�����ݻص�������ָ�롣
* @param [IN] bContinue                �Ƿ�������к������Ƶ���Ų�����
* @param [IN] lUserParam               �û����ò�����
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
*      Ҳ����#IMOS_OpenFile��#IMOS_StartPlay֮����ã���������#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ��
*      ��ʧЧ���´��������ػط�ʱ��Ҫ����ͬλ���������ã�
* - 2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��#XP_DECODE_AUDIO_DATA_CALLBACK_PF��ΪNULL��
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDecodeAudioDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode,
                                                    IN XP_DECODE_AUDIO_DATA_CALLBACK_PF pfnDecodeAudioDataCBFun,
                                                    IN BOOL_T bContinue,
                                                    IN LONG_REAL lUserParam);

/**
* ����ʵʱץ�ģ������������û�ָ���ĵ�ͼ���ļ����󸽼�ץ��ϵͳʱ�䡣\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         Ҫ�����ͼ���ļ����ļ�����������չ���������������ڴ��ļ����󸽼�ץ��ϵͳʱ�䡣
* @param [IN] ulPicFormat        ͼ���ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
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
* - 1�������������û�ָ�����ļ������渽��������"20080928(13-10-50-99)"��ʽ��ץ��ϵͳʱ�䣻
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchOnce(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          IN const CHAR *pcFileName,
                                          IN ULONG_32 ulPicFormat);

/**
* ����ʵʱץ�ģ�ץȡ��ͼ���ļ���ȫ�����û�ָ����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         Ҫ�����ͼ���ļ����ļ�����������չ�������ļ���ȫ�����û�ָ����
* @param [IN] ulPicFormat        ͼ���ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
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
* - 1���û���ȷ����ͬһץ�ı���·���£�ץ��ͼ���ļ�������������
* - 2�������������û�ָ����ͼ���ļ����󸽼��Ϻ�׺����
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SnatchOnceEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN const CHAR *pcFileName,
                                            IN ULONG_32 ulPicFormat);

/**
* ��������ʵʱץ�ġ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         ͼ���ļ���ŵ�·���������ļ�����������չ������
* @param [IN] ulPicFormat        ͼ���ļ��ĸ�ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @param [IN] ulInterval         ץ�ļ������λΪ���� ; 0xFFFFFFFF ��ʾץ��ÿ��I֡
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartSnatchSeries(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 IN const CHAR *pcFileName,
                                                 IN ULONG_32 ulPicFormat,
                                                 IN ULONG_32 ulInterval);

/**
* ֹͣ����ʵʱץ�ġ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_START_SERIES_SNATCH      ����ͨ��δ��������ץ�Ĳ���
* -         #ERR_XP_FAIL_TO_STOP_SERIES_SNATCH   ֹͣ����ץ�Ĳ���ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopSnatchSeries(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode);

/**
* ��������¼��¼���ļ����ɲ��������ɡ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         ¼���ļ����·�����������ļ�������·�����治��б�ܣ���
* @param [IN] ulFileFormat       ¼���ļ��ĸ�ʽ�����#XP_MEDIA_FILE_FORMAT_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                    ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                    ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                       ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           ����ͨ���Ѿ�����¼�����
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      ¼���ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             Ӳ�̿ռ䲻��
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 ��ǰ��������ͣ����״̬
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         ��ǰ�����ڱ��ٲ���״̬
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  ��ǰ�����ڵ�֡����״̬
* -         #ERR_XP_NOT_SUPPORT                          ��֧�ָù���
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           ��������¼��ʧ��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE        ����ͨ����ý��������Ͳ�֧�ָò���
* @note
* - 1����������¼���ļ�����������Ϊ�����������-ͨ����-S��ʼʱ��E����ʱ�䣬ʱ�������硰YYYYMMDDHHMMSSMS��
* -    ��ʽ��ʱ��ֵ��ɣ����磺Cam0001-00-S20100316094658286E20100316094806084��
* - 2�����㲥�طŻ򱾵��ļ��طŴ�����ͣ���š����ٲ��Ż�֡����״̬ʱ����֧����������¼�������
* - 3������¼�����¼������У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ�¼����Ϣ#XP_RUN_INFO_RECORD_VIDEO��Я���Ĵ����룺
* -     #ERR_XP_DISK_CAPACITY_WARN              �������ڼ���¼��
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_FAIL_TO_WRITE_FILE              �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* - 4���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartRecord(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           IN const CHAR *pcFileName,
                                           IN ULONG_32 ulFileFormat);

/**
* ��������¼��¼���ļ���ȫ�����û�ָ����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         Ҫ�����¼���ļ�����������չ�������ļ���ȫ�����û�ָ����
* @param [IN] ulFileFormat       ¼���ļ��ĸ�ʽ�����#XP_MEDIA_FILE_FORMAT_Eö����ȡֵ��
* @param [OUT] pcFilePostfix     ���¼���ļ���׺��ָ�룬����������Ӧ��С��#IMOS_XP_FILE_POSTFIX_LEN��
*                                ����û�����Ҫ���غ�׺�����ɽ��ò�������ΪNULL��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                    ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                    ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                       ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           ����ͨ���Ѿ�����¼�����
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      ¼���ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             Ӳ�̿ռ䲻��
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 ��ǰ��������ͣ����״̬
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         ��ǰ�����ڱ��ٲ���״̬
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  ��ǰ�����ڵ�֡����״̬
* -         #ERR_XP_NOT_SUPPORT                          ��֧�ָù���
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           ��������¼��ʧ��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE        ����ͨ����ý��������Ͳ�֧�ָò���
* @note
* - 1���û���ȷ����ͬһ¼�񱣴�·���£�¼���ļ�������������
* - 2�����㲥�طŻ򱾵��ļ��طŴ�����ͣ���š����ٲ��Ż�֡����״̬ʱ����֧����������¼�������
* - 3�������������û�ָ����¼���ļ����󸽼��Ϻ�׺����
* - 4������¼�����¼������У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ�¼����Ϣ#XP_RUN_INFO_RECORD_VIDEO��Я���Ĵ����룺
* -     #ERR_XP_DISK_CAPACITY_WARN              �������ڼ���¼��
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_FAIL_TO_WRITE_FILE              �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         �ϱ���Ϣ֮ǰ��������ֹͣ¼��
* - 5���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartRecordEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcFileName,
                                             IN ULONG_32 ulFileFormat,
                                             OUT CHAR *pcFilePostfix);

/**
* ֹͣ����¼��\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                    ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                    ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                       ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_START_RECORD_VIDEO               ����ͨ��δ��������¼�����
* -         #ERR_XP_FAIL_TO_STOP_RECORD_VIDEO            ֹͣ����¼��ʧ��
* @note
* - 1���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopRecord(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);

/**
* �����Ƶ�����ʽ��\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @param [OUT] pulVideoEncodeType     ��Ƶ�����ʽ�����#XP_VIDEO_ENCODE_TYPE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES           ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER              ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                 ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE  �����Ƶ�����ʽʧ��
* @note
* - 1��ֻ����ʵ�����㲥�طŻ򱾵��ļ��طſ�ʼ�����׼ȷ��ȡ��ָ��ͨ������Ƶ�����ʽ��
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetVideoEncodeType(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  OUT ULONG_32 *pulVideoEncodeType);

/**
* ��ö����ʡ�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [OUT] pulRecvPktNum        �ѽ��յ�������
* @param [OUT] pulLostPktNum        ����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_LOST_PKT_RATE    ��ö�����ͳ������ʧ��
* @note
* - 1��ֻ����ʵ�����㲥�طŻ򱾵��ļ��طſ�ʼ֮�����׼ȷ���ָ������ͨ���Ķ����ʣ�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLostPacketRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN const CHAR *pcChannelCode,
                                                 OUT ULONG_32 *pulRecvPktNum,
                                                 OUT ULONG_32 *pulLostPktNum);

/**
* ��λ�����ʡ�\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE      ��λ������ͳ��ʧ��
* @note
* - 1�����øú����󣬽��Ӹ�λʱ�����¿�ʼͳ�ƶ����ʣ�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetLostPacketRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcChannelCode);

/**
* ��ö�֡�ʡ�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [OUT] pulAllFrameNum       ֡������
* @param [OUT] pulLostFrameNum      ������֡����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE  ��ö�֡��ͳ������ʧ��
* @note
* - 1��ֻ����ʵ�����㲥�طŻ򱾵��ļ��طſ�ʼ֮�����׼ȷ���ָ������ͨ���Ķ�֡�ʣ�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetLostFrameRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                OUT ULONG_32 *pulAllFrameNum,
                                                OUT ULONG_32 *pulLostFrameNum);
/**
* ��λ��֡�ʡ�\n
* @param [IN] pstUserLoginIDInfo      �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode           ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE    ��λ��֡��ͳ��ʧ��
* @note
* - 1�����øú����󣬽��Ӹ�λʱ�����¿�ʼͳ�ƶ�֡�ʣ�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResetLostFrameRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode);

/**
* ���֡�ʡ�\n
* @param [IN] pstUserLoginIDInfo   �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode        ����ͨ�����롣
* @param [OUT] pulFrameRate        ֡�ʣ���λΪfps��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨδ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_FRAME_RATE       ���֡������ʧ��
* @note
* - 1��ֻ����ʵ�����㲥�طŻ򱾵��ļ��طſ�ʼ֮�����׼ȷ���ָ������ͨ����֡�ʣ�
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFrameRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            OUT ULONG_32 *pulFrameRate);

/**
* ������ʡ�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [OUT] pulBitRate           ���ʣ���λΪbps��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý��ҵ�����Ͳ�֧�ִ˲���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_BIT_RATE         �����������ʧ��
* @note
* - 1��ֻ����ʵ����㲥�طſ�ʼ֮�����׼ȷ���ָ������ͨ�������ʣ�
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetBitRate(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode,
                                          OUT ULONG_32 *pulBitRate);

/**
* ��������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_DECODE_AUDIO_NOT_CONTINUE        ��Ƶ�����ݽ���󲻼������в��Ų���
* -         #ERR_XP_FAIL_TO_QUIET                    ����������ʧ��
* @note
* - 1��ͬһʱ��ֻ����һ·��������������Ѿ��������򿪣����Զ��ر�ԭ���Ѿ��򿪵�������Ĭ��
* -    ����������ǹرյģ�
* - 2�����øú���ʱ���������#ERR_XP_DECODE_AUDIO_NOT_CONTINUE�����룬����Ϊ�û��ڵ���
* -    #IMOS_SetDecodeAudioDataCB����ʱ��bContinue����ΪBOOL_FALSE��ԭ������ģ�Ҳ����˵��
* -    #IMOS_SetDecodeAudioDataCB�����Ľ������Ƶ�������Ƿ񲥷Ź��ܵ����ȼ����ڱ��������ܣ�
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PlaySound(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* �ر�������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_QUIET                    �ر���������ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopSound(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* ��������������������������\n
* @param [IN] ulVolume ����ֵ��ȡֵ��0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    ������������ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetVolume(IN ULONG_32 ulVolume);

/**
* ��õ�ǰ���õ�����ֵ��\n
* @param [OUT] pulVolume ����ֵ��ָ�루���ص�����ֵȡֵ��0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_VOLUME       �������ֵʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetVolume(OUT ULONG_32 *pulVolume);

/**
* ��������ͨ����Ƶ���ݵ�WAVE���Σ����Ըı�����ͨ�����������Ĵ�С��\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] ulCoefficient      �����Ĳ�������Χ��0��255��255Ϊ����������ֵ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    ������������ʧ��
* @note
* - 1����������#IMOS_SetVolume�����Ĳ�֮ͬ�����ڣ����ǵ�������ͨ��������ʵʱ���š��طź�������
* -    �������ݵ�WAVE���Σ�ֻ������ͨ�������ã���#IMOS_SetVolume�ǵ�����������������������ϵͳ�����ã�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AdjustAllWaveAudio(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN ULONG_32 ulCoefficient);
/** @} */  /* end of groupPlayerRealtime */

/** @defgroup groupPlayerPlayback �㲥�طţ���������
*   ʵ�ֵ㲥�طź�����¼����ع��ܣ�����ץͼ������¼�񡢻ط�¼���ļ�ʱ���ݲ��񡢻طſ��ơ�¼���ļ����ء�
*   ���������Լ���ȡý���������ȹ��ܡ�
*   @{
*/
/**
* �򿪵㲥�ط�ý������\n
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
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcVodUrl,
                                             IN const CHAR *pcServerIP,
                                             IN USHORT usServerPort,
                                             IN ULONG_32 ulProtl);

/**
* �ط���ǽ��\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] ulProtl               ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenVodToTv(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
											  IN const CHAR *pcChannelCode,
											  IN ULONG_32 ulProtl);

/**
* ����ͨ���������ĳ��̱�ʶ��\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcDecoderTag       ͨ���������ĳ��̱�ʶ������#IMOS_GetRecordFileURL������ȡ���μ�
*                                #IMOS_GetRecordFileURL������ʹ��˵����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* @note
* - 1������û�û�е��øú�������ָ��ͨ���������ĳ��̱�ʶ�����ͨ��Ĭ��ʹ��H3C V3��TS��װ�����Ľ�������
* - 2�������ڵ㲥�ط�ʱ����ͨ���������ĳ��̱�ʶ��
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDecoderTag(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcDecoderTag);

/**
* ����ָ��ͨ�������ַŴ��ܡ�\n
* @param [IN] pstUserLoginIDInfo       �û���¼��Ϣ
* @param [IN] pcChannelCode            ͨ������
* @param[IN]    horizon                ˮƽת�� (-360 ȡֵΪ  360����λ��)
* @param[IN]    vectal                 ��ֱת�� (-360 ȡֵΪ  360����λ��)
* @param[IN]    zoom                   �Ŵ���С    (-1��ʾ��С5%,0��ʾ��������1��ʾ����5%)
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_SUPPORT                  ��֧�ָù���
* @note
* - 1���ýӿں�����֧��Windows��
*/

IMOS_EXPORT ULONG_32 STDCALL IMOS_SetSceneControl(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
													 IN const CHAR *pcChannelCode,
													 IN const LONG_32 lHorizon,
													 IN const LONG_32 lVectal,
													 IN const LONG_32 lZoom);
													 
/**
* ��ʼ���š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_OPEN                ����ͨ��δ����ý��ҵ��
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲���ʧ��
* -         #ERR_XP_FAIL_TO_START_PLAY           ��ʼ����ʧ��
* @note
* - 1����Ҫ���ڿ�ʼ�㲥�طźͱ����ļ��طţ�
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartPlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* ��ͣ���š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_PAUSE_MEDIA          ��ͣý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_PAUSE_PROTOCOL       ����Э����ͣʧ��
* -         #ERR_XP_FAIL_TO_PAUSE                ��ͣ���Ų���ʧ��
* @note
* - 1���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_PausePlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);

/**
* �ָ����ţ��ָ���������ͣ��ͨ����\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲���ʧ��
* -         #ERR_XP_FAIL_TO_RESUME_MEDIA         �ָ�ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_RESUME               �ָ����Ų���ʧ��
* @note
* - 1���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ResumePlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);

/**
* ֹͣ���š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_STOP_MEDIA           ֹͣý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_STOP_PROTOCOL        ֹͣ����Э��
* -         #ERR_XP_FAIL_TO_QUIT_SESSION         �˳��Ựʧ��
* -         #ERR_XP_FAIL_TO_STOP_PLAY            ֹͣ���Ų���ʧ��
* @note
* - 1����Ҫ����ֹͣ�㲥�طźͱ����ļ��طţ�
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopPlay(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCodel);

/**
* ���ò����ٶȣ����Ե��������ٶȣ�ʹ�䱶��ǰ�����ߺ��˲��š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulPlaySpeed        �����ٶȣ����#XP_PLAY_STATUS_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY   ����ǰ��/���˲���ʧ��
* @note
* - 1�����ڱ���¼��ʱ����֧�ֱ���ǰ��/���˲��Ų�����
* - 2���㲥�ط�ʱ����֧��1/2��1/4���ٺ��˲��ţ������ļ�����ʱ����֧�ֺ��˲��ţ�
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlaySpeed(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcChannelCode,
                                            IN ULONG_32 ulPlaySpeed);

/**
* ��֡���š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_STEP_PLAY            ��֡����ʧ��
* @note
* - 1��Ŀǰ�ýӿڽ�֧�ֵ㲥�ط�ʱ��֡���ţ������ļ��ط�ʱ�ݲ�֧�ֵ�֡���ţ�
* - 2�����ڱ���¼��ʱ����֧�ֵ�֡���Ų�����
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OneByOne(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode);

/**
* ��֡���š�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_STEP_PLAY            ��֡����ʧ��
* @note
* - 1��Ŀǰ�ýӿڽ�֧�ֵ㲥�ط�ʱ��֡���ţ������ļ��ط�ʱ�ݲ�֧�ֵ�֡���ţ�
* - 2�����ڱ���¼��ʱ����֧�ֵ�֡���Ų�����
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AutoOneByOne(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
										   IN const CHAR *pcChannelCode);
										
										
/**
* ����ʱ�䣨�ַ����ͣ������ļ�����λ�á�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcTime             �����ļ�����λ�õ�ָ��ʱ�䡣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            ��ת����ʧ��
* @note
* - 1�����ڲ�ͬ��Ӧ�ã�pcTime����ȡֵӦ��ͬ��
* -   ��1�������ļ��ط�ʱ���ò�����ֵӦΪ���ʱ�䣬������ļ�ͷ�Ĳ���ʱ�䣨��λΪ�룩��
* -   ��2���㲥�ط�ʱ���ò�����ֵӦΪ����ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* - 2�����ڱ���¼��ʱ�򣬲�֧�ָ���ʱ�������ļ�����λ�ò�����
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlayedTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             IN const CHAR *pcTime);

/**
* ����ʱ�䣨���ͣ������ļ�����λ�á�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] ulTime             �����ļ�����λ�õ�ָ��ʱ�䡣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_DRAG_PLAY            ��ת����ʧ��
* @note
* - 1�����ڲ�ͬ��Ӧ�ã�ulTime����ȡֵӦ��ͬ��
* -   ��1�������ļ��ط�ʱ���ò�����ֵӦΪ���ʱ�䣬������ļ�ͷ�Ĳ���ʱ�䣬��λΪ�룻
* -   ��2���㲥�ط�ʱ���ò�����ֵӦΪ����ʱ�䣬��λΪ�롣
* - 2�����ڱ���¼��ʱ�򣬲�֧�ָ���ʱ�������ļ�����λ�ò�����
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetPlayedTimeEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN ULONG_32 ulTime);

/**
* ��õ�ǰ����ʱ�䣨�ַ����ͣ���\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [OUT] pszTime           ��ŵ�ǰ����ʱ��ֵ������������Ӧ��С��#IMOS_TIME_LEN��32����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    ��õ�ǰ���Ž���ʧ��
* @note
* -     pszTime������ŵ�ǰ����ʱ�䣬���ڲ�ͬ��Ӧ�����ŵ�ֵ��ͬ��
* - 1�������ļ��ط�ʱ����ŵ������ʱ�䣬��������ļ�ͷ�Ĳ���ʱ�䣨��λΪ�룩��
* - 2���㲥�ط�ʱ����ŵ��Ǿ���ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPlayedTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode,
                                             OUT CHAR *pszTime);

/**
* ��õ�ǰ����ʱ�䣨���ͣ���\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [OUT] pulTime           ��ŵ�ǰ����ʱ��ֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_NOT_SUPPORT_MEDIA_SVC        ����ͨ����ý�����Ͳ�֧�ָò���
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PLAY_POSITION    ��õ�ǰ���Ž���ʧ��
* @note
* -     pulTime����������ŵ�ǰ���Ž��ȵ�ʱ��ֵ�����ڲ�ͬ��Ӧ�����ŵ�ֵ��ͬ��
* - 1�������ļ��ط�ʱ����ŵ������ʱ�䣬��������ļ�ͷ�Ĳ���ʱ�䣬��λΪ�룻
* - 2���㲥�ط�ʱ����ŵ��Ǿ���ʱ�䣬��λΪ�룻
* - 3���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetPlayedTimeEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               OUT ULONG_32 *pulTime);

/**
* ��������ý������ֻ֧������TS������ΪTS��ʽ¼���ļ���\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl           ������ý������Դ��URL��
* @param [IN]  pcServerIP          ý�����ط�������IP��
* @param [IN]  usServerPort        ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl             ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��������Ŀǰ��֧��TCPЭ�飩��
* @param [IN]  ulDownMediaSpeed    ý�����������ٶȣ����#XP_DOWN_MEDIA_SPEED_Eö����ȡֵ��
* @param [IN]  pcFileName          ����ý�����ݱ�����ļ���������·����
* @param [OUT] pcDownloadID        ����ͨ���ţ�����������Ӧ��С��#IMOS_RES_CODE_LEN��48����
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
* - 4��ֹͣý�������������#IMOS_StopDownMediaStream�ӿڣ�
* - 5���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownMediaStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcDownUrl,
                                                    IN const CHAR *pcServerIP,
                                                    IN USHORT usServerPort,
                                                    IN ULONG_32 ulProtl,
                                                    IN ULONG_32 ulDownMediaSpeed,
                                                    IN const CHAR *pcFileName,
                                                    OUT CHAR *pcDownloadID);

/**
* ���ó�֡���ء�\n
* @param [IN]  pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode                ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note
* 1�������øýӿ�ʱĬ��Ϊȫ֡����
* 2����#IMOS_OpenDownloadCallback��#IMOS_StartDownloadCallback֮�����
* 3����#IMOS_OpenDownload��#IMOS_StartDownload֮�����
* 4����#IMOS_OpenDownloadEx��#IMOS_StartDownloadEx֮�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetExtractFrameDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode);

/**
* ֹͣ����ý������\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownloadID        ����ͨ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note
* - 1���ýӿ���#IMOS_StartDownMediaStream�ӿ�ƥ�䣻
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownMediaStream(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                   IN const CHAR *pcDownloadID);

/**
* ��ý�������أ�֧��TS��������ý�������أ������ص�ý��������Ϊָ���ĸ�ʽ��\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl           Ҫ����¼���ļ���URL��
* @param [IN]  pcServerIP          ý�����ط�������IP��
* @param [IN]  usServerPort        ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl             ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��Ŀǰ��֧��TCPЭ�飩��
* @param [IN]  ulDownMediaSpeed    ý�����������ٶȣ����#XP_DOWN_MEDIA_SPEED_Eö����ȡֵ��
* @param [IN]  pcFileName          ���غ󱣴浽���ص��ļ�·�����������ļ�������·�����治��б�ܣ���
* @param [IN]  ulFileFormat        ���ر����ļ��ĸ�ʽ�����#XP_MEDIA_FILE_FORMAT_Eö����ȡֵ��
* @param [OUT] pcChannelCode       ������Դ���롣
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
* - 1���û����øú����ɹ��󣬿ɻ��������Դ���룬���ڱ�ʶһ·����ͨ����
* - 2�����ͬʱ֧������32·����ͨ����
* - 3����ý�������غ������#IMOS_StartDownload�ӿڿ�ʼ���أ�ֹͣ����ʱ����#IMOS_StopDownload�ӿڣ�
* - 4������¼���ļ�����������Ϊ�����������-ͨ����-S��ʼʱ��E����ʱ�䣬����ʱ��ĸ�ʽΪ��YYYYMMDDHHMMSSMS��
* -    �磺Cam0001-00-S20100316094658286E20100316094806084��
* - 5���������غ������ع����У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ���Ϣ
* -     �ϱ���Ϣ��#XP_RUN_INFO_DOWN_MEDIA_PROCESS��Я���Ĵ�����Ϊ��
* -     #ERR_XP_DISK_CAPACITY_WARN              ��������������
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_FAIL_TO_WRITE_FILE              �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     �ϱ���Ϣ��#XP_RUN_INFO_DOWN_RTSP_PROTOCOL��Я���Ĵ�����Ϊ��
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN          �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_DISCONNECT                 �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_ENCODE_CHANGE              �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT         �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_COMPLETE                   �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* - 7���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                      IN const CHAR *pcDownUrl,
                                                      IN const CHAR *pcServerIP,
                                                      IN USHORT usServerPort,
                                                      IN ULONG_32 ulProtl,
                                                      IN ULONG_32 ulDownMediaSpeed,
                                                      IN const CHAR *pcFileName,
                                                      IN ULONG_32 ulFileFormat,
                                                      OUT CHAR *pcDownloadID);

/**
* ��ý�������أ�Ŀǰֻ֧��TSý�������أ������ص�ý��������Ϊts�ĸ�ʽ������¼���ļ���ȫ�����û�ָ����\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl           Ҫ����¼���ļ���URL��
* @param [IN]  pcServerIP          ý�����ط�������IP��
* @param [IN]  usServerPort        ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl             ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��
* @param [OUT] pcChannelCode       ������Դ���롣
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
* - 1���û����øú����ɹ��󣬿ɻ��������Դ���룬���ڱ�ʶһ·����ͨ����
* - 2�����ͬʱ֧������32·����ͨ����
* - 3��Ŀǰ��֧��TSý��������,�ҽ�֧��1�������أ�
* - 4����ý�������غ������#IMOS_StartDownloadEx�ӿڿ�ʼ���أ�ֹͣ����ʱ����#IMOS_StopDownload�ӿڣ�
* - 5���������غ������ع����У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ���Ϣ
* -     �ϱ���Ϣ��#XP_RUN_INFO_DOWN_MEDIA_PROCESS��Я���Ĵ�����Ϊ��
* -     #ERR_XP_DISK_CAPACITY_WARN              ��������������
* -     #ERR_XP_DISK_CAPACITY_NOT_ENOUGH        �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_FAIL_TO_WRITE_FILE              �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE   �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_MEDIA_RESOLUTION_CHANGE         �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     �ϱ���Ϣ��#XP_RUN_INFO_DOWN_RTSP_PROTOCOL��Я���Ĵ�����Ϊ��
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN          �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_DISCONNECT                 �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_ENCODE_CHANGE              �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT         �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_COMPLETE                   �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* - 6���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                              IN const CHAR *pcDownUrl,
                                              IN const CHAR *pcServerIP,
                                              IN USHORT usServerPort,
                                              IN ULONG_32 ulProtl,
                                              OUT CHAR *pcChannelCode);

/**
* ��ʼ���أ�ֻ�д�ý�������غ���ܿ�ʼ���ء�\n
* @param [IN] pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode       ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲��ţ����أ�ʧ��
* -         #ERR_XP_NOT_SUPPORT_DOWNLOAD_FORMAT  �����ļ���ʽ��֧��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý��ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           ý�岥�Ŵ���ʧ��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     ���̿ռ䲻��
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       ��ʼ����ʧ��
* @note
* - 1���û�����#IMOS_OpenDownload�ӿڴ�ý�������غ��ٵ��øýӿڿ�ʼ���أ�ֹͣ����ʱ����#IMOS_StopDownload�ӿڣ�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN const CHAR *pcChannelCode);

/**
* ��ʼ���أ�ֻ�д�ý�������غ���ܿ�ʼ���ء�����¼���ļ���ȫ�����û�ָ����\n
* @param [IN]  pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode      ������Դ���롣
* @param [IN]  pcFileName         ���غ󱣴浽���ص��ļ�����������չ�����������ļ�·�����ļ���
*                                 ȫ�����û�ָ����
* @param [IN]  ulFileFormat       ���ر����ļ��ĸ�ʽ�����#XP_MEDIA_FILE_FORMAT_Eö����ȡֵ��
* @param [IN]  ulDownMediaSpeed   ý�����������ٶȣ����#XP_DOWN_MEDIA_SPEED_Eö����ȡֵ��
* @param [OUT] pcFilePostfix      ���¼���ļ���׺��ָ�룬����������Ӧ��С��#IMOS_XP_FILE_POSTFIX_LEN��
*                                 ����û�����Ҫ���غ�׺�����ɽ��ò�������ΪNULL��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲��ţ����أ�ʧ��
* -         #ERR_XP_NOT_SUPPORT_DOWNLOAD_FORMAT  �����ļ���ʽ��֧��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ����ý��������ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           ý�岥�Ŵ���ʧ��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     ���̿ռ䲻��
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       ��ʼ����ʧ��
* @note
* - 1���û�����#IMOS_OpenDownloadEx�ӿڴ�ý�������غ��ٵ��øýӿڿ�ʼ���أ�ֹͣ����ʱ����#IMOS_StopDownload�ӿڣ�
* - 2�������������û�ָ���ĵ��ļ����󸽼��Ϻ�׺����
* - 3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownloadEx(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               IN const CHAR *pcFileName,
                                               IN ULONG_32 ulFileFormat,
                                               IN ULONG_32 ulDownMediaSpeed,
                                               OUT CHAR *pcFilePostfix);

/**
* ֹͣ����ý������\n
* @param [IN]  pstUserLoginIDInfo   �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode        ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note
* - 1���ýӿ���#IMOS_OpenDownload��#IMOS_StartDownload�ӿ�ƥ�䣻
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownload(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                            IN const CHAR *pcDownloadID);

/**
* �����ز���ý����ͨ����\n
* @param [IN]  pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownUrl                    Ҫ����¼���ļ���URL��
* @param [IN]  pcServerIP                   ý�����ط�������IP��
* @param [IN]  usServerPort                 ý�����ط������Ķ˿ںš�
* @param [IN]  ulProtl                      ����ý������Э�����ͣ����#XP_PROTOCOL_Eö����ȡֵ��Ŀǰ��֧��TCPЭ�飩��
* @param [IN]  ulDownMediaSpeed             ý�����������ٶȣ����#XP_DOWN_MEDIA_SPEED_Eö����ȡֵ��
* @param [IN]  pfnSourceMediaDataCBFun      ����ý�������ݻص�������ָ�롣
* @param [IN]  lUserParam                   �û����ò�����
* @param [OUT] pcChannelCode                ������Դ���룬����������Ӧ��С��#IMOS_RES_CODE_LEN��
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
* - 1���û����øú����ɹ��󣬿ɻ��������Դ���룬���ڱ�ʶһ·����ͨ����
* - 2�����ͬʱ֧������32·����ͨ����
* - 3��Ŀǰ��֧��TCPЭ������ý������
* - 4����ý�������غ������#IMOS_StartDownloadCallback�ӿڿ�ʼ���أ�ֹͣ����ʱ����#IMOS_StopDownloadCallback�ӿڣ�
* - 5���������غ������ع����У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ���Ϣ
* -     �ϱ���Ϣ��#XP_RUN_INFO_DOWN_MEDIA_PROCESS��Я���Ĵ�����Ϊ��
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA      �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     �ϱ���Ϣ��#XP_RUN_INFO_DOWN_RTSP_PROTOCOL��Я���Ĵ�����Ϊ��
* -     #ERR_XP_RTSP_ABNORMAL_TEATDOWN          �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_DISCONNECT                 �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_ENCODE_CHANGE              �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_KEEP_LIVE_TIME_OUT         �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* -     #ERR_XP_RTSP_COMPLETE                   �ϱ�����Ϣ֮ǰ��������ֹͣ��Ӧͨ��������
* - 6���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenDownloadCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcDownUrl,
                                                    IN const CHAR *pcServerIP,
                                                    IN USHORT usServerPort,
                                                    IN ULONG_32 ulProtl,
                                                    IN ULONG_32 ulDownMediaSpeed,
                                                    IN XP_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                    IN LONG_REAL lUserParam,
                                                    OUT CHAR *pcChannelCode);

/**
* ��ʼ���ز���ý������\n
* @param [IN]  pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode                ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_PLAY_PROTOCOL        ����Э�̲��ţ����أ�ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_NET_MEDIA       ������ý��ʧ��
* -         #ERR_XP_FAIL_TO_PLAY_MEDIA           ý�岥�Ŵ���ʧ��
* -         #ERR_XP_FAIL_TO_START_DOWNLOAD       ��ʼ����ʧ��
* @note
* - 1���û�����#IMOS_OpenDownloadCallback�ӿڴ�ý�������غ��ٵ��øýӿڿ�ʼ���أ�ֹͣ����ʱ����#IMOS_StopDownloadCallback�ӿڣ�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartDownloadCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                     IN const CHAR *pcChannelCode);

/**
* ֹͣ���ز���ý������\n
* @param [IN]  pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcChannelCode        ������Դ���롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* @note
* - 1���ýӿ���#IMOS_OpenDownloadCallback��#IMOS_StartDownloadCallback�ӿ�ƥ����ã�
* - 2���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopDownloadCallback(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                    IN const CHAR *pcChannelCode);

/**
* ��õ�ǰ����¼���ļ��ľ���ʱ�䣬�����ڼ��㵱ǰ����¼���ļ��Ľ��ȡ�\n
* @param [IN]  pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN]  pcDownloadID          ����ͨ���š�
* @param [OUT] pszTime               ��ǰ����¼���ļ����ȵľ���ʱ��ֵ������������Ӧ��С��#IMOS_TIME_LEN��32����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         �������ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_GET_DOWN_POSITION    ��õ�ǰ���ؽ���ʧ��
* @note
* - 1��pszTime������ŵ��ǵ�ǰ����¼���ļ��ľ���ʱ�䣬ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss��
* - 2����������Ҫ��#IMOS_RecordRetrieval����һ�����ʹ�ã����ܼ������ǰ����¼���ļ��Ľ��ȡ�
*      �û�����#IMOS_RecordRetrieval������ɻ��¼���ļ��Ŀ�ʼʱ��ͽ���ʱ�䣬���ñ���������
*      ��ǰ����¼���ļ���ʱ�䣬���ԣ���ǰ����¼���ļ��Ľ��� =����ǰ����¼���ļ���ʱ�� - ��ʼʱ�䣩
*      / ������ʱ�� - ��ʼʱ�䣩��
* - 3���ú���һ�����ڼ���¼���ļ����ع����еĽ��ȡ���¼���������ʱ����������ͨ����Ϣ�ص��������û�
*      �ϱ���¼��������ɡ���Ϣ���û����յ���Ϣ���ˢ������״̬Ϊ����ɡ���
* - 4���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetDownloadTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcDownloadID,
                                               OUT CHAR *pszTime);

/** @} */  /* end of groupPlayerPlayback */

/** @defgroup groupPlayerLocalFile �����ļ��طţ���������
*   ʵ�ֱ����ļ��طŹ��ܡ�����ץͼ������¼�񡢱��ػط�¼���ļ�ʱ���ݲ��񡢻طſ��ơ���������
*   �Լ���ȡý���������ȹ��ܡ�
*   @{
*/
/**
* �򿪱��ز����ļ���\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcFileName         �����ļ����ļ����������ļ�·������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_AVAILABLE           ����ͨ��������
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ������Դʧ��
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      �ļ����Ÿ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       ����ļ��ܵĲ���ʱ��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_FILE            ���������ļ�����ʧ��(�ļ������ڻ������ڱ���������ʹ��)
* -         #ERR_XP_FILE_DESTROY                 Ҫ�򿪵��ļ�̫С�����Ѿ���
* -         #ERR_COMMON_NO_MEMORY                ���ļ�ʱϵͳ�ڴ治��
* -         #ERR_XP_FILE_HAVE_OPEN               ����ͨ���Ѿ������ļ�
* @note
* - 1�������ļ����ź��ڲ��Ź����У�������ͨ��#IMOS_SetRunMsgCB���õĻص������ϱ���Ϣ#XP_RUN_INFO_MEDIA_PROCESS��Я���Ĵ����룺
* -     #ERR_XP_FINISH_PLAY_FILE            �ϱ���Ϣ֮ǰ����������ͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_FILE_DESTROY                �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_COMMON_NO_MEMORY               �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* -     #ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA  �ϱ���Ϣ֮ǰ��������ֹͣ��Ӧͨ���Ĳ���
* - 2���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_OpenFile(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                        IN const CHAR *pcChannelCode,
                                        IN const CHAR *pcFileName);
/**
* ����ļ��ܵ�ʱ�䳤�ȡ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [OUT] pulTotalTime      �ļ��ܵ�ʱ�䳤�ȣ���λΪ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* @note
* - 1���ýӿں���֧��Windows��Linux��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFileTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                           IN const CHAR *pcChannelCode,
                                           OUT ULONG_32 *pulTotalTime);
/** @} */  /* end of groupPlayerLocalFile */

/** @defgroup groupPlayerVoice �����Խ��͹㲥����������
*   ʵ�������Խ��͹㲥��ع��ܣ�������Ƶ���ݷ��Ϳ��ƺ������������Ƶȹ��ܡ�
*   @{
*/
/**
* ������ֹͣ�������Զ˷����������ݡ�\n
* @param [IN] pstUserLoginIDInfo   �û���¼ID��Ϣ��ʶ��
* @param [IN] bSend                �Ƿ��������Զ˷����������ݣ�#BOOL_TRUE���������ͣ�#BOOL_FALSE��ֹͣ���ͣ���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_FAIL_TO_VOICE_SILENCE            ������ֹͣ�������Զ˷�����������ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SendVoiceData(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                             IN BOOL_T bSend);

/**
* ������ֹͣ�������������š�\n
* @param [IN] pstUserLoginIDInfo   �û���¼ID��Ϣ��ʶ��
* @param [IN] bQuiet               �Ƿ�������ֹͣ�����������������ţ�#BOOL_TRUE�����������������ţ�#BOOL_FALSE��ֹͣ�����������ţ���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_NOT_START_VOICE_TALKBACK         ��ǰû�����������Խ�ҵ��
* -         #ERR_XP_FAIL_TO_QUIET                    ���û�ֹͣ��������������ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_VoiceQuiet(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN BOOL_T bQuiet);

/**
* ������˷�������\n
* @param [IN] ulVolume ����ֵ��ȡֵ��Χ��0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_MIC_NOT_EXIST            ϵͳ����˷����䲻����
* -         #ERR_XP_FAIL_TO_ADJUST_VOLUME    ������������ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMicVolume(IN ULONG_32 ulVolume);

/**
* �����˷�����ֵ��\n
* @param [OUT] pulVolume ����ֵ��ָ�루���ص�����ֵ��Χ��0��255��255Ϊ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_MIC_NOT_EXIST            ϵͳ����˷����䲻����
* -         #ERR_XP_FAIL_TO_GET_VOLUME       �������ֵʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetMicVolume(OUT ULONG_32 *pulVolume);
/** @} */  /* end of groupPlayerVoice */

/**
* ���ûطŻ������صĿ�ʼʱ��ͽ���ʱ�䡣
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcStartTime        ���ŵ���ʼʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @param [IN] pcStopTime         ���ŵĽ���ʱ�䣨ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_OPEN                ָ���Ĳ���ͨ��δ����ý��ҵ��
* -         #ERR_XP_FAIL_TO_SET_STARTSTOP_TIME   ���ÿ�ʼʱ��ͽ���ʱ��ʧ��
* @note
* 1���ýӿ������Զ�����ʱ����ȡ�
* 2���ط�ʱ���û��ڵ���#IMOS_OpenVodStream֮���#IMOS_StartPlay֮ǰ���øýӿڡ�
* 3������ʱ���û��ڵ���#IMOS_OpenDownloadEx֮���#IMOS_StartDownloadEx֮ǰ���øýӿڡ�
* 4����������¼����Ҫ��������ӿ����ÿ�ʼʱ��ͽ���ʱ�䣬������ȷ��ȡ���ȡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetStartStopTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                IN const CHAR *pcStartTime,
                                                IN const CHAR *pcStopTime);


/**
* ����ý��Ƭ�εĿ�ʼʱ��ͽ���ʱ�䡣
* @param [IN] pstUserLoginIDInfo           �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                ����ͨ�����롣
* @param [IN] pstMediaSectionTime        ý��Ƭ�ε�ʱ����Ϣ��ʱ���ʽΪ��yyyy-mm-dd hh:mm:ss����
* @param [IN] ulSenctionNum                 ý��Ƭ�ε���Ŀ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM      ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER            ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_PORT_NOT_OPEN                ָ���Ĳ���ͨ��δ����ý��ҵ��
* -         #ERR_XP_FAIL_TO_SET_MEDIA_SECTION_TIME   ����ý��Ƭ��ʱ����Ϣʧ��
* @note
* 1���ýӿ����ڱ���ý��Ƭ�ε�ʱ�䡣
* 2������ʱ���û��ڵ���#IMOS_OpenDownloadEx֮���#IMOS_StartDownloadEx֮ǰ���øýӿڡ�
* 3��Ŀǰ��֧�����ء�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetMediaSectionTime(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
												   IN const CHAR *pcChannelCode,
												   IN const XP_MEDIA_SECTION_TIME_S *pstMediaSectionTime,
												   IN ULONG_32 ulSectionNum);



/**
* ���IP��ַӳ�� \n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] pcSrcAddr          Դ��ַ
* @param [IN] pcDstAddr          ӳ����ַ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* @note
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddAddressMap(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN const CHAR *pcSrcAddr, IN const CHAR *pcDstAddr);

/**
* ɾ��IP��ַӳ�� \n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ
* @param [IN] pcSrcAddr          Դ��ַ
* @return ��
* @note
*/
IMOS_EXPORT VOID STDCALL IMOS_DelAddressMap(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN const CHAR *pcSrcAddr);

/**
* ������������
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] szXPVoiceTalkCode     �����Խ����롣
* @param [IN] pucDataBuf            �������ݵ�ַ��
* @param [IN] ulDataLen             �������ݳ��ȡ�
* @param [IN] pstVoiceParam         ����������
* @return �������������Ƿ�ɹ���
*         ERR_COMMON_SUCCEED        �ɹ���
*         ERR_COMMON_INVALID_PARAM  ��Ч������
* @note
*   1.szXPVoiceTalkCode��Ϊ�մ���pstVoiceParamΪ�����������ݲ�ʹ�ã���NULL
*   2.Ŀǰֻ֧������G711��Ƶ�����������ݣ�ÿ�η��͵����ݴ�СΪ320�ֽ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_VoiceInputData(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                 IN  CHAR szXPVoiceTalkCode[IMOS_RES_CODE_LEN],
                                                 IN const UCHAR *pucDataBuf,
                                                 IN ULONG_32 ulDataLen,
                                                 IN XP_AUDIO_SAMPLE_PARAM_S *pstVoiceParam);

/**
* ���ý�������Ƶ�����ݻص�������\n
* @param [IN] pstUserLoginIDInfo       �û���¼ID��Ϣ��ʶ��
* @param [IN] pfnParseVoiceDataCBFun   ��������Ƶ�����ݻص�������ָ�롣
* @param [IN] bContinue                �Ƿ����������Ƶ����Ͳ��Ų�����
* @param [IN] lUserParam               �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_PORT_NOT_REGISTER                ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note
*   1.�ú�����IMOS_StartVoiceTalk֮ǰ��֮����ã���IMOS_StopVoiceTalk֮���Զ�ʧЧ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetParseVoiceDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                      IN XP_PARSE_VOICE_DATA_CALLBACK_PF pfnParseVoiceDataCBFun,
                                                      IN BOOL_T bContinue,
                                                      IN LONG_REAL lUserParam);

/**
* ����Ͱ�ͽ����\�\\n
* @param [IN] pstUserLoginIDInfo        �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode             ͨ����Դ���롣
* @param [IN] bOpen                     �Ƿ���Ͱ�ͽ������ܡ�
* @param [IN] enBarrelAjustLevel        Ͱ�ͽ����ȼ������#XP_BARREL_ADJUST_LEVEL_Eö��ֵ��ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_FAIL                        ִ��ʧ��
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_BARREL_ADJUST       ����Ͱ�ͽ���ʧ��
* @note
* -    1��Ĭ�ϲ�����Ͱ�ͽ�����
* -    2��Ͱ�ͽ����ȼ���ΧΪ[1--10]��Ĭ��ֵΪ1��
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetBarrelAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN BOOL_T bOpen,
                                                  IN XP_BARREL_ADJUST_LEVEL_E enBarrelAjustLevel);


/**
* ����ddraw����hdc�Ļص�������\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pfnDDrawDisplayHdcCBFun  DDraw����hdc�ص�������ָ�롣
* @param [IN] lUserParam               �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_DISPLAY_HDC_CB       ������ʾ�ص�����ʧ��
* @note
*      1���ú����ڴ���ͨ����Դ֮����ã��ͷ�ͨ����Դ��ʧЧ��
*      2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ����ΪNULL��
*      3���ûص�������������ͨƷ��ʱʹ�á�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDisplayHdcCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  IN XP_PLAYER_HDC_CALLBACK_PF pfnDisplayHdcCBFun,
                                                  IN LONG_REAL lUserParam);

/**
* �����Դ��ͷ�ģʽ��\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] bRemainRenderRes   �Ƿ����Դ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                    �ɹ�
* -         #ERR_COMMON_INVALID_PARAM              ���������Ч
* @note
* - 1���ú������������Ƿ��ͷ�ͨ����ʾ��Դ�����Խ����ʱ�����е���DirectX�Դ���Դ�޷��������⡣
* - 2������û�û�е��øú������򲥷���XP�ڲ�Ĭ��ʹ���Դ��ͷ�ģʽ��
* - 3����Startplay֮ǰ��֮����ã�StopPlay֮��ʧЧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetRenderResourceMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                        IN const CHAR *pcChannelCode,
                                                        IN BOOL_T bRemainRenderRes);


/**
* ��ȡ���е�ͨ����Դ���롣\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [OUT] pcChannelCodel         ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* @note �ޡ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetChannelCode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, OUT CHAR *pcChannelCode);

/**
* �ͷſ��е�ͨ����Դ���롣\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [OUT] pcChannelCodel         ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* @note �ޡ�
*/
IMOS_EXPORT VOID STDCALL IMOS_FreeChannelCode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN const CHAR *pcChannelCode);

/**
* ����ͼƬ���Ź��ܡ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_START_IMAGE          ����ͼƬ����ģʽʧ��
* @note ��ǰֻ֧��httpЭ���jpgͼƬ���š�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartImage(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                          IN const CHAR *pcChannelCode);

/**
* ͼƬ���ء�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @param [IN] pcImageURL         ͼƬURL��Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           ����ͼƬʧ��
* @note ��ǰֻ֧��httpЭ���jpgͼƬ���š�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_LoadImage(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode,
                                         IN const CHAR *pcImageURL);

/**
* �ر�ͼƬ���Ź��ܡ�\n
* @param [IN] pstUserLoginIDInfo �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ����ͨ�����롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_STOP_IMAGE           �ر�ͼƬ����ģʽʧ��
* @note ��ǰֻ֧��httpЭ���jpgͼƬ���š�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopImage(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                         IN const CHAR *pcChannelCode);
										 

/**
* �������ص�¼���Ƿ��Ǽ���(Ĭ��ͬԭʼ����)��\n
* @param [IN] pstUserLoginIDInfo        �û���Ϣ
* @param [IN] pcChannelCode             ����ͨ���š�
* @param [IN] bDownloadMode             �Ƿ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* @note �����ַ����������ж��壬�����շ�˫�����뱣��һ�£����Դ����ַ�������ָ�벻��Ϊ�ա�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetDownloadScrambleMode(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                  IN const CHAR *pcChannelCode,
                                                  BOOL_T bDOownloadMode);

/**
* ���ò����������Ӧ��Keyֵ�Ļص����� 
* @param [IN] pstUserLoginIDInfo        �û���Ϣ
* @param [IN] szCamName                 ���������
* @param [IN] pstQueryCondition         ��ѯ����(��ֵΪNULL)
* @param [INOUT]pstCameraDescrambleInfo ��ȡ��������Ϣ
*/
typedef ULONG_32 (STDCALL *XP_GETSCRAMBLE_KEY_CALLBACK_PF)(IN  USER_LOGIN_ID_INFO_S            *pstUserLoginIDInfo,
                                                           IN  CHAR                            szCamName[IMOS_NAME_LEN],
                                                           IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
                                                           OUT CAM_DESCRAMBLE_INFO_S           *pstCameraDescrambleInfo);

/* Begin Added by lizhen 2017-6-23 for ���û�ȡ��Ƶ����key�Ļص�����ָ�� */
/**
* ���û�ȡ����key�����Ļص�������\n
* @param [IN] pstUserLoginIDInfo        �û���Ϣ
* @param [IN] XP_GETSCRAMBLE_KEY_CALLBACK_PF             �ص�����ָ�롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetScrambleKeyCallBack(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                         IN XP_GETSCRAMBLE_KEY_CALLBACK_PF pfnXpGetScrambleKeyCallBack);
														 
/* Begin:Added by lizhen in 2017-9-1 for ���۽��� */
/**
* ���۽������á�\n
* @param [IN] pstUserLoginIDInfo    �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode         ����ͨ�����롣
* @param [IN] pstWorkParam          �㷨����1֡����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
            #ERR_COMMON_FAIL                     ִ��ʧ��
* @note 
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFishAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                IN const CHAR *pcChannelCode,
                                                IN IMOS_uintptr_t pstWorkInterfaceParam);

/**
* �������۽����ص�ָ��
* @param [IN] pstUserLoginIDInfo                �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                     ����ͨ�����롣
* @param [INOUT] pfnFishAdajustDataCBFun        ���۽����ص�ָ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
#ERR_COMMON_FAIL                                 ִ��ʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_SetFishAdajustDataCB(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                                       IN const CHAR *pcChannelCode,
                                                       IN IMOS_uintptr_t pfnFishAdajustDataCBFun,
                                                       IN IMOS_uintptr_t pfnISFQueryCBFun);

/**
* �жϵ�ǰͨ���Ƿ�������ͨ��
* @param [IN] pstUserLoginIDInfo                �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode                     ����ͨ�����롣
* @param [IN] pbIsFishAdjust                    �����Ƿ�������ͨ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
#ERR_COMMON_FAIL                                 ִ��ʧ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_IsFishAdjust(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
                                               IN const CHAR *pcChannelCode,
                                               OUT BOOL_T *pbIsFishAdjust);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_MEDIA_PLAYER_SDK_FUNC_H_ */
