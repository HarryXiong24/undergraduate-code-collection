
public class Person {
	private String name;
	private int age;
	private String like;
	
	public Person(String name,int age,String like)
	{
		this.name=name;
		this.age=age;
		this.like=like;
	}
	
	public void show()
	{
		System.out.println("姓名:"+this.name+"年龄:"+this.age+"爱好:"+this.like);
	}
	
	public static void main(String[] args) {
		Person person=new Person("小明",18,"弹琴");
		person.show();
	}

	
}


