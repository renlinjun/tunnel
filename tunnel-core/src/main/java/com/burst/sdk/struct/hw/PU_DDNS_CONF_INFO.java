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
public class PU_DDNS_CONF_INFO extends Structure {
	public boolean bEnable;
	/**
	 * \u7528\u6237\u8d26\u53f7\u540d<br>
	 * C type : CHAR[256]
	 */
	public byte[] szUserID = new byte[256];
	/**
	 * \u7528\u6237Pwd\u660e\u7801<br>
	 * C type : CHAR[256]
	 */
	public byte[] szUserPWD = new byte[256];
	/** C type : CHAR[32] */
	public byte[] szReserve = new byte[32];
	public PU_DDNS_CONF_INFO() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("bEnable", "szUserID", "szUserPWD", "szReserve");
	}
	/**
	 * @param szUserID \u7528\u6237\u8d26\u53f7\u540d<br>
	 * C type : CHAR[256]<br>
	 * @param szUserPWD \u7528\u6237Pwd\u660e\u7801<br>
	 * C type : CHAR[256]<br>
	 * @param szReserve C type : CHAR[32]
	 */
	public PU_DDNS_CONF_INFO(boolean bEnable, byte szUserID[], byte szUserPWD[], byte szReserve[]) {
		super();
		this.bEnable = bEnable;
		if ((szUserID.length != this.szUserID.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szUserID = szUserID;
		if ((szUserPWD.length != this.szUserPWD.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szUserPWD = szUserPWD;
		if ((szReserve.length != this.szReserve.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserve = szReserve;
	}
	public PU_DDNS_CONF_INFO(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_DDNS_CONF_INFO implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_DDNS_CONF_INFO implements Structure.ByValue {
		
	};
}
