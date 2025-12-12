#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

#define all(x) (x).begin(),(x).end()

using namespace std;

signed main() {
	vector<vector<string>> shapes(6, vector<string>(3));
	vector<int> cnt(6,0);
	for (int i=0; i<6; ++i){
		string s;
		cin >> s;
		for (int j=0; j<3; ++j){
			cin >> s;
			cnt[i] += count(all(s), '#');
			shapes[i][j] = s;
		}
	}

	int ans=0;
	string s;
	while (getline(cin,s)) {
		s=aoc::str::trim(s);
		if (s.empty()) continue;
		int x, y;
		char c;
		stringstream ss(s);
		ss >> x >> c >> y >> c;
		vector<int> v(6);
		for (int i=0; i<6; ++i){
			ss >> v[i];
		}
		int a=0;
		for (int i=0; i<6; ++i){
			a+=v[i]*cnt[i];
		}
		if (a<x*y) ans++;
	}
	cout << ans << endl;
}
