package com.bust.utils;

import sun.misc.BASE64Encoder;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/18 12:22
 */
public class ByteUtils {

    public static byte[] intToByteArray(int i) {
        byte[] result = new byte[4];
        // 由高位到低位
        result[0] = (byte) ((i >> 24) & 0xFF);
        result[1] = (byte) ((i >> 16) & 0xFF);
        result[2] = (byte) ((i >> 8) & 0xFF);
        result[3] = (byte) (i & 0xFF);
        return result;
    }

    /**
     * byte[]转int
     * @param b
     * @return
     */
    public static int byteArrayToInt(byte[] b) {
        int value = 0;
        for(int i=0;i<b.length;i++){
            int shift = (4-1-i)*8;
            value += (b[i]&0x000000FF) << shift;
        }
        return value;
    }

    /**
     * byte[]转int
     * @param b
     * @return
     */
    public static int byteArrayToInt(byte[] b,int off) {
        int value = 0;
        for(int i=off;i<(off+4);i++){
            int shift = (4-1-i)*8;
            value += (b[i]&0x000000FF) << shift;
        }
        return value;
    }

    public static byte[] byteCopy(byte[] src,int start,int length) {
        byte[] des = new byte[length];
        System.arraycopy(src,start,des,0,length);
        return des;
    }


    public static String ImageToBase64ByLocal(String imgFile) {
        // 将图片文件转化为字节数组字符串，并对其进行Base64编码处理
        InputStream in = null;
        byte[] data = null;
        // 读取图片字节数组
        try {
            in = new FileInputStream(imgFile);
            data = new byte[in.available()];
            in.read(data);
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        // 对字节数组Base64编码
        BASE64Encoder encoder = new BASE64Encoder();

        return encoder.encode(data);// 返回Base64编码过的字节数组字符串
    }

    public static String bytesToHexString(byte[] packageFooter) {
        StringBuffer sb = new StringBuffer(packageFooter.length);
        String sTmp;
        for (int i = 0; i < packageFooter.length; i++) {
            sTmp = Integer.toHexString(0xFF & packageFooter[i]);
            if (sTmp.length() < 2)
                sb.append(0);
            sb.append(sTmp.toUpperCase());
        }
        return sb.toString();
    }
}
