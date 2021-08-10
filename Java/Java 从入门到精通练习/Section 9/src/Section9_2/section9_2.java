package Section9_2;

interface CircleShape{
	public double PI=3.14;
	public default double area(double r)
	{
		return PI*r*r;
	}
}

class Circle implements CircleShape{
	public double r;
	public Circle(double r) {
		this.r = r;
	}
	public double cir()
	{
		return 2*PI*r;
	}
	
}

class Cylinder implements CircleShape{
	public double r;
	public double h;
	public Cylinder(double r,double h) {
		this.r = r;
		this.h = h;
	}
	public double s()
	{
		return 2*PI*r*r+2*PI*r*h;
	}
	public double v()
	{
		return PI*r*r*h;
	}
	
}

public class section9_2 {

	public static void main(String[] args) {
		Circle a=new Circle(1);
		Cylinder b=new Cylinder(1,1);
        
		System.out.println(a.cir());
		System.out.println(b.s());
		System.out.println(b.v());
		
	}

}
