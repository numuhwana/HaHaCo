#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
	freopen("123더하기.txt", "r", stdin);
	int tc;
	cin >> tc;
	vector<long long> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	for (int t = 0; t < tc; t++) {
		long long N;
		cin >> N;
		for (int j = v.size(); j <= N; j++) {
			long long sum = 0;
			for (int i = 1; i <= 3; i++) {
				sum += v[j - i];
			}
			v.push_back(sum);
		}
		cout << v[N] << endl;
	}
	return 0;
}