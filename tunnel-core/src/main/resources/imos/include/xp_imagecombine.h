/*******************************************************************************
Copyright (c) 2008-2013, Zhejiang Uniview Technology Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                            xp_imagecombine.h
Project Code: XP
Module Name:  MPM
Date Created: 2011-11-21
Author:       wangjiangzhu/06641
Description:  完成jpg图片的拼接与字符叠加操作
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

/** 编译选项 */
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

/* 函数调用错误码定义 */
#define   SUCCEED                    0         //函数调用成功
#define   ERR_INVALID_PARAMETER      1         //输入参数非法
#define   ERR_SYSTEM_MEMORY          2         //申请系统内存失败
#define   ERR_MEMORY_NOT_ENOUGH      3         //输入的内存不足
#define   ERR_NOT_BMP_PIC            4         //输入的图片不为BMP图片
#define   ERR_RGB2YUV_FAILED         5         //RGB转YUV图片失败

#define   ERR_CREATE_JEG_DECODERR    6         //创建Jpg解码器失败
#define   ERR_JPG_DECODE_PIC         7         //解码Jpg图片失败

#define   ERR_CREATE_RESAMPLE        8         //创建图片重采样句柄失败
#define   ERR_RESET_RESAMPLE_PAR     9         //设置重采样参数失败
#define   ERR_RESAMPLE_FAILED        10        //进行图片重采样失败

#define   ERR_CREATE_JPG_ENCODER     11        //jpe编码器创建失败
#define   ERR_JPG_ENCODE_PIC         12        //jpg编码失败

#define   ERR_PRE_DECODE_FAILEDD     13        //图片进行长宽预解码失败
#define   ERR_BMP_DECODE_PIC         14        //BMP解码失败
#define TMS_UV_MAX_VEHICLE_PIC_NUM   4         //最大图片数量

/* 图片拼接模式 */
typedef enum tagCombinePicMode
{
    /* Begin modify by WangJiangZhu for MPPD00488, 增加自适应与特写图片功能20130128 */
    COMBINE_PIC_MODE_NONE           = 0,     /*< 不指定渲染模式 */
    COMBINE_PIC_MODE_TOP1DOWN3      = 1,     /*< 3张图片，上1下3模式，上1和下左为同一张 */
    COMBINE_PIC_MODE_LEFT1RIGHT3    = 2,     /*< 3张图片，左1右3模式，左1和右上为同一张 */
    COMBINE_PIC_MODE_TOP1DOWN1      = 3,     /*< 2张图片，上1下1模式 */
    COMBINE_PIC_MODE_LEFT1RIGHT1    = 4,     /*< 2张图片，左1右1模式 */
    COMBINE_PIC_MODE_STOP2DOWN2     = 5,     /*< 3张图片，合成田字格，1在上左，2在上右，3在下左，第1张特写在下右 */
    COMBINE_PIC_MODE_TOP2DOWN2      = 6,     /*< 4张图片，合成田字格 */
    COMBINE_PIC_MODE_4STOP2DOWN2    = 7,     /*< 4张图片，合成田字格，2在上左，3在上右，4在下左，第1张特写在下右 */
    COMBINE_PIC_MODE_SLINEDISCARD   = 8,     /*< 2~4张图片，合成1字形，第1张提取特写图片，第1张原图丢弃 */
    COMBINE_PIC_MODE_SLINE          = 9,     /*< 1~3张图片，合成1字形，第1张提取特写图片，第1张原图不丢弃 */
    COMBINE_PIC_MODE_LINE           = 10,    /*< 2~4张图片，直接合成1字形 */
    COMBINE_PIC_MODE_ONE_PICTURE    = 11,    /*< 1张图片*/
    COMBINE_PIC_MODE_TOP3DOWN3      = 12,    /* 人脸电警6图合成 */
    COMBINE_PIC_MODE_TOP2DOWN2EX    = 13,    /* 人脸电警4图合成 */

    COMBINE_PIC_MODE_MAX,                    /*< 当前支持的渲染模式 */
    COMBINE_PIC_MODE_INVALID        = 0xFFFF /*< 无效值 */
    /* END modify by WangJiangZhu for MPPD00488, 增加自适应与特写图片功能 20130128*/
}COMBINE_PIC_MODE_E;


typedef enum tagOSDPlaceMode
{
	OSD_PLACE_MODE_TOP,
	OSD_PLACE_MODE_DOWN
}OSD_PLACE_MODE;

/* 图像信息 */
typedef struct tagSrcPictureInfo
{
    UCHAR *  pucSrcJpgPicture;
    ULONG_32    ulSrcJpgPictureSize;
}SRC_PICTURE_INFO_S;

/**
* @struct tagTMSOsdInfo
* @brief TMS OSD
* @attention 无
*/
typedef struct tagTMSOsdInfo
{
    /** 背景叠加OSD起始X坐标 */
    ULONG_32 ulOriginX;

    /** 背景叠加OSD起始Y坐标 */
    ULONG_32 ulOriginY;

    /** 背景颜色 */
    long  lbkcolor;

    /** 背景透明度 */
    long  lbkTransparence;

    /** OSD透明度 */
    long  lTransparence;

    /** 字体大小 */
    long  lSize;

    /** 字体颜色 */
    long  lColor;

    /** 字体 */
    char  szFont[15];

    /** OSD个数 */
    ULONG_32 ulOSDNum;

    /** OSD列表 */
    char  aszOSD[4][256];
}TMS_OSD_INFO_S;

#ifndef _H3C_VIDEO_MJPEG_H_
/**
* @struct tagPictureYUV420
* @brief 图像结构体定义
* @attention 无
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
* 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
* 字库使用点阵字库
* @param[in] pucSrcJpgPicture1      输入图片1起始地址
* @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
* @param[in] pucSrcJpgPicture2      输入图片2起始地址
* @param[in] ulSrcJpgPictureSize2 输入图片2的内存大小
* @param[in] pucSrcJpgPicture3      输入图片3起始地址
* @param[in] ulSrcJpgPictureSize3   输入图片3的内存大小
* @param[in] pstOsdInfo             OSD结构体信息
* @param[in] ulCombineMode          图像拼接模式，暂时不使用
* @param[out] pucDstJpgPicture      拼接后图片的内存
* @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
* @param[out] ulOSDPlaceMode     图像拼接OSD的位置
* @return 图像拼接操作是否成功
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSD(UCHAR * pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                         UCHAR * pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                         UCHAR * pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                         const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                         UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize, ULONG_32 ulOSDPlaceMode);

/**
* 将BMP图片转换为JPG图片.
* @param[in] pucBmpPicture       输入BMP图片
* @param[in] ulBmpPicture        输入BMP图片的大小
* @param[OUT] pucJpgPicture      输出的Jpg图片
* @param[OUT] pulJpgPictureSize输出的Jpg图片大小
* @return 图片转换是否成功
*/
IMAGE_COMBINE_EXPORT int  STDCALL bmp2Jpg(UCHAR * pucBmpPicture, ULONG_32 ulBmpPicture,
                                          UCHAR * pucJpgPicture, ULONG_32 *pulJpgPictureSize);

/**
* 从一张jpg图片中获取车牌特写图片
* @param[in] pucJpgPicture       输入Jpg图片
* @param[in] pulJpgPictureSize   输入Jpg图片的大小
* @param[OUT] pucPlateJpg        输出车牌Jpg图片
* @param[OUT] pulPlateJpgSize  输出车牌Jpg图片大小
* @return 扣取图片是否成功，如果输入jpg图片中不含有车牌位置等信息会扣取失败
*         非我司设备也会出现扣取图片失败
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL Jpg2PlateJpg(UCHAR * pucJpgPicture, ULONG_32 pulJpgPictureSize,
                                                   UCHAR * pucPlateJpg, ULONG_32 *pulPlateJpgSize);

/**
* 从一张jpg图片中获取车牌特写图片的位置
* @param[in] pucJpgPicture       输入Jpg图片
* @param[in] pulJpgPictureSize   输入Jpg图片的大小
* @param[OUT] aulPosition        输出车牌位置
* @return 查询结果
*         
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL findPlateFromPic(IN UCHAR * pucJpgPicture, IN ULONG_32 pulJpgPictureSize,
                                                   OUT LONG_32 alPosition[4]);

/**
* 对单张图片叠加OSD
* @param[in] pucSrcJpgPicture1      输入图片1起始地址
* @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
* @param[in] pstOsdInfo             OSD结构体信息
* @param[in] ulOSDPlaceMode         OSD位置
* @param[out] pucDstJpgPicture      拼接后图片的内存
* @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
* @return 图像拼接操作是否成功
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combineOnePictureWithOSD(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                            const TMS_OSD_INFO_S *pstOsdInfo, ULONG_32 ulOSDPlaceMode,
                                                            UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize);

#ifdef WIN32
/**
* 将BMP图片转换为JPG图片.
* @param[in]  YUV的图片结构体
* @param[OUT] pucJpgPicture      输出的Jpg图片
* @param[OUT] pulJpgPictureSize输出的Jpg图片大小
* @return 图片转换是否成功
*/
IMAGE_COMBINE_EXPORT int  STDCALL yuv2Jpg(DSP_Picture_Mjpeg_S * pstPictureYuv420,
                                          UCHAR * pucJpgPicture, ULONG_32 *pulJpgPictureSize);


/**
* 加密图片
* @param[in] pucSrcJpgPicture       待加密的JPG图片
* @param[in] ulSrcJpgPictureSize    待加密的JPG图片大小
* @param[out] pucDstJpgPicture      加密后的JPG图片
* @param[out] pulDstJpgPictureSize  加密后的JPG图片大小
* @return 加密是否成功
*/
IMAGE_COMBINE_EXPORT int  STDCALL encImgData(UCHAR *pucSrcJpgPicture,
                                             ULONG_32 ulSrcJpgPictureSize,
                                             UCHAR *pucDstJpgPicture,
                                             ULONG_32 *pulDstJpgPictureSize);

#endif

/**
* 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
* 字库使用点阵字库
* @param[in] pstSrcPictureInfo      原始图像
* @param[in] ulSrcPictureNum        原始图像数目
* @param[in] pstOsdInfo             OSD结构体信息
* @param[in] ulCombineMode          图像拼接模式，暂时不使用
* @param[in] ucAroundSidePixel     图片四周边宽度(像素为单位，只对4张图片田字形有效)
* @param[in] ucCenterSidePixel       图片中心边宽度(像素为单位，只对4张图片田字形有效)
* @param[out] pucDstJpgPicture      拼接后图片的内存
* @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
* @param[out] ulOSDPlaceMode     图像拼接OSD的位置
* @return 图像拼接操作是否成功
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDEx(SRC_PICTURE_INFO_S *pstSrcPictureInfo, ULONG_32 ulSrcPictureNum,
                                                           const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                           UCHAR ucAroundSidePixel, UCHAR ucCenterSidePixel,
                                                           UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode);


 /* BEGIN: added by ChenXiaoYan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号：MPPD06632 */
 /**
 * 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
 * 字库使用矢量字库,一定要设置字体大小
 * @param[in] pstSrcPictureInfo      原始图像
 * @param[in] ulSrcPictureNum        原始图像数目
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[in] ulCombineMode          图像拼接模式，暂时不使用
 * @param[in] ucAroundSidePixel     图片四周边宽度(像素为单位，只对4张图片田字形有效)
 * @param[in] ucCenterSidePixel       图片中心边宽度(像素为单位，只对4张图片田字形有效)
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @return 图像拼接操作是否成功
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDExUseVector(SRC_PICTURE_INFO_S *pstSrcPictureInfo, ULONG_32 ulSrcPictureNum,
                                                            const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                            UCHAR ucAroundSidePixel, UCHAR ucCenterSidePixel,
                                                            UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum);



 /**
 * 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
 * 字库使用矢量字库,一定要设置字体大小
 * @param[in] pucSrcJpgPicture1      输入图片1起始地址
 * @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
 * @param[in] pucSrcJpgPicture2      输入图片2起始地址
 * @param[in] ulSrcJpgPictureSize2 输入图片2的内存大小
 * @param[in] pucSrcJpgPicture3      输入图片3起始地址
 * @param[in] ulSrcJpgPictureSize3   输入图片3的内存大小
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[in] ulCombineMode          图像拼接模式，暂时不使用
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @return 图像拼接操作是否成功
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDUseVector(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                          UCHAR *pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                          UCHAR *pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                          const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                          UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum);


/**
 * 对单张图片叠加OSD 
 * 字库使用矢量字库,一定要设置字体大小
 * @param[in] pucSrcJpgPicture1      输入图片1起始地址
 * @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[in] ulOSDPlaceMode         OSD位置
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @return 图像拼接操作是否成功   lattice vector
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combineOnePictureWithOSDUseVector(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
     const TMS_OSD_INFO_S *pstOsdInfo, ULONG_32 ulOSDPlaceMode,
     UCHAR *pucDstJpgPicture, ULONG_32 *pulDstJpgPictureSize);
 /* END: added by ChenXiaoYan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号：MPPD06632 */


/**
*单张图像进行缩小 
* @param[in] pucSrcJpgPicture1             输入图片起始地址
* @param[in] ulSrcJpgPictureSize1          输入图片1的内存大小
* @param[in] ulFlexibleNum                 缩小系数（百分比1~100）
* @param[in] ucQuality   ：[入出]图片的压缩质量因子（1～10），1：最佳质量，10：最劣质量
* @param[in] pucDstJpgPicture              输出图片起始地址
* @param[in] pulDstJpgPictureSize          输出图片内存大小
*/
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL flexibleImage(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
													ULONG_32 ulFlexibleNum,  UCHAR ucQuality,
													UCHAR *pucDstJpgPicture, ULONG_32 *pulDstJpgPictureSize);

 /**
* 把电警上来的田字图和 卡口过来的图片合成3+3的模式
* @param[in] pstSrcPicInfo_1      输入图片1的存储结构
* @param[in] pstSrcPicInfo_2      输入图片2的存储结构
* @param[in] pstOsdInfo           OSD结构体信息(NULL表示不加OSD，反之则添加)
* @param[out] pstDstJpgPicture    拼接后图片的存储结构
* @return 图像拼接操作是否成功
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
 * 进行图片拼接
 * @param[in] pucSrcJpgPicture1      输入图片1起始地址
 * @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[in] ulCombineMode          图像拼接模式，暂时不使用
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @return 图像拼接操作是否成功
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureForSpecial(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
     const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
     UCHAR *pucDstJpgPicture,   ULONG_32 &ulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode);

  /**
 * 从一张jpg图片中获取车牌特写图片
 * @param[in] pucJpgPicture       输入Jpg图片
 * @param[in] pulJpgPictureSize   输入Jpg图片的大小
 * @param[in] ulTopX              车牌起始位置X坐标
 * @param[in] ulTopY              车牌起始位置Y坐标
 * @param[in] ulHeight            车牌区域高度
 * @param[in] ulWidth             车牌区域宽度
 * @param[OUT] pucPlateJpg        输出车牌Jpg图片
 * @param[OUT] pulPlateJpgSize  输出车牌Jpg图片大小
 * @return 扣取图片是否成功，如果输入jpg图片中不含有车牌位置等信息会扣取失败
 *         非我司设备也会出现扣取图片失败
 */
 IMAGE_COMBINE_EXPORT ULONG_32 STDCALL CutRectFromPic(IN UCHAR * pucJpgPicture, IN ULONG_32 pulJpgPictureSize,IN ULONG_32 ulTopX, IN ULONG_32 ulTopY,
                                                    IN ULONG_32 ulHeight,IN ULONG_32 ulWidth, OUT UCHAR * pucPlateJpg, OUT ULONG_32 *pulPlateJpgSize);
     
 /**
 * 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
 * 字库使用矢量字库
 * @param[in] pucSrcJpgPicture1      输入图片1起始地址
 * @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
 * @param[in] pucSrcJpgPicture2      输入图片2起始地址
 * @param[in] ulSrcJpgPictureSize2 输入图片2的内存大小
 * @param[in] pucSrcJpgPicture3      输入图片3起始地址
 * @param[in] ulSrcJpgPictureSize3   输入图片3的内存大小
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @param[in] ulOSDPlaceMode         OSD叠加位置
 * @return 图像拼接操作是否成功
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combine3VPictureWithOSD(UCHAR *pucSrcJpgPicture1, ULONG_32 ulSrcJpgPictureSize1,
                                                                  UCHAR *pucSrcJpgPicture2, ULONG_32 ulSrcJpgPictureSize2,
                                                                  UCHAR *pucSrcJpgPicture3, ULONG_32 ulSrcJpgPictureSize3,
                                                                  const TMS_OSD_INFO_S *pstOsdInfo, 
                                                                  UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize);
 /* BEGIN: ADD by chenxiaoyan, 2013/12/16 for 违法图片合成叠加信息生僻字显示不正确 问题单号: MPPD06632 */
 /**
 * 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
 * 字库使用矢量字库
 * @param[in] pstSrcPictureInfo      原始图像
 * @param[in] ulSrcPictureNum        原始图像数目
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[in] ulCombineMode          图像拼接模式，暂时不使用
 * @param[in] ucAroundSidePixel     图片四周边宽度(像素为单位，只对4张图片田字形有效)
 * @param[in] ucCenterSidePixel       图片中心边宽度(像素为单位，只对4张图片田字形有效)
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @return 图像拼接操作是否成功
 */
IMAGE_COMBINE_EXPORT ULONG_32 STDCALL combinePictureWithOSDExUseVectorWithLimitSize(SRC_PICTURE_INFO_S *pstSrcPictureInfo, ULONG_32 ulSrcPictureNum,
                                                                    const TMS_OSD_INFO_S *pstOsdInfo,  ULONG_32 ulCombineMode,
                                                                    UCHAR ucAroundSidePixel, UCHAR ucCenterSidePixel,
                                                                    UCHAR *pucDstJpgPicture,   ULONG_32 *pulDstJpgPictureSize,  ULONG_32 ulOSDPlaceMode,ULONG_32 ulOsdPicNum,ULONG_32 ulLimitSize);


/* 把电警上来的田字图和 卡口过来的图片合成3+3的模式
* @param[in] pstSrcPicInfo_1      输入图片1的存储结构
* @param[in] pstSrcPicInfo_2      输入图片2的存储结构
* @param[in] pstOsdInfo           OSD结构体信息(NULL表示不加OSD，反之则添加)
* @param[out] pstDstJpgPicture    拼接后图片的存储结构
* @return 图像拼接操作是否成功
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
 * 进行图片拼接，支持三张图片的拼接，内部进行自适应，当前ulCombineMode字段暂时没有使用.
 * 字库使用矢量字库
 * @param[in] pucSrcJpgPicture1      输入图片1起始地址
 * @param[in] ulSrcJpgPictureSize1   输入图片1的内存大小
 * @param[in] pucSrcJpgPicture2      输入图片2起始地址
 * @param[in] ulSrcJpgPictureSize2 输入图片2的内存大小
 * @param[in] pucSrcJpgPicture3      输入图片3起始地址
 * @param[in] ulSrcJpgPictureSize3   输入图片3的内存大小
 * @param[in] pstOsdInfo             OSD结构体信息
 * @param[in] ulCombineMode          图像拼接模式，暂时不使用
 * @param[out] pucDstJpgPicture      拼接后图片的内存
 * @param[out] pulDstJpgPictureSize  拼接后保存图片的内存大小
 * @return 图像拼接操作是否成功
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
