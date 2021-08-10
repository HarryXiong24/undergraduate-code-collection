		
public class Book {
	private String name;
	private double price;
	
	public Book(String name,double price)
	{
		this.name=name;
		this.price=price;
	}
	
	public void printlnfo()
	{
		System.out.println("name:"+this.name+"price:"+this.price);
	}
	
	public static void main(String[] args) {
	    Book bookA=new Book("ÌÚÑ¶´«",58.00);
	    Book bookB=bookA;
        bookA.printlnfo();
        bookB.printlnfo();
	}

}
