import java.io.*;
import java.util.*;

public class Main{
	static class b{
		int x;
		int y;
	}
	
	//static boolean visit[][];
	static int arr[][];
	static int xx[]= {0,1,1,1,0,-1,-1,-1};
	static int yy[]= {-1,-1,0,1,1,1,0,-1};
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//FileInputStream fs=new FileInputStream(INPUT);
		//PrintStream ps=new PrintStream(new FileOutputStream(OUTPUT));
		//System.setIn(fs);
		//System.setOut(ps);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st=new StringTokenizer(br.readLine());
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();
		while(true) {//모든지도를 읽어올때까지
			st=new StringTokenizer(br.readLine());
			int m=Integer.parseInt(st.nextToken());
			int n=Integer.parseInt(st.nextToken());
			if(n==0 || m==0) break;
			//visit=new boolean[n][m];//visit
			arr=new int[n][m];
			for(int i=0;i<n;i++) {//입력받기
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<m;j++) {
					arr[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			
			Queue<b> q=new LinkedList<b>();
			int cnt=0;
			for(int i=0;i<n;i++) {//돌면서 땅찾기
				for(int j=0;j<m;j++) {
					if(arr[i][j]==1) {
						cnt++;
						b cur=new b();
						cur.x=j;
						cur.y=i;
						arr[i][j]=0;
						q.offer(cur);
						while(!q.isEmpty()) {
							cur=q.poll();
							for(int z=0;z<8;z++) {
								int nx=cur.x+xx[z];
								int ny=cur.y+yy[z];
								if(nx>=0 && ny>=0 && nx<m && ny<n && arr[ny][nx]==1) {
									b nw=new b();
									nw.x=nx;
									nw.y=ny;
									arr[ny][nx]=0;
									q.offer(nw);
								}
							}
						}
					}
				}
			}
			sb.append(cnt).append("\n");
		}
		System.out.println(sb);
	}

}
