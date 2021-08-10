package JavaQBank;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/* StudentScore类，表示单个学生的成绩  */
class StudentScore
{
	//成员变量score，表示学生的分数
	private float score;
	
	//StudentScore 的构造方法，对score变量进行初始化
	/******start******/
	public StudentScore(float score)
	{
		this.score = score;
	}
	/******end******/
	
	//score变量的setter和getter方法
	/******start******/
	public float getScore() 
	{
		return score;
	}

	public void setScore(float score)
	{
		this.score = score;
	}
	/******end******/
}

/*totalscore类的定义*/
public class totalscore
{
	//成员变量 name表示成绩单的名称
	private String name;
	//StudentScore数组类型的成员变量stuScores，表示本成绩单包含的所有学生成绩。
	/******start******/
	private StudentScore[] stuScores;
	/******end******/
	
	//totalscore类的构造方法，对两个成员变量进行初始化
	/******start******/
	public totalscore(String name, StudentScore[] stuScores) 
	{
		this.name = name;
		this.stuScores = stuScores;
	}
	/******end******/
	
	/*calculateTotalScore方法，计算本成绩单上所有成绩之和 @return 总成绩 */
	public float calculateTotalScore()
	{
		/******start******/
		float sum = 0;
		float score = 0;
		int i;
		
		for(i = 0; i < stuScores.length; i++)
		{
			score = stuScores[i].getScore();
			sum = sum + score;
		}
		
		return sum;
		/******end******/
	}
	

	public static void main(String[] args) 
	{
		List<StudentScore> scores = new ArrayList<StudentScore>();
		System.out.println("请输入成绩，成绩之间用空格隔开,结尾标记为exit，比如输入：79 69 90，将会得到输出结果：238.0");
		Scanner scanner = new Scanner(System.in); 
		while (scanner.hasNextFloat()) 
		{
			float score =scanner.nextFloat();
			scores.add(new StudentScore(score));
			
		}
		scanner.close();
		totalscore exam = new totalscore("网络1班", scores.toArray(new StudentScore[0]));
		System.out.println("output:"+exam.calculateTotalScore());
	}

}