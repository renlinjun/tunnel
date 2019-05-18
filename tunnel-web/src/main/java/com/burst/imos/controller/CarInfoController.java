package com.burst.imos.controller;

import com.burst.cache.RequestData;
import com.burst.cache.ResponseData;
import com.burst.exception.CustomException;
import com.burst.tunnel.service.ICarInfoService;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @描述: 车辆信息查询接口
 * @作者: REN
 * @时间: 2019/5/6 09:49
 */
@RestController
@RequestMapping("carInfo")
public class CarInfoController {

    //@Autowired
    private ICarInfoService carInfoService;
    @RequestMapping("/getCarInfo")
    public ResponseData getCurrentCarInfo(@RequestBody RequestData requestData) {
        try {
            return carInfoService.queryCurrentCarInfo(requestData.getData());
        } catch (CustomException e) {
            e.printStackTrace();
            return new ResponseData(-1,"查询失败");
        }
    }

    @RequestMapping("/getTunnelCarInfo")
    public ResponseData getAllCurrentCarInfo(@RequestBody RequestData requestData) {
        try {
            return carInfoService.getTunnelCarInfo();
        } catch (CustomException e) {
            e.printStackTrace();
            return new ResponseData(-1,"查询失败");
        }
    }

    /**
     *
     * 功能描述:
     *          根据隧道获取当前隧道内车辆
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    @RequestMapping("/getCarsByTunnel")
    public ResponseData getCurrentCarsByTunnel(@RequestBody RequestData requestData) {

        ResponseData responseData = null;

        try {
            responseData = carInfoService.getCurrentCarsByTunnel(requestData.getData());
        } catch (CustomException e) {
            e.printStackTrace();
        }
        return responseData;
    }
}
