package com.burst.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;
import static  com.burst.sdk.constanst.IMOSDefLibrary.*;
/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class TagMSInfo extends Structure {
	/** C type : CHAR[IMOS_DEVICE_CODE_LEN] */
	public byte[] szMSCode = new byte[IMOS_DEVICE_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szMSName = new byte[IMOS_NAME_LEN];
	/** C type : CHAR[IMOS_DOMAIN_CODE_LEN] */
	public byte[] szOrgCode = new byte[IMOS_DOMAIN_CODE_LEN];
	/** C type : CHAR[IMOS_DESC_LEN - IMOS_STRING_LEN_128] */
	public byte[] szDevDesc = new byte[IMOS_DESC_LEN - IMOS_STRING_LEN_128];
	/** C type : int */
	public int ulMSType;
	/** C type : CHAR[124] */
	public byte[] szReserve = new byte[124];
	public TagMSInfo() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szMSCode", "szMSName", "szOrgCode", "szDevDesc", "ulMSType", "szReserve");
	}
	/**
	 * @param szMSCode C type : CHAR[IMOS_DEVICE_CODE_LEN]<br>
	 * @param szMSName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param szOrgCode C type : CHAR[IMOS_DOMAIN_CODE_LEN]<br>
	 * @param szDevDesc C type : CHAR[IMOS_DESC_LEN - IMOS_STRING_LEN_128]<br>
	 * @param ulMSType C type : int<br>
	 * @param szReserve C type : CHAR[124]
	 */
	public TagMSInfo(byte szMSCode[], byte szMSName[], byte szOrgCode[], byte szDevDesc[], int ulMSType, byte szReserve[]) {
		super();
		if ((szMSCode.length != this.szMSCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szMSCode = szMSCode;
		if ((szMSName.length != this.szMSName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szMSName = szMSName;
		if ((szOrgCode.length != this.szOrgCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szOrgCode = szOrgCode;
		if ((szDevDesc.length != this.szDevDesc.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDevDesc = szDevDesc;
		this.ulMSType = ulMSType;
		if ((szReserve.length != this.szReserve.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserve = szReserve;
	}
	public TagMSInfo(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagMSInfo implements Structure.ByReference {
		
	};
	public static class ByValue extends TagMSInfo implements Structure.ByValue {
		
	};
}
