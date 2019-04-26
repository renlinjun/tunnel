package tunnel.actual;

import com.burst.websocket.TunnelMessageHandler;
import com.tunnel.utils.JSONUtils;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import tunnel.constants.DataType;
import tunnel.core.PushData;
import tunnel.core.VehicleData;

/**
 * @描述: 实时过车数据处理类
 * @作者: REN
 * @时间: 2019/4/24 14:39
 */
@Component
public class VehicleHandler {

    public void handler(VehicleData vehicleData) {
        PushData pushData = new PushData(DataType.PROC_TYPE_VEHICLE_DATA,vehicleData);
        //向连接的客户端推送数据
        TextMessage textMessage = new TextMessage(JSONUtils.beanToJson(pushData));
        TunnelMessageHandler.sendAllConnectedClient(textMessage);
    }
}
