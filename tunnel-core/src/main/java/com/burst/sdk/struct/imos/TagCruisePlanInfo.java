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
public class TagCruisePlanInfo extends Structure {
	/** C type : CRUISE_PLAN_BASE_S */
	public TagCruisePlanBase stCruiseBaseInfo;
	/** C type : PLAN_TIME_FOR_RES_S */
	public TagPlanTimeForRes stCruiseTimeInfo;
	public TagCruisePlanInfo() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stCruiseBaseInfo", "stCruiseTimeInfo");
	}
	/**
	 * @param stCruiseBaseInfo C type : CRUISE_PLAN_BASE_S<br>
	 * @param stCruiseTimeInfo C type : PLAN_TIME_FOR_RES_S
	 */
	public TagCruisePlanInfo(TagCruisePlanBase stCruiseBaseInfo, TagPlanTimeForRes stCruiseTimeInfo) {
		super();
		this.stCruiseBaseInfo = stCruiseBaseInfo;
		this.stCruiseTimeInfo = stCruiseTimeInfo;
	}
	public TagCruisePlanInfo(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagCruisePlanInfo implements Structure.ByReference {
		
	};
	public static class ByValue extends TagCruisePlanInfo implements Structure.ByValue {
		
	};
}
