package tunnel.actual;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import org.springframework.stereotype.Component;
import tunnel.core.VehicleData;

import java.io.ByteArrayInputStream;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/23 14:57
 */
@Component
public class XmlParse {

    public VehicleData parse(byte[] data) throws DocumentException {

        VehicleData vehicleData = new VehicleData();
        SAXReader reader = new SAXReader();
        ByteArrayInputStream is = new ByteArrayInputStream(data);
        Document doc = reader.read(is);
        Element root = doc.getRootElement();

        Element vehicleVersionE = root.element("VehicleVersion");
        vehicleData.setVehicleVersion(Integer.parseInt(vehicleVersionE.getTextTrim()));
        Element devIdE = root.element("DevID");
        vehicleData.setDevId(devIdE.getTextTrim());
        Element recordIdE = root.element("RecordID");
        vehicleData.setRecordId(Integer.parseInt(recordIdE.getTextTrim()));
        vehicleData.setTollgateId(root.elementTextTrim("TollgateID"));
        vehicleData.setTollgateName(root.elementTextTrim("TollgateName"));
        vehicleData.setPassTime(root.elementTextTrim("PassTime"));
        vehicleData.setPassTime2(root.elementTextTrim("PassTime2"));
        vehicleData.setPlaceCode(root.elementTextTrim("PlaceCode"));
        vehicleData.setPlaceName(root.elementTextTrim("PlaceName"));
        vehicleData.setLaneId(root.elementTextTrim("LaneID"));
        vehicleData.setCarPlate(root.elementTextTrim("CarPlate"));
        vehicleData.setPlateStatus(root.elementTextTrim("PlateStatus"));
        return vehicleData;
    }
}
