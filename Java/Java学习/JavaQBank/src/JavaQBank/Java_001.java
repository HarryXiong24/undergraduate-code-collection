package JavaQBank;

import java.util.Scanner;

public class Java_001 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("output:please input yrear:");
		int year;
		Scanner scanner = new Scanner(System.in);
		year = scanner.nextInt();
		if (year<0||year>3000)
		{
			System.out.println("error");
			System.exit(0);
		}
		if ((year%4==0)&&(year%100!=0)||(year%400==0))
			System.out.println(year+" is bissextile");
		else
			System.out.println(year+" is not bissextile ");
		
		scanner.close();
	}
	

}
