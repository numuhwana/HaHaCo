import java.util.*;
class Solution {
    int[][] comp2;
    int n2=0,cnt=0;
     boolean visit[];
    void bfs(int num1){
        cnt++;
        Queue<Integer> q=new LinkedList<Integer>();
        q.offer(num1);
        visit[num1]=true;
        int cur=0;
        while(!q.isEmpty()){
            cur=q.poll();
            //System.out.println(cur);
            for(int i=0;i<comp2[cur].length;i++){
                if(comp2[cur][i]==1 && !visit[i]){
                    visit[cur]=true;
                    q.offer(i);
                }
            }
        }
    }
    public int solution(int n, int[][] computers) {
        n2=n;
        comp2=computers;
        visit=new boolean[n];
        for(int i=0;i<visit.length;i++){
            visit[i]=false;
        }
        for(int i=0;i<computers.length;i++){
            if(!visit[i]){
                bfs(i);
            }
        }
        return cnt;
    }
}