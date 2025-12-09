#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

int t = 100;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

signed main() {
	string s;
	vector<point> vc;
	while (getline(cin,s)) {
		int x, y;
		char c;

		stringstream(s) >> x >> c >> y;

		vc.push_back({x,y});
	}

	int ans = 0;

	for (int i=0; i<vc.size(); ++i) {
		for (int j=i+1; j<vc.size(); ++j) {
			int l = abs(vc[i].x - vc[j].x+1);
			int w = abs(vc[i].y - vc[j].y+1);
			ans=max(ans, l*w);
		}
	}

	cout << ans;
}
