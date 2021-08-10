package MyLinkList;

//测试代码
public class AList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkList exam = new LinkList();
		int len;
		
		exam.insertValue(1, 1);
		exam.insertValue(2, 2);
		exam.insertValue(3, 3);
		exam.insertValue(4, 4);
		exam.insertValue(5, 5);
		exam.printList();
		System.out.println("");
		
		exam.insertHead(10);
		exam.insertTail(10);
		exam.printList();
		len = exam.getLenth();
		System.out.println("The len is:" + len);
		
		exam.deleteValue(5);
		exam.printList();
	}

}
