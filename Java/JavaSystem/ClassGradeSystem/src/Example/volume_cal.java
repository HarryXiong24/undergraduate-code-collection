package Example;
//类的组合

public class volume_cal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		area ex = new area();
		ex.result();
		System.out.print(ex.area_res);
	}

}

class length {
	int length;
	length(int x)
	{
		this.length = x;
	}
}

class width {
	int width;
	width(int x)
	{
		this.width = x;
	}
}

class high{
	int high;
	high(int x)
	{
		this.high = x;
	}
}

class area{
	length l = new length(3);
	width w = new width(3);
	int area_res;
	
	int result()
	{
		area_res = l.length * w.width;
		
		return area_res;
	}
	
}
