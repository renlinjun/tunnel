package com.burst.imos.controller;

import com.alibaba.fastjson.JSONObject;
import com.burst.common.RequestData;
import com.burst.common.ResponseData;
import com.burst.tunnel.service.ITunnelService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * @描述: 隧道基本信息控制层
 * @作者: REN
 * @时间: 2019/5/7 11:36
 */
@RestController
@RequestMapping("tunnel")
public class TunnelController {

    @Autowired
    private ITunnelService tunnelService;

    @RequestMapping(value = "/addTunnelBase",method = RequestMethod.POST)
    public ResponseData addTunnelBase(@RequestBody RequestData requestData) {
        JSONObject jsonObject = requestData.getData();
        return tunnelService.saveTunnelBase(jsonObject);
    }

    @RequestMapping(value = "/getTunnelBase",method = RequestMethod.POST)
    public ResponseData getTunnelBase(@RequestBody RequestData requestData) {
        JSONObject jsonObject = requestData.getData();
        return tunnelService.queryTunnelBase(jsonObject);
    }

}
