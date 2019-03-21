/*****************************************************************************
*
*                华为3COM 技术有限公司(2004)
*                            版权所有
*
*-----------------------------------------------------------------------------
*
*                            License_struct_def.h
*
*    产品名:)
*    模块名:
*  生成日期: 2012/8/31
*      作者: kangshunli
*  文件描述: License_struct_def.h 的头文件
*
*-----------------------------------------------------------------------------
*   修改历史
*   日期        姓名             描述
*-----------------------------------------------------------------------------
*
 *****************************************************************************/
#ifndef __LICENSE_STRUCT_DEF_H__
#define __LICENSE_STRUCT_DEF_H__

/*@brief 通用名称字符串长度*/
#define IA_NAME_LEN            64

/*@brief E-mail字符串长度*/
#define IA_EMAI_LEN            64

/*@brief 电话号码最大长度*/
#define IA_PHONE_LEN           32

/*@brief 邮编长度*/
#define IA_MAIL_CODE_LEN       8

/*@brief 联系人地址长度*/
#define IA_CONTACT_ADDRESS_LEN 64

/*@brief 时间字符串长度*/
#define TIME_STRING_LEN        21

/*@brief License永久有效*/
#define IA_LICENSE_NOT_EXPIRE 0xFFFFFFFF

/* 智能任务业务类型枚举 */
typedef enum tagInteTaskType
{
    INTE_TASK_TYPE_BACKUP               = 0x41,       /** 智能备份 */
    INTE_TASK_TYPE_PERIMETER            = 0X41,       /** 周界license */
    INTE_TASK_TYPE_VD                   = 0xfe,       /** 视频诊断 */
    INTE_TASK_TYPE_OCCUPANCY_LANE       = 0xff,       /** 占道分析 */
}INTE_TASK_TYPE_E;

/**
* @struct tagContactInfo
* @brief 联系人信息结构
* @attention 无
*/
typedef struct tagIAContactInfo
{
    /** 联系人姓名 */
    char szName[IA_NAME_LEN];

    /** 联系人所在公司 */
    char szCompany[IA_NAME_LEN];

    /** 联系人email地址 */
    char szEmail[IA_EMAI_LEN];

    /** 联系人电话 */
    char szPhone[IA_PHONE_LEN];

    /** 联系人邮编 */
    char szZipcode[IA_MAIL_CODE_LEN];

    /** 联系人地址 */
    char szAddress[IA_CONTACT_ADDRESS_LEN];

} IA_CONTACTINFO_S;

/**
* @struct tagClientInfo
* @brief 用户信息结构
* @attention 无
*/
typedef struct tagIAClientInfo
{
    /** 客户名称，一般同公司名称 */
    char szClientName[IA_NAME_LEN];

    /** 国家 */
    char szCountry[IA_NAME_LEN];

    /** 省 */
    char szProvince[IA_NAME_LEN];

    /** 县市 */
    char szCity[IA_NAME_LEN];

    /** 公司 */
    char szCompany[IA_NAME_LEN];

    /** 邮编 */
    char szZipcode[IA_MAIL_CODE_LEN];

    /** 地址 */
    char szAddress[IA_CONTACT_ADDRESS_LEN];

    /** email地址 */
    char szEmail[IA_EMAI_LEN];

    /** 电话 */
    char szPhone[IA_PHONE_LEN];

    /** 联系人信息 */
    IA_CONTACTINFO_S stContactInfo;

} IA_CLIENTINFO_S;


typedef struct tagIALicenseInfo
{
    long lServiceType;        /** 业务类型 */
    long lServiceValue;       /** 授权规格 */
    long lUsedValue;          /** 已用规格 */
    unsigned long ulCreateTime;       /** License创建日期 */
    unsigned long ulTotalDay;         /** 有效天数IA_LICENSE_NOT_EXPIRE为永久有效，其它值为试用版本License有效天数 */
    unsigned long ulUsedDay;          /** 已使用天数 */
}IA_LICENSE_INFO_S;


#endif /* __LICENSE_STRUCT_DEF_H__ */
