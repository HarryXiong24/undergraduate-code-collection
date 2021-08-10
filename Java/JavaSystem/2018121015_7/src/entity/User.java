package entity;

import java.util.Date;

public class User {
	private int id;
	private String userName;
	private String pwd;
	private String gender;
	private String category;
	private String interest;
	private String photo;
	private Date regTime;
	
	public void setId(int id) {
		this.id = id;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public void setPwd(String pwd) {
		this.pwd = pwd;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public void setCategory(String category) {
		this.category = category;
	}

	public void setRegTime(Date regTime) {
		this.regTime = regTime;
	}
	public int getId() {
		return id;
	}
	public String getUserName() {
		return userName;
	}
	public String getPwd() {
		return pwd;
	}
	public String getGender() {
		return gender;
	}
	public String getCategory() {
		return category;
	}
	public Date getRegTime() {
		return regTime;
	}
	public String getInterest() {
		return interest;
	}
	public void setInterest(String interest) {
		this.interest = interest;
	}
	public String getPhoto() {
		return photo;
	}
	public void setPhoto(String photo) {
		this.photo = photo;
	}
	
}
