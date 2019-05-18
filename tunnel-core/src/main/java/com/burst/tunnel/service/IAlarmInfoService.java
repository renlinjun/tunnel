package com.burst.tunnel.service;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.ResponseData;


/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/14 16:23
 */
public interface IAlarmInfoService {

    ResponseData dealAlarm(JSONObject json);

    ResponseData updataAlarmInfo(JSONObject json);
}
