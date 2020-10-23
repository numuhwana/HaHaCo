package com.yujin;

public class MSTPractice {

	static public void union(int parent[], int a,int b ) {
		a=findParent(parent,a);
		b=findParent(parent,b);
		if(a<b) parent[b]=a;
		else parent[a]=b;
	}
	static public int findParent(int parent[],int x) {
		if(parent[x]==x) return x;
		return parent[x]=findParent(parent,parent[x]);
	}
	static public boolean connected(int parent[],int a,int b) {
		a=findParent(parent,a);
		b=findParent(parent,b);
		if(a==b) return true;
		else return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int parent[]= {0,1,2,3,4,5,6};
		union(parent,0,1);
		union(parent,1,2);
		union(parent,0,5);
		union(parent,3,6);
		union(parent,6,4);
		
		StringBuilder sb=new StringBuilder();
		sb.append("3과 5는 같은 그래프에 있을까요?").append(connected(parent,3,5)).append("\n");
		System.out.println(sb);
		System.out.print("parent: ");
		for(int i=0;i<7;i++) {
			System.out.print(parent[i]+" ");
		}System.out.println("\n");
		
		union(parent,3,1);
		sb=new StringBuilder();
		sb.append("1과 6는 같은 그래프에 있을까요?").append(connected(parent,1,6)).append("\n");
		System.out.println(sb);
		System.out.print("parent: ");
		for(int i=0;i<7;i++) {
			System.out.print(parent[i]+" ");
		}System.out.println("\n");
	}

}
