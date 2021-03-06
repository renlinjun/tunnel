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
public class PU_ITS_SIGNAL_LIGHT_AREA_PARAM extends Structure {
	/**
	 * \u4fe1\u53f7\u706f\u5bfc\u5411<br>
	 * C type : PU_ITS_LIGHT_DIR_S
	 */
	public PU_ITS_LIGHT_DIR stLightDir;
	/**
	 * \u4fe1\u53f7\u706f\u989c\u8272<br>
	 * C type : PU_ITS_LIGHT_COLOR_S
	 */
	public PU_ITS_LIGHT_COLOR stLightColor;
	/** \u706f\u4e2a\u6570 */
	public int iLightNum;
	/**
	 * \u4fe1\u53f7\u706f\u5b89\u88c5\u65b9\u5f0f<br>
	 * C type : PU_ITS_LIGHT_ARRANGE_TYPE_E
	 */
	public int enLightArrangeType;
	/** \u9ec4\u706f\u6301\u7eed\u65f6\u95f4 */
	public int iYellowTime;
	/**
	 * \u4fe1\u53f7\u706f\u4f4d\u7f6e\u6846<br>
	 * C type : PU_MD_AREA_S
	 */
	public PU_MD_AREA stLightArea;
	/** C type : CHAR[32] */
	public byte[] szReserve = new byte[32];
	public PU_ITS_SIGNAL_LIGHT_AREA_PARAM() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stLightDir", "stLightColor", "iLightNum", "enLightArrangeType", "iYellowTime", "stLightArea", "szReserve");
	}
	/**
	 * @param stLightDir \u4fe1\u53f7\u706f\u5bfc\u5411<br>
	 * C type : PU_ITS_LIGHT_DIR_S<br>
	 * @param stLightColor \u4fe1\u53f7\u706f\u989c\u8272<br>
	 * C type : PU_ITS_LIGHT_COLOR_S<br>
	 * @param iLightNum \u706f\u4e2a\u6570<br>
	 * @param enLightArrangeType \u4fe1\u53f7\u706f\u5b89\u88c5\u65b9\u5f0f<br>
	 * C type : PU_ITS_LIGHT_ARRANGE_TYPE_E<br>
	 * @param iYellowTime \u9ec4\u706f\u6301\u7eed\u65f6\u95f4<br>
	 * @param stLightArea \u4fe1\u53f7\u706f\u4f4d\u7f6e\u6846<br>
	 * C type : PU_MD_AREA_S<br>
	 * @param szReserve C type : CHAR[32]
	 */
	public PU_ITS_SIGNAL_LIGHT_AREA_PARAM(PU_ITS_LIGHT_DIR stLightDir, PU_ITS_LIGHT_COLOR stLightColor, int iLightNum, int enLightArrangeType, int iYellowTime, PU_MD_AREA stLightArea, byte szReserve[]) {
		super();
		this.stLightDir = stLightDir;
		this.stLightColor = stLightColor;
		this.iLightNum = iLightNum;
		this.enLightArrangeType = enLightArrangeType;
		this.iYellowTime = iYellowTime;
		this.stLightArea = stLightArea;
		if ((szReserve.length != this.szReserve.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserve = szReserve;
	}
	public PU_ITS_SIGNAL_LIGHT_AREA_PARAM(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_ITS_SIGNAL_LIGHT_AREA_PARAM implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_ITS_SIGNAL_LIGHT_AREA_PARAM implements Structure.ByValue {
		
	};
}
