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
public class PU_FACE_DETC_PARA extends Structure {
	/** \u544a\u8b66\u68c0\u6d4b\u65f6\u95f4 */
	public NativeLong ulAlarmTime;
	/** \u4f7f\u80fd */
	public boolean bEnable;
	/** \u68c0\u6d4b\u7075\u654f\u5ea6 */
	public NativeLong ulSensitivity;
	/** \u6700\u5c0f\u68c0\u6d4b\u4eba\u8138 */
	public NativeLong ulMinDectFace;
	/** \u6700\u5927\u68c0\u6d4b\u4eba\u8138 */
	public NativeLong ulMaxDectFace;
	/** \u68c0\u6d4b\u6a21\u5f0f 0:\u6b63\u5e38\u6a21\u5f0f */
	public NativeLong ulDectMode;
	/** C type : CHAR[32] */
	public byte[] szReserved = new byte[32];
	public PU_FACE_DETC_PARA() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulAlarmTime", "bEnable", "ulSensitivity", "ulMinDectFace", "ulMaxDectFace", "ulDectMode", "szReserved");
	}
	/**
	 * @param ulAlarmTime \u544a\u8b66\u68c0\u6d4b\u65f6\u95f4<br>
	 * @param bEnable \u4f7f\u80fd<br>
	 * @param ulSensitivity \u68c0\u6d4b\u7075\u654f\u5ea6<br>
	 * @param ulMinDectFace \u6700\u5c0f\u68c0\u6d4b\u4eba\u8138<br>
	 * @param ulMaxDectFace \u6700\u5927\u68c0\u6d4b\u4eba\u8138<br>
	 * @param ulDectMode \u68c0\u6d4b\u6a21\u5f0f 0:\u6b63\u5e38\u6a21\u5f0f<br>
	 * @param szReserved C type : CHAR[32]
	 */
	public PU_FACE_DETC_PARA(NativeLong ulAlarmTime, boolean bEnable, NativeLong ulSensitivity, NativeLong ulMinDectFace, NativeLong ulMaxDectFace, NativeLong ulDectMode, byte szReserved[]) {
		super();
		this.ulAlarmTime = ulAlarmTime;
		this.bEnable = bEnable;
		this.ulSensitivity = ulSensitivity;
		this.ulMinDectFace = ulMinDectFace;
		this.ulMaxDectFace = ulMaxDectFace;
		this.ulDectMode = ulDectMode;
		if ((szReserved.length != this.szReserved.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserved = szReserved;
	}
	public PU_FACE_DETC_PARA(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_FACE_DETC_PARA implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_FACE_DETC_PARA implements Structure.ByValue {
		
	};
}
