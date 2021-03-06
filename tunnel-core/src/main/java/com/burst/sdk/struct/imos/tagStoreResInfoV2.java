package com.burst.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
import static com.burst.sdk.constanst.IMOSDefLibrary.*;
/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagStoreResInfoV2 extends Structure {
	/** C type : STORE_RES_INFO_S */
	public tagStoreResInfo stStoreResInfo;
	/** C type : CHAR[IMOS_CODE_LEN] */
	public byte[] szDMDevCode = new byte[IMOS_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szDMDevName = new byte[IMOS_NAME_LEN];
	public tagStoreResInfoV2() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stStoreResInfo", "szDMDevCode", "szDMDevName");
	}
	/**
	 * @param stStoreResInfo C type : STORE_RES_INFO_S<br>
	 * @param szDMDevCode C type : CHAR[IMOS_CODE_LEN]<br>
	 * @param szDMDevName C type : CHAR[IMOS_NAME_LEN]
	 */
	public tagStoreResInfoV2(tagStoreResInfo stStoreResInfo, byte szDMDevCode[], byte szDMDevName[]) {
		super();
		this.stStoreResInfo = stStoreResInfo;
		if ((szDMDevCode.length != this.szDMDevCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDMDevCode = szDMDevCode;
		if ((szDMDevName.length != this.szDMDevName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDMDevName = szDMDevName;
	}
	public tagStoreResInfoV2(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagStoreResInfoV2 implements Structure.ByReference {
		
	};
	public static class ByValue extends tagStoreResInfoV2 implements Structure.ByValue {
		
	};
}
