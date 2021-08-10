package UserDao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DB {
	private String dbFile;

	static {
		try {
			Class.forName("org.sqlite.JDBC");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

	public DB(String dbFile) {
		this.dbFile = dbFile;
	}

	public Connection getConnection() {
		try {
			String url = "jdbc:sqlite:" + this.dbFile;
			Connection connection = DriverManager.getConnection(url);
			return connection;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static void close(Connection connection, Statement stmt, ResultSet rs) {
		try {
			if (connection != null) {
				connection.close();
			}
			if (stmt != null) {
				stmt.close();
			}
			if (rs != null)
				rs.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}