package JavaQBank;

import java.util.Scanner;

public class Java_007 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("output:请输入三个整数\n");
		Scanner cin=new Scanner(System.in);
		int a=cin.nextInt();
		int b=cin.nextInt();
		int c=cin.nextInt();
		if(a+b<c||a+c<b||c+b<a)
		{
			System.out.print("不能构成三角形\n");
		}
		else
		{
			int l=a+b+c;
			System.out.print(l);
		}
		
		cin.close();
	}

}
