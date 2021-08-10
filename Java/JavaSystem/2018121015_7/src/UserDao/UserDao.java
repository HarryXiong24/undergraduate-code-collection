package UserDao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.activation.DataSource;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import com.sun.xml.internal.bind.CycleRecoverable.Context;

import entity.User;

public class UserDao {
	private Connection connection;
	private DataSource dataSource;
	
	public UserDao() {
		// TODO Auto-generated constructor stub
		try {
			Context initContext = (Context) new InitialContext();
			Context envContext = (Context) ((InitialContext) initContext).lookup("java:/comp/env");
			dataSource = (DataSource)((InitialContext) envContext).lookup("JDBC");
			connection = dataSource.getConnection();
		} catch (NamingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public int addUser(User user) {
		PreparedStatement pstmt = null;
		Statement stmt = null;
		try {
//			Date date = new Date();
//			long lg = date.getTime();		
//			String sql = "INSERT INTO t_user(name,pwd,gender,category,interest,photo,regTime) VALUES(?, ?, ?, ?, ?, ?, ?)";
//			pstmt = connection.prepareStatement(sql);
//			pstmt.setString(1, user.getUserName());
//			pstmt.setString(2, user.getPwd());
//			pstmt.setString(3, user.getGender());
//			pstmt.setString(4, user.getCategory());
//			pstmt.setString(5, user.getInterest());
//			pstmt.setString(6, user.getPhoto());
//			pstmt.setDate(7, new java.sql.Date(lg));
//			
//			pstmt.executeUpdate();
//			pstmt.clearParameters();
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
