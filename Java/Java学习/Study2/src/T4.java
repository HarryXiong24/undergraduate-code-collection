import java.util.Scanner;


public class T4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double result = 0;
		double temp = 0;
		Scanner input = new Scanner(System.in);
		int num = 0;
		int i = 0;
		
		System.out.printf("Please input i: ");
		num = input.nextInt();
		
		for(i = 1; i <= num; i++)
		{
			temp = Math.pow(-1, i+1) / (2*i-1);	
			result = temp + result;
		}
		input.close();
		
		System.out.printf("PI is : %f", 4 * result);
	}
	
	
}

