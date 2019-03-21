package tunnel.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
import static tunnel.sdk.constanst.IMOSDefLibrary.*;
/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagUserPasswordInfo extends Structure {
	/** C type : USER_INFO_S */
	public tagUserInfo stUserInfo;
	/** C type : CHAR[IMOS_PASSWD_ENCRYPT_LEN] */
	public byte[] szPassword = new byte[IMOS_PASSWD_ENCRYPT_LEN];
	public tagUserPasswordInfo() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stUserInfo", "szPassword");
	}
	/**
	 * @param stUserInfo C type : USER_INFO_S<br>
	 * @param szPassword C type : CHAR[IMOS_PASSWD_ENCRYPT_LEN]
	 */
	public tagUserPasswordInfo(tagUserInfo stUserInfo, byte szPassword[]) {
		super();
		this.stUserInfo = stUserInfo;
		if ((szPassword.length != this.szPassword.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szPassword = szPassword;
	}
	public tagUserPasswordInfo(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagUserPasswordInfo implements Structure.ByReference {
		
	};
	public static class ByValue extends tagUserPasswordInfo implements Structure.ByValue {
		
	};
}