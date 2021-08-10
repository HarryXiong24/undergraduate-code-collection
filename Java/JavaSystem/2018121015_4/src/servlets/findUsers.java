package servlets;

import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entities.User;
import model.UserModel;

/**
 * Servlet implementation class findUsers
 */
@WebServlet("/findUsers.do")
public class findUsers extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public findUsers() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		List<User> list = new LinkedList<User>();
		UserModel userModel = new UserModel();
		
		String userDictionary = getServletContext().getRealPath("/WEB-INF/users");
		File root = new File(userDictionary);
		File[] files = root.listFiles();
		for(File file : files) {
			User user = userModel.findUser(file);
			list.add(user);
		}
		
		request.setAttribute("list", list);
		request.getRequestDispatcher("users.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
