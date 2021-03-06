package com.burst.sdk.struct.imos;
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
public class TagOrgNodeInfo extends Structure {
	/** C type : ORG_BASIC_S */
	public TagOrgBasicInfo stOrgBasicInfo;
	/** C type : ORG_CONTACT_INFO_S */
	public TagOrgContactInfo stOrgContactInfo;
	public TagOrgNodeInfo() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stOrgBasicInfo", "stOrgContactInfo");
	}
	/**
	 * @param stOrgBasicInfo C type : ORG_BASIC_S<br>
	 * @param stOrgContactInfo C type : ORG_CONTACT_INFO_S
	 */
	public TagOrgNodeInfo(TagOrgBasicInfo stOrgBasicInfo, TagOrgContactInfo stOrgContactInfo) {
		super();
		this.stOrgBasicInfo = stOrgBasicInfo;
		this.stOrgContactInfo = stOrgContactInfo;
	}
	public TagOrgNodeInfo(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagOrgNodeInfo implements Structure.ByReference {
		
	};
	public static class ByValue extends TagOrgNodeInfo implements Structure.ByValue {
		
	};
}
