#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#pragma warning (disable:4996)
using namespace std;
int N, M;
int m[1000][1000] = { 0, };
bool visit[1000][1000][2];
struct land {
	int x, y;
	int c=1;
	int wallcnt = 0;
};
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int small;
void bfs() {
	queue<land> q;
	land cur;
	visit[0][0][0] = true;
	cur.x = 0;
	cur.y = 0;
	int nx, ny;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.y == N - 1 && cur.x == M - 1) {//끝에 도달한 경우
			small = cur.c;
			return;
		}
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				land nw;
				nw.wallcnt = cur.wallcnt;
				if (m[ny][nx] == 1) {//벽이라면
					if (cur.wallcnt == 0) {//벽을 부실수 있는경우라면
						nw.wallcnt++;
					}
					else continue;//벽을 이미 한번 이상 뚫었다면
				}
				if (!visit[ny][nx][nw.wallcnt]) {//cost가 더 작은경우에만 방문
					visit[ny][nx][nw.wallcnt] = true;
					nw.x = nx;
					nw.y = ny;
					nw.c = cur.c + 1;
					q.push(nw);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("벽부수고이동하기.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
		for (int j = 0; j < M; j++) {
			m[i][j] = s[j] - '0';
		}
	}
	small = N * M+1;
	bfs();
	cout << (small==(N*M+1)?-1:small);
	return 0;
}