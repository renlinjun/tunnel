package tunnel.sdk.callBack;
import com.sun.jna.Pointer;
import com.sun.jna.win32.StdCallLibrary.StdCallCallback;



/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/19 16:59
 */
public interface XpPlayerTranscodeCallbackPF extends StdCallCallback {

    /**
     *
     * 功能描述: 转码回调函数的指针类型。
     * @auther: 任琳珺
     * @参数
         [IN] ulPort 播放通道号
         [IN] pucBuffer 转码后打包的数据指针
         [IN] ulBufSize 缓冲区大小
         [IN] lUserParam 用户设置参数，即用户在调用::IMOS_XP_SetTranscodeCB函数时指定的用户参数
         [IN] lReserved 预留参数
     * @返回
     *      无。注解用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
     */
    void callBack(int ulPort, Pointer pucBuffer, int ulBufSize, long lUserParam, long lReserved);

}
