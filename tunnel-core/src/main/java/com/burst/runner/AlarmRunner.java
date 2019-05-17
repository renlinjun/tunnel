package com.burst.runner;

import com.burst.thread.AlarmThread;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

/**
 * @描述: 启动告警数据扫描线程
 * @作者: REN
 * @时间: 2019/5/3 00:43
 */
@Component
@Order(5)
public class AlarmRunner implements ApplicationRunner {

    @Autowired
    private AlarmThread thread;

    @Override
    public void run(ApplicationArguments args) throws Exception {
        thread.start();
    }
}
