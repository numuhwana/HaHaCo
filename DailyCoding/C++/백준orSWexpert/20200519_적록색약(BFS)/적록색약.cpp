#include <iostream>
#include <queue>
//#pragma warning (disable:4996)
using namespace std;
int n;
char arr[101][101];
bool visit[101][101] = { false, };
bool visit2[101][101] = { false, };
struct col {
	int x, y;
	char c;
};
queue<col> q;
int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,1,-1 };
void find1() {//적록색약 아닌사람
	int nx, ny;
	col cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (arr[ny][nx] == cur.c && !visit[ny][nx]) {//같고 visit 안한부분
					visit[ny][nx] = true;
					col nw;
					nw.c = cur.c;
					nw.x = nx;
					nw.y = ny;
					q.push(nw);
				}
			}
		}
	}
}
void find2() {
	int nx, ny;
	col cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (cur.c == 'B') {//blue를 제외하고는 모두 같은것으로 취급
					if (arr[ny][nx] == cur.c && !visit2[ny][nx]) {//같고 visit 안한부분
						visit2[ny][nx] = true;
						col nw;
						nw.c = cur.c;
						nw.x = nx;
						nw.y = ny;
						q.push(nw);
					}
				}
				else {
					if (arr[ny][nx] !='B' && !visit2[ny][nx]) {//같고 visit 안한부분
						visit2[ny][nx] = true;
						col nw;
						nw.c = cur.c;
						nw.x = nx;
						nw.y = ny;
						q.push(nw);
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("적록색약.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt1=0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {//적록색양 아닌사람
				visit[i][j] = true;
				col c;
				c.x = j;
				c.y = i;
				c.c = arr[i][j];
				q.push(c);
				find1();
				cnt1++;
			}
			if (!visit2[i][j]) {//적록색약
				visit2[i][j] = true;
				col c;
				c.x = j;
				c.y = i;
				c.c = arr[i][j];
				q.push(c);
				find2();
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2;

	return 0;
}