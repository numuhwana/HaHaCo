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
		Set<String> s=new HashSet<String>();
		s.add("a");
		s.add("b");
		s.add("c");
		s.add("d");
		Iterator<String> it=s.iterator();
		while(it.hasNext()) {
			String cur=it.next();
			//System.out.println(cur);
			if(cur.equals("b")) {
				it.remove();
			}
			//it=s.iterator();
		}
	}

}
