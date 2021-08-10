package com.xhw.controller;

import com.xhw.entity.User;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class LoginController {
    @PostMapping("/login")
    public String login(@ModelAttribute("user") User loginUser ) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-mvc.xml");
        User user = applicationContext.getBean(User.class);
        if(loginUser.getUsername().equals(user.getUsername()) &&
                loginUser.getPassword().equals(user.getPassword())) {
            System.out.println("成功");
            return  "success";
        } else {
            return "error";
        }
    }
}
