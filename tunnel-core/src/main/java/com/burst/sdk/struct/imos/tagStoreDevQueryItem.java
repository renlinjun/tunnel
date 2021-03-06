package com.burst.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_DEVICE_CODE_LEN;
import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_IPADDR_LEN;
import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_NAME_LEN;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagStoreDevQueryItem extends Structure {
	/** C type : CHAR[IMOS_DEVICE_CODE_LEN] */
	public byte[] szStoreDevCode = new byte[IMOS_DEVICE_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szStoreDevName = new byte[IMOS_NAME_LEN];
	/** C type : int */
	public int ulStoreDevType;
	/** C type : CHAR[IMOS_DEVICE_CODE_LEN] */
	public byte[] szDMCode = new byte[IMOS_DEVICE_CODE_LEN];
	/** C type : CHAR[IMOS_NAME_LEN] */
	public byte[] szDMName = new byte[IMOS_NAME_LEN];
	/** C type : int */
	public int ulDevaddrtype;
	/** C type : CHAR[IMOS_IPADDR_LEN] */
	public byte[] szDevAddr = new byte[IMOS_IPADDR_LEN];
	/** C type : int */
	public int ulStoreDevTotalSize;
	/** C type : int */
	public int ulStoreDevUsedSize;
	/** C type : int */
	public int ulStoreRunStatus;
	/** C type : int */
	public int ulIsOnline;
	/** C type : int */
	public int ulDevExtStatus;
	/** C type : int */
	public int ulStoreDevSubType;
	/** C type : CHAR[60] */
	public byte[] szReserve = new byte[60];
	public tagStoreDevQueryItem() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szStoreDevCode", "szStoreDevName", "ulStoreDevType", "szDMCode", "szDMName", "ulDevaddrtype", "szDevAddr", "ulStoreDevTotalSize", "ulStoreDevUsedSize", "ulStoreRunStatus", "ulIsOnline", "ulDevExtStatus", "ulStoreDevSubType", "szReserve");
	}
	public tagStoreDevQueryItem(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagStoreDevQueryItem implements Structure.ByReference {
		
	};
	public static class ByValue extends tagStoreDevQueryItem implements Structure.ByValue {
		
	};
}
