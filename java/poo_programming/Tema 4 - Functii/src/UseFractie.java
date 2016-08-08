import fractie.*;

import java.util.Scanner;


public class UseFractie 
{
	public static void main(String[] args) 
	{
	
	while(true)
	{
		Scanner CitireTastatura=new Scanner(System.in);
		System.out.println("Introduceti comanda : ");
		String c=CitireTastatura.next();
		
		if (c.equals("q")) break;
		
		
        int c1=CitireTastatura.nextInt();
        int c2=CitireTastatura.nextInt();
        int c3=CitireTastatura.nextInt();
        int c4=CitireTastatura.nextInt();
        
        Fractie rez=new Fractie();
        Fractie f1=new Fractie(c1,c2);
        Fractie f2=new Fractie(c3,c4);
        
		 switch(c.charAt(0))
			{
		        case '+': {
		                	rez=f1.adunare(f2);
		                	rez.AfisareFractie();
		                	System.out.println();
		                	break;
		                  }
		        
		        case '-': {
		                   	rez=f1.scadere(f2);
		                   	rez.AfisareFractie();
		                	System.out.println();
		                	break;
	    	              }
		        
		        case '*': {		        	        		        	
		                	rez=f1.inmultire(f2);
		                	rez.AfisareFractie();
		                	System.out.println();
		                	break;
		                  }
		        
		        case '/': {		        	        		        	
		                	rez=f1.impartire(f2);
		                	rez.AfisareFractie();
		                	System.out.println();
		                	break;
			              }
		        
		        default :
		                  {
		        	System.out.println("Ati introdus comanda gresit ! : ");
		        	System.out.println();
		            break;
		                  }
		        }
		}
	
	}
}

