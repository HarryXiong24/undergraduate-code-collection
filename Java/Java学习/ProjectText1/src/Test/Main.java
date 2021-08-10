package Test;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Please input a decimal num:");
		
		Scanner input = new Scanner(System.in);
		int value = input.nextInt();
		input.close();
		String result = DecimalToBinary.decimalToBinary(value);
		
		System.out.println("The binary num is:" + result);
	}

}
