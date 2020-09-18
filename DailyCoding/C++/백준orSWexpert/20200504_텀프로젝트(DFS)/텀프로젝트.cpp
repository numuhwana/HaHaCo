#include <iostream>
#include <vector>
//#pragma warning (disable:4996)
using namespace std;
int T;
int s;
int cnt = 0;
vector<int> arr;
vector<bool> visit;
vector<bool> cycle;
void find(int cur) {
	visit[cur] = true;
	int nxt = arr[cur];
	if (!visit[nxt]) {//방문하지 않은 경우 방문해본다.
		find(nxt);
	}
	else {//cycle이 생긴경우
		if (cycle[nxt] == false) {//새로운 사이클인지 판단
			for (int i = nxt; i != cur; i = arr[i]) {//nxt부터 모든 사이클의 요소들에 대하여 cnt++
				cnt++;
			}
			cnt++;
		}
	}
	cycle[cur] = true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("test.txt", "r", stdin);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> s;
		cnt = 0;
		arr.push_back(0);
		for (int i = 0; i < s; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
			visit.push_back(false);
			cycle.push_back(false);
		}
		visit.push_back(false);
		cycle.push_back(false);
		for (int i = 1; i <= s; i++) {
 			if(!visit[i]) find(i);
		}
		cout << s-cnt << endl;
		arr.clear();
		visit.clear();
		cycle.clear();
	}
	return 0;
}