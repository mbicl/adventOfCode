#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cassert>
#include <set>

#define int long long

using namespace std;

vector<string> vc;
int n, m, ans;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void go(int i, int j){
    if (vc[i][j]=='9'){
        ans++;
        return;
    }

    for (int k=0; k<4; ++k){
        if (vc[i+dx[k]][j+dy[k]]-vc[i][j]==1){
            go(i+dx[k],j+dy[k]);
        }
    }
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vc.push_back(string(200,'.'));
    string s;
    while (cin >> s){
        n++;
        m=s.size();
        vc.push_back("."+s+".");
    }
    vc.push_back(string(200,'.'));

    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (vc[i][j]=='0'){
                go(i,j);
            }
        }
    }

    cout << ans;
}
