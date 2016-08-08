//Subclas� a clasei Fruct
//Portocala este un fruct->este respectat spiritul natural
//al mo�tenirii
//Se adaug� noi atribute informa�ionale
//Se redefine�te metoda consultaTipFruct()
//Este un exemplu clasic de specializare prin redefinire



class Portocala extends Fruct
{
	private double greutate;
	private int forma;
	Portocala(int t,double g,int f)
	{
		super(t);
		System.out.println("Constructor Portocala...");
		greutate=g;
		forma=f;
	}
	int consultaTipFruct()
	{
		System.out.println("Consultare tip fruct..redefinire Porto");
		return super.consultaTipFruct();
	}
	double consultaGreutate()
	{
		return greutate;
	}
	int consultaForma()
	{
		return forma;
	}
}