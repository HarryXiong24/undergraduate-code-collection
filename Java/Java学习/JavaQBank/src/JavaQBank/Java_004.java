package JavaQBank;

public class Java_004 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("output:please num");
		int number = 100;
		int i, j, k;
		for (int sum; number<1000; number++)
		{
			i=number/100; 
			j=(number-i*100)/10; 
			k=number-i*100-j*10;
			sum=i*i*i+j*j*j+k*k*k;
			if (sum==number) 
				System.out.println(number+" is a dafodil number! ");
		}
	}

}
