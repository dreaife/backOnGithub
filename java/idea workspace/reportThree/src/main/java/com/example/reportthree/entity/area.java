package com.example.reportthree.entity;

public class area {
    private int id;
    private String cityName;
    private int cityId;

    public area() {
    }

    public area(int id, String cityName, int cityId) {
        this.id = id;
        this.cityName = cityName;
        this.cityId = cityId;
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

    public int getCityId() {
        return cityId;
    }

    public void setCityId(int cityId) {
        this.cityId = cityId;
    }
}
