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
public class PU_ITS_LIGHT_COLOR extends Structure {
	/** \u7ea2\u706f */
	public boolean bRed;
	/** \u7eff\u706f */
	public boolean bGreen;
	/** \u9ec4\u706f */
	public boolean bYellow;
	public PU_ITS_LIGHT_COLOR() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("bRed", "bGreen", "bYellow");
	}
	/**
	 * @param bRed \u7ea2\u706f<br>
	 * @param bGreen \u7eff\u706f<br>
	 * @param bYellow \u9ec4\u706f
	 */
	public PU_ITS_LIGHT_COLOR(boolean bRed, boolean bGreen, boolean bYellow) {
		super();
		this.bRed = bRed;
		this.bGreen = bGreen;
		this.bYellow = bYellow;
	}
	public PU_ITS_LIGHT_COLOR(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_ITS_LIGHT_COLOR implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_ITS_LIGHT_COLOR implements Structure.ByValue {
		
	};
}
