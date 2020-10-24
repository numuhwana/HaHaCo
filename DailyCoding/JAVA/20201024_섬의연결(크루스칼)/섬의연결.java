import java.util.*;

class Solution {
    static class block implements Comparable<block>{
        int x;
        int y;
        int w;
        @Override
        public int compareTo(block b){
            return this.w-b.w;
        }
    }
    static public int getParent(int parent[], int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent,parent[x]);
}
static public boolean isConnected(int parent[],int x,int y){
    x=getParent(parent,x);
    y=getParent(parent,y);
    if(x==y) return true;
    return false;
}
static public void Union(int parent[],int x,int y){
    x=getParent(parent,x);
    y=getParent(parent,y);
    if(x<y) parent[y]=x;
    else parent[x]=y;
}
    public int solution(int n, int[][] costs) {
        int answer = 0;
        int parent[]=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        PriorityQueue<block> q=new PriorityQueue<>();
        for(int i=0;i<costs.length;i++){
            block b=new block();
            b.x=costs[i][0];
            b.y=costs[i][1];
            b.w=costs[i][2];
            q.offer(b);
        }
        while(!q.isEmpty()){
            block cur=q.poll();
            if(!isConnected(parent,cur.x,cur.y)){
                 Union(parent,cur.x,cur.y);
                answer+=cur.w;
            }
        }
        return answer;
    }
}