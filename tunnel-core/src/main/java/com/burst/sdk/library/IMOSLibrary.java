package com.burst.sdk.library;

import com.burst.sdk.callBack.CallBackProcExPf;
import com.burst.sdk.callBack.CallBackProcPf;
import com.burst.sdk.struct.imos.*;
import com.sun.jna.Native;
import com.sun.jna.win32.StdCallLibrary;

import java.io.File;

/**
 * @描述: SDK对外开放的实现各种业务的同步接口
 *        包含 sdk_func.h、sdk_tollgate_func.h
 *        他们的实现都在imos_sdk.dll中
 * @作者: REN
 * @时间: 2019/1/3 15:32
 */
public interface IMOSLibrary extends StdCallLibrary {
    //String JNA_LIBRARY_NAME = "imos_sdk";
    String JNA_LIBRARY_NAME = "imos"+ File.separator+"redist"+File.separator+"imos_sdk";
    //设置为false
    String result = System.setProperty("jna.protected","false");
    String debug = System.setProperty("jna.debug_load", "true");
    //String encode = System.setProperty("jna.encoding", stringEncoding);
    //NativeLibrary JNA_NATIVE_LIB = NativeLibrary.getInstance("imos"+ File.separator+"redist"+File.separator+IMOSLibrary.JNA_LIBRARY_NAME);
    public static IMOSLibrary INSTANCE = Native.load(IMOSLibrary.JNA_LIBRARY_NAME, IMOSLibrary.class);
    /**
     * @描述：SDK初始化，详细的调用依赖关系请参见SDK说明文档。该模块包含初始化接口和清空接口。
     *
     * @defgroup
     *
     * @param:
     *        szServerAdd char[] 服务器地址
     *        ulServerPort unsigned 端口
     *        bUIFlag unsigned SDK在UI侧启动的标记，#true:1为在UI侧，#false:0为在服务器侧
     *        bXPFlag unsigned SDK是否包含有XP的标记, #BOOL_TRUE为包含(XP)播放器; #BOOL_FALSE为不包含XP(播放器)
     * @return:
     */
    int IMOS_Initiate(byte[] szServerAdd,int ulServerPort,int bUIFlag,int bXPFlag);

    /**
     *
     * 功能描述:
     *          加密
     * @auther: 任琳珺
     * @date:  2019-02-27
     * @param:
     *          pcInput 需要加密的字符串
     *          ulInLen 加密长度
     *          szOutput 加密后的字节数组
     * @return:
     */
    int IMOS_Encrypt(String pcInput,int ulInLen,byte[] szOutput);



    /**
     *
     *
     * @param:
     *      @param   pstUserLogIDInfo
     * @return:
     */
    int IMOS_CleanUp(TagUserLoginIDInfo.ByReference pstUserLogIDInfo);

    /**
     *
     * 功能描述: 
     * 
     * @auther:
     * @date:  
     * @param: 
     * @return: 
     */
    int IMOS_Login(byte[] szUserLoginName, byte[] szPassword, byte[] szIpAddress, TagLoginInfo.ByReference pstSDKLoginInfo);

    int IMOS_Logout(TagUserLoginIDInfo.ByReference pstUserLogIDInfo);

    /**
     *
     * 功能描述:
     *        登录服务端
     * @auther:
     * @date:
     * @param:
     *          szUserLoginName 用户名
     *          szPassword 密码
     *          szIpAddress ip地址
     *          szCltIpAddress 客户端地址
     *          pstSDKLoginInfo 登录成功后登录信息
     * @return:
     */
    int IMOS_LoginEx(byte[] szUserLoginName, byte[] szPassword, byte[] szIpAddress,String szCltIpAddress, TagLoginInfo.ByReference pstSDKLoginInfo);

    int IMOS_LogoutEx(TagUserLoginIDInfo.ByReference pstUserLogIDInfo);

    /**
     *
     * 功能描述:  订阅推送
     *
     * @auther: 任琳珺
     * @date:   2019-02-27
     * @param:
     *          pstSDKLoginInfo 当前登录用户信息
     *          ulSubscribePushType 订阅类型，取值范围为 @code{SDKDef.tagSubscribePushType}，目前支持ALL
     * @return:
     */
    int IMOS_SubscribePushInfo(TagLoginInfo.ByReference pstSDKLoginInfo,int ulSubscribePushType);


    /**
     *
     * 功能描述: 注册推送信息处理的回调函数。
     * 
     * @auther:
     * @date:  
     * @param:
     *          userLoginIDInfo 用户登录ID信息标识
     *          callback 回调函数处理指针
     * @return: 
     */
    int IMOS_RegCallBackPrcFunc(TagUserLoginIDInfo.ByReference userLoginIDInfo, CallBackProcPf callback);

    /**
     *
     * 功能描述: 对外提供给注册推送信息处理的回调函数。
     *          代码中获取推送消息用这个函数
     *
     * @auther:
     * @date:
     * @param:
     *          userLoginIDInfo 用户登录ID信息标识
     *          callback 回调函数处理指针
     * @return:
     */
    int IMOS_RegCallBackPrcFuncEx(TagUserLoginIDInfo.ByReference userLoginIDInfo, CallBackProcExPf callback);

    /**
     *
     * 功能描述: 查询卡口
     * 
     * @auther: 任琳珺
     * @date:  
     * @param:
     *      [it] userLoginIDInfo 用户登录信息
     *      [in] szTollgateCode 卡口编码
     *      [out] tagTollgateInfo 卡口信息
     * @return:
     * 返回如下结果：
     * 成功：
     * ERR_COMMON_SUCCEED
     * 失败：
     * 返回操作结果码，见错误码文件
     */
    int IMOS_QueryTollgate(TagUserLoginIDInfo.ByReference userLoginIDInfo, byte[] szTollgateCode, TagTollgateInfo.ByReference tagTollgateInfo);

    /**
     *
     * 功能描述: 查询组织下的卡口列表
     *
     * @auther: 任琳珺
     * @date: 2019-03-18
     * @param:  [in] pstUserLogIDInfo 用户登录ID信息标识
     *          [in] szOrgCode 组织编码
     *          [in] pstQueryCondition 通用查询条件(支持的查询条件可以为::NAME_TYPE[卡口名称])
     *          [in] pstQueryPageInfo 请求分页信息
     *          [out] pstRspPageInfo 响应分页信息
     *          [out] pstTollgateList 卡口列表
     * @return:
     */
    int IMOS_QueryTollgateList  (TagUserLoginIDInfo.ByReference userLoginIDInfo,
                                         byte[]  szOrgCode,
                                         TagCommonQueryCondition.ByReference pstQueryCondition,
                                         TagQueryPageInfo.ByReference pstQueryPageInfo,
                                         TagRspPageInfo.ByReference pstRspPageInfo,
                                         TagTollgateInfo.ByReference tollgateList
    );


    /**
     *
     * 功能描述: 完成用户保活功能
     *
     * @auther: 任琳珺
     * @date:  2019-02-28
     * @param:
     *         userLoginIDInfo 当前登录的用户
     * @return: 执行结果状态码
     */
    int IMOS_UserKeepAlive  (TagUserLoginIDInfo.ByReference userLoginIDInfo);

    /**
     *
     * 功能描述: 开启卡口实时监控
     *
     * @auther: 任琳珺
     * @date: 2019-02-28
     * @param:
     *    [in] pstUserLoginIDInfo 用户登录ID信息标识
     *    [in] szCameraCode 摄像机编码
     *    [in] szMonitorCode 在硬解实况中为监视器编码; 在软解实况中为窗格编码
     *    [in] ulStreamType 流类型, 取值为::IMOS_FAVORITE_STREAM_E
     *    [in] ulOperateCode 操作原因码, 取值为::CS_OPERATE_CODE_E

     * @return:
     */
    int IMOS_StartMonitor  (TagUserLoginIDInfo.ByReference userLoginIDInfo,
                            byte[]  szCameraCode,
                            byte[]  szMonitorCode,
                            int  ulStreamType,
                            int  ulOperateCode
    );

    /**
     *
     * 功能描述: 释放空闲的通道资源编码。
     * 
     * @auther: 任琳珺
     * @date:  2019-03-13
     * @param: [in] pstUserLoginIDInfo 用户登录ID信息标识。
                [out] pcChannelCodel 播放通道编码
     * @return:
     */
    void IMOS_FreeChannelCode(TagUserLoginIDInfo.ByReference userLoginIDInfo,
                                                    String  pcChannelCode
    );


    /**
     *
     * 功能描述:
     *  停止实时监控
     * @auther: 任琳珺
     * @date: 2019-03-13
     * @param:
     * [in] pstUserLoginIDInfo 用户登录ID信息标识
     * [in] szMonitorCode 在硬解实况中为监视器编码; 在软解实况中为窗格编码
     * [in] ulOperateCode 操作原因码, 取值为::CS_OPERATE_CODE_E
     * @return:
     */
    int IMOS_StopMonitor(TagUserLoginIDInfo.ByReference userLoginIdInfo,
                                                        byte[] szMonitorCode,
                                                        int ulOperateCode
    );



    /**
     *
     * 功能描述: 查询卡口摄像机列表
     * @auther: 任琳珺
     * @date:  2019-03-02
     * @param:  [in] pstUserLogIDInfo 用户登录ID信息标识
     *          [in] szTollgateCode 所属卡口编码
     *          [in] pstQueryCondition 通用查询条件
     *          [in] pstQueryPageInfo 请求分页信息
     *          [out] pstRspPageInfo 响应分页信息
     *          [out] pstTollgateVideoCameraItemList 摄像机列表
     * @return:
     */
    int IMOS_QueryTollgateVideoCameraList  (TagUserLoginIDInfo.ByReference userLoginIDInfo,
                                            byte[] szTollgateCode,
                                            TagCommonQueryCondition.ByReference pstQueryCondition,
                                            TagQueryPageInfo.ByReference pstQueryPageInfo,
                                            TagRspPageInfo.ByReference pstRspPageInfo,
                                            TagTollgateVideoCameraQueryItem.ByReference pstTollgateVideoCameraItemList
    );

    /**
     *
     * 功能描述: 查询卡口相机列表
     * 
     * @auther: 任琳珺
     * @date:  2019-03-02
     * @param:
     *  [in] pstUserLogIDInfo 用户登录ID信息标识
     *  [in] szTollgateCode 所属卡口编码
     *  [in] pstQueryCondition 通用查询条件
     *  [in] pstQueryPageInfo 请求分页信息
     * [out] pstRspPageInfo 响应分页信息
     * [out] pstTollgateCameraList 相机列表
     * @return:
     */
    int IMOS_QueryTollgateCameraList  (TagUserLoginIDInfo.ByReference userLoginIDInfo,
                                       byte[]  szTollgateCode,
                                       TagCommonQueryCondition.ByReference  pstQueryCondition,
                                       TagQueryPageInfo.ByReference  pstQueryPageInfo,
                                       TagRspPageInfo.ByReference pstRspPageInfo,
                                       TagTollgateCameraInfo.ByReference  pstTollgateCameraList
    );

    /**
     *
     * 功能描述: 查询卡口下车道列表
     *
     * @auther: 任琳珺
     * @date: 2019-03-18
     * @param:
     *
     * @return:
     */
    int IMOS_QueryTollgateLaneList(
                    TagUserLoginIDInfo.ByReference userLoginIDInfo,
                    String szTollgateCode,
                    TagCommonQueryCondition.ByReference  pstQueryCondition,
                    TagQueryPageInfo.ByReference  pstQueryPageInfo,
                    TagRspPageInfo.ByReference pstRspPageInfo,
                    TagTollgateLaneQueryItem[] tollgateLaneQueryItems
    );

    /**
     *
     * 功能描述: 开启照相机实时监控
     *
     * @auther: 任琳珺
     * @date: 2019-02-28
     * @param:
     *    [in] pstUserLoginIDInfo 用户登录ID信息标识
     *    [in] szCameraCode 照相机编码
     *    [in] szMonitorCode 在硬解实况中为监视器编码; 在软解实况中为窗格编码
     *    [in] ulOperateCode 操作原因码, 取值为::CS_OPERATE_CODE_E

     * @return:
     */
    int IMOS_StartTollgateMonitor  (TagUserLoginIDInfo.ByReference userLoginIDInfo,
                                                              byte[]  szCameraCode,
                                                              byte[]  szMonitorCode,
                                                              int  ulOperateCode
    );








    /**
     *
     * 功能描述:
     * 启动播放器组件。
     * @auther: 任琳珺
     * @date:  2018-03-13
     * @param: [IN]       pstUserLoginIDInfo  用户登录ID信息标识
     *          [IN]       ulPlayWndNum        播放窗格数量，具体取值视实际情况而定
     *          [IN][OUT]  pstPlayWndInfo      播放窗格编码结构体指针。
     * @return:
     */
    int IMOS_StartPlayer(TagUserLoginIDInfo.ByReference userLoginIdInfo,
                         int ulPlayWndNum,
                         TagPlayWndInfo.ByReference playWndInfo
    );

    /**
     *
     * 功能描述:
     *      停止播放器
     * @auther:  任琳珺
     * @date:  2019-03-13
     * @param:
     *  userLoginIdInfo 用户登录ID信息标识
     * @return:
     */
    int IMOS_StopPlayer  (TagUserLoginIDInfo.ByReference userLoginIdInfo);







}

