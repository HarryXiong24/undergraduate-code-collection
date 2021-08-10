package study3_1;


class MyInteger{
	private Integer value ;
	
	MyInteger(int value)
	{
		this.value = value;
	}

	public Integer getValue() {
		return this.value;
	}
	
	public boolean isEven()
	{
		if(this.value % 2 == 0)
		{
			return true;
		}
		return false;
	}
	
	public boolean isOdd()
	{
		if(this.value % 2 == 1)
		{
			return true;
		}
		return false;
	}
	
	public boolean isPrime()
	{
		int i = 2;
		
		do
		{
			if(this.value % i == 0)
			{
				return false;
			}
			i++;
		}while(i < this.value);
		
		return true;
	}
	
	public static boolean isEven(int value)
	{
		if(value % 2 == 0)
		{
			return true;
		}
		return false;
	}
	
	public static boolean isOdd(int value)
	{
		if(value % 2 == 1)
		{
			return true;
		}
		return false;
	}
	
	public static boolean isPrime(int value)
	{
		int i = 2;
		
		do
		{
			if(value % i == 0)
			{
				return false;
			}
			i++;
		}while(i < value);
		
		return true;
	}
	
	
}


public class Demo1 {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
