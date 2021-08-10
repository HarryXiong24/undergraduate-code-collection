import java.util.Scanner;

interface Agents {
	void sell();
}


/******start******/
class Seller implements Agents{
	private String name;
	
	public Seller(String name) {
		super();
		this.name = name;
	}
	
	
	public String getName() {
		return name;
	}

	@Override
	public void sell() {
		// TODO Auto-generated method stub
		System.out.println(getName());
	}
	
}

class Customerss{
	private Seller agent;
	

	public void setAgent(Seller seller) {
		agent = seller;
	}

	public void buy()
	{
		System.out.println(agent.getName() + " seller sells.");
		System.out.println("customer buys shoes.");
	}
}
/******end******/

public class NO3_H_2019_xx1_p3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String name = scanner.next();
		
		Customerss customer=new Customerss();
		Seller seller=new Seller(name);
		
		customer.setAgent(seller);
		customer.buy();
		
		scanner.close();
	}
}