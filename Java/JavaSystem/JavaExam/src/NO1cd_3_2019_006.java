import java.util.Scanner;
public class NO1cd_3_2019_006 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a = 0, b = 0, c = 0, d = 0;
		int number;
		Scanner input = new Scanner(System.in);
		
		do {
			number = input.nextInt();
		} while (number < 1000 || number > 9999);
		//有规律，取最低位mod10，之后不断除10砍掉最后一位，再一次mod10
		d = number % 10;
		c = number/10%10;
		b = number/100%10;
		a = number/1000%10;
		
		a = (a+5)%10;
		b = (b+5)%10;
		c = (c+5)%10;
		d = (d+5)%10;
		
		System.out.println("" + d + c + b + a);
		input.close();
	}
}
