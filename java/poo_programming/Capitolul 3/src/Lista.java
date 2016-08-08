//Specificare aproape completa a clasei abstracte Lista
abstract class Lista
{
	private Nod AStart;
	private Nod AUltim;
	private int NrElem;


	//Modificator atribut AStart;
	public Nod consultaAStart()
	{
		return AStart;
	};
	
	// Modificator atribut NrElem
	public void consultaNrElem(int nr)
	{
		NrElem=nr;
	};
	
	//Selector atribut NrElem
	public int consultaNrElem()
	{
		return NrElem;
	};
	
	//Modificator atribut AUltim
	public void stareAUltim(Nod Element)
	{
		AUltim=Element;
	};
	
	//Selector atribut AUltim
	public Nod consultaAUltim()
	{
		return AUltim;
	};
	
	public abstract void insereazaDNod(Nod Element);
	public abstract void insereazaINod(Nod Element);
	public abstract void stergeNodAdr(Nod element);
	public abstract void stergeNodNum(int Nr);
	public final void salveazaInFisier(char numef[])
	{
		System.out.println("Neimplementata...");
	};
	public final Nod incarcaDinFisier(char numef[])
	{
		System.out.println("Neimplementata..");
		return null;
	};
}
