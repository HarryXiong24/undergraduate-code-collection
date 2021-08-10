import java.util.*;

public class Test2 {
	public static void main(String[] args) {
		GregorianCalendar ex1 = new GregorianCalendar();
		System.out.printf("%d ", ex1.get(GregorianCalendar.YEAR));
		System.out.printf("%d ", ex1.get(GregorianCalendar.MONTH));
		System.out.printf("%d ", ex1.get(GregorianCalendar.DAY_OF_MONTH));
		
		System.out.printf("\n");
		ex1.setTimeInMillis(1234567898765L);
		System.out.printf("%d ", ex1.get(GregorianCalendar.YEAR));
		System.out.printf("%d ", ex1.get(GregorianCalendar.MONTH));
		System.out.printf("%d ", ex1.get(GregorianCalendar.DAY_OF_MONTH));
		
	}
}
