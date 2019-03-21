package tunnel.sdk.struct.hw;
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
public class PU_FACE_PROCESS_DL_PARAM extends Structure {
	/** \u53d1\u9001\u4eba\u8138\u62a0\u56fe */
	public boolean bSendFaceImg;
	/** \u53d1\u9001\u4eba\u4f53\u62a0\u56fe */
	public boolean bSendBodyImg;
	/** \u53d1\u9001\u5168\u666f\u56fe */
	public boolean bSendPanorama;
	/** \u56fe\u50cf\u589e\u5f3a */
	public boolean bFaceEnhancement;
	/** \u4eba\u8138\u56fe\u6293\u62cd\u8d28\u91cf(1-10) */
	public NativeLong ulFaceImgQuality;
	/** \u4eba\u4f53\u62a0\u56fe\u8d28\u91cf(1-10) */
	public NativeLong ulBodyImgQuality;
	/** \u5168\u666f\u56fe\u6293\u62cd\u8d28\u91cf(1-10) */
	public NativeLong ulPanoramaImgQuality;
	/** \u53d1\u9001\u7684\u4eba\u8138\u5c0f\u56fe\u6570\u91cf */
	public NativeLong ulSendFaceNum;
	/** \u53d1\u9001\u7684\u4eba\u4f53\u5c0f\u56fe\u6570\u91cf */
	public NativeLong ulSendBodyNum;
	/** C type : CHAR[32] */
	public byte[] szReserved = new byte[32];
	public PU_FACE_PROCESS_DL_PARAM() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("bSendFaceImg", "bSendBodyImg", "bSendPanorama", "bFaceEnhancement", "ulFaceImgQuality", "ulBodyImgQuality", "ulPanoramaImgQuality", "ulSendFaceNum", "ulSendBodyNum", "szReserved");
	}
	public PU_FACE_PROCESS_DL_PARAM(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_FACE_PROCESS_DL_PARAM implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_FACE_PROCESS_DL_PARAM implements Structure.ByValue {
		
	};
}