//本地数据库连接
import java.sql.*;

public class homework6 {
    public static void main(String[] args) {

        //本地数据库连接
        System.out.println("本地数据库连接");
        try {
            Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        Connection con;
        Statement state;
        String sql;
        ResultSet res;
        try {
            con = DriverManager.getConnection("jdbc:derby:D:/codeS/backOnGithub/JavaDB/dreaife;create=false");
            state = con.createStatement();

            sql = "select * from erogeDate";
            res = state.executeQuery(sql);
            System.out.println("游戏编号\t游戏名称\t制作社团\t制作时间\t游戏价格");
            while (res.next()){
                String num = res.getString("GAMENUM");
                String name = res.getString("GAMENAME");
                String club = res.getString("GAMECLUB");
                String time = res.getString("GAMETIME");
                int price = res.getInt("GAMEPRICE");

                System.out.println(num+"\t"+name+"\t"+club+"\t"+time+"\t"+price);
            }res.close();
            state.close();
            con.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
