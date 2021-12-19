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
* @author 何庆晟
* @since <pre>12月 19, 2021</pre> 
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
        System.out.println("功能正常！！！");
        if (p1 != null)
            System.out.println("登录成功！！！");
        else
            System.out.println("登录失败~~~");
    } catch (SQLException e) {
        e.printStackTrace();
        System.out.println("功能故障");
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
        System.out.println("功能正常");
        System.out.println(money);
    } catch (SQLException e) {
        e.printStackTrace();
        System.out.println("功能故障");
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
        System.out.println("功能正常");
        if(i != 0)
            System.out.println("转账成功！！！");
        else
            System.out.println("转账失败~~~");
    } catch (SQLException e) {
        e.printStackTrace();
        System.out.println("功能故障");
    }

} 


} 
