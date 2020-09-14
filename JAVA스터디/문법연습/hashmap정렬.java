//https://jobc.tistory.com/176
//hash map 정렬

package com.yujin;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;

public class Hashsort {
	public static void main(String[] args) {
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		hm.put("가", 100);
		hm.put("나", 50);
		hm.put("다", 10);
		
		// 1. entryset 받아오기
		Set<Entry<String, Integer>> entry = hm.entrySet();
		
		// 2. entryset으로 arraylist 만들기
		ArrayList<Entry<String, Integer>> list = new ArrayList<Entry<String, Integer>>(entry);

		// 3. comparator 만들어서 sort하기 - 이때 정렬 기준 설정(value 오름차순)
		Collections.sort(list, new Comparator<Entry<String, Integer>>() {
			@Override
			public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
				return o1.getValue() - o2.getValue();
			}
		}); 
		
		for (Entry<String, Integer> e : list) {
			System.out.println(e);
		}
	}
}