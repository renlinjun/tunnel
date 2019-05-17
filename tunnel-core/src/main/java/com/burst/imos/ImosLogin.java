package com.burst.imos;

import com.burst.common.SystemCache;
import com.burst.config.VmServerProperties;
import com.burst.exception.CustomException;
import com.burst.sdk.constanst.IMOSErrCodeEnum;
import com.burst.sdk.library.IMOSLibrary;
import com.burst.sdk.struct.imos.TagLoginInfo;
import com.burst.sdk.struct.imos.TagUserLoginIDInfo;
import org.springframework.beans.factory.annotation.Autowired;

/**
 * @描述: 登录功能操作类
 * @作者: REN
 * @时间: 2019/3/4 15:20
 */
//@Component
public class ImosLogin {

    @Autowired
    private VmServerProperties vmServerProperties;


    /*private String username = "loadmin";
    private String password = "imos_123";
    private String serverAdd = "172.17.11.146";
    private int  ulServerPort = 8800;*/

    private String username = vmServerProperties.getUsername();
    private String password = vmServerProperties.getPassword();
    private String serverAdd = vmServerProperties.getAddress();
    private int  ulServerPort = vmServerProperties.getPort();


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
    public TagLoginInfo.ByReference login(boolean isKeepAlive) throws CustomException {
        return login(vmServerProperties.getUsername(),vmServerProperties.getPassword(),vmServerProperties.getAddress(),isKeepAlive);
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
    public TagLoginInfo.ByReference login(String username,String password,String serverAdd,boolean isKeeyAlive) throws CustomException {
        Initiate();
        byte[] passwordByte = new byte[64];
        IMOSLibrary.INSTANCE.IMOS_Encrypt(password,password.length(),passwordByte);
        TagLoginInfo.ByReference logInfoReference = new TagLoginInfo.ByReference();
        int loginResult = IMOSLibrary.INSTANCE.IMOS_LoginEx(username.getBytes(),passwordByte,serverAdd.getBytes(),"N/A",logInfoReference);

        if(loginResult != IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(loginResult,"登录失败",ImosLogin.class);
        }

        /*if(isKeeyAlive) {
            IMOSLibrary.INSTANCE.IMOS_UserKeepAlive(logInfoReference.getTagUserLoginIDInfoReference());
        }*/
        //保存登录信息
        SystemCache.loginInfo = logInfoReference;
        TagUserLoginIDInfo.ByReference userIDInfoReference = logInfoReference.getTagUserLoginIDInfoReference();
        //保存登录人员信息
        SystemCache.userIDInfoReference = userIDInfoReference;

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
    public TagLoginInfo.ByReference login() throws CustomException {
        return login(true);
    }

    public int Initiate() throws CustomException {
        //初始化
        int initResult = IMOSLibrary.INSTANCE.IMOS_Initiate(serverAdd.getBytes(),ulServerPort,1,0);
        if(initResult!= IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(initResult,"初始化失败",ImosLogin.class);
        }
        return initResult;
    }

    public int Initiate(String serverAdd,int ulServerPort) throws CustomException {
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
    public void loginOut(TagUserLoginIDInfo.ByReference userLoginIDInfoReference) throws CustomException {
        int result = IMOSLibrary.INSTANCE.IMOS_Logout(userLoginIDInfoReference);
        SystemCache.loginInfo = null;
        SystemCache.userIDInfoReference = null;
        if(result!=IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(result,"退出失败",ImosLogin.class);
        }
    }

    public void loginOut() throws CustomException {
        int result = IMOSLibrary.INSTANCE.IMOS_Logout(SystemCache.userIDInfoReference);
        SystemCache.loginInfo = null;
        SystemCache.userIDInfoReference = null;
        if(result!=IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(result,"退出失败",ImosLogin.class);
        }
    }
}
