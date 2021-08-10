package StudentGradeManageSystem;
import java.io.*;

public class Regist {
	String name;
	String pass;
	String filename;
	
	void regist(String name, String pass){
		this.name = name;
		this.pass = pass;
		this.filename = name + ".txt";
	}
	
	void inputfile()
	{
		try {
			FileWriter theclass = new FileWriter(filename);
			BufferedWriter myclass = new BufferedWriter(theclass);
			myclass.write(filename);
			myclass.write(pass);
			myclass.newLine();
			myclass.write("班级名:"+this.name);
			myclass.newLine();
			myclass.write("number"+"\t\t"+"name"+"\t\t"+"sex"+"\t\t"+"Chinese" + "\t\t" + "English" + "\t\t" + "Math" + "\t\t" + "Average");
			myclass.newLine();
			myclass.close();
			System.out.print("注册成功!\n");
		}
		catch(IOException ioe){
			System.out.print(ioe);
		}
	}
	
}

