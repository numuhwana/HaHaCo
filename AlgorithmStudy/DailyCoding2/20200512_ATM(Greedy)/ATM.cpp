#include <iostream>
#include <queue>
//#pragma warning (disable:4996)
using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int>> q;
	int ct, time = 0,tmp;
	//freopen("ATMtest.txt", "r", stdin);
	cin >> ct;
	for (int i = 0; i < ct; i++) {
		cin >> tmp;
		q.push(tmp);
	}
	int cur;
	while (!q.empty()) {
		time += (q.top()*q.size());
		q.pop();
	}
	cout << time;
	return 0;
}