package com.burst.tunnel.service.impl;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.ResponseData;
import com.burst.config.TunnelProperties;
import com.burst.tunnel.dao.CamInfoMapper;
import com.burst.tunnel.dao.TunnelMapper;
import com.burst.tunnel.service.ICamService;
import com.bust.constants.ResultConstants;
import com.bust.utils.UUIDUtils;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/7 16:45
 */
//@Component
public class CamServiceImpl implements ICamService {

    //@Autowired
    private CamInfoMapper camInfoMapper;
    @Autowired
    private TunnelMapper tunnelMapper;
    @Autowired
    private TunnelProperties tp;

    /**
     * 功能描述:
     * 增加摄像机
     *
     * @param data
     * @auther: 任琳珺
     * @date: 2019-05-09
     * @param:
     * @return:
     */
    @Override
    public ResponseData addCam(JSONObject data) {
        //设置数据ID
        data.put("id", UUIDUtils.getUUID());
        camInfoMapper.addCam(data);
        return new ResponseData(ResultConstants.SUCCESS_CODE,"添加成功",data);
    }

    /**
     * 功能描述:
     * 查询摄像头列表
     *
     * @param condition
     * @auther： 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    @Override
    public ResponseData listCameTree(JSONObject condition) {
        Map<String,Object> tree = new HashMap<>();
        tree.put("label",tp.getTunnelName());

        List<Map<String,Object>> tunnelList = tunnelMapper.queryTunnelBaseInfo(new HashMap<>());
        tree.put("children",tunnelList);
        for(int i=0;i<tunnelList.size();i++) {
            Map<String,Object> tunnelInfo = tunnelList.get(i);
            tunnelInfo.put("label",tunnelInfo.get("direction"));
            String tunnelId = tunnelInfo.get("id").toString();
            List<Map<String,Object>> cameList = camInfoMapper.listCameByTunnel(tunnelId);
            for(int j=0;j<cameList.size();j++) {
                Map<String,Object> came = cameList.get(i);
                came.put("label",came.get("cameCode"));
            }
            tunnelInfo.put("children",cameList);
        }
        return new ResponseData(ResultConstants.SUCCESS_CODE,"查询成功",tree);
    }

    /**
     * 功能描述:
     * 查询摄像头列表
     *
     * @param condition
     * @auther： 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    @Override
    public ResponseData listCame(JSONObject condition) {

        List<Map<String,Object>> tunnelList = tunnelMapper.queryTunnelBaseInfo(new HashMap<>());

        for(int i=0;i<tunnelList.size();i++) {

            Map<String,Object> tunnelInfo = tunnelList.get(i);
            System.out.println(tunnelInfo);
            String tunnelId = tunnelInfo.get("id").toString();
            List<Map<String,Object>> cameList = camInfoMapper.listCameByTunnel(tunnelId);
            tunnelInfo.put("cameList",cameList);
        }
        return new ResponseData(ResultConstants.SUCCESS_CODE,"查询成功",tunnelList);
    }

    /**
     * 功能描述:
     * 根据隧道ID查询摄像头列表
     *
     * @param condition
     * @auther： 任琳珺
     * @date: 2019-05-10
     * @param:
     * @return:
     */
    @Override
    public ResponseData listCameByTunnel(JSONObject condition) {
        String tunnelId = condition.getString("tunnelId");
        List<Map<String,Object>> cameList = camInfoMapper.listCameByTunnel(tunnelId);
        return new ResponseData(ResultConstants.SUCCESS_CODE,"查询成功",cameList);
    }

}
