#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

signed main() {
	vector<string> v;
	string s;
	while (getline(cin, s)) {
		v.push_back(s);
	}

	int n = v.size(), m = v[0].size();
	int x = 0, y = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (v[i][j]=='S') {
				x = i;
				y = j;
			}
		}
	}

	v[x][y]='|';
	int ans = 0;
	for (int i=x+1; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (v[i-1][j]=='|') {
				if (v[i][j]=='.') {
					v[i][j]='|';
				}
				else if (v[i][j]=='^') {
					v[i][j-1]='|';
					v[i][j+1]='|';
					ans++;
				}
			}
		}
	}
	cout << ans;
}