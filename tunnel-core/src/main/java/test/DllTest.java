package test;

import tunnel.sdk.constanst.IMOSErrCodeEnum;
import tunnel.sdk.library.IMOSLibrary;
import tunnel.sdk.library.SDKLibrary;
import tunnel.sdk.struct.imos.TagLoginInfo;

/**
 * @描述:n
 * @作者: REN
 * @时间: 2018/12/25 16:55
 */
public class DllTest {

    public static void main(String args[]) {/*
        System.out.println("两个数相加的和为："+ TestLibrary.INSTANCE.add(5,6));
        TestLibrary.INSTANCE.addArray(new IntByReference(5),new IntByReference(6),new IntByReference(7),5);
        System.out.println("两个字符连接为："+ TestLibrary.INSTANCE.stringFun("aaa","bbb"));*/
        String username = "loadmin";
        String password = "imos_123";
        byte[] passwordByte = new byte[64];
        int result = IMOSLibrary.INSTANCE.IMOS_Encrypt(password,password.length(),passwordByte);
        System.out.println("加密后为："+ result);
        System.out.println(new String(passwordByte));

        String serverAdd = "172.17.11.146";


        int initResult = IMOSLibrary.INSTANCE.IMOS_Initiate(serverAdd.getBytes(),8800,1,0);
        System.out.println("初始化结果:"+initResult+"---是否成功："+(initResult== IMOSErrCodeEnum.ERR_COMMON_SUCCEED));
        /*System.out.printf("十六进制：");
        System.out.printf("%x\n",initResult);
        if(initResult==IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            TagLoginInfo.ByReference logInfoReference = new TagLoginInfo.ByReference();
            int loginResult = IMOSLibrary.INSTANCE.IMOS_LoginEx(username.getBytes(),passwordByte,serverAdd.getBytes(),"N/A",logInfoReference);
            //IMOSLibrary.INSTANCE.IMOS_CleanUp()
            System.out.println(new String(logInfoReference.szOrgCode));
            System.out.println(loginResult);
        }*/

    }
}
