package tunnel.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @描述: 卡口车道信息
 * @作者: 任琳珺
 * @时间: 2019/3/18 15:19
 */
public class TagTollgateLaneInfo extends Structure{

    /** 所属卡口编码 */
    public String szTollgateCode = new String();

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
    public int  lLimitedSpeed;

    /** 进出城标志: 0,不涉及 1,进城 2,出城 */
    public int ulIntoCityFlag;

    /** 方向编号 */
    public String szDirection = new String();

    /** 预留字段信息 */
    public String szReserve = new String();

    public TagTollgateLaneInfo() {
        super();
    }

    public TagTollgateLaneInfo(Pointer pointer) {
        super(pointer);
    }


    public List<String> getFieldOrder() {
        return Arrays.asList("szTollgateCode","ulLaneNumber","ulLaneType","ulDirection",
                                "szDirectionName","ulMarkedSpeed","lLimitedSpeed",
                                "ulIntoCityFlag","szDirection","szReserve");
    }

    public static class ByReference extends TagTollgateLaneInfo implements Structure.ByReference {}

    public static class ByValue extends TagTollgateLaneInfo implements Structure.ByValue {}

}
