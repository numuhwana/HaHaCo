package com.yujin;
import java.io.*;
import java.util.*;
public class Main_16398 {
static class con implements Comparable<con>{
	int x;
	int y;
	int w;
	@Override
	public int compareTo(con b) {
		return this.w-b.w;//positive면 자리바꿈
	}
}
static private int getParent(int parent[],int x) {
	if(parent[x]==x) return x;
	return parent[x]=getParent(parent,parent[x]);
}
static private void union(int parent[],int x,int y) {
	x=getParent(parent,x);
	y=getParent(parent,y);
	if(x>y) parent[x]=y;
	else parent[y]=x;
}
static private boolean isConnected(int parent[],int x,int y) {
	x=getParent(parent,x);
	y=getParent(parent,y);
	if(x==y) return true;
	return false;
}
static private PriorityQueue<con> q=new PriorityQueue<con>();

	static private String INPUT="C:/spring_workspace/DailyCodingJAVA/input/Main_16398.txt";	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		FileInputStream fs=new FileInputStream(INPUT);
		System.setIn(fs);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n=Integer.parseInt(br.readLine());
		
		int parent[]=new int[n];
		for(int i=0;i<n;i++) {
			st=new StringTokenizer(br.readLine());
			parent[i]=i;
			for(int j=0;j<n;j++) {
				int w=Integer.parseInt(st.nextToken());
				if(i<j) {
					con c=new con();
					c.x=j;
					c.y=i;
					c.w=w;
					q.offer(c);
				}
			}
		}
		long cnt=0;
		long price=0;
		while(!q.isEmpty()) {
			con cur=q.poll();
			if(!isConnected(parent,cur.x,cur.y)) {
				union(parent,cur.x,cur.y);
				cnt++;
				price+=cur.w;
			}
			if(cnt==n) break;
			
		}
		System.out.println(price);
		
	}

}
