/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              mw_ptzlib_pub.h
  Project Code: IMOS
   Module Name: PTZ_LIB
  Date Created: 2009-3-25
        Author: 李树析/05305
   Description:云台通用库头对外文件
   Caution:      云台协议由于使用了全局变量，不能用于多线程环境
--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/

#ifndef _MW_PTZLIB_PUB_H_
#define _MW_PTZLIB_PUB_H_

#ifdef  __cplusplus
extern "C"{
#endif
/* 编译选项 */
#if defined(WIN32)
    #if defined(MW_PTZLIB_EXPORTS_DLL)
        #define MW_PTZLIB_EXPORT  __declspec( dllexport )
    #else
        #define MW_PTZLIB_EXPORT  __declspec( dllimport )
    #endif
#else
    #define MW_PTZLIB_EXPORT
#endif
#define MW_PTZ_CMD_LEN 1024 /**< 云台协议命令字最大长度 */
#define MW_PTZLIB_NAME_LEN 20 /**< 云台协议名称最大长度，加上了后缀名的长度4 */
#define MW_PTZ_FACTORY_PATH_LEN 128 /**< 云台协议目录长度*/
#define MW_PTZ_KEY_DES_LEN 64 /**<云台操作描述长度 */


/*定义云台库错误码
由于云台库可供CC和MW两者使用，
所以使用内部错误码方式
无需单独申请错误码*/
#define ERR_PTZLIB_SUCCESS 0UL   /**<  云台库返回成功*/
#define ERR_PTZLIB_GENERAL 1UL /**<  云台库通用错误 主要是参数不合法、
                                                        文件无法打开、分配内存失败等*/
#define ERR_PTZLIB_FACTORY_NOTEXIST 2UL  /**<  云台模板不存在 */
#define ERR_PTZLIB_CMD_NOTSUPPORT 3UL  /**<  云台命令不支持 */
#define ERR_PTZLIB_FACTORY_INVALID 4UL  /**<  云台模板不合法*/
/* Begin Added by l05305, 2009-7-3 of VVD29490 */
#define   MW_PTZ_SPEEDSET 0xffffffff
/* End   Added by l05305, 2009-7-3 of VVD29490 */

/**
* @enum  tagMwPtzCmdEnum
* @brief 云台控制命令枚举
* @attention
*/
typedef enum tagMwPtzCmdEnum
{
    MW_PTZ_IRISCLOSESTOP        = 0x0101,       /**< 光圈关停止 */
    MW_PTZ_IRISCLOSE            = 0x0102,       /**< 光圈关 */
    MW_PTZ_IRISOPENSTOP         = 0x0103,       /**< 光圈开停止 */
    MW_PTZ_IRISOPEN             = 0x0104,       /**< 光圈开 */

    MW_PTZ_FOCUSNEARSTOP        = 0x0201,       /**< 近聚集停止 */
    MW_PTZ_FOCUSNEAR            = 0x0202,       /**< 近聚集 */
    MW_PTZ_FOCUSFARSTOP         = 0x0203,       /**< 远聚集 停止*/
    MW_PTZ_FOCUSFAR             = 0x0204,       /**< 远聚集 */

    MW_PTZ_ZOOMTELESTOP         = 0x0301,       /**< 放大停止 */
    MW_PTZ_ZOOMTELE             = 0x0302,       /**< 放大 */
    MW_PTZ_ZOOMWIDESTOP         = 0x0303,       /**< 缩小停止 */
    MW_PTZ_ZOOMWIDE             = 0x0304,       /**< 缩小 */

    MW_PTZ_TILTUPSTOP           = 0x0401,       /**< 向上停止 */
    MW_PTZ_TILTUP               = 0x0402,       /**< 向上 */
    MW_PTZ_TILTDOWNSTOP         = 0x0403,       /**< 向下停止 */
    MW_PTZ_TILTDOWN             = 0x0404,       /**< 向下 */

    MW_PTZ_PANRIGHTSTOP         = 0x0501,       /**< 向右停止 */
    MW_PTZ_PANRIGHT             = 0x0502,       /**< 向右 */
    MW_PTZ_PANLEFTSTOP          = 0x0503,       /**< 向左停止 */
    MW_PTZ_PANLEFT              = 0x0504,       /**< 向左 */

    MW_PTZ_PRESAVE              = 0x0601,       /**< 预置位保存 */
    MW_PTZ_PRECALL              = 0x0602,       /**< 预置位调用 */
    MW_PTZ_PREDEL               = 0x0603,       /**< 预置位删除 */

    MW_PTZ_LEFTUPSTOP           = 0x0701,       /**< 左上停止 */
    MW_PTZ_LEFTUP               = 0x0702,       /**< 左上 */
    MW_PTZ_LEFTDOWNSTOP         = 0x0703,       /**< 左下停止 */
    MW_PTZ_LEFTDOWN             = 0x0704,       /**< 左下 */

    MW_PTZ_RIGHTUPSTOP          = 0x0801,       /**< 右上停止 */
    MW_PTZ_RIGHTUP              = 0x0802,       /**< 右上 */
    MW_PTZ_RIGHTDOWNSTOP        = 0x0803,       /**< 右下停止 */
    MW_PTZ_RIGHTDOWN            = 0x0804,       /**< 右下 */

    MW_PTZ_ALLSTOP              = 0x0901,       /**< 全停命令字 */
    /* Begin Add By hexiaojun/h02450 for onvif摄像机设置云台绝对位置 */
    MW_PTZ_ABSOLUTE_MOVE        = 0x0902,       /**< 云台绝对移动 */
    /* End Add By hexiaojun/h02450 for onvif摄像机设置云台绝对位置 */

    MW_PTZ_BRUSHON              = 0x0A01,       /**< 雨刷开 */
    MW_PTZ_BRUSHOFF             = 0x0A02,       /**< 雨刷关 */

    MW_PTZ_LIGHTON              = 0x0B01,       /**< 灯开 */
    MW_PTZ_LIGHTOFF             = 0x0B02,       /**< 灯关 */

    MW_PTZ_HEATON               = 0x0C01,       /**< 加热开 */
    MW_PTZ_HEATOFF              = 0x0C02,       /**< 加热关 */

    MW_PTZ_INFRAREDON           = 0x0D01,       /**< 红外开 */
    MW_PTZ_INFRAREDOFF          = 0x0D02,       /**< 红外关 */

    MW_PTZ_SCANCRUISE           = 0x0E01,       /**< 云台线性扫猫 */
    MW_PTZ_SCANCRUISESTOP       = 0x0E02,       /**< 云台线性扫猫 */

    MW_PTZ_TRACKCRUISE          = 0x0F01,       /**<  云台轨迹巡航 */
    MW_PTZ_TRACKCRUISESTOP      = 0x0F02,       /**<  云台轨迹巡航 */

    MW_PTZ_PRESETCRUISE         = 0x1001,       /**<  云台按预置位巡航 ，该命令字不在云台模板体现 */
    MW_PTZ_PRESETCRUISESTOP     = 0x1002,       /**<  云台按预置位巡航 停止，该命令字不在云台模板体现 */

    /* Begin: Added by zhongke z01354, 2014-06-13 for 国标修订二期 */
    MW_PTZ_ADD_CRUISE_POINT     = 0x1003,       /* 云台添加轨迹巡航点 */
    MW_PTZ_DEL_CRUISE_POINT     = 0x1004,       /* 云台删除轨迹巡航点 */

    MW_PTZ_SET_CRUISE_SPEED     = 0x1005,       /* 设置云台巡航速度   */
    MW_PTZ_SET_CRUISE_STAY_TIME = 0x1006,       /* 设置云台巡航停留时间 */
    /* End: Added by zhongke z01354, 2014-06-13 for 国标修订二期 */

    MW_PTZ_GBSTARTCRUISE        = 0x1007,       /* 国标开始巡航 */

    /* Begin: Added by t07041 20110117, 拉框放大特性 */
    MW_PTZ_AREAZOOMIN           = 0x1101,       /**<  拉框放大 */
    MW_PTZ_AREAZOOMOUT          = 0x1102,       /**<  拉框缩小 */
    /* End: Added by t07041 20110117, 拉框放大特性 */

    /* Begin added by z00758,2013-05-28 for JilinDianli */
    MW_PTZ_ABSPOSITION              = 0x0902,     /**< 设置摄像机绝对角度 */
    /* End added by z00758,2013-05-28 for JilinDianli */

    MW_PTZ_UPTELESTOP=0x0411,/**< 向上放大停止 */
    MW_PTZ_UPTELE=0x0412,/**< 向上放大 */
    MW_PTZ_DOWNTELESTOP=0x0413,/**< 向下放大停止 */
    MW_PTZ_DOWNTELE=0x0414,/**< 向下放大 */

    MW_PTZ_UPWIDESTOP=0x0421,/**< 向上缩小停止 */
    MW_PTZ_UPWIDE=0x0422,/**< 向上缩小 */
    MW_PTZ_DOWNWIDESTOP=0x0423,/**< 向下缩小停止 */
    MW_PTZ_DOWNWIDE=0x0424,/**< 向下缩小 */

    MW_PTZ_RIGHTTELESTOP=0x0511,/**< 向右放大停止 */
    MW_PTZ_RIGHTTELE=0x0512,/**< 向右放大 */
    MW_PTZ_LEFTTELESTOP=0x0513,/**< 向左放大停止 */
    MW_PTZ_LEFTTELE=0x0514,/**< 向左放大 */

    MW_PTZ_RIGHTWIDESTOP=0x0521,/**< 向右缩小停止 */
    MW_PTZ_RIGHTWIDE=0x0522,/**< 向右缩小 */
    MW_PTZ_LEFTWIDESTOP=0x0523,/**< 向左缩小停止 */
    MW_PTZ_LEFTWIDE=0x0524,/**< 向左缩小 */

    MW_PTZ_LEFTUPTELESTOP=0x0711,/**< 左上放大停止 */
    MW_PTZ_LEFTUPTELE=0x0712,/**< 左上放大 */
    MW_PTZ_LEFTDOWNTELESTOP=0x0713,/**< 左下放大停止 */
    MW_PTZ_LEFTDOWNTELE=0x0714,/**< 左下放大 */

    MW_PTZ_LEFTUPWIDESTOP=0x0721,/**< 左上缩小停止 */
    MW_PTZ_LEFTUPWIDE=0x0722,/**< 左上缩小 */
    MW_PTZ_LEFTDOWNWIDESTOP=0x0723,/**< 左下缩小停止 */
    MW_PTZ_LEFTDOWNWIDE=0x0724,/**< 左下缩小 */

    MW_PTZ_RIGHTUPTELESTOP=0x0811,/**< 右上放大停止 */
    MW_PTZ_RIGHTUPTELE=0x0812,/**< 右上放大 */
    MW_PTZ_RIGHTDOWNTELESTOP=0x0813,/**< 右下放大停止 */
    MW_PTZ_RIGHTDOWNTELE=0x0814,/**< 右下放大 */

    MW_PTZ_RIGHTUPWIDESTOP=0x0821,/**< 右上缩小停止 */
    MW_PTZ_RIGHTUPWIDE=0x0822,/**< 右上缩小 */
    MW_PTZ_RIGHTDOWNWIDESTOP=0x0823,/**< 右下缩小停止 */
    MW_PTZ_RIGHTDOWNWIDE=0x0824,/**< 右下缩小 */

    MW_PTZ_RELEASEPTZCTRL = 0x1201,     /*Added by yuanyan 2014-10-13 for MPPD14565 UV-1键盘释放云台控制*/

    /* Begin: Modified by 01354 zhongke, 2014-04-30 for MPPD11293 */
    MW_PTZ_CONTINUOUSTRACKCRUISESTOP = 0x1401,
    /* End: Modified by 01354 zhongke, 2014-04-30 for MPPD11293 */

	MW_PTZ_IRMODE   = 0x1301,   			/* 设置红外灯模式 */
	MW_PTZ_IRSETBRIGHT     =  0x1302,    /* 设置红外灯亮度 */



    MW_PTZ_CMD_BUTT
}MW_PTZ_CMD_E;

/* Begin Added by c00291, 2013-4-28 */
/* method和描述 */
typedef struct tagPTZKey
{
    ULONG_32   ulCmdID;
    CHAR    szDsb[MW_PTZ_KEY_DES_LEN];
}PTZ_KEY_S;
/* End   Added by c00291, 2013-4-28 of log_audit */
/**
* @struct  tagMwPtzCmdBuffer
* @brief 云台控制指令buffer和发送参数
* @attention
 */
typedef struct tagMwPtzCmdBuffer
{
    ULONG_32 ulCmdLen;  /**<  命令长度，每个命令一个长度，解决可变命令存在的问题 */
    ULONG_32 ulCmdIntervalDelay;     /**<   由于某些协议需要一个命令间隔一段时间再次发送  单位是毫秒返回0的话不需要间隔*/
    ULONG_32 ulCmdSendTimes;     /**<   由于某些协议需要重复多次发送，该项用来标识发送多少次，默认是1*/
    UCHAR ucCmdBuf[MW_PTZ_CMD_LEN];/**<  命令字Buffer*/
    /* Begin Added by l05305, 2009-7-3 of VVD29490 */
    BOOL_T bIsSupportSpeedSet;/* 是否支持速度设置 */
    /* End   Added by l05305, 2009-7-3 of VVD29490 */
}MW_PTZ_CMD_BUF_S;

/**
* @struct  tagMwPtzOperation
* @brief 云台控制指令参数
* @attention
 */
typedef struct tagMwPtzOperation
{
    MW_PTZ_CMD_E enCmdType;     /**< 云台命令类型 */
    ULONG_32 ulCmdParam1;           /**< 参数1 具体如何填写参考文档 */
    ULONG_32 ulCmdParam2;           /**< 参数2 具体如何填写参考文档 */
    ULONG_32 ulCmdParam3;           /**< 参数3 具体如何填写参考文档 */
}MW_PTZ_OPER_S;


/** @defgroup groupPtzInit 云台相关操作的接口
*   该模块提供云台库的初始化、清除以及相关操作的接口，详细的调用依赖关系请参见SDK说明文档。
*   @{
*/
/**
* 云台库初始化函数，初始化指定目录下的所有云台协议
任何使用该库的模块都必须首先初始化\n
* @param [IN] CHAR *pcFactoryPath       云台协议路径
* @return 返回如下结果:
* - 成功:
* - #ERR_PTZLIB_SUCCESS
* - 失败:
* - #ERR_PTZLIB_GENERAL
* @note 扫描目录只会扫描后缀是.ini的文件，
              这意味着协议名称必须是ini后缀
*/
MW_PTZLIB_EXPORT ULONG_32 MW_PTZLIB_Init(IN CHAR *pcFactoryPath);

/**
* 云台库销毁函数\n
* @param 无
* @return 该函数无返回值
* @note
*/
MW_PTZLIB_EXPORT VOID MW_PTZLIB_Destroy(VOID);

/**
* 云台安装某个云台协议模板\n
* @param [IN] CHAR *pcFactoryName       云台模板名称
* @param [IN] CHAR *pcFilePathName       云台协议路径
* @return 返回如下结果
* - 成功:
* - #ERR_PTZLIB_SUCCESS
* - 失败:
* - #ERR_PTZLIB_FACTORY_INVALID
* - #ERR_PTZLIB_GENERAL
* @note
*/
MW_PTZLIB_EXPORT ULONG_32 MW_PTZLIB_InstallProtocolFactory(IN CHAR *pcFactoryName, IN CHAR *pcFilePathName);


/**
* 根据云台协议，地址码和操作类型得到云台buffer\n
* @param [IN] CHAR *pcFactoryName     云台协议名称
* @param [IN] MW_PTZ_OPER_S *pstPtzOperation     云台操作参数
* @param [IN] ULONG ulPtzAddr     云台地址码
* @param [OUT] MW_PTZ_CMD_BUF_S *pstCmdBuf     云台命令字buffer
* @return 返回如下结果
* - 成功:
* - #ERR_PTZLIB_SUCCESS
* - 失败:
* - #ERR_PTZLIB_FACTORY_NOTEXIST
* - #ERR_PTZLIB_CMD_NOTSUPPORT
* - #ERR_PTZLIB_GENERAL
* @note
*/

MW_PTZLIB_EXPORT ULONG_32 MW_PTZLIB_GetPtzCmdBuffer
(
    IN CHAR *pcFactoryName,
    IN MW_PTZ_OPER_S *pstPtzOperation,
    IN ULONG_32 ulPtzAddr,
    OUT MW_PTZ_CMD_BUF_S *pstCmdBuf
);

/**
* 调试函数，详细显示当前支持的所有云台协议\n
* @param [IN] VOID
* @return 该函数无返回值
* @note
*/
MW_PTZLIB_EXPORT VOID MW_PTZLIB_DumpAllPtzFactory(VOID);


/**
* 检测云台协议是否存在 \n
* @param [IN] CHAR *pcFactoryName       云台协议名称
* @return 返回如下结果:
* - 成功:
* - #BOOL_TRUE
* - 失败:
* - #BOOL_FALSE
* @note
*/
MW_PTZLIB_EXPORT BOOL_T MW_PTZLIB_CheckPtzTemplateExist(IN CHAR *pcFactoryName);

/** @} */ /* end of ptz Module */

#ifdef  __cplusplus
}
#endif


#endif  /* end of _MW_PTZLIB_PUB_H_  */

