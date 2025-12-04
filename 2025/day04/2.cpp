#include "../../utils/aoc_utils.h"

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

int t = 100;

struct point {
	int x, y;
};

int dx[] = {-1, 0, 0, 1, -1, 1, -1, 1};
int dy[] = {0, -1, 1, 0, -1, -1, 1, 1};

signed main() {
	vector<string> g;
	string s;
	g.push_back(string(500, '.'));
	while (cin >> s) {
		s = "." + s + ".";
		g.push_back(s);
	}
	g.push_back(string(500, '.'));
	
	int n = g.size();
	int m = g[1].size();
	int ans = 0;
	int cnt = 0;

	do {
		cnt=0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] != '@') continue;
				int c = 0;
				for (int d = 0; d < 8; d++) {
					if (g[i + dx[d]][j + dy[d]] == '@') c++;
				}
				if (c < 4) {
					g[i][j] = '.';
					cnt++;
				}
			}
		}
		ans+=cnt;
	} while (cnt > 0);

	cout << ans;
}
