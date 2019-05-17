package test;

import com.burst.exception.CustomException;
import com.burst.sdk.constanst.IMOSDefLibrary;
import com.burst.sdk.constanst.IMOSErrCodeEnum;
import com.burst.sdk.library.IMOSLibrary;
import com.burst.sdk.struct.imos.*;
import com.sun.jna.Native;

import static com.burst.sdk.constanst.SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM;


/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/22 09:50
 */
public class TollgateTest {

    public static void main(String args[]) throws CustomException {
        String username = "loadmin";
        String password = "imos_123";
        byte[] passwordByte = new byte[64];
        int result = IMOSLibrary.INSTANCE.IMOS_Encrypt(password,password.length(),passwordByte);
        System.out.println("加密后为："+ result);
        System.out.println(new String(passwordByte));

        String serverAdd = "172.17.11.146";


        int initResult = IMOSLibrary.INSTANCE.IMOS_Initiate(serverAdd.getBytes(),8800,1,0);
        System.out.println("初始化结果:"+initResult+"---是否成功："+(initResult== IMOSErrCodeEnum.ERR_COMMON_SUCCEED));
        System.out.printf("十六进制：");
        System.out.printf("%x\n",initResult);
        if(initResult==IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            TagLoginInfo.ByReference logInfoReference = new TagLoginInfo.ByReference();
            int loginResult = IMOSLibrary.INSTANCE.IMOS_LoginEx(username.getBytes(),passwordByte,serverAdd.getBytes(),"N/A",logInfoReference);
            TagUserLoginIDInfo.ByReference userLoginIDInfo = logInfoReference.getTagUserLoginIDInfoReference();
            String szTollgateCode = "1-15-1";
            TagTollgateInfo.ByReference tagTollgateInfo = new TagTollgateInfo.ByReference();
            //TODO 卡口编码暂时为 "1-15-1"
            System.out.println();
            IMOSLibrary.INSTANCE.IMOS_QueryTollgate(userLoginIDInfo,szTollgateCode.getBytes(),tagTollgateInfo);
            if(tagTollgateInfo.ulIsOnline != IMOSDefLibrary.IMOS_DEV_STATUS_ONLINE) {
                throw  new CustomException(-1,"卡口["+"编号：1-15-1"+",名称："+tagTollgateInfo.szTollgateName+"]处于离线状态");
            }
            /* 如果设备在线 */
            //卡口编码
            byte[] szTollgageCode = tagTollgateInfo.szTollgateCode;
            System.out.println("组织编码："+Native.toString(tagTollgateInfo.szOrgCode));
            System.out.println("卡口编码："+ Native.toString(szTollgageCode));


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
            int queryResult = IMOSLibrary.INSTANCE.IMOS_QueryTollgateVideoCameraList(userLoginIDInfo,szTollgageCode,commonQueryCondition,queryPageInfo,respPageInfoReference,videoCameItem);

            if(queryResult!= IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
                throw new CustomException(queryResult,"查询摄像机列表失败");
            }
            //将结构体指针转换为结构体
            TagRspPageInfo tagRspPageInfo = new TagRspPageInfo(respPageInfoReference.getPointer());
            //查询出的摄像头数量
            int resultCount = tagRspPageInfo.ulTotalRowNum;
            System.out.println("查询到的摄像机数量:"+resultCount);
            //取出所有的摄像机
            TagTollgateVideoCameraQueryItem[] videoCameraQueryItems = (TagTollgateVideoCameraQueryItem[]) videoCameItem.toArray(resultCount);

            IMOSLibrary.INSTANCE.IMOS_LogoutEx(userLoginIDInfo);
            //取出所有的摄像机
            //清除资源
            IMOSLibrary.INSTANCE.IMOS_CleanUp(userLoginIDInfo);
            System.out.println(new String(logInfoReference.szOrgCode));
            System.out.println(loginResult);
        }

    }
}
