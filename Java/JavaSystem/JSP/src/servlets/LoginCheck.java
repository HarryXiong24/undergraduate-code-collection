package servlets;

import java.io.File;
import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import jsp.exp.dao.UserDao;
import jsp.exp.entity.User;

/**
 * Servlet implementation class DoLogin
 */
@WebServlet("/loginCheck.do")
public class LoginCheck extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginCheck() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html; charset=UTF-8"); 
		
		String name = request.getParameter("userName");
		String pwd = request.getParameter("pwd");
		String autoLogin = request.getParameter("autoLogin");
		
		
		UserDao userDao = new UserDao("D:\\编程\\SQLite DB\\db.db");
		List<User> users = userDao.queryAll();
		
		
		if (autoLogin != null) {
			Cookie cookie1 = new Cookie("name", name);
			Cookie cookie2 = new Cookie("pwd", pwd);
			response.addCookie(cookie1);
			response.addCookie(cookie2);
		} 
		
		int res = 0;
		for(User user : users) {
			if(user.getUserName().equals(name) && user.getPwd().equals(pwd)) {
				res = 1;
				break;
			} 
		}
		
		if(res == 1) {
			HttpSession session = request.getSession();
			session.setAttribute("name", name);
			response.getWriter().println("登录成功！3秒后跳转到首页！");
			response.setHeader("refresh", "3;url=index.view");
		} else {
			response.getWriter().println("登录失败！用户名或密码错误，3秒后将跳转到登录页面");
			response.setHeader("refresh", "3;url=autoLogin");
		}
	}

}
