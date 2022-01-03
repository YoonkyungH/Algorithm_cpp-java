// 게임
// DFS

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int ans;
char board[51][51];
bool visited[51][51] = {false, };
int DP[51][51];

// 좌 하 상 우
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool dfs(int y, int x, int cnt) {   // row, column
    if(ans == -1) { return true; }  // 무한대로 움직일 수 있는 경우

    ans = max(ans, cnt);

    visited[y][x] = true;
    DP[y][x] = cnt; // DP 배열에 값을 업데이트

    for(int i=0; i<4; i++) {    // 상하좌우 검사
        int ny = y + dy[i]*(board[y][x] - '0'); // !! 문자열이라 '0'을 빼면 int 가 됨
        int nx = x + dx[i]*(board[y][x] - '0');

        if(ny<0 || ny>=N || nx<0 || nx>=M || board[ny][nx] == 'H') { continue; }    // 범위에 어긋나거나 구멍일땐 탐색 X

        // !! 방문한 곳에 또 왔다면 무한번 움직일 수 있다는 것
        if(visited[ny][nx]) {   
            ans = -1; return true;
        }

        // DP에 있는 값이 cnt보다 크면 이미 더 길게 움직이는 것이 계산되어 있다는 것
        if(DP[ny][nx] > 0 && cnt < DP[ny][nx]) { continue; }
        
        // 무한번 움직일 수 있다면 true 반환
        if(dfs(ny, nx, cnt+1)) { return true; }
    }
    
    // 다시 돌아왔기 때문에 false로 되돌려놓음
    visited[y][x] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> M;

    // for(int i=0; i<N; i++) {
    //     cin >> board[i];
    // }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 1);

    cout << ans << '\n';

    return 0;
}