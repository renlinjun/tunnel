package tunnel.imos;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import tunnel.bayonet.BayonetHandler;
import tunnel.constants.SystemConstants;
import tunnel.exception.CustomException;
import tunnel.sdk.callBack.CallBackProcExPf;
import tunnel.sdk.callBack.XpPlayerTranscodeCallbackPF;
import tunnel.sdk.callBack.impl.CallBackProcExPfImpl;
import tunnel.sdk.callBack.impl.XpPlayerTranscodeCallbackPFImpl;
import tunnel.sdk.constanst.IMOSDefLibrary;
import tunnel.sdk.constanst.IMOSErrCodeEnum;
import tunnel.sdk.constanst.SDKDef;
import tunnel.sdk.library.IMOSLibrary;
import tunnel.sdk.struct.imos.*;

import static tunnel.sdk.constanst.IMOSDefLibrary.IMOS_CODE_TYPE_UTF8;
import static tunnel.sdk.constanst.SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM;

/**
 * @描述: 宇视平台对卡口功能的实现
 * @作者: REN
 * @时间: 2019/2/27 11:22
 */
@Component
public class ImosHandler implements BayonetHandler {

    @Autowired
    private CallBackProcExPf callBackProcExPf;

    @Override
    public void init() throws CustomException {
        //初始化
        ImosLogin.Initiate();
    }

    @Override
    public void actualInfo() throws CustomException {
        //获取登录信息
        TagLoginInfo.ByReference loginInfoReference = SystemConstants.loginInfo;
        if(loginInfoReference==null) {
            throw new CustomException(-1,"获取登录信息失败!");
        }
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemConstants.userIDInfoReference;
        //订阅推送
        IMOSLibrary.INSTANCE.IMOS_SubscribePushInfo(loginInfoReference, SDKDef.tagSubscribePushType.SUBSCRIBE_PUSH_TYPE_ALL);
        //注册消息推送回调函数
        //CallBackProcExPf callBackProcExPf = new CallBackProcExPfImpl();
        IMOSLibrary.INSTANCE.IMOS_RegCallBackPrcFuncEx(userIDInfoReference,callBackProcExPf);
        //查询卡口
        TagTollgateInfo tagTollgateInfo = new TagTollgateInfo();
        //TODO 卡口编码暂时为 "1-15-1"
        System.out.println();
        IMOSLibrary.INSTANCE.IMOS_QueryTollgate(userIDInfoReference,"1-15-1".getBytes(),tagTollgateInfo);

        if(tagTollgateInfo.ulIsOnline != IMOSDefLibrary.IMOS_DEV_STATUS_ONLINE) {
            throw  new CustomException(-1,"卡口["+"编号：1-15-1"+",名称："+tagTollgateInfo.szTollgateName+"]处于离线状态");
        }
        /* 如果设备在线 */
        //卡口编码
        byte[] szTollgageCode = tagTollgateInfo.szTollgateCode;
        System.out.println("卡口编码字节："+szTollgageCode);
        System.out.println("卡口编码字符串："+new String(szTollgageCode));
        /* 开始查询摄像头列表，并开启视频流 *****/

        //取出所有的摄像机
        TagTollgateVideoCameraQueryItem[] videoCameraQueryItems = listVideoCameraByBayonet(new String(szTollgageCode));
        for(int i=0;i<videoCameraQueryItems.length;i++) {
            TagTollgateVideoCameraQueryItem videoCamera = videoCameraQueryItems[i];
            //开启视频流
            IMOSLibrary.INSTANCE.IMOS_StartMonitor(userIDInfoReference,new String(videoCamera.szCameraCode),IMOS_CODE_TYPE_UTF8.getBytes(),
                                                SDKDef.tagIMOSFavoriteStream.IMOS_FAVORITE_STREAM_ANY, SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);
        }

        /* 摄像头列表查询结束  ****/

        /* 开始查询照相机列表，并开启照片流  */

        TagTollgateCameraInfo[] cameraInfos = listCameraByBayonet(new String(szTollgageCode));
        for(int i=0;i<cameraInfos.length;i++) {
            TagTollgateCameraInfo camera = cameraInfos[i];
            //开启视频流
            IMOSLibrary.INSTANCE.IMOS_StartTollgateMonitor(userIDInfoReference,camera.szCameraCode,IMOS_CODE_TYPE_UTF8.getBytes(),
                    SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);
        }
    }

    @Override
    public TagTollgateVideoCameraQueryItem[] listVideoCameraByBayonet(String szTollgageCode) throws CustomException {
        //查询条件，目前没有查询条件，因此该出为0个查询条件
        TagCommonQueryCondition.ByReference commonQueryCondition = new TagCommonQueryCondition.ByReference();
        commonQueryCondition.ulItemNum = 0;
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfo = new TagQueryPageInfo.ByReference();
        queryPageInfo.ulPageFirstRowNumber = 0;
        queryPageInfo.bQueryCount = 0;
        queryPageInfo.ulPageRowNum = IMOS_PAGE_QUERY_ROW_MAX_NUM;
        //响应的分页信息
        TagRspPageInfo.ByReference respPageInfoReference = new TagRspPageInfo.ByReference();
        //返回的摄像机列表,返回的是一个起始地址
        TagTollgateVideoCameraQueryItem.ByReference videoCameItem = new TagTollgateVideoCameraQueryItem.ByReference();
        int queryResult = IMOSLibrary.INSTANCE.IMOS_QueryTollgateVideoCameraList(SystemConstants.userIDInfoReference,new String(szTollgageCode),commonQueryCondition,queryPageInfo,respPageInfoReference,videoCameItem);

        if(queryResult!= IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(queryResult,"查询摄像机列表失败");
        }
        //将结构体指针转换为结构体
        TagRspPageInfo tagRspPageInfo = new TagRspPageInfo(respPageInfoReference.getPointer());
        //查询出的摄像头数量
        int resultCount = tagRspPageInfo.ulTotalRowNum;
        //取出所有的摄像机
        TagTollgateVideoCameraQueryItem[] videoCameraQueryItems = (TagTollgateVideoCameraQueryItem[]) videoCameItem.toArray(resultCount);
        return videoCameraQueryItems;
    }

    @Override
    public TagTollgateCameraInfo[] listCameraByBayonet(String szTollgageCode) throws CustomException {
        //查询条件，目前没有查询条件，因此该出为0个查询条件
        TagCommonQueryCondition.ByReference commonQueryConditionCamera = new TagCommonQueryCondition.ByReference();
        commonQueryConditionCamera.ulItemNum = 0;
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfo = new TagQueryPageInfo.ByReference();
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfoCamera = new TagQueryPageInfo.ByReference();
        queryPageInfo.ulPageFirstRowNumber = 0;
        queryPageInfo.bQueryCount = 0;
        queryPageInfo.ulPageRowNum = IMOS_PAGE_QUERY_ROW_MAX_NUM;
        //响应的分页信息
        TagRspPageInfo.ByReference respPageInfoReferenceCamera = new TagRspPageInfo.ByReference();
        TagTollgateCameraInfo.ByReference cameraInfoReference = new TagTollgateCameraInfo.ByReference();
        int queryCameraResult = IMOSLibrary.INSTANCE.IMOS_QueryTollgateCameraList(SystemConstants.userIDInfoReference,szTollgageCode.getBytes(),commonQueryConditionCamera,
                queryPageInfoCamera,respPageInfoReferenceCamera,cameraInfoReference);

        if(queryCameraResult!= IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(queryCameraResult,"查询照相机失败");
        }

        TagTollgateCameraInfo[] cameraInfos = (TagTollgateCameraInfo[]) cameraInfoReference.toArray(respPageInfoReferenceCamera.ulTotalRowNum);
        return cameraInfos;
    }

    @Override
    public void startLiveVideoStream() throws CustomException {
        //如果未获取到登录信息，则登录服务器
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemConstants.userIDInfoReference;
        if(userIDInfoReference==null) {
            ImosLogin.login(true);
        }
        //通道编码
        String channelCode = new String();
        IMOSLibrary.INSTANCE.IMOS_GetChannelCode(userIDInfoReference,channelCode);
        //播放窗格编码结构体指针
        TagPlayWndInfo.ByReference playWndInfo = new TagPlayWndInfo.ByReference();
        IMOSLibrary.INSTANCE.IMOS_StartPlayer(userIDInfoReference,1,playWndInfo);
        //获取视频流数据
        XpPlayerTranscodeCallbackPF xpPlayerTranscodeCallbackPF = new XpPlayerTranscodeCallbackPFImpl();
        IMOSLibrary.INSTANCE.IMOS_SetDecodeVideoDataCB(userIDInfoReference,channelCode,xpPlayerTranscodeCallbackPF,1,0);


    }

    @Override
    public void stopLiveVideoStream() throws CustomException {
        //如果未获取到登录信息，则登录服务器
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemConstants.userIDInfoReference;
        if(userIDInfoReference==null) {
            ImosLogin.login(true);
        }
        //停止播放器
        IMOSLibrary.INSTANCE.IMOS_StopPlayer(userIDInfoReference);
        //释放通道资源
        IMOSLibrary.INSTANCE.IMOS_FreeChannelCode(userIDInfoReference,"");
    }

    /**
     * 功能描述: 查询组织下的卡口列表
     *
     * @param szOrgCode
     * @auther: 任琳珺
     * @date: 2019-03-18
     * @param: szOrgCode 组织编码
     * @return:
     */
    @Override
    public TagTollgateInfo[] IMOS_QueryTollgateList(String szOrgCode) throws CustomException {
        //如果未获取到登录信息，则登录服务器
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemConstants.userIDInfoReference;
        if(userIDInfoReference==null) {
            ImosLogin.login(true);
        }


        //查询条件，目前没有查询条件，因此该出为0个查询条件
        TagCommonQueryCondition.ByReference commonQueryCondition = new TagCommonQueryCondition.ByReference();
        commonQueryCondition.ulItemNum = 0;
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfo = new TagQueryPageInfo.ByReference();
        queryPageInfo.ulPageFirstRowNumber = 0;
        queryPageInfo.bQueryCount = 0;
        queryPageInfo.ulPageRowNum = IMOS_PAGE_QUERY_ROW_MAX_NUM;
        //响应的分页信息
        TagRspPageInfo.ByReference respPageInfoReference = new TagRspPageInfo.ByReference();
        TagTollgateInfo.ByReference tollgateInfoReference = new TagTollgateInfo.ByReference();
        IMOSLibrary.INSTANCE.IMOS_QueryTollgateList(userIDInfoReference,szOrgCode,commonQueryCondition,
                                                    queryPageInfo,respPageInfoReference,tollgateInfoReference);

        TagTollgateInfo[] tollgateInfos = ( TagTollgateInfo[])tollgateInfoReference.toArray(respPageInfoReference.ulTotalRowNum);

        return tollgateInfos;
    }

}
