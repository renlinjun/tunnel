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
public class TagVehicleData_bak extends Structure {

    /** 车辆信息编号 */
    public byte[]  szVehicleRecodeId = new byte[IMOS_TOLLGATE_SPECIAL_ID_LEN];

    /** 摄像机编码 */
    public byte[]  szCameraCode = new byte[IMOS_TOLLGATE_CODE_LEN];

    /** 卡口编号 */
    public byte[]  szTollgateCode = new byte[IMOS_TOLLGATE_CODE_LEN];

    /** 车道号，不可修改 */
    public byte[]  szLaneNumber = new byte[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 行驶方向 */
    public byte[] szDirectionName = new byte[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 通过时间 */
    public byte[]  szPassTime = new byte[IMOS_TIME_LEN];

    /** 号牌数量 */
    public int ulLicensePlateNum;

    /** 号牌号码 */
    //public String  szLicensePlatCode;
    public byte[]  szLicensePlatCode = new byte[IMOS_TOLLGATE_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    public byte[]  szLicensePlateColor = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典 */
    public byte[]  szLicensePlateType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌一致 */
    public int  bLicensePlateCoincide = 1;

    /** 车辆品牌，参考数据字典 */
    public byte[]  szVehicleLogo = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    public int ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    public byte[]  szVehicleColor = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    public byte[]  szVehicleFiguration = new byte[IMOS_DICTIONARY_KEY_LEN];


    /** 车辆类型，参考数据字典 */
    public byte[]  szVehicleType = new byte[IMOS_DICTIONARY_KEY_LEN];

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
    public byte[]  szVehicleStatus = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 图像数量 */
    public int ulImgNum;

    /** 图像名称列表 */
    //public byte[][]  aszImgList = new byte[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];
    //public byte[]  aszImgList = new byte[IMOS_MAX_VEHICLE_IMG_NUM * IMOS_MAX_VEHICLE_IMG_NAME_LEN];
    public String[]  aszImgList = new String[IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** 图像路径列表用于Tware内部使用，这里的图像名称可能和xml中不一样 */
   //public byte[][] aszImgPathList = new byte[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];
   //public byte[] aszImgPathList = new byte[IMOS_MAX_VEHICLE_IMG_NUM * IMOS_MAX_VEHICLE_IMG_NAME_LEN];
   public String[] aszImgPathList = new String[IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** 图像类型列表 */
    public byte[] aulImgTypeList = new byte[IMOS_MAX_VEHICLE_IMG_NUM];

    /** 图像子合成标志列表 */
    public byte[] szImgSubComposeList = new byte[IMOS_MAX_VEHICLE_IMG_NUM];

    /** 图像子合成标志是否存在列表 */
    public byte[] szImgIsSubComposeList = new byte[IMOS_MAX_VEHICLE_IMG_NUM];

    /** 识别时间，单位: 毫秒 */
    public int ulIdentifyTime;

    /** 识别时间是否存在 */
    public int ulIsIdentifyTime;

    /** 识别状态，参考#VEHICLE_IDENTIFY_STATUS_E */
    public int ulIdentifyStatus;

    /** 处理标记 */
    public byte[]  szDealStatus = new byte[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 过车数据类型，参考#VEHICLE_RECORD_TYPE_E */
    public int ulVehicleDataType;

    /** 卡口编号2 */
    public byte[]  szTollgateCode2 = new byte[IMOS_TOLLGATE_CODE_LEN];

    /** 卡口车道号2 */
    public byte[]  szLaneNumber2 = new byte[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 行驶方向2 */
    public byte[] szDirectionName2 = new byte[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 通过时间2 */
    public byte[] szPassTime2 = new byte[IMOS_TIME_LEN];

    /** 是否已上传 */
    public int ulTransFlag;

    /** 违章地点编码 */
    public byte[] szPlaceCode = new byte[IMOS_TOLLGATE_CODE_LEN];

    /** 采集设备类型 */
    public byte[] szEquipmentType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 采集机关编码 */
    public byte[] szDeptCode = new byte[IMOS_CODE_LEN];

    /** 更新时间 */
    public byte[] szUpdateTime = new byte[IMOS_TIME_LEN];

    /* begin added by suzhijie for change */
    /** 卡口名称 */
    public byte[]  szTollgateName = new byte[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 卡口名称2 */
    public byte[]  szTollgateName2 = new byte[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 地点名称 */
    public byte[] szSectionName = new byte[IMOS_PLACE_NAME_LEN];

    /** 是否实时记录和命令字 */
    public int ulCommand;

    /** 卡口车道类型 */
    public byte[]  szLaneType = new byte[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 卡口车道类型2 */
    public byte[]  szLaneType2 = new byte[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 方向编号 */
    public byte[] szDirectNumber = new byte[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 方向编号2 */
    public byte[] szDirectNumber2 = new byte[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 尾部号牌号码 */
    public byte[]  szBackendPlatCode = new byte[IMOS_TOLLGATE_CODE_LEN];

    /** 尾部号牌颜色，参考数据字典 */
    public byte[]  szBackendPlateColor = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 尾部号牌种类，参考数据字典 */
    public byte[]  szBackendPlateType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 标识限速 */
    public int ulMarkedSpeed;

    /** 标识限速是否存在 */
    public int ulIsMarkedSpeed;

    /** 行人衣着颜色，参考数据字典 */
    public byte[]  szDressColor = new byte[IMOS_DICTIONARY_KEY_LEN];

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

    public TagVehicleData_bak() {
        super();
    }

    public TagVehicleData_bak(Pointer peer) {
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

    public static class ByReference extends TagVehicleData_bak implements Structure.ByReference {

    };
    public static class ByValue extends TagVehicleData_bak implements Structure.ByValue {

    };
}
