package test.work.demo02.view;

import test.work.demo02.dao.pmsDao;
import test.work.demo02.entity.User;

import java.sql.SQLException;
import java.util.Scanner;

public class userView {
    static pmsDao dao = new pmsDao();
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.printf("��¼,1\nע��,2\n");
        String selec = cin.nextLine();
        System.out.println("�����˺�");
        String accName = cin.nextLine();
        System.out.println("��������");
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
            System.out.println("ϵͳ����ά��");
        }if(user == null)
            System.out.println("��¼ʧ��");
        else
            System.out.println("��¼�ɹ�");
    }
    static void toRegist(String name, String password){
        int i = 0;
        try {
            i = dao.newLog(name,password);
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("ϵͳ����ά��");
        }if(i == 0)
            System.out.println("ע��ʧ��");
        else
            System.out.println("ע��ɹ�");
    }
}
