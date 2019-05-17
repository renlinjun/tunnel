package com.burst.runner;

import com.burst.bayonet.BayonetHandler;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;

/**
 * @描述: 播放器随系统启动
 * @作者: REN
 * @时间: 2019/4/9 15:51
 */
//@Component
//@Order(3)
public class PlayerRunner implements ApplicationRunner {
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
        bayonetHandler.startLiveVideoStream();
    }
}
