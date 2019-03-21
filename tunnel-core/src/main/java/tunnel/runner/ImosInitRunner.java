package tunnel.runner;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;
import tunnel.bayonet.BayonetHandler;
import tunnel.exception.CustomException;
import tunnel.imos.ImosLogin;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/21 09:16
 */
@Component
@Order(1)
public class ImosInitRunner implements ApplicationRunner {

    @Autowired
    public BayonetHandler bayonetHandler;

    /**
     * Callback used to run the bean.
     *
     * @param args incoming application arguments
     * @throws Exception on error
     */
    @Override
    public void run(ApplicationArguments args) throws Exception {
        System.out.println("开始登录imos平台");
        init();
        System.out.println("imos平台登录完成");
    }

    /**
     *
     * 功能描述:
     *      imos协议初始化，包括初始化imos协议，登录imos服务器，并且保存登录信息
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    private void init() {
        try {
            ImosLogin.login(true);
        } catch (CustomException e) {
            e.printStackTrace();
            System.out.println("登录IMOS器服务失败：["+e.getCode()+"]");
        }
    }
}
