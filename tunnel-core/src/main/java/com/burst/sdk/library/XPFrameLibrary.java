package com.burst.sdk.library;

import com.burst.sdk.callBack.XpPlayerTranscodeCallbackPF;
import com.burst.sdk.struct.imos.TagUserLoginIDInfo;
import com.sun.jna.Library;
import com.sun.jna.Native;

import java.io.File;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/15 22:39
 */
public interface XPFrameLibrary extends Library {

    //String JNA_LIBRARY_NAME = "imos_sdk";
    String JNA_LIBRARY_NAME = "imos"+ File.separator+"redist"+File.separator+"xp_frame";
    //设置为false
    String result = System.setProperty("jna.protected","false");
    String debug = System.setProperty("jna.debug_load", "true");
    public static XPFrameLibrary INSTANCE = Native.load(XPFrameLibrary.JNA_LIBRARY_NAME, XPFrameLibrary.class);


    /**
     *
     * 功能描述:
     * 获取空闲的通道资源编码。
     * @auther:
     * @date:
     * @param:
     *   [in] pstUserLoginIDInfo    用户登录ID信息标识。
     *   [out] pcChannelCodel         播放通道编码。
     * @return 返回如下错误码：
     * -         #ERR_COMMON_SUCCEED                  成功
     * -         #ERR_COMMON_INVALID_PARAM            输入参数无效
     * @note 无。
     */
    int IMOS_GetChannelCode(TagUserLoginIDInfo.ByReference userLoginIdInfo, byte[] pcChannelCode);

    /**
     *
     * 功能描述:
     *      设置解码后视频流数据回调函数。
     * @auther: 任琳珺
     * @date: 2019-03-13
     * @param:
     *  [in] pstUserLoginIDInfo 用户登录ID信息标识。
     *  [in] pcChannelCode 播放通道编码。
     *  [in] pfnDecodeVideoDataCBFun 解码后视频流数据回调函数的指针。
     *  [in] bContinue 是否继续进行后面的视频显示操作。（1：是 0：否）
     *  [in] lUserParam 用户设置参数。
     * @return:
     */
    int IMOS_SetDecodeVideoDataCB  (TagUserLoginIDInfo.ByReference userLoginIdInfo,
                                    byte[]  pcChannelCode,
                                    XpPlayerTranscodeCallbackPF pfnDecodeVideoDataCBFun,
                                    int  bContinue,
                                    long  lUserParam
    );

    /**
     *
     * 功能描述: 启动图片播放功能。
     *
     * @auther:
     * @date:
     * @param:
     *      [in] pstUserLoginIDInfo 用户登录ID信息标识。
     *      [in] pcChannelCode 播放通道编码。
     * @return:
     */
    int IMOS_StartImage  (TagUserLoginIDInfo.ByReference userLoginIDInfo,
                          byte[]  pcChannelCode
    );

    /**
     *
     * 功能描述: 图片加载
     *
     * @auther: 任琳珺
     * @date:
     * @param:
     *          [in] pstUserLoginIDInfo 用户登录ID信息标识。
     *          [in] pcChannelCode 播放通道编码。
     *          [in] pcImageURL 图片URL信息
     * @return:
     */
    int IMOS_LoadImage(TagUserLoginIDInfo.ByReference userLoginIDInfo,
                       byte[] pcChannelCode,
                       byte[]  pcImageURL
    );
}
