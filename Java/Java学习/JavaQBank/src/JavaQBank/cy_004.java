package JavaQBank;

import java.io.BufferedReader; 
import java.io.InputStreamReader; 

class reverse 
{
		/*编写方法reverseArray实现数组重元素逆序\*/
	
	/******start******/
	public String[] reverseArray(String a[])
	{
		int i = 0;
		String temp = null;
		
		for(i = 0; i < a.length/2; i++)
		{
			temp = a[i];
			a[i] = a[a.length - i - 1];
			a[a.length - i - 1] = temp;
		}
		
		return a;
	}
	/******end******/
}

public class cy_004
{
	public static String input()
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String a=br.readLine();
			return a;
		}
		catch(Exception e)
		{
			return null;
		}
	}

	public static void print(String[] s)
	{
		for(int i=0;i<s.length;i++)
		{
			System.out.print(s[i]+",");
		}
		System.out.println();
	}
	public static void main(String args[])
	{
		String str1 = input();
		String a[]= new String[4];
		if(str1.contains(","))
		{
			a = str1.split(",");
			System.out.println("output:");
			print(a);
			reverse r =new reverse();
			String [] s = new String [4];
			s=r.reverseArray(a);
			System.out.println("逆序后：");
			print(s);
		}
		else
		{
			System.out.println("输入请用逗号隔开！");
		}
	}
}