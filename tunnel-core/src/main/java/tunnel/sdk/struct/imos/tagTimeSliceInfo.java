package tunnel.sdk.struct.imos;
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
public class tagTimeSliceInfo extends Structure {
	/** C type : TIME_SLICE_S */
	public tagTimeSlice stTimeSlice;
	public tagTimeSliceInfo() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("stTimeSlice");
	}
	/** @param stTimeSlice C type : TIME_SLICE_S */
	public tagTimeSliceInfo(tagTimeSlice stTimeSlice) {
		super();
		this.stTimeSlice = stTimeSlice;
	}
	public tagTimeSliceInfo(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends tagTimeSliceInfo implements Structure.ByReference {
		
	};
	public static class ByValue extends tagTimeSliceInfo implements Structure.ByValue {
		
	};
}