/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_def.h

  Project Code: IMOS PLAT
   Module Name: PUBLIC
  Date Created: 2009-03-16
        Author: lilunyi/03464
   Description: ����ƽ̨����ͷ�ļ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_DEF_H_
#define _IMOS_DEF_H_

#ifdef  __cplusplus
extern "C"{
#endif

/* ��ͬ���ͷ���ʹ����ͬ��ProcID��1-99���������ʹ�� */
#define IMOS_PROCID_VMSERVER            0x1
#define IMOS_PROCID_ISCSERVER           0x1
#define IMOS_PROCID_SDKSERVER           0x2
#define IMOS_PROCID_MCSERVER            0x3
#define IMOS_PROCID_MPSERVER            0x4
#define IMOS_PROCID_MSSERVER            0x4
#define IMOS_PROCID_DMSERVER            0x4
#define IMOS_PROCID_VXSERVER            0x4
#define IMOS_PROCID_SGSERVER            0x5
#define IMOS_PROCID_BMSERVER            0x6
#define IMOS_PROCID_BWSERVER            0x7
#define IMOS_PROCID_NDSERVER            0x8
#define IMOS_PROCID_IMPSERVER           0x9
#define IMOS_PROCID_UNPSERVER           0xA

#define IMOS_PROCID_TMSSERVER           0xB
#define IMOS_PROCID_TMSCOMBINE          0xC
#define IMOS_PROCID_TMSWS               0xD
#define IMOS_PROCID_TMSRECORD           0xE
#define IMOS_PROCID_TSSERVER            0xF

#define IMOS_PROCID_DRSERVER            0x10
#define IMOS_PROCID_MDSERVER            0x11
#define IMOS_PROCID_TMSNDSERVER         0x12
#define IMOS_PROCID_UVWSSERVER          0x13
#define IMOS_PROCID_MAPMSERVER          0x14

/* Begin: Added by zhongke z01354, 2014-10-23 for uniview_keyboard */
#define IMOS_PROCID_KBSERVER            0x15
/* End: Added by zhongke z01354, 2014-10-23 for uniview_keyboard */

#define IMOS_PROCID_CDMSERVER           0x16
#define IMOS_PROCID_CDVSERVER           0x17
#define IMOS_PROCID_VODSERVER           0x18

/* Begin: Added by zhongke, 2015-03-06 for CDS�ƴ洢 */
#define IMOS_PROCID_DMCSERVER            0x19
/* End: Added by zhongke, 2015-03-06 for CDS�ƴ洢 */

#define IMOS_PROCID_PAWSSERVER          0x20
#define IMOS_PROCID_DMGSERVER           0x21

/* Begin: Modified by zhouquanwei/z01364, 2015-07-27 for onvif ���� */
#define IMOS_PROCID_ONVIFSERVER         0x22
/* End: Modified by zhouquanwei/z01364, 2015-07-27 for onvif ���� */

/* SDK client�͵�����SDK����ʹ��100 */
#define IMOS_PROCID_SDKCLIENT           0x64

/* TP���̱�������ֵ���䣬��101��ʼ */
#define IMOS_PROCID_MW_CTRL             0x65
#define IMOS_PROCID_MW_STOR_MCP         0x66
#define IMOS_PROCID_MW_PTZ              0x67
#define IMOS_PROCID_MW_SNMP             0x68
#define IMOS_PROCID_MW_ALM              0x69
#define IMOS_PROCID_MW_CAPI             0x6A
#define IMOS_PROCID_MW_SDK              0x6B

#define IMOS_PROCID_NM_CTRL             0x6D
#define IMOS_PROCID_RGBSERVER           0x6E

/* Begin: Added by zhouquanwei/z01364, 2015-06-06 for onvif server */
/* onvifsever���� */
#define IMOS_PROCID_ONVIF_SERVER        0x70
/* End: Added by zhouquanwei/z01364, 2015-06-06 for onvif server */

/* Begin Added by zhangqiwei/z02459, 2016-05-10 for cluserver*/
#define IMOS_PROCID_CDS_CLUSERVER        0x71
/* End Added by zhangqiwei/z02459, 2016-05-10 for cluserver*/

/* ���Թ����Լ��������߳���ʹ��257 */
#define IMOS_PROCID_DT                  0x101
/* IMOS���������� */
#define IMOS_PROCID_WATCHDOG                  0x102

/** @brief Ȩ����������������� */
#define IMOS_AUTHORITY_MAX_NUM                  128

/** �ڲ�Ȩ����������������� */
#define IMOS_AUTHORITY_MAX_NUM_EX               1024

/** �洢Ȩ���ֶ������� */
#define IMOS_AUTHORITY_MAX_FIELD_COUNT          32

/*@brief IMOSϵͳ��������*/
#define IMOS_SYS_PARAM_LEN                      128             /**< ƽ̨֧�ֵ�ϵͳ��������, ��Ч���λ��Ϊ127λ */

/*@brief ͨ��CODE����*/
#define IMOS_CODE_LEN                           48             /**< ƽ̨֧�ֵ���Ч���λ��Ϊ47λ */

/*@brief ͨ���û�Ŀ¼����*/
#define IMOS_USR_DIR_LEN           96             /**< �����û�Ŀ¼��������Code��ɣ���Ϊ96*/

/*@brief ͨ�������ַ������� */
#define IMOS_NAME_LEN                           64             /**< ƽ̨֧�ֵ���Ч���λ��Ϊ63λ */

/*@brief URL��ַ���� */
#define IMOS_URL_LEN                            512
/*@brief ���ͼ���� */
#define MAX_LAYER_NUM                           6              /**< ƽ̨֧�ֵ���Ч���ͼ���� */
/////////////////////

/*@brief ��Դ������Ϣ�ַ�������*/
#define IMOS_RES_CODE_LEN                       IMOS_CODE_LEN

/*@brief �豸������Ϣ�ַ�������*/
#define IMOS_DEVICE_CODE_LEN                    IMOS_CODE_LEN

/*@brief �û�������Ϣ�ַ�������*/
#define IMOS_USER_CODE_LEN                      IMOS_CODE_LEN

/*@brief �������Ϣ�ַ�������*/
#define IMOS_DOMAIN_CODE_LEN                    IMOS_CODE_LEN

/*@brief ��������Ϣ�ַ������� */
#define IMOS_DOMAIN_NAME_LEN                    IMOS_NAME_LEN

/*@brief Ȩ�ޱ�����Ϣ�ַ�������*/
#define IMOS_AUTH_CODE_LEN                      IMOS_CODE_LEN

/*@brief �û�Ŀ¼���볤��*/
#define IMOS_USR_DIR_CODE_LEN           (2*IMOS_CODE_LEN)      /**< �����û�Ŀ¼code������������Code��ɣ���Ϊ2��ͨ��CODE��С*/

/*@brief �û�Ŀ¼���Ƴ���*/
#define IMOS_USR_DIR_NAME_LEN           IMOS_USR_DIR_CODE_LEN  /**<���ǵ�VM�û�Ŀ¼�����������DMCͳһ���ɣ���������뱣��һ��*/

/*@brief ���й�����UA ID���ַ����鳤��*/
#define IMOS_UAID_LEN                           64             /**< ƽ̨֧�ֵ���Ч���λ��Ϊ63λ */

/*@brief UA������Ϣ�ַ�������*/
#define IMOS_UA_CODE_LEN                        IMOS_UAID_LEN

/*@brief ��Ƶ��ǩ��Ϣ�ַ�������*/
#define IMOS_RECORD_LABEL_LEN                   256

/*@brief ����Э�̻ỰID����*/
#define IMOS_SSN_ID_LEN                         IMOS_STRING_LEN_32

/*@brief MP������������ */
#define IMOS_MP_ABILITY_LEN                     IMOS_STRING_LEN_256

/*@brief DecoderTag�ĳ��� */
#define IMOS_DECODERTAG_LEN                     IMOS_STRING_LEN_32

/*@brief SG����ͷ����*/
#define IMOS_SG_HEAD_CODE_LEN                       2

/*@brief JSON��ʽ�����ֵ����*/
#define IMOS_JSON_NUM_LEN                           8   /* Added by c02845,2016-03-05,for MPPD35518,ͨ��Э��*/

/* @brief IMOS �����ļ���������󳤶� */
#define IMOS_CONF_ITEM_MAX_LEN          512

//////////////

/* Begin Add by zhengyibing(01306), 2014-05-30 for �¹����޸Ķ��� */
#define IMOS_CAMEAR_VIDEO_STREAM_NUMBER_LEN               8         /*  �������Ƶ������Ŀ:Ŀǰ���֧��8· */
#define IMOS_CAMEAR_AUDIO_STREAM_NUMBER_LEN               4         /* �������Ƶ������Ŀ:Ŀǰ���֧��4· */
#define IMOS_CAMEAR_SVAC_ENCODE_ROI_LEN                   16        /* ����Ȥ��������Ŀ:���16 */
/* End Add by zhengyibing(01306), 2014-05-30 for �¹����޸Ķ��� */

/* Begin Add By hexiaojun/hW0959 for ����֧��˫���� 2014-10-13 */
#define IMOS_STREAM_NUMBER_ONE                  1        /* �����������Ŀ 1�� */
#define IMOS_STREAM_NUMBER_TWO                  2        /* �����������Ŀ 2�� */
#define IMOS_STREAM_INDEX                       2        /* �������������(���Ӻ�ɾ������¼��ʱ��ֻ��ɾ��������Ϊ2������) */
/* ����������һ������¼����Ϣ�Ĳ��� */
#define IMOS_STREAM_OTHER_INFO                  0        /* �����õ�������Ϣ����������Ϊ0 */
#define IMOS_ENABLE_STREAM                      1        /* ʹ���� */
#define IMOS_ENCODE_FORMAT                      6        /* �����ʽ */
#define IMOS_BIT_RATE                           2048     /* ���� */
#define IMOS_FRAME_RATE                         25       /* ֡�� */
#define IMOS_I_FRAME_INTERVAL                   25       /* I֡��� */
#define IMOS_IMAGE_QUALITY                      1        /* ͼ������ */
/* End Add By hexiaojun/hW0959 for ����֧��˫���� 2014-10-13 */

/*@brief MAI/AOI��Ϣ��ͨ��ģ�����Ƶ��ַ������� MODULENAME@DEVCODE */
#define IMOS_MODULE_NAME_LEN                    64 /**< ƽ̨֧�ֵ���Ч���λ��Ϊ63λ */

/*@brief mac��ַ�ַ������� "AA-BB-CC-DD-EE-FF" */
#define IMOS_MAC_ADDR_LEN                       20

/*@brief imos_addr IP��ַ��Ϣ�ַ�������
 * IPV4: "192.168.0.102"
 * IPV6: "A1:0:8:100:200:0:0:321A"
 * ����: "AS_server_hangzhou" */
#define IMOS_IPADDR_LEN                         64

/*@brief ��Ч��IP��ַ���� */
#define IMOS_IPADDR_TYPE_INVALID                (0xFFFFFFFF)

/*====== BEGIN: Added by shendongchun 00400 for �û���¼������ǿ, 2012��11��14�� 17:56:58 =====*/
/*@brief MAC��ַ���� */
#define IMOS_IPADDR_TYPE_MAC                    0
/*====== END  : Added by shendongchun 00400 for �û���¼������ǿ, 2012��11��14�� 17:56:58 =====*/

/* Begin added by lijiangkun lW4644 for MPPD54193 ,Jan 04, 2018 */
/*@brief ��������2016������֧�ֵ�ͼ������ */
#define IMOS_FACE_PICUNMBER                     2

/*@brief ��������2016������֧�ֵĵ�1��ͼƬ */
#define IMOS_FACE_PICUNMBER1                    0

/*@brief ��������2016������֧�ֵĵ�2��ͼƬ */
#define IMOS_FACE_PICUNMBER2                    1

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-�ַ� ��0�� */
#define IMOS_IAVAS_ISIPCH0                       '0'

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-�ַ� ��9�� */
#define IMOS_IAVAS_ISIPCH9                       '9'

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-�ַ� ��.�� */
#define IMOS_IAVAS_ISIPCHDOT                     '.'

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-����7 */
#define IMOS_IAVAS_ISIPNUM7                     7

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-����20 */
#define IMOS_IAVAS_ISIPNUM20                    20

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-����3 */
#define IMOS_IAVAS_ISIPNUM3                     3

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-����10 */
#define IMOS_IAVAS_ISIPNUM10                    10

/*@brief �ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP-����10 */
#define IMOS_IAVAS_ISIPNUM255                   255

/*@brief IAVAS-����0 */
#define IMOS_IAVAS_NUM0                          0

/*@brief IAVAS-����1 */
#define IMOS_IAVAS_NUM1                          1

/*@brief IAVAS-����2 */
#define IMOS_IAVAS_NUM2                          2

/*@brief IAVAS-����3 */
#define IMOS_IAVAS_NUM3                          3

/*@brief IAVAS-����4 */
#define IMOS_IAVAS_NUM4                          4

/*@brief IAVAS-����50 */
#define IMOS_IAVAS_NUM50                         50

/*@brief IAVAS-����60 */
#define IMOS_IAVAS_NUM60                         60

/*@brief IAVAS-����80 */
#define IMOS_IAVAS_NUM80                         80

/*@brief IAVAS-�ַ���0 */
#define IMOS_IAVAS_STRING0                       "0"

/*@brief IAVAS-���ַ��� */
#define IMOS_IAVAS_STRINGNULL                    ""

/* End added by lijiangkun lW4644 for MPPD54193 ,Jan 04, 2018 */

/*@brief IPV4��ַ���� */
#define IMOS_IPADDR_TYPE_IPV4                   1

/*@brief IPV6��ַ���� */
#define IMOS_IPADDR_TYPE_IPV6                   2

/*@brief ������ַ���� */
#define IMOS_IPADDR_TYPE_DOMAINNAME             16

/*@brief ������Ϣ�ַ������� */
#define IMOS_PASSWD_LEN                         16

/*@brief ���Ŀ�����ܺ��ַ������� */
#define IMOS_PASSWD_ENCRYPT_LEN                 64  /**< ƽ̨֧�ֵ���Ч���λ��Ϊ63λ */

/* Begin Added by yW4708 2017-10-17,for MPPD52393 ���֤���� */
/*@brief���֤�ַ������� */
#define IMOS_ID_CARD_LEN                        19 /**<���֤���볤��18λ ����1λ*/
/* End Added by yW4708 2017-10-17,for MPPD52393 ���֤���� */

/*@brief imos_time ʱ����Ϣ�ַ������� "2008-10-02 09:25:33.001 GMT" */
#define IMOS_TIME_LEN                           32

/*@brief imos_simple_time ʱ����Ϣ�ַ������� "hh:mm:ss" */
#define IMOS_SIMPLE_TIME_LEN                    12

/*@brief imos_simple_date ������Ϣ�ַ������� "YYYY-MM-DD"*/
#define IMOS_SIMPLE_DATE_LEN                    12

/** Begin Added by c02845,for MPPD35518��ƽ̨֧�ֱ�����ͨ��Э�飬Уʱʱ�䷵�ظ�ʽ */

/*@brief imos_checktime_date ������Ϣ�ַ������� "YYYYMMDDHHMMSS"*/
#define IMOS_CHENCTTIME_DATE_LEN                16

/** ����Э���豸���볤�� */
#define TMS_UV_DEV_CODE_LEN                     32

/*@brief imos_collecttime_date MAC�ɼ�ʱ����Ϣ�ַ������� "YYYYMMDDHHMMSSMMM"*/
#define IMOS_MAC_COLLECTTIME_DATE_LEN           18

/** End Added by c02845,ƽ̨֧�ֱ�����ͨ��Э�飬Уʱʱ�䷵�ظ�ʽ */

#define IMOS_SAMPLETIME_DATE_LEN                18

/*@brief imos_description ������Ϣ�ַ������� */
#define IMOS_DESC_LEN                           (128 * 3)

/*@brief �̶��绰�����ַ������� */
#define IMOS_PHONE_LEN                          32

/*@brief �ƶ��绰�����ַ������� */
#define IMOS_MOBILE_LEN                         32

/*@brief �ƶ��绰�����ַ�������12*256 */
#define IMOS_SMS_LEN_3072                       3072

/*@brief E-Mail�ַ������� */
#define IMOS_MAIL_LEN                           64

/*@brief ��������������� */
#define IMOS_MAIL_CODE_LEN                      8

/*@brief ѡ������һ���յĳ��� ��ʽ��:0110101(1����ѡ��0����ûѡ��)*/
#define IMOS_WEEK_CODE_LEN                      8

/*@brief ʱ���ʽ����00:00:00*/
#define IMOS_TIME_CODE_LEN                      12

/*@brief ͨ�ŵ�ַ�ַ������� */
#define IMOS_CONTACT_ADDRESS_LEN                64

/*@brief ��Ʒ�����ַ������� */
#define IMOS_PRODUCTNAME_LEN                    32

/*@brief �汾��Ϣ�ַ������� */
#define IMOS_VERSION_INFO_LEN                   64

/*====== BEGIN: Added by shendongchun 00400 for VVD75808, 2012��11��15�� 10:41:45 =====*/
/*@brief �°汾��Ϣ�ַ������� */
#define IMOS_NEW_VERSION_INFO_LEN               256
/*====== END  : Added by shendongchun 00400 for VVD75808, 2012��11��15�� 10:41:45 =====*/

/*@brief �ļ������� */
#define IMOS_FILE_NAME_LEN                      64

/*@brief �ļ�������(V2) */
#define IMOS_FILE_NAME_LEN_V2                   256

/** @brief �������ַ�������(��ULONG���ֵ����,4�ֽ�FFFFFFFF,ʮ����Ϊ4294967295,��1λ'\0',��11λ) */
#define IMOS_ERR_CODE_LEN                       11

/* Begin Added by wuchengping02739, 2011-07-19 of VVD57853 */
/** @brief XML�ֶ� - �ɹ���Ӧ */
#define IMOS_XML_KEY_RSP_OK "Rsp_Ok"

/** @brief XML�ֶ�ֵͨ�ó���(ʹ��ʱ,ע�ⳤ���Ƿ���) */
#define IMOS_XML_KEY_LEN                        64
/* End Added by wuchengping02739, 2011-07-19 of VVD57853 */

/*@brief �ļ�����·��(·��+�ļ���)���� */
#define IMOS_FILE_PATH_LEN                      256

/*@brief �ļ�����·��(�����ļ���)���� */
#define IMOS_FILE_PATH_WITHOUT_FILENAME_LEN     128

/** @brief �ص�������� */
#define IMOS_MEASUREMENT_LEN                    16

/** @brief �����ֵ�Key�ֶγ��� */
#define IMOS_DICTIONARY_KEY_LEN                 8

/** @brief ��γ���ַ������� */
#define IMOS_COORDINATE_LEN                     32

/*@brief ��Դ������֯·������ */
#define IMOS_RES_PATH_LEN                       1024

/*@brief XP���񲼾������ַ������� */
#define IMOS_XP_LAYOUT_DESC_LEN                 256

/*@brief ��չ�ֶγ��� */
#define IMOS_RESERVED_LEN                       64

/*@brief ͨ��8λ�ַ��� */
#define IMOS_STRING_LEN_8                      8

/*@brief ͨ��4λ�ַ��� */
#define IMOS_STRING_LEN_4                      4

/*@brief ͨ��14λ�ַ��� */
#define IMOS_STRING_LEN_14                      14

/*@brief ͨ��16λ�ַ��� */
#define IMOS_STRING_LEN_16                      16

/*@brief ͨ��32λ�ַ��� */
#define IMOS_STRING_LEN_32                      32

/*@brief ͨ��64λ�ַ��� */
#define IMOS_STRING_LEN_64                      64

/*@brief ͨ��128λ�ַ��� */
#define IMOS_STRING_LEN_128                     128

/*@brief ͨ��256λ�ַ��� */
#define IMOS_STRING_LEN_256                     256

/*@brief ͨ��512λ�ַ��� */
#define IMOS_STRING_LEN_512                     512

/*@brief ͨ��1024λ�ַ��� */
#define IMOS_STRING_LEN_1024                    1024

/*@brief ͨ��2048λ�ַ��� */
#define IMOS_STRING_LEN_2048                    2048

/*@brief ͨ��1Mλ�ַ��� */
#define IMOS_STRING_LEN_1M                      (1024 * 1024)

/*@brief SN���� */
#define IMOS_SN_LEN                             24

/*@brief ��Դ����� */
#define IMOS_RES_TREE_LEVEL                     26

/*@brief �豸����״̬ */
#define IMOS_DEV_STATUS_ONLINE                  1

/*@brief �豸����״̬ */
#define IMOS_DEV_STATUS_OFFLINE         2

/*@brief �豸����״̬ */
#define IMOS_DEV_STATUS_NORMAL          3

/*@brief �豸����״̬ */
#define IMOS_DEV_STATUS_FAULT           4

/*@brief �豸���� */
#define IMOS_DEV_UNABLE                 0

/*@brief �豸���� */
#define IMOS_DEV_ENABLE                 1

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
/*@brief ��������Ч״̬,��Բ��߱�������״̬����Դ */
#define IMOS_SWITCH_STATUS_INVALID      0

/*@brief ��������״̬ */
#define IMOS_SWITCH_STATUS_ON           1

/*@brief �������ر�״̬ */
#define IMOS_SWITCH_STATUS_OFF          2
/* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

/*@brief �����ƣ�IMOS_ltoa������ʹ�� */
#define  IMOS_Radix_2                   2

/*@brief �˽��ƣ�IMOS_ltoa������ʹ�� */
#define  IMOS_Radix_8                   8

/*@brief ʮ���ƣ�IMOS_ltoa������ʹ�� */
#define  IMOS_Radix_10                  10

/*@brief ʮ�����ƣ�IMOS_ltoa������ʹ�� */
#define  IMOS_Radix_16                  16


/*@brief IMOS_ID ��Ӧ�ַ����ĳ��ȣ�64λ����IDת����������Ч�ַ�����Ϊ20�� */
#define  IMOS_ID_STRING_LEN             24

/*@brief ����¼�������� */
#define  IMOS_BAK_CASE_LEN              128

/*@brief ����������Ϣ�ַ������� */
#define IMOS_CASE_DESC_LEN                      (1024 * 3)

/*@brief ��ע��Ϣ�ַ������� */
#define IMOS_NOTE_LEN                           (256 * 3)

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/** @brief �����켣��ײͨ���ص�������� */
#define IMOS_VEHICLE_TRACK_PLACE_MAX_NUM             16

/** @brief �����켣��ײ�����Դ���� */
#define IMOS_VEHICLE_TRACK_COLLISION_RES_MAX_NUM     200

/** @brief �����״γ�������������Դ���� */
#define IMOS_VEHICLE_FIRST_APPEAR_RES_MAX_NUM        200

/** @brief ������Σʱ������������Դ���� */
#define IMOS_VEHICLE_PERIL_TIME_RES_MAX_NUM          200

/** @brief ����Ƶ��ҹ������������Դ���� */
#define IMOS_VEHICLE_FREQUENT_NIGHT_OUT_RES_MAX_NUM  200

/** @brief �������ҹ������������Դ���� */
#define IMOS_VEHICLE_NOCTURNAL_RES_MAX_NUM           200

/** @brief ������ν��ǲ���������������Դ���� */
#define IMOS_VEHICLE_ONLY_INTO_CITY_RES_MAX_NUM      200

/** @brief ������������������Դ���� */
#define IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM   200

/** @brief ��ͼ�������������Դ���� */
#define IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM            200
/* End added by bt00977, 2013-1-25 of MPPD00420 */

/** @brief TMS���ַת�������Դ���� */
#define IMOS_TMS_MULTI_FORWARD_RES_MAX_NUM            200

/** @brief ���������������Դ���� */
#define IMOS_TOLLGATE_GROUP_RES_MAX_NUM            200

/** @brief һ�δ���������Ŀ*/
#define IMOS_MAX_DEAL_NUM_ONE_TIME                  200

/** @brief ����ƽ���ٶ���Чֵ */
#define IMOS_TOLLGATE_INVALID_AVERAGE_SPEED          (0XFFFE)

/*@brief һ���ڵ����� */
#define IMOS_SECS_PER_DAY	            86400

/*@brief һСʱ�ڵ����� */
#define IMOS_SECS_PER_HOUR	            3600

/*@brief һ�����ڵ����� */
#define IMOS_SECS_PER_MINUTE            60

/*@brief һСʱ�ڵķ����� */
#define IMOS_MINS_PER_HOUR	            60

/*Begin added by liujian 02319, 2016-03-31 for �����ڱ�����������*/
/*@ brief һ���ڵ�Сʱ��*/
#define IMOS_HOURS_PER_DAY              24
/*End added by liujian 02319, 2016-03-31 for �����ڱ�����������*/

/*@brief ������ */
#define IMOS_SUN            0

/*@brief ����һ */
#define IMOS_MON            1

/*@brief ���ڶ� */
#define IMOS_TUE            2

/*@brief ������ */
#define IMOS_WED            3

/*@brief ������ */
#define IMOS_THU            4

/*@brief ������ */
#define IMOS_FRI            5

/*@brief ������ */
#define IMOS_SAT            6

/*@brief һ�� */
#define IMOS_JAN            0

/*@brief ���� */
#define IMOS_FEB            1

/*@brief ���� */
#define IMOS_MAR            2

/*@brief ���� */
#define IMOS_APR            3

/*@brief ���� */
#define IMOS_MAY            4

/*@brief ���� */
#define IMOS_JUN            5

/*@brief ���� */
#define IMOS_JUL            6

/*@brief ���� */
#define IMOS_AUG            7

/*@brief ���� */
#define IMOS_SEP            8

/*@brief ʮ�� */
#define IMOS_OCT            9

/*@brief ʮһ�� */
#define IMOS_NOV            10

/*@brief ʮ���� */
#define IMOS_DEC            11

/* @brief SG ID��Ϣ�ַ�������, SG ID���ɹ���SG����&5λ����� */
#define IMOS_SG_ID_LEN   (IMOS_DEVICE_CODE_LEN + 6)

/*@brief ÿ����Ƶͨ��֧�ֵ��������Ŀ  */
#define IMOS_STREAM_MAXNUM                  2

/*@brief ÿ����Ƶͨ��֧�ֵ��������Ŀ,Ŀǰ�������͵�EC�Դ˱�׼  */
#define IMOS_STREAM_MAXNUM_II                  3

/*@brief ÿ����Ƶͨ��֧�ֵ����������Ŀ  */
#define IMOS_AREA_MAXNUM                    12

/*@brief ��ͨ���ڸ�����������Ŀ */
#define IMOS_MASK_AREA_MAXNUM               4

/*@brief ��ͨ���ڸ�����������Ŀ(8) */
#define IMOS_MASK_AREA_MAXNUM_VIII          8

/*@brief ��ͨ���������������Ŀ */
#define IMOS_DETECT_AREA_MAXNUM             4

/*@brief ÿ����Ƶͨ��֧�ֵ����OSD��Ŀ ����osd + ͼƬosd  */
#define IMOS_OSD_NAME_MAXNUM                1

/*@brief ÿ����Ƶͨ��֧�ֵ����OSD��Ŀ ����osd + ͼƬosd Ŀǰ����EC2004-HF��EC2016-HC�Դ˱�׼ */
#define IMOS_OSD_NAME_MAXNUM_II             2

/*@brief ÿ����Ƶͨ��֧�ֵ����OSD��Ŀ ����osd + ͼƬosd Ŀǰ�������͵�DC�Դ˱�׼ */
#define IMOS_OSD_NAME_MAXNUM_I              1

/*@brief ÿ����Ƶͨ��֧�ֵ����OSD��Ŀ ����osd + ͼƬosd Ŀǰ��EC2004-HF��EC2016-HC�����EC�豸�Դ˱�׼ */
#define IMOS_OSD_NAME_MAXNUM_IV             4

/*@brief ÿ����Ƶͨ��֧�ֵ����OSD��Ŀ ����osd + ͼƬosd ĿǰEC1001�Դ˱�׼ */
#define IMOS_OSD_NAME_MAXNUM_VIII             8

/* Modified by wuchengping02739, 2011-12-16 of VVD63549 */
/*@brief ����OSD��������  */
#define IMOS_OSD_NAME_MAX                     9

/*@brief ʱ��OSD��������  */
#define IMOS_OSD_TIME_MAX                   1

/** @brief ����OSDȱʡֵ */
#define IMOS_NAME_OSD_DEFAULT_VALUE        "H3C"

/** @brief �л�ʱ����ȱʡֵ */
#define IMOS_INTERVAL_DEFAULT_VALUE         0

/*@brief ÿ��ͨ������ѡ���MS���������  */
#define IMOS_MS_MAX_NUM_PER_CHANNEL         1

/*@brief ��ȫ����������  */
#define IMOS_MAX_NET_SEGM_NUM               10

/*@brief �ƻ���ÿ���ʱ��Ƭ����  */
#define IMOS_MAX_TIME_SLICE_NUM             4

/*@brief �˺�Ѳ���ƻ���ÿ���ʱ��Ƭ����  */
#define IMOS_MAX_CRUISE_TIME_SLICE_NUM		8


/*@brief �ƻ���ÿ���ʱ��Ƭ����V2�汾  */
#define IMOS_MAX_TIME_SLICE_NUM_V2          16

/*@brief �ƻ���ÿ�ܵ�����  */
#define IMOS_WEEK_DAYS                      7

/*@brief �ƻ������������  */
#define IMOS_EXCP_DAYS                      16

/*@brief ע��/ע��ҵ����� */
#define  IMOS_SRV_CODE_REGISTER             1001

/*@brief �����·�ҵ����� */
#define  IMOS_SRV_CODE_CONFIG               1002

/*@brief �ļ�����/����ҵ����� */
#define  IMOS_SRV_CODE_FILE                 1003

/*@brief Ѳ��ҵ����� */
#define  IMOS_SRV_CODE_CHECK                1004

/*@brief ʵʱ��Ƶҵ����� */
#define  IMOS_SRV_CODE_MONITOR              2001

/* Begin added by y01359 for A8, 2015-02-05 for A8 */
/*@brief ʵʱ��ƵA8�ڲ�ҵ����� */
#define  IMOS_SRV_CODE_MONITOR_INNER_A8     2002
/* End added by y01359 for A8, 2015-02-05 for A8 */

/*@brief �����Խ�ҵ����� */
#define  IMOS_SRV_CODE_VOICE_TALKBACK       2011

/*@brief �����㲥ҵ����� */
#define  IMOS_SRV_CODE_VOICE_BROADCAST      2012

/*@brief ����Ƶ�Խ�ҵ����� */
#define  IMOS_SRV_CODE_MON_TALKBACK         2013

/*@brief ����Ƶ�㲥ҵ����� */
#define  IMOS_SRV_CODE_MON_BROADCAST        2014

/* Begin added by y01359 2014-11-26 for A8 */
/*@brief ����ǽҵ����� */
#define  IMOS_SRV_CODE_TVWALL_OPERATE                            2501

/*@brief ����ǽ��������ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_WINDOWS_CONTRAL                    2502

/*@brief ����ǽ��ͼ����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_BASE_PICTURE_OPERATE               2503

/*@brief ����ǽ��ʱ����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_TIMER_PARAM_OPERATE                2505

/*@brief ����ǽ���߻ָ�ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_DORMANCY_OPERATE                   2506

/*@brief ����ǽ��������˿�ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_OUTPUT_TEST_OPERATE                2507

/*@brief ����ǽ��������EDIDҵ����� */
#define  IMOS_SRV_CODE_TVWALL_INPUT_EDID_OPERATE                 2509

/*@brief ����ǽ������Ƶ����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_AUDIO_INPUT                        2512

/*@brief ����ǽ������Ƶ���ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_AUDIO_OUTPUT                       2513

/*@brief ����ǽ������Ƶ����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_AUDIO_MUTE                         2514

/*@brief ����ǽ������Ƶ����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_AUDIO_VOLUME                       2515

/*@brief ����ǽ��������ͼ�����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_VIN_CHANNEL_IMAGE_PARAM            2516

/*@brief ����ǽ����LEDҵ����� */
#define  IMOS_SRV_CODE_TVWALL_VIRTUAL_LED                        2517

/*@brief ����ǽͣ����LEDҵ����� */
#define  IMOS_SRV_CODE_TVWALL_ENABLE_VIRTUAL_LED                 2518

/*@brief ����ǽ�������ͼ�����Ȼ�Աȶ�ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_ADJUST_BRIGHT_CNT                  2519

/*@brief A8�豸ͨ���豸�����߸澯*/
#define  IMOS_SRV_CODE_A8_DEVICE_STATUS_ALARM                    2521

/*@brief ����ǽ�����������ҵ����� */
#define  IMOS_SRV_CODE_A8_TVWALL_VIN_CHANNEL_PARAM               2522

/*@brief ����ǽ�������ڿ���ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_BATCH_WINDOWS_CONTRAL              2523

/*@brief ����ǽ�������ò���ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_BATCH_CFG_PARAM                    2524

/*@brief ����ǽ�����Ƶ����ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_OUTPUT_AUDIO_PARAM                 2525

/*@brief A8�豸���ó���ҵ����� */
#define  IMOS_SRV_CODE_A8_DEVICE_SMOOTH_DISPLAY_PARAM            2526

/*@brief A8��ѯ�豸ҵ����� */
#define  IMOS_SRV_CODE_QUERY_DEVICE_PARAM                        2527

/*@brief A8��ѯ���ڽ�����Ϣҵ����� */
#define  IMOS_SRV_CODE_QUERY_WINDOW_DECOED_INFO                  2528

/*@brief A8����ǽʵ���澯ҵ����� */
#define  IMOS_SRV_CODE_TVWALL_MONITOR_ALARM_INFO                 2529

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */
/*@brief ����������ò�����*/
#define  IMOS_SRV_CODE_CLEAN_OUT_DEPLOY  2530
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */

/* Ended added by y01359 2014-11-26 for A8 */

/* Begin: Added by mW4699 maojiangfeng, 2017-12-18 for Xware֧��������� */
/*@brief Xware��ѯ�豸ҵ����� */
#define  IMOS_SRV_CODE_DACT_QUERY_DEVICE_PARAM                        2531
/* End: Added by mW4699 maojiangfeng, 2017-12-18 for Xware֧��������� */

/* Begin: Added by mW4699 maojiangfeng, 2018-03-07 for MPPD57183 Xware˫���Ŵ� */
/*@brief ����ǽ�������ſ���ҵ����� */
#define  IMOS_SRV_CODE_ZOOM_SCREEN_OPERATE                     2532
/* End: Added by mW4699 maojiangfeng, 2018-03-07 for MPPD57183 Xware˫���Ŵ� */

/*@brief ¼���ѯҵ����� */
#define  IMOS_SRV_CODE_REC_QUERY            3001

/*@brief ¼������ҵ����� */
#define  IMOS_SRV_CODE_REC_DOWNLOAD         3002

/*@brief ¼��ط�ҵ����� */
#define  IMOS_SRV_CODE_REC_VOD              3003

/*@brief ¼�񱸷�ҵ����� */
#define  IMOS_SRV_CODE_REC_BACKUP           3004

/* added by z06806 for vodwall prj 20101220 begin */
/*@brief �ط���ǽҵ����� */
#define  IMOS_SRV_CODE_VODWALL              3005
/* added by z06806 for vodwall prj 20101220 end */

/*@brief ¼���ȡURLҵ����� */
#define  IMOS_SRV_CODE_REC_URL              3006

/*@brief ¼���ѯ�������ҵ����� */
#define  IMOS_SRV_CODE_REC_QUERY_PUSH       3007

/* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
/*@brief ¼������ҵ����� */
#define  IMOS_SRV_CODE_LOCK_RECORD       3008
/* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */

/*@brief ǰ��¼�����ҵ����� */
#define IMOS_SRV_CODE_DEVICE_REC_QUERY     3009         /* Add by zhengyibing(01306), 2014-04-19 for �¹����޶�*/

/*@brief ֱ�Ӵ洢ҵ����� */
#define  IMOS_SRV_CODE_DIR_STROE            4001

/*@brief �����洢ҵ����� */
#define  IMOS_SRV_CODE_STR_STORE            4002

/*@brief ǰ�˴洢ҵ����� */
#define  IMOS_SRV_CODE_TP_STORE             4003

/*@brief ˢ�´洢�������� */
#define  IMOS_SRV_CODE_REFRESH_STORE_IDX    4004

/*@brief ��ȡInitiatorҵ����� */
#define  IMOS_SRV_CODE_GET_INITIATOR        4010

/*@brief �������Ĵ洢��Դҵ����� */
#define  IMOS_SRV_CODE_CENT_STORE_RES_CFG   4011

/*@brief �������Ĵ洢�ƻ�ҵ����� */
#define  IMOS_SRV_CODE_CENT_STORE_PLAN_CFG  4012

/*@brief �������ĸ澯�����洢ҵ����� */
#define  IMOS_SRV_CODE_CENT_ALARM_STORE_CFG 4013

/*@brief ���Ĵ����澯�洢ҵ����� */
#define  IMOS_SRV_CODE_CENT_TRIGGER_ALARM_STORE   4020

/*@brief ���Ĵ����ֶ��洢ҵ����� */
#define  IMOS_SRV_CODE_CENT_TRIGGER_MANUAL_STORE  4021

/*@brief ǰ���ֶ��洢ҵ����� */
#define  IMOS_SRV_CODE_FRONT_END_MANUAL_STORE  4022

/*@brief ����ֱ��ҵ����� */
#define  IMOS_SRV_CODE_PIC_STROE            9001  /* Added by c02845,2016-03-28,������ֱ�� */

/*@brief ��̨����ҵ����� */
#define  IMOS_SRV_CODE_PTZ                  5001

/*@brief ����������ҵ����� */
#define  IMOS_SRV_CODE_SWITCH               5002

/*@brief Ԥ��λ�б��ѯҵ����� */
#define  IMOS_SRV_CODE_PRESETLIST_QUERY     5003

/*@brief ��̨����������ҵ����� */
#define  IMOS_SRV_CODE_PTZ_LOCK_UNLOCK     5004

/*@brief ��̨������֪ͨҵ����� */
#define  IMOS_SRV_CODE_PTZ_UNLOCK_NOTIFY     5005

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
/*@brief ����������������ҵ����� */
#define  IMOS_SRV_CODE_IOT_SWITCH           5006
/* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

/*@brief ͸��ͨ��ҵ����� */
#define  IMOS_SRV_CODE_TRANS_CHANNEL        6001

/*@brief ͸�����ݴ���ҵ����� */
#define  IMOS_SRV_CODE_TRANS_DATA           6002

/*@brief �澯����ҵ����� */
#define  IMOS_SRV_CODE_ALARM                7001

/*@brief ��/����ҵ����� */
#define  IMOS_SRV_CODE_ALARM_CTRL           7002

/*@brief �澯��ѯҵ����� */
#define  IMOS_SRV_CODE_ALARM_QUERY          7003

/*@brief �������Ϣ��ѯҵ����� */
#define  IMOS_SRV_CODE_CAM_INFO_QUERY       7004

/*@brief ��ѯ�豸��Ϣ���� */
#define  IMOS_SRV_CODE_DEV_INFO_QUERY     7005

/*@brief ��ѯ�豸��Ϣ�������Ӧ */
#define  IMOS_SRV_CODE_DEV_INFO_RES       7006

/*@brief ��ѯ�豸״̬���� */
#define  IMOS_SRV_CODE_DEV_STATIC_QUERY       7007

/*@brief ��ѯ�豸״̬�������Ӧ */
#define  IMOS_SRV_CODE_DEV_STATIC_RES       7008

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XM��Xware����SIP�ӿ� */
/*@brief ������������ϱ����� */
#define  IMOS_SRV_CODE_DEV_ABILITY_CHANGE  7091

/*@brief ҵ�������ϱ����� */
#define  IMOS_SRV_CODE_FUC_ABILITY_CHANGE  7092
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XM��Xware����SIP�ӿ� */

/*@brief �豸����ҵ����� */
#define  IMOS_SRV_CODE_DEVICE_SHARE         8001 /* Added by MultiDomain */

/*@brief ��������ҵ����� */
#define IMOS_SRV_CODE_LAYOUT_RES_SHARE      8002

/*@brief ������Դ��ѯҵ����� */
#define  IMOS_SRV_CODE_RESOURCE_QUERY       8100

/*@brief Ŀ¼�����ϱ�ҵ����� */
#define IMOS_SRV_CODE_SUB_CATALOG           8101

/*Begin added by zhuhongyan 00342 2013-1-23 for ����B���� */
/*@brief �豸Уʱ��������ҵ����� */
#define IMOS_SRV_CODE_SET_DATETIME          8101

/*@brief ��Ƶ�����������ҵ����� */
#define IMOS_SRV_CODE_SET_VIDEOCODE         8102

/*@brief �豸��Դ��������ҵ����� */
#define IMOS_SRV_CODE_SET_RESOURCE          8103

/*@brief Ԥ�õ��������ҵ����� */
#define IMOS_SRV_CODE_SET_PRESET            8104

/*@brief OSD��������ҵ����� */
#define IMOS_SRV_CODE_SET_OSD               8105

/*@brief ��Ƶ�ڵ���������ҵ����� */
#define IMOS_SRV_CODE_SET_VIDEOHIDE         8106

/*@brief �ڵ��澯��������ҵ����� */
#define IMOS_SRV_CODE_SET_COVERALARM         8107

/*@brief �ƶ����澯��������ҵ����� */
#define IMOS_SRV_CODE_SET_MOTIONALARM       8108

/*@brief �豸ʱ�Ӳ�����ѯҵ����� */
#define IMOS_SRV_CODE_QUERY_DATETIME        8151

/*@brief ��Ƶ���������ѯҵ����� */
#define IMOS_SRV_CODE_QUERY_VIDEOCODE       8152

/*@brief �豸��Դ������ѯҵ����� */
#define IMOS_SRV_CODE_QUERY_RESOURCE        8153

/*@brief Ԥ�õ������ѯҵ����� */
#define IMOS_SRV_CODE_QUERY_PRESET          8154

/*@brief OSD������ѯҵ����� */
#define IMOS_SRV_CODE_QUERY_OSD             8155

/*@brief ��ѯ�ڸǱ��� */
#define  IMOS_SRV_CODE_QUERY_VIDEOMASK          8156

/*@brief�ڵ��澯��ѯҵ����� */
#define  IMOS_SRV_CODE_QUERY_COVERDETECT          8157

/*@brief �ƶ���� �澯��ѯҵ����� */
#define  IMOS_SRV_CODE_QUERY_MOTIONDETECT         8158

/*@brief ��ά���� ҵ����� */
#define IMOS_SRV_CODE_3DCONTROLCAMERA             8159
/*End added by zhuhongyan 00342 2013-1-23 for ����B���� Զ�̲�������*/

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
/*@brief �������������豸���������Ϣ ҵ����� */
#define IMOS_SRV_CODE_DETECT_IOT_RES              8201
/* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

/*@brief �����ϱ�ҵ����� */
#define IMOS_SRV_CODE_SUBSCRIBE             9001

/*@brief �������ͬ��ҵ����� */
#define IMOS_SRV_CODE_DOMAIN_DATASYN        9002

/*@brief ��Դ��ѯҵ����� */
#define IMOS_SRV_CODE_QUERY_RES             9003
/*@brief �豸Զ������ */
#define  IMOS_SRV_CODE_TEL_REBOOT           9600

/*@brief ����ҵ����� */
#define IMOS_SRV_CODE_SETGUARD              9601

/*@brief ����ҵ����� */
#define IMOS_SRV_CODE_RESETGUARD            9602

/*@brief ������λҵ����� */
#define IMOS_SRV_CODE_ALARM_RESET           9603

/* Begin Add by zhengyibing(01306), 2014-05-30 for �¹����޸����� */
/*@brief �豸���ò�ѯ */
#define IMOS_SRV_CODE_DEV_CONFIG_QUERY     9604

/*@brief �豸�����·� */
#define IMOS_SRV_CODE_DEV_CONFIG_SET     9605
/* End Add by zhengyibing(01306), 2014-05-30 for �¹����޸����� */

/*@brief ���꿨��ҵ����� */
#define IMOS_SRV_CODE_TG_DISPOSE            9701

/*Begin added by h02674 2016-07-14 for��GBǿ�ƹؼ�֡�����·�MPPD42024*/
/*@brief���͹ؼ�֡*/
#define IMOS_SRV_CODE_KEY_FRAME_SEND        9702
/*End added by h02674 2016-07-14 for��GBǿ�ƹؼ�֡�����·�MPPD42024*/
/*@brief ������Ȩ��ĳ��� */
#define IMOS_LICENSE_AUTHORITY_CODE_LENGTH (32 + 4)

/*@brief �������ͣ��ڸ����� */
#define IMOS_VIDEO_AREA_TYPE_MASK           0

/*@brief �������ͣ��ڵ����� */
#define IMOS_VIDEO_AREA_TYPE_COVER_DETECT   1

/*@brief �������ͣ��ƶ�������� */
#define IMOS_VIDEO_AREA_TYPE_MOTION_DETECT  2

/*@brief ��Ƶ�������ͨ��������� */
#define IMOS_VOUT_CHANNEL_MAXNUM            4

/*@brief ��Ƶ�������ͨ��ȱʡ���� */
#define IMOS_VOUT_CHANNEL_DEFAULT_NUM       1

/*@brief BP֧�ֵ�Ԥ����������ÿ�������������󳤶� */
#define IMOS_MAX_CMD_PARAM_LEN              512

/*@brief BP֧�ֵ�Ԥ����������֧�ֵ����������� */
#define IMOS_MAX_CMD_PARAM_NUM              6

/*@brief gb2312�������� */
#define IMOS_CODE_TYPE_GB2312 "gb2312"

/*@brief utf-8�������� */
#define IMOS_CODE_TYPE_UTF8 "utf-8"

/*@brief gbk�������� */
#define IMOS_CODE_TYPE_GBK "gbk"

/*@brief IMOSĬ���豸���� */
#define IMOS_DEVICE_TYPE_DESC_DEFAULT       "defaultType"

/*@brief IMOS֧�ֵ��豸���͸���(EC/DC/MS/TS/DM/VX500/����ͷ/������/ECR/BM/IPSAN/TMS/����/�������/ͼ��ͻ���) */
#define IMOS_DEVICE_TYPE_NUM                15/* Modified by b00103, 2013-04-01 of MPPD01243 */

/*@brief NTP������ͬ����Ϣ�곤�� */
#define IMOS_NTP_SYNC_STATUS_LEN            32

/*@brief ���������̵�����ID��Сֵ */
#define IMOS_MIN_THIRD_MANUFACTURERID        1

/*@brief ���������̵�����ID���ֵ(�û�������) */
#define IMOS_MAX_THIRD_MANUFACTURER_ID       60000

/*@brief �������豸���͵�����ID��Сֵ */
#define IMOS_MIN_THIRD_DEV_TYPE_ID           20000

/*@brief �������豸���͵�����ID���ֵ(�û�������) */
#define IMOS_MAX_THIRD_DEV_TYPE_ID           40000

/*@brief �������澯���͵�����ID��Сֵ */
#define IMOS_MIN_THIRD_EVT_TYPE_ID           20000

/*@brief �������澯���͵�����ID���ֵ(�û�������) */
#define IMOS_MAX_THIRD_EVT_TYPE_ID           40000

/*@brief �������澯���������ݿ��в����� */
#define IMOS_NO_EXIST_EVENT_TYPE_ID          0

/*@brief �����豸���� */
#define IMOS_DEVICE_TYPE_ALL                 65535

/*@brief ���������̵�����ID���ֵ(�������ó�������) */
#define IMOS_MAX_THIRD_MANUFACTURER_ID_ALL   65535

/*@brief �������豸���͵�����ID���ֵ(���������豸����) */
#define IMOS_MAX_THIRD_DEV_TYPE_ID_ALL       50000

/*@brief �������澯���͵�����ID���ֵ(�������ø澯����) */
#define IMOS_MAX_THIRD_EVT_TYPE_ID_ALL       50000

/*@brief ���Ĺ������������� */
#define IMOS_SUBSC_ITEM_MAX_NUM             8

/* Begin added by baoyihui02795, 2011-04-28 of ������Ŀ */
/** @brief ������Ϣ���ͼƬ���� */
#define IMOS_MAX_VEHICLE_IMG_NUM            4

/*added by a02842 for �����ֶ�MPPD41265��2016-10-14*/
/** @brief ������Ϣ������ͼƬ���� */
#define IMOS_MAX_VEHICLE_IMG_NUM_EX            4

/** @brief ������Ϣ���ԭͼͼƬ������ */
#define IMOS_MAX_VEHICLE_TOTAL_IMG_NUM        (IMOS_MAX_VEHICLE_IMG_NUM + IMOS_MAX_VEHICLE_IMG_NUM_EX)

/** @brief ��������������� */
#define IMOS_MAX_LICENSE_PLATE_NUM          2

/** @brief һ�������Ӧ����󳵵����� */
#define IMOS_MAX_CAMERA_LANE_NUM                      8

/** @brief ��󳵵��������� */
#define IMOS_MAX_LANE_DIRECTION_NUM                   200

/** @brief ȱʡ������������ */
#define IMOS_DEFAULT_LANE_DIRECTION_NUM               2

/** @brief ������������� */
#define IMOS_MAX_VEHICLE_TYPE_NUM                     5
/* End added by baoyihui02795, 2011-04-28 of ������Ŀ */

/* Begin added by b00103, 2012-04-17 of ����D006 */
/** @brief ��󿨿�ͼƬ����������  */
#define IMOS_MAX_TOLLGATE_PHOTO_STOR_SLICE_NUM       16

/** @brief ��󿨿�ͼƬ����������������  */
#define IMOS_MAX_TOLLGATE_PHOTO_LIFT_CYCLE_NUM       16
/* End added by b00103, 2012-04-17 of ����D006 */

/** @brief ����ʱ���ַ�����׼���� */
#define IMOS_DATE_TIME_FORMAT_LEN                    (19)

/*@brief ��ѯ�������� */
#define IMOS_QUERY_ITEM_MAX_NUM2            200

/** @brief ���ƻ���������  */
#define IMOS_MAX_PLAN_PARAM_LEN             128

/*@brief 1���ӵ����� */
#define IMOS_SECOND_IN_MIN                  60

/*@brief 1��Сʱ������ */
#define IMOS_SECOND_IN_HOUR                 3600

/*@brief 1������� */
#define IMOS_SECOND_IN_DAY                 86400

/** @brief һ���澯���Ĺ���֧�ֵ��û�������� */
#define IMOS_ALARM_SEND_USER_MAXNUM         256

/** @brief һ���澯���Ĺ���֧�ֵĵ�����ϵͳ������� */
#define IMOS_ALARM_SEND_THD_SYS_MAXNUM         256

/** @brief һ���澯���Ĺ���֧�ֵĸ澯Դ������� */
#define IMOS_ALARM_SEND_SRC_MAXNUM          4000

/** @brief ϵͳ֧�ֵĸ澯���Ĺ���������� */
#define IMOS_ALARM_SEND_RULE_MAXNUM         3000

/** @brief ��Ϊ��������������� */
#define IMOS_BEHAVIOR_RULE_MAX  8

/** @brief �����ַ������� 16 */
#define IMOS_COORDINATE_STR_LEN_16  16

/** @brief �����ַ������� 56 */
#define IMOS_COORDINATE_STR_LEN_56  56

/* Added by wuchengping02739, 2011-12-16 of VVD63517 */
/** @brief ��Դ����չ��Ϣ���� 1024 */
#define IMOS_RES_GROUP_EXT_LEN 1024

/*@brief WebGisͼ������������ */
#define IMOS_WEBGIS_LAYER_NAME_LEN                   256

/** @brief ���ַ��� */
#define IMOS_NULL_STRING  ""

/* Begin Added by ykf0030, 2012-2-27 of ������Ӧ�� */
/** @brief ECʵ��������Ӧ����Ĭ��ֵ */
#define IMOS_MON_NETWORK_ADAPT_ENABLE_DEFAULT    2

/** @brief EC�洢������Ӧ����Ĭ��ֵ */
#define IMOS_STORE_NETWORK_ADAPT_ENABLE_DEFAULT  2

/* Begin Modified by shaoyili(KF0094), 2012-12-5 of VVD69387 */
/** @brief EC������ӦģʽĬ��ֵ */
#define IMOS_NETWORK_ADAPT_MODE_DEFAULT  0
/* End Modified by shaoyili(KF0094), 2012-12-5 of VVD69387 */

/** @brief ECʵ����������Ӧ�ָ�ʱ��Ĭ��ֵ */
#define IMOS_NETWORK_ADAPT_COUNT_DEFAULT  30
/* End Added by ykf0030, 2012-2-27 of ������Ӧ�� */

/** @brief ��¼onvif����ģ��ע������ */
#define AS_RTDE_MODULE_NAME "AS_RTDE_MOUDLE"

/** @brief ��¼onvif����ģ�� */
#define AS_RTDE_MODULE_CMD_ID 0x07140000

#define IMOS_MAX_WINDOW_NUMBER              256                  /**<�˻���������˿�Ԥ�������������*/

/*@brief EC��������������ֵ*/
#define IMOS_CAM_MAX_NUM                    16

/*@brief �����������չ�ֶγ��� */
#define IMOS_CAM_SHARE_RESERVED_LEN             32  /* added by tangxiaobin00764,2012-10-25 of ��Դ�������������*/

/* Begin: added by zkf0134, 2013.11.22 for �����л�֧������������Ӧ*/
/* �����л�֧������������Ӧ�ر��ٽ�ֵ*/
#define IMOS_SPLIT_SCREEN_SWITCH_CLOSE            0
/* End: added by zkf0134, 2013.11.22 for �����л�֧������������Ӧ*/

/* ��ͨ�¼��ṹ���еĲ�������: ���� ���<���ӿƼ��ǻ�����ͨ��Э��>��<3.3.1  �����͵����ݰ�> */
#define TMS_TRAFFIC_EVENT_PARAM_TYPE_INT  "0"

/* ��ͨ�¼��ṹ���У���������: �ַ��� ���<���ӿƼ��ǻ�����ͨ��Э��>��<3.3.1  �����͵����ݰ�> */
#define TMS_TRAFFIC_EVENT_PARAM_TYPE_STRING  "1"

/* ��ͨ�¼��ṹ���в����������Ŀ */
#define TMS_TRAFFIC_EVENT_MAX_PARAM_NUMBER  4

/* ��ͨ�¼��ṹ����ͼƬ�������Ŀ */
#define TMS_TRAFFIC_EVENT_MAX_PIC_NUMBER     4

/* Begin: Added by lW2822, 2017-03-22 for MPPD45413 ���ܻط� */
/* ����Ȥ������һ��22*18�Ŀ򣬽����·�һ��0/1���ַ�����Ǹ���Ȥ�����м䶺�Ÿ��� */
#define IMOS_QUERY_MOTION_MAX_INTEREST_AREA   792
/* End: Added by lW2822, 2017-03-22 for MPPD45413 ���ܻط� */

/* Begin: Added by l03769, 2017-09-18 for MPPD51328 ��Ƶ���� */
/* ���ܺ����Ƶ����KEY��󳤶�(64�ֽ�) */
#define IMOS_ENCRYPTED_SCRAMBLE_KEY_MAX_LEN  65
/* End: Added by l03769, 2017-09-18 for MPPD51328 ��Ƶ���� */

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
*@enum tagUMUsbDirType
*@brief USBĿ¼����
*/
typedef enum tagUMUsbDirType
{
    UM_USB_DIR_TYPE_FILE,                      /* �ļ� */
    UM_USB_DIR_TYPE_DIR,                       /* Ŀ¼ */
}UM_USB_DIR_TYPE_E;

#define USB_FILE_NAME_LEN               64
#define USB_DIR_NUM                     100
#define USB_DISK_MAX_NUMBER             2         /* U�̸�����ĿǰΪ2�� */
/* End Added by lw0581,2013-11-6 for  VVD06374*/
/** @brief ����rgb,������ɫֵ */
#define COLOR(r, g, b)  ((ULONG_32) (((UCHAR) (r) | ((USHORT) ((UCHAR) (g)) << 8)) | (((ULONG_32) (UCHAR) (b)) << 16)))

/*====== BEGIN: Added by shendongchun 00400 for �û���¼������ǿ, 2012��11��13�� 19:06:00 =====*/
/*@brief �û���¼ʱ����ַ���� */
#define IMOS_MAX_LOGIN_ADDRESS_NUM               (20)

/*@brief ���û���¼��Ϣ����ַ���� */
#define IMOS_MAX_BINDING_ADDRESS_NUM             (50)
/*====== END  : Added by shendongchun 00400 for �û���¼������ǿ, 2012��11��13�� 19:06:00 =====*/
/* Begin Added by w00523, 2012-11-06 for SDC-OSD */
#define MAX_OTHER_HEADER_NUM                                5
#define MAX_EXT_INFO_ATTRIBUTE_NUM                          20
#define MAX_EXT_INFO_ATTR_KEY_LEN                           32
#define MAX_EXT_INFO_ATTR_VALUE_LEN                         128
#define MAX_EXT_INFO_TOTOL_LEN                              512
/* End Added by w00523, 2012-11-06 for SDC-OSD */

/* Begin added by y01359, 2015-01-26 for A8 */
/** @brief A�豸���ͨ�������� */
#define A_CHANNEL_MAX_NUM 512

/** @brief A�豸ͨ���ż�������󳤶� */
#define A_CHANNEL_INDEX_TYPE_LEN 15

/** A8�豸ͨ��������� */
#define A8_CHANNEL_MAX_NUM 48

/* Begin: Modified by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */
/** ����A8�豸����ǽ������� */
#define A8_TV_WALL_MAX_NUM 16
/* End: Modified by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */

/** ��������ǽ�����ʾ��(ƴ����)�� */
#define IMOS_TV_WALL_SCREEN_MAX           128

/** �����������ʾ���ڸ��� */
#define IMOS_TV_WALL_SCREEN_WINDOWS_MAX      4

/** ��������ǽLED �������*/
#define IMOS_TV_WALL_LED_CONTENT_MAX      4

/** ��������ǽ��󴰿ڸ��� */
#define IMOS_TV_WALL_WINDOWS_MAX          (IMOS_TV_WALL_SCREEN_MAX*IMOS_TV_WALL_SCREEN_WINDOWS_MAX)

/** ��������ǽ����ϴ���ͼ�� */
#define IMOS_TV_WALL_BASE_PICTURE_MAX           8

/* End added by y01359, 2015-01-26 for A8 */

#define IMOS_POLYGON_GEO_LEN   1024
#define IMOS_POINT_GEO_LEN   128

/** @brief IMOSȫ��������:IMOS-ALL */
#define IMOS_ALL_DESC "IMOS-ALL"

/** @brief IMOSȫ��������IMOS-ALL���� */
#define IMOS_ALL_DESC_LEN 8

/** @brief IMOSȫ��������VFA=���� */
#define IMOS_VFA_LEN 4

/* Begin: Added by tangxiaobin00764, 2013.3.5  for IVSD00576 of ������IPC�Ż� ����review */
#define IMOS_IPC_CAM_INFO_REVERSED_LEN   512
/* End: Added by tangxiaobin00764, 2013.3.5  for IVSD00576 of ������IPC�Ż� ����review */

/* ¼��ն�ʱ���ݲ�(��λ:��) */
#define IMOS_REC_TIME_TOLERANCE_DIFF        1

/* ��mw_webapi_pub.h����ֲ�����ĺ� */
/* �������Ƶĳ��� */
#define IMOS_NETWORK_CARD_NAME_LEN_FOR_ECR          16
/* ��������������ӿ����� ���ֵΪ16 */
#define IMOS_NETWORK_CARD_PHY_MAXNUM_FOR_ECR        16
/* ����������IP��ַ���� ���ֵΪ4 */
#define IMOS_NETWORK_CARD_IP_ADDR_MAXNUM_FOR_ECR    4
/** �汾�ų��� */
#define IMOS_VERSION_LENTH                          64
/** ip ��ַ��󳤶� */
#define IMOS_IPADDR_LENTH                           40

/* begin added by suzhijie 00294 for NVRV3R1 20130411 */
/*@brief ���ڵص������ַ������� */
#define IMOS_PLACE_NAME_LEN                           256

/*@brief ���ڹ�����¼�������ַ������� ʵ�ʼ�¼������ֵ*/
#define IMOS_TOLLGATE_SPECIAL_LEN                           4

/*@brief ���ڹ�����¼�����������ַ������� */
#define IMOS_TOLLGATE_SPECIAL_NAME_LEN                           68

/*@brief ���ڹ�����¼������ID�ַ������� */
#define IMOS_TOLLGATE_SPECIAL_ID_LEN                           20

/*@brief ���ڹ�����¼����ͨ���볤��*/
#define IMOS_TOLLGATE_CODE_LEN                           36

/*@brief UM ��ѯU���ļ���Ŀ¼������*/
#define UM_USB_DIR_NUM                     100
/* end added by suzhijie 00294 for NVRV3R1 20130411 */

/* begin added by suzhijie 00294 for NVRV3R1 20130329 */
/** @brief ������Ϣ���ͼƬ���� */
#define IMOS_MAX_VEHICLE_IMG_NUM_FOR_ECR    6

/*@brief ������Ϣ���ͼƬ���Ƴ��� */
#define IMOS_MAX_VEHICLE_IMG_NAME_LEN       260
/* end added by suzhijie 00294 for NVRV3R1 20130329 */

/* Begin: added by liuhongjieKF0170, 2013-9-4 of IPC֧������OSD */
#define IMOS_IPC_SERIAL_PORT_MAX_NUM       5
#define IMOS_XML_EXPAND_DESC_LEN           IMOS_STRING_LEN_32
#define IMOS_IPC_OSD_MAXNUM                8
#define IMOS_IPC_OSD_BLOCK_MAXNUM   8
#define IMOS_IPC_OSD_BLOCK_MAXNUM_III   3
#define IMOS_IPC_OSD_VERSSION_ONE     "VersionV01"
#define IMOS_IPC_MAX_ROI_NUM               4
/* End: added by liuhongjieKF0170, 2013-9-4 of IPC֧������OSD */

/* Begin: addedBy liuhongjieKF0170, 2013-9-27  IPC֧������OSD */
#define IMOS_IPC_OSD_SUPPORT_MIB_FLG  ";17.1.2.1"
/* End: addedBy liuhongjieKF0170, 2013-9-27  IPC֧������OSD */

/* Begin Add by zhouquanwei/z01364 2013-11-08 of onvif֧�ֶ�profile */
/*@brief onvif profile �����Ŀ */
#define IMOS_ONVIF_PROFILE_MAX   8

/*@brief onvif profile ������:Ŀǰ������������*/
#define IMOS_ONVIF_STREAM_MAX    2
/* End Add by zhouquanwei/z01364 2013-11-08 of onvif֧�ֶ�profile */

/* Begin: Added by zhongke, 2015-02-27 for CDS�ƴ洢 */
#define IMOS_CDS_SERVER_UDP_PORT           8887
/* End: Added by zhongke, 2015-02-27 for CDS�ƴ洢 */
/* Begin added by m01736 2015.12.4 for NAT��Խ */
/** @brief DDNS�豸���кų��Ȱ����豸ID�������*/
#define IMOS_DEV_SERIAL_NUM_LEN         128

/** @brief DDNS������ַ�������*/
#define IMOS_RAND_NUM_LEN         32

/** @brief ������Ϣ�ַ�������*/
#define IMOS_DDNS_DOMAIN_LEN         256

/** @brief ����HTTP��Ϣ��URL��ַ����*/
#define IMOS_DDNS_URL_LEN         256
/* End added by m01736 2015.12.4 for NAT��Խ */

/* Begin: add by l01420, 2016-03-22 for MPPD35824*/
/*@brief �ؽ�����ʶ*/
#define IMOS_REBUILD_STREAM    1000

/*@brief �ؽ������(s)*/
#define IMOS_REBUILD_STREAM_DEFAULT_INTERVAL    1
/* End: add by l01420, 2016-03-22 for MPPD35824*/

/* Begin added by c02845,2016-05-12,��ͨ����Ϣ������������ */
#define IMOS_TRAFFIC_FLOW_LANE_MAX_NUM (4 * 8 * 7)

/* ��ͨ����ѯʱ���Ŀ������� */
#define IMOS_TRAFFIC_FLOW_TOLLGATE_MAX_NUM  8

/* ���ꡢ�¡��ղ�ѯ���ص��������(���ֳ���) */
#define  IMOS_TRAFFIC_FLOW_LIST_MAX_NUM     32
/* End added by c02845,2016-05-12,��ͨ����Ϣ������������ */

/*Begin added by a02842 for whitelist extension,2017-02-23*/
/*@brief ��������չ��Դ�б��ַ�������*/
#define IMOS_WHITELIST_RES_LEN    (IMOS_CODE_LEN * IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM)

/*@brief ��������չΥ�������б���󳤶�*/
#define IMOS_WHITELIST_ALARMTYPE_MAX_NUM   200

/*@brief ��������չΥ�������б��ַ�������*/
#define IMOS_WHITELIST_ALARMTYPE_LEN    (IMOS_DICTIONARY_KEY_LEN * IMOS_WHITELIST_ALARMTYPE_MAX_NUM)
/*End added by a02842 for whitelist extension,2017-02-23*/

/*@brief ����MAC��������������*/
#define IMOS_MAC_IDENTIFY_INFO_MAX_NUM      64

/*Begin added by a02842 for MultyFeatureType,2017-12-26*/
/*@brief ͨ��features �ַ��� ����*/
#define IMOS_FEATURES_LEN           102400
/*End added by a02842 for MultyFeatureType,2017-12-26*/

/* Begin: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */
/*@brief ������ӵ���������Ŀ */
#define IMOS_MAX_CABIN_NUM           10

/*@brief һ�������������ܰ�10��������� */
#define IMOS_BIND_FIRE_ZONE_MAX_NUM  10

/*@brief һ�������������ܰ�30������ */
#define IMOS_BIND_CABIN_MAX_NUM      30

/*@brief һ����������ܰ�200����Դ */
#define IMOS_BIND_RES_MAX_NUM        200

/*@brief �������һ�β�32����Դ��ʵʱ���� */
#define IMOS_QUERY_RES_REAL_TIME_DATA_MAX_NUM        32
/* End: Added by l03769, 2017-11-07 for MPPD52823 �����ۺϹ������Ժ�̨����B3328 */

/* Begin add by liucanming/03903, 2017-09-18 for MPPD54245 A8 ����Ѳ */
/** @brief A8ƴ����Ѳ����������������Ѳ��Դ�������*/
#define IMOS_POLL_IN_SCENE_MAX_NUM_EX  8

/** @brief ����ǽ����󳡾�����*/
#define IMOS_SCENE_MAX_NUM_EX 32

/** @brief ����ǽ����Ѳ��Դ�����*/
#define IMOS_POLL_RES_MAX_NUM_EX 256
/* End add by liucanming/03903, 2017-09-18 for MPPD54245 A8 ����Ѳ */

/* Begin: Added by l03769, 2017-12-21 for MPPD53844 ��������Դ������� */
/*@brief �������һ����������Ӱ���Դ����Ϊ200 */
#define IMOS_IOT_DEV_BIND_RES_MAX_NUM        200
/* End: Added by l03769, 2017-12-21 for MPPD53844 ��������Դ������� */

/* Begin added by gaopan/W4627, 2018-3-7 for �����ͻ����������ǽʱ�ܹ�����ǽ����ʷ��¼���� MPPD56781*/
#define IMOS_SCREEN_SPLIT_PAGE_MAX_NUM    1000
/* End added by gaopan/W4627, 2018-3-7 for �����ͻ����������ǽʱ�ܹ�����ǽ����ʷ��¼���� MPPD56781*/


/**
 * @enum tagIMOSBehaviorType
 * @brief ��Ϊ����
 * @attention
 */
typedef enum tagIMOSBehaviorType
{
    IMOS_BEHAVIOR_TYPE_THRU_LINE    = 0,    /**< ���� */
    IMOS_BEHAVIOR_TYPE_INOUT_AREA   = 1,    /**< �������� */

    IMOS_BEHAVIOR_TYPE_MAX,
    IMOS_BEHAVIOR_TYPE_INVALID      = 0XFFFFFFFF
} IMOS_BEHAVIOR_TYPE_E;

/** �豸����״̬ö�� */
typedef enum tagIMOSDevExtStatus
{
    IMOS_EXT_STATUS_NORMAL   = 0,                /**< ����״̬ */
    IMOS_EXT_STATUS_VIDEO_LOST_RESUME = 1,       /**< ��Ƶ�ָ� */
    IMOS_EXT_STATUS_VIDEO_LOST = 2,              /**< ��Ƶ��ʧ */
    IMOS_EXT_STATUS_MAX,                         /**< ���ֵ */
    IMOS_EXT_STATUS_INVALID    = 0xFFFFFFFF      /**< ��Чֵ */
}IMOS_DEV_EXT_STATUS_E;

/* Begin added by lijiangkun lW4644 for MPPD56103 ,Feb 01, 2018 */
/**
* @enum tagIMOSPicUrlNum
* @brief  �豸����״̬ö��
* @attention ��
*/
typedef enum tagIMOSPicUrlNum
{
    IMOS_TMS_URL0   = 0,                    /**< urlͼƬ����0 */
    IMOS_TMS_URL1   = 1,                    /**< urlͼƬ����1 */
    IMOS_TMS_URL2   = 2,                    /**< urlͼƬ����2 */
    IMOS_TMS_URL3   = 3,                    /**< urlͼƬ����3 */
}IMOS_PIC_URL_NUM_E;
/* End added by lijiangkun lW4644 for MPPD56103 ,Feb 01, 2018 */

/* Begin added by lijiangkun lW4644 for MPPD54193 ,Feb 25, 2018 */
/**
* @enum tagIMOSPICFace
* @brief  DBE ����thrift��������ö��
* @attention ��
*/
typedef enum tagIMOSPICFace
{
    IMOS_FACE_PICPANORAMA = 1,            /* ��������2016������-ȫ��ͼ */
    IMOS_FACE_PICFACE = 2,                /* ��������2016������-����ͼ */

    IMOS_FACE_PIC_MAX,                    /* ���ֵ */
}IMOS_PIC_FACE_E;

/**
* @enum tagIMOSPICFace
* @brief  IAVAS�ɼ�����ö��
* @attention ��
*/
typedef enum tagIMOSIAVASEquipmentTYPE
{
    IMOS_IAVAS_EQUIPMENTTYPE7 = 7,            /* �ɼ�����-07-��ͨ�ṹ�� */
    IMOS_IAVAS_EQUIPMENTTYPE8 = 8,            /* �ɼ�����-08-��ؽṹ�� */

    IMOS_IAVAS_EQUIPMENTTYPE_MAX,             /* ���ֵ */
}IMOS_IAVAS_EQUIPMENTTYPE_E;

/**
* @enum tagIMOSThriftType
* @brief  DBE ����thrift��������ö��
* @attention ��
*/
typedef enum tagIMOSThriftType
{
    IMOS_THRIFT_TYPE_FACE = 1,               /* ����������ͼ��thrift����0-�˿ں�9100 */
    IMOS_THRIFT_TYPE_IAVAS = 2,              /* �����ṹ��-������thrift����0-�˿ں�9100 */

    IMOS_THRIFT_TYPE_MAX                     /* ���ֵ */
}IMOS_THRIFT_TYPE_E;

/*** begin�ṹ������ TMS ���Կ���-��Ա��Ҫת�����ֶ� */
/**
* @enum tagIMOSHatFlag
* @brief  �㷨���޴�ñ��ö��
* @attention ��
*/
typedef enum tagIMOSHatFlag
{
    IAVAS_NO = 0,           /** ��ñ�� */
    IAVAS_YES = 1,          /** ��ñ�� */
    IAVAS_UNKNOWN = 99      /** �쳣 */
}IMOS_HAT_FLAG_E;

/**
* @enum tagIMOSUnvHatFlag
* @brief  ����Э�������޴�ñ��
* @attention ��
*/
typedef enum tagIMOSUnvHatFlag
{
    IAVAS_UNV_YES = 1,      /** ��ñ�� */
    IAVAS_UNV_NO = 2,       /** ��ñ�� */
    IAVAS_UNV_UNKNOWN = 99  /** �쳣 */
}IMOS_UNVHAT_FLAG_E;

/**
* @enum tagIMOSGenderType
* @brief  �㷨ö���Ա�
* @attention ��
*/
typedef enum tagIMOSGenderType
{
    IAVAS_MALE = 0,             /** ���� */
    IAVAS_FEMALE = 1,           /** Ů�� */
    IAVAS_UNKNOWN_GENDER = 99   /** �쳣 */
}IMOS_GENDER_TYPE_E;

/**
* @enum tagIMOSUnvGenderType
* @brief  ����Э���׼ö���Ա�
* @attention ��
*/
typedef enum tagIMOSUnvGenderType
{
    IAVAS_UNV_MALE = 1,             /** ���� */
    IAVAS_UNV_FEMALE = 0,           /** Ů�� */
    IAVAS_UNV_UNKNOWN_GENDER = 98   /** �쳣 */
}IMOS_UNVGENDER_TYPE_E;

/**
* @enum tagIMOSPersonAttrUpClothType
* @brief  �㷨ö�����¿�ʽ
* @attention ��
*/
typedef enum tagIMOSPersonAttrUpClothType
{
    IAVAS_UPCLOTHTYPE_COTTA = 0,           /** ��Ӧ<CoatStyle>3</CoatStyle>--T�� */
    IAVAS_UPCLOTHTYPE_LONG_SLEEVE = 1,     /** ��Ӧ<CoatStyle>5</CoatStyle>--���� */
    IAVAS_UPCLOTHTYPE_UNKNOWN = 99         /** ��Ӧ<CoatStyle>99</CoatStyle>--���� */
}IMOS_PERSONATTR_UPCLOTHTYPE_E;

/**
* @enum tagIMOSUnvPersonAttrUpClothType
* @brief  Э���Ӧ���¿�ʽ
* @attention ��
*/
typedef enum tagIMOSUnvPersonAttrUpClothType
{
    IAVAS_UNV_UPCLOTHTYPE_COTTA = 3,        /** T�� */
    IAVAS_UNV_UPCLOTHTYPE_LONG_SLEEVE = 5,  /** ���� */
    IAVAS_UNV_UPCLOTHTYPE_UNKNOWN = 99      /** ���� */
}IMOS_UNVPERSONATTR_UPCLOTHTYPE_E;

/**
* @enum tagIMOSColorType
* @brief  �㷨��Ӧö������������ɫ
* @attention ��
*/
typedef enum tagIMOSColorType
{
    IAVAS_BLACK = 0,
    IAVAS_WHITE = 1,
    IAVAS_RED = 2,
    IAVAS_GREEN = 3,
    IAVAS_BLUE = 4,
    IAVAS_YELLOW = 5,
    IAVAS_PURPLE = 6,
    IAVAS_GRAY = 7,
    IAVAS_ORANGE = 8,
    IAVAS_BROWN = 9,
    IAVAS_PINK = 10,
    IAVAS_UNKNOWN_COLOR = 99
}IMOS_COLOR_TYPE_E;

/**
* @enum tagIMOSUnvColorType
* @brief  Э���Ӧ����������ɫ
* @attention ��
*/
typedef enum tagIMOSUnvColorType
{
    IAVAS_UNV_UNKNOWN_COLOR   = 0x01,
    IAVAS_UNV_GRAY            = 0x010,
    IAVAS_UNV_BLACK           = 0x020,
    IAVAS_UNV_BROWN           = 0x040,
    IAVAS_UNV_WHITE           = 0x080,
    IAVAS_UNV_PINK            = 0x0100,
    IAVAS_UNV_PURPLE          = 0x0200,
    IAVAS_UNV_BLUE            = 0x0400,
    IAVAS_UNV_UNKNOWN_COLOR2  = 0x0800,
    IAVAS_UNV_GREEN           = 0x01000,
    IAVAS_UNV_YELLOW          = 0x02000,
    IAVAS_UNV_ORANGE          = 0x04000,
    IAVAS_UNV_RED             = 0x08000
}IMOS_UNVCOLOR_TYPE_E;

/**
* @enum tagIMOSPersonAttrDnClothType
* @brief  �㷨��Ӧö�ٿ��ӿ�ʽ
* @attention ��
*/
typedef enum tagIMOSPersonAttrDnClothType
{
    IAVAS_DNCLOTHTYPE_SHORTS = 0,          /** ��Ӧ<TrousersStyle>9</TrousersStyle>--�̿�ͷ */
    IAVAS_DNCLOTHTYPE_TROUSERS = 1,        /** ��Ӧ<TrousersStyle>1</TrousersStyle>--ţ�п� */
    IAVAS_DNCLOTHTYPE_UNKNOWN = 99         /** ��Ӧ<TrousersStyle>99</TrousersStyle>--���� */
}IMOS_PERSONATTR_DNCLOTHTYPE_E;

/**
* @enum tagIMOSUnvPersonAttrDnClothType
* @brief  Э���Ӧ���ӿ�ʽ
* @attention ��
*/
typedef enum tagIMOSUnvPersonAttrDnClothType
{
    IAVAS_UNV_DNCLOTHTYPE_SHORTS = 9,       /** �̿�ͷ */
    IAVAS_UNV_DNCLOTHTYPE_TROUSERS = 1,     /** ţ�п� */
    IAVAS_UNV_DNCLOTHTYPE_UNKNOWN = 99      /** ���� */
}IMOS_UNVPERSONATTR_DNCLOTHTYPE_E;

/**
* @enum tagIMOSPersonAttrShoesType
* @brief  �㷨��Ӧö��Ь�ӿ�ʽ
* @attention ��
*/
typedef enum tagIMOSPersonAttrShoesType
{
    IAVAS_SHOESTYPE_LOW = 0,      /** ��Ӧ<ShoesStyle>6</ShoesStyle>--����Ь */
    IAVAS_SHOESTYPE_HIGH = 1,     /** ��Ӧ<ShoesStyle>7</ShoesStyle>--��Ͳѥ */
    IAVAS_SHOESTYPE_UNKNOWN = 99 /** ��Ӧ<ShoesStyle>99</ShoesStyle>--���� */
}IMOS_PERSONATTR_SHOES_E;

/**
* @enum tagIMOSUnvPersonAttrShoesType
* @brief  Э���ӦЬ�ӿ�ʽ
* @attention ��
*/
typedef enum tagIMOSUnvPersonAttrShoesType
{
    IAVAS_UNV_SHOESTYPE_LOW = 6,      /** ����Ь */
    IAVAS_UNV_SHOESTYPE_HIGH = 7,     /** ��Ͳѥ */
    IAVAS_UNV_SHOESTYPE_UNKNOWN = 99  /** ���� */
}IMOS_UNVPERSONATTR_SHOES_E;

/**
* @enum tagIMOSPersonAttrBagType
* @brief  �㷨��Ӧö�ٰ���ʽ
* @attention ��
*/
typedef enum tagIMOSPersonAttrBagType
{
    IAVAS_BAGTYPE_NONE = 0,
    IAVAS_BAGTYPE_HAND = 1,     /** ��Ӧ<BagStyle>2</BagStyle>--����� */
    IAVAS_BAGTYPE_BACK = 2,     /** ��Ӧ<BagStyle>3</BagStyle>--˫��� */
    IAVAS_BAGTYPE_UNKOWN = 99 /** ��Ӧ<BagStyle>99</BagStyle>--���� */
}IMOS_PERSONATTR_BAGTYPE;

/**
* @enum tagIMOSUnvPersonAttrBagType
* @brief  Э���Ӧ����ʽ
* @attention ��
*/
typedef enum tagIMOSUnvPersonAttrBagType
{
    IAVAS_UNV_BAGTYPE_HAND = 2,     /** ����� */
    IAVAS_UNV_BAGTYPE_BACK = 3,     /** ˫��� */
    IAVAS_UNV_BAGTYPE_UNKOWN = 99   /** ���� */
}IMOS_UNVPERSONATTR_BAGTYPE;

/*** end �ṹ������ TMS ���Կ���-��Ա��Ҫת�����ֶ� */
/*** begin�ṹ������ TMS ���Կ���-��������Ҫת�����ֶ� */

/**
* @enum tagIMOSVehicleAttr_VehicleType
* @brief  �������Ͷ�Ӧö�� ����Э��δ֪������4����Ҫת��Ϊ�㷨ö��ֵ0�����������㷨��Э����һ�µ�
* @attention ��
*/
enum tagIMOSVehicleAttr_VehicleType
{
    IAVAS_VehicleAttr_VehicleType_UNKNOWN_VEHICLE_TYPE = 0, /** ��Ӧ<VehicleType>4</VehicleType> */
    IAVAS_VehicleAttr_VehicleType_SEDAN = 11,
    IAVAS_VehicleAttr_VehicleType_SUV = 12,
    IAVAS_VehicleAttr_VehicleType_MINIBUS = 13,
    IAVAS_VehicleAttr_VehicleType_BUGGY = 14,
    IAVAS_VehicleAttr_VehicleType_MIDBUS = 15,
    IAVAS_VehicleAttr_VehicleType_BIGBUS = 16,
    IAVAS_VehicleAttr_VehicleType_BIGTRUCK = 17,
    IAVAS_VehicleAttr_VehicleType_PICKUP = 18,
    IAVAS_VehicleAttr_VehicleType_MPV = 19,
};
/*** end�ṹ������ TMS ���Կ�����-��������Ҫת�����ֶ� */
/* End added by lijiangkun lW4644 for MPPD54193 ,Jan 03, 2018 */
/**
* @enum tagIMOSDevBelongAttr
* @brief  �豸��������ö��
* @attention ��
*/
typedef enum tagIMOSDevBelongAttr
{
    IMOS_DEV_LOCAL = 0,                        /**< ���ڱ�����豸 */
    IMOS_DEV_FOREIGN = 1,                      /**< ����������豸 */
    IMOS_DEV_BELONG_ALL = 2,                   /**< �����豸 */
    IMOS_DEV_BELONG_MAX,                       /**< ���ֵ */
    IMOS_DEV_BELONG_INVALID = 0xFFFFFFFF       /**< ��Чֵ */
}IMOS_DEV_BELONG_ATTR;

/**
* @enum tagIMOSFaultDevStatus
* @brief  �豸����״̬ö��ѡ��
* @attention ��
*/
typedef enum tagIMOSFaultDevStatus
{
    IMOS_DEV_FAULT_STATUS_ONLINE = 0,          /**< �豸�������� */
    IMOS_DEV_FAULT_STATUS_FAULT = 1,           /**< �豸���߹��� */
    IMOS_DEV_FAULT_STATUS_OFFLINE = 2,         /**< �豸���� */
    IMOS_DEV_FAULT_STATUS_ALL = 3,             /**< �豸����״̬ */
    IMOS_DEV_FAULT_STATUS_MAX,                 /**< ���ֵ */
    IMOS_DEV_FAULT_STATUS_INVALID = 0xFFFFFFFF /**< ��Чֵ */
}IMOS_DEV_FAULT_STATUS_E;

/**
* @enum tagIMOSDomainDevType
* @brief ���豸����(��Ʒ����������,���Ӳ�Ʒ�Ƕ����ܿ��������豸����)
* @attention
*/
typedef enum tagIMOSDomainDevType
{
    IMOS_DOMAIN_DEV_TYPE_DA          = 0,        /**< DA */
    IMOS_DOMAIN_DEV_TYPE_DVR         = 1,        /**< DVR */
    IMOS_DOMAIN_DEV_TYPE_NVR         = 2,        /**< NVR */
    IMOS_DOMAIN_DEV_TYPE_PLS         = 3,        /**< PL-S */
    IMOS_DOMAIN_DEV_TYPE_V3VM        = 4,        /**< V3VM */
    IMOS_DOMAIN_DEV_TYPE_ISC3000E    = 5,        /**< ISC3000-E */

    IMOS_DOMAIN_DEV_TYPE_MAX,                    /**< ���ֵ */
    IMOS_DOMAIN_DEV_TYPE_INVALID     = 0xFFFF    /**< ��Чֵ */
} IMOS_DOMAIN_DEV_TYPE_E;

/**
* @enum tagIMOSDBConnectionNum
* @brief ���ݿ����Ӻ���
* @attention ��
*/
typedef enum tagIMOSDBConnectionNum
{
    IMOS_DB_CONNECTION_CM = 1,                  /**< ����ģ�����ݿ����Ӻ��� */
    IMOS_DB_CONNECTION_RS = 2,                  /**< ����ģ�����ݿ����Ӻ��� */
    IMOS_DB_CONNECTION_SM = 3,                  /**< ����ģ�����ݿ����Ӻ��� */
    IMOS_DB_CONNECTION_MAX,                     /**< ���ֵ */
    IMOS_DB_CONNECTION_INVALID = 0xFFFFFFFF     /**< ��Чֵ */
}IMOS_DB_CONNECTION_NUM_E;

/**
* @enum tagIMOSDomainDeviceType
* @brief ���豸����(����VM�豸,Ϊ��Ʒ����������)
* @attention
*/
typedef enum tagIMOSDomainDeviceType
{
    /* VM�豸(����"IMOSƽ̨һ�״���"������,��Ʒ���γɵ��豸)������:0��99 */
    IMOS_DOMAIN_DEVICE_TYPE_VM8500      = 0,       /**< VM8500 */
    IMOS_DOMAIN_DEVICE_TYPE_VM5500      = 1,       /**< VM5500 */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3308HF   = 2,       /**< ECR3308-HF */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HF   = 3,       /**< ECR3316-HF */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3000E    = 4,       /**< ISC3000-E */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3000S    = 5,       /**< ISC3000-S */
    IMOS_DOMAIN_DEVICE_TYPE_PL          = 6,       /**< PL */
    IMOS_DOMAIN_DEVICE_TYPE_PLS         = 7,       /**< PL-S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC6000     = 8,       /**< ISC6000 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC3500E    = 9,       /**< ISC3500-E */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500S    = 10,       /**< ISC3500-S */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3308HFE   = 11,       /**< ECR3308-HF-E */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HFE   = 12,       /**< ECR3316-HF-E */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3308HFS   = 13,       /**< ECR3308-HF-S */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HFS   = 14,       /**< ECR3316-HF-S */
    /* Added by zhangjiarui/03328 2017-03-02 for MPPD38663 */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HFSC = 15,        /**< ECR3316-HF-SC */

    /* Begin: added by lw0581, 2013.12.19 for  MPPD06992 */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000_S    = 27,          /**< ISC5000_S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000_E    = 28,          /**< ISC5000_E */
    /* End: added by lw0581, 2013.12.19 for  MPPD06992 */

    IMOS_DOMAIN_DEVICE_TYPE_VM9500   = 29,          /**< VM9500 */
    IMOS_DOMAIN_DEVICE_TYPE_VM2500   = 30,          /**< VM2500 */
    IMOS_DOMAIN_DEVICE_TYPE_VM3500   = 31,          /**< VM3500 */
    IMOS_DOMAIN_DEVICE_TYPE_VM5800   = 32,          /**< VM5800 */
    IMOS_DOMAIN_DEVICE_TYPE_VM7500   = 33,          /**< VM7500 */


    /* H3C�������豸:100�� */
    IMOS_DOMAIN_DEVICE_TYPE_DA8500      = 100,     /**< DA8500 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC3500ET    = 1020,       /**< ISC3500-ET */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500EL    = 1021,       /**< ISC3500-EL */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500ST    = 1022,       /**< ISC3500-ST */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500SL    = 1023,       /**< ISC3500-SL */

    IMOS_DOMAIN_DEVICE_TYPE_ECR2104HF    = 7001,       /**< ECR2108-HF */
    IMOS_DOMAIN_DEVICE_TYPE_ECR2108HF    = 7002,       /**< ECR2108-HF */

    /* Begin: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR���� */
    IMOS_DOMAIN_DEVICE_TYPE_ECR_ALL    = 7000,       /**< ECR���� */
    IMOS_DOMAIN_DEVICE_TYPE_NVR_ALL    = 8000,       /**< NVR���� */
    /* End: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR���� */

    IMOS_DOMAIN_DEVICE_TYPE_ISC2500SP    = 8001,       /**< ISC2500-SP */
    IMOS_DOMAIN_DEVICE_TYPE_ISC2500EP    = 8002,       /**< ISC2500-EP */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000S     = 8003,       /**< ISC5000-S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000E     = 8004,       /**< ISC5000-E */
    IMOS_DOMAIN_DEVICE_TYPE_ISC2500S     = 8005,       /**< ISC2500-S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC2500E     = 8006,       /**< ISC2500-E */

    IMOS_DOMAIN_DEVICE_TYPE_ISC3500E_B05     = 8007,     /**< ISC3500-E_B05 */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500S_B05     = 8008,     /**< ISC3500-S_B05 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC2500SCT    = 8100,     /**<ISC2500-SCT */

    IMOS_DOMAIN_DEVICE_TYPE_CVS5516      = 10001,     /**< CVS5516 */

    IMOS_DOMAIN_DEVICE_TYPE_MAX,                   /**< ���ֵ */
    IMOS_DOMAIN_DEVICE_TYPE_INVALID     = 0xFFFF   /**< ��Чֵ */
} IMOS_DOMAIN_DEVICE_TYPE_E;

/**
* @enum tagIMOSBooleanType
* @brief ����������
* @attention ��
*/
typedef enum tagIMOSBooleanType
{
    IMOS_BOOLEAN_TYPE_IN = 0,                   /**< ���뿪���� */
    IMOS_BOOLEAN_TYPE_OUT = 1,                  /**< ��������� */
    IMOS_BOOLEAN_TYPE_NONE = 2,                 /**< ���п��������� */

    IMOS_BOOLEAN_TYPE_MAX,                      /**< ���ֵ */
    IMOS_BOOLEAN_TYPE_INVALID = 0xFFFFFFFF      /**< ��Чֵ */
}IMOS_BOOLEAN_TYPE_E;

/**
* @name ���豸����(�ַ���ֵ)
* @{
*/
/* Begin: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR���� */
/** @brief ECR����*/
#define IMOS_DOMAIN_DEV_TYPE_ECR_ALL        "ECR_ALL"

/** @brief NVR����*/
#define IMOS_DOMAIN_DEV_TYPE_NVR_ALL        "ISC_ALL"
/* End: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR���� */

/** @brief H3C ISC6000 */
#define IMOS_DOMAIN_DEV_TYPE_ISC6000_STR        "H3C-ISC6000"

/** @brief H3C VM8500 */
#define IMOS_DOMAIN_DEV_TYPE_VM8500_STR         "H3C-VM8500"

/** @brief H3C VM9500 */
#define IMOS_DOMAIN_DEV_TYPE_VM9500_STR         "H3C-VM9500"

/** @brief H3C VM5500 */
#define IMOS_DOMAIN_DEV_TYPE_VM5500_STR         "H3C-VM5500"

/** @brief H3C ECR3308HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR3308HF_STR      "H3C-ECR3308HF"

/** @brief H3C ECR3316HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_STR      "H3C-ECR3316HF"

/** @brief H3C ECR3308HF_E */
#define IMOS_DOMAIN_DEV_TYPE_ECR3308HF_E_STR    "H3C-ECR3308HF-E"

/** @brief H3C ECR3316HF_E */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_E_STR    "H3C-ECR3316HF-E"

/** @brief H3C ECR3308HF_S */
#define IMOS_DOMAIN_DEV_TYPE_ECR3308HF_S_STR    "H3C-ECR3308HF-S"

/** @brief H3C ECR3316HF_S */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_S_STR    "H3C-ECR3316HF-S"

/* Added by zhangjiarui/03328 2017-03-02 for MPPD38663 */
/** @brief H3C ECR3316HF_SC */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_SC_STR   "ECR3316-HF-SC"

/** @brief ECR2108HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR2108HF_STR      "ECR2108_HF"

/** @brief ECR2104HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR2104HF_STR      "ECR2104_HF"

/** @brief ISC3500_ET */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500ET          "ISC3500_ET"

/** @brief ISC3500_EL */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500EL          "ISC3500_EL"

/** @brief ISC3500_ST */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500ST          "ISC3500_ST"

/** @brief ISC3500_SL */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500SL          "ISC3500_SL"

/** @brief ISC3500-E_B05 */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500E_B05       "ISC3500-E_B05"

/** @brief ISC3500-S_B05 */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500S_B05       "ISC3500-S_B05"

/** @brief ISC2500_SP */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500SP          "ISC2500_SP"

/** @brief ISC2500_EP */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500EP          "ISC2500_EP"

/** @brief ISC2500_S */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500S           "ISC2500_S"

/** @brief ISC2500_E */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500E           "ISC2500_E"

/** @brief ISC5000_S */
#define IMOS_DOMAIN_DEV_TYPE_ISC5000S           "ISC5000_S"

/** @brief ISC5000_E */
#define IMOS_DOMAIN_DEV_TYPE_ISC5000E           "ISC5000_E"

/** @brief ISC2500-SCT */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500SCT         "ISC2500-SCT"

/** @brief H3C VM8000 */
#define IMOS_DOMAIN_DEV_TYPE_VM8000_STR         "H3C-VM8000"

/** @brief H3C VM5000 */
#define IMOS_DOMAIN_DEV_TYPE_VM5000_STR         "H3C-VM5000"

/** @brief H3C ISC3000 */
#define IMOS_DOMAIN_DEV_TYPE_ISC3000_STR        "H3C-ISC3000"

/** @brief H3C ISC3000-E */
#define IMOS_DOMAIN_DEV_TYPE_ISC3000E_STR       "H3C-ISC3000-E"

/** @brief H3C ISC3000-S */
#define IMOS_DOMAIN_DEV_TYPE_ISC3000S_STR       "H3C-ISC3000-S"

/** @brief H3C DA8500 */
#define IMOS_DOMAIN_DEV_TYPE_DA8500_STR         "H3C-DA8500"

/** @brief Aproud PL */
#define IMOS_DOMAIN_DEV_TYPE_PL_STR             "Aproud-PL"

/** @brief Aproud PL-S */
#define IMOS_DOMAIN_DEV_TYPE_PLS_STR            "Aproud-PL-S"

/** @brief Aproud ONU */
#define IMOS_DOMAIN_DEV_TYPE_ONU_STR            "Aproud-ONU"

/* Added by zhangjiarui/03328 2017-03-02 for MPPD44239 */
#define IMOS_DOMAIN_DEV_TYPE_CVS5516_STR        "CVS5516"
/* End Added by zhangjiarui/03328 2017-03-02 for MPPD44239 */

/** @brief ��H3C���� */
#define IMOS_DOMAIN_DEV_TYPE_OTHER_STR          "Other"
/** @} */

/* Added by MultiDomain */
/** @brief SGĬ�ϱ��� */
#define IMOS_AS_DEFAULT_SG_CODE                   "SG0000"

/** @brief ECPAGGUOBIAOĬ�ϱ��� */
#define IMOS_DEFAULT_PAG_GB_CODE                "ECPAGGUOBIAO"

/** @brief ECPAGIMOSCODEĬ�ϱ��� */
#define IMOS_DEFAULT_PAG_IMOS_CODE              "ECPAGIMOSCODE"

/* Begin added by j00350 for MPPD08948, 20140120 */
/** @brief ECPAGMOBILEĬ�ϱ��� */
#define IMOS_DEFAULT_PAG_MOBILE_CODE            "ECPAGMOBILE"          /* MOBILE */
/* End added by j00350 for MPPD08948, 20140120 */

/* Begin Add By wenduanqiang/wW2834 for onvif����NVR����λ���� 2015-9-18 */
#define IMOS_DEFAULT_ONVIF10       "ONVIF1.0"      /**< ONVIF1.0 */
#define IMOS_DEFAULT_ONVIF20       "ONVIF2.0"      /**< ONVIF2.0 */
#define IMOS_DEFAULT_ONVIF21       "ONVIF2.1"      /**< ONVIF2.1 */
/* End Add By wenduanqiang/wW2834 for onvif����NVR����λ���� 2015-9-18 */

/* add by g00351, 2013-04-22 for ������license���� */

/** @brief ������Ϣ��Manufacturer�ֶε�uniview�ַ��� */
#define  IMOS_MANUFACTURER_UNIVIEW_SRT     "uniview"

/** @brief ������Ϣ��Manufacturer�ֶε�h3c�ַ��� */
#define  IMOS_MANUFACTURER_H3C_SRT          "h3c"

/** @brief ������Ϣ��Manufacturer�ֶε�other�ַ��� */
#define  IMOS_MANUFACTURER_OTHER_SRT     "other"

/** @brief ������Ϣ��Manufacturer�ֶε�unknow�ַ��� */
#define  IMOS_MANUFACTURER_UNKNOW_SRT     "unknow"

/* begin added by suzhijie 00294 for NVRV3R1 20130410 */
#define IMOS_NVR_TOLLGATE_CAMERA_CODE        "specialCodeForPictureStore"
#define IMOS_NVR_EXPORT_VEDIO_TO_USB_HASH        "specialCodeExportVedioToUSB"
#define IMOS_NVR_EXPORT_PIC_TO_USB_HASH        "specialCodeExportPicToUSB"
#define IMOS_NVR_CAMERA_QUERY_USB_DISK         "cameraforqueryusbdisk"
#define IMOS_NVR_CAMERA_QUERY_USB_DIR           "cameraforqueryusbdir"
/* end added by suzhijie 00294 for NVRV3R1 20130410 */

/* Begin Modify by zhouquanwei/z01364 for �ֲ�ʽPAG�����̶������޸� */
/** @brief VMƽ̨�ڲ���ʾ */
#define VM_CODE  "iccsid"

/* Begin modified by j00350 for MPPD08948, 20140120 */
/* �ж��Ƿ���PAG�豸�����������ONVIF */
#define IMOS_IS_PAG(devCode) \
    ((0 == IMOS_strncmp(devCode, IMOS_DEFAULT_PAG_GB_CODE, sizeof(IMOS_DEFAULT_PAG_GB_CODE) - 1)) || \
     (0 == IMOS_strncmp(devCode, IMOS_DEFAULT_PAG_IMOS_CODE, sizeof(IMOS_DEFAULT_PAG_IMOS_CODE) - 1)) || \
     (0 == IMOS_strncmp(devCode, IMOS_DEFAULT_PAG_MOBILE_CODE, IMOS_CODE_LEN)))
/* End modified by j00350 for MPPD08948, 20140120 */
/* End Modify by zhouquanwei/z01364 for �ֲ�ʽPAG�����̶������޸� */

/* Begin Add By wenduanqiang/wW2834 for onvif����NVR����λ���� 2015-9-18 */
#define IMOS_IS_ONVIF(pcPlugininfo) \
	((0 == IMOS_strncmp(pcPlugininfo, IMOS_DEFAULT_ONVIF10, IMOS_STRING_LEN_64)) || \
	 (0 == IMOS_strncmp(pcPlugininfo, IMOS_DEFAULT_ONVIF20, IMOS_STRING_LEN_64)) || \
	 (0 == IMOS_strncmp(pcPlugininfo, IMOS_DEFAULT_ONVIF21, IMOS_STRING_LEN_64)))
/* End Add By wenduanqiang/wW2834 for onvif����NVR����λ���� 2015-9-18 */

/**
* @enum tagIMOSPhyOutChnlWorkingMode
* @brief �������ͨ���Ĺ���ģʽ
* @attention
*/
typedef enum tagIMOSPhyOutChnlWorkingMode
{
    IMOS_PCWM_1_SPLIT   = 1,    /**< 1���� */
    IMOS_PCWM_4_SPLIT   = 4,    /**< 4���� */
    IMOS_PCWM_6_SPLIT   = 6,    /**< 6���� */
    IMOS_PCWM_8_SPLIT   = 8,    /**< 8���� */
    IMOS_PCWM_9_SPLIT   = 9,    /**< 9���� */
    IMOS_PCWM_10_SPLIT  = 10,   /**< 10���� */
    IMOS_PCWM_13_SPLIT  = 13,   /**< 13���� */
    IMOS_PCWM_16_SPLIT  = 16,   /**< 16���� */
    IMOS_PCWM_25_SPLIT  = 25,   /**< 25����*/
    IMOS_PCWM_36_SPLIT  = 36,   /**< 36���� */

    IMOS_PCWM_BUTT
} IMOS_PHY_OUT_CHNL_WORKING_MODE_E;

/** @brief ���¸澯�¶����� - ��С */
#define IMOS_LOW_TEMPERATURE_ALARM_MIN -100

/** @brief ���¸澯�¶����� - ��� */
#define IMOS_LOW_TEMPERATURE_ALARM_MAX 49

/** @brief ���¸澯�¶����� - ��С */
#define IMOS_HIGH_TEMPERATURE_ALARM_MIN 50

/** @brief ���¸澯�¶����� - ��� */
#define IMOS_HIGH_TEMPERATURE_ALARM_MAX 104

/* @brief ��Ч���򼶱���� */
#define IMOS_INVALID_DOMAIN_LEVEL (0xFFFF)

#define MAX_MMI_NUM_PER_SLOT                    8             /* added by lw0581, 2013.12.19 for  MPPD06992 */

/* Begin Add by zhouquanwei/z01364 for �ֲ�ʽPAG����SDK�ӿ� */
#define PAG_WITH_VM 0   /* ����ʽPAG */
#define PAG_DIST    1   /* �ֲ�ʽʽPAG */
/* End Add by zhouquanwei/z01364 for �ֲ�ʽPAG����SDK�ӿ� */

/**
* @enum tagIMOSNatLevel
* @brief Nat����
* @attention ��
*/
typedef enum tagIMOSNatLevel
{
    IMOS_NAT_LEVEL_LOWER = 1,                   /**< nat����ϵͣ�����ȱ��򣬱��ȽϷ���nat�� */
    IMOS_NAT_LEVEL_EQUAL = 2,                   /**< ͬ���𣬼���ȱ���û�о���nat */
    IMOS_NAT_LEVEL_UPPER = 3,                   /**< nat����ϸߣ�����ȱ��򣬱�����nat�ڣ����ȽϷ��ڹ��� */

    IMOS_NAT_LEVEL_INVALID = 0xFFFFFFFF         /**< ��Чֵ */
}IMOS_NAT_LEVEL_E;

/**
* @enum tagIMOSStorStatus
* @brief �洢״̬
* @attention ��
*/
typedef enum tagIMOSStorStatus
{
    IMOS_STOR_ABNORMAL = 0,                         /**< �洢�쳣 */
    IMOS_STOR_NORMAL = 1,                           /**< �洢���� */
    IMOS_STOR_UNALLOC_RES = 2,                      /**< δ���ô洢��Դ */

    IMOS_STOR_STATUS_INVALID = 0xFFFFFFFF           /**< ��Чֵ */
}IMOS_STOR_STATUS_E;

/**
* @enum tagIMOSDeviceRegProtocolType
* @brief �豸ע��Э������
* @attention
*/
typedef enum tagIMOSDeviceRegProtocolType
{
    DEVICE_REG_PROTOCOL_UNKNOWN = 0,
    DEVICE_REG_PROTOCOL_IMOS    = 1,
    DEVICE_REG_PROTOCOL_GB      = 2,

    /* Begin: Added by zhouquanwei/z01364, 2015-08-17 for ONVIF �����豸���� */
    DEVICE_REG_PROTOCOL_ONVIF   = 3,
    /* End: Added by zhouquanwei/z01364, 2015-08-17 for ONVIF �����豸���� */

    DEVICE_REG_PROTOCOL_MAX,
    DEVICE_REG_PROTOCOL_INVALID = 0xFFFFFFFF

}IMOS_DEVICE_REG_PROTOCOL_TYPE_E;
/**
* @enum tagASSUBModeType
* @brief SUBģ���ɫö��
* @attention ��Ҫ��DAO_DOMAIN_TYPE_Eͬ��
*/
/*Added by y00104 for Alarm Optimization 2013-01-30*/
typedef enum tagASSUBModeType
{
    AS_SUB_DOMAIN_TYPE_REQUEST = 0,           /**< ���ķ����� */
    AS_SUB_DOMAIN_TYPE_MID,                   /**< �����м��� */
    AS_SUB_DOMAIN_TYPE_RESPOND,               /**< ����֪ͨ�� */

    AS_SUB_DOMAIN_TYPE_MAX,                   /**< ���ֵ */
    AS_SUB_DOMAIN_TYPE_INVALID = 0xFF         /**< ��Чֵ */
}AS_SUB_DOMAIN_TYPE_E;

/*Begin added by zhangzeyao zKF0189,2013.8.22 ��ѯ�豸�����Ϣ */
/**
*@enum tagDevieTypeForECR
*@brief �豸����
*/
typedef enum tagDevieTypeForECR
{
    IMOS_EC1001_HF = 0,
    IMOS_EC1002_HD,
    IMOS_EC1004_HC,
    IMOS_EC2004_HF,
    IMOS_DC1001_FF = 7,
    IMOS_EC3016_HC,
    IMOS_ISC3100,
    IMOS_EC1001_EF = 10,
    IMOS_EC3004_HF,
    IMOS_EC3008_HD,
    IMOS_ER3316_HC_8CH,
    IMOS_ER3316_HC_4CH,
    IMOS_ER3308_HD_4CH,
    IMOS_ISC3000,

    IMOS_EC2016_HC = 200,
    IMOS_EC2016_HC_8CH = 201,
    IMOS_EC2016_HC_4CH = 202,
    IMOS_EC1501_HF = 203,

    IMOS_ECR3316_HC = 300,
    IMOS_ECR3316_HC_8CH,
    IMOS_ECR3316_HC_4CH,
    IMOS_ECR3308_HD,
    IMOS_ECR3308_HD_4CH,

    IMOS_DC2004_FF_R5 = 503,

    IMOS_EC1001 = 1000,
    IMOS_DC1001 = 1001,
    IMOS_EC1101_HF = 1002,
    IMOS_EC1102_HF = 1003,
    IMOS_EC1801_HH = 1004,
    IMOS_DC1801_FH = 1005,
    IMOS_ECR3308_HF = 1006,                  /* ECR3308-HF */
    IMOS_ECR3316_HF = 1007,                  /* ECR3316-HF */

    /* OEM��Ʒ�ͺ� */
    IMOS_VR2004 = 10003,
    IMOS_VL2004 = 10503,
    IMOS_VR1102 = 11003,

    /* IPC��Ʒ�ͺ� */
    IMOS_HIC5201 = 12001,
    IMOS_HIC5221 = 12002,
    IMOS_DEV_TYPE_BUTT
}DEVICE_TYPE_FOR_ECR_E;

/**
*@enum tagNetLinkModeForECR
*@brief ��·ģʽѡ��ö��
*/
typedef enum tagNetLinkModeForECR
{
    IMOS_NET_LINK_MODE_ELEC = 0,                  /* ��·ѡ���� */
    IMOS_NET_LINK_MODE_RAY,                       /* ��·ѡ���� */
    IMOS_NET_LINK_MODE_AUTO,                      /* ��·ѡ������Ӧ */
    IMOS_NET_LINK_MODE_BUTT
}NET_LINK_MODE_FOR_ECR_E;

/**
* @enum tagDevFansStatusForECR
* @brief  �豸����״̬
* @attention
*/
typedef enum tagDevFansStatusForECR
{
    IMOS_SPEED_LOW   = 0,
    IMOS_SPEED_HIGH  = 1,
    IMOS_SPEED_FAULT = 2,
    IMOS_SPEED_NULL  = 3,
    IMOS_FAN_TYPE_BUTT
}DEV_FANS_STATUS_FOR_ECR_E;

/**
*@enum tagIpGetTypeForECR
*@brief ��ȡip��ַ����
*/
typedef enum tagIpGetTypeForECR
{
    IMOS_IP_GET_STATICIP = 0,             /* ��̬���� */
    IMOS_IP_GET_PPPOE,                    /* pppoeģʽ */
    IMOS_IP_GET_DHCP,                     /* ��̬��ȡ */
    IMOS_IP_GET_UNP,                      /* UNP���ŷ�ʽ��ȡ */
    IMOS_IP_GET_NULL,                     /* û������ */
    IMOS_IP_GET_BUTT                      /* ����ģʽ */
}IP_GET_TYPE_FOR_ECR_E;

/**
* @enum tagConnectStatusForECR
* @brief  ����״̬ δ���Ӻ���Ĳ���������
* @attention
*/
typedef enum tagConnectStatusForECR
{
    IMOS_NOT_CONNECTED         = 0,        /* δ���� */
    IMOS_IS_CONNECTED           = 1,  /* ������ */
    IMOS_CONNECT_TYPE_BUTT
}CONNECTION_STATUS_FOR_ECR_E;

/**
*@enum tagETHSpeedForECR
*@brief ��������
*/
typedef enum tagETHSpeedForECR
{
    IMOS_ETH_SPEED_AUTO   = 0,                     /* ��������Ϊ��Э�� */
    IMOS_ETH_SPEED_10M    = 1,                     /* ��������Ϊ10M */
    IMOS_ETH_SPEED_100M   = 2,                     /* ��������Ϊ100M */
    IMOS_ETH_SPEED_1000M  = 3,                     /* ��������Ϊ1000M */
    IMOS_ETH_SPEED_BUTT
}ETH_SPEED_FOR_ECR_E;

/**
*@enum tagETHDuplexForECR
*@brief ���ڹ���ģʽ
*/
typedef enum tagETHDuplexForECR
{
    IMOS_ETH_DUPLEX_AUTO   = 0,                    /* ����˫��ģʽΪ��Э�� */
    IMOS_ETH_DUPLEX_FULL   = 1,                    /* ����˫��ģʽΪȫ˫�� */
    IMOS_ETH_DUPLEX_HALF   = 2,                    /* ����˫��ģʽΪ��˫�� */
    IMOS_ETH_DUPLEX_BUTT
}ETH_DUPLEX_FOR_ECR_E;

/*End:add by zhangzeyao zKF0189,2013.8.22 ��ѯ�豸�����Ϣ*/

/* Begin added by g00351,2013-09-09 of ֧������OSD*/
/**
* @enum tagDevNewOsdType
* @brief ����OSD����
* @attention ��
*/
typedef enum tagDevNewOsdType
{
    DEV_NEW_OSD_WORD = 1,                   /**< �Զ���(����) */
    DEV_NEW_OSD_TIME = 2,                   /**< ʱ�� */
    DEV_NEW_OSD_PTZ_COORDINAT  = 3,         /**< ��̨���� */
    DEV_NEW_OSD_MULTIPLE = 4,               /**< �䱶 */
    DEV_NEW_OSD_GUARDPOSITION = 5,          /**< Ԥ��λ */
    DEV_NEW_OSD_SERIAL_INFO = 6,            /**< ������Ϣ */

    DEV_NEW_OSD_MAX,
    DEV_NEW_OSD_PTZ_USER = 100,             /**< ��̨�û�������ɽϴ�ֵ������IPC��չOSD����ʱ���ֳ�ͻ */
    DEV_NEW_OSD_INVALID  = 0xFFFF           /**< ��Чֵ */

} DEV_NEW_OSD_TYPE_E;

/* End added by g00351,2013-09-09 of ֧������OSD*/

/* Begin Added by shendongchun 2014-02-26 for ���������ݿ��������� */
/**
* @struct tagDRType
* @brief DR����ö��
* @attention ��
*/
typedef enum tagDRType
{
    DR8500_M = 0,                                  /**< DR8500�������� */
    DR8500_N = 1,                                  /**< DR8500���������� */
    DR9500_M = 2,                                  /**< DR9500�������� */
    DR9500_N = 3,                                  /**< DR9500���������� */
    DR_MAX,                                    /**< DR�������������ֵ */
    DR_INVALID = 0XFFFFFFFF                    /**< DR������������Чֵ */
} DR_TYPE_E;
/* End Added by shendongchun 2014-02-26 for ���������ݿ��������� */

/**
* @struct tagTMSSubType
* @brief TMS������ö��
* @attention ��
*/
typedef enum tagTMSSubType
{
    TMS8500_SUB_TYPE = 0,                                   /**< TMS8500������ */
    TMS9500_SUB_TYPE = 2,                                   /**< TMS9500������ */
    TMS5516_SUB_TYPE = 3,                                   /**< TMS5516������ */

    TMS_SUB_TYPE_MAX,                                       /**< TMS���������ֵ */
    TMS_SUB_TYPE_INVALID = 0XFFFFFFFF                       /**< TMS��������Чֵ */
} TMS_SUB_TYPE_E;

/* Begin add by liujian/02319, 2016-06-27 for 2016 �¹����豸Ŀ¼��ѯ */
/**
* @enum tagSVCEncodeEnhanceType
* @brief SVC ʱ���������������ǿ����
* @attention ��
*/
typedef enum tagSVCEncodeEnhanceType
{
    SVC_NO_ENCODE_ENHANCE = 0,                      /** ��֧����ǿ */
    SVC_FIRST_ENCODE_ENHANCE = 1,                /** 1����ǿ(1 ����ǿ��) */
    SVC_SECOND_ENCODE_ENHANCE = 2,           /** 2����ǿ(2 ����ǿ��) */
    SVC_THIRD_ENCODE_ENHANCE = 3,               /** 3����ǿ(3 ����ǿ��)*/

    SVC_MAX_ENCODE_ENHANCE
}SVC_ENCODE_ENHANCE_TYPE_E;
/* End add by liujian/02319, 2016-06-27 for 2016 �¹����豸Ŀ¼��ѯ */


/** ��ͨ�¼�����ö��ֵ */
typedef enum tagTrafficEventType
{
    TRAFFIC_EVENT_ABNORMAL_PARKING = 0,    /* �쳣ͣ�� */
    TRAFFIC_EVNET_ABNORMAL_PEDESTRIAN = 1, /* �쳣���� */
    TRAFFIC_EVNET_VEHICLE_CONGESTION = 2,  /* ����ӵ�� */
    TRAFFIC_EVENT_QUEUE_LENGTH       = 3,  /* �Ŷӳ��� */
    TRAFFIC_EVENT_TRAVEL_AGAINST_TRAFFIC = 4, /* ���� */
    TRAFFIC_EVENT_THROW_STUFF           = 5,  /* ������ */
    TRAFFIC_EVENT_VEHICLE_OFF_TRACK     = 6,  /* ������ʻ���¼� */
    TRAFFIC_EVENT_OTHER                 = 99, /* ���� */

    TRAFFIC_EVENT_INVALID               = 0xFFFFFFFF    /* ��Чֵ */
} TMS_TRAFFIC_EVENT_TYPE_E;

/* Begin: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */
#if 0
/***********�����Կ��豸(Xware)�����Ϣ**********/
#endif
/**
* @struct tagTVWallBelongType
* @brief ����ǽ��������
* @attention ��
*/
typedef enum tagTVWallBelongType
{
    TVWALL_BELONG_TYPE_A8 = 0,                      /**< A8 */
    TVWALL_BELONG_TYPE_XWARE = 1,                   /**< XWARE */

    TVWALL_BELONG_TYPE_MAX,                         /**< ���ֵ */
    TVWALL_BELONG_TYPE_INVALID = 0XFFFFFFFF        /**< ��Чֵ */
} TVWALL_BELONG_TYPE_E;

/**
* @struct tagXwareDevAbilityOperate
* @brief �豸����������������
* @attention ��
*/
typedef enum tagXwareDevAbilityOperate
{
    XWARE_DEVICE_ABILITY_OPERATE_ADD = 0,                      /**< ���� */
    XWARE_DEVICE_ABILITY_OPERATE_DELETE = 1,                   /**< ���� */

    XWARE_DEVICE_ABILITY_OPERATE_MAX,                          /**< ���ֵ */
    XWARE_DEVICE_ABILITY_OPERATE_INVALID = 0XFFFFFFFF          /**< ��Чֵ */
} XWARE_DEVICE_ABILITY_OPERATE_E;

/**
* @struct tagTvwallVirLEDStatus
* @brief ����ǽLED����״̬
* @attention ��
*/
typedef enum tagTvwallVirLEDStatus
{
    TVWALL_VIR_LED_STATUS_DISABLE = 0,                      /**< ����LED������ */
    TVWALL_VIR_LED_STATUS_ENABLE = 1,                       /**< ����LED���� */

    TVWALL_VIR_LED_STATUS_MAX,                              /**< ����LED״̬���ֵ */
    TVWALL_VIR_LED_STATUS_INVALID = 0XFFFFFFFF              /**< ����LED״̬��Чֵ */
} TVWALL_VIR_LED_STATUS_E;

/**
* @struct tagTvwallVirLEDType
* @brief ����ǽLED����
* @attention ��
*/
typedef enum tagTvwallVirLEDType
{
    TVWALL_VIR_LED_TYPE_WORD = 1,                           /**< ������ */
    TVWALL_VIR_LED_TYPE_TIME = 2,                           /**< ʱ���� */
    TVWALL_VIR_LED_TYPE_ICON = 3,                           /**< ͼ���� */

    TVWALL_VIR_LED_TYPE_MAX,                                /**< ����LED�������ֵ */
    TVWALL_VIR_LED_TYPE_INVALID = 0XFFFFFFFF                /**< ����LED������Чֵ */
} TVWALL_VIR_LED_TYPE_E;

/**
* @struct tagTvwallVirLEDTransparent
* @brief ����ǽLED����͸����
* @attention ��
*/
typedef enum tagTvwallVirLEDTransparent
{
    TVWALL_VIR_LED_TRANSPARENT_YES = 0,                     /**< ͸�� */
    TVWALL_VIR_LED_TRANSPARENT_NO = 100,                   /**< ��͸�� */

    TVWALL_VIR_LED_TRANSPARENT_MAX,                          /**< ����LED͸�������ֵ */
    TVWALL_VIR_LED_TRANSPARENT_INVALID = 0XFFFFFFFF          /**< ����LED͸������Чֵ */
} TVWALL_VIR_LED_TRANSPARENT_E;

/**
* @struct tagTvwallVirLEDFont
* @brief ����ǽLED����
* @attention ��
* ��ֻ��һ��"����"�����ڿ���չ
*/
typedef enum tagTvwallVirLEDFont
{
    TVWALL_VIR_LED_FONT_SONG = 1,                     /**< ����*/

    TVWALL_VIR_LED_FONT_MAX,                          /**< ����LED�������ֵ */
    TVWALL_VIR_LED_FONT_INVALID = 0XFFFFFFFF          /**< ����LED������Чֵ */
} TVWALL_VIR_LED_FONT_E;

/**
* @struct tagTvwallVirLEDSize
* @brief ����ǽLED�����С
* @attention ��
*/
typedef enum tagTvwallVirLEDSize
{
    TVWALL_VIR_LED_SIZE_24 = 1,                     /**< 24*24����*/
    TVWALL_VIR_LED_SIZE_32 = 2,                     /**< 32*32����*/
    TVWALL_VIR_LED_SIZE_48 = 3,                     /**< 48*48����*/
    TVWALL_VIR_LED_SIZE_64 = 4,                     /**< 64*64����*/
    TVWALL_VIR_LED_SIZE_96 = 5,                     /**< 96*96����*/
    TVWALL_VIR_LED_SIZE_128 = 6,                    /**< 128*128����*/

    TVWALL_VIR_LED_SIZE_MAX,                          /**< ����LED�������ֵ */
    TVWALL_VIR_LED_SIZE_INVALID = 0XFFFFFFFF          /**< ����LED������Чֵ */
} TVWALL_VIR_LED_SIZE_E;

/**
* @struct tagTvwallVirLEDLeftRightAlignment
* @brief ����ǽLED���Ҷ��뷽ʽ
* @attention ��
*/
typedef enum tagTvwallVirLEDLeftRightAlignment
{
    TVWALL_VIR_LED_LEFTRIGHT_ALI_LEFT = 1,                     /**< ����� */
    TVWALL_VIR_LED_LEFTRIGHT_ALI_MID = 2,                      /**< ���ж��� */
    TVWALL_VIR_LED_LEFTRIGHT_ALI_RIGHT = 3,                    /**< �Ҷ��� */

    TVWALL_VIR_LED_LEFTRIGHT_ALI_MAX,                          /**< ����LED���Ҷ��뷽ʽ���ֵ */
    TVWALL_VIR_LED_LEFTRIGHT_ALI_INVALID = 0XFFFFFFFF          /**< ����LED���Ҷ��뷽ʽ��Чֵ */
} TVWALL_VIR_LED_LEFTRIGHT_ALI_E;

/**
* @struct tagTvwallVirLEDUpDownAlignment
* @brief ����ǽLED���¶��뷽ʽ
* @attention ��
*/
typedef enum tagTvwallVirLEDUpDownAlignment
{
    TVWALL_VIR_LED_UPDOWN_ALI_UP = 1,                           /**< �϶��� */
    TVWALL_VIR_LED_UPDOWN_ALI_MID = 2,                          /**< ���ж��� */
    TVWALL_VIR_LED_UPDOWN_ALI_DOWN = 3,                         /**< �¶��� */

    TVWALL_VIR_LED_UPDOWN_ALI_MAX,                              /**< ����LED���¶��뷽ʽ���ֵ */
    TVWALL_VIR_LED_UPDOWN_ALI_INVALID = 0XFFFFFFFF              /**< ����LED���¶��뷽ʽ��Чֵ */
} TVWALL_VIR_LED_UPDOWN_ALI_E;

/**
* @struct tagTvwallVirLEDScrollType
* @brief ����ǽLED���ֹ�������
* @attention ��
*/
typedef enum tagTvwallVirLEDScrollType
{
    TVWALL_VIR_LED_SCROLL_TYPE_NO = 1,                           /**< ������ */
    TVWALL_VIR_LED_SCROLL_TYPE_LEFT = 2,                         /**< ������� */
    TVWALL_VIR_LED_SCROLL_TYPE_RIGHT = 3,                        /**< ���ҹ��� */
    TVWALL_VIR_LED_SCROLL_TYPE_UP = 4,                           /**< ���Ϲ��� */
    TVWALL_VIR_LED_SCROLL_TYPE_DOWN = 5,                         /**< ���¹��� */

    TVWALL_VIR_LED_SCROLL_TYPE_MAX,                              /**< ����LED���ֹ����������ֵ */
    TVWALL_VIR_LED_SCROLL_TYPE_INVALID = 0XFFFFFFFF              /**< ����LED���ֹ���������Чֵ */
} TVWALL_VIR_LED_SCROLL_TYPE_E;
/* End: Added by zhuzhicong 02302, 2017-07-03 for MPPD48388 XWARE���뵽ƽ̨ */


#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_DEF_H_ */

