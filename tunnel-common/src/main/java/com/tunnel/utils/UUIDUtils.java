package com.tunnel.utils;

import java.util.UUID;

/**
 * 生成UUID的工具
 * @author 任琳珺
 * @时间 2018-11-10
 */
public class UUIDUtils {

    /**
     * 产生UUID，并且将UUID中的“-”替换
     * @return
     */
    public static String getUUID(){
        return UUID.randomUUID().toString().replace("-","");
    }
}
