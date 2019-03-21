package tunnel.sdk.callBack;

import com.sun.jna.Pointer;
import com.sun.jna.win32.StdCallLibrary.StdCallCallback;

/**
 * @描述：
 * @作者: REN
 * @时间: 2019/1/5 16:07
 */
public interface CallBackProcPf extends StdCallCallback {
    /**
     *
     * :
     *     ulProcType CALL_BACK_PROC_TYPE_E(SDKDef.TagCallBackProcType)
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public void callback(int ulProcType, Pointer pParam);

}
