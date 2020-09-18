//package com.yujin;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int[][] arr;
	static boolean[] team;
	static int mini=Integer.MAX_VALUE;
	public static void dfs(int cur,int count) {
		if(count==n/2) {
			cal();
		}else {
			for(int i=cur;i<=n;i++) {
				team[i]=true;
				dfs(i+1,count+1);
				team[i]=false;
			}
		}
		
	}
	public static void cal() {
		int st[]=new int[n/2];
		int lk[]=new int[n/2];
		int sidx=0;
		int lidx=0;
		for(int i=1;i<=n;i++) {
			if(team[i]) {
				lk[lidx++]=i;
			}else {
				st[sidx++]=i;
			}
		}
		int stsum=0;
		int lksum=0;
		for(int i=0;i<n/2;i++) {
			for(int j=i+1;j<n/2;j++) {
				stsum+=arr[st[i]][st[j]]+arr[st[j]][st[i]];
				lksum+=arr[lk[i]][lk[j]]+arr[lk[j]][lk[i]];
			}
		}
		mini=Math.min(mini,Math.abs(stsum-lksum));
	}
	//static String INPUT="C:/spring_workspace/DailyCodingJAVA/input/Main_14889.txt";
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
//		FileInputStream fs=null;
//		try {
//			fs=new FileInputStream(INPUT);
//			System.setIn(fs);
//		}catch(Exception e) {
//			
//		}
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		n=Integer.parseInt(st.nextToken());
		arr=new int[n+1][n+1];
		team=new boolean[n+1];
		for(int i=1;i<=n;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=1;j<=n;j++) {
				 arr[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		dfs(1,0);
		
		StringBuilder sb=new StringBuilder();
		sb.append(mini).append("\n");
		System.out.println(sb);
	}

}
