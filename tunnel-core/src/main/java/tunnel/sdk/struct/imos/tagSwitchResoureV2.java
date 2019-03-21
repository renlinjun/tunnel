package tunnel.sdk.struct.imos;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;

import static tunnel.sdk.constanst.SDKDef.IMOS_SWITCH_CAM_MAXNUM_V2;

/**
 * <i>native declaration : sdk_struct.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class tagSwitchResoureV2 extends Structure {
	/** C type : SWITCH_BASE_S */
	public tagSwitchBase stSwitchBaseInfo;
	/** C type : int */
	public int ulSwitchResNum;
	/** C type : SWITCH_UNIT_V2_S[IMOS_SWITCH_CAM_MAXNUM_V2] */
	public tagSwitchUnitV2[] astSwitchUnitList = new tagSwitchUnitV2[IMOS_SWITCH_CAM_MAXNUM_V2];
	public tagSwitchResoureV2() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stSwitchBaseInfo", "ulSwitchResNum", "astSwitchUnitList");
	}
	/**
	 * @param stSwitchBaseInfo C type : SWITCH_BASE_S<br>
	 * @param ulSwitchResNum C type : int<br>
	 * @param astSwitchUnitList C type : SWITCH_UNIT_V2_S[IMOS_SWITCH_CAM_MAXNUM_V2]
	 */
	public tagSwitchResoureV2(tagSwitchBase stSwitchBaseInfo, int ulSwitchResNum, tagSwitchUnitV2 astSwitchUnitList[]) {
		super();
		this.stSwitchBaseInfo = stSwitchBaseInfo;
		this.ulSwitchResNum = ulSwitchResNum;
		if ((astSwitchUnitList.length != this.astSwitchUnitList.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.astSwitchUnitList = astSwitchUnitList;
	}
	public tagSwitchResoureV2(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagSwitchResoureV2 implements Structure.ByReference {
		
	};
	public static class ByValue extends tagSwitchResoureV2 implements Structure.ByValue {
		
	};
}