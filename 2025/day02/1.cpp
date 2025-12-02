#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

#define int long long

int t = 100;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int x) {
	string s = to_string(x), c="";
	int n=s.size();
	for (int i=0; i<n; ++i) {
		c+=s.front();
		s.erase(0,1);
		if (s==c) {
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
		// cout << "From " << a << " to " << b << ":\n";
		ans+=dist(a,b);
	}

	cout << ans;
}
