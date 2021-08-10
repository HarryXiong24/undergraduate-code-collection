package Example;

public class Vector_Cal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector ex1 = new Vector(1, 1);
		Vector ex2 = new Vector(3, 4);
		
		System.out.print("向量ex1�?:");
		ex1.show();
		System.out.print("向量ex2�?:");
		ex2.show();
		
		System.out.print("相加�?:");
		ex1.add(ex2);
		
		System.out.print("相减�?:");
		ex1.minus(ex2);
		
		System.out.print("内积�?:"+ ex1.inner_product(ex2));

	}

}

class Vector{
	int a,b;
	Vector(int a, int b)
	{
		this.a = a;
		this.b = b;
	}
	
	void show()
	{
		System.out.println("(" + this.a + "," + this.b + ")");
	}
	
	void add(Vector ex)
	{
		int a=0,b=0;
		
		a = this.a + ex.a;
		b = this.b + ex.b;
		
		System.out.println("(" + a + "," + b + ")");
	}
	
	void minus(Vector ex)
	{
		int a=0,b=0;
		
		a = this.a - ex.a;
		b = this.b - ex.b;
		
		System.out.println("(" + a + "," + b + ")");
	}
	
	int inner_product(Vector ex)
	{
		int result;
		
		result = this.a * ex.a + this.b * ex.b;
		
		return result;
	}
}
