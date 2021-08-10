import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class message{
	private String content;
	private String title;
	private Date time;
	
	public message(String content, String title, Date time) {
		super();
		this.content = content;
		this.title = title;
		this.time = time;
	}
	
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public Date getTime() {
		return time;
	}
	public void setTime(Date time) {
		this.time = time;
	}
	
}

/****start********/
class user{
	private String name;
	private List messages = new ArrayList();
	
	public user(String name, List messages) {
		super();
		this.name = name;
		this.messages = messages;
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public List getMessages() {
		return messages;
	}

	public void setMessages(List messages) {
		this.messages = messages;
	}

	public void addMessages(message m) {
		messages.add(m);
	}

	public void deleteMessages(message m) {
		if(m == null)
		{
			throw new NullPointerException();
		}
		else {
			messages.remove(m);
		}
	}
	
	public void print(List messages2) {
		// TODO Auto-generated method stub
		System.out.println(messages2);
	}

}

/****end********/

public class NO7_cy_15f_collection{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String content1 = scanner.next();
		String title1 = scanner.next();
		String content2 = scanner.next();
		String title2 = scanner.next();
		String username = scanner.next();
		
		System.out.println("output:");
		
		message m1 = new message(content1, title1,new Date());
		List list = new ArrayList();
		list.add(m1);
		
		user u = new user(username,list);
		message m2 = new message(content2, title2,new Date());
		u.addMessages(m2);
		try{
		u.deleteMessages(null);
		}catch(NullPointerException e){
			System.out.println(e.toString());
		}
		
		System.out.println(u.getName());
        u.print(u.getMessages());
		scanner.close();
	}
}


