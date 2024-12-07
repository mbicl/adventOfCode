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

int ok(int &s, vector<int> &v, int sum, int i){
    if (i==v.size()){
        if (sum==s) return 1;
        else return 0;
    }
    if (ok(s,v,sum+v[i],i+1)) return 1;
    if (ok(s,v,sum*v[i],i+1)) return 1;
    string c=to_string(sum)+to_string(v[i]);
    if (ok(s,v,stoll(c),i+1)) return 1;
    return 0;
}
signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int ans=0;

    while (getline(cin,s)){
        string c[2];
        int i=0;
        for (auto it:s){
            if (it==':') i++;
            c[i]+=it;
        }

        c[1].erase(0,2);
        c[1]+=" ";

        vector<int> v;
        string a;
        for (auto it:c[1]){
            if (it==' '){
                v.push_back(stoll(a));
                a.clear();
            } else {
                a+=it;
            }
        }
        int b=stoll(c[0]);
        if (ok(b,v,v[0],1)){
            ans+=stoll(c[0]);
        }
    }

    cout << ans;
}
