package JavaQBank;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Emplee 
{
	/*1.编写一个员工类，封装姓名、年龄、学历等属性*/
	/******start******/
	private String name;
	private String age;
	private String education;
	
	public String getName() 
	{
		return name;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public String getAge() 
	{
		return age;
	}
	
	public void setAge(String age) 
	{
		this.age = age;
	}
	
	public String getEducation() 
	{
		return education;
	}
	
	public void setEducation(String education) 
	{
		this.education = education;
	}
	/******end******/
}

public class cy_005
{
	public static void main(String args[])
	{
		String str1 = input();
		String a[]= new String[3];
		if(str1.contains(","))
		{
			a = str1.split(",");
			String name = a[0];
			String age = a[1];
			String education = a[2];
			Emplee e = new Emplee();
			e.setName(name);
			e.setAge(age);
			e.setEducation(education);
			System.out.println("output:");
			System.out.println("员工姓名："+e.getName());
			System.out.println("员工年龄："+e.getAge());
			System.out.println("员工学历："+e.getEducation());
		}
		else
		{
			System.out.println("输入请用逗号隔开！");
		}
	}
	public static String input()
	{
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String a=br.readLine();
			return a;
		}
		catch(Exception e)
		{
			return null;
		}
	}
}