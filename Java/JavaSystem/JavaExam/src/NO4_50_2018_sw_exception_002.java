import java.util.InputMismatchException;
import java.util.Scanner;
/**
 * 下面的Main类中的division方法是进行除法运算，在指定位置添加异常处理代码，分别捕获ArithmeticException和InputMismatchException这两种异常；
 */
public class NO4_50_2018_sw_exception_002{
	public double division(int num1,int num2){
		 //返回除法运算结果：return num1 / num2; 添加异常处理代码，处理当除数为0时抛出的获ArithmeticException对象，捕获到异常后，输出：divisor can not be zero   并且返回0；
         /******start******/
		 try {
			 if(num2 == 0)
			 {
				 throw new ArithmeticException();
			 }
		 }
		 catch(ArithmeticException e) {
			 System.out.println("divisor can not be zero");
			 return 0;
		 }
		 
		 return num1 / num2;

         /******end******/
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入被除数与除数：");
		NO4_50_2018_sw_exception_002 main = new NO4_50_2018_sw_exception_002();
		
		int dividend = 0;
		int divisor = 1;
        //获取输入的除数和被除数代码：dividend = scanner.nextInt();divisor = scanner.nextInt();
		//添加代码，捕获InputMismatchException异常，当输入不数字二是其他字符时，捕获该异常并输出：input error
		/******start******/
        try {
        	dividend = scanner.nextInt();
        	divisor = scanner.nextInt();
        }
        catch (InputMismatchException e){
        	System.out.println("input error");
        }

        /******end******/
		System.out.print("output:");
		System.out.println(main.division(dividend,divisor));
		scanner.close();
	}
}