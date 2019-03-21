package tunnel.imos.controller;

import com.alibaba.fastjson.JSONObject;
import com.tunnel.constants.ResultConstants;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;
import tunnel.common.RequestData;
import tunnel.common.ResponseData;
import tunnel.exception.CustomException;
import tunnel.imos.ImosLogin;
import tunnel.imos.service.ILoginService;
import tunnel.sdk.constanst.IMOSErrCodeEnum;

/**
 * @描述: IMOS平台协议登录相关操作
 * @作者: 任琳珺
 * @时间: 2019/3/20 16:44
 */
@RestController
public class LoginController {

    @Autowired
    public ILoginService loginService;

    @RequestMapping(method = RequestMethod.POST,value = "/login")
    public ResponseData loginEx(@RequestBody RequestData requestData) {
        JSONObject data = requestData.getData();
        int result = loginService.login(data);
        return new ResponseData(result,"",null);
    }

    @RequestMapping(method = RequestMethod.POST,value = "/loginOut")
    public String loginOutEx() {
        try {
            ImosLogin.loginOut();
        } catch (CustomException e) {
            e.printStackTrace();
        }
        return "";
    }

}
