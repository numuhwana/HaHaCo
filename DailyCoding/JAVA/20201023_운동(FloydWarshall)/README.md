# 운동

문제
홍익 제국의 중심은 행성 T이다. 제국의 황제 윤석이는 행성 T에서 제국을 효과적으로 통치하기 위해서, N개의 행성 간에 플로우를 설치하려고 한다.

두 행성 간에 플로우를 설치하면 제국의 함선과 무역선들은 한 행성에서 다른 행성으로 무시할 수 있을 만큼 짧은 시간만에 이동할 수 있다. 하지만, 치안을 유지하기 위해서 플로우 내에 제국군을 주둔시켜야 한다.

모든 행성 간에 플로우를 설치하고 플로우 내에 제국군을 주둔하면, 제국의 제정이 악화되기 때문에 황제 윤석이는 제국의 모든 행성을 연결하면서 플로우 관리 비용을 최소한으로 하려 한다.

N개의 행성은 정수 1,…,N으로 표시하고, 행성 i와 행성 j사이의 플로우 관리비용은 Cij이며, i = j인 경우 항상 0이다.

제국의 참모인 당신은 제국의 황제 윤석이를 도와 제국 내 모든 행성을 연결하고, 그 유지비용을 최소화하자.  이때 플로우의 설치비용은 무시하기로 한다.

입력
입력으로 첫 줄에 행성의 수 N (1 ≤ N ≤ 1000)이 주어진다.

두 번째 줄부터 N+1줄까지 각 행성간의 플로우 관리 비용이 N x N 행렬 (Cij),  (1 ≤ i, j ≤ N, 1 ≤ Cij ≤ 100,000,000, Cij = Cji) 로 주어진다.

출력
모든 행성을 연결했을 때, 최소 플로우의 관리비용을 출력한다.


## Example1

```
Input: 
3
0 2 3
2 0 1
3 1 0

Output: 
3
```

## Example1

```
Input: 
5
0 6 8 1 3
6 0 5 7 3
8 5 0 9 4
1 7 9 0 6
3 3 4 6 0

Output: 
11
```

## trial1
### Intuition
```
사이클중에 가장 경로가 적은 사이클을 구하는 문제이고 플로이드 워셔를 사용해서 해결할수 있다.
우선 2차원 그래프를 사용해서 모두 내가 정의한 INF로 초기화를 시켜준다.
그리고 flowdwarshall 함수를 돌리는데 이함수는 시작 node, 중간 node, 끝 node에 대해서 중간 node를
거쳐가는 것이 짧은지 거쳐가지 않는 것이 빠른지 결정해 최상의 경로를 찾아서 시작node와 끝node에 대한 
거리를 계속 갱신해주는 방식으로 구현한다.

그리고 사이클을 찾는 문제이기때문에 시작 node와 끝 node가 같으면 자신으로 돌아오는 최상의 거리를 찾을수 있다.

```
### Codes  
```java
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
```

### Results (Performance)  
**Runtime:** 916 ms   
**Memory Usage:**   68620 kb    

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1956