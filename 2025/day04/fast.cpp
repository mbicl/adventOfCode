#pragma GCC optimize("O3,unroll-loops")

#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

int t = 100;

int dx[] = {-1, 0, 0, 1, -1, 1, -1, 1};
int dy[] = {0, -1, 1, 0, -1, -1, 1, 1};
char g[3002][3002];

void solve() {
    ifstream fin("large_input.txt");
    ofstream fout("output.txt");
	for (int i=1; i<3001; ++i) {
        for (int j=1; j<3001; ++j) {
            fin >> g[i][j];
        }
    }
	
	int n = 3002;
	int m = 3002;
	int ans = 0;
	int cnt = 0;

	do {
		cnt=0;
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (g[i][j] != '@') continue;
				int c = 0;
				for (int d = 0; d < 8; d++) {
					if (g[i + dx[d]][j + dy[d]] == '@') c++;
				}
				if (c < 4) {
					g[i][j] = '.';
					cnt++;
				}
			}
		}
		ans+=cnt;
	} while (cnt > 0);

	fout << ans;
}

int main() {
    ofstream perf_out("perf.txt", ios::app);
    auto start = chrono::high_resolution_clock::now();

    solve();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    perf_out << "Execution time (C++): " << duration.count() << " ms\n";

    return 0;
}