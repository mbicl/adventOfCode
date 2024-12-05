#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cassert>

#define int long long

using namespace std;

string trim(string s){
    while (s.size() && s.back()==' ') s.pop_back();
    while (s.size() && s.front()==' ') s.erase(0,1);
    return s;
}
signed main(){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int ans=0;
    string s;
    bool queries=0;
    map<int,vector<int>> vc;
    int cnt=0;
    while (getline(cin,s)){
        s=trim(s);
        if (s.empty()){
            queries=1;
            continue;
        }

        if (!queries){
            int a=stoi(s.substr(0,2)), b=stoi(s.substr(3,2));
            vc[a].push_back(b);
        } else {
            vector<int> v;
            for (auto &c:s) if (c==',') c=' ';
            stringstream ss(s);
            int a;
            bool ok=1;
            while (ss>>a){
                for (auto i:vc[a]){
                    for (auto j:v){
                        if(i==j){
                            ok=0;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) break;
                v.push_back(a);
            }
            if (!ok) {
                cnt++;
                continue;
            }
            assert(v.size()%2==1);
            ans+=v[v.size()/2];
            
            for (auto i:v) cerr << i << " ";
            cerr << endl;
        }
    }
    cout << ans << " " << cnt;
}
