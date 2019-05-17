package com.burst.tunnel.service;

import com.alibaba.fastjson.JSONObject;
import com.burst.common.ResponseData;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/7 16:43
 */
public interface ITunnelService {

    ResponseData saveTunnelBase(JSONObject info);

    ResponseData queryTunnelBase(JSONObject condition);
}
