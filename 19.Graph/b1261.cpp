#include <iostream>
#include <queue>
#include <string>
// #include <algorithm>
using namespace std;

#define INF 123456789

// 알고스팟

int M, N;
int board[101][101];
int dist[101][101];
int dy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs() {
  queue<pair<int, int>> q;

  q.push({0, 0});
  dist[0][0] = 0;
  // q.push({1, 1});
  // dist[1][1] = 0;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for(int i=0; i<4; i++) {
      int nx = x + dy[i][0];
      int ny = y + dy[i][1];
      // 탐색할 범위가 아니라면
      if(nx<0 || ny<0 || nx>=M || ny>=N) { continue; }
      // 가야할 곳이 벽일 때
      if(board[nx][ny] == 1) {
        // 다른 루트로 그 자리를 오는 것보다
        // 그 전 자리에서 벽 뚫고 그 자리로 가는 것이 가중치가 낮다면 갱신
        if(dist[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx, ny});
        }
      }
      // 가야할 곳이 벽이 아니라면
      else if(board[nx][ny] == 0) {
        // 가중치가 더 낮으면 갱신
        if(dist[nx][ny] > dist[x][y]) {
          dist[nx][ny] = dist[x][y];
          q.push({nx, ny});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);

  cin >> N >> M;                 // 세로, 가로

  // for(int i=1; i<=M; i++) {       // 가로
  //   for(int j=1; j<=N; j++) {    // 세로
  //     cin >> board[i][j];
  //   }
  // }

  string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
      // 가중치를 무한대로 초기화
			dist[i][j] = 987654321;
			board[i][j] = str[j] - '0';
		}
	}

  bfs();
  cout << dist[M-1][N-1] << '\n';

  return 0;
}
