package tunnel.common;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.alibaba.fastjson.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

/**
 * 客户端请求数据的封装
 * @author RLJ
 *
 */
public class RequestData {
	
	/** 当前第几页 */
	private int page = 1;
	/** 每页显示条数 */
	private int pageSize = -1;
	/** 总页数 */
	private int totalPage;
	/** 分页查询开始记录，第一条记录从0开始 */
	private int start = 0;
	
	/**客户端请求的数据*/
	private  JSONObject data;

	public int getPage() {
		return page;
	}

	public void setPage(int page) {
		this.page = page;
	}

	public int getPageSize() {
		return this.pageSize;
	}

	public void setPageSize(int pageSize) {
		this.pageSize = pageSize;
	}

	public int getTotalPage() {
		return this.totalPage;
	}

	public void setTotalPage(int totalPage) {
		this.pageSize = pageSize;
	}

	public void setData(JSONObject data) {
		this.data = data;
	}

	public JSONObject getData() {
		return this.data;
	}

	
	@Override
	public String toString() {
		return data.toJSONString();
	}
	
	
	/**
	 * 将请求中的数据转换为相应的实体对象
	 * @return
	 */
	public <T> T parseObj(Class<T> clazz) {
		JSONObject json = this.getData();
		Set<String> keys = json.keySet();
		Map<String,Object> beanMap = new HashMap<String,Object>();
		Iterator<String> it = keys.iterator();
		//将数据从map中取出转换为bean
		while(it.hasNext()) {
			String key = it.next();
			Object value = json.get(key);
			beanMap.put(StrUtil.toCamelCase(key), value);
		}
		return BeanUtil.mapToBean(beanMap, clazz, false);
		
	}
}
