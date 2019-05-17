package com.burst.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @描述: 卡口信息结构体
 * @作者: REN
 * @时间: 2019/2/27 17:35
 */
public class TagTollgateInfo  extends Structure {
    /** 卡口编号    */
    public byte[] szTollgateCode = new byte[48];
    /** 卡口名称   */
    public byte[] szTollgateName = new  byte[64];
    /** 所属组织  */
    public byte[] szOrgCode = new  byte[48];
    /** 所属组织名称，暂不支持，填空  */
    public byte[] szOrgName = new  byte[64];
    /**  所属TMS编码  */
    public byte[] szTMSCode = new  byte[48];
    /** 所属TMS名称，查询返回，其他情况下可以不填  */
    public byte[] szTMSName = new  byte[64];
    /** 卡口类型，参考::TALLGATE_TYPE_E  */
    public int ulType;
    /** 设备是否在线, 取值为::IMOS_DEV_STATUS_ONLINE或::IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义  */
    public int ulIsOnline;
    /** 设备扩展状态，预留  */
    public int ulDevExtStatus;
    /** 车道数  */
    public int ulLaneNum;
    /** 经度  */
    public byte[] szLongitude = new  byte[32];
    /** 纬度  */
    public byte[] szLatitude = new  byte[32];
    /** 卡口示意图(形如ftp://用户名:密码@192.168.10.1/dispose/abc.jpg)，必须先通过FTP上传到服务器，通过IMOS_GetFTPInfoByOper获取FTP参数  */
    public byte[] szPicture = new  byte[256];
    /** 卡口描述，暂未使用，填空  */
    public byte[] szDesc = new  byte[128 * 3];
    /** 地点编码  */
    public byte[] szPlaceCode = new  byte[48];
    /** 地点名称 */
    public byte[] szPlaceName = new  byte[64];
    /** 采集机关编码  */
    public byte[] szDeptCode = new  byte[48];
    /** 采集机关名称  */
    public byte[] szDeptName = new  byte[64];
    /** 预留字段  */
    public byte[] szReserve = new  byte[256];

    public TagTollgateInfo() {
        super();
        read();
    }


    protected List<String> getFieldOrder() {
        return Arrays.asList("szTollgateCode", "szTollgateName",
                "szOrgCode", "szOrgName", "szTMSCode", "szTMSName",
                "ulType","ulIsOnline","ulDevExtStatus","ulLaneNum","szLongitude","szLatitude","szPicture",
                "szDesc","szPlaceCode","szPlaceName","szDeptCode","szDeptName","szReserve");
    }

    public TagTollgateInfo(Pointer peer) {
        super(peer);
        read();
    }
    public static class ByReference extends TagTollgateInfo implements Structure.ByReference {

        public ByReference(Pointer pointer) {
            super(pointer);
        }
        public ByReference() {
            super();
        }

    }
    public static class ByValue extends TagTollgateInfo implements Structure.ByValue {

    }
}

