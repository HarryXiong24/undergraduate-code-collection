package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import jsp.exp.dao.UserDao;

/**
 * Servlet implementation class DeleteUsers
 */
@WebServlet("/deleteUsers.do")
public class DeleteUsers extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteUsers() {
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
		
		UserDao userDao = new UserDao("D:\\编程\\SQLite DB\\db.db");
		int res = userDao.deleteUser(Integer.parseInt(request.getParameter("id")));
		
		if(res == 1) {
			response.getWriter().println("删除成功！3秒后将刷新");
			response.setHeader("refresh", "3;url=findUsers.do");
		} else {
			response.getWriter().println("删除失败！3秒后将刷新");
			response.setHeader("refresh", "3;url=findUsers.do");
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
