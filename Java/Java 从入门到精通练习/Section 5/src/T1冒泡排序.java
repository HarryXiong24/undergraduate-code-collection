
public class T1Ã°ÅÝÅÅÐò
{
	public static void main(String[] args) 
	{
		int[] a= {25,35,45,33,42,13,24,35,67,34};
		int temp;
		int i,j;
		
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
