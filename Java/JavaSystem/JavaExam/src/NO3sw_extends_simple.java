import java.util.Scanner;

class employee{
	private String name;
	public employee(String name) {
		super();
		this.name = name;
	
	}
	public String getName() {
		return name;
	}
	public String work(){
		return "一般工作";
	}
        
	
}
/******start******/
class manager extends employee{
	private String duty;
	
	public manager(String name, String duty) {
		super(name);
		this.duty = duty;
		// TODO Auto-generated constructor stub
	}

	public String getDuty() {
		return duty;
	}

	public void setDuty(String duty) {
		this.duty = duty;
	}

	@Override
	public String work() {
		// TODO Auto-generated method stub
		return "经理" + getName() + "的主要职责是：" + duty;
	}
	
	
}

/******end******/
public class NO3sw_extends_simple{
	public static void main(String[] args) {
		System.out.println("请输入经理的姓名和职责，以空格分开");
		Scanner san = new Scanner(System.in);
		String name = san.next();
		String duty = san.next();
		employee manager  = new manager(name,duty);
		System.out.println("output:"+manager.work());
	}
}
