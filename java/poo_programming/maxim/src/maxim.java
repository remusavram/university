import java.util.*;

public class maxim {
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
			int k=0;
			int [] c=new int[n];
			c[k]=a[0][0];
			if(a[1][0]>a[1][1])
				{
				c[k]=a[1][0];
				k++;
				}
			else
				{
				c[k]=a[1][1];
				k++;
				}
			int max;    
			for(int i=2;i<a.length;i++)
				{
				max=Integer.MIN_VALUE;
				for(int j=i-1;j<=i+1;j++)
				
					if(a[i][j]>max)
						max=a[i][j];
				c[k]=max;
				k++;
				}
		   for(int i=0;i<k;i++)
			   System.out.print(c[k]);
			
			
			}

}