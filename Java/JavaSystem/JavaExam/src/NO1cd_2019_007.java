
public class NO1cd_2019_007 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int numerator = 2;
		int donominator = 1;
		double sum = 2;
		int i = 1;
		
		do
		{
			int temp = donominator;
			donominator = numerator;
			numerator = numerator + temp;
			sum = sum + (double)numerator/donominator;
			i++;
		}while(i <= 19);
		
		System.out.printf("%.2f\n", sum);
		
	}
}

/*
public class Main {
	public static void main(String[] args) {
		int x = 2, y = 1, t;
		double sum = 0;
		for (int i = 1; i <= 20; i++) {
			sum = sum + (double) x / y;
			t = y;
			y = x;
			x = y + t;
		}
		System.out.printf("%.2f",sum);
	}
}*/
