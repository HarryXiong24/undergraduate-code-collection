package com.wjy.service;

import com.wjy.dao.bookmapper;
import com.wjy.pojo.Books;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.ArrayList;
import java.util.List;

public class bookserviceimpl implements bookservice {
    @Autowired
    private bookmapper bookmapper;

    public com.wjy.dao.bookmapper getBookmapper() {
        return bookmapper;
    }

    public void setBookmapper(com.wjy.dao.bookmapper bookmapper) {
        this.bookmapper = bookmapper;
    }

    public bookserviceimpl(com.wjy.dao.bookmapper bookmapper) {
        this.bookmapper = bookmapper;
    }

    public bookserviceimpl() {
    }

    public int addbook(Books books) {
        return bookmapper.addbook(books);
    }

    public int deletebook(int id) {
        return 0;
    }

    public List<Books> selectbook() {
        List<Books> booksList=bookmapper.selectbook();
        List<Books> booksList1=new ArrayList<Books>();
        for (Books books : booksList) {
            if (books.getBookId()==2){
                booksList1.add(books);
            }
        }
        return booksList1;
    }

    public int updatebook(Books books) {
        return 0;
    }
}
