import java.util.*;
import java.io.*;
public class Main{
	static class ch implements Comparable<ch>{
		int x;
		int y;
		int cnt=1;
		@Override
		public int compareTo(ch b) {
			return this.cnt-b.cnt;//cnt가 작은게 앞으로가기
		}
	}
	static int xx[]= {0,1,0,-1};
	static int yy[]= {-1,0,1,0};
	static int n=0,m=0;
	static int arr[][];
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		
		PriorityQueue<ch> q=new PriorityQueue<ch>();
		Queue<ch> air=new LinkedList<ch>();
		
		arr=new int[n][m];
		for(int i=0;i<n;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				if(arr[i][j]==1) {//모두 넣기
					ch nw=new ch();
					nw.x=j;
					nw.y=i;
					q.offer(nw);
				}else {
					if(i==0 || i==n-1 || j==0 || j==m-1) {
						arr[i][j]=3;
						ch a=new ch();
						a.x=j;
						a.y=i;
						air.offer(a);
					}
				}
			}
		}
		ch cur=null;
		int mx=0;
		int allcnt=0;
		int tmp[][]=new int[n][m];
		while(!q.isEmpty()) {//치즈에 대해서
			cur=q.poll();
			if(cur.cnt>mx) {//다음 카운트가 존재하는경우
				mx=cur.cnt;
				outside(air);//공기에 대해서
				copy(arr,tmp);//이전 tmp
				allcnt=q.size()+1;
			}
			boolean cnt=false;
			for(int i=0;i<4;i++) {
				int nx=cur.x+xx[i];
				int ny=cur.y+yy[i];
				if(nx>=0 &&ny>=0 && nx<m && ny<n) {
					if(tmp[ny][nx]==3) {//한면이라도 바깥공기라면
					cnt=true;
					break;
					}
				}
			}
			if(!cnt) {
				cur.cnt=cur.cnt+1;
				q.offer(cur);
			}else {
				arr[cur.y][cur.x]=3;
				air.offer(cur);//현재 치즈였던거는 공기가 됨
			}
		}
		StringBuilder sb=new StringBuilder();
		sb.append(mx).append("\n").append(allcnt).append("\n");
		System.out.println(sb);
	}
	public static void copy(int arr[][],int tmp[][]) {
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[i].length;j++) {
				tmp[i][j]=arr[i][j];
			}
		}
	}
	public static void outside(Queue<ch> air) {
		ch cur;
		while(!air.isEmpty()) {
			cur=air.poll();
			arr[cur.y][cur.x]=3;
			for(int i=0;i<4;i++) {
				int nx=cur.x+xx[i];
				int ny=cur.y+yy[i];
				if(nx>=0 &&ny>=0 && nx<m && ny<n && arr[ny][nx]==0) {
					arr[ny][nx]=3;
					ch nw=new ch();
					nw.x=nx;
					nw.y=ny;
					air.offer(nw);
				}
			}
		}
	}


}
