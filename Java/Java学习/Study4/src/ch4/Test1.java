package ch4;

class Rectangle
{
	public double width = 1.0;
	public double height = 1.0;
	
	public Rectangle() {
		
	}

	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
	}
	
	public double getArea()
	{
		double result;
		
		result = width * height;
		
		return result; 
	}
	
	public double getPerimeter()
	{
		double result;
		
		result = (width + height) * 2;
		
		return result; 
	}
	
	
}


public class Test1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Rectangle ex1 = new Rectangle(4, 40);
		Rectangle ex2 = new Rectangle(3.5, 35.9);
		
		System.out.printf("The 1st rectangle's width:%.1f,height:%.1f,area:%.1f,perimeter:%.1f\n", ex1.width, ex1.height, ex1.getArea(), ex1.getPerimeter());
		System.out.printf("The 2st rectangle's width:%.1f,height:%.1f,area:%.1f,perimeter:%.1f", ex2.width, ex2.height, ex2.getArea(), ex2.getPerimeter());
		
	}

}
