package grade02Class.dreaife.day02;

import java.sql.*;
import java.util.Scanner;

public class login {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.println("输入账号 密码");
        String name = cin.nextLine(),password = cin.nextLine();

        Statement stmt;
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
            stmt = con.createStatement();
            String sql = "select * from t_user where username = '" + name + "' and password = '" + password + "';";
            res = stmt.executeQuery(sql);
            if(res == null){
                System.out.println("账号或密码错误！");
                return;
            }else System.out.println("登录成功！");
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
