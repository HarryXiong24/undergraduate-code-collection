<%@ page language="java" contentType="text/html; charset=UTF-8" 
pageEncoding="UTF-8" errorPage="error.jsp" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
	int divisor = 0;
    int dividend = 3;
    int res;
    
    try {
		res = dividend / divisor;
	}
	catch(ArithmeticException zz) {
		throw new ArithmeticException("Error!"); 
	}
%>
</body>
</html>