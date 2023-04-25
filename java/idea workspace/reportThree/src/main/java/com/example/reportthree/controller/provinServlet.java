package com.example.reportthree.controller;

import com.example.reportthree.dao.searchDao;
import com.example.reportthree.entity.province;
import com.google.gson.Gson;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.List;

@WebServlet("/provinUpdate")
public class provinServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        int pid = Integer.parseInt(req.getParameter("pid"));
        List<province> provinces = new searchDao().provinQuery();
        String provinStr = new Gson().toJson(provinces);
        resp.getWriter().print(provinStr);
    }
}