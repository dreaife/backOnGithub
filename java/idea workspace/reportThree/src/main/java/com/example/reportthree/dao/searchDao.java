package com.example.reportthree.dao;

import com.example.reportthree.entity.area;
import com.example.reportthree.entity.city;
import com.example.reportthree.entity.province;
import com.example.reportthree.util.dbhelper;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class searchDao {
    dbhelper db = new dbhelper();

    public List<province> provinQuery(){
        List<province> list = new ArrayList<province>();
        Connection conn = db.getConnection();
        PreparedStatement pst = null;
        try {
            pst = conn.prepareStatement("SELECT * FROM province");
            ResultSet rs = pst.executeQuery();
            while (rs.next()){;
                int id = rs.getInt("id");
                String name = rs.getString("name");
                province provinces = new province(id,name);
                list.add(provinces);
            }
            return list;
        }
        catch (Exception e){

        }
        finally {
            db.close(conn,pst);
        }

        return list;
    }

    public List<city> cityQuery(int provinId){
        List<city> list = new ArrayList<city>();
        Connection conn = db.getConnection();
        PreparedStatement pst = null;
        try {
            pst = conn.prepareStatement("SELECT * FROM city where provinceid=?");
            pst.setObject(1,provinId);
            ResultSet rs = pst.executeQuery();
            while (rs.next()){;
                int id = rs.getInt("id");
                String name = rs.getString("name");
                int proId = rs.getInt("provinceid");
                city cities = new city(id,name,proId);
                list.add(cities);
            }
            return list;
        }
        catch (Exception e){

        }
        finally {
            db.close(conn,pst);
        }

        return list;
    }

    public List<area> areaQuery(int cityId){
        List<area> list = new ArrayList<area>();
        Connection conn = db.getConnection();
        PreparedStatement pst = null;
        try {
            pst = conn.prepareStatement("SELECT * FROM area where cityid=?");
            pst.setObject(1,cityId);
            ResultSet rs = pst.executeQuery();
            while (rs.next()){;
                int id = rs.getInt("id");
                String name = rs.getString("name");
                int proId = rs.getInt("cityid");
                area areas = new area(id,name,proId);
                list.add(areas);
            }
            return list;
        }
        catch (Exception e){

        }
        finally {
            db.close(conn,pst);
        }

        return list;
    }
//
//    public static void main(String[] args) {
//        System.out.println(new searchDao().areaQuery(1));
//    }
}
