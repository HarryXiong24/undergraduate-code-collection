package Section8_2;

class Instrument {
	public String play()
	{
		return "play Instrument";
	}

}

class Wind extends Instrument{
	public String play()
	{
		return "play wind";
	}
}

class Stringed extends Instrument{
	public String play()
	{
		return "play stringed";
	}
}

public class playInstrument{
	public static void main(String[] args) {
		Instrument a=new Instrument();
		Wind b=new Wind();
		Stringed c=new Stringed();
		
		System.out.println(a.play());
		a=b;
		System.out.println(a.play());
		a=c;
		System.out.println(a.play());
		
	}
	
}



