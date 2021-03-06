package grade02Class.dreaife.day03;

import org.apache.commons.dbcp.BasicDataSource;
import org.apache.commons.dbcp.DelegatingResultSet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class jdbcToolsUpdate {

    private  static BasicDataSource dataSource = new BasicDataSource();

    private jdbcToolsUpdate(){}

    static{

        Properties prop = new Properties();
        try {
            prop.load(jdbcToolsUpdate.class.getClassLoader().getResourceAsStream("db.properties"));
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

//        try {
//            System.out.println("加载连接");
//            Class.forName(driverClass);
//        } catch (ClassNotFoundException e) {
//            e.printStackTrace();
//        }
    }

    public static Connection getConn() throws SQLException {
        Connection conn =  dataSource.getConnection();
        return conn;
    }

    public static void closeConn(Connection conn){
        if(conn != null){
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        try {
            System.out.println(getConn());
            System.out.println(getConn());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
