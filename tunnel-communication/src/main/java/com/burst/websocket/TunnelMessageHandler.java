package com.burst.websocket;


import com.tunnel.utils.JSONUtils;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.*;
import org.springframework.web.socket.handler.AbstractWebSocketHandler;

import javax.xml.soap.Text;
import java.io.IOException;
import java.util.*;

/**
 * @描述: 消息推送和接收处理类
 * @作者: 任琳珺
 * @时间: 2019/1/15 16:55
 */
@Component
public class TunnelMessageHandler extends AbstractWebSocketHandler {

    public static List<WebSocketSession> connedClient = new ArrayList<>();

    //连接建立
    public  void afterConnectionEstablished(WebSocketSession session) throws Exception {
        session.getAttributes().put("uuid",UUID.randomUUID().toString());
        System.out.println("连接建立:[ip="+session.getRemoteAddress()+",id="+session.getId()+"]");
        String uid = (String) session.getAttributes().get("uuid");
        System.out.println("uuid:"+uid);
        connedClient.add(session);
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
        connedClient.remove(session);
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
    public static void sendAllConnectedClient(AbstractWebSocketMessage message) {
        for (WebSocketSession session : connedClient) {
            if(session.isOpen()) {
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
