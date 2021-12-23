package test.work.demo02.util;

import org.apache.commons.dbcp.BasicDataSource;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

/**
 * @author 何庆晟
 */

public class JdbcUtil {
    private  static final BasicDataSource dataSource = new BasicDataSource();

    private JdbcUtil(){}

    static {

        Properties prop = new Properties();
        try {
            prop.load(JdbcUtil.class.getClassLoader().getResourceAsStream("pmsdb.properties"));
            String driverClass = prop.getProperty("jdbc.driverClass");
            String url = prop.getProperty("jdbc.url");
            String user = prop.getProperty("jdbc.user");
            String password = prop.getProperty("jdbc.password");

            int initialSize = Integer.parseInt(prop.getProperty("ds.initialSize"));
            int maxActive = Integer.parseInt(prop.getProperty("ds.maxActive"));
            int maxWait = Integer.parseInt(prop.getProperty("ds.maxWait"));
            int maxIdle = Integer.parseInt(prop.getProperty("ds.maxIdle"));

            dataSource.setDriverClassName(driverClass);
            dataSource.setUrl(url);
            dataSource.setUsername(user);
            dataSource.setPassword(password);

            dataSource.setInitialSize(initialSize);
            dataSource.setMaxActive(maxActive);
            dataSource.setMaxWait(maxWait);//最大等待时间
            dataSource.setMaxIdle(maxIdle);//最大空闲数

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Connection getConn() throws SQLException {
            Connection conn = null;
            conn = dataSource.getConnection();
            return conn;
    }

    public static void closeConn(Connection conn){
        if(conn != null) try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
    }
}
