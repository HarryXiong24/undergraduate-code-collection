package com.xhw.entity;

import org.springframework.stereotype.Controller;

/**
 * 用户类
 */
public class User {
    private String name;
    private String password;

    public User() {
    }

    public User(String name, String password) {
        this.name = name;
        this.password = password;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void SayHello() {
        try {
            int i = 2/0;
        } catch (ArithmeticException e) {
            System.out.println("发生了异常");
        }

        System.out.println("Hello " + this.name);
    }
}


