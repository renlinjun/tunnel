package com.burst.cache;

import java.util.HashMap;
import java.util.Map;

/**
 * @描述: 隧道相关常量
 * @作者: REN
 * @时间: 2019/5/2 22:11
 */
public class TunnelCache {

    //隧道方向与隧道ID对应关系
    public static Map<String,String> direct2Id = new HashMap<>();
    //隧道ID与隧道方向对应关系
    public static Map<String,String> Id2direct = new HashMap<>();
    //隧道方向代码与隧道方向对应关系
    public static Map<Integer,String> directCode2Directory = new HashMap<>();
    //隧道方向与隧道代码对应关系
    public static Map<String,Integer> direct2DirectoryCode = new HashMap<>();
}
