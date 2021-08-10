import java.util.Scanner;

interface Animals {
    public void play(Toy toy);
}

abstract class Toy {
    protected String name;
 
    public String getName() {
        return name;
    }

    abstract public void showName();
}

/******start******/
class Dog implements Animals{
	private String name;
	
	public Dog(String name) {
		super();
		this.name = name;
	}

	public String getName() {
		return name;
	}

	@Override
	public void play(Toy toy) {
		// TODO Auto-generated method stub
		System.out.println("Dog " + getName() + " play " + toy.getName());
	}
	
}

class Ball extends Toy{
	private String name;
	
	public Ball(String name) {
		super();
		this.name = name;
	}

	public String getName() {
		return name;
	}
	
	@Override
	public void showName() {
		// TODO Auto-generated method stub
		System.out.println("Ball");
	}
	
}
/******end******/
class Masters {

	public void playWith(Animals an, Toy toy) {
		/******start******/
		an.play(toy);
		toy.showName();
		
		/******end******/
	}
}

public class NO3_2019_xx4_p3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String dogName = scanner.next();

		Masters master = new Masters();
		Dog dog = new Dog(dogName);
		Ball ball = new Ball("ball");
        master.playWith(dog, ball);

		scanner.close();
	}
}