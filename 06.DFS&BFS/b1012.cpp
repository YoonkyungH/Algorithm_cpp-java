#include <iostream>
#include <queue>
using namespace std;

#define MAX 50

// 유기농 배추

int T, M, N, K;                         // T: 테스트케이스, M: 가로, N: 세로, K: 배추위치
int y, x;
int earthworm = 0;                      // 지렁이 수
int field[MAX][MAX] = {0, };            // 배추 위치
bool visited[MAX][MAX] = {false, };     // 방문 여부
queue<pair<int, int>> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
  q.push(make_pair(y, x));          // pair 만들어서 queue에 저장

  visited[y][x] = true;

  while(!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {   // 상하좌우 검사
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위를 벗어나지 않으며
      if(0<=nx && nx<M && 0<=ny && ny<N) {
        // 방문하지 않은 배추라면
        if(field[ny][nx] == 1 && visited[ny][nx] == false) {
          visited[ny][nx] = true;
          q.push(make_pair(ny, nx));
        }
      }
    }
  }
}

int main() {
  cin >> T;
  for(int l=0; l<T; l++) {
    M=0; N=0; K=0;              // 가로, 세로, 배추 수, 지렁이 수 초기화
    earthworm = 0;
    while(!q.empty()) q.pop();  // queue 비우기

    // 원래 이렇게 하려고 했는데 안돼서 아래 방법 이용
    // field[MAX][MAX] = {0, };
    // visited[MAX][MAX] = {false, };

    for(int i=0; i<MAX; i++) {          // field, visited 초기화
      for(int j=0; j<MAX; j++) {
        field[i][j] = 0;
        visited[i][j] = false;
      }
    }

    cin >> M >> N >> K;                 // 가로, 세로, 배추개수

    for(int i=0; i<K; i++) {
      cin >> x >> y;                    // 하,,이걸 y, x로 반대로 써서,,
      field[y][x] = 1;                  // (y, x)에 해당하는 자리에 배추심기
    }

    for(int i=0; i<M; i++) {
      for(int j=0; j<N; j++) {
        // 모든 field를 검사하면서 방문하지 않은 배추가 있으면 bfs탐색
        if(field[j][i] == 1 && visited[j][i] == false) {
          bfs(j, i);                    // 하,,이것도 반대로 써서,,
          earthworm++;
        }
      }
    }
    cout << earthworm << '\n';
  }

  return 0;

}
