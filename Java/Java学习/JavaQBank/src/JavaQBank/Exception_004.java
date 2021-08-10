package JavaQBank;

public class Exception_004 
{
	public static void main(String args[])
	{
		int a=4,b=0;
		try{
			if(b == 0) 
				throw new ArithmeticException();
			else 
				System.out.println("output:result is"+a/b);
		}
		/******start******/
		catch(ArithmeticException e){
			System.out.println(e +" output:throwed!!");
		/******end******/
		}
	}
}