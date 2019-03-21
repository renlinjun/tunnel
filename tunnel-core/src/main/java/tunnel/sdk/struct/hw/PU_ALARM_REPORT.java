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
public class PU_ALARM_REPORT extends Structure {
	/** \u544a\u8b66\u8bbe\u5907ID */
	public NativeLong ulDeviceId;
	/**
	 * \u544a\u8b66\u7c7b\u578b<br>
	 * C type : PU_ALARM_TYPE_E
	 */
	public int enAlarmType;
	/**
	 * \u544a\u8b66\u53d1\u751f\u65f6\u95f4<br>
	 * C type : PU_TIME_S
	 */
	public PU_TIME stTime;
	/**
	 * \u544a\u8b66\u53d1\u751f/\u6d88\u9664<br>
	 * C type : PU_ALARM_ACTION_E
	 */
	public int enAction;
	/** \u544a\u8b66ID */
	public NativeLong ulAlarmId;
	/** C type : CHAR[32] */
	public byte[] szReserve = new byte[32];
	public PU_ALARM_REPORT() {
		super();
	}
	protected List<String> getFieldOrder() {
		return Arrays.asList("ulDeviceId", "enAlarmType", "stTime", "enAction", "ulAlarmId", "szReserve");
	}
	/**
	 * @param ulDeviceId \u544a\u8b66\u8bbe\u5907ID<br>
	 * @param enAlarmType \u544a\u8b66\u7c7b\u578b<br>
	 * C type : PU_ALARM_TYPE_E<br>
	 * @param stTime \u544a\u8b66\u53d1\u751f\u65f6\u95f4<br>
	 * C type : PU_TIME_S<br>
	 * @param enAction \u544a\u8b66\u53d1\u751f/\u6d88\u9664<br>
	 * C type : PU_ALARM_ACTION_E<br>
	 * @param ulAlarmId \u544a\u8b66ID<br>
	 * @param szReserve C type : CHAR[32]
	 */
	public PU_ALARM_REPORT(NativeLong ulDeviceId, int enAlarmType, PU_TIME stTime, int enAction, NativeLong ulAlarmId, byte szReserve[]) {
		super();
		this.ulDeviceId = ulDeviceId;
		this.enAlarmType = enAlarmType;
		this.stTime = stTime;
		this.enAction = enAction;
		this.ulAlarmId = ulAlarmId;
		if ((szReserve.length != this.szReserve.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.szReserve = szReserve;
	}
	public PU_ALARM_REPORT(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_ALARM_REPORT implements Structure.ByReference {
		
	};
	public static class ByValue extends PU_ALARM_REPORT implements Structure.ByValue {
		
	};
}