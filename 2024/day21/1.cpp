#include "../../utils/aoc_utils.h"

#include <iostream>
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
    vector<string> g;
    string s;
    int n=0, m;
    point start, end;

    g.push_back(string(200,'#'));
    while (getline(cin,s)){
        n++;
        m=s.size();
        int x=s.find('S');
        if (x!=string::npos){
            start.x=n;
            start.y=x+1;
        }
        x=s.find('E');
        if (x!=string::npos){
            end.x=n;
            end.y=x+1;
        }
        g.push_back("#"+s+"#");
    }
    g.push_back(string(200,'#'));

    vector<vector<int>> dist(n+2,vector<int>(m+2,1e9));
    vector<vector<bool>> vis(n+2,vector<bool>(m+2,0));

    dist[start.x][start.y]=0;
    queue<point> q;
    q.push(start);

    while (q.size()){
        auto [x,y]=q.front(); q.pop();
        if (vis[x][y] || x==end.x && y==end.y) continue;
        vis[x][y]=1;
        int cnt=0;
        for (int i=0; i<4; ++i){
            int nx=x+dx[i], ny=y+dy[i];
            if (g[nx][ny]=='#' || vis[nx][ny]) continue;
            dist[nx][ny]=min(dist[nx][ny],dist[x][y]+1);
            q.push({nx,ny});
            cnt++;
        }
        if (cnt>1) cout << x << " " << y << endl;
    }
    cout << dist[end.x][end.y] << endl;
    int ans=0;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (g[i][j]=='#') continue;
            for (int k=0; k<4; ++k){
                int x=i+dx[k]*2, y=j+dy[k]*2;
                int mx=i+dx[k], my=j+dy[k];
                if (g[x][y]=='#'  || g[mx][my]!='#') continue;
                if (dist[x][y]-dist[i][j]-2>=t){
                    ans++;
                }
            }
        }
    }

    cout << ans;
}
