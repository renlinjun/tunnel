package com.burst.sdk.struct.imos;

import com.burst.sdk.constanst.IMOSDefLibrary;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;


/**
 * @描述: 卡口相机信息
 * @作者: REN
 * @时间: 2019/3/2 17:02
 */
public class TagTollgateCameraInfo extends Structure {
    /** 相机编码 */
    public byte[]  szCameraCode = new byte[IMOSDefLibrary.IMOS_CODE_LEN];
    /** 相机名称 */
    public byte[]  szCameraName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
    /** 相机类型，参考#TALLGATE_CAMERA_TYPE_E */
    public int ulCameraType;
    /** 所属EC编码 */
    public byte[] szECCode= new byte[IMOSDefLibrary.IMOS_CODE_LEN];
    /** 所属EC名称，查询返回，其他情况下可以不填 */
    public byte[] szECName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
    /** 所属EC类型 */
    public int ulECType;
    /** 所属EC通道 */
    public int ulECChannel;
    /** 所属卡口编码 */
    public byte[] szTollgateCode = new byte[IMOSDefLibrary.IMOS_CODE_LEN];
    /** 所属卡口名称，查询返回，其他情况下可以不填 */
    public byte[] szTollgateName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
    /** 抓拍的车道数量，如果是一个车道对应一个相机，则填1 */
    public int ulTollgateLaneNum;
    /** 抓拍的卡口车道列表 */
    public int[] aulTollgateLaneList = new int[IMOSDefLibrary.IMOS_MAX_CAMERA_LANE_NUM];
    /** 设备地址类型，1-IPv4 2-IPv6 */
    public int ulDevAddrType;
    /** 设备地址 */
    public byte[]  szDevAddr = new byte[IMOSDefLibrary.IMOS_IPADDR_LEN];
    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    public int ulIsOnline;
    /** 设备扩展状态，预留 */
    public int ulDevExtStatus;
    /** 经度 */
    public byte[]  szLongitude = new byte[IMOSDefLibrary.IMOS_COORDINATE_LEN];
    /** 纬度 */
    public byte[]  szLatitude= new byte[IMOSDefLibrary.IMOS_COORDINATE_LEN];
    /** 相机描述, 暂不使用，填空 */
    public byte[]  szCameraDesc=new byte[IMOSDefLibrary.IMOS_DESC_LEN];
    /** 采集设备类型 */
    public byte[] szEquipmentType=new byte[IMOSDefLibrary.IMOS_DICTIONARY_KEY_LEN];
    /** 预留字段 */
    public byte[] szReserve = new byte[196];

    protected List<String> getFieldOrder() {
        return Arrays.asList("szCameraCode","szCameraName","ulCameraType","szECCode","szECName","ulECType","ulECChannel",
                            "szTollgateCode", "szTollgateName","ulTollgateLaneNum","aulTollgateLaneList",
                "ulDevAddrType","szDevAddr","ulIsOnline","ulDevExtStatus","szLongitude",
                "szLatitude","szCameraDesc","szEquipmentType","szReserve");
    }

    public TagTollgateCameraInfo() {
        super();
    }

    public TagTollgateCameraInfo(Pointer peer) {
        super(peer);
    }
    public static class ByReference extends TagTollgateCameraInfo implements Structure.ByReference {
        public ByReference(Pointer pointer) {
            super(pointer);
        }
        public ByReference() {
            super();
        }
    }
    public static class ByValue extends TagTollgateCameraInfo implements Structure.ByValue {

    }
}
