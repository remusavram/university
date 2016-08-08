import java.util.Scanner;

public class jhf {
	public static void main(String[] args) 
		
	{
		
		Scanner sc=new Scanner(System.in);
		
		
		int n=sc.nextInt();
		
		int[][] a=new int[n][];
		for(int i=0;i<a.length;i++)
			{System.out.print("m=");
			int m=sc.nextInt();
			a[i]=new int[m];
			for(int j=0;j<m;j++)
			{
				System.out.print("a["+i+"]["+j+"]=");
				a[i][j]=sc.nextInt();
			}
			}
			int k=0,l,j;
			int [] c=new int[n];
			c[k]=a[0][0];
			if(a[1][0]>a[1][1])
				{
				c[k]=a[1][0];
				l=0;
				k++;
				}
			else
				{
				c[k]=a[1][1];
				l=1;
				k++;
				}
			int max;    
			for(int i=1;i<a.length-1;i++)
				{
				max=Integer.MIN_VALUE;
				if(a[i+1][l+1]>max)
						{
					     max=a[i+1][l+1];
					     j=l+1;
						}
				
				else
					{
					max=a[i+1][l];
					j=l;
					}
				c[k]=max;
				l=j;
				k++;
				
				}
		   for(int i=0;i<k;i++)
			   System.out.print(c[k]);
			
			
			}

}
