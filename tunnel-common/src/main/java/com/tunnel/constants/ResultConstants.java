package com.tunnel.constants;


import tunnel.common.ResponseData;

/**
 * 请求返回的结果枚举
 * 系统级别从900开始，其他为1-100
 * @author 任琳珺
 * 2018-12-05
 *
 */
public class ResultConstants {
	/**
	 * 成功标志
	 */
	public static int SUCCESS_CODE = 0;


	/**
	 * 登录验证失败
	 */
	public static int LOGIN_CHECK_FAIL = 2;

	public static int TOKEN_CHECK_FAIL = -1;
	
	/**
	 * 操作失败
	 */
	public static int OPT_FAIL = 1;

	/**
	 * 全局异常结果代码
	 */
	public static int EXCEPTION_CODE = 2;

	/**
	 * 流操作失败
	 */
	public static int STREAM_OPT_FAIL = 3;
	
	/**
	 * 数据检查错误
	 */
	public static int DATA_CHECK_ERROR = 6;

	/**
	 * 文件操作异常
	 */
	public static int FILE_OPT_EXCEPTION_CODE = 7;

	/**
	 * 缺失参数参数
	 */
	public static int MISS_ARGS_CDOE = 997;

	/**
	 * 非法的参数
	 */
	public static int INVALID_ARGS_CODE = 998;

	/**
	 * 系统错误
	 */
	public static int SYS_ERROR_CODE = 999;

	/**
	 *
	 * 文件超出设置大小
	 */
	public static int FILE_MAX_SIZE_EXCEEDED = 10;
	
	/**预定于成功标志*/
	public static ResponseData SUCCESS_RESULT = new ResponseData(SUCCESS_CODE,"操作成功");

	/** 参数错误结果 */
	public static ResponseData INVALID_ARGS_RESULT = new ResponseData(INVALID_ARGS_CODE,"非法的参数");

	/** 缺失参数结果 */
	public static ResponseData MISS_ARGS_RESULT = new ResponseData(MISS_ARGS_CDOE,"缺失必要参数");
	
}
