package tunnel.core;

import com.alibaba.fastjson.JSONObject;

/**
 * @描述: 推送数据
 * @作者: 任琳珺
 * @时间: 2019/4/15 15:21
 */
public class PushData {

    private int dataType;
    private Object data;

    public PushData() {}

    public PushData(int dataType,Object jsonData) {
        this.dataType = dataType;
        this.data = jsonData;
    }

    public void setDataType(int dataType) {
        this.dataType = dataType;
    }

    public void setJsonData(Object data) {
        this.data = data;
    }

    public int getDataType() {
        return dataType;
    }

    public Object getJsonData() {
        return this.data;
    }

}
