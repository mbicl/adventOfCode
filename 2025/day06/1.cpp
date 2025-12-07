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
    vector<vector<int>> vc;
    vector<string> ops;
    string line;

    while (getline(cin, line)) {
        line = aoc::str::trim(line);
        if (line.front() == '*' || line.front() == '+') {
            ops = aoc::str::split(line, ' ');
        } else {
            auto parts = aoc::str::split(line, ' ');
            vector<int> row;
            for (auto &p : parts) {
                row.push_back(stoll(p));
            }
            vc.push_back(row);
        }
    }

    int ans = 0;
    vector<int> v(ops.size(),0);
    for (int i=0; i<ops.size(); i++) {
        if (ops[i]=="*") v[i]=1;
    }

    for (int i=0; i<vc.size(); i++) {
        for (int j=0; j<ops.size(); j++) {
            if (ops[j]=="*") {
                v[j] *=vc[i][j];
            } else {
                v[j] +=vc[i][j];
            }
        }
    }

    for (int i=0; i<v.size(); i++) {
        ans += v[i];
    }
    cout << ans << "\n";
}
