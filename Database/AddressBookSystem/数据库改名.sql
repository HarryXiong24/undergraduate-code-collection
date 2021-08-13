/*use master
alter database regexp_like(,'^a[a-z]*n$') modify name=Info_181*/



declare @temp varchar(100)
SELECT @temp = Name FROM Master..SysDatabases where Name like 'YQBlog' ORDER BY Name
EXEC sys.sp_renamedb @dbname = @temp,
    @newname = 'Info_181'

declare @tem varchar(100)
SELECT Distinct Name FROM Master..SysDatabases where Name like ''




