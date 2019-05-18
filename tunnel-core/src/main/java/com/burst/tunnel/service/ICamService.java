package com.burst.tunnel.service;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.ResponseData;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/7 16:45
 */
public interface ICamService {

    /**
     *
     * 功能描述:
     *         增加摄像机
     * @auther: 任琳珺
     * @date: 2019-05-09
     * @param:
     * @return:
     */
    ResponseData addCam(JSONObject data);

    /**
     *
     * 功能描述:
     *          查询摄像头列表
     * @auther： 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    ResponseData listCame(JSONObject condition);

    /**
     *
     * 功能描述:
     *          以树形结构展示摄像机
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    ResponseData listCameTree(JSONObject condition);

    /**
     *
     * 功能描述:
     *          根据隧道ID查询摄像头列表
     * @auther： 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    ResponseData listCameByTunnel(JSONObject condition);
}
