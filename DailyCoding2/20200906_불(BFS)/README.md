# 불

문제
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.

매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.
```
'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
```
각 지도에 @의 개수는 하나이다.

출력
각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.



## Example1

```
Input: 
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###

Output: 
2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE
```

## trial1
### Intuition
```
BFS 문제였기 때문에 queue를 사용하였다.
사람에 대한 queue와 불에 대한 queue를 같이 사용하여 문제를 해결하였다.
불을 먼저 퍼트린다음에 사람을 퍼트렸다. 그 이유는 사람은 불이 퍼진장소에 가지 못해야하기 때문에
동시에 퍼진다고 해도 불이 우선순위이다.
time이라는 구조체를 obj에 넣어놓고 time이 바뀌기 전까지 모든 객체에 대해서 퍼트리는 방식이다.
불은 벽에 붙지 못하므로 @(사람) .(빈공간) 인 경우에만 자리를 차지하도록 하고 visit로 방문표시를 하였다
방문표시는 벽이 있는 공간에도 해주었다.
그렇게 하면 사람이 갈수 있는 공간은 빈공간밖에 없다. 그렇게 해서 map의 범위를 벗어날 수 있게 되면
그것은 EXIT를 한 경우이고 범위를 벗어나지 못한 상태에서 모든 큐가 비어있게 된다면 
불로부터 벗어나지 못한것이다. 
```
### Codes  
```cpp
#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
struct obj{
    int x, y;
    int time=0;
};
int main() {
    freopen("불.txt", "r", stdin);
    int TC;
    cin >> TC;
    for (int t = 0; t < TC; t++) {
        int w, h;
        cin >> w >> h;
        queue<obj> qf;//불에 대한 queue
        queue<obj> qp;//사람에 대한 queue
        vector<vector<char>> v;
        bool visit[1001][1001] = { 0, };
        for (int i = 0; i < h; i++) {
            vector<char> v2;
            for (int j = 0; j < w; j++) {
                char tmp;
                cin >> tmp;
                v2.push_back(tmp);
                if (tmp == '*') {//불인경우
                    obj fire;
                    fire.x = j;
                    fire.y = i;
                    qf.push(fire);
                    visit[i][j] = true;
                }
                else if (tmp == '@') {
                    obj person;
                    person.x = j;
                    person.y = i;
                    qp.push(person);
                    visit[i][j] = true;
                }
                else if(tmp=='#'){
                    visit[i][j] = true;//벽이므로
                }
            }
            v.push_back(v2);
        }//여기까지 map과 사람,불 초기화 완료
        obj curp,curf;
        int nx, ny;
        int curt = 0;
        bool finish = false;
        while (!finish && (!qp.empty() || !qf.empty()))//둘중 하나라도 갈길이 더이상 없다면
        {
            while (!qf.empty() && qf.front().time==curt) {//현재시간이랑 같은애들은 퍼트린다
                curf = qf.front();
                qf.pop();
                for (int i = 0; i < 4; i++) {//모든 방향에 대해서 퍼진다.
                    nx = curf.x + xx[i];
                    ny = curf.y + yy[i];
                    if (nx >= 0 && ny >= 0 && nx < w && ny < h && (v[ny][nx]=='.' || v[ny][nx]=='@')) {//불은 범위 안에서만 퍼진다.
                        visit[ny][nx] = true;
                        v[ny][nx] = '*';
                        obj fire;
                        fire.x = nx;
                        fire.y = ny;
                        fire.time = curt + 1;
                        qf.push(fire);
                    }
                }
            }
            while (!qp.empty() && !finish && qp.front().time == curt) {
                curp = qp.front();
                qp.pop();
                for (int i = 0; i < 4; i++) {
                    nx = curp.x + xx[i];
                    ny = curp.y + yy[i];
                    if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
                        if (!visit[ny][nx]) {//갈수 있는 길인경우
                            visit[ny][nx] = true;
                            obj pers;
                            pers.x = nx;
                            pers.y = ny;
                            pers.time = curt + 1;
                            qp.push(pers);
                        }
                    }
                    else {//범위를 벗어나는 경우 현재 시간 출력 끝~
                        finish = true;
                        cout << curt + 1 << endl;
                        break;
                    }
                }
            }
            curt++;
        }
        if (!finish) {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
```

### Results (Performance)  
**Runtime:** 160 ms   
**Memory Usage:**   6176 kb    

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (백준)  
https://www.acmicpc.net/problem/5427