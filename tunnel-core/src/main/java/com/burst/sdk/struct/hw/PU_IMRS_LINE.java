package com.burst.sdk.struct.hw;
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
public class PU_IMRS_LINE extends Structure {
	/** C type : PU_IGT_POINT_S */
	public PU_IGT_POINT stStartPoint;
	/** C type : PU_IGT_POINT_S */
	public PU_IGT_POINT stEndPoint;
	public PU_IMRS_LINE() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stStartPoint", "stEndPoint");
	}
	/**
	 * @param stStartPoint C type : PU_IGT_POINT_S<br>
	 * @param stEndPoint C type : PU_IGT_POINT_S
	 */
	public PU_IMRS_LINE(PU_IGT_POINT stStartPoint, PU_IGT_POINT stEndPoint) {
		super();
		this.stStartPoint = stStartPoint;
		this.stEndPoint = stEndPoint;
	}
	public PU_IMRS_LINE(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_IMRS_LINE implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_IMRS_LINE implements Structure.ByValue {
		
	};
}