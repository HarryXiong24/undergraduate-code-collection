/* CREATE DATABASE */

CREATE DATABASE ClassTest
ON PRIMARY
(
	NAME = ClassTest_Data,
	FILENAME = 'D:\编程\数据库\CLASSTEST\ClassTest.mdf',
	SIZE = 10,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 5
)
LOG ON
(
	NAME = ClassTest_Log,
	FILENAME = 'D:\编程\数据库\CLASSTEST\ClassTest.ldf',
	SIZE = 10,
	MAXSIZE = 2000,
	FILEGROWTH = 10%
)
GO

/* ALTER DATABASE */

ALTER DATABASE ClassTest
ADD LOG FILE
(
	NAME = ClassTest2_Log,
	FILENAME = 'D:\编程\数据库\CLASSTEST\ClassTest2.ldf',
	SIZE = 10,
	MAXSIZE = 2000,
	FILEGROWTH = 10%
)
GO

ALTER DATABASE ClassTest
MODIFY FILE
(
	NAME = ClassTest_Data,
	SIZE = 20,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 10
)
GO

/* DELETE DATABASE */
DROP DATABASE ClassTest

/* Create table */
Use ClassTest
CREATE TABLE ToyBrand
(
	cBrandId CHAR(3) PRIMARY KEY,
	cBrandName CHAR(3) NOT NULL
)

Use ClassTest
CREATE TABLE Toys
(
	cToyId CHAR(6) CHECK(cToyId LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
	vToyNAME VARCHAR(20) DEFAULT '000',
	cBrandID CHAR(3) references ToyBrand(cBrandId),
	cBrandName CHAR(3),
	MyToyRate MONEY CHECK(MyToyRate > 0) NOT NULL, 
	UserAge SMALLINT CHECK(UserAge BETWEEN 0 AND 16) NOT NULL,
	UserSex char(3) CHECK(UserSex in('M', 'W')),

	PRIMARY KEY(cToyId),
	FOREIGN KEY(cBrandID) REFERENCES ToyBrand(cBrandID)
)

/* Delete table */
DROP TABLE ToyBrand
DROP TABLE Toys
	
/* Alter */
ALTER TABLE Toys
ADD ToyWeight SMALLINT NOT NULL

ALTER TABLE Toys
DROP COLUMN ToyWeight