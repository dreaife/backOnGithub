package test.work.demo02.view;

import test.work.demo02.dao.pmsDao;
import test.work.demo02.entity.User;

import java.sql.SQLException;
import java.util.Scanner;

public class userView {
    static pmsDao dao = new pmsDao();
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.printf("登录,1\n注册,2\n");
        String selec = cin.nextLine();
        System.out.println("输入账号");
        String accName = cin.nextLine();
        System.out.println("输入密码");
        String password = cin.nextLine();
        if("1".equals(selec)){
            toLogin(accName,password);
        }else{
            toRegist(accName,password);
        }cin.close();
    }
    static void toLogin(String name, String password) {
        User user = null;
        try {
            user = dao.login(name,password);
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("系统正在维护");
        }if(user == null)
            System.out.println("登录失败");
        else
            System.out.println("登录成功");
    }
    static void toRegist(String name, String password){
        int i = 0;
        try {
            i = dao.newLog(name,password);
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("系统正在维护");
        }if(i == 0)
            System.out.println("注册失败");
        else
            System.out.println("注册成功");
    }
}
