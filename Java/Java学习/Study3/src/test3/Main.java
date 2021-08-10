package test3;
import java.util.Scanner;

public class Main {
	/******start******/
	public int checkPassword(String pwd) 
	{
		int lenth = 0;
		int i = 0;
		int count = 0;
		
		lenth = pwd.length();
		char[] ch = pwd.toCharArray();
		
		if(lenth < 8)
		{
			System.out.println("Invalid Password");
			return 0;
		}
		
		for(i = 0; i < lenth; i++)
		{
			if( (ch[i] < '0' || ch[i] > '9') && (ch[i] < 'a' || ch[i] > 'z') && (ch[i] < 'a' && ch[i] > 'z') )
			{
				System.out.println("Invalid Password");
				return 0;
			}
			if( ch[i] >= '0' && ch[i] <= '9')
			{
				count++;
			}
		}
		
		if(count < 2)
		{
			System.out.println("Invalid Password");
			return 0;
		}
		else
		{
			System.out.println("Valid Password");
			return 0;
		}
		
		
	}
	/******end******/
		public static void main(String[] args) {
			  Main main = new Main(); System.out.println("请输入密码：");
			  Scanner scanner = new Scanner(System.in); 
			  String pwd = scanner.next();
			  main.checkPassword(pwd);
			  
			  scanner.close();
		}
}
