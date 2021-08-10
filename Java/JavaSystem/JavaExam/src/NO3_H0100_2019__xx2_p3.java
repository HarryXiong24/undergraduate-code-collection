import java.util.Scanner;

interface Agent {
	void employ();
}

/******start******/
class Employees{
	Agent agent;
	
	public void setAgent(Agent agent) {
		this.agent = agent;
	}


	public void findJob() {
		agent.employ();
		System.out.println("employee is hired.");
	}
	
}

class Employer implements Agent{
	String name;
	
	public Employer(String name) {
		super();
		this.name = name;
	}

	@Override
	public void employ() {
		// TODO Auto-generated method stub
		System.out.println( name + " employer employs.");
	}
	
}
/******end******/
public class NO3_H0100_2019__xx2_p3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String name = scanner.next();
		
		Employees employee=new Employees();
		Employer employer=new Employer(name);
		
		employee.setAgent(employer);
		employee.findJob();
		
		scanner.close();
	}
}