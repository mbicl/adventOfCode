#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <map>

#define int long long

using namespace std;

map<string, int> mp;
vector<int> g[1000];
int dp[1000][4];
int svr, out, dac, fft;

int go(int u, int b) {
	b|=(u==dac?2:0);
	b|=(u==fft?1:0);
	if (dp[u][b]!=-1) {
		return dp[u][b];
	}
	if (u==out) {
		return (b==3?1:0);
	}
	int sum = 0;
	for (auto v:g[u]) {
		sum+=go(v, b);
	}
	dp[u][b]=sum;
	return dp[u][b];
}

signed main() {
	for (int i=0; i<1000; ++i) {
		for (int j=0; j<4; ++j) {
			dp[i][j]=-1;
		}
	}
	string s;
	while (getline(cin, s)) {
		auto v=aoc::str::split(s, ' ');
		v[0].pop_back();
		for (auto &i:v){
			if (!mp.count(i)) {
				mp[i]=mp.size();
			}
		}
		for (int i=1; i<v.size(); ++i) {
			g[mp[v[0]]].push_back(mp[v[i]]);
		}
	}
	svr=mp["svr"];
	out=mp["out"];
	dac=mp["dac"];
	fft=mp["fft"];

	cout << go(svr, 0) << endl;
}
