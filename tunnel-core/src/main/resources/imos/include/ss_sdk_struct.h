/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              ss_sdk_struct.h

  Project Code: SDK
   Module Name: SDK
  Date Created: 2009-02-27
        Author: huangjun (00754)
                chenshangwu (07076)
   Description: ���ݽṹ�����ĵ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _SS_SDK_STRUCT_H_
#define _SS_SDK_STRUCT_H_

#ifdef  __cplusplus
extern "C"{
#endif

#pragma pack(4)

/*******************************************************************************
SS�����ṹ
*******************************************************************************/

/**
* @struct tagQueryByCond
* @brief ����������ģ����ѯ��
* @attention
*/
typedef struct tagQueryByCond
{
    /** �豸���ƻ���Դ���ơ� �������Ϊ�գ� ���ѯ���еļ�¼ */
    CHAR    szName[IMOS_NAME_LEN];

    /** ��ʼʱ�䡣 �����ʼʱ��ͽ���ʱ���Ϊ0�� ���ѯ����ʱ��εļ�¼ */
    LONG_32    lStartTime;

    /** ����ʱ�� */
    LONG_32    lEndTime;

} QUERY_BY_COND_S;


/**
 * @struct tagTerminalTimeStatInfoEx
 * @brief  �ն�ʱ��ͳ����Ϣ
 * @attention
 */
typedef struct tagTerminalTimeStatInfoEx
{

  /** �豸���� */
  CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

  /** �豸���� */
  CHAR  szDevName[IMOS_NAME_LEN];

  /** ʱ��*/
  ULONG_32        ulTimeDuration;
} TERMINAL_TIME_STAT_INFO_EX_S;

/**
 * @struct tagConfStatInfoEx
 * @brief  ������ͳ����Ϣ
 * @attention
 */
typedef struct tagConfStatInfoEx
{
  /** ����ʱ��*/
  LONG_32         lSampleTime;

  /** ������*/
  ULONG_32        ulConfNumber;

  /** �����ն���*/
  ULONG_32        ulTermNumber;
} CONF_STAT_INFO_EX_S;

/**
 * @struct tagVirtualTermResEx
 * @brief  �����ն���Դ��Ϣ
 * @attention
 */
typedef struct tagVirtualTermResEx
{
    /** �����ն���Դ����*/
    CHAR        szVirtualResCode[IMOS_RES_CODE_LEN];

    /** �ն�E164��*/
    CHAR        szTermE164[IMOS_CONF_ALIAS_LEN];

    /** �ն˱���*/
    CHAR        szTermAlias[IMOS_CONF_ALIAS_LEN];

    /** �������������*/
    CHAR        szVirtualScreenCode[IMOS_RES_CODE_LEN];

    /** �������������*/
    CHAR        szVirtualCameraCode[IMOS_RES_CODE_LEN];

    /** ��Դʹ��״̬ ö������ MC_VIRTUAL_RES_STATUS_EX_E */
    ULONG_32       ulResStatus;
} VIRTUAL_TERM_RES_QURERY_ITEM_EX_S;

/**
* @struct tagMC_ConfBaseInfoEx
* @brief ����򵥽ṹ
* @attention
*/
typedef struct tagMC_ConfBaseInfoEx
{
    /** �������ƻ����ģ���� */
    CHAR        szConfName[IMOS_CONF_NAME_LEN];

    /** ����E164���� */
    CHAR        szConfE164[IMOS_CONF_ALIAS_LEN];

    /** ���鴴���� */
    CHAR        szCreater[IMOS_NAME_LEN];

    /** ���鴴���ߵ��û����� */
    CHAR        szCreaterUserCode[IMOS_USER_CODE_LEN];

    /** ���鴴��ʱ�� ����ʱ���治��Ҫ��д��ͳһIMSC��д*/
    LONG_32        lCreateTime;

    /** �Ƿ��������� */
    BOOL_T      bAtOnce;

    /** �Ƿ����û���(�������ʱ��) */
    BOOL_T      bConfForever;

    /** �����ٿ�ʱ�� */
    LONG_32        lStartTime;

    /** ����ʱ������λΪ�� */
    LONG_32        lDuration;

    /** �������� */
    CHAR        szDescribe[IMOS_DESC_LEN];

    /** �����洿ת�� */
    BOOL_T      bPureTransmit;

    /** �����ʽ���� */
    BOOL_T      bPackageAdapt;
} MC_CONF_BASE_INFO_EX_S;

/**
* @struct tagMC_ConfReserveInfoEx
* @brief ԤԼ������Ϣ
* @attention ��1�δ���ʱ����������Ҳ�����ɹ����������鰴�����ڵ���Ч�����������ڻ���ʱ�����ܳ���24Сʱ��
*/
typedef struct tagMC_ConfReserveInfoEx
{
    /** ���ڻ�������  MC_CONF_CYCLE_TYPE_EX_E */
    ULONG_32                   ulCycleType;

    /** �ظ�����, �ö�����λ��ʾ;
    �����������Ϊ��, ���0λ��ʾ1��, ���ε���, ��31λ��ʾ��ĩ;
    �����������Ϊ��, ���0λ��ʾ����һ, ���ε���

    ���е�0λ�Ǵ����ұ߿�ʼ��ġ�
    ����:
    1��������ܵĻ���������һ/�ܶ�/�����ٿ�����Ӧ���� 0000....0000111 �����ܶ��ٿ�����Ӧ���� 0000....0000010
    2��������µĻ�������1��2�ſ���Ӧ���� 0000....0000011 ������ĩ����Ӧ���� 1000....0000000
    ����31�ſ���Ӧ���� 0100....0000000
    3���������Ļ���lCycleDateû������
    */
    LONG_32                    lCycleDate;

    /** �ظ�����1-10000 */
    ULONG_32                   ulCycleCount;

    /** ���ڻ���������� MC_CONF_CYCLE_END_TYPE_EX_E */
    ULONG_32                   ulCycleEndType;

    /** �ظ�����Ŀ�ʼ���� ��������ʱ����д���Ի����ٿ�ʱ��Ϊ׼ */
    LONG_32                    lCycleBeginTime;

    /** �ظ�����Ľ�ֹ���ڣ�ʵ����дλ��ֹ���� + 23:59:59 */
    LONG_32                    lCycleEndTime;
} MC_CONF_RESERVE_INFO_EX_S;


/**
* @struct tagMC_ConfAuthorityInfoEx
* @brief �������Ȩ������
* @attention
*/
typedef struct tagMC_ConfAuthorityInfoEx
{
    /** �Ƿ�������飬����ǿ�ʱ��BOOL_TRUE,������BOOL_FALSE */
    BOOL_T           bSecret;

    /** ������� */
    CHAR             szPwd[IMOS_CONF_PWD_LEN];

    /** �����绰����֧�֣�ָ�Ƿ����������᳡ */
    BOOL_T           bNameless;

    /** ����������ָ����ڼ䲻�����������᳡���� */
    BOOL_T           bLocked;
} MC_CONF_AUTHORITY_INFO_EX_S;

/**
* @struct tagHD_BannerInfoEx
* @brief �����Ϣ
* @attention
*/
typedef  struct  tagHD_BannerInfoEx
{
    /** BOOL_TRUE, ֧�ֺ�� */
    BOOL_T                       bSupportBanner;

    /** ������� */
    CHAR                         szBannerInfo[IMOS_BANNER_LEN];

    /** ���� HD_FONT_EX_E */
    ULONG_32                        ulFont;

    /** �����С HD_FONT_SIZE_EX_E */
    ULONG_32                        ulFontSize;

    /** ������ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32                        ulFontColor;

    /** ������ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32                        ulBgColor;

    /** ���λ�� HD_BANNER_POS_EX_E */
    ULONG_32                        ulBannerPos;

    /** ����Ƿ����� */
    BOOL_T                       bIsConceal;
} HD_BANNER_INFO_EX_S;


/**
* @struct tagHD_ConfShowTimerInfoEx
* @brief ����ʱ����ʾ�Ľṹ
* @attention
*/
typedef struct tagHD_ConfShowTimerInfoEx
{
    /** ʱ����ʾ���� HD_CONF_SHOW_TIMER_TYPE_EX_E */
    ULONG_32   ulShowType;

    /** ������ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32   ulFontColor;

    /** ������ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32   ulBGColor;

    /** �������� HD_FONT_EX_E */
    ULONG_32   ulFont;

    /** �����С HD_FONT_SIZE_EX_E */
    ULONG_32   ulFontSize;

    /** λ�� HD_SITE_NAME_TIMER_POS_EX_E */
    ULONG_32   ulSitePos;
} HD_CONF_SHOW_TIMER_INFO_EX_S;

/**
* @struct tagHD_SiteNameInfoEx
* @brief �᳡����ʾ�ṹ
* @attention
*/
typedef struct tagHD_SiteNameInfoEx
{
    /** BOOL_TRUE, ֧�ֻ᳡�� */
    BOOL_T   bSupportSiteName;

    /** �Ƿ���ʾ�᳡������ʾMCU���õĻ᳡������ʾ�ն��Դ��᳡�� HD_CONF_SHOW_SITE_NAME_EX_E */
    ULONG_32    ulSiteNameAble;

    /** �᳡����ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32    ulNameColor;

    /** ������ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32    ulBGColor;

    /** �᳡������ HD_FONT_EX_E */
    ULONG_32    ulFont;

    /** �᳡�������С HD_FONT_SIZE_EX_E */
    ULONG_32    ulFontSize;

    /** �᳡��λ�� HD_SITE_NAME_TIMER_POS_EX_E��������֧�ֺ��ʱ��ֻ��ѡ�����º�����λ�� */
    ULONG_32    ulSitePos;
} HD_SITE_NAME_INFO_EX_S;

/**
* @struct tagMC_ConfFrameEx
* @brief ����ı߿�����,����������ϯ�������ˡ������᳡�߿���ɫ���߿��ϸ��
* @attention
*/
typedef struct tagMC_ConfFrameEx
{
    /** �߿��ϸ HD_FRAME_THICK_TYPE_EX_E */
    ULONG_32         ulFrameThick;

    /** ��ϯ�߿���ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32         ulChairColor;

    /** �����˱߿���ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32         ulSpeakerColor;

    /** �����᳡�߿���ɫ HD_COLOR_TABLE16_TYPE_EX_E */
    ULONG_32         ulOtherColor;
} MC_CONF_FRAME_EX_S;

/**
* @struct tagHD_TitleInfoEx
* @brief ��Ļ��Ϣ
* @attention ��Ļʱ���͹���������ѡ1��
*/
typedef  struct  tagHD_TitleInfoEx
{
    /** �Ƿ�֧����Ļ: BOOL_TRUE, ֧����Ļ */
    BOOL_T            bSupport;

    /** ���� HD_FONT_EX_E  */
    ULONG_32             ulFont;

    /** �����С HD_FONT_SIZE_EX_E  */
    ULONG_32             ulFontSize;

    /** ������ɫ HD_COLOR_TABLE4_TYPE_EX_E */
    ULONG_32             ulFontColor;

    /** �������� HD_COLOR_TABLE4_TYPE_EX_E */
    ULONG_32             ulBgColor;

    /** ��Ļλ�� HD_TITLE_POS_EX_E */
    ULONG_32             ulTitlePos;

    /** ��Ļ�����ٶ� HD_TITLE_ROLL_SPEED_EX_E */
    ULONG_32             ulMoveSpeed;

    /** ��Ļ�������� HD_TITLE_ROLL_DIRECTION_EX_E */
    ULONG_32             ulMoveDirection;

    /** ��Ļ�������� */
    LONG_32              lRollNum;

    /** ��Ļ����ʱ�� HD_TITLE_LAST_TIME_EX_E */
    ULONG_32             ulRollTimeLen;

    /** ��Ļ����������ʽ HD_TITLE_ROLL_END_TYPE_EX_E */
    ULONG_32             ulRollEndType;

    /** ��Ļ�Ƿ���ʾ  */
    BOOL_T            bIsConceal;

    /** �Ƿ������Ļ��ʾ */
    BOOL_T            bIsMoreRowDisplay;

    /** ��Ļ���� */
    CHAR              szTitleBuff[IMOS_TITLE_LEN];
} HD_TITLE_INFO_EX_S;

/**
* @struct tagMC_MultiPicSiteShowModeInfoEx
* @brief ���û᳡��ʾģʽ����Ϣ�ṹ:
* szSiteCodeֻ�ڻ�����ʾģʽΪָ���᳡ʱ����Ч; ��Ϊָ���᳡��szSiteCodeΪ��ʱ����ʾ"��"������С����λ�ò���ʾ�κλ᳡��
* ��������ʾģʽΪ������ϯ�������ˡ������������᳡��Ѳʱ��IMSC�ڻ��������л�ȡ��SDK�·�ʱ�᳡����Ϊ��;
* ��������ʾģʽΪ�Զ����ʱ, �������һ�����߻᳡, SDK�·�ʱ�᳡����Ϊ��
* @attention
*/
typedef struct tagMC_MultiPicSiteShowModeInfoEx
{
    /** ������ʾģʽ MC_MULTI_PIC_ONE_PIC_EX_E */
    ULONG_32                    ulShowSite;

    /** ָ���᳡����  ��ͬ"������ʾģʽ"�в�ͬ������ */
    CHAR                     szSiteCode[IMOS_RES_CODE_LEN];

    /** ָ���᳡���� */
    CHAR                     szSiteName[IMOS_NAME_LEN];

    /** ��ǰ�᳡���� */
    CHAR                     szCurrSiteCode[IMOS_RES_CODE_LEN];

    /** ��ǰ�᳡���� */
    CHAR                     szCurrSiteName[IMOS_NAME_LEN];

    /** ��Ӧ�ڶ������,��С����ı�� �������ʱ�������Ч, ������ʱ��0 */
    LONG_32                     lSerialNum;

    /** ��Ѳʱ��ѡ����Ѳ�б���� MC_CYCLE_TABLE_INDEX_EX_E */
    ULONG_32                    ulCycleIndex;
} MC_MULTI_PIC_SITE_SHOW_MODE_EX_S;

/**
* @enum tagMC_MultiPicInfoEx
* @brief �������Ϣ�ṹ
* @attention
*/
typedef struct tagMC_MultiPicInfoEx
{
    /** �Ƿ�໭�档BOOL_FALSE��ʾ��ת������MCU�������������жϣ�SDK�·�ʱ��BOOL_TRUE */
    BOOL_T                bMultiPic;

    /** �����ģʽ HD_MULTIPIC_MODE_EX_E */
    ULONG_32                 ulMultiPic;

    /** ������� */
    LONG_32                  lMultiPicNum;

    /** С����λ�á���ʾģʽ */
    MC_MULTI_PIC_SITE_SHOW_MODE_EX_S   astSiteShowMode[IMOS_HD_MAX_SUBPIC_NUM];
} MC_MULTI_PIC_INFO_EX_S;


/**
* @struct tagMC_ConfPollModeEx
* @brief ������Ѳģʽ
* @attention
*/
typedef  struct tagMC_ConfPollModeEx
{
    /** BOOL_TRUE, ������Ѳ, ������Ѳ */
    BOOL_T                           bCycle;

    /** ��Ѳʱ����,��λ�� MC_CYCLE_TIME_INTERVAL_EX_E */
    ULONG_32                            ulCycleTime;
} MC_CONF_POLL_MODE_EX_S;

/**
* @struct tagMC_ConfBaseAttrEx
* @brief �����������
* @attention
*/
typedef struct tagMC_ConfBaseAttrEx
{
    /** Э������,Ĭ��H323 MC_PROTOCOL_TYPE_EX_E */
    ULONG_32       ulProtocolType;

    /** ����ģʽ MC_CONF_MODE_EX_E Ŀǰʵ�ֵ��ݺ���ϯģʽ������ģʽ�Ѻϲ�������ģʽ�� */
    ULONG_32       ulConfMode;

    /** ��������� HD_MULTI_PIC_NUM_EX_E */
    ULONG_32       ulMultiPicNum;

    /** ����ѡ��ۿ�ģʽ MC_CHAIR_BROWSE_MODE_EX_E */
    ULONG_32       ulChairBrowseMode;

    /** �㲥ģʽ MC_BROADCAST_MODE_EX_E */
    ULONG_32       ulBroadcastMode;

    /** ��������ϸ��Ϣ�ṹ С����ı����Ч */
    MC_MULTI_PIC_SITE_SHOW_MODE_EX_S   stSinglePicInfo;

    /** �������ϸ��Ϣ�ṹ */
    MC_MULTI_PIC_INFO_EX_S      stMultiPicInfo;

    /** BOOL_TRUE֧�ֶ໭���Զ��л�, ����֧�ֶ໭���Զ��л� */
    BOOL_T                      bAutoMultiPic;

    /** �������� HD_BITRATE_EX_E */
    ULONG_32                       ulBitRate;

    /** ����������ʽ MC_DROP_REINVITE_MODE_EX_E */
    ULONG_32                       ulReInvite;

    /** BOOL_TRUE֧���Զ����٣�MCUδ�õ�����0 */
    BOOL_T                      bAutoRateAdjust;

    /** ����������Ѳ��Ϣ�ṹ */
    MC_CONF_POLL_MODE_EX_S      stConfMainPoll;

    /** ����㲥��Ѳ��Ϣ�ṹ */
    MC_CONF_POLL_MODE_EX_S      stConfBroadPoll;
} MC_CONF_BASE_ATTR_EX_S;

/**
* @struct tagMC_ConfNormalInfo
* @brief ���������Ϣ iMSC��չ��
* @attention
*/
typedef struct tagMC_ConfNormalInfoEx
{
    /** �Ƿ���iMSC�����Ļ��� */
    BOOL_T                       bConfIsImscCreate;

    /** ���鱸�� */
    BOOL_T                       bAutoBackup;

    /** �������� MC_CONF_CASCADE_TYPE_EX_E */
    ULONG_32                        ulCascadeType;

    /** ���������Ϣ */
    MC_CONF_BASE_INFO_EX_S       stConfBaseInfo;

    /** ԤԼ������Ϣ */
    MC_CONF_RESERVE_INFO_EX_S    stConfReserveInfo;

    /** �������Ȩ����Ϣ */
    MC_CONF_AUTHORITY_INFO_EX_S  stConfAuthInfo;


    /** ��������Ϣ */
    HD_BANNER_INFO_EX_S          stBannerInfo;

    /** ����ʱ����ʾ��Ϣ�����ֶ�MCUû���õ���ȫ��0  */
    HD_CONF_SHOW_TIMER_INFO_EX_S stTimerInfo;

    /** �᳡����ʾ��Ϣ */
    HD_SITE_NAME_INFO_EX_S       stSiteNameInfo;

    /** �������������Ϣ */
    MC_CONF_BASE_ATTR_EX_S       stConfBaseAttr;

    /** �߿����� */
    MC_CONF_FRAME_EX_S           stConfFrame;

    /** ������Ļ��Ϣ�ṹ */
    HD_TITLE_INFO_EX_S           stTitleInfo;
} MC_CONF_NORMAL_INFO_EX_S;





/**
* @struct tagMC_MainVideoCfgEx
* @brief ������������
* @attention
*/
typedef struct tagMC_MainVideoCfgEx
{
    /** ����Э���ʽ�� */
    LONG_32                lVideoProtFmtNum;

    /** ����Э���ʽ HD_VIDEO_PROT_FMT_EX_E */
    ULONG_32               aulVideoProtFmt[IMOS_EN_VID_PROT_FMT_COUNT];

    /** ֧��֡�ʸ��� */
    LONG_32                lVideoFramerateNum;

    /** ��Ƶ֡�� HD_FRAME_RATE_EX_E */
    ULONG_32               aulFramerate[IMOS_HD_MAX_VIDEO_FRAMERATE_NUM];

    /** ��Ƶ���ʵĸ��� */
    LONG_32                lVideoRateNum;

    /** ��Ƶ������ HD_BITRATE_EX_E */
    ULONG_32               aulVideoRate[IMOS_HD_MAX_VIDEO_RATE_NUM];
} MC_MAIN_VIDEO_CFG_EX_S;


/**
* @struct tagMC_MainVideoCfgEx
* @brief ������������
* @attention
*/
typedef struct tagMC_RoleVideoCfgEx
{
    /* ��Ƶ��׼�ĸ�������������䣬��1��������0 */
    LONG_32                lVideoProtNum;

    /** ֧�ֵ���Ƶ��׼, ����ΪH264ʱ����H263+, ������H264  HD_VIDEO_PROT_EX_E */
    ULONG_32               aulVideoProt[IMOS_HD_MAX_VIDEO_PROTOCOL_NUM];

    /** ��Ƶ��ʽ�ĸ��� */
    LONG_32                lVideoFmtNum;

    /** ��Ƶ��ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32               aulVideoFmt[IMOS_HD_MAX_VIDEO_FORMAT_NUM];

    /** ֧��֡�ʸ��� */
    LONG_32                lVideoFramerateNum;

    /** ��Ƶ֡�� HD_FRAME_RATE_EX_E */
    ULONG_32               aulFramerate[IMOS_HD_MAX_VIDEO_FRAMERATE_NUM];

    /** ��Ƶ���ʵĸ��� */
    LONG_32                lVideoRateNum;

    /* ��Ƶ������ HD_BITRATE_EX_E */
    ULONG_32               aulVideoRate[IMOS_HD_MAX_VIDEO_RATE_NUM];
} MC_ROLE_VIDEO_CFG_EX_S;


/**
* @struct tagMC_ConfMediaInfo
* @brief ����ý����Ϣ
* @attention
*/
typedef struct tagMC_ConfMediaInfoEx
{
    /** ��Ƶ */
    /** ���鵱ǰ��Ƶ��׼ HD_AUDIO_PROT_EX_E */
    ULONG_32                          ulCurrentAudioProt;

    /** ��ƵЭ������, ����lAudioProtCount�ֶη�0ʱ����BOOL_TRUE������BOOL_FALSE */
    BOOL_T                         bAudioAdapt;

    /** ֧����ƵЭ���� */
    LONG_32                           lAudioProtCount;

    /** ��Ƶ��׼ HD_AUDIO_PROT_EX_E */
    ULONG_32                          aulAudioProt[IMOS_HD_MAX_AUDIO_PROTOCOL_NUM];

    /** ������Ƶ */
    /** ���鵱ǰ������Ƶ��׼ HD_VIDEO_PROT_EX_E */
    ULONG_32                          ulCurrentMainVideoProt;

    /** ���鵱ǰ������ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32                          ulCurrentMainVideoFmt;

    /** ���鵱ǰ�������� HD_BITRATE_EX_E, Ĭ����дΪ������� */
    ULONG_32                          ulCurrentMainVideoBitRate;

    /** ���鵱ǰ����֡�� HD_FRAME_RATE_EX_E */
    ULONG_32                          ulCurMainFrameRate;

    /** ����Э������ */
    BOOL_T                         bMainVideoProtoAdapt;

    /** ������ʽ���䣬ѡ���������ʽʱ����BOOL_TRUE */
    BOOL_T                         bMainVideoFmtAdapt;

    /** �������� */
    MC_MAIN_VIDEO_CFG_EX_S         stMainVidoCfg;

    /** ����Ƶ֧�ֻ��ټ��� MC_CONF_MIXRATE_EX_E����δ�õ�����0 */
    ULONG_32                          ulMainMixType;

    /** ����֡�������ö�� HD_RATE_AND_FRAME_ADAPT_MODE_EX_E */
    ULONG_32                          ulRateFrameFirst;

    /** ���ʻ�֡�������·�� MC_ADAPT_COUNT_EX_E��ֻ����ѡ�����ʻ�֡����������ʱ��Ч��������1 */
    ULONG_32                          ulAdapterCount;

    /** ������������ֵ */
    ULONG_32                          aulRateAdapterValue[IMOS_MC_MAX_BITRATE_ADAPT_COUNT];

    /** ������Ƶ */
    /** ���鵱ǰ������Ƶ��׼ HD_VIDEO_PROT_EX_E */
    ULONG_32                          ulCurrentRoleVideoProt;

    /** ���鵱ǰ������ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32                          ulCurrentRoleVideoFmt;

    /** ���鵱ǰ�������� HD_BITRATE_EX_E */
    ULONG_32                          ulCurrentRoleVideoBitRate;

    /** ��������� MC_CONF_TYPE_EX_E */
    ULONG_32                          ulConfType;

    /** ���鵱ǰ����֡�� HD_FRAME_RATE_EX_E */
    ULONG_32                          ulCurRoleFrameRate;

    /** �Ƿ������� */
    BOOL_T                         bRoleVideoProtAdapt;

    /** ������ʽ���� */
    BOOL_T                         bRoleVideoFmtAdapt;

    /** �������� */
    MC_ROLE_VIDEO_CFG_EX_S         stRoleVidoCfg;

    /** �������� HD_ROLE_VIDEO_TYPE_EX_E��Ĭ��������ģʽ */
    ULONG_32                          ulRoleVideoMode;

    /** ����֡������  HD_RATE_AND_FRAME_ADAPT_MODE_EX_E��ֻ��ѡ��IMOS_EN_RATE_FRAME_NO��IMOS_EN_RATE_FRAME_FALL */
    ULONG_32                          ulRoleRateFrameAdapt;

    /** ������Ϣ */
    /** �Ƿ�֧���������� */
    BOOL_T                         bAutoFlowCtrl;

    /** �Ƿ�֧���ն�ģʽת��, �ݲ�֧�֣���FALSE�� */
    BOOL_T                         bSiteRequestMode;

    /** ý������㷨 MC_MEDIA_ENCRYPT_EX_E��Ŀǰ��IMOS_EN_MEDIA_ENCRYPT_NO */
    ULONG_32                          ulMediaEncryptType;

    /** �������(H.235)��Ϣ MC_SIGNAL_TYPE_EX_E��Ŀǰ��IMOS_EN_SIGNAL_TYPE_NO */
    ULONG_32                          ulSignalType;
} MC_CONF_MEDIA_INFO_EX_S;

/**
* @struct tagMC_ConfNAAEx
* @brief NAA����
* @attention
*/
typedef struct tagMC_ConfNAAEx
{
    /** �Ƿ����NAA */
    BOOL_T                      bNAA;

    /** NAAֵ���� HD_NAA_TYPE_EX_E */
    ULONG_32                       ulNaaType;
} MC_CONF_NAA_EX_S;

/**
* @struct tagHD_IFramePolicyEx
* @brief I֡�������
* @attention
*/
typedef  struct  tagHD_IFramePolicyEx
{
    /** �Զ�����I֡��ÿ��֡�� HD_IFRAME_NUM_FRAME_EX_E */
    ULONG_32           ulAutoEncIFrameNum;

    /** �Զ�����I֡��ʱ����(��) HD_IFRAME_ATUO_ENC_INTERVAL_EX_E */
    ULONG_32           ulAutoEncIFrameInterval;

    /** ����I֡�����ÿ��֡�� HD_IFRAME_NUM_FRAME_EX_E����δ�ã���0 */
    ULONG_32           ulRequestIFrameNum;

    /** ����I֡�������С���(��) HD_IFRAME_MANUAL_ENC_INTERVAL_EX_E */
    ULONG_32           ulRequestInterval;

    /** ��ӦI֡�����ÿ��֡�� HD_IFRAME_NUM_FRAME_EX_E����δ�ã���0 */
    ULONG_32           ulResponseIFrameNum;

    /** ��ӦI֡�������С���(��) HD_IFRAME_MANUAL_ENC_INTERVAL_EX_E */
    ULONG_32           ulResponseInterval;
} HD_IFRAME_POLICY_EX_S;

/**
* @struct tagHD_APowEstParamEx
* @brief ��Ƶ��������������
* @attention
*/
typedef struct tagHD_APowEstParamEx
{
    /** �ϱ�ʱ��������10msΪ��λ��Ĭ��Ϊ1  */
    LONG_32    lPowerReportGap;

    /** �������ڳ��ȣ���10msΪ��λ  */
    LONG_32    lPowerWinLen;

    /** �������������������
    0��ȡ������������
    1-ȡ������������
    2��ȡ��������ƽ��ֵ��
    3��ȡȡ�����������ֵ��
    4��ȡȡ����������Сֵ      */
    USHORT  usPowerStereoPara;
    UCHAR   szReserved[2];
}HD_APOWEST_PARAM_EX_S;


/**
* @struct tagMC_ConfColorInfoEx
* @brief �������ɫ��Ϣ
* @attention
*/
typedef struct tagMC_ConfColorInfoEx
{
    /** ��Ļ������ɫ�� HD_COLOR_GROUP_TYPE_EX_E ����Ҫ�������д����ֵ��һ���� */
    ULONG_32  ulTitleGroup;

    /** ��������������ɫ�� HD_COLOR_GROUP_TYPE_EX_E */
    ULONG_32  ulOtherGroup;
}MC_CONF_COLOR_INFO_EX_S;


/**
* @union tagHD_IpPreDiffServEx
* @brief IP Precedence ��Diffservֻ��ͬʱ����һ�֡�
* @attention
*/
typedef  union  tagHD_IpPreDiffServEx
{
    /** ip���� HD_IP_PRECEDENCE_TYPE_EX_E */
    ULONG_32            ulIPPrecedence;

    /** Diffserv HD_DIFFSERV_TYPE_EX_E */
    ULONG_32            ulDiffServ;
} HD_IPPRECEDENCE_DIFFSERV_EX_U;

/**
* @struct tagHD_QosServEx
* @brief ip ���Ⱥͷ���������Ϣ
* @attention
*/
typedef  struct tagHD_QosServEx
{
    /** �������� HD_QOS_TYPE_EX_E */
    ULONG_32                             ulQOSType;

    /** ���񼶱� */
    HD_IPPRECEDENCE_DIFFSERV_EX_U     unQOSLerver;
} HD_QOS_SERV_EX_S;


/**
* @struct tagMC_ConfLostPacketPolicyEx
* @brief ���鶪�����Խṹ
* @attention
*/
typedef struct tagMC_ConfLostPacketPolicyEx
{
    /** ���������� */
    LONG_32 lMaxLostPacketRate;

    /** ����������ʱ������λS */
    LONG_32 lMaxLostPacketTime;
} MC_CONF_LP_POLICY_EX_S;

/**
* @struct tagMC_ConfAlarmInfoEx
* @brief ��������澯��Ϣ�ṹ
* @attention
*/
typedef struct tagMC_ConfAlarmInfoEx
{
    /** �Ƿ���������澯����BOOL_TRUE�� */
    BOOL_T bUseVoiceLightAlarm;
} MC_CONF_ALARM_INFO_EX_S;

/**
* @struct tagConfAdvanceInfoEx
* @brief ����߼���Ϣ iMSC��չ��
* @attention
*/
typedef struct tagMC_ConfAdvanceInfoEx
{
    /** ����ý����Ϣ */
    MC_CONF_MEDIA_INFO_EX_S     stConfMediaInfo;

    /** ������Ӧ������ */
    MC_CONF_NAA_EX_S            stNAA;

    /** I֡������� */
    HD_IFRAME_POLICY_EX_S       stIFramePolicy;

    /** �Ƿ�֧���鲥����������ʱ��0 */
    BOOL_T                      bMultiCast;

    /** �Ƿ��Զ������鲥 */
    BOOL_T                      bAutoMultiCast;

    /** ����״̬ MC_CONF_STATUS_EX_E */
    ULONG_32                       ulStatus;

    /** ��ʼ�鲥��־ */
    BOOL_T                      bBeginMulticast;

    /** Ԥ�������ϯ, ����Ϊ����ϯʱ Ϊ��  */
    CHAR                        szSetChairCode[IMOS_RES_CODE_LEN];

    /** Ԥ����鷢���ˣ�δ�õ���Ϊ��  */
    CHAR                        szSetSpeakerCode[IMOS_RES_CODE_LEN];

    /** Ԥ��㲥�᳡����������ʱ��Ϊ��  */
    CHAR                        szSetBroadcastCode[IMOS_RES_CODE_LEN];

    /** ָ�������᳡,�Զ�ʱΪ��  */
    CHAR                        szSetRoleVideoSiteCode[IMOS_RES_CODE_LEN];

    /** Ԥ�������ۿ��Ļ᳡ */
    CHAR                        szSetMainSiteObserve[IMOS_RES_CODE_LEN];

    /** ���㲥�߹ۿ����� MC_BROADCASTED_OBSERVE_EX_E�� δʹ�ã���0 */
    ULONG_32                       ulBroadcastedObserve;

    /** ��Ƶ������������δ�õ�����0  */
    HD_APOWEST_PARAM_EX_S          stApowestParam;

    /** ��ɫ��Ϣ */
    MC_CONF_COLOR_INFO_EX_S        stColorInfo;

    /** ���񼶱�δ�õ�����0 */
    HD_QOS_SERV_EX_S               stQosServ;

    /** �л��㲥ʱ����ϯ�ۿ�ģʽ MC_CHAIR_LOOK_MODE_EX_E */
    ULONG_32                          ulChairLookMode;

    /** �᳡ѡ��ۿ���ö�� MC_SELECT_LOOK_EX_E */
    ULONG_32                          ulSelectLook;

    /** �Ƿ���ǰ��������֪ͨ��ö�� MC_AHEAD_END_CONF_EX_E�� δʵ�� ��ǰ�������鹦��δʵ�֣�δ�õ�����0 */
    ULONG_32                          ulAheadEndConf;

    /** �������� */
    MC_CONF_LP_POLICY_EX_S         stLPPolicy;

    /** ����澯��Ϣ */
    MC_CONF_ALARM_INFO_EX_S        stAlarmInfo;

    /** ����ѡ��ۿ��᳡�Ƿ��Զ�����˷� */
    BOOL_T                         bIsChairWatchedMicAutoOpen;

    /** ���㲥�᳡�Ƿ��Զ�����˷� */
    BOOL_T                         bIsBroadcastedMicAutoOpen;

    /** �᳡������˷��Ƿ��Զ����� */
    BOOL_T                         bIsAllSiteMicAutoOpen;

    /** ͼ���������� HD_SCALER_TYPE_EX_E */
    ULONG_32                          ulScalerType;

    /** ������������ HD_LPR_TYPE_EX_E */
    ULONG_32                          ulLPRType;

    /** ��������ʾ���� HD_TIP_TIME_LEN_TYPE_EX_E */
    ULONG_32                          ulTipEndType;
} MC_CONF_ADVANCE_INFO_EX_S;

/**
 * @struct tagMC_ConfInfoEx
 * @brief ���������Ϣ�͸߼���Ϣ
 * @attention ?? ��Ҫ�����Զ�����/�ֹ����ȵ���Ϣ�� �ò�����ϢΪiMSC��չ��
 */
typedef struct tagMC_ConfInfoEx
{
    /** ������ͨ��Ϣ */
    MC_CONF_NORMAL_INFO_EX_S          stNormalInfo;

    /** ����߼���Ϣ */
    MC_CONF_ADVANCE_INFO_EX_S         stAdvanceInfo;
} MC_CONF_INFO_EX_S;


/**
 * @struct tagConfTopologyNodeEx
 * @brief  �������˽ڵ���Ϣ
 * @attention
 */
typedef struct tagConfTopologyNodeEx
{
    /**  �ڵ���� */
    CHAR                    szNodeCode[IMOS_RES_CODE_LEN];

    /**  �ڵ����� MC_NODE_TYPE_EX_E */
    ULONG_32                   ulNodeType;

    /**  �ڵ��X���� */
    ULONG_32                   ulXpos;

    /**  �ڵ�����y���� */
    ULONG_32                   ulYpos;

    /**  �ڵ��� */
    CHAR                    szNodeName[IMOS_NAME_LEN];

    /** �豸���� */
    CHAR                    szNodeDesc[IMOS_DESC_LEN];
} CONF_TOPOLOGY_NODE_EX_S;

/**
 * @struct tagMC_MultiCastInfoEx
 * @brief �鲥��Ϣ
 * @attention
 */
typedef struct tagMC_MultiCastInfoEx
{
    /** �Ƿ�֧���鲥 */
    BOOL_T      bMultiCast;

    /** �鲥��ַ */
    CHAR        szMultiAddr[IMOS_IPADDR_LEN];

    /** �鲥�û����� */
    CHAR        szMultiUserPwd[IMOS_CONF_PWD_LEN];

    /** ָ�����鲥������ */
    LONG_32        lIfaceCount;

    /** �����鲥������ */
    USHORT      ausIface[IMOS_MC_MAX_LAN_NET_NUM];

    /** ��Ƶ�鲥�˿� */
    ULONG_32       ulMultiPortAudio;

    /** ������Ƶ�鲥�˿�,��Ƶ�鲥�˿ڼ�2 */
    ULONG_32       ulMultiPortVideo;

    /** ������Ƶ�鲥�˿�,�����鲥�˿ڼ�2 */
    ULONG_32       ulMultiPortRoleVideo;
} MC_MULTICAST_INFO_EX_S;






/**
 * @struct tagMC_ConfActiveInfoEx
 * @brief ������Ϣ iMSC��չ
 * @attention
 */
typedef    struct    tagMC_ConfActiveInfoEx
{
    /** ����ID, iMSC��ʹ�� */
    IMOS_ID              idConfId;

    /** ������ */
    CHAR                 szConfName[IMOS_CONF_NAME_LEN];

    /** ��ǰ������ϯ�᳡�� */
    CHAR                 szCurrentChair[IMOS_NAME_LEN];

    /** ��ǰ������ϯ���� */
    CHAR                 szCurrentChairCode[IMOS_RES_CODE_LEN];

    /** ��ǰ���鷢���ߵĻ᳡�� */
    CHAR                 szCurrentSpeaker[IMOS_NAME_LEN];

    /** ���鷢���ߵĻ᳡���� */
    CHAR                 szCurrentSpeakerCode[IMOS_RES_CODE_LEN];

    /** ��ǰ�㲥�᳡�� */
    CHAR                 szCurrentBroadcastSite[IMOS_NAME_LEN];

    /** ��ǰ�㲥�᳡���� */
    CHAR                 szCurrentBroadcastCode[IMOS_RES_CODE_LEN];

    /** �����ۿ��᳡�� */
    CHAR                 szMainSiteBWSite[IMOS_NAME_LEN];

    /** �����ۿ��᳡���� */
    CHAR                 szMainSiteBWSiteCode[IMOS_RES_CODE_LEN];

    /** Ԥ��Ļ�����ϯ�᳡�� */
    CHAR                 szSetChair[IMOS_NAME_LEN];

    /** Ԥ�������ϯ�᳡���� */
    CHAR                 szSetChairCode[IMOS_RES_CODE_LEN];

    /** ����FECC�����ߵĻ᳡�� */
    CHAR                 szFECCController[IMOS_NAME_LEN];

    /** ����FECC�����߻᳡����*/
    CHAR                 szFECCControllerCode[IMOS_RES_CODE_LEN];

    /** ����FECC�ܿ��ߵĻ᳡�� */
    CHAR                 szFECCControlled[IMOS_NAME_LEN];

    /** ����FECC�ܿ��߻᳡����*/
    CHAR                 szFECCControlledCode[IMOS_RES_CODE_LEN];

    /** ����˫��Դ�Ļ᳡�� */
    CHAR                 szSetRoleVideoSite[IMOS_NAME_LEN];

    /** ����˫��Դ�Ļ���� */
    CHAR                 szSetRoleVideoSiteCode[IMOS_RES_CODE_LEN];

    /** ���鵱ǰ˫��Դ�Ļ᳡�� */
    CHAR                 szCurRoleVideoSite[IMOS_NAME_LEN];

    /** ���鵱ǰ˫��Դ�Ļ᳡���� */
    CHAR                 szCurRoleVideoSiteCode[IMOS_RES_CODE_LEN];

    /** ���鿪ʼʱ�� */
    LONG_32                 lConfBeginTime;

    /** �������ʱ�� */
    LONG_32                 lLastTime;

    /** �᳡���� */
    LONG_32                 lSiteCount;

    /** ����ģʽ MC_CONF_MODE_EX_E */
    ULONG_32                ulConfMode;

    /** ���߻᳡�� */
    LONG_32                 lLiveSiteCount;
} MC_CONF_ACTIVE_INFO_EX_S;

/**
* @struct tagMC_SiteMediaInfoEx
* @brief �᳡�����״̬��Ϣ
* @attention
*/
typedef struct tagMC_SiteMediaInfoEx
{
    /** ���ʱ�� */
    LONG_32                    lJoinTime;

    /** �Ƿ��� */
    BOOL_T                  bIsSilence;

    /** �Ƿ���� */
    BOOL_T                  bIsMute;

    /** �Ƿ���������Ƶ */
    BOOL_T                  bSendMainVideo;

    /** �Ƿ��͸�����Ƶ */
    BOOL_T                  bSendRoleVideo;

    /** ���д��� HD_BITRATE_EX_E */
    ULONG_32                   ulBandWidth;

    /** ��ǰ���᳡�ۿ��Ļ᳡���� */
    CHAR                    szTermWatchedCode[IMOS_RES_CODE_LEN];

    /** ��ǰ���᳡�ۿ��Ļ᳡���� */
    CHAR                    szTermWatchedName[IMOS_NAME_LEN];
} MC_CONF_SITE_STATUS_INFO_EX_S;

/**
* @struct tagHD_AudioCapEx
* @brief ��Ƶ����
* @attention
*/
typedef  struct    tagHD_AudioCapEx
{
    /** ��Ƶ������ʽ HD_AUDIO_PROT_EX_E */
    ULONG_32            ulAudio;

    /** ��Ƶ������bps */
    LONG_32             lAudBitRate;

    /** ������ */
    LONG_32             lSampleRate;

    /** �Ƿ�H235 */
    BOOL_T           bH235;
} HD_AUDIO_CAP_EX_S;


/**
* @struct tagHD_VideoFmtFREx
* @brief ��Ƶͼ���ʽ��֡�ʽṹ
* @attention
*/
typedef  struct    tagHD_VideoFmtFREx
{
    /** ͼ���ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32             ulFmt;

    /** ��Ƶͼ��֡�� */
    LONG_32              lFrameRate;

    /** ��Ƶͼ��֡������ */
    BOOL_T            bFrameRateAdapt;
} HD_VIDEO_FMT_FR_EX_S;

/**
* @struct tagHD_VideoCapEx
* @brief ��Ƶ����
* @attention
*/
typedef  struct    tagHD_VideoCapEx
{
    /** ��Ƶ�����Э�� HD_VIDEO_PROT_EX_E */
    ULONG_32                ulVideo;

    /** ͼ���ʽ���� */
    LONG_32                 lFmtCount;

    /** ��Ƶͼ���ʽ��֡�� */
    HD_VIDEO_FMT_FR_EX_S    astFmt[IMOS_HD_MAX_VIDEO_FORMAT_NUM];

    /** ��Ƶͼ������bps */
    LONG_32                 lBitrate;

    /** ��Ƶ��д�������� */
    BOOL_T               bBitrateAdapt;

    /** �Ƿ�H235 */
    BOOL_T               bH235;

    /** �Ƿ�H239 */
    BOOL_T               bH239;

    /** ��ɫ���� HD_ROLE_VIDEO_TYPE_EX_E */
    ULONG_32                ulRole;
} HD_VIDEO_CAP_EX_S;

/**
* @struct tagHD_DataCapEx
* @brief ��������
* @attention
*/
typedef  struct    tagHD_DataCapEx
{
    /** ���ݸ�ʽ HD_DATA_PROT_EX_E */
    ULONG_32            ulData;

    /** ������bps */
    LONG_32             lBitRate;

    /** �Ƿ�H235 */
    BOOL_T           bH235;
} HD_DATA_CAP_EX_S;

/**
* @struct tagHD_ControlCapEx
* @brief ��������
* @attention
*/
typedef  struct    tagHD_ControlCapEx
{
    /** ����������ʽ HD_CTRL_PROT_EX_E */
    ULONG_32   ulCtrl;
} HD_CTRL_CAP_EX_S;

/**
* @union tagHD_CapSetUnEx
* @brief ������������
* @attention
*/
typedef  union    tagHD_CapSetUnEx
{
    /** ��Ƶ���� */
    HD_AUDIO_CAP_EX_S   stAudio;

    /** ��Ƶ���� */
    HD_VIDEO_CAP_EX_S   stVideo;

    /** �������� */
    HD_DATA_CAP_EX_S    stData;

    /** �������� */
    HD_CTRL_CAP_EX_S    stCtrl;
} HD_CAP_SET_EX_U;

/**
* @struct tagHD_CapItemEx
* @brief ������ṹ��
* @attention
*/
typedef  struct    tagHD_CapItemEx
{
    /** �������� HD_CAP_TYPE_EX_E */
    ULONG_32               ulCapType;

    /** �������� */
    HD_CAP_SET_EX_U     unCap;
} HD_CAP_ITEM_EX_S;

/**
* @struct tagMC_SiteCapStEx
* @brief ��������ȷ���Ļ᳡����
* @attention
*/
typedef  struct    tagMC_SiteCapStEx
{
    /*��������*/
    LONG_32          lCapCount;

    /*�᳡����*/
    HD_CAP_ITEM_EX_S astCap[IMOS_HD_MAX_SIM_CAP_NUM];
}MC_SITE_CAP_EX_S;

/**
 * @struct tagMC_SiteInfo
 * @brief �᳡�������Ϣ
 * @attention
 */
typedef struct tagMC_SiteInfoEx
{
    /** �᳡���� */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** �᳡���ڻ����Ψһ��־ */
    IMOS_ID  idConfId;

    /** �᳡E164���� */
    CHAR     szE164[IMOS_NAME_LEN];

    /** �᳡���� */
    CHAR     szAlias[IMOS_NAME_LEN];

    /** �᳡���� */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** ѡ��ۿ��Ļ᳡���� */
    CHAR     szLookSiteCode[IMOS_RES_CODE_LEN];

    /** ��ʾ���᳡�������᳡�ۿ�ʱ�õĻ����ID */
    CHAR     szMixerCode[IMOS_RES_CODE_LEN];

    /** H323CC��������� */
    ULONG_32    ulCCContext;

    /** �᳡��Ƶͨ�����ڵ�VP��� */
    LONG_32     lVPID;

    /** �᳡״̬������Ϣ */
    MC_CONF_SITE_STATUS_INFO_EX_S   stSiteConf;

    /** �᳡���� */
    MC_SITE_CAP_EX_S                stCap;

    /** �᳡��IP��ַ */
    CHAR          szIP[IMOS_IPADDR_LEN];
} MC_SITE_INFO_EX_S;

/**
 * @struct tagMC_ConfSiteListDefEx
 * @brief �����ڻ����еĻ᳡�б���Ϣ
 * @attention
 */
typedef struct tagMC_ConfSiteListDefEx
{
    /** �᳡���� */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** �᳡����MCU�ı��� */
    CHAR     szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** �᳡��MCU�ϵ�ID��-1Ϊ��Ч�Ļ᳡ID */
    LONG_32     lSiteIdInMcu;

    /** �᳡���� */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** �᳡״̬������Ϣ */
    MC_CONF_SITE_STATUS_INFO_EX_S   stSiteConf;

    /** �᳡״̬ MC_SITE_STATUS_EX_E */
    ULONG_32              ulSiteStatus;

    /** �����᳡���ߵ�ʱ�������жϻ᳡���ߵ�ԭ�� HD_RESULT_EX_E */
    ULONG_32              ulResult;

    /** �ն�IP��ַ */
    CHAR               szIpAddr[IMOS_IPADDR_LEN];

    /** �ն�����Ƶʹ������ MC_TERM_TYPE_EX_E */
    ULONG_32              ulTermType;

    /** �ն��ܴ��� */
    LONG_32               lBandWidth;

    /** �ն�����(TERM_QUERY_TYPE_E) */
    ULONG_32              ulQueryTermType;

    /** �л���ʽ MC_LINK_LAYER_SWITCH_MODE_EX_E */
    ULONG_32              ulSwitchMode;

    /** ��ǰʹ�õ���· MC_LINK_LAYER_TYPE_EX_E */
    ULONG_32              ulCurLinkLayer;

    /** ����·������״̬ MC_LINK_LAYER_STATE_EX_E */
    ULONG_32              aulLayerState[IMOS_EN_LINK_LAYER_TYPE_COUNT];

    /** ����澯״̬ MC_TERM_ALARM_STATUS_EX_E */
    ULONG_32              ulAlarmStatus;
} MC_CONF_SITE_LIST_EX_S;


/**
 * @struct tagMC_ConfSiteNameEx
 * @brief  �᳡������Ϣ
 * @attention
 */
typedef struct tagMC_ConfSiteNameEx
{
    /** �᳡���� */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

   /** �᳡���� */
    CHAR     szSiteName[IMOS_NAME_LEN];
}MC_CONF_SITE_NAME_EX_S;



/**
* @struct tagMC_NetStatusEx
* @brief ���ڲ���
* @attention
*/
typedef struct tagMC_NetStatusEx
{
    /** �����Ƿ����ñ�־ */
    BOOL_T      bUseFlag;

    /** ���ڱ�ʶ */
    CHAR        szCardName[IMOS_NETCARD_NAME_LEN];

    /** ����״̬, BOOL_TRUE��ʾ�Ѿ��������� */
    BOOL_T      bConnect;

    /** IP��ַ */
    CHAR        szIPAddr[IMOS_IPADDR_LEN];

    /** �������� */
    CHAR        szSubmask[IMOS_IPADDR_LEN];

    /** ���ص�ַ */
    CHAR        szGateWay[IMOS_IPADDR_LEN];

    /** ����˫��ģʽ HD_NETCARD_DUPLEX_TYPE_EX_E */
    ULONG_32       ulCardDuplexType;

    /** ����֧������ HD_NETCARD_RATE_EX_E */
    ULONG_32       ulCardRate;

    /** BOOL_TRUEʹ�ù�� */
    BOOL_T      bUseLightNet;
} MC_NET_STATUS_EX_S;


/**
* @struct tagMC_McuLanIPEx
* @brief ������Ϣ�����ṹ���޸�ʱulMask��ʾ���ں�(��������λ��ʾ);
* @attention
*/
typedef struct tagMC_McuLanIPEx
{
    /** ���ڻ�����Ϣ */
    MC_NET_STATUS_EX_S     astLanAddr[IMOS_MC_MAX_MCU_IP_NUM];
}MC_MCU_LAN_IP_EX_S;

/**
* @struct tagMC_BackupLayer_IPCfgEx
* @brief ������·���Ե� IP ����
* @attention
*/
typedef struct tagMC_BackupLayer_IPCfgEx
{
    /** lo/eth1/eth2 ��ַ */
    MC_NET_STATUS_EX_S astLanAddr[IMOS_EN_LINK_LAYER_NIC_TYPE_COUNT];
} MC_BACKUP_LAYER_IP_CFG_EX_S;

/**
 * @struct tagMC_MCUIPCfgEx
  * @brief MCU IP ������Ϣ
 * @attention
 */
typedef struct tagMC_MCUIPCfgEx
{
    /** �Ƿ����ñ�����·���� */
    BOOL_T                        bUseBakLayer;

    /** MCU��IP��Ϣ */
    MC_MCU_LAN_IP_EX_S            stLanIP;

    /** ˫��·���ݲ��Ե� IP ���� */
    MC_BACKUP_LAYER_IP_CFG_EX_S    stBakIPInfo;
} MC_MCU_IP_CFG_S;


/**
 * @struct tagMC_MCURouteEx
 * @brief ����·�ɱ�ṹ
 * @attention
 */
typedef struct tagMC_MCURouteEx
{
    /** Ŀ��IP��ַ */
    CHAR             szDestAddr[IMOS_IPADDR_LEN];

    /** ���ص�ַ */
    CHAR             szGateway[IMOS_IPADDR_LEN];

    /** �������� */
    CHAR             szSubmask[IMOS_IPADDR_LEN];

    /** ����NATʱ�Ƿ����ⲿ·�� */
    BOOL_T           bExtern;
} MC_MCU_ROUTE_EX_S;

/**
 * @struct tagMC_MCULanTableEx
 * @brief LAN����Ѿ����ӵ��ⲿ��������ÿ���Ѿ����ӵ����ڵ�·�ɱ����Ϣ
 * @attention
 */
typedef struct tagMC_MCULanTableEx
{
    /** �Ѿ����ӵ����ڸ��� */
    ULONG_32              ulCount;

    /** ÿ�����ڵ�·�ɼ�¼�� */
    LONG_32               alRouteCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** ·�ɱ� */
    MC_MCU_ROUTE_EX_S  astRouteTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ROUTE_NUM];
} MC_MCU_LAN_ROUTE_TABLE_EX_S;


/**
* @struct tagMC_MCUARPEx
* @brief ����ARP�ṹ
* @attention
*/
typedef struct tagMC_MCUARPEx
{
    /** IP��ַ */
    CHAR  szAddr[IMOS_IPADDR_LEN];

    /** MAC��ַ */
    CHAR  szMACAddr[IMOS_MC_MAX_MAC_ADDR_LEN];

    /** ���ڱ�ʶ */
    CHAR  szCardName[IMOS_NETCARD_NAME_LEN];
} MC_MCU_ARP_EX_S;

/**
 * @struct tagMC_MCUARPTableEx
 * @brief LAN����Ѿ����ӵ��ⲿ��������ÿ���Ѿ����ӵ����ڵ�ARP�����Ϣ
 * @attention
 */
typedef struct tagMC_MCUARPTableEx
{
    /** �Ѿ����ӵ����ڸ��� */
    ULONG_32              ulCount;

    /** ÿ�����ڵ�ARP��¼�� */
    LONG_32               alARPCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** ARP�� */
    MC_MCU_ARP_EX_S    astARPTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ARP_NUM];
} MC_MCU_ARP_TABLE_EX_S;

/**
* @struct tagHD_BoardSeriesInfoEx
* @brief ���ڵ����ò���
* @attention
*/
typedef struct tagHD_BoardSeriesInfoEx
{
    /** ÿ������� HD_COM_BIT_RATE_EX_E */
    ULONG_32              ulBitRate;

    /** ����λ */
    USHORT             usData;

    /** �����ֶ������ֽڶ��� */
    USHORT             usReserve;

    /** ��żУ�� */
    BOOL_T             bParityCheck;

    /** ֹͣλ */
    USHORT             usStopBit;

    /** �����ֶ������ֽڶ��� */
    USHORT             usReserve1;

    /** �������� */
    BOOL_T             bFlowControl;
} HD_BOARD_SERIAL_INFO_EX_S;

/**
* @struct tagHD_BoardNormalInfoEx
* @brief ÿ�����Ļ�����Ϣ
* @attention
*/
typedef struct tagHD_BoardNormalInfoEx
{
    /** MCU����屾�� */
    CHAR        szMcuSoftVersion[IMOS_SOFT_VERSION_LEN];

    /** �豸���� */
    CHAR        szDeviceName[IMOS_SOFT_VERSION_LEN];

    /** Ӳ���汾�� */
    CHAR        szHardDeviceVision[IMOS_SOFT_VERSION_LEN];

    /** UBoot�汾�� */
    CHAR        szUBootVersion[IMOS_SOFT_VERSION_LEN];

    /** Kernel�汾�� */
    CHAR        szKernelVersion[IMOS_SOFT_VERSION_LEN];

    /** Fpga�汾�� */
    CHAR        szFpgaVersion[IMOS_SOFT_VERSION_LEN];

    /** Cpld�汾��(�ֹ�������CPLD), 0λ��ʾCPLD0�汾(��ֵ��ʾ), 1λ��ʾCPLD1 */
    CHAR        szCpldVersion[IMOS_SOFT_VERSION_LEN];

    /** ���Ӳ�λ�� */
    USHORT      usSlot;

    /** �����ֶ������ֽڶ��� */
    USHORT      usReserve;

    /** ����IP��ַ */
    CHAR        szIpAddr[IMOS_IPADDR_LEN];

    /** ���������˿� */
    ULONG_32       ulPort;

    /** CPU�¶� */
    LONG_32       ulCPUTemperature;

    /** CPU���ȵ�ת�� HD_FAN_STATE_EX_E */
    ULONG_32       ulFanState;

    /** CPU��Դʹ���� */
    ULONG_32       ulUsedCPU;

    /** ���ڴ��С */
    ULONG_32       ulTotalMemory;

    /** �ڴ���Դʹ���� */
    ULONG_32       ulUsedM;

    /** ����������Ϣ */
    HD_BOARD_SERIAL_INFO_EX_S    stSeriesInfo;

    /** ����汾�� */
    CHAR        szMcuExVersion[IMOS_SOFT_VERSION_LEN];

    /** ����ʱ�� */
    CHAR        szMeMakeTime[50];

    /** �����ֶ������ֽڶ��� */
    USHORT      usReserve2;
    /** �����汾 */
    CHAR        szDrvVersion[IMOS_SOFT_VERSION_LEN];

    /** DSP�汾�� */
    CHAR        szDSPVersion[IMOS_SOFT_VERSION_LEN];

    /** �豸�ͺ� */
    CHAR        szDevModel[IMOS_SOFT_VERSION_LEN];

    /** �豸���к� */
    CHAR        szSerialNum[IMOS_HD_MAX_SOFT_VERSION_LEN + 1];

    /** ��Ƶ������ */
    CHAR        szAudEstDevDSP[IMOS_SOFT_VERSION_LEN];

    /** ��Ƶ����� */
    CHAR        szAudMixDevDSP[IMOS_SOFT_VERSION_LEN];

    /** ��Ƶ������*/
    CHAR        szVidDeCodeDevDSP[IMOS_SOFT_VERSION_LEN];

    /** ��Ƶ������ */
    CHAR        szVidEnCodeDevDSP[IMOS_SOFT_VERSION_LEN];
    /** �忨����ʱ�� */
    LONG_32        lBootTime;
} HD_BOARD_NORMAL_INFO_EX_S;


/**
* @struct tagHD_LanInfoEx
* @brief LAN�����Ϣ,����״̬��ʾ�����Ƿ��������硣
* @attention
*/
typedef struct tagHD_LanInfoEx
{
    /** LAN�������Ϣ */
    HD_BOARD_NORMAL_INFO_EX_S    stLANBoard;

    /** LAN���SFP1���Ƿ���λ */
    BOOL_T                    bSFP1;

    /** LAN���SFP1���Ƿ���λ */
    BOOL_T                    bSFP2;

    /** LAN���GE3���Ƿ���λ */
    BOOL_T                    bGE3;

    /** LAN���GE4���Ƿ���λ */
    BOOL_T                    bGE4;

    /** LAN���SFP1������״̬ */
    BOOL_T                    bConnect1;

    /** LAN���SFP1������״̬ */
    BOOL_T                    bConnect2;

    /** LAN���GE3������״̬ */
    BOOL_T                    bConnect3;

    /** LAN���GE4������״̬ */
    BOOL_T                    bConnect4;

    /** ��������1 */
    USHORT                    usNet1;

    /** ��������2 */
    USHORT                    usNet2;

    /** ��������3 */
    USHORT                    usNet3;

    /** ��������4 */
    USHORT                    usNet4;
} HD_LAN_INFO_EX_S;

/**
* @struct tagHD_BoardDSPInfoEx
* @brief ÿ��DSP��ʹ�����
* @attention
*/
typedef struct tagHD_BoardDSPInfoEx
{
    /** DSP״̬ HD_DSP_STATUS_EX_E */
    ULONG_32                ulDspStat;

    /** DSP�ϵĻ��� */
    IMOS_ID              aidConfId[IMOS_HD_MAX_DSP_NUM_PER_CONF];
} HD_BOARD_DSP_INFO_EX_S;


/**
* @struct tagHD_VPAPInfoEx
* @brief ÿ��VP�塢AP�������,HD_DSP_INFO_EX_S ������ÿ��DSP�ϵĻ���
* @attention
*/
typedef struct tagHD_VPAPInfoEx
{
    /** ���������Ϣ */
    HD_BOARD_NORMAL_INFO_EX_S  stBoard;

    /** ����DSP���� */
    ULONG_32                   ulDSP;

    /** DSP�б� */
    HD_BOARD_DSP_INFO_EX_S  astDSPInfo[IMOS_HD_MAX_DSP_PER_PLANK];
} HD_VP_AP_INFO_EX_S;

/**
 * @union tagHD_DeviceUnionEx
 * @brief VP��AP��LAN��MC��MC������Ϣ��һ�֡�
 * @attention
 */
typedef  union  tagHD_DeviceUnionEx
{
    /** MC����Ϣ */
    HD_BOARD_NORMAL_INFO_EX_S         stMCInfo;

    /** MC������Ϣ */
    HD_BOARD_NORMAL_INFO_EX_S         stMCBInfo;

    /** LAN����Ϣ */
    HD_LAN_INFO_EX_S                  stLanInfo;

    /** VP����Ϣ */
    HD_VP_AP_INFO_EX_S                stVPInfo;

    /** AP����Ϣ */
    HD_VP_AP_INFO_EX_S                stAPInfo;
} HD_DEVICE_EX_U;




/**
 * @struct tagMC_TermVideoCfgEx
 * @brief ����ն�����������Ƶ֧�ֵı�׼����ʽ�����ʡ�֡�ʵ���Ϣ�Ľṹ
 * @attention
 */
typedef struct tagMC_TermVideoCfgEx
{
    /** ��Ƶ��׼�ĸ�������1 */
    LONG_32                lVideoProtNum;

    /** ֧�ֵ���Ƶ��׼ HD_VIDEO_PROT_EX_E��ֻѡ��1�� */
    ULONG_32               aulVideoProt[IMOS_EN_VID_PROT_COUNT];

    /** ��Ƶ��߸�ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32               ulVideoFmt;

    /** ��Ƶ���֡�� HD_FRAME_RATE_EX_E */
    ULONG_32               ulFrameRate;

    /** ��Ƶ��߱����� HD_BITRATE_EX_E */
    ULONG_32               ulVideoRate;
} MC_TERM_VIDEO_CFG_EX_S;

/**
 * @struct tagMC_TermRoleVideoCfgEx
 * @brief ����ն����ø�����Ƶ֧�ֵı�׼����ʽ�����ʡ�֡�ʵ���Ϣ�Ľṹ
 * @attention
 */
typedef struct tagMC_TermRoleVideoCfgEx
{
    /** ��Ƶ��׼�ĸ�������1  */
    LONG_32                lVideoProtNum;

    /** ֧�ֵ���Ƶ��׼ HD_VIDEO_PROT_EX_E��ѡ��1��  */
    ULONG_32               aulVideoProt[IMOS_EN_VID_PROT_COUNT];

    /** ���Ƶ��߸�ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32               ulVideoFmt;

    /** ���Ƶ���֡�� HD_FRAME_RATE_EX_E */
    ULONG_32               ulFrameRate;

    /** ��Ƶ��߱����� HD_BITRATE_EX_E */
    ULONG_32               ulVideoRate;

    /** ��Ƭ��Ƶ��߸�ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32               ulPresentationVideoFmt;

    /** ��Ƭ��Ƶ���֡�� HD_FRAME_RATE_EX_E */
    ULONG_32               ulPresentationFrameRate;
} MC_TERM_ROLEVIDEO_CFG_EX_S;



/**
* @struct tagHD_SimpleChannelEx
* @brief ����ý��ͨ���Ķ�̬��Ϣ
* @attention
*/
typedef  struct  tagHD_SimpleChannelEx
{
    /** ͨ������ */
    /** ͨ���������� HD_CAP_TYPE_EX_E */
    ULONG_32                   ulCapType;

    /** ͨ������ HD_CHN_DIRECTION_EX_E */
    ULONG_32                   ulDirect;

    /** ͨ��������Ϣ */
    HD_CAP_SET_EX_U         unSimpleCap;

    /** BOOL_TRUE, ���� */
    BOOL_T                  bEncrypt;

    /** Զ�˵�ַ */
    CHAR                    szRemoteIP[IMOS_IPADDR_LEN];

    /** Զ�˶˿� 0-65535 */
    ULONG_32                   ulRemotePort;

    /** ���˵�ַ */
    CHAR                    szLocalIP[IMOS_IPADDR_LEN];

    /** ���˶˿� 0-65535 */
    ULONG_32                   ulLocalPort;

    /** ͨ��״̬��Ϣ */
    /** ͨ������ */
    ULONG_32                   ulBiteRateCurrent;

    /** ��ͨ���������� */
    LONG_32                    lTotalPacketNum;

    /** ��ͨ���������� */
    LONG_32                    lLostPacketNum;

    /** ʵʱ������, ����ֵ��ʾ���ǷŴ�1000��, ʵ�ʻ�ȡ�İٷֱ�ΪlMaxLostPackRate */
    LONG_32                    lLostRateCurrent;

    /** ��ֵ������, ����ֵ��ʾ���ǷŴ�1000��, ʵ�ʻ�ȡ�İٷֱ�ΪlMaxLostPackRate */
    LONG_32                    lLostRatePeak;

    /** JB */
    /** ��ǰJB(JitterBuffer)��С */
    LONG_32                    lJBSizeCurrent;

    /** ��ֵJB(JitterBuffer)��С */
    LONG_32                    lJBSizePeak;

    /** ��ǰͨ����NAA������� */
    LONG_32                    lNAACachePackNumCurrent;

    /** ��ֵͨ����NAA������� */
    LONG_32                    lNAACachePackNumPeak;

    /** �����ط����� */
    LONG_32                    lReSendNumRequested;

    /** ʵ���յ����ط����� */
    LONG_32                    lResendNumReceved;
} HD_SIMPLE_CHANNEL_EX_S;

/**
 * @struct tagMC_SiteCapSetEx
 * @brief �ն�����ͨ������Ϣ
 * @attention
 */
typedef  struct    tagMC_SiteCapSetEx
{
    /** ͨ������ */
    LONG_32                     lCount;

    /** ���� */
    HD_SIMPLE_CHANNEL_EX_S   astCap[IMOS_HD_MAX_SIM_CAP_NUM];
} MC_SITE_CAP_SET_EX_S;


/**
* @struct tagMC_IPPortEx
* @brief IP/Port �鲥IP
* @attention
*/
typedef struct tagMC_IPPortEx
{
    /** IP��ַ */
    CHAR          szIP[IMOS_IPADDR_LEN];

    /** ��ʼ�˿�, ����ռ��2��,��������Ƶ����Ƶ�˿�
    * ��ʼ�˿ںţ����� 100��
    * ��ô100��101 ����Ƶ��102 103 ����Ƶ��
    * Ҳ����˵��ͨ��ָ��һ���˿ڣ��Ϳ��������Ƶ����Ƶ�Ķ˿ںš�
    */
    ULONG_32         ulPort;
} MC_IP_PORT_EX_S;

/**
 * @struct tagMC_MulticastEx
 * @brief ��ΨһID���鲥�ṹ
 * @attention
 */
typedef struct tagMC_MulticastEx
{
    /** �鲥��ΨһID */
    LONG_32                              lMulticastID;

    /** �����鲥��ַ */
    MC_IP_PORT_EX_S                   stMulticastIP;
}MC_MULTICAST_EX_S;


/**
 * @struct tagMC_MCUConfNATEx
 * @brief NAT����
 * @attention
 */
typedef struct tagMC_MCUConfNATEx
{
    /** �Ƿ�����NAT */
    BOOL_T              abUseNAT[IMOS_MC_MAX_MCU_IP_NUM];

    /** NAT�ⲿ��ַ */
    CHAR                aszNatAddr[IMOS_MC_MAX_MCU_IP_NUM][IMOS_IPADDR_LEN];

    /** ���п�ʼ�˿� */
    ULONG_32               ulBeginCallPort;

    /** ���н����˿� */
    ULONG_32               ulEndCallPort;

    /** ý�忪ʼ�˿� */
    ULONG_32               ulBeginRTPPort;

    /** ý������˿� */
    ULONG_32               ulEndRTPPort;
} MC_MCU_CONFIG_NAT_EX_S;

/**
 * @struct tagMC_MCUNTPInfoEx
 * @brief NTP����
 * @attention
 */
typedef struct tagMC_MCUNTPInfoEx
{
    /** �Ƿ�����NTP */
    BOOL_T              bUseNTP;

    /** NTP��������ַ */
    CHAR                szNTPServerAddr[IMOS_IPADDR_LEN];

    /** NTPʱ��ͬ����� MC_NTP_TIME_SYNCH_INTERVAL_EX_E */
    ULONG_32               ulSynchInterval;
} MC_MCU_NTP_INFO_EX_S;

/**
 * @struct tagHD_ColorValueEx
 * @brief ��ɫRGBֵ�ṹ
 * @attention
 */
typedef struct tagHD_ColorValueEx
{
    /** ��ɫRֵ */
    UCHAR      ucRed;

    /** ��ɫGֵ */
    UCHAR      ucGreen;

    /** ��ɫBֵ */
    UCHAR      ucBlue;

    /** ͸���� */
    UCHAR      ucAlfa;
} HD_COLOR_VALUE_EX_S;

/**
 * @struct tagHD_McuColorValueEx
 * @brief ��ɫ���ýṹ
 * @attention
 */
typedef struct tagHD_McuColorValueEx
{
    HD_COLOR_VALUE_EX_S    astOSDValue[IMOS_EN_COLOR_GROUP_COUNT][IMOS_EN_COLOR_TABLE16_TYPE_COUNT];
    HD_COLOR_VALUE_EX_S    astTitleValue[IMOS_EN_COLOR_GROUP_COUNT][IMOS_EN_COLOR_TABLE4_TYPE_COUNT];
}HD_MCU_COLOR_VALUE_EX_S;

/**
* @struct tagMC_MCUConfigAlarmEx
* @brief ����澯����
* @attention
*/
typedef struct tagMC_MCUConfigAlarmEx
{
    /** ����澯��������ַ */
    CHAR   szRemoteIP[IMOS_IPADDR_LEN];

    /** ����澯�������˿� */
    ULONG_32 ulRemotePort;

    /** ����澯���ض˿� */
    ULONG_32 ulLocalPort;

    /** ��Դ1��������澯�� */
    ULONG_32 ulPower1AlarmID;

    /** ��Դ2��������澯�� */
    ULONG_32 ulPower2AlarmID;
} MC_MCU_CONFIG_ALARM_EX_S;

/**
* @struct tagMC_MCUConfigNormalEx
* @brief ϵͳ��������
* @attention
*/
typedef struct tagMC_MCUConfigNormalEx
{
    /** ����H323ID */
    CHAR                  szAlias[IMOS_MCU_NAME_LEN];

    /** ϵͳʱ�� */
    LONG_32                  lSystemTime;

    /** ʱ�� HD_SYS_TIMEZONE_EX_E */
    ULONG_32                 ulTimeZone;

    /** ϵͳ���� HD_SYS_LANGUAGE_EX_E */
    ULONG_32                 ulLanguage;
} MC_MCU_CONFIG_NORMAL_EX_S;

/**
* @struct tagMC_MCUConfigGKEx
* @brief ��������
* @attention
*/
typedef struct tagMC_MCUConfigGKEx
{
    /** �Ƿ�ʹ������, �Ƿ��������� MC_GK_TYPE_EX_E */
    ULONG_32              ulGKType;

    /** �ⲿGK IP��ַ */
    CHAR               szGKAddr[IMOS_IPADDR_LEN];
} MC_MCU_CONFIG_GK_EX_S;

/**
* @struct tagHASystem_InfoEx
* @brief ˫��ϵͳ������Ϣ
* @attention
*/
typedef struct tagHASystem_InfoEx
{
    /** ��������IP��ַ������¼MCU��IP��ַ */
    CHAR                szLocIp[IMOS_IPADDR_LEN];

    /** Զ��IP��ַ�� ������IP��ַ */
    CHAR                szRemoteIp[IMOS_IPADDR_LEN];

    /** �������Ķ˿ںţ� �涨�� 0 */
    ULONG_32               ulLocPort;

    /** Զ�˶˿ںţ� �涨�� 0 */
    ULONG_32               ulRemotePort;

    /** ����BAK��״̬ BAK_STATE_EX_E */
    ULONG_32               ulCfgBakState;

    /**  �������汾ΪԶ��ҵ���ַ */
    CHAR                szLoIp[IMOS_IPADDR_LEN];
}HA_SYSTEM_INFO_EX_S;

/**
* @struct tagHD_MPPromptCfgEx
* @brief ����ʹ��Ĭ����ʾ����ͼƬ
* @attention
*/
typedef  struct  tagHD_MPPromptCfgEx
{
    /** BOOL_TRUE, ʹ��Ĭ����ʾ�� */
    BOOL_T          bUseDefaultPromptSound;

    /** BOOL_TRUE, ʹ��Ĭ����ʾͼƬ */
    BOOL_T          bUseDefaultPromptPic;
} HD_MP_PROMPT_CFG_EX_S;

/**
* @struct tagMC_MCULanARPTableEx
* @brief LAN����Ѿ����ӵ��ⲿ��������ÿ���Ѿ����ӵ����ڵ�ARP��·�ɱ����Ϣ
* @attention
*/
typedef struct tagMC_MCULanARPTableEx
{
    /** �Ѿ����ӵ����ڸ��� */
    ULONG_32              ulCount;

    /** ÿ�����ڵ�·�ɼ�¼�� */
    LONG_32               alRouteCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** ·�ɱ� */
    MC_MCU_ROUTE_EX_S  astRouteTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ROUTE_NUM];

    /** ÿ�����ڵ�ARP��¼�� */
    LONG_32               alARPCount[IMOS_MC_MAX_LAN_NET_NUM];

    /** ARP�� */
    MC_MCU_ARP_EX_S    astARPTable[IMOS_MC_MAX_LAN_NET_NUM][IMOS_MC_MAX_LAN_ARP_NUM];
} MC_MCU_LAN_ROUTE_ARP_TABLE_EX_S;


/**
* @struct tagMC_VersionCfgEx
* @brief �汾����
* @attention
*/
typedef struct tagMC_VersionCfgEx
{
    /** �Ƿ���ʾ�汾 */
    BOOL_T bIsTestVersion;

    /** �Ƿ�֧���鲥 */
    BOOL_T bSupportMulticast;

    /** �Ƿ�֧��Nat */
    BOOL_T bSupportNat;
} MC_VERSION_CONFIG_EX_S;


/**
 * @struct tagMC_MCUConfigAllEx
 * @brief MCU����
 * @attention
 */
typedef struct tagMC_MCUConfigAllEx
{
    /** ˫��·�������� �Ƿ����ñ�����·���� */
    BOOL_T                               bUseBakLayer;

    /** ˫��·�������� ˫��·����IP���� */
    MC_BACKUP_LAYER_IP_CFG_EX_S          stBackupLanIP;

    /** ����澯���� */
    MC_MCU_CONFIG_ALARM_EX_S             stConfigAlarm;

    /** �������� */
    MC_MCU_LAN_IP_EX_S                    stConfAddr;

    /** MCU��ͨ��Ϣ */
    MC_MCU_CONFIG_NORMAL_EX_S             stConfNormal;

    /** MCU��GK���� */
    MC_MCU_CONFIG_GK_EX_S                 stConfGK;

    /** ·�ɱ�ARP��*/
    MC_MCU_LAN_ROUTE_ARP_TABLE_EX_S       stConfRouteARP;

    /** NAT���� */
    MC_MCU_CONFIG_NAT_EX_S                stConfNAT;

    /** ���񼶱� */
    HD_QOS_SERV_EX_S                      stQosServ;

    /** ��ɫֵ */
    HD_MCU_COLOR_VALUE_EX_S               stColorValue;

    /** �Ƿ�֧��RIPЭ�� */
    BOOL_T                                bRIPEnabled;

    /** GKע��״̬ HD_RESULT_EX_E */
    ULONG_32                                 ulGkRegState;

    /** MCU����ģʽ */
    HA_SYSTEM_INFO_EX_S                   stMcuRunMode;

    /** NTP�������� */
    MC_MCU_NTP_INFO_EX_S                  stNTPInfo;

    /** MP��ʾ���� */
    HD_MP_PROMPT_CFG_EX_S                 stMPPromptCfg;

    /** �汾���� */
    MC_VERSION_CONFIG_EX_S                stVersionCfg;
} MC_MCU_CONFIG_ALL_EX_S;

#if 0
#endif

/**
 * @struct tagConfContactInfo
 * @brief ������ϵ����Ϣ
 * @attention
 */
typedef struct tagConfContactInfo
{
    /** ��ϵ��ID */
    IMOS_ID idContactId;

    /** ��ϵ������ */
    CHAR    szContactName[IMOS_NAME_LEN];

    /** ��ϵ���ƶ��绰 */
    CHAR    szMobilePhone[IMOS_MOBILE_LEN];

    /** ��ϵ�˵����ʼ� */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** ��ϵ��Notes�ʼ� */
    CHAR    szNotesEmail[IMOS_MAIL_LEN];

    /** ��ϵ�����ڵĲ��� */
    CHAR    szDepartment[IMOS_NAME_LEN];

    /** ��ϵ�˱�ע */
    CHAR    szDesc[IMOS_DESC_LEN];
}CONF_CONTACT_INFO_EX_S;

#if 0
#endif

/**
 * @struct tagDeviceBaseInfo
 * @brief MG��Ѷ�豸������Ϣ
 * @attention
 */
typedef struct tagDeviceBaseInfo
{
    /** �豸���� */
    CHAR  szDevName[IMOS_SITE_NAME_LEN];

    /** �豸���ͣ� IMOS_TYPE_E */
    ULONG_32 ulDevType;

    /** �豸�����ͣ� MC_DEVICE_TYPE_EX_E */
    ULONG_32 ulDevSubType;

    /** �豸��ַ����: IMOS_IPADDR_TYPE_IPV4��IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32 ulDevAddrType;

    /**�豸��ַ */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ����ߣ��豸����״̬IMOS_DEV_STATUS_ONLINE���豸����״̬IMOS_DEV_STATUS_OFFLINE */
    ULONG_32 ulIsOnline;

    /** ������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸��չ״̬*/
    ULONG_32 ulDevExtStatus;

    /** �豸���� , ����ֻ����дΪ�� */
    CHAR  szDevDesc[IMOS_DESC_LEN];
}DEVICE_BASE_INFO_S;


/**
 * @struct tagTerminalQueryItemEx
 * @brief MG��Ѷ�ն��б��ѯ��Ԫ��Ϣ
 * @attention
 */
typedef struct tagTerminalQueryItemEx
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** E.164���� */
    CHAR  szDevE164Num[IMOS_CONF_ALIAS_LEN];

    /** H.323 ID */
    CHAR  szDevH323Id[IMOS_CONF_ALIAS_LEN];

    /** �ն��ܴ��� HD_BITRATE_EX_E */
    ULONG_32 ulBandWidth;

    /** �ն�״̬ MG_SESSION_STATUS_E */
    ULONG_32 ulCallStatus;

    /** BOOL_TRUE��ʾΪ�������豸 */
    BOOL_T             bIs3rdTerm;

    /** �豸������Ϣ */
    DEVICE_BASE_INFO_S stDeviceBaseInfo;
}TERMINAL_QURERY_ITEM_EX_S;

/**
 * @struct tagMC_TermAlarmInfoEx
 * @brief �ն˸澯��Ϣ
 * @attention
 */
typedef struct tagMC_TermAlarmInfoEx
{
    /** �澯�� */
    LONG_32                      lAlarmID;

    /** �澯״̬ MC_TERM_ALARM_STATUS_EX_E�������ն�ʱ���ã���0 */
    ULONG_32                     ulAlarmStatus;
} MC_TERM_ALARM_INFO_EX_S;

/**
* @struct tagMC_Site_BFD_Layer_Switch_ModeEx
* @brief �᳡��·�л�ģʽ�ṹ
* @attention
*/
typedef struct tagMC_Site_BFD_Layer_Switch_ModeEx
{
    /** �л���ʽ MC_LINK_LAYER_SWITCH_MODE_EX_E */
    ULONG_32 ulSwitchMode;

    /** Ŀ����· MC_LINK_LAYER_TYPE_EX_E */
    ULONG_32 ulLinkLayer;
} MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S;


/**
* @struct tagMC_Site_BFD_LinkLayer_InfoEx
* @brief �᳡ʹ�õ���·��Ϣ�ṹ
* @attention
*/
typedef struct tagMC_Site_BFD_LinkLayer_InfoEx
{
    /** ��ǰʹ�õ���· MC_LINK_LAYER_TYPE_EX_E */
    ULONG_32 ulInUseLayer;

    /** ����·������״̬ MC_LINK_LAYER_STATE_EX_E */
    ULONG_32 aulLayerState[IMOS_EN_LINK_LAYER_TYPE_COUNT];
} MC_SITE_BFD_LINK_LAYER_INFO_EX_S;

/**
* @struct tagMC_LinkInfoEx
* @brief ˫��·��Ϣ
* @attention
*/
typedef struct tagMC_LinkInfoEx
{
    /** ������·IP��ַ */
    CHAR                               szIpAddressMain[IMOS_IPADDR_LEN];
    CHAR                               szIpAddressBak[IMOS_IPADDR_LEN];

    /** ����·���� HD_BITRATE_EX_E */
    ULONG_32                              ulBandWidthMain;
    ULONG_32                              ulBandWidthBak;

    /** ��·�л�ģʽ */
    MC_SITE_BFD_LAYER_SWITCH_MODE_EX_S stLayerSwitchMode;

    /** ��·��Ϣ�������ն�ʱ���ã���0 */
    MC_SITE_BFD_LINK_LAYER_INFO_EX_S   stLayerInfo;
} MC_LINK_INFO_EX_S;

/**
 * @struct tagTerminalConfigEx
 * @brief MG��Ѷ�ն˳��ò���
 * @attention
 */
typedef struct tagTerminalConfigEx
{
    /** E.164���� */
    CHAR  szDevE164Num[IMOS_CONF_ALIAS_LEN];

    /** H.323 ID */
    CHAR  szDevH323Id[IMOS_CONF_ALIAS_LEN];

    /** �ն�ҵ��IP��ַ */
    CHAR                   szTermAddr[IMOS_IPADDR_LEN];

    /** �ն��ܴ��� HD_BITRATE_EX_E */
    ULONG_32                  ulBandWidth;

    /** �ն�Э������ MC_PROTOCOL_TYPE_EX_E */
    ULONG_32                  ulProtocolType;

    /** �ն�����Ƶʹ������ MC_TERM_TYPE_EX_E */
    ULONG_32                  ulTermType;

    /** BOOL_TRUE��ʾΪ�������豸 */
    BOOL_T                 bIs3rdTerm;

    /** �ն�״̬ MG_SESSION_STATUS_E */
    ULONG_32                  ulSiteStatus;

    /** �Ƿ񶪰��᳡ */
    BOOL_T                 bLostPacketSite;

    /** MCU�����ն˵ĺ������� MC_MCU_CALL_TYPE_EX_E */
    ULONG_32                  ulMCUCallType;

    /** ˫��·��Ϣ */
    MC_LINK_INFO_EX_S      stLinkInfo;

    /** �澯��Ϣ */
    MC_TERM_ALARM_INFO_EX_S stAlarmInfo;
}TERMINAL_CONFIG_EX_S;

/**
 * @struct tagTerminalCapacityEx
 * @brief MG��Ѷ�ն˵�������
 * @attention
 */
typedef struct tagTerminalCapacityEx
{
    /** ���õ�������Ϣ */
    MC_TERM_VIDEO_CFG_EX_S stMainVideoCfg;

    /** ���õĸ�����Ϣ */
    MC_TERM_ROLEVIDEO_CFG_EX_S stRoleVideoCfg;

    /** ֧����Ƶ��׼�ĸ��� */
    LONG_32                lAudioCount;

    /** ֧�ֵ���Ƶ��׼ HD_AUDIO_PROT_EX_E */
    ULONG_32               aulAudioProt[IMOS_EN_AUD_PROT_COUNT];

}TERMINAL_CAPACITY_EX_S;

/**
* @struct tagMcuBackupInfoEx
* @brief MCU������Ϣ
* @attention
*/
typedef struct tagMcuBackupInfoEx
{
    /** MCU�������� MCU_BACKUP_TYPE_E ר���ڱ��ݵ�MCU�������ڱ��ݵ�MCU���������ڱ��ݵ�MCU */
    ULONG_32 ulBackupType;

    /** ���ݷ�ΧMCU_BACKUP_SCOPE_E ֻ���ڱ��ݵ�ǰ���MCU�������ڱ��ݵ�ǰ����������MCU��Ŀǰ�ݲ�֧�� */
    ULONG_32 ulBackupScope;

    /** �������ȼ���Ŀǰ�ݲ�֧�� */
    ULONG_32 ulBackupPriority;
}MCU_BACKUP_INFO_EX_S;

/**
 * @struct tagMcuBaseInfoEx
 * @brief MCU������Ϣ
 * @attention
 */
typedef struct tagMcuBaseInfoEx
{
   /** �豸���� */
   CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

   /** MCU������Ϣ */
   MCU_BACKUP_INFO_EX_S stMcuBackupInfo;

   /** �豸������Ϣ */
   DEVICE_BASE_INFO_S stDeviceBaseInfo;
}MCU_BASE_INFO_EX_S;



 /**
  * @struct tagConfQueryItemEx
  * @brief �����ѯ��Ԫ��Ϣ
  * @attention
  */
 typedef struct tagConfQueryItemEx
 {
     /** ����ID */
     IMOS_ID  idConfId;

     /** �Ƿ���iMSC�����Ļ��� */
     ULONG_32 ulConfIsImscCreated;

     /** �������� �� ����ģ������ */
     CHAR  szConfName[IMOS_NAME_LEN];

     /** ���鴴���� */
     CHAR  szCreater[IMOS_NAME_LEN];

     /** ����ģʽ MC_CONF_MODE_EX_E */
     ULONG_32 ulConfMode;

     /** ���鷽�� */
     LONG_32  lSiteCount;

     /** �������� HD_BITRATE_EX_E */
     ULONG_32 ulBitRate;

     /** �����ٿ�ʱ�䣬���ڻ���ģ����Ч*/
     LONG_32  lStartTime;

     /** ������ʱ������λ���룬���ڻ���ģ����Ч */
     LONG_32  lTotalDuration;

     /** ����ʣ��ʱ������λ���롣ֻ�ж��ڻ������Ч */
     LONG_32  lLeftDuration;

     /** �Ƿ�֧���鲥 */
     ULONG_32  ulMultiCast;

     /** �����Ƿ������û��� */
     BOOL_T bConfForever;

     /** ������֯���� */
     CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

 }CONF_QUERY_ITEM_EX_S;

/**
 * @struct tagConfSiteCasteEx
 * @brief MG��Ѷ�ն˵ļ�����Ϣ
 * @attention
 */
typedef struct tagConfSiteCasteEx
{
    /** �ն˱��� */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** �ն�����MCU�ı��� */
    CHAR  szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];
}CONF_SITE_CASTE_EX_S;

/**
 * @struct tagConfSiteName
 * @brief MG��Ѷ�ն˵�������Ϣ
 * @attention
 */
typedef struct tagConfSiteName
{
    /** �ն˱��� */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];
}CONF_SITE_NAME_S;

/**
* @struct tagConfTermNameType
* @brief �ն˵�������Ϣ������
* @attention
*/
typedef struct tagConfTermNameType
{
    /** �ն˱��� */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �ն�����(TERM_QUERY_TYPE_E) */
    ULONG_32 ulTermType;

}CONF_TERM_NAME_TYPE_S;


/**
 * @struct tagConfContact
 * @brief ������ϵ��
 * @attention
 */
typedef struct tagConfContact
{
    /** ��ϵ��ID */
    IMOS_ID idContactId;

    /** ��ϵ������ */
    CHAR    szContactName[IMOS_NAME_LEN];
}CONF_CONRTACT_S;


/**
 * @struct tagConfSiteCircleEx
 * @brief MG��Ѷ�ն˵���Ѳ��Ϣ
 * @attention
 */
typedef struct tagConfSiteCircleEx
{
    /** ��Ѳ����� MC_CYCLE_TABLE_INDEX_EX_E */
    ULONG_32 ulTableIndex;

    /** �豸���� */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR  szTermName[IMOS_NAME_LEN];
}CONF_SITE_CIRCLE_EX_S;

/**
 * @struct tagConfMcuCasteEx
 * @brief �����MCU��Ϣ
 * @attention ulMcuOnlineStatusֻ��SDK��ʹ�ã�������ĳ�����ʹ�ã����ڲ��ӿ�Ĭ����Чֵ�������������ʹ�ã���Чֵ��
 */
typedef struct tagConfMcuCasteEx
{
    /** MCU���� */
    CHAR  szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �ϼ�MCU���� */
    CHAR  szUpperMcuCode[IMOS_DEVICE_CODE_LEN];

    /** MCU�Ϸֻ����״̬ MC_CONF_STATUS_EX_E */
    ULONG_32 ulMCUConfStatus;

    /** MCU�Ϸֻ����ID��-1Ϊ��Ч�Ļ���ID */
    LONG_32 lConfIdInMcu;

    /** MCU����״̬ DEV_ONLINE_STATUS_E*/
    ULONG_32 ulMcuOnlineStatus;

    /** �鲥���ò��� */
    MC_MULTICAST_INFO_EX_S      stMulticastInfo;
}CONF_MCU_CASTE_EX_S;

/**
 * @struct tagConfSiteInfoEx
 * @brief  �᳡������Ϣ
 * @attention
 */
typedef struct tagConfSiteInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �᳡���� */
    CHAR  szSiteCode[IMOS_RES_CODE_LEN];

    /** �᳡���� */
    CHAR  szSiteName[IMOS_NAME_LEN];
}CONF_SITE_INFO_EX_S;


/**
 * @struct tagTermStatusChangeEx
 * @brief  �ն�״̬�ı�
 * @attention
 */
typedef struct tagTermStatusChangeEx
{
    /** �᳡���� */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** �᳡���� */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** �ն�״̬ MC_SITE_STATUS_EX_E */
    ULONG_32    ulSiteStatus;

    /** ����ID�� �ն�Ŀǰ�μӵĻ���ID�����ڻ�����Ϊ0��0ʱ���²�����Ч */
    IMOS_ID  idConfId;

    /** ��˷��Ƿ�رգ��Ƿ���� */
    BOOL_T   bCloseMic;

    /** �������Ƿ�رգ��Ƿ��� */
    BOOL_T   bCloseSpeaker;

    /** �Ƿ����� */
    BOOL_T   bIsChair;

    /** �Ƿ�㲥 */
    BOOL_T   bIsBroadcast;

    /** ��ǰ���û᳡�鿴���ն�ģʽ MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulTermWatchedSiteType;

    /** ��ǰ���û᳡�鿴���ն� */
    CHAR     szTermWatchedCode[IMOS_RES_CODE_LEN];
    CHAR     szTermWatchedName[IMOS_NAME_LEN];

    /** �����Ƿ��������� */
    BOOL_T   bConnected;
}TERM_STATUS_CHANGE_EX_S;

/**
* @struct tagCallSiteInfoEx
* @brief  ���л᳡��Ϣ
* @attention
*/
typedef struct tagCallSiteInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �᳡���� */
    CHAR  szSiteCode[IMOS_RES_CODE_LEN];

    /** �᳡���� */
    CHAR  szSiteName[IMOS_NAME_LEN];

    /** ����ʧ�ܽ�� ����ȡֵ�μ�imos_ss_err.h�������ļ� */
    ULONG_32 ulCallFailRslt;
}CALL_SITE_INFO_EX_S;

/**
* @struct tagGKRegStateInfoEx
* @brief  GKע������Ϣ
* @attention
*/
typedef struct tagGKRegStateInfoEx
{
    /** MCU���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** GKע��������ȡֵ�μ�imos_ss_err.h */
    ULONG_32  ulGKRegState;
}GK_REG_STATE_INFO_EX_S;

/**
* @struct tagMgSessionStatusEx
* @brief MG�Ự״̬�ϱ��ṹ
* @attention
*/
typedef struct tagMgSessionStatusEx
{
    /** �ն˱��� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** MG�ն�״̬����ȡֵ�μ�MG_SESSION_STATUS_E */
    ULONG_32  ulMgSessionStatus;
}MG_SESSION_STATUS_EX_S;

/**
 * @struct tagConfResStatusChangeInfoEx
 * @brief  ������Դ����״̬�ı�
 * @attention
 */
typedef struct tagConfResStatusChangeInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;


    /** ����ɹ�/ʧ�� */
    BOOL_T   bAssinFlag;
}CONF_RES_STATUS_CHANGE_INFO_EX_S;


/**
* @struct tagDeviceChangeInfoEx
* @brief  �ն��豸������Ϣ
* @attention
*/
typedef struct tagDeviceChangeInfoEx
{
    /** ����ID�� ���豸���ڻ����У� ����ID������ */
    IMOS_ID  idConfId;

    /** MCU���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �᳡�� */
    ULONG_32 ulSiteCount;

    /** �᳡���ֺ�������Ϣ */
    CONF_TERM_NAME_TYPE_S stTermNameType[IMOS_HD_MAX_SITE_PER_CONF_NUM];

    /** �������ͣ� �������޸ġ�ɾ�� DEVICE_OPERATE_TYPE_E */
    ULONG_32    ulChangeType;
}DEVICE_CHANGE_INFO_EX_S;

/**
 * @struct tagDelayConfInfoEx
 * @brief  �����ӳ���Ϣ
 * @attention
 */
typedef struct tagDelayConfInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �����ӳ�ʱ��, ʱ�䵥λΪ���� */
    LONG_32  lDelayTime;
}DELAY_CONF_INFO_EX_S;

/**
 * @struct tagMC_SynchronizeWithWebEx
 * @brief  �㲥�᳡�� ��ϯ�������ۿ��᳡
 * @attention
 */
typedef struct tagMC_SynchronizeWithWebEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** Ԥ���㲥�᳡ */
    CHAR     szSetBroadcastSiteCode[IMOS_RES_CODE_LEN];
    CHAR     szSetBroadcastSiteName[IMOS_NAME_LEN];

    /** ʵ�ʹ㲥�᳡ģʽ MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurBroadcastSiteType;

    /** ʵ�ʹ㲥�᳡ */
    CHAR    szCurBroadcastSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurBroadcastSiteName[IMOS_NAME_LEN];

    /** ��ϯ������Ԥ���ۿ��᳡ */
    CHAR    szSetChairBrowseSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szSetChairBrowseSiteName[IMOS_NAME_LEN];

    /** ��ϯ������ʵ�ʹۿ��᳡ģʽ MC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurChairBrowseSiteType;

    /** ��ϯ������ʵ�ʹۿ��᳡ */
    CHAR    szCurChairBrowseSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurChairBrowseSiteName[IMOS_NAME_LEN];
} MC_SYNCHRONIZE_WITH_WEB_EX_S;

/**
* @struct tagCurBroadcastInfoEx
* @brief  ��ǰʵ�ʹ㲥�᳡
* @attention
*/
typedef struct tagCurBroadcastInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** ʵ�ʹ㲥�᳡ */
    CHAR    szCurBroadcastSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurBroadcastSiteName[IMOS_NAME_LEN];

    /** ʵ�ʹ㲥�᳡ģʽMC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurBroadcastSiteType;
} CUR_BROADCAST_INFO_EX_S;

/**
* @struct tagCurChairBrowseInfoEx
* @brief  ��ǰ��ϯ�������ۿ��᳡
* @attention
*/
typedef struct tagCurChairBrowseInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** ��ϯ������ʵ�ʹۿ��᳡ */
    CHAR    szCurChairBrowseSiteCode[IMOS_RES_CODE_LEN];
    CHAR    szCurChairBrowseSiteName[IMOS_NAME_LEN];

    /** ��ϯ������ʵ�ʹۿ��᳡ģʽMC_BROWSE_SITE_TYPE_EX_E */
    ULONG_32   ulCurChairBrowseSiteType;
} CUR_CHAIR_BROWSE_INFO_EX_S;

/**
 * @struct tagAppointChairInfoEx
 * @brief  ָ����ϯ��Ϣ
 * @attention
 */
typedef struct tagAppointChairInfoEx
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �᳡���� */
    CHAR  szSiteCode[IMOS_RES_CODE_LEN];

    /** ָ������Ψһ��ʶ */
    CHAR  szSetChairCode[IMOS_RES_CODE_LEN];

    /** ��ǰ����Ψһ��ʶ */
    CHAR  szCurChairCode[IMOS_RES_CODE_LEN];
}APPOINT_CHAIR_INFO_EX_S;


/**
 * @struct tagConfStatusInfoEx
 * @brief  ����״̬��Ϣ
 * @attention
 */
typedef struct tagConfStatusInfoEx
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** MCU�������� CONF_MCU_CASCADE_TYPE_E */
    ULONG_32                   ulMcuCascType;

    /** ����ID */
    IMOS_ID                 idConfId;

    /** ����״̬ MC_CONF_STATUS_EX_E */
    ULONG_32                   ulConfStatus;
}CONF_STATUS_INFO_EX_S;


/**
 * @struct tagDeviceCodeChangeInfoEx
 * @brief  �豸����ı���Ϣ
 * @attention
 */
typedef struct tagDeviceCodeChangeInfoEx
{
    /** ԭ�ն˱��� */
    CHAR szOldSiteCode[IMOS_RES_CODE_LEN];

    /** ���ն����ֺ����� */
    CONF_TERM_NAME_TYPE_S stNewConfTermNameType;

}DEVICE_CODE_CHANGE_INFO_EX_S;

/**
 * @struct tagSiteSelectBrowseSiteInfoEx
 * @brief  ĳ�᳡ѡ����һ���ۿ��Ļ᳡����Ϣ
 * @attention
 */
typedef struct tagSiteSelectBrowseSiteInfoEx
{
    /** ����ID */
    IMOS_ID                 idConfId;


    /** �᳡���� */
    CHAR                    szSiteCode[IMOS_RES_CODE_LEN];

    /** ���ۿ��᳡�ı��� */
    CHAR                    szBeBrowsedSiteCode[IMOS_RES_CODE_LEN];
}SITE_SELECT_BROWSE_SITE_INFO_EX_S;

/**
 * @struct tagConfSiteCodeEx
 * @brief MG��Ѷ�ն˵��豸����
 * @attention
 */
typedef struct tagConfSiteCodeEx
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];
}CONF_SITE_CODE_EX_S;

/**
 * @struct tagConfMcuCodeEx
 * @brief MCU���豸����
 * @attention
 */
typedef struct tagConfMcuCodeEx
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];
}CONF_MCU_CODE_EX_S;

/*************************************************************************************
SS MG�᳡�ն��������ݽṹ
***************************************************************************************/
/**
* @struct tagHD_AnswerConfigEx
* @brief ��������
* @attention
*/
typedef struct tagHD_AnswerConfigEx
{

    /** �Զ�Ӧ��*/
    BOOL_T                  bAutoAnswer;

    /** ��������Զ�Ӧ�� */
    LONG_32                    lRingTime;

    /** �������� HD_AUDIO_VOLUME_EX_E */
    ULONG_32                   ulRingVol;

    /** ����ѡ�� HD_RING_TYPE_EX_E */
    ULONG_32                   ulRingType;
    LONG_32                    lReserved[8];
}HD_ANSWER_CONFIG_EX_S;

/**
* @struct tagHD_Sys_Started_CfgEx
* @brief ��������/�����������������(δ��)
* @attention
*/
typedef struct tagHD_Sys_Started_CfgEx
{

    /** �������� HD_RING_TYPE_EX_E */
    ULONG_32       ulRingType;
}HD_SYS_STARTED_CFG_EX_S;

/**
 * @struct tagHD_OtherConfigParamEx
 * @brief MG�������ò���
 * @attention
 */
typedef struct tagHD_OtherConfigParamEx
{
    /** �����������ò���  */
    HD_ANSWER_CONFIG_EX_S            stAnswerParam;



    /** �������� */
    HD_SYS_STARTED_CFG_EX_S          stStartedParam;
} MC_OTHERCONFIGPARAM_EX_S;


/**
* @struct tagHD_H323ConfigEx
* @brief h323����
* @attention
*/
typedef struct tagHD_H323ConfigEx
{

    /** �Ƿ�ʹ�÷����� */
    BOOL_T           bUseServer;

    /** ������ip��ַ */
    CHAR             szServerIP[IMOS_IPADDR_LEN];

    /** ע����� */
    CHAR             szRegNumber[IMOS_HD_MAX_NAME_LENGTH];

    /** ע������ */
    CHAR             szRegPasswd[IMOS_HD_MAX_PASSWORD_LENGTH];

    /** H323 ID */
    CHAR             szH323id[IMOS_HD_MAX_NAME_LENGTH];

    /** �Ƿ�ʹ��H323IDע�� */
    BOOL_T           bUseH323id;

    /** �Ƿ�����ϵͳ�� */
    BOOL_T           bSetSysName;

    /** H323 ϵͳ�� */
    CHAR             szSysName[IMOS_HD_MAX_NAME_LENGTH];
    LONG_32             lReserved[2];
}HD_H323_CONFIG_EX_S;



/**
* @struct tagHD_SIPConfigEx
* @brief SIP����
* @attention
*/
typedef struct tagHD_SIPConfigEx
{

    /** �Ƿ�ʹ�÷����� */
    BOOL_T               bUseServer;

    /** ������ip��ַ */
    CHAR                 szServerIP[IMOS_IPADDR_LEN];

    /** ע����� */
    CHAR                 szRegNumber[IMOS_HD_MAX_NAME_LENGTH];

    /** ע������ */
    CHAR                 szRegPasswd[IMOS_HD_MAX_PASSWORD_LENGTH];

    /** SIPע��ID */
    CHAR                 szRegid[IMOS_HD_MAX_NAME_LENGTH];
    LONG_32                 lReserved[2];
}HD_SIP_CONFIG_EX_S;

/**
 * @struct tagHD_ProtocolAllEx
 * @brief Э������
 * @attention
 */
typedef struct tagHD_ProtocolAllEx
{

    /** �Ƿ�ѡ���ӦЭ�� */
    BOOL_T              abProtoType[IMOS_EN_PROTO_TYPE_COUNT];

    /** H.323���� */
    HD_H323_CONFIG_EX_S stH323Config;

    /** SIP���� */
    HD_SIP_CONFIG_EX_S  stSIPConfig;
    LONG_32                alReserved[8];
}HD_PROTOCOL_ALL_EX_S;


/**
* @struct tagHD_ConnetConfigEx
* @brief ������������
* @attention
*/
typedef struct tagHD_ConnetConfigEx
{

    /** �������ӷ�ʽ HD_CONNECT_TYPE_EX_E */
    ULONG_32                   ulConnectType;

    /** ���������� HD_BITRATE_EX_E */
    ULONG_32                   ulBandwidth;

    /* �̶�IP������ */

    /** ip��ַ */
    CHAR                    szIPaddr[IMOS_IPADDR_LEN];

    /** �������� */
    CHAR                    szSubmask[IMOS_IPADDR_LEN];

    /** ���� */
    CHAR                    szGateway[IMOS_IPADDR_LEN];

    /* PPPoE������ */

    /** �û��� */
    CHAR                    szPppoe_user[IMOS_HD_MAX_NAME_LENGTH];

    /** ���� */
    CHAR                    szPppoe_passwd[IMOS_HD_MAX_PASSWORD_LENGTH];

    LONG_32                    alReserved[8];
}HD_CONNECT_CONFIG_EX_S;

/**
 * @struct tagHD_AllConnetConfigEx
 * @brief ����������������
 * @attention
 */
typedef struct tagHD_AllConnetConfigEx
{
    /** �������ڵ��������� */
    HD_CONNECT_CONFIG_EX_S astAllConnectCfg[IMOS_EN_HD_NIC_COUNT];
}HD_ALLCONNECT_CONFIG_EX_S;

/**
 * @struct tagHD_NIC_Number_CfgEx
 * @brief ��ǰʹ�õ����ں�
 * @attention
 */
typedef struct tagHD_NIC_Number_CfgEx
{

    /** ���ں� HD_NIC_NUMBER_EX_E */
    ULONG_32  ulNIC;
}HD_NIC_NUMBER_CFG_EX_S;

/**
* @struct tagHD_NicConfigEx
* @brief ��������
* @attention
*/
typedef struct tagHD_NicConfigEx
{

    /** �������� �Զ�/ȫ˫��/��˫�� HD_NETCARD_DUPLEX_TYPE_EX_E */
    ULONG_32                        ulNICType;

    /** �������� HD_NETCARD_RATE_EX_E */
    ULONG_32                        ulNICSpeed;

    /** �������÷�ʽ HD_NETCARD_SET_TYPE_EX_E */
    ULONG_32                        ulCardSetType;
    LONG_32                         lReserved[4];
}HD_NICCONFIG_EX_S;

/**
 * @struct tagHD_AllNicConfigEx
 * @brief ������������
 * @attention
 */
typedef struct tagHD_AllNicConfigEx
{

    /** ����������Ϣ */
    HD_NICCONFIG_EX_S     astNICConfig[IMOS_EN_HD_NIC_COUNT];
    LONG_32                  alReserved[7];
}HD_ALLNIC_CONFIG_EX_S;


/**
* @struct tagHD_NetConfigEx
* @brief ����������Ϣ�ṹ
* @attention
*/
typedef struct tagHD_NetConfigEx
{
    /** ���� */
    CHAR                   szNetIP[IMOS_IPADDR_LEN];

    /** �������� */
    CHAR                   szNetMask[IMOS_IPADDR_LEN];
    LONG_32                   lReserved[2];
}HD_NET_CONFIG_EX_S;


/**
* @struct tagHD_NATConfigEx
* @brief NAT ����
* @attention
*/
typedef struct tagHD_NATConfigEx
{

    /** �Ƿ�ʹ�� NAT ��ַ */
    BOOL_T                  bUseNAT;

    /** NAT��ַ */
    CHAR                    szNATAddr[IMOS_IPADDR_LEN];

    /** NAT���ص�ַ */
    CHAR                    szNATGateway[IMOS_IPADDR_LEN];

    /* �˿����� */

    /** �Ƿ�ʹ�ù̶��˿� */
    BOOL_T                  bUseFixedPort;

    /** ���ж˿� */
    ULONG_32                   ulCallPort;

    /** RAS�˿� */
    ULONG_32                   ulRasPort;

    /** ���ݶ˿� */
    ULONG_32                   ulDataPort;

    /** ��Ƶ�˿� */
    ULONG_32                   ulAudioPort;

    /** ������Ƶ */
    ULONG_32                   ulMainVideoPort;

    /** ������Ƶ */
    ULONG_32                   ulSecVideoPort;

    /** h225/h245ʹ��  */
    ULONG_32                   ulOtherTcpPort1;

    /** h225/h245ʹ�� */
    ULONG_32                   ulOtherTcpPort2;

    /* �������� */

    /** ˽������ */
    USHORT                  usPriNetCount;

    /** �����ֶ������ֽڶ��� */
    USHORT                  usReserved;

    /** ˽������ */
    HD_NET_CONFIG_EX_S      astPriNetConfig[IMOS_HD_MAX_PRIVATE_NET_COUNT];
    LONG_32                    alReserved[8];
}HD_NAT_CONFIG_EX_S;

/**
 * @struct tagHD_AllNATConfigEx
 * @brief NAT ����
 * @attention
 */
typedef struct tagHD_AllNATConfigEx
{
    HD_NAT_CONFIG_EX_S    astAllNATCfg[IMOS_EN_HD_NIC_COUNT];
}HD_ALL_NAT_CONFIG_EX_S;

/**
 * @struct tagHD_NTPConfigEx
 * @brief NTP����
 * @attention
 */
typedef struct tagHD_NTPConfigEx
{

    /** �Ƿ�ʹ��NTP */
    BOOL_T                    bUseNTP;

    /** NTP��������ַ */
    CHAR                      szNTPServer[IMOS_IPADDR_LEN];
    LONG_32                      alReserved[8];
}HD_NTP_CONFIG_EX_S;

/**
 * @struct tagHD_MvConfigEx
 * @brief ��������
 * @attention
 */
typedef struct tagHD_MvConfigEx
{

    /** �Ƿ��Զ�����������Ƶ */
    BOOL_T                     bAutoSend;

    /** �������ȼ� HD_VIDEO_PROT_EX_E */
    ULONG_32                      ulCapacity;

    /** ֡�� HD_FRAMERATE_TYPE_EX_E */
    ULONG_32                      ulFramRate;

    /** ͼ���ʽ HD_VIDEO_FORMAT_EX_E */
    ULONG_32                      ulVideoFmt;
    LONG_32                       alReservered[8];
}HD_MV_CONFIG_EX_S;


/**
 * @struct tagHD_RvConfigEx
 * @brief ��������
 * @attention
 */
typedef struct tagHD_RvConfigEx
{

    /** �Ƿ�ʹ�ø��� */
    BOOL_T                     bStartRV;

    /** �Ƿ��Զ����͸�����Ƶ */
    BOOL_T                     bAutoSend;

    /** �������ȼ� HD_VIDEO_PROT_EX_E */
    ULONG_32                      ulCapacity;

    /** ˫��ģʽ HD_ROLE_VIDEO_TYPE_EX_E */
    ULONG_32                      ulRoleVideoType;

    /** �������� HD_BITRATE_EX_E */
    ULONG_32                      ulBandwidth;

    /** ��˽���� */
    BOOL_T                     bPrivate;

    /** ֡�� HD_FRAMERATE_TYPE_EX_E */
    ULONG_32                      ulFramRate;
    LONG_32                       alReservered[7];
}HD_RV_CONFIG_EX_S;


/**
* @struct tagHD_VideoOutInfoEx
* @brief ��Ƶ�����Ϣ
* @attention
*/
typedef struct tagHD_VideoOutInfoEx
{

    /** ��Ƶ����˿� HD_VIDEO_OUT_PORT_EX_E */
    ULONG_32                           ulVideoOutPort;

    /** ��Ƶ������� HD_VIDEO_OUT_CONTENT_TYPE_EX_E */
    ULONG_32                           ulVideoOutContent;
} HD_VIDEO_OUT_INFO_EX_S;

/**
 * @struct tagHD_VideoInOutEx
 * @brief ��Ƶ�����������
 * @attention
 */
typedef struct tagHD_VideoInOutEx
{

    /** ��Ƶ�������� HD_VIDEO_IN_PORT_EX_E */
    ULONG_32                  aulVideoIn[IMOS_EN_VIDEO_TYPE_COUNT];

    /** ��Ƶ������� */
    HD_VIDEO_OUT_INFO_EX_S astVideoOut[IMOS_HD_VIDEO_OUT_NUM];
} HD_VIDEO_INOUT_EX_S;


/**
* @struct tagHD_AudioInOutEx
* @brief ��Ƶ�����������
* @attention
*/
typedef  struct    tagHD_AudioInOutEx
{

    /** ��Ƶ�������� */
    BOOL_T                         abAudioIn[IMOS_EN_AUDIO_IN_PORT_COUNT];

    /** ��Ƶ�������� */
    BOOL_T                         abAudioOut[IMOS_EN_AUDIO_OUT_PORT_COUNT];

    /** ��Ƶ RCA ����˿����� HD_AUDIO_IN_PORT_SUB_TYPE_EX_E  */
    ULONG_32                          aulAudioInPortType[IMOS_EN_AUDIO_IN_PORT_COUNT];
} HD_AUDIO_INOUT_EX_S;

/**
* @struct tagHD_Record_CfgEx
* @brief ¼������
* @attention
*/
typedef  struct    tagHD_Record_CfgEx
{

    /** �Ƿ�ʹ��¼�� */
    BOOL_T                      bUseRecord;

    /** ¼���洢���� HD_RECORD_STORAGE_TYPE_EX_E */
    ULONG_32                       ulStorageType;

    /** ¼���洢·�� */
    CHAR                        szPath[IMOS_HD_MAX_PATH_LENGTH];

    /** ¼������ӿ����� HD_AUDIO_OUT_PORT_EX_E */
    ULONG_32                       ulOutPort;
} HD_RECORD_CFG_EX_S;

/**
 * @struct tagHD_AudioAllConfigEx
 * @brief ��Ƶ����
 * @attention
 */
typedef struct tagHD_AudioAllConfigEx
{

    /** ��Ƶ��������˿� */
    HD_AUDIO_INOUT_EX_S     stInOutPorts;

    /** �Ƿ��Զ�������Ƶ */
    BOOL_T                  bAutoSend;

    /** MIC���������ȼ� HD_AEC_TYPE_EX_E */
    ULONG_32                   ulMICAEC;

    /** RCA���������ȼ� HD_AEC_TYPE_EX_E */
    ULONG_32                   ulRCAAEC;

    /** �������ȼ� HD_AUDIO_PROT_EX_E */
    ULONG_32                   ulCapacity;

    /** �������� HD_AUDIO_VOLUME_EX_E */
    ULONG_32                   aulInVol[IMOS_EN_AUDIO_IN_PORT_COUNT];

    /** ������� HD_AUDIO_VOLUME_EX_E */
    ULONG_32                   ulOutVol;

    /** �Ƿ������Զ����� */
    BOOL_T                  bAutoAGC;

    /** ���� */
    BOOL_T                  bSilence;

    /** ���� */
    BOOL_T                  bMute;

    /** ����(ֻ��� MIC )  */
    BOOL_T                  abFeedBack[IMOS_EN_AUDIO_IN_PORT_COUNT];

    /** ¼������ */
    HD_RECORD_CFG_EX_S      stRecordCfg;
    LONG_32                    alReservered[5];
}HD_AUDIOALL_CONFIG_EX_S;

/**
 * @struct tagHD_InnerModuleDebugLevelEx
 * @brief ģ��ĵ��Լ��������Ϣ
 * @attention
 */
typedef  struct  tagHD_InnerModuleDebugLevelEx
{

    /** ģ����Լ��� HD_DEBUG_LEVEL_EX_E */
    ULONG_32               aulDebugLevel[IMOS_EN_HD_MODULE_TYPE_COUNT];

    /** ��־��������ַ */
    CHAR                szServer[IMOS_IPADDR_LEN];
}HD_INNER_MODULE_DEBUG_LEVEL_EX_S;

/**
 * @struct tagHD_LogConfigEx
 * @brief ��־����
 * @attention
 */
typedef struct tagHD_LogConfigEx
{

    /** �Ƿ�������־ */
    BOOL_T             bUseLOG;

    /** ��Ӧ��־�����Ƿ����� */
    BOOL_T             abLevel[IMOS_EN_HD_LOG_TYPE_COUNT];
    LONG_32               lReserved[8];
}HD_LOG_CONFIG_EX_S;

/**
 * @struct tagHD_UpdateConfigEx
 * @brief ��������
 * @attention
 */
typedef struct tagHD_UpdateConfigEx
{

    /** �Ƿ��Զ����� */
    BOOL_T          bAutoUpdate;

    /** ����������ip��ַ */
    CHAR            szServer[IMOS_IPADDR_LEN];

    /** ����·�� */
    CHAR            szPath[IMOS_HD_MAX_PATH_LENGTH];

    /** �Զ�����·�� */
    CHAR            szAutoPath[IMOS_HD_MAX_PATH_LENGTH];

    /** �����ļ��� */
    CHAR            szFilename[IMOS_HD_MAX_NAME_LENGTH];

    /** ���ذ汾�� */
    CHAR            szVersion[IMOS_HD_VERSION_LEN];

    /** ���ݰ汾���� */
    CHAR            szVerRange[IMOS_EN_MAX_VERSION_COUNT][IMOS_HD_VERSION_LEN];
    LONG_32            lReserved[8];
}HD_UPDATE_CONFIG_EX_S;

/**
 * @struct tagHD_SiteConfigEx
 * @brief �᳡���� ����Ϣ����
 * @attention
 */
typedef struct tagHD_SiteConfigEx
{
    HD_SITE_NAME_INFO_EX_S stSiteNameInfo;

    /** �Ƿ�ʹ�� LOGO  */
    BOOL_T                  bUseLogo;

    /** ʹ��Ĭ�� LOGO ����ϵͳ LOGO��ֻ��ȷ��ʹ�� LOGO ������²���ʹ�� HD_LOGO_TYPE_EX_E */
    ULONG_32                   ulLogoType;

    /** ���� */
    TIME_T                  tiDate;

    /** ʱ�� */
    TIME_T                  tiTime;
    LONG_32                    lReserved[8];
}HD_SITE_CONFIG_EX_S;

/**
 * @struct tagHD_NAAConfigEx
 * @brief NAA����
 * @attention
 */
typedef struct tagHD_NAAConfigEx
{

    /** �Ƿ�ʹ�� NAA */
    BOOL_T             bUseNAA;

    /** ʹ�� NAA ������ HD_TNAA_TYPE_EX_E */
    ULONG_32              ulNAAType;
    LONG_32               alReservered[8];
}HD_NAA_CONFIG_EX_S;

/**
* @struct tagHD_CamPresetPosEx
* @brief �����Ԥ��λ�ṹ
* @attention
*/
typedef struct tagHD_CamPresetPosEx
{

    /** Ԥ��λ����Ч�� */
    BOOL_T         bValidPos;

    /** ����λ�� */
    USHORT         usPanPos;

    /** ����λ�� */
    USHORT         usTiltPos;

    /** ����λ�� */
    USHORT         usZoomPos;

    USHORT         usReserved;
    LONG_32           alReserved[3];
}HD_CAM_PRESET_POS_EX_S;

/**
* @struct tagHD_CameraConfigEx
* @brief ������ṹ
* @attention
*/
typedef struct tagHD_CameraConfigEx
{

    /** ���ƣ����ڽ�����ʾ 22���ַ�������\0  */
    CHAR                      szName[IMOS_HD_MAX_NAME_LENGTH];

    /** ���� HD_CAMERA_TYPE_EX_E */
    ULONG_32                     ulType;

    /** �˶��ٶ� HD_CAMERA_SPEED_EX_E */
    ULONG_32                     ulSpeed;

    /** ���ƴ��� HD_CAMERA_PORT_EX_E */
    ULONG_32                     ulPort;

    /** ���������Ԥ��λ */
    HD_CAM_PRESET_POS_EX_S    astCamPresetPos[IMOS_HD_MAX_CAM_PRE_NUM];
    LONG_32                      alReserved[8];
}HD_CAMERA_CONFIG_EX_S;


/**
 * @struct tagAllCam_ConfigEx
 * @brief ���������
 * @attention
 */
typedef struct tagAllCam_ConfigEx
{
    HD_CAMERA_CONFIG_EX_S astCamCfg[IMOS_EN_VIDEO_IN_PORT_COUNT];
}HD_ALLCAM_CONFIG_EX_S;


/**
 * @struct tagAllCam_Preset_PosEx
 * @brief �����Ԥ��λ(ALL)
 * @attention
 */
typedef struct tagAllCam_Preset_PosEx
{

    /** �����豾��Ԥ��λ */
    HD_CAM_PRESET_POS_EX_S astCamPos[IMOS_EN_VIDEO_IN_PORT_COUNT][IMOS_HD_MAX_CAM_PRE_NUM];

    /** Զ���豾��Ԥ��λ */
    HD_CAM_PRESET_POS_EX_S astRemoteCamPos[IMOS_EN_VIDEO_IN_PORT_COUNT][IMOS_HD_MAX_CAM_PRE_NUM];

    /** ������Զ��Ԥ��λ */
    BOOL_T                 abRemoteNumber[IMOS_HD_MAX_CAM_PRE_NUM];
}HD_ALLCAM_PRESET_POS_EX_S;


/**
 * @struct tagHD_ConfServerEx
 * @brief ip ���Ⱥͷ���������Ϣ
 * @attention
 */
typedef  struct tagHD_ConfServerEx
{

    /** �������� HD_QOS_TYPE_EX_E */
    ULONG_32                           ulQOSType;

    /** ���񼶱� */
    HD_IPPRECEDENCE_DIFFSERV_EX_U   unQOSLerver;
} HD_QOS_SERVER_EX_S;


/**
* @struct tagHD_VideoPortDVIFmtEx
* @brief DVI��ʽ��Ϣ
* @attention
*/
typedef struct tagHD_VideoPortDVIFmtEx
{

    /** DVI�������� HD_VIDEO_PORT_DVI_TYPE_EX_E */
    ULONG_32     ulVideoPortDVIType;

    /** ��Ƶ�ֱ��ʴ�С HD_VIDEO_FORMAT_EX_E */
    ULONG_32     ulVideoResolution;

    /** ��Ƶˢ��Ƶ�� HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32     ulVideoFrequence;
} HD_VIDEO_PORT_DVI_FMT_EX_S;

/**
* @struct tagHD_VideoPortSDIFmtEx
* @brief SDI��ʽ��Ϣ
* @attention
*/
typedef struct tagHD_VideoPortSDIFmtEx
{

    /** ��Ƶ�ֱ��ʴ�С HD_VIDEO_FORMAT_EX_E */
    ULONG_32            ulVideoResolution;

    /** ��Ƶˢ��Ƶ�� HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32            ulVideoFrequence;
} HD_VIDEO_PORT_SDI_FMT_EX_S;

/**
* @struct tagHD_VideoPortSFmt
* @brief S ��ʽ��Ϣ
* @attention
*/
typedef struct tagHD_VideoPortSFmt
{

    /** P/N  HD_RESTRICT_TYPE_EX_E */
    ULONG_32        ulRestictType;

    /** ��Ƶˢ��Ƶ��  HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32        ulVideoFrequence;
} HD_VIDEO_PORT_S_FMT_EX_S;

/**
* @struct tagHD_VideoPortRCAFmtEx
* @brief RCA ��ʽ��Ϣ
* @attention
*/
typedef struct tagHD_VideoPortRCAFmtEx
{

    /** P/N HD_RESTRICT_TYPE_EX_E */
    ULONG_32        ulRestictType;

    /** ��Ƶˢ��Ƶ�� HD_VIDEO_FREQUENCE_TYPE_EX_E */
    ULONG_32        ulVideoFrequence;
} HD_VIDEO_PORT_RCA_FMT_EX_S;

/**
* @union tagHD_VideoPortFmtUEx
* @brief ��Ƶ�˿ڸ�ʽ
* @attention
*/
typedef union tagHD_VideoPortFmtUEx
{

    /** DVI ��ʽ */
    HD_VIDEO_PORT_DVI_FMT_EX_S stVideoPortDVIFmt;

    /** SDI ��ʽ */
    HD_VIDEO_PORT_SDI_FMT_EX_S stVideoPortSDIFmt;

    /** S ��ʽ */
    HD_VIDEO_PORT_S_FMT_EX_S   stVideoPortSFmt;

    /** RCA ��ʽ */
    HD_VIDEO_PORT_RCA_FMT_EX_S stVideoPortRCAFmt;
} HD_VIDEO_PORT_FMT_EX_U;


/**
* @struct tagHD_VideoParamEx
* @brief ��Ƶ����
* @attention
*/
typedef struct tagHD_VideoParamEx
{

    /** ���� */
    LONG_32    lBright;

    /** �Աȶ� */
    LONG_32    lContrast;

    /** ���Ͷ� */
    LONG_32    lSaturation;

    /** ɫ�� */
    LONG_32    lChroma;
} HD_VIDEO_PARAM_EX_S;


/**
* @struct tagHD_VideoInPortParaEx
* @brief ��Ƶ����˿ڲ���
* @attention
*/
typedef struct tagHD_VideoInPortParaEx
{

    /** ����˿����� HD_VIDEO_PORT_TYPE_EX_E */
    ULONG_32                   ulVideoPortType;

    /** ����˿ڸ�ʽ */
    HD_VIDEO_PORT_FMT_EX_U  unVideoPortFmt;

    /** ����˿�AD���� */
    HD_VIDEO_PARAM_EX_S     stVideoParam;

    /** ����˿ڶ�Ӧ��������� */
    HD_CAMERA_CONFIG_EX_S   stCameraParam;
} HD_VIDEO_IN_PORT_PARA_EX_S;

/**
 * @struct tagHD_VideoInPortCfgEx
 * @brief ��Ƶ����˿�����
 * @attention
 */
typedef struct tagHD_VideoInPortCfgEx
{

    /** ��������˿����� */
    HD_VIDEO_IN_PORT_PARA_EX_S astVideoInPortPara[IMOS_EN_VIDEO_IN_PORT_COUNT];
} HD_VIDEO_IN_PORT_CFG_EX_S;

/**
 * @struct tagHD_VideoInPortEventEx
 * @brief ʵ����Ƶ����˿ڲ���
 * @attention
 */
typedef struct tagHD_VideoInPortEventEx
{

    /** �ض��˿��Ƿ��б仯 */
    BOOL_T                     abChange[IMOS_EN_VIDEO_IN_PORT_COUNT];

    /** 0ֵ��ʾ�ض��˿�����Դ�޷�ʶ���������Դ */
    ULONG_32                      aulCheckFlag[IMOS_EN_VIDEO_IN_PORT_COUNT];

    /** ʵ������˿����� */
    HD_VIDEO_IN_PORT_PARA_EX_S astVideoInPortPara[IMOS_EN_VIDEO_IN_PORT_COUNT];
} HD_VIDEO_IN_PORT_EVENT_EX_S;


/**
* @struct tagHD_VideoOutPortParaEx
* @brief ��Ƶ����˿ڲ���
* @attention
*/
typedef struct tagHD_VideoOutPortParaEx
{

    /** ��Ƶ����˿����� HD_VIDEO_PORT_TYPE_EX_E */
    ULONG_32                   ulVideoPortType;

    /** ��Ƶ����˿ڸ�ʽ */
    HD_VIDEO_PORT_FMT_EX_U  unVideoPortFmt;

    /** ��Ƶ���AD���� */
    HD_VIDEO_PARAM_EX_S     stVideoParam;
} HD_VIDEO_OUT_PORT_PARA_EX_S;


/**
 * @struct tagHD_VideoOutPortCfgEx
 * @brief ��Ƶ����˿�����
 * @attention
 */
typedef struct tagHD_VideoOutPortCfgEx
{

    /** ��������˿����� */
    HD_VIDEO_OUT_PORT_PARA_EX_S astVideoOutPortFmt[IMOS_EN_VIDEO_OUT_PORT_COUNT];
} HD_VIDEO_OUT_PORT_CFG_EX_S;

/**
 * @struct tagMC_MultiCastCfgEx
 * @brief �鲥��Ϣ�ṹ
 * @attention
 */
typedef struct tagMC_MultiCastCfgEx
{

    /** �Ƿ������鲥 */
    BOOL_T          bUseMulticast;

    /** �鲥 IP ��ַ */
    CHAR            szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥��ʼ�˿� */
    ULONG_32           ulMulticastPort;

    /** �鲥·���м� */
    ULONG_32           ulMulticastTTL;

    /** �Ƿ�ʹ����֤ */
    BOOL_T          bUseMCPwd;

    /** �鲥��֤���� */
    CHAR            szMulticastPwd[IMOS_HD_MAX_PASSWORD_LENGTH];
} MC_MULTICAST_CFG_EX_S;

/**
* @struct tagInner_VersionEx
* @brief �汾��Ϣ
* @attention
*/
typedef struct tagInner_VersionEx
{

    /** �ն˰汾 */
    CHAR szTerminalSoftVer[IMOS_HD_VERSION_LEN];

    /** ����汾����ʱ�� */
    CHAR szSoftVerMaketime[IMOS_HD_VERSION_LEN];

    /** ��������汾 */
    CHAR szDriverVer[IMOS_HD_VERSION_LEN];

    /** �ں������汾 */
    CHAR szKernelVer[IMOS_HD_VERSION_LEN];

    /** UBOOT �汾 */
    CHAR szUbootVer[IMOS_HD_VERSION_LEN];

    /** FPGA �汾 */
    CHAR szFpgaVer[IMOS_HD_VERSION_LEN];

    /** CPLD �汾 */
    CHAR szCpldVer[IMOS_HD_VERSION_LEN];

    /** DSP �汾 */
    CHAR szDspVer[IMOS_HD_VERSION_LEN];

    /** JRE �汾 */
    CHAR szJREVer[IMOS_HD_VERSION_LEN];

    /** ��������̰汾(�����ݲ���ʾ) */
    CHAR szCourseVer[IMOS_EN_HD_PROCESS_TYPE_COUNT][IMOS_HD_VERSION_LEN];
}HD_INNER_VERSION_EX_S;

/**
 * @struct tagDevice_InfoEx
 * @brief �豸��Ϣ
 * @attention
 */
typedef struct tagDevice_InfoEx
{

    /** ��Ʒ���к� */
    CHAR szSerialNum[IMOS_HD_VERSION_LEN];

    /** ����汾 */
    CHAR szSoftVer[IMOS_HD_VERSION_LEN];

    /** Ӳ���汾 */
    CHAR szHardVer[IMOS_HD_VERSION_LEN];

    /** �ڲ��汾��Ϣ */
    HD_INNER_VERSION_EX_S stInnerVer;
}HD_DEVICE_INFO_EX_S;

/**
 * @struct tagHD_LicenseInfoEx
 * @brief �� license ��صĹ�������
 * ע��: LONG lLicenseInfo ���и�λ�ֱ����:(�Ӹߵ��ͣ�δ��עλ����չ)
 *       ....       BIT1               BIT0
 *       ....    bSupportTMC       bSupport1080P
      *
 *       ��: BIT0 = 0 ��ʾ��֧�� 1080P  BIT0 = 1 ��ʾ֧�� 1080P
 *           BIT1 = 0 ��ʾ��֧�� TMC    BIT1 = 1 ��ʾ֧�� TMC
 * @attention
 */
typedef struct tagHD_LicenseInfoEx
{

    /** �ض�λ��ʾ�ض�����Ϣ(��������ṹ����) */
    ULONG_32 ulLicenseInfo;
} HD_LICENSE_INFO_EX_S;


/**
 * @struct tagHD_MPSwitchCfgEx
 * @brief MP ��������
 * @attention
 */
typedef struct tagHD_MPSwitchCfgEx
{

    /** �����Ƿ�ر�����ƽ�� */
    BOOL_T bIsCloseSmoothSend;
} HD_MP_SWITCH_CFG_EX_S;

/**
 * @struct tagHD_STKDropCallCfgEx
 * @brief STK�Զ��Ҷ�ʱ������
 * @attention
 */
typedef struct tagHD_STKDropCallCfgEx
{

    /** ���Զ��Ƿ��Ծ�������ӳٳ�ʱʱ�䣬��λ�� */
    LONG_32 lRoundTripDelayTime;

    /** ���������ӳٵļ������λ�� */
    LONG_32 lRoundTripIntervalTime;

    /** ���������ӳٵĴ��� */
    LONG_32 lRoundTripCount;
} HD_STK_DROP_CALL_CFG_EX_S;

/**
 * @struct tagHD_ApPrearrange_CfgEx
 * @brief AP Ԥ����
 * @attention
 */
typedef struct tagHD_ApPrearrange_CfgEx
{

    /** ������ʱ���� */
    ULONG_32 ulDecodeTimeLapRtpNum;

    /** ������ʱ���� */
    ULONG_32 ulEncodeTimeLapRtpNum;
} HD_AP_PREARRANG_CFG_EX_S;

/**
 * @struct tagAddrbook_ItemEx
 * @brief ��ַ������ṹ(����)
 * @attention
 */
typedef struct tagAddrbook_ItemEx
{
    /** �ն�IP��ַ */
    CHAR                  szIPAddr[IMOS_IPADDR_LEN];

    /** �ն����� */
    CHAR                  szName[IMOS_NAME_LEN];

    /** �ն�E.164���� */
    CHAR                  szNumber[IMOS_HD_MAX_NAME_LENGTH];

    /**  �ն�H.323 ID */
    CHAR                  szAlias[IMOS_HD_MAX_NAME_LENGTH];

    /** ���� HD_PROTO_TYPE_EX_E */
    ULONG_32                 ulProtoType;

    /** ��0 */
    LONG_32                  lAddrID;

    /** ������Ϣ�����ն��в����ڣ� ��ռ��� */
    CHAR                  szCity[IMOS_HD_MAX_NAME_LENGTH];
    CHAR                  szProv[IMOS_HD_MAX_NAME_LENGTH];
    LONG_32                  lReservered[2];
} HD_ADDRBOOK_ITEM_EX_S;

/**
 * @struct tagBatchImportAddrAckEx
 * @brief ��iMSC�����������ַ�������Ľ���ṹ.
 * @attention
 */
typedef struct tagBatchImportAddrAckEx
{
    /** ���������� OPERATE_RESULT_E */
    ULONG_32                     ulRslt;

    /** ������ĵ�ַ����¼ */
    HD_ADDRBOOK_ITEM_EX_S      stAddrBookItem;
} BATCH_IMPORT_ADDR_ACK_CAUSE_EX_S;

/**
* @struct tagHD_AllConfigParamEx
* @brief MG�������ò���
* @attention
*/
typedef struct tagHD_AllConfigParamEx
{
    /** �����������ò���  */
    HD_ANSWER_CONFIG_EX_S            stAnswerParam;

    /** Э�����ò��� */
    HD_PROTOCOL_ALL_EX_S             stProtocolParam;



    /** �������������������ò��� */
    HD_ALLCONNECT_CONFIG_EX_S        stAllConnectParam;

    /** ���ں�*/
    HD_NIC_NUMBER_CFG_EX_S           stNICNumber;

    /** NIC�������ò��� */
    HD_ALLNIC_CONFIG_EX_S            stAllNicParam;

    /** ����NAT�������ò��� */
    HD_ALL_NAT_CONFIG_EX_S           stAllNATParam;

    /** NTP�������ò��� */
    HD_NTP_CONFIG_EX_S               stNTPParam;

    /** �����������ò��� */
    HD_MV_CONFIG_EX_S                stMvParam;

    /** �����������ò��� */
    HD_RV_CONFIG_EX_S                stRvParam;

    /** ��Ƶ�������ѡ������ */
    HD_VIDEO_INOUT_EX_S              stVideoIOParam;

    /** ��Ƶ���ò��� */
    HD_AUDIOALL_CONFIG_EX_S          stAudioParam;

    /** ���Լ������ */
    HD_INNER_MODULE_DEBUG_LEVEL_EX_S stDebugParam;

    /** ��־���ò��� */
    HD_LOG_CONFIG_EX_S               stLogParam;

    /** �����������ò��� */
    HD_UPDATE_CONFIG_EX_S            stUpdateParam;

    /** �᳡�������ò��� */
    HD_SITE_CONFIG_EX_S              stSiteParam;

    /** NAA���ò��� */
    HD_NAA_CONFIG_EX_S               stNAAParam;

    /** ��������ò��� */
    HD_ALLCAM_CONFIG_EX_S            stCamParam;

    /** �����Ԥ��λ */
    HD_ALLCAM_PRESET_POS_EX_S        stCamAllPos;


    /** QOS���ò��� */
    HD_QOS_SERVER_EX_S               stQosParam;

    /** ��Ƶ����˿����� */
    HD_VIDEO_IN_PORT_CFG_EX_S        stVideoInPortParam;

    /** ʵ����Ƶ����˿�����(������޹�) */
    HD_VIDEO_IN_PORT_EVENT_EX_S      stRealVideoInPortParam;

    /** ��Ƶ����˿����� */
    HD_VIDEO_OUT_PORT_CFG_EX_S       stVideoOutPortParam;

    /** �鲥���ò��� */
    MC_MULTICAST_CFG_EX_S            stMultiCastParam;

    /** �������� */
    HD_SYS_STARTED_CFG_EX_S          stStartedParam;

    /** �豸��Ϣ */
    HD_DEVICE_INFO_EX_S              stDevInfo;

    /** license ��Ϣ */
    HD_LICENSE_INFO_EX_S             stLicenseInfo;

    /** MP ������Ϣ(������޹�) */
    HD_MP_SWITCH_CFG_EX_S            stMPSwitchParam;

    /** �Ҷ���Ϣ(������޹�) */
    HD_STK_DROP_CALL_CFG_EX_S        stHangUpParam;

    /** AP Ԥ������Ϣ(������޹�) */
    HD_AP_PREARRANG_CFG_EX_S         stAPPrearrangeParam;
}MC_ALLCONFIGPARAM_EX_S;

/**
* @struct tagHD_NetworkConfigParamEx
* @brief MG�������ò���
* @attention
*/
typedef struct tagHD_NetworkConfigParamEx
{
    /** �������������������ò��� */
    HD_ALLCONNECT_CONFIG_EX_S        stAllConnectParam;

    /** ���ں�*/
    HD_NIC_NUMBER_CFG_EX_S           stNICNumber;

    /** NIC�������ò��� */
    HD_ALLNIC_CONFIG_EX_S            stAllNicParam;

    /** NAA���ò��� */
    HD_NAA_CONFIG_EX_S               stNAAParam;

    /** ����NAT�������ò��� */
    HD_ALL_NAT_CONFIG_EX_S           stAllNATParam;

    /** NTP�������ò��� */
    HD_NTP_CONFIG_EX_S               stNTPParam;

    /** QOS���ò��� */
    HD_QOS_SERVER_EX_S               stQosParam;

    /** �鲥���ò��� */
    MC_MULTICAST_CFG_EX_S            stMultiCastParam;
} MC_NETWORKCONFIGPARAM_EX_S;

/**
* @struct tagHD_VideoConfigParamEx
* @brief MG��Ƶ���ò���
* @attention
*/
typedef struct tagHD_VideoConfigParamEx
{
    /** �����������ò��� */
    HD_MV_CONFIG_EX_S                stMvParam;

    /** �����������ò��� */
    HD_RV_CONFIG_EX_S                stRvParam;

    /** ��Ƶ�������ѡ������ */
    HD_VIDEO_INOUT_EX_S              stVideoIOParam;

    /** ��������ò��� */
    HD_ALLCAM_CONFIG_EX_S            stCamParam;

    /** �����Ԥ��λ */
    HD_ALLCAM_PRESET_POS_EX_S        stCamAllPos;

    /** ��Ƶ����˿����� */
    HD_VIDEO_IN_PORT_CFG_EX_S        stVideoInPortParam;

    /** ʵ����Ƶ����˿�����(������޹�) */
    HD_VIDEO_IN_PORT_EVENT_EX_S      stRealVideoInPortParam;

    /** ��Ƶ����˿����� */
    HD_VIDEO_OUT_PORT_CFG_EX_S       stVideoOutPortParam;

} MC_VIDEOCONFIGPARAM_EX_S;

#if 0
#endif

/*************************************************************************************
SS ��СMIB
***************************************************************************************/

/**
 * @struct tagDevicePerformanceInfo
 * @brief �豸��������
 * @attention
 */
typedef struct tagDevicePerformanceInfo
{
    /** ���豸����֮�� �豸�ܵ�����ʱ�� */
    ULONG_32                 ulSysUpTime;

    /** CPU������ */
    ULONG_32                 ulCpuUsage;

    /** �ڴ�������  */
    ULONG_32                 ulMemUsage;

    /** �ڴ��С  */
    ULONG_32                 ulMemSize;

    /** �豸�¶�  */
    LONG_32                  lTemperature;
} DEVICE_PERFORMANCE_INFO_S;

/**
 * @struct tagPort_InfoEx
 * @brief �˿���Ϣ
 * @attention
 */
typedef struct tagPort_Info
{
    /** �ӿ������� Ϊ����0������ */
    LONG_32                  lIfIndex;

    /** �ӿ����ͣ� һ��Ϊ6. ethernetCsmacd(6), -- for all ethernet-like interfaces, regardless of speed, as per RFC3635 */
    LONG_32                  lIfType;

    /** �ӿ����� */
    CHAR                  szIfDescr[IMOS_DESC_LEN];

    /** �ӿ��ܹ�����/���͵����İ� */
    LONG_32                  lIfMtu;

    /** IfAdminStatus��ifOperStatus��ӳ���豸�ӿڵ�״̬������������ʾ�豸״̬ */

    /** �ӿڵĹ���״̬�� ȡֵ��Χ:
       1: up(1)
       2: down(2)
       3: testing(3)
    */
    LONG_32                  lIfAdminStatus;

    /** �ӿڵĲ���״̬�� ȡֵ��Χ:
        1: up(1)
        2: down(2)
        3: testing(3)
        4: unknown(4)
        5: dormant(5)
        6: notPresent(6)
        7: lowerLayerDown(7)
    */
    LONG_32                  lIfOperStatus;

    /** �����ַ */
    CHAR                  szIfPhysAddress[IMOS_IPADDR_LEN];

    /** �˿����� */
    ULONG_32                 ulIfSpeed;

} PORT_INFO_S;

/**
 * @struct tagDevicePortInfo
 * @brief �豸�˿���Ϣ
 * @attention
 */
typedef struct tagDevicePortInfo
{
    /** �˿ڸ��� */
    ULONG_32                        ulPortNum;

    /** �˿���Ϣ */
    PORT_INFO_S               astPortInfo[IMOS_HD_MAX_PRIVATE_NET_COUNT];
} DEVICE_PORT_INFO_S;

/*************************************************************************************
SS �ʼ�������ص�����
***************************************************************************************/
/**
 * @struct tagEmailSendingRules
 * @brief �ʼ����͹���:
 * �ʼ����ʹ������ֵ��ȣ�
 * 1������������޸Ļ���ɹ�ʱ�� ֪ͨһ�Σ�
 * 2������֮ǰһСʱ ֪ͨ3�Σ���1�Σ�����ǰ1Сʱ����2�Σ�ǰ��Сʱ����3�Σ�ǰʮ���ӣ���
 * @attention
 */
typedef struct tagEmailSendingRules
{
    /** ����������޸Ļ���ɹ�ʱ�� ֪ͨһ�Ρ� BOOL_TRUE��֪ͨ�� ����֪ͨ */
    BOOL_T  bSendMailOnceConfCreated;

    /** �Ƿ񷢳�֪ͨ�� BOOL_TRUE��֪ͨ�� ����֪ͨ  */
    BOOL_T  abNotify[IMOS_EMAIL_NOTIFICATION_NUMBER];

    /** ��ǰ��ǰ֪ͨʱ�䣬 ��λΪ���� */
    ULONG_32   aulNotifyTime[IMOS_EMAIL_NOTIFICATION_NUMBER];
} EMAIL_SENDING_RULES_S;


/*************************************************************************************
SS ˫��·��������
***************************************************************************************/




/**
 * @struct tagModifyTermRepEx
 * @brief MCU�ϱ��ն��޸ĵ���Ϣ
 * @attention
 */
typedef struct tagModifyTermRepEx
{
    /** �ն˱��� */
    CHAR  szTermCode[IMOS_DEVICE_CODE_LEN];

    /** �ն����� */
    CHAR  szTermName[IMOS_NAME_LEN];

    /** ˫��·��Ϣ */
    MC_LINK_INFO_EX_S      stLinkInfo;

    /** �澯��Ϣ */
    MC_TERM_ALARM_INFO_EX_S stAlarmInfo;

} MODIFY_TERM_REP_EX_S;

/**
 * @struct tagMCSetPicModeMsgEx
 * @brief ����ģʽ
 * @attention
*/
typedef struct tagMCSetPicModeMsgEx
{
    /** ����ѡ��ۿ�ģʽ MC_CHAIR_BROWSE_MODE_EX_E */
    ULONG_32                              ulChairBrowseMode;

    /** �㲥ģʽ MC_BROADCAST_MODE_EX_E */
    ULONG_32                              ulBroadcastMode;

    /** ��������ϸ��Ϣ�ṹ */
    MC_MULTI_PIC_SITE_SHOW_MODE_EX_S   stSinglePicInfo;

    /** �໭��ģʽ���᳡λ�õȽṹ*/
    MC_MULTI_PIC_INFO_EX_S             stMultiPicModePos;
} MC_SET_PIC_MODE_MSG_EX_S;


/**
 * @struct tagMC_ConfigRouteMsgEx
 * @brief ��ӡ��޸ġ�ɾ��MCU����·����Ϣ��ֻ���޸ĵ�ʱ����д�ɵ�·��
 * @attention
*/
typedef struct tagMC_ConfigRouteMsgEx
{
    /** ���ڱ�� */
    ULONG_32                      ulLanID;

    /** ·���޸����� MC_CONFIG_ROUTE_TYPE_EX_E*/
    ULONG_32                      ulConfigRouteType;

    /** �ɵ�·�� */
    MC_MCU_ROUTE_EX_S          stOldRoute;

    /** �µ�·�� */
    MC_MCU_ROUTE_EX_S          stNewRoute;
} MC_CONFIG_ROUTE_MSG_EX_S;


/**
 * @struct tagMC_ConfCtrlInfoEx
 * @brief �����Ƿ��Զ�����˷�����ݽṹ
 * @attention
*/
typedef struct tagMC_ConfCtrlInfoEx
{
    /** ����ѡ��ۿ��᳡�Ƿ��Զ�����˷� */
    BOOL_T                     bIsChairWatchedMicAutoOpen;

    /** ���㲥�᳡�Ƿ��Զ�����˷� */
    BOOL_T                     bIsBroadcastedMicAutoOpen;
} MC_CONF_CTRL_INFO_EX_S;


/**
 * @struct tagBackupMCUReport
 * @brief  ����MCU��Ϣ
 * @attention
 */
typedef struct tagBackupMCUReport
{
    /** MCU���� */
    CHAR szMCUCode[IMOS_RES_CODE_LEN];

    /** MCU���� */
    CHAR szMCUName[IMOS_NAME_LEN];

    /** MCU�豸��ַ */
    CHAR szMCUAddr[IMOS_IPADDR_LEN];

    /**������MCU�豸��ַ */
    CHAR szBackupMCUAddr[IMOS_IPADDR_LEN];
} BACKUP_MCU_REPORT_S;


/**
 * @struct tagConfSendRoleSiteChange
 * @brief  ���鵱ǰ�������͵Ļ᳡�ı仯
 * @attention
 */
typedef struct tagConfSendRoleSiteChange
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �᳡���� */
    CHAR     szSiteCode[IMOS_RES_CODE_LEN];

    /** �᳡���� */
    CHAR     szSiteName[IMOS_NAME_LEN];

    /** ��������/ֹͣ���ͱ��, (TRUE)--��ʼ���ͣ� (FALSE)--ֹͣ���� */
    BOOL_T   bSendRole;
} CONF_SEND_ROLE_SITE_CHANGE_S;


/**
 * @struct tagConfAutoMultPicChange
 * @brief  �໭���Զ��л�ֵ�ı�
 * @attention
 */
typedef struct tagConfAutoMultPicChange
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �Զ��л���״ֵ̬ */
    BOOL_T   bAutoMultiPic;
} CONF_AUTOMULTIPIC_CHANGE_S;


/**
 * @struct tagConfSetTurnBroadcaseChange
 * @brief  ������ѯģʽ�ı�
 * @attention
 */
typedef struct tagConfSetTurnBroadcaseChange
{
    /** ����ID */
    IMOS_ID  idConfId;

    /**  ��Ѳģʽ   MC_CONF_TURN_BROADCAST_MODE_EX_E*/
    ULONG_32    ulTurnMode;

    /** BOOL_TRUE, ������ѯ, ������ѯ */
    BOOL_T    bCycle;
} CONF_SET_TURN_BROADCAST_CHANGE_S;

/**
 * @struct tagConfSetPicModeChange
 * @brief  ���û���ģʽ�ϱ�
 * @attention
 */
typedef struct tagConfSetPicModeChange
{
    /** ����ID */
    IMOS_ID  idConfId;
} CONF_SET_PIC_MODE_CHANGE_S;

/**
* @struct tagMcuSyncStatusChange
* @brief  MCUͬ��״̬�ı��ϱ�
* @attention
*/
typedef struct tagMcuSyncStatusChange
{
    /** MCU���� */
    CHAR szMcuCode[IMOS_DEVICE_CODE_LEN];

    /** ͬ��״̬(MCU_SYNCHRON_STATUS_E) */
    ULONG_32 ulMcuSyncStatus;

    /** ͬ������������(ͬ����ʼ��Զ��0��ͬ�������ɹ���0��ʧ������Ӧ������) */
    ULONG_32 ulSyncRet;

    /** �û���½���룬���û���½�����������ģ�Ψһ��ʶ�� */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

} MCU_SYNC_STATUS_CHANGE_S;

/**
 * @struct tagConfFECCChange
 * @brief  ���鵱ǰFECC�����߻򱻿��߷����仯
 * @attention
 */
typedef struct tagConfFECCChange
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** �����߻᳡���� */
    CHAR     szControllerCode[IMOS_RES_CODE_LEN];

    /** �����߻᳡���� */
    CHAR     szControllerName[IMOS_NAME_LEN];

    /** �����߻᳡���� */
    CHAR     szControlledCode[IMOS_RES_CODE_LEN];

    /** �����߻᳡���� */
    CHAR     szControlledName[IMOS_NAME_LEN];

} CONF_FECC_CHANGE_S;

/**
* @struct tagConfMcuBackupChange
* @brief  ����MCU������Ϣ
* @attention
*/
typedef struct tagConfMcuBackupChange
{
    /** ����ID */
    IMOS_ID  idConfId;

    /** ����MCU���� */
    CHAR szMCUCode[IMOS_RES_CODE_LEN];

    /** ����MCU���� */
    CHAR szMCUName[IMOS_NAME_LEN];

    /** ����MCU���� */
    CHAR szBackupMCUCode[IMOS_RES_CODE_LEN];

} CONF_MCU_BACKUP_CHANGE_S;

#pragma pack()

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

