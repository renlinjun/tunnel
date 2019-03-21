package tunnel.imos;

import org.springframework.stereotype.Component;
import tunnel.constants.SystemConstants;
import tunnel.exception.CustomException;
import tunnel.sdk.constanst.IMOSErrCodeEnum;
import tunnel.sdk.library.IMOSLibrary;
import tunnel.sdk.struct.imos.TagLoginInfo;
import tunnel.sdk.struct.imos.TagUserLoginIDInfo;

/**
 * @描述: 登录功能操作类
 * @作者: REN
 * @时间: 2019/3/4 15:20
 */
@Component
public class ImosLogin {

    private static String username = "loadmin";
    private static String password = "imos_123";
    private static String serverAdd = "172.17.11.146";
    private static int  ulServerPort = 8800;

    /**
     *
     * 功能描述: 登录服务器
     *
     * @auther: 任琳珺
     * @date:  2019-03-04
     * @param:
     *          boolean isKeeyAlive 用户是否保活 true：保活 false：不保活
     * @return:
     *      用户登录信息指针
     */
    public static TagLoginInfo.ByReference login(boolean isKeepAlive) throws CustomException {
        return login(username,password,serverAdd,isKeepAlive);
    }

    /**
     *
     * 功能描述: 登录服务器
     *
     * @auther: 任琳珺
     * @date:  2019-03-04
     * @param:
     *          boolean isKeeyAlive 用户是否保活 true：保活 false：不保活
     * @return:
     *      用户登录信息指针
     */
    public static TagLoginInfo.ByReference login(String username,String password,String serverAdd,boolean isKeeyAlive) throws CustomException {
        Initiate();
        byte[] passwordByte = new byte[64];
        int result = IMOSLibrary.INSTANCE.IMOS_Encrypt(password,password.length(),passwordByte);
        TagLoginInfo.ByReference logInfoReference = new TagLoginInfo.ByReference();
        int loginResult = IMOSLibrary.INSTANCE.IMOS_LoginEx(username.getBytes(),passwordByte,serverAdd.getBytes(),"N/A",logInfoReference);

        if(loginResult != IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(loginResult,"登录失败",ImosLogin.class);
        }

        if(isKeeyAlive) {
            IMOSLibrary.INSTANCE.IMOS_UserKeepAlive(logInfoReference.getTagUserLoginIDInfoReference());
        }
        //保存登录信息
        SystemConstants.loginInfo = logInfoReference;
        TagUserLoginIDInfo.ByReference userIDInfoReference = logInfoReference.getTagUserLoginIDInfoReference();
        //保存登录人员信息
        SystemConstants.userIDInfoReference = userIDInfoReference;

        return logInfoReference;
    }

    /**
     *
     * 功能描述: 登录服务器，默认保活用户
     *
     * @auther: 任琳珺
     * @date:  2019-03-04
     * @param:
     * @return:
     */
    public static TagLoginInfo.ByReference login() throws CustomException {
        return login(true);
    }

    public static int Initiate() throws CustomException {
        //初始化
        int initResult = IMOSLibrary.INSTANCE.IMOS_Initiate(serverAdd.getBytes(),ulServerPort,1,0);
        if(initResult!=IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(initResult,"初始化失败",ImosLogin.class);
        }
        return initResult;
    }

    public static int Initiate(String serverAdd,int ulServerPort) throws CustomException {
        //初始化
        int initResult = IMOSLibrary.INSTANCE.IMOS_Initiate(serverAdd.getBytes(),ulServerPort,1,0);
        if(initResult!=IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(initResult,"初始化失败",ImosLogin.class);
        }
        return initResult;
    }

    /**
     *
     * 功能描述:
     *      退出登录
     * @auther: 任琳珺
     * @date: 2019-03-04
     * @param:
     * @return:
     */
    public static void loginOut(TagUserLoginIDInfo.ByReference userLoginIDInfoReference) throws CustomException {
        int result = IMOSLibrary.INSTANCE.IMOS_Logout(userLoginIDInfoReference);
        SystemConstants.loginInfo = null;
        SystemConstants.userIDInfoReference = null;
        if(result!=IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(result,"退出失败",ImosLogin.class);
        }
    }

    public static void loginOut() throws CustomException {
        int result = IMOSLibrary.INSTANCE.IMOS_Logout(SystemConstants.userIDInfoReference);
        SystemConstants.loginInfo = null;
        SystemConstants.userIDInfoReference = null;
        if(result!=IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(result,"退出失败",ImosLogin.class);
        }
    }
}
