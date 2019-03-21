package tunnel.sdk.struct.hw;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * <i>native declaration : D:\HWPuSDK.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class PU_USER_INFO extends Structure {
	/**
	 * \u7528\u6237\u7c7b\u578b<br>
	 * C type : PU_USER_TYPE_E
	 */
	public int enUserType;
	/**
	 * \u7528\u6237\u540d,\u6700\u957f\u652f\u630116\u4f4d<br>
	 * C type : CHAR[32]
	 */
	public byte[] szUserName = new byte[32];
	/**
	 * Pwd<br>
	 * C type : CHAR[(64 + 4)]
	 */
	public byte[] szUserPwd = new byte[64 + 4];
	/**
	 * szReserved[0]\u4ee3\u8868WEB\u591a\u70b9\u767b\u9646\u7528\u6237\u6570\uff0c\u8303\u56f41-10<br>
	 * C type : CHAR[32]
	 */
	public byte[] szReserved = new byte[32];
	public PU_USER_INFO() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("enUserType", "szUserName", "szUserPwd", "szReserved");
	}
	/**
	 * @param enUserType \u7528\u6237\u7c7b\u578b<br>
	 * C type : PU_USER_TYPE_E<br>
	 * @param szUserName \u7528\u6237\u540d,\u6700\u957f\u652f\u630116\u4f4d<br>
	 * C type : CHAR[32]<br>
	 * @param szUserPwd Pwd<br>
	 * C type : CHAR[(64 + 4)]<br>
	 * @param szReserved szReserved[0]\u4ee3\u8868WEB\u591a\u70b9\u767b\u9646\u7528\u6237\u6570\uff0c\u8303\u56f41-10<br>
	 * C type : CHAR[32]
	 */
	public PU_USER_INFO(int enUserType, byte szUserName[], byte szUserPwd[], byte szReserved[]) {
		super();
		this.enUserType = enUserType;
		if ((szUserName.length != this.szUserName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szUserName = szUserName;
		if ((szUserPwd.length != this.szUserPwd.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szUserPwd = szUserPwd;
		if ((szReserved.length != this.szReserved.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserved = szReserved;
	}
	public PU_USER_INFO(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_USER_INFO implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_USER_INFO implements Structure.ByValue {
		
	};
}