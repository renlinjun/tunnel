package com.burst.config;

import com.burst.websocket.TunnelMessageHandler;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.server.ServerHttpRequest;
import org.springframework.http.server.ServerHttpResponse;
import org.springframework.lang.Nullable;
import org.springframework.web.socket.WebSocketHandler;
import org.springframework.web.socket.config.annotation.EnableWebSocket;
import org.springframework.web.socket.config.annotation.WebSocketConfigurer;
import org.springframework.web.socket.config.annotation.WebSocketHandlerRegistry;
import org.springframework.web.socket.server.support.HttpSessionHandshakeInterceptor;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/1/15 17:00
 */
@Configuration
@EnableWebSocket
public class WebSocketConfig implements WebSocketConfigurer {

    @Override
    public void registerWebSocketHandlers(WebSocketHandlerRegistry registry) {
        registry.addHandler(myHandler(), "/handMessage")
                .addInterceptors(customizSessionHandshake())
                .setAllowedOrigins("*");
    }


    @Bean
    public HttpSessionHandshakeInterceptor customizSessionHandshake() {
        return new HttpSessionHandshakeInterceptor() {
            public void afterHandshake(ServerHttpRequest request, ServerHttpResponse response, WebSocketHandler wsHandler, @Nullable Exception ex) {
                this.setCopyHttpSessionId(false);
                System.out.println("afterHandshake。。。。。。");
            }
        };
    }

    @Bean
    public WebSocketHandler myHandler() {
        return new TunnelMessageHandler();
    }
}
