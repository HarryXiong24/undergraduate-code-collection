import java.util.Scanner;
class  Client{
	private String id;
	private double discount;
	public Client(String id, double discount) {
		this.id = id;
		this.discount = discount;
	}
	public double getDiscount() {
		return discount;
	}
	public void setDiscount(double discount) {
		this.discount = discount;
	}
	public String getId() {
		return id;
	}
	public double checkout(double subtotal){
		double pay = subtotal * discount;
		return pay;
	}
}
/******start******/
class VIPClient extends Client{
	private double bonusPoints;

	public VIPClient(String id, double discount, double bonusPoints) {
		super(id, discount);
		this.bonusPoints = bonusPoints;
	}

	public double getBonusPoints() {
		return bonusPoints;
	}

	@Override
	public double checkout(double subtotal) {
		// TODO Auto-generated method stub
		double pay = 0;
		if(bonusPoints >= subtotal * getDiscount())
		{
			bonusPoints = bonusPoints - subtotal * getDiscount();
			return pay;
		}
		else
		{
			pay = subtotal * getDiscount() - bonusPoints;
			bonusPoints = pay / 100;
			return pay;
		}
	}	
}
/******end******/
public class NO3_50_2017_en_sw_p3_f004 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please Enter Client ID, Discount and initial BonusPoint");
		String id = scanner.next();
		double discount = scanner.nextDouble();
		double bonusPoints = scanner.nextDouble();
		VIPClient vip = new VIPClient(id,discount,bonusPoints);
		System.out.println(vip instanceof Client);
		System.out.println("The client is "+vip.getId()+". The sum of consumption is: 2000, and he actually pays "+vip.checkout(2000)+", and the number of the remaining bonus points are "+vip.getBonusPoints());
		System.out.println("The client is "+vip.getId()+". The sum of consumption is: 200, and he actually pays "+vip.checkout(200)+", and the number of the remaining bonus points are "+vip.getBonusPoints());
		scanner.close();
	}
}