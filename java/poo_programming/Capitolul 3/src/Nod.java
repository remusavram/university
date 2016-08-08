
public class Nod 
{
	private int Data;
	private Nod Urmator;
	
	//constructor
	public Nod(int Numar)
	{
		Data=Numar;
	};
	//modificator atribut Data
	public void setareData(int nr)
	{
		Data=Numar;
	};
	
	//selector atribur Data
	public int consultareData()
	{
		return Data;
	};
	
	//Modificator dtribut urmator
	public void setUrmator(Nod Element)
	{
		Urmatorul=Element;
	};
	
	//Selector atribut Urmatorul
	public Nod consultaUrmator()
	{
		return Urmatorul
	};
};

//Specificare aproape completa a clasei abstracte Lista
abstract class Lista
{
	private Nod AStart;
	private Nod Aultim;
	private int NrElem;
}
