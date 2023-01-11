package demo;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class test {

    @Test
    public void test01(){
        ApplicationContext ac = new ClassPathXmlApplicationContext("applicationContext.xml");
        OutDemo demo = (OutDemo)ac.getBean("outDemo");
        System.out.println(demo.demo01);
    }
}
