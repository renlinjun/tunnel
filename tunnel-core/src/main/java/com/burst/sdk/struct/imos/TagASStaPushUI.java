package com.burst.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @描述: 推送给UI的设备状态信息数据结构
 * @作者: REN
 * @时间: 2019/4/8 21:50
 */
public class TagASStaPushUI extends Structure {

    /** 父设备类型 见IMOS_TYPE_E,在sdk_def.h中定义 */
    public int ulParDevType;
    /** 父设备编码 */
    public byte szParDevCode[];
    /** 设备状态 1-#IMOS_DEV_STATUS_ONLINE和2-#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义
     如果父设备类型为"摄像机",则设备状态取值为#AS_CAMERA_STATUS_E */
    public int ulDevSta;
    /* 是否有子设备 */
    public int bHasSubDev;
    /** 子设备类型 */
    public int ulSubDevType;
    /** 子设备编码 */
    public byte szSubDevCode[];

    public TagASStaPushUI() {
        super();
    }

    public TagASStaPushUI(Pointer peer) {
        super(peer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("ulParDevType", "szParDevCode", "ulDevSta", "bHasSubDev",
                "ulSubDevType", "szSubDevCode");
    }

    public static class ByReference extends TagASStaPushUI implements Structure.ByReference {

    }
    public static class ByValue extends TagASStaPushUI implements Structure.ByValue {

    }
}
