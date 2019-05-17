package com.burst.runner;

import com.alibaba.fastjson.JSONObject;
import com.burst.common.ResponseData;
import com.burst.common.TunnelCache;
import com.burst.tunnel.service.ITunnelService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Map;

/**
 * @描述: 隧道信息初始化
 * @作者: REN
 * @时间: 2019/5/10 11:22
 */
@Component
@Order(10)
public class TunnelInfoRunner implements ApplicationRunner {

    @Autowired
    private ITunnelService tunnelService;

    /**
     * Callback used to run the bean.
     *
     * @param args incoming application arguments
     * @throws Exception on error
     */
    @Override
    public void run(ApplicationArguments args) throws Exception {
        ResponseData responseData = tunnelService.queryTunnelBase(new JSONObject());
        List<Map<String,Object>> tunnelList = (List)((Map)responseData.getData()).get("datalist");
        for(int i=0;i<tunnelList.size();i++) {
            Map<String,Object> tunnelInfo = tunnelList.get(i);
            TunnelCache.direct2Id.put(tunnelInfo.get("direction").toString(),tunnelInfo.get("id").toString());
            TunnelCache.directCode2Directory.put(Integer.parseInt(tunnelInfo.get("directionCode").toString()), tunnelInfo.get("direction").toString());
            TunnelCache.direct2DirectoryCode.put( tunnelInfo.get("direction").toString(),Integer.parseInt(tunnelInfo.get("directionCode").toString()));
        }

    }
}
