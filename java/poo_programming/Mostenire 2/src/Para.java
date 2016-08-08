//Subclas� a clasei Fruct
//Para este un fruct->este respectat spiritul natural
//al mo�tenirii
//Se adaug� noi atribute informa�ionale
//Se redefine�te metoda consultaTipFruct()
//Este un exemplu clasic de specializare prin redefinire

class Para extends Fruct
{
	private double greutate;
	private int forma;
	Para(int t,double g,int f)
	{
		super(t);
		System.out.println("Constructor Para...");
		greutate=g;
		forma=f;
	}
	int consultaTipFruct()
	{
		System.out.println("Consultare tip fruct..redefinire Para");
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