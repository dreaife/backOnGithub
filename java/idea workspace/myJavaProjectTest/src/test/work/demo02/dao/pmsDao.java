package test.work.demo02.dao;

import test.work.demo02.entity.User;
import test.work.demo02.util.JdbcUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author 何庆晟
 */

public class pmsDao {
    /**
     * 用户登录功能
     */
    public User login(String accName, String password) throws SQLException {
        User user = null;
        Connection conn = null;
        try {
            String sql = "select * from t_user where name = ? and password = ?";
            conn = JdbcUtil.getConn();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,accName);
            pstmt.setString(2,password);
            ResultSet res = pstmt.executeQuery();
            if(res.next()){
                user = new User();
                user.setId(res.getInt("id"));
                user.setUserName(res.getString("name"));
                user.setPassword(res.getString("password"));
//                user.setEmail(res.getString("email"));
//                user.setPhone(res.getString("phone"));
                user.setCreated(res.getTimestamp("started"));
                user.setUpdated(res.getTimestamp("updated"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        } finally {
            JdbcUtil.closeConn(conn);
        }

        return user;
    }

    /**
     * 注册
     */
    public int newLog(String accName,String password) throws SQLException {
        int i = 0;
        String sql = "insert into t_user(name,password,started,updated) values(?,?,now(),now()) ";
        Connection conn = null;
        try {
            conn = JdbcUtil.getConn();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,accName);
            pstmt.setString(2,password);
            i = pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        }finally {
            JdbcUtil.closeConn(conn);
        }
        return i;
    }
}
