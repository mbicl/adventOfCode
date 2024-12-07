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

int ok(int s, vector<int> v){
    int n=v.size();
    for (int i=0; i<(1<<(n-1)); ++i){
        int sum=v[0];
        for (int j=0; j<n-1; ++j){
            if (i&(1<<j)){
                sum*=v[j+1];
            } else {
                sum+=v[j+1];
            }
        }
        if (sum==s){
            return 1;
        }
    }
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

        if (ok(stoll(c[0]),v)){
            ans+=stoll(c[0]);
        }
    }

    cout << ans;
}
