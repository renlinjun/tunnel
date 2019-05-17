package com.burst.tunnel.service.impl;

import com.alibaba.fastjson.JSONObject;
import com.burst.common.CurrentCarInfosCache;
import com.burst.common.ResponseData;
import com.burst.tunnel.dao.TunnelMapper;
import com.burst.tunnel.service.ITunnelService;
import com.bust.constants.ResultConstants;
import com.bust.utils.UUIDUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Map;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/7 16:43
 */
@Component
public class TunnelServiceImpl implements ITunnelService {

    @Autowired
    private TunnelMapper tunnelMapper;
    @Autowired
    private CurrentCarInfosCache carInfosCache;

    @Override
    public ResponseData saveTunnelBase(JSONObject jsonInfo) {
        jsonInfo.put("id", UUIDUtils.getUUID());
        tunnelMapper.addTunnelBase(jsonInfo);
        return ResultConstants.SUCCESS_RESULT;
    }

    @Override
    public ResponseData queryTunnelBase(JSONObject condition) {
        List<Map<String,Object>> result = tunnelMapper.queryTunnelBaseInfo(condition);
        return new ResponseData(ResultConstants.SUCCESS_CODE,"查询成功",result);
    }

}
