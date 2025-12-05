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
	while (cin >> x) {
		bool ok = false;
		for (auto& p : vc) {
			if (p.first <= x && x <= p.second) {
				ok = true;
				break;
			}
		}
		if (ok) ans++;
	}

	cout << ans;
}
