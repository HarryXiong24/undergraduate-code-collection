package main;

import java.util.Scanner;
/******start******/
class Rectangle
{
	private double width;
	private double height;
	
	public Rectangle()
	{
		this.width = 10.0;
		this.height = 10.0;
	}
	
	public Rectangle(double x, double y)
	{
		this.width = x;
		this.height = y;
	}
	
	public double getArea()
	{
		return width * height;
	}
	
	
	public double getPerimeter()
	{
		return 2 * (width + height);
	}
}

/******end******/
public class Main {
	public static void main(String[] args) {
		Rectangle defaultRectangle = new Rectangle();
		System.out.println("Default Rectangle's Area is: "+defaultRectangle.getArea());
		Scanner scanner = new Scanner(System.in);
		System.out.println("please input width and height：");
		double width = scanner.nextDouble();
		double height = scanner.nextDouble();
		System.out.print("The rectangle's perimeter is: ");
		//instantiate a rectangle object use the input width and height,and print the perimeters of this rectangle;
        //在下面编写代码实现：实例化一个矩形对象，其长和宽为前面输入的值，并输出该矩形的周长值
        /******start******/
		Rectangle Rectangle = new Rectangle(width, height);
		double perimeter = Rectangle.getPerimeter();
		System.out.print(perimeter);
		
		scanner.close();
		/******end******/
		
	}

}