package com.burst.tunnel.service.impl;

import cn.hutool.core.util.StrUtil;
import com.alibaba.fastjson.JSONObject;
import com.burst.common.ResponseData;
import com.burst.core.VehicleData;
import com.burst.exception.CustomException;
import com.burst.common.CurrentCarInfosCache;
import com.burst.tunnel.dao.CarInfoMapper;
import com.burst.tunnel.service.ICarInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;

/**
 * @描述: 车辆信息查询业务层处理类
 * @作者: REN
 * @时间: 2019/5/6 09:54
 */
@Service
public class CarInfoServiceImpl implements ICarInfoService {

    @Autowired
    private CurrentCarInfosCache currentCarInfos;
    @Autowired
    private CarInfoMapper carInfoMapper;

    /**
     * 功能描述:
     * 批量存储过车数据
     *
     * @param vehicleDatas
     * @auther: 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    @Override
    public ResponseData storeCarInfoBatch(List<VehicleData> vehicleDatas) {
        return null;
    }

    public ResponseData queryCurrentCarInfo(JSONObject json) throws CustomException {
        String carPlate = json.getString("carPlate");
        if(StrUtil.isEmpty(carPlate)) {
            throw new CustomException(-1,"缺少必要参数");
        }
        //根据车牌号获取当前车辆信息
        VehicleData vehicleData = currentCarInfos.currentCarList.get(carPlate);

        return new ResponseData(0,"查询成功",vehicleData);
    }

    /**
     *
     * 功能描述:
     *     根据隧道id查询当前隧道车辆列表
     *
     * @auther: 任琳珺
     * @date: 2019-05-14
     * @param:
     * @return:
     */
    @Override
    public ResponseData getCurrentCarsByTunnel(JSONObject json) throws CustomException  {
        String tunnelId = json.getString("tunnelId");
        if(StrUtil.isEmpty(tunnelId)) {
            throw new CustomException(-1,"缺少隧道ID");
        }

        List<VehicleData> cars = currentCarInfos.tunnelCarList.get(tunnelId);
        return new ResponseData(0,"查询成功",cars);
    }




    @Override
    public ResponseData getTunnelCarInfo()  throws CustomException{
        List<VehicleData> alarmCarInfos = currentCarInfos.alarmCarInfo;
        //List<VehicleData> passengersDanger = currentCarInfos.passengersDanger;
        Map<String,VehicleData> currentAllCarInfo = currentCarInfos.currentCarList;
        List<VehicleData> currentCarList = new LinkedList<>();
        Set<Map.Entry<String,VehicleData>> allCarEntry = currentAllCarInfo.entrySet();
        Iterator<Map.Entry<String,VehicleData>> iterator = allCarEntry.iterator();
        while (iterator.hasNext()) {
            Map.Entry<String,VehicleData> carInfoEntry = iterator.next();
            currentCarList.add(carInfoEntry.getValue());
        }

        Map<String,List<VehicleData>> carInfo = new HashMap<>();
        carInfo.put("allCar",currentCarList);
        carInfo.put("alarmCar",alarmCarInfos);
        //carInfo.put("passsengerDanger",passengersDanger);

        return new ResponseData(0,"查询车辆信息成功",carInfo);
    }
}
