package Example;

class Complex
{
	int realPart;
	int imagePart;
	
	Complex()
	{
		this.realPart = 0;
		this.imagePart = 0;
	}
	Complex(int r, int i)
	{
		this.realPart = r;
		this.imagePart = i;
	}
	
	void addComplex(Complex ex)
	{
		realPart = realPart + ex.realPart;
		imagePart = imagePart + ex.imagePart;
	}
	
}

public class Complex_Cal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Complex ex1 = new Complex(2, 1);
		Complex ex2 = new Complex(1, 2);
		
		System.out.println("ex1=" + ex1.realPart + "+" + ex1.imagePart + "i");
		System.out.println("ex2=" + ex2.realPart + "+" + ex2.imagePart + "i");
		
		ex1.addComplex(ex2);
		
		System.out.println("ex1+ex2=" + ex1.realPart + "+" + ex1.imagePart + "i");
	}

}
