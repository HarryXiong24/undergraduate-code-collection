import java.util.Scanner;

class Customers {
         //客户编号id
	private String id;
	public Customers(String id) {
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
class VIPCustomer extends Customers{
	private double credit;

	public VIPCustomer(String id, double credit) {
		super(id);
		this.credit = credit;
	}

	
	public double getCredit() {
		return credit;
	}


	@Override
	public double payAmount(double consumptionAmount) {
		// TODO Auto-generated method stub
		double output = 0;
		
		if(consumptionAmount <= credit)
		{
			credit = credit - consumptionAmount;
			credit = Math.floor(credit);
			return 0;
		}
		else
		{
			output = consumptionAmount - credit;
			credit = Math.floor(output);
			return output;
		}
	}
}
/******end******/
public class NO3_50100_2018_cn_sw_p3_002{
	public static void main(String[] args) {
		Customers customer = new VIPCustomer("001",100.0);
		System.out.println("客户："+customer.getId()+"本次消费了78.5元，实际支付"+customer.payAmount(78.5)+"元");
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入vip客户编号，初始消费积分及本次消费金额：");
		String id = scanner.next();
		double credit = scanner.nextDouble();
		double consumption = scanner.nextDouble();
		VIPCustomer vip = new VIPCustomer(id, credit);
		System.out.println("output:");
		System.out.println("VIP客户："+vip.getId()+"本次消费了"+consumption+"元，实际支付"+vip.payAmount(consumption)+"元，剩余积分："+vip.getCredit());
		scanner.close();
	}
}
