package Test;

public class DecimalToBinary {
	public static String decimalToBinary(int value)
	{
		int i = -1;
	    char[] ch = new char[100];
		
		do{
			i = i + 1;
			ch[i] = (char)(value % 2 + 48) ;
			value = value / 2;
		}while(value != 0);
		
		String s = new String(ch);
		System.out.println(s);
		String snew = s.trim();
		
		StringBuffer result = new StringBuffer(snew);
		return result.reverse().toString();
	}
}


