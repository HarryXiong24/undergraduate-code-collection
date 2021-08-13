declare @a int, @b int ,@c int
set @a = 556
select @b = 778 + @a
if @b > 2000
	begin
		print @b
		print @a
	end
else
	begin
		print 'Not full'
		print 'Try again'
	end

set @c = 3
while @c < 10
begin
	set @c = @c + 1
end

print @c