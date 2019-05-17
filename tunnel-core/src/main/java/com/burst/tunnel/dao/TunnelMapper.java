package com.burst.tunnel.dao;

import org.apache.ibatis.annotations.Mapper;

import java.util.List;
import java.util.Map;

/**
 * @描述: 隧道信息Dao层
 * @作者: 任琳珺
 * @时间: 2019/5/7 16:51
 */
//@Mapper
public interface TunnelMapper {

    void addTunnelBase(Map<String, Object> data);

    List<Map<String,Object>> queryTunnelBaseInfo(Map<String, Object> condition);
}
