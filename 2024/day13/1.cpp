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
        if (cnt==1) res.x=a;
        if (cnt==2) res.y=a;
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
        bool ok=0;
        int mn=1e18;

        int cnt=max(c.x/a.x,c.y/a.y);
        for (int i=cnt; i>=0; --i){
            if (i*a.x>c.x || i*a.y>c.y) continue;
            int x=(c.x-i*a.x)/b.x, y=(c.y-i*a.y)/b.y;

            if (y!=x || i*a.x+x*b.x!=c.x || i*a.y+y*b.y!=c.y) continue;

            mn=min(i*3+x,mn);
            ok=1;
        }

        cnt=max(c.x/b.x,c.y/b.y);
        for (int i=cnt; i>=0; --i){
            if (i*b.x>c.x || i*b.y>c.y) continue;
            int x=(c.x-i*b.x)/a.x, y=(c.y-i*b.y)/a.y;

            if (y!=x || i*b.x+x*a.x!=c.x || i*b.y+y*a.y!=c.y) continue;

            mn=min(i+x*3,mn);
            ok=1;
        }

        if (ok) {
            ans+=mn;
        }
    }
    cout << ans;
}
