package com.yujin;

import java.util.*;
public class Hashmaptest {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<Integer,ArrayList<Integer>> m=new HashMap<Integer,ArrayList<Integer>>();
		ArrayList<Integer> hi= new ArrayList<>();
		for(int i=0;i<5;i++){
			hi.add(i);
		};
		ArrayList<Integer> hi2= new ArrayList<Integer>();
		for(int i=3;i<7;i++){
			hi2.add(i);
		};
		m.put(1,hi);
		m.put(2,hi2);
		for(int i:m.keySet()) {
			ArrayList<Integer> a=m.get(i);
			for(int j=0;j<a.size();j++) {
				System.out.print(a.get(j)+" ");
			}System.out.println("\n");
		}
		return;
	}

}
