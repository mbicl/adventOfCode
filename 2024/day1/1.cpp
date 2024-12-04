#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    vector<int> left, right;

    int a, b;

    while (cin >> a >> b){
        left.push_back(a);
        right.push_back(b);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int ans=0;
    for (int i=0; i<left.size(); ++i){
        ans+=abs(left[i]-right[i]);
    }

    cout << ans;
}
