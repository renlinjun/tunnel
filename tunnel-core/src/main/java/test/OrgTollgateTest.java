package test;

import com.burst.exception.CustomException;
import com.burst.sdk.constanst.IMOSErrCodeEnum;
import com.burst.sdk.library.IMOSLibrary;
import com.burst.sdk.struct.imos.*;
import com.sun.jna.Native;
import com.sun.jna.Pointer;


import static  com.burst.sdk.constanst.SDKDef.IMOS_PAGE_QUERY_ROW_MAX_NUM;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/22 09:50
 */
public class OrgTollgateTest {

    public static void main(String args[]) throws CustomException {
        String username = "loadmin";
        String password = "imos_123";
        byte[] passwordByte = new byte[64];
        int result = IMOSLibrary.INSTANCE.IMOS_Encrypt(password,password.length(),passwordByte);
        System.out.println("加密结果："+ result);
        System.out.println("加密后字符串："+Native.toString(passwordByte));

        String serverAdd = "172.17.11.146";


        int initResult = IMOSLibrary.INSTANCE.IMOS_Initiate(serverAdd.getBytes(),8800,1,0);
        System.out.println("初始化结果:"+initResult+"---是否成功："+(initResult== IMOSErrCodeEnum.ERR_COMMON_SUCCEED));
        if(initResult==IMOSErrCodeEnum.ERR_COMMON_SUCCEED) {
            TagLoginInfo.ByReference logInfoReference = new TagLoginInfo.ByReference();
            int loginResult = IMOSLibrary.INSTANCE.IMOS_LoginEx(username.getBytes(),passwordByte,serverAdd.getBytes(),"N/A",logInfoReference);
            TagUserLoginIDInfo.ByReference userLoginIDInfo = logInfoReference.getTagUserLoginIDInfoReference();
            String szOrgCode = "iccsid";


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
            TagTollgateInfo tollgateInfo = new TagTollgateInfo();
            Pointer pointer = new Pointer(Native.malloc(tollgateInfo.size() * IMOS_PAGE_QUERY_ROW_MAX_NUM));
            TagTollgateInfo.ByReference bf = new  TagTollgateInfo.ByReference(pointer);
            //Pointer pointer = new Pointer(tollgateInfo.size() * IMOS_PAGE_QUERY_ROW_MAX_NUM);
            int queryResult = IMOSLibrary.INSTANCE.IMOS_QueryTollgateList(userLoginIDInfo,szOrgCode.getBytes(),commonQueryCondition,queryPageInfo,respPageInfoReference,bf);
            System.out.println("查询结果："+queryResult);
            System.out.println("数量:"+respPageInfoReference.ulRowNum);
            //TagTollgateInfo[] tollgateInfos = (TagTollgateInfo[])new TagTollgateInfo().toArray(respPageInfoReference.ulRowNum);
            //TagTollgateInfo[] tollgateInfos = (TagTollgateInfo[])tollgateInfo.toArray(respPageInfoReference.ulRowNum);


            //Pointer[] tollgateinfoPs = pointer.getPointerArray(tollgateInfo.size(),respPageInfoReference.ulRowNum);

            for (int i=0;i<respPageInfoReference.ulRowNum;i++) {
                long offset = i * tollgateInfo.size();
                Pointer infoPointer = pointer.share(offset,tollgateInfo.size());
                TagTollgateInfo info = new TagTollgateInfo(infoPointer);
                byte[] aa = info.szTollgateCode;
                System.out.println("卡口编码["+i+"]："+Native.toString(info.szTollgateName));
                System.out.println("卡口状态["+i+"]："+info.ulIsOnline);
            }


            //tollgateInfo.toArray(tollgateInfos);
            /*System.out.println("tollgateInfo数量:"+tollgateInfos.length);
            for(int i=0;i<tollgateInfos.length;i++) {
                System.out.println("卡口编码：["+i+"]"+Native.toString(tollgateInfos[i].szTollgateCode));
                System.out.println("卡口状态：["+i+"]"+tollgateInfos[i].ulIsOnline);
            }
*/
            IMOSLibrary.INSTANCE.IMOS_LogoutEx(userLoginIDInfo);
            //取出所有的摄像机
            //清除资源
            IMOSLibrary.INSTANCE.IMOS_CleanUp(userLoginIDInfo);
            System.out.println(Native.toString(logInfoReference.szOrgCode));
            System.out.println(loginResult);
        }

    }
}
