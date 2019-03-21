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
public class TagResAuthority extends Structure {
	/** C type : ORG_AUTHORITY_V2_S */
	public TagOrgAuthorityV2 stAuthorities;
	/** C type : CHAR[IMOS_CODE_LEN] */
	public byte[] szResIdCode = new byte[IMOS_CODE_LEN];
	public TagResAuthority() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stAuthorities", "szResIdCode");
	}
	/**
	 * @param stAuthorities C type : ORG_AUTHORITY_V2_S<br>
	 * @param szResIdCode C type : CHAR[IMOS_CODE_LEN]
	 */
	public TagResAuthority(TagOrgAuthorityV2 stAuthorities, byte szResIdCode[]) {
		super();
		this.stAuthorities = stAuthorities;
		if ((szResIdCode.length != this.szResIdCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szResIdCode = szResIdCode;
	}
	public TagResAuthority(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagResAuthority implements Structure.ByReference {
		
	};
	public static class ByValue extends TagResAuthority implements Structure.ByValue {
		
	};
}