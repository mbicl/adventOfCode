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

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unordered_map<char, vector<vector<int>>> antenna_pos_by_freq;
    set<char> keys;
    int p1 = 0;
    string line;
    vector<string> arr;
    int row=0;
    int xdim = 0, ydim = 0;
    while (getline(cin, line)) {
        for (int col=0; col < line.size(); col++) {
            if (line[col] != '.') {
                if (antenna_pos_by_freq.find(line[col]) == antenna_pos_by_freq.end())
                    antenna_pos_by_freq[line[col]] = {};
                antenna_pos_by_freq[line[col]].push_back({row, col});
                keys.insert(line[col]);
            }
        }
        arr.push_back(line);
        ydim = line.size();
        xdim++;
        row++;
    }

    set<vector<int>> antinode_set;
    for (char key : keys) {
        for (int i=0; i<antenna_pos_by_freq[key].size(); i++) {
            vector<int> pos1 = antenna_pos_by_freq[key][i];
            for (int j=i; j<antenna_pos_by_freq[key].size(); j++) {
                if (i == j)
                    continue;
                vector<int> pos2 = antenna_pos_by_freq[key][j];
                int xdiff, ydiff;
                xdiff = pos2[0] - pos1[0];
                ydiff = pos2[1] - pos1[1];
                if ((0 <= pos1[0] - xdiff && pos1[0] - xdiff < xdim) && (0 <= pos1[1] - ydiff && pos1[1] - ydiff < ydim)) {
                    antinode_set.insert({pos1[0] - xdiff, pos1[1] - ydiff});
                }
                if ((0 <= pos2[0] + xdiff && pos2[0] + xdiff < xdim) && (0 <= pos2[1] + ydiff && pos2[1] + ydiff < ydim))
                    antinode_set.insert({pos2[0] + xdiff, pos2[1] + ydiff});
            }
        }
    }
    for (vector<int> val : antinode_set) {
        cout << val[0] << ',' << val[1] << '\n';
        arr[val[0]][val[1]] = '#';
    }
    for (string line : arr)
        cout << line << '\n';
    cout << antinode_set.size() << '\n';
}