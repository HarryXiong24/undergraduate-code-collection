import java.util.Scanner;

public class T1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double value = 0;
		Scanner input = new Scanner(System.in);
		double rate = 0.00417;
		double money = 0;
		double temp = 0;
		int i = 0;
		
		System.out.printf("Input:\n");
		money = input.nextDouble();
		
		for(i = 0; i < 6; i++)
		{
			temp = value + money;
			value = temp * (rate + 1);
		}
		input.close();
		
		System.out.print("After the sixth month,the account value is $"+value);
	}

}
