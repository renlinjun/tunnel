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
public class PU_DEC_DECRYPTION_INFO extends Structure {
	/** \u89e3\u5bc6\u7684\u901a\u9053\u53f7 */
	public NativeLong ulChannelId;
	/** \u89e3\u5bc6\u4f7f\u80fd\u72b6\u6001 */
	public boolean bEnable;
	/**
	 * \u89e3\u5bc6\u7b97\u6cd5\u7c7b\u578b<br>
	 * C type : PU_ENCRYPT_TYPE_E
	 */
	public int enDecryptionType;
	/**
	 * \u89c6\u9891\u5bc6\u94a5<br>
	 * C type : CHAR[44]
	 */
	public byte[] szVideoCrypto = new byte[44];
	/**
	 * \u97f3\u9891\u5bc6\u94a5<br>
	 * C type : CHAR[44]
	 */
	public byte[] szAudioCrypto = new byte[44];
	public PU_DEC_DECRYPTION_INFO() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulChannelId", "bEnable", "enDecryptionType", "szVideoCrypto", "szAudioCrypto");
	}
	/**
	 * @param ulChannelId \u89e3\u5bc6\u7684\u901a\u9053\u53f7<br>
	 * @param bEnable \u89e3\u5bc6\u4f7f\u80fd\u72b6\u6001<br>
	 * @param enDecryptionType \u89e3\u5bc6\u7b97\u6cd5\u7c7b\u578b<br>
	 * C type : PU_ENCRYPT_TYPE_E<br>
	 * @param szVideoCrypto \u89c6\u9891\u5bc6\u94a5<br>
	 * C type : CHAR[44]<br>
	 * @param szAudioCrypto \u97f3\u9891\u5bc6\u94a5<br>
	 * C type : CHAR[44]
	 */
	public PU_DEC_DECRYPTION_INFO(NativeLong ulChannelId, boolean bEnable, int enDecryptionType, byte szVideoCrypto[], byte szAudioCrypto[]) {
		super();
		this.ulChannelId = ulChannelId;
		this.bEnable = bEnable;
		this.enDecryptionType = enDecryptionType;
		if ((szVideoCrypto.length != this.szVideoCrypto.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szVideoCrypto = szVideoCrypto;
		if ((szAudioCrypto.length != this.szAudioCrypto.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szAudioCrypto = szAudioCrypto;
	}
	public PU_DEC_DECRYPTION_INFO(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_DEC_DECRYPTION_INFO implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_DEC_DECRYPTION_INFO implements Structure.ByValue {
		
	};
}
