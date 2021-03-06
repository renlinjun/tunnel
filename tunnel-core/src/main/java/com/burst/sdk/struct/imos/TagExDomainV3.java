package com.burst.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_STRING_LEN_64;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class TagExDomainV3 extends Structure {
	/** C type : EX_DOMAIN_V2_S */
	public TagExDomainV2 stExDomainInfoV2;
	/** C type : int */
	public int ulExDomainSubType;
	/** C type : CHAR[IMOS_STRING_LEN_64] */
	public byte[] szDevType = new byte[IMOS_STRING_LEN_64];
	public TagExDomainV3() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stExDomainInfoV2", "ulExDomainSubType", "szDevType");
	}
	/**
	 * @param stExDomainInfoV2 C type : EX_DOMAIN_V2_S<br>
	 * @param ulExDomainSubType C type : int<br>
	 * @param szDevType C type : CHAR[IMOS_STRING_LEN_64]
	 */
	public TagExDomainV3(TagExDomainV2 stExDomainInfoV2, int ulExDomainSubType, byte szDevType[]) {
		super();
		this.stExDomainInfoV2 = stExDomainInfoV2;
		this.ulExDomainSubType = ulExDomainSubType;
		if ((szDevType.length != this.szDevType.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDevType = szDevType;
	}
	public TagExDomainV3(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagExDomainV3 implements Structure.ByReference {
		
	};
	public static class ByValue extends TagExDomainV3 implements Structure.ByValue {
		
	};
}
