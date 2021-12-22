package test.work.demo02.dao;

import test.work.demo02.util.JdbcUtil;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class itemDao {

    int getMaxPage(int index) throws SQLException {
        int maxPage = 0;
        String sql = "select count(ID) from t_item";
        Connection conn = null;
        try {
            conn = JdbcUtil.getConn();
            Statement stmt = conn.createStatement();
            ResultSet res = stmt.executeQuery(sql);
            if(res.next()){
                maxPage = res.getInt(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        } finally {
            JdbcUtil.closeConn(conn);
        }maxPage = (maxPage%index != 0)?(maxPage/index+1):(maxPage/index);
        return maxPage;
    }

}
