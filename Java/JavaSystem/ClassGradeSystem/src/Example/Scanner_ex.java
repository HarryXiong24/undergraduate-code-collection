package Example;

import java.util.Scanner;

public class Scanner_ex {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a=0,b=0;
		
		Scanner ex = new Scanner(System.in);
		System.out.print("请输入数字a:");
		a = ex.nextInt();
		System.out.print("请输入数字b:");
		b = ex.nextInt();
		ex.close();
		System.out.println("a+b=" + (a+b));
	}

}
