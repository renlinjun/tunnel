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
public class PU_ONVIF_SWITCH extends Structure {
	/** ONVIF\u5f00\u5173 */
	public boolean bEnable;
	/** C type : CHAR[32] */
	public byte[] szReserve = new byte[32];
	public PU_ONVIF_SWITCH() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("bEnable", "szReserve");
	}
	/**
	 * @param bEnable ONVIF\u5f00\u5173<br>
	 * @param szReserve C type : CHAR[32]
	 */
	public PU_ONVIF_SWITCH(boolean bEnable, byte szReserve[]) {
		super();
		this.bEnable = bEnable;
		if ((szReserve.length != this.szReserve.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserve = szReserve;
	}
	public PU_ONVIF_SWITCH(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_ONVIF_SWITCH implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_ONVIF_SWITCH implements Structure.ByValue {
		
	};
}