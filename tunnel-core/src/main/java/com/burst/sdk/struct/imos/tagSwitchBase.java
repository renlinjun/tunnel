package com.burst.sdk.struct.imos;
import com.burst.sdk.constanst.IMOSDefLibrary;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagSwitchBase extends Structure {
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szSwitchName = new byte[IMOSDefLibrary.IMOS_NAME_LEN];
	/** C type : CHAR[IMOS_DESC_LEN] */
	public byte[] szSwitchDesc = new byte[IMOSDefLibrary.IMOS_DESC_LEN];
	public tagSwitchBase() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szSwitchName", "szSwitchDesc");
	}
	/**
	 * @param szSwitchName C type : CHAR[IMOS_NAME_LEN]<br>
	 * @param szSwitchDesc C type : CHAR[IMOS_DESC_LEN]
	 */
	public tagSwitchBase(byte szSwitchName[], byte szSwitchDesc[]) {
		super();
		if ((szSwitchName.length != this.szSwitchName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szSwitchName = szSwitchName;
		if ((szSwitchDesc.length != this.szSwitchDesc.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szSwitchDesc = szSwitchDesc;
	}
	public tagSwitchBase(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagSwitchBase implements Structure.ByReference {
		
	};
	public static class ByValue extends tagSwitchBase implements Structure.ByValue {
		
	};
}
