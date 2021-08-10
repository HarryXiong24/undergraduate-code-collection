package JavaQBank;

import java.util.Scanner;

/* 定义DemoPerson,该类有属性name，带参的构造方法初始化name成员变量，有speak方法，
 * 输出字符串：“my name is:xxxx”,xxxx为键盘录入的姓名（即name值）；
 * 
 * 定义类DemoStudent，该类是DemoPerson的子类，有自己的成员变量number（学号），
 * 其构造方法需要2个字符串作为参数，用以初始化name及学号，DemoStudent类覆盖了父类的speak方法；
 * 且新增另一个speak方法，该方法需要一个字符串作为参数，该方法的功能是直接输出参数的值； 
 */

/******start******/
class DemoPerson{
	private String name;

	public DemoPerson(String name) {
		this.name = name;
	}
	
	public void speak()
	{
		System.out.println("my name is:" + name);
	}
}

class DemoStudent extends DemoPerson{
		// TODO Auto-generated constructor stub
	private String number;

	public DemoStudent(String name, String number) {
		super(name);
		this.number = number;
	}
	
	
	public String getNumber() {
		return number;
	}


	public void setNumber(String number) {
		this.number = number;
	}

	public void speak(String s)
	{
		System.out.println(s);
	}
}
/******end******/

public class hlb_001{
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner san = new Scanner(System.in);
		String name = san.next();
		String number = san.next();
		DemoPerson stu = new DemoStudent(name,number);
		stu.speak();
		DemoStudent substu = (DemoStudent)stu;
		String msg = substu.getNumber();
		substu.speak(msg);
	}
}