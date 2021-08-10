package study11;

public class MyPerspon {
	public static void main(String[] args) {
		Student ex1 = new Student("Harry", "NULL", "123456", "null", "senjor");
		Person ex2 = new Student("Jerry", "NULL", "654321", "null", "senjor");
		
		System.out.println(ex1.toString());
		System.out.println(ex2.friend(ex1));
	}
}
