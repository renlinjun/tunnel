package tunnel.sdk.callBack.impl;

import com.burst.websocket.TunnelMessageHandler;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.PointerByReference;
import com.tunnel.utils.JSONUtils;
import org.springframework.stereotype.Component;
import org.springframework.web.server.WebSession;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;
import tunnel.sdk.callBack.CallBackProcExPf;
import tunnel.sdk.struct.imos.TagUserLoginIDInfo;
import tunnel.sdk.struct.imos.TagVehicleAlarmData;
import tunnel.sdk.struct.imos.TagVehicleData;
import tunnel.sdk.struct.imos.TagVehicleRealTimeData;

import javax.websocket.Session;
import java.io.IOException;
import java.util.List;

import static tunnel.sdk.constanst.SDKDef.TagCallBackProcType.PROC_TYPE_VEHICLE_ALARM_DATA;
import static tunnel.sdk.constanst.SDKDef.TagCallBackProcType.PROC_TYPE_VEHICLE_DATA;

/**
 * @描述: 推送信息回调函数
 * @作者: REN
 * @时间: 2019/1/5 16:11
 */
@Component
public class CallBackProcExPfImpl implements CallBackProcExPf {

    @Override
    public void callback(TagUserLoginIDInfo.ByReference userLoginIDInfo,int ulProcType, Pointer pParam){
        //根据消息类型判断用哪个函数进行处理
        switch (ulProcType) {
            case  PROC_TYPE_VEHICLE_DATA : //实时车辆信息
                vehicleData(userLoginIDInfo,pParam);
                break;
            case  PROC_TYPE_VEHICLE_ALARM_DATA: //通知车辆实时告警
                vehicleAlarmData(userLoginIDInfo,pParam);
                break;
            default:

        }
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
        System.out.println("开始向客户端推送消息");
        TunnelMessageHandler.sendAllConnectedClient(new TextMessage(JSONUtils.beanToJson(stVehicleData)));
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
        TunnelMessageHandler.sendAllConnectedClient(new TextMessage(JSONUtils.beanToJson(vehicleAlarmData)));
    }

}
