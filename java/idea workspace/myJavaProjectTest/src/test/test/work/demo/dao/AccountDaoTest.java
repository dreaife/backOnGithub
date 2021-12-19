package test.test.work.demo.dao; 

import org.junit.Test; 
import org.junit.Before; 
import org.junit.After;
import test.work.demo.dao.AccountDao;
import test.work.demo.entity.Account;

import java.sql.SQLException;

/** 
* AccountDao Tester. 
* 
* @author ������
* @since <pre>12�� 19, 2021</pre> 
* @version 1.0 
*/ 
public class AccountDaoTest { 

@Before
public void before() throws Exception {
} 

@After
public void after() throws Exception {
} 

/** 
* 
* Method: login(String accName, String password) 
* 
*/ 
@Test
public void testLogin() {
    AccountDao dao = new AccountDao();
    Account p1 = null;
    try {
        p1 = dao.login("admin","123456");
        System.out.println("��������������");
        if (p1 != null)
            System.out.println("��¼�ɹ�������");
        else
            System.out.println("��¼ʧ��~~~");
    } catch (SQLException e) {
        e.printStackTrace();
        System.out.println("���ܹ���");
    }

} 

/** 
* 
* Method: getBalance(String accName, String password) 
* 
*/ 
@Test
public void testGetBalance() {
    AccountDao dao = new AccountDao();
    double money = 0;
    try {
        money = dao.getBalance("admin","123456");
        System.out.println("��������");
        System.out.println(money);
    } catch (SQLException e) {
        e.printStackTrace();
        System.out.println("���ܹ���");
    }

} 

/** 
* 
* Method: sendMoney(String acc1, String acc2, double money) 
* 
*/ 
@Test
public void testSendMoney() {
    AccountDao dao = new AccountDao();
    int i = 0;
    try {
        i = dao.sendMoney("admin","dreaife",7000.0);
        System.out.println("��������");
        if(i != 0)
            System.out.println("ת�˳ɹ�������");
        else
            System.out.println("ת��ʧ��~~~");
    } catch (SQLException e) {
        e.printStackTrace();
        System.out.println("���ܹ���");
    }

} 


} 
