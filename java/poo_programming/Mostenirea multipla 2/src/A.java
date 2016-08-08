//A foloseste interfata IConst
//Este obligata sa implementeze ftest()

class A implements IConst
{
	A()
	{
		System.out.println("Constructor..");
	};
	public void ftest()
	{
		System.out.println("ftest() la lucru...");
	};
}