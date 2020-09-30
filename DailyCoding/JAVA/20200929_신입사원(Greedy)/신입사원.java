//package com.yujin;
import java.io.*;
import java.util.*;

public class Main {
	//static private final String INPUT="C:/spring_workspace/DailyCodingJAVA/input/Main_1946.txt";
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//FileInputStream fs=new FileInputStream(INPUT);
		//System.setIn(fs);
		//////
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		StringBuilder sb=new StringBuilder();
		int TC=Integer.parseInt(st.nextToken());
		
		for(int t=0;t<TC;t++) {
			int n;
			st=new StringTokenizer(br.readLine());
			n=Integer.parseInt(st.nextToken());
			//Queue<per> q=new LinkedList<per>();
			int arr[]=new int[n+1];
			for(int i=0;i<n;i++) {
				st=new StringTokenizer(br.readLine());
				arr[Integer.parseInt(st.nextToken())]=Integer.parseInt(st.nextToken());
			}
			int mx=arr[1];
			for(int i=2;i<arr.length;i++) {
				if(mx<arr[i]) n--;
				else mx=arr[i];
			}
			sb.append(n).append("\n");
		}
		System.out.println(sb);
		
	}

}
