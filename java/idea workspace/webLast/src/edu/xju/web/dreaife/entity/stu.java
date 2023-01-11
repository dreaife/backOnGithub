package edu.xju.web.dreaife.entity;

import java.sql.Timestamp;

public class stu {
    private int id;
    private String username;
    private String password;
    private int sex;
    private Timestamp birthday;
    private String tclass;

    @Override
    public String toString() {
        return "stu{" +
                "id=" + id +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", sex=" + sex +
                ", birthday=" + birthday +
                ", tclass='" + tclass + '\'' +
                '}';
    }

    public stu(int id, String username, String password, int sex, Timestamp birthday, String tclass) {
        this.id = id;
        this.username = username;
        this.password = password;
        this.sex = sex;
        this.birthday = birthday;
        this.tclass = tclass;
    }

    public stu(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public stu() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public int getSex() {
        return sex;
    }

    public void setSex(int sex) {
        this.sex = sex;
    }

    public Timestamp getBirthday() {
        return birthday;
    }

    public void setBirthday(Timestamp birthday) {
        this.birthday = birthday;
    }

    public String getTclass() {
        return tclass;
    }

    public void setTclass(String tclass) {
        this.tclass = tclass;
    }
}
