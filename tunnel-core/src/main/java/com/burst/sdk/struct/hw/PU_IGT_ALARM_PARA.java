package com.burst.sdk.struct.hw;
import com.burst.sdk.library.HWPuSDKLibrary;
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
public class PU_IGT_ALARM_PARA extends Structure {
	public NativeLong ulChannelId;
	/** \u667a\u80fd\u603b\u5f00\u5173 */
	public boolean bIgtEnable;
	/** \u76ee\u6807\u8f68\u8ff9\u8ddf\u8e2a\u4f7f\u80fd */
	public boolean bTrackEnable;
	/**
	 * \u573a\u666f\u6a21\u5f0f\u7c7b\u578b<br>
	 * C type : PU_IGT_FIELD_TYPE_E
	 */
	public int enFieldType;
	/**
	 * \u524d\u666f\u76ee\u6807\u6700\u5c0f\u5c3a\u5bf8\u8bbe\u5b9a<br>
	 * C type : PU_IGT_MINTARGET_SIZE_E
	 */
	public int enMinTargetSize;
	/**
	 * \u53bb\u9634\u5f71\u6a21\u5f0f\u8bbe\u5b9a<br>
	 * C type : PU_IGT_SHADOW_MODE_E
	 */
	public int enShadowMode;
	/**
	 * \u76ee\u6807\u68c0\u6d4b\u7075\u654f\u5ea6\u8bbe\u5b9a<br>
	 * C type : PU_IGT_DETECT_SENS_E
	 */
	public int enDetectSens;
	/** \u662f\u5426\u663e\u793a\u4e0d\u654f\u611f\u76ee\u6807\u4fe1\u606f */
	public boolean bInsensitiveObject;
	/**
	 * szReserved[0] \u8868\u793a\u6700\u5c0f\u76ee\u6807\u5c3a\u5bf8\u5bbd(5~200\u4e14\u5c0f\u4e8e\u6700\u5927\u5c3a\u5bf8)<br>
	 * C type : UCHAR[32]
	 */
	public HWPuSDKLibrary.UCHAR[] szReserved = new HWPuSDKLibrary.UCHAR[32];
	public PU_IGT_ALARM_PARA() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulChannelId", "bIgtEnable", "bTrackEnable", "enFieldType", "enMinTargetSize", "enShadowMode", "enDetectSens", "bInsensitiveObject", "szReserved");
	}
	/**
	 * @param bIgtEnable \u667a\u80fd\u603b\u5f00\u5173<br>
	 * @param bTrackEnable \u76ee\u6807\u8f68\u8ff9\u8ddf\u8e2a\u4f7f\u80fd<br>
	 * @param enFieldType \u573a\u666f\u6a21\u5f0f\u7c7b\u578b<br>
	 * C type : PU_IGT_FIELD_TYPE_E<br>
	 * @param enMinTargetSize \u524d\u666f\u76ee\u6807\u6700\u5c0f\u5c3a\u5bf8\u8bbe\u5b9a<br>
	 * C type : PU_IGT_MINTARGET_SIZE_E<br>
	 * @param enShadowMode \u53bb\u9634\u5f71\u6a21\u5f0f\u8bbe\u5b9a<br>
	 * C type : PU_IGT_SHADOW_MODE_E<br>
	 * @param enDetectSens \u76ee\u6807\u68c0\u6d4b\u7075\u654f\u5ea6\u8bbe\u5b9a<br>
	 * C type : PU_IGT_DETECT_SENS_E<br>
	 * @param bInsensitiveObject \u662f\u5426\u663e\u793a\u4e0d\u654f\u611f\u76ee\u6807\u4fe1\u606f<br>
	 * @param szReserved szReserved[0] \u8868\u793a\u6700\u5c0f\u76ee\u6807\u5c3a\u5bf8\u5bbd(5~200\u4e14\u5c0f\u4e8e\u6700\u5927\u5c3a\u5bf8)<br>
	 * C type : UCHAR[32]
	 */
	public PU_IGT_ALARM_PARA(NativeLong ulChannelId, boolean bIgtEnable, boolean bTrackEnable, int enFieldType, int enMinTargetSize, int enShadowMode, int enDetectSens, boolean bInsensitiveObject, HWPuSDKLibrary.UCHAR szReserved[]) {
		super();
		this.ulChannelId = ulChannelId;
		this.bIgtEnable = bIgtEnable;
		this.bTrackEnable = bTrackEnable;
		this.enFieldType = enFieldType;
		this.enMinTargetSize = enMinTargetSize;
		this.enShadowMode = enShadowMode;
		this.enDetectSens = enDetectSens;
		this.bInsensitiveObject = bInsensitiveObject;
		if ((szReserved.length != this.szReserved.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserved = szReserved;
	}
	public PU_IGT_ALARM_PARA(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_IGT_ALARM_PARA implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_IGT_ALARM_PARA implements Structure.ByValue {
		
	};
}
