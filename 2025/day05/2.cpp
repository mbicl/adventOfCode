#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

#define int long long
vector<pair<int, int>> vc;

signed main() {
	string s;

	while (getline(cin,s)) {
		s = aoc::str::trim(s);
		if (s.empty()) break;
		
		int l, r;
		char c;
		stringstream(s) >> l >> c >> r;
		if (l>r) swap(l, r);
		vc.push_back({l, r});
	}

	int ans = 0, x;

	sort(vc.begin(), vc.end());
	vector<pair<int, int>> v;
	for (auto& p : vc) {
		if (v.empty() || v.back().second < p.first) {
			v.push_back(p);
		} else {
			v.back().second = max(v.back().second, p.second);
		}
	}

	for (auto p:v) {
		ans += p.second - p.first + 1;
	}

	cout << ans;
}
