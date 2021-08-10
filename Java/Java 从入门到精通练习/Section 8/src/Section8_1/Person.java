package Section8_1;

public class Person {
	String name;
	String addr;
	String sex;
	int age;
	
	public Person(String name, String addr, String sex, int age) {
		this.name = name;
		this.addr = addr;
		this.sex = sex;
		this.age = age;
	}
	
	public String talk()
	{
		return this.name+" "+this.addr+" "+this.sex+" "+this.age;
	}
	
}
