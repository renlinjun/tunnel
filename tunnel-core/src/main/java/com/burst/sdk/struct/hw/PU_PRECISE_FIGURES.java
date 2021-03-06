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
public class PU_PRECISE_FIGURES extends Structure {
	/** \u6570\u5b57\u6574\u6570\u90e8\u5206 */
	public NativeLong ulIntValue;
	/** \u6570\u5b57\u5c0f\u6570\u90e8\u5206 */
	public NativeLong ulDotValue;
	public PU_PRECISE_FIGURES() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulIntValue", "ulDotValue");
	}
	/**
	 * @param ulIntValue \u6570\u5b57\u6574\u6570\u90e8\u5206<br>
	 * @param ulDotValue \u6570\u5b57\u5c0f\u6570\u90e8\u5206
	 */
	public PU_PRECISE_FIGURES(NativeLong ulIntValue, NativeLong ulDotValue) {
		super();
		this.ulIntValue = ulIntValue;
		this.ulDotValue = ulDotValue;
	}
	public PU_PRECISE_FIGURES(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_PRECISE_FIGURES implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_PRECISE_FIGURES implements Structure.ByValue {
		
	};
}
