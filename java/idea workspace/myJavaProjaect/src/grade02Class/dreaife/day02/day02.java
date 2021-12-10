package grade02Class.dreaife.day02;

import java.sql.*;
import java.util.Scanner;

public class day02 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.println("输入账号 密码 邮箱 手机号");
        String name = cin.nextLine();
        String password = cin.nextLine();
        String email = cin.nextLine();
        String phone = cin.nextLine();

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
            String sql = "insert into t_user(username,password,email,phone) values('"+name+"','"+password+"','"+email+"','"+phone+"');";
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
