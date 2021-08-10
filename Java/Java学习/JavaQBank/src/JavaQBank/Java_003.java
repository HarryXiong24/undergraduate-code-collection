package JavaQBank;

public class Java_003 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i = 1;
		int j = 1;
		
		for(i = 1; i < 9; i++)
		{
			for(j = 1; j <= i; j++)
			{
				System.out.printf("%dX%d=%d\t", i, j, j * i);
			}
			System.out.printf("\n");
		}
	}

}
