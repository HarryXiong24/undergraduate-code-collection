package UserDao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import entity.User;

public class UserDao {
	private Connection connection;
	private DB db;
	
	public UserDao(String dbFile) {
		// TODO Auto-generated constructor stub
		this.db = new DB(dbFile);
	    this.connection = this.db.getConnection();
	}
	
	public int addUser(User user) {
		Statement stmt = null;
		try {
			stmt = this.connection.createStatement();
			String sql = "INSERT INTO t_user(name,pwd,gender,category,interest,photo,regTime) VALUES('" + user.getUserName() + "','" + user.getPwd() + "','" + user.getGender() + "','" + user.getCategory() + "','" + user.getInterest() + "','" + user.getPhoto() + "','" + new Date() + "')";
			stmt.executeUpdate(sql);
			stmt.close();
			return 1;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		} finally {
		      DB.close(null, stmt, null);
	    }
	}
	
	@SuppressWarnings("deprecation")
	public User findById(int id)
	  {
	    Statement stmt = null;
	    ResultSet rs = null;
	    User user = null;
	    try {
	      stmt = this.connection.createStatement();
	      String sql = "SELECT * FROM t_user WHERE id = " + id;
	      rs = stmt.executeQuery(sql);
	      while (rs.next()) {
	        user = new User();
	        user.setId(rs.getInt(1));
	        user.setUserName(rs.getString(2));
	        user.setPwd(rs.getString(3));
	        user.setGender(rs.getString(4));
	        user.setCategory(rs.getString(5));
	        user.setInterest(rs.getString(6));
	        user.setPhoto(rs.getString(7));
	        user.setRegTime(new Date(rs.getString(8)));
	      }
	      
	      return user;
	    }
	    catch (SQLException e) {
	      e.printStackTrace();
	      return null;
	    } finally {
	      DB.close(null, stmt, null);
	    }
	  }
	
	@SuppressWarnings("deprecation")
	public List<User> queryAll()
	  {
	    Statement stmt = null;
	    ResultSet rs = null;
	    List<User> users = new ArrayList<User>();
	    try {
	      stmt = this.connection.createStatement();
	      String sql = "SELECT * FROM t_user";
	      rs = stmt.executeQuery(sql);
	      while (rs.next()) {
	        User user = new User();
	        user.setId(rs.getInt(1));
	        user.setUserName(rs.getString(2));
	        user.setPwd(rs.getString(3));
	        user.setGender(rs.getString(4));
	        user.setCategory(rs.getString(5));
	        user.setInterest(rs.getString(6));
	        user.setPhoto(rs.getString(7));
	        user.setRegTime(new Date(rs.getString(8)));
	        users.add(user);
	      }
	      return users;
	    }
	    catch (SQLException e) {
	      e.printStackTrace();
	      return null;
	    } finally {
	      DB.close(null, stmt, null);
	    }
	  }

	  public int deleteUser(int id)
	  {
	    Statement stmt = null;
	    try {
	      stmt = this.connection.createStatement();
	      String sql = "DELETE FROM t_user WHERE id = " + id;
	      stmt.executeUpdate(sql);
	      return 1;
	    }
	    catch (SQLException e) {
	      e.printStackTrace();
	      return 0;
	    } finally {
	      DB.close(null, stmt, null);
	    }
	  }
	
}
