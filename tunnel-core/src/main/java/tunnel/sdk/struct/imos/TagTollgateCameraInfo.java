package tunnel.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static tunnel.sdk.constanst.IMOSDefLibrary.*;

/**
 * @描述: 卡口相机信息
 * @作者: REN
 * @时间: 2019/3/2 17:02
 */
public class TagTollgateCameraInfo extends Structure {
    /** 相机编码 */
    public byte  szCameraCode[] = new byte[IMOS_CODE_LEN];
    /** 相机名称 */
    byte[]  szCameraName = new byte[IMOS_NAME_LEN];
    /** 相机类型，参考#TALLGATE_CAMERA_TYPE_E */
    int ulCameraType;
    /** 所属EC编码 */
    byte[] szECCode= new byte[IMOS_CODE_LEN];
    /** 所属EC名称，查询返回，其他情况下可以不填 */
    byte[] szECName = new byte[IMOS_NAME_LEN];
    /** 所属EC类型 */
    int ulECType;
    /** 所属EC通道 */
    int ulECChannel;
    /** 所属卡口编码 */
    byte[] szTollgateCode = new byte[IMOS_CODE_LEN];
    /** 所属卡口名称，查询返回，其他情况下可以不填 */
    byte[] szTollgateName = new byte[IMOS_NAME_LEN];
    /** 抓拍的车道数量，如果是一个车道对应一个相机，则填1 */
    int ulTollgateLaneNum;
    /** 抓拍的卡口车道列表 */
    int[] aulTollgateLaneList = new int[IMOS_MAX_CAMERA_LANE_NUM];
    /** 设备地址类型，1-IPv4 2-IPv6 */
    int ulDevAddrType;
    /** 设备地址 */
    byte[]  szDevAddr = new byte[IMOS_IPADDR_LEN];
    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    int ulIsOnline;
    /** 设备扩展状态，预留 */
    int ulDevExtStatus;
    /** 经度 */
    byte[]  szLongitude = new byte[IMOS_COORDINATE_LEN];
    /** 纬度 */
    byte[]  szLatitude= new byte[IMOS_COORDINATE_LEN];
    /** 相机描述, 暂不使用，填空 */
    byte[]  szCameraDesc=new byte[IMOS_DESC_LEN];
    /** 采集设备类型 */
    byte[] szEquipmentType=new byte[IMOS_DICTIONARY_KEY_LEN];
    /** 预留字段 */
    byte[] szReserve = new byte[196];

    protected List<String> getFieldOrder() {
        return Arrays.asList("szCameraCode","szCameraName","ulCameraType","szECCode","szECName","ulECType","ulECChannel","szTollgateCode",
                "szTollgateName","ulTollgateLaneNum","aulTollgateLaneList","ulDevAddrType","szDevAddr","ulIsOnline","ulDevExtStatus","szLongitude",
                "szLatitude","szCameraDesc","szEquipmentType","szReserve");
    }

    public TagTollgateCameraInfo() {
        super();
    }

    public TagTollgateCameraInfo(Pointer peer) {
        super(peer);
    }
    public static class ByReference extends TagCruisePathQueryItem implements Structure.ByReference {

    };
    public static class ByValue extends TagCruisePathQueryItem implements Structure.ByValue {

    };
}
