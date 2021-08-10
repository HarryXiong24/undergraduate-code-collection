public interface AreaCalculatar {
	abstract double getArea();
}

class Circle implements AreaCalculatar {
	private double r;
	
	public Circle(double r) {
		// TODO Auto-generated constructor stub
		this.r = r;
	}
	
	getArea() {
		return 2 * Math.PI * this.r;
	}
}
