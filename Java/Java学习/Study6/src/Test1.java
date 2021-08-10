class Triangle extends Shape{
	private double side1;
	private double side2;
	private double side3;

	public Triangle() {
		super("T0");
		this.side1 = 1.0;
		this.side2 = 1.0;
		this.side3 = 1.0;
	}

	public Triangle(String name, double side1, double side2, double side3) {
		super(name);
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}

	public double getSide1() {
		return side1;
	}

	public double getSide2() {
		return side2;
	}

	public double getSide3() {
		return side3;
	}
	
	
	
	@Override
	public double getArea() {
		double area = 0;
		double s = 0;
		double temp = 0;
		
		s = (side1 + side2 + side3) / 2;
		temp = s * (s - side1) * (s - side2) * (s - side3);
		area = Math.sqrt(temp);
		
		return area;
	}
	
	@Override
	public double getPerimeter(){
		return side1 + side2 + side3;
	}
	
	public String toString() {
		return "Triangle " + getName() + ": side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3 +" area = " + getArea() +" perimeter = " + getPerimeter();
	}
	
}

public class Test1 {
	public static void main(String[] args) {
		Triangle ex1 = new Triangle();
		Triangle ex2 = new Triangle("T1", 2, 2, 2);
		
		System.out.println(ex1.toString());
		System.out.println(ex2.toString());
	}
}
