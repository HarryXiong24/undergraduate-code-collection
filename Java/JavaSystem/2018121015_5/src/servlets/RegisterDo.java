package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

import org.apache.catalina.tribes.util.Arrays;

import jsp.exp.dao.UserDao;
import jsp.exp.entity.User;


/**
 * Servlet implementation class DoRegister
 */
@MultipartConfig
@WebServlet("/register.do")
public class RegisterDo extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public RegisterDo() {
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
		
		Part part = request.getPart("photo");
		String photo = part.getSubmittedFileName();
		String[] interests = request.getParameterValues("interest");
		String userName = request.getParameter("userName");
		String pwd = request.getParameter("pwd");
		String gender = request.getParameter("gender");
		String category = request.getParameter("category");
		
		User user = new User();
		user.setUserName(userName);
		user.setPwd(pwd);
		user.setGender(gender);
		user.setCategory(category);
		user.setInterest(Arrays.toString(interests));
		user.setPhoto(photo);
		
		UserDao userDao = new UserDao("D:\\编程\\SQLite DB\\db.db");
		int res = userDao.addUser(user);
		
		if(res == 1) {
			response.getWriter().println("注册成功！3秒后将刷新");
			response.setHeader("refresh", "3;url=register.html");
		} else {
			response.getWriter().println("注册失败！3秒后将刷新");
			response.setHeader("refresh", "3;url=register.html");
		}
		
	}

}