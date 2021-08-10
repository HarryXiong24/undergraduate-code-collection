abstract class NewShape {
	private String name;
	
	public NewShape(String name) {
		this.name = name;
	}
	
	public abstract double getArea();
	
	public abstract double getPerimeter();
	
    public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}

}
public class Test3 {

}
