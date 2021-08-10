package JavaQBank;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class sw_005
{
	public static void main(String[] args) 
	{
		List<Double> inputs = new ArrayList<Double>();
		//从控制台输入数据，一次性依次输入矩形的长、宽和圆形的半径三个数据。最后以exit结束。
		System.out.println("请依次序输入矩形的长、宽和圆形的半径这三个数据，数据之间用空格隔开,结尾标记为exit，比如输入：10 20 5 exit，将会得到输出结果：此图形的周长是：60.0,面积是：200.0");
		Scanner scanner = new Scanner(System.in); 
		while (scanner.hasNextDouble())
		{
			double input = scanner.nextDouble();
			inputs.add(input);
		}
		//实例化Rectangle类的实例对象
		Shape rectangle = new Rectangle(inputs.get(0), inputs.get(1));
		System.out.println("矩形的周长和面积分别是：");
		System.out.print("output:");
		System.out.println(rectangle.getPerimeter()+"和"+rectangle.getArea());
		//实例化Circle类的实例对象
		Shape circle = new Circle(inputs.get(2));
		System.out.println("圆形的周长和面积分别是：");
		System.out.print("output:");
		System.out.print(circle.getPerimeter()+"和"+circle.getArea());
		//输出矩形和圆形的周长与面积值
	}
}

interface  Shape
{
	/*** 计算图形的周长 
	@return 周长值*/
	public abstract double getPerimeter();
	/*** 计算图形的面积
	@return 面积值*/
	public abstract double getArea();
}
	/*** 定义类Rectangle表示矩形，实现Shape接口。
	Rectangle类必须具有长（length）和宽（width）两个属性，定义为double类型；
	Rectangle类提供计算周长和面积的方法实现。
	
	Rectangle类的访问修饰符定义为default\n */
	/******start******/
class Rectangle implements Shape
{
	private double length;
	private double width;
	
	public Rectangle(double length, double width) {
		this.length = length;
		this.width = width;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * (length + width);
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return length * width;
	}

}
	/******end******/
	
	/**** 定义类Circle类表示圆形，Circle类实现Shape接口。
	Circle类必须具有半径（radius）的属性，定义为double类型；
	Circle类提供计算周长和面积的方法实现。
	Circle类的访问修饰符定义为default\n */

	/******start******/
class Circle implements Shape{
	private double radius;

	public Circle(double radius) {
		this.radius = radius;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * Math.PI * radius;
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return Math.PI * radius * radius;
	}
	
}
	/******end******/