package com.burst.test;

import com.burst.core.VehicleData;
import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import org.springframework.stereotype.Component;

import java.io.*;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @描述: 解析实时xml数据
 * @作者: REN
 * @时间: 2019/4/23 14:57
 */
@Component
public class XmlParseTmp {

    public List<VehicleData> tempParse() throws FileNotFoundException, DocumentException {
        String filepath = "/Users/xixiaoxiao/Desktop/data.xml";
        FileInputStream fileInputStream = new FileInputStream(filepath);
        SAXReader reader = new SAXReader();
        Document doc = reader.read(fileInputStream);
        Element root = doc.getRootElement();
        List<Element> rows = root.element("Worksheet").element("Table").elements("Row");
        rows.remove(0);
        List<VehicleData> vehicleDatas = rows.stream().map(e->rowToData(e)).collect(Collectors.toList());
        return vehicleDatas;
    }

    public VehicleData rowToData(Element element) {
        List<Element> cells = element.elements("Cell");
        VehicleData vehicleData = new VehicleData();
        int i=0;
        vehicleData.setTollgateName(cells.get(i).element("Data").getTextTrim());
        i++;
        vehicleData.setLaneId(cells.get(i).element("Data").getTextTrim());
        i++;
        vehicleData.setDirectionName(cells.get(i).element("Data").getTextTrim());
        i++;
        vehicleData.setCarPlate(cells.get(i).element("Data").getTextTrim());
        i++;
        //vehicleData.setPlateColor(CarInfoCache.carColor(cells.get(i).element("Data").getTextTrim()));
        i++;
        vehicleData.setVehicleColor(cells.get(i).element("Data").getTextTrim());
        i++;
        vehicleData.setVehicleType(cells.get(i).element("Data").getTextTrim());
        i++;
        vehicleData.setVehicleSpeed(Integer.parseInt(cells.get(i).element("Data").getTextTrim()));
        i++;
        vehicleData.setPassTime(cells.get(i).element("Data").getTextTrim());
        i++;
        return vehicleData;
    }

    public static void main(String[] args) {
        try {
            new XmlParseTmp().tempParse();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (DocumentException e) {
            e.printStackTrace();
        }
    }
}
