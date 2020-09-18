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
		HashMap<String,Integer> m=new HashMap<String,Integer>();
		m.put("안녕",12);
		m.put("그래",13);
		m.put("녕",15);
		m.put("래",14);
		Iterator it=m.keySet().iterator();
		while(it.hasNext()) {
			String s=(String)it.next();
			if(s.contains("그")) {
				m.remove(s);
				it=m.keySet().iterator();
			}
		}
		TreeMap<String,Integer> m2=new TreeMap<String,Integer>(Collections.reverseOrder());
		
		
		for(String k:m2.keySet()) {
			System.out.println(k);
		}
		

}
