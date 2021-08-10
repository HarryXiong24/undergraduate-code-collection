package com.wjy.pojo;

import java.util.List;

public class MovieBoxOfficeResult {
    private List<String> legend;
    private List<String> xAxis;
    private List<MovieBokOfficeVo> series;

    public List<String> getLegend() {
        return legend;
    }

    public void setLegend(List<String> legend) {
        this.legend = legend;
    }

    public List<String> getxAxis() {
        return xAxis;
    }

    public void setxAxis(List<String> xAxis) {
        this.xAxis = xAxis;
    }

    public List<MovieBokOfficeVo> getSeries() {
        return series;
    }

    public void setSeries(List<MovieBokOfficeVo> series) {
        this.series = series;
    }

    @Override
    public String toString() {
        return "MovieBoxOfficeResult{" +
                "legend=" + legend +
                ", xAxis=" + xAxis +
                ", series=" + series +
                '}';
    }
}