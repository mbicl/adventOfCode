#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

#define int long long

using namespace std;

struct point {
    int x, y, z;
};

double dist(point &a, point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

struct dsu{
	vector<int> p, h;
	int n;
	
	dsu(int n){
		p.assign(n+1,0);
		h.assign(n+1,1);
		for (int i=1; i<=n; ++i){
			p[i]=i;
		}
		this->n=n;
	}
	
	int get(int i){
		if (p[i]!=i) p[i]=get(p[i]);
		return p[i]; 
	}
	int geth(int i){
		return h[get(i)];
	}
	bool same(int a, int b){
		if (get(a)==get(b)) return true;
		else return false;
	}
	void unite(int a, int b){
		int aa=get(a);
		int bb=get(b);
		if (aa==bb) return;
		if (h[aa]>h[bb]){
			p[bb]=aa;
			h[aa]+=h[bb];
		}
		else {
			p[aa]=bb;
			h[bb]+=h[aa];
		}
	}
};

signed main() {
	string s;
	vector<point> v;
	while (getline(cin, s)) {
		int x, y, z;
		char c;
		stringstream(s) >> x >> c >> y >> c >> z;
		v.push_back({x, y, z});
	}

	dsu d(v.size()+10);
	int t=1000;
	vector<vector<bool>> u(v.size()+10, vector<bool>(v.size()+10, false));

	while (t--){
		double mn = 1e18;
		int x,y;
		for (int i=0; i<v.size()-1; ++i){
			for (int j=i+1; j<v.size(); ++j){
				if (!u[i][j]){
					double dis = dist(v[i], v[j]);
					if (dis<mn){
						mn=dis;
						x=i;
						y=j;
					}
				}
			}
		}
		// cout << x << " " << y << "\n";
		u[x][y] = true;
		u[y][x] = true;
		d.unite(x, y);
	}
	cout << "\n";
	int ans = 1;
	vector<int> res;
	vector<bool> used(v.size()+10, false);
	for (int i=0; i<v.size(); ++i){
		int root = d.get(i);
		if (!used[root]){
			used[root]=true;
			int h=d.geth(root);
			res.push_back(h);
			// cout << h << " " << i << " " << root << "\n";
		}
	}

	sort(res.rbegin(), res.rend());
	for (int i=0; i<3; ++i){
		ans*=res[i];
	}

	cout << ans;
}
