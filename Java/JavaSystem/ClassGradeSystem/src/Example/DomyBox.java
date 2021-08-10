package Example;

class myBox{
	double length,width;
	
	myBox(double length,double width)
	{
		this.length=length;
		this.width=width;
	}
	
	double S()
	{
		double squre=0;
		
		squre = this.length * this.width;
		
		return squre;
	}
	
	double C()
	{
		double cir;
		
		cir = 2 * (this.length+this.width);
		
		return cir;
	}
	
	void change(double length,double width)
	{
		this.length=length;
		this.width=width;
	}
}

public class DomyBox {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		myBox ex1 = new myBox(2, 3);
		
		System.out.println("该矩形面积为:" + ex1.S());
		System.out.println("该矩形周长为:" + ex1.C());
		
		ex1.change(5, 5);
		
		System.out.println("该矩形面积为:" + ex1.S());
		System.out.println("该矩形周长为:" + ex1.C());
		
	}

}
