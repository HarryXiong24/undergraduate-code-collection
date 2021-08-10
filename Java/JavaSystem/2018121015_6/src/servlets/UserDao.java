package servlets;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class UserDao {
	public int delUser(int uid) {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			
			
			String url = "jdbc:mysql://192.168.1.1:3306/jsp";
			String userName = "root";
			String password = "2018121015";
			
			Connection connection = DriverManager.getConnection(url, userName, password);
			
			Statement stmt = connection.createStatement();
			
		    String sql = "DELETE FROM t_user WHERE id = " + uid;
		    stmt.executeUpdate(sql);
		    
		    stmt.close();
		    connection.close();
		    
		    return 1;
		
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		} 
	}
}
