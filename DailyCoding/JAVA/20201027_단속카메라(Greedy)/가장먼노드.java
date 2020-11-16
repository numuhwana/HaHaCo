import java.util.*;

class Solution {
    static class block implements Comparable<block>{
        int val;
        int cnt=0;
        @Override
        public int compareTo(block a){
            return this.cnt-a.cnt;
        }
    }
    public int solution(int n, int[][] edge) {
        int answer = 0;
        boolean visit[]=new boolean[n+1];
        boolean graph[][]=new boolean[n+1][n+1];
        for(int i=0;i<edge.length;i++){
            graph[edge[i][0]][edge[i][1]]=true;
            graph[edge[i][1]][edge[i][0]]=true;
        }
       // PriorityQueue<block> q=new PriorityQueue<>();
        Queue<block> q=new LinkedList<>();// -> 이게 더 효율이 좋음
        block cur=new block();
        cur.val=1;
        cur.cnt=1;
        visit[1]=true;
        q.offer(cur);//1부터 시작
        int nwcnt=0;
        while(!q.isEmpty()){
            cur=q.poll();
            if(nwcnt!=cur.cnt){
                //System.out.println(cur.val+"(cnt):"+(q.size()+1));
                answer=q.size()+1;//현재 카운트에 1추가
                nwcnt=cur.cnt;
            }
            for(int i=1;i<=n;i++){
                if(!visit[i] && graph[cur.val][i]){//연결 여부와 방문 했는지 확인
                    visit[i]=true;
                    block nwb=new block();
                    nwb.val=i;
                    nwb.cnt=cur.cnt+1;
                    //System.out.println(cur.val+":"+i+","+nwb.val+","+nwb.cnt);
                    q.offer(nwb);
                }
            }
        }
        return answer;
    }
}