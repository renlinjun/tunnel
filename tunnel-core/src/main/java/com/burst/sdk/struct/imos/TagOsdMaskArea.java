package com.burst.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
import static com.burst.sdk.constanst.IMOSDefLibrary.*;
/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class TagOsdMaskArea extends Structure {
	/** C type : VIDEO_AREA_S[IMOS_MASK_AREA_MAXNUM] */
	public tagVideoArea[] astMaskArea = new tagVideoArea[IMOS_MASK_AREA_MAXNUM];
	public TagOsdMaskArea() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("astMaskArea");
	}
	/** @param astMaskArea C type : VIDEO_AREA_S[IMOS_MASK_AREA_MAXNUM] */
	public TagOsdMaskArea(tagVideoArea astMaskArea[]) {
		super();
		if ((astMaskArea.length != this.astMaskArea.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.astMaskArea = astMaskArea;
	}
	public TagOsdMaskArea(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends TagOsdMaskArea implements Structure.ByReference {
		
	};
	public static class ByValue extends TagOsdMaskArea implements Structure.ByValue {
		
	};
}