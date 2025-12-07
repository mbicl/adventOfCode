#include "../../utils/aoc_utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

#define int long long

int t = 100;

struct point {
    int x, y;
};

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

signed main() {
    vector<string> g;
    vector<string> ops;
    string line;

    while (getline(cin, line)) {
        if (line.front() == '*' || line.front() == '+') {
            ops = aoc::str::split(line, ' ');
        } else {
            g.push_back(line);
        }
    }

    int cnt = 0, ans = 0;
    vector<int> col;

    int n=g.size();
    int m=g[0].size();

    for (int j=0; j<m; ++j){
        string cur;
        for (int i=0; i<n; ++i){
            if (isdigit(g[i][j])){
                cur+=g[i][j];
            }
        }
        if (cur.size()){
            col.push_back(stoll(cur));
        } else {
            // for (auto &x : col){
            //     cout << x << " ";
            // }
            // cout << "\n";
            if (ops[cnt]=="*"){
                int res = 1;
                for (auto &x : col){
                    res*=x;
                }
                ans += res;
            } else {
                int res = 0;
                for (auto &x : col){
                    res+=x;
                }
                ans += res;
            }
            cnt++;
            col.clear();
        }
    }
    // for (auto &x : col){
    //     cout << x << " ";
    // }
    // cout << "\n";
    if (ops[cnt]=="*"){
        int res = 1;
        for (auto &x : col){
            res*=x;
        }
        ans += res;
    } else {
        int res = 0;
        for (auto &x : col){
            res+=x;
        }
        ans += res;
    }
    col.clear();

    cout << ans << "\n";
}
