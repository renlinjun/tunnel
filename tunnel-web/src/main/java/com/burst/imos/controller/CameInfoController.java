package com.burst.imos.controller;

import com.alibaba.fastjson.JSONObject;
import com.burst.cache.RequestData;
import com.burst.cache.ResponseData;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/9 10:36
 */
@RestController
@RequestMapping("came")
public class CameInfoController {
    //@Autowired
    //private ICamService camService;

    /***
     * 增加摄像机
     * @param requestData
     * @return
     */
    @RequestMapping(value = "/addCame",method = RequestMethod.POST)
    public ResponseData addCame(@RequestBody RequestData requestData) {
        JSONObject json = requestData.getData();
        //return camService.addCam(json);
        return null;
    }

    /**
     *
     * 功能描述:
     *     查询摄像机列表树
     * @auther: 任琳珺
     * @date:  2019-05-09
     * @param:
     * @return:
     */
    @RequestMapping(value = "/listCameTree",method = RequestMethod.POST)
    public ResponseData listCameTree(@RequestBody RequestData requestData) {
        JSONObject json = requestData.getData();
        //return camService.listCameTree(json);
        return null;
    }
}
