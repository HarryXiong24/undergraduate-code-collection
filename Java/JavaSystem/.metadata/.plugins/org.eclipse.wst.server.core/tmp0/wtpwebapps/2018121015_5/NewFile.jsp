<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta http-equiv="content-type" content="text/html; charset=UTF-8">
	<meta charset="utf-8">
	<title>首页</title>
</head>

<body>
<% 
if(application.getAttribute("count") == null) {
	application.setAttribute("count", 0);
}

int count = (int)application.getAttribute("count");

count++;

application.setAttribute("count", count);
%>
    <p>欢迎您：     
    	<c:out value="${sessionScope.loginUser}">游客</c:out>       
     </p>
    <p>网站访问次数：       ${applicationScope.count} </p>
</body>

</html>