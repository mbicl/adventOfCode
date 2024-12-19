#include "../../utils/aoc_utils.h"
#include <bits/stdc++.h>

using namespace std;

map<string,bool> memo;

bool ok(string s, vector<string> &v) {
	if (memo.count(s)) return memo[s];
	bool res = 0;
	for (auto c : v) {
		if (s.front()!=c.front() || c.size()>s.size()) continue;
		string a = s.substr(0, c.size());
		if (a != c) continue;
		if (a.size() == s.size()) {
			memo[s]=1;
			return 1;
		}
		res = res || ok(s.substr(a.size()), v);
	}
	memo[s]=res;
	return res;
}

signed main() {
	string s;
	getline(cin, s);
	vector<string> t = aoc::str::split(aoc::str::remove_spaces(s), ',');
	cin.ignore();

	int ans = 0;
	while (getline(cin, s)) {
		memo.clear();
		ans += ok(s, t);
	}

	cout << ans;
}
