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
public class tagPlanTimeV2 extends Structure {
	/** C type : PLAN_WEEKTIME_V2_S[IMOS_WEEK_DAYS] */
	public tagPlanWeekTimeV2[] astPlanTimeV2 = new tagPlanWeekTimeV2[IMOSDefLibrary.IMOS_WEEK_DAYS];
	/** C type : int */
	public int ulPlanExtTimeNum;
	/** C type : PLAN_EXTTIME_V2_S[IMOS_EXCP_DAYS] */
	public tagPlanExtTimeV2[] astPlanExtTimeV2 = new tagPlanExtTimeV2[IMOSDefLibrary.IMOS_EXCP_DAYS];
	public tagPlanTimeV2() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("astPlanTimeV2", "ulPlanExtTimeNum", "astPlanExtTimeV2");
	}
	/**
	 * @param astPlanTimeV2 C type : PLAN_WEEKTIME_V2_S[IMOS_WEEK_DAYS]<br>
	 * @param ulPlanExtTimeNum C type : int<br>
	 * @param astPlanExtTimeV2 C type : PLAN_EXTTIME_V2_S[IMOS_EXCP_DAYS]
	 */
	public tagPlanTimeV2(tagPlanWeekTimeV2 astPlanTimeV2[], int ulPlanExtTimeNum, tagPlanExtTimeV2 astPlanExtTimeV2[]) {
		super();
		if ((astPlanTimeV2.length != this.astPlanTimeV2.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.astPlanTimeV2 = astPlanTimeV2;
		this.ulPlanExtTimeNum = ulPlanExtTimeNum;
		if ((astPlanExtTimeV2.length != this.astPlanExtTimeV2.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.astPlanExtTimeV2 = astPlanExtTimeV2;
	}
	public tagPlanTimeV2(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagPlanTimeV2 implements Structure.ByReference {
		
	};
	public static class ByValue extends tagPlanTimeV2 implements Structure.ByValue {
		
	};
}