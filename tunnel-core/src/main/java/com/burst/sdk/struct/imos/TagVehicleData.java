package com.burst.sdk.struct.imos;

import com.alibaba.fastjson.JSONObject;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.*;


/**
 * @描述: 过车记录结构
 * @作者: REN
 * @时间: 2019/3/6 15:59
 */
public class TagVehicleData extends Structure {

    /** 车辆信息编号 */
    public byte[]  szVehicleDataCode = new byte[IMOS_CODE_LEN];

    /** 卡口编号，查询返回，其他情况下可以不填 */
    public byte[]  szTollgateCode = new byte[IMOS_CODE_LEN];

    /** 卡口名称，查询返回，其他情况下可以不填 */
    public byte[]  szTollgateName = new byte[IMOS_NAME_LEN];

    /** 车道号，查询返回，其他情况下可以不填 */
    public int ulLaneNumber;

    /** 行驶方向编号，已废弃 */
    public int ulDirection;

    /** 行驶方向名称，已废弃 */
    public byte[] szDirectionName = new byte[IMOS_NAME_LEN];

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 */
    public byte[]  szPassTime = new byte[IMOS_TIME_LEN];

    /** 号牌数量 */
    public int ulLicensePlateNum;

    /** 号牌号码 */
    public byte[]  aszLicensePlateList = new byte[IMOS_MAX_LICENSE_PLATE_NUM * IMOS_CODE_LEN];

    /** 号牌种类，参考数据字典 */
    public byte[]  szLicensePlateType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌颜色，参考数据字典 */
    public byte[]  szLicensePlateColor = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆速度，单位Km/h */
    public int ulVehicleSpeed;

    /** 标示限速，单位Km/h，查询返回，其他情况下可以不填 */
    public int ulMarkedSpeed;

    /** 车道限速，单位Km/h */
    public int ulLimitedSpeed;

    /** 车辆品牌，参考数据字典 */
    public byte[]  szVehicleLogo = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    public byte[]  szVehicleFiguration = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    public byte[]  szVehicleType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车长，单位: 厘米 */
    public int ulVehicleLen;

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    public int ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    public byte[]  szVehicleColor = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 识别时间，单位: 毫秒 */
    public int ulIdentifyTime;

    /** 识别状态，参考#VEHICLE_IDENTIFY_STATUS_E */
    public int ulIdentifyStatus;

    /** 行驶状态，参考数据字典 */
    public byte[]  szVehicleStatus = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 处理标记，参考#VEHICLE_DEAL_STATUS_E */
    public int ulDealStatus;

    /** 图像数量 */
    public int ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of 卡口三期 */
    /** 图像名称(包含路径)列表，过车数据类型为区间测速时，第0张图片为驶入图片，第1张图片为驶出图片 */
    public byte[]  aszImgList = new byte[IMOS_MAX_VEHICLE_IMG_NUM * IMOS_URL_LEN];

    /** 过车数据类型，参考#VEHICLE_RECORD_TYPE_E */
    public int ulVehicleDataType;

    /** 过车数据类型为区间测速时，为区间编号，其他情况为空 */
    public byte[] szSectionCode = new byte[IMOS_CODE_LEN];

    /** 过车数据类型为区间测速时，为区间名称，其他情况为空 */
    public byte[] szSectionName = new byte[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口编号，其他情况为空 */
    public byte[]  szTollgateCode2 = new byte[IMOS_CODE_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口名称，其他情况为空 */
    public byte[]  szTollgateName2 = new byte[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口车道号，其他情况为0 */
    public int ulLaneNumber2;

    /** 过车数据类型为区间测速时，为驶出卡口行驶方向编号，已废弃 */
    public int ulDirection2;

    /** 过车数据类型为区间测速时，为驶出卡口行驶方向名称，其他情况为空 */
    public byte[] szDirectionName2 = new byte[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime */
    public byte[]  szPassTime2 = new byte[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为区间距离，单位:米，其他情况为0 */
    public int ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of 卡口三期 */

    /** 是否为外域图片，1:外域图片; 0:本域图片，按比特位从低到高，每个比特位表示一张图片
     aszImgList:1 ~ 4, 车牌彩色特征图片:5, 车牌二值化特征图片:6, 驾驶室特征图片:7, 副驾驶室特征图片:8, 车标特征图片:9 */
    public int ulIsForeign;

    /** 地点编码 */
    public byte[] szPlaceCode = new byte[IMOS_CODE_LEN];

    /** 地点名称 */
    public byte[] szPlaceName = new byte[IMOS_NAME_LEN];

    /** 采集类型 */
    public byte[] szEquipmentType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 采集机关编码 */
    public byte[] szDeptCode = new byte[IMOS_CODE_LEN];

    /** 采集机关名称 */
    public byte[] szDeptName = new byte[IMOS_NAME_LEN];

    /** 更新时间 */
    public byte[] szUpdateTime = new byte[IMOS_TIME_LEN];

    /** 行驶方向,告警类别为区间测速告警时，为驶入卡口行驶方向 */
    public byte[] szDirection = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶方向2,通常等于szDirection,告警类别为区间测速告警时，为驶出卡口行驶方向 */
    public byte[] szDirection2 = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌坐标 */
    public byte[] szPlateCoordinate = new byte[IMOS_COORDINATE_LEN];

    /** 车标坐标 */
    public byte[] szLogoCoordinate = new byte[IMOS_COORDINATE_LEN];

    /** 号牌置信度，取值范围[0, 100] */
    public int ulPlateConfidence;

    /** 尾部号牌置信度，取值范围[0, 100] */
    public int ulRearPlateConfidence;

    /** 车辆重量，单位kg */
    public int ulVehicleWeight;

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 支持毫秒 */
    public byte[]  szPassTimeEx = new byte[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime 支持毫秒 */
    public byte[]  szPassTime2Ex = new byte[IMOS_TIME_LEN];

    /** 预留字段 */
    public byte[] szReserve = new byte[100];

    public TagVehicleData() {
        super();
    }

    public TagVehicleData(Pointer peer) {
        super(peer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList(
                "szVehicleDataCode","szTollgateCode","szTollgateName","ulLaneNumber","ulDirection","szDirectionName",
                "szPassTime","ulLicensePlateNum","aszLicensePlateList","szLicensePlateType","szLicensePlateColor","ulVehicleSpeed",
                "ulMarkedSpeed","ulLimitedSpeed","szVehicleLogo","szVehicleFiguration","szVehicleType","ulVehicleLen",
                "ulVehicleColorDepth","szVehicleColor","ulIdentifyTime","ulIdentifyStatus","szVehicleStatus","ulDealStatus",
                "ulImgNum","aszImgList","ulVehicleDataType","szSectionCode","szSectionName","szTollgateCode2",
                "szTollgateName2","ulLaneNumber2","ulDirection2","szDirectionName2","szPassTime2","ulSectionDistance","ulIsForeign",
                "szPlaceCode","szPlaceName","szEquipmentType","szDeptCode","szDeptName","szUpdateTime",
                "szDirection","szDirection2","szPlateCoordinate","szLogoCoordinate","ulPlateConfidence","ulRearPlateConfidence",
                "ulVehicleWeight","szPassTimeEx","szPassTime2Ex","szReserve");
    }

    public JSONObject toJsonObj() {
        JSONObject data = new JSONObject();
        data.put("szVehicleDataCode", Native.toString(szVehicleDataCode));
        data.put("szTollgateCode", Native.toString(szTollgateCode));
        data.put("szTollgateName", Native.toString(szTollgateName));
        data.put("ulLaneNumber", ulLaneNumber);
        data.put("szPassTime", Native.toString(szPassTime));
        data.put("aszLicensePlateList", Native.toString(aszLicensePlateList));
        data.put("szLicensePlateType", Native.toString(szLicensePlateType));
        data.put("szLicensePlateColor", Native.toString(szLicensePlateColor));
        data.put("ulVehicleSpeed",ulVehicleSpeed);
        data.put("szVehicleType", Native.toString(szVehicleType));
        data.put("szVehicleColor", Native.toString(szVehicleColor));
        data.put("szTollgateCode2", Native.toString(szTollgateCode2));
        data.put("szTollgateName2", Native.toString(szTollgateName2));
        data.put("ulLaneNumber2",ulLaneNumber2);
        data.put("szPassTime2", Native.toString(szPassTime2));
        data.put("ulSectionDistance", ulSectionDistance);
        data.put("szPassTimeEx", Native.toString(szPassTimeEx));
        data.put("szPassTime2Ex", Native.toString(szPassTime2Ex));

        return data;
    }

    public static class ByReference extends TagVehicleData implements Structure.ByReference {

    };
    public static class ByValue extends TagVehicleData implements Structure.ByValue {

    };
}
