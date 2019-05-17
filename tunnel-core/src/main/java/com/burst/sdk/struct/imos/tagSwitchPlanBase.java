package com.burst.sdk.struct.imos;
import com.burst.sdk.constanst.IMOSDefLibrary;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagSwitchPlanBase extends Structure {
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szPlanName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
	/** C type : CHAR[IMOS_TIME_LEN] */
	public byte[] szCreatTime = new byte[IMOSDefLibrary.IMOS_TIME_LEN];
	/** C type : CHAR[IMOS_RES_CODE_LEN] */
	public byte[] szScrCode = new byte[IMOSDefLibrary.IMOS_RES_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szScrName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
	/** C type : int */
	public int ulPlanType;
	/** C type : CHAR[IMOS_DOMAIN_CODE_LEN] */
	public byte[] szOrgCode = new byte[IMOSDefLibrary.IMOS_DOMAIN_CODE_LEN];
	/** C type : CHAR[IMOS_DESC_LEN] */
	public byte[] szPlanDesc = new byte[IMOSDefLibrary.IMOS_DESC_LEN];
	public tagSwitchPlanBase() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szPlanName", "szCreatTime", "szScrCode", "szScrName", "ulPlanType", "szOrgCode", "szPlanDesc");
	}
	/**
	 * @param szPlanName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param szCreatTime C type : CHAR[IMOS_TIME_LEN]<br>
	 * @param szScrCode C type : CHAR[IMOS_RES_CODE_LEN]<br>
	 * @param szScrName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param ulPlanType C type : int<br>
	 * @param szOrgCode C type : CHAR[IMOS_DOMAIN_CODE_LEN]<br>
	 * @param szPlanDesc C type : CHAR[IMOS_DESC_LEN]
	 */
	public tagSwitchPlanBase(byte szPlanName[], byte szCreatTime[], byte szScrCode[], byte szScrName[], int ulPlanType, byte szOrgCode[], byte szPlanDesc[]) {
		super();
		if ((szPlanName.length != this.szPlanName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szPlanName = szPlanName;
		if ((szCreatTime.length != this.szCreatTime.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szCreatTime = szCreatTime;
		if ((szScrCode.length != this.szScrCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szScrCode = szScrCode;
		if ((szScrName.length != this.szScrName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szScrName = szScrName;
		this.ulPlanType = ulPlanType;
		if ((szOrgCode.length != this.szOrgCode.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szOrgCode = szOrgCode;
		if ((szPlanDesc.length != this.szPlanDesc.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szPlanDesc = szPlanDesc;
	}
	public tagSwitchPlanBase(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagSwitchPlanBase implements Structure.ByReference {
		
	};
	public static class ByValue extends tagSwitchPlanBase implements Structure.ByValue {
		
	};
}