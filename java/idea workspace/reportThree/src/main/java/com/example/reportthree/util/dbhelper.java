package com.example.reportthree.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class dbhelper {
    private static final String drive = "com.mysql.cj.jdbc.Driver";
    private static final String url = "jdbc:mysql://localhost:3306/javawebtabet?serverTimezone=UTC";
    private static final String username = "root";
    private static final String password = "123456";
    public Connection conn = null;

    public Connection getConnection() {
        try {
            Class.forName(drive);
            conn = DriverManager.getConnection(url, username, password);
        } catch (Exception e) {

            e.printStackTrace();
        }
        return conn;
    }

    public void close(Connection conn, PreparedStatement pst) {
        if (conn != null) {
            try {
                pst.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
    }
}
