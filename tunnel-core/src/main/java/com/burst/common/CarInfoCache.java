package com.burst.common;

import java.util.HashMap;
import java.util.Map;

/**
 * @描述:  车辆信息常量，包括一些基本不会变化的数据
 * @作者: REN
 * @时间: 2019/4/27 00:50
 */
public class CarInfoCache {

    //车辆颜色对应关系
    public static Map<String,String> carColor = new HashMap<String,String>();
    //车辆类型
    public static Map<Integer,String> carType = new HashMap<Integer,String>();

    static {
        carColor.put("A","白色");
        carColor.put("B","灰色");
        carColor.put("C","黄色");
        carColor.put("D","粉色");
        carColor.put("E","红色");
        carColor.put("F","紫色");
        carColor.put("J","绿色");
        carColor.put("H","蓝色");
        carColor.put("I","棕色");
        carColor.put("J","黑色");
        carColor.put("K","橙色");
        carColor.put("L","青色");
        carColor.put("M","银色");
        carColor.put("N","银白");
        carColor.put("O","深色");
        carColor.put("P","浅色");
        carColor.put("Q","无色");
        carColor.put("Z","其他");


        carType.put(0,"未知");
        carType.put(1,"小型车");
        carType.put(2,"中型车");
        carType.put(3,"大型车");
        carType.put(4,"其他");
        carType.put(5,"行人");
        carType.put(6,"二轮车");
        carType.put(7,"三轮车");
        carType.put(8,"摩托车");
        carType.put(9,"拖拉机");
        carType.put(10,"农用车");
        carType.put(11,"轿车");
        carType.put(12,"SUV");
        carType.put(13,"面包车");
        carType.put(14,"小货车");
        carType.put(15,"中巴车/中型客车");
        carType.put(16,"大客车/大型客车");
        carType.put(17,"大货车/大型货车");
        carType.put(18,"皮卡车");
        carType.put(19,"MPV 商务车");
        carType.put(20,"非机动车");
        carType.put(21,"跑车");
        carType.put(22,"微型轿车");
        carType.put(23,"两厢轿车");
        carType.put(24,"三厢轿车");
        carType.put(25,"轻型客车");
        carType.put(26,"中型货车");
        carType.put(27,"挂车");
        carType.put(28,"槽罐车");
        carType.put(29,"洒水车");
        carType.put(99,"危化品车");
    }
}
