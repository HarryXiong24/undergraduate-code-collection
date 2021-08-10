package Example;
//类的继承与多�?
public class area_calulation_colorsetting {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//练习类的向上转型
		figure ex[] = new figure[2];
		ex[0] = new circle(5);
		ex[1] = new rectangle(2,2);
		int i;
		
		for(i=0;i<ex.length;i++)
		{
			//问题出在这里，他说�?�The method color(String) is undefined for the type figure�?
			//因为ex里面没有color方法，向上转型是能有父类的方�?
			ex[i].color("Blue"); 
			ex[i].area();
		}	
		
		cuboid exam = new cuboid(1,2,3);
		
		exam.volume();
		exam.color();
	}

}

//图形抽象�?
abstract class figure{
	double result;
	void area()
	{
		System.out.println("The " + this.getClass().getSimpleName() + " area is:" + this.result);
	}
	abstract void color(String color);
}

//颜色设置接口
interface colorset{
	abstract void color(String color);
}

//圆形继承�?
class circle extends figure implements colorset{
	final double pi = 3.14;
	int r;
	
	circle(int r){
		this.r = r;
	}
	
	public void color(String color)
	{
		System.out.println("The " + this.getClass().getSimpleName() + " color is:" + color);
	}
	
	void area()
	{
		this.result = pi * this.r * this.r;
		super.area();
	}
}

//矩形继承�?
class rectangle extends figure implements colorset{
	int length,width;
	
	rectangle(int length,int width){
		this.length = length;
		this.width = width;
	}
	
	public void color(String color)
	{
		System.out.println("The " + this.getClass().getSimpleName() + " color is:" + color);
	}
	
	void area()
	{
		this.result = this.length * this.width;
		super.area();
	}
}

//棱柱体继承类
class cuboid extends rectangle{
	int high;
	
	cuboid(int length,int width,int high)
	{
		super(length,width);
		this.high = high;
	}
	
	public void color()
	{
		System.out.println("The " + this.getClass().getSimpleName() + " color is: white" );
		System.out.println("The " + this.getClass().getSimpleName() + " volume is:" + this.result);
		
	}
	
	void volume()
	{
		this.result = this.length * this.width * this.high;
	}
	
}
