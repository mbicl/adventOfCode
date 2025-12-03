#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

#define int long long

signed main() {
	int ans = 0;
	string s;
	while (cin >> s) {
		string c;
		int cnt=12, f=0;

		while (cnt>0) {
			int mx=f;
			for (int i=mx; i<s.size()-cnt+1; ++i) {
				if (s[i]>s[mx]) {
					mx=i;
				}
			}
			c+=s[mx];
			f=mx+1;
			cnt--;
		}

		ans+=stoll(c);
	}

	cout << ans;
}
