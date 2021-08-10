<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% 
	String name = request.getParameter("userName");
	String pwd = request.getParameter("pwd");
	application.setAttribute("name", name);
	application.setAttribute("pwd", pwd);
	if( name.equals((String)application.getInitParameter("userName")) && pwd.equals((String)application.getInitParameter("password")) ) {
		session.setAttribute("userName", name);
%>	
<jsp:forward page="home.jsp" />
<% 
	} else {
		out.println("登录失败！3秒后跳转到首页！");
		response.setHeader("refresh", "3;url=login.jsp");
	} 
%>