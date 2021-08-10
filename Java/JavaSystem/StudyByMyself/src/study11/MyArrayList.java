package study11;

import java.util.ArrayList;

public class MyArrayList {
	public static void main(String[] args) {
		ArrayList<Integer> ex1 = new ArrayList<Integer>();
		int i = 0;
		
		for(i = 0; i < 10; i++)
		{
			ex1.add(i + 1);
		}
		
		//toArray()的两种用法,只能用于引用类型数组的转换
		//Object[] a = ex1.toArray();
		Integer[] a = ex1.toArray(new Integer[ex1.size()]);
		
		for(int b : a)
		{
			System.out.println(b);
			System.out.println(Integer.toString(b));
		}
	}
}
