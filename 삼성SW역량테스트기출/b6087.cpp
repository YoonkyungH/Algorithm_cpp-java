// 레이저 통신
#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> Start, End;

int W, H;
char map[100][100];
int visited[100][100];  // 각 좌표별로 갈 수 있는 최소 거울의 개수

int bfs(int a, int b) {
    queue<pair<pair<int, int>, pair<int, int> > > q;

    // 최초 큐에 (x, y 좌표)를 넣고, (현재 진행방향, 거울개수)를 넣을 때,
    // 현재 진행방향에 동서남북을 모두 넣음
    for(int i=0; i<4; i++) {
        q.push(make_pair(make_pair(a, b), make_pair(i, 0)));
    }   
    visited[a][b] = 0;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;   // 현재 진행방향
        int cnt = q.front().second.second;  // 거울의 개수
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];
            int nCnt = cnt; // nCnt: 현재 거울의 개수

            // 현재 좌표가 범위 내인지,
            // 갈 수 있는 곳인지 검사해서 아니라면 continue;
            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

            if(map[nx][ny] == '*') continue;    // 벽이면 갈 수 없음
            if(dir != i) nCnt += 1; // 현재 방향과 달라졌다면 거울의 개수 +1
            if(visited[nx][ny] >= nCnt) {
                // 현재 거울 개수보다 새로 계산한 거울의 개수가 더 작을 경우 갱신
                visited[nx][ny] = nCnt;
                q.push(make_pair(make_pair(nx, ny), make_pair(i, nCnt)));
            }
        }
    }

    return visited[End.first][End.second];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 0;
    cin >> W >> H;

    bool flag = false;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 'C') {
                if(tmp == 0) {
                    Start.first = i;
                    Start.second = j;
                    tmp++;
                } else {
                    End.first = i;
                    End.second = j;
                }
            }

            visited[i][j] = INF;
        }
    }

    cout << bfs(Start.first, Start.second) << '\n';

    return 0;
}