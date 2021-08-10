package study11;

//super的使用

public class Student extends Person {
	private String stauts;
	
	public Student(String name, String address, String phoneNumber, String email, String stauts) {
		super(name, address, phoneNumber, email);
		this.stauts = stauts;
	}

	public String getStauts() {
		return stauts;
	}

	public void setStauts(String stauts) {
		this.stauts = stauts;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Name:" + getName() + " Stauts:" + getStauts(); 
	}

}
