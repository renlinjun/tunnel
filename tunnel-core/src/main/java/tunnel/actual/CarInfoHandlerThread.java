package tunnel.actual;

import com.burst.websocket.TunnelMessageHandler;
import com.tunnel.utils.ByteUtils;
import org.dom4j.DocumentException;
import tunnel.core.VehicleData;
/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/26 10:16
 */
public class CarInfoHandlerThread extends Thread {

    byte[] datas;

    public CarInfoHandlerThread(byte[] datas) {
        this.datas = datas;
    }
    /**
     * When an object implementing interface <code>Runnable</code> is used
     * to create a thread, starting the thread causes the object's
     * <code>run</code> method to be called in that separately executing
     * thread.
     * <p>
     * The general contract of the method <code>run</code> is that it may
     * take any action whatsoever.
     *
     * @see Thread#run()
     */
    @Override
    public void run() {
        //协议版本
        byte[] protocolByte = new byte[4];
        System.arraycopy(datas,0,protocolByte,0,4);
        int protocolVersion = ByteUtils.byteArrayToInt(protocolByte);
        //命令码
        byte[] commandCodeByte = new byte[4];
        System.arraycopy(datas,3,protocolByte,0,4);
        int commandCode = ByteUtils.byteArrayToInt(commandCodeByte);
        if(protocolVersion==2) { //协议版本为2则xml以xml方式描述
            XmlParse xmlParse = new XmlParse();
            if(118==commandCode) {//过车
                //过车数据内容
                byte[] dataContent = ByteUtils.byteCopy(datas,7,datas.length-8);
                //xml信息长度
                int xmllength = ByteUtils.byteArrayToInt(ByteUtils.byteCopy(dataContent,0,4));
                try {
                    //解析xml
                    VehicleData vehicleData = xmlParse.parse(ByteUtils.byteCopy(dataContent,3,xmllength));
                    //TODO 处理图像数据

                    //想客户端发送消息
                    TunnelMessageHandler.sendAllConnectedClient(vehicleData);
                } catch (DocumentException e) {
                    e.printStackTrace();
                }
            }

        }else if(protocolVersion==3) {//协议版本为3则xml以json方式描述

        }
    }
}
