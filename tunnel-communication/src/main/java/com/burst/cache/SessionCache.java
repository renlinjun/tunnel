package com.burst.cache;

import org.springframework.web.socket.WebSocketSession;

import java.util.HashMap;
import java.util.Map;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/12 19:25
 */
public class SessionCache {

    public static Map<String,WebSocketSession> sessionMap = new HashMap<>();
}
