package StudentGradeManageSystem;

import java.sql.*;

public class OutputDatabase {
	String classname;
	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";//SQL数据库引擎
    String URL="jdbc:sqlserver://localhost:1433;DatabaseName=Test";//注意更换自己的数据库端口和名称
    String Name="Sa";//填写登录名
    String Pwd="xhw20000424vxv";//密码
    Connection conn = null;
    
	OutputDatabase(String name)
	{
		this.classname = name;
	}
	
	public void open()
	{
		try
		{
		   Class.forName(driverName);
		   conn = DriverManager.getConnection(URL,Name,Pwd);
		   System.out.println("数据库连接成功");
		   
		   String table = "CREATE TABLE " + "class" + this.classname +
	                  "(Number VARCHAR(10) not NULL, " +
	                  " Name VARCHAR(20) not NULL," + 
	                  " Sex CHAR(1) not NULL, " + 
	                  " Chinese numeric(6, 2), " + 
	                  " English numeric(6, 2), " +
	                  " Math numeric(6, 2), " +
	                  " Average numeric(6, 2) )";
		   Statement stmt = conn.createStatement();
		   stmt.executeUpdate(table);
		   stmt.close();   
		} 
		catch(Exception a)
		{
		   a.printStackTrace();
		   System.out.println("连接失败");
	    }
	}
	
	public void Save(int st_num,String st_name,String st_sex,double Chinese,double English,double Math,double Average)
	{
		String sql = "INSERT INTO " + "class" + this.classname + "(Number,Name,Sex,Chinese,English,Math,Average)"
				  +  "VALUES(?,?,?,?,?,?,?)"; 
		try 
		{
		  PreparedStatement pstmt = conn.prepareStatement(sql);
		  pstmt.setString(1, ""+st_num);
		  pstmt.setString(2, st_name);
		  pstmt.setString(3, st_sex);
		  pstmt.setDouble(4, Chinese);
		  pstmt.setDouble(5, English);
		  pstmt.setDouble(6, Math);
		  pstmt.setDouble(7, Average);
		  pstmt.executeUpdate();
		  pstmt.close();
		}
		catch(SQLException e)
		{
			  e.printStackTrace();
		}
	}
	
	public void close()
	{
		try {
			this.conn.close();
		}
		catch(Exception a)
		{
		   a.printStackTrace();
		   System.out.println("关闭失败");
	    }
	}
}
