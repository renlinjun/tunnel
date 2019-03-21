package tunnel.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static tunnel.sdk.constanst.IMOSDefLibrary.IMOS_CODE_LEN;

/**
 * @描述: 车辆实时显示记录
 * @作者: REN
 * @时间: 2019/3/6 15:54
 */
public class TagVehicleRealTimeData extends Structure {

    /** XP窗格编码 */
    public byte szXPWinCode[] = new byte[IMOS_CODE_LEN];

    /** 相机编码 */
    public byte szCameraCode[] = new byte[IMOS_CODE_LEN];

    /** 车辆基本信息 */
    public TagVehicleData.ByValue stVehicleData = new TagVehicleData.ByValue();

    public TagVehicleRealTimeData(Pointer pointer) {
        super(pointer);
    }

    public TagVehicleRealTimeData() {
        super();
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("szXPWinCode", "szCameraCode", "stVehicleData");
    }

    public static class ByReference extends TagVehicleRealTimeData implements Structure.ByReference {
    }
    public static class ByValue extends TagVehicleRealTimeData implements Structure.ByValue {
    }
}
