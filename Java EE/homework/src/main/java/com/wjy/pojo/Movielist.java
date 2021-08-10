package com.wjy.pojo;

public class Movielist {
    private int movieID;
    private String movieName;
    private String movieActor;
    private String movieInfo;
    private String movieDetail;
    private Double moviePoint;
    private String launcher;

    public Movielist(String movieName, String movieActor, String movieInfo, String movieDetail, Double moviePoint, String launcher) {
        this.movieName = movieName;
        this.movieActor = movieActor;
        this.movieInfo = movieInfo;
        this.movieDetail = movieDetail;
        this.moviePoint = moviePoint;
        this.launcher = launcher;
    }

    public Movielist() {
    }

    public int getMovieID() {
        return movieID;
    }

    public void setMovieID(int movieID) {
        this.movieID = movieID;
    }

    public String getMovieName() {
        return movieName;
    }

    public void setMovieName(String movieName) {
        this.movieName = movieName;
    }

    public String getMovieActor() {
        return movieActor;
    }

    public void setMovieActor(String movieActor) {
        this.movieActor = movieActor;
    }

    public String getMovieInfo() {
        return movieInfo;
    }

    public void setMovieInfo(String movieInfo) {
        this.movieInfo = movieInfo;
    }

    public String getMovieDetail() {
        return movieDetail;
    }

    public void setMovieDetail(String movieDetail) {
        this.movieDetail = movieDetail;
    }

    public Double getMoviePoint() {
        return moviePoint;
    }

    public void setMoviePoint(Double moviePoint) {
        this.moviePoint = moviePoint;
    }

    public String getLauncher() {
        return launcher;
    }

    public void setLauncher(String launcher) {
        this.launcher = launcher;
    }

    @Override
    public String toString() {
        return "Movielist{" +
                "movieID=" + movieID +
                ", movieName='" + movieName + '\'' +
                ", movieActor='" + movieActor + '\'' +
                ", movieInfo='" + movieInfo + '\'' +
                ", movieDetail='" + movieDetail + '\'' +
                ", moviePoint=" + moviePoint +
                ", launcher=" + launcher +
                '}';
    }
}
