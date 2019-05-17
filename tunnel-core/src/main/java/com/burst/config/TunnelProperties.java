package com.burst.config;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import sun.rmi.server.InactiveGroupException;

/**
 * @描述: 隧道信息
 * @作者: REN
 * @时间: 2019/4/28 15:02
 */
@Component
public class TunnelProperties {
    /** 隧道长度 */
    @Value("${tunnel.size}")
    private int size;
    @Value("${tunnel.name}")
    private String tunnelName;
    /** 方向1入口卡口编码 */
    @Value("${tunnel.direction1.in-tollgateId}")
    private String inTollgateId1;
    /** 方向1出口卡口编码 */
    @Value("${tunnel.direction1.out-tollgateId}")
    private String outTollgateId1;
    /** 方向2入口卡口编码 */
    @Value("${tunnel.direction2.in-tollgateId}")
    private String inTollgateId2;
    /** 方向2出口卡口编码 */
    @Value("${tunnel.direction2.out-tollgateId}")
    private String outTollgateId2;

    public String getTunnelName() {
        return tunnelName;
    }

    public void setTunnelName(String tunnelName) {
        this.tunnelName = tunnelName;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public String getInTollgateId1() {
        return inTollgateId1;
    }

    public void setInTollgateId1(String inTollgateId1) {
        this.inTollgateId1 = inTollgateId1;
    }

    public String getOutTollgateId1() {
        return outTollgateId1;
    }

    public void setOutTollgateId1(String outTollgateId1) {
        this.outTollgateId1 = outTollgateId1;
    }

    public String getInTollgateId2() {
        return inTollgateId2;
    }

    public void setInTollgateId2(String inTollgateId2) {
        this.inTollgateId2 = inTollgateId2;
    }

    public String getOutTollgateId2() {
        return outTollgateId2;
    }

    public void setOutTollgateId2(String outTollgateId2) {
        this.outTollgateId2 = outTollgateId2;
    }

}
