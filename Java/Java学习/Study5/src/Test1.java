import java.util.Random;

public class Test1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer[] ex = new Integer[100];
		
		for(int i = 0; i < 100; i++)
		{
			ex[i] = new Random().nextInt(200);
		}
				
		for(int i = 0; i < 100; i++)
		{
			System.out.printf("%-4d ", ex[i]);
			if((i+1) % 10 == 0)
			{
				System.out.println("");
			}
		}
	}
}
