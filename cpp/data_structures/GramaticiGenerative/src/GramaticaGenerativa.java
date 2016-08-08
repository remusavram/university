import java.util.*;
import java.io.*;

public class GramaticaGenerativa 
{
	public static boolean cuvTerminal(String s,int m,char[] term)
	{
		for(int i=0;i<s.length();i++)
		{
			int ok=1;
			for(int j=0;j<m;j++)
				if(s.charAt(i)==term[j])
				{
					ok=0;
				    j=m;
				}
			if(ok==1)
				return false;
		}
		return true;
			
	}
	
	static String landaRight(String str,String[] sir1,String[] sir2,int idx)
	{
		//cazul in acre landa apare in dr(sir2)-se elimina o litera/un grup
		int lg=sir1[idx].length();
		StringBuffer sb=new StringBuffer(str);
		int poz=str.indexOf(sir1[idx]);
  	    if(sir2[idx].equals("landa") && poz >= 0)
  	    {
  		   sb.delete(poz, poz+lg);
  		    return sb.toString();
  		}
  	    else 
  	    	return str;
	}
	
	
	public static void main(String[] args) throws IOException
	{
	   Scanner s=new Scanner(new File("gramatica.in"));
       int n=s.nextInt();
       char[] neterm=new char[n]; //sirul neterminalelor(n-elem)
       for(int i=0;i<n;i++)
    	   neterm[i]=s.next().charAt(0);
       
       int m=s.nextInt();
       char[] term=new char[m]; //sirul terminalelor(m-elem)
       for(int i=0;i<m;i++)
    	   term[i]=s.next().charAt(0);
       
       int nr;
       nr=s.nextInt();
       
       String[] sir1=new String[nr];
       String[] sir2=new String[nr];
       
       for(int i=0;i<nr;i++)
       {
    	   sir1[i]=s.next();
    	   sir2[i]=s.next();
       } 
       
       int nrit=s.nextInt();
       s.close();
       Random rand = new Random();
       
       
       int ord=1;
        PrintWriter pw=new PrintWriter("rezultat.out");
        pw.println("Rezultatele iteratiilor:");
       
       while(nrit!=0)
       {
    	   int ok=1;
    	   int poz;
    	   System.out.println();
    	   String str="S";
    	   System.out.print(" "+ord+":"+str);
           while(!cuvTerminal(str,m,term) && ok==1)
           {
                int[] aux=new int[20];
                int idx=0;//index in sirul auxiliar care retine regulile care contin neterminale din cuv curent
    	        for(int i=0;i<nr;i++)
    	        	if(str.indexOf("landa")>=0 && str.equals(""))
    	        			aux[idx++]=i;
    	           else
    	        	   if(str.indexOf(sir1[i])>=0)
    	    		        aux[idx++]=i;
    	    	   
    	    	      
    	        System.out.println(" idx::"+idx);
    	        
    	        if(idx<1)
    	        {
    	    	    System.out.println("  !blocaj!");
    	    	    ok=0;
    	         }
    	       	else
    	        {
    	           poz=rand.nextInt(idx);//regula kre se va aplik este:aux[poz]
    	           //landa case!!
    	           if(sir2[aux[poz]].equals("landa"))
    	           {
    	        	   str=landaRight(str,sir1,sir2,aux[poz]);
    	        	   System.out.print(" => "+str); 
    	           }
    	           else
    	           {
    	               str=str.replaceFirst(sir1[aux[poz]],sir2[aux[poz]]);
    	               System.out.print(" => "+str); 
    	           }
    	        }
            }
           pw.print(str+" - ");
           if(cuvTerminal(str,m,term))
        	   pw.print("terminal ");
           else
        	   pw.print("neterminal ");
           pw.println();
          nrit--;
          ord++;
       }
       pw.close();
      
       
       
	}

}
