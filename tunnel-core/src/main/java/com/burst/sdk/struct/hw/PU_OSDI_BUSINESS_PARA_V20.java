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
public class PU_OSDI_BUSINESS_PARA_V20 extends Structure {
	/** \u901a\u9053\u53f7 */
	public NativeLong ulChannelID;
	/** OSDI\u603b\u5f00\u5173 */
	public boolean bOSDIEnable;
	/** \u5f53\u524d\u533a\u57df\u6570\u91cf */
	public NativeLong ulOSDINum;
	/**
	 * OSDI\u533a\u57df\u4fe1\u606f<br>
	 * C type : PU_OSDI_AREA_CFG_PARA_V20_S[(8)]
	 */
	public PU_OSDI_AREA_CFG_PARA_V20[] stOSDIAreaPara = new PU_OSDI_AREA_CFG_PARA_V20[8];
	public PU_OSDI_BUSINESS_PARA_V20() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulChannelID", "bOSDIEnable", "ulOSDINum", "stOSDIAreaPara");
	}
	/**
	 * @param ulChannelID \u901a\u9053\u53f7<br>
	 * @param bOSDIEnable OSDI\u603b\u5f00\u5173<br>
	 * @param ulOSDINum \u5f53\u524d\u533a\u57df\u6570\u91cf<br>
	 * @param stOSDIAreaPara OSDI\u533a\u57df\u4fe1\u606f<br>
	 * C type : PU_OSDI_AREA_CFG_PARA_V20_S[(8)]
	 */
	public PU_OSDI_BUSINESS_PARA_V20(NativeLong ulChannelID, boolean bOSDIEnable, NativeLong ulOSDINum, PU_OSDI_AREA_CFG_PARA_V20 stOSDIAreaPara[]) {
		super();
		this.ulChannelID = ulChannelID;
		this.bOSDIEnable = bOSDIEnable;
		this.ulOSDINum = ulOSDINum;
		if ((stOSDIAreaPara.length != this.stOSDIAreaPara.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.stOSDIAreaPara = stOSDIAreaPara;
	}
	public PU_OSDI_BUSINESS_PARA_V20(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_OSDI_BUSINESS_PARA_V20 implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_OSDI_BUSINESS_PARA_V20 implements Structure.ByValue {
		
	};
}
