CREATE DATABASE Hospital
ON PRIMARY
(
	NAME = 'Hospital_Data',
	FILENAME = 'D:\编程\数据库\Hospital\Hospital_Data.mdf',
	SIZE = 5,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 1
)
LOG ON
(
	NAME = 'Hospital_Log',
	FILENAME = 'D:\编程\数据库\Hospital\Hospital_Log.ndf',
	SIZE = 2,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 10%
)
GO

USE Hospital
CREATE TABLE Faculty
(
	Fname varchar(10) PRIMARY KEY,
	Faddress varchar(10),
	Ftelephone char(7)
)

USE Hospital
CREATE TABLE Doctor
(
	Dno char(6) PRIMARY KEY,
	Dname varchar(6) NOT NULL,
	Dtitle varchar(10),
	Dage tinyint NOT NULL,
	Fname varchar(10) REFERENCES Faculty(Fname)
)

USE Hospital
CREATE TABLE PatientRoom
(
	Rno char(4) PRIMARY KEY,
	Rsite tinyint CHECK (Rsite >= 0 and Rsite <= 4),
	Fname varchar(10) REFERENCES Faculty(Fname)
)

USE Hospital
CREATE TABLE Patient
(
	Pno char(6) PRIMARY KEY,
	Pname  varchar(6) NOT NULL,
	Psex char(2) CHECK (Psex IN('M' , 'W')),
	Pdiagnose varchar(20),
	Dno char(6) REFERENCES Doctor(Dno),
	Rno char(4) REFERENCES PatientRoom(Rno)
)

USE Hospital
CREATE UNIQUE NONCLUSTERED INDEX Doctor_index
ON Doctor(Dname)
CREATE UNIQUE NONCLUSTERED INDEX Patient_index
ON Patient(Pname)


