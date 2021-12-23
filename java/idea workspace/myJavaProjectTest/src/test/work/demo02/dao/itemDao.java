package test.work.demo02.dao;

import test.work.demo02.entity.Item;
import test.work.demo02.util.JdbcUtil;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class itemDao {

    public int getMaxPage(int index) throws SQLException {
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

    public List<Item> goToPage(int p,int idxP) throws SQLException {
        List<Item> list = new ArrayList<Item>();
        String sql = "select * from t_item limit ?,?";
        Connection conn = null;
        try {
            conn = JdbcUtil.getConn();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1,(p-1)*idxP);
            pstmt.setInt(2,idxP);
            ResultSet res = pstmt.executeQuery();
            while(res.next()){
                Item item = new Item();
                item.setId(res.getInt("id"));
                item.setTitle(res.getString("title"));
                item.setPrice(res.getDouble("price"));
                item.setNum(res.getInt("num"));
                item.setItype(res.getString("itype"));
                item.setColor(res.getString("color"));
                list.add(item);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        } finally {
            JdbcUtil.closeConn(conn);
        }
        return list;
    }

}
