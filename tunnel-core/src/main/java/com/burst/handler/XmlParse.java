package com.burst.handler;

import com.burst.config.TunnelConfig;
import com.burst.config.TunnelProperties;
import com.burst.cache.TunnelCache;
import com.burst.core.VehicleData;
import com.burst.utils.CarOptionUtils;
import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.io.*;

/**
 * @描述: 解析实时xml数据
 * @作者: REN
 * @时间: 2019/4/23 14:57
 */
@Component
public class XmlParse {

    @Autowired
    private TunnelProperties tunnelProperties;

    public VehicleData parse(byte[] data) throws DocumentException, UnsupportedEncodingException {
        System.out.println("过车数据："+new String(data,"UTF-8"));
        VehicleData vehicleData = new VehicleData();
        //默认不是两客一危车辆
        vehicleData.setPassengerDanger(false);
        SAXReader reader = new SAXReader();
        ByteArrayInputStream bais = new ByteArrayInputStream(data);

        Document doc = reader.read(new InputStreamReader(bais,"UTF8"));
        Element root = doc.getRootElement();

        Element recordIdE = root.element("RecordID");
        vehicleData.setCarPlate(root.elementTextTrim("CarPlate"));
        vehicleData.setRecordId(Integer.parseInt(recordIdE.getTextTrim()));
        String tollgateId = root.elementTextTrim("TollgateID");
        vehicleData.setTollgateId(root.elementTextTrim("TollgateID"));
        //首先判断方向
        //根据方向设置隧道ID
        String directionName = root.elementTextTrim("DirectionName");
        int directionCode = TunnelCache.direct2DirectoryCode.get(directionName);
        //TODO 在卡口为非区间测速情况下这样判断
        vehicleData.setPassTime(root.elementTextTrim("PassTime1"));
        //1表示正方向
        if(directionCode==1) {
            //判断是进入隧道或者离开隧道
            if(tunnelProperties.getInTollgateId1().equals(tollgateId)) {
                vehicleData.setInSideOrOutSide(TunnelConfig.IN_TOLLGATE);
            }else if(tunnelProperties.getOutTollgateId1().equals(tollgateId)){
                vehicleData.setInSideOrOutSide(TunnelConfig.OUT_TOLLGATE);
            }else {
                vehicleData.setInSideOrOutSide(TunnelConfig.OTHER_TOLLGATE);
            }
        }else if(directionCode==2){
            //判断是进入隧道或者离开隧道
            if(tunnelProperties.getInTollgateId2().equals(tollgateId)) {
                vehicleData.setInSideOrOutSide(TunnelConfig.IN_TOLLGATE);
            }else if(tunnelProperties.getOutTollgateId2().equals(tollgateId)){
                vehicleData.setInSideOrOutSide(TunnelConfig.OUT_TOLLGATE);
            }else {
                vehicleData.setInSideOrOutSide(TunnelConfig.OTHER_TOLLGATE);
            }
        }

        vehicleData.setTunnelId(TunnelCache.direct2Id.get(directionName));
        vehicleData.setTollgateName(root.elementTextTrim("TollgateName"));
        vehicleData.setInTime(root.elementTextTrim("PassTime"));
        vehicleData.setOutTime(root.elementTextTrim("PassTime2"));
        vehicleData.setPlaceCode(root.elementTextTrim("PlaceCode"));
        vehicleData.setPlaceName(root.elementTextTrim("PlaceName"));
        //判断是否是两客一危车辆
        String isDanger = root.elementTextTrim("DangerousGoodsMarkStatus");
        //判断是否是危险品车辆
        if(CarOptionUtils.isDanger(isDanger)) {
            vehicleData.setPassengerDanger(true);
            vehicleData.setVehicleType("99");
        }
        int vehicleType = Integer.parseInt(root.elementTextTrim("VehicleType"));
        if(vehicleType==16 || vehicleType==15) {
            vehicleData.setPassengerDanger(true);
        }

        vehicleData.setVehicleSpeed(Integer.parseInt(root.elementTextTrim("vehicleSpeed")));
        return vehicleData;
    }



}
