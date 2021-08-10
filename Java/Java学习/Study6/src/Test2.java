class Circle extends Shape{
	private double radius;

	public Circle() {
		super("T0");
		this.radius = 1.0;
	}

	public Circle(String name, double radius) {
		super(name);
		this.radius = radius;
	}

	public double getRadius() {
		return radius;
	}

	@Override
	public double getArea() {
		return radius * radius * Math.PI;
	}
	
	@Override
	public double getPerimeter(){
		return 2 * radius * Math.PI;
	}
	
	public String toString() {
		return "Circle " + getName() + ": radius = " + radius + " area = " + getArea() +" perimeter = " + getPerimeter();
	}	
}

class Rectangle extends Shape{
	private double width;
	private double length;

	public Rectangle() {
		super("T0");
		this.width = 1.0;
		this.length = 1.0;
	}

	public Rectangle(String name, double width, double length) {
		super(name);
		this.width = width;
		this.length = length;
	}

	public double getWidth() {
		return width;
	}

	public double getLength() {
		return length;
	}

	@Override
	public double getArea() {
		return width * length;
	}
	
	@Override
	public double getPerimeter(){
		return 2 * (width + length);
	}
	
	public String toString() {
		return "Rectangle " + getName() + ": width = " + width + " length = " + length + " area = " + getArea() +" perimeter = " + getPerimeter();
	}	
}

public class Test2 {
	public static void main(String[] args) {
		Shape ex1 = new Circle();
		Shape ex2 = new Triangle();
		Shape ex3 = new Rectangle();
		
		System.out.println(ex1.toString());
		System.out.println(ex2.toString());
		System.out.println(ex3.toString());
	}
}
