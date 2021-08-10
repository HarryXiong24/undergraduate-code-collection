import java.util.Scanner;

public class T2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num = 0;
		Scanner input = new Scanner(System.in);
		int d1,d2,d3,d4,d5,d6,d7,d8,d9;
		int checksum = 0;
		
		System.out.printf("Enter the first 9 digits of an ISBN as integer: ");
		num = input.nextInt();
		
		d1 = num / 100000000;
		d2 = num % 100000000 / 10000000;
		d3 = num % 10000000 / 1000000;
		d4 = num % 1000000 / 100000;
		d5 = num % 100000 / 10000;
		d6 = num % 10000 / 1000;
		d7 = num % 1000 / 100;
		d8 = num % 100 / 10;
		d9 = num % 10;
		
		checksum = (d1*1 + d2*2 + d3*3 + d4*4 + d5*5 + d6*6 +d7*7 +d8*8 + d9*9) % 11;
		
		if(checksum != 10)
		{
			System.out.println("The ISBN-10 number is " + d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + checksum);
		}
		else
		{
			System.out.println("The ISBN-10 number is " + d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + "X");
		}
		input.close();
		
	}

}
//013601267
//013031997