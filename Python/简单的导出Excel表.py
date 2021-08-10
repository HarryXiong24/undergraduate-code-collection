import xlwt

wb=xlwt.Workbook()
ws=wb.add_sheet('python',cell_overwrite_ok=True)
for i in range(0,7):
	for k in range(5):
		ws.write(i,k,i+k)
wb.save('a.xls')