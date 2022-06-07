// 탈주범 검거
// 백트래킹 + dfs

#include <iostream>
#include <string.h> // memset
using namespace std;

int map[50][50];
bool visited[50][50] = {false, };
bool location[50][50];
int N, M, R, C, L; // 세로, 가로, 멘홀의 세로, 가로, 소요시간
int ans;

int direct[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int t) {
    if(t == L) return;

    location[y][x] = true;
    int cur = map[y][x];
    int next;

    for(int i=0; i<4; i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];
        next = map[ny][nx];

        if(map[ny][nx] == 0) continue;  // 파이프가 없는 경우
        else if(visited[ny][nx]) continue;  // 이미 방문한 경우
        else if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;   // 지도에서 벗어나는 경우

        if(i == 0 && (cur==3 || cur==5 || cur==6)) continue;    // 위로 못 가는 경우
        else if(i == 1 && (cur==2 || cur==6 || cur==7)) continue;   // 우
        else if(i == 2 && (cur==3 || cur==4 || cur==7)) continue;   // 하
        else if(i == 3 && (cur==2 || cur==4 || cur==5)) continue;   // 좌

        if(i == 0 && (next == 3 || next == 4 || next == 7)) continue;   // 다음 파이프와 연결 불가능한 경우
        else if(i == 1 && (next == 2 || next == 4 || next == 5)) continue;
        else if(i == 2 && (next == 3 || next == 5 || next == 6)) continue;
        else if(i == 3 && (next == 2 || next == 6 || next == 7)) continue;

        visited[y][x] = true;
        dfs(nx, ny, t + 1);
        visited[y][x] = false;  
        // visited를 true, false로 바꾸는 것 -> 백트래킹
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        memset(map, 0, sizeof(map));
        memset(location, false, sizeof(location));
        ans = 0;

        // int tunnel;
        cin >> N >> M >> R >> C >> L;
        for(int y=0; y<N; y++) {
            for(int x=0; x<M; x++) {
                cin >> map[y][x];
            }
        }

        dfs(C, R, 0);

        for(int y=0; y<N; y++) {
            for(int x=0; x<M; x++) {
                if(location[y][x]) {
                    ans++;
                }
            }
        }

        cout << "#" << i << " " << ans << '\n';
    }

    return 0;
}