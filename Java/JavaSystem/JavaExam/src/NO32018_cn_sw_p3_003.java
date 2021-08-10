import java.util.Scanner;
class Customer {
         //客户编号id
	private String id;
	public Customer(String id) {
		super();
		this.id = id;
	}
	public String getId() {
		return id;
	}
      //计算客户本次消费需要实际支出的费用，对于普通客户，消费金额就是客户实际需要支出的金额
	public double payAmount(double consumptionAmount){
		return consumptionAmount;
	}
	
}
/******start******/
class DiscountCustomer extends Customer{
	private double discount;

	public DiscountCustomer(String id, double discount) {
		super(id);
		this.discount = discount;
	}

	@Override
	public double payAmount(double consumptionAmount) {
		// TODO Auto-generated method stub
		double output = 0;
		output = consumptionAmount * discount;
		return output;
	}
	
}
/******end******/
public class NO32018_cn_sw_p3_003{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入折扣客户编号，折扣系数及本次消费金额：");
		String id = scanner.next();
		double discount = scanner.nextDouble();
		double consumption = scanner.nextDouble();
		Customer customer = new DiscountCustomer(id, discount);
		System.out.println("output:");
		System.out.println("折扣客户："+customer.getId()+"本次消费了"+consumption+"元，实际支付"+customer.payAmount(consumption)+"元");
		scanner.close();
	}
}