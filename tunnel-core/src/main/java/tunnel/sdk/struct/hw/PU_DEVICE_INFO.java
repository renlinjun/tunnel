package tunnel.sdk.struct.hw;
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
public class PU_DEVICE_INFO extends Structure {
	/**
	 * \u8bbe\u5907\u540d\u79f0\u6700\u957f32\u4f4d<br>
	 * C type : CHAR[32]
	 */
	public byte[] szDeviceName = new byte[32];
	/**
	 * \u8bbe\u5907\u5382\u5546<br>
	 * C type : CHAR[12]
	 */
	public byte[] szDeviceFac = new byte[12];
	/**
	 * \u8bbe\u5907\u578b\u53f7,\u53ea\u53ef\u67e5\u8be2\u4e0d\u53ef\u8bbe\u7f6e<br>
	 * C type : CHAR[32]
	 */
	public byte[] szDeviceType = new byte[32];
	/**
	 * \u786c\u4ef6\u5e8f\u5217\u53f7<br>
	 * C type : CHAR[32]
	 */
	public byte[] szSerialNumber = new byte[32];
	/**
	 * \u8bbe\u5907\u7248\u672c<br>
	 * C type : PU_DEVICE_VERSION
	 */
	public PU_DEVICE_VERSION stDeviceVersion;
	/** C type : CHAR[32] */
	public byte[] szReserved = new byte[32];
	public PU_DEVICE_INFO() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("szDeviceName", "szDeviceFac", "szDeviceType", "szSerialNumber", "stDeviceVersion", "szReserved");
	}
	/**
	 * @param szDeviceName \u8bbe\u5907\u540d\u79f0\u6700\u957f32\u4f4d<br>
	 * C type : CHAR[32]<br>
	 * @param szDeviceFac \u8bbe\u5907\u5382\u5546<br>
	 * C type : CHAR[12]<br>
	 * @param szDeviceType \u8bbe\u5907\u578b\u53f7,\u53ea\u53ef\u67e5\u8be2\u4e0d\u53ef\u8bbe\u7f6e<br>
	 * C type : CHAR[32]<br>
	 * @param szSerialNumber \u786c\u4ef6\u5e8f\u5217\u53f7<br>
	 * C type : CHAR[32]<br>
	 * @param stDeviceVersion \u8bbe\u5907\u7248\u672c<br>
	 * C type : PU_DEVICE_VERSION<br>
	 * @param szReserved C type : CHAR[32]
	 */
	public PU_DEVICE_INFO(byte szDeviceName[], byte szDeviceFac[], byte szDeviceType[], byte szSerialNumber[], PU_DEVICE_VERSION stDeviceVersion, byte szReserved[]) {
		super();
		if ((szDeviceName.length != this.szDeviceName.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDeviceName = szDeviceName;
		if ((szDeviceFac.length != this.szDeviceFac.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDeviceFac = szDeviceFac;
		if ((szDeviceType.length != this.szDeviceType.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szDeviceType = szDeviceType;
		if ((szSerialNumber.length != this.szSerialNumber.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szSerialNumber = szSerialNumber;
		this.stDeviceVersion = stDeviceVersion;
		if ((szReserved.length != this.szReserved.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserved = szReserved;
	}
	public PU_DEVICE_INFO(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_DEVICE_INFO implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_DEVICE_INFO implements Structure.ByValue {
		
	};
}