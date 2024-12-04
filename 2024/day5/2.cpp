#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#define int long long

using namespace std;

signed main(){
    int ans=0;
    vector<string> vc;
    string s;
    vc.push_back(string(1000,' '));
    while (getline(cin,s)){
        vc.push_back(" "+s+" ");
    }
    vc.push_back(string(1000,' '));

    int n=vc.size(), m=vc[1].size();
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<m-1; ++j){
            if (vc[i][j]=='A'){
                string a;
                a+=vc[i-1][j-1];
                a+=vc[i][j];
                a+=vc[i+1][j+1];

                string b;
                b+=vc[i-1][j+1];
                b+=vc[i][j];
                b+=vc[i+1][j-1];

                if ((a=="SAM" || a=="MAS") && (b=="SAM" || b=="MAS")) ans++;
            }
        }
    }
    cout << ans;
}
