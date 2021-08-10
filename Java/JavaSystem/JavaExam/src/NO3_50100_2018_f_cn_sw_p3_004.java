import java.util.Scanner;

//已有一个表示课程的类Course，定义如下：
class Course {
	private String name;

	public Course(String name) {
		super();
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	// 该方法为计算课程成绩绩点
	public double getCradePoint() {
		return 0;
	}
}
// 定义一个表示实践课程的类PracticalCourses继承于Course类
/******start******/
class PracticalCourses extends Course{
	private double examScore;
	private double practiceScore;
	
	public PracticalCourses(String name, double examScore, double practiceScore) {
		super(name);
		this.examScore = examScore;
		this.practiceScore = practiceScore;
	}

	public double getExamScore() {
		return examScore;
	}

	public double getPracticeScore() {
		return practiceScore;
	}

	@Override
	public double getCradePoint() {
		// TODO Auto-generated method stub
		double point = 0;
		if(examScore < 60 || practiceScore < 60)
		{
			point = 0;
			return point;
		}
		else
		{
			double sum = examScore * 0.5 + practiceScore * 0.5;
			point = (sum-60)*0.3 + 1;
			return point;
		}
	}
}
/******end******/
public class NO3_50100_2018_f_cn_sw_p3_004 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入课程名字，理论成绩和实践成绩：");
		String name = scanner.next();
		double examScore = scanner.nextDouble();
		double practiceScore = scanner.nextDouble();
		PracticalCourses practicalCourses = new PracticalCourses(name, examScore, practiceScore);
		System.out.println("课程：" + name + "的理论成绩为：" + practicalCourses.getExamScore() + ",实践成绩为："
				+ practicalCourses.getPracticeScore() + ",绩点成绩为：" + practicalCourses.getCradePoint());
		System.out.println("PracticalCourse继承于Course：" + (practicalCourses instanceof Course));
		scanner.close();
	}
}