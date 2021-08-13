CREATE DATABASE Stu2018121015
ON PRIMARY
(
	NAME = Stu_Data,
	FILENAME = 'D:\Stu_Data.mdf',
	SIZE = 5,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 2
)
LOG ON
(
	NAME = Stu_log,
	FILENAME = 'D:\Stu.ldf',
	SIZE = 5,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 10%
)
GO                                                                                                                                                                                   

USE Stu2018121015
CREATE TABLE Class
(
	Cno CHAR(4) PRIMARY KEY,
	Cname VARCHAR(50),
	Cmajor VARCHAR(100),
	Counselor VARCHAR(50)
)

USE Stu2018121015
CREATE TABLE Student
(
	Sno CHAR(8) PRIMARY KEY,
	Sname VARCHAR(20) NOT NULL,
	SIDcno VARCHAR(30) UNIQUE,
	Ssex CHAR(2) CHECK (Ssex IN('M','W')),
	Sbirth Date,
	Cno CHAR(4) REFERENCES Class(Cno)
)

USE Stu2018121015
CREATE TABLE Curriculum
(
	Cuno CHAR(5) PRIMARY KEY,
	Cuname VARCHAR(50) NOT NULL,
	Cupoint FLOAT CHECK(Cupoint >= 1 AND Cupoint <= 6)
)
	
USE Stu2018121015
CREATE TABLE Elective
(
	Cuno CHAR(5),
	Sno CHAR(8),
	Egrade INT CHECK(Egrade BETWEEN 0 AND 100),
	PRIMARY KEY(Cuno, Sno),
	FOREIGN KEY(Cuno) REFERENCES Curriculum(Cuno),
	FOREIGN KEY(Sno) REFERENCES Student(Sno)
)

USE Stu2018121015
CREATE UNIQUE NONCLUSTERED INDEX Sname_index
ON Student(Sname)
CREATE UNIQUE NONCLUSTERED INDEX Cuname_index
ON Curriculum(Cuname)

--T2
USE Stu2018121015
INSERT Class VALUES ('1001', 'Class181', 'Computer', 'Sara'),
('1002', 'Class182', 'Computer', 'Sara'),
('1003', 'Class183', 'English', 'Sally'),
('1004', 'Class184', 'Computer', 'Paul'),
('1005', 'Class185', 'Math', 'Pete'),
('1006', 'Class186', 'Math', 'Pete'),
('1007', 'Class187', 'Chinese', 'Sally'),
('1008', 'Class188', 'PE', 'Paul')

INSERT Student VALUES ('20180001', 'Peter', '10001', 'M', '2000-4-2', '1001'),
('20180002', 'Harry', '10002', 'M', '2000-4-24', '1002'),
('20180003', 'Jack', '10003', 'M', '2000-4-4', '1003'),
('20180004', 'Margaret', '10004', 'W', '2000-6-26', '1004'),
('20180005', 'John', '10005', 'M', '2000-4-2', '1005'),
('20180006', 'Mark', '10006', 'M', '2000-04-04', '1006'),
('20180007', 'Curry', '10007', 'M', '2000-04-26', '1003'),
('20180008', 'Kate', '10008', 'W', '2000-03-21', '1004'),
('20180009', 'James', '10009', 'M', '2000-02-14', '1008'),
('20180010', 'David', '10010', 'M', '2000-01-31', '1007')

INSERT Curriculum VALUES ('90001', 'Math', 2.5),
('90002', 'English', 3),
('90003', 'Chinese', 2),
('90004', 'Computer', 4),
('90005', 'Internet', 4),
('90006', 'SQL', 3),
('90007', 'PE', 1.5),
('90008', 'Physics', 2)


INSERT Elective VALUES ('90005', '20180001', 100),
('90004', '20180002', 90),
('90003', '20180003', 70),
('90002', '20180004', 90),
('90001', '20180005', 60),
('90007', '20180003', 75),
('90008', '20180007', 85),
('90006', '20180009', 45),
('90007', '20180002', 85),
('90006', '20180001', 75),
('90006', '20180002', 77),
('90006', '20180003', 83)

--T3
USE Stu2018121015
SELECT Sno, Sname, Sbirth INTO newstudent FROM Student

--T4
USE Stu2018121015
INSERT INTO newstudent 
SELECT Sno, Sname, Sbirth 
FROM Student

--T5
USE Stu2018121015
UPDATE Student
SET Sname = 'Jerry'
WHERE Sno = '20180005'

--T6
DELETE FROM Student where Sname = 'Jerry'

--T7
SELECT * FROM Elective 

--T8
SELECT Sno, Sname FROM Student
ORDER BY Sno DESC

--T9
UPDATE Elective
SET Egrade = Egrade + 10 WHERE Sno = '20180002'

--T10
SELECT Top 10 Sno FROM Elective
WHERE Cuno = '90001'
ORDER BY Egrade ASC

--T11
SELECT Cuno, Egrade FROM Elective
WHERE Cuno = '90001' or Cuno = '90002'

--T12
SELECT Cuno FROM Elective
WHERE Egrade IS NULL

--T13
SELECT * FROM Student
WHERE Sname = 'Harry'

--T14
SELECT DISTINCT Cno FROM Class

--T15
SELECT Sno, Cuno, Egrade FROM Elective

--T16
USE Stu2018121015
SELECT Student.Sno, Sname, Curriculum.Cuno, Curriculum.Cuname, AVG(Egrade) as Average
FROM Elective, Student, Curriculum
WHERE Elective.Sno = Student.Sno and Elective.Cuno = Curriculum.Cuno
GROUP BY Student.Sno, Sname, Curriculum.Cuno, Curriculum.Cuname

--T17
USE Stu2018121015
SELECT Student.Sname as 'Student who elective SQL' 
FROM Student
WHERE Sno in (SELECT Sno FROM Elective,Curriculum WHERE Elective.Cuno = Curriculum.Cuno and Cuname = 'SQL')

--T18
USE Stu2018121015
SELECT SUBSTRING(Sname, 1, 1) as 'The head of name', COUNT(*) AS Number
FROM Student
GROUP BY SUBSTRING(Sname, 1, 1)

--T19
--查询每门课程有多少人选，即使没有人选的课程也要显示出来
USE Stu2018121015
SELECT Curriculum.Cuno, Curriculum.Cuname, COUNT(*) as Number
FROM Elective, Curriculum
WHERE Elective.Cuno = Curriculum.Cuno
GROUP BY Curriculum.Cuno, Curriculum.Cuname

--T20
--查询每个同学每门课程的总分和平均分，分时高的显示在顶部（平均分高于60才显示）
USE Stu2018121015
SELECT Sname, Cuname, AVG(Egrade) as Average, SUM(Egrade) as TotalGrade
FROM Elective, Student, Curriculum
WHERE Elective.Sno = Student.Sno and Elective.Cuno = Curriculum.Cuno
GROUP BY Sname, Cuname
HAVING AVG(Egrade) >= 60
ORDER BY SUM(Egrade) DESC

--T21
--查找数据库原理及应用课程的最高分的学生的姓名
USE Stu2018121015
SELECT TOP 1 Cuname, Sname, Egrade
FROM Elective, Curriculum, Student
WHERE Student.Sno = (SELECT TOP 1 Sno FROM Elective, Curriculum 
WHERE Curriculum.Cuno = Elective.Cuno and Cuname = 'SQL'
ORDER BY Egrade DESC) 
and Curriculum.Cuno = (SELECT TOP 1 Elective.Cuno FROM Elective, Curriculum 
WHERE Curriculum.Cuno = Elective.Cuno and Cuname = 'SQL'
ORDER BY Egrade DESC)
and Egrade = (SELECT TOP 1 Egrade FROM Elective, Curriculum 
WHERE Curriculum.Cuno = Elective.Cuno and Cuname = 'SQL'
ORDER BY Egrade DESC)

--T22
--统计每个学生获得的学分，分数大于等于60分的才能获得学分。显示学号、姓名和学分
SELECT Student.Sno, Sname, SUM(Cupoint) as 'The total of point'
FROM Student, Curriculum, Elective
WHERE Elective.Egrade >= 60 and Student.Sno = Elective.Sno and Curriculum.Cuno = Elective.Cuno
GROUP BY Student.Sno, Sname

--T23
--查询每个同学的学号，姓名、选修的课程名和成绩
SELECT Student.Sno, Sname, Cuname, Egrade
FROM Student, Curriculum, Elective
WHERE Student.Sno = Elective.Sno and Curriculum.Cuno = Elective.Cuno
ORDER BY Student.Sno

--T24
--统计每个班有多少人
SELECT Cname, COUNT(Cno) as 'The number of class'
FROM Class
GROUP BY Cname

--T25
--统计每个班每门课程的平均分，需要班级名称，课程名称和平均分数
SELECT Cname, Cuname, AVG(Egrade) as 'Average grade'
FROM Class, Curriculum, Elective, Student
WHERE Elective.Cuno = Curriculum.Cuno and Elective.Sno = Student.Sno and Student.Cno = Class.Cno 
GROUP BY Cname, Cuname
ORDER BY Cname

--T26
--查询班级和学生姓名
SELECT Cname, Sname
FROM Student, Class
WHERE Student.Cno = Class.Cno
ORDER BY Class.Cno

--T27
--查找“数据库原理及应用”课程没有成绩的学生有哪些
SELECT Sname, 'no grade in SQL' as type
FROM Student, Elective, Curriculum
WHERE Student.Sno = Elective.Sno AND Elective.Cuno = Curriculum.Cuno
AND Cuname = 'SQL' AND Egrade = 0

--T28
--按照年度统计每年出生的学生有多少人

--T29
--查询学生的姓名、课程名、成绩,按照成绩降序排列,成绩相同按照学号由小到大排列
SELECT Sname, Cuname, Egrade
FROM Student, Curriculum, Elective
WHERE Student.Sno = Elective.Sno AND Elective.Cuno = Curriculum.Cuno 
ORDER BY Egrade DESC, Student.Sno

--T30
--统计男女生各有多少人
SELECT TOP 1 (SELECT COUNT(Ssex) AS 'Man' FROM Student WHERE Ssex = 'M') as Man, (SELECT COUNT(Ssex) AS 'Woman' FROM Student WHERE Ssex = 'W') AS Woman
FROM Student

--T31
CREATE VIEW Exam1
AS
SELECT Student.Sno, Sname, SUM(Egrade) as Total, AVG(Egrade) as Average
FROM Student, Elective
WHERE Student.Sno = Elective.Sno 
GROUP BY Student.Sno, Sname

--T32
SELECT Top 1 Sno, Sname, Total, Average
FROM Exam1

--T33
CREATE PROCEDURE PROExam1
@InputSno char(8),
@OutputSno char(8) OUTPUT,
@Average int OUTPUT,
@Total int OUTPUT
AS
BEGIN
	IF EXISTS(SELECT * FROM Exam1 WHERE Sno = @InputSno)
		BEGIN
			SELECT @OutputSno =	SNO, @Average = Average, @Total = Total
			FROM Exam1
			WHERE Sno = @InputSno
			RETURN 0
		END
	ELSE
		BEGIN
			PRINT 'No this student'
			RETURN 1
		END
END

--T34
DECLARE @OutputSno char(8)
DECLARE @Average int
DECLARE @Total int 
DECLARE @ReturnValue int
EXEC @ReturnValue = PROExam1 '20180002',@OutputSno OUTPUT, @Average OUTPUT,@Total OUTPUT
SELECT @OutputSno as Sno ,@Average as Average, @Total as Total, @ReturnValue as ReturnValue

