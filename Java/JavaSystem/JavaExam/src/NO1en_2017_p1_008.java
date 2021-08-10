import java.util.Scanner;

public class NO1en_2017_p1_008 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double a, b, c, d, e, f;
		double x, y;
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter a,b,c,d,e,f:");
		a = input.nextDouble();
		b = input.nextDouble();
		c = input.nextDouble();
		d = input.nextDouble();
		e = input.nextDouble();
		f = input.nextDouble();
		
		if (a*d-b*c == 0) {
			System.out.println("equation has no solution");
		} 
		else {
			x = (e*d - b*f) / (a*d - b*c);
			y = (a*f - e*c) / (a*d - b*c);
			System.out.println("x is " + x + " and y is " + y);
		}
		
		input.close();
	}

}
