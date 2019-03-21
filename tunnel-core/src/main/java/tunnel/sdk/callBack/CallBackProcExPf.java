package tunnel.sdk.callBack;

import com.sun.jna.Pointer;
import com.sun.jna.win32.StdCallLibrary.StdCallCallback;
import tunnel.sdk.struct.imos.TagUserLoginIDInfo;

import java.io.IOException;

/**
 * @描述： 消息处理回调函数
 * @作者:
 * @时间: 2019/1/5 16:07
 */
public interface  CallBackProcExPf extends StdCallCallback {
    /**
     *
     *
     *     ulProcType CALL_BACK_PROC_TYPE_E(SDKDef.TagCallBackProcType)
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public void callback(TagUserLoginIDInfo.ByReference userLoginIDInfo,int ulProcType, Pointer pParam) throws IOException;

}
