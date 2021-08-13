import sqlite3
# 连接到SQLite数据库,数据库文件是mrsoft.db
conn = sqlite3.connect('mrsoft.db')
# 创建一个Cursor:
cursor = conn.cursor()
cursor.execute('delete from user where id = ?',(1,))
cursor.execute('select * from user')
result = cursor.fetchall()
print(result)
# 关闭游标
cursor.close()
# 提交事务
conn.commit()
# 关闭Connection:
conn.close()