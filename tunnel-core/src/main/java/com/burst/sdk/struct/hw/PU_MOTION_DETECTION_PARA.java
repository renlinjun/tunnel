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
public class PU_MOTION_DETECTION_PARA extends Structure {
	/** \u89c6\u9891\u901a\u9053ID */
	public NativeLong ulChannelId;
	/** \u4f7f\u80fd */
	public NativeLong lEnable;
	/** \u68c0\u6d4b\u4e8b\u4ef6\u95f4\u96941~30s\uff0c\u5728\u8be5\u95f4\u9694\u5185\u7684\u8fd0\u52a8\u90fd\u4f5c\u4e3a\u7edf\u4e00\u8fd0\u52a8 */
	public NativeLong ulInterval;
	/** \u8fd0\u52a8\u68c0\u6d4b\u7075\u654f\u5ea61~5\uff0c\u6570\u5b57\u8d8a\u9ad8\u8d8a\u7075\u654f */
	public NativeLong ulSensitivity;
	/** \u544a\u8b66\u68c0\u6d4b\u65f6\u95f4\u95f4\u96941~256\uff0c\u6bcfx\u79d2\u68c0\u6d4b\u4e00\u6b21\u662f\u5426\u5728\u544a\u8b66\u72b6\u6001 */
	public NativeLong ulDeteInterval;
	/**
	 * \u544a\u8b66\u68c0\u6d4b\u533a\u57df<br>
	 * C type : PU_DETECTION_AREA_S
	 */
	public PU_DETECTION_AREA stDetectionArea;
	/**
	 * \u5e03\u9632\u65f6\u95f4\u5217\u8868<br>
	 * C type : PU_ALARM_TIME_LIST_S
	 */
	public PU_ALARM_TIME_PARA_LIST stAlarmTimeList;
	public PU_MOTION_DETECTION_PARA() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulChannelId", "lEnable", "ulInterval", "ulSensitivity", "ulDeteInterval", "stDetectionArea", "stAlarmTimeList");
	}
	/**
	 * @param ulChannelId \u89c6\u9891\u901a\u9053ID<br>
	 * @param lEnable \u4f7f\u80fd<br>
	 * @param ulInterval \u68c0\u6d4b\u4e8b\u4ef6\u95f4\u96941~30s\uff0c\u5728\u8be5\u95f4\u9694\u5185\u7684\u8fd0\u52a8\u90fd\u4f5c\u4e3a\u7edf\u4e00\u8fd0\u52a8<br>
	 * @param ulSensitivity \u8fd0\u52a8\u68c0\u6d4b\u7075\u654f\u5ea61~5\uff0c\u6570\u5b57\u8d8a\u9ad8\u8d8a\u7075\u654f<br>
	 * @param ulDeteInterval \u544a\u8b66\u68c0\u6d4b\u65f6\u95f4\u95f4\u96941~256\uff0c\u6bcfx\u79d2\u68c0\u6d4b\u4e00\u6b21\u662f\u5426\u5728\u544a\u8b66\u72b6\u6001<br>
	 * @param stDetectionArea \u544a\u8b66\u68c0\u6d4b\u533a\u57df<br>
	 * C type : PU_DETECTION_AREA_S<br>
	 * @param stAlarmTimeList \u5e03\u9632\u65f6\u95f4\u5217\u8868<br>
	 * C type : PU_ALARM_TIME_LIST_S
	 */
	public PU_MOTION_DETECTION_PARA(NativeLong ulChannelId, NativeLong lEnable, NativeLong ulInterval, NativeLong ulSensitivity, NativeLong ulDeteInterval, PU_DETECTION_AREA stDetectionArea, PU_ALARM_TIME_PARA_LIST stAlarmTimeList) {
		super();
		this.ulChannelId = ulChannelId;
		this.lEnable = lEnable;
		this.ulInterval = ulInterval;
		this.ulSensitivity = ulSensitivity;
		this.ulDeteInterval = ulDeteInterval;
		this.stDetectionArea = stDetectionArea;
		this.stAlarmTimeList = stAlarmTimeList;
	}
	public PU_MOTION_DETECTION_PARA(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_MOTION_DETECTION_PARA implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_MOTION_DETECTION_PARA implements Structure.ByValue {
		
	};
}
