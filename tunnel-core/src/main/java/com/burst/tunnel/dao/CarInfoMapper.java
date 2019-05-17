package com.burst.tunnel.dao;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import com.burst.core.VehicleData;
import org.apache.ibatis.annotations.Mapper;

/**
 * @描述: 实时数据Dao层
 * @作者: 任琳珺
 * @时间: 2019/4/27 02:26
 */
@Mapper
public interface CarInfoMapper extends BaseMapper<VehicleData> {


}
