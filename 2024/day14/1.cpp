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

struct point {
    int x, y;
};

struct robot {
    point pos;
    point v;
};

vector<string> split(string s, char c=' '){
    vector<string> res;
    string a;
    for (char i:s){
        if (i==c) {
            if (a.size()) res.push_back(a);
            a.clear();
        } else {
            a+=i;
        }
    }
    if (a.size()) res.push_back(a);
    return res;
}

robot parse(string s) {
    vector<string> v=split(s);
    v[0].erase(0,2);
    v[1].erase(0,2);
    vector<string> l=split(v[0],',');
    vector<string> r=split(v[1],',');
    robot res={{stoi(l[1]),stoi(l[0])},{stoi(r[1]),stoi(r[0])}};
    return res;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<robot> vc;
    string s;
    while (getline(cin,s)){
        vc.push_back(parse(s));
    }

    int n=103, m=101, cnt=100;
    vector<vector<int>> c(n,vector<int>(m,0));

    for (auto r:vc){
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        vector<point> pos;
        while (!vis[r.pos.x][r.pos.y]){
            pos.push_back(r.pos);
            vis[r.pos.x][r.pos.y]=1;
            r.pos.x+=r.v.x;
            r.pos.y+=r.v.y;
            r.pos.x%=n;
            r.pos.x+=n;
            r.pos.x%=n;
            r.pos.y%=m;
            r.pos.y+=m;
            r.pos.y%=m;
        }
        point i=pos[cnt%pos.size()];
        c[i.x][i.y]++;
    }

    int q1=0, q2=0, q3=0, q4=0;

    for (int i=0; i<n/2; ++i){
        for (int j=0; j<m/2; ++j){
            q1+=c[i][j];
        }
    }
    for (int i=(n+1)/2; i<n; ++i){
        for (int j=0; j<m/2; ++j){
            q2+=c[i][j];
        }
    }
    for (int i=0; i<n/2; ++i){
        for (int j=(m+1)/2; j<m; ++j){
            q3+=c[i][j];
        }
    }
    for (int i=(n+1)/2; i<n; ++i){
        for (int j=(m+1)/2; j<m; ++j){
            q4+=c[i][j];
        }
    }
    int ans=q1*q2*q3*q4;

    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << q1 << " " << q2 << " " << q3 << " " << q4 << endl;
    cout << ans;
}
