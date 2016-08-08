import java.util.*;
import java.io.*;

public class Dikstra {
	public static void drum(int[] p, int s, int i){						//functia drum
		if(s!=i && p[i]>=0)
			drum(p,s,p[i]);
		System.out.print(i+" ");
	}
	
	public static void main(String[] args)throws IOException {			// programul principal
		Scanner sc=new Scanner(new FileReader("date.txt"));
		int s=sc.nextInt();
		int n=sc.nextInt();
		int m=sc.nextInt();
		int[][]b=new int[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i==j)
					b[i][j]=0;
				else
					b[i][j]=100000;
		LinkedList<Integer>[]list=new LinkedList[n];
		for(int i=0;i<n;i++)
			list[i]=new LinkedList<Integer>();
		for(int i=0;i<m;i++){
			int x=sc.nextInt();
			int y=sc.nextInt();
			int dist=sc.nextInt();
			b[x][y]=dist;
			list[x].add(y);
		}
		boolean[] viz=new boolean[n];
		int nr =0;
		int[]d=new int[n];
		int[]p=new int[n];
		for(int i=0;i<n;i++)
		{
			d[i]=100000;
			p[i]=-1;
		}
		d[s]=0;
		while(nr<n){
			int x=0, min=Integer.MAX_VALUE;
			for(int i=0;i<n;i++)
				if(!viz[i] && d[i]<min){
					min=d[i];
					x=i;
				}
			viz[x]=true;
			nr++;
			for(int y:list[x])
				if(!viz[y] && d[x]+b[x][y]<d[y]){
					d[y]=d[x]+b[x][y];
					p[y]=x;
				}
		}
		System.out.printf("d=(");									//prima afisare
		for(int i=0;i<n;i++)
			System.out.print(d[i]+" ");
		System.out.printf(");");
		System.out.println();
		System.out.printf("p=(");
		for(int i=0;i<n;i++)
			System.out.print(p[i]+" ");
		System.out.printf(");");
		System.out.println("\n");
		
		for(int i=0;i<n;i++)										// a doua afisare
		{
			System.out.printf("Drumul de la %d la %d are costul minim %d si trece prin: ", s,i,d[i]);
			drum(p,s,i);
			System.out.println();
		}
		
	}
}
