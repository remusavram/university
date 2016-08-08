package fractie;

public class Fractie 
{
	 private int numarator;
	 private int numitor;

	public Fractie()
	{
		numarator=0;
		numitor=0;
	}

	public Fractie(int intnumarator,int intnumitor)
	{
		numarator=intnumarator;
		numitor=intnumitor;
	}
	public int getNumarator()
	{
		return numarator;
	}
	public int getNumitor()
	{
		return numitor;
	}
	public Fractie adunare(Fractie a)
	{
		Fractie rezultat=new Fractie();
		rezultat.numarator=(numarator*(cmmmc(numitor,a.numitor)/numitor)) + (a.numarator*(cmmmc(numitor,a.numitor)/a.numitor));
		rezultat.numitor=cmmmc(numitor,a.numitor);
		
		return rezultat;
	}
	public Fractie scadere(Fractie a)
	{
		Fractie rezultat=new Fractie();
		rezultat.numarator=(numarator*(cmmmc(numitor,a.numitor)/numitor)) - (a.numarator*(cmmmc(numitor,a.numitor)/a.numitor));
		rezultat.numitor=cmmmc(numitor,a.numitor);
		
		return rezultat;
	}
	public Fractie inmultire(Fractie a)
	{
		Fractie rezultat=new Fractie();
		rezultat.numarator=numarator * a.numarator;
		rezultat.numitor=numitor * a.numitor;
		return rezultat;
	}
	public Fractie impartire(Fractie a)
	{
		Fractie rezultat=new Fractie();
		rezultat.numarator=numarator * a.numitor;
		rezultat.numitor=numitor * a.numarator;
		return rezultat;
	}
	public void AfisareFractie()
	{
		System.out.println("Fractia este: " + getNumarator() + "/" + getNumitor());
	}
	public int cmmmc(int a, int b)
	{
		int p=a*b;
		while (a!=b)
		{
		if(a>b)
			a=a-b;
		else
		    b=b-a;
		}
		return p/b;
	}
}
