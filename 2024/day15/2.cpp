#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cassert>
#include <set>

#include "../../utils/aoc_utils.h"

#define int long long

using namespace std;

struct point{
    int x, y;
};

vector<string> vc;
point r;
int n=0, m;

void up(){
    cout << "^\n";
    map<int,set<int>> levels;
    levels[r.x].insert(r.y);
    int l=r.x-1;
    bool ok=1;

    while (ok){
        int cnt=0;
        for (int c:levels[l+1]){
            if (vc[l][c]=='#') {
                ok=0;
                break;
            }
            if (vc[l][c]=='[') {
                cnt++;
                levels[l].insert(c);
                levels[l].insert(c+1);
            }
            if (vc[l][c]==']'){
                levels[l].insert(c-1);
                levels[l].insert(c);
                cnt++;
            }
        }
        if (cnt==0) break;
        l--;
    }
    if (!ok) return;
    
    l++;
    while (l<=r.x){
        for (int c:levels[l]){
            swap(vc[l][c],vc[l-1][c]);
        }
        l++;
    }
    r.x--;
}

void down(){
    cout << "v\n";
    map<int,set<int>> levels;
    levels[r.x].insert(r.y);
    int l=r.x+1;
    bool ok=1;

    while (ok){
        int cnt=0;
        for (int c:levels[l-1]){
            if (vc[l][c]=='#') {
                ok=0;
                break;
            }
            if (vc[l][c]=='[') {
                cnt++;
                levels[l].insert(c);
                levels[l].insert(c+1);
            }
            if (vc[l][c]==']'){
                levels[l].insert(c-1);
                levels[l].insert(c);
                cnt++;
            }
        }
        if (cnt==0) break;
        l++;
    }
    if (!ok) return;

    l--;
    while (l>=r.x){
        for (int c:levels[l]){
            swap(vc[l][c],vc[l+1][c]);
        }
        l--;
    }
    r.x++;
}

void left(){
    cout << "<\n";
    int i=r.y-1;
    while (i>0){
        if (vc[r.x][i]=='#' || vc[r.x][i]=='.') break;
        i--;
    }
    
    if (vc[r.x][i]=='.'){
        for (int j=i+1; j<=r.y; ++j)
            swap(vc[r.x][j-1],vc[r.x][j]);
        r.y--;
    }
}

void right(){
    cout << ">\n";
    int i=r.y+1;
    while (i<m){
        if (vc[r.x][i]=='#' || vc[r.x][i]=='.') break;
        i++;
    }
    
    if (vc[r.x][i]=='.'){
        for (int j=i-1; j>=r.y; --j)
            swap(vc[r.x][j+1],vc[r.x][j]);
        r.y++;
    }
}

void print_map(){
    // for (auto c:vc){
    //     cout << c << endl;
    // }
    // cout << endl;
}
signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, cm;
    bool l=0;

    while (getline(cin,s)){
        s=aoc::str::trim(s);
        if (s.empty()){
            l=1;
        }

        if (l) cm.append(s);
        else {
            string ss;
            for (char c:s){
                if (c=='@') ss+="@.";
                else if (c=='O') ss+="[]";
                else {
                    ss.push_back(c);
                    ss.push_back(c);
                }
            }
            m=ss.size();
            vc.push_back(ss);
            if (ss.find('@')!=string::npos){
                r.y=ss.find('@');
                r.x=n;
            }
            n++;
        }
    }
    cout << "org:\n";
    print_map();
    for (char c:cm){
        if (c=='<') left();
        if (c=='>') right();
        if (c=='^') up();
        if (c=='v') down();
        print_map();
    }

    int ans=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (vc[i][j]=='[') {
                ans+=i*100+j;
            }
        }
    }
    cout << ans;
}
