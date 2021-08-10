package test3;

import java.lang.Math;

public class T4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = new int[100];
		int[] count = new int[10];
		int i = 0;
		
		for(i = 0; i < 100; i++)
		{
			arr[i] = (int)(Math.random() * 10);
			if( arr[i] == 0)
			{
				count[0]++;
			}
			if( arr[i] == 1)
			{
				count[1]++;
			}
			if( arr[i] == 2)
			{
				count[2]++;
			}
			if( arr[i] == 3)
			{
				count[3]++;
			}
			if( arr[i] == 4)
			{
				count[4]++;
			}
			if( arr[i] == 5)
			{
				count[5]++;
			}
			if( arr[i] == 6)
			{
				count[6]++;
			}
			if( arr[i] == 7)
			{
				count[7]++;
			}
			if( arr[i] == 8)
			{
				count[8]++;
			}
			if( arr[i] == 9)
			{
				count[9]++;
			}
		}
		
		for(i = 0; i < 10; i++)
		{
			System.out.printf("%d ", count[i]);
		}
	}

}
