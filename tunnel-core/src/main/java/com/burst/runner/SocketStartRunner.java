package com.burst.runner;

import com.burst.socket.ActualInfoSocketServer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/17 20:49
 */
@Component
@Order(10)
public class SocketStartRunner implements ApplicationRunner {
    @Autowired
    private ActualInfoSocketServer server;
    /**
     * Callback used to run the bean.
     *
     * @param args incoming application arguments
     * @throws Exception on error
     */
    @Override
    public void run(ApplicationArguments args) throws Exception {
        server.start();
    }
}
