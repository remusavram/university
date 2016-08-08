import java.util.*;
import java.io.*;


public class AutomatFinDet 
{
	public static void main(String[] args) throws IOException
	{
		Scanner s=new Scanner(new File("date.in"));
		//n-numarul de stari
		int n=s.nextInt();
		String[] q=new String[n];
		for(int i=0;i<n;i++)
		{
		    q[i]=s.next();
		    System.out.print("  "+q[i]);
		}
		
		//m-numarul de simboluri
		int m=s.nextInt();
		String[] e=new String[m];
		for(int i=0;i<m;i++)
			e[i]=s.next();
		
		//nf-nr de stari finale
		int nf=s.nextInt();
		String[] f=new String[nf];
		for(int i=0;i<nf;i++)
			f[i]=s.next();
		//str-cuv initial
		String str=s.next();
		if(apartineAlfabet(str,e))
			System.out.println("DA");
		
		
		s.close();
			

	}
	public boolean apartineAlfabet(String str,String[] e)
	{
		int ok=0;
		for(int i=0;i<str.length();i++)
		{
			for(int j=0;j<e.length;j++)
				if(str.charAt(i)==e[j].charAt(0))
				{
					ok=1;
					j=e.length;
				}
			if(ok==0)
				return false;
		}
		return true;
		
				
	}

}
