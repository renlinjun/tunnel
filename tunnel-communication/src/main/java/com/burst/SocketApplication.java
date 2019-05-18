package com.burst;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.jdbc.DataSourceAutoConfiguration;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/1/15 17:01
 */
@SpringBootApplication(exclude = DataSourceAutoConfiguration.class)
public class SocketApplication {
    public static void main(String args[]) {
        SpringApplication.run(SocketApplication.class);
    }
}
