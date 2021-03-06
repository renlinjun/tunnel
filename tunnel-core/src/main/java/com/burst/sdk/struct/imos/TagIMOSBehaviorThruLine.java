package com.burst.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import static com.burst.sdk.constanst.IMOSDefLibrary.IMOS_COORDINATE_STR_LEN_16;


/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class TagIMOSBehaviorThruLine extends Structure {
    /**
     * C type : CHAR[IMOS_COORDINATE_STR_LEN_16]
     */
    public byte[] szLine = new byte[IMOS_COORDINATE_STR_LEN_16];
    /**
     * C type : int
     */
    public int ulDirection;
    /**
     * C type : int
     */
    public int ulHeight;
    /**
     * C type : int
     */
    public int ulColor;
    /**
     * C type : CHAR[128]
     */
    public byte[] szReserve = new byte[128];

    public TagIMOSBehaviorThruLine() {
        super();
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("szLine", "ulDirection", "ulHeight", "ulColor", "szReserve");
    }

    /**
     * @param szLine      C type : CHAR[IMOS_COORDINATE_STR_LEN_16]<br>
     * @param ulDirection C type : int<br>
     * @param ulHeight    C type : int<br>
     * @param ulColor     C type : int<br>
     * @param szReserve   C type : CHAR[128]
     */
    public TagIMOSBehaviorThruLine(byte szLine[], int ulDirection, int ulHeight, int ulColor, byte szReserve[]) {
        super();
        if ((szLine.length != this.szLine.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.szLine = szLine;
        this.ulDirection = ulDirection;
        this.ulHeight = ulHeight;
        this.ulColor = ulColor;
        if ((szReserve.length != this.szReserve.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.szReserve = szReserve;
    }

    public TagIMOSBehaviorThruLine(Pointer peer) {
        super(peer);
    }

    public static class ByReference extends TagIMOSBehaviorThruLine implements Structure.ByReference {

    }

    ;

    public static class ByValue extends TagIMOSBehaviorThruLine implements Structure.ByValue {

    }

    ;
}
