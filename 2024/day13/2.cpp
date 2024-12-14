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

struct point{
    int x, y;
};

point ab(string s){
    int a=0, cnt=0;
    point res;
    for (char c:s){
        if (isdigit(c)) a=a*10+(c-48);
        if (c=='+') a=0, cnt++;
        if (cnt==1) res.x=a;
        if (cnt==2) res.y=a;
    }
    return res;
}

point xx(string s){
    int a=0, cnt=0;
    point res;
    for (char c:s){
        if (isdigit(c)) a=a*10+(c-48);
        if (c=='=') a=0, cnt++;
        if (cnt==1) res.x=a+10000000000000;
        if (cnt==2) res.y=a+10000000000000;
    }
    return res;
}

string trim(string s){
    while (s.size() && s.back()==' '){
        s.pop_back();
    }
    while (s.size() && s.front()==' ') s.erase(0,1);
    return s;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    vector<string> v;
    point a, b, c;/* code */
    int ans=0, cnt1=0;

    while (getline(cin,s)){
        s=trim(s);
        if (s.size()) {
            v.push_back(s);
            continue;
        }
        cnt1++;
        cerr << v.size() << endl;
        a=ab(v[0]);
        b=ab(v[1]);
        c=xx(v[2]);
        cout << a.x << " " << a.y << endl;
        cout << b.x << " " << b.y << endl;
        cout << c.x << " " << c.y << endl << endl;
        v.clear();
        
        int da=a.x*b.y-a.y*b.x;
        int xa=c.x*b.y-c.y*b.x;
        int db=a.x*b.y-a.y*b.x;
        int xb=c.y*a.x-c.x*a.y;

        if (xa%da==0 && xb%db==0) {
            ans+=xa/da*3;
            ans+=xb/db;
        }
    }
    cout << ans << endl;
}
