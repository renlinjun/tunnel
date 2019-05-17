package com.burst.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_DOMAIN_CODE_LEN;
import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_NAME_LEN;
import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_RES_CODE_LEN;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagShareAlarmSrcBase extends Structure {
	/** C type : CHAR[IMOS_RES_CODE_LEN] */
	public byte[] szAlarmSrcCode = new byte[IMOS_RES_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szAlarmSrcName = new byte[IMOS_NAME_LEN];
	/** C type : CHAR[IMOS_DOMAIN_CODE_LEN] */
	public byte[] szParentOrgCode = new byte[IMOS_DOMAIN_CODE_LEN];
	/** C type : CHAR[IMOS_RES_CODE_LEN] */
	public byte[] szAlarmSrcShareCode = new byte[IMOS_RES_CODE_LEN];
	public tagShareAlarmSrcBase() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szAlarmSrcCode", "szAlarmSrcName", "szParentOrgCode", "szAlarmSrcShareCode");
	}
	/**
	 * @param szAlarmSrcCode C type : CHAR[IMOS_RES_CODE_LEN]<br>
	 * @param szAlarmSrcName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param szParentOrgCode C type : CHAR[IMOS_DOMAIN_CODE_LEN]<br>
	 * @param szAlarmSrcShareCode C type : CHAR[IMOS_RES_CODE_LEN]
	 */
	public tagShareAlarmSrcBase(byte szAlarmSrcCode[], byte szAlarmSrcName[], byte szParentOrgCode[], byte szAlarmSrcShareCode[]) {
		super();
		if ((szAlarmSrcCode.length != this.szAlarmSrcCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szAlarmSrcCode = szAlarmSrcCode;
		if ((szAlarmSrcName.length != this.szAlarmSrcName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szAlarmSrcName = szAlarmSrcName;
		if ((szParentOrgCode.length != this.szParentOrgCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szParentOrgCode = szParentOrgCode;
		if ((szAlarmSrcShareCode.length != this.szAlarmSrcShareCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szAlarmSrcShareCode = szAlarmSrcShareCode;
	}
	public tagShareAlarmSrcBase(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagShareAlarmSrcBase implements Structure.ByReference {
		
	};
	public static class ByValue extends tagShareAlarmSrcBase implements Structure.ByValue {
		
	};
}