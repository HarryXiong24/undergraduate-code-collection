import java.util.Random;
public class T2乱序排序
{
	public static void main(String[] args) 
	{
		Random rand=new Random();          //rand为对象名
		int[] a=new int[rand.nextInt(20)];
		int temp;
		int i,j;
		
		System.out.println("数组长度为:"+a.length);
		for(i=0;i<a.length;i++)
		{
			a[i]=rand.nextInt(100);
		}
		
		for(j=a.length;j>1;j--)
		{
			for(i=1;i<a.length;i++)
			{
				if(a[i]<a[i-1])
				{
					temp=a[i];
					a[i]=a[i-1];
					a[i-1]=temp;
				}
			}
		}
		
		for(i=0;i<a.length;i++)
		{
			System.out.print(a[i]+" ");
		}

	}

}
