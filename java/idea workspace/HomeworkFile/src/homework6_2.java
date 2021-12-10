//网络数据库连接
import java.sql.*;

public class homework6_2 {
    public static void main(String[] args) {
        //网络数据库连接
        System.out.println("\n网络数据库连接");
        Connection con;
        Statement state;
        String sql;
        ResultSet res;
        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        try {
            con = DriverManager.getConnection("jdbc:derby://localhost:1527//dreaife;create=false");
            state = con.createStatement();

            sql = new String("select * from erogeDate");
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
