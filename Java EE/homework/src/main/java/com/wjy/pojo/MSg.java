package com.wjy.pojo;

public class MSg {
    private String msg;
    private String success;

    public MSg(String msg, String success) {
        this.msg = msg;
        this.success = success;
    }

    public MSg() {
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public String getSuccess() {
        return success;
    }

    public void setSuccess(String success) {
        this.success = success;
    }

    @Override
    public String toString() {
        return "MSg{" +
                "msg='" + msg + '\'' +
                ", success='" + success + '\'' +
                '}';
    }
}
