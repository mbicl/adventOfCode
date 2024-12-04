#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool ok(vector<int> vc){
    if (is_sorted(vc.begin(),vc.end())){
        for (int i=1; i<vc.size(); ++i){
            if (vc[i]-vc[i-1]<1 || vc[i]-vc[i-1]>3){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int main(){
    int ans=0;
    string s;
    while (getline(cin,s)){
        // cout << s << endl;
        s+=" ";
        vector<int> vc;
        string a;
        for (char c:s){
            if (c==' '){
                vc.push_back(stoi(a.c_str()));
                a.clear();
            } else {
                a.push_back(c);
            }
        }

        bool cl=0;
        for (int i=0; i<vc.size(); ++i){
            vector<int> v=vc;
            v.erase(v.begin()+i);
            if (ok(v)){
                ans++;
                cl=1;
                break;
            }
        }
        if (cl) continue;
        reverse(vc.begin(),vc.end());

        for (int i=0; i<vc.size(); ++i){
            vector<int> v=vc;
            v.erase(v.begin()+i);
            if (ok(v)){
                ans++;
                cl=1;
                break;
            }
        }
    }

    cout << ans;
}
