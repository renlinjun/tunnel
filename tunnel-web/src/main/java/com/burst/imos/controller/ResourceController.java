package com.burst.imos.controller;

import com.burst.common.ResponseData;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * @描述: 组织、卡口、摄像机、照相机等资源控制层
 * @作者: REN
 * @时间: 2019/4/12 14:38
 */
@RestController
@RequestMapping
public class ResourceController {

    /**
     *
     * 功能描述: 查询卡口列表
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    @RequestMapping(value = "/listTollgate",method = RequestMethod.POST)
    public ResponseData listTollgate() {
        return new ResponseData();
    }

}
