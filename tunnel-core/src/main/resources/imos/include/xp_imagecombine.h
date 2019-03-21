/*******************************************************************************
Copyright (c) 2008-2013, Zhejiang Uniview Technology Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                            xp_imagecombine.h
Project Code: XP
Module Name:  MPM
Date Created: 2011-11-21
Author:       wangjiangzhu/06641
Description:  ���jpgͼƬ��ƴ�����ַ����Ӳ���
--------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
YYYY-MM-DD

*******************************************************************************/

#ifndef __XP_IMAGECOMBINE_H__
#define __XP_IMAGECOMBINE_H__

#ifdef  __cplusplus
extern "C"{
#endif

/** ����ѡ�� */
#if defined(WIN32)
    #if defined(IMAGECOMBINE_EXPORTS)
        #define IMAGE_COMBINE_EXPORT  __declspec( dllexport )
    #else
        #define IMAGE_COMBINE_EXPORT  __declspec( dllimport )
    #endif
#else
    #define IMAGE_COMBINE_EXPORT
#endif

#define TMS_CB_CMD_ID        0x040702
#define COMBINE_SIX_PIC      0x80000000
#define CUT_ENABLE           0x40000000

/* �������ô����붨�� */
#define   SUCCEED                    0         //�������óɹ�
#define   ERR_INVALID_PARAMETER      1         //��������Ƿ�
#define   ERR_SYSTEM_MEMORY          2         //����ϵͳ�ڴ�ʧ��
#define   ERR_MEMORY_NOT_ENOUGH      3         //������ڴ治��
#define   ERR_NOT_BMP_PIC            4         //�����ͼƬ��ΪBMPͼƬ
#define   ERR_RGB2YUV_FAILED         5         //RGBתYUVͼƬʧ��

#define   ERR_CREATE_JEG_DECODERR    6         //����Jpg������ʧ��
#define   ERR_JPG_DECODE_PIC         7         //����JpgͼƬʧ��

#define   ERR_CREATE_RESAMPLE        8         //����ͼƬ�ز������ʧ��
#define   ERR_RESET_RESAMPLE_PAR     9         //�����ز�������ʧ��
#define   ERR_RESAMPLE_FAILED        10        //����ͼƬ�ز���ʧ��

#define   ERR_CREATE_JPG_ENCODER     11        //jpe����������ʧ��
#define   ERR_JPG_ENCODE_PIC         12        //jpg����ʧ��

#define   ERR_PRE_DECODE_FAILEDD     13        //ͼƬ���г���Ԥ����ʧ��
#define   ERR_BMP_DECODE_PIC         14        //BMP����ʧ��
#define TMS_UV_MAX_VEHICLE_PIC_NUM   4         //���ͼƬ����

/* ͼƬƴ��ģʽ */
typedef enum tagCombinePicMode
{
    /* Begin modify by WangJiangZhu for MPPD00488, ��������Ӧ����дͼƬ����20130128 */
    COMBINE_PIC_MODE_NONE           = 0,     /*< ��ָ����Ⱦģʽ */
    COMBINE_PIC_MODE_TOP1DOWN3      = 1,     /*< 3��ͼƬ����1��3ģʽ����1������Ϊͬһ�� */
    COMBINE_PIC_MODE_LEFT1RIGHT3    = 2,     /*< 3��ͼƬ����1��3ģʽ����1������Ϊͬһ�� */
    COMBINE_PIC_MODE_TOP1DOWN1      = 3,     /*< 2��ͼƬ����1��1ģʽ */
    COMBINE_PIC_MODE_LEFT1RIGHT1    = 4,     /*< 2��ͼƬ����1��1ģʽ */
    COMBINE_PIC_MODE_STOP2DOWN2     = 5,     /*< 3��ͼƬ���ϳ����ָ�1������2�����ң�3�����󣬵�1����д������ */
    COMBINE_PIC_MODE_TOP2DOWN2      = 6,     /*< 4��ͼƬ���ϳ����ָ� */
    COMBINE_PIC_MODE_4STOP2DOWN2    = 7,     /*< 4��ͼƬ���ϳ����ָ�2������3�����ң�4�����󣬵�1����д������ */
    COMBINE_PIC_MODE_SLINEDISCARD   = 8,     /*< 2~4��ͼƬ���ϳ�1���Σ���1����ȡ��дͼƬ����1��ԭͼ���� */
    COMBINE_PIC_MODE_SLINE          = 9,     /*< 1~3��ͼƬ���ϳ�1���Σ���1����ȡ��дͼƬ����1��ԭͼ������ */
    COMBINE_PIC_MODE_LINE           = 10,    /*< 2~4��ͼƬ��ֱ�Ӻϳ�1���� */
    COMBINE_PIC_MODE_ONE_PICTURE    = 11,    /*< 1��ͼƬ*/
    COMBINE_PIC_MODE_TOP3DOWN3      = 12,    /* �����羯6ͼ�ϳ� */
    COMBINE_PIC_MODE_TOP2DOWN2EX    = 13,    /* �����羯4ͼ�ϳ� */

    COMBINE_PIC_MODE_MAX,                    /*< ��ǰ֧�ֵ���Ⱦģʽ */
    COMBINE_PIC_MODE_INVALID        = 0xFFFF /*< ��Чֵ */
    /* END modify by WangJiangZhu for MPPD00488, ��������Ӧ����дͼƬ���� 20130128*/
}COMBINE_PIC_MODE_E;


typedef enum tagOSDPlaceMode
{
	OSD_PLACE_MODE_TOP,
	OSD_PLACE_MODE_DOWN
}OSD_PLACE_MODE;

/* ͼ����Ϣ */
typedef struct tagSrcPictureInfo
{
    UCHAR *  pucSrcJpgPicture;
    ULONG_32    ulSrcJpgPictureSize;
}SRC_PICTURE_INFO_S;

/**
* @struct tagTMSOsdInfo
* @brief TMS OSD
* @attention ��
*/
typedef struct tagTMSOsdInfo
{
    /** ��������OSD��ʼX���� */
    ULONG_32 ulOriginX;

    /** ��������OSD��ʼY���� */
    ULONG_32 ulOriginY;

    /** ������ɫ */
    long  lbkcolor;

    /** ����͸���� */
    long  lbkTransparence;

    /** OSD͸���� */
    long  lTransparence;

    /** �����С */
    long  lSize;

    /** ������ɫ */
    long  lColor;

    /** ���� */
    char  szFont[15];

    /** OSD���� */
    ULONG_32 ulOSDNum;

    /** OSD�б� */
    char  aszOSD[4][256];
}TMS_OSD_INFO_S;

#ifndef _H3C_VIDEO_MJPEG_H_
/**
* @struct tagPictureYUV420
* @brief ͼ��ṹ�嶨��
* @attention ��
*/
typedef struct tagPictureYUV420
{
    UCHAR   *pucData[4];
    LONG_32    pLines[4];
    LONG_32    lWidth;
    LONG_32    lHeight;
}PICTURE_YUV420_S;
#endif

/**
* ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
* �ֿ�ʹ�õ����ֿ�
* @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
* @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
* @param[in] pucSrcJpgPicture2      ����ͼƬ2��ʼ��ַ
* @param[in] ulSrcJpgPictureSize2�� ����ͼƬ2���ڴ��С
* @param[in] pucSrcJpgPicture3      ����ͼƬ3��ʼ��ַ
* @param[in] ulSrcJpgPictureSize3   ����ͼƬ3���ڴ��С
* @param[in] pstOsdInfo             OSD�ṹ����Ϣ
* @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
* @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
* @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
* @param[out] ulOSDPlaceMode     ͼ��ƴ��OSD��λ��
* @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSD(UCHAR * pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                         UCHAR * pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                         UCHAR * pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                         const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                         UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize, ULONG_32 ulOSDPlaceMode);

/**
* ��BMPͼƬת��ΪJPGͼƬ.
* @param[in] pucBmpPicture       ����BMPͼƬ
* @param[in] ulBmpPicture        ����BMPͼƬ�Ĵ�С
* @param[OUT] pucJpgPicture      �����JpgͼƬ
* @param[OUT] pulJpgPictureSize�������JpgͼƬ��С
* @return ͼƬת���Ƿ�ɹ�
*/
IMAGE_COMBINE_EXPORT int  STDCALL bmp2Jpg(UCHAR * pucBmpPicture, ULONG_32 ulBmpPicture,
                                          UCHAR * pucJpgPicture, ULONG_32 *pulJpgPictureSize);

/**
* ��һ��jpgͼƬ�л�ȡ������дͼƬ
* @param[in] pucJpgPicture       ����JpgͼƬ
* @param[in] pulJpgPictureSize   ����JpgͼƬ�Ĵ�С
* @param[OUT] pucPlateJpg        �������JpgͼƬ
* @param[OUT] pulPlateJpgSize��  �������JpgͼƬ��С
* @return ��ȡͼƬ�Ƿ�ɹ����������jpgͼƬ�в����г���λ�õ���Ϣ���ȡʧ��
*         ����˾�豸Ҳ����ֿ�ȡͼƬʧ��
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL Jpg2PlateJpg(UCHAR * pucJpgPicture, ULONG_32 pulJpgPictureSize,
                                                   UCHAR * pucPlateJpg, ULONG_32 *pulPlateJpgSize);

/**
* ��һ��jpgͼƬ�л�ȡ������дͼƬ��λ��
* @param[in] pucJpgPicture       ����JpgͼƬ
* @param[in] pulJpgPictureSize   ����JpgͼƬ�Ĵ�С
* @param[OUT] aulPosition        �������λ��
* @return ��ѯ���
*         
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL findPlateFromPic(IN UCHAR * pucJpgPicture, IN ULONG_32 pulJpgPictureSize,
                                                   OUT LONG_32 alPosition[4]);

/**
* �Ե���ͼƬ����OSD
* @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
* @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
* @param[in] pstOsdInfo             OSD�ṹ����Ϣ
* @param[in] ulOSDPlaceMode         OSDλ��
* @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
* @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
* @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combineOnePictureWithOSD(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                            const TMS_OSD_INFO_S *pstOsdInfo, ULONG_32 ulOSDPlaceMode,
                                                            UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize);

#ifdef WIN32
/**
* ��BMPͼƬת��ΪJPGͼƬ.
* @param[in]  YUV��ͼƬ�ṹ��
* @param[OUT] pucJpgPicture      �����JpgͼƬ
* @param[OUT] pulJpgPictureSize�������JpgͼƬ��С
* @return ͼƬת���Ƿ�ɹ�
*/
IMAGE_COMBINE_EXPORT int  STDCALL yuv2Jpg(DSP_Picture_Mjpeg_S * pstPictureYuv420,
                                          UCHAR * pucJpgPicture, ULONG_32 *pulJpgPictureSize);


/**
* ����ͼƬ
* @param[in] pucSrcJpgPicture       �����ܵ�JPGͼƬ
* @param[in] ulSrcJpgPictureSize    �����ܵ�JPGͼƬ��С
* @param[out] pucDstJpgPicture      ���ܺ��JPGͼƬ
* @param[out] pulDstJpgPictureSize  ���ܺ��JPGͼƬ��С
* @return �����Ƿ�ɹ�
*/
IMAGE_COMBINE_EXPORT int  STDCALL encImgData(UCHAR *pucSrcJpgPicture,
                                             ULONG_32 ulSrcJpgPictureSize,
                                             UCHAR *pucDstJpgPicture,
                                             ULONG_32 *pulDstJpgPictureSize);

#endif

/**
* ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
* �ֿ�ʹ�õ����ֿ�
* @param[in] pstSrcPictureInfo      ԭʼͼ��
* @param[in] ulSrcPictureNum        ԭʼͼ����Ŀ
* @param[in] pstOsdInfo             OSD�ṹ����Ϣ
* @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
* @param[in] ucAroundSidePixel     ͼƬ���ܱ߿��(����Ϊ��λ��ֻ��4��ͼƬ��������Ч)
* @param[in] ucCenterSidePixel       ͼƬ���ı߿��(����Ϊ��λ��ֻ��4��ͼƬ��������Ч)
* @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
* @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
* @param[out] ulOSDPlaceMode     ͼ��ƴ��OSD��λ��
* @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDEx(SRC_PICTURE_INFO_S *pstSrcPictureInfo, ULONG_32 ulSrcPictureNum,
                                                           const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                           UCHAR ucAroundSidePixel, UCHAR ucCenterSidePixel,
                                                           UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode);


 /* BEGIN: added by ChenXiaoYan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ�ţ�MPPD06632 */
 /**
 * ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
 * �ֿ�ʹ��ʸ���ֿ�,һ��Ҫ���������С
 * @param[in] pstSrcPictureInfo      ԭʼͼ��
 * @param[in] ulSrcPictureNum        ԭʼͼ����Ŀ
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
 * @param[in] ucAroundSidePixel     ͼƬ���ܱ߿��(����Ϊ��λ��ֻ��4��ͼƬ��������Ч)
 * @param[in] ucCenterSidePixel       ͼƬ���ı߿��(����Ϊ��λ��ֻ��4��ͼƬ��������Ч)
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDExUseVector(SRC_PICTURE_INFO_S *pstSrcPictureInfo, ULONG_32 ulSrcPictureNum,
                                                            const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                            UCHAR ucAroundSidePixel, UCHAR ucCenterSidePixel,
                                                            UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum);



 /**
 * ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
 * �ֿ�ʹ��ʸ���ֿ�,һ��Ҫ���������С
 * @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
 * @param[in] pucSrcJpgPicture2      ����ͼƬ2��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize2�� ����ͼƬ2���ڴ��С
 * @param[in] pucSrcJpgPicture3      ����ͼƬ3��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize3   ����ͼƬ3���ڴ��С
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDUseVector(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                          UCHAR *pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                          UCHAR *pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                          const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                          UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum);


/**
 * �Ե���ͼƬ����OSD 
 * �ֿ�ʹ��ʸ���ֿ�,һ��Ҫ���������С
 * @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[in] ulOSDPlaceMode         OSDλ��
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�   lattice vector
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combineOnePictureWithOSDUseVector(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
     const TMS_OSD_INFO_S *pstOsdInfo, ULONG_32 ulOSDPlaceMode,
     UCHAR *pucDstJpgPicture, ULONG_32 *pulDstJpgPictureSize);
 /* END: added by ChenXiaoYan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ�ţ�MPPD06632 */


/**
*����ͼ�������С 
* @param[in] pucSrcJpgPicture1             ����ͼƬ��ʼ��ַ
* @param[in] ulSrcJpgPictureSize1          ����ͼƬ1���ڴ��С
* @param[in] ulFlexibleNum                 ��Сϵ�����ٷֱ�1~100��
* @param[in] ucQuality   ��[���]ͼƬ��ѹ���������ӣ�1��10����1�����������10����������
* @param[in] pucDstJpgPicture              ���ͼƬ��ʼ��ַ
* @param[in] pulDstJpgPictureSize          ���ͼƬ�ڴ��С
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL flexibleImage(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
													ULONG_32 ulFlexibleNum,  UCHAR ucQuality,
													UCHAR *pucDstJpgPicture, ULONG_32 *pulDstJpgPictureSize);

 /**
* �ѵ羯����������ͼ�� ���ڹ�����ͼƬ�ϳ�3+3��ģʽ
* @param[in] pstSrcPicInfo_1      ����ͼƬ1�Ĵ洢�ṹ
* @param[in] pstSrcPicInfo_2      ����ͼƬ2�Ĵ洢�ṹ
* @param[in] pstOsdInfo           OSD�ṹ����Ϣ(NULL��ʾ����OSD����֮�����)
* @param[out] pstDstJpgPicture    ƴ�Ӻ�ͼƬ�Ĵ洢�ṹ
* @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
*/
/*
ULONG_32 combineTop3Down3_Do
(IN SRC_PICTURE_INFO_S *pstSrcPictureInfo, IN ULONG_32 ulSrcPictureNum,
 IN SRC_PICTURE_INFO_S * pstSrcPicInfo_2, IN const TMS_OSD_INFO_S *pstOsdInfo, IN ULONG_32 ulCombineNum, 
 OUT SRC_PICTURE_INFO_S * pstDstPicInfo)
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combineElecPolicePicture(IN SRC_PICTURE_INFO_S *pstSrcPictureInfo, IN ULONG_32 ulSrcPictureNum, IN SRC_PICTURE_INFO_S * pstSrcPicInfo_2,
                                                          IN const TMS_OSD_INFO_S *pstOsdInfo,  IN ULONG_32 ulCombineMode,
                                                          IN UCHAR ucAroundSidePixel, IN UCHAR ucCenterSidePixel,
                                                          OUT UCHAR *pucSrcJpgPicture, OUT ULONG_32 &ulSrcJpgPictureSize,  IN ULONG_32 ulOSDPlace,ULONG_32 ulOsdPicNum
                                                          );
 /**
 * ����ͼƬƴ��
 * @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureForSpecial(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
     const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
     UCHAR *pucDstJpgPicture,   ULONG_32 &ulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode);

  /**
 * ��һ��jpgͼƬ�л�ȡ������дͼƬ
 * @param[in] pucJpgPicture       ����JpgͼƬ
 * @param[in] pulJpgPictureSize   ����JpgͼƬ�Ĵ�С
 * @param[in] ulTopX              ������ʼλ��X����
 * @param[in] ulTopY              ������ʼλ��Y����
 * @param[in] ulHeight            ��������߶�
 * @param[in] ulWidth             ����������
 * @param[OUT] pucPlateJpg        �������JpgͼƬ
 * @param[OUT] pulPlateJpgSize��  �������JpgͼƬ��С
 * @return ��ȡͼƬ�Ƿ�ɹ����������jpgͼƬ�в����г���λ�õ���Ϣ���ȡʧ��
 *         ����˾�豸Ҳ����ֿ�ȡͼƬʧ��
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL CutRectFromPic(IN UCHAR * pucJpgPicture, IN ULONG_32 pulJpgPictureSize,IN ULONG_32 ulTopX, IN ULONG_32 ulTopY,
                                                    IN ULONG_32 ulHeight,IN ULONG_32 ulWidth, OUT UCHAR * pucPlateJpg, OUT ULONG_32 *pulPlateJpgSize);
     
 /**
 * ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
 * �ֿ�ʹ��ʸ���ֿ�
 * @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
 * @param[in] pucSrcJpgPicture2      ����ͼƬ2��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize2�� ����ͼƬ2���ڴ��С
 * @param[in] pucSrcJpgPicture3      ����ͼƬ3��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize3   ����ͼƬ3���ڴ��С
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @param[in] ulOSDPlaceMode         OSD����λ��
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combine3VPictureWithOSD(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                                  UCHAR *pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                                  UCHAR *pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                                  const TMS_OSD_INFO_S *pstOsdInfo, 
                                                                  UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize);
 /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
 /**
 * ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
 * �ֿ�ʹ��ʸ���ֿ�
 * @param[in] pstSrcPictureInfo      ԭʼͼ��
 * @param[in] ulSrcPictureNum        ԭʼͼ����Ŀ
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
 * @param[in] ucAroundSidePixel     ͼƬ���ܱ߿��(����Ϊ��λ��ֻ��4��ͼƬ��������Ч)
 * @param[in] ucCenterSidePixel       ͼƬ���ı߿��(����Ϊ��λ��ֻ��4��ͼƬ��������Ч)
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDExUseVectorWithLimitSize(SRC_PICTURE_INFO_S *pstSrcPictureInfo, ULONG_32 ulSrcPictureNum,
                                                                    const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                                    UCHAR ucAroundSidePixel, UCHAR ucCenterSidePixel,
                                                                    UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum,ULONG_32 ulLimitSize);


/* �ѵ羯����������ͼ�� ���ڹ�����ͼƬ�ϳ�3+3��ģʽ
* @param[in] pstSrcPicInfo_1      ����ͼƬ1�Ĵ洢�ṹ
* @param[in] pstSrcPicInfo_2      ����ͼƬ2�Ĵ洢�ṹ
* @param[in] pstOsdInfo           OSD�ṹ����Ϣ(NULL��ʾ����OSD����֮�����)
* @param[out] pstDstJpgPicture    ƴ�Ӻ�ͼƬ�Ĵ洢�ṹ
* @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
*/
/*
ULONG_32 combineTop3Down3_Do
(IN SRC_PICTURE_INFO_S *pstSrcPictureInfo, IN ULONG_32 ulSrcPictureNum,
 IN SRC_PICTURE_INFO_S * pstSrcPicInfo_2, IN const TMS_OSD_INFO_S *pstOsdInfo, IN ULONG_32 ulCombineNum, 
 OUT SRC_PICTURE_INFO_S * pstDstPicInfo)
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combineElecPolicePictureWithLimitSize(IN SRC_PICTURE_INFO_S *pstSrcPictureInfo, IN ULONG_32 ulSrcPictureNum, IN SRC_PICTURE_INFO_S * pstSrcPicInfo_2,
                                                          IN const TMS_OSD_INFO_S *pstOsdInfo,  IN ULONG_32 ulCombineMode,
                                                          IN UCHAR ucAroundSidePixel, IN UCHAR ucCenterSidePixel,
                                                          OUT UCHAR *pucSrcJpgPicture, OUT ULONG_32 &ulSrcJpgPictureSize,  IN ULONG_32 ulOSDPlace,ULONG_32 ulOsdPicNum,ULONG_32 ulLimitSize
                                                          );

  /**
 * ����ͼƬƴ�ӣ�֧������ͼƬ��ƴ�ӣ��ڲ���������Ӧ����ǰulCombineMode�ֶ���ʱû��ʹ��.
 * �ֿ�ʹ��ʸ���ֿ�
 * @param[in] pucSrcJpgPicture1      ����ͼƬ1��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize1   ����ͼƬ1���ڴ��С
 * @param[in] pucSrcJpgPicture2      ����ͼƬ2��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize2�� ����ͼƬ2���ڴ��С
 * @param[in] pucSrcJpgPicture3      ����ͼƬ3��ʼ��ַ
 * @param[in] ulSrcJpgPictureSize3   ����ͼƬ3���ڴ��С
 * @param[in] pstOsdInfo             OSD�ṹ����Ϣ
 * @param[in] ulCombineMode          ͼ��ƴ��ģʽ����ʱ��ʹ��
 * @param[out] pucDstJpgPicture      ƴ�Ӻ�ͼƬ���ڴ�
 * @param[out] pulDstJpgPictureSize  ƴ�Ӻ󱣴�ͼƬ���ڴ��С
 * @return ͼ��ƴ�Ӳ����Ƿ�ɹ�
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDUseVectorWithLimitSize(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                                  UCHAR *pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                                  UCHAR *pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                                  const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                                  UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum,ULONG_32 ulLImitSize);

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif
