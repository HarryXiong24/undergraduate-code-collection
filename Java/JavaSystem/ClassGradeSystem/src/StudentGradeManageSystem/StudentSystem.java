package StudentGradeManageSystem;
import java.util.Scanner;

public class StudentSystem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int first_choose = 0;
		
		System.out.printf("欢迎进入学生成绩管理系统!\n");
		do {
			System.out.printf("您有如下选择:\n1.注册班级\n2.登录班级\n3.退出\n");
			System.out.printf("请输入:");
			first_choose = input.nextInt();
			
			if(first_choose == 1)
			{
				System.out.printf("请输入班级名:\n");
				String regist_name = input.next();
				System.out.printf("请输入密码:\n");
				String regist_pass = input.next();
				Regist rex = new Regist();
				
				rex.regist(regist_name, regist_pass);
				rex.inputfile();
			}
			
			if(first_choose == 2)
			{
				int loginOK;
				int i;
				
				System.out.printf("请输入班级名:\n");
				String login_name = input.next();
				System.out.printf("请输入密码:\n");
				String login_pass = input.next();
				classes lex= new classes();
				
				loginOK = lex.login(login_name, login_pass);
				
				if(loginOK == 1)
				{
					System.out.printf("请输入学生人数:\n");
					int stsnumber = input.nextInt();
					lex.setClass_number(stsnumber);
					
					System.out.printf("是否存储到数据库:1.是 2.否\n");
					int save_choose = input.nextInt();
					if(save_choose == 1)
					{
						OutputDatabase data = new OutputDatabase(login_name);
						data.open();
						for(i = 0; i < lex.st.length; i++)
						{
							System.out.printf("请输入学号:\n");
							int st_num = input.nextInt();
							System.out.printf("请输入姓名和性别:\n");
							String st_name = input.next();
							String st_sex = input.next();
							System.out.printf("请输入成绩:\n");
							double Chinese = input.nextDouble();
							double English = input.nextDouble();
							double Math = input.nextDouble();
						
							lex.writefile(i,st_num,st_name,st_sex,Chinese,English,Math);
							double Average = lex.st[i].ave_cal();
							data.Save(st_num,st_name,st_sex,Chinese,English,Math,Average);
						}	
						data.close();
					}
					else {
						for(i = 0; i < lex.st.length; i++)
						{
							System.out.printf("请输入学号:\n");
							int st_num = input.nextInt();
							System.out.printf("请输入姓名和性别:\n");
							String st_name = input.next();
							String st_sex = input.next();
							System.out.printf("请输入成绩:\n");
							double Chinese = input.nextDouble();
							double English = input.nextDouble();
							double Math = input.nextDouble();
						
							lex.writefile(i,st_num,st_name,st_sex,Chinese,English,Math);
						}
					}
					
					System.out.println("保存完毕!");
					
				}
			}
			
			if(first_choose == 3)
			
			{
				System.out.println("欢迎下次使用!");
			}

			try {
				Thread.sleep(1000);
			}
			catch(InterruptedException e) {
				
			}
			
		}while(first_choose != 3);
		
		input.close();
		
	}

}
