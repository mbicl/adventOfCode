#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#define int long long

using namespace std;

int f(string s){
    vector<int> v;
    string c;
    int cnt=0;
    for (char a:s){
        if (isdigit(a)){
            c+=a;
        } else {
            if (a!=',') return 0;
            cnt++;
            v.push_back(stoi(c));
            c.clear();
        }
    }
    v.push_back(stoi(c));
    if (cnt!=1 || v.size()!=2 || v[0]>999 || v[1]>999) return 0;
    cerr << v[0] << " " << v[1];
    return v[0]*v[1];
}

signed main(){
    string s;
    int ans=0;

    while (getline(cin,s)){
        for (int i=3; i<s.size(); ++i){
            if (s.substr(i-3,4)=="mul("){
                int j=i+1;
                while (j<s.size() && s[j]!=')') j++;
                if (j>=s.size()) break;
                string c=s.substr(i+1,j-i-1);
                cerr << s.substr(i-3,j-i+4) << " -> " << c << " -> ";
                ans+=f(c);
                cerr << endl;
            }
        }
    }
    cout << ans;
}
