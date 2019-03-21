package tunnel.sdk.library;

import com.sun.jna.Native;
import com.sun.jna.NativeLibrary;
import com.sun.jna.win32.StdCallLibrary;
import tunnel.sdk.callBack.CallBackProcPf;
import tunnel.sdk.struct.imos.TagLoginInfo;
import tunnel.sdk.struct.imos.TagUserLoginIDInfo;

import java.io.File;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/1/4 16:31
 */
public interface SDKLibrary extends StdCallLibrary {
    public static final String JNA_LIBRARY_NAME = "imos_sdk";
    String result = System.setProperty("jna.protected","false");
    String debug = System.setProperty("jna.debug_load", "true");
    public static final NativeLibrary JNA_NATIVE_LIB = NativeLibrary.getInstance("imos"+ File.separator+"redist"+File.separator+IMOSLibrary.JNA_LIBRARY_NAME);
    public static final SDKLibrary INSTANCE = Native.load(SDKLibrary.JNA_LIBRARY_NAME, SDKLibrary.class);

    /**
     * @描述：SDK初始化，详细的调用依赖关系请参见SDK说明文档。该模块包含初始化接口和清空接口。
     *
     * @defgroup
     *
     * @param:
     *        szServerAdd char[] 服务器地址
     *        ulServerPort unsigned 端口
     *        bUIFlag unsigned SDK在UI侧启动的标记，#true为在UI侧，#false为在服务器侧
     *        bXPFlag unsigned SDK是否包含有XP的标记, #BOOL_TRUE为包含(XP)播放器; #BOOL_FALSE为不包含XP(播放器)
     * @return:
     */
    int IMOS_Initiate(byte[] szServerAdd,int ulServerPort,int bUIFlag,int bXPFlag);

    /**
     *
     *
     * @param:
     *      @param   pstUserLogIDInfo
     * @return:
     */
    int IMOS_CleanUp(TagUserLoginIDInfo.ByReference pstUserLogIDInfo);

    int IMOS_Login(byte[] szUserLoginName, byte[] szPassword, byte[] szIpAddress, TagLoginInfo.ByReference pstSDKLoginInfo);

    int IMOS_Logout(TagUserLoginIDInfo.ByReference pstUserLogIDInfo);

    int IMOS_LoginEx(byte[] szUserLoginName, byte[] szPassword, byte[] szIpAddress,byte[] szCltIpAddress, TagLoginInfo.ByReference pstSDKLoginInfo);

    int IMOS_LogoutEx(TagUserLoginIDInfo.ByReference pstUserLogIDInfo);

    int IMOS_Encrypt(String pcInput,int ulInLen,byte[] szOutput);


    int IMOS_RegCallBackPrcFunc(TagUserLoginIDInfo userLoginIDInfo, CallBackProcPf callback);



}

