#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cassert>
#include <set>
#include <queue>
#include <functional>

#include "../../utils/aoc_utils.h"

#define int long long

using namespace std;

struct point{
    int x, y;

    inline bool operator < (const point & o) const {
        if (x==o.x) return y<o.y;
        return x<o.x;
    }
};

struct dpoint {
    point p;
    char direction;
    int score;

    inline bool operator < (const dpoint & o) const {
        return score > o.score;
    }    
};

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> vc;
    string line;
    point s, e;
    int n=0, m;
    while (getline(cin,line)){
        vc.push_back(line);
        m=line.size();
        if (line.find('S')!=string::npos){
            s.x=n;
            s.y=line.find('S');
        }
        if (line.find('E')!=string::npos){
            e.x=n;
            e.y=line.find('E');
        }
        n++;
    }

    map<char,point> dir={
        {'L',{0,-1}},
        {'R',{0,1}},
        {'U',{-1,0}},
        {'D',{1,0}}
    };

    priority_queue<dpoint> q;
    q.push({
        .p=s,
        .direction='R',
        .score=0
    });

    vector<vector<int>> dis(n,vector<int>(m,1e9));
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    dis[s.x][s.y]=0;
    while (q.size()){
        auto d=q.top(); q.pop();
        auto [x,y]=d.p;
        if (vis[x][y] || vc[x][y]=='#' || x==e.x && y==e.y || d.score!=dis[x][y]) continue;
        vis[x][y]=1;

        char left, right, front=d.direction, back;
        if (front=='R') {
            left='U';
            right='D';
            back='L';
        }
        if (front=='L') {
            left='D';
            right='U';
            back='R';
        }
        if (front=='U') {
            left='L';
            right='R';
            back='D';
        }
        if (front=='D') {
            left='R';
            right='L';
            back='U';
        }

        int dx=dir[left].x+x, dy=dir[left].y+y;
        if (vc[dx][dy]!='#' && dis[x][y]+1001<dis[dx][dy]){
            dis[dx][dy]=dis[x][y]+1001;
            q.push({.p={dx,dy}, .direction=left, .score=dis[dx][dy]});
        }

        dx=dir[right].x+x, dy=dir[right].y+y;
        if (vc[dx][dy]!='#' && dis[x][y]+1001<dis[dx][dy]){
            dis[dx][dy]=dis[x][y]+1001;
            q.push({.p={dx,dy}, .direction=right, .score=dis[dx][dy]});
        }

        dx=dir[front].x+x, dy=dir[front].y+y;
        if (vc[dx][dy]!='#' && dis[x][y]+1<dis[dx][dy]){
            dis[dx][dy]=dis[x][y]+1;
            q.push({.p={dx,dy}, .direction=front, .score=dis[dx][dy]});
        }
    }

    set<point> st;

    function<void(dpoint,vector<vector<bool>>&,vector<point>)> go;
    go=[&dis,&e,&st,&dir,&vc,&go](dpoint cur, vector<vector<bool>> &vis, vector<point> path){
        auto [x,y]=cur.p;
        if (cur.score>dis[e.x][e.y] || cur.score>dis[x][y]+1000) return;
        if (x==e.x && y==e.y && cur.score==dis[e.x][e.y]){
            for (auto i:path){
                st.insert(i);
            }
            return;
        }
        if (vis[x][y] || vc[x][y]=='#' || x==e.x && y==e.y) return;
        vis[x][y]=1;
        
        char left, right, front=cur.direction;
        if (front=='R') {
            left='U';
            right='D';
        }
        if (front=='L') {
            left='D';
            right='U';
        }
        if (front=='U') {
            left='L';
            right='R';
        }
        if (front=='D') {
            left='R';
            right='L';
        }

        int dx=dir[left].x+x, dy=dir[left].y+y;
        if (vc[dx][dy]!='#'){
            path.push_back({dx,dy});
            go(
                {.p={dx,dy}, .direction=left, .score=cur.score+1001},
                vis,
                path
            );
            path.pop_back();
        }

        dx=dir[right].x+x, dy=dir[right].y+y;
        if (vc[dx][dy]!='#'){
            path.push_back({dx,dy});
            go(
                {.p={dx,dy}, .direction=right, .score=cur.score+1001},
                vis,
                path
            );
            path.pop_back();
        }

        dx=dir[front].x+x, dy=dir[front].y+y;
        if (vc[dx][dy]!='#'){
            path.push_back({dx,dy});
            go(
                {.p={dx,dy}, .direction=front, .score=cur.score+1},
                vis,
                path
            );
            path.pop_back();
        }
        vis[x][y]=0;
    };

    vis=vector<vector<bool>>(n,vector<bool>(m,0));
    go({.p=s,.direction='R',.score=0},vis,{s});

    cout << st.size();
}