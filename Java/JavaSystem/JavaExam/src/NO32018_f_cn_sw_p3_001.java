import java.util.Scanner;
//已有一个类Converter，表示换算器，定义如下：
class Converters{
	private String name;
	public Converters(String name){
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public void convert(double input){
	}
}
//定义一个温度换算器（TemperatureConverter）继承于Converter类；
/******start******/
class TemperatureConverter extends Converters{
	private double fahrenheit;

	public TemperatureConverter(String name) {
		super(name);
	}

	public double getFahrenheit() {
		return fahrenheit;
	}

	public void setFahrenheit(double fahrenheit) {
		this.fahrenheit = fahrenheit;
	}

	@Override
	public void convert(double input) {
		// TODO Auto-generated method stub
		fahrenheit = (9 / 5.0) * input + 32;
	}
	
}
/******end******/
public class NO32018_f_cn_sw_p3_001 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入一个温度数据（单位摄氏度）：");
		double input = scanner.nextDouble();
		TemperatureConverter converter = new TemperatureConverter("温度换算器");
		converter.convert(input);
		System.out.println("output:");
		System.out.println("摄氏"+input+"度换算为华氏度为："+converter.getFahrenheit());
		System.out.println("检查继承关系："+(converter instanceof Converters));
		converter.setFahrenheit(100);
		scanner.close();
	}

}