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
    while (getline(cin,s)){
        vc.push_back("    "+s+"    ");
    }
    int n=vc.size(), m=vc[0].size();
    for (int i=0; i<n; ++i){
        for (int j=4; j<m-4; ++j){
            if (j>2){
                s=vc[i].substr(j-3,4);
                if (s=="XMAS" || s=="SAMX") ans++;
            }
            if (i>2){
                s.clear();
                for (int k=i-3; k<=i; ++k){
                    s+=vc[k][j];
                }
                if (s=="XMAS" || s=="SAMX") ans++;
            }
            if (i<n-3){
                s.clear();
                for (int k=0; k<4; ++k){
                    s+=vc[i+k][j+k];
                }
                if (s=="XMAS" || s=="SAMX") ans++;
                s.clear();
                for (int k=0; k<4; ++k){
                    s+=vc[i+k][j-k];
                }
                if (s=="XMAS" || s=="SAMX") ans++;
            }
        }
    }
    cout << ans;
}
