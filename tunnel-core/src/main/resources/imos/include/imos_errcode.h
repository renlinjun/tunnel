/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_errcode.h

  Project Code: IMOS PLAT
   Module Name: BP
  Date Created: 2008-08-28
        Author: wuxianmin/04253
   Description: ����ƽ̨���������붨��ͷ�ļ�

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

/* ͨ�ô����� */
#define ERR_COMMON_SUCCEED                      0x000000              /**< ִ�гɹ� */
#define ERR_COMMON_FAIL                         0x000001              /**< ִ��ʧ�� */
#define ERR_COMMON_INVALID_PARAM                0x000002              /**< ��������Ƿ� */
#define ERR_COMMON_NO_MEMORY                    0x000003              /**< ϵͳ�ڴ治�� */
#define ERR_COMMON_SYS_FAIL                     0x000004              /**< ϵͳͨ�ô��� */
#define ERR_COMMON_IE_NOT_EXIST                 0x000005              /**< IE������ */
/* Begin Add By hexiaojun/hW0959 for �û���¼ʱ������ */
#define ERR_COMMON_CB_STATUS_CHANGE                    0x000006              /**< ���ƿ��е�¼ʱ�䳬���趨��Χ״̬�仯 */
#define ERR_COMMON_CB_BEYOND_EFECTIVE_TIME             0x000007              /**< ���ƿ��е�¼��Чʱ�䳬���趨��Χ״̬�仯 */
/* End Add By hexiaojun/hW0959 for �û���¼ʱ������ */

/* �ļ���Ŀ¼���� */
#define ERR_COMMON_DIR_FAIL_OPEN                0x000010              /**< ��Ŀ¼ʧ�� */
#define ERR_COMMON_DIR_FAIL_READ                0x000011              /**< ��ȡĿ¼�ļ�ʧ�� */
#define ERR_COMMON_DIR_FAIL_REMOVE              0x000012              /**< ɾ��Ŀ¼ʧ�� */
#define ERR_COMMON_DIR_FAIL_MKDIR               0x000013              /**< ����Ŀ¼ʧ�� */
#define ERR_COMMON_FILE_CANT_OPEN               0x000015              /**< �򿪣��������ļ�ʧ�� */
#define ERR_COMMON_FILE_FAIL_FSEEK              0x000016              /**< �����ļ���дλ��ʧ�� */
#define ERR_COMMON_FILE_FAIL_FTELL              0x000017              /**< ��ȡ�ļ���дλ��ʧ�� */
#define ERR_COMMON_FILE_FAIL_FREAD              0x000018              /**< ��ȡ�ļ�ʧ�� */
#define ERR_COMMON_FILE_FAIL_FWRITE             0x000019              /**< д���ļ�ʧ�� */
#define ERR_COMMON_FAIL_STAT                    0x00001A              /**< ��ȡ�ļ���Ŀ¼��״̬ʧ�� */
#define ERR_COMMON_FILE_FAIL_CHMOD              0x00001B              /**< �޸��ļ�����ʧ�� */
#define ERR_COMMON_FILE_FAIL_DELETE             0x00001C              /**< ɾ���ļ�ʧ�� */

/* ���ݿ������� */
#define ERR_COMMON_DB_EXCEPTION                 0x000020              /**< ���ݿ�����쳣 */
#define ERR_COMMON_DB_RECORD_NOT_EXIST          0x000021              /**< ���ݿ��¼������ */
#define ERR_COMMON_DB_READ_DATA_EXCEPTION       0x000022              /**< ���ݿ��ȡ��¼�쳣 */
#define ERR_COMMON_DB_RECORD_EXIST              0x000023              /**< ���ݿ��¼�Ѵ��� */
/* added by c02845,2016-06-17,��ͨ����Ϣ���� */
#define ERR_COMMON_DB_READ_DATA_OUTLIMIT        0x000024              /**< ���ݿ��ȡ��¼�������� */

/* ϵͳ����������� */
#define ERR_COMMON_FAIL_CALL_SYSTEM             0x000030              /**< ִ��shell�ű�ʧ�� */
#define ERR_COMMON_FAIL_CALL_POPEN              0x000031              /**< �򿪹ܵ�ʧ�� */

#define ERR_COMMON_PROCSRV_BUSY                 0x000032              /**< ҵ��æ */

/* ����ΪSIPͨ�ô����루�����뷶Χ100~700�� */
#define ERR_COMMON_SIP_RSP_STATE_RINGING        180   /**< ���б������� */
#define ERR_COMMON_SIP_RSP_STATE_CALLFORWARD    181   /**< ��������ת���� */
#define ERR_COMMON_SIP_RSP_STATE_QUEUED         182   /**< �������ڶ��еȴ��� */
#define ERR_COMMON_SIP_RSP_STATE_SSNPRORESS     183   /**< ����Զ�������� */
#define ERR_COMMON_SIP_RSP_STATE_OK             200   /**< ����ժ�� */
#define ERR_COMMON_SIP_RSP_STATE_MULTCHOICE     300   /**< ���ж�·ѡ�� */
#define ERR_COMMON_SIP_RSP_STATE_MOVPER         301   /**< ����ת�� */
#define ERR_COMMON_SIP_RSP_STATE_MOVTEM         302   /**< ��ʱת�� */
#define ERR_COMMON_SIP_RSP_STATE_USEPROXY       305   /**< ����ģʽӦ�� */
#define ERR_COMMON_SIP_RSP_STATE_ALTERSER       380   /**< ��ѡ���� */
#define ERR_COMMON_SIP_RSP_STATE_BADREQ         400   /**< ����ͷ����� */
#define ERR_COMMON_SIP_RSP_STATE_UNAUTHORIZE    401   /**< ��Ȩδͨ�� */
#define ERR_COMMON_SIP_RSP_STATE_PAYREQ         402   /**< ���Ѳ���, ����ʧ�� */
#define ERR_COMMON_SIP_RSP_STATE_FORBIDDEN      403   /**< ���񱻽�ֹ */
#define ERR_COMMON_SIP_RSP_STATE_NOTFOUND       404   /**< Ŀ�Ķ˲����� */
#define ERR_COMMON_SIP_RSP_STATE_METHNOTALLOW   405   /**< ��֧�ֵķ��� */
#define ERR_COMMON_SIP_RSP_STATE_NOTACPT        406   /**< ���󲻱����� */
#define ERR_COMMON_SIP_RSP_STATE_PROXYAUTHREQ   407   /**< ����ģʽ��Ȩ���� */
#define ERR_COMMON_SIP_RSP_STATE_REQTIMEOUT     408   /**< ����ʱ */
#define ERR_COMMON_SIP_RSP_STATE_GONE           410   /**< ������� */
#define ERR_COMMON_SIP_RSP_STATE_REQLARGE       413   /**< ������Ϣ��̫�� */
#define ERR_COMMON_SIP_RSP_STATE_URILONG        414   /**< ����URI̫�� */
#define ERR_COMMON_SIP_RSP_STATE_UNSUPPTYPE     415   /**< ��֧�ֵ�ý������ */
#define ERR_COMMON_SIP_RSP_STATE_UNSUPPURI      416   /**< ��֧�ֵ�URI�� */
#define ERR_COMMON_SIP_RSP_STATE_BADEXTEND      420   /**< �Ƿ�����չ�ֶ� */
#define ERR_COMMON_SIP_RSP_STATE_EXTENDREQ      421   /**< ��չ������ */
#define ERR_COMMON_SIP_RSP_STATE_INTERBRIEFE    423   /**< ���̫�� */
#define ERR_COMMON_SIP_RSP_STATE_NOTENFBNDWTH   453   /**< ������ */
#define ERR_COMMON_SIP_RSP_STATE_TEMPUNAVAIL    480   /**< ��Դ��ʱ������ */
#define ERR_COMMON_SIP_RSP_STATE_CALLNOTEXIST   481   /**< ���л������񲻴��� */
#define ERR_COMMON_SIP_RSP_STATE_MANYHOP        483   /**< �м�����̫�� */
#define ERR_COMMON_SIP_RSP_STATE_ADDRINCOMP     484   /**< ��ַ��ȫ */
#define ERR_COMMON_SIP_RSP_STATE_AMBIGUOUS      485   /**< ��Ϣ����ȷ */
#define ERR_COMMON_SIP_RSP_STATE_BUSY           486   /**< ������æ */
#define ERR_COMMON_SIP_RSP_STATE_REQTERM        487   /**< ������ֹ */
#define ERR_COMMON_SIP_RSP_STATE_NOACPTHERE     488   /**< ��ǰ���󲻱����� */
#define ERR_COMMON_SIP_RSP_STATE_REQPEND        491   /**< ��������� */
#define ERR_COMMON_SIP_RSP_STATE_UNDECIPHER     493   /**< ����ȷ�ϵ����� */
#define ERR_COMMON_SIP_RSP_STATE_SERVINTERERR   500   /**< ����˴��� */
#define ERR_COMMON_SIP_RSP_STATE_NOTIMPLEMENT   501   /**< δ��ִ�� */
#define ERR_COMMON_SIP_RSP_STATE_BADGATEWAY     502   /**< ���ش��� */
#define ERR_COMMON_SIP_RSP_STATE_SERVUNAVAIL    503   /**< ����˲����� */
#define ERR_COMMON_SIP_RSP_STATE_SERVTIMEOUT    504   /**< ����˳�ʱ */
#define ERR_COMMON_SIP_RSP_STATE_VERSNOTSUPP    505   /**< ��֧�ֵİ汾 */
#define ERR_COMMON_SIP_RSP_STATE_MSGLARGE       513   /**< ��Ϣ̫�� */
#define ERR_COMMON_SIP_RSP_STATE_BUSYALL        600   /**< ����æ, ������Դ�ľ� */
#define ERR_COMMON_SIP_RSP_STATE_DECLINE        603   /**< ����л�� */
#define ERR_COMMON_SIP_RSP_STATE_NOTEXIST       604   /**< ����ȫ�嶼������ */
#define ERR_COMMON_SIP_RSP_STATE_NOTACCEPT      606   /**< ������ */
/* Begin Added by w00523, 2012-08-23 for SIP-TCP project */
#define ERR_COMMON_SIP_RSP_STATE_HEADER_WAIT    608   /**< SIP����ͷ������ */
#define ERR_COMMON_SIP_RSP_STATE_FRAGMENT       609   /**< ���ķ�Ƭδ�� */
#define ERR_COMMON_SIP_RSP_STATE_TCP_MSG_ERR    610   /**< TCP��Ϣ����ʧ�� */
#define ERR_COMMON_SIP_RSP_STATE_TCP_LINK_ERR   611   /**< TCP�����쳣 */
#define ERR_COMMON_SIP_RSP_STATE_TCP_CCB_ERR    612   /**< TCP��Ϣ���ƿ��쳣 */
#define ERR_COMMON_SIP_RSP_STATE_MSG_LONG       613   /**< SIP��Ϣ̫�� */
#define ERR_COMMON_SIP_RSP_STATE_NO_TCPCCB_FIND 614   /**< TCP���ӿ��ƿ鲻���� */
#define ERR_COMMON_SIP_RSP_STATE_TCP_CCB_MAX    615   /**< TCP���ӿ��ƿ����� */
/* End Added by w00523, 2012-08-23 for SIP-TCP project */
/* ����ΪSIPͨ�ô����� */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* end of _IMOS_ERRCODE_H_ */
