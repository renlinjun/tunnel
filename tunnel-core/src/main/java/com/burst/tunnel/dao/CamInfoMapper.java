package com.burst.tunnel.dao;


import java.util.List;
import java.util.Map;

/**
 * @描述: 相机信息Dao层
 * @作者: 任琳珺
 * @时间: 2019/5/7 16:52
 */
//@Mapper
public interface CamInfoMapper {
    /***
     * 增加摄像机
     * @param data
     */
    void addCam(Map<String, Object> data);

    /***
     * 增批量加摄像机
     * @param datas
     */
    void addCamBatch(List<Map<String, Object>> datas);

    /**
     *
     * 功能描述:
     *      查询摄像机列表
     * @auther:e
     * @date:
     * @param:
     * @return:e
     */
    List<Map<String,Object>> listCame(Map<String, Object> condition);

    /**
     *
     * 功能描述:
     *      根据隧道查询摄像机列表
     * @auther:e
     * @date:
     * @param:
     * @return:e
     */
    List<Map<String,Object>> listCameByTunnel(String tunnelId);

}
