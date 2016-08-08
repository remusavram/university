public class TestInterf
{
	public static void main(String args[])
	{
		//Crearea unui obiect de tip I1
		//utilizand clasa A
		I1 ob1=new A();
		System.out.println("Ura...");
		//Utilizarea obiectului de tip I1
		ob1.f1();
		//Crearea unui obiect de tip I12
		//utilizand clasa C
		I12 ob12=new C();
		//Utilizarea obiectului de tip I12
		ob12.f1();
		ob12.f2();
		ob12.f3();
		//Crearea unui obiect de tip I1
		//utilizand clasa C
		I1 ob2=new C();
		//Utilizare obiect de tip I1
		//creat cu suport C
		ob2.f1();
		//Down casting dirijat de
		//interfete
		ob2=(I1)ob12;
		ob2.f1();
	}
}