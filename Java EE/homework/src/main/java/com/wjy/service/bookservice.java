package com.wjy.service;

import com.wjy.pojo.Books;

import java.util.List;

public interface bookservice {
    int addbook(Books books);
    int deletebook(int id);
    List<Books> selectbook();
    int updatebook(Books books);

}
