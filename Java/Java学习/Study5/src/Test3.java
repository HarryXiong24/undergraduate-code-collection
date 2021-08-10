import java.util.Date;

class Account{
	private int id;
	private double balance;
	private double annualInterestRate;
	private Date ateCreated;
	
	public Account() {
		this.id = 0;
		this.balance = 0;
		this.annualInterestRate = 0;
		this.ateCreated = new Date();
	}

	public Account(int id, double balance) {
		this.id = id;
		this.balance = balance;
		this.annualInterestRate = 0;
		this.ateCreated = new Date();
	}

	public void setId(int id) {
		this.id = id;
	}

	public void setBalance(double balance) {
		this.balance = balance;
	}

	public void setAnnualInterestRate(double annualInterestRate) {
		this.annualInterestRate = annualInterestRate / 100.0;
	}

	public int getId() {
		return id;
	}

	public double getBalance() {
		return balance;
	}

	public double getAnnualInterestRate() {
		return annualInterestRate;
	}

	public Date getAteCreated() {
		return ateCreated;
	}

	public double getMonthlyInterestRate() {
		return annualInterestRate / 12;
	}
	
	public double getMonthlyInterest() {
		return balance * annualInterestRate / 12;
	}
	
	public void withdraw(double amount) {
		balance = balance - amount;
	}
	
	public void deposit(double amount) {
		balance = balance + amount;
	}
	
}

public class Test3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Account ex1 = new Account(1122, 20000);
		ex1.setAnnualInterestRate(4.5);
		ex1.withdraw(2500);
		ex1.deposit(3000);
		System.out.println("Balance:" + ex1.getBalance());
		System.out.println("Monthly interest:" + ex1.getMonthlyInterest());
		System.out.println(ex1.getAteCreated());
		
	}

}
