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
public class PU_DEC_CHANNEL_ABILITY extends Structure {
	/**
	 * \u6620\u5c04\u5173\u7cfb<br>
	 * C type : PU_DEC_CHANNEL_PORT_MAP_S
	 */
	public PU_DEC_CHANNEL_PORT_MAP stChannelPortMap;
	/**
	 * \u89e3\u7801\u89c6\u9891\u683c\u5f0f<br>
	 * C type : PU_ENCODE_TYPE_E[4]
	 */
	public int[] enVideoDecFormats = new int[4];
	/**
	 * \u89e3\u7801\u97f3\u9891\u683c\u5f0f<br>
	 * C type : PU_ENCODE_TYPE_E[4]
	 */
	public int[] enAudioDecFormats = new int[4];
	/**
	 * \u89e3\u7801\u6700\u5927\u5206\u8fa8\u7387<br>
	 * C type : PU_RESOLUTION_TYPE_E
	 */
	public int enMaxDecResolution;
	/**
	 * \u6700\u5927\u5e27\u7387  :30\u5e27|| 60 \u5e27<br>
	 * C type : PU_FRAME_RATE_E
	 */
	public int enMaxFrameRate;
	/** 0: no support 1: support */
	public boolean bSupportDecryption;
	/** 0: no support 1: support */
	public boolean bSupportWaterMark;
	public PU_DEC_CHANNEL_ABILITY() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stChannelPortMap", "enVideoDecFormats", "enAudioDecFormats", "enMaxDecResolution", "enMaxFrameRate", "bSupportDecryption", "bSupportWaterMark");
	}
	/**
	 * @param stChannelPortMap \u6620\u5c04\u5173\u7cfb<br>
	 * C type : PU_DEC_CHANNEL_PORT_MAP_S<br>
	 * @param enVideoDecFormats \u89e3\u7801\u89c6\u9891\u683c\u5f0f<br>
	 * C type : PU_ENCODE_TYPE_E[4]<br>
	 * @param enAudioDecFormats \u89e3\u7801\u97f3\u9891\u683c\u5f0f<br>
	 * C type : PU_ENCODE_TYPE_E[4]<br>
	 * @param enMaxDecResolution \u89e3\u7801\u6700\u5927\u5206\u8fa8\u7387<br>
	 * C type : PU_RESOLUTION_TYPE_E<br>
	 * @param enMaxFrameRate \u6700\u5927\u5e27\u7387  :30\u5e27|| 60 \u5e27<br>
	 * C type : PU_FRAME_RATE_E<br>
	 * @param bSupportDecryption 0: no support 1: support<br>
	 * @param bSupportWaterMark 0: no support 1: support
	 */
	public PU_DEC_CHANNEL_ABILITY(PU_DEC_CHANNEL_PORT_MAP stChannelPortMap, int enVideoDecFormats[], int enAudioDecFormats[], int enMaxDecResolution, int enMaxFrameRate, boolean bSupportDecryption, boolean bSupportWaterMark) {
		super();
		this.stChannelPortMap = stChannelPortMap;
		if ((enVideoDecFormats.length != this.enVideoDecFormats.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.enVideoDecFormats = enVideoDecFormats;
		if ((enAudioDecFormats.length != this.enAudioDecFormats.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.enAudioDecFormats = enAudioDecFormats;
		this.enMaxDecResolution = enMaxDecResolution;
		this.enMaxFrameRate = enMaxFrameRate;
		this.bSupportDecryption = bSupportDecryption;
		this.bSupportWaterMark = bSupportWaterMark;
	}
	public PU_DEC_CHANNEL_ABILITY(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_DEC_CHANNEL_ABILITY implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_DEC_CHANNEL_ABILITY implements Structure.ByValue {
		
	};
}
