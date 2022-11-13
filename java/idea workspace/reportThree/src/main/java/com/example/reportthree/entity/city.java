package com.example.reportthree.entity;

public class city {
    private int id;
    private String cityName;
    private int proId;

    public city() {
    }

    public city(int id, String cityName, int proId) {
        this.id = id;
        this.cityName = cityName;
        this.proId = proId;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getCityName() {
        return cityName;
    }

    public void setCityName(String cityName) {
        this.cityName = cityName;
    }

    public int getProId() {
        return proId;
    }

    public void setProId(int proId) {
        this.proId = proId;
    }
}
