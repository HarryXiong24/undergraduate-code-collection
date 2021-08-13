import pymysql

# 打开数据库连接
db = pymysql.connect("localhost", "root", "root", "mrsoft")
# 使用 cursor() 方法创建一个游标对象 cursor
cursor = db.cursor()
# 使用 execute() 方法执行 SQL，如果表存在则删除
cursor.execute("DROP TABLE IF EXISTS books")
# 使用预处理语句创建表
sql = """
CREATE TABLE books (
  id int(8) NOT NULL AUTO_INCREMENT,
  name varchar(50) NOT NULL,
  category varchar(50) NOT NULL,
  price decimal(10,2) DEFAULT NULL,
  publish_time date DEFAULT NULL,
  PRIMARY KEY (id)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
"""
# 执行SQL语句
cursor.execute(sql)
# 关闭数据库连接
db.close()