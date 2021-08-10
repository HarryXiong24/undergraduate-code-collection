package study3_1;

class MyPoint{
	private int x;
	private int y;
	public static double PI = 3.14;
	
	public MyPoint()
	{
		this.x = 0;
		this.y = 0;
	}
	
	public MyPoint(int x,int y)
	{
		this.x = x;
		this.y = y;
	}
	
	public int getX() 
	{
		return x;
	}
	
	public int getY() 
	{
		return y;
	}
	
	public double distance(MyPoint external)
	{
		double dis = 0;
		
		dis = Math.sqrt(Math.pow(this.x - external.x, 2) + Math.pow(this.y - external.y, 2));
		return dis;
	}
	
	public double distance(int x, int y)
	{
		double dis = 0;
		
		dis = Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
		return dis;
	}
	
	public static double getPI()   //static里调用非静态的方法或属性,都要先实例化对象才能调用
	{
		return PI;
	}
	
	
}

public class Demo2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyPoint ex1 = new MyPoint();
		MyPoint ex2 = new MyPoint(3,4);
		double len1 = 0;
		double len2 = 0;
		double PI = 0;
		
		len1 = ex1.distance(ex2);
		len2 = ex1.distance(3, 4);
		System.out.println(len1);
		System.out.println(len2);
		System.out.println(MyPoint.PI);
		
		PI = MyPoint.getPI();
		System.out.println(PI);              
	}

}

