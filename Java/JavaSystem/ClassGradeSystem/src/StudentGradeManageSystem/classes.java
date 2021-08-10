package StudentGradeManageSystem;
import java.io.*;


interface Login {
	abstract int login(String name, String pass);
}

public class classes implements Login {
	String may_name;
	String may_pass;
	String may_filename;
	String filename;
	String outputname;
	StudentInfo st[];
	
	public int login(String name, String pass)
	{
		this.may_name = name;
		this.may_pass = pass;
		this.may_filename = this.may_name + ".txt" + this.may_pass;
		this.outputname = name + ".txt";
		try {
			FileReader theclass = new FileReader(outputname);
			BufferedReader myclass = new BufferedReader(theclass);
			filename = myclass.readLine();
			myclass.close();
			
		}
		catch(IOException ioe){
			System.out.println("登录失败!");	
		}
		
			
		if( filename.equals(may_filename) ) 
		{
			System.out.println("登录成功!");
			return 1;
		}
		else
		{
			System.out.println("密码错误!");
			return 0;
		}
		
	}
	

	public void setClass_number(int class_number) {
		int i = 0;
		
		st = new StudentInfo[class_number];
		
		for(i = 0; i < class_number; i++)
		{
			st[i] = new StudentInfo();
		}
	}

	public void writefile(int i,int st_num,String st_name,String st_sex,double Chinese, double English , double Math)
	{
		st[i].setInfo(st_num, st_name, st_sex);
		st[i].setscore(Chinese, English, Math);
		st[i].ave_cal();
		
		try {
			FileWriter out = new FileWriter(outputname,true);
			BufferedWriter outfile = new BufferedWriter(out);
			outfile.newLine();
			outfile.write(st[i].number+"\t\t");
			outfile.write(st[i].name+"\t\t");
			outfile.write(st[i].sex+"\t\t");
			outfile.write(st[i].Chinese + "\t\t" + st[i].English + "\t\t" + st[i].Math + "\t\t");
			outfile.write("Average is:"+st[i].average);
			outfile.close();
		}
			
		catch(IOException ioe){
			System.out.print("没有这个班级!\n");
		}	
	}
	
}
