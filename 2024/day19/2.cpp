#include "../../utils/aoc_utils.h"
#include <bits/stdc++.h>

using namespace std;

#define int long long

map<string,int> memo;

int ok(string s, vector<string> &v) {
	if (memo.count(s)) return memo[s];
	int res = 0;
	for (auto c : v) {
		if (s.front()!=c.front() || c.size()>s.size()) continue;
		string a = s.substr(0, c.size());
		if (a != c) continue;
		if (a.size() == s.size()) {
			res++;
			continue;
		}
		res += ok(s.substr(a.size()), v);
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
