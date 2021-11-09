// 그림

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int ans = 0, cnt = 0, art = 0;

int map[500][500];
bool visited[500][500] = {false, };

// 동 남 서 북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    cnt = 0;
    
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    visited[x][y] = true;

    while(!q.empty()) {
        cnt++;  // 그림의 면적을 알아내기 위해 한 칸씩 돌 때마다 cnt 증가

        x = q.front().first;
        y = q.front().second;
        q.pop();

        // if(map[x][y] == 1) { cnt++; }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<n && 0<=ny && ny<m) {
                if(map[nx][ny] != 0 && visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    ans = max(ans, cnt);    // 가장 큰 그림의 넓이만 구해야하므로 애초에 ans에 지금까지 구해진 것 중 가장 큰 넓이로만 넣어줌
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;  // 세로, 가로

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // 방문하지 않았으며 그림이 있는 곳이라면 그림의 개수를 하나 증가시키고 그림 크기를 알아내기 위해 bfs 호출
            if(visited[i][j] == false && map[i][j] == 1) { art++; bfs(i, j); }
        }
    }
    
    cout << art << ' ' << ans << '\n';


    return 0;
}