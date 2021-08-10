package Example;
//相同的进程共享对�?

public class RunnableExam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("主进程开�?");
		
		Runnableex1 ex1 = new Runnableex1();
		new Thread(ex1).start();
		new Thread(ex1).start();
		
		try {
			Thread.sleep(1000);
		}
		catch(InterruptedException e) {
			
		}
		System.out.println("主进程结�?");
	}

}
 
class Runnableex1 implements Runnable{
	int i = 10;
	int result = 1;
	
	public void cal()
	{
		System.out.println("次进程开�?");
		/*for(i = 1; i <= 10; i++)
		{
			result *= i;
		}*/
		i--;
		//System.out.println("10!=" + result);
		System.out.println("i=" + i);
		System.out.println("次进程结�?");
	}
	
	public void run()
	{
		cal();
	}
}