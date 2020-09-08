#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int N;
	//freopen("계단오르기.txt", "r", stdin);
	cin >> N;
	vector<int> v;
	v.push_back(0);
	vector<int> v2;
	v2.push_back(0);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		v2.push_back(0);
	}
	v2[1] = v[1];
	v2[2] = v[1] + v[2];
	for (int i = 3; i <= N; i++) {
		v2[i] = max(v[i] + v2[i - 2], v[i] + v[i - 1] + v2[i - 3]);
	}
	cout << v2[N];
	return 0;
}