package com.burst.sdk.struct.hw;
import com.sun.jna.Pointer;
import com.sun.jna.Union;
/**
 * <i>native declaration : D:\HWPuSDK.h</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class PU_EVENT_NOTIFY_BODY extends Union {
	/**
	 * \u901a\u7528\u4e8b\u4ef6<br>
	 * C type : PU_EVENT_COMMON_S
	 */
	public PU_EVENT_COMMON stPuEventCommon;
	/**
	 * IPC\u6d41\u5957\u9910\u53d8\u66f4<br>
	 * C type : PU_EVENT_STEAM_PACKAGE_CHANGE_S
	 */
	public PU_EVENT_STEAM_PACKAGE_CHANGE stPuStreamPackgeChange;
	/**
	 * \u524d\u7aef\u8bf7\u6c42\u4e0a\u4f20\u56fe\u7247URL<br>
	 * C type : PU_EVENT_UPLOAD_IMAGE_URL_S
	 */
	public PU_EVENT_UPLOAD_IMAGE_URL stPuUploadImageURL;
	/**
	 * \u524d\u7aef\u56fe\u7247\u4e0a\u4f20\u5b8c\u6210\u901a\u77e5<br>
	 * C type : PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S
	 */
	public PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY stUploadCompNotify;
	/**
	 * \u524d\u7aefDEC\u4e3b\u52a8\u6ce8\u518c<br>
	 * C type : PU_DEC_CALLBACK_INFO_S
	 */
	public PU_DEC_CALLBACK_INFO stPuDecRegister;
	/**
	 * \u524d\u7aef\u8bbe\u5907\u8fde\u63a5\u72b6\u6001<br>
	 * C type : PU_CONNECT_STATUS_S
	 */
	public PU_CONNECT_STATUS stPuConnetStatus;
	/**
	 * \u524d\u7aefIPC\u4e3b\u52a8\u6ce8\u518c<br>
	 * C type : PU_EVENT_REGISTER_S
	 */
	public PU_EVENT_REGISTER stPuIpcRegister;
	/**
	 * \u900f\u660e\u901a\u9053\u6570\u636e\u4e0a\u62a5<br>
	 * C type : PU_EVENT_TRANSPARENT_S
	 */
	public PU_EVENT_TRANSPARENT stTransparentChannelNotify;
	/**
	 * \u6570\u5b57\u6c34\u5370<br>
	 * C type : PU_WATER_MARK_S
	 */
	public PU_WATER_MARK stPuWaterMark;
	/**
	 * \u53ef\u89c6\u5316\u4fe1\u606f\u4e0a\u62a5<br>
	 * C type : PU_PTZ_REPORT_INFO_S
	 */
	public PU_PTZ_REPORT_INFO stVisualInfo;
	public PU_EVENT_NOTIFY_BODY() {
		super();
	}
	/**
	 * @param stPuEventCommon \u901a\u7528\u4e8b\u4ef6<br>
	 * C type : PU_EVENT_COMMON_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_EVENT_COMMON stPuEventCommon) {
		super();
		this.stPuEventCommon = stPuEventCommon;
		setType(PU_EVENT_COMMON.class);
	}
	/**
	 * @param stPuStreamPackgeChange IPC\u6d41\u5957\u9910\u53d8\u66f4<br>
	 * C type : PU_EVENT_STEAM_PACKAGE_CHANGE_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_EVENT_STEAM_PACKAGE_CHANGE stPuStreamPackgeChange) {
		super();
		this.stPuStreamPackgeChange = stPuStreamPackgeChange;
		setType(PU_EVENT_STEAM_PACKAGE_CHANGE.class);
	}
	/**
	 * @param stPuUploadImageURL \u524d\u7aef\u8bf7\u6c42\u4e0a\u4f20\u56fe\u7247URL<br>
	 * C type : PU_EVENT_UPLOAD_IMAGE_URL_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_EVENT_UPLOAD_IMAGE_URL stPuUploadImageURL) {
		super();
		this.stPuUploadImageURL = stPuUploadImageURL;
		setType(PU_EVENT_UPLOAD_IMAGE_URL.class);
	}
	/**
	 * @param stUploadCompNotify \u524d\u7aef\u56fe\u7247\u4e0a\u4f20\u5b8c\u6210\u901a\u77e5<br>
	 * C type : PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY stUploadCompNotify) {
		super();
		this.stUploadCompNotify = stUploadCompNotify;
		setType(PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY.class);
	}
	/**
	 * @param stPuDecRegister \u524d\u7aefDEC\u4e3b\u52a8\u6ce8\u518c<br>
	 * C type : PU_DEC_CALLBACK_INFO_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_DEC_CALLBACK_INFO stPuDecRegister) {
		super();
		this.stPuDecRegister = stPuDecRegister;
		setType(PU_DEC_CALLBACK_INFO.class);
	}
	/**
	 * @param stPuConnetStatus \u524d\u7aef\u8bbe\u5907\u8fde\u63a5\u72b6\u6001<br>
	 * C type : PU_CONNECT_STATUS_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_CONNECT_STATUS stPuConnetStatus) {
		super();
		this.stPuConnetStatus = stPuConnetStatus;
		setType(PU_CONNECT_STATUS.class);
	}
	/**
	 * @param stPuIpcRegister \u524d\u7aefIPC\u4e3b\u52a8\u6ce8\u518c<br>
	 * C type : PU_EVENT_REGISTER_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_EVENT_REGISTER stPuIpcRegister) {
		super();
		this.stPuIpcRegister = stPuIpcRegister;
		setType(PU_EVENT_REGISTER.class);
	}
	/**
	 * @param stTransparentChannelNotify \u900f\u660e\u901a\u9053\u6570\u636e\u4e0a\u62a5<br>
	 * C type : PU_EVENT_TRANSPARENT_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_EVENT_TRANSPARENT stTransparentChannelNotify) {
		super();
		this.stTransparentChannelNotify = stTransparentChannelNotify;
		setType(PU_EVENT_TRANSPARENT.class);
	}
	/**
	 * @param stPuWaterMark \u6570\u5b57\u6c34\u5370<br>
	 * C type : PU_WATER_MARK_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_WATER_MARK stPuWaterMark) {
		super();
		this.stPuWaterMark = stPuWaterMark;
		setType(PU_WATER_MARK.class);
	}
	/**
	 * @param stVisualInfo \u53ef\u89c6\u5316\u4fe1\u606f\u4e0a\u62a5<br>
	 * C type : PU_PTZ_REPORT_INFO_S
	 */
	public PU_EVENT_NOTIFY_BODY(PU_PTZ_REPORT_INFO stVisualInfo) {
		super();
		this.stVisualInfo = stVisualInfo;
		setType(PU_PTZ_REPORT_INFO.class);
	}
	public PU_EVENT_NOTIFY_BODY(Pointer peer) {
		super(peer);
	}
	public static class ByReference extends PU_EVENT_NOTIFY_BODY implements com.sun.jna.Structure.ByReference {
		
	};
	public static class ByValue extends PU_EVENT_NOTIFY_BODY implements com.sun.jna.Structure.ByValue {
		
	};
}
