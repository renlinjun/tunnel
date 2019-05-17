package com.burst.utils;

import cn.hutool.core.util.StrUtil;
import com.burst.core.VehicleData;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/16 22:01
 */
public class CarOptionUtils {

    /**
     *
     * 功能描述: 是否是危化品车辆
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public static boolean isDanger(String status) {
        if(StrUtil.isEmpty(status)) {
            return false;
        }
        if(Integer.parseInt(status)==1) {
            return true;
        }
        return false;
    }
}
