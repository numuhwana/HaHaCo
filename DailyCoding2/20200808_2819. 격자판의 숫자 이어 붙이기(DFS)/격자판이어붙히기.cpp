#include <iostream>
#include <vector>
#include <set>
#include <string>
#pragma warning (disable:4996)
using namespace std;
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
int main() {
    freopen("격자판.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        vector<vector<int>> v(4, vector<int>(4, 0));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                block b;
                b.x = j;
                b.y = i;
                function(v,b,v[i][j],1);
            }
        }
        cout << "#" << t<<" " << s.size()<<endl;
        s.clear();

    }
    return 0;
}