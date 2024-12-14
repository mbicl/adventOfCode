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

map<pair<int,int>,int> mp;

int go(int n, int t){
    if (t==0) return 1;
    if (mp.count({n,t})) return mp[{n,t}];
    if (n==0){
        mp[{n,t}]=go(1,t-1);
    }
    else if (to_string(n).size()%2==0){
        string s=to_string(n);
        mp[{n,t}]+=go(stoi(s.substr(0,s.size()/2)),t-1);
        mp[{n,t}]+=go(stoi(s.substr(s.size()/2,s.size()/2)),t-1);
    }
    else {
        mp[{n,t}]=go(n*2024,t-1);
    }
    return mp[{n,t}];
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> vc;
    int x;
    while (cin >> x){
        vc.push_back(x);
    }
    
    int ans=0;

    for (auto i:vc){
        ans+=go(i,75);
    }

    cout << ans;
}
