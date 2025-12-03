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

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

signed main() {
	int ans = 0;
	string s;
	while (cin >> s) {
		int mx=0;
		for (int i=0; i<s.size()-1; ++i) {
			if (s[i]>s[mx]) {
				mx=i;
			}
		}
		int mx2=mx+1;
		for (int i=mx+1; i<s.size(); ++i) {
			if (s[i]>s[mx2]) {
				mx2=i;
			}
		}
		ans+=(s[mx]-'0')*10+(s[mx2]-'0');
	}

	cout << ans;
}
