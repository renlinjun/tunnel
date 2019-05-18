package com.burst.tunnel.service;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.ResponseData;
import com.burst.core.VehicleData;
import com.burst.exception.CustomException;

import java.util.List;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/6 09:50
 */
public interface ICarInfoService {


    /**
     *
     * 功能描述:
     *      批量存储过车数据
     * @auther: 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    ResponseData storeCarInfoBatch(List<VehicleData> vehicleDatas);

    /***
     *  获取隧道中的单个车辆信息
     * @param json
     * @return
     * @throws CustomException
     */
    ResponseData queryCurrentCarInfo(JSONObject json) throws CustomException;

    /**
     *
     * 功能描述:
     *  获取隧道中的所有车辆信息
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    ResponseData getCurrentCarsByTunnel(JSONObject json) throws CustomException;

    ResponseData getTunnelCarInfo()  throws CustomException;

}
