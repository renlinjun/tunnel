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
public class PU_PTZ_SPEED_ABILITY extends Structure {
	/** \u6c34\u5e73\u6700\u5927\u901f\u5ea6(\u5355\u4f4d:\u5ea6/\u79d2) */
	public NativeLong ulPanSpeedMax;
	/** \u5782\u76f4\u6700\u5927\u901f\u5ea6(\u5355\u4f4d:\u5ea6/\u79d2) */
	public NativeLong ulTiltSpeedMax;
	public PU_PTZ_SPEED_ABILITY() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulPanSpeedMax", "ulTiltSpeedMax");
	}
	/**
	 * @param ulPanSpeedMax \u6c34\u5e73\u6700\u5927\u901f\u5ea6(\u5355\u4f4d:\u5ea6/\u79d2)<br>
	 * @param ulTiltSpeedMax \u5782\u76f4\u6700\u5927\u901f\u5ea6(\u5355\u4f4d:\u5ea6/\u79d2)
	 */
	public PU_PTZ_SPEED_ABILITY(NativeLong ulPanSpeedMax, NativeLong ulTiltSpeedMax) {
		super();
		this.ulPanSpeedMax = ulPanSpeedMax;
		this.ulTiltSpeedMax = ulTiltSpeedMax;
	}
	public PU_PTZ_SPEED_ABILITY(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_PTZ_SPEED_ABILITY implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_PTZ_SPEED_ABILITY implements Structure.ByValue {
		
	};
}
