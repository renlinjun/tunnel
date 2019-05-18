package com.burst.imos;

import cn.hutool.core.util.StrUtil;
import com.burst.bayonet.BayonetHandler;
import com.burst.cache.SystemCache;
import com.burst.exception.CustomException;
import com.burst.sdk.callBack.CallBackProcExPf;
import com.burst.sdk.constanst.IMOSDefLibrary;
import com.burst.sdk.constanst.IMOSErrCodeEnum;
import com.burst.sdk.constanst.SDKDef;
import com.burst.sdk.library.IMOSLibrary;
import com.burst.sdk.library.XPFrameLibrary;
import com.burst.sdk.struct.imos.*;
import com.burst.utils.JNAUtil;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import org.springframework.beans.factory.annotation.Autowired;

/**
 * @描述: 宇视平台对卡口功能的实现
 * @作者: REN
 * @时间: 2019/2/27 11:22
 */
//@Component
public class ImosHandler implements BayonetHandler {

    @Autowired
    private CallBackProcExPf callBackProcExPf;
    @Autowired
    private ImosLogin imosLogin;

    @Override
    public void init() throws CustomException {
        //初始化
        imosLogin.Initiate();
    }

    @Override
    public void actualInfo() throws CustomException {
        //获取登录信息
        TagLoginInfo.ByReference loginInfoReference = SystemCache.loginInfo;
        if(loginInfoReference==null) {
            throw new CustomException(-1,"获取登录信息失败!");
        }
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemCache.userIDInfoReference;
        //订阅推送
        IMOSLibrary.INSTANCE.IMOS_SubscribePushInfo(loginInfoReference, SDKDef.tagSubscribePushType.SUBSCRIBE_PUSH_TYPE_ALL);
        //注册消息推送回调函数
        //CallBackProcExPf callBackProcExPf = new CallBackProcExPfImpl();
        IMOSLibrary.INSTANCE.IMOS_RegCallBackPrcFuncEx(userIDInfoReference,callBackProcExPf);
        //查询卡口
        TagTollgateInfo.ByReference tagTollgateInfo = new TagTollgateInfo.ByReference();


        //@TODO 由于未知原因，此处可能存在多个线程。导致一直查询不到卡口信息，因此在该处强制线程休眠300毫秒，以后可接着排查该问题
        try {
            Thread.sleep(300);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //TODO 卡口编码暂时为 "1-15-1"
        IMOSLibrary.INSTANCE.IMOS_QueryTollgate(userIDInfoReference,"1-15-1".getBytes(),tagTollgateInfo);

        if(tagTollgateInfo.ulIsOnline != IMOSDefLibrary.IMOS_DEV_STATUS_ONLINE) {
            throw  new CustomException(-1,"卡口["+"编号：1-15-1"+",名称："+tagTollgateInfo.szTollgateName+"]处于离线状态");
        }
        /* 如果设备在线 */
        //卡口编码
        byte[] szTollgageCode = tagTollgateInfo.szTollgateCode;
        System.out.println("卡口编码："+Native.toString(szTollgageCode));
        /* 开始查询摄像头列表，并开启视频流 *****/

        //取出所有的摄像机
        /*TagTollgateVideoCameraQueryItem.ByReference[] videoCameraQueryItems = listVideoCameraByBayonet("1-15-1".getBytes());
        for(int i=0;i<videoCameraQueryItems.length;i++) {
            TagTollgateVideoCameraQueryItem.ByReference videoCamera = videoCameraQueryItems[i];
            //开启视频流
            IMOSLibrary.INSTANCE.IMOS_StartMonitor(userIDInfoReference,videoCamera.szCameraCode,IMOS_CODE_TYPE_UTF8.getBytes(),
                                                SDKDef.tagIMOSFavoriteStream.IMOS_FAVORITE_STREAM_ANY, SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);

        }*/

        startLiveVideoStream();

        /* 摄像头列表查询结束  ****/

        /* 开始查询照相机列表，并开启照片流  */

       /* TagTollgateCameraInfo.ByReference[] cameraInfos = listCameraByBayonet(szTollgageCode);
        for(int i=0;i<cameraInfos.length;i++) {
            TagTollgateCameraInfo.ByReference camera = cameraInfos[i];
            //开启视频流
            IMOSLibrary.INSTANCE.IMOS_StartTollgateMonitor(userIDInfoReference,camera.szCameraCode,IMOS_CODE_TYPE_UTF8.getBytes(),
                    SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);
        }*/
    }


    private void play(byte[] carameCode,byte[] channelCode) {
        //开启照片流
        IMOSLibrary.INSTANCE.IMOS_StartTollgateMonitor(SystemCache.userIDInfoReference,carameCode,channelCode,
                SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);

        //开启视频流
        IMOSLibrary.INSTANCE.IMOS_StartMonitor(SystemCache.userIDInfoReference,carameCode,channelCode,
                SDKDef.tagIMOSFavoriteStream.IMOS_FAVORITE_STREAM_ANY, SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);

    }

    @Override
    public TagTollgateVideoCameraQueryItem.ByReference[] listVideoCameraByBayonet(byte[] szTollgageCode) throws CustomException {
        //查询条件，目前没有查询条件，因此该出为0个查询条件
        TagCommonQueryCondition.ByReference commonQueryCondition = new TagCommonQueryCondition.ByReference();
        commonQueryCondition.ulItemNum = 0;
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfo = new TagQueryPageInfo.ByReference();
        queryPageInfo.ulPageFirstRowNumber = 0;
        queryPageInfo.bQueryCount = 0;
        queryPageInfo.ulPageRowNum = SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM;
        //响应的分页信息
        TagRspPageInfo.ByReference respPageInfoReference = new TagRspPageInfo.ByReference();
        TagTollgateVideoCameraQueryItem videoCameraQueryItem = new  TagTollgateVideoCameraQueryItem();
        //分配内存，创建内存指针
        Pointer pointer = new Pointer(Native.malloc(videoCameraQueryItem.size() * SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM));
        //从内存指针中创建结构体引用

        //返回的摄像机列表,返回的是一个起始地址
        TagTollgateVideoCameraQueryItem.ByReference videoCameItemReference = new TagTollgateVideoCameraQueryItem.ByReference(pointer);
        int queryResult = IMOSLibrary.INSTANCE.IMOS_QueryTollgateVideoCameraList(SystemCache.userIDInfoReference,szTollgageCode,commonQueryCondition,queryPageInfo,respPageInfoReference,videoCameItemReference);

        if(queryResult!= IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(queryResult,"查询摄像机列表失败");
        }
        //查询出的摄像头数量
        int resultCount = respPageInfoReference.ulTotalRowNum;

        //TagTollgateVideoCameraQueryItem[] videoCameraInfos = new TagTollgateVideoCameraQueryItem[respPageInfoReference.ulRowNum];
        //从指针中读出结构体，放入数组中
       /* for (int i=0;i<resultCount;i++) {
            long offset = i * videoCameraQueryItem.size();
            Pointer infoPointer = pointer.share(offset,videoCameraQueryItem.size());
            TagTollgateVideoCameraQueryItem info = new TagTollgateVideoCameraQueryItem(infoPointer);
            videoCameraInfos[i] = info;
        }*/
        TagTollgateVideoCameraQueryItem.ByReference[] videoCameraInfos = ( TagTollgateVideoCameraQueryItem.ByReference[])videoCameItemReference.toArray(respPageInfoReference.ulRowNum);
        //释放内存
        JNAUtil.freeMemory(pointer);
        return videoCameraInfos;
    }

    @Override
    public TagTollgateCameraInfo.ByReference[] listCameraByBayonet(byte[] szTollgageCode) throws CustomException {
        //查询条件，目前没有查询条件，因此该出为0个查询条件
        TagCommonQueryCondition.ByReference commonQueryConditionCamera = new TagCommonQueryCondition.ByReference();
        commonQueryConditionCamera.ulItemNum = 0;
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfo = new TagQueryPageInfo.ByReference();
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfoCamera = new TagQueryPageInfo.ByReference();
        queryPageInfo.ulPageFirstRowNumber = 0;
        queryPageInfo.bQueryCount = 0;
        queryPageInfo.ulPageRowNum = SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM;
        //响应的分页信息
        TagRspPageInfo.ByReference respPageInfoReferenceCamera = new TagRspPageInfo.ByReference();

        //结构体大小
        //int structerSize = Native.getNativeSize(TagTollgateCameraInfo.class);
        int structerSize = new TagTollgateCameraInfo().size();
        //分配内存
        Pointer pointer = new Pointer(Native.malloc(structerSize * SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM));
        //结构体指针
        TagTollgateCameraInfo.ByReference cameraInfoReference = new TagTollgateCameraInfo.ByReference(pointer);

        int queryCameraResult = IMOSLibrary.INSTANCE.IMOS_QueryTollgateCameraList(SystemCache.userIDInfoReference,
                                                                        szTollgageCode,commonQueryConditionCamera,
                                                                        queryPageInfoCamera,respPageInfoReferenceCamera,cameraInfoReference);

        if(queryCameraResult!= IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            throw new CustomException(queryCameraResult,"查询照相机失败");
        }
        int resultCount = respPageInfoReferenceCamera.ulRowNum;
        //TagTollgateCameraInfo[] cameraInfos = new TagTollgateCameraInfo[respPageInfoReferenceCamera.ulRowNum];
        //从指针中读出结构体，放入数组中
        /*for (int i=0;i<resultCount;i++) {
            long offset = i * structerSize;
            Pointer infoPointer = pointer.share(offset,structerSize);
            TagTollgateCameraInfo info = new TagTollgateCameraInfo(infoPointer);
            cameraInfos[i] = info;
        }*/
        TagTollgateCameraInfo.ByReference[] cameraInfos = (TagTollgateCameraInfo.ByReference[])cameraInfoReference.toArray(resultCount);
        //释放内存
        JNAUtil.freeMemory(pointer);

        return cameraInfos;
    }

    @Override
    public void startLiveVideoStream() throws CustomException {
        //如果未获取到登录信息，则登录服务器
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemCache.userIDInfoReference;
        if(userIDInfoReference==null) {
            imosLogin.login(true);
        }
        //播放窗格编码结构体指针
        TagPlayWndInfo.ByReference playWndInfo = new TagPlayWndInfo.ByReference();
        //启动播放器
        IMOSLibrary.INSTANCE.IMOS_StartPlayer(userIDInfoReference,1,playWndInfo);
        //针对每个摄像头开启实时监控
        TagTollgateVideoCameraQueryItem.ByReference[] videoCameras = listVideoCameraByBayonet("1-15-1".getBytes());
        for(int i=0;i<videoCameras.length;i++) {
            TagTollgateVideoCameraQueryItem vc = videoCameras[i];
            if(StrUtil.isEmpty(Native.toString(vc.szCameraCode))) {
                continue;
            }
            //XpPlayerTranscodeCallbackPF xpPlayerTranscodeCallbackPF = new XpPlayerTranscodeCallbackPFImpl();

            //获取空闲的通道编码
            byte[] channelCode = new byte[48];
            XPFrameLibrary.INSTANCE.IMOS_GetChannelCode(userIDInfoReference,channelCode);
            //设置码流回调函数，该函数可以在IMOS_StartMonitor之前或者之后调用
            //XPFrameLibrary.INSTANCE.IMOS_SetDecodeVideoDataCB(userIDInfoReference,channelCode,xpPlayerTranscodeCallbackPF,1,0);
            //将通道与摄像机编码对应关系存放
            //ImosConstants.channelCamera.put(Native.toString(channelCode),Native.toString(vc.szCameraCode));
            //用辅流策略，主流和辅流的图像质量不同
            IMOSLibrary.INSTANCE.IMOS_StartMonitor(SystemCache.userIDInfoReference,vc.szCameraCode,
                    channelCode, SDKDef.tagIMOSFavoriteStream.IMOS_FAVORITE_STREAM_SECONDERY , SDKDef.tagCSOperateCode.SYSMANGER_OPERATE_SERVICE);
            //开启照片流
            IMOSLibrary.INSTANCE.IMOS_StartTollgateMonitor(SystemCache.userIDInfoReference,vc.szCameraCode,channelCode,
                    SDKDef.tagCSOperateCode.SYSTEM_OPERATE_SERVICE);

            XPFrameLibrary.INSTANCE.IMOS_StartImage(SystemCache.userIDInfoReference,channelCode);


        }
    }


    @Override
    public void stopLiveVideoStream() throws CustomException {
        //如果未获取到登录信息，则登录服务器
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemCache.userIDInfoReference;
        if(userIDInfoReference==null) {
            imosLogin.login(true);
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
    public TagTollgateInfo[] IMOS_QueryTollgateList(byte[] szOrgCode) throws CustomException {
        //如果未获取到登录信息，则登录服务器
        TagUserLoginIDInfo.ByReference userIDInfoReference = SystemCache.userIDInfoReference;
        if(userIDInfoReference==null) {
            imosLogin.login(true);
        }


        //查询条件，目前没有查询条件，因此该出为0个查询条件
        TagCommonQueryCondition.ByReference commonQueryCondition = new TagCommonQueryCondition.ByReference();
        commonQueryCondition.ulItemNum = 0;
        //请求的分页信息
        TagQueryPageInfo.ByReference queryPageInfo = new TagQueryPageInfo.ByReference();
        queryPageInfo.ulPageFirstRowNumber = 0;
        queryPageInfo.bQueryCount = 0;
        queryPageInfo.ulPageRowNum = SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM;
        //响应的分页信息
        TagRspPageInfo.ByReference respPageInfoReference = new TagRspPageInfo.ByReference();
        TagTollgateInfo tollgateInfo = new TagTollgateInfo();
        //分配内存，创建内存指针
        Pointer pointer = new Pointer(Native.malloc(tollgateInfo.size() * SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM));
        //从内存指针中创建结构体引用
        TagTollgateInfo.ByReference tollgateInfoReference = new  TagTollgateInfo.ByReference(pointer);
        IMOSLibrary.INSTANCE.IMOS_QueryTollgateList(userIDInfoReference,szOrgCode,commonQueryCondition,
                                                    queryPageInfo,respPageInfoReference,tollgateInfoReference);

        //TagTollgateInfo[] tollgateInfos = ( TagTollgateInfo[])tollgateInfoReference.toArray(respPageInfoReference.ulTotalRowNum);
        TagTollgateInfo[] tollgateInfos = new TagTollgateInfo[respPageInfoReference.ulRowNum];
        //从指针中读出结构体，放入数组中
        for (int i=0;i<respPageInfoReference.ulRowNum;i++) {
            long offset = i * tollgateInfo.size();
            Pointer infoPointer = pointer.share(offset,tollgateInfo.size());
            TagTollgateInfo info = new TagTollgateInfo(infoPointer);
            tollgateInfos[i] = info;
        }
        //释放内存
        JNAUtil.freeMemory(pointer);
        return tollgateInfos;
    }

}
