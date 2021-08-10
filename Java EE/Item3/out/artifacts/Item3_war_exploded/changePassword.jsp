<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>changepassword</title>
</head>
<body>
<form action="/changePassword" method="post">
    旧密码：<input type="text" name="oldPassword"/><br/>
    新密码：<input type="text" name="newPassword"/><br/>
    <input type="submit" value="提交"/>
</form>
</body>
</html>
