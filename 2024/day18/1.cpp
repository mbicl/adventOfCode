#include "../../utils/aoc_utils.h"
#include <bits/stdc++.h>

using namespace std;

struct point{
	int x, y;
};

point input(){
	string s;
	getline(cin,s);
	auto v=aoc::str::split(s,',');
	return {stoi(v[0]),stoi(v[1])};
}

signed main() {
	vector<vector<char>> g(77,vector<char>(77,'.'));
	
	for (int i=0; i<1024; ++i){
		auto [x,y]=input();
		g[x][y]='#';
	}

	queue<point> q;
	vector<vector<int>> dist(77,vector<int>(77,7070));
	q.push({0,0});
	dist[0][0]=0;

	int dx[]={-1,0,0,1};
	int dy[]={0,-1,1,0};

	while (q.size()){
		auto [x,y]=q.front(); q.pop();
		if (g[x][y]=='#') continue;
		g[x][y]='#';

		for (int i=0; i<4; ++i){
			int nx=x+dx[i], ny=y+dy[i];
			if (nx<0 || nx>70 || ny<0 || ny>70) continue;
			q.push({nx,ny});
			dist[nx][ny]=min(dist[nx][ny],dist[x][y]+1);
		}
	}

	cout << dist[70][70];
}
