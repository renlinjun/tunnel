package com.bust.utils;

import java.util.Calendar;
import java.util.Date;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/2 21:39
 */
public class DateUtil {


    /**
     *
     * 功能描述:
     *          针对当前时间偏移若干秒后的时间
     * @auther:
     * @date:
     *
     * @param:
     *          second 偏差秒，正数表示之后多少秒
     *                        负数表示之前多少秒
     * @return:
     *          偏移后的时间
     */
    public static long secondOffset(int second) {
        Date date = new Date();
        return secondOffset(date.getTime(),second);
    }

    /**
     *
     * 功能描述:
     *          针对当前时间偏移若干秒后的时间
     * @auther:
     * @date:
     *
     * @param:
     *          second 偏差秒，正数表示之后多少秒
     *                        负数表示之前多少秒
     * @return:
     *          偏移后的时间
     */
    public static long secondOffset(long time ,int second) {
        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(time);
        calendar.add(Calendar.SECOND,second);
        return calendar.getTime().getTime();
    }

    /**
     *
     * 功能描述: 
     *          给定的时间是否在当前时间的多少秒之后
     * @auther:
     * @date:  
     * @param: 
     * @return: 
     */
    public static boolean isTimeAfterNowForSecond(long time,int second) {
        long afterTime = secondOffset(time,second);
        long now = new Date().getTime();
        return (afterTime - now >0);
    }
}
