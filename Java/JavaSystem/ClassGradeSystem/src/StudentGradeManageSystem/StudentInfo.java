package StudentGradeManageSystem;

public class StudentInfo extends score_cal{
	public int number;
	public String name;
	public String sex;
	
	public void setInfo(int number, String name, String sex) {
		this.number = number;
		this.name = name;
		this.sex = sex;
	}
	
	public int getNumber() {
		return number;
	}
	
	public String getName() {
		return name;
	}
	
	public String getSex() {
		return sex;
	}
	
}