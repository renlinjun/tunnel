package com.burst.sdk.struct.imos;

import com.alibaba.fastjson.JSONObject;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.*;

/**
 * @描述: 车辆报警记录(实时)
 * @作者: REN
 * @时间: 2019/3/9 14:36
 */
public class TagVehicleAlarmData extends Structure{
    /** 车辆报警信息编号 */
    public byte[]  szVehicleAlarmCode = new byte[IMOS_CODE_LEN];

    /** 车辆信息编号，查询返回，其他情况下可以不填 */
    public byte[]  szVehicleDataCode = new byte[IMOS_CODE_LEN];

    /** 互联类型，取值为DISPOSITION_INTER_TYPE_LOCAL或者DISPOSITION_INTER_TYPE_LOWER */
    public int ulInterType;

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

    /** 通过时间/告警类别为区间测速告警时，为驶入卡口时间 */
    public byte[]  szPassTime = new byte[IMOS_TIME_LEN];

    /** 号牌数量 */
    public int ulLicensePlateNum;

    /** 号牌号码 */
    public byte[]  aszLicensePlateList = new byte[IMOS_MAX_LICENSE_PLATE_NUM * IMOS_CODE_LEN];

    /** 号牌种类，参考数据字典 */
    public byte[]  szLicensePlateType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌颜色，参考数据字典 */
    public byte[]  szLicensePlateColor = new byte[IMOS_DICTIONARY_KEY_LEN];
    /** 车辆速度，单位Km/h，告警类别为区间测速告警时，为区间平均行驶速度 */
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

    /** 行驶状态，参考数据字典 */
    public byte[]  szVehicleStatus = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 告警类别，参考#VEHICLE_ALARM_TYPE_E */
    public int ulAlarmType;

    /** 根据告警类别填写，如果是布控报警，则为布控编号，如果是黑名单报警，则为黑名单编号。如果是其他，则为空 */
    public byte[]  szDispositionCode = new byte[IMOS_CODE_LEN];

    /** 布控类别，参考数据字典，布控报警才有值，否则为空 */
    public byte[]  szDispositionType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 报警时间，告警类别为区间测速告警时，为驶出卡口时间 */
    public byte[]  szAlarmTime = new byte[IMOS_TIME_LEN];

    /** 处理标记，参考#VEHICLE_DEAL_STATUS_E */
    public int ulDealStatus;

    /** 图像数量 */
    public int ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of 卡口三期 */
    /** 图像名称(包含路径)列表，告警类别为区间测速告警时，第0张图片为合成图片，第1张图片为驶入图片，第2张图片为驶出图片 */
    public byte[]  aszImgList = new byte[IMOS_MAX_VEHICLE_IMG_NUM * IMOS_URL_LEN];

    /** 告警类别为区间测速告警时，为区间编码，其他情况为空 */
    public byte[] szSectionCode = new byte[IMOS_CODE_LEN];

    /** 告警类别为区间测速告警时，为区间名称，其他情况为空 */
    public byte[] szSectionName = new byte[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口编号，其他情况为空 */
    public byte[]  szTollgateCode2 = new byte[IMOS_CODE_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口名称，其他情况为空 */
    public byte[]  szTollgateName2 = new byte[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口车道号，其他情况为0 */
    public int ulLaneNumber2;

    /** 告警类别为区间测速告警时，为驶出卡口行驶方向编号，已废弃 */
    public int ulDirection2;

    /** 告警类别为区间测速告警时，为驶出卡口行驶方向名称，其他情况为空 */
    public byte[] szDirectionName2 = new byte[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口时间，否则等于szPassTime */
    public byte[]  szPassTime2 = new byte[IMOS_TIME_LEN];

    /** 告警类别为区间测速告警时，为区间距离，单位:米，其他情况为0 */
    public int ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of 卡口三期 */

    /** 是否为外域图片，1:外域图片; 0:本域图片，按比特位从低到高，每个比特位表示一张图片
     aszImgList:1 ~ 4, 车牌彩色特征图片:5, 车牌二值化特征图片:6, 驾驶室特征图片:7, 副驾驶室特征图片:8, 车标特征图片:9 */
    public int ulIsForeign;

    /** 违章地点编码 */
    public byte[] szPlaceCode = new byte[IMOS_CODE_LEN];

    /** 违章地点名称 */
    public byte[] szPlaceName = new byte[IMOS_NAME_LEN];

    /** 采集设备类型 */
    public byte[] szEquipmentType = new byte[IMOS_DICTIONARY_KEY_LEN];

    /** 校对用户编码 */
    public byte[] szCorrectUserCode = new byte[IMOS_CODE_LEN];

    /** 校对时间 */
    public byte[] szCorrectTime = new byte[IMOS_TIME_LEN];

    /** 处理用户编码 */
    public byte[] szDoneUserCode = new byte[IMOS_CODE_LEN];

    /** 处理时间 */
    public byte[] szDoneTime = new byte[IMOS_TIME_LEN];

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

    /** 合成图片标识，BOOL_TRUE:aszImgList[0]为合成图片，BOOL_FALSE:无合成图片 */
    public int ulCombineFlag;

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

    /** 报警时间，告警类别为区间测速告警时，为驶出卡口时间 支持毫秒 */
    public byte[]  szAlarmTimeEx = new byte[IMOS_TIME_LEN];

    /** 预留字段 */
    public byte[] szReserve = new byte[64];

    public TagVehicleAlarmData(Pointer pointer) {
        super(pointer);
    }

    public TagVehicleAlarmData() {
        super();
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("szVehicleAlarmCode","szVehicleDataCode","ulInterType","szTollgateCode","szTollgateName","ulLaneNumber","ulDirection",
                "szDirectionName","szPassTime","ulLicensePlateNum","aszLicensePlateList","szLicensePlateType","szLicensePlateColor","ulVehicleSpeed",
                "ulMarkedSpeed","ulLimitedSpeed","szVehicleLogo","szVehicleFiguration","szVehicleType","ulVehicleLen","ulVehicleColorDepth","szVehicleColor",
                "szVehicleStatus","szVehicleStatus","ulAlarmType","szDispositionCode","szDispositionType","szAlarmTime","ulDealStatus",
                "ulImgNum","aszImgList","szSectionCode","szSectionName","szTollgateCode2","szTollgateName2","ulLaneNumber2","ulDirection2","szDirectionName2",
                "szPassTime2","ulSectionDistance","ulIsForeign","szPlaceCode","szPlaceName","szEquipmentType","szCorrectUserCode","szCorrectTime","szDoneUserCode",
                "szDoneTime","szDeptCode","szDeptName","szDirection","szDirection2","szPlateCoordinate","szLogoCoordinate","ulCombineFlag","ulPlateConfidence",
                "ulRearPlateConfidence","ulVehicleWeight","szPassTimeEx","szPassTime2Ex","szAlarmTimeEx","szReserve");
    }


    public JSONObject toJsonObj() {
        JSONObject data = new JSONObject();
        data.put("szVehicleAlarmCode", Native.toString(szVehicleAlarmCode));
        data.put("szVehicleDataCode", Native.toString(szVehicleDataCode));
        data.put("szTollgateCode", Native.toString(szTollgateCode));
        data.put("szTollgateName", Native.toString(szTollgateName));
        data.put("ulLaneNumber", ulLaneNumber);
        data.put("szPassTime", Native.toString(szPassTime));
        data.put("aszLicensePlateList", Native.toString(aszLicensePlateList));
        data.put("szLicensePlateType", Native.toString(szLicensePlateType));
        data.put("ulVehicleSpeed",ulVehicleSpeed);
        data.put("ulLimitedSpeed", ulLimitedSpeed);
        data.put("szVehicleType", Native.toString(szVehicleType));
        data.put("szVehicleColor", Native.toString(szVehicleColor));
        data.put("ulAlarmType", ulAlarmType);
        data.put("szDispositionCode", Native.toString(szDispositionCode));
        data.put("szAlarmTime", Native.toString(szAlarmTime));
        data.put("szTollgateCode2", Native.toString(szTollgateCode2));
        data.put("szSectionName", Native.toString(szSectionName));
        data.put("szDirectionName2", Native.toString(szDirectionName2));
        data.put("szPassTime2", Native.toString(szPassTime2));
        data.put("szPlaceCode", Native.toString(szPlaceCode));
        data.put("szPassTime2Ex", Native.toString(szPassTime2Ex));
        data.put("szAlarmTimeEx", Native.toString(szAlarmTimeEx));
        data.put("szPassTimeEx", Native.toString(szPassTimeEx));
        return data;
    }
    public static class ByReference extends TagVehicleAlarmData implements Structure.ByReference {

    };
    public static class ByValue extends TagVehicleAlarmData implements Structure.ByValue {

    };

}
