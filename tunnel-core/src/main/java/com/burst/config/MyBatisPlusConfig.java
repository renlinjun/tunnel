package com.burst.config;

import com.baomidou.mybatisplus.spring.boot.starter.ConfigurationCustomizer;
import com.burst.wrapper.MapWrapperFactory;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/8 16:44
 */
@Configuration
@MapperScan(basePackages = "com.burst.*.dao")
public class MyBatisPlusConfig {

    @Bean
    public ConfigurationCustomizer mybatisConfigurationCustomizer(){
        return new ConfigurationCustomizer() {
            @Override
            public void customize(org.apache.ibatis.session.Configuration configuration) {
                configuration.setObjectWrapperFactory(new MapWrapperFactory());
            }
        };
    }
}