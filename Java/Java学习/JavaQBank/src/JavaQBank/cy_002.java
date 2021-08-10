package JavaQBank;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Owner
{
	private String name;
	private Dog dog;
	public Dog getDog()
	{
		return dog;
	}
	public void setDog(Dog dog)
	{
		this.dog = dog;
	}
	public Owner(String name )
	{
		this.name=name;
	}
	public String getName()
	{
		return name;
	}
}

class Dog 
{
	String name;
	Owner owner;
	public Dog(String name )
	{
		this.name=name;
	}
	public Owner getOwner()
	{
		return owner;
	}
	/*
	*按注释要求完成代码填写
	1.设置狗狗的主人
	2.如果狗狗原先就有主人
	3.那么取消和原先主人的关联关系
	4.建立狗和新的主人的关联关系
	5.建立新的主人和狗的关联关系
	*/
	
	/******start******/
	public void setOwner(Owner owner)
	{
		if(this.owner != null)
		{
			this.owner.setDog(null);
		}
		this.owner = owner;
		owner.setDog(this);
	}
	/******end******/
}

public class cy_002
{
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
	public static void main(String args[])
	{
		String str1 = input();
		String str[]= new String[3];
		if(str1.contains(","))
		{
			str = str1.split(",");
			Owner owner1 =new Owner(str[0]);
			Owner owner2=new Owner(str[1]);
			Dog dog= new Dog(str[2]);
			dog.setOwner(owner1);
			System.out.println("output:");
			System.out.println("狗狗"+dog.name+"的主人是:"+dog.owner.getName());
			dog.setOwner(owner2);
			System.out.println("狗狗"+dog.name+"的主人是:"+dog.owner.getName());
		}else
		{
			System.out.println("输入请用逗号隔开！");
		}
	}
}