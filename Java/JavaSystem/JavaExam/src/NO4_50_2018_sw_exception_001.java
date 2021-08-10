import java.util.Scanner;

import jdk.nashorn.internal.runtime.linker.InvokeByName;
class MyException{
	private int output;
	public int getOutput(){
		return output;
	}
	//check方法，如果input为奇数，返回input%2的值，如果input为偶数则抛出一个异常对象，包含的异常信息如下所示；
	public void check(int input) throws Exception{
		if (input % 2 != 0) {
			output = input % 2;
		}else{
			throw new Exception("error,input number is: "+input);
		}
	}
}

class HandleException{
/******start******/
	public void invokeCheck(MyException exception, int input){
		try {
			exception.check(input);
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
/******end******/
}

public class NO4_50_2018_sw_exception_001 {
	public static void main(String[] args)  {
		MyException myException = new MyException();
		HandleException handleException = new HandleException();
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入一个整数：");
		int input = scanner.nextInt();
		handleException.invokeCheck(myException, input);
		System.out.println("output:"+myException.getOutput());
		scanner.close();
	}
}