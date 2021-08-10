package ch4;

import java.util.Scanner;

class Palindrome
{
	public static int reverse(int number)
	{
		int res = 0;
		
		StringBuffer st = new StringBuffer(String.valueOf(number));
		StringBuffer reverse = st.reverse();
        res = Integer.valueOf(reverse.toString());
        
        return res;	
	}
	
	public static boolean isPalindrome(int number)
	{
		int res = 0;
		
        res = Palindrome.reverse(number);
		
		if(res == number)
		{
			return true;
		}
		
		return false;	
	}
}

public class Test3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int number = 0;
		int reverse = 0;
		boolean res = false;
		
		Scanner input = new Scanner(System.in);
		
		System.out.printf("Enter a number:\n");
		number = input.nextInt();
		
		reverse = Palindrome.reverse(number);
		System.out.printf("The reverse number is:%d\n", reverse);
		
		res = Palindrome.isPalindrome(number);
		if( res == true)
			System.out.printf("Number %d is a palindrome\n", number);
		else
			System.out.printf("Number %d is not a palindrome\n", number);
			
		input.close();
		
		
	}

}



//int i = 0;
//int len;
//String temp;
//
//temp = Integer.toString(number);
//
//len = temp.length();
//
//int a[] = new int[len];
//
//for( i = 0; i < a.length; i++)
//{
//	a[i] = number % 10;
//	number = number / 10;
//}
//
//for(i = 0; i < a.length/2; i++)
//{
//	if(a[i] != a[a.length - i- 1])
//	{
//		return false;
//	}
//}
//
//return true;
