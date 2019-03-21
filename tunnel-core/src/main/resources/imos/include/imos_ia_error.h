
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

#define ERR_IA_COMMON_UNINITIAL            (ERR_IA_COMMON_BASE + 2)    /* IA������δ��ʼ�� */
#define ERR_IA_COMMON_PARAMETER_INVALID    (ERR_IA_COMMON_BASE + 3)    /* ��������Ƿ� */
#define ERR_IA_COMMON_NO_MEMORY            (ERR_IA_COMMON_BASE + 4)    /* �ڴ治�� */
#define ERR_IA_COMMON_RES_ISNOT_EXIST      (ERR_IA_COMMON_BASE + 5)    /* ������Դ������ */
#define ERR_IA_COMMON_RES_HAVE_EXIST       (ERR_IA_COMMON_BASE + 6)    /* ��Ҫ��������Դ�Ѿ����� */
#define ERR_IA_COMMON_CREATE_RES           (ERR_IA_COMMON_BASE + 7)    /* ������Դʧ�� */
#define ERR_IA_COMMON_EXCEPTION            (ERR_IA_COMMON_BASE + 8)    /* �������쳣 */
#define ERR_IA_COMMON_VOD_COMPLIETE        (ERR_IA_COMMON_BASE + 9)    /* �ط���� */
#define ERR_IA_COMMON_MERGEFILE_NO_FILE    (ERR_IA_COMMON_BASE + 11)   /* �������ļ��޷��ϲ�*/
#define ERR_IA_COMMON_DOWNLOAD_ERR         (ERR_IA_COMMON_BASE + 12)   /* ����ʧ��*/
#define ERR_IA_COMMON_RES_NOT_ENOUGH       (ERR_IA_COMMON_BASE + 13)   /* �������Դ����*/
#define ERR_IA_COMMON_9LIN_EXCEPTION       (ERR_IA_COMMON_BASE + 14)   /* �����쳣*/
#define ERR_IA_COMMON_NOT_9LIN_SERVER	   (ERR_IA_COMMON_BASE + 15)   /* ���Ǿ��������*/

/* UserMgr������ */
#define ERR_IA_USER_ISNOT_EXIST            (ERR_IA_COMMON_BASE + 20)   /* �û������� */
#define ERR_IA_USER_PASSWD                 (ERR_IA_COMMON_BASE + 21)   /* �û�������� */
#define ERR_IA_USER_KEEPALIVE              (ERR_IA_COMMON_BASE + 22)   /* �û����ʱ */

#define ERR_IA_URL_IS_EMPTY                (ERR_IA_COMMON_BASE + 23)   /* url ��ԴΪ��,����δ���ô洢��Դ�����������*/
#define ERR_IA_USER_NOT_LOGIN              (ERR_IA_COMMON_BASE + 24)   /* �û�δ��¼*/

/* sourceģ������� */
#define ERR_IA_SOURCE_RECV                 (ERR_IA_COMMON_BASE + 50)
#define ERR_IA_SOURCE_SEND                 (ERR_IA_COMMON_BASE + 51)
#define ERR_IA_SOURCE_TIMEOUT              (ERR_IA_COMMON_BASE + 52)
#define ERR_IA_SOURCE_KEEPALIVE_FAILD      (ERR_IA_COMMON_BASE + 55)   /*source ����ʧ��*/
#define ERR_IA_SOURCE_GETRES_FAILD         (ERR_IA_COMMON_BASE + 56)   /*��ȡͨ����Դʧ��*/
#define ERR_IA_SOURCE_STARTVOD_FAILD       (ERR_IA_COMMON_BASE + 57)   /*�����ط�ʧ��*/

/*decoder filter ʧ�ܴ����뷶Χ*/
#define ERR_IA_DECODER_BASE                (ERR_IA_COMMON_BASE + 100)
#define ERR_IA_DECODER_RES_FAIL            (ERR_IA_DECODER_BASE + 101)

/*analytics filter ʧ�ܴ����뷶Χ*/
#define ERR_IA_ANALYTICS_BASE              (ERR_IA_COMMON_BASE + 200)

/* ҵ��������� */
#define ERR_IA_LOGIN_FAILED                (ERR_IA_COMMON_BASE + 300)   /* �û���¼ʧ�� */
#define ERR_IA_CREATE_MSG_CHANNEL          (ERR_IA_COMMON_BASE + 301)   /* ������������ͻ�����Ϣͨ��ͨ��ʧ�� */

/* licenseģ������� */
#define ERR_IA_COMMON_NO_LICENSE           (ERR_IA_COMMON_BASE + 400)   /* licenseδ��Ȩ */
#define ERR_IA_COMMON_EXPIRE               (ERR_IA_COMMON_BASE + 401)   /* license���� */
#define ERR_IA_COMMON_OUTNUMBER            (ERR_IA_COMMON_BASE + 402)   /* license������Ȩ���� */
#define ERR_IA_COMMON_HANDLE_REPEAT        (ERR_IA_COMMON_BASE + 403)   /* �ظ�������ҵ���� */

/* merger ģ�������*/
#define ERR_IA_COMMON_NO_ALARM             (ERR_IA_COMMON_BASE + 450)   /* ָ��ʱ�����޸澯*/
#define ERR_IA_COMMON_DIFFTIME_ZERO        (ERR_IA_COMMON_BASE + 451)   /* ָ��ʱ����Ϊ0*/
#define ERR_IA_COMMON_UPLOAD_LARGEFILE     (ERR_IA_COMMON_BASE + 452)   /* �ϲ�����1G���ļ�*/
#define ERR_IA_COMMON_UPLOAD_FAILD         (ERR_IA_COMMON_BASE + 453)   /* �ϴ������ݷ�����ʧ��*/
#endif