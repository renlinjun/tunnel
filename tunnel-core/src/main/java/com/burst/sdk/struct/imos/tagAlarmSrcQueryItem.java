package com.burst.sdk.struct.imos;
import com.burst.sdk.constanst.IMOSDefLibrary;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import  com.burst.sdk.constanst.IMOSDefLibrary;

import java.util.Arrays;
import java.util.List;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagAlarmSrcQueryItem extends Structure {
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szAlarmSrcName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
	/** C type : CHAR[IMOS_RES_CODE_LEN] */
	public byte[] szAlarmSrcCode = new byte[IMOSDefLibrary.IMOS_RES_CODE_LEN];
	/** C type : int */
	public int ulDevType;
	/** C type : int */
	public int ulDevSubType;
	/** C type : CHAR[IMOS_DOMAIN_CODE_LEN] */
	public byte[] szOrgCode = new byte[IMOSDefLibrary.IMOS_DOMAIN_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szOrgName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
	/** C type : CHAR[IMOS_STRING_LEN_64] */
	public byte[] szDevType = new byte[IMOSDefLibrary.IMOS_STRING_LEN_64];
	public tagAlarmSrcQueryItem() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szAlarmSrcName", "szAlarmSrcCode", "ulDevType", "ulDevSubType", "szOrgCode", "szOrgName", "szDevType");
	}
	/**
	 * @param szAlarmSrcName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param szAlarmSrcCode C type : CHAR[IMOS_RES_CODE_LEN]<br>
	 * @param ulDevType C type : int<br>
	 * @param ulDevSubType C type : int<br>
	 * @param szOrgCode C type : CHAR[IMOS_DOMAIN_CODE_LEN]<br>
	 * @param szOrgName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param szDevType C type : CHAR[IMOS_STRING_LEN_64]
	 */
	public tagAlarmSrcQueryItem(byte szAlarmSrcName[], byte szAlarmSrcCode[], int ulDevType, int ulDevSubType, byte szOrgCode[], byte szOrgName[], byte szDevType[]) {
		super();
		if ((szAlarmSrcName.length != this.szAlarmSrcName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szAlarmSrcName = szAlarmSrcName;
		if ((szAlarmSrcCode.length != this.szAlarmSrcCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szAlarmSrcCode = szAlarmSrcCode;
		this.ulDevType = ulDevType;
		this.ulDevSubType = ulDevSubType;
		if ((szOrgCode.length != this.szOrgCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szOrgCode = szOrgCode;
		if ((szOrgName.length != this.szOrgName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szOrgName = szOrgName;
		if ((szDevType.length != this.szDevType.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDevType = szDevType;
	}
	public tagAlarmSrcQueryItem(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagAlarmSrcQueryItem implements Structure.ByReference {
		
	};
	public static class ByValue extends tagAlarmSrcQueryItem implements Structure.ByValue {
		
	};
}
