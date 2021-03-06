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
public class META_POLYGON_S extends Structure {
	/** \u70b9\u4e2a\u6570 */
	public int uPointNum;
	/** C type : META_POINT_S[(10)] */
	public META_POINT_S[] astPts = new META_POINT_S[10];
	public META_POLYGON_S() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("uPointNum", "astPts");
	}
	/**
	 * @param uPointNum \u70b9\u4e2a\u6570<br>
	 * @param astPts C type : META_POINT_S[(10)]
	 */
	public META_POLYGON_S(int uPointNum, META_POINT_S astPts[]) {
		super();
		this.uPointNum = uPointNum;
		if ((astPts.length != this.astPts.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.astPts = astPts;
	}
	public META_POLYGON_S(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends META_POLYGON_S implements Structure.ByReference {
		
	};
	public static class ByValue extends META_POLYGON_S implements Structure.ByValue {
		
	};
}
