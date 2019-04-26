package com.tunnel.utils;

import java.util.HashMap;
import java.util.Map;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/12 19:19
 */
public class URLTools {

    /**
     *
     * 功能描述:  获取URI上的所有参数
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public static Map<String,String> getUriParams(String queryStr) {
        String[] queryArray = queryStr.split("&");
        Map<String,String> paramerMap = new HashMap<>();
        for(int i=0;i<queryArray.length;i++) {
            String param = queryArray[i];
            String[] str = param.split("=");
            paramerMap.put(str[0],str[1]);
        }
        return paramerMap;
    }

    /**
     *
     * 功能描述:  获取URI上指定参数的值
     *
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public static String getUriParamByName(String queryStr,String paramName) {
        return getUriParams(queryStr).get(paramName);
    }
}
