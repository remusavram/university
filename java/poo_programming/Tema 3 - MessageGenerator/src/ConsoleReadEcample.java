import java.util.Scanner;
			
public class ConsoleReadEcample
{
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("Primu operand: ");
		int num1=scan.nextInt();
		System.out.println("Al doilea operand: ");
		int num2=scan.nextInt();
		int num3=num1+num2;
		System.out.println("Suma este: "+num3);		
	}
}
