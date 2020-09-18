package com.yujin;

import java.util.*;
class Test1 {
    int size=0;
    int target2=0;
    int cnt=0;
    int[] numbers2={};
    public void dfs(ArrayList<Boolean> a){
        if(a.size()==size){
            int sum=0;
            for(int i=0;i<a.size();i++){
               if(a.get(i)){
                   sum=sum+numbers2[i];
               } else{
                   sum=sum-numbers2[i];
               }
            }
            if(sum==target2) cnt++;
        }else{
            a.add(true);//덧셈
            dfs(a);
            a.remove(a.size()-1);
            a.add(false);//뺄셈
            dfs(a);
            a.remove(a.size()-1);
        }
    }
    public int solution(int[] numbers, int target) {
        int answer = 0;
        target2=target;
        size=numbers.length;
        numbers2=numbers;
        ArrayList<Boolean> s=new ArrayList<Boolean>();
        dfs(s);
        answer=cnt;
        return answer;
    }
}