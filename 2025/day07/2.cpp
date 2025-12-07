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
	vector<vector<int>> dp(n, vector<int>(m, 0));

	v[x][y]='|';
	dp[x][y] = 1;
	int ans = 0;
	for (int i=x; i<n-1; ++i) {
		for (int j=0; j<m; ++j) {
			if (v[i][j]=='|') {
				if (v[i+1][j]!='^') {
					v[i+1][j]='|';
					dp[i+1][j] += dp[i][j];
				}
				else if (v[i+1][j]=='^') {
					if (j-1>=0){
						v[i+1][j-1]='|';
						dp[i+1][j-1] += dp[i][j];
					}
					if (j+1<m) {
						v[i+1][j+1]='|';
						dp[i+1][j+1] += dp[i][j];
					}
				}
			}
		}
	}
	
	for (int j=0; j<m; ++j) {
		if (v[n-1][j]=='|') {
			ans += dp[n-1][j];
		}
	}
	cout << ans;
}