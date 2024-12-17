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
    int i=r.x-1;
    while (i>0){
        if (vc[i][r.y]=='#' || vc[i][r.y]=='.') break;
        i--;
    }
    
    if (vc[i][r.y]=='.'){
        for (int j=i+1; j<=r.x; ++j)
            swap(vc[j-1][r.y],vc[j][r.y]);
        r.x--;
    }
}

void down(){
    int i=r.x+1;
    while (i<n){
        if (vc[i][r.y]=='#' || vc[i][r.y]=='.') break;
        i++;
    }
    
    if (vc[i][r.y]=='.'){
        for (int j=i-1; j>=r.x; --j)
            swap(vc[j+1][r.y],vc[j][r.y]);
        r.x++;
    }
}

void left(){
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
            m=s.size();
            vc.push_back(s);
            if (s.find('@')!=string::npos){
                r.y=s.find('@');
                r.x=n;
            }
            n++;
        }
    }

    for (char c:cm){
        if (c=='<') left();
        if (c=='>') right();
        if (c=='^') up();
        if (c=='v') down();
    }

    int ans=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (vc[i][j]=='O') {
                ans+=i*100+j;
            }
        }
    }
    for (auto c:vc){
        cout << c << endl;
    }
    cout << ans;
}
