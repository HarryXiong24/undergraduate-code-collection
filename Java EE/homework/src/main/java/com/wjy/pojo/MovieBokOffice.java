package com.wjy.pojo;

import java.util.List;

public class MovieBokOffice {
    private String movieName;
    private String type;
    private String stack;
    private String movieBox;
    private List<Integer> data;

    @Override
    public String toString() {
        return "MovieBokOffice{" +
                "movieName='" + movieName + '\'' +
                ", type='" + type + '\'' +
                ", stack='" + stack + '\'' +
                ", movieBox='" + movieBox + '\'' +
                ", data=" + data +
                '}';
    }

    public String getMovieName() {
        return movieName;
    }

    public void setMovieName(String movieName) {
        this.movieName = movieName;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getStack() {
        return stack;
    }

    public void setStack(String stack) {
        this.stack = stack;
    }

    public String getMovieBox() {
        return movieBox;
    }

    public void setMovieBox(String movieBox) {
        this.movieBox = movieBox;
    }

    public List<Integer> getData() {
        return data;
    }

    public void setData(List<Integer> data) {
        this.data = data;
    }
}
