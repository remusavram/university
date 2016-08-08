import java.util.*;
public class palindrom
{
	
	
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Textul: ");
		String s=sc.nextLine();
        StringBuilder sb=new StringBuilder();
		for(int i=s.length()-1;i>=0;i--)
		               sb.append(s.charAt(i));
			
		
		String rez=sb.toString();
		System.out.println(rez);
		if(s.equalsIgnoreCase(rez))
			System.out.print("palindrom");
		else
			System.out.print("nu sunt palindrome");
	}
}
