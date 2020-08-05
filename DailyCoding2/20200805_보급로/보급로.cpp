#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
int main() {
    Solution sol = Solution();
    vector<vector<int>> A = {
        //{{0,1,0,1},{0,0,0,0},{1,0,0,0}}
        {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}}
    };
    cout << sol.shortestBridge(A);
    return 0;
}