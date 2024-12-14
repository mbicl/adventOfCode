#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cassert>
#include <set>

#include <opencv2/opencv.hpp>

#define int long long

using namespace std;

cv::Mat convertVectorToMat(const std::vector<std::vector<int>>& vec) {
    int rows = vec.size();
    int cols = vec[0].size();

    cv::Mat mat(rows, cols, CV_32S);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat.at<int>(i, j) = vec[i][j];
        }
    }

    return mat;
}

cv::Mat convertToGrayscale(const cv::Mat& mat) {
    double minVal, maxVal;
    cv::minMaxLoc(mat, &minVal, &maxVal);

    cv::Mat grayMat;
    mat.convertTo(grayMat, CV_8U, 255.0 / (maxVal - minVal), -minVal * 255.0 / (maxVal - minVal));
    return grayMat;
}

struct point {
    int x, y;
};

struct robot {
    point pos;
    point v;
};

vector<string> split(string s, char c=' '){
    vector<string> res;
    string a;
    for (char i:s){
        if (i==c) {
            if (a.size()) res.push_back(a);
            a.clear();
        } else {
            a+=i;
        }
    }
    if (a.size()) res.push_back(a);
    return res;
}

robot parse(string s) {
    vector<string> v=split(s);
    v[0].erase(0,2);
    v[1].erase(0,2);
    vector<string> l=split(v[0],',');
    vector<string> r=split(v[1],',');
    robot res={{stoi(l[0]),stoi(l[1])},{stoi(r[0]),stoi(r[1])}};
    return res;
}

int score(vector<vector<int>> &vc, int n, int m){
    int mxi=0, mxj=0;
    for (int i=0; i<n; i++) {
        int cnt=0;
        for (int j=0; j<m; j++) {
            cnt+=vc[i][j];
        }
        mxi=max(mxi,cnt);
    }
    for (int j=0; j<m; j++) {
        int cnt=0;
        for (int i=0; i<n; i++) {
            cnt+=vc[i][j];
        }
        mxj=max(mxj,cnt);
    }
    return mxi*mxj;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<robot> vc;
    string s;
    while (getline(cin,s)){
        vc.push_back(parse(s));
    }

    int n=103, m=101;

    int ans=0, mx=0;

    vector<vector<int>> img;
    for (int t=0; t<=n*m; ++t) {
        vector<vector<int>> cnt(n,vector<int>(m));
        for (auto &r:vc) {
            cnt[r.pos.y][r.pos.x]=1;

            r.pos.x+=r.v.x;
            r.pos.x%=m;
            r.pos.x+=m;
            r.pos.x%=m;

            r.pos.y+=r.v.y;
            r.pos.y%=n;
            r.pos.y+=n;
            r.pos.y%=n;
        }
        int sc=score(cnt,n,m);
        if (sc>mx){
            mx=sc;
            ans=t;
            img=cnt;
        }
    }

    cv::Mat mat=convertToGrayscale(convertVectorToMat(img));
    cv::imwrite("rasm.png",mat);
    cout << ans;
}
