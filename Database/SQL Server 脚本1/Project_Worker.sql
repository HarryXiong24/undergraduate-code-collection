CREATE DATABASE Project_Work
ON PRIMARY
(
	NAME = 'Project_Work_Data',
	FILENAME = 'D:\编程\数据库\Project_Work\Project_Work_Data.mdf',
	SIZE = 5,
	MAXSIZE = 100,
	FILEGROWTH = 10%
)
LOG ON
(
	NAME = 'Project_Work_Log',
	FILENAME = 'D:\编程\数据库\Project_Work\Project_Work_Log.ndf',
	SIZE = 1,
	MAXSIZE = 100,
	FILEGROWTH = 2
)

USE Project_Work
CREATE TABLE Division
(
	Dno char(4) PRIMARY KEY,
	Dname varchar(10) NOT NULL
)

USE Project_Work
CREATE TABLE Worker
(
	Wno char(6) PRIMARY KEY,
	Wname varchar(10) NOT NULL,
	Wsex  char(2) CHECK (Wsex IN('M', 'W')),
	Dno char(4) REFERENCES Division(Dno)
)

USE Project_Work
CREATE TABLE Project
(
	Pno char(6) PRIMARY KEY,
	Pname varchar(10) NOT NULL,
	Dno char(4) REFERENCES Division(Dno)
)

USE Project_Work
CREATE TABLE Project_Work
(
	Wno char(6),
	Dno char(4),
	FOREIGN KEY(Wno) REFERENCES Worker(Wno),
	FOREIGN KEY(Dno) REFERENCES Division(Dno),
	Wmoney int NOT NULL,
	PRIMARY KEY(Wno, Dno)
)

USE Project_Work
CREATE UNIQUE NONCLUSTERED INDEX Pname_index
ON Project(Pname)