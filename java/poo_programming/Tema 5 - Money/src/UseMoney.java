import Money.Money;
import extMoney.ExtMoney;
public class UseMoney
// A driver class using Money and ExtMoney
{
	public static void main(String[] args)
	{
		Money money1;
		Money money2;
		ExtMoney extMoney1;
		ExtMoney extMoney2;
		System.out.println("Initialized by default constructors");
		money1 = new Money();
		extMoney1 = new ExtMoney();
		System.out.println("variables instantiated");
		money1.print();
		extMoney1.print();
		System.out.println("Initialized by other constructor");
		money2 = new Money(2000, 22);
		extMoney2 = new ExtMoney(3000, 88, "monoply");
		//illustration of the polymorphism
		money2.print();
		extMoney2.print();
		System.out.println("initialized at run time");
		money1.initializare(4000, 44);
		extMoney1.initialize(5000, 99, "play");
		money1.print();
		extMoney1.print();
	}
}