package tunnel.sdk.callBack.impl;

import com.sun.jna.Pointer;
import org.springframework.stereotype.Component;
import tunnel.sdk.callBack.CallBackProcExPf;
import tunnel.sdk.callBack.CallBackProcPf;
import tunnel.sdk.struct.imos.TagUserLoginIDInfo;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/1/5 16:11
 */
@Component
public class CallBackProcPfImpl implements CallBackProcPf {

    @Override
    public void callback(int ulProcType, Pointer pParam) {
    }

}
