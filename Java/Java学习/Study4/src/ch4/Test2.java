package ch4;

class Stock
{
	public String symbol;
	public String name;
	public double previousClosingPrice;
	public double currentPrice;
	
	public Stock(String symbol, String name) {
		this.symbol = symbol;
		this.name = name;
	}
	
	public double getChangePercent()
	{
		double per;
		
		per = previousClosingPrice - currentPrice;
		
		per = Math.abs(per);
		
		return per;
	}
	
}


public class Test2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stock ex1 = new Stock("ORCL", "Oracle Corporation");
		ex1.previousClosingPrice = 34.5;
		ex1.currentPrice = 36.85;
		
		System.out.printf("The price-change percentage of stock ORCL is:%.2f", ex1.getChangePercent());
		System.out.println("%");
	}

}
