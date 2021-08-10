interface AreaCalculatar {
	abstract double getArea();
}

class Circle implements AreaCalculatar {
	private double r;
	
	public Circle(double r) {
		// TODO Auto-generated constructor stub
		this.r = r;
	}
	
	public double getArea() {
		return Math.PI * this.r * this.r;
	}
}

public class temp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle circle = new Circle(4.5);
		System.out.println(circle.getArea());
	}

}
