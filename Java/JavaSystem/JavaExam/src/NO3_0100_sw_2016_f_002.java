import java.util.Scanner;

class Item{
	private String name;
	private float price;
	private int count;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public float getPrice() {
		return price;
	}
	
	public void setPrice(float price) {
		this.price = price;
	}
	
	public int getCount() {
		return count;
	}
	public void setCount(int count) {
		this.count = count;
	}
	public Item(String name, float price, int count) {
		this.name = name;
		this.price = price;
		this.count = count;
	}
        //计算商品的总价格
	public float calTotal(){
		return price*count;
	}
        //输出商品的总价格
	public void print() {
		System.out.println(count+"件"+name+"商品 ,总价:"+calTotal());
	}
}
/******start******/
class DiscountItem extends Item{
	private float discount;

	public DiscountItem(String name, float price, int count, float discount) {
		super(name, price, count);
		this.discount = discount;
	}

	public float getDiscount() {
		return discount;
	}

	public void setDiscount(float discount) {
		this.discount = discount;
	}

	@Override
	public float calTotal() {
		// TODO Auto-generated method stub
		return getCount() * getPrice() * discount;
	}
}
/******end******/
public class NO3_0100_sw_2016_f_002 {
public static void main(String[] args) {
	System.out.println("请输入一种商品的名称、单价、数量以及折扣（折扣为0-1.0之间的数），数据之间以空格分开");
	Scanner scanner = new Scanner(System.in);
	String name = scanner.next();
	float price = scanner.nextFloat();
	int count = scanner.nextInt();
	float discount = scanner.nextFloat();
	System.out.println("output:");
	Item item = new Item(name, price, count);
	item.print();
	System.out.println("打折了!");
	item = new DiscountItem(name, price, count, discount);
	item.print();
	scanner.close();
	}
}