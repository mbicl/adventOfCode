#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
#define int long long

signed main(){
    vector<int> left;
    map<int,int> mp;

    int a, b;

    while (cin >> a >> b){
        left.push_back(a);
        mp[b]++;
    }

    int ans=0;
    for (int i=0; i<left.size(); ++i){
        ans+=left[i]*mp[left[i]];
    }

    cout << ans;
}
