package com.burst.common;

import org.springframework.web.socket.WebSocketSession;

import java.util.*;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/12 19:25
 */
public class SessionCache {

    public static List<WebSocketSession> allConnedClient = new Vector<>();

    public static Map<Integer,WebSocketSession> sessionMap = new HashMap<>();
}
