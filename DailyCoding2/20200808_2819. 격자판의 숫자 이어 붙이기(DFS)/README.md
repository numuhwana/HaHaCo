# 2819. 격자판의 숫자 이어 붙이기
문제는 사이트참조

## Example1

```
Input: 
2
1 2 3 4
3 2 9 2
1 5 2 1
1 2 1 1

1 2 3 4
3 2 2 2
1 2 2 1
1 2 1 3

Output: 

#1 4615
#2 1509
```

## trial1
### Intuition
```
격자판의 크기가 그렇게 크지 않기 때문에 dfs를 사용하여 문제를 해결하였다.
만약에 dept가 7이 된다면 7자리 수가 다 만들어진 것이기 때문에 set에 넣는다.
set을 사용한 이유는 set는 중복을 알아서 걸러주기 때문이다.
그리고 현재 좌표가 어디든 4가지의 선택지가 있으므로 for문을 돌려주었다.
이 함수는 모든 격자판의 자리에서 이루어져야 한다.
그러므로 2차원 배열을 돌려주어서 모든 경우의 수를 따졌다.
```
### Codes  
```cpp
struct block {
    int x;
    int y;
};
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
set<int> s;
void function(vector<vector<int>> &v,block &b,int ans,int dep) {
    if (dep == 7) {
        s.insert(ans);
    }
    else {
        block nxt;
        for (int i = 0; i < 4; i++) {//4가지 선택지
            nxt.x = b.x + xx[i];
            nxt.y = b.y + yy[i];
            if (nxt.x >= 0 && nxt.y >= 0 && nxt.x < 4 && nxt.y < 4) {
                int tmp = ans * 10 + v[nxt.y][nxt.x];
                function(v, nxt, tmp,dep+1);
            }
        }
    }

}
```

### Results (Performance)  
**Runtime:**  158 ms 
**Memory Usage:** 	13,484 kb 

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (swexpert)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB&categoryId=AV7I5fgqEogDFAXB&categoryType=CODE&&&