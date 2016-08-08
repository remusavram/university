//Clasa C implementeaza interftata I12
//Evident,functiile expuse de interfetele
//I1 si I2 sunt implementate si de catre
//clasa C
//Deoarece I12 este derivata din I1 si I2
//ni se ingaduie sa privim instantele de tip
//I12 ca fiind de tip I1 sau I2, dupa cum
//este in interesul nostru


class C implements I12
{
	public C()
	{
		System.out.println("CCCC...");
	};
	public void f3()
	{
		System.out.println("f3...");
	};
	public void f1()
	{
		System.out.println("f1....");
	};
	public void f2()
	{
		System.out.println("f2....");
	};
};