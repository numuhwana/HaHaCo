package com.yujin;

import java.util.*;
public class Maintest {

	private static int[] answers={1,2,3,4,5};

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Solution sol=new Solution();
//		String bg="hit";
//		String tar="cog";
//		String[] words= {"hot", "dot", "dog", "lot", "log"};
//		System.out.println(sol.solution(bg,tar,words));
		
		//uppercase
		String s="a...bcd__df s0...3459..daf";
		System.out.println(s.toUpperCase());
		//lowercase
		String S="ABCEDFS";
		System.out.println(S.toLowerCase());
		
		StringBuilder sb=new StringBuilder(s);
		sb.setCharAt(2, 'Z');
		s=sb.toString();
		System.out.println(sb.toString());
		
		//String에서 숫자를 a로 바꿔주기
		//String s="abcd__dfs345daf";
		
		for(int i=0;i<s.length();i++) {
			if(48<=s.charAt(i) && s.charAt(i)<=57 ) {
				sb.setCharAt(i, 'a');
			}
		}
		s=sb.toString();
		System.out.println(s);
		s.trim();
		s=s.replaceAll("a", "");
		s=s.replaceAll("_", "");
		s=s.replace("dd", "d");
		//s=s.replaceAll("\\ ", "");
		System.out.println("=====");
		System.out.println(s);
		
		System.out.println(s.replace("...","."));
		//sb=new StringBuilder(s);
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='.') {
				int j=i;
				while(s.charAt(j)=='.') {
					j++;
				}
				s=s.replace(s.substring(i,j),".");
				//System.out.println("="+s);
				
			}
		}
		//System.out.println(s.replaceAll("[...]", "."));
		System.out.println(s);
		
	}
		

}
