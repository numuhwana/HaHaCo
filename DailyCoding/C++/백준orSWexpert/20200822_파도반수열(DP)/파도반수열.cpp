#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
	freopen("파도반 수열.txt", "r", stdin);
	int tc;
	cin >> tc;
	vector<long long> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	for (int t = 0; t < tc; t++) {
		long long N;
		cin >> N;
		for (int i = v.size(); i < N; i++) {
			long long tmp = v[i - 3] + v[i - 2];
			v.push_back(tmp);
		}
		cout << v[N-1]<<endl;
	}
	return 0;
}