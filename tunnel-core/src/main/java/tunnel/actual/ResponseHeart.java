package tunnel.actual;


import com.tunnel.utils.ByteUtils;

import java.io.DataOutputStream;
import java.io.IOException;

/**
 * 响应接收到的心跳包
 * @author guozhiyuna W7163
 * @create 2019-1-27 10:19
 **/
public class ResponseHeart {

    /**
     * 模拟服务端组建反馈心跳包数据
     * @param packageHead
     * @param protocolVersion
     * @param commandCode
     * @param camID
     * @param packageTail
     */
    private static byte[] buildResponse(int packageHead, int protocolVersion, int commandCode, String camID, int packageTail) throws IOException {
        /**
         * 1. 计算心跳反馈包
         */
        //包头
        byte [] head = ByteUtils.intToByteArray(packageHead);
        //协议版本
        byte [] version = ByteUtils.intToByteArray(protocolVersion);
        //命令码
        byte [] command = ByteUtils.intToByteArray(commandCode);
        //相机编号
        byte[] cam = new byte[32];
        System.arraycopy(camID.getBytes(),0,cam,0,camID.getBytes().length);
        //包尾
        byte [] tail = ByteUtils.intToByteArray(packageTail);
        //计算消息总长度
        //协议版本长度 + 命令码长度 + 相机ID长度
        int packageLength = version.length + command.length + cam.length;
        //数据包长度
        byte [] pkglen = ByteUtils.intToByteArray(packageLength);
        //包头长度 + 数据包长度 + 数据包内容的长度 + 包尾长度
        byte [] totalLength = new byte[52];

        /**
         * 2. 组装包
         */
        System.arraycopy(head,0,totalLength,0,4);
        System.arraycopy(pkglen,0,totalLength,4,4);
        System.arraycopy(version,0,totalLength,8,4);
        System.arraycopy(command,0,totalLength,12,4);
        System.arraycopy(cam,0,totalLength,16,cam.length);
        System.arraycopy(tail,0,totalLength,16+cam.length,4);
        return totalLength;
    }

    /**
     * 反馈心跳包
     * @param outputStream
     */
    public static void send(DataOutputStream outputStream){

        //注意：该Demo仅演示如何发送宇视人脸协议数据，请根据实际情况，灵活使用。
        /**
         * 1. 模拟数据,并填写基本信息
         */
        //定义宇视协议包头 固定值
        int packageHead = 0x77aa77aa;
        //定义协议版本号 现仅支持xml格式 赋值：2 固定值
        int protocolVersion = 2;
        //定义命令码 发送人脸协议的命令码
        int command = 501;
        //卡口相机编号
        String camID = ActualInfoSocketServer.map.get("cam");
        //定义宇视协议包尾 固定值
        int packageTail = 0x77ab77ab;
        byte[] alive = new byte[52];
        System.out.println("反馈数据: 命令码 "+command+" 卡口或相机编号 "+camID);
        try {
            alive = buildResponse(packageHead, protocolVersion, command, camID, packageTail);
        } catch (IOException e) {
            e.printStackTrace();
        }
        /**
         * 4. 反馈心跳包
         */
        try {
            outputStream.write(alive,0,alive.length);
            outputStream.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 接收心跳数据包并解析
     * @param heart
     * @param dos
     */
    public static void receiveHeartAndResponse(byte[] heart, DataOutputStream dos){
        if(heart.length == 0) return;
        System.out.println("-----收到心跳包-----");
        byte[] command = new byte[4];
        byte[] cam = new byte[32];
        System.arraycopy(heart,12,command,0,4);
        System.arraycopy(heart,16,cam,0,32);
        int commandCode = ByteUtils.byteArrayToInt(command);
        String camID = new String(cam);
        ActualInfoSocketServer.map.put("cam",camID);
        if(commandCode == 101){
            send(dos);
            System.out.println("-----心跳已反馈-----");
            System.out.println();
        }
    }
}
