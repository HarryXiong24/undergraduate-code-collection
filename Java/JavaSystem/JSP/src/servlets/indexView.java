package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class IndexViewServlet
 */
@WebServlet("/index.view")
public class indexView extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public indexView() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//获取Session对象
		HttpSession session = request.getSession();
		//判断session对象中是否保存了登录信息，如果没有，表示未登录或已退出，跳转到登录页面
		if (session.getAttribute("name") == null) {
			response.sendRedirect("autoLogin");
		}else {
			//有已登录信息，跳转到首页
			request.getRequestDispatcher("home.jsp").forward(request, response);
		}
		
	}

}
