<%@ page import="java.nio.file.Path" %><%--
  Created by IntelliJ IDEA.
  User: 87726
  Date: 2022/12/25
  Time: 2:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Login</title>
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <link href="css/loginPage.css" rel="stylesheet">
    <script src="js/jquery-1.11.3.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
    <style>
        body{
            background: url("<%=request.getContextPath()%>/login/img/background.jpg") no-repeat center center fixed;
            /*兼容浏览器版本*/
            -webkit-background-size: cover;
            -o-background-size: cover;
            background-size: cover;
        }
    </style>
    <script type="text/javascript">
      function login(){
        var username = $('#username').val();
        var password = $('#lastname').val();
        $.ajax({
          url:"/webLast/loginAction",
          type:"post",
          data:{
            "username":username,
            "password":password,
          },
          dataType:"json",
          success:function (data){
            var tar1 = (username == data.username);
            var tar2 = (password == data.password);
            if(tar1 && tar2){
              sessionStorage.setItem("profileName",username);
              document.location.href = "<%=request.getContextPath()%>/index.jsp?profileName="+username;
            }else {
              alert("账号或密码错误\n请重试");
            }
          }
        })
      }
    </script>
</head>
<body>
<div class="loginForm">
  <h2>用户登录</h2>
  <form>
    <div class="form-group">
      <label for="exampleInputEmail1">用户名</label>
      <input type="email" class="form-control" id="exampleInputEmail1" placeholder="请输入用户名">
    </div>
    <div class="form-group">
      <label for="exampleInputPassword1">密码</label>
      <input type="password" class="form-control" id="exampleInputPassword1" placeholder="请输入密码">
    </div>

    <div class="form-group">
      <div class="col-sm-offset-2 col-sm-10">
        <button type="button" onclick="login()" class="btn btn-primary">登录</button>
        <a type="button" class="btn btn-default col-sm-offset-4 " href="register.jsp" >注册</a>
      </div>
    </div>
  </form>
</div>
</body>
</html>
