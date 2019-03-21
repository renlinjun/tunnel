/*******************************************************************************
 Copyright (c) 2008-2013, Zhejiang Uniview Technology Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                             xp_overlaytext.h
  Project Code: XP
   Module Name: MPM
  Date Created: 2011-11-05
        Author: wangjiangzhu/06641
   Description: ͼƬ�ϳɺ�OSD��Ϣ����

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/

#ifndef _XP_OVERLAY_TEXT_H_
#define _XP_OVERLAY_TEXT_H_

#include "xp_imagecombine.h"
 /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
#ifdef _USE_TRUETYPE_FONT
#include "ft2build.h"
#include FT_FREETYPE_H
#endif
 /* END: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
#define  MAX_OSD_SIZE    512
#define  MAX_FONT_MATRIX 48

/**
* @enum tagOverlayHandleType
* @brief �ֿ������Ͷ���
* @attention ��
*/
typedef enum tagOverlayHandleType
{
    OVERLAY_FONT_TYPE_HZK_24,
    OVERLAY_FONT_TYPE_ASC_24,
    OVERLAY_FONT_TYPE_HZK_48,
    OVERLAY_FONT_TYPE_ASC_48,
    OVERLAY_FONT_TYPE_INVALID
}OVERLAY_FONT_TYPE_E;

/* �ַ�����ṹ�� */
typedef struct tagOsdFontPointMatrix
{
    UCHAR    szOsdText[MAX_OSD_SIZE]; /* ��ǰ�ַ��������󳤶� */
    LONG_32     lOsdTextLen;            /* ��ǰ��Ҫ���ӵ��ַ������� */
    UCHAR    *pucPointBeginAddr;      /* ������ʼ��ַ */
    UCHAR    *pucPointCurAddr;        /* ����ǰ��ַ */
    LONG_32     lOneFontSizeBytes;       /* ÿ�����ֵ��ֽ��� */
    LONG_32     lOneFontPixelSize;       /* �ֿ�����С */
}OSD_FONT_POINT_MATRIX_S;

/* RGB��ɫ��Ϣ */
typedef struct tagRGB
{
    UCHAR ucR;
    UCHAR ucG;
    UCHAR ucB;
}RGB_POINT_S;

/* YUV��ɫ��Ϣ */
typedef struct tagYUV
{
    UCHAR ucY;
    UCHAR ucU;
    UCHAR ucV;
}YUV_POINT_S;

/* �ֿ���Ϣ�ַ������� */
#define  HZK_24_FILE   "Hzk24.dat"
#define  ASC_24_FILE   "Asc24.dat"
#define  HZK_48_FILE   "Hzk48s.dat"
#define  ASC_48_FILE   "Asc48.dat"
 /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
#define  TRUETYPE_FILE   "simsun.ttc"
 /* END: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
/* ����ͼƬ������ѡ����Ҫ���ӵ�OSD�����С */
#define  PICTURE_D1_HEIGHT   576
#define PICTURE_D1_WIDTH     720
#define  PICTURE_720_HEIGHT  720

/* �����ַ������� */
class COverlayText
{
public:
    /**
    * ���캯�� \n
    */
    COverlayText(VOID);

    /**
    * �������� \n
    */
    ~COverlayText(VOID);
public:

    /**
    * ��ʼ��ͼ��ƴ����Ҫ����Դ \n
    */
    ULONG_32 initOverlayText(VOID);

    /**
    * ����OSD \n
    * @param [IN] ulPosition_X      X����
    * @param [IN] ulPosition_Y      Y����
    * @param [IN] strOSDText        OSD
    * @param [IN][OUT] stPicture    ͼƬYUV
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 overlayText(IN ULONG_32 ulPosition_X,
                      IN ULONG_32 ulPosition_Y,
                      IN const std::string &strOSDText,
                      INOUT const DSP_Picture_Mjpeg_S &stPicture);

    /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
    /**
    * ����OSD \n
    * @param [IN] ulPosition_X      X����
    * @param [IN] ulPosition_Y      Y����
    * @param [IN] strOSDText        OSD
    * @param [IN] lFontPixelSize    �����С
    * @param [IN][OUT] stPicture    ͼƬYUV
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 overlay(IN ULONG_32 ulPosition_X,
        IN ULONG_32 ulPosition_Y,
        IN const std::string &strOSDText,
        IN LONG_32 lFontPixelSize,
        INOUT const DSP_Picture_Mjpeg_S &stPicture,
        OUT  LONG_32 &lReserByte);
    /* END: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */

    /**
    * ����OSD \n
    * @param [IN] ulPosition_X      X����
    * @param [IN] ulPosition_Y      Y����
    * @param [IN] strOSDText        OSD
    * @param [IN][OUT] stPicture    ͼƬYUV
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 overlayTextPixel(IN ULONG_32 ulPosition_X,
                           IN ULONG_32 ulPosition_Y,
                           IN const std::string &strOSDText,
                           INOUT const DSP_Picture_Mjpeg_S &stPicture,
                           OUT LONG_32 &lReserByte);
    /**
    * ��ȡ��ǰOSD�ĸ߶ȣ��û�������һ����λ�� \n
    * @param [IN] ��
    * @return ��һ���е�λ����Ϣ���ٷֱȱ�ʾ
    * - ����������
    */
    ULONG_32 getOsdHeight();

    /**
    * �ͷ��ַ����ӹ����е���Դ \n
    * @return VOID,
    */
    VOID releaseOverlayText(VOID);

    /**
    * ���������OSD��Ϣ������д�ռ�ļ��� \n
    * @param [IN] pstTmsOsdInfo  �����OSD��Ϣ
    * @param [IN] ulImageWidth   ����ͼƬ�Ŀ��
    * @param [IN] ulImageHegiht  ����ͼƬ�ĸ߶�
    * @return VOID,
    */
    VOID calcOsdSize(const TMS_OSD_INFO_S *pstTmsOsdInfo,
                     ULONG_32 &ulImageWidth,
                     ULONG_32 &ulImageHegiht,
                     ULONG_32 &ulFontByteSizePerLine);
    
    ULONG_32 RGBToYUV420(IN RGB_POINT_S &stRGB, OUT YUV_POINT_S &stYUV);

	void  setYUV(YUV_POINT_S &stYUV);

    /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
    /* �Ƿ�ʹ��ʸ���ֿ� */
    bool m_bUseVector;
   /* END: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
private:

    /**
    * ��ȡ��ǰ�ַ���������Ϣ \n
    * @param [IN] lPosPexiel_X      X����
    * @param [IN] lPosPexiel_Y      Y����
    * @param [IN][OUT] stPicture    ͼƬYUV
    * @return VOID,
    */
    VOID overlayMatrix(IN LONG_32 lPosPexiel_X, IN LONG_32 lPosPexiel_Y, INOUT const DSP_Picture_Mjpeg_S &stPicture) ;

    /**
    * ��ȡ��ǰ�ַ���������Ϣ \n
    * @param [IN][OUT] stFontPointMatrix �ַ�����
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 getStringFontMatrix(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, LONG_32 &lReserByte);

/* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
#ifdef _USE_TRUETYPE_FONT
    /**
    * ��ȡ��ǰ�ַ���������Ϣ \n
    * @param [IN][OUT] stFontPointMatrix �ַ�����
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 getStringFontInfo(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, LONG_32 &lReserByte);

    /**
    * ��ѯ��ǰ�����ַ��ĵ�����Ϣ \n
    * @param [IN][OUT] stFontPointMatrix �ַ�����
    * @param [IN]wChar                   ��Ҫת�����ַ�
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 getFontByFT(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, wchar_t wChar, LONG_32 lIndex);

    /**
    * ��ȡ��ǰ�ַ���ʸ���ַ���Ϣ \n
    * @param [IN] lPosPexiel_X      X����
    * @param [IN] lPosPexiel_Y      Y����
    * @param [IN][OUT] stPicture    ͼƬYUV
    * @return VOID,
    */
    VOID overlayTrueType(IN LONG_32 lPosPexiel_X, IN LONG_32 lPosPexiel_Y, INOUT const DSP_Picture_Mjpeg_S &stPicture) ;
#endif
/* END: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */

    /**
    * ��ѯ��ǰ�����ַ��ĵ�����Ϣ \n
    * @param [IN][OUT] stFontPointMatrix �ַ�����
    * @param [IN]lTextIndex              ��Ҫת�����ַ��±�
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 getChineseFont(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, IN LONG_32 lTextIndex);

    /**
    * ���������assiic����Ϣ��ȡ��Ӧ�ĵ�����Ϣ \n
    * @param [IN][OUT] stFontPointMatrix �ַ�����
    * @param [IN]lTextIndex              ��Ҫת�����ַ��±�
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 getAsciiFont(IN OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, IN LONG_32 lTextIndex);

    /**
    * �Ե����ֿ����ת�� \n
    * @param [IN]      lPixelSize      ��С
    * @param [IN][OUT] pcFontPixelAddr �ַ�����
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 matrixInversion(IN LONG_32 lPixelSize, INOUT UCHAR *pcFontPixelAddr);

    /**
    * �����ֿ����͵õ��ֿ��ļ���� \n
    * @param [IN]      enHandleType    �ֿ�����
    * @return IMOS_HANDLE �ֿ��ļ����,
    */
    IMOS_HANDLE getFontHandleByType(IN OVERLAY_FONT_TYPE_E enHandleType);

    /**
    * ��ȡ���� \n
    * @param [IN]      enHandleType    �ֿ�����
    * @param [IN]      stOffset        ƫ��
    * @param [IN]      ulBuffLen       buffer��С
    * @param [IN][OUT] pucBuff         buffer
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - ����������
    */
    ULONG_32 readFont(IN OVERLAY_FONT_TYPE_E enHandleType,
                   IN IMOS_LOFF_S stOffset,
                   IN ULONG_32 ulBuffLen,
                   INOUT UCHAR *pucBuff);
public:
    /* ÿ�е��ӵ������ֽ��� */
    ULONG_32 m_ulFontByteSizeArry[50];
private:
    /* �����ַ��������ݽṹ�� */
    OSD_FONT_POINT_MATRIX_S m_stOsdFontPointMatrix;

    /* һ��OSDЯ���İٷֱ����� */
    ULONG_32       m_ulOsdHeigh;

    /* �ֿ��� */
    IMOS_HANDLE m_hHZK_24;
    IMOS_HANDLE m_hASC_24;
    IMOS_HANDLE m_hHZK_48;
    IMOS_HANDLE m_hASC_48;
/* BEGIN: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
    /* True Type�ֿ⼰�䳤�� */
    UCHAR       *m_aucTrueType;
    LONG_32        m_lTrueType_Size;
/* END: ADD by chenxiaoyan, 2013/12/16 for Υ��ͼƬ�ϳɵ�����Ϣ��Ƨ����ʾ����ȷ ���ⵥ��: MPPD06632 */
    /* Begin add for red font */
    YUV_POINT_S m_stYUV;
    /* End add for red font */
};


#endif

