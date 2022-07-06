package summerMiddle.HomeworkDay03.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DBHelper {
    private static final String drive = "org.mariadb.jdbc.Driver";
    private static final String url = "jdbc:mariadb://127.0.0.1:3600/eroge";
    private static final String username = "root";
    private static final String password = "20011223";
    public Connection con = null;

    public Connection getCon(){
        try {
            Class.forName(drive);
            con = DriverManager.getConnection(url,username,password);
        }catch (Exception e){
            e.printStackTrace();
        }return con;
    }
    public void close(Connection con, PreparedStatement pstmt){
        if(con != null){
            try {
                pstmt.close();
                con.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }
}
