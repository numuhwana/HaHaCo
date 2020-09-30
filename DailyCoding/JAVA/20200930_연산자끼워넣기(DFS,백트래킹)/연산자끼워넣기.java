//package com.yujin;
import java.io.*;
import java.util.*;

public class Main {
	//static private final String INPUT="C:/spring_workspace/DailyCodingJAVA/input/Main_14888.txt";
	static int comp[]=new int[4];//연산자
	static int arr[];
	static long mx=Long.MIN_VALUE;
	static long mn=Long.MAX_VALUE;
	static int n=0;
	public static void dfs(int cur,long res) {
		if(cur==n) {
			mx=(long)Math.max(res, mx);
			mn=(long)Math.min(res, mn);
		}else {
			for(int i=0;i<4;i++) {
				if(comp[i]>0) {
					comp[i]--;
					switch(i) {
					case 0://
						res+=arr[cur];
						dfs(cur+1,res);
						res-=arr[cur];
						break;
					case 1:
						res-=arr[cur];
						dfs(cur+1,res);
						res+=arr[cur];
						break;
					case 2:
						res*=arr[cur];
						dfs(cur+1,res);
						res/=arr[cur];
						break;
					case 3:
						res/=arr[cur];
						dfs(cur+1,res);
						res*=arr[cur];
						break;
					}
					comp[i]++;
				}
			}
		}
	}
	public static void main(String[] args) throws Exception{
		//FileInputStream fs=new FileInputStream(INPUT);
		//System.setIn(fs);
		///
		//System.out.println(-10/3+"");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		st=new StringTokenizer(br.readLine());
		
		arr=new int[n];//숫자
		for(int i=0;i<n;i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<4;i++) {
			comp[i]=Integer.parseInt(st.nextToken());
		}
		long res=arr[0];
		dfs(1,res);
		StringBuilder sb=new StringBuilder();
		sb.append(mx).append("\n").append(mn).append("\n");
		System.out.println(sb);
	}

}
