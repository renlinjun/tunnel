package tunnel.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static tunnel.sdk.constanst.IMOSDefLibrary.IMOS_CODE_LEN;
import static tunnel.sdk.constanst.IMOSDefLibrary.IMOS_MAX_CAMERA_LANE_NUM;
import static tunnel.sdk.constanst.IMOSDefLibrary.IMOS_NAME_LEN;

/**
 * @描述: 卡口摄像机查询信息
 * @作者: REN
 * @时间: 2019/3/2 17:02
 */
public class TagTollgateVideoCameraQueryItem extends Structure {
    /** 全景摄像机编码 */
    public byte[] szCameraCode = new byte[IMOS_CODE_LEN];

    /** 全景摄像机名称 */
    public byte[] szCameraName = new byte[IMOS_NAME_LEN];

    /** 全景摄像机类型，参考#CAMERA_TYPE_E */
    public int ulCameraType;

    /** 所属卡口编码 */
    public byte[] szTollgateCode = new byte[IMOS_CODE_LEN];

    /** 所属卡口名称 */
    public byte[] szTollgateName = new byte[IMOS_NAME_LEN];

    /** 抓拍的卡口车道数量 */
    public int ulPhotoLaneNum;

    /** 抓拍的卡口车道列表 */
    public int aulPhotoLaneList[] = new int[IMOS_MAX_CAMERA_LANE_NUM];

    /** 监控的卡口车道数量 */
    public int ulVideoLaneNum;

    /** 监控的卡口车道列表 */
    public int aulVideoLaneList[] = new int[IMOS_MAX_CAMERA_LANE_NUM];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    public int ulIsOnline;

    /** 设备扩展状态，预留 */
    public int ulDevExtStatus;

    /** 全景摄像机描述, 暂不使用，填空 */
    public int  szCameraDesc;

    /** 资源是否属于外域 */
    public int   ulIsForeign;

    /** 采集设备类型 */
    public int  szEquipmentType;

    /** 预留字段 */
    public byte[] szReserve = new byte[196];

    protected List<String> getFieldOrder() {
        return Arrays.asList("szCameraCode","szCameraName","ulCameraType","szTollgateCode","ulPhotoLaneNum","ulPhotoLaneNum","aulPhotoLaneList",
                "ulVideoLaneNum","aulVideoLaneList","ulIsOnline","ulDevExtStatus","szCameraDesc","ulIsForeign","szEquipmentType","szReserve");
    }


    public TagTollgateVideoCameraQueryItem() {
        super();
    }

    public TagTollgateVideoCameraQueryItem(Pointer peer) {
        super(peer);
    }


    public static class ByReference extends TagCruisePathQueryItem implements Structure.ByReference {

    };
    public static class ByValue extends TagCruisePathQueryItem implements Structure.ByValue {

    };
}
