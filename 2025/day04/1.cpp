#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int t = 100;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1,-1,1,-1,1};
int dy[]={0,-1,1,0,-1,-1,1,1};

signed main() {
	vector<string> g;
	string s;
	g.push_back(string(500,'.'));
	while (cin >> s) {
		s="."+s+".";
		g.push_back(s);
	}
	g.push_back(string(500,'.'));
	
	int n = g.size();
	int m = g[1].size();
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j]!='@') continue;
			int cnt = 0;
			for (int d = 0; d < 8; d++) {
				if (g[i+dx[d]][j+dy[d]]=='@') cnt++;
			}
			if (cnt<4) ans++;
		}
	}

	cout << ans;
}
