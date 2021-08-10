package Example;

public class ThreadExam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Threadex1 a = new Threadex1();
		
		System.out.println("主进程开�?");
		a.start();
		try {
			Thread.sleep(1000);
		}
		catch(InterruptedException e) {
			
		}
		System.out.println("主进程结�?");
		
	}

}


class Threadex1 extends Thread{
	int i = 0;
	int result = 1;
	
	public void cal()
	{
		System.out.println("次进程开�?");
		for(i = 1; i <= 10; i++)
		{
			result *= i;
		}
		System.out.println("10!=" + result);
		System.out.println("次进程结�?");
	}
	
	public void run()
	{
		cal();
	}
}
