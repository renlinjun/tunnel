package tunnel.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static tunnel.sdk.constanst.IMOSDefLibrary.*;

/**
 * @描述: 过车记录结构
 * @作者: REN
 * @时间: 2019/3/6 15:59
 */
public class TagVehicleData extends Structure {

    /** 车辆信息编号 */
    public String  szVehicleRecodeId = new String();

    /** 摄像机编码 */
    public String  szCameraCode = new String();

    /** 卡口编号 */
    public String  szTollgateCode = new String();

    /** 车道号，不可修改 */
    public String  szLaneNumber = new String();

    /** 行驶方向 */
    public String szDirectionName = new String();

    /** 通过时间 */
    public String  szPassTime = new String();

    /** 号牌数量 */
    public int ulLicensePlateNum;

    /** 号牌号码 */
    //public String  szLicensePlatCode;
    public String  szLicensePlatCode = new String();

    /** 号牌颜色，参考数据字典 */
    public String  szLicensePlateColor = new String();

    /** 号牌种类，参考数据字典 */
    public String  szLicensePlateType = new String();

    /** 号牌一致 */
    public int  bLicensePlateCoincide = 1;

    /** 车辆品牌，参考数据字典 */
    public String  szVehicleLogo = new String();

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    public int ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    public String  szVehicleColor = new String();

    /** 车辆外形，暂不使用 */
    public String  szVehicleFiguration = new String();


    /** 车辆类型，参考数据字典 IMOSDefLibrary tagIMOSVehicleAttr_VehicleType*/
    public String  szVehicleType = new String();

    /** 车长，单位: 厘米 */
    public int ulVehicleLen;

    /** 车长是否存在 */
    public int ulIsVehicleLen;

    /** 车辆速度，单位Km/h */
    public int ulVehicleSpeed;

    /** 车辆速度是否存在 */
    public int ulIsVehicleSpeed;

    /** 车道限速，单位Km/h */
    public int ulLimitedSpeed;

    /** 车道限速是否存在 */
    public int ulIsLimitedSpeed;


    /** 行驶状态，参考数据字典 */
    public String  szVehicleStatus = new String();

    /** 图像数量 */
    public int ulImgNum;

    /** 图像名称列表 */
    //public String[]  aszImgList = new byte[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];
    //public String  aszImgList = new byte[IMOS_MAX_VEHICLE_IMG_NUM * IMOS_MAX_VEHICLE_IMG_NAME_LEN];
    public String[]  aszImgList = new String[IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** 图像路径列表用于Tware内部使用，这里的图像名称可能和xml中不一样 */
   //public String[] aszImgPathList = new byte[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];
   //public String aszImgPathList = new byte[IMOS_MAX_VEHICLE_IMG_NUM * IMOS_MAX_VEHICLE_IMG_NAME_LEN];
   public String[] aszImgPathList = new String[IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** 图像类型列表 */
    public String aulImgTypeList = new String();

    /** 图像子合成标志列表 */
    public String szImgSubComposeList = new String();

    /** 图像子合成标志是否存在列表 */
    public String szImgIsSubComposeList = new String();

    /** 识别时间，单位: 毫秒 */
    public int ulIdentifyTime;

    /** 识别时间是否存在 */
    public int ulIsIdentifyTime;

    /** 识别状态，参考#VEHICLE_IDENTIFY_STATUS_E */
    public int ulIdentifyStatus;

    /** 处理标记 */
    public String  szDealStatus = new String();

    /** 过车数据类型，参考#VEHICLE_RECORD_TYPE_E */
    public int ulVehicleDataType;

    /** 卡口编号2 */
    public String  szTollgateCode2 = new String();

    /** 卡口车道号2 */
    public String  szLaneNumber2 = new String();

    /** 行驶方向2 */
    public String szDirectionName2 = new String();

    /** 通过时间2 */
    public String szPassTime2 = new String();

    /** 是否已上传 */
    public int ulTransFlag;

    /** 违章地点编码 */
    public String szPlaceCode = new String();

    /** 采集设备类型 */
    public String szEquipmentType = new String();

    /** 采集机关编码 */
    public String szDeptCode = new String();

    /** 更新时间 */
    public String szUpdateTime = new String();

    /* begin added by suzhijie for change */
    /** 卡口名称 */
    public String  szTollgateName = new String();

    /** 卡口名称2 */
    public String  szTollgateName2 = new String();

    /** 地点名称 */
    public String szSectionName = new String();

    /** 是否实时记录和命令字 */
    public int ulCommand;

    /** 卡口车道类型 */
    public String  szLaneType = new String();

    /** 卡口车道类型2 */
    public String  szLaneType2 = new String();

    /** 方向编号 */
    public String szDirectNumber = new String();

    /** 方向编号2 */
    public String szDirectNumber2 = new String();

    /** 尾部号牌号码 */
    public String  szBackendPlatCode = new String();

    /** 尾部号牌颜色，参考数据字典 */
    public String  szBackendPlateColor = new String();

    /** 尾部号牌种类，参考数据字典 */
    public String  szBackendPlateType = new String();

    /** 标识限速 */
    public int ulMarkedSpeed;

    /** 标识限速是否存在 */
    public int ulIsMarkedSpeed;

    /** 行人衣着颜色，参考数据字典 */
    public String  szDressColor = new String();

    /** 红灯时间 */
    public int ulRedLightTime;

    /** 红灯时间是否存在 */
    public int ulIsRedLightTime;

    /** 应用类型 */
    public int ulApplycationType;

    /** 应用类型是否存在 */
    public int ulIsApplycationType;

    /** 全局合成标识 */
    public int ulGlobalComposeFlag;

    /** 全局合成标识是否存在 */
    public int ulIsGlobalComposeFlag;

    public TagVehicleData() {
        super();
    }

    public TagVehicleData(Pointer peer) {
        super(peer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("szVehicleRecodeId", "szCameraCode", "szTollgateCode","szLaneNumber","szDirectionName","szPassTime",
                "ulLicensePlateNum","szLicensePlatCode","szLicensePlateColor","szLicensePlateType","bLicensePlateCoincide","szVehicleLogo",
                "ulVehicleColorDepth", "szVehicleColor","szVehicleFiguration", "szVehicleType","ulVehicleLen","ulIsVehicleLen",
                "ulVehicleSpeed","ulIsVehicleSpeed","ulLimitedSpeed","ulIsLimitedSpeed", "szVehicleStatus","ulImgNum",
                "aszImgList", "aszImgPathList","aulImgTypeList","szImgSubComposeList","szImgIsSubComposeList", "ulIdentifyTime",
                "ulIsIdentifyTime", "ulIdentifyStatus","szDealStatus","ulVehicleDataType","szTollgateCode2","szLaneNumber2",
                "szDirectionName2", "szPassTime2","ulTransFlag","szPlaceCode","szEquipmentType", "szDeptCode",
                "szUpdateTime","szTollgateName","szTollgateName2", "szSectionName","ulCommand", "szLaneType",
                "szLaneType2","szDirectNumber","szDirectNumber2","szBackendPlatCode","szBackendPlateColor", "szBackendPlateType",
                "ulMarkedSpeed","ulIsMarkedSpeed","szDressColor","ulRedLightTime","ulIsRedLightTime", "ulApplycationType",
                "ulIsApplycationType","ulGlobalComposeFlag","ulIsGlobalComposeFlag");
    }

    public String toString() {
        return "";
    }

    public static class ByReference extends TagVehicleData implements Structure.ByReference {}
    public static class ByValue extends TagVehicleData implements Structure.ByValue {}
}
