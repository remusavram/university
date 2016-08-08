class Fruct
{
	private int tipfruct;
	Fruct(int t)
	{
		tipfruct=t;
		System.out.println("Constructor Fruct...");
	}
	final int consultaTipFruct()
	{
		return tipfruct;
	}
}
