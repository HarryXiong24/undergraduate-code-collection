package com.wjy.pojo;

import java.util.Date;

public class Comment {
    private int ID;
    private String name;
    private String comment;
    private Date date;
    private Double point;

    public Comment(String name, String comment, Date date, Double point, String moviename) {
        this.name = name;
        this.comment = comment;
        this.date = date;
        this.point = point;
    }

    public Comment() {
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getComment() {
        return comment;
    }

    public void setComment(String comment) {
        this.comment = comment;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public Double getPoint() {
        return point;
    }

    public void setPoint(Double point) {
        this.point = point;
    }


    @Override
    public String toString() {
        return "Comment{" +
                "ID=" + ID +
                ", name='" + name + '\'' +
                ", comment='" + comment + '\'' +
                ", date=" + date +
                ", point=" + point +
                '}';
    }
}

