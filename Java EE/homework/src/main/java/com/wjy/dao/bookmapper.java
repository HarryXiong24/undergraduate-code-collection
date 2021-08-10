package com.wjy.dao;

import com.wjy.pojo.Books;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;
@Mapper
public interface bookmapper  {
    int addbook(Books books);
    int deletebook(int id);
    List<Books> selectbook();
    int updatebook(Books books);

}
