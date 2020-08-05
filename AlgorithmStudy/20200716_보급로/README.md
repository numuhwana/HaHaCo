# 보급로
문제는 사이트참조

## Example1

```
Input: A = [[0,1],[1,0]]
Output: 1
```

## Example2

```
Input: A = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
```

## Example3

```
Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
```

Constraints:
```
2 <= A.length == A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1
```

## trial1
### Intuition
```
문제를 잘못 이해하여 땅은 여러개 존재할 수 있다고 생각하였고
땅들이 사방으로 퍼져나간다고 생각할때 땅들이 모두 연결되는 최소의 경로가 어떻게 되는지에 대해서 문제를 풀어보았다.
문제와는 의도는 달랐지만 어쩌다가 좋은 문제를 만든것 같아서 트라이얼에 넣게 되었다.

나는 우선 BFS와 연결 여부는 연결map을 통해서 확인하도록 하여 해결하였다.
처음에는 for문을 돌려 모든 지도에 존재하는 땅들에 대해서 조사해야한다. 
for문을 돌릴때 땅을 찾고 이미 방문한 땅이 아닐때마다 bfs를 돌려서 cnt를 세어주어 땅에 번호를 매긴다.
이때 모든 독립된 땅을 찾는 큐는 q2로 지정하였다.
이때 모든 땅들은 q에 넣어준다.
q에 넣어주는 값은 block 구조체로 땅번호 num, 경로 걸음수인 cnt 그리고 좌표로 구성되어있다.

이중 for문을 모두 돌았을때에는 q를 사용하여 사방탐색을 시작한다.
사방탐색을 하면서 고유의 땅번호가 만약 현재 탐색하던 땅과 다른번호라면 땅들끼리 만나는 것으로 생각하여
연결 여부 map에 연결되었다는 표시를 한다.
이렇게 연결 횟수가 독립된 땅의 개수보다 1개 작다면 모든 땅이 연결된 것이라고 할 수 있다.


I misunderstood the problem and thought there could be multiple lands in the map
When I thought that the lands were spreading all over the place, I solved the problem of what would be the minimum path to all the lands.
The intention was different from the problem, but it seemed to have made a good problem, so I put it in the trial.

First of all, I solved it by checking whether or not to connect with BFS through the connection map.
Initially, you need to turn the for statement to examine the lands on all maps.
When you run the for statement, it finds the land, and whenever it is not already visited, it turns bfs and counts the cnts to number the land.
At this time, the queue for finding all independent lands was designated as q2.
At this time, all the lands are put in q.
The value put in q is a block structure, which is composed of land number num, path step number cnt, and coordinates.

When all of the for statements are turned, use q to start searching everywhere.
When searching through all directions, if the unique land number is different from the current land, it is considered to meet the lands.
Whether it is connected or not The map indicates that it is connected.
If the number of connections is one less than the number of independent lands, it can be said that all lands are connected.

```
### Codes  
```cpp
class Solution {
public:
    int xx[4] = { 1,-1,0,0 };
    int yy[4] = { 0,0,1,-1 };
    int total = 0;
    struct block {
        int x;
        int y;
        int cnt;
        int num;
    };
    queue<block> q,q2;
    int shortestBridge(vector<vector<int>>& A) {
        int cnt = 1;
        vector<vector<int>> visit(A.size(), vector<int>(A[0].size(), 0));
        int nx, ny;
        block cur;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] == 1 && visit[i][j]==0) {//아직 방문을 안했고 1인경우에만
                    block b;
                    b.x = j;
                    b.y = i;
                    b.cnt = 0;
                    b.num = cnt;//땅번호
                    q.push(b);
                    q2.push(b);
                    visit[i][j] = cnt;
                    while (!q2.empty()) {//현재 땅과 연결된 전체 땅을 모두 구해준다.
                        cur = q2.front();
                        q2.pop();
                        for (int i = 0; i < 4; i++) {
                            nx = xx[i] + cur.x;
                            ny = yy[i] + cur.y;
                            if (nx >= 0 && ny >= 0 && nx < A[0].size() && ny < A.size()) {//범위 안이라면
                                if (visit[ny][nx] == 0 && A[ny][nx]==1) {//아직 방문 안했고 현재땅과 연결되어있는경우에만
                                    visit[ny][nx] = cur.num;//visit을 땅번호로 갱신
                                    block nxt;
                                    nxt.x = nx;
                                    nxt.y = ny;
                                    nxt.cnt = cur.cnt;
                                    nxt.num = cur.num;//현재땅번호넣기
                                    q2.push(nxt);//다음 경로
                                    q.push(nxt);//연결된 땅은 다 넣어준다.
                                }
                            }
                        }
                    }
                    cnt++;//땅번호 갱신
                }
            }
        }
        vector<vector<bool>> con(cnt, vector<bool>(cnt, false));//연결상태
        for (int i = 0; i < con.size(); i++) {//자기자신은 무조건 연결된상태
            con[i][i] = true;
        }
        int concnt = 0;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                nx = xx[i] + cur.x;
                ny = yy[i] + cur.y;
                if (nx >= 0 && ny >= 0 && nx < A[0].size() && ny < A.size()) {//범위 안이라면
                    if (visit[ny][nx]==0) {//아직 방문 안한경우
                        visit[ny][nx] = cur.num;
                        block nxt;
                        nxt.x = nx;
                        nxt.y = ny;
                        nxt.num = cur.num;
                        nxt.cnt = cur.cnt + 1;
                        q.push(nxt);//다음 경로
                    }
                    else if(visit[ny][nx]!=cur.num && con[cur.num][visit[ny][nx]]==false){//이미 방문한경우에는 땅숫자가 다른경우에 연결상태 확인한다.
                        //연결해주고 연결개수 확인해준다.
                        con[cur.num][visit[ny][nx]] = true;
                        con[visit[ny][nx]][cur.num] = true;
                        total = cur.cnt+1;
                        concnt++;
                        if (concnt == (cnt - 2)) {
                            return total;
                        }
                    }
                }
            }
        }
        return total;

    }
};
```

## trial2
### Intuition
```
두번째 트라이얼에서는 사실 첫번째 트라이얼에서 이해한 코드보다 더 간단하게 해결할 수 있었다.
이중 for문을 돌면서 땅이 나오게 되면 그 땅에 대해서 모두 q에 넣도록 한다.
그리고 문제에서는 두개의 땅만 존재한다고 했으니 더이상 for문을 돌려줄 필요 없이 break를 해준다.

그러면 이제 q에 대해서 bfs를 돌리면서 사방 탐색을 하게 된다. 
새로운 땅을 만난경우에는 A[ny][nx]가 1인 경우이고 이미 탐색한 땅은 visit[ny][nx]에서 걸리기 때문에 A만 확인해주면 된다.
이때 새로운 땅은 하나라도 만나면 값을 리턴해주면 된다.
이문제에서는 새로운 땅을 바로 밟기 직전까지의 경로를 세어주는 것이기 때문에 현재 큐에서 빼낸 block에 대한 cnt를
리턴해주게 되면 답이 된다.

In the second trial, it was actually easier to solve than the code understood in the first trial.
If the land comes out while turning the for statement, put all q in the land.
And in the problem, there are only two lands, so it breaks without having to return a for statement anymore.

Then you will now run bfs on q to search everywhere.
If you meet a new land, A[ny][nx] is 1, and the land you have already searched is taken from visit[ny][nx], so you only need to check A.
At this time, if there is any new land, simply return the value.
In this problem, it is counting the path to just before stepping on the new ground.
If it returns, it becomes the answer.
```
### Codes  
```cpp
class Solution {
public:
    struct block {
        int x;
        int y;
        int cnt=0;
    };
    int xx[4] = { 0,0,-1,1 };
    int yy[4] = { 1,-1,0,0 };
    queue<block> q,q2;
    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<bool>> visit(A.size(), vector<bool>(A.size(), false));
        int nx, ny;
        block cur;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] == 1 && visit[i][j]==false) {
                    visit[i][j] = true;
                    block b;
                    b.x = j;
                    b.y = i;
                    q.push(b);
                    q2.push(b);
                    while (!q2.empty()) {
                        cur = q2.front();
                        q2.pop();
                        for (int i = 0; i < 4; i++) {
                            nx = xx[i] + cur.x;
                            ny = yy[i] + cur.y;
                            if (nx >= 0 && ny >= 0 && nx < A.size() && ny < A.size() && !visit[ny][nx] && A[ny][nx]==1) {
                                visit[ny][nx] = true;
                                block nxt;
                                nxt.x = nx;
                                nxt.y = ny;
                                q2.push(nxt);
                                q.push(nxt);
                            }
                        }
                    }
                    i = A.size();
                    break;
                }
            }
        }
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                nx = xx[i] + cur.x;
                ny = yy[i] + cur.y;
                if (nx >= 0 && ny >= 0 && nx < A.size() && ny < A.size() && !visit[ny][nx]) {
                    visit[ny][nx] = true;
                    if (A[ny][nx] == 1) {//새로운 땅을 만난거임
                        return cur.cnt;
                    }
                    block nxt;
                    nxt.x = nx;
                    nxt.y = ny;
                    nxt.cnt = cur.cnt + 1;
                    q.push(nxt);
                }
            }
        }
        return 0;
        
    }
};
```

### Results (Performance)  
**Runtime:**  80 ms O(n^2) //완전탐색
**Memory Usage:** 	20 MB  

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (swexpert)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD&categoryId=AV15QRX6APsCFAYD&categoryType=CODE