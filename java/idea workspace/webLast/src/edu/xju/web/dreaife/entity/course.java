package edu.xju.web.dreaife.entity;

import java.sql.Timestamp;

public class course {
    private int id;
    private String className;
    private int point;
    private Timestamp time;
    private int tid;

    @Override
    public String toString() {
        return "course{" +
                "id=" + id +
                ", className='" + className + '\'' +
                ", point=" + point +
                ", time=" + time +
                ", tid=" + tid +
                '}';
    }

    public course() {
    }

    public course(int id, String className, int point, Timestamp time, int tid) {
        this.id = id;
        this.className = className;
        this.point = point;
        this.time = time;
        this.tid = tid;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public int getPoint() {
        return point;
    }

    public void setPoint(int point) {
        this.point = point;
    }

    public Timestamp getTime() {
        return time;
    }

    public void setTime(Timestamp time) {
        this.time = time;
    }

    public int getTid() {
        return tid;
    }

    public void setTid(int tid) {
        this.tid = tid;
    }
}
