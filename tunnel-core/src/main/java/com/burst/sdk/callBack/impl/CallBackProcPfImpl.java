package com.burst.sdk.callBack.impl;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.SystemCache;
import com.burst.sdk.struct.imos.TagVehicleAlarmData;
import com.burst.sdk.struct.imos.TagVehicleData;
import com.burst.websocket.TunnelMessageHandler;
import com.bust.constants.DataType;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import com.burst.sdk.callBack.CallBackProcPf;
import com.burst.sdk.library.XPFrameLibrary;
import com.burst.sdk.struct.imos.*;

import static com.burst.sdk.constanst.SDKDef.TagCallBackProcType.*;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/1/5 16:11
 */
@Component
public class CallBackProcPfImpl implements CallBackProcPf {

    @Override
    public void callback(int ulProcType, Pointer pParam) {
        //根据消息类型判断用哪个函数进行处理
        switch (ulProcType) {
            case PROC_TYPE_DEV_STATUS : //设备状态信息
                devStatusData(pParam);
                break;
            case  PROC_TYPE_VEHICLE_DATA : //实时车辆信息
                vehicleData(pParam);
                break;
            case  PROC_TYPE_VEHICLE_ALARM_DATA: //通知车辆实时告警
                vehicleAlarmData(pParam);
                break;
            case  PROC_TYPE_ALARM: //告警
                alarm(pParam);
                break;
            default:
                System.out.println("未知的消息类型");
        }
    }

    /**
     *
     * 功能描述: 设备状态信息
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    private void devStatusData(Pointer pParam) {
        System.out.println("设备状态信息推送");
        TagASStaPushUI pushUI = new TagASStaPushUI(pParam);
        System.out.println("父设备类型："+pushUI.ulParDevType+",父设备编码:"+pushUI.szParDevCode);
        System.out.println("子设备类型："+pushUI.ulSubDevType+",子设备编码:"+pushUI.szSubDevCode);
    }

    /**
     *
     * 功能描述:
     * 通知实时车辆信息，对应结构:VEHICLE_REAL_TIME_DATA_S
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    private void vehicleData(Pointer pParam) {
        System.out.println("接收到实时过车数据.......");
        //车辆实时显示记录
        TagVehicleRealTimeData vehicleRealTimeData = new TagVehicleRealTimeData(pParam);
        //获取到车辆实时基本信息
        TagVehicleData stVehicleData = vehicleRealTimeData.stVehicleData;
        //加载图片
        XPFrameLibrary.INSTANCE.IMOS_LoadImage(SystemCache.userIDInfoReference,vehicleRealTimeData.szXPWinCode,stVehicleData.aszImgList);
        JSONObject data = stVehicleData.toJsonObj();
        //将数据类型设置为实时过车数据
        data.put("dataType", DataType.PROC_TYPE_VEHICLE_DATA);
        System.out.println("开始向客户端推送消息");
        TunnelMessageHandler.sendTextMessage2Client(new TextMessage(data.toJSONString()));
    }

    /**
     *
     * 功能描述:
     * 通知实时车辆报警，对应结构:VEHICLE_ALARM_DATA_S
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    private void vehicleAlarmData(Pointer pParam) {
        TagVehicleAlarmData vehicleAlarmData = new TagVehicleAlarmData(pParam);
        JSONObject data = vehicleAlarmData.toJsonObj();
        //将数据类型设置为告警数据
        data.put("dataType",DataType.PROC_TYPE_VEHICLE_ALARM_DATA);
        TunnelMessageHandler.sendTextMessage2Client(new TextMessage(data.toJSONString()));
    }


    /**
     *
     * 功能描述: 告警
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    private void alarm(Pointer pointer) {
        TagASAlarmPushUI tagASAlarmPushUI = new TagASAlarmPushUI(pointer);
        System.out.println("告警源名称："+Native.toString(tagASAlarmPushUI.szAlarmSrcName));
        System.out.println("告警描述信息："+Native.toString(tagASAlarmPushUI.szAlarmDesc));
        System.out.println("告警类型："+tagASAlarmPushUI.ulAlarmType);
    }

}
