import message.*;
import java.util.Scanner;
import java.io.*;

public class ShowMessage 
{
	
	public static void main(String[] args)throws IOException
	{
		//exercitiu 3
		
		Messagegenerator mesaj;																								
		mesaj=new Messagegenerator();
		System.out.println("+++++++++++++++++"+"\n"+ "Salut"+"\n"+"limbaj"+"\n"+"Java"+"\n"+"+++++++++++++++++"+"\n");		
		
		//exercitiu 1+2
		
		mesaj.initializare("aaa");
		mesaj.writePhrase("aaa");
		System.out.println();
		mesaj.writeSentence("bbb");
		
		//exercitiu 5
		
		Scanner scan=new Scanner(System.in);
		System.out.print("\n\n"+"Primul cuvant: ");
		String primul= scan.nextLine();
		System.out.print("Al doilea cuvant: ");
		String al_doilea= scan.nextLine();
		System.out.print("Al treilea cuvant: ");
		String al_treilea= scan.nextLine();
		System.out.println("\n"+"+++++++++++++++++"+"\n"+ primul+"\n"+al_doilea+"\n"+al_treilea+"\n"+"+++++++++++++++++"+"\n");
	}
}
