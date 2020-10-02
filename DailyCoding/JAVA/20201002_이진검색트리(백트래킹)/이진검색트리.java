//package com.yujin;
import java.io.*;
import java.util.*;

public class Main {
	//static private final String INPUT="C:/spring_workspace/DailyCodingJAVA/input/Main_5639.txt";	
	static ArrayList<Integer> arr;
	static StringBuilder sb=new StringBuilder();
	static void post(int rt,int lst) {
		if(rt>lst) return; 
		int mx=mxidx(rt,lst);
		//int ll=lst;
		post(rt+1,mx);//left에 대해서 먼저 실행하고
		post(mx+1,lst);//right에 대해서 실행하기
		sb.append(arr.get(rt)).append("\n");
	}
	static int mxidx(int rt,int lst) {//left인 인덱스의 끝
		for(int i=rt+1;i<=lst;i++) {
			if(arr.get(rt)<arr.get(i)) {
				return i-1;
			}
		}
		return lst;
	}
	public static void main(String[] args) throws Exception{
		//FileInputStream fs=new FileInputStream(INPUT);
		//System.setIn(fs);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		arr=new ArrayList<Integer>();
		
		String tmp=br.readLine();
		while(tmp!=null) {
			arr.add(Integer.parseInt(tmp));
			tmp=br.readLine();
		}
		post(0,arr.size()-1);
		System.out.println(sb);
	}

}
