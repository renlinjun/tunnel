package com.burst.sdk.struct.hw;
import com.sun.jna.NativeLong;
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
public class PU_SNMP_COMMUNITY_LIST_EX extends Structure {
	/** \u793e\u56e2\u6570\u76ee */
	public NativeLong ulCommunityNum;
	/**
	 * \u793e\u56e2\u4fe1\u606f<br>
	 * C type : PU_SNMP_COMMUNITY_INFO_S_EX[3]
	 */
	public PU_SNMP_COMMUNITY_INFO_EX[] szCommunityInfo = new PU_SNMP_COMMUNITY_INFO_EX[3];
	/** C type : CHAR[32] */
	public byte[] szReserved = new byte[32];
	public PU_SNMP_COMMUNITY_LIST_EX() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulCommunityNum", "szCommunityInfo", "szReserved");
	}
	/**
	 * @param ulCommunityNum \u793e\u56e2\u6570\u76ee<br>
	 * @param szCommunityInfo \u793e\u56e2\u4fe1\u606f<br>
	 * C type : PU_SNMP_COMMUNITY_INFO_S_EX[3]<br>
	 * @param szReserved C type : CHAR[32]
	 */
	public PU_SNMP_COMMUNITY_LIST_EX(NativeLong ulCommunityNum, PU_SNMP_COMMUNITY_INFO_EX szCommunityInfo[], byte szReserved[]) {
		super();
		this.ulCommunityNum = ulCommunityNum;
		if ((szCommunityInfo.length != this.szCommunityInfo.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szCommunityInfo = szCommunityInfo;
		if ((szReserved.length != this.szReserved.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserved = szReserved;
	}
	public PU_SNMP_COMMUNITY_LIST_EX(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_SNMP_COMMUNITY_LIST_EX implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_SNMP_COMMUNITY_LIST_EX implements Structure.ByValue {
		
	};
}