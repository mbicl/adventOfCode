#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define int long long
#define pii pair<int,int>

using namespace std;

signed main() {
    string s;
	vector<pii> vc;
	while (getline(cin,s)) {
		int x, y;
		char c;

		stringstream(s) >> x >> c >> y;

		vc.push_back({x,y});
	}
    
    int n = vc.size();
    set<int> sx, sy;
    for (auto &[x,y]:vc) {
        sx.insert(x);
        sy.insert(y);
    }
    vector<int> xs(sx.begin(),sx.end());
    vector<int> ys(sy.begin(),sy.end());
    
    map<int,int> mpx, mpy;
    for (int i=0; i<xs.size(); ++i) mpx[xs[i]]=i;
    for (int i=0; i<ys.size(); ++i) mpy[ys[i]]=i;
    
    int nx=xs.size(), ny=ys.size();

    vector<array<int,4>> v;
    for (int i=0; i<n; ++i) {
        auto [x1,y1]=vc[i];
        auto [x2,y2]=vc[(i+1)%n];
        v.push_back({x1,y1,x2,y2});
    }
    
    auto check=[&](int i, int j) -> bool {
        if (i+1>=nx || j+1>=ny) return false;
        double x=(xs[i]+xs[i+1])/2.0;
        double y=(ys[j]+ys[j+1])/2.0;

        int cnt=0;
        for (auto &[x1,y1,x2,y2]:v) {
            if (x1==x2) {
                if (x1>x) {
                    double y_min=min((double)y1,(double)y2);
                    double y_max=max((double)y1,(double)y2);
                    if (y_min<y && y<y_max) {
                        cnt++;
                    }
                }
            }
        }
        return cnt%2==1;
    };
    
    vector<vector<bool>> inside(nx, vector<bool>(ny,false));
    for (int i=0; i+1<nx; ++i) {
        for (int j=0; j+1<ny; ++j) {
            inside[i][j]=check(i,j);
        }
    }
    
    vector<vector<int>> pre(nx+1,vector<int>(ny+1,0));
    for (int i=0; i<nx-1; ++i) {
        for (int j=0; j<ny-1; ++j) {
            pre[i+1][j+1]=pre[i][j+1]+pre[i+1][j]-pre[i][j]+(inside[i][j]?1:0);
        }
    }
    
    auto ok=[&](int i1, int j1, int i2, int j2) -> bool {
        int s=(i2-i1)*(j2-j1);
        int sum=pre[i2][j2]-pre[i1][j2]-pre[i2][j1]+pre[i1][j1];
        return sum==s;
    };
    
    int ans = 0;

    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            auto [x1,y1]=vc[i];
            auto [x2,y2]=vc[j];
            if (x1==x2 || y1==y2) continue;
            int xi1=mpx[x1], xi2=mpx[x2];
            int yi1=mpy[y1], yi2=mpy[y2];
            
            if (xi1>xi2) swap(xi1,xi2);
            if (yi1>yi2) swap(yi1,yi2);
            
            if (ok(xi1,yi1,xi2,yi2)) {
                int xl=abs(x2-x1)+1;
                int yl=abs(y2-y1)+1;
                int s=xl*yl;
                ans=max(ans,s);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}