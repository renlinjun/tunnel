/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
xp_player_inner.h

Project Code: IMOSͨ��ý�岥����
Module Name: IMOSͨ��ý�岥����
Date Created: 2012-03-31
Author: jinqifeng 00350
Description: IMOSͨ��ý�岥����XP�ڲ��ӿ�

--------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_XP_PLAYER_INNER_H_
#define _IMOS_XP_PLAYER_INNER_H_

/* ����IMOS����ƽ̨��ͷ�ļ� */
#include "imos_public.h"
#include "imos_errcode.h"
#include "imos_def.h"

/* ����������SDK���ݽṹͷ�ļ� */
#include "xp_datatype.h"
#include "xp_player.h"

#ifdef  __cplusplus
extern "C"{
#endif

/**
* ����ָ��ץ����Ŀ������ʵʱץ�ġ�\n
* @param [IN] ulPort             ����ͨ���š�
* @param [IN] pcFileName         ͼ���ļ���ŵ�·���������ļ�����������չ������
* @param [IN] ulPicFormat        ͼ���ļ��ĸ�ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @param [IN] ulInterval         ץ�ļ������λΪ���롣
* @param [IN] ulCount            ץ����Ŀ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NOT_START_PLAY               ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_ALREADY_START_SERIES_SNATCH  ����ͨ���Ѿ�����������ץ�ĵĲ���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_START_SERIES_SNATCH  ��������ץ�Ĳ���ʧ��
* @note
* -
* -    1��������XP�����ļ������渽��������"20080928(13-10-50-99)"��ʽ��ץ��ʱ����ַ�����
* -       ��λʱ���ڳɹ�ץ�ĵ����ͼƬ���ͻ��������йأ�
* -    2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartSnatchSeriesEx(IN ULONG_32 ulPort,
                                                                IN const CHAR *pcFileName,
                                                                IN ULONG_32 ulPicFormat,
                                                                IN ULONG_32 ulInterval,
                                                                IN ULONG_32 ulCount);

/**
* ����ָ��ͨ�������ַŴ��ܡ�\n
* @param [IN] ulPort                   ����ͨ����
* @param [IN] hWnd                     ���л����,hWnd = IMOS_INVALID_HANDLE��ʾ�رգ���IMOS_INVALID_HANDLE��ʾ����
* @param [IN] pstRect                  ԭʼͼ���������꣬pstRect = NULLΪȫ����ʾ��������ֵΪ������ͼ���еİٷֱ�ֵ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_SUPPORT                  ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_DIGITALZOOM      ���õ��ӷŴ�ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDigitalZoom(IN ULONG_32 ulPort,
                                                           IN IMOS_HANDLE hWnd,
                                                           IN XP_RECT_S *pstRect);

/**
* ��ȡָ��ͨ����ͼƬ��Ϣ��\n
* @param [IN] ulPort                   ����ͨ����
* @param [OUT] pulWidth                ͼƬ�Ŀ�
* @param [OUT] pulHeight               ͼƬ�ĸ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_GET_PIC_PARAM        ��õ�ǰͨ�������ͼƬ������Ϣʧ��
* -         #ERR_COMMON_INVALID_PARAM            ��������
* @note
* - 1���ýӿں�����֧��Windows��
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetPicSize(IN ULONG_32 ulPort,
                                                       OUT ULONG_32 *pulWidth,
                                                       OUT ULONG_32 *pulHeight);

/**
* �����Ƿ��������������ܡ�\n
* @param [IN] bAdjust �Ƿ�������������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_SET_PARAM            ���ò����������ò���ʧ��
* @note
* -  1����ǰֻ֧��UDP+TS�е���Ƶ��������
* -  2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_AdjustPktSeq(IN BOOL_T bAdjust);

/**
* ��ָ��ͨ����ͼ������������
* @param [IN] ulPort             ����ͨ����
* @param [IN] pDrawHandle        ��ͼ���
* @param [IN] ulNum              ���������򶥵���������Ϊ6
* @param [IN] pointArry          �����ַ
* @param [IN] ulDir              ����,���#XP_AREA_DIRECTION_Eö����ȡֵ��
* @param [IN] ulColor            ������ɫ
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_PolylineTo(IN ULONG_32 ulPort,
                                                      IN IMOS_HANDLE pDrawHandle,
                                                      IN ULONG_32 ulNum,
                                                      IN XP_POINT_S *pointArry,
                                                      IN ULONG_32 ulDir,
                                                      IN ULONG_32 ulColor);

/**
* ��ָ��ͨ����ͼ������������
* @param [IN] ulPort                   ����ͨ����
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] ulNum                    ���������򶥵���������Ϊ#MAX_AREA_POINT
* @param [IN] pointArry                �����ַ
* @param [IN] ulWidth                  �������
* @param [IN] ulColor                  ������ɫ
* @return ��
* @note ��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_PolylineToWindow(IN ULONG_32 ulPort,
                                                            IN IMOS_HANDLE pDrawHandle,
                                                            IN ULONG_32 ulNum,
                                                            IN XP_POINT_S *pointArry,
                                                            IN ULONG_32 ulWidth,
                                                            IN ULONG_32 ulColor);

/**
* ��ָ��ͨ����ͼ����Ӱ�ߣ�
* @param [IN] ulPort             ����ͨ����
* @param [IN] pDrawHandle        ��ͼ���
* @param [IN] pstStart           ֱ�����
* @param [IN] pstEnd             ֱ���յ�
* @param [IN] ulDir��            ��������,���#XP_THRU_LINE_DIRECTION_Eö����ȡֵ
* @param [IN] ulColor            ������ɫ
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_DLineTo(IN ULONG_32 ulPort,
                                                   IN IMOS_HANDLE pDrawHandle,
                                                   IN const XP_POINT_S *pstStart,
                                                   IN const XP_POINT_S *pstEnd,
                                                   IN ULONG_32 ulDir,
                                                   IN ULONG_32 ulColor);

/**
* ��ȡ��ͼ���
* @param [IN] ulPort             ����ͨ����
* @return �������½����
* - �ɹ���IMOS_HANDLE
* - #
* - ʧ�ܣ�IMOS_INVALID_HANDLE
* -
* @note
* - 1����Ҫ����Ƶ����ͼ��������Ҫ����#IMOS_GetHVDC��ȡHVDC���ſ�����ͼ����ʾ������#IMOS_ReleaseHVDCȡ����ͼ������ʾ
* - 2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT IMOS_HANDLE STDCALL IMOS_XP_GetHVDC(IN ULONG_32 ulPort);

/**
* �ͷŻ�ͼ���
* @param [IN] ulPort             ����ͨ����
* @param [IN] pDrawHandle        ͨ��IMOS_GetHVDC��ȡ�ľ��
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_ReleaseHVDC(IN ULONG_32 ulPort,
                                                       IN IMOS_HANDLE pDrawHandle);
/**
* ��ʼ��ͼ
* @param [IN] ulPort                   ����ͨ����
* @param [IN] pDrawHandle              ��ͼ���
* @param [IN] pverBer                  ��������
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_BEGINHVDC           ��ʼ��ͼʧ��
* @note
* - 1����ͼ���ϻ��ߣ�������Ҫ��#IMOS_BeginDraw��#IMOS_EndDraw ֮�����������������Ч
* - 2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_BeginDraw(IN ULONG_32 ulPort,
                                                      IN IMOS_HANDLE pDrawHandle,
                                                      IN VOID *pverBer);

/**
* �����ͼ
* @param [IN] ulPort             ����ͨ����
* @param [IN] pDrawHandle        ��ͼ���
* @return ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_EndDraw(IN ULONG_32 ulPort,
                                                   IN IMOS_HANDLE pDrawHandle);

/**
* ���ý�������ܹ�����ʾʹ��
* @param [IN] ulPort             ����ͨ����
* @param [IN] bEnable            �Ƿ���ʾ
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERULE   ������ʾ���ܹ���ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ShowAnalyseRule(IN ULONG_32 ulPort,
                                                            IN const BOOL_T bEnable);

/**
* ���ý�������ܽ����ʾʹ��
* @param [IN] ulPort        ����ͨ����
* @param [IN] bEnable       �Ƿ���ʾ
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_ENABLEANALYSERESULT ������ʾ���ܽ��ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ShowAnalyseResult(IN ULONG_32 ulPort,
                                                              IN const BOOL_T bEnable);

/**
* Ӱ�����\n
* @param [IN] ulPort        ����ͨ����
* @param [IN] pstAdjust     Ӱ����ڲ���
* @param [IN] bOpen         �Ƿ��Ӱ�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY              ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                 ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_VIDEO_ADJUST    ����Ӱ�����ʧ��
* @note
*      1���ú�����Ҫ��#IMOS_XP_StartPlay֮���#IMOS_XP_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ�����Ӱ����ڡ�
* -    3���Աȶ�ȡֵ��ΧΪ[0--199]��Ĭ��ֵΪ100��
* -       ����ȡֵ��ΧΪ[0--199]��Ĭ��ֵΪ100��
* -       ɫ��ȡֵ��ΧΪ[0--359]��Ĭ��ֵΪ0��
* -       ���Ͷ�ȡֵ��ΧΪ[0--359]��Ĭ��ֵΪ100��
* -       ٤��ȡֵ��ΧΪ[0--99]��Ĭ��ֵΪ10��
* -    4���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoAdjust(IN ULONG_32 ulPort,
                                                           IN const XP_VIDEO_ADJUST_S *pstAdjust,
                                                           IN BOOL_T bOpen);

/**
* ģ������\n
* @param [IN] ulPort        ����ͨ����
* @param [IN] ulFactor      ģ���������
* @param [IN] bOpen         �Ƿ�����ģ������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_VIDEO_MONITOR_BLUR  ����ģ������ʧ��
* @note
* -    1���ú�����Ҫ��#IMOS_XP_StartPlay֮���#IMOS_XP_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ�����ģ������
* -    3��ģ���������ȡֵ��ΧΪ[1--127]��Ĭ��ֵΪ80��
* -    4���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoMotionBlur(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulFactor,
                                                               IN BOOL_T bOpen);

/**
* ��������ʵʱץ�ġ�\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] pcFileName        ����ͼ����ļ�·���������ļ�����������׺������
* @param [IN] ulPicFormat       ͼ���ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @param [IN] pstRect           �ƶ�ץ������
* @param [OUT] pcFilePostfix    ���ͼ���ļ���׺��ָ�룬����������Ӧ��С��#IMOS_XP_FILE_POSTFIX_LEN��
*                               ����û�����Ҫ���غ�׺�����ɽ��ò�������ΪNULL��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY               ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         û�н������ͼƬ�ɹ�ץ��
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          ����ץ�Ĳ���ʧ��
* @note
* -  1. ������������ͼ���ʽ���ļ�������׷�Ӷ�Ӧ�ĺ�׺������BMPͼ���ļ��ĺ�׺Ϊ.bmp��
* -  2. pstRectΪNULLʱ��Ϊץ������ͼ��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SnatchRegion(IN ULONG_32 ulPort,
                                                         IN const CHAR *pcFileName,
                                                         IN ULONG_32 ulPicFormat,
                                                         IN const XP_RECT_S *pstRect,
                                                         OUT CHAR *pcFilePostfix);

/**
* �񻯴���\n
* @param [IN] ulPort        ����ͨ����
* @param [IN] fSigma        �񻯴������
* @param [IN] bOpen         �Ƿ������񻯴���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_VIDEO_SHARPEN       �����񻯴���ʧ��
* @note
* -    1���ú�����Ҫ��#IMOS_XP_StartPlay֮���#IMOS_XP_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ������񻯴���
* -    3���񻯴������ȡֵ��ΧΪ[0.0--2.0]��Ĭ��ֵΪ0.05��
* -    4���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoSharpen(IN ULONG_32 ulPort,
                                                            IN FLOAT fSigma,
                                                            IN BOOL_T bOpen);

/**
* ȥ����\n
* @param [IN] ulPort            ����ͨ����
* @param [IN] ulLowValue        �������ڲ���
* @param [IN] ulHighValue       �������ڲ���
* @param [IN] bOpen             �Ƿ�����ȥ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_DE_FOG              ����ȥ����ʧ��
* @note
* -    1���ú�����Ҫ��#IMOS_XP_StartPlay֮���#IMOS_XP_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ�����ȥ����
* -    3��ȥ�������1ȡֵ��ΧΪ[0--49]��Ĭ��ֵΪ0��
* -       ȥ�������2ȡֵ��ΧΪ[51--100]��Ĭ��ֵΪ100��
* -    4���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDeFog(IN ULONG_32 ulPort,
                                                     IN ULONG_32 ulLowValue,
                                                     IN ULONG_32 ulHighValue,
                                                     IN BOOL_T bOpen);

/**
* �����������������ƴ֡���ԡ�\n
* @param [IN] ulDataLostSplitterPolicy  �������������ƴ֡���ԣ����#XP_MEDIA_DATA_LOST_SPLITTER_POLICYö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* @note
* -    1���������������Ĭ�϶���һ��I֡��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMediaDataLostSplitterPolicy(IN ULONG_32 ulDataLostSplitterPolicy);

/**
* ����˸����\n
* @param [IN] ulPort            ����ͨ����
* @param [IN] ulWinSize         �ο�֡��
* @param [IN] ulSoftenVal       ֡���˲�����
* @param [IN] bOpen             �Ƿ���������˸����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_ANTI_FLICKER        ���÷���˸����ʧ��
* @note
* -    1���ú�����Ҫ��#IMOS_XP_StartPlay֮���#IMOS_XP_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ���������˸����
* -    3��ulWinSizeȡֵ��ΧΪ[0--100]��
* -       ulSoftenValȡֵ��ΧΪ[0--30]��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetAntiFlicker(IN ULONG_32 ulPort,
                                                           IN ULONG_32 ulWinSize,
                                                           IN ULONG_32 ulSoftenVal,
                                                           IN BOOL_T bOpen);

/**
* ����ͼ��ĶԱȶȲ�����\n
* @param [IN] ulPort             ����ͨ���š�
* @param [IN] ulContrastMode     ͼ��Աȶ�ģʽ�����#XP_PICTURE_CONTRAST_MODE_Eö����ȡֵ��
* @param [IN] ulContrastLevelEx  ͼ��Աȶȼ������#XP_PICTURE_CONTRAST_LEVEL_EX_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED              �ɹ�
* -         #ERR_COMMON_INVALID_PARAM        ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES     ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_SUPPORT_SET_CONTRAST ����ͨ����֧������ͼ��ԱȶȲ���
* -         #ERR_XP_FAIL_TO_SET_CONTRAST     ����ͼ��Աȶ�ʧ��
* @note
* -    1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ�ϲ����жԱȶȵ��ڴ���
* -    2�������ڿ�ʼ����#IMOS_XP_StartPlay֮ǰ���ã������õĶԱȶȲ��������棬��Ϊ������ͨ������ʱ
* -       �ĳ�ʼֵ���ڿ�ʼ���ź���øýӿ����õĶԱȶȲ�����ʱ��Ч��
* -    3�����øýӿڶ�ָ������ͨ�����õĶԱȲ����ڲ����������ڼ�һֱ��Ч��������ulContrastMode
* -       ����#XP_PICTURE_CONTRAST_MODE_NONEʱ����ֹͣ�Աȶȵ��ڴ�����ʱulContrastLevel������
* -       ���ֵ��Ч��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetPictureContrastEx(IN ULONG_32 ulPort,
                                                                 IN ULONG_32 ulContrastMode,
                                                                 IN ULONG_32 ulContrastLevelEx);

/**
* ��֡���˲��š�\n
* @param [IN] ulPort   ����ͨ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_NOT_START_PLAY               ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_IN_RECORD_VIDEO_STATUS       ��ǰ���ڱ���¼��
* -         #ERR_XP_FAIL_TO_STEP_PLAY            ��֡����ʧ��
* @note
* -    1�����ڱ���¼��ʱ����֧�ֵ�֡���˲��Ų�����
* -    2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OneByOneBack(IN ULONG_32 ulPort);

/**
* �������ϵͳ��Ӳ������
* @param [IN] �ޡ�
* @return ����#XP_HW_STATUS_Eö�����͵Ĳ���
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CheckHWValidate();

/**
* ����ͼ��ƴ�Ӳ���
* @param [IN] ulChannelID                   ����ͼ��ƴ�ӵ�ͨ����
* @param [IN] pcCombineResCode              ͼ��ƴ����Դ����
* @param [IN] ulCombineStreamNum             ͼ��ƴ�ӵ�ͨ����Ŀ
* @param [IN] pulCombineStreamChannelID     ͼ��ƴ��ͨ������
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_START_COMBINE_IMAGE ����ͼ��ƴ�Ӳ���ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartCombineVideo(IN const ULONG_32 ulChannelID,
                                                              IN const CHAR  *pcCombineResCode,
                                                              IN const ULONG_32 ulCombineStreamNum,
                                                              IN const ULONG_32 *pulCombineStreamChannelID);
/**
* ֹͣͼ��ƴ�Ӳ���
* @param [IN] ulChannelID           ����ͼ��ƴ�ӵ�ͨ����
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_IMAGE  ֹͣͼ��ƴ�Ӳ���ʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopCombineVideo(IN const ULONG_32 ulChannelID);

/**
* �궨ͼ��ƴ��������
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
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_MarkCombinePoint(IN const CHAR  *pcCombineResCode,
                                                             IN LONG_32  lCombineStreamNum,
                                                             IN LONG_32  *plCombinPointNum,
                                                             IN LONG_32  *plCombinPointVal,
                                                             IN LONG  lReserve);

/**
* ������Ƶͼ����ӷŴ��ܡ�\n
* @param [IN] ulChannelID           ���ŵ��ӷŴ��ͨ����
* @param [IN] pcCombineResCode      ͼ��ƴ����Դ����
* @param [IN] pstComobineZoomRect   ���ӷŴ�������Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_START_COMBINE_ZOOM   �������ӷŴ�ʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartCombineZoom(IN const ULONG_32 ulChannelID,
                                                             IN const CHAR  *pcCombineResCode,
                                                             IN const XP_COMBINE_ZOOM_RECT_S *pstComobineZoomRect);

/**
* �޸ĵ��ӷŴ�������Ϣ��\n
* @param [IN] ulChannelID           ���ŵ��ӷŴ��ͨ����
* @param [IN] pcCombineResCode      ͼ��ƴ����Դ����
* @param [IN] pstComobineZoomRect   ���ӷŴ�������Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_MOVE_COMBINE_ZOOM    �޸ĵ��ӷŴ�������Ϣʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_MoveCombineZoom(IN const ULONG_32 ulChannelID,
                                                            IN const CHAR  *pcCombineResCode,
                                                            IN const XP_COMBINE_ZOOM_RECT_S *pstComobineZoomRect);


/**
* �ر���Ƶͼ����ӷŴ��ܡ�\n
* @param [IN] ulChannelID           ���ŵ��ӷŴ��ͨ����
* @param [IN] pcCombineResCode      ͼ��ƴ����Դ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_STOP_COMBINE_ZOOM    �رյ��ӷŴ���ʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopCombineZoom(IN const ULONG_32 ulChannelID,
                                                            IN const CHAR  *pcCombineResCode);

/**
* �ж��Ƿ�ΪDB33�����׼���롣\n
* @param [IN] pcDecodetag    decodetag��Ϣ
* @return #BOOL_TRUE����DB33��������׼���룻 #BOOL_FALSE����DB33��������׼����
* @note ��
*/
IMOS_XP_PLAYER_EXPORT BOOL_T STDCALL IMOS_XP_IsDB33Decodetag(IN const CHAR *pcDecodetag);

/**
* ���ý���ģʽ \n
* @param [IN] ulChannelID        �û���¼ID��Ϣ��ʶ ���ò�����Ч��ȫ����Ч
* @param [IN] ulMode                    ����ģʽ 0 �������ģʽ
* @return
* @note
* - 1���ýӿں�����֧��Windows��
* - 2���ýӿ�Ϊʵ���Խӿڣ��ᵼ�³����ȶ����½������Ƽ��û�ʹ�á�
* - 3���ú������سɹ�ʧ��
* - 4���ýӿڿ��Ժ�IMOS_XP_SetTransParam���ʹ��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVideoDecodeMode(IN const ULONG_32 ulChannelID,
                                                               IN ULONG_32 ulMode);

/**
* ��ȡ���ж˿ںš�\n
* @param [INOUT] pulPort    ����ͨ����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ȡ��Դʧ��
* @note ��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetPort(INOUT ULONG_32 *pulPort);

/**
* �ͷŶ˿ںš�\n
* @param [IN] ulPort    ����ͨ����
* @return ��
* @note ��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_FreePort(IN ULONG_32 ulPort);


/**
* ����ͨ����ԭʼ������Ϣ��\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcDecoderTag  �����������ǩ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò��Ŵ��ڵ���Դʧ��
* @note �ýӿڻὫ�����DecoderTag�޸�Ϊ�����̵�ԭʼ������Ӧ��DecoderTag;
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRawDecoderTag(IN ULONG_32 ulPort,
                                                             IN const CHAR *pcDecoderTag);

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartMultiSectionJoint(IN const CHAR *pcFileName,
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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartMultiFileJoint(IN CHAR *pacFileName[],
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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CreateTsDataJointFile(IN const CHAR *pcJointFileName, OUT ULONG *pulHandle);

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_JointTsDataToFile(IN ULONG ulHandle, IN UCHAR *pucDataBuf, IN ULONG_32 ulDataLen,IN ULONG_32 ulMode);

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_CloseTsDataJointFile(IN ULONG ulHandle, OUT XP_FILE_JOINT_INFO_S *pstFileJointInfo);

/**
* ����ͼƬ���Ź��ܡ�\n
* @param [IN] ulPort ����ͨ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_START_IMAGE          ����ͼƬ����ģʽʧ��
* @note ��ǰֻ֧��httpЭ���jpgͼƬ���š�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartImage(IN ULONG_32 ulPort);

/**
* ͼƬ���ء�\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcImageURL    ����ͼƬURL��Ϣ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           ����ͼƬʧ��
* @note ��ǰֻ֧��httpЭ���jpgͼƬ���š�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_LoadImage(IN ULONG_32 ulPort,
                                                      IN const CHAR *pcImageURL);

/**
* ����ͼƬ�ڴ�.\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcImageMemory ͼƬʼ��ַ
* @param [IN] ulImageSize   ͼƬ��С
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           ����ͼƬʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_LoadImageMemory(IN ULONG_32 ulPort,
                                                            IN const UCHAR *pucImageMemory,
                                                            IN const ULONG_32 ulImageSize);

/**
* ����ͼƬ�ڴ�.\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcImageMemory ͼƬʼ��ַ
* @param [IN] ulImageSize   ͼƬ��С
* @param [IN] pcPrivateData ˽��������ʼ��ַ
* @param [IN] ulPrivateLen  ˽�����ݳ���
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_LOAD_IMAGE           ����ͼƬʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_LoadImageMemoryEx(IN ULONG_32 ulPort,
                                                              IN const UCHAR *pcImageMemory,
                                                              IN const ULONG_32 ulImageSize,
                                                              IN const UCHAR *pcPrivateData,
                                                              IN const ULONG_32  ulPrivateLen);


/**
* �ر�ͼƬ���Ź��ܡ�\n
* @param [IN] ulPort  ����ͨ���š�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER            ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_STOP_IMAGE           �ر�ͼƬ����ģʽʧ��
* @note ��ǰֻ֧��httpЭ���jpgͼƬ���š�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopImage(IN ULONG_32 ulPort);


/**
* ��������ҵ��������͡�\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] ulAudioEncType  ��Ƶ�������ͣ����#XP_AUDIO_ENCODE_TYPE_Eö����ȡֵ��
* @param [IN] ulSampleRate  ��Ƶ�����ʡ�
* @param [IN] ulChannels  ��Ƶ��������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVoiceEncodeType(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulAudioEncType,
                                                               IN ULONG_32 ulSampleRate,
                                                               IN ULONG_32 ulChannels);

/**
* ���ý���ͨ����SDP��Ϣ��\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcDecoderSdp  ͨ����������SDP��Ϣ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò��Ŵ��ڵ���Դʧ��
* @note
* -    1��Ŀǰ����Ϊ�˽��������DB33�����������͵�����Э�̳���sdp��Ϣ���ø�������DB33��������
* -    2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDecoderSdp(IN ULONG_32 ulPort,
                                                          IN const CHAR *pcDecoderSdp);

/**
* ����ʵʱץ�ģ����޸��ļ�������\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] pcFileName        ����ͼ����ļ�·���������ļ�����
* @param [IN] ulPicFormat       ͼ���ʽ�����#XP_PICTURE_FORMAT_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY               ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT_SNATCH_FORMAT    ץ�ĸ�ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH     Ӳ�̿ռ䲻��
* -         #ERR_XP_NO_PICTURE_TO_SNATCH         û�н������ͼƬ�ɹ�ץ��
* -         #ERR_XP_FAIL_TO_SNATCH_ONCE          ����ץ�Ĳ���ʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SnatchOnceEx(IN ULONG_32 ulPort,
                                                         IN const CHAR *pcFileName,
                                                         IN ULONG_32 ulPicFormat);


/**
* ��ʼ����¼�񣨲��޸��ļ�������\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] pcFileName        ¼���ļ����·���������ļ�����
* @param [IN] ulMediaFileFormat ¼���ļ��ĸ�ʽ�����#XP_MEDIA_FILE_FORMAT_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                    ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                       ͨ��δ��ʼ���Ų���
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           ָ���Ĳ���ͨ���Ѿ�����¼�����
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      ¼���ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             Ӳ�̿ռ䲻��
* -         #ERR_XP_IN_PAUSE_PLAY_STATUS                 ��ǰ��������ͣ����״̬
* -         #ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS         ��ǰ�����ڱ��ٲ���״̬
* -         #ERR_XP_IN_STEP_PLAY_STATUS                  ��ǰ�����ڵ�֡����״̬
* -         #ERR_XP_NOT_SUPPORT                          ��֧�ָù���
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           ��������¼��ʧ��
* @note
* -    1�������Ŵ�����ͣ���š����ٲ��š����ٲ��Ż�֡����״̬ʱ����֧����������¼�������
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartRecordEx(IN ULONG_32 ulPort,
                                                          IN const CHAR *pcFileName,
                                                          IN ULONG_32 ulMediaFileFormat);

/**
* ����ת����ý�������ݻص�������\n
* @param [IN] ulPort                  ����ͨ���š�
* @param [IN] pfnTranscodeCBFun       ת���ý�������ݻص�������ָ�롣
* @param [IN] pstEncParam             ����������
* @param [IN] bContinue               �Ƿ�������к����ƴ֡���������ʾ������
* @param [IN] lUserParam              �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note
* -     1���ú�����IMOS_XP_StartPlay֮ǰ��֮����ã�
* -     2�����IMOS_XP_StopPlayǰ���ص�����ָ����ΪNULL��
* -     3���ú��������������������ص�����ͬʱʹ�ã�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTranscodeCB(IN ULONG_32 ulPort,
                                                           IN XP_PLAYER_TRANSCODE_CALLBACK_PF pfnTranscodeCBFun,
                                                           IN const XP_ENCODE_PARAM_S *pstEncParam,
                                                           IN BOOL_T bContinue,
                                                           IN LONG_REAL lUserParam);

/**
* ����ת��װ��TS��������Ļص�����ָ�롣\n
* @param [IN] ulPort                        ����ͨ���š�
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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTsDataOutputCB(IN ULONG_32 ulPort,
                                                              IN XP_PLAYER_MEDIA_DATA_CALLBACK_PF pfnMediaDataCallback,
                                                              IN LONG_REAL lUserParam);

/**
* ��ȡĳ��ͨ����ý����������Ϣ��\n
* @param [IN] ulPort                        ����ͨ���š�
* @param [OUT] pcMediaReceiveIp             ý��������IP��ַ
* @param [OUT] pusMediaReceivePort          ý���������˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
* - 1����#IMOS_XP_StartPlay֮����ã���#IMOS_XP_StopPlayʱ�Զ�ʧЧ
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetMediaReceiveInfo(IN ULONG_32 ulPort,
                                                                OUT CHAR *pcMediaReceiveIp,
                                                                OUT USHORT *pusMediaReceivePort);

/**
* ������ر�ý�������������ܡ�\n
* @param [IN] ulPort                        ����ͨ���š�
* @param [IN] bOpen                         �Ƿ�������������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
* - 1����#IMOS_XP_StartPlay֮����ã���#IMOS_XP_StopPlayʱ�Զ�ʧЧ
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetCrossStream(IN ULONG_32 ulPort,
                                                           IN const BOOL_T bOpen);

/**
* �򿪱��ز����ļ��������ļ���������\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcFileName    �����ļ����ļ����������ļ�·������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ��������Ƿ�
* -         #ERR_XP_PORT_NOT_AVAILABLE           ����ͨ��������
* -         #ERR_COMMON_NO_MEMORY                ϵͳ�ڴ治��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ò���ͨ������Դʧ��
* -         #ERR_XP_NOT_SUPPORT_FILE_FORMAT      �ļ����Ÿ�ʽ��֧��
* -         #ERR_XP_FAIL_TO_GET_TOTAL_TIME       ����ļ��ܵĲ���ʱ��ʧ��
* -         #ERR_XP_FAIL_TO_OPEN_FILE            ���������ļ�����ʧ��(�ļ������ڻ������ڱ���������ʹ��)
* -         #ERR_XP_FILE_DESTROY                 ��Ҫ�򿪵��ļ�̫С�����Ѿ���
* -         #ERR_XP_FILE_HAVE_OPEN               ָ��ͨ���Ѿ������ļ�
* @note �ޡ�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_OpenFileBuildIndex(IN ULONG_32 ulPort,
                                                               IN const CHAR *pcFileName);

/**
* ������ʾOSD
* @param [IN] ulPort        ����ͨ����
* @param [IN] pstOsdList    OSD��Ϣ�б�
* @param [IN] ulOsdNum      OSD����
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_XP_FAIL_TO_SET_OSD             ������ʾosdʧ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* @note
* - 1�����øýӿڿ�ʼ��ʾָ����OSD��ֱ������IMOS_XP_StopOSD��OSD��ʧ��
* - 2���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartOSD(IN ULONG_32 ulPort,
                                                     IN const XP_OSD_OVER_INFO_S *pstOsdList,
                                                     IN ULONG_32 ulOsdNum);

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_AddOSD(IN ULONG_32 ulPort,
													  IN const XP_OSD_OVER_INFO_S *pstOsdList,
													  IN ULONG_32 ulOsdNum);
/************************************************************************/
/* ��ѯOSD��Ϣ(��Ҫ��OSD�����򣬳��Ϳ�) 
* @param [IN] ulPort        ����ͨ����
* @param [INOUT] pstOsdList    OSD��Ϣ�б�
* @param [IN] ulOsdNum      OSD����
* @return �������½����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* @note
* - ���ص��ǵ���IMOS_AddOsd�ӿ���ӵ�OSD��������ʱ��OSD

*/
/************************************************************************/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_QueryOSD(IN ULONG ulPort,
                                                        INOUT XP_OSD_OVER_INFO_S *pstOsdList,
                                                        IN ULONG_32 ulOsdNum);												  

/**
* ��λ��ʾOSD
* @param [IN] ulPort        ����ͨ����
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_XP_FAIL_TO_STOP_OSD            ֹͣ��ʾosdʧ��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò���ͨ����Դʧ��
* @note
* - 1���ýӿں�����֧��Windows��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StopOSD(IN ULONG_32 ulPort);

/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */
/**
* ���û�ȡ�㲥�ط�ʱ��Ļص����� \n
* @param [IN]  ulPort                   ����ͨ���š�
* @param [IN]  pfnGetVodTimeCBFun       ��ȡ�㲥�ط�ʱ��Ļص�����ָ�롣
* @param [IN]  lUserParam               �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_PORT_NOT_REGISTER                ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note �ޡ�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetVodTimeCB(IN ULONG_32 ulPort,
                                                   IN XP_PLAYER_GET_VODTIME_CALLBACK_PF pfnGetVodTimeCBFun,
                                                   IN LONG_REAL lUserParam);
/* END: Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */


/**
* ���������ʽ��Ϣ��\n
* @param [IN] ulPort                        ����ͨ���š�
* @param [IN] pulStreamType                 ������ʽ��Ϣ(����Ϊ#XP_MEDIA_FILE_FORMAT_E����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* @note
* - 1����#IMOS_XP_StartPlay֮�����
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetStreamType(IN ULONG_32 ulPort,
                                                          OUT ULONG_32 *pulStreamType);
/**
* ����ת�����������ڲ��ӿڣ���\n
* @param [IN] ulPort                  ����ͨ���š�
* @param [IN] pstTrans         ת�����Ƶͼ��ֱ�����Ϣ  NULL Ϊ�ر�

* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         ERR_COMMON_INVALID_PARAM                 ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
@note �ڵ��øýӿ�ǰ����Ҫȫ�ֵ���IMOS_XP_SetVideoDecodeMode ,ѡ��GPUģʽ
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetTransParam(IN ULONG_32 ulPort,
                                                                IN const XP_TRANS_PARAM_S *pstPicDimension);

/**
* ���ò��Ż�����ʱ����Ƶ������Ĭ��Ϊ��������\n
* @param [IN] ulPort      ����ͨ����
* @param [IN] ulSoundChannel     �������������#XP_AUDIO_CHANNEL_Eö����ȡֵ

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
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetSoundChannel(IN ULONG_32 ulPort, IN ULONG_32 ulSoundChannel);

/**
* �����Ƿ�������������\n
* @param [IN] bResistLost �Ƿ�����������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_SET_PARAM            ���ò����������ò���ʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_ResistLost(IN BOOL_T bResistLost);

/**
* ����xp��֪ͨ���ĵĽ��ն˵�ַ\n
* @param [IN] ulPort          ����ͨ���š�
* @param [IN] pcFeedbackIP       ������֪ͨ���ĵĽ��ն˵�ַ��
* @param [IN] usFeedbackPort      ������֪ͨ���ĵĽ��ն˼����˿ڡ�
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ���ò���ͨ��ʧ��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetFeedbackAddr(IN ULONG_32 ulPort,
                                                            IN const CHAR *pcFeedbackIP,
                                                            IN USHORT usFeedbackPort);

/**
* ����¼���������ͣ\�\\n
* @param [IN] pstUserLoginIDInfo  �û���¼ID��Ϣ��ʶ��
* @param [IN] pcChannelCode      ������Դ���롣
* @param [IN] ulType              ��ö��ֵ  0 both,1 only video, 2 video and left audio, 3,vidoe and right audio
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
            ���������������
* @note �ýӿ�IMOS_XP_StartRecord��֮ǰ����
*/

IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRecordDataType(IN ULONG_32 ulPort,
                                                                            IN XP_MEDIATYPE_E enMediaType);

/* ����ת��¼��\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] pcFileName        ¼���ļ����·���������ļ�����������׺������
* @param [IN] ulMediaFileFormat ¼���ļ��ĸ�ʽ�����#XP_MEDIA_FILE_FORMAT_Eö����ȡֵ��
* @param [IN] pstParam          ת�����
* @param [OUT] pcFilePostfix    ���¼���ļ���׺��ָ�룬����������Ӧ��С��#IMOS_XP_FILE_POSTFIX_LEN��
*                               ����û�����Ҫ���غ�׺�����ɽ��ò�������ΪNULL��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                          �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                    ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES                 ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                       ͨ��δ��ʼ���Ų���
* -         #ERR_XP_ALREADY_START_RECORD_VIDEO           ָ���Ĳ���ͨ���Ѿ�����¼�����
* -         #ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT      ¼���ʽ��֧��
* -         #ERR_XP_DISK_CAPACITY_NOT_ENOUGH             Ӳ�̿ռ䲻��
* -         #ERR_XP_NOT_SUPPORT                          ��֧�ָù���
* -         #ERR_XP_FAIL_TO_START_RECORD_VIDEO           ��������¼��ʧ��
* @note
* -    1��������������ý������ʽ���ļ�������׷�Ӷ�Ӧ�ĺ�׺������TS��¼���ļ��ĺ�׺Ϊ.ts��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_StartConvertToFile(IN ULONG_32 ulPort,
                                                                  IN const CHAR *pcFileName,
                                                                  IN ULONG_32 ulMediaFileFormat,
                                                                  IN const XP_ENCODE_PARAM_S *pstParam,
                                                                  OUT CHAR *pcFilePostfix);

/* ֹͣת��¼��\n
* @param [IN] ulPort            ����ͨ���š�
* @return VOID
* @note ��
*/
IMOS_XP_PLAYER_EXPORT VOID STDCALL IMOS_XP_StopConvertToFile(IN ULONG_32 ulPort);

/* ��ѯָ���Ĳ���ͨ���Ƿ��ڻ״̬��\n
* @param [IN] ulPort            ����ͨ���š�
* @return VOID
* @note ��
*/
IMOS_XP_PLAYER_EXPORT BOOL_T STDCALL IMOS_XP_IsPortActive(IN ULONG_32 ulPort);

/**
* ����Ͱ�ͽ����\�\\n
* @param [IN] ulPort                    ����ͨ����
* @param [IN] bOpen                     �Ƿ���Ͱ�ͽ������ܡ�
* @param [IN] enBarrelAjustLevel        Ͱ�ͽ����ȼ������#XP_BARREL_ADJUST_LEVEL_Eö��ֵ��ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
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
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetBarrelAdjust(IN ULONG_32 ulPort,
                                                       IN BOOL_T bOpen,
                                                       IN XP_BARREL_ADJUST_LEVEL_E enBarrelAjustLevel);

/**
* ����ָ������ͨ����ҵ�����͡�\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] ulRenderScale     ��Ƶͼ���ڲ���ͨ���ϵ���ʾ���������#PORT_MEDIA_SVC_TYPE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* @note
* -    1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ������������Ŵ���

*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMediaSvcType(IN ULONG_32 ulPort,
                                                               IN ULONG_32 ulMediaSvcType);

/* Begin add by sunbiao/sW1071 2014.10.28 for MPPD18406 ����dspȥ���� */
/**
* ������Ƶȥ���������\�\\n
* @param [IN] ulPort                    ����ͨ����
* @param [IN] bOpen                     �Ƿ���ȥ�������ܡ�
* @param [IN] stDeshakeParm             ȥ��������,�ṹ��XP_DESHAKE_PARM_S ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_COMMON_INVALID_PARAM               ���������Ч
* -         #ERR_XP_PORT_NOT_REGISTER               ����ͨ��û��ע��
* -         #ERR_XP_FAIL_TO_GET_PORT_RES            ��ò���ͨ����Դʧ��
* -         #ERR_XP_NOT_START_PLAY                  ����ͨ��δ��ʼ���Ų���
* -         #ERR_XP_NOT_SUPPORT                     ��֧�ָù���
* -         #ERR_XP_FAIL_TO_SET_DESHAKE             ����ȥ����ʧ��
* @note
*       ��֧��320 * 240�����·ֱ��ʣ���dsp���Ż�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetDeshake(IN ULONG_32 ulPort,
                                                  IN BOOL_T bOpen,
                                                  IN XP_DESHAKE_PARM_S &stDeshakeParm);
/* End add by sunbiao/sW1071 2014.10.28 for MPPD18406 ����dspȥ���� */

/**
* ����IA GPU����⡣\n
* @param [IN] ulPort                   ����ͨ���š�
* @param [IN] bEnable                  �Ƿ�����IA GPU����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_ENABLE_IA_GPU_DECODE     ���ý����ʧ��
* @note
*      1���ú����ڴ���ͨ����Դ֮����ã��ͷ�ͨ����Դ��ʧЧ��
*      2���ú�����֧����˾h264���룬��h264����ʱ��תΪ��⡣
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_EnableIAGpuDecode(IN ULONG_32 ulPort,
                                                                 IN BOOL_T bEnable);

/**
* ������ر���ʾ���ܹ��ܡ�\n
* @param [IN] ulPort                        ����ͨ���š�
* @param [IN] bOpen                         �Ƿ���������ʾ
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetDisplayIntelligence(IN ULONG_32 ulPort, IN BOOL_T bOpen);

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP�ͻ���¼��ʱ֧�ִ�С���� */
/**
* ���÷ֶ�¼��ʱ, �ļ���С���ޡ�\n
* @param [IN] ulPort                             ����ͨ����
* @param [IN]  ulMaxRecordSize                   ¼���ļ������ֵ, ��λΪM��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ȡͨ��ʧ��
* -         #ERR_PUBLIC_ACQUIRE_MUTEX_FAIL       ��ȡ��ʧ��
* -         #ERR_COMMON_INVALID_PARAM            ��������
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetMaxRecordSize(IN ULONG_32 ulPort, IN ULONG_32 ulMaxRecordSize);

/**
* ����¼��ֶ��ļ������ɷ�ʽ��\n
* @param [IN]  ulPort                            ����ͨ���š�
* @param [IN]  ulRecSegmentNameMode                  ����¼��ֶ��ļ�����ģʽ�����#FILENAME_SPECIFY_MODE_Eö����ȡֵ��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES         ��ȡͨ��ʧ��
* -         #ERR_PUBLIC_ACQUIRE_MUTEX_FAIL       ��ȡ��ʧ��
* -         #ERR_COMMON_INVALID_PARAM            ��������
* @note
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetRecSegmentNameMode(IN ULONG_32 ulPort,
                                                                     IN ULONG_32 ulRecSegmentNameMode);

/**
* ���û�ȡ��ǰ���ؽ�������ص�������\n
* @param [IN]  ulPort                   ����ͨ���š�
* @param [IN]  pfnGetCurDownPosCBFun    ��ȡ��ǰ���ؽ�������ص�������ָ�롣
* @param [IN]  lUserParam               �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_PORT_NOT_REGISTER                ָ���Ĳ���ͨ��û��ע��
* -         #ERR_XP_NOT_START_PLAY                   ָ���Ĳ���ͨ��δ��ʼ���Ų���
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* -         #ERR_XP_FAIL_TO_SET_CUR_POS_CB           ����setCurDownPosCallback�ص�����ʧ��
* @note �ޡ�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 IMOS_XP_SetCurDownPosCB(IN ULONG_32 ulPort,
                                                       IN XP_PLAYER_GET_CURDOWNPOS_CALLBACK_PF pfnGetCurDownPosCBFun,
                                                       IN LONG_REAL lUserParam);
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP�ͻ���¼��ʱ֧�ִ�С���� */

/**
* ����ƴ֡ǰý�������ݻص�������\n
* @param [IN] ulPort                  ����ͨ���š�
* @param [IN] pfnSourceMediaDataCBFun ƴ֡ǰý�������ݻص�������ָ�롣
* @param [IN] bContinue               �Ƿ�������к����ƴ֡���������ʾ������
* @param [IN] lUserParam              �û����ò�����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* -         #ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB      ����ý�������ݻص�����ʧ��
* @note
*      1���ú�����IMOS_XP_StartPlay֮ǰ��֮����ã���IMOS_XP_StopPlayʱ�Զ�ʧЧ��
*      2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ����ΪNULL��
*      3��Ŀǰֻ��bContinueΪfalse����Ч��
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetSourceMediaDataCBEx(IN ULONG_32 ulPort,
                                                                 IN XP_PLAYER_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun,
                                                                 IN BOOL_T bContinue,
                                                                 IN LONG_REAL lUserParam);

/**
* ��ȡý����������\n
* @param [IN] ulPort            �˿ں�
* @param [OUT] pstMediaAbility              ý��������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ��������Ƿ�
* -         #ERR_XP_PORT_NOT_REGISTER                ����ͨ��û��ע��
* @note
* - 1����#IMOS_StartPlay֮����ã���#IMOS_StopPlayʱ�Զ�ʧЧ
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetMediaAbilityInfo(IN ULONG_32 ulPort,
                                                                OUT XP_MEDIA_ABILITY_S *pstMediaAbility);

/**
* ����ͨ���Ĵ�������Ϣ��\n
* @param [IN] ulPort        ����ͨ���š�
* @param [IN] pcProcxyDecoderTag  �����������ǩ��Ŀǰ֧�ֵĳ��̽������У�"h3c-v3"��ʾH3C V3�汾��������
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_COMMON_INVALID_PARAM           ��������Ƿ�
* -         #ERR_XP_FAIL_TO_GET_PORT_RES        ��ò��Ŵ��ڵ���Դʧ��
* @note ����û�û�е��øú������򲥷���XP�ڸ�ͨ��Ĭ��ʹ��H3C V3�汾�Ľ�������
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetProcxyDecoderTag(IN ULONG_32 ulPort,
                                                                IN const CHAR *pcProcxyDecoderTag);

/**
* ���ü��������Ϣ��\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] ulScrambleKey    ����KEY��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* @note �����ַ����������ж��壬�����շ�˫�����뱣��һ�£����Դ����ַ�������ָ�벻��Ϊ�ա�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetScrambleKey(IN ULONG_32 ulPort,
															   IN const ULONG ulScrambleKey);

/**
* ���ûط���ǽ����Ϣ��\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] pcScrambleMode    ����ģʽ��
* @param [IN] pcScrambleKey     ����KEY(δ������������)��
* @param [IN] pcCameraCode      ��������롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* @note �����ַ����������ж��壬�����շ�˫�����뱣��һ�£����Դ����ַ�������ָ�벻��Ϊ�ա�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetScrambleInfo(IN ULONG_32 ulPort,
                                                              IN CHAR *pcScrambleMode,
                                                              IN CHAR *pcScrambleKey,
                                                              IN CHAR *pcCameraCode);

/**
* ��ȡ�ط���ǽ����Ϣ��\n
* @param [IN] ulPort            ����ͨ���š�
* @param [OUT] pcScrambleMode    ����ģʽ��
* @param [OUT] pcScrambleKey     ����KEY(δ������������)��
* @param [OUT] pcCameraCode      ��������롣
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* @note �����ַ����������ж��壬�����շ�˫�����뱣��һ�£����Դ����ַ�������ָ�벻��Ϊ�ա�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetScrambleInfo(IN ULONG_32 ulPort,
                                                               OUT CHAR *pcScrambleMode,
                                                               OUT CHAR *pcScrambleKey,
                                                               OUT CHAR *pcCameraCode);

/**
* ��ȡ����¼���еı�ʶ��Ϣ��\n
* @param [IN] ulPort            ����ͨ���š�
* @param [IN] ulScrambleKey     ����KEY��
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                      �ɹ�
* -         #ERR_COMMON_INVALID_PARAM                ���������Ч
* -         #ERR_XP_FAIL_TO_GET_PORT_RES             ��ò���ͨ����Դʧ��
* @note �����ַ����������ж��壬�����շ�˫�����뱣��һ�£����Դ����ַ�������ָ�벻��Ϊ�ա�
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_GetFileScrambleInfo(IN ULONG_32 ulPort,
                                                                   IN OUT CHAR *strCamCode);
																   
																   /**
* ���۽������á�\n
* @param [IN] ulPort                ����ͨ����
* @param [IN] pstWorkInterfaceParam �㷨����1֡����
* @return �������´����룺
* -         #ERR_COMMON_SUCCEED                  �ɹ�
* -         #ERR_COMMON_INVALID_PARAM            ���������Ч
            #ERR_COMMON_FAIL                     ִ��ʧ��
* @note 
*/
IMOS_XP_PLAYER_EXPORT ULONG_32 STDCALL IMOS_XP_SetFishAdjust(IN ULONG_32 ulPort,
                                                IN  IMOS_uintptr_t pstWorkInterfaceParam);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_XP_PLAYER_INNER_H_ */
