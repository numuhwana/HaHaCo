import java.io.*;
import java.util.*;

public class Main {
	static int graph[][];
	static int INF=1000000000;
	static int res=INF;
	public static void FloydWar() {
		for (int k = 0; k < graph.length; k++) {
			for (int i = 0; i < graph.length; i++) {
				for(int j=0;j<graph.length;j++) {
					graph[i][j]=Math.min(graph[i][k]+graph[k][j],graph[i][j]);
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		graph = new int[V+1][V+1];
		for(int i=0;i<=V;i++) {
			for(int j=0;j<=V;j++) {
				graph[i][j]=INF;
			}
		}
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int x, y;
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			graph[y][x] = Integer.parseInt(st.nextToken());
		}
		FloydWar();
		for(int i=1;i<=V;i++) {
			res=Math.min(graph[i][i],res);
		}
		if(res==INF) System.out.println(-1);
		else System.out.println(res);
	}

}
