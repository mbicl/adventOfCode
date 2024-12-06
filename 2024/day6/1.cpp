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

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> vc;
    vc.push_back(string(100, ' '));

    string s;
    int n = 0, m;

    while (cin >> s)
    {
        m = s.size();
        n++;
        s = " " + s + " ";
        vc.push_back(s);
    }
    vc.push_back(string(100, ' '));
    cout << n << " " << m << endl;
    int x = -1, y;
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

    string dir = "URDL";
    int d = 0;
    map<char, pair<int, int>> mp;
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    set<pair<int, int>> ans;

    while (vc[x][y] != ' ')
    {
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
            ans.insert({x, y});
            x = i;
            y = j;
        }
    }

    cout << ans.size();
}
