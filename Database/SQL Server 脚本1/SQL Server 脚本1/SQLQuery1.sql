USE master
GO
CREATE DATABASE myclass1
ON PRIMARY
(
	NAME = myclass1_data,
	FILENAME = 'D:\编程\数据库\myclass1.MDF',
	SIZE = 10,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 5
)
LOG ON
(
	NAME = myclass1_log,
	FILENAME = 'D:\编程\数据库\myclass1.LDF',
	SIZE = 10,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 5
)
GO