/*								Tema 1
*
*
*	Se dau n vase avand capacitatile c1, c2, . . . , cn, unde ci este o valoare
*	naturala, exprimata in litri. Vasele nu au gradatii de volum. Initial, vasele
*	sunt goale. Sunt permise urmatoarele trei operatii:
*		1. se poate trece apa din vasul i in vasul j (i 6= j), pana cand se umple
*	vasul j sau se goleste vasul i;
*		2. se poate goli vasul i pe pamant;
*		3. se poate adauga apa de la robinet in vasul i pana cand se umple.
*	Folosind algoritm de cautare “mai intai in adancime cu adancire
*	iterativa”, sa se determine numarul minim de operatii, precum ¸si care sunt
*	acestea, pentru a ajunge ca intr-un vas sa se gaseasca un volum V (numar
*	natural dat) de apa. Daca nu este posibil, atunci acest lucru va fi raportat.

*	• Datele de intrare n, c1, c2, . . . , cn, V se citesc dintr-un fisier de intrare
*	de tip text.
*	• Datele de iesire se vor scrie intr-un fi¸sier de tip text, cate o operatie
*	pe o linie (“Se toarna din vasul . . .in vasul . . . ; cont¸inutul actual al
*	vaselor este ... (scrieti lista tuturor volumelor de apa aflate in fiecare
*	vas in parte).”), sau mesajul “Nu se poate.”, dupa caz. Pe ultima linie
*	se va afisa numaarul de operat¸ii efectuate in total.
*		Exemplu: Fie n = 2, c1 = 5, c2 = 3, V = 4.
*	Succesiunea de stari este: (0, 0) -> (5, 0) -> (2, 3) -> (2, 0) -> (0, 2) ->
*	(5, 2) -> (4, 3). Exista cel putin alte 2 solutii cu 6 operatii, dar se cere
*	raportarea uneia singure.
*/




package Vase_Package;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) 
	{
		// definim functia principala in care:
		// deschidem fisierul in.txt si memoram datele din fisier;
		// creem un obiect de tip Vase si apelam algoritmul de cautare “mai intai in adancime cu adancire iterativa”;
		// deschidem fisierul out.txt si scriem in el solutia problemei;
		
		try 
		{
			// deschidem fisierul in.txt
			BufferedReader br = new BufferedReader(new FileReader("in.txt"));
				    		  
			// citim numarul vaselor de pe prima linie
		    int nr_vase=Integer.parseInt(br.readLine());
		    
		    // citim cantitatile de pe a 2 linie
		    int[] cantitati =new int[nr_vase];
		    int i=0;
		   
	        String linie = br.readLine();			         
	        StringTokenizer st = new StringTokenizer(linie," ");	        
	        while (st.hasMoreTokens())
	        {		           
	            cantitati[i] = Integer.parseInt(st.nextToken());
	            i++;
	        }
	        
	        // citim volumul ce dorim sa il aflam de pe a 3 linie
	        int volum=Integer.parseInt(br.readLine());	        
	        
	        // deschidem fisierul out.txt
	        PrintWriter scrieInFisier = new PrintWriter(new BufferedWriter(new FileWriter("out.txt", false)));
	        scrieInFisier.println("Pentru aflarea solutiei se foloseste algoritm de cautare “mai intai in adancime cu adancire iterativa”.");
	        scrieInFisier.println();
	        br.close();
	        scrieInFisier.flush();
	        
	        // creem un obiect de tip Vase
	        Vase v = new Vase(cantitati,volum);
	        
	        // prima data verificam contitiile ca informatiile preluate din fisierul in.txt sa fie corect introduse
	        if(v.verificareConditii() == 1)
	        {
	        	scrieInFisier.println("Toate capacitatile vaselor au aceeasi cantitate!");
	        	scrieInFisier.flush();
	        }
	        else if (v.verificareConditii() == 2)
	        {
	        	scrieInFisier.println("Volumul ce vrem sa il obtinem este mai mare decat cantitatea vasului cu cantitatea maxima!");
	        	scrieInFisier.flush();
	        }
	        else if (v.verificareConditii() == 3)
	        {
		        v.cautareAdancimeIterativa();
	        }
	        else
	        {
	        	scrieInFisier.println();
		        scrieInFisier.println();
		        scrieInFisier.println("Datele introduse sunt incorecte!!");
	        }
	       
		} 
		// afisam daca exista erori
		catch (FileNotFoundException e) 
		{			
			e.printStackTrace();
		} 
		catch (NumberFormatException e)
		{			
			e.printStackTrace();
		} 
		catch (IOException e) 
		{			
			e.printStackTrace();
		}
		System.out.println("Programul a fost rulat cu success!");
	}
}