package com.burst;

import com.burst.config.DataSourceConfig;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.jdbc.DataSourceAutoConfiguration;

/**
 * @描述: web程序启动类
 * @作者: REN
 * @时间: 2019/3/20 16:58
 */
@SpringBootApplication(exclude = {DataSourceAutoConfiguration.class})
public class WebApp {
    public static void main(String args[]) {
        SpringApplication.run(WebApp.class);
    }
}
