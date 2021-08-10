package test3;
import java.util.Scanner;

class CountLetters
{
	public static int countLetters(String s)
	{
		return s.length();
	}
}

public class T2 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		System.out.println("Please input a String:");
		String s = input.next();
		int len = CountLetters.countLetters(s);
		
		System.out.println("The String lenth is:" + len);
		input.close();	  
	}
}
