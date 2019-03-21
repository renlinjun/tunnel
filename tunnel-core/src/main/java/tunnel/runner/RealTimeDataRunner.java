package tunnel.runner;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;
import tunnel.bayonet.BayonetHandler;
import tunnel.exception.CustomException;


/**
 * @描述: 实时数据接口
 * @作者: REN
 * @时间: 2019/3/21 09:31
 */
@Component
@Order(2)
public class RealTimeDataRunner implements ApplicationRunner {

    @Autowired
    public BayonetHandler bayonetHandler;

    /**
     * Callback used to run the bean.
     *
     * @param args incoming application arguments
     * @throws Exception on error
     */
    @Override
    public void run(ApplicationArguments args) {
        System.out.println("开启实时数据");
        try {
            bayonetHandler.actualInfo();
        } catch (CustomException e) {
            e.printStackTrace();
            System.out.println("开启实况数据失败![code="+e.getCode()+"][msg="+e.getMsg()+"]");
        }
        System.out.println("实时数据开启成功");
    }
}
