package com.burst.test;

import com.burst.core.PushData;
import com.burst.core.VehicleData;
import com.burst.websocket.TunnelMessageHandler;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/5 22:27
 */
@Component
public class WebSocketTest implements ApplicationRunner {

    /**
     * Callback used to run the bean.
     *
     * @param args incoming application arguments
     * @throws Exception on error
     */
    @Override
    public void run(ApplicationArguments args) throws Exception {
        System.out.println("启动发送消息");
        int i = 0;
        while(true) {
            new SendThread(i++).start();
        }
    }
}

class SendThread extends Thread {

    int i;

    SendThread(int i) {
        this.i = i;
    }

    public void run() {
        PushData pushData = new PushData();
        pushData.setDataType(91);
        pushData.setJsonData(new VehicleData());
        TunnelMessageHandler.sendTextMessage2Client(pushData);
    }
}
