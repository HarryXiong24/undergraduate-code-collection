package Xhw;
import java.util.*;

public class Exercise2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int number;
		int a = 0, b = 0, c = 0;
		int sum = 0;
		int flag = 1;
		
		do{
			System.out.printf("Please enter a number between 0 and 1000: ");
			number = input.nextInt();
			
			if(number <= 0 || number >= 1000)
			{
				System.out.printf("Overflow!\n");
			}
			else 
			{
				a = number / 100;
				b = number / 10 % 10;
				c = number % 100 % 10;
				
				sum = a + b + c;
				
				System.out.printf("The sum of the digits is %d.\n", sum);
			}
			
			System.out.printf("Weather exit? Yes 1, NO 0: \n");
			flag = input.nextInt();
			
		}while(flag == 0);
		
		System.out.println("Thank you for using!\n");
		input.close();
		
	}

}
