class Portocala extends Fruct
{
	private int tipcoaja;
	Portocala(int tf,int tc)
	{
		super(tf);
		System.out.println("Constructor Para2...");
		tipcoaja=tc;
	}
	int consultaTipCoaja()
	{
		return tipcoaja;
	}
}