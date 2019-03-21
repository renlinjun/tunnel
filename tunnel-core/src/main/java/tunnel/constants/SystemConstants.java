package tunnel.constants;

import com.sun.jna.Pointer;
import tunnel.sdk.struct.imos.TagLoginInfo;
import tunnel.sdk.struct.imos.TagUserLoginIDInfo;

/**
 * @描述: 系统级别初始化后或者执行某些操作后需要保存的常量
 * @作者: REN
 * @时间: 2019/3/13 10:10
 */
public class SystemConstants {
    /** 当前登录信息 */
    public static TagLoginInfo.ByReference loginInfo = null;
    /** 当前登录人员的信息 */
    public static TagUserLoginIDInfo.ByReference userIDInfoReference = null;

}
