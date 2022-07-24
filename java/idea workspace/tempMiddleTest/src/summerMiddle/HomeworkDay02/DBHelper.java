package summerMiddle.HomeworkDay02;

import java.sql.*;

public class DBHelper {
    private static final String drive = "org.mariadb.jdbc.Driver";
    private static final String url = "jdbc:mariadb://127.0.0.1:3600/infor";
    private static final String username = "root";
    private static final String password = "20011223";
    public Connection con = null;
    public Statement stmt = null;
    public ResultSet res = null;

    public Connection getCon(){
        try {
            Class.forName(drive);
            con = DriverManager.getConnection(url,username,password);
            System.out.println("数据库连接成功");
        }catch (Exception e){
            e.printStackTrace();
        }return con;
    }

    public void close(){
        try {
            if(con != null) con.close();
            if(stmt != null) stmt.close();
            if(res != null) res.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws SQLException {
        DBHelper dbHelper = new DBHelper();
        dbHelper.getCon();
        dbHelper.stmt = dbHelper.con.createStatement();
        dbHelper.res = dbHelper.stmt.executeQuery("select order_id,account from myorder;");
        System.out.println("执行select查询，结果如下：");
        while (dbHelper.res.next()){
            System.out.println("用户id："+dbHelper.res.getString(1)+
                    "\t用户账号："+dbHelper.res.getString(2));
        }dbHelper.close();
    }
}
