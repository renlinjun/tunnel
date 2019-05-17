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
public class PU_INIT_DECODE_INFO_RSP extends Structure {
	/**
	 * \u89e3\u7801\u5668\u7684\u5a92\u4f53IP<br>
	 * C type : CHAR[16]
	 */
	public byte[] szDecMediaIp = new byte[16];
	/**
	 * \u89e3\u7801\u5668\u7684\u7aef\u53e3\u4fe1\u606f<br>
	 * C type : PU_PORT_INFO_S
	 */
	public PU_PORT_INFO stDecPortInfo;
	/** C type : CHAR[32] */
	public byte[] szReserve = new byte[32];
	public PU_INIT_DECODE_INFO_RSP() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szDecMediaIp", "stDecPortInfo", "szReserve");
	}
	/**
	 * @param szDecMediaIp \u89e3\u7801\u5668\u7684\u5a92\u4f53IP<br>
	 * C type : CHAR[16]<br>
	 * @param stDecPortInfo \u89e3\u7801\u5668\u7684\u7aef\u53e3\u4fe1\u606f<br>
	 * C type : PU_PORT_INFO_S<br>
	 * @param szReserve C type : CHAR[32]
	 */
	public PU_INIT_DECODE_INFO_RSP(byte szDecMediaIp[], PU_PORT_INFO stDecPortInfo, byte szReserve[]) {
		super();
		if ((szDecMediaIp.length != this.szDecMediaIp.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDecMediaIp = szDecMediaIp;
		this.stDecPortInfo = stDecPortInfo;
		if ((szReserve.length != this.szReserve.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserve = szReserve;
	}
	public PU_INIT_DECODE_INFO_RSP(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_INIT_DECODE_INFO_RSP implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_INIT_DECODE_INFO_RSP implements Structure.ByValue {
		
	};
}