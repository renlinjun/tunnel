package com.burst.common;

import com.burst.config.TunnelConfig;
import com.burst.config.TunnelProperties;
import com.burst.core.VehicleData;
import com.burst.tunnel.service.ICarInfoService;
import com.bust.utils.DateUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.*;

/**
 * @描述: 当前过车信息数据
 *        spring本身实例化即为单例模式，因此只需要对当前对象做同步锁即可
 * @作者: 任琳珺
 * @时间: 2019/4/28 14:30
 */
@Component
public class CurrentCarInfosCache {

    @Autowired
    private ICarInfoService carInfoService;

    @Autowired
    private TunnelProperties tp;

    /** 当前双向隧道内所有车辆信息 */
    public Map<String,VehicleData> currentCarList = new HashMap<>();
    /** 根据隧道划分的车辆信息列表 */
    public Map<String,List<VehicleData>> tunnelCarList = new HashMap<>();
  /*  *//** 驶出隧道的车辆信息，改信息不是所有驶出的车辆，只是用来当驶出车辆达到一定数量后更新数据库数据 ,默认30条*//*
    public Map<String,VehicleData> outSideCarInfo = new HashMap<>();*/
    /** 需要存储的车辆信息,按照车辆驶出隧道来计算，当驶出车辆达到一定数量后更新数据库数据 ,默认30条 */
    public List<VehicleData> storeCarInfos = new ArrayList<>();

    /** 预估计算出的车辆驶出隧道时间 （车牌号：驶出时间）*/
    public Map<String,Long> carMayOutSideTime = new HashMap<>();
    /** 涉及到的告警车辆列表 */
    public List<VehicleData> alarmCarInfo = new ArrayList<>();
    /** 发生告警推送的信息数量 */
    private int alarmedCarNum = 0;



    /**
     *
     * 功能描述:
     *          更新车辆信息
     * @auther:
     * @date:
     * @param:
     *      实时车辆信息
     * @return:
     */
    public void updateCarInfos(VehicleData vehicleData) {
        synchronized(this) {
            //替换或者添加当前过车信息到当前隧道内的车辆
            String carPlate = vehicleData.getCarPlate();
            //如果是出隧道则将车辆从当前隧道车辆信息中移除
            if(vehicleData.getInSideOrOutSide()== TunnelConfig.OUT_TOLLGATE) {
                VehicleData currentCar = currentCarList.get(carPlate);
                currentCar.setOutTime(vehicleData.getPassTime());
                currentCarList.remove(carPlate);
                getCarMayOutSideInfo().remove(carPlate);
                storeCarInfos.add(vehicleData);
            }else {
                if(vehicleData.getInSideOrOutSide()== TunnelConfig.IN_TOLLGATE) {
                    ComputCarMayOutSideTime(vehicleData);
                }
                updateCurrentInfo(vehicleData);
            }
            //如果数据达到20条，则存入数据库
            if(storeCarInfos.size()==20) {
                carInfoService.storeCarInfoBatch(storeCarInfos);
                storeCarInfos.clear();
            }
        }
    }

    /**
     *
     * 功能描述: 根据车牌获取隧道内车辆信息
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public VehicleData getCarInfoByPlate(String carPlate) {
        return currentCarList.get(carPlate);
    }

    public Map<String,Long> getCarMayOutSideInfo() {
        return carMayOutSideTime;
    }

    public void updateCurrentInfo(VehicleData vehicleData) {
        synchronized(this) {
            //替换或者添加当前过车信息到当前隧道内的车辆
            String carPlate = vehicleData.getCarPlate();
            currentCarList.put(carPlate, vehicleData);
            //根据隧道存放车辆信息
            tunnelCarList.get(vehicleData.getTunnelId()).add(vehicleData);
        }
    }

    /**
     *
     * 功能描述:
     *      增加告警车辆
     * @auther:
     * @date:
     * @param:
     *      carPlate 车辆车牌号
     * @return:
     */
    public void addAlarmCar(String carPlate) {
        alarmCarInfo.add(currentCarList.get(carPlate));
    }

    public int getAlarmCarNum() {
        return alarmedCarNum;
    }

    public void addAlarmCarNum() {
        this.alarmedCarNum++;
    }

    public void ComputCarMayOutSideTime(VehicleData vehicleData) {
        int tunnelSize = tp.getSize();
        double hour = tunnelSize / vehicleData.getVehicleSpeed();
        int second = (int)(hour * 60 * 60);
        long outSideTime = DateUtil.secondOffset(second);
        carMayOutSideTime.put(vehicleData.getCarPlate(),outSideTime);
    }

}
