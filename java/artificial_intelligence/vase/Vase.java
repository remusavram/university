package Vase_Package;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;



public class Vase 
{
	// cantitati reprezinta cantitatile vaselor existente
	int[] cantitati;
	// vol_cautat reprezinta cantitatea ce dorim sa il aflam
	int vol_cautat;
	
	// constructorul clasei Vase
	Vase(int[] cantitati,int vol_cautat) 
	{
		this.cantitati=cantitati;
		this.vol_cautat=vol_cautat;
	}
		
	// aceasta functie returneaza vasul cu cantitatea cea mai mare
	public int max(int[] cantitati) 
	{
		int max = cantitati[0];   
	    for (int i=0; i<cantitati.length; i++)
	        if (cantitati[i] > max)
	        	max = cantitati[i];
	   return max;
	}
	   
	// aceasta functie verifica daca toate vasele au aceeasi cantitate
	public boolean CantitatiEgale()
	{
	   int primul = cantitati[0];
	   for(int i=0; i<cantitati.length; i++)			   
		   if(cantitati[i] != primul) 
			   return true;			   
	   return false;
	}
	   
	// verificam daca volumul ce vrem sa il obtinem este mai mare decat cantitatea vasului cu cantitatea maxima
	public boolean verificareCantitateDorita()
	{
		for(int i=0; i<cantitati.length; i++) 	    	
	  		if(vol_cautat > max(cantitati))  
	   			return true;	    	  
	   	return false;
    }
	    
	    // verificam toate conditiile de mai sus
	    public int verificareConditii()
	    {
	    	if(verificareCantitateDorita())
	    		return 2;
	    	if(!CantitatiEgale())
    	    	return 1;
	    	return 3;
	    }
	
	    // verificam daca avem vreun vas cu aceeasi capacitatea ce dorim sa o aflam
	    public boolean esteSolutie(Nod nod) {
	    	for(int i=0; i<nod.volTemp.length; i++) 	
	    	if (nod.volTemp[i] == vol_cautat) 
	    		return true;	    	
	    	return false;
		}
	  
	    // aceasta functie face operatiile de golire a unui vas, de umplere a unui vas si de transfer de apa intre 2 vase
	    public ArrayList<Nod> succesori(Nod tata) 
	    {
	    	ArrayList<Nod> listasuccesori = new ArrayList<Nod>();		
			// facem calculele folosind 2 cata 2 vase
	    	for(int i=0;i<cantitati.length-1;i++)
				for(int j=i+1;j<cantitati.length;j++)
				{
					// conditie: daca x nu este plin si y nu este gol se transfera cantitatea z din y in x
					if (tata.volTemp[i] < cantitati[i] && tata.volTemp[j] > 0) 
					{
						int z = Math.min(tata.volTemp[j], cantitati[i]-tata.volTemp[i]);								
						int volTemp[]=new int[tata.volTemp.length];
						for(int k=0;k<tata.volTemp.length;k++) volTemp[k]=tata.volTemp[k];
						volTemp[i]=volTemp[i]+z;
						volTemp[j]=volTemp[j]-z;
						String operatieEfectuata="Se varsa cantitatea "+z+" din vasul"+j+" in vasul"+i+" "+Arrays.toString(volTemp);
						int nivel=tata.nivel;
						listasuccesori.add(new Nod(volTemp,operatieEfectuata,tata,nivel+1)); 
					}
					
					// conditie: daca y nu este plin si x nu este gol se transfera cantitatea z din x in y
					if (tata.volTemp[j] < cantitati[j] && tata.volTemp[i] > 0) 
					{
						int z = Math.min(tata.volTemp[i], cantitati[j]-tata.volTemp[j]);								
						int volTemp[]=new int[tata.volTemp.length];
						for(int k=0;k<tata.volTemp.length;k++) volTemp[k]=tata.volTemp[k];
						volTemp[i]=volTemp[i]-z;
						volTemp[j]=volTemp[j]+z;
						String operatieEfectuata="Se varsa cantitatea "+z+" din vasul" +i+" in vasul"+j+" "+Arrays.toString(volTemp);
						int nivel=tata.nivel;
						listasuccesori.add(new Nod(volTemp,operatieEfectuata, tata,nivel+1)); 			
					}
					
					// se goleste vasul i
					if (tata.volTemp[i] > 0) 
					{ 									
						int volTemp[]=new int[tata.volTemp.length];
						for(int k=0;k<tata.volTemp.length;k++) volTemp[k]=tata.volTemp[k];
						volTemp[i]=0;
						String operatieEfectuata="Se goleste vasul"+i+" "+Arrays.toString(volTemp);
						int nivel=tata.nivel;
						listasuccesori.add(new Nod(volTemp,operatieEfectuata,tata,nivel+1)); 
					} 
					
					// se goleste vasul j
					if (tata.volTemp[j] > 0) 
					{ 									
						int volTemp[]=new int[tata.volTemp.length];
						for(int k=0;k<tata.volTemp.length;k++) volTemp[k]=tata.volTemp[k];
						volTemp[j]=0;
						String operatieEfectuata="Se goleste vasul"+j+" "+Arrays.toString(volTemp);
						int nivel=tata.nivel;
						listasuccesori.add(new Nod(volTemp,operatieEfectuata,tata,nivel+1)); 
					} 
					
					// se umple vasul i
					if (tata.volTemp[i] < cantitati[i]) 
					{ 									
						int volTemp[]=new int[tata.volTemp.length];
						for(int k=0;k<tata.volTemp.length;k++) volTemp[k]=tata.volTemp[k];
						volTemp[i]=cantitati[i];
						String operatieEfectuata="Se umple vasul"+i+" "+Arrays.toString(volTemp);
						int nivel=tata.nivel;
						listasuccesori.add(new Nod(volTemp,operatieEfectuata,tata,nivel+1));
					} 
					
					//se umple vasul j
					if (tata.volTemp[j] < cantitati[j]) { 									
						int volTemp[]=new int[tata.volTemp.length];
						for(int k=0;k<tata.volTemp.length;k++) volTemp[k]=tata.volTemp[k];
						volTemp[j]=cantitati[j];
						String operatieEfectuata="Se umple vasul"+j+" "+Arrays.toString(volTemp);
						int nivel=tata.nivel;
						listasuccesori.add(new Nod(volTemp,operatieEfectuata, tata,nivel+1)); 	
					} 
				}
			
		return(listasuccesori);
	}
	    
	// aceasta functie foloseste algoritmul de cautare in adancime limitata  
	public Nod cautareAdancimeLimitata(Nod nod, int limita) 
	{
		Nod rez;
		// se verifica daca exista vreun vas care are acceasi cantitate cu cantitatea ce dorim sa o aflam 
	    if(esteSolutie(nod))
	    	return nod;
	    if( nod.getNivel() == limita)
	    	return null;
	    ArrayList<Nod>  newsuccesori = succesori(nod);
	    for(Iterator<Nod> it=newsuccesori.iterator(); it.hasNext();) 
	    {
	    	rez = cautareAdancimeLimitata(it.next(), limita);
	        if( rez != null)
	        	return rez;
	    }
	    return null;
	}
	
	// aceasta functie foloseste algoritmul de cautare in adancime iterativa
	public void cautareAdancimeIterativa() 
	{
		// limita reprezinta nivelul maxim
		int limita = 30;
		Nod rezultat;
		// la inceput se presupune ca toate vasele sunt goale
		int[] volTemp = new int[cantitati.length];
	  	for(int i=0;i<cantitati.length;i++)
	  		volTemp[i] = 0;
        Nod nod= new Nod(volTemp,"initializare: "+Arrays.toString(volTemp), null,0);
		
        // se deschide fisierul out.txt pentru a se scrie solutia problemei
        try 
		{			    		 
			PrintWriter scrieInFisier = new PrintWriter(new BufferedWriter(new FileWriter("out.txt", true)));		
		    for(int nivel=0; nivel<=limita; nivel++) 
		    {
		    	rezultat = cautareAdancimeLimitata(nod, nivel);
		        if( rezultat != null) 
		        {
		        	scrieInFisier.println("\nSolutie : \n");
					ArrayList<Nod> solutie = rezultat.getCale();					    	
					for(int i=0; i<solutie.size(); i++)
						scrieInFisier.println(i + ": " + solutie.get(i));							    		
					scrieInFisier.print("\n Numarul de operatii efectuate: " + (rezultat.getCale().size()-1)); 
				   	// dupa afisarea primei solutii oprim programul;
					break;
		        } 
		    }
        scrieInFisier.flush();
		scrieInFisier.close();
		}
        catch (FileNotFoundException e) 
        {	
        	e.printStackTrace(); 
        }
        catch (IOException e) 
        {
        	e.printStackTrace(); 
        }
	}
}


