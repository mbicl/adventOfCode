#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

string target;
string joltage;
vector<vector<int>> vc;
int cnt;

void bfs(string lamps, int parent){
	if (lamps == target) {
		cnt = 0;
		return;
	}

	queue<tuple<string,int,int>> q;
	q.push({lamps, parent, 0});
	while (q.size()) {
		auto [cur, p, c] = q.front(); q.pop();
		if (cur == target) {
			cnt = min(cnt, c);
			cout << cnt << "\n";
			return;
		}
		for (int i=0; i<vc.size(); ++i) {
			if (i == p) continue;
			string nxt = cur;
			for (int d:vc[i]) {
				if (cur[d] == '.') nxt[d] = '#';
				else nxt[d] = '.';
			}
			q.push({nxt, i, c+1});
		}
	}
}

int solve(string s) {
	vc.clear();
	cnt = 1e9;
	auto v = aoc::str::split(s,' ');
	target = v[0];
	joltage = v.back();
	v.erase(v.begin());
	v.pop_back();

	target.erase(0,1);
	target.pop_back();
	joltage.erase(0,1);
	joltage.pop_back();

	string lamps = string(target.size(),'.');

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

	bfs(lamps, -1);

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

	cout << ans << "\n";
}
