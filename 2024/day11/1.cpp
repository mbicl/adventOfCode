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

    vector<int> vc;
    int x;
    while (cin >> x){
        vc.push_back(x);
    }
    int t=25;
    while (t--){
        vector<int> v;
        for (auto i:vc){
            if (i==0) v.push_back(1);
            else if (to_string(i).size()%2==0){
                string s=to_string(i);
                v.push_back(stoi(s.substr(0,s.size()/2)));
                v.push_back(stoi(s.substr(s.size()/2,s.size()/2)));
            }
            else v.push_back(i*2024);
        }
        vc=v;
    }

    // for (auto i:vc) cout << i << " ";
    // cout << endl;

    cout << vc.size();
}
