package Circle;
import Point.point;

public class circle extends point 
{
 
	double r;
    double res;
	
	public circle(double r,double x,double y)
	{
		super(x,y);
		this.r=r;
	}
	
	public double print()
	{
		res=3.14*this.r*this.r;
		return res;
	}
	
}
