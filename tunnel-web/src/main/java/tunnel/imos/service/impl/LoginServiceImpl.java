package tunnel.imos.service.impl;

import com.alibaba.fastjson.JSONObject;
import com.tunnel.constants.ResultConstants;
import org.springframework.stereotype.Service;
import tunnel.exception.CustomException;
import tunnel.imos.ImosLogin;
import tunnel.imos.service.ILoginService;
import tunnel.sdk.constanst.IMOSErrCodeEnum;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/20 22:58
 */
@Service
public class LoginServiceImpl implements ILoginService {

    public int login(JSONObject data) {
        String serverAdd = "192.168.1.16";
        String username = data.getString("username");
        String password = data.getString("password");
        try {
            int initResult = ImosLogin.Initiate(serverAdd,8800);
            if(initResult== IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
                ImosLogin.login(username,password,serverAdd,true);
            }
        } catch (CustomException e) {
            e.printStackTrace();
            return ResultConstants.LOGIN_CHECK_FAIL;
        }
        return ResultConstants.SUCCESS_CODE;
    }
}
