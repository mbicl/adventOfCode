#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<string, vector<string>> g;
int ans = 0;

void go(string u) {
	if (u=="out") {
		ans++;
		return;
	}
	for (auto v : g[u]) {
		go(v);
	}
}

signed main() {
	string s;
	while (getline(cin, s)) {
		auto v=aoc::str::split(s, ' ');
		v[0].pop_back();
		for (int i=1; i<v.size(); ++i) {
			g[v[0]].push_back(v[i]);
		}
	}

	go("you");

	cout << ans;
}
