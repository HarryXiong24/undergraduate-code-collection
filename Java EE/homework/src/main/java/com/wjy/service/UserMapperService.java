package com.wjy.service;

import com.wjy.pojo.Comment;
import com.wjy.pojo.Movielist;
import com.wjy.pojo.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface UserMapperService {
    public boolean addUser(User user);//注册用户，返回一个标记成功的信号
    public void update(User user);
    public void deleteUser(@Param("id") int id);
    List<User> SelectUser();
    public User getUserById(int id);
    public boolean token(User user);//检验登录信息
    public User returnuser(boolean a, String name);//返回成功登录的信息
    public User returnuserr(User user);//将msg和success放入user对象中传回数据
    //上述的所有方法对user表进行操作，此为分界线

    public List<Movielist> showmovie();//显示电影详情页
    public void releaseComment(Comment comment);


    public List<Comment> showcomment(String id);//显示某部电影的所有评论


    public void releasemovie(Movielist movielist);
    //通过判断用户是否是管理员来确定该用户是否有发布电影的能力
    public void RemoveComment(int id);
}
