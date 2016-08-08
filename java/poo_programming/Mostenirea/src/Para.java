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
	double consultaGreutate()
	{
		return greutate;
	}
	int consultaForma()
	{
		return forma;
	}
}