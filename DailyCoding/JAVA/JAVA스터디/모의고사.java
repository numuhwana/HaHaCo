package com.yujin;

import java.util.*;
class Solution {
    int one[]={1,2,3,4,5};
    int two[]={2,1,2,3,2,4,2,5};
    int three[]={3,3,1,1,2,2,4,4,5,5};
    public int[] solution(int[] answers) {
        int[] answer = {};
        int cnt[]={0,0,0};
        for(int i=0;i<answers.length;i++){
            if(one[(i%5)]==answers[i]) cnt[0]++;
            if(two[(i%8)]==answers[i]) cnt[1]++;
            if(three[(i%10)]==answers[i]) cnt[2]++;
        }
        int hi=0;
        int howmany=0;
        List arr=new ArrayList<Integer>();
        for(int i=0;i<3;i++){
            if(cnt[i]>hi){
                howmany=1;
                hi=cnt[i];
                arr.clear();
                arr.add(i+1);
            }else if(cnt[i]==hi){ howmany++;
                                 arr.add(i+1);
                                }
        }
        if(howmany>2){
            Collections.sort(arr);
        }
        answer=new int[arr.size()];
        for(int i=0;i<arr.size();i++){
            answer[i]=(int)arr.get(i);
        }
        return answer;
    }
}