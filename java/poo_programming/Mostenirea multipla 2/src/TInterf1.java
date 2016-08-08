public class TInterf1
{
	public static void main(String s[])
	{
		//Creare variabila obiect
		//de tip A
		//se mostenesc constantele
		//interfetei IConst
		A va=new A();
		System.out.println(va.Numar);
		System.out.println(va.s);
		va.ftest();
		//Creare variabila obiect
		//de tip IConst
		IConst iva=new A();
		System.out.println(iva.Numar); 
		System.out.println(iva.s);
		iva.ftest();
	};
}