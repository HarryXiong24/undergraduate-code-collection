package JavaQBank;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class doll 
{
	/* 1.申明成员变量number,id和 name，其中id表示玩具的序号，name表示玩具的名字\n * 
	2.编写构造函数 ，在构造函数中为成员变量name,id赋值，\n * 
	3.其中name的值通过为构造函数传参数赋值。\n * 
	4.id代表玩具的序号，每个玩具的序号自增且必须唯一。\n * 
	提示：可以让number完成序号的自增，再赋值给id，以确保序号唯一。\n *\n*/
	/******start******/
	private static int number = 0;
	private int id;
	private String name;
	
	public doll(String name)
	{
		this.name = name;
		this.id = number;
		number++;
	}
	
	/******end******/
	public void speak(String word)
	{
		String showNumber="目前共有"+number+"个娃娃！";
		String showId="我的ID是"+id;
		System.out.println(name+":"+showNumber);
		System.out.println(name+":"+showId);
		System.out.println(name+":"+word);
	}
	public static String input()
	{
		try
		{
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
public class cy_001
{
	public static void main(String args[])
	{
		String str1 = doll.input();
		String str[]= new String[2];
		if(str1.contains(","))
		{
			str = str1.split(",");
			doll doll1 = new doll(str[0]);
			doll doll2 = new doll(str[1]);
			System.out.println("output:");
			doll1.speak("hello!");
			doll2.speak("hello!");
		}
		else
		{
			System.out.println("输入请用逗号隔开！");
		}
	}
}