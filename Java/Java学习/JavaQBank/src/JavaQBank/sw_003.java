package JavaQBank;

import java.util.Scanner;

public class sw_003
{
	public static void main(String[] args) 
	{
		System.out.println("请输入职员姓名和月薪，以逗号\",\"隔开，例如：张三,1000");
		Scanner scanner = new Scanner(System.in); 
		String input[] = scanner.nextLine().split(",");
		String name = input[0];
		double monthlyIncome = Double.parseDouble(input[1]);
		Employee zhansan = new Employee(name,monthlyIncome);
		System.out.println("请依次输入经理的姓名、月薪和奖金信息，以逗号\",\"隔开，例如：李四,2000,10000");
		input = scanner.nextLine().split(",");
		name = input[0];
		monthlyIncome = Double.parseDouble(input[1]);
		double bonus = Double.parseDouble(input[2]);
		Employee lisi = new Manager(name,monthlyIncome,bonus);
		zhansan.showInfo();
		lisi.showInfo();
	}
}

/* 定义一个Employee类表示职员；
 * 
 * 1、Employee类有两个成员变量，姓名name和月薪monthlyIncome
 * 2、Employee类有一个构造方法，实现对两个成员变量的初始化。
 * 3、Employee类有两个成员方法，calculateAnnualIncome：计算职员的年收入，实现算法为：年收入=月薪×12； showInfo方法则输出职员的姓名和年收入等信息。
 * 按下面的注释提示以及demo类中main方法提示填写代码，完善Employee类的定义
 */
 
class Employee {
	protected String name;//姓名
	protected double monthlyIncome;//月薪
	
	/* Employee类的构造方法，对两个成员变量进行初始化  */
	/******start******/
	public Employee(String name, double monthlyIncome) {
		this.name = name;
		this.monthlyIncome = monthlyIncome;
	}
	/******end******/
	
	/* 成员方法：calculateAnnualIncome，计算职员的年收入，年收入=月薪×12 */
	/******start******/
	public double calculateAnnualIncome(){
		double yearIncome = 0;
		
		yearIncome = monthlyIncome * 12;
		
		return yearIncome;
	}
	/******end******/
	
	/*成员方法：showInfo，输出职员的相关信息。 */
	public void showInfo(){
		System.out.println("output:"+name+"的年收入为："+calculateAnnualIncome());
	}
}
	
	/* 定义Manager类，表示经理。经理也是一类职员，跟一般职员比较，经理多了一个收入属性，奖金（bonus） 
	 * 所以，Manager类需要重写calculateAnnualIncome方法，计算经理的年收入的方法为:年收入=月薪×12+奖金
	 * 按这些说明，以及demo类中的代码来完成Manager类的定义。
	 * 重要提示：因为程序编译需要，请不要将Manager类的访问修饰符定义为public，而定义为default
	 */

/******start******/	
class Manager extends Employee{
	protected double bonus;
	
	public Manager(String name, double monthlyIncome, double bonus) {
		super(name, monthlyIncome);
		this.bonus = bonus;
	}
	
	@Override
	public double calculateAnnualIncome(){
		double yearIncome = 0;
		
		yearIncome = monthlyIncome * 12 + bonus;
		
		return yearIncome;
	}
	
	
	
}
/******end******/