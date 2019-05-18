package com.burst.cache;


import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 统一数据返回格式
 * @author RLJ 2018-05-10
 *
 *
 */
public class ResponseData  extends MessageData {
    private int code;
    private String msg;
    //private JSONObject data;
    private Object data;
    public ResponseData() {}
    public ResponseData(int code,String msg,Object data) {
        setDataByType(data);
        this.code = code;
        this.msg = msg;
    }
    public ResponseData(int code,String msg) {
        this(code,msg,null);
    }

    public String getMsg() {
        return msg;
    }

    public int getCode() {
        return code;
    }

    public Object getData() {
        return data;
    }

    public void setDataByType(Object data) {
        if(data instanceof List) {
            Map<String,Object> datalist = new HashMap<String,Object>();
            datalist.put("datalist",data);
            this.data = datalist;
        }else {
            this.data = data;
        }
    }
}
