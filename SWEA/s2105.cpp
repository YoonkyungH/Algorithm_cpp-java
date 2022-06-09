#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int map[20][20];
bool visited[20][20] = {false, };
vector<int> tmp;
int n;
int ans, startX, startY, m;

int direct[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void dfs(int x, int y, int d) {
    int nx = x + direct[d][0];
    int ny = y + direct[d][1];

    if(d == 3 && nx == startX && ny == startY) {
        int len = tmp.size();
        if(ans < len) {
            ans = len;
        }
        return;
    }
    
    if(nx < 0 || ny < 0 || nx >= n || ny >= n) return;
    if(find(tmp.begin(), tmp.end(), map[nx][ny]) != tmp.end()) return;

    tmp.push_back(map[nx][ny]);
    if(d == 3) {
        dfs(nx, ny, d);
    } else {
        dfs(nx, ny, d);
        dfs(nx, ny, d+1);
    }
    tmp.pop_back();

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        cin >> n;

        memset(map, 0, sizeof(map));
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                cin >> map[j][k];
            }
        }

        ans = -1;
        for(int j=0; j<n-2; j++) {
            for(int k=0; k<n-1; k++) {
                tmp.clear();
                tmp.push_back(map[j][k]);
                startX = j; startY = k;
                dfs(j, k, 0);
            }
        }
        
        cout << "#" << i << " " << ans << '\n';
    }

    return 0;
}