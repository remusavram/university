
public class Mosten2
{
	public static void main(String[] s)
	{
		//Declarare variabil� referin�� de tipul clasei r�d�cin�
		Fruct of;
		//Alocare referin�� utiliz�nd constructorul unei subclase
		//a clasei r�d�cin� (Para)
		of=new Para(1,2.75,3);
		System.out.println("Para ...creata ca referinta Fruct");
		//Utilizare, de fapt, �n spirit polimorfic
		//a variabilei definite �i alocate mai sus
		System.out.println("Tip fruct:"+of.consultaTipFruct());
		//Alocare referin�� utiliz�nd constructorul unei subclase
		//a clasei r�d�cin� (Portocala)
		of=new Portocala(2,0.75,4);
		System.out.println("Portocala ...creata ca referinta Fruct");
		//Utilizare, de fapt, �n spirit polimorfic
		//a variabilei definite si alocate mai sus
		System.out.println("Tip fruct:"+of.consultaTipFruct());
	}
};