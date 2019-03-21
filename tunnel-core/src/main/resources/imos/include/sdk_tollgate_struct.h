/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              sdk_tollgate_struct.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2011-03-14
        Author: baoyihui/02795
   Description: ����SDK�ṹ����


--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_TOLLGATE_STRUCT_H_
#define _IMOS_SDK_TOLLGATE_STRUCT_H_

#ifdef  __cplusplus
    extern "C"{
#endif

/**
 * @struct tagTMSInfo
 * @brief TMS(��ͨý�彻��������)��Ϣ
 * @attention
 */
typedef struct tagTMSInfo
{
    /** ���� */
    CHAR szTMSCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szTMSName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** TMS���ͣ�Ŀǰ��д0 */
    ULONG_32 ulType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ����ѯ���أ���������¿��Բ��� */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ����, �ݲ�ʹ�ã���� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

} TMS_INFO_S;

/**
 * @struct tagDRInfo
 * @brief DR(��������������)��Ϣ
 * @attention
 */
typedef struct tagDRInfo
{
    /** ���� */
    CHAR szDRCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szDRName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** DRS���ͣ�Ŀǰ��д0 */
    ULONG_32 ulType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ����ѯ���أ���������¿��Բ��� */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ����, �ݲ�ʹ�ã���� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

} DR_INFO_S;


/**
 * @struct tagTollgateInfo
 * @brief ������Ϣ�ṹ
 * @attention
 */
typedef struct tagTollgateInfo
{
    /** ���ڱ�� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���ƣ��ݲ�֧�֣���� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** ����TMS���� */
    CHAR szTMSCode[IMOS_CODE_LEN];

    /** ����TMS���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szTMSName[IMOS_NAME_LEN];

    /** �������ͣ��ο�#TALLGATE_TYPE_E */
    ULONG_32 ulType;

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ������ */
    ULONG_32 ulLaneNum;

    /** ���� */
    CHAR szLongitude[IMOS_COORDINATE_LEN];

    /** γ�� */
    CHAR szLatitude[IMOS_COORDINATE_LEN];

    /** ����ʾ��ͼ(����ftp://�û���:����@192.168.10.1/dispose/abc.jpg)��������ͨ��FTP�ϴ�����������ͨ��IMOS_GetFTPInfoByOper��ȡFTP���� */
    CHAR szPicture[IMOS_FILE_PATH_LEN];

    /** ������������δʹ�ã���� */
    CHAR szDesc[IMOS_DESC_LEN];

    /** �ص���� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** �ص����ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** �ɼ����ر��� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** �ɼ��������� */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[256];
} TOLLGATE_INFO_S;

/**
 * @struct tagTollgateLaneInfo
 * @brief ���ڳ�����Ϣ�ṹ
 * @attention
 */
typedef struct tagTollgateLaneInfo
{
    /** �������ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** ������ */
    ULONG_32 ulLaneNumber;

    /** �������ͣ��ο�#LANE_TYPE_E */
    ULONG_32 ulLaneType;

    /** �����ţ����� */
    ULONG_32 ulDirection;

    /** �������ƣ����� */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** ��ʾ���٣���λKm/h */
    ULONG_32 ulMarkedSpeed;

    /** ִ�����٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** �����Ǳ�־: 0,���漰 1,���� 2,���� */
    ULONG_32 ulIntoCityFlag;

    /** ������ */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ���Ϣ */
    CHAR szReserve[192];
}TOLLGATE_LANE_INFO_S;

/**
 * @struct tagTollgateLaneQueryItem
 * @brief ���ڳ�����ѯ�ṹ
 * @attention
 */
typedef struct tagTollgateLaneQueryItem
{
    /** �������ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �����������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ������ */
    ULONG_32 ulLaneNumber;

    /** �������ͣ��ο�#LANE_TYPE_E */
    ULONG_32 ulLaneType;

    /** �����ţ����� */
    ULONG_32 ulDirection;

    /** �������ƣ����� */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** ��ʾ���٣���λKm/h */
    ULONG_32 ulMarkedSpeed;

    /** ִ�����٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** �����Ǳ�־: 0,���漰 1,���� 2,���� */
    ULONG_32 ulIntoCityFlag;

    /** ץ��������� */
    CHAR szPhotoCameraCode[IMOS_CODE_LEN];

    /** ץ��������� */
    CHAR szPhotoCameraName[IMOS_NAME_LEN];

    /** ȫ����������� */
    CHAR szVideoCameraCode[IMOS_CODE_LEN];

    /** ȫ����������� */
    CHAR szVideoCameraName[IMOS_NAME_LEN];

    /** ������ */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ���Ϣ */
    CHAR szReserve[192];
}TOLLGATE_LANE_QUERY_ITEM_S;

/**
 * @struct tagTrafficLightStatus
 * @brief ���̵�״̬
 * @attention
 */
typedef struct tagTrafficLightStatus
{
    /** ������ */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ����ʱ�� */
    CHAR szSampleTime[IMOS_TIME_LEN];

    /** ���̵�״̬������ʮ����λ�ӵ͵��ߣ����α�ʾ��ֱ�ҵĺ��̵�״̬��ǧλԤ��λ1����/ʮ/�٣�ÿһλ��״̬λ�ο�#TRAFFIC_LIGHT_STATUS_E */
    ULONG_32 ulTrafficLightStatus;

    /** Ԥ���ֶ���Ϣ */
    CHAR szReserve[196];
}TRAFFIC_LIGHT_STATUS_S;

/**
 * @struct tagTollgateCameraInfo
 * @brief ���������Ϣ�ṹ
 * @attention
 */
typedef struct tagTollgateCameraInfo
{
    /** ������� */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** ������� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** ������ͣ��ο�#TALLGATE_CAMERA_TYPE_E */
    ULONG_32 ulCameraType;

    /** ����EC���� */
    CHAR szECCode[IMOS_CODE_LEN];

    /** ����EC���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szECName[IMOS_NAME_LEN];

    /** ����EC���� */
    ULONG_32 ulECType;

    /** ����ECͨ�� */
    ULONG_32 ulECChannel;

    /** �������ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �����������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ץ�ĵĳ��������������һ��������Ӧһ�����������1 */
    ULONG_32 ulTollgateLaneNum;

    /** ץ�ĵĿ��ڳ����б� */
    ULONG_32 aulTollgateLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ���� */
    CHAR  szLongitude[IMOS_COORDINATE_LEN];

    /** γ�� */
    CHAR  szLatitude[IMOS_COORDINATE_LEN];

    /** �������, �ݲ�ʹ�ã���� */
    CHAR  szCameraDesc[IMOS_DESC_LEN];

    /** �ɼ��豸���� */
    CHAR  szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[196];
} TOLLGATE_CAMERA_INFO_S;

/**
 * @struct tagTollgateFlashlightInfo
 * @brief �������Ϣ�ṹ
 * @attention
 */
typedef struct tagTollgateFlashlightInfo
{
    /** ����Ʊ�� */
    CHAR szTollgateFlashlightCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR szTollgateFlashlightName[IMOS_NAME_LEN];

    /** �������ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �����������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ��װʱ�� */
    CHAR szBulidTime[IMOS_TIME_LEN];

    /** ������� */
    ULONG_32 ulFlashCount;

    /** ץ�ĵĳ��������������һ��������Ӧһ�����������д1 */
    ULONG_32 ulTollgateLaneNum;

    /** ץ�ĵĿ��ڳ����б� */
    ULONG_32 aulTollgateLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** Ԥ���ֶ� */
    CHAR szReserve[256];
} TOLLGATE_FLASHLIGHT_INFO_S;

/**
 * @struct tagDispositionDept
 * @brief ��/���ص�λ�ṹ
 * @attention
 */
typedef struct tagDispositionDept
{
    /** ��λ���� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** ��λ���� */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** ��λ���ͣ��ο�#DISPOSITION_DEPT_TYPE_E */
    ULONG_32 ulDeptType;

    /** �������� */
    CHAR szCityName[IMOS_NAME_LEN];

    /** ��ϵ�� */
    CHAR szContactName[IMOS_NAME_LEN];

    /** ��ϵ�绰 */
    CHAR szPhone[IMOS_PHONE_LEN];

    /** ��ϵ�ֻ� */
    CHAR szMobilePhone[IMOS_MOBILE_LEN];

    /** ��λ���� */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;
} DISPOSITION_DEPT_S;

/**
 * @struct tagStatementDispositionUndoInfo
 * @brief ������Ϣ�ṹ
 * @attention
 */
typedef struct tagStatementDispositionUndoInfo
{

    /** ���ص�λ���룬������д */
    CHAR szUndoDept[IMOS_CODE_LEN];

    /** ������Ա���룬������д */
    CHAR szUndoUser[IMOS_CODE_LEN];

    /** ����ʱ�� */
    CHAR szUndoTime[IMOS_TIME_LEN];

    /** ����ԭ�򣬿��Բ���д */
    CHAR szUndoDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[204];

} STATEMENT_DISPOSITION_UNDO_INFO_S;

/**
 * @struct tagStatementDispositionInfo
 * @brief ������Ϣ�ṹ
 * @attention
 */
typedef struct tagStatementDispositionInfo
{
    /** ���ر�ţ�ϵͳ�Զ����� */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** �����������ͣ��ο�#DISPOSITION_INTER_TYPE_E */
    ULONG_32 ulInterType;

    /** �Ƿ�ģ��ƥ�䣬BOOL_TRUE: ģ��ƥ�䣬BOOL_FALSE: ��ȷƥ�� */
    BOOL_T bFuzzyMatch;

    /** ���ƺ��룬������д */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ����Ʒ�ƣ��ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ����Ʒ�� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ������ɫ */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ���ص�λ���룬������д */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ������Ա���룬������д */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** �������ȼ���ȡֵ��ΧΪ1-63��1��ʾ��ߣ�Ĭ��Ϊ2 */
    ULONG_32 ulPriority;

    /** ��������, 0-����;1-������Ŀǰ��֧�ֹ�������1 */
    ULONG_32 ulOpenFlag;

    /** ������𣬲ο������ֵ䣬������д */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** ������Ƭ(����ftp://�û���:����@192.168.10.1/tollgate/abc.jpg)��������ͨ��FTP�ϴ�����������ͨ��IMOS_GetFTPInfoByOper��ȡFTP���� */
    CHAR  szDispositionImage[IMOS_FILE_PATH_LEN];

    /** ��Ӳ��س���������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** ���ؿ�ʼʱ�䣬������д */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** ���ؽ���ʱ�䣬������д */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** ����״̬���ο�#DISPOSITION_STATUS_E����ѯ���أ���οɲ��� */
    ULONG_32 ulStatus;

    /** ������չ״̬���ο�#DISPOSITION_EXT_STATUS_E����ѯ���أ���οɲ��� */
    ULONG_32 ulExtStatus;

    /** �������������Բ��� */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** ���غ�����������Բ��� */
    CHAR  szActionDesc[IMOS_DESC_LEN];

    /** ���Ź������� (֧��256������)*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];

    /** ����� (������ͣ������ר��)*/
    CHAR szDomainCode[IMOS_CODE_LEN];

    /** ���ؼƻ��Ƿ����� */
    ULONG_32 ulDisposePlanStatus;

    /** Ԥ���ֶ� */
    CHAR szReserve[140];

    /** ������Ϣ */
    STATEMENT_DISPOSITION_UNDO_INFO_S stUndoInfo;

    /* �¼ӣ������� */
    CHAR szAuditRemark[IMOS_STRING_LEN_512];

    /* �������ƣ��ɲ��� */
    CHAR szDispositionName[IMOS_NAME_LEN];
} STATEMENT_DISPOSITION_INFO_S;

/*Begin added by a02842 for MPPD46586,2017-4-11*/
/**
 * @struct tagStatementDispositionInfoV2
 * @brief ������Ϣ�ṹ
 * @attention
 */
typedef struct tagStatementDispositionInfoV2
{

    /** ���ر�ţ�ϵͳ�Զ����� */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** �����������ͣ��ο�#DISPOSITION_INTER_TYPE_E */
    ULONG_32 ulInterType;

    /** �Ƿ�ģ��ƥ�䣬BOOL_TRUE: ģ��ƥ�䣬BOOL_FALSE: ��ȷƥ�� */
    BOOL_T bFuzzyMatch;

    /** ���ƺ��룬������д */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ����Ʒ�ƣ��ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ����Ʒ�� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ������ɫ */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ���ص�λ���룬������д */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ������Ա���룬������д */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** �������ȼ���ȡֵ��ΧΪ1-63��1��ʾ��ߣ�Ĭ��Ϊ2 */
    ULONG_32 ulPriority;

    /** ��������, 0-����;1-������Ŀǰ��֧�ֹ�������1 */
    ULONG_32 ulOpenFlag;

    /** ������𣬲ο������ֵ䣬������д */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** ������Ƭ(����ftp://�û���:����@192.168.10.1/tollgate/abc.jpg)��������ͨ��FTP�ϴ�����������ͨ��IMOS_GetFTPInfoByOper��ȡFTP���� */
    CHAR  szDispositionImage[IMOS_FILE_PATH_LEN];

    /** ��Ӳ��س���������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** ���ؿ�ʼʱ�䣬������д */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** ���ؽ���ʱ�䣬������д */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** ����״̬���ο�#DISPOSITION_STATUS_E����ѯ���أ���οɲ��� */
    ULONG_32 ulStatus;

    /** ������չ״̬���ο�#DISPOSITION_EXT_STATUS_E����ѯ���أ���οɲ��� */
    ULONG_32 ulExtStatus;

    /** �������������Բ��� */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** ���غ�����������Բ��� */
    CHAR  szActionDesc[IMOS_DESC_LEN];

    /** ���Ź������� (֧��256������)*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];

    /** ����� (������ͣ������ר��)*/
    CHAR szDomainCode[IMOS_CODE_LEN];

    /** ���ؼƻ��Ƿ����� */
    ULONG_32 ulDisposePlanStatus;
    
    /** Ԥ���ֶ� */
    CHAR szReserve[140];

    /** ������Ϣ */
    STATEMENT_DISPOSITION_UNDO_INFO_S stUndoInfo;
	
    /* �¼ӣ������� */
    CHAR szAuditRemark[IMOS_STRING_LEN_512];

    /* �������ƣ��ɲ��� */
    CHAR szDispositionName[IMOS_NAME_LEN];
    /***********************************����Ȩ������*****************************************/
    /**���ع㲥ģʽ0:�㲥(�ɷ����û��б���Ч)�� 1:�������鲥*/
    ULONG_32 ulBroadcastMode;

    /**�����û�����()*/
    CHAR szAddUsrCode[IMOS_CODE_LEN];

    /**�ɷ����û��б�,��ʱ֧��64 ��31λ
    �û�������ɵ��ַ������ö�������*/
    CHAR szAccessUsrList[IMOS_STRING_LEN_2048];

    /**Ԥ��λ*/
    CHAR szReserve1[8192];
} STATEMENT_DISPOSITION_INFO_V2_S;
/*End added by a02842 for MPPD46586,2017-4-11*/

/**
* @struct tagStatementDispositionDomain
* @brief ��������Ϣ
* @attention
*/
typedef struct tagStatementDispositionDomain
{
    /** ����� */
    CHAR  szDomainCode[IMOS_CODE_LEN];

    /** ������ */
    CHAR  szDomainName[IMOS_NAME_LEN];

    /** ����״̬���ο�#DISPOSITION_STATUS_E */
    ULONG_32 ulStatus;

    /** ���������ο�#DISPOSITION_RESULT_E */
    ULONG_32 ulResult;
} STATEMENT_DISPOSITION_DOMAIN_S;

/**
* @struct tagMapAreaDisposeResInfo
* @brief ��ͼ����������Դ��Ϣ
* @attention
*/
typedef struct tagMapAreaDisposeResInfo
{
    /** ��ͼ����������Դ���� */
    ULONG_32 ulDisposeResNum;

    /** ��ͼ����������Դ�б� */
    RES_INFO_S astDisposeResList[IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM];
} MAP_AREA_DISPOSE_RES_INFO_S;

/**
 * @struct tagDisposePlanBase
 * @brief ���ؼƻ�������Ϣ
 * @attention
 */
typedef struct tagDisposePlanBase
{
    /** ���ؼƻ��������� */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** �ƻ�״̬��BOOL_TRUE:����; BOOL_FALSE:ֹͣ */
    ULONG_32    ulPlanStatus;

    /** �ƻ�����, ȡֵΪ#PLAN_TYPE_E */
    ULONG_32    ulPlanType;

    /** �ƻ�����, �ɲ��� */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}DISPOSE_PLAN_BASE_S;

/**
 * @struct tagDisposePlanInfo
 * @brief ���ؼƻ���Ϣ
 * @attention
 */
typedef struct tagDisposePlanInfo
{
    /** ���ؼƻ�������Ϣ */
    DISPOSE_PLAN_BASE_S stDisposeBaseInfo;

    /** ���ؼƻ�ʱ����Ϣ */
    PLAN_TIME_FOR_RES_S stDisposeTimeInfo;
}DISPOSE_PLAN_INFO_S;

/**
 * @struct tagVehicleBlacklist
 * @brief �������ṹ
 * @attention
 */
typedef struct tagVehicleBlacklist
{
    /** ��������ţ��Զ����� */
    CHAR  szBlacklistCode[IMOS_CODE_LEN];

    /** �Ƿ�ģ��ƥ�䣬BOOL_TRUE: ģ��ƥ�䣬BOOL_FALSE: ��ȷƥ�䣬Ŀǰ��֧�־�ȷƥ�䣬��BOOL_FALSE */
    BOOL_T bFuzzyMatch;

    /** ���ƺ��� */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ¼�벿�ű��룬����Ϊ�� */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ¼���˱��룬����Ϊ�� */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** ��������Դ���ο�BLACKLIST_SRC_E */
    ULONG_32 ulSource;

    /** �������ȼ���ȡֵ��ΧΪ1-63��1��ʾ��ߣ�Ĭ��Ϊ3 */
    ULONG_32 ulPriority;

    /** ������ԭ���ݲ�ʹ�ã���� */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** ��Ӻ�������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** ���ؿ�ʼʱ�䣬����Ϊ�� */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** ���ؽ���ʱ�䣬����Ϊ�� */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** ����˵�������Բ��� */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;
} VEHICLE_BLACKLIST_S;

/**
 * @struct tagDictionaryData
 * @brief �����ֵ�ṹ
 * @attention
 */
typedef struct tagDictionaryData
{

    /** �����ֵ���� */
    CHAR  szDataCode[IMOS_DICTIONARY_KEY_LEN];

    /** �����ֵ����� */
    CHAR  szDataName[IMOS_NAME_LEN];

    /** �Ƿ�ϵͳԤ�����ϵͳԤ���������ɾ�����޸ģ�BOOL_TRUE:ϵͳԤ���壬BOOL_FALSE:��ϵͳԤ���� */
    BOOL_T bPreDefined;

} DICTIONARY_DATA_S;

/**
 * @struct tagDictionaryDatav2
 * @brief �����ֵ�ṹ ֧��42�������ַ�
 * @attention
 */
typedef struct tagDictionaryDatav2
{

    /** �����ֵ���� */
    CHAR  szDataCode[IMOS_DICTIONARY_KEY_LEN];

    /** �����ֵ����� */
    CHAR  szDataName[IMOS_STRING_LEN_128];

    /** �Ƿ�ϵͳԤ�����ϵͳԤ���������ɾ�����޸ģ�BOOL_TRUE:ϵͳԤ���壬BOOL_FALSE:��ϵͳԤ���� */
    BOOL_T bPreDefined;

} DICTIONARY_DATAV2_S;

/**
 * @struct tagStoreResBasicInfo
 * @brief �洢��Դ������Ϣ
 * @attention
 */
typedef struct tagStoreResBasicInfo
{

    /** �洢��Դ���룬�Զ����ɣ�����ʱ��� */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** �洢��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** �豸���� */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** �洢����, ȡֵΪ#AS_DEVCM_STORAGE_TYPE_E */
    ULONG_32  ulStorageType;

    /** �洢�豸���룬�洢����ΪSTORAGE_TYPE_LOCAL(���ش洢)ʱ��� */
    CHAR   szStoreDevCode[IMOS_CODE_LEN];

    /** ��Դ��;, ȡֵΪ#STORAGE_RES_USAGE_E */
    ULONG_32  ulResUsage;

    /** ָ���洢�豸�ռ䲻��ʱ,�Ƿ�֧���Զ�ѡ��洢�豸(BOOL_TRUEΪ֧��; BOOL_FALSEΪ��֧��)��ĿǰΪBOOL_FALSE */
    BOOL_T bAutoSelectStoreDev;

    /** ������������ԣ�ȡֵΪ#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32  ulDiskFullPolicy;

    /** ����洢�ռ䣬��λ:MB */
    ULONG_32  ulStoreCapacity;

    /** ��Դȫ·�����洢����ΪSTORAGE_TYPE_LOCAL(���ش洢)ʱ��Ҫ��д��������� */
    CHAR szResPath[IMOS_FILE_PATH_LEN];

    /** ���½ṹ������ӵ�������Դʱʹ�� */
    /** LUN ID */
    ULONG_32 ulLunId;

    /** Target�� */
    CHAR szTarget[IMOS_STRING_LEN_256];

    /** Initiator�� */
    CHAR szInitiator[IMOS_STRING_LEN_256];

    /** IPSAN�豸��ַ */
    CHAR szDevAddress[IMOS_IPADDR_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

}STORE_RES_BASIC_INFO_S;

/**
 * @struct tagStoreResBasicQueryItem
 * @brief �洢��Դ��ѯ����Item
 * @attention
 */
typedef struct tagStoreResBasicQueryItem
{

    /** �洢��Դ���� */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** �洢��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** �豸���� */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �洢����, �ο�#AS_DEVCM_STORAGE_TYPE_E */
    ULONG_32  ulStorageType;

    /** �洢�豸���� */
    CHAR   szStoreDevCode[IMOS_CODE_LEN];

    /** �洢�豸���� */
    CHAR   szStoreDevName[IMOS_NAME_LEN];

    /** �洢�豸����, �ο�#STORE_DEV_TYPE_E */
    ULONG_32  ulStoreDevType;

    /** �洢�豸������, Ŀǰ�ݲ�ʹ�� */
    ULONG_32  ulStoreDevSubType;

    /** ��Դ��;, ȡֵΪ#STORAGE_RES_USAGE_E */
    ULONG_32  ulResUsage;

    /** ������������ԣ��ο�#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32  ulDiskFullPolicy;

    /** ��Դ״̬���ο�#BAK_RES_STATUS_E */
    ULONG_32 ulResStatus;

    /** ����������λ:MB */
    ULONG_32  ulTotalCapacity;

    /** ʣ����������λ:MB */
    ULONG_32  ulFreeCapacity;

    /** ��Դȫ·�� */
    CHAR  szResPath[IMOS_FILE_PATH_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

}STORE_RES_BASIC_QUERY_ITEM_S;

/**
 * @struct tagGisMapBaseIcon
 * @brief GISͼ�������Ϣ
 * @attention
 */
typedef struct tagGisMapBaseIcon
{

    /** ͼ����룬�Զ����� */
    CHAR szIconCode[IMOS_CODE_LEN];

    /** ��ͼ���� */
    CHAR szGISMapCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR szResCode[IMOS_CODE_LEN];

    /** ͼ�����ͣ��ο�#IMOS_TYPE_E��Ŀǰ��֧��IMOS_TYPE_TOLLGATE */
    ULONG_32 ulIconType;

    /** λ����Ϣ���� */
    CHAR szSiteDesc[IMOS_STRING_LEN_32];

} GIS_MAP_BASE_ICON_S;


/**
 * @struct tagGisMapIcon
 * @brief GISͼ����Ϣ
 * @attention
 */
typedef struct tagGisMapIcon
{
    /** ͼ�������Ϣ */
    GIS_MAP_BASE_ICON_S stBaseIcon;

    /** ��Դ���� */
    CHAR szResName[IMOS_NAME_LEN];

    /** ��Դ���� */
    ULONG_32 ulResType;

    /** ��Դ������ */
    ULONG_32 ulResSubType;

    /** ��Դ״̬ */
    ULONG_32 ulResState;

    /** ��Դ����״̬ */
    ULONG_32 ulResExtState;

    /** �Ƿ����� */
    ULONG_32 ulIsForeign;

    /** �澯���س̶�, ȡֵΪ#ALARM_SEVERITY_LEVEL_E��Ԥ�� */
    ULONG_32 ulCamAlarmLevel;

}GIS_MAP_ICON_S;


/**
* @struct tagQueryVehicleDayStatByType
* @brief ���շֳ�������ͳ��
* @attention
*/
typedef struct tagQueryVehicleDayStatByType
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ������ */
    CHAR szStatDate[IMOS_SIMPLE_DATE_LEN];

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ƽ���ٶ� */
    ULONG_32 ulAvgSpeed;

    /** ��������ͳ�Ƶ����� */
    ULONG_32 aulCountByType[IMOS_MAX_VEHICLE_TYPE_NUM];
} QUERY_VEHICLE_DAY_STAT_BY_TYPE_S;


/**
* @struct tagQueryVehicleDayStatByDir
* @brief ���շֳ�������ͳ��
* @attention
*/
typedef struct tagQueryVehicleDayStatByDir
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ������ */
    CHAR szStatDate[IMOS_SIMPLE_DATE_LEN];

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ƽ���ٶ� */
    ULONG_32 ulAvgSpeed;

    /** ���ݷ���ͳ�Ƶ����� */
    ULONG_32 aulCountByDir[IMOS_MAX_LANE_DIRECTION_NUM];
} QUERY_VEHICLE_DAY_STAT_BY_DIR_S;


/**
* @struct tagQueryVehicleDayStatByLane
* @brief ���շֳ���ͳ��
* @attention
*/
typedef struct tagQueryVehicleDayStatByLane
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ������ */
    CHAR szStatDate[IMOS_SIMPLE_DATE_LEN];

    /** ������ */
    ULONG_32 ulLaneNumber;

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ƽ���ٶ� */
    ULONG_32 ulAvgSpeed;

} QUERY_VEHICLE_DAY_STAT_BY_LANE_S;





/**
* @struct tagQueryVehicleHourStatByType
* @brief ��Сʱ�ֳ�������ͳ��
* @attention
*/
typedef struct tagQueryVehicleHourStatByType
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ��ʱ�� */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ƽ���ٶ� */
    ULONG_32 ulAvgSpeed;

    /** ��������ͳ�Ƶ����� */
    ULONG_32 aulCountByType[IMOS_MAX_VEHICLE_TYPE_NUM];
} QUERY_VEHICLE_HOUR_STAT_BY_TYPE_S;


/**
* @struct tagQueryVehicleHourStatByDir
* @brief ��Сʱ�ֳ�������ͳ��
* @attention
*/
typedef struct tagQueryVehicleHourStatByDir
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ��ʱ�� */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ƽ���ٶ� */
    ULONG_32 ulAvgSpeed;

    /** ���ݷ���ͳ�Ƶ����� */
    ULONG_32 aulCountByDir[IMOS_MAX_LANE_DIRECTION_NUM];
} QUERY_VEHICLE_HOUR_STAT_BY_DIR_S;


/**
* @struct tagQueryVehicleHourStatByLane
* @brief ��Сʱ�ֳ���ͳ��
* @attention
*/
typedef struct tagQueryVehicleHourStatByLane
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ��ʱ�� */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** ������ */
    ULONG_32 ulLaneNumber;

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ƽ���ٶ� */
    ULONG_32 ulAvgSpeed;

} QUERY_VEHICLE_HOUR_STAT_BY_LANE_S;

/**
 * @struct tagTollgateVideoCameraBindInfo
 * @brief �������������Ϣ
 * @attention
 */
typedef struct tagTollgateVideoCameraBindInfo
{
    /** ��������� */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** �������ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** ץ�ĵĿ��ڳ������� */
    ULONG_32 ulPhotoLaneNum;

    /** ץ�ĵĿ��ڳ����б� */
    ULONG_32 aulPhotoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** ��صĿ��ڳ������� */
    ULONG_32 ulVideoLaneNum;

    /** ��صĿ��ڳ����б� */
    ULONG_32 aulVideoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** �ɼ��豸���� */
    CHAR  szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[196];
} TOLLGATE_VIDEO_CAMERA_BIND_INFO_S;

/**
 * @struct tagTollgateVideoCameraQueryItem
 * @brief �����������ѯ��Ϣ
 * @attention
 */
typedef struct tagTollgateVideoCameraQueryItem
{
    /** ȫ����������� */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** ȫ����������� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** ȫ����������ͣ��ο�#CAMERA_TYPE_E */
    ULONG_32 ulCameraType;

    /** �������ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** ������������ */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ץ�ĵĿ��ڳ������� */
    ULONG_32 ulPhotoLaneNum;

    /** ץ�ĵĿ��ڳ����б� */
    ULONG_32 aulPhotoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** ��صĿ��ڳ������� */
    ULONG_32 ulVideoLaneNum;

    /** ��صĿ��ڳ����б� */
    ULONG_32 aulVideoLaneList[IMOS_MAX_CAMERA_LANE_NUM];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ȫ�����������, �ݲ�ʹ�ã���� */
    CHAR  szCameraDesc[IMOS_DESC_LEN];

    /** ��Դ�Ƿ��������� */
    ULONG_32   ulIsForeign;

    /** �ɼ��豸���� */
    CHAR  szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[196];
} TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S;


/**
 * @struct tagVehicleWhitelist
 * @brief �������ṹ
 * @attention
 */
typedef struct tagVehicleWhitelist
{
    /** ��������ţ��Զ����� */
    CHAR  szWhitelistCode[IMOS_CODE_LEN];

    /** ���ƺ��� */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ¼�벿�ű��룬����Ϊ�� */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ¼���˱��룬����Ϊ�� */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** ��Ӱ�������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** ���������� */
    CHAR  szWhiteListDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;
} VEHICLE_WHITELIST_S;

/*added by a02842 for whitelist extension,2017-02-23*/
/**
 * @struct tagVehicleWhitelist
 * @brief �������ṹ
 * @attention
 */
typedef struct tagVehicleWhitelistV2
{
    /** ��������ţ��Զ����� */
    CHAR  szWhitelistCode[IMOS_CODE_LEN];

    /** ���ƺ��� */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ¼�벿�ű��룬����Ϊ�� */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ¼���˱��룬����Ϊ�� */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** ��Ӱ�������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** ���������� */
    CHAR  szWhiteListDesc[IMOS_DESC_LEN];

    /**----------------��������չ���ܲ���------------------*/
    /** �Ƿ�ģ��ƥ�� */
    BOOL_T bFuzzyMatch;

    /** �������Ƿ�Ϊ��ʱ״̬0:����1:��ʱ*/
    BOOL_T bTempStatus;

    /** �������Ƿ����ò�ѯ����0:����������1:��������(tbl_vehicle_whitelist)*/
    BOOL_T bRegionStatus;
    
    /** ������״̬*/
    ULONG_32 ulWhiteListStatus;
	
    /** ���ؿ�ʼʱ�� */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** ���ؽ���ʱ�� */
    CHAR  szEndTime[IMOS_TIME_LEN];    

    /** �澯���ͱ����б����֧��50��Υ�����ͣ�Ϊ�ձ�ʾ������*/
    CHAR  szAlarmTypeCodeList[IMOS_WHITELIST_ALARMTYPE_LEN];

    /*Begin added by h03869, Sep 07, 2017 for MPPD51033*/
    /** ���Ž��պ���*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];
    /*End added by h03869, Sep 07, 2017 for MPPD51033*/
    
    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;
} VEHICLE_WHITELIST_V2_S;

/**
 * @struct tagVehiclePlate
 * @brief �����ṹ
 * @attention
 */
typedef struct tagVehiclePlate
{
    /** ������ţ��Զ����� */
    CHAR  szPlateCode[IMOS_CODE_LEN];

    /** ���ƺ��� */
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ�������� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ¼�벿�ű��룬����Ϊ�� */
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ¼���˱��룬����Ϊ�� */
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** ���������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** �������� */
    CHAR  szPlateDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[256];
} VEHICLE_PLATE_S;

/**
 * @struct tagTollgateLocalRes
 * @brief ���ڱ��ش洢��Դ
 * @attention
 */
typedef struct tagTollgateLocalRes
{
    /** ��Դ·�� */
    CHAR szResPath[IMOS_FILE_PATH_LEN];

    /** �����豸�� */
    CHAR szDiskName[IMOS_FILE_PATH_LEN];
} TOLLGATE_LOCAL_RES_S;

/**
* @struct tagPlateAnalyseResult
* @brief ���Ʒ������
* @attention
*/
typedef struct tagPlateAnalyseResult
{
    /** ������ */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ������ʻ��¼ */
    VEHICLE_DATA_S stVehicleData;

} PLATE_ANALYSE_RESULT_S;

/**
* @struct tagPlateAnalyseInfo
* @brief ���Ʒ�����Ϣ
* @attention
*/
typedef struct tagPlateAnalyseInfo
{
    /** ���Ʒ������ */
    CHAR szPlateAnalyseCode[IMOS_CODE_LEN];

    /** ��ʼʱ�� */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** ���������1 */
    CHAR szTollgateGroupCode1[IMOS_CODE_LEN];

    /** ����������1 */
    CHAR szTollgateGroupName1[IMOS_NAME_LEN];

    /** ���������2 */
    CHAR szTollgateGroupCode2[IMOS_CODE_LEN];

    /** ����������2 */
    CHAR szTollgateGroupName2[IMOS_NAME_LEN];

    /** �Ƿ�������ͬ���Ʋ�ͬ������ɫ,1Ϊ����; 0Ϊ������ */
    ULONG_32 ulDiffVehicleColorEnabled;

    /** �Ƿ�������ͬ���Ʋ�ͬ��������,1Ϊ����; 0Ϊ������ */
    ULONG_32 ulDiffVehicleTypeEnabled;

    /** �Ƿ�������ͬ���Ƽ���ʱ��ͨ����ͬ������,1Ϊ����; 0Ϊ������ */
    ULONG_32 ulCuttyTimeDiffTollgateEnabled;

    /** ͬһ����������������֮�����Сʱ��������λ�� */
    ULONG_32 ulTGTimePeriod;

    /** ����״̬ */
    ULONG_32 ulAnalyseStatus;

    /** Ԥ���ֶ� */
    CHAR  szReserved[32];

} PLATE_ANALYSE_INFO_S;

/**
* @struct tagVehiclePhotoStorSlice
* @brief ����������
* @attention
*/
typedef struct tagVehiclePhotoStorSlice
{
    /** ʱ��� */
    TIME_SLICE_S stSlice;

    /** ���� */
    ULONG_32 ulProportion;
} VEHICLE_PHOTO_STOR_SLICE_S;

/**
* @struct tagTollgateStorCycle
* @brief ���ڴ洢����
* @attention
*/
typedef struct tagTollgateStorCycle
{
    /** ������¼�������� */
    ULONG_32 ulVehicleDataStorDay;

    /** �����澯�������� */
    ULONG_32 ulVehicleAlarmStorDay;

    /** ������¼��ʼ����ٷֱ�0-100 */
    ULONG_32 ulVehicleDataClearPercent;

    /** ������¼ֹͣ����ٷֱ�0-100 */
    ULONG_32 ulVehicleDataStopPercent;

    /** �����澯��ʼ����ٷֱ�0-100 */
    ULONG_32 ulVehicleAlarmClearPercent;

    /** �����澯ֹͣ����ٷֱ�0-100 */
    ULONG_32 ulVehicleAlarmStopPercent;

    /** ���������� */
    ULONG_32 ulPhotoStorSliceNum;

    /** �������б� */
    VEHICLE_PHOTO_STOR_SLICE_S astPhotoStorSliceList[IMOS_MAX_TOLLGATE_PHOTO_STOR_SLICE_NUM];

	/* Begin added by c02845,2016-03-28,������ֱ�� */	
    /** ����ֱ�湲�����ͼƬ������������ 0-100 */
    ULONG_32 ulCDSVehicleCapPercent;

    /** ����ֱ�湲��澯ͼƬ������������ 0-100 */
    ULONG_32 ulCDSAlarmCapPercent;

    /** ����ֱ�������¼��ʼ����ٷֱ�0-100 */
    ULONG_32 ulCDSVehicleDataClearPercent;

    /** ����ֱ�������¼ֹͣ����ٷֱ�0-100 */
    ULONG_32 ulCDSVehicleDataStopPercent;

    /** ����ֱ������澯��ʼ����ٷֱ�0-100 */
    ULONG_32 ulCDSVehicleAlarmClearPercent;

    /** ����ֱ������澯ֹͣ����ٷֱ�0-100 */
    ULONG_32 ulCDSVehicleAlarmStopPercent;
	/* End added by c02845,2016-03-28,������ֱ�� */

    /** ����ֱ�����ͼƬ�������� */
    ULONG_32 ulCDSVehiclePicStorDay;

    /** ����ֱ������澯ͼƬ�������� */
    ULONG_32 ulCDSVehicleAlarmPicStorDay;
} TOLLGATE_STOR_CYCLE_S;

/**
* @struct tagTollgatePhotoLifeCycle
* @brief ����ͼƬ��������
* @attention
*/
typedef struct tagTollgatePhotoLifeCycle
{
    /** �Ƿ����ã�BOOL_TRUE�����ã�BOOL_FALSE�������� */
    ULONG_32 ulEnableStatus;

    /** ��ʼ���� */
    ULONG_32 ulBeginDay;

    /** ��ֹ���� */
    ULONG_32 ulEndDay;

    /** ѹ���ٷֱ�0��100 */
    ULONG_32 ulCompressPercent;

} TOLLGATE_PHOTO_LIFE_CYCLE_S;

/**
* @struct tagTollgatePhotoLifeCycleCfg
* @brief ����ͼƬ������������
* @attention
*/
typedef struct tagTollgatePhotoLifeCycleCfg
{
    /** ����ͼƬ������������ */
    ULONG_32 ulPhotoLifeCycleNum;

    /** ����ͼƬ���������б� */
    TOLLGATE_PHOTO_LIFE_CYCLE_S astPhotoLifeCycleList[IMOS_MAX_TOLLGATE_PHOTO_LIFT_CYCLE_NUM];

} TOLLGATE_PHOTO_LIFE_CYCLE_CFG_S;

/**
* @struct tagDetectionRoadSection
* @brief ��������
* @attention
*/
typedef struct tagDetectionRoadSection
{
    /** ������ */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** ���ڱ�ţ�ʻ�룩 */
    CHAR szInTollgateCode[IMOS_CODE_LEN];

    /** ���ڱ�ţ�ʻ���� */
    CHAR szOutTollgateCode[IMOS_CODE_LEN];

    /** ������룬��λ:�� */
    ULONG_32 ulSectionDistance;

    /** �����٣����٣�����λ��Km/h */
    ULONG_32 ulLargeVehicleUpperSpeed;

    /** �����٣����٣�����λ��Km/h */
    ULONG_32 ulLargeVehicleLowerSpeed;

    /** С�����٣����٣�����λ��Km/h */
    ULONG_32 ulSmallVehicleUpperSpeed;

    /** С�����٣����٣�����λ��Km/h */
    ULONG_32 ulSmallVehicleLowerSpeed;

    /* Begin added by c02845, 2015-11-05, of MPPD31387, �������䳬ʱΥ�� */
    /** �����������ڵ�����ͣ��ʱ�䣬��λ�� */
    ULONG_32 ulSectionTime;
    /* End added by c02845, 2015-11-05, of MPPD31387, �������䳬ʱΥ�� */

    /** �������� */
    CHAR szSectionDesc[IMOS_DESC_LEN];

} DETECTION_ROAD_SECTION_S;

/**
* @struct tagDetectionRoadSectionQueryItem
* @brief ���������ѯItem
* @attention
*/
typedef struct tagDetectionRoadSectionQueryItem
{
    /** ������ */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** ���ڱ�ţ�ʻ�룩 */
    CHAR szInTollgateCode[IMOS_CODE_LEN];

    /** �������ƣ�ʻ�룩 */
    CHAR szInTollgateName[IMOS_NAME_LEN];

    /** ���ڱ�ţ�ʻ���� */
    CHAR szOutTollgateCode[IMOS_CODE_LEN];

    /** �������ƣ�ʻ���� */
    CHAR szOutTollgateName[IMOS_NAME_LEN];

    /** ������룬��λ:�� */
    ULONG_32 ulSectionDistance;

    /** �����٣����٣�����λ��Km/h */
    ULONG_32 ulLargeVehicleUpperSpeed;

    /** �����٣����٣�����λ��Km/h */
    ULONG_32 ulLargeVehicleLowerSpeed;

    /** С�����٣����٣�����λ��Km/h */
    ULONG_32 ulSmallVehicleUpperSpeed;

    /** С�����٣����٣�����λ��Km/h */
    ULONG_32 ulSmallVehicleLowerSpeed;

    /* Begin added by c02845, 2015-11-05, of �������䳬ʱΥ�� */
    /** �����������ڵ�����ͣ��ʱ�䣬��λ�� */
    ULONG_32 ulSectionTime;
    /* End added by  c02845, 2015-10-12 of �������䳬ʱΥ��*/

    /** �������� */
    CHAR szSectionDesc[IMOS_DESC_LEN];

} DETECTION_ROAD_SECTION_QUERY_ITEM_S;

/**
* @struct tagVehicleViolationTypeCount
* @brief �������ͺ������Ķ�Ӧ��ϵ
* @attention
*/
typedef struct tagVehicleViolationTypeCount
{

    /* �������� */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /* ���� */
    ULONG_32 ulCount;

} VEHICLE_VIOLATION_TYPE_COUNT_S;

/**
* @struct tagVehicleViolationStatByType
* @brief ��Υ������ͳ�ƽ��
* @attention
*/
typedef struct tagVehicleViolationStatByType
{

    /** Υ������ */
    CHAR szViolationType[IMOS_DICTIONARY_KEY_LEN];

    /** Υ���������� */
    CHAR szViolationName[IMOS_NAME_LEN];

    /** �ܼ� */
    ULONG_32 ulTotalCount;

    /** ������������ */
    ULONG_32 ulTypeCountNum;

    /** ��ӦΥ�����͵ĸ��ֳ������͵�Υ������ͳ�ƽ�� */
    VEHICLE_VIOLATION_TYPE_COUNT_S astTypeCountList[IMOS_VEHICLE_TYPE_MAX_NUM];

} VEHICLE_VIOLATION_STAT_BY_TYPE_S;

/**
* @struct tagViolationStatByTollgateItem
* @brief ����Υ������ͳ�Ƶ�Υ������
* @attention
*/
typedef struct tagViolationStatByTollgateItem
{
    /** Υ������ */
    CHAR szViolationType[IMOS_DICTIONARY_KEY_LEN];

    /** Υ������ */
    ULONG_32 ulViolationCount;

} VIOLATION_STAT_BY_TOLLGATE_ITEM_S;

/**
* @struct tagVehicleViolationStatByTollgate
* @brief ������ͳ�ƽ��
* @attention
*/
typedef struct tagVehicleViolationStatByTollgate
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** �ܼ� */
    ULONG_32 ulTotalCount;

    /** Υ���������� */
    ULONG_32 ulViolationNum;

    /** ����Υ������ͳ�Ƶ�Υ�������б� */
    VIOLATION_STAT_BY_TOLLGATE_ITEM_S astViolationList[IMOS_VEHICLE_VIOLATION_MAX_NUM];

} VEHICLE_VIOLATION_STAT_BY_TOLLGATE_S;

/**
* @struct tagVehicleViolationStatByDealStatus
* @brief ������״̬ͳ�ƽ��
* @attention
*/
typedef struct tagVehicleViolationStatByDealStatus
{
    /** ����״̬ */
    ULONG_32 ulDealStatus;

    /** Υ������ */
    ULONG_32 ulCount;

    /** �ٷֱȣ�9999��ʾ99.99% */
    ULONG_32 ulPercent;

} VEHICLE_VIOLATION_STAT_BY_DEAL_STATUS_S;

/**
* @struct tagTMSForwardAddrInfo
* @brief TMSת����ַ
* @attention
*/
typedef struct tagTMSForwardAddrInfo
{
    /** ת����ַ��� */
    CHAR  szForwardAddrCode[IMOS_CODE_LEN];

    /** TMS���� */
    CHAR  szTMSCode[IMOS_CODE_LEN];

    /** ת����ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulForwardAddrType;

    /** ת����ַ */
    CHAR  szForwardAddr[IMOS_IPADDR_LEN];

    /** ת���˿� */
    ULONG_32 ulForwardPort;

    /** ��·״̬ */
    ULONG_32 ulLinkStatus;

} TMS_FORWARD_ADDR_INFO_S;

/**
 * @struct tagViolationPlace
 * @brief Υ�µص�
 * @attention
 */
typedef struct tagViolationPlace
{
    /** �ص��� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** �ص����� */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** �������� */
    CHAR szAdminDivision[IMOS_CODE_LEN];

    /** ��·���� */
    CHAR szRoadCode[IMOS_CODE_LEN];

    /** ��·���׮�� */
    CHAR szKilometer[IMOS_MEASUREMENT_LEN];

    /** ���� */
    CHAR szMeter[IMOS_MEASUREMENT_LEN];

    /** �ص����� */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VIOLATION_PLACE_S;

/**
 * @struct tagDevAddr
 * @brief �豸��ַ
 * @attention
 */
typedef struct tagDevAddr
{
    /** ��ַ��� */
    CHAR szDevAddrCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** ��ַ���� */
    ULONG_32 ulAddrType;

    /** ��ַ */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** �˿ں� */
    ULONG_32 ulPort;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} DEV_ADDR_S;

/**
* @struct tagVehicleAbnormalAnalyseInfo
* @brief �쳣��Ϊ������Ϣ
* @attention
*/
typedef struct tagVehicleAbnormalAnalyseInfo
{
    /** �쳣��Ϊ������� */
    CHAR szAbnormalAnalyseCode[IMOS_CODE_LEN];

    /** ��ʼʱ�� */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** ͨ��������ֵ */
    ULONG_32 ulMaxPassCount;

    /** ����״̬����VEHICLE_ABNORMAL_ANALYSE_STATUS_E */
    ULONG_32 ulAnalyseStatus;

    /** ����������VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulOperator;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_ABNORMAL_ANALYSE_INFO_S;

/**
* @struct tagVehicleAbnormalAnalyseResult
* @brief �쳣��Ϊ�������
* @attention
*/
typedef struct tagVehicleAbnormalAnalyseResult
{
    /** ������ */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ���ƺ��� */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͨ������ */
    ULONG_32 ulPassCount;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_ABNORMAL_ANALYSE_RESULT_S;

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/**
* @struct tagVehicleTrackCollisionInfo
* @brief �����켣��ײ��Ϣ
* @attention
*/
typedef struct tagVehicleTrackCollisionInfo
{
    /** ��Դ���� */
    ULONG_32 ulResNum;

    /** ��Դ�б� */
    RES_INFO_S astResList[IMOS_VEHICLE_TRACK_COLLISION_RES_MAX_NUM];

    /** ��ʼʱ�� */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR szEndTime[IMOS_TIME_LEN];
} VEHICLE_TRACK_COLLISION_INFO_S;

/**
* @struct tagVehicleTrackCollisionDetail
* @brief �����켣��ײ��ϸ��Ϣ
* @attention
*/
typedef struct tagVehicleTrackCollisionDetail
{
    /** �����켣��ײ��� */
    CHAR szTrackCollisionCode[IMOS_CODE_LEN];

    /** �����켣��ײ���� */
    CHAR szTrackCollisionName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** �����켣���� */
    ULONG_32 ulVehicleTrackNum;

    /** �����켣��Ϣ */
    VEHICLE_TRACK_COLLISION_INFO_S astVehicleTrackList[IMOS_VEHICLE_TRACK_PLACE_MAX_NUM];

    /** ����״̬����VEHICLE_TRACK_COLLISION_STATUS_E */
    ULONG_32 ulStatus;

    /** ��ע */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_TRACK_COLLISION_DETAIL_S;

/**
* @struct tagVehicleTrackCollisionQueryItem
* @brief �����켣��ײ
* @attention
*/
typedef struct tagVehicleTrackCollisionQueryItem
{
    /** �����켣��ײ��� */
    CHAR szTrackCollisionCode[IMOS_CODE_LEN];

    /** �����켣��ײ���� */
    CHAR szTrackCollisionName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ����״̬����VEHICLE_TRACK_COLLISION_STATUS_E */
    ULONG_32 ulStatus;

    /** ��ע */
    CHAR szDesc[IMOS_DESC_LEN];

    /** �켣��ײ��Сʱ�� */
    CHAR szTrackCollisionMinTime[IMOS_TIME_LEN];

    /** �켣��ײ���ʱ�� */
    CHAR szTrackCollisionMaxTime[IMOS_TIME_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_TRACK_COLLISION_QUERY_ITEM_S;

/**
* @struct tagVehicleTrackCollisionResult
* @brief �����켣��ײ���
* @attention
*/
typedef struct tagVehicleTrackCollisionResult
{
    /** ������� */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ������Ϣ��� */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ��ʻ���򣬲ο������ֵ� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ���� */
    ULONG_32 ulVehicleSpeed;

    /** ͨ������ʱ�� */
    CHAR szPassTime[IMOS_TIME_LEN];

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_TRACK_COLLISION_RESULT_S;

/**
* @struct tagVehicleFirstAppearInfo
* @brief �����״γ�����Ϣ
* @attention
*/
typedef struct tagVehicleFirstAppearInfo
{
    /** �����״γ��ֱ�� */
    CHAR szFirstAppearCode[IMOS_CODE_LEN];

    /** �����״γ������� */
    CHAR szFirstAppearName[IMOS_NAME_LEN];

    /** ��Դ���� */
    ULONG_32 ulResNum;

    /** ��Դ�б� */
    RES_INFO_S astResList[IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM];

    /** ��ʼʱ�� */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** ����״̬����VEHICLE_FIRST_APPEAR_STATUS_E */
    ULONG_32 ulStatus;

    /** ��ע */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_FIRST_APPEAR_INFO_S;

/**
* @struct tagVehicleFirstAppearResult
* @brief �����״γ��ֽ��
* @attention
*/
typedef struct tagVehicleFirstAppearResult
{
    /** ������� */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ������Ϣ��� */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ��ʻ���򣬲ο������ֵ� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ���� */
    ULONG_32 ulVehicleSpeed;

    /** ͨ������ʱ�� */
    CHAR szPassTime[IMOS_TIME_LEN];

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_FIRST_APPEAR_RESULT_S;

/**
* @struct tagVehiclePerilTimeInfo
* @brief ������Σʱ����Ϣ
* @attention
*/
typedef struct tagVehiclePerilTimeInfo
{
    /** ������Σʱ�α�� */
    CHAR szPerilTimeCode[IMOS_CODE_LEN];

    /** ������Σʱ������ */
    CHAR szPerilTimeName[IMOS_NAME_LEN];

    /** ��Դ���� */
    ULONG_32 ulResNum;

    /** ��Դ�б� */
    RES_INFO_S astResList[IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM];

    /** ��ʼ���� YYYY-MM-DD */
    CHAR szBeginDate[IMOS_SIMPLE_DATE_LEN];

    /** �������� YYYY-MM-DD */
    CHAR szEndDate[IMOS_SIMPLE_DATE_LEN];

    /** ��ʼʱ�� hh:mm:ss */
    CHAR szBeginTime[IMOS_SIMPLE_TIME_LEN];

    /** ����ʱ�� hh:mm:ss */
    CHAR szEndTime[IMOS_SIMPLE_TIME_LEN];

    /** ����״̬����VEHICLE_PERIL_TIME_STATUS_E */
    ULONG_32 ulStatus;

    /** ��ע */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_PERIL_TIME_INFO_S;

/**
* @struct tagVehiclePerilTimeResult
* @brief ������Σʱ�ν��
* @attention
*/
typedef struct tagVehiclePerilTimeResult
{
    /** ������� */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ������Ϣ��� */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ��ʻ���򣬲ο������ֵ� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ���� */
    ULONG_32 ulVehicleSpeed;

    /** ͨ������ʱ�� */
    CHAR szPassTime[IMOS_TIME_LEN];

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_PERIL_TIME_RESULT_S;

/**
* @struct tagOnlyIntoCItyInfo
* @brief ������ν��ǲ�������Ϣ
* @attention
*/
typedef struct tagOnlyIntoCItyInfo
{
    /** ������ */
    CHAR szTaskCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** ��ʼʱ�� YYYY-MM-DD HH:mm:ss */
    CHAR szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� YYYY-MM-DD HH:mm:ss */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** ���Ǵ�����ֵ */
    ULONG_32 ulIntoCityCount;

    /** ���Ǵ�����ֵ */
    ULONG_32 ulOutCityCount;

    /** ����״̬����VEHICLE_ABNORMAL_ANALYSE_STATUS_E */
    ULONG_32 ulAnalyseStatus;

    /** ���ǲ���������VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulIntoCityOperator;

    /** ���ǲ���������VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulOutCityOperator;

    /** ��ע */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_ONLY_INTO_CITY_INFO_S;

/**
* @struct tagOnlyIntoCityResult
* @brief ������ν��ǲ����ǽ��
* @attention
*/
typedef struct tagOnlyIntoCityResult
{
    /** ������� */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ������Ϣ��� */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ���Ǵ��� */
    ULONG_32 ulIntoCityCount;

    /** ���Ǵ��� */
    ULONG_32 ulOutCityCount;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_ONLY_INTO_CITY_RESULT_S;

/**
* @struct tagFrequentNightOutInfo
* @brief ����Ƶ��ҹ�������ҹ��������Ϣ
* @attention
*/
typedef struct tagFrequentNightOutInfo
{
    /** ������ */
    CHAR szTaskCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** ��Դ���� */
    ULONG_32 ulResNum;

    /** ��Դ�б� */
    RES_INFO_S astResList[IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM];

    /** ��ʼ���� YYYY-MM-DD */
    CHAR szBeginDate[IMOS_SIMPLE_DATE_LEN];

    /** �������� YYYY-MM-DD */
    CHAR szEndDate[IMOS_SIMPLE_DATE_LEN];

    /** ���쿪ʼʱ�� hh:mm:ss */
    CHAR szDayBeginTime[IMOS_SIMPLE_TIME_LEN];

    /** �������ʱ�� hh:mm:ss */
    CHAR szDayEndTime[IMOS_SIMPLE_TIME_LEN];

    /** ���Ͽ�ʼʱ�� hh:mm:ss */
    CHAR szNightBeginTime[IMOS_SIMPLE_TIME_LEN];

    /** ���Ͻ���ʱ�� hh:mm:ss */
    CHAR szNightEndTime[IMOS_SIMPLE_TIME_LEN];

    /** ����ͨ��������ֵ */
    ULONG_32 ulDayMaxPassCount;

    /** ����ͨ��������ֵ */
    ULONG_32 ulNightMaxPassCount;

    /** ����״̬����VEHICLE_ABNORMAL_ANALYSE_STATUS_E */
    ULONG_32 ulAnalyseStatus;

    /** �������������VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulDayOperator;

    /** ���ϲ���������VEHICLE_ABNORMAL_ANALYSE_OPERATOR_E */
    ULONG_32 ulNightOperator;

    /** ��ע */
    CHAR szDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_FREQUENT_NIGHT_OUT_INFO_S;

/**
* @struct tagFrequentNightOutResult
* @brief ����Ƶ��ҹ�������ҹ�����ý��
* @attention
*/
typedef struct tagFrequentNightOutResult
{
    /** ������� */
    CHAR szResultCode[IMOS_CODE_LEN];

    /** ������Ϣ��� */
    CHAR szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ���ƺ���  */
    CHAR szPlateCode[IMOS_CODE_LEN];

    /** ���쳵�����ִ��� */
    ULONG_32 ulDayPassCount;

    /** ���ϳ������ִ��� */
    ULONG_32 ulNightPassCount;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} VEHICLE_FREQUENT_NIGHT_OUT_RESULT_S;




/* End added by bt00977, 2013-1-25 of MPPD00420 */

/**
 * @struct tagRestrictPlanWeekTime
 * @brief �ܼƻ�
 * @attention
 */
typedef struct tagRestrictPlanWeekTime
{
    /** �ܼ� */
    ULONG_32 ulWeekDay;

    /** ʱ����Ϣ, ���еĿ�ʼʱ��ͽ���ʱ���ʽΪ"hh:mm:ss" */
    TIME_SLICE_S astTimeSlice[IMOS_MAX_TIME_SLICE_NUM];

    /** ������β�������ö��ŷָ�������:1,9 */
    CHAR szParam[IMOS_MAX_PLAN_PARAM_LEN];

}RESTRICT_PLAN_WEEKTIME_S;

/**
 * @struct tagRestrictPlanExtTime
 * @brief ����ʱ����Ϣ, ����������ƻ�ʱ��ʱʹ��. ����ƻ����������ƻ��Ļ��������õ�����ִ�мƻ�
 * @attention
 */
typedef struct tagRestrictPlanExtTime
{
    /** �������� ��ʽΪ"YYYY-MM-DD" */
    CHAR szExtDate[IMOS_SIMPLE_DATE_LEN];

    /** ����ʱ��Ƭ����, ���еĿ�ʼʱ��ͽ���ʱ��ĸ�ʽΪ"hh:mm:ss" */
    TIME_SLICE_S astTimeSlice[IMOS_MAX_TIME_SLICE_NUM];

    /** ������β�������ö��ŷָ�������:1,9 */
    CHAR szParam[IMOS_MAX_PLAN_PARAM_LEN];
}RESTRICT_PLAN_EXTTIME_S;

/**
 * @struct tagRestrictPlanTime
 * @brief �ƻ�ʱ����Ϣ�ṹ
 * @attention
 */
typedef struct tagRestrictPlanTime
{
    /** �ܼƻ� */
    RESTRICT_PLAN_WEEKTIME_S astPlanWeekTime[IMOS_WEEK_DAYS];

    /** ����ʱ������������ʱ���ʵ������, ���ȡֵΪ#IMOS_EXCP_DAYS */
    ULONG_32 ulPlanExtTimeNum;

    /** ����ʱ������ */
    RESTRICT_PLAN_EXTTIME_S astPlanExtTime[IMOS_EXCP_DAYS];

}RESTRICT_PLAN_TIME_S;

/**
 * @struct tagVehicleRestrictBase
 * @brief �������л�������
 * @attention
 */
typedef struct tagVehicleRestrictBase
{
    /** ���б��� */
    CHAR szRestrictCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szRestrictName[IMOS_NAME_LEN];

    /** ���з�ʽ���ο�#VEHICLE_RESTRICT_TYPE_E */
    ULONG_32 ulRestrictType;

    /** �������ͣ��ο������ֵ� */
    CHAR szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʼ���� */
    CHAR szBeginDate[IMOS_SIMPLE_DATE_LEN];

    /** �������� */
    CHAR szEndDate[IMOS_SIMPLE_DATE_LEN];

    /** �ƻ�״̬��BOOL_TRUE:����; BOOL_FALSE:ֹͣ */
    ULONG_32 ulPlanStatus;

    /** �ƻ�����, ȡֵΪ#PLAN_TYPE_E */
    ULONG_32 ulPlanType;

    /** �ƻ�����, �ɲ��� */
    CHAR szRestrictDesc[IMOS_DESC_LEN];

}VEHICLE_RESTRICT_BASE_S;

/**
 * @struct tagVehicleRestrictInfo
 * @brief ��������
 * @attention
 */
typedef struct tagVehicleRestrictInfo
{
    /** �������л������� */
    VEHICLE_RESTRICT_BASE_S stRestrictBase;

    /** ��������ʱ��ƻ� */
    RESTRICT_PLAN_TIME_S stPlanTime;

}VEHICLE_RESTRICT_INFO_S;

/**
 * @struct tagNestQueryCondition
 * @brief Ƕ�ײ�ѯ����
 * @attention
 */
typedef struct tagNestQueryCondition
{
    /** ��ѯ��������: #QUERY_TYPE_E */
    ULONG_32 ulQueryType;

    /** ��ѯ�����߼���ϵ����: ֧��#EQUAL_FLAG */
    ULONG_32 ulLogicFlag;

    /** ��ѯ����ȡֵ���������#IMOS_QUERY_ITEM_MAX_NUM2 */
    ULONG_32 ulQueryDataNum;

    /** ��ѯ����ȡֵ�б� */
    CHAR aszQueryDataList[IMOS_QUERY_ITEM_MAX_NUM2][IMOS_QUERY_DATA_MAX_LEN];

} NEST_QUERY_CONDITION_S;

/**
* @struct tagVehicleCharacterPic
* @brief ��������ͼƬ
* @attention
*/
typedef struct tagVehicleCharacterPic
{
    /** ������Ϣ��� */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** ���Ʋ�ɫ����ͼƬ */
    CHAR szPlatePic[IMOS_URL_LEN];

    /** ���ƶ�ֵ������ͼƬ */
    CHAR szBinaryPlatePic[IMOS_URL_LEN];

    /** ��ʻ������ͼƬ */
    CHAR szDriveCabPic[IMOS_URL_LEN];

    /** ����ʻ������ͼƬ */
    CHAR szAssistDriveCabPic[IMOS_URL_LEN];

    /** ��������ͼƬ */
    CHAR szVehicleLogoPic[IMOS_URL_LEN];

    /** ����¼���ַ */
    CHAR szRelateVideoAddr[IMOS_URL_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[512];
}VEHICLE_CHARACTER_PIC_S;

/**
* @struct tagDetectionRoadSectionVioConf
* @brief �������䳬�ٰٷֱ�����
* @attention
*/
typedef struct tagDetectionRoadSectionVioConf
{
    /** ���ٰٷֱ����ޣ�ȡֵ��Χ[0,999] */
    ULONG_32 ulLowerSpeedPercent;

    /** ���ٰٷֱ����ޣ�ȡֵ��Χ[0,999]���������ulLowerSpeedPercent */
    ULONG_32 ulUpperSpeedPercent;

    /** Υ������,�ο������ֵ� */
    CHAR szViolationType[IMOS_DICTIONARY_KEY_LEN];
	
	/** �������� */
    CHAR szVehicleType2[IMOS_DICTIONARY_KEY_LEN];

}DETECTION_ROAD_SECTION_VIO_CONF_S;

/**
* @struct tagVehicleRealTimeStatBaseInfo
* @brief ������ͳ�ƻ�����Ϣ
* @attention
*/
typedef struct tagVehicleRealTimeStatBaseInfo
{
    /** ���ڱ��� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];

    /** ͳ��ʱ�� */
    CHAR szStatTime[IMOS_TIME_LEN];

    /** ������ */
    ULONG_32 ulTotalCount;

    /** ��ƽ���ٶ� */
    ULONG_32 ulTotalAvgSpeed;
}VEHICLE_REAL_TIME_STAT_BASE_INFO_S;

/**
 * @struct tagVehicleRealTimeStatDirInfo
 * @brief ������ͳ����ʻ������Ϣ
 * @attention
 */
typedef struct tagVehicleRealTimeStatDirInfo
{
    /** ������ */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** �������� */
    CHAR szDirName[IMOS_NAME_LEN];

    /** ����ʻ�������� */
    ULONG_32 ulDirCount;

    /** ����ʻ�������� */
    ULONG_32 ulDirAvgSpeed;
}VEHICLE_REAL_TIME_STAT_DIR_INFO_S;

/**
* @struct tagVehicleRealTimeStatByDir
* @brief ����������ʻ����ͳ��
* @attention
*/
typedef struct tagVehicleRealTimeStatByDir
{
    /** ������ͳ�ƻ�����Ϣ */
    VEHICLE_REAL_TIME_STAT_BASE_INFO_S stStatBaseInfo;

    /** ͳ����ʻ�������� */
    ULONG_32 ulStatDirNum;

    /** ������ʻ����ͳ�Ƶ�������Ϣ */
    VEHICLE_REAL_TIME_STAT_DIR_INFO_S astStatDirList[IMOS_MAX_LANE_DIRECTION_NUM];
}VEHICLE_REAL_TIME_STAT_BY_DIR_S;

/**
* @struct tagTMSMultiAddrForwardRule
* @brief TMS���ַת������
* @attention
*/
typedef struct tagTMSMultiAddrForwardRule
{
    /** ת�������� */
    CHAR szForwardRuleCode[IMOS_CODE_LEN];

    /** ת���������� */
    CHAR szForwardRuleName[IMOS_NAME_LEN];

    /** ת�����ͣ�0-���� 1-����/������ */
    ULONG_32 ulForwardType;

    /** ת��ģʽ��#�ο�TMS_FORWARD_MODE_E */
    ULONG_32 ulForwardMod;

    /** ת����ַ���ͣ�1-IPV4 2-IPV6 16-DNS */
    ULONG_32 ulForwardAddrType;

    /** ת����ַ */
    CHAR szForwardAddr[IMOS_IPADDR_LEN];

    /** ת���˿� */
    ULONG_32 ulForwardPort;

    /** ת��״̬ */
    ULONG_32 ulStatus;

    /** Ԥ���ֶ� */
    CHAR szReserve[124];
}TMS_MULTI_ADDR_FORWARD_RULE_S;

/**
* @struct tagTMSMultiAddrForwardInfo
* @brief TMS���ַת��
* @attention
*/
typedef struct tagTMSMultiAddrForwardInfo
{
    /** TMSת������ */
    TMS_MULTI_ADDR_FORWARD_RULE_S stTmsMultiForwardRule;

    /** ת����Դ���� */
    ULONG_32 ulResNum;

    /** ת����Դ�б� */
    RES_INFO_S astResList[IMOS_TMS_MULTI_FORWARD_RES_MAX_NUM];
}TMS_MULTI_ADDR_FORWARD_INFO_S;


/**
* @struct tagTollgateGroupInfo
* @brief ����������
* @attention
*/
typedef struct tagTollgateGroupInfo
{
     /** ��������*/
    CHAR szTollgateGroupCode[IMOS_CODE_LEN];

    /** ���������� */
    CHAR szTollgateGroupName[IMOS_NAME_LEN];

    /** �������� */
    ULONG_32 ulResNum;

    /** �����б� */
    RES_INFO_S astResList[IMOS_TMS_MULTI_FORWARD_RES_MAX_NUM];

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
}TOLLGATE_GROUP_INFO_S;



/**
* @struct tagViolationCombineConf
* @brief �ϳ�Υ��ͼƬ���ӵ����ýṹ
* @attention ��
*/
typedef struct tagViolationCombineConf
{
    /** Υ��ͼƬ�ϳ�ʹ�� */
    ULONG_32 ulCombineEnable;

    /** ���ӳ��ƺ��� */
    ULONG_32 ulHasPlateCode;

    /** ���ӳ�����ɫ */
    ULONG_32 ulHasPlateColor;

    /** ���Ӻ��ʱ�� */
    ULONG_32 ulHasRedLightTime;

    /** �����ٶ� */
    ULONG_32 ulHasSpeed;

    /** ����ץ�ĵص� */
    ULONG_32 ulHasTollgateName;

    /** �������� */
    ULONG_32 ulHasLimitedSpeed;

    /** ����ץ��ʱ�� */
    ULONG_32 ulHasPassTime;

    /** ���ӳ������� */
    ULONG_32 ulHasVehicleType;

    /** ����Υ������ */
    ULONG_32 ulHasViolationType;

    /** ���ӳ���Ʒ�� */
    ULONG_32 ulHasVehicleLogo;

    /** ���ӳ�����ɫ */
    ULONG_32 ulHasVehicleColor;

    /** ���ӳ����� */
    ULONG_32 ulHasLaneNumber;

    /** ���������� */
    ULONG_32 ulHasCameraCode;

    /** ����������� */
    ULONG_32 ulHasCameraName;

    /** ���ӷ��� */
    ULONG_32 ulHasDirection;

    /** ���ӷ�α�� */
    ULONG_32 ulHasEncrypt;

    /** ð�ŷָBOOL_TRUE:ð�ŷָBOOL_FALSE:�ո� */
    ULONG_32 ulHasColon;

    /* OSDλ����Ϣ���ο�#OSD_PLACE_MODE */
    ULONG_32 ulOSDPlaceMode;

    /** ���ٰٷֱ� */
    ULONG_32 ulHasSpeedPercent;

    /** ���������С */
    ULONG_32 ulFontVectorSize;

    /** �Ƿ�ʱ����ʾ���� */
    ULONG_32 ulHasMillisecond;

    /** ����Υ������ */
    ULONG_32 ulHasViolationCode; /* Added by l01773, 2014-12-11 of MPPD20183*/

    /** �������� */
    ULONG_32 ulHasP2PName;  /* Added by y01693 for mppd21982 20150128 */

    /** ������� */
    ULONG_32 ulHasP2PDistance;

    /** ʻ����ص����� */
    ULONG_32 ulHasTollgateName2;

    /** ʻ�����ʱ�� */
    ULONG_32 ulHasPassTime2;

    /** ��ʻʱ�� */
    ULONG_32 ulHasTravelTimes;

    /** ʻ�������� */
    ULONG_32 ulHasCameraCode2;

    /** ʻ��������� */
    ULONG_32 ulHasCameraName2;

    /** �������ͣ��ο�#TMS_COMBINE_TYPE_E */
    ULONG_32 ulHasDateType;

    /** Ԥ���ֶ� */
    CHAR szReserve[80];
}VIOLATION_COMBINE_CONF_S;

/* Start added by lKF0174, 2013-11-18 of MPPD06792 */
/**
* @struct tagVehicleTransFlag
* @brief �޸Ĺ���/Υ���ϴ���־λ�ṹ
* @attention ��
*/
typedef struct tagVehicleTransFlag
{
    /** ������Ϣ��� */
    CHAR  szDataCode[IMOS_CODE_LEN];

    /** �������� 0��ʾ�������ݣ�1��ʾΥ������*/
    ULONG_32 ulType;

    /** ͨ��ʱ�� */
    CHAR  szPassTime[IMOS_TIME_LEN];

/* Start added by xW1251, 2014-11-19 for Υ��¼���ֶ������Ż�*/
    /** �澯ʱ�� */
    CHAR  szAlarmTime[IMOS_TIME_LEN];

    /** ���ڱ��� ,����32*/
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** ������� */
    ULONG_32 ulLaneIndex;

   /** ͼƬ1����*/
   CHAR szPic1Name[IMOS_URL_LEN];

/* End modified by xW1251, 2014-11-10 for Υ��¼���ֶ������Ż�*/

    /** �Ƿ��ϴ� �ο�#VEHICLE_TRANS_FLAG_VALUE_E*/
    ULONG_32 ulTransFlag;

    /** �����ʶ����λ���ο�#VEHICLE_TRANS_FLAG_BIT_E */
    ULONG_32 ulTransFlagBit;

    /** Ԥ���ֶ� */
    CHAR szReserve[256];
}VEHICLE_TRANS_FLAG_S;
/* End added by lKF0174, 2013-11-18 of MPPD06792 */

/* Begin Added by shendongchun 00400 2014-02-26 for �����ݷ��������� */
/**
 * @struct tagDBInfo
 * @brief DB(���ݴ洢������)��Ϣ
 * @attention
 */
typedef struct tagDBInfo
{
    /** ���� */
    CHAR szDBCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szDBName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** DBS���ͣ�0-DB8500��1-DB9500 */
    ULONG_32 ulType;

  /** DBS�����ͣ�DB9500_TYPE_E����ѯʱ���أ������������Ҫ��д */
    ULONG_32 ulSubType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ����ѯ���أ���������¿��Բ��� */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ����, �ݲ�ʹ�ã���� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

} DB_INFO_S;

/* End Added by shendongchun 00400 2014-02-26 for �����ݷ��������� */

/**
 * @struct tagIAHRInfo
 * @brief IAHR(�����������ڷ�����)��Ϣ
 * @attention
 */
typedef struct tagIAHRInfo
{
    /** ���� */
    CHAR szIAHRCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szIAHRName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** IAHR�����ͣ�Ŀǰδʹ�ã�Ĭ��Ϊ0 */
    ULONG_32 ulType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ����ѯ���أ���������¿��Բ��� */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ����, �ݲ�ʹ�ã���� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

} IAHR_INFO_S;

/**
* @struct tagElecPoliceBindInfo
* @brief �羯����Ϣ
* @attention ��Դ�б����֧��200��
*/
typedef struct tagElecPoliceBindInfo
{
    /** �羯���� */
    CHAR szElecPoliceCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    ULONG_32 ulResNum;

    /** ��Դ�б� */
    RES_INFO_S astResList[IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM];
} ELEC_POLICE_BIND_INFO_S;

/**
* ������TMS�İ󶨹�ϵ
*
*/
typedef struct tagTollgateTmsBindInfo
{
    /** TMS����(��ʱʹ�ã����ʱ��ʹ��)*/
    CHAR        szTMSCode[IMOS_CODE_LEN];

    /** ��Դ��Ŀ*/
    ULONG_32    ulResNum;

    /** ��Դ�б�(���ΪIMOS_MAX_DEAL_NUM_ONE_TIME)*/
    RES_INFO_S  astResList[IMOS_MAX_DEAL_NUM_ONE_TIME];
}TOLLGATE_TMS_BIND_INFO_S;

/* Begin added by c02845,2016-05-12,��ͨ����Ϣ���� */

/**
 * @struct tagTrafficFlowQueryCondition
 * @brief ��ѯ����(���ֳ���)
 * @attention ���ա��¡���ȷ�ʽ.������,�򷵻ص���24Сʱ�ڸ���Сʱ��24��ͳ�����ݣ�����\��Ҳ����
 */
typedef struct tagTrafficFlowQueryCondition
{
    /** ��ѯʱ�䷽ʽ: #TRAFFIC_QUERY_TIME_E, ���ա��¡���ȷ�ʽ*/
    ULONG_32 ulTrafficQueryTime;

    /** ��ѯʱ��㣬��ʽΪ:YYYY_MM_DD����ʽ */
    CHAR szDayTime[IMOS_SIMPLE_DATE_LEN];

    /* �������� */
    ULONG_32 ulTGDevNum;

    /* �����豸���� */
    CHAR szTGDevCode[IMOS_TRAFFIC_FLOW_TOLLGATE_MAX_NUM][IMOS_CODE_LEN];
    
}TRAFFICFLOW_QUERY_CONDITION_S;

/**
* @struct tagTrafficFlowResInfo
* @brief ��Դ��Ϣ
* @attention ��
*/
typedef struct tagTrafficFlowResList
{
    /** ��ԴID���ַ���"0"��ʾϵͳ */
    CHAR    szResIdCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR    szResCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR    szResName[IMOS_NAME_LEN];

    /** ��Դ���ͣ�ȡֵ��ΧΪ#IMOS_TYPE_E */
    ULONG_32   ulResType;

    /** ��Դ������,Ŀǰ��Դ������ֻ�������/��֯/����ʾ/����Ѳ��Ч�������������Ϊ��̨/����̨;
        ����֯����Ϊ:1-��������2-�����������3-�����������. 4-�ϼ���������.
        5-�¼���������.6-ƽ����������.
        ������ʾ��Դ��������ʾ���ͣ�ȡֵΪ#SALVO_TYPE_E
        ������Ѳ��Դ��������Ѳ���ͣ�ȡֵΪ#GROUP_SWITCH_TYPE_E */
    ULONG_32   ulResSubType;

    /** ������֯���� */
    CHAR        szOrgCode[IMOS_CODE_LEN];

    /** ������֯���� */
    CHAR        szOrgName[IMOS_NAME_LEN];

} TRAFFICFLOW_RES_INFO_S;

/**
 * @struct tagTrafficFlowQueryCondition
 * @brief �ֳ�����ѯ����
 * @attention  ��Сʱ��ѯ,��ѯ�Ľ���Ǵ�szBeginDayTime~szEndDayTime���������
 * @attention ÿ���szBeginHourTime~szBeginHourTimeʱ����ڳ�������Ϣ��ƽ��ֵͳ�ƽ��
 */
typedef struct tagTrafficFlowHourQueryCondition
{
    /** ��ʼ��ѯ����,��ʽΪ:YYYY-MM-DD����ʽ */
    CHAR szBeginDayTime[IMOS_SIMPLE_DATE_LEN];

    /** ��ֹ��ѯ����,��ʽΪ:YYYY-MM-DD����ʽ */
    CHAR szEndDayTime[IMOS_SIMPLE_DATE_LEN];

    /** ��ʼ��ѯʱ��,��ʽΪ:HH:MM:SS����ʽ */
    CHAR szBeginHourTime[IMOS_SIMPLE_DATE_LEN];

    /** ��ֹ��ѯʱ��,��ʽΪ:HH:MM:SS����ʽ */
    CHAR szEndHourTime[IMOS_SIMPLE_DATE_LEN];

    /* ��ѯ��֯���� */
    ULONG_32 ulResNum;
    
    /* ��֯���� */
    TRAFFICFLOW_RES_INFO_S astTrafficFlowResLaneList[IMOS_TRAFFIC_FLOW_TOLLGATE_MAX_NUM];

 }TRAFFICFLOW_QUERY_CONDITION_LANE_S;


/**
* @struct tagTrafficFlowQueryItem
* @brief ��ͨ����Ϣ��ѯ��Ϣ
* @attention ���ա��¡����ѯ�Ľӿڣ����ֳ�����,ֻ���ݿ��ڱ����ѯ������
*/
typedef struct tagTrafficFlowQueryInfo
{
    /* ��ѯ���ʱ��,ע:��������ѯ���򷵻ظ�ʽ:YYYY-MM, */
    /* ���²�ѯ�򷵻ظ�ʽ:YYYY-MM-DD, ���ղ�ѯ,YYYY-MM-DD HH:00:00 */
    CHAR szQueryTime[IMOS_TIME_LEN];
    
    /** ��������,��λ:�� */
    ULONG_32 ulVehicleNum;

    /** �����Ŷӳ���,��λ:�� */
    ULONG_32 ulQueueLength;

    /** ƽ������,��λ��Km/h */
    ULONG_32 ulVehicleAverageSpeed;

}TRAFFIC_FLOW_QUERY_INFO_S;

/**
 * @struct tagVehicleAtrributionList
 * @brief ��ͨ����Ϣ��ѯ�б�
 * @attention  IMOS_TRAFFIC_FLOW_LIST_MAX_NUM����Ϊ32,
 * @attention  ʵ���У����ղ�ѯ�򷵻�24Сʱ����Ϣ����24����ѯ�����,�����򷵻�ÿ�¸�����������Ϣ ...
 */
typedef struct tagTrafficFlowQueryList
{
    /* ��ѯ������� */
    ULONG_32 ulResultNum;

    /* ��ѯ����б�ÿ��ʱ���һ�������磺���ղ�ѯ������24��;���²�ѯ������28~31������;���꣬����12�� */
    TRAFFIC_FLOW_QUERY_INFO_S astTrafficFlowList[IMOS_TRAFFIC_FLOW_LIST_MAX_NUM];
}TRAFFIC_FLOW_QUERY_LIST_S;


/**
* @struct tagTrafficFlowQueryItem
* @brief ��ͨ����Ϣ��Сʱ��ѯ������ÿ�������ľ��峵������Ϣ
* @attention
*/
typedef struct tagTrafficFlowQueryLane
{  
    /** ���ڱ�� */
    CHAR szTollgateCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szTollgateName[IMOS_NAME_LEN];
    
    /* ������� */
    ULONG_32 ulLaneID;

    /* ��������,�뷽���Ŷ�Ӧ,����ƽ̨���ø�ֵ */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /* ��ѯ���������,��ʽΪYYYY-MM-DD HH:MM:SS */
    CHAR szData[IMOS_TIME_LEN];

    /** ��������,��λ:�� */
    DULONG ulVehicleNum;

    /** �����Ŷӳ���,��λ:�� */
    ULONG_32 ulQueueLength;

    /** ƽ������,��λ��Km/h */
    ULONG_32 ulVehicleAverageSpeed;

} TRAFFIC_FLOW_QUERY_LANE_INFO_S;

/**
 * @struct tagVehicleAtrributionList
 * @brief ��ͨ����Ϣ��ѯ�б�
 * @attention  IMOS_TRAFFIC_FLOW_LANE_MAX_NUM ����Ϊ�(4*8*7),��:4�����ڣ�ÿ���������8������,��ѯ�������7��;
 * @attention  ʵ���У����ز�ѯ�����ڣ�ÿ�����������ÿ����������Ϣ
 */
typedef struct tagTrafficFlowQueryLaneList
{
    /* ��ѯ������� */
    ULONG_32 ulResultNum;

    /* ��ѯ����б�ÿ������һ�� */
    TRAFFIC_FLOW_QUERY_LANE_INFO_S astTrafficFlowlaneList[IMOS_TRAFFIC_FLOW_LANE_MAX_NUM];
}TRAFFIC_FLOW_QUERY_LANE_LIST_S;


/* End added by c02845,2016-05-12,��ͨ������*/

/*Begin added by a02842 for ����������ͳ��,2016-06-24*/
/**
* @struct tagVehicleStatInfoHbase
* @brief ������ͳ��SDK�ӿ�
*/
typedef struct tagTrafficStatInfoHbase
{
    /** ��ʼʱ��*/
    CHAR        szStartTime[IMOS_TIME_LEN];

    /** ����ʱ��*/
    CHAR        szEndTime[IMOS_TIME_LEN];

    /**��ѯ����1---����֯ͳ�ơ�2---������ͳ��*/
    ULONG_32 ulQueryType;

    /**ͳ������1---������2---Υ��*/
    ULONG_32 ulStatType;

    /**�������ͣ�ȡֵΪ�������Ͷ�Ӧ�ĺ�����*/
    ULONG_32 ulReportType;

    /**ͳ��������,ֵ�ο�tbl_dic_type*/
    ULONG_32 ulSubType;

    /**ͳ������1---��ʱ��ͳ�ơ�2---���ص㿨��ͳ��,3---��������ͳ��*/
    ULONG_32  ulGroupType;

    /** ͳ������ο���0:ʱ��򿨿�,1:ͳ��ֵ*/
    ULONG_32   ulOrderItem;
    
    /** ͳ����������0:asc����,1:desc����*/
    ULONG_32   ulOrderType;
}TRAFFIC_STAT_INFO_HBASE_S;

/**
* @struct tagTrafficStatDicInfo
* @brief ����ͳ�ƽ��
*/
typedef struct tagTrafficStatDicCountResult
{
    /** ͳ�������ֵ����*/
    CHAR          szDicCode[IMOS_DICTIONARY_KEY_LEN];

    /** ͳ������*/
    ULONG_32    ulCount;        
}TRAFFIC_STAT_DIC_COUNT_RESULT;

/**
* @struct tagVehicleStatInfoHbase
* @brief ������ͳ��SDK�ӿ�
*/
typedef struct tagTrafficStatResultHbase
{
    /**ͳ������1---������2---Υ��*/
    ULONG_32 ulStatType;
    
    /**ͳ������1---��ʱ��ͳ�ơ�2---���ص㿨��ͳ�ƣ�,3---��������ͳ��*/
    ULONG_32  ulGroupType;

    /**��ʱ��ͳ��:ͳ��ʱ��*/
    CHAR        szStatTime[IMOS_TIME_LEN];

    /**������ͳ��:ͳ�ƿ���*/
    CHAR        szStatTollgate[IMOS_CODE_LEN];

    /**��������ͳ��:ͳ��������,ulGroupType = 3ʱ������ͳ�������ͽ���б�*/
    CHAR        szDicCode[IMOS_DICTIONARY_KEY_LEN];
        
    /** �ܼ� */
    ULONG_32 ulTotalCount;

    /** ͳ��������*/
    ULONG_32    ulSubType;

    /** ͳ�������ͷ�������*/
    ULONG_32    ulDicCountNum;
    
    /** ͳ�������ͽ���б�*/
    TRAFFIC_STAT_DIC_COUNT_RESULT astDicCount[IMOS_DIC_CODE_MAX_NUM];
}TRAFFIC_STAT_RESULT_HBASE_S;
/*End added by a02842 for ����������ͳ��,2016-06-24*/

/*Begin added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/
/**
 * @struct tagMacRfidDispositionUndoInfo
 * @brief MAC&RFID������Ϣ�ṹ
 * @attention
 */
typedef struct tagMacRfidDispositionUndoInfo
{

    /** ���ص�λ����*/
    CHAR szUndoDept[IMOS_CODE_LEN];

    /** ������Ա����*/
    CHAR szUndoUser[IMOS_CODE_LEN];

    /** ����ʱ�� */
    CHAR szUndoTime[IMOS_TIME_LEN];

    /** ����ԭ�򣬿��Բ���д */
    CHAR szUndoDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[204];

} MACRFID_DISPOSITION_UNDO_INFO_S;

/**
 * @struct tagMacRfidDispositionInfo
 * @brief MAC&RFID������Ϣ�ṹ
 * @attention
 */
typedef struct tagMacRfidDispositionInfo
{

    /** ���ر�ţ�ϵͳ�Զ����� */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** ������𣬲ο�#DISPOSITION_TYPE_E����α��� */
    ULONG_32 ulDispositionType;

    /** RFID�豸�ţ�������д */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /**  ���ص�MAC��ַ��������д */
    CHAR szMacAddr[IMOS_CODE_LEN];

    /** ���ƺ��룬���Բ���*/
    CHAR  szLicensePlate[IMOS_CODE_LEN];

    /**������֯�����Բ���*/
    CHAR szOrganization[IMOS_CODE_LEN];

    /** ������ɫ���ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ������ɫ */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ����Ʒ�ƣ��ο������ֵ䣬���Բ��Ĭ��Ϊ�գ���ʾ����Ʒ�� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������������Բ��Ĭ��Ϊ��*/
    CHAR  szDriverName[IMOS_NAME_LEN];

    /** �������֤���룬���Բ��Ĭ��Ϊ��*/
    CHAR  szDriverID[IMOS_CODE_LEN];

    /** ������ϵ�绰�����Բ��Ĭ��Ϊ��*/
    CHAR  szDriverPhoneNum[IMOS_CODE_LEN];

    /** ���ص�λ���룬���Բ���*/
    CHAR  szDispositionDept[IMOS_CODE_LEN];

    /** ������Ա���룬���Բ���*/
    CHAR  szDispositionUser[IMOS_CODE_LEN];

    /** RFID����ԭ�򣬲ο������ֵ䣬������д */
    CHAR  szRfidDispositionReason[IMOS_DICTIONARY_KEY_LEN];

    /** MAC����ԭ�򣬲ο������ֵ䣬������д */
    CHAR  szMacDispositionReason[IMOS_DICTIONARY_KEY_LEN];

    /** ��Ӳ��س���������ʱ�̣���ѯ���أ���οɲ��� */
    CHAR  szAddTime[IMOS_TIME_LEN];

    /** ���ؿ�ʼʱ�䣬������д */
    CHAR  szBeginTime[IMOS_TIME_LEN];

    /** ���ؽ���ʱ�䣬������д */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** ����״̬���ο�#DISPOSITION_STATUS_E����ѯ���أ���οɲ��� */
    ULONG_32 ulStatus;

    /** �������������Բ��� */
    CHAR  szCaseDesc[IMOS_DESC_LEN];

    /** ���Ź������� (֧��256������)*/
    CHAR szSmsMobile[IMOS_SMS_LEN_3072];

    /** ������Ƭ(����ftp://�û���:����@192.168.10.1/tollgate/abc.jpg)��������ͨ��FTP�ϴ�����������ͨ��IMOS_GetFTPInfoByOper��ȡFTP���� */
    CHAR  szDispositionImage[IMOS_FILE_PATH_LEN];

    /** ������Ϣ */
    MACRFID_DISPOSITION_UNDO_INFO_S stUndoInfo;

    /** ��չ1*/
    CHAR szExpend1[IMOS_CODE_LEN];

    /** ��չ2*/
    CHAR szExpend2[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR szVehicleType[IMOS_CODE_LEN];
    
    /** ��������������ͣ�֧�ְ�������ݲ���*/
    CHAR szIdentifyType[IMOS_CODE_LEN];

    /** ����������ݱ��룬֧�ְ�������ݲ���*/
    CHAR szIdentifyCode[IMOS_CODE_LEN];

} MACRFID_DISPOSITION_INFO_S;

/**
 * RFID��Ϣ�ṹ
 */
typedef struct tagRfidAlarmInfo
{
     /* �澯ID��Ψһ */
     CHAR szAlarmId[IMOS_CODE_LEN];

     /* �澯ʱ�� */
     CHAR szAlarmTime[IMOS_TIME_LEN];

     /* �澯ԭ��*/
     CHAR  szAlarmReason[IMOS_DICTIONARY_KEY_LEN];

     /* ��¼ID �ǿ� */
    CHAR szRecordID[IMOS_CODE_LEN];
       
    /** �ɼ��豸��� */
    CHAR szDevID[IMOS_STRING_LEN_32];
    
    /**���ڱ��*/
    CHAR szTollgateID[IMOS_STRING_LEN_32];

    /* ���� */
    CHAR szLongitude[IMOS_COORDINATE_LEN];
    
    /* γ�� */ 
    CHAR szLatitude[IMOS_COORDINATE_LEN];
    
    /**��ǩ����*/
    CHAR szRfidName[IMOS_CODE_LEN];

        /**��ǩID*/
    CHAR szLabelID[IMOS_STRING_LEN_16];
    
    /**�ر���ID*/
    CHAR szLandMarkID[IMOS_STRING_LEN_16];
    
    /**���ɼ��豸״̬*/
    CHAR szDevStatus[IMOS_STRING_LEN_16];

    /**״̬*/
    CHAR szStatus[IMOS_STRING_LEN_16];
    
    /**�߼����������*/
    CHAR szCounter[IMOS_STRING_LEN_16];
    
    /**�ź�ǿ��RSSI*/
    CHAR szRSSI[IMOS_STRING_LEN_16];
    
    /**�������*/
    CHAR szLaneID[IMOS_STRING_LEN_16];
    
    /**������*/
    CHAR szDirection[IMOS_STRING_LEN_16];
    
    /** �����������豸���� */
    CHAR szDevType[IMOS_STRING_LEN_16];
    
    /** Ӧ������ */
    CHAR szApplyType[IMOS_STRING_LEN_16];

    /**����ʱ��*/
    CHAR szPassTime[IMOS_TIME_LEN];
    
    /** װ��ʡ�� */
    CHAR szProvince[IMOS_STRING_LEN_32];
    
    /** װ�ó��� */
    CHAR szCity[IMOS_STRING_LEN_32];
    
    /** �������ʱ�� */
    CHAR szDatabaseTime[IMOS_TIME_LEN];
    
    /**ƽ̨����ʱ�� */
    CHAR szReceiveTime[IMOS_TIME_LEN];

	/** added by a02842 for MPPD51528,2017/09/22*/
    /** �豸����*/
    CHAR szDevName[IMOS_NAME_LEN];
    
    /** ���ƺ�*/
    CHAR  szPlateCode[IMOS_CODE_LEN];
    
    /** ��������*/
    CHAR  szDriverName[IMOS_NAME_LEN];

    /** �������֤����*/
    CHAR  szDriverID[IMOS_CODE_LEN];

    /** ��ϵ�绰*/
    CHAR  szDriverPhone[IMOS_CODE_LEN];

    /** Ԥ��λ*/
    CHAR  szReserve[IMOS_STRING_LEN_256];
}RFID_ALARM_INFO_S;

/*Begin added by a02842 for mac identify,2017-05-08*/
/**
 * MAC������ݽṹ
 */
typedef struct tagMACIdentifyInfo
{
    /** �����������*/
    CHAR szIdentifyType[IMOS_CODE_LEN];

    /** ������ݱ���*/
    CHAR szIdentifyCode[IMOS_CODE_LEN];
    
    /**�������ID*/
    CHAR szIdentifyID[IMOS_CODE_LEN];

    /**Ԥ��λ*/
    CHAR szRes1[IMOS_CODE_LEN];  
}MAC_IDENTIFY_INFO;
/*End added by a02842 for mac identify,2017-05-08*/

/**
 * MAC��ַ��Ϣ�ṹ
 */
typedef struct tagMacAlarmInfo
{
     /* �澯ID��Ψһ */
     CHAR szAlarmId[IMOS_CODE_LEN];

     /* �澯ʱ�� */
     CHAR szAlarmTime[IMOS_TIME_LEN];

     /* �澯ԭ��*/
     CHAR szAlarmReason[IMOS_DICTIONARY_KEY_LEN];

     /* ��¼ID �ǿ� */
    CHAR szRecordID[IMOS_CODE_LEN];

    /* �豸ID �ǿ� */
    CHAR szDevID[IMOS_CODE_LEN];

    /* MAC��ַ �ǿ� */
    CHAR szMACAddr[IMOS_CODE_LEN];

    /* �ն˳�ǿ �ǿ� */
    CHAR szFieldIntensity[IMOS_CODE_LEN];

    /* �ն�״̬ �ɿ� 0-�ն˽��� 1-�ն��뿪 */
    CHAR szDevStatus[IMOS_DICTIONARY_KEY_LEN];

    /* ���ɼ��豸���� 0: �ն��豸(Ĭ��) 1: �ȵ� */
    CHAR szDevType[IMOS_DICTIONARY_KEY_LEN];

    /* �ɼ�����*/
    ULONG_32 ulScanNum;
    
    /* �ɼ�ʱ�� �ǿ� */
    CHAR szCollecttime[IMOS_TIME_LEN]; 

    /* ������� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /* �豸���� */
    CHAR szLongitude[IMOS_COORDINATE_LEN];

    /* �豸γ�� */
    CHAR szLatitude[IMOS_COORDINATE_LEN];

    /* �豸���� */
    CHAR szAltitude[IMOS_STRING_LEN_32];

    /* X���� */
    CHAR szCoordX[IMOS_CODE_LEN];
    
    /* Y ���� */
    CHAR szCoordY[IMOS_CODE_LEN];

    /* �����ȵ�SSID */
    CHAR szHotPointSSID[IMOS_STRING_LEN_64];

    /* �����ȵ�MAC */
    CHAR szHotPointMAC[IMOS_CODE_LEN];

    /* �����ȵ�Ƶ�� */
    CHAR szHotPointChannel[IMOS_CODE_LEN];

    /* �����ȵ�������� */
    CHAR szHotPointEncryptType[IMOS_CODE_LEN];

    /* �ն��豸�ɼ���Ϣ���� */
    /* �ն�Ʒ�� */
    CHAR szDevBrand[IMOS_CODE_LEN];

    /* �ն���Ϣ*/
    CHAR szDevInfo[IMOS_DESC_LEN];

    /* �ն���ʷSSID�б� ,�澯��ʱ��ʹ��*/
    CHAR szSSIDList[IMOS_STRING_LEN_1024];

    /* ������� 0: Server 1: Client */
    CHAR szIDType[IMOS_DICTIONARY_KEY_LEN];

    /* ����������(�����������ܹ��ɼ�) */
    /* QQ�ʺ� */
    CHAR szQQID[IMOS_STRING_LEN_256];
    
    /* ΢��ʶ��� */
    CHAR szWeCharID[IMOS_STRING_LEN_256];
    
    /* ΢���ʺ� */
    CHAR szWeiBoID[IMOS_STRING_LEN_256];

    /* ΢���ʺ� */
    CHAR szTencentweibo_ID[IMOS_STRING_LEN_256];
    
    /* �Ա��ʺ� */
    CHAR szTaoBaoID[IMOS_STRING_LEN_256];
    
    /* IMEI: �ƶ��豸ʶ���� */
    CHAR szIMEI[IMOS_STRING_LEN_32];
    
    /* IMSI: �ƶ��û�ʶ���� */
    CHAR szIMSI[IMOS_STRING_LEN_32];
    
    /* �ֻ����� */    
    CHAR szMobileNum[IMOS_STRING_LEN_256];
}    MAC_ALARM_INFO_S;

/*Begin added by a02842 for mac identify,2017-05-08*/
/**
 * MAC��ַ��Ϣ�ṹ
 */
typedef struct tagMacAlarmInfoV2
{
     /* �澯ID��Ψһ */
     CHAR szAlarmId[IMOS_CODE_LEN];

     /* �澯ʱ�� */
     CHAR szAlarmTime[IMOS_TIME_LEN];

     /* �澯ԭ��*/
     CHAR szAlarmReason[IMOS_DICTIONARY_KEY_LEN];

     /* ��¼ID �ǿ� */
    CHAR szRecordID[IMOS_CODE_LEN];

    /* �豸ID �ǿ� */
    CHAR szDevID[IMOS_CODE_LEN];

    /* MAC��ַ �ǿ� */
    CHAR szMACAddr[IMOS_CODE_LEN];

    /* �ն˳�ǿ �ǿ� */
    CHAR szFieldIntensity[IMOS_CODE_LEN];

    /* �ն�״̬ �ɿ� 0-�ն˽��� 1-�ն��뿪 */
    CHAR szDevStatus[IMOS_DICTIONARY_KEY_LEN];

    /* ���ɼ��豸���� 0: �ն��豸(Ĭ��) 1: �ȵ� */
    CHAR szDevType[IMOS_DICTIONARY_KEY_LEN];

    /* �ɼ�����*/
    ULONG_32 ulScanNum;
    
    /* �ɼ�ʱ�� �ǿ� */
    CHAR szCollecttime[IMOS_TIME_LEN]; 

    /* ������� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /* �豸���� */
    CHAR szLongitude[IMOS_COORDINATE_LEN];

    /* �豸γ�� */
    CHAR szLatitude[IMOS_COORDINATE_LEN];

    /* �豸���� */
    CHAR szAltitude[IMOS_STRING_LEN_32];

    /* X���� */
    CHAR szCoordX[IMOS_CODE_LEN];
    
    /* Y ���� */
    CHAR szCoordY[IMOS_CODE_LEN];

    /* �����ȵ�SSID */
    CHAR szHotPointSSID[IMOS_STRING_LEN_64];

    /* �����ȵ�MAC */
    CHAR szHotPointMAC[IMOS_CODE_LEN];

    /* �����ȵ�Ƶ�� */
    CHAR szHotPointChannel[IMOS_CODE_LEN];

    /* �����ȵ�������� */
    CHAR szHotPointEncryptType[IMOS_CODE_LEN];

    /* �ն��豸�ɼ���Ϣ���� */
    /* �ն�Ʒ�� */
    CHAR szDevBrand[IMOS_CODE_LEN];

    /* �ն���Ϣ*/
    CHAR szDevInfo[IMOS_DESC_LEN];

    /* �ն���ʷSSID�б� ,�澯��ʱ��ʹ��*/
    CHAR szSSIDList[IMOS_STRING_LEN_1024];

    /* ������� 0: Server 1: Client */
    CHAR szIDType[IMOS_DICTIONARY_KEY_LEN];

    /* ����������(�����������ܹ��ɼ�) */
    /* QQ�ʺ� */
    CHAR szQQID[IMOS_STRING_LEN_256];
    
    /* ΢��ʶ��� */
    CHAR szWeCharID[IMOS_STRING_LEN_256];
    
    /* ΢���ʺ� */
    CHAR szWeiBoID[IMOS_STRING_LEN_256];

    /* ΢���ʺ� */
    CHAR szTencentweibo_ID[IMOS_STRING_LEN_256];
    
    /* �Ա��ʺ� */
    CHAR szTaoBaoID[IMOS_STRING_LEN_256];
    
    /* IMEI: �ƶ��豸ʶ���� */
    CHAR szIMEI[IMOS_STRING_LEN_32];
    
    /* IMSI: �ƶ��û�ʶ���� */
    CHAR szIMSI[IMOS_STRING_LEN_32];
    
    /* �ֻ����� */    
    CHAR szMobileNum[IMOS_STRING_LEN_256];

    /*�����������*/
    ULONG_32 ulIdentifyNum;
    
    /*���������Ϣ*/
    MAC_IDENTIFY_INFO astIdentifyInfo[IMOS_MAC_IDENTIFY_INFO_MAX_NUM];

    /*���ع���ID*/
    IMOS_ID    idDisposeID;    
    
    /*Ԥ��λ*/
    CHAR szReserve1[120];
}MAC_ALARM_INFO_V2_S;
/*End added by a02842 for mac identify,2017-05-08*/

/*End added by yaozhongmin 02844 date: Aug 25 2016 for MPPD40310*/

/**
 * ����������Ϣ�ṹ
 */
typedef struct tagTollgateFlowInfo
{   
    /* ���ڱ��� */
    CHAR szTollgateID[IMOS_CODE_LEN];

    /* �ɼ�ʱ�� */
    CHAR szSampleTime[IMOS_TIME_LEN];

    /* ����״̬ */
    ULONG_32 ulState;
}TOLLGATE_FLOW_INFO_S;


#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif
