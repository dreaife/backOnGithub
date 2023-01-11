package edu.xju.web.dreaife.util;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class JDBCUtil {
    private static DataSource dataSource;
    static {
        //创建Druid连接池
        //1. 使用Properties对象，加载配置文件中的数据
        Properties properties = new Properties();
        InputStream in = JDBCUtil.class.getClassLoader().getResourceAsStream("jdbc.properties");
        try {
            properties.load(in);
            //2. 使用DruidDataSourceFactory工厂类，根据properties对象中的数据创建DataSource
            dataSource = DruidDataSourceFactory.createDataSource(properties);//赋值给成员变量dataSource
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 获取连接池对象的方法
     * @return
     */
    public static DataSource getDataSource() {
        return dataSource;
    }

    public static Connection getConnection(){
        //从连接池获取连接
        Connection conn = null;
        try {
            conn = dataSource.getConnection();
        } catch (SQLException e) {
            e.printStackTrace();
            throw new RuntimeException(e.getMessage());
        }
        return conn;
    }

    /**
     * 关闭2资源的方法
     */
    public static void close(Statement stm, Connection conn) throws SQLException {
        close(null,stm,conn);
    }

    /**
     * 关闭3资源的方法
     */
    public static void close(ResultSet rst, Statement stm, Connection conn) throws SQLException {
        if (rst != null) {
            rst.close();
        }
        if (stm != null) {
            stm.close();
        }
        if (conn != null) {
            conn.close();
        }
    }
}