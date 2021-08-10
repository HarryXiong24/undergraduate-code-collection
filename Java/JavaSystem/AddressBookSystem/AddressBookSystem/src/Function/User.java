package Function;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import Database.Create_NewDatabase;

public class User implements Database.Connection_Database, Create_NewDatabase{
	
	protected String account;
	protected String password;
	protected String DatabaseName;
	
	public User(String account, String password) {
		this.account = account;
		this.password = password;
		this.DatabaseName = "User" + account + password;	
	}

	// 创建新的数据库
	public int Create_NewDatabase() {
	
	   // JDBC driver name and database URL
	   final String JDBC_DRIVER = "com.microsoft.sqlserver.jdbc.SQLServerDriver";  
	   final String DB_URL = "jdbc:sqlserver://localhost:1433";
	   final String USER = "Sa";
	   final String PASS = "xhw20000424vxv";
	   Connection conn = null;
	   Statement stmt = null;
	   int flag = 0;
	   
	   try{
	      // Register JDBC driver
	      Class.forName(JDBC_DRIVER);

	      // Open a connection
	      System.out.println("Connecting to database...");
	      conn = DriverManager.getConnection(DB_URL, USER, PASS);
	      System.out.println("Database connected successfully...");

	      // Execute a query
	      System.out.println("Creating database...");
	      stmt = conn.createStatement();

	      String sql = "CREATE DATABASE " + DatabaseName + " " +
	    		  "\nON PRIMARY\r\n" + 
	    		  "(\r\n" + 
	    		  "	NAME = " + DatabaseName + ",\r\n" + 
	    		  "	FILENAME = 'D:\\编程\\数据库\\AddressBookSystem\\" + DatabaseName + "_Data.mdf',\r\n" + 
	    		  "	SIZE = 5,\r\n" + 
	    		  "	MAXSIZE = UNLIMITED,\r\n" + 
	    		  "	FILEGROWTH = 2\r\n" + 
	    		  ")\r\n" + 
	    		  "LOG ON\r\n" + 
	    		  "(\r\n" + 
	    		  "	NAME = " + DatabaseName + "_log,\r\n" + 
	    		  "	FILENAME = 'D:\\编程\\数据库\\AddressBookSystem\\" + DatabaseName + ".ldf',\r\n" + 
	    		  "	SIZE = 5,\r\n" + 
	    		  "	MAXSIZE = UNLIMITED,\r\n" + 
	    		  "	FILEGROWTH = 10%\r\n" + 
	    		  ")";
	      System.out.println(sql);
	      stmt.executeUpdate(sql);
	      System.out.println("Database created successfully...");
	   }
	   catch(SQLException se){
	      //Handle errors for JDBC
	      se.printStackTrace();
	      flag = 4;
	   }
	   catch(Exception e){
	      // Handle errors for Class.forName
	      e.printStackTrace();
	   }
	   finally{
	      // finally block used to close resources
	      try{
	         if(stmt!=null)
	            stmt.close();
	      }
	      catch(SQLException se2){
	      }
	      // nothing we can do
	      try{
	         if(conn!=null)
	            conn.close();
	      }
	      catch(SQLException se){
	         se.printStackTrace();
	      }//end finally try
	      System.out.println(flag);
	      return flag;
	   }//end try
	}
	
	// 连接数据库
	public int Connection_Database() {
			
		final String JDBC_DRIVER="com.microsoft.sqlserver.jdbc.SQLServerDriver";// SQL数据库引擎
		final String DB_URL="jdbc:sqlserver://localhost:1433;DatabaseName=" + DatabaseName;// 注意更换自己的数据库端口和名称
		final String USER="Sa";// 填写登录名
		final String PASS="xhw20000424vxv";// 密码
		
	    try{
			   Class.forName(JDBC_DRIVER);
			   DriverManager.getConnection(DB_URL,USER,PASS);
			   System.out.println("数据库连接成功");
			 
		   } 
		catch(Exception e){
			   e.printStackTrace();
			   System.out.println("连接失败");
		   }
		return 0;
	}
	
	/*
	// 查找数据库
	public int Research_Database()
	{
		final String JDBC_DRIVER = "com.microsoft.sqlserver.jdbc.SQLServerDriver";  
		final String DB_URL = "jdbc:sqlserver://localhost:1433";
		final String USER = "Sa";
		final String PASS = "xhw20000424vxv";
		Connection conn = null;
		Statement stmt = null;
		String Research_Res = null;
		int  flag = 0;
		   
	   try{
		  // Register JDBC driver
		  Class.forName(JDBC_DRIVER);
		
		  // Open a connection
		  System.out.println("Connecting to database...");
		  conn = DriverManager.getConnection(DB_URL, USER, PASS);
		  System.out.println("Database connected successfully...");
		
		  // Execute a query
		  System.out.println("Creating database...");
		  stmt = conn.createStatement();
		
		  String sql = "SELECT Distinct Name FROM Master..SysDatabases where Name like '" + DatabaseName + "'";

		  System.out.println(sql);
		  ResultSet rs = stmt.executeQuery(sql);
		  Research_Res = rs.getString("Name");
	   }
	   catch(SQLException se){
	      //Handle errors for JDBC
	      se.printStackTrace();
	      if(Research_Res.equals(DatabaseName) == true || Research_Res == null)
		  {
			  flag = 4;
		  }
	      else
	      {
	    	  flag = 0;
	      }
	   }
	   catch(Exception e){
	      // Handle errors for Class.forName
	      e.printStackTrace();
	      if(Research_Res.equals(DatabaseName) == true || Research_Res == null)
		  {
			  flag = 4;
		  }
	      else
	      {
	    	  flag = 0;
	      }
	   }
	   finally{
		      // finally block used to close resources
		  try{
		     if(stmt!=null)
		        stmt.close();
		  }
		  catch(SQLException se2){
		  }
		  // nothing we can do
		  try{
		     if(conn!=null)
		        conn.close();
		  }
		  catch(SQLException se){
		     se.printStackTrace();
		  }
		  //end finally try
		  
		  System.out.println(flag);
		  System.out.println(Research_Res);
		  return flag;
	   }//end try
	}
	*/
	public void Create_Contact()
	{
		
	}
			
}
