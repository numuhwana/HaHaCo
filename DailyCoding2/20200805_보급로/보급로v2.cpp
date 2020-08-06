#include <iostream>
#include <vector>
#include <queue>
#include <string>
#pragma warning (disable:4996)
using namespace std;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };

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
int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(NULL);
    int tc = 0;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        int n = 0;
        cin >> n;
        vector<vector<int>> grid;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            string tmp2;
            cin >> tmp2;
            for (char j : tmp2) {
                int val = j - '0';
                tmp.push_back(val);
                mx = mx + val;
            }
            grid.push_back(tmp);
        }
        cout<<"#"<<t+1<<" "<<function(grid, n,mx+1)<<endl;

    }
}