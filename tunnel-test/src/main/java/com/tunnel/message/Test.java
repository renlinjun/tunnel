package com.tunnel.message;

import tunnel.sdk.library.IMOSLibrary;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/21 10:28
 */
public class Test {

    public static  void main(String args[]) {
        IMOSLibrary.INSTANCE.IMOS_Initiate("172.17.11.146".getBytes(),8800,1,0);
    }
}
