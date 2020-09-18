import java.util.*;
class Solution {
    int answer = 0;
    static class pos{
        public String s;
        public int cnt;
        public boolean visit[];
        public pos(int size){
            visit= new boolean[size];
        }
        public pos(){
        }
    }
    int comp(String a, String b){//단어의 유사도
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)==b.charAt(i)){
                cnt++;
            }
        }
        return a.length()-cnt;
    }
    public int solution(String begin, String target, String[] words) {
        Queue<pos> q=new LinkedList<pos>();
        pos cur=new pos(words.length);
        cur.s=begin;
        cur.cnt=0;
        q.offer(cur);
        while(!q.isEmpty()){
            cur=q.poll();
            if(cur.s.equals(target)){
                answer=cur.cnt;
                break;
            }
            for(int i=0;i<words.length;i++){
                if(!cur.visit[i] && comp(cur.s,words[i])==1){//방문을 한적이 없고 비교했을때 단어 1개만
                    pos nw=new pos();
                    nw.s=words[i];
                    nw.cnt=cur.cnt+1;
                    nw.visit=cur.visit;
                    nw.visit[i]=true;
                    q.offer(nw);
                }
            }
        }
        return answer;
    }
}