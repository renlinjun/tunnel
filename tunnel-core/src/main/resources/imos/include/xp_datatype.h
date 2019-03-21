/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              xp_datatype.h

  Project Code: IMOSͨ��ý�岥����
   Module Name: IMOSͨ��ý�岥����
  Date Created: 2008-09-10
        Author: shiyouhua/04562
   Description: ������XP�Ĵ���������ݽṹ���Ͷ���ͷ�ļ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_MEDIA_PLAY_SDK_DATA_TYPE_H_
#define _IMOS_MEDIA_PLAY_SDK_DATA_TYPE_H_

/************************************************************************/
/*********************** XP SDK�����붨��********************************/
/**********************[0x000700��0x0008FF] *****************************/
/************************************************************************/

/* ������ֹͣ������XP���ش����� */
#define ERR_XP_FAIL_TO_REG_BP_CMD                       0x000700        /**< ������XP����ģ�������ƽ̨BPע��ʧ�� */
#define ERR_XP_FAIL_TO_INIT_XP                          0x000701        /**< ��ʼ��������XPʧ�� */
#define ERR_XP_FAIL_TO_CLEANUP_XP                       0x000702        /**< �ͷŲ�����XP��Դʧ�� */
#define ERR_XP_FAIL_TO_START_XP                         0x000703        /**< ����������XPʧ�� */
#define ERR_XP_FAIL_TO_STOP_XP                          0x000704        /**< ֹͣ������XPʧ�� */
#define ERR_XP_FAIL_TO_REGIST_XP                        0x000705        /**< ע�Ქ����XPʧ�� */
#define ERR_XP_FAIL_TO_UNREGIST_XP                      0x000706        /**< ע��������XPʧ�� */
#define ERR_XP_FAIL_TO_SET_PARAM                        0x000707        /**< ���ò�����XP�����ò���ʧ�� */
#define ERR_XP_EXCEED_MAX_PLAY_WINDOW_NUM               0x000708        /**< ע��Ĳ��Ŵ������ѳ��������֧�ֵĲ��Ŵ����� */
#define ERR_XP_WINDOW_ALREADY_SET                       0x000709        /**< ͨ���ѱ�ע�� */
#define ERR_XP_EXCEED_MAX_PLAY_PORT_NUM                 0x00070A        /**< ע��Ĳ���ͨ�����ѳ��������֧�ֵĲ���ͨ���� */
#define ERR_XP_NOT_SUPPORT                              0x00070B        /**< ��֧�ָù���*/
#define ERR_XP_UNKNOWN_ERROR                            0x00070C        /**< δ֪����*/

/* ���غ��ͷŶ�̬����Դ���ش����� */
#define ERR_XP_DLL_NOT_EXIST                            0x000720        /**< ָ���Ķ�̬�ⲻ���� */
#define ERR_XP_FAIL_TO_LOAD_DLL                         0x000721        /**< ���ض�̬��ʧ�� */
#define ERR_XP_FAIL_TO_UNLOAD_DLL                       0x000722        /**< ж�ض�̬��ʧ�� */
#define ERR_XP_FAIL_TO_WRITE_FILE                       0x000723        /**< д�ļ�����ʧ�� */
#define ERR_XP_FAIL_TO_INIT_DLL                         0x000724        /**< ��̬���ʼ��ʧ�� */
#define ERR_XP_FUNCTION_CALL_ORDER_ERROR                0x000725        /**< ��������˳����� */

/* ������XPý��������ش����� */
#define ERR_XP_WINDOW_NOT_REGISTER                      0x000730        /**< ���Ŵ���û��ע�� */
#define ERR_XP_PORT_NOT_AVAILABLE                       0x000731        /**< ͨ�������� */
#define ERR_XP_FAIL_TO_GET_PORT_RES                     0x000732        /**< ��ò���ͨ����Դʧ�� */
#define ERR_XP_NOT_SUPPORT_MEDIA_SVC                    0x000733        /**< ����ͨ����ý��ҵ�����Ͳ�֧�ִ˲��� */
#define ERR_XP_PORT_NOT_REGISTER                        0x000734        /**< ����ͨ��û��ע�� */
#define ERR_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE            0x000735        /**< ����ͨ����ý������ʽ��֧�ִ˲��� */
#define ERR_XP_MEDIA_RESOLUTION_CHANGE                  0x000736        /**< ����ͨ����ý�����ֱ��ʷ����仯 */
#define ERR_XP_FAIL_TO_START_IMAGE                      0x000737        /**< ��ͼƬ����ģʽʧ�� */
#define ERR_XP_FAIL_TO_LOAD_IMAGE                       0x000738        /**< ����ͼƬʧ�� */
#define ERR_XP_FAIL_TO_STOP_IMAGE                       0x000739        /**< �ر�ͼƬ����ģʽʧ�� */
#define ERR_XP_FAIL_TO_JOIN_FILE                        0x000740        /**< �ļ��ϲ�ʧ�� */
#define ERR_XP_FAIL_TO_OPEN_REALTIME                    0x000741        /**< ����ʵʱ���ҵ��ʧ�� */
#define ERR_XP_FAIL_TO_OPEN_VOD                         0x000742        /**< �����㲥�ط�ҵ��ʧ�� */
#define ERR_XP_FAIL_TO_OPEN_FILE                        0x000743        /**< ���������ļ��ط�ҵ��ʧ��(�û�û��Ȩ�ޣ����߸��ļ����ڱ���������ʹ��) */
#define ERR_XP_FAIL_TO_START_PLAY                       0x000744        /**< ��ʼ����ʧ�� */
#define ERR_XP_FAIL_TO_PAUSE                            0x000745        /**< ��ͣ����ʧ�� */
#define ERR_XP_FAIL_TO_RESUME                           0x000746        /**< �ָ�����ʧ�� */
#define ERR_XP_FAIL_TO_STOP_PLAY                        0x000747        /**< ֹͣ����ʧ�� */
#define ERR_XP_FAIL_TO_MULTIPL_SPEED_PLAY               0x000748        /**< ����ǰ��/���˲���ʧ�� */
#define ERR_XP_FAIL_TO_STEP_PLAY                        0x000749        /**< ��֡����ʧ�� */
#define ERR_XP_FAIL_TO_DRAG_PLAY                        0x00074A        /**< ��ת����ʧ�� */
#define ERR_XP_FAIL_TO_GET_PLAY_POSITION                0x00074B        /**< ��õ�ǰ���Ž���ʧ�� */
#define ERR_XP_FAIL_TO_QUIET                            0x00074C        /**< ���û�ֹͣ��������ʧ�� */
#define ERR_XP_FAIL_TO_ADJUST_VOLUME                    0x00074D        /**< ��������ʧ�� */
#define ERR_XP_FAIL_TO_GET_VOLUME                       0x00074E        /**< �������ֵʧ�� */
#define ERR_XP_FAIL_TO_SNATCH_ONCE                      0x00074F        /**< ����ץ��ʧ�� */
#define ERR_XP_FAIL_TO_START_SERIES_SNATCH              0x000750        /**< ��������ץ��ʧ�� */
#define ERR_XP_FAIL_TO_SERIES_SNATCH                    0x000751        /**< ����ץ�Ĺ�����ץ��ʧ�� */
#define ERR_XP_FAIL_TO_STOP_SERIES_SNATCH               0x000752        /**< ֹͣ����ץ��ʧ�� */
#define ERR_XP_FAIL_TO_START_RECORD_VIDEO               0x000753        /**< ��������¼��ʧ�� */
#define ERR_XP_FAIL_TO_STOP_RECORD_VIDEO                0x000754        /**< ֹͣ����¼��ʧ�� */
#define ERR_XP_FAIL_TO_RECORD_VIDEO                     0x000755        /**< ����¼������г��� */
#define ERR_XP_FAIL_TO_START_RECORD_AUDIO               0x000756        /**< ����¼��ʧ�� */
#define ERR_XP_FAIL_TO_STOP_RECORD_AUDIO                0x000757        /**< ֹͣ¼��ʧ�� */
#define ERR_XP_FAIL_TO_RECORD_AUDIO                     0x000758        /**< ¼�������г��� */
#define ERR_XP_DOWNLOAD_PORT_NUM_LIMIT                  0x000759        /**< �����������ͨ���� */
#define ERR_XP_FAIL_TO_START_DOWNLOAD                   0x00075A        /**< ��������¼��ʧ�� */
#define ERR_XP_FAIL_TO_GET_DOWNLOAD_POSITION            0x00075B        /**< ��õ�ǰ¼�����ؽ���ʧ�� */
#define ERR_XP_MIC_NOT_EXIST                            0x00075C        /**< ϵͳ����˷����䲻���� */
#define ERR_XP_NO_PICTURE_TO_SNATCH                     0x00075D        /**< û�н������ͼƬ�ɹ�ץ�� */
#define ERR_XP_DECODE_AUDIO_NOT_CONTINUE                0x00075E        /**< ��Ƶ�����ݽ���󲻼������в��Ų��� */
#define ERR_XP_FAIL_TO_OPEN_DOWNLOAD                    0x00075F        /**< ��������ҵ��ʧ�� */
#define ERR_XP_IN_PAUSE_PLAY_STATUS                     0x000760        /**< ��ǰ��������ͣ����״̬ */
#define ERR_XP_IN_MULTIPL_SPEED_PLAY_STATUS             0x000761        /**< ��ǰ�����ڱ��ٲ���״̬ */
#define ERR_XP_IN_STEP_PLAY_STATUS                      0x000762        /**< ��ǰ�����ڵ�֡����״̬ */
#define ERR_XP_IN_RECORD_VIDEO_STATUS                   0x000763        /**< ��ǰ�����ڱ���¼��״̬ */
#define ERR_XP_NOT_SUPPORT_DOWNLOAD_FORMAT              0x000764        /**< ���ظ�ʽ��֧�� */
#define ERR_XP_NOT_SUPPORT_SET_CONTRAST                 0x000765        /**< ����ͨ����֧������ͼ��ԱȶȲ��� */
#define ERR_XP_FAIL_TO_SET_CONTRAST                     0x000766        /**< ����ͼ��ԱȶȲ���ʧ�� */
#define ERR_XP_FAIL_TO_OPEN_VOICE_TALKBACK              0x000767        /**< ���������Խ�ʧ�� */
#define ERR_XP_FAIL_TO_CLOSE_VOICE_TALKBACK             0x000768        /**< ֹͣ�����Խ�ʧ�� */
#define ERR_XP_FAIL_TO_OPEN_VOICE_BROADCAST             0x000769        /**< ���������㲥ʧ�� */
#define ERR_XP_FAIL_TO_CLOSE_VOICE_BROADCAST            0x00076A        /**< ֹͣ�����㲥ʧ�� */
#define ERR_XP_ALREADY_START_VOICE_TALKBACK             0x00076B        /**< �����Խ��Ѿ����� */
#define ERR_XP_ALREADY_START_VOICE_BROADCAST            0x00076C        /**< �����㲥�Ѿ����� */
#define ERR_XP_NOT_START_VOICE_SVC                      0x00076D        /**< δ��������ҵ�� */
#define ERR_XP_NOT_START_VOICE_TALKBACK                 0x00076E        /**< δ���������Խ�ҵ�� */
#define ERR_XP_NOT_START_VOICE_BROADCAST                0x00076F        /**< δ���������㲥ҵ�� */
#define ERR_XP_FAIL_TO_VOICE_SILENCE                    0x000770        /**< ������ֹͣ�������Զ˷�����������ʧ�� */
#define ERR_XP_FAIL_TO_GET_LOST_PKT_RATE                0x000771        /**< ��õ�ǰ����������ʧ�� */
#define ERR_XP_FAIL_TO_RESET_LOST_PKT_RATE              0x000772        /**< ��λ������ʧ�� */
#define ERR_XP_FAIL_TO_GET_FRAME_RATE                   0x000773        /**< ��õ�ǰ֡������ʧ�� */
#define ERR_XP_FAIL_TO_GET_BIT_RATE                     0x000774        /**< ��õ�ǰ��������ʧ�� */
#define ERR_XP_FAIL_TO_RESET_BUFFER                     0x000775        /**< ��ջ�����ʧ�� */
#define ERR_XP_FAIL_TO_SET_FIELD_MODE                   0x000776        /**< ���ý��볡ģʽʧ�� */
#define ERR_XP_FAIL_TO_ENABLE_DEINTERLACE               0x000777        /**< ������ر�ȥ��֯����ʧ�� */
#define ERR_XP_FAIL_TO_SET_DEINTERLACE_MODE             0x000778        /**< ����ȥ��֯����ģʽʧ�� */
#define ERR_XP_FAIL_TO_INPUT_DATA                       0x000779        /**< ����ý��������ʧ�� */
#define ERR_XP_NOT_SUPPORT_STREAM_FORMAT                0x00077A        /**< ��֧�ֵ��������� */
#define ERR_XP_FAIL_TO_SET_PROCESS_DATA_CB              0x00077B        /**< ����ý�������ݻص�����ʧ�� */
#define ERR_XP_FAIL_TO_ENABLE_OUTPUT_DATA               0x00077C        /**< ������رս����ý�����������ʧ�� */
#define ERR_XP_FAIL_TO_SET_PORT_PARAM                   0x00077D        /**< ����ͨ���Ĳ���ʧ�� */
#define ERR_XP_FAIL_TO_START_VOICE_SVC                  0x00077E        /**< ��������ҵ��ʧ�� */
#define ERR_XP_FAIL_TO_STOP_VOICE_SVC                   0x00077F        /**< ֹͣ����ҵ��ʧ�� */
#define ERR_XP_FAIL_TO_GET_LOST_FRAME_RATE              0x000780        /**< ��õ�ǰ��֡������ʧ�� */
#define ERR_XP_FAIL_TO_RESET_LOST_FRAME_RATE            0x000781        /**< ��λ��֡��ʧ�� */
#define ERR_XP_FAIL_TO_SET_WAVEIN_MOD                   0x000782        /**< ������Ƶ����Դʧ�� */
#define ERR_XP_FAIL_TO_SET_RENDER_SCALE                 0x000783        /**< ����ͼ����ʾ��������ʧ�� */
#define ERR_XP_ALREADY_START_SERIES_SNATCH              0x000784        /**< ����ͨ���Ѿ���������ץ�Ĳ��� */
#define ERR_XP_ALREADY_START_RECORD_VIDEO               0x000785        /**< ����ͨ���Ѿ���������¼����� */
#define ERR_XP_ALREADY_START_RECORD_AUDIO               0x000786        /**< ����ͨ���Ѿ�����¼������ */
#define ERR_XP_NOT_START_SERIES_SNATCH                  0x000787        /**< ����ͨ��δ��������ץ�Ĳ��� */
#define ERR_XP_NOT_START_RECORD_VIDEO                   0x000788        /**< ����ͨ��δ��������¼����� */
#define ERR_XP_NOT_START_RECORD_AUDIO                   0x000789        /**< ����ͨ��δ����¼������ */
#define ERR_XP_ALREADY_START_OUTPUT_MEDIA               0x00078A        /**< ����ͨ���Ѿ�����ý����������� */
#define ERR_XP_ALREADY_STOP_OUTPUT_MEDIA                0x00078B        /**< ����ͨ��δ����ý����������� */
#define ERR_XP_FINISH_SERIES_SNATCH                     0x00078C        /**< �������ץ������ */
#define ERR_XP_PORT_NOT_EXIST                           0x00078D        /**< ͨ�������� */
#define ERR_XP_PORT_ALREADY_EXIST                       0x00078E        /**< ͨ���Ѿ����� */
#define ERR_XP_PORT_ALREADY_OPEN                        0x00078F        /**< ͨ���Ѿ����� */
#define ERR_XP_PORT_NOT_OPEN                            0x000790        /**< ͨ��δ��ý��ҵ�� */
#define ERR_XP_NOT_START_PLAY                           0x000791        /**< ����ͨ��δ��ʼ���Ų��� */
#define ERR_XP_FAIL_TO_OPEN_NET_MEDIA                   0x000792        /**< ������ý��ʧ�� */
#define ERR_XP_FAIL_TO_PLAY_MEDIA                       0x000793        /**< ý�岥�Ŵ���ʧ�� */
#define ERR_XP_FAIL_TO_PAUSE_MEDIA                      0x000794        /**< ��ͣý�岥�Ŵ���ʧ�� */
#define ERR_XP_FAIL_TO_RESUME_MEDIA                     0x000795        /**< �ָ�ý�岥�Ŵ���ʧ�� */
#define ERR_XP_FAIL_TO_STOP_MEDIA                       0x000796        /**< ֹͣý�岥�Ŵ���ʧ�� */
#define ERR_XP_NOT_SUPPORT_FILE_FORMAT                  0x000797        /**< �ļ����Ÿ�ʽ��֧�� */
#define ERR_XP_NOT_SUPPORT_SNATCH_FORMAT                0x000798        /**< ץ�ĸ�ʽ��֧�� */
#define ERR_XP_NOT_SUPPORT_RECORD_VIDEO_FORMAT          0x000799        /**< ¼���ʽ��֧�� */
#define ERR_XP_NOT_SUPPORT_RECORD_AUDIO_FORMAT          0x00079A        /**< ¼����ʽ��֧�� */
#define ERR_XP_DISK_CAPACITY_WARN                       0x00079B        /**< Ӳ��ʣ��ռ������ֵ */
#define ERR_XP_DISK_CAPACITY_NOT_ENOUGH                 0x00079C        /**< Ӳ��ʣ��ռ䲻�㣬�޷�����ҵ�� */
#define ERR_XP_FAIL_TO_GET_TOTAL_TIME                   0x00079D        /**< ����ļ��ܵĲ���ʱ��ʧ�� */
#define ERR_XP_FINISH_PLAY_FILE                         0x00079E        /**< �ļ��Ѿ�������� */
#define ERR_XP_FILE_DESTROY                             0x00079F        /**< �ļ����� */
#define ERR_XP_FILE_HAVE_OPEN                           0x0007A0        /**< ͨ���Ѿ����ļ� */
#define ERR_XP_FAIL_TO_DECODE_VIDEO                     0x0007A1        /**< ��Ƶ����ʧ�� */
#define ERR_XP_FAIL_TO_DECODE_AUDIO                     0x0007A2        /**< ��Ƶ����ʧ�� */
#define ERR_XP_NOT_SUPPORT_MEDIA_STREAM_TYPE            0x0007A3        /**< ��֧�ֵ�ý���������� */
#define ERR_XP_NOT_SUPPORT_TRANSPORT_PROTOCOL_TYPE      0x0007A4        /**< ��֧�ֵĴ����Э������ */
#define ERR_XP_FAIL_TO_RECV_DATA                        0x0007A5        /**< ������ϵ��½�������ʧ�� */
#define ERR_XP_FAIL_TO_SEND_DATA                        0x0007A6        /**< ������ϵ��·�������ʧ�� */
#define ERR_XP_FAIL_TO_OPERATE_AUDIO_EQUIPMENT          0x0007A7        /**< ��Ƶ�豸����ʧ�� */
#define ERR_XP_FAIL_TO_GET_VIDEO_ENCODE_TYPE            0x0007A8        /**< �����Ƶ�����ʽʧ�� */
#define ERR_XP_FAIL_TO_PROCESS_MEDIA_DATA               0x0007A9        /**< ý�����ݴ���ʧ�� */
#define ERR_XP_FAIL_TO_START_REALREPLAY                 0x0007AA        /**< ��ʼ��ʱ�ط�ʧ�� */
#define ERR_XP_SET_REALREPLAY_TIME_LARGE                0x0007AB        /**< ���ü�ʱ�ط�ʱ��̫�� */
#define ERR_XP_VOICE_RUNNING                            0x0007AC        /**< ����ҵ�����й����г���*/
#define ERR_XP_FAIL_TO_OPEN_STREAM                      0x0007AD        /**< ����ý��������ʧ�� */
#define ERR_XP_FAIL_TO_CREATE_SOCKET                    0x0007AE        /**< Socket����ʧ�� */
#define ERR_XP_PLAY_ALREADY_START                       0x0007AF        /**< ͨ���Ѿ��������� */

/* ����Э�� */
#define ERR_XP_FAIL_TO_SETUP_PROTOCOL                   0x0007B0        /**< ��������Э��ʧ�� */
#define ERR_XP_FAIL_TO_PLAY_PROTOCOL                    0x0007B1        /**< ����Э�̲���ʧ�� */
#define ERR_XP_FAIL_TO_PAUSE_PROTOCOL                   0x0007B2        /**< ����Э����ͣʧ�� */
#define ERR_XP_FAIL_TO_STOP_PROTOCOL                    0x0007B3        /**< ֹͣ����Э��ʧ�� */
#define ERR_XP_RTSP_COMPLETE                            0x0007B4        /**< RTSP���Ż�������� */
#define ERR_XP_RTSP_ABNORMAL_TEATDOWN                   0x0007B5        /**< RTSP�쳣���ߣ���������ȡ�ļ���������ݱ���д */
#define ERR_XP_RTSP_KEEP_LIVE_TIME_OUT                  0x0007B6        /**< RTSP����ʧ�� */
#define ERR_XP_RTSP_ENCODE_CHANGE                       0x0007B7        /**< RTSP��������ʽ�л� */
#define ERR_XP_RTSP_DISCONNECT                          0x0007B8        /**< RTSP���ӶϿ����㲥�طŻ��������Զ���ֹ���������� */
#define ERR_XP_RTSP_DISCONNECT_ONVIF                    0x0007B9        /**< ONVIFʵ��ֱ��ʱ��Rtsp���ӶϿ����ȴ����� */
#define ERR_XP_RTSP_MSREPLAY_VODONWALL_NOTSUPPORT       0x0007BA        /**< ����MS�м̵Ļط���ǽ��֧�� */
#define ERR_XP_RTSP_VODONWALL_FAIL                      0x0007BB        /**< �ط���ǽ����ʧ�� */
#define ERR_XP_SIP_NEGORIATE_TIMEOUT                    0x0007BC        /**< SIPЭ�̳�ʱ */
#define ERR_XP_SIP_SESSION_OVERLAY                      0x0007BD        /**< SIP�Ự�ظ��������ͷ� */
#define ERR_XP_SIP_ONVIF_RECONNECT_TIMEOUT              0x0007BE        /**< Onvif������ʱ�������ͷ� */
#define ERR_XP_RTSP_COMPLETE_CLOSE                      0x0007BF        /**< ���ŵ�ĩβ�������������� */

/* �Ự���� */
#define ERR_XP_FAIL_TO_SETUP_SESSION                    0x0007C0        /**< ����Ự����ʧ�� */
#define ERR_XP_FAIL_TO_QUIT_SESSION                     0x0007C1        /**< �˳��Ựʧ�� */
#define ERR_XP_AUDIO_DEVICE_UNRIPE                      0x0007C2        /**< ��Ƶ�豸δ׼���� */

#define ERR_XP_RTSP_ONVIF_FAIL                          0x0007C5        /**< ONVIFʵ��ʱ�����豸����RTSP����ʧ�� */

/* Rtsp �Ự���� */
#define ERR_XP_RTSP_REQ_TIMEOUT                         0x0007D1        /**< ����ҵ����ʱ */
#define ERR_XP_RTSP_NOT_ENOUGH_BANDWIDTH                0x0007D2        /**< ����ҵ������� */
#define ERR_XP_RTSP_SERVINTERERR                        0x0007D3        /**< ����ҵ���ڲ����� */

/* ����ҵ��*/
#define ERR_XP_FAIL_TO_CLOSE_FILE                       0x0007D4        /**< �ر��ļ�����ʧ�� */
#define ERR_XP_FAIL_TO_CLOSE_STREAM                     0x0007D5        /**< �ر�ý��������ʧ�� */
#define ERR_XP_INPUTDATA_BUFFER_FULL                    0x0007D6        /**< �������ݻ����� */
#define ERR_XP_MEDIA_STREAM_NOT_SUPPORT                 0x0007D7        /**< �޷�ʶ�𣨻�֧�֣������� */
#define ERR_XP_FAIL_TO_PLAY_SOUND                       0x0007D8        /**< ������������ʧ�� */
#define ERR_XP_FAIL_TO_STOP_SOUND                       0x0007D9        /**< �ر���������ʧ�� */
#define ERR_XP_FAIL_TO_OPEN_VOICE_SVC                   0x0007DA        /**< ��������ҵ��ʧ�� */
#define ERR_XP_FAIL_TO_CLOSE_VOICE_SVC                  0x0007DB        /**< �ر�����ҵ��ʧ�� */
#define ERR_XP_FAIL_TO_SET_DIGITALZOOM                  0x0007DC        /**< �������ַŴ�ʧ�� */
#define ERR_XP_FAIL_TO_GET_PIC_PARAM                    0x0007DD        /**< ͨ����ȡͼƬ��Ϣ���� */
#define ERR_XP_FAIL_TO_BEGINHVDC                        0x0007DE        /**< ��ʼ��ͼʧ�� */
#define ERR_XP_FAIL_TO_ENABLEANALYSERULE                0x0007DF        /**< ������ʾ���ܹ���ʧ�� */
#define ERR_XP_FAIL_TO_ENABLEANALYSERESULT              0x0007E0        /**< ������ʾ���ܽ��ʧ�� */
#define ERR_XP_FAIL_TO_START_COMBINE_IMAGE              0x0007E1        /**< ����ͼ��ƴ�Ӳ���ʧ�� */
#define ERR_XP_FAIL_TO_MARK_COMBINE_IMAGE               0x0007E2        /**< �趨ͼ��ƴ��������ʧ�� */
#define ERR_XP_FAIL_TO_STOP_COMBINE_IMAGE               0x0007E3        /**< ֹͣͼ��ƴ�Ӳ���ʧ�� */
#define ERR_XP_FAIL_TO_START_COMBINE_ZOOM               0x0007E4        /**< ����ƴ��ͼƬ���ַŴ�ʧ�� */
#define ERR_XP_FAIL_TO_STOP_COMBINE_ZOOM                0x0007E5        /**< ֹͣƴ��ͼƬ���ַŴ�ʧ�� */
#define ERR_XP_FAIL_TO_MOVE_COMBINE_ZOOM                0x0007E6        /**< �޸�ƴ��ͼƬ���ַŴ�ʧ�� */
#define ERR_XP_FAIL_TO_SET_DECODER_MODE                 0x0007E7        /**< ���ý���ģʽʧ�� */
#define ERR_XP_FAIL_TO_SET_VIDEO_ADJUST                 0x0007E8        /**< ����Ӱ�����ʧ�� */
#define ERR_XP_FAIL_TO_SET_VIDEO_MOTION_BLUR            0x0007E9        /**< ����ģ������ʧ�� */
#define ERR_XP_FAIL_TO_SET_VIDEO_SHARPEN                0x0007EA        /**< �����񻯴���ʧ�� */
#define ERR_XP_FAIL_TO_SET_DE_FOG                       0x0007EB        /**< ����ȥ����ʧ�� */
#define ERR_XP_FAIL_TO_SET_ANTI_FLICKER                 0x0007EC        /**< ���÷���˸����ʧ�� */
#define ERR_XP_FAIL_TO_SIP_NEGORIATE                    0x0007ED        /**< SIPЭ��ʧ�� */
#define ERR_XP_NOT_SUPPORT_DECODERTAG                   0x0007EE        /**< �����������ڻ��̲�֧�� */
#define ERR_XP_FAIL_TO_SET_STARTSTOP_TIME               0x0007EF        /**< ���ÿ�ʼʱ��ͽ���ʱ��ʧ�� */
#define ERR_XP_RECOERD_REBUILD                          0x0007F0        /**<���ػ�¼���ؽ� */
#define ERR_XP_FAIL_TO_KEEP_LIVE_STREAM                 0x0007F1        /**< ��������ʧ�� */
#define ERR_XP_FAIL_LOGIN_BALL                          0x0007F2        /**< ��¼���ʧ�� */
#define ERR_XP_FAIL_MARK_BALL                           0x0007F3        /**< �����ʧ�� */
#define ERR_XP_FAIL_OPT_BALL_COMMAND                    0x0007F4        /**< ����������ʧ�� */
#define ERR_XP_BALL_CAMERA_LOGOUT                       0x0007F5        /**< �ǳ����ʧ�� */
#define ERR_XP_FAIL_TO_BUILD_FILE_INDEX                 0x0007F6        /**< �����ļ�����ʧ�� */
#define ERR_XP_FAIL_TO_SET_OSD                          0x0007F7        /**< ����OSDʧ�� */
#define ERR_XP_FAIL_TO_STOP_OSD                         0x0007F8        /**< �ر�OSDʧ�� */

#define ERR_XP_FAIL_TO_SET_AUDIO_CHANNEL                0x0007F9        /**< ������Ƶ����ʧ�� */
#define ERR_XP_FAIL_NO_RIGHT_AUDIO_CHANNEL              0x0007FA        /**< û����Ƶ������ */

#define ERR_XP_FAIL_TO_SET_BARREL_ADJUST                0x0007FB        /**< ����Ͱ�ͽ���ʧ�� */
#define ERR_XP_FAIL_TO_SET_DISPLAY_HDC_CB               0x0007FC        /**< ������ʾHDC�ص�����ʧ�� */
#define ERR_XP_MEDIA_BUFFER_HIGH_LEVEL                  0x0007FD        /**< ý�建���ˮλ */
#define ERR_XP_MEDIA_BUFFER_LOW_LEVEL                   0x0007FE        /**< ý�建���ˮλ */
#define ERR_XP_FAIL_TO_SET_MEDIA_SVC_TYPE               0x0007FF        /**< ����ý��ҵ������ʧ�� */

#define ERR_XP_FINISH_SERIES_ONESNATCH                  0x000800        /**< ����ץ�ĳɹ�ץ��һ��ͼƬ*/

/* Add by sunbiao/sW1071 2014.10.28 for MPPD18406 ����dspȥ���� */
#define ERR_XP_FAIL_TO_SET_DESHAKE                      0x000801        /**< ����ȥ����ʧ�� */

/* Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */
#define ERR_XP_FAIL_TO_SET_VOD_TIME_CB                  0x000802        /**< ���û�ȡ�㲥�ط�ʱ��Ļص�����ʧ�� */

/* Begin: Add by chenliang w0897, 2014/12/2, MPPD11546: XP�ͻ���¼��ʱ֧�ִ�С���� */
#define ERR_XP_FAIL_TO_SET_CUR_POS_CB                   0x000803        /**< ����setCurDownPosCallback�ص�����ʧ�� */
#define ERR_XP_FAIL_TO_SET_DOWNLOAD_TYPE                0x000804        /**< ����setDownloadType����ʧ�� */
/* End: Add by chenliang w0897, 2014/12/2, MPPD11546: XP�ͻ���¼��ʱ֧�ִ�С���� */
/* begin add by liguopeng01371 2015-1-27 MPPD05811 ��������Դ���Ƭ���� */
#define ERR_XP_FAIL_TO_SET_RENDER_RESOURCE_MODE         0x000805           /* �����Դ��ͷ�ģʽʧ�� */
#define ERR_XP_FAIL_TO_SET_PROXY                        0x000806           /**< ���ô���ʧ�� */
#define ERR_XP_FAIL_TO_DELETE_ALL_SVC_AND_WND         0x000807           /**< ɾ������svc�ʹ��ھ�� */

/* Added by shichao/W1439 2015/4/29 */
#define ERR_XP_FAIL_TO_ENABLE_IA_GPU_DECODE             0x000808       /**< ����GPU����ʧ�� */
#define ERR_XP_FAIL_BL_MATCHERROR                        0x000809        /*ǹ�������������ʧ��*/
#define ERR_XP_FAIL_TO_SET_MEDIA_SECTION_TIME    0x00080A   /*����ý��Ƭ��ʱ����Ϣʧ��*/
#define ERR_XP_FAIL_TO_SET_FISH_ADJUST                  0x00080B        /* �������۽���ʧ�� */

/**********ע�⣺XP������ֵ��ΧΪ��[0x000700��0x0008FF] *****************/


/************************************************************************/
/*************************** �ļ���׺������******************************/
/************************************************************************/
#define IMOS_XP_FILE_POSTFIX_LEN    32


/************************************************************************/
/*********************** XP SDK���ݽṹ���Ͷ���**************************/
/************************************************************************/
/* Begin:Added by lizhen in 2017-9-1 for ���۽��� */
/* ���۽�����Ҫ�Ĳ��� */
#define PTZ_NUM_MAX      (9)    /*���֧�ֵ�����PTZ����*/
#define FALSE_PTZ_ID      10    /* ��ЧPTZID */
#define FALSE_AREA_ID     10    /* ��Ч�궨��ID */
/* End:Added by lizhen in 2017-9-1 for ���۽��� */

/**
* @enum tagPlayType
* @brief ͨ������ҵ������ö�ٶ���
* @attention ��
*/
typedef enum tagPlayType
{
    XP_PLAY_REALTIME = 0,               /**< ʵʱ��� */
    XP_PLAY_VOD = 1,                    /**< �ط� */
    XP_PLAY_INTELLIGENT = 2             /**< �������ҵ�� */
}XP_PLAY_TYPE_E;

/**
* @enum tagPictureFluency
* @brief ͼ�񲥷�������ö�����Ͷ���
* @attention ��
*/
typedef enum tagPictureFluency
{
    XP_PICTURE_TIME_PRIORITY = 0,         /**< ʵʱ������ */
    XP_PICTURE_FLUENCY_PRIORITY = 1,      /**< ���������� */
    XP_PICTURE_TIME_FLUENCY_AUTO = 2,     /**< ����Ӧ */
    XP_PICTURE_HIGH_LOWDELAY = 3,         /**< ������ʱ */
}XP_PICTURE_FLUENCY_E;

/**
* @enum tagRenderScale
* @brief ���Ŵ�����ʾͼ��ı���ö�����Ͷ���
* @attention ��
*/
typedef enum tagRenderScale
{
    XP_RENDER_SCALE_FULL = 0,               /**< ͼ������������Ŵ��� */
    XP_RENDER_SCALE_PROPORTION = 1          /**< ͼ�񰴱�����ʾ */
}XP_RENDER_SCALE_E;

/**
* @enum tagPictureFormat
* @brief ͼƬ��ʽö�ٶ���
* @attention ��
*/
typedef enum tagPictureFormat
{
    XP_PICTURE_BMP = 0,                 /**< ͼƬ��ʽΪbmp��ʽ */
    XP_PICTURE_JPG = 1                  /**< ͼƬ��ʽΪjpg��ʽ */
}XP_PICTURE_FORMAT_E;

/**
* @enum tagVideoEncodeType
* @brief ��Ƶ�����ʽö�ٶ���
* @attention ��
*/
typedef enum tagVideoEncodeType
{
    XP_VIDEO_ENCODE_MPEG2 = 0,          /**< ��Ƶ����MPEG-2��׼ */
    XP_VIDEO_ENCODE_MPEG4 = 1,          /**< ��Ƶ����MPEG-4��׼ */
    XP_VIDEO_ENCODE_H264 = 2,           /**< ��Ƶ����H.264��׼ */
    XP_VIDEO_ENCODE_MJPEG = 3,          /**< ��Ƶ����MJPEG��׼ */
    /* add by chenxiangyi 02451 MPPD27703 h265�������� */
    XP_VIDEO_ENCODE_H265 = 4            /**< ��Ƶ����h.265��׼ */
}XP_VIDEO_ENCODE_TYPE_E;

/**
* @enum tagAudioEncodeType
* @brief ��Ƶ�����ʽö�ٶ���
* @attention ��
*/
typedef enum tagAudioEncodeType
{
    XP_AUDIO_ENCODE_G711U = 0,          /**< ��Ƶ����G.711U�ɱ�׼ */
    XP_AUDIO_ENCODE_MP2 = 1,            /**< ��Ƶ����MP2�����׼ */
    XP_AUDIO_ENCODE_AAC = 2,            /**< ��Ƶ����AAC�����׼ */
    XP_AUDIO_ENCODE_G711A = 3,          /**< ��Ƶ����G.711A�ɱ�׼ */
    XP_AUDIO_ENCODE_PCMA = 4            /**< ��Ƶ����PCMA�ɱ�׼ */
}XP_AUDIO_ENCODE_TYPE_E;

/**
* @enum tagMediaFileFormat
* @brief ý���ļ���ʽö�ٶ���
* @attention ��
*/
typedef enum tagMediaFileFormat
{
    XP_MEDIA_FILE_TS  = 0,                  /**< TS��ʽ��ý���ļ� */
    XP_MEDIA_FILE_FLV = 1,                  /**< FLV��ʽ��ý���ļ� */
    XP_MEDIA_FILE_AVI = 2,                  /**< AVI��ʽ��ý���ļ� */
    XP_MEDIA_FILE_MP4 = 3,                  /**< MP4��ʽ��ý���ļ� */
    XP_MEDIA_FILE_WMV = 4,                  /**< MP4��ʽ��ý���ļ� */
    XP_MEDIA_FILE_MKV = 5,                  /**< MKV��ʽ��ý���ļ� */
    XP_MEDIA_FILE_ASF = 6,                  /**< ASF��ʽ��ý���ļ� */
    XP_MEDIA_FILE_M4V = 7,                  /**< M4V��ʽ */
    XP_MEDIA_FILE_H264 = 8,                 /**< H264��������ʽ */
    XP_MEDIA_FILE_MPEG = 9,                 /**< MPEG��������ʽ */

    XP_MEDIA_FILE_H3C_PRIVATE = 100,        /* H3C V1˽�и�ʽ */
    XP_MEDIA_FILE_HIK_PRIVATE = 101,        /* ����˽�и�ʽ */
    XP_MEDIA_FILE_DAHUA_PRIVATE = 102,      /* ��˽�и�ʽ */
    XP_MEDIA_FILE_MOBOTIX_PRIVATE = 103,    /* mobotix˽�и�ʽ */
    XP_MEDIA_FILE_NANZI_PRIVATE = 104,      /* ����˽�и�ʽ */
    XP_MEDIA_FILE_RM_PRIVATE = 105,         /* ����˽�и�ʽ */
    XP_MEDIA_FILE_HANBANG_PRIVATE = 106,    /* ����˽�и�ʽ */
    XP_MEDIA_FILE_CHENGFENG_PRIVATE = 107,  /* �Ϸ�˽�и�ʽ */

    XP_MEDIA_FILE_UNKNOWN = 0XFFFFFFFF
}XP_MEDIA_FILE_FORMAT_E;

/**
* @enum tagRenderMode
* @brief ��Ƶ��ʾģʽö�ٶ���
* @attention ��
*/
typedef enum tagRenderMode
{
    XP_RENDER_MODE_D3D = 0,             /**< ʹ��D3D�ķ�ʽ������ʾ */
    XP_RENDER_MODE_DDRAW_NORMAL = 1 ,    /**< ʹ��Ddraw��Normal��ʾģʽ */
    XP_RENDER_MODE_LOWER = 2,           /**< ʹ�õ�Ʒ����ʾģʽ */
    XP_RENDER_MODE_MAX = 0xFF
}XP_RENDER_MODE_E;

/**
* @enum tagPixelFormat
* @brief ��Ƶ���ظ�ʽö�ٶ��壬��Ҫ���Ͻӿں���#XP_SetPixelFormat��ʹ�á�
* @attention ��
*/
typedef enum tagPixelFormat
{
    XP_PIXEL_FORMAT_YUV = 0,            /**< YUV��ʽ��� */
    XP_PIXEL_FORMAT_RGB = 1             /**< RGB��ʽ��� */
}XP_PIXEL_FORMAT_E;

/**
* @enum tagPixelFormatEx
* @brief ��Ƶ���ظ�ʽö����ǿ���壬��Ҫ���½ӿں���#IMOS_SetPixelFormat��ʹ�á�
*        ��tagPixelFormatö����������ϸ������Ƶ���ظ�ʽ
* @attention ��
*/
typedef enum tagPixelFormatEx
{
    XP_PIXEL_FORMAT_YUV420 = 0,         /**< YUV420��ʽ��� */
    XP_PIXEL_FORMAT_RGB32 = 1           /**< RGB32��ʽ��� */
}XP_PIXEL_FORMAT_EX_E;

/**
* @enum tagFieldMode
* @brief ��ģʽö�ٶ���
* @attention ��
*/
typedef enum tagFieldMode
{
    XP_FIELD_MODE_SINGLE = 0,           /**< ����ģʽ */
    XP_FIELD_MODE_DOUBLE = 1            /**< ˫��ģʽ */
}XP_FIELD_MODE_E;

/**
* @enum tagDeinterlaceMode
* @brief ȥ��֯����ģʽ��ö�ٶ���
* @attention ��
*/
typedef enum tagDeinterlaceMode
{
    XP_DEINTERLACE_NONE = 0,            /**< ������ȥ��֯���� */
    XP_DEINTERLACE_DOUBLETOPFIELG = 1,  /**< �����������׳�ģʽ */
    XP_DEINTERLACE_BLEND = 2,           /**< ���ģʽ */
    XP_DEINTERLACE_X  = 3               /**< xģʽ */
}XP_DEINTERLACE_MODE_E;

/**
* @enum tagWaveInSource
* @brief ��Ƶ����Դ����
* @attention ��
*/
typedef enum tagWaveInSource
{
    XP_WAVEIN_SOURCE_DEVICE = 0,        /**< ��˷�����Ƶ����Դ */
    XP_WAVEIN_SOURCE_FILE = 1,          /**< ��Ƶ�ļ�����Ƶ����Դ */
    XP_WAVEIN_SOURCE_INPUT = 2          /**< �û�������Ƶ������Ϊ��Ƶ����Դ */
}XP_WAVEIN_SOURCE_E;

/**
* @enum tagAudioSampleFormatType
* @brief ��Ƶλ��
* @attention ��
*/
typedef enum tagXPAudioSampleFormatType
{
    XP_AUDIO_SAMPLE_FMT_NONE = -1,
    XP_AUDIO_SAMPLE_FMT_U8,          ///< �޷���8λ����
    XP_AUDIO_SAMPLE_FMT_S16,         ///< �з���16λ����
    XP_AUDIO_SAMPLE_FMT_S32,         ///<  �з���32λ����
    XP_AUDIO_SAMPLE_FMT_FLT,         ///< ������
    XP_AUDIO_SAMPLE_FMT_DBL,         ///< double��
} XP_AUDIO_SAMPLE_FORMAT_E;

/**
* @struct tagAudioSampleParamType
* @brief ��Ƶ����
* @attention ��
*/
typedef struct tagXPAudioSampleParamType
{
    ULONG ulChannels;                     /**< ��������������Ϊ1��������Ϊ2 */
    ULONG ulSampleRate;                   /**< ������ */
    XP_AUDIO_SAMPLE_FORMAT_E enSampleFormat; /**< λ�� */
} XP_AUDIO_SAMPLE_PARAM_S;

/**
* @enum tagRecordQuality
* @brief ¼������ö�ٶ���
* @attention ��
*/
typedef enum tagRecordQuality
{
    XP_RECORD_PRIORITY = 0,             /**< ����ʱ¼������������*/
    XP_PLAY_PRIORITY = 1                /**< ����ʱ���Ŵ�������*/
}XP_RECORD_QUALITY_E;

/**
* @enum tagMediaDataLostSplitterPolicy
* @brief �������������ƴ֡���Ե�ö�ٶ���
* @attention ��
*/
typedef enum tagMediaDataLostSplitterPolicy
{
    XP_MEDIA_LOST_NO_SPLITTER = 0 ,       /**< ������������¶������� */
    XP_MEDIA_LOST_CONTINUE_SPLITTER = 1   /**< ������������¼���ƴ֡ */
}XP_MEDIA_DATA_LOST_SPLITTER_POLICY;

/**
* @enum tagPlayStatus
* @brief ����״̬ö�ٶ���
* @attention ��
*/
typedef enum tagPlayStatus
{
    XP_PLAY_STATUS_16_BACKWARD = 0,         /**< 16���ٺ��˲��� */
    XP_PLAY_STATUS_8_BACKWARD = 1,          /**< 8���ٺ��˲��� */
    XP_PLAY_STATUS_4_BACKWARD = 2,          /**< 4���ٺ��˲��� */
    XP_PLAY_STATUS_2_BACKWARD = 3,          /**< 2���ٺ��˲��� */
    XP_PLAY_STATUS_1_BACKWARD = 4,          /**< �����ٶȺ��˲��� */
    XP_PLAY_STATUS_HALF_BACKWARD = 5,       /**< 1/2���ٺ��˲��� */
    XP_PLAY_STATUS_QUARTER_BACKWARD = 6,    /**< 1/4���ٺ��˲��� */
    XP_PLAY_STATUS_QUARTER_FORWARD = 7,     /**< 1/4���ٲ��� */
    XP_PLAY_STATUS_HALF_FORWARD = 8,        /**< 1/2���ٲ��� */
    XP_PLAY_STATUS_1_FORWARD = 9,           /**< �����ٶ�ǰ������ */
    XP_PLAY_STATUS_2_FORWARD = 10,          /**< 2����ǰ������ */
    XP_PLAY_STATUS_4_FORWARD = 11,          /**< 4����ǰ������ */
    XP_PLAY_STATUS_8_FORWARD = 12,          /**< 8����ǰ������ */
    XP_PLAY_STATUS_16_FORWARD = 13,         /**< 16����ǰ������ */
    XP_PLAY_STATUS_SUPER_FAST_FORWARD = 14,  /**< ����ǰ������ */
    XP_PLAY_STATUS_ONEEIGHTH_FORWARD = 15     /**< 1/8���ٲ��� */
}XP_PLAY_STATUS_E;

/**
* @enum tagRunInfoType
* @brief �ϱ���Ϣ���͵�ö�ٶ���
* @attention ��
*/
typedef enum tagRunInfoType
{
    XP_RUN_INFO_SERIES_SNATCH = 0,        /**< ����ץ�Ĺ������ϱ�������Ϣ */
    XP_RUN_INFO_RECORD_VIDEO = 1,         /**< ����¼��������ϱ�������Ϣ */
    XP_RUN_INFO_MEDIA_PROCESS = 2,        /**< ��Ƶý�崦������е��ϱ�������Ϣ */
    XP_RUN_INFO_DOWN_MEDIA_PROCESS = 3,   /**< ý�������ع������ϱ�������Ϣ */
    XP_RUN_INFO_VOICE_MEDIA_PROCESS = 4,  /**< ����ý�崦������е��ϱ�������Ϣ */
    XP_RUN_INFO_RTSP_PROTOCOL = 5,        /**< RTSPЭ��������еĴ�����Ϣ */
    XP_RUN_INFO_DOWN_RTSP_PROTOCOL = 6,   /**< ����¼�������RTSPЭ��Ĵ�����Ϣ */
    XP_RUN_INFO_SIP_LIVE_TIMEOUT = 7,     /**< SIPע�ᱣ�ʱ */
    XP_RUN_INFO_PASSIVE_MONITOR = 8,      /**< ����ʵ��ֹͣ������Ϣ */
    XP_RUN_INFO_PASSIVE_START_MONITOR = 9,/**< ����ʵ������������Ϣ */
    XP_RUN_INFO_MEDIA_NOT_IDENTIFY = 10,  /**< �����޷�ʶ�� */
    XP_RUN_INFO_RECV_PACKET_NUM = 11,     /**< �����ڽ��յ��İ��� */
    XP_RUN_INFO_RECV_BYTE_NUM = 12,       /**< �����ڽ��յ����ֽ��� */
    XP_RUN_INFO_VIDEO_FRAME_NUM = 13,     /**< �����ڽ�������Ƶ֡�� */
    XP_RUN_INFO_AUDIO_FRAME_NUM = 14,     /**< �����ڽ�������Ƶ֡�� */
    XP_RUN_INFO_LOST_PACKET_RATIO = 15,   /**< �����ڶ�����ͳ����Ϣ����λΪ0.01%�� */
    XP_RUN_INFO_MEDIA_PLAY_PROGRESS = 16, /**< ý����Я���Ľ�����Ϣ */
    XP_RUN_INFO_MEDIA_PLAY_END = 17,      /**< ý����Я���Ĳ��Ž��� */
    XP_RUN_INFO_MEDIA_ABNORMAL = 18       /**< ý�崦���쳣 */
}XP_RUN_INFO_TYPE_E;

/**
* @enum tagMediaDataType
* @brief �����ý�����������͵�ö�ٶ���
* @attention ��
*/
typedef enum tagMediaDataType
{
    XP_VIDEO_DATA_DECODE = 0,           /**< ��������Ƶ���� */
    XP_AUDIO_DATA_DECODE = 1            /**< ��������Ƶ���� */
}XP_OUTPUT_MEDIA_DATA_TYPE_E;

/**
* @enum tagWaveFormatInfo
* @brief �������Ƶ��ʽ��ö�����Ͷ���
* @attention ��
*/
typedef enum tagWaveFormatInfo
{
    XP_WAVE_FORMAT_PCM8M16 = 0,         /**< PCM��8K�����ʣ���������M����16λ���� */
    XP_WAVE_FORMAT_PCM16M16 = 1,        /**< PCM��16K�����ʣ���������M����16λ���� */
    XP_WAVE_FORMAT_PCM441M16 = 2        /**< PCM��44.1K�����ʣ���������M����16λ���� */
}XP_WAVE_FORMAT_INFO_E;

/**
* @enum tagVoiceSvcType
* @brief ����ҵ������ö�ٶ���
* @attention ��
*/
typedef enum tagVoiceSvcType
{
    XP_VOICE_SERVICE_BROADCAST = 0,        /**< �����㲥ҵ�����ͣ��������� */
    XP_VOICE_SERVICE_TALKBACK = 1,         /**< �����Խ�ҵ�����ͣ������շ� */
    XP_VOICE_SERVICE_BE_BROADCASTED = 2    /**< �������㲥ҵ�����ͣ������� */
}XP_VOICE_SERVICE_TYPE_E;

/**
* @enum tagMediaDataFormat
* @brief ý����������ʽ
* @attention ��
*/
typedef enum tagMediaDataFormat
{
    XP_MEDIA_DATA_TS = 0,               /**< TS��װ���� */
    XP_MEDIA_DATA_ES12 = 1,             /**< RTP + ��/��Ƶ˽��ͷ��12�ֽڣ� + ES���� */
    XP_MEDIA_DATA_ES12_TIME = 2,        /**< RTP + ʱ�����8�ֽڣ� + ��/��Ƶ˽��ͷ��12�ֽڣ� + ES���� */
    XP_MEDIA_DATA_RTP_ES = 3,           /**< RTP + ES���� */
    XP_MEDIA_DATA_HIK = 4,              /**< �����������ص��ĵ�һ�����Ǻ���40�ֽ�ϵͳͷ */
    XP_MEDIA_DATA_DH = 5,               /**< ������ */
    XP_MEDIA_DATA_RM = 6,               /**< �����������ص��ĵ�һ����������40�ֽ�ϵͳͷ */
    XP_MEDIA_DATA_TDY_SWALLOW = 7,      /**< TDY-SWALLOW */
    XP_MEDIA_DATA_DMA_SWALLOW = 8,      /**< DMA-SWALLOW */
    XP_MEDIA_DATA_NANZI = 9,            /**< �������� */
    XP_MEDIA_DATA_RTP3984 = 10,         /**< �����rfc3984���� */
    XP_MEDIA_DATA_RTP_PS = 11,          /**< RTP+PS */
    XP_MEDIA_DATA_RTP_H264 = 12         /**< RTP+H264 */
}XP_MEDIA_DATA_FORMAT_E;

/**
* @enum tagNetworkTransportProtl
* @brief ���紫��Э�飬��Ҫ���Ͻӿں���#XP_SetTransportProtocol��ʹ�á�
* @attention ��
*/
typedef enum tagNetworkTransportProtl
{
    XP_NETWORK_TRANSPORT_PROTOCOL_UDP = 0,  /**< UDPЭ�� */
    XP_NETWORK_TRANSPORT_PROTOCOL_TCP = 1   /**< TCPЭ�� */
}XP_NETWORK_TRANSPORT_PROTOCOL_E;

/**
* @enum tagProtocol
* @brief ����Э�飬��Ҫ���½ӿں���#IMOS_OpenVodStream��#IMOS_StartDownMediaStream��ʹ�á�
* @attention ��
*/
typedef enum tagProtocol
{
    XP_PROTOCOL_UDP = 0,                   /**< UDPЭ�� */
    XP_PROTOCOL_TCP = 1,                   /**< TCPЭ��Client��*/
    XP_PROTOCOL_TCP_SERVER = 2             /**< TCPЭ��Server��*/
}XP_PROTOCOL_E;

/* begin Added by chenxiangyi W1099, 2014/9/28  onvif֧���鲥  MPPD17374 */
/**
* @enum tagBroadcastmethod
* @brief ý�崫����ʽö�����Ͷ���
* @attention ��
*/
typedef enum tagBroadcastmethod
{
    XP_BM_UNICAST = 0,                     /**< ���� */
    XP_BM_MULTICAST = 1,                   /**< �鲥 */

    XP_BM_INVALID = 0xFFFFFFFF             /**< ������ʽ��Ч */
}XP_BROADCAST_METHOD_E;
/* end Added by chenxiangyi W1099, 2014/9/28  onvif֧���鲥  MPPD17374 */

/**
* @enum tagRenderTimeType
* @brief ʱ���ö�����Ͷ���
* @attention ��
*/
typedef enum tagRenderTimeType
{
    XP_RENDER_FRAME_RATE = 0,               /**< ʹ��֡�����ݽ�����Ƶ��Ⱦ */
    XP_RENDER_ABSOLUTE_TIME = 1             /**< ʹ�þ���ʱ�����ݽ�����Ƶ��Ⱦ */
}XP_RENDER_TIME_TYPE_E;

/**
* @enum tagDownMediaSpeed
* @brief ý�����������ٶȵ�ö�ٶ���
* @attention ��
*/
typedef enum tagDownMediaSpeed
{
    XP_DOWN_MEDIA_SPEED_ONE = 0,            /**< һ��������ý���ļ� */
    XP_DOWN_MEDIA_SPEED_TWO = 1,            /**< ����������ý���ļ� */
    XP_DOWN_MEDIA_SPEED_FOUR = 2,           /**< �ı�������ý���ļ� */
    XP_DOWN_MEDIA_SPEED_EIGHT = 3           /**< �˱�������ý���ļ� */
}XP_DOWN_MEDIA_SPEED_E;

/**
* @enum tagNatMode
* @brief NAT��ʽ��ö������
* @attention ��
*/
typedef enum tagNatMode
{
    XP_NAT_NONE = 0,                     /**< ��NAT�ķ�ʽ */
    XP_NAT_IN   = 1,                     /**< NAT IN��ʽ */
    XP_NAT_OUT  = 2                      /**< NAT OUT��ʽ */
}XP_NAT_MODE_E;

/**
* @enum tagVideoFrameType
* @brief ��Ƶ֡���͵�ö�ٶ���
* @attention ��
*/
typedef enum tagVideoFrameType
{
    XP_VIDEO_FRAME_I = 0,               /**< ��Ƶ֡ΪI֡ */
    XP_VIDEO_FRAME_P = 1,               /**< ��Ƶ֡ΪP֡ */
    XP_VIDEO_FRAME_B = 2                /**< ��Ƶ֡ΪB֡ */
}XP_VIDEO_FRAME_TYPE_E;

/**
* @enum tagPictureContrastMode
* @brief ͼ��Աȶ�ģʽ����
* @attention ��
*/
typedef enum tagPictureContrastMode
{
    XP_PICTURE_CONTRAST_MODE_NONE = 0,       /**< �����жԱȶȵ��ڴ��� */
    XP_PICTURE_CONTRAST_MODE_BRIGHTNESS = 1, /**< �Աȶ�����ģʽ */
    XP_PICTURE_CONTRAST_MODE_SOFTNESS = 2    /**< �Աȶ����ģʽ */
}XP_PICTURE_CONTRAST_MODE_E;

/**
* @enum tagJpgPictureQuality
* @brief ͼ����������
* @attention ��
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
* @brief ͼ��Աȶȼ�������
* @attention ��
*/
typedef enum tagPictureContrastLevel
{
    XP_PICTURE_CONTRAST_LEVEL_LOW = 0,       /**< �Աȶȵͼ��� */
    XP_PICTURE_CONTRAST_LEVEL_MIDDLE = 1,    /**< �Աȶ��м��� */
    XP_PICTURE_CONTRAST_LEVEL_HIGH = 2       /**< �Աȶȸ߼��� */
}XP_PICTURE_CONTRAST_LEVEL_E;

/**
* @enum tagPictureContrastLevelEx
* @brief ͼ��Աȶȼ�������
* @attention ��
*/
typedef enum tagPictureContrastLevelEx
{
    XP_PICTURE_CONTRAST_LEVEL_1 = 1,        /**< �Աȶ�1���� */
    XP_PICTURE_CONTRAST_LEVEL_2 = 2,        /**< �Աȶ�2���� */
    XP_PICTURE_CONTRAST_LEVEL_3 = 3,        /**< �Աȶ�3���� */
    XP_PICTURE_CONTRAST_LEVEL_4 = 4,        /**< �Աȶ�4���� */
    XP_PICTURE_CONTRAST_LEVEL_5 = 5,        /**< �Աȶ�5���� */
    XP_PICTURE_CONTRAST_LEVEL_6 = 6,        /**< �Աȶ�6���� */
    XP_PICTURE_CONTRAST_LEVEL_7 = 7,        /**< �Աȶ�7���� */
    XP_PICTURE_CONTRAST_LEVEL_8 = 8,        /**< �Աȶ�8���� */
    XP_PICTURE_CONTRAST_LEVEL_9 = 9,        /**< �Աȶ�9���� */
    XP_PICTURE_CONTRAST_LEVEL_10 = 10       /**< �Աȶ�10���� */
}XP_PICTURE_CONTRAST_LEVEL_EX_E;

/**
* @enum tagResolutionType
* @brief �ֱ�������
* @attention ��
*/
typedef enum tagResolutionType
{
    XP_RESOLUTION_AUTO = 0,       /**< ԭ�еķֱ��ʣ������ ��ʾ */
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
* @brief �����������
* @attention ��
*/
typedef enum tagEncodePacketType
{
    XP_ENC_PKT_TS = 0,             /**< TS����ʽ */
    XP_ENC_PKT_RTP_ES = 1,         /**< RTP+ES����ʽ */
    XP_ENC_PKT_RTP_PS = 2,         /**< RTP+PS����ʽ */
    XP_ENC_PKT_RFC3984 = 3,        /**< RFC3984����ʽ */
    XP_ENC_PKT_RTP_TS = 4,         /**< RTP_TS����ʽ */
}XP_ENCODE_PACKET_TYPE_E;

/**
* @enum tagEncodeSDKType
* @brief ���������
* @attention ��
*/
typedef enum tagEncodeSDK
{
    XP_ENCODE_DSP = 0,          /**< DSP���� */
    XP_ENCODE_SW = 1,           /**< Intel SDK����� */
    XP_ENCODE_HW = 2,           /**< Intel SDKӲ���� */
    XP_ENCODE_FRAME = 3,        /**< ת��װ */
    XP_ENCODE_HW_TOTAL = 4,     /** �����ȫ��ʹ��GPU,������H264�� */
    XP_ENCODE_INVALID           /**< ��Ч������� */
}XP_ENCODE_SDK_E;

/**
* @enum tagEncodeMode
* @brief ����ģʽ
* @attention ��
*/
typedef enum tagEncodeMode
{
    XP_ENC_MODE_CBR = 0,           /**< CBR */
    XP_ENC_MODE_CVBR = 1,          /**< CVBR */
    XP_ENC_MODE_VBR = 2            /**< VBR */
}XP_ENCODE_MODE_E;

/**
* @enum tagAudioFlag
* @brief ��Ƶ��������
* @attention ��
*/
typedef enum tagAudioFlag
{
    XP_AUDIO_LOCAL_GATHERED = 0,    /**< ���زɼ������� */
    XP_AUDIO_DEVICE_SEND = 1        /**< �豸���͹������������� */
} XP_AUDIO_FLAG_E;

/**
* @struct tagRunInfo
* @brief �ϱ���Ϣ�Ľṹ�嶨�壬��Ҫ�ڻص�����#XP_RUN_INFO_CALLBACK_PF��ʹ�á�
* @attention ��
*/
typedef struct tagRunInfo
{
    IMOS_HANDLE hWnd;                           /**< ���Ŵ����� */
    ULONG_32 ulErrCode;                            /**< �ϱ��Ĵ����� */
}XP_RUN_INFO_S;

/**
* @struct tagRunInfoEx
* @brief �ϱ���Ϣ����ǿ�ṹ�嶨�壬��Ҫ�ڻص�����#XP_RUN_INFO_CALLBACK_EX_PF��ʹ�á�
*        ��tagRunInfo�ṹ����������ʹ��ͨ����Դ�����滻���Ŵ��ھ����
* @attention ��
*/
typedef struct tagRunInfoEx
{
    CHAR szPortCode[IMOS_RES_CODE_LEN];         /**< ͨ����Դ���� */
    ULONG_32 ulErrCode;                            /**< �ϱ��Ĵ����� */
}XP_RUN_INFO_EX_S;

/**
* @struct tagRunInfoEx
* @brief �ϱ���Ϣ����ǿ�ṹ�嶨�壬��Ҫ�ڻص�����#XP_RUN_INFO_CALLBACK_EX_PF��ʹ�á�
*        ��tagRunInfo�ṹ����������ʹ��ͨ����Դ�����滻���Ŵ��ھ����
* @attention ��
*/
typedef struct tagRunInfoEx2
{
    CHAR szPortCode[IMOS_RES_CODE_LEN];         /**< ͨ����Դ���� */
    ULONG_32 ulErrCode;                            /**< �ϱ��Ĵ����� */
    CHAR szDescribe[IMOS_URL_LEN];            /*������Ϣ*/
}XP_RUN_INFO_EX2_S;

/**
* @struct tagStartMonitorRunInfo
* @brief �ϱ�����ʵ��������Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagStartMonitorRunInfo
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< ͨ����Դ���� */
    CHAR szCameraID[IMOS_CODE_LEN];             /**< ��������� */
    ULONG_32 ulErrCode;                            /**< �ϱ��Ĵ����� */
    CHAR szReserved[64];                        /**< �������� */
}XP_START_MONITOR_RUN_INFO_S;

/**
* @struct tagDownRunInfo
* @brief ý�������ع������ϱ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagDownRunInfo
{
    CHAR szDownID[IMOS_RES_CODE_LEN];           /**< ý��������ID */
    ULONG_32 ulErrCode;                            /**< �ϱ��Ĵ����� */
}XP_DOWN_RUN_INFO_S;

/**
* @struct tagVoiceRunInfo
* @brief ����ҵ��ý��������������ϱ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagVoiceRunInfo
{
    CHAR szVoiceID[IMOS_RES_CODE_LEN];           /**< ���Ϊ������Э�������ҵ����ò���ΪԶ����Դ���룻����ΪSDK�ӿں���������ͨ��ID���� */
    ULONG_32 ulErrCode;                             /**< �ϱ��Ĵ����� */
}XP_VOICE_RUN_INFO_S;

/**
* @struct tagRecvPktNum
* @brief �ϱ������ڽ��հ�����Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagRecvPktNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< ͨ����Դ���� */
    ULONG_32 ulRecvPktNum;                         /**< ���յ��İ��� */
    ULONG_32 ulStatPeriod;                         /**< ͳ�Ƶ����ڣ����룩*/
}XP_RECV_PACKET_NUM_S;

/**
* @struct tagRecvByteNum
* @brief �ϱ������ڽ����ֽ�����Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagRecvByteNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< ͨ����Դ���� */
    ULONG_32 ulRecvByteNum;                        /**< ���յ����ֽ��� */
    ULONG_32 ulStatPeriod;                         /**< ͳ�Ƶ����ڣ����룩*/
}XP_RECV_BYTE_NUM_S;

/**
* @struct tagVideoFrameNum
* @brief �ϱ������ڽ�����Ƶ֡����Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagVideoFrameNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< ͨ����Դ���� */
    ULONG_32 ulVideoFrameNum;                      /**< ��������Ƶ֡�� */
    ULONG_32 ulStatPeriod;                         /**< ͳ�Ƶ����ڣ����룩 */
}XP_VIDEO_FRAME_NUM_S;

/**
* @struct tagAudioFrameNum
* @brief �ϱ������ڽ�����Ƶ֡����Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagAudioFrameNum
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< ͨ����Դ���� */
    ULONG_32 ulAudioFrameNum;                      /**< ��������Ƶ֡�� */
    ULONG_32 ulStatPeriod;                         /**< ͳ�Ƶ����ڣ����룩 */
}XP_AUDIO_FRAME_NUM_S;

/**
* @struct tagLostPktRatio
* @brief �ϱ������ڶ�������Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagLostPktRatio
{
    CHAR szPortCode[IMOS_CODE_LEN];             /**< ͨ����Դ���� */
    ULONG_32 ulLostPktRatio;                       /**< ��������Ϣ����λΪ0.01%�� */
    ULONG_32 ulStatPeriod;                         /**< ͳ�Ƶ����ڣ����룩 */
}XP_LOST_PAKCET_RATIO_S;

/**
* @struct tagSourceDataExInfo
* @brief ƴ֡ǰý������չ��Ϣ�Ľṹ�嶨�塣
* @attention ��
*/
typedef struct tagSourceDataExInfo
{
    CHAR szDecoderTag[IMOS_CODE_LEN];             /**< ��������ǩ*/
    CHAR szReserved[64];                          /**< ��������*/
}XP_SOURCE_DATA_EX_INFO_S;

/**
* @struct tagParseVideoData
* @brief ���ƴ֡����Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagParseVideoData
{
    UCHAR *pucData;             /**< ��Ƶ����ָ�� */
    ULONG_32 ulDataLen;            /**< ��Ƶ���ݳ��� */
    ULONG_32 ulVideoFrameType;     /**< ��Ƶ֡���ͣ���#XP_VIDEO_FRAME_TYPE_E��ȡֵ */
    ULONG_32 ulVideoCodeFormat;    /**< ��Ƶ�����ʽ����#XP_VIDEO_ENCODE_TYPE_E��ȡֵ */
    ULONG_32 ulHeight;             /**< ��Ƶͼ��߶� */
    ULONG_32 ulWidth;              /**< ��Ƶͼ���� */
    DLONG dlTimeStamp;          /**< ʱ��������룩*/
    ULONG_32 ulReserved1;          /**< �������� */
    ULONG_32 ulReserved2;          /**< �������� */
}XP_PARSE_VIDEO_DATA_S;

/**
* @struct tagParseAudioData
* @brief ���ƴ֡����Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagParseAudioData
{
    UCHAR *pucData;             /**< ��Ƶ����ָ�� */
    ULONG_32 ulDataLen;            /**< ��Ƶ���ݳ��� */
    ULONG_32 ulAudioCodeFormat;    /**< ��Ƶ�����ʽ����#XP_AUDIO_ENCODE_TYPE_E��ȡֵ */
    ULONG_32 ulWaveFormat;         /**< ��Ƶ���ݽ������Ƶ��ʽ����Ӧ#XP_WAVE_FORMAT_INFO_Eö���е�ֵ */
    DLONG dlTimeStamp;          /**< ʱ��������룩*/
    ULONG_32 ulReserved1;          /**< �������� */
    ULONG_32 ulReserved2;          /**< �������� */
}XP_PARSE_AUDIO_DATA_S;

/**
* @struct tagPictureData
* @brief ��Ž����ͼ�����ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagPictureData
{
    UCHAR *pucData[4];                          /**< pucData[0]:Y ƽ��ָ��,pucData[1]:U ƽ��ָ��,pucData[2]:V ƽ��ָ�� */
    ULONG_32 ulLineSize[4];                        /**< ulLineSize[0]:Yƽ��ÿ�п��, ulLineSize[1]:Uƽ��ÿ�п��, ulLineSize[2]:Vƽ��ÿ�п�� */
    ULONG_32 ulPicHeight;                          /**< ͼƬ�߶� */
    ULONG_32 ulPicWidth;                           /**< ͼƬ��� */
    ULONG_32 ulRenderTimeType;                     /**< ������Ⱦ��ʱ���������ͣ���ӦtagRenderTimeTypeö���е�ֵ */
    DLONG dlRenderTime;                         /**< ������Ⱦ��ʱ������ */
}XP_PICTURE_DATA_S;

/**
* @struct tagPictureDataEx
* @brief ͼ��������չ�����ṹ�嶨��
* @attention ��
*/
typedef struct tagPictureDataEx
{
    /* ͼ�����ݶ�Ӧ��UTCʱ�� */
    ULONG_32 ulUTCTime;

    /* ͼ�����ݶ�Ӧ��UTCʱ�䣨ͨ��UTCʱ���ʱ�������õ��� */
    ULONG_32 ulUTCTime2;

    /* ���ʱ�����Ϣ����λΪ���룩 */
    DLONG dlRelativeTimeStamp;

    /* ǰһ��I֡λ�� */
    ULONG_32 ulPFilePos;

    /* ��ǰ֡I֡λ�� */
    ULONG_32 ulCFilePos;

    /* ��һ��I֡λ�� */
    ULONG_32 ulNFilePos;

    /* �������� */
    CHAR szReserver[36];
}XP_PICTURE_DATA_EX_S;

/**
* @struct tagWaveData
* @brief ��Ž������Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagWaveData
{
    CHAR *pcData;                               /**< ��Ƶ����ָ�� */
    ULONG_32 ulDataLen;                            /**< ��Ƶ���ݳ��� */
    ULONG_32 ulWaveFormat;                         /**< �������Ƶ��ʽ����ӦtagWaveFormatInfoö���е�ֵ */
}XP_WAVE_DATA_S;

/**
* @struct tagWaveInFileInfo
* @brief ������Ƶ�ļ���Ϊ����Դʱ����Ҫ���õĶ��������Ϣ��
* @attention ��
*/
typedef struct tagWaveInFileInfo
{
    CHAR szWaveFileName[IMOS_FILE_PATH_LEN];    /**< ��Ƶ�ļ����ƣ�����·����Ϣ�� */
    BOOL_T bCyclePlay;                          /**< �Ƿ�ѭ��������Ƶ�ļ� */
}XP_WAVEIN_FILE_INFO_S;

/**
* @struct tagRect
* @brief ������Ϣ��
* @attention ��
*/
typedef struct tagRect
{
    LONG_32 lLeft;                               /*x�����ֵ�ٷֱ�[0 ~ 100]*/
    LONG_32 lTop;                                /*y�ᶥ��ֵ�ٷֱ�[0 ~ 100]*/
    LONG_32 lRight;                              /*x���ҵ�ֵ�ٷֱ�[0 ~ 100]*/
    LONG_32 lBottom;                             /*y��׵�ֵ�ٷֱ�[0 ~ 100]*/
}XP_RECT_S;

/**
* @struct tagPoint
* @brief �������Ϣ��
* @attention ��
*/
typedef struct tagPoint
{
    LONG_32 lX;                               /*x��ֵ�ٷֱ�[0 ~ 100]*/
    LONG_32 lY;                               /*y��ֵ�ٷֱ�[0 ~ 100]*/
}XP_POINT_S;

/**
* @struct tagPointEx
* @brief �������Ϣ��
* @attention ��
*/
typedef struct tagPointEx
{
    LONG_32 lX;                               /*x��ֵ�ٷֱ�[0 ~ 9999]*/
    LONG_32 lY;                               /*y��ֵ�ٷֱ�[0 ~ 9999]*/
}XP_POINTEX_S;
/**
 * @enum tagCombineZoomRect
 * @brief ƴ��ͼƬ�Ŵ�������Ϣ
 * @attention
 */
typedef struct tagCombineZoomRect
{
    LONG_32  lX;                              /* ƴ��ͼƬ����Ҫ�Ŵ����ĵ�Xָ��,��ȷ��0.01%,[0 -- 10000] */
    LONG_32  lY;                              /* ƴ��ͼƬ����Ҫ�Ŵ����ĵ�Yָ��,��ȷ��0.01%,[0 -- 10000] */
    ULONG_32 ulZoomHeight;                    /* �Ŵ�����ĸ߶�,��λΪ���� */
    ULONG_32 ulZoomWidth;                     /* �Ŵ�����Ŀ��,��λΪ���� */
}XP_COMBINE_ZOOM_RECT_S;


/**
 * @enum tagEncodeParam
 * @brief �������
 * @attention
 */
typedef struct tagEncodeParam
{
    ULONG_32 ulVideoEncType;     /* ��Ƶ�����ʽ, #XP_VIDEO_ENCODE_TYPE_E,�ֽ�֧��#XP_VIDEO_ENCODE_H264 */
    ULONG_32 ulAudioEncType;     /* ��Ƶ�����ʽ,#XP_AUDIO_ENCODE_TYPE_E */
    ULONG_32 ulEncMode;          /* ����ģʽ,#XP_ENCODE_MODE_E */
    ULONG_32 ulPktType;          /* �������,#XP_ENCODE_PACKET_TYPE_E*/
    ULONG_32 ulRltRatio;         /* �ֱ��ʴ�С����#XP_RESOLUTION_TYPE_E, #XP_RESOLUTION_AUTO Ϊԭʼ�ֱ���*/
    ULONG_32 ulQpValue;          /* VBRʱ,QPֵ��Ч,ȡֵ[1,51]��Ĭ����д������дΪ20*/
    ULONG_32 ulBitRate;          /* CBRʱ��������Ч����λkbps����Ϊ0ʱ���Զ����ݷֱ������ */
    ULONG_32 ulFrameRate;        /* ֡�� */
    ULONG_32 ulGopLen;           /* I֡��� */
    ULONG_32 ulEncSDK;              /* ����⣬Ĭ��ʹ��DSP�Ľ����, #XP_ENCODE_SDK_E */
}XP_ENCODE_PARAM_S;

/**
* @enum tagVideoAdjust
* @brief Ӱ����ڲ���
* @attention
*/
typedef struct tagVideoAdjust
{
    LONG_32 lCont;             /**< �Աȶ� */
    LONG_32 lLum;              /**< ���� */
    LONG_32 lHue;              /**< ɫ�� */
    LONG_32 lSat;              /**< ���Ͷ� */
    LONG_32 lGamma;            /**< ٤�� */
}XP_VIDEO_ADJUST_S;

/**
* @struct tagFileJointInfo
* @brief �ļ�ƴ����Ϣ
* @attention
*/
typedef struct tagFileJointInfo
{
    /* ƴ�����ɵ��ļ��Ĳ�����ʱ�� */
    ULONG_32 ulJointFileTotalTime;

    /* Ԥ���ֶ� */
    CHAR szReserve[60];
}XP_FILE_JOINT_INFO_S;

/**
* @struct tagMediaSectionTime
* @brief ý��Ƭ�ε���ʼʱ��
* @attention
*/
typedef struct tagMediaSectionTime
{
    CHAR szStartTime[IMOS_TIME_LEN];
    CHAR szEndTime[IMOS_TIME_LEN];
}XP_MEDIA_SECTION_TIME_S;

/**
* @struct tagPortResCodeInfo
* @brief ͨ����Դ����ṹ��
* @attention
*/
typedef struct tagPortResCodeInfo
{
    /** ͨ����Դ���� */
    CHAR szPortResCode[IMOS_RES_CODE_LEN];

    /* Ԥ���ֶ� */
    CHAR szReserve[128];
}PORD_RES_CODE_INFO_S;

/**
* @enum tagOsdOverInfo
* @brief OSD��Ϣ�Ľṹ��
* @attention
*/
typedef struct tagOsdOverInfo
{
    UCHAR *pucBuf;              /**< ����ָ�� */
    ULONG_32 ulBufLen;             /**< ���ݳ��� */
    ULONG_32 ulColor;              /**< ��ɫ */
    ULONG_32 ulPosX;               /**< X��ٷֱ�[0 ~ 100] */
    ULONG_32 ulPosY;               /**< Y��ٷֱ�[0 ~ 100] */
    ULONG_32 ulSize;               /**< �����С */
    /* Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */
    ULONG_32 ulOsdType;            /**< ���嶨���#XP_OSD_TYPE_INFO_E  */
    ULONG_32 ulOsdBkType;             /**< ���嶨���#XP_OSD_BK_TYPE_E  */
    ULONG_32 ulWidth;
    ULONG_32 ulHeigh;
    UCHAR ucOsdJudge[16];       /**< ������;��һ�㲻�ô��� */
    UCHAR ucReserver[232];     /**< �����ֶΣ�������չ��ʱ��Ӹ��ڴ���з��䣨��ǰSDK�û�����ĸÿ����ݱ���Ϊȫ0�����ں����ӿڹ�����չ��SDK������ */
}XP_OSD_OVER_INFO_S;

/* Begin: Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */
/**
* @enum tagOSDTypeInfo
* @brief OSD���Ͷ���
* @attention ��
*/
typedef enum tagOSDTypeInfo
{
    NORMAL_OSD = 0,          /**< ��ͨOSD */
    SYSTIME_OSD = 1,         /**< ϵͳʱ��OSD */
    VODTIME_OSD = 2          /**< �㲥�ط�ʱ��OSD */
}XP_OSD_TYPE_INFO_E;
/* END: Add by chenliang w0897, 2014/12/1, MPPD19576, ����汾�������Ժ�����D109 */

/**
* @enum tagOSDBkType
* @brief OSD�������Ͷ���
* @attention ��
*/
typedef enum tagOSDBkType
{
    NORMAL_BK_OSD = 0,            /**< OSD��ͨ���� */
    WATERMARK_BK_OSD = 1,         /**< OSDˮӡ���� */
}XP_OSD_BK_TYPE_E;

typedef struct tagTransParam
{
    ULONG_32 ulEncodeType;//XP_VIDEO_ENCODE_TYPE_E
    ULONG_32 ulWidth;
    ULONG_32 ulHeight;
}XP_TRANS_PARAM_S;

/**
 * @enum tagXPThruLineDirection
 * @brief "������Ϊ"����
 * @attention
 */
typedef enum tagXPThruLineDirection
{
    XP_THRU_LINE_DIRECTION_CLOCKWISE          = 0,    /**< ˳ʱ�� */
    XP_THRU_LINE_DIRECTION_ANTICLOCKWISE      = 1,    /**< ��ʱ�� */
    XP_THRU_LINE_DIRECTION_ALL                = 2,    /**< ˫�� */

    XP_THRU_LINE_DIRECTION_MAX,
    XP_THRU_LINE_DIRECTION_INVALID            = 0XFFFFFFFF
} XP_THRU_LINE_DIRECTION_E;

/**
 * @enum tagXPAreaDirection
 * @brief "������Ϊ"����
 * @attention
 */
typedef enum tagXPAreaDirection
{
    XP_AREA_DIRECTION_IN       = 0,    /**< In */
    XP_AREA_DIRECTION_OUT      = 1,    /**< Out */
    XP_AREA_DIRECTION_ALL      = 2,    /**< ˫�� */

    XP_AREA_DIRECTION_MAX,
    XP_AREA_DIRECTION_INVALID  = 0XFFFFFFFF
} XP_AREA_DIRECTION_E;

/**
 * @enum tagXPHWStatus
 * @brief Ӳ������
 * @attention
 */
typedef enum tagXPHWStatus
{
    XP_HW_NORMAL = 0,                    /**< ���� */
    XP_HW_DDRAW_NOSUPPORT   = 1,         /**< ��ͨƷ��Ӳ������δ���� */
    XP_HW_D3D_NOSUPPORT     = 2,         /**< ��Ʒ��Ӳ������δ���� */
    XP_HW_RENDER_NOSUPPORT  = 3          /**< Ӳ�����پ�δ���� */
}XP_HW_STATUS_E;

/**
 * @struct tagXpPTZAbsPosition
 * @brief ��̨����λ��
 * @attention ��
 */
typedef struct tagXpPTZAbsPosition
{
    FLOAT fLatitude;              /**< ��̨γ��, ��Χ: -18~90��, ������С�������λ */
    FLOAT fLongitude;             /**< ��̨����, ��Χ: 0~360��, ������С�������λ */
    FLOAT fMoveSpeed;             /**< ת�����ٶȣ�ȡֵ��Χ0-9��(�����н�����ͳһ)��0Ϊʹ��Ĭ���ٶ� */
}XP_PTZ_ABSPOSITION_S;

/**
 * @struct tagXpPTZAbsZoom
 * @brief ��̨���Ա䱶��Ϣ
 * @attention ��
 */
typedef struct tagXpPTZAbsZoom
{
    FLOAT fPtzZoomNum;        /**< ��̨zoom ��������ȷ��С�������λ��ȡֵ��Χ1-36 */
    FLOAT fPtzZoomSpeed;      /**< ��̨zoom �ٶȣ�99�� 1-99 */
}XP_PTZ_ABSZOOM_S;

/**
 * @struct tagXPBallLoginInfo
 * @brief �����¼�����Ϣ
 * @attention
 */
typedef struct tagXPBallLoginInfo
{
    CHAR   szBallCameraIP[IMOS_IPADDR_LEN];  /**< ���IP��ַ */
    USHORT usBallCameraPort;                 /**< ����˿ں� */
    CHAR   szUserName[IMOS_NAME_LEN];        /**< �����¼�û��� */
    CHAR   szPassword[IMOS_PASSWD_LEN];      /**< �����¼���� */
}XP_BALL_LOGIN_INFO_S;

/**
 * @struct tagXPBLMatchPointParam
 * @brief  ǹ������ӳ������ṹ��
 * @attention
 */
typedef struct tagXPBLMatchPointParam
{
    USHORT usMasterPointX;     /**< ǹ��X���� */
    USHORT usMasterPointY;     /**< ǹ��Y���� */
    USHORT usSlavePointX;      /**< ����������� */
    USHORT usSlavePointY;      /**< ���γ������ */
}XP_BL_MATCH_POINT_PARAM_S;

/**
 * @struct tagXPBallMarkPoint
 * @brief  ����궨��Ϣ
 * @attention
 */
typedef struct tagXPBallMarkPoint
{
    USHORT  usCameraImageWdith;   /**< ǹ�������� */
    USHORT  usCameraImageHeight;  /**< ǹ������߶� */
    USHORT  usBallImageWidth;     /**< ��������� */
    USHORT  usBallImageHeight;    /**< �������߶� */
    USHORT  usBlMatchPointNum;    /**< ����궨����� */
    XP_BL_MATCH_POINT_PARAM_S  *pstBLMatchPointParam;  /**< ����궨�� */
}XP_BALL_MARK_POINT_S;

/**
 * @struct tagXPBLOffsetMatchPointParam
 * @brief  �����оƫ��ӳ������ṹ��
 * @attention
 */
typedef struct tagXPBLOffsetMatchPointParam
{
    USHORT      usZoomNum;  /**< �䱶ϵ�� */
    USHORT      usPointX;   /**< �������X */
    USHORT      usPointY;   /**< �������Y */
}XP_BL_OFFSET_MATCH_POINT_PARAM_S;

/**
* @struct tagXPBLOffsetMatchParam
* @brief  �����оƫ�����
* @attention
*/
/*�����оƫ��ӳ����������ṹ��*/
typedef struct tagXPBLOffsetMatchParam
{
    USHORT         usMaxZoonNum;  /**< ������䱶ϵ�� */
    USHORT         usZoomCnt;     /**< �����о�䱶�������� */
    XP_BL_OFFSET_MATCH_POINT_PARAM_S* pstBlOffsetMatchPointParam;  /**< �����о�䱶���� */
}XP_BL_OFFSET_MATCHPARAM_S;

/**
 * @struct tagXPCameraZoomArea
 * @brief ����������Ϣ
 * @attention ��
 */
typedef struct tagXPCameraZoomArea
{
    USHORT usMidPointX;         /**< �������ĵ������ */
    USHORT usMidPointY;         /**< �������ĵ������� */
    USHORT usLengthX;           /**< ���򳤶� */
    USHORT usLengthY;           /**< ������ */
    USHORT usWidth;             /**< ���Ŵ��񳤶� */
    USHORT usHeight;            /**< ���Ŵ����� */
}XP_CAMERA_ZOOMAREA_S;

/**
* @enum tagTsFileJointMode
* @brief tsƴ��ģʽö�ٶ���
* @attention ��
*/
typedef enum tagTsFileJointMode
{
    XP_TSJOINT_MODE_NOMAL = 0,           /**< ��ͨģʽ ֱ��׷��ģʽ*/
    XP_TSJOINT_MODE_PAT = 1              /**<   patģʽ ��Ҫƫ�Ƶ���һ��I֡ǰ���P֡*/
}XP_TSJOINT_MODE_E;

/**
* @enum tagAudioChannel
* @brief ��Ƶ������������
* @attention ��
*/
typedef enum tagAudioChannel
{
    XP_AUDIO_CHANNEL_LEFT = 0,       /**< ������ */
    XP_AUDIO_CHANNEL_RIGHT = 1,      /**< ������ */
}XP_AUDIO_CHANNEL_E;

/**
* @enum tagXPMediaType
* @brief ý����������
* @attention ��
*/
typedef enum tagXPMediaType
{
    XP_MEDIA_NONE = 0,       /**< ��û��Ƶ��Ҳû��Ƶ  */
    XP_MEDIA_AUDIO_ONLY = 1, /**< ֻ������Ƶ���� */
    XP_MEDIA_VIDEO_ONLY = 2, /**< ֻ������Ƶ���� */
    XP_MEDIA_BOTH = 3        /**< ��������Ƶ���� */
}XP_MEDIATYPE_E;

/**
* @enum tagBarrelAdjustLevel
* @brief Ͱ�ͽ����ȼ�
* @attention ��
*/
typedef enum tagBarrelAdjustLevel
{
    XP_BARREL_ADJUST_LEVEL_1 = 1,   /** Ͱ�ͽ����ȼ�1 */
    XP_BARREL_ADJUST_LEVEL_2 = 2,   /** Ͱ�ͽ����ȼ�2 */
    XP_BARREL_ADJUST_LEVEL_3 = 3,   /** Ͱ�ͽ����ȼ�3 */
    XP_BARREL_ADJUST_LEVEL_4 = 4,   /** Ͱ�ͽ����ȼ�4 */
    XP_BARREL_ADJUST_LEVEL_5 = 5,   /** Ͱ�ͽ����ȼ�5 */
    XP_BARREL_ADJUST_LEVEL_6 = 6,   /** Ͱ�ͽ����ȼ�6 */
    XP_BARREL_ADJUST_LEVEL_7 = 7,   /** Ͱ�ͽ����ȼ�7 */
    XP_BARREL_ADJUST_LEVEL_8 = 8,   /** Ͱ�ͽ����ȼ�8 */
    XP_BARREL_ADJUST_LEVEL_9 = 9,   /** Ͱ�ͽ����ȼ�9 */
    XP_BARREL_ADJUST_LEVEL_10 = 10  /** Ͱ�ͽ����ȼ�10 */
} XP_BARREL_ADJUST_LEVEL_E;

/* Begin add by sunbiao/sW1071 2014.10.28 for MPPD18406 ����dspȥ���� */
/**
* @enum tagXpDeshakeParm
* @brief dspȥ��������
* @attention ��
*/
typedef struct tagXpDeshakeParm
{
    ULONG_32 ulMaxXoffset;             //��Χ0-100 ��Ե��ȡ��� Ĭ��50
    ULONG_32 ulMaxYoffset;             //��Χ0-100 ��Ե��ȡ���� Ĭ��50
    ULONG_32 ulUpdateFrameNum;         //��Χ25-100��Ĭ��25��ˢ��֡�����
}XP_DESHAKE_PARM_S;
/* Begin add by sunbiao/sW1071 2014.10.28 for MPPD18406 ����dspȥ���� */

/**
* @enum tagAppliProtlID
* @brief Ӧ�ò�Э������
* @attention ��
*/
typedef enum tagAppliProtl
{
    APPLI_PROTL_NONE = 0,            /* û�ж���Ӧ�ò�Э�� */
    APPLI_PROTL_RTP,                 /* ָ��Э��Ϊrtp */
}XP_APPLI_PROTL_E;

/**
* @struct tagMediaAbility
* @brief ý���������ṹ�塣
* @attention ��
*/
typedef struct tagMediaAbility
{
    CHAR szDecoderTag[IMOS_CODE_LEN];             /**< �����ǩ */
    CHAR szReceiveIP[IMOS_IPADDR_LEN];              /**< ����IP��ַ */
    USHORT usReceivePort;                           /**< �����˿ں�(������) */
    CHAR szSendIP[IMOS_IPADDR_LEN];              /**< ����IP��ַ */
    USHORT usSendPort;                           /**< �����˿ں�(������) */

    XP_PROTOCOL_E enProtocol;                    /* ����Э�� */

    XP_APPLI_PROTL_E enAppliProtl;                /**  Ӧ�ò�Э�� */

    XP_ENCODE_PACKET_TYPE_E enPacketType;         /**  ������װ���� */

}XP_MEDIA_ABILITY_S;

/**
/* ��Ϣ�����쳣��Ϣ�ص�������ָ�����ͣ����Ͻӿں���#XP_SetRunMsgCB��ʹ�á�\n
* @param [IN] enRunInfoType ��Ϣ�����쳣��Ϣ���͡�
* @param [IN] pParam        �����Ϣ�����쳣��Ϣ���ݵĻ�����ָ�루����ŵ���������Ϣ�����쳣��Ϣ�����йأ���
* @return �ޡ�
* @note
* -     1���ͻ���ʵ�ָûص�����ʱ��Ҫȷ���������췵�أ����������������XP�ڲ����øûص��������̡߳�
* -     2������pParam��ʵ�����͸��ݾ������Ϣ�����쳣��Ϣ���Ͷ������ͻ���Ҫ������Ϣ�����쳣��Ϣ��������Ӧ������ת������ĳЩ����£��ò����п���ΪNULL��
* -     ���������ת����ϵ���£�
* -         ��enRunInfoTypeֵΪ#XP_RUN_INFO_SERIES_SNATCH��#XP_RUN_INFO_RECORD_VIDEO��#XP_RUN_INFO_MEDIA_PROCESS��
* -     #XP_RUN_INFO_RTSP_PROTOCOL��#XP_RUN_INFO_PASSIVE_MONITORʱ���뽫pParamָ��ת��Ϊ#XP_RUN_INFO_S�ṹ��ָ�����ͣ�
* -         ��enRunInfoTypeֵΪ#XP_RUN_INFO_DOWN_MEDIA_PROCESS��#XP_RUN_INFO_DOWN_RTSP_PROTOCOLʱ��
* -     �뽫pParamָ��ת��Ϊ#XP_DOWN_RUN_INFO_S�ṹ��ָ�����ͣ�
* -         ��enRunInfoTypeֵΪ#XP_RUN_INFO_VOICE_MEDIA_PROCESSʱ���轫pParamָ��ת��Ϊ#XP_VOICE_RUN_INFO_S�ṹ��ָ�����ͣ�
* -         ��enRunInfoTypeֵΪ#XP_RUN_INFO_SIP_LIVE_TIMEOUTʱ��pParamָ��ΪNULL��
*/
typedef VOID (STDCALL* XP_RUN_INFO_CALLBACK_PF)(IN XP_RUN_INFO_TYPE_E enRunInfoType,
                                                IN VOID *pParam);

/**
* �����ý�������ݻص�������ָ�����ͣ����Ͻӿں���#XP_SetOutputMediaDataCB��ʹ�á�\n
* @param [IN] hXpWnd          ���Ŵ��ھ����
* @param [IN] enMediaDataType �����ý�����������͡�
* @param [IN] pDataParam      ��Ž����ý����������Ϣ������ָ�루����ŵ�ý����������ý�������������йأ���
* @return �ޡ�
* @note
* -     1���ͻ�Ӧ��ʱ���������ý�����ݣ�ȷ���������췵�أ������Ӱ�첥����XP�ڵ�ý��������
* -     2������pDataParam��ʵ�����������enMediaDataType�йأ��ͻ���Ҫ����������Ϣ��������Ӧ������ת����
* -     ���������ת����ϵ���£�
* -         ��enMediaDataTypeֵΪ#XP_VIDEO_DATA_DECODEʱ���뽫pDataParamָ��ת��Ϊ#XP_PICTURE_DATA_S�ṹ��ָ�����ͣ�
* -         ��enMediaDataTypeֵΪ#XP_AUDIO_DATA_DECODEʱ���뽫pDataParamָ��ת��Ϊ#XP_WAVE_DATA_S�ṹ��ָ�����͡�
*/
typedef VOID (STDCALL* XP_PROCESS_MEDIA_DATA_CALLBACK_PF)(IN IMOS_HANDLE hWnd,
                                                          IN XP_OUTPUT_MEDIA_DATA_TYPE_E enMediaDataType,
                                                          IN const VOID *pDataParam);

/**
* ת��ص�������ָ�����͡�\n
* @param [IN] ulPort           ����ͨ����
* @param [IN] pucBuffer        ת�����������ָ��
* @param [IN] ulBufSize        ��������С
* @param [IN] lUserParam       �û����ò��������û��ڵ���#IMOS_XP_SetTranscodeCB����ʱָ�����û�����
* @param [IN] lReserved        Ԥ������
* @return �ޡ�
* @note  �û�Ӧ��ʱ���������ý�������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* XP_PLAYER_TRANSCODE_CALLBACK_PF)(IN ULONG_32 ulPort,
                                                        IN const UCHAR *pucBuffer,
                                                        IN ULONG_32 ulBufSize,
                                                        IN LONG_REAL lUserParam,
                                                        IN LONG_REAL lReserved);

#endif /* _IMOS_MEDIA_PLAY_SDK_DATA_TYPE_H_ */
