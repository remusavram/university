import java.util.*;
import java.io.*;


public class algoritm_Floyd_Warshall {
	public static void main(String[] args)throws IOException {
		Scanner sc=new Scanner(new FileReader("date2.txt"));
		int n=sc.nextInt();
		int m=sc.nextInt();
		int[][]d=new int[n][n];
		int[][]p=new int[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i==j)
					d[i][j]=0;
				else
					d[i][j]=100000;
		for(int i=0;i<m;i++){
			int x=sc.nextInt();
			int y=sc.nextInt();
			int dist=sc.nextInt();
			d[x][y]=dist;
			p[x][y]=x;
		}
		int temp=0;
		for(int k=0;k<n;k++)
		{
			temp++;
			System.out.println();
			System.out.printf("%d",temp);
			System.out.println("\n");
			System.out.printf("Matricea D:");
			System.out.println();
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					if(d[i][j]<100000)
						System.out.printf("%8d",d[i][j]);
					else
						System.out.print(" infinit");
				System.out.println();
			}
			System.out.println();
			System.out.println();
			System.out.printf("Matricea P:");
			System.out.println();
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					System.out.printf("%8d",p[i][j]);
				System.out.println();
			}
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						if(d[i][k]+d[k][j]<d[i][j]){
							p[i][j]=p[k][j];
							d[i][j]=d[i][k]+d[k][j];
						}
					}
		System.out.println();
		System.out.print("Matricea D finala:");
		System.out.println();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				if(d[i][j]<100000)
					System.out.printf("%8d",d[i][j]);
				else
					System.out.print(" infinit");
			System.out.println();
		}
		System.out.println();
		System.out.print("Matricea P finala:");
		System.out.println();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				System.out.printf("%8d",p[i][j]);
			System.out.println();
		}
	}
}
