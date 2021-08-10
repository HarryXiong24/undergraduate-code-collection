package com.wjy.pojo;

public class IDDD {
    private String id;

    public IDDD(String id) {
        this.id = id;
    }

    public IDDD() {
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return "IDDD{" +
                "id='" + id + '\'' +
                '}';
    }
}
