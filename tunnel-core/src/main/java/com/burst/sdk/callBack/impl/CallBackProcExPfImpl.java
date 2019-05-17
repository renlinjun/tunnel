package com.burst.sdk.callBack.impl;

import com.alibaba.fastjson.JSONObject;
import com.burst.sdk.callBack.CallBackProcExPf;
import com.burst.sdk.constanst.SDKDef;
import com.burst.sdk.library.XPFrameLibrary;
import com.burst.sdk.struct.imos.*;
import com.burst.websocket.TunnelMessageHandler;
import com.bust.constants.DataType;
import com.sun.jna.Pointer;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;

/**
 * @描述: 推送信息回调函数
 * @作者: REN
 * @时间: 2019/1/5 16:11
 */
@Component
public class CallBackProcExPfImpl implements CallBackProcExPf {

    @Override
    public void callback(TagUserLoginIDInfo.ByReference userLoginIDInfo, int ulProcType, Pointer pParam){
        //根据消息类型判断用哪个函数进行处理
        switch (ulProcType) {
            case SDKDef.TagCallBackProcType.PROC_TYPE_DEV_STATUS : //设备状态信息
                devStatusData(userLoginIDInfo,pParam);
            case  SDKDef.TagCallBackProcType.PROC_TYPE_VEHICLE_DATA : //实时车辆信息
                vehicleData(userLoginIDInfo,pParam);
                break;
            case  SDKDef.TagCallBackProcType.PROC_TYPE_VEHICLE_ALARM_DATA: //通知车辆实时告警
                vehicleAlarmData(userLoginIDInfo,pParam);
                break;
            default:

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
    private void devStatusData(TagUserLoginIDInfo.ByReference userLoginIDInfo,Pointer pParam) {
        System.out.println("设备状态信息推送");
        TagASStaPushUI pushUI = new TagASStaPushUI(pParam);
        System.out.println("设备状态："+pushUI.ulDevSta);
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
    private void vehicleData(TagUserLoginIDInfo.ByReference userLoginIDInfo,Pointer pParam) {
        System.out.println("接收到实时过车数据.......");

        //车辆实时显示记录
        TagVehicleRealTimeData vehicleRealTimeData = new TagVehicleRealTimeData(pParam);
        //获取到车辆实时基本信息
        TagVehicleData stVehicleData = vehicleRealTimeData.stVehicleData;
        //加载图片
        XPFrameLibrary.INSTANCE.IMOS_LoadImage(userLoginIDInfo,vehicleRealTimeData.szXPWinCode,stVehicleData.aszImgList);
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
    private void vehicleAlarmData(TagUserLoginIDInfo.ByReference userLoginIDInfo,Pointer pParam) {
        TagVehicleAlarmData vehicleAlarmData = new TagVehicleAlarmData(pParam);
        JSONObject data = vehicleAlarmData.toJsonObj();
        //将数据类型设置为告警数据
        data.put("dataType", DataType.PROC_TYPE_VEHICLE_ALARM_DATA);
        TunnelMessageHandler.sendTextMessage2Client(new TextMessage(data.toJSONString()));
    }

}
