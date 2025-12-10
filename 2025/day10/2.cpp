#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>

#define int long long

using namespace std;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

vector<int> target;
vector<vector<int>> vc;
int cnt;

bool veq(vector<int> &a, vector<int> &b) {
	if (a.size() != b.size()) return false;
	for (int i=0; i<a.size(); ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void bfs(vector<int> joltages, int parent){
	if (veq(joltages, target)) {
		cnt = 0;
		return;
	}

	queue<tuple<vector<int>,int,int>> q;
	q.push({joltages, parent, 0});
	set<vector<int>> vis;
	vis.insert(joltages);
	while (q.size()) {
		auto [cur, p, c] = q.front(); q.pop();
		if (veq(cur, target)) {
			cnt = min(cnt, c);
			cout << cnt << endl;
			return;
		}
		for (int i=0; i<vc.size(); ++i) {
			vector<int> nxt = cur;
			bool ok = true;
			for (int d:vc[i]) {
				nxt[d]++;
				if (nxt[d]>target[d]){
					ok = false;
					break;
				}
			}
			if (ok && vis.count(nxt) == 0) {
				q.push({nxt, i, c+1});
				vis.insert(nxt);
			}
		}
	}
}

int solve(string s) {
	target.clear();
	vc.clear();
	cnt = 1e9;
	auto v = aoc::str::split(s,' ');
	string j = v.back();
	v.erase(v.begin());
	v.pop_back();

	j.erase(0,1);
	j.pop_back();

	auto joltage_strs = aoc::str::split(j,',');
	for (auto &d:joltage_strs) {
		int z;
		stringstream(d) >> z;
		target.push_back(z);
	}

	vector<int> joltages(target.size(), 0);

	for (auto &c:v) {
		c.erase(0,1);
		c.pop_back();
		auto x = aoc::str::split(c,',');
		vector<int> p;
		for (auto &d:x) {
			int z;
			stringstream(d) >> z;
			p.push_back(z);
		}
		vc.push_back(p);
	}

	bfs(joltages, -1);

	return cnt;
}

signed main() {
	string s;
	vector<string> l;
	while (getline(cin, s)) {
		l.push_back(s);
	}

	int ans = 0;
	for (auto &c:l) {
		ans += solve(c);
	}

	cout << ans << endl;
}
