int main() {
	//freopen("그룹단어체크.txt", "r", stdin);
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		map<int, bool> m;
		char cur = v[i][0];
		bool yes = true;
		for (int j = 0; j < v[i].size(); j++) {
			if (m.find(v[i][j]) != m.end()) {//이미 존재한다는 뜻
				if (v[i][j - 1] != v[i][j]) {//이전꺼와 같은지?
					yes = false;
					break;
				}
			}
			else {
				m[v[i][j]] = true;
			}
		}
		if (yes) cnt++;
	}
	cout << cnt << endl;
	return 0;
}