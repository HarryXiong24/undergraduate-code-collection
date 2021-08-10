package MyLinkList;

public class LinkList 
{
	private Node head = new Node();
	private final int PARAM_ERROR = -1;
	private final int NOTFIND = -2;
	private final int CANNOT_DEL = -3;
	private final int CANNOT_INSERT = -4;
	
	private class Node                    //节点类
	{
		private int data;
		private Node next;
		
		public Node()
		{
			this.data = 0;
			this.next = null;
		}
	}
	
	//public int searchByPos(int pos, Node result)
	public Node searchByPos(int pos)           //查找函数
	{
		int i = 0;
		Node temp = null;
		
		if(head == null)
		{
			return temp;
			//result = null;
			//return PARAM_ERROR;
		}
		
		temp = head;
		
		while(i < pos && temp.next != null )
		{
			i++;
			temp = temp.next;
		}
		
		if(i == pos)
		{
			return temp;
			//result = temp;
			//return 0;
		}
		else
		{
			temp = null;
			return temp;
			//result = null;
			//return NOTFIND;
		}

	}
	
	public int insertValue(int pos, int value)      //根据位置插入值
	{
		Node temp = new Node();
		Node Lnew = new Node();
		int flag = 0;
		
		if(head == null)
		{
			return PARAM_ERROR;
		}
		
		Lnew.data = value;
		Lnew.next = null;
		
		temp = searchByPos(pos-1);
		//flag = searchByPos(pos-1, temp);
		
		if(flag == NOTFIND)
		{
			return CANNOT_INSERT;
		}
		else
		{
			Lnew.next = temp.next;
			temp.next = Lnew;
		}
		
		return 0;
	}
	
	public int getLenth()                   //返回长度
	{
		int len = 0;
		Node temp = null;
		
		if(head == null)
		{
			return PARAM_ERROR;
		}
		temp = head.next;
		
		while(temp != null)
		{
			len++;
			temp = temp.next;
		}
		
		return len;
	}
	
	public int insertHead(int value)              //头插
	{
		int flag = 0;
		
		flag = insertValue(1, value);
		
		return flag;
	}
	
	public int insertTail(int value)              //尾插
	{
		int flag,len;
		
		len = getLenth();
		
		flag = insertValue(len+1, value);                //因为插入队尾，所以应当为len+1个位置 
		
		return flag;
	}
	 
	public int printList()                       //打印
	{
		Node temp = null;
		
		if(head == null)
		{
			return PARAM_ERROR;
		}
		temp = head.next;
		
		while(temp != null)
		{
			System.out.printf("%d ",temp.data);
			temp = temp.next;
		}
		return 0;
	}
	
	public int deleteValue(int pos)               //根据位置删除值
	{
		Node temp1 = null;
		Node temp2 = null;
		int flag = 0;
		
		if(head == null)
		{
			return PARAM_ERROR;
		}
		temp1 = head;
		
		temp1 = searchByPos(pos-1);
		//flag = searchByPos(pos-1, temp1);
		
		if(flag == NOTFIND)
		{
			return CANNOT_DEL;
		}
		
		temp2 = temp1.next;
		temp1.next = temp2.next;
		temp2 = null;
		
		return 0;
	}
}
