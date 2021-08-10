package servlets;

import java.io.File;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import model.UserModel;

/**
 * Servlet implementation class DoLogin
 */
@WebServlet("/loginCheck.do")
public class LoginCheck extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	private String name = "caterpillar";
	private String password = "123456";
	
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
		
		String name = request.getParameter("userName");
		String pwd = request.getParameter("pwd");
		String autoLogin = request.getParameter("autoLogin");
		UserModel userModal = new UserModel();
		
		// 获取存储用户信息文件的目录
		String userDictionary = getServletContext().getRealPath("/WEB-INF/users");
		File savedFile = new File(userDictionary + "/" + name + ".properties");
		response.setContentType("text/html; charset=UTF-8");

		if (autoLogin != null) {
			Cookie cookie1 = new Cookie("name", name);
			Cookie cookie2 = new Cookie("pwd", pwd);
			response.addCookie(cookie1);
			response.addCookie(cookie2);
		} 
		
		boolean res = userModal.loginCheck(savedFile, pwd);
		if(res) {
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
