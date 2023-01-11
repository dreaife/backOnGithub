package edu.xju.web.dreaife.Controller;

import edu.xju.web.dreaife.Dao.stuDao;
import edu.xju.web.dreaife.entity.stu;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/registerAction")
public class registController extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        String username =req.getParameter("username");
        String lastname =req.getParameter("password1");
        String confinename=req.getParameter("password2");
        System.out.println(lastname+" "+confinename);
        stu users = stuDao.userExit(username);
        if (lastname.equals(confinename)&&lastname!=""&&confinename!=""){
            if (users!=null) {
                req.setAttribute("message","用户已存在，请重新输入用户名");
                req.getRequestDispatcher("login/register.jsp").forward(req,resp);
            }else {
                stuDao.userRegist(username,lastname);
                req.getRequestDispatcher("login/login.jsp").forward(req,resp);
            }
        }else {
            if (username==""||lastname==""||confinename==""){
                req.setAttribute("message","请输入账号或密码");
                req.getRequestDispatcher("login/register.jsp").forward(req,resp);
            }
            req.setAttribute("message","两次密码不相同，请重新输入");
            req.getRequestDispatcher("login/register.jsp").forward(req,resp);
        }
    }
}
