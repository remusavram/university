//Clasa de baza
//Modeleaz� inform�ional obiectul Fruct
//Metoda consultaTipFruct() se va redefini
//in descendentul Para


class Fruct
{
	private int tipfruct;
	Fruct(int t)
	{
		tipfruct=t;
		System.out.println("Constructor Fruct...");
	}
	int consultaTipFruct()
	{
		return tipfruct;
	}
}