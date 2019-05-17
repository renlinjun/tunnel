package com.burst.runner;

import com.burst.bayonet.BayonetHandler;
import com.burst.exception.CustomException;
import com.burst.imos.ImosLogin;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/21 09:16
 */
//@Component
//@Order(1)
public class ImosInitRunner implements ApplicationRunner {

    @Autowired
    public BayonetHandler bayonetHandler;

    @Autowired
    public ImosLogin loginHandler;

    /**
     * Callback used to run the bean.
     *
     * @param args incoming application arguments
     * @throws Exception on error
     */
    @Override
    public void run(ApplicationArguments args) {
        System.out.println("开始登录imos平台");
        try {
            init();
        } catch (CustomException e) {
            e.printStackTrace();
            System.err.println("imos平台登录失败["+e.getCode()+"]");
            System.exit(-1);
        }
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
    private void init() throws CustomException {
        loginHandler.login(true);
    }
}
