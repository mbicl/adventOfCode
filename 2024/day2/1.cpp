#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

        if (is_sorted(vc.begin(),vc.end())){
            bool ok=1;
            for (int i=1; i<vc.size(); ++i){
                if (vc[i]-vc[i-1]<1 || vc[i]-vc[i-1]>3){
                    ok=0;
                    break;
                }
            }
            if (ok) {
                ans++;
                continue;
            }
        }
        reverse(vc.begin(),vc.end());
        if (is_sorted(vc.begin(),vc.end())){
            bool ok=1;
            for (int i=1; i<vc.size(); ++i){
                if (vc[i]-vc[i-1]<1 || vc[i]-vc[i-1]>3){
                    ok=0;
                    break;
                }
            }
            if (ok) {
                ans++;
                continue;
            }
        }
    }

    cout << ans;
}
