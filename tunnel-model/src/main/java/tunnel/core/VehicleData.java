package tunnel.core;

import java.util.List;

/**
 * @描述: 实时车辆信息
 * @作者: REN
 * @时间: 2019/4/23 15:08
 */
public class VehicleData {

    /** 车辆卡口信息版本号 */
    private int vehicleVersion;
    /** 卡口相机编号 */
    private String  camId;
    /** 设备编号 */
    private String  devId;
    /** 采集类型 */
    private String  equipmentType;
    /** 记录ID号 */
    private int recordId;
    /** 卡口编号 */
    private String tollgateId;
    /** 卡口名称 */
    private String tollgateName;
    /** 经过时刻 */
    private String  passTime;
    /** 经过时刻2 */
    private String passTime2;
    /** 地点编号 */
    private String  placeCode;
    /** 地点名称*/
    private String  placeName;
    /** 车道编号 */
    private String  LaneId;
    /** 车道类型 */
    private String laneType;
    /** 车道行驶方向 */
    private String laneDirection;
    /** 车道行驶描述 */
    private String laneDescription;
    /** 方向名称 */
    private String  directionName;
    /** 号牌状态 */
    private String  plateStatus;
    /** 号牌号码 */
    private String  carPlate;
    /** 号牌置信度 */
    private int plateConfidence;
    /** 字符置信度 */
    private int charConfidence;
    /** 号牌种类 */
    private String  plateType;
    /** 号牌颜色 */
    private int plateColor;
    /** 抓拍触发类型 */
    private int triggerType;
    /** 图像数量 */
    private int  PicNumber;
    /** 图像信息 */
    private List<ImageData> images;
    /** 车辆速度 */
    private int vehicleSpeed;
    /** 标识限速 */
    private int markedSpeed;
    /** 行驶状态 */
    private String driveStatus;
    /** 车辆品牌 */
    private String vehicleBrand;
    /** 车辆类型 */
    private String vehicleType;

    public int getVehicleVersion() {
        return vehicleVersion;
    }

    public void setVehicleVersion(int vehicleVersion) {
        this.vehicleVersion = vehicleVersion;
    }

    public String getCamId() {
        return camId;
    }

    public void setCamId(String camId) {
        this.camId = camId;
    }

    public String getDevId() {
        return devId;
    }

    public void setDevId(String devId) {
        this.devId = devId;
    }

    public String getEquipmentType() {
        return equipmentType;
    }

    public void setEquipmentType(String equipmentType) {
        this.equipmentType = equipmentType;
    }

    public int getRecordId() {
        return recordId;
    }

    public void setRecordId(int recordId) {
        this.recordId = recordId;
    }

    public String getTollgateId() {
        return tollgateId;
    }

    public void setTollgateId(String tollgateId) {
        this.tollgateId = tollgateId;
    }

    public String getTollgateName() {
        return tollgateName;
    }

    public void setTollgateName(String tollgateName) {
        this.tollgateName = tollgateName;
    }

    public String getPassTime() {
        return passTime;
    }

    public void setPassTime(String passTime) {
        this.passTime = passTime;
    }

    public String getPassTime2() {
        return passTime2;
    }

    public void setPassTime2(String passTime2) {
        this.passTime2 = passTime2;
    }

    public String getPlaceCode() {
        return placeCode;
    }

    public void setPlaceCode(String placeCode) {
        this.placeCode = placeCode;
    }

    public String getPlaceName() {
        return placeName;
    }

    public void setPlaceName(String placeName) {
        this.placeName = placeName;
    }

    public String getLaneId() {
        return LaneId;
    }

    public void setLaneId(String laneId) {
        LaneId = laneId;
    }

    public String getLaneType() {
        return laneType;
    }

    public void setLaneType(String laneType) {
        this.laneType = laneType;
    }

    public String getLaneDirection() {
        return laneDirection;
    }

    public void setLaneDirection(String laneDirection) {
        this.laneDirection = laneDirection;
    }

    public String getLaneDescription() {
        return laneDescription;
    }

    public void setLaneDescription(String laneDescription) {
        this.laneDescription = laneDescription;
    }

    public String getDirectionName() {
        return directionName;
    }

    public void setDirectionName(String directionName) {
        this.directionName = directionName;
    }

    public String getPlateStatus() {
        return plateStatus;
    }

    public void setPlateStatus(String plateStatus) {
        this.plateStatus = plateStatus;
    }

    public String getCarPlate() {
        return carPlate;
    }

    public void setCarPlate(String carPlate) {
        this.carPlate = carPlate;
    }

    public int getPlateConfidence() {
        return plateConfidence;
    }

    public void setPlateConfidence(int plateConfidence) {
        this.plateConfidence = plateConfidence;
    }

    public int getCharConfidence() {
        return charConfidence;
    }

    public void setCharConfidence(int charConfidence) {
        this.charConfidence = charConfidence;
    }

    public String getPlateType() {
        return plateType;
    }

    public void setPlateType(String plateType) {
        this.plateType = plateType;
    }

    public int getPlateColor() {
        return plateColor;
    }

    public void setPlateColor(int plateColor) {
        this.plateColor = plateColor;
    }

    public int getTriggerType() {
        return triggerType;
    }

    public void setTriggerType(int triggerType) {
        this.triggerType = triggerType;
    }

    public int getPicNumber() {
        return PicNumber;
    }

    public void setPicNumber(int picNumber) {
        PicNumber = picNumber;
    }

    public List<ImageData> getImages() {
        return images;
    }

    public void setImages(List<ImageData> images) {
        this.images = images;
    }

    public int getVehicleSpeed() {
        return vehicleSpeed;
    }

    public void setVehicleSpeed(int vehicleSpeed) {
        this.vehicleSpeed = vehicleSpeed;
    }

    public int getMarkedSpeed() {
        return markedSpeed;
    }

    public void setMarkedSpeed(int markedSpeed) {
        this.markedSpeed = markedSpeed;
    }

    public String getDriveStatus() {
        return driveStatus;
    }

    public void setDriveStatus(String driveStatus) {
        this.driveStatus = driveStatus;
    }

    public String getVehicleBrand() {
        return vehicleBrand;
    }

    public void setVehicleBrand(String vehicleBrand) {
        this.vehicleBrand = vehicleBrand;
    }

    public String getVehicleType() {
        return vehicleType;
    }

    public void setVehicleType(String vehicleType) {
        this.vehicleType = vehicleType;
    }

    public String getVehicleType2() {
        return vehicleType2;
    }

    public void setVehicleType2(String vehicleType2) {
        this.vehicleType2 = vehicleType2;
    }

    public String getVehicleColor() {
        return vehicleColor;
    }

    public void setVehicleColor(String vehicleColor) {
        this.vehicleColor = vehicleColor;
    }

    public String getVideoURL() {
        return videoURL;
    }

    public void setVideoURL(String videoURL) {
        this.videoURL = videoURL;
    }

    /** 车辆类型2 */

    private String vehicleType2;
    /** 车身颜色 */
    private String vehicleColor;
    /** 关联录像路径 */
    private String videoURL;
}
