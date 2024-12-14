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

    string s;
    
    cin >> s;

    vector<int> vc;
    int id=0;

    for (int i=0; i<s.size(); ++i){
        int j=s[i]-48, p=id;
        if (i%2==0){
            id++;
        } else {
            p=-1;
        }
        for (int k=0; k<j; ++k){
            vc.push_back(p);
        }
    }
    int l=0, r=vc.size()-1;
    while (l<r){
        while (l<r && vc[l]!=-1) l++;
        while (l<r && vc[r]==-1) r--;
        swap(vc[l],vc[r]);
    }

    int ans=0;
    for (int i=0; i<vc.size(); ++i){
        if (vc[i]==-1) break;
        ans+=i*vc[i];
    }
    cout << ans;
}
