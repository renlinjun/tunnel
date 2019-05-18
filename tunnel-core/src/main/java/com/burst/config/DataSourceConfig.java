package com.burst.config;


import javax.sql.DataSource;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/9 10:20
 */
//@Configuration
public class DataSourceConfig {

    /*@Bean
    public DataSource druidDataSource(Environment env) {
        DruidDataSource datasource = new DruidDataSource();
        datasource.setUrl(env.getProperty("spring.datasource.url"));
        datasource.setUsername(env.getProperty("spring.datasource.username"));
        datasource.setPassword(env.getProperty("spring.datasource.password"));
        datasource.setDriverClassName(env.getProperty("spring.datasource.driver-class-name"));
        datasource.setInitialSize(10);
        *//*datasource.setMinIdle(env.);
        datasource.setMaxActive(maxActive);
        datasource.setMaxWait(maxWait);
        datasource.setTimeBetweenEvictionRunsMillis(timeBetweenEvictionRunsMillis);
        datasource.setMinEvictableIdleTimeMillis(minEvictableIdleTimeMillis);
        datasource.setValidationQuery(validationQuery);
        datasource.setTestWhileIdle(testWhileIdle);
        datasource.setTestOnBorrow(testOnBorrow);
        datasource.setTestOnReturn(testOnReturn);*//*
        return datasource;
    }*/
}
