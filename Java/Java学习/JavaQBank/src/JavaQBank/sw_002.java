package JavaQBank;

import java.util.Scanner;
import java.util.ArrayList;

class sw_002
{
	public static void main(String[] args) 
	{
		ArrayList<Integer> list = new ArrayList<Integer>();
		System.out.println("请输入一个大于1，小于100的正整数n和一个结尾标记exit(两者之间以空格隔开)，比如输入：10 exit，即n=10，将输出小于n(n=10)的所有素数与素数的个数，即：所有小于等于n的素数共有4个，它们是：[2, 3, 5, 7]");
		Scanner scanner = new Scanner(System.in);
		int n = 0;
		while (scanner.hasNextInt())
		{
			n = scanner.nextInt();
		}
		if (n<2) 
		{
			System.out.println("output:输入有误");
		}
		else 
		{
			for (int i = 2; i <= n; i++) 
			{
				if (isPrime(i))
					list.add(i);
			}
			System.out.println("output:所有小于等于"+n+"的素数共有" + list.size() + "个，它们是："+list);
		}
		scanner.close();
		/*** 
		定义一个静态的方法 isPrime,该方法实现对一个判断一个正整数是否为素数。
		* @param i 待判断的正整数,
		* @return 当i<2时，返回false，当i>=2时，i为素数则返回true，i为合数则返回false，
		*/
	}
	public static boolean isPrime(int i)
	 {
		/******start******/
		int j=2;
		
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				break;
		}
		if(j==i)
			return true;
		else
			return false;
			
		/******end******/
	 }
}