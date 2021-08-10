package com.wjy.controler;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.wjy.pojo.*;
import com.wjy.service.MovieBoxOfficeServiceImpl;
import com.wjy.service.UserMapperService;
import com.wjy.service.bookservice;
import com.wjy.ulitis.jsonn;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@CrossOrigin(origins = "*", maxAge = 3600)
@Controller
public class controler {
    @Autowired
    @Qualifier("bookserviceimpl")
    private bookservice bookservice;
    @Autowired
    @Qualifier("UserMapperServiceimple")
    private UserMapperService userMapperService;
    @Autowired
    private MovieBoxOfficeServiceImpl movieBoxOfficeService;


//    @RequestMapping("/hello")
//    public String welcom(Model model){
//        List<Books> list=bookservice.selectbook();
//        model.addAttribute("msg",list);
//        return "hello";
//    }
//    @RequestMapping("/login")
//    public String login(User user,Model model){
//        User user1=new User();
//        user1=userMapperService.returnuserr(user);
//        if (user1.getSuccess().equals("true")){
//            model.addAttribute("msg",user1);
//            return "success";
//        }
//        return "erro";
//    }
//    @RequestMapping("/UserList")
//    public String User(Model model){
//        model.addAttribute("msg",userMapperService.SelectUser());
//        return "user";
//
//    }

    @RequestMapping(value = "/loginl",method = RequestMethod.POST,produces = "application/json; charset=utf-8")
    @ResponseBody
    public String loginll(@RequestBody String json) {
       User user1=new User();
       JSON json1 = JSONObject.parseObject(json);
       User user = JSON.toJavaObject(json1, User.class);
       user1= userMapperService.returnuserr(user);
        String s= jsonn.objectTojson(user1);
        return s;
    }//登录页传入正确的用户会传出{"id":"1","msg":"????","password":"52013114","success":"true","token":"admin","username":"zhj"}类似的数据
    //错误的用户会传出{"id":"0","msg":"????????","password":"","success":"false","token":"","username":""}
    @RequestMapping(value = "/register",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String register(@RequestBody String json){
        MSg mSg=new MSg();
        mSg.setMsg("注册失败");
        mSg.setSuccess("false");
        JSON json1 = JSONObject.parseObject(json);
        User user = JSON.toJavaObject(json1, User.class);
      boolean registinfo=userMapperService.addUser(user);
      if (registinfo){
          mSg.setMsg("注册成功");
          mSg.setSuccess("true");
      }
        return JSON.toJSONString(mSg);
    }
    //收到前端传过来的User对象通过检验数据库是否有该对象来返回true或者false来表示是否注册成功
    @RequestMapping(value = "/Movieinfo",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String movie() {
        List<Movielist> movielist=userMapperService.showmovie();
        String s= JSON.toJSONString(movielist);
        return s;
    }//显示当前所有电影的方法
    //返回类似[{"date":1608218717000,"launcher":1,"movieActor":"徐峥","movieDetail":"某某某","movieID":1,"movieInfo":"反映中国现代社会现状","movieName":"我不是药神","moviePoint":8.0},{"date":1608218766000,"launcher":1,"movieActor":"银河",
    // "movieDetail":"旭旭","movieID":2,"movieInfo":"很暖的爱情电影","movieName":"叫我第三名","moviePoint":9.0},
    // {"date":1608218805000,"launcher":1,"movieActor":"蓄水","movieDetail":"新海诚","movieID":3,"movieInfo":"很有趣的电影","movieName":"你的名字","moviePoint":8.0},
    // {"date":1608233043000,"launcher":2,"movieID":10,"movieName":"将杠八比"}]
    @RequestMapping(value = "/movieComment",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String movieComment(@RequestBody String json) {
        JSON json1 = JSONObject.parseObject(json);
        IDDD idfiy= JSON.toJavaObject(json1, IDDD.class);
        List<Comment> commentList=userMapperService.showcomment(idfiy.getId());
        String s=JSON.toJSONString(commentList);
        return s;
    }
   // [{"comment":"还可以吧，挺好用的","date":1608224544000,"iD":1,"name":"zhj","point":9.0},{"comment":"二刷二刷，太感人了有没有","date":
      //  1608230700000,"iD":1,"name":"zhj","point":9.0},{"comment":"听朋友来看的，感觉真不错","date":1608230749000,"iD":1,"name":"xhw","point":9.5}]
    @RequestMapping(value = "/LaunchMovie",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String LaunchMovie(@RequestBody String json){
        JSON json1 = JSONObject.parseObject(json);
        Movielist movielist= JSON.toJavaObject(json1, Movielist.class);
        MSg mSg=new MSg();
        mSg.setMsg("发布成功");
        mSg.setSuccess("true");
       userMapperService.releasemovie(movielist);
        return JSON.toJSONString(mSg);
    }
    //发布电影的功能
    @RequestMapping(value = "/LaunchComment",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String LaunchComment(@RequestBody String json){
        JSON json1 = JSONObject.parseObject(json);
        Comment comment= JSON.toJavaObject(json1,Comment.class);
        userMapperService.releaseComment(comment);
        MSg mSg=new MSg();
        mSg.setSuccess("true");
        mSg.setMsg("发布成功");
        return JSON.toJSONString(mSg);
    }
    //用户发布评论的功能
    @RequestMapping(value = "/RemoveComment",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String RemoveComment(@RequestBody String json){
        JSON json1 = JSONObject.parseObject(json);
        IDDD idfiy= JSON.toJavaObject(json1, IDDD.class);
        userMapperService.RemoveComment(Integer.valueOf(idfiy.getId()));
        MSg mSg=new MSg();
        mSg.setSuccess("true");
        mSg.setMsg("删除成功");
        return JSON.toJSONString(mSg);
    }

    @RequestMapping(value = "/movieBoxOffice",produces = "application/json; charset=utf-8")
    @ResponseBody
    public String getMovieBoxOffice() {
        MovieBoxOfficeResult movieBoxOffice = movieBoxOfficeService.getMovieBoxOffice();
        return JSON.toJSONString(movieBoxOffice);

    }


}
