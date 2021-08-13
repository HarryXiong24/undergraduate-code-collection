--创建储存过程
CREATE PROCEDURE preInfo
@StundentName VARCHAR(20)
AS
BEGIN
	SELECT Sno, Sname, Ssex, Sbirth
	FROM Student
	WHERE Student.Sname = @StundentName
END

--执行语句
DECLARE @return int
--有返回值
EXEC @return = preInfo 'Harry'
--显示返回值
SELECT @return as ReturnValue