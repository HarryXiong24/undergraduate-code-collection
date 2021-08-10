package Example;

//构�?�方法只有方法名
//Java可以定义很多个构造方法，通过构�?�方法里的参数个数来判断选择哪个构�?�方�?
//当成员变量和�?部变量重名时，在方法中使用this时，表示的是该方法所在类中的成员变量�?
//this关键字在�?个构造方法中调用另外的构造方�?


class Pointcalss {
	int x,y;
	Pointcalss()
	{
		this.x=1;
		this.y=1;
	}
	Pointcalss(int x,int y)
	{
		this.x=x;
		this.y=y;
	}
	void show()
	{
		System.out.println("�?(x,y)�?"+"("+this.x+","+this.y+")");
	}
}

public class Point{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Pointcalss p1=new Pointcalss();
		Pointcalss p2=new Pointcalss(2,2);
		p1.show();
		p2.show();
		
	//	System.out.print(p1.getClass().getPackageName());
	}

}




