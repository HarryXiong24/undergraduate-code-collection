import java.util.Scanner;

interface Animal {
    public void eat(Food food);
}

abstract class Food {
    protected String name;
 
    public String getName() {
        return name;
    }

    abstract public void showName();
}

/******start******/
class Cat implements Animal{
	private String name;
	
	public Cat(String name) {
		super();
		this.name = name;
	}
	
	public String getName() {
		return name;
	}

	@Override
	public void eat(Food food) {
		// TODO Auto-generated method stub
		System.out.println("Cat " + name + " eat " + food.getName());
	}
	
}

class Fish extends Food{
	
	public Fish(String name) {
		this.name = name;
		// TODO Auto-generated constructor stub
	}

	@Override
	public void showName() {
		// TODO Auto-generated method stub
		System.out.println("Fish");
	}
	
}
/******end******/

class Master {

	public void feed(Animal an, Food f) {
		/******start******/
		an.eat(f);
		f.showName();
		/******end******/
	}
    
}

public class NO3_H_2019_xx3_p3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String catName = scanner.next();

		Master master = new Master();
		Cat cat = new Cat(catName);
		Fish fish = new Fish("fish");
        master.feed(cat, fish);

		scanner.close();
	}
}