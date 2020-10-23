import java.io.*;
import java.util.*;
public class Main_16202 {
		static class con implements Comparable<con>{
		int x;
		int y;
		int w;
		@Override
		public int compareTo(con b) {
			return this.w-b.w;
		}
	}
	static public int getParent(int parent[],int x) {
		if(parent[x]==x) return x;
		return parent[x]=getParent(parent,parent[x]);
	}
	static public void union(int parent[],int x, int y) {
		x=getParent(parent,x);
		y=getParent(parent,y);
		if(x<y) parent[y]=x;
		else parent[x]=y;
	}
	static public boolean isConnected(int parent[],int x,int y) {
		x=getParent(parent,x);
		y=getParent(parent,y);
		if(x==y) return true;
		return false;
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		FileInputStream fs=new FileInputStream(INPUT);
		System.setIn(fs);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		int N=Integer.parseInt(st.nextToken());
		int M=Integer.parseInt(st.nextToken());
		int K=Integer.parseInt(st.nextToken());
		StringBuilder sb=new StringBuilder();
		
		int parent[]=new int[N+1];
		PriorityQueue<con> q=new PriorityQueue<con>();
		PriorityQueue<con> tmp=new PriorityQueue<con>();
		
		for(int i=1;i<=N;i++) {
			parent[i]=i;
		}
		for(int i=1;i<=M;i++) {
			st=new StringTokenizer(br.readLine());
			con c=new con();
			c.x=Integer.parseInt(st.nextToken());
			c.y=Integer.parseInt(st.nextToken());
			c.w=i;
			tmp.offer(c);
		}
		int cnt;
			for(int i=0;i<K;i++) {//횟수
				cnt=1;
				q.clear();
				q.addAll(tmp);
				int total=0;
				parent=new int[N+1];
				for(int z=1;z<=N;z++) {
					parent[z]=z;
				}
				while(!q.isEmpty()) {
					con cur=q.poll();
					if(!isConnected(parent,cur.x,cur.y)) {
						union(parent,cur.x,cur.y);
						cnt++;
						total+=cur.w;
					}
					if(cnt==N) break;
				}
				if(cnt!=N) {
					for(int j=i;j<K;j++) {
						sb.append(0).append(" ");
					}
					break;
				}else {
					sb.append(total).append(" ");
				}
				tmp.poll();
			}
		
		System.out.println(sb);
		
	}

}
