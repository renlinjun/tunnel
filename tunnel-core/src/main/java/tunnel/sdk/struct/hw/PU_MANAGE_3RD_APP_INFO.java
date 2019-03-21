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
public class PU_MANAGE_3RD_APP_INFO extends Structure {
	/** \u6709\u6548\u7684\u7b97\u6cd5App\u4e2a\u6570 */
	public int uiValidCount;
	/**
	 * \u4e09\u65b9\u7b97\u6cd5App\u4fe1\u606f<br>
	 * C type : PU_3RD_APP_BASIC_INFO_S[16]
	 */
	public PU_3RD_APP_BASIC_INFO[] ast3RdAppInfo = new PU_3RD_APP_BASIC_INFO[16];
	/** C type : CHAR[32] */
	public byte[] szReserved = new byte[32];
	public PU_MANAGE_3RD_APP_INFO() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("uiValidCount", "ast3RdAppInfo", "szReserved");
	}
	/**
	 * @param uiValidCount \u6709\u6548\u7684\u7b97\u6cd5App\u4e2a\u6570<br>
	 * @param ast3RdAppInfo \u4e09\u65b9\u7b97\u6cd5App\u4fe1\u606f<br>
	 * C type : PU_3RD_APP_BASIC_INFO_S[16]<br>
	 * @param szReserved C type : CHAR[32]
	 */
	public PU_MANAGE_3RD_APP_INFO(int uiValidCount, PU_3RD_APP_BASIC_INFO ast3RdAppInfo[], byte szReserved[]) {
		super();
		this.uiValidCount = uiValidCount;
		if ((ast3RdAppInfo.length != this.ast3RdAppInfo.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.ast3RdAppInfo = ast3RdAppInfo;
		if ((szReserved.length != this.szReserved.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserved = szReserved;
	}
	public PU_MANAGE_3RD_APP_INFO(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_MANAGE_3RD_APP_INFO implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_MANAGE_3RD_APP_INFO implements Structure.ByValue {
		
	};
}