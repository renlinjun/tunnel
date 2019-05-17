package com.burst.tunnel;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

/**
 * @描述: 隧道基本信息
 * @作者: REN
 * @时间: 2019/5/7 16:36
 */
public class TunnelBaseInfo {
    private String id;
    private String tunnelName;
    private int tunnelSize;
    private int laneNum;
    private String startMileage;
    private int mileageSpace;
    private String direction;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getTunnelName() {
        return tunnelName;
    }

    public void setTunnelName(String tunnelName) {
        this.tunnelName = tunnelName;
    }

    public int getTunnelSize() {
        return tunnelSize;
    }

    public void setTunnelSize(int tunnelSize) {
        this.tunnelSize = tunnelSize;
    }

    public int getLaneNum() {
        return laneNum;
    }

    public void setLaneNum(int laneNum) {
        this.laneNum = laneNum;
    }

    public String getStartMileage() {
        return startMileage;
    }

    public void setStartMileage(String startMileage) {
        this.startMileage = startMileage;
    }

    public int getMileageSpace() {
        return mileageSpace;
    }

    public void setMileageSpace(int mileageSpace) {
        this.mileageSpace = mileageSpace;
    }

    public String getDirection() {
        return direction;
    }

    public void setDirection(String direction) {
        this.direction = direction;
    }
}
