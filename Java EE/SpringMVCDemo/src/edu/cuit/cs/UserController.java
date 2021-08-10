package edu.cuit.cs;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import java.util.HashMap;
import java.util.Map;

@Controller
public class UserController {
    @RequestMapping(value="login")
    private String Login(){
        System.out.println("login");
        return "login";
    }
    @RequestMapping(value="doLogin1")
    private ModelAndView DoLogin(User user){
        Map<String,Object> model = new HashMap<String,Object>();
        model.put("user",user);
        if (user.getUsername().equals("admin") && user.getUserpassword().equals("admin")){
            return new ModelAndView("success", model);
        }else{
            return new ModelAndView("error", model);
        }
    }
    @RequestMapping(value="doLogin")
    private String DoLogin1(User user){
        System.out.println(user.getUsername());
        return "index";
    }
}
