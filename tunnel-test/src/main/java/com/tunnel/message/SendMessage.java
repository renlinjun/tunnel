package com.tunnel.message;

import com.burst.websocket.TunnelMessageHandler;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import java.io.IOException;
import java.util.List;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/8 19:26
 */
@SpringBootApplication
public class SendMessage {
    public static void  main(String args[]) {
        SpringApplication.run(SendMessage.class);
    }
}
