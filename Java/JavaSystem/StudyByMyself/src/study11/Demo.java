package study11;

//this的使用

class Circle
{
	public int r;
	public int x;
	public int y;
	public String color;
	
	public Circle(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public Circle(int r, int x, int y) {
		this.r = r;
		this.x = x;
		this.y = y;
	}
	
	public Circle(int r, int x, int y, String color) {
		this(x, y);                //写多少参数调用那个参数的构造方法
		this.color = color;
	}
	
	public String info()
	{
		return "x:" + x + " y:" + y + " r:" + r + " color:" + color;
	}
	
}

public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle ex1 = new Circle(1, 1, 1, "blue");
		
		System.out.println(ex1.info());
	}

}
