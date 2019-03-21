package com.burst.send;

import com.burst.websocket.TunnelMessageHandler;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/1/17 15:34
 */
@Component
public class SendTest {
    @Autowired
    private TunnelMessageHandler textMessageHandler;

    public void send() {
        //textMessageHandler.handleTextMessage();
}




}
