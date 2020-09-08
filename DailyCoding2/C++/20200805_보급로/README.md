# 1249. [S/W 문제해결 응용] 4일차 - 보급로
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
처음에는 그냥 bfs를 사용하여 가장 적은 시간이 걸리는 보급로로 0,0에서 n,n 좌표로 이동하는 값을 구하였다.
visit값에는 현재 좌표까지 도달하는데 최소 시간 값을 넣도록 하여 그 값을 초과하는 경우에는 더이상
확인할 필요가 없으므로 제외하고 q에 넣어주었다.
이때 걸린 시간은 완전탐색이므로 많이 걸리게 된다.
```
### Codes  
```cpp
struct block {
    int x = 0;
    int y = 0;
    int val = 0;
};
int function(vector<vector<int>> &grid,int n,int mx) {
    vector<vector<int>> visit(n,vector<int>(n,mx));//최고 숫자로 초기화
    queue<block> q;
    block cur;
    q.push(cur);
    int nx, ny;
    visit[0][0] = 0;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.x == n && cur.y == n) break;
        for (int i = 0; i < 4; i++) {
            nx = cur.x+xx[i];
            ny = cur.y+yy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {//만족한 경우
                int nxtval = cur.val + grid[ny][nx];
                if (visit[ny][nx] > nxtval) {//현재 visit 값보다 작은경우
                    visit[ny][nx] = nxtval;
                    block nxt;
                    nxt.x = nx;
                    nxt.y = ny;
                    nxt.val = nxtval;
                    q.push(nxt);
                }
            }
        }
    }
    return visit[n - 1][n - 1];
}
```

### Results (Performance)  
**Runtime:**  782 ms
**Memory Usage:**   13,080 kb 


## trial2
### Intuition
```
두번째는 priority queue를 이용하여 bfs이지만 최소로 걸리는 시간 위주로 탐색하였다.
이 방법으로 만약에 n,n로 도달하게 되면 가장 최소로 걸린 시간이 결과로 나오게 된다.
```
### Codes  
```cpp
struct block {
    int x = 0;
    int y = 0;
    int val = 0;
    bool operator>(const block& b) const {
        return val > b.val;
    }
};
int function(vector<vector<int>> &grid,int n,int mx) {
    vector<vector<int>> visit(n,vector<int>(n,mx));//최고 숫자로 초기화
    priority_queue<block,vector<block>,greater<block>> q;
    block cur;
    q.push(cur);
    int nx, ny;
    visit[0][0] = 0;
    while (!q.empty()) {
        cur = q.top();
        q.pop();
        if (cur.x == n && cur.y == n) break;
        for (int i = 0; i < 4; i++) {
            nx = cur.x+xx[i];
            ny = cur.y+yy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {//만족한 경우
                int nxtval = cur.val + grid[ny][nx];
                if (visit[ny][nx] > nxtval) {//현재 visit 값보다 작은경우
                    visit[ny][nx] = nxtval;
                    block nxt;
                    nxt.x = nx;
                    nxt.y = ny;
                    nxt.val = nxtval;
                    q.push(nxt);
                }
            }
        }
    }
    return visit[n - 1][n - 1];
}
```

### Results (Performance)  
**Runtime:**  53 ms 
**Memory Usage:** 	12,836 kb  

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (swexpert)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD&categoryId=AV15QRX6APsCFAYD&categoryType=CODE