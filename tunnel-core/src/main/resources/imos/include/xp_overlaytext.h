/*******************************************************************************
 Copyright (c) 2008-2013, Zhejiang Uniview Technology Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                             xp_overlaytext.h
  Project Code: XP
   Module Name: MPM
  Date Created: 2011-11-05
        Author: wangjiangzhu/06641
   Description: 图片合成后OSD信息叠加

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/

#ifndef _XP_OVERLAY_TEXT_H_
#define _XP_OVERLAY_TEXT_H_

#include "xp_imagecombine.h"
 /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
#ifdef _USE_TRUETYPE_FONT
#include "ft2build.h"
#include FT_FREETYPE_H
#endif
 /* END: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
#define  MAX_OSD_SIZE    512
#define  MAX_FONT_MATRIX 48

/**
* @enum tagOverlayHandleType
* @brief 字库句柄类型定义
* @attention 无
*/
typedef enum tagOverlayHandleType
{
    OVERLAY_FONT_TYPE_HZK_24,
    OVERLAY_FONT_TYPE_ASC_24,
    OVERLAY_FONT_TYPE_HZK_48,
    OVERLAY_FONT_TYPE_ASC_48,
    OVERLAY_FONT_TYPE_INVALID
}OVERLAY_FONT_TYPE_E;

/* 字符点阵结构体 */
typedef struct tagOsdFontPointMatrix
{
    UCHAR    szOsdText[MAX_OSD_SIZE]; /* 当前字符点阵的最大长度 */
    LONG_32     lOsdTextLen;            /* 当前需要叠加的字符串长度 */
    UCHAR    *pucPointBeginAddr;      /* 点阵起始地址 */
    UCHAR    *pucPointCurAddr;        /* 点阵当前地址 */
    LONG_32     lOneFontSizeBytes;       /* 每个汉字的字节数 */
    LONG_32     lOneFontPixelSize;       /* 字库点阵大小 */
}OSD_FONT_POINT_MATRIX_S;

/* RGB颜色信息 */
typedef struct tagRGB
{
    UCHAR ucR;
    UCHAR ucG;
    UCHAR ucB;
}RGB_POINT_S;

/* YUV颜色信息 */
typedef struct tagYUV
{
    UCHAR ucY;
    UCHAR ucU;
    UCHAR ucV;
}YUV_POINT_S;

/* 字库信息字符串定义 */
#define  HZK_24_FILE   "Hzk24.dat"
#define  ASC_24_FILE   "Asc24.dat"
#define  HZK_48_FILE   "Hzk48s.dat"
#define  ASC_48_FILE   "Asc48.dat"
 /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
#define  TRUETYPE_FILE   "simsun.ttc"
 /* END: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
/* 根据图片的像素选择需要叠加的OSD点阵大小 */
#define  PICTURE_D1_HEIGHT   576
#define PICTURE_D1_WIDTH     720
#define  PICTURE_720_HEIGHT  720

/* 进行字符叠加类 */
class COverlayText
{
public:
    /**
    * 构造函数 \n
    */
    COverlayText(VOID);

    /**
    * 析构函数 \n
    */
    ~COverlayText(VOID);
public:

    /**
    * 初始化图像拼接需要的资源 \n
    */
    ULONG_32 initOverlayText(VOID);

    /**
    * 叠加OSD \n
    * @param [IN] ulPosition_X      X坐标
    * @param [IN] ulPosition_Y      Y坐标
    * @param [IN] strOSDText        OSD
    * @param [IN][OUT] stPicture    图片YUV
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 overlayText(IN ULONG_32 ulPosition_X,
                      IN ULONG_32 ulPosition_Y,
                      IN const std::string &strOSDText,
                      INOUT const DSP_Picture_Mjpeg_S &stPicture);

    /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
    /**
    * 叠加OSD \n
    * @param [IN] ulPosition_X      X坐标
    * @param [IN] ulPosition_Y      Y坐标
    * @param [IN] strOSDText        OSD
    * @param [IN] lFontPixelSize    字体大小
    * @param [IN][OUT] stPicture    图片YUV
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 overlay(IN ULONG_32 ulPosition_X,
        IN ULONG_32 ulPosition_Y,
        IN const std::string &strOSDText,
        IN LONG_32 lFontPixelSize,
        INOUT const DSP_Picture_Mjpeg_S &stPicture,
        OUT  LONG_32 &lReserByte);
    /* END: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */

    /**
    * 叠加OSD \n
    * @param [IN] ulPosition_X      X坐标
    * @param [IN] ulPosition_Y      Y坐标
    * @param [IN] strOSDText        OSD
    * @param [IN][OUT] stPicture    图片YUV
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 overlayTextPixel(IN ULONG_32 ulPosition_X,
                           IN ULONG_32 ulPosition_Y,
                           IN const std::string &strOSDText,
                           INOUT const DSP_Picture_Mjpeg_S &stPicture,
                           OUT LONG_32 &lReserByte);
    /**
    * 获取当前OSD的高度，用户计算下一个行位置 \n
    * @param [IN] 无
    * @return 下一个行的位置信息，百分比表示
    * - 其他错误码
    */
    ULONG_32 getOsdHeight();

    /**
    * 释放字符叠加过程中的资源 \n
    * @return VOID,
    */
    VOID releaseOverlayText(VOID);

    /**
    * 根据输入的OSD信息进行填写空间的计算 \n
    * @param [IN] pstTmsOsdInfo  输入的OSD信息
    * @param [IN] ulImageWidth   输入图片的宽度
    * @param [IN] ulImageHegiht  输入图片的高度
    * @return VOID,
    */
    VOID calcOsdSize(const TMS_OSD_INFO_S *pstTmsOsdInfo,
                     ULONG_32 &ulImageWidth,
                     ULONG_32 &ulImageHegiht,
                     ULONG_32 &ulFontByteSizePerLine);
    
    ULONG_32 RGBToYUV420(IN RGB_POINT_S &stRGB, OUT YUV_POINT_S &stYUV);

	void  setYUV(YUV_POINT_S &stYUV);

    /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
    /* 是否使用矢量字库 */
    bool m_bUseVector;
   /* END: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
private:

    /**
    * 获取当前字符串点阵信息 \n
    * @param [IN] lPosPexiel_X      X坐标
    * @param [IN] lPosPexiel_Y      Y坐标
    * @param [IN][OUT] stPicture    图片YUV
    * @return VOID,
    */
    VOID overlayMatrix(IN LONG_32 lPosPexiel_X, IN LONG_32 lPosPexiel_Y, INOUT const DSP_Picture_Mjpeg_S &stPicture) ;

    /**
    * 获取当前字符串点阵信息 \n
    * @param [IN][OUT] stFontPointMatrix 字符点阵
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 getStringFontMatrix(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, LONG_32 &lReserByte);

/* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
#ifdef _USE_TRUETYPE_FONT
    /**
    * 获取当前字符串文字信息 \n
    * @param [IN][OUT] stFontPointMatrix 字符点阵
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 getStringFontInfo(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, LONG_32 &lReserByte);

    /**
    * 查询当前中文字符的点阵信息 \n
    * @param [IN][OUT] stFontPointMatrix 字符点阵
    * @param [IN]wChar                   需要转换的字符
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 getFontByFT(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, wchar_t wChar, LONG_32 lIndex);

    /**
    * 获取当前字符串矢量字符信息 \n
    * @param [IN] lPosPexiel_X      X坐标
    * @param [IN] lPosPexiel_Y      Y坐标
    * @param [IN][OUT] stPicture    图片YUV
    * @return VOID,
    */
    VOID overlayTrueType(IN LONG_32 lPosPexiel_X, IN LONG_32 lPosPexiel_Y, INOUT const DSP_Picture_Mjpeg_S &stPicture) ;
#endif
/* END: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */

    /**
    * 查询当前中文字符的点阵信息 \n
    * @param [IN][OUT] stFontPointMatrix 字符点阵
    * @param [IN]lTextIndex              需要转换的字符下标
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 getChineseFont(INOUT OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, IN LONG_32 lTextIndex);

    /**
    * 根据输入的assiic码信息获取响应的点阵信息 \n
    * @param [IN][OUT] stFontPointMatrix 字符点阵
    * @param [IN]lTextIndex              需要转换的字符下标
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 getAsciiFont(IN OSD_FONT_POINT_MATRIX_S &stFontPointMatrix, IN LONG_32 lTextIndex);

    /**
    * 对点阵字库进行转置 \n
    * @param [IN]      lPixelSize      大小
    * @param [IN][OUT] pcFontPixelAddr 字符点阵
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 matrixInversion(IN LONG_32 lPixelSize, INOUT UCHAR *pcFontPixelAddr);

    /**
    * 根据字库类型得到字库文件句柄 \n
    * @param [IN]      enHandleType    字库类型
    * @return IMOS_HANDLE 字库文件句柄,
    */
    IMOS_HANDLE getFontHandleByType(IN OVERLAY_FONT_TYPE_E enHandleType);

    /**
    * 读取字体 \n
    * @param [IN]      enHandleType    字库类型
    * @param [IN]      stOffset        偏移
    * @param [IN]      ulBuffLen       buffer大小
    * @param [IN][OUT] pucBuff         buffer
    * @return ULONG,
    * - ERR_COMMON_SUCCEED
    * - 其他错误码
    */
    ULONG_32 readFont(IN OVERLAY_FONT_TYPE_E enHandleType,
                   IN IMOS_LOFF_S stOffset,
                   IN ULONG_32 ulBuffLen,
                   INOUT UCHAR *pucBuff);
public:
    /* 每行叠加的文字字节数 */
    ULONG_32 m_ulFontByteSizeArry[50];
private:
    /* 保存字符点阵数据结构体 */
    OSD_FONT_POINT_MATRIX_S m_stOsdFontPointMatrix;

    /* 一行OSD携带的百分比像素 */
    ULONG_32       m_ulOsdHeigh;

    /* 字库句柄 */
    IMOS_HANDLE m_hHZK_24;
    IMOS_HANDLE m_hASC_24;
    IMOS_HANDLE m_hHZK_48;
    IMOS_HANDLE m_hASC_48;
/* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
    /* True Type字库及其长度 */
    UCHAR       *m_aucTrueType;
    LONG_32        m_lTrueType_Size;
/* END: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
    /* Begin add for red font */
    YUV_POINT_S m_stYUV;
    /* End add for red font */
};


#endif

