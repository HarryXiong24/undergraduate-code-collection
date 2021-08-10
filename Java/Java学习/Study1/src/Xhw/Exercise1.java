package Xhw;

public class Exercise1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double fivetotal = 0;
		
		double birth = 7.0;
		double death = 13.0;
		double immigrant = 45.0;
		
		double time = 5 * 365 * 24 * 60 * 60;
		
		double nowpeople = 312032486.0;
		double futurepeople = 0.0;
		
		fivetotal = time/birth - time/death + time/immigrant;
		futurepeople = nowpeople + fivetotal;
		
		System.out.printf("Each Five year the increasing population is: %.2f\n", fivetotal);
		System.out.printf("Now the population is: %.2f\n",nowpeople);
		System.out.printf("Five year later the population is: %.2f\n", futurepeople);
	}

}
