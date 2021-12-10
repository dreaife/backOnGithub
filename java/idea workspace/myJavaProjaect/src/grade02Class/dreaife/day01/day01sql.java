package grade02Class.dreaife.day01;

import java.sql.*;

class sqlToDo {
        void loadMySql() {
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
            String dburl = "jdbc:mysql://localhost:3306/dreaife";
            try {
                con = DriverManager.getConnection(dburl, "dreaife", "20011223hqs12");
                stmt = con.createStatement();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        String getSQL() {
            String sql = "select * from USER;";
            sql = "insert into user values ('7','fafaa','41212312',0);";
            return sql;
        }

        void getDBRes(String sql) {
            try {
//                res = stmt.executeQuery(sql);
//                while (res.next()) {
//                    String num = res.getString(1);
//                    String name = res.getString(2);
//                    Integer score = res.getInt(4);
//                    System.out.print(num + "\t" + name + "\t" + score.toString() + "\n");
//                }
                int ans = stmt.executeUpdate(sql);
                if(ans>0){
                    System.out.println("存储成功！");
                }else System.out.println("failed!");
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        void dbclose() {
            try {
                if(stmt!=null) stmt.close();
                if(con!=null) con.close();
                if(res!=null) res.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }

        private Statement stmt;
        private Connection con;
        private ResultSet res;
    }

public class day01sql{
    public static void main(String[] args) {
        sqlToDo stodo = new sqlToDo();
        stodo.loadMySql();
        String sql = stodo.getSQL();
        stodo.getDBRes(sql);
        stodo.dbclose();
    }

}
