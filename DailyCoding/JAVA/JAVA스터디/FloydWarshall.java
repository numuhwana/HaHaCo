//참고: https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F
package com.yujin;

public class FloydWarshall {
	static long INF=Integer.MAX_VALUE;
	static long graph[][]= {
			{0,5,INF,8},
			{7,0,9,INF},
			{2,INF,0,4},
			{INF,INF,3,0}
	};
	static long res[][];
	static int num=4;
	public static int floydwarshall() {
		res=new long[num][num];
		for(int i=0;i<graph.length;i++) {
			for(int j=0;j<graph[i].length;j++) {
				res[i][j]=graph[i][j];
			}
		}
		for(int k=0;k<num;k++) {//거쳐가는 node
			for(int i=0;i<num;i++) {//출발 node
				for(int j=0;j<num;j++) {//도착 node
					if(res[i][k]+res[k][j]<res[i][j]) {
						//node k를 거쳐가는 것이 더 빠른경우
						res[i][j]=res[i][k]+res[k][j];//더 적은 weight로 갱신
					}
				}
			}
		}
		return 0;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		floydwarshall();
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<num;i++) {
			for(int j=0;j<num;j++) {
				sb.append(res[i][j]).append(" ");
			}sb.append("\n");
		}sb.append("\n");
		System.out.println(sb);
	}

}
