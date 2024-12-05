#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
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

vector<int> vc[101];
vector<int> vs;
bool vis[101];

void go(int i){
    if (vis[i]) return;
    vis[i]=1;
    for (auto j:vc[i]) go(j);
    vs.push_back(i);
}
signed main(){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int ans=0;
    string s;
    bool queries=0;
    int cnt=0;
    while (getline(cin,s)){
        s=trim(s);
        if (s.empty()){
            for (int i=1; i<=100; ++i){
                go(i);
                if (vc[i].size()){
                    cout << i << " -> ";
                    for (auto j:vc[i]) cout << j << " ";
                    cout << endl;
                }
            }
            queries=1;
            continue;
        }

        if (!queries){
            int a=stoi(s.substr(0,2)), b=stoi(s.substr(3,2));
            vc[b].push_back(a);
        } else {
            vector<int> v;
            for (auto &c:s) if (c==',') c=' ';
            stringstream ss(s);
            int a;
            while (ss>>a){
                v.push_back(a);
            }
            bool ok=1;
            for (int i=0; i<v.size(); ++i){
                for (int k:vc[v[i]]){
                    for (int j=i+1; j<v.size(); ++j){
                        if (k==v[j]){
                            ok=0;
                        }
                    }
                }
            }
            if (ok) continue;
            cnt++;

            for (int i=0; i<v.size();){
                int dif=1;
                for (int j=i+1; j<v.size(); ++j){
                    for (int k:vc[v[i]]){
                        if (k==v[j]){
                            dif=0;
                            swap(v[i],v[j]);
                            break;
                        }
                    }
                    if (dif==0) break;
                }
                i+=dif;
            }
            for (auto i:v) cout << i << " ";
            cout << endl;

            ans+=v[v.size()/2];
        }
    }
    cout << ans << " " << cnt;
}
