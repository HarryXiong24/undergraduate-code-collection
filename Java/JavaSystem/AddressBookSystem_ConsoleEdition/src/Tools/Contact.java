package Tools;

import java.util.ArrayList;

/**
 * @ClassName Contact.java
 * @Package Tools
 * @author XHW
 * @time 下午9:41:50
 * @Description 用于暂存联系人信息，方便文件的读入读出
 */
public class Contact {
	
	private String name;
	private String sex;
	private ArrayList<String> phonenumbers = new ArrayList<String>();
	private String email;
	private String group;
	private String other;
	
	public Contact() {
		
	}
	
	public Contact(String name, String sex, ArrayList<String> phonenumbers, String email, String group, String other) {
		super();
		this.name = name;
		this.sex = sex;
		this.phonenumbers = phonenumbers;
		this.email = email;
		this.group = group;
		this.other = other;
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getOther() {
		return other;
	}

	public void setOther(String other) {
		this.other = other;
	}

	public String getGroup() {
		return group;
	}

	public void setGroup(String group) {
		this.group = group;
	}

	public ArrayList<String> getPhonenumbers() {
		return phonenumbers;
	}

	public void setPhonenumbers(ArrayList<String> phonenumbers) {
		this.phonenumbers = phonenumbers;
	}
	
}
