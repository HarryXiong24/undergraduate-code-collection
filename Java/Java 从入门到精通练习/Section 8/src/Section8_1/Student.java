package Section8_1;
import Section8_1.Person;

public class Student extends Person
{
	double math;
	double english;
	public Student(String name, String addr, String sex, int age, double math, double english) {
		super(name, addr, sex, age);
		this.math = math;
		this.english = english;
	}

	public String talk() {                //覆写的方法类型必须一致
		return "我是：" + this.name + "，今年：" +
		        this.age + "岁, 性别：" + this.sex+ ", 家住："+
		        this.addr+ ", 数学 ： "+ this.math + ", 英语： "+ this.english;
	}
}
