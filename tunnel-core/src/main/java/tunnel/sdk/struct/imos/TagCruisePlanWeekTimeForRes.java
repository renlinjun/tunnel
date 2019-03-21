package tunnel.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;
import static tunnel.sdk.constanst.IMOSDefLibrary.*;
/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class TagCruisePlanWeekTimeForRes extends Structure {
	/** C type : int */
	public int ulWeekDay;
	/** C type : TIME_SLICE_FOR_RES_S[IMOS_MAX_CRUISE_TIME_SLICE_NUM] */
	public tagTimeSliceForRes[] astTimeInfo = new tagTimeSliceForRes[IMOS_MAX_CRUISE_TIME_SLICE_NUM];
	public TagCruisePlanWeekTimeForRes() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulWeekDay", "astTimeInfo");
	}
	/**
	 * @param ulWeekDay C type : int<br>
	 * @param astTimeInfo C type : TIME_SLICE_FOR_RES_S[IMOS_MAX_CRUISE_TIME_SLICE_NUM]
	 */
	public TagCruisePlanWeekTimeForRes(int ulWeekDay, tagTimeSliceForRes astTimeInfo[]) {
		super();
		this.ulWeekDay = ulWeekDay;
		if ((astTimeInfo.length != this.astTimeInfo.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.astTimeInfo = astTimeInfo;
	}
	public TagCruisePlanWeekTimeForRes(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagCruisePlanWeekTimeForRes implements Structure.ByReference {
		
	};
	public static class ByValue extends TagCruisePlanWeekTimeForRes implements Structure.ByValue {
		
	};
}