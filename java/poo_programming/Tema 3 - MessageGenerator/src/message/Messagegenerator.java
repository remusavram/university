package message;

public class Messagegenerator 
{
	public final static char HALF_STOC=';';
	public final static char FULL_Stop='.';
	public String border;
	public Messagegenerator()
	{
		border="    ";
	}
	
	public Messagegenerator(String initBorder)
	{
		border=initBorder;
	}
	
	public Messagegenerator(String b, int x)
	{
		border=b;
		if(x!=1 || x!=2)
			System.out.println("Eroare");
		else
			if(x==1)
				System.out.println(border);
			else
			{
				System.out.println(border);
				System.out.println(border);
			}
	}
	
	public void initializare(String newBorder)
	{
		border=newBorder;
	}

	public void printBorder()
	{
		System.out.println(border);
	}
	
	public void writePhrase(String str)
	{
		System.out.print(str + HALF_STOC);
	}
	
	public void writeSentence(String str)
	{
		System.out.print(str + FULL_Stop);
	}

}
