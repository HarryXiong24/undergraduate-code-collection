package com.xhw.controller;

import com.xhw.entity.User;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.Map;

@Controller
public class ChangePasswordController {
    @PostMapping("/changePassword")
    public String changePassword(@RequestParam("oldPassword") String oldPassword,
                                 @RequestParam("newPassword") String newPassword, Map<String,User> map) {

        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-mvc.xml");
        User user = applicationContext.getBean(User.class);

        if(oldPassword.equals(user.getPassword())) {
            user.setPassword(newPassword);
            map.put("user",user);
            return "userinfo";
        } else {
            return "error";
        }
    }
}
