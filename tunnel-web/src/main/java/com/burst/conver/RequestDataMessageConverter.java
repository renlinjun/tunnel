package com.burst.conver;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import com.burst.common.MessageData;
import com.burst.common.RequestData;
import com.burst.common.ResponseData;
import org.springframework.http.HttpInputMessage;
import org.springframework.http.HttpOutputMessage;
import org.springframework.http.MediaType;
import org.springframework.http.converter.AbstractHttpMessageConverter;
import org.springframework.http.converter.HttpMessageNotReadableException;
import org.springframework.http.converter.HttpMessageNotWritableException;

import com.alibaba.fastjson.JSONObject;

/**
 * 请求数据格式统一处理类
 * @author RLJ
 *
 */
public class RequestDataMessageConverter extends AbstractHttpMessageConverter<MessageData> {


	@Override
	public List<MediaType> getSupportedMediaTypes() {
		List<MediaType> mediaTypes = new ArrayList<MediaType>();
		mediaTypes.add(MediaType.ALL);
		return mediaTypes;
	}

	

	@Override
	protected boolean supports(Class<?> clazz) {
		if(RequestData.class.isAssignableFrom(clazz)) {
			return true;
		}
		return false;
	}

	@Override
	protected RequestData readInternal(Class<? extends MessageData> clazz, HttpInputMessage inputMessage)
			throws IOException, HttpMessageNotReadableException {
		
		RequestData requestData = null;
		try {
			requestData = (RequestData)clazz.newInstance();
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		}
		
		InputStream is = inputMessage.getBody();	
		byte[] data = new byte[is.available()];
		JSONObject json = null;
		//判断请求内容中是否有数据
		if(data.length<=0) {
			//如果没有请求数据则放一个空的JSONObject
			json = new JSONObject();
			requestData.setData(json);
		}else {
			//否则读取请求中的请求数据
			is.read(data);
			String dataStr = new String(data, "UTF-8");
			json = JSONObject.parseObject(dataStr);
			if(json.containsKey("data")) {
				requestData.setData(json.getJSONObject("data"));
			}else {
				requestData.setData(json);
			}
		}
		
		return requestData;
	}

	/**
	 *向外客户端写该对象数据时会用到该方法
	 */
	@Override
	protected void writeInternal(MessageData responseData, HttpOutputMessage outputMessage)
			throws IOException, HttpMessageNotWritableException {
		// TODO Auto-generated method stub
		System.out.println("writeInternal。。。。。。");
		
		ResponseData resData = (ResponseData)responseData;

	}

	

}
