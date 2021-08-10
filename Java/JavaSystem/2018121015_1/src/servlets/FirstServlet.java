package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class FirstServlet
 */
@WebServlet("/firstServlet")
public class FirstServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FirstServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html; charset=UTF-8");
		
		response.getWriter().append("获取到的客户机信息如下:");
		response.getWriter().append("<br/>请求的URL地址: " + request.getServletPath());
		response.getWriter().append("<br/>请求的资源: " + request.getContextPath());
		response.getWriter().append("<br/>请求的URL地址中附带的参数:" + request.getParameterValues(null));
		response.getWriter().append("<br/>来访者的IP地址: " + request.getRemoteAddr());
		response.getWriter().append("<br/>来访者的主机名: " + request.getRemoteHost());
		response.getWriter().append("<br/>使用的端口号:" + request.getServerPort());
		response.getWriter().append("<br/>remoteUser:" + request.getRemoteUser());
		response.getWriter().append("<br/>请求使用的方法: " + request.getMethod());
		response.getWriter().append("<br/>pathInfo:" + request.getPathInfo());
		response.getWriter().append("<br/>1oca1Addr:" + request.getLocalAddr());
		response.getWriter().append("<br/>1oca1Name:" + request.getLocalName());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
