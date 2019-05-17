package com.burst.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @描述: 卡口车道查询结构
 * @作者: REN
 * @时间: 2019/3/18 16:00
 */
public class TagTollgateLaneQueryItem extends Structure {
    /** 所属卡口编码 */
    public String szTollgateCode = new String();

    /** 所属卡口名称，查询返回，其他情况下可以不填 */
    public String szTollgateName = new String();

    /** 车道号 */
    public int ulLaneNumber;

    /** 车道类型，参考#LANE_TYPE_E */
    public int ulLaneType;

    /** 方向编号，废弃 */
    public int ulDirection;

    /** 方向名称，废弃 */
    public String szDirectionName = new String();

    /** 标示限速，单位Km/h */
    public int ulMarkedSpeed;

    /** 执法限速，单位Km/h */
    public int ulLimitedSpeed;

    /** 进出城标志: 0,不涉及 1,进城 2,出城 */
    public int ulIntoCityFlag;

    /** 抓拍相机编码 */
    public String szPhotoCameraCode = new String();

    /** 抓拍相机名称 */
    public String szPhotoCameraName = new String();

    /** 全景摄像机编码 */
    public String szVideoCameraCode = new String();

    /** 全景摄像机名称 */
    public String szVideoCameraName = new String();

    /** 方向编号 */
    public String szDirection = new String();

    /** 预留字段信息 */
    public String szReserve = new String();


    public TagTollgateLaneQueryItem(){
        super();
    }

    public TagTollgateLaneQueryItem(Pointer pointer) {
        super(pointer);
    }

    public List<String> getFieldOrder() {
        return Arrays.asList("szTollgateCode","ulLaneNumber","ulLaneType","ulDirection","szDirectionName","ulMarkedSpeed",
                            "ulLimitedSpeed","ulIntoCityFlag","szDirection","szReserve");
    }

    public static class ByReference extends TagTollgateLaneQueryItem implements Structure.ByReference{}

    public static class ByValue extends TagTollgateLaneQueryItem implements Structure.ByValue{}
}
