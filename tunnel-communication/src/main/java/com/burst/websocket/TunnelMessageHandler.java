package com.burst.websocket;


import cn.hutool.core.util.StrUtil;
import com.burst.common.SessionCache;
import com.bust.constants.WBMessageConverType;
import com.bust.utils.JSONUtils;
import com.bust.utils.URLTools;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.*;
import org.springframework.web.socket.handler.AbstractWebSocketHandler;

import java.io.IOException;
import java.util.*;

/**
 * @描述: 消息推送和接收处理类
 * @作者: 任琳珺
 * @时间: 2019/1/15 16:55
 */
@Component
public class TunnelMessageHandler extends AbstractWebSocketHandler {

    //连接建立
    public void afterConnectionEstablished(WebSocketSession session) throws Exception {
        String queryStr = session.getUri().getQuery();
        String connectTypeStr = URLTools.getUriParamByName(queryStr,"connectType");
        int connectType = 0;
        if(!StrUtil.isEmpty(connectTypeStr)) {
            connectType = Integer.parseInt(connectTypeStr);
        }

        session.getAttributes().put("uuid",UUID.randomUUID().toString());
        System.out.println("连接建立:[ip="+session.getRemoteAddress()+",id="+session.getId()+"]");
        SessionCache.allConnedClient.add(session);
        SessionCache.sessionMap.put(connectType,session);
    }

    //接收消息
    public void handleTextMessage(WebSocketSession session, TextMessage message) throws Exception {
        System.out.println("接收到消息Text。。。。");

    }

    public void handleBinaryMessage(WebSocketSession session, BinaryMessage message) throws Exception {
        System.out.println("接收到消息。。。。");
    }

    //连接断开以后
    public void afterConnectionClosed(WebSocketSession session, CloseStatus status) throws Exception {
        SessionCache.allConnedClient.remove(session);
        System.out.println("断开连接:"+session.getRemoteAddress()+";状态码："+status);
    }

    /**
     *
     * 功能描述:
     *      向所有连接的客户端发送消息
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public static void sendMessage2Client(AbstractWebSocketMessage message) {
        for (WebSocketSession session : SessionCache.allConnedClient) {
            synchronized (session) {
                if (session.isOpen()) {
                    try {
                        //发送推送消息
                        session.sendMessage(message);
                    } catch (IOException e) {
                        e.printStackTrace();
                        System.out.println("发送消息失败！");
                    }
                }
            }
        }
    }

    public static void sendMessageByClientType(AbstractWebSocketMessage message, int clientType)  {}

    /**
     *
     * 功能描述:
     *      向所有连接的客户端发送消息,
     * @auther:
     * @date:
     * @param:
     *      obj 发送的数据对象
     *      converType
     * @return:
     */
    public static void sendMessage2Client(Object obj, int converType) {
        AbstractWebSocketMessage message = null;
        if(converType == WBMessageConverType.TEXT_TYPE) {
            message = new TextMessage(JSONUtils.beanToJson(obj));
        }else if(converType == WBMessageConverType.BYTE_TYPE){
            message = new BinaryMessage((byte[])obj);
        }
        sendMessage2Client(message);
    }

    public static void sendByteMessage2Client(byte[] data) {
        sendMessage2Client(data,WBMessageConverType.BYTE_TYPE);
    }

    /**
     *
     * 功能描述:
     *      向所有连接的客户端发送消息
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    public static void sendTextMessage2Client(Object obj) {
        sendMessage2Client(obj,WBMessageConverType.TEXT_TYPE);
    }
}
