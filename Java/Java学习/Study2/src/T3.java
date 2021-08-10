
public class T3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i = 0;
		int j = 0;
		int k = 0;
		
		System.out.println("Pattern A");
		for(i = 1;i <= 6; i++)
		{
			for(j = 1; j <= i; j++)
			{
				System.out.printf("%d",j);
			}
			System.out.printf("\n");
		}
		
		System.out.println("Pattern B");
		for(i = 1;i <= 6; i++)
		{
			for(j = 1; j <= 7-i; j++)
			{
				System.out.printf("%d",j);
			}
			System.out.printf("\n");
		}
		
		System.out.println("Pattern C");
		for(i = 1;i <= 6; i++)
		{
			for(j = 1; j <= 6-i; j++)
			{
				System.out.printf(" ");
			}
			
			for(k = i; k >= 1; k--)
			{
				System.out.printf("%d",k);
			}
			System.out.printf("\n");
		}
		
		System.out.println("Pattern D");
		for(i = 1;i <= 6; i++)
		{
			for(j = 1; j <= i-1; j++)
			{
				System.out.printf(" ");
			}
			
			for(k = 1; k <= 7-i; k++)
			{
				System.out.printf("%d",k);
			}
			System.out.printf("\n");
		}
		
	}

}