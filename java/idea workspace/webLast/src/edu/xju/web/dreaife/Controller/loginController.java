package edu.xju.web.dreaife.Controller;

import com.google.gson.Gson;
import edu.xju.web.dreaife.Dao.stuDao;
import edu.xju.web.dreaife.entity.stu;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/loginAction")
public class loginController extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        String uname = req.getParameter("username");
        String passwd = req.getParameter("password");
        stu users = null;
        users = stuDao.userLogin(uname,passwd);

        String str = new Gson().toJson(users);
        resp.getWriter().print(str);
    }
}
