public class Mosten1
{
	public static void main(String[] s)
	{
		//Declarare variabil� referin��
		//av�nd tipul clasei r�d�cin�
		Fruct of;
		//Declarare �i alocare variabil� referin��
		//de tip Para
		Para obpara=new Para(1,1.5,2);
		//Declarare �i alocare variabil� referin��
		//de tip Portocala
		Portocala obport=new Portocala(10,1);
		//Utilizare normal� a variabilei de tip Para
		System.out.println("Para ..creata ca referinta Para");
		System.out.println("Tip fruct:"+ obpara.consultaTipFruct());
		System.out.println("Greutate fruct:"+obpara.consultaGreutate());
		System.out.println("Forma fruct:"+obpara.consultaForma());
		//Utilizare normala a variabilei de tip Portocala
		System.out.println("Portocala creata ca referinta Portocala");
		System.out.println("Tip fruct:"+obport.consultaTipFruct());
		System.out.println("Tip coaja:"+obport.consultaTipCoaja());
		//Exemplu de Up casting (implicit)
		of=new Para(1,2.5,3);
		//Exemplu de Down casting (explicit);
		//Foarte util in programarea generica
		obpara=(Para)of;
		//Utilizare variabile referin��
		//setate prin casting explicit
		System.out.println("Para ...creata ca referinta Fruct");
		System.out.println("Tip fruct:"+obpara.consultaTipFruct());
		System.out.println("Greutate fruct:" +obpara.consultaGreutate());
		System.out.println("Forma fruct:"+obpara.consultaForma());
	}
};