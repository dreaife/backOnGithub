<%--
  Created by IntelliJ IDEA.
  User: 87726
  Date: 2022/12/25
  Time: 3:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Register</title>
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <link href="css/loginPage.css" rel="stylesheet">
    <script src="js/jquery-1.11.3.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
    <%String user_err=(String) request.getAttribute("message");%>
    <script type="text/javascript">
        function register(){
            var username = $('#username').val();
            var password1 = $('#password1').val();
            var password2 = $('#password2').val();
            $.ajax({
                url:"/webLast/registerAction",
                type:"post",
                data:{
                    "username":username,
                    "password1":password1,
                    "password2":password2,
                },
                dataType:"json",
                success:function (data){
                    var tt = "<%=user_err%>";
                    if(tt != null){
                        alert(tt);
                        window.location='<%=request.getContextPath()%>/login/register.jsp' ;
                    }
                }
            })
        }
    </script>
    <style>
        body{
            background: url("<%=request.getContextPath()%>/login/img/background.jpg") no-repeat center center fixed;
            /*兼容浏览器版本*/
            -webkit-background-size: cover;
            -o-background-size: cover;
            background-size: cover;
        }
    </style>
</head>
<body>
<div class="loginForm">
    <h2>用户注册</h2>
    <form>
        <div class="form-group">
            <label for="username">用户名</label>
            <input type="email" class="form-control" id="username" placeholder="请输入用户名">
        </div>
        <div class="form-group">
            <label for="password1">密码</label>
            <input type="password" class="form-control" id="password1" placeholder="请输入密码">
        </div>
        <div class="form-group">
            <label for="password2">确认密码</label>
            <input type="password" class="form-control" id="password2" placeholder="请输入密码">
        </div>
        <div style="text-align: center;vertical-align: middle;">
            <input type="submit" onclick="register()" class="btn btn-primary" value="注册"/>
        </div>
    </form>
</div>
</body>
</html>
