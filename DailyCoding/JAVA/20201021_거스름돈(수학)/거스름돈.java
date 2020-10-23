package com.yujin;
import java.io.*;

public class Main_14916 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		
		int cnt=500001;
		int div=n/5;
		for(int i=0;i<=div;i++) {
			int cur=n-(5*i);
			if(cur%2==0) {
				cnt=Math.min(cnt,((cur/2)+i) );
			}
		}
		cnt=(cnt==500001?-1:cnt);
		System.out.println(cnt);
	}

}
