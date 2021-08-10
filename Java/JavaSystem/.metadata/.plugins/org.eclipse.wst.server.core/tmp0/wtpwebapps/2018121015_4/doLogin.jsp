<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<c:choose>
	<c:when test="${param.userName == initParam.userName && param.pwd == initParam.password}">
		<% session.setAttribute("userName", request.getParameter("userName")); %>
		<jsp:forward page="home.jsp" />
	</c:when>
	<c:otherwise>
		<c:redirect url="login.jsp"></c:redirect>
	</c:otherwise>
</c:choose>