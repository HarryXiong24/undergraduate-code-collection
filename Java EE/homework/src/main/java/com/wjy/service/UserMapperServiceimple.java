package com.wjy.service;

import com.wjy.dao.UserMapper;
import com.wjy.pojo.Comment;
import com.wjy.pojo.Movielist;
import com.wjy.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.ArrayList;
import java.util.List;

public class UserMapperServiceimple implements UserMapperService {
    @Autowired
    UserMapper userMapper;

    public UserMapper getUserMapper() {
        return userMapper;
    }

    public void setUserMapper(UserMapper userMapper) {
        this.userMapper = userMapper;
    }

    public void update(User user) {

    }

    public void deleteUser(int id) {

    }

    public List<User> SelectUser() {
        return userMapper.SelectUser();
    }

    public User getUserById(int id) {
        return null;
    }

    public boolean token(User user) {
        List<User> userslist= userMapper.SelectUser();
        int logic=0;
        for (User user1 : userslist) {
            if (user1.getUsername().equals(user.getUsername())){
                if (user1.getPassword().equals(user.getPassword())){
                    logic=1;
                }
            }
        }
        if (logic==1){
            return true;
        }
        else
            return false;
    }
    //检验用户登录帐户密码
    public User returnuser(boolean a, String name) {
        List<User> userslist= userMapper.SelectUser();
        User nowuser=new User();
        nowuser=null;
        if (a){
            for (User user : userslist) {
                if (user.getUsername().equals(name)){
                    nowuser=user;
                }
            }
        }
        return nowuser;
    }

    public User returnuserr(User user) {
        List<User> userslist= userMapper.SelectUser();
        User nowuser=new User();
        nowuser.setMsg("用户名或密码错误");
        nowuser.setSuccess("false");
        for (User user1 : userslist) {
            if (user1.getUsername().equals(user.getUsername())){
                if (user1.getPassword().equals(user.getPassword())){
                    nowuser=user1;
                    nowuser.setMsg("登陆成功");
                    nowuser.setSuccess("true");
                }
            }
        }
        return nowuser;
    } //通过传入的用户来检验登录情况以及返回一个success信号


    public boolean addUser(User user) {
        List<User> userslist= userMapper.SelectUser();
        user.setToken("user");
        for (User user1 : userslist) {
            if (user1.getUsername().equals(user.getUsername())){
                return false;
            }
        }
        userMapper.addUser(user);
        return true;
    }
    //注册用户的功能并返回是否注册成功


    public List<Movielist> showmovie() {
        List<Movielist> userslist= userMapper.showmovie();
        return userslist;
    }

    public void releaseComment(Comment comment) {
         userMapper.releaseComment(comment);
    }
   //发表评论，需要得到一个封装好的comment对象

    //显示所有电影详情页
    public List<Comment> showcomment(String id) {
        List<Comment> userslist= userMapper.showcomment(id);
        List<Comment> nowuserslist=  new ArrayList<Comment>();
        for (Comment comment : userslist) {
            if (Integer.toString(comment.getID()).equals(id)){
                nowuserslist.add(comment);
            }
        }
        return nowuserslist;
    }


    //返回带参名字的所有电影
    public void releasemovie( Movielist movielist) {
        userMapper.releasemovie(movielist);
    }
//通过判断用户是否是管理员来确定该用户是否有发布电影的能力
public void RemoveComment(int id) {
    userMapper.RemoveComment(id);
}
}
