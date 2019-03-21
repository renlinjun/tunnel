package com.tunnel.message;

import com.burst.websocket.TunnelMessageHandler;
import com.tunnel.utils.JSONUtils;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;
import tunnel.sdk.struct.imos.*;

import java.io.IOException;
import java.util.List;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/8 20:16
 */
@Component
public class CustomApplicationRunner implements  ApplicationRunner {
    @Override
    public void run(ApplicationArguments args) throws Exception {

        new Thread(()->{
            try {
                Thread.sleep(10000);
                int i = 1;
                while (true) {
                    i++;
                    Thread.sleep(1000);
                    List<WebSocketSession> connedClients = TunnelMessageHandler.connedClient;

                    for (WebSocketSession session : connedClients) {
                        //TagVehicleRealTimeData.ByValue vehicleRealTimeData = new TagVehicleRealTimeData.ByValue();
                        TagVehicleData.ByValue stVehicleData = new TagVehicleData.ByValue();
                        tagVideoInChannel.ByReference tagVideoInChannel = new tagVideoInChannel.ByReference();
                        //TagVehicleData stVehicleData = vehicleRealTimeData.stVehicleData;
                        stVehicleData.szLicensePlatCode = PlateNumber.createNum();
                        String jsonStr = JSONUtils.beanToJson(stVehicleData);
                        session.sendMessage(new TextMessage(jsonStr));
                    }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }
}
