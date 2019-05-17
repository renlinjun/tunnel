package com.burst.handler;

import com.burst.common.CurrentCarInfosCache;
import com.burst.core.VehicleData;
import com.burst.websocket.TunnelMessageHandler;
import com.bust.constants.DataType;
import com.bust.utils.ByteUtils;
import com.bust.utils.JSONUtils;
import com.bust.utils.UUIDUtils;
import org.dom4j.DocumentException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import com.burst.core.PushData;

import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

/**
 * @描述: 实时过车数据处理类
 * @作者: REN
 * @时间: 2019/4/24 14:39
 */
@Component
public class VehicleHandler {

    Logger logger = LoggerFactory.getLogger(VehicleHandler.class);

    @Autowired
    private CurrentCarInfosCache currentCarInfosCache;

    public static void send2Client(VehicleData vehicleData, int dataType) {
        PushData pushData = new PushData(dataType,vehicleData);
        //向连接的客户端推送数据
        TextMessage textMessage = new TextMessage(JSONUtils.beanToJson(pushData));
        TunnelMessageHandler.sendTextMessage2Client(textMessage);
    }

    @Async("vehicleDataExecutor")
    public void vehicleDataHandle(byte[] datas) {
        //协议版本
        byte[] protocolByte = new byte[4];
        System.arraycopy(datas,0,protocolByte,0,4);
        int protocolVersion = ByteUtils.byteArrayToInt(protocolByte);
        //命令码
        byte[] commandCodeByte = ByteUtils.byteCopy(datas,4,4);
        int commandCode = ByteUtils.byteArrayToInt(commandCodeByte);
        if(protocolVersion==2) { //协议版本为2则xml以xml方式描述
            XmlParse xmlParse = new XmlParse();
            PicHandler picHandler = new PicHandler();
            if(213==commandCode) {//过车
                //过车数据内容
                byte[] dataContent = ByteUtils.byteCopy(datas,8,datas.length-8);
                //xml信息长度
                int xmllength = ByteUtils.byteArrayToInt(ByteUtils.byteCopy(dataContent,0,4));
                try {
                    //解析xml
                    VehicleData vehicleData = xmlParse.parse(ByteUtils.byteCopy(dataContent,4,xmllength));
                    //为过车数据添加ID字段
                    vehicleData.setId(UUIDUtils.getUUID());
                    System.out.println("过车数据："+JSONUtils.beanToJson(vehicleData));
                    //记录日志
                    logger.info("过车数据："+JSONUtils.beanToJson(vehicleData));
                    //向客户端发送实时过车消息
                    VehicleHandler.send2Client(vehicleData, DataType.PROC_TYPE_VEHICLE_DATA);
                    //存储隧道内当前车辆信息
                    currentCarInfosCache.updateCarInfos(vehicleData);
                    if(currentCarInfosCache.tunnelCarList.get(vehicleData.getTunnelId())!=null) {
                        currentCarInfosCache.tunnelCarList.get(vehicleData.getTunnelId()).add(vehicleData);
                    }else {
                        List<VehicleData> tunnelCarInfos = new ArrayList<>();
                        tunnelCarInfos.add(vehicleData);
                        currentCarInfosCache.tunnelCarList.put(vehicleData.getTunnelId(),tunnelCarInfos);
                    }
                    //TODO 处理图像数据

                } catch (DocumentException e) {
                    e.printStackTrace();
                } catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                }
            }

        }else if(protocolVersion==3) {//协议版本为3则xml以json方式描述

        }
    }
}
