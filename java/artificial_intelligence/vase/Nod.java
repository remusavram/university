package Vase_Package;

import java.util.ArrayList;
import java.util.Arrays;

class Nod 
{
	// clasa nod reprezinta o faza in care vasele au diferite cantitatii; si retine tatal si adancimea nodului
	
	// vectorul volum retine cantitatile vaselor intr-un anumit moment
	int[] volTemp;
	// op retine operatia ce s-a efectuat; ex: "Se umple vasul i"
	String operatieEfectuata = "";
	// nodul tata retine parintele 
	Nod tata; 
	// variabila nivel retine vivelul pe care se afla nodul respectiv
	int nivel;
	
	// definim constructorul
	Nod (int[] volTemp, String operatieEfectuata,Nod tata,int nivel)
	{				
		this.volTemp=volTemp;
		this.operatieEfectuata=operatieEfectuata;
		this.tata = tata;
		this.nivel=nivel;
	}
	
	public String toString() 
	{
		return operatieEfectuata;
	}
			
	public int getNivel() 
	{
		return nivel;
    }


	// aceasta functie creeaza o lista de noduri pentru a putea retine legatura dintre ele
	public void getCale(ArrayList<Nod> lnoduri) 
	{
	    if (tata != null) 
	    	tata.getCale(lnoduri);
		lnoduri.add(this);
	}

	public ArrayList<Nod> getCale() 
	{
	    ArrayList<Nod> result = new ArrayList();
	    getCale(result);
	    return result;
	}
}
