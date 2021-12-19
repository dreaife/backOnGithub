package test.work.demo.dao;

import test.work.demo.entity.Account;
import test.work.demo.util.JdbcUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author 何庆晟
 */

public class AccountDao {
    /**
     * 用户登录功能
     */
    public Account login(String accName,String password) throws SQLException {
        Account user = null;
        Connection conn = null;
        try {
            String sql = "select * from t_account where accout = ? and password = ?";
            conn = JdbcUtil.getConn();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,accName);
            pstmt.setString(2,password);
            ResultSet res = pstmt.executeQuery();
            if(res.next()){
                user = new Account();
                user.setId(res.getInt("id"));
                user.setAccout(res.getString("accout"));
                user.setPassword(res.getString("password"));
                user.setBalance(res.getDouble("balance"));
                user.setStarted(res.getTimestamp("started"));
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
     * 查询余额功能
     */
    public double getBalance(String accName,String password) throws SQLException {
        double money = 0.0;
        String sql = "select balance from t_account where accout = ? and password = ?";
        Connection conn = null;
        try {
            conn = JdbcUtil.getConn();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,accName);
            pstmt.setString(2,password);
            ResultSet res = pstmt.executeQuery();
            if(res.next())
                money = res.getDouble("balance");
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        }finally {
            JdbcUtil.closeConn(conn);
        }
        return money;
    }

    /**
     * 转账功能
     */
    public int sendMoney(String acc1,String acc2,double money) throws SQLException {
        int i = 0;
        boolean autoCommitMode = false;
        String sqlIn = "update t_account set balance = balance - ? where accout = ?";
        String sqlOut = "update t_account set balance = balance + ? where accout = ?";
        Connection conn = null;
        try {
            conn = JdbcUtil.getConn();
            autoCommitMode = conn.getAutoCommit();
            conn.setAutoCommit(false);
            PreparedStatement pstmt = conn.prepareStatement(sqlIn);
            pstmt.setDouble(1,money);
            pstmt.setString(2,acc1);
            pstmt.executeUpdate();
            pstmt = conn.prepareStatement(sqlOut);
            pstmt.setDouble(1,money);
            pstmt.setString(2,acc2);
            i = pstmt.executeUpdate();
            conn.commit();
        } catch (SQLException e) {
            if(conn!=null) conn.rollback();
            e.printStackTrace();
            throw e;
        }finally {
            if(conn!=null) conn.setAutoCommit(autoCommitMode);
            JdbcUtil.closeConn(conn);
        }
        return i;
    }

}
