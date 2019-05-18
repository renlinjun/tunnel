package com.burst.system.controller;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.RequestData;
import com.burst.cache.ResponseData;
import com.burst.exception.CustomException;
import com.burst.imos.ImosLogin;
import com.burst.system.service.ILoginService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

/**
 * @描述: IMOS平台协议登录相关操作
 * @作者: 任琳珺
 * @时间: 2019/3/20 16:44
 */
//@RestController
public class LoginController {

    @Autowired
    private ILoginService loginService;
    @Autowired
    private ImosLogin imosLogin;

    @RequestMapping(method = RequestMethod.POST,value = "/login")
    public ResponseData loginEx(@RequestBody RequestData requestData) {
        JSONObject data = requestData.getData();
        int result = loginService.login(data);
        return new ResponseData(result,"",null);
    }

    @RequestMapping(method = RequestMethod.POST,value = "/loginOut")
    public String loginOutEx() {
        try {
            imosLogin.loginOut();
        } catch (CustomException e) {
            e.printStackTrace();
        }
        return "";
    }

}
