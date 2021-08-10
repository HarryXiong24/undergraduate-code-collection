package com.wjy.service;

import com.wjy.dao.MovieBoxOfficeMapper;
import com.wjy.pojo.MovieBokOffice;
import com.wjy.pojo.MovieBokOfficeVo;
import com.wjy.pojo.MovieBoxOfficeResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@Service
public class MovieBoxOfficeServiceImpl implements MovieBoxOfficeService{
    @Autowired
    private MovieBoxOfficeMapper movieBoxOfficeMapper;

    public MovieBoxOfficeResult getMovieBoxOffice() {
        ArrayList<String> legend = new ArrayList<String>();
        List<String> list = Arrays.asList("周一", "周二", "周三", "周四", "周五", "周六", "周日");

        List<MovieBokOffice> allBoxOffice = movieBoxOfficeMapper.getAllBoxOffice();
        List<MovieBokOfficeVo> series = new ArrayList<MovieBokOfficeVo>();
        for (MovieBokOffice movieBokOffice : allBoxOffice) {
            MovieBokOfficeVo movieBokOfficeVo = new MovieBokOfficeVo();
            legend.add(movieBokOffice.getMovieName());
            String str_data = movieBokOffice.getMovieBox();
            List<String> strings = Arrays.asList(str_data.split("-"));
            System.out.println(strings);
            ArrayList<Integer> integers = new ArrayList<Integer>();
            for (String string : strings) {
                Integer integer = Integer.valueOf(string);
                integers.add(integer);
            }
            movieBokOfficeVo.setName(movieBokOffice.getMovieName());
            movieBokOfficeVo.setData(integers);
            movieBokOfficeVo.setStack("总量");
            movieBokOfficeVo.setType("line");
            series.add(movieBokOfficeVo);
        }
        MovieBoxOfficeResult movieBoxOfficeResult = new MovieBoxOfficeResult();
        movieBoxOfficeResult.setLegend(legend);


        movieBoxOfficeResult.setSeries(series);
        movieBoxOfficeResult.setxAxis(list);
        return movieBoxOfficeResult;
    }
}
