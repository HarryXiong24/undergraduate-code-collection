interface Colorable{
	public abstract void howToColor();
}

class Square extends Shape implements Colorable{
	private double side;

	public Square() {
		super("T0");
		this.side = 1.0;
	}

	public Square(String name, double side) {
		super(name);
		this.side = side;
	}

	public double getSide() {
		return side;
	}
	
	@Override
	public double getArea() {
		return side * side;
	}
	
	@Override
	public double getPerimeter(){
		return 4 * side;
	}
	
	public String toString() {
		return "Square " + getName() + ": side = " + side + " area = " + getArea() +" perimeter = " + getPerimeter();
	}	

	@Override
	public void howToColor() {
		// TODO Auto-generated method stub
		System.out.println("Color all four sides to paint blue.  The blue is the color");
	}
	
}
public class Test4 {
	Square ex1 = new Square();
	
}
