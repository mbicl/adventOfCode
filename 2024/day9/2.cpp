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
            for (int k=0; k<j; ++k){
                vc.push_back(id*10+j);
            }
            id++;
        } else {
            for (int k=0; k<j; ++k){
                vc.push_back(-j);
            }
        }
        
    }
    int l=0, r=vc.size()-1;
    map<int,bool> used;
    while (1){
        l=0;
        while (l<r && vc[l]>0) l++;
        while (l<r && (vc[r]<0 || used.count(vc[r]/10))) r--;
        if (l>=r) break;
        l=0;
        while (l<r && (vc[l]>0 || -vc[l]<vc[r]%10)) l++;
        used[vc[r]/10]=1;
        if (l>=r) continue;

        int c=vc[r]%10;
        while (c>0 && l<r){
            vc[l]=vc[r];
            vc[r]=-100;
            l++;r--;
            c--;
        }

        c=0;
        int ll=l;
        while (ll<r && vc[ll]<0) c++, ll++;

        ll=l;
        while (ll<r && vc[ll]<0) vc[ll]=-c, ll++;
    }

    int ans=0;
    for (int i=0; i<vc.size(); ++i){
        // if (vc[i]>0) cout << vc[i]/10 << " ";
        // else cout << vc[i] << " ";
        if (vc[i]<0) continue;
        ans+=i*(vc[i]/10);
    }
    cout << endl;
    cout << ans;
}
