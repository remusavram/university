package Money;

public class Money 
{
	public final static char SYMBOL='$';
	private long dollars;
	private long cents;
	
	public Money()
	{
		dollars=0;
		cents=0;
	}
	
	public Money(long initDollars, long initcents)
	{
		dollars= initDollars;
		cents= initcents;
	}
	
	public void initializare(long newDollars, long newcents)
	{
		dollars=newDollars;
		cents=newcents;
	}

	public long dollarsAre()
	{
		return dollars;
	}
	
	public long centsAre()
	{
		return cents;
	}
	
	public void print()
	{
		System.out.print("" + SYMBOL + dollars + '.' + cents);
	}
	
	public Money add(Money value)
	{
		Money result=new Money();
		result.cents=cents + value.cents;
		result.dollars=dollars + value.dollars;
		if(result.cents>100)
		{
			result.cents=result.cents-100;
			result.dollars++;
		}
		return result;
	}
}
