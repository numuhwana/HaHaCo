#include <iostream>
#include <vector>
//#pragma warning (disable:4996)
using namespace std;
int function(vector<int> &v,int& n,int total) {
	vector<bool> visit(total + 1, false);
	vector<int> v2;
	visit[0] = true;
	v2.push_back(0);
	for (int i = 0; i < v.size(); i++) {
		int len = v2.size();
		for (int j = 0; j < len; j++) {
			int tmp = v2[j] + v[i];
			if (!visit[tmp]) {//visit을 안했을 경우에만 더하기
				v2.push_back(tmp);
				visit[tmp] = true;
			}
		}
	}
	return v2.size();
}
int main() {
	//freopen("sample_input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc = 0;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n = 0;
		cin >> n;
		vector<int> v(n, 0);//각 문제의 배점
		int total = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			v[i]=tmp;
			total += tmp;
		}
		int ans=function(v, n, total);
		cout << '#'<<t+1<<" "<<ans<<endl;
	}
	return 0;
}