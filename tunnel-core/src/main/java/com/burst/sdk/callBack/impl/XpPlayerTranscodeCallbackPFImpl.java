package com.burst.sdk.callBack.impl;

import com.burst.websocket.TunnelMessageHandler;
import com.sun.jna.Pointer;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.BinaryMessage;
import com.burst.sdk.callBack.XpPlayerTranscodeCallbackPF;
import com.burst.sdk.struct.imos.TagParseVideoData;
import com.burst.sdk.struct.imos.TagPictureData;
import com.burst.sdk.struct.imos.TagUserLoginIDInfo;

import java.nio.ByteBuffer;


/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/19 18:42
 */
@Component
public class XpPlayerTranscodeCallbackPFImpl implements XpPlayerTranscodeCallbackPF {

    /**
     * 功能描述: 转码回调函数的指针类型。
     *
     * @param userLoginIDInfo
     * @param pcChannelCode
     * @param pucBuffer
     * @param lUserParam
     * @param lReserved
     * @auther: 任琳珺
     * @参数 [in] userLoginIDInfo 用户登录ID信息标识。
     *      [in] pcChannelCode 播放通道编码。
     *      [in] pstParseAudioData 存放拼帧后音频流数据信息缓冲区指针
     *      [in] lUserParam 用户设置参数，用户在调用::IMOS_SetParseAudioDataCB函数时指定的用户参数
     *      [in] lReserved 保留参数

     * @返回 无。注解用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
     */
    @Override
    public void callBack(TagUserLoginIDInfo.ByReference userLoginIDInfo,byte[] pcChannelCode, TagParseVideoData.ByReference pucBuffer, long lUserParam, long lReserved) {
        byte[] data = pucBuffer.pucData;
        //发送缓冲区中的数据
        /*
        TagParseVideoData tagPictureData = new TagParseVideoData(pucBuffer);
        ByteBuffer buffer = pucBuffer.getByteBuffer(0,ulBufSize);
        TunnelMessageHandler.sendTextMessage2Client(new BinaryMessage(buffer));
        */
    }
}
