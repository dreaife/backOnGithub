package edu.xju.web.dreaife.Dao;

import edu.xju.web.dreaife.entity.tea;
import edu.xju.web.dreaife.util.JDBCUtil;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;

import java.sql.SQLException;

public class teaDao {
    public static tea userLogin(String uname, String passwd){
        String sql = "select * from tea where uname = ?";
        QueryRunner queryRunner = new QueryRunner(JDBCUtil.getDataSource());
        tea users = null;
        try {
            users = queryRunner.query(sql,new BeanHandler<tea>(tea.class),uname);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        System.out.println(users);
        System.out.println(passwd);
        return users;
    }

    public static boolean userRegist(String uname, String passwd){
        String sql = "insert into tea (uname, passwd) values (?,?)";
        QueryRunner queryRunner = new QueryRunner(JDBCUtil.getDataSource());
        int i = 0;
        try {
            i = queryRunner.update(sql, uname, passwd);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        System.out.println(i);
        return i != 0;
    }

    public static tea userExit(String uname) {
        String sql = "select * from tea where uname = ?";
        QueryRunner queryRunner = new QueryRunner(JDBCUtil.getDataSource());
        tea users = null;
        try {
            users = queryRunner.query(sql,new BeanHandler<tea>(tea.class),uname);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return users;
    }

    public static tea findUserByID(int uid){
        String sql = "select * from tea where id = ?";
        QueryRunner queryRunner = new QueryRunner(JDBCUtil.getDataSource());
        tea users = null;
        try {
            users = queryRunner.query(sql,new BeanHandler<tea>(tea.class),uid);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return users;
    }
}
