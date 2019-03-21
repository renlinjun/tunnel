/*****************************************************************************
*
*                ��Ϊ3COM �������޹�˾(2004)
*                            ��Ȩ����
*
*-----------------------------------------------------------------------------
*
*                            License_struct_def.h
*
*    ��Ʒ��:)
*    ģ����:
*  ��������: 2012/8/31
*      ����: kangshunli
*  �ļ�����: License_struct_def.h ��ͷ�ļ�
*
*-----------------------------------------------------------------------------
*   �޸���ʷ
*   ����        ����             ����
*-----------------------------------------------------------------------------
*
 *****************************************************************************/
#ifndef __LICENSE_STRUCT_DEF_H__
#define __LICENSE_STRUCT_DEF_H__

/*@brief ͨ�������ַ�������*/
#define IA_NAME_LEN            64

/*@brief E-mail�ַ�������*/
#define IA_EMAI_LEN            64

/*@brief �绰������󳤶�*/
#define IA_PHONE_LEN           32

/*@brief �ʱ೤��*/
#define IA_MAIL_CODE_LEN       8

/*@brief ��ϵ�˵�ַ����*/
#define IA_CONTACT_ADDRESS_LEN 64

/*@brief ʱ���ַ�������*/
#define TIME_STRING_LEN        21

/*@brief License������Ч*/
#define IA_LICENSE_NOT_EXPIRE 0xFFFFFFFF

/* ��������ҵ������ö�� */
typedef enum tagInteTaskType
{
    INTE_TASK_TYPE_BACKUP               = 0x41,       /** ���ܱ��� */
    INTE_TASK_TYPE_PERIMETER            = 0X41,       /** �ܽ�license */
    INTE_TASK_TYPE_VD                   = 0xfe,       /** ��Ƶ��� */
    INTE_TASK_TYPE_OCCUPANCY_LANE       = 0xff,       /** ռ������ */
}INTE_TASK_TYPE_E;

/**
* @struct tagContactInfo
* @brief ��ϵ����Ϣ�ṹ
* @attention ��
*/
typedef struct tagIAContactInfo
{
    /** ��ϵ������ */
    char szName[IA_NAME_LEN];

    /** ��ϵ�����ڹ�˾ */
    char szCompany[IA_NAME_LEN];

    /** ��ϵ��email��ַ */
    char szEmail[IA_EMAI_LEN];

    /** ��ϵ�˵绰 */
    char szPhone[IA_PHONE_LEN];

    /** ��ϵ���ʱ� */
    char szZipcode[IA_MAIL_CODE_LEN];

    /** ��ϵ�˵�ַ */
    char szAddress[IA_CONTACT_ADDRESS_LEN];

} IA_CONTACTINFO_S;

/**
* @struct tagClientInfo
* @brief �û���Ϣ�ṹ
* @attention ��
*/
typedef struct tagIAClientInfo
{
    /** �ͻ����ƣ�һ��ͬ��˾���� */
    char szClientName[IA_NAME_LEN];

    /** ���� */
    char szCountry[IA_NAME_LEN];

    /** ʡ */
    char szProvince[IA_NAME_LEN];

    /** ���� */
    char szCity[IA_NAME_LEN];

    /** ��˾ */
    char szCompany[IA_NAME_LEN];

    /** �ʱ� */
    char szZipcode[IA_MAIL_CODE_LEN];

    /** ��ַ */
    char szAddress[IA_CONTACT_ADDRESS_LEN];

    /** email��ַ */
    char szEmail[IA_EMAI_LEN];

    /** �绰 */
    char szPhone[IA_PHONE_LEN];

    /** ��ϵ����Ϣ */
    IA_CONTACTINFO_S stContactInfo;

} IA_CLIENTINFO_S;


typedef struct tagIALicenseInfo
{
    long lServiceType;        /** ҵ������ */
    long lServiceValue;       /** ��Ȩ��� */
    long lUsedValue;          /** ���ù�� */
    unsigned long ulCreateTime;       /** License�������� */
    unsigned long ulTotalDay;         /** ��Ч����IA_LICENSE_NOT_EXPIREΪ������Ч������ֵΪ���ð汾License��Ч���� */
    unsigned long ulUsedDay;          /** ��ʹ������ */
}IA_LICENSE_INFO_S;


#endif /* __LICENSE_STRUCT_DEF_H__ */
