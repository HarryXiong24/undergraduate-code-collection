package DatabaseExam;
import java.sql.*;

//jdbc的写入和读出

public class exam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		  	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";//SQL数据库引擎
		    String URL="jdbc:sqlserver://localhost:1433;DatabaseName=Test";//注意更换自己的数据库端口和名称
		    String Name="Sa";//填写登录名
		    String Pwd="xhw20000424vxv";//密码
		    Connection conn = null;
		    Statement stmt = null;
		    
		   try{
			   Class.forName(driverName);
			   conn = DriverManager.getConnection(URL,Name,Pwd);
			   System.out.println("数据库连接成功");
			 
		   } 
		   catch(Exception e){
			   e.printStackTrace();
			   System.out.println("连接失败");
		      }
		   
		   String sql1 = "INSERT INTO class values('10001', 'Peter', 'M', 60, 45, 52, 62)";
		   String sql2 = "INSERT INTO class values('10002', 'Junny', 'w', 59, 89, 60, 75)";
		   String sql3 = "SELECT Name, Sex, Average FROM class";
		   
		   try {
			  stmt = conn.createStatement();

			  stmt.executeUpdate(sql1);
			  stmt.executeUpdate(sql2);
			  System.out.println("写入成功!");
		   }
		   catch(SQLException e) {
			  e.printStackTrace();
		   }
		   
		   try {
			   ResultSet rs = stmt.executeQuery(sql3);
			   
			   while( rs.next() )
			   {
				   String name = rs.getString("name");
				   String sex = rs.getString("sex");
				   double average = rs.getDouble("average");
				                                                                                                                                                     
				   System.out.println("Name:" + name + " Sex:" + sex + " Average:" + average);
			   }
			   rs.close();
			   stmt.close();
			   conn.close();
		   }
		   catch(SQLException e)
		   {
			   e.getStackTrace();
		   }
		   
		   
		   	  
	}
}

