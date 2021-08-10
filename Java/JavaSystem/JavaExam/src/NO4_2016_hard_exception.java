import java.util.Scanner;

class validator{
	public static int checkInput(int input) throws Exception{
		if (input < 0) {
			throw new Exception("输入有误，输入必须大于等于0");
		}else {
			return input;
		}
	}
}

class person{
	String name;
	int age;
	public person(String name) {
		this.name = name;
	}
	public void setAge(int age) throws Exception{
		this.age = validator.checkInput(age);
	}
	public void modifyAge(int age){
		try {
			this.age = validator.checkInput(age);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
	}
	public void print(){
		System.out.println("name:"+name+",age:"+age);
	}
}

public class NO4_2016_hard_exception {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String name = scanner.next();
		int age = Integer.parseInt(scanner.next());
		System.out.println("output:");
		person person = new person(name);
		try {
			person.setAge(age);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
		person.print();
		person.modifyAge(age+2);
		person.print();
	}

}