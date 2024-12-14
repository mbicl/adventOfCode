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
int n, m, s, p;

bool vis[555][555];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void go(int i, int j){
    if (vis[i][j]) return;
    vis[i][j]=1;
    s++;

    for (int k=0; k<4; ++k){
        int x=i+dx[k], y=j+dy[k];
        if (vc[x][y]==vc[i][j]){
            go(x,y);
        }
    }

    if (vc[i-1][j]!=vc[i][j] && vc[i][j-1]!=vc[i][j]) p++;
    if (vc[i-1][j]!=vc[i][j] && vc[i][j+1]!=vc[i][j]) p++;
    if (vc[i+1][j]!=vc[i][j] && vc[i][j-1]!=vc[i][j]) p++;
    if (vc[i+1][j]!=vc[i][j] && vc[i][j+1]!=vc[i][j]) p++;

    if (vc[i-1][j]==vc[i][j] && vc[i][j-1]==vc[i][j] && vc[i-1][j-1]!=vc[i][j]) p++;
    if (vc[i-1][j]==vc[i][j] && vc[i][j+1]==vc[i][j] && vc[i-1][j+1]!=vc[i][j]) p++;
    if (vc[i+1][j]==vc[i][j] && vc[i][j-1]==vc[i][j] && vc[i+1][j-1]!=vc[i][j]) p++;
    if (vc[i+1][j]==vc[i][j] && vc[i][j+1]==vc[i][j] && vc[i+1][j+1]!=vc[i][j]) p++;
}
signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vc.push_back(string(200,' '));
    string sss;
    while (cin >> sss){
        n++;
        m=sss.size();
        vc.push_back(" "+sss+" ");
    }
    vc.push_back(string(200,' '));

    int ans=0;

    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (vis[i][j]) continue;
            s=0;
            p=0;
            go(i,j);
            cout << vc[i][j] << " " << p << endl;
            ans+=s*p;
        }
    }

    cout << ans;
}
