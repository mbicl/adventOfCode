#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

int t = 100;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int x) {
	// if (x==1010) cout << "here\n";
	string s = to_string(x), c;
	for (int i=0; i<s.size(); ++i) {
		c+=s[i];
		int cnt=0;
		bool ok = true;
		for (int j=0; j<s.size(); j+=c.size()) {
			if (s.substr(j,c.size())==c) {
				cnt++;
			} else {
				ok=false;
				break;
			}
		}
		if (ok && cnt>=2) {
			return true;
		}
	}
	return false;
}

int dist(int a, int b) {
	int ans=0;
	for (int i=a; i<=b; i++) {
		if (check(i)) {
			ans+=i;
			// cout << i << "\n";
		}
	}
	return ans;
}
signed main() {
	string s;
	getline(cin,s);
	auto v = aoc::str::split(aoc::str::trim(s), ',');
	int ans = 0;

	for (auto i:v) {
		auto j = aoc::str::split(aoc::str::trim(i),'-');

		int a = stoll(j[0]);
		int b = stoll(j[1]);
		cout << "From " << a << " to " << b << ":\n";
		ans+=dist(a,b);
	}

	cout << ans;
}
