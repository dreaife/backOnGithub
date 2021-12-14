package ProjectTest.demo.dao;

import ProjectTest.demo.entity.User;
import ProjectTest.demo.util.JdbcUtil;
import com.mysql.cj.jdbc.CallableStatementWrapper;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class UserDao {

    public void save(User user) throws SQLException {
        String sql = "insert into t_user (username,password,email,phone,created,updated) "+
                "values(?,?,?,?,NOW(),NOW())";
        Connection conn = null;
        try {
            conn = JdbcUtil.getConn();

            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,user.getUserName());
            pstmt.setString(2,user.getPassword());
            pstmt.setString(3,user.getEmail());
            pstmt.setString(4, user.getPhone());
            pstmt.executeUpdate();
        } finally {
            JdbcUtil.closeConn(conn);
        }
    }

    public void delete(Integer id) throws SQLException {
        String sql = "delete from t_user where id = ?";
        Connection con = null;
        try {
            con = JdbcUtil.getConn();

            PreparedStatement pstmt = con.prepareStatement(sql);
            pstmt.setString(1,id.toString());
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        }finally {
            JdbcUtil.closeConn(con);
        }
    }

    public  void  updatePassword(Integer id,String newPassword) throws SQLException {
        String sql = "update t_user set password = ? where id = ?";
        Connection con = null;
        try {
            con = JdbcUtil.getConn();

            PreparedStatement pstmt = con.prepareStatement(sql);
            pstmt.setString(1,newPassword);
            pstmt.setInt(2,id);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        }finally {
            JdbcUtil.closeConn(con);
        }
    }
}
