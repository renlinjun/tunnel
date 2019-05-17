package com.burst.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.scheduling.annotation.EnableAsync;
import org.springframework.scheduling.concurrent.ThreadPoolTaskExecutor;

import java.util.concurrent.Executor;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/6 09:40
 */
@Configuration
@EnableAsync
public class ExecutorConfig {
    /** Set the ThreadPoolExecutor's core pool size. */
    private int corePoolSize = 5;
    /** Set the ThreadPoolExecutor's maximum pool size. */
    private int maxPoolSize = 20;
    /** Set the capacity for the ThreadPoolExecutor's BlockingQueue. */
    private int queueCapacity = 10;

    @Bean
    public Executor vehicleDataExecutor() {
        ThreadPoolTaskExecutor executor = new ThreadPoolTaskExecutor();
        executor.setCorePoolSize(corePoolSize);
        executor.setMaxPoolSize(maxPoolSize);
        executor.setQueueCapacity(queueCapacity);
        executor.setThreadNamePrefix("MessageHandlerExecutor-");
        executor.initialize();
        return executor;
    }

}
