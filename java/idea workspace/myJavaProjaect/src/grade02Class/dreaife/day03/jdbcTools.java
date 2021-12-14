package grade02Class.dreaife.day03;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class jdbcTools {
    public static String driverClass;
    public static String url;
    public static String user;
    public static String password;

    private jdbcTools(){}

    static{

        Properties prop = new Properties();
        try {
            prop.load(jdbcTools.class.getClassLoader().getResourceAsStream("db.properties"));
            driverClass = prop.getProperty("jdbc.driverClass");
            url = prop.getProperty("jdbc.url");
            user = prop.getProperty("jdbc.user");
            password = prop.getProperty("jdbc.password");
            System.out.println(url);
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            System.out.println("加载连接");
            Class.forName(driverClass);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static Connection getConn() throws SQLException {
        Connection conn = null;
        conn = DriverManager.getConnection(url,user,password);
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
