package summerMiddle.HomeworkDay03.dao;

import summerMiddle.HomeworkDay03.entity.Club;
import summerMiddle.HomeworkDay03.entity.Game;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class ClubDao {
    private DBHelper dbHelper = new DBHelper();

    public List<Club> queryAll(){
        List<Club> list = new ArrayList<Club>();
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("select * from club");
            ResultSet res = pstmt.executeQuery();
            while (res.next()){
                Club club = new Club(res.getInt("club_id"),
                                    res.getString("club_name"),
                                    res.getString("club_age"));
                list.add(club);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return list;
    }
    public Club queryOne(int cid){
        Club club;
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("select * from club where club_id=?");
            pstmt.setObject(1,cid);
            ResultSet res = pstmt.executeQuery();
            res.next();
            club = new Club(res.getInt("club_id"),
                        res.getString("club_name"),
                        res.getString("club_age"));
            return club;
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return null;
    }
    public int clubAdd(Club club){
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("insert into eroge.club (club_id,club_name, club_age) values(?,?,?)");
            pstmt.setObject(1,club.getClub_id());
            pstmt.setObject(2,club.getClub_name());
            pstmt.setObject(3,club.getClub_age());
            int value = pstmt.executeUpdate();
            return value;
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return 0;
    }
    public int clubDele(int cid){
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("delete from club where club_id=?");
            pstmt.setObject(1,cid);
            int value = pstmt.executeUpdate();
            return value;
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return 0;
    }
    public List<Club> queryOneMaybe(String name){
        List<Club> list = new ArrayList<Club>();
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("select * from club where club_name like concat('%',?,'%')");
            pstmt.setObject(1,name);
            ResultSet res = pstmt.executeQuery();
            while (res.next()){
                Club club = new Club(res.getInt("club_id"),
                        res.getString("club_name"),
                        res.getString("club_age"));
                list.add(club);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return list;
    }
    public List<Club> queryOnePage(int page,int len){
        List<Club> list = new ArrayList<Club>();
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("select * from club limit ?,?");
            pstmt.setObject(1,(page-1)*len);
            pstmt.setObject(2,len);
            ResultSet res = pstmt.executeQuery();
            while (res.next()){
                Club club = new Club(res.getInt("club_id"),
                        res.getString("club_name"),
                        res.getString("club_age"));
                list.add(club);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return list;
    }
    public List<Game> queryByGame(int cid){
        List<Game> list = new ArrayList<Game>();
        Connection con = dbHelper.getCon();
        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement("select * from game where game_club = (select club_name from club where club_id=?)");
            pstmt.setObject(1,cid);
            ResultSet res = pstmt.executeQuery();
            while (res.next()){
                Game game = new Game(res.getInt("game_id"),
                        res.getString("game_name"),
                        res.getInt("game_value"),
                        res.getString("game_age"),
                        res.getString("game_club"));
                list.add(game);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            dbHelper.close(con,pstmt);
        }return list;
    }
    public static void main(String[] args) {
        ClubDao clubDao = new ClubDao();
        System.out.println("\n全部查询");
        List<Club> clubList = clubDao.queryAll();
        for(Club x:clubList) {
            System.out.println(x.toString());
        }

        System.out.println("\n单个查询");
        System.out.println(clubDao.queryOne(1));

        System.out.println("\nclub插入");
        if(clubDao.clubAdd(new Club(7,"Favorite","2004-05-28"))!=0) System.out.println("插入成功");
        else System.out.println("插入失败");

        System.out.println("\nclub删除");
        if(clubDao.clubDele(7)!=0) System.out.println("删除成功");
        else System.out.println("删除失败");

        System.out.println("\n模糊查询");
        System.out.println(clubDao.queryOneMaybe("IF").toString());

        System.out.println("\n分页查询");
        clubList = clubDao.queryOnePage(1,4);
        for(Club x:clubList) {
            System.out.println(x.toString());
        }

        System.out.println("\n根据Club id查询Game数据");
        List<Game> gameList = clubDao.queryByGame(2);
        for(Game x : gameList){
            System.out.println(x.toString());
        }
    }
}
