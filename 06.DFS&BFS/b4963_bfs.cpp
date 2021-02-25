#include <iostream>
#include <queue>
using namespace std;

#define MAX 50

// 섬의 개수

int w, h, island;
int cnt = 0;
int map[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false, };
queue<pair<int, int>> q;

// 기존과는 다르게 대각선까지 조사해야 하므로 4가지 방향 4군데 추가
int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };

void bfs(int y, int x) {
  q.push(make_pair(y, x));

  visited[y][x] == true;

  while(!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {   // 모든 방향 검사
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위를 벗어나지 않으며
      if(0<=nx && nx<h && 0<=ny && ny<w) {
        // 방문하지 않은 섬이 있다면
        if(map[ny][nx] == 1 && visited[ny][nx] == false) {
          visited[ny][nx] = true;
          q.push(make_pair(ny, nx));
        }
      }
    }
  }
}

int main() {
    while(1) {
      w=0; h=0; cnt=0;
      for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
          map[i][j] = 0;
          visited[i][j] = false;
        }
      }
      cin >> w >> h;
      // 0 0입력이 들어오면 입력이 끝난 것이므로 while문 탈출
      if(w == 0 && h == 0) break;
      for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
          cin >> island;
          map[j][i] = island;
        }
      }
      for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
          // 방문하지 않은 섬일 때
          if(map[j][i] == 1 && visited[j][i] == false) {
            bfs(j, i);
            cnt++;
          }
        }
      }

      cout << cnt << '\n';
    }

    return 0;
}
