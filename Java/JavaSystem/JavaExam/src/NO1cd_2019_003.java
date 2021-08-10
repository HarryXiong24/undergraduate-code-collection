public class NO1cd_2019_003 {
	//求10000以下的完全数。
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int temp;
		int sum;
		
		for(int i = 1; i <= 10000; i++)
		{
			sum = 0;
			temp = 1;
			while(temp < i)
			{
				if(i % temp == 0)
				{
					sum = sum + temp;
				}
				temp++;
			}
			if(sum == i)
			{
				System.out.println(i);
			}
		}	
	}
}
