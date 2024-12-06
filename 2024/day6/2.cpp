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

string dir = "URDL";
int d;
map<char, pair<int, int>> mp;
vector<string> vc;
set<array<int,3>> vis;
int n, m, x=-1, y;

int go(){
    while (vc[x][y] != ' ') {
        // cout << x << " " << y << endl;
        int i = x + mp[dir[d]].first;
        int j = y + mp[dir[d]].second;
        if (vc[i][j] == '#')
        {
            d++;
            d %= 4;
        }
        else
        {
            if (vis.count({x,y,d})){
                // cout << x << " " << y << " " << d << endl;
                return 1;
            }
            vis.insert({x,y,d});
            x = i;
            y = j;
        }
    }

    return 0;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    vc.push_back(string(140, ' '));

    string s;

    while (cin >> s)
    {
        m = s.size();
        n++;
        s = " " + s + " ";
        vc.push_back(s);
    }
    vc.push_back(string(140, ' '));
    cout << n << " " << m << endl;

    for (int i = 1; i <= n; ++i)
    {
        if (x != -1)
            break;
        for (int j = 1; j <= m; ++j)
        {
            if (vc[i][j] == '^')
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    int ox=x, oy=y;

    int ans=0;

    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (vc[i][j]=='#') continue;
            vc[i][j]='#';
            x=ox, y=oy;
            d=0;
            vis.clear();
            ans+=go();
            vc[i][j]='.';
        }
    }

    cout << ans;
}
