package com.burst.test;

import com.burst.core.PushData;
import com.burst.core.VehicleData;
import com.burst.websocket.TunnelMessageHandler;
import com.bust.constants.DataType;
import com.bust.utils.JSONUtils;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;

import java.util.List;
import java.util.Random;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/5 22:27
 */
//@Component
//@Order(5)
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
        List<VehicleData>  datas = new XmlParseTmp().tempParse();
        System.out.println(datas.size()+"==========");
        Thread.sleep(60000);
        datas.stream().forEach(
                data-> {
                    System.out.println("启动发送消息线程");
                    try {
                        int randomInt = new Random().nextInt(10)+5;
                        Thread.sleep(randomInt*1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    new SendThread(data).start();
                }
        );
    }
}

class SendThread extends Thread {
    private VehicleData vehicleData;
    SendThread(VehicleData vehicleData) {
        this.vehicleData = vehicleData;
    }
    public void run() {
        send2Client(vehicleData, DataType.PROC_TYPE_VEHICLE_DATA);
    }

    public void send2Client(VehicleData vehicleData, int dataType) {
        PushData pushData = new PushData(dataType,vehicleData);
        //向连接的客户端推送数据
        TextMessage textMessage = new TextMessage(JSONUtils.beanToJson(pushData));
		System.out.println("向客户端推送数据："+pushData);
        TunnelMessageHandler.sendTextMessage2Client(textMessage);
    }


}
