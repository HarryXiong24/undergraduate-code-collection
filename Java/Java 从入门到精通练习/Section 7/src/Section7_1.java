
public class Section7_1 {

	public static void main(String[] args) {
		int[] oldArr= {1,3,4,5,0,0,6,6,0,5,4,7,0,5};
		int[] newArr=new int[100];
		int i;
		int j=0;
		for(i=0;i<oldArr.length;i++)
		{
			if(oldArr[i]!=0)
			{
				newArr[j]=oldArr[i];
				j++;
			}
		}
		
		for(i=0;i<j;i++)
		{
			System.out.print(newArr[i]+" ");
		}

	}

}
