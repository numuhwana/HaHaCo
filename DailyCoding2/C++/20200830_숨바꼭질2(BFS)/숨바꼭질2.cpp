#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
const int MAX = 100001;
bool visit[MAX] = { 0, };//경우의수
struct block {
	int x;
	int time;
};
int main() {
	freopen("숨바꼭질2.txt", "r", stdin);
	int N, K;
	cin >> N >> K;
	int xx[3] = { -1,1,2 };
	queue<block> q;
	block cur;
	cur.x = N;
	cur.time = 0;
	q.push(cur);
	visit[N] = true;
	int cnt = 1;
	int minK = MAX;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		visit[cur.x] = true;
		if (cur.x == K) {
			if (minK > cur.time) {
				cnt = 1;
				minK = cur.time;
			}
			else if (minK == cur.time) {
				cnt++;
			}
		}

		for (int i = 0; i < 3; i++) {
			int nx= xx[i] + cur.x;
			if (i == 2) nx = xx[i] * cur.x;
			if (nx >= 0 && nx <= MAX && !visit[nx]) {//다음 인덱스가 범위 안에 있는 경우
				block nw;
				nw.x = nx;
				nw.time = cur.time + 1;
				q.push(nw);
			}
		}
	}
	cout << minK << endl << cnt << endl;
	return 0;
}