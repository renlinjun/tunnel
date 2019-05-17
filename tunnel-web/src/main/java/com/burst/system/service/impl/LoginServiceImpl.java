package com.burst.system.service.impl;

import com.alibaba.fastjson.JSONObject;
import com.burst.exception.CustomException;
import com.burst.imos.ImosLogin;
import com.burst.system.service.ILoginService;
import com.bust.constants.ResultConstants;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.burst.sdk.constanst.IMOSErrCodeEnum;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/20 22:58
 */
//@Service
public class LoginServiceImpl implements ILoginService {

    @Autowired
    private ImosLogin imosLogin;

    public int login(JSONObject data) {
        String serverAdd = "192.168.1.16";
        String username = data.getString("username");
        String password = data.getString("password");
        try {
            int initResult = imosLogin.Initiate(serverAdd,8800);
            if(initResult== IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
                imosLogin.login(username,password,serverAdd,true);
            }
        } catch (CustomException e) {
            e.printStackTrace();
            return ResultConstants.LOGIN_CHECK_FAIL;
        }
        return ResultConstants.SUCCESS_CODE;
    }
}
