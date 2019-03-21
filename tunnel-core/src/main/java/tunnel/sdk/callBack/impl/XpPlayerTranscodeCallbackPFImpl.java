package tunnel.sdk.callBack.impl;

import com.burst.websocket.TunnelMessageHandler;
import com.sun.jna.Pointer;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.BinaryMessage;
import tunnel.sdk.callBack.XpPlayerTranscodeCallbackPF;

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
     * @param ulPort
     * @param pucBuffer
     * @param ulBufSize
     * @param lUserParam
     * @param lReserved
     * @auther: 任琳珺
     * @参数 [IN] ulPort 播放通道号
     *      [IN] pucBuffer 转码后打包的数据指针
     *      [IN] ulBufSize 缓冲区大小
     *      [IN] lUserParam 用户设置参数，即用户在调用::IMOS_XP_SetTranscodeCB函数时指定的用户参数
     *      [IN] lReserved 预留参数
     * @返回 无。注解用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
     */
    @Override
    public void callBack(int ulPort,Pointer pucBuffer, int ulBufSize, long lUserParam, long lReserved) {
        //发送缓冲区中的数据
        ByteBuffer buffer = pucBuffer.getByteBuffer(0,ulBufSize);
        TunnelMessageHandler.sendAllConnectedClient(new BinaryMessage(buffer));
    }
}
