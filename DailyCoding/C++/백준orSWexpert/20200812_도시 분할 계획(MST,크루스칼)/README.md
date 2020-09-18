# 도시 분할 계획
동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다. 그러다가 평화로운 마을에 가게 되었는데, 그곳에서는 알 수 없는 일이 벌어지고 있었다.

마을은 N개의 집과 그 집들을 연결하는 M개의 길로 이루어져 있다. 길은 어느 방향으로든지 다닐 수 있는 편리한 길이다. 그리고 각 길마다 길을 유지하는데 드는 유지비가 있다.

마을의 이장은 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있다. 마을이 너무 커서 혼자서는 관리할 수 없기 때문이다. 마을을 분할할 때는 각 분리된 마을 안에 집들이 서로 연결되도록 분할해야 한다. 각 분리된 마을 안에 있는 임의의 두 집 사이에 경로가 항상 존재해야 한다는 뜻이다. 마을에는 집이 하나 이상 있어야 한다.

그렇게 마을의 이장은 계획을 세우다가 마을 안에 길이 너무 많다는 생각을 하게 되었다. 일단 분리된 두 마을 사이에 있는 길들은 필요가 없으므로 없앨 수 있다. 그리고 각 분리된 마을 안에서도 임의의 두 집 사이에 경로가 항상 존재하게 하면서 길을 더 없앨 수 있다. 마을의 이장은 위 조건을 만족하도록 길들을 모두 없애고 나머지 길의 유지비의 합을 최소로 하고 싶다. 이것을 구하는 프로그램을 작성하시오.

## Example1

```
Input: 
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

Output: 

8
```

## trial1
### Intuition
```
크루스칼 알고리즘을 사용하여 문제를 해결하였다. 
각 node별로 서로의 최상의 parent를 저장하여 간선의 길이가 가장 짧은것부터 모든 node들이
같은 최상위 parent를 가질때 까지 진행한다.
이문제에서는 모든 node들이 연결이 되는 것이 아니라 모든 node들을 짧은 간선들로 연결시켜준것에서
가장 긴 간선 하나를 빼는것이 목표이다.
그렇게 해야 두 마을이 분할이 되기 때문이다.
```
### Codes  
```cpp
struct node{
    int s;
    int e;
    int v;
    bool operator >(const node& a) const {
        return v > a.v;
    }
};
int findp(vector<int> &p,int a) {
    if (p[a] == a) return a;
    p[a] = findp(p, p[a]);
    return p[a];
}
void unionn(vector<int> &p, int a, int b) {
    int pa = findp(p, a);
    int pb = findp(p, b);
    if (pa==pb) return;
    p[pa] = b;
}
int main() {
    int N, M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("도시분할계획.txt", "r", stdin);
    cin >> N >> M;
    priority_queue<node,vector<node>,greater<node>> pq;
    vector<int> p;
    for (int i = 0; i <= N; i++) {
        p.push_back(i);
    }
    for (int i = 0; i < M; i++) {
        node tmp;
        cin>>tmp.s>>tmp.e>>tmp.v;
        pq.push(tmp);
    }
    node cur;
    int res = 0;
    int cnt = 0;
    while(!pq.empty()) {//완전 다 연결되기 바로 이전까지만
        cur = pq.top();
        pq.pop();
        int sp = findp(p,cur.s);
        int ep = findp(p, cur.e);
        if (sp == ep) continue;//이미 연결됐으면 더할필요 없음
        cnt++;
        if (cnt == N - 1) break;
        unionn(p,sp, ep);
        res += cur.v;
        
    }
    cout << res;
    return 0;
}
```

### Results (Performance)  
**Runtime:**  158 ms 
**Memory Usage:** 	13,484 kb 

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1647