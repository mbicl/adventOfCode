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
	int a=50, ans=0;
	string s;
	while (cin >> s) {
		char c=s[0];
		int x;
		s.erase(0,1);
		stringstream(s) >> x;
		if (c=='L') {
			while (x--) {
				a--;
				if (a==0) ans++;
				if (a==-1) a=99;
			}
		}
		else {
			while (x--) {
				a++;
				if (a==100) a=0;
				if (a==0) ans++;
			}
		}
	}

	cout << ans;
}
