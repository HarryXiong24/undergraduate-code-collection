import java.util.Scanner;
//已有一个类Converter，表示换算器，定义如下：
class Converter{
	private String name;
	public Converter(String name){
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public double convert(double input){
		return 0;
	}
}
//定义一个货币换算器（CurrencyConverter）继承于Converter类；
/******start******/
class CurrencyConverter extends Converter
{
	private double exchangeRate = 1.0;
	
	public CurrencyConverter(String name, double exchangeRate) {
		super(name);
		this.exchangeRate = exchangeRate;
	}

	public double getExchangeRate() {
		return exchangeRate;
	}

	public void setExchangeRate(double exchangeRate) {
		this.exchangeRate = exchangeRate;
	}

	@Override
	public double convert(double input) {
		// TODO Auto-generated method stub
		return input * exchangeRate;
	}
}

/******end******/
public class NO32019_ch_sw_p3_001 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入换算汇率和原货币金额，用空格隔开：");
		double rate = scanner.nextDouble();
		double input = scanner.nextDouble();
		CurrencyConverter converter = new CurrencyConverter("货币换算器", rate);
		converter.convert(input);
		System.out.println("原货币金额："+input+"换算为目标数据后的金额为："+converter.convert(input));
		System.out.println("检查继承关系："+(converter instanceof Converter));
		converter.setExchangeRate(5.5);
		scanner.close();
	}

}