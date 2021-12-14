package grade02Class.dreaife.day03;

import java.sql.*;
import java.util.Scanner;

public class loginPreparWithjdbcTools {
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        System.out.println("输入账号 密码");
        String name = sin.nextLine(),password = sin.nextLine();
        sin.close();

        PreparedStatement stmt;
        ResultSet res;
        Connection con=null;
        try {
            con = jdbcToolsUpdate.getConn();
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
        jdbcToolsUpdate.closeConn(con);

    }
}
