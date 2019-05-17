package com.burst.sdk.struct.imos;

import com.burst.sdk.constanst.IMOSDefLibrary;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.*;

/**
 * @描述: 告警
 * @作者: REN
 * @时间: 2019/4/16 15:51
 */
public class TagASAlarmPushUI extends Structure {
    /** 告警事件编码 */
    public byte[]  szAlarmEventCode = new byte[IMOSDefLibrary.IMOS_RES_CODE_LEN];
    /** 告警源编码 */
    public byte[]  szAlarmSrcCode = new byte[IMOSDefLibrary.IMOS_DEVICE_CODE_LEN];
    /** 告警源名称 */
    public byte[]  szAlarmSrcName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
    /** 使能后名字*/
    public byte[]  szActiveName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
    /** 告警类型 AlARM_TYPE_E 在sdk_def.h中定义 */
    public int  ulAlarmType;
    /** 告警级别 ALARM_SEVERITY_LEVEL_E 在sdk_def.h中定义 */
    public int  ulAlarmLevel;
    /** 告警触发时间 */
    public byte[]   szAlarmTime = new byte[IMOSDefLibrary.IMOS_TIME_LEN];
    /** 告警描述信息 */
    public byte[] szAlarmDesc = new byte[IMOSDefLibrary.IMOS_STRING_LEN_256];
    /** 告警源父节点名称 */
    public byte[] szAlarmSrcParName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
    /** 保留字段 */
    public byte[]  szReserve = new byte[64];


    public TagASAlarmPushUI(Pointer pointer) {
        super(pointer);
    }

    public TagASAlarmPushUI() {
        super();
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("szAlarmEventCode", "szAlarmSrcCode", "szAlarmSrcName", "szActiveName",
                "ulAlarmType", "ulAlarmLevel","szAlarmTime","szAlarmDesc","szAlarmSrcParName","szReserve");
    }

    public static class ByReference extends TagASAlarmPushUI implements Structure.ByReference {

    }
    public static class ByValue extends TagASAlarmPushUI implements Structure.ByValue {

    }


}
