import java.util.Scanner;

//求出任意数字的各个位数之和
public class NO1en_2017_p1_006 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		System.out.println("Enter a positive number:");
		int num = input.nextInt();
		int sum = 0;
		while(num!=0){
			sum = sum + num%10;
			num = num/10;
		}
		System.out.println("The sum of the digits is "+sum);
	}
}
