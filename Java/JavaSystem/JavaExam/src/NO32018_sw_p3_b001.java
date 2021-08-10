import java.util.Scanner;
class SimpleCalculator{
	protected double operand1;
	protected double operand2;
	public SimpleCalculator(double operand1, double operand2) {
		this.operand1 = operand1;
		this.operand2 = operand2;
	}
	public double addition(){
		return operand1 + operand2;
	}
	public double subtraction(){
		return operand1 - operand2;
	}
	public double calculate(String operator){
		switch (operator) {
		case "+":
			return addition();
		case "-":
			return subtraction();
		default:
			return 0.0;
		}
	}
}
/******start******/
class AdvancedCalculator extends SimpleCalculator{

	public AdvancedCalculator(double operand1, double operand2) {
		super(operand1, operand2);
		// TODO Auto-generated constructor stub
	}
	
	public double multiply()
	{
		return operand1 * operand2;
	}
	
	public double division()
	{
		return operand1 / operand2;
	}

	@Override
	public double calculate(String operator) {
		// TODO Auto-generated method stub
		switch (operator) {
		case "+":
			return addition();
		case "-":
			return subtraction();
		case "*":
		    return multiply();
		case "/":
		    return division();
		default:
			return 0.0;
		}
	}	
}
/******end******/
public class NO32018_sw_p3_b001 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please input the operands and operator, e.g., 4 + 5, where we have a blank between the operand and the operator.");
		double operand1 = scanner.nextDouble();
		String operator = scanner.next();
		double operand2 = scanner.nextDouble();
		SimpleCalculator caculator = new AdvancedCalculator(operand1, operand2);
		System.out.println("The output is: "+caculator.calculate(operator));
		scanner.close();
		
	}
}