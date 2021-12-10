package grade02Class.dreaife.day02;

import java.sql.*;
import java.util.Scanner;

public class loginPrepar {
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        System.out.println("输入账号 密码");
        String name = sin.nextLine(),password = sin.nextLine();

        PreparedStatement stmt;
        Connection con;
        ResultSet res;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        String url = "jdbc:mysql://localhost:3306/dreaife";
        try {
            con = DriverManager.getConnection(url,"dreaife","20011223hqs12");
            String sql = "select * from t_user where username = ? and password = ?;";
            stmt = con.prepareStatement(sql);
            stmt.setString(1,name);
            stmt.setString(2,password);

            res = stmt.executeQuery();
            if(!res.next()){
                System.out.println("账号或密码错误！");
                return;
            }else System.out.println("登录成功！");
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
