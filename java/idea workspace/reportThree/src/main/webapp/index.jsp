<%--
  Created by IntelliJ IDEA.
  User: 87726
  Date: 2022/11/06
  Time: 19:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>三级联动</title>
    <script src="js/jquery.js"></script>
    <script type="text/javascript">
        function produceOption(id,list){
            console.log(list)
            $(id).empty()
            $(list).each((index,item)=>{
                $(id).append("<option value="+item.id+">"+item.name+"</option>")
            })
        }
        function produceOption2(id,list){
            console.log(list)
            $(id).empty()
            $(list).each((index,item)=>{
                $(id).append("<option value="+item.id+">"+item.cityName+"</option>")
            })
        }
        window.onload = function () {
            $.ajax({
                url:"provinUpdate",
                method:"post",
                data:{pid:0},
                dataType:"json",
                success: function(res) {
                    produceOption("#proviance",res)
                    $("#proviance").prepend("<option selected='selected'>请选择省份</option>")
                }
            })
        }
        $(()=>{
            $.ajax({
                url:"provinUpdate",
                method:"post",
                data:{pid:0},
                dataType:"json",
                success: function(res) {
                    produceOption("#proviance",res)
                    $("#proviance").prepend("<option selected='selected'>请选择省份</option>")
                }
            })
            $("#proviance").change(function(){
                var pid = $(this).prop("value")
                $.ajax({
                    url:"cityUpdate",
                    method:"post",
                    data:{pid:pid},
                    dataType:"json",
                    success: function(res) {
                        produceOption2("#city",res)
                        $("#city").prepend("<option selected='selected'>请选择城市</option>")
                    }
                })
            })
            $("#city").on("change",function(){
                var pid = $(this).prop("value")
                $.ajax({
                    url:"areaUpdate",
                    method:"post",
                    data:{pid:pid},
                    dataType:"json",
                    success: function(res) {
                        produceOption2("#country",res)

                    }
                })
            })
        })
    </script>
</head>
<body>
    <h3>三级联动</h3>
    <hr/>
    <select name="pro" id="proviance">
        <option>选择省份</option>
    </select>
    <select name="city" id="city">
        <option>选择城市</option>
    </select>
    <select name="country" id="country">
        <option>请选择区域</option>
    </select>
</body>
</html>
