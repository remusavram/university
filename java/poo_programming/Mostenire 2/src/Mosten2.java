
public class Mosten2
{
	public static void main(String[] s)
	{
		//Declarare variabilã referinþã de tipul clasei rãdãcinã
		Fruct of;
		//Alocare referinþã utilizând constructorul unei subclase
		//a clasei rãdãcinã (Para)
		of=new Para(1,2.75,3);
		System.out.println("Para ...creata ca referinta Fruct");
		//Utilizare, de fapt, în spirit polimorfic
		//a variabilei definite ºi alocate mai sus
		System.out.println("Tip fruct:"+of.consultaTipFruct());
		//Alocare referinþã utilizând constructorul unei subclase
		//a clasei rãdãcinã (Portocala)
		of=new Portocala(2,0.75,4);
		System.out.println("Portocala ...creata ca referinta Fruct");
		//Utilizare, de fapt, în spirit polimorfic
		//a variabilei definite si alocate mai sus
		System.out.println("Tip fruct:"+of.consultaTipFruct());
	}
};