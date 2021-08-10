package JavaQBank;

public class Java_006 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i = 1;
		int j = 0;
		double result = 0;
		
		for(i = 1; i <= 100; i++)
		{
			result = Math.pow(-1, j) * 1/i + result;
			j++;
		}
		System.out.print("output:1-1/2+1/3-1/4+…+1/99-1/100="+result);
	}

}
