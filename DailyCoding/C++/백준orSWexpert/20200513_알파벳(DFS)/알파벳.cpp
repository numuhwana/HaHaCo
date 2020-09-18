#include <iostream>
#include <vector>
//#pragma warning (disable:4996)
using namespace std;
char arr[21][21];
int r, c;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int cnt = 0;
struct block {
	int x, y;
	char c;
};
vector<bool> visit(26,false);
bool visit2[21][21] = { false, };
void dfs(block cur,int stp) {
	if (stp == (r*c) && !visit[cur.c - 'A']) {
		cnt = stp;
	}
	if (visit[cur.c - 65]) {
		if ((stp - 1) > cnt) cnt = stp - 1;//현재 step이 가장 크다면
	}
	else {
		int nx, ny;
		visit[cur.c - 65] = true;//현재 알파벳 방문표시
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
				if (!visit2[ny][nx]) {
					visit2[ny][nx] = true;
					block b;
					b.x = nx;
					b.y = ny;
					b.c = arr[ny][nx];
					dfs(b, stp + 1);
					visit2[ny][nx] = false;//방문했다가 다시 안방문하기
				}
			}
		}
		visit[cur.c - 65] = false;
		
	}
}
int main() {
	//freopen("알파벳.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	block b;
	b.x = 0;
	b.y = 0;
	b.c = arr[0][0];
	visit2[0][0] = true;
	dfs(b, 1);
	cout << cnt;
	return 0;
}