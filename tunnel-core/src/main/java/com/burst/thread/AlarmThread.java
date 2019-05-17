package com.burst.thread;

import com.burst.common.CurrentCarInfosCache;
import com.burst.core.VehicleData;
import com.burst.handler.VehicleHandler;
import com.burst.tunnel.dao.AlarmMapper;
import com.bust.constants.DataType;
import com.bust.utils.DateUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.Iterator;
import java.util.Map;
import java.util.Set;

/**
 * @描述: 扫描当前隧道内车辆信息。查看车辆是否产生告警
 * @作者: REN
 * @时间: 2019/5/3 00:06
 */
@Component
public class AlarmThread extends Thread {


    @Autowired
    private AlarmMapper alarmMapper;
    @Autowired
    private CurrentCarInfosCache currentCarInfosCache;

    @Override
    public void run() {

        while(true) {

            Map<String,Long> carMayOutSide = currentCarInfosCache.getCarMayOutSideInfo();
            if(carMayOutSide.size()>0) {
                Set<String> keys = carMayOutSide.keySet();
                Iterator<String> it = keys.iterator();
                while (it.hasNext()) {
                    String carPlate = it.next();
                    long mayTime = carMayOutSide.get(carPlate);
                    //如果预计时间比当前时间超过20秒，则告警
                    if(DateUtil.isTimeAfterNowForSecond(mayTime,-20)) {
                        System.out.println("隧道内发生告警事件");
                        currentCarInfosCache.addAlarmCar(carPlate);
                        VehicleData alarmCar = currentCarInfosCache.getCarInfoByPlate(carPlate);
                        //将告警车辆存入数据库并且推送数据
                        if(currentCarInfosCache.getAlarmCarNum()<10) {
                            //推送通知消息
                            VehicleHandler.send2Client(alarmCar, DataType.PROC_TYPE_VEHICLE_ALARM_DATA);
                            currentCarInfosCache.addAlarmCarNum();
                        }
                    }
                }
            }
            //线程睡眠20秒钟后再执行
            try {
                Thread.sleep(20 * 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
