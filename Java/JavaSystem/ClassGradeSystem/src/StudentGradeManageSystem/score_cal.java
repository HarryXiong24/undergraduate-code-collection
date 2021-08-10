package StudentGradeManageSystem;

public class score_cal{
	public double Chinese;
	public double English;
	public double Math;
	public double average;
	
	public void setscore(double chinese, double english, double math) {
		this.Chinese = chinese;
		this.English = english;
		this.Math = math;
	}
	
	public double getChinese() {
		return Chinese;
	}
	
	public double getEnglish() {
		return English;
	}
	
	public double getMath() {
		return Math;
	}
	
	public double ave_cal()
	{
		this.average = (this.Chinese + this.English + this.Math) / 3.0;
		
		return this.average;
	}
	
	
}