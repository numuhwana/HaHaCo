#include <iostream>
#include <vector>
#include <limits.h>
#include <cstdint>
#pragma warning (disable:4996)
using namespace std;
int n,m,len=INT_MAX;
int g[51][51] = { 0, };
struct chicken {
	int x, y;
};
struct house {
	int x, y,len=2601;
};
vector<chicken> c;
vector<house> h;
vector<chicken> q;
void findway(vector<chicken> qq, vector<house> hh) {
	chicken k;
	int tmplen,localmax=0;
	while (!qq.empty()) {//모든 치킨집에 대하여
		k = qq.back();
		qq.pop_back();
		for (int i = 0; i < hh.size(); i++) {//모든 집에 대하여
			tmplen = abs(k.x - hh[i].x) + abs(k.y - hh[i].y);
			if (hh[i].len > tmplen) {
				hh[i].len = tmplen;//거리가 더 짧으면 업데이트
			}
		}
	}
	for (int i = 0; i < hh.size(); i++) {//모든 집에 대하여
		localmax += hh[i].len;
	}
	len = (localmax < len ? localmax : len);
}
void choose(int cur) {
	if (q.size() == m) {
		findway(q,h);
	}
	else {
		for (int i = cur; i < c.size(); i++) {
				q.push_back(c[i]);
				choose(i+1);
				q.pop_back();
		}
	}
}
int main() {
	//freopen("test.txt", "r", stdin);
	cin >> n>>m;
	house hh;
	chicken cc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>g[i][j];
			if (g[i][j] == 1) {
				hh.x = j;
				hh.y = i;
				h.push_back(hh);
			}
			else if (g[i][j] == 2) {
				cc.x = j;
				cc.y = i;
				c.push_back(cc);
			}
		}
	}
	choose(0);
	cout << len;

	return 0;
}