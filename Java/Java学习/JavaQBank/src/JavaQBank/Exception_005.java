package JavaQBank;

class CCircleException extends Exception{
	private static final long serialVersionUID = 1L;
}

class CCircle{
	private double radius;

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) throws CCircleException{
		if(radius < 0)
		{
			throw new CCircleException();
		}
		else
		{
			this.radius = radius;
		}
	}

	public void show()
	{
		System.out.println("area="+3.14*radius*radius);
	}
}

public class Exception_005{
	/******start******/
	public static void main(String args[]){
		CCircle cir=new CCircle();
		try{
			cir.setRadius(-2.0);
		}
		catch(CCircleException e){
			System.out.println(e+" output:throwed!!");
		}
		cir.show();
	}
}
