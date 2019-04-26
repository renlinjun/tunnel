package tunnel.actual;

import com.tunnel.utils.ByteUtils;
import org.dom4j.DocumentException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import tunnel.core.VehicleData;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/23 14:49
 */
@Component
public class ActualInfoSocketServer {

    //用一个总的map来存放数据
    public static HashMap<String, String> map = new HashMap<>();

    public void start() {
        try {
            ServerSocket server = new ServerSocket(8089);
            System.out.println("服务开启，监听端口8089");
            Socket socket = server.accept();
            System.out.println("接收到客户端连接：" + socket.getInetAddress().getHostAddress());
            DataInputStream dis = new DataInputStream(socket.getInputStream());
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            //开始接受数据
            while (true) {
                //读取包头
                int header = dis.readInt();
                //如果包头对不上，则可能是心跳或者其他数据
                if(header!=0x77aa77aa) {
                    continue;
                }
                //协议版本+命令码+数据内容的长度
                int datasLen = dis.readInt();
                byte[] datas = receive(dis,baos,datasLen);

                int tail = dis.readInt();
                //判断包尾是否正确
                if(tail!=0x77aa77aa) {
                    continue;
                }
                //启动线程去专门处理数据
                new CarInfoHandlerThread(datas).start();
                //重置字节输出流
                baos.reset();

            }
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    //读取datas数据
    private byte[] receive(DataInputStream dis, ByteArrayOutputStream baos,int datasLen) {
        byte[] buffer = new byte[1024*1024];
        try {
            do {
                int length = dis.read(buffer,0,datasLen);
                if(length==0) {
                    continue;
                }
                baos.write(buffer, 0, length);
                datasLen = datasLen -length;
            }while(datasLen>0);
        } catch (IOException e) {
            e.printStackTrace();
        }

        return baos.toByteArray();
    }

    public static void main(String args[]) {
        new ActualInfoSocketServer().start();
    }
}
