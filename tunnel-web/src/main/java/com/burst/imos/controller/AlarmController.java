package com.burst.imos.controller;

import com.burst.common.RequestData;
import com.burst.common.ResponseData;
import com.bust.constants.ResultConstants;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/14 16:22
 */
@RestController
@RequestMapping("alarm")
public class AlarmController {

    /**
     *
     * 功能描述:
     *          更新告警信息
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    @RequestMapping("/dealAlarm")
    public ResponseData dealAlarm(@RequestBody RequestData requestData) {
        return ResultConstants.SUCCESS_RESULT;
    }

    /**
     *
     * 功能描述:
     *          处理告警
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    @RequestMapping("/updateAlarm")
    public ResponseData updateAlarm(@RequestBody RequestData requestData) {

        return ResultConstants.SUCCESS_RESULT;
    }

}
