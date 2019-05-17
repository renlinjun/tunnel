package com.burst.config;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/25 17:13
 */
@Component
public class VmServerProperties {
    @Value("${vm.server.addr}")
    private String address;
    @Value("${vm.server.port}")
    private int port;
    @Value("${vm.server.username}")
    private String username;
    @Value("${vm.server.password}")
    private String password;
    public void setAddress(String address) {
        this.address = address;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setPort(int port) {
        this.port = port;
    }

    public int getPort() {
        return port;
    }

    public String getAddress() {
        return address;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}
