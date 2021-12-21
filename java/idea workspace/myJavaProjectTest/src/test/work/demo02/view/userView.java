package test.work.demo02.view;

import test.work.demo02.dao.pmsDao;

import java.util.Scanner;

public class userView {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.printf("登录,1\n注册,2\n");
        int selec = cin.nextInt();
        System.out.println("输入账号及密码");
        String accName = cin.nextLine();
        String password = cin.nextLine();
        pmsDao dao = new pmsDao();
        if(selec == 1){
            toLogin(accName,password);
        }else{
            toRegist(accName,password);
        }
    }
    static void toLogin(String name, String password){

    }
    static void toRegist(String name, String password){

    }
}
