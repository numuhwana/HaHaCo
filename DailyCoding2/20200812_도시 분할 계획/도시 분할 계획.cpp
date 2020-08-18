#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
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