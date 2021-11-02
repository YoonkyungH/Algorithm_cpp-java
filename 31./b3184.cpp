// 양

#include <iostream>
#include <queue>

using namespace std;

int R, C; // R개의 줄에 C개의 글자
int sheep = 0, sheepSum = 0;
int wolf = 0, wolfSum = 0;

char map[250][250];
bool visited[250][250] = {false, };
queue<pair<int, int> > q;

// 동 남 서 북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    sheep = 0; wolf = 0;

    q.push(make_pair(x, y));

    visited[x][y] = true;
     
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 양이거나 늑대면 바로 숫자세기
        if(map[x][y] == 'o') { sheep++; }
        else if(map[x][y] == 'v') { wolf++; }

        for(int i=0; i<4; i++) {    // 상하좌우 검사
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나지 않으면서 방문하지 않은 울타리 외의 영역이라면
            if(0<=nx && nx<R && 0<=ny && ny<C) {
                if(map[nx][ny] != '#' && visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }

        }
    }
    
    // 한 울타리를 끝낸 후이므로 누가 이겼는지 보고 수를 증가시켜주기
    if(sheep > wolf) { sheepSum += sheep; }
    else if(sheep <= wolf) { wolfSum += wolf; } 
}

int main() {
    ios::sync_with_stdio(0);

    cin >> R >> C;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(visited[i][j] == false) { bfs(i, j); }
        }
    }
    // bfs(0, 0);

    cout << sheepSum << ' ' << wolfSum << '\n';

    return 0;
}